#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x6E10;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FF9580EC_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4,R5,LR} \n" 
      "    LDR     R3, =0x748FC \n" 
      "    LDR     R5, =0x6E0C \n" 
      "    SUB     SP, SP, #4 \n" 
      "    MVN     R1, #0 \n" 
      "    STR     R0, [R5] \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF81FD74 \n" 
      "    BL      sub_FF95E3C0 \n" 
      "    BL      wait_until_remote_button_is_released\n" // +
      "    LDR     R0, [R0, #0x7C] \n" 
      //"    BL      sub_FF89FD28 \n" // - nullsub
      "    BL      sub_FF958060 \n" 
      "    BL      capt_seq_hook_set_nr\n" // +
      "    LDR     R3, =0x6E14 \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF8A0224 \n" 
      "    LDR     PC, =0xFF958128\n" // + continue in ROM
/*      "    LDR     R3, =0x6E10 \n" 
      "    LDR     R3, [R3] \n" 
      "    CMP     R3, #1 \n" 
      "    MOV     R4, #0 \n" 
      "    BNE     loc_FF958168 \n" 
      "    BL      sub_FF952190 \n" */
    );
}


void __attribute__((naked,noinline)) sub_FF954A30_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4,R5,LR} \n" 
      "    LDR     R5, [R0, #0xC] \n" 
      "    BL      sub_FF95E164 \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF954A48 \n" 
      "    BL      sub_FF95E170 \n" 
"loc_FF954A48:\n"
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF956E1C \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF956E5C \n" 
      "    TST     R0, #1 \n" 
      "    MOV     R2, R5 \n" 
      "    MOV     R1, #1 \n" 
      "    BEQ     loc_FF954A70 \n" 
      "    LDMFD   SP!, {R4,R5,LR} \n" 
      "    B       sub_FF952E48 \n" 
"loc_FF954A70:\n"
      "    BL      sub_FF995864 \n" 
      "    BL      sub_FF952190 \n" 
      "    MOV     R4, R0 \n" 
      "    BL      sub_FF824750 \n" 
      "    ADD     R3, R5, R5, LSL #1 \n" 
      "    ADD     R4, R4, R3, LSL #5 \n" 
      "    STR     R0, [R4, #4] \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF958904 \n" 
      "    BL      sub_FF9573C8 \n" 
      "    BL      sub_FF95736C \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF9580EC_my \n" // ->
      "    BL      capt_seq_hook_raw_here\n" // +
      "    MOV     R2, R5 \n" 
      "    MOV     R1, #1 \n" 
      "    BL      sub_FF952E48 \n" 
      "    LDMFD   SP!, {R4,R5,LR} \n" 
      "    B       sub_FF9582EC \n" 
    );
}

void __attribute__((naked,noinline)) capt_seq_task()
{
	asm volatile (
                 "STMFD   SP!, {R4,LR}\n"
                 "SUB     SP, SP, #4\n"
                 "MOV     R4, SP\n"
                 "B       loc_FF954F90\n"
"loc_FF954E3C:\n"
                 "LDR     R2, [SP,#0xC-0xC]\n"
                 "LDR     R3, [R2]\n"
                 "MOV     R0, R2\n"
                 "CMP     R3, #0x15\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FF954F68\n"
                 ".long loc_FF954EAC\n"
                 ".long loc_FF954EB8\n"
                 ".long loc_FF954EC0\n"
                 ".long loc_FF954ED0\n"
                 ".long loc_FF954EC8\n"
                 ".long loc_FF954ED8\n"
                 ".long loc_FF954EE0\n"
                 ".long loc_FF954EEC\n"
                 ".long loc_FF954EF4\n"
                 ".long loc_FF954F00\n"
                 ".long loc_FF954F08\n"
                 ".long loc_FF954F10\n"
                 ".long loc_FF954F18\n"
                 ".long loc_FF954F20\n"
                 ".long loc_FF954F28\n"
                 ".long loc_FF954F34\n"
                 ".long loc_FF954F3C\n"
                 ".long loc_FF954F44\n"
                 ".long loc_FF954F4C\n"
                 ".long loc_FF954F58\n"
                 ".long loc_FF954F60\n"
                 ".long loc_FF954F78\n"
"loc_FF954EAC:\n"
                 "BL      sub_FF9566B0\n"
                 "BL      shooting_expo_param_override\n" // +
                 "BL      sub_FF952984\n"
                 "B       loc_FF954F74\n"
"loc_FF954EB8:\n"
                 "BL      sub_FF954A30_my\n"    // ->
                 "B       loc_FF954F74\n"
"loc_FF954EC0:\n"
                 "BL      sub_FF956E0C\n"
                 "B       loc_FF954F74\n"
"loc_FF954EC8:\n"
                 "BL      sub_FF9558B4\n"
                 "B       loc_FF954F74\n"
"loc_FF954ED0:\n"
                 "BL      sub_FF955910\n"
                 "B       loc_FF954F74\n"
"loc_FF954ED8:\n"
                 "BL      sub_FF955B74\n"
                 "B       loc_FF954F74\n"
"loc_FF954EE0:\n"
                 "BL      sub_FF9567A4\n"
                 "BL      sub_FF952984\n"
                 "B       loc_FF954F74\n"
"loc_FF954EEC:\n"
                 "BL      sub_FF954B20\n"
                 "B       loc_FF954F74\n"
"loc_FF954EF4:\n"
                 "BL      sub_FF95680C\n"
                 "BL      sub_FF952984\n"
                 "B       loc_FF954F74\n"
"loc_FF954F00:\n"
                 "BL      sub_FF955910\n"
                 "B       loc_FF954F74\n"
"loc_FF954F08:\n"
                 "BL      sub_FF957504\n"
                 "B       loc_FF954F74\n"
"loc_FF954F10:\n"
                 "BL      sub_FF95782C\n"
                 "B       loc_FF954F74\n"
"loc_FF954F18:\n"
                 "BL      sub_FF9578B8\n"
                 "B       loc_FF954F74\n"
"loc_FF954F20:\n"
                 "BL      sub_FF957970\n"
                 "B       loc_FF954F74\n"
"loc_FF954F28:\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FF957A20\n"
                 "B       loc_FF954F74\n"
"loc_FF954F34:\n"
                 "BL      sub_FF957B70\n"
                 "B       loc_FF954F74\n"
"loc_FF954F3C:\n"
                 "BL      sub_FF957BE4\n"
                 "B       loc_FF954F74\n"
"loc_FF954F44:\n"
                 "BL      sub_FF957C9C\n"
                 "B       loc_FF954F74\n"
"loc_FF954F4C:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF957A20\n"
                 "B       loc_FF954F74\n"
"loc_FF954F58:\n"
                 "BL      sub_FF957D6C\n"
                 "B       loc_FF954F74\n"
"loc_FF954F60:\n"
                 "BL      sub_FF957D98\n"
                 "B       loc_FF954F74\n"
"loc_FF954F68:\n"
                 "LDR     R0, =0xFF9547B4\n"
                 "MOV     R1, #0x2DC\n"
                 "BL      sub_FF813A80\n"
"loc_FF954F74:\n"
                 "LDR     R2, [SP,#0xC-0xC]\n"
"loc_FF954F78:\n"
                 "LDR     R3, =0x74884\n"
                 "LDR     R1, [R2,#4]\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF81FBD8\n"
                 "LDR     R0, [SP,#0xC-0xC]\n"
                 "BL      sub_FF954830\n"
"loc_FF954F90:\n"
                 "LDR     R3, =0x74888\n"
                 "MOV     R1, R4\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R2, #0\n"
                 "BL      sub_FF820388\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FF954E3C\n"
                 "MOV     R1, #0x24C\n"
                 "LDR     R0, =0xFF9547B4\n"
                 "ADD     R1, R1, #1\n"
                 "BL      sub_FF813A80\n"
                 "BL      sub_FF821924\n"
                 "ADD     SP, SP, #4\n"
                 "LDMFD   SP!, {R4,PC}\n"
    );
}


void __attribute__((naked,noinline)) exp_drv_task() { // sub_FF8FB1F4
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    SUB     SP, SP, #0x14 \n" 
      "    MOV     R7, SP \n" 
      "    B       loc_FF8FB4E8 \n" 
"loc_FF8FB204:\n"
      "    CMP     R2, #0x19 \n" 
      "    BNE     loc_FF8FB21C \n" 
      "    LDR     R0, [R12, #0x34] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R12, #0x30] \n" 
      "    B       loc_FF8FB254 \n" 
"loc_FF8FB21C:\n"
      "    SUB     R3, R2, #0x16 \n" 
      "    CMP     R3, #1 \n" 
      "    BHI     loc_FF8FB234 \n" 
      "    MOV     R0, R12 \n" 
      "    BL      sub_FF8FB19C \n" 
      "    B       loc_FF8FB244 \n" 
"loc_FF8FB234:\n"
      "    CMP     R2, #0x18 \n" 
      "    BNE     loc_FF8FB260 \n" 
      "    BL      sub_FF8AE1B8 \n" 
      "    BL      sub_FF8B0030 \n" 
"loc_FF8FB244:\n"
      "    LDR     R3, [SP] \n" 
      "    LDR     R0, [R3, #0x34] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3, #0x30] \n" 
"loc_FF8FB254:\n"
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8F938C \n" 
      "    B       loc_FF8FB4E8 \n" 
"loc_FF8FB260:\n"
      "    CMP     R2, #0xC \n" 
      "    MOV     R8, #1 \n" 
      "    BNE     loc_FF8FB2D0 \n" 
      "    LDR     R1, [R12, #0x24] \n" 
      "    ADD     R1, R1, R1, LSL #1 \n" 
      "    ADD     R1, R12, R1, LSL #1 \n" 
      "    ADD     R6, SP, #0xC \n" 
      "    SUB     R1, R1, #2 \n" 
      "    MOV     R2, #6 \n" 
      "    MOV     R0, R6 \n" 
      "    BL      sub_FFAFC6DC \n" 
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8FA668 \n" 
      "    LDR     R3, [SP] \n" 
      "    LDR     R1, [R3, #0x24] \n" 
      "    LDR     R2, [R3, #0x34] \n" 
      "    ADD     R0, R3, #4 \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3, #0x30] \n" 
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8FA7EC \n" 
      "    LDR     R3, [SP] \n" 
      "    ADD     R0, R3, #4 \n" 
      "    LDR     R1, [R3, #0x24] \n" 
      "    LDR     R2, [R3, #0x3C] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3, #0x38] \n" 
      "    B       loc_FF8FB498 \n" 
"loc_FF8FB2D0:\n"
      "    SUB     R3, R2, #0xD \n" 
      "    CMP     R3, #1 \n" 
      "    BHI     loc_FF8FB350 \n" 
      "    ADD     R6, SP, #0xC \n" 
      "    ADD     R5, SP, #4 \n" 
      "    MOV     R0, R12 \n" 
      "    MOV     R1, R6 \n" 
      "    MOV     R2, R5 \n" 
      "    BL      sub_FF8FA868 \n" 
      "    MOV     R4, R0 \n" 
      "    CMP     R4, #3 \n" 
      "    CMPNE   R4, #1 \n" 
      "    BNE     loc_FF8FB330 \n" 
      "    LDR     R12, [SP] \n" 
      "    MOV     R0, R5 \n" 
      "    LDR     R1, [R12, #0x24] \n" 
      "    MOV     R2, R4 \n" 
      "    LDR     R3, [R12, #0x34] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R12, #0x30] \n" 
      "    MOV     R1, R4 \n" 
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8FB17C \n" 
      "    B       loc_FF8FB498 \n" 
"loc_FF8FB330:\n"
      "    LDR     R12, [SP] \n" 
      "    MOV     R2, R4 \n" 
      "    ADD     R0, R12, #4 \n" 
      "    LDR     R1, [R12, #0x24] \n" 
      "    LDR     R3, [R12, #0x34] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R12, #0x30] \n" 
      "    B       loc_FF8FB498 \n" 
"loc_FF8FB350:\n"
      "    CMP     R2, #0x14 \n" 
      "    BNE     loc_FF8FB3A4 \n" 
      "    LDR     R1, [R12, #0x24] \n" 
      "    ADD     R1, R1, R1, LSL #1 \n" 
      "    ADD     R1, R12, R1, LSL #1 \n" 
      "    ADD     R6, SP, #0xC \n" 
      "    SUB     R1, R1, #2 \n" 
      "    MOV     R2, #6 \n" 
      "    MOV     R0, R6 \n" 
      "    BL      sub_FFAFC6DC \n" 
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8FA13C \n" 
      "    LDR     R3, [SP] \n" 
      "    ADD     R0, R3, #4 \n" 
      "    LDR     R1, [R3, #0x24] \n" 
      "    LDR     R2, [R3, #0x34] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3, #0x30] \n" 
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8FA398 \n" 
      "    B       loc_FF8FB498 \n" 
"loc_FF8FB3A4:\n"
      "    ADD     R6, SP, #0xC \n" 
      "    ADD     R1, R12, #4 \n" 
      "    MOV     R0, R6 \n" 
      "    MOV     R2, #6 \n" 
      "    BL      sub_FFAFC6DC \n" 
      "    LDR     R12, [SP] \n" 
      "    LDR     R3, [R12] \n" 
      "    MOV     R0, R12 \n" 
      "    CMP     R3, #0x15 \n" 
      "    LDRLS   PC, [PC, R3, LSL #2] \n" 
      "    B       loc_FF8FB484 \n" 
      "    .long   loc_FF8FB428 \n" 
      "    .long   loc_FF8FB430 \n" 
      "    .long   loc_FF8FB438 \n" 
      "    .long   loc_FF8FB438 \n" 
      "    .long   loc_FF8FB428 \n" 
      "    .long   loc_FF8FB430 \n" 
      "    .long   loc_FF8FB438 \n" 
      "    .long   loc_FF8FB438 \n" 
      "    .long   loc_FF8FB450 \n" 
      "    .long   loc_FF8FB450 \n" 
      "    .long   loc_FF8FB474 \n" 
      "    .long   loc_FF8FB47C \n" 
      "    .long   loc_FF8FB484 \n" 
      "    .long   loc_FF8FB484 \n" 
      "    .long   loc_FF8FB484 \n" 
      "    .long   loc_FF8FB440 \n" 
      "    .long   loc_FF8FB448 \n" 
      "    .long   loc_FF8FB45C \n" 
      "    .long   loc_FF8FB464 \n" 
      "    .long   loc_FF8FB464 \n" 
      "    .long   loc_FF8FB484 \n" 
      "    .long   loc_FF8FB46C \n" 
"loc_FF8FB428:\n" 
      "    BL      sub_FF8F9868 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB430:\n" 
      "    BL      sub_FF8F99A4 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB438:\n" 
      "    BL      sub_FF8F9AD4 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB440:\n" 
      "    BL      sub_FF8F9CA8 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB448:\n" 
      "    BL      sub_FF8F9DB0 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB450:\n" 
      "    BL      sub_FF8F9E74_my \n" // ->
      "    MOV     R8, #0 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB45C:\n" 
      "    BL      sub_FF8F9F38 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB464:\n" 
      "    BL      sub_FF8FA020 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB46C:\n" 
      "    BL      sub_FF8FA428 \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB474:\n" 
      "    BL      sub_FF8FA4FC \n" 
      "    B       loc_FF8FB480 \n" 
"loc_FF8FB47C:\n" 
      "    BL      sub_FF8FA5E8 \n" 
"loc_FF8FB480:\n"
      "    LDR     R12, [SP] \n" 
"loc_FF8FB484:\n"
      "    ADD     R0, R12, #4 \n" 
      "    LDR     R1, [R12, #0x24] \n" 
      "    LDR     R2, [R12, #0x34] \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R12, #0x30] \n" 
"loc_FF8FB498:\n"
      "    CMP     R8, #1 \n" 
      "    BNE     loc_FF8FB4C0 \n" 
      "    LDR     R1, [SP] \n" 
      "    LDR     R3, [R1, #0x24] \n" 
      "    ADD     R3, R3, R3, LSL #1 \n" 
      "    ADD     R1, R1, R3, LSL #1 \n" 
      "    MOV     R0, R6 \n" 
      "    SUB     R1, R1, #2 \n" 
      "    BL      sub_FF8F9720 \n" 
      "    B       loc_FF8FB4E0 \n" 
"loc_FF8FB4C0:\n"
      "    MOV     R0, #1 \n" 
      "    MOV     R1, R0 \n" 
      "    MOV     R2, R0 \n" 
      "    BL      sub_FF8F96C4 \n" 
      "    MOV     R0, #1 \n" 
      "    MOV     R1, R0 \n" 
      "    MOV     R2, R0 \n" 
      "    BL      sub_FF8F97E0 \n" 
"loc_FF8FB4E0:\n"
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF8F938C \n" 
"loc_FF8FB4E8:\n"
      "    LDR     R3, =0x50390 \n" 
      "    MOV     R2, #0 \n" 
      "    LDR     R0, [R3] \n" 
      "    MOV     R1, R7 \n" 
      "    BL      sub_FF820388 \n" 
      "    LDR     R12, [SP] \n" 
      "    LDR     R2, [R12] \n" 
      "    CMP     R2, #0x1A \n" 
      "    BNE     loc_FF8FB204 \n" 
      "    MOV     R0, R12 \n" 
      "    BL      sub_FF8F938C \n" 
      "    LDR     R3, =0x5038C \n" 
      "    MOV     R1, #1 \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF81FBD8 \n" 
      "    BL      sub_FF821924 \n" 
      "    ADD     SP, SP, #0x14 \n" 
      "    LDMFD   SP!, {R4-R8,PC} \n" 
    );
}

void __attribute__((naked,noinline)) sub_FF8F9E74_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4,R5,LR} \n" 
      "    LDR     R3, =0x5038C \n" 
      "    MOV     R4, R0 \n" 
      "    MOV     R1, #0xE \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF81FD74 \n" 
      "    MOV     R1, #0 \n" 
      "    LDRSH   R0, [R4, #4] \n" 
      "    BL      sub_FF8F942C \n" 
      "    MOV     R5, R0 \n" 
      "    LDRSH   R0, [R4, #6] \n" 
      "    BL      sub_FF8F955C \n" 
      "    LDRSH   R0, [R4, #8] \n" 
      "    BL      sub_FF8F95F8 \n" 
      "    LDR     R3, [R4] \n" 
      "    CMP     R3, #9 \n" 
      "    MOVEQ   R5, #0 \n" 
      "    CMP     R5, #1 \n" 
      "    LDR     R1, =0xFF8F93BC \n" 
      "    MOV     R2, #2 \n" 
      "    BNE     loc_FF8F9EE0 \n" 
      "    LDRSH   R0, [R4, #4] \n" 
      "    BL      sub_FFAA118C \n" 
      "    LDR     R2, =0x503B8 \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [R2] \n" 
      "    B       loc_FF8F9EE4 \n" 
"loc_FF8F9EE0:\n"
      "    BL      sub_FF8F9694 \n" 
"loc_FF8F9EE4:\n"
      "    STRH    R0, [R4, #4] \n" 
      "    LDRSH   R0, [R4, #6] \n" 
      "    BL      sub_FF8ADE50_my \n" // ->
      "    BL      sub_FF8AFDD4 \n" 
      "    LDRSH   R0, [R4, #8] \n" 
      "    MOV     R1, #1 \n" 
      "    BL      sub_FF8AFBF0 \n" 
      "    MOV     R1, #0 \n" 
      "    ADD     R0, R4, #8 \n" 
      "    BL      sub_FF8AFCB4 \n" 
      "    CMP     R5, #1 \n" 
      "    MOV     R1, #2 \n" 
      "    MOV     R2, #0 \n" 
      "    LDMNEFD SP!, {R4,R5,PC} \n" 
      "    LDR     R3, =0x5038C \n" 
      "    LDR     R0, [R3] \n" 
      "    LDMFD   SP!, {R4,R5,LR} \n" 
      "    B       sub_FF81FBC8 \n" 
    );
}

void __attribute__((naked,noinline)) sub_FF8ADE50_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4,LR} \n" 
      "    LDR     R3, =0x541C \n" 
      "    LDR     R2, [R3] \n" 
      "    MOV     R3, R0, LSL #0x10 \n" 
      "    CMP     R2, #1 \n" 
      "    MOV     R1, #0x110 \n" 
      "    LDR     R0, =0xFF8AD7EC \n" 
      "    MOV     R4, R3, ASR #0x10 \n" 
      "    BEQ     loc_FF8ADE78 \n" 
      "    BL      sub_FF813A80 \n" 
"loc_FF8ADE78:\n"
      "    MOV     R1, #0x114 \n" 
      "    CMN     R4, #0xC00 \n" 
      "    LDR     R3, =0x367BE \n" 
      "    LDR     R0, =0xFF8AD7EC \n" 
      "    ADD     R1, R1, #2 \n" 
      "    LDREQSH R4, [R3] \n" 
      "    LDRNE   R3, =0x367BE \n" 
      "    CMN     R4, #0xC00 \n" 
      "    STRH    R4, [R3] \n" 
      "    BNE     loc_FF8ADEA4 \n" 
      "    BL      sub_FF813A80 \n" 
"loc_FF8ADEA4:\n"
      "    MOV     R0, R4 \n" 
//      "    BL      sub_FF8AEF88 \n" // -
      "    BL      apex2us\n"         // +
      "    BL      sub_FF8AD3A4 \n" 
      "    TST     R0, #1 \n" 
      "    MOV     R1, #0x118 \n" 
      "    LDR     R0, =0xFF8AD7EC \n" 
      "    LDMEQFD SP!, {R4,PC} \n" 
      "    LDMFD   SP!, {R4,LR} \n" 
      "    B       sub_FF813A80 \n" 
    );
}