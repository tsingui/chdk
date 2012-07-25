#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void __attribute__((naked,noinline)) movie_record_task(){

asm volatile (
                "STMFD  SP!, {R2-R10,LR}\n"
                "LDR    R6, =0xFF18C57C\n"
                "LDR    R7, =sub_FF18D218_my\n"
                "LDR    R4, =0x85E0\n"
                "LDR    R9, =0x67F\n"
                "LDR    R10, =0x2710\n"
                "MOV    R8, #1\n"
                "MOV    R5, #0\n"
"loc_FF18D7E0:\n"
                "LDR    R0, [R4, #0x24]\n"
                "MOV    R2, #0\n"
                "ADD    R1, SP, #4\n"
                "BL     sub_FF02B17C\n"
                "LDR    R0, [R4, #0x2C]\n"
                "CMP    R0, #0\n"
                "LDRNE  R0, [R4, #0xC]\n"
                "CMPNE  R0, #2\n"
                "LDRNE  R0, [R4, #0x44]\n"
                "CMPNE  R0, #6\n"
                "BNE    loc_FF18D91C\n"
                "LDR    R0, [SP, #4]\n"
                "LDR    R1, [R0]\n"
                "SUB    R1, R1, #2\n"
                "CMP    R1, #0xD\n"
                "ADDCC  PC, PC, R1, LSL #2\n"
                "B      loc_FF18D91C\n"
"loc_FF18D824:\n"
                "B      loc_FF18D8BC\n"
"loc_FF18D828:\n"
                "B      loc_FF18D8E0\n"
"loc_FF18D82C:\n"
                "B      loc_FF18D8F0\n"
"loc_FF18D830:\n"
                "B      loc_FF18D8F8\n"
"loc_FF18D834:\n"
                "B      loc_FF18D900\n"
"loc_FF18D838:\n"
                "B      loc_FF18D908\n"
"loc_FF18D83C:\n"
                "B      loc_FF18D8C4\n"
"loc_FF18D840:\n"
                "B      loc_FF18D910\n"
"loc_FF18D844:\n"
                "B      loc_FF18D8D0\n"
"loc_FF18D848:\n"
                "B      loc_FF18D91C\n"
"loc_FF18D84C:\n"
                "B      loc_FF18D918\n"
"loc_FF18D850:\n"
                "B      loc_FF18D888\n"
"loc_FF18D854:\n"
                "B      loc_FF18D858\n"
"loc_FF18D858:\n"
                "STR    R5, [R4, #0x40]\n"
                "STR    R5, [R4, #0x30]\n"
                "STR    R5, [R4, #0x34]\n"
                "STRH   R5, [R4, #6]\n"
                "STR    R6, [R4, #0xD8]\n"
                "STR    R7, [R4, #0xF0]\n"
                "LDR    R0, [R4, #0xC]\n"
                "ADD    R0, R0, #1\n"
                "STR    R0, [R4, #0xC]\n"
                "MOV    R0, #6\n"
                "STR    R0, [R4, #0x44]\n"
                "B      loc_FF18D8A8\n"
"loc_FF18D888:\n"
                "STR    R5, [R4, #0x40]\n"
                "STR    R5, [R4, #0x30]\n"
                "STR    R6, [R4, #0xD8]\n"
                "STR    R7, [R4, #0xF0]\n"
                "LDR    R0, [R4, #0xC]\n"
                "ADD    R0, R0, #1\n"
                "STR    R0, [R4, #0xC]\n"
                "STR    R8, [R4, #0x44]\n"
"loc_FF18D8A8:\n"
                "LDR    R2, =0xFF18BBB8\n"
//                "LDR    R2, =sub_FF18BBB8\n"
                "LDR    R1, =0xC6A08\n"
                "LDR    R0, =0xFF18BCCC\n"
                "BL     sub_FF0453CC\n"
                "B      loc_FF18D91C\n"
"loc_FF18D8BC:\n"
//              "BL     sub_FF18CE08_my\n"
                "BL     movie_time\n"
"label_A:\n"
                "B      loc_FF18D91C\n"
"loc_FF18D8C4:\n"
                "LDR    R1, [R4, #0xF0]\n"
                "BLX    R1\n"
                "B      loc_FF18D91C\n"
"loc_FF18D8D0:\n"
                "LDR    R1, [R0, #0x18]\n"
                "LDR    R0, [R0, #4]\n"
                "BL     sub_FF306C24\n"
                "B      loc_FF18D91C\n"
"loc_FF18D8E0:\n"
                "LDR    R0, [R4, #0x44]\n"
                "CMP    R0, #5\n"
                "STRNE  R8, [R4, #0x34]\n"
                "B      loc_FF18D91C\n"
"loc_FF18D8F0:\n"
                "BL     sub_FF18C258\n"
                "B      loc_FF18D91C\n"
"loc_FF18D8F8:\n"
                "BL     sub_FF18BF6C\n"
                "B      loc_FF18D91C\n"
"loc_FF18D900:\n"
                "BL     sub_FF18BD24\n"
                "B      loc_FF18D91C\n"
"loc_FF18D908:\n"
                "BL     sub_FF18B94C\n"
                "B      loc_FF18D91C\n"
"loc_FF18D910:\n"
                "BL     sub_FF18B8CC\n"
                "B      loc_FF18D91C\n"
"loc_FF18D918:\n"
                "BL     sub_FF18DE6C\n"
"loc_FF18D91C:\n"
                "LDR    R1, [SP, #4]\n"
                "LDR    R3, =0xFF18B630\n"
                "STR    R5, [R1]\n"
                "STR    R9, [SP]\n"
                "LDR    R0, [R4, #0x28]\n"
                "MOV    R2, R10\n"
                "BL     sub_FF02BAF4\n"
                "B      loc_FF18D7E0\n"
    );
}

void __attribute__((naked,noinline)) movie_time(){
if( (int)conf.ext_video_time == 1 )
{
asm volatile (
                "BL     sub_FF18CE08_my\n"
				"B		label_A\n"
			 );
}
else
{
asm volatile (
                "BL     sub_FF18CE08\n"
				"B		label_A\n"
			 );
}

}

void __attribute__((naked,noinline)) sub_FF18CE08_my(){

asm volatile (
                "STMFD  SP!, {R0-R8,LR}\n"
                "LDR    R6, =0x85E0\n"
                "MOV    R0, #0\n"
                "STR    R0, [R6, #0x34]\n"
                "STR    R0, [R6, #0x38]\n"
                "ADD    R0, R6, #0\n"
                "LDR    R0, [R0, #0x5C]\n"
                "LDRH   R1, [R6, #6]\n"
                "MOV    R3, #0x3E8\n"
                "MUL    R0, R3, R0\n"
                "CMP    R1, #0\n"
                "MOV    R2, #1\n"
                "BNE    loc_FF18CE4C\n"
                "LDR    R1, [R6, #0x90]\n"
                "CMP    R1, #0\n"
                "BNE    loc_FF18CE5C\n"
                "B      loc_FF18CE54\n"
"loc_FF18CE4C:\n"
                "CMP    R1, #3\n"
                "BNE    loc_FF18CE5C\n"
"loc_FF18CE54:\n"
                "STR    R2, [R6, #0x48]\n"
                "B      loc_FF18CE68\n"
"loc_FF18CE5C:\n"
                "MOV    R1, #0x3E8\n"
                "BL     sub_FF3B61A8\n"
                "STR    R0, [R6, #0x48]\n"
"loc_FF18CE68:\n"
                "LDR    R4, =0xC6A3C\n"
                "MOV    R7, #2\n"
                "LDR    R0, [R4, #8]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18CED0\n"
                "LDR    R0, [R6, #0x58]\n"
                "MOV    R1, #4\n"
                "CMP    R0, #0x18\n"
                "BEQ    loc_FF18D064\n"
                "BGT    loc_FF18CEAC\n"
                "CMP    R0, #0xA\n"
                "CMPNE  R0, #0xF\n"
                "STREQ  R7, [R4, #0x14]\n"
                "BEQ    loc_FF18CED0\n"
                "CMP    R0, #0x14\n"
                "BNE    loc_FF18CEC4\n"
                "B      loc_FF18D064\n"
"loc_FF18CEAC:\n"
                "CMP    R0, #0x1E\n"
                "BEQ    loc_FF18D064\n"
                "CMP    R0, #0x3C\n"
                "MOVEQ  R0, #8\n"
                "STREQ  R0, [R4, #0x14]\n"
                "BEQ    loc_FF18CED0\n"
"loc_FF18CEC4:\n"
                "LDR    R1, =0x777\n"
                "LDR    R0, =0xFF18B630\n"
                "BL     sub_FF00EC80\n"
"loc_FF18CED0:\n"
                "LDR    R2, =0x85E2\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #2\n"
                "MOV    R1, #0xAA\n"
                "BL     sub_FF08C390\n"
                "LDR    R2, =0x85E4\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #2\n"
                "MOV    R1, #0xA9\n"
                "BL     sub_FF08C390\n"
                "LDR    R2, =0x8630\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #4\n"
                "MOV    R1, #0xA2\n"
                "BL     sub_FF08C390\n"
                "LDR    R2, =0x8634\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #4\n"
                "MOV    R1, #0xA3\n"
                "BL     sub_FF08C390\n"
                "LDR    R0, [R6, #0x90]\n"
                "CMP    R0, #0\n"
                "LDRNE  R2, =0x86E0\n"
                "MOVNE  R1, #0\n"
                "MOVNE  R0, #0xD\n"
                "BLNE   sub_FF086824\n"
                "LDR    R0, [R6, #0x4C]\n"
                "LDR    R5, =0x86E0\n"
                "LDR    R8, =0xC6A24\n"
                "CMP    R0, #2\n"
                "CMPNE  R0, #3\n"
                "BNE    loc_FF18CFCC\n"
                "LDR    R0, [R6, #0x90]\n"
                "CMP    R0, #0\n"
                "LDRNE  R0, =0x443FC000\n"
                "STRNE  R0, [R5]\n"
                "BNE    loc_FF18CFCC\n"
                "LDR    R0, =0x460B8600\n"
                "LDR    R1, =0x10959E0\n"
                "STR    R0, [R5]\n"
                "STR    R1, [R5, #4]\n"
                "LDMIA  R8, {R1,R2}\n"
                "STR    R0, [R6, #0xA0]\n"
                "MUL    R1, R2, R1\n"
                "MOV    R2, #0\n"
                "MOV    R3, R1, LSL #1\n"
                "ADD    R1, R0, R3\n"
                "STR    R3, [R6, #0x9C]\n"
                "STR    R1, [R6, #0xA4]\n"
                "STMEA  SP, {R1-R3}\n"
                "MOV    R3, R2\n"
                "MOV    R2, #9\n"
                "MOV    R1, #5\n"
                "MOV    R0, #0x10\n"
                "BL     sub_FF2B0840\n"
                "LDR    R1, [R5]\n"
                "LDR    R0, [R6, #0x9C]\n"
                "ADD    R1, R1, R0, LSL #1\n"
                "STR    R1, [R5]\n"
                "LDR    R1, [R5, #4]\n"
                "RSB    R0, R0, #0\n"
                "ADD    R0, R1, R0, LSL #1\n"
                "STR    R0, [R5, #4]\n"
"loc_FF18CFCC:\n"
                "LDR    R3, =0xFF18CDD4\n"
                "LDMIA  R5, {R0,R1}\n"
                "STR    R3, [SP]\n"
                "LDR    R3, =0xC6A3C\n"
                "SUB    R2, R3, #0x18\n"
                "BL     sub_FF305594_my\n"
                "LDR    R3, [R6, #0xB8]\n"
                "STR    R3, [SP]\n"
                "LDR    R0, [R6, #0x90]\n"
                "LDRD   R2, [R6, #0xF8]\n"
                "BL     sub_FF3059A0\n"
                "LDR    R0, [R6, #0x64]\n"
                "LDR    R3, =0x8668\n"
                "AND    R1, R0, #0xFF\n"
                "LDR    R0, [R8]\n"
                "SUB    R2, R3, #4\n"
                "BL     sub_FF3032C0\n"
                "LDRH   R0, [R6, #6]\n"
                "CMP    R0, #2\n"
                "LDREQ  R0, =0xFF18CA98\n"
                "STREQ  R0, [R6, #0xF0]\n"
                "LDR    R0, [R6, #0x90]\n"
                "CMP    R0, #0\n"
                "LDREQ  R1, =0xFF18C6DC\n"
                "STREQ  R1, [R6, #0xF0]\n"
                "LDR    R2, [R6, #0xC]\n"
                "LDR    R1, =0xFF4144D0\n"
                "CMP    R2, #2\n"
                "BNE    loc_FF18D06C\n"
                "LDR    R0, [R6, #0x4C]\n"
                "ADD    R0, R1, R0, LSL #3\n"
                "LDR    R1, [R8, #0xC]\n"
                "LDR    R0, [R0, R1, LSL #2]\n"
                "BL     sub_FF2B6938\n"
                "LDR    R0, =0xFF18C658\n"
                "MOV    R1, #0\n"
                "BL     sub_FF2B6E4C\n"
                "B      loc_FF18D0A8\n"
"loc_FF18D064:\n"
                "STR    R1, [R4, #0x14]\n"
                "B      loc_FF18CED0\n"
"loc_FF18D06C:\n"
                "CMP    R0, #0\n"
                "BNE    loc_FF18D088\n"
                "LDR    R1, [R6, #0x98]\n"
                "MOV    R0, #5\n"
                "BL     sub_FF2B6E60\n"
                "BL     sub_FF2B6EF0\n"
                "B      loc_FF18D0A8\n"
"loc_FF18D088:\n"
                "LDR    R0, [R6, #0x4C]\n"
                "ADD    R0, R1, R0, LSL #3\n"
                "LDR    R1, [R8, #0xC]\n"
                "LDR    R0, [R0, R1, LSL #2]\n"
                "BL     sub_FF2B50D4\n"
                "LDR    R0, =0xFF18C658\n"
                "MOV    R1, #0\n"
                "BL     sub_FF2B581C\n"
"loc_FF18D0A8:\n"
                "LDR    R0, [R4, #8]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D0DC\n"
                "ADD    R0, SP, #0xC\n"
                "BL     sub_FF306AA0\n"
                "LDR    R1, [R4, #0xC]\n"
                "LDR    R0, [SP, #0xC]\n"
                "BL     sub_FF05D068\n"
                "ADD    R0, SP, #0xC\n"
                "BL     sub_FF306AA0\n"
                "LDR    R1, [R4, #0xC]\n"
                "LDR    R0, [SP, #0xC]\n"
                "BL     sub_FF05D068\n"
"loc_FF18D0DC:\n"
                "LDR    R0, =0xFF18C610\n"
                "STR    R7, [R6, #0x44]!\n"
                "STR    R0, [R6, #0x94]\n"
                "LDMFD  SP!, {R0-R8,PC}\n"
    );
}

void __attribute__((naked,noinline)) sub_FF305594_my(){

asm volatile (
                "STMFD  SP!, {R0-R12,LR}\n"
                "MOV    R8, R0\n"
                "LDR    R0, [R2, #0x10]\n"
                "LDR    R7, [SP, #0x38]\n"
                "CMP    R0, #0\n"
                "LDREQ  R1, =0x32A\n"
                "LDREQ  R0, =0xFF3041A8\n"
                "MOV    R5, #0\n"
                "MOV    R4, R2\n"
                "MOV    R9, R3\n"
                "MOV    R6, R5\n"
                "BLEQ   sub_FF00EC80\n"
                "LDR    R11, =0xDE88\n"
                "LDR    R0, [R4]\n"
                "MOV    R10, #0x1E\n"
                "STR    R0, [R11, #0xD0]\n"
                "LDR    R0, [R4, #4]\n"
                "STR    R0, [R11, #0xD4]\n"
                "LDR    R0, [R4, #0x10]\n"
                "STR    R0, [R11, #0xE0]\n"
                "LDR    R1, [R4, #8]\n"
                "LDR    R0, =0x7530\n"
                "CMP    R1, #0xB\n"
                "ADDCC  PC, PC, R1, LSL #2\n"
                "B      loc_FF305680\n"
"loc_FF3055F8:\n"
                "B      loc_FF305634\n"
"loc_FF3055FC:\n"
                "B      loc_FF305624\n"
"loc_FF305600:\n"
                "B      loc_FF30565C\n"
"loc_FF305604:\n"
                "B      loc_FF305670\n"
"loc_FF305608:\n"
                "B      loc_FF305680\n"
"loc_FF30560C:\n"
                "B      loc_FF305680\n"
"loc_FF305610:\n"
                "B      loc_FF305680\n"
"loc_FF305614:\n"
                "B      loc_FF305680\n"
"loc_FF305618:\n"
                "B      loc_FF305654\n"
"loc_FF30561C:\n"
                "B      loc_FF30564C\n"
"loc_FF305620:\n"
                "B      loc_FF30563C\n"
"loc_FF305624:\n"
                "LDR    R6, =0x5DC0\n"
                "MOV    R0, #0x18\n"
                "STR    R6, [R11, #0x12C]\n"
                "B      loc_FF305668\n"
"loc_FF305634:\n"
                "MOV    R6, R0\n"
                "B      loc_FF305640\n"
"loc_FF30563C:\n"
                "LDR    R6, =0x5DC\n"
"loc_FF305640:\n"
                "STR    R0, [R11, #0x12C]\n"
                "STR    R10, [R11, #0xD8]\n"
                "B      loc_FF30568C\n"
"loc_FF30564C:\n"
                "LDR    R6, =0xBB8\n"
                "B      loc_FF305640\n"
"loc_FF305654:\n"
                "LDR    R6, =0x1770\n"
                "B      loc_FF305640\n"
"loc_FF30565C:\n"
//              "LDR    R6, =0x3A980\n"
                "LDR    R6, =0xFFFFFFFE\n"           //240fps video time limit 
                "STR    R0, [R11, #0x12C]\n"
                "MOV    R0, #0xF0\n"
"loc_FF305668:\n"
                "STR    R0, [R11, #0xD8]\n"
                "B      loc_FF30568C\n"
"loc_FF305670:\n"
                "STR    R0, [R11, #0x12C]\n"
//                "LDR    R6, =0x1D4C0\n"
                "LDR    R6, =0xFFFFFFFE\n"           //120fps video time limit
                "MOV    R0, #0x78\n"
                "B      loc_FF305668\n"
"loc_FF305680:\n"
                "LDR    R1, =0x35B\n"
                "LDR    R0, =0xFF3041A8\n"
                "BL     sub_FF00EC80\n"
"loc_FF30568C:\n"
                "LDR    R0, [R11, #0xD8]\n"
//                "LDR    R1, =0xE0F\n"
                "LDR    R1, =0xFD20\n"               //240p, 480p video time limit 0xFD20(~18hr)
                "MOV    R0, R0, LSR #1\n"
                "STR    R0, [R11, #0xDC]\n"
                "LDR    R0, [R9]\n"
                "STR    R0, [R11, #0xE4]\n"
                "LDRH   R0, [R9, #0x10]\n"
                "STR    R0, [R11, #0xE8]\n"
                "LDR    R0, [R9, #4]\n"
                "STRH   R0, [R11, #2]\n"
                "LDR    R0, [R9, #8]\n"
                "STRH   R0, [R11, #4]\n"
                "LDR    R0, [R9, #0x14]\n"
                "STR    R0, [R11, #0xEC]\n"
                "STR    R7, [R11, #0x128]\n"
                "LDR    R0, [R11, #0xD0]\n"
                "CMP    R0, #0x140\n"
                "MOVEQ  R0, #0x20000\n"
                "MOVEQ  R5, #1\n"
                "STREQ  R0, [R11, #0xAC]\n"
                "BEQ    loc_FF305720\n"
                "CMP    R0, #0x280\n"
                "LDREQ  R0, =0x7A760\n"
                "MOVEQ  R5, #2\n"
                "STREQ  R0, [R11, #0xAC]\n"
                "BEQ    loc_FF305720\n"
                "CMP    R0, #0x500\n"
                "LDREQ  R0, =0x11DA50\n"
//              "LDR    R1, =0x707\n"
                "LDR    R1, =0xFFE\n"                   //720p, 1080p video time limit 0xFFE(~68min)
                "MOVEQ  R5, #4\n"
                "STREQ  R0, [R11, #0xAC]\n"
                "BEQ    loc_FF305720\n"
                "CMP    R0, #0x780\n"
                "BNE    loc_FF305728\n"
                "MOV    R0, #0x200000\n"
                "MOV    R5, #5\n"
                "STR    R0, [R11, #0xAC]\n"
"loc_FF305720:\n"
                "STR    R1, [R11, #0x4C]\n"
                "B      loc_FF305734\n"
"loc_FF305728:\n"
                "LDR    R1, =0x383\n"
                "LDR    R0, =0xFF3041A8\n"
                "BL     sub_FF00EC80\n"
"loc_FF305734:\n"
                "LDR    R0, [R11, #0x4C]\n"
                "LDR    R1, =0x138D\n"
                "MUL    R0, R6, R0\n"
                "BL     sub_FF3B61A8\n"
                "ADD    R0, R0, #1\n"
                "ADD    R0, R0, R0, LSL #2\n"
                "STR    R0, [R11, #0x48]\n"
                "LDR    R7, [R4, #8]\n"
                "CMP    R7, #2\n"
                "CMPNE  R7, #3\n"
                "BNE    loc_FF30578C\n"
                "RSB    R0, R6, R6, LSL #4\n"
                "LDR    R1, =0x3E9\n"
                "MOV    R0, R0, LSL #1\n"
                "STR    R10, [R11, #0x4C]\n"
                "BL     sub_FF3B61A8\n"
                "LDR    R1, [R11, #0xE0]\n"
                "MOV    R6, R1\n"
                "BL     sub_FF3B61A8\n"
                "ADD    R0, R0, #1\n"
                "MUL    R0, R6, R0\n"
                "STR    R0, [R11, #0x48]\n"
"loc_FF30578C:\n"
                "LDR    R0, [R4, #0xC]\n"
                "LDR    R6, [R9, #0xC]\n"
                "ADDS   R1, R0, #0\n"
                "MOV    R0, R6, LSR #1\n"
                "STR    R6, [R11, #0x94]\n"
                "STR    R0, [R11, #0x98]\n"
                "ADD    R0, R8, #3\n"
                "BIC    R0, R0, #3\n"
                "STR    R0, [R11, #0xF4]\n"
                "LDR    R2, [R11, #0x48]\n"
                "MOVNE  R1, #1\n"
                "MOV    R2, R2, LSL #2\n"
                "ADD    R3, R0, R2\n"
                "STR    R3, [R11, #0xF8]\n"
                "LDRH   R12, [R11, #4]\n"
                "LDR    R0, [SP, #4]\n"
                "ADD    R2, R2, R3\n"
                "CMP    R12, #0\n"
                "ADD    R0, R0, R8\n"
                "BEQ    loc_FF305904\n"
                "STR    R2, [R11, #0xFC]\n"
                "LDR    R3, [R11, #0x4C]\n"
                "LDR    R8, =0x11D628\n"
                "ADD    R2, R2, R3, LSL #3\n"
                "ADD    R2, R2, #0x1F\n"
                "BIC    R2, R2, #0x1F\n"
                "STR    R2, [R11, #0x100]\n"
                "LDR    R3, [R11, #0xAC]\n"
                "LDR    R10, =0xE008\n"
                "ADD    R2, R2, R3\n"
                "ADD    R3, R2, #0x100000\n"
                "STR    R2, [R11, #0x78]\n"
                "SUB    R0, R0, R3\n"
                "RSB    R2, R6, #0\n"
                "ADD    R0, R0, R2, LSL #1\n"
                "MOV    R0, R0, LSR #0xF\n"
                "MOV    R0, R0, LSL #0xF\n"
                "STR    R3, [R11, #0x104]\n"
                "ADD    R7, R3, R0\n"
                "STR    R0, [R11, #0x110]\n"
                "STR    R7, [R11, #0x108]\n"
                "MOV    R2, #0\n"
                "ADD    R9, R8, #0x10\n"
                "STR    R7, [R11, #0x10C]\n"
"loc_FF30583C:\n"
                "MLA    R0, R2, R6, R7\n"
                "ADD    R12, R8, R2, LSL #3\n"
                "ADD    R0, R0, #3\n"
                "BIC    R0, R0, #3\n"
                "STR    R0, [R10, R2, LSL #2]\n"
                "MOV    R0, #0\n"
                "ADD    LR, R9, R2, LSL #3\n"
"loc_FF305858:\n"
                "STR    R3, [R12, R0, LSL #2]\n"
                "STR    R3, [LR, R0, LSL #2]\n"
                "ADD    R0, R0, #1\n"
                "CMP    R0, #2\n"
                "BLT    loc_FF305858\n"
                "ADD    R2, R2, #1\n"
                "CMP    R2, #2\n"
                "BLT    loc_FF30583C\n"
                "LDRH   R3, [R4, #0x14]\n"
                "LDR    R2, [R4, #8]\n"
                "MOV    R0, R5\n"
                "BL     sub_FF0DA84C\n"
                "LDR    R1, [R11, #0x94]\n"
                "ADD    R0, R0, R1\n"
"loc_FF305890:\n"
                "STR    R0, [R11, #0x8C]\n"
                "LDMFD  SP!, {R0-R12,PC}\n"
//                "STRVSBT  R7, [R8], #-0x66D\n"
//                "ANDEQ  LR, R0, R0, LSR #0x20\n"
"loc_FF305904:\n"
                "ADD    R2, R2, #0x1F\n"
                "BIC    R2, R2, #0x1F\n"
                "STR    R2, [R11, #0x100]\n"
                "LDR    R3, [R11, #0xAC]\n"
                "ADD    R2, R2, R3\n"
                "SUB    R0, R0, R2\n"
                "MOV    R0, R0, LSR #0xF\n"
                "MOV    R0, R0, LSL #0xF\n"
                "STR    R2, [R11, #0x104]\n"
                "STR    R0, [R11, #0x110]\n"
                "ADD    R0, R0, R2\n"
                "STR    R0, [R11, #0x108]\n"
                "LDRH   R3, [R4, #0x14]\n"
                "MOV    R2, R7\n"
                "MOV    R0, R5\n"
                "BL     sub_FF0DA84C\n"
                "B      loc_FF305890\n"
    );
}

void __attribute__((naked,noinline)) sub_FF18D218_my(){

asm volatile (
                "STMFD  SP!, {R4-R11,LR}\n"
                "SUB    SP, SP, #0x64\n"
                "MOV    R9, #0\n"
                "LDR    R8, =0x85E0\n"
                "STR    R9, [SP, #0x54]\n"
                "STR    R9, [SP, #0x4C]\n"
                "STR    R9, [R8, #0xDC]\n"
                "STR    R9, [R8, #0xE0]\n"
                "STR    R9, [R8, #0xE4]\n"
                "MOV    R4, R0\n"
                "STR    R9, [R8, #0xE8]\n"
                "LDR    R0, [R8, #0x44]\n"
                "MOV    R7, R9\n"
                "CMP    R0, #3\n"
                "MOVEQ  R0, #4\n"
                "STREQ  R0, [R8, #0x44]\n"
                "LDR    R0, [R8, #0xD8]\n"
                "MOV    R5, #1\n"
                "MOV    R6, R9\n"
                "BLX    R0\n"
                "LDR    R0, [R8, #0x44]\n"
                "CMP    R0, #6\n"
                "BEQ    loc_FF18D288\n"
                "LDR    R1, [R8, #0xC]\n"
                "CMP    R1, #2\n"
                "BNE    loc_FF18D2B0\n"
                "CMP    R0, #5\n"
                "BEQ    loc_FF18D2C0\n"
"loc_FF18D288:\n"
                "LDR    R2, =0xFF18D0F8\n"
                "LDR    R1, =0xFF18D158\n"
                "LDR    R0, =0xFF18D1B8\n"
                "MOV    R6, #1\n"
                "ADD    R3, SP, #0x34\n"
                "BL     sub_FF0463D8\n"
                "LDR    R0, [R8, #0x44]\n"
                "CMP    R0, #4\n"
                "MOVNE  R5, #0\n"
                "B      loc_FF18D2D0\n"
"loc_FF18D2B0:\n"
                "CMP    R0, #4\n"
                "BEQ    loc_FF18D2D0\n"
                "CMP    R1, #2\n"
                "BNE    loc_FF18D2C8\n"
"loc_FF18D2C0:\n"
                "MOV    R0, #0\n"
                "BL     sub_FF0463E4\n"
"loc_FF18D2C8:\n"
                "ADD    SP, SP, #0x64\n"
                "LDMFD  SP!, {R4-R11,PC}\n"
"loc_FF18D2D0:\n"
                "LDRH   R0, [R8, #6]\n"
                "CMP    R0, #3\n"
                "BNE    loc_FF18D2F0\n"
                "LDR    R0, [R8, #0x6C]\n"
                "LDR    R1, [R8, #0xEC]\n"
                "BL     sub_FF3B61A8\n"
                "CMP    R1, #0\n"
                "MOVNE  R5, #0\n"
"loc_FF18D2F0:\n"
                "LDR    R0, [R8, #0x44]\n"
                "CMP    R0, #6\n"
                "CMPNE  R0, #1\n"
                "CMPNE  R0, #3\n"
                "BNE    loc_FF18D334\n"
                "CMP    R6, #1\n"
                "CMPEQ  R5, #0\n"
                "BNE    loc_FF18D334\n"
                "BL     sub_FF0463DC\n"
                "LDR    R0, [R8, #0x18]\n"
                "MOV    R1, #0x3E8\n"
                "BL     sub_FF02B598\n"
                "CMP    R0, #9\n"
                "BNE    loc_FF18D73C\n"
                "MOV    R0, #0x90000\n"
                "BL     sub_FF09342C\n"
                "B      loc_FF18D2C8\n"
"loc_FF18D334:\n"
                "CMP    R5, #1\n"
                "MOV    R10, #1\n"
                "BNE    loc_FF18D35C\n"
                "ADD    R3, SP, #0x4C\n"
                "ADD    R2, SP, #0x50\n"
                "ADD    R1, SP, #0x54\n"
                "ADD    R0, SP, #0x58\n"
                "BL     sub_FF306D4C\n"
                "MOVS   R9, R0\n"
                "BNE    loc_FF18D378\n"
"loc_FF18D35C:\n"
                "LDR    R0, [R8, #0x34]\n"
                "CMP    R0, #1\n"
                "BNE    loc_FF18D4B8\n"
                "LDR    R0, [R8, #0x6C]\n"
                "LDR    R1, [R8, #0x48]\n"
                "CMP    R0, R1\n"
                "BCC    loc_FF18D4B8\n"
"loc_FF18D378:\n"
                "MOV    R0, R9\n"
                "BL     sub_FF18C6A0\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "BNE    loc_FF18D3E8\n"
                "LDR    R0, =0xFF18D0EC\n"
                "MOV    R1, #0\n"
                "BL     sub_FF2B6E4C\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "STRD   R2, [SP, #0x28]\n"
                "MOV    R2, #0x18\n"
                "ADD    R1, SP, #0x34\n"
                "ADD    R0, SP, #0x10\n"
                "BL     sub_FF3B5E8C\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "MOV    R3, #0xFFFFFFFE\n"
                "ADD    R0, SP, #0x60\n"
                "STMEA  SP, {R0-R3}\n"
                "MOV    R3, #0\n"
                "LDR    R0, =0xC6A54\n"
                "MOV    R2, R3\n"
                "MOV    R1, #0x40\n"
                "BL     sub_FF2B6D98\n"
                "B      loc_FF18D440\n"
"loc_FF18D3E0:\n"
                "MOV    R1, #1\n"
                "B      loc_FF18D6CC\n"
"loc_FF18D3E8:\n"
                "BL     sub_FF18DF94\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "MOV    R1, #0xFFFFFFFE\n"
                "MOV    R0, #0\n"
                "ADD    R5, SP, #0x1C\n"
                "STMIA  R5, {R0-R3}\n"
                "LDR    R3, [R4, #0x1C]\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "ADD    R0, SP, #0x60\n"
                "ADD    R4, SP, #0xC\n"
                "STMIA  R4, {R0-R3}\n"
                "MOV    R3, #0\n"
                "MOV    R1, #0x40\n"
                "STMEA  SP, {R1,R3}\n"
                "MOV    R2, #0\n"
                "STR    R3, [SP, #8]\n"
                "LDR    R3, =0xC6A54\n"
                "MOV    R1, R2\n"
                "MOV    R0, R2\n"
                "BL     sub_FF2B5700\n"
"loc_FF18D440:\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL     sub_FF02B598\n"
                "CMP    R0, #9\n"
                "BEQ    loc_FF18D3E0\n"
                "LDR    R0, [SP, #0x5C]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D468\n"
"loc_FF18D460:\n"
                "MOV    R1, #1\n"
                "B      loc_FF18D6E4\n"
"loc_FF18D468:\n"
                "LDR    R0, [R8, #0xC]\n"
                "MOV    R4, #5\n"
                "CMP    R0, #2\n"
                "MOV    R0, #1\n"
                "BNE    loc_FF18D4A4\n"
                "BL     sub_FF2B6E0C\n"
                "BL     sub_FF2B6E34\n"
                "MOV    R0, #0\n"
                "BL     sub_FF0463E4\n"
                "BL     sub_FF0463F4\n"
                "STR    R4, [R8, #0x44]\n"
                "BL     sub_FF18DF94\n"
                "BL     sub_FF046450\n"
                "STR    R10, [R8, #0x44]\n"
                "B      loc_FF18D4B0\n"
"loc_FF18D4A4:\n"
                "BL     sub_FF2B57AC\n"
                "BL     sub_FF2B57F8\n"
                "STR    R4, [R8, #0x44]\n"
"loc_FF18D4B0:\n"
                "STR    R7, [R8, #0x34]\n"
                "B      loc_FF18D2C8\n"
"loc_FF18D4B8:\n"
                "CMP    R5, #1\n"
                "BNE    loc_FF18D734\n"
                "STR    R10, [R8, #0x38]\n"
                "LDR    R0, [R8, #0x6C]\n"
                "LDR    R11, [R4, #0xC]\n"
                "CMP    R0, #0\n"
                "LDRNE  R9, [SP, #0x58]\n"
                "LDRNE  R10, [SP, #0x54]\n"
                "BNE    loc_FF18D604\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "BNE    loc_FF18D55C\n"
                "LDR    R0, =0xFF18D0EC\n"
                "MOV    R1, #0\n"
                "BL     sub_FF2B6E4C\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "STRD   R2, [SP, #0x28]\n"
                "MOV    R2, #0x18\n"
                "ADD    R1, SP, #0x34\n"
                "ADD    R0, SP, #0x10\n"
                "BL     sub_FF3B5E8C\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "MOV    R3, #0xFFFFFFFF\n"
                "ADD    R0, SP, #0x60\n"
                "STMEA  SP, {R0-R3}\n"
                "LDR    R0, [SP, #0x58]\n"
                "LDR    R1, [SP, #0x54]\n"
                "LDR    R2, [SP, #0x50]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "BL     sub_FF2B6D98\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL     sub_FF02B598\n"
                "CMP    R0, #9\n"
                "BEQ    loc_FF18D3E0\n"
                "LDR    R0, =0xFF18C658\n"
                "MOV    R1, #0\n"
                "BL     sub_FF2B6E4C\n"
                "B      loc_FF18D5C4\n"
"loc_FF18D55C:\n"
                "LDR    R0, [R4, #0x20]\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "MOV    R1, #0xFFFFFFFF\n"
                "ADD    R9, SP, #0x1C\n"
                "STMIA  R9, {R0-R3}\n"
                "LDR    R3, [R4, #0x1C]\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "ADD    R0, SP, #0x60\n"
                "ADD    R9, SP, #0xC\n"
                "STMIA  R9, {R0-R3}\n"
                "LDR    R1, [SP, #0x50]\n"
                "LDR    R2, [SP, #0x54]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "STMFA  SP, {R1,R3}\n"
                "STR    R2, [SP]\n"
                "LDMIB  R4, {R0,R1}\n"
                "LDR    R3, [SP, #0x58]\n"
                "MOV    R2, R11\n"
                "BL     sub_FF2B5700\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL     sub_FF02B598\n"
                "CMP    R0, #9\n"
                "BEQ    loc_FF18D3E0\n"
"loc_FF18D5C4:\n"
                "LDR    R0, [SP, #0x5C]\n"
                "CMP    R0, #0\n"
                "BNE    loc_FF18D460\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "MOV    R0, #1\n"
                "BNE    loc_FF18D5E8\n"
                "BL     sub_FF2B6E0C\n"
                "B      loc_FF18D5EC\n"
"loc_FF18D5E8:\n"
                "BL     sub_FF2B57AC\n"
"loc_FF18D5EC:\n"
                "STR    R7, [R8, #0xE8]\n"
                "LDR    R0, [SP, #0x60]\n"
                "LDR    R1, [SP, #0x58]\n"
                "ADD    R9, R1, R0\n"
                "LDR    R1, [SP, #0x54]\n"
                "SUB    R10, R1, R0\n"
"loc_FF18D604:\n"
                "LDR    R0, [R8, #0xC]\n"
                "LDR    R2, [R8, #0x64]\n"
                "CMP    R0, #2\n"
                "ADD    R3, SP, #0x5C\n"
                "BNE    loc_FF18D65C\n"
                "STRD   R2, [SP, #0x28]\n"
                "MOV    R2, #0x18\n"
                "ADD    R1, SP, #0x34\n"
                "ADD    R0, SP, #0x10\n"
                "BL     sub_FF3B5E8C\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "LDR    R3, [R8, #0x68]\n"
                "ADD    R0, SP, #0x60\n"
                "STMEA  SP, {R0-R3}\n"
                "LDR    R2, [SP, #0x50]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "MOV    R1, R10\n"
                "MOV    R0, R9\n"
                "BL     sub_FF2B6D98\n"
                "BL     sub_FF0463DC\n"
                "B      loc_FF18D6B4\n"
"loc_FF18D65C:\n"
                "LDR    R1, [R8, #0x68]\n"
                "LDR    R0, [R4, #0x20]\n"
                "STR    R1, [SP, #0x20]\n"
                "STR    R0, [SP, #0x1C]\n"
                "STR    R2, [SP, #0x24]\n"
                "STR    R3, [SP, #0x28]\n"
                "LDR    R3, [R4, #0x1C]\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "ADD    R0, SP, #0x60\n"
                "STR    R2, [SP, #0x14]\n"
                "LDR    R2, [SP, #0x50]\n"
                "STR    R1, [SP, #0x10]\n"
                "STR    R3, [SP, #0x18]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "STR    R0, [SP, #0xC]\n"
                "STMFA  SP, {R2,R3}\n"
                "STR    R10, [SP]\n"
                "LDMIB  R4, {R0,R1}\n"
                "MOV    R3, R9\n"
                "MOV    R2, R11\n"
                "BL     sub_FF2B5700\n"
"loc_FF18D6B4:\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL     sub_FF02B598\n"
                "CMP    R0, #9\n"
                "BNE    loc_FF18D6D4\n"
                "MOV    R1, #0\n"
"loc_FF18D6CC:\n"
                "MOV    R0, #0x90000\n"
                "B      loc_FF18D6E8\n"
"loc_FF18D6D4:\n"
                "LDR    R0, [SP, #0x5C]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D6F0\n"
                "MOV    R1, #0\n"
"loc_FF18D6E4:\n"
                "MOV    R0, #0xA0000\n"
"loc_FF18D6E8:\n"
                "BL     sub_FF18CA1C\n"
                "B      loc_FF18D2C8\n"
"loc_FF18D6F0:\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "MOV    R0, #0\n"
                "BNE    loc_FF18D708\n"
                "BL     sub_FF2B6E0C\n"
                "B      loc_FF18D70C\n"
"loc_FF18D708:\n"
                "BL     sub_FF2B57AC\n"
"loc_FF18D70C:\n"
                "LDR    R0, [SP, #0x58]\n"
                "LDR    R1, [SP, #0x60]\n"
                "BL     sub_FF306FE0\n"
                "LDR    R0, [R8, #0x68]\n"
                "LDR    R3, =0x8668\n"
                "ADD    R1, R0, #1\n"
                "STR    R1, [R8, #0x68]\n"
                "LDR    R0, [SP, #0x60]\n"
                "SUB    R2, R3, #4\n"
                "BL     sub_FF30340C\n"
        //PATCH BEGIN
                "LDR    R0, =0x8664\n"
                "BL     set_quality\n"
        //PATCH ENDE
"loc_FF18D734:\n"
                "CMP    R6, #1\n"
                "BNE    loc_FF18D748\n"
"loc_FF18D73C:\n"
                "BL     sub_FF0463E0\n"
                "MOV    R0, #1\n"
                "BL     sub_FF0463E4\n"
"loc_FF18D748:\n"
                "CMP    R5, #1\n"
                "LDRNEH R0, [R8, #6]\n"
                "CMPNE  R0, #3\n"
                "BNE    loc_FF18D2C8\n"
                "LDR    R0, [R8, #0x6C]\n"
                "ADD    R0, R0, #1\n"
                "STR    R0, [R8, #0x6C]\n"
                "LDRH   R1, [R8, #6]\n"
                "CMP    R1, #3\n"
                "LDRNE  R1, [R8, #0x54]\n"
                "LDREQ  R1, =0x3E9\n"
                "MUL    R0, R1, R0\n"
                "LDRNE  R1, [R8, #0x50]\n"
                "LDREQ  R1, =0x1770\n"
                "BL     sub_FF3B61A8\n"
                "MOV    R4, R0\n"
                "BL     sub_FF307674\n"
                "LDR    R0, [R8, #0x8C]\n"
                "CMP    R0, R4\n"
                "BNE    loc_FF18D7A4\n"
                "LDR    R0, [R8, #0x3C]\n"
                "CMP    R0, #1\n"
                "BNE    loc_FF18D7B8\n"
"loc_FF18D7A4:\n"
                "LDR    R1, [R8, #0xBC]\n"
                "MOV    R0, R4\n"
                "BLX    R1\n"
                "STR    R4, [R8, #0x8C]\n"
                "STR    R7, [R8, #0x3C]\n"
"loc_FF18D7B8:\n"
                "STR    R7, [R8, #0x38]\n"
                "B      loc_FF18D2C8\n"
    );
}

