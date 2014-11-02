#include "camera_info.h"
#include "stdlib.h"
#include "keyboard.h"
#include "battery.h"
#include "conf.h"
#include "gui_draw.h"
#include "gui_batt.h"
//-------------------------------------------------------------------

static char osd_buf[32];

//-------------------------------------------------------------------
static long get_batt_average() {
    #define VOLTS_N         100
    static unsigned short   volts[VOLTS_N] = {0};
    static unsigned int     n = 0, rn = 0;
    static unsigned long    volt_aver = 0;

    volt_aver-=volts[n];
    volts[n]=(unsigned short)stat_get_vbatt();
    volt_aver+=volts[n];
    if (++n>rn) rn=n;
    if (n>=VOLTS_N) n=0;
    return volt_aver/rn;
}

//-------------------------------------------------------------------
unsigned long get_batt_perc() {
    unsigned long v;

    v = get_batt_average();
    if (v>conf.batt_volts_max) v=conf.batt_volts_max;
    if (v<conf.batt_volts_min) v=conf.batt_volts_min;
    return (v-conf.batt_volts_min)*100/(conf.batt_volts_max-conf.batt_volts_min);
}

//-------------------------------------------------------------------
static void gui_batt_draw_icon () {
    register coord xx, yy;
    
    xx = conf.batt_icon_pos.x;
    yy = conf.batt_icon_pos.y;

    int perc = get_batt_perc();

    // set bar color depending percent
    color cl1 = (perc>50) ? COLOR_GREEN_DK :(perc<=20) ? COLOR_RED_DK : COLOR_YELLOW_DK;
    color cl2 = (perc>50) ? COLOR_GREEN    :(perc<=20) ? COLOR_RED    : COLOR_YELLOW;
    color cl3 = (perc>50) ? COLOR_GREEN_LT :(perc<=20) ? COLOR_RED_LT : COLOR_YELLOW_LT;

    // icon
    draw_round_rect(xx,     yy+3,   xx+3,   yy+9,   COLOR_GREY);
    draw_rect(xx+3,         yy,     xx+31,  yy+12,  COLOR_GREY);
    draw_filled_rect(xx+1,  yy+4,   xx+2,   yy+8,   MAKE_COLOR(COLOR_YELLOW_DK, COLOR_YELLOW_DK));
    draw_filled_rect(xx+4,  yy+6,   xx+30,  yy+11,  MAKE_COLOR(COLOR_GREY_DK,   COLOR_GREY_DK));
    draw_filled_rect(xx+4,  yy+1,   xx+30,  yy+5,   MAKE_COLOR(COLOR_GREY_LT,   COLOR_GREY_LT));
    // fill icon
    draw_rect(xx+4,         yy+2,   xx+30,  yy+10,  cl1);
    draw_filled_rect(xx+29-(25*perc/100),   yy+6,  xx+29,   yy+9,  MAKE_COLOR(cl2, cl2));
    draw_filled_rect(xx+29-(25*perc/100),   yy+3,  xx+29,   yy+5,  MAKE_COLOR(cl3, cl3));
}

//-------------------------------------------------------------------
static void gui_batt_draw_charge(){
    int perc = get_batt_perc();
    twoColors cl = user_color((perc<=20) ? conf.osd_color_warn : conf.osd_color);
    sprintf(osd_buf, "%3d%%", perc);
    osd_buf[5]=0;
    draw_osd_string(conf.batt_txt_pos, 0, 0, osd_buf, cl, conf.batt_txt_scale);
}

//-------------------------------------------------------------------
static void gui_batt_draw_volts() {
    unsigned long v;

    v = get_batt_average();
    sprintf(osd_buf, "%ld.%03ld", v/1000, v%1000);
    osd_buf[5]=0;
    draw_osd_string(conf.batt_txt_pos, 0, 0, osd_buf, user_color(conf.osd_color), conf.batt_txt_scale);
}

//-------------------------------------------------------------------
void gui_batt_draw_osd(int is_osd_edit)
{
    if (conf.batt_perc_show || is_osd_edit)
        gui_batt_draw_charge();

    if (conf.batt_volts_show || is_osd_edit)
        gui_batt_draw_volts();
    
    if (conf.batt_icon_show || is_osd_edit)
        gui_batt_draw_icon();
}

//-------------------------------------------------------------------