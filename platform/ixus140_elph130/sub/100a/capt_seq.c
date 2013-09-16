/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

// NOTE auto in P mode doesn't seem to ever enable dark frame, even if you override > 1.3 sec
static long *nrflag = (long*)(0xE4F0+4); // FF3634B8, 4th arg to  sub_FF2A49C4

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF0B06BC - 0xFF0B0950, length=166
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x9EA24 \n"
"    LDR     R7, =0x38E0 \n"
"    MOV     R6, #0 \n"

"loc_FF0B06CC:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_00677418 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0B06F8 \n"
"    LDR     R1, =0x475 \n"
"    LDR     R0, =0xFF0B0194 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF0B06F8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x22 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0B0918 \n"
"    B       loc_FF0B0794 \n"
"    B       loc_FF0B07AC \n"
"    B       loc_FF0B07B8 \n"
"    B       loc_FF0B07CC \n"
"    B       loc_FF0B07C4 \n"
"    B       loc_FF0B07D8 \n"
"    B       loc_FF0B07E0 \n"
"    B       loc_FF0B07E8 \n"
"    B       loc_FF0B07F4 \n"
"    B       loc_FF0B0820 \n"
"    B       loc_FF0B0800 \n"
"    B       loc_FF0B080C \n"
"    B       loc_FF0B0814 \n"
"    B       loc_FF0B0828 \n"
"    B       loc_FF0B0830 \n"
"    B       loc_FF0B0838 \n"
"    B       loc_FF0B0840 \n"
"    B       loc_FF0B0848 \n"
"    B       loc_FF0B0854 \n"
"    B       loc_FF0B085C \n"
"    B       loc_FF0B0864 \n"
"    B       loc_FF0B086C \n"
"    B       loc_FF0B0874 \n"
"    B       loc_FF0B087C \n"
"    B       loc_FF0B0884 \n"
"    B       loc_FF0B088C \n"
"    B       loc_FF0B0894 \n"
"    B       loc_FF0B089C \n"
"    B       loc_FF0B08A8 \n"
"    B       loc_FF0B08B0 \n"
"    B       loc_FF0B08BC \n"
"    B       loc_FF0B08F8 \n"
"    B       loc_FF0B0904 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0794:\n"
//"    BL      shooting_expo_iso_override\n"      // extra ISO override call doesn't appear to be needed on elph130
"    BL      sub_FF0B0EB4 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF0AE238 \n"
// try avoid intermittetant override failues on quick press, may not to be 100% effective
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF1F9248_my \n"  // --> Patched. Old value = 0xFF1F9248.
"    B       loc_FF0B0924 \n"

"loc_FF0B07AC:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF1F916C_my \n"  // --> Patched. Old value = 0xFF1F916C.
"    B       loc_FF0B0924 \n"

"loc_FF0B07B8:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF0B11C8 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B07C4:\n"
"    BL      sub_FF0B0AF0 \n"
"    B       loc_FF0B07D0 \n"

"loc_FF0B07CC:\n"
"    BL      sub_FF0B0E90 \n"

"loc_FF0B07D0:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B07D8:\n"
"    BL      sub_FF0B0E98 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B07E0:\n"
"    BL      sub_FF0B109C \n"
"    B       loc_FF0B07F8 \n"

"loc_FF0B07E8:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF1F92D8 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B07F4:\n"
"    BL      sub_FF0B1120 \n"

"loc_FF0B07F8:\n"
"    BL      sub_FF0AE238 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0800:\n"
"    LDR     R0, [R5, #0x58] \n"
"    BL      sub_FF0B1780 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B080C:\n"
"    BL      sub_FF0B1BAC \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0814:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0B1C10 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0820:\n"
"    BL      sub_FF0B0E90 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0828:\n"
"    BL      sub_FF1F8640 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0830:\n"
"    BL      sub_FF1F8878 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0838:\n"
"    BL      sub_FF1F8934 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0840:\n"
"    BL      sub_FF1F8A08 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0848:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF1F8CC0 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0854:\n"
"    BL      sub_FF1F8E24 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B085C:\n"
"    BL      sub_FF1F8EB8 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0864:\n"
"    BL      sub_FF1F8F60 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B086C:\n"
"    BL      sub_FF0B136C \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0874:\n"
"    BL      sub_FF0B1400 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B087C:\n"
"    BL      sub_FF1F8AD8 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0884:\n"
"    BL      sub_FF1F8B40 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B088C:\n"
"    BL      sub_FF0B4068 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0894:\n"
"    BL      sub_FF0B4160 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B089C:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF1F9070 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B08A8:\n"
"    BL      sub_FF1F90E0 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B08B0:\n"
"    BL      sub_FF0B42EC \n"
"    BL      sub_FF0B41B8 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B08BC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF1F9A48 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF1F9B7C \n"
"    LDR     R0, =0x9EB24 \n"
"    LDRH    R0, [R0, #0x8C] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8000 \n"
"    SUBNES  R1, R1, #0x230 \n"
"    BNE     loc_FF0B0924 \n"
"    BL      sub_FF0B4160 \n"
"    BL      sub_FF0B4798 \n"
"    BL      sub_FF0B45FC \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B08F8:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xD \n"
"    B       loc_FF0B090C \n"

"loc_FF0B0904:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xC \n"

"loc_FF0B090C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0AEB38 \n"
"    B       loc_FF0B0924 \n"

"loc_FF0B0918:\n"
"    LDR     R1, =0x5DA \n"
"    LDR     R0, =0xFF0B0194 \n"
"    BL      _DebugAssert \n"

"loc_FF0B0924:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_0067F164 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x116 \n"
"    LDREQ   R0, =0xFF0B0194 \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF0B06CC \n"
);
}

/*************************************************************/
//** sub_FF1F9248_my @ 0xFF1F9248 - 0xFF1F92D4, length=36
void __attribute__((naked,noinline)) sub_FF1F9248_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF0AFDA8 \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF0B5F14 \n"
"    LDR     R6, =0x80CC \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF1F92D0 \n"
"    BL      sub_FF0B0EA0 \n"
"    BL      sub_FF0B1F38 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF0B1F90 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #8 \n"
"    MOV     R0, #0x3F \n"
"    BL      _SetPropertyCase \n"
"    BL      sub_FF1F9D3C \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_0067F198 /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF36336C \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF363740_my \n"  // --> Patched. Old value = 0xFF363740.
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF1F92D0:\n"
"    STR     R5, [R6] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF1F916C_my @ 0xFF1F916C - 0xFF1F9224, length=47
void __attribute__((naked,noinline)) sub_FF1F916C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, =0x80CC \n"
"    LDR     R6, =0x9EA24 \n"
"    LDR     R0, [R0] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    BNE     sub_FF1F9228 \n"
"    LDR     R0, [R6, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF1F9228 \n"
"    BL      sub_FF0B1F38 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF0B1F90 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF0B5F14 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1F91E0 \n"
"    BL      sub_FF0AE9A8 \n"
"    MOV     R4, #1 \n"

"loc_FF1F91E0:\n"
"    TST     R4, #1 \n"
"    BNE     sub_FF1F9228 \n"
"    BL      sub_FF1F9D3C \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_0067F198 /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF362ABC \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     sub_FF1F9228 \n"
"    BL      sub_FF0B0EA0 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF36336C \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF0B77C4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF363740_my \n"  // --> Patched. Old value = 0xFF363740.
"    MOV     R4, R0 \n"
"    BL      capt_seq_hook_raw_here \n"         // added
"    LDR     PC, =0xFF1F9228 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF363740_my @ 0xFF363740 - 0xFF3637CC, length=36
void __attribute__((naked,noinline)) sub_FF363740_my() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF3632D4 \n"
"    BL      sub_FF1F980C \n"
"    LDR     R7, =0x9EA24 \n"
"    LDR     R9, =0x820D \n"
"    LDR     R0, [R7, #0x180] \n"
"    ADD     R6, R7, #0x100 \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF363788 \n"
"    LDRH    R0, [R7] \n"
"    CMP     R0, R9 \n"
"    LDRNEH  R0, [R6, #0x8A] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF15C34C \n"

"loc_FF363788:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0x170 \n"
"    LDRNE   R0, =0xFF3639F8 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFF362FD4 \n"
"    LDREQ   R0, =0xFF363698 \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF1110E0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF36341C_my \n"  // --> Patched. Old value = 0xFF36341C.
"    LDR     PC, =0xFF3637D0 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF36341C_my @ 0xFF36341C - 0xFF3634C0, length=42
void __attribute__((naked,noinline)) sub_FF36341C_my() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R6, =0x9EBF4 \n"
"    LDR     R5, =0x9EA24 \n"
"    MOV     R4, R0 \n"
"    LDR     R3, [R6] \n"
"    LDRSH   R2, [R6, #0xC] \n"
"    LDRSH   R1, [R6, #0xE] \n"
"    LDR     R0, [R5, #0x88] \n"
"    BL      sub_FF1AE7A0 \n"
"    MOV     R2, #2 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0xFA \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x2D9 \n"
"    LDRNE   R0, =0xFF36323C \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [R6, #0xC] \n"
"    LDRSH   R1, [SP, #8] \n"
"    BL      sub_FF159890 \n"
"    LDR     R0, [R5, #0xE4] \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R5] \n"
"    LDRNE   R1, =0x820D \n"
"    CMPNE   R0, R1 \n"
"    LDRNE   R0, =0x9EB24 \n"
"    LDRNEH  R0, [R0, #0x8A] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF3634C0 \n"
"    BL      _GetCCDTemperature \n"
"    LDR     R3, =0xE4F0 \n"
"    STRH    R0, [R4, #0xA8] \n"
"    SUB     R2, R3, #4 \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRSH   R2, [R6, #0xC] \n"
"    LDRH    R0, [R5, #0x5E] \n"
"    ADD     R3, R3, #4 \n"
"    BL      sub_FF2A49C4 \n"

"loc_FF3634C0:\n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDRH    R0, [R4, #0xA8] \n"
"    LDR     PC, =0xFF3634C4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF11D558 - 0xFF11DBE8, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x4CF8 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0xF2910 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF11D578:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_00677418 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF11D5C4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF11D724 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF11D6AC \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF11D508 \n"

"loc_FF11D5C4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF11D5F0 \n"
"    BL      sub_FF11EA8C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_0067F164 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF11D5F0:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF11D60C \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF11DBE0 \n"

"loc_FF11D60C:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF11D65C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0067F198 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF118BCC \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF1EB704 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0067F0A4 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1664 \n"
"    BNE     loc_FF11D718 \n"

"loc_FF11D648:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF11DBE0 \n"

"loc_FF11D65C:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF11D6A4 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF11D508 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0067F198 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF118BDC \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF1EB8A4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0067F0A4 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF11D648 \n"
"    LDR     R1, =0x166E \n"
"    B       loc_FF11D718 \n"

"loc_FF11D6A4:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF11D6BC \n"

"loc_FF11D6AC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF11D508 \n"
"    B       loc_FF11D648 \n"

"loc_FF11D6BC:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF11D6D4 \n"
"    BL      sub_FF109048 \n"
"    BL      sub_FF109E04 \n"
"    BL      sub_FF109918 \n"
"    B       loc_FF11D648 \n"

"loc_FF11D6D4:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF11D724 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_0067F198 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF118BFC \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF108A98 \n"
"    BL      sub_FF108D28 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_0067EFC0 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF11D648 \n"
"    LDR     R1, =0x1696 \n"

"loc_FF11D718:\n"
"    LDR     R0, =0xFF119360 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF11D648 \n"

"loc_FF11D724:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF11D78C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF11B918 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF11EEAC \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF11DAA4 \n"

"loc_FF11D78C:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF11D844 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF11BB7C \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF11D7E0 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF11D818 \n"

"loc_FF11D7E0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF11D82C \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF11D17C \n"

"loc_FF11D818:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF11D4A8 \n"
"    B       loc_FF11DAAC \n"

"loc_FF11D82C:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF11DAAC \n"

"loc_FF11D844:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF11D890 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF11A8EC \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF11AD30 \n"
"    B       loc_FF11DAAC \n"

"loc_FF11D890:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11D94C \n"
"    B       loc_FF11D94C \n"
"    B       loc_FF11D954 \n"
"    B       loc_FF11D95C \n"
"    B       loc_FF11D95C \n"
"    B       loc_FF11D95C \n"
"    B       loc_FF11D94C \n"
"    B       loc_FF11D954 \n"
"    B       loc_FF11D95C \n"
"    B       loc_FF11D95C \n"
"    B       loc_FF11D974 \n"
"    B       loc_FF11D974 \n"
"    B       loc_FF11DA80 \n"
"    B       loc_FF11DA88 \n"
"    B       loc_FF11DA88 \n"
"    B       loc_FF11DA88 \n"
"    B       loc_FF11DA88 \n"
"    B       loc_FF11DA90 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11D964 \n"
"    B       loc_FF11D96C \n"
"    B       loc_FF11D96C \n"
"    B       loc_FF11D96C \n"
"    B       loc_FF11D980 \n"
"    B       loc_FF11D980 \n"
"    B       loc_FF11D988 \n"
"    B       loc_FF11D9C0 \n"
"    B       loc_FF11D9F8 \n"
"    B       loc_FF11DA30 \n"
"    B       loc_FF11DA68 \n"
"    B       loc_FF11DA68 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA94 \n"
"    B       loc_FF11DA70 \n"
"    B       loc_FF11DA78 \n"

"loc_FF11D94C:\n"
"    BL      sub_FF1191E0 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D954:\n"
"    BL      sub_FF11949C \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D95C:\n"
"    BL      sub_FF1196C8 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D964:\n"
"    BL      sub_FF1199F4 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D96C:\n"
"    BL      sub_FF119C10 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D974:\n"
"    BL      sub_FF119FD0_my \n"  // --> Patched. Old value = 0xFF119FD0.
"    MOV     R8, #0 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D980:\n"
"    BL      sub_FF11A114 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D988:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF11EB30 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D9C0:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF11ECA8 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11D9F8:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF11ED60 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA30:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF11EE08 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA68:\n"
"    BL      sub_FF11A69C \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA70:\n"
"    BL      sub_FF11AE34 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA78:\n"
"    BL      sub_FF11B11C \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA80:\n"
"    BL      sub_FF11B3E0 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA88:\n"
"    BL      sub_FF11B5A0 \n"
"    B       loc_FF11DA94 \n"

"loc_FF11DA90:\n"
"    BL      sub_FF11B70C \n"

"loc_FF11DA94:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF11DAA4:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF11DAAC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF11DAE4 \n"
"    BGT     loc_FF11DAD4 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF11DB18 \n"
"    B       loc_FF11DAE4 \n"

"loc_FF11DAD4:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF11DB18 \n"

"loc_FF11DAE4:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF11DB18 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF11F0C0 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF11DB18:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF11DB68 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0xF2910 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006950D8 \n"
"    LDR     R0, =0xF291C \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006950D8 \n"
"    LDR     R0, =0xF2928 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_006950D8 \n"
"    B       loc_FF11DBE0 \n"

"loc_FF11DB68:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF11DBAC \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF118FC0 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF11DBDC \n"

"loc_FF11DBAC:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF118FC0 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF11DBDC:\n"
"    BL      sub_FF11912C \n"

"loc_FF11DBE0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF11EA8C \n"
"    B       loc_FF11D578 \n"
);
}

/*************************************************************/
//** sub_FF119FD0_my @ 0xFF119FD0 - 0xFF11A094, length=50
void __attribute__((naked,noinline)) sub_FF119FD0_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4CF8 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_0067F198 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF118C64 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF118E20 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF118E78 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF118ED0 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF118F28 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0xF2928 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF11A068 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF11A068 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF118BBC \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF1EB788 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF11A070 \n"

"loc_FF11A068:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF11A070:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF11A08C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF118C40 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF11EAEC \n"

"loc_FF11A08C:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF108D94_my \n"  // --> Patched. Old value = 0xFF108D94.
"    LDR     PC, =0xFF11A098 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF108D94_my @ 0xFF108D94 - 0xFF108DD4, length=17
void __attribute__((naked,noinline)) sub_FF108D94_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x4978 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x154 \n"
"    LDRNE   R0, =0xFF108BCC \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x15A \n"
"    LDREQ   R0, =0xFF108BCC \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF108DD8 \n"  // Continue in firmware
);
}
