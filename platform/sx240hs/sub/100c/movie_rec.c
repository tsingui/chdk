/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xFF1B8350 - 0xFF1B84C8, length=95
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R6, =0xFF1B6FD8 \n"
"    LDR     R7, =0xFF1B7D44 \n"
"    LDR     R4, =0xAB38 \n"
"    LDR     R9, =0x69B \n"
"    LDR     R10, =0x2710 \n"
"    MOV     R8, #1 \n"
"    MOV     R5, #0 \n"

"loc_FF1B8370:\n"
"    LDR     R0, [R4, #0x24] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068BBE4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF1B84AC \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF1B84AC \n"
"    B       loc_FF1B844C \n"
"    B       loc_FF1B8470 \n"
"    B       loc_FF1B8480 \n"
"    B       loc_FF1B8488 \n"
"    B       loc_FF1B8490 \n"
"    B       loc_FF1B8498 \n"
"    B       loc_FF1B8454 \n"
"    B       loc_FF1B84A0 \n"
"    B       loc_FF1B8460 \n"
"    B       loc_FF1B84AC \n"
"    B       loc_FF1B84A8 \n"
"    B       loc_FF1B8418 \n"
"    B       loc_FF1B83E8 \n"

"loc_FF1B83E8:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R5, [R4, #0x34] \n"
"    STRH    R5, [R4, #6] \n"
"    STR     R6, [R4, #0xD4] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF1B8438 \n"

"loc_FF1B8418:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R6, [R4, #0xD4] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    STR     R8, [R4, #0x44] \n"

"loc_FF1B8438:\n"
"    LDR     R2, =0xFF1B64B0 \n"
"    LDR     R1, =0xD368C \n"
"    LDR     R0, =0xFF1B65C4 \n"
"    BL      sub_FF03EF7C \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B844C:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_FF1B78D0_my \n"  // --> Patched. Old value = 0xFF1B78D0.
);
}
else
{
asm volatile (
"    BL      sub_FF1B78D0 \n"
);
}
asm volatile (
"    B       loc_FF1B84AC \n"

"loc_FF1B8454:\n"
"    LDR     R1, [R4, #0xF0] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_FF1B84AC \n"

"loc_FF1B8460:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF34F104 \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B8470:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R8, [R4, #0x34] \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B8480:\n"
"    BL      sub_FF1B6C40 \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B8488:\n"
"    BL      sub_FF1B6924 \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B8490:\n"
"    BL      sub_FF1B6628 \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B8498:\n"
"    BL      sub_FF1B61D8 \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B84A0:\n"
"    BL      sub_FF1B6158 \n"
"    B       loc_FF1B84AC \n"

"loc_FF1B84A8:\n"
"    BL      sub_FF1B8A84 \n"

"loc_FF1B84AC:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF1B5DF0 /*'MovieRecorder.c'*/ \n"
"    STR     R5, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, R10 \n"
"    BL      sub_0068AF18 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF1B8370 \n"
);
}

/*************************************************************/
//** sub_FF1B78D0_my @ 0xFF1B78D0 - 0xFF1B7C08, length=207
void __attribute__((naked,noinline)) sub_FF1B78D0_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    LDR     R6, =0xAB38 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x34] \n"
"    STR     R0, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R4, [R0, #0x58] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R0, #0x3E8 \n"
"    MUL     R0, R4, R0 \n"
"    LDR     R8, =0xFFF00 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_FF1B7918 \n"
"    LDR     R1, [R6, #0x90] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF1B7928 \n"
"    B       loc_FF1B7920 \n"

"loc_FF1B7918:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF1B7928 \n"

"loc_FF1B7920:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF1B7934 \n"

"loc_FF1B7928:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF1B7934:\n"
"    LDR     R5, =0xD36C0 \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1B79A0 \n"
"    CMP     R4, #0x18 \n"
"    MOV     R0, #4 \n"
"    BEQ     loc_FF1B798C \n"
"    BGT     loc_FF1B7974 \n"
"    CMP     R4, #0xA \n"
"    CMPNE   R4, #0xF \n"
"    STREQ   R7, [R5, #0x14] \n"
"    BEQ     loc_FF1B79A0 \n"
"    CMP     R4, #0x14 \n"
"    BNE     loc_FF1B7994 \n"
"    B       loc_FF1B798C \n"

"loc_FF1B7974:\n"
"    CMP     R4, #0x19 \n"
"    CMPNE   R4, #0x1E \n"
"    BEQ     loc_FF1B798C \n"
"    CMP     R4, #0x3C \n"
"    BNE     loc_FF1B7994 \n"
"    MOV     R0, #8 \n"

"loc_FF1B798C:\n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FF1B79A0 \n"

"loc_FF1B7994:\n"
"    LDR     R0, =0xFF1B5DF0 /*'MovieRecorder.c'*/ \n"
"    MOV     R1, #0x790 \n"
"    BL      _DebugAssert \n"

"loc_FF1B79A0:\n"
"    LDR     R0, [R6, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF1B79B8 \n"
"    BL      sub_FF301DAC \n"
"    LDR     R0, =0xD36D8 \n"
"    BL      sub_FF34B1F4 \n"

"loc_FF1B79B8:\n"
"    LDR     R2, =0xAB3A \n"
"    LDR     R0, [R6, #0xB4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF080958 \n"
"    LDR     R2, =0xAB3C \n"
"    LDR     R0, [R6, #0xB4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF080958 \n"
"    LDR     R2, =0xAB88 \n"
"    LDR     R0, [R6, #0xB4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF080958 \n"
"    LDR     R2, =0xAB8C \n"
"    LDR     R0, [R6, #0xB4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF080958 \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xAC38 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xE \n"
"    BLNE    sub_FF07AC2C \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R4, =0xAC38 \n"
"    LDR     R9, =0xD36A8 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #2 \n"
"    BNE     loc_FF1B7AEC \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x483FC000 \n"
"    STRNE   R0, [R4] \n"
"    BNE     loc_FF1B7AEC \n"
"    LDR     R1, =0x484B4600 \n"
"    LDR     R0, =0x3A57E00 \n"
"    STR     R1, [R4] \n"
"    STR     R0, [R4, #4] \n"
"    LDMIA   R9, {R0,R2} \n"
"    MUL     R0, R2, R0 \n"
"    MOV     R3, R0, LSL#1 \n"
"    CMP     R3, R8 \n"
"    STR     R3, [R6, #0x9C] \n"
"    MOVCC   R2, #0 \n"
"    STR     R1, [R6, #0xA0] \n"
"    BCC     loc_FF1B7AB4 \n"
"    MOV     R2, #0 \n"
"    STMEA   SP, {R1,R2,R8} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_FF2FBE10 \n"
"    LDR     R0, [R6, #0x9C] \n"
"    MOV     R2, #0 \n"
"    SUB     R3, R0, #0xF0000 \n"
"    LDR     R0, [R6, #0xA0] \n"
"    SUB     R3, R3, #0xFF00 \n"
"    ADD     R1, R0, #0xF0000 \n"
"    ADD     R1, R1, #0xFF00 \n"

"loc_FF1B7AB4:\n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_FF2FBE10 \n"
"    LDR     R1, [R4] \n"
"    LDR     R0, [R6, #0x9C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R4] \n"
"    LDR     R1, [R4, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R4, #4] \n"

"loc_FF1B7AEC:\n"
"    LDR     R2, =0xD36C0 \n"
"    LDR     R3, =0xFF1B789C \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, [R4] \n"
"    STRD    R2, [SP] \n"
"    SUB     R3, R2, #0x18 \n"
"    MOV     R2, R0 \n"
"    LDR     R0, [R6, #0x90] \n"
"    BL      sub_FF34D848_my \n"  // --> Patched. Old value = 0xFF34D848.
"    LDRD    R0, [R6, #0xF8] \n"
"    LDR     R2, [R6, #0xB4] \n"
"    BL      sub_FF34DE34 \n"
"    LDR     R3, =0xABC0 \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R1, [R9, #8] \n"
"    AND     R2, R0, #0xFF \n"
"    LDR     R0, [R9] \n"
"    SUB     R3, R3, #4 \n"
"    BL      sub_FF34AD5C \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF1B7570 \n"
"    STREQ   R0, [R6, #0xF0] \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF1B7140 \n"
"    STREQ   R1, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xC] \n"
"    LDR     R1, =0xFF57676C \n"
"    CMP     R2, #2 \n"
"    BNE     loc_FF1B7B90 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF300B40 \n"
"    LDR     R0, =0xFF1B70B4 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF3010C4 \n"
"    B       loc_FF1B7BC8 \n"

"loc_FF1B7B90:\n"
"    CMP     R0, #0 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BNE     loc_FF1B7BB8 \n"
"    LDR     R1, [R6, #0x98] \n"
"    BL      sub_FF3011A4 \n"
"    BL      sub_FF301228 \n"
"    B       loc_FF1B7BC8 \n"

"loc_FF1B7BB8:\n"
"    BL      sub_FF2FED2C \n"
"    LDR     R0, =0xFF1B70B4 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF2FF53C \n"

"loc_FF1B7BC8:\n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1B7BFC \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF34EE6C \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF050DC0 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF34EE6C \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF050DC0 \n"

"loc_FF1B7BFC:\n"
"    LDR     R0, =0xFF1B706C \n"
"    STR     R7, [R6, #0x44]! \n"
"    STR     R0, [R6, #0x90] \n"
"    LDMFD   SP!, {R0-R10,PC} \n"
);
}

/*************************************************************/
//** sub_FF34D848_my @ 0xFF34D848 - 0xFF34DDD8, length=357
void __attribute__((naked,noinline)) sub_FF34D848_my() {
asm volatile (
"    STMFD   SP!, {R0-R11,LR} \n"
"    MOV     R8, R0 \n"
"    LDR     R0, [R3, #0x10] \n"
"    SUB     SP, SP, #4 \n"
"    CMP     R0, #0 \n"
"    LDR     R7, [SP, #0x38] \n"
"    LDREQ   R1, =0x36A \n"
"    LDREQ   R0, =0xFF34B7E8 /*'MovWriter.c'*/ \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R3 \n"
"    MOV     R5, R6 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R11, =0xFE20 \n"
"    CMP     R8, #0 \n"
"    MOV     R10, #0 \n"
"    STR     R8, [R11, #0x94] \n"
"    MOVEQ   R0, #1 \n"
"    STRNE   R10, [R11, #0xD8] \n"
"    STREQ   R0, [R11, #0xD8] \n"
"    LDR     R0, [R4] \n"
"    LDR     R3, =0x61A8 \n"
"    STR     R0, [R11, #0xE0] \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, =0x7530 \n"
"    STR     R0, [R11, #0xE4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0x18 \n"
"    STR     R0, [R11, #0xF0] \n"
"    LDR     R8, [R4, #8] \n"
"    LDR     R0, =0x3E9 \n"
"    CMP     R8, #0xF \n"
"    MOV     R12, #0x3E8 \n"
"    MOV     R9, #0x1E \n"
"    ADDCC   PC, PC, R8, LSL#2 \n"
"    B       loc_FF34D9A0 \n"
"    B       loc_FF34D928 \n"
"    B       loc_FF34D920 \n"
"    B       loc_FF34D910 \n"
"    B       loc_FF34D97C \n"
"    B       loc_FF34D98C \n"
"    B       loc_FF34D9A0 \n"
"    B       loc_FF34D9A0 \n"
"    B       loc_FF34D9A0 \n"
"    B       loc_FF34D9A0 \n"
"    B       loc_FF34D948 \n"
"    B       loc_FF34D940 \n"
"    B       loc_FF34D938 \n"
"    B       loc_FF34D974 \n"
"    B       loc_FF34D96C \n"
"    B       loc_FF34D958 \n"

"loc_FF34D910:\n"
"    LDR     R5, =0x5DC0 \n"
"    STR     R2, [R11, #0xE8] \n"
"    STR     R5, [R11, #0x13C] \n"
"    B       loc_FF34D930 \n"

"loc_FF34D920:\n"
"    MOV     R5, R3 \n"
"    B       loc_FF34D95C \n"

"loc_FF34D928:\n"
"    MOV     R5, R1 \n"
"    B       loc_FF34D94C \n"

"loc_FF34D930:\n"
"    STR     R0, [R11, #0x140] \n"
"    B       loc_FF34D9AC \n"

"loc_FF34D938:\n"
"    LDR     R5, =0x5DC \n"
"    B       loc_FF34D94C \n"

"loc_FF34D940:\n"
"    LDR     R5, =0xBB8 \n"
"    B       loc_FF34D94C \n"

"loc_FF34D948:\n"
"    LDR     R5, =0x1770 \n"

"loc_FF34D94C:\n"
"    STR     R1, [R11, #0x13C] \n"
"    STR     R9, [R11, #0xE8] \n"
"    B       loc_FF34D930 \n"

"loc_FF34D958:\n"
"    LDR     R5, =0x4E2 \n"

"loc_FF34D95C:\n"
"    STR     R2, [R11, #0xE8] \n"
"    STR     R3, [R11, #0x13C] \n"
"    STR     R12, [R11, #0x140] \n"
"    B       loc_FF34D9AC \n"

"loc_FF34D96C:\n"
"    LDR     R5, =0x9C4 \n"
"    B       loc_FF34D95C \n"

"loc_FF34D974:\n"
"    LDR     R5, =0x1388 \n"
"    B       loc_FF34D95C \n"

"loc_FF34D97C:\n"
"    STR     R1, [R11, #0x13C] \n"
"    LDR     R5, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs 240fps
"    MOV     R1, #0xF0 \n"
"    B       loc_FF34D998 \n"

"loc_FF34D98C:\n"
"    LDR     R5, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs 120fps
"    STR     R1, [R11, #0x13C] \n"
"    MOV     R1, #0x78 \n"

"loc_FF34D998:\n"
"    STR     R1, [R11, #0xE8] \n"
"    B       loc_FF34D930 \n"

"loc_FF34D9A0:\n"
"    LDR     R0, =0xFF34B7E8 /*'MovWriter.c'*/ \n"
"    MOV     R1, #0x3C4 \n"
"    BL      _DebugAssert \n"

"loc_FF34D9AC:\n"
"    LDR     R0, [R11, #0xE8] \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0xE0F. 2hrs
"    MOV     R0, R0, LSR#1 \n"
"    STR     R0, [R11, #0xEC] \n"
"    LDR     R0, [R7] \n"
"    STR     R0, [R11, #0xF4] \n"
"    LDRH    R0, [R7, #0x10] \n"
"    STR     R0, [R11, #0xF8] \n"
"    LDR     R0, [R7, #4] \n"
"    STRH    R0, [R11, #2] \n"
"    LDR     R0, [R7, #8] \n"
"    STRH    R0, [R11, #4] \n"
"    LDR     R0, [R7, #0x14] \n"
"    STR     R0, [R11, #0xFC] \n"
"    LDR     R0, [SP, #0x3C] \n"
"    STR     R0, [R11, #0x138] \n"
"    LDR     R0, [R11, #0xE0] \n"
"    CMP     R0, #0x140 \n"
"    MOVEQ   R0, #0x20000 \n"
"    MOVEQ   R6, #1 \n"
"    STREQ   R0, [R11, #0xB8] \n"
"    BEQ     loc_FF34DA44 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R6, #2 \n"
"    STREQ   R0, [R11, #0xB8] \n"
"    BEQ     loc_FF34DA44 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R6, #4 \n"
"    STREQ   R0, [R11, #0xB8] \n"
"    BEQ     loc_FF34DA44 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FF34DA4C \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R6, #5 \n"
"    STR     R0, [R11, #0xB8] \n"

"loc_FF34DA44:\n"
"    STR     R1, [R11, #0x54] \n"
"    B       loc_FF34DA58 \n"

"loc_FF34DA4C:\n"
"    LDR     R0, =0xFF34B7E8 /*'MovWriter.c'*/ \n"
"    MOV     R1, #0x3EC \n"
"    BL      _DebugAssert \n"

"loc_FF34DA58:\n"
"    LDR     R8, [R4, #8] \n"
"    CMP     R8, #0xB \n"
"    CMPNE   R8, #0xA \n"
"    CMPNE   R8, #9 \n"
"    BNE     loc_FF34DA8C \n"
"    LDR     R0, [R11, #0xE0] \n"
"    CMP     R0, #0x500 \n"
"    BNE     loc_FF34DA8C \n"
"    LDR     R0, [R11, #0x54] \n"
"    LDR     R1, [R11, #0x140] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    B       loc_FF34DAAC \n"

"loc_FF34DA8C:\n"
"    LDR     R0, [R11, #0x54] \n"
"    LDR     R1, [R11, #0x140] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    MOV     R1, #5 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"

"loc_FF34DAAC:\n"
"    CMP     R8, #0xB \n"
"    CMPNE   R8, #0xA \n"
"    CMPNE   R8, #9 \n"
"    STR     R0, [R11, #0x50] \n"
"    BNE     loc_FF34DAD4 \n"
"    LDR     R1, [R11, #0x140] \n"
"    MUL     R0, R1, R0 \n"
"    MOV     R1, R5 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R11, #0x54] \n"

"loc_FF34DAD4:\n"
"    CMP     R8, #3 \n"
"    CMPNE   R8, #4 \n"
"    BNE     loc_FF34DB0C \n"
"    RSB     R0, R5, R5, LSL#4 \n"
"    STR     R9, [R11, #0x54] \n"
"    LDR     R1, [R11, #0x140] \n"
"    MOV     R0, R0, LSL#1 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    LDR     R1, [R11, #0xF0] \n"
"    MOV     R9, R1 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R9, R0 \n"
"    STR     R0, [R11, #0x50] \n"

"loc_FF34DB0C:\n"
"    ADD     R0, R5, R5, LSL#8 \n"
"    LDR     R1, [R11, #0x140] \n"
"    RSB     R0, R0, R0, LSL#3 \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R11, #0x80] \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    STR     R0, [SP] \n"
"    LDR     R5, [R7, #0xC] \n"
"    MOV     R0, R5, LSR#1 \n"
"    STR     R5, [R11, #0xA0] \n"
"    STR     R0, [R11, #0xA4] \n"
"    LDR     R0, [SP, #8] \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R1, R0, #3 \n"
"    STR     R1, [R11, #0x104] \n"
"    LDR     R0, [R11, #0x50] \n"
"    MOV     R0, R0, LSL#2 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R11, #0x108] \n"
"    LDRH    R7, [R11, #4] \n"
"    LDR     R2, [SP, #0xC] \n"
"    LDR     R3, [SP, #8] \n"
"    CMP     R7, #0 \n"
"    ADD     R9, R3, R2 \n"
"    BEQ     loc_FF34DD90 \n"
"    ADD     R8, R1, R0 \n"
"    STR     R8, [R11, #0x10C] \n"
"    LDR     R1, [R11, #0xEC] \n"
"    BL      sub_00690934 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, R8 \n"
"    ADD     R0, R0, #0x1F \n"
"    BIC     R0, R0, #0x1F \n"
"    STR     R0, [R11, #0x110] \n"
"    LDR     R1, [R11, #0xD8] \n"
"    CMP     R1, #0 \n"
"    STREQ   R10, [R11, #0x84] \n"
"    LDREQ   R2, [R11, #0xB8] \n"
"    ADDEQ   R0, R0, R2 \n"
"    STREQ   R0, [R11, #0x114] \n"
"    MOVEQ   R0, #2 \n"
"    STREQ   R0, [R11, #0x40] \n"
"    BEQ     loc_FF34DC48 \n"
"    LDR     R2, [R11, #0xB8] \n"
"    CMP     R7, #1 \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R11, #0x84] \n"
"    ADD     R0, R0, #0x100000 \n"
"    MOV     R2, #5 \n"
"    B       loc_FF34DC30 \n"

"loc_FF34DC30:\n"
"    STR     R0, [R11, #0x114] \n"
"    STR     R2, [R11, #0x40] \n"
"    ADDEQ   R2, R5, R5, LSL#1 \n"
"    SUBEQ   R0, R9, R0 \n"
"    MOVEQ   R2, R2, LSL#1 \n"
"    BEQ     loc_FF34DC58 \n"

"loc_FF34DC48:\n"
"    LDR     R2, [R11, #0x40] \n"
"    LDR     R0, [R11, #0x114] \n"
"    MUL     R2, R5, R2 \n"
"    SUB     R0, R9, R0 \n"

"loc_FF34DC58:\n"
"    SUB     R0, R0, R2 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R0, [R11, #0x120] \n"
"    LDR     R2, [R11, #0x114] \n"
"    CMP     R1, #0 \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R11, #0x118] \n"
"    BEQ     loc_FF34DC8C \n"
"    CMP     R7, #1 \n"
"    BICEQ   R0, R0, #3 \n"
"    STREQ   R0, [R11, #0x28] \n"
"    ADDEQ   R0, R0, R5 \n"

"loc_FF34DC8C:\n"
"    STR     R0, [R11, #0x11C] \n"
"    LDR     R10, =0x170BB4 \n"
"    LDR     R8, [R11, #0x40] \n"
"    LDR     R9, [R11, #0x11C] \n"
"    MOV     R0, #0 \n"
"    SUB     LR, R10, #0x28 \n"

"loc_FF34DCA4:\n"
"    CMP     R0, R8 \n"
"    MLACC   R1, R0, R5, R9 \n"
"    LDR     R3, =0x170B64 \n"
"    ADDCC   R1, R1, #3 \n"
"    MOVCS   R1, #0 \n"
"    BICCC   R1, R1, #3 \n"
"    STR     R1, [R10, R0, LSL#2] \n"
"    MOV     R1, #0 \n"
"    ADD     R3, R3, R0, LSL#3 \n"
"    ADD     R12, LR, R0, LSL#3 \n"

"loc_FF34DCCC:\n"
"    STR     R2, [R3, R1, LSL#2] \n"
"    STR     R2, [R12, R1, LSL#2] \n"
"    ADD     R1, R1, #1 \n"
"    CMP     R1, #2 \n"
"    BLT     loc_FF34DCCC \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #5 \n"
"    BLT     loc_FF34DCA4 \n"
"    CMP     R7, #1 \n"
"    MOVNE   R0, #0 \n"
"    STRNE   R0, [R11, #0xDC] \n"
"    BNE     loc_FF34DD4C \n"
"    LDRH    R0, [R11, #2] \n"
"    CMP     R0, #0x10 \n"
"    LDRNE   R1, =0x48D \n"
"    LDRNE   R0, =0xFF34B7E8 /*'MovWriter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    MOV     R0, #1 \n"
"    STR     R0, [R11, #0xDC] \n"
"    LDRH    R0, [R11, #4] \n"
"    MVN     R1, #0x10000 \n"
"    AND     R0, R1, R0, LSL#1 \n"
"    STRH    R0, [R11, #4] \n"
"    LDR     R0, [R11, #0xF8] \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R0, [R11, #0xF8] \n"
"    LDR     R0, [R11, #0xA0] \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R0, [R11, #0xA0] \n"
"    LDR     R0, [R11, #0xA4] \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R0, [R11, #0xA4] \n"

"loc_FF34DD4C:\n"
"    LDR     R0, [R11, #0xD8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF34DD68 \n"
"    LDR     R1, [R4, #8] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF0D35A4 \n"
"    B       loc_FF34DD7C \n"

"loc_FF34DD68:\n"
"    LDRH    R3, [R4, #0x14] \n"
"    LDR     R2, [R4, #8] \n"
"    LDR     R1, [SP] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF0D34D8 \n"

"loc_FF34DD7C:\n"
"    LDR     R1, [R11, #0xA0] \n"
"    ADD     R0, R0, R1 \n"

"loc_FF34DD84:\n"
"    STR     R0, [R11, #0x98] \n"
"    ADD     SP, SP, #0x14 \n"
"    LDMFD   SP!, {R4-R11,PC} \n"

"loc_FF34DD90:\n"
"    ADD     R0, R0, R1 \n"
"    ADD     R0, R0, #0x1F \n"
"    BIC     R0, R0, #0x1F \n"
"    STR     R0, [R11, #0x110] \n"
"    LDR     R1, [R11, #0xB8] \n"
"    MOV     R2, R8 \n"
"    ADD     R0, R0, R1 \n"
"    SUB     R1, R9, R0 \n"
"    MOV     R1, R1, LSR#15 \n"
"    MOV     R1, R1, LSL#15 \n"
"    STR     R0, [R11, #0x114] \n"
"    ADD     R0, R0, R1 \n"
"    STR     R1, [R11, #0x120] \n"
"    STR     R0, [R11, #0x118] \n"
"    LDRH    R3, [R4, #0x14] \n"
"    LDR     R1, [SP] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF0D34D8 \n"
"    B       loc_FF34DD84 \n"
);
}
