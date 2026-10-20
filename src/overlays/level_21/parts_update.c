#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80087690.
 * Assembly SHA256 4900377fee472457deaff20daadd00b6139cb6ed17fd7f7b1045193a6cd54e87.
 * AI-generated; not human reviewed. Verified case C is adapted to every
 * original target instruction. Selector0 retains its original D_8006C5C8
 * branch and distinct raw-byte34/32 predicates. All raw access widths,
 * constants, helper arguments, frame offsets and shared entries are retained.
 * Units/fixed point, complete helper semantics and caller cadence remain
 * unresolved. Step is the original argument, not an inferred time unit.
 * Original1760 instructions and85 owned selectors/targets are mandatory.
 * The original0xE0-byte frame retains step at SP0x88, double at SP0x90.
 * Step() names destructive initialized T1 loads. Selector6 retains S0 radius,
 * S1 angle, S5 raw height and T1 MULT captures. Helper input widths retain
 * the complete original call values. Selector0xF uses the original SP0x50
 * vector and original128-byte-field store order. Selector0x3A uses the
 * original T1 double load. The shared removal is inside selector0x54.
 * Quad uses ordinary C allocation to FP. Every constraint input is initialized;
 * original MULT producers precede HI/LO captures. Empty compiler metadata
 * emits zero CPU instructions. C generates every CPU instruction. Compiler,
 * assembler, pipeline, flags, padding and all acceptance gates are unchanged.
 * Falsification: all native/linked words and conditional/internal targets,
 * all selectors, preserved data and full EXE/every-overlay retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Update87690Step() ({word9=frame.saved.step88;__asm__("":"=r"(word9):"0"(word9));word9;})
extern int Update87690D_8006C5C8 __asm__("D_8006C5C8");
#define Update87690Step() ({word9=frame.saved.step88;__asm__("":"=r"(word9):"0"(word9));word9;})
int Update87690func_8004F52C(void*,void*) __asm__("func_8004F52C");
int Update87690func_8004F554(void*,void*) __asm__("func_8004F554");
int Update87690func_8004F194(void*,void*,void*) __asm__("func_8004F194");
int Update87690func_8004F110(void*,int) __asm__("func_8004F110");
extern unsigned short Update87690Table658A0[] __asm__("D_800658A0");
extern unsigned short Update87690Table65920[] __asm__("D_80065920");
int Update87690func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
extern unsigned char Update87690D_8006E020[] __asm__("D_8006E020");
#define Update87690Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update87690func_8004E9E4(int) __asm__("func_8004E9E4");
int Update87690func_8004EA2C(int) __asm__("func_8004EA2C");
int Update87690func_8004F178(void*,void*) __asm__("func_8004F178");
int Update87690func_8004F504(void*,void*) __asm__("func_8004F504");
int Update87690func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update87690func_80056504(void*) __asm__("func_80056504");
extern int Update87690D_8006C644 __asm__("D_8006C644");
extern unsigned short Update87690Sin[] __asm__("D_80065920");
extern unsigned short Update87690Cos[] __asm__("D_800658A0");
extern int (*Update87690SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
int Update87690rand(void) __asm__("rand");
extern unsigned char *Update87690D_8006C554 __asm__("D_8006C554");
extern int Update87690D_8006C598 __asm__("D_8006C598");
extern int Update87690D_8006C640 __asm__("D_8006C640");
extern short Update87690D_8006E040 __asm__("D_8006E040");
extern int Update87690D_8006E344 __asm__("D_8006E344");
extern unsigned char Update87690D_80070328[] __asm__("D_80070328");
extern int Update87690Player48 __asm__("D_80070328 + 0x48");
extern int Update87690Player284 __asm__("D_80070328 + 0x284");
extern int Update87690Player280 __asm__("D_80070328 + 0x280");
#define Update87690High(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})
unsigned char *func_level_21_80087690(int initialStep) {
    register void *vector16 __asm__("$16");
    register void *vector17 __asm__("$17");
    int halfwordMinus1;
    int halfwordMinus2;
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[42];
        unsigned short halves[84];
        struct {
            int pad[30];
            volatile int step88;
            int pad8C;
            volatile int doubled90;
            int rest[9];
        }
        saved;
    }
    frame;
    register int scratch5 __asm__("$5");
    register int scratch7 __asm__("$7");
    register int scratch8 __asm__("$8");
    register int predicate3 __asm__("$3");
    int temp_a0_3;
    int temp_a0_5;
    int quadrupledStep;
    register int word9 __asm__("$9");
    register int var_a1 __asm__("$5");
    register int iteration __asm__("$16");
    register int predicate2 __asm__("$2");
    register int random2 __asm__("$2");
    register int halfword3 __asm__("$3");
    register int scratch3 __asm__("$3");
    int temp_v0_14;
    int temp_v0_16;
    unsigned short temp_a0_4;
    register int temp_a1 __asm__("$5");
    unsigned short temp_a1_2;
    register unsigned char *recordPlus1 __asm__("$18");
    register unsigned char *record __asm__("$19");
    register unsigned char *recordPlus4 __asm__("$22");
    register unsigned char *recordPlus24 __asm__("$23");
    unsigned char *var_v0;
    unsigned char temp_v0_10;
    unsigned char temp_v0_11;
    unsigned char temp_v0_13;
    unsigned char temp_v0_15;
    unsigned char temp_v0_17;
    unsigned char temp_v0_18;
    unsigned char temp_v0_19;
    unsigned char temp_v0_4;
    unsigned char temp_v0_5;
    unsigned char temp_v0_6;
    unsigned char temp_v0_7;
    unsigned char temp_v0_8;
    unsigned char temp_v0_9;
    unsigned char temp_v1;
    unsigned char temp_v1_10;
    register int scratch4 __asm__("$4");
    register int low19 __asm__("$19");
    register int savedLow22 __asm__("$22");
    int mode18;
    int maskedLow0;
    record = Update87690D_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    frame.saved.step88=incomingStep;
    __asm__ volatile("" : "=r"(record) : "0"(record) : "$4","memory");
    scratch4 = Update87690Field(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    if (scratch3 != scratch2) {
        recordPlus1=record+1;
        word9=frame.saved.step88;
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus24=record+0x18;
        __asm__("":"=r"(word9),"=r"(recordPlus24):"0"(word9),"1"(recordPlus24));
        word9*=2;
        frame.saved.doubled90=word9;
        __asm__ volatile("" ::: "memory");
        word9=frame.saved.step88;
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus4=record+4;
        __asm__("":"=r"(word9),"=r"(recordPlus4):"0"(word9),"1"(recordPlus4));
        quadrupledStep=word9*4;
        __asm__("":"=r"(quadrupledStep):"0"(quadrupledStep));
        scratch3=scratch4&255;
        __asm__("":"=r"(scratch3),"=r"(scratch4):"0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update87690D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update87690D_8006C598 == 0) {
                            goto dispatchRecord;
                        }
                        goto removeRecord;
                    }
                    goto nextRecord;
                }
            dispatchRecord:
                temp_v1 = *record;
                switch (temp_v1) {
                case 0x0:
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update87690Field(recordPlus1,short*,0x1D)!=0)Update87690Field(recordPlus1,unsigned short*,0x1B)=Update87690Field(recordPlus1,unsigned short*,0x1B)+1;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled90;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xC);
                    scratch2+=word9;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch2-=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xD);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2-=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    word9=frame.saved.step88;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    scratch4=scratch3+word9;
                    word9=1;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch4;
                    scratch3=Update87690D_8006C5C8;
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    if(scratch3==word9){
                        scratch2=scratch4&255;
                        predicate2=(unsigned int)scratch2<34;
                        if(!predicate2)goto removeRecord;
                        goto nextRecord;
                    }
                    scratch2=scratch4&255;
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0x1:
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update87690Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update87690Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch3=Update87690Field(recordPlus1,unsigned char*,9);
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch3+=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xC);
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    Update87690Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2+=Update87690Step();
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    goto checkMasked24;
                case 0x2:
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update87690Field(recordPlus1,short*,0x1D)!=0)
                    Update87690Field(recordPlus1,unsigned short*,0x1B)=Update87690Field(recordPlus1,unsigned short*,0x1B)+1;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "$8","memory");
                    word9=1;
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled90;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){
                        scratch2=scratch3-quadrupledStep;
                        Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    }
                    else Update87690Field(recordPlus1,unsigned char*,0xB)=0;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xC);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){
                        scratch2=scratch3-quadrupledStep;
                        Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }
                    else Update87690Field(recordPlus1,unsigned char*,0xC)=0;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xD);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){
                        __asm__ volatile("" : : "r"(quadrupledStep) : "memory");
                        scratch2=scratch3-quadrupledStep;
                        Update87690Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
                    else Update87690Field(recordPlus1,unsigned char*,0xD)=0;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2+=Update87690Step();
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$3","memory");
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0x3:
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update87690Field(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update87690Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    word9=1;
                    __asm__("" : "=r"(word9):"0"(word9));
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    scratch4=Update87690Field(recordPlus1,unsigned char*,0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4):"0"(scratch2),"1"(scratch4));
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch2+=3;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(scratch3==scratch4){
                        scratch3=Update87690Field(recordPlus1,unsigned char*,0xC);
                        scratch2=scratch4-4;
                        Update87690Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        scratch3-=4;
                        Update87690Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    }
                    else{
                        scratch2=scratch4+4;
                        Update87690Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xB);
                    scratch2-=4;
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2&=255;
                    __asm__ volatile("" : "=r"(scratch2):"0"(scratch2):"$3","memory");
                    if(scratch2==0)goto removeRecord;
                    __asm__ volatile("" ::: "$3","memory");
                    goto checkByte2;
                case 0x5:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=48)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    Update87690func_8004F52C(&frame.words[0],recordPlus4);
                    random2=Update87690rand();
                    halfword3=Update87690Field(recordPlus1,unsigned short*,0x17);
                    __asm__("" : "=r"(random2),"=r"(halfword3):"0"(random2),"1"(halfword3));
                    random2&=6;
                    halfword3-=3;
                    halfword3+=random2;
                    Update87690Field(recordPlus1,unsigned short*,0x17)=halfword3;
                    random2=Update87690rand();
                    vector16=&frame.words[4];
                    scratch4=(int)vector16;
                    playerEnd=recordPlus24;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd):"0"(scratch4),"1"(playerEnd));
                    random2&=6;
                    halfword3=Update87690Field(recordPlus1,unsigned short*,0x19);
                    scratch6=Update87690Field(recordPlus1,unsigned short*,0x1B);
                    __asm__("" : "=r"(random2),"=r"(halfword3),"=r"(scratch6):"0"(random2),"1"(halfword3),"2"(scratch6));
                    halfword3-=3;
                    halfword3+=random2;
                    scratch6-=1;
                    Update87690Field(recordPlus1,unsigned short*,0x19)=halfword3;
                    Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch6;
                    Update87690func_8004F554((void*)scratch4,playerEnd);
                    Update87690func_8004F110(vector16,2);
                    Update87690func_8004F194(&frame.words[0],&frame.words[0],vector16);
                    Update87690func_8004F504(recordPlus4,&frame.words[0]);
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2+=1;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                case 0x6:
                    {
                        register int radius16 __asm__("$16");
                        register int angle17 __asm__("$17");
                        register int height21 __asm__("$21");
                        register int product9 __asm__("$9");
                        playerEnd=Update87690Field(recordPlus1,unsigned char**,0x17);
                        Update87690func_8004F178(&frame.words[8],playerEnd);
                        scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                        radius16=scratch2<<6;
                        scratch2=Update87690Field(recordPlus1,short*,0x1D);
                        scratch3=frame.words[10];
                        scratch2<<=6;
                        height21=scratch3+scratch2;
                        scratch3=Update87690Field(recordPlus1,short*,0x1B);
                        angle17=radius16;
                        if(scratch3<radius16)radius16=scratch3;
                        scratch2=Update87690func_8004EA2C(angle17);
                        product9=radius16*scratch2;
                        scratch2=frame.words[8];
                        __asm__("" : "=r"(product9),"=r"(scratch2) : "0"(product9),"1"(scratch2));
                        scratch3=product9>>12;
                        scratch2+=scratch3;
                        frame.words[8]=scratch2;
                        scratch2=Update87690func_8004E9E4(angle17);
                        product9=radius16*scratch2;
                        scratch2=frame.words[9];
                        __asm__("" : "=r"(product9),"=r"(scratch2) : "0"(product9),"1"(scratch2));
                        scratch3=product9>>12;
                        scratch2+=scratch3;
                        frame.words[9]=scratch2;
                        scratch2=Update87690Field(recordPlus1,short*,7);
                        scratch2=(scratch2<<2)+64;
                        frame.words[10]=scratch2;
                        if(height21<scratch2)goto removeRecord;
                        Update87690func_8004F504(recordPlus4,&frame.words[8]);
                        scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                        scratch2++;
                        Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                        goto nextRecord;
                    }
                case 0x9:
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update87690Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update87690Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled90;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch3+=word9;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch2+=Update87690Step();
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0xA:
                    {
                        register void *temporary16 __asm__("$16");
                        scratch3=Update87690Player48;
                        if(scratch3==30 && Update87690Player280<0)goto removeRecord;
                        playerEnd=Update87690D_80070328+0x288;
                        __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                        if(Update87690Field(playerEnd,int*,0)!=0)goto removeRecord;
                        if(Update87690Player284==0)goto removeRecord;
                        temporary16=&frame.words[12];
                        Update87690func_8004F178(temporary16,playerEnd-0x288);
                        scratch2=Update87690func_8004EA2C(Update87690Field(recordPlus1, short *, 0x17));
                        scratch3=frame.words[12];
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2>>=4;
                        scratch3+=scratch2;
                        frame.words[12]=scratch3;
                        scratch2=Update87690func_8004E9E4(Update87690Field(recordPlus1, short *, 0x17));
                        scratch4=(int)recordPlus4;
                        playerEnd=(unsigned char*)temporary16;
                        __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch2) : "0"(scratch4),"1"(playerEnd),"2"(scratch2));
                        scratch2>>=4;
                        scratch3=frame.words[13];
                        scratch6=frame.words[14];
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                        scratch3+=scratch2;
                        scratch6+=256;
                        frame.words[13]=scratch3;
                        frame.words[14]=scratch6;
                        __asm__("" : "=r"(scratch6) : "0"(scratch6));
                        Update87690func_8004F504((void*)scratch4,playerEnd);
                        scratch4=Update87690Field(recordPlus1, unsigned short *, 0x17);
                        scratch4+=64;
                        Update87690Field(recordPlus1, unsigned short *, 0x17)=scratch4;
                        __asm__("" : "=r"(scratch4) : "0"(scratch4));
                        scratch4<<=16;
                        scratch2=Update87690D_8006E040;
                        __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                        scratch4>>=16;
                        scratch4-=scratch2;
                        scratch2=Update87690func_8004EA2C(scratch4&4095);
                        scratch3=0x60606061;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        if(scratch2<0)scratch2=-scratch2;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        high7=Update87690High(scratch2,scratch3);
                        scratch2>>=31;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2));
                        scratch3=high7>>6;
                        scratch3-=scratch2;
                        Update87690Field(recordPlus1, unsigned char *, 9)=scratch3;
                        goto nextRecord;
                    }
                case 0xB:
                    scratch2=Update87690Field(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){
                        scratch2=Update87690Field(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update87690Field(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch6) : "0"(scratch4),"1"(playerEnd),"2"(scratch6));
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=1;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update87690func_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 9);
                    word9=frame.saved.doubled90;
                    scratch3=Update87690Field(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update87690Field(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 0xA);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update87690Field(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update87690Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=quadrupledStep;
                    Update87690Field(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update87690Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update87690Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                case 0xC:
                    Update87690Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update87690Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update87690func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update87690Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update87690Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update87690Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update87690Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update87690Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update87690Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update87690Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0xD:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=28)goto removeRecord;
                    if(Update87690Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update87690Field(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update87690Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__ volatile("" ::: "$8","memory");
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$8","memory");
                    word9=1;
                    __asm__("" : "=r"(scratch2),"=r"(word9) : "0"(scratch2),"1"(word9));
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled90;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(word9),"=r"(scratch3) : "0"(scratch2),"1"(word9),"2"(scratch3));
                    scratch2+=word9;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    if((unsigned int)scratch3>=13){
                        scratch2=scratch3-12;
                        scratch2*=8;
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        scratch2=word9-scratch2;
                        if(scratch2<0)scratch2=0;
                        scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                        Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=64;
                        scratch3-=12;
                        scratch3*=4;
                        scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        goto zeroDAndAge;
                    }
                    else{
                        predicate2=(unsigned int)scratch3<5;
                        __asm__("" : "=r"(predicate2) : "0"(predicate2));
                        if(!predicate2){
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9) : "memory");
                            scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                            scratch2=-128;
                            Update87690Field(recordPlus1,unsigned char*,0xB)=word9;
                            Update87690Field(recordPlus1,unsigned char*,0xD)=0;
                            scratch3-=4;
                            scratch3*=8;
                            scratch2-=scratch3;
                            Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        }
                        else{
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9) : "memory");
                            scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                            __asm__("" : "=r"(scratch2),"=r"(word9) : "0"(scratch2),"1"(word9));
                            Update87690Field(recordPlus1,unsigned char*,0xB)=word9;
                            Update87690Field(recordPlus1,unsigned char*,0xC)=word9;
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            scratch2*=32;
                            scratch2=word9-scratch2;
                            if(scratch2<0)scratch2=0;
                            Update87690Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        }
                    }
                    goto sharedOriginalAge;
                case 0xE:
                    if (Update87690Field(recordPlus1, unsigned char *, 2) != 0) {
                        halfwordMinus1 = Update87690Field(recordPlus1, unsigned short *, 0x1B) - 1;
                        Update87690Field(recordPlus1, unsigned short *, 0x1B) = halfwordMinus1;
                        if ((short) halfwordMinus1 == -1) {
                            if (Update87690Field(recordPlus1, unsigned char *, 1) != 0) {
                                Update87690SpawnParticle(1, 0x12, (Vector3D *) recordPlus4, 0);
                            }
                            goto removeRecord;
                        }
                        if (Update87690Field(recordPlus1, unsigned char *, 2) != 0) {
                            scratch2=Update87690Field(recordPlus1,unsigned short*,0x17);
                            scratch3=Update87690Field(recordPlus1,unsigned short*,0x11);
                            scratch4=Update87690Field(recordPlus1,unsigned short*,0x13);
                            temp_a1=Update87690Field(recordPlus1,unsigned short*,0x15);
                            scratch6=Update87690Field(recordPlus1,unsigned char*,0x1E);
                            __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(temp_a1),"=r"(scratch6):"0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(temp_a1),"4"(scratch6));
                            scratch2+=scratch3;
                            Update87690Field(recordPlus1,unsigned short*,0x17)=scratch2;
                            scratch2=Update87690Field(recordPlus1,unsigned short*,0x19);
                            scratch3=Update87690Field(recordPlus1,unsigned char*,0x1D);
                            scratch2+=scratch4;
                            scratch3*=2;
                            Update87690Field(recordPlus1,unsigned short*,0x19)=scratch2;
                            scratch3=Update87690Field(Update87690Table65920,unsigned short*,scratch3);
                            scratch2=Update87690Field(recordPlus1,unsigned short*,0x17);
                            scratch4=Update87690Field(recordPlus1,unsigned char*,0x1D);
                            __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4):"0"(scratch3),"1"(scratch2),"2"(scratch4));
                            scratch3=(scratch3<<16)>>23;
                            scratch2+=scratch3;
                            scratch4*=2;
                            Update87690Field(recordPlus1,unsigned short*,3)=scratch2;
                            scratch4=Update87690Field(Update87690Table658A0,unsigned short*,scratch4);
                            scratch2=Update87690Field(recordPlus1,unsigned short*,7);
                            scratch3=Update87690Field(recordPlus1,unsigned char*,0x1D);
                            __asm__("" : "=r"(scratch4),"=r"(scratch2),"=r"(scratch3),"=r"(temp_a1),"=r"(scratch6):"0"(scratch4),"1"(scratch2),"2"(scratch3),"3"(temp_a1),"4"(scratch6));
                            scratch2+=temp_a1;
                            scratch3+=scratch6;
                            scratch4<<=16;
                            Update87690Field(recordPlus1,unsigned short*,7)=scratch2;
                            scratch2=Update87690Field(recordPlus1,unsigned short*,0x19);
                            scratch4>>=23;
                            Update87690Field(recordPlus1,unsigned char*,0x1D)=scratch3;
                            scratch2+=scratch4;
                            Update87690Field(recordPlus1,unsigned short*,5)=scratch2;
                        }
                        goto nextRecord;
                    }
                    halfwordMinus2=Update87690Field(recordPlus1,unsigned short*,0x1B)-2;
                    Update87690Field(recordPlus1,unsigned short*,0x1B)=halfwordMinus2;
                    if((halfwordMinus2<<16)<=0)goto removeRecord;
                    scratch3=Update87690Field(recordPlus1,unsigned short*,0x11);
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4):"0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3*=2;
                    scratch2+=scratch3;
                    scratch4*=2;
                    Update87690Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x19);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1D);
                    scratch2+=scratch4;
                    scratch3*=2;
                    Update87690Field(recordPlus1,unsigned short*,0x19)=scratch2;
                    scratch2=Update87690Field(Update87690Table65920,unsigned short*,scratch3);
                    scratch3=Update87690Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2=(scratch2<<16)>>23;
                    scratch3+=scratch2;
                    scratch4*=2;
                    Update87690Field(recordPlus1,unsigned short*,3)=scratch3;
                    __asm__ volatile("" ::: "$3","memory");
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1D);
                    scratch2=Update87690Field(recordPlus1,unsigned short*,7);
                    scratch3*=2;
                    temp_a1=Update87690Field(Update87690Table658A0,unsigned short*,scratch3);
                    scratch2+=scratch4;
                    Update87690Field(recordPlus1,unsigned short*,7)=scratch2;
                    __asm__ volatile("" ::: "$3","memory");
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0x1E);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(temp_a1):"0"(scratch2),"1"(scratch3),"2"(temp_a1));
                    scratch2*=2;
                    scratch3+=scratch2;
                    temp_a1<<=16;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x19);
                    temp_a1>>=23;
                    Update87690Field(recordPlus1,unsigned char*,0x1D)=scratch3;
                    scratch2+=temp_a1;
                    Update87690Field(recordPlus1,unsigned short*,5)=scratch2;
                    goto nextRecord;
                case 0xF:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=48)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    vector17=&frame.words[16];
                    Update87690func_8004F52C(vector17,recordPlus4);
                    random2=Update87690rand();
                    halfword3=Update87690Field(recordPlus1,unsigned short*,0x17);
                    __asm__("" : "=r"(random2),"=r"(halfword3):"0"(random2),"1"(halfword3));
                    random2&=6;
                    halfword3-=3;
                    halfword3+=random2;
                    Update87690Field(recordPlus1,unsigned short*,0x17)=halfword3;
                    random2=Update87690rand();
                    vector16=&frame.words[20];
                    scratch4=(int)vector16;
                    playerEnd=recordPlus24;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd):"0"(scratch4),"1"(playerEnd));
                    random2&=6;
                    halfword3=Update87690Field(recordPlus1,unsigned short*,0x19);
                    scratch6=Update87690Field(recordPlus1,unsigned short*,0x1B);
                    __asm__("" : "=r"(random2),"=r"(halfword3),"=r"(scratch6):"0"(random2),"1"(halfword3),"2"(scratch6));
                    halfword3-=3;
                    halfword3+=random2;
                    scratch6-=1;
                    Update87690Field(recordPlus1,unsigned short*,0x19)=halfword3;
                    Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch6;
                    Update87690func_8004F554((void*)scratch4,playerEnd);
                    Update87690func_8004F194(vector17,vector17,vector16);
                    Update87690func_8004F504(recordPlus4,vector17);
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2+=1;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    Update87690func_8004F1C8(vector16,vector17,Update87690D_8006E020);
                    scratch4=frame.words[20];
                    scratch3=frame.words[21];
                    scratch2=frame.words[22];
                    __asm__("" : "=r"(scratch4),"=r"(scratch3),"=r"(scratch2):"0"(scratch4),"1"(scratch3),"2"(scratch2));
                    if(scratch4<0)scratch4=-scratch4;
                    if(scratch3<0)scratch3=-scratch3;
                    scratch4+=scratch3;
                    __asm__ volatile("" : "=r"(scratch4),"=r"(scratch2):"0"(scratch4),"1"(scratch2):"memory");
                    if(scratch2<0)scratch2=-scratch2;
                    scratch4+=scratch2;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0);
                    scratch2=3;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    if(scratch3==scratch2){
                        predicate2=scratch4<0x3001;
                        __asm__("" : "=r"(predicate2):"0"(predicate2));
                        if(predicate2)goto nextRecord;
                        scratch2=255;
                        Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update87690Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        scratch2=4;
                        Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                        Update87690Field(recordPlus1,unsigned char*,0)=0;
                        Update87690Field(recordPlus1,unsigned char*,0xE)=64;
                    }
                    else{
                        predicate2=scratch4<0x2800;
                        __asm__("" : "=r"(predicate2):"0"(predicate2));
                        if(!predicate2)goto nextRecord;
                        scratch2=3;
                        word9=128;
                        __asm__("":"=r"(scratch2),"=r"(word9):"0"(scratch2),"1"(word9));
                        Update87690Field(recordPlus1,unsigned char*,0xB)=word9;
                        Update87690Field(recordPlus1,unsigned char*,0xC)=word9;
                        __asm__ volatile("" ::: "memory");
                        Update87690Field(recordPlus1,unsigned char*,0)=scratch2;
                        scratch2=4;
                        Update87690Field(recordPlus1,unsigned char*,0x10)=scratch2;
                        scratch2=44;
                        Update87690Field(recordPlus1,unsigned char*,0xD)=word9;
                        Update87690Field(recordPlus1,unsigned char*,0xE)=scratch2;
                        Update87690Field(recordPlus1,unsigned char*,0xF)=0;
                        scratch2=Update87690rand();
                        scratch4=scratch2&7;
                        scratch2=scratch4+18;
                        Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                        scratch2=scratch4+15;
                        Update87690Field(recordPlus1,unsigned char*,0xA)=scratch2;
                    }
                    goto nextRecord;
                case 0x12:
                    if (Update87690Field(recordPlus1, unsigned char *, 2) != 0) {
                        scratch3 = Update87690Field(recordPlus1, unsigned char *, 9);
                        if (scratch3 >= 5U) {
                            scratch2=scratch3-1;
                            __asm__("" : "=r"(scratch2):"0"(scratch2));
                            Update87690Field(recordPlus1, unsigned char *, 9) = scratch2;
                            goto nextRecord;
                        }
                    }
                    goto removeRecord;
                case 0x21:
                    Update87690func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update87690Field(recordPlus1, short *, 0x1D) != 0) {
                        Update87690Field(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xB);
                    word9=frame.saved.doubled90;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2),"=r"(word9),"=r"(scratch3) : "0"(scratch2),"1"(word9),"2"(scratch3));
                    scratch4=scratch2-word9;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    word9=1;
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled90;
                    scratch3+=word9;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch3;
                    if (scratch4 < 0) {
                        scratch4 = 0;
                    }
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("":"=r"(scratch2):"0"(scratch2):"memory");
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch4;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch4;
                    Update87690Field(recordPlus1,unsigned char*,0xD)=scratch4;
                    scratch2+=Update87690Step();
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=32)goto removeRecord;
                    if(Update87690Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    if(scratch4==0)goto removeRecord;
                    goto nextRecord;
                case 0x29:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=1;
                    scratch8=scratch2&255;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    if((unsigned int)scratch3<(unsigned int)scratch8){
                        if(Update87690Field(recordPlus1,unsigned char*,0x1E)==0)goto removeRecord;
                        Update87690SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update87690Field(recordPlus1,short*,0x17);
                    scratch7=Update87690Field(recordPlus1,short*,0x11);
                    __asm__("" : "=r"(scratch2),"=r"(scratch7) : "0"(scratch2),"1"(scratch7));
                    scratch2-=scratch7;
                    scratch2*=scratch8;
                    scratch8=scratch2/scratch3;
                    scratch6=Update87690Field(recordPlus1,short*,0x13);
                    scratch2=Update87690Field(recordPlus1,short*,0x19);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                    scratch2-=scratch6;
                    scratch2*=scratch3;
                    scratch5=Update87690Field(recordPlus1,unsigned char*,0x1D);
                    scratch5=scratch2/scratch5;
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x15);
                    __asm__ volatile("" : "=r"(scratch4) : "0"(scratch4) : "memory");
                    scratch3=Update87690Field(recordPlus1,unsigned short*,0x15);
                    scratch2=Update87690Field(recordPlus1,unsigned short*,7);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=2;
                    Update87690Field(recordPlus1,unsigned short*,0x15)=scratch3;
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2+=scratch4;
                    Update87690Field(recordPlus1,unsigned short*,7)=scratch2;
                    scratch2=Update87690D_8006C644;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch7+=scratch8;
                    Update87690Field(recordPlus1,unsigned short*,3)=scratch7;
                    scratch6+=scratch5;
                    Update87690Field(recordPlus1,unsigned short*,5)=scratch6;
                    scratch2=Update87690Sin[scratch2];
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=26;
                    scratch2+=10;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update87690D_8006C644;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch2=Update87690Cos[scratch2];
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=27;
                    scratch2+=6;
                    Update87690Field(recordPlus1,unsigned char*,0xA)=scratch2;
                    goto nextRecord;
                case 0x2A:
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update87690Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xB);
                    scratch4=Update87690Field(recordPlus1,short*,0x11);
                    scratch5=Update87690Field(recordPlus1,short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(scratch5) : "0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(scratch5));
                    scratch2+=2;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=6;
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=6;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    scratch2=Update87690Field(recordPlus1,int*,0x17);
                    scratch3-=6;
                    Update87690Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch3=Update87690Field(recordPlus1,int*,0x1B);
                    scratch2+=scratch4;
                    Update87690Field(recordPlus1,int*,0x17)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update87690Field(recordPlus1,int*,0x17);
                    scratch3+=scratch5;
                    Update87690Field(recordPlus1,int*,0x1B)=scratch3;
                    __asm__ volatile("" ::: "memory");
                    scratch3=Update87690Field(recordPlus1,int*,0x1B);
                    scratch2>>=2;
                    scratch3>>=2;
                    Update87690Field(recordPlus1,unsigned short*,3)=scratch2;
                    Update87690Field(recordPlus1,unsigned short*,5)=scratch3;
                    goto nextRecord;
                case 0x2B:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch2<4)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,short*,0x17);
                    temp_a1=3;
                    if(scratch2!=0)temp_a1=2;
                    scratch4=Update87690Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch4),"=r"(temp_a1) : "0"(scratch4),"1"(temp_a1) : "memory");
                    scratch3=Update87690Field(recordPlus1,short*,0x17);
                    scratch2=scratch4+1;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(scratch3!=0){
                        scratch2=scratch4+2;
                        Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xB);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=temp_a1;
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=temp_a1;
                    Update87690Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2-=temp_a1;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    goto nextRecord;
                case 0x2C:
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x11);
                    scratch3=Update87690Field(recordPlus1,unsigned short*,0x19);
                    scratch5=Update87690Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3),"=r"(scratch5) : "0"(scratch2),"1"(scratch4),"2"(scratch3),"3"(scratch5));
                    scratch2+=scratch4;
                    Update87690Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,7);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x15);
                    scratch3+=scratch5;
                    Update87690Field(recordPlus1,unsigned short*,0x19)=scratch3;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1B);
                    scratch2+=scratch4;
                    scratch3*=2;
                    Update87690Field(recordPlus1,unsigned short*,7)=scratch2;
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch3=Update87690Field(Update87690Sin,unsigned short*,scratch3);
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update87690Field(recordPlus1,unsigned char*,0x1B);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=24;
                    scratch2+=scratch3;
                    scratch4*=2;
                    Update87690Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0x1B);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0x1C);
                    scratch4=Update87690Field(Update87690Cos,unsigned short*,scratch4);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2+=scratch3;
                    scratch4<<=16;
                    scratch4>>=24;
                    Update87690Field(recordPlus1,unsigned char*,0x1B)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x19);
                    scratch3=Update87690D_8006C640;
                    scratch2+=scratch4;
                    scratch3&=3;
                    Update87690Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch3==0){
                        scratch2=Update87690Field(recordPlus1,short*,0x15);
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        if(scratch2<9){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update87690Field(recordPlus1,unsigned short*,0x15)=scratch2;
                        }
                        scratch3=Update87690Field(recordPlus1,unsigned char*,9);
                        if((unsigned int)scratch3<20){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                    }
                    scratch2=Update87690Field(recordPlus1,short*,7);
                    scratch3=Update87690Field(recordPlus1,short*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2>=scratch3){
                        scratch3=Update87690Field(recordPlus1,unsigned char*,0x10);
                        scratch2=3;
                        if(scratch3!=scratch2)goto removeRecord;
                    sharedSpawn43:
                        Update87690SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    if(scratch2==0)goto removeRecord;
                    __asm__ volatile("" ::: "memory");
                    goto checkByte2;
                case 0x2E:
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update87690Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=3;
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=8;
                    Update87690Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=8;
                    scratch3-=8;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update87690Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto nextRecord;
                case 0x3A:
                    if((unsigned int)Update87690Field(recordPlus1,unsigned char*,1)>=28)goto removeRecord;
                    Update87690func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update87690Field(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update87690Field(recordPlus1,unsigned short*,0x1B);
                        scratch2++;
                        Update87690Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    word9=1;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2=word9-scratch2;
                    Update87690Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,9);
                    {
                        register int originalDouble9 __asm__("$9")=frame.saved.doubled90;
                        __asm__("" : "=r"(originalDouble9),"=r"(scratch3),"=r"(scratch2) : "0"(originalDouble9),"1"(scratch3),"2"(scratch2));
                        scratch4=scratch3&255;
                        __asm__("" : "=r"(scratch4),"=r"(originalDouble9):"0"(scratch4),"1"(originalDouble9));
                        scratch2+=originalDouble9;
                    }
                    Update87690Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(!(predicate2=(unsigned int)scratch4<13)){
                        scratch2=(scratch4-12)<<2;
                        scratch3=64;
                        scratch3-=scratch2;
                        if(scratch3<0)scratch3=0;
                        __asm__ volatile("" ::: "$8","memory");
                        scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"$8","memory");
                        word9=128;
                        __asm__("" : "=r"(word9),"=r"(scratch2),"=r"(scratch3):"0"(word9),"1"(scratch2),"2"(scratch3));
                        Update87690Field(recordPlus1,unsigned char*,0xB)=scratch3;
                        __asm__ volatile("" : "=r"(scratch2),"=r"(word9):"0"(scratch2),"1"(word9):"memory");
                        scratch2=(scratch2-12)<<3;
                        scratch3=word9-scratch2;
                        if(scratch3<0)scratch3=0;
                        Update87690Field(recordPlus1,unsigned char*,0xC)=scratch3;
                        goto zeroDAndAge;
                    }
                    else if(!(predicate2=(unsigned int)scratch4<5)){
                        scratch3=(scratch3-4)<<3;
                        scratch2=-128;
                        scratch2-=scratch3;
                        Update87690Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        word9=128;
                        __asm__("" : "=r"(word9):"0"(word9));
                        Update87690Field(recordPlus1,unsigned char*,0xC)=word9;
                    zeroDAndAge:
                        Update87690Field(recordPlus1,unsigned char*,0xD)=0;
                    }
                sharedOriginalAge:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2+=Update87690Step();
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                case 0x3B:
                    Update87690Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update87690Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update87690func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update87690D_8006C640 & 1) {
                        Update87690Field(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update87690Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update87690Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update87690Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update87690Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update87690Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update87690Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update87690Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0x42:
                    word9=frame.saved.step88;
                    __asm__("":"=r"(word9):"0"(word9));
                    iteration=0;
                    if(word9>0) {
                        do {
                            if (Update87690Field(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update87690Field(recordPlus1, unsigned short *, 3);
                                scratch4=Update87690Field(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update87690Field(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update87690Field(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update87690Field(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update87690Field(recordPlus1, unsigned short *, 7);
                                scratch4=Update87690Field(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update87690Field(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update87690Field(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update87690Field(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update87690rand();
                                    halfword3=Update87690Field(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update87690Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update87690rand();
                                    halfword3=Update87690Field(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update87690Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update87690rand();
                                    halfword3=Update87690Field(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update87690Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                            scratch2+=1;
                            Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                            word9=frame.saved.step88;
                            __asm__("":"=r"(word9):"0"(word9));
                            __asm__("":"=r"(iteration),"=r"(word9):"0"(iteration),"1"(word9));
                            iteration+=1;
                            predicate2=iteration<word9;
                            __asm__("":"=r"(predicate2):"0"(predicate2));
                        }
                        while(predicate2);
                    }
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                checkMasked24:
                    predicate2=(unsigned int)scratch2<24;
                    goto checkPredicate;
                checkPredicate:
                    if(predicate2==0)goto removeRecord;
                checkByte2:
                    if(Update87690Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                case 0x46:
                    temp_v0_11 = Update87690Field(recordPlus1, unsigned char *, 1) + 1;
                    Update87690Field(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update87690Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update87690Field(recordPlus1, unsigned short *, 9) - (short) Update87690Field(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[48] = (unsigned short) temp_a0_3;
                        frame.halves[49] = (unsigned short) ((int) ((short) Update87690Field(recordPlus1, unsigned short *, 0xB) - (short) Update87690Field(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[50] = (unsigned short) ((int) ((short) Update87690Field(recordPlus1, unsigned short *, 0xD) - (short) Update87690Field(recordPlus1, unsigned short *, 7)) >> 1);
                        Update87690Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update87690Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 5) + frame.halves[49]);
                        Update87690Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 7) + frame.halves[50]);
                        random2=Update87690rand();
                        halfword3=frame.halves[48];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[48]=halfword3;
                        random2=Update87690rand();
                        halfword3=frame.halves[49];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[49]=halfword3;
                        if (Update87690Field(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[50] -= 1;
                        }
                        random2=Update87690Field(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[48];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update87690Field(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update87690Field(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[49];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update87690Field(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update87690Field(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[50];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update87690Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update87690Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128){
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            Update87690Field(recordPlus1,unsigned char*,0xF)=word9;
                        }
                        temp_v0_13 = Update87690Field(recordPlus1, unsigned char *, 0x10) - 4;
                        Update87690Field(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update87690Field(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update87690Field(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update87690Field(recordPlus1, unsigned char *, 0x13) - 3;
                        Update87690Field(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update87690Field(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        temp_v0_15 = Update87690Field(recordPlus1, unsigned char *, 0x14) - 4;
                        Update87690Field(recordPlus1, unsigned char *, 0x14) = temp_v0_15;
                        if ((unsigned int) (temp_v0_15 & 0xFF) < 0x80U) {
                            __asm__ volatile("" ::: "$9","memory");
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            Update87690Field(recordPlus1,unsigned char*,0x14)=word9;
                        }
                        temp_v0_16 = (unsigned char) Update87690Field(recordPlus1, unsigned char *, 0x15) - 6;
                        Update87690Field(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update87690Field(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x47:
                    temp_v0_17 = Update87690Field(recordPlus1, unsigned char *, 1) + 1;
                    Update87690Field(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update87690Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[26] = (short) Update87690Field(recordPlus1, unsigned short *, 9) - (short) Update87690Field(recordPlus1, unsigned short *, 3);
                        frame.words[27] = (short) Update87690Field(recordPlus1, unsigned short *, 0xB) - (short) Update87690Field(recordPlus1, unsigned short *, 5);
                        frame.words[28] = (short) Update87690Field(recordPlus1, unsigned short *, 0xD) - (short) Update87690Field(recordPlus1, unsigned short *, 7);
                        random2=Update87690rand();
                        halfword3=frame.words[26];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[26]=halfword3;
                        random2=Update87690rand();
                        halfword3=frame.words[27];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[27]=halfword3;
                        random2=Update87690rand();
                        halfword3=frame.words[28];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[28]=halfword3;
                        Update87690Field(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update87690Field(recordPlus1, unsigned short *, 9) + frame.words[26]);
                        Update87690Field(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update87690Field(recordPlus1, unsigned short *, 0xB) + frame.words[27]);
                        Update87690Field(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update87690Field(recordPlus1, unsigned short *, 0xD) + frame.words[28]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[26];
                        scratch2=Update87690Field(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update87690Field(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[27];
                        scratch2=Update87690Field(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update87690Field(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[28];
                        scratch3=Update87690Field(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update87690Field(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update87690Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update87690Field(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update87690Field(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update87690Field(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update87690Field(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update87690Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update87690Field(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update87690Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x48:
                    temp_v0_18 = Update87690Field(recordPlus1, unsigned char *, 1) + 1;
                    Update87690Field(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update87690Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[24] = (int) ((short) Update87690Field(recordPlus1, unsigned short *, 3) - (short) Update87690Field(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[25] = (int) ((short) Update87690Field(recordPlus1, unsigned short *, 5) - (short) Update87690Field(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[26] = (int) ((short) Update87690Field(recordPlus1, unsigned short *, 7) - (short) Update87690Field(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update87690rand();
                        halfword3=frame.words[24];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[24]=halfword3;
                        random2=Update87690rand();
                        halfword3=frame.words[25];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[25]=halfword3;
                        random2=Update87690rand();
                        halfword3=frame.words[26];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[26]=halfword3;
                        Update87690Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 3) + frame.words[24]);
                        Update87690Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 5) + frame.words[25]);
                        Update87690Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 7) + frame.words[26]);
                        __asm__ __volatile__("" ::: "memory");
                        Update87690Field(recordPlus1, unsigned short *, 9) = (short) (Update87690Field(recordPlus1, unsigned short *, 3) - (frame.words[24] * 2));
                        Update87690Field(recordPlus1, unsigned short *, 0xB) = (short) (Update87690Field(recordPlus1, unsigned short *, 5) - (frame.words[25] * 2));
                        Update87690Field(recordPlus1, unsigned short *, 0xD) = (short) (Update87690Field(recordPlus1, unsigned short *, 7) - (frame.words[26] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4A:
                    scratch2=Update87690Field(recordPlus1,unsigned short*,3);
                    scratch3=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0xF);
                    temp_a1=Update87690Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(temp_a1):"0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(temp_a1));
                    scratch6=scratch3+1;
                    scratch2+=scratch4;
                    Update87690Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,5);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x11);
                    scratch3=Update87690Field(recordPlus1,unsigned short*,7);
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch6;
                    scratch2+=scratch4;
                    Update87690Field(recordPlus1,unsigned short*,5)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,0xC);
                    scratch3+=temp_a1;
                    Update87690Field(recordPlus1,unsigned short*,7)=scratch3;
                    scratch3=Update87690Field(recordPlus1,unsigned char*,2);
                    scratch2-=15;
                    Update87690Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    scratch2=scratch6&255;
                    if((unsigned int)scratch2>=17)goto removeRecord;
                    recordPlus1+=32;
                    break;
                case 0x4E:
                    temp_v0_19 = Update87690Field(recordPlus1, unsigned char *, 1) + 1;
                    Update87690Field(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update87690Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update87690Field(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update87690Field(recordPlus1, unsigned short *, 0x13);
                        Update87690Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 3) + Update87690Field(recordPlus1, unsigned short *, 0xF));
                        Update87690Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update87690Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update87690rand();
                        halfword3=Update87690Field(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update87690Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update87690rand();
                        halfword3=Update87690Field(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update87690Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update87690rand();
                        halfword3=Update87690Field(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update87690Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update87690Field(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update87690Field(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update87690Field(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update87690Field(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update87690Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update87690Field(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update87690Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update87690Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4F:
                    temp_a0_5 = (int) ((short) Update87690Field(recordPlus1, unsigned short *, 9) - (short) Update87690Field(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[48] = (unsigned short) temp_a0_5;
                    frame.halves[49] = (unsigned short) ((int) ((short) Update87690Field(recordPlus1, unsigned short *, 0xB) - (short) Update87690Field(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[50] = (unsigned short) ((int) ((short) Update87690Field(recordPlus1, unsigned short *, 0xD) - (short) Update87690Field(recordPlus1, unsigned short *, 7)) >> 1);
                    Update87690Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update87690Field(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update87690Field(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[49];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update87690Field(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update87690Field(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[50];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update87690Field(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update87690Field(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[48];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update87690Field(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update87690Field(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[49];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update87690Field(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update87690Field(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[50];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update87690Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update87690Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update87690Field(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update87690Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update87690Field(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update87690Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update87690Field(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update87690Field(recordPlus1, unsigned char *, 0x13);
                    Update87690Field(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update87690Field(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update87690Field(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                case 0x52:
                    scratch2=Update87690Field(recordPlus1,unsigned short*,7);
                    scratch3=Update87690Field(recordPlus1,unsigned short*,0xD);
                    scratch2+=48;
                    scratch3+=48;
                    Update87690Field(recordPlus1,unsigned short*,0xD)=scratch3;
                    scratch3=(short)scratch3;
                    Update87690Field(recordPlus1,unsigned short*,7)=scratch2;
                    if(scratch3<0)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,int*,0x17);
                    if(scratch2<scratch3)goto removeRecord;
                    recordPlus1+=32;
                    break;
                case 0x54:
                    scratch2=Update87690Field(recordPlus1,unsigned char*,1);
                    scratch2+=1;
                    Update87690Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=8)goto removeRecord;
                    scratch2=Update87690Field(recordPlus1,unsigned char*,2);
                    if(scratch2!=0)goto surviving54;
                removeRecord:
                    Update87690func_80056504(record);
                    recordPlus1+=32;
                    break;
                surviving54:
                    scratch2=Update87690Field(recordPlus1,unsigned short*,3);
                    scratch3=Update87690Field(recordPlus1,unsigned short*,0xF);
                    scratch4=Update87690Field(recordPlus1,unsigned short*,0x11);
                    temp_a1=Update87690Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(temp_a1) : "0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(temp_a1));
                    scratch2+=scratch3;
                    Update87690Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update87690Field(recordPlus1,unsigned short*,5);
                    scratch3=Update87690Field(recordPlus1,unsigned short*,7);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch4;
                    scratch3+=temp_a1;
                    Update87690Field(recordPlus1,unsigned short*,5)=scratch2;
                    Update87690Field(recordPlus1,unsigned short*,7)=scratch3;
                    goto nextRecord;
                    default:goto nextRecord;
                }
            }
            else {
            nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus24+=0x20;
            recordPlus4+=0x20;
            scratch4 = *recordPlus1;
            __asm__("" : "=r"(scratch4) : "0"(scratch4));
            __asm__ __volatile__("" ::: "$2", "memory");
            scratch2=255;
            __asm__("" : "=r"(scratch2) : "0"(scratch2));
            scratch3 = scratch4 & 0xFF;
            __asm__("" : "=r"(scratch4),"=r"(scratch3),"=r"(scratch2) : "0"(scratch4),"1"(scratch3),"2"(scratch2));
            record += 0x20;
        }
        while (scratch3 != scratch2);
    }
    return record;
}
#undef Update87690High
#undef Update87690Field
#undef Update87690Step
#undef Update87690Step
