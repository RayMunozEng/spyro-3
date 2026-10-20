#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80096434.
 * Assembly SHA256 33615b0fb9127c4f5e0039a396ea9a1230bb1074b998fcd4d992e9c7d233d27d.
 * AI-generated; not human reviewed. All1589 original instructions,
 * 91 selectors (bias19) and one owned table-padding word are required.
 * Eleven physical case groups reuse verified34 source references with
 * per-case stack/address mappings. Original21/30 and36/37/48 retain their
 * independent scalar, pointer, matrix, mode, clamp and vector producers.
 * Original0x130 frame retains scratch10..104 and savedS0..S7.
 * Constant divisions38/60 use complete signed64 C products to initialize
 * HI/LO before the empty high-half constraints; no undefined HI producer.
 * Typed aliases remain distinct. Empty initialized constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every original native/linked instruction, conditional/internal
 * target, selector/padding/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics22Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics22Call363DCView1() __asm__("func_800363DC");
unsigned char Physics22Call40D10View1() __asm__("func_80040D10");
unsigned char Physics22Call41580View1() __asm__("func_80041580");
unsigned char Physics22Call416F4View1() __asm__("func_800416F4");
unsigned char Physics22Call417FCView1() __asm__("func_800417FC");
unsigned char Physics22Call41B64View1() __asm__("func_80041B64");
int Physics22Call4E9E4View1() __asm__("func_8004E9E4");
int Physics22Call4EA2CView1() __asm__("func_8004EA2C");
unsigned char Physics22Call4ED6CView1() __asm__("func_8004ED6C");
int Physics22Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics22Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics22Call4F168View1() __asm__("func_8004F168");
unsigned char Physics22Call4F178View1() __asm__("func_8004F178");
unsigned char Physics22Call4F194View1() __asm__("func_8004F194");
unsigned char Physics22Call4F1C8View1() __asm__("func_8004F1C8");
int Physics22CallRandView1() __asm__("rand");
extern unsigned char Physics22Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics22Data65920View1 __asm__("D_80065920");
extern void *Physics22Data6C570View1 __asm__("D_8006C570");
extern int Physics22Data6C640View1 __asm__("D_8006C640");
extern int Physics22Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics22Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics22Player0View1 __asm__("D_80070328");
extern int Physics22Player94View1 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics22Call40D10View2() __asm__("func_80040D10");
int Physics22Call41580View2() __asm__("func_80041580");
int Physics22Call416F4View2() __asm__("func_800416F4");
int Physics22Call417FCView2() __asm__("func_800417FC");
int Physics22Call41848View1() __asm__("func_80041848");
int Physics22Call41B64View2() __asm__("func_80041B64");
int Physics22Call4E9E4View2() __asm__("func_8004E9E4");
int Physics22Call4EA2CView2() __asm__("func_8004EA2C");
int Physics22Call4EDE8View2() __asm__("func_8004EDE8");
int Physics22Call4F08CView2() __asm__("func_8004F08C");
int Physics22Call4F168View2() __asm__("func_8004F168");
int Physics22Call4F178View2() __asm__("func_8004F178");
int Physics22Call4F194View2() __asm__("func_8004F194");
int Physics22Call4F1C8View2() __asm__("func_8004F1C8");
int Physics22Call4F284View1() __asm__("func_8004F284");
extern unsigned char Physics22Data676E8View1 __asm__("D_800676E8");
extern int* Physics22Data6C570View2 __asm__("D_8006C570");
extern int Physics22Data6C58CView1 __asm__("D_8006C58C");
extern int Physics22Data6C5C8View1 __asm__("D_8006C5C8");
extern short Physics22Data6E040View1 __asm__("D_8006E040");
extern int Physics22Data6E044View2 __asm__("D_8006E044");
extern int Physics22Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics22Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics22PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics22Player94View2 __asm__("D_80070328+0x94");
extern int Physics22PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics22Player80View1 __asm__("D_80070328+0x80");
extern int Physics22PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics22Player64View1 __asm__("D_80070328+0x64");
extern int Physics22Player144View1 __asm__("D_80070328+0x144");
extern int Physics22PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics22Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics22PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics22PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics22Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics22Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics22Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics22Player101View1 __asm__("D_80070328+0x101");
extern int Physics22PlayerA4View1 __asm__("D_80070328+0xA4");
extern int Physics22Player210View1 __asm__("D_80070328+0x210");
extern int Physics22PlayerF8View1 __asm__("D_80070328+0xF8");
extern int Physics22Player8View1 __asm__("D_80070328+0x8");
int Physics22Call4EDE8View3() __asm__("func_8004EDE8");
int Physics22Call4F08CView3() __asm__("func_8004F08C");
int Physics22Call4F178View3() __asm__("func_8004F178");
int Physics22Call4F194View3() __asm__("func_8004F194");
int Physics22Call4F1C8View3() __asm__("func_8004F1C8");
extern unsigned char Physics22Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics22Data65920View2 __asm__("D_80065920");
extern int Physics22Data6C514View1 __asm__("D_8006C514");
extern int Physics22Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics22Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics22Player16CView1 __asm__("D_80070328+0x16C");
int Physics22Call40954View1() __asm__("func_80040954");
int Physics22Call40F48View1() __asm__("func_80040F48");
int Physics22Call41580View3() __asm__("func_80041580");
int Physics22Call417FCView3() __asm__("func_800417FC");
int Physics22Call41848View2() __asm__("func_80041848");
int Physics22Call4E56CView1() __asm__("func_8004E56C");
int Physics22Call4E880View1() __asm__("func_8004E880");
int Physics22Call4ECF4View1() __asm__("func_8004ECF4");
int Physics22Call4EDE8View4() __asm__("func_8004EDE8");
int Physics22Call4F08CView4() __asm__("func_8004F08C");
int Physics22Call4F168View3() __asm__("func_8004F168");
int Physics22Call4F178View4() __asm__("func_8004F178");
int Physics22Call4F194View4() __asm__("func_8004F194");
int Physics22Call4F1C8View4() __asm__("func_8004F1C8");
int Physics22Call4F6C4View1() __asm__("func_8004F6C4");
int Physics22Call5F35CView1() __asm__("func_8005F35C");
extern int* Physics22Data6C570View3 __asm__("D_8006C570");
extern int Physics22Data6C700View1 __asm__("D_8006C700");
extern int Physics22Data6E538View2 __asm__("D_8006E538");
extern unsigned char Physics22Player0View4 __asm__("D_80070328");
extern void *(*Physics22_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics22PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics22Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics22Player68View1 __asm__("D_80070328+0x68");
extern int Physics22Player6CView1 __asm__("D_80070328+0x6C");
extern int Physics22Player70View1 __asm__("D_80070328+0x70");
extern int Physics22PlayerA0View2 __asm__("D_80070328+0xA0");
extern int Physics22Player5CView1 __asm__("D_80070328+0x5C");
extern int Physics22Player60View1 __asm__("D_80070328+0x60");
extern int Physics22Player64View2 __asm__("D_80070328+0x64");
extern int Physics22Player164View1 __asm__("D_80070328+0x164");
extern int Physics22PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics22PlayerB8View2 __asm__("D_80070328+0xB8");
extern int Physics22Player10CView1 __asm__("D_80070328+0x10C");
extern int Physics22Player16CView2 __asm__("D_80070328+0x16C");
extern int Physics22Player168View1 __asm__("D_80070328+0x168");
extern int Physics22Player94View3 __asm__("D_80070328+0x94");
extern int Physics22Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics22Player80View2 __asm__("D_80070328+0x80");
extern int Physics22Player90View1 __asm__("D_80070328+0x90");
extern int Physics22Player84View1 __asm__("D_80070328+0x84");
void func_level_22_80096434(int slotIndex) {
    register int signedWord19 __asm__("$19");
    register int signedWord20 __asm__("$20");
    register int signedWord21 __asm__("$21");
    register void * savedPointer22 __asm__("$22");
    register void * savedPointer17 __asm__("$17");
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void *vectorAt40 __asm__("$16");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    register int rawProduct __asm__("$9");
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58;
        short sp5C,padding5E;
        int sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104;
    }
    originalFrame;
    register int signedTableWord __asm__("$7");
    register void *globalVector80 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$19");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$23");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char *globalByteE __asm__("$18");
    register void *globalFieldB8PointerState1A __asm__("$16");
    register void *globalFieldB8PointerState20 __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    void *temp_v0_5;
    void *temp_v0_7;
    void *raw13_temp_s0_9;
    void *raw13_temp_s1_4;
    void *raw13_temp_s1_5;
    int raw13_temp_v0_15;
    int raw13_temp_v0_16;
    int raw34_temp_v0_8;
    int raw22_temp_v0_6;
    workWord2=slotIndex*16;
    globalPointer=&Physics22Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics22Data6C570View1=(void*)workWord2;
    workWord2=Physics22Field(&Physics22Player0View1,int*,0x54);
    stateWord3=Physics22Field(&Physics22Player0View1,int*,0x48);
    combinedIndex=workWord2+slotIndex;
    switch (stateWord3) {
    case 20:case 53:case 54:globalVector80 = &Physics22Player0View1 + 0x80;
        Physics22Call4F168View1(globalVector80);
        Physics22Call4F168View1(globalVector80 + 0xC);
        if (Physics22Data6E044View1 != 7) {
            Physics22Call40D10View1(0x1200);
            Physics22Call416F4View1();
            Physics22Call41580View1(0x5A, 0x10);
            return;
        }
        return;
    default:
        return;
    case 19:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3=Physics22Data6E344View1;
            workWord2=13;
            if(workWord3==workWord2){
                workWord2=Physics22Data6C514View1;
                if(workWord2)return;
            }
            vectorAt30=&Physics22Player0View3+8;
            workWord3=Physics22Field(vectorAt30,int*,0);
            workWord2=Physics22Field(&Physics22Player0View3,int*,0x144);
            numeric4=workWord3-workWord2;
            workWord2=numeric4<1024;
            if(!workWord2)goto beyond19;
            workWord2=Physics22Player94View2;
            workWord2+=128;
            Physics22Player94View2=workWord2;
            workWord2=workWord2<4801;
            __asm__("":"=r"(numeric4):"0"(numeric4),"r"(workWord2));
            if(!workWord2){
                workWord2=4800;
                Physics22Player94View2=workWord2;
            }
            rawProduct=numeric4*numeric4;
            call4=&originalFrame.sp10;
            workWord3=Physics22Field(&Physics22Player0View3,int*,0x148);
            __asm__("":"=r"(rawProduct):"0"(rawProduct),"r"(workWord2),"r"(workWord3),"r"(call4));
            workWord2=rawProduct>>11;
            angle16=workWord2+workWord3;
            Physics22Player64View1=angle16;
            __asm__ volatile("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4):"memory");
            Physics22Call4F178View3(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics22Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics22Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x800965DC):"memory");
            numeric6=1024;
            goto limit19;
            beyond19:numeric5=Physics22Field(&Physics22Player0View3,int*,0x14C);
            workWord2=workWord3-numeric5;
            workWord2=workWord2<-1024;
            numeric6=numeric5-workWord3;
            if(!workWord2)goto curve19;
            __asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x80096600));
            workWord2=Physics22Player4CView1;
            workWord3=1;
            if(!workWord2){
                workWord2=Physics22Field(&Physics22Player0View3,int*,0x148);
                Physics22Player4CView1=workWord3;
                workWord2+=512;
                Physics22Field(&Physics22Player0View3,int*,0x148)=workWord2;
            }
            workWord2=Physics22Player94View2;
            workWord2+=128;
            Physics22Player94View2=workWord2;
            workWord2=workWord2<4801;
            if(!workWord2)Physics22Player94View2=4800;
            workWord2=Physics22Field(&Physics22Player0View3,int*,0x150);
            numeric6=numeric4-1024;
            workWord3=workWord2*numeric6;
            workWord2=Physics22Field(&Physics22Player0View3,int*,0x154);
            workWord2=workWord3/workWord2;
            call4=&originalFrame.sp10;
            workWord3=Physics22Field(&Physics22Player0View3,int*,0x148);
            angle16=workWord3+workWord2;
            workWord2=(numeric6<<10)>>10;
            workWord2=angle16+workWord2;
            angle16=workWord2&4095;
            Physics22Player64View1=angle16;
            Physics22Call4F178View3(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics22Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics22Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x80096710):"memory");
            numeric6=1024;
            goto limit19;
            curve19:__asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x80096718));
            workWord2=(numeric6*4800)>>10;
            Physics22Player94View2=workWord2;
            workWord2=Physics22Player16CView1;
            numeric7=Physics22Field(&Physics22Player0View3,int*,0x168);
            workWord3=Physics22Field(&Physics22Player0View3,int*,0x158);
            workWord2&=127;
            numeric4=numeric7<<1;
            Physics22Player16CView1=workWord2;
            workWord2=*(short*)(&Physics22Data65920View2+numeric4);
            workWord3+=1024;
            product10=workWord3*workWord2;
            square8=numeric6*numeric6;
            workWord2=product10>>12;
            originalFrame.sp10=workWord2;
            workWord2=*(short*)(&Physics22Data658A0View2+numeric4);
            workWord3=workWord3*workWord2;
            numeric7<<=4;
            call4=&originalFrame.sp10;
            call5=call4;
            __asm__("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4),"r"(call5));
            numeric6=(int)vectorAt30+340;
            workWord2=square8>>11;
            angle16=numeric7-workWord2;
            workWord2=workWord3>>12;
            originalFrame.sp14=workWord2;
            Physics22Call4F194View3(call4,call5,numeric6,numeric7);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics22Player64View1=angle16;
            Physics22Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics22Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<2049;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            numeric6=2048;
            limit19:Physics22Call4F08CView3(call4,call5,numeric6);
            commit19:workWord2=originalFrame.sp10;
            workWord3=originalFrame.sp14;
            Physics22Field(&Physics22Player0View3,int*,0x8C)=workWord2;
            Physics22Field(&Physics22Player0View3,int*,0x90)=workWord3;
            return;
        }
    case 0x15:
        raw22_temp_v0_6 = Physics22Field(&Physics22Player0View4, int *, 0x94) - 0x140;
        Physics22Field(&Physics22Player0View4, int *, 0x94) = raw22_temp_v0_6;
        if (raw22_temp_v0_6 < -0x2300) {
            Physics22Field(&Physics22Player0View4, int *, 0x94) = -0x2300;
        }
        Physics22Field(&Physics22Player0View4, int *, 0xA4) = Physics22Call4E880View1(Physics22Field(&Physics22Player0View4, int *, 0x8C), Physics22Field(&Physics22Player0View4, int *, 0x90), 1);
        Physics22Call41580View3(0x5A, 0x10);
        return;
    case 26:globalFieldB8PointerState1A = &Physics22Player0View3 + 0xB8;
        if (Physics22Field(&Physics22Player0View3, int *, 0xB8) != 0) {
            raw34_temp_v0_8 = Physics22Field(&Physics22Player0View3, int *, 0x94) - 0x600;
            Physics22Field(&Physics22Player0View3, int *, 0x94) = raw34_temp_v0_8;
            if (raw34_temp_v0_8 < -0x2300) {
                Physics22Field(&Physics22Player0View3, int *, 0x94) = -0x2300;
            }
            Physics22Call4F178View3(globalFieldB8PointerState1A - 0x38, globalFieldB8PointerState1A - 0x2C);
            return;
        }
        goto block_42;
    case 107:Physics22Call40D10View1(0xC80);
        Physics22Call41580View1(0x28, 8);
        Physics22Call417FCView1(0x140, 0xC0);
        globalFieldA4Pointer = &Physics22Player0View1 + 0xA4;
        globalVector8CState20 = globalFieldA4Pointer - 0x18;
        workWord2=Physics22Call4EA2CView1(Physics22Field(globalFieldA4Pointer,int*,0));
        workWord3=Physics22Field(&Physics22Player0View1,int*,0xB0);
        rawProduct=workWord3*workWord2;
        call4=(void*)Physics22Field(globalFieldA4Pointer,int*,0);
        workWord2=rawProduct>>12;
        __asm__("" : "=r"(workWord2):"0"(workWord2));
        originalFrame.sp20=workWord2;
        workWord2=Physics22Call4E9E4View1(call4);
        workWord3=Physics22Field(&Physics22Player0View1,int*,0xB0);
        rawProduct=workWord3*workWord2;
        workWord2=rawProduct>>12;
        __asm__("" : "=r"(workWord2):"0"(workWord2));
        originalFrame.sp24=workWord2;
        Physics22Call4F1C8View1(&originalFrame.sp20, &originalFrame.sp20, globalVector8CState20);
        originalFrame.sp28 = 0;
        temp_v0_4 = Physics22Call4EDE8View1(&originalFrame.sp20, 0);
        __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
        var_a0_3 = globalFieldA4Pointer - 0x24;
        if (temp_v0_4 >= 0x281) {
            Physics22Call4F08CView1(&originalFrame.sp20, temp_v0_4, 0x280);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
        }
        Physics22Call4F194View1(var_a0_3, globalVector8CState20, &originalFrame.sp20);
        Physics22Call41B64View1();
        if (combinedIndex < 0xD) {
            __asm__("" :: "r"(combinedIndex));
            nextField94 = Physics22Field(&Physics22Player0View1, int *, 0x94) + 0x17;
        }
        else {
            nextField94 = Physics22Field(&Physics22Player0View1, int *, 0x94) - 0xC0;
        }
        Physics22Player94View1=nextField94;
        __asm__ volatile("" ::: "memory");
        if (Controller88028_SpawnParticle != 0) {
            globalPointer=&Physics22Player0View1+0x148;
            __asm__("" : "=r"(globalPointer):"0"(globalPointer));
            particleIndex=0;
            if (Physics22Field(globalPointer,int*,0) != 0) {
                workWord2=combinedIndex*4;
                __asm__("" : "=r"(workWord2):"0"(workWord2));
                particleThreshold=workWord2+combinedIndex;
                globalByteE=globalPointer-0x13A;
                vectorAt40=&originalFrame.sp40;
                __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
            spawnParticleLoop:
                if (particleThreshold < (Physics22CallRandView1() & 0xFF)) {
                    workWord2=Physics22Call363DCView1(0,0xC);
                    call4=globalByteE+0x22;
                    workWord3=*globalByteE;
                    __asm__("" : "=r"(workWord3):"0"(workWord3));
                    call5=vectorAt40;
                    __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
                    workWord3+=0x80;
                    __asm__("" : "=r"(workWord3):"0"(workWord3));
                    workWord3+=workWord2;
                    __asm__("" : "=r"(workWord3):"0"(workWord3));
                    workWord3=(workWord3&0xFF)*2;
                    signedTableWord = *(short*)(&Physics22Data65920View1 + workWord3);
                    call6=vectorAt40;
                    originalFrame.sp30 = (int) (signedTableWord * 5) >> 0xA;
                    workWord3=*(short*)(&Physics22Data658A0View1 + workWord3);
                    __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                    originalFrame.sp38 = 0xE;
                    originalFrame.sp40 = -0x12C;
                    originalFrame.sp44 = 0;
                    originalFrame.sp48 = -0xC8;
                    __asm__ volatile("" ::: "memory");
                    originalFrame.sp34 = (workWord3 * 5) >> 0xA;
                    Physics22Call4ED6CView1(call4, call5, call6, signedTableWord);
                    originalFrame.sp40 += Physics22Call363DCView1(0, 0x50);
                    originalFrame.sp44 += Physics22Call363DCView1(0, 0x50);
                    originalFrame.sp48 += Physics22Call363DCView1(0, 0x50);
                    Physics22Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                    temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp30);
                    Physics22Field(temp_v0_5, signed char *, 2) = 8;
                    Physics22Field(temp_v0_5, signed char *, 0xA) = 0x20;
                }
                particleIndex += 1;
                if (particleIndex < 2) {
                    goto spawnParticleLoop;
                }
            }
        }
        break;
    case 30:globalVector80=&Physics22Player80View1;
        __asm__ volatile("":"=r"(globalVector80):"0"(globalVector80));
        block_42:call4=&Physics22Player80View2;
        __asm__("":"=r"(call4):"0"(call4));
        Physics22Call4F168View3(call4);
        call4=&Physics22Player8CView1;
        __asm__("":"=r"(call4):"0"(call4));
        Physics22Call4F168View3(call4);
        return;
    case 32:case 108:globalFieldB8PointerState20 = &Physics22Player0View1 + 0xB8;
        if (Physics22Field(&Physics22Player0View1, int *, 0xB8) != 0) {
            vectorAt30=&originalFrame.sp30;
            Physics22Call4F168View1(vectorAt30);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
            Physics22Call4F1C8View1(call4, call5, globalVector8CState20);
            originalFrame.sp38 = 0;
            temp_v0_6 = Physics22Call4EDE8View1(&originalFrame.sp30, 0);
            if (temp_v0_6 >= 0x41) {
                Physics22Call4F08CView1(&originalFrame.sp30, temp_v0_6, 0x40);
            }
            originalFrame.sp38 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Physics22Call4F194View1(globalVector80State20, globalVector8CState20, &originalFrame.sp30);
            Physics22Call4F178View1(globalVector8CState20, globalVector80State20);
        }
        else {
            Physics22Call4F168View1(globalFieldB8PointerState20 - 0x38);
            Physics22Call4F168View1(globalFieldB8PointerState20 - 0x2C);
        }
        if (Physics22Field(&Physics22Player0View1, int *, 0x94) < -0x2300) {
            Physics22Field(&Physics22Player0View1, int *, 0x94) = -0x2300;
        }
        if ((Physics22Field(&Physics22Player0View1, int *, 0x48) == 0x3A) && (Controller88028_SpawnParticle != 0) && (Physics22Data6C640View1 & 1)) {
            originalFrame.sp50 = 0;
            originalFrame.sp54 = 0;
            originalFrame.sp58 = 0xE;
            Physics22Call4F178View1(&originalFrame.sp60, (&Physics22Player0View1 + 0x94) - 0x94);
            originalFrame.sp60 += Physics22Call363DCView1(0, 0x12C);
            originalFrame.sp64 += Physics22Call363DCView1(0, 0x12C);
            originalFrame.sp68 += Physics22Call363DCView1(0, 0x12C);
            temp_v0_7 = Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp60, &originalFrame.sp50);
            Physics22Field(temp_v0_7, signed char *, 2) = 6;
            Physics22Field(temp_v0_7, signed char *, 0xA) = 0x20;
        }
        break;
    case 0x24:
    case 0x25:
    case 48:{
            register int limit16 __asm__("$16");
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics22Call40F48View1(&originalFrame.sp50,0);
            workWord2=originalFrame.sp50;
            call5=&Physics22PlayerA8View2;
            workWord3=workWord2*9;
            workWord3<<=2;
            workWord2-=workWord3;
            workWord3=Physics22Field(call5,int*,0);
            numeric4=workWord2>>7;
            workWord2=workWord3<numeric4;
            if(workWord2){
                workWord2=workWord3+8;
                Physics22Field(call5,int*,0)=workWord2;
                workWord2=numeric4<workWord2;
            }
            else{
                workWord2=workWord3-8;
                Physics22Field(call5,int*,0)=workWord2;
                workWord2=workWord2<numeric4;
            }
            if(workWord2)Physics22Field(call5,int*,0)=numeric4;
            workWord3=Physics22Player4CView2;
            workWord2=5;
            if(workWord3==workWord2){
                workWord3=Physics22Player68View1;
                numeric4=Physics22Player6CView1;
                workWord2=(workWord3<<5)>>9;
                workWord3-=workWord2;
                workWord2=(numeric4<<5)>>9;
                Physics22Player68View1=workWord3;
                workWord3=originalFrame.sp50;
                numeric4-=workWord2;
                Physics22Player6CView1=numeric4;
                numeric4=Physics22Player70View1;
                workWord2=workWord3*48;
                workWord2=-workWord2;
                workWord2>>=8;
                workWord3=(numeric4<<5)>>9;
                workWord2-=workWord3;
                numeric4+=workWord2;
                goto store70;
            }
            workWord2=4;
            if(workWord3!=workWord2)goto default48;
            workWord2=Physics22Data6E538View2&16;
            if(!workWord2)goto default48;
            workWord2=originalFrame.sp50;
            numeric4=Physics22Player68View1;
            numeric5=Physics22Player6CView1;
            workWord3=(workWord2*48)>>8;
            workWord2=(numeric4<<5)>>9;
            workWord3-=workWord2;
            workWord2=originalFrame.sp54;
            numeric4+=workWord3;
            Physics22Player68View1=numeric4;
            numeric4=Physics22Player70View1;
            workWord3=(workWord2*48)>>8;
            workWord2=(numeric5<<5)>>9;
            workWord3-=workWord2;
            numeric5+=workWord3;
            workWord2=(numeric4<<5)>>9;
            Physics22Player6CView1=numeric5;
            numeric4-=workWord2;
            goto store70;
            default48:globalVector80=&Physics22PlayerA8View2;
            call4=globalVector80-16;
            workWord2=Physics22Field(globalVector80,int*,0);
            call5=0;
            workWord2=-workWord2;
            signedWord20=workWord2<<3;
            workWord2=Physics22Call4EDE8View4(call4,call5);
            call4=(void*)workWord2;
            call5=(void*)Physics22PlayerA0View2;
            workWord2=Physics22Call4E880View1(call4,call5,1);
            signedWord19=workWord2&4095;
            workWord2=signedWord19<2049;
            if(!workWord2){
                signedWord19-=4096;
                workWord2=signedWord19<-256;
            }
            else workWord2=signedWord19<-256;
            if(workWord2)signedWord19=-256;
            workWord2=Physics22Player5CView1;
            workWord2=signedWord20-workWord2;
            signedWord20=workWord2&4095;
            workWord2=signedWord20<2049;
            if(!workWord2)signedWord20-=4096;
            workWord2=Physics22Player60View1;
            workWord2-=signedWord19;
            signedWord19=workWord2&4095;
            workWord2=signedWord19<2049;
            if(!workWord2)signedWord19-=4096;
            workWord2=signedWord20<-256;
            if(workWord2){
                signedWord20=-256;
                __asm__("":"=r"(signedWord20):"0"(signedWord20));
                workWord2=signedWord20<257;
            }
            else workWord2=signedWord20<257;
            if(!workWord2)signedWord20=256;
            workWord2=signedWord19<-256;
            if(workWord2){
                signedWord19=-256;
                __asm__("":"=r"(signedWord19):"0"(signedWord19));
                workWord2=signedWord19<257;
            }
            else workWord2=signedWord19<257;
            if(!workWord2)signedWord19=256;
            workWord3=(signedWord20<<2)>>4;
            numeric4=Physics22Player68View1;
            signedWord21=Physics22Field(globalVector80,int*,0);
            workWord2=(numeric4<<5)>>6;
            workWord3-=workWord2;
            numeric4+=workWord3;
            workWord3=signedWord19<<2;
            Physics22Player68View1=numeric4;
            numeric4=Physics22Player6CView1;
            workWord3>>=4;
            workWord2=(numeric4<<5)>>6;
            workWord3-=workWord2;
            numeric4+=workWord3;
            workWord3=signedWord21<<2;
            Physics22Player6CView1=numeric4;
            numeric4=Physics22Player70View1;
            workWord3>>=4;
            workWord2=(numeric4<<5)>>6;
            workWord3-=workWord2;
            numeric4+=workWord3;
            store70:Physics22Player70View1=numeric4;
            __asm__ volatile("":::"memory");
            workWord2=4;
            signedWord20=Physics22Player68View1;
            signedWord19=Physics22Player6CView1;
            signedWord21=Physics22Player70View1;
            workWord3=Physics22Player4CView2;
            signedWord20>>=2;
            if(workWord3==workWord2){
                workWord2=Physics22Data6E538View2&16;
                signedWord19>>=2;
                if(workWord2)signedWord21>>=2;
            }
            else{
                workWord2=5;
                if(workWord3==workWord2){
                    signedWord21>>=2;
                    signedWord19>>=2;
                }
            }
            workWord2=(unsigned int)(Physics22Player4CView2-4)<2;
            globalVector80=&originalFrame.sp58;
            if(workWord2){
                call4=Physics22Field(&Physics22Player0View4,void**,0x250);
                if(call4){
                    call4=Physics22Field(call4,void**,0);
                    workWord2=Physics22Field(call4,int*,0xF4);
                    workWord3=Physics22Field(call4,int*,0xFC);
                    workWord2+=signedWord20;
                    Physics22Field(call4,int*,0xF4)=workWord2;
                    workWord2=Physics22Field(call4,int*,0xF8);
                    workWord3+=signedWord21;
                    Physics22Field(call4,int*,0xFC)=workWord3;
                    workWord2+=signedWord19;
                    Physics22Field(call4,int*,0xF8)=workWord2;
                }
            }
            call4=globalVector80;
            globalVector8CState20=&originalFrame.sp70;
            call5=globalVector8CState20;
            __asm__ volatile(""::"r"(call5):"memory");
            savedPointer22=&Physics22Player5CView1;
            workWord2=Physics22Field(savedPointer22,int*,0);
            workWord3=Physics22Player64View2;
            __asm__ volatile(""::"r"(workWord2),"r"(workWord3):"$17","memory");
            savedPointer17=&originalFrame.sp88;
            Physics22Field(&originalFrame.sp58,short*,0)=workWord2;
            workWord2=Physics22Player60View1;
            call6=savedPointer17;
            originalFrame.sp5C=workWord3;
            workWord2=-workWord2;
            Physics22Field(&originalFrame.sp58,short*,2)=workWord2;
            Physics22Call4F6C4View1(call4,call5,call6);
            Physics22Call4ECF4View1(globalVector8CState20,globalVector8CState20);
            call4=globalVector80;
            call5=savedPointer17;
            __asm__ volatile(""::"r"(call4),"r"(call5):"memory");
            globalVector80=&originalFrame.spA0;
            call6=globalVector80;
            Physics22Field(&originalFrame.sp58,short*,0)=signedWord20;
            Physics22Field(&originalFrame.sp58,short*,2)=signedWord19;
            originalFrame.sp5C=signedWord21;
            Physics22Call4F6C4View1(call4,call5,call6);
            Physics22Call4ECF4View1(savedPointer17,savedPointer17);
            Physics22Call5F35CView1(globalVector8CState20,savedPointer17,globalVector80);
            Physics22Call4E56CView1(savedPointer22,globalVector80);
            workWord2=Physics22Player164View1;
            if(workWord2){
                workWord2=14208;
                Physics22PlayerACView2=workWord2;
                workWord2=96;
                goto update16C;
            }
            workWord3=Physics22PlayerB8View2;
            __asm__ volatile(""::"r"(workWord3):"memory");
            workWord2=8192;
            Physics22PlayerACView2=workWord2;
            call4=savedPointer22+60;
            if(workWord3)goto queryC700;
            numeric4=Physics22Data6C700View1;
            workWord3=Physics22PlayerA0View2;
            Physics22PlayerACView2=numeric4;
            limit16=8192;
            if(workWord3>=0)goto producerQuery;
            {
                long long computedProduct;
                int nativeHigh;
                workWord2=0x6BCA1AF3;
                computedProduct=(long long)workWord3*workWord2;
                workWord3>>=31;
                __asm__("":"=h"(nativeHigh):"x"(computedProduct));
                rawProduct=nativeHigh;
                __asm__("":"=r"(rawProduct):"0"(rawProduct));
                workWord2=rawProduct>>4;
                workWord2-=workWord3;
            }
            __asm__ volatile(""::"i"(0x800971C4):"memory");
            workWord2=numeric4-workWord2;
            goto storeC700Difference;
            producerQuery:workWord2=Physics22Call40954View1(Physics22Player10CView1);
            workWord3=9;
            if(workWord2==workWord3)goto clampC700;
            numeric4=Physics22PlayerA0View2;
            {
                long long computedProduct;
                int nativeHigh;
                workWord2=(int)0x88888889;
                computedProduct=(long long)numeric4*workWord2;
                workWord2=Physics22Data6C700View1;
                __asm__ volatile(""::"r"(workWord2):"memory");
                __asm__("":"=h"(nativeHigh):"x"(computedProduct));
                rawProduct=nativeHigh;
                __asm__("":"=r"(rawProduct):"0"(rawProduct));
                workWord3=rawProduct+numeric4;
                workWord3>>=5;
                numeric4>>=31;
                workWord3-=numeric4;
            }
            workWord2-=workWord3;
            storeC700Difference:Physics22Data6C700View1=workWord2;
            clampC700:__asm__("":"=r"(limit16):"0"(limit16));
            workWord2=Physics22Data6C700View1;
            workWord3=limit16+7040;
            workWord2=workWord3<workWord2;
            if(workWord2)Physics22Data6C700View1=workWord3;
            workWord2=Physics22Data6C700View1;
            workWord3=limit16-2560;
            workWord2=workWord2<workWord3;
            if(workWord2)Physics22Data6C700View1=workWord3;
            numeric4=Physics22Data6C700View1;
            workWord3=limit16-numeric4;
            workWord2=workWord3<53;
            if(!workWord2){
                workWord3=52;
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord2=workWord3<-18;
            }
            else workWord2=workWord3<-18;
            if(!workWord2){
                workWord2=numeric4+workWord3;
                goto storeC700;
            }
            __asm__ volatile(""::"i"(0x80097290):"memory");
            workWord3=-18;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=numeric4+workWord3;
            goto storeC700;
            queryC700:workWord2=Physics22Call4EDE8View4(call4,1);
            workWord3=Physics22Data6C700View1;
            workWord2-=workWord3;
            workWord2-=1000;
            if(workWord2<=0){
                workWord2=workWord3+workWord2;
                goto doneC700;
            }
            workWord2=workWord3+workWord2;
            storeC700:Physics22Data6C700View1=workWord2;
            doneC700:workWord2=0;
            update16C:savedPointer17=&Physics22Player16CView2;
            numeric5=Physics22Player168View1;
            workWord3=Physics22Field(savedPointer17,int*,0);
            workWord2-=numeric5;
            workWord2<<=4;
            numeric4=workWord3<<5;
            workWord2-=numeric4;
            workWord2>>=6;
            workWord3+=workWord2;
            Physics22Field(savedPointer17,int*,0)=workWord3;
            workWord3>>=4;
            numeric5+=workWord3;
            Physics22Player168View1=numeric5;
            if(numeric5<0)Physics22Player168View1=0;
            workWord2=Physics22Player168View1;
            workWord2=workWord2<97;
            call4=(void*)576;
            if(!workWord2){
                workWord2=96;
                Physics22Player168View1=workWord2;
            }
            Physics22Call417FCView3(call4,48);
            Physics22Call41848View2();
            workWord3=Physics22Player4CView2;
            workWord2=4;
            if(workWord3!=workWord2)goto maybeFive48;
            workWord2=Physics22Data6E538View2&16;
            call5=savedPointer17-236;
            if(workWord2)goto subtract128;
            globalVector80=&originalFrame.spB8;
            call4=globalVector80;
            __asm__ volatile("":"=r"(savedPointer17):"0"(savedPointer17),"r"(call4):"memory");
            savedPointer17-=224;
            Physics22Call4F1C8View4(call4,call5,savedPointer17);
            originalFrame.spC0=0;
            call5=(void*)Physics22Call4EDE8View4(globalVector80,0);
            workWord2=(int)call5<385;
            call4=savedPointer17;
            if(!workWord2){
                Physics22Call4F08CView4(globalVector80,call5,384);
                call4=savedPointer17;
            }
            call5=call4;
            Physics22Call4F194View4(call4,call5,globalVector80);
            subtract128:globalPointer=&Physics22Player94View3;
            workWord2=Physics22Field(globalPointer,int*,0);
            workWord2-=128;
            Physics22Field(globalPointer,int*,0)=workWord2;
            goto clamp94PointerReady;
            maybeFive48:workWord2=5;
            if(workWord3!=workWord2)goto gate48;
            globalVector80=&originalFrame.spC8;
            call4=globalVector80;
            __asm__ volatile("":"=r"(savedPointer17):"0"(savedPointer17),"r"(call4):"memory");
            savedPointer17-=224;
            Physics22Call4F178View4(call4,savedPointer17);
            originalFrame.spD0=0;
            call5=(void*)Physics22Call4EDE8View4(globalVector80,0);
            workWord2=(int)call5<65;
            if(!workWord2)Physics22Call4F08CView4(globalVector80,call5,64);
            workWord2=128;
            originalFrame.spD0=workWord2;
            call4=savedPointer17;
            call5=call4;
            Physics22Call4F1C8View4(call4,call5,globalVector80);
            goto clamp104;
            gate48:workWord2=combinedIndex<13;
            if(!workWord2)goto flags48;
            workWord2=1;
            if(workWord3!=workWord2)goto flags48;
            workWord2=(int)Physics22Data6C570View3;
            workWord2=Physics22Field((void*)workWord2,int*,0)&64;
            if(!workWord2)goto flags48;
            workWord2=Physics22Player80View2;
            workWord3=Physics22Player94View3;
            numeric4=Physics22Player84View1;
            Physics22Player8CView1=workWord2;
            Physics22Player90View1=numeric4;
            workWord3-=64;
            goto store94From3;
            flags48:call6=&Physics22PlayerFCView1;
            workWord2=Physics22Field(call6,unsigned char*,0);
            if(workWord2)goto copy48;
            workWord2=Physics22PlayerB8View2;
            call4=call6-112;
            if(!workWord2)goto vector48;
            copy48:workWord2=Physics22Player80View2;
            workWord3=Physics22PlayerA0View2;
            numeric4=Physics22Player84View1;
            workWord3-=192;
            Physics22Player8CView1=workWord2;
            Physics22Player90View1=numeric4;
            Physics22Player94View3=workWord3;
            Physics22PlayerA0View2=workWord3;
            goto clamp104;
            vector48:call5=call6-124;
            Physics22Call4F194View4(call4,call5,call6-20);
            goto clamp104;
        }
    case 105:globalVector80=&Physics22Player0View2+0xB8;
        workWord2=Physics22Field(globalVector80,int*,0);
        if(!workWord2)goto zero105;
        vectorAt30=&originalFrame.spD8;
        Physics22Call4F168View2(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics22Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.spE0=0;
        call5=(void*)Physics22Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics22Call4F08CView2(vectorAt30,call5,64);
        originalFrame.spE0=-192;
        globalVector80-=56;
        Physics22Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics22Call4F178View2(globalVector8CState20,globalVector80);
        goto clamp104;
        zero105:Physics22Call4F168View2(globalVector80-56);
        Physics22Call4F168View2(globalVector80-44);
        goto clamp104;
    case 100:globalVector80=&Physics22Player0View2+0x80;
        Physics22Call4F168View2(globalVector80);
        Physics22Call4F168View2(globalVector80+12);
        if(Physics22Data6E044View2!=7){
            Physics22Call40D10View2(3840);
            Physics22Call416F4View2();
            Physics22Call41580View2(90,16);
        }
        workWord2=Physics22Player1BAView1;
        if(!workWord2){
            workWord2=1;
            goto byteOne;
        }
        workWord2=Physics22Data6E538View1&16;
        if(workWord2){
            workWord2=1;
            goto wordOneReturn;
        }
        workWord2=1;
        Physics22Player1BAView1=0;
        __asm__ volatile(""::"i"(0x80097654):"memory");
        goto byteOne;
    case 101:workWord3=Physics22Data6E044View2;
        workWord2=8;
        if(workWord3!=workWord2)Physics22Call40D10View2(3840);
        globalVector80=&Physics22Data6E538View1;
        workWord2=Physics22Field(globalVector80,int*,0)&12;
        if(workWord2)Physics22PlayerACView1=0;
        workWord2=Physics22Call416F4View2();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics22Call41580View2(call4,call5);
        workWord3=Physics22PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics22Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics22Player144View1;
        workWord2++;
        Physics22Player144View1=workWord2;
        goto saved101;
        reset101:Physics22Player144View1=0;
        saved101:call4=&Physics22PlayerACView1;
        globalVector80=(void*)Physics22Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics22Player20CView1&64;
        if(workWord2)Physics22Field(call4,int*,0)=0;
        else{
            workWord3=Physics22PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics22Field(call4,int*,0)=workWord3;
        }
        pass101:Physics22Call417FCView2(256,384);
        workWord2=Physics22Player101View1;
        call4=&Physics22PlayerACView1;
        Physics22Field(call4,int*,0)=(int)globalVector80;
        if(workWord2){
            Physics22Call4F168View2(call4-32);
            goto fields101;
        }
        Physics22Call41848View1(call4);
        Physics22Call41B64View2();
        fields101:call6=&Physics22PlayerFCView1;
        workWord2=Physics22Field(call6,unsigned char*,0);
        if(workWord2)goto field94FromA0;
        workWord2=Physics22PlayerB8View1;
        call4=call6-112;
        if(!workWord2)goto commit101;
        field94FromA0:workWord2=Physics22PlayerA0View1;
        workWord2-=192;
        Physics22Player94View2=workWord2;
        return;
        commit101:call5=call4;
        vectorCommit61:Physics22Call4F194View2(call4,call5,call6-20);
        return;
    case 102:case 103:case 106:{
            register int limit17 __asm__("$17");
            register int numeric5 __asm__("$5");
            Physics22Call40D10View2(6400);
            workWord2=Physics22Data6E538View1;
            workWord3=workWord2&12;
            if(workWord3)goto held106;
            workWord2=Physics22Call4F284View1(Physics22PlayerA4View1,Physics22Player64View1);
            workWord2=workWord2<1665;
            if(workWord2)Physics22Call41580View2(44,6);
            limit17=80;
            goto move106;
            held106:workWord2=8;
            if(workWord3!=workWord2)goto other106;
            workWord2=Physics22Data6E040View1;
            workWord3=6400;
            Physics22PlayerACView1=workWord3;
            workWord2-=1024;
            goto heading106;
            other106:workWord2=4;
            limit17=320;
            if(workWord3!=workWord2)goto move106;
            workWord2=Physics22Data6E040View1;
            workWord3=6400;
            Physics22PlayerACView1=workWord3;
            workWord2+=1024;
            heading106:Physics22PlayerA4View1=workWord2;
            limit17=320;
            move106:Physics22Call417FCView2(256,384);
            globalVector8C=&Physics22Player210View1;
            workWord2=Physics22Field(globalVector8C,int*,0)&1024;
            if(workWord2)goto clamp106;
            call4=(void*)Physics22PlayerA4View1;
            globalVector8CState20=globalVector8C-388;
            workWord2=Physics22Call4EA2CView2(call4);
            workWord3=Physics22PlayerB0View1;
            rawProduct=workWord3*workWord2;
            call4=(void*)Physics22PlayerA4View1;
            workWord2=rawProduct>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spE8=workWord2;
            workWord2=Physics22Call4E9E4View2(call4);
            workWord3=Physics22PlayerB0View1;
            rawProduct=workWord3*workWord2;
            call4=globalVector8CState20;
            call5=globalVector8C-376;
            workWord2=rawProduct>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spEC=workWord2;
            Physics22Call4F178View2(call4,call5);
            globalVector80=&originalFrame.spE8;
            Physics22Call4F1C8View2(globalVector80,globalVector80,globalVector8CState20);
            originalFrame.spF0=0;
            call5=(void*)Physics22Call4EDE8View2(globalVector80,0);
            workWord2=limit17<(int)call5;
            if(workWord2)Physics22Call4F08CView2(globalVector80,call5,limit17);
            Physics22Call4F194View2(globalVector8C-400,globalVector8CState20,globalVector80);
            Physics22Call41B64View2();
            workWord2=(int)Physics22Data6C570View2;
            workWord2=Physics22Field((void*)workWord2,int*,0)&64;
            if(workWord2)Physics22Player144View1=0;
            else{
                workWord2=Physics22Player144View1;
                workWord2++;
                Physics22Player144View1=workWord2;
            }
            workWord2=Physics22Player144View1;
            workWord2=workWord2<10;
            if(workWord2){
                workWord2=Physics22Player94View2;
                workWord2+=256;
                goto store106;
            }
            workWord2=Physics22Player94View2;
            workWord2-=96;
            store106:Physics22Player94View2=workWord2;
            workWord2=Physics22PlayerF8View1;
            workWord3=Physics22Player8View1;
            numeric5=workWord2-workWord3;
            workWord2=numeric5<4096;
            workWord3=numeric5<<2;
            if(!workWord2)goto mode106;
            workWord2=Physics22Player94View2;
            workWord2=workWord3<workWord2;
            if(workWord2)Physics22Player94View2=workWord3;
            mode106:workWord3=Physics22Player4CView1;
            workWord2=127;
            if(workWord3==workWord2)goto clamp106;
            call4=&Physics22Data676E8View1;
            workWord2=Physics22Data6C58CView1;
            workWord3=Physics22Data6C5C8View1;
            workWord2<<=4;
            workWord2+=(int)call4;
            workWord3<<=2;
            workWord3+=workWord2;
            workWord2=Physics22Player8View1;
            workWord3=Physics22Field((void*)workWord3,int*,0);
            workWord2-=workWord3;
            numeric5=workWord2-1024;
            workWord2=numeric5<4096;
            workWord3=-numeric5;
            if(workWord2){
                workWord2=Physics22Player94View2;
                __asm__(""::"r"(workWord3),"r"(workWord2));
                workWord3<<=1;
                workWord2=workWord2<workWord3;
                if(workWord2)Physics22Player94View2=workWord3;
            }
            clamp106:globalPointer=&Physics22Player94View2;
            workWord2=Physics22Field(globalPointer,int*,0);
            workWord2=workWord2<-4480;
            if(workWord2){
                workWord2=-4480;
                Physics22Field(globalPointer,int*,0)=workWord2;
            }
            workWord2=Physics22Field(globalPointer,int*,0);
            workWord2=workWord2<1921;
            if(!workWord2){
                workWord2=1920;
                Physics22Field(globalPointer,int*,0)=workWord2;
            }
            return;
        }
    case 104:{
            register int numeric5 __asm__("$5");
            Physics22Call4F168View2(&originalFrame.spF8);
            raw13_temp_s1_4 = &Physics22Player0View2 + 0x8C;
            Physics22Call4F1C8View2(&originalFrame.spF8, &originalFrame.spF8, raw13_temp_s1_4);
            if (Physics22PlayerB8View1 != 0) {
                originalFrame.sp100 = 0;
                raw13_temp_v0_15 = Physics22Call4EDE8View2(&originalFrame.spF8, 0);
                if (raw13_temp_v0_15 >= 0x41) {
                    Physics22Call4F08CView2(&originalFrame.spF8, raw13_temp_v0_15, 0x40);
                }
            }
            else {
                raw13_temp_v0_16 = Physics22Call4EDE8View2(&originalFrame.spF8, 1);
                if (raw13_temp_v0_16 >= 0x101) {
                    Physics22Call4F08CView2(&originalFrame.spF8, raw13_temp_v0_16, 0x100);
                }
                Physics22Call4F194View2(raw13_temp_s1_4, raw13_temp_s1_4, &originalFrame.spF8);
            }
            raw13_temp_s0_9 = &Physics22Player0View2 + 0x80;
            raw13_temp_s1_5 = raw13_temp_s0_9 + 0xC;
            originalFrame.sp100 = -0xC0;
            Physics22Call4F194View2(raw13_temp_s0_9, raw13_temp_s1_5, &originalFrame.spF8);
            Physics22Call4F178View2(raw13_temp_s1_5, raw13_temp_s0_9);
            call4=&Physics22Data676E8View1;
            workWord2=Physics22Data6C58CView1;
            workWord3=Physics22Data6C5C8View1;
            workWord2<<=4;
            workWord2+=(int)call4;
            workWord3<<=2;
            workWord3+=workWord2;
            workWord2=Physics22Player8View1;
            workWord3=Physics22Field((void*)workWord3,int*,0);
            workWord2-=workWord3;
            numeric5=workWord2-1024;
            workWord2=numeric5<4096;
            workWord3=-numeric5;
            if(workWord2){
                workWord2=Physics22Player94View2;
                __asm__(""::"r"(workWord3),"r"(workWord2));
                workWord3<<=1;
                workWord2=workWord2<workWord3;
                if(workWord2){
                    store94From3:Physics22Player94View2=workWord3;
                }
            }
            clamp104:globalPointer=&Physics22Player94View2;
            clamp94PointerReady:workWord2=Physics22Field(globalPointer,int*,0);
            workWord2=workWord2<-8960;
            if(!workWord2)return;
            workWord2=-8960;
            Physics22Field(globalPointer,int*,0)=workWord2;
            return;
        }
    case 109:globalVector80=&Physics22Player0View2+0x80;
        Physics22Call4F168View2(globalVector80);
        Physics22Call4F168View2(globalVector80+12);
        workWord2=Physics22Player1BAView1;
        if(!workWord2){
            workWord2=1;
            goto byteOne;
        }
        workWord2=Physics22Data6E538View1&16;
        if(workWord2){
            workWord2=1;
            goto wordOneReturn;
        }
        workWord2=1;
        Physics22Player1BAView1=0;
        byteOne:Physics22Player1B9View1=workWord2;
        wordOneReturn:__asm__(""::"r"(workWord2));
        return;
    }
}
#undef Physics22Field


int Callback22First42A44(void) __asm__("func_80042A44");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 numeric decode.
 * Original animation callback at 80097D08; private+0x30 child pointer,
 * child+0x38 halfword, player+0x74 vector, byte offsets +0x24/-0x74/+0x58.
 * Unsigned halfword load with signed shifts 16/17 and signed guarded division
 * follow original instructions. Empty constraints preserve original register
 * lifetimes and scheduling; they emit no instructions. Helper meanings, units,
 * cadence and runtime semantics remain unresolved. Acceptance requires every
 * original word/internal jump, strict complete TU, EXE and every overlay hash.
 */
extern int Callback22Step __asm__("D_80070328+0x144");
extern int Callback22Z __asm__("D_80070328+8");
extern int Callback22Limit __asm__("D_80070328+0x280");
extern Spyro Callback22Player __asm__("D_80070328");
int Callback22Call80037058(int x, int y) __asm__("func_80037058");
int Callback22Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback22Call80041930(void) __asm__("func_80041930");
void Callback22Call80041AE8(void) __asm__("func_80041AE8");
void Callback22Call80041C20(void) __asm__("func_80041C20");
void Callback22Call80042A44(void) __asm__("func_80042A44");
void Callback22Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback22Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback22Query(Vector3D*,int) __asm__("func_8001A358");
extern unsigned char* Callback22Table[] __asm__("D_8006EE2C");
extern unsigned char Callback22Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback22Call8004F110(Vector3D*,int) __asm__("func_8004F110");
int Callback22Call80038000(Moby*,Vector3D*,int,int,int) __asm__("func_80038000");
void Callback22Call8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void Callback22Call8003BE70(int) __asm__("func_8003BE70");
void func_level_22_80097D08(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; Vector3D third; int reserved44;} local;
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback22Player.animationState) {
    case 0x14:
    case 0x64:
        if(func_800438F4()==0)func_80043728();
        Callback22Call80041C20();
        Callback22Player.unk9a=0;
        goto call42A44;
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x67:
    case 0x69:
    case 0x6C:
        Callback22Call80041C20();
call42A44:
        Callback22Call80042A44();
clearSharedValue:
        Callback22Player.unk4[0]=0;
        return;
    case 0x66:
        Callback22Call80041C20();
        Callback22Call80042A44();
        descriptorMoby=Callback22Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(descriptorMoby) : "0"(descriptorMoby) : "memory");
        Callback22Player.unk4[0]=0;
        goto descriptorTail;
    case 0x65:
        func_800438F4();
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80041930();
        goto queryC00;
    case 0x13:
    case 0x15:
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80041930();
        goto clearSharedValue;
    case 0x1A:
    case 0x68:
        Callback22Call80041C20();
        Callback22Call80042A44();
queryC00:
        Callback22Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x6B:
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80041930();
        if(Callback22Player.unk7a[3].z<0 && Callback22Player.animationStateFrames>=4)
            Callback22Player.unk5=1;
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback22Z;
            register int velocity __asm__("$6")=Callback22Step;
            register int scalarPosition __asm__("$2")=*zWord;
            register int tick __asm__("$3")=D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            __asm__("" : "=r"(velocity) : "0"(velocity));
            __asm__("" : "=r"(scalarPosition) : "0"(scalarPosition));
            __asm__("" : "=r"(tick) : "0"(tick));
            increment=velocity>>6;
            __asm__("" : "=r"(increment) : "0"(increment));
            scalarPosition+=increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(scalarPosition));
            tick<<=9;
            *zWord=scalarPosition;
            status=Callback22Limit;
            velocity+=tick;
            Callback22Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback22Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback22Step=0x2580;
            }
        limitsDone:
            Callback22Call80041C20();
            Callback22Call80042A44();
            func_8004F178(&local.first,&Callback22Player.position);
            local.first.z+=0x400;
            Callback22Player.unk4[0]=Callback22Query(&local.first,0xC00);
            positionDelta=(int)Callback22Player.union144.a.unk13cb;
            positionValue=Callback22Player.position.z;
            positionDelta >>= 6;
            positionValue-=positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback22Player.position.z=positionValue;
            return;
        }
    case 0x24:
    case 0x25:
    case 0x30:
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80043A38(0xC00);
        if ((Callback22Player.ticksSinceLastSurfaceTouch == 0) && (func_80040954(Callback22Player.unk11[2]) == 9)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback22Player.ticksSinceLastSurfaceTouch + 0x94), (Vector3D *) ((unsigned char*)&Callback22Player.ticksSinceLastSurfaceTouch + 0x14));
            Callback22Player.union144.a.unk13da = Callback22Player.unk7a[3].z;
        }
        Callback22Player.unk4[0] = 0;
        if ((Callback22Player.unk5 == 1) && ((Callback22Player.animationStateFrames >= 0xD) || !(Callback22Word8006E538 & 0x40))) {
            Callback22Player.unk5 = 2;
        }
        if (Callback22Player.unk5 != 3) {
            Callback22Player.union144.a.unk13db.x = 0;
            Callback22Player.union144.a.unk13db.y = 0;
            return;
        }
        break;
    case 0x6A:
    case 0x6D: {
        register unsigned char* privateData __asm__("$17")=Callback22Player.critterMobyPtr->mobyTag;
        register int changed __asm__("$20")=0;
        register Vector3D* vectorBase __asm__("$16");
        register Vector3D* copyBase __asm__("$18");
        register unsigned char* sourceBase __asm__("$19");
        register int queryHeight __asm__("$16");
        if(*(Moby**)(privateData+0x30)!=0) {
            vectorBase=&local.second;
            sourceBase=Callback22Source;
            func_8004F178(vectorBase,(Vector3D*)sourceBase);
            Callback22Call8004F110(vectorBase,6);
            {
                Moby* child=*(Moby**)(privateData+0x30);
                child->position.z+=((int)((unsigned int)*(unsigned short*)((unsigned char*)child+0x38)<<16))>>17;
            }
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)*(Moby**)(privateData+0x30)+0xC));
            copyBase=&local.third;
            func_8004F178(copyBase,vectorBase);
            {
                int height=((int)((unsigned int)*(unsigned short*)((unsigned char*)*(Moby**)(privateData+0x30)+0x38)<<16))>>17;
                register int result=Callback22Call80038000(*(Moby**)(privateData+0x30),vectorBase,height,height,0x1022);
                register Vector3D* childVector __asm__("$4")=vectorBase;
                if(result!=0) {
                    register Vector3D* childCopy __asm__("$6")=copyBase;
                    {register Moby* childArgument __asm__("$5")=*(Moby**)(privateData+0x30);
                    __asm__ volatile("" : "=r"(changed) : "0"(changed) : "memory");
                    changed=1;
                    Callback22Call8004F1C8(childVector,(Vector3D*)((unsigned char*)childArgument+0xC),childCopy);}
                    func_8004F0E8(vectorBase,6);
                    func_8004F194((Vector3D*)sourceBase,(Vector3D*)sourceBase,vectorBase);
                }
            }
            Callback22Call80041C20();
            {register Vector3D* argument0 __asm__("$4")=(Vector3D*)(sourceBase+0x24);
            if(changed!=0) {
                register int componentX __asm__("$8")=local.second.x;
                register int divisor __asm__("$2")=D_8006C648;
                register int componentY __asm__("$7");
                register int componentZ __asm__("$3");
                componentX/=divisor;
                __asm__("" : "=r"(componentX) : "0"(componentX));
                componentY=local.second.y/divisor;
                __asm__("" : "=r"(componentY) : "0"(componentY));
                componentZ=local.second.z/divisor;
                __asm__ volatile("" : "=r"(componentZ), "=r"(argument0) : "0"(componentZ), "1"(argument0) : "memory");
                local.second.x=componentX;
                local.second.y=componentY;
                local.second.z=componentZ;
                Callback22Call8004F1C8(argument0,argument0,vectorBase);
            }}
            {register Moby* child __asm__("$2")=*(Moby**)(privateData+0x30);
            register int childValue __asm__("$3")=*(short*)((unsigned char*)child+0x38);
            register int playerValue __asm__("$2")=Callback22Player.unk4a;
            playerValue+=childValue;
            __asm__("" : "=r"(playerValue) : "0"(playerValue));
            queryHeight=playerValue+64;}
            if(Callback22Query((Vector3D*)(sourceBase-0x74),queryHeight)!=0 && Callback22Player.unk7a[2].z<=0) {
                if(Callback22Player.unk7a[2].z>=-2047)
                    Callback22Player.position.z=D_80071908+queryHeight-64;
                Callback22Player.ticksSinceLastSurfaceTouch=0;
                func_8004F178((Vector3D*)(sourceBase+0x58),&D_80071918);
            } else {
                register int* counterPointer __asm__("$2")=&Callback22Player.ticksSinceLastSurfaceTouch;
                register int counterValue __asm__("$3");
                register int vectorZ __asm__("$4");
                __asm__("" : "=r"(counterPointer) : "0"(counterPointer));
                Callback22Player.unk9e.x=0;
                Callback22Player.unk9e.y=0;
                counterValue=*counterPointer;
                __asm__ volatile("" : "=r"(counterPointer) : "0"(counterPointer) : "memory");
                vectorZ=4096;
                Callback22Player.unk9e.z=vectorZ;
                counterValue+=1;
                *counterPointer=counterValue;
            }
        } else Callback22Call80041C20();
        Callback22Player.unk4[0]=0;
        if(Callback22Player.animationState!=0x6A)return;
        descriptorMoby=Callback22Player.critterMobyPtr;
descriptorTail:
        selector=Callback22Table[descriptorMoby->mobyClass][6];
        if(selector!=(unsigned int)Callback22Player.unk22[3]) {
            if(Callback22Call8003BF6C(Callback22Player.unk22[3],Callback22Player.unk22[2])!=0)
                Callback22Call8003BE70(Callback22Player.unk22[2]);
            Callback22Player.unk22[2]=-1;
        }
        Callback22Player.unk22[3]=selector;
        if(Callback22Call8003BF6C(selector,Callback22Player.unk22[2])==0)
            Callback22Player.unk22[2]=PlaySound(Callback22Player.unk22[3],0,4);
        return;
    }
    default:
        return;
    }
}


#define LEVEL_ID 22
#define PlaySpyroSounds_level_22 func_level_22_800983C0
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_22_8009852C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1a:
    case 0x1e:
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x64:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0x6c:
    case 0x6d:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x13:
    case 0x15:
    case 0x66:
    case 0x67:
    case 0x6a:
    case 0x6b:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800985A8.
 * Reuses verified33 private0/4/8 swirl and15 flags490/trig producer, verified21
 * squish, verified37 drowning/vector, verified24 walk and signed-halfword routes.
 * Original22 supplies state13 skateboard vector14C/98, scalar2000 minimum,
 * roll5C saved in144, shared35/36 clears, and64..6D independent special states.
 * Original68 flags400 copy from21C/scale6 or signed65920/658A0 table shift1.
 * Numeric offsets are bytes; widths, branches and shifts are source-native.
 * Empty constraints retain original register lifetimes without emitting opcodes.
 * Require every original code/local jump/owned table word, strict complete TU
 * and complete EXE/every overlay hashes. Helper/audio semantics, units, cadence
 * and live runtime parity remain open. Execution is once per invocation.
 */
extern int D_8006C700;
void Transition22_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
int Transition22_func_8004E880(int,int,int) __asm__("func_8004E880");

extern Spyro Transition22_D_80070328 __asm__("D_80070328");
int Transition22_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Transition22_func_8003636C(int low, int high) __asm__("func_8003636C");
void Transition22_func_80043A38(int scale) __asm__("func_80043A38");
void Transition22_func_800441F0(void) __asm__("func_800441F0");
void Transition22_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition22_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition22RawUnion[] __asm__("D_80070328+0x144");
extern int Transition22RawMovement __asm__("D_80070328+0x50");
extern void (*Call22Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw22State[] __asm__("D_80070328+0x50");
extern short Signed22TableA[] __asm__("D_800658A0");
extern short Signed22TableB[] __asm__("D_80065920");

int Call22EA2C(int) __asm__("func_8004EA2C");
int Call22E9E4(int) __asm__("func_8004E9E4");
void func_level_22_800985A8(int arg0){
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");



    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    register unsigned char* stateBase __asm__("$17");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");

    register int oldMovementC __asm__("$5");
    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    switch(arg0){
    case 0x14:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_800441F0();
        Transition22_D_80070328.grounded = 1;
        Transition22_D_80070328.union144.a.unk13cb = Transition22_func_8003636C(1, 3);
        Transition22_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition22RawMovement;
        privateData = Transition22_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition22_D_80070328.unk5 = 0;
        Transition22_D_80070328.grounded = 0;
        Transition22_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition22_D_80070328.m_WhirlwindPointer;
        yawValue=Transition22_D_80070328.rotation.yaw;
        positionZ=Transition22_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition22_D_80070328.union144.a.unk13cc=yawValue;
        Transition22_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition22_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition22_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition22_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition22_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition22_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition22_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition22_D_80070328.unk13e[0] = (int) Transition22_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition22_D_80070328.unk20a = 0;
        Transition22_D_80070328.critterMobyPtr = 0;
        Transition22_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x15:
        Transition22_D_80070328.movementState=7;
        Transition22_D_80070328.grounded=0;
        Transition22_D_80070328.unk5=0;
        if(Transition22_D_80070328.unk17a&0x490){
            register int first __asm__("$2")=Transition22_D_80070328.unk17e.x;
            register int second __asm__("$3")=Transition22_D_80070328.unk17e.z;
            register int third __asm__("$2");
            __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second));
            first<<=6;
            Transition22_D_80070328.unk7a[2].x=first;
            __asm__ volatile("" : : : "memory");
            third=Transition22_D_80070328.unk17e.y;
            __asm__("" : "=r"(third),"=r"(second) : "0"(third),"1"(second));
            second<<=6;
            Transition22_D_80070328.unk7a[2].z=second;
            __asm__ volatile("" : "=r"(third) : "0"(third) : "memory");
            third<<=6;
            Transition22_D_80070328.unk7a[2].y=third;
        }else{
            shiftedValue=Transition22_func_8004E880(-Transition22_D_80070328.unk7a[2].x,-Transition22_D_80070328.unk7a[2].y,1);
            Transition22_D_80070328.unk7b=shiftedValue;
            Transition22_D_80070328.unk7a[2].x=(Call22EA2C(shiftedValue)<<12)>>12;
            Transition22_D_80070328.unk7a[2].y=(Call22E9E4(Transition22_D_80070328.unk7b)<<12)>>12;
            Transition22_D_80070328.unk7a[2].z=0x1000;
        }
        goto clearPointers;
    case 0x1A:
        savedBase = Transition22RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition22RawMovement;
        Transition22RawMovement = MOVEMENT_STATE_HURT;
        Transition22_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition22_func_8004F168(destination);
        Transition22_D_80070328.grounded = 1;
        Transition22_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition22RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition22RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition22_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition22_D_8006E524=value;
        stateWord=(int*)Transition22RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition22_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition22_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition22_D_80070328.unk20a=0;
        Transition22_D_80070328.critterMobyPtr=0;
        Transition22_D_80070328.unk22[3]=value;
        return;
    }
    case 0x20:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition22_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x24:case 0x25:case 0x30: {
        register unsigned char* state __asm__("$16")=Raw22State;
        register int kind __asm__("$17");
        register int previous __asm__("$2")=*(int*)state;
        register int currentScalar __asm__("$2");
        register int scalar __asm__("$3");
        register int savedRoll __asm__("$3");
        __asm__("" : "=r"(previous) : "0"(previous));
        kind=19;
        __asm__("" : "=r"(kind) : "0"(kind));

        destination=(Vector3D*)(state+0x48);
        if(previous!=kind){
            Transition22_D_80070328.union144.a.unk13db.z=0;
            Transition22_D_80070328.unk5=0;
            Transition22_func_8004F168((Vector3D*)(state+0xFC));
            Transition22_D_80070328.union144.a.unk13da=0;
            __asm__ volatile("" : "=r"(state) : "0"(state) : "memory");
            destination=(Vector3D*)(state+0x48);
        }
        *(int*)state=kind;
        Transition22_D_80070328.unk8[0]=Transition22_func_8004EDE8(destination,0);
        currentScalar=D_8006C700;
        __asm__("" : "=r"(currentScalar) : "0"(currentScalar));
        scalar=0x2000;
        __asm__("" : "=r"(scalar) : "0"(scalar));
        Transition22_D_80070328.horizontalSpeed=scalar;
        __asm__ volatile("" : "=r"(currentScalar) : "0"(currentScalar) : "memory");
        if(currentScalar<0x2000)D_8006C700=scalar;
        Transition22_func_80043A38(0xC00);
        savedRoll=Transition22_D_80070328.rotation.roll;
        __asm__("" : "=r"(savedRoll) : "0"(savedRoll));
        Transition22_D_80070328.grounded=1;
        Transition22_D_80070328.unk15c=0;
        Transition22_D_80070328.union144.a.unk13cc=0;
        Transition22_D_80070328.union144.a.unk13db.x=0;
        Transition22_D_80070328.union144.a.unk13db.y=0;
        Transition22_D_80070328.unk13a[0]=0x20000;
        Transition22_D_80070328.union144.a.unk13cb=savedRoll;
        return;
    }
    case 0x35:
    case 0x36:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_800441F0();
        Transition22_D_80070328.grounded = 1;
clearPointers:
        Transition22_D_80070328.unk20a=0;
        Transition22_D_80070328.critterMobyPtr=0;
        return;
    case 0x64:
    case 0x6D:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_800441F0();
        Transition22_D_80070328.grounded = 1;
        return;
    case 0x65:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition22_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition22_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition22_D_80070328.movementState + 0x48));
            Transition22_D_80070328.unk5 = 1;
        } else {
            Transition22_D_80070328.unk5 = 0;
        }
        Transition22_D_80070328.unk8[0] = Transition22_func_8004EDE8(&Transition22_D_80070328.unk7a[3], 0);
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x69:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.grounded = 1;
        goto clearDeathFlag;
    case 0x66:case 0x67:case 0x6A:
        stateBaseA=Raw22State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination=(Vector3D*)(stateBaseA+0x48);
        *(int*)stateBaseA=3;
        Transition22_D_80070328.unk8[0]=Transition22_func_8004EDE8(destination,0);
        Transition22_D_80070328.unk15b=1;
        Transition22_D_80070328.grounded=0;
        Transition22_D_80070328.union144.a.unk13cb=0x14;
clearSpecialTail:
        Transition22_D_80070328.idle=0;
        Transition22_D_80070328.unk15g=0;
        return;
    case 0x6B:
        savedBase = Transition22RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition22RawMovement;
        Transition22RawMovement = MOVEMENT_STATE_HURT;
        Transition22_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition22_D_80070328.unk8[0] = Transition22_func_8004EDE8(sourceC, 0);
        Transition22_D_80070328.unk7a[2].z = 0xDC0;
        Transition22_D_80070328.grounded = 0;
        Transition22_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition22_D_80070328.damageFlags & 0x200) {
            Transition22_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition22_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        return;
    case 0x6C:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
clearDeathFlag:
        Transition22_D_8006E524 = 0xF;
        return;
    case 0x68: {
        register int previousMovement __asm__("$2")=Transition22RawMovement;
        register int kind __asm__("$3");
        register int flags __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        kind=7;
        __asm__("" : "=r"(kind) : "0"(kind));
        Transition22RawMovement=kind;
        __asm__ volatile("" : : : "memory");
        flags=Transition22_D_80070328.unk17a;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        unionPointer=Transition22RawUnion;
        __asm__("" : "=r"(flags),"=r"(unionPointer) : "0"(flags),"1"(unionPointer));
        Transition22_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        *(int*)unionPointer=previousMovement;
        if(flags&0x400){
            sourceC=(Vector3D*)(unionPointer-0xB8);
            func_8004F178(sourceC,(Vector3D*)(unionPointer+0xD8));
            Transition22_func_8004F0E8(sourceC,6);
        }else if(Transition22_D_80070328.unk22[5]>=0){
            tableOffsetOrValue=Transition22_D_80070328.unk22[5]*2;
            tableValueA=*(short*)((unsigned char*)Signed22TableB+tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            Transition22_D_80070328.unk7a[2].x=tableValueA>>1;
            tableOffsetOrValue=*(short*)((unsigned char*)Signed22TableA+tableOffsetOrValue);
            Transition22_D_80070328.unk7a[2].z=0;
            __asm__ volatile("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Transition22_D_80070328.unk7a[2].y=tableOffsetOrValue>>1;
        }else Transition22_func_8004F168((Vector3D*)(unionPointer-0xB8));
        destination=&Transition22_D_80070328.unk7a[1];
        func_8004F178(destination,(Vector3D*)((unsigned char*)destination+0xC));
        Transition22_D_80070328.grounded=1;
        Transition22_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        return;
    }
    default:return;
    }
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * func_level_22_80098E80:1269 original instructions and91 dispatch words, evidence4906.
 * Verified animation selector/input handler idioms reused; raw19..109 states
 * follow original private pointer, callback and numeric branch chains.
 * Field units, helper meanings and update cadence unresolved. Acceptance:
 * every original native/internal-target/table word and full retail hashes. */
#define A4891Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern int A4891W48 __asm__("D_80070328 + 0x48");
extern unsigned char* A4891W250 __asm__("D_80070328 + 0x250");
extern volatile int A4891Buttons __asm__("D_8006E538");
extern unsigned char A4891E535 __asm__("D_8006E535");
extern int A4891WB8 __asm__("D_80070328 + 0xB8");
extern int A4891WE4 __asm__("D_80070328 + 0xE4");
extern int A4891WA8 __asm__("D_80070328 + 0xA8");
extern int A4891WAC __asm__("D_80070328 + 0xAC");
extern int A4891WB0 __asm__("D_80070328 + 0xB0");
extern int A4891W144 __asm__("D_80070328 + 0x144");
extern int A4891WA0 __asm__("D_80070328 + 0xA0");
extern int A4891W8 __asm__("D_80070328 + 8");
extern int A4891W4C __asm__("D_80070328 + 0x4C");
extern int A4891W94 __asm__("D_80070328 + 0x94");
extern int A4891W54 __asm__("D_80070328 + 0x54");
extern int A4891WCC __asm__("D_80070328 + 0xCC");
extern int A4891W8C __asm__("D_80070328 + 0x8C");
extern int A4891WD0 __asm__("D_80070328 + 0xD0");
extern int A4891W90 __asm__("D_80070328 + 0x90");
extern int A4891WD4 __asm__("D_80070328 + 0xD4");
extern unsigned char A4891Table[] __asm__("D_800676E8");
extern int A4891Row __asm__("D_8006C58C"), A4891Column __asm__("D_8006C5C8");
extern int (*A4891Callback)(int) __asm__("unk_ovlheader_8007431C");
void A4891Select(int) __asm__("func_8004BEF8");
void A4891H498C0(void) __asm__("func_800498C0");

extern int A4898W48 __asm__("D_80070328 + 0x48");
extern int A4898W4C __asm__("D_80070328 + 0x4C");
extern int A4898W54 __asm__("D_80070328 + 0x54");
extern int A4898WA0 __asm__("D_80070328 + 0xA0");
extern int A4898WA8 __asm__("D_80070328 + 0xA8");
extern int A4898WAC __asm__("D_80070328 + 0xAC");
extern int A4898WB0 __asm__("D_80070328 + 0xB0");
extern int A4898WB8 __asm__("D_80070328 + 0xB8");
extern int A4898WCC __asm__("D_80070328 + 0xCC");
extern int A4898WD0 __asm__("D_80070328 + 0xD0");
extern int A4898WD4 __asm__("D_80070328 + 0xD4");
extern int A4898W8C __asm__("D_80070328 + 0x8C");
extern int A4898W90 __asm__("D_80070328 + 0x90");
extern int A4898W94 __asm__("D_80070328 + 0x94");
extern int A4898WE4 __asm__("D_80070328 + 0xE4");
extern int A4898W144 __asm__("D_80070328 + 0x144");
extern int A4898W158 __asm__("D_80070328 + 0x158");
extern int A4898W1EC __asm__("D_80070328 + 0x1EC");
extern int A4898W1F0 __asm__("D_80070328 + 0x1F0");
extern int A4898W240 __asm__("D_80070328 + 0x240");
extern int A4898W280 __asm__("D_80070328 + 0x280");
extern unsigned char A4898B14 __asm__("D_80070328 + 0x14");
extern unsigned char A4898B15 __asm__("D_80070328 + 0x15");
extern unsigned char A4898B16 __asm__("D_80070328 + 0x16");
extern unsigned char A4898B17 __asm__("D_80070328 + 0x17");
extern unsigned char A4898B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A4898BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A4898B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A4898B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A4898Player[] __asm__("D_80070328");
extern unsigned char A4898Table[] __asm__("D_80066530");
extern int A4898Buttons __asm__("D_8006E538"),A4898NewButtons __asm__("D_8006E53C");
extern int A4898Mode __asm__("D_8006E044"),A4898Gate __asm__("D_8006E344"),A4898Count __asm__("D_8006C514");
extern int (*A4898Callback)() __asm__("unk_ovlheader_80074374");
extern int A4898W24 __asm__("D_80070328 + 0x24");
extern int A4898W28C __asm__("D_80070328 + 0x28C");
extern int A4898W290 __asm__("D_80070328 + 0x290");
extern int A4898Surface __asm__("D_8006FA38");
extern unsigned char* A4898SoundDesc __asm__("D_8006C654");
int A4898Sound() __asm__("PlaySound");
int A4898H3BF6C() __asm__("func_8003BF6C");
int A4898H3BE70() __asm__("func_8003BE70");
int A4898H40994() __asm__("func_80040994");
int A4898H4BEF8() __asm__("func_8004BEF8");
int A4898H49688() __asm__("func_80049688");
int A4898H4F334() __asm__("func_8004F334");
int A4898H498C0() __asm__("func_800498C0");
extern volatile int A4898W20C __asm__("D_80070328 + 0x20C");
extern int A4898W214 __asm__("D_80070328 + 0x214");
extern unsigned char A4898B100 __asm__("D_80070328 + 0x100");
extern unsigned char A4898E535 __asm__("D_8006E535");
extern unsigned char* A4898Models __asm__("D_8006EE2C");
int A4898H40BCC() __asm__("func_80040BCC");
int A4898H1A310() __asm__("func_8001A310");
extern int A4898W10C __asm__("D_80070328 + 0x10C");
extern int A4898WB4 __asm__("D_80070328 + 0xB4");
extern int A4898WA4 __asm__("D_80070328 + 0xA4");
extern int (*A4898Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A4898H40954() __asm__("func_80040954");

extern int A4907WBC __asm__("D_80070328 + 0xBC");
extern int A4907W160 __asm__("D_80070328 + 0x160");
extern int A4907W15C __asm__("D_80070328 + 0x15C");
extern int A4907W88 __asm__("D_80070328 + 0x88");
extern int A4907W84 __asm__("D_80070328 + 0x84");
extern int A4907W68 __asm__("D_80070328 + 0x68");
extern int A4907W6C __asm__("D_80070328 + 0x6C");
int A4908H3BABC() __asm__("func_8003BABC");
int A4908H4F1C8() __asm__("func_8004F1C8");
int A4908H4EDE8() __asm__("func_8004EDE8");
int A4907H3BABC() __asm__("func_8003BABC");
int A4907H4ED6C() __asm__("func_8004ED6C");
int A4907H4EF04() __asm__("func_8004EF04");
int A4907H41848() __asm__("func_80041848");
int A4907H4F178() __asm__("func_8004F178");
int A4907H4F08C() __asm__("func_8004F08C");
int A4907H4F194() __asm__("func_8004F194");
int A4907H43E00() __asm__("func_80043E00");
int A4907H4F110() __asm__("func_8004F110");
int A4907H4F1C8() __asm__("func_8004F1C8");
int A4907H4EDE8() __asm__("func_8004EDE8");

void func_level_22_80098E80(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int selector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* private16 __asm__("$16");
    register unsigned char* object4 __asm__("$4");
    register unsigned char* table4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");

    struct {int first[4],second[4],third[4],fourth[4],fifth[4],sixth[4],seventh[4],eighth[4];} frame;
    register int* state __asm__("$16");
    register int* saved16 __asm__("$16");
    register int* saved17 __asm__("$17");
    register int* saved18 __asm__("$18");
    register int* saved19 __asm__("$19");
    register int* state4 __asm__("$4");
    register int call6 __asm__("$6");
    work2 = A4891W48;
    switch (work2) {
    case 22: case 23: case 24: case 25: case 27: case 28: case 29: case 31: case 33: case 34: case 35: case 38: case 39: case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 49: case 50: case 51: case 52: case 55: case 56: case 57: case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89: case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: return;

 case 20:
  if(A4898H40994())return;
  work2=A4898NewButtons&64;selector4=6;if(work2)goto select;
  work2=A4898WB8<4;selector4=7;if(!work2)goto select;if(A4898WE4>=23)goto select;
  work3=A4898Buttons;
  work2=work3&128;selector4=13;if(work2)goto select;
  work2=A4898WA8;if(work2<0)work2=-work2;
  if(work2>=17){selector4=1;goto select;}
  work2=work3&12;
  __asm__("" : "=r"(work2):"0"(work2));
  if(!work2){work2=A4898WAC;selector4=1;if(work2)goto select;}
  if(A4898Mode==7 || A4898W240) {
   state=&A4898W48;__asm__("" : "=r"(state):"0"(state));
   if(!*state)return;
   A4898H4BEF8(0);
   if(A4898Table[*((unsigned char*)state-0x2C)]>=96){A4898B14=A4898B15;A4898B16=A4898B17;}
   A4898B17=0;work3=*state;work2=113;*((unsigned char*)state-0x2C)=work2;
   A4898W1F0=0;A4898B15=work3;A4898W1EC=work3;return;
  }
  work2=A4898BFC;selector4=15;if(work2)goto select;
  A4898H49688();return;
 case 53: case 54:
  if(A4898H40994())return;
  selector4=0;goto select;

 case 19:
  if(A4898H40994())return;
  work2=13;work3=A4898Gate;
  if(work3==work2){work2=A4898Count;selector4=17;if(work2)goto select;}
  selector4=(int)A4898Player;work2=A4898H4F334((void*)selector4,(void*)(selector4+348));
  work3=A4898W158;work3=work3<work2;selector4=17;if(!work3)return;goto select;
 case 21:
  if(A4898W54<33)return;
  if(!A4898WB8){A4898H4BEF8(4);A4898W4C=1;return;}
  work2=A4907WBC;selector4=7;if(work2)return;goto select;

 case 26:
  if(A4898W24&16)return;
  if(A4898W54<25)return;
  if(A4898W280<0){selector4=32;goto select;}
  A4898Sound(A4898SoundDesc[15],0,0);
  work3=A4898W144;work2=10;if(work3==work2){__asm__ volatile("" ::: "memory");selector4=44;goto select;}
  work2=work3-11;if((unsigned)work2<2){__asm__ volatile("" ::: "memory");selector4=41;goto select;}
  work2=A4898WB8;selector4=0;if(!work2)goto select;__asm__ volatile("" ::: "memory");selector4=7;goto select;
 case 30: {
  register int* timer4 __asm__("$4");
  register int (*callback3)() __asm__("$3");
  if(A4898NewButtons&64)A4898B1B6=1;
  if(A4898Surface>=0){
   if(A4898W144<=0x8FFF)return;
   callback3=A4898Callback;A4898W28C=-1;
   if(callback3){callback3();return;}
   goto call498C0;
  }
  timer4=&A4898W280;__asm__("" : "=r"(timer4):"0"(timer4));
  if(*timer4<0){
   if(A4898W144<=0x8FFF)return;
   A4898W28C=-1;call498C0:A4898H498C0();__asm__ volatile("" ::: "memory");return;
  }
  work3=A4898W54;
  if(work3>=61){*timer4=-1;return;}
  work2=work3<16;
  __asm__("" : "=r"(work2):"0"(work2));
  if(work2)return;
  if(!A4898B1B6)return;
  if(A4898W28C>=0){
   if(A4898H3BF6C(A4898W290,A4898W28C))A4898H3BE70(A4898W28C);
   A4898W28C=-1;
  }
  selector4=6;goto select;
 }
 case 32:
  if(A4898W54>=125)goto call498C0;
  return;

 case 36:
  if(A4898H40994())return;
  saved16=&A4898W4C;work2=*saved16;
  if((unsigned)(work2-1)<2 && !A4898WB8){
   if(A4898WE4>=60)goto expired36;
   frame.first[0]=0;frame.first[1]=0;frame.first[2]=4096;
   A4907H4ED6C(saved16-7,frame.first,frame.first);
   A4907H4EF04(saved16+32,4096);
work3=frame.first[0];work2=saved16[32];product5=work3*work2;
  work3=frame.first[1];work2=A4898WD0;selector4=work3*work2;
  work3=frame.first[2];work2=A4898WD4;work3*=work2;
  work2=product5+selector4;work2+=work3;work2>>=12;

   selector4=21;if(work2<1536)goto select;
   product5=2;object4=A4891W250;
   __asm__("" : "=r"(object4):"0"(object4));call6=0;
   __asm__("" : "=r"(object4),"=r"(product5),"=r"(call6):"0"(object4),"1"(product5),"2"(call6));
   *saved16=0;A4908H3BABC(object4,product5,call6);return;
  expired36:__asm__ volatile("" ::: "memory");selector4=21;goto select;
  }
  state4=&A4898W4C;work3=*state4;work2=3;
  if(work3==work2){
   if(A4898Buttons&64)A4898B1B6=1;
   work2=A4898H40954(A4898W10C);work3=9;
   if(work2!=work3){
    if(A4898WA0>0 && A4907W160>=4)A4898WB8=1;
    else A4898W4C=0;
   }
   saved17=&A4898WB8;__asm__("" : "=r"(saved17):"0"(saved17));work2=*saved17;
   if(!work2)goto remainder36;
   if(A4898W158<=2048)goto reset36;
   A4907H41848();work3=A4907W15C;work2=2;
   if(work3==work2){
    selector4=48;
    if(A4898B1B6){work2=A4907W88;work2+=3840;A4907W88=work2;work2=4;goto set36;}
    work2=4;goto set36;
   }
   if(A4898B1B6 || work3==1){
    A4907H4F178(frame.first,saved17+37);
    frame.first[2]=0;A4907H4EF04(frame.first,4096);
    work3=frame.first[0];work2=saved17[-14];call6=work3*work2;
    work3=frame.first[1];work2=A4907W84;work3*=work2;
    call6+=work3;call6>>=12;call6=-call6;
    A4907H4F08C(frame.first,4096,call6);
    saved16=saved17-14;A4907W88+=2048;
    A4907H4F194(saved16,saved16,frame.first);
    A4907H43E00(saved16);A4907H4F110(frame.first,4);
    A4907H4F194(saved17-46,saved17-46,frame.first);
    selector4=37;A4907W68=0;A4907W6C=0;work2=5;goto set36;
   }
   selector4=48;work2=4;
  set36:
   A4898W4C=work2;A4898H4BEF8(selector4);
   A4907H3BABC(A4891W250,1,0);
   saved16=&A4898W8C;selector4=(int)saved16;
   __asm__("" : "=r"(selector4):"0"(selector4));saved17=saved16-3;
   A4907H4F178((void*)selector4,saved17);A4907H4F178(saved16+3,saved17);return;
 reset36:A4898W4C=0;goto remainder36;
  }
  if(work3)goto remainder36;
  if(A4898WB8<5 && (A4898NewButtons&64)){
   work2=1;work3=A4898WA0;*state4=work2;A4898W54=0;work3+=3520;A4898W94=work3;return;
  }
  work2=A4898WB8;
  if(work2){work2=work2<5;goto count36;}
  work2=A4898WE4;work2=work2<48;selector4=21;if(!work2)goto select;
  __asm__ volatile("" ::: "memory");work2=A4898WB8;work2=work2<5;
 count36:
  if(!work2){work2=1;A4898W4C=work2;A4898W54=0;}
 remainder36:
  saved18=frame.second;
  selector4=(int)saved18;__asm__("" : "=r"(selector4):"0"(selector4));
  saved16=&A4898W8C;product5=(int)saved16;
  __asm__("" : "=r"(product5):"0"(product5));saved17=saved16+3;
  A4908H4F1C8((void*)selector4,(void*)product5,saved17);
  saved19=frame.third;A4908H4F1C8(saved19,saved16-3,saved17);
  work2=A4908H4EDE8(saved18,1);work3=A4898WAC;work2<<=8;work2/=work3;
  if(work2<218)return;
  work2=A4908H4EDE8(saved19,1);work3=A4898WAC;work2<<=8;work2/=work3;
  __asm__ volatile("" : "=r"(work2):"0"(work2):"$4");
  work2=work2<218;selector4=21;if(work2)return;
  __asm__ volatile("" ::: "memory");goto select;

 case 48:
  if(A4898H40994())return;
  saved16=&A4898WB8;
  if(!*saved16 && A4898WE4<60){
   frame.fourth[0]=0;frame.fourth[1]=0;frame.fourth[2]=4096;
   A4907H4ED6C(saved16-34,frame.fourth,frame.fourth);
   A4907H4EF04(saved16+5,4096);
work3=frame.fourth[0];work2=saved16[5];product5=work3*work2;
  work3=frame.fourth[1];work2=A4898WD0;selector4=work3*work2;
  work3=frame.fourth[2];work2=A4898WD4;work3*=work2;
  work2=product5+selector4;work2+=work3;work2>>=12;

   selector4=21;if(work2<1536)goto select;
   A4898W4C=0;A4898H4BEF8(36);
   object4=A4891W250;product5=2;goto partialBABC;
  }

  saved18=frame.fifth;
  selector4=(int)saved18;__asm__("" : "=r"(selector4):"0"(selector4));
  saved16=&A4898W8C;product5=(int)saved16;
  __asm__("" : "=r"(product5):"0"(product5));saved17=saved16+3;
  A4907H4F1C8((void*)selector4,(void*)product5,saved17);
  saved19=frame.sixth;A4907H4F1C8(saved19,saved16-3,saved17);
  work2=A4907H4EDE8(saved18,1);work3=A4898WAC;work2<<=8;work2/=work3;
  if(work2<218)return;
  work2=A4907H4EDE8(saved19,1);work3=A4898WAC;work2<<=8;work2/=work3;
  __asm__("" ::: "$4");
  work2=work2<218;selector4=21;if(work2)return;
  __asm__ volatile("" ::: "memory");goto select;

 case 37:
  if(A4898H40994())return;
  saved17=&A4898WB8;
  if(*saved17)return;
  if(A4898WE4>=60)return;
  saved19=saved17-34;selector4=(int)saved19;
  __asm__("" : "=r"(selector4):"0"(selector4));saved16=frame.seventh;
  product5=(int)saved16;call6=product5;
  __asm__("" : "=r"(product5),"=r"(call6):"0"(product5),"1"(call6));saved18=(int*)4096;
  frame.seventh[0]=0;frame.seventh[1]=0;frame.seventh[2]=(int)saved18;
  A4907H4ED6C((void*)selector4,(void*)product5,(void*)call6);
  A4907H4EF04(saved17+5,4096);
work3=frame.seventh[0];work2=saved17[5];product5=work3*work2;
  work3=frame.seventh[1];work2=A4898WD0;selector4=work3*work2;
  work3=frame.seventh[2];work2=A4898WD4;work3*=work2;
  work2=product5+selector4;work2+=work3;work2>>=12;

  selector4=21;if(work2<1536)goto select;
  frame.seventh[0]=(int)saved18;frame.seventh[1]=0;frame.seventh[2]=0;
  A4907H4ED6C(saved19,saved16,saved16);
  saved16=frame.eighth;A4907H4F178(saved16,saved17-8);
  A4907H4EF04(saved16,4096);
  work3=frame.seventh[0];work2=frame.eighth[0];product5=work3*work2;
  work3=frame.seventh[1];work2=frame.eighth[1];selector4=work3*work2;
  work3=frame.seventh[2];work2=frame.eighth[2];work3*=work2;
  A4898W4C=0;work2=product5+selector4;work2+=work3;work2>>=12;
  selector4=21;if(work2<2560)goto select;
  A4898H4BEF8(36);object4=A4891W250;product5=2;
 partialBABC:
  A4907H3BABC(object4,product5,0);return;

    case 100:
        work2 = (int) A4891W250;
        callback3 = A4891Callback;
        private16 = A4891Field((void*) work2, unsigned char**, 0);
        if (callback3(25)) return;
        work2 = A4891Field(private16, int*, 0x30);
        selector4 = 106;
        if (work2) goto select;
        work3 = A4891Buttons;
        work2 = work3 & 64;
        selector4 = 102;
        if (work2) goto select;
        work2 = A4891WB8 < 4;
        selector4 = 103;
        if (!work2) goto select;
        if (A4891WE4 >= 23) goto select;
        work2 = A4891WA8;
        if (work2 < 0) work2 = -work2;
        if (work2 >= 17) { __asm__ volatile("" ::: "memory"); selector4 = 101; goto select; }
        work2 = work3 & 12;
        if (work2) return;
        work2 = A4891WAC;
        selector4 = 101;
        if (!work2) return;
        goto select;

    case 101:
        work2 = (int) A4891W250;
        callback3 = A4891Callback;
        private16 = A4891Field((void*) work2, unsigned char**, 0);
        if (callback3(25)) return;
        work2 = A4891Field(private16, int*, 0x30);
        selector4 = 106;
        if (work2) goto select;
        work2 = A4891Buttons & 64;
        selector4 = 102;
        if (work2) goto select;
        work2 = A4891WB8 < 4;
        selector4 = 103;
        if (!work2) goto select;
        if (A4891WE4 >= 23) goto select;
        if (A4891E535) { work2 = A4891WB0; selector4 = 100; if (!work2) goto select; }
        if (!(A4891Buttons & 12)) return;
        work2 = A4891W144 < 16;
        selector4 = 100;
        if (work2) return;
        goto select;

    case 102:
        work2 = (int) A4891W250;
        callback3 = A4891Callback;
        private16 = A4891Field((void*) work2, unsigned char**, 0);
        if (callback3(25)) return;
        work2 = A4891Field(private16, int*, 0x30);
        selector4 = 106;
        if (work2) goto select;
        if (!A4891WB8 && A4891WA0 <= 0) {
            __asm__ volatile("" ::: "memory");
            if (A4891WE4 >= 23) return;
            work2 = A4891WAC;
            selector4 = 101;
            if (work2) goto select;
            __asm__ volatile("" ::: "memory");
            selector4 = 100;
            goto select;
        }
        if (A4891W144 < 11) return;
                table4 = A4891Table;
        work2 = A4891Row;
        work3 = A4891Column;
        work2 = (work2 << 4) + (int) table4;
        work3 = (work3 << 2) + work2;
        work2 = A4891W8;
        work3 = A4891Field((void*) work3, int*, 0);
        work2 -= work3;
        if (work2 <= 4096) return;
        work3 = A4891W4C;
        selector4 = 103;
        if (work3 == 127) return;
        goto select;

    case 103:
        work2 = (int) A4891W250;
        callback3 = A4891Callback;
        private16 = A4891Field((void*) work2, unsigned char**, 0);
        if (callback3(25)) return;
        work2 = A4891Field(private16, int*, 0x30);
        selector4 = 106;
        if (work2) goto select;
        work2 = A4891Buttons & 64;
        selector4 = 102;
        if (work2) goto select;
        if (!A4891WB8) {
            if (A4891WE4 >= 23) return;
            work2 = A4891WAC;
            selector4 = 101;
            if (work2) goto select;
            selector4 = 100;
            goto select;
        }
                table4 = A4891Table;
        work2 = A4891Row;
        work3 = A4891Column;
        work2 = (work2 << 4) + (int) table4;
        work3 = (work3 << 2) + work2;
        work2 = A4891W8;
        work3 = A4891Field((void*) work3, int*, 0);
        work2 -= work3;
        selector4 = 102;
        if (work2 >= 4096) return;
        goto select;

    case 104:
                object4 = A4891W250;
        work2 = A4891W48;
        work3 = A4891Field(object4, unsigned char*, 0x3C);
        work2 -= 100;
        if (work3 != work2) return;
        work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
        if (!work2) return;
        work2 = A4891WB8;
        selector4 = 100;
        if (!work2) goto select;
        selector4 = 103;
        goto select;

    case 105:
    case 108:
                object4 = A4891W250;
        work2 = A4891W48;
        work3 = A4891Field(object4, unsigned char*, 0x3C);
        work2 -= 100;
        if (work3 != work2) return;
        work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
        if (!work2) return;
        goto call498C0;

    case 106:
        work2 = (int) A4891W250;
        callback3 = A4891Callback;
        private16 = A4891Field((void*) work2, unsigned char**, 0);
        if (callback3(25)) return;
        if (!A4891Field(private16, int*, 0x30)) {
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2) goto select;
            selector4 = 103;
            goto select;
        }
        if (A4891WB8) return;
        work2 = A4891W94;
        if (work2 > 0) return;
        work2 = -(work2 << 1) >> 2;
        A4891W94 = work2;
        A4891WA0 = work2;
        selector4 = 109;
        if (work2 >= 1024) return;
        goto select;

    case 107:
        if (!A4891WB8 && A4891W54 >= 16) {
            if (A4891WE4 >= 23) return;
            work3 = A4891WCC;
            work2 = A4891W8C;
            product5 = work3 * work2;
            work3 = A4891WD0;
            work2 = A4891W90;
            selector4 = work3 * work2;
            work3 = A4891WD4;
            work2 = A4891W94;
            work3 *= work2;
            work2 = product5 + selector4;
            work2 += work3;
            if (work2 >= 0) return;
            work2 = A4891WAC;
            selector4 = 100;
            if (!work2) goto select;
            selector4 = 101;
            goto select;
        }
        work2 = A4891Buttons & 64;
        if (work2 && A4891W4C == 1) { selector4 = 102; goto select; }
                object4 = A4891W250;
        work2 = A4891W48;
        work3 = A4891Field(object4, unsigned char*, 0x3C);
        work2 -= 100;
        if (work3 != work2) return;
        work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
        if (!work2) return;
        selector4 = 103;
        goto select;

    case 109:
        work2 = (int) A4891W250;
        callback3 = A4891Callback;
        private16 = A4891Field((void*) work2, unsigned char**, 0);
        if (callback3(25)) return;
        if (!A4891Field(private16, int*, 0x30) || A4891WB8 >= 4) {
            __asm__ volatile("" ::: "memory");
            selector4 = 103;
            goto select;
        }
        work2 = A4891Buttons & 64;
        selector4 = 102;
        if (work2) goto select;
        __asm__("" ::: "$4");
        if (A4891E535) return;
        A4891WA0 = 1536;
        selector4 = 102;
        goto select;
    }
    return;
select:
    A4891Select(selector4);
}
#undef A4891Field
