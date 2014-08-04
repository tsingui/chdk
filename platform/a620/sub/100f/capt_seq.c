/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x6D44;

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFFD375D8 - 0xFFD37770, length=103
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    SUB     SP, SP, #4 \n"
"    MOV     R4, SP \n"
"    B       loc_FFD3773C \n"

"loc_FFD375E8:\n"
"    LDR     R2, [SP] \n"
"    LDR     R3, [R2] \n"
"    MOV     R0, R2 \n"
"    CMP     R3, #0x15 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FFD37714 \n"
"    .long   loc_FFD37658 \n"
"    .long   loc_FFD37664 \n"
"    .long   loc_FFD3766C \n"
"    .long   loc_FFD3767C \n"
"    .long   loc_FFD37674 \n"
"    .long   loc_FFD37684 \n"
"    .long   loc_FFD3768C \n"
"    .long   loc_FFD37698 \n"
"    .long   loc_FFD376A0 \n"
"    .long   loc_FFD376AC \n"
"    .long   loc_FFD376B4 \n"
"    .long   loc_FFD376BC \n"
"    .long   loc_FFD376C4 \n"
"    .long   loc_FFD376CC \n"
"    .long   loc_FFD376D4 \n"
"    .long   loc_FFD376E0 \n"
"    .long   loc_FFD376E8 \n"
"    .long   loc_FFD376F0 \n"
"    .long   loc_FFD376F8 \n"
"    .long   loc_FFD37704 \n"
"    .long   loc_FFD3770C \n"
"    .long   loc_FFD37724 \n"

"loc_FFD37658:\n"
"    BL      sub_FFD38DBC \n"
"    BL      shooting_expo_param_override\n"   // +
"    BL      sub_FFD35274 \n"
"    B       loc_FFD37720 \n"

"loc_FFD37664:\n"
"    BL      sub_FFD371E4_my \n"  // --> Patched. Old value = 0xFFD371E4.
"    B       loc_FFD37720 \n"

"loc_FFD3766C:\n"
"    BL      sub_FFD39150 \n"
"    B       loc_FFD37720 \n"

"loc_FFD37674:\n"
"    BL      sub_FFD38078 \n"
"    B       loc_FFD37720 \n"

"loc_FFD3767C:\n"
"    BL      sub_FFD380D4 \n"
"    B       loc_FFD37720 \n"

"loc_FFD37684:\n"
"    BL      sub_FFD382C4 \n"
"    B       loc_FFD37720 \n"

"loc_FFD3768C:\n"
"    BL      sub_FFD38EB0 \n"
"    BL      sub_FFD35274 \n"
"    B       loc_FFD37720 \n"

"loc_FFD37698:\n"
"    BL      sub_FFD372CC \n"
"    B       loc_FFD37720 \n"

"loc_FFD376A0:\n"
"    BL      sub_FFD38F18 \n"
"    BL      sub_FFD35274 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376AC:\n"
"    BL      sub_FFD380D4 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376B4:\n"
"    BL      sub_FFD397DC \n"
"    B       loc_FFD37720 \n"

"loc_FFD376BC:\n"
"    BL      sub_FFD39A64 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376C4:\n"
"    BL      sub_FFD39AF0 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376CC:\n"
"    BL      sub_FFD39BA8 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376D4:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FFD39C58 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376E0:\n"
"    BL      sub_FFD39DA8 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376E8:\n"
"    BL      sub_FFD39E1C \n"
"    B       loc_FFD37720 \n"

"loc_FFD376F0:\n"
"    BL      sub_FFD39ED4 \n"
"    B       loc_FFD37720 \n"

"loc_FFD376F8:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FFD39C58 \n"
"    B       loc_FFD37720 \n"

"loc_FFD37704:\n"
"    BL      sub_FFD39FD4 \n"
"    B       loc_FFD37720 \n"

"loc_FFD3770C:\n"
"    BL      sub_FFD3A000 \n"
"    B       loc_FFD37720 \n"

"loc_FFD37714:\n"
"    LDR     R0, =0xFFD36F68 \n"
"    MOV     R1, #0x2DC \n"
"    BL      _DebugAssert \n"

"loc_FFD37720:\n"
"    LDR     R2, [SP] \n"

"loc_FFD37724:\n"
"    LDR     R3, =0x7414C \n"
"    LDR     R1, [R2, #4] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFC0F8A4 /*_SetEventFlag*/ \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFD36FE4 \n"

"loc_FFD3773C:\n"
"    LDR     R3, =0x74150 \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [R3] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FFC10054 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFD375E8 \n"
"    MOV     R1, #0x24C \n"
"    LDR     R0, =0xFFD36F68 \n"
"    ADD     R1, R1, #1 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FFD371E4_my @ 0xFFD371E4 - 0xFFD37260, length=32
void __attribute__((naked,noinline)) sub_FFD371E4_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R5, [R0, #0xC] \n"
"    BL      sub_FFD400C8 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFD371FC \n"
"    BL      sub_FFD400D4 \n"

"loc_FFD371FC:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FFD39160 \n"
"    TST     R0, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BEQ     loc_FFD3721C \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FFD35710 \n"

"loc_FFD3721C:\n"
"    BL      sub_FFD75760 \n"
"    BL      sub_FFD34A68 \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFC14384 \n"
"    ADD     R3, R5, R5, LSL#1 \n"
"    ADD     R4, R4, R3, LSL#5 \n"
"    STR     R0, [R4, #4] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFD3AB6C \n"
"    BL      sub_FFD396A4 \n"
"    BL      sub_FFD39644 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFD3A354_my \n"  // --> Patched. Old value = 0xFFD3A354.
"    BL      capt_seq_hook_raw_here\n"   // +
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FFD35710 \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FFD3A554 \n"
);
}

/*************************************************************/
//** sub_FFD3A354_my @ 0xFFD3A354 - 0xFFD3A380, length=12
void __attribute__((naked,noinline)) sub_FFD3A354_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x741C4 \n"
"    LDR     R5, =0x6D40 \n"
"    SUB     SP, SP, #4 \n"
"    MVN     R1, #0 \n"
"    STR     R0, [R5] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFC0FA40 /*_ClearEventFlag*/ \n"
"    BL      sub_FFD40324 \n"
"    BL      wait_until_remote_button_is_released\n"
"    LDR     R0, [R0, #0x7C] \n"
//"  BL      _sub_FFC8C380 \n"  // Nullsub call removed
"    BL      sub_FFD3A2C8 \n"
"    BL      capt_seq_hook_set_nr\n"
"    LDR     PC, =0xFFD3A384 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFFCE32AC - 0xFFCE35E4, length=207
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x14 \n"
"    MOV     R7, SP \n"
"    B       loc_FFCE35A0 \n"

"loc_FFCE32BC:\n"
"    CMP     R2, #0x19 \n"
"    BNE     loc_FFCE32D4 \n"
"    LDR     R0, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    B       loc_FFCE330C \n"

"loc_FFCE32D4:\n"
"    SUB     R3, R2, #0x16 \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FFCE32EC \n"
"    MOV     R0, R12 \n"
"    BL      sub_FFCE3254 \n"
"    B       loc_FFCE32FC \n"

"loc_FFCE32EC:\n"
"    CMP     R2, #0x18 \n"
"    BNE     loc_FFCE3318 \n"
"    BL      sub_FFC981CC \n"
"    BL      sub_FFC9A044 \n"

"loc_FFCE32FC:\n"
"    LDR     R3, [SP] \n"
"    LDR     R0, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"

"loc_FFCE330C:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE15A4 \n"
"    B       loc_FFCE35A0 \n"

"loc_FFCE3318:\n"
"    CMP     R2, #0xC \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FFCE3388 \n"
"    LDR     R1, [R12, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE287C \n"
"    LDR     R3, [SP] \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    ADD     R0, R3, #4 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE2A00 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x3C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x38] \n"
"    B       loc_FFCE3550 \n"

"loc_FFCE3388:\n"
"    SUB     R3, R2, #0xD \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FFCE3408 \n"
"    ADD     R6, SP, #0xC \n"
"    ADD     R5, SP, #4 \n"
"    MOV     R0, R12 \n"
"    MOV     R1, R6 \n"
"    MOV     R2, R5 \n"
"    BL      sub_FFCE2A7C \n"
"    MOV     R4, R0 \n"
"    CMP     R4, #3 \n"
"    CMPNE   R4, #1 \n"
"    BNE     loc_FFCE33E8 \n"
"    LDR     R12, [SP] \n"
"    MOV     R0, R5 \n"
"    LDR     R1, [R12, #0x24] \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE3234 \n"
"    B       loc_FFCE3550 \n"

"loc_FFCE33E8:\n"
"    LDR     R12, [SP] \n"
"    MOV     R2, R4 \n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R3, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    B       loc_FFCE3550 \n"

"loc_FFCE3408:\n"
"    CMP     R2, #0x14 \n"
"    BNE     loc_FFCE345C \n"
"    LDR     R1, [R12, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE2354 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE25AC \n"
"    B       loc_FFCE3550 \n"

"loc_FFCE345C:\n"
"    ADD     R6, SP, #0xC \n"
"    ADD     R1, R12, #4 \n"
"    MOV     R0, R6 \n"
"    MOV     R2, #6 \n"
"    BL      _memcpy \n"
"    LDR     R12, [SP] \n"
"    LDR     R3, [R12] \n"
"    MOV     R0, R12 \n"
"    CMP     R3, #0x15 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FFCE353C \n"
"    .long   loc_FFCE34E0 \n"
"    .long   loc_FFCE34E8 \n"
"    .long   loc_FFCE34F0 \n"
"    .long   loc_FFCE34F0 \n"
"    .long   loc_FFCE34E0 \n"
"    .long   loc_FFCE34E8 \n"
"    .long   loc_FFCE34F0 \n"
"    .long   loc_FFCE34F0 \n"
"    .long   loc_FFCE3508 \n"
"    .long   loc_FFCE3508 \n"
"    .long   loc_FFCE352C \n"
"    .long   loc_FFCE3534 \n"
"    .long   loc_FFCE353C \n"
"    .long   loc_FFCE353C \n"
"    .long   loc_FFCE353C \n"
"    .long   loc_FFCE34F8 \n"
"    .long   loc_FFCE3500 \n"
"    .long   loc_FFCE3514 \n"
"    .long   loc_FFCE351C \n"
"    .long   loc_FFCE351C \n"
"    .long   loc_FFCE353C \n"
"    .long   loc_FFCE3524 \n"

"loc_FFCE34E0:\n"
"    BL      sub_FFCE1A80 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE34E8:\n"
"    BL      sub_FFCE1BBC \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE34F0:\n"
"    BL      sub_FFCE1CEC \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE34F8:\n"
"    BL      sub_FFCE1EC0 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE3500:\n"
"    BL      sub_FFCE1FC8 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE3508:\n"
"    BL      sub_FFCE208C_my \n"  // --> Patched. Old value = 0xFFCE208C.
"    MOV     R8, #0 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE3514:\n"
"    BL      sub_FFCE2150 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE351C:\n"
"    BL      sub_FFCE2238 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE3524:\n"
"    BL      sub_FFCE263C \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE352C:\n"
"    BL      sub_FFCE2710 \n"
"    B       loc_FFCE3538 \n"

"loc_FFCE3534:\n"
"    BL      sub_FFCE27FC \n"

"loc_FFCE3538:\n"
"    LDR     R12, [SP] \n"

"loc_FFCE353C:\n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R2, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"

"loc_FFCE3550:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FFCE3578 \n"
"    LDR     R1, [SP] \n"
"    LDR     R3, [R1, #0x24] \n"
"    ADD     R3, R3, R3, LSL#1 \n"
"    ADD     R1, R1, R3, LSL#1 \n"
"    MOV     R0, R6 \n"
"    SUB     R1, R1, #2 \n"
"    BL      sub_FFCE1938 \n"
"    B       loc_FFCE3598 \n"

"loc_FFCE3578:\n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FFCE18DC \n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FFCE19F8 \n"

"loc_FFCE3598:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFCE15A4 \n"

"loc_FFCE35A0:\n"
"    LDR     R3, =0x4FEE0 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, R7 \n"
"    BL      sub_FFC10054 /*_ReceiveMessageQueue*/ \n"
"    LDR     R12, [SP] \n"
"    LDR     R2, [R12] \n"
"    CMP     R2, #0x1A \n"
"    BNE     loc_FFCE32BC \n"
"    MOV     R0, R12 \n"
"    BL      sub_FFCE15A4 \n"
"    LDR     R3, =0x4FEDC \n"
"    MOV     R1, #1 \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFC0F8A4 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x14 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FFCE208C_my @ 0xFFCE208C - 0xFFCE2140, length=46
void __attribute__((naked,noinline)) sub_FFCE208C_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x4FEDC \n"
"    MOV     R4, R0 \n"
"    MOV     R1, #0xE \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFC0FA40 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FFCE1644 \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FFCE1774 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FFCE1810 \n"
"    LDR     R3, [R4] \n"
"    CMP     R3, #9 \n"
"    MOVEQ   R5, #0 \n"
"    CMP     R5, #1 \n"
"    LDR     R1, =0xFFCE15D4 \n"
"    MOV     R2, #2 \n"
"    BNE     loc_FFCE20F8 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FFE63A5C \n"
"    LDR     R2, =0x4FF08 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    B       loc_FFCE20FC \n"

"loc_FFCE20F8:\n"
"    BL      sub_FFCE18AC \n"

"loc_FFCE20FC:\n"
"    STRH    R0, [R4, #4] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FFC97E64_my \n"  // --> Patched. Old value = 0xFFC97E64.
"    BL      sub_FFC99DE8 \n"
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FFC99C04 \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FFC99CC8 \n"
"    CMP     R5, #1 \n"
"    MOV     R1, #2 \n"
"    MOV     R2, #0 \n"
"    LDMNEFD SP!, {R4,R5,PC} \n"
"    LDR     R3, =0x4FEDC \n"
"    LDR     R0, [R3] \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FFC0F894 /*_WaitForAllEventFlag*/ \n"
);
}

/*************************************************************/
//** sub_FFC97E64_my @ 0xFFC97E64 - 0xFFC97EBC, length=23
void __attribute__((naked,noinline)) sub_FFC97E64_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R3, =0x53AC \n"
"    LDR     R2, [R3] \n"
"    MOV     R3, R0, LSL#16 \n"
"    CMP     R2, #1 \n"
"    MOV     R1, #0x110 \n"
"    LDR     R0, =0xFFC97800 \n"
"    MOV     R4, R3, ASR#16 \n"
"    BEQ     loc_FFC97E8C \n"
"    BL      _DebugAssert \n"

"loc_FFC97E8C:\n"
"    MOV     R1, #0x114 \n"
"    CMN     R4, #0xC00 \n"
"    LDR     R3, =0x3635E \n"
"    LDR     R0, =0xFFC97800 \n"
"    ADD     R1, R1, #2 \n"
"    LDREQSH R4, [R3] \n"
"    LDRNE   R3, =0x3635E \n"
"    CMN     R4, #0xC00 \n"
"    STRH    R4, [R3] \n"
"    BNE     loc_FFC97EB8 \n"
"    BL      _DebugAssert \n"

"loc_FFC97EB8:\n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFFC97EC0 \n"  // Continue in firmware
);
}