#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

//TODO
KeyMap keymap[] = {
//    { 1, KEY_ZOOM_IN         ,0x00080000 },
//    { 1, KEY_ZOOM_OUT        ,0X00040000 },    
    { 2, KEY_ZOOM_IN         ,0x00008000 }, //Slow Zoom In
    { 2, KEY_ZOOM_OUT        ,0X00004000 }, //Slow Zoom out
    { 2, KEY_MENU            ,0x00001000 },
    { 2, KEY_VIDEO           ,0X00002000 },
//  { 2, KEY_AUTO            ,0x00000800 }, //New key
    { 2, KEY_DISPLAY         ,0x00000400 },
    { 2, KEY_PLAYBACK        ,0x00000200 },  
    { 2, KEY_SHOOT_FULL      ,0x00000060 },
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, //??                     20
    { 2, KEY_SHOOT_HALF      ,0x00000020 }, //?? Versión enviada para Marcio 40
    { 2, KEY_LEFT            ,0X00000010 },
    { 2, KEY_DOWN            ,0x00000008 },
    { 2, KEY_RIGHT           ,0x00000004 },        
    { 2, KEY_UP              ,0x00000002 },    
    { 2, KEY_SET             ,0x00000001 },
    { 0, 0, 0 }
};

int get_usb_bit()
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK);
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    //sx510 101a found @ 0xff00c114
    asm volatile(
        "STMFD   SP!, {R1-R7,LR}\n"
        "MOV     R5, #0\n"
        "BL      my_kbd_read_keys\n"
        "B       _kbd_p1_f_cont\n"
    );

    return 0; // shut up the compiler
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    while (physw_run){
        _SleepTask(physw_sleep_delay);
        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }
    _ExitTask();
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

