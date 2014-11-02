/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 300  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xF80C1810 - 0xF80C1AF0, length=185
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R4, =0xA31F0 \n"
"    LDR     R7, =0x3EC8 \n"
"    MOV     R6, #0 \n"

"loc_F80C1820:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_0068F164 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_F80C184C \n"
"    LDR     R1, =0x491 \n"
"    LDR     R0, =0xF80C1188 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_F80C184C:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x27 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_F80C1AB8 \n"
"    B       loc_F80C18FC \n"
"    B       loc_F80C1914 \n"
"    B       loc_F80C1920 \n"
"    B       loc_F80C1934 \n"
"    B       loc_F80C192C \n"
"    B       loc_F80C1940 \n"
"    B       loc_F80C1948 \n"
"    B       loc_F80C1950 \n"
"    B       loc_F80C196C \n"
"    B       loc_F80C19C0 \n"
"    B       loc_F80C1978 \n"
"    B       loc_F80C1984 \n"
"    B       loc_F80C198C \n"
"    B       loc_F80C19A8 \n"
"    B       loc_F80C19B0 \n"
"    B       loc_F80C19B8 \n"
"    B       loc_F80C19C8 \n"
"    B       loc_F80C19D0 \n"
"    B       loc_F80C19D8 \n"
"    B       loc_F80C19E0 \n"
"    B       loc_F80C19E8 \n"
"    B       loc_F80C19F0 \n"
"    B       loc_F80C19F8 \n"
"    B       loc_F80C1A00 \n"
"    B       loc_F80C1A08 \n"
"    B       loc_F80C1A10 \n"
"    B       loc_F80C1A1C \n"
"    B       loc_F80C1A24 \n"
"    B       loc_F80C1A30 \n"
"    B       loc_F80C1A38 \n"
"    B       loc_F80C1A40 \n"
"    B       loc_F80C1A48 \n"
"    B       loc_F80C1A50 \n"
"    B       loc_F80C1A58 \n"
"    B       loc_F80C1A60 \n"
"    B       loc_F80C1A6C \n"
"    B       loc_F80C1A74 \n"
"    B       loc_F80C1A80 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C18FC:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_F80C20A0 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_F80BE994 \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R4,#0x28]\n"                  // added, fixes overrides  behavior at short shutter press (from S95)
//"  LDR     R0, [R4, #0x28] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_F82676F4 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1914:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_F80C1C0C_my \n"  // --> Patched. Old value = 0xF80C1C0C.
"    B       loc_F80C1AC4 \n"

"loc_F80C1920:\n"
"    MOV     R0, #1 \n"
"    BL      sub_F80C23DC \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C192C:\n"
"    BL      sub_F80C1D58 \n"
"    B       loc_F80C1938 \n"

"loc_F80C1934:\n"
"    BL      sub_F80C2080 \n"

"loc_F80C1938:\n"
"    STR     R6, [R4, #0x28] \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1940:\n"
"    BL      sub_F80C2088 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1948:\n"
"    BL      sub_F80C22B4 \n"
"    B       loc_F80C1970 \n"

"loc_F80C1950:\n"
"    LDR     R5, [R0, #0x10] \n"
"    MOV     R0, R5 \n"
"    BL      sub_F82677C0 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    BL      sub_F80BF418 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C196C:\n"
"    BL      sub_F80C2344 \n"

"loc_F80C1970:\n"
"    BL      sub_F80BE994 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1978:\n"
"    LDR     R0, [R4, #0x58] \n"
"    BL      sub_F80C2ED4 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1984:\n"
"    BL      sub_F80C326C \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C198C:\n"
"    LDRH    R0, [R4] \n"
"    SUB     R1, R0, #0x8200 \n"
"    SUBS    R1, R1, #0x39 \n"
"    MOVNE   R0, #0 \n"
"    MOVEQ   R0, #1 \n"
"    BL      sub_F80C32D0 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19A8:\n"
"    BL      sub_F80C34B8 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19B0:\n"
"    BL      sub_F80C392C \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19B8:\n"
"    BL      sub_F80C39E0 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19C0:\n"
"    BL      sub_F80C2080 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19C8:\n"
"    BL      sub_F8265508 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19D0:\n"
"    BL      sub_F826573C \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19D8:\n"
"    BL      sub_F82657F4 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19E0:\n"
"    BL      sub_F82658A8 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19E8:\n"
"    BL      sub_F82659A8 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C19F0:\n"
"    MOV     R0, #0 \n"
"    B       loc_F80C1A14 \n"

"loc_F80C19F8:\n"
"    BL      sub_F8265BDC \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A00:\n"
"    BL      sub_F8265C70 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A08:\n"
"    BL      sub_F8265D18 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A10:\n"
"    MOV     R0, #1 \n"

"loc_F80C1A14:\n"
"    BL      sub_F8265A78 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A1C:\n"
"    BL      sub_F80C25F0 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A24:\n"
"    BL      sub_F80C2684 \n"
"    BL      sub_F8268B74 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A30:\n"
"    BL      sub_F80C294C \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A38:\n"
"    BL      sub_F80C2A84 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A40:\n"
"    BL      sub_F8268C48 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A48:\n"
"    BL      sub_F8036D20 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A50:\n"
"    BL      sub_F80C7BA0 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A58:\n"
"    BL      sub_F80C7CA0 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A60:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_F8265E20 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A6C:\n"
"    BL      sub_F8265E90 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A74:\n"
"    BL      sub_F80C7E2C \n"
"    BL      sub_F80C7CF8 \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1A80:\n"
"    MOV     R0, #1 \n"
"    BL      sub_F8267FF0 \n"
"    MOV     R0, #1 \n"
"    BL      sub_F8268124 \n"
"    LDRH    R0, [R4, #0xA4] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R4] \n"
"    SUBNE   R1, R0, #0x4200 \n"
"    SUBNES  R1, R1, #0x2E \n"
"    BNE     loc_F80C1AC4 \n"
"    BL      sub_F80C7CA0 \n"
"    BL      sub_F80C8544 \n"
"    BL      sub_F80C824C \n"
"    B       loc_F80C1AC4 \n"

"loc_F80C1AB8:\n"
"    LDR     R1, =0x5F2 \n"
"    LDR     R0, =0xF80C1188 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F80C1AC4:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_0068EED4 /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x117 \n"
"    LDREQ   R0, =0xF80C1188 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R5, #8] \n"
"    B       loc_F80C1820 \n"
);
}

/*************************************************************/
//** sub_F80C1C0C_my @ 0xF80C1C0C - 0xF80C1CAC, length=41
void __attribute__((naked,noinline)) sub_F80C1C0C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xA31F0 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_F80C1C5C \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x30 \n"
"    BLNE    sub_F80C6488 \n"
"    BL      sub_F80C5F50 \n"
"    MOV     R1, R6 \n"
"    BL      sub_F80C5FA8 \n"
"    LDR     R0, =0x10F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R6, #0x78 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R6, #0x7C \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"

"loc_F80C1C5C:\n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x20 \n"
"    MOV     R0, R6 \n"
"    BEQ     loc_F80C1C74 \n"
"    BL      sub_F82685BC \n"
"    B       loc_F80C1C78 \n"

"loc_F80C1C74:\n"
"    BL      sub_F826747C_my \n"  // --> Patched. Old value = 0xF826747C.
"    BL      capt_seq_hook_raw_here \n" // +++

"loc_F80C1C78:\n"
"    MOV     R4, R0 \n"
"    MOV     R2, R6 \n"
"    MOV     R1, #1 \n"
"    BL      sub_F80BF418 \n"
"    TST     R4, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_F8266438 \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #2 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    B       sub_F80BF5C0 \n"
);
}

/*************************************************************/
//** sub_F826747C_my @ 0xF826747C - 0xF82676F0, length=158
void __attribute__((naked,noinline)) sub_F826747C_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R6, =0xA31F0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R6, #0x28] \n"
"    LDR     R5, =0x420D \n"
"    CMP     R0, #0 \n"
"    MOV     R7, #0 \n"
"    BNE     loc_F8267520 \n"
"    LDR     R1, [R6, #0x94] \n"
"    TST     R1, #6 \n"
"    BNE     loc_F82674BC \n"
"    MOV     R0, #0xC \n"
"    BL      sub_F80CA308 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_F8267520 \n"
"    B       loc_F8267518 \n"

"loc_F82674BC:\n"
"    LDRH    R0, [R6] \n"
"    CMP     R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_F8267500 \n"
"    LDRH    R0, [R6, #0x9E] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_F82674EC \n"
"    TST     R1, #2 \n"
"    BNE     loc_F8267520 \n"

"loc_F82674EC:\n"
"    BL      sub_F801F980 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_F8267520 \n"
"    BL      sub_F80CA370 \n"
"    B       loc_F8267518 \n"

"loc_F8267500:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_F80CA308 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_F8267520 \n"
"    BL      sub_F8267E6C \n"
"    BL      sub_F80BF034 \n"

"loc_F8267518:\n"
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_F8267520:\n"
"    MOV     R0, R4 \n"
"    BL      sub_F8268CBC \n"
"    BL      sub_F80C2090 \n"
"    LDR     R0, [R6, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_F82676DC \n"
"    MOV     R0, R4 \n"
"    BL      sub_F8266324 \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R3-R7,PC} \n"
"    LDR     R0, [R6, #0x94] \n"
"    AND     R0, R0, #0x40 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6] \n"
"    CMPNE   R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_F826758C \n"
"    BL      sub_F82682E4 \n"
"    MOV     R3, #0xB3 \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xF826779C /*'SsCaptureSeq.c'*/ \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_F80CA580 \n"

"loc_F826758C:\n"
"    LDR     R0, [R6, #0x94] \n"
"    AND     R0, R0, #4 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6] \n"
"    CMPNE   R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_F82675C0 \n"
"    LDR     R0, [R6, #0x98] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_F82675CC \n"

"loc_F82675C0:\n"
"    MOV     R0, R4 \n"
"    BL      sub_F826685C \n"
"    BL      sub_F8267DB0 \n"

//begin patch
"    BL      wait_until_remote_button_is_released\n" // +++
"    BL      capt_seq_hook_set_nr\n" // +++
//end patch

"loc_F82675CC:\n"
"    LDRH    R0, [R6] \n"
"    CMP     R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_F81753B8 \n"
"    LDR     R0, [R6, #0x94] \n"
"    TST     R0, #4 \n"
"    BEQ     loc_F8267624 \n"
"    LDR     R0, [R6, #0x98] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_F8267624 \n"
"    LDRH    R0, [R6] \n"
"    CMP     R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #3 \n"
"    BLLS    sub_F81753B8 \n"

"loc_F8267624:\n"
"    LDR     R0, [R6, #0x94] \n"
"    TST     R0, #0x40 \n"
"    BEQ     loc_F826768C \n"
"    LDR     R0, =0x181 \n"
"    MOV     R2, #4 \n"
"    MOV     R1, SP \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xD4 \n"
"    LDRNE   R0, =0xF826779C /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_F826766C \n"
"    BL      sub_F82682E4 \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_0068EED4 /*_SetEventFlag*/ \n"
"    B       loc_F826768C \n"

"loc_F826766C:\n"
"    BL      sub_F82682E4 \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_0068EF08 /*_ClearEventFlag*/ \n"
"    LDR     R2, =0xF8267468 \n"
"    LDR     R0, [SP] \n"
"    MOV     R3, #0x8000 \n"
"    MOV     R1, R2 \n"
"    BL      sub_F8039EA8 /*_SetTimerAfter*/ \n"

"loc_F826768C:\n"
"    LDR     R0, [R6, #0x94] \n"
"    AND     R0, R0, #6 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6] \n"
"    CMPNE   R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #2 \n"
"    BLLS    sub_F80CBB48 \n"
"    LDR     R0, [R6, #0x94] \n"
"    TST     R0, #0x10 \n"
"    MOV     R0, R4 \n"
"    BEQ     loc_F82676D0 \n"
"    BL      sub_F8454D44 \n"
"    B       loc_F82676D4 \n"

"loc_F82676D0:\n"
"    BL      sub_F8266EA4 \n"

"loc_F82676D4:\n"
"    MOV     R7, R0 \n"
"    B       loc_F82676EC \n"

"loc_F82676DC:\n"
"    LDR     R0, =0xA5F0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R7, #0x1D \n"

"loc_F82676EC:\n"
"    MOV     R0, R7 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xF810CFA0 - 0xF810D630, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x5438 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0xC3A30 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_F810CFC0:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_0068F164 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F810D00C \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_F810D16C \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_F810D0F4 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_F810CF50 \n"

"loc_F810D00C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_F810D038 \n"
"    BL      sub_F810E4D4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_0068EED4 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_F810D038:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_F810D054 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_F810D628 \n"

"loc_F810D054:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_F810D0A4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0068EF08 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xF810869C \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_F8229E9C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0068EE14 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1643 \n"
"    BNE     loc_F810D160 \n"

"loc_F810D090:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_F810D628 \n"

"loc_F810D0A4:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_F810D0EC \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_F810CF50 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0068EF08 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xF81086AC \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_F822AC50 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0068EE14 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_F810D090 \n"
"    LDR     R1, =0x164D \n"
"    B       loc_F810D160 \n"

"loc_F810D0EC:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_F810D104 \n"

"loc_F810D0F4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_F810CF50 \n"
"    B       loc_F810D090 \n"

"loc_F810D104:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_F810D11C \n"
"    BL      sub_F80F7544 \n"
"    BL      sub_F80F831C \n"
"    BL      sub_F80F7E2C \n"
"    B       loc_F810D090 \n"

"loc_F810D11C:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_F810D16C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_0068EF08 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xF81086CC \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_F80F6F88 \n"
"    BL      sub_F80F7224 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_0068ED30 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_F810D090 \n"
"    LDR     R1, =0x1675 \n"

"loc_F810D160:\n"
"    LDR     R0, =0xF8108E4C /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_F810D090 \n"

"loc_F810D16C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_F810D1D4 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_F810B410 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_F810E8E0 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_F810D4EC \n"

"loc_F810D1D4:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_F810D28C \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_F810B674 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_F810D228 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_F810D260 \n"

"loc_F810D228:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_F810D274 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_F810CC40 \n"

"loc_F810D260:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_F810CEF0 \n"
"    B       loc_F810D4F4 \n"

"loc_F810D274:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_F810D4F4 \n"

"loc_F810D28C:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_F810D2D8 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_F810A3D8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_F810A834 \n"
"    B       loc_F810D4F4 \n"

"loc_F810D2D8:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D394 \n"
"    B       loc_F810D394 \n"
"    B       loc_F810D39C \n"
"    B       loc_F810D3A4 \n"
"    B       loc_F810D3A4 \n"
"    B       loc_F810D3A4 \n"
"    B       loc_F810D394 \n"
"    B       loc_F810D39C \n"
"    B       loc_F810D3A4 \n"
"    B       loc_F810D3A4 \n"
"    B       loc_F810D3BC \n"
"    B       loc_F810D3BC \n"
"    B       loc_F810D4C8 \n"
"    B       loc_F810D4D0 \n"
"    B       loc_F810D4D0 \n"
"    B       loc_F810D4D0 \n"
"    B       loc_F810D4D0 \n"
"    B       loc_F810D4D8 \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D3AC \n"
"    B       loc_F810D3B4 \n"
"    B       loc_F810D3B4 \n"
"    B       loc_F810D3B4 \n"
"    B       loc_F810D3C8 \n"
"    B       loc_F810D3C8 \n"
"    B       loc_F810D3D0 \n"
"    B       loc_F810D408 \n"
"    B       loc_F810D440 \n"
"    B       loc_F810D478 \n"
"    B       loc_F810D4B0 \n"
"    B       loc_F810D4B0 \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4DC \n"
"    B       loc_F810D4B8 \n"
"    B       loc_F810D4C0 \n"

"loc_F810D394:\n"
"    BL      sub_F8108C60 \n"
"    B       loc_F810D4DC \n"

"loc_F810D39C:\n"
"    BL      sub_F8108FA0 \n"
"    B       loc_F810D4DC \n"

"loc_F810D3A4:\n"
"    BL      sub_F810920C \n"
"    B       loc_F810D4DC \n"

"loc_F810D3AC:\n"
"    BL      sub_F8109504 \n"
"    B       loc_F810D4DC \n"

"loc_F810D3B4:\n"
"    BL      sub_F8109720 \n"
"    B       loc_F810D4DC \n"

"loc_F810D3BC:\n"
"    BL      sub_F8109B08_my \n"  // --> Patched. Old value = 0xF8109B08.
"    MOV     R8, #0 \n"
"    B       loc_F810D4DC \n"

"loc_F810D3C8:\n"
"    BL      sub_F8109C48 \n"
"    B       loc_F810D4DC \n"

"loc_F810D3D0:\n"
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
"    BL      sub_F810E568 \n"
"    B       loc_F810D4DC \n"

"loc_F810D408:\n"
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
"    BL      sub_F810E6E0 \n"
"    B       loc_F810D4DC \n"

"loc_F810D440:\n"
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
"    BL      sub_F810E794 \n"
"    B       loc_F810D4DC \n"

"loc_F810D478:\n"
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
"    BL      sub_F810E83C \n"
"    B       loc_F810D4DC \n"

"loc_F810D4B0:\n"
"    BL      sub_F810A16C \n"
"    B       loc_F810D4DC \n"

"loc_F810D4B8:\n"
"    BL      sub_F810A938 \n"
"    B       loc_F810D4DC \n"

"loc_F810D4C0:\n"
"    BL      sub_F810AC20 \n"
"    B       loc_F810D4DC \n"

"loc_F810D4C8:\n"
"    BL      sub_F810AEDC \n"
"    B       loc_F810D4DC \n"

"loc_F810D4D0:\n"
"    BL      sub_F810B09C \n"
"    B       loc_F810D4DC \n"

"loc_F810D4D8:\n"
"    BL      sub_F810B204 \n"

"loc_F810D4DC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_F810D4EC:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_F810D4F4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_F810D52C \n"
"    BGT     loc_F810D51C \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_F810D560 \n"
"    B       loc_F810D52C \n"

"loc_F810D51C:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_F810D560 \n"

"loc_F810D52C:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_F810D560 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_F810EAEC \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_F810D560:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_F810D5B0 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0xC3A30 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006AB658 \n"
"    LDR     R0, =0xC3A3C \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006AB658 \n"
"    LDR     R0, =0xC3A48 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_006AB658 \n"
"    B       loc_F810D628 \n"

"loc_F810D5B0:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_F810D5F4 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_F8108A34 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_F810D624 \n"

"loc_F810D5F4:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_F8108A34 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_F810D624:\n"
"    BL      sub_F8108BAC \n"

"loc_F810D628:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_F810E4D4 \n"
"    B       loc_F810CFC0 \n"
);
}

/*************************************************************/
//** sub_F8109B08_my @ 0xF8109B08 - 0xF8109C44, length=80
void __attribute__((naked,noinline)) sub_F8109B08_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x5438 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_0068EF08 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_F8108734 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_F8108894 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_F81088EC \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_F8108944 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_F810899C \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0xC3A48 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_F8109B9C \n"
"    CMP     R6, #1 \n"
"    BNE     loc_F8109B9C \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xF810868C \n"
"    MOV     R2, #2 \n"
"    BL      sub_F822A1BC \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_F8109BA4 \n"

"loc_F8109B9C:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_F8109BA4:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_F8109BC0 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xF8108710 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_F810E524 \n"

"loc_F8109BC0:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_F80F7290_my \n"  // --> Patched. Old value = 0xF80F7290.
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_F80F7AE4 \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_F80F7B6C \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_F81028F8 \n"
"    LDR     R4, =0xBB8 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_F8109C18 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #2 \n"
"    BL      sub_0068EE14 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R0, =0xF8108E4C /*'ExpDrv.c'*/ \n"
"    MOVNE   R1, #0x820 \n"
"    BLNE    _DebugAssert \n"

"loc_F8109C18:\n"
"    CMP     R5, #1 \n"
"    LDMNEFD SP!, {R4-R8,PC} \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #0x20 \n"
"    BL      sub_0068EE14 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R8,PC} \n"
"    LDMFD   SP!, {R4-R8,LR} \n"
"    LDR     R1, =0x825 \n"
"    LDR     R0, =0xF8108E4C /*'ExpDrv.c'*/ \n"
"    B       _DebugAssert \n"
);
}

/*************************************************************/
//** sub_F80F7290_my @ 0xF80F7290 - 0xF80F72F8, length=27
void __attribute__((naked,noinline)) sub_F80F7290_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x50A4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x154 \n"
"    LDRNE   R0, =0xF80F708C /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x15A \n"
"    LDREQ   R0, =0xF80F708C /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_F8174B6C \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_F817E2E4 \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    LDR     R1, =0x15F \n"
"    LDR     R0, =0xF80F708C /*'Shutter.c'*/ \n"
"    B       _DebugAssert \n"
);
}
