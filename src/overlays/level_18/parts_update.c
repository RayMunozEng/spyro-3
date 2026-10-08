#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Update74DE4Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update74DE4func_8004E9E4(short) __asm__("func_8004E9E4");
int Update74DE4func_8004EA2C(short) __asm__("func_8004EA2C");
int Update74DE4func_8004F178(void*,void*) __asm__("func_8004F178");
int Update74DE4func_8004F504(void*,void*) __asm__("func_8004F504");
int Update74DE4func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update74DE4func_80056504(void*) __asm__("func_80056504");
int Update74DE4rand(void) __asm__("rand");
extern unsigned char *Update74DE4D_8006C554 __asm__("D_8006C554");
extern int Update74DE4D_8006C598 __asm__("D_8006C598");
extern int Update74DE4D_8006C640 __asm__("D_8006C640");
extern short Update74DE4D_8006E040 __asm__("D_8006E040");
extern int Update74DE4D_8006E344 __asm__("D_8006E344");
extern unsigned char Update74DE4D_80070328[] __asm__("D_80070328");
extern int Update74DE4Player48 __asm__("D_80070328 + 0x48");
extern int Update74DE4Player284 __asm__("D_80070328 + 0x284");
extern int Update74DE4Player280 __asm__("D_80070328 + 0x280");
#define Update74DE4High(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})
extern int (*Update74DE4SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
unsigned char *func_level_18_800858B8(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$8");
    register int step __asm__("$20");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {int words[12];
        unsigned short halves[24];
    } frame;
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$22");
    int raw128;
    register int doubledStep __asm__("$23");
    int var_a1;
    register int iteration __asm__("$17");
    register int predicate2 __asm__("$2");
    register int random2 __asm__("$2");
    register int halfword3 __asm__("$3");
    register int scratch3 __asm__("$3");
    int temp_v0_14;
    int temp_v0_16;
    unsigned short temp_a0_4;
    register int temp_a1 __asm__("$5");
    unsigned short temp_a1_2;
    register unsigned char *recordPlus1 __asm__("$16");
    register unsigned char *record __asm__("$18");
    register unsigned char *recordPlus4 __asm__("$19");
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
    record = Update74DE4D_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    step=incomingStep;
    __asm__("" : "=r"(record),"=r"(step) : "0"(record),"1"(step) : "$4");
    scratch4 = Update74DE4Field(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    if (scratch3 != scratch2) {
        doubledStep = step * 2;
        __asm__("" : "=r"(step),"=r"(doubledStep) : "0"(step),"1"(doubledStep));
        quadrupledStep = step * 4;
        __asm__("" : "=r"(doubledStep),"=r"(quadrupledStep),"=r"(step) : "0"(doubledStep),"1"(quadrupledStep),"2"(step));
        raw128=128;
        __asm__("" : "=r"(raw128) : "0"(raw128));
        recordPlus1 = record + 1;
        recordPlus24 = record + 0x18;
        recordPlus4 = record + 4;
        __asm__("" : "=r"(scratch4) : "0"(scratch4));
        scratch3 = scratch4 & 0xFF;
        __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update74DE4D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update74DE4D_8006C598 == 0) {
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
                    Update74DE4func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update74DE4Field(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update74DE4Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update74DE4Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=1;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 9);
                    scratch4=Update74DE4Field(recordPlus1, unsigned short *, 0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch3+=doubledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 9)=scratch3;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xC);
                    scratch2-=scratch4;
                    Update74DE4Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=quadrupledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xC)=scratch3;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=quadrupledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update74DE4Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    __asm__("" : "=r"(predicate2),"=r"(scratch3) : "0"(predicate2),"1"(scratch3));
                    Update74DE4Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    goto checkPredicate;
                    case 0x1:
                    Update74DE4func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update74DE4Field(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update74DE4Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update74DE4Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=1;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 9);
                    scratch4=Update74DE4Field(recordPlus1, unsigned short *, 0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch3+=quadrupledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 9)=scratch3;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xC);
                    scratch2-=scratch4;
                    Update74DE4Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=quadrupledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xC)=scratch3;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=quadrupledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update74DE4Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<24;
                    __asm__("" : "=r"(predicate2),"=r"(scratch3) : "0"(predicate2),"1"(scratch3));
                    Update74DE4Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    goto checkPredicate;
                    case 0x9:
                    Update74DE4func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update74DE4Field(recordPlus1, short *, 0x1D);
                    if(scratch2!=0){scratch2=Update74DE4Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2++;
                        Update74DE4Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch3=Update74DE4Field(recordPlus1, unsigned short *, 0x1D);
                    __asm__ __volatile__("" ::: "$2", "memory");
                    scratch2=1;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=scratch3;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 9);
                    Update74DE4Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3+=doubledStep;
                    scratch2+=step;
                    Update74DE4Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    __asm__("" : "=r"(predicate2),"=r"(scratch3) : "0"(predicate2),"1"(scratch3));
                    Update74DE4Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto checkPredicate;
                    case 0xA:
                    scratch3=Update74DE4Player48;
                    if(scratch3==30 && Update74DE4Player280<0)goto removeRecord;
                    playerEnd=Update74DE4D_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update74DE4Field(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update74DE4Player284==0)goto removeRecord;
                    Update74DE4func_8004F178(&frame.words[0],playerEnd-0x288);
                    scratch2=Update74DE4func_8004EA2C(Update74DE4Field(recordPlus1, short *, 0x17));
                    scratch3=frame.words[0];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[0]=scratch3;
                    scratch2=Update74DE4func_8004E9E4(Update74DE4Field(recordPlus1, short *, 0x17));
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
                    Update74DE4func_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update74DE4Field(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update74DE4Field(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update74DE4D_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update74DE4func_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    high7=Update74DE4High(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=high7>>6;
                    scratch3-=scratch2;
                    Update74DE4Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                    case 0xB:
                    scratch2=Update74DE4Field(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){scratch2=Update74DE4Field(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update74DE4Field(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch6) : "0"(scratch4),"1"(playerEnd),"2"(scratch6));
                    scratch3=Update74DE4Field(recordPlus1, unsigned short *, 0x1D);
                    __asm__ __volatile__("" ::: "$2", "memory");
                    scratch2=1;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=scratch3;
                    Update74DE4Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update74DE4func_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 9);
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=doubledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xA);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=quadrupledStep;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                    case 0xC:
                    Update74DE4Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update74DE4Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update74DE4func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update74DE4Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update74DE4Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update74DE4Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update74DE4Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                    case 0xD:
                    if((unsigned int)Update74DE4Field(recordPlus1,unsigned char*,1)>=28)goto removeRecord;
                    if(Update74DE4Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    Update74DE4func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update74DE4Field(recordPlus1,short*,0x1D)!=0)
                        Update74DE4Field(recordPlus1,unsigned short*,0x1B)=Update74DE4Field(recordPlus1,unsigned short*,0x1B)+1;
                    __asm__ volatile("" ::: "$2","memory");
                    scratch3=Update74DE4Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2");
                    scratch2=1;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=scratch3;
                    Update74DE4Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,9);
                    scratch3=Update74DE4Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=doubledStep;
                    Update74DE4Field(recordPlus1,unsigned char*,9)=scratch2;
                    predicate2=(unsigned int)scratch3<13;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(!predicate2){
                        scratch2=(scratch3-12)*8;
                        scratch2=raw128-scratch2;
                        if(scratch2<0)scratch2=0;
                        scratch3=Update74DE4Field(recordPlus1,unsigned char*,1);
                        Update74DE4Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=64;
                        scratch3=(scratch3-12)*4;
                        scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update74DE4Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update74DE4Field(recordPlus1,unsigned char*,0xD)=0;
                    }else {
                    predicate2=(unsigned int)scratch3<5;
                    if(!predicate2){
                        scratch2=-128;
                        scratch3=Update74DE4Field(recordPlus1,unsigned char*,1);
                        Update74DE4Field(recordPlus1,unsigned char*,0xB)=raw128;
                        Update74DE4Field(recordPlus1,unsigned char*,0xD)=0;
                        scratch3=(scratch3-4)*8;
                        scratch2-=scratch3;
                        Update74DE4Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }else{
                        scratch2=Update74DE4Field(recordPlus1,unsigned char*,1);
                        Update74DE4Field(recordPlus1,unsigned char*,0xB)=raw128;
                        scratch2*=32;
                        scratch2=raw128-scratch2;
                        Update74DE4Field(recordPlus1,unsigned char*,0xC)=raw128;
                        if(scratch2<0)scratch2=0;
                        Update74DE4Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
                    }
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update74DE4Field(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                    case 0x21:
                    Update74DE4func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update74DE4Field(recordPlus1, short *, 0x1D) != 0) {
                        Update74DE4Field(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    var_a1 = Update74DE4Field(recordPlus1, unsigned char *, 0xB) - doubledStep;
                    Update74DE4Field(recordPlus1, short *, 0x1D) = (short) (1 - (unsigned short) Update74DE4Field(recordPlus1, short *, 0x1D));
                    Update74DE4Field(recordPlus1, unsigned char *, 9) = (unsigned char) (Update74DE4Field(recordPlus1, unsigned char *, 9) + doubledStep);
                    if (var_a1 < 0) {
                        var_a1 = 0;
                    }
                    Update74DE4Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) var_a1;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) var_a1;
                    Update74DE4Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) var_a1;
                    temp_v0_7 = Update74DE4Field(recordPlus1, unsigned char *, 1) + step;
                    Update74DE4Field(recordPlus1, unsigned char *, 1) = temp_v0_7;
                    if (((unsigned int) (temp_v0_7 & 0xFF) < 0x20U) && (Update74DE4Field(recordPlus1, unsigned char *, 2) != 0) && (var_a1 != 0)) {
                        recordPlus1 += 0x20;
                    } else {
                        goto removeRecord;
                    }
                    break;
                    case 0x37:
                    Update74DE4func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch3=Update74DE4Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3));
                    scratch2=scratch3+step;
                    Update74DE4Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update74DE4Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129)Update74DE4Field(recordPlus1,unsigned char*,9)=raw128;
                    scratch4=Update74DE4Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch4<17) {scratch2=256;goto addedEarlyAge;}
                    predicate2=scratch3<17;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(predicate2)Update74DE4SpawnParticle(1,56,record,0);
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,1);
                    scratch2-=16;
                    scratch3=scratch2*8;
                    scratch2=256;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3<0)scratch3=0;
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,0xC);
                    Update74DE4Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3>>=1;
                    if(scratch3>=scratch2)goto nextRecord;
addedStoreByteC:
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    Update74DE4Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    goto nextRecord;
addedEarlyAge:
                    scratch3=scratch4*16;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3>=32)goto addedStoreByteC;
                    scratch3=32;
                    goto addedStoreByteC;
                    case 0x38:
                    Update74DE4func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update74DE4Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch2=Update74DE4Field(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update74DE4Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129)Update74DE4Field(recordPlus1,unsigned char*,9)=raw128;
                    __asm__ volatile("" : : "r"(step) : "$4","memory");
                    scratch3=Update74DE4Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2");
                    if((unsigned int)scratch3<16)scratch2=scratch3*4;
                    else {scratch2=48;scratch2-=scratch3;scratch2*=2;}
                    if(scratch2<=0)goto removeRecord;
                    Update74DE4Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    Update74DE4Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update74DE4Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    goto nextRecord;
                    case 0x3B:
                    Update74DE4Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update74DE4Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update74DE4func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update74DE4D_8006C640 & 1) {
                        Update74DE4Field(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update74DE4Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update74DE4Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update74DE4Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update74DE4Field(recordPlus1,unsigned int*,0xB);
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
                            if (Update74DE4Field(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update74DE4Field(recordPlus1, unsigned short *, 3);
                                scratch4=Update74DE4Field(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update74DE4Field(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update74DE4Field(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update74DE4Field(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update74DE4Field(recordPlus1, unsigned short *, 7);
                                scratch4=Update74DE4Field(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update74DE4Field(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update74DE4Field(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update74DE4Field(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update74DE4rand();
                                    halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update74DE4Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update74DE4rand();
                                    halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update74DE4Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update74DE4rand();
                                    halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update74DE4Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            iteration += 1;
                            Update74DE4Field(recordPlus1, unsigned char *, 1) = (unsigned char) (Update74DE4Field(recordPlus1, unsigned char *, 1) + 1);
                        } while (iteration < step);
                    }
                    predicate2 = (unsigned char) Update74DE4Field(recordPlus1, unsigned char *, 1) < 0x18U;
                    goto checkPredicate;
                    checkPredicate:
                    if(predicate2==0)goto removeRecord;
                    checkByte2:
                    if(Update74DE4Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x46:
                    temp_v0_11 = Update74DE4Field(recordPlus1, unsigned char *, 1) + 1;
                    Update74DE4Field(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update74DE4Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 9) - (short) Update74DE4Field(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[8] = (unsigned short) temp_a0_3;
                        frame.halves[9] = (unsigned short) ((int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 0xB) - (short) Update74DE4Field(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[10] = (unsigned short) ((int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 0xD) - (short) Update74DE4Field(recordPlus1, unsigned short *, 7)) >> 1);
                        Update74DE4Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update74DE4Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 5) + frame.halves[9]);
                        Update74DE4Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 7) + frame.halves[10]);
                        random2=Update74DE4rand();
                        halfword3=frame.halves[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[8]=halfword3;
                        random2=Update74DE4rand();
                        halfword3=frame.halves[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[9]=halfword3;
                        if (Update74DE4Field(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[10] -= 1;
                        }
                        random2=Update74DE4Field(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[8];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update74DE4Field(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update74DE4Field(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[9];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update74DE4Field(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[10];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update74DE4Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update74DE4Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128)Update74DE4Field(recordPlus1, unsigned char *, 0xF)=raw128;
                        temp_v0_13 = Update74DE4Field(recordPlus1, unsigned char *, 0x10) - 4;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update74DE4Field(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update74DE4Field(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update74DE4Field(recordPlus1, unsigned char *, 0x13) - 3;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update74DE4Field(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        temp_v0_15 = Update74DE4Field(recordPlus1, unsigned char *, 0x14) - 4;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x14) = temp_v0_15;
                        if ((unsigned int) (temp_v0_15 & 0xFF) < 0x80U) {
                            Update74DE4Field(recordPlus1, unsigned char *, 0x14) = raw128;
                        }
                        temp_v0_16 = (unsigned char) Update74DE4Field(recordPlus1, unsigned char *, 0x15) - 6;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update74DE4Field(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x47:
                    temp_v0_17 = Update74DE4Field(recordPlus1, unsigned char *, 1) + 1;
                    Update74DE4Field(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update74DE4Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[6] = (short) Update74DE4Field(recordPlus1, unsigned short *, 9) - (short) Update74DE4Field(recordPlus1, unsigned short *, 3);
                        frame.words[7] = (short) Update74DE4Field(recordPlus1, unsigned short *, 0xB) - (short) Update74DE4Field(recordPlus1, unsigned short *, 5);
                        frame.words[8] = (short) Update74DE4Field(recordPlus1, unsigned short *, 0xD) - (short) Update74DE4Field(recordPlus1, unsigned short *, 7);
                        random2=Update74DE4rand();
                        halfword3=frame.words[6];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[6]=halfword3;
                        random2=Update74DE4rand();
                        halfword3=frame.words[7];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[7]=halfword3;
                        random2=Update74DE4rand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        Update74DE4Field(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update74DE4Field(recordPlus1, unsigned short *, 9) + frame.words[6]);
                        Update74DE4Field(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update74DE4Field(recordPlus1, unsigned short *, 0xB) + frame.words[7]);
                        Update74DE4Field(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update74DE4Field(recordPlus1, unsigned short *, 0xD) + frame.words[8]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[6];
                        scratch2=Update74DE4Field(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update74DE4Field(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[7];
                        scratch2=Update74DE4Field(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update74DE4Field(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[8];
                        scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update74DE4Field(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update74DE4Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update74DE4Field(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update74DE4Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x48:
                    temp_v0_18 = Update74DE4Field(recordPlus1, unsigned char *, 1) + 1;
                    Update74DE4Field(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update74DE4Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[4] = (int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 3) - (short) Update74DE4Field(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[5] = (int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 5) - (short) Update74DE4Field(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[6] = (int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 7) - (short) Update74DE4Field(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update74DE4rand();
                        halfword3=frame.words[4];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[4]=halfword3;
                        random2=Update74DE4rand();
                        halfword3=frame.words[5];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[5]=halfword3;
                        random2=Update74DE4rand();
                        halfword3=frame.words[6];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[6]=halfword3;
                        Update74DE4Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 3) + frame.words[4]);
                        Update74DE4Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 5) + frame.words[5]);
                        Update74DE4Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 7) + frame.words[6]);
                        __asm__ __volatile__("" ::: "memory");
                        Update74DE4Field(recordPlus1, unsigned short *, 9) = (short) (Update74DE4Field(recordPlus1, unsigned short *, 3) - (frame.words[4] * 2));
                        Update74DE4Field(recordPlus1, unsigned short *, 0xB) = (short) (Update74DE4Field(recordPlus1, unsigned short *, 5) - (frame.words[5] * 2));
                        Update74DE4Field(recordPlus1, unsigned short *, 0xD) = (short) (Update74DE4Field(recordPlus1, unsigned short *, 7) - (frame.words[6] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4E:
                    temp_v0_19 = Update74DE4Field(recordPlus1, unsigned char *, 1) + 1;
                    Update74DE4Field(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update74DE4Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update74DE4Field(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update74DE4Field(recordPlus1, unsigned short *, 0x13);
                        Update74DE4Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 3) + Update74DE4Field(recordPlus1, unsigned short *, 0xF));
                        Update74DE4Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update74DE4Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update74DE4rand();
                        halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update74DE4Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update74DE4rand();
                        halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update74DE4Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update74DE4rand();
                        halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update74DE4Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update74DE4Field(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update74DE4Field(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update74DE4Field(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update74DE4Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update74DE4Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update74DE4Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4F:
                    temp_a0_5 = (int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 9) - (short) Update74DE4Field(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[8] = (unsigned short) temp_a0_5;
                    frame.halves[9] = (unsigned short) ((int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 0xB) - (short) Update74DE4Field(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[10] = (unsigned short) ((int) ((short) Update74DE4Field(recordPlus1, unsigned short *, 0xD) - (short) Update74DE4Field(recordPlus1, unsigned short *, 7)) >> 1);
                    Update74DE4Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update74DE4Field(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update74DE4Field(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[9];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update74DE4Field(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update74DE4Field(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[10];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update74DE4Field(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update74DE4Field(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[8];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update74DE4Field(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update74DE4Field(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[9];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update74DE4Field(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update74DE4Field(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[10];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update74DE4Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update74DE4Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 2);
                    if(scratch2!=0)goto surviving4F;
                    removeRecord:
                    Update74DE4func_80056504(record);
                    recordPlus1+=32;
                    break;
                    surviving4F:
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update74DE4Field(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update74DE4Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update74DE4Field(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update74DE4Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update74DE4Field(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update74DE4Field(recordPlus1, unsigned char *, 0x13);
                    Update74DE4Field(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update74DE4Field(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update74DE4Field(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
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
