#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008B114.
 * Assembly SHA256 e4710e6894ec2ab9f58a1316a90f13c2b7dab7f43108692db12c5369e7c4d2d1.
 * AI-generated; not human reviewed. Verified case C, including the shared3E
 * table/helper chain, is adapted to every original target instruction. The
 * new selector28 retains all111 original rows: raw counter predicates, signed
 * seven-eighths halfword operations, literal byte branches, random mask/compare,
 * reset stores and original shared entries. These are raw instruction routes;
 * no new gameplay meaning, units/fixed point, helper semantics or cadence is
 * claimed. Step is the original argument, not an inferred time unit.
 * Original1835 instructions and80 owned selectors/targets are mandatory.
 * Original frame0xC0, step48/double50/pointer90 and scratch slots are retained.
 * Step() names destructive initialized T1 stack loads. Quad uses ordinary C
 * allocation to FP; no fixed FP binding. Selector3E uses original saved pointer
 * S7, index S6 and halfword S4 phases. Original sine/cosine T1 base handoffs,
 * ordered field loads, byte clamps and shared removal are explicit.
 * Every constraint input is initialized; original MULT producers precede
 * HI/LO captures. Empty identities and paired .set metadata emit zero CPU
 * words. C emits every CPU instruction. Compiler/assembler/pipeline/flags,
 * original padding and all acceptance gates remain unchanged.
 * Falsification: all native/linked words, conditional/internal targets, every
 * selector, preserved data and full EXE/every-overlay original retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Update8B114Step() ({word9=frame.saved.step48;__asm__("":"=r"(word9):"0"(word9));word9;})
#define Update8B114Step() ({word9=frame.saved.step48;__asm__("":"=r"(word9):"0"(word9));word9;})
int Update8B114func_800359A4(void*,int) __asm__("func_800359A4");
extern int Update8B114D_8006C648 __asm__("D_8006C648");
int Update8B114func_8004E880(int,int,int) __asm__("func_8004E880");
int Update8B114func_8004F2EC(int,int,int,int) __asm__("func_8004F2EC");
int Update8B114func_8004F264(int,int) __asm__("func_8004F264");
int Update8B114func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
#define Update8B114Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update8B114func_8004E9E4(short) __asm__("func_8004E9E4");
int Update8B114func_8004EA2C(short) __asm__("func_8004EA2C");
int Update8B114func_8004F178(void*,void*) __asm__("func_8004F178");
int Update8B114func_8004F504(void*,void*) __asm__("func_8004F504");
int Update8B114func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update8B114func_80056504(void*) __asm__("func_80056504");
extern int Update8B114D_8006C644 __asm__("D_8006C644");
extern unsigned short Update8B114Sin[] __asm__("D_80065920");
extern unsigned short Update8B114Cos[] __asm__("D_800658A0");
extern int (*Update8B114SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
int Update8B114rand(void) __asm__("rand");
extern unsigned char *Update8B114D_8006C554 __asm__("D_8006C554");
extern int Update8B114D_8006C598 __asm__("D_8006C598");
extern int Update8B114D_8006C640 __asm__("D_8006C640");
extern short Update8B114D_8006E040 __asm__("D_8006E040");
extern int Update8B114D_8006E344 __asm__("D_8006E344");
extern unsigned char Update8B114D_80070328[] __asm__("D_80070328");
extern int Update8B114Player48 __asm__("D_80070328 + 0x48");
extern int Update8B114Player284 __asm__("D_80070328 + 0x284");
extern int Update8B114Player280 __asm__("D_80070328 + 0x280");
#define Update8B114High(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})
unsigned char *func_level_44_8008B114(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[32];
        unsigned short halves[64];
        struct {
            int pad[14];
            volatile int step48;
            int pad4C;
            volatile int doubled50;
            int rest[15];
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
    register unsigned char *record __asm__("$19");
    register unsigned char *recordPlus4 __asm__("$21");
    unsigned char *recordPlus24;
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
    record = Update8B114D_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    frame.saved.step48=incomingStep;
    __asm__ volatile("" : "=r"(record) : "0"(record) : "$4","memory");
    scratch4 = Update8B114Field(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    if (scratch3 != scratch2) {
        word9=frame.saved.step48;
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus1=record+1;
        __asm__("":"=r"(recordPlus1),"=r"(word9):"0"(recordPlus1),"1"(word9));
        word9*=2;
        frame.saved.doubled50=word9;
        __asm__ volatile("" ::: "memory");
        word9=frame.saved.step48;
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus4=record+4;
        __asm__("":"=r"(recordPlus4),"=r"(word9):"0"(recordPlus4),"1"(word9));
        quadrupledStep=word9*4;
        __asm__("":"=r"(quadrupledStep):"0"(quadrupledStep));
        word9=(int)(record+0x18);
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus24=(unsigned char*)word9;
        __asm__ volatile("":"=r"(scratch4):"0"(scratch4):"memory");
        scratch3=scratch4&255;
        __asm__("":"=r"(scratch3),"=r"(scratch4):"0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update8B114D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update8B114D_8006C598 == 0) {
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
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8B114Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8B114Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled50;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    scratch3+=word9;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    scratch2-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch3-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0x1:
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8B114Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8B114Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch3+=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    goto checkMasked24;
                case 0x2:
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update8B114Field(recordPlus1,short*,0x1D)!=0)
                    Update8B114Field(recordPlus1,unsigned short*,0x1B)=Update8B114Field(recordPlus1,unsigned short*,0x1B)+1;
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "$8","memory");
                    word9=1;
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled50;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){
                        scratch2=scratch3-quadrupledStep;
                        Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    }
                    else Update8B114Field(recordPlus1,unsigned char*,0xB)=0;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){
                        scratch2=scratch3-quadrupledStep;
                        Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }
                    else Update8B114Field(recordPlus1,unsigned char*,0xC)=0;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    predicate2=scratch3<quadrupledStep;
                    if(!predicate2){
                        __asm__ volatile("" : : "r"(quadrupledStep) : "memory");
                        scratch2=scratch3-quadrupledStep;
                        Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
                    else Update8B114Field(recordPlus1,unsigned char*,0xD)=0;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$3","memory");
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0x9:
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8B114Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8B114Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled50;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch3+=word9;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0xA:
                    scratch3=Update8B114Player48;
                    if(scratch3==30 && Update8B114Player280<0)goto removeRecord;
                    playerEnd=Update8B114D_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update8B114Field(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update8B114Player284==0)goto removeRecord;
                    Update8B114func_8004F178(&frame.words[0],playerEnd-0x288);
                    scratch2=Update8B114func_8004EA2C(Update8B114Field(recordPlus1, short *, 0x17));
                    scratch3=frame.words[0];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[0]=scratch3;
                    scratch2=Update8B114func_8004E9E4(Update8B114Field(recordPlus1, short *, 0x17));
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
                    Update8B114func_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update8B114Field(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update8B114Field(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update8B114D_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update8B114func_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    high7=Update8B114High(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=high7>>6;
                    scratch3-=scratch2;
                    Update8B114Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                case 0xB:
                    scratch2=Update8B114Field(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){
                        scratch2=Update8B114Field(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update8B114Field(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch6) : "0"(scratch4),"1"(playerEnd),"2"(scratch6));
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=1;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update8B114func_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update8B114Field(recordPlus1, unsigned char *, 9);
                    word9=frame.saved.doubled50;
                    scratch3=Update8B114Field(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update8B114Field(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update8B114Field(recordPlus1, unsigned char *, 0xA);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update8B114Field(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update8B114Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=quadrupledStep;
                    Update8B114Field(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update8B114Field(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update8B114Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update8B114Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                case 0xC:
                    Update8B114Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update8B114Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update8B114func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update8B114Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update8B114Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update8B114Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update8B114Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update8B114Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update8B114Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update8B114Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0xD:
                    if((unsigned int)Update8B114Field(recordPlus1,unsigned char*,1)>=28)goto removeRecord;
                    if(Update8B114Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update8B114Field(recordPlus1,short*,0x1D)!=0)
                    Update8B114Field(recordPlus1,unsigned short*,0x1B)=Update8B114Field(recordPlus1,unsigned short*,0x1B)+1;
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$8");
                    word9=1;
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled50;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    predicate2=(unsigned int)scratch3<13;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(!predicate2){
                        scratch2=(scratch3-12)*8;
                        scratch3=128;
                        scratch2=scratch3-scratch2;
                        if(scratch2<0)scratch2=0;
                        scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                        Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=64;
                        scratch3=(scratch3-12)*4;
                        scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update8B114Field(recordPlus1,unsigned char*,0xD)=0;
                    }
                    else {
                        predicate2=(unsigned int)scratch3<5;
                        if(!predicate2){
                            scratch2=128;
                            scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                            Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                            scratch2=-128;
                            Update8B114Field(recordPlus1,unsigned char*,0xD)=0;
                            scratch3=(scratch3-4)*8;
                            scratch2-=scratch3;
                            Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        }
                        else{
                            scratch2=128;
                            scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                            Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                            Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                            __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2","memory");
                            scratch2=128;
                            scratch3*=32;
                            scratch2-=scratch3;
                            if(scratch2<0)scratch2=0;
                            Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        }
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                case 0x21:
                    Update8B114func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update8B114Field(recordPlus1, short *, 0x1D) != 0) {
                        Update8B114Field(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    word9=frame.saved.doubled50;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2),"=r"(word9),"=r"(scratch3) : "0"(scratch2),"1"(word9),"2"(scratch3));
                    scratch4=scratch2-word9;
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    word9=1;
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled50;
                    scratch3+=word9;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch3;
                    if (scratch4 < 0) {
                        scratch4 = 0;
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("":"=r"(scratch2):"0"(scratch2):"memory");
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch4;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch4;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch4;
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=32)goto removeRecord;
                    if(Update8B114Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    if(scratch4==0)goto removeRecord;
                    goto nextRecord;
                case 0x27:
                    scratch2=Update8B114Field(recordPlus1,short*,0x17);
                    if(scratch2>0){
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3-1;
                    }
                    else{
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3+1;
                    }
                    Update8B114Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,short*,0x19);
                    if(scratch2>0){
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3-1;
                    }
                    else{
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch3) : "0"(scratch3));
                        scratch2=scratch3+1;
                    }
                    Update8B114Field(recordPlus1,unsigned short*,0x19)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1B);
                    scratch2+=1;
                    Update8B114Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    scratch2<<=16;
                    scratch2>>=16;
                    if(scratch2>=25)Update8B114Field(recordPlus1,unsigned short*,0x1B)=24;
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    word9=(int)Update8B114Sin;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch3=Update8B114Field(recordPlus1,unsigned short*,3);
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"memory");
                    scratch2=(scratch2<<4)&0x1F0;
                    scratch2+=word9;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=(int)Update8B114Cos;
                    __asm__ volatile("":"=r"(word9),"=r"(scratch2):"0"(word9),"1"(scratch2):"memory");
                    scratch4=Update8B114Field((void*)scratch2,unsigned short*,0);
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__("":"=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch4=(scratch4<<16)>>25;
                    scratch3+=scratch4;
                    scratch2=(scratch2<<4)&0x1F0;
                    scratch2+=word9;
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    Update8B114Field(recordPlus1,unsigned short*,3)=scratch3;
                    scratch3=Update8B114Field((void*)scratch2,unsigned short*,0);
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,5);
                    scratch4=Update8B114Field(recordPlus1,unsigned char*,0xA);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=25;
                    scratch2+=scratch3;
                    Update8B114Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch4==0 || (Update8B114D_8006C640&1)!=0){
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                        scratch2+=1;
                        Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch2=Update8B114func_800359A4(record+2,1);
                    if(scratch2!=0)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xA);
                    __asm__ volatile("":"=r"(scratch2):"0"(scratch2),"i"(0x8008B964));
                    if(scratch2==0)goto checkByte2;
                    recordPlus1+=32;
                    break;
                case 0x28:
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8B114Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8B114Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    halfword3=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    halfword3=word9-halfword3;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=halfword3;
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2<30){
                        scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                        if((unsigned int)scratch3<100){
                            scratch2=scratch3+quadrupledStep;
                            Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                        goto fields28;
                    }
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                    if((unsigned int)scratch3>=5){
                        scratch2=scratch3-Update8B114Step();
                        Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch3=Update8B114Field(recordPlus1,short*,0x17);
                    scratch2=scratch3<<3;
                    scratch2-=scratch3;
                    scratch3=Update8B114Field(recordPlus1,short*,0x19);
                    scratch2>>=3;
                    Update8B114Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=scratch3<<3;
                    scratch2-=scratch3;
                    scratch3=Update8B114Field(recordPlus1,short*,0x1B);
                    scratch2>>=3;
                    Update8B114Field(recordPlus1,unsigned short*,0x19)=scratch2;
                    scratch2=scratch3<<3;
                    scratch2-=scratch3;
                    scratch2>>=3;
                    Update8B114Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                fields28:
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    __asm__ volatile("":"=r"(scratch2):"0"(scratch2):"memory");
                    if((unsigned int)scratch2>=11){
                        __asm__ volatile("" ::: "memory");
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                        word9=frame.saved.doubled50;
                        scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                        scratch2-=word9;
                        Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,0xC);
                        scratch3-=word9;
                        Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                        scratch2-=word9;
                        Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        goto finish28;
                    }
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch3>=2){
                        scratch2=scratch3-1;
                        Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    }
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    if((unsigned int)scratch3>=2){
                        scratch2=scratch3-1;
                        Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    if((unsigned int)scratch3>=2){
                        scratch2=scratch3-1;
                        Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
                finish28:
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=60){
                        scratch2=Update8B114rand();
                        scratch2&=15;
                        scratch3=7;
                        if(scratch2==scratch3){
                            scratch2=96;
                            Update8B114Field(recordPlus1,unsigned char*,1)=0;
                            Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                            Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                            Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch2;
                            __asm__ volatile("" ::: "$9","memory");
                            word9=1;
                            __asm__("":"=r"(word9):"0"(word9));
                            *record=word9;
                        }
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    predicate2=(unsigned int)scratch2<121;
                    goto checkPredicate;
                case 0x29:
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=1;
                    scratch8=scratch2&255;
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    if((unsigned int)scratch3<(unsigned int)scratch8){
                        if(Update8B114Field(recordPlus1,unsigned char*,0x1E)==0)goto removeRecord;
                        Update8B114SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update8B114Field(recordPlus1,short*,0x17);
                    scratch7=Update8B114Field(recordPlus1,short*,0x11);
                    __asm__("" : "=r"(scratch2),"=r"(scratch7) : "0"(scratch2),"1"(scratch7));
                    scratch2-=scratch7;
                    scratch2*=scratch8;
                    scratch8=scratch2/scratch3;
                    scratch6=Update8B114Field(recordPlus1,short*,0x13);
                    scratch2=Update8B114Field(recordPlus1,short*,0x19);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                    scratch2-=scratch6;
                    scratch2*=scratch3;
                    scratch5=Update8B114Field(recordPlus1,unsigned char*,0x1D);
                    scratch5=scratch2/scratch5;
                    word9=(int)Update8B114Sin;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch4=Update8B114Field(recordPlus1,unsigned short*,0x15);
                    __asm__ volatile("" : "=r"(scratch4) : "0"(scratch4) : "memory");
                    scratch3=Update8B114Field(recordPlus1,unsigned short*,0x15);
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,7);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=2;
                    Update8B114Field(recordPlus1,unsigned short*,0x15)=scratch3;
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2+=scratch4;
                    Update8B114Field(recordPlus1,unsigned short*,7)=scratch2;
                    scratch2=Update8B114D_8006C644;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch2*=2;
                    scratch2+=word9;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=(int)Update8B114Cos;
                    __asm__ volatile("":"=r"(word9):"0"(word9):"memory");
                    scratch7+=scratch8;
                    Update8B114Field(recordPlus1,unsigned short*,3)=scratch7;
                    scratch6+=scratch5;
                    Update8B114Field(recordPlus1,unsigned short*,5)=scratch6;
                    scratch2=Update8B114Field((void*)scratch2,unsigned short*,0);
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=26;
                    scratch2+=10;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update8B114D_8006C644;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch2*=2;
                    scratch2+=word9;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    scratch2=Update8B114Field((void*)scratch2,unsigned short*,0);
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=27;
                    scratch2+=6;
                    Update8B114Field(recordPlus1,unsigned char*,0xA)=scratch2;
                    goto nextRecord;
                case 0x2A:
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update8B114Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    scratch4=Update8B114Field(recordPlus1,short*,0x11);
                    scratch5=Update8B114Field(recordPlus1,short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(scratch5) : "0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(scratch5));
                    scratch2+=2;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=6;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=6;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,int*,0x17);
                    scratch3-=6;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,int*,0x1B);
                    scratch2+=scratch4;
                    Update8B114Field(recordPlus1,int*,0x17)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update8B114Field(recordPlus1,int*,0x17);
                    scratch3+=scratch5;
                    Update8B114Field(recordPlus1,int*,0x1B)=scratch3;
                    __asm__ volatile("" ::: "memory");
                    scratch3=Update8B114Field(recordPlus1,int*,0x1B);
                    scratch2>>=2;
                    scratch3>>=2;
                    Update8B114Field(recordPlus1,unsigned short*,3)=scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,5)=scratch3;
                    goto nextRecord;
                case 0x2B:
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch2<4)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,short*,0x17);
                    temp_a1=3;
                    if(scratch2!=0)temp_a1=2;
                    scratch4=Update8B114Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch4),"=r"(temp_a1) : "0"(scratch4),"1"(temp_a1) : "memory");
                    scratch3=Update8B114Field(recordPlus1,short*,0x17);
                    scratch2=scratch4+1;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(scratch3!=0){
                        scratch2=scratch4+2;
                        Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=temp_a1;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=temp_a1;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2-=temp_a1;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    goto nextRecord;
                case 0x2C:
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update8B114Field(recordPlus1,unsigned short*,0x11);
                    scratch3=Update8B114Field(recordPlus1,unsigned short*,0x19);
                    scratch5=Update8B114Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3),"=r"(scratch5) : "0"(scratch2),"1"(scratch4),"2"(scratch3),"3"(scratch5));
                    scratch2+=scratch4;
                    scratch3+=scratch5;
                    Update8B114Field(recordPlus1,unsigned short*,0x19)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned short*,7);
                    scratch4=Update8B114Field(recordPlus1,unsigned short*,0x15);
                    __asm__ volatile("":"=r"(scratch3),"=r"(scratch4):"0"(scratch3),"1"(scratch4):"$9","memory");
                    word9=(int)Update8B114Sin;
                    __asm__("":"=r"(word9):"0"(word9));
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4):"memory");
                    Update8B114Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0x1B);
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4):"memory");
                    scratch3+=scratch4;
                    scratch2*=2;
                    scratch2+=word9;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=(int)Update8B114Cos;
                    __asm__ volatile("":"=r"(word9):"0"(word9):"memory");
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    Update8B114Field(recordPlus1,unsigned short*,7)=scratch3;
                    scratch3=Update8B114Field((void*)scratch2,unsigned short*,0);
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x17);
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"memory");
                    scratch4=Update8B114Field(recordPlus1,unsigned char*,0x1B);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=24;
                    scratch2+=scratch3;
                    scratch4*=2;
                    scratch4+=word9;
                    __asm__("":"=r"(scratch4):"0"(scratch4));
                    Update8B114Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0x1B);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0x1C);
                    scratch4=Update8B114Field((void*)scratch4,unsigned short*,0);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2+=scratch3;
                    scratch4<<=16;
                    scratch4>>=24;
                    Update8B114Field(recordPlus1,unsigned char*,0x1B)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x19);
                    scratch3=Update8B114D_8006C640;
                    scratch2+=scratch4;
                    scratch3&=3;
                    Update8B114Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch3==0){
                        scratch2=Update8B114Field(recordPlus1,short*,0x15);
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        if(scratch2<9){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update8B114Field(recordPlus1,unsigned short*,0x15)=scratch2;
                        }
                        scratch3=Update8B114Field(recordPlus1,unsigned char*,9);
                        if((unsigned int)scratch3<20){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                    }
                    scratch2=Update8B114Field(recordPlus1,short*,7);
                    scratch3=Update8B114Field(recordPlus1,short*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2>=scratch3){
                        scratch3=Update8B114Field(recordPlus1,unsigned char*,0x10);
                        scratch2=3;
                        if(scratch3!=scratch2)goto removeRecord;
                    sharedSpawn43:
                        Update8B114SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    if(scratch2==0)goto removeRecord;
                    __asm__ volatile("" ::: "memory");
                    goto checkByte2;
                case 0x2E:
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update8B114Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=3;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=8;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=8;
                    scratch3-=8;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto nextRecord;
                case 0x32:
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    if(scratch2==0)goto nextRecord;
                    scratch2=Update8B114D_8006C648;
                    scratch4=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch3=(scratch2<<3)-scratch2;
                    scratch4-=scratch3;
                    if(scratch4<0)scratch4=0;
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch4;
                    if(Update8B114func_800359A4(record+2,1)!=0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                case 0x37:
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3));
                    scratch2=scratch3+Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129){
                        scratch2=128;
                        Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch4=Update8B114Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch4<17) {
                        scratch2=256;
                        goto addedEarlyAge;
                    }
                    predicate2=scratch3<17;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(predicate2)Update8B114SpawnParticle(1,56,record,0);
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch2-=16;
                    scratch3=scratch2*8;
                    scratch2=256;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3<0)scratch3=0;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3>>=1;
                    if(scratch3>=scratch2)goto nextRecord;
                addedStoreByteC:
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    goto nextRecord;
                addedEarlyAge:
                    scratch3=scratch4*16;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3>=32)goto addedStoreByteC;
                    scratch3=32;
                    goto addedStoreByteC;
                case 0x38:
                    Update8B114func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129){
                        scratch2=128;
                        Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    __asm__ volatile("" : : "r"(quadrupledStep) : "$4","memory");
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2");
                    if((unsigned int)scratch3<16)scratch2=scratch3*4;
                    else {
                        scratch2=48;
                        scratch2-=scratch3;
                        scratch2*=2;
                    }
                    if(scratch2<=0)goto removeRecord;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    goto nextRecord;
                case 0x3B:
                    Update8B114Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update8B114Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update8B114func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update8B114D_8006C640 & 1) {
                        Update8B114Field(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update8B114Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update8B114Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update8B114Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update8B114Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update8B114Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update8B114Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update8B114Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0x3D:
                    if(Update8B114Field(recordPlus1,short*,0x1D)!=0)
                    Update8B114Field(recordPlus1,unsigned short*,0x1B)=Update8B114Field(recordPlus1,unsigned short*,0x1B)+1;
                    word9=1;
                    scratch2=Update8B114Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xC);
                    scratch2=word9-scratch2;
                    Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update8B114Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                    scratch3-=quadrupledStep;
                    Update8B114Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$3","memory");
                    scratch2+=Update8B114Step();
                    Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$8","memory");
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0x3E:
                    {
                        register unsigned char *state23 __asm__("$23");
                        register unsigned char *table18 __asm__("$18");
                        register int index22 __asm__("$22");
                        register int angle20 __asm__("$20");
                        register int raw17 __asm__("$17");
                        state23=recordPlus24;
                        table18=Update8B114Field(recordPlus1,unsigned char**,0x17);
                        __asm__ volatile("":"=r"(state23),"=r"(table18):"0"(state23),"1"(table18):"memory");
                        index22=Update8B114Field(recordPlus1,short*,0x1B);
                        angle20=Update8B114Field(recordPlus1,short*,0x1D);
                        raw17=6;
                        if(index22==0){
                            __asm__ volatile("":"=r"(index22):"0"(index22));
                            scratch7=Update8B114Field(recordPlus1,unsigned short*,3);
                            scratch7*=4;
                            frame.words[8]=scratch7;
                            scratch3=Update8B114Field(recordPlus1,unsigned short*,5);
                            scratch3*=4;
                            frame.words[9]=scratch3;
                            scratch2=Update8B114Field(recordPlus1,unsigned short*,7);
                            scratch2*=4;
                            frame.words[10]=scratch2;
                            scratch2=Update8B114Field(table18,int*,0xC);
                            scratch6=0;
                            scratch4=Update8B114Field((void*)scratch2,int*,0);
                            playerEnd=(unsigned char*)Update8B114Field((void*)scratch2,int*,4);
                            scratch4-=scratch7;
                            scratch2=Update8B114func_8004E880(scratch4,(int)playerEnd-scratch3,scratch6);
                            scratch2=Update8B114func_8004F2EC(scratch2,angle20,1,1);
                            Update8B114Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                            scratch3=Update8B114Field(table18,int*,0xC);
                            scratch2=frame.words[10];
                            scratch3=Update8B114Field((void*)scratch3,int*,8);
                            scratch2-=2200;
                            scratch3=scratch2-scratch3;
                            predicate2=scratch3<1501;
                            if(!predicate2){
                                scratch2=Update8B114Field(recordPlus1,unsigned short*,7);
                                scratch2-=75;
                                Update8B114Field(recordPlus1,unsigned short*,7)=scratch2;
                                goto join3E;
                            }
                            predicate2=scratch3 < -1500;
                            if(predicate2){
                                scratch2=Update8B114Field(recordPlus1,unsigned short*,7);
                                scratch2+=75;
                                Update8B114Field(recordPlus1,unsigned short*,7)=scratch2;
                            }
                        }
                        else{
                            scratch3=Update8B114Field(table18,short*,0);
                            var_a1=index22+1;
                            predicate2=var_a1<scratch3;
                            __asm__ volatile(".set	noreorder" : "=r"(predicate2) : "0"(predicate2));
                            if(!predicate2){
                                scratch4=(int)&frame.words[4];
                                __asm__ volatile(".set	reorder" : "=r"(scratch4) : "0"(scratch4));
                                var_a1=scratch3-1;
                                scratch2=Update8B114Field(table18,int*,0xC);
                                scratch6=var_a1<<4;
                                var_a1=scratch2+scratch6;
                                scratch6-=16;
                                scratch6+=scratch2;
                            }
                            else{
                                scratch4=(int)&frame.words[4];
                                __asm__ volatile(".set	reorder" : "=r"(scratch4) : "0"(scratch4));
                                __asm__ volatile("":"=r"(var_a1):"0"(var_a1),"r"(scratch4),"i"(0x8008C36C));
                                var_a1<<=4;
                                scratch6=Update8B114Field(table18,int*,0xC);
                                __asm__("":"=r"(index22):"0"(index22));
                                scratch2=index22<<4;
                                var_a1=scratch6+var_a1;
                                scratch6+=scratch2;
                            }
                            Update8B114func_8004F1C8((void*)scratch4,(void*)var_a1,(void*)scratch6);
                            scratch4=frame.words[4];
                            var_a1=frame.words[5];
                            scratch2=Update8B114func_8004E880(scratch4,var_a1,0);
                            scratch4=scratch2;
                            var_a1=angle20;
                            __asm__("":"=r"(scratch4),"=r"(var_a1):"0"(scratch4),"1"(var_a1));
                            scratch6=raw17;
                            scratch7=(scratch6>>1)+1;
                            scratch2=Update8B114func_8004F2EC(scratch4,var_a1,scratch6,scratch7);
                            Update8B114Field(state23,unsigned short*,6)=scratch2;
                        }
                    join3E:
                        raw17=350;
                        if(index22==0)raw17=100;
                        scratch3=angle20<<1;
                        word9=(int)Update8B114Sin;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=scratch3+word9;
                        __asm__("":"=r"(scratch2):"0"(scratch2));
                        scratch2=Update8B114Field((void*)scratch2,short*,0);
                        word9=raw17*scratch2;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=word9>>12;
                        word9=(int)Update8B114Cos;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch3+=word9;
                        __asm__ volatile("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"memory");
                        frame.halves[24]=scratch2;
                        scratch2=Update8B114Field((void*)scratch3,short*,0);
                        word9=raw17*scratch2;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=word9>>12;
                        frame.halves[26]=0;
                        frame.halves[25]=scratch2;
                        Update8B114func_8004F5A8(recordPlus4,recordPlus4,&frame.halves[24]);
                        word9=(int)Update8B114Sin;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                        scratch3=Update8B114Field(recordPlus1,unsigned short*,3);
                        __asm__ volatile("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"memory");
                        scratch2=(scratch2<<4)&0x1F0;
                        scratch2+=word9;
                        __asm__("":"=r"(scratch2):"0"(scratch2));
                        word9=(int)Update8B114Cos;
                        __asm__ volatile("":"=r"(word9),"=r"(scratch2):"0"(word9),"1"(scratch2):"memory");
                        scratch4=Update8B114Field((void*)scratch2,unsigned short*,0);
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                        __asm__("":"=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch4=(scratch4<<16)>>25;
                        scratch3+=scratch4;
                        scratch2=(scratch2<<4)&0x1F0;
                        scratch2+=word9;
                        __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                        Update8B114Field(recordPlus1,unsigned short*,3)=scratch3;
                        scratch3=Update8B114Field((void*)scratch2,unsigned short*,0);
                        scratch2=Update8B114Field(recordPlus1,unsigned short*,5);
                        scratch8=Update8B114Field(recordPlus1,unsigned short*,3);
                        __asm__("":"=r"(scratch3),"=r"(scratch2),"=r"(scratch8):"0"(scratch3),"1"(scratch2),"2"(scratch8));
                        scratch3=(scratch3<<16)>>25;
                        scratch2+=scratch3;
                        scratch8*=4;
                        Update8B114Field(recordPlus1,unsigned short*,5)=scratch2;
                        frame.words[4]=scratch8;
                        scratch7=Update8B114Field(recordPlus1,unsigned short*,5);
                        scratch7*=4;
                        frame.words[5]=scratch7;
                        scratch2=Update8B114Field(recordPlus1,unsigned short*,7);
                        scratch6=0;
                        scratch2*=4;
                        frame.words[6]=scratch2;
                        scratch3=Update8B114Field(table18,int*,0xC);
                        scratch2=index22<<4;
                        scratch2+=scratch3;
                        scratch4=Update8B114Field((void*)scratch2,int*,0);
                        var_a1=Update8B114Field((void*)scratch2,int*,4);
                        scratch4-=scratch8;
                        var_a1-=scratch7;
                        scratch2=Update8B114func_8004E880(scratch4,var_a1,scratch6);
                        scratch2=Update8B114func_8004F264(scratch2,Update8B114Field(state23,short*,6));
                        if(scratch2>=65){
                            scratch2=Update8B114Field(state23,unsigned short*,4);
                            scratch2+=1;
                            Update8B114Field(state23,unsigned short*,4)=scratch2;
                            __asm__("":"=r"(scratch2):"0"(scratch2));
                            scratch2<<=16;
                            scratch3=Update8B114Field(table18,short*,0);
                            scratch2>>=16;
                            predicate2=scratch2<scratch3;
                            scratch4=scratch3;
                            if(!predicate2){
                                __asm__ volatile("":"=r"(scratch4):"0"(scratch4),"i"(0x8008C500));
                                scratch2=scratch4-1;
                                Update8B114Field(state23,unsigned short*,4)=scratch2;
                            }
                        }
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,0xA);
                        if(scratch2==0 || (Update8B114D_8006C640&1)!=0){
                            scratch2=Update8B114Field(recordPlus1,unsigned char*,9);
                            scratch2+=1;
                            Update8B114Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                        scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                        scratch3=scratch2+1;
                        predicate2=(unsigned int)scratch2<101;
                        Update8B114Field(recordPlus1,unsigned char*,1)=scratch3;
                        if(!predicate2)goto removeRecord;
                        if(index22==0)goto nextRecord;
                        scratch2=scratch3&255;
                        if((unsigned int)scratch2<11)goto nextRecord;
                        if(Update8B114Field(recordPlus1,unsigned char*,0xA)==0)goto checkByte2;
                        goto nextRecord;
                    }
                case 0x42:
                    word9=frame.saved.step48;
                    __asm__("":"=r"(word9):"0"(word9));
                    iteration=0;
                    if(word9>0) {
                        do {
                            if (Update8B114Field(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update8B114Field(recordPlus1, unsigned short *, 3);
                                scratch4=Update8B114Field(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update8B114Field(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update8B114Field(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update8B114Field(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update8B114Field(recordPlus1, unsigned short *, 7);
                                scratch4=Update8B114Field(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update8B114Field(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update8B114Field(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update8B114Field(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update8B114rand();
                                    halfword3=Update8B114Field(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update8B114Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update8B114rand();
                                    halfword3=Update8B114Field(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update8B114Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update8B114rand();
                                    halfword3=Update8B114Field(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update8B114Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                            scratch2+=1;
                            Update8B114Field(recordPlus1,unsigned char*,1)=scratch2;
                            word9=frame.saved.step48;
                            __asm__("":"=r"(word9):"0"(word9));
                            __asm__("":"=r"(iteration),"=r"(word9):"0"(iteration),"1"(word9));
                            iteration+=1;
                            predicate2=iteration<word9;
                            __asm__("":"=r"(predicate2):"0"(predicate2));
                        }
                        while(predicate2);
                    }
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,1);
                checkMasked24:
                    predicate2=(unsigned int)scratch2<24;
                    goto checkPredicate;
                checkPredicate:
                    if(predicate2==0)goto removeRecord;
                checkByte2:
                    if(Update8B114Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                case 0x46:
                    temp_v0_11 = Update8B114Field(recordPlus1, unsigned char *, 1) + 1;
                    Update8B114Field(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update8B114Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update8B114Field(recordPlus1, unsigned short *, 9) - (short) Update8B114Field(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[16] = (unsigned short) temp_a0_3;
                        frame.halves[17] = (unsigned short) ((int) ((short) Update8B114Field(recordPlus1, unsigned short *, 0xB) - (short) Update8B114Field(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[18] = (unsigned short) ((int) ((short) Update8B114Field(recordPlus1, unsigned short *, 0xD) - (short) Update8B114Field(recordPlus1, unsigned short *, 7)) >> 1);
                        Update8B114Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update8B114Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 5) + frame.halves[17]);
                        Update8B114Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 7) + frame.halves[18]);
                        random2=Update8B114rand();
                        halfword3=frame.halves[16];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[16]=halfword3;
                        random2=Update8B114rand();
                        halfword3=frame.halves[17];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[17]=halfword3;
                        if (Update8B114Field(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[18] -= 1;
                        }
                        random2=Update8B114Field(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[16];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update8B114Field(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update8B114Field(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[17];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update8B114Field(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update8B114Field(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[18];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update8B114Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update8B114Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128)Update8B114Field(recordPlus1, unsigned char *, 0xF)=128;
                        temp_v0_13 = Update8B114Field(recordPlus1, unsigned char *, 0x10) - 4;
                        Update8B114Field(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update8B114Field(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update8B114Field(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update8B114Field(recordPlus1, unsigned char *, 0x13) - 3;
                        Update8B114Field(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update8B114Field(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        temp_v0_15 = Update8B114Field(recordPlus1, unsigned char *, 0x14) - 4;
                        Update8B114Field(recordPlus1, unsigned char *, 0x14) = temp_v0_15;
                        if ((unsigned int) (temp_v0_15 & 0xFF) < 0x80U) {
                            Update8B114Field(recordPlus1, unsigned char *, 0x14) = 0x80U;
                        }
                        temp_v0_16 = (unsigned char) Update8B114Field(recordPlus1, unsigned char *, 0x15) - 6;
                        Update8B114Field(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update8B114Field(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x47:
                    temp_v0_17 = Update8B114Field(recordPlus1, unsigned char *, 1) + 1;
                    Update8B114Field(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update8B114Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[8] = (short) Update8B114Field(recordPlus1, unsigned short *, 9) - (short) Update8B114Field(recordPlus1, unsigned short *, 3);
                        frame.words[9] = (short) Update8B114Field(recordPlus1, unsigned short *, 0xB) - (short) Update8B114Field(recordPlus1, unsigned short *, 5);
                        frame.words[10] = (short) Update8B114Field(recordPlus1, unsigned short *, 0xD) - (short) Update8B114Field(recordPlus1, unsigned short *, 7);
                        random2=Update8B114rand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        random2=Update8B114rand();
                        halfword3=frame.words[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[9]=halfword3;
                        random2=Update8B114rand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        Update8B114Field(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update8B114Field(recordPlus1, unsigned short *, 9) + frame.words[8]);
                        Update8B114Field(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update8B114Field(recordPlus1, unsigned short *, 0xB) + frame.words[9]);
                        Update8B114Field(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update8B114Field(recordPlus1, unsigned short *, 0xD) + frame.words[10]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[8];
                        scratch2=Update8B114Field(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update8B114Field(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[9];
                        scratch2=Update8B114Field(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update8B114Field(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[10];
                        scratch3=Update8B114Field(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update8B114Field(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update8B114Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update8B114Field(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update8B114Field(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update8B114Field(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update8B114Field(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update8B114Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update8B114Field(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update8B114Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x48:
                    temp_v0_18 = Update8B114Field(recordPlus1, unsigned char *, 1) + 1;
                    Update8B114Field(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update8B114Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[8] = (int) ((short) Update8B114Field(recordPlus1, unsigned short *, 3) - (short) Update8B114Field(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[9] = (int) ((short) Update8B114Field(recordPlus1, unsigned short *, 5) - (short) Update8B114Field(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[10] = (int) ((short) Update8B114Field(recordPlus1, unsigned short *, 7) - (short) Update8B114Field(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update8B114rand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        random2=Update8B114rand();
                        halfword3=frame.words[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[9]=halfword3;
                        random2=Update8B114rand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        Update8B114Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 3) + frame.words[8]);
                        Update8B114Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 5) + frame.words[9]);
                        Update8B114Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 7) + frame.words[10]);
                        __asm__ __volatile__("" ::: "memory");
                        Update8B114Field(recordPlus1, unsigned short *, 9) = (short) (Update8B114Field(recordPlus1, unsigned short *, 3) - (frame.words[8] * 2));
                        Update8B114Field(recordPlus1, unsigned short *, 0xB) = (short) (Update8B114Field(recordPlus1, unsigned short *, 5) - (frame.words[9] * 2));
                        Update8B114Field(recordPlus1, unsigned short *, 0xD) = (short) (Update8B114Field(recordPlus1, unsigned short *, 7) - (frame.words[10] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4E:
                    temp_v0_19 = Update8B114Field(recordPlus1, unsigned char *, 1) + 1;
                    Update8B114Field(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update8B114Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update8B114Field(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update8B114Field(recordPlus1, unsigned short *, 0x13);
                        Update8B114Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 3) + Update8B114Field(recordPlus1, unsigned short *, 0xF));
                        Update8B114Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update8B114Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update8B114rand();
                        halfword3=Update8B114Field(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update8B114Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update8B114rand();
                        halfword3=Update8B114Field(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update8B114Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update8B114rand();
                        halfword3=Update8B114Field(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update8B114Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update8B114Field(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update8B114Field(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update8B114Field(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update8B114Field(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update8B114Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update8B114Field(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update8B114Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update8B114Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4F:
                    temp_a0_5 = (int) ((short) Update8B114Field(recordPlus1, unsigned short *, 9) - (short) Update8B114Field(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[16] = (unsigned short) temp_a0_5;
                    frame.halves[17] = (unsigned short) ((int) ((short) Update8B114Field(recordPlus1, unsigned short *, 0xB) - (short) Update8B114Field(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[18] = (unsigned short) ((int) ((short) Update8B114Field(recordPlus1, unsigned short *, 0xD) - (short) Update8B114Field(recordPlus1, unsigned short *, 7)) >> 1);
                    Update8B114Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8B114Field(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update8B114Field(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[17];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update8B114Field(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update8B114Field(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[18];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update8B114Field(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update8B114Field(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[16];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update8B114Field(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update8B114Field(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[17];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update8B114Field(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update8B114Field(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update8B114Field(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[18];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update8B114Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update8B114Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update8B114Field(recordPlus1,unsigned char*,2);
                    if(scratch2!=0)goto surviving4F;
                removeRecord:
                    Update8B114func_80056504(record);
                    recordPlus1+=32;
                    break;
                    surviving4F:;
                    scratch2=Update8B114Field(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update8B114Field(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update8B114Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update8B114Field(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update8B114Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update8B114Field(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update8B114Field(recordPlus1, unsigned char *, 0x13);
                    Update8B114Field(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update8B114Field(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update8B114Field(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                    default:goto nextRecord;
                }
            }
            else {
            nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus4+=0x20;
            word9=(int)recordPlus24;
            __asm__("":"=r"(word9):"0"(word9));
            word9+=0x20;
            recordPlus24=(unsigned char*)word9;
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
#undef Update8B114High
#undef Update8B114Field
#undef Update8B114Step
#undef Update8B114Step
