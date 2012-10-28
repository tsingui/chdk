#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)(0x8744+0x00);  // Found @ ff9df57c & ff9df5dc
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

#define PAUSE_FOR_FILE_COUNTER 250           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF86ECA8 

void __attribute__((naked,noinline)) capt_seq_task(  ) { 
asm volatile (
      "STMFD   SP!, {R3-R7,LR} \n"
      "LDR     R5, =0x36C34 \n"
      "LDR     R6, =0x2ACC \n"
"loc_FF86ECB4:\n"
      "MOV     R2, #0 \n"
      "LDR     R0, [R6, #4] \n"
      "MOV     R1, SP \n"
      "BL      sub_003F7218 \n" // RAM
      "TST     R0, #1 \n"
      "BEQ     loc_FF86ECE0 \n"
      "LDR     R1, =0x493 \n"
      "LDR     R0, =0xFF86E814 \n" // **"SsShootTask.c"
      "BL      _DebugAssert \n"
      "BL      _ExitTask \n"
      "LDMFD   SP!, {R3-R7,PC} \n"
"loc_FF86ECE0:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x20 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF86EF20 \n"
      "B       loc_FF86ED74 \n"
      "B       loc_FF86ED7C \n"
      "B       loc_FF86EDE0 \n"
      "B       loc_FF86EDF4 \n"
      "B       loc_FF86EDEC \n"
      "B       loc_FF86EDFC \n"
      "B       loc_FF86EE04 \n"
      "B       loc_FF86EE10 \n"
      "B       loc_FF86EE2C \n"
      "B       loc_FF86EDF4 \n"
      "B       loc_FF86EE34 \n"
      "B       loc_FF86EE40 \n"
      "B       loc_FF86EE48 \n"
      "B       loc_FF86EE54 \n"
      "B       loc_FF86EE5C \n"
      "B       loc_FF86EE64 \n"
      "B       loc_FF86EE6C \n"
      "B       loc_FF86EE74 \n"
      "B       loc_FF86EE80 \n"
      "B       loc_FF86EE88 \n"
      "B       loc_FF86EE90 \n"
      "B       loc_FF86EE98 \n"
      "B       loc_FF86EEA0 \n"
      "B       loc_FF86EEAC \n"
      "B       loc_FF86EEB4 \n"
      "B       loc_FF86EEBC \n"
      "B       loc_FF86EEC4 \n"
      "B       loc_FF86EECC \n"
      "B       loc_FF86EED8 \n"
      "B       loc_FF86EEE0 \n"
      "B       loc_FF86EEEC \n"
      "B       loc_FF86EF2C \n"
"loc_FF86ED74:\n"  // jump table entry 0
      "BL		shooting_expo_iso_override\n"  	// added
      "BL      sub_FF86F50C \n"
      "BL      shooting_expo_param_override\n"      // added
      "B       loc_FF86EE08 \n"
"loc_FF86ED7C:\n" // jump table entry 1
      "LDR     R4, [R0, #0x10] \n"
      "LDR     R0, [R5, #0x84] \n"
      "TST     R0, #0x30 \n"
      "BLNE    sub_FF87066C \n"
      "BL      sub_FF87034C \n"
      "MOV     R1, R4 \n"
      "BL      sub_FF8703A4 \n"
      "LDR     R0, =0x10F \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R4, #0x24 \n"
      "BL      sub_FF87E744 \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R4, #0x28 \n"
      "MOV     R0, #0x2C \n"
      "BL      sub_FF87E744 \n"
      "MOV     R0, R4 \n"
//      "BL      sub_FF960D4C \n" //original
      "BL      sub_FF960D4C_my \n" //patched
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R7, R0 \n"
      "MOV     R2, R4 \n"
      "MOV     R1, #1 \n"
      "BL      sub_FF86D0F8 \n"
      "TST     R7, #1 \n"
      "MOVEQ   R0, R4 \n"
      "BLEQ    sub_FF960754 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDE0:\n" // jump table entry 2
      "MOV     R0, #1 \n"
      "BL      sub_FF86F7D0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDEC:\n"
      "BL      sub_FF86F154 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDF4:\n"
      "BL      sub_FF86F4EC \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDFC:\n"
      "BL      sub_FF86F4F4 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE04:\n"
      "BL      sub_FF86F6B8 \n"
"loc_FF86EE08:\n"
      "BL      sub_FF86CC78 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE10:\n"
      "LDR     R4, [R0, #0x10] \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF960E50 \n"
      "MOV     R2, R4 \n"
      "MOV     R1, #9 \n"
      "BL      sub_FF86D0F8 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE2C:\n"
      "BL      sub_FF86F738 \n"
      "B       loc_FF86EE08 \n"
"loc_FF86EE34:\n"
      "LDR     R0, [R5, #0x50] \n"
      "BL      sub_FF86FB70 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE40:\n"
      "BL      sub_FF86FF08 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE48:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF86FF6C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE54:\n"
      "BL      sub_FF95FB24 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE5C:\n"
      "BL      sub_FF95FD84 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE64:\n"
      "BL      sub_FF95FE3C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE6C:\n"
      "BL      sub_FF95FF10 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE74:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF960170 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE80:\n"
      "BL      sub_FF9602E0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE88:\n"
      "BL      sub_FF960374 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE90:\n"
      "BL      sub_FF96042C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE98:\n"
      "BL      sub_FF86F94C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEA0:\n"
      "BL      sub_FF86F978 \n"
      "BL      sub_FF830FB0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEAC:\n"
      "BL      sub_FF95FFE0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEB4:\n"
      "BL      sub_FF960020 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEBC:\n"
      "BL      sub_FF871844 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEC4:\n"
      "BL      sub_FF8718B8 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EECC:\n"
      "LDR     R0, [R0, #0xC] \n"
      "BL      sub_FF960544 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EED8:\n"
      "BL      sub_FF9605B4 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEE0:\n"
      "BL      sub_FF871920 \n"
      "BL      sub_FF8718D8 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEEC:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF961568 \n"
      "MOV     R0, #1 \n"
      "BL      sub_FF961690 \n"
      "LDRH    R0, [R5, #0x94] \n"
      "CMP     R0, #4 \n"
      "LDRNEH  R0, [R5] \n"
      "SUBNE   R1, R0, #0x8200 \n"
      "SUBNES  R1, R1, #0x2E \n"
      "BNE     loc_FF86EF2C \n"
      "BL      sub_FF8718B8 \n"
      "BL      sub_FF871D7C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EF20:\n"
      "LDR     R1, =0x5F4 \n"
      "LDR     R0, =0xFF86E814 \n" // *"SsShootTask.c"
      "BL      _DebugAssert \n"
"loc_FF86EF2C:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0, #4] \n"
      "LDR     R0, [R6] \n"
      "BL      sub_003FAC6C \n" // RAM
      "LDR     R4, [SP] \n"
      "LDR     R0, [R4, #8] \n"
      "CMP     R0, #0 \n"
      "LDREQ   R1, =0x117 \n"
      "LDREQ   R0, =0xFF86E814 \n" // *"SsShootTask.c"
      "BLEQ    _DebugAssert \n"
      "MOV     R0, #0 \n"
      "STR     R0, [R4, #8] \n"
      "B       loc_FF86ECB4 \n"
	);
}

//** sub_FF960D4C_my  @ 0xFF960D4C 

void __attribute__((naked,noinline)) sub_FF960D4C_my() {
asm volatile (
      "STMFD   SP!, {R3-R5,LR} \n"
      "MOV     R5, R0 \n"
      "MOV     R0, #0xC \n"
      "BL      sub_FF873300 \n"
      "TST     R0, #1 \n"
      "MOVNE   R0, #1 \n"
      "BNE     sub_FF960E4C \n"   //loc_ to sub_
      "BL      sub_FF86F4FC \n"
      "MOV     R0, R5 \n"
      "BL      sub_FF9606A4 \n"
      "TST     R0, #1 \n"
      "BNE     sub_FF960E4C \n"   //loc_ to sub_
      "LDR     R4, =0x36C34 \n"
      "LDR     R0, [R4, #0x84] \n"
      "AND     R0, R0, #0x40 \n"
      "CMP     R0, #0 \n"
      "LDRNEH  R0, [R4, #0x92] \n"
      "CMPNE   R0, #3 \n"
      "LDRNE   R0, [R5, #8] \n"
      "CMPNE   R0, #1 \n"
      "BLS     loc_FF960DBC \n"
      "BL      sub_FF961850 \n"
      "MOV     R3, #0xC0 \n"
      "STR     R3, [SP] \n"
      "LDR     R2, =0x3A98 \n"
      "LDR     R3, =0xFF960EDC \n" //SsCaptureSeq.c
      "MOV     R1, #0x8000 \n"
      "BL      sub_FF873568 \n"
"loc_FF960DBC:\n"
      "MOV     R0, R5 \n"
      "BL      sub_FF96098C \n"
      "BL      sub_FF961348 \n"
      
      "BL      wait_until_remote_button_is_released \n"  //before shoot XXX
      "BL      capt_seq_hook_set_nr \n"

      "LDR     R0, [R4, #0x84] \n"
      "TST     R0, #0x40 \n"
      "BEQ     sub_FF960E30 \n" //from loc_ to sub_ 
      "LDR     R0, =0x181 \n"
      "MOV     R2, #4 \n"
      "MOV     R1, SP \n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1 \n"
      "MOVNE   R1, #0xD4 \n"
      "LDRNE   R0, =0xFF960EDC \n" //SsCaptureSeq.c
      "BLNE    _DebugAssert \n" //RAM
      "LDR     R0, [SP] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF960E10 \n"
      "BL      sub_FF961850 \n"
      "MOV     R1, #0x8000 \n"
      "BL      sub_003FAC6C \n" //RAM
      "B       sub_FF960E30 \n" // from loc_ to sub_
"loc_FF960E10:\n"
      "BL      sub_FF961850 \n"
      "MOV     R1, #0x8000 \n"
      "BL      sub_003FACA0 \n" //RAM
      "LDR     R2, =0xFF960D38 \n"
      "LDR     R0, [SP] \n"
      "MOV     R3, #0x8000 \n"
      "ADD     R1, R2, #0 \n"
      "BL      sub_FF833200 \n"
"loc_FF960E30:\n"
      "LDR     R0, [R4, #0x84] \n"
      "TST     R0, #0x10 \n"
      "MOV     R0, R5 \n"
      "LDMEQFD SP!, {R3-R5,LR} \n"
	);
}

//** exp_drv_task  @ 0xFF8AE8D4 

void __attribute__((naked,noinline)) exp_drv_task(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R9,LR} \n"
      "SUB     SP, SP, #0x2C \n"
      "LDR     R6, =0x3D78 \n"
      "LDR     R7, =0xBB8 \n"
      "LDR     R4, =0x55E1C \n"
      "MOV     R0, #0 \n"
      "ADD     R5, SP, #0x1C \n"
      "STR     R0, [SP, #0xC] \n"
"loc_FF8AE8F4:\n"
      "LDR     R0, [R6, #0x20] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #0x28 \n"
      "BL      sub_003F7218 \n" //RAM
      "LDR     R0, [SP, #0xC] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF8AE940 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0x14 \n"
      "CMPNE   R0, #0x15 \n"
      "CMPNE   R0, #0x16 \n"
      "CMPNE   R0, #0x17 \n"
      "BEQ     loc_FF8AEAA0 \n"
      "CMP     R0, #0x2A \n"
      "BEQ     loc_FF8AEA28 \n"
      "ADD     R1, SP, #0xC \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF8AE884 \n"
"loc_FF8AE940:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x30 \n"
      "BNE     loc_FF8AE96C \n"
      "BL      sub_FF8AFCB0 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #1 \n"
      "BL      sub_003FAC6C \n" //RAM
      "BL      _ExitTask \n"
      "ADD     SP, SP, #0x2C \n"
      "LDMFD   SP!, {R4-R9,PC} \n"
"loc_FF8AE96C:\n"
      "CMP     R1, #0x2F \n"
      "BNE     loc_FF8AE988 \n"
      "LDR     R2, [R0, #0x8C]! \n"
      "LDR     R1, [R0, #4] \n"
      "MOV     R0, R1 \n"
      "BLX     R2 \n"
      "B       loc_FF8AEF5C \n"
"loc_FF8AE988:\n"
      "CMP     R1, #0x28 \n"
      "BNE     loc_FF8AE9D8 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_003FACA0 \n" //RAM
      "LDR     R0, =0xFF8AA1F0 \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_FF954E04 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_003FABAC \n"
      "TST     R0, #1 \n"
      "LDRNE   R1, =0x1599 \n"
      "BNE     loc_FF8AEA94 \n"
"loc_FF8AE9C4:\n"
      "LDR     R1, [SP, #0x28] \n"
      "LDR     R0, [R1, #0x90] \n"
      "LDR     R1, [R1, #0x8C] \n"
      "BLX     R1 \n"
      "B       loc_FF8AEF5C \n"
"loc_FF8AE9D8:\n"
      "CMP     R1, #0x29 \n"
      "BNE     loc_FF8AEA20 \n"
      "ADD     R1, SP, #0xC \n"
      "BL      sub_FF8AE884 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_003FACA0 \n"
      "LDR     R0, =0xFF8AA200 \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_FF954FA4 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_003FABAC \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF8AE9C4 \n"
      "LDR     R1, =0x15A3 \n"
      "B       loc_FF8AEA94 \n"
"loc_FF8AEA20:\n"
      "CMP     R1, #0x2A \n"
      "BNE     loc_FF8AEA38 \n"
"loc_FF8AEA28:\n"
      "LDR     R0, [SP, #0x28] \n"
      "ADD     R1, SP, #0xC \n"
      "BL      sub_FF8AE884 \n"
      "B       loc_FF8AE9C4 \n"
"loc_FF8AEA38:\n"
      "CMP     R1, #0x2D \n"
      "BNE     loc_FF8AEA50 \n"
      "BL      sub_FF89A404 \n"
      "BL      sub_FF89B0EC \n"
      "BL      sub_FF89AC54 \n"
      "B       loc_FF8AE9C4 \n"
"loc_FF8AEA50:\n"
      "CMP     R1, #0x2E \n"
      "BNE     loc_FF8AEAA0 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #4 \n"
      "BL      sub_003FACA0 \n" //RAM
      "LDR     R1, =0xFF8AA220 \n"
      "LDR     R0, =0xFFFFF400 \n"
      "MOV     R2, #4 \n"
      "BL      sub_FF899E54 \n"
      "BL      sub_FF89A0E4 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #4 \n"
      "BL      sub_003FAAC8 \n" //RAM
      "TST     R0, #1 \n"
      "BEQ     loc_FF8AE9C4 \n"
      "LDR     R1, =0x15CB \n"
"loc_FF8AEA94:\n"
      "LDR     R0, =0xFF8AA914 \n" // **"ExpDrv.c"
      "BL      _DebugAssert \n"
      "B       loc_FF8AE9C4 \n"
"loc_FF8AEAA0:\n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R8, #1 \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x12 \n"
      "CMPNE   R1, #0x13 \n"
      "BNE     loc_FF8AEB08 \n"
      "LDR     R1, [R0, #0x7C] \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R1, R0, R1, LSL #2 \n"
      "SUB     R1, R1, #8 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "BL      sub_FF8ACE28 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R3, [R0, #0x8C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF8B00B4 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R2, [R0, #0x98] \n"
      "LDR     R3, [R0, #0x94] \n"
      "B       loc_FF8AEE20 \n"
"loc_FF8AEB08:\n"
      "CMP     R1, #0x14 \n"
      "CMPNE   R1, #0x15 \n"
      "CMPNE   R1, #0x16 \n"
      "CMPNE   R1, #0x17 \n"
      "BNE     loc_FF8AEBC0 \n"
      "ADD     R3, SP, #0xC \n"
      "MOV     R2, SP \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_FF8AD088 \n"
      "CMP     R0, #1 \n"
      "MOV     R9, R0 \n"
      "CMPNE   R9, #5 \n"
      "BNE     loc_FF8AEB5C \n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R2, R9 \n"
      "LDR     R1, [R0, #0x7C]! \n"
      "LDR     R12, [R0, #0x10]! \n"
      "LDR     R3, [R0, #4] \n"
      "MOV     R0, SP \n"
      "BLX     R12 \n"
      "B       loc_FF8AEB94 \n"
"loc_FF8AEB5C:\n"
      "LDR     R0, [SP, #0x28] \n"
      "CMP     R9, #2 \n"
      "LDR     R3, [R0, #0x90] \n"
      "CMPNE   R9, #6 \n"
      "BNE     loc_FF8AEBA8 \n"
      "LDR     R12, [R0, #0x8C] \n"
      "MOV     R2, R9 \n"
      "MOV     R1, #1 \n"
      "MOV     R0, SP \n"
      "BLX     R12 \n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R2, SP \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_FF8AE570 \n"
"loc_FF8AEB94:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R2, [SP, #0xC] \n"
      "MOV     R1, R9 \n"
      "BL      sub_FF8AE7C0 \n"
      "B       loc_FF8AEE28 \n"
"loc_FF8AEBA8:\n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R12, [R0, #0x8C] \n"
      "MOV     R2, R9 \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R12 \n"
      "B       loc_FF8AEE28 \n"
"loc_FF8AEBC0:\n"
      "CMP     R1, #0x24 \n"
      "CMPNE   R1, #0x25 \n"
      "BNE     loc_FF8AEC0C \n"
      "LDR     R1, [R0, #0x7C] \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R1, R0, R1, LSL #2 \n"
      "SUB     R1, R1, #8 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "BL      sub_FF8ABE14 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R3, [R0, #0x8C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF8AC254 \n"
      "B       loc_FF8AEE28 \n"
"loc_FF8AEC0C:\n"
      "ADD     R1, R0, #4 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x28 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AECC8 \n"
      "B       loc_FF8AECC8 \n"
      "B       loc_FF8AECD0 \n"
      "B       loc_FF8AECD8 \n"
      "B       loc_FF8AECD8 \n"
      "B       loc_FF8AECD8 \n"
      "B       loc_FF8AECC8 \n"
      "B       loc_FF8AECD0 \n"
      "B       loc_FF8AECD8 \n"
      "B       loc_FF8AECD8 \n"
      "B       loc_FF8AECF0 \n"
      "B       loc_FF8AECF0 \n"
      "B       loc_FF8AEDFC \n"
      "B       loc_FF8AEE04 \n"
      "B       loc_FF8AEE04 \n"
      "B       loc_FF8AEE04 \n"
      "B       loc_FF8AEE04 \n"
      "B       loc_FF8AEE0C \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AECE0 \n"
      "B       loc_FF8AECE8 \n"
      "B       loc_FF8AECE8 \n"
      "B       loc_FF8AECE8 \n"
      "B       loc_FF8AECFC \n"
      "B       loc_FF8AECFC \n"
      "B       loc_FF8AED04 \n"
      "B       loc_FF8AED3C \n"
      "B       loc_FF8AED74 \n"
      "B       loc_FF8AEDAC \n"
      "B       loc_FF8AEDE4 \n"
      "B       loc_FF8AEDE4 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEE10 \n"
      "B       loc_FF8AEDEC \n"
      "B       loc_FF8AEDF4 \n"
"loc_FF8AECC8:\n"
      "BL      sub_FF8AA798 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AECD0:\n"
      "BL      sub_FF8AAA3C \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AECD8:\n"
      "BL      sub_FF8AAC64 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AECE0:\n"
      "BL      sub_FF8AAF88 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AECE8:\n"
      "BL      sub_FF8AB1A0 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AECF0:\n"
//      "BL      sub_FF8AB54C \n" //original
      "BL      sub_FF8AB54C_my \n" //patched
      "MOV     R8, #0 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AECFC:\n"
      "BL      sub_FF8AB68C \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AED04:\n"
      "LDRH    R1, [R0, #4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R4, #2] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R0, #0xC] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8AFD44 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AED3C:\n"
      "LDRH    R1, [R0, #4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R4, #2] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R4, #8] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8AFEB4 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AED74:\n"
      "LDRH    R1, [R4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R0, #6] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R4, #8] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8AFF68 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEDAC:\n"
      "LDRH    R1, [R4] \n"
      "STRH    R1, [SP, #0x1C] \n"
      "LDRH    R1, [R4, #2] \n"
      "STRH    R1, [SP, #0x1E] \n"
      "LDRH    R1, [R4, #4] \n"
      "STRH    R1, [SP, #0x20] \n"
      "LDRH    R1, [R4, #6] \n"
      "STRH    R1, [SP, #0x22] \n"
      "LDRH    R1, [R0, #0xC] \n"
      "STRH    R1, [SP, #0x24] \n"
      "LDRH    R1, [R4, #0xA] \n"
      "STRH    R1, [SP, #0x26] \n"
      "BL      sub_FF8B0010 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEDE4:\n"
      "BL      sub_FF8ABBC8 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEDEC:\n"
      "BL      sub_FF8AC358 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEDF4:\n"
      "BL      sub_FF8AC63C \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEDFC:\n"
      "BL      sub_FF8AC8FC \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEE04:\n"
      "BL      sub_FF8ACAB8 \n"
      "B       loc_FF8AEE10 \n"
"loc_FF8AEE0C:\n"
      "BL      sub_FF8ACC20 \n"
"loc_FF8AEE10:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "LDR     R3, [R0, #0x8C] \n"
"loc_FF8AEE20:\n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
"loc_FF8AEE28:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0x10 \n"
      "BEQ     loc_FF8AEE60 \n"
      "BGT     loc_FF8AEE50 \n"
      "CMP     R0, #1 \n"
      "CMPNE   R0, #4 \n"
      "CMPNE   R0, #0xE \n"
      "BNE     loc_FF8AEE94 \n"
      "B       loc_FF8AEE60 \n"
"loc_FF8AEE50:\n"
      "CMP     R0, #0x13 \n"
      "CMPNE   R0, #0x17 \n"
      "CMPNE   R0, #0x1A \n"
      "BNE     loc_FF8AEE94 \n"
"loc_FF8AEE60:\n"
      "LDRSH   R0, [R4] \n"
      "CMN     R0, #0xC00 \n"
      "LDRNESH R1, [R4, #8] \n"
      "CMNNE   R1, #0xC00 \n"
      "STRNEH  R0, [SP, #0x1C] \n"
      "STRNEH  R1, [SP, #0x24] \n"
      "BNE     loc_FF8AEE94 \n"
      "ADD     R0, SP, #0x10 \n"
      "BL      sub_FF8B02C4 \n"
      "LDRH    R0, [SP, #0x10] \n"
      "STRH    R0, [SP, #0x1C] \n"
      "LDRH    R0, [SP, #0x18] \n"
      "STRH    R0, [SP, #0x24] \n"
"loc_FF8AEE94:\n"
      "LDR     R0, [SP, #0x28] \n"
      "CMP     R8, #1 \n"
      "BNE     loc_FF8AEEE4 \n"
      "LDR     R1, [R0, #0x7C] \n"
      "MOV     R2, #0xC \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R0, R0, R1, LSL #2 \n"
      "SUB     R8, R0, #8 \n"
      "LDR     R0, =0x55E1C \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_003FC17C \n"
      "LDR     R0, =0x55E28 \n"
      "MOV     R2, #0xC \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_003FC17C \n"
      "LDR     R0, =0x55E34 \n"
      "MOV     R2, #0xC \n"
      "MOV     R1, R8 \n"
      "BL      sub_003FC17C \n"
      "B       loc_FF8AEF5C \n"
"loc_FF8AEEE4:\n"
      "LDR     R0, [R0] \n"
      "MOV     R3, #1 \n"
      "CMP     R0, #0xB \n"
      "BNE     loc_FF8AEF28 \n"
      "MOV     R2, #0 \n"
      "STRD    R2, [SP] \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF8AA578 \n"
      "MOV     R3, #1 \n"
      "MOV     R2, #0 \n"
      "STRD    R2, [SP] \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, #0 \n"
      "B       loc_FF8AEF58 \n"
"loc_FF8AEF28:\n"
      "MOV     R2, #1 \n"
      "STRD    R2, [SP] \n"
      "MOV     R3, R2 \n"
      "MOV     R1, R2 \n"
      "MOV     R0, R2 \n"
      "BL      sub_FF8AA578 \n"
      "MOV     R3, #1 \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, R3 \n"
      "STR     R3, [SP] \n"
      "STR     R3, [SP, #4] \n"
"loc_FF8AEF58:\n"
      "BL      sub_FF8AA6E4 \n"
"loc_FF8AEF5C:\n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF8AFCB0 \n"
      "B       loc_FF8AE8F4 \n"
	);
}

//** sub_FF8AB54C_my  @ 0xFF8AB54C

void __attribute__((naked,noinline)) sub_FF8AB54C_my(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R8,LR} \n"
      "LDR     R7, =0x3D78 \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R7, #0x1C] \n"
      "MOV     R1, #0x3E \n"
      "BL      sub_003FACA0 \n" // RAM
      "MOV     R2, #0 \n"
      "LDRSH   R0, [R4, #4] \n"
      "MOV     R1, R2 \n"
      "BL      sub_FF8AA280 \n"
      "MOV     R6, R0 \n"
      "LDRSH   R0, [R4, #6] \n"
      "BL      sub_FF8AA3D0 \n"
      "LDRSH   R0, [R4, #8] \n"
      "BL      sub_FF8AA428 \n"
      "LDRSH   R0, [R4, #0xA] \n"
      "BL      sub_FF8AA480 \n"
      "LDRSH   R0, [R4, #0xC] \n"
      "MOV     R1, #0 \n"
      "BL      sub_FF8AA4D8 \n"
      "MOV     R5, R0 \n"
      "LDR     R0, [R4] \n"
      "LDR     R8, =0x55E34 \n"
      "CMP     R0, #0xB \n"
      "MOVEQ   R6, #0 \n"
      "MOVEQ   R5, R6 \n"
      "BEQ     loc_FF8AB5E0 \n"
      "CMP     R6, #1 \n"
      "BNE     loc_FF8AB5E0 \n"
      "LDRSH   R0, [R4, #4] \n"
      "LDR     R1, =0xFF8AA1E0 \n"
      "MOV     R2, #2 \n"
      "BL      sub_FF954E88 \n"
      "STRH    R0, [R4, #4] \n"
      "MOV     R0, #0 \n"
      "STR     R0, [R7, #0x28] \n"
      "B       loc_FF8AB5E8 \n"
"loc_FF8AB5E0:\n"
      "LDRH    R0, [R8] \n"
      "STRH    R0, [R4, #4] \n"
"loc_FF8AB5E8:\n"
      "CMP     R5, #1 \n"
      "LDRNEH  R0, [R8, #8] \n"
      "BNE     loc_FF8AB604 \n"
      "LDRSH   R0, [R4, #0xC] \n"
      "LDR     R1, =0xFF8AA264 \n"
      "MOV     R2, #0x20 \n"
      "BL      sub_FF8AFD00 \n"
"loc_FF8AB604:\n"
      "STRH    R0, [R4, #0xC] \n"
      "LDRSH   R0, [R4, #6] \n"
//      "BL      sub_FF89A150 \n" //original
      "BL      sub_FF89A150_my \n" //patched
      "B       sub_FF8AB610 \n" // continue in firmware
	);
}

//** sub_FF89A150_my  @ 0xFF89A150 

void __attribute__((naked,noinline)) sub_FF89A150_my() { 
asm volatile (
      "STMFD   SP!, {R4-R6,LR} \n"
      "LDR     R5, =0x39C8 \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R5, #4] \n"
      "CMP     R0, #1 \n"
      "LDRNE   R1, =0x14D \n"
      "LDRNE   R0, =0xFF899F88 \n" //  ; "Shutter.c"
      "BLNE    _DebugAssert \n"
      "CMN     R4, #0xC00 \n"
      "LDREQSH R4, [R5, #2] \n"
      "CMN     R4, #0xC00 \n"
      "LDREQ   R1, =0x153 \n"
      "LDREQ   R0, =0xFF899F88 \n" //  ; "Shutter.c"
      "STRH    R4, [R5, #2] \n"
      "BLEQ    _DebugAssert \n" //RAM
      "MOV     R0, R4 \n"
//      "BL      sub_FF9D8E90 \n"
      "BL      apex2us \n"   //patch
      "MOV     R4, R0 \n"
      "BL      sub_FF8E9590 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF8F1D98 \n"
      "TST     R0, #1 \n"
      "LDMEQFD SP!, {R4-R6,PC} \n"
      "LDMFD   SP!, {R4-R6,LR} \n"
      "MOV     R1, #0x158 \n"
      "LDR     R0, =0xFF899F88 \n" // ; "Shutter.c"
      "B       _DebugAssert \n"
	);
}
