#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800989E8.
 * Assembly SHA256 ba12545e58aaa2ba23df6002dc68d882836853edaaf11347caee32e82ddf4333.
 * AI-generated; not human reviewed. Verified sibling C cases were adapted
 * to the original selector, field, helper, register and stack differences.
 * Selector0E is decoded from its complete original instruction chain.
 * Raw fields retain byte/halfword/word widths and original signed operations.
 * The original168-byte frame retains the outgoing fifth argument atSP10,
 * local objectSP18..13F, countSP120, iterationSP128 and strideSP138.
 * Byte255 uses ordinary C register allocation. The initialized integer SP
 * identity in selector29 derives from the local object's verifiedSP18 base;
 * it preserves the original repeated SP+A0 producers and emits no CPU word.
 * All empty metadata inputs are initialized. C emits every CPU instruction;
 * compiler/assembler/pipeline/flags, padding and acceptance gates are frozen.
 * Helper meanings/contracts, physical units/fixed point and caller cadence
 * remain unresolved. Cadence per invocation; invocation rate unknown.
 * Falsification: every original native/linked word, conditional/internal
 * target, owned table/data record, and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
int Spawn989E8func_8004F570(void*,void*) __asm__("func_8004F570");
int Spawn989E8func_8004F5A8(void*,void*,void*) __asm__("func_8004F5A8");
#include "common.h"
extern int Spawn989E8D_8006E020 __asm__("D_8006E020");
extern int Spawn989E8D_8006E024 __asm__("D_8006E024");
extern int Spawn989E8D_8006E028 __asm__("D_8006E028");
extern int Spawn989E8D_80071918 __asm__("D_80071918");
extern int Spawn989E8D_8007191C __asm__("D_8007191C");
extern int Spawn989E8D_80071920 __asm__("D_80071920");
extern int Spawn989E8D_80071930 __asm__("D_80071930");
extern unsigned short Spawn989E8D_8006E03E __asm__("D_8006E03E");
extern short Spawn989E8D_8006E040 __asm__("D_8006E040");
int Spawn989E8func_8004EA2C(int) __asm__("func_8004EA2C");
int Spawn989E8func_8004E9E4(int) __asm__("func_8004E9E4");
int Spawn989E8func_8001A310(void*,int,int,int) __asm__("func_8001A310");
int Spawn989E8func_8001A358(void*,int) __asm__("func_8001A358");
extern int Spawn989E8D_8006D07C __asm__("D_8006D07C");
extern int Spawn989E8D_8006D080 __asm__("D_8006D080");
extern int Spawn989E8D_8006D084 __asm__("D_8006D084");
extern int Spawn989E8D_80071934 __asm__("D_80071934");
extern unsigned char Spawn989E8PlayerE __asm__("D_80070328 + 0xE");
#define Spawn989E8High(a,b) ({ int high; __asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory"); high; })
extern unsigned char Spawn989E8Color1[] __asm__("D_80066BAC");
extern unsigned char Spawn989E8Color2[] __asm__("D_80066BAC");
#define Spawn989E8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Spawn989E8func_8004EA90(void*,void*,int) __asm__("func_8004EA90");
int Spawn989E8func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Spawn989E8func_8004F110(void*,int) __asm__("func_8004F110");
int Spawn989E8func_8004F178(void*,void*) __asm__("func_8004F178");
int Spawn989E8func_8004F194(void*,void*,void*) __asm__("func_8004F194");
int Spawn989E8func_8004F1FC(void*,void*,int) __asm__("func_8004F1FC");
int Spawn989E8func_8004F504(void*,void*) __asm__("func_8004F504");
void* Spawn989E8func_80056434(int) __asm__("func_80056434");
int Spawn989E8func_8003636C(int,int) __asm__("func_8003636C");
int Spawn989E8func_8004F58C(void*,void*) __asm__("func_8004F58C");
int Spawn989E8rand(void) __asm__("rand");
extern unsigned char Spawn989E8D_800658A0[] __asm__("D_800658A0");
extern unsigned char Spawn989E8D_80065920[] __asm__("D_80065920");
extern unsigned char Spawn989E8D_80066A28[] __asm__("D_80066A28");
extern unsigned char Spawn989E8D_80066A48[] __asm__("D_80066A48");
extern unsigned char Spawn989E8D_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Spawn989E8D_80070328[] __asm__("D_80070328");
extern int Spawn989E8D_8006E344 __asm__("D_8006E344");
int Spawn989E8func_8001830C(void*,void*,int,int,int) __asm__("func_8001830C");
extern int Spawn989E8D_80071908 __asm__("D_80071908");
#define Spawn989E8Stack(t,o) (*(t*)((unsigned char*)&frame+(o)-0x18))
void *func_level_50_800989E8(int entryCount,int kind,void *input,void *mode) {
    int frame[74];
    register void *vector16 __asm__("$16");
    register int kindSelector __asm__("$23")=kind;
    register unsigned char *reference __asm__("$20")=input;
    register unsigned char *modeSelector __asm__("$22")=mode;
    register unsigned char *temp_s1 __asm__("$17");
    register unsigned char *temp_s1_2 __asm__("$17");
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    register int commonByte8 __asm__("$8");
    register int commonByte9 __asm__("$9");
    int byte255;
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    register int tailByte __asm__("$2");
    register int scratch19 __asm__("$18");
    int var_v0_2;
    register int var_v0_4 __asm__("$2");
    unsigned int temp_v1_2;
    unsigned char temp_v1_3;
    void *var_a0;
    register unsigned char *record __asm__("$19");
    __asm__("":"=r"(kindSelector),"=r"(reference),"=r"(modeSelector):"0"(kindSelector),"1"(reference),"2"(modeSelector));
    record=0;
    __asm__("":"=r"(record):"0"(record));
    Spawn989E8Stack(int,0x120)=entryCount;
    Spawn989E8Stack(int,0x128)=0;
    if(entryCount>0){
        byte255=255;
        __asm__ volatile("":"=r"(byte255):"0"(byte255):"memory");
        Spawn989E8Stack(volatile int,0x138)=0;
        do{
            __asm__ volatile("":"=r"(byte255):"0"(byte255):"memory");
            switch(kindSelector){
            case 0x0:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    register int one __asm__("$8");
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$9");
                    one=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = one;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x18;
                tailByte=Spawn989E8rand();
                commonByte9=128;
                commonByte8=128;
                __asm__("" : "=r"(commonByte9),"=r"(commonByte8),"=r"(tailByte):"0"(commonByte9),"1"(commonByte8),"2"(tailByte));
                Spawn989E8Field(record,volatile unsigned char*,12)=commonByte9;
                Spawn989E8Field(record,volatile unsigned char*,13)=commonByte8;
                commonByte8=46;
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                __asm__ volatile("" : "=r"(commonByte9),"=r"(commonByte8):"0"(commonByte9),"1"(commonByte8):"$3","memory");
                tailByte=4;
                Spawn989E8Field(record,unsigned char*,14)=commonByte9;
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            case 0x1:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                    tailByte=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = tailByte;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x10;
                tailByte=Spawn989E8rand();
                Spawn989E8Field(record, unsigned char *, 0xB) = tailByte;
                __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                tailByte=96;
                commonByte9=46;
                __asm__("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"memory");
                Spawn989E8Field(record, unsigned char *, 0xC) = tailByte;
                Spawn989E8Field(record, unsigned char *, 0xD) = tailByte;
                Spawn989E8Field(record, unsigned char *, 0xE) = tailByte;
                __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                tailByte=4;
                goto initializeF9;
            case 0x4:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                    tailByte=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = tailByte;
                    Spawn989E8func_8004F504(destination, source);
                }
                tailByte=8;
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                tailByte=Spawn989E8rand();
                commonByte8=128;
                commonByte9=128;
                __asm__("":"=r"(tailByte),"=r"(commonByte8),"=r"(commonByte9):"0"(tailByte),"1"(commonByte8),"2"(commonByte9));
                Spawn989E8Field(record,volatile unsigned char*,12)=commonByte8;
                Spawn989E8Field(record,volatile unsigned char*,13)=commonByte9;
                commonByte9=46;
                Spawn989E8Field(record,volatile unsigned char*,14)=commonByte8;
                commonByte8=2;
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                Spawn989E8Field(record,volatile unsigned char*,15)=commonByte9;
                Spawn989E8Field(record,volatile unsigned char*,17)=commonByte8;
                Spawn989E8Field(record,unsigned char*,16)=0;
                tailByte=Spawn989E8rand();
                tailByte&=3;
                __asm__("" : "=r"(tailByte):"0"(tailByte));
                tailByte+=4;
                Spawn989E8Field(record,unsigned short*,24)=tailByte;
                tailByte=Spawn989E8rand();
                tailByte&=3;
                tailByte+=2;
                Spawn989E8Field(record,unsigned short*,26)=tailByte;
                tailByte=Spawn989E8rand();
                tailByte&=7;
                tailByte+=3;
                Spawn989E8Field(record,unsigned short*,28)=tailByte;
                tailByte=(int)modeSelector>>2;
                Spawn989E8Field(record,unsigned short*,30)=tailByte;
                break;
            case 0x9:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=&Spawn989E8Stack(int,0x18);
                    register unsigned char *player __asm__("$16");
                    register void *source __asm__("$5");
                    __asm__("" : "=r"(destination) : "0"(destination) : "$16");
                    player=Spawn989E8D_80070328;
                    source=player;
                    __asm__("" : "=r"(destination),"=r"(source),"=r"(player) : "0"(destination),"1"(source),"2"(player) : "$2");
                    tailByte=1;
                    __asm__ volatile("" : "=r"(tailByte),"=r"(destination),"=r"(source),"=r"(player) : "0"(tailByte),"1"(destination),"2"(source),"3"(player) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = tailByte;
                    Spawn989E8func_8004F178(destination,source);
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x18);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0x7E;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=0x3F;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=random;
                        Spawn989E8Stack(int,0x18)=component;
                    }
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3");
                        register void *destination __asm__("$4")=record+4;
                        register void *source __asm__("$5")=&Spawn989E8Stack(int,0x18);
                        __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$3","memory");
                        component=Spawn989E8Stack(int,0x1C);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0x7E;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=0x3F;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=random;
                        Spawn989E8Stack(int,0x1C)=component;
                        Spawn989E8func_8004F504(destination,source);
                    }
                    Spawn989E8func_8004F178(&Spawn989E8Stack(int,0x18), player + 0x98);
                    Spawn989E8func_8004F110(&Spawn989E8Stack(int,0x18), 6);
                    Spawn989E8func_8004F504(record + 0x18, &Spawn989E8Stack(int,0x18));
                }
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x18;
                tailByte = Spawn989E8rand();
                commonByte9=128;
                commonByte8=128;
                __asm__("" : "=r"(commonByte9),"=r"(commonByte8),"=r"(tailByte):"0"(commonByte9),"1"(commonByte8),"2"(tailByte));
                Spawn989E8Field(record,volatile unsigned char*,12)=commonByte9;
                Spawn989E8Field(record,volatile unsigned char*,13)=commonByte8;
                commonByte8=46;
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,volatile unsigned char*,14)=commonByte9;
                __asm__ volatile("" ::: "memory");
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            case 0xA:
                record = Spawn989E8func_80056434(3);
                Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=Spawn989E8D_80070328;
                    tailByte=Spawn989E8rand();
                    destination=record+4;
                    source=Spawn989E8D_80070328;
                    tailByte&=31;
                    __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Spawn989E8Field(record,unsigned char*,2)=tailByte;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    tailByte=1;
                    Spawn989E8Field(record,unsigned char*,3)=tailByte;
                    Spawn989E8func_8004F504(destination,source);
                }
                {
                    register int factor __asm__("$4")=0x66660000;
                    register int value __asm__("$2");
                    register int count __asm__("$9");
                    register int iteration8 __asm__("$8");
                    register int dividend __asm__("$3");
                    register int productHigh __asm__("hi");
                    register int color __asm__("$4");
                    value=24;
                    __asm__("" : "=r"(factor),"=r"(value) : "0"(factor),"1"(value));
                    Spawn989E8Field(record,unsigned char*,10)=value;
                    value=15;
                    Spawn989E8Field(record,unsigned char*,11)=value;
                    __asm__("" : "=r"(factor) : "0"(factor) : "memory");
                    count=Spawn989E8Stack(int,0x120);
                    iteration8=Spawn989E8Stack(int,0x128);
                    __asm__("" : "=r"(count),"=r"(iteration8):"0"(count),"1"(iteration8));
                    factor|=0x6667;
                    dividend=count-iteration8;
                    count=Spawn989E8Stack(volatile int,0x138);
                    __asm__("" : "=r"(count),"=r"(dividend) : "0"(count),"1"(dividend));
                    dividend<<=12;
                    value=*(Spawn989E8D_80066BAC+count);
                    __asm__("" : "=r"(dividend),"=r"(factor) : "0"(dividend),"1"(factor) : "memory");
                    productHigh=Spawn989E8High(dividend,factor);
                    Spawn989E8Field(record,unsigned char*,12)=value;
                    value=*(Spawn989E8Color1+1+count);
                    dividend>>=31;
                    Spawn989E8Field(record,unsigned char*,13)=value;
                    color=*(Spawn989E8Color2+2+count);
                    value=44;
                    Spawn989E8Field(record,unsigned char*,15)=value;
                    value=4;
                    Spawn989E8Field(record,unsigned char*,17)=value;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    Spawn989E8Field(record,unsigned char*,14)=color;
                    __asm__("" : "=h"(productHigh),"=r"(dividend) : "0"(productHigh),"1"(dividend) : "memory");
                    iteration8=productHigh;
                    __asm__("" : "=r"(iteration8) : "0"(iteration8));
                    value=(iteration8>>1)-dividend;
                    Spawn989E8Field(record,short*,24)=value;
                }
                break;
            case 0xC:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=reference+32;
                    register int iteration __asm__("$9");
                    register void *vector __asm__("$6");
                    register int base __asm__("$2");
                    register void *table __asm__("$5");
                    __asm__("" : "=r"(destination):"0"(destination):"$2","$5","memory");
                    base=(int)Spawn989E8D_80066A48;
                    vector16=&Spawn989E8Stack(int,0x28);
                    __asm__("":"=r"(vector16):"0"(vector16):"memory");
                    iteration=Spawn989E8Stack(int,0x128);
                    __asm__ volatile("":"=r"(iteration):"0"(iteration):"$6","memory");
                    vector=vector16;
                    __asm__("":"=r"(vector16),"=r"(vector),"=r"(iteration),"=r"(base):"0"(vector16),"1"(vector),"2"(iteration),"3"(base):"memory");
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    __asm__("" : "=r"(base),"=r"(iteration):"0"(base),"1"(iteration):"memory");
                    table=(void*)(iteration*12);
                    __asm__("" : "=r"(table),"=r"(base):"0"(table),"1"(base));
                    table=(void*)((int)table+base);
                    __asm__("" : "=r"(table):"0"(table):"$2","memory");
                    base=1;
                    Spawn989E8Field(record,unsigned char*,3)=base;
                    base=4;
                    Spawn989E8Field(record,unsigned char*,17)=base;
                    Spawn989E8func_8004ED6C(destination,table,vector);
                }
                if (({
                    register int observed __asm__("$2")=Spawn989E8Field(reference,short*,54);
                    __asm__("" : "=r"(observed):"0"(observed):"memory");scratch17=0x17D;
                    __asm__("" : "=r"(scratch17):"0"(scratch17):"memory");
                    observed==scratch17;
                }
                )) {
                    Spawn989E8func_8004F1FC(vector16, vector16, 3);
                }
                Spawn989E8func_8004F194(vector16, vector16, reference + 0xC);
                if (modeSelector == (unsigned char *)5) {
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x28);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0x1FF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x100;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x28)=component;
                    }
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x2C);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0x1FF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x100;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x2C)=component;
                    }
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x30);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0x1FF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x100;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x30)=component;
                    }
                }
                if (modeSelector == (unsigned char *)6) {
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x28);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0xFF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x80;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x28)=component;
                    }
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x2C);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0xFF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x80;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x2C)=component;
                    }
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x30);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0xFF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x80;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x30)=component;
                    }
                }
                if (Spawn989E8Field(reference, short *, 0x36) == 0xB6) {
                    Spawn989E8Stack(int,0x30) += 0x200;
                }
                Spawn989E8func_8004F504(record + 4, vector16);
                Spawn989E8Field(record, int *, 0xC) = (int) *(int*)(Spawn989E8D_80066A28 + ((int) modeSelector * 4));
                if (({
                    register int observed __asm__("$2")=Spawn989E8Field(reference,short*,54);
                    __asm__("" : "=r"(scratch17):"0"(scratch17):"memory");
                    observed==scratch17;
                }
                )) {
                    var_v0_2 = (Spawn989E8rand() & 0x1F) + 0x60;
                }
                else {
                    var_v0_2 = (Spawn989E8rand() & 7) + 0x20;
                }
                Spawn989E8Field(record, unsigned char *, 0xA) = var_v0_2;
                tailByte=Spawn989E8rand();
                {
                    register void *destination __asm__("$4")=record+24;
                    register int iteration __asm__("$8")=Spawn989E8Stack(int,0x128);
                    register int base __asm__("$3");
                    register void *source __asm__("$5");
                    __asm__("" : "=r"(destination),"=r"(iteration),"=r"(tailByte):"0"(destination),"1"(iteration),"2"(tailByte):"$3","$5","memory");
                    base=(int)Spawn989E8D_80066A48;
                    Spawn989E8Field(record,unsigned char*,11)=tailByte;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    __asm__("" : "=r"(base),"=r"(iteration):"0"(base),"1"(iteration):"memory");
                    source=(void*)(iteration*12);
                    __asm__("" : "=r"(source),"=r"(base):"0"(source),"1"(base));
                    source=(void*)((int)source+base);
                    Spawn989E8func_8004F504(destination,source);
                }
                Spawn989E8Field(record, unsigned short *, 0x18) = (unsigned short) (((int) (Spawn989E8Field(record, unsigned short *, 0x18) << 0x10) >> 0x12) - 4 + (Spawn989E8rand() & 7));
                Spawn989E8Field(record, unsigned short *, 0x1A) = (unsigned short) (((int) (Spawn989E8Field(record, unsigned short *, 0x1A) << 0x10) >> 0x12) - 4 + (Spawn989E8rand() & 7));
                Spawn989E8Field(record, unsigned short *, 0x1C) = (unsigned short) (((int) (Spawn989E8Field(record, unsigned short *, 0x1C) << 0x10) >> 0x12) - 4 + (Spawn989E8rand() & 7));
                break;
            case 0xD:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    register int one __asm__("$2");
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$8");
                    one=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = one;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x18;
                tailByte=Spawn989E8rand();
                commonByte9=46;
                __asm__("":"=r"(tailByte),"=r"(commonByte9):"0"(tailByte),"1"(commonByte9));
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,volatile unsigned char*,12)=byte255;
                Spawn989E8Field(record,volatile unsigned char*,13)=byte255;
                Spawn989E8Field(record,unsigned char*,14)=0;
                goto initializeF9;
            case 0xE:
                {
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int value4 __asm__("$4");
                    register int value5 __asm__("$5");
                    register int low8 __asm__("$8");
                    register int low9 __asm__("$9");
                    register void *vector17 __asm__("$17");
                    register void *vector18 __asm__("$18");
                    register void *vector16 __asm__("$16");
                    int productLo;
                    value2=Spawn989E8rand();
                    value2&=1;
                    if(value2){
                        value2=Spawn989E8rand();
                        value3=Spawn989E8D_8006E040;
                        value2&=1023;
                        value2-=512;
                        scratch17=value3-value2;
                    }
                    else{
                        value2=Spawn989E8rand();
                        scratch17=value2&4095;
                    }
                    value2=Spawn989E8rand();
                    value4=scratch17;
                    scratch19=value2&16383;
                    value2=Spawn989E8func_8004EA2C(value4);
                    scratch16=value2;
                    value2=Spawn989E8rand();
                    productLo=scratch16*scratch19;
                    __asm__ volatile("":"=l"(productLo):"0"(productLo):"memory");
                    value4=scratch17;
                    value2&=2047;
                    value2-=1024;
                    value3=Spawn989E8Field(Spawn989E8D_80070328,int*,0x98);
                    value5=Spawn989E8D_8006E020;
                    value3<<=1;
                    value5+=value3;
                    __asm__ volatile("":"=l"(productLo),"=r"(value2),"=r"(value4),"=r"(value5):"0"(productLo),"1"(value2),"2"(value4),"3"(value5):"memory");
                    low8=productLo;
                    __asm__("":"=r"(low8):"0"(low8));
                    value3=low8>>12;
                    value5+=value3;
                    value5-=value2;
                    Spawn989E8Stack(int,0x38)=value5;
                    value2=Spawn989E8func_8004E9E4(value4);
                    scratch16=value2;
                    value2=Spawn989E8rand();
                    productLo=scratch16*scratch19;
                    __asm__ volatile("":"=l"(productLo):"0"(productLo):"memory");
                    value2&=2047;
                    value3=Spawn989E8D_8006E028;
                    value2-=1024;
                    value3+=16384;
                    Spawn989E8Stack(int,0x40)=value3;
                    value3=Spawn989E8Field(Spawn989E8D_80070328,int*,0x9C);
                    value4=Spawn989E8D_8006E024;
                    value3<<=1;
                    value4+=value3;
                    __asm__ volatile("":"=l"(productLo),"=r"(value2),"=r"(value4):"0"(productLo),"1"(value2),"2"(value4):"memory");
                    low9=productLo;
                    __asm__("":"=r"(low9):"0"(low9));
                    value3=low9>>12;
                    value4+=value3;
                    value3=Spawn989E8Stack(int,0x38);
                    value4-=value2;
                    Spawn989E8Stack(int,0x3C)=value4;
                    if(value3<=0)break;
                    if(value4<=0)break;
                    value2=Spawn989E8func_8001A310(&Spawn989E8Stack(int,0x38),0x60C0,2,0);
                    scratch16=value2;
                    if(reference){
                        value2=Spawn989E8rand();
                        value2&=8191;
                        value3=Spawn989E8D_8006E028;
                        value2-=2048;
                        goto rawHeightE;
                    }
                    value2=Spawn989E8D_8006E03E;
                    value3=value2&4095;
                    value2=value3<1024;
                    __asm__("":"=r"(value2),"=r"(value3):"0"(value2),"1"(value3));
                    if(value2){
                        value2=scratch19>>2;
                        goto angleHeightE;
                    }
                    value2=value3<3841;
                    __asm__("":"=r"(value2):"0"(value2));
                    if(value2){
                        value2=scratch19>>1;
                        goto baseHeightE;
                    }
                    value2=scratch19>>1;
                angleHeightE:
                    value3=Spawn989E8D_8006E028;
                    value2+=2048;
                rawHeightE:
                    value3+=value2;
                    Spawn989E8Stack(int,0x40)=value3;
                    goto heightDoneE;
                baseHeightE:
                    value2=Spawn989E8D_8006E028;
                    value2+=8192;
                    Spawn989E8Stack(int,0x40)=value2;
                heightDoneE:
                    if(Spawn989E8Stack(int,0x40)<scratch16+1024)break;
                    if(scratch16 && Spawn989E8D_80071920<=0)break;
                    record=Spawn989E8func_80056434(3);
                    value5=1;
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,2)=0;
                    Spawn989E8Field(record,unsigned char*,3)=value5;
                    if(scratch16==0){
                        value2=Spawn989E8Stack(int,0x40);
                        scratch16=value2-16384;
                        if(scratch16<1024)scratch16=1024;
                    }
                    else{
                        value2=Spawn989E8D_80071918;
                        value3=Spawn989E8D_8007191C;
                        value4=Spawn989E8D_80071920;
                        if(value2<0)value2=-value2;
                        if(value3<0)value3=-value3;
                        value2+=value3;
                        if(value2<value4)Spawn989E8Field(record,unsigned char*,2)=value5;
                    }
                    vector18=record+4;
                    value2=Spawn989E8rand();
                    Spawn989E8Stack(int,0x48)=value2&3;
                    value2=Spawn989E8rand();
                    Spawn989E8Stack(int,0x4C)=value2&3;
                    value2=Spawn989E8rand();
                    value2&=7;
                    value3=Spawn989E8Stack(int,0x40);
                    value2+=10;
                    value3-=scratch16;
                    value3>>=2;
                    value3/=value2;
                    value5=(int)&Spawn989E8Stack(int,0x38);
                    Spawn989E8Stack(int,0x50)=value2;
                    value4=(int)vector18;
                    Spawn989E8Field(record,unsigned short*,0x1C)=value3;
                    Spawn989E8Stack(int,0x40)=scratch16;
                    Spawn989E8func_8004F504((void*)value4,(void*)value5);
                    vector17=&Spawn989E8Stack(int,0x58);
                    value4=(int)vector17;
                    value5=(int)&Spawn989E8Stack(int,0x48);
                    Spawn989E8func_8004F1FC((void*)value4,(void*)value5,Spawn989E8Field(record,short*,0x1C));
                    vector16=&Spawn989E8Stack(int,0x68);
                    Spawn989E8func_8004F570(vector16,vector17);
                    Spawn989E8func_8004F5A8(vector18,vector18,vector16);
                    value2=Spawn989E8Field(record,unsigned short*,4);
                    value3=Spawn989E8Field(record,unsigned short*,6);
                    Spawn989E8Field(record,unsigned short*,24)=value2;
                    Spawn989E8Field(record,unsigned short*,26)=value3;
                    value2=Spawn989E8rand();
                    Spawn989E8Field(record,unsigned char*,30)=value2;
                    value2=Spawn989E8rand();
                    value2&=3;
                    value2+=1;
                    Spawn989E8Field(record,unsigned char*,31)=value2;
                    value2=Spawn989E8Stack(int,0x48);
                    value2=-value2;
                    Spawn989E8Field(record,unsigned short*,18)=value2;
                    value2=Spawn989E8Stack(int,0x4C);
                    value2=-value2;
                    Spawn989E8Field(record,unsigned short*,20)=value2;
                    value2=Spawn989E8Stack(int,0x50);
                    value2=-value2;
                    Spawn989E8Field(record,unsigned short*,22)=value2;
                    value2=Spawn989E8rand();
                    value2&=7;
                    value2+=20;
                    Spawn989E8Field(record,unsigned char*,10)=value2;
                    value2=Spawn989E8rand();
                    value2&=7;
                    value2+=12;
                    commonByte8=128;
                    commonByte9=128;
                    __asm__("":"=r"(commonByte8),"=r"(commonByte9),"=r"(value2):"0"(commonByte8),"1"(commonByte9),"2"(value2));
                    Spawn989E8Field(record,volatile unsigned char*,12)=commonByte8;
                    Spawn989E8Field(record,volatile unsigned char*,11)=value2;
                    value2=44;
                    Spawn989E8Field(record,volatile unsigned char*,13)=commonByte9;
                    Spawn989E8Field(record,volatile unsigned char*,14)=commonByte8;
                    Spawn989E8Field(record,volatile unsigned char*,15)=value2;
                    Spawn989E8Field(record,volatile unsigned char*,17)=0;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    break;
                }
            case 0x12:
                record=Spawn989E8func_80056434(4);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    __asm__("" : "=r"(destination),"=r"(source):"0"(destination),"1"(source):"$2");
                    tailByte=1;
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,2)=0;
                    Spawn989E8Field(record,unsigned char*,3)=tailByte;
                    Spawn989E8func_8004F58C(destination,source);
                }
                tailByte=Spawn989E8rand();
                tailByte&=6;
                __asm__("" : "=r"(tailByte):"0"(tailByte));
                tailByte+=14;
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                {
                    register int value3 __asm__("$3")=Spawn989E8PlayerE;
                    tailByte=32;
                    Spawn989E8Field(record,volatile unsigned char*,12)=tailByte;
                    Spawn989E8Field(record,volatile unsigned char*,13)=tailByte;
                    tailByte=64;
                    commonByte9=46;
                    Spawn989E8Field(record,volatile unsigned char*,14)=tailByte;
                    tailByte=2;
                    Spawn989E8Field(record,volatile unsigned char*,15)=commonByte9;
                    Spawn989E8Field(record,volatile unsigned char*,17)=tailByte;
                    Spawn989E8Field(record,volatile unsigned char*,16)=0;
                    __asm__ volatile(""::"i"(0x800993DC):"memory");
                    Spawn989E8Field(record,unsigned char*,11)=value3;
                }
                break;
            case 0x21:
                record = Spawn989E8func_80056434(2);
                tailByte=1;
                __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                Spawn989E8Field(record, unsigned char *, 2) = 0;
                Spawn989E8Field(record, unsigned char *, 3) = tailByte;
                if (modeSelector == 0) {
                    {
                        register void *destination __asm__("$4");
                        scratch16=(int)&Spawn989E8Stack(int,0x80);
                        destination=(void*)scratch16;
                        __asm__("" : "=r"(scratch16),"=r"(destination) : "0"(scratch16),"1"(destination) : "$17");
                        temp_s1 = Spawn989E8D_80070328 + 0x98;
                        Spawn989E8func_8004F178(destination,temp_s1);
                    }
                    Spawn989E8func_8004F110((void*)scratch16, 6);
                    Spawn989E8func_8004F178(&Spawn989E8Stack(int,0x70), temp_s1 - 0x98);
                    Spawn989E8Stack(int,0x78) -= 0x164;
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3")=Spawn989E8Stack(int,0x70);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0xFF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x80;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x70)=component;
                    }
                    {
                        register int random __asm__("$2")=Spawn989E8rand();
                        register int component __asm__("$3");
                        __asm__("" : "=r"(random) : "0"(random) : "$18");
                        scratch19=48;
                        component=Spawn989E8Stack(int,0x74);
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        random&=0xFF;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component+=0x80;
                        __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                        component-=random;
                        Spawn989E8Stack(int,0x74)=component;
                    }
                    goto setDestination;
                }
                else {
                    register int one __asm__("$8")=1;
                    __asm__("" : "=r"(one) : "0"(one));
                    if(modeSelector == (unsigned char*)one) {
                        {
                            register void *base4 __asm__("$4")=Spawn989E8D_80070328+0x30;
                            register void *arg5 __asm__("$5");
                            register void *arg6 __asm__("$6");
                            __asm__("" : "=r"(base4):"0"(base4):"$16","memory");
                            scratch16=(int)&Spawn989E8Stack(int,0x70);
                            arg5=(void*)scratch16;
                            arg6=arg5;
                            Spawn989E8Stack(int,0x70) = 0x164;
                            Spawn989E8Stack(int,0x74) = 0;
                            Spawn989E8Stack(int,0x78) = 0;
                            Spawn989E8func_8004ED6C(base4,arg5,arg6);
                        }
                        {
                            register void *arg4 __asm__("$4")=(void*)scratch16;
                            register void *arg5 __asm__("$5")=arg4;
                            register unsigned char *table9 __asm__("$9")=Spawn989E8D_80070328+0x30;
                            __asm__("" : "=r"(arg4),"=r"(arg5),"=r"(table9):"0"(arg4),"1"(arg5),"2"(table9):"memory");
                            Spawn989E8func_8004F194(arg4,arg5,table9-0x30);
                        }
                        scratch19 = 0x40;
                        Spawn989E8Stack(int,0x80) = -(Spawn989E8rand() & 7);
                        {
                            register int random __asm__("$2")=Spawn989E8rand();
                            register int component __asm__("$3");
                            register void *destination __asm__("$4")=Spawn989E8D_80070328+0x30;
                            register void *vector __asm__("$5")=&Spawn989E8Stack(int,0x80);
                            register int iteration8 __asm__("$8")=Spawn989E8Stack(int,0x128);
                            register int angle __asm__("$7");
                            register void *output __asm__("$6")=vector;
                            __asm__("" : "=r"(destination),"=r"(vector),"=r"(output) : "0"(destination),"1"(vector),"2"(output) : "memory");
                            __asm__("" : "=r"(iteration8):"0"(iteration8));
                            random&=15;
                            angle=iteration8<<6;
                            component=*(unsigned short*)(Spawn989E8D_80065920+angle);
                            __asm__("" : "=r"(random) : "0"(random) : "memory");
                            random-=8;
                            __asm__("" : "=r"(random) : "0"(random));
                            component=(component<<16)>>23;
                            component-=random;
                            Spawn989E8Stack(int,0x84)=component;
                            random=*(unsigned short*)(Spawn989E8D_800658A0+angle);
                            random=(random<<16)>>23;
                            Spawn989E8Stack(int,0x88)=random;
                            Spawn989E8func_8004ED6C(destination,vector,output);
                        }
                        var_a0 = record + 4;
                        goto finishMode;
                    }
                    else {
                        register int two __asm__("$9")=2;
                        __asm__("" : "=r"(two):"0"(two));
                        scratch16=5;
                        if(modeSelector == (unsigned char*)two) {
                            {
                                register int iteration8 __asm__("$8")=Spawn989E8Stack(int,0x128);
                                __asm__("" : "=r"(iteration8):"0"(iteration8):"$17","$16","$18","memory");
                                scratch17=iteration8<<5;
                                __asm__("" : "=r"(scratch17):"0"(scratch17):"$16","$18","memory");
                            }
                            scratch16 = 6;
                            scratch19 = 0x30;
                            goto updateSharedVector;
                        }
                        else {
                            {
                                register int iteration9 __asm__("$9")=Spawn989E8Stack(int,0x128);
                                register int offset __asm__("$2");
                                scratch19=64;
                                __asm__("" : "=r"(iteration9),"=r"(scratch19):"0"(iteration9),"1"(scratch19):"$2","memory");
                                offset=iteration9<<5;
                                __asm__("" : "=r"(offset) : "0"(offset));
                                scratch17=offset+16;
                            }
                        }
                    }
                }
            updateSharedVector:
                Spawn989E8func_8004F178(&Spawn989E8Stack(int,0x70),Spawn989E8D_80070328);
                {
                    register short *first __asm__("$5")=(short*)Spawn989E8D_80065920;
                    register unsigned char *second __asm__("$4");
                    register int value __asm__("$2");
                    register int other __asm__("$3");
                    second=(unsigned char*)(scratch17*2);
                    __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$2","$3","memory");
                    first=(short*)((int)second+(int)first);
                    value=*first;
                    other=Spawn989E8Stack(int,0x70);
                    value>>=scratch16;
                    other+=value;
                    value=(int)Spawn989E8D_800658A0;
                    second+=value;
                    value=Spawn989E8Stack(int,0x78);
                    Spawn989E8Stack(int,0x70)=other;
                    other=*(short*)second;
                    value-=356;
                    Spawn989E8Stack(int,0x78)=value;
                    value=Spawn989E8Stack(int,0x74);
                    other>>=scratch16;
                    value+=other;
                    Spawn989E8Stack(int,0x74)=value;
                    __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$2","$3","memory");
                    value=*first;
                    other=scratch16+1;
                    value>>=other;
                    Spawn989E8Stack(int,0x80)=value;
                    value=*(short*)second;
                    Spawn989E8Stack(int,0x88)=0;
                    value>>=other;
                    Spawn989E8Stack(int,0x84)=value;
                }
            setDestination:
                var_a0=record+4;
            finishMode:
                Spawn989E8func_8004F504(var_a0, &Spawn989E8Stack(int,0x70));
                Spawn989E8func_8004F504(record + 0x18, &Spawn989E8Stack(int,0x80));
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x10;
                tailByte=Spawn989E8rand();
                commonByte8=46;
                __asm__("" : "=r"(tailByte),"=r"(commonByte8):"0"(tailByte),"1"(commonByte8):"memory");
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,volatile unsigned char*,12)=scratch19;
                Spawn989E8Field(record,volatile unsigned char*,13)=scratch19;
                Spawn989E8Field(record,volatile unsigned char*,14)=scratch19;
                __asm__ volatile("" ::: "memory");
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            case 0x27:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    register int one __asm__("$2");
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$9");
                    one=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 3) = one;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                {
                    register int value4 __asm__("$4")=10;
                    register int value5 __asm__("$5")=24;
                    commonByte9=128;
                    commonByte8=128;
                    __asm__("" : "=r"(value4),"=r"(value5),"=r"(commonByte9),"=r"(commonByte8):"0"(value4),"1"(value5),"2"(commonByte9),"3"(commonByte8):"memory");
                    Spawn989E8Field(record,volatile unsigned char*,12)=commonByte9;
                    Spawn989E8Field(record,volatile unsigned char*,13)=commonByte8;
                    commonByte8=46;
                    tailByte=4;
                    Spawn989E8Field(record,volatile unsigned char*,11)=0;
                    Spawn989E8Field(record,volatile unsigned char*,14)=commonByte9;
                    Spawn989E8Field(record,volatile unsigned char*,15)=commonByte8;
                    Spawn989E8Field(record,volatile unsigned char*,17)=tailByte;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    tailByte=Spawn989E8func_8003636C(value4,value5);
                }
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                tailByte=Spawn989E8func_8003636C(40,70);
                Spawn989E8Field(record,unsigned char*,2)=tailByte;
                break;
            case 0x29:
                {
                    register void *vector16 __asm__("$16");
                    register void *vector17 __asm__("$17");
                    register unsigned int stackBase29 __asm__("$29");
                    register int angle21 __asm__("$21");
                    register int radius19 __asm__("$18");
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int index4 __asm__("$4");
                    register int low8 __asm__("$8");
                    register int low9 __asm__("$9");
                    register void *destination4 __asm__("$4");
                    register void *source5 __asm__("$5");
                    __asm__ volatile("" ::: "$16","memory");
                    vector16=&Spawn989E8Stack(int,0x90);
                    __asm__ volatile("" : "=r"(vector16):"0"(vector16):"memory");
                    Spawn989E8func_8004F178(vector16,reference);
                    value2=Spawn989E8rand();
                    value3=Spawn989E8Stack(int,0x90);
                    value2&=255;
                    value3+=128;
                    value3-=value2;
                    Spawn989E8Stack(int,0x90)=value3;
                    value2=Spawn989E8rand();
                    value3=Spawn989E8Stack(int,0x94);
                    value2&=255;
                    value3+=128;
                    value3-=value2;
                    Spawn989E8Stack(int,0x94)=value3;
                    value2=Spawn989E8rand();
                    angle21=value2&255;
                    value2=Spawn989E8rand();
                    {
                        register void *arg4 __asm__("$4")=&Spawn989E8Stack(int,0xA0);
                        register void *arg5 __asm__("$5")=vector16;
                        __asm__("" : "=r"(arg4),"=r"(arg5),"=r"(value2):"0"(arg4),"1"(arg5),"2"(value2));
                        value2&=1023;
                        radius19=value2+512;
                        Spawn989E8func_8004F178(arg4,arg5);
                    }
                    destination4=&Spawn989E8Stack(int,0xB0);
                    if(modeSelector!=0) source5=modeSelector;
                    else {
                        source5=Spawn989E8D_80070328+0x8C;
                        __asm__ volatile("" : "=r"(source5):"0"(source5):"memory");
                    }
                    Spawn989E8func_8004F178(destination4,source5);
                    __asm__ volatile("" ::: "$16","memory");
                    vector16=&Spawn989E8Stack(int,0xB0);
                    __asm__ volatile("" : "=r"(vector16):"0"(vector16):"memory");
                    Spawn989E8func_8004F110(vector16,1);
                    {
                        register int count9 __asm__("$9")=Spawn989E8Stack(int,0x120);
                        register int one8 __asm__("$8")=1;
                        __asm__("" : "=r"(count9),"=r"(one8):"0"(count9),"1"(one8));
                        __asm__ volatile("" ::: "$17","memory");
                        __asm__ volatile("":"=r"(stackBase29):"0"((unsigned int)&frame-0x18):"memory");
                        vector17=(void*)(stackBase29+0xA0);
                        if(count9==one8){
                            Spawn989E8func_8004F1FC(vector16,vector16,3);
                            __asm__ volatile("" : "=r"(vector17):"0"(vector17):"memory");
                            __asm__ volatile("" ::: "$17","memory");
                            __asm__ volatile("":"=r"(stackBase29):"0"((unsigned int)&frame-0x18):"memory");
                            vector17=(void*)(stackBase29+0xA0);
                            __asm__ volatile("" : "=r"(vector17):"0"(vector17):"memory");
                        }
                    }
                    Spawn989E8Stack(int,0xB8)=0;
                    Spawn989E8func_8004F194(vector17,vector17,vector16);
                    index4=angle21<<1;
                    value2=Spawn989E8Field(Spawn989E8D_80065920+index4,short*,0);
                    __asm__ volatile("" : "=l"(low9):"0"(value2*radius19):"memory");
                    value2=Spawn989E8Stack(int,0xA0);
                    value3=low9>>12;
                    value2+=value3;
                    Spawn989E8Stack(int,0xA0)=value2;
                    value2=Spawn989E8Field(Spawn989E8D_800658A0+index4,short*,0);
                    {
                        int productLo=value2*radius19;
                        __asm__ volatile("" : "=l"(productLo):"0"(productLo):"memory");
                        source5=(void*)1024;
                        value2=Spawn989E8Stack(int,0xA8);
                        __asm__("" : "=r"(source5),"=r"(value2):"0"(source5),"1"(value2):"$4");
                        destination4=vector17;
                        __asm__("" : "=r"(source5),"=r"(value2),"=r"(destination4):"0"(source5),"1"(value2),"2"(destination4));
                        value2+=512;
                        Spawn989E8Stack(int,0xA8)=value2;
                        value2=Spawn989E8Stack(int,0xA4);
                        __asm__ volatile("" : "=l"(productLo),"=r"(value2):"0"(productLo),"1"(value2):"memory");
                        low8=productLo;
                        __asm__("" : "=r"(low8):"0"(low8));
                        value3=low8>>12;
                        value2+=value3;
                        Spawn989E8Stack(int,0xA4)=value2;
                        value2=Spawn989E8func_8001A358(destination4,(int)source5);
                    }
                    Spawn989E8Stack(int,0xA8)=value2;
                    if(value2==0)break;
                    record=Spawn989E8func_80056434(3);
                    value2=1;
                    __asm__("" : "=r"(value2):"0"(value2):"memory");
                    Spawn989E8Field(record,volatile unsigned char*,3)=value2;
                    value2=10;
                    __asm__("" : "=r"(value2):"0"(value2):"memory");
                    Spawn989E8Field(record,volatile unsigned char*,10)=value2;
                    value2=6;
                    __asm__("" : "=r"(value2):"0"(value2):"$4","memory");
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,2)=0;
                    destination4=record+4;
                    __asm__("" : "=r"(destination4):"0"(destination4));
                    Spawn989E8Field(record,unsigned char*,11)=value2;
                    value2=Spawn989E8D_8006D07C;
                    __asm__ volatile("" : "=r"(value2):"0"(value2):"$16","memory");
                    __asm__ volatile("" ::: "$16","memory");
                    vector16=&Spawn989E8Stack(int,0x90);
                    __asm__ volatile("" : "=r"(vector16):"0"(vector16):"memory");
                    value2>>=4;
                    Spawn989E8Field(record,unsigned char*,12)=value2;
                    value2=Spawn989E8D_8006D080;
                    __asm__("" : "=r"(value2):"0"(value2):"$5","memory");
                    source5=vector16;
                    __asm__("" : "=r"(value2),"=r"(source5):"0"(value2),"1"(source5));
                    value2>>=4;
                    Spawn989E8Field(record,unsigned char*,13)=value2;
                    value3=Spawn989E8D_8006D084;
                    __asm__ volatile("" : "=r"(value3):"0"(value3):"$9","$2","memory");
                    commonByte9=46;
                    value2=2;
                    __asm__("" : "=r"(value3),"=r"(commonByte9),"=r"(value2):"0"(value3),"1"(commonByte9),"2"(value2));
                    Spawn989E8Field(record,unsigned char*,15)=commonByte9;
                    Spawn989E8Field(record,unsigned char*,17)=value2;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    __asm__ volatile("" : "=r"(value3):"0"(value3):"memory");
                    value3>>=4;
                    Spawn989E8Field(record,unsigned char*,14)=value3;
                    Spawn989E8func_8004F504(destination4,source5);
                    Spawn989E8func_8004F504(record+18,vector16);
                    Spawn989E8func_8004F504(record+24,vector17);
                    scratch16=Spawn989E8rand();
                    value2=Spawn989E8rand();
                    scratch16&=14;
                    value2=(value2&6)+20;
                    scratch16+=value2;
                    Spawn989E8Field(record,unsigned short*,22)=scratch16;
                    Spawn989E8Field(record,unsigned char*,30)=0;
                    while(scratch16>0 || Spawn989E8Stack(int,0x98)>Spawn989E8Stack(int,0xA8)){
                        Spawn989E8Stack(int,0x98)+=scratch16<<2;
                        Spawn989E8Field(record,unsigned char*,30)+=1;
                        scratch16-=2;
                        __asm__ volatile("" : "=r"(scratch16):"0"(scratch16):"memory");
                    }
                    value2=Spawn989E8rand();
                    Spawn989E8Field(record,unsigned char*,29)=value2;
                    Spawn989E8Field(record,unsigned char*,31)=Spawn989E8D_80071934;
                }
                break;
            case 0x2A:
                record=Spawn989E8func_80056434(4);
                {
                    register void *arg4 __asm__("$4")=record+4;
                    register void *arg5 __asm__("$5")=reference;
                    __asm__("" : "=r"(arg4),"=r"(arg5):"0"(arg4),"1"(arg5):"$2");
                    tailByte=1;
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,2)=0;
                    Spawn989E8Field(record,unsigned char*,3)=tailByte;
                    Spawn989E8func_8004F504(arg4,arg5);
                }
                tailByte=Spawn989E8Field(reference,int*,0);
                Spawn989E8Field(record,int*,24)=tailByte;
                tailByte=Spawn989E8Field(reference,int*,4);
                Spawn989E8Field(record,int*,28)=tailByte;
                tailByte=Spawn989E8Field(modeSelector,int*,0);
                Spawn989E8Field(record,unsigned short*,18)=tailByte;
                tailByte=Spawn989E8Field(modeSelector,int*,4);
                Spawn989E8Field(record,unsigned short*,20)=tailByte;
                tailByte=Spawn989E8rand();
                tailByte=(tailByte&7)+3;
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                tailByte=108;
                __asm__("" : "=r"(tailByte):"0"(tailByte):"$3","$8","memory");
                {
                    register int color3 __asm__("$3")=Spawn989E8PlayerE;
                    __asm__("" : "=r"(color3),"=r"(tailByte):"0"(color3),"1"(tailByte):"$8","memory");
                    commonByte8=46;
                    Spawn989E8Field(record,unsigned char*,12)=tailByte;
                    Spawn989E8Field(record,unsigned char*,13)=tailByte;
                    Spawn989E8Field(record,unsigned char*,14)=tailByte;
                    Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                    Spawn989E8Field(record,unsigned char*,17)=0;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    __asm__ volatile("" : "=r"(color3):"0"(color3):"memory");
                    color3+=32;
                    Spawn989E8Field(record,unsigned char*,11)=color3;
                }
                break;
                {
                    register int commonByte3 __asm__("$3");
                case 0x2B:
                    record=Spawn989E8func_80056434(4);
                    tailByte=1;
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,2)=0;
                    Spawn989E8Field(record,unsigned char*,3)=tailByte;
                    if(modeSelector==0){
                        Spawn989E8func_8004F58C(record+4,reference);
                        tailByte=Spawn989E8rand();
                        tailByte&=7;
                        tailByte+=2;
                        Spawn989E8Field(record,unsigned char*,10)=tailByte;
                        commonByte3=96;
                    }
                    else{
                        Spawn989E8func_8004F504(record+4,reference);
                        {
                            register int two __asm__("$9")=2;
                            __asm__("" : "=r"(two):"0"(two));
                            if(modeSelector==(unsigned char*)two){
                                {
                                    register int random __asm__("$2")=Spawn989E8rand();
                                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,4);
                                    __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                                    random&=127;
                                    component+=32;
                                    component-=random;
                                    Spawn989E8Field(record,unsigned short*,4)=component;
                                }
                                {
                                    register int random __asm__("$2")=Spawn989E8rand();
                                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,6);
                                    __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                                    random&=127;
                                    component+=32;
                                    component-=random;
                                    Spawn989E8Field(record,unsigned short*,6)=component;
                                }
                            }
                        }
                        tailByte=Spawn989E8rand();
                        tailByte&=7;
                        __asm__("" : "=r"(tailByte):"0"(tailByte));
                        tailByte+=16;
                        Spawn989E8Field(record,unsigned char*,10)=tailByte;
                        commonByte3=64;
                    }
                    {
                        register int sourceByte __asm__("$2")=Spawn989E8Field(Spawn989E8D_80070328,unsigned char*,14);
                        __asm__("" : "=r"(sourceByte),"=r"(commonByte3):"0"(sourceByte),"1"(commonByte3):"memory");
                        Spawn989E8Field(record,unsigned char*,12)=commonByte3;
                        Spawn989E8Field(record,unsigned char*,13)=commonByte3;
                        Spawn989E8Field(record,unsigned char*,14)=commonByte3;
                        commonByte8=46;
                        __asm__("" : "=r"(sourceByte),"=r"(commonByte8):"0"(sourceByte),"1"(commonByte8):"memory");
                        Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                        Spawn989E8Field(record,unsigned char*,17)=0;
                        Spawn989E8Field(record,unsigned char*,16)=0;
                        Spawn989E8Field(record,unsigned short*,24)=(int)modeSelector;
                        Spawn989E8Field(record,unsigned char*,11)=sourceByte;
                    }
                    break;
                }
            case 0x2C:
                {
                    register void *vector17 __asm__("$17");
                    register unsigned char *player16 __asm__("$16");
                    register void *copy16 __asm__("$16");
                    register void *arg4 __asm__("$4")=Spawn989E8D_80070328+0x30;
                    register void *arg5 __asm__("$5")=reference;
                    register void *arg6 __asm__("$6");
                    register int value2 __asm__("$2");
                    __asm__("" : "=r"(arg4),"=r"(arg5):"0"(arg4),"1"(arg5):"$17","memory");
                    vector17=&Spawn989E8Stack(int,0xC0);
                    __asm__("" : "=r"(arg4),"=r"(arg5),"=r"(vector17):"0"(arg4),"1"(arg5),"2"(vector17));
                    Spawn989E8func_8004ED6C(arg4,arg5,vector17);
                    arg4=vector17;
                    arg5=vector17;
                    {
                        register unsigned char *table9 __asm__("$9")=Spawn989E8D_80070328+0x30;
                        __asm__("" : "=r"(table9):"0"(table9):"memory");
                        player16=table9-0x30;
                    }
                    Spawn989E8func_8004F194(arg4,arg5,player16);
                    if(Spawn989E8func_8001830C(player16,vector17,2,0,0)!=0)break;
                    record=Spawn989E8func_80056434(2);
                    arg4=record+4;
                    arg5=vector17;
                    value2=1;
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,3)=value2;
                    Spawn989E8func_8004F504(arg4,arg5);
                    Spawn989E8func_8004F504(record+24,vector17);
                    value2=Spawn989E8Field(Spawn989E8D_80070328,int*,0x8C);
                    value2>>=9;
                    Spawn989E8Field(record,unsigned short*,18)=value2;
                    value2=Spawn989E8Field(Spawn989E8D_80070328,int*,0x90);
                    value2>>=9;
                    Spawn989E8Field(record,unsigned short*,20)=value2;
                    value2=Spawn989E8rand();
                    value2&=3;
                    __asm__("" : "=r"(value2):"0"(value2));
                    value2+=4;
                    commonByte8=128;
                    commonByte9=128;
                    __asm__("" : "=r"(value2),"=r"(commonByte8),"=r"(commonByte9):"0"(value2),"1"(commonByte8),"2"(commonByte9):"memory");
                    Spawn989E8Field(record,volatile unsigned char*,12)=commonByte8;
                    Spawn989E8Field(record,volatile unsigned char*,13)=commonByte9;
                    commonByte9=46;
                    Spawn989E8Field(record,volatile unsigned short*,22)=value2;
                    value2=2;
                    Spawn989E8Field(record,volatile unsigned char*,11)=0;
                    Spawn989E8Field(record,volatile unsigned char*,14)=commonByte8;
                    Spawn989E8Field(record,volatile unsigned char*,15)=commonByte9;
                    Spawn989E8Field(record,volatile unsigned char*,17)=value2;
                    Spawn989E8Field(record,unsigned char*,16)=0;
                    value2=Spawn989E8rand();
                    value2&=7;
                    __asm__("" : "=r"(value2):"0"(value2));
                    value2+=6;
                    Spawn989E8Field(record,unsigned char*,10)=value2;
                    value2=Spawn989E8rand();
                    Spawn989E8Field(record,unsigned char*,28)=value2;
                    value2=Spawn989E8rand();
                    value2&=31;
                    {
                        register int value3 __asm__("$3")=16;
                        value3-=value2;
                        Spawn989E8Field(record,unsigned char*,29)=value3;
                    }
                    value2=Spawn989E8rand();
                    copy16=&Spawn989E8Stack(int,0xD0);
                    arg4=copy16;
                    arg5=vector17;
                    __asm__("" : "=r"(copy16),"=r"(arg4),"=r"(arg5),"=r"(value2):"0"(copy16),"1"(arg4),"2"(arg5),"3"(value2):"memory");
                    value2&=31;
                    __asm__("" : "=r"(value2):"0"(value2));
                    value2+=64;
                    Spawn989E8Field(record,unsigned char*,2)=value2;
                    Spawn989E8func_8004F178(arg4,arg5);
                    arg4=vector17;
                    arg5=copy16;
                    value2=Spawn989E8Stack(int,0xD8);
                    value2+=3072;
                    Spawn989E8Stack(int,0xD8)=value2;
                    value2=Spawn989E8func_8001830C(arg4,arg5,2,0,0);
                    if(value2){
                        value2=Spawn989E8D_80071908;
                        value2>>=2;
                        Spawn989E8Field(record,unsigned short*,30)=value2;
                        value2=Spawn989E8D_80071934;
                        if(value2==0)break;
                        value2=3;
                        Spawn989E8Field(record,unsigned char*,17)=value2;
                        break;
                    }
                    value2=Spawn989E8Stack(int,0xD8);
                    value2>>=2;
                    Spawn989E8Field(record,unsigned short*,30)=value2;
                }
                break;
            case 0x2E:
                record=Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    tailByte=1;
                    __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte):"0"(destination),"1"(source),"2"(tailByte):"memory");
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,2)=0;
                    Spawn989E8Field(record,unsigned char*,3)=tailByte;
                    Spawn989E8func_8004F504(destination,source);
                }
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,4);
                    __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                    random&=127;
                    component+=64;
                    component-=random;
                    Spawn989E8Field(record,unsigned short*,4)=component;
                }
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,6);
                    __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                    random&=127;
                    component+=64;
                    component-=random;
                    Spawn989E8Field(record,unsigned short*,6)=component;
                }
                if(modeSelector!=0){
                    tailByte=Spawn989E8rand();
                    tailByte&=15;
                    __asm__("" : "=r"(tailByte):"0"(tailByte));
                    tailByte=(int)modeSelector+tailByte;
                }
                else{
                    tailByte=Spawn989E8rand();
                    tailByte&=15;
                    __asm__("" : "=r"(tailByte):"0"(tailByte));
                    tailByte+=20;
                }
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                tailByte=Spawn989E8rand();
                commonByte8=128;
                commonByte9=128;
                __asm__("" : "=r"(commonByte8),"=r"(commonByte9),"=r"(tailByte):"0"(commonByte8),"1"(commonByte9),"2"(tailByte));
                Spawn989E8Field(record,volatile unsigned char*,12)=commonByte8;
                Spawn989E8Field(record,volatile unsigned char*,13)=commonByte9;
                commonByte9=46;
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                tailByte=2;
                __asm__ volatile("" : "=r"(tailByte),"=r"(commonByte9),"=r"(commonByte8):"0"(tailByte),"1"(commonByte9),"2"(commonByte8):"$4","memory");
                Spawn989E8Field(record,unsigned char*,14)=commonByte8;
                goto initializeF9;
            case 0x37:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                    tailByte=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = tailByte;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                tailByte=64;
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                tailByte=Spawn989E8rand();
                commonByte8=46;
                __asm__ volatile("" : "=r"(commonByte8),"=r"(tailByte):"0"(commonByte8),"1"(tailByte):"$3","memory");
                Spawn989E8Field(record,unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,unsigned char*,12)=byte255;
                Spawn989E8Field(record,unsigned char*,13)=byte255;
                __asm__ volatile("" : "=r"(commonByte8),"=r"(tailByte):"0"(commonByte8),"1"(tailByte):"$4","memory");
                Spawn989E8Field(record,unsigned char*,14)=0;
                __asm__ volatile(""::"i"(0x80099D3C):"memory");
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            case 0x38:
                record=Spawn989E8func_80056434(2);
                tailByte=1;
                __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                Spawn989E8Field(record,unsigned char*,2)=0;
                Spawn989E8Field(record,unsigned char*,3)=tailByte;
                Spawn989E8Field(record,unsigned short*,4)=Spawn989E8Field(reference,unsigned short*,4);
                Spawn989E8Field(record,unsigned short*,6)=Spawn989E8Field(reference,unsigned short*,6);
                Spawn989E8Field(record,unsigned short*,8)=Spawn989E8Field(reference,unsigned short*,8);
                Spawn989E8Field(record,int*,24)=Spawn989E8Field(reference,int*,24);
                Spawn989E8Field(record,int*,28)=Spawn989E8Field(reference,int*,28);
                tailByte=Spawn989E8Field(reference,unsigned char*,10);
                __asm__("" : "=r"(tailByte) : "0"(tailByte));
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                __asm__ volatile("" : : : "memory");
                {
                    register unsigned int sourceByte __asm__("$2")=Spawn989E8Field(reference,unsigned char*,11);
                    __asm__("" : "=r"(sourceByte),"=r"(tailByte) : "0"(sourceByte),"1"(tailByte) : "memory");
                    commonByte9=46;
                    Spawn989E8Field(record,volatile unsigned char*,12)=0;
                    Spawn989E8Field(record,volatile unsigned char*,13)=0;
                    Spawn989E8Field(record,volatile unsigned char*,14)=0;
                    Spawn989E8Field(record,volatile unsigned char*,15)=commonByte9;
                    Spawn989E8Field(record,volatile unsigned char*,17)=0;
                    Spawn989E8Field(record,volatile unsigned char*,16)=0;
                    Spawn989E8Field(record,unsigned char*,11)=sourceByte;
                }
                break;
            case 0x39:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    register int one __asm__("$2");
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$8");
                    one=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = one;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x18;
                tailByte=Spawn989E8rand();
                commonByte8=46;
                __asm__("":"=r"(tailByte),"=r"(commonByte8):"0"(tailByte),"1"(commonByte8));
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,volatile unsigned char*,12)=byte255;
                Spawn989E8Field(record,volatile unsigned char*,13)=byte255;
                Spawn989E8Field(record,volatile unsigned char*,14)=0;
                __asm__ volatile(""::"i"(0x80099E2C):"memory");
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            case 0x3A:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    register int one __asm__("$2");
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$8");
                    one=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = one;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                Spawn989E8Field(record, short *, 0x1E) = 0;
                Spawn989E8Field(record, unsigned char *, 0xA) = 0x18;
                tailByte=Spawn989E8rand();
                commonByte9=128;
                commonByte8=46;
                __asm__("":"=r"(tailByte),"=r"(commonByte8),"=r"(commonByte9):"0"(tailByte),"1"(commonByte8),"2"(commonByte9));
                Spawn989E8Field(record,volatile unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,volatile unsigned char*,12)=commonByte9;
                Spawn989E8Field(record,volatile unsigned char*,13)=byte255;
                Spawn989E8Field(record,volatile unsigned char*,14)=0;
                __asm__ volatile(""::"i"(0x80099E94):"memory");
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            case 0x3B:
                record = Spawn989E8func_80056434(5);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    register int flags __asm__("$3");
                    register int value __asm__("$2");
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$3","$2","memory");
                    flags=Spawn989E8Field(record,unsigned char*,1);
                    __asm__ __volatile__("" ::: "$2","memory");
                    value=1;
                    __asm__("" : "=r"(value) : "0"(value) : "memory");
                    Spawn989E8Field(record,unsigned char*,3)=value;
                    value=16;
                    Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                    Spawn989E8Field(record,unsigned char*,17)=value;
                    flags|=16;
                    Spawn989E8Field(record,unsigned char*,1)=flags;
                    Spawn989E8func_8004F504(destination,source);
                }
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,4);
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    random&=31;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component+=16;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component-=random;
                    Spawn989E8Field(record,unsigned short*,4)=component;
                }
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,6);
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    random&=15;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component+=8;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component-=random;
                    Spawn989E8Field(record,unsigned short*,6)=component;
                }
                if(modeSelector==0) {
                    __asm__ __volatile__("" ::: "$2");
                    var_v0=0x2E0080C0;
                }
                else {
                    __asm__ __volatile__("" ::: "$2");
                    var_v0=0x2E00C000;
                }
                __asm__("" : "=r"(var_v0) : "0"(var_v0));
                Spawn989E8Field(record,int*,12)=var_v0;
                Spawn989E8Field(record, unsigned char *, 0xA) = (unsigned char) ((Spawn989E8rand() & 0xF) + 0x14);
                Spawn989E8Field(record, unsigned char *, 0xB) = Spawn989E8rand();
                Spawn989E8Field(record, unsigned char *, 0x10) = 0;
                Spawn989E8Field(record, short *, 0x18) = (short) ((Spawn989E8rand() & 7) - 4);
                Spawn989E8Field(record, short *, 0x1A) = (short) (-2 - (Spawn989E8rand() & 7));
                Spawn989E8Field(record, short *, 0x1C) = (short) ((Spawn989E8rand() & 0xF) - 8);
                break;
            case 0x3C:
                record = Spawn989E8func_80056434(2);
                {
                    register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                    __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                    tailByte=1;
                    __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = 0;
                    Spawn989E8Field(record, unsigned char *, 3) = tailByte;
                    Spawn989E8func_8004F504(destination, source);
                }
                Spawn989E8func_8004F504(record + 0x18, modeSelector);
                {
                    register int value __asm__("$3")=Spawn989E8Field(modeSelector,int*,8);
                    tailByte=value-1;
                    __asm__("" : "=r"(tailByte),"=r"(value):"0"(tailByte),"1"(value));
                    if((unsigned)tailByte<7){
                        tailByte=value<<5;
                        Spawn989E8Field(record,unsigned char*,2)=tailByte;
                        Spawn989E8Field(record,unsigned short*,28)=0;
                        Spawn989E8Field(record,unsigned char*,14)=byte255;
                    }
                    else Spawn989E8Field(record,unsigned char*,14)=0;
                }
                tailByte=24;
                Spawn989E8Field(record,unsigned short*,30)=0;
                Spawn989E8Field(record,unsigned char*,10)=tailByte;
                tailByte=Spawn989E8rand();
                commonByte9=46;
                __asm__("" : "=r"(tailByte),"=r"(commonByte9):"0"(tailByte),"1"(commonByte9):"memory");
                Spawn989E8Field(record,unsigned char*,11)=tailByte;
                tailByte=4;
                Spawn989E8Field(record,unsigned char*,12)=byte255;
                Spawn989E8Field(record,unsigned char*,13)=byte255;
            initializeF9:
                Spawn989E8Field(record,unsigned char*,15)=commonByte9;
            initializeTrailingBytes:
                __asm__ volatile("" : "=r"(tailByte):"0"(tailByte):"$3","memory");
                Spawn989E8Field(record,unsigned char*,17)=tailByte;
                Spawn989E8Field(record,unsigned char*,16)=0;
                break;
            case 0x42:
                record = Spawn989E8func_80056434(0);
                Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                Spawn989E8Field(record, unsigned char *, 2) = (unsigned char) (Spawn989E8rand() & 0xF);
                Spawn989E8Field(record, unsigned char *, 3) = 1;
                Spawn989E8Field(record, short *, 4) = (short) ((((int) Spawn989E8Field(reference, int *, 0) >> 2) + (Spawn989E8rand() & 0xF)) - 8);
                Spawn989E8Field(record, short *, 6) = (short) ((((int) Spawn989E8Field(reference, int *, 4) >> 2) + (Spawn989E8rand() & 0xF)) - 8);
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(reference,int*,8);
                    __asm__("" : "=r"(random) : "0"(random) : "memory");
                    random&=15;
                    Spawn989E8Field(record,short*,16)=0;
                    Spawn989E8Field(record,short*,18)=0;
                    Spawn989E8Field(record,short*,20)=0;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component) : "memory");
                    component>>=2;
                    component+=random;
                    component-=8;
                    Spawn989E8Field(record,short*,8)=component;
                }
                {
                    register int observed __asm__("$3")=Spawn989E8D_8006E344;
                    register int expected __asm__("$2");
                    __asm__ __volatile__("" ::: "$2","memory");
                    expected=4;
                    __asm__("" : "=r"(observed),"=r"(expected) : "0"(observed),"1"(expected));
                    if(observed==expected)var_v0_4=100;
                    else var_v0_4=2;
                }
                {
                    register int one __asm__("$8")=1;
                    __asm__("" : "=r"(one),"=r"(var_v0_4) : "0"(one),"1"(var_v0_4));
                    Spawn989E8Field(record,unsigned char*,10)=var_v0_4;
                    if(modeSelector==(unsigned char*)one)goto forceColor;
                    if(modeSelector!=0)goto selectColor;
                    if(Spawn989E8Field(Spawn989E8D_80070328,int*,0x280)<3)goto selectColor;
                forceColor:
                    __asm__ __volatile__("" ::: "$2");
                    goto colorCaseOne;
                    selectColor:;
                }
                temp_v1_2 = Spawn989E8rand() & 7;
                switch (temp_v1_2) {
                case 0:
                    Spawn989E8Field(record, unsigned char *, 0xC) = byte255;
                    Spawn989E8Field(record, unsigned char *, 0xD) = 0;
                    Spawn989E8Field(record, unsigned char *, 0xE) = 0;
                    break;
                case 1:
                colorCaseOne:
                    Spawn989E8Field(record,unsigned char*,12)=byte255;
                    goto storeSecondColor;
                case 2:
                    Spawn989E8Field(record,unsigned char*,12)=0;
                storeSecondColor:
                    Spawn989E8Field(record,unsigned char*,13)=byte255;
                    Spawn989E8Field(record,unsigned char*,14)=0;
                    break;
                case 3:
                    Spawn989E8Field(record, unsigned char *, 0xC) = 0;
                    Spawn989E8Field(record, unsigned char *, 0xD) = byte255;
                    goto storeThirdColor;
                case 4:
                    Spawn989E8Field(record, unsigned char *, 0xC) = 0;
                    Spawn989E8Field(record, unsigned char *, 0xD) = 0;
                    goto storeThirdColor;
                case 5:
                    Spawn989E8Field(record, unsigned char *, 0xC) = byte255;
                    Spawn989E8Field(record, unsigned char *, 0xD) = 0;
                    goto storeThirdColor;
                case 6:
                    {
                        register int byte128 __asm__("$9")=128;
                        __asm__("" : "=r"(byte128) : "0"(byte128));
                        Spawn989E8Field(record,unsigned char*,12)=byte255;
                        Spawn989E8Field(record,unsigned char*,13)=byte128;
                    }
                    Spawn989E8Field(record, unsigned char *, 0xE) = 0;
                    break;
                case 7:
                    {
                        register int byte128 __asm__("$8")=128;
                        __asm__("" : "=r"(byte128) : "0"(byte128));
                        Spawn989E8Field(record,unsigned char*,12)=0;
                        Spawn989E8Field(record,unsigned char*,13)=byte128;
                    }
                storeThirdColor:
                    Spawn989E8Field(record,unsigned char*,14)=byte255;
                    break;
                }
                Spawn989E8Field(record, unsigned char *, 0xF) = 0x40;
                break;
            case 0x46:
                record = Spawn989E8func_80056434(1);
                Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                Spawn989E8Field(record, unsigned char *, 2) = (unsigned char) (Spawn989E8rand() & 0xF);
                Spawn989E8Field(record, unsigned char *, 3) = 1;
                Spawn989E8Stack(unsigned char,0xF0) = 0;
                Spawn989E8Stack(unsigned char,0xF1) = Spawn989E8rand();
                Spawn989E8Stack(unsigned char,0xF2) = Spawn989E8rand();
                Spawn989E8func_8004EA90(&Spawn989E8Stack(unsigned char,0xF0), &Spawn989E8Stack(int,0xF8), 0);
                Spawn989E8Stack(int,0xE0) = modeSelector;
                Spawn989E8Stack(int,0xE4) = 0;
                Spawn989E8Stack(int,0xE8) = 0;
                Spawn989E8func_8004ED6C(&Spawn989E8Stack(int,0xF8), (unsigned char *) &Spawn989E8Stack(int,0xE0), (unsigned char *) &Spawn989E8Stack(int,0xE0));
                Spawn989E8Field(record, unsigned short *, 4) = (unsigned short) ((int) Spawn989E8Field(reference, int *, 0) >> 2);
                Spawn989E8Field(record, unsigned short *, 6) = (unsigned short) ((int) Spawn989E8Field(reference, int *, 4) >> 2);
                Spawn989E8Field(record, unsigned short *, 8) = (unsigned short) ((int) Spawn989E8Field(reference, int *, 8) >> 2);
                {
                    register int value __asm__("$2")=Spawn989E8Stack(int,0xE0);
                    register int other __asm__("$3")=Spawn989E8Field(record,unsigned short*,4);
                    register int byte128 __asm__("$9");
                    value<<=1;
                    other+=value;
                    __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                    Spawn989E8Field(record,short*,10)=other;
                    __asm__("" ::: "memory");
                    value=Spawn989E8Stack(int,0xE4);
                    other=Spawn989E8Field(record,unsigned short*,6);
                    value<<=1;
                    other+=value;
                    __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                    Spawn989E8Field(record,short*,12)=other;
                    __asm__("" ::: "$2","memory");
                    other=Spawn989E8Stack(int,0xE8);
                    value=2;
                    Spawn989E8Field(record,unsigned char*,23)=value;
                    value=224;
                    Spawn989E8Field(record,unsigned char*,16)=value;
                    value=192;
                    Spawn989E8Field(record,unsigned char*,17)=value;
                    value=80;
                    Spawn989E8Field(record,unsigned char*,19)=value;
                    __asm__("" : "=r"(other) : "0"(other) : "$2","memory");
                    value=Spawn989E8Field(record,unsigned short*,8);
                    __asm__ __volatile__("" ::: "$8","memory");
                    byte128=128;
                    __asm__("" : "=r"(byte128) : "0"(byte128));
                    Spawn989E8Field(record,unsigned char*,18)=0;
                    Spawn989E8Field(record,unsigned char*,20)=byte255;
                    Spawn989E8Field(record,unsigned char*,21)=byte255;
                    Spawn989E8Field(record,unsigned char*,22)=byte128;
                    __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value) : "memory");
                    other<<=1;
                    value+=other;
                    Spawn989E8Field(record,short*,14)=value;
                }
                break;
            case 0x47:
                record = Spawn989E8func_80056434(1);
                Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                Spawn989E8Field(record, unsigned char *, 2) = (unsigned char) (Spawn989E8rand() & 7);
                Spawn989E8Field(record, unsigned char *, 3) = 1;
                temp_v0_4 = (int) (((Spawn989E8rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                Spawn989E8Stack(int,0x110) = temp_v0_4;
                temp_v0_5 = (int) (((Spawn989E8rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                Spawn989E8Stack(int,0x114) = temp_v0_5;
                temp_v0_6 = (int) (((Spawn989E8rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                Spawn989E8Stack(int,0x118) = temp_v0_6;
                {
                    register int value __asm__("$2");
                    register int other __asm__("$3");
                    other=Spawn989E8Field(reference,int*,0);
                    value=Spawn989E8Stack(int,0x110);
                    other>>=2;
                    value<<=2;
                    __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                    other+=value;
                    Spawn989E8Field(record,unsigned short*,4)=other;
                    __asm__("" ::: "$2","$3","memory");
                    other=Spawn989E8Field(reference,int*,4);
                    value=Spawn989E8Stack(int,0x114);
                    other>>=2;
                    value<<=2;
                    __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                    other+=value;
                    Spawn989E8Field(record,unsigned short*,6)=other;
                    __asm__("" ::: "$2","$3","memory");
                    other=Spawn989E8Field(reference,int*,8);
                    value=Spawn989E8Stack(int,0x118);
                    other>>=2;
                    value<<=2;
                    __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                    other+=value;
                    Spawn989E8Field(record,unsigned short*,8)=other;
                    __asm__("" ::: "$2","$3","memory");
                }
                {
                    register int other __asm__("$3")=Spawn989E8Stack(int,0x110);
                    register int value __asm__("$2")=Spawn989E8Field(record,unsigned short*,4);
                    register int finalComponent __asm__("$4");
                    __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                    value+=other;
                    Spawn989E8Field(record,short*,10)=value;
                    __asm__("" ::: "$2","$3","memory");
                    other=Spawn989E8Stack(int,0x114);
                    value=Spawn989E8Field(record,unsigned short*,6);
                    __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                    value+=other;
                    Spawn989E8Field(record,short*,12)=value;
                    __asm__("" ::: "$2","$3","$4","memory");
                    finalComponent=Spawn989E8Stack(int,0x118);
                    other=Spawn989E8Field(record,unsigned short*,8);
                    __asm__ __volatile__("" ::: "$2","memory");
                    value=2;
                    Spawn989E8Field(record,unsigned char*,23)=value;
                    value=224;
                    Spawn989E8Field(record,unsigned char*,16)=value;
                    Spawn989E8Field(record,unsigned char*,17)=value;
                    value=96;
                    Spawn989E8Field(record,unsigned char*,18)=value;
                    Spawn989E8Field(record,unsigned char*,20)=byte255;
                    Spawn989E8Field(record,unsigned char*,21)=byte255;
                    Spawn989E8Field(record,unsigned char*,22)=byte255;
                    value=80;
                    Spawn989E8Field(record,unsigned char*,19)=value;
                    __asm__("" : "=r"(other),"=r"(finalComponent) : "0"(other),"1"(finalComponent) : "memory");
                    other+=finalComponent;
                    Spawn989E8Field(record,short*,14)=other;
                }
                break;
            case 0x4E:
                record = Spawn989E8func_80056434(0);
                Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                Spawn989E8Field(record, unsigned char *, 2) = (unsigned char) (Spawn989E8rand() & 0x1F);
                Spawn989E8Field(record, unsigned char *, 3) = 1;
                Spawn989E8func_8004F504(record + 4, reference);
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,4);
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    random&=63;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component-=32;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component+=random;
                    Spawn989E8Field(record,unsigned short*,4)=component;
                }
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,6);
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    random&=63;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component-=32;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component+=random;
                    Spawn989E8Field(record,unsigned short*,6)=component;
                }
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3")=Spawn989E8Field(record,unsigned short*,8);
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    random&=63;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component-=32;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    component+=random;
                    Spawn989E8Field(record,unsigned short*,8)=component;
                }
                Spawn989E8Field(record, short *, 0x10) = (short) ((Spawn989E8rand() & 2) - 1);
                Spawn989E8Field(record, short *, 0x12) = (short) ((Spawn989E8rand() & 2) - 1);
                Spawn989E8Field(record, short *, 0x14) = (short) -(Spawn989E8rand() & 1);
                tailByte=Spawn989E8rand();
                tailByte|=128;
                __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                Spawn989E8Field(record,unsigned char*,12)=tailByte;
                {
                    register int random __asm__("$2")=Spawn989E8rand();
                    register int component __asm__("$3");
                    random&=127;
                    __asm__("" : "=r"(random) : "0"(random));
                    component=Spawn989E8Field(record,unsigned char*,12);
                    __asm__("" : "=r"(random) : "0"(random) : "memory");
                    random+=96;
                    __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                    Spawn989E8Field(record,unsigned char*,13)=random;
                    if((unsigned int)component<(unsigned int)random)Spawn989E8Field(record,unsigned char*,13)=component;
                }
                Spawn989E8Field(record, unsigned char *, 0xE) = (unsigned char) ((Spawn989E8rand() & 0x3F) + 0x40);
                Spawn989E8Field(record, unsigned char *, 0xF) = 0x40;
                Spawn989E8Field(record, unsigned char *, 0xA) = 2;
                break;
            case 0x4F:
                {
                    register int local128 __asm__("$8");
                    record = Spawn989E8func_80056434(1);
                    Spawn989E8Field(record, unsigned char *, 0) = kindSelector;
                    Spawn989E8Field(record, unsigned char *, 2) = (unsigned char) (Spawn989E8rand() & 0xF);
                    Spawn989E8Field(record, unsigned char *, 3) = 1;
                    Spawn989E8func_8004F504(record + 0xA, reference);
                    {
                        register void *vector __asm__("$16");
                        __asm__ volatile("" ::: "$16");
                        vector=(void*)&Spawn989E8Stack(int,0x110);
                        __asm__("" : "=r"(vector) : "0"(vector));
                        Spawn989E8func_8004F194(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2")=Spawn989E8rand();
                            register int component __asm__("$3");
                            component=*(volatile int*)&Spawn989E8Stack(int,0x110);
                            __asm__ volatile("" : "=r"(random), "=r"(component) : "0"(random), "1"(component) : "memory");
                            random&=0x3F;
                            component-=0x20;
                            component+=random;
                            Spawn989E8Stack(int,0x110)=component;
                        }
                        {
                            register int random __asm__("$2")=Spawn989E8rand();
                            register int component __asm__("$3")=Spawn989E8Stack(int,0x114);
                            random&=0x3F;
                            component-=0x20;
                            component+=random;
                            Spawn989E8Stack(int,0x114)=component;
                        }
                        {
                            register int random __asm__("$2")=Spawn989E8rand();
                            register int component __asm__("$3");
                            register void *destination __asm__("$4")=record+4;
                            register void *source __asm__("$5")=vector;
                            component=Spawn989E8Stack(int,0x118);
                            random&=0x7F;
                            component-=0x40;
                            component+=random;
                            Spawn989E8Stack(int,0x118)=component;
                            Spawn989E8func_8004F504(destination,source);
                        }
                    }
                    Spawn989E8Field(record, unsigned char *, 0x17) = 2;
                    tailByte=Spawn989E8rand();
                    tailByte|=192;
                    Spawn989E8Field(record,unsigned char*,16)=tailByte;
                    Spawn989E8Field(record, unsigned char *, 0x11) = (unsigned char) ((Spawn989E8rand() & 0x3F) - 0x60);
                    Spawn989E8Field(record, unsigned char *, 0x12) = 0;
                    tailByte=Spawn989E8rand();
                    tailByte|=224;
                    Spawn989E8Field(record,unsigned char*,20)=tailByte;
                    tailByte=Spawn989E8rand();
                    tailByte|=224;
                    local128=128;
                    Spawn989E8Field(record,unsigned char*,21)=tailByte;
                    {
                        Spawn989E8Field(record, unsigned char *, 0x16) = local128;
                    }
                    Spawn989E8Field(record, unsigned char *, 0x13) = 0x50;
                    break;
                }
            case 0x54:
                record=Spawn989E8func_80056434(0);
                Spawn989E8Field(record,unsigned char*,0)=kindSelector;
                tailByte=Spawn989E8rand();
                tailByte&=15;
                Spawn989E8Field(record,unsigned char*,2)=tailByte;
                Spawn989E8Field(record,unsigned char*,3)=1;
                Spawn989E8Field(record,unsigned short*,4)=Spawn989E8Field(reference,int*,0)>>2;
                Spawn989E8Field(record,unsigned short*,6)=Spawn989E8Field(reference,int*,4)>>2;
                Spawn989E8Field(record,unsigned short*,8)=Spawn989E8Field(reference,int*,8)>>2;
                tailByte=Spawn989E8func_8003636C(-3,3);
                Spawn989E8Field(record,unsigned short*,16)=tailByte;
                tailByte=Spawn989E8func_8003636C(-3,3);
                Spawn989E8Field(record,unsigned short*,18)=tailByte;
                tailByte=Spawn989E8func_8003636C(-3,3);
                Spawn989E8Field(record,unsigned short*,20)=tailByte;
                Spawn989E8Field(record,unsigned char*,10)=2;
                Spawn989E8Field(record,unsigned char*,12)=Spawn989E8Field(modeSelector,unsigned char*,0);
                Spawn989E8Field(record,unsigned char*,13)=Spawn989E8Field(modeSelector,unsigned char*,1);
                {
                    register int color3 __asm__("$3")=Spawn989E8Field(modeSelector,unsigned char*,2);
                    tailByte=64;
                    Spawn989E8Field(record,unsigned char*,15)=tailByte;
                    Spawn989E8Field(record,unsigned char*,14)=color3;
                }
                break;
            storeTrailingF8:
                Spawn989E8Field(record,unsigned char*,15)=commonByte8;
                goto initializeTrailingBytes;
            }
            __asm__ volatile("":"=r"(byte255):"0"(byte255):"memory");
            {
                register int stride9 __asm__("$9")=Spawn989E8Stack(volatile int,0x138);
                register int iteration8 __asm__("$8")=Spawn989E8Stack(int,0x128);
                __asm__("":"=r"(stride9),"=r"(iteration8):"0"(stride9),"1"(iteration8));
                stride9+=4;
                Spawn989E8Stack(volatile int,0x138)=stride9;
                stride9=Spawn989E8Stack(int,0x120);
                __asm__("":"=r"(stride9),"=r"(iteration8):"0"(stride9),"1"(iteration8));
                iteration8+=1;
                var_v0=iteration8<stride9;
                __asm__ volatile("":"=r"(var_v0),"=r"(iteration8):"0"(var_v0),"1"(iteration8):"$3","memory");
                Spawn989E8Stack(int,0x128)=iteration8;
            }
        }
        while(var_v0);
    }
    return record;
}
#undef Spawn989E8Field
#undef Spawn989E8High
#undef Spawn989E8Stack
