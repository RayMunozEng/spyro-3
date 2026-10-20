#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80094D30.
 * Assembly SHA256 042d5a51d88e95182ab50b81bc58fc6a93817f0d1220905d59efc73b43f7ab59.
 * AI-generated; not human reviewed. All1277 original instructions,
 * 91 selectors (bias19) and one owned table-padding word are required.
 * Original19 retains signed halfword table producers, wrapped shifts,
 * three distinct low products, guarded variable division, pointer8 and
 * every original vector/helper/clamp join. Original47/50..52 retain raw
 * signed direction tests and helper3194 selectors0..3 at their exact guards.
 * Nine physical case groups reuse decoded13/verified27 source references;
 * decoded13 is uninstalled and is not itself acceptance evidence.
 * This function's original0xE0 frame retains scratch10..C4 and savedS0..S3.
 * Typed aliases remain distinct. Empty initialized constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every original native/linked instruction, conditional/internal
 * target, selector/padding/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics34Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics34Call363DCView1() __asm__("func_800363DC");
unsigned char Physics34Call40D10View1() __asm__("func_80040D10");
unsigned char Physics34Call41580View1() __asm__("func_80041580");
unsigned char Physics34Call416F4View1() __asm__("func_800416F4");
unsigned char Physics34Call417FCView1() __asm__("func_800417FC");
unsigned char Physics34Call41B64View1() __asm__("func_80041B64");
int Physics34Call4E9E4View1() __asm__("func_8004E9E4");
int Physics34Call4EA2CView1() __asm__("func_8004EA2C");
unsigned char Physics34Call4ED6CView1() __asm__("func_8004ED6C");
int Physics34Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics34Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics34Call4F168View1() __asm__("func_8004F168");
unsigned char Physics34Call4F178View1() __asm__("func_8004F178");
unsigned char Physics34Call4F194View1() __asm__("func_8004F194");
unsigned char Physics34Call4F1C8View1() __asm__("func_8004F1C8");
int Physics34CallRandView1() __asm__("rand");
extern unsigned char Physics34Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics34Data65920View1 __asm__("D_80065920");
extern void *Physics34Data6C570View1 __asm__("D_8006C570");
extern int Physics34Data6C640View1 __asm__("D_8006C640");
extern int Physics34Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics34Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics34Player0View1 __asm__("D_80070328");
extern int Physics34Player94View1 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics34Call40D10View2() __asm__("func_80040D10");
int Physics34Call41580View2() __asm__("func_80041580");
int Physics34Call416F4View2() __asm__("func_800416F4");
int Physics34Call417FCView2() __asm__("func_800417FC");
int Physics34Call41848View1() __asm__("func_80041848");
int Physics34Call41B64View2() __asm__("func_80041B64");
int Physics34Call4E9E4View2() __asm__("func_8004E9E4");
int Physics34Call4EA2CView2() __asm__("func_8004EA2C");
int Physics34Call4EDE8View2() __asm__("func_8004EDE8");
int Physics34Call4F08CView2() __asm__("func_8004F08C");
int Physics34Call4F168View2() __asm__("func_8004F168");
int Physics34Call4F178View2() __asm__("func_8004F178");
int Physics34Call4F194View2() __asm__("func_8004F194");
int Physics34Call4F1C8View2() __asm__("func_8004F1C8");
int Physics34Call4F284View1() __asm__("func_8004F284");
extern unsigned char Physics34Data676E8View1 __asm__("D_800676E8");
extern int* Physics34Data6C570View2 __asm__("D_8006C570");
extern int Physics34Data6C58CView1 __asm__("D_8006C58C");
extern int Physics34Data6C5C8View1 __asm__("D_8006C5C8");
extern short Physics34Data6E040View1 __asm__("D_8006E040");
extern int Physics34Data6E044View2 __asm__("D_8006E044");
extern int Physics34Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics34Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics34PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics34Player94View2 __asm__("D_80070328+0x94");
extern int Physics34PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics34Player80View1 __asm__("D_80070328+0x80");
extern int Physics34PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics34Player64View1 __asm__("D_80070328+0x64");
extern int Physics34Player144View1 __asm__("D_80070328+0x144");
extern int Physics34PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics34Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics34PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics34PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics34Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics34Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics34Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics34Player101View1 __asm__("D_80070328+0x101");
extern int Physics34PlayerA4View1 __asm__("D_80070328+0xA4");
extern int Physics34Player210View1 __asm__("D_80070328+0x210");
extern int Physics34PlayerF8View1 __asm__("D_80070328+0xF8");
extern int Physics34Player8View1 __asm__("D_80070328+0x8");
int Physics34Call40F48View1() __asm__("func_80040F48");
int Physics34Call43194View1() __asm__("func_80043194");
int Physics34Call4E880View1() __asm__("func_8004E880");
int Physics34Call4ED6CView2() __asm__("func_8004ED6C");
int Physics34Call4EDE8View3() __asm__("func_8004EDE8");
int Physics34Call4F08CView3() __asm__("func_8004F08C");
int Physics34Call4F168View3() __asm__("func_8004F168");
int Physics34Call4F178View3() __asm__("func_8004F178");
int Physics34Call4F194View3() __asm__("func_8004F194");
int Physics34Call4F1C8View3() __asm__("func_8004F1C8");
extern unsigned char Physics34Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics34Data65920View2 __asm__("D_80065920");
extern int Physics34Data6C514View1 __asm__("D_8006C514");
extern int Physics34Data6E044View3 __asm__("D_8006E044");
extern int Physics34Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics34Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics34Player16CView1 __asm__("D_80070328+0x16C");
void func_level_34_80094D30(int slotIndex) {
    register int rawValue2 __asm__("$2");
    register int stateSelector3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void *vectorAt40 __asm__("$16");
    register void *savedPointer17 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    register int product9 __asm__("$9");
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4;
    }
    originalFrame;
    register int signedTableWord __asm__("$7");
    register void *savedPointer16 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *savedPointer18 __asm__("$18");
    register void *savedPointer19 __asm__("$19");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$18");
    int temp_v0_4;
    int temp_v0_6;
    register int rawValue3 __asm__("$3");
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
    void *raw34_temp_a0_3;
    void *raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
    int raw34_temp_v0_8;
    rawValue2=slotIndex*16;
    globalPointer=&Physics34Data6E548View1;
    rawValue2+=(int)globalPointer;
    __asm__("":"=r"(rawValue2):"0"(rawValue2));
    Physics34Data6C570View1=(void*)rawValue2;
    rawValue2=Physics34Field(&Physics34Player0View1,int*,0x54);
    stateSelector3=Physics34Field(&Physics34Player0View1,int*,0x48);
    combinedIndex=rawValue2+slotIndex;
    switch (stateSelector3) {
    case 53:case 54:savedPointer16 = &Physics34Player0View1 + 0x80;
        Physics34Call4F168View1(savedPointer16);
        Physics34Call4F168View1(savedPointer16 + 0xC);
        if (Physics34Data6E044View1 != 7) {
            Physics34Call40D10View1(0x1200);
            Physics34Call416F4View1();
            Physics34Call41580View1(0x5A, 0x10);
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
            rawValue3=Physics34Data6E344View1;
            rawValue2=13;
            if(rawValue3==rawValue2){
                rawValue2=Physics34Data6C514View1;
                if(rawValue2)return;
            }
            savedPointer17=&Physics34Player0View3+8;
            rawValue3=Physics34Field(savedPointer17,int*,0);
            rawValue2=Physics34Field(&Physics34Player0View3,int*,0x144);
            numeric4=rawValue3-rawValue2;
            rawValue2=numeric4<1024;
            if(!rawValue2)goto beyond19;
            rawValue2=Physics34Player94View2;
            rawValue2+=128;
            Physics34Player94View2=rawValue2;
            rawValue2=rawValue2<4801;
            __asm__("":"=r"(numeric4):"0"(numeric4),"r"(rawValue2));
            if(!rawValue2){
                rawValue2=4800;
                Physics34Player94View2=rawValue2;
            }
            product9=numeric4*numeric4;
            call4=&originalFrame.sp10;
            rawValue3=Physics34Field(&Physics34Player0View3,int*,0x148);
            __asm__("":"=r"(product9):"0"(product9),"r"(rawValue2),"r"(rawValue3),"r"(call4));
            rawValue2=product9>>11;
            angle16=rawValue2+rawValue3;
            Physics34Player64View1=angle16;
            __asm__ volatile("":"=r"(savedPointer17):"0"(savedPointer17),"r"(call4):"memory");
            Physics34Call4F178View3(call4,savedPointer17+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics34Call4F1C8View3(call4,call5,savedPointer17-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            rawValue2=Physics34Call4EDE8View3(call4,call5);
            numeric6=rawValue2;
            rawValue2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(rawValue2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x80094EC8):"memory");
            numeric6=1024;
            goto limit19;
            beyond19:numeric5=Physics34Field(&Physics34Player0View3,int*,0x14C);
            rawValue2=rawValue3-numeric5;
            rawValue2=rawValue2<-1024;
            numeric6=numeric5-rawValue3;
            if(!rawValue2)goto curve19;
            __asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x80094EEC));
            rawValue2=Physics34Player4CView1;
            rawValue3=1;
            if(!rawValue2){
                rawValue2=Physics34Field(&Physics34Player0View3,int*,0x148);
                Physics34Player4CView1=rawValue3;
                rawValue2+=512;
                Physics34Field(&Physics34Player0View3,int*,0x148)=rawValue2;
            }
            rawValue2=Physics34Player94View2;
            rawValue2+=128;
            Physics34Player94View2=rawValue2;
            rawValue2=rawValue2<4801;
            if(!rawValue2)Physics34Player94View2=4800;
            rawValue2=Physics34Field(&Physics34Player0View3,int*,0x150);
            numeric6=numeric4-1024;
            rawValue3=rawValue2*numeric6;
            rawValue2=Physics34Field(&Physics34Player0View3,int*,0x154);
            rawValue2=rawValue3/rawValue2;
            call4=&originalFrame.sp10;
            rawValue3=Physics34Field(&Physics34Player0View3,int*,0x148);
            angle16=rawValue3+rawValue2;
            rawValue2=(numeric6<<10)>>10;
            rawValue2=angle16+rawValue2;
            angle16=rawValue2&4095;
            Physics34Player64View1=angle16;
            Physics34Call4F178View3(call4,savedPointer17+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics34Call4F1C8View3(call4,call5,savedPointer17-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            rawValue2=Physics34Call4EDE8View3(call4,call5);
            numeric6=rawValue2;
            rawValue2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(rawValue2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x80094FFC):"memory");
            numeric6=1024;
            goto limit19;
            curve19:__asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x80095004));
            rawValue2=(numeric6*4800)>>10;
            Physics34Player94View2=rawValue2;
            rawValue2=Physics34Player16CView1;
            numeric7=Physics34Field(&Physics34Player0View3,int*,0x168);
            rawValue3=Physics34Field(&Physics34Player0View3,int*,0x158);
            rawValue2&=127;
            numeric4=numeric7<<1;
            Physics34Player16CView1=rawValue2;
            rawValue2=*(short*)(&Physics34Data65920View2+numeric4);
            rawValue3+=1024;
            product10=rawValue3*rawValue2;
            square8=numeric6*numeric6;
            rawValue2=product10>>12;
            originalFrame.sp10=rawValue2;
            rawValue2=*(short*)(&Physics34Data658A0View2+numeric4);
            rawValue3=rawValue3*rawValue2;
            numeric7<<=4;
            call4=&originalFrame.sp10;
            call5=call4;
            __asm__("":"=r"(savedPointer17):"0"(savedPointer17),"r"(call4),"r"(call5));
            numeric6=(int)savedPointer17+340;
            rawValue2=square8>>11;
            angle16=numeric7-rawValue2;
            rawValue2=rawValue3>>12;
            originalFrame.sp14=rawValue2;
            Physics34Call4F194View3(call4,call5,numeric6,numeric7);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics34Player64View1=angle16;
            Physics34Call4F1C8View3(call4,call5,savedPointer17-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            rawValue2=Physics34Call4EDE8View3(call4,call5);
            numeric6=rawValue2;
            rawValue2=numeric6<2049;
            call4=&originalFrame.sp10;
            if(rawValue2)goto commit19;
            call5=(void*)numeric6;
            numeric6=2048;
            limit19:Physics34Call4F08CView3(call4,call5,numeric6);
            commit19:rawValue2=originalFrame.sp10;
            rawValue3=originalFrame.sp14;
            Physics34Field(&Physics34Player0View3,int*,0x8C)=rawValue2;
            Physics34Field(&Physics34Player0View3,int*,0x90)=rawValue3;
            return;
        }
    case 0x1D:
        Physics34Call4F168View3(&originalFrame.sp20);
        raw34_temp_s1_2 = &Physics34Player0View3 + 0x8C;
        Physics34Call4F1C8View3(&originalFrame.sp20, &originalFrame.sp20, raw34_temp_s1_2);
        if (Physics34Field(&Physics34Player0View3, int *, 0xB8) != 0) {
            originalFrame.sp28 = 0;
            raw34_temp_v0_6 = Physics34Call4EDE8View3(&originalFrame.sp20, 0);
            if (raw34_temp_v0_6 >= 0x41) {
                Physics34Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_6, 0x40);
            }
            originalFrame.sp28 = -0xC0;
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            call6=&originalFrame.sp20;
            goto commit29;
        }
        else {
            raw34_temp_v0_7 = Physics34Call4EDE8View3(&originalFrame.sp20, 1);
            if (raw34_temp_v0_7 >= 0x101) {
                Physics34Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_7, 0x100);
            }
            Physics34Call4F194View3(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp20);
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            __asm__("":"=r"(call5):"0"(call5));
            call6=call5+92;
        }
        commit29:Physics34Call4F194View3(call4,call5,call6);
        raw34_temp_a0_3 = &Physics34Player0View3 + 0x8C;
        Physics34Call4F178View3(raw34_temp_a0_3, raw34_temp_a0_3 - 0xC);
        if (Physics34Field(&Physics34Player0View3, int *, 0x94) < -0x2300) {
            Physics34Field(&Physics34Player0View3, int *, 0x94) = -0x2300;
            return;
        }
        break;
    case 0x1A:
        globalFieldB8PointerState1A = &Physics34Player0View3 + 0xB8;
        if (Physics34Field(&Physics34Player0View3, int *, 0xB8) != 0) {
            raw34_temp_v0_8 = Physics34Field(&Physics34Player0View3, int *, 0x94) - 0x600;
            Physics34Field(&Physics34Player0View3, int *, 0x94) = raw34_temp_v0_8;
            if (raw34_temp_v0_8 < -0x2300) {
                Physics34Field(&Physics34Player0View3, int *, 0x94) = -0x2300;
            }
            Physics34Call4F178View3(globalFieldB8PointerState1A - 0x38, globalFieldB8PointerState1A - 0x2C);
            return;
        }
    block_75:
        Physics34Call4F168View3(&Physics34Player0View3 + 0x80);
        Physics34Call4F168View3(&Physics34Player0View3 + 0x8C);
        return;
    case 107:Physics34Call40D10View1(0xC80);
        Physics34Call41580View1(0x28, 8);
        Physics34Call417FCView1(0x140, 0xC0);
        globalFieldA4Pointer = &Physics34Player0View1 + 0xA4;
        savedPointer19 = globalFieldA4Pointer - 0x18;
        rawValue2=Physics34Call4EA2CView1(Physics34Field(globalFieldA4Pointer,int*,0));
        rawValue3=Physics34Field(&Physics34Player0View1,int*,0xB0);
        product9=rawValue3*rawValue2;
        call4=(void*)Physics34Field(globalFieldA4Pointer,int*,0);
        rawValue2=product9>>12;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        originalFrame.sp30=rawValue2;
        rawValue2=Physics34Call4E9E4View1(call4);
        rawValue3=Physics34Field(&Physics34Player0View1,int*,0xB0);
        product9=rawValue3*rawValue2;
        rawValue2=product9>>12;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        originalFrame.sp34=rawValue2;
        Physics34Call4F1C8View1(&originalFrame.sp30, &originalFrame.sp30, savedPointer19);
        originalFrame.sp38 = 0;
        temp_v0_4 = Physics34Call4EDE8View1(&originalFrame.sp30, 0);
        __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
        var_a0_3 = globalFieldA4Pointer - 0x24;
        if (temp_v0_4 >= 0x281) {
            Physics34Call4F08CView1(&originalFrame.sp30, temp_v0_4, 0x280);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
        }
        Physics34Call4F194View1(var_a0_3, savedPointer19, &originalFrame.sp30);
        Physics34Call41B64View1();
        if (combinedIndex < 0xD) {
            __asm__("" :: "r"(combinedIndex));
            nextField94 = Physics34Field(&Physics34Player0View1, int *, 0x94) + 0x17;
        }
        else {
            nextField94 = Physics34Field(&Physics34Player0View1, int *, 0x94) - 0xC0;
        }
        Physics34Player94View1=nextField94;
        __asm__ volatile("" ::: "memory");
        if (Controller88028_SpawnParticle != 0) {
            globalPointer=&Physics34Player0View1+0x148;
            __asm__("" : "=r"(globalPointer):"0"(globalPointer));
            particleIndex=0;
            if (Physics34Field(globalPointer,int*,0) != 0) {
                rawValue2=combinedIndex*4;
                __asm__("" : "=r"(rawValue2):"0"(rawValue2));
                particleThreshold=rawValue2+combinedIndex;
                globalByteE=globalPointer-0x13A;
                vectorAt40=&originalFrame.sp50;
                __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
            spawnParticleLoop:
                if (particleThreshold < (Physics34CallRandView1() & 0xFF)) {
                    rawValue2=Physics34Call363DCView1(0,0xC);
                    call4=globalByteE+0x22;
                    rawValue3=*globalByteE;
                    __asm__("" : "=r"(rawValue3):"0"(rawValue3));
                    call5=vectorAt40;
                    __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
                    rawValue3+=0x80;
                    __asm__("" : "=r"(rawValue3):"0"(rawValue3));
                    rawValue3+=rawValue2;
                    __asm__("" : "=r"(rawValue3):"0"(rawValue3));
                    rawValue3=(rawValue3&0xFF)*2;
                    signedTableWord = *(short*)(&Physics34Data65920View1 + rawValue3);
                    call6=vectorAt40;
                    originalFrame.sp40 = (int) (signedTableWord * 5) >> 0xA;
                    rawValue3=*(short*)(&Physics34Data658A0View1 + rawValue3);
                    __asm__ volatile("" : "=r"(rawValue3):"0"(rawValue3):"memory");
                    originalFrame.sp48 = 0xE;
                    originalFrame.sp50 = -0x12C;
                    originalFrame.sp54 = 0;
                    originalFrame.sp58 = -0xC8;
                    __asm__ volatile("" ::: "memory");
                    originalFrame.sp44 = (rawValue3 * 5) >> 0xA;
                    Physics34Call4ED6CView1(call4, call5, call6, signedTableWord);
                    originalFrame.sp50 += Physics34Call363DCView1(0, 0x50);
                    originalFrame.sp54 += Physics34Call363DCView1(0, 0x50);
                    originalFrame.sp58 += Physics34Call363DCView1(0, 0x50);
                    Physics34Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                    temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp40);
                    Physics34Field(temp_v0_5, signed char *, 2) = 8;
                    Physics34Field(temp_v0_5, signed char *, 0xA) = 0x20;
                }
                particleIndex += 1;
                if (particleIndex < 2) {
                    goto spawnParticleLoop;
                }
            }
        }
        break;
    case 0x1E:
        savedPointer16 = &Physics34Player0View3 + 0x80;
        Physics34Call4F168View3(savedPointer16);
        Physics34Call4F168View3(savedPointer16 + 0xC);
        return;
    case 32:case 108:globalFieldB8PointerState20 = &Physics34Player0View1 + 0xB8;
        if (Physics34Field(&Physics34Player0View1, int *, 0xB8) != 0) {
            savedPointer17=&originalFrame.sp40;
            Physics34Call4F168View1(savedPointer17);
            call4=savedPointer17;
            call5=savedPointer17;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            savedPointer18 = globalFieldB8PointerState20 - 0x2C;
            Physics34Call4F1C8View1(call4, call5, savedPointer18);
            originalFrame.sp48 = 0;
            temp_v0_6 = Physics34Call4EDE8View1(&originalFrame.sp40, 0);
            if (temp_v0_6 >= 0x41) {
                Physics34Call4F08CView1(&originalFrame.sp40, temp_v0_6, 0x40);
            }
            originalFrame.sp48 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Physics34Call4F194View1(globalVector80State20, savedPointer18, &originalFrame.sp40);
            Physics34Call4F178View1(savedPointer18, globalVector80State20);
        }
        else {
            Physics34Call4F168View1(globalFieldB8PointerState20 - 0x38);
            Physics34Call4F168View1(globalFieldB8PointerState20 - 0x2C);
        }
        if (Physics34Field(&Physics34Player0View1, int *, 0x94) < -0x2300) {
            Physics34Field(&Physics34Player0View1, int *, 0x94) = -0x2300;
        }
        if ((Physics34Field(&Physics34Player0View1, int *, 0x48) == 0x3A) && (Controller88028_SpawnParticle != 0) && (Physics34Data6C640View1 & 1)) {
            originalFrame.sp60 = 0;
            originalFrame.sp64 = 0;
            originalFrame.sp68 = 0xE;
            Physics34Call4F178View1(&originalFrame.sp70, (&Physics34Player0View1 + 0x94) - 0x94);
            originalFrame.sp70 += Physics34Call363DCView1(0, 0x12C);
            originalFrame.sp74 += Physics34Call363DCView1(0, 0x12C);
            originalFrame.sp78 += Physics34Call363DCView1(0, 0x12C);
            temp_v0_7 = Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp70, &originalFrame.sp60);
            Physics34Field(temp_v0_7, signed char *, 2) = 6;
            Physics34Field(temp_v0_7, signed char *, 0xA) = 0x20;
        }
        break;
    case 47:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            rawValue3=Physics34Data6E044View3;
            rawValue2=7;
            if(rawValue3==rawValue2)goto zero47;
            Physics34Call40F48View1(&originalFrame.sp60,0);
            rawValue2=originalFrame.sp60;
            numeric6=originalFrame.sp64;
            originalFrame.sp68=0;
            rawValue3=(rawValue2*9<<7)>>7;
            rawValue2=(numeric6*3<<9)>>7;
            originalFrame.sp60=rawValue3;
            rawValue3=-rawValue3;
            originalFrame.sp64=rawValue2;
            originalFrame.sp6C=rawValue3;
            originalFrame.sp70=rawValue2;
            rawValue2=Physics34Call4EDE8View3(&originalFrame.sp68,0,numeric6);
            numeric4=originalFrame.sp70;
            rawValue3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(rawValue3):"0"(rawValue3));
                rawValue3=-rawValue3;
            }
            rawValue3=rawValue3<rawValue2;
            if(rawValue3){
                rawValue2=originalFrame.sp6C;
                originalFrame.sp70=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(rawValue2>0){
                    __asm__ volatile(""::"i"(0x80095730):"memory");
                    numeric4=1;
                }
                if(!Physics34Call43194View1(numeric4)){
                    originalFrame.sp6C=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp6C=0;
                originalFrame.sp68=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x80095758):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics34Call43194View1(numeric4)){
                    originalFrame.sp70=0;
                }
            }
            call4=&originalFrame.sp68;
            rawValue2=Physics34Call4EDE8View3(call4,1);
            Physics34PlayerACView1=rawValue2;
            __asm__ volatile(""::"i"(0x80095788):"memory");
            goto clear47;
            zero47:Physics34PlayerACView1=0;
            clear47:savedPointer16=&Physics34Player80View1;
            __asm__("":"=r"(savedPointer16):"0"(savedPointer16));
            Physics34Call4F168View3(&Physics34Player0View3+0x80);
            Physics34Call4F168View3(&Physics34Player0View3+0x8C);
            return;
        }
    case 0x32:
    case 0x33:
    case 52:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics34Call40F48View1(&originalFrame.sp80,0);
            rawValue2=originalFrame.sp80;
            numeric6=originalFrame.sp84;
            originalFrame.sp88=0;
            rawValue3=(rawValue2*9<<7)>>7;
            rawValue2=(numeric6*3<<9)>>7;
            originalFrame.sp80=rawValue3;
            rawValue3=-rawValue3;
            originalFrame.sp84=rawValue2;
            originalFrame.sp8C=rawValue3;
            originalFrame.sp90=rawValue2;
            rawValue2=Physics34Call4EDE8View3(&originalFrame.sp88,0,numeric6);
            numeric4=originalFrame.sp90;
            rawValue3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(rawValue3):"0"(rawValue3));
                rawValue3=-rawValue3;
            }
            rawValue3=rawValue3<rawValue2;
            if(rawValue3){
                rawValue2=originalFrame.sp8C;
                originalFrame.sp90=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(rawValue2>0){
                    __asm__ volatile(""::"i"(0x80095850):"memory");
                    numeric4=1;
                }
                if(!Physics34Call43194View1(numeric4)){
                    originalFrame.sp8C=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp8C=0;
                originalFrame.sp88=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x80095878):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics34Call43194View1(numeric4)){
                    originalFrame.sp90=0;
                }
            }
            savedPointer17=&originalFrame.sp88;
            rawValue2=Physics34Call4EDE8View3(savedPointer17,1);
            numeric6=1;
            __asm__("":"=r"(numeric6):"0"(numeric6));
            numeric4=originalFrame.sp80;
            numeric5=originalFrame.sp84;
            savedPointer16=&Physics34PlayerACView1;
            Physics34Field(savedPointer16,int*,0)=rawValue2;
            rawValue2=Physics34Call4E880View1(numeric4,numeric5,numeric6);
            rawValue3=rawValue2;
            rawValue2=rawValue3<2049;
            Physics34PlayerA4View1=rawValue3;
            call4=savedPointer16-124;
            if(!rawValue2){
                rawValue2=rawValue3-4096;
                Physics34PlayerA4View1=rawValue2;
            }
            call5=savedPointer17;
            rawValue2=originalFrame.sp88;
            call6=savedPointer17;
            rawValue2+=1024;
            originalFrame.sp88=rawValue2;
            Physics34Call4ED6CView2(call4,call5,call6);
            call4=savedPointer17;
            call5=savedPointer17;
            __asm__("":"=r"(savedPointer16):"0"(savedPointer16),"r"(call4),"r"(call5));
            savedPointer18=savedPointer16-32;
            Physics34Call4F1C8View3(call4,call5,savedPointer18);
            call5=(void*)Physics34Call4EDE8View3(savedPointer17,0);
            rawValue2=(int)call5<385;
            if(!rawValue2)Physics34Call4F08CView3(savedPointer17,call5,384);
            savedPointer16-=44;
            Physics34Call4F194View3(savedPointer16,savedPointer18,savedPointer17);
            Physics34Call4F178View3(savedPointer18,savedPointer16);
            return;
        }
    case 105:savedPointer16=&Physics34Player0View2+0xB8;
        rawValue2=Physics34Field(savedPointer16,int*,0);
        if(!rawValue2)goto zero105;
        savedPointer17=&originalFrame.sp98;
        Physics34Call4F168View2(savedPointer17);
        call4=savedPointer17;
        call5=savedPointer17;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        savedPointer18=savedPointer16-44;
        Physics34Call4F1C8View2(call4,call5,savedPointer18);
        originalFrame.spA0=0;
        call5=(void*)Physics34Call4EDE8View2(savedPointer17,0);
        rawValue2=(int)call5<65;
        if(!rawValue2)Physics34Call4F08CView2(savedPointer17,call5,64);
        originalFrame.spA0=-192;
        savedPointer16-=56;
        Physics34Call4F194View2(savedPointer16,savedPointer18,savedPointer17);
        Physics34Call4F178View2(savedPointer18,savedPointer16);
        goto clamp104;
        zero105:Physics34Call4F168View2(savedPointer16-56);
        Physics34Call4F168View2(savedPointer16-44);
        goto clamp104;
    case 100:savedPointer16=&Physics34Player0View2+0x80;
        Physics34Call4F168View2(savedPointer16);
        Physics34Call4F168View2(savedPointer16+12);
        if(Physics34Data6E044View2!=7){
            Physics34Call40D10View2(3840);
            Physics34Call416F4View2();
            Physics34Call41580View2(90,16);
        }
        rawValue2=Physics34Player1BAView1;
        if(!rawValue2){
            rawValue2=1;
            goto byteOne;
        }
        rawValue2=Physics34Data6E538View1&16;
        if(rawValue2){
            rawValue2=1;
            goto wordOneReturn;
        }
        rawValue2=1;
        Physics34Player1BAView1=0;
        __asm__ volatile(""::"i"(0x80095A80):"memory");
        goto byteOne;
    case 101:rawValue3=Physics34Data6E044View2;
        rawValue2=8;
        if(rawValue3!=rawValue2)Physics34Call40D10View2(3840);
        savedPointer16=&Physics34Data6E538View1;
        rawValue2=Physics34Field(savedPointer16,int*,0)&12;
        if(rawValue2)Physics34PlayerACView1=0;
        rawValue2=Physics34Call416F4View2();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)rawValue2;
        rawValue2=Physics34Call41580View2(call4,call5);
        rawValue3=Physics34PlayerA8View1;
        if(rawValue3<0)rawValue3=-rawValue3;
        rawValue3=rawValue3<8;
        __asm__("":"=r"(rawValue3):"0"(rawValue3),"r"(rawValue2));
        call5=(void*)rawValue2;
        if(!rawValue3)goto reset101;
        rawValue2=Physics34Field(savedPointer16,int*,0)&12;
        if(!rawValue2)goto reset101;
        rawValue2=Physics34Player144View1;
        rawValue2++;
        Physics34Player144View1=rawValue2;
        goto saved101;
        reset101:Physics34Player144View1=0;
        saved101:call4=&Physics34PlayerACView1;
        savedPointer16=(void*)Physics34Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        rawValue2=(int)call5;
        if((int)call5<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<513;
        if(rawValue2)goto pass101;
        collision101:rawValue2=Physics34Player20CView1&64;
        if(rawValue2)Physics34Field(call4,int*,0)=0;
        else{
            rawValue3=Physics34PlayerB0View1;
            rawValue2=rawValue3<(int)savedPointer16;
            if(rawValue2)Physics34Field(call4,int*,0)=rawValue3;
        }
        pass101:Physics34Call417FCView2(256,384);
        rawValue2=Physics34Player101View1;
        call4=&Physics34PlayerACView1;
        Physics34Field(call4,int*,0)=(int)savedPointer16;
        if(rawValue2){
            Physics34Call4F168View2(call4-32);
            goto fields101;
        }
        Physics34Call41848View1(call4);
        Physics34Call41B64View2();
        fields101:call6=&Physics34PlayerFCView1;
        rawValue2=Physics34Field(call6,unsigned char*,0);
        if(rawValue2)goto field94FromA0;
        rawValue2=Physics34PlayerB8View1;
        call4=call6-112;
        if(!rawValue2)goto commit101;
        field94FromA0:rawValue2=Physics34PlayerA0View1;
        rawValue2-=192;
        Physics34Player94View2=rawValue2;
        return;
        commit101:call5=call4;
        vectorCommit61:Physics34Call4F194View2(call4,call5,call6-20);
        return;
    case 102:case 103:case 106:{
            register int limit17 __asm__("$17");
            register int numeric5 __asm__("$5");
            Physics34Call40D10View2(6400);
            rawValue2=Physics34Data6E538View1;
            rawValue3=rawValue2&12;
            if(rawValue3)goto held106;
            rawValue2=Physics34Call4F284View1(Physics34PlayerA4View1,Physics34Player64View1);
            rawValue2=rawValue2<1665;
            if(rawValue2)Physics34Call41580View2(44,6);
            limit17=80;
            goto move106;
            held106:rawValue2=8;
            if(rawValue3!=rawValue2)goto other106;
            rawValue2=Physics34Data6E040View1;
            rawValue3=6400;
            Physics34PlayerACView1=rawValue3;
            rawValue2-=1024;
            goto heading106;
            other106:rawValue2=4;
            limit17=320;
            if(rawValue3!=rawValue2)goto move106;
            rawValue2=Physics34Data6E040View1;
            rawValue3=6400;
            Physics34PlayerACView1=rawValue3;
            rawValue2+=1024;
            heading106:Physics34PlayerA4View1=rawValue2;
            limit17=320;
            move106:Physics34Call417FCView2(256,384);
            savedPointer19=&Physics34Player210View1;
            rawValue2=Physics34Field(savedPointer19,int*,0)&1024;
            if(rawValue2)goto clamp106;
            call4=(void*)Physics34PlayerA4View1;
            savedPointer18=savedPointer19-388;
            rawValue2=Physics34Call4EA2CView2(call4);
            rawValue3=Physics34PlayerB0View1;
            product9=rawValue3*rawValue2;
            call4=(void*)Physics34PlayerA4View1;
            rawValue2=product9>>12;
            __asm__("":"=r"(rawValue2):"0"(rawValue2));
            originalFrame.spA8=rawValue2;
            rawValue2=Physics34Call4E9E4View2(call4);
            rawValue3=Physics34PlayerB0View1;
            product9=rawValue3*rawValue2;
            call4=savedPointer18;
            call5=savedPointer19-376;
            rawValue2=product9>>12;
            __asm__("":"=r"(rawValue2):"0"(rawValue2));
            originalFrame.spAC=rawValue2;
            Physics34Call4F178View2(call4,call5);
            savedPointer16=&originalFrame.spA8;
            Physics34Call4F1C8View2(savedPointer16,savedPointer16,savedPointer18);
            originalFrame.spB0=0;
            call5=(void*)Physics34Call4EDE8View2(savedPointer16,0);
            rawValue2=limit17<(int)call5;
            if(rawValue2)Physics34Call4F08CView2(savedPointer16,call5,limit17);
            Physics34Call4F194View2(savedPointer19-400,savedPointer18,savedPointer16);
            Physics34Call41B64View2();
            rawValue2=(int)Physics34Data6C570View2;
            rawValue2=Physics34Field((void*)rawValue2,int*,0)&64;
            if(rawValue2)Physics34Player144View1=0;
            else{
                rawValue2=Physics34Player144View1;
                rawValue2++;
                Physics34Player144View1=rawValue2;
            }
            rawValue2=Physics34Player144View1;
            rawValue2=rawValue2<10;
            if(rawValue2){
                rawValue2=Physics34Player94View2;
                rawValue2+=256;
                goto store106;
            }
            rawValue2=Physics34Player94View2;
            rawValue2-=96;
            store106:Physics34Player94View2=rawValue2;
            rawValue2=Physics34PlayerF8View1;
            rawValue3=Physics34Player8View1;
            numeric5=rawValue2-rawValue3;
            rawValue2=numeric5<4096;
            rawValue3=numeric5<<2;
            if(!rawValue2)goto mode106;
            rawValue2=Physics34Player94View2;
            rawValue2=rawValue3<rawValue2;
            if(rawValue2)Physics34Player94View2=rawValue3;
            mode106:rawValue3=Physics34Player4CView1;
            rawValue2=127;
            if(rawValue3==rawValue2)goto clamp106;
            call4=&Physics34Data676E8View1;
            rawValue2=Physics34Data6C58CView1;
            rawValue3=Physics34Data6C5C8View1;
            rawValue2<<=4;
            rawValue2+=(int)call4;
            rawValue3<<=2;
            rawValue3+=rawValue2;
            rawValue2=Physics34Player8View1;
            rawValue3=Physics34Field((void*)rawValue3,int*,0);
            rawValue2-=rawValue3;
            numeric5=rawValue2-1024;
            rawValue2=numeric5<4096;
            rawValue3=-numeric5;
            if(rawValue2){
                rawValue2=Physics34Player94View2;
                __asm__(""::"r"(rawValue3),"r"(rawValue2));
                rawValue3<<=1;
                rawValue2=rawValue2<rawValue3;
                if(rawValue2)Physics34Player94View2=rawValue3;
            }
            clamp106:globalPointer=&Physics34Player94View2;
            rawValue2=Physics34Field(globalPointer,int*,0);
            rawValue2=rawValue2<-4480;
            if(rawValue2){
                rawValue2=-4480;
                Physics34Field(globalPointer,int*,0)=rawValue2;
            }
            rawValue2=Physics34Field(globalPointer,int*,0);
            rawValue2=rawValue2<1921;
            if(!rawValue2){
                rawValue2=1920;
                Physics34Field(globalPointer,int*,0)=rawValue2;
            }
            return;
        }
    case 104:{
            register int numeric5 __asm__("$5");
            Physics34Call4F168View2(&originalFrame.spB8);
            raw13_temp_s1_4 = &Physics34Player0View2 + 0x8C;
            Physics34Call4F1C8View2(&originalFrame.spB8, &originalFrame.spB8, raw13_temp_s1_4);
            if (Physics34PlayerB8View1 != 0) {
                originalFrame.spC0 = 0;
                raw13_temp_v0_15 = Physics34Call4EDE8View2(&originalFrame.spB8, 0);
                if (raw13_temp_v0_15 >= 0x41) {
                    Physics34Call4F08CView2(&originalFrame.spB8, raw13_temp_v0_15, 0x40);
                }
            }
            else {
                raw13_temp_v0_16 = Physics34Call4EDE8View2(&originalFrame.spB8, 1);
                if (raw13_temp_v0_16 >= 0x101) {
                    Physics34Call4F08CView2(&originalFrame.spB8, raw13_temp_v0_16, 0x100);
                }
                Physics34Call4F194View2(raw13_temp_s1_4, raw13_temp_s1_4, &originalFrame.spB8);
            }
            raw13_temp_s0_9 = &Physics34Player0View2 + 0x80;
            raw13_temp_s1_5 = raw13_temp_s0_9 + 0xC;
            originalFrame.spC0 = -0xC0;
            Physics34Call4F194View2(raw13_temp_s0_9, raw13_temp_s1_5, &originalFrame.spB8);
            Physics34Call4F178View2(raw13_temp_s1_5, raw13_temp_s0_9);
            call4=&Physics34Data676E8View1;
            rawValue2=Physics34Data6C58CView1;
            rawValue3=Physics34Data6C5C8View1;
            rawValue2<<=4;
            rawValue2+=(int)call4;
            rawValue3<<=2;
            rawValue3+=rawValue2;
            rawValue2=Physics34Player8View1;
            rawValue3=Physics34Field((void*)rawValue3,int*,0);
            rawValue2-=rawValue3;
            numeric5=rawValue2-1024;
            rawValue2=numeric5<4096;
            rawValue3=-numeric5;
            if(rawValue2){
                rawValue2=Physics34Player94View2;
                __asm__(""::"r"(rawValue3),"r"(rawValue2));
                rawValue3<<=1;
                rawValue2=rawValue2<rawValue3;
                if(rawValue2)Physics34Player94View2=rawValue3;
            }
            clamp104:globalPointer=&Physics34Player94View2;
            rawValue2=Physics34Field(globalPointer,int*,0);
            rawValue2=rawValue2<-8960;
            if(!rawValue2)return;
            rawValue2=-8960;
            Physics34Field(globalPointer,int*,0)=rawValue2;
            return;
        }
    case 109:savedPointer16=&Physics34Player0View2+0x80;
        Physics34Call4F168View2(savedPointer16);
        Physics34Call4F168View2(savedPointer16+12);
        rawValue2=Physics34Player1BAView1;
        if(!rawValue2){
            rawValue2=1;
            goto byteOne;
        }
        rawValue2=Physics34Data6E538View1&16;
        if(rawValue2){
            rawValue2=1;
            goto wordOneReturn;
        }
        rawValue2=1;
        Physics34Player1BAView1=0;
        byteOne:Physics34Player1B9View1=rawValue2;
        wordOneReturn:__asm__(""::"r"(rawValue2));
        return;
    }
}
#undef Physics34Field


int Callback34First42A44(void) __asm__("func_80042A44");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 numeric decode.
 * Original animation callback at 80096124; private+0x30 child pointer,
 * child+0x38 halfword, player+0x74 vector, byte offsets +0x24/-0x74/+0x58.
 * Unsigned halfword load with signed shifts 16/17 and signed guarded division
 * follow original instructions. Empty constraints preserve original register
 * lifetimes and scheduling; they emit no instructions. Helper meanings, units,
 * cadence and runtime semantics remain unresolved. Acceptance requires every
 * original word/internal jump, strict complete TU, EXE and every overlay hash.
 */
extern int Callback34Step __asm__("D_80070328+0x144");
extern int Callback34Z __asm__("D_80070328+8");
extern int Callback34Limit __asm__("D_80070328+0x280");
extern Spyro Callback34Player __asm__("D_80070328");
int Callback34Call80037058(int x, int y) __asm__("func_80037058");
int Callback34Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback34Call80041930(void) __asm__("func_80041930");
void Callback34Call80041AE8(void) __asm__("func_80041AE8");
void Callback34Call80041C20(void) __asm__("func_80041C20");
void Callback34Call80042A44(void) __asm__("func_80042A44");
void Callback34Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback34Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback34Query(Vector3D*,int) __asm__("func_8001A358");
int Callback34Length(Vector3D*, int) __asm__("func_8004EDE8");
extern unsigned char* Callback34Table[] __asm__("D_8006EE2C");
extern unsigned char Callback34Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback34Call8004F110(Vector3D*,int) __asm__("func_8004F110");
int Callback34Call80038000(Moby*,Vector3D*,int,int,int) __asm__("func_80038000");
void Callback34Call8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void Callback34Call8003BE70(int) __asm__("func_8003BE70");
void func_level_34_80096124(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; Vector3D third; int reserved44;} local;
    register int computedValue __asm__("$4");
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback34Player.animationState) {
    case 0x64:
        if(func_800438F4()==0)func_80043728();
        Callback34Call80041C20();
        Callback34Player.unk9a=0;
        goto call42A44;
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x67:
    case 0x69:
    case 0x6C:
        Callback34Call80041C20();
call42A44:
        Callback34Call80042A44();
clearSharedValue:
        Callback34Player.unk4[0]=0;
        return;
    case 0x66:
        Callback34Call80041C20();
        Callback34Call80042A44();
        descriptorMoby=Callback34Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(descriptorMoby) : "0"(descriptorMoby) : "memory");
        Callback34Player.unk4[0]=0;
        goto descriptorTail;
    case 0x65:
        func_800438F4();
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        goto queryC00;
    case 0x13:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        goto clearSharedValue;
    case 0x1A:
    case 0x1D:
    case 0x68:
        Callback34Call80041C20();
        Callback34Call80042A44();
queryC00:
        Callback34Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x6B:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        if(Callback34Player.unk7a[3].z<0 && Callback34Player.animationStateFrames>=4)
            Callback34Player.unk5=1;
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback34Z;
            register int velocity __asm__("$6")=Callback34Step;
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
            status=Callback34Limit;
            velocity+=tick;
            Callback34Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback34Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback34Step=0x2580;
            }
        limitsDone:
            Callback34Call80041C20();
            Callback34Call80042A44();
            func_8004F178(&local.first,&Callback34Player.position);
            local.first.z+=0x400;
            Callback34Player.unk4[0]=Callback34Query(&local.first,0xC00);
            positionDelta=(int)Callback34Player.union144.a.unk13cb;
            positionValue=Callback34Player.position.z;
            positionDelta >>= 6;
            positionValue-=positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback34Player.position.z=positionValue;
            return;
        }
    case 0x2F:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback34Player.unk7a[3].z << 2);
        Callback34Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)((unsigned int)ABS(numerator) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 0x10;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 0x10;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
    case 0x33:
    case 0x34:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        func_80042F64();
        Callback34Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback34Length((Vector3D *) ((unsigned char*)Callback34Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 8;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 8;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
compareUpperLimit:
        belowLimit=clampedValue<0x41;
applyUpperLimit:
        if(!belowLimit)clampedValue=0x40;
        func_800443A4(clampedValue);
        return;
    case 0x6A:
    case 0x6D: {
        register unsigned char* privateData __asm__("$17")=Callback34Player.critterMobyPtr->mobyTag;
        register int changed __asm__("$20")=0;
        register Vector3D* vectorBase __asm__("$16");
        register Vector3D* copyBase __asm__("$18");
        register unsigned char* sourceBase __asm__("$19");
        register int queryHeight __asm__("$16");
        if(*(Moby**)(privateData+0x30)!=0) {
            vectorBase=&local.second;
            sourceBase=Callback34Source;
            func_8004F178(vectorBase,(Vector3D*)sourceBase);
            Callback34Call8004F110(vectorBase,6);
            {
                Moby* child=*(Moby**)(privateData+0x30);
                child->position.z+=((int)((unsigned int)*(unsigned short*)((unsigned char*)child+0x38)<<16))>>17;
            }
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)*(Moby**)(privateData+0x30)+0xC));
            copyBase=&local.third;
            func_8004F178(copyBase,vectorBase);
            {
                int height=((int)((unsigned int)*(unsigned short*)((unsigned char*)*(Moby**)(privateData+0x30)+0x38)<<16))>>17;
                register int result=Callback34Call80038000(*(Moby**)(privateData+0x30),vectorBase,height,height,0x1022);
                register Vector3D* childVector __asm__("$4")=vectorBase;
                if(result!=0) {
                    register Vector3D* childCopy __asm__("$6")=copyBase;
                    {register Moby* childArgument __asm__("$5")=*(Moby**)(privateData+0x30);
                    __asm__ volatile("" : "=r"(changed) : "0"(changed) : "memory");
                    changed=1;
                    Callback34Call8004F1C8(childVector,(Vector3D*)((unsigned char*)childArgument+0xC),childCopy);}
                    func_8004F0E8(vectorBase,6);
                    func_8004F194((Vector3D*)sourceBase,(Vector3D*)sourceBase,vectorBase);
                }
            }
            Callback34Call80041C20();
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
                Callback34Call8004F1C8(argument0,argument0,vectorBase);
            }}
            {register Moby* child __asm__("$2")=*(Moby**)(privateData+0x30);
            register int childValue __asm__("$3")=*(short*)((unsigned char*)child+0x38);
            register int playerValue __asm__("$2")=Callback34Player.unk4a;
            playerValue+=childValue;
            __asm__("" : "=r"(playerValue) : "0"(playerValue));
            queryHeight=playerValue+64;}
            if(Callback34Query((Vector3D*)(sourceBase-0x74),queryHeight)!=0 && Callback34Player.unk7a[2].z<=0) {
                if(Callback34Player.unk7a[2].z>=-2047)
                    Callback34Player.position.z=D_80071908+queryHeight-64;
                Callback34Player.ticksSinceLastSurfaceTouch=0;
                func_8004F178((Vector3D*)(sourceBase+0x58),&D_80071918);
            } else {
                register int* counterPointer __asm__("$2")=&Callback34Player.ticksSinceLastSurfaceTouch;
                register int counterValue __asm__("$3");
                register int vectorZ __asm__("$4");
                __asm__("" : "=r"(counterPointer) : "0"(counterPointer));
                Callback34Player.unk9e.x=0;
                Callback34Player.unk9e.y=0;
                counterValue=*counterPointer;
                __asm__ volatile("" : "=r"(counterPointer) : "0"(counterPointer) : "memory");
                vectorZ=4096;
                Callback34Player.unk9e.z=vectorZ;
                counterValue+=1;
                *counterPointer=counterValue;
            }
        } else Callback34Call80041C20();
        Callback34Player.unk4[0]=0;
        if(Callback34Player.animationState!=0x6A)return;
        descriptorMoby=Callback34Player.critterMobyPtr;
descriptorTail:
        selector=Callback34Table[descriptorMoby->mobyClass][6];
        if(selector!=(unsigned int)Callback34Player.unk22[3]) {
            if(Callback34Call8003BF6C(Callback34Player.unk22[3],Callback34Player.unk22[2])!=0)
                Callback34Call8003BE70(Callback34Player.unk22[2]);
            Callback34Player.unk22[2]=-1;
        }
        Callback34Player.unk22[3]=selector;
        if(Callback34Call8003BF6C(selector,Callback34Player.unk22[2])==0)
            Callback34Player.unk22[2]=PlaySound(Callback34Player.unk22[3],0,4);
        return;
    }
    default:
        return;
    }
}


#define LEVEL_ID 34
#define PlaySpyroSounds_level_34 func_level_34_80096828
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_34_80096A28(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x1a:
    case 0x1d:
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
    case 0x66:
    case 0x67:
    case 0x6a:
    case 0x6b:
        func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80096AC0.
 * Reuses verified22 private0/4/8 swirl, squish, drowning and64..6D producers,
 * verified37 numeric21C/220/224 hurt/fallbackA0 and independent sound call.
 * Original34 adds independent2F and32/33/34 ladder blocks sharing grounded
 * store with35/36 before244/250 clear. Original access widths and byte offsets,
 * signed table shifts1, flags400/copy21C/scale6, masks and branches are retained.
 * Empty constraints retain original scheduling without emitting instructions.
 * Require every code/internal jump/owned dispatch word and complete retail
 * hashes. Helper/audio meanings, units, cadence and live parity remain open.
 */
void Transition34_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");

extern Spyro Transition34_D_80070328 __asm__("D_80070328");
int Transition34_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition34_func_80043A38(int scale) __asm__("func_80043A38");
void Transition34_func_800441F0(void) __asm__("func_800441F0");
void Transition34_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition34_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition34RawUnion[] __asm__("D_80070328+0x144");
extern int Transition34RawMovement __asm__("D_80070328+0x50");
extern void (*Call34Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw34State[] __asm__("D_80070328+0x50");
extern short Signed34TableA[] __asm__("D_800658A0");
extern short Signed34TableB[] __asm__("D_80065920");

void func_level_34_80096AC0(int arg0){
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");



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
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition34RawMovement;
        privateData = Transition34_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition34_D_80070328.unk5 = 0;
        Transition34_D_80070328.grounded = 0;
        Transition34_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition34_D_80070328.m_WhirlwindPointer;
        yawValue=Transition34_D_80070328.rotation.yaw;
        positionZ=Transition34_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition34_D_80070328.union144.a.unk13cc=yawValue;
        Transition34_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition34_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition34_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition34_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition34_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition34_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition34_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition34_D_80070328.unk13e[0] = (int) Transition34_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition34_D_80070328.unk20a = 0;
        Transition34_D_80070328.critterMobyPtr = 0;
        Transition34_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition34RawMovement;
        register int first __asm__("$3")=Transition34_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition34RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition34_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition34_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition34_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition34_D_80070328.unk17e.z;
        second<<=6;
        Transition34_D_80070328.union144.a.unk13cb=oldState;
        Transition34_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition34_D_80070328.unk7a[3].z;
        Transition34_D_80070328.unk7a[2].z=second;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded=1;
        Transition34_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    }

    case 0x1A:
        savedBase = Transition34RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition34RawMovement;
        Transition34RawMovement = MOVEMENT_STATE_HURT;
        Transition34_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition34_func_8004F168(destination);
        Transition34_D_80070328.grounded = 1;
        Transition34_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition34RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition34RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition34_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition34_D_8006E524=value;
        stateWord=(int*)Transition34RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition34_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition34_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition34_D_80070328.unk20a=0;
        Transition34_D_80070328.critterMobyPtr=0;
        Transition34_D_80070328.unk22[3]=value;
        return;
    }
    case 0x20:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition34_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x2F:
        savedBase=(unsigned char*)&Transition34RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition34_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            __asm__ volatile("" : : : "memory");
            goto setGrounded;
        }
        goto clearPointers;
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition34RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition34_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            goto setGrounded;
        }
        goto clearPointers;
    case 0x35:
    case 0x36:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_800441F0();
setGrounded:
        Transition34_D_80070328.grounded = 1;
clearPointers:
        Transition34_D_80070328.unk20a=0;
        Transition34_D_80070328.critterMobyPtr=0;
        return;
    case 0x64:
    case 0x6D:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_800441F0();
        Transition34_D_80070328.grounded = 1;
        return;
    case 0x65:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition34_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition34_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition34_D_80070328.movementState + 0x48));
            Transition34_D_80070328.unk5 = 1;
        } else {
            Transition34_D_80070328.unk5 = 0;
        }
        Transition34_D_80070328.unk8[0] = Transition34_func_8004EDE8(&Transition34_D_80070328.unk7a[3], 0);
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition34_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x69:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded = 1;
        goto clearDeathFlag;
    case 0x66:case 0x67:case 0x6A:
        stateBaseA=Raw34State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination=(Vector3D*)(stateBaseA+0x48);
        *(int*)stateBaseA=3;
        Transition34_D_80070328.unk8[0]=Transition34_func_8004EDE8(destination,0);
        Transition34_D_80070328.unk15b=1;
        Transition34_D_80070328.grounded=0;
        Transition34_D_80070328.union144.a.unk13cb=0x14;
clearSpecialTail:
        Transition34_D_80070328.idle=0;
        Transition34_D_80070328.unk15g=0;
        return;
    case 0x6B:
        savedBase = Transition34RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition34RawMovement;
        Transition34RawMovement = MOVEMENT_STATE_HURT;
        Transition34_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition34_D_80070328.unk8[0] = Transition34_func_8004EDE8(sourceC, 0);
        Transition34_D_80070328.unk7a[2].z = 0xDC0;
        Transition34_D_80070328.grounded = 0;
        Transition34_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition34_D_80070328.damageFlags & 0x200) {
            Transition34_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition34_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        return;
    case 0x6C:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
clearDeathFlag:
        Transition34_D_8006E524 = 0xF;
        return;
    case 0x68: {
        register int previousMovement __asm__("$2")=Transition34RawMovement;
        register int kind __asm__("$3");
        register int flags __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        kind=7;
        __asm__("" : "=r"(kind) : "0"(kind));
        Transition34RawMovement=kind;
        __asm__ volatile("" : : : "memory");
        flags=Transition34_D_80070328.unk17a;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        unionPointer=Transition34RawUnion;
        __asm__("" : "=r"(flags),"=r"(unionPointer) : "0"(flags),"1"(unionPointer));
        Transition34_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        *(int*)unionPointer=previousMovement;
        if(flags&0x400){
            sourceC=(Vector3D*)(unionPointer-0xB8);
            func_8004F178(sourceC,(Vector3D*)(unionPointer+0xD8));
            Transition34_func_8004F0E8(sourceC,6);
        }else if(Transition34_D_80070328.unk22[5]>=0){
            tableOffsetOrValue=Transition34_D_80070328.unk22[5]*2;
            tableValueA=*(short*)((unsigned char*)Signed34TableB+tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            Transition34_D_80070328.unk7a[2].x=tableValueA>>1;
            tableOffsetOrValue=*(short*)((unsigned char*)Signed34TableA+tableOffsetOrValue);
            Transition34_D_80070328.unk7a[2].z=0;
            __asm__ volatile("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Transition34_D_80070328.unk7a[2].y=tableOffsetOrValue>>1;
        }else Transition34_func_8004F168((Vector3D*)(unionPointer-0xB8));
        destination=&Transition34_D_80070328.unk7a[1];
        func_8004F178(destination,(Vector3D*)((unsigned char*)destination+0xC));
        Transition34_D_80070328.grounded=1;
        Transition34_D_8006E524=15;
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
 * func_level_34_800972CC:747 instructions and91 dispatch words, evidence4897.
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

void func_level_34_800972CC(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int selector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* private16 __asm__("$16");
    register unsigned char* object4 __asm__("$4");
    register unsigned char* table4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");

    work2 = A4891W48;
    switch (work2) {
    case 20: case 21: case 22: case 23: case 24: case 25: case 27: case 28: case 31: case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 48: case 49: case 55: case 56: case 57: case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89: case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: return;

 case 53: case 54:
  if(A4898H40994())return;
  selector4=0;goto select;

 case 29:
  if(A4898W54<25)return;
  if(A4898W280<0){selector4=31;goto select;}
  work2=10;work3=A4898W144;if(work3==work2){__asm__ volatile("" ::: "memory");selector4=44;goto select;}
  work2=work3-11;if((unsigned)work2<2){__asm__ volatile("" ::: "memory");selector4=41;goto select;}
  work2=A4898WB8;selector4=0;if(!work2)goto select;__asm__ volatile("" ::: "memory");selector4=7;goto select;
 case 19:
  if(A4898H40994())return;
  work2=13;work3=A4898Gate;
  if(work3==work2){work2=A4898Count;selector4=17;if(work2)goto select;}
  selector4=(int)A4898Player;work2=A4898H4F334((void*)selector4,(void*)(selector4+348));
  work3=A4898W158;work3=work3<work2;selector4=17;if(!work3)return;goto select;
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

 case 47:
  if(A4898H40994())return;
  if(A4898NewButtons&64){work2=A4898Buttons&16384;selector4=6;if(work2)goto specialJump;__asm__ volatile("" ::: "memory");goto select;}
  work2=A4898WAC;selector4=50;if(!work2)return;goto select;
 case 50:
  if(A4898H40994())return;
  if(A4898NewButtons&64){work2=A4898Buttons&16384;selector4=6;if(work2)goto specialJump;goto select;}
  work2=A4898WAC;selector4=47;if(!work2)goto select;
  work2=A4898WA0;work3=A4898WB4;if(work2<0)work2=-work2;work2=work2<work3;if(!work2)return;
  work2=A4898WA4;if(work2<0)work2=-work2;work2=work2<1024;selector4=52;if(!work2)goto select;selector4=51;goto select;
 case 51: case 52:
  if(A4898H40994())return;
  if(A4898NewButtons&64){work2=A4898Buttons&16384;selector4=6;if(!work2)goto select;
   specialJump:A4898H4BEF8(7);work2=3;A4898W4C=work2;return;
  }
  work2=A4898WAC;selector4=47;if(!work2)goto select;
  work2=A4898WA0;work3=A4898WB4;if(work2<0)work2=-work2;work2=work2<work3;selector4=50;if(work2)return;__asm__ volatile("" ::: "memory");
  goto select;

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
