/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 3 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1[5];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFA1B8B8 - 0xFFA1B998, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R4, =0x9214 \n"

"loc_FFA1B8C0:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF826978 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFA1B8F0 \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFA1B8F8 \n"
"    LDR     R0, [R4, #8] \n"
"    BL      _GiveSemaphore \n"

"loc_FFA1B8F0:\n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R1-R5,PC} \n"

"loc_FFA1B8F8:\n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #5 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFA1B8C0 \n"
"    B       loc_FFA1B920 \n"
"    B       loc_FFA1B984 \n"
"    B       loc_FFA1B98C \n"
"    B       loc_FFA1B98C \n"
"    B       loc_FFA1B98C \n"
"    B       loc_FFA1B994 \n"

"loc_FFA1B920:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFA1B928:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF826BBC /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFA1B954 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF826978 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFA1B928 \n"

"loc_FFA1B954:\n"
"    LDR     R0, [R4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA1B978 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4] \n"
"    LDR     R0, =0xCD228 \n"
"    BL      sub_FF8524C4 \n"
"    BL      sub_FF850A50 \n"

"loc_FFA1B978:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFA1B8C0 \n"

"loc_FFA1B984:\n"
"    BL      sub_FFA1BB6C_my \n"  // --> Patched. Old value = 0xFFA1BB6C. Open stage
"    B       loc_FFA1B8C0 \n"

"loc_FFA1B98C:\n"
"    BL      sub_FFA1BCB8_my \n"  // --> Patched. Old value = 0xFFA1BCB8. Write stage
"    B       loc_FFA1B8C0 \n"

"loc_FFA1B994:\n"
"    BL      sub_FFA1BDB4_my \n"  // --> Patched. Old value = 0xFFA1BDB4. Close stage
"    B       loc_FFA1B8C0 \n"
);
}

/*************************************************************/
//** sub_FFA1BB6C_my @ 0xFFA1BB6C - 0xFFA1BBAC, length=17
void __attribute__((naked,noinline)) sub_FFA1BB6C_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x2C \n"
"    SUB     SP, SP, #0x38 \n"
"    BL      sub_FF8524C4 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF850A00 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF84EEA8 \n"
"    LDR     R7, [R4, #8] \n"
"    LDR     R8, =0x1B6 \n"
"    ADD     R6, R4, #0x2C \n"
"    LDR     R5, [R4, #0xC] \n"
//hook start
"    STMFD SP!, {R4-R12,LR}\n"
"    MOV R0, R4\n"
"    BL filewrite_main_hook\n"
"    LDMFD SP!, {R4-R12,LR}\n"
//hook end
"    MOV     R0, R6 \n"
"    MOV     R1, R7 \n"
"    MOV     R2, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _open2.
"    LDR     PC, =0xFFA1BBB0 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFA1BCB8_my @ 0xFFA1BCB8 - 0xFFA1BDB0, length=63
void __attribute__((naked,noinline)) sub_FFA1BCB8_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #4 \n"
"    LDREQ   R6, [R4, #0x18] \n"
"    LDREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FFA1BCF4 \n"
"    CMP     R0, #5 \n"
"    LDREQ   R6, [R4, #0x20] \n"
"    LDREQ   R7, [R4, #0x1C] \n"
"    BEQ     loc_FFA1BCF4 \n"
"    CMP     R0, #6 \n"
"    BNE     loc_FFA1BD08 \n"
"    LDR     R6, [R4, #0x28] \n"
"    LDR     R7, [R4, #0x24] \n"

"loc_FFA1BCF4:\n"
"    CMP     R6, #0 \n"
"    BNE     loc_FFA1BD18 \n"

"loc_FFA1BCFC:\n"
"    MOV     R1, R4 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFA1BDAC \n"

"loc_FFA1BD08:\n"
"    LDR     R1, =0x20D \n"
"    LDR     R0, =0xFFA1BC98 \n"
"    BL      _DebugAssert \n"
"    B       loc_FFA1BCFC \n"

"loc_FFA1BD18:\n"
"    LDR     R9, =0x9214 \n"
"    MOV     R5, R6 \n"

"loc_FFA1BD20:\n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R5, #0x1000000 \n"
"    MOVLS   R8, R5 \n"
"    MOVHI   R8, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R8, R0 \n"
"    MOVHI   R8, R0 \n"
"    LDR     R0, [R9] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R4, #4] \n"
"    CMP     R8, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R4, #4] \n"
"    BEQ     loc_FFA1BD80 \n"
"    LDR     R0, =0x10B1 \n"
"    BL      sub_FF874010 /*_IsControlEventActive_FW*/ \n"
"    LDR     R1, =0x9200005 \n"
"    STR     R1, [R4, #0x10] \n"
"    B       loc_FFA1BCFC \n"

"loc_FFA1BD80:\n"
"    SUB     R5, R5, R0 \n"
"    CMP     R5, R6 \n"
"    ADD     R7, R7, R0 \n"
"    LDRCS   R0, =0xFFA1BC98 \n"
"    MOVCS   R1, #0x23C \n"
"    BLCS    _DebugAssert \n"
"    CMP     R5, #0 \n"
"    BNE     loc_FFA1BD20 \n"
"    LDR     R0, [R4] \n"
"    MOV     R1, R4 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFA1BDAC:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFA1B810 \n"
);
}

/*************************************************************/
//** sub_FFA1BDB4_my @ 0xFFA1BDB4 - 0xFFA1BDD0, length=8
void __attribute__((naked,noinline)) sub_FFA1BDB4_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R5, =0x9214 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5] \n"
"    SUB     SP, SP, #0x1C \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFA1BDE8 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFA1BDD4 \n"  // Continue in firmware
);
}
