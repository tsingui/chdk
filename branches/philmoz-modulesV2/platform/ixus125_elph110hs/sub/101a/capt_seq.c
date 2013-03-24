#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)(0xa60c+0x0c);  // Found @ ff199efc & ff199f18

#define PAUSE_FOR_FILE_COUNTER 250           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF068E64 

void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
      "STMFD   SP!, {R3-R9,LR} \n"
      "LDR     R4, =0x3E178 \n"
      "LDR     R7, =0x2E34 \n"
      "MOV     R6, #0 \n"
"loc_FF068E74:\n"
      "LDR     R0, [R7, #4] \n"
      "MOV     R2, #0 \n"
      "MOV     R1, SP \n"
      "BL      sub_0068BBE4 \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF068EA0 \n"
      "LDR     R1, =0x493 \n"
      "LDR     R0, =0xFF06894C \n" // SsShootTask.c
      "BL      _DebugAssert \n"
      "BL      _ExitTask \n"
      "LDMFD   SP!, {R3-R9,PC} \n"
"loc_FF068EA0:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x23 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF069154 \n" //Jump Table
      "B       loc_FF068F40 \n" //(01)
      "B       loc_FF068F58 \n" //(02)
      "B       loc_FF068FDC \n" //(03)
      "B       loc_FF068FF0 \n" //(04)
      "B       loc_FF068FE8 \n" //(05)
      "B       loc_FF068FFC \n" //(06)
      "B       loc_FF069004 \n" //(07)
      "B       loc_FF06900C \n" //(08)
      "B       loc_FF069028 \n" //(09)
      "B       loc_FF06907C \n" //(10)
      "B       loc_FF069034 \n" //(11)
      "B       loc_FF069040 \n" //(12)
      "B       loc_FF069048 \n" //(13)
      "B       loc_FF069064 \n" //(14)
      "B       loc_FF06906C \n" //(15)
      "B       loc_FF069074 \n" //(16)
      "B       loc_FF069084 \n" //(17)
      "B       loc_FF06908C \n" //(18)
      "B       loc_FF069094 \n" //(19)
      "B       loc_FF06909C \n" //(20)
      "B       loc_FF0690A4 \n" //(21)
      "B       loc_FF0690B0 \n" //(22)
      "B       loc_FF0690B8 \n" //(23)
      "B       loc_FF0690C0 \n" //(24)
      "B       loc_FF0690C8 \n" //(25)
      "B       loc_FF0690D0 \n" //(26)
      "B       loc_FF0690DC \n" //(27)
      "B       loc_FF0690E4 \n" //(28)
      "B       loc_FF0690EC \n" //(29)
      "B       loc_FF0690F4 \n" //(30)
      "B       loc_FF0690FC \n" //(31)
      "B       loc_FF069108 \n" //(32)
      "B       loc_FF069110 \n" //(33)
      "B       loc_FF06911C \n" //(34)
      "B       loc_FF069160 \n" //(35)
"loc_FF068F40:\n" // Jump table entry (01)
      "BL		shooting_expo_iso_override\n"  	// added
      "BL      sub_FF069734 \n"
      "BL      shooting_expo_param_override\n"      // added
      "BL      sub_FF06620C \n"
//patch begin
//      "LDR     R0, [R4, #0x28] \n"
//      "CMP     R0, #0 \n"
//      "BLNE    sub_FF19AC38 \n"
      "MOV     R0, #0\n"
      "STR     R0, [R4,#0x28]\n"          //fixes overrides  behavior at short shutter press
//patch end
      "B       loc_FF069160 \n"
"loc_FF068F58:\n" // Jump table entry (02)
      "LDR     R5, [R0, #0x10] \n"
      "LDR     R0, [R4, #0x28] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF068FA0 \n"
      "LDR     R0, [R4, #0x8C] \n"
      "TST     R0, #0x30 \n"
      "BLNE    sub_FF06CC00 \n"
      "BL      sub_FF06C8DC \n"
      "MOV     R1, R5 \n"
      "BL      sub_FF06C934 \n"
      "LDR     R0, =0x10F \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R5, #0x40 \n"
      "BL      _SetPropertyCase \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R5, #0x44 \n"
      "MOV     R0, #0x2C \n"
      "BL      _SetPropertyCase \n"
"loc_FF068FA0:\n"
      "MOV     R0, R5 \n"
//      "BL      sub_FF19AA2C \n"  //original
      "BL      sub_FF19AA2C_my \n" //patched
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R8, R0 \n"
      "MOV     R2, R5 \n"
      "MOV     R1, #1 \n"
      "BL      sub_FF066D54 \n"
      "TST     R8, #1 \n"
      "BNE     loc_FF069160 \n"
      "MOV     R0, R5 \n"
      "BL      sub_FF199A34 \n"
      "LDR     R0, [R4, #0x8C] \n"
      "TST     R0, #2 \n"
      "MOVNE   R0, R5 \n"
      "BLNE    sub_FF066EF4 \n"
      "B       loc_FF069160 \n"
"loc_FF068FDC:\n" //Jump table entry (03)
      "MOV     R0, #1 \n"
      "BL      sub_FF069A3C \n"
      "B       loc_FF069160 \n"
"loc_FF068FE8:\n" //Jump table entry (05)
      "BL      sub_FF069334 \n"
      "B       loc_FF068FF4 \n"
"loc_FF068FF0:\n" //Jump table entry (04)
      "BL      sub_FF069714 \n"
"loc_FF068FF4:\n"
      "STR     R6, [R4, #0x28] \n"
      "B       loc_FF069160 \n"
"loc_FF068FFC:\n" //Jump table entry (06)
      "BL      sub_FF06971C \n"
      "B       loc_FF069160 \n"
"loc_FF069004:\n" //Jump table entry (07)
      "BL      sub_FF069910 \n"
      "B       loc_FF06902C \n"
"loc_FF06900C:\n" //Jump table entry (08)
      "LDR     R5, [R0, #0x10] \n"
      "MOV     R0, R5 \n"
      "BL      sub_FF19ACD0 \n"
      "MOV     R2, R5 \n"
      "MOV     R1, #9 \n"
      "BL      sub_FF066D54 \n"
      "B       loc_FF069160 \n"
"loc_FF069028:\n" //Jump table entry (09)
      "BL      sub_FF0699A0 \n"
"loc_FF06902C:\n"
      "BL      sub_FF06620C \n"
      "B       loc_FF069160 \n"
"loc_FF069034:\n"
      "LDR     R0, [R4, #0x58] \n"
      "BL      sub_FF06A0C0 \n"
      "B       loc_FF069160 \n"
"loc_FF069040:\n"
      "BL      sub_FF06A3B8 \n"
      "B       loc_FF069160 \n"
"loc_FF069048:\n"
      "LDRH    R1, [R4] \n"
      "SUB     R0, R1, #0x8200 \n"
      "SUBS    R0, R0, #0x39 \n"
      "MOVNE   R0, #0 \n"
      "MOVEQ   R0, #1 \n"
      "BL      sub_FF06A41C \n"
      "B       loc_FF069160 \n"
"loc_FF069064:\n"
      "BL      sub_FF06A610 \n"
      "B       loc_FF069160 \n"
"loc_FF06906C:\n"
      "BL      sub_FF06AA8C \n"
      "B       loc_FF069160 \n"
"loc_FF069074:\n"
      "BL      sub_FF06AB40 \n"
      "B       loc_FF069160 \n"
"loc_FF06907C:\n"
      "BL      sub_FF069714 \n"
      "B       loc_FF069160 \n"
"loc_FF069084:\n"
      "BL      sub_FF198CB0 \n"
      "B       loc_FF069160 \n"
"loc_FF06908C:\n"
      "BL      sub_FF198F18 \n"
      "B       loc_FF069160 \n"
"loc_FF069094:\n"
      "BL      sub_FF198FD0 \n"
      "B       loc_FF069160 \n"
"loc_FF06909C:\n"
      "BL      sub_FF1990A4 \n"
      "B       loc_FF069160 \n"
"loc_FF0690A4:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF199358 \n"
      "B       loc_FF069160 \n"
"loc_FF0690B0:\n"
      "BL      sub_FF1994C8 \n"
      "B       loc_FF069160 \n"
"loc_FF0690B8:\n"
      "BL      sub_FF19955C \n"
      "B       loc_FF069160 \n"
"loc_FF0690C0:\n"
      "BL      sub_FF199618 \n"
      "B       loc_FF069160 \n"
"loc_FF0690C8:\n"
      "BL      sub_FF069BF4 \n"
      "B       loc_FF069160 \n"
"loc_FF0690D0:\n"
      "BL      sub_FF069C88 \n"
      "BL      sub_FF021F1C \n"
      "B       loc_FF069160 \n"
"loc_FF0690DC:\n"
      "BL      sub_FF199174 \n"
      "B       loc_FF069160 \n"
"loc_FF0690E4:\n"
      "BL      sub_FF1991DC \n"
      "B       loc_FF069160 \n"
"loc_FF0690EC:\n"
      "BL      sub_FF06DE74 \n"
      "B       loc_FF069160 \n"
"loc_FF0690F4:\n"
      "BL      sub_FF06DEFC \n"
      "B       loc_FF069160 \n"
"loc_FF0690FC:\n"
      "LDR     R0, [R0, #0xC] \n"
      "BL      sub_FF199740 \n"
      "B       loc_FF069160 \n"
"loc_FF069108:\n"
      "BL      sub_FF1997B0 \n"
      "B       loc_FF069160 \n"
"loc_FF069110:\n"
      "BL      sub_FF06DF64 \n"
      "BL      sub_FF06DF1C \n"
      "B       loc_FF069160 \n"
"loc_FF06911C:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF19B480 \n"
      "MOV     R0, #1 \n"
      "BL      sub_FF19B5B4 \n"
      "LDRH    R0, [R4, #0x9C] \n"
      "CMP     R0, #4 \n"
      "LDRNEH  R0, [R4] \n"
      "SUBNE   R1, R0, #0x8200 \n"
      "SUBNES  R1, R1, #0x2E \n"
      "BNE     loc_FF069160 \n"
      "BL      sub_FF06DEFC \n"
      "BL      sub_FF06E65C \n"
      "BL      sub_FF06E38C \n"
      "B       loc_FF069160 \n"
"loc_FF069154:\n"
      "LDR     R1, =0x5F4 \n"
      "LDR     R0, =0xFF06894C \n" // SsShootTask.c
      "BL      _DebugAssert \n"
"loc_FF069160:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0, #4] \n"
      "LDR     R0, [R7] \n"
      "BL      sub_0068B954 \n" //RAM
      "LDR     R5, [SP] \n"
      "LDR     R0, [R5, #8] \n"
      "CMP     R0, #0 \n"
      "LDREQ   R1, =0x117 \n"
      "LDREQ   R0, =0xFF06894C \n" // SsShootTask.c
      "BLEQ    _DebugAssert \n"
      "STR     R6, [R5, #8] \n"
      "B       loc_FF068E74 \n"
	);
}


//** sub_FF19AA2C_my  @ 0xFF19AA2C

void __attribute__((naked,noinline)) sub_FF19AA2C_my() {
asm volatile (
      "STMFD   SP!, {R3-R7,LR} \n"
      "LDR     R6, =0x3E178 \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R6, #0x28] \n"
      "LDR     R5, =0x820D \n"
      "CMP     R0, #0 \n"
      "MOV     R7, #0 \n"
      "BNE     loc_FF19AAD0 \n"
      "LDR     R1, [R6, #0x8C] \n"
      "TST     R1, #6 \n"
      "BNE     loc_FF19AA6C \n"
      "MOV     R0, #0xC \n"
      "BL      sub_FF06FD24 \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF19AAD0 \n"
      "B       loc_FF19AAC8 \n"
"loc_FF19AA6C:\n"
      "LDRH    R0, [R6] \n"
      "CMP     R0, R5 \n"
      "LDRNEH  R0, [R6, #0x9A] \n"
      "CMPNE   R0, #3 \n"
      "LDRNE   R0, [R4, #8] \n"
      "CMPNE   R0, #1 \n"
      "BLS     loc_FF19AAB0 \n"
      "LDRH    R0, [R6, #0x96] \n"
      "CMP     R0, #3 \n"
      "BNE     loc_FF19AA9C \n"
      "TST     R1, #2 \n"
      "BNE     loc_FF19AAD0 \n"
"loc_FF19AA9C:\n"
      "BL      sub_FF01CDB0 \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF19AAD0 \n"
      "BL      sub_FF06FD8C \n"
      "B       loc_FF19AAC8 \n"
"loc_FF19AAB0:\n"
      "MOV     R0, #0xC \n"
      "BL      sub_FF06FD24 \n"
      "TST     R0, #1 \n"
      "BEQ     loc_FF19AAD0 \n"
      "BL      sub_FF19B300 \n"
      "BL      sub_FF0669C0 \n"
"loc_FF19AAC8:\n"
      "MOV     R0, #1 \n"
      "LDMFD   SP!, {R3-R7,PC} \n"
"loc_FF19AAD0:\n"
      "BL      sub_FF069724 \n"
      "LDR     R0, [R6, #0x28] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF19AC20 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF199970 \n"
      "TST     R0, #1 \n"
      "LDMNEFD SP!, {R3-R7,PC} \n"
      "LDR     R0, [R6, #0x8C] \n"
      "AND     R0, R0, #0x40 \n"
      "CMP     R0, #0 \n"
      "LDRNEH  R0, [R6] \n"
      "CMPNE   R0, R5 \n"
      "LDRNEH  R0, [R6, #0x9A] \n"
      "CMPNE   R0, #3 \n"
      "LDRNE   R0, [R4, #8] \n"
      "CMPNE   R0, #1 \n"
      "BLS     loc_FF19AB34 \n"
      "BL      sub_FF19B774 \n"
      "MOV     R3, #0xC0 \n"
      "STR     R3, [SP] \n"
      "LDR     R2, =0x3A98 \n"
      "LDR     R3, =0xFF19AD60 \n" //SsCaptureSeq.c
      "MOV     R1, #0x8000 \n"
      "BL      sub_FF06FF9C \n"
"loc_FF19AB34:\n"
      "LDR     R0, [R6, #0x8C] \n"
      "AND     R0, R0, #6 \n"
      "CMP     R0, #0 \n"
      "LDRNEH  R0, [R6] \n"
      "CMPNE   R0, R5 \n"
      "LDRNEH  R0, [R6, #0x9A] \n"
      "CMPNE   R0, #3 \n"
      "LDRNE   R0, [R4, #8] \n"
      "CMPNE   R0, #1 \n"
      "BHI     loc_FF19AB68 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF199D8C \n"
      "BL      sub_FF19B244 \n"

      "BL      wait_until_remote_button_is_released \n"  //before shoot XXX
      "BL      capt_seq_hook_set_nr \n"

"loc_FF19AB68:\n"
      "LDR     R0, [R6, #0x8C] \n"
      "TST     R0, #0x40 \n"
      "BEQ     loc_FF19ABD0 \n"
      "LDR     R0, =0x181 \n"
      "MOV     R2, #4 \n"
      "MOV     R1, SP \n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1 \n"
      "MOVNE   R1, #0xD4 \n"
      "LDRNE   R0, =0xFF19AD60 \n" //SsCaptureSeq.c
      "BLNE    _DebugAssert \n"
      "LDR     R0, [SP] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF19ABB0 \n"
      "BL      sub_FF19B774 \n"
      "MOV     R1, #0x8000 \n"
      "BL      sub_0068B954 \n"
      "B       loc_FF19ABD0 \n"
"loc_FF19ABB0:\n"
      "BL      sub_FF19B774 \n"
      "MOV     R1, #0x8000 \n"
      "BL      sub_0068B988 \n"
      "LDR     R2, =0xFF19AA18 \n"
      "LDR     R0, [SP] \n"
      "MOV     R3, #0x8000 \n"
      "ADD     R1, R2, #0 \n"
      "BL      sub_FF024A10 \n"
"loc_FF19ABD0:\n"
      "LDR     R0, [R6, #0x8C] \n"
      "AND     R0, R0, #6 \n"
      "CMP     R0, #0 \n"
      "LDRNEH  R0, [R6] \n"
      "CMPNE   R0, R5 \n"
      "LDRNEH  R0, [R6, #0x9A] \n"
      "CMPNE   R0, #3 \n"
      "LDRNE   R0, [R4, #8] \n"
      "CMPNE   R0, #1 \n"
      "MOVLS   R0, #2 \n"
      "BLLS    sub_FF0714EC \n"
      "LDR     R0, [R6, #0x8C] \n"
      "TST     R0, #0x10 \n"
      "MOV     R0, R4 \n"
      "BEQ     loc_FF19AC14 \n"
      "BL      sub_FF320AD0 \n"
      "B       loc_FF19AC18 \n"
"loc_FF19AC14:\n"
      "BL      sub_FF19A4C8 \n"
"loc_FF19AC18:\n"
      "MOV     R7, R0 \n"
      "B       loc_FF19AC30 \n"
"loc_FF19AC20:\n"
      "LDR     R0, =0xA628 \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0 \n"
      "MOVNE   R7, #0x1D \n"
"loc_FF19AC30:\n"
      "MOV     R0, R7 \n"
      "LDMFD   SP!, {R3-R7,PC} \n"
	);
}

//** exp_drv_task  @ 0xFF0B2AA8 

void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
      "STMFD   SP!, {R4-R9,LR} \n"
      "SUB     SP, SP, #0x2C \n"
      "LDR     R6, =0x4298 \n"
      "LDR     R7, =0xBB8 \n"
      "LDR     R4, =0x5B198 \n"
      "MOV     R0, #0 \n"
      "ADD     R5, SP, #0x1C \n"
      "STR     R0, [SP, #0xC] \n"
"loc_FF0B2AC8:\n"
      "LDR     R0, [R6, #0x20] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #0x28 \n"
      "BL      sub_0068BBE4 \n" //RAM
      "LDR     R0, [SP, #0xC] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF0B2B14 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0x14 \n"
      "CMPNE   R0, #0x15 \n"
      "CMPNE   R0, #0x16 \n"
      "CMPNE   R0, #0x17 \n"
      "BEQ     loc_FF0B2C74 \n"
      "CMP     R0, #0x2A \n"
      "BEQ     loc_FF0B2BFC \n"
      "ADD     R1, SP, #0xC \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF0B2A58 \n"
"loc_FF0B2B14:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x30 \n"
      "BNE     loc_FF0B2B40 \n"
      "BL      sub_FF0B3EA8 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #1 \n"
      "BL      sub_0068B954 \n"
      "BL      _ExitTask \n"
      "ADD     SP, SP, #0x2C \n"
      "LDMFD   SP!, {R4-R9,PC} \n"
"loc_FF0B2B40:\n"
      "CMP     R1, #0x2F \n"
      "BNE     loc_FF0B2B5C \n"
      "LDR     R2, [R0, #0x8C]! \n"
      "LDR     R1, [R0, #4] \n"
      "MOV     R0, R1 \n"
      "BLX     R2 \n"
      "B       loc_FF0B3130 \n"
"loc_FF0B2B5C:\n"
      "CMP     R1, #0x28 \n"
      "BNE     loc_FF0B2BAC \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_0068B988 \n" //RAM
      "LDR     R0, =0xFF0AD978 \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_FF189ADC \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #0x80 \n"
      "BL      sub_0068B894 \n" //RAM
      "TST     R0, #1 \n"
      "LDRNE   R1, =0x1582 \n"
      "BNE     loc_FF0B2C68 \n"
"loc_FF0B2B98:\n"
      "LDR     R1, [SP, #0x28] \n"
      "LDR     R0, [R1, #0x90] \n"
      "LDR     R1, [R1, #0x8C] \n"
      "BLX     R1 \n"
      "B       loc_FF0B3130 \n"
"loc_FF0B2BAC:\n"
      "CMP     R1, #0x29 \n"
      "BNE     loc_FF0B2BF4 \n"
      "ADD     R1, SP, #0xC \n"
      "BL      sub_FF0B2A58 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_0068B988 \n" //RAM
      "LDR     R0, =0xFF0AD988 \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_FF189C7C \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #0x100 \n"
      "BL      sub_0068B894 \n" //RAM
      "TST     R0, #1 \n"
      "BEQ     loc_FF0B2B98 \n"
      "LDR     R1, =0x158C \n"
      "B       loc_FF0B2C68 \n"
"loc_FF0B2BF4:\n"
      "CMP     R1, #0x2A \n"
      "BNE     loc_FF0B2C0C \n"
"loc_FF0B2BFC:\n"
      "LDR     R0, [SP, #0x28] \n"
      "ADD     R1, SP, #0xC \n"
      "BL      sub_FF0B2A58 \n"
      "B       loc_FF0B2B98 \n"
"loc_FF0B2C0C:\n"
      "CMP     R1, #0x2D \n"
      "BNE     loc_FF0B2C24 \n"
      "BL      sub_FF09DAE8 \n"
      "BL      sub_FF09E7D4 \n"
      "BL      sub_FF09E33C \n"
      "B       loc_FF0B2B98 \n"
"loc_FF0B2C24:\n"
      "CMP     R1, #0x2E \n"
      "BNE     loc_FF0B2C74 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R1, #4 \n"
      "BL      sub_0068B988 \n" //RAM
      "LDR     R1, =0xFF0AD9A8 \n"
      "LDR     R0, =0xFFFFF400 \n"
      "MOV     R2, #4 \n"
      "BL      sub_FF09D538 \n"
      "BL      sub_FF09D7C8 \n"
      "LDR     R0, [R6, #0x1C] \n"
      "MOV     R2, R7 \n"
      "MOV     R1, #4 \n"
      "BL      sub_0068B7B0 \n" //RAM
      "TST     R0, #1 \n"
      "BEQ     loc_FF0B2B98 \n"
      "LDR     R1, =0x15B4 \n"
"loc_FF0B2C68:\n"
      "LDR     R0, =0xFF0AE188 \n"
      "BL      _DebugAssert \n"
      "B       loc_FF0B2B98 \n"
"loc_FF0B2C74:\n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R8, #1 \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x12 \n"
      "CMPNE   R1, #0x13 \n"
      "BNE     loc_FF0B2CDC \n"
      "LDR     R1, [R0, #0x7C] \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R1, R0, R1, LSL #2 \n"
      "SUB     R1, R1, #8 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "BL      sub_FF0B0C18 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R3, [R0, #0x8C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF0B42C8 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R2, [R0, #0x98] \n"
      "LDR     R3, [R0, #0x94] \n"
      "B       loc_FF0B2FF4 \n"
"loc_FF0B2CDC:\n"
      "CMP     R1, #0x14 \n"
      "CMPNE   R1, #0x15 \n"
      "CMPNE   R1, #0x16 \n"
      "CMPNE   R1, #0x17 \n"
      "BNE     loc_FF0B2D94 \n"
      "ADD     R3, SP, #0xC \n"
      "MOV     R2, SP \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_FF0B0E78 \n"
      "CMP     R0, #1 \n"
      "MOV     R9, R0 \n"
      "CMPNE   R9, #5 \n"
      "BNE     loc_FF0B2D30 \n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R2, R9 \n"
      "LDR     R1, [R0, #0x7C]! \n"
      "LDR     R12, [R0, #0x10]! \n"
      "LDR     R3, [R0, #4] \n"
      "MOV     R0, SP \n"
      "BLX     R12 \n"
      "B       loc_FF0B2D68 \n"
"loc_FF0B2D30:\n"
      "LDR     R0, [SP, #0x28] \n"
      "CMP     R9, #2 \n"
      "LDR     R3, [R0, #0x90] \n"
      "CMPNE   R9, #6 \n"
      "BNE     loc_FF0B2D7C \n"
      "LDR     R12, [R0, #0x8C] \n"
      "MOV     R2, R9 \n"
      "MOV     R1, #1 \n"
      "MOV     R0, SP \n"
      "BLX     R12 \n"
      "LDR     R0, [SP, #0x28] \n"
      "MOV     R2, SP \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_FF0B2730 \n"
"loc_FF0B2D68:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R2, [SP, #0xC] \n"
      "MOV     R1, R9 \n"
      "BL      sub_FF0B29F8 \n"
      "B       loc_FF0B2FFC \n"
"loc_FF0B2D7C:\n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R12, [R0, #0x8C] \n"
      "MOV     R2, R9 \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R12 \n"
      "B       loc_FF0B2FFC \n"
"loc_FF0B2D94:\n"
      "CMP     R1, #0x24 \n"
      "CMPNE   R1, #0x25 \n"
      "BNE     loc_FF0B2DE0 \n"
      "LDR     R1, [R0, #0x7C] \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R1, R0, R1, LSL #2 \n"
      "SUB     R1, R1, #8 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "BL      sub_FF0AF994 \n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R3, [R0, #0x8C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF0AFE68 \n"
      "B       loc_FF0B2FFC \n"
"loc_FF0B2DE0:\n"
      "ADD     R1, R0, #4 \n"
      "LDMIA   R1, {R2,R3,R9} \n"
      "STMIA   R5, {R2,R3,R9} \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x28 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2E9C \n"
      "B       loc_FF0B2E9C \n"
      "B       loc_FF0B2EA4 \n"
      "B       loc_FF0B2EAC \n"
      "B       loc_FF0B2EAC \n"
      "B       loc_FF0B2EAC \n"
      "B       loc_FF0B2E9C \n"
      "B       loc_FF0B2EA4 \n"
      "B       loc_FF0B2EAC \n"
      "B       loc_FF0B2EAC \n"
      "B       loc_FF0B2EC4 \n"
      "B       loc_FF0B2EC4 \n"
      "B       loc_FF0B2FD0 \n"
      "B       loc_FF0B2FD8 \n"
      "B       loc_FF0B2FD8 \n"
      "B       loc_FF0B2FD8 \n"
      "B       loc_FF0B2FD8 \n"
      "B       loc_FF0B2FE0 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2EB4 \n"
      "B       loc_FF0B2EBC \n"
      "B       loc_FF0B2EBC \n"
      "B       loc_FF0B2EBC \n"
      "B       loc_FF0B2ED0 \n"
      "B       loc_FF0B2ED0 \n"
      "B       loc_FF0B2ED8 \n"
      "B       loc_FF0B2F10 \n"
      "B       loc_FF0B2F48 \n"
      "B       loc_FF0B2F80 \n"
      "B       loc_FF0B2FB8 \n"
      "B       loc_FF0B2FB8 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FE4 \n"
      "B       loc_FF0B2FC0 \n"
      "B       loc_FF0B2FC8 \n"
"loc_FF0B2E9C:\n"
      "BL      sub_FF0ADFBC \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2EA4:\n"
      "BL      sub_FF0AE2B4 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2EAC:\n"
      "BL      sub_FF0AE51C \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2EB4:\n"
      "BL      sub_FF0AE810 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2EBC:\n"
      "BL      sub_FF0AEA28 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2EC4:\n"
//      "BL      sub_FF0AEF18 \n" //original
      "BL      sub_FF0AEF18_my \n" //patched
      "MOV     R8, #0 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2ED0:\n"
      "BL      sub_FF0AF0F8 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2ED8:\n"
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
      "BL      sub_FF0B3F3C \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2F10:\n"
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
      "BL      sub_FF0B40C8 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2F48:\n"
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
      "BL      sub_FF0B417C \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2F80:\n"
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
      "BL      sub_FF0B4224 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2FB8:\n"
      "BL      sub_FF0AF748 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2FC0:\n"
      "BL      sub_FF0AFF6C \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2FC8:\n"
      "BL      sub_FF0B04C8 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2FD0:\n"
      "BL      sub_FF0B06EC \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2FD8:\n"
      "BL      sub_FF0B08A8 \n"
      "B       loc_FF0B2FE4 \n"
"loc_FF0B2FE0:\n"
      "BL      sub_FF0B0A10 \n"
"loc_FF0B2FE4:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R1, [R0, #0x7C] \n"
      "LDR     R2, [R0, #0x90] \n"
      "LDR     R3, [R0, #0x8C] \n"
"loc_FF0B2FF4:\n"
      "ADD     R0, R0, #4 \n"
      "BLX     R3 \n"
"loc_FF0B2FFC:\n"
      "LDR     R0, [SP, #0x28] \n"
      "LDR     R0, [R0] \n"
      "CMP     R0, #0x10 \n"
      "BEQ     loc_FF0B3034 \n"
      "BGT     loc_FF0B3024 \n"
      "CMP     R0, #1 \n"
      "CMPNE   R0, #4 \n"
      "CMPNE   R0, #0xE \n"
      "BNE     loc_FF0B3068 \n"
      "B       loc_FF0B3034 \n"
"loc_FF0B3024:\n"
      "CMP     R0, #0x13 \n"
      "CMPNE   R0, #0x17 \n"
      "CMPNE   R0, #0x1A \n"
      "BNE     loc_FF0B3068 \n"
"loc_FF0B3034:\n"
      "LDRSH   R0, [R4] \n"
      "CMN     R0, #0xC00 \n"
      "LDRNESH R1, [R4, #8] \n"
      "CMNNE   R1, #0xC00 \n"
      "STRNEH  R0, [SP, #0x1C] \n"
      "STRNEH  R1, [SP, #0x24] \n"
      "BNE     loc_FF0B3068 \n"
      "ADD     R0, SP, #0x10 \n"
      "BL      sub_FF0B44D4 \n"
      "LDRH    R0, [SP, #0x10] \n"
      "STRH    R0, [SP, #0x1C] \n"
      "LDRH    R0, [SP, #0x18] \n"
      "STRH    R0, [SP, #0x24] \n"
"loc_FF0B3068:\n"
      "LDR     R0, [SP, #0x28] \n"
      "CMP     R8, #1 \n"
      "BNE     loc_FF0B30B8 \n"
      "LDR     R1, [R0, #0x7C] \n"
      "MOV     R2, #0xC \n"
      "ADD     R1, R1, R1, LSL #1 \n"
      "ADD     R0, R0, R1, LSL #2 \n"
      "SUB     R8, R0, #8 \n"
      "LDR     R0, =0x5B198 \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_0069017C \n" //RAM
      "LDR     R0, =0x5B1A4 \n"
      "MOV     R2, #0xC \n"
      "ADD     R1, SP, #0x1C \n"
      "BL      sub_0069017C \n" //RAM
      "LDR     R0, =0x5B1B0 \n"
      "MOV     R2, #0xC \n"
      "MOV     R1, R8 \n"
      "BL      sub_0069017C \n"
      "B       loc_FF0B3130 \n"
"loc_FF0B30B8:\n"
      "LDR     R0, [R0] \n"
      "MOV     R3, #1 \n"
      "CMP     R0, #0xB \n"
      "BNE     loc_FF0B30FC \n"
      "MOV     R2, #0 \n"
      "STRD    R2, [SP] \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF0ADD9C \n"
      "MOV     R3, #1 \n"
      "MOV     R2, #0 \n"
      "STRD    R2, [SP] \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, #0 \n"
      "B       loc_FF0B312C \n"
"loc_FF0B30FC:\n"
      "MOV     R2, #1 \n"
      "STRD    R2, [SP] \n"
      "MOV     R3, R2 \n"
      "MOV     R1, R2 \n"
      "MOV     R0, R2 \n"
      "BL      sub_FF0ADD9C \n"
      "MOV     R3, #1 \n"
      "MOV     R2, R3 \n"
      "MOV     R1, R3 \n"
      "MOV     R0, R3 \n"
      "STR     R3, [SP] \n"
      "STR     R3, [SP, #4] \n"
"loc_FF0B312C:\n"
      "BL      sub_FF0ADF08 \n"
"loc_FF0B3130:\n"
      "LDR     R0, [SP, #0x28] \n"
      "BL      sub_FF0B3EA8 \n"
      "B       loc_FF0B2AC8 \n"
	);
}

//** sub_FF0AEF18_my  @ 0xFF0AEF18 

void __attribute__((naked,noinline)) sub_FF0AEF18_my() {
asm volatile (
      "STMFD   SP!, {R4-R8,LR} \n"
      "LDR     R7, =0x4298 \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R7, #0x1C] \n"
      "MOV     R1, #0x3E \n"
      "BL      sub_0068B988 \n" //RAM
      "MOV     R2, #0 \n"
      "LDRSH   R0, [R4, #4] \n"
      "MOV     R1, R2 \n"
      "BL      sub_FF0ADA08 \n"
      "MOV     R6, R0 \n"
      "LDRSH   R0, [R4, #6] \n"
      "BL      sub_FF0ADBAC \n"
      "LDRSH   R0, [R4, #8] \n"
      "BL      sub_FF0ADC04 \n"
      "LDRSH   R0, [R4, #0xA] \n"
      "BL      sub_FF0ADC5C \n"
      "LDRSH   R0, [R4, #0xC] \n"
      "MOV     R1, #0 \n"
      "BL      sub_FF0ADCB4 \n"
      "MOV     R5, R0 \n"
      "LDR     R0, [R4] \n"
      "LDR     R8, =0x5B1B0 \n"
      "CMP     R0, #0xB \n"
      "MOVEQ   R6, #0 \n"
      "MOVEQ   R5, R6 \n"
      "BEQ     loc_FF0AEFAC \n"
      "CMP     R6, #1 \n"
      "BNE     loc_FF0AEFAC \n"
      "LDRSH   R0, [R4, #4] \n"
      "LDR     R1, =0xFF0AD968 \n"
      "MOV     R2, #2 \n"
      "BL      sub_FF189B60 \n"
      "STRH    R0, [R4, #4] \n"
      "MOV     R0, #0 \n"
      "STR     R0, [R7, #0x28] \n"
      "B       loc_FF0AEFB4 \n"
"loc_FF0AEFAC:\n"
      "LDRH    R0, [R8] \n"
      "STRH    R0, [R4, #4] \n"
"loc_FF0AEFB4:\n"
      "CMP     R5, #1 \n"
      "LDRNEH  R0, [R8, #8] \n"
      "BNE     loc_FF0AEFD0 \n"
      "LDRSH   R0, [R4, #0xC] \n"
      "LDR     R1, =0xFF0AD9EC \n"
      "MOV     R2, #0x20 \n"
      "BL      sub_FF0B3EF8 \n"
"loc_FF0AEFD0:\n"
      "STRH    R0, [R4, #0xC] \n"
      "LDRSH   R0, [R4, #6] \n"
//      "BL      sub_FF09D834 \n" //original
      "BL      sub_FF09D834_my \n" //patched
      "B       sub_FF0AEFDC \n" // continue in firmware
	);
}

//** sub_FF09D834_my  @ 0xFF09D834 

void __attribute__((naked,noinline)) sub_FF09D834_my() {
asm volatile (
      "STMFD   SP!, {R4-R6,LR} \n"
      "LDR     R5, =0x3EE8 \n"
      "MOV     R4, R0 \n"
      "LDR     R0, [R5, #4] \n"
      "CMP     R0, #1 \n"
      "LDRNE   R1, =0x14D \n"
      "LDRNE   R0, =0xFF09D66C \n" //  ; "Shutter.c"
      "BLNE    _DebugAssert \n"
      "CMN     R4, #0xC00 \n"
      "LDREQSH R4, [R5, #2] \n"
      "CMN     R4, #0xC00 \n"
      "LDREQ   R1, =0x153 \n"
      "LDREQ   R0, =0xFF09D66C \n" //  ; "Shutter.c"
      "STRH    R4, [R5, #2] \n"
      "BLEQ    _DebugAssert \n"
      "MOV     R0, R4 \n"
//      "BL      _apex2us \n" //original _apex2us
      "BL      apex2us \n"  //patch
      "MOV     R4, R0 \n"
      "BL      sub_FF0F83F4 \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF1018BC \n"
      "TST     R0, #1 \n"
      "LDMEQFD SP!, {R4-R6,PC} \n"
      "LDMFD   SP!, {R4-R6,LR} \n"
      "MOV     R1, #0x158 \n"
      "LDR     R0, =0xFF09D66C \n"
      "B       _DebugAssert \n"
	);
}
