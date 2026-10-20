#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Level16Spawnfunc_8001A358(void*,int) __asm__("func_8001A358");
extern int Level16SpawnD_8006D07C __asm__("D_8006D07C");
extern int Level16SpawnD_8006D080 __asm__("D_8006D080");
extern int Level16SpawnD_8006D084 __asm__("D_8006D084");
extern int Level16SpawnD_80071934 __asm__("D_80071934");
extern unsigned char Level16SpawnPlayerE __asm__("D_80070328 + 0xE");
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level16SpawnHigh(a,b) ({ int high; __asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory"); high; })
extern unsigned char Level16SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level16SpawnColor2[] __asm__("D_80066BAC");
#define Level16SpawnField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level16Spawnfunc_8004EA90(void*,void*,int) __asm__("func_8004EA90");
int Level16Spawnfunc_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Level16Spawnfunc_8004F110(void*,int) __asm__("func_8004F110");
int Level16Spawnfunc_8004F178(void*,void*) __asm__("func_8004F178");
int Level16Spawnfunc_8004F194(void*,void*,void*) __asm__("func_8004F194");
int Level16Spawnfunc_8004F1FC(void*,void*,int) __asm__("func_8004F1FC");
int Level16Spawnfunc_8004F504(void*,void*) __asm__("func_8004F504");
void* Level16Spawnfunc_80056434(int) __asm__("func_80056434");
int Level16Spawnfunc_8003636C(int,int) __asm__("func_8003636C");
int Level16Spawnfunc_8004F58C(void*,void*) __asm__("func_8004F58C");
int Level16Spawnrand(void) __asm__("rand");
extern unsigned char Level16SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level16SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level16SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level16SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level16SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level16SpawnD_80070328[] __asm__("D_80070328");
extern int Level16SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original SCUS-94467 USA Rev0 level16
 * constructor evidence: build/sibling4248.func_level_16_80081F48.json.
 * Raw helper contracts, units and update cadence remain unresolved. */
void *func_level_16_80081F48(int entryCount, int kind, void *input, void *mode) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        int sp1C;
        int sp20;
        int sp24;
        int sp28;
        int sp2C;
        int sp30;
        int sp34;
        int sp38;
        int sp3C;
        int sp40;
        int sp44;
        int sp48;
        int sp4C;
        int sp50;
        int sp54;
        int sp58;
        int sp5C;
        int sp60;
        int sp64;
        int sp68;
        int sp6C;
        int sp70;
        int sp74;
        int sp78;
        int sp7C;
        int sp80;
        int sp84;
        int sp88;
        int sp8C;
        int sp90;
        int sp94;
        int sp98;
        int sp9C;
        unsigned char spA0,spA1,spA2,padA3;
        int spA4;
        int spA8;
        int spAC;
        int spB0;
        int spB4;
        int spB8;
        int spBC;
        int spC0;
        int spC4;
        int spC8;
        int spCC;
        int spD0;
        int spD4;
        int spD8;
        int spDC;
        int * volatile spE0;
        int spE4;
        int spE8;
        int spEC;
        volatile int spF0;
        int spF4;
    } frame;
    register int kindSelector __asm__("$23")=kind;
    register unsigned char *reference __asm__("$20")=input;
    register unsigned char *modeSelector __asm__("$22")=mode;
    short *temp_a0_2;
    short *temp_a1;
    register unsigned char *temp_s1 __asm__("$17");
    register unsigned char *temp_s1_2 __asm__("$17");
    int temp_a0;
    int temp_a3;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v1;
    register int commonByte8 __asm__("$8");
    register int commonByte9 __asm__("$9");
    int byte255;
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailByte __asm__("$2");
    register int scratch19 __asm__("$19");
    int var_v0_2;
    register int var_v0_4 __asm__("$2");
    unsigned int temp_v1_2;
    int temp_v0_7;
    unsigned char temp_v1_3;
    void *var_a0;
    register unsigned char *record __asm__("$18");

    __asm__("" : "=r"(kindSelector),"=r"(reference),"=r"(modeSelector) : "0"(kindSelector),"1"(reference),"2"(modeSelector));
    record = 0;
    __asm__("" : "=r"(record):"0"(record));
    frame.spD0 = entryCount;
    frame.spD8 = 0;
    if (entryCount > 0) {
        {register int *vectorBase __asm__("$8")=&frame.sp30;
         __asm__("" : "=r"(vectorBase) : "0"(vectorBase) : "$30");
         byte255=255;
         __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
         frame.spE0=vectorBase;
         }
        frame.spF0 = 0;
        do {
                __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                switch (kindSelector) {                     /* switch 1 */
                case 0x0:                           /* switch 1 */
                    record = Level16Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     register int one __asm__("$9");
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$8");
                     one=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = 0;
                    Level16SpawnField(record, unsigned char *, 3) = one;
                    Level16Spawnfunc_8004F504(destination, source);
                    }
                    Level16Spawnfunc_8004F504(record + 0x18, modeSelector);
                    Level16SpawnField(record, short *, 0x1E) = 0;
                    Level16SpawnField(record, unsigned char *, 0xA) = 0x18;
                    tailByte=Level16Spawnrand();
                    commonByte8=128;commonByte9=128;
                    __asm__("" : "=r"(commonByte8),"=r"(commonByte9),"=r"(tailByte):"0"(commonByte8),"1"(commonByte9),"2"(tailByte));
                    Level16SpawnField(record,volatile unsigned char*,12)=commonByte8;
                    Level16SpawnField(record,volatile unsigned char*,13)=commonByte9;
                    commonByte9=46;Level16SpawnField(record,volatile unsigned char*,11)=tailByte;
                    __asm__ volatile("" : "=r"(commonByte8),"=r"(commonByte9):"0"(commonByte8),"1"(commonByte9):"$3","memory");
                    tailByte=4;goto storeTrailingE8;
                case 0x1:                           /* switch 1 */
                    record = Level16Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = 0;
                    Level16SpawnField(record, unsigned char *, 3) = tailByte;
                    Level16Spawnfunc_8004F504(destination, source);
                    }
                    Level16Spawnfunc_8004F504(record + 0x18, modeSelector);
                    Level16SpawnField(record, short *, 0x1E) = 0;
                    Level16SpawnField(record, unsigned char *, 0xA) = 0x10;
                    tailByte=Level16Spawnrand();
                    Level16SpawnField(record,volatile unsigned char*,11)=tailByte;
                    tailByte=96;commonByte8=46;
                    __asm__("" : "=r"(commonByte8),"=r"(tailByte):"0"(commonByte8),"1"(tailByte));
                    Level16SpawnField(record,volatile unsigned char*,12)=tailByte;Level16SpawnField(record,volatile unsigned char*,13)=tailByte;Level16SpawnField(record,volatile unsigned char*,14)=tailByte;
                    __asm__ volatile("" : "=r"(commonByte8),"=r"(tailByte):"0"(commonByte8),"1"(tailByte):"$3","memory");
                    tailByte=4;Level16SpawnField(record,unsigned char*,15)=commonByte8;
                    goto initializeTrailingBytes;
                case 0x2:
                    record=Level16Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source):"0"(destination),"1"(source):"$2");
                     tailByte=1;
                     __asm__("" : "=r"(tailByte),"=r"(destination),"=r"(source):"0"(tailByte),"1"(destination),"2"(source));
                     Level16SpawnField(record,unsigned char*,0)=kindSelector;
                     Level16SpawnField(record,unsigned char*,2)=0;
                     Level16SpawnField(record,unsigned char*,3)=tailByte;
                     Level16Spawnfunc_8004F504(destination,source);
                     tailByte=Level16Spawnrand();tailByte&=63;tailByte-=32;frame.sp10=tailByte;
                     tailByte=Level16Spawnrand();
                     destination=record+24;source=&frame.sp10;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte):"0"(destination),"1"(source),"2"(tailByte));
                     tailByte&=63;tailByte-=32;frame.sp14=tailByte;frame.sp18=16;
                     Level16Spawnfunc_8004F504(destination,source);
                    }
                    tailByte=32;
                    Level16SpawnField(record,unsigned short*,30)=0;
                    Level16SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=Level16Spawnrand();
                    commonByte9=128;commonByte8=128;
                    __asm__("" : "=r"(commonByte9),"=r"(commonByte8),"=r"(tailByte):"0"(commonByte9),"1"(commonByte8),"2"(tailByte));
                    Level16SpawnField(record,volatile unsigned char*,12)=commonByte9;Level16SpawnField(record,volatile unsigned char*,13)=commonByte8;
                    commonByte8=46;
                    Level16SpawnField(record,volatile unsigned char*,14)=commonByte9;
                    commonByte9=2;Level16SpawnField(record,volatile unsigned char*,11)=tailByte;
                    Level16SpawnField(record,volatile unsigned char*,15)=commonByte8;
                    Level16SpawnField(record,volatile unsigned char*,17)=commonByte9;Level16SpawnField(record,unsigned char*,16)=0;
                    break;
                case 0x9:                           /* switch 1 */
                    record = Level16Spawnfunc_80056434(2);
                    {register void *playerVector __asm__("$16")=&frame.sp20;
                     register void *destination __asm__("$4")=playerVector;
                     register unsigned char *player __asm__("$17");
                     register void *source __asm__("$5");
                     __asm__("" : "=r"(destination) : "0"(destination) : "$17");
                     player=Level16SpawnD_80070328;
                     source=player;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(player) : "0"(destination),"1"(source),"2"(player) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(tailByte),"=r"(destination),"=r"(source),"=r"(player) : "0"(tailByte),"1"(destination),"2"(source),"3"(player) : "memory");
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = 0;
                    Level16SpawnField(record, unsigned char *, 3) = tailByte;
                    Level16Spawnfunc_8004F178(destination,source);
                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp20;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x7E;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=0x3F;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     frame.sp20=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3");
                     register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=&frame.sp20;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$3","memory");
                     component=frame.sp24;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x7E;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=0x3F;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     frame.sp24=component;
                     Level16Spawnfunc_8004F504(destination,source);
                     }
                    Level16Spawnfunc_8004F178(playerVector, player + 0x98);
                    Level16Spawnfunc_8004F110(playerVector, 6);
                    Level16Spawnfunc_8004F504(record + 0x18, playerVector);
                    }
                    Level16SpawnField(record, short *, 0x1E) = 0;
                    Level16SpawnField(record, unsigned char *, 0xA) = 0x18;
                    tailByte=Level16Spawnrand();
                    commonByte8=128;commonByte9=128;
                    __asm__("" : "=r"(commonByte8),"=r"(commonByte9),"=r"(tailByte):"0"(commonByte8),"1"(commonByte9),"2"(tailByte));
                    Level16SpawnField(record,volatile unsigned char*,12)=commonByte8;Level16SpawnField(record,volatile unsigned char*,13)=commonByte9;
                    commonByte9=46;
                    Level16SpawnField(record,volatile unsigned char*,11)=tailByte;
                    tailByte=4;
                    goto storeTrailingE8;

                case 0xA:                           /* switch 1 */
                    record = Level16Spawnfunc_80056434(3);
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=Level16SpawnD_80070328;
                     tailByte=Level16Spawnrand();
                     destination=record+4;
                     source=Level16SpawnD_80070328;
                     tailByte&=31;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                     Level16SpawnField(record,unsigned char*,2)=tailByte;
                     __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                     tailByte=1;
                     Level16SpawnField(record,unsigned char*,3)=tailByte;
                     Level16Spawnfunc_8004F504(destination,source);
                     }
                    {register int factor __asm__("$4")=0x66660000;
                     register int value __asm__("$2");
                     register int count __asm__("$8");
                     register int iteration8 __asm__("$9");
                     register int dividend __asm__("$3");
                     register int productHigh __asm__("hi");
                     register int color __asm__("$4");
                     value=24;
                     __asm__("" : "=r"(factor),"=r"(value) : "0"(factor),"1"(value));
                     Level16SpawnField(record,unsigned char*,10)=value;
                     value=15;
                     Level16SpawnField(record,unsigned char*,11)=value;
                     __asm__("" : "=r"(factor) : "0"(factor) : "memory");
                     count=frame.spD0;
                     iteration8=frame.spD8;
                     __asm__("" : "=r"(count),"=r"(iteration8):"0"(count),"1"(iteration8));
                     factor|=0x6667;
                     dividend=count-iteration8;
                     count=frame.spF0;
                     __asm__("" : "=r"(count),"=r"(dividend) : "0"(count),"1"(dividend));
                     dividend<<=12;
                     value=*(Level16SpawnD_80066BAC+count);
                     __asm__("" : "=r"(dividend),"=r"(factor) : "0"(dividend),"1"(factor) : "memory");
                     productHigh=Level16SpawnHigh(dividend,factor);
                     Level16SpawnField(record,unsigned char*,12)=value;
                     value=*(Level16SpawnColor1+1+count);
                     dividend>>=31;
                     Level16SpawnField(record,unsigned char*,13)=value;
                     color=*(Level16SpawnColor2+2+count);
                     value=44;
                     Level16SpawnField(record,unsigned char*,15)=value;
                     value=4;
                     Level16SpawnField(record,unsigned char*,17)=value;
                     Level16SpawnField(record,unsigned char*,16)=0;
                     Level16SpawnField(record,unsigned char*,14)=color;
                     __asm__("" : "=h"(productHigh),"=r"(dividend) : "0"(productHigh),"1"(dividend) : "memory");
                     iteration8=productHigh;
                     __asm__("" : "=r"(iteration8) : "0"(iteration8));
                     value=(iteration8>>1)-dividend;
                     Level16SpawnField(record,short*,24)=value;
                    }
                    break;
                case 0xC:                           /* switch 1 */
                    record = Level16Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=reference+32;
                     register int iteration __asm__("$8")=frame.spD8;
                     register void *vector __asm__("$6")=frame.spE0;
                     register int base __asm__("$2");
                     register void *table __asm__("$5");
                     __asm__("" : "=r"(destination),"=r"(iteration),"=r"(vector):"0"(destination),"1"(iteration),"2"(vector):"$2","$5","memory");
                     base=(int)Level16SpawnD_80066A48;
                     Level16SpawnField(record,unsigned char*,0)=kindSelector;
                     __asm__("" : "=r"(base),"=r"(iteration):"0"(base),"1"(iteration):"memory");
                     table=(void*)(iteration*12);
                     __asm__("" : "=r"(table),"=r"(base):"0"(table),"1"(base));
                     table=(void*)((int)table+base);
                     __asm__("" : "=r"(table):"0"(table):"$2","memory");
                     base=1;Level16SpawnField(record,unsigned char*,3)=base;
                     base=4;Level16SpawnField(record,unsigned char*,17)=base;
                     Level16Spawnfunc_8004ED6C(destination,table,vector);
                     }
                    if (({register int observed __asm__("$2")=Level16SpawnField(reference,short*,54);
                         register int expected __asm__("$9");
                         __asm__ __volatile__("" ::: "$8","memory");
                         expected=0x17D;
                         __asm__("" : "=r"(expected) : "0"(expected));
                         observed==expected;
                         })) {
                        Level16Spawnfunc_8004F1FC(frame.spE0, frame.spE0, 3);
                    }
                    Level16Spawnfunc_8004F194(frame.spE0, frame.spE0, reference + 0xC);
                    if (modeSelector == (unsigned char *)5) {
                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp30;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x1FF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x100;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp30=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp34;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x1FF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x100;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp34=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp38;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x1FF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x100;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp38=component;
                     }

                    }
                    if (modeSelector == (unsigned char *)6) {
                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp30;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp30=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp34;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp34=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp38;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp38=component;
                     }

                    }
                    if (Level16SpawnField(reference, short *, 0x36) == 0xB6) {
                        frame.sp38 += 0x200;
                    }
                    Level16Spawnfunc_8004F504(record + 4, frame.spE0);
                    Level16SpawnField(record, int *, 0xC) = (int) *(int*)(Level16SpawnD_80066A28 + ((int) modeSelector * 4));
                    if (({register int observed __asm__("$2")=Level16SpawnField(reference,short*,54);
                         register int expected __asm__("$8");
                         __asm__ __volatile__("" ::: "$8","memory");
                         expected=0x17D;
                         __asm__("" : "=r"(expected) : "0"(expected));
                         observed==expected;
                         })) {
                        var_v0_2 = (Level16Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level16Spawnrand() & 7) + 0x20;
                    }
                    Level16SpawnField(record, unsigned char *, 0xA) = var_v0_2;
                    tailByte=Level16Spawnrand();
                    {register void *destination __asm__("$4")=record+24;
                     register int iteration __asm__("$9")=frame.spD8;
                     register int base __asm__("$3");
                     register void *source __asm__("$5");
                     __asm__("" : "=r"(destination),"=r"(iteration),"=r"(tailByte):"0"(destination),"1"(iteration),"2"(tailByte):"$3","$5","memory");
                     base=(int)Level16SpawnD_80066A48;
                     Level16SpawnField(record,unsigned char*,11)=tailByte;
                     Level16SpawnField(record,unsigned char*,16)=0;
                     __asm__("" : "=r"(base),"=r"(iteration):"0"(base),"1"(iteration):"memory");
                     source=(void*)(iteration*12);
                     __asm__("" : "=r"(source),"=r"(base):"0"(source),"1"(base));
                     source=(void*)((int)source+base);
                     Level16Spawnfunc_8004F504(destination,source);
                     }
                    Level16SpawnField(record, unsigned short *, 0x18) = (unsigned short) (((int) (Level16SpawnField(record, unsigned short *, 0x18) << 0x10) >> 0x12) - 4 + (Level16Spawnrand() & 7));
                    Level16SpawnField(record, unsigned short *, 0x1A) = (unsigned short) (((int) (Level16SpawnField(record, unsigned short *, 0x1A) << 0x10) >> 0x12) - 4 + (Level16Spawnrand() & 7));
                    Level16SpawnField(record, unsigned short *, 0x1C) = (unsigned short) (((int) (Level16SpawnField(record, unsigned short *, 0x1C) << 0x10) >> 0x12) - 4 + (Level16Spawnrand() & 7));
                    break;
                case 0x21:                          /* switch 1 */
                    record = Level16Spawnfunc_80056434(2);
                    tailByte=1;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = 0;
                    Level16SpawnField(record, unsigned char *, 3) = tailByte;
                    if (modeSelector == 0) {
                        {register void *destination __asm__("$4");
                         scratch16=(int)&frame.sp50;
                         destination=(void*)scratch16;
                         __asm__("" : "=r"(scratch16),"=r"(destination) : "0"(scratch16),"1"(destination) : "$17");
                         temp_s1 = Level16SpawnD_80070328 + 0x98;
                         Level16Spawnfunc_8004F178(destination,temp_s1);
                         }
                        Level16Spawnfunc_8004F110((void*)scratch16, 6);
                        Level16Spawnfunc_8004F178(&frame.sp40, temp_s1 - 0x98);
                        frame.sp48 -= 0x164;
                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.sp40;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp40=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3");
                     __asm__("" : "=r"(random) : "0"(random) : "$19");
                     scratch19=48;
                     component=frame.sp44;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp44=component;
                     }

                        goto setDestination;
                    } else {
                        register int one __asm__("$8")=1;
                        __asm__("" : "=r"(one) : "0"(one));
                        if(modeSelector == (unsigned char*)one) {
                        temp_s1_2 = Level16SpawnD_80070328 + 0x30;
                        frame.sp40 = 0x164;
                        frame.sp44 = 0;
                        frame.sp48 = 0;
                        Level16Spawnfunc_8004ED6C(temp_s1_2, &frame.sp40, &frame.sp40);
                        Level16Spawnfunc_8004F194(&frame.sp40, &frame.sp40, temp_s1_2 - 0x30);
                        scratch19 = 0x40;
                        frame.sp50 = -(Level16Spawnrand() & 7);
                        {register int random __asm__("$2")=Level16Spawnrand();
                         register int component __asm__("$3");
                         register void *destination __asm__("$4")=temp_s1_2;
                         register void *vector __asm__("$5")=&frame.sp50;
                         register int iteration8 __asm__("$9")=frame.spD8;
                         register int angle __asm__("$7");
                         register void *output __asm__("$6")=vector;
                         __asm__("" : "=r"(destination),"=r"(vector),"=r"(angle),"=r"(output) : "0"(destination),"1"(vector),"2"(angle),"3"(output) : "memory");
                         __asm__("" : "=r"(iteration8):"0"(iteration8));
                         random&=15;angle=iteration8<<6;
                         component=*(unsigned short*)(Level16SpawnD_80065920+angle);
                         __asm__("" : "=r"(random) : "0"(random) : "memory");
                         random-=8;
                         __asm__("" : "=r"(random) : "0"(random));
                         component=(component<<16)>>23;
                         component-=random;
                         frame.sp54=component;
                         random=*(unsigned short*)(Level16SpawnD_800658A0+angle);
                         random=(random<<16)>>23;
                         frame.sp58=random;
                         Level16Spawnfunc_8004ED6C(destination,vector,output);
                         }
                        var_a0 = record + 4;
                        goto finishMode;
                        } else {one=2;__asm__("" : "=r"(one):"0"(one));scratch16=5;if(modeSelector == (unsigned char*)one) {
                        {register int iteration8 __asm__("$9")=frame.spD8;
                         __asm__("" : "=r"(iteration8):"0"(iteration8):"$17","$16","$19","memory");
                         scratch17=iteration8<<5;
                         __asm__("" : "=r"(scratch17):"0"(scratch17):"$16","$19","memory");
                        }
                        scratch16 = 6;
                        scratch19 = 0x30;
                        goto updateSharedVector;
                        } else {
                        {register int iteration9 __asm__("$8")=frame.spD8;
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
                        Level16Spawnfunc_8004F178(&frame.sp40,Level16SpawnD_80070328);
                        {register short *first __asm__("$5")=(short*)Level16SpawnD_80065920;
                         register unsigned char *second __asm__("$4");
                         register int value __asm__("$2");
                         register int other __asm__("$3");
                         second=(unsigned char*)(scratch17*2);
                         __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$2","$3","memory");
                         first=(short*)((int)second+(int)first);
                         value=*first;
                         other=frame.sp40;
                         value>>=scratch16;
                         other+=value;
                         value=(int)Level16SpawnD_800658A0;
                         second+=value;
                         value=frame.sp48;
                         frame.sp40=other;
                         other=*(short*)second;
                         value-=356;
                         frame.sp48=value;
                         value=frame.sp44;
                         other>>=scratch16;
                         value+=other;
                         frame.sp44=value;
                         __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$2","$3","memory");
                         value=*first;
                         other=scratch16+1;
                         value>>=other;
                         frame.sp50=value;
                         value=*(short*)second;
                         frame.sp58=0;
                         value>>=other;
                         frame.sp54=value;
                         }
setDestination:
                        var_a0=record+4;
finishMode:
                    Level16Spawnfunc_8004F504(var_a0, &frame.sp40);
                    Level16Spawnfunc_8004F504(record + 0x18, &frame.sp50);
                    Level16SpawnField(record, short *, 0x1E) = 0;
                    Level16SpawnField(record, unsigned char *, 0xA) = 0x10;
                    tailByte=Level16Spawnrand();commonByte9=46;
                    __asm__("" : "=r"(tailByte),"=r"(commonByte9):"0"(tailByte),"1"(commonByte9):"memory");
                    Level16SpawnField(record,volatile unsigned char*,11)=tailByte;
                    tailByte=4;
                    Level16SpawnField(record,volatile unsigned char*,12)=scratch19;
                    Level16SpawnField(record,volatile unsigned char*,13)=scratch19;
                    Level16SpawnField(record,unsigned char*,14)=scratch19;
                    goto storeTrailingF9;

                case 0x29:
                    {register unsigned char *stackBase29 __asm__("$29");
                     register void *vector16 __asm__("$16");
                     register void *vector17 __asm__("$17");
                     register int angle21 __asm__("$21");
                     register int radius19 __asm__("$19");
                     register int value2 __asm__("$2");
                     register int value3 __asm__("$3");
                     register int index4 __asm__("$4");
                     register int low8 __asm__("$9");
                     register int low9 __asm__("$8");
                     register void *destination4 __asm__("$4");
                     register void *source5 __asm__("$5");
                     __asm__ volatile("" ::: "$16","memory");/* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                     __asm__ volatile("" : "=r"(stackBase29):"0"((unsigned char*)&frame-0x10):"memory");
                     vector16=stackBase29+0x60;
                     __asm__ volatile("" : "=r"(vector16):"0"(vector16):"memory");
                     Level16Spawnfunc_8004F178(vector16,reference);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     value2=Level16Spawnrand();
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");value3=frame.sp60;value2&=255;value3+=128;value3-=value2;frame.sp60=value3;
                     value2=Level16Spawnrand();
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");value3=frame.sp64;value2&=255;value3+=128;value3-=value2;frame.sp64=value3;
                     value2=Level16Spawnrand();
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");angle21=value2&255;
                     value2=Level16Spawnrand();
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     {register void *arg4 __asm__("$4")=&frame.sp70;
                      register void *arg5 __asm__("$5")=vector16;
                      __asm__("" : "=r"(arg4),"=r"(arg5),"=r"(value2):"0"(arg4),"1"(arg5),"2"(value2));
                      value2&=1023;radius19=value2+512;
                      Level16Spawnfunc_8004F178(arg4,arg5);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");}
                     destination4=&frame.sp80;
                     if(modeSelector!=0) source5=modeSelector;
                     else {source5=Level16SpawnD_80070328+0x8C;__asm__ volatile("" : "=r"(source5):"0"(source5):"memory");}
                     Level16Spawnfunc_8004F178(destination4,source5);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     __asm__ volatile("" ::: "$16","memory");/* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                     __asm__ volatile("" : "=r"(stackBase29):"0"((unsigned char*)&frame-0x10):"memory");
                     vector16=stackBase29+0x80;
                     __asm__ volatile("" : "=r"(vector16):"0"(vector16):"memory");Level16Spawnfunc_8004F110(vector16,1);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     {register int count9 __asm__("$8")=frame.spD0;
                      register int one8 __asm__("$9")=1;
                      __asm__("" : "=r"(count9),"=r"(one8):"0"(count9),"1"(one8));
                     __asm__ volatile("" ::: "$17","memory");/* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                     __asm__ volatile("" : "=r"(stackBase29):"0"((unsigned char*)&frame-0x10):"memory");
                     vector17=stackBase29+0x70;
                     if(count9==one8){Level16Spawnfunc_8004F1FC(vector16,vector16,3);
                     __asm__ volatile("" : "=r"(vector17):"0"(vector17):"memory");
                     __asm__ volatile("" ::: "$17","memory");/* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                     __asm__ volatile("" : "=r"(stackBase29):"0"((unsigned char*)&frame-0x10):"memory");
                     vector17=stackBase29+0x70;
                     __asm__ volatile("" : "=r"(vector17):"0"(vector17):"memory");
                     } }
                     frame.sp88=0;
                     Level16Spawnfunc_8004F194(vector17,vector17,vector16);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     index4=angle21<<1;
                     value2=Level16SpawnField(Level16SpawnD_80065920+index4,short*,0);
                     __asm__ volatile("" : "=l"(low9):"0"(value2*radius19):"memory");
                     value2=frame.sp70;value3=low9>>12;value2+=value3;frame.sp70=value2;
                     value2=Level16SpawnField(Level16SpawnD_800658A0+index4,short*,0);
                     {int productLo=value2*radius19;
                      __asm__ volatile("" : "=l"(productLo):"0"(productLo):"memory");
                      source5=(void*)1024;value2=frame.sp78;
                      __asm__("" : "=r"(source5),"=r"(value2):"0"(source5),"1"(value2):"$4");destination4=vector17;
                      __asm__("" : "=r"(source5),"=r"(value2),"=r"(destination4):"0"(source5),"1"(value2),"2"(destination4));
                      value2+=512;frame.sp78=value2;value2=frame.sp74;
                      __asm__ volatile("" : "=l"(productLo),"=r"(value2):"0"(productLo),"1"(value2):"memory");
                      low8=productLo;__asm__("" : "=r"(low8):"0"(low8));
                      value3=low8>>12;value2+=value3;frame.sp74=value2;
                      value2=Level16Spawnfunc_8001A358(destination4,(int)source5);
                     }
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");frame.sp78=value2;
                     if(value2==0)break;
                     record=Level16Spawnfunc_80056434(3);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     value2=1;__asm__("" : "=r"(value2):"0"(value2):"memory");
                     Level16SpawnField(record,volatile unsigned char*,3)=value2;
                     value2=10;__asm__("" : "=r"(value2):"0"(value2):"memory");
                     Level16SpawnField(record,volatile unsigned char*,10)=value2;
                     value2=6;__asm__("" : "=r"(value2):"0"(value2):"$4","memory");
                     Level16SpawnField(record,unsigned char*,0)=kindSelector;
                     Level16SpawnField(record,unsigned char*,2)=0;
                     destination4=record+4;
                     __asm__("" : "=r"(destination4):"0"(destination4));
                     Level16SpawnField(record,unsigned char*,11)=value2;
                     value2=Level16SpawnD_8006D07C;
                     __asm__ volatile("" : "=r"(value2):"0"(value2):"$16","memory");
                     
                     __asm__ volatile("" ::: "$16","memory");/* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                     __asm__ volatile("" : "=r"(stackBase29):"0"((unsigned char*)&frame-0x10):"memory");
                     vector16=stackBase29+0x60;
                     __asm__ volatile("" : "=r"(vector16):"0"(vector16):"memory");
                     
                     value2>>=4;Level16SpawnField(record,unsigned char*,12)=value2;
                     value2=Level16SpawnD_8006D080;
                     __asm__("" : "=r"(value2):"0"(value2):"$5","memory");source5=vector16;
                     __asm__("" : "=r"(value2),"=r"(source5):"0"(value2),"1"(source5));
                     value2>>=4;Level16SpawnField(record,unsigned char*,13)=value2;
                     value3=Level16SpawnD_8006D084;
                     __asm__ volatile("" : "=r"(value3):"0"(value3):"$8","$2","memory");commonByte8=46;value2=2;
                     __asm__("" : "=r"(value3),"=r"(commonByte8),"=r"(value2):"0"(value3),"1"(commonByte8),"2"(value2));
                     Level16SpawnField(record,unsigned char*,15)=commonByte8;
                     Level16SpawnField(record,unsigned char*,17)=value2;Level16SpawnField(record,unsigned char*,16)=0;
                     __asm__ volatile("" : "=r"(value3):"0"(value3):"memory");value3>>=4;Level16SpawnField(record,unsigned char*,14)=value3;
                     Level16Spawnfunc_8004F504(destination4,source5);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     Level16Spawnfunc_8004F504(record+18,vector16);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     Level16Spawnfunc_8004F504(record+24,vector17);
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     scratch16=Level16Spawnrand();value2=Level16Spawnrand();
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
                     scratch16&=14;value2=(value2&6)+20;scratch16+=value2;
                     Level16SpawnField(record,unsigned short*,22)=scratch16;
                     Level16SpawnField(record,unsigned char*,30)=0;
                     while(scratch16>0 || frame.sp68>frame.sp78){
                         frame.sp68+=scratch16<<2;Level16SpawnField(record,unsigned char*,30)+=1;scratch16-=2;
                         __asm__ volatile("" : "=r"(scratch16):"0"(scratch16):"memory");
                     }
                     value2=Level16Spawnrand();
                     __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");Level16SpawnField(record,unsigned char*,29)=value2;
                     Level16SpawnField(record,unsigned char*,31)=Level16SpawnD_80071934;
                    }
                    break;
                case 0x2A:
                    record=Level16Spawnfunc_80056434(4);
                    {register void *arg4 __asm__("$4")=record+4;register void *arg5 __asm__("$5")=reference;
                    __asm__("" : "=r"(arg4),"=r"(arg5):"0"(arg4),"1"(arg5):"$2");tailByte=1;Level16SpawnField(record,unsigned char*,0)=kindSelector;Level16SpawnField(record,unsigned char*,2)=0;Level16SpawnField(record,unsigned char*,3)=tailByte;
                    Level16Spawnfunc_8004F504(arg4,arg5);}
                    tailByte=Level16SpawnField(reference,int*,0);Level16SpawnField(record,int*,24)=tailByte;
                    tailByte=Level16SpawnField(reference,int*,4);Level16SpawnField(record,int*,28)=tailByte;
                    tailByte=Level16SpawnField(modeSelector,int*,0);Level16SpawnField(record,unsigned short*,18)=tailByte;
                    tailByte=Level16SpawnField(modeSelector,int*,4);Level16SpawnField(record,unsigned short*,20)=tailByte;
                    tailByte=Level16Spawnrand();tailByte=(tailByte&7)+3;Level16SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=108;
                    __asm__("" : "=r"(tailByte):"0"(tailByte):"$3","$9","memory");
                    {register int color3 __asm__("$3")=Level16SpawnPlayerE;
                    __asm__("" : "=r"(color3),"=r"(tailByte):"0"(color3),"1"(tailByte):"$9","memory");commonByte9=46;
                    Level16SpawnField(record,unsigned char*,12)=tailByte;Level16SpawnField(record,unsigned char*,13)=tailByte;Level16SpawnField(record,unsigned char*,14)=tailByte;
                    Level16SpawnField(record,unsigned char*,15)=commonByte9;Level16SpawnField(record,unsigned char*,17)=0;Level16SpawnField(record,unsigned char*,16)=0;
                    __asm__ volatile("" : "=r"(color3):"0"(color3):"memory");color3+=32;Level16SpawnField(record,unsigned char*,11)=color3;}
                    break;
{register int commonByte3 __asm__("$3");
                case 0x2B:
                    record=Level16Spawnfunc_80056434(4);
                    tailByte=1;
                    Level16SpawnField(record,unsigned char*,0)=kindSelector;
                    Level16SpawnField(record,unsigned char*,2)=0;
                    Level16SpawnField(record,unsigned char*,3)=tailByte;
                    if(modeSelector==0){
                        Level16Spawnfunc_8004F58C(record+4,reference);
                        tailByte=Level16Spawnrand();tailByte&=7;tailByte+=2;
                        Level16SpawnField(record,unsigned char*,10)=tailByte;
                        commonByte3=96;
                    }else{
                        Level16Spawnfunc_8004F504(record+4,reference);
                        {register int two __asm__("$8")=2;
                         __asm__("" : "=r"(two):"0"(two));
                         if(modeSelector==(unsigned char*)two){
                            {register int random __asm__("$2")=Level16Spawnrand();
                             register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,4);
                             __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                             random&=127;component+=32;component-=random;
                             Level16SpawnField(record,unsigned short*,4)=component;}
                            {register int random __asm__("$2")=Level16Spawnrand();
                             register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,6);
                             __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                             random&=127;component+=32;component-=random;
                             Level16SpawnField(record,unsigned short*,6)=component;}
                         }}
                        tailByte=Level16Spawnrand();tailByte&=7;__asm__("" : "=r"(tailByte):"0"(tailByte));tailByte+=16;
                        Level16SpawnField(record,unsigned char*,10)=tailByte;
                        commonByte3=64;
                    }
                    {register int sourceByte __asm__("$2")=Level16SpawnField(Level16SpawnD_80070328,unsigned char*,14);
                     __asm__("" : "=r"(sourceByte),"=r"(commonByte3):"0"(sourceByte),"1"(commonByte3):"memory");
                     Level16SpawnField(record,unsigned char*,12)=commonByte3;
                     Level16SpawnField(record,unsigned char*,13)=commonByte3;
                     Level16SpawnField(record,unsigned char*,14)=commonByte3;
                     commonByte9=46;__asm__("" : "=r"(sourceByte),"=r"(commonByte9):"0"(sourceByte),"1"(commonByte9):"memory");Level16SpawnField(record,unsigned char*,15)=commonByte9;
                     Level16SpawnField(record,unsigned char*,17)=0;
                     Level16SpawnField(record,unsigned char*,16)=0;
                     Level16SpawnField(record,unsigned short*,24)=(int)modeSelector;
                     Level16SpawnField(record,unsigned char*,11)=sourceByte;
                    }
                    break;
}
                case 0x2E:
                    record=Level16Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     tailByte=1;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte):"0"(destination),"1"(source),"2"(tailByte):"memory");
                     Level16SpawnField(record,unsigned char*,0)=kindSelector;
                     Level16SpawnField(record,unsigned char*,2)=0;
                     Level16SpawnField(record,unsigned char*,3)=tailByte;
                     Level16Spawnfunc_8004F504(destination,source);
                    }
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,4);
                     __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                     random&=127;component+=64;component-=random;
                     Level16SpawnField(record,unsigned short*,4)=component;}
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(random),"=r"(component):"0"(random),"1"(component));
                     random&=127;component+=64;component-=random;
                     Level16SpawnField(record,unsigned short*,6)=component;}
                    if(modeSelector!=0){
                        tailByte=Level16Spawnrand();tailByte&=15;
                        __asm__("" : "=r"(tailByte):"0"(tailByte));
                        tailByte=(int)modeSelector+tailByte;
                    }else{
                        tailByte=Level16Spawnrand();tailByte&=15;
                        __asm__("" : "=r"(tailByte):"0"(tailByte));
                        tailByte+=20;
                    }
                    Level16SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=Level16Spawnrand();
                    commonByte8=128;commonByte9=128;
                    __asm__("" : "=r"(commonByte8),"=r"(commonByte9),"=r"(tailByte):"0"(commonByte8),"1"(commonByte9),"2"(tailByte));
                    Level16SpawnField(record,volatile unsigned char*,12)=commonByte8;Level16SpawnField(record,volatile unsigned char*,13)=commonByte9;
                    commonByte9=46;
                    Level16SpawnField(record,volatile unsigned char*,11)=tailByte;
                    tailByte=2;
                    __asm__ volatile("" : "=r"(tailByte),"=r"(commonByte9),"=r"(commonByte8):"0"(tailByte),"1"(commonByte9),"2"(commonByte8):"$4","memory");
storeTrailingE8:
                    Level16SpawnField(record,unsigned char*,14)=commonByte8;
storeTrailingF9:
                    __asm__ volatile("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"memory");
                    Level16SpawnField(record,unsigned char*,15)=commonByte9;
                    initializeTrailingBytes:
                    __asm__ volatile("" : "=r"(tailByte):"0"(tailByte):"$3","memory");
                    Level16SpawnField(record,unsigned char*,17)=tailByte;
                    Level16SpawnField(record,unsigned char*,16)=0;
                    break;
                case 0x3B:                          /* switch 1 */
                    record = Level16Spawnfunc_80056434(5);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     register int flags __asm__("$3");
                     register int value __asm__("$2");
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$3","$2","memory");
                     flags=Level16SpawnField(record,unsigned char*,1);
                     __asm__ __volatile__("" ::: "$2","memory");
                     value=1;
                     __asm__("" : "=r"(value) : "0"(value) : "memory");
                     Level16SpawnField(record,unsigned char*,3)=value;
                     value=16;
                     Level16SpawnField(record,unsigned char*,0)=kindSelector;
                     Level16SpawnField(record,unsigned char*,17)=value;
                     flags|=16;
                     Level16SpawnField(record,unsigned char*,1)=flags;
                     Level16Spawnfunc_8004F504(destination,source);
                     }
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,4);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=31;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=16;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     Level16SpawnField(record,unsigned short*,4)=component;
                     }
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=15;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=8;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     Level16SpawnField(record,unsigned short*,6)=component;
                     }
                    if(modeSelector==0) {
                        __asm__ __volatile__("" ::: "$2");
                        var_v0=0x2E0080C0;
                    } else {
                        __asm__ __volatile__("" ::: "$2");
                        var_v0=0x2E00C000;
                    }
                    __asm__("" : "=r"(var_v0) : "0"(var_v0));
                    Level16SpawnField(record,int*,12)=var_v0;
                    Level16SpawnField(record, unsigned char *, 0xA) = (unsigned char) ((Level16Spawnrand() & 0xF) + 0x14);
                    Level16SpawnField(record, unsigned char *, 0xB) = Level16Spawnrand();
                    Level16SpawnField(record, unsigned char *, 0x10) = 0;
                    Level16SpawnField(record, short *, 0x18) = (short) ((Level16Spawnrand() & 7) - 4);
                    Level16SpawnField(record, short *, 0x1A) = (short) (-2 - (Level16Spawnrand() & 7));
                    Level16SpawnField(record, short *, 0x1C) = (short) ((Level16Spawnrand() & 0xF) - 8);
                    break;
                case 0x42:                          /* switch 1 */
                    {register int local128 __asm__("$9");
                    record = Level16Spawnfunc_80056434(0);
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = (unsigned char) (Level16Spawnrand() & 0xF);
                    Level16SpawnField(record, unsigned char *, 3) = 1;
                    Level16SpawnField(record, short *, 4) = (short) ((((int) Level16SpawnField(reference, int *, 0) >> 2) + (Level16Spawnrand() & 0xF)) - 8);
                    Level16SpawnField(record, short *, 6) = (short) ((((int) Level16SpawnField(reference, int *, 4) >> 2) + (Level16Spawnrand() & 0xF)) - 8);
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(reference,int*,8);
                     __asm__("" : "=r"(random) : "0"(random) : "memory");
                     random&=15;
                     Level16SpawnField(record,short*,16)=0;
                     Level16SpawnField(record,short*,18)=0;
                     Level16SpawnField(record,short*,20)=0;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component) : "memory");
                     component>>=2;
                     component+=random;
                     component-=8;
                     Level16SpawnField(record,short*,8)=component;
                     }
                    {register int observed __asm__("$3")=Level16SpawnD_8006E344;
                     register int expected __asm__("$2");
                     __asm__ __volatile__("" ::: "$2","memory");
                     expected=4;
                     __asm__("" : "=r"(observed),"=r"(expected) : "0"(observed),"1"(expected));
                     if(observed==expected)var_v0_4=100;
                     else var_v0_4=2;
                     }
                    {register int one __asm__("$8")=1;
                     __asm__("" : "=r"(one),"=r"(var_v0_4) : "0"(one),"1"(var_v0_4));
                     Level16SpawnField(record,unsigned char*,10)=var_v0_4;
                     if(modeSelector==(unsigned char*)one)goto forceColor;
                     if(modeSelector!=0)goto selectColor;
                     if(Level16SpawnField(Level16SpawnD_80070328,int*,0x280)<3)goto selectColor;
forceColor:
                     __asm__ __volatile__("" ::: "$2");
                     goto colorCaseOne;
selectColor:;
}
                    temp_v1_2 = Level16Spawnrand() & 7;
                    switch (temp_v1_2) {            /* switch 3 */
                    case 0:                         /* switch 3 */
                        Level16SpawnField(record, unsigned char *, 0xC) = byte255;
                        Level16SpawnField(record, unsigned char *, 0xD) = 0;
                        Level16SpawnField(record, unsigned char *, 0xE) = 0;
                        break;
                    case 1:
colorCaseOne:
                        Level16SpawnField(record,unsigned char*,12)=byte255;
                        goto storeSecondColor;
                    case 2:
                        Level16SpawnField(record,unsigned char*,12)=0;
storeSecondColor:
                        Level16SpawnField(record,unsigned char*,13)=byte255;
                        Level16SpawnField(record,unsigned char*,14)=0;
                        break;
                    case 3:                         /* switch 3 */
                        Level16SpawnField(record, unsigned char *, 0xC) = 0;
                        Level16SpawnField(record, unsigned char *, 0xD) = byte255;
                        goto storeThirdColor;
                    case 4:                         /* switch 3 */
                        Level16SpawnField(record, unsigned char *, 0xC) = 0;
                        Level16SpawnField(record, unsigned char *, 0xD) = 0;
                        goto storeThirdColor;
                    case 5:                         /* switch 3 */
                        Level16SpawnField(record, unsigned char *, 0xC) = byte255;
                        Level16SpawnField(record, unsigned char *, 0xD) = 0;
                        goto storeThirdColor;
                    case 6:
                        {
                         local128=128;__asm__("" : "=r"(local128) : "0"(local128));
                         Level16SpawnField(record,unsigned char*,12)=byte255;
                         Level16SpawnField(record,unsigned char*,13)=local128;
                         }
                        Level16SpawnField(record, unsigned char *, 0xE) = 0;
                        break;
                    case 7:
                        {
                         commonByte8=128;__asm__("" : "=r"(commonByte8) : "0"(commonByte8));
                         Level16SpawnField(record,unsigned char*,12)=0;
                         Level16SpawnField(record,unsigned char*,13)=commonByte8;
                         }
storeThirdColor:
                        Level16SpawnField(record,unsigned char*,14)=byte255;
                        break;
                    }
                    Level16SpawnField(record, unsigned char *, 0xF) = 0x40;
                    break;
                    }
                case 0x46:                          /* switch 1 */
                    {register int local128 __asm__("$9");
                    record = Level16Spawnfunc_80056434(1);
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = (unsigned char) (Level16Spawnrand() & 0xF);
                    Level16SpawnField(record, unsigned char *, 3) = 1;
                    frame.spA0 = 0;
                    frame.spA1 = Level16Spawnrand();
                    frame.spA2 = Level16Spawnrand();
                    Level16Spawnfunc_8004EA90(&frame.spA0, &frame.spA8, 0);
                    frame.sp90 = (int)modeSelector;
                    frame.sp94 = 0;
                    frame.sp98 = 0;
                    Level16Spawnfunc_8004ED6C(&frame.spA8, (unsigned char *) &frame.sp90, (unsigned char *) &frame.sp90);
                    Level16SpawnField(record, unsigned short *, 4) = (unsigned short) ((int) Level16SpawnField(reference, int *, 0) >> 2);
                    Level16SpawnField(record, unsigned short *, 6) = (unsigned short) ((int) Level16SpawnField(reference, int *, 4) >> 2);
                    Level16SpawnField(record, unsigned short *, 8) = (unsigned short) ((int) Level16SpawnField(reference, int *, 8) >> 2);
                    {register int value __asm__("$2")=frame.sp90;
                     register int other __asm__("$3")=Level16SpawnField(record,unsigned short*,4);
      
                     value<<=1;
                     other+=value;
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     Level16SpawnField(record,short*,10)=other;
                     __asm__("" ::: "memory");
                     value=frame.sp94;
                     other=Level16SpawnField(record,unsigned short*,6);
                     value<<=1;
                     other+=value;
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     Level16SpawnField(record,short*,12)=other;
                     __asm__("" ::: "$2","memory");
                     other=frame.sp98;
                     value=2;
                     Level16SpawnField(record,unsigned char*,23)=value;
                     value=224;
                     Level16SpawnField(record,unsigned char*,16)=value;
                     value=192;
                     Level16SpawnField(record,unsigned char*,17)=value;
                     value=80;
                     Level16SpawnField(record,unsigned char*,19)=value;
                     __asm__("" : "=r"(other) : "0"(other) : "$2","memory");
                     value=Level16SpawnField(record,unsigned short*,8);
                     __asm__ __volatile__("" ::: "$9","memory");
 
                     local128=128;__asm__("" : "=r"(local128) : "0"(local128));
                     Level16SpawnField(record,unsigned char*,18)=0;
                     Level16SpawnField(record,unsigned char*,20)=byte255;
                     Level16SpawnField(record,unsigned char*,21)=byte255;
                     Level16SpawnField(record,unsigned char*,22)=local128;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value) : "memory");
                     other<<=1;
                     value+=other;
                     Level16SpawnField(record,short*,14)=value;
                     }
                    break;
                    }
                case 0x47:                          /* switch 1 */
                    record = Level16Spawnfunc_80056434(1);
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = (unsigned char) (Level16Spawnrand() & 7);
                    Level16SpawnField(record, unsigned char *, 3) = 1;
                    temp_v0_4 = (int) (((Level16Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC0 = temp_v0_4;
                    temp_v0_5 = (int) (((Level16Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC4 = temp_v0_5;
                    temp_v0_6 = (int) (((Level16Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC8 = temp_v0_6;
                    {register int value __asm__("$2");
                    register int other __asm__("$3");
                     other=Level16SpawnField(reference,int*,0);
                     value=frame.spC0;
                     other>>=2;
                     value<<=2;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                     other+=value;
                     Level16SpawnField(record,unsigned short*,4)=other;
                     __asm__("" ::: "$2","$3","memory");
                     other=Level16SpawnField(reference,int*,4);
                     value=frame.spC4;
                     other>>=2;
                     value<<=2;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                     other+=value;
                     Level16SpawnField(record,unsigned short*,6)=other;
                     __asm__("" ::: "$2","$3","memory");
                     other=Level16SpawnField(reference,int*,8);
                     value=frame.spC8;
                     other>>=2;
                     value<<=2;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                     other+=value;
                     Level16SpawnField(record,unsigned short*,8)=other;
                     __asm__("" ::: "$2","$3","memory");
                    }
                    {register int other __asm__("$3")=frame.spC0;
                     register int value __asm__("$2")=Level16SpawnField(record,unsigned short*,4);
                     register int finalComponent __asm__("$4");
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     value+=other;
                     Level16SpawnField(record,short*,10)=value;
                     __asm__("" ::: "$2","$3","memory");
                     other=frame.spC4;
                     value=Level16SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     value+=other;
                     Level16SpawnField(record,short*,12)=value;
                     __asm__("" ::: "$2","$3","$4","memory");
                     finalComponent=frame.spC8;
                     other=Level16SpawnField(record,unsigned short*,8);
                     __asm__ __volatile__("" ::: "$2","memory");
                     value=2;
                     Level16SpawnField(record,unsigned char*,23)=value;
                     value=224;
                     Level16SpawnField(record,unsigned char*,16)=value;
                     Level16SpawnField(record,unsigned char*,17)=value;
                     value=96;
                     Level16SpawnField(record,unsigned char*,18)=value;
                     Level16SpawnField(record,unsigned char*,20)=byte255;
                     Level16SpawnField(record,unsigned char*,21)=byte255;
                     Level16SpawnField(record,unsigned char*,22)=byte255;
                     value=80;
                     Level16SpawnField(record,unsigned char*,19)=value;
                     __asm__("" : "=r"(other),"=r"(finalComponent) : "0"(other),"1"(finalComponent) : "memory");
                     other+=finalComponent;
                     Level16SpawnField(record,short*,14)=other;
                     }
                    break;
                case 0x4E:                          /* switch 1 */
                    record = Level16Spawnfunc_80056434(0);
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = (unsigned char) (Level16Spawnrand() & 0x1F);
                    Level16SpawnField(record, unsigned char *, 3) = 1;
                    Level16Spawnfunc_8004F504(record + 4, reference);
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,4);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=63;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=32;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     Level16SpawnField(record,unsigned short*,4)=component;
                     }
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=63;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=32;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     Level16SpawnField(record,unsigned short*,6)=component;
                     }
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3")=Level16SpawnField(record,unsigned short*,8);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=63;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=32;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     Level16SpawnField(record,unsigned short*,8)=component;
                     }
                    Level16SpawnField(record, short *, 0x10) = (short) ((Level16Spawnrand() & 2) - 1);
                    Level16SpawnField(record, short *, 0x12) = (short) ((Level16Spawnrand() & 2) - 1);
                    Level16SpawnField(record, short *, 0x14) = (short) -(Level16Spawnrand() & 1);
                    tailByte=Level16Spawnrand();
                    tailByte|=128;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    Level16SpawnField(record,unsigned char*,12)=tailByte;
                    {register int random __asm__("$2")=Level16Spawnrand();
                     register int component __asm__("$3");
                     random&=127;
                     __asm__("" : "=r"(random) : "0"(random));
                     component=Level16SpawnField(record,unsigned char*,12);
                     __asm__("" : "=r"(random) : "0"(random) : "memory");
                     random+=96;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     Level16SpawnField(record,unsigned char*,13)=random;
                     if((unsigned int)component<(unsigned int)random)Level16SpawnField(record,unsigned char*,13)=component;
                     }
                    Level16SpawnField(record, unsigned char *, 0xE) = (unsigned char) ((Level16Spawnrand() & 0x3F) + 0x40);
                    Level16SpawnField(record, unsigned char *, 0xF) = 0x40;
                    Level16SpawnField(record, unsigned char *, 0xA) = 2;
                    break;
                case 0x4F:                          /* switch 1 */
                    {register int local128 __asm__("$8");
                    record = Level16Spawnfunc_80056434(1);
                    Level16SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level16SpawnField(record, unsigned char *, 2) = (unsigned char) (Level16Spawnrand() & 0xF);
                    Level16SpawnField(record, unsigned char *, 3) = 1;
                    Level16Spawnfunc_8004F504(record + 0xA, reference);
                    {register void *vector __asm__("$16");
                     __asm__ volatile("" ::: "$16");
                     vector=(void*)&frame.spC0;
                     __asm__("" : "=r"(vector) : "0"(vector));
                    Level16Spawnfunc_8004F194(vector, reference, modeSelector);
                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3");
                    component=*(volatile int*)&frame.spC0;
                     __asm__ volatile("" : "=r"(random), "=r"(component) : "0"(random), "1"(component) : "memory");
                     random&=0x3F;
                     component-=0x20;
                     component+=random;
                     frame.spC0=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3")=frame.spC4;
                     
                     random&=0x3F;
                     
                     component-=0x20;
                     
                     component+=random;
                     frame.spC4=component;
                     }

                    {register int random __asm__("$2")=Level16Spawnrand();
                    register int component __asm__("$3");
                     register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=vector;
                     
                     component=frame.spC8;
                     
                     random&=0x7F;
                     
                     component-=0x40;
                     
                     component+=random;
                     frame.spC8=component;
                     Level16Spawnfunc_8004F504(destination,source);
                     }
                    }
                    Level16SpawnField(record, unsigned char *, 0x17) = 2;
                    tailByte=Level16Spawnrand();
                    tailByte|=192;
                    
                    Level16SpawnField(record,unsigned char*,16)=tailByte;
                    Level16SpawnField(record, unsigned char *, 0x11) = (unsigned char) ((Level16Spawnrand() & 0x3F) - 0x60);
                    Level16SpawnField(record, unsigned char *, 0x12) = 0;
                    tailByte=Level16Spawnrand();
                    tailByte|=224;
                    
                    Level16SpawnField(record,unsigned char*,20)=tailByte;
                    tailByte=Level16Spawnrand();
                    tailByte|=224;
                    
                    local128=128;
                    Level16SpawnField(record,unsigned char*,21)=tailByte;
                    {
                    
                    Level16SpawnField(record, unsigned char *, 0x16) = local128;
                    }
                    Level16SpawnField(record, unsigned char *, 0x13) = 0x50;
                    break;
                    }
                case 0x54:
                    record=Level16Spawnfunc_80056434(0);
                    Level16SpawnField(record,unsigned char*,0)=kindSelector;
                    tailByte=Level16Spawnrand();tailByte&=15;
                    Level16SpawnField(record,unsigned char*,2)=tailByte;
                    Level16SpawnField(record,unsigned char*,3)=1;
                    Level16SpawnField(record,unsigned short*,4)=Level16SpawnField(reference,int*,0)>>2;
                    Level16SpawnField(record,unsigned short*,6)=Level16SpawnField(reference,int*,4)>>2;
                    Level16SpawnField(record,unsigned short*,8)=Level16SpawnField(reference,int*,8)>>2;
                    tailByte=Level16Spawnfunc_8003636C(-3,3);
                    Level16SpawnField(record,unsigned short*,16)=tailByte;
                    tailByte=Level16Spawnfunc_8003636C(-3,3);
                    Level16SpawnField(record,unsigned short*,18)=tailByte;
                    tailByte=Level16Spawnfunc_8003636C(-3,3);
                    Level16SpawnField(record,unsigned short*,20)=tailByte;
                    Level16SpawnField(record,unsigned char*,10)=2;
                    Level16SpawnField(record,unsigned char*,12)=Level16SpawnField(modeSelector,unsigned char*,0);
                    Level16SpawnField(record,unsigned char*,13)=Level16SpawnField(modeSelector,unsigned char*,1);
                    {register int color3 __asm__("$3")=Level16SpawnField(modeSelector,unsigned char*,2);
                     tailByte=64;Level16SpawnField(record,unsigned char*,15)=tailByte;
                     Level16SpawnField(record,unsigned char*,14)=color3;
                    }
                    break;
                }
            __asm__ volatile("" : "=r"(byte255):"0"(byte255):"memory");
            {register int stride8 __asm__("$9")=frame.spF0;
             register int iteration9 __asm__("$8")=frame.spD8;
             __asm__("" : "=r"(stride8),"=r"(iteration9):"0"(stride8),"1"(iteration9));
             stride8+=4;frame.spF0=stride8;
             stride8=frame.spD0;
             __asm__("" : "=r"(stride8),"=r"(iteration9):"0"(stride8),"1"(iteration9));
             iteration9+=1;var_v0=iteration9<stride8;
             __asm__ volatile("" : "=r"(var_v0),"=r"(iteration9):"0"(var_v0),"1"(iteration9):"$3","memory");
             frame.spD8=iteration9;
            }
        } while (var_v0);
    }
    return record;
}

#undef Level16SpawnField

#undef Level16SpawnHigh



