#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI-generated; not human reviewed. Uninstalled level30 candidate: verified level10/11/26/35 C baselines.
 * Verified cutscene71 C adapted only to complete original4028 instructions and dispatch.
 * Raw units/helper meanings/cadence unresolved; native and linked originals
 * plus full EXE and every overlay hashes required before acceptance. */


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */


#define Update850C0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update850C0func_8004E9E4(short) __asm__("func_8004E9E4");
int Update850C0func_8004EA2C(short) __asm__("func_8004EA2C");
int Update850C0func_8004F178(void*,void*) __asm__("func_8004F178");
int Update850C0func_8004F504(void*,void*) __asm__("func_8004F504");
int Update850C0func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update850C0func_80056504(void*) __asm__("func_80056504");
extern int Update850C0D_8006C644 __asm__("D_8006C644");
extern unsigned short Update850C0Sin[] __asm__("D_80065920");
extern unsigned short Update850C0Cos[] __asm__("D_800658A0");
extern int (*Update850C0SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
int Update850C0func_800359A4(void*,int) __asm__("func_800359A4");
int Update850C0func_8004EDE8(void*,int) __asm__("func_8004EDE8");
int Update850C0func_8004F08C(void*,int,int) __asm__("func_8004F08C");
int Update850C0func_8004EF04(void*,int) __asm__("func_8004EF04");
int Update850C0func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Update850C0rand(void) __asm__("rand");
extern unsigned char *Update850C0D_8006C554 __asm__("D_8006C554");
extern int Update850C0D_8006C598 __asm__("D_8006C598");
extern int Update850C0D_8006C640 __asm__("D_8006C640");
extern short Update850C0D_8006E040 __asm__("D_8006E040");
extern int Update850C0D_8006E344 __asm__("D_8006E344");
extern unsigned char Update850C0D_80070328[] __asm__("D_80070328");
extern int Update850C0Player48 __asm__("D_80070328 + 0x48");
extern int Update850C0Player284 __asm__("D_80070328 + 0x284");
extern int Update850C0Player280 __asm__("D_80070328 + 0x280");
#define Update850C0High(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})

unsigned char *func_level_30_800850C0(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    register int step __asm__("$22");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {int words[30];
        unsigned short halves[60];
        struct {int pad[14];volatile int doubled48;int rest[15];} saved;
    } frame;
    register int scratch5 __asm__("$5");
    register int scratch7 __asm__("$7");
    register int scratch8 __asm__("$8");
    register int predicate3 __asm__("$3");
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$21");
    int doubledStep;
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
    register unsigned char *recordPlus4 __asm__("$20");
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
    record = Update850C0D_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    step=incomingStep;
    __asm__("" : "=r"(record),"=r"(step) : "0"(record),"1"(step) : "$4");
    scratch4 = Update850C0Field(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    __asm__("" : "=r"(step) : "0"(step));
    if (scratch3 != scratch2) {
        doubledStep = step * 2;
        __asm__("" : "=r"(step) : "0"(step));
        quadrupledStep = step * 4;
        __asm__("" : "=r"(quadrupledStep),"=r"(step) : "0"(quadrupledStep),"1"(step));
        recordPlus1 = record + 1;
        recordPlus24 = record + 0x18;
        recordPlus4 = record + 4;
        __asm__("" : "=r"(scratch4) : "0"(scratch4));
        scratch3 = scratch4 & 0xFF;
        __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update850C0D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update850C0D_8006C598 == 0) {
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
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update850C0Field(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update850C0Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update850C0Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=1;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch4=Update850C0Field(recordPlus1,unsigned short*,0x1D);
                    scratch3+=doubledStep;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    scratch2-=scratch4;
                    Update850C0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=quadrupledStep;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<32;
                    Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                    case 0x1:
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update850C0Field(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update850C0Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update850C0Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=1;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch4=Update850C0Field(recordPlus1,unsigned short*,0x1D);
                    scratch3+=quadrupledStep;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    scratch2-=scratch4;
                    Update850C0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=quadrupledStep;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<24;
                    Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                    case 0x2:
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update850C0Field(recordPlus1,short*,0x1D)!=0)
                        Update850C0Field(recordPlus1,unsigned short*,0x1B)=Update850C0Field(recordPlus1,unsigned short*,0x1B)+1;
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2","memory");
                    scratch2=1;
                    scratch2-=scratch3;
                    Update850C0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=doubledStep;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){scratch2=scratch3-quadrupledStep;Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch2;}
                    else Update850C0Field(recordPlus1,unsigned char*,0xB)=0;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){scratch2=scratch3-quadrupledStep;Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch2;}
                    else Update850C0Field(recordPlus1,unsigned char*,0xC)=0;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xD);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){__asm__ volatile("" : : "r"(step) : "memory");scratch2=scratch3-quadrupledStep;Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch2;}
                    else Update850C0Field(recordPlus1,unsigned char*,0xD)=0;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                    case 0x4:
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch3=Update850C0Field(recordPlus1,short*,0x17);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=1;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if(scratch2<scratch3){
                        scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                        scratch2+=4;
                        Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xA);
                    scratch4=Update850C0Field(recordPlus1,unsigned char*,0x19);
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,7);
                    scratch5=Update850C0Field(recordPlus1,unsigned short*,0x1B);
                    __asm__("" : "=r"(scratch3),"=r"(scratch4),"=r"(scratch2),"=r"(scratch5) : "0"(scratch3),"1"(scratch4),"2"(scratch2),"3"(scratch5));
                    scratch3+=scratch4;
                    scratch2+=scratch5;
                    Update850C0Field(recordPlus1,unsigned short*,7)=scratch2;
                    scratch2<<=16;
                    Update850C0Field(recordPlus1,unsigned char*,0xA)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,short*,0x1D);
                    scratch2>>=16;
                    predicate3=scratch3<scratch2;
                    __asm__("" : "=r"(predicate3) : "0"(predicate3));
                    if(!predicate3)goto nextRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch2-=4;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2<9)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x9:
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update850C0Field(recordPlus1, short *, 0x1D);
                    if(scratch2!=0){scratch2=Update850C0Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2++;
                        Update850C0Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2","memory");
                    scratch2=1;
                    scratch2-=scratch3;
                    scratch3=Update850C0Field(recordPlus1, unsigned char *, 9);
                    Update850C0Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    scratch3+=doubledStep;
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=step;
                    Update850C0Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    Update850C0Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto checkPredicate;
                    case 0xA:
                    {
                    scratch3=Update850C0Player48;
                    if(scratch3==30 && Update850C0Player280<0)goto removeRecord;
                    playerEnd=Update850C0D_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update850C0Field(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update850C0Player284==0)goto removeRecord;
                    Update850C0func_8004F178((&frame.words[0]),playerEnd-0x288);
                    scratch2=Update850C0func_8004EA2C(Update850C0Field(recordPlus1, short *, 0x17));
                    scratch3=frame.words[0];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[0]=scratch3;
                    scratch2=Update850C0func_8004E9E4(Update850C0Field(recordPlus1, short *, 0x17));
                    scratch4=(int)recordPlus4;
                    playerEnd=(unsigned char*)(&frame.words[0]);
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
                    Update850C0func_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update850C0Field(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update850C0Field(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update850C0D_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update850C0func_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    high7=Update850C0High(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=high7>>6;
                    scratch3-=scratch2;
                    Update850C0Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                    }
                    case 0xB:
                    scratch2=Update850C0Field(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){scratch2=Update850C0Field(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update850C0Field(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd) : "0"(scratch4),"1"(playerEnd));
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch6) : "0"(scratch6) : "$3","memory");
                    scratch3=Update850C0Field(recordPlus1, unsigned short *, 0x1D);
                    scratch2=1;
                    scratch2-=scratch3;
                    Update850C0Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update850C0func_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 9);
                    __asm__("" : "=r"(scratch2),"=r"(doubledStep) : "0"(scratch2),"1"(doubledStep));
                    scratch3=Update850C0Field(recordPlus1, unsigned char *, 0xB);
                    scratch2+=doubledStep;
                    Update850C0Field(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 0xA);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update850C0Field(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update850C0Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=quadrupledStep;
                    Update850C0Field(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update850C0Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update850C0Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                    case 0xC:
                    Update850C0Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update850C0Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update850C0func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update850C0Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update850C0Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update850C0Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update850C0Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update850C0Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update850C0Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update850C0Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                    case 0x13:
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=65)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch2+=doubledStep;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129)Update850C0Field(recordPlus1,unsigned char*,9)=128;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch3<33){scratch2=256;goto added19Early;}
                    scratch2=64;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=33)scratch3=32;
                    if(scratch3<0)scratch3=0;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3*=8;
                    if(scratch3>=256)scratch3=255;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    goto nextRecord;
added19Early:
                    scratch3*=8;
                    __asm__ volatile("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2) : "$4","memory");
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    predicate2=scratch3<32;
                    __asm__ volatile("" : "=r"(predicate2) : "0"(predicate2) : "$4","memory");
                    if(!predicate2)goto addedStoreByteC;
                    scratch3=32;
                    goto addedStoreByteC;
                    case 0x1E: {
                    register void *vector16 __asm__("$16");
                    register unsigned char *other6 __asm__("$6");
                    vector16=&frame.words[4];
                    scratch4=(int)vector16;
                    scratch5=1;
                    other6=Update850C0Field(recordPlus1,unsigned char**,0x17);
                    scratch2=Update850C0Field(recordPlus1,short*,3);
                    scratch3=Update850C0Field(other6,int*,12);
                    scratch2*=4;
                    scratch3-=scratch2;
                    frame.words[4]=scratch3;
                    scratch2=Update850C0Field(recordPlus1,short*,5);
                    scratch3=Update850C0Field(other6,int*,16);
                    scratch2*=4;
                    scratch3-=scratch2;
                    frame.words[5]=scratch3;
                    scratch3=Update850C0Field(recordPlus1,short*,7);
                    scratch2=Update850C0Field(other6,int*,20);
                    scratch3*=4;
                    scratch3-=1024;
                    scratch2-=scratch3;
                    frame.words[6]=scratch2;
                    scratch5=Update850C0func_8004EDE8(vector16,1);
                    if(scratch5<193)goto removeRecord;
                    Update850C0func_8004F08C(vector16,scratch5,192);
                    scratch2=frame.words[4];
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,3);
                    scratch2>>=2;
                    scratch3+=scratch2;
                    Update850C0Field(recordPlus1,unsigned short*,3)=scratch3;
                    scratch2=frame.words[5];
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,5);
                    scratch2>>=2;
                    scratch3+=scratch2;
                    Update850C0Field(recordPlus1,unsigned short*,5)=scratch3;
                    scratch2=frame.words[6];
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,7);
                    scratch2>>=2;
                    scratch3+=scratch2;
                    Update850C0Field(recordPlus1,unsigned short*,7)=scratch3;
                    goto nextRecord;
                    }
                    case 0x21:
                    Update850C0func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update850C0Field(recordPlus1, short *, 0x1D) != 0) {
                        Update850C0Field(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    scratch4=Update850C0Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2),"=r"(doubledStep),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(doubledStep),"2"(scratch4),"3"(scratch3));
                    var_a1=scratch2-doubledStep;
                    scratch2=1;
                    scratch2-=scratch4;
                    scratch3+=doubledStep;
                    Update850C0Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch3;
                    if (var_a1 < 0) {
                        var_a1 = 0;
                    }
                    Update850C0Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) var_a1;
                    Update850C0Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) var_a1;
                    Update850C0Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) var_a1;
                    temp_v0_7 = Update850C0Field(recordPlus1, unsigned char *, 1) + step;
                    Update850C0Field(recordPlus1, unsigned char *, 1) = temp_v0_7;
                    if (((unsigned int) (temp_v0_7 & 0xFF) < 0x20U) && (Update850C0Field(recordPlus1, unsigned char *, 2) != 0) && (var_a1 != 0)) {
                        recordPlus1 += 0x20;
                    } else {
                        goto removeRecord;
                    }
                    break;
                    case 0x27:
                    scratch2=Update850C0Field(recordPlus1,short*,0x17);
                    if(scratch2>0){
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3-1;
                    }else{
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3+1;
                    }
                    Update850C0Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,short*,0x19);
                    if(scratch2>0){
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3-1;
                    }else{
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3+1;
                    }
                    Update850C0Field(recordPlus1,unsigned short*,0x19)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,0x1B);
                    scratch2+=1;
                    Update850C0Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    scratch2<<=16;
                    scratch2>>=16;
                    if(scratch2>=25)Update850C0Field(recordPlus1,unsigned short*,0x1B)=24;
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : : : "memory");
                    scratch4=Update850C0Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4) : "0"(scratch2),"1"(scratch4));
                    scratch2<<=4;
                    scratch2&=0x1F0;
                    scratch4<<=4;
                    scratch4&=0x1F0;
                    __asm__("" : "=r"(scratch2),"=r"(scratch4) : "0"(scratch2),"1"(scratch4));
                    scratch3=Update850C0Field(Update850C0Sin,unsigned short*,scratch2);
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,3);
                    scratch3<<=16;
                    scratch3>>=25;
                    scratch2+=scratch3;
                    Update850C0Field(recordPlus1,unsigned short*,3)=scratch2;
                    __asm__ volatile("" : "=r"(scratch4) : "0"(scratch4) : "memory");
                    scratch3=Update850C0Field(Update850C0Cos,unsigned short*,scratch4);
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,5);
                    scratch4=Update850C0Field(recordPlus1,unsigned char*,0xA);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=25;
                    scratch2+=scratch3;
                    Update850C0Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch4==0 || (Update850C0D_8006C640&1)!=0){
                        scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                        scratch2+=1;
                        Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    if(Update850C0func_800359A4(record+2,1)!=0)goto removeRecord;
                    if(Update850C0Field(recordPlus1,unsigned char*,0xA)==0)goto checkByte2;
                    recordPlus1+=32;
                    break;
                    case 0x29:
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=1;
                    scratch8=scratch2&255;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    if((unsigned int)scratch3<(unsigned int)scratch8){
                        if(Update850C0Field(recordPlus1,unsigned char*,0x1E)==0)goto removeRecord;
                        goto sharedSpawn43;
                        goto removeRecord;
                    }
                    scratch2=Update850C0Field(recordPlus1,short*,0x17);
                    scratch7=Update850C0Field(recordPlus1,short*,0x11);
                    __asm__("" : "=r"(scratch2),"=r"(scratch7) : "0"(scratch2),"1"(scratch7));
                    scratch2-=scratch7;
                    scratch2*=scratch8;
                    scratch8=scratch2/scratch3;
                    scratch6=Update850C0Field(recordPlus1,short*,0x13);
                    scratch2=Update850C0Field(recordPlus1,short*,0x19);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                    scratch2-=scratch6;
                    scratch2*=scratch3;
                    scratch5=Update850C0Field(recordPlus1,unsigned char*,0x1D);
                    scratch5=scratch2/scratch5;
                    scratch4=Update850C0Field(recordPlus1,unsigned short*,0x15);
                    __asm__ volatile("" : "=r"(scratch4) : "0"(scratch4) : "memory");
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,0x15);
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,7);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=2;
                    Update850C0Field(recordPlus1,unsigned short*,0x15)=scratch3;
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2+=scratch4;
                    Update850C0Field(recordPlus1,unsigned short*,7)=scratch2;
                    scratch2=Update850C0D_8006C644;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch7+=scratch8;
                    Update850C0Field(recordPlus1,unsigned short*,3)=scratch7;
                    scratch6+=scratch5;
                    Update850C0Field(recordPlus1,unsigned short*,5)=scratch6;
                    scratch2=Update850C0Sin[scratch2];
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=26;
                    scratch2+=10;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update850C0D_8006C644;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch2=Update850C0Cos[scratch2];
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=27;
                    scratch2+=6;
                    Update850C0Field(recordPlus1,unsigned char*,0xA)=scratch2;
                    goto nextRecord;
                    case 0x2A:
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update850C0Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    scratch4=Update850C0Field(recordPlus1,short*,0x11);
                    scratch5=Update850C0Field(recordPlus1,short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(scratch5) : "0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(scratch5));
                    scratch2+=2;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=6;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=6;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,int*,0x17);
                    scratch3-=6;
                    Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,int*,0x1B);
                    scratch2+=scratch4;
                    Update850C0Field(recordPlus1,int*,0x17)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update850C0Field(recordPlus1,int*,0x17);
                    scratch3+=scratch5;
                    Update850C0Field(recordPlus1,int*,0x1B)=scratch3;
                    __asm__ volatile("" ::: "memory");
                    scratch3=Update850C0Field(recordPlus1,int*,0x1B);
                    scratch2>>=2;
                    scratch3>>=2;
                    Update850C0Field(recordPlus1,unsigned short*,3)=scratch2;
                    Update850C0Field(recordPlus1,unsigned short*,5)=scratch3;
                    goto nextRecord;
                    case 0x2B:
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch2<4)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,short*,0x17);
                    temp_a1=3;
                    if(scratch2!=0)temp_a1=2;
                    scratch4=Update850C0Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch4),"=r"(temp_a1) : "0"(scratch4),"1"(temp_a1) : "memory");
                    scratch3=Update850C0Field(recordPlus1,short*,0x17);
                    scratch2=scratch4+1;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(scratch3!=0){scratch2=scratch4+2;Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;}
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=temp_a1;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=temp_a1;
                    Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2-=temp_a1;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    goto nextRecord;
                    case 0x2C:
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update850C0Field(recordPlus1,unsigned short*,0x11);
                    scratch3=Update850C0Field(recordPlus1,unsigned short*,0x19);
                    scratch5=Update850C0Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3),"=r"(scratch5) : "0"(scratch2),"1"(scratch4),"2"(scratch3),"3"(scratch5));
                    scratch2+=scratch4;
                    Update850C0Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,7);
                    scratch4=Update850C0Field(recordPlus1,unsigned short*,0x15);
                    scratch3+=scratch5;
                    Update850C0Field(recordPlus1,unsigned short*,0x19)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0x1B);
                    scratch2+=scratch4;
                    scratch3*=2;
                    Update850C0Field(recordPlus1,unsigned short*,7)=scratch2;
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch3=Update850C0Field(Update850C0Sin,unsigned short*,scratch3);
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update850C0Field(recordPlus1,unsigned char*,0x1B);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=24;
                    scratch2+=scratch3;
                    scratch4*=2;
                    Update850C0Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0x1B);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0x1C);
                    scratch4=Update850C0Field(Update850C0Cos,unsigned short*,scratch4);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2+=scratch3;
                    scratch4<<=16;
                    scratch4>>=24;
                    Update850C0Field(recordPlus1,unsigned char*,0x1B)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned short*,0x19);
                    scratch3=Update850C0D_8006C640;
                    scratch2+=scratch4;
                    scratch3&=3;
                    Update850C0Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch3==0){
                        scratch2=Update850C0Field(recordPlus1,short*,0x15);
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        if(scratch2<9){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update850C0Field(recordPlus1,unsigned short*,0x15)=scratch2;
                        }
                        scratch3=Update850C0Field(recordPlus1,unsigned char*,9);
                        if((unsigned int)scratch3<20){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                    }
                    scratch2=Update850C0Field(recordPlus1,short*,7);
                    scratch3=Update850C0Field(recordPlus1,short*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2>=scratch3){
                        scratch3=Update850C0Field(recordPlus1,unsigned char*,0x10);
                        scratch2=3;
                        if(scratch3!=scratch2)goto removeRecord;
sharedSpawn43:
                        Update850C0SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    if(scratch2==0)goto removeRecord;
                    __asm__ volatile("" ::: "memory");
                    goto checkByte2;
                    case 0x2E:
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update850C0Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=3;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=8;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=8;
                    scratch3-=8;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto nextRecord;
                    case 0x37:
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3));
                    scratch2=scratch3+step;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129)Update850C0Field(recordPlus1,unsigned char*,9)=128;
                    scratch4=Update850C0Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch4<17) {scratch2=256;goto addedEarlyAge;}
                    predicate2=scratch3<17;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(predicate2)Update850C0SpawnParticle(1,56,record,0);
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2-=16;
                    scratch3=scratch2*8;
                    scratch2=256;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3<0)scratch3=0;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,0xC);
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3>>=1;
                    if(scratch3>=scratch2)goto nextRecord;
addedStoreByteC:
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    goto nextRecord;
addedEarlyAge:
                    scratch3=scratch4*16;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3>=32)goto addedStoreByteC;
                    scratch3=32;
                    goto addedStoreByteC;
                    case 0x38:
                    Update850C0func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update850C0Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129)Update850C0Field(recordPlus1,unsigned char*,9)=128;
                    __asm__ volatile("" : : "r"(step) : "$4","memory");
                    scratch3=Update850C0Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2");
                    if((unsigned int)scratch3<16)scratch2=scratch3*4;
                    else {scratch2=48;scratch2-=scratch3;scratch2*=2;}
                    if(scratch2<=0)goto removeRecord;
                    Update850C0Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    Update850C0Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update850C0Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    goto nextRecord;
                    case 0x3B:
                    Update850C0Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update850C0Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update850C0func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update850C0D_8006C640 & 1) {
                        Update850C0Field(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update850C0Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update850C0Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update850C0Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update850C0Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update850C0Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update850C0Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update850C0Field(recordPlus1,unsigned int*,0xB);
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
                            if (Update850C0Field(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update850C0Field(recordPlus1, unsigned short *, 3);
                                scratch4=Update850C0Field(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update850C0Field(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update850C0Field(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update850C0Field(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update850C0Field(recordPlus1, unsigned short *, 7);
                                scratch4=Update850C0Field(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update850C0Field(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update850C0Field(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update850C0Field(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update850C0rand();
                                    halfword3=Update850C0Field(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update850C0Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update850C0rand();
                                    halfword3=Update850C0Field(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update850C0Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update850C0rand();
                                    halfword3=Update850C0Field(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update850C0Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            iteration += 1;
                            Update850C0Field(recordPlus1, unsigned char *, 1) = (unsigned char) (Update850C0Field(recordPlus1, unsigned char *, 1) + 1);
                        } while (iteration < step);
                    }
                    predicate2 = (unsigned char) Update850C0Field(recordPlus1, unsigned char *, 1) < 0x18U;
                    goto checkPredicate;
                    checkPredicate:
                    if(predicate2==0)goto removeRecord;
                    checkByte2:
                    if(Update850C0Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x46:
                    temp_v0_11 = Update850C0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update850C0Field(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update850C0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update850C0Field(recordPlus1, unsigned short *, 9) - (short) Update850C0Field(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[16] = (unsigned short) temp_a0_3;
                        frame.halves[17] = (unsigned short) ((int) ((short) Update850C0Field(recordPlus1, unsigned short *, 0xB) - (short) Update850C0Field(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[18] = (unsigned short) ((int) ((short) Update850C0Field(recordPlus1, unsigned short *, 0xD) - (short) Update850C0Field(recordPlus1, unsigned short *, 7)) >> 1);
                        Update850C0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update850C0Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 5) + frame.halves[17]);
                        Update850C0Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 7) + frame.halves[18]);
                        random2=Update850C0rand();
                        halfword3=frame.halves[16];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[16]=halfword3;
                        random2=Update850C0rand();
                        halfword3=frame.halves[17];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[17]=halfword3;
                        if (Update850C0Field(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[18] -= 1;
                        }
                        random2=Update850C0Field(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[16];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update850C0Field(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update850C0Field(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[17];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update850C0Field(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update850C0Field(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[18];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update850C0Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update850C0Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128)Update850C0Field(recordPlus1, unsigned char *, 0xF)=128;
                        temp_v0_13 = Update850C0Field(recordPlus1, unsigned char *, 0x10) - 4;
                        Update850C0Field(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update850C0Field(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update850C0Field(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update850C0Field(recordPlus1, unsigned char *, 0x13) - 3;
                        Update850C0Field(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update850C0Field(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        temp_v0_15 = Update850C0Field(recordPlus1, unsigned char *, 0x14) - 4;
                        Update850C0Field(recordPlus1, unsigned char *, 0x14) = temp_v0_15;
                        if ((unsigned int) (temp_v0_15 & 0xFF) < 0x80U) {
                            Update850C0Field(recordPlus1, unsigned char *, 0x14) = 0x80U;
                        }
                        temp_v0_16 = (unsigned char) Update850C0Field(recordPlus1, unsigned char *, 0x15) - 6;
                        Update850C0Field(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update850C0Field(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x47:
                    temp_v0_17 = Update850C0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update850C0Field(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update850C0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[10] = (short) Update850C0Field(recordPlus1, unsigned short *, 9) - (short) Update850C0Field(recordPlus1, unsigned short *, 3);
                        frame.words[11] = (short) Update850C0Field(recordPlus1, unsigned short *, 0xB) - (short) Update850C0Field(recordPlus1, unsigned short *, 5);
                        frame.words[12] = (short) Update850C0Field(recordPlus1, unsigned short *, 0xD) - (short) Update850C0Field(recordPlus1, unsigned short *, 7);
                        random2=Update850C0rand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        random2=Update850C0rand();
                        halfword3=frame.words[11];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[11]=halfword3;
                        random2=Update850C0rand();
                        halfword3=frame.words[12];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[12]=halfword3;
                        Update850C0Field(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update850C0Field(recordPlus1, unsigned short *, 9) + frame.words[10]);
                        Update850C0Field(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update850C0Field(recordPlus1, unsigned short *, 0xB) + frame.words[11]);
                        Update850C0Field(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update850C0Field(recordPlus1, unsigned short *, 0xD) + frame.words[12]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[10];
                        scratch2=Update850C0Field(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update850C0Field(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[11];
                        scratch2=Update850C0Field(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update850C0Field(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[12];
                        scratch3=Update850C0Field(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update850C0Field(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update850C0Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update850C0Field(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update850C0Field(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update850C0Field(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update850C0Field(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update850C0Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update850C0Field(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update850C0Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x48:
                    temp_v0_18 = Update850C0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update850C0Field(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update850C0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[8] = (int) ((short) Update850C0Field(recordPlus1, unsigned short *, 3) - (short) Update850C0Field(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[9] = (int) ((short) Update850C0Field(recordPlus1, unsigned short *, 5) - (short) Update850C0Field(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[10] = (int) ((short) Update850C0Field(recordPlus1, unsigned short *, 7) - (short) Update850C0Field(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update850C0rand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        random2=Update850C0rand();
                        halfword3=frame.words[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[9]=halfword3;
                        random2=Update850C0rand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        Update850C0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 3) + frame.words[8]);
                        Update850C0Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 5) + frame.words[9]);
                        Update850C0Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 7) + frame.words[10]);
                        __asm__ __volatile__("" ::: "memory");
                        Update850C0Field(recordPlus1, unsigned short *, 9) = (short) (Update850C0Field(recordPlus1, unsigned short *, 3) - (frame.words[8] * 2));
                        Update850C0Field(recordPlus1, unsigned short *, 0xB) = (short) (Update850C0Field(recordPlus1, unsigned short *, 5) - (frame.words[9] * 2));
                        Update850C0Field(recordPlus1, unsigned short *, 0xD) = (short) (Update850C0Field(recordPlus1, unsigned short *, 7) - (frame.words[10] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4E:
                    temp_v0_19 = Update850C0Field(recordPlus1, unsigned char *, 1) + 1;
                    Update850C0Field(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update850C0Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update850C0Field(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update850C0Field(recordPlus1, unsigned short *, 0x13);
                        Update850C0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 3) + Update850C0Field(recordPlus1, unsigned short *, 0xF));
                        Update850C0Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update850C0Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update850C0rand();
                        halfword3=Update850C0Field(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update850C0Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update850C0rand();
                        halfword3=Update850C0Field(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update850C0Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update850C0rand();
                        halfword3=Update850C0Field(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update850C0Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update850C0Field(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update850C0Field(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update850C0Field(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update850C0Field(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update850C0Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update850C0Field(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update850C0Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update850C0Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4F:
                    temp_a0_5 = (int) ((short) Update850C0Field(recordPlus1, unsigned short *, 9) - (short) Update850C0Field(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[16] = (unsigned short) temp_a0_5;
                    frame.halves[17] = (unsigned short) ((int) ((short) Update850C0Field(recordPlus1, unsigned short *, 0xB) - (short) Update850C0Field(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[18] = (unsigned short) ((int) ((short) Update850C0Field(recordPlus1, unsigned short *, 0xD) - (short) Update850C0Field(recordPlus1, unsigned short *, 7)) >> 1);
                    Update850C0Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update850C0Field(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update850C0Field(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[17];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update850C0Field(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update850C0Field(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[18];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update850C0Field(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update850C0Field(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[16];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update850C0Field(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update850C0Field(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[17];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update850C0Field(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update850C0Field(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[18];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update850C0Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update850C0Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update850C0Field(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update850C0Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update850C0Field(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update850C0Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update850C0Field(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update850C0Field(recordPlus1, unsigned char *, 0x13);
                    Update850C0Field(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update850C0Field(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update850C0Field(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                    case 0x56: {
                    register void *matrix __asm__("$16");
                    register void *delta __asm__("$17");
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,1);
                    scratch2++;
                    Update850C0Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=8)goto removeRecord;
                    scratch2=Update850C0Field(recordPlus1,unsigned char*,2);
                    matrix=&frame.words[14];
                    if(scratch2!=0)goto surviving86;
removeRecord:
                    Update850C0func_80056504(record);
                    recordPlus1+=32;
                    break;
surviving86:

                     scratch4=Update850C0Field(recordPlus1,short*,9);
                     scratch2=Update850C0Field(recordPlus1,short*,3);
                     scratch4-=scratch2;
                     frame.words[8]=scratch4;
                     scratch2=Update850C0Field(recordPlus1,short*,0xB);
                     scratch3=Update850C0Field(recordPlus1,short*,5);
                     scratch2-=scratch3;
                     frame.words[9]=scratch2;
                     scratch2=Update850C0Field(recordPlus1,short*,0xD);
                     scratch3=Update850C0Field(recordPlus1,short*,7);
                     scratch2-=scratch3;
                     frame.words[10]=scratch2;
                     scratch2=Update850C0Field(recordPlus1,unsigned short*,3);
                     delta=&frame.words[8];
                     scratch2+=scratch4;
                     Update850C0Field(recordPlus1,unsigned short*,3)=scratch2;
                     scratch3=frame.words[9];
                     scratch2=Update850C0Field(recordPlus1,unsigned short*,5);
                     scratch2+=scratch3;
                     Update850C0Field(recordPlus1,unsigned short*,5)=scratch2;
                     scratch3=frame.words[10];
                     scratch2=Update850C0Field(recordPlus1,unsigned short*,7);
                     scratch2+=scratch3;
                     Update850C0Field(recordPlus1,unsigned short*,7)=scratch2;
                     Update850C0func_8004F178(matrix,delta);
                     Update850C0func_8004EF04(matrix,3);
                     Update850C0func_8004F1C8(delta,delta,matrix);
                     scratch3=frame.words[8];
                     scratch2=Update850C0Field(recordPlus1,unsigned short*,3);
                     scratch2+=scratch3;
                     Update850C0Field(recordPlus1,unsigned short*,9)=scratch2;
                     scratch3=frame.words[9];
                     scratch2=Update850C0Field(recordPlus1,unsigned short*,5);
                     scratch2+=scratch3;
                     Update850C0Field(recordPlus1,unsigned short*,0xB)=scratch2;
                     scratch3=frame.words[10];
                     scratch2=Update850C0Field(recordPlus1,unsigned short*,7);
                     scratch2+=scratch3;
                     Update850C0Field(recordPlus1,unsigned short*,0xD)=scratch2;
                    goto nextRecord;
                    }
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
#undef Update850C0High
#undef Update850C0Field




