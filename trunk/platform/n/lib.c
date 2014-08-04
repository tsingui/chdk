// Powershot N

#include "platform.h"
#include "lolevel.h"

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *camera_jpeg_count_str()    { return (char*)0x00220c20; }             // Found @0xff2c1778
long hook_raw_size()             { return 0x0124ab50; }                    // Found @0xff4b9540
int get_flash_params_count(void) { return 0x91; }                          // Found @0xff25006c

char *hook_raw_image_addr()
{
    return raw_buffers[active_raw_buffer];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[(active_raw_buffer^1)];
}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenUnlock();
    extern void _ScreenLock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

// powershot N has only one LED - on the power button
void debug_led(int state) 
{
    if ( state == 1 ) *(int*)0xc022c30c = ( (*(int*)0xc022c30c) & 0xffffffcf ) | 0x20 ;
    else              *(int*)0xc022c30c = ( (*(int*)0xc022c30c) & 0xffffffcf )        ;
}
void camera_set_led(int led, int state, int bright) { debug_led(state) ; }


// Bitmap values 
void *vid_get_bitmap_fb()   { return (void*)0x406c5000; }        // Found @0xff08d5d8
void *vid_get_viewport_fb() { return (void*)0x4081ab80; }        // Found @0xff4b7ba4

void *vid_get_viewport_fb_d()                                    // buffer used in playback mode & fallback if vid_get_viewport_live_fb returns null
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

void *vid_get_viewport_live_fb()                                 // live buffer used in record mode
{ 
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    if (MODE_IS_VIDEO(mode_get()) || (movie_status==VIDEO_RECORD_IN_PROGRESS))
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.
   
    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // -1 used for best MD response - TODO verify this
    return viewport_buffers[(active_viewport_buffer-7)&7];  // -7 tested best with fudgey's HTML motion detector
}



// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
        return 2;              
}

int vid_get_viewport_width()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 360;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize() >> 1;    
}

long vid_get_viewport_height()
{
  if ((mode_get() & MODE_MASK) == MODE_PLAY)
  {
       return 240;
  }
  extern int _GetVRAMVPixelsSize();
  return _GetVRAMVPixelsSize() >> 1;

}


// Functions for PTP Live View system

int vid_get_viewport_width_proper()             { return vid_get_viewport_width() * 2; }
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }
int vid_get_aspect_ratio()                      { return 1; }
void * vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x7510+0x18)); //found Powershot N @ loc_FF1BDFEC (from A1400 example)
}


#ifdef CAM_LOAD_CUSTOM_COLORS

// Function to load CHDK custom colors into active Canon palette

extern int active_palette_buffer;
extern int** palette_buffer_ptr;
extern char palette_control;

void *vid_get_bitmap_active_palette()
{
    int *p ;
    
    p = palette_buffer_ptr[active_palette_buffer+1];
    
    if(!p) {                            // active_palette_buffer can point at null when func and menu are opened for the first time
        p = palette_buffer_ptr[0+1];    // rec mode buffer appears to always be initialized
    }
    return (p+1);                      
}

void load_chdk_palette()
{
    // active_palette_buffer values
    //  0x00:shooting, 0x04:camera modes menu, 0x0C:func menu, 0x10:playback, 0x14:shooting setup menu, 0x18:wifi menu
    if ((active_palette_buffer == 0x00) || (active_palette_buffer == 0x10) )
    {
        int * pal = (int*) vid_get_bitmap_active_palette();
        
        if (pal[CHDK_COLOR_BASE+0] != 0x3F3ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x3F3ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x3F26EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x3F4CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x3F73BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x3F4BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x3F95AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x3F4766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x3F1250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x3F7F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x3F512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x3FA9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x3F819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x3FDED115;  // Light Yellow
            pal[CHDK_COLOR_BASE+13] = 0x1F190000;   // Transparent Light Grey
            
            
            palette_control = 1; // note appears to be a bitmask, bit 2 is also used
            
            vid_bitmap_refresh();
        }
    }
}
#endif