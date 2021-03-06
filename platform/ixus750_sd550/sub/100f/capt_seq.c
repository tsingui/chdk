/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF94E028 - 0xFF94E1B4, length=100
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    SUB     SP, SP, #4 \n"
"    MOV     R4, SP \n"
"    B       loc_FF94E180 \n"

"loc_FF94E038:\n"
"    LDR     R2, [SP] \n"
"    LDR     R3, [R2] \n"
"    MOV     R0, R2 \n"
"    CMP     R3, #0x14 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF94E154 \n"
"    .long   loc_FF94E0A4 \n"
"    .long   loc_FF94E0B0 \n"
"    .long   loc_FF94E0B8 \n"
"    .long   loc_FF94E0C8 \n"
"    .long   loc_FF94E0C0 \n"
"    .long   loc_FF94E0D0 \n"
"    .long   loc_FF94E0D8 \n"
"    .long   loc_FF94E0E4 \n"
"    .long   loc_FF94E0EC \n"
"    .long   loc_FF94E0F8 \n"
"    .long   loc_FF94E100 \n"
"    .long   loc_FF94E108 \n"
"    .long   loc_FF94E110 \n"
"    .long   loc_FF94E118 \n"
"    .long   loc_FF94E120 \n"
"    .long   loc_FF94E12C \n"
"    .long   loc_FF94E134 \n"
"    .long   loc_FF94E13C \n"
"    .long   loc_FF94E144 \n"
"    .long   loc_FF94E14C \n"
"    .long   loc_FF94E168 \n"

"loc_FF94E0A4:\n"
"    BL      sub_FF94F808 \n"
"    BL      shooting_expo_param_override\n"   // +
"    BL      sub_FF94BF50 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0B0:\n"
"    BL      sub_FF94DDF4_my \n"  // --> Patched. Old value = 0xFF94DDF4.
"    B       loc_FF94E164 \n"

"loc_FF94E0B8:\n"
"    BL      sub_FF94FB9C \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0C0:\n"
"    BL      sub_FF94EABC \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0C8:\n"
"    BL      sub_FF94EB18 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0D0:\n"
"    BL      sub_FF94ED0C \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0D8:\n"
"    BL      sub_FF94F8FC \n"
"    BL      sub_FF94BF50 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0E4:\n"
"    BL      sub_FF94DEA8 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0EC:\n"
"    BL      sub_FF94F964 \n"
"    BL      sub_FF94BF50 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E0F8:\n"
"    BL      sub_FF94EB18 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E100:\n"
"    BL      sub_FF95022C \n"
"    B       loc_FF94E164 \n"

"loc_FF94E108:\n"
"    BL      sub_FF9504B4 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E110:\n"
"    BL      sub_FF950528 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E118:\n"
"    BL      sub_FF9505E0 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E120:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF950678 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E12C:\n"
"    BL      sub_FF9507C8 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E134:\n"
"    BL      sub_FF95083C \n"
"    B       loc_FF94E164 \n"

"loc_FF94E13C:\n"
"    BL      sub_FF9508F4 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E144:\n"
"    BL      sub_FF9509C4 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E14C:\n"
"    BL      sub_FF9509F0 \n"
"    B       loc_FF94E164 \n"

"loc_FF94E154:\n"
"    MOV     R1, #0x2DC \n"
"    LDR     R0, =0xFF94DBA0 /*'ShootTask.c'*/ \n"
"    ADD     R1, R1, #2 \n"
"    BL      _DebugAssert \n"

"loc_FF94E164:\n"
"    LDR     R2, [SP] \n"

"loc_FF94E168:\n"
"    LDR     R3, =0x73EF4 \n"
"    LDR     R1, [R2, #4] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF8206E8 /*_SetEventFlag*/ \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF94DC1C \n"

"loc_FF94E180:\n"
"    LDR     R3, =0x73EF8 \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [R3] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FF820EA4 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF94E038 \n"
"    MOV     R1, #0x24C \n"
"    LDR     R0, =0xFF94DBA0 /*'ShootTask.c'*/ \n"
"    ADD     R1, R1, #3 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FF94DDF4_my @ 0xFF94DDF4 - 0xFF94DE70, length=32
void __attribute__((naked,noinline)) sub_FF94DDF4_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R5, [R0, #0xC] \n"
"    BL      sub_FF956524 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF94DE0C \n"
"    BL      sub_FF956530 \n"

"loc_FF94DE0C:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF94FBAC \n"
"    TST     R0, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BEQ     loc_FF94DE2C \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF94C3F4 \n"

"loc_FF94DE2C:\n"
"    BL      sub_FF989BEC \n"
"    BL      sub_FF94B82C \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF82572C \n"
"    ADD     R3, R5, R5, LSL#1 \n"
"    ADD     R4, R4, R3, LSL#5 \n"
"    STR     R0, [R4, #4] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF951558 \n"
"    BL      sub_FF9500F0 \n"
"    BL      sub_FF950090 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF950D44_my \n"  // --> Patched. Old value = 0xFF950D44.
"    BL      capt_seq_hook_raw_here\n"   // +
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF94C3F4 \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF950F40 \n"
);
}

/*************************************************************/
//** sub_FF950D44_my @ 0xFF950D44 - 0xFF950D78, length=14
void __attribute__((naked,noinline)) sub_FF950D44_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x73F6C \n"
"    LDR     R5, =0x6DB0 \n"
"    SUB     SP, SP, #4 \n"
"    MVN     R1, #0 \n"
"    STR     R0, [R5] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF820884 /*_ClearEventFlag*/ \n"
"    BL      sub_FF956780 \n"
"    LDR     R0, [R0, #0x7C] \n"
"    BL      sub_FF89F644 \n"
"    BL      sub_FF950CB8 \n"
"    BL      wait_until_remote_button_is_released\n"
"    BL      capt_seq_hook_set_nr\n"
"    LDR     R3, =0x6DB8 \n"
"    LDR     R0, [R3] \n"
"    LDR     PC, =0xFF950D7C \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8F5B50 - 0xFF8F5E88, length=207
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x14 \n"
"    MOV     R7, SP \n"
"    B       loc_FF8F5E44 \n"

"loc_FF8F5B60:\n"
"    CMP     R2, #0x19 \n"
"    BNE     loc_FF8F5B78 \n"
"    LDR     R0, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    B       loc_FF8F5BB0 \n"

"loc_FF8F5B78:\n"
"    SUB     R3, R2, #0x16 \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF8F5B90 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF8F5AF8 \n"
"    B       loc_FF8F5BA0 \n"

"loc_FF8F5B90:\n"
"    CMP     R2, #0x18 \n"
"    BNE     loc_FF8F5BBC \n"
"    BL      sub_FF8AB964 \n"
"    BL      sub_FF8AD7DC \n"

"loc_FF8F5BA0:\n"
"    LDR     R3, [SP] \n"
"    LDR     R0, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"

"loc_FF8F5BB0:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F3F6C \n"
"    B       loc_FF8F5E44 \n"

"loc_FF8F5BBC:\n"
"    CMP     R2, #0xC \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FF8F5C2C \n"
"    LDR     R1, [R12, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F5198 \n"
"    LDR     R3, [SP] \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    ADD     R0, R3, #4 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F531C \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x3C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x38] \n"
"    B       loc_FF8F5DF4 \n"

"loc_FF8F5C2C:\n"
"    SUB     R3, R2, #0xD \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF8F5CAC \n"
"    ADD     R6, SP, #0xC \n"
"    ADD     R5, SP, #4 \n"
"    MOV     R0, R12 \n"
"    MOV     R1, R6 \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF8F5398 \n"
"    MOV     R4, R0 \n"
"    CMP     R4, #3 \n"
"    CMPNE   R4, #1 \n"
"    BNE     loc_FF8F5C8C \n"
"    LDR     R12, [SP] \n"
"    MOV     R0, R5 \n"
"    LDR     R1, [R12, #0x24] \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F5AD8 \n"
"    B       loc_FF8F5DF4 \n"

"loc_FF8F5C8C:\n"
"    LDR     R12, [SP] \n"
"    MOV     R2, R4 \n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R3, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"
"    B       loc_FF8F5DF4 \n"

"loc_FF8F5CAC:\n"
"    CMP     R2, #0x14 \n"
"    BNE     loc_FF8F5D00 \n"
"    LDR     R1, [R12, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F4CF8 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F4EC8 \n"
"    B       loc_FF8F5DF4 \n"

"loc_FF8F5D00:\n"
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
"    B       loc_FF8F5DE0 \n"
"    .long   loc_FF8F5D84 \n"
"    .long   loc_FF8F5D8C \n"
"    .long   loc_FF8F5D94 \n"
"    .long   loc_FF8F5D94 \n"
"    .long   loc_FF8F5D84 \n"
"    .long   loc_FF8F5D8C \n"
"    .long   loc_FF8F5D94 \n"
"    .long   loc_FF8F5D94 \n"
"    .long   loc_FF8F5DAC \n"
"    .long   loc_FF8F5DAC \n"
"    .long   loc_FF8F5DD0 \n"
"    .long   loc_FF8F5DD8 \n"
"    .long   loc_FF8F5DE0 \n"
"    .long   loc_FF8F5DE0 \n"
"    .long   loc_FF8F5DE0 \n"
"    .long   loc_FF8F5D9C \n"
"    .long   loc_FF8F5DA4 \n"
"    .long   loc_FF8F5DB8 \n"
"    .long   loc_FF8F5DC0 \n"
"    .long   loc_FF8F5DC0 \n"
"    .long   loc_FF8F5DE0 \n"
"    .long   loc_FF8F5DC8 \n"

"loc_FF8F5D84:\n"
"    BL      sub_FF8F4448 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5D8C:\n"
"    BL      sub_FF8F4584 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5D94:\n"
"    BL      sub_FF8F46B4 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5D9C:\n"
"    BL      sub_FF8F4888 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DA4:\n"
"    BL      sub_FF8F4990 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DAC:\n"
"    BL      sub_FF8F4A54_my \n"  // --> Patched. Old value = 0xFF8F4A54.
"    MOV     R8, #0 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DB8:\n"
"    BL      sub_FF8F4B18 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DC0:\n"
"    BL      sub_FF8F4C00 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DC8:\n"
"    BL      sub_FF8F4F58 \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DD0:\n"
"    BL      sub_FF8F502C \n"
"    B       loc_FF8F5DDC \n"

"loc_FF8F5DD8:\n"
"    BL      sub_FF8F5118 \n"

"loc_FF8F5DDC:\n"
"    LDR     R12, [SP] \n"

"loc_FF8F5DE0:\n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R2, [R12, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x30] \n"

"loc_FF8F5DF4:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8F5E1C \n"
"    LDR     R1, [SP] \n"
"    LDR     R3, [R1, #0x24] \n"
"    ADD     R3, R3, R3, LSL#1 \n"
"    ADD     R1, R1, R3, LSL#1 \n"
"    MOV     R0, R6 \n"
"    SUB     R1, R1, #2 \n"
"    BL      sub_FF8F4300 \n"
"    B       loc_FF8F5E3C \n"

"loc_FF8F5E1C:\n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF8F42A4 \n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF8F43C0 \n"

"loc_FF8F5E3C:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F3F6C \n"

"loc_FF8F5E44:\n"
"    LDR     R3, =0x4FB18 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, R7 \n"
"    BL      sub_FF820EA4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R12, [SP] \n"
"    LDR     R2, [R12] \n"
"    CMP     R2, #0x1A \n"
"    BNE     loc_FF8F5B60 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF8F3F6C \n"
"    LDR     R3, =0x4FB14 \n"
"    MOV     R1, #1 \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF8206E8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x14 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF8F4A54_my @ 0xFF8F4A54 - 0xFF8F4B08, length=46
void __attribute__((naked,noinline)) sub_FF8F4A54_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x4FB14 \n"
"    MOV     R4, R0 \n"
"    MOV     R1, #0xE \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF820884 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FF8F400C \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8F413C \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8F41D8 \n"
"    LDR     R3, [R4] \n"
"    CMP     R3, #9 \n"
"    MOVEQ   R5, #0 \n"
"    CMP     R5, #1 \n"
"    LDR     R1, =0xFF8F3F9C \n"
"    MOV     R2, #2 \n"
"    BNE     loc_FF8F4AC0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FFA75964 \n"
"    LDR     R2, =0x4FB40 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    B       loc_FF8F4AC4 \n"

"loc_FF8F4AC0:\n"
"    BL      sub_FF8F4274 \n"

"loc_FF8F4AC4:\n"
"    STRH    R0, [R4, #4] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8AB5FC_my \n"  // --> Patched. Old value = 0xFF8AB5FC.
"    BL      sub_FF8AD580 \n"
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF8AD39C \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FF8AD460 \n"
"    CMP     R5, #1 \n"
"    MOV     R1, #2 \n"
"    MOV     R2, #0 \n"
"    LDMNEFD SP!, {R4,R5,PC} \n"
"    LDR     R3, =0x4FB14 \n"
"    LDR     R0, [R3] \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF8206D8 /*_WaitForAllEventFlag*/ \n"
);
}

/*************************************************************/
//** sub_FF8AB5FC_my @ 0xFF8AB5FC - 0xFF8AB654, length=23
void __attribute__((naked,noinline)) sub_FF8AB5FC_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R3, =0x53B8 \n"
"    LDR     R2, [R3] \n"
"    MOV     R3, R0, LSL#16 \n"
"    CMP     R2, #1 \n"
"    MOV     R1, #0x110 \n"
"    LDR     R0, =0xFF8AAF98 /*'Shutter.c'*/ \n"
"    MOV     R4, R3, ASR#16 \n"
"    BEQ     loc_FF8AB624 \n"
"    BL      _DebugAssert \n"

"loc_FF8AB624:\n"
"    MOV     R1, #0x114 \n"
"    CMN     R4, #0xC00 \n"
"    LDR     R3, =0x35FD6 \n"
"    LDR     R0, =0xFF8AAF98 /*'Shutter.c'*/ \n"
"    ADD     R1, R1, #2 \n"
"    LDREQSH R4, [R3] \n"
"    LDRNE   R3, =0x35FD6 \n"
"    CMN     R4, #0xC00 \n"
"    STRH    R4, [R3] \n"
"    BNE     loc_FF8AB650 \n"
"    BL      _DebugAssert \n"

"loc_FF8AB650:\n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8AB658 \n"  // Continue in firmware
);
}
