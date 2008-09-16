#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[56]={
0x10000,0xC000,0x5800, 0x2000, 0x1C6A, 0x1550,0x9C5,  0x38D,  0x3C45, 0x2D34, 0x14B8, 0x788,  0x5F60, 0x4788,
0x20C9, 0xBE1, 0x8661, 0x64C9, 0x2E31, 0x10CB,0xB21A, 0x8594, 0x3D39, 0x1642, 0xE249, 0xA9B8, 0x4DC9, 0x1C48,
0x117D2,0xD1DF,0x6030, 0x22F9, 0x153D5,0xFEE1,0x74D1, 0x2A79, 0x195F8,0x1307C,0x8B8D, 0x32AA, 0x1E01C,0x16817,
0xA509, 0x3C01,0x2328E,0x1A5ED,0xC160, 0x4637,0x28C99,0x1E975,0xE054, 0x5190, 0x2F08B,0x2346B,0x102AF,0x5E0E
};

long def_table2[12]={0xE666,0xACCD,0x4F33,0x1CCD,-0x170A,-0x1148,-0x7EB,-0x2E1,-0x2BC6,-0x20D5,-0xF0C,-0x579};

long table1[56], table2[12];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<56;i++) table1[i]=(def_table1[i]*a)/b;
 for (i=0;i<12;i++) table2[i]=(def_table2[i]*a)/b;
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"    
                "SUB     SP, SP, #4\n"      
                "MOV     R4, SP\n"          
                "B       loc_FF951170\n"    
"loc_FF9510C0:\n"                           
                "LDR     R3, =0x6F940\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #0\n"          
                "BNE     loc_FF95115C\n"    
                "SUB     R3, R12, #1\n"     
                "CMP     R3, #0xA\n"        
                "LDRLS   PC, [PC,R3,LSL#2]\n" 
                "B       loc_FF95115C\n"    
                ".long loc_FF95110C\n"
                ".long loc_FF951114\n"
                ".long loc_FF95112C\n"
                ".long loc_FF951134\n"
                ".long loc_FF95113C\n"
                ".long loc_FF95111C\n"
                ".long loc_FF951144\n"
                ".long loc_FF951124\n"
                ".long loc_FF95115C\n"
                ".long loc_FF951154\n"
                ".long loc_FF95114C\n"
"loc_FF95110C:\n"                           
                                        
                "BL      sub_FF9511F0\n"    
                "B       loc_FF951158\n"    
"loc_FF951114:\n"                           
                                        
                "BL      sub_FF951424\n"    
				"BL	 unlock_optical_zoom\n"
                "B       loc_FF951158\n"    
"loc_FF95111C:\n"                           
                                        
                "BL      sub_FF9517AC_my\n"    //---------------------> ' FF9517AC
                "B       loc_FF951158\n"    
"loc_FF951124:\n"                           
                                        
                "BL      sub_FF951C44\n"    
                "B       loc_FF951158\n"    
"loc_FF95112C:\n"                           
                                        
                "BL      sub_FF951A14\n"    
                "B       loc_FF951158\n"    
"loc_FF951134:\n"                           
                                        
                "BL      sub_FF951E50\n"    
                "B       loc_FF951158\n"    
"loc_FF95113C:\n"                           
                                        
                "BL      sub_FF952014\n"    
                "B       loc_FF951158\n"    
"loc_FF951144:\n"                           
                                        
                "BL      sub_FF951D04\n"    
                "B       loc_FF951158\n"    
"loc_FF95114C:\n"                           
                                        
                "BL      sub_FF951DE4\n"    
                "B       loc_FF951158\n"    
"loc_FF951154:\n"                           
                                        
                "BL      sub_FF951A64\n"    
"loc_FF951158:\n"                           
                                        
                "LDR     R1, [SP]\n"        
"loc_FF95115C:\n"                           
                                        
                "LDR     R3, =0x6F870\n"    
                "MOV     R2, #0\n"          
                "STR     R2, [R1]\n"        
                "LDR     R0, [R3]\n"        
                "BL      sub_FF8211A4\n" // PostMessageQueue
"loc_FF951170:\n"                           
                "LDR     R3, =0x6F86C\n"    
                "MOV     R1, R4\n"          
                "LDR     R0, [R3]\n"        
                "MOV     R2, #0\n"          
                "BL      sub_FF820D8C\n" // ReceiveMessageQueue
                "LDR     R0, [SP]\n"        
                "LDR     R12, [R0]\n"       
                "CMP     R12, #0xC\n"       
                "MOV     R1, R0\n"          
                "BNE     loc_FF9510C0\n"    
                "LDR     R3, =0x6F864\n"    
                "LDR     R0, [R3]\n"        
                "BL      sub_FF821BAC\n" // GiveSemaphore
                "BL      sub_FF8225B4\n" // ExitTask
                "ADD     SP, SP, #4\n"      
                "LDMFD   SP!, {R4,PC}\n"    

 );
}


void __attribute__((naked,noinline)) sub_FF9517AC_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n" 
                "LDR     R5, =0x6F95C\n"    
                "SUB     SP, SP, #0x1C\n"   
                "LDR     R3, [R5]\n"        
                "CMP     R3, #3\n"          
                "MOV     R4, R0\n"          
                "MOVEQ   R3, #4\n"          
                "STREQ   R3, [R5]\n"        
                "LDR     R3, =0x6FA04\n"    
                "MOV     LR, PC\n"          
                "LDR     PC, [R3]\n"        
                "LDR     R2, [R5]\n"        
                "CMP     R2, #4\n"          
                "BNE     loc_FF951944\n"    
                "ADD     R0, SP, #0x18\n"   
                "BL      sub_FF9533BC_my\n"  //------------------>  FF9533BC
                "CMP     R0, #0\n"          
                "BNE     loc_FF95181C\n"    
                "LDR     R3, =0x6F948\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #1\n"          
                "BNE     loc_FF951838\n"    
                "LDR     R2, =0x6F998\n"    
                "LDR     R1, =0x6F970\n"    
                "LDR     R12, [R2]\n"       
                "LDR     R3, [R1]\n"        
                "CMP     R12, R3\n"         
                "BCC     loc_FF951838\n"    
"loc_FF95181C:\n"                           
                "BL      sub_FF95198C\n"    
                "LDR     R3, =0x56BC\n"     
                "LDR     R0, [R3]\n"        
                "BL      sub_FF8302C4\n"    
                "MOV     R3, #5\n"          
                "STR     R3, [R5]\n"        
                "B       loc_FF951944\n"    
"loc_FF951838:\n"                           
                                        
                "LDR     R0, [R4,#4]\n"     
                "LDR     R5, [R4,#0xC]\n"   
                "LDR     R3, =0x6F9A0\n"    
                "LDR     R4, [R4,#8]\n"     
                "LDR     R8, =0x6F9AC\n"    
                "LDR     R6, =0x6F94C\n"    
                "ADD     R12, SP, #0x14\n"  
                "ADD     LR, SP, #0x10\n"   
                "MOV     R7, #1\n"          
                "LDR     R2, [R3]\n"        
                "LDR     R1, [SP,#0x18]\n"  
                "STMEA   SP, {R4,R5,R12,LR}\n" 
                "LDR     R3, [R8]\n"        
                "STR     R7, [R6]\n"        
                "BL      sub_FF8A2D4C\n"    
                "LDR     R3, =0x6F864\n"    
                "MOV     R1, #0x3E8\n"      
                "LDR     R0, [R3]\n"        
                "BL      sub_FF8219C4\n"   
                "CMP     R0, #9\n"          
                "BNE     loc_FF95189C\n"    
                "BL      sub_FF953AB0\n"    
                "LDR     R3, =0x6F95C\n"    
                "LDR     R0, =0xFF951794\n" // aJpegtimeout_2
                "B       loc_FF9518B4\n"    
"loc_FF95189C:\n"                           
                "LDR     R5, [SP,#0x10]\n"  
                "CMP     R5, #0\n"          
                "BEQ     loc_FF9518C0\n"    
                "BL      sub_FF953AB0\n"    
                "LDR     R3, =0x6F95C\n"    
                "LDR     R0, =0xFF9517A0\n" // aJpegicerror_3
"loc_FF9518B4:\n"                           
                "STR     R7, [R3]\n"        
                "BL      sub_FF96B100\n"  // HardwareDefect
                "B       loc_FF951944\n"    
"loc_FF9518C0:\n"                           
                "BL      sub_FF8A2DF8\n"  // IsEmptyWriteCache_42
                "LDR     R0, [SP,#0x18]\n"  
                "LDR     R1, [SP,#0x14]\n"  
                "BL      sub_FF9537DC\n"    
                "LDR     R4, =0x6F998\n"    
                "LDR     R3, [R4]\n"        
                "ADD     R3, R3, #1\n"      
                "LDR     R0, [SP,#0x14]\n"  
                "MOV     R1, R8\n"          
                "STR     R3, [R4]\n"        
                "MOV     R2, R5\n"          
                "BL      sub_FF95240C_my\n"   //---------------------->  FF95240C
                "LDR     R3, =0x6F984\n"    
                "LDR     R4, [R4]\n"        
                "LDR     R1, [R3]\n"        
                "MOV     R0, R4\n"          
                "BL      sub_FFAB18F4\n"   // __umodsi3
                "CMP     R0, #0\n"          
                "BEQ     loc_FF951920\n"    
                "LDR     R6, =0x6F950\n"    
                "LDR     R3, [R6]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FF951938\n"    
                "B       loc_FF951924\n"    
"loc_FF951920:\n"                           
                "LDR     R6, =0x6F950\n"    
"loc_FF951924:\n"                           
                "MOV     R0, R4\n"          
                "LDR     R3, =0x6F9E0\n"    
                "MOV     LR, PC\n"          
                "LDR     PC, [R3]\n"        
                "STR     R5, [R6]\n"        
"loc_FF951938:\n"                           
                "LDR     R2, =0x6F94C\n"    
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        
"loc_FF951944:\n"                           
                                        
                "ADD     SP, SP, #0x1C\n"   
                "LDMFD   SP!, {R4-R8,PC}\n" 
	
 );
}

void __attribute__((naked,noinline)) sub_FF9533BC_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n" 
                "LDR     R12, =0x6FCAC\n"   
                "LDR     R3, =0x6FCC4\n"    
                "SUB     SP, SP, #8\n"      
                "LDR     R1, [R3]\n"        
                "LDR     R2, [R12]\n"       
                "LDR     R3, =0x6FD44\n"    
                "ADD     R7, R2, #1\n"      
                "LDR     R3, [R3]\n"        
                "CMP     R7, R1\n"          
                "STR     R7, [R12]\n"       
                "MOV     R11, R0\n"         
                "STR     R3, [SP,#4]\n"     
                "MOVHI   R3, #0\n"          
                "STRHI   R3, [R11]\n"       
                "MOVHI   R0, #0x80000001\n" 
                "BHI     loc_FF953790\n"    
                "LDR     R3, =0x6FD28\n"    
                "LDR     R4, [R3]\n"        
                "MOV     R0, R7\n"          
                "MOV     R1, R4\n"          
                "BL      sub_FFAB18F4\n"  // __umodsi3
                "CMP     R0, #1\n"          
                "BNE     loc_FF953624\n"    
                "LDR     R3, =0x6FD48\n"    
                "LDR     R1, =0x6FD54\n"    
                "LDR     R0, =0x6FC98\n"    
                "LDR     R10, [R3]\n"       
                "LDR     R2, [R1]\n"        
                "LDR     R5, [R0]\n"        
                "ADD     R2, R10, R2\n"     
                "CMP     R2, R5\n"          
                "BNE     loc_FF953460\n"    
                "MOV     R1, R4\n"          
                "MOV     R0, R7\n"          
                "BL      sub_FFAB1264\n"  // __udivsi3
                "LDR     R4, =0x6FCA0\n"    
                "ADD     R0, R0, #1\n"      
                "AND     R0, R0, #1\n"      
                "STR     R10, [R4,R0,LSL#2]\n" 
                "B       loc_FF95347C\n"    
"loc_FF953460:\n"                           
                "MOV     R1, R4\n"          
                "MOV     R0, R7\n"          
                "BL      sub_FFAB1264\n"   // __udivsi3
                "LDR     R4, =0x6FCA0\n"    
                "ADD     R0, R0, #1\n"      
                "AND     R0, R0, #1\n"      
                "STR     R5, [R4,R0,LSL#2]\n" 
"loc_FF95347C:\n"                           
                "LDR     R2, =0x6FD28\n"    
                "LDR     R3, =0x6FCAC\n"    
                "LDR     R1, [R2]\n"        
                "LDR     R0, [R3]\n"        
                "BL      sub_FFAB1264\n"  // __udivsi3
                "LDR     R1, =0x6FC94\n"    
                "ADD     R0, R0, #1\n"      
                "AND     R0, R0, #1\n"      
                "LDR     R12, [R4,R0,LSL#2]\n" 
                "LDR     R2, [R1]\n"        
                "CMP     R12, R2\n"         
                "BHI     loc_FF9534C8\n"    
                "LDR     R4, =0x6FCE4\n"    
                "LDR     R3, [R4]\n"        
                "ADD     R3, R12, R3\n"     
                "ADD     R3, R3, #8\n"      
                "CMP     R2, R3\n"          
                "BCS     loc_FF9534CC\n"    
                "B       loc_FF9536A0\n"    
"loc_FF9534C8:\n"                           
                "LDR     R4, =0x6FCE4\n"    
"loc_FF9534CC:\n"                           
                "LDR     R2, =0x6FD48\n"    
                "LDR     R1, =0x6FD54\n"    
                "LDR     R0, [R4]\n"        
                "LDR     R3, [R1]\n"        
                "LDR     LR, [R2]\n"        
                "ADD     R0, R12, R0\n"     
                "ADD     R2, LR, R3\n"      
                "ADD     R1, R0, #8\n"      
                "CMP     R1, R2\n"          
                "BLS     loc_FF95351C\n"    
                "LDR     R3, =0x6FC94\n"    
                "RSB     R2, R2, R0\n"      
                "ADD     R0, R2, #8\n"      
                "LDR     R1, [R3]\n"        
                "ADD     R2, LR, R0\n"      
                "CMP     R1, R2\n"          
                "BCC     loc_FF9536A0\n"    
                "LDR     R3, =0x6FC98\n"    
                "STR     R2, [R3]\n"        
                "B       loc_FF953524\n"    
"loc_FF95351C:\n"                           
                "LDR     R3, =0x6FC98\n"    
                "STR     R1, [R3]\n"        
"loc_FF953524:\n"                           
                "LDR     R3, [R4]\n"        
                "LDR     R12, =0x6FCF8\n"   
                "ADD     R3, R3, #0x18\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FF9536E0\n"    
                "BNE     loc_FF953554\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BHI     loc_FF9536E0\n"    
"loc_FF953554:\n"                           
                "LDR     R4, [R4]\n"        
                "LDR     LR, =0x6FD00\n"    
                "STR     R4, [SP]\n"        
                "LDR     R12, =0x6FCF8\n"   
                "LDR     R3, =0x6FCAC\n"    
                "LDMIA   LR, {R7,R8}\n"     
                "LDMIA   R12, {R5,R6}\n"    
                "LDR     R10, [R3]\n"       
                "LDR     R2, =0x6FD28\n"    
                "MOV     R3, R4\n"          
                "MOV     R4, #0\n"          
                "ADDS    R7, R7, R3\n"      
                "ADC     R8, R8, R4\n"      
                "LDR     R9, [R2]\n"        
                "SUBS    R5, R5, R3\n"      
                "SBC     R6, R6, R4\n"      
                "MVN     R2, #0\n"          
                "MVN     R1, #0x17\n"       
                "ADDS    R5, R5, R1\n"      
                "MOV     R4, #0\n"          
                "MOV     R3, #0x18\n"       
                "ADC     R6, R6, R2\n"      
                "ADDS    R7, R7, R3\n"      
                "ADC     R8, R8, R4\n"      
                "STMIA   R12, {R5,R6}\n"    
                "SUB     R0, R10, #1\n"     
                "MOV     R1, R9\n"          
                "STMIA   LR, {R7,R8}\n"     
                "BL      sub_FFAB1264\n"  // __udivsi3
                "CMP     R10, #1\n"         
                "MLA     R0, R9, R0, R0\n"  
                "BEQ     loc_FF953624\n"    
                "LDR     R2, [SP,#4]\n"     
                "SUB     R3, R0, #1\n"      
                "MOV     R3, R3,LSL#4\n"    
                "ADD     R5, R2, #0x14\n"   
                "ADD     R4, R2, #0x10\n"   
                "LDR     R1, [R5,R3]\n"     
                "LDR     R2, [R4,R3]\n"     
                "MOV     R3, R0,LSL#4\n"    
                "LDR     R0, [SP,#4]\n"     
                "ADD     R2, R2, R1\n"      
                "LDR     LR, =0x62773130\n" 
                "ADD     R1, R0, #8\n"      
                "ADD     R12, R0, #0xC\n"   
                "ADD     R2, R2, #8\n"      
                "MOV     R0, #0\n"          
                "STR     LR, [R1,R3]\n"     
                "STR     R0, [R12,R3]\n"    
                "STR     R2, [R4,R3]\n"     
                "LDR     R1, [SP]\n"        
                "STR     R1, [R5,R3]\n"     
"loc_FF953624:\n"                           
                                        
                "LDR     R2, =0x6FC98\n"    
                "LDR     R3, [R2]\n"        
                "ADD     R1, R3, #8\n"      
                "STR     R1, [R11]\n"       
                "LDR     R0, =0x6FC94\n"    
                "LDR     R2, [R0]\n"        
                "CMP     R3, R2\n"          
                "BHI     loc_FF95365C\n"    
                "LDR     LR, =0x6FCF4\n"    
                "LDR     R3, [LR]\n"        
                "ADD     R3, R1, R3\n"      
                "CMP     R2, R3\n"          
                "BCS     loc_FF953660\n"    
                "B       loc_FF9536A0\n"    
"loc_FF95365C:\n"                           
                "LDR     LR, =0x6FCF4\n"    
"loc_FF953660:\n"                           
                "LDR     R3, =0x6FD48\n"    
                "LDR     R2, =0x6FD54\n"    
                "LDR     R12, [R3]\n"       
                "LDR     R0, [R2]\n"        
                "LDR     R1, [R11]\n"       
                "LDR     R3, [LR]\n"        
                "ADD     R2, R1, R3\n"      
                "ADD     R1, R12, R0\n"     
                "CMP     R2, R1\n"          
                "BLS     loc_FF9536B0\n"    
                "RSB     R0, R1, R2\n"      
                "LDR     R1, =0x6FC94\n"    
                "LDR     R2, [R1]\n"        
                "ADD     R3, R12, R0\n"     
                "CMP     R2, R3\n"          
                "BCS     loc_FF9536B0\n"    
"loc_FF9536A0:\n"                           
                                        
                "MOV     R3, #0\n"          
                "STR     R3, [R11]\n"       
                "MOV     R0, #0x80000003\n" 
                "B       loc_FF953790\n"    
"loc_FF9536B0:\n"                           
                                        
                "LDR     R3, [LR]\n"        
                "LDR     R12, =0x6FCF8\n"   
                "ADD     R3, R3, #0x18\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FF9536E0\n"    
                "BNE     loc_FF9536F0\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BLS     loc_FF9536F0\n"    
"loc_FF9536E0:\n"                           
                                        
                "MOV     R3, #0\n"          
                "STR     R3, [R11]\n"       
                "MOV     R0, #0x80000005\n" 
                "B       loc_FF953790\n"    
"loc_FF9536F0:\n"                           
                                        
                "LDR     R1, =0x6FCDC\n"    
                "LDR     R0, =0x6FD28\n"    
                "LDR     R3, [R1]\n"        
                "LDR     R2, [R0]\n"        
                "ADD     R3, R3, R2,LSL#4\n" 
                "ADD     R3, R3, R3,LSL#2\n" 
                "LDR     R12, =0x6FCF8\n"   
                "MOV     R3, R3,LSL#1\n"    
                "ADD     R3, R3, #0xA0\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FF953738\n"    
                "BNE     loc_FF95375C\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BLS     loc_FF95375C\n"    
"loc_FF953738:\n"                           
                "LDR     R4, =0x6FD10\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FF95375C\n"    
                "MOV     R0, #0x3140\n"     
                "ADD     R0, R0, #8\n"      
                "BL      sub_FF96F030\n"  // PostLogicalEventToUI
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        
"loc_FF95375C:\n"                           
                                        
                "LDR     R2, =0x6FD00\n"    
                "LDR     R3, [R2,#4]\n"     
                "CMP     R3, #0\n"          
                "BHI     loc_FF95377C\n"    
                "BNE     loc_FF95378C\n"    
                "LDR     R3, [R2]\n"        
                "CMP     R3, #0x40000000\n" 
           //   "BLS     loc_FF95378C\n"     // -

                "B       loc_FF95378C\n"     // +
                
"loc_FF95377C:\n"                           
                "MOV     R3, #0\n"          
                "STR     R3, [R11]\n"       
                "MOV     R0, #0x80000007\n" 
                "B       loc_FF953790\n"    
"loc_FF95378C:\n"                           
                                        
                "MOV     R0, #0\n"          
"loc_FF953790:\n"                           
                                        
                "ADD     SP, SP, #8\n"      
                "LDMFD   SP!, {R4-R11,PC}\n" 
 );
}

void __attribute__((naked,noinline)) sub_FF95240C_my(){
 asm volatile(
                "CMP     R2, #1\n"          
                "STMFD   SP!, {R4-R7,LR}\n" 
                "MOV     R7, R0\n"          
                "MOV     R6, R1\n"          
                "LDREQ   R3, =CompressionRateTable\n" 
                "LDREQ   R2, [R3,#0x18]\n"  
                "STREQ   R2, [R6]\n"        
                "LDMEQFD SP!, {R4-R7,PC}\n" 
                "LDR     R12, =0x6FA10\n"   
                "LDR     R0, [R12]\n"       
                "LDR     R3, =0x6FA18\n"    
                "CMP     R0, #0\n"          
                "LDR     R1, [R3]\n"        
                "BEQ     loc_FF952458\n"    
                "LDR     R2, =0x6FA1C\n"    
                "LDR     R3, [R2]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FF95246C\n"    
                "B       loc_FF95245C\n"    
"loc_FF952458:\n"                           
                "LDR     R2, =0x6FA1C\n"    
"loc_FF95245C:\n"                           
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        
                "STR     R7, [R12]\n"       
                "B       loc_FF952520\n"    
"loc_FF95246C:\n"                           
                "LDR     R3, =0x6FA14\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R5, =table1\n" // + 0xFF9521E0
                "MOV     LR, R2,LSL#2\n"    
                "LDR     R3, [R5,LR]\n"     
                "LDR     R4, =table2\n" // + 0xFF9522C0
                "RSB     R12, R3, R0\n"     
                "LDR     R2, [R4,LR]\n"     
                "CMP     R12, #0\n"         
                "RSB     R0, R2, R0\n"      
                "BLE     loc_FF9524CC\n"    
                "ADD     R3, R5, #0x10\n"   
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R1, R1, #1\n"      
                "BGE     loc_FF9524C0\n"    
                "ADD     R3, R5, #0x20\n"   
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R1, R1, #2\n"      
                "ADDLT   R1, R1, #3\n"      
"loc_FF9524C0:\n"                           
          //    "CMP     R1, #0xE\n"     // -
          //    "MOVGE   R1, #0xE\n"     // -
                "CMP     R1, #0x1A\n"    // +   
                "MOVGE   R1, #0x1A\n"    // +   

                "B       loc_FF952504\n"    
"loc_FF9524CC:\n"                           
                "CMP     R0, #0\n"          
                "BGE     loc_FF952504\n"    
                "ADD     R3, R4, #0x10\n"   
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R0\n"          
                "SUBLE   R1, R1, #1\n"      
                "BLE     loc_FF9524FC\n"    
                "ADD     R3, R4, #0x20\n"   
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R0\n"          
                "SUBLE   R1, R1, #2\n"      
                "SUBGT   R1, R1, #3\n"      
"loc_FF9524FC:\n"                           
                "CMP     R1, #0\n"          
                "MOVLT   R1, #0\n"          
"loc_FF952504:\n"                           
                                        
                "LDR     R0, =0x6FA18\n"    
                "LDR     R3, [R0]\n"        
                "CMP     R1, R3\n"          
                "LDRNE   R2, =0x6FA1C\n"    
                "MOVNE   R3, #1\n"          
                "STRNE   R1, [R0]\n"        
                "STRNE   R3, [R2]\n"        
"loc_FF952520:\n"                           
                "LDR     R3, =0x6FA18\n"    
           //   "LDR     R1, =0x56C0\n"   // -
                "LDR     R1, =video_mode\n" //+
                "LDR     R0, [R3]\n"        
                "LDR     R2, =CompressionRateTable\n"   //+ FF9521A4
                "LDR     R12, [R1]\n"
                "LDR     R12, [R12]\n" //+       
                "LDR     LR, [R2,R0,LSL#2]\n" 
                "LDR     R3, =0x6FA10\n"    
                "CMP     R12, #1\n"         
                "STR     R7, [R3]\n"        
                "STR     LR, [R6]\n"        
           //   "MOVEQ   R3, #0xB\n"   // -

                "LDREQ   R3, =video_quality\n"          // +
                "LDREQ   R3, [R3]\n"                    // +
                "LDREQ   R3, [R3]\n"                    // +

                "STREQ   R3, [R6]\n"        
                "LDMFD   SP!, {R4-R7,PC}\n" 
 );
}
