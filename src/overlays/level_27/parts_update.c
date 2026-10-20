#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-derived SCUS-94467 Rev0 C.
 * Source: asm/nonmatchings/overlays/level_27/parts_update/func_level_27_80085DF0.s; SHA256 90795dd49daae319741bbe350ab1a4093ab1e1accea5a6c6c2d12714459da8ea.
 * Complete original rows/selector table: build/sibling6095.func_level_27_80085DF0.json.
 * Reuses verified level17 update C and level31 selector22 C. Original27
 * independently establishes all selector differences, raw field widths,
 * signed arithmetic, scratch locations, register roles and callback calls.
 * Selector22 has54 identical original instructions; selector26/29 are
 * translated from original rows436..585. Units/fixed-point interpretations,
 * helper/global producer-consumer chains and runtime verification remain
 * unresolved. Cadence: per invocation, frame rate unproven. Falsification:
 * native and linked words/targets plus full executable/all overlay hashes.
 */
#define Update85DF0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update85DF0func_8004E9E4(short) __asm__("func_8004E9E4");
int Update85DF0func_8004EA2C(short) __asm__("func_8004EA2C");
int Update85DF0func_8004F178(void*,void*) __asm__("func_8004F178");
int Update85DF0func_8004F504(void*,void*) __asm__("func_8004F504");
int Update85DF0func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update85DF0func_80056504(void*) __asm__("func_80056504");
int Update85DF0func_800359A4(void*,int) __asm__("func_800359A4");
extern int Update85DF0D_8006C648 __asm__("D_8006C648");
int Update85DF0func_8004F0E8(void*,int) __asm__("func_8004F0E8");
int Update85DF0func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Update85DF0func_8004EDE8(void*,int) __asm__("func_8004EDE8");
extern unsigned char Update85DF0D_8006E020[] __asm__("D_8006E020");
int Update85DF0rand(void) __asm__("rand");
extern unsigned char *Update85DF0D_8006C554 __asm__("D_8006C554");
extern int Update85DF0D_8006C598 __asm__("D_8006C598");
extern int Update85DF0D_8006C640 __asm__("D_8006C640");
extern short Update85DF0D_8006E040 __asm__("D_8006E040");
extern int Update85DF0D_8006E344 __asm__("D_8006E344");
extern unsigned char Update85DF0D_80070328[] __asm__("D_80070328");
extern int Update85DF0Player48 __asm__("D_80070328 + 0x48");
extern int Update85DF0Player284 __asm__("D_80070328 + 0x284");
extern int Update85DF0Player280 __asm__("D_80070328 + 0x280");
#define Update85DF0High(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})
extern int (*Update85DF0SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
extern unsigned char Update85DF0Table658A0[] __asm__("D_800658A0");
extern unsigned char Update85DF0Table65920[] __asm__("D_80065920");
extern void *Update85DF0D_8006C550 __asm__("D_8006C550");
int Update85DF0func_8004F554(void*,void*) __asm__("func_8004F554");
int Update85DF0func_8004F334(void*,void*) __asm__("func_8004F334");
int Update85DF0func_8001BA30(void*,int,int,int,int,int) __asm__("func_8001BA30");
int Update85DF0func_80019194(void*,int) __asm__("func_80019194");
int Update85DF0func_8004E880(int,int,int) __asm__("func_8004E880");
unsigned char *func_level_27_80085DF0(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int multiplyHigh8 __asm__("$8");
    register int step __asm__("$22");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {int words[30];
        unsigned short halves[60];
        struct {char pad68[104]; volatile int doubledStep;} spill;
    } frame;
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$23");
    register int doubledStep __asm__("$8");
    void *contact30;
    register void *hit16 __asm__("$16");
    register int argument7 __asm__("$7");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int (*particle3)() __asm__("$3");
    register int toggleOne8 __asm__("$8");
    int var_a1;
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
    register unsigned char *recordPlus4 __asm__("$20");
    register unsigned char *recordPlus24 __asm__("$21");
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
    record = Update85DF0D_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    step=incomingStep;
    __asm__("" : "=r"(record),"=r"(step) : "0"(record),"1"(step) : "$4");
    scratch4 = Update85DF0Field(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    if (scratch3 != scratch2) {
        doubledStep = step * 2;
        __asm__("" : "=r"(step),"=r"(doubledStep) : "0"(step),"1"(doubledStep));
        frame.spill.doubledStep=doubledStep;
        quadrupledStep = step * 4;
        __asm__("" : "=r"(doubledStep),"=r"(quadrupledStep),"=r"(step) : "0"(doubledStep),"1"(quadrupledStep),"2"(step));
        contact30=&frame.words[12];
        __asm__("" : "=r"(contact30):"0"(contact30));
        recordPlus1 = record + 1;
        recordPlus24 = record + 0x18;
        recordPlus4 = record + 4;
        __asm__("" : "=r"(scratch4) : "0"(scratch4));
        scratch3 = scratch4 & 0xFF;
        __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update85DF0D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update85DF0D_8006C598 == 0) {
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
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update85DF0Field(recordPlus1,short*,0x1D);
                    toggleOne8=1;
                    if(scratch2!=0){scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1B);scratch2++;Update85DF0Field(recordPlus1,unsigned short*,0x1B)=scratch2;}
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,9);
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    __asm__("" : "=r"(toggleOne8):"0"(toggleOne8):"memory");
                    __asm__ volatile("" : "=r"(scratch3):"0"(scratch3):"memory");
                    doubledStep=frame.spill.doubledStep;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xB);
                    scratch3+=doubledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xC);
                    scratch2-=quadrupledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    scratch2+=step;Update85DF0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xD);
                    predicate2=(unsigned int)scratch2<32;
                    scratch3-=quadrupledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                    case 0x1:
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update85DF0Field(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update85DF0Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update85DF0Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    toggleOne8=1;
                    __asm__("" : "=r"(toggleOne8):"0"(toggleOne8));
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,9);
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1D);
                    scratch3+=quadrupledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xC);
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=quadrupledStep;
                    Update85DF0Field(recordPlus1, unsigned char *, 0xC)=scratch3;
                    scratch3=Update85DF0Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=quadrupledStep;
                    Update85DF0Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update85DF0Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<24;
                    __asm__("" : "=r"(predicate2),"=r"(scratch3) : "0"(predicate2),"1"(scratch3));
                    Update85DF0Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    goto checkPredicate;
                    case 0x9:
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update85DF0Field(recordPlus1, short *, 0x1D);
                    toggleOne8=1;
                    if(scratch2!=0){scratch2=Update85DF0Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2++;
                        Update85DF0Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,9);
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    __asm__("" : "=r"(toggleOne8):"0"(toggleOne8):"memory");
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,1);
                    doubledStep=frame.spill.doubledStep;
                    __asm__("" : "=r"(doubledStep):"0"(doubledStep));
                    scratch3+=doubledStep;
                    scratch2+=step;
                    Update85DF0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<32;
                    __asm__("" : "=r"(predicate2),"=r"(scratch3):"0"(predicate2),"1"(scratch3));
                    Update85DF0Field(recordPlus1,unsigned char*,9)=scratch3;
                    goto checkPredicate;
                    case 0xA:
                    scratch3=Update85DF0Player48;
                    if(scratch3==30 && Update85DF0Player280<0)goto removeRecord;
                    playerEnd=Update85DF0D_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update85DF0Field(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update85DF0Player284==0)goto removeRecord;
                    Update85DF0func_8004F178(&frame.words[0],playerEnd-0x288);
                    scratch2=Update85DF0func_8004EA2C(Update85DF0Field(recordPlus1, short *, 0x17));
                    scratch3=frame.words[0];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[0]=scratch3;
                    scratch2=Update85DF0func_8004E9E4(Update85DF0Field(recordPlus1, short *, 0x17));
                    scratch4=(int)recordPlus4;
                    playerEnd=(unsigned char*)&frame.words[0];
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch2) : "0"(scratch4),"1"(playerEnd),"2"(scratch2));
                    scratch2>>=4;
                    scratch3=frame.words[1];
                    scratch6=frame.words[2];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                    scratch3+=scratch2;
                    scratch6+=256;
                    frame.words[1]=scratch3;
                    frame.words[2]=scratch6;
                    __asm__("" : "=r"(scratch6) : "0"(scratch6));
                    Update85DF0func_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update85DF0Field(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update85DF0Field(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update85DF0D_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update85DF0func_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    multiplyHigh8=Update85DF0High(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=multiplyHigh8>>6;
                    scratch3-=scratch2;
                    Update85DF0Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                    case 0xB:
                    scratch2=Update85DF0Field(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){scratch2=Update85DF0Field(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update85DF0Field(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch6) : "0"(scratch4),"1"(playerEnd),"2"(scratch6));
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch2):"0"(scratch2));
                    toggleOne8=1;
                    __asm__("" : "=r"(scratch2),"=r"(toggleOne8):"0"(scratch2),"1"(toggleOne8));
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update85DF0func_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 9);
                    __asm__("" : "=r"(scratch2):"0"(scratch2):"memory");
                    doubledStep=frame.spill.doubledStep;
                    __asm__("" : "=r"(doubledStep):"0"(doubledStep));
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xB);
                    scratch2+=doubledStep;
                    Update85DF0Field(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xA);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update85DF0Field(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update85DF0Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=quadrupledStep;
                    Update85DF0Field(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update85DF0Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update85DF0Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                    case 0xC:
                    Update85DF0Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update85DF0Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update85DF0func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update85DF0Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update85DF0Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update85DF0Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update85DF0Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                    case 0xD:
                    {register void *temporary17 __asm__("$17");
                     register void *other16 __asm__("$16");
                     scratch2=Update85DF0Field(recordPlus1,unsigned char*,2);
                     if(scratch2==0)goto original13Body;
                     scratch2=Update85DF0D_8006C640;
                     scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xA);
                     scratch2&=3;
                     if(scratch2!=scratch3)goto original13Body;
                     scratch2=Update85DF0Field(recordPlus1,short*,3);
                     temporary17=&frame.words[4];
                     frame.words[4]=scratch2;
                     scratch2=Update85DF0Field(recordPlus1,short*,5);
                     frame.words[5]=scratch2;
                     scratch2=Update85DF0Field(recordPlus1,short*,7);
                     frame.words[6]=scratch2;
                     Update85DF0func_8004F0E8(temporary17,2);
                     other16=&frame.words[8];
                     Update85DF0func_8004F1C8(other16,temporary17,Update85DF0D_8006E020);
                     scratch2=Update85DF0func_8004EDE8(other16,0);
                     if(scratch2<0x6A4)goto removeRecord;
                    }
original13Body:;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=28)goto removeRecord;
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update85DF0Field(recordPlus1,short*,0x1D);
                    if(scratch2!=0){scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1B);scratch2++;Update85DF0Field(recordPlus1,unsigned short*,0x1B)=scratch2;}
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch2):"0"(scratch2));
                    toggleOne8=1;
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2):"0"(scratch2):"memory");
                    doubledStep=frame.spill.doubledStep;
                    __asm__("" : "=r"(doubledStep):"0"(doubledStep));
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,1);
                    scratch2+=doubledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(!(predicate2=(unsigned int)scratch3<13)){
                        scratch2=(scratch3-12)<<3;scratch3=128;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                        scratch2=scratch3-scratch2;if(scratch2<0)scratch2=0;
                        scratch3=Update85DF0Field(recordPlus1,unsigned char*,1);
                        Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=64;scratch3=(scratch3-12)<<2;scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update85DF0Field(recordPlus1,unsigned char*,0xD)=0;
                    }else if(!(predicate2=(unsigned int)scratch3<5)){
                        scratch2=128;
                        __asm__("" : "=r"(scratch2):"0"(scratch2));
                        scratch3=Update85DF0Field(recordPlus1,unsigned char*,1);
                        Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=-128;
                        Update85DF0Field(recordPlus1,unsigned char*,0xD)=0;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"memory");
                        scratch3=(scratch3-4)<<3;scratch2-=scratch3;
                        Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }else{
                        scratch2=128;
                        __asm__("" : "=r"(scratch2):"0"(scratch2));
                        scratch3=Update85DF0Field(recordPlus1,unsigned char*,1);
                        Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        __asm__ volatile("" ::: "$2","memory");
                        scratch2=128;scratch3<<=5;scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update85DF0Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
age0xD:
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update85DF0Field(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                    case 0x16:
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    toggleOne8=1;
                    __asm__("" : "=r"(toggleOne8):"0"(toggleOne8));
                    __asm__("" : "=r"(toggleOne8):"0"(toggleOne8):"memory");
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0x1D);
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1,unsigned char*,0x1D)=scratch2;
                    if((unsigned int)scratch3<32){scratch2=scratch3+1;Update85DF0Field(recordPlus1,unsigned char*,9)=scratch2;}
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0x1E);
                    __asm__ volatile("" : "=r"(scratch2):"0"(scratch2):"$4","memory");
                    scratch4=Update85DF0Field(recordPlus1,unsigned char*,0x1E);
                    __asm__ volatile("" : "=r"(scratch2),"=r"(scratch4):"0"(scratch2),"1"(scratch4):"memory");
                    scratch2*=2;scratch4*=2;
                    scratch3=Update85DF0Field(Update85DF0Table658A0,unsigned short*,scratch2);
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,3);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch3=(scratch3<<16)>>26;
                    scratch2+=scratch3;
                    Update85DF0Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0x1E);
                    scratch3=Update85DF0Field(Update85DF0Table65920,unsigned short*,scratch4);
                    scratch4=Update85DF0Field(recordPlus1,unsigned char*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2+=8;
                    scratch3<<=16;
                    Update85DF0Field(recordPlus1,unsigned char*,0x1E)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,5);
                    scratch3>>=26;
                    scratch2+=scratch3;
                    Update85DF0Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch4!=0){
                        scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xB);
                        scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xD);
                        scratch2-=1;
                        Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xC);
                        scratch3-=1;
                        Update85DF0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                        scratch2-=1;
                        Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch2>=128)goto removeRecord;
                    recordPlus1+=32;
                    break;

                    case 0x1A:

                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch3>=4){scratch2=scratch3-4;Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch2;}
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xC);
                    __asm__("" : "=r"(scratch2):"0"(scratch2));
                    if((unsigned int)scratch2<4)goto removeRecord;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xD);
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch2-=4;Update85DF0Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    if((unsigned int)scratch3<4)goto removeRecord;
                    scratch2=scratch3-4;Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    goto nextRecord;
                    case 0x1D:
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;Update85DF0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;if((unsigned int)scratch2>=65)goto removeRecord;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,9);
                    doubledStep=frame.spill.doubledStep;
                    __asm__("" : "=r"(doubledStep):"0"(doubledStep));
                    scratch2+=doubledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;if((unsigned int)scratch2>=129){scratch2=128;Update85DF0Field(recordPlus1,unsigned char*,9)=scratch2;}
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch3>=33){
                        scratch2=64;scratch3=scratch2-scratch3;
                        if(scratch3>=33)scratch3=32;
                        if(scratch3<0)scratch3=0;
                        Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                        scratch3<<=3;if(scratch3>=256)scratch3=255;
                        Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    }else{
                        scratch2=256;scratch3<<=3;scratch3=scratch2-scratch3;
                        if(scratch3>=256)scratch3=255;
                        if(scratch3<32)scratch3=32;
                        Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    }
                    scratch3=Update85DF0D_8006C640;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xA);
                    scratch3&=7;scratch2&=7;
                    if(scratch3==scratch2){
                        Update85DF0func_8004F554(contact30,recordPlus4);
                        Update85DF0func_8004F0E8(contact30,2);
                        hit16=(void*)Update85DF0func_8001BA30(contact30,512,3,0,0x100000,0);
                        if(hit16){
                            scratch4=Update85DF0Field(recordPlus1,short*,0x17);frame.words[16]=scratch4;
                            argument5=Update85DF0Field(recordPlus1,short*,0x19);frame.words[17]=argument5;
                            scratch2=Update85DF0func_8004E880(scratch4,argument5,0);
                            Update85DF0Field(hit16,unsigned char*,0x51)=scratch2;
                        }else{
                            scratch2=Update85DF0func_80019194(contact30,256);
                            if(scratch2==0)goto nextRecord;
                        }
                        scratch4=1;argument5=1;argument6=(int)&frame.words[12];argument7=(int)&frame.words[16];
                        __asm__("" : "=r"(scratch4),"=r"(argument5),"=r"(argument6),"=r"(argument7):"0"(scratch4),"1"(argument5),"2"(argument6),"3"(argument7));
                        particle3=Update85DF0SpawnParticle;
                        __asm__("" : "=r"(particle3):"0"(particle3));
                        scratch2=100;
                        frame.words[16]=0;frame.words[17]=0;frame.words[18]=scratch2;
                        particle3(scratch4,argument5,argument6,argument7);
                        goto removeRecord;
                    }else{
                        hit16=Update85DF0D_8006C550;
                        Update85DF0func_8004F554(contact30,recordPlus4);
                        Update85DF0func_8004F0E8(contact30,2);
                        scratch2=Update85DF0func_8004F334(contact30,(unsigned char*)hit16+12);
                        if(scratch2>=800)goto nextRecord;
                        scratch2=Update85DF0Field(hit16,int*,0x18);scratch2|=0x100000;
                        Update85DF0Field(hit16,int*,0x18)=scratch2;
                        scratch4=Update85DF0Field(recordPlus1,short*,0x17);frame.words[16]=scratch4;
                        argument5=Update85DF0Field(recordPlus1,short*,0x19);frame.words[17]=argument5;
                        scratch2=Update85DF0func_8004E880(scratch4,argument5,0);
                        Update85DF0Field(hit16,unsigned char*,0x51)=scratch2;
                        goto nextRecord;
                    }
                    case 0x21:
                    Update85DF0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update85DF0Field(recordPlus1,short*,0x1D);
                    if(scratch2!=0){scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1B);scratch2++;Update85DF0Field(recordPlus1,unsigned short*,0x1B)=scratch2;}
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,0xB);
                                        __asm__("" : "=r"(scratch2):"0"(scratch2));
                    doubledStep=frame.spill.doubledStep;
                    scratch3=Update85DF0Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(doubledStep),"=r"(scratch3):"0"(doubledStep),"1"(scratch3));
                    scratch4=scratch2-doubledStep;
                    scratch2=Update85DF0Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch2):"0"(scratch2));
                    toggleOne8=1;
                    __asm__("" : "=r"(scratch2),"=r"(toggleOne8):"0"(scratch2),"1"(toggleOne8));
                    scratch2=toggleOne8-scratch2;
                    Update85DF0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    __asm__ volatile("" : "=r"(scratch3):"0"(scratch3):"memory");
                    doubledStep=frame.spill.doubledStep;
                    scratch3+=doubledStep;
                    Update85DF0Field(recordPlus1,unsigned char*,9)=scratch3;
                    if(scratch4<0)scratch4=0;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,1);
                    Update85DF0Field(recordPlus1,unsigned char*,0xB)=scratch4;
                    Update85DF0Field(recordPlus1,unsigned char*,0xC)=scratch4;
                    Update85DF0Field(recordPlus1,unsigned char*,0xD)=scratch4;
                    scratch2+=step;
                    Update85DF0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=32)goto removeRecord;
                    scratch2=Update85DF0Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    if(scratch4==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x3B:
                    Update85DF0Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update85DF0Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update85DF0func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update85DF0D_8006C640 & 1) {
                        Update85DF0Field(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update85DF0Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update85DF0Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update85DF0Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update85DF0Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                    case 0x42:
                    iteration = 0;
                    if (step > 0) {
                        do {
                            if (Update85DF0Field(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update85DF0Field(recordPlus1, unsigned short *, 3);
                                scratch4=Update85DF0Field(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update85DF0Field(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update85DF0Field(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update85DF0Field(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update85DF0Field(recordPlus1, unsigned short *, 7);
                                scratch4=Update85DF0Field(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update85DF0Field(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update85DF0Field(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update85DF0Field(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update85DF0rand();
                                    halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update85DF0Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update85DF0rand();
                                    halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update85DF0Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update85DF0rand();
                                    halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update85DF0Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            iteration += 1;
                            Update85DF0Field(recordPlus1, unsigned char *, 1) = (unsigned char) (Update85DF0Field(recordPlus1, unsigned char *, 1) + 1);
                        } while (iteration < step);
                    }
                    predicate2 = (unsigned char) Update85DF0Field(recordPlus1, unsigned char *, 1) < 0x18U;
                    goto checkPredicate;
                    checkPredicate:
                    if(predicate2==0)goto removeRecord;
                    checkByte2:
                    if(Update85DF0Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x46:
                    temp_v0_11 = Update85DF0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update85DF0Field(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update85DF0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 9) - (short) Update85DF0Field(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[40] = (unsigned short) temp_a0_3;
                        frame.halves[41] = (unsigned short) ((int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 0xB) - (short) Update85DF0Field(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[42] = (unsigned short) ((int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 0xD) - (short) Update85DF0Field(recordPlus1, unsigned short *, 7)) >> 1);
                        Update85DF0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update85DF0Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 5) + frame.halves[41]);
                        Update85DF0Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 7) + frame.halves[42]);
                        random2=Update85DF0rand();
                        halfword3=frame.halves[40];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[40]=halfword3;
                        random2=Update85DF0rand();
                        halfword3=frame.halves[41];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[41]=halfword3;
                        if (Update85DF0Field(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[42] -= 1;
                        }
                        random2=Update85DF0Field(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[40];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update85DF0Field(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update85DF0Field(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[41];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update85DF0Field(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[42];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update85DF0Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update85DF0Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128){scratch2=128;Update85DF0Field(recordPlus1,unsigned char*,0xF)=scratch2;}
                        temp_v0_13 = Update85DF0Field(recordPlus1, unsigned char *, 0x10) - 4;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update85DF0Field(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update85DF0Field(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update85DF0Field(recordPlus1, unsigned char *, 0x13) - 3;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update85DF0Field(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        scratch2 = Update85DF0Field(recordPlus1, unsigned char *, 0x14);
                        scratch2 -= 4;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x14) = scratch2;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2 &= 255;
                        predicate2=(unsigned int)scratch2<0x80U;
                        if(predicate2){scratch2=128;Update85DF0Field(recordPlus1,unsigned char*,0x14)=scratch2;}
                        temp_v0_16 = (unsigned char) Update85DF0Field(recordPlus1, unsigned char *, 0x15) - 6;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update85DF0Field(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x47:
                    temp_v0_17 = Update85DF0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update85DF0Field(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update85DF0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[22] = (short) Update85DF0Field(recordPlus1, unsigned short *, 9) - (short) Update85DF0Field(recordPlus1, unsigned short *, 3);
                        frame.words[23] = (short) Update85DF0Field(recordPlus1, unsigned short *, 0xB) - (short) Update85DF0Field(recordPlus1, unsigned short *, 5);
                        frame.words[24] = (short) Update85DF0Field(recordPlus1, unsigned short *, 0xD) - (short) Update85DF0Field(recordPlus1, unsigned short *, 7);
                        random2=Update85DF0rand();
                        halfword3=frame.words[22];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[22]=halfword3;
                        random2=Update85DF0rand();
                        halfword3=frame.words[23];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[23]=halfword3;
                        random2=Update85DF0rand();
                        halfword3=frame.words[24];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[24]=halfword3;
                        Update85DF0Field(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update85DF0Field(recordPlus1, unsigned short *, 9) + frame.words[22]);
                        Update85DF0Field(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update85DF0Field(recordPlus1, unsigned short *, 0xB) + frame.words[23]);
                        Update85DF0Field(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update85DF0Field(recordPlus1, unsigned short *, 0xD) + frame.words[24]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[22];
                        scratch2=Update85DF0Field(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update85DF0Field(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[23];
                        scratch2=Update85DF0Field(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update85DF0Field(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[24];
                        scratch3=Update85DF0Field(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update85DF0Field(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update85DF0Field(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update85DF0Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update85DF0Field(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update85DF0Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x48:
                    temp_v0_18 = Update85DF0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update85DF0Field(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update85DF0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[20] = (int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 3) - (short) Update85DF0Field(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[21] = (int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 5) - (short) Update85DF0Field(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[22] = (int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 7) - (short) Update85DF0Field(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update85DF0rand();
                        halfword3=frame.words[20];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[20]=halfword3;
                        random2=Update85DF0rand();
                        halfword3=frame.words[21];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[21]=halfword3;
                        random2=Update85DF0rand();
                        halfword3=frame.words[22];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[22]=halfword3;
                        Update85DF0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 3) + frame.words[20]);
                        Update85DF0Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 5) + frame.words[21]);
                        Update85DF0Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 7) + frame.words[22]);
                        __asm__ __volatile__("" ::: "memory");
                        Update85DF0Field(recordPlus1, unsigned short *, 9) = (short) (Update85DF0Field(recordPlus1, unsigned short *, 3) - (frame.words[20] * 2));
                        Update85DF0Field(recordPlus1, unsigned short *, 0xB) = (short) (Update85DF0Field(recordPlus1, unsigned short *, 5) - (frame.words[21] * 2));
                        Update85DF0Field(recordPlus1, unsigned short *, 0xD) = (short) (Update85DF0Field(recordPlus1, unsigned short *, 7) - (frame.words[22] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4E:
                    temp_v0_19 = Update85DF0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update85DF0Field(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update85DF0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update85DF0Field(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update85DF0Field(recordPlus1, unsigned short *, 0x13);
                        Update85DF0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 3) + Update85DF0Field(recordPlus1, unsigned short *, 0xF));
                        Update85DF0Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update85DF0Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update85DF0rand();
                        halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update85DF0Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update85DF0rand();
                        halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update85DF0Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update85DF0rand();
                        halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update85DF0Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update85DF0Field(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update85DF0Field(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update85DF0Field(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update85DF0Field(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update85DF0Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update85DF0Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update85DF0Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4F:
                    temp_a0_5 = (int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 9) - (short) Update85DF0Field(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[40] = (unsigned short) temp_a0_5;
                    frame.halves[41] = (unsigned short) ((int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 0xB) - (short) Update85DF0Field(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[42] = (unsigned short) ((int) ((short) Update85DF0Field(recordPlus1, unsigned short *, 0xD) - (short) Update85DF0Field(recordPlus1, unsigned short *, 7)) >> 1);
                    Update85DF0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update85DF0Field(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update85DF0Field(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[41];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update85DF0Field(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update85DF0Field(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[42];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update85DF0Field(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update85DF0Field(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[40];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update85DF0Field(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update85DF0Field(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[41];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update85DF0Field(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update85DF0Field(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[42];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update85DF0Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update85DF0Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 2);
                    if(scratch2!=0)goto surviving4F;
                    removeRecord:
                    Update85DF0func_80056504(record);
                    recordPlus1+=32;
                    break;
                    surviving4F:
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update85DF0Field(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update85DF0Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update85DF0Field(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update85DF0Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update85DF0Field(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update85DF0Field(recordPlus1, unsigned char *, 0x13);
                    Update85DF0Field(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update85DF0Field(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update85DF0Field(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                    default:goto nextRecord;
                }
            } else {
                nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus24 += 0x20;
            recordPlus4 += 0x20;
            scratch4 = *recordPlus1;
            __asm__("" : "=r"(scratch4) : "0"(scratch4));
            __asm__ __volatile__("" ::: "$2", "memory");
            scratch2=255;
            __asm__("" : "=r"(scratch2) : "0"(scratch2));
            scratch3 = scratch4 & 0xFF;
            __asm__("" : "=r"(scratch4),"=r"(scratch3),"=r"(scratch2) : "0"(scratch4),"1"(scratch3),"2"(scratch2));
            record += 0x20;
        } while (scratch3 != scratch2);
    }
    return record;
}

