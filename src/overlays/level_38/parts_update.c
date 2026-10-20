#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008537C.
 * Assembly SHA256 48ed6c0bfadd9c39e21ec00f8684db5abdb88d7b9ef0d5d2198ff6688b8f4b98.
 * AI-generated; not human reviewed. Verified sibling C cases are adapted to
 * every original instruction; selector0x3E is decoded from its complete194
 * original rows. It retains count0/data0xC table accesses,16-byte index strides,
 * record+0x18 fields, saved halfword20, raw6/350/100 phases, helper arguments,
 * signed/unsigned table loads, literal shifts and distinct original branches.
 * The saved halfword20 is not refreshed after either original helper store.
 * All raw access widths, constants, stack offsets and shared entries remain
 * original. Physical units/fixed point, complete helper contracts and caller
 * cadence are unresolved. Step is the original argument, not a time unit.
 * Original1419 instructions and80 owned selectors/targets are mandatory.
 * Original frame0xC0, double58/quad60/pointer90 and vector/halfword scratch
 * slots are retained. Step uses ordinary C allocation to FP; no fixed FP
 * binding. Original counters0/1/D, selector14 limit17 and1E saved pointer S1
 * remain concrete original routes. All constraint operands are initialized;
 * original MULT producers precede every HI/LO capture. Paired .set scheduling
 * metadata retains the original BNE/address-delay pair. Empty metadata with
 * original branch identities emits zero CPU instructions. C emits every CPU
 * instruction; compiler/assembler/pipeline/flags/padding/gates are unchanged.
 * Falsification: all native/linked words, conditional/internal targets, every
 * selector, preserved data and full EXE/every-overlay original retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
int Update8537Cfunc_8004E880(int,int,int) __asm__("func_8004E880");
int Update8537Cfunc_8004F2EC(int,int,int,int) __asm__("func_8004F2EC");
int Update8537Cfunc_8004F264(int,int) __asm__("func_8004F264");
int Update8537Cfunc_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Update8537Cfunc_8004EDE8(void*,int) __asm__("func_8004EDE8");
int Update8537Cfunc_8004F08C(void*,int,int) __asm__("func_8004F08C");
#define Update8537CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update8537Cfunc_8004E9E4(short) __asm__("func_8004E9E4");
int Update8537Cfunc_8004EA2C(short) __asm__("func_8004EA2C");
int Update8537Cfunc_8004F178(void*,void*) __asm__("func_8004F178");
int Update8537Cfunc_8004F504(void*,void*) __asm__("func_8004F504");
int Update8537Cfunc_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update8537Cfunc_80056504(void*) __asm__("func_80056504");
extern int Update8537CD_8006C644 __asm__("D_8006C644");
extern unsigned short Update8537CSin[] __asm__("D_80065920");
extern unsigned short Update8537CCos[] __asm__("D_800658A0");
extern int (*Update8537CSpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
int Update8537Crand(void) __asm__("rand");
extern unsigned char *Update8537CD_8006C554 __asm__("D_8006C554");
extern int Update8537CD_8006C598 __asm__("D_8006C598");
extern int Update8537CD_8006C640 __asm__("D_8006C640");
extern short Update8537CD_8006E040 __asm__("D_8006E040");
extern int Update8537CD_8006E344 __asm__("D_8006E344");
extern unsigned char Update8537CD_80070328[] __asm__("D_80070328");
extern int Update8537CPlayer48 __asm__("D_80070328 + 0x48");
extern int Update8537CPlayer284 __asm__("D_80070328 + 0x284");
extern int Update8537CPlayer280 __asm__("D_80070328 + 0x280");
#define Update8537CHigh(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})
unsigned char *func_level_38_8008537C(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    int step;
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[32];
        unsigned short halves[64];
        struct {
            int pad[18];
            volatile int doubled58;
            int pad5C;
            volatile int quadrupled60;
            int rest[11];
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
    register unsigned char *recordPlus4 __asm__("$23");
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
    record = Update8537CD_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    step=incomingStep;
    __asm__("" : "=r"(record),"=r"(step) : "0"(record),"1"(step) : "$4");
    scratch4 = Update8537CField(record, unsigned char *, 1);
    __asm__("" : "=r"(scratch4) : "0"(scratch4));
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2=255;
    __asm__("" : "=r"(scratch2) : "0"(scratch2));
    scratch3=scratch4&255;
    __asm__("" : "=r"(scratch3),"=r"(scratch4) : "0"(scratch3),"1"(scratch4));
    __asm__("" : "=r"(step) : "0"(step));
    if (scratch3 != scratch2) {
        word9=step*2;
        __asm__("":"=r"(word9),"=r"(step):"0"(word9),"1"(step));
        frame.saved.doubled58=word9;
        word9=step*4;
        recordPlus1=record+1;
        recordPlus4=record+4;
        __asm__ volatile("":"=r"(recordPlus1),"=r"(recordPlus4),"=r"(word9):"0"(recordPlus1),"1"(recordPlus4),"2"(word9):"memory");
        frame.saved.quadrupled60=word9;
        word9=(int)(record+0x18);
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus24=(unsigned char*)word9;
        __asm__ volatile("":"=r"(scratch4):"0"(scratch4):"memory");
        scratch3=scratch4&255;
        __asm__("":"=r"(scratch3),"=r"(scratch4):"0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update8537CD_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update8537CD_8006C598 == 0) {
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
                    Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8537CField(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update8537CField(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8537CField(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    scratch2=1;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    scratch4=Update8537CField(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update8537CField(recordPlus1,unsigned char*,9);
                    scratch2-=scratch4;
                    Update8537CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled58;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch3+=word9;
                    Update8537CField(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update8537CField(recordPlus1,unsigned char*,0xC);
                    word9=frame.saved.quadrupled60;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,0xB);
                    scratch3-=word9;
                    Update8537CField(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update8537CField(recordPlus1,unsigned char*,0xD);
                    scratch2-=word9;
                    Update8537CField(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    scratch3-=word9;
                    scratch2+=step;
                    Update8537CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    predicate2=(unsigned int)scratch2<32;
                    __asm__ volatile("" : : "i"(0x800854E4));
                    Update8537CField(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                case 0x1:
                    Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8537CField(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update8537CField(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8537CField(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    scratch2=1;
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    scratch4=Update8537CField(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update8537CField(recordPlus1,unsigned char*,9);
                    scratch2-=scratch4;
                    Update8537CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.quadrupled60;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,0xB);
                    scratch3+=word9;
                    Update8537CField(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update8537CField(recordPlus1,unsigned char*,0xC);
                    scratch2-=word9;
                    Update8537CField(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    scratch3-=word9;
                    scratch2+=step;
                    Update8537CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    Update8537CField(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update8537CField(recordPlus1,unsigned char*,0xD);
                    predicate2=(unsigned int)scratch2<24;
                    scratch3-=word9;
                    Update8537CField(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                case 0x9:
                    Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8537CField(recordPlus1, short *, 0x1D);
                    if(scratch2!=0){
                        scratch2=Update8537CField(recordPlus1, unsigned short *, 0x1B);
                        scratch2++;
                        Update8537CField(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    scratch3=Update8537CField(recordPlus1, unsigned short *, 0x1D);
                    __asm__ __volatile__("" ::: "$2", "memory");
                    scratch2=1;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=scratch3;
                    scratch3=Update8537CField(recordPlus1, unsigned char *, 9);
                    Update8537CField(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    word9=frame.saved.doubled58;
                    __asm__("" : "=r"(word9) : "0"(word9) : "$2","memory");
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3+=word9;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2+=step;
                    Update8537CField(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    __asm__("" : "=r"(predicate2),"=r"(scratch3) : "0"(predicate2),"1"(scratch3));
                    Update8537CField(recordPlus1, unsigned char *, 9)=scratch3;
                    goto checkPredicate;
                case 0xA:
                    scratch3=Update8537CPlayer48;
                    if(scratch3==30 && Update8537CPlayer280<0)goto removeRecord;
                    playerEnd=Update8537CD_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update8537CField(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update8537CPlayer284==0)goto removeRecord;
                    Update8537Cfunc_8004F178(&frame.words[0],playerEnd-0x288);
                    scratch2=Update8537Cfunc_8004EA2C(Update8537CField(recordPlus1, short *, 0x17));
                    scratch3=frame.words[0];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[0]=scratch3;
                    scratch2=Update8537Cfunc_8004E9E4(Update8537CField(recordPlus1, short *, 0x17));
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
                    Update8537Cfunc_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update8537CField(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update8537CField(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update8537CD_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update8537Cfunc_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    high7=Update8537CHigh(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=high7>>6;
                    scratch3-=scratch2;
                    Update8537CField(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                case 0xB:
                    scratch2=Update8537CField(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){
                        scratch2=Update8537CField(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update8537CField(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd),"=r"(scratch6) : "0"(scratch4),"1"(playerEnd),"2"(scratch6));
                    scratch3=Update8537CField(recordPlus1, unsigned short *, 0x1D);
                    __asm__ __volatile__("" ::: "$2", "memory");
                    scratch2=1;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=scratch3;
                    Update8537CField(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update8537Cfunc_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 9);
                    word9=frame.saved.doubled58;
                    scratch3=Update8537CField(recordPlus1, unsigned char *, 0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update8537CField(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 0xA);
                    word9=frame.saved.quadrupled60;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update8537CField(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update8537CField(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update8537CField(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update8537CField(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update8537CField(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                case 0xC:
                    Update8537CField(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update8537CField(recordPlus1, unsigned char *, 0xA) + 8);
                    Update8537Cfunc_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update8537CField(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update8537CField(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update8537CField(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update8537CField(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update8537CField(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update8537CField(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update8537CField(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0xD:
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=28)goto removeRecord;
                    if(Update8537CField(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8537CField(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update8537CField(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update8537CField(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__ volatile("" ::: "$8","memory");
                    scratch3=Update8537CField(recordPlus1,unsigned short*,0x1D);
                    scratch2=1;
                    scratch2-=scratch3;
                    Update8537CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled58;
                    scratch3=Update8537CField(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(word9),"=r"(scratch3) : "0"(scratch2),"1"(word9),"2"(scratch3));
                    scratch2+=word9;
                    Update8537CField(recordPlus1,unsigned char*,9)=scratch2;
                    if((unsigned int)scratch3>=13){
                        scratch2=scratch3-12;
                        scratch2*=8;
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        scratch2=word9-scratch2;
                        if(scratch2<0)scratch2=0;
                        scratch3=Update8537CField(recordPlus1,unsigned char*,1);
                        Update8537CField(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=64;
                        scratch3-=12;
                        scratch3*=4;
                        scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update8537CField(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update8537CField(recordPlus1,unsigned char*,0xD)=0;
                    }
                    else{
                        predicate2=(unsigned int)scratch3<5;
                        __asm__("" : "=r"(predicate2) : "0"(predicate2));
                        if(!predicate2){
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9) : "memory");
                            scratch3=Update8537CField(recordPlus1,unsigned char*,1);
                            scratch2=-128;
                            Update8537CField(recordPlus1,unsigned char*,0xB)=word9;
                            Update8537CField(recordPlus1,unsigned char*,0xD)=0;
                            scratch3-=4;
                            scratch3*=8;
                            scratch2-=scratch3;
                            Update8537CField(recordPlus1,unsigned char*,0xC)=scratch2;
                        }
                        else{
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9) : "memory");
                            scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                            __asm__("" : "=r"(scratch2),"=r"(word9) : "0"(scratch2),"1"(word9));
                            Update8537CField(recordPlus1,unsigned char*,0xB)=word9;
                            Update8537CField(recordPlus1,unsigned char*,0xC)=word9;
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            scratch2*=32;
                            scratch2=word9-scratch2;
                            if(scratch2<0)scratch2=0;
                            Update8537CField(recordPlus1,unsigned char*,0xD)=scratch2;
                        }
                    }
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update8537CField(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                case 0x14:
                    Update8537Cfunc_8004F5A8((Vector3D16 *) recordPlus4, (Vector3D16 *) recordPlus4, recordPlus24);
                    scratch2 = Update8537CField(recordPlus1, unsigned char *, 1) + step;
                    Update8537CField(recordPlus1, unsigned char *, 1) = scratch2;
                    if ((unsigned int) (scratch2 & 0xFF) >= 0x11U) {
                        if ((Update8537Crand() & 0x3F) >= (Update8537CField(recordPlus1, unsigned char *, 1) - 0x10)) {
                            recordPlus1 += 0x20;
                        }
                        else {
                            goto removeRecord;
                        }
                    }
                    else {
                        scratch2 = Update8537CField(recordPlus1, unsigned char *, 9) + step;
                        Update8537CField(recordPlus1, unsigned char *, 9) = scratch2;
                        if ((unsigned int) (scratch2 & 0xFF) >= 0x81U) {
                            word9=128;
                            __asm__("":"=r"(word9):"0"(word9));
                            Update8537CField(recordPlus1, unsigned char *, 9) = word9;
                        }
                        goto nextRecord;
                    }
                    break;
                case 0x1E: {
                        register void *vector16 __asm__("$17");
                        register unsigned char *other6 __asm__("$6");
                        vector16=&frame.words[4];
                        scratch4=(int)vector16;
                        scratch5=1;
                        other6=Update8537CField(recordPlus1,unsigned char**,0x17);
                        scratch2=Update8537CField(recordPlus1,short*,3);
                        scratch3=Update8537CField(other6,int*,12);
                        scratch2*=4;
                        scratch3-=scratch2;
                        frame.words[4]=scratch3;
                        scratch2=Update8537CField(recordPlus1,short*,5);
                        scratch3=Update8537CField(other6,int*,16);
                        scratch2*=4;
                        scratch3-=scratch2;
                        frame.words[5]=scratch3;
                        scratch3=Update8537CField(recordPlus1,short*,7);
                        scratch2=Update8537CField(other6,int*,20);
                        scratch3*=4;
                        scratch3-=1024;
                        scratch2-=scratch3;
                        frame.words[6]=scratch2;
                        scratch5=Update8537Cfunc_8004EDE8(vector16,1);
                        if(scratch5<193)goto removeRecord;
                        Update8537Cfunc_8004F08C(vector16,scratch5,192);
                        scratch2=frame.words[4];
                        scratch3=Update8537CField(recordPlus1,unsigned short*,3);
                        scratch2>>=2;
                        scratch3+=scratch2;
                        Update8537CField(recordPlus1,unsigned short*,3)=scratch3;
                        scratch2=frame.words[5];
                        scratch3=Update8537CField(recordPlus1,unsigned short*,5);
                        scratch2>>=2;
                        scratch3+=scratch2;
                        Update8537CField(recordPlus1,unsigned short*,5)=scratch3;
                        scratch2=frame.words[6];
                        scratch3=Update8537CField(recordPlus1,unsigned short*,7);
                        scratch2>>=2;
                        scratch3+=scratch2;
                        Update8537CField(recordPlus1,unsigned short*,7)=scratch3;
                        goto nextRecord;
                    }
                case 0x21:
                    Update8537Cfunc_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update8537CField(recordPlus1, short *, 0x1D) != 0) {
                        Update8537CField(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    scratch2=Update8537CField(recordPlus1,unsigned char*,0xB);
                    word9=frame.saved.doubled58;
                    scratch4=Update8537CField(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update8537CField(recordPlus1,unsigned char*,9);
                    {
                        register int remaining5 __asm__("$5");
                        remaining5=scratch2-word9;
                        scratch2=1;
                        scratch2-=scratch4;
                        scratch3+=word9;
                        Update8537CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                        Update8537CField(recordPlus1,unsigned char*,9)=scratch3;
                        if(remaining5<0)remaining5=0;
                        scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                        Update8537CField(recordPlus1,unsigned char*,0xB)=remaining5;
                        Update8537CField(recordPlus1,unsigned char*,0xC)=remaining5;
                        Update8537CField(recordPlus1,unsigned char*,0xD)=remaining5;
                        scratch2+=step;
                        Update8537CField(recordPlus1,unsigned char*,1)=scratch2;
                        scratch2&=255;
                        if((unsigned int)scratch2>=32)goto removeRecord;
                        scratch2=Update8537CField(recordPlus1,unsigned char*,2);
                        if(scratch2==0)goto removeRecord;
                        if(remaining5==0)goto removeRecord;
                        recordPlus1+=32;
                        break;
                    }
                case 0x2C:
                    scratch2=Update8537CField(recordPlus1,unsigned short*,0x17);
                    scratch4=Update8537CField(recordPlus1,unsigned short*,0x11);
                    scratch3=Update8537CField(recordPlus1,unsigned short*,0x19);
                    scratch5=Update8537CField(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3),"=r"(scratch5) : "0"(scratch2),"1"(scratch4),"2"(scratch3),"3"(scratch5));
                    scratch2+=scratch4;
                    Update8537CField(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update8537CField(recordPlus1,unsigned short*,7);
                    scratch4=Update8537CField(recordPlus1,unsigned short*,0x15);
                    scratch3+=scratch5;
                    Update8537CField(recordPlus1,unsigned short*,0x19)=scratch3;
                    scratch3=Update8537CField(recordPlus1,unsigned char*,0x1B);
                    scratch2+=scratch4;
                    scratch3*=2;
                    Update8537CField(recordPlus1,unsigned short*,7)=scratch2;
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch3=Update8537CField(Update8537CSin,unsigned short*,scratch3);
                    scratch2=Update8537CField(recordPlus1,unsigned short*,0x17);
                    scratch4=Update8537CField(recordPlus1,unsigned char*,0x1B);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=24;
                    scratch2+=scratch3;
                    scratch4*=2;
                    Update8537CField(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,0x1B);
                    scratch3=Update8537CField(recordPlus1,unsigned char*,0x1C);
                    scratch4=Update8537CField(Update8537CCos,unsigned short*,scratch4);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2+=scratch3;
                    scratch4<<=16;
                    scratch4>>=24;
                    Update8537CField(recordPlus1,unsigned char*,0x1B)=scratch2;
                    scratch2=Update8537CField(recordPlus1,unsigned short*,0x19);
                    scratch3=Update8537CD_8006C640;
                    scratch2+=scratch4;
                    scratch3&=3;
                    Update8537CField(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch3==0){
                        scratch2=Update8537CField(recordPlus1,short*,0x15);
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        if(scratch2<9){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update8537CField(recordPlus1,unsigned short*,0x15)=scratch2;
                        }
                        scratch3=Update8537CField(recordPlus1,unsigned char*,9);
                        if((unsigned int)scratch3<20){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update8537CField(recordPlus1,unsigned char*,9)=scratch2;
                        }
                    }
                    scratch2=Update8537CField(recordPlus1,short*,7);
                    scratch3=Update8537CField(recordPlus1,short*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2>=scratch3){
                        scratch3=Update8537CField(recordPlus1,unsigned char*,0x10);
                        scratch2=3;
                        if(scratch3!=scratch2)goto removeRecord;
                    sharedSpawn43:
                        Update8537CSpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    if(scratch2==0)goto removeRecord;
                    __asm__ volatile("" ::: "memory");
                    goto checkByte2;
                case 0x37:
                    Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch3=Update8537CField(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3));
                    scratch2=scratch3+step;
                    Update8537CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch2=Update8537CField(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update8537CField(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129){
                        __asm__ volatile("" ::: "$8","memory");
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        Update8537CField(recordPlus1,unsigned char*,9)=word9;
                    }
                    scratch4=Update8537CField(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch4<17) {
                        scratch2=256;
                        goto addedEarlyAge;
                    }
                    predicate2=scratch3<17;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(predicate2)Update8537CSpawnParticle(1,56,record,0);
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    scratch2-=16;
                    scratch3=scratch2*8;
                    scratch2=256;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3<0)scratch3=0;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,0xC);
                    Update8537CField(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3>>=1;
                    if(scratch3>=scratch2)goto nextRecord;
                addedStoreByteC:
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    Update8537CField(recordPlus1,unsigned char*,0xC)=scratch3;
                    goto nextRecord;
                addedEarlyAge:
                    scratch3=scratch4*16;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3>=32)goto addedStoreByteC;
                    scratch3=32;
                    goto addedStoreByteC;
                case 0x38:
                    Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update8537CField(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update8537CField(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129){
                        __asm__ volatile("" ::: "$8","memory");
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        Update8537CField(recordPlus1,unsigned char*,9)=word9;
                    }
                    __asm__ volatile("" : : "r"(step) : "$4","memory");
                    scratch3=Update8537CField(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2");
                    if((unsigned int)scratch3<16)scratch2=scratch3*4;
                    else {
                        scratch2=48;
                        scratch2-=scratch3;
                        scratch2*=2;
                    }
                    if(scratch2<=0)goto removeRecord;
                    Update8537CField(recordPlus1,unsigned char*,0xB)=scratch2;
                    Update8537CField(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update8537CField(recordPlus1,unsigned char*,0xD)=scratch2;
                    goto nextRecord;
                case 0x3B:
                    Update8537CField(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update8537CField(recordPlus1, unsigned char *, 0xA) + 8);
                    Update8537Cfunc_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update8537CD_8006C640 & 1) {
                        Update8537CField(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update8537CField(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update8537CField(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update8537CField(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update8537CField(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update8537CField(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update8537CField(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update8537CField(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0x3E:
                    {
                        register unsigned char *state22 __asm__("$22");
                        register unsigned char *table18 __asm__("$18");
                        register int index21 __asm__("$21");
                        register int angle20 __asm__("$20");
                        register int raw17 __asm__("$17");
                        state22=recordPlus24;
                        table18=Update8537CField(recordPlus1,unsigned char**,0x17);
                        __asm__ volatile("":"=r"(state22),"=r"(table18):"0"(state22),"1"(table18):"memory");
                        index21=Update8537CField(recordPlus1,short*,0x1B);
                        angle20=Update8537CField(recordPlus1,short*,0x1D);
                        raw17=6;
                        if(index21==0){
                            __asm__ volatile("":"=r"(index21):"0"(index21));
                            scratch7=Update8537CField(recordPlus1,unsigned short*,3);
                            scratch7*=4;
                            frame.words[12]=scratch7;
                            scratch3=Update8537CField(recordPlus1,unsigned short*,5);
                            scratch3*=4;
                            frame.words[13]=scratch3;
                            scratch2=Update8537CField(recordPlus1,unsigned short*,7);
                            scratch2*=4;
                            frame.words[14]=scratch2;
                            scratch2=Update8537CField(table18,int*,0xC);
                            scratch6=0;
                            scratch4=Update8537CField((void*)scratch2,int*,0);
                            playerEnd=(unsigned char*)Update8537CField((void*)scratch2,int*,4);
                            scratch4-=scratch7;
                            scratch2=Update8537Cfunc_8004E880(scratch4,(int)playerEnd-scratch3,scratch6);
                            scratch2=Update8537Cfunc_8004F2EC(scratch2,angle20,1,1);
                            Update8537CField(recordPlus1,unsigned short*,0x1D)=scratch2;
                            scratch3=Update8537CField(table18,int*,0xC);
                            scratch2=frame.words[14];
                            scratch3=Update8537CField((void*)scratch3,int*,8);
                            scratch2-=2200;
                            scratch3=scratch2-scratch3;
                            predicate2=scratch3<1501;
                            if(!predicate2){
                                scratch2=Update8537CField(recordPlus1,unsigned short*,7);
                                scratch2-=75;
                                Update8537CField(recordPlus1,unsigned short*,7)=scratch2;
                                goto join3E;
                            }
                            predicate2=scratch3 < -1500;
                            if(predicate2){
                                scratch2=Update8537CField(recordPlus1,unsigned short*,7);
                                scratch2+=75;
                                Update8537CField(recordPlus1,unsigned short*,7)=scratch2;
                            }
                        }
                        else{
                            scratch3=Update8537CField(table18,short*,0);
                            var_a1=index21+1;
                            predicate2=var_a1<scratch3;
                            __asm__ volatile(".set	noreorder" : "=r"(predicate2) : "0"(predicate2));
                            if(!predicate2){
                                scratch4=(int)&frame.words[8];
                                __asm__ volatile(".set	reorder" : "=r"(scratch4) : "0"(scratch4));
                                var_a1=scratch3-1;
                                scratch2=Update8537CField(table18,int*,0xC);
                                scratch6=var_a1<<4;
                                var_a1=scratch2+scratch6;
                                scratch6-=16;
                                scratch6+=scratch2;
                            }
                            else{
                                scratch4=(int)&frame.words[8];
                                __asm__ volatile(".set	reorder" : "=r"(scratch4) : "0"(scratch4));
                                __asm__ volatile("":"=r"(var_a1):"0"(var_a1),"r"(scratch4),"i"(0x80085F70));
                                var_a1<<=4;
                                scratch6=Update8537CField(table18,int*,0xC);
                                __asm__("":"=r"(index21):"0"(index21));
                                scratch2=index21<<4;
                                var_a1=scratch6+var_a1;
                                scratch6+=scratch2;
                            }
                            Update8537Cfunc_8004F1C8((void*)scratch4,(void*)var_a1,(void*)scratch6);
                            scratch4=frame.words[8];
                            var_a1=frame.words[9];
                            scratch2=Update8537Cfunc_8004E880(scratch4,var_a1,0);
                            scratch4=scratch2;
                            var_a1=angle20;
                            __asm__("":"=r"(scratch4),"=r"(var_a1):"0"(scratch4),"1"(var_a1));
                            scratch6=raw17;
                            scratch7=(scratch6>>1)+1;
                            scratch2=Update8537Cfunc_8004F2EC(scratch4,var_a1,scratch6,scratch7);
                            Update8537CField(state22,unsigned short*,6)=scratch2;
                        }
                    join3E:
                        raw17=350;
                        if(index21==0)raw17=100;
                        scratch3=angle20<<1;
                        scratch2=Update8537CField(Update8537CSin,short*,scratch3);
                        word9=raw17*scratch2;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=word9>>12;
                        frame.halves[32]=scratch2;
                        scratch2=Update8537CField(Update8537CCos,short*,scratch3);
                        word9=raw17*scratch2;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=word9>>12;
                        frame.halves[34]=0;
                        frame.halves[33]=scratch2;
                        Update8537Cfunc_8004F5A8(recordPlus4,recordPlus4,&frame.halves[32]);
                        scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                        __asm__ volatile("":"=r"(scratch2):"0"(scratch2):"memory");
                        scratch4=Update8537CField(recordPlus1,unsigned char*,1);
                        __asm__("":"=r"(scratch2),"=r"(scratch4):"0"(scratch2),"1"(scratch4));
                        scratch2=(scratch2<<4)&0x1F0;
                        scratch4=(scratch4<<4)&0x1F0;
                        __asm__("":"=r"(scratch2),"=r"(scratch4):"0"(scratch2),"1"(scratch4));
                        scratch3=Update8537CField(Update8537CSin,unsigned short*,scratch2);
                        scratch2=Update8537CField(recordPlus1,unsigned short*,3);
                        scratch3=(scratch3<<16)>>25;
                        scratch2+=scratch3;
                        Update8537CField(recordPlus1,unsigned short*,3)=scratch2;
                        scratch3=Update8537CField(Update8537CCos,unsigned short*,scratch4);
                        scratch2=Update8537CField(recordPlus1,unsigned short*,5);
                        scratch8=Update8537CField(recordPlus1,unsigned short*,3);
                        __asm__("":"=r"(scratch3),"=r"(scratch2),"=r"(scratch8):"0"(scratch3),"1"(scratch2),"2"(scratch8));
                        scratch3=(scratch3<<16)>>25;
                        scratch2+=scratch3;
                        scratch8*=4;
                        Update8537CField(recordPlus1,unsigned short*,5)=scratch2;
                        frame.words[8]=scratch8;
                        scratch7=Update8537CField(recordPlus1,unsigned short*,5);
                        scratch7*=4;
                        frame.words[9]=scratch7;
                        scratch2=Update8537CField(recordPlus1,unsigned short*,7);
                        scratch6=0;
                        scratch2*=4;
                        frame.words[10]=scratch2;
                        scratch3=Update8537CField(table18,int*,0xC);
                        scratch2=index21<<4;
                        scratch2+=scratch3;
                        scratch4=Update8537CField((void*)scratch2,int*,0);
                        var_a1=Update8537CField((void*)scratch2,int*,4);
                        scratch4-=scratch8;
                        var_a1-=scratch7;
                        scratch2=Update8537Cfunc_8004E880(scratch4,var_a1,scratch6);
                        scratch2=Update8537Cfunc_8004F264(scratch2,Update8537CField(state22,short*,6));
                        if(scratch2>=65){
                            scratch2=Update8537CField(state22,unsigned short*,4);
                            scratch2+=1;
                            Update8537CField(state22,unsigned short*,4)=scratch2;
                            __asm__("":"=r"(scratch2):"0"(scratch2));
                            scratch2<<=16;
                            scratch3=Update8537CField(table18,short*,0);
                            scratch2>>=16;
                            predicate2=scratch2<scratch3;
                            scratch4=scratch3;
                            if(!predicate2){
                                __asm__ volatile("":"=r"(scratch4):"0"(scratch4),"i"(0x800860F4));
                                scratch2=scratch4-1;
                                Update8537CField(state22,unsigned short*,4)=scratch2;
                            }
                        }
                        scratch2=Update8537CField(recordPlus1,unsigned char*,0xA);
                        if(scratch2==0 || (Update8537CD_8006C640&1)!=0){
                            scratch2=Update8537CField(recordPlus1,unsigned char*,9);
                            scratch2+=1;
                            Update8537CField(recordPlus1,unsigned char*,9)=scratch2;
                        }
                        scratch2=Update8537CField(recordPlus1,unsigned char*,1);
                        scratch3=scratch2+1;
                        predicate2=(unsigned int)scratch2<101;
                        Update8537CField(recordPlus1,unsigned char*,1)=scratch3;
                        if(!predicate2)goto removeRecord;
                        if(index21==0)goto nextRecord;
                        scratch2=scratch3&255;
                        if((unsigned int)scratch2<11)goto nextRecord;
                        if(Update8537CField(recordPlus1,unsigned char*,0xA)==0)goto checkByte2;
                        goto nextRecord;
                    }
                case 0x42:
                    iteration = 0;
                    if (step > 0) {
                        do {
                            if (Update8537CField(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update8537CField(recordPlus1, unsigned short *, 3);
                                scratch4=Update8537CField(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update8537CField(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update8537CField(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update8537CField(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update8537CField(recordPlus1, unsigned short *, 7);
                                scratch4=Update8537CField(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update8537CField(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update8537CField(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update8537CField(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update8537Crand();
                                    halfword3=Update8537CField(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update8537CField(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update8537Crand();
                                    halfword3=Update8537CField(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update8537CField(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update8537Crand();
                                    halfword3=Update8537CField(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update8537CField(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            iteration += 1;
                            Update8537CField(recordPlus1, unsigned char *, 1) = (unsigned char) (Update8537CField(recordPlus1, unsigned char *, 1) + 1);
                        }
                        while (iteration < step);
                    }
                    predicate2 = (unsigned char) Update8537CField(recordPlus1, unsigned char *, 1) < 0x18U;
                    goto checkPredicate;
                checkPredicate:
                    if(predicate2==0)goto removeRecord;
                checkByte2:
                    if(Update8537CField(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    recordPlus1+=32;
                    break;
                case 0x46:
                    temp_v0_11 = Update8537CField(recordPlus1, unsigned char *, 1) + 1;
                    Update8537CField(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update8537CField(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update8537CField(recordPlus1, unsigned short *, 9) - (short) Update8537CField(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[24] = (unsigned short) temp_a0_3;
                        frame.halves[25] = (unsigned short) ((int) ((short) Update8537CField(recordPlus1, unsigned short *, 0xB) - (short) Update8537CField(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[26] = (unsigned short) ((int) ((short) Update8537CField(recordPlus1, unsigned short *, 0xD) - (short) Update8537CField(recordPlus1, unsigned short *, 7)) >> 1);
                        Update8537CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update8537CField(recordPlus1, unsigned short *, 5) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 5) + frame.halves[25]);
                        Update8537CField(recordPlus1, unsigned short *, 7) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 7) + frame.halves[26]);
                        random2=Update8537Crand();
                        halfword3=frame.halves[24];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[24]=halfword3;
                        random2=Update8537Crand();
                        halfword3=frame.halves[25];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[25]=halfword3;
                        if (Update8537CField(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[26] -= 1;
                        }
                        random2=Update8537CField(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[24];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update8537CField(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update8537CField(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[25];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update8537CField(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update8537CField(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[26];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update8537CField(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update8537CField(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128){
                            register int original1287 __asm__("$9")=128;
                            Update8537CField(recordPlus1, unsigned char *, 0xF)=original1287;
                        }
                        temp_v0_13 = Update8537CField(recordPlus1, unsigned char *, 0x10) - 4;
                        Update8537CField(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update8537CField(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update8537CField(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update8537CField(recordPlus1, unsigned char *, 0x13) - 3;
                        Update8537CField(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update8537CField(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        scratch2 = Update8537CField(recordPlus1, unsigned char *, 0x14);
                        scratch2 -= 4;
                        Update8537CField(recordPlus1, unsigned char *, 0x14) = scratch2;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2 &= 255;
                        predicate2=(unsigned int)scratch2<0x80U;
                        if (predicate2) {
                            {
                                register int original1287 __asm__("$9");
                                __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$9","memory");
                                original1287=128;
                                __asm__("" : "=r"(scratch2),"=r"(original1287) : "0"(scratch2),"1"(original1287));
                                Update8537CField(recordPlus1, unsigned char *, 0x14) = original1287;
                            }
                        }
                        temp_v0_16 = (unsigned char) Update8537CField(recordPlus1, unsigned char *, 0x15) - 6;
                        Update8537CField(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update8537CField(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x47:
                    temp_v0_17 = Update8537CField(recordPlus1, unsigned char *, 1) + 1;
                    Update8537CField(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update8537CField(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[12] = (short) Update8537CField(recordPlus1, unsigned short *, 9) - (short) Update8537CField(recordPlus1, unsigned short *, 3);
                        frame.words[13] = (short) Update8537CField(recordPlus1, unsigned short *, 0xB) - (short) Update8537CField(recordPlus1, unsigned short *, 5);
                        frame.words[14] = (short) Update8537CField(recordPlus1, unsigned short *, 0xD) - (short) Update8537CField(recordPlus1, unsigned short *, 7);
                        random2=Update8537Crand();
                        halfword3=frame.words[12];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[12]=halfword3;
                        random2=Update8537Crand();
                        halfword3=frame.words[13];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[13]=halfword3;
                        random2=Update8537Crand();
                        halfword3=frame.words[14];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[14]=halfword3;
                        Update8537CField(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update8537CField(recordPlus1, unsigned short *, 9) + frame.words[12]);
                        Update8537CField(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update8537CField(recordPlus1, unsigned short *, 0xB) + frame.words[13]);
                        Update8537CField(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update8537CField(recordPlus1, unsigned short *, 0xD) + frame.words[14]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[12];
                        scratch2=Update8537CField(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update8537CField(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[13];
                        scratch2=Update8537CField(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update8537CField(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[14];
                        scratch3=Update8537CField(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update8537CField(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update8537CField(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update8537CField(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update8537CField(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update8537CField(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update8537CField(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update8537CField(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update8537CField(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update8537CField(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x48:
                    temp_v0_18 = Update8537CField(recordPlus1, unsigned char *, 1) + 1;
                    Update8537CField(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update8537CField(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[12] = (int) ((short) Update8537CField(recordPlus1, unsigned short *, 3) - (short) Update8537CField(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[13] = (int) ((short) Update8537CField(recordPlus1, unsigned short *, 5) - (short) Update8537CField(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[14] = (int) ((short) Update8537CField(recordPlus1, unsigned short *, 7) - (short) Update8537CField(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update8537Crand();
                        halfword3=frame.words[12];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[12]=halfword3;
                        random2=Update8537Crand();
                        halfword3=frame.words[13];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[13]=halfword3;
                        random2=Update8537Crand();
                        halfword3=frame.words[14];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[14]=halfword3;
                        Update8537CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 3) + frame.words[12]);
                        Update8537CField(recordPlus1, unsigned short *, 5) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 5) + frame.words[13]);
                        Update8537CField(recordPlus1, unsigned short *, 7) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 7) + frame.words[14]);
                        __asm__ __volatile__("" ::: "memory");
                        Update8537CField(recordPlus1, unsigned short *, 9) = (short) (Update8537CField(recordPlus1, unsigned short *, 3) - (frame.words[12] * 2));
                        Update8537CField(recordPlus1, unsigned short *, 0xB) = (short) (Update8537CField(recordPlus1, unsigned short *, 5) - (frame.words[13] * 2));
                        Update8537CField(recordPlus1, unsigned short *, 0xD) = (short) (Update8537CField(recordPlus1, unsigned short *, 7) - (frame.words[14] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4E:
                    temp_v0_19 = Update8537CField(recordPlus1, unsigned char *, 1) + 1;
                    Update8537CField(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update8537CField(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update8537CField(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update8537CField(recordPlus1, unsigned short *, 0x13);
                        Update8537CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 3) + Update8537CField(recordPlus1, unsigned short *, 0xF));
                        Update8537CField(recordPlus1, unsigned short *, 5) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update8537CField(recordPlus1, unsigned short *, 7) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update8537Crand();
                        halfword3=Update8537CField(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update8537CField(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update8537Crand();
                        halfword3=Update8537CField(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update8537CField(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update8537Crand();
                        halfword3=Update8537CField(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update8537CField(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update8537CField(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update8537CField(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update8537CField(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update8537CField(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update8537CField(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update8537CField(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update8537CField(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update8537CField(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4F:
                    temp_a0_5 = (int) ((short) Update8537CField(recordPlus1, unsigned short *, 9) - (short) Update8537CField(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[24] = (unsigned short) temp_a0_5;
                    frame.halves[25] = (unsigned short) ((int) ((short) Update8537CField(recordPlus1, unsigned short *, 0xB) - (short) Update8537CField(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[26] = (unsigned short) ((int) ((short) Update8537CField(recordPlus1, unsigned short *, 0xD) - (short) Update8537CField(recordPlus1, unsigned short *, 7)) >> 1);
                    Update8537CField(recordPlus1, unsigned short *, 3) = (unsigned short) (Update8537CField(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update8537CField(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[25];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update8537CField(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update8537CField(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[26];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update8537CField(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update8537CField(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[24];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update8537CField(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update8537CField(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[25];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update8537CField(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update8537CField(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[26];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update8537CField(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update8537CField(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update8537CField(recordPlus1,unsigned char*,2);
                    if(scratch2!=0)goto surviving4F;
                removeRecord:
                    Update8537Cfunc_80056504(record);
                    recordPlus1+=32;
                    break;
                    surviving4F:;
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update8537CField(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update8537CField(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update8537CField(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update8537CField(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update8537CField(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update8537CField(recordPlus1, unsigned char *, 0x13);
                    Update8537CField(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update8537CField(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update8537CField(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                    default:goto nextRecord;
                }
            }
            else {
            nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus4 += 0x20;
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
#undef Update8537CHigh
#undef Update8537CField
