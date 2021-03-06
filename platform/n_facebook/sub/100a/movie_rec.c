/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
// Powershot N Facebook
#include "conf.h"

void change_video_tables(int a, int b){ }

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}
//////////////////////////////////////////////////////////////
// movie_record_task - based on A1400
//////////////////////////////////////////////////////////////

/*************************************************************/
//** movie_record_task @ 0xFF23B0E0 - 0xFF23B2A4, length=114
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R8, =0xFF23AD10 \n"
"    LDR     R4, =0xA5B0 \n"
"    LDR     R9, =0x2710 \n"
"    MVN     R7, #0 \n"
"    MOV     R5, #1 \n"
"    MOV     R6, #0 \n"

"loc_FF23B0FC:\n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068BDE4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x30] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF23B284 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xF \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF23B284 \n"
"    B       loc_FF23B1CC \n"
"    B       loc_FF23B1F0 \n"
"    B       loc_FF23B200 \n"
"    B       loc_FF23B208 \n"
"    B       loc_FF23B210 \n"
"    B       loc_FF23B218 \n"
"    B       loc_FF23B1D4 \n"
"    B       loc_FF23B244 \n"
"    B       loc_FF23B270 \n"
"    B       loc_FF23B278 \n"
"    B       loc_FF23B1E0 \n"
"    B       loc_FF23B284 \n"
"    B       loc_FF23B280 \n"
"    B       loc_FF23B1A8 \n"
"    B       loc_FF23B17C \n"

"loc_FF23B17C:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R6, [R4, #0x34] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STRH    R6, [R4, #6] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF23B1C4 \n"

"loc_FF23B1A8:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    STR     R5, [R4, #0x44] \n"

"loc_FF23B1C4:\n"
"    STR     R5, [R4, #8] \n"
"    B       loc_FF23B284 \n"

"loc_FF23B1CC:\n"
"    BL      unlock_optical_zoom\n" // added
"    BL      sub_FF23A974 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B1D4:\n"
"    LDR     R1, [R4, #0xCC] \n"
"    BLX     R1 \n"
"    LDR     R0, =video_compression_rate \n" // added
"    BL      set_quality \n"                 // added
"    BL      mute_on_zoom \n"                // added
"    B       loc_FF23B284 \n"

"loc_FF23B1E0:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF3E4BB0 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B1F0:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x34] \n"
"    B       loc_FF23B284 \n"

"loc_FF23B200:\n"
"    BL      sub_FF239ECC \n"
"    B       loc_FF23B284 \n"

"loc_FF23B208:\n"
"    BL      sub_FF239DB4 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B210:\n"
"    BL      sub_FF239A68 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B218:\n"
"    LDR     R1, [R4, #0x94] \n"
"    LDR     R0, =0x4840F640 \n"
"    CMP     R1, #0 \n"
"    LDREQ   R1, =0xFF239A2C \n"
"    LDREQ   R0, [R4, #0x98] \n"
"    BEQ     loc_FF23B23C \n"
"    BL      sub_FF3E586C \n"
"    LDR     R1, =0xFF239A2C \n"
"    MOV     R0, #0 \n"

"loc_FF23B23C:\n"
"    BL      sub_FF3E3E58 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B244:\n"
"    LDR     R0, =0x213834 \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xFF2399B4 \n"
"    LDRNE   R0, =0xFF239A08 \n"
"    MOVNE   R3, #0 \n"
"    MOVNE   R1, R3 \n"
"    BLNE    sub_FF095224 \n"
"    MOV     R0, #3 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF23B284 \n"

"loc_FF23B270:\n"
"    BL      sub_FF239934 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B278:\n"
"    BL      sub_FF23BCD0 \n"
"    B       loc_FF23B284 \n"

"loc_FF23B280:\n"
"    BL      sub_FF23BBF0 \n"

"loc_FF23B284:\n"
"    LDR     R1, [SP, #4] \n"
"    MOV     R3, #0x680 \n"
"    STR     R6, [R1] \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xFF239580 /*'MovieRecorder.c'*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    MOV     R2, R9 \n"
"    BL      sub_0068B044 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF23B0FC \n"
);
}
