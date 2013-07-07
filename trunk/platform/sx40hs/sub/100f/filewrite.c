/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7   // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * pdc is required, everything after that is optional (DryOS < R50)
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 */
typedef struct
{
    int unkn1[5];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int unkn2;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFF337508 - 0xFF3375EC, length=58
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xF12C \n"

"loc_FF337510:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF02B0F4 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x33E \n"
"    LDRNE   R0, =0xFF3375FC \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF337510 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E0 \n"
"    B       loc_FF3375E8 \n"
"    B       loc_FF33756C \n"
"    B       loc_FF3375D8 \n"

"loc_FF33756C:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FF337578:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02B338 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF3375A4 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02B0F4 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF337578 \n"

"loc_FF3375A4:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF3375CC \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x173944 \n"
"    BL      sub_FF06A7D8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF068A54 \n"

"loc_FF3375CC:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF337510 \n"

"loc_FF3375D8:\n"
"    BL      sub_FF3377EC_my \n"  // --> Patched. Old value = 0xFF3377EC.
"    B       loc_FF337510 \n"

"loc_FF3375E0:\n"
"    BL      sub_FF337948_my \n"  // --> Patched. Old value = 0xFF337948.
"    B       loc_FF337510 \n"

"loc_FF3375E8:\n"
"    BL      sub_FF33739C_my \n"  // --> Patched. Old value = 0xFF33739C.
"    B       loc_FF337510 \n"
);
}

/*************************************************************/
//** sub_FF3377EC_my @ 0xFF3377EC - 0xFF337844, length=23
void __attribute__((naked,noinline)) sub_FF3377EC_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x3C \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF06A7D8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF068918 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF000348 \n"
"    LDR     R0, [R4, #0x4C] \n"
"    ADD     R7, R4, #0x50 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
"    LDR     R8, [R4, #8] \n"
"    BL      sub_FF1D4D70 \n"
//hook start
"    STMFD   SP!, {R4-R12,LR} \n"
"    MOV     R0, R4 \n"
"    BL      filewrite_main_hook \n"
"    LDMFD   SP!, {R4-R12,LR} \n"
//hook end
"    LDR     R9, =0x1B6 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R9 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFF337848 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF337948_my @ 0xFF337948 - 0xFF3379C8, length=33
void __attribute__((naked,noinline)) sub_FF337948_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF337974 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF33798C \n"
"    B       loc_FF337980 \n"

"loc_FF337974:\n"
"    LDR     R1, =0x29E \n"
"    LDR     R0, =0xFF3375FC \n"
"    BL      _DebugAssert \n"

"loc_FF337980:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FF337A20 \n"

"loc_FF33798C:\n"
"    LDR     R9, =0xF12C \n"
"    MOV     R4, R7 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _write.
"    LDR     PC, =0xFF3379CC \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF33739C_my @ 0xFF33739C - 0xFF3373D0, length=14
void __attribute__((naked,noinline)) sub_FF33739C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xF12C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF3373E4 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FF3373D0 \n"
"    BL      sub_FF027694 \n"
"    B       sub_FF3373D4 \n"

"loc_FF3373D0:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF3373D4 \n"  // Continue in firmware
);
}
