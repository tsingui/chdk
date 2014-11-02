#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"

typedef struct {
	short grp;
	short hackkey;
	long canonkey;
} KeyMap;

static long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

//SX50
#define SD_READONLY_FLAG    0x00000002 // Found @0xff49e5dc, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xff49e64c, levent 0x202
#define USB_IDX             2
#define HOTSHOE_FLAG        0x00080000 // Found @0xff49e624, levent 0x204
#define HOTSHOE_IDX         2
//CHECK
#define KEYS_MASK0 (0x00CFFDE0)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x0000C000) 

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

static KeyMap keymap[] = {
    { 0, KEY_SET             ,0x00000400 }, // Found @0xff49e55c, levent 0x08
    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff49e564, levent 0x0a
    { 0, KEY_DOWN            ,0x00001000 }, // Found @0xff49e56c, levent 0x05
    { 0, KEY_MENU            ,0x00002000 }, // Found @0xff49e574, levent 0x09
    { 0, KEY_LEFT            ,0x00004000 }, // Found @0xff49e57c, levent 0x06
    { 0, KEY_UP              ,0x00040000 }, // Found @0xff49e59c, levent 0x04
    { 0, KEY_RIGHT           ,0x00080000 }, // Found @0xff49e5a4, levent 0x07
    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff49e5fc, levent 0x100
    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff49e604, levent 0x101
    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff49e61c, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff49e61c, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff49e614, levent 0x00
	{ 0, KEY_PRINT		     ,0x00800000 },
	{ 0, KEY_FLASH           ,0x00400000 },
	{ 0, KEY_ERASE		     ,0x00020000 },	
	{ 0, KEY_VIDEO           ,0x00010000 },
	{ 0, KEY_ZOOM_IN	     ,0x00000060 }, // 2 bits used, 4 values (0x00000060)
	{ 0, KEY_ZOOM_IN	     ,0x00000020 }, // 2 bits used, 4 values (0x00000060)
	{ 0, KEY_ZOOM_IN	     ,0x00000040 }, // 2 bits used, 4 values (0x00000060)
	{ 0, KEY_ZOOM_OUT	     ,0x00000180 }, // 2 bits used, 4 values (0x00000180)
	{ 0, KEY_ZOOM_OUT	     ,0x00000080 }, // 2 bits used, 4 values (0x00000180)
	{ 0, KEY_ZOOM_OUT	     ,0x00000100 }, // 2 bits used, 4 values (0x00000180)
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;


static void __attribute__((noinline)) mykbd_task_proceed()
{
	while (physw_run){
		_SleepTask(physw_sleep_delay);

		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline))
mykbd_task()
{
    mykbd_task_proceed();

    _ExitTask();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	asm volatile(
		"STMFD   SP!, {R1-R7,LR}\n"
		"MOV     R5, #0\n"
		//"BL      _kbd_read_keys \n"
		"BL		my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}

// Set to 1 to disable jogdial events from being processed in firmware
volatile int jogdial_stopped=0;

// Pointer to stack location where jogdial task records previous and current
// jogdial positions
extern short* jog_position;
extern short rear_dial_position;

void jogdial_control(int n)
{
    if (jogdial_stopped && !n)
    {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = rear_dial_position;   // Rear dial
    }
    jogdial_stopped = n;
}

void my_kbd_read_keys()
{
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];

	_GetKbdState(kbd_new_state);
	_kbd_read_keys_r2(kbd_new_state);

	if (kbd_process() == 0){
		// leave it alone...
          physw_status[0] = kbd_new_state[0];
          physw_status[1] = kbd_new_state[1];
          physw_status[2] = kbd_new_state[2];
          jogdial_control(0);

	} else {
		// override keys
	 	physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) | (kbd_mod_state[0] & KEYS_MASK0);
		physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) | (kbd_mod_state[1] & KEYS_MASK1);
		physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) | (kbd_mod_state[2] & KEYS_MASK2);

		if ((jogdial_stopped==0) && !camera_info.state.state_kbd_script_run)
		{
			jogdial_control(1);
			get_jogdial_direction();
		}
		else if (jogdial_stopped && camera_info.state.state_kbd_script_run) jogdial_control(0);
	}

    // Disable Zoom Assist button
    if (conf.zoom_assist_button_disable)
        physw_status[0] |= 0x00010000;

	//_kbd_read_keys_r2(physw_status);

    physw_status[SD_READONLY_IDX] = physw_status[SD_READONLY_IDX] & ~SD_READONLY_FLAG;
	if (conf.remote_enable) {
		physw_status[USB_IDX] = physw_status[USB_IDX] & ~USB_MASK;
	}
#ifdef CAM_HOTSHOE_OVERRIDE
    HOTSHOE_OVERRIDE; /* macro defined in platform.h */
#endif

}


/****************/

void kbd_set_alt_mode_key_mask(long key)
{
}

void kbd_key_press(long key)
{
	int i;

	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key)
		{
			kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release_all()
{
	kbd_mod_state[0] |= KEYS_MASK0;
	kbd_mod_state[1] |= KEYS_MASK1;
	kbd_mod_state[2] |= KEYS_MASK2;
}

long kbd_is_key_pressed(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)
                return 1;
		}
	}
	return 0;
}

long kbd_is_key_clicked(long key)
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (keymap[i].hackkey == key){
			return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
			       ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
		}
	}
	return 0;
}

long kbd_get_pressed_key()
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0){
			return keymap[i].hackkey;
		}
	}
	return 0;
}

long kbd_get_clicked_key()
{
	int i;
	for (i=0;keymap[i].hackkey;i++){
		if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
		    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)) {
			return keymap[i].hackkey;
		}
	}
	return 0;
}

static short new_jogdial=0, old_jogdial=0;

long get_jogdial_direction(void)
{
    old_jogdial = new_jogdial;
    new_jogdial = rear_dial_position;
    if (old_jogdial < new_jogdial) return JOGDIAL_RIGHT;
    else if (old_jogdial > new_jogdial) return JOGDIAL_LEFT;
    else return 0;
}
