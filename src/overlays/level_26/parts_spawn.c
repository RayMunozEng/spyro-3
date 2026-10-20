#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level26SpawnHigh(a,b) ({ int high; __asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory"); high; })
extern unsigned char Level26SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level26SpawnColor2[] __asm__("D_80066BAC");
#define Level26SpawnField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level26Spawnfunc_8004EA90(void*,void*,int) __asm__("func_8004EA90");
int Level26Spawnfunc_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Level26Spawnfunc_8004F110(void*,int) __asm__("func_8004F110");
int Level26Spawnfunc_8004F178(void*,void*) __asm__("func_8004F178");
int Level26Spawnfunc_8004F194(void*,void*,void*) __asm__("func_8004F194");
int Level26Spawnfunc_8004F1FC(void*,void*,int) __asm__("func_8004F1FC");
int Level26Spawnfunc_8004F504(void*,void*) __asm__("func_8004F504");
void* Level26Spawnfunc_80056434(int) __asm__("func_80056434");
int Level26Spawnfunc_8003636C(int,int) __asm__("func_8003636C");
int Level26Spawnrand(void) __asm__("rand");
extern unsigned char Level26SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level26SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level26SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level26SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level26SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level26SpawnD_80070328[] __asm__("D_80070328");
extern int Level26SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original USA Rev0 level26 instructions
 * and dispatch: build/sibling4154.func_level_26_80087A14.json.
 * Raw units, helper contracts and cadence remain unresolved. */
void *func_level_26_80087A14(int entryCount, int kind, void *input, void *mode) {
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
        unsigned char sp70,sp71,sp72,pad73;
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
        int spA0;
        int spA4;
        int spA8;
        int spAC;
        int * volatile spB0;
        int spB4;
        int spB8;
        int spBC;
        volatile int spC0;
        int spC4;
        volatile int spC8;
        int spCC;
    } frame;
    register int kindSelector __asm__("$21")=kind;
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
    int byte128;
    register int byte255 __asm__("$23");
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailByte __asm__("$2");
    register int commonByte __asm__("$9");
    register int commonByte9 __asm__("$8");
    register int zeroColor __asm__("$8");
    register int zeroFour __asm__("$9");
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
    frame.spA0 = entryCount;
    frame.spA8 = 0;
    if (entryCount > 0) {
        byte128=128;
        __asm__("" : "=r"(byte128):"0"(byte128));
        {register int *vectorBase __asm__("$8")=&frame.sp30;
         __asm__("" : "=r"(vectorBase) : "0"(vectorBase) : "$23");
         byte255=255;
         frame.spB0=vectorBase;
         }
        frame.spC0 = 0;
        frame.spC8 = 0;
        do {
                switch (kindSelector) {                     /* switch 1 */
                case 0x0:                           /* switch 1 */
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     register int one __asm__("$9");
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$8");
                     one=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(one) : "0"(destination),"1"(source),"2"(one) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = one;
                    Level26Spawnfunc_8004F504(destination, source);
                    }
                    Level26Spawnfunc_8004F504(record + 0x18, modeSelector);
                    Level26SpawnField(record, short *, 0x1E) = 0;
                    Level26SpawnField(record, unsigned char *, 0xA) = 0x18;
                    tailByte = Level26Spawnrand();
                    {
                     __asm__ volatile("" : "=r"(byte128),"=r"(tailByte) : "0"(byte128),"1"(tailByte) : "$3","memory");
                    __asm__ volatile("" : "=r"(tailByte),"=r"(byte128) : "0"(tailByte),"1"(byte128) : "memory");
                    zeroColor=46;
                    __asm__("" : "=r"(zeroColor),"=r"(tailByte):"0"(zeroColor),"1"(tailByte):"memory");
                    zeroFour=4;
                    __asm__("" : "=r"(zeroFour):"0"(zeroFour):"memory");
                    Level26SpawnField(record, unsigned char *, 0xB) = tailByte;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");

                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");

                    Level26SpawnField(record, unsigned char *, 0xC) = byte128;
                    Level26SpawnField(record, unsigned char *, 0xD) = byte128;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3","memory");
                    Level26SpawnField(record, unsigned char *, 0xE) = byte128;
                    }

                    __asm__ volatile("" : "=r"(zeroColor):"0"(zeroColor):"memory");
                    Level26SpawnField(record,unsigned char*,15)=zeroColor;
                    Level26SpawnField(record,unsigned char*,17)=zeroFour;
                    Level26SpawnField(record,unsigned char*,16)=0;
                    break;
                case 0x1:                           /* switch 1 */
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    Level26Spawnfunc_8004F504(destination, source);
                    }
                    Level26Spawnfunc_8004F504(record + 0x18, modeSelector);
                    Level26SpawnField(record, short *, 0x1E) = 0;
                    Level26SpawnField(record, unsigned char *, 0xA) = 0x10;
                    tailByte=Level26Spawnrand();
                    Level26SpawnField(record, unsigned char *, 0xB) = tailByte;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    tailByte=96;
                    commonByte9=46;
                    __asm__("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"memory");
                    Level26SpawnField(record, unsigned char *, 0xC) = tailByte;
                    Level26SpawnField(record, unsigned char *, 0xD) = tailByte;

                    goto initializeE;
                case 0x2:
                    record=Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source):"0"(destination),"1"(source):"$2");
                     tailByte=1;
                     __asm__("" : "=r"(tailByte),"=r"(destination),"=r"(source):"0"(tailByte),"1"(destination),"2"(source));
                     Level26SpawnField(record,unsigned char*,0)=kindSelector;
                     Level26SpawnField(record,unsigned char*,2)=0;
                     Level26SpawnField(record,unsigned char*,3)=tailByte;
                     Level26Spawnfunc_8004F504(destination,source);
                     tailByte=Level26Spawnrand();tailByte&=63;tailByte-=32;frame.sp10=tailByte;
                     tailByte=Level26Spawnrand();
                     destination=record+24;source=&frame.sp10;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte):"0"(destination),"1"(source),"2"(tailByte));
                     tailByte&=63;tailByte-=32;frame.sp14=tailByte;frame.sp18=16;
                     Level26Spawnfunc_8004F504(destination,source);
                    }
                    tailByte=32;
                    Level26SpawnField(record,unsigned short*,30)=0;
                    Level26SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=Level26Spawnrand();
                    commonByte=46;
                    __asm__("" : "=r"(commonByte),"=r"(tailByte):"0"(commonByte),"1"(tailByte):"memory");
                    Level26SpawnField(record,unsigned char*,11)=tailByte;
                    tailByte=2;
                    Level26SpawnField(record,unsigned char*,12)=byte128;
                    Level26SpawnField(record,unsigned char*,13)=byte128;
                    Level26SpawnField(record,unsigned char*,14)=byte128;
                    Level26SpawnField(record,unsigned char*,15)=commonByte;
                    goto initializeByte11;
                case 0x9:                           /* switch 1 */
                    record = Level26Spawnfunc_80056434(2);
                    {register void *playerVector __asm__("$16")=&frame.sp20;
                     register void *destination __asm__("$4")=playerVector;
                     register unsigned char *player __asm__("$17");
                     register void *source __asm__("$5");
                     __asm__("" : "=r"(destination) : "0"(destination) : "$17");
                     player=Level26SpawnD_80070328;
                     source=player;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(player) : "0"(destination),"1"(source),"2"(player) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(tailByte),"=r"(destination),"=r"(source),"=r"(player) : "0"(tailByte),"1"(destination),"2"(source),"3"(player) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    Level26Spawnfunc_8004F178(destination,source);
                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp20;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x7E;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=0x3F;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     frame.sp20=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
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
                     Level26Spawnfunc_8004F504(destination,source);
                     }
                    Level26Spawnfunc_8004F178(playerVector, player + 0x98);
                    Level26Spawnfunc_8004F110(playerVector, 6);
                    Level26Spawnfunc_8004F504(record + 0x18, playerVector);
                    }
                    Level26SpawnField(record, short *, 0x1E) = 0;
                    Level26SpawnField(record, unsigned char *, 0xA) = 0x18;
                    tailByte = Level26Spawnrand();
                    {
                     __asm__ volatile("" : "=r"(byte128),"=r"(tailByte) : "0"(byte128),"1"(tailByte) : "$4","memory");
                    __asm__ volatile("" : "=r"(tailByte),"=r"(byte128) : "0"(tailByte),"1"(byte128) : "memory");
                    commonByte9=46;
                    __asm__("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"memory");
                    Level26SpawnField(record, unsigned char *, 0xB) = tailByte;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");

                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    tailByte=4;
                    Level26SpawnField(record, unsigned char *, 0xC) = byte128;
                    Level26SpawnField(record, unsigned char *, 0xD) = byte128;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$4","memory");
                    Level26SpawnField(record, unsigned char *, 0xE) = byte128;
                    }

                    Level26SpawnField(record,unsigned char*,15)=commonByte9;
                    goto initializeByte11;
                case 0xA:                           /* switch 1 */
                    record = Level26Spawnfunc_80056434(3);
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=Level26SpawnD_80070328;
                     tailByte=Level26Spawnrand();
                     destination=record+4;
                     source=Level26SpawnD_80070328;
                     tailByte&=31;
                     __asm__("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                     Level26SpawnField(record,unsigned char*,2)=tailByte;
                     __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                     tailByte=1;
                     Level26SpawnField(record,unsigned char*,3)=tailByte;
                     Level26Spawnfunc_8004F504(destination,source);
                     }
                    {register int factor __asm__("$4")=0x66660000;
                     register int value __asm__("$2");
                     register int count __asm__("$9");
                     register int iteration8 __asm__("$8");
                     register int dividend __asm__("$3");
                     register int productHigh __asm__("hi");
                     register int color __asm__("$4");
                     value=24;
                     __asm__("" : "=r"(factor),"=r"(value) : "0"(factor),"1"(value));
                     Level26SpawnField(record,unsigned char*,10)=value;
                     value=15;
                     Level26SpawnField(record,unsigned char*,11)=value;
                     __asm__("" : "=r"(factor) : "0"(factor) : "memory");
                     count=frame.spA0;
                     iteration8=frame.spA8;
                     __asm__("" : "=r"(count),"=r"(iteration8):"0"(count),"1"(iteration8));
                     factor|=0x6667;
                     dividend=count-iteration8;
                     count=frame.spC8;
                     __asm__("" : "=r"(count),"=r"(dividend) : "0"(count),"1"(dividend));
                     dividend<<=12;
                     value=*(Level26SpawnD_80066BAC+count);
                     __asm__("" : "=r"(dividend),"=r"(factor) : "0"(dividend),"1"(factor) : "memory");
                     productHigh=Level26SpawnHigh(dividend,factor);
                     Level26SpawnField(record,unsigned char*,12)=value;
                     value=*(Level26SpawnColor1+1+count);
                     dividend>>=31;
                     Level26SpawnField(record,unsigned char*,13)=value;
                     color=*(Level26SpawnColor2+2+count);
                     value=44;
                     Level26SpawnField(record,unsigned char*,15)=value;
                     value=4;
                     Level26SpawnField(record,unsigned char*,17)=value;
                     Level26SpawnField(record,unsigned char*,16)=0;
                     Level26SpawnField(record,unsigned char*,14)=color;
                     __asm__("" : "=h"(productHigh),"=r"(dividend) : "0"(productHigh),"1"(dividend) : "memory");
                     iteration8=productHigh;
                     __asm__("" : "=r"(iteration8) : "0"(iteration8));
                     value=(iteration8>>1)-dividend;
                     Level26SpawnField(record,short*,24)=value;
                    }
                    break;
                case 0xC:                           /* switch 1 */
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=reference+32;
                     register void *table __asm__("$5");
                     register int offset __asm__("$9");
                     register void *vector __asm__("$6");
                     register int value __asm__("$2");
                     __asm__("" : "=r"(destination) : "0"(destination) : "$5","$8","$6","$2","memory");
                     table=Level26SpawnD_80066A48;
                     offset=frame.spC0;
                     vector=frame.spB0;
                     __asm__("" : "=r"(table),"=r"(offset),"=r"(vector) : "0"(table),"1"(offset),"2"(vector) : "$2","memory");
                     value=1;
                     Level26SpawnField(record,unsigned char*,3)=value;
                     value=4;
                     Level26SpawnField(record,unsigned char*,0)=kindSelector;
                     Level26SpawnField(record,unsigned char*,17)=value;
                     __asm__("" : "=r"(destination),"=r"(table),"=r"(offset),"=r"(vector) : "0"(destination),"1"(table),"2"(offset),"3"(vector) : "memory");
                     table=(void*)(offset+(int)table);
                     Level26Spawnfunc_8004ED6C(destination,table,vector);
                     }
                    if (({register int observed __asm__("$2")=Level26SpawnField(reference,short*,54);
                         register int expected __asm__("$8");
                         __asm__ __volatile__("" ::: "$8","memory");
                         expected=0x17D;
                         __asm__("" : "=r"(expected) : "0"(expected));
                         observed==expected;
                         })) {
                        Level26Spawnfunc_8004F1FC(frame.spB0, frame.spB0, 3);
                    }
                    Level26Spawnfunc_8004F194(frame.spB0, frame.spB0, reference + 0xC);
                    if (modeSelector == (unsigned char *)5) {
                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp30;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x1FF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x100;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp30=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp34;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0x1FF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x100;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp34=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
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
                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp30;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp30=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp34;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp34=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
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
                    if (Level26SpawnField(reference, short *, 0x36) == 0xB6) {
                        frame.sp38 += 0x200;
                    }
                    Level26Spawnfunc_8004F504(record + 4, frame.spB0);
                    Level26SpawnField(record, int *, 0xC) = (int) *(int*)(Level26SpawnD_80066A28 + ((int) modeSelector * 4));
                    if (({register int observed __asm__("$2")=Level26SpawnField(reference,short*,54);
                         register int expected __asm__("$9");
                         __asm__ __volatile__("" ::: "$8","memory");
                         expected=0x17D;
                         __asm__("" : "=r"(expected) : "0"(expected));
                         observed==expected;
                         })) {
                        var_v0_2 = (Level26Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level26Spawnrand() & 7) + 0x20;
                    }
                    Level26SpawnField(record, unsigned char *, 0xA) = var_v0_2;
                    tailByte=Level26Spawnrand();
                    {register void *destination __asm__("$4")=record+24;
                     register int offset __asm__("$8")=frame.spC0;
                     register void *source __asm__("$5");
                     __asm__("" : "=r"(destination) : "0"(destination) : "$5","memory");
                     source=Level26SpawnD_80066A48;
                     __asm__("" : "=r"(destination),"=r"(offset),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(offset),"2"(source),"3"(tailByte) : "memory");
                     Level26SpawnField(record,unsigned char*,11)=tailByte;
                     Level26SpawnField(record,unsigned char*,16)=0;
                     __asm__("" : "=r"(destination),"=r"(offset),"=r"(source) : "0"(destination),"1"(offset),"2"(source) : "memory");
                     source=(void*)(offset+(int)source);
                     Level26Spawnfunc_8004F504(destination,source);
                     }
                    Level26SpawnField(record, unsigned short *, 0x18) = (unsigned short) (((int) (Level26SpawnField(record, unsigned short *, 0x18) << 0x10) >> 0x12) - 4 + (Level26Spawnrand() & 7));
                    Level26SpawnField(record, unsigned short *, 0x1A) = (unsigned short) (((int) (Level26SpawnField(record, unsigned short *, 0x1A) << 0x10) >> 0x12) - 4 + (Level26Spawnrand() & 7));
                    Level26SpawnField(record, unsigned short *, 0x1C) = (unsigned short) (((int) (Level26SpawnField(record, unsigned short *, 0x1C) << 0x10) >> 0x12) - 4 + (Level26Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    Level26Spawnfunc_8004F504(destination, source);
                    }
                    Level26Spawnfunc_8004F504(record + 0x18, modeSelector);
                    tailByte=24;
                    Level26SpawnField(record,short*,0x1E)=0;
                    Level26SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=Level26Spawnrand();
                    commonByte=46;
                    __asm__ volatile("" : "=r"(commonByte),"=r"(tailByte):"0"(commonByte),"1"(tailByte):"$3","memory");
                    Level26SpawnField(record,unsigned char*,11)=tailByte;
                    tailByte=4;
                    Level26SpawnField(record,unsigned char*,12)=byte255;
                    Level26SpawnField(record,unsigned char*,13)=byte255;
                    Level26SpawnField(record,unsigned char*,14)=0;
                    __asm__ volatile("" : "=r"(commonByte),"=r"(tailByte):"0"(commonByte),"1"(tailByte):"$4","memory");
                    Level26SpawnField(record,unsigned char*,15)=commonByte;
                    goto initializeByte11;
                case 0x13:
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    Level26Spawnfunc_8004F504(destination, source);
                    }
                    Level26Spawnfunc_8004F504(record + 0x18, modeSelector);
                    tailByte=32;
                    Level26SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=Level26Spawnrand();
                    commonByte9=46;
                    __asm__ volatile("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"$3","memory");
                    Level26SpawnField(record,unsigned char*,11)=tailByte;
                    tailByte=4;
                    Level26SpawnField(record,unsigned char*,12)=byte255;
                    Level26SpawnField(record,unsigned char*,13)=byte255;
                    __asm__ volatile("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"$4","memory");
                    Level26SpawnField(record,unsigned char*,14)=0;

                    goto initializeTrailingBytes;
                case 0x21:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(2);
                    tailByte=1;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    if (modeSelector == 0) {
                        {register void *destination __asm__("$4");
                         scratch16=(int)&frame.sp50;
                         destination=(void*)scratch16;
                         __asm__("" : "=r"(scratch16),"=r"(destination) : "0"(scratch16),"1"(destination) : "$17");
                         temp_s1 = Level26SpawnD_80070328 + 0x98;
                         Level26Spawnfunc_8004F178(destination,temp_s1);
                         }
                        Level26Spawnfunc_8004F110((void*)scratch16, 6);
                        Level26Spawnfunc_8004F178(&frame.sp40, temp_s1 - 0x98);
                        frame.sp48 -= 0x164;
                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp40;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=0xFF;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=0x80;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     frame.sp40=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
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
                        register int one __asm__("$9")=1;
                        register int two __asm__("$2");
                        __asm__("" : "=r"(one) : "0"(one));
                        if(modeSelector == (unsigned char*)one) {
                        temp_s1_2 = Level26SpawnD_80070328 + 0x30;
                        frame.sp40 = 0x164;
                        frame.sp44 = 0;
                        frame.sp48 = 0;
                        Level26Spawnfunc_8004ED6C(temp_s1_2, &frame.sp40, &frame.sp40);
                        Level26Spawnfunc_8004F194(&frame.sp40, &frame.sp40, temp_s1_2 - 0x30);
                        scratch19 = 0x40;
                        frame.sp50 = -(Level26Spawnrand() & 7);
                        {register int random __asm__("$2")=Level26Spawnrand();
                         register int component __asm__("$3");
                         register void *destination __asm__("$4")=temp_s1_2;
                         register void *vector __asm__("$5")=&frame.sp50;
                         register int iteration8 __asm__("$8")=frame.spA8;
                         register int angle __asm__("$7");
                         register void *output __asm__("$6")=vector;
                         __asm__("" : "=r"(destination),"=r"(vector),"=r"(angle),"=r"(output) : "0"(destination),"1"(vector),"2"(angle),"3"(output) : "memory");
                         __asm__("" : "=r"(iteration8):"0"(iteration8));
                         random&=15;angle=iteration8<<6;
                         component=*(unsigned short*)(Level26SpawnD_80065920+angle);
                         __asm__("" : "=r"(random) : "0"(random) : "memory");
                         random-=8;
                         __asm__("" : "=r"(random) : "0"(random));
                         component=(component<<16)>>23;
                         component-=random;
                         frame.sp54=component;
                         random=*(unsigned short*)(Level26SpawnD_800658A0+angle);
                         random=(random<<16)>>23;
                         frame.sp58=random;
                         Level26Spawnfunc_8004ED6C(destination,vector,output);
                         }
                        var_a0 = record + 4;
                        goto finishMode;
                        } else {two=2;__asm__("" : "=r"(two):"0"(two));scratch16=5;if(modeSelector == (unsigned char*)two) {
                        {register int iteration8 __asm__("$9")=frame.spA8;
                         __asm__("" : "=r"(iteration8):"0"(iteration8):"$17","$16","$19","memory");
                         scratch17=iteration8<<5;
                         __asm__("" : "=r"(scratch17):"0"(scratch17):"$16","$19","memory");
                        }
                        scratch16 = 6;
                        scratch19 = 0x30;
                        goto updateSharedVector;
                        } else {
                        {register int iteration9 __asm__("$8")=frame.spA8;
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
                        Level26Spawnfunc_8004F178(&frame.sp40,Level26SpawnD_80070328);
                        {register short *first __asm__("$5")=(short*)Level26SpawnD_80065920;
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
                         value=(int)Level26SpawnD_800658A0;
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
                    Level26Spawnfunc_8004F504(var_a0, &frame.sp40);
                    Level26Spawnfunc_8004F504(record + 0x18, &frame.sp50);
                    Level26SpawnField(record, short *, 0x1E) = 0;
                    Level26SpawnField(record, unsigned char *, 0xA) = 0x10;
                    tailByte=Level26Spawnrand();
                    commonByte=46;
                    __asm__("" : "=r"(commonByte),"=r"(tailByte) : "0"(commonByte),"1"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0xB) = tailByte;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    tailByte=4;
                    Level26SpawnField(record, unsigned char *, 0xC) = scratch19;
                    Level26SpawnField(record, unsigned char *, 0xD) = scratch19;
                    Level26SpawnField(record, unsigned char *, 0xE) = scratch19;
                    __asm__ volatile("" : "=r"(commonByte):"0"(commonByte):"$3","memory");
                    Level26SpawnField(record,unsigned char*,15)=commonByte;
                    goto initializeByte11;
                case 0x37:
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    Level26Spawnfunc_8004F504(destination, source);
                    }
                    Level26Spawnfunc_8004F504(record + 0x18, modeSelector);
                    tailByte=64;
                    Level26SpawnField(record, unsigned char *, 0xA) = tailByte;
                    tailByte=Level26Spawnrand();
                    commonByte9=46;
                    __asm__("" : "=r"(commonByte9),"=r"(tailByte) : "0"(commonByte9),"1"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0xB) = tailByte;
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    tailByte=4;
                    Level26SpawnField(record, unsigned char *, 0xC) = byte255;
                    Level26SpawnField(record, unsigned char *, 0xD) = byte255;
                    Level26SpawnField(record, unsigned char *, 0xE) = 0;
                    goto initializeTrailingBytes;
                case 0x38:
                    record=Level26Spawnfunc_80056434(2);
                    tailByte=1;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    Level26SpawnField(record,unsigned char*,0)=kindSelector;
                    Level26SpawnField(record,unsigned char*,2)=0;
                    Level26SpawnField(record,unsigned char*,3)=tailByte;
                    Level26SpawnField(record,unsigned short*,4)=Level26SpawnField(reference,unsigned short*,4);
                    Level26SpawnField(record,unsigned short*,6)=Level26SpawnField(reference,unsigned short*,6);
                    Level26SpawnField(record,unsigned short*,8)=Level26SpawnField(reference,unsigned short*,8);
                    Level26SpawnField(record,int*,24)=Level26SpawnField(reference,int*,24);
                    Level26SpawnField(record,int*,28)=Level26SpawnField(reference,int*,28);
                    tailByte=Level26SpawnField(reference,unsigned char*,10);
                    __asm__("" : "=r"(tailByte) : "0"(tailByte));
                    Level26SpawnField(record,unsigned char*,10)=tailByte;
                    __asm__ volatile("" : : : "memory");
                    { register unsigned int sourceByte __asm__("$2")=Level26SpawnField(reference,unsigned char*,11);
                      __asm__("" : "=r"(sourceByte) : "0"(sourceByte) : "memory");
                      commonByte=46;
                      Level26SpawnField(record,volatile unsigned char*,12)=0;
                      Level26SpawnField(record,volatile unsigned char*,13)=0;
                      Level26SpawnField(record,volatile unsigned char*,14)=0;
                      Level26SpawnField(record,volatile unsigned char*,15)=commonByte;
                      Level26SpawnField(record,volatile unsigned char*,17)=0;
                      Level26SpawnField(record,volatile unsigned char*,16)=0;
                      Level26SpawnField(record,unsigned char*,11)=sourceByte;
                    }
                    break;
                case 0x3B:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(5);
                    {register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=reference;
                     register int flags __asm__("$3");
                     register int value __asm__("$2");
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$3","$2","memory");
                     flags=Level26SpawnField(record,unsigned char*,1);
                     __asm__ __volatile__("" ::: "$2","memory");
                     value=1;
                     __asm__("" : "=r"(value) : "0"(value) : "memory");
                     Level26SpawnField(record,unsigned char*,3)=value;
                     value=16;
                     Level26SpawnField(record,unsigned char*,0)=kindSelector;
                     Level26SpawnField(record,unsigned char*,17)=value;
                     flags|=16;
                     Level26SpawnField(record,unsigned char*,1)=flags;
                     Level26Spawnfunc_8004F504(destination,source);
                     }
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3")=Level26SpawnField(record,unsigned short*,4);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=31;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=16;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     Level26SpawnField(record,unsigned short*,4)=component;
                     }
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3")=Level26SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=15;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=8;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=random;
                     Level26SpawnField(record,unsigned short*,6)=component;
                     }
                    if(modeSelector==0) {
                        __asm__ __volatile__("" ::: "$2");
                        var_v0=0x2E0080C0;
                    } else {
                        __asm__ __volatile__("" ::: "$2");
                        var_v0=0x2E00C000;
                    }
                    __asm__("" : "=r"(var_v0) : "0"(var_v0));
                    Level26SpawnField(record,int*,12)=var_v0;
                    Level26SpawnField(record, unsigned char *, 0xA) = (unsigned char) ((Level26Spawnrand() & 0xF) + 0x14);
                    Level26SpawnField(record, unsigned char *, 0xB) = Level26Spawnrand();
                    Level26SpawnField(record, unsigned char *, 0x10) = 0;
                    Level26SpawnField(record, short *, 0x18) = (short) ((Level26Spawnrand() & 7) - 4);
                    Level26SpawnField(record, short *, 0x1A) = (short) (-2 - (Level26Spawnrand() & 7));
                    Level26SpawnField(record, short *, 0x1C) = (short) ((Level26Spawnrand() & 0xF) - 8);
                    break;
                case 0x3F:
                    record = Level26Spawnfunc_80056434(2);
                    {register void *destination __asm__("$4")=record+4;
                    register void *source __asm__("$5")=reference;
                     __asm__("" : "=r"(destination),"=r"(source) : "0"(destination),"1"(source) : "$2");
                     tailByte=1;
                     __asm__ volatile("" : "=r"(destination),"=r"(source),"=r"(tailByte) : "0"(destination),"1"(source),"2"(tailByte) : "memory");
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = 0;
                    Level26SpawnField(record, unsigned char *, 3) = tailByte;
                    Level26Spawnfunc_8004F504(destination, source);
                    }
                    Level26Spawnfunc_8004F504(record + 0x18, modeSelector);
                    tailByte=24;
                    Level26SpawnField(record,short*,30)=0;
                    Level26SpawnField(record,unsigned char*,10)=tailByte;
                    tailByte=Level26Spawnrand();
                    Level26SpawnField(record,unsigned char*,11)=tailByte;
                    tailByte=64;Level26SpawnField(record,unsigned char*,12)=tailByte;
                    tailByte=32;Level26SpawnField(record,unsigned char*,13)=tailByte;
                    tailByte=16;commonByte9=46;
                    __asm__("" : "=r"(tailByte),"=r"(commonByte9):"0"(tailByte),"1"(commonByte9):"memory");
initializeE:
                    __asm__ volatile("" : "=r"(tailByte):"0"(tailByte):"$3","memory");
                    Level26SpawnField(record,unsigned char*,14)=tailByte;
                    tailByte=4;
initializeTrailingBytes:
                    __asm__ volatile("" : "=r"(commonByte9),"=r"(tailByte):"0"(commonByte9),"1"(tailByte):"$3","memory");
                    Level26SpawnField(record,unsigned char*,15)=commonByte9;
initializeByte11:
                    Level26SpawnField(record,unsigned char*,17)=tailByte;
                    Level26SpawnField(record,unsigned char*,16)=0;
                    break;
                case 0x42:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(0);
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = (unsigned char) (Level26Spawnrand() & 0xF);
                    Level26SpawnField(record, unsigned char *, 3) = 1;
                    Level26SpawnField(record, short *, 4) = (short) ((((int) Level26SpawnField(reference, int *, 0) >> 2) + (Level26Spawnrand() & 0xF)) - 8);
                    Level26SpawnField(record, short *, 6) = (short) ((((int) Level26SpawnField(reference, int *, 4) >> 2) + (Level26Spawnrand() & 0xF)) - 8);
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3")=Level26SpawnField(reference,int*,8);
                     __asm__("" : "=r"(random) : "0"(random) : "memory");
                     random&=15;
                     Level26SpawnField(record,short*,16)=0;
                     Level26SpawnField(record,short*,18)=0;
                     Level26SpawnField(record,short*,20)=0;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component) : "memory");
                     component>>=2;
                     component+=random;
                     component-=8;
                     Level26SpawnField(record,short*,8)=component;
                     }
                    {register int observed __asm__("$2")=Level26SpawnD_8006E344;
                     register int expected __asm__("$9");
                     __asm__ __volatile__("" : "=r"(observed):"0"(observed):"$9","memory");
                     expected=4;
                     __asm__("" : "=r"(observed),"=r"(expected) : "0"(observed),"1"(expected));
                     if(observed==expected)var_v0_4=100;
                     else var_v0_4=2;
                     }
                    {register int one __asm__("$8")=1;
                     __asm__("" : "=r"(one),"=r"(var_v0_4) : "0"(one),"1"(var_v0_4));
                     Level26SpawnField(record,unsigned char*,10)=var_v0_4;
                     if(modeSelector==(unsigned char*)one)goto forceColor;
                     if(modeSelector!=0)goto selectColor;
                     if(Level26SpawnField(Level26SpawnD_80070328,int*,0x280)<3)goto selectColor;
forceColor:
                     __asm__ __volatile__("" ::: "$2");
                     goto colorCaseOne;
selectColor:;
}
                    temp_v1_2 = Level26Spawnrand() & 7;
                    switch (temp_v1_2) {            /* switch 3 */
                    case 0:                         /* switch 3 */
                        Level26SpawnField(record, unsigned char *, 0xC) = byte255;
                        Level26SpawnField(record, unsigned char *, 0xD) = 0;
                        Level26SpawnField(record, unsigned char *, 0xE) = 0;
                        break;
                    case 1:
colorCaseOne:
                        Level26SpawnField(record,unsigned char*,12)=byte255;
                        goto storeSecondColor;
                    case 2:
                        Level26SpawnField(record,unsigned char*,12)=0;
storeSecondColor:
                        Level26SpawnField(record,unsigned char*,13)=byte255;
                        Level26SpawnField(record,unsigned char*,14)=0;
                        break;
                    case 3:                         /* switch 3 */
                        Level26SpawnField(record, unsigned char *, 0xC) = 0;
                        Level26SpawnField(record, unsigned char *, 0xD) = byte255;
                        goto storeThirdColor;
                    case 4:                         /* switch 3 */
                        Level26SpawnField(record, unsigned char *, 0xC) = 0;
                        Level26SpawnField(record, unsigned char *, 0xD) = 0;
                        goto storeThirdColor;
                    case 5:                         /* switch 3 */
                        Level26SpawnField(record, unsigned char *, 0xC) = byte255;
                        Level26SpawnField(record, unsigned char *, 0xD) = 0;
                        goto storeThirdColor;
                    case 6:
                        {
                         __asm__("" : "=r"(byte128) : "0"(byte128));
                         Level26SpawnField(record,unsigned char*,12)=byte255;
                         Level26SpawnField(record,unsigned char*,13)=byte128;
                         }
                        Level26SpawnField(record, unsigned char *, 0xE) = 0;
                        break;
                    case 7:
                        {
                         __asm__("" : "=r"(byte128) : "0"(byte128));
                         Level26SpawnField(record,unsigned char*,12)=0;
                         Level26SpawnField(record,unsigned char*,13)=byte128;
                         }
storeThirdColor:
                        Level26SpawnField(record,unsigned char*,14)=byte255;
                        break;
                    }
                    Level26SpawnField(record, unsigned char *, 0xF) = 0x40;
                    break;
                case 0x46:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(1);
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = (unsigned char) (Level26Spawnrand() & 0xF);
                    Level26SpawnField(record, unsigned char *, 3) = 1;
                    frame.sp70 = 0;
                    frame.sp71 = Level26Spawnrand();
                    frame.sp72 = Level26Spawnrand();
                    Level26Spawnfunc_8004EA90(&frame.sp70, &frame.sp78, 0);
                    frame.sp60 = (int)modeSelector;
                    frame.sp64 = 0;
                    frame.sp68 = 0;
                    Level26Spawnfunc_8004ED6C(&frame.sp78, (unsigned char *) &frame.sp60, (unsigned char *) &frame.sp60);
                    Level26SpawnField(record, unsigned short *, 4) = (unsigned short) ((int) Level26SpawnField(reference, int *, 0) >> 2);
                    Level26SpawnField(record, unsigned short *, 6) = (unsigned short) ((int) Level26SpawnField(reference, int *, 4) >> 2);
                    Level26SpawnField(record, unsigned short *, 8) = (unsigned short) ((int) Level26SpawnField(reference, int *, 8) >> 2);
                    {register int value __asm__("$2")=frame.sp60;
                     register int other __asm__("$3")=Level26SpawnField(record,unsigned short*,4);
      
                     value<<=1;
                     other+=value;
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     Level26SpawnField(record,short*,10)=other;
                     __asm__("" ::: "memory");
                     value=frame.sp64;
                     other=Level26SpawnField(record,unsigned short*,6);
                     value<<=1;
                     other+=value;
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     Level26SpawnField(record,short*,12)=other;
                     __asm__("" ::: "$2","memory");
                     other=frame.sp68;
                     value=2;
                     Level26SpawnField(record,unsigned char*,23)=value;
                     value=224;
                     Level26SpawnField(record,unsigned char*,16)=value;
                     value=192;
                     Level26SpawnField(record,unsigned char*,17)=value;
                     value=80;
                     Level26SpawnField(record,unsigned char*,19)=value;
                     __asm__("" : "=r"(other) : "0"(other) : "$2","memory");
                     value=Level26SpawnField(record,unsigned short*,8);
                     __asm__ __volatile__("" ::: "$8","memory");
 
                     __asm__("" : "=r"(byte128) : "0"(byte128));
                     Level26SpawnField(record,unsigned char*,18)=0;
                     Level26SpawnField(record,unsigned char*,20)=byte255;
                     Level26SpawnField(record,unsigned char*,21)=byte255;
                     Level26SpawnField(record,unsigned char*,22)=byte128;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value) : "memory");
                     other<<=1;
                     value+=other;
                     Level26SpawnField(record,short*,14)=value;
                     }
                    break;
                case 0x47:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(1);
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = (unsigned char) (Level26Spawnrand() & 7);
                    Level26SpawnField(record, unsigned char *, 3) = 1;
                    temp_v0_4 = (int) (((Level26Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp90 = temp_v0_4;
                    temp_v0_5 = (int) (((Level26Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp94 = temp_v0_5;
                    temp_v0_6 = (int) (((Level26Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp98 = temp_v0_6;
                    {register int value __asm__("$2");
                    register int other __asm__("$3");
                     other=Level26SpawnField(reference,int*,0);
                     value=frame.sp90;
                     other>>=2;
                     value<<=2;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                     other+=value;
                     Level26SpawnField(record,unsigned short*,4)=other;
                     __asm__("" ::: "$2","$3","memory");
                     other=Level26SpawnField(reference,int*,4);
                     value=frame.sp94;
                     other>>=2;
                     value<<=2;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                     other+=value;
                     Level26SpawnField(record,unsigned short*,6)=other;
                     __asm__("" ::: "$2","$3","memory");
                     other=Level26SpawnField(reference,int*,8);
                     value=frame.sp98;
                     other>>=2;
                     value<<=2;
                     __asm__("" : "=r"(other),"=r"(value) : "0"(other),"1"(value));
                     other+=value;
                     Level26SpawnField(record,unsigned short*,8)=other;
                     __asm__("" ::: "$2","$3","memory");
                    }
                    {register int other __asm__("$3")=frame.sp90;
                     register int value __asm__("$2")=Level26SpawnField(record,unsigned short*,4);
                     register int finalComponent __asm__("$4");
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     value+=other;
                     Level26SpawnField(record,short*,10)=value;
                     __asm__("" ::: "$2","$3","memory");
                     other=frame.sp94;
                     value=Level26SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(value),"=r"(other) : "0"(value),"1"(other));
                     value+=other;
                     Level26SpawnField(record,short*,12)=value;
                     __asm__("" ::: "$2","$3","$4","memory");
                     finalComponent=frame.sp98;
                     other=Level26SpawnField(record,unsigned short*,8);
                     __asm__ __volatile__("" ::: "$2","memory");
                     value=2;
                     Level26SpawnField(record,unsigned char*,23)=value;
                     value=224;
                     Level26SpawnField(record,unsigned char*,16)=value;
                     Level26SpawnField(record,unsigned char*,17)=value;
                     value=96;
                     Level26SpawnField(record,unsigned char*,18)=value;
                     Level26SpawnField(record,unsigned char*,20)=byte255;
                     Level26SpawnField(record,unsigned char*,21)=byte255;
                     Level26SpawnField(record,unsigned char*,22)=byte255;
                     value=80;
                     Level26SpawnField(record,unsigned char*,19)=value;
                     __asm__("" : "=r"(other),"=r"(finalComponent) : "0"(other),"1"(finalComponent) : "memory");
                     other+=finalComponent;
                     Level26SpawnField(record,short*,14)=other;
                     }
                    break;
                case 0x4E:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(0);
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = (unsigned char) (Level26Spawnrand() & 0x1F);
                    Level26SpawnField(record, unsigned char *, 3) = 1;
                    Level26Spawnfunc_8004F504(record + 4, reference);
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3")=Level26SpawnField(record,unsigned short*,4);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=63;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=32;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     Level26SpawnField(record,unsigned short*,4)=component;
                     }
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3")=Level26SpawnField(record,unsigned short*,6);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=63;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=32;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     Level26SpawnField(record,unsigned short*,6)=component;
                     }
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3")=Level26SpawnField(record,unsigned short*,8);
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     random&=63;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component-=32;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     component+=random;
                     Level26SpawnField(record,unsigned short*,8)=component;
                     }
                    Level26SpawnField(record, short *, 0x10) = (short) ((Level26Spawnrand() & 2) - 1);
                    Level26SpawnField(record, short *, 0x12) = (short) ((Level26Spawnrand() & 2) - 1);
                    Level26SpawnField(record, short *, 0x14) = (short) -(Level26Spawnrand() & 1);
                    tailByte=Level26Spawnrand();
                    tailByte|=128;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "memory");
                    Level26SpawnField(record,unsigned char*,12)=tailByte;
                    {register int random __asm__("$2")=Level26Spawnrand();
                     register int component __asm__("$3");
                     random&=127;
                     __asm__("" : "=r"(random) : "0"(random));
                     component=Level26SpawnField(record,unsigned char*,12);
                     __asm__("" : "=r"(random) : "0"(random) : "memory");
                     random+=96;
                     __asm__("" : "=r"(random),"=r"(component) : "0"(random),"1"(component));
                     Level26SpawnField(record,unsigned char*,13)=random;
                     if((unsigned int)component<(unsigned int)random)Level26SpawnField(record,unsigned char*,13)=component;
                     }
                    Level26SpawnField(record, unsigned char *, 0xE) = (unsigned char) ((Level26Spawnrand() & 0x3F) + 0x40);
                    Level26SpawnField(record, unsigned char *, 0xF) = 0x40;
                    Level26SpawnField(record, unsigned char *, 0xA) = 2;
                    break;
                case 0x4F:                          /* switch 1 */
                    record = Level26Spawnfunc_80056434(1);
                    Level26SpawnField(record, unsigned char *, 0) = kindSelector;
                    Level26SpawnField(record, unsigned char *, 2) = (unsigned char) (Level26Spawnrand() & 0xF);
                    Level26SpawnField(record, unsigned char *, 3) = 1;
                    Level26Spawnfunc_8004F504(record + 0xA, reference);
                    {register void *vector __asm__("$16");
                     __asm__ volatile("" ::: "$16");
                     vector=(void*)&frame.sp90;
                     __asm__("" : "=r"(vector) : "0"(vector));
                    Level26Spawnfunc_8004F194(vector, reference, modeSelector);
                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3");
                    component=*(volatile int*)&frame.sp90;
                     __asm__ volatile("" : "=r"(random), "=r"(component) : "0"(random), "1"(component) : "memory");
                     random&=0x3F;
                     component-=0x20;
                     component+=random;
                     frame.sp90=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3")=frame.sp94;
                     
                     random&=0x3F;
                     
                     component-=0x20;
                     
                     component+=random;
                     frame.sp94=component;
                     }

                    {register int random __asm__("$2")=Level26Spawnrand();
                    register int component __asm__("$3");
                     register void *destination __asm__("$4")=record+4;
                     register void *source __asm__("$5")=vector;
                     
                     component=frame.sp98;
                     
                     random&=0x7F;
                     
                     component-=0x40;
                     
                     component+=random;
                     frame.sp98=component;
                     Level26Spawnfunc_8004F504(destination,source);
                     }
                    }
                    Level26SpawnField(record, unsigned char *, 0x17) = 2;
                    tailByte=Level26Spawnrand();
                    tailByte|=192;
                    
                    Level26SpawnField(record,unsigned char*,16)=tailByte;
                    Level26SpawnField(record, unsigned char *, 0x11) = (unsigned char) ((Level26Spawnrand() & 0x3F) - 0x60);
                    Level26SpawnField(record, unsigned char *, 0x12) = 0;
                    tailByte=Level26Spawnrand();
                    tailByte|=224;
                    
                    Level26SpawnField(record,unsigned char*,20)=tailByte;
                    tailByte=Level26Spawnrand();
                    tailByte|=224;
                    
                    Level26SpawnField(record,unsigned char*,21)=tailByte;
                    {
                    
                    Level26SpawnField(record, unsigned char *, 0x16) = byte128;
                    }
                    Level26SpawnField(record, unsigned char *, 0x13) = 0x50;
                    break;
                }
            {register int stride9 __asm__("$9")=frame.spC0;
             register int stride8 __asm__("$8")=frame.spC8;
             __asm__("" : "=r"(stride9),"=r"(stride8):"0"(stride9),"1"(stride8));
             stride9+=12;frame.spC0=stride9;
             stride9=frame.spA8;
             __asm__("" : "=r"(stride9),"=r"(stride8):"0"(stride9),"1"(stride8):"memory");
             stride8+=4;frame.spC8=stride8;
             stride8=frame.spA0;
             __asm__("" : "=r"(stride8),"=r"(stride9):"0"(stride8),"1"(stride9));
             stride9+=1;var_v0=stride9<stride8;
             __asm__ volatile("" : "=r"(var_v0),"=r"(stride9):"0"(var_v0),"1"(stride9):"$3","memory");
             frame.spA8=stride9;
             }
        } while (var_v0);
    }
    return record;
}

#undef Level26SpawnField

#undef Level26SpawnHigh


