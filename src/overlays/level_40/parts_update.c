#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI-generated; not human reviewed. Uninstalled cutscene80/level40 candidate.
 * Verified cutscene71 C adapted only to complete original3975 instructions.
 * Raw units/helper meanings/cadence unresolved; native and linked originals
 * plus full EXE and every overlay hashes required before acceptance. */


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */


#define Update83D3CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update83D3Cfunc_8004E9E4(short) __asm__("func_8004E9E4");
int Update83D3Cfunc_8004EA2C(short) __asm__("func_8004EA2C");
int Update83D3Cfunc_8004F178(void*,void*) __asm__("func_8004F178");
int Update83D3Cfunc_8004F504(void*,void*) __asm__("func_8004F504");
int Update83D3Cfunc_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update83D3Cfunc_80056504(void*) __asm__("func_80056504");
int Update83D3Crand(void) __asm__("rand");
extern unsigned char *Update83D3CD_8006C554 __asm__("D_8006C554");
extern int Update83D3CD_8006C598 __asm__("D_8006C598");
extern int Update83D3CD_8006C640 __asm__("D_8006C640");
extern short Update83D3CD_8006E040 __asm__("D_8006E040");
extern int Update83D3CD_8006E344 __asm__("D_8006E344");
extern unsigned char Update83D3CD_80070328[] __asm__("D_80070328");
extern int Update83D3CPlayer48 __asm__("D_80070328 + 0x48");
extern int Update83D3CPlayer284 __asm__("D_80070328 + 0x284");
extern int Update83D3CPlayer280 __asm__("D_80070328 + 0x280");
#define Update83D3CHigh(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})

unsigned char *func_level_40_80083D3C(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$7");
    int step;
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {int words[18];
        unsigned short halves[36];
        struct {int pad[14];volatile int doubled48;int rest[3];} saved;
    } frame;
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$22");
    register int doubledStep __asm__("$7");
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
    register unsigned char *recordPlus1 __asm__("$17");
    register unsigned char *record __asm__("$20");
    register unsigned char *recordPlus4 __asm__("$21");
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
    record = Update83D3CD_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    step=incomingStep;
    __asm__("" : "=r"(record),"=r"(step) : "0"(record),"1"(step) : "$4");
    scratch4 = Update83D3CField(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    doubledStep = step * 2;
    if (scratch3 != scratch2) {
        frame.saved.doubled48=doubledStep;
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
                if (Update83D3CD_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update83D3CD_8006C598 == 0) {
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
                    Update83D3Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update83D3CField(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update83D3CField(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update83D3CField(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=1;
                    scratch4=Update83D3CField(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,9);
                    scratch2-=scratch4;
                    Update83D3CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    doubledStep=frame.saved.doubled48;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,0xB);
                    scratch3+=doubledStep;
                    Update83D3CField(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xC);
                    scratch2-=quadrupledStep;
                    Update83D3CField(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update83D3CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    Update83D3CField(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xD);
                    predicate2=(unsigned int)scratch2<32;
                    scratch3-=quadrupledStep;
                    Update83D3CField(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                    case 0x1:
                    Update83D3Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update83D3CField(recordPlus1, short *, 0x1D);
                    __asm__ __volatile__("" ::: "$3", "memory");
                    if(scratch2!=0){scratch2=Update83D3CField(recordPlus1, unsigned short *, 0x1B);
                        scratch2+=1;
                        Update83D3CField(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch2=1;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,9);
                    scratch4=Update83D3CField(recordPlus1,unsigned short*,0x1D);
                    scratch3+=quadrupledStep;
                    Update83D3CField(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xC);
                    scratch2-=scratch4;
                    Update83D3CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update83D3CField(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xD);
                    scratch2-=quadrupledStep;
                    Update83D3CField(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    scratch2+=step;
                    Update83D3CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<24;
                    Update83D3CField(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                    case 0x2:
                    Update83D3Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update83D3CField(recordPlus1,short*,0x1D)!=0)
                        Update83D3CField(recordPlus1,unsigned short*,0x1B)=Update83D3CField(recordPlus1,unsigned short*,0x1B)+1;
                    scratch3=Update83D3CField(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2","memory");
                    scratch2=1;
                    scratch2-=scratch3;
                    Update83D3CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,9);
                    doubledStep=frame.saved.doubled48;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=doubledStep;
                    Update83D3CField(recordPlus1,unsigned char*,9)=scratch2;
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){scratch2=scratch3-quadrupledStep;Update83D3CField(recordPlus1,unsigned char*,0xB)=scratch2;}
                    else Update83D3CField(recordPlus1,unsigned char*,0xB)=0;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xC);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){scratch2=scratch3-quadrupledStep;Update83D3CField(recordPlus1,unsigned char*,0xC)=scratch2;}
                    else Update83D3CField(recordPlus1,unsigned char*,0xC)=0;
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xD);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){__asm__ volatile("" : : "r"(step) : "memory");scratch2=scratch3-quadrupledStep;Update83D3CField(recordPlus1,unsigned char*,0xD)=scratch2;}
                    else Update83D3CField(recordPlus1,unsigned char*,0xD)=0;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update83D3CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                    case 0x6:
                    {register int radius16 __asm__("$16");
                     register int angle18 __asm__("$18");
                     register int height19 __asm__("$19");
                     register int product7 __asm__("$7");
                     playerEnd=Update83D3CField(recordPlus1,unsigned char**,0x17);
                     Update83D3Cfunc_8004F178(&frame.words[0],playerEnd);
                     scratch2=Update83D3CField(recordPlus1,unsigned char*,1);
                     radius16=scratch2<<6;
                     scratch2=Update83D3CField(recordPlus1,short*,0x1D);
                     scratch3=frame.words[2];
                     scratch2<<=6;
                     height19=scratch3+scratch2;
                     scratch3=Update83D3CField(recordPlus1,short*,0x1B);
                     angle18=radius16;
                     if(scratch3<radius16)radius16=scratch3;
                     scratch2=Update83D3Cfunc_8004EA2C(angle18);
                     product7=radius16*scratch2;
                     scratch2=frame.words[0];
                     __asm__("" : "=r"(product7),"=r"(scratch2) : "0"(product7),"1"(scratch2));
                     scratch3=product7>>12;
                     scratch2+=scratch3;
                     frame.words[0]=scratch2;
                     scratch2=Update83D3Cfunc_8004E9E4(angle18);
                     product7=radius16*scratch2;
                     scratch2=frame.words[1];
                     __asm__("" : "=r"(product7),"=r"(scratch2) : "0"(product7),"1"(scratch2));
                     scratch3=product7>>12;
                     scratch2+=scratch3;
                     frame.words[1]=scratch2;
                     scratch2=Update83D3CField(recordPlus1,short*,7);
                     scratch2=(scratch2<<2)+64;
                     frame.words[2]=scratch2;
                     if(height19<scratch2)goto removeRecord;
                     Update83D3Cfunc_8004F504(recordPlus4,&frame.words[0]);
                     scratch2=Update83D3CField(recordPlus1,unsigned char*,1);
                     scratch2++;
                     Update83D3CField(recordPlus1,unsigned char*,1)=scratch2;
                     goto nextRecord;
                    }
                    case 0x9:
                    Update83D3Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update83D3CField(recordPlus1, short *, 0x1D);
                    if(scratch2!=0){scratch2=Update83D3CField(recordPlus1, unsigned short *, 0x1B);
                        scratch2++;
                        Update83D3CField(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch3=Update83D3CField(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2","memory");
                    scratch2=1;
                    scratch2-=scratch3;
                    scratch3=Update83D3CField(recordPlus1, unsigned char *, 9);
                    Update83D3CField(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    doubledStep=frame.saved.doubled48;
                    scratch3+=doubledStep;
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=step;
                    Update83D3CField(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    Update83D3CField(recordPlus1, unsigned char *, 9)=scratch3;
                    goto checkPredicate;
                    case 0xA:
                    {register void *temporary16 __asm__("$16");
                    scratch3=Update83D3CPlayer48;
                    if(scratch3==30 && Update83D3CPlayer280<0)goto removeRecord;
                    playerEnd=Update83D3CD_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update83D3CField(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update83D3CPlayer284==0)goto removeRecord;
                    temporary16=&frame.words[4];
                    Update83D3Cfunc_8004F178(temporary16,playerEnd-0x288);
                    scratch2=Update83D3Cfunc_8004EA2C(Update83D3CField(recordPlus1, short *, 0x17));
                    scratch3=frame.words[4];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[4]=scratch3;
                    scratch2=Update83D3Cfunc_8004E9E4(Update83D3CField(recordPlus1, short *, 0x17));
                    scratch4=(int)recordPlus4;
                    playerEnd=(unsigned char*)temporary16;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch2) : "0"(scratch4),"1"(playerEnd),"2"(scratch2));
                    scratch2>>=4;
                    scratch3=frame.words[5];
                    scratch6=frame.words[6];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                    scratch3+=scratch2;
                    scratch6+=256;
                    frame.words[5]=scratch3;
                    frame.words[6]=scratch6;
                    __asm__("" : "=r"(scratch6) : "0"(scratch6));
                    Update83D3Cfunc_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update83D3CField(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update83D3CField(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update83D3CD_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update83D3Cfunc_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    high7=Update83D3CHigh(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=high7>>6;
                    scratch3-=scratch2;
                    Update83D3CField(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                    }
                    case 0xB:
                    scratch2=Update83D3CField(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){scratch2=Update83D3CField(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update83D3CField(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd) : "0"(scratch4),"1"(playerEnd));
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch6) : "0"(scratch6) : "$3","memory");
                    scratch3=Update83D3CField(recordPlus1, unsigned short *, 0x1D);
                    scratch2=1;
                    scratch2-=scratch3;
                    Update83D3CField(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update83D3Cfunc_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 9);
                    doubledStep=frame.saved.doubled48;
                    __asm__("" : "=r"(scratch2),"=r"(doubledStep) : "0"(scratch2),"1"(doubledStep));
                    scratch3=Update83D3CField(recordPlus1, unsigned char *, 0xB);
                    scratch2+=doubledStep;
                    Update83D3CField(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 0xA);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update83D3CField(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update83D3CField(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=quadrupledStep;
                    Update83D3CField(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update83D3CField(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update83D3CField(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                    case 0xC:
                    Update83D3CField(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update83D3CField(recordPlus1, unsigned char *, 0xA) + 8);
                    Update83D3Cfunc_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update83D3CField(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update83D3CField(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update83D3CField(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update83D3CField(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update83D3CField(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update83D3CField(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update83D3CField(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                    case 0x21:
                    Update83D3Cfunc_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update83D3CField(recordPlus1, short *, 0x1D) != 0) {
                        Update83D3CField(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,0xB);
                    doubledStep=frame.saved.doubled48;
                    scratch4=Update83D3CField(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2),"=r"(doubledStep),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(doubledStep),"2"(scratch4),"3"(scratch3));
                    var_a1=scratch2-doubledStep;
                    scratch2=1;
                    scratch2-=scratch4;
                    scratch3+=doubledStep;
                    Update83D3CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    Update83D3CField(recordPlus1,unsigned char*,9)=scratch3;
                    if (var_a1 < 0) {
                        var_a1 = 0;
                    }
                    Update83D3CField(recordPlus1, unsigned char *, 0xB) = (unsigned char) var_a1;
                    Update83D3CField(recordPlus1, unsigned char *, 0xC) = (unsigned char) var_a1;
                    Update83D3CField(recordPlus1, unsigned char *, 0xD) = (unsigned char) var_a1;
                    temp_v0_7 = Update83D3CField(recordPlus1, unsigned char *, 1) + step;
                    Update83D3CField(recordPlus1, unsigned char *, 1) = temp_v0_7;
                    if (((unsigned int) (temp_v0_7 & 0xFF) < 0x20U) && (Update83D3CField(recordPlus1, unsigned char *, 2) != 0) && (var_a1 != 0)) {
                        recordPlus1 += 0x20;
                    } else {
                        goto removeRecord;
                    }
                    break;
                    case 0x2B:
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch2<4)goto removeRecord;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update83D3CField(recordPlus1,short*,0x17);
                    temp_a1=3;
                    if(scratch2!=0)temp_a1=2;
                    scratch4=Update83D3CField(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch4),"=r"(temp_a1) : "0"(scratch4),"1"(temp_a1) : "memory");
                    scratch3=Update83D3CField(recordPlus1,short*,0x17);
                    scratch2=scratch4+1;
                    Update83D3CField(recordPlus1,unsigned char*,9)=scratch2;
                    if(scratch3!=0){scratch2=scratch4+2;Update83D3CField(recordPlus1,unsigned char*,9)=scratch2;}
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,0xB);
                    scratch3=Update83D3CField(recordPlus1,unsigned char*,0xD);
                    scratch2-=temp_a1;
                    Update83D3CField(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,0xC);
                    scratch3-=temp_a1;
                    Update83D3CField(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2-=temp_a1;
                    Update83D3CField(recordPlus1,unsigned char*,0xC)=scratch2;
                    goto nextRecord;
                    case 0x3B:
                    Update83D3CField(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update83D3CField(recordPlus1, unsigned char *, 0xA) + 8);
                    Update83D3Cfunc_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update83D3CD_8006C640 & 1) {
                        Update83D3CField(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update83D3CField(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update83D3CField(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update83D3CField(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update83D3CField(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update83D3CField(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update83D3CField(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update83D3CField(recordPlus1,unsigned int*,0xB);
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
                            if (Update83D3CField(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update83D3CField(recordPlus1, unsigned short *, 3);
                                scratch4=Update83D3CField(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update83D3CField(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update83D3CField(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update83D3CField(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update83D3CField(recordPlus1, unsigned short *, 7);
                                scratch4=Update83D3CField(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update83D3CField(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update83D3CField(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update83D3CField(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update83D3Crand();
                                    halfword3=Update83D3CField(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update83D3CField(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update83D3Crand();
                                    halfword3=Update83D3CField(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update83D3CField(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update83D3Crand();
                                    halfword3=Update83D3CField(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update83D3CField(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            iteration += 1;
                            Update83D3CField(recordPlus1, unsigned char *, 1) = (unsigned char) (Update83D3CField(recordPlus1, unsigned char *, 1) + 1);
                        } while (iteration < step);
                    }
                    predicate2 = (unsigned char) Update83D3CField(recordPlus1, unsigned char *, 1) < 0x18U;
                    goto checkPredicate;
                    checkPredicate:
                    if(predicate2==0)goto removeRecord;
                    checkByte2:
                    if(Update83D3CField(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x46:
                    temp_v0_11 = Update83D3CField(recordPlus1, unsigned char *, 1) + 1;
                    Update83D3CField(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update83D3CField(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update83D3CField(recordPlus1, unsigned short *, 9) - (short) Update83D3CField(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[16] = (unsigned short) temp_a0_3;
                        frame.halves[17] = (unsigned short) ((int) ((short) Update83D3CField(recordPlus1, unsigned short *, 0xB) - (short) Update83D3CField(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[18] = (unsigned short) ((int) ((short) Update83D3CField(recordPlus1, unsigned short *, 0xD) - (short) Update83D3CField(recordPlus1, unsigned short *, 7)) >> 1);
                        Update83D3CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update83D3CField(recordPlus1, unsigned short *, 5) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 5) + frame.halves[17]);
                        Update83D3CField(recordPlus1, unsigned short *, 7) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 7) + frame.halves[18]);
                        random2=Update83D3Crand();
                        halfword3=frame.halves[16];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[16]=halfword3;
                        random2=Update83D3Crand();
                        halfword3=frame.halves[17];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[17]=halfword3;
                        if (Update83D3CField(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[18] -= 1;
                        }
                        random2=Update83D3CField(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[16];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update83D3CField(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update83D3CField(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[17];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update83D3CField(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update83D3CField(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[18];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update83D3CField(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update83D3CField(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128)Update83D3CField(recordPlus1, unsigned char *, 0xF)=128;
                        temp_v0_13 = Update83D3CField(recordPlus1, unsigned char *, 0x10) - 4;
                        Update83D3CField(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update83D3CField(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update83D3CField(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update83D3CField(recordPlus1, unsigned char *, 0x13) - 3;
                        Update83D3CField(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update83D3CField(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        temp_v0_15 = Update83D3CField(recordPlus1, unsigned char *, 0x14) - 4;
                        Update83D3CField(recordPlus1, unsigned char *, 0x14) = temp_v0_15;
                        if ((unsigned int) (temp_v0_15 & 0xFF) < 0x80U) {
                            Update83D3CField(recordPlus1, unsigned char *, 0x14) = 0x80U;
                        }
                        temp_v0_16 = (unsigned char) Update83D3CField(recordPlus1, unsigned char *, 0x15) - 6;
                        Update83D3CField(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update83D3CField(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x47:
                    temp_v0_17 = Update83D3CField(recordPlus1, unsigned char *, 1) + 1;
                    Update83D3CField(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update83D3CField(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[10] = (short) Update83D3CField(recordPlus1, unsigned short *, 9) - (short) Update83D3CField(recordPlus1, unsigned short *, 3);
                        frame.words[11] = (short) Update83D3CField(recordPlus1, unsigned short *, 0xB) - (short) Update83D3CField(recordPlus1, unsigned short *, 5);
                        frame.words[12] = (short) Update83D3CField(recordPlus1, unsigned short *, 0xD) - (short) Update83D3CField(recordPlus1, unsigned short *, 7);
                        random2=Update83D3Crand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        random2=Update83D3Crand();
                        halfword3=frame.words[11];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[11]=halfword3;
                        random2=Update83D3Crand();
                        halfword3=frame.words[12];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[12]=halfword3;
                        Update83D3CField(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update83D3CField(recordPlus1, unsigned short *, 9) + frame.words[10]);
                        Update83D3CField(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update83D3CField(recordPlus1, unsigned short *, 0xB) + frame.words[11]);
                        Update83D3CField(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update83D3CField(recordPlus1, unsigned short *, 0xD) + frame.words[12]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[10];
                        scratch2=Update83D3CField(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update83D3CField(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[11];
                        scratch2=Update83D3CField(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update83D3CField(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[12];
                        scratch3=Update83D3CField(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update83D3CField(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update83D3CField(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update83D3CField(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update83D3CField(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update83D3CField(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update83D3CField(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update83D3CField(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update83D3CField(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update83D3CField(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x48:
                    temp_v0_18 = Update83D3CField(recordPlus1, unsigned char *, 1) + 1;
                    Update83D3CField(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update83D3CField(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[8] = (int) ((short) Update83D3CField(recordPlus1, unsigned short *, 3) - (short) Update83D3CField(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[9] = (int) ((short) Update83D3CField(recordPlus1, unsigned short *, 5) - (short) Update83D3CField(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[10] = (int) ((short) Update83D3CField(recordPlus1, unsigned short *, 7) - (short) Update83D3CField(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update83D3Crand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        random2=Update83D3Crand();
                        halfword3=frame.words[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[9]=halfword3;
                        random2=Update83D3Crand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        Update83D3CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 3) + frame.words[8]);
                        Update83D3CField(recordPlus1, unsigned short *, 5) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 5) + frame.words[9]);
                        Update83D3CField(recordPlus1, unsigned short *, 7) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 7) + frame.words[10]);
                        __asm__ __volatile__("" ::: "memory");
                        Update83D3CField(recordPlus1, unsigned short *, 9) = (short) (Update83D3CField(recordPlus1, unsigned short *, 3) - (frame.words[8] * 2));
                        Update83D3CField(recordPlus1, unsigned short *, 0xB) = (short) (Update83D3CField(recordPlus1, unsigned short *, 5) - (frame.words[9] * 2));
                        Update83D3CField(recordPlus1, unsigned short *, 0xD) = (short) (Update83D3CField(recordPlus1, unsigned short *, 7) - (frame.words[10] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4E:
                    temp_v0_19 = Update83D3CField(recordPlus1, unsigned char *, 1) + 1;
                    Update83D3CField(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update83D3CField(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update83D3CField(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update83D3CField(recordPlus1, unsigned short *, 0x13);
                        Update83D3CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 3) + Update83D3CField(recordPlus1, unsigned short *, 0xF));
                        Update83D3CField(recordPlus1, unsigned short *, 5) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update83D3CField(recordPlus1, unsigned short *, 7) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update83D3Crand();
                        halfword3=Update83D3CField(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update83D3CField(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update83D3Crand();
                        halfword3=Update83D3CField(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update83D3CField(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update83D3Crand();
                        halfword3=Update83D3CField(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update83D3CField(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update83D3CField(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update83D3CField(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update83D3CField(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update83D3CField(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update83D3CField(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update83D3CField(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update83D3CField(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update83D3CField(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                    case 0x4F:
                    temp_a0_5 = (int) ((short) Update83D3CField(recordPlus1, unsigned short *, 9) - (short) Update83D3CField(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[16] = (unsigned short) temp_a0_5;
                    frame.halves[17] = (unsigned short) ((int) ((short) Update83D3CField(recordPlus1, unsigned short *, 0xB) - (short) Update83D3CField(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[18] = (unsigned short) ((int) ((short) Update83D3CField(recordPlus1, unsigned short *, 0xD) - (short) Update83D3CField(recordPlus1, unsigned short *, 7)) >> 1);
                    Update83D3CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update83D3CField(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update83D3CField(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[17];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update83D3CField(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update83D3CField(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[18];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update83D3CField(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update83D3CField(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[16];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update83D3CField(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update83D3CField(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[17];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update83D3CField(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update83D3CField(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[18];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update83D3CField(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update83D3CField(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update83D3CField(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update83D3CField(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update83D3CField(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update83D3CField(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update83D3CField(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update83D3CField(recordPlus1, unsigned char *, 0x13);
                    Update83D3CField(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update83D3CField(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update83D3CField(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                    case 0x52:
                    scratch2=Update83D3CField(recordPlus1,unsigned short*,7);
                    scratch3=Update83D3CField(recordPlus1,unsigned short*,0xD);
                    scratch2+=48;
                    scratch3+=48;
                    Update83D3CField(recordPlus1,unsigned short*,0xD)=scratch3;
                    scratch3=(short)scratch3;
                    Update83D3CField(recordPlus1,unsigned short*,7)=scratch2;
                    if(scratch3<0)goto removeRecord;
                    scratch2=Update83D3CField(recordPlus1,int*,0x17);
                    if(scratch2<scratch3)goto removeRecord;
                    recordPlus1+=32;
                    break;
                    case 0x54:
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,1);
                    scratch2+=1;
                    Update83D3CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=8)goto removeRecord;
                    scratch2=Update83D3CField(recordPlus1,unsigned char*,2);
                    if(scratch2!=0)goto surviving54;
                    removeRecord:
                    Update83D3Cfunc_80056504(record);
                    recordPlus1+=32;
                    break;
                    surviving54:
                    scratch2=Update83D3CField(recordPlus1,unsigned short*,3);
                    scratch3=Update83D3CField(recordPlus1,unsigned short*,0xF);
                    scratch4=Update83D3CField(recordPlus1,unsigned short*,0x11);
                    temp_a1=Update83D3CField(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(temp_a1) : "0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(temp_a1));
                    scratch2+=scratch3;
                    Update83D3CField(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update83D3CField(recordPlus1,unsigned short*,5);
                    scratch3=Update83D3CField(recordPlus1,unsigned short*,7);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch4;
                    scratch3+=temp_a1;
                    Update83D3CField(recordPlus1,unsigned short*,5)=scratch2;
                    Update83D3CField(recordPlus1,unsigned short*,7)=scratch3;
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
#undef Update83D3CHigh
#undef Update83D3CField



