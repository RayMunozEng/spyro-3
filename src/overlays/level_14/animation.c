#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80093F80.
 * Assembly SHA256 7cbe08a694ff3915ddab59273f0c898f31b4cb5fd30af578cb0281e287f31165.
 * AI-generated; not human reviewed. All2135 original instructions and
 * 60 selectors (bias20) are required. Frame0x130 retains scratch10..114,
 * savedS0..S4, slotS2 and combinedS3.
 * Seventeen exact groups reuse verified11/13/32/42 with original frame and
 * address maps. State42 retains the original C5C8==3/20C-bit128 speed gate,
 * S1 short delta and S0 pointer60 lifetimes, spring and particle sequence.
 * All83 original27/60 rows retain both input-selected denominators, signed
 * division checks, scalar/vector stores and the final shared zero94 join.
 * All165 original75..77 rows retain independent absolute scalar fields,
 * pointer13C/148 tests, signed halfword36 selectors421/470..473/450 and
 * chained pointer sign test. Three wrapped products and their signed sum
 * retain original GPR5/GPR4/GPR3 results and exact event/particle/audio calls.
 * The decoder's stray outer case2 is removed; the original selector domain
 * is20..79, and27 reaches75's final zero94 store at800960B0.
 * Typed aliases remain distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, conditional/internal target,
 * selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics14Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics14Call363DCView1() __asm__("func_800363DC");
unsigned char Physics14Call40D10View1() __asm__("func_80040D10");
unsigned char Physics14Call41580View1() __asm__("func_80041580");
unsigned char Physics14Call416F4View1() __asm__("func_800416F4");
unsigned char Physics14Call417FCView1() __asm__("func_800417FC");
unsigned char Physics14Call41B64View1() __asm__("func_80041B64");
int Physics14Call4E9E4View1() __asm__("func_8004E9E4");
int Physics14Call4EA2CView1() __asm__("func_8004EA2C");
unsigned char Physics14Call4ED6CView1() __asm__("func_8004ED6C");
int Physics14Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics14Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics14Call4F168View1() __asm__("func_8004F168");
unsigned char Physics14Call4F178View1() __asm__("func_8004F178");
unsigned char Physics14Call4F194View1() __asm__("func_8004F194");
unsigned char Physics14Call4F1C8View1() __asm__("func_8004F1C8");
int Physics14CallRandView1() __asm__("rand");
extern unsigned char Physics14Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics14Data65920View1 __asm__("D_80065920");
extern void *Physics14Data6C570View1 __asm__("D_8006C570");
extern int Physics14Data6C640View1 __asm__("D_8006C640");
extern int Physics14Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics14Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics14Player0View1 __asm__("D_80070328");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics14Call40D10View2() __asm__("func_80040D10");
int Physics14Call41580View2() __asm__("func_80041580");
int Physics14Call416F4View2() __asm__("func_800416F4");
int Physics14Call417FCView2() __asm__("func_800417FC");
int Physics14Call41848View1() __asm__("func_80041848");
int Physics14Call41B64View2() __asm__("func_80041B64");
int Physics14Call4E9E4View2() __asm__("func_8004E9E4");
int Physics14Call4EA2CView2() __asm__("func_8004EA2C");
int Physics14Call4EDE8View2() __asm__("func_8004EDE8");
int Physics14Call4F08CView2() __asm__("func_8004F08C");
int Physics14Call4F168View2() __asm__("func_8004F168");
int Physics14Call4F178View2() __asm__("func_8004F178");
int Physics14Call4F194View2() __asm__("func_8004F194");
int Physics14Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics14Data6C5C8View1 __asm__("D_8006C5C8");
extern int Physics14Data6E044View2 __asm__("D_8006E044");
extern int Physics14Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics14Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics14PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics14Player94View1 __asm__("D_80070328+0x94");
extern int Physics14PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics14Player80View1 __asm__("D_80070328+0x80");
extern int Physics14PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics14Player64View1 __asm__("D_80070328+0x64");
extern int Physics14Player88View1 __asm__("D_80070328+0x88");
extern int Physics14Player84View1 __asm__("D_80070328+0x84");
extern int Physics14Player144View1 __asm__("D_80070328+0x144");
extern int Physics14Player60View1 __asm__("D_80070328+0x60");
extern int Physics14PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics14Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics14Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics14Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics14PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics14PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics14Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics14Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics14Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics14Player101View1 __asm__("D_80070328+0x101");
extern int Physics14PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics14Call4F178View3() __asm__("func_8004F178");
extern unsigned char Physics14Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics14Player148View1 __asm__("D_80070328+0x148");
extern int Physics14PlayerCCView1 __asm__("D_80070328+0xCC");
extern int Physics14PlayerD0View1 __asm__("D_80070328+0xD0");
extern int Physics14PlayerE4View1 __asm__("D_80070328+0xE4");
int Physics14Call40D10View3() __asm__("func_80040D10");
int Physics14Call410F8View1() __asm__("func_800410F8");
int Physics14Call41580View3() __asm__("func_80041580");
int Physics14Call417FCView3() __asm__("func_800417FC");
int Physics14Call41848View2() __asm__("func_80041848");
int Physics14Call41B64View3() __asm__("func_80041B64");
int Physics14Call4EA2CView3() __asm__("func_8004EA2C");
int Physics14Call4ED6CView2() __asm__("func_8004ED6C");
int Physics14Call4F110View1() __asm__("func_8004F110");
int Physics14Call4F168View3() __asm__("func_8004F168");
int Physics14Call4F178View4() __asm__("func_8004F178");
int Physics14Call4F194View3() __asm__("func_8004F194");
int Physics14CallRandView2() __asm__("rand");
extern int* Physics14Data6C570View2 __asm__("D_8006C570");
extern int Physics14Data6C640View2 __asm__("D_8006C640");
extern int Physics14Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics14Player0View4 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics14Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics14Player158View1 __asm__("D_80070328+0x158");
extern int Physics14Player20CView2 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
int Physics14Call4F110View2() __asm__("func_8004F110");
int Physics14Call4F178View5() __asm__("func_8004F178");
int Physics14Call4F194View4() __asm__("func_8004F194");
extern int Physics14Data6E1D4View1 __asm__("D_8006E1D4");
extern int Physics14Data6E1D8View1 __asm__("D_8006E1D8");
extern int Physics14Data6E52CView1 __asm__("D_8006E52C");
extern int Physics14Data6E530View1 __asm__("D_8006E530");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics14Player250View1 __asm__("D_80070328+0x250");
extern int Physics14Player54View1 __asm__("D_80070328+0x54");
extern int Physics14PlayerD4View1 __asm__("D_80070328+0xD4");
extern void *Physics14Data6C654View1 __asm__("D_8006C654");
int Physics14DataPlaySoundView1() __asm__("PlaySound");
extern int Physics14Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics14Player90View1 __asm__("D_80070328+0x90");
extern void *(*Physics14_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics14PlayerB4View1 __asm__("D_80070328+0xB4");
extern int Physics14Player13CView1 __asm__("D_80070328+0x13C");
void func_level_14_80093F80(int slotIndex) {
    register void *fieldA4State28 __asm__("$16");
    register void *vector8CState28 __asm__("$17");
    register int signedWord19 __asm__("$20");
    register int signedWord20 __asm__("$21");
    register int signedWord21 __asm__("$22");
    register void *savedPointer22 __asm__("$19");
    register void *savedPointer17 __asm__("$17");
    register void *(*particleCall3)() __asm__("$3");
    register int particleArg7 __asm__("$7");
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void *vectorAt40 __asm__("$16");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104,sp108,sp10C,sp110,sp114;
    }
    originalFrame;
    register int signedTableWord __asm__("$7");
    register void *globalVector80 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$18");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register unsigned char *globalByteE __asm__("$18");
    register void *globalField4CPointer __asm__("$16");
    register void *globalFieldB8PointerState1A __asm__("$16");
    register void *globalFieldB8PointerState20 __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    void *temp_v0_5;
    void *temp_v0_7;
    int raw34_temp_v0_8;
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    void *raw21_temp_s0_9;
    int raw21_temp_a0_5;
    int raw21_temp_a0_7;
    int raw21_temp_a1_2;
    int raw21_temp_a1_4;
    register int raw21_temp_s0_8 __asm__("$16");
    int raw21_temp_s1_4;
    int raw21_temp_v1_6;
    int raw21_temp_v1_7;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s0_7;
    register void *raw21_temp_s1_5 __asm__("$17");
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex=slotIndex;
    workWord2=savedSlotIndex*16;
    globalPointer=&Physics14Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics14Data6C570View1=(void*)workWord2;
    workWord2=Physics14Field(&Physics14Player0View1,int*,0x54);
    stateWord3=Physics14Field(&Physics14Player0View1,int*,0x48);
    combinedIndex=workWord2+savedSlotIndex;
    switch (stateWord3) {
    case 20:globalVector80 = &Physics14Player0View1 + 0x80;
        Physics14Call4F168View1(globalVector80);
        Physics14Call4F168View1(globalVector80 + 0xC);
        if (Physics14Data6E044View1 != 7) {
            Physics14Call40D10View1(0x1200);
            Physics14Call416F4View1();
            Physics14Call41580View1(0x5A, 0x10);
            return;
        }
        return;
    default:
        return;
    case 29:Physics14Call4F168View2(&originalFrame.sp10);
        call4=&originalFrame.sp10;
        call5=call4;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector80=&Physics14Player0View2+0x8C;
        Physics14Call4F1C8View2(call4,call5,globalVector80);
        if(Physics14PlayerB8View1){
            originalFrame.sp18=0;
            call5=(void*)Physics14Call4EDE8View2(&originalFrame.sp10,0);
            workWord2=(int)call5<65;
            if(!workWord2)Physics14Call4F08CView2(&originalFrame.sp10,call5,64);
            originalFrame.sp18=-192;
            call4=globalVector80-12;
            call5=globalVector80;
            call6=&originalFrame.sp10;
            goto vector29;
        }
        call5=(void*)Physics14Call4EDE8View2(&originalFrame.sp10,1);
        workWord2=(int)call5<257;
        if(!workWord2)Physics14Call4F08CView2(&originalFrame.sp10,call5,256);
        Physics14Call4F194View2(globalVector80,globalVector80,&originalFrame.sp10);
        call4=globalVector80-12;
        call5=globalVector80;
        call6=call5+0x5C;
        vector29:__asm__ volatile(""::"i"(0x800940F8):"memory");
        Physics14Call4F194View2(call4,call5,call6);
        call4=&Physics14Player0View2+0x8C;
        Physics14Call4F178View2(call4,call4-12);
        workWord2=Physics14Player94View1;
        workWord2=workWord2<-8960;
        goto clamp19;
    case 26:globalFieldB8PointerState1A = &Physics14Player0View3 + 0xB8;
        if (Physics14Field(&Physics14Player0View3, int *, 0xB8) != 0) {
            raw34_temp_v0_8 = Physics14Field(&Physics14Player0View3, int *, 0x94) - 0x600;
            Physics14Field(&Physics14Player0View3, int *, 0x94) = raw34_temp_v0_8;
            if (raw34_temp_v0_8 < -0x2300) {
                Physics14Field(&Physics14Player0View3, int *, 0x94) = -0x2300;
            }
            Physics14Call4F178View3(globalFieldB8PointerState1A - 0x38, globalFieldB8PointerState1A - 0x2C);
            return;
        }
        goto block_154;
    case 32:globalFieldB8PointerState20 = &Physics14Player0View1 + 0xB8;
        if (Physics14Field(&Physics14Player0View1, int *, 0xB8) != 0) {
            vectorAt30=&originalFrame.sp20;
            Physics14Call4F168View1(vectorAt30);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
            Physics14Call4F1C8View1(call4, call5, globalVector8CState20);
            originalFrame.sp28 = 0;
            temp_v0_6 = Physics14Call4EDE8View1(&originalFrame.sp20, 0);
            if (temp_v0_6 >= 0x41) {
                Physics14Call4F08CView1(&originalFrame.sp20, temp_v0_6, 0x40);
            }
            originalFrame.sp28 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Physics14Call4F194View1(globalVector80State20, globalVector8CState20, &originalFrame.sp20);
            Physics14Call4F178View1(globalVector8CState20, globalVector80State20);
        }
        else {
            Physics14Call4F168View1(globalFieldB8PointerState20 - 0x38);
            Physics14Call4F168View1(globalFieldB8PointerState20 - 0x2C);
        }
        if (Physics14Field(&Physics14Player0View1, int *, 0x94) < -0x2300) {
            Physics14Field(&Physics14Player0View1, int *, 0x94) = -0x2300;
        }
        if ((Physics14Field(&Physics14Player0View1, int *, 0x48) == 0x3A) && (Controller88028_SpawnParticle != 0) && (Physics14Data6C640View1 & 1)) {
            originalFrame.sp30 = 0;
            originalFrame.sp34 = 0;
            originalFrame.sp38 = 0xE;
            Physics14Call4F178View1(&originalFrame.sp40, (&Physics14Player0View1 + 0x94) - 0x94);
            originalFrame.sp40 += Physics14Call363DCView1(0, 0x12C);
            originalFrame.sp44 += Physics14Call363DCView1(0, 0x12C);
            originalFrame.sp48 += Physics14Call363DCView1(0, 0x12C);
            temp_v0_7 = Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp40, &originalFrame.sp30);
            Physics14Field(temp_v0_7, signed char *, 2) = 6;
            Physics14Field(temp_v0_7, signed char *, 0xA) = 0x20;
        }
        break;
    case 40:{
            register int numeric4 __asm__("$4");
            call5=&Physics14Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics14Field(call5,int*,0)&64;
            call4=&originalFrame.sp30;
            if(workWord2)goto block_132;
            call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics14Call410F8View1(call4,call5,0);
            workWord3=Physics14Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics14Player60View1;
                numeric4=Physics14Player144View1;
                workWord2-=workWord3;
                workWord3=numeric4<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp34=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp34=workWord2;
                }
                __asm__ volatile("":::"memory");
                workWord2=originalFrame.sp34;
                workWord3=numeric4+1;
                Physics14Player144View1=workWord3;
                workWord3=workWord3<21;
                workWord2=(workWord2<<7)>>8;
                originalFrame.sp34=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics14Player4CView1=0;
                }
            }
            raw21_temp_s1_4 = (int) (originalFrame.sp30 * 0x14) >> 7;
            Physics14Field(&Physics14Player0View4, int *, 0x64) = (int) ((Physics14Field(&Physics14Player0View4, int *, 0x64) + raw21_temp_s1_4) & 0xFFF);
            raw21_temp_v1_6 = (Physics14Field(&Physics14Player0View4, int *, 0x60) + ((int) (originalFrame.sp34 * -0xF) >> 7)) & 0xFFF;
            Physics14Field(&Physics14Player0View4, int *, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics14Field(&Physics14Player0View4, int *, 0x60) = (int) (raw21_temp_v1_6 - 0x1000);
            }
            if (Physics14Field(&Physics14Player0View4, int *, 0x60) < -0x320) {
                Physics14Field(&Physics14Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics14Field(&Physics14Player0View4, int *, 0x60) >= 0x321) {
                Physics14Field(&Physics14Player0View4, int *, 0x60) = 0x320;
            }
            if ((*Physics14Data6C570View2 & 0x40) || (Physics14Field(&Physics14Player0View4, int *, 0x4C) == 1)) {
                Physics14Field(&Physics14Player0View4, int *, 0xAC) = 0xE00;
            }
            else {
                Physics14Field(&Physics14Player0View4, int *, 0xAC) = 0;
            }
            if (Physics14Field(&Physics14Player0View4, int *, 0x4C) == 2) {
                Physics14Call417FCView3(0xC0, 0xC0);
                if (Physics14Field(&Physics14Player0View4, int *, 0xB0) < 0xE01) {
                    Physics14Field(&Physics14Player0View4, int *, 0x4C) = 0;
                }
            }
            else {
                Physics14Call417FCView3(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics14Player0View4 + 0x60;
            raw21_temp_a0_5 = (((int) (raw21_temp_s1_4 * -(Physics14Call4EA2CView3(Physics14Field(&Physics14Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics14Field(&Physics14Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics14Field(&Physics14Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics14Field(&Physics14Player0View4, int *, 0x14C) + raw21_temp_a0_5;
            Physics14Field(&Physics14Player0View4, int *, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 = (Physics14Field(&Physics14Player0View4, int *, 0x5C) + (raw21_temp_v1_7 >> 6)) & 0xFFF;
            Physics14Field(&Physics14Player0View4, int *, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics14Field(&Physics14Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_2 - 0x1000);
            }
            if (Physics14Field(&Physics14Player0View4, int *, 0x5C) < -0x300) {
                Physics14Field(&Physics14Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics14Field(&Physics14Player0View4, int *, 0x5C) >= 0x301) {
                Physics14Field(&Physics14Player0View4, int *, 0x5C) = 0x300;
            }
            Physics14Call41848View2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics14Call4F178View4(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2=Physics14CallRandView2()&31;
            if(workWord2)goto block_130;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            particleCall3=Physics21_SpawnParticle;
            call4=(void*)1;
            if(!particleCall3)goto block_130;
            call5=(void*)44;
            call6=&originalFrame.sp38;
            particleArg7=0;
            __asm__("":"=r"(particleArg7):"0"(particleArg7));
            workWord2=544;
            originalFrame.sp38=workWord2;
            workWord2=64;
            originalFrame.sp3C=0;
            __asm__ volatile(""::"i"(0x80094600):"memory");
            originalFrame.sp40=workWord2;
            goto block_129;
        }
    case 41:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics14Player0View4 + 0x20C;
            if (!(Physics14Field(&Physics14Player0View4, int *, 0x20C) & 0x40)) {
                if (Physics14Data6E044View3 != 7) {
                    Physics14Call410F8View1(&originalFrame.sp38, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3=originalFrame.sp38;
                    numeric4=originalFrame.sp3C;
                    workWord2=workWord3*5;
                    workWord2<<=2;
                    raw21_temp_s0_8=workWord2>>7;
                    workWord2=numeric4<<4;
                    numeric4-=workWord2;
                    numeric4>>=7;
                    workWord3=Physics14Player64View1;
                    workWord2=Physics14Player60View1;
                    workWord3+=raw21_temp_s0_8;
                    workWord3&=4095;
                    workWord2+=numeric4;
                    Physics14Player64View1=workWord3;
                    workWord3=workWord2&4095;
                    workWord2=workWord3<2049;
                    Physics14Player60View1=workWord3;
                    if(!workWord2){
                        workWord2=workWord3-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics14Player60View1=workWord2;
                    }
                    if (Physics14Field(&Physics14Player0View4, int *, 0x60) < -0x320) {
                        Physics14Field(&Physics14Player0View4, int *, 0x60) = -0x320;
                    }
                    if (Physics14Field(&Physics14Player0View4, int *, 0x60) >= 0x321) {
                        Physics14Field(&Physics14Player0View4, int *, 0x60) = 0x320;
                    }
                    workWord2=Physics14Call4EA2CView3(Physics14Player60View1);
                    workWord2<<=5;
                    workWord2=-workWord2;
                    product41=raw21_temp_s0_8*workWord2;
                    workWord3=Physics14Field(raw21_temp_s1_5,int*,-192);
                    numeric5=Physics14Player5CView1;
                    workWord2=(workWord3<<4)>>6;
                    numeric4=product41>>12;
                    numeric4-=workWord2;
                    workWord2=(numeric5<<6)>>6;
                    numeric4-=workWord2;
                    workWord3+=numeric4;
                    Physics14Field(raw21_temp_s1_5,int*,-192)=workWord3;
                    workWord3>>=6;
                    numeric5+=workWord3;
                    numeric5&=4095;
                    workWord2=numeric5<2049;
                    Physics14Player5CView1=numeric5;
                    if(!workWord2){
                        workWord2=numeric5-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics14Player5CView1=workWord2;
                    }
                    if (Physics14Field(&Physics14Player0View4, int *, 0x5C) < -0x300) {
                        Physics14Field(&Physics14Player0View4, int *, 0x5C) = -0x300;
                    }
                    if (Physics14Field(&Physics14Player0View4, int *, 0x5C) >= 0x301) {
                        Physics14Field(&Physics14Player0View4, int *, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics14Player0View4 + 0x80;
                Physics14Call4F168View3(raw21_temp_s0_9);
                Physics14Call4F168View3(raw21_temp_s0_9 + 0xC);
                workWord2=Physics14CallRandView2()&31;
                if(workWord2)goto block_130;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                particleCall3=Physics21_SpawnParticle;
                call4=(void*)1;
                if(!particleCall3)goto block_130;
                call5=(void*)44;
                call6=&originalFrame.sp50;
                particleArg7=0;
                __asm__("":"=r"(particleArg7):"0"(particleArg7));
                workWord2=544;
                originalFrame.sp50=workWord2;
                workWord2=64;
                originalFrame.sp54=0;
                originalFrame.sp58=workWord2;
                block_129:particleCall3(call4,call5,call6,particleArg7);
                block_130:globalPointer=&Physics14Player158View1;
                workWord2=Physics14Field(globalPointer,int*,0);
                workWord2++;
                Physics14Field(globalPointer,int*,0)=workWord2;
                return;
            }
            goto block_132;
        }
    case 42:{
            register int delta17 __asm__("$17");
            register void *pointer16 __asm__("$16");
            int product42;
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5=&Physics14Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics14Field(call5,int*,0)&64;
            call4=&originalFrame.sp40;
            if(!workWord2)goto run42;
            block_132:Physics14PlayerACView1=0;
            Physics14PlayerB0View1=0;
            return;
            run42:call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics14Call410F8View1(call4,call5,0);
            workWord3=Physics14Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics14Player60View1;
                numeric5=Physics14Player144View1;
                workWord2-=workWord3;
                workWord3=numeric5<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp44=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp44=workWord2;
                }
                __asm__ volatile("":::"memory");
                numeric4=originalFrame.sp44;
                workWord3=numeric5+1;
                Physics14Player144View1=workWord3;
                workWord3=workWord3<13;
                workWord2=numeric4*3;
                workWord2<<=5;
                workWord2>>=8;
                originalFrame.sp44=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics14Player4CView1=0;
                }
            }
            call5=&Physics14Player64View1;
            workWord3=originalFrame.sp40;
            numeric4=originalFrame.sp44;
            workWord2=workWord3*5;
            workWord2<<=2;
            delta17=workWord2>>7;
            workWord2=numeric4<<4;
            workWord3=Physics14Field(call5,int*,0);
            numeric4-=workWord2;
            workWord3+=delta17;
            workWord3&=4095;
            Physics14Field(call5,int*,0)=workWord3;
            workWord2=Physics14Player60View1;
            numeric4>>=7;
            workWord2+=numeric4;
            workWord3=workWord2&4095;
            workWord2=workWord3<2049;
            Physics14Player60View1=workWord3;
            if(!workWord2){
                workWord2=workWord3-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics14Player60View1=workWord2;
            }
            workWord2=Physics14Player60View1;
            workWord2=workWord2<-800;
            if(workWord2)Physics14Player60View1=-800;
            workWord2=Physics14Player60View1;
            workWord2=workWord2<801;
            if(!workWord2){
                workWord2=800;
                Physics14Player60View1=workWord2;
            }
            workWord3=Physics14Data6C5C8View1;
            __asm__ volatile(""::"r"(workWord3):"memory");
            workWord2=7168;
            Physics14PlayerACView1=workWord2;
            workWord2=3;
            numeric4=576;
            if(workWord3==workWord2){
                workWord2=Physics14Player20CView1&128;
                if(workWord2)Physics14PlayerACView1=0;
            }
            Physics14Call417FCView2(numeric4,48);
            pointer16=&Physics14Player60View1;
            workWord2=Physics14Call4EA2CView2(Physics14Field(pointer16,int*,0));
            workWord2<<=5;
            workWord2=-workWord2;
            product42=delta17*workWord2;
            workWord3=Physics14Player14CView1;
            numeric5=Physics14Player5CView1;
            workWord2=(workWord3<<4)>>6;
            numeric4=product42>>12;
            numeric4-=workWord2;
            workWord2=(numeric5<<6)>>6;
            numeric4-=workWord2;
            workWord3+=numeric4;
            Physics14Player14CView1=workWord3;
            workWord3>>=6;
            numeric5+=workWord3;
            numeric5&=4095;
            workWord2=numeric5<2049;
            Physics14Player5CView1=numeric5;
            if(!workWord2){
                workWord2=numeric5-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics14Player5CView1=workWord2;
            }
            workWord2=Physics14Player5CView1;
            workWord2=workWord2<-768;
            if(workWord2)Physics14Player5CView1=-768;
            workWord2=Physics14Player5CView1;
            workWord2=workWord2<769;
            if(!workWord2)Physics14Player5CView1=768;
            Physics14Call41848View1();
            Physics14Call4F178View2(pointer16+44,pointer16+32);
            if(Physics21_SpawnParticle&&Physics14PlayerB4View1>=2001){
                originalFrame.sp48=-400;
                originalFrame.sp4C=64-(Physics14CallRandView2()&127);
                originalFrame.sp50=-300;
                Physics21_SpawnParticle(1,44,&originalFrame.sp48,0);
                return;
            }
            return;
        }
    case 43:case 44:case 78:case 79:globalField4CPointer=&Physics14Player4CView1;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics14Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3!=workWord2)goto continue43;
        block_154:call4=&Physics14Player80View1;
        __asm__("":"=r"(call4):"0"(call4));
        Physics14Call4F168View3(call4);
        call4=&Physics14Player8CView1;
        __asm__("":"=r"(call4):"0"(call4));
        Physics14Call4F168View3(call4);
        return;
        continue43:workWord2=7;
        workWord3=Physics14Data6E044View3;
        if (workWord3 == workWord2) {
            Physics14Field(&Physics14Player0View4, int *, 0xB0) = 0;
        }
        else {
            Physics14Call40D10View3(0x980);
            raw21_var_v0_2 = Physics14Call41580View3(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics14Field(&Physics14Player0View4, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics14Field(&Physics14Player0View4, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics14Call417FCView3(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics14Player0View4 + 0xB0;
        if (Physics14Field(&Physics14Player0View4, int *, 0xB0) != 0) {
            Physics14Call41848View2();
            Physics14Call41B64View3();
            Physics14Field(&Physics14Player0View4, int *, 0x94) = 0;
        }
        else {
            Physics14Call4F168View3(raw21_temp_s0_11 - 0x30);
            Physics14Call4F168View3(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics14Player0View4 + 0x28;
            if (Physics14Field(&Physics14Player0View4, int *, 0x28) < 0) {
                if ((Physics14Field(&Physics14Player0View4, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics14Data6C640View2 & 1)) {
                    Physics14Call4F178View4(&originalFrame.sp48, raw21_temp_s4 - 0x28);
                    originalFrame.sp64 = 0x40;
                    originalFrame.sp68 = 0;
                    originalFrame.sp60 = (int) Physics14Field(&Physics14Player0View4, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp64 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics14Call4ED6CView2(raw21_temp_s2_3, &originalFrame.sp60, &originalFrame.sp70);
                    Physics14Call4F194View3(&originalFrame.sp48, &originalFrame.sp48, &originalFrame.sp70);
                    originalFrame.sp60 = 0;
                    originalFrame.sp50 = -Physics14Field(&Physics14Player0View4, int *, 0x28);
                    Physics14Call4ED6CView2(raw21_temp_s2_3, &originalFrame.sp60, &originalFrame.sp60);
                    Physics14Call4F110View1(&originalFrame.sp60, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp48, &originalFrame.sp60);
                    if (!(Physics14CallRandView2() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp48, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics14Player0View4 + 0xB0;
                    if ((Physics14Field(&Physics14Player0View4, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics14Data6C640View2 & 7) && !(Physics14CallRandView2() & 3)) {
                        originalFrame.sp80 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp84 = 0;
                        originalFrame.sp88 = 0;
                        Physics14Call4ED6CView2(raw21_temp_s1_7 - 0x80, &originalFrame.sp80, &originalFrame.sp80);
                        Physics14Call4F194View3(&originalFrame.sp80, &originalFrame.sp80, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp88 = -Physics14Field(&Physics14Player0View4, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp80, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics14Field(&Physics14Player0View4, int *, 0x144) - ((int) ((Physics14Field(&Physics14Player0View4, int *, 0x148) * 2) + (Physics14Field(&Physics14Player0View4, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics14Field(&Physics14Player0View4, int *, 0x148) + raw21_temp_a1_4;
        Physics14Field(&Physics14Player0View4, int *, 0x144) = raw21_temp_a1_4;
        Physics14Field(&Physics14Player0View4, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics14Field(&Physics14Player0View4, int *, 0x148) = 0x5900;
        }
        if (Physics14Field(&Physics14Player0View4, int *, 0x148) < -0x5900) {
            Physics14Field(&Physics14Player0View4, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 57:if ((workWord2=combinedIndex<9)==0) {
            Physics14Field(&Physics14Player0View4, int *, 0x80) = (int) (Physics14Field(&Physics14Player0View4, int *, 0x8C) * 0xF8);
            Physics14Field(&Physics14Player0View4, int *, 0x84) = (int) (Physics14Field(&Physics14Player0View4, int *, 0x90) * 0xF8);
            Physics14Field(&Physics14Player0View4, int *, 0x88) = (int) (Physics14Field(&Physics14Player0View4, int *, 0x94) * 0xF8);
            Physics14Call4F110View1(&Physics14Player0View4 + 0x80, 8);
        }
        block_188:call4=&Physics14Player0View4+0x8C;
        call5=call4-12;
        Physics14Call4F178View4(call4,call5);
        return;
    case 27:case 60:{
            register int denominator17 __asm__("$17");
            register int limit18 __asm__("$18");
            register void *pointer16 __asm__("$16");
            register void *vector17 __asm__("$17");
            int product27a,product27b;
            workWord2=Physics14Data6E538View1&192;
            denominator17=9216;
            if(!workWord2)goto slow27;
            Physics14Call40D10View2(9216);
            Physics14PlayerACView1=denominator17;
            limit18=64;
            goto input27;
            slow27:denominator17=4608;
            Physics14Call40D10View2(4608);
            limit18=32;
            input27:Physics14Call41580View2(25,5);
            pointer16=&Physics14PlayerACView1;
            __asm__("":"=r"(pointer16):"0"(pointer16));
            workWord3=Physics14Field(pointer16,int*,0);
            workWord2=workWord3<<5;
            workWord2/=denominator17;
            call4=(void*)Physics14PlayerA4View1;
            Physics14PlayerB0View1=workWord3;
            limit18=workWord2+limit18;
            workWord2=Physics14Call4EA2CView2(call4);
            workWord3=Physics14PlayerB0View1;
            product27a=workWord3*workWord2;
            call4=(void*)Physics14PlayerA4View1;
            workWord2=product27a>>12;
            Physics14Field(pointer16,int*,-44)=workWord2;
            workWord2=Physics14Call4E9E4View2(call4);
            workWord3=Physics14PlayerB0View1;
            product27b=workWord3*workWord2;
            vector17=&originalFrame.sp70;
            call4=vector17;
            __asm__ volatile(""::"r"(call4):"memory");
            call5=pointer16-44;
            pointer16-=32;
            Physics14Player88View1=0;
            workWord2=product27b>>12;
            Physics14Player84View1=workWord2;
            Physics14Call4F1C8View2(call4,call5,pointer16);
            originalFrame.sp78=0;
            workWord2=Physics14Call4EDE8View2(vector17,0);
            call5=(void*)workWord2;
            workWord2=limit18<(int)call5;
            call4=vector17;
            if(workWord2)Physics14Call4F08CView2(call4,call5,limit18);
            call4=pointer16;
            call5=call4;
            Physics14Call4F194View2(call4,call5,vector17);
            goto zeroVelocity75;
        }
    case 65:globalVector80=&Physics14Player0View2+0x80;
        Physics14Call4F168View2(globalVector80);
        Physics14Call4F168View2(globalVector80+12);
        if(Physics14Data6E044View2!=7){
            Physics14Call40D10View2(6016);
            Physics14Call416F4View2();
            Physics14Call41580View2(90,16);
        }
        workWord2=Physics14Player1BAView1;
        if(!workWord2)goto byteOne65;
        workWord2=Physics14Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics14Player1BAView1=0;
        Physics14Player1B9View1=workWord2;
        return;
        byteOne65:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics14Player1B9View1=workWord2;
        return;
    case 66:case 69:workWord3=Physics14Data6E044View2;
        workWord2=8;
        if(workWord3!=workWord2)Physics14Call40D10View2(6016);
        globalVector80=&Physics14Data6E538View1;
        workWord2=Physics14Field(globalVector80,int*,0)&12;
        if(workWord2)Physics14PlayerACView1=0;
        workWord2=Physics14Call416F4View2();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics14Call41580View2(call4,call5);
        workWord3=Physics14PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics14Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics14Player144View1;
        workWord2++;
        Physics14Player144View1=workWord2;
        goto saved101;
        reset101:Physics14Player144View1=0;
        saved101:call4=&Physics14PlayerACView1;
        globalVector80=(void*)Physics14Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics14Player20CView1&64;
        if(workWord2)Physics14Field(call4,int*,0)=0;
        else{
            workWord3=Physics14PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics14Field(call4,int*,0)=workWord3;
        }
        pass101:Physics14Call417FCView2(320,192);
        workWord2=Physics14Player101View1;
        call4=&Physics14PlayerACView1;
        Physics14Field(call4,int*,0)=(int)globalVector80;
        if(workWord2){
            Physics14Call4F168View2(call4-32);
            goto fields101;
        }
        Physics14Call41848View1(call4);
        Physics14Call41B64View2();
        fields101:call6=&Physics14PlayerFCView1;
        workWord2=Physics14Field(call6,unsigned char*,0);
        if(workWord2)goto block_303;
        workWord2=Physics14PlayerB8View1;
        call4=call6-112;
        if(workWord2)goto block_303;
        commit101:goto vectorInput71;
    case 67:{
            int lowProduct3Case67,lowProduct4Case67;
            Physics14Call40D10View1(0xC80);
            Physics14Call41580View1(0x28, 8);
            Physics14Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics14Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics14Call4EA2CView1(Physics14Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics14Field(&Physics14Player0View1,int*,0xB0);
            lowProduct3Case67=workWord3*workWord2;
            call4=(void*)Physics14Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp90=workWord2;
            workWord2=Physics14Call4E9E4View1(call4);
            workWord3=Physics14Field(&Physics14Player0View1,int*,0xB0);
            lowProduct4Case67=workWord3*workWord2;
            workWord2=lowProduct4Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp94=workWord2;
            Physics14Call4F1C8View1(&originalFrame.sp90, &originalFrame.sp90, globalVector8C);
            originalFrame.sp98 = 0;
            temp_v0_4 = Physics14Call4EDE8View1(&originalFrame.sp90, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics14Call4F08CView1(&originalFrame.sp90, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics14Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp90);
            Physics14Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract320_73;
            workWord2=Physics14Player4CView1;
            if(workWord2)goto subtract320_73;
            workWord2=(int)Physics14Data6C570View1;
            workWord2=Physics14Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add30_70;
            workWord2=Physics14Player144View1;
            if(workWord2)goto add30_70;
            goto subtract320_73;
        }
    case 68:{
            register void *child19 __asm__("$19");
            register int numeric5 __asm__("$5");
            int lowProduct3Case68,lowProduct4Case68;
            globalFieldA4Pointer=&Physics14Player4CView1;
            workWord2=2;
            globalPointer=(void*)Physics14Player250View1;
            call4=(void*)Physics14Field(globalFieldA4Pointer,int*,0);
            child19=Physics14Field(globalPointer,void**,0);
            numeric5=1600;
            if((int)call4==workWord2)numeric5=3200;
            Physics14Call40D10View1(numeric5,numeric5);
            Physics14Call41580View1(22,4);
            Physics14Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics14Call4EA2CView1(Physics14Field(globalFieldA4Pointer,int*,88));
            workWord3=Physics14PlayerB0View1;
            lowProduct3Case68=workWord3*workWord2;
            call4=(void*)Physics14Field(globalFieldA4Pointer,int*,88);
            workWord2=lowProduct3Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spA0=workWord2;
            workWord2=Physics14Call4E9E4View1(call4);
            workWord3=Physics14PlayerB0View1;
            lowProduct4Case68=workWord3*workWord2;
            workWord2=lowProduct4Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spA4=workWord2;
            Physics14Call4F1C8View1(&originalFrame.spA0, &originalFrame.spA0, globalVector8C);
            originalFrame.spA8 = 0;
            temp_v0_4 = Physics14Call4EDE8View1(&originalFrame.spA0, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x141) {
                Physics14Call4F08CView1(&originalFrame.spA0, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics14Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spA0);
            Physics14Call41B64View1();
            workWord2=Physics14Player94View1;
            workWord2-=320;
            Physics14Player94View1=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics14Field(globalFieldA4Pointer,int*,72)=workWord2;
            }
            workWord2=Physics14Field(globalFieldA4Pointer,unsigned char*,362);
            if(!workWord2)return;
            workWord2=Physics14Field(child19,int*,72);
            workWord2++;
            Physics14Field(child19,int*,72)=workWord2;
            return;
        }
    case 70:{
            int lowProduct3Case70,lowProduct4Case70;
            Physics14Call40D10View1(0xC80);
            Physics14Call41580View1(0x28, 8);
            Physics14Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics14Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics14Call4EA2CView1(Physics14Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics14Field(&Physics14Player0View1,int*,0xB0);
            lowProduct3Case70=workWord3*workWord2;
            call4=(void*)Physics14Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spB0=workWord2;
            workWord2=Physics14Call4E9E4View1(call4);
            workWord3=Physics14Field(&Physics14Player0View1,int*,0xB0);
            lowProduct4Case70=workWord3*workWord2;
            workWord2=lowProduct4Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spB4=workWord2;
            Physics14Call4F1C8View1(&originalFrame.spB0, &originalFrame.spB0, globalVector8C);
            originalFrame.spB8 = 0;
            temp_v0_4 = Physics14Call4EDE8View1(&originalFrame.spB0, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics14Call4F08CView1(&originalFrame.spB0, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics14Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spB0);
            Physics14Call41B64View1();
            workWord2=combinedIndex<7;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics14Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            add30_70:workWord2=Physics14Player94View1;
            workWord2+=30;
            Physics14Player94View1=workWord2;
            return;
        }
    case 71:{
            register int numeric5 __asm__("$5");
            int lowProduct3Case71,lowProduct4Case71;
            globalFieldA4Pointer=&Physics14PlayerB8View1;
            workWord2=Physics14Field(globalFieldA4Pointer,int*,0);
            if(!workWord2)goto grounded71;
            workWord2=2;
            workWord3=Physics14Player4CView1;
            numeric5=1600;
            if(workWord3==workWord2)numeric5=3200;
            Physics14Call40D10View1(numeric5,numeric5);
            Physics14Call41580View1(22,4);
            Physics14Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer-44;
            workWord2=Physics14Call4EA2CView1(Physics14PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics14PlayerB0View1;
            lowProduct3Case71=workWord3*workWord2;
            call4=(void*)Physics14PlayerA4View1;
            workWord2=lowProduct3Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spC0=workWord2;
            workWord2=Physics14Call4E9E4View1(call4);
            workWord3=Physics14PlayerB0View1;
            lowProduct4Case71=workWord3*workWord2;
            workWord2=lowProduct4Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spC4=workWord2;
            Physics14Call4F1C8View1(&originalFrame.spC0, &originalFrame.spC0, globalVector8C);
            originalFrame.spC8 = 0;
            temp_v0_4 = Physics14Call4EDE8View1(&originalFrame.spC0, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer-56;
            if (temp_v0_4 >= 0x141) {
                Physics14Call4F08CView1(&originalFrame.spC0, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer-56;
            }
            Physics14Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spC0);
            Physics14Call41B64View1();
            workWord2=Physics14Player94View1;
            workWord2-=320;
            Physics14Player94View1=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics14Player94View1=workWord2;
            }
            return;
        grounded71:
            workWord3=Physics14Data6E044View2;
            workWord2=8;
            if(workWord3!=workWord2)Physics14Call40D10View2(6016);
            globalVector80=&Physics14Data6E538View1;
            workWord2=Physics14Field(globalVector80,int*,0)&12;
            if(workWord2)Physics14PlayerACView1=0;
            workWord2=Physics14Call416F4View2();
            call4=(void*)90;
            call5=(void*)16;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalFieldA4Pointer=(void*)workWord2;
            workWord2=Physics14Call41580View2(call4,call5);
            workWord3=Physics14PlayerA8View1;
            if(workWord3<0)workWord3=-workWord3;
            workWord3=workWord3<8;
            __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
            call5=(void*)workWord2;
            if(!workWord3)goto reset71;
            workWord2=Physics14Field(globalVector80,int*,0)&12;
            if(!workWord2)goto reset71;
            workWord2=Physics14Player144View1;
            workWord2++;
            Physics14Player144View1=workWord2;
            goto saved71;
            reset71:Physics14Player144View1=0;
            saved71:call4=&Physics14PlayerACView1;
            globalVector80=(void*)Physics14Field(call4,int*,0);
            if(globalFieldA4Pointer)goto collision71;
            workWord2=(int)call5;
            if((int)call5<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass71;
            collision71:workWord2=Physics14Player20CView1&64;
            if(workWord2)Physics14Field(call4,int*,0)=0;
            else{
                workWord3=Physics14PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics14Field(call4,int*,0)=workWord3;
            }
            pass71:Physics14Call417FCView2(320,192);
            workWord2=Physics14Player101View1;
            call4=&Physics14PlayerACView1;
            Physics14Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics14Call4F168View2(call4-32);
                goto fields71;
            }
            Physics14Call41848View1(call4);
            Physics14Call41B64View2();
            fields71:call6=&Physics14PlayerFCView1;
            workWord2=Physics14Field(call6,unsigned char*,0);
            if(workWord2)goto block_303;
            workWord2=Physics14PlayerB8View1;
            call4=call6-112;
            if(!workWord2)goto vectorInput71;
            block_303:workWord2=Physics14PlayerA0View1;
            workWord2-=320;
            Physics14Player94View1=workWord2;
            return;
            vectorInput71:__asm__ volatile(""::"i"(0x800958F0):"memory");
            call5=call4;
            vectorCommit49:Physics14Call4F194View4(call4,call5,call6-20);
            return;
        }
    case 72:{
            int lowProduct3Case72,lowProduct4Case72;
            globalFieldA4Pointer=&Physics14Player4CView1;
            workWord2=Physics14Field(globalFieldA4Pointer,int*,0);
            if(workWord2)goto vector72;
            workWord2=combinedIndex<19;
            call4=globalFieldA4Pointer+64;
            if(workWord2)goto neutralVector72;
            call4=globalFieldA4Pointer+52;
            workWord3=Physics14Player8CView2;
            workWord2=workWord3*7;
            workWord3=Physics14Player90View1;
            workWord2<<=5;
            Physics14Field(globalFieldA4Pointer,int*,52)=workWord2;
            workWord2=workWord3*7;
            workWord3=Physics14Player94View1;
            workWord2<<=5;
            Physics14Player84View1=workWord2;
            workWord2=workWord3*7;
            workWord2<<=5;
            Physics14Player88View1=workWord2;
            Physics14Call4F110View2(call4,8);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            call4=globalFieldA4Pointer+64;
            neutralVector72:Physics14Call4F178View5(call4,globalFieldA4Pointer+52);
            workWord2=Physics14Player94View1;
            workWord2-=192;
            Physics14Player94View1=workWord2;
            workWord2=workWord2<-8960;
            clamp19:if(workWord2){
                workWord2=-8960;
                Physics14Player94View1=workWord2;
            }
            return;
            vector72:Physics14Call40D10View1(3200);
            Physics14Call41580View1(40,8);
            Physics14Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics14Call4EA2CView1(Physics14PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics14PlayerB0View1;
            lowProduct3Case72=workWord3*workWord2;
            call4=(void*)Physics14PlayerA4View1;
            workWord2=lowProduct3Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spD0=workWord2;
            workWord2=Physics14Call4E9E4View1(call4);
            workWord3=Physics14PlayerB0View1;
            lowProduct4Case72=workWord3*workWord2;
            workWord2=lowProduct4Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spD4=workWord2;
            Physics14Call4F1C8View1(&originalFrame.spD0, &originalFrame.spD0, globalVector8C);
            originalFrame.spD8 = 0;
            temp_v0_4 = Physics14Call4EDE8View1(&originalFrame.spD0, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x281) {
                Physics14Call4F08CView1(&originalFrame.spD0, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics14Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spD0);
            Physics14Call41B64View1();
            if(combinedIndex<13){
                __asm__(""::"r"(combinedIndex));
                workWord2=Physics14Player94View1;
                workWord2+=30;
            }
            else{
                workWord2=Physics14Player94View1;
                workWord2-=320;
            }
            Physics14Player94View1=workWord2;
            __asm__ volatile("" ::: "memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer=&Physics14Player0View1+0x148;
                __asm__("" : "=r"(globalPointer):"0"(globalPointer));
                particleIndex=0;
                if (Physics14Field(globalPointer,int*,0) != 0) {
                    workWord2=combinedIndex*4;
                    __asm__("" : "=r"(workWord2):"0"(workWord2));
                    particleThreshold=workWord2+combinedIndex;
                    globalByteE=globalPointer-0x13A;
                    vectorAt40=&originalFrame.spF0;
                    __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
                spawnParticleLoop72:
                    if (particleThreshold < (Physics14CallRandView1() & 0xFF)) {
                        workWord2=Physics14Call363DCView1(0,0xC);
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
                        signedTableWord = *(short*)(&Physics14Data65920View1 + workWord3);
                        call6=vectorAt40;
                        originalFrame.spE0 = (int) (signedTableWord * 5) >> 0xA;
                        workWord3=*(short*)(&Physics14Data658A0View1 + workWord3);
                        __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                        originalFrame.spE8 = 0xE;
                        originalFrame.spF0 = -0x12C;
                        originalFrame.spF4 = 0;
                        originalFrame.spF8 = -0xC8;
                        __asm__ volatile("" ::: "memory");
                        originalFrame.spE4 = (workWord3 * 5) >> 0xA;
                        Physics14Call4ED6CView1(call4, call5, call6, signedTableWord);
                        originalFrame.spF0 += Physics14Call363DCView1(0, 0x50);
                        originalFrame.spF4 += Physics14Call363DCView1(0, 0x50);
                        originalFrame.spF8 += Physics14Call363DCView1(0, 0x50);
                        Physics14Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.spE0);
                        workWord2=(int)temp_v0_5;
                        workWord3=8;
                        Physics14Field((void*)workWord2,signed char*,2)=workWord3;
                        workWord3=32;
                        Physics14Field((void*)workWord2,signed char*,10)=workWord3;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop72;
                    }
                }
            }
            break;
        }
    case 73:{
            int lowProduct3Case73,lowProduct4Case73;
            Physics14Call40D10View1(0x640);
            Physics14Call41580View1(0x28, 8);
            Physics14Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics14Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics14Call4EA2CView1(Physics14Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics14Field(&Physics14Player0View1,int*,0xB0);
            lowProduct3Case73=workWord3*workWord2;
            call4=(void*)Physics14Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spE0=workWord2;
            workWord2=Physics14Call4E9E4View1(call4);
            workWord3=Physics14Field(&Physics14Player0View1,int*,0xB0);
            lowProduct4Case73=workWord3*workWord2;
            workWord2=lowProduct4Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spE4=workWord2;
            Physics14Call4F1C8View1(&originalFrame.spE0, &originalFrame.spE0, globalVector8C);
            originalFrame.spE8 = 0;
            temp_v0_4 = Physics14Call4EDE8View1(&originalFrame.spE0, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics14Call4F08CView1(&originalFrame.spE0, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics14Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spE0);
            Physics14Call41B64View1();
            workWord2=combinedIndex<19;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics14Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            workWord2=Physics14Player94View1;
            workWord2+=100;
            Physics14Player94View1=workWord2;
            return;
            subtract320_73:globalPointer=&Physics14Player94View1;
            workWord2=Physics14Field(globalPointer,int*,0);
            workWord2-=320;
            Physics14Field(globalPointer,int*,0)=workWord2;
            return;
        }
    case 74:globalVector80=&Physics14Player0View2+0xB8;
        workWord2=Physics14Field(globalVector80,int*,0);
        if(!workWord2)goto zero105;
        vectorAt30=&originalFrame.sp100;
        Physics14Call4F168View2(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics14Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.sp108=0;
        call5=(void*)Physics14Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics14Call4F08CView2(vectorAt30,call5,64);
        originalFrame.sp108=-320;
        globalVector80-=56;
        Physics14Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics14Call4F178View2(globalVector8CState20,globalVector80);
        goto clamp74;
        zero105:Physics14Call4F168View2(globalVector80-56);
        Physics14Call4F168View2(globalVector80-44);
        goto clamp74;
        clamp74:globalPointer=&Physics14Player94View1;
        workWord2=Physics14Field(globalPointer,int*,0);
        workWord2=workWord2<-12800;
        if(workWord2){
            workWord2=-12800;
            Physics14Field(globalPointer,int*,0)=workWord2;
        }
        return;
    case 75:case 76:case 77:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            workWord3=Physics14Player4CView1;
            numeric4=1;
            Physics14Player8CView2=0;
            Physics14Player90View1=0;
            if(workWord3==numeric4)goto descend75;
            workWord2=workWord3<2;
            if(!workWord2)goto larger75;
            if(!workWord3)goto zero75;
            return;
            larger75:workWord2=2;
            if(workWord3==workWord2)goto zeroVelocity75;
            return;
            zero75:workWord2=Physics14Player144View1;
            workWord2++;
            Physics14Player144View1=workWord2;
            workWord2=workWord2<42;
            if(workWord2){
                workWord2=Physics14Player94View1;
                workWord2-=32;
                Physics14Player94View1=workWord2;
                return;
            }
            Physics14Player4CView1=numeric4;
            __asm__ volatile("":::"$2","memory");
            Physics14Player54View1=0;
            return;
            descend75:workWord2=Physics14Player94View1;
            workWord2-=2048;
            Physics14Player94View1=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2)Physics14Player94View1=-12800;
            workWord2=Physics14PlayerB8View1;
            if(workWord2)return;
            workWord2=Physics14Player54View1;
            workWord2=workWord2<9;
            if(workWord2)return;
            workWord3=Physics14Player13CView1;
            if(!workWord3)goto objectPassed75;
            workWord2=Physics14Player148View1;
            if(!workWord2)goto objectPassed75;
            workWord2=421;
            numeric5=Physics14Field((void*)workWord3,short*,54);
            numeric4=numeric5;
            if(numeric5==workWord2){
                workWord2=Physics14Field((void*)workWord3,int*,0);
                workWord2=Physics14Field((void*)workWord2,int*,16);
                if(workWord2<0)return;
            }
            workWord2=(numeric4-470)&65535;
            workWord2=(unsigned int)workWord2<4;
            if(workWord2)return;
            workWord2=450;
            if(numeric5==workWord2)return;
            objectPassed75:workWord2=Physics14PlayerE4View1;
            workWord2=workWord2<23;
            if(!workWord2)return;
            workWord3=Physics14PlayerCCView1;
            workWord2=Physics14Player8CView2;
            numeric5=workWord3*workWord2;
            workWord3=Physics14PlayerD0View1;
            workWord2=Physics14Player90View1;
            numeric4=workWord3*workWord2;
            workWord3=Physics14PlayerD4View1;
            workWord2=Physics14Player94View1;
            workWord3*=workWord2;
            workWord2=numeric5+numeric4;
            workWord2+=workWord3;
            if(workWord2>=0)return;
            workWord2=4096;
            particleCall3=Physics42_SpawnParticle;
            __asm__ volatile(""::"r"(particleCall3):"memory");
            Physics14Data6E1D4View1=workWord2;
            workWord2=30;
            Physics14Data6E1D8View1=workWord2;
            workWord2=2;
            Physics14Player4CView1=workWord2;
            Physics14Player54View1=0;
            call4=(void*)8;
            if(particleCall3){
                call5=(void*)33;
                call6=0;
                particleArg7=2;
                particleCall3(call4,call5,call6,particleArg7);
                Physics42_SpawnParticle(8,33,0,3);
            }
            call5=0;
            __asm__ volatile(""::"r"(call5):"memory");
            globalPointer=Physics14Data6C654View1;
            __asm__ volatile(""::"r"(globalPointer):"memory");
            workWord2=120;
            Physics14Data6E530View1=workWord2;
            workWord2=15;
            Physics14Data6E52CView1=workWord2;
            call4=(void*)Physics14Field(globalPointer,unsigned char*,20);
            Physics14DataPlaySoundView1(call4,call5,0);
            return;
            zeroVelocity75:Physics14Player94View1=0;
            return;
        }
    }
}
#undef Physics14Field


/* AI generated; not human reviewed. SCUS-94467 800960DC..80096870.
 * Verified11 shared table/flag and23 saved-vector case47 paths reused only
 * against original14 instructions. Original14 supplies1B/3C word71934/71908,
 * signed Moby38 halfword and private2 threshold/arithmetic chain. Numeric widths,
 * helper meaning,units/cadence unresolved. Original80096418..80096574 controls
 * stack18 copy, saved S0 status71934, source71908, signed Moby+38 and private+2.
 * Thresholds11F9/10CD and signed limits160/40 retain original units unknown.
 * Empty constraints preserve argument/load/branch-delay lifetimes; unused V0
 * result after1D helper establishes no return meaning. Six reserved stack words
 * retain originalframe60 without inventing accesses or source variable meanings.
 * Every code/table word, strict fullTU and every EXE/overlay hash required.
 */
extern Spyro Callback14Player __asm__("D_80070328");
int Callback14Call80037058(int x, int y) __asm__("func_80037058");
void Callback14Call80041930(void) __asm__("func_80041930");
void Callback14Call80041AE8(void) __asm__("func_80041AE8");
void Callback14Call80041C20(void) __asm__("func_80041C20");
void Callback14Call80042A44(void) __asm__("func_80042A44");
void Callback14Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback14Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
extern int D_80071924;
extern int** Callback14Table __asm__("D_8006D048+0x14");
int Callback14Call80055E84(Moby*) __asm__("func_80055E84");
void Callback14Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback14Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback14Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback14Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback14Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback14Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback14Values[] __asm__("D_8006FCF0");
void Callback14Call80049590(void) __asm__("func_80049590");
int Callback14Call8003BF6C(int,int) __asm__("func_8003BF6C");
extern int D_80071908,D_80071934;
int Callback14First42A44(void) __asm__("func_80042A44");
void func_level_14_800960DC(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; int reserved38[6];} local;
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback14Player.animationState) {
    case 0x14:
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback14Call80041C20();
        Callback14Player.unk9a=0;
        Callback14Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x20:
    case 0x44:
    case 0x4A:
        Callback14Call80041C20();
        Callback14Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80041930();
        goto queryC00;
    case 0x1D:
        Callback14Call80041C20();
        {register int unusedResult __asm__("$2")=Callback14First42A44();
        __asm__ volatile("" : : "r"(unusedResult));}
        goto queryC00;
    case 0x1A:
        Callback14Call80041C20();
        Callback14Call80042A44();
        goto queryC00;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback14Call80041C20();
        Callback14Call80042A44();
        descriptor=&Callback14Player.unk22[2];
        if (Callback14Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback14Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=decreasingValue-0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
        }
        goto clearSharedValue;
    case 0x2A:
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80049590();
        descriptor=&Callback14Player.unk22[2];
        if (Callback14Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback14Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback14Player.unk22[2];
        }
        if (Callback14Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback14Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback14Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback14Flags[flagOffset] = Callback14Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
    case 0x4E:
    case 0x4F:
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80041AE8();
        if ((unsigned char) Callback14Player.unk10[4] != 0) {
            computedValue = -Callback14Player.unk9ha[4] - Callback14Call80037058(Callback14Player.position.x, Callback14Player.position.y);
            positionValue = Callback14Player.unk4a - computedValue;
            Callback14Player.unk4[0] = computedValue;
            positionDelta = (int) Callback14Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback14Player.position.z=positionValue;
            return;
        }
        break;
    case 0x1B:
    case 0x3C: {
        register int* statusPointer __asm__("$16");
        register int belowThreshold __asm__("$2");
        register unsigned char* savedBase __asm__("$16");
        register Moby* sourceMoby __asm__("$4");
        register unsigned char* privateData __asm__("$5");
        register int inputValue __asm__("$3");
        register int halfword __asm__("$2");
        register int oldValue __asm__("$3");
        Callback14Call80041C20();
        Callback14Call80042A44();
        {register Vector3D* copyDestination __asm__("$4")=&local.first;
        __asm__("" : "=r"(copyDestination) : "0"(copyDestination));
        savedBase=(unsigned char*)&Callback14Player;
        func_8004F178(copyDestination,(Vector3D*)savedBase);}
        {register Vector3D* argument0 __asm__("$4")=(Vector3D*)savedBase;
        register Vector3D* argument1 __asm__("$5")=&local.first;
        register int argument2 __asm__("$6")=0;
        register int argument3 __asm__("$7")=0;
        __asm__("" : "=r"(argument0), "=r"(argument1), "=r"(argument2), "=r"(argument3) : "0"(argument0), "1"(argument1), "2"(argument2), "3"(argument3));
        statusPointer=&D_80071934;
        *statusPointer=0;
        local.first.z-=0x800;
        Callback14Call8001830C(argument0,argument1,argument2,argument3,Callback14Player.critterMobyPtr);}
        if(*statusPointer!=0) {
            Callback14Player.unk9ha[4]=D_80071908;
            Callback14Player.position.z=D_80071908+Callback14Player.critterMobyPtr->distanceToGround;
        } else Callback14Player.unk9ha[4]=0;
        sourceMoby=Callback14Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(sourceMoby) : "0"(sourceMoby) : "memory");
        if(sourceMoby!=0 && Callback14Player.critterMobyPtr->mobyClass==0x12C) {
            inputValue=Callback14Player.unk8[1];
            privateData=sourceMoby->mobyTag;
            if(inputValue>=0x11F9) {
                halfword=*(short*)(privateData+2);
                oldValue=halfword;
                __asm__("" : "=r"(oldValue) : "0"(oldValue), "r"(halfword));
                if(halfword<160) {
                    halfword=oldValue+40;
                    *(short*)(privateData+2)=halfword;
                }
            } else {
                belowThreshold=inputValue<0x10CD;
                __asm__("" : "=r"(belowThreshold) : "0"(belowThreshold));
                if(!belowThreshold) {
                halfword=*(short*)(privateData+2);
                oldValue=halfword;
                __asm__("" : "=r"(oldValue) : "0"(oldValue), "r"(halfword));
                if(halfword<40) {
                    halfword=oldValue+40;
                    *(short*)(privateData+2)=halfword;
                }
            } else {
                halfword=*(short*)(privateData+2);
                oldValue=halfword;
                if(halfword>0) {
                    halfword=oldValue-40;
                    __asm__("" : "=r"(halfword) : "0"(halfword));
                    *(short*)(privateData+2)=halfword;
                }
            }
            }
            Callback14Player.position.z+=*(short*)(privateData+2);
        }
        goto clearSharedValue;
    }
    case 0x43:
    case 0x46:
    case 0x49:
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80041930();
        if(Callback14Player.unk7a[3].z < 0 && Callback14Player.animationStateFrames >= 4) {
            Callback14Player.unk5=1;
        } else {
            if(Callback14Player.unk5==0 && !(Callback14Word8006E538 & 0x40) && Callback14Player.union144.a.unk13cb==0)
                Callback14Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register Vector3D* vectorBase __asm__("$17");
        register int flags __asm__("$18");
        if(Callback14Player.ticksSinceLastSurfaceTouch) {
            Callback14Call80041C20();
            Callback14Call80042A44();
        } else {
            func_800438F4();
            Callback14Call80041C20();
            Callback14Call80042A44();
            Callback14Call80041930();
            Callback14Call80043A38(0xC00);
        }
        progress=Callback14Call80055E84(Callback14Player.critterMobyPtr);
        if(Callback14Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            local.second.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback14Player.unk4a;
            vectorBase=&local.second;
            local.second.y=0;
            local.second.z=0x200-*sourceBase;
            Callback14Call8004ED6C((unsigned char*)sourceBase-0x14,vectorBase,vectorBase);
            {register Vector3D* argument0 __asm__("$4")=vectorBase;
            register Vector3D* argument1 __asm__("$5")=vectorBase;
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback14Call8001BA30(vectorBase,0x200,0,0,flags,Callback14Player.critterMobyPtr);
            if((Callback14Call80019138(vectorBase,0x200,0,0,flags,Callback14Player.critterMobyPtr)!=0 ||
                Callback14Call8001830C((Vector3D*)sourceBase,vectorBase,0,0x02000000,Callback14Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback14Table;
                    register int* entry __asm__("$3");
                    index &= 63;
                    entry=table[index];
                    entry[1] |= flags;
                }
            }
        }
        goto clearSharedValue;
    }
    case 0x4B:
    case 0x4C:
    case 0x4D:
        Callback14Call80041C20();
        Callback14Call80042A44();
        if(Callback14Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback14Call80041C20();
        Callback14Call80042A44();
        if(Callback14Player.unk5!=0)goto call41930;
queryC00:
        Callback14Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback14Call80041930();
clearSharedValue:
        Callback14Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 14
#define PlaySpyroSounds_level_14 func_level_14_80096874
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_14_8009697C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x43:
    case 0x44:
    case 0x46:
    case 0x49:
    case 0x4b:
    case 0x4c:
    case 0x4d:
        func_80043ABC(0);
        break;
    case 0x1b:
    case 0x3c:
        if (*(int*)((char*)&spyro + 0x50) != 6) func_80043ABC(0);
        *(int*)((char*)&spyro + 0x60) += *(int*)((char*)&spyro + 0xB4) / 96;
        break;
    case 0x47:
    case 0x48:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state) func_80043ABC(0);
            else func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x2b:
    case 0x2c:
    case 0x41:
    case 0x42:
    case 0x45:
    case 0x4a:
    case 0x4e:
    case 0x4f:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80096A68.
 * Verified11 water/character,37 hurt,22 squish/death,32 table,16 surface.
 * Original14 state12/scalar400, stack10/20/30 water,40 jump,50 surface and
 * shared sound after39 preserved. Numeric offsets are bytes; word60 wrap
 * vectors800/801/FFF give0/-7FF/-1, signed table-2/0/2 gives-1/0/1 for48.
 * Every invocation retains original code/internal jumps/owned table words;
 * strict complete TU and every original hash required. Helper meanings,
 * physical units, audio, cadence and live parity remain open.
 */
extern short Signed14TableB[] __asm__("D_80065920");
extern short Signed14TableA[] __asm__("D_800658A0");
extern int Raw14Yaw __asm__("D_80070328+0x64");
extern int Raw14TableIndex __asm__("D_80070328+0x298");
extern short D_800658A0[];
extern short D_80065920[];
extern int Raw14Animation __asm__("D_80070328+0x48");
extern unsigned char Raw14Union[] __asm__("D_80070328+0x144");
extern unsigned char Raw14Movement[] __asm__("D_80070328+0x50");
extern int Raw14X __asm__("D_80070328+0x8C");
extern int Raw14Word __asm__("D_80070328+0x50");
void Transition14_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern Spyro Transition14_D_80070328 __asm__("D_80070328");
int Transition14_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition14_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition14_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition14RawUnion[] __asm__("D_80070328+0x144");
extern int Transition14RawMovement __asm__("D_80070328+0x50");
extern void (*Call14Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw14State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call14A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw14NegativeWord __asm__("D_80070328+0x28");
int Transition14_func_8003636C(int,int) __asm__("func_8003636C");
void Transition14_func_800441F0(void) __asm__("func_800441F0");
void Transition14_func_80043A38(int) __asm__("func_80043A38");
void func_level_14_80096A68(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third; int gap3; Vector3D fourth; int gap4; Vector3D fifth;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    int maskedValue;
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register Vector3D *damageSource __asm__("$16");
    register Vector3D *damageDestination __asm__("$16");
    Vector3D *firstJumpSource;
    Vector3D *secondJumpSource;
    enum MovementState nextSubstate;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void *jumpPrivate __asm__("$18");
    register void *damagePrivate __asm__("$18");
    register Vector3D* jumpVector __asm__("$16");
    register int oldMovementC __asm__("$5");
    switch(arg0){
    case 0x14:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.unk5 = 0;
        Transition14_func_800441F0();
        Transition14_D_80070328.grounded = 1;
        Transition14_D_80070328.union144.a.unk13cb = Transition14_func_8003636C(1, 3);
        Transition14_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x1D: {
        register int oldState __asm__("$4")=Transition14RawMovement;
        register int first __asm__("$3")=Transition14_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition14RawMovement=second;
        second=Transition14_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition14_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition14_D_80070328.unk7a[2].x=first;
        third=Transition14_D_80070328.unk17e.z;
        second<<=6;
        Transition14_D_80070328.union144.a.unk13cb=oldState;
        Transition14_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition14_D_80070328.unk7a[3].z;
        Transition14_D_80070328.unk7a[2].z=second;
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.grounded=1;
        Transition14_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedHurtSound;
        goto clearPointers;
    }

    case 0x1A:
        savedBase = Transition14RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition14RawMovement;
        Transition14RawMovement = MOVEMENT_STATE_HURT;
        Transition14_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition14_func_8004F168(destination);
        Transition14_D_80070328.grounded = 1;
        Transition14_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    case 0x20:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition14_D_80070328.unk5 = 0;
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition14_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition14_D_80070328.movementState - 0xB) >= 2U) && (Transition14_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition14_D_80070328.movementState - 0x50));
                if ((Transition14_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw14NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition14_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call14A358(&vectors.first, 0x800);
                    vectors.first.z = firstResult;
                    if (firstResult != 0) {
                        firstParticleKind = 6;
                        if (D_80071934 != 0) {
                            firstParticleSubtype = 0x2E;
emitFirstParticle:
                            SpawnParticle(firstParticleKind, firstParticleSubtype, &vectors.first, 0);
                        }
                    }
                }
            }
            firstWrappedWord = Transition14_D_80070328.rotation.pitch & 0xFFF;
            Transition14_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition14_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition14_D_80070328.rotation.pitch > 0) {
                Transition14_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition14_D_80070328.unk5 = 1;
            }
            Transition14_func_8004F168((Vector3D *) ((unsigned char*)&Transition14_D_80070328.rotation.pitch + 0xEC));
            Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition14_D_80070328.rotation.pitch + 0x38), 0);
            Transition14_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition14_D_80070328.animationState == 0x2A) {
            Transition14_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition14_D_80070328.union144.a.unk13da = 0;
        }
        Transition14_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition14_D_80070328.unk20a = 0;
        Transition14_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw14State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw14NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition14_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call14A358(localVector, 0x800);
                    vectors.second.z = secondResult;
                    if (secondResult != 0) {
                        secondParticleKind = 6;
                        if (D_80071934 != 0) {
                            secondParticleSubtype = 0x2E;
emitSecondParticle:
                            SpawnParticle(secondParticleKind, secondParticleSubtype, localVector, 0);
                        }
                    }
                }
            }
            if (Transition14_D_80070328.animationState == 0x2E) {
                Transition14_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition14_D_80070328.rotation.pitch & 0xFFF;
            Transition14_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition14_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition14_D_80070328.rotation.pitch > 0) {
                Transition14_D_80070328.rotation.pitch = 0;
            }
            Transition14_D_80070328.unk5 = 1;
            Transition14_func_8004F168((Vector3D *) ((unsigned char*)&Transition14_D_80070328.animationState + 0x104));
            Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition14_D_80070328.animationState + 0x50), 0);
            Transition14_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition14_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition14_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition14RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition14RawUnion;
            *(int*)unionPointer=(-Transition14_D_80070328.unk7a[2].z)>>2;
            if(Transition14RawMovement!=8){Transition14_D_80070328.union144.a.unk13cc=0x5900;Transition14RawMovement=10;}
            Transition14_D_80070328.unk5=0;
            Transition14_D_80070328.unk8[0]=Transition14_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition14_D_80070328.grounded=1;
            Transition14_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call14A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition14RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition14RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw14TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition14RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition14_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw14TableIndex=((Raw14Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw14TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed14TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed14TableA+tableOffset);
        Transition14_D_80070328.unk7a[2].z=0;
        Transition14_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition14_D_80070328.grounded=1;
        Transition14_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedHurtSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition14_D_80070328.unk20a=0;
        Transition14_D_80070328.critterMobyPtr=0;
        return;
    case 0x1B:case 0x3C:
        movement=Raw14Movement;
        *(int*)movement=18;
        Transition14_D_80070328.unk5=0;
        Transition14_D_80070328.unk8[0]=Transition14_func_8004EDE8((Vector3D*)(movement+0x48),0);
        Transition14_D_80070328.grounded=1;
        Transition14_D_80070328.unk4a=0x400;
        return;
    case 0x41:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_func_800441F0();
        Transition14_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition14_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition14_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition14_D_80070328.movementState) + 0x48)));
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(&Transition14_D_80070328.unk7a[3], 0);
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw14Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition14_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition14_D_80070328.unk4[0] < 0)) {
            jumpVector=&vectors.fourth;
            func_8004F178(jumpVector, (Vector3D*)(initialMovement-0x50));
            vectors.fourth.z = -Transition14_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, jumpVector, 0);
            SpawnParticle(4, 0x29, jumpVector, 0);
        }
        }
        movement=Raw14Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition14_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition14_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition14_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition14_D_80070328.animationState==0x43)Transition14_D_80070328.unk5=1;
            else if(Transition14_D_80070328.animationState==0x46)Transition14_D_80070328.unk5=Transition14_D_80070328.movementState;
            else if(Transition14_D_80070328.animationState==0x49)Transition14_D_80070328.unk5=4;
        } else {
            Transition14_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(&Transition14_D_80070328.unk7a[3], 0);
        Transition14_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw14Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition14_D_80070328.unk7a[2].z = 0x12C0;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition14_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition14_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition14_D_80070328.animationState == 0x43) {
                    Transition14_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition14_D_80070328.animationState == 0x46) {
                    Transition14_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition14_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition14_D_80070328.grounded = 0;
            Transition14_D_80070328.idle = 0;
            Transition14_D_80070328.unk15g = 0;
        } else {
            Transition14_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition14_func_80043A38(0xC00);
            Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition14_D_80070328.grounded = 1;
        }
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(&Transition14_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition14_D_80070328.idle = 0;
        Transition14_D_80070328.unk15g = 0;
        return;
    case 0x4E:case 0x4F: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Raw14Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw14Union;
            *(int*)unionPointer=(-Transition14_D_80070328.unk7a[2].z)>>2;
            if(Raw14Word!=8){Transition14_D_80070328.union144.a.unk13cc=0x5900;Raw14Word=10;}
            Transition14_D_80070328.unk5=0;
            Transition14_D_80070328.unk8[0]=Transition14_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition14_D_80070328.grounded=1;
            Transition14_D_80070328.unk15b=1;
            localVector=&vectors.fifth;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.fifth.z+=0x400;
            lengthResult=Call14A358(localVector,0x800);
            vectors.fifth.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        return;
    }
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition14_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw14Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw14Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw14Word = MOVEMENT_STATE_HURT;
        if (Transition14_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition14_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition14_D_80070328.grounded = 0;
            Transition14_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition14_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition14_func_8004F0E8(damageDestination, 6);
            } else if (Transition14_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition14_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw14X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition14_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition14_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition14_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition14_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition14_D_80070328.unk7a[1]) + 0xC));
            Transition14_func_80043A38(0xC00);
            Transition14_D_80070328.grounded = 1;
        }
        Transition14_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.grounded = 1;
        Transition14_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw14Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition14_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw14Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition14_D_80070328.union144.a.unk13cc=1;
        }else Transition14_D_80070328.union144.a.unk13cc=0;
        Transition14_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition14_D_80070328.movementState) + 0x3C)));
        Transition14_D_80070328.unk7a[2].z = 0x800;
        Transition14_D_80070328.grounded = 0;
        Transition14_D_80070328.unk13a[0] = 0x20000;
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition14_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition14_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition14_D_80070328.unk5=nextSubstate;
        Transition14_D_80070328.grounded=0;
        Transition14_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80097AD0.
 * Assembly SHA256 db5e22dc06cae6cba7677ef2a401240aee7c188941db46720a283bf72c900a96.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1397 original instructions and60 state-table entries (bias20).
 * Original65..77 Sheila chains reuse the fully matched level23 baseline.
 * Each outer case cluster uses the target selectors; original49/66 guarded
 * exits remain distinct. View names preserve the original typed aliases;
 * exact symbol identities and per-state donor provenance are recorded.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim14Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim14Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim14Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim14PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim14PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim14PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim14PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim14Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim14Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim14Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim14Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim14Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim14Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim14Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim14Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim14Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim14PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim14Data66530View1[] __asm__("D_80066530");
extern int Anim14Data6E538View1 __asm__("D_8006E538"),Anim14Data6E53CView1 __asm__("D_8006E53C");
extern int Anim14Data6E044View1 __asm__("D_8006E044"),A4898Gate __asm__("D_8006E344"),A4898Count __asm__("D_8006C514");
int Anim14Call40994View1() __asm__("func_80040994");
int Anim14Call4BEF8View1() __asm__("func_8004BEF8");
int Anim14Call49688View1() __asm__("func_80049688");
extern int Anim14Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim14Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim14PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim14PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim14Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim14Player280View2 __asm__("D_80070328 + 0x280");
extern int Anim14Data6E538View2 __asm__("D_8006E538"),Anim14Data6E53CView2 __asm__("D_8006E53C");
extern int Anim14Data6E044View2 __asm__("D_8006E044"),A21Gate __asm__("D_8006E344"),A21Count __asm__("D_8006C514");
extern int (*Anim14Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim14Player24View1 __asm__("D_80070328 + 0x24");
extern unsigned char* Anim14Data6C654View1 __asm__("D_8006C654");
int Anim14CallPlaySoundView1() __asm__("PlaySound");
int Anim14Call40994View2() __asm__("func_80040994");
int Anim14Call4BEF8View2() __asm__("func_8004BEF8");
int Anim14Call498C0View1() __asm__("func_800498C0");
extern volatile int Anim14Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim14Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim14Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim14Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim14Data6EE2CView1 __asm__("D_8006EE2C");
int Anim14Call40BCCView1() __asm__("func_80040BCC");
int Anim14Call1A310View1() __asm__("func_8001A310");
extern int (*Anim14Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int Anim14Player44View1 __asm__("D_80070328 + 0x44");
extern int Anim14Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim14Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim14Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim14Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim14Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim14Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim14Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim14Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim14PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim14PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim14PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim14PlayerB8View3 __asm__("D_80070328 + 0xB8");
extern int Anim14PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim14PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim14PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim14PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim14Player144View3 __asm__("D_80070328 + 0x144");
extern int Anim14Player280View3 __asm__("D_80070328 + 0x280");
extern unsigned char Anim14Player0View1[] __asm__("D_80070328");
extern unsigned char *Anim14Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim14Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim14Data6E535View2 __asm__("D_8006E535");
extern int Anim14Data6E538View3 __asm__("D_8006E538");
extern int Anim14Data6E53CView3 __asm__("D_8006E53C");
extern int Anim14Data6E530View1 __asm__("D_8006E530");
extern int Anim14Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char *Anim14Data6C654View2 __asm__("D_8006C654");
extern int (*Anim14Data7431CView2)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim14DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim14Call55E84View1(void*) __asm__("func_80055E84");
int Anim14Call1A358View1(void*,int) __asm__("func_8001A358");
int Anim14Call4BEF8View3(int) __asm__("func_8004BEF8");
int Anim14CallPlaySoundView2(unsigned char,int,int) __asm__("PlaySound");
#define Anim14Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_14_80097AD0(void){
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int* savedPointer16 __asm__("$16");
    rawValue2=Anim14Player48View1;
    switch(rawValue2){
    case 20:
        if(Anim14Call40994View1())return;
        rawValue2=Anim14Data6E53CView1&64;
        nextSelector4=6;
        if(rawValue2)goto select;
        rawValue2=Anim14PlayerB8View1<4;
        nextSelector4=7;
        if(!rawValue2)goto select;
        if(Anim14PlayerE4View1>=23)goto select;
        rawValue3=Anim14Data6E538View1;
        rawValue2=rawValue3&128;
        nextSelector4=13;
        if(rawValue2)goto select;
        rawValue2=Anim14PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        if(rawValue2>=17){
            nextSelector4=1;
            goto select;
        }
        rawValue2=rawValue3&12;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        if(!rawValue2){
            rawValue2=Anim14PlayerACView1;
            nextSelector4=1;
            if(rawValue2)goto select;
        }
        if(Anim14Data6E044View1==7 || Anim14Player240View1) {
            savedPointer16=&Anim14Player48View2;
            __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
            if(!*savedPointer16)return;
            Anim14Call4BEF8View1(0);
            if(Anim14Data66530View1[*((unsigned char*)savedPointer16-0x2C)]>=96){
                Anim14Player14View1=Anim14Player15View1;
                Anim14Player16View1=Anim14Player17View1;
            }
            Anim14Player17View1=0;
            rawValue3=*savedPointer16;
            rawValue2=113;
            *((unsigned char*)savedPointer16-0x2C)=rawValue2;
            Anim14Player1F0View1=0;
            Anim14Player15View1=rawValue3;
            Anim14Player1ECView1=rawValue3;
            return;
        }
        rawValue2=Anim14PlayerFCView1;
        nextSelector4=15;
        if(rawValue2)goto select;
        Anim14Call49688View1();
        return;
    case 29:
        if(Anim14Player54View1<25)return;
        if(Anim14Player280View1<0){
            __asm__ volatile(""::"i"(0x80097CD0):"memory");
            nextSelector4=31;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim14Player144View1;
        if(rawValue3==rawValue2){
            __asm__ volatile("" ::: "memory");
            nextSelector4=44;
            goto select;
        }
        rawValue2=rawValue3-11;
        if((unsigned)rawValue2<2){
            __asm__ volatile("" ::: "memory");
            nextSelector4=41;
            goto select;
        }
        rawValue2=Anim14PlayerB8View1;
        nextSelector4=0;
        if(!rawValue2)goto select;
        __asm__ volatile("" ::: "memory");
        nextSelector4=7;
        goto select;
    case 26:
        if(Anim14Player24View1&16)return;
        if(Anim14Player54View2<25)return;
        if(Anim14Player280View2<0){
            nextSelector4=32;
            goto select;
        }
        Anim14CallPlaySoundView1(Anim14Data6C654View1[15],0,0);
        rawValue3=Anim14Player144View2;
        rawValue2=10;
        if(rawValue3==rawValue2){
            __asm__ volatile("" ::: "memory");
            nextSelector4=44;
            goto select;
        }
        rawValue2=rawValue3-11;
        if((unsigned)rawValue2<2){
            __asm__ volatile("" ::: "memory");
            nextSelector4=41;
            goto select;
        }
        rawValue2=Anim14PlayerB8View2;
        nextSelector4=0;
        if(!rawValue2)goto select;
        __asm__ volatile("" ::: "memory");
        nextSelector4=7;
        goto select;
    case 27:
        if(Anim14Player54View1<25)return;
        rawValue2=Anim14Player280View1;
        nextSelector4=60;
        if(rawValue2>=0)goto select;
        __asm__ volatile(""::"i"(0x80097E00):"memory");
        nextSelector4=31;
        goto select;
    case 32:
        if(Anim14Player54View2<125)return;
        call498C0:Anim14Call498C0View1();
        return;
    case 40:
        if(Anim14Call40994View2())return;
        if((Anim14Data6E538View2&128) && Anim14Player4CView1!=1){
            nextSelector4=42;
            goto select;
        }
        if(Anim14PlayerB0View1)return;
        rawValue2=Anim14Player20CView1&64;
        nextSelector4=41;
        if(!rawValue2)goto select;
        if(Anim14Player214View1<=0)return;
        goto select;
    case 41:
        if(Anim14Call40994View2())return;
        nextSelector4=Anim14Data6E538View2;
        rawValue2=nextSelector4&128;
        if(rawValue2){
            nextSelector4=42;
            goto select;
        }
        rawValue2=7;
        rawValue3=Anim14Data6E044View2;
        if(rawValue3==rawValue2)return;
        rawValue2=nextSelector4&64;
        nextSelector4=40;
        if(rawValue2)goto select;
        if(!(Anim14Player20CView1&64))return;
        if(!Anim14Player214View1)goto select;
        return;
    case 42:
        if(Anim14Call40BCCView1())return;
        if((Anim14Data6E538View2&128) || Anim14Player4CView1==1)goto flag64;
        rawValue2=Anim14Player20CView1&128;
        nextSelector4=40;
        if(!rawValue2)goto select;
        flag64:rawValue2=Anim14Player20CView1&64;
        nextSelector4=40;
        if(!rawValue2)return;
        goto select;
    case 43:
        {
            register unsigned char* byte4 __asm__("$4");
            if(Anim14Call40994View2())return;
            if((Anim14Data6E53CView2&64) && Anim14Player54View2>=9){
                nextSelector4=6;
                goto partialCall;
            }
            byte4=&Anim14Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto partialCall;
            }
            if(!(Anim14Data6E53CView2&128))goto check44;
            if(Anim14Player54View2<9)goto check44;
            rawValue2=*(int*)(Anim14Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto check44;
            rawValue2=Anim14Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(rawValue2)goto check44;
            goto select;
            partialCall:Anim14Call4BEF8View2(nextSelector4);
            check44:rawValue2=Anim14Data6E535View1;
            nextSelector4=44;
            if(!rawValue2)return;
            goto select;
        }
    case 44:
        {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3=Anim14Player4CView1;
            rawValue2=1;
            if(rawValue3!=rawValue2)goto other44;
            if(Anim14Data6E53CView2&0x850)goto callback44;
            if(Anim14Player54View2<61)return;
            callback44:callback2=Anim14Data74374View1;
            __asm__("" : "=r"(callback2):"0"(callback2));
            if(!callback2)goto missingCallback;
            callback2();
            return;
            missingCallback:goto call498C0;
            other44:if(Anim14Call40994View2())return;
            if((Anim14Data6E53CView2&64) && Anim14Player54View2>=9){
                nextSelector4=6;
                goto select;
            }
            byte4=&Anim14Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto select;
            }
            if(!(Anim14Data6E53CView2&128))goto mode44;
            if(Anim14Player54View2<9)goto mode44;
            rawValue2=*(int*)(Anim14Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto mode44;
            rawValue2=Anim14Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(!rawValue2)goto select;
            mode44:rawValue3=Anim14Data6E044View2;
            rawValue2=7;
            if(rawValue3==rawValue2)return;
            rawValue2=Anim14Data6E535View1;
            nextSelector4=43;
            if(rawValue2)return;
            __asm__ volatile(""::"i"(0x800981E8):"memory");
            goto select;
        }
    case 57:
        if(Anim14Player54View2<25)return;
        if(Anim14Player280View2<0){
            __asm__ volatile(""::"i"(0x8009821C):"memory");
            nextSelector4=31;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim14Player144View2;
        nextSelector4=41;
        if(rawValue3!=rawValue2)goto select;
        nextSelector4=44;
        goto select;
    case 60:
        {
            register int (*callback2)(int) __asm__("$2");
            callback:callback2=Anim14Data7431CView1;
            callback2(1);
            return;
        }
    case 65:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim14Player250View1;
            rawValue2=(int)Anim14Field((void*)rawValue2,void**,0);
            rawValue2=Anim14Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x800982B8):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim14PlayerB8View3<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)goto select;
        rawValue2=Anim14PlayerA8View2;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim14Data6E538View3&12;
        if(rawValue2)return;
        rawValue2=Anim14PlayerACView2;
        if(!rawValue2)return;
        goto select;
    case 66:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim14Player250View1;
            rawValue2=(int)Anim14Field((void*)rawValue2,void**,0);
            rawValue2=Anim14Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x800983AC):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim14PlayerB8View3<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query66;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input66;
    query66:
        rawValue2=Anim14Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input66:
        rawValue2=Anim14Data6E535View2;
        if(!rawValue2)goto held66;
        rawValue2=Anim14PlayerB0View2;
        nextSelector4=65;
        if(!rawValue2)goto select;
    held66:
        rawValue2=Anim14Data6E538View3&12;
        if(!rawValue2)return;
        rawValue2=Anim14Player144View3<16;
        nextSelector4=65;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x8009848C):"memory");
        goto select;
    case 67:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=Anim14Player54View3<16;
        if(!rawValue2){
            rawValue2=Anim14Data6E53CView3&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim14Player44View1;
            nextSelector4=(int)Anim14Player0View1;
            rawValue2=Anim14Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim14PlayerB8View3;
        if(rawValue2)goto finish67;
        rawValue2=Anim14Player54View3<16;
        if(rawValue2)goto finish67;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue3=Anim14PlayerCCView1;
        rawValue2=Anim14Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim14PlayerD0View1;
        rawValue2=Anim14Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim14PlayerD4View1;
        rawValue2=Anim14Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim14PlayerACView2;
        nextSelector4=66;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x800985E0):"memory");
        nextSelector4=65;
        goto select;
    finish67:
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8009861C):"memory");
        goto select;
    case 68:
        rawValue2=(int)Anim14Player250View1;
        callback3=Anim14Data7431CView2;
        record16=Anim14Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(9);
        if(rawValue2)return;
        rawValue2=Anim14Data6E53CView3&64;
        if(rawValue2){
            rawValue2=1;
            nextSelector4=(int)&Anim14Player4CView2;
            rawValue3=*(int*)nextSelector4;
            __asm__("":"=r"(rawValue2):"0"(rawValue2));
            if(rawValue3==rawValue2){
                rawValue2=Anim14Player54View3<31;
                nextSelector4-=76;
                if(rawValue2){
                    rawValue2=Anim14Call1A358View1((void*)nextSelector4,1024);
                    if(!rawValue2){
                        nextSelector4=70;
                        goto select;
                    }
                }
            }
            rawValue2=1;
            Anim14Player1B6View1=rawValue2;
            Anim14Field(record16,int*,0x48)=0;
        }
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            nextSelector4=(int)&Anim14Player4CView2;
            rawValue2=*(int*)nextSelector4;
            nextSelector4-=76;
            if(rawValue2){
                product5=Anim14Player44View1;
                rawValue2=Anim14Call1A358View1((void*)nextSelector4,product5+512);
                nextSelector4=75;
                if(!rawValue2)goto select;
            }
        }
        rawValue2=Anim14PlayerB8View3;
        if(rawValue2)return;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue2=Anim14Player1B6View1;
        if(rawValue2){
            rawValue2=Anim14Field(record16,int*,0x48)<7;
            if(rawValue2){
                rawValue2=2;
                rawValue3=Anim14Player50View1;
                nextSelector4=67;
                if(rawValue3!=rawValue2)goto effectSelect;
                nextSelector4=73;
                goto effectSelect;
            }
        }
        rawValue3=Anim14Player50View1;
        rawValue2=2;
        if(rawValue3==rawValue2){
            Anim14Field(record16,int*,0x48)=0;
        }
        else{
            rawValue2=255;
            Anim14Field(record16,int*,0x48)=rawValue2;
        }
        rawValue2=Anim14PlayerACView2;
        nextSelector4=66;
        if(rawValue2)goto effectSelect;
        nextSelector4=69;
        goto effectSelect;
    case 69:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim14Player250View1;
            rawValue2=(int)Anim14Field((void*)rawValue2,void**,0);
            rawValue2=Anim14Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x80098814):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim14PlayerB8View3<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query69;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input69;
    query69:
        rawValue2=Anim14Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input69:
        rawValue2=Anim14Data6E535View2;
        if(!rawValue2)goto held69;
        rawValue2=Anim14PlayerB0View2;
        if(!rawValue2){
            __asm__ volatile(""::"i"(0x800988C4):"memory");
            nextSelector4=65;
            goto select;
        }
    held69:
        rawValue2=Anim14Data6E538View3&12;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim14Player144View3<16;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x800988FC):"memory");
        nextSelector4=65;
        goto select;
    case 70:case 73:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim14Player44View1;
            nextSelector4=(int)Anim14Player0View1;
            rawValue2=Anim14Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim14PlayerB8View3;
        if(rawValue2)goto finish70;
        rawValue2=Anim14Player54View3<16;
        if(rawValue2)goto finish70;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue3=Anim14PlayerCCView1;
        rawValue2=Anim14Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim14PlayerD0View1;
        rawValue2=Anim14Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim14PlayerD4View1;
        rawValue2=Anim14Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim14PlayerACView2;
        nextSelector4=66;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80098A20):"memory");
        nextSelector4=65;
        goto select;
    finish70:
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80098A5C):"memory");
        goto select;
    case 71:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=3;
        rawValue3=Anim14Player50View1;
        if(rawValue3!=rawValue2)goto other71;
        rawValue2=Anim14PlayerB8View3;
        if(rawValue2)goto finish71;
        rawValue2=Anim14PlayerE4View2<23;
        nextSelector4=71;
        if(!rawValue2)return;
    effectSelect:
        Anim14Call4BEF8View3(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim14DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        rawValue2=(int)Anim14Data6C654View2;
        product5=0;
        nextSelector4=Anim14Field((void*)rawValue2,unsigned char*,0x12);
        Anim14CallPlaySoundView2((unsigned char)nextSelector4,product5,0);
        rawValue2=Anim14Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim14Data6E530View1=rawValue2;
        rawValue2=15;
        Anim14Data6E52CView1=rawValue2;
        return;
    finish71:
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80098B6C):"memory");
        goto select;
    other71:
        rawValue2=Anim14PlayerB8View3<4;
        nextSelector4=71;
        if(!rawValue2)goto select;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query71;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)goto query71;
        rawValue2=Anim14Data6E535View2;
        nextSelector4=66;
        if(!rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80098BEC):"memory");
        nextSelector4=65;
        goto select;
    query71:
        rawValue2=Anim14Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<16;
        if(rawValue2)return;
        rawValue2=Anim14Data6E535View2;
        nextSelector4=66;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80098C1C):"memory");
        goto select;
    case 72:
        rawValue2=Anim14Player4CView2;
        if(!rawValue2)goto finish72;
        rawValue2=Anim14Player280View3;
        if(rawValue2<0)goto finish72;
        rawValue2=Anim14Player54View3<16;
        if(!rawValue2){
            rawValue2=Anim14Data6E53CView3&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim14Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim14Player44View1;
            nextSelector4=(int)Anim14Player0View1;
            rawValue2=Anim14Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim14PlayerB8View3;
        if(rawValue2)goto finish72;
        rawValue2=Anim14Player54View3<16;
        if(rawValue2)goto finish72;
        rawValue2=Anim14PlayerE4View2<23;
        if(!rawValue2)goto finish72;
        rawValue3=Anim14PlayerCCView1;
        rawValue2=Anim14Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim14PlayerD0View1;
        rawValue2=Anim14Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim14PlayerD4View1;
        rawValue2=Anim14Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)goto finish72;
        rawValue2=Anim14PlayerACView2;
        nextSelector4=66;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80098D7C):"memory");
        nextSelector4=65;
        goto select;
    finish72:
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim14Player280View3;
        if(rawValue2<0){
            nextSelector4=74;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim14Player144View3;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x80098DE8):"memory");
            nextSelector4=79;
            goto select;
        }
        rawValue2=Anim14PlayerB8View3;
        nextSelector4=65;
        if(!rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80098E04):"memory");
        nextSelector4=68;
        goto select;
    case 74:
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        goto call498C0;
    case 75:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim14Player4CView2;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim14Player54View3<61;
        nextSelector4=68;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=76;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80098EC4):"memory");
        goto select;
    case 76:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim14Player4CView2;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim14Player54View3<61;
        nextSelector4=68;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80098F14):"memory");
        goto select;
    case 77:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        nextSelector4=(int)Anim14Player250View1;
        rawValue2=Anim14Player48View3;
        rawValue3=Anim14Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim14Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=65;
        if(!rawValue2)return;
        goto select;
    case 78:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=Anim14Data6E53CView3&64;
        if(rawValue2){
            rawValue2=Anim14Player54View3<9;
            nextSelector4=67;
            if(!rawValue2)goto partial78;
        }
        rawValue2=Anim14Player100View1;
        nextSelector4=68;
        if(rawValue2)goto after78;
        partial78:Anim14Call4BEF8View3(nextSelector4);
        after78:rawValue2=Anim14Data6E535View2;
        nextSelector4=79;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80098FF0):"memory");
        goto select;
    case 79:
        rawValue2=Anim14Data7431CView2(9);
        if(rawValue2)return;
        if((Anim14Data6E53CView3&64) && Anim14Player54View3>=9){
            nextSelector4=67;
            goto select;
        }
        rawValue2=Anim14Player100View1;
        if(!rawValue2){
            nextSelector4=68;
            goto select;
        }
        rawValue2=7;
        rawValue3=Anim14Data6E044View2;
        if(rawValue3==rawValue2)return;
        rawValue2=Anim14Data6E535View2;
        nextSelector4=78;
        if(rawValue2)return;
        goto select;
        default:return;
    }
    select:Anim14Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim14Field
