#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)(0x6cb8-0x08);  // Found @ ff94ff04 & ff94ff20

#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF876E70 

void __attribute__((naked,noinline)) capt_seq_task() {
 asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n" 
"    LDR     R6, =0x2B04 \n" 
"    LDR     R4, =0x4A5C8 \n" 
"    MOV     R9, #1 \n" 
"    MOV     R7, #0 \n" 
"loc_FF876E84:\n"
"    LDR     R0, [R6, #4] \n" 
"    MOV     R2, #0 \n" 
"    MOV     R1, SP \n" 
"    BL      sub_FF837F08 \n" 
"    TST     R0, #1 \n" 
"    BEQ     loc_FF876EB0 \n" 
"    LDR     R1, =0x5B3 \n" 
"    LDR     R0, =0xFF8769B0 \n" 
"    BL      sub_FF81E88C \n" 
"    BL      sub_FF81E844 \n" 
"    LDMFD   SP!, {R3-R9,PC} \n" 
"loc_FF876EB0:\n"
"    LDR     R0, [SP] \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x1F \n" 
"    ADDLS   PC, PC, R1, LSL #2 \n" 
"    B       loc_FF877154 \n" 
"    B       loc_FF876F44 \n" 
"    B       loc_FF876FA8 \n" 
"    B       loc_FF876FE4 \n" 
"    B       loc_FF876FF8 \n" 
"    B       loc_FF876FF0 \n" 
"    B       loc_FF877000 \n" 
"    B       loc_FF877008 \n" 
"    B       loc_FF877010 \n" 
"    B       loc_FF877068 \n" 
"    B       loc_FF877090 \n" 
"    B       loc_FF877074 \n" 
"    B       loc_FF877080 \n" 
"    B       loc_FF877088 \n" 
"    B       loc_FF877098 \n" 
"    B       loc_FF8770A0 \n" 
"    B       loc_FF8770A8 \n" 
"    B       loc_FF8770B0 \n" 
"    B       loc_FF8770B8 \n" 
"    B       loc_FF8770C4 \n" 
"    B       loc_FF8770CC \n" 
"    B       loc_FF8770D4 \n" 
"    B       loc_FF8770DC \n" 
"    B       loc_FF8770E4 \n" 
"    B       loc_FF8770F0 \n" 
"    B       loc_FF8770F8 \n" 
"    B       loc_FF877100 \n" 
"    B       loc_FF877108 \n" 
"    B       loc_FF877110 \n" 
"    B       loc_FF877118 \n" 
"    B       loc_FF877120 \n" 
"    B       loc_FF87712C \n" 
"    B       loc_FF877160 \n" 
"loc_FF876F44:\n"
"    BL      sub_FF8777F4 \n" 
"	BL      shooting_expo_param_override\n"  
"    BL      sub_FF874C6C \n" 

//  this code added to avoid some incorrect behavior if overrides are used.
 //  but it can cause some unexpected side effects. In this case, remove this code!
                 "MOV     R0, #0\n"
                 "STR     R0, [R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
//end of modified code                  
"    LDR     R0, [R4, #0x24] \n" 
"    CMP     R0, #0 \n" 
"    BEQ     loc_FF877160 \n" 
"    BL      sub_FF87668C \n" 
"    MOV     R5, R0 \n" 
"    LDR     R0, [R4, #0x24] \n" 
"    CMP     R0, #0 \n" 
"    BEQ     loc_FF876F8C \n" 
"    MOV     R0, #0xC \n" 
"    BL      sub_FF87BB14 \n" 
"    TST     R0, #1 \n" 
"    STRNE   R9, [R6, #0x10] \n" 
"    LDRNE   R0, [R5, #8] \n" 
"    ORRNE   R0, R0, #0x40000000 \n" 
"    STRNE   R0, [R5, #8] \n" 
"    BNE     loc_FF877160 \n" 
"loc_FF876F8C:\n"
"    MOV     R0, R5 \n" 
"    BL      sub_FF876930 \n" 
"    MOV     R0, R5 \n" 
"    BL      sub_FF94FE74_my \n"   //----------------->
"	BL      capt_seq_hook_raw_here\n"     
"    TST     R0, #1 \n" 
"    STRNE   R9, [R6, #0x10] \n" 
"    B       loc_FF877160 \n" 
"loc_FF876FA8:\n"
"    LDR     R0, [R4, #0x24] \n" 
"    CMP     R0, #0 \n" 
"    BNE     loc_FF876FD4 \n" 
"    MOV     R0, #0xC \n" 
"    BL      sub_FF87BB14 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R0, [SP] \n" 
"    MOVNE   R1, #1 \n" 
"    LDRNE   R2, [R0, #0xC] \n" 
"    MOVNE   R0, #1 \n" 
"    BNE     loc_FF877060 \n" 
"loc_FF876FD4:\n"
"    LDR     R0, [SP] \n" 
"    BL      sub_FF877278_my \n"    //----------------->          
"loc_FF876FDC:\n"
"    STR     R7, [R4, #0x24] \n" 
"    B       loc_FF877160 \n" 
"loc_FF876FE4:\n"
"    MOV     R0, #1 \n" 
"    BL      sub_FF877A50 \n" 
"    B       loc_FF877160 \n" 
"loc_FF876FF0:\n"
"    BL      sub_FF877430 \n" 
"    B       loc_FF876FDC \n" 
"loc_FF876FF8:\n"
"    BL      sub_FF8777D4 \n" 
"    B       loc_FF876FDC \n" 
"loc_FF877000:\n"
"    BL      sub_FF8777DC \n" 
"    B       loc_FF877160 \n" 
"loc_FF877008:\n"
"    BL      sub_FF877970 \n" 
"    B       loc_FF87706C \n" 
"loc_FF877010:\n"
"    LDR     R5, [R0, #0xC] \n" 
"    BL      sub_FF8777E4 \n" 
"    MOV     R0, R5 \n" 
"    BL      sub_FF94EB30 \n" 
"    TST     R0, #1 \n" 
"    MOV     R8, R0 \n" 
"    BNE     loc_FF877050 \n" 
"    BL      sub_FF888CD8 \n" 
"    STR     R0, [R5, #0x18] \n" 
"    MOV     R0, R5 \n" 
"    BL      sub_FF94FD8C \n" 
"    MOV     R0, R5 \n" 
"    BL      sub_FF95018C \n" 
"    MOV     R8, R0 \n" 
"    LDR     R0, [R5, #0x18] \n" 
"    BL      sub_FF888EEC \n" 
"loc_FF877050:\n"
"    BL      sub_FF8777D4 \n" 
"    MOV     R2, R5 \n" 
"    MOV     R1, #9 \n" 
"    MOV     R0, R8 \n" 
"loc_FF877060:\n"
"    BL      sub_FF875158 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877068:\n"
"    BL      sub_FF8779D0 \n" 
"loc_FF87706C:\n"
"    BL      sub_FF874C6C \n" 
"    B       loc_FF877160 \n" 
"loc_FF877074:\n"
"    LDR     R0, [R4, #0x54] \n" 
"    BL      sub_FF877DE0 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877080:\n"
"    BL      sub_FF878094 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877088:\n"
"    BL      sub_FF878128 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877090:\n"
"    BL      sub_FF8777D4 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877098:\n"
"    BL      sub_FF94ED48 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770A0:\n"
"    BL      sub_FF94EF5C \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770A8:\n"
"    BL      sub_FF94EFF4 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770B0:\n"
"    BL      sub_FF94F0C4 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770B8:\n"
"    MOV     R0, #0 \n" 
"    BL      sub_FF94F314 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770C4:\n"
"    BL      sub_FF94F470 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770CC:\n"
"    BL      sub_FF94F500 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770D4:\n"
"    BL      sub_FF94F5C0 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770DC:\n"
"    BL      sub_FF877BCC \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770E4:\n"
"    BL      sub_FF877C6C \n" 
"    BL      sub_FF835F60 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770F0:\n"
"    BL      sub_FF94F190 \n" 
"    B       loc_FF877160 \n" 
"loc_FF8770F8:\n"
"    BL      sub_FF94F1FC \n" 
"    B       loc_FF877160 \n" 
"loc_FF877100:\n"
"    BL      sub_FF87A1E8 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877108:\n"
"    BL      sub_FF87A254 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877110:\n"
"    BL      sub_FF94F740 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877118:\n"
"    BL      sub_FF94F7AC \n" 
"    B       loc_FF877160 \n" 
"loc_FF877120:\n"
"    BL      sub_FF87A2B0 \n" 
"    BL      sub_FF87A270 \n" 
"    B       loc_FF877160 \n" 
"loc_FF87712C:\n"
"    MOV     R0, #1 \n" 
"    BL      sub_FF950A04 \n" 
"    MOV     R0, #1 \n" 
"    BL      sub_FF950B14 \n" 
"    LDRH    R0, [R4, #0x98] \n" 
"    CMP     R0, #4 \n" 
"    BNE     loc_FF877160 \n" 
"    BL      sub_FF87A254 \n" 
"    BL      sub_FF87A728 \n" 
"    B       loc_FF877160 \n" 
"loc_FF877154:\n"
"    LDR     R1, =0x708 \n" 
"    LDR     R0, =0xFF8769B0 \n" 
"    BL      sub_FF81E88C \n" 
"loc_FF877160:\n"
"    LDR     R0, [SP] \n" 
"    LDR     R1, [R0, #4] \n" 
"    LDR     R0, [R6] \n" 
"    BL      sub_FF8809C4 \n" 
"    LDR     R5, [SP] \n" 
"    LDR     R0, [R5, #8] \n" 
"    CMP     R0, #0 \n" 
"    LDREQ   R1, =0x131 \n" 
"    LDREQ   R0, =0xFF8769B0 \n" 
"    BLEQ    sub_FF81E88C \n" 
"    STR     R7, [R5, #8] \n" 
"    B       loc_FF876E84 \n" 
);

}

//** sub_FF94FE74_my  @ 0xFF94FE74 

void __attribute__((naked,noinline)) sub_FF94FE74_my(){
 asm volatile(
"    STMFD   SP!, {R0-R8,LR} \n" 
"    MOV     R4, R0 \n" 
"    BL      sub_FF950D00 \n" 
"    MVN     R1, #0 \n" 
"    BL      sub_FF8809F8 \n" 
"    LDR     R5, =0x6CB0 \n" 
"    LDR     R0, [R5, #0xC] \n" 
"    CMP     R0, #0 \n" 
"    BNE     loc_FF94FEC4 \n" 
"    MOV     R1, #1 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF838750 \n" 
"    STR     R0, [R5, #0xC] \n" 
"    MOV     R3, #0 \n" 
"    STR     R3, [SP] \n" 
"    LDR     R3, =0xFF94F800 \n" 
"    LDR     R0, =0xFF9500F4 \n" 
"    MOV     R2, #0x400 \n" 
"    MOV     R1, #0x17 \n" 
"    BL      sub_FF83871C \n" 
"loc_FF94FEC4:\n"
"    MOV     R2, #4 \n" 
"    ADD     R1, SP, #8 \n" 
"    MOV     R0, #0x8A \n" 
"    BL      sub_FF888B48 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R1, =0x3C5 \n" 
"    LDRNE   R0, =0xFF94FA98 \n" 
"    BLNE    sub_FF81E88C \n" 
"    LDR     R6, =0x4A690 \n" 
"    LDR     R8, =0x4A5C8 \n" 
"    LDR     R3, [R6] \n" 
"    LDRSH   R2, [R6, #0xC] \n" 
"    LDRSH   R1, [R6, #0xE] \n" 
"    LDR     R0, [R8, #0x8C] \n" 
"    BL      sub_FF916320 \n" 
"    BL      sub_FF85E238 \n" 
"    LDR     R3, =0x6CB8 \n" 
"    STRH    R0, [R4, #0xA4] \n" 
"    SUB     R2, R3, #4 \n" 
"    STRD    R2, [SP] \n" 
"    MOV     R1, R0 \n" 
"    LDRH    R0, [R8, #0x5C] \n" 
"    LDRSH   R2, [R6, #0xC] \n" 
"    SUB     R3, R3, #8 \n" 
"    BL      sub_FF9523BC \n" 
"	BL  wait_until_remote_button_is_released\n"
"	BL  capt_seq_hook_set_nr\n"
"	B	sub_FF94FF28\n"//go to the ROM
 );
}

//** sub_FF877278_my  @ 0xFF877278 

void __attribute__((naked,noinline)) sub_FF877278_my(){
 asm volatile(
"    STMFD   SP!, {R4-R6,LR} \n" 
"    LDR     R4, [R0, #0xC] \n" 
"    LDR     R6, =0x4A5C8 \n" 
"    LDR     R0, [R4, #8] \n" 
"    MOV     R5, #0 \n" 
"    ORR     R0, R0, #1 \n" 
"    STR     R0, [R4, #8] \n" 
"    LDR     R0, [R6, #0x24] \n" 
"    CMP     R0, #0 \n" 
"    MOVEQ   R0, #2 \n" 
"    BLEQ    sub_FF873370 \n" 
"    BL      sub_FF8777E4 \n" 
"    LDR     R0, [R6, #0x24] \n" 
"    CMP     R0, #0 \n" 
"    BNE     loc_FF877354 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF950A04 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF950B14 \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF877B74 \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF94E780 \n" 
"    CMP     R0, #0 \n" 
"    BEQ     loc_FF877308 \n" 
"    BL      sub_FF950A44 \n" 
"    BL      sub_FF950B58 \n" 
"    BL      sub_FF950BA8 \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF94E864 \n" 
"    TST     R0, #1 \n" 
"    MOVNE   R2, R4 \n" 
"    LDMNEFD SP!, {R4-R6,LR} \n" 
"    MOVNE   R1, #1 \n" 
"    BNE     sub_FF875158 \n" 
"    B       loc_FF87731C \n" 
"loc_FF877308:\n"
"    MOV     R0, R4 \n" 
"    BL      sub_FF94E800 \n" 
"    BL      sub_FF950A44 \n" 
"    BL      sub_FF950B58 \n" 
"    BL      sub_FF950BA8 \n" 
"loc_FF87731C:\n"
"    MOV     R0, R4 \n" 
"    BL      sub_FF876930 \n" 
"    LDRH    R0, [R6] \n" 
"    SUB     R12, R0, #0x8200 \n" 
"    SUBS    R12, R12, #0xF \n" 
"    LDREQ   R0, [R4, #0x18] \n" 
"    BLEQ    sub_FF872E38 \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF94FD8C \n" 
"    BL      sub_FF95080C \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF94FE74_my \n"    //-----------------> 
"    MOV     R5, R0 \n" 
"	BL     capt_seq_hook_raw_here\n"   //-----------------> 
"    B       loc_FF877364 \n" 
"loc_FF877354:\n"
"    LDR     R0, =0x2B04 \n" 
"    LDR     R0, [R0, #0x10] \n" 
"    CMP     R0, #0 \n" 
"    MOVNE   R5, #0x1D \n" 
"loc_FF877364:\n"
"    BL      sub_FF87A254 \n" 
"    BL      sub_FF87A29C \n" 
"    BL      sub_FF87A2DC \n" 
"    MOV     R2, R4 \n" 
"    MOV     R1, #1 \n" 
"    MOV     R0, R5 \n" 
"    BL      sub_FF875158 \n" 
"    BL      sub_FF950130 \n" 
"    CMP     R0, #0 \n" 
"    LDRNE   R0, [R4, #8] \n" 
"    ORRNE   R0, R0, #0x2000 \n" 
"    STRNE   R0, [R4, #8] \n" 
"    LDMFD   SP!, {R4-R6,PC} \n" 
 );
}

//** exp_drv_task  @ 0xFF8BA2D4 

void __attribute__((naked,noinline)) exp_drv_task(){
 asm volatile(
"    STMFD   SP!, {R4-R8,LR} \n" 
"    SUB     SP, SP, #0x20 \n" 
"    LDR     R8, =0xBB8 \n" 
"    LDR     R7, =0x4130 \n" 
"    LDR     R5, =0x4F45C \n" 
"    MOV     R0, #0 \n" 
"    ADD     R6, SP, #0x10 \n" 
"    STR     R0, [SP, #0xC] \n" 
"loc_FF8BA2F4:\n"
"    LDR     R0, [R7, #0x20] \n" 
"    MOV     R2, #0 \n" 
"    ADD     R1, SP, #0x1C \n" 
"    BL      sub_FF837F08 \n" 
"    LDR     R0, [SP, #0xC] \n" 
"    CMP     R0, #1 \n" 
"    BNE     loc_FF8BA340 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R0, [R0] \n" 
"    CMP     R0, #0x13 \n" 
"    CMPNE   R0, #0x14 \n" 
"    CMPNE   R0, #0x15 \n" 
"    CMPNE   R0, #0x16 \n" 
"    BEQ     loc_FF8BA45C \n" 
"    CMP     R0, #0x28 \n" 
"    BEQ     loc_FF8BA434 \n" 
"    ADD     R1, SP, #0xC \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF8BA284 \n" 
"loc_FF8BA340:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x2D \n" 
"    BNE     loc_FF8BA370 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    BL      sub_FF8BB544 \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R1, #1 \n" 
"    BL      sub_FF8809C4 \n" 
"    BL      sub_FF81E844 \n" 
"    ADD     SP, SP, #0x20 \n" 
"    LDMFD   SP!, {R4-R8,PC} \n" 
"loc_FF8BA370:\n"
"    CMP     R1, #0x2C \n" 
"    BNE     loc_FF8BA38C \n" 
"    LDR     R2, [R0, #0x8C]! \n" 
"    LDR     R1, [R0, #4] \n" 
"    MOV     R0, R1 \n" 
"    BLX     R2 \n" 
"    B       loc_FF8BA884 \n" 
"loc_FF8BA38C:\n"
"    CMP     R1, #0x26 \n" 
"    BNE     loc_FF8BA3DC \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R1, #0x80 \n" 
"    BL      sub_FF8809F8 \n" 
"    LDR     R0, =0xFF8B69C4 \n" 
"    MOV     R1, #0x80 \n" 
"    BL      sub_FF94389C \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R2, R8 \n" 
"    MOV     R1, #0x80 \n" 
"    BL      sub_FF880904 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R1, =0xE57 \n" 
"    BNE     loc_FF8BA420 \n" 
"loc_FF8BA3C8:\n"
"    LDR     R1, [SP, #0x1C] \n" 
"    LDR     R0, [R1, #0x90] \n" 
"    LDR     R1, [R1, #0x8C] \n" 
"    BLX     R1 \n" 
"    B       loc_FF8BA884 \n" 
"loc_FF8BA3DC:\n"
"    CMP     R1, #0x27 \n" 
"    BNE     loc_FF8BA42C \n" 
"    ADD     R1, SP, #0xC \n" 
"    BL      sub_FF8BA284 \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R1, #0x100 \n" 
"    BL      sub_FF8809F8 \n" 
"    LDR     R0, =0xFF8B69D4 \n" 
"    MOV     R1, #0x100 \n" 
"    BL      sub_FF94422C \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R2, R8 \n" 
"    MOV     R1, #0x100 \n" 
"    BL      sub_FF880904 \n" 
"    TST     R0, #1 \n" 
"    BEQ     loc_FF8BA3C8 \n" 
"    LDR     R1, =0xE61 \n" 
"loc_FF8BA420:\n"
"    LDR     R0, =0xFF8B7034 \n" 
"    BL      sub_FF81E88C \n" 
"    B       loc_FF8BA3C8 \n" 
"loc_FF8BA42C:\n"
"    CMP     R1, #0x28 \n" 
"    BNE     loc_FF8BA444 \n" 
"loc_FF8BA434:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    ADD     R1, SP, #0xC \n" 
"    BL      sub_FF8BA284 \n" 
"    B       loc_FF8BA3C8 \n" 
"loc_FF8BA444:\n"
"    CMP     R1, #0x2B \n" 
"    BNE     loc_FF8BA45C \n" 
"    BL      sub_FF8AA480 \n" 
"    BL      sub_FF8AB0A4 \n" 
"    BL      sub_FF8AABF8 \n" 
"    B       loc_FF8BA3C8 \n" 
"loc_FF8BA45C:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    MOV     R4, #1 \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x11 \n" 
"    CMPNE   R1, #0x12 \n" 
"    BNE     loc_FF8BA4CC \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    ADD     R1, R1, R1, LSL #1 \n" 
"    ADD     R1, R0, R1, LSL #2 \n" 
"    SUB     R1, R1, #8 \n" 
"    LDMIA   R1, {R2-R4} \n" 
"    STMIA   R6, {R2-R4} \n" 
"    BL      sub_FF8B8BA0 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R3, [R0, #0x8C] \n" 
"    LDR     R2, [R0, #0x90] \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    BL      sub_FF8BB900 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R3, [R0, #0x94] \n" 
"    LDR     R2, [R0, #0x98] \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"    B       loc_FF8BA7C4 \n" 
"loc_FF8BA4CC:\n"
"    CMP     R1, #0x13 \n" 
"    CMPNE   R1, #0x14 \n" 
"    CMPNE   R1, #0x15 \n" 
"    CMPNE   R1, #0x16 \n" 
"    BNE     loc_FF8BA584 \n" 
"    ADD     R3, SP, #0xC \n" 
"    MOV     R2, SP \n" 
"    ADD     R1, SP, #0x10 \n" 
"    BL      sub_FF8B8E7C \n" 
"    CMP     R0, #1 \n" 
"    MOV     R4, R0 \n" 
"    CMPNE   R4, #5 \n" 
"    BNE     loc_FF8BA520 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    MOV     R2, R4 \n" 
"    LDR     R1, [R0, #0x7C]! \n" 
"    LDR     R12, [R0, #0x10]! \n" 
"    LDR     R3, [R0, #4] \n" 
"    MOV     R0, SP \n" 
"    BLX     R12 \n" 
"    B       loc_FF8BA558 \n" 
"loc_FF8BA520:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    CMP     R4, #2 \n" 
"    LDR     R3, [R0, #0x90] \n" 
"    CMPNE   R4, #6 \n" 
"    BNE     loc_FF8BA56C \n" 
"    LDR     R12, [R0, #0x8C] \n" 
"    MOV     R0, SP \n" 
"    MOV     R2, R4 \n" 
"    MOV     R1, #1 \n" 
"    BLX     R12 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    MOV     R2, SP \n" 
"    ADD     R1, SP, #0x10 \n" 
"    BL      sub_FF8B9F98 \n" 
"loc_FF8BA558:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R2, [SP, #0xC] \n" 
"    MOV     R1, R4 \n" 
"    BL      sub_FF8BA224 \n" 
"    B       loc_FF8BA7C4 \n" 
"loc_FF8BA56C:\n"
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R12, [R0, #0x8C] \n" 
"    ADD     R0, R0, #4 \n" 
"    MOV     R2, R4 \n" 
"    BLX     R12 \n" 
"    B       loc_FF8BA7C4 \n" 
"loc_FF8BA584:\n"
"    CMP     R1, #0x22 \n" 
"    CMPNE   R1, #0x23 \n" 
"    BNE     loc_FF8BA5D0 \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    ADD     R1, R1, R1, LSL #1 \n" 
"    ADD     R1, R0, R1, LSL #2 \n" 
"    SUB     R1, R1, #8 \n" 
"    LDMIA   R1, {R2-R4} \n" 
"    STMIA   R6, {R2-R4} \n" 
"    BL      sub_FF8B80E4 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R3, [R0, #0x8C] \n" 
"    LDR     R2, [R0, #0x90] \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"    LDR     R0, [SP, #0x1C] \n" 
"    BL      sub_FF8B83E4 \n" 
"    B       loc_FF8BA7C4 \n" 
"loc_FF8BA5D0:\n"
"    ADD     R1, R0, #4 \n" 
"    LDMIA   R1, {R2,R3,R12} \n" 
"    STMIA   R6, {R2,R3,R12} \n" 
"    LDR     R1, [R0] \n" 
"    CMP     R1, #0x25 \n" 
"    ADDLS   PC, PC, R1, LSL #2 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA684 \n" 
"    B       loc_FF8BA684 \n" 
"    B       loc_FF8BA68C \n" 
"    B       loc_FF8BA694 \n" 
"    B       loc_FF8BA694 \n" 
"    B       loc_FF8BA694 \n" 
"    B       loc_FF8BA684 \n" 
"    B       loc_FF8BA68C \n" 
"    B       loc_FF8BA694 \n" 
"    B       loc_FF8BA694 \n" 
"    B       loc_FF8BA6AC \n" 
"    B       loc_FF8BA6AC \n" 
"    B       loc_FF8BA798 \n" 
"    B       loc_FF8BA7A0 \n" 
"    B       loc_FF8BA7A0 \n" 
"    B       loc_FF8BA7A0 \n" 
"    B       loc_FF8BA7A0 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA69C \n" 
"    B       loc_FF8BA6A4 \n" 
"    B       loc_FF8BA6A4 \n" 
"    B       loc_FF8BA6B8 \n" 
"    B       loc_FF8BA6B8 \n" 
"    B       loc_FF8BA6C0 \n" 
"    B       loc_FF8BA6F0 \n" 
"    B       loc_FF8BA720 \n" 
"    B       loc_FF8BA750 \n" 
"    B       loc_FF8BA780 \n" 
"    B       loc_FF8BA780 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA7A4 \n" 
"    B       loc_FF8BA788 \n" 
"    B       loc_FF8BA790 \n" 
"loc_FF8BA684:\n"
"    BL      sub_FF8B6EDC \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA68C:\n"
"    BL      sub_FF8B7160 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA694:\n"
"    BL      sub_FF8B7368 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA69C:\n"
"    BL      sub_FF8B75E0 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA6A4:\n"
"    BL      sub_FF8B77D8 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA6AC:\n"
"    BL      sub_FF8B7A94_my \n"    //----------------->  
"    MOV     R4, #0 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA6B8:\n"
"    BL      sub_FF8B7BD4 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA6C0:\n"
"    LDRH    R1, [R0, #4] \n" 
"    STRH    R1, [SP, #0x10] \n" 
"    LDRH    R1, [R5, #2] \n" 
"    STRH    R1, [SP, #0x12] \n" 
"    LDRH    R1, [R5, #4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R5, #6] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R0, #0xC] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    BL      sub_FF8BB5B8 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA6F0:\n"
"    LDRH    R1, [R0, #4] \n" 
"    STRH    R1, [SP, #0x10] \n" 
"    LDRH    R1, [R5, #2] \n" 
"    STRH    R1, [SP, #0x12] \n" 
"    LDRH    R1, [R5, #4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R5, #6] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R5, #8] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    BL      sub_FF8BB718 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA720:\n"
"    LDRH    R1, [R5] \n" 
"    STRH    R1, [SP, #0x10] \n" 
"    LDRH    R1, [R0, #6] \n" 
"    STRH    R1, [SP, #0x12] \n" 
"    LDRH    R1, [R5, #4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R5, #6] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R5, #8] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    BL      sub_FF8BB7C4 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA750:\n"
"    LDRH    R1, [R5] \n" 
"    STRH    R1, [SP, #0x10] \n" 
"    LDRH    R1, [R5, #2] \n" 
"    STRH    R1, [SP, #0x12] \n" 
"    LDRH    R1, [R5, #4] \n" 
"    STRH    R1, [SP, #0x14] \n" 
"    LDRH    R1, [R5, #6] \n" 
"    STRH    R1, [SP, #0x16] \n" 
"    LDRH    R1, [R0, #0xC] \n" 
"    STRH    R1, [SP, #0x18] \n" 
"    BL      sub_FF8BB864 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA780:\n"
"    BL      sub_FF8B7F20 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA788:\n"
"    BL      sub_FF8B84E8 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA790:\n"
"    BL      sub_FF8B8724 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA798:\n"
"    BL      sub_FF8B88A0 \n" 
"    B       loc_FF8BA7A4 \n" 
"loc_FF8BA7A0:\n"
"    BL      sub_FF8B8A3C \n" 
"loc_FF8BA7A4:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    LDR     R3, [R0, #0x8C] \n" 
"    LDR     R2, [R0, #0x90] \n" 
"    ADD     R0, R0, #4 \n" 
"    BLX     R3 \n" 
"    CMP     R4, #1 \n" 
"    BNE     loc_FF8BA80C \n" 
"loc_FF8BA7C4:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    MOV     R2, #0xC \n" 
"    LDR     R1, [R0, #0x7C] \n" 
"    ADD     R1, R1, R1, LSL #1 \n" 
"    ADD     R0, R0, R1, LSL #2 \n" 
"    SUB     R4, R0, #8 \n" 
"    LDR     R0, =0x4F45C \n" 
"    ADD     R1, SP, #0x10 \n" 
"    BL      sub_FFB3A37C \n" 
"    LDR     R0, =0x4F468 \n" 
"    MOV     R2, #0xC \n" 
"    ADD     R1, SP, #0x10 \n" 
"    BL      sub_FFB3A37C \n" 
"    LDR     R0, =0x4F474 \n" 
"    MOV     R2, #0xC \n" 
"    MOV     R1, R4 \n" 
"    BL      sub_FFB3A37C \n" 
"    B       loc_FF8BA884 \n" 
"loc_FF8BA80C:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    LDR     R0, [R0] \n" 
"    CMP     R0, #0xB \n" 
"    BNE     loc_FF8BA854 \n" 
"    MOV     R3, #0 \n" 
"    STR     R3, [SP] \n" 
"    MOV     R3, #1 \n" 
"    MOV     R2, #1 \n" 
"    MOV     R1, #1 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF8B6CE4 \n" 
"    MOV     R3, #0 \n" 
"    STR     R3, [SP] \n" 
"    MOV     R3, #1 \n" 
"    MOV     R2, #1 \n" 
"    MOV     R1, #1 \n" 
"    MOV     R0, #0 \n" 
"    B       loc_FF8BA880 \n" 
"loc_FF8BA854:\n"
"    MOV     R3, #1 \n" 
"    MOV     R2, #1 \n" 
"    MOV     R1, #1 \n" 
"    MOV     R0, #1 \n" 
"    STR     R3, [SP] \n" 
"    BL      sub_FF8B6CE4 \n" 
"    MOV     R3, #1 \n" 
"    MOV     R2, #1 \n" 
"    MOV     R1, #1 \n" 
"    MOV     R0, #1 \n" 
"    STR     R3, [SP] \n" 
"loc_FF8BA880:\n"
"    BL      sub_FF8B6E24 \n" 
"loc_FF8BA884:\n"
"    LDR     R0, [SP, #0x1C] \n" 
"    BL      sub_FF8BB544 \n" 
"    B       loc_FF8BA2F4 \n" 

 );
}

void __attribute__((naked,noinline)) sub_FF8B7A94_my(){
 asm volatile(
"    STMFD   SP!, {R4-R8,LR} \n" 
"    LDR     R7, =0x4130 \n" 
"    MOV     R4, R0 \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R1, #0x3E \n" 
"    BL      sub_FF8809F8 \n" 
"    LDRSH   R0, [R4, #4] \n" 
"    MOV     R2, #0 \n" 
"    MOV     R1, #0 \n" 
"    BL      sub_FF8B6A48 \n" 
"    MOV     R6, R0 \n" 
"    LDRSH   R0, [R4, #6] \n" 
"    BL      sub_FF8B6B58 \n" 
"    LDRSH   R0, [R4, #8] \n" 
"    BL      sub_FF8B6BB0 \n" 
"    LDRSH   R0, [R4, #0xA] \n" 
"    BL      sub_FF8B6C08 \n" 
"    LDRSH   R0, [R4, #0xC] \n" 
"    MOV     R1, #0 \n" 
"    BL      sub_FF8B6C60 \n" 
"    MOV     R5, R0 \n" 
"    LDR     R0, [R4] \n" 
"    LDR     R8, =0x4F474 \n" 
"    CMP     R0, #0xB \n" 
"    MOVEQ   R6, #0 \n" 
"    MOVEQ   R5, #0 \n" 
"    BEQ     loc_FF8B7B28 \n" 
"    CMP     R6, #1 \n" 
"    BNE     loc_FF8B7B28 \n" 
"    LDRSH   R0, [R4, #4] \n" 
"    LDR     R1, =0xFF8B69B4 \n" 
"    MOV     R2, #2 \n" 
"    BL      sub_FF943BE8 \n" 
"    STRH    R0, [R4, #4] \n" 
"    MOV     R0, #0 \n" 
"    STR     R0, [R7, #0x28] \n" 
"    B       loc_FF8B7B30 \n" 
"loc_FF8B7B28:\n"
"    LDRH    R0, [R8] \n" 
"    STRH    R0, [R4, #4] \n" 
"loc_FF8B7B30:\n"
"    CMP     R5, #1 \n" 
"    LDRNEH  R0, [R8, #8] \n" 
"    BNE     loc_FF8B7B4C \n" 
"    LDRSH   R0, [R4, #0xC] \n" 
"    LDR     R1, =0xFF8B6A38 \n" 
"    MOV     R2, #0x20 \n" 
"    BL      sub_FF8BB574 \n" 
"loc_FF8B7B4C:\n"
"    STRH    R0, [R4, #0xC] \n" 
"    LDRSH   R0, [R4, #6] \n" 
"    BL      sub_FF8AA1F0_my \n"    //----------------->  
"    LDRSH   R0, [R4, #8] \n" 
"    MOV     R1, #1 \n" 
"    BL      sub_FF8AA940 \n" 
"    MOV     R1, #0 \n" 
"    ADD     R0, R4, #8 \n" 
"    BL      sub_FF8AA9C8 \n" 
"    LDRSH   R0, [R4, #0xE] \n" 
"    BL      sub_FF8B24B0 \n" 
"    LDR     R4, =0xBB8 \n" 
"    CMP     R6, #1 \n" 
"    BNE     loc_FF8B7BA4 \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R2, R4 \n" 
"    MOV     R1, #2 \n" 
"    BL      sub_FF880904 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R1, =0x59B \n" 
"    LDRNE   R0, =0xFF8B7034 \n" 
"    BLNE    sub_FF81E88C \n" 
"loc_FF8B7BA4:\n"
"    CMP     R5, #1 \n" 
"    LDMNEFD SP!, {R4-R8,PC} \n" 
"    LDR     R0, [R7, #0x1C] \n" 
"    MOV     R2, R4 \n" 
"    MOV     R1, #0x20 \n" 
"    BL      sub_FF880904 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R0, =0xFF8B7034 \n" 
"    LDMNEFD SP!, {R4-R8,LR} \n" 
"    MOVNE   R1, #0x5A0 \n" 
"    BNE     sub_FF81E88C \n" 
"    LDMFD   SP!, {R4-R8,PC} \n" 
 );
}

void __attribute__((naked,noinline)) sub_FF8AA1F0_my(){
 asm volatile(
"    STMFD   SP!, {R4-R6,LR} \n" 
"    LDR     R5, =0x3E48 \n" 
"    MOV     R4, R0 \n" 
"    LDR     R0, [R5, #4] \n" 
"    CMP     R0, #1 \n" 
"    LDRNE   R1, =0x146 \n" 
"    LDRNE   R0, =0xFF8A9FF4 \n" 
"    BLNE    sub_FF81E88C \n" 
"    CMN     R4, #0xC00 \n" 
"    LDREQSH R4, [R5, #2] \n" 
"    CMN     R4, #0xC00 \n" 
"    MOVEQ   R1, #0x14C \n" 
"    LDREQ   R0, =0xFF8A9FF4 \n" 
"    STRH    R4, [R5, #2] \n" 
"    BLEQ    sub_FF81E88C \n" 
"    MOV     R0, R4 \n" 
//"    BL      sub_FF9FD42C \n" 
"	BL      apex2us\n"
"    MOV     R4, R0 \n" 
//"    BL      sub_FF8DF5C8 \n" 
"    MOV     R0, R4 \n" 
"    BL      sub_FF8E32C0 \n" 
"    TST     R0, #1 \n" 
"    LDRNE   R1, =0x151 \n" 
"    LDMNEFD SP!, {R4-R6,LR} \n" 
"    LDRNE   R0, =0xFF8A9FF4 \n" 
"    BNE     sub_FF81E88C \n" 
"    LDMFD   SP!, {R4-R6,PC} \n" 
 );
}
