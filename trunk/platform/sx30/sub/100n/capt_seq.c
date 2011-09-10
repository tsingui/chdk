#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)(0x8608+0x8); // in _sub_FF99555C__NRTable.c__0
#define NR_AUTO (0)							// have to explictly reset value back to 0 to enable auto

#include "../../../generic/capt_seq.c"

//void __attribute__((naked,noinline)) hangdebug() {
//	debug_led(1);
//	while(1);
//}

// @ FF8868C4
void __attribute__((naked,noinline)) capt_seq_task() {

asm volatile (

	"STMFD SP!, {R3-R7,LR}\n"
	"LDR	R7, =0x3648\n"
	"LDR	R4, =0x3BC24\n"
	"MOV	R6, #0\n"

"loc_FF8868D4:\n"
	"LDR	R0, [R7,#4]\n"
	"MOV	R2, #0\n"
	"MOV	R1, SP\n"
	"BL		sub_FF83A4C8\n"
	"TST	R0, #1\n"
	"BEQ	loc_FF886900\n"
	"LDR	R1, =0x43F\n"
	"LDR	R0, =0xFF8863B4\n"
	"BL		_DebugAssert\n"
	"BL		_ExitTask\n"
	"LDMFD SP!, {R3-R7,PC}\n"

"loc_FF886900:\n"
	"LDR	R0, [SP]\n"
	"LDR	R1, [R0]\n"
	"CMP	R1, #0x22\n"
	"ADDLS	PC, PC, R1,LSL#2\n"

			  "B  loc_FF886B54\n"
"loc_FF886914: B  loc_FF8869A0\n"
"loc_FF886918: B  loc_FF8869B8\n"
"loc_FF88691C: B  loc_FF8869D0\n"
"loc_FF886920: B  loc_FF8869F0\n"
"loc_FF886924: B  loc_FF8869E8\n"
"loc_FF886928: B  loc_FF8869FC\n"
"loc_FF88692C: B  loc_FF886A04\n"
"loc_FF886930: B  loc_FF886A0C\n"
"loc_FF886934: B  loc_FF886A18\n"
"loc_FF886938: B  loc_FF886A40\n"
"loc_FF88693C: B  loc_FF886A24\n"
"loc_FF886940: B  loc_FF886A30\n"
"loc_FF886944: B  loc_FF886A38\n"
"loc_FF886948: B  loc_FF886A48\n"
"loc_FF88694C: B  loc_FF886A50\n"
"loc_FF886950: B  loc_FF886A58\n"
"loc_FF886954: B  loc_FF886A60\n"
"loc_FF886958: B  loc_FF886A68\n"
"loc_FF88695C: B  loc_FF886A70\n"
"loc_FF886960: B  loc_FF886A78\n"
"loc_FF886964: B  loc_FF886A80\n"
"loc_FF886968: B  loc_FF886A88\n"
"loc_FF88696C: B  loc_FF886A90\n"
"loc_FF886970: B  loc_FF886A9C\n"
"loc_FF886974: B  loc_FF886AA4\n"
"loc_FF886978: B  loc_FF886AB0\n"
"loc_FF88697C: B  loc_FF886AB8\n"
"loc_FF886980: B  loc_FF886AE8\n"
"loc_FF886984: B  loc_FF886AF0\n"
"loc_FF886988: B  loc_FF886AF8\n"
"loc_FF88698C: B  loc_FF886B00\n"
"loc_FF886990: B  loc_FF886B08\n"
"loc_FF886994: B  loc_FF886B10\n"
"loc_FF886998: B  loc_FF886B1C\n"
"loc_FF88699C: B  loc_FF886B60\n"

// jump table entry 0
"loc_FF8869A0:\n"

"		BL	shooting_expo_iso_override\n"  		    // added

"		BL	sub_FF887088 \n"

"		BL	shooting_expo_param_override\n"  		// added

"		BL	sub_FF8840C0 \n"

"		MOV     R0, #0\n"							// added
"		STR     R0, [R4,#0x24]\n"					// added, fixes overrides  behavior at short shutter press (from S95)

//"		LDR	R0, [R4,#0x24] \n"						// above two lines make this code redundant
//"		CMP	R0, #0 \n"								// above two lines make this code redundant

//"		BLNE	sub_FF992FD8 \n"					// above two lines make this code redundant
//"		BLNE	sub_FF992FD8_my \n"					// patched (above two lines make this patch redundant)

"		B	loc_FF886B60 \n"

// jump table entry 1
"loc_FF8869B8: \n"
"		LDRH	R1, [R4] \n"
"		SUB	R12, R1, #0x8200 \n"
"		SUBS	R12, R12, #0x2E \n"
"		LDRNE	R0, [R0,#0xC] \n"

//"		BLNE	sub_FF992E04 \n"
"		BLNE	sub_FF992E04_my \n"

"		B	loc_FF886B60 \n"

// jump table entry 2
"loc_FF8869D0: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF8873A0 \n"
"		LDR	R0, [R4,#0xC]\n"
"		CMP	R0, #0\n"
"		BLNE	sub_FF888028 \n"
"		B	loc_FF886B60 \n"

"loc_FF8869E8: \n"
"		BL	sub_FF886D24 \n"
"		B	loc_FF8869F4 \n"

"loc_FF8869F0: \n"
"		BL	sub_FF887068 \n"
"loc_FF8869F4: \n"
"		STR	R6, [R4,#0x24] \n"
"		B	loc_FF886B60 \n"

"loc_FF8869FC: \n"
"		BL	sub_FF887070 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A04: \n"
"		BL	sub_FF887274 \n"
"		B	loc_FF886A1C \n"

"loc_FF886A0C: \n"
"		LDR	R0, [R0,#0xC] \n"
"		BL	sub_FF993040 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A18: \n"
"		BL	sub_FF887310 \n"
"loc_FF886A1C: \n"
"		BL	sub_FF8840C0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A24: \n"
"		LDR	R0, [R4,#0x54] \n"
"		BL	sub_FF887A60 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A30: \n"
"		BL	sub_FF887DE0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A38: \n"
"		BL	sub_FF887E44 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A40: \n"
"		BL	sub_FF887068 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A48: \n"
"		BL	sub_FF991DE0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A50: \n"
"		BL	sub_FF992030 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A58: \n"
"		BL	sub_FF9920FC \n"
"		B	loc_FF886B60 \n"

"loc_FF886A60: \n"
"		BL	sub_FF992210 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A68: \n"
"		BL	sub_FF9922E0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A70: \n"
"		MOV	R0, #0 \n"
"		B	loc_FF886A94 \n"

"loc_FF886A78: \n"
"		BL	sub_FF9928F4 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A80: \n"
"		BL	sub_FF99298C \n"
"		B	loc_FF886B60 \n"

"loc_FF886A88: \n"
"		BL	sub_FF992A6C \n"
"		B	loc_FF886B60 \n"

"loc_FF886A90: \n"
"		MOV	R0, #1 \n"
"loc_FF886A94: \n"
"		BL	sub_FF992798 \n"
"		B	loc_FF886B60 \n"

"loc_FF886A9C: \n"
"		BL	sub_FF8875DC \n"
"		B	loc_FF886B60 \n"

"loc_FF886AA4: \n"
"		BL	sub_FF887684 \n"
"		BL	sub_FF993CA0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886AB0: \n"
"		BL	sub_FF9925C0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886AB8: \n"
"		MOV     R2, #2 \n"
"		ADD     R1, R4, #0x68 \n"
"		MOV     R0, #0x6F \n"
"		BL      sub_FF8999CC \n"
"		TST     R0, #1 \n"
"		LDRNE   R1, =0x531 \n"
"		LDRNE   R0, =0xFF8863B4 \n"
"		BLNE    _DebugAssert \n"
"		LDRH    R0, [R4,#0x68] \n"
"		CMP     R0, #1 \n"
"		BLEQ    sub_FF9925B4 \n"
"		B	loc_FF886B60 \n"

"loc_FF886AE8: \n"
"		BL	sub_FF9926EC \n"
"		B	loc_FF886B60 \n"

"loc_FF886AF0: \n"
"		BL	sub_FF993D70 \n"
"		B	loc_FF886B60 \n"

"loc_FF886AF8: \n"
"		BL	sub_FF837D44 \n"
"		B	loc_FF886B60 \n"

"loc_FF886B00: \n"
"		BL	sub_FF88A2DC \n"
"		B	loc_FF886B60 \n"

"loc_FF886B08: \n"
"		BL	sub_FF88A364 \n"
"		B	loc_FF886B60 \n"

"loc_FF886B10: \n"
"		BL	sub_FF88A3C0 \n"
"		BL	sub_FF88A380 \n"
"		B	loc_FF886B60 \n"

"loc_FF886B1C: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF9937DC \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF99390C \n"
"		LDRH	R0, [R4,#0xA4] \n"
"		CMP	R0, #4 \n"
"		LDRNEH	R0, [R4] \n"
"		SUBNE	R12, R0, #0x4200 \n"
"		SUBNES	R12, R12, #0x2A \n"
"		BNE	loc_FF886B60 \n"
"		BL	sub_FF88A364 \n"
"		BL	sub_FF88A8D8 \n"
"		BL	sub_FF88A7E0 \n"
"		B	loc_FF886B60 \n"

"loc_FF886B54: \n"
"		LDR	R1, =0x591 \n"
"		LDR	R0, =0xFF8863B4 \n"
"		BL	_DebugAssert \n"				// DebugAssert

"loc_FF886B60: \n"
"		LDR	R0, [SP] \n"
"		LDR	R1, [R0,#4] \n"
"		LDR	R0, [R7] \n"
"		BL	sub_FF89179C \n"
"		LDR	R5, [SP] \n"
"		LDR	R0, [R5,#8] \n"
"		CMP	R0, #0 \n"
"		LDREQ	R1, =0x115 \n"
"		LDREQ	R0, =0xFF8863B4 \n"
"		BLEQ	_DebugAssert \n"			// DebugAssert
"		STR	R6, [R5,#8] \n"
"		B	loc_FF8868D4 \n"
	);
}

// @ FF992E04
void __attribute__((naked,noinline)) sub_FF992E04_my(){
asm volatile(
"                STMFD   SP!, {R3-R7,LR} \n"
"                LDR     R5, =0x3BC24 \n"
"                MOV     R4, R0 \n"
"                LDR     R0, [R5,#0x24] \n"
"                MOV     R6, #0 \n"
"                CMP     R0, #0 \n"
"                BNE     loc_FF992E40 \n"
"                MOV     R0, #0xC \n"
"                BL      sub_FF88C64C \n"
"                TST     R0, #1 \n"
"                MOVNE   R2, R4 \n"
"                LDMNEFD SP!, {R3-R7,LR} \n"
"                MOVNE   R1, #1 \n"
"                MOVNE   R0, #1 \n"
"                BNE     sub_FF88479C \n"

"loc_FF992E40: \n"
"                LDR     R0, [R4,#8] \n"
"                LDR     R7, =0x420C \n"
"                ORR     R0, R0, #1 \n"
"                STR     R0, [R4,#8] \n"
"                LDRH    R0, [R5] \n"
"                CMP     R0, R7 \n"
"                BEQ     loc_FF992ED0 \n"
"                LDRH    R0, [R5,#0xA2] \n"
"                CMP     R0, #3 \n"
"                BEQ     loc_FF992F18 \n"
"                LDR     R0, [R4,#0xC] \n"
"                CMP     R0, #1 \n"
"                BLS     loc_FF992EDC \n"
"                LDRH    R0, [R5,#0xA0] \n"
"                CMP     R0, #0 \n"
"                BNE     loc_FF992F18 \n"
"                LDRH    R0, [R5,#0x9C] \n"
"                CMP     R0, #2 \n"
"                BNE     loc_FF992EE8 \n"
"                BL      sub_FF887744 \n"
"                LDRH    R0, [R5] \n"
"                CMP     R0, R7 \n"
"                BEQ     loc_FF992ED0 \n"
"                LDRH    R0, [R5,#0xA2] \n"
"                CMP     R0, #3 \n"
"                BEQ     loc_FF992F18 \n"
"                LDR     R0, [R4,#0xC] \n"
"                CMP     R0, #1 \n"
"                BLS     loc_FF992EDC \n"
"                LDRH    R0, [R5,#0xA0] \n"
"                CMP     R0, #0 \n"
"                BNE     loc_FF992F18 \n"
"                LDRH    R0, [R5,#0x9C] \n"
"                CMP     R0, #2 \n"
"                BEQ     loc_FF992F14 \n"
"                B       loc_FF992EE8 \n"

"loc_FF992ED0: \n"
"                LDRH    R0, [R5,#0xA2] \n"
"                CMP     R0, #3 \n"
"                BEQ     loc_FF992F18 \n"

"loc_FF992EDC: \n"
"                LDRH    R0, [R5,#0xA0] \n"
"                CMP     R0, #0 \n"
"                BNE     loc_FF992F18 \n"

"loc_FF992EE8: \n"
"                LDRH    R0, [R5,#0x9C] \n"
"                CMP     R0, #1 \n"
"                BNE     loc_FF992F18 \n"
"                LDRH    R0, [R5] \n"
"                CMP     R0, R7 \n"
"                LDRNE   R0, [R4,#0xC] \n"
"                CMPNE   R0, #1 \n"
"                BLS     loc_FF992F18 \n"
"                LDR     R0, [R4,#0x10] \n"
"                CMP     R0, #1 \n"
"                BNE     loc_FF992F18 \n"

"loc_FF992F14: \n"
"                BL      sub_FF993DA8 \n"

"loc_FF992F18: \n"
"                BL      sub_FF993D70 \n"
"                BL      sub_FF887078 \n"
"                LDR     R0, [R5,#0x24] \n"			// before shot XXX
"                CMP     R0, #0 \n"
"                BNE     loc_FF992FB0 \n"
"                MOV     R0, R4 \n"
"                BL      sub_FFAEC418 \n"
"                TST     R0, #1 \n"
"                BNE     locret_FF992FD4 \n"
"                MOV     R0, R4 \n"
"                BL      sub_FFAEC82C \n"
"                BL      sub_FF9935B0 \n"
"                MOV     R6, #1 \n"
"                MOV     R0, #2 \n"
"                BL      sub_FF87FD8C \n"			// after pre-flash, before shot XXX

                 "BL      wait_until_remote_button_is_released\n"
                 "BL      capt_seq_hook_set_nr\n"                     // +

"                LDRH    R0, [R5] \n"
"                SUB     R12, R0, #0x8200 \n"
"                SUBS    R12, R12, #0x2D \n"
"                BNE     loc_FF992FA0 \n"
"                MOV     R2, #2 \n"
"                ADD     R0, R2, #0x15C \n"
"                MOV     R1, SP \n"
"                STR     R6, [SP] \n"
"                BL      _GetPropertyCase \n"
"                TST     R0, #1 \n"
"                MOVNE   R1, #0xC3 \n"
//"                ADRNE   R0, aSscaptureseq_c \n"
"                LDRNE   R0, =0xFF9930B4 \n"
"                BLNE    _DebugAssert \n"
"                LDRH    R0, [SP] \n"
"                CMP     R0, #1 \n"
"                STRHI   R6, [R4,#0xD4] \n"
"                BHI     loc_FF992FC0 \n"
"                MOV     R0, #0 \n"
"                STR     R0, [R4,#0xD4] \n"

"loc_FF992FA0: \n"
"                MOV     R0, R4 \n"
//"                BL      sub_FFAECD24 \n"
"                BL      sub_FFAECD24_my \n"
"                MOV     R6, R0 \n"
"                B       loc_FF992FC4 \n"

"loc_FF992FB0: \n"
"                LDR     R0, =0x85AC \n"
"                LDR     R0, [R0] \n"
"                CMP     R0, #0 \n"
"                BEQ     loc_FF992FC4 \n"

"loc_FF992FC0: \n"
"                MOV     R6, #0x1D \n"

"loc_FF992FC4: \n"
"                MOV     R1, R6 \n"
"                MOV     R0, R4 \n"
"                LDMFD   SP!, {R3-R7,LR} \n"
"                B       sub_FFAEC53C \n"

"locret_FF992FD4: \n"
"                LDMFD   SP!, {R3-R7,PC} \n"
);
}

// @ FFAECD24
void __attribute__((naked,noinline)) sub_FFAECD24_my(){
 asm volatile(
"                STMFD   SP!, {R2-R6,LR} \n"
"                MOV     R5, R0 \n"
"                BL      sub_FF993AD0 \n"
//"                MOVL    R1, 0xFFFFFFFF \n"
"				 MVN     R1, #0 \n"
"                BL      sub_FF8917D0 \n"
"                LDR     R0, =0xFFAEC5B8 \n"
"                MOV     R1, R5 \n"
"                BL      sub_FF8C6448 \n"
"                MOV     R0, R5 \n"
"                BL      sub_FFAEC4C4 \n"
"                MOV     R0, R5 \n"
"                BL      sub_FFAEC914 \n"
"                MOV     R4, R0 \n"
"                LDR     R1, =0xE164 \n"
"                MOV     R0, #0x8A \n"
"                MOV     R2, #4 \n"
"                BL      _GetPropertyCase \n"
"                TST     R0, #1 \n"
"                LDRNE   R1, =0x1F6 \n"
//"                ADRNE   R0, aSsstandardcapt ; "SsStandardCaptureSeq.c" \n"
"                LDRNE   R0, =0xFFAECEAC \n"
"                BLNE    _DebugAssert \n"
"                BL      sub_FF889A04 \n"
"                MOV     R0, R4 \n"
"                CMP     R0, #1 \n"
"                MOV     R4, #0 \n"
"                BEQ     loc_FFAECDC4 \n"
"                CMP     R0, #2 \n"
"                BEQ     loc_FFAECDD4 \n"
"                CMP     R0, #3 \n"
"                BEQ     loc_FFAECDF8 \n"
"                CMP     R0, #7 \n"
"                BNE     loc_FFAECE14 \n"
"                MOV     R0, #0 \n"
"                BL      sub_FF8C6478 \n"
"                MOV     R0, #4 \n"
"                STR     R0, [SP,#0x4] \n"

"loc_FFAECDB4: \n"
"                ADD     R1, SP, #0x4 \n"
"                MOV     R0, R5 \n"
"                BL      sub_FFAECB88 \n"
"                B       loc_FFAECDF0 \n"

"loc_FFAECDC4: \n"
"                MOV     R0, #1 \n"
"                BL      sub_FF8C6478 \n"
"                STR     R4, [SP,#0x4] \n"
"                B       loc_FFAECDB4 \n"

"loc_FFAECDD4: \n"
"                MOV     R0, #1 \n"
"                BL      sub_FF8C6478 \n"
"                MOV     R0, #1 \n"
"                STR     R0, [SP,#0x4] \n"
"                MOV     R0, R5 \n"
"                ADD     R1, SP, #0x4 \n"
"                BL      sub_FFAECF80 \n"

"loc_FFAECDF0: \n"

"		BL      capt_seq_hook_raw_here\n"      		// added (16/2/2011, moved here so that long exposures work)

"                MOV     R6, R0 \n"
"                B       loc_FFAECE20 \n"

"loc_FFAECDF8: \n"
"                MOV     R0, #1 \n"
"                BL      sub_FF8C6478 \n"
"                ADD     R1, SP, #0x4 \n"
"                MOV     R0, R5 \n"
"                STR     R4, [SP,#0x4] \n"
"                BL      sub_FFAECC04 \n"
"                B       loc_FFAECDF0 \n"

"loc_FFAECE14: \n"
"                MOV     R1, #0x22C \n"
//"                ADR     R0, aSsstandardcapt ; "SsStandardCaptureSeq.c" \n"
"                LDR   R0, =0xFFAECEAC \n"
"                BL      _DebugAssert \n"

"loc_FFAECE20: \n"
"                TST     R6, #1 \n"
"                MOVNE   R0, R6 \n"
"                BNE     locret_FFAECE8C \n"
"                MOV     R1, #0 \n"
//"                ADR     R0, nullsub_309 \n"
"				 LDR	 R0, =0xFFAECAF8 \n"
"                BL      sub_FF8C6448 \n"
"                LDR     R0, =0x3BC24 \n"
"                LDRH    R0, [R0] \n"
"                SUB     R12, R0, #0x4000 \n"
"                SUBS    R12, R12, #0x20C \n"
"                BLEQ    sub_FF8AF954 \n"
"                MOV     R0, R5 \n"
"                BL      sub_FFAEC9BC \n"
"                BL      sub_FF993AD0 \n"
"                MOV     R3, #0x244 \n"
"                STR     R3, [SP] \n"
"                LDR     R2, =0x3A98 \n"
//"                ADR     R3, aSsstandardcapt ; "SsStandardCaptureSeq.c" \n"
"                LDR   R3, =0xFFAECEAC \n"
"                MOV     R1, #4 \n"
"                BL      sub_FF88C9C8 \n"
"                CMP     R0, #0 \n"
"                MOVNE   R1, #0x244 \n"
//"                ADRNE   R0, aSsstandardcapt ; "SsStandardCaptureSeq.c" \n"
"                LDRNE   R0, =0xFFAECEAC \n"
"                BLNE    _DebugAssert \n"
"                LDRH    R0, [SP,#0x4] \n"
"                STRH    R0, [R5,#0x14] \n"
"                MOV     R0, #0 \n"

"locret_FFAECE8C: \n"
"                LDMFD   SP!, {R2-R6,PC} \n"
	 );
}

/*************************************************************/
// @ FF8D081C (1.00n)
void __attribute__((naked,noinline)) exp_drv_task(){

 asm volatile(
"                STMFD   SP!, {R4-R8,LR} \n"
"                SUB     SP, SP, #0x20 \n"
"                LDR     R8, =0xBB8 \n"
"                LDR     R7, =0x5094 \n"
"                LDR     R5, =0x57870 \n"
"                MOV     R0, #0 \n"
"                ADD     R6, SP, #0x10 \n"
"                STR     R0, [SP,#0x0C] \n"

"loc_FF8D083C: \n"
"                LDR     R0, [R7,#0x20] \n"
"                MOV     R2, #0 \n"
"                ADD     R1, SP, #0x1C \n"
"                BL      sub_FF83A4C8 \n"
"                LDR     R0, [SP,#0x0C] \n"
"                CMP     R0, #1 \n"
"                BNE     loc_FF8D0888 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R0, [R0] \n"
"                CMP     R0, #0x14 \n"
"                CMPNE   R0, #0x15 \n"
"                CMPNE   R0, #0x16 \n"
"                CMPNE   R0, #0x17 \n"
"                BEQ     loc_FF8D09EC \n"
"                CMP     R0, #0x29 \n"
"                BEQ     loc_FF8D0974 \n"
"                ADD     R1, SP, #0x0C \n"
"                MOV     R0, #0 \n"
"                BL      sub_FF8D07CC \n"

"loc_FF8D0888: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R1, [R0] \n"
"                CMP     R1, #0x2F \n"
"                BNE     loc_FF8D08B8 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                BL      sub_FF8D1BC0 \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R1, #1 \n"
"                BL      sub_FF89179C \n"
"                BL      _ExitTask \n"
"                ADD     SP, SP, #0x20 \n"
"                LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF8D08B8: \n"
"                CMP     R1, #0x2E \n"
"                BNE     loc_FF8D08D4 \n"
"                LDR     R2, [R0,#0x8C]! \n"
"                LDR     R1, [R0,#4] \n"
"                MOV     R0, R1 \n"
"                BLX     R2 \n"
"                B       loc_FF8D0EA8 \n"

"loc_FF8D08D4: \n"
"                CMP     R1, #0x27 \n"
"                BNE     loc_FF8D0924 \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R1, #0x80 \n"
"                BL      sub_FF8917D0 \n"
"                LDR     R0, =0xFF8CC67C \n"
"                MOV     R1, #0x80 \n"
"                BL      sub_FF97F76C \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R2, R8 \n"
"                MOV     R1, #0x80 \n"
"                BL      sub_FF8916DC \n"
"                TST     R0, #1 \n"
"                LDRNE   R1, =0x1089 \n"
"                BNE     loc_FF8D09E0 \n"

"loc_FF8D0910: \n"
"                LDR     R1, [SP,#0x1C] \n"
"                LDR     R0, [R1,#0x90] \n"
"                LDR     R1, [R1,#0x8C] \n"
"                BLX     R1 \n"
"                B       loc_FF8D0EA8 \n"

"loc_FF8D0924: \n"
"                CMP     R1, #0x28 \n"
"                BNE     loc_FF8D096C \n"
"                ADD     R1, SP, #0x0C \n"
"                BL      sub_FF8D07CC \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R1, #0x100 \n"
"                BL      sub_FF8917D0 \n"
"                LDR     R0, =0xFF8CC68C \n"
"                MOV     R1, #0x100 \n"
"                BL      sub_FF98019C \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R2, R8 \n"
"                MOV     R1, #0x100 \n"
"                BL      sub_FF8916DC \n"
"                TST     R0, #1 \n"
"                BEQ     loc_FF8D0910 \n"
"                LDR     R1, =0x1093 \n"
"                B       loc_FF8D09E0 \n"

"loc_FF8D096C: \n"
"                CMP     R1, #0x29 \n"
"                BNE     loc_FF8D0984 \n"

"loc_FF8D0974: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                ADD     R1, SP, #0x0C \n"
"                BL      sub_FF8D07CC \n"
"                B       loc_FF8D0910 \n"

"loc_FF8D0984: \n"
"                CMP     R1, #0x2C \n"
"                BNE     loc_FF8D099C \n"
"                BL      sub_FF8BEBD0 \n"
"                BL      sub_FF8BF7DC \n"
"                BL      sub_FF8BF348 \n"
"                B       loc_FF8D0910 \n"

"loc_FF8D099C: \n"
"                CMP     R1, #0x2D \n"
"                BNE     loc_FF8D09EC \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R1, #4 \n"
"                BL      sub_FF8917D0 \n"
"                LDR     R1, =0xFF8CC6AC \n"
"                LDR     R0, =0xFFFFF400 \n"
"                MOV     R2, #4 \n"
"                BL      sub_FF8BE64C \n"
"                BL      sub_FF8BE8D4 \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R2, R8 \n"
"                MOV     R1, #4 \n"
"                BL      sub_FF8915F8 \n"
"                TST     R0, #1 \n"
"                BEQ     loc_FF8D0910 \n"
"                LDR     R1, =0x10BB \n"

"loc_FF8D09E0: \n"
"                LDR     R0, =0xFF8CCD34 \n"
"                BL      _DebugAssert \n"
"                B       loc_FF8D0910 \n"

"loc_FF8D09EC: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                MOV     R4, #1 \n"
"                LDR     R1, [R0] \n"
"                CMP     R1, #0x12 \n"
"                CMPNE   R1, #0x13 \n"
"                BNE     loc_FF8D0A5C \n"
"                LDR     R1, [R0,#0x7C] \n"
"                ADD     R1, R1, R1,LSL#1 \n"
"                ADD     R1, R0, R1,LSL#2 \n"
"                SUB     R1, R1, #8 \n"
"                LDMIA   R1, {R2-R4} \n"
"                STMIA   R6, {R2-R4} \n"
"                BL      sub_FF8CEF54 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R3, [R0,#0x8C] \n"
"                LDR     R2, [R0,#0x90] \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                BL      sub_FF8D1FCC \n"
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R3, [R0,#0x94] \n"
"                LDR     R2, [R0,#0x98] \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"
"                B       loc_FF8D0DE4 \n"

"loc_FF8D0A5C: \n"
"                CMP     R1, #0x14 \n"
"                CMPNE   R1, #0x15 \n"
"                CMPNE   R1, #0x16 \n"
"                CMPNE   R1, #0x17 \n"
"                BNE     loc_FF8D0B14 \n"
"                ADD     R3, SP, #0x0C \n"
"                MOV     R2, SP \n"
"                ADD     R1, SP, #0x10 \n"
"                BL      sub_FF8CF1C0 \n"
"                CMP     R0, #1 \n"
"                MOV     R4, R0 \n"
"                CMPNE   R4, #5 \n"
"                BNE     loc_FF8D0AB0 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                MOV     R2, R4 \n"
"                LDR     R1, [R0,#0x7C]! \n"
"                LDR     R12, [R0,#0x10]! \n"
"                LDR     R3, [R0,#4] \n"
"                MOV     R0, SP \n"
"                BLX     R12 \n"
"                B       loc_FF8D0AE8 \n"

"loc_FF8D0AB0: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                CMP     R4, #2 \n"
"                LDR     R3, [R0,#0x90] \n"
"                CMPNE   R4, #6 \n"
"                BNE     loc_FF8D0AFC \n"
"                LDR     R12, [R0,#0x8C] \n"
"                MOV     R0, SP \n"
"                MOV     R2, R4 \n"
"                MOV     R1, #1 \n"
"                BLX     R12 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                MOV     R2, SP \n"
"                ADD     R1, SP, #0x10 \n"
"                BL      sub_FF8D0518 \n"

"loc_FF8D0AE8: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R2, [SP,#0x0C] \n"
"                MOV     R1, R4 \n"
"                BL      sub_FF8D076C \n"
"                B       loc_FF8D0DE4 \n"

"loc_FF8D0AFC: \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R12, [R0,#0x8C] \n"
"                ADD     R0, R0, #4 \n"
"                MOV     R2, R4 \n"
"                BLX     R12 \n"
"                B       loc_FF8D0DE4 \n"

"loc_FF8D0B14: \n"
"                CMP     R1, #0x23 \n"
"                CMPNE   R1, #0x24 \n"
"                BNE     loc_FF8D0B60 \n"
"                LDR     R1, [R0,#0x7C] \n"
"                ADD     R1, R1, R1,LSL#1 \n"
"                ADD     R1, R0, R1,LSL#2 \n"
"                SUB     R1, R1, #8 \n"
"                LDMIA   R1, {R2-R4} \n"
"                STMIA   R6, {R2-R4} \n"
"                BL      sub_FF8CDFD8 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R3, [R0,#0x8C] \n"
"                LDR     R2, [R0,#0x90] \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"
"                LDR     R0, [SP,#0x1C] \n"
"                BL      sub_FF8CE424 \n"
"                B       loc_FF8D0DE4 \n"

"loc_FF8D0B60: \n"
"                ADD     R1, R0, #4 \n"
"                LDMIA   R1, {R2,R3,R12} \n"
"                STMIA   R6, {R2,R3,R12} \n"
"                LDR     R1, [R0] \n"
"                CMP     R1, #0x26 \n"
"                ADDLS   PC, PC, R1,LSL#2 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0B7C: \n"
"                B       loc_FF8D0C18 \n"

"loc_FF8D0B80: \n"
"                B       loc_FF8D0C18 \n"

"loc_FF8D0B84: \n"
"                B       loc_FF8D0C20 \n"

"loc_FF8D0B88: \n"
"                B       loc_FF8D0C28 \n"

"loc_FF8D0B8C: \n"
"                B       loc_FF8D0C28 \n"

"loc_FF8D0B90: \n"
"                B       loc_FF8D0C28 \n"

"loc_FF8D0B94: \n"
"                B       loc_FF8D0C18 \n"

"loc_FF8D0B98: \n"
"                B       loc_FF8D0C20 \n"

"loc_FF8D0B9C: \n"
"                B       loc_FF8D0C28 \n"

"loc_FF8D0BA0: \n"
"                B       loc_FF8D0C28 \n"

"loc_FF8D0BA4: \n"
"                B       loc_FF8D0C40 \n"

"loc_FF8D0BA8: \n"
"                B       loc_FF8D0C40 \n"

"loc_FF8D0BAC: \n"
"                B       loc_FF8D0DB0 \n"

"loc_FF8D0BB0: \n"
"                B       loc_FF8D0DB8 \n"

"loc_FF8D0BB4: \n"
"                B       loc_FF8D0DB8 \n"

"loc_FF8D0BB8: \n"
"                B       loc_FF8D0DB8 \n"

"loc_FF8D0BBC: \n"
"                B       loc_FF8D0DB8 \n"

"loc_FF8D0BC0: \n"
"                B       loc_FF8D0DC0 \n"

"loc_FF8D0BC4: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0BC8: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0BCC: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0BD0: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0BD4: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0BD8: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0BDC: \n"
"                B       loc_FF8D0C30 \n"

"loc_FF8D0BE0: \n"
"                B       loc_FF8D0C38 \n"

"loc_FF8D0BE4: \n"
"                B       loc_FF8D0C38 \n"

"loc_FF8D0BE8: \n"
"                B       loc_FF8D0C4C \n"

"loc_FF8D0BEC: \n"
"                B       loc_FF8D0C4C \n"

"loc_FF8D0BF0: \n"
"                B       loc_FF8D0C54 \n"

"loc_FF8D0BF4: \n"
"                B       loc_FF8D0C8C \n"

"loc_FF8D0BF8: \n"
"                B       loc_FF8D0CC4 \n"

"loc_FF8D0BFC: \n"
"                B       loc_FF8D0D60 \n"

"loc_FF8D0C00: \n"
"                B       loc_FF8D0D98 \n"

"loc_FF8D0C04: \n"
"                B       loc_FF8D0D98 \n"

"loc_FF8D0C08: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C0C: \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C10: \n"
"                B       loc_FF8D0DA0 \n"

"loc_FF8D0C14: \n"
"                B       loc_FF8D0DA8 \n"

"loc_FF8D0C18: \n"
//"; jumptable FF8D0B70 entries 0,1,6      ; LOCATION: ExpDrv.c:928
"                BL      sub_FF8CCBBC \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C20: \n"
//"; jumptable FF8D0B70 entries 2,7        ; LOCATION: ExpDrv.c:0
"                BL      sub_FF8CCE58 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C28: \n"
//"; jumptable FF8D0B70 entries 3-5,8,9    ; LOCATION: ExpDrv.c:0
"                BL      sub_FF8CD080 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C30: \n"
//"; jumptable FF8D0B70 entry 24           ; LOCATION: ExpDrv.c:2
"                BL      sub_FF8CD358 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C38: \n"
//"; jumptable FF8D0B70 entries 25,26      ; LOCATION: ExpDrv.c:0
"                BL      sub_FF8CD570 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C40: \n"
//"; jumptable FF8D0B70 entries 10,11      ; LOCATION: ExpDrv.c:2
//"                BL      sub_FF8CD894 \n"
"                BL      sub_FF8CD894_my \n"  // patched
"                MOV     R4, #0 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C4C: \n"
//"; jumptable FF8D0B70 entries 27,28      ; LOCATION: ExpDrv.c:0
"                BL      sub_FF8CD9DC \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C54: \n"
//"; jumptable FF8D0B70 entry 29
"                LDRH    R1, [R0,#4] \n"
"                STRH    R1, [SP,#0x10] \n"
"                LDRH    R1, [R5,#2] \n"
"                STRH    R1, [SP,#0x12] \n"
"                LDRH    R1, [R5,#4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R5,#6] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R0,#0xC] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R5,#0xA] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                BL      sub_FF8D1CC4 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0C8C: \n"
//"; jumptable FF8D0B70 entry 30
"                LDRH    R1, [R0,#4] \n"
"                STRH    R1, [SP,#0x10] \n"
"                LDRH    R1, [R5,#2] \n"
"                STRH    R1, [SP,#0x12] \n"
"                LDRH    R1, [R5,#4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R5,#6] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R5,#8] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R5,#0xA] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                BL      sub_FF8D1DCC \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0CC4: \n"
//"; jumptable FF8D0B70 entry 31
"                LDRH    R1, [R5] \n"
"                STRH    R1, [SP,#0x10] \n"
"                LDRH    R1, [R0,#6] \n"
"                STRH    R1, [SP,#0x12] \n"
"                LDRH    R1, [R5,#4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R5,#6] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R5,#8] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R5,#0xA] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                BL      sub_FF8D1E80 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0D60: \n"
//"; jumptable FF8D0B70 entry 32
"                LDRH    R1, [R5] \n"
"                STRH    R1, [SP,#0x10] \n"
"                LDRH    R1, [R5,#2] \n"
"                STRH    R1, [SP,#0x12] \n"
"                LDRH    R1, [R5,#4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R5,#6] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R0,#0xC] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R5,#0xA] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                BL      sub_FF8D1F28 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0D98: \n"
//"; jumptable FF8D0B70 entries 33,34      ; LOCATION: ExpDrv.c:6
"                BL      sub_FF8CDDB0 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0DA0: \n"
//"; jumptable FF8D0B70 entry 37           ; LOCATION: ExpDrv.c:10
"                BL      sub_FF8CE528 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0DA8: \n"
//"; jumptable FF8D0B70 entry 38           ; LOCATION: ExpDrv.c:6
"                BL      sub_FF8CE7C4 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0DB0: \n"
//"; jumptable FF8D0B70 entry 12           ; LOCATION: ExpDrv.c:2
"                BL      sub_FF8CE9A4 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0DB8: \n"
//"; jumptable FF8D0B70 entries 13-16      ; LOCATION: ExpDrv.c:128
"                BL      sub_FF8CEB60 \n"
"                B       loc_FF8D0DC4 \n"

"loc_FF8D0DC0: \n"
//"; jumptable FF8D0B70 entry 17           ; LOCATION: ExpDrv.c:2
"                BL      sub_FF8CED4C \n"

"loc_FF8D0DC4: \n"
//"; jumptable FF8D0B70 default entry
//"; jumptable FF8D0B70 entries 18-23,35,36
"                LDR     R0, [SP,#0x1C] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R3, [R0,#0x8C] \n"
"                LDR     R2, [R0,#0x90] \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"
"                CMP     R4, #1 \n"
"                BNE     loc_FF8D0E2C \n"

"loc_FF8D0DE4: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                MOV     R2, #0xC \n"
"                LDR     R1, [R0,#0x7C] \n"
"                ADD     R1, R1, R1,LSL#1 \n"
"                ADD     R0, R0, R1,LSL#2 \n"
"                SUB     R4, R0, #8 \n"
"                LDR     R0, =0x57870 \n"
"                ADD     R1, SP, #0x10 \n"
"                BL      sub_FFB92564 \n"
"                LDR     R0, =0x5787C \n"
"                MOV     R2, #0xC \n"
"                ADD     R1, SP, #0x10 \n"
"                BL      sub_FFB92564 \n"
"                LDR     R0, =0x57888 \n"
"                MOV     R2, #0xC \n"
"                MOV     R1, R4 \n"
"                BL      sub_FFB92564 \n"
"                B       loc_FF8D0EA8 \n"

"loc_FF8D0E2C: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                MOV     R3, #1 \n"
"                LDR     R0, [R0] \n"
"                CMP     R0, #0xB \n"
"                BNE     loc_FF8D0E74 \n"
"                MOV     R2, #0 \n"
"                STRD    R2, [SP] \n"
"                MOV     R2, #1 \n"
"                MOV     R1, #1 \n"
"                MOV     R0, #0 \n"
"                BL      sub_FF8CC99C \n"
"                MOV     R3, #1 \n"
"                MOV     R2, #0 \n"
"                STRD    R2, [SP] \n"
"                MOV     R2, #1 \n"
"                MOV     R1, #1 \n"
"                MOV     R0, #0 \n"
"                B       loc_FF8D0EA4 \n"

"loc_FF8D0E74: \n"
"                MOV     R2, #1 \n"
"                STRD    R2, [SP] \n"
"                MOV     R3, #1 \n"
"                MOV     R1, #1 \n"
"                MOV     R0, #1 \n"
"                BL      sub_FF8CC99C \n"
"                MOV     R3, #1 \n"
"                MOV     R2, #1 \n"
"                MOV     R1, #1 \n"
"                MOV     R0, #1 \n"
"                STR     R3, [SP] \n"
"                STR     R3, [SP,#0x04] \n"

"loc_FF8D0EA4: \n"
"                BL      sub_FF8CCB04 \n"

"loc_FF8D0EA8: \n"
"                LDR     R0, [SP,#0x1C] \n"
"                BL      sub_FF8D1BC0 \n"
"                B       loc_FF8D083C \n"
 );
}

// @ FF8CD894
void __attribute__((naked,noinline)) sub_FF8CD894_my() {
	asm volatile (
"                STMFD   SP!, {R4-R8,LR} \n"
"                LDR     R7, =0x5094 \n"
"                MOV     R4, R0 \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R1, #0x3E \n"
"                BL      sub_FF8917D0 \n"
"                LDRSH   R0, [R4,#4] \n"
"                MOV     R2, #0 \n"
"                MOV     R1, #0 \n"
"                BL      sub_FF8CC700 \n"
"                MOV     R5, R0 \n"
"                LDRSH   R0, [R4,#6] \n"
"                BL      sub_FF8CC810 \n"
"                LDRSH   R0, [R4,#8] \n"
"                BL      sub_FF8CC868 \n"
"                LDRSH   R0, [R4,#0xA] \n"
"                BL      sub_FF8CC8C0 \n"
"                LDRSH   R0, [R4,#0xC] \n"
"                MOV     R1, #0 \n"
"                BL      sub_FF8CC918 \n"
"                MOV     R6, R0 \n"
"                LDRSH   R0, [R4,#0xE] \n"
"                BL      sub_FF8D1C64 \n"
"                LDR     R0, [R4] \n"
"                LDR     R8, =0x57888 \n"
"                CMP     R0, #0xB \n"
"                MOVEQ   R5, #0 \n"
"                MOVEQ   R6, #0 \n"
"                BEQ     loc_FF8CD930 \n"
"                CMP     R5, #1 \n"
"                BNE     loc_FF8CD930 \n"
"                LDRSH   R0, [R4,#4] \n"
"                LDR     R1, =0xFF8CC66C \n"
"                MOV     R2, #2 \n"
"                BL      sub_FF97FAB8 \n"
"                STRH    R0, [R4,#4] \n"
"                MOV     R0, #0 \n"
"                STR     R0, [R7,#0x28] \n"
"                B       loc_FF8CD938 \n"

"loc_FF8CD930: \n"
"                LDRH    R0, [R8] \n"
"                STRH    R0, [R4,#4] \n"

"loc_FF8CD938: \n"
"                CMP     R6, #1 \n"
"                LDRNEH  R0, [R8,#8] \n"
"                BNE     loc_FF8CD954 \n"
"                LDRSH   R0, [R4,#0xC] \n"
"                LDR     R1, =0xFF8CC6F0 \n"
"                MOV     R2, #0x20 \n"
"                BL      sub_FF8D1C80 \n"

"loc_FF8CD954: \n"
"                STRH    R0, [R4,#0xC] \n"
"                LDRSH   R0, [R4,#6] \n"
//"                BL      sub_FF8BE940 \n"
"                BL      sub_FF8BE940_my \n" // patched
"				B	sub_FF8CD960 \n"		// continue in firmware
	);
}

// @ FF8BE940
void __attribute__((naked,noinline)) sub_FF8BE940_my() {
	asm volatile (
"                STMFD   SP!, {R4-R6,LR} \n"
"                LDR     R5, =0x4D70 \n"
"                MOV     R4, R0 \n"
"                LDR     R0, [R5,#4] \n"
"                CMP     R0, #1 \n"
"                LDRNE   R1, =0x146 \n"
"                LDRNE   R0, =0xFF8BE744 \n"
"                BLNE    _DebugAssert \n"
"                CMN     R4, #0xC00 \n"
"                LDREQSH R4, [R5,#2] \n"
"                CMN     R4, #0xC00 \n"
"                MOVEQ   R1, #0x14C \n"
"                LDRNE   R0, =0xFF8BE744 \n"
"                STRH    R4, [R5,#2] \n"
"                BLEQ    _DebugAssert \n"
"                MOV     R0, R4 \n"
"                BL      apex2us \n"	// patched
"				B	sub_FF8BE984 \n"	// continue in firmware
);
}
