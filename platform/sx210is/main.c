#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();


void startup()
{


	long *bss = &link_bss_start;
	long *ptr;

	// sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
		started();
		shutdown();
	}

	// initialize .bss senment
	while (bss<&link_bss_end)
		*bss++ = 0;


	boot();
}


//zoom position is get_parameter_data(87)

// Focus length table in firmware @ 0xfffea1cc
#define NUM_FL 126		// 0 - 125, entries in firmware (3 words each entry, first is FL)
extern int focus_len_table[NUM_FL*3];

// Focal length range is 5.0 - 70,0 mm, 27.3 - 392 in 35-mm equivalent.
// So, CF_EFL = 27.3/5.0*10000=54600 or392/70*10000=56000
// diff = 54600 - 54566.6 = 1400, split it 1400 / 2 = 700
// add to base 56000 + 700 = 56700
// divide by 10 to avoid overflow in get_effective_focal_length()
#define CF_EFL  5670
const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
	return (CF_EFL*get_focal_length(zp))/1000;
}

int get_focal_length(int zp) {
	if (zp < 0) zp = 0;
	else if (zp >= NUM_FL) zp = NUM_FL-1;
	return focus_len_table[zp*3];
}

int get_zoom_x(int zp) {
	return get_focal_length(zp)*10/focus_len_table[0];
}


long get_vbatt_min()
{
	return 3280;  // min observed was 3.408, then it died
}

long get_vbatt_max()
{
	return 4057;  // fresh from change (actual was 4.127)
}
