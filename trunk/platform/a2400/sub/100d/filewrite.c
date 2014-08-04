/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1;
    int file_offset;
    int full_size;
    int unkn2, unkn3, unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int seek_flag;
    char name[32];
} fwt_data_struct;
#define FWT_MUSTSEEK    2   // value of the masked seek_flag indicating seek is required
#define FWT_SEEKMASK    0xffffffff   // masks out unneeded bits of seek_flag

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFA557FC - 0xFFA55940, length=82
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R7, =0x9780 \n"
"    MOV     R6, #0 \n"

"loc_FFA55808:\n"
"    LDR     R0, [R7, #0x14] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R5, R7 \n"
"    BL      sub_003F7218 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x38E \n"
"    LDRNE   R0, =0xFFA55940 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xB \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFA55808 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55910 \n"
"    B       loc_FFA55918 \n"
"    B       loc_FFA5586C \n"
"    B       loc_FFA558DC \n"
"    B       loc_FFA558D4 \n"

"loc_FFA5586C:\n"
"    STR     R6, [SP] \n"

"loc_FFA55870:\n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R1, SP \n"
"    BL      sub_003F745C /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFA5589C \n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_003F7218 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFA55870 \n"

"loc_FFA5589C:\n"
"    LDR     R0, [R5, #8] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA558C8 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R5, #8] \n"
"    LDR     R0, =0x1319A4 \n"
"    STR     R6, [R5, #4] \n"
"    BL      sub_FF866698 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8649B0 \n"

"loc_FFA558C8:\n"
"    LDR     R0, [R5, #0x10] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFA55808 \n"

"loc_FFA558D4:\n"
"    BL      sub_FFA554F8_my \n"  // --> Patched. Old value = 0xFFA554F8. Open stage
"    B       loc_FFA55808 \n"

"loc_FFA558DC:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #8] \n"
"    MOV     R2, #0 \n"
"    BL      fwt_lseek \n"  // --> Patched. Old value = _lseek.
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOV     R1, R4 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    MOVNE   R0, #0 \n"
"    MOVEQ   R0, #7 \n"
"    BL      sub_FFA5543C \n"
"    B       loc_FFA55808 \n"

"loc_FFA55910:\n"
"    BL      sub_FFA55B38_my \n"  // --> Patched. Old value = 0xFFA55B38. Write stage
"    B       loc_FFA55808 \n"

"loc_FFA55918:\n"
"    BL      sub_FFA55664_my \n"  // --> Patched. Old value = 0xFFA55664. Close stage
"    B       loc_FFA55808 \n"
);
}

/*************************************************************/
//** sub_FFA554F8_my @ 0xFFA554F8 - 0xFFA55660, length=91
void __attribute__((naked,noinline)) sub_FFA554F8_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    LDR     R6, =0x9780 \n"
"    MOV     R4, R0 \n"
//hook start placed here to avoid bne a few instructions below
//R0 holds data block start
"    STMFD   SP!, {R4-R12,LR}\n"
"    BL      filewrite_main_hook\n"
"    LDMFD   SP!, {R4-R12,LR}\n"
//hook end
"    LDR     R0, [R6, #4] \n"
"    SUB     SP, SP, #0x3C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFA55634 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF866698 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF864874 \n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      sub_FF810364 \n"
"    LDR     R0, [R4, #0x50] \n"
"    LDR     R9, =0x1B6 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #0xC] \n"
"    ADD     R7, R4, #0x54 \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #0xC] \n"
"    LDR     R8, [R4, #0xC] \n"
"    LDR     R5, [R4, #0x10] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FFA555C4 \n"
"    MOV     R0, R7 \n"
"    BL      sub_FF831B44 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R7 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_003FC17C \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0x13] \n"
"    STR     R1, [SP, #0x24] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x2C] \n"
"    STR     R1, [SP, #0x28] \n"
"    ADD     R1, SP, #0x24 \n"
"    ADD     R0, SP, #4 \n"
"    STR     R5, [SP, #0x30] \n"
"    STR     R5, [SP, #0x34] \n"
"    STR     R5, [SP, #0x38] \n"
"    BL      sub_FF8641F0 \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R7 \n"
"    BL      _Open \n"

"loc_FFA555C4:\n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R6, #8] \n"
"    BNE     loc_FFA55600 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF866698 \n"
"    LDR     R1, [R6, #0x1C] \n"
"    BL      sub_FF8649B0 \n"
"    LDR     R1, [R6, #0x18] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FFA5565C \n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,LR} \n"
"    LDR     R0, =0x9200001 \n"
"    BX      R1 \n"

"loc_FFA55600:\n"
"    MOV     R0, #1 \n"
"    STR     R0, [R6, #4] \n"
"    LDR     R0, =0x1319A4 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x54 \n"
"    BL      sub_003FC364 \n"
//mod start
"    LDR     R3, =current_write_ignored\n"
"    LDR     R3, [R3]\n"
"    CMP     R3, #0\n"
"    BNE     loc_A\n" // jump over the next block
//mod end
"    LDR     R1, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF831814 \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, R4 \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FFA55658 \n"

"loc_FFA55634:\n"
"loc_A:\n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FFA55650 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, R4 \n"
"    BEQ     loc_FFA55658 \n"

"loc_FFA55650:\n"
"    MOV     R1, R4 \n"
"    MOV     R0, #9 \n"

"loc_FFA55658:\n"
"    BL      sub_FFA5543C \n"

"loc_FFA5565C:\n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FFA55B38_my @ 0xFFA55B38 - 0xFFA55C14, length=56
void __attribute__((naked,noinline)) sub_FFA55B38_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFA55B64 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x18]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FFA55B7C \n"
"    B       loc_FFA55B70 \n"

"loc_FFA55B64:\n"
"    LDR     R1, =0x2DD \n"
"    LDR     R0, =0xFFA55940 \n"
"    BL      _DebugAssert \n"

"loc_FFA55B70:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFA55C10 \n"

"loc_FFA55B7C:\n"
"    LDR     R9, =0x9780 \n"
"    MOV     R4, R7 \n"

"loc_FFA55B84:\n"
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
"    LDR     R0, [R9, #8] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFA55BE4 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FFA55B70 \n"

"loc_FFA55BE4:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    ADD     R8, R8, R0 \n"
"    MOVCS   R1, #0x308 \n"
"    LDRCS   R0, =0xFFA55940 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFA55B84 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFA55C10:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFA5543C \n"
);
}

/*************************************************************/
//** sub_FFA55664_my @ 0xFFA55664 - 0xFFA557F8, length=102
void __attribute__((naked,noinline)) sub_FFA55664_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x50] \n"
"    LDR     R5, =0x9780 \n"
"    CMP     R0, #3 \n"
"    SUB     SP, SP, #0x38 \n"
"    BEQ     loc_FFA557DC \n"
"    LDR     R0, [R5, #8] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA556B8 \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FFA556A4 \n"
//mod start
"    LDR     R3, =current_write_ignored\n"
"    LDR     R3, [R3]\n"
"    CMP     R3, #0\n"
"    BNE     loc_B\n" // jump over the next block
//mod end
"    BL      sub_FF831568 \n"
"    B       loc_FFA556A8 \n"

"loc_FFA556A4:\n"
"loc_B:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.

"loc_FFA556A8:\n"
"    CMP     R0, #0 \n"
"    MVN     R0, #0 \n"
"    STRNE   R6, [R4, #0x14] \n"
"    STR     R0, [R5, #8] \n"

"loc_FFA556B8:\n"
"    LDR     R0, [R4, #0x14] \n"
"    TST     R0, #1 \n"
"    BNE     loc_FFA557C0 \n"
"    LDR     R0, [R4, #0xC] \n"
"    TST     R0, #8 \n"
"    BNE     loc_FFA556DC \n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_FFA5570C \n"

"loc_FFA556DC:\n"
"    ADD     R1, SP, #0x20 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF864138 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x346 \n"
"    LDREQ   R0, =0xFFA55940 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R4, #4] \n"
"    ADD     R0, R0, R1 \n"
"    STR     R0, [SP, #0x28] \n"
"    B       loc_FFA5573C \n"

"loc_FFA5570C:\n"
"    LDR     R0, =0x81FF \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x20 \n"
"    STR     R0, [SP, #0x24] \n"
"    LDR     R0, [R4, #4] \n"
"    STR     R0, [SP, #0x28] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [SP, #0x2C] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [SP, #0x30] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [SP, #0x34] \n"

"loc_FFA5573C:\n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FFA557C0 \n"
"    ADD     R1, SP, #0x20 \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF8641F0 \n"
"    LDR     R0, [R4, #0x50] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFA557C0 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x54 \n"
"    MOV     R0, SP \n"
"    BL      sub_003FC364 \n"
"    MOV     R0, SP \n"
"    BL      _strlen \n"
"    MOV     R2, #0x54 \n"
"    ADD     R0, R0, SP \n"
"    MOV     R1, #0x4D \n"
"    STRB    R2, [R0, #-3] \n"
"    STRB    R1, [R0, #-2] \n"
"    MOV     R1, #0x50 \n"
"    STRB    R1, [R0, #-1] \n"
"    MOV     R1, SP \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF863A88 \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x164 \n"
"    LDREQ   R0, =0xFFA55940 \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, SP \n"
"    BL      sub_FF86464C \n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF86464C \n"

"loc_FFA557C0:\n"
"    ADD     R0, R4, #0x54 \n"
"    BL      sub_FF866698 \n"
"    LDR     R1, [R5, #0x1C] \n"
"    BL      sub_FF8649B0 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R5, #4] \n"
"    B       loc_FFA557E4 \n"

"loc_FFA557DC:\n"
"    LDR     R0, [R5, #0x1C] \n"
"    BLX     R0 \n"

"loc_FFA557E4:\n"
"    LDR     R1, [R5, #0x18] \n"
"    CMP     R1, #0 \n"
"    LDRNE   R0, [R4, #0x14] \n"
"    BLXNE   R1 \n"
"    ADD     SP, SP, #0x38 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}