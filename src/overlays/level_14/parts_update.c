#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80090754.
 * Assembly SHA256 b6001770b9e9e2a045cd488517208837961a61d7cba98c94335da8debbcb7674.
 * AI-generated; not human reviewed. Verified case C, including level38's
 * complete selector3E chain, is adapted to every original target instruction.
 * All raw field widths, constants, helper arguments, stack slots and shared
 * branch entries are retained. Units/fixed point, full helper semantics and
 * caller cadence remain unresolved; step is the argument, not a time unit.
 * Original1991 instructions and86 owned selectors/targets are mandatory.
 * Original frame0xC8, double48/quad50/pointer98 and repeated quad loads are
 * retained. Step uses ordinary C allocation to FP, with no fixed FP binding.
 * The byte-mode saved low bits occupy S5; selector3E's saved halfword is S3.
 * Original T1 sine-table base producers remain explicit in27/29/2C/3E.
 * Selector2C keeps exact original ordered field loads/stores and address phases;
 * selector27 keeps its distinct post-helper byte check. Every empty-constraint
 * operand is initialized. Original MULT producers precede HI/LO captures.
 * Empty identities and paired .set scheduling metadata emit zero CPU words;
 * C generates every CPU instruction. Compiler/assembler/pipeline/flags,
 * original padding and all acceptance gates remain unchanged.
 * Falsification: all native/linked words, conditional/internal targets, every
 * selector, preserved data and full EXE/every-overlay original retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
int Update90754func_800359A4(void*,int) __asm__("func_800359A4");
int Update90754func_8004E880(int,int,int) __asm__("func_8004E880");
int Update90754func_8004F2EC(int,int,int,int) __asm__("func_8004F2EC");
int Update90754func_8004F264(int,int) __asm__("func_8004F264");
int Update90754func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
#define Update90754Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Update90754func_8004E9E4(short) __asm__("func_8004E9E4");
int Update90754func_8004EA2C(short) __asm__("func_8004EA2C");
int Update90754func_8004F178(void*,void*) __asm__("func_8004F178");
int Update90754func_8004F504(void*,void*) __asm__("func_8004F504");
int Update90754func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
int Update90754func_80056504(void*) __asm__("func_80056504");
extern int Update90754D_8006C644 __asm__("D_8006C644");
extern unsigned short Update90754Sin[] __asm__("D_80065920");
extern unsigned short Update90754Cos[] __asm__("D_800658A0");
extern int (*Update90754SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
int Update90754rand(void) __asm__("rand");
extern unsigned char *Update90754D_8006C554 __asm__("D_8006C554");
extern int Update90754D_8006C598 __asm__("D_8006C598");
extern int Update90754D_8006C640 __asm__("D_8006C640");
extern short Update90754D_8006E040 __asm__("D_8006E040");
extern int Update90754D_8006E344 __asm__("D_8006E344");
extern unsigned char Update90754D_80070328[] __asm__("D_80070328");
extern int Update90754Player48 __asm__("D_80070328 + 0x48");
extern int Update90754Player284 __asm__("D_80070328 + 0x284");
extern int Update90754Player280 __asm__("D_80070328 + 0x280");
#define Update90754High(a,b) ({int high;__asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory");high;})
unsigned char *func_level_14_80090754(int initialStep) {
    register unsigned char *playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    int step;
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[34];
        unsigned short halves[68];
        struct {
            int pad[14];
            volatile int doubled48;
            int pad4C;
            volatile int quadrupled50;
            int rest[17];
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
    register unsigned char *record __asm__("$20");
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
    register int savedLow21 __asm__("$21");
    int mode18;
    int maskedLow0;
    record = Update90754D_8006C554;
    incomingStep=initialStep;
    __asm__("" : "=r"(record),"=r"(incomingStep) : "0"(record),"1"(incomingStep));
    step=incomingStep;
    __asm__("" : "=r"(record),"=r"(step) : "0"(record),"1"(step) : "$4");
    scratch4 = Update90754Field(record, unsigned char *, 1);
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
        frame.saved.doubled48=word9;
        word9=step*4;
        recordPlus1=record+1;
        recordPlus4=record+4;
        __asm__ volatile("":"=r"(recordPlus1),"=r"(recordPlus4),"=r"(word9):"0"(recordPlus1),"1"(recordPlus4),"2"(word9):"memory");
        frame.saved.quadrupled50=word9;
        word9=(int)(record+0x18);
        __asm__("":"=r"(word9):"0"(word9));
        recordPlus24=(unsigned char*)word9;
        __asm__ volatile("":"=r"(scratch4):"0"(scratch4):"memory");
        scratch3=scratch4&255;
        __asm__("":"=r"(scratch3),"=r"(scratch4):"0"(scratch3),"1"(scratch4));
        do {
            __asm__ __volatile__("" ::: "$2");
            if (scratch3 != 0xFE) {
                if (Update90754D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update90754D_8006C598 == 0) {
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
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update90754Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update90754Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update90754Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled48;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch3+=word9;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xC);
                    word9=frame.saved.quadrupled50;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=word9;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=word9;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch3-=word9;
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    predicate2=(unsigned int)scratch2<32;
                    __asm__ volatile("" : : "i"(0x800908B8));
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                case 0x1:
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update90754Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update90754Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update90754Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.quadrupled50;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xB);
                    scratch3+=word9;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xC);
                    scratch2-=word9;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch3-=word9;
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    predicate2=(unsigned int)scratch2<24;
                    scratch3-=word9;
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto checkPredicate;
                case 0x2:
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    if(Update90754Field(recordPlus1,short*,0x1D)!=0)
                    Update90754Field(recordPlus1,unsigned short*,0x1B)=Update90754Field(recordPlus1,unsigned short*,0x1B)+1;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=1;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled48;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    word9=frame.saved.quadrupled50;
                    predicate2=scratch3<word9;
                    if(!predicate2){
                        scratch2=scratch3-word9;
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    }
                    else Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xC);
                    word9=frame.saved.quadrupled50;
                    predicate2=scratch3<word9;
                    if(!predicate2){
                        scratch2=scratch3-word9;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    }
                    else Update90754Field(recordPlus1,unsigned char*,0xC)=0;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    word9=frame.saved.quadrupled50;
                    predicate2=scratch3<word9;
                    if(!predicate2){
                        __asm__ volatile("" : : "r"(step) : "memory");
                        scratch2=scratch3-word9;
                        Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    }
                    else Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<32;
                    goto checkPredicate;
                case 0x9:
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update90754Field(recordPlus1, short *, 0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update90754Field(recordPlus1, unsigned short *, 0x1B);
                        scratch2++;
                        Update90754Field(recordPlus1, unsigned short *, 0x1B)=scratch2;
                    }
                    __asm__("" : "=r"(word9) : "0"(word9));
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    word9=frame.saved.doubled48;
                    scratch3+=word9;
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=step;
                    Update90754Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    predicate2=(unsigned int)scratch2<32;
                    Update90754Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto checkPredicate;
                case 0xA:
                    scratch3=Update90754Player48;
                    if(scratch3==30 && Update90754Player280<0)goto removeRecord;
                    playerEnd=Update90754D_80070328+0x288;
                    __asm__("" : "=r"(playerEnd) : "0"(playerEnd));
                    if(Update90754Field(playerEnd,int*,0)!=0)goto removeRecord;
                    if(Update90754Player284==0)goto removeRecord;
                    Update90754func_8004F178(&frame.words[0],playerEnd-0x288);
                    scratch2=Update90754func_8004EA2C(Update90754Field(recordPlus1, short *, 0x17));
                    scratch3=frame.words[0];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2>>=4;
                    scratch3+=scratch2;
                    frame.words[0]=scratch3;
                    scratch2=Update90754func_8004E9E4(Update90754Field(recordPlus1, short *, 0x17));
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
                    Update90754func_8004F504((void*)scratch4,playerEnd);
                    scratch4=Update90754Field(recordPlus1, unsigned short *, 0x17);
                    scratch4+=64;
                    Update90754Field(recordPlus1, unsigned short *, 0x17)=scratch4;
                    __asm__("" : "=r"(scratch4) : "0"(scratch4));
                    scratch4<<=16;
                    scratch2=Update90754D_8006E040;
                    __asm__("" : "=r"(scratch4),"=r"(scratch2) : "0"(scratch4),"1"(scratch2));
                    scratch4>>=16;
                    scratch4-=scratch2;
                    scratch2=Update90754func_8004EA2C(scratch4&4095);
                    scratch3=0x60606061;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2<0)scratch2=-scratch2;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    high7=Update90754High(scratch2,scratch3);
                    scratch2>>=31;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch3=high7>>6;
                    scratch3-=scratch2;
                    Update90754Field(recordPlus1, unsigned char *, 9)=scratch3;
                    goto nextRecord;
                case 0xB:
                    scratch2=Update90754Field(recordPlus1, short *, 0x1D);
                    scratch4=(int)recordPlus4;
                    if(scratch2!=0){
                        scratch2=Update90754Field(recordPlus1, unsigned short *, 0x15);
                        scratch2++;
                        Update90754Field(recordPlus1, unsigned short *, 0x15)=scratch2;
                    }
                    playerEnd=recordPlus4;
                    __asm__("" : "=r"(scratch4),"=r"(playerEnd) : "0"(scratch4),"1"(playerEnd));
                    scratch6=(int)record+18;
                    __asm__("" : "=r"(scratch6) : "0"(scratch6) : "$3","memory");
                    scratch2=Update90754Field(recordPlus1, unsigned short *, 0x1D);
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=1;
                    __asm__("":"=r"(word9),"=r"(scratch2):"0"(word9),"1"(scratch2));
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1, unsigned short *, 0x1D)=scratch2;
                    Update90754func_8004F5A8((void*)scratch4,playerEnd,(void*)scratch6);
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 9);
                    word9=frame.saved.doubled48;
                    __asm__("" : "=r"(scratch2),"=r"(word9) : "0"(scratch2),"1"(word9));
                    scratch3=Update90754Field(recordPlus1, unsigned char *, 0xB);
                    scratch2+=word9;
                    Update90754Field(recordPlus1, unsigned char *, 9)=scratch2;
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 0xA);
                    word9=frame.saved.quadrupled50;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update90754Field(recordPlus1, unsigned char *, 0xB)=scratch3;
                    scratch3=Update90754Field(recordPlus1, unsigned char *, 0xD);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=word9;
                    Update90754Field(recordPlus1, unsigned char *, 0xA)=scratch2;
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=4;
                    Update90754Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    scratch2-=4;
                    Update90754Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                    if(scratch3==0)goto removeRecord;
                    goto checkByte2;
                case 0xC:
                    Update90754Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update90754Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update90754func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    temp_v0_4 = Update90754Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_4 != 0) {
                        Update90754Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_4 - 8);
                    }
                    temp_v0_5 = Update90754Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_5 != 0) {
                        Update90754Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_5 - 8);
                    }
                    temp_v0_6 = Update90754Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_6 != 0) {
                        Update90754Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_6 - 8);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update90754Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0xD:
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch2>=28)goto removeRecord;
                    if(Update90754Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update90754Field(recordPlus1,short*,0x1D);
                    if(scratch2!=0){
                        scratch2=Update90754Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update90754Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    __asm__ volatile("" ::: "$8","memory");
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    __asm__("":"=r"(scratch2):"0"(scratch2));
                    word9=1;
                    __asm__("":"=r"(word9):"0"(word9),"r"(scratch2));
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    word9=frame.saved.doubled48;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(word9),"=r"(scratch3) : "0"(scratch2),"1"(word9),"2"(scratch3));
                    scratch2+=word9;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    if((unsigned int)scratch3>=13){
                        scratch2=scratch3-12;
                        scratch2*=8;
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        scratch2=word9-scratch2;
                        if(scratch2<0)scratch2=0;
                        scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=64;
                        scratch3-=12;
                        scratch3*=4;
                        scratch2-=scratch3;
                        if(scratch2<0)scratch2=0;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                    }
                    else{
                        predicate2=(unsigned int)scratch3<5;
                        __asm__("" : "=r"(predicate2) : "0"(predicate2));
                        if(!predicate2){
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9) : "memory");
                            scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                            scratch2=-128;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=word9;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                            scratch3-=4;
                            scratch3*=8;
                            scratch2-=scratch3;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        }
                        else{
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9) : "memory");
                            scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                            __asm__("" : "=r"(scratch2),"=r"(word9) : "0"(scratch2),"1"(word9));
                            Update90754Field(recordPlus1,unsigned char*,0xB)=word9;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=word9;
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            scratch2*=32;
                            scratch2=word9-scratch2;
                            if(scratch2<0)scratch2=0;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        }
                    }
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    goto nextRecord;
                case 0x21:
                    Update90754func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update90754Field(recordPlus1, short *, 0x1D) != 0) {
                        Update90754Field(recordPlus1, unsigned short *, 0x1B) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 0x1B) + 1);
                    }
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xB);
                    word9=frame.saved.doubled48;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch2),"=r"(word9),"=r"(scratch3) : "0"(scratch2),"1"(word9),"2"(scratch3));
                    scratch4=scratch2-word9;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    word9=1;
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled48;
                    scratch3+=word9;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch3;
                    if (scratch4 < 0) {
                        scratch4 = 0;
                    }
                    Update90754Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) scratch4;
                    Update90754Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) scratch4;
                    Update90754Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) scratch4;
                    temp_v0_7 = Update90754Field(recordPlus1, unsigned char *, 1) + step;
                    Update90754Field(recordPlus1, unsigned char *, 1) = temp_v0_7;
                    if (((unsigned int) (temp_v0_7 & 0xFF) < 0x20U) && (Update90754Field(recordPlus1, unsigned char *, 2) != 0) && (scratch4 != 0)) {
                        recordPlus1 += 0x20;
                    }
                    else {
                        goto removeRecord;
                    }
                    break;
                case 0x27:
                    scratch2=Update90754Field(recordPlus1,short*,0x17);
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
                    Update90754Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    scratch2=Update90754Field(recordPlus1,short*,0x19);
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
                    Update90754Field(recordPlus1,unsigned short*,0x19)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1B);
                    scratch2+=1;
                    Update90754Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    scratch2<<=16;
                    scratch2>>=16;
                    if(scratch2>=25)Update90754Field(recordPlus1,unsigned short*,0x1B)=24;
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    word9=(int)Update90754Sin;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : : : "memory");
                    scratch4=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4) : "0"(scratch2),"1"(scratch4));
                    scratch2<<=4;
                    scratch2&=0x1F0;
                    scratch2+=word9;
                    scratch4<<=4;
                    scratch4&=0x1F0;
                    __asm__("" : "=r"(scratch2),"=r"(scratch4) : "0"(scratch2),"1"(scratch4));
                    scratch3=Update90754Field((void*)scratch2,unsigned short*,0);
                    scratch2=Update90754Field(recordPlus1,unsigned short*,3);
                    scratch3<<=16;
                    scratch3>>=25;
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1,unsigned short*,3)=scratch2;
                    __asm__ volatile("" : "=r"(scratch4) : "0"(scratch4) : "memory");
                    scratch3=Update90754Field(Update90754Cos,unsigned short*,scratch4);
                    scratch2=Update90754Field(recordPlus1,unsigned short*,5);
                    scratch4=Update90754Field(recordPlus1,unsigned char*,0xA);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=25;
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch4==0 || (Update90754D_8006C640&1)!=0){
                        scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                        scratch2+=1;
                        Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch2=Update90754func_800359A4(record+2,1);
                    if(scratch2!=0)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xA);
                    __asm__ volatile("":"=r"(scratch2):"0"(scratch2),"i"(0x80090F98));
                    if(scratch2==0)goto checkByte2;
                    recordPlus1+=32;
                    break;
                case 0x29:
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=1;
                    scratch8=scratch2&255;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    if((unsigned int)scratch3<(unsigned int)scratch8){
                        if(Update90754Field(recordPlus1,unsigned char*,0x1E)==0)goto removeRecord;
                        Update90754SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update90754Field(recordPlus1,short*,0x17);
                    scratch7=Update90754Field(recordPlus1,short*,0x11);
                    __asm__("" : "=r"(scratch2),"=r"(scratch7) : "0"(scratch2),"1"(scratch7));
                    scratch2-=scratch7;
                    scratch2*=scratch8;
                    scratch8=scratch2/scratch3;
                    scratch6=Update90754Field(recordPlus1,short*,0x13);
                    scratch2=Update90754Field(recordPlus1,short*,0x19);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch6) : "0"(scratch2),"1"(scratch3),"2"(scratch6));
                    scratch2-=scratch6;
                    scratch2*=scratch3;
                    scratch5=Update90754Field(recordPlus1,unsigned char*,0x1D);
                    scratch5=scratch2/scratch5;
                    word9=(int)Update90754Sin;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch4=Update90754Field(recordPlus1,unsigned short*,0x15);
                    __asm__ volatile("" : "=r"(scratch4) : "0"(scratch4) : "memory");
                    scratch3=Update90754Field(recordPlus1,unsigned short*,0x15);
                    scratch2=Update90754Field(recordPlus1,unsigned short*,7);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=2;
                    Update90754Field(recordPlus1,unsigned short*,0x15)=scratch3;
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2+=scratch4;
                    Update90754Field(recordPlus1,unsigned short*,7)=scratch2;
                    scratch2=Update90754D_8006C644;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch7+=scratch8;
                    Update90754Field(recordPlus1,unsigned short*,3)=scratch7;
                    scratch6+=scratch5;
                    Update90754Field(recordPlus1,unsigned short*,5)=scratch6;
                    scratch2*=2;
                    scratch2+=word9;
                    scratch2=Update90754Field((void*)scratch2,unsigned short*,0);
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=26;
                    scratch2+=10;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update90754D_8006C644;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0x1C);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2*=8;
                    scratch2+=scratch3;
                    scratch2&=255;
                    scratch2=Update90754Cos[scratch2];
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    scratch2<<=16;
                    scratch2>>=27;
                    scratch2+=6;
                    Update90754Field(recordPlus1,unsigned char*,0xA)=scratch2;
                    goto nextRecord;
                case 0x2A:
                    scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update90754Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xB);
                    scratch4=Update90754Field(recordPlus1,short*,0x11);
                    scratch5=Update90754Field(recordPlus1,short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4),"=r"(scratch5) : "0"(scratch2),"1"(scratch3),"2"(scratch4),"3"(scratch5));
                    scratch2+=2;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=6;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=6;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    scratch2=Update90754Field(recordPlus1,int*,0x17);
                    scratch3-=6;
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch3=Update90754Field(recordPlus1,int*,0x1B);
                    scratch2+=scratch4;
                    Update90754Field(recordPlus1,int*,0x17)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update90754Field(recordPlus1,int*,0x17);
                    scratch3+=scratch5;
                    Update90754Field(recordPlus1,int*,0x1B)=scratch3;
                    __asm__ volatile("" ::: "memory");
                    scratch3=Update90754Field(recordPlus1,int*,0x1B);
                    scratch2>>=2;
                    scratch3>>=2;
                    Update90754Field(recordPlus1,unsigned short*,3)=scratch2;
                    Update90754Field(recordPlus1,unsigned short*,5)=scratch3;
                    goto nextRecord;
                case 0x2B:
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xB);
                    if((unsigned int)scratch2<4)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1,short*,0x17);
                    temp_a1=3;
                    if(scratch2!=0)temp_a1=2;
                    scratch4=Update90754Field(recordPlus1,unsigned char*,9);
                    __asm__("" : "=r"(scratch4),"=r"(temp_a1) : "0"(scratch4),"1"(temp_a1) : "memory");
                    scratch3=Update90754Field(recordPlus1,short*,0x17);
                    scratch2=scratch4+1;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    if(scratch3!=0){
                        scratch2=scratch4+2;
                        Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    }
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xB);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=temp_a1;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=temp_a1;
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2-=temp_a1;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    goto nextRecord;
                case 0x2C:
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x17);
                    scratch4=Update90754Field(recordPlus1,unsigned short*,0x11);
                    scratch3=Update90754Field(recordPlus1,unsigned short*,0x19);
                    scratch5=Update90754Field(recordPlus1,unsigned short*,0x13);
                    __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3),"=r"(scratch5) : "0"(scratch2),"1"(scratch4),"2"(scratch3),"3"(scratch5));
                    scratch2+=scratch4;
                    scratch3+=scratch5;
                    Update90754Field(recordPlus1,unsigned short*,0x19)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned short*,7);
                    scratch4=Update90754Field(recordPlus1,unsigned short*,0x15);
                    __asm__ volatile("":"=r"(scratch3),"=r"(scratch4):"0"(scratch3),"1"(scratch4):"$9","memory");
                    word9=(int)Update90754Sin;
                    __asm__("":"=r"(word9):"0"(word9));
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4):"memory");
                    Update90754Field(recordPlus1,unsigned short*,0x17)=scratch2;
                    __asm__ volatile("" ::: "memory");
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0x1B);
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3),"=r"(scratch4):"0"(scratch2),"1"(scratch3),"2"(scratch4):"memory");
                    scratch3+=scratch4;
                    scratch2*=2;
                    scratch2+=word9;
                    __asm__("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    Update90754Field(recordPlus1,unsigned short*,7)=scratch3;
                    scratch3=Update90754Field((void*)scratch2,unsigned short*,0);
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x17);
                    __asm__ volatile("":"=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3):"memory");
                    scratch4=Update90754Field(recordPlus1,unsigned char*,0x1B);
                    __asm__("" : "=r"(scratch3),"=r"(scratch2),"=r"(scratch4) : "0"(scratch3),"1"(scratch2),"2"(scratch4));
                    scratch3<<=16;
                    scratch3>>=24;
                    scratch2+=scratch3;
                    scratch4*=2;
                    Update90754Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0x1B);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0x1C);
                    scratch4=Update90754Field(Update90754Cos,unsigned short*,scratch4);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                    scratch2+=scratch3;
                    scratch4<<=16;
                    scratch4>>=24;
                    Update90754Field(recordPlus1,unsigned char*,0x1B)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x19);
                    scratch3=Update90754D_8006C640;
                    scratch2+=scratch4;
                    scratch3&=3;
                    Update90754Field(recordPlus1,unsigned short*,5)=scratch2;
                    if(scratch3==0){
                        scratch2=Update90754Field(recordPlus1,short*,0x15);
                        scratch3=scratch2;
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        if(scratch2<9){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update90754Field(recordPlus1,unsigned short*,0x15)=scratch2;
                        }
                        scratch3=Update90754Field(recordPlus1,unsigned char*,9);
                        if((unsigned int)scratch3<20){
                            scratch2=scratch3+1;
                            __asm__("" : "=r"(scratch2) : "0"(scratch2));
                            Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                    }
                    scratch2=Update90754Field(recordPlus1,short*,7);
                    scratch3=Update90754Field(recordPlus1,short*,0x1D);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    if(scratch2>=scratch3){
                        scratch3=Update90754Field(recordPlus1,unsigned char*,0x10);
                        scratch2=3;
                        if(scratch3!=scratch2)goto removeRecord;
                    sharedSpawn43:
                        Update90754SpawnParticle(1,43,recordPlus4,0);
                        goto removeRecord;
                    }
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    if(scratch2==0)goto removeRecord;
                    __asm__ volatile("" ::: "memory");
                    goto checkByte2;
                case 0x2E:
                    scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch2=scratch3+1;
                    predicate3=(unsigned int)scratch3<16;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    if(!predicate3)goto removeRecord;
                    if(Update90754Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xB);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=3;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xC);
                    scratch3-=8;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=8;
                    scratch3-=8;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    goto nextRecord;
                case 0x31:
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xC);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3):"0"(scratch2),"1"(scratch3));
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xB);
                    scratch3-=step;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned char*,0xD);
                    scratch2-=step;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch3-=step;
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<48;
                    goto checkPredicate;
                case 0x37:
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3));
                    scratch2=scratch3+step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch3&=255;
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129){
                        __asm__ volatile("" ::: "$8","memory");
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        Update90754Field(recordPlus1,unsigned char*,9)=word9;
                    }
                    scratch4=Update90754Field(recordPlus1,unsigned char*,1);
                    if((unsigned int)scratch4<17) {
                        scratch2=256;
                        goto addedEarlyAge;
                    }
                    predicate2=scratch3<17;
                    __asm__("" : "=r"(predicate2) : "0"(predicate2));
                    if(predicate2)Update90754SpawnParticle(1,56,record,0);
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch2-=16;
                    scratch3=scratch2*8;
                    scratch2=256;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3<0)scratch3=0;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,0xC);
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                    scratch3>>=1;
                    if(scratch3>=scratch2)goto nextRecord;
                addedStoreByteC:
                    __asm__ volatile("" : "=r"(scratch3) : "0"(scratch3) : "memory");
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                    goto nextRecord;
                addedEarlyAge:
                    scratch3=scratch4*16;
                    scratch3=scratch2-scratch3;
                    if(scratch3>=256)scratch3=255;
                    if(scratch3>=32)goto addedStoreByteC;
                    scratch3=32;
                    goto addedStoreByteC;
                case 0x38:
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=49)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch2+=step;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                    scratch2&=255;
                    if((unsigned int)scratch2>=129){
                        __asm__ volatile("" ::: "$8","memory");
                        word9=128;
                        __asm__("" : "=r"(word9) : "0"(word9));
                        Update90754Field(recordPlus1,unsigned char*,9)=word9;
                    }
                    __asm__ volatile("" : : "r"(step) : "$4","memory");
                    scratch3=Update90754Field(recordPlus1,unsigned char*,1);
                    __asm__("" : "=r"(scratch3) : "0"(scratch3) : "$2");
                    if((unsigned int)scratch3<16)scratch2=scratch3*4;
                    else {
                        scratch2=48;
                        scratch2-=scratch3;
                        scratch2*=2;
                    }
                    if(scratch2<=0)goto removeRecord;
                    Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                    Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                    goto nextRecord;
                case 0x3B:
                    Update90754Field(recordPlus1, unsigned char *, 0xA) = (unsigned char) (Update90754Field(recordPlus1, unsigned char *, 0xA) + 8);
                    Update90754func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                    if (Update90754D_8006C640 & 1) {
                        Update90754Field(recordPlus1, unsigned short *, 0x19) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 0x19) + 1);
                    }
                    temp_v0_8 = Update90754Field(recordPlus1, unsigned char *, 0xB);
                    if (temp_v0_8 != 0) {
                        Update90754Field(recordPlus1, unsigned char *, 0xB) = (unsigned char) (temp_v0_8 - 4);
                    }
                    temp_v0_9 = Update90754Field(recordPlus1, unsigned char *, 0xC);
                    if (temp_v0_9 != 0) {
                        Update90754Field(recordPlus1, unsigned char *, 0xC) = (unsigned char) (temp_v0_9 - 4);
                    }
                    temp_v0_10 = Update90754Field(recordPlus1, unsigned char *, 0xD);
                    if (temp_v0_10 != 0) {
                        Update90754Field(recordPlus1, unsigned char *, 0xD) = (unsigned char) (temp_v0_10 - 4);
                    }
                    scratch3=0xFF0000;
                    __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                    scratch2=Update90754Field(recordPlus1,unsigned int*,0xB);
                    scratch3|=0xFFFF;
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2&=scratch3;
                    __asm__("" : "=r"(scratch2) : "0"(scratch2));
                    if(scratch2==0)goto removeRecord;
                    __asm__ __volatile__("" ::: "$2");
                    goto checkByte2;
                case 0x3C:
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    low19=scratch2&31;
                    savedLow21=low19;
                    __asm__("":"=r"(savedLow21):"0"(savedLow21),"r"(low19));
                    mode18=(unsigned int)scratch2>>5;
                    maskedLow0=(unsigned char)savedLow21;
                    if((unsigned int)maskedLow0>=28)goto removeRecord;
                    if(Update90754Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    Update90754func_8004F5A8(recordPlus4,recordPlus4,recordPlus24);
                    scratch2=Update90754Field(recordPlus1,short*,0x1D);
                    word9=1;
                    if(scratch2!=0){
                        scratch2=Update90754Field(recordPlus1,unsigned short*,0x1B);
                        scratch2+=1;
                        Update90754Field(recordPlus1,unsigned short*,0x1B)=scratch2;
                    }
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0x1D);
                    scratch3=Update90754Field(recordPlus1,unsigned char*,9);
                    scratch2=word9-scratch2;
                    Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                    word9=frame.saved.doubled48;
                    __asm__("":"=r"(word9):"0"(word9));
                    scratch3+=word9;
                    Update90754Field(recordPlus1,unsigned char*,9)=scratch3;
                    if(mode18==0){
                        if((unsigned int)maskedLow0>=13){
                            scratch4=maskedLow0-12;
                            scratch2=scratch4<<3;
                            word9=128;
                            __asm__("":"=r"(word9):"0"(word9));
                            scratch3=word9-scratch2;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x80091700));
                                scratch3=0;
                            }
                            Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                            scratch3=scratch4<<2;
                            scratch2=64;
                            scratch3=scratch2-scratch3;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x8009171C));
                                scratch3=0;
                            }
                            goto storeByte12Zero13;
                        }
                        if((unsigned int)maskedLow0>=5){
                            word9=128;
                            scratch3=low19-4;
                            scratch3<<=3;
                            scratch2=-128;
                            scratch2-=scratch3;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=word9;
                            goto storeWordToByte12Zero13;
                        }
                        scratch2=maskedLow0<<5;
                        word9=128;
                        scratch3=word9-scratch2;
                        __asm__ volatile("":"=r"(word9):"0"(word9));
                        word9=128;
                        Update90754Field(recordPlus1,unsigned char*,0xB)=word9;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=word9;
                        if(scratch3<0){
                            __asm__ volatile("" : : "i"(0x80091760));
                            scratch3=0;
                        }
                        goto storeByte13;
                    }
                    word9=1;
                    __asm__("":"=r"(word9):"0"(word9));
                    if(mode18==word9){
                        if((unsigned int)maskedLow0>=15){
                            scratch2=maskedLow0-12;
                            scratch2<<=2;
                            scratch3=64;
                            scratch3-=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x80091798));
                                scratch3=0;
                            }
                            goto storeByte12Zero13;
                        }
                        if((unsigned int)maskedLow0>=5){
                            scratch2=low19-4;
                            scratch2<<=3;
                            scratch2=~scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                            goto storeWordToByte12Zero13;
                        }
                        scratch2=maskedLow0<<5;
                        word9=128;
                        scratch3=word9-scratch2;
                        scratch2=255;
                        if(scratch3<0){
                            __asm__ volatile("" : : "i"(0x800917CC));
                            scratch3=0;
                        }
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                    storeByte13:
                        Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                        goto finishByteModes;
                    }
                    if(mode18==2){
                        if((unsigned int)maskedLow0>=15){
                            scratch2=maskedLow0-12;
                            scratch2<<=2;
                            scratch3=64;
                            scratch3-=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=0;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x8009180C));
                                scratch3=0;
                            }
                            Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                            goto finishByteModes;
                        }
                        if((unsigned int)maskedLow0>=5){
                            scratch2=low19-4;
                            scratch2<<=3;
                            scratch2=~scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=0;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                            goto finishByteModes;
                        }
                        scratch2=maskedLow0<<5;
                        word9=128;
                        scratch3=word9-scratch2;
                        scratch2=255;
                        if(scratch3<0){
                            __asm__ volatile("" : : "i"(0x80091850));
                            scratch3=0;
                        }
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        goto storeByte13;
                    }
                    if(mode18==3){
                        if((unsigned int)maskedLow0>=15){
                            scratch2=maskedLow0-12;
                            scratch2<<=2;
                            scratch3=64;
                            scratch3-=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x8009188C));
                                scratch3=0;
                            }
                            Update90754Field(recordPlus1,unsigned char*,0xD)=scratch3;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=0;
                            goto finishByteModes;
                        }
                        if((unsigned int)maskedLow0>=5){
                            scratch2=low19-4;
                            scratch2<<=3;
                            scratch2=~scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=0;
                            goto finishByteModes;
                        }
                        scratch2=maskedLow0<<5;
                        word9=128;
                        scratch3=word9-scratch2;
                        scratch2=255;
                        if(scratch3<0){
                            __asm__ volatile("" : : "i"(0x800918D0));
                            scratch3=0;
                        }
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                        Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                        goto finishByteModes;
                    }
                    if(mode18==4){
                        if((unsigned int)maskedLow0>=15){
                            scratch2=maskedLow0-12;
                            scratch2<<=2;
                            scratch3=64;
                            scratch3-=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x80091910));
                                scratch3=0;
                            }
                            Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                            goto storeByte13;
                        }
                        if((unsigned int)maskedLow0>=5){
                            scratch2=low19-4;
                            scratch2<<=3;
                            scratch2=~scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=0;
                        storeWordToBytes12And13:
                            Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                            goto finishByteModes;
                        }
                        scratch2=savedLow21<<5;
                        word9=128;
                        scratch3=word9-scratch2;
                        scratch2=255;
                        if(scratch3<0){
                            __asm__ volatile("" : : "i"(0x80091948));
                            scratch3=0;
                        }
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        goto finishByteModes;
                    }
                    if(mode18==5){
                        __asm__ volatile("":"=r"(savedLow21):"0"(savedLow21));
                        if((unsigned int)maskedLow0>=15){
                            scratch2=maskedLow0-12;
                            scratch2<<=2;
                            scratch3=64;
                            scratch3-=scratch2;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x80091988));
                                scratch3=0;
                            }
                            Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                        storeByte12Zero13:
                            Update90754Field(recordPlus1,unsigned char*,0xC)=scratch3;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                            goto finishByteModes;
                        }
                        scratch3=(unsigned char)savedLow21;
                        if((unsigned int)scratch3>=5){
                            scratch2=savedLow21-4;
                            scratch2<<=3;
                            scratch2=~scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        storeWordToByte12Zero13:
                            Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=0;
                            goto finishByteModes;
                        }
                        scratch2=scratch3<<5;
                        word9=128;
                        __asm__ volatile("":"=r"(word9):"0"(word9));
                        word9=128;
                        scratch3=word9-scratch2;
                        scratch2=255;
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        if(scratch3<0){
                            __asm__ volatile("" : : "i"(0x800919E0));
                            scratch3=0;
                        }
                        goto storeByte13;
                    }
                    if(mode18==6){
                        if((unsigned int)maskedLow0>=4){
                            scratch2=maskedLow0<<3;
                            scratch2-=maskedLow0;
                            scratch3=160;
                            scratch3-=scratch2;
                            scratch2=(unsigned char)scratch3;
                            if(scratch3<0){
                                __asm__ volatile("" : : "i"(0x80091A14));
                                scratch3=0;
                            }
                            scratch2=(unsigned char)scratch3;
                            scratch2=(unsigned int)scratch2>>1;
                            Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                            scratch2=(unsigned int)scratch2>>1;
                            Update90754Field(recordPlus1,unsigned char*,0xB)=scratch3;
                            Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                            goto finishByteModes;
                        }
                        scratch2=160;
                        Update90754Field(recordPlus1,unsigned char*,0xB)=scratch2;
                        scratch2=80;
                        Update90754Field(recordPlus1,unsigned char*,0xC)=scratch2;
                        scratch2=40;
                        Update90754Field(recordPlus1,unsigned char*,0xD)=scratch2;
                        goto finishByteModes;
                    }
                    if(mode18==7 && savedLow21!=0)Update90754func_80056504(record);
                    goto finishByteModes;
                finishByteModes:
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch3=savedLow21+step;
                    scratch2&=224;
                    scratch3|=scratch2;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch3;
                    goto nextRecord;
                case 0x3E:
                    {
                        register unsigned char *state22 __asm__("$22");
                        register unsigned char *table18 __asm__("$18");
                        register int index21 __asm__("$21");
                        register int angle19 __asm__("$19");
                        register int raw17 __asm__("$17");
                        state22=recordPlus24;
                        table18=Update90754Field(recordPlus1,unsigned char**,0x17);
                        __asm__ volatile("":"=r"(state22),"=r"(table18):"0"(state22),"1"(table18):"memory");
                        index21=Update90754Field(recordPlus1,short*,0x1B);
                        angle19=Update90754Field(recordPlus1,short*,0x1D);
                        raw17=6;
                        if(index21==0){
                            __asm__ volatile("":"=r"(index21):"0"(index21));
                            scratch7=Update90754Field(recordPlus1,unsigned short*,3);
                            scratch7*=4;
                            frame.words[8]=scratch7;
                            scratch3=Update90754Field(recordPlus1,unsigned short*,5);
                            scratch3*=4;
                            frame.words[9]=scratch3;
                            scratch2=Update90754Field(recordPlus1,unsigned short*,7);
                            scratch2*=4;
                            frame.words[10]=scratch2;
                            scratch2=Update90754Field(table18,int*,0xC);
                            scratch6=0;
                            scratch4=Update90754Field((void*)scratch2,int*,0);
                            playerEnd=(unsigned char*)Update90754Field((void*)scratch2,int*,4);
                            scratch4-=scratch7;
                            scratch2=Update90754func_8004E880(scratch4,(int)playerEnd-scratch3,scratch6);
                            scratch2=Update90754func_8004F2EC(scratch2,angle19,1,1);
                            Update90754Field(recordPlus1,unsigned short*,0x1D)=scratch2;
                            scratch3=Update90754Field(table18,int*,0xC);
                            scratch2=frame.words[10];
                            scratch3=Update90754Field((void*)scratch3,int*,8);
                            scratch2-=2200;
                            scratch3=scratch2-scratch3;
                            predicate2=scratch3<1501;
                            if(!predicate2){
                                scratch2=Update90754Field(recordPlus1,unsigned short*,7);
                                scratch2-=75;
                                Update90754Field(recordPlus1,unsigned short*,7)=scratch2;
                                goto join3E;
                            }
                            predicate2=scratch3 < -1500;
                            if(predicate2){
                                scratch2=Update90754Field(recordPlus1,unsigned short*,7);
                                scratch2+=75;
                                Update90754Field(recordPlus1,unsigned short*,7)=scratch2;
                            }
                        }
                        else{
                            scratch3=Update90754Field(table18,short*,0);
                            var_a1=index21+1;
                            predicate2=var_a1<scratch3;
                            __asm__ volatile(".set	noreorder" : "=r"(predicate2) : "0"(predicate2));
                            if(!predicate2){
                                scratch4=(int)&frame.words[4];
                                __asm__ volatile(".set	reorder" : "=r"(scratch4) : "0"(scratch4));
                                var_a1=scratch3-1;
                                scratch2=Update90754Field(table18,int*,0xC);
                                scratch6=var_a1<<4;
                                var_a1=scratch2+scratch6;
                                scratch6-=16;
                                scratch6+=scratch2;
                            }
                            else{
                                scratch4=(int)&frame.words[4];
                                __asm__ volatile(".set	reorder" : "=r"(scratch4) : "0"(scratch4));
                                __asm__ volatile("":"=r"(var_a1):"0"(var_a1),"r"(scratch4),"i"(0x80091B7C));
                                var_a1<<=4;
                                scratch6=Update90754Field(table18,int*,0xC);
                                __asm__("":"=r"(index21):"0"(index21));
                                scratch2=index21<<4;
                                var_a1=scratch6+var_a1;
                                scratch6+=scratch2;
                            }
                            Update90754func_8004F1C8((void*)scratch4,(void*)var_a1,(void*)scratch6);
                            scratch4=frame.words[4];
                            var_a1=frame.words[5];
                            scratch2=Update90754func_8004E880(scratch4,var_a1,0);
                            scratch4=scratch2;
                            var_a1=angle19;
                            __asm__("":"=r"(scratch4),"=r"(var_a1):"0"(scratch4),"1"(var_a1));
                            scratch6=raw17;
                            scratch7=(scratch6>>1)+1;
                            scratch2=Update90754func_8004F2EC(scratch4,var_a1,scratch6,scratch7);
                            Update90754Field(state22,unsigned short*,6)=scratch2;
                        }
                    join3E:
                        raw17=350;
                        if(index21==0)raw17=100;
                        scratch3=angle19<<1;
                        word9=(int)Update90754Sin;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=scratch3+word9;
                        __asm__("":"=r"(scratch2):"0"(scratch2));
                        scratch2=Update90754Field((void*)scratch2,short*,0);
                        word9=raw17*scratch2;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=word9>>12;
                        frame.halves[24]=scratch2;
                        scratch2=Update90754Field(Update90754Cos,short*,scratch3);
                        word9=raw17*scratch2;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=word9>>12;
                        frame.halves[26]=0;
                        frame.halves[25]=scratch2;
                        Update90754func_8004F5A8(recordPlus4,recordPlus4,&frame.halves[24]);
                        word9=(int)Update90754Sin;
                        __asm__("":"=r"(word9):"0"(word9));
                        scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                        __asm__ volatile("":"=r"(scratch2):"0"(scratch2):"memory");
                        scratch4=Update90754Field(recordPlus1,unsigned char*,1);
                        __asm__("":"=r"(scratch2),"=r"(scratch4):"0"(scratch2),"1"(scratch4));
                        scratch2=(scratch2<<4)&0x1F0;
                        scratch2+=word9;
                        scratch4=(scratch4<<4)&0x1F0;
                        __asm__("":"=r"(scratch2),"=r"(scratch4):"0"(scratch2),"1"(scratch4));
                        scratch3=Update90754Field((void*)scratch2,unsigned short*,0);
                        scratch2=Update90754Field(recordPlus1,unsigned short*,3);
                        scratch3=(scratch3<<16)>>25;
                        scratch2+=scratch3;
                        Update90754Field(recordPlus1,unsigned short*,3)=scratch2;
                        scratch3=Update90754Field(Update90754Cos,unsigned short*,scratch4);
                        scratch2=Update90754Field(recordPlus1,unsigned short*,5);
                        scratch8=Update90754Field(recordPlus1,unsigned short*,3);
                        __asm__("":"=r"(scratch3),"=r"(scratch2),"=r"(scratch8):"0"(scratch3),"1"(scratch2),"2"(scratch8));
                        scratch3=(scratch3<<16)>>25;
                        scratch2+=scratch3;
                        scratch8*=4;
                        Update90754Field(recordPlus1,unsigned short*,5)=scratch2;
                        frame.words[4]=scratch8;
                        scratch7=Update90754Field(recordPlus1,unsigned short*,5);
                        scratch7*=4;
                        frame.words[5]=scratch7;
                        scratch2=Update90754Field(recordPlus1,unsigned short*,7);
                        scratch6=0;
                        scratch2*=4;
                        frame.words[6]=scratch2;
                        scratch3=Update90754Field(table18,int*,0xC);
                        scratch2=index21<<4;
                        scratch2+=scratch3;
                        scratch4=Update90754Field((void*)scratch2,int*,0);
                        var_a1=Update90754Field((void*)scratch2,int*,4);
                        scratch4-=scratch8;
                        var_a1-=scratch7;
                        scratch2=Update90754func_8004E880(scratch4,var_a1,scratch6);
                        scratch2=Update90754func_8004F264(scratch2,Update90754Field(state22,short*,6));
                        if(scratch2>=65){
                            scratch2=Update90754Field(state22,unsigned short*,4);
                            scratch2+=1;
                            Update90754Field(state22,unsigned short*,4)=scratch2;
                            __asm__("":"=r"(scratch2):"0"(scratch2));
                            scratch2<<=16;
                            scratch3=Update90754Field(table18,short*,0);
                            scratch2>>=16;
                            predicate2=scratch2<scratch3;
                            scratch4=scratch3;
                            if(!predicate2){
                                __asm__ volatile("":"=r"(scratch4):"0"(scratch4),"i"(0x80091D08));
                                scratch2=scratch4-1;
                                Update90754Field(state22,unsigned short*,4)=scratch2;
                            }
                        }
                        scratch2=Update90754Field(recordPlus1,unsigned char*,0xA);
                        if(scratch2==0 || (Update90754D_8006C640&1)!=0){
                            scratch2=Update90754Field(recordPlus1,unsigned char*,9);
                            scratch2+=1;
                            Update90754Field(recordPlus1,unsigned char*,9)=scratch2;
                        }
                        scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                        scratch3=scratch2+1;
                        predicate2=(unsigned int)scratch2<101;
                        Update90754Field(recordPlus1,unsigned char*,1)=scratch3;
                        if(!predicate2)goto removeRecord;
                        if(index21==0)goto nextRecord;
                        scratch2=scratch3&255;
                        if((unsigned int)scratch2<11)goto nextRecord;
                        if(Update90754Field(recordPlus1,unsigned char*,0xA)==0)goto checkByte2;
                        goto nextRecord;
                    }
                case 0x42:
                    iteration = 0;
                    if (step > 0) {
                        do {
                            if (Update90754Field(recordPlus1, unsigned char *, 1) & 1) {
                                scratch2=Update90754Field(recordPlus1, unsigned short *, 3);
                                scratch4=Update90754Field(recordPlus1, unsigned short *, 0xF);
                                scratch3=Update90754Field(recordPlus1, unsigned short *, 5);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                temp_a1=Update90754Field(recordPlus1, unsigned short *, 0x11);
                                scratch2+=scratch4;
                                Update90754Field(recordPlus1, unsigned short *, 3)=scratch2;
                                scratch2=Update90754Field(recordPlus1, unsigned short *, 7);
                                scratch4=Update90754Field(recordPlus1, unsigned short *, 0x13);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch3+=temp_a1;
                                Update90754Field(recordPlus1, unsigned short *, 5)=scratch3;
                                scratch3=Update90754Field(recordPlus1, unsigned char *, 1);
                                __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                                scratch2+=scratch4;
                                scratch3&=2;
                                Update90754Field(recordPlus1, unsigned short *, 7)=scratch2;
                                if(scratch3!=0){
                                    random2=Update90754rand();
                                    halfword3=Update90754Field(recordPlus1, unsigned short *, 0xF);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update90754Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                                    random2=Update90754rand();
                                    halfword3=Update90754Field(recordPlus1, unsigned short *, 0x11);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update90754Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                                    random2=Update90754rand();
                                    halfword3=Update90754Field(recordPlus1, unsigned short *, 0x13);
                                    __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                                    random2 &= 2;
                                    halfword3 -= 1;
                                    halfword3 += random2;
                                    Update90754Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                                }
                            }
                            iteration += 1;
                            Update90754Field(recordPlus1, unsigned char *, 1) = (unsigned char) (Update90754Field(recordPlus1, unsigned char *, 1) + 1);
                        }
                        while (iteration < step);
                    }
                    predicate2 = (unsigned char) Update90754Field(recordPlus1, unsigned char *, 1) < 0x18U;
                    goto checkPredicate;
                case 0x46:
                    temp_v0_11 = Update90754Field(recordPlus1, unsigned char *, 1) + 1;
                    Update90754Field(recordPlus1, unsigned char *, 1) = temp_v0_11;
                    if (((unsigned int) (temp_v0_11 & 0xFF) < 0x20U) && (Update90754Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_3 = (int) ((short) Update90754Field(recordPlus1, unsigned short *, 9) - (short) Update90754Field(recordPlus1, unsigned short *, 3)) >> 1;
                        frame.halves[16] = (unsigned short) temp_a0_3;
                        frame.halves[17] = (unsigned short) ((int) ((short) Update90754Field(recordPlus1, unsigned short *, 0xB) - (short) Update90754Field(recordPlus1, unsigned short *, 5)) >> 1);
                        frame.halves[18] = (unsigned short) ((int) ((short) Update90754Field(recordPlus1, unsigned short *, 0xD) - (short) Update90754Field(recordPlus1, unsigned short *, 7)) >> 1);
                        Update90754Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 3) + temp_a0_3);
                        Update90754Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 5) + frame.halves[17]);
                        Update90754Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 7) + frame.halves[18]);
                        random2=Update90754rand();
                        halfword3=frame.halves[16];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[16]=halfword3;
                        random2=Update90754rand();
                        halfword3=frame.halves[17];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.halves[17]=halfword3;
                        if (Update90754Field(recordPlus1, unsigned char *, 1) & 1) {
                            frame.halves[18] -= 1;
                        }
                        random2=Update90754Field(recordPlus1, unsigned short *, 9);
                        halfword3=frame.halves[16];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update90754Field(recordPlus1, unsigned short *, 9)=random2;
                        random2=Update90754Field(recordPlus1, unsigned short *, 0xB);
                        halfword3=frame.halves[17];
                        __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                        random2+=halfword3;
                        Update90754Field(recordPlus1, unsigned short *, 0xB)=random2;
                        halfword3=Update90754Field(recordPlus1, unsigned short *, 0xD);
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0xF);
                        scratch4=frame.halves[18];
                        __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                        scratch2=scratch2-3;
                        halfword3+=scratch4;
                        Update90754Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2&=255;
                        __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                        Update90754Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                        if((unsigned int)scratch2<128){
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            Update90754Field(recordPlus1,unsigned char*,0xF)=word9;
                        }
                        temp_v0_13 = Update90754Field(recordPlus1, unsigned char *, 0x10) - 4;
                        Update90754Field(recordPlus1, unsigned char *, 0x10) = temp_v0_13;
                        if ((unsigned int) (temp_v0_13 & 0xFF) < 0x60U) {
                            Update90754Field(recordPlus1, unsigned char *, 0x10) = 0x60U;
                        }
                        Update90754Field(recordPlus1, unsigned char *, 0x11) = 0;
                        temp_v0_14 = (unsigned char) Update90754Field(recordPlus1, unsigned char *, 0x13) - 3;
                        Update90754Field(recordPlus1, unsigned char *, 0x13) = temp_v0_14;
                        if ((unsigned int) (temp_v0_14 & 0xFF) < 0xC0U) {
                            Update90754Field(recordPlus1, unsigned char *, 0x13) = 0xC0;
                        }
                        temp_v0_15 = Update90754Field(recordPlus1, unsigned char *, 0x14) - 4;
                        Update90754Field(recordPlus1, unsigned char *, 0x14) = temp_v0_15;
                        if ((unsigned int) (temp_v0_15 & 0xFF) < 0x80U) {
                            __asm__ volatile("" ::: "$8","memory");
                            word9=128;
                            __asm__("" : "=r"(word9) : "0"(word9));
                            Update90754Field(recordPlus1,unsigned char*,0x14)=word9;
                        }
                        temp_v0_16 = (unsigned char) Update90754Field(recordPlus1, unsigned char *, 0x15) - 6;
                        Update90754Field(recordPlus1, unsigned char *, 0x15) = temp_v0_16;
                        if ((unsigned int) (temp_v0_16 & 0xFF) < 0x20U) {
                            Update90754Field(recordPlus1, unsigned char *, 0x15) = 0x20;
                        }
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x47:
                    temp_v0_17 = Update90754Field(recordPlus1, unsigned char *, 1) + 1;
                    Update90754Field(recordPlus1, unsigned char *, 1) = temp_v0_17;
                    if (((unsigned int) (temp_v0_17 & 0xFF) < 0x20U) && (Update90754Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[8] = (short) Update90754Field(recordPlus1, unsigned short *, 9) - (short) Update90754Field(recordPlus1, unsigned short *, 3);
                        frame.words[9] = (short) Update90754Field(recordPlus1, unsigned short *, 0xB) - (short) Update90754Field(recordPlus1, unsigned short *, 5);
                        frame.words[10] = (short) Update90754Field(recordPlus1, unsigned short *, 0xD) - (short) Update90754Field(recordPlus1, unsigned short *, 7);
                        random2=Update90754rand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        random2=Update90754rand();
                        halfword3=frame.words[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[9]=halfword3;
                        random2=Update90754rand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        Update90754Field(recordPlus1, unsigned short *, 9) = (short) ((unsigned short) Update90754Field(recordPlus1, unsigned short *, 9) + frame.words[8]);
                        Update90754Field(recordPlus1, unsigned short *, 0xB) = (short) ((unsigned short) Update90754Field(recordPlus1, unsigned short *, 0xB) + frame.words[9]);
                        Update90754Field(recordPlus1, unsigned short *, 0xD) = (short) ((unsigned short) Update90754Field(recordPlus1, unsigned short *, 0xD) + frame.words[10]);
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[8];
                        scratch2=Update90754Field(recordPlus1, unsigned short *, 9);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update90754Field(recordPlus1, unsigned short *, 3)=scratch2;
                        __asm__ __volatile__("" ::: "memory");
                        scratch3=frame.words[9];
                        scratch2=Update90754Field(recordPlus1, unsigned short *, 0xB);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=scratch3;
                        Update90754Field(recordPlus1, unsigned short *, 5)=scratch2;
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0x13);
                        scratch4=frame.words[10];
                        scratch3=Update90754Field(recordPlus1, unsigned char *, 0x15);
                        __asm__("" : "=r"(scratch2),"=r"(scratch4),"=r"(scratch3) : "0"(scratch2),"1"(scratch4),"2"(scratch3));
                        scratch2-=2;
                        Update90754Field(recordPlus1, unsigned char *, 0x13)=scratch2;
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0x14);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=4;
                        Update90754Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                        scratch3=Update90754Field(recordPlus1, unsigned char *, 0x10);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=2;
                        Update90754Field(recordPlus1, unsigned char *, 0x14)=scratch2;
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0xF);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=3;
                        Update90754Field(recordPlus1, unsigned char *, 0x10)=scratch3;
                        scratch3=Update90754Field(recordPlus1, unsigned short *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch2-=3;
                        Update90754Field(recordPlus1, unsigned char *, 0xF)=scratch2;
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0x11);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3),"=r"(scratch4) : "0"(scratch2),"1"(scratch3),"2"(scratch4));
                        scratch3-=scratch4;
                        Update90754Field(recordPlus1, unsigned short *, 7)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=3;
                        Update90754Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x48:
                    temp_v0_18 = Update90754Field(recordPlus1, unsigned char *, 1) + 1;
                    Update90754Field(recordPlus1, unsigned char *, 1) = temp_v0_18;
                    if (((unsigned int) (temp_v0_18 & 0xFF) < 0x38U) && (Update90754Field(recordPlus1, unsigned char *, 2) != 0)) {
                        frame.words[8] = (int) ((short) Update90754Field(recordPlus1, unsigned short *, 3) - (short) Update90754Field(recordPlus1, unsigned short *, 9)) >> 1;
                        frame.words[9] = (int) ((short) Update90754Field(recordPlus1, unsigned short *, 5) - (short) Update90754Field(recordPlus1, unsigned short *, 0xB)) >> 1;
                        frame.words[10] = (int) ((short) Update90754Field(recordPlus1, unsigned short *, 7) - (short) Update90754Field(recordPlus1, unsigned short *, 0xD)) >> 1;
                        random2=Update90754rand();
                        halfword3=frame.words[8];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[8]=halfword3;
                        random2=Update90754rand();
                        halfword3=frame.words[9];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 4;
                        halfword3 -= 2;
                        halfword3 += random2;
                        frame.words[9]=halfword3;
                        random2=Update90754rand();
                        halfword3=frame.words[10];
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        frame.words[10]=halfword3;
                        Update90754Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 3) + frame.words[8]);
                        Update90754Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 5) + frame.words[9]);
                        Update90754Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 7) + frame.words[10]);
                        __asm__ __volatile__("" ::: "memory");
                        Update90754Field(recordPlus1, unsigned short *, 9) = (short) (Update90754Field(recordPlus1, unsigned short *, 3) - (frame.words[8] * 2));
                        Update90754Field(recordPlus1, unsigned short *, 0xB) = (short) (Update90754Field(recordPlus1, unsigned short *, 5) - (frame.words[9] * 2));
                        Update90754Field(recordPlus1, unsigned short *, 0xD) = (short) (Update90754Field(recordPlus1, unsigned short *, 7) - (frame.words[10] * 2));
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4E:
                    temp_v0_19 = Update90754Field(recordPlus1, unsigned char *, 1) + 1;
                    Update90754Field(recordPlus1, unsigned char *, 1) = temp_v0_19;
                    if (((unsigned int) (temp_v0_19 & 0xFF) < 0x28U) && (Update90754Field(recordPlus1, unsigned char *, 2) != 0)) {
                        temp_a0_4 = Update90754Field(recordPlus1, unsigned short *, 0x11);
                        temp_a1_2 = Update90754Field(recordPlus1, unsigned short *, 0x13);
                        Update90754Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 3) + Update90754Field(recordPlus1, unsigned short *, 0xF));
                        Update90754Field(recordPlus1, unsigned short *, 5) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 5) + temp_a0_4);
                        Update90754Field(recordPlus1, unsigned short *, 7) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 7) + temp_a1_2);
                        random2=Update90754rand();
                        halfword3=Update90754Field(recordPlus1, unsigned short *, 0xF);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update90754Field(recordPlus1, unsigned short *, 0xF)=halfword3;
                        random2=Update90754rand();
                        halfword3=Update90754Field(recordPlus1, unsigned short *, 0x11);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2 &= 2;
                        halfword3 -= 1;
                        halfword3 += random2;
                        Update90754Field(recordPlus1, unsigned short *, 0x11)=halfword3;
                        random2=Update90754rand();
                        halfword3=Update90754Field(recordPlus1, unsigned short *, 0x13);
                        __asm__ __volatile__("" : "=r"(halfword3),"=r"(random2) : "0"(halfword3),"1"(random2) : "memory");
                        random2&=2;
                        halfword3-=1;
                        halfword3+=random2;
                        Update90754Field(recordPlus1, unsigned short *, 0x13)=halfword3;
                        __asm__("" : "=r"(halfword3) : "0"(halfword3));
                        halfword3=(short)halfword3;
                        if(halfword3>=3)Update90754Field(recordPlus1, unsigned short *, 0x13)=2;
                        scratch2=Update90754Field(recordPlus1, short *, 0x13);
                        if(scratch2 < -4)Update90754Field(recordPlus1, short *, 0x13)=-4;
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0xB);
                        scratch3=Update90754Field(recordPlus1, unsigned char *, 0xD);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch2-=2;
                        Update90754Field(recordPlus1, unsigned char *, 0xB)=scratch2;
                        scratch2=Update90754Field(recordPlus1, unsigned char *, 0xC);
                        __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                        scratch3-=1;
                        Update90754Field(recordPlus1, unsigned char *, 0xD)=scratch3;
                        __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                        scratch2-=2;
                        Update90754Field(recordPlus1, unsigned char *, 0xC)=scratch2;
                        goto nextRecord;
                    }
                    goto removeRecord;
                case 0x4F:
                    temp_a0_5 = (int) ((short) Update90754Field(recordPlus1, unsigned short *, 9) - (short) Update90754Field(recordPlus1, unsigned short *, 3)) >> 1;
                    frame.halves[16] = (unsigned short) temp_a0_5;
                    frame.halves[17] = (unsigned short) ((int) ((short) Update90754Field(recordPlus1, unsigned short *, 0xB) - (short) Update90754Field(recordPlus1, unsigned short *, 5)) >> 1);
                    frame.halves[18] = (unsigned short) ((int) ((short) Update90754Field(recordPlus1, unsigned short *, 0xD) - (short) Update90754Field(recordPlus1, unsigned short *, 7)) >> 1);
                    Update90754Field(recordPlus1, unsigned short *, 3) = (unsigned short) (Update90754Field(recordPlus1, unsigned short *, 3) + temp_a0_5);
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update90754Field(recordPlus1, unsigned short *, 5);
                    scratch3=frame.halves[17];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1, unsigned short *, 5)=scratch2;
                    __asm__ __volatile__("" ::: "$2", "$3", "memory");
                    scratch2=Update90754Field(recordPlus1, unsigned short *, 7);
                    scratch3=frame.halves[18];
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1, unsigned short *, 7)=scratch2;
                    __asm__ __volatile__("" ::: "memory");
                    random2=Update90754Field(recordPlus1, unsigned short *, 9);
                    halfword3=frame.halves[16];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update90754Field(recordPlus1, unsigned short *, 9)=random2;
                    random2=Update90754Field(recordPlus1, unsigned short *, 0xB);
                    halfword3=frame.halves[17];
                    __asm__("" : "=r"(random2),"=r"(halfword3) : "0"(random2),"1"(halfword3));
                    random2+=halfword3;
                    Update90754Field(recordPlus1, unsigned short *, 0xB)=random2;
                    halfword3=Update90754Field(recordPlus1, unsigned short *, 0xD);
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 1);
                    scratch4=frame.halves[18];
                    __asm__("" : "=r"(halfword3),"=r"(scratch2),"=r"(scratch4) : "0"(halfword3),"1"(scratch2),"2"(scratch4));
                    scratch2=scratch2+1;
                    halfword3+=scratch4;
                    Update90754Field(recordPlus1, unsigned char *, 1)=scratch2;
                    scratch2&=255;
                    __asm__("" : "=r"(scratch2),"=r"(halfword3) : "0"(scratch2),"1"(halfword3));
                    Update90754Field(recordPlus1, unsigned short *, 0xD)=halfword3;
                    if((unsigned int)scratch2>=24)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 2);
                    if(scratch2==0)goto removeRecord;
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 0x11);
                    scratch3=Update90754Field(recordPlus1, unsigned char *, 0x15);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch2-=3;
                    Update90754Field(recordPlus1, unsigned char *, 0x11)=scratch2;
                    scratch2=Update90754Field(recordPlus1, unsigned char *, 0x10);
                    __asm__("" : "=r"(scratch2),"=r"(scratch3) : "0"(scratch2),"1"(scratch3));
                    scratch3-=3;
                    __asm__("" : "=r"(scratch3),"=r"(scratch2) : "0"(scratch3),"1"(scratch2));
                    Update90754Field(recordPlus1, unsigned char *, 0x15)=scratch3;
                    __asm__ __volatile__("" : "=r"(scratch2) : "0"(scratch2) : "memory");
                    scratch2-=4;
                    Update90754Field(recordPlus1, unsigned char *, 0x10)=scratch2;
                    temp_v1_10 = (unsigned char) Update90754Field(recordPlus1, unsigned char *, 0x13);
                    Update90754Field(recordPlus1, unsigned char *, 0x14) = (unsigned char) (Update90754Field(recordPlus1, unsigned char *, 0x14) - 4);
                    if (temp_v1_10 >= 6U) {
                        Update90754Field(recordPlus1, unsigned char *, 0x13) = (signed char) (temp_v1_10 - 6);
                    }
                    goto nextRecord;
                case 0x55:
                    scratch4=Update90754Field(recordPlus1,unsigned short*,9);
                    scratch2=Update90754Field(recordPlus1,unsigned short*,3);
                    scratch4-=scratch2;
                    frame.halves[16]=scratch4;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0xB);
                    scratch3=Update90754Field(recordPlus1,unsigned short*,5);
                    scratch2-=scratch3;
                    frame.halves[17]=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0xD);
                    scratch3=Update90754Field(recordPlus1,unsigned short*,7);
                    scratch2-=scratch3;
                    frame.halves[18]=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,3);
                    scratch2+=scratch4;
                    Update90754Field(recordPlus1,unsigned short*,3)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,5);
                    scratch3=frame.halves[17];
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1,unsigned short*,5)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,7);
                    scratch3=frame.halves[18];
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1,unsigned short*,7)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,9);
                    scratch3=frame.halves[16];
                    scratch2+=scratch3;
                    Update90754Field(recordPlus1,unsigned short*,9)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned short*,0xB);
                    scratch3=frame.halves[17];
                    scratch2+=scratch3;
                    scratch3=Update90754Field(recordPlus1,unsigned short*,0xD);
                    Update90754Field(recordPlus1,unsigned short*,0xB)=scratch2;
                    scratch2=Update90754Field(recordPlus1,unsigned char*,1);
                    scratch4=frame.halves[18];
                    scratch2+=1;
                    scratch3+=scratch4;
                    Update90754Field(recordPlus1,unsigned char*,1)=scratch2;
                    scratch2&=255;
                    predicate2=(unsigned int)scratch2<2;
                    Update90754Field(recordPlus1,unsigned short*,0xD)=scratch3;
                checkPredicate:
                    if(predicate2==0)goto removeRecord;
                checkByte2:
                    if(Update90754Field(recordPlus1,unsigned char*,2)==0)goto removeRecord;
                    goto nextRecord;
                removeRecord:
                    Update90754func_80056504(record);
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
#undef Update90754High
#undef Update90754Field
