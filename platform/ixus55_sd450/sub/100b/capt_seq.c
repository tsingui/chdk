/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF94D7F8 - 0xFF94D984, length=100
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    SUB     SP, SP, #4 \n"
"    MOV     R4, SP \n"
"    B       loc_FF94D950 \n"

"loc_FF94D808:\n"
"    LDR     R2, [SP] \n"
"    LDR     R3, [R2] \n"
"    MOV     R0, R2 \n"
"    CMP     R3, #0x14 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF94D924 \n"
"    .long   loc_FF94D874 \n"
"    .long   loc_FF94D880 \n"
"    .long   loc_FF94D888 \n"
"    .long   loc_FF94D898 \n"
"    .long   loc_FF94D890 \n"
"    .long   loc_FF94D8A0 \n"
"    .long   loc_FF94D8A8 \n"
"    .long   loc_FF94D8B4 \n"
"    .long   loc_FF94D8BC \n"
"    .long   loc_FF94D8C8 \n"
"    .long   loc_FF94D8D0 \n"
"    .long   loc_FF94D8D8 \n"
"    .long   loc_FF94D8E0 \n"
"    .long   loc_FF94D8E8 \n"
"    .long   loc_FF94D8F0 \n"
"    .long   loc_FF94D8FC \n"
"    .long   loc_FF94D904 \n"
"    .long   loc_FF94D90C \n"
"    .long   loc_FF94D914 \n"
"    .long   loc_FF94D91C \n"
"    .long   loc_FF94D938 \n"

"loc_FF94D874:\n"
"    BL      sub_FF94EFD0 \n"
"    BL      shooting_expo_param_override\n"   // +
"    BL      sub_FF94B720 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D880:\n"
"    BL      sub_FF94D5C4_my \n"  // --> Patched. Old value = 0xFF94D5C4.
"    B       loc_FF94D934 \n"

"loc_FF94D888:\n"
"    BL      sub_FF94F364 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D890:\n"
"    BL      sub_FF94E28C \n"
"    B       loc_FF94D934 \n"

"loc_FF94D898:\n"
"    BL      sub_FF94E2E8 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8A0:\n"
"    BL      sub_FF94E4D8 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8A8:\n"
"    BL      sub_FF94F0C4 \n"
"    BL      sub_FF94B720 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8B4:\n"
"    BL      sub_FF94D678 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8BC:\n"
"    BL      sub_FF94F12C \n"
"    BL      sub_FF94B720 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8C8:\n"
"    BL      sub_FF94E2E8 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8D0:\n"
"    BL      sub_FF94F9F0 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8D8:\n"
"    BL      sub_FF94FC78 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8E0:\n"
"    BL      sub_FF94FD04 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8E8:\n"
"    BL      sub_FF94FDBC \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8F0:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF94FE6C \n"
"    B       loc_FF94D934 \n"

"loc_FF94D8FC:\n"
"    BL      sub_FF94FFBC \n"
"    B       loc_FF94D934 \n"

"loc_FF94D904:\n"
"    BL      sub_FF950030 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D90C:\n"
"    BL      sub_FF9500E8 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D914:\n"
"    BL      sub_FF9501B8 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D91C:\n"
"    BL      sub_FF9501E4 \n"
"    B       loc_FF94D934 \n"

"loc_FF94D924:\n"
"    MOV     R1, #0x2DC \n"
"    LDR     R0, =0xFF94D370 /*'ShootTask.c'*/ \n"
"    ADD     R1, R1, #2 \n"
"    BL      _DebugAssert \n"

"loc_FF94D934:\n"
"    LDR     R2, [SP] \n"

"loc_FF94D938:\n"
"    LDR     R3, =0x7D444 \n"
"    LDR     R1, [R2, #4] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FC50 /*_SetEventFlag*/ \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF94D3EC \n"

"loc_FF94D950:\n"
"    LDR     R3, =0x7D448 \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [R3] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FF820400 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF94D808 \n"
"    MOV     R1, #0x24C \n"
"    LDR     R0, =0xFF94D370 /*'ShootTask.c'*/ \n"
"    ADD     R1, R1, #3 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FF94D5C4_my @ 0xFF94D5C4 - 0xFF94D640, length=32
void __attribute__((naked,noinline)) sub_FF94D5C4_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R5, [R0, #0xC] \n"
"    BL      sub_FF955D34 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF94D5DC \n"
"    BL      sub_FF955D40 \n"

"loc_FF94D5DC:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF94F374 \n"
"    TST     R0, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BEQ     loc_FF94D5FC \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF94BBC4 \n"

"loc_FF94D5FC:\n"
"    BL      sub_FF989274 \n"
"    BL      sub_FF94AFFC \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF82474C \n"
"    ADD     R3, R5, R5, LSL#1 \n"
"    ADD     R4, R4, R3, LSL#5 \n"
"    STR     R0, [R4, #4] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF950D50 \n"
"    BL      sub_FF94F8B8 \n"
"    BL      sub_FF94F858 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF950538_my \n"  // --> Patched. Old value = 0xFF950538.
"    BL      capt_seq_hook_raw_here\n"   // +
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF94BBC4 \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF950738 \n"
);
}

/*************************************************************/
//** sub_FF950538_my @ 0xFF950538 - 0xFF950564, length=12
void __attribute__((naked,noinline)) sub_FF950538_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x7D4BC \n"
"    LDR     R5, =0x6D68 \n"
"    SUB     SP, SP, #4 \n"
"    MVN     R1, #0 \n"
"    STR     R0, [R5] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FDEC /*_ClearEventFlag*/ \n"
"    BL      sub_FF955F90 \n"
"    LDR     R0, [R0, #0x7C] \n"
"    BL      sub_FF89DBA4 \n"
"    BL      sub_FF9504AC \n"
"    BL      wait_until_remote_button_is_released\n"
"    BL      capt_seq_hook_set_nr\n"
"    LDR     PC, =0xFF950568 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8F5274 - 0xFF8F55AC, length=207
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x14 \n"
"    MOV     R7, SP \n"
"    B       loc_FF8F5568 \n"

"loc_FF8F5284:\n"
"    CMP     R2, #0x19 \n"
"    BNE     loc_FF8F529C \n"
"    LDR     R0, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    B       loc_FF8F52D4 \n"

"loc_FF8F529C:\n"
"    SUB     R3, R2, #0x16 \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF8F52B4 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF8F521C \n"
"    B       loc_FF8F52C4 \n"

"loc_FF8F52B4:\n"
"    CMP     R2, #0x18 \n"
"    BNE     loc_FF8F52E0 \n"
"    BL      sub_FF8AA678 \n"
"    BL      sub_FF8AC4F0 \n"

"loc_FF8F52C4:\n"
"    LDR     R3, [SP] \n"
"    LDR     R0, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"

"loc_FF8F52D4:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F3690 \n"
"    B       loc_FF8F5568 \n"

"loc_FF8F52E0:\n"
"    CMP     R2, #0xC \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FF8F5350 \n"
"    LDR     R1, [R12, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F48BC \n"
"    LDR     R3, [SP] \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    ADD     R0, R3, #4 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F4A40 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x3C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x38] \n"
"    B       loc_FF8F5518 \n"

"loc_FF8F5350:\n"
"    SUB     R3, R2, #0xD \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF8F53D0 \n"
"    ADD     R6, SP, #0xC \n"
"    ADD     R5, SP, #4 \n"
"    MOV     R0, R12 \n"
"    MOV     R1, R6 \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF8F4ABC \n"
"    MOV     R4, R0 \n"
"    CMP     R4, #3 \n"
"    CMPNE   R4, #1 \n"
"    BNE     loc_FF8F53B0 \n"
"    LDR     R12, [SP] \n"
"    MOV     R0, R5 \n"
"    LDR     R1, [R12, #0x24] \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F51FC \n"
"    B       loc_FF8F5518 \n"

"loc_FF8F53B0:\n"
"    LDR     R12, [SP] \n"
"    MOV     R2, R4 \n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R3, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    B       loc_FF8F5518 \n"

"loc_FF8F53D0:\n"
"    CMP     R2, #0x14 \n"
"    BNE     loc_FF8F5424 \n"
"    LDR     R1, [R12, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F441C \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F45EC \n"
"    B       loc_FF8F5518 \n"

"loc_FF8F5424:\n"
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
"    B       loc_FF8F5504 \n"
"    .long   loc_FF8F54A8 \n"
"    .long   loc_FF8F54B0 \n"
"    .long   loc_FF8F54B8 \n"
"    .long   loc_FF8F54B8 \n"
"    .long   loc_FF8F54A8 \n"
"    .long   loc_FF8F54B0 \n"
"    .long   loc_FF8F54B8 \n"
"    .long   loc_FF8F54B8 \n"
"    .long   loc_FF8F54D0 \n"
"    .long   loc_FF8F54D0 \n"
"    .long   loc_FF8F54F4 \n"
"    .long   loc_FF8F54FC \n"
"    .long   loc_FF8F5504 \n"
"    .long   loc_FF8F5504 \n"
"    .long   loc_FF8F5504 \n"
"    .long   loc_FF8F54C0 \n"
"    .long   loc_FF8F54C8 \n"
"    .long   loc_FF8F54DC \n"
"    .long   loc_FF8F54E4 \n"
"    .long   loc_FF8F54E4 \n"
"    .long   loc_FF8F5504 \n"
"    .long   loc_FF8F54EC \n"

"loc_FF8F54A8:\n"
"    BL      sub_FF8F3B6C \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54B0:\n"
"    BL      sub_FF8F3CA8 \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54B8:\n"
"    BL      sub_FF8F3DD8 \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54C0:\n"
"    BL      sub_FF8F3FAC \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54C8:\n"
"    BL      sub_FF8F40B4 \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54D0:\n"
"    BL      sub_FF8F4178_my \n"  // --> Patched. Old value = 0xFF8F4178.
"    MOV     R8, #0 \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54DC:\n"
"    BL      sub_FF8F423C \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54E4:\n"
"    BL      sub_FF8F4324 \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54EC:\n"
"    BL      sub_FF8F467C \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54F4:\n"
"    BL      sub_FF8F4750 \n"
"    B       loc_FF8F5500 \n"

"loc_FF8F54FC:\n"
"    BL      sub_FF8F483C \n"

"loc_FF8F5500:\n"
"    LDR     R12, [SP] \n"

"loc_FF8F5504:\n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R2, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"

"loc_FF8F5518:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8F5540 \n"
"    LDR     R1, [SP] \n"
"    LDR     R3, [R1, #0x24] \n"
"    ADD     R3, R3, R3, LSL#1 \n"
"    ADD     R1, R1, R3, LSL#1 \n"
"    MOV     R0, R6 \n"
"    SUB     R1, R1, #2 \n"
"    BL      sub_FF8F3A24 \n"
"    B       loc_FF8F5560 \n"

"loc_FF8F5540:\n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF8F39C8 \n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF8F3AE4 \n"

"loc_FF8F5560:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F3690 \n"

"loc_FF8F5568:\n"
"    LDR     R3, =0x59068 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, R7 \n"
"    BL      sub_FF820400 /*_ReceiveMessageQueue*/ \n"
"    LDR     R12, [SP] \n"
"    LDR     R2, [R12] \n"
"    CMP     R2, #0x1A \n"
"    BNE     loc_FF8F5284 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF8F3690 \n"
"    LDR     R3, =0x59064 \n"
"    MOV     R1, #1 \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FC50 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x14 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF8F4178_my @ 0xFF8F4178 - 0xFF8F422C, length=46
void __attribute__((naked,noinline)) sub_FF8F4178_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x59064 \n"
"    MOV     R4, R0 \n"
"    MOV     R1, #0xE \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FDEC /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FF8F3730 \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8F3860 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8F38FC \n"
"    LDR     R3, [R4] \n"
"    CMP     R3, #9 \n"
"    MOVEQ   R5, #0 \n"
"    CMP     R5, #1 \n"
"    LDR     R1, =0xFF8F36C0 \n"
"    MOV     R2, #2 \n"
"    BNE     loc_FF8F41E4 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FFA753D0 \n"
"    LDR     R2, =0x59090 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    B       loc_FF8F41E8 \n"

"loc_FF8F41E4:\n"
"    BL      sub_FF8F3998 \n"

"loc_FF8F41E8:\n"
"    STRH    R0, [R4, #4] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8AA310_my \n"  // --> Patched. Old value = 0xFF8AA310.
"    BL      sub_FF8AC294 \n"
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF8AC0B0 \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FF8AC174 \n"
"    CMP     R5, #1 \n"
"    MOV     R1, #2 \n"
"    MOV     R2, #0 \n"
"    LDMNEFD SP!, {R4,R5,PC} \n"
"    LDR     R3, =0x59064 \n"
"    LDR     R0, [R3] \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF81FC40 /*_WaitForAllEventFlag*/ \n"
);
}

/*************************************************************/
//** sub_FF8AA310_my @ 0xFF8AA310 - 0xFF8AA368, length=23
void __attribute__((naked,noinline)) sub_FF8AA310_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R3, =0x539C \n"
"    LDR     R2, [R3] \n"
"    MOV     R3, R0, LSL#16 \n"
"    CMP     R2, #1 \n"
"    MOV     R1, #0x110 \n"
"    LDR     R0, =0xFF8A9CAC /*'Shutter.c'*/ \n"
"    MOV     R4, R3, ASR#16 \n"
"    BEQ     loc_FF8AA338 \n"
"    BL      _DebugAssert \n"

"loc_FF8AA338:\n"
"    MOV     R1, #0x114 \n"
"    CMN     R4, #0xC00 \n"
"    LDR     R3, =0x3F5BE \n"
"    LDR     R0, =0xFF8A9CAC /*'Shutter.c'*/ \n"
"    ADD     R1, R1, #2 \n"
"    LDREQSH R4, [R3] \n"
"    LDRNE   R3, =0x3F5BE \n"
"    CMN     R4, #0xC00 \n"
"    STRH    R4, [R3] \n"
"    BNE     loc_FF8AA364 \n"
"    BL      _DebugAssert \n"

"loc_FF8AA364:\n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8AA36C \n"  // Continue in firmware
);
}
