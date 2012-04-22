#include "platform.h"
#include "keyboard.h"
#include "stdlib.h"

/*
void *hook_raw_fptr()
{
    return (void*)0x34C50;
}

void *hook_raw_ret_addr()
{
    return (void*)0xFFCC7FF0;
}
*/

char *hook_raw_image_addr()
{
    return (char*)0x105B8AC0; // OK (find on ".crw")
    
}

long hook_raw_size()
{
    return 0x75A8F0; // OK (find on ".crw")
}

/*
void *vid_get_viewport_live_fb()
{
    return (void*)0;
}
*/

void *vid_get_bitmap_fb()
{
    return (void*)0x103C79A0; // OK (find in _CreatePhysicalVram)
}

void *vid_get_viewport_fb()
{
    return (void*)0x105F17A0; // OK (find on "VRAM Address  : %p")
}

void *vid_get_viewport_fb_d()
{
// from ewavr 
  int x=(*(int*)0x63AD0); // found in sub_FFD25770
  return (void *)x;
// if we start camera in PB mode with movie on display, this pointer will be NULL
// _fb isn't valid data, but at least it doesn't crash
//  return (void*) (x ? (void *)x : vid_get_viewport_fb()) ;
}

long vid_get_viewport_height()
{
  return 240;
// real height in rec mode can be obtained below
// note: 240 normally, 160 in stitch, 264 in 320x240 video, 528 in 640x480 video
// contiuously variable with digital zoom in video
//    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:*(int*)(0x32C68+4); // GetVRAMVPixelsSize
}

int review_fullscreen_mode(){ //from 710 added
 char r;
 get_parameter_data(53, &r, 1);
 return  r==0;
}

int postreview_fullscreen_mode(){ //from 710 added
 char r;
 get_parameter_data(54, &r, 1);
 return  r==0;
}


static int file_size_table[3][5]={{3110,2562,1666,1057,288},
				  {1954,1441, 928, 608,176},
				  {960,  736, 480, 320,112}};  // in KB   // from 710 added
				  	
				  
long raw_shoot_avail(){ // from 710 added
 long jpegs,size,quality;
 jpegs=atoi((char*)0x6E8D0); // orig.0x7BD98 find -> a9999
 get_property_case(23, (void *)&quality, 4);
 get_property_case(24, (void *)&size, 4);
 if ((size>4) || (quality>2)) return 0; 
 return (file_size_table[quality][size]*jpegs)/(file_size_table[quality][size]+(hook_raw_size()>>10));
}


int mf_slider_active() // from 710 added
{
 return *(long*)0x6C8B0==0x100; // orig.0x798F0  found in "ControlSwitcher.c"
}

void *vid_get_viewport_live_fb() // from 710 added
{
   // return (void*)0x10670ee0;
    void **fb=(void **)0x5288;
    unsigned char buff = *((unsigned char*)0x5298);
    if (buff == 0) {
        buff = 2;
    }
    else {
        buff--;
    }
    return fb[buff];
}


char *camera_jpeg_count_str()
{
    return (char*)0x6E8D0 ; // from 700 added orig. 0x78688
}

// PTP display stuff
int vid_get_palette_type() { return 1; }
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() {
    return (void *)0x634E0; // GetPaletteFromPhysicalScreen
}

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)0x5ED0); // FFD23420 DisplayPhysicalScreenWithYUVPalette
}
#if 1
int vid_get_viewport_max_height()               { return 528; } // in 640x480 movie mode
// this returns actual width in rec mode
// normally 704, effectively 352 at normal 1:2 PAR. In 640 video, doesn't change but has 1:1 PAR
// actual width is also 704 in playback mode, but the variable returns 0
// in 320 video 352, 1:1. In stitch 352, 1:2
int vid_get_viewport_width_proper() {
    // fake 1:1 mode
    if((mode_get()&MODE_SHOOTING_MASK) == MODE_PORTRAIT) {
        return 528;
    }
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?704:*(int*)0x32C68;
}
int vid_get_viewport_height_proper() {
    // fake 16:9 mode
    if((mode_get()&MODE_SHOOTING_MASK) == MODE_LANDSCAPE) {
        return 180; 
    }
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:*(int*)(0x32C68+4);
}
#endif
int vid_get_viewport_logical_height() {
    // except for stitch, always full screen
    int m = mode_get();
    if((m&MODE_MASK) != MODE_PLAY && ((m&MODE_SHOOTING_MASK) == MODE_STITCH || (m&MODE_SHOOTING_MASK) == MODE_LANDSCAPE)) {
        return 240;
    }
    return vid_get_viewport_height_proper();
}
int vid_get_viewport_logical_width() {
    // except for stitch, always full screen
    int m = mode_get();
    if((m&MODE_MASK) != MODE_PLAY && ((m&MODE_SHOOTING_MASK) == MODE_STITCH || (m&MODE_SHOOTING_MASK) == MODE_PORTRAIT)) {
        return 704;
    }
    return vid_get_viewport_width_proper();
}
int vid_get_viewport_display_xoffset_proper() {
    int val=0;
    int m = mode_get();
    if((m&MODE_MASK) != MODE_PLAY && (m&MODE_SHOOTING_MASK) == MODE_STITCH) {
        short dir=0;
        short seq=0;
        get_property_case(PROPCASE_STITCH_DIRECTION,&dir,sizeof(dir));
        get_property_case(PROPCASE_STITCH_SEQUENCE,&seq,sizeof(seq));
        // overall stitch window is 3/4 screen width, centered
        // live part is 1/2, so margin is either 1/8th or 3/8th
        if(dir==0) {
            val = seq?264:88;
        } else {
            val = seq?88:264;
        }
    } else if((m&MODE_SHOOTING_MASK) == MODE_PORTRAIT) {
        val = 88;
    }
    return val;
}
int vid_get_viewport_xoffset() {
    if((mode_get()&MODE_SHOOTING_MASK) == MODE_PORTRAIT) {
       return 88;
    }
    return 0;
}
int vid_get_viewport_display_yoffset_proper() {
    int m = mode_get();
    if((m&MODE_SHOOTING_MASK) == MODE_LANDSCAPE) {
       return 30;
    }
    return ((m&MODE_MASK) != MODE_PLAY && (m&MODE_SHOOTING_MASK) == MODE_STITCH)?60:0; // window is 120, centered in 240 screen
}
int vid_get_viewport_yoffset() {
    if((mode_get()&MODE_SHOOTING_MASK) == MODE_LANDSCAPE) {
       return 30;
    }
    return 0;
}
