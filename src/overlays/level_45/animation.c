#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800869F4.
* Assembly SHA256 f735d89ecd4af41c24d96f9f8cec95467c95085b9473505280a3a7ab6d6dde23.
* AI-generated; not human reviewed. All1243 original instructions, * 0 selectors bias0 and 0 owned padding words are required.
* Original frame0xB0; every concrete field width and producer is retained.
* Sparse selector dispatch uses the original branch tree, with no jump table.
* Verified25 movement and particle bodies retain original stack/field producers.
* The initial S1 playerVector54 pointer is used by43/44 and55 before any replacement;
* state25 retains the original S0 selector as its upper-clamp store source.
* States33..35 and160..163 preserve separate ordinary C product lifetimes and
* the original physical shared tail at80087C18/80087CA0/80087CB0/80087CE8.
* The160 input frame is SP70..80; original shifts2, clamp5 and conditional
* maximum remain separate from33's shifts3, clamp10 and additive recurrence.
* State61 preserves the physical shared zero store at80087644 and both signed
* input branches. Complete ordinary signed divisions800/352 retain original
* magic-product instructions. Every saved S0..S4/RA and frame0xB0 is required.
* Initialized zero-word dependencies follow actual original argument producers;
* the last sparse dispatch records its original unconditional jump80086AC4.
* Repeated identical declarations are removed; distinct typed aliases stay
* distinct. Initialized empty constraints and original address metadata emit
* zero CPU instructions; frozen C tools emit words. Units/fixed point, helper
* contracts and caller rate remain unresolved; cadence is per invocation.
* Falsification: every native/linked instruction, actual internal/conditional
* target, selector/data and full EXE/every-overlay retail hashes. Binary identity
* does not establish synchronized runtime or system completeness. */
#define Physics45Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
extern void *Physics45Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics45Data6E548View1 __asm__("D_8006E548");
int Physics45Call40D10View1() __asm__("func_80040D10");
int Physics45Call40F48View1() __asm__("func_80040F48");
int Physics45Call41404View1() __asm__("func_80041404");
int Physics45Call41580View1() __asm__("func_80041580");
int Physics45Call416F4View1() __asm__("func_800416F4");
int Physics45Call417FCView1() __asm__("func_800417FC");
int Physics45Call41848View1() __asm__("func_80041848");
int Physics45Call41B64View1() __asm__("func_80041B64");
int Physics45Call4E9E4View1() __asm__("func_8004E9E4");
int Physics45Call4EA2CView1() __asm__("func_8004EA2C");
int Physics45Call4F168View1() __asm__("func_8004F168");
int Physics45Call4F194View1() __asm__("func_8004F194");
extern int Physics45Data6763CView1 __asm__("D_8006763C");
extern int Physics45Data67640View1 __asm__("D_80067640");
extern int Physics45Data67644View1 __asm__("D_80067644");
extern int Physics45Data6E044View1 __asm__("D_8006E044");
extern int Physics45PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics45Player94View1 __asm__("D_80070328+0x94");
extern int Physics45PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics45Player80View1 __asm__("D_80070328+0x80");
extern int Physics45PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics45Player64View1 __asm__("D_80070328+0x64");
extern int Physics45Player88View1 __asm__("D_80070328+0x88");
extern int Physics45Player84View1 __asm__("D_80070328+0x84");
extern int Physics45Player144View1 __asm__("D_80070328+0x144");
extern int Physics45Player60View1 __asm__("D_80070328+0x60");
extern int Physics45PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics45Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics45PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics45PlayerA0View1 __asm__("D_80070328+0xA0");
int Physics45Call13E38View1() __asm__("func_80013E38");
int Physics45Call410F8View1() __asm__("func_800410F8");
int Physics45Call41848View2() __asm__("func_80041848");
int Physics45Call41B64View2() __asm__("func_80041B64");
int Physics45Call4E4E4View1() __asm__("func_8004E4E4");
int Physics45Call4EA2CView2() __asm__("func_8004EA2C");
int Physics45Call4F194View2() __asm__("func_8004F194");
extern int Physics45Data67630View1 __asm__("D_80067630");
extern int Physics45Data67634View1 __asm__("D_80067634");
extern int Physics45Data67638View1 __asm__("D_80067638");
extern int Physics45Data6FA38View1 __asm__("D_8006FA38");
extern int Physics45Data71908View1 __asm__("D_80071908");
extern int Physics45Player130View1 __asm__("D_80070328+0x130");
extern int Physics45Player144View2 __asm__("D_80070328+0x144");
extern short Physics45Player148View1 __asm__("D_80070328+0x148");
extern short Physics45Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics45Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics45Player150View1 __asm__("D_80070328+0x150");
extern int Physics45Player154View1 __asm__("D_80070328+0x154");
extern int Physics45Player160View1 __asm__("D_80070328+0x160");
extern int Physics45Player48View1 __asm__("D_80070328+0x48");
extern int Physics45Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics45Player5CView1 __asm__("D_80070328+0x5C");
extern int Physics45Player60View2 __asm__("D_80070328+0x60");
extern int Physics45Player64View2 __asm__("D_80070328+0x64");
extern int Physics45Player8View1 __asm__("D_80070328+0x8");
extern int Physics45Player88View2 __asm__("D_80070328+0x88");
extern int Physics45Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics45Player90View1 __asm__("D_80070328+0x90");
extern int Physics45Player94View2 __asm__("D_80070328+0x94");
extern int Physics45PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics45PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics45PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics45PlayerF8View1 __asm__("D_80070328+0xF8");
int Physics45Call40D10View2() __asm__("func_80040D10");
int Physics45Call41580View2() __asm__("func_80041580");
int Physics45Call417FCView2() __asm__("func_800417FC");
int Physics45Call41848View3() __asm__("func_80041848");
int Physics45Call41B64View3() __asm__("func_80041B64");
int Physics45Call4ED6CView1() __asm__("func_8004ED6C");
int Physics45Call4F110View1() __asm__("func_8004F110");
int Physics45Call4F168View2() __asm__("func_8004F168");
int Physics45Call4F178View1() __asm__("func_8004F178");
int Physics45Call4F194View3() __asm__("func_8004F194");
int Physics45CallRandView1() __asm__("rand");
extern int Physics45Data6C640View1 __asm__("D_8006C640");
extern int Physics45Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics45Player0View1 __asm__("D_80070328");
extern void *(*Physics45SpawnParticleView1)() __asm__("SpawnParticle");
extern int Physics45Player148View2 __asm__("D_80070328+0x148");
extern unsigned char Physics45Player54View1 __asm__("D_80070328+0x54");
void func_level_45_800869F4(int slotIndex) {
    register int stateSelector16 __asm__("$16");
    register void *playerVector54 __asm__("$17");
    register int numeric4 __asm__("$4");
    register int numeric5 __asm__("$5");
    register int delta18 __asm__("$18");
    register int delta19 __asm__("$19");
    register void *movementPointer17 __asm__("$17");
    register void *scratchPointer16 __asm__("$16");
    register int responseLimit16 __asm__("$16");
    int springProduct33, springProduct160;
    register int workWord2 __asm__("$2");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0, lowProduct1;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94;
    }
    originalFrame;
    register void *globalVector80 __asm__("$16");
    register int workWord3 __asm__("$3");
    register int savedSlotIndex __asm__("$18");
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    int raw21_temp_a0_7;
    int raw21_temp_a1_4;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex = slotIndex;
    workWord2 = savedSlotIndex*16;
    globalPointer = &Physics45Data6E548View1;
    stateSelector16 = Physics45Player48View1;
    __asm__("":"=r"(globalPointer):"0"(globalPointer), "r"(stateSelector16), "r"(workWord2));
    workWord2 += (int)globalPointer;
    playerVector54 = &Physics45Player54View1;
    __asm__ volatile("":"=r"(workWord2), "=r"(playerVector54):"0"(workWord2), "1"(playerVector54):"memory");
    Physics45Data6C570View1 = (void*)workWord2;
    workWord2 = stateSelector16 < 45;
    if (!workWord2) goto highDispatch45;
    workWord2 = stateSelector16 < 43;
    if (!workWord2) goto state43;
    workWord2 = 25;
    if (stateSelector16 == workWord2) goto state25;
    workWord2 = stateSelector16 < 26;
    if (!workWord2) goto middleDispatch45;
    workWord2 = 20;
    if (stateSelector16 == workWord2) goto state20;
    return;
    middleDispatch45:workWord2 = stateSelector16 < 36;
    if (!workWord2) return;
    workWord2 = stateSelector16 < 33;
    if (workWord2) return;
    call4 = &originalFrame.sp18;
    goto state33;
    highDispatch45:workWord2 = 55;
    if (stateSelector16 == workWord2) goto state55;
    workWord2 = stateSelector16 < 56;
    if (workWord2) goto upperReset45;
    workWord2 = 61;
    if (stateSelector16 == workWord2) goto state61;
    workWord2 = stateSelector16 < 61;
    if (workWord2) return;
    workWord2 = stateSelector16 < 164;
    if (!workWord2) return;
    workWord2 = stateSelector16 < 160;
    if (workWord2) return;
    call4 = &originalFrame.sp70;
    __asm__ volatile(""::"r"(call4), "i"(0x80086AC4):"memory");
    goto state160;
    upperReset45:workWord2 = stateSelector16 < 53;
    if (workWord2) return;
state20:
    __asm__ volatile(""::"r"(stateSelector16));
    globalVector80 = &Physics45Player80View1;
    Physics45Call4F168View1(globalVector80);
    Physics45Call4F168View1(globalVector80+12);
    workWord3 = Physics45Data6E044View1;
    workWord2 = 7;
    if (workWord3 == workWord2) return;
    Physics45Call40D10View1(0x1200);
    Physics45Call416F4View1();
    Physics45Call41580View1(90, 16);
    return;
    state25:Physics45Call40F48View1(&originalFrame.sp10, 1);
    workWord2 = originalFrame.sp10;
    workWord2 >>= 1;
    Physics45PlayerA8View1 = workWord2;
    workWord2 = workWord2 < -25;
    if (workWord2){
        workWord2 = -25;
        Physics45PlayerA8View1 = workWord2;
    }
    workWord2 = Physics45PlayerA8View1;
    workWord2 = workWord2 < 26;
    if (!workWord2)Physics45PlayerA8View1 = stateSelector16;
    call4 = (void*)Physics45PlayerA8View1;
    Physics45Call41404View1(call4);
    Physics45Call417FCView1(576, 384);
    workWord2 = Physics45Call4EA2CView1(Physics45Player64View1);
    workWord3 = Physics45PlayerB0View1;
    lowProduct0 = workWord3*workWord2;
    call4 = (void*)Physics45Player64View1;
    workWord2 = lowProduct0 >> 12;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics45Player80View1 = workWord2;
    workWord2 = Physics45Call4E9E4View1(call4);
    workWord3 = Physics45PlayerB0View1;
    lowProduct1 = workWord3*workWord2;
    workWord2 = Physics45Player94View1;
    Physics45Player88View1 = workWord2;
    workWord2 = lowProduct1 >> 12;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics45Player84View1 = workWord2;
    Physics45Call41B64View1();
    workWord2 = Physics45Player144View1;
    workWord2 += 12;
    Physics45Player144View1 = workWord2;
    workWord2 = workWord2 < 193;
    if (!workWord2){
        workWord2 = 192;
        Physics45Player144View1 = workWord2;
    }
    workWord2 = Physics45Player94View1;
    workWord3 = Physics45Player144View1;
    workWord2 -= workWord3;
    Physics45Player94View1 = workWord2;
    workWord2 = workWord2 < -8960;
    clamp19:__asm__ volatile(""::"i"(0x80086C60):"memory");
    if (!workWord2) return;
    workWord2 = -8960;
    Physics45Player94View1 = workWord2;
    return;
state33:
    __asm__ volatile(""::"r"(call4), "r"(stateSelector16):"memory");
    movementPointer17 = &Physics45Player154View1;
    Physics45Call410F8View1(call4, movementPointer17, 0);
    workWord2 = originalFrame.sp1C;
    numeric4 = Physics45Player94View2;
    workWord2 = -workWord2;
    workWord3 = workWord2*5;
    workWord3 <<= 2;
    delta18 = workWord3 >> 7;
    numeric4 >>= 3;
    workWord3 = originalFrame.sp18;
    numeric4 -= 1024;
    originalFrame.sp28 = numeric4;
    workWord2 = workWord3*5;
    workWord2 <<= 2;
    delta19 = workWord2 >> 7;
    if (numeric4 < 0){
        scratchPointer16 = &originalFrame.sp20;
        call4 = scratchPointer16;
        call5 = scratchPointer16;
        __asm__ volatile("":"=r"(movementPointer17):"0"(movementPointer17), "r"(call4), "r"(call5):"memory");
        movementPointer17 -= 340;
        call6 = movementPointer17;
        workWord2 = Physics45Player8CView1;
        workWord3 = Physics45Player90View1;
        workWord2 >>= 3;
        workWord3 >>= 3;
        originalFrame.sp20 = workWord2;
        originalFrame.sp24 = workWord3;
        Physics45Call4F194View2(call4, call5, call6);
        if (!Physics45Call13E38View1(movementPointer17, scratchPointer16, 2)){
            workWord2 = Physics45Player8View1;
            workWord3 = Physics45Data71908View1;
            workWord2 -= workWord3;
            workWord2 >>= 3;
            originalFrame.sp1C = workWord2;
            workWord2 = workWord2 < 11;
            if (!workWord2)originalFrame.sp1C = 10;
            __asm__ volatile("":::"memory");
            workWord2 = originalFrame.sp1C;
            delta18 += workWord2;
        }
    }
    workWord2 = Physics45PlayerF8View1;
    workWord3 = Physics45Player8View1;
    workWord3 = workWord2-workWord3;
    __asm__("":"=r"(workWord3):"0"(workWord3));
    workWord2 = workWord3 < 4096;
    if (workWord2){
        workWord2 = workWord3*3;
        workWord2 <<= 3;
        workWord2 += workWord3;
        workWord2 <<= 5;
        workWord3 = Physics45Player60View2;
        numeric4 = workWord2 >> 12;
        workWord3 = numeric4-workWord3;
        numeric4 = workWord3&4095;
        workWord2 = numeric4 < 2049;
        if (!workWord2){
            numeric4 -= 4096;
            workWord2 = numeric4 < delta18;
        }
        else workWord2 = numeric4 < delta18;
        if (workWord2)delta18 = numeric4;
    }
    call4 = &Physics45Player64View2;
    workWord2 = Physics45Field(call4, int*, 0);
    workWord3 = Physics45Player60View2;
    Physics45PlayerA8View2 = delta19;
    workWord2 += delta19;
    workWord2 &= 4095;
    workWord3 += delta18;
    workWord3 &= 4095;
    Physics45Field(call4, int*, 0) = workWord2;
    workWord2 = workWord3 < 2049;
    Physics45Player60View2 = workWord3;
    if (!workWord2){
        workWord2 = workWord3-4096;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics45Player60View2 = workWord2;
    }
    workWord2 = Physics45Player60View2;
    workWord2 = workWord2 < -800;
    if (workWord2)Physics45Player60View2 = -800;
    workWord2 = Physics45Player60View2;
    workWord2 = workWord2 < 801;
    if (!workWord2)Physics45Player60View2 = 800;
    workWord2 = Physics45Data6FA38View1;
    if (workWord2 >= 0) goto nonnegative33;
    workWord3 = Physics45Player60View2;
    if (workWord3 >= 0) goto positive33;
    numeric4 = Physics45Data67634View1;
    workWord2 = Physics45Data67630View1;
    workWord2 = numeric4-workWord2;
    goto quotient33;
    positive33:if (workWord3 <= 0) goto zero33;
    workWord2 = Physics45Data67638View1;
    numeric4 = Physics45Data67634View1;
    workWord2 -= numeric4;
    quotient33:workWord2 = workWord3*workWord2;
    workWord3 = workWord2/800;
    numeric4 += workWord3;
    Physics45PlayerACView2 = numeric4;
    goto modifier33;
    zero33:workWord2 = Physics45Data67634View1;
    Physics45PlayerACView2 = workWord2;
    modifier33:speed33:call5 = &Physics45Player144View2;
    workWord2 = Physics45PlayerACView2;
    numeric4 = Physics45PlayerB0View2;
    workWord3 = Physics45Field(call5, int*, 0);
    workWord2 -= numeric4;
    workWord2 -= workWord3;
    workWord2 = (workWord2 << 6) >> 6;
    workWord3 += workWord2;
    Physics45Field(call5, int*, 0) = workWord3;
    workWord3 >>= 6;
    numeric4 += workWord3;
    Physics45PlayerB0View2 = numeric4;
    numeric4 = numeric4 < 2048;
    if (numeric4)Physics45PlayerB0View2 = 2048;
    workWord2 = Physics45PlayerB0View2;
    workWord2 = workWord2 < 19201;
    if (!workWord2)Physics45PlayerB0View2 = 19200;
    goto rotation33;
    nonnegative33:numeric4 = Physics45Player8View1;
    responseLimit16 = 0;
    workWord2 = Physics45Call4E4E4View1(numeric4);
    workWord3 = Physics45Player148View1;
    __asm__ volatile(""::"r"(workWord3), "r"(workWord2):"memory");
    numeric4 = workWord2;
    __asm__("":"=r"(numeric4):"0"(numeric4));
    Physics45PlayerACView2 = numeric4;
    numeric5 = workWord3;
    if (!workWord3) goto zeroCounter33;
    workWord2 = 0x60000;
    Physics45Player130View1 = workWord2;
    workWord2 = numeric5-1;
    Physics45Player148View1 = workWord2;
    workWord2 <<= 16;
    if (workWord2 > 0) goto positiveCounter33;
    workWord3 = Physics45PlayerB0View2;
    workWord2 = workWord3-numeric4;
    workWord2 = workWord2 < 192;
    if (workWord2){
        workWord2 = numeric4+8192;
        Physics45PlayerB0View2 = workWord2;
        Physics45Player148View1 = 0;
        goto counterClamp33;
    }
    workWord2 = workWord3-192;
    Physics45PlayerB0View2 = workWord2;
    workWord2 = 1;
    Physics45Player148View1 = workWord2;
    goto counterClamp33;
    positiveCounter33:workWord2 = numeric4+8192;
    Physics45PlayerB0View2 = workWord2;
    responseLimit16 = 96;
    goto counterClamp33;
    zeroCounter33:Physics45PlayerB0View2 = numeric4;
    __asm__ volatile("":"=r"(responseLimit16):"0"(responseLimit16):"$3", "memory");
    Physics45Player130View1 = 0;
    counterClamp33:globalPointer = &Physics45PlayerB0View2;
    workWord2 = Physics45Field(globalPointer, int*, 0);
    workWord2 = workWord2 < 22785;
    if (!workWord2)Physics45Field(globalPointer, int*, 0) = 22784;
    workWord2 = Physics45Field(globalPointer, int*, 0);
    workWord2 = workWord2 < 2048;
    if (workWord2)Physics45Field(globalPointer, int*, 0) = 2048;
    numeric5 = Physics45Player14CView1;
    workWord3 = Physics45Player150View1;
    workWord2 = responseLimit16-numeric5;
    workWord2 <<= 4;
    numeric4 = workWord3 << 5;
    workWord2 -= numeric4;
    workWord2 >>= 6;
    workWord3 += workWord2;
    Physics45Player150View1 = workWord3;
    workWord3 >>= 4;
    numeric5 += workWord3;
    Physics45Player14CView1 = numeric5;
    if (numeric5 < 0)Physics45Player14CView1 = 0;
    workWord2 = Physics45Player14CView1;
    workWord2 = workWord2 < 97;
    if (!workWord2)Physics45Player14CView1 = 96;
    rotation33:workWord2 = Physics45Player148View1;
    workWord2 = workWord2 < 2;
    if (workWord2) goto spring33;
    workWord3 = Physics45Player14AView1;
    __asm__("":"=r"(workWord3):"0"(workWord3));
    workWord2 = workWord3*3;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    workWord3 = Physics45Player5CView1;
    workWord2 <<= 11;
    Physics45Player154View1 = workWord2;
    workWord2 >>= 6;
    workWord3 += workWord2;
    workWord3 &= 4095;
    workWord2 = workWord3 < 2049;
    Physics45Player5CView1 = workWord3;
    if (workWord2) goto rotationDone33;
    workWord2 = workWord3-4096;
    goto storeAngle33;
    spring33:workWord2 = Physics45Call4EA2CView2(Physics45Player60View2);
    workWord2 <<= 5;
    workWord2 = -workWord2;
    springProduct33 = delta19*workWord2;
    workWord3 = Physics45Player154View1;
    numeric5 = Physics45Player5CView1;
    workWord2 = (workWord3 << 4) >> 6;
    numeric4 = springProduct33 >> 12;
    numeric4 -= workWord2;
    workWord2 = (numeric5 << 6) >> 6;
    numeric4 -= workWord2;
    workWord3 += numeric4;
    Physics45Player154View1 = workWord3;
    workWord3 >>= 6;
    numeric5 += workWord3;
    numeric5 &= 4095;
    workWord2 = numeric5 < 2049;
    Physics45Player5CView1 = numeric5;
    if (workWord2) goto rotationDone33;
    workWord2 = numeric5-4096;
    storeAngle33:Physics45Player5CView1 = workWord2;
    rotationDone33:Physics45Call41848View2();
    call5 = &Physics45Player4CView2;
    numeric4 = Physics45Field(call5, int*, 0);
    if (!numeric4) goto noInput45;
    workWord2 = Physics45Player8View1;
    workWord3 = Physics45PlayerF8View1;
    workWord2 = workWord2 < workWord3;
    if (!workWord2) goto zeroActive45;
    workWord2 = 1;
    if (numeric4 == workWord2) goto increment45;
    goto decline45;
    state43:workWord3 = Physics45Player4CView1;
    workWord2 = 1;
    if (workWord3 != workWord2) goto continue43;
    block_154:Physics45Call4F168View2(playerVector54+44);
    Physics45Call4F168View2(playerVector54+56);
    return;
    continue43:workWord2 = 7;
    workWord3 = Physics45Data6E044View2;
    if (workWord3 == workWord2) {
        Physics45Field(&Physics45Player0View1, int *, 0xB0) = 0;
    }
    else {
        Physics45Call40D10View2(0x980);
        raw21_var_v0_2 = Physics45Call41580View2(0x5A, 0x10);
        if (raw21_var_v0_2 < 0) {
            raw21_var_v0_2 = -raw21_var_v0_2;
        }
        if (raw21_var_v0_2 >= 0x201) {
            Physics45Field(&Physics45Player0View1, int *, 0xAC) = 0;
        }
        raw21_var_a0_2 = 0xC0;
        if (Physics45Field(&Physics45Player0View1, int *, 0xB0) >= 0xC81) {
            raw21_var_a0_2 = 0;
            raw21_var_a1_4 = 0xC0;
        }
        else {
            raw21_var_a1_4 = 0x40;
        }
        Physics45Call417FCView2(raw21_var_a0_2, raw21_var_a1_4);
    }
    raw21_temp_s0_11 = &Physics45Player0View1 + 0xB0;
    if (Physics45Field(&Physics45Player0View1, int *, 0xB0) != 0) {
        Physics45Call41848View3();
        Physics45Call41B64View3();
        Physics45Field(&Physics45Player0View1, int *, 0x94) = 0;
    }
    else {
        Physics45Call4F168View2(raw21_temp_s0_11 - 0x30);
        Physics45Call4F168View2(raw21_temp_s0_11 - 0x24);
    }
    if (Physics45SpawnParticleView1 != 0) {
        raw21_temp_s4 = &Physics45Player0View1 + 0x28;
        if (Physics45Field(&Physics45Player0View1, int *, 0x28) < 0) {
            if ((Physics45Field(&Physics45Player0View1, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics45Data6C640View1 & 1)) {
                Physics45Call4F178View1(&originalFrame.sp30, raw21_temp_s4 - 0x28);
                originalFrame.sp44 = 0x40;
                originalFrame.sp48 = 0;
                originalFrame.sp40 = (int) Physics45Field(&Physics45Player0View1, int *, 0xB0) >> 5;
                if (savedSlotIndex != 0) {
                    originalFrame.sp44 = -0x40;
                }
                raw21_temp_s2_3 = raw21_temp_s4 + 8;
                Physics45Call4ED6CView1(raw21_temp_s2_3, &originalFrame.sp40, &originalFrame.sp50);
                Physics45Call4F194View3(&originalFrame.sp30, &originalFrame.sp30, &originalFrame.sp50);
                originalFrame.sp40 = 0;
                originalFrame.sp38 = -Physics45Field(&Physics45Player0View1, int *, 0x28);
                Physics45Call4ED6CView1(raw21_temp_s2_3, &originalFrame.sp40, &originalFrame.sp40);
                Physics45Call4F110View1(&originalFrame.sp40, 3);
                Physics45SpawnParticleView1(1, 0x2A, &originalFrame.sp30, &originalFrame.sp40);
                if (!(Physics45CallRandView1() & 0x1F)) {
                    Physics45SpawnParticleView1(1, 0x29, &originalFrame.sp30, 0);
                }
            }
            else {
                raw21_temp_s1_7 = &Physics45Player0View1 + 0xB0;
                if ((Physics45Field(&Physics45Player0View1, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics45Data6C640View1 & 7) && !(Physics45CallRandView1() & 3)) {
                    originalFrame.sp60 = 0x80;
                    __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                    originalFrame.sp64 = 0;
                    originalFrame.sp68 = 0;
                    Physics45Call4ED6CView1(raw21_temp_s1_7 - 0x80, &originalFrame.sp60, &originalFrame.sp60);
                    Physics45Call4F194View3(&originalFrame.sp60, &originalFrame.sp60, raw21_temp_s1_7 - 0xB0);
                    originalFrame.sp68 = -Physics45Field(&Physics45Player0View1, int *, 0x28);
                    Physics45SpawnParticleView1(1, 0x2B, &originalFrame.sp60, (int *)1);
                }
            }
        }
    }
    raw21_temp_a1_4 = Physics45Field(&Physics45Player0View1, int *, 0x144) - ((int) ((Physics45Field(&Physics45Player0View1, int *, 0x148) * 2) + (Physics45Field(&Physics45Player0View1, int *, 0x144) * 0x14)) >> 8);
    raw21_temp_a0_7 = Physics45Field(&Physics45Player0View1, int *, 0x148) + raw21_temp_a1_4;
    Physics45Field(&Physics45Player0View1, int *, 0x144) = raw21_temp_a1_4;
    Physics45Field(&Physics45Player0View1, int *, 0x148) = raw21_temp_a0_7;
    if (raw21_temp_a0_7 >= 0x5901) {
        Physics45Field(&Physics45Player0View1, int *, 0x148) = 0x5900;
    }
    if (Physics45Field(&Physics45Player0View1, int *, 0x148) < -0x5900) {
        Physics45Field(&Physics45Player0View1, int *, 0x148) = -0x5900;
        return;
    }
    return;
    state55:{
        register int numeric4 __asm__("$4");
        register int numeric5 __asm__("$5");
        Physics45Call4F168View1(playerVector54+44);
        Physics45Call4F168View1(playerVector54+56);
        numeric5 = Physics45Player148View2;
        numeric4 = Physics45Player144View1;
        workWord3 = numeric5 << 1;
        workWord2 = numeric4*5;
        workWord2 <<= 2;
        workWord3 += workWord2;
        workWord3 >>= 8;
        numeric4 -= workWord3;
        numeric5 += numeric4;
        Physics45Player144View1 = numeric4;
        Physics45Player148View2 = numeric5;
        return;
    }
    state61:Physics45Call40F48View1(&originalFrame.sp50, 1);
    workWord3 = originalFrame.sp50;
    workWord2 = workWord3*25;
    call4 = (void*)(workWord2 >> 7);
    if (!call4) goto zeroSteer61;
    if ((int)call4 >= 0) goto positive61;
    workWord2 = Physics45PlayerA8View1;
    if (workWord2 <= 0) goto approach61;
    goto zeroSteer61;
    positive61:workWord2 = Physics45PlayerA8View1;
    if (workWord2 >= 0) goto approach61;
    zeroSteer61:Physics45PlayerA8View1 = 0;
    approach61:call5 = &Physics45PlayerA8View1;
    workWord3 = Physics45Field(call5, int*, 0);
    workWord2 = workWord3 < (int)call4;
    if (workWord2){
        workWord2 = workWord3+3;
        Physics45Field(call5, int*, 0) = workWord2;
        workWord2 = (int)call4 < workWord2;
        goto clamp61;
    }
    workWord2 = workWord3-3;
    Physics45Field(call5, int*, 0) = workWord2;
    workWord2 = workWord2 < (int)call4;
    clamp61:if (workWord2)Physics45Field(call5, int*, 0) = (int)call4;
    call4 = (void*)Physics45PlayerA8View1;
    Physics45Call41404View1(call4);
    workWord3 = Physics45Player60View1;
    workWord2 = workWord3 < 2049;
    if (!workWord2){
        workWord2 = workWord3-4096;
        Physics45Player60View1 = workWord2;
        __asm__ volatile("":::"memory");
        workWord3 = Physics45Player60View1;
        __asm__ volatile("":::"memory");
    }
    if (workWord3 >= 0) goto nonnegative61;
    call4 = (void*)Physics45Data67640View1;
    workWord2 = Physics45Data6763CView1;
    workWord2 = (int)call4-workWord2;
    goto quotient61;
    nonnegative61:if (workWord3 <= 0) goto zero61;
    workWord2 = Physics45Data67644View1;
    call4 = (void*)Physics45Data67640View1;
    workWord2 -= (int)call4;
    quotient61:workWord2 = workWord3*workWord2;
    workWord3 = workWord2/352;
    call4 += workWord3;
    Physics45PlayerACView1 = (int)call4;
    goto update61;
    zero61:workWord2 = Physics45Data67640View1;
    Physics45PlayerACView1 = workWord2;
    update61:Physics45Call417FCView1(576, 384);
    Physics45Call41848View1();
    call6 = &Physics45PlayerFCView1;
    workWord2 = Physics45Field(call6, unsigned char*, 0);
    if (workWord2) goto field94FromA0;
    workWord2 = Physics45PlayerB8View1;
    call4 = call6-112;
    if (!workWord2) goto vectorCommit61;
    field94FromA0:workWord2 = Physics45PlayerA0View1;
    workWord2 -= 192;
    Physics45Player94View1 = workWord2;
    return;
    vectorCommit61:call5 = call6-124;
    Physics45Call4F194View1(call4, call5, call6-20);
    return;
state160:
    __asm__ volatile(""::"r"(call4), "r"(stateSelector16):"memory");
    movementPointer17 = &Physics45Player154View1;
    Physics45Call410F8View1(call4, movementPointer17, 0);
    workWord2 = originalFrame.sp74;
    numeric4 = Physics45Player94View2;
    workWord2 = -workWord2;
    workWord3 = workWord2*5;
    workWord3 <<= 2;
    delta18 = workWord3 >> 7;
    numeric4 >>= 2;
    workWord3 = originalFrame.sp70;
    numeric4 -= 1024;
    originalFrame.sp80 = numeric4;
    workWord2 = workWord3*5;
    workWord2 <<= 2;
    delta19 = workWord2 >> 7;
    if (numeric4 < 0){
        scratchPointer16 = &originalFrame.sp78;
        call4 = scratchPointer16;
        call5 = scratchPointer16;
        __asm__ volatile("":"=r"(movementPointer17):"0"(movementPointer17), "r"(call4), "r"(call5):"memory");
        movementPointer17 -= 340;
        call6 = movementPointer17;
        workWord2 = Physics45Player8CView1;
        workWord3 = Physics45Player90View1;
        workWord2 >>= 2;
        workWord3 >>= 2;
        originalFrame.sp78 = workWord2;
        originalFrame.sp7C = workWord3;
        Physics45Call4F194View2(call4, call5, call6);
        if (!Physics45Call13E38View1(movementPointer17, scratchPointer16, 2)){
            workWord2 = Physics45Player8View1;
            workWord3 = Physics45Data71908View1;
            workWord2 -= workWord3;
            workWord2 >>= 3;
            originalFrame.sp74 = workWord2;
            workWord2 = workWord2 < 6;
            if (!workWord2)originalFrame.sp74 = 5;
            __asm__ volatile("":::"memory");
            workWord3 = originalFrame.sp74;
            workWord2 = delta18 < workWord3;
            if (workWord2)delta18 = workWord3;
        }
    }
    workWord2 = Physics45PlayerF8View1;
    workWord3 = Physics45Player8View1;
    workWord3 = workWord2-workWord3;
    __asm__("":"=r"(workWord3):"0"(workWord3));
    workWord2 = workWord3 < 4096;
    if (workWord2){
        workWord2 = workWord3*3;
        workWord2 <<= 3;
        workWord2 += workWord3;
        workWord2 <<= 5;
        workWord3 = Physics45Player60View2;
        numeric4 = workWord2 >> 12;
        workWord3 = numeric4-workWord3;
        numeric4 = workWord3&4095;
        workWord2 = numeric4 < 2049;
        if (!workWord2){
            numeric4 -= 4096;
            workWord2 = numeric4 < delta18;
        }
        else workWord2 = numeric4 < delta18;
        if (workWord2)delta18 = numeric4;
    }
    call4 = &Physics45Player64View2;
    workWord2 = Physics45Field(call4, int*, 0);
    workWord3 = Physics45Player60View2;
    Physics45PlayerA8View2 = delta19;
    workWord2 += delta19;
    workWord2 &= 4095;
    workWord3 += delta18;
    workWord3 &= 4095;
    Physics45Field(call4, int*, 0) = workWord2;
    workWord2 = workWord3 < 2049;
    Physics45Player60View2 = workWord3;
    if (!workWord2){
        workWord2 = workWord3-4096;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics45Player60View2 = workWord2;
    }
    workWord2 = Physics45Player60View2;
    workWord2 = workWord2 < -800;
    if (workWord2)Physics45Player60View2 = -800;
    workWord2 = Physics45Player60View2;
    workWord2 = workWord2 < 801;
    if (!workWord2)Physics45Player60View2 = 800;
    numeric4 = Physics45Player8View1;
    responseLimit16 = 0;
    workWord2 = Physics45Call4E4E4View1(numeric4);
    workWord3 = Physics45Player148View1;
    __asm__ volatile(""::"r"(workWord3), "r"(workWord2):"memory");
    numeric4 = workWord2;
    __asm__("":"=r"(numeric4):"0"(numeric4));
    Physics45PlayerACView2 = numeric4;
    numeric5 = workWord3;
    if (!workWord3) goto zeroCounter160;
    workWord2 = 0x60000;
    Physics45Player130View1 = workWord2;
    workWord2 = numeric5-1;
    Physics45Player148View1 = workWord2;
    workWord2 <<= 16;
    if (workWord2 > 0) goto positiveCounter160;
    workWord3 = Physics45PlayerB0View2;
    workWord2 = workWord3-numeric4;
    workWord2 = workWord2 < 192;
    if (workWord2){
        workWord2 = numeric4+8192;
        Physics45PlayerB0View2 = workWord2;
        Physics45Player148View1 = 0;
        goto counterClamp160;
    }
    workWord2 = workWord3-192;
    Physics45PlayerB0View2 = workWord2;
    workWord2 = 1;
    Physics45Player148View1 = workWord2;
    goto counterClamp160;
    positiveCounter160:workWord2 = numeric4+8192;
    Physics45PlayerB0View2 = workWord2;
    responseLimit16 = 96;
    goto counterClamp160;
    zeroCounter160:Physics45PlayerB0View2 = numeric4;
    __asm__ volatile("":"=r"(responseLimit16):"0"(responseLimit16):"$3", "memory");
    Physics45Player130View1 = 0;
    counterClamp160:globalPointer = &Physics45PlayerB0View2;
    workWord2 = Physics45Field(globalPointer, int*, 0);
    workWord2 = workWord2 < 22785;
    if (!workWord2)Physics45Field(globalPointer, int*, 0) = 22784;
    workWord2 = Physics45Field(globalPointer, int*, 0);
    workWord2 = workWord2 < 2048;
    if (workWord2)Physics45Field(globalPointer, int*, 0) = 2048;
    numeric5 = Physics45Player14CView1;
    workWord3 = Physics45Player150View1;
    workWord2 = responseLimit16-numeric5;
    workWord2 <<= 4;
    numeric4 = workWord3 << 5;
    workWord2 -= numeric4;
    workWord2 >>= 6;
    workWord3 += workWord2;
    Physics45Player150View1 = workWord3;
    workWord3 >>= 4;
    numeric5 += workWord3;
    Physics45Player14CView1 = numeric5;
    if (numeric5 < 0)Physics45Player14CView1 = 0;
    workWord2 = Physics45Player14CView1;
    workWord2 = workWord2 < 97;
    if (!workWord2)Physics45Player14CView1 = 96;
    rotation160:workWord2 = Physics45Player148View1;
    workWord2 = workWord2 < 2;
    if (workWord2) goto spring160;
    workWord3 = Physics45Player14AView1;
    __asm__("":"=r"(workWord3):"0"(workWord3));
    workWord2 = workWord3*3;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    workWord3 = Physics45Player5CView1;
    workWord2 <<= 11;
    Physics45Player154View1 = workWord2;
    workWord2 >>= 6;
    workWord3 += workWord2;
    workWord3 &= 4095;
    workWord2 = workWord3 < 2049;
    Physics45Player5CView1 = workWord3;
    if (workWord2) goto rotationDone160;
    workWord2 = workWord3-4096;
    goto storeAngle160;
    spring160:workWord2 = Physics45Call4EA2CView2(Physics45Player60View2);
    workWord2 <<= 5;
    workWord2 = -workWord2;
    springProduct160 = delta19*workWord2;
    workWord3 = Physics45Player154View1;
    numeric5 = Physics45Player5CView1;
    workWord2 = (workWord3 << 4) >> 6;
    numeric4 = springProduct160 >> 12;
    numeric4 -= workWord2;
    workWord2 = (numeric5 << 6) >> 6;
    numeric4 -= workWord2;
    workWord3 += numeric4;
    Physics45Player154View1 = workWord3;
    workWord3 >>= 6;
    numeric5 += workWord3;
    numeric5 &= 4095;
    workWord2 = numeric5 < 2049;
    Physics45Player5CView1 = numeric5;
    if (workWord2) goto rotationDone160;
    workWord2 = numeric5-4096;
    storeAngle160:Physics45Player5CView1 = workWord2;
    rotationDone160:Physics45Call41848View2();
    call5 = &Physics45Player4CView2;
    numeric4 = Physics45Field(call5, int*, 0);
    if (numeric4) goto active45;
    noInput45:workWord2 = (int)Physics45Data6C570View1;
    workWord2 = Physics45Field((void*)workWord2, int*, 4)&64;
    if (!workWord2) goto end45;
    workWord2 = Physics45PlayerF8View1;
    workWord3 = Physics45Player8View1;
    workWord2 -= 512;
    workWord3 = workWord3 < workWord2;
    if (!workWord3) goto end45;
    workWord3 = Physics45Player48View1;
    workWord2 = 33;
    if (workWord3 != workWord2) goto end45;
    workWord2 = 1;
    Physics45Field(call5, int*, 0) = workWord2;
    __asm__ volatile("":::"$4", "memory");
    Physics45Player160View1 = 0;
    goto end45;
    active45:workWord2 = Physics45Player8View1;
    workWord3 = Physics45PlayerF8View1;
    workWord2 = workWord2 < workWord3;
    if (workWord2){
        workWord2 = 1;
        goto activeRemainder45;
    }
    workWord2 = 1;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    zeroActive45:Physics45Field(call5, int*, 0) = 0;
    goto end45;
    activeRemainder45:if (numeric4 != workWord2) goto decline45;
    increment45:workWord2 = Physics45Player160View1;
    workWord2 += 512;
    Physics45Player160View1 = workWord2;
    workWord2 = workWord2 < 6144;
    if (!workWord2){
        workWord2 = 6144;
        Physics45Player160View1 = workWord2;
        workWord2 = 2;
        Physics45Field(call5, int*, 0) = workWord2;
    }
    goto add88;
    decline45:workWord2 = Physics45Player160View1;
    workWord2 -= 256;
    Physics45Player160View1 = workWord2;
    if (workWord2 <= 0){
        Physics45Player160View1 = 0;
        Physics45Field(call5, int*, 0) = 0;
    }
    add88:{
        register void *pointer2 __asm__("$2");
        pointer2 = &Physics45Player88View2;
        workWord3 = Physics45Field(pointer2, int*, 0);
        numeric4 = Physics45Player160View1;
        workWord3 += numeric4;
        Physics45Field(pointer2, int*, 0) = workWord3;
    }
    end45:Physics45Call41B64View2();
    return;
}
#undef Physics45Field


/* AI generated; not human reviewed. SCUS-94467 80087D60..800882C4.
 * Reuses verified level15_800882B8 particle arithmetic and typed helpers;
 * original level45 supplies dispatch, two stack vectors and producer ordering.
 * Byte-addressed sources preserve offsets; scalar samples remain signed words.
 * Empty constraints retain original register/memory lifetimes, emitting no code.
 * Helper meanings, source units, sound descriptors and cadence remain unresolved.
 * Acceptance: all original linked words and every complete retail hash.
 */
extern unsigned char Callback45CountBase[] __asm__("D_80070328+0x148");
extern int Callback45HeightF4 __asm__("D_80070328+0xF4");
extern Spyro Callback45Player __asm__("D_80070328");
int Callback45Call80037058(int x, int y) __asm__("func_80037058");
int Callback45Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback45Call80041930(void) __asm__("func_80041930");
void Callback45Call80041AE8(void) __asm__("func_80041AE8");
void Callback45Call80041C20(void) __asm__("func_80041C20");
void Callback45Call80042A44(void) __asm__("func_80042A44");
void Callback45Call80043728(void) __asm__("func_80043728");
int Callback45Call800438F4(void) __asm__("func_800438F4");
void Callback45Call80043A38(int scale) __asm__("func_80043A38");
void Callback45Call80049590(void) __asm__("func_80049590");
void Callback45Call8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback45Word8006E344 __asm__("D_8006E344");
extern int Callback45Word8006E52C __asm__("D_8006E52C");
extern int Callback45Word8006E530 __asm__("D_8006E530");
extern int Callback45Word8006E538 __asm__("D_8006E538");
void func_level_45_80087D60(void) {
    struct {Vector3D first; int reserved1C; Vector3D second; int reserved2C; int reserved[4];} local;
    register unsigned char* firstSource __asm__("$18");
    register unsigned char* secondSource __asm__("$19");
    int clampValue, computedValue;
    register int iteration __asm__("$16");
    register int firstLimit __asm__("$17");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register Vector3D* secondVector __asm__("$17");
    register unsigned char* countBase __asm__("$5");
    register int* zWord __asm__("$19");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
    switch (Callback45Player.animationState) {
        case 20:
            if (Callback45Call800438F4() == 0) {
                Callback45Call80043728();
            }
            Callback45Call80041C20();
            Callback45Player.unk9a = 0;
            Callback45Call80042A44();
            goto clearSharedValue;
        case 0x35:
        case 0x36:
            Callback45Call80041C20();
            Callback45Call80042A44();
            goto clearSharedValue;
        case 25:
            Callback45Call80041C20();
            Callback45Call80042A44();
            Callback45Call80041930();
            Callback45Call80049590();
            if ((Callback45Player.movementState == MOVEMENT_STATE_SUPERCHARGE) && (SpawnParticle != 0)) {
                SpawnParticle(1, 9, 0, 0);
            }
            if ((Callback45Player.unk7a[3].z < 0) && (Callback45Player.animationStateFrames >= 4)) {
                Callback45Player.unk5 = 1;
            } else if ((Callback45Player.unk5 == 0) && !(Callback45Word8006E538 & 0x40)) {
                Callback45Player.unk5 = 2;
            }
            goto clearSharedValue;
        case 0x21:
        case 0x22:
        case 0x23:
            Callback45Call80041C20();
            Callback45Call80042A44();
            Callback45Call80041930();
            if (SpawnParticle != 0) {
                countBase=Callback45CountBase;
                __asm__("" : "=r"(countBase) : "0"(countBase));
                if (*(short*)countBase == 0) goto clearSharedValue;
                firstLimit = 1;
                if (*(short*)countBase >= 2) {
                    firstLimit = 2;
                }
                iteration = 0;
                if (firstLimit != 0) {
                    firstSource = countBase - 0xB0;
                    do {
                        func_8004F178(&local.first, (Vector3D *) firstSource);
                        Callback45Call8004F110(&local.first, 7);
                        iteration += 1;
                        sample=rand();
                        component=local.first.x;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.first.x=component;
                        sample=rand();
                        component=local.first.y;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.first.y=component;
                        sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=firstSource - 0x98;
                        vector=&local.first;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "$8", "memory");
                        sample &=254;
                        __asm__("" : "=r"(sample) : "0"(sample) : "$3", "$8", "memory");
                        component=local.first.z;
                        __asm__("" : "=r"(component) : "0"(component) : "$8", "memory");
                        particles=SpawnParticle;
                        __asm__("" : "=r"(particles), "=r"(component) : "0"(particles), "1"(component));
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.first.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < firstLimit);
                }
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
        case 0x37:
        Callback45Call80041C20();
        Callback45Call80042A44();
        Callback45Call80041AE8();
        if ((unsigned char) Callback45Player.unk10[4] != 0) {
            computedValue = -Callback45Player.unk9ha[4] - Callback45Call80037058(Callback45Player.position.x, Callback45Player.position.y);
            Callback45Player.unk4[0] = computedValue;
            Callback45Player.position.z = (Callback45Player.unk4a - computedValue) - ((int) Callback45Player.union144.a.unk13cc >> 6);
        }

            return;
        case 0x3D:
            Callback45Call80041C20();
            Callback45Call80042A44();
            Callback45Call80043A38(0xC00);
            Callback45Call80049590();
            if (SpawnParticle != 0) {
                SpawnParticle(1, 9, 0, 0);
            }
            Callback45Word8006E530 = 0x78;
            Callback45Player.unk4[0] = 0;
            Callback45Word8006E52C = 4;
            if ((Callback45Word8006E344 == 0) && (Callback45Call8003BF6C((int) D_8006C654->supercharge, Callback45Player.unk22[2]) == 0)) {
                Callback45Player.unk22[2] = PlaySound((int) D_8006C654->supercharge, 0, 4);
                Callback45Player.unk22[3] = (int) D_8006C654->supercharge;
            }

            return;
        case 0xA0:
        case 0xA1:
        case 0xA2:
        case 0xA3:
                Callback45Call80041C20();
                Callback45Call80042A44();
                zWord=&Callback45Player.position.z;
                __asm__("" : "=r"(zWord) : "0"(zWord));
                clampValue = Callback45HeightF4 + Callback45Player.unk4a;
                if (*zWord < clampValue) {
                    *zWord = clampValue;
                }
                Callback45Call80041930();
                if ((SpawnParticle != 0) && (Callback45Player.union144.b.unk148 != 0)) {
                    secondLimit = 1;
                    if (Callback45Player.union144.b.unk148 >= 2) {
                        secondLimit = 2;
                    }
                    iteration = 0;
                    if (secondLimit != 0) {
                        secondVector=&local.second;
                        __asm__("" : "=r"(secondVector), "=r"(zWord) : "0"(secondVector), "1"(zWord));
                        secondSource = (unsigned char*)zWord + 0x90;
                        do {
                            func_8004F178(secondVector, (Vector3D *) secondSource);
                            Callback45Call8004F110(secondVector, 7);
                            iteration += 1;
                            sample=rand();
                            component=local.second.x;
                            sample &= 254;
                            component -=127;
                            component +=sample;
                            __asm__("" : "=r"(component) : "0"(component));
                            local.second.x=component;
                            sample=rand();
                            component=local.second.y;
                            sample &= 254;
                            component -=127;
                            component +=sample;
                            __asm__("" : "=r"(component) : "0"(component));
                            local.second.y=component;
                            sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=secondSource - 0x98;
                        vector=secondVector;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "$8", "memory");
                        sample &=254;
                        __asm__("" : "=r"(sample) : "0"(sample) : "$3", "$8", "memory");
                        component=local.second.z;
                        __asm__("" : "=r"(component) : "0"(component) : "$8", "memory");
                        particles=SpawnParticle;
                        __asm__("" : "=r"(particles), "=r"(component) : "0"(particles), "1"(component));
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                        } while (iteration < secondLimit);
                    }
                }
            goto clearSharedValue;

        default:return;
    }
clearSharedValue:
    Callback45Player.unk4[0]=0;
}


#define LEVEL_ID 45
#define PlaySpyroSounds_level_45 func_level_45_800882C8
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_45_800883D0(int index) {
    register int* state __asm__("$5");
    register int value __asm__("$3");
    register unsigned char* base __asm__("$2");
    register unsigned int offset __asm__("$4");
    offset = index * 16;
    __asm__("" : "=r"(offset) : "0"(offset) : "$2");
    base = D_8006E548;
    __asm__("" : "=r"(base) : "0"(base), "r"(offset) : "$5");
    state = &spyro.animationState;
    value = *state;
    __asm__("" : "=r"(value) : "0"(value) : "memory");
    offset = offset + (unsigned int)base;
    __asm__("" : "=r"(offset) : "0"(offset), "r"(value));
    D_8006C570 = (unsigned char*)offset;
    __asm__("" : : "r"(value) : "$2", "memory");
    if (value < 0x2D) {
        if (value >= 0x2B) goto vector;
        if (value == 0x19) goto other;
        if (value >= 0x1A) return;
        if (value == 0x14) goto vector;
        return;
    } else {
        if (value == 0x3D) goto vector;
        if (value >= 0x3E) return;
        if (value >= 0x38) return;
        if (value < 0x35) return;
    }
vector:
    __asm__("" : : "r"(value));
    func_80043ABC(&spyro.unk9e);
    return;
other:
    func_80043E00((Vector3D*)((char*)state + 0x44));
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80088484.
 * Reuses verified25/35 fly/surface/charge blocks. Original45 selector14
 * helper3636C(1,3) result stored144, zero148; A0..A3 shares fly entry but
 * retains pointers via original selector<A0 tail. Surface vector stack10.
 * Byte offsets, original stores/widths and sound selector22/7 retained.
 * Clamp7FF/800/4B00/4B01 ->800/800/4B00/4B00 before subsequent helpers.
 * Empty constraints emit no instructions. Every original code/internal jump/
 * owned word, strict full TU and every original EXE/overlay hash required.
 * Helpers, units, audio semantics, cadence and live parity remain open.
 */
int Call45_8003636C(int,int) __asm__("func_8003636C");
extern Spyro Transition45Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw45Word __asm__("D_80070328+0x50");
extern unsigned char Raw45State[] __asm__("D_80070328+0x50");
extern unsigned char Raw45Union[] __asm__("D_80070328+0x144");
extern int Raw45Spit __asm__("D_80070328+0x170");
void Call45_8004F168(Vector3D*) __asm__("func_8004F168");
int Call45_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call45A358(Vector3D*,int) __asm__("func_8001A358");
void Call45_800441F0(void) __asm__("func_800441F0");
void Call45_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_45_80088484(int arg0) {
    Vector3D surfaceVector;
    int vectorLength,surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");
    switch(arg0){
    case 0x14:
        Transition45Player.movementState=0;
        Transition45Player.unk5=0;
        Call45_800441F0();
        Transition45Player.grounded=1;
        Transition45Player.union144.a.unk13cb=Call45_8003636C(1,3);
        Transition45Player.union144.a.unk13cc=0;
        goto clearPointers;

    case 0x35:
        __asm__ volatile("" : : : "memory");
        goto standEntry;
    case 0x36:
standEntry:
        Transition45Player.movementState = MOVEMENT_STATE_STAND;
        Transition45Player.unk5 = 0;
        Call45_800441F0();
        Transition45Player.grounded = 1;
        goto clearPointers;

    case 0x19:
        soundZero=0;
        __asm__("" : "=r"(soundZero) : "0"(soundZero));
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition45Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition45Player.unk13a[0] = 0x60000;
        Transition45Player.unk5 = 0;
        Transition45Player.union144.a.unk13cb = 0;
        Transition45Player.grounded = 0;
        Transition45Player.unk15b = 1;
        soundSelector = soundTable[0x22];
playSharedSound:
        PlaySound((int) soundSelector, (Moby*)soundZero, 0);
        goto clearPointers;
    case 0xA0:case 0xA1:case 0xA2:case 0xA3:
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$17")=(unsigned char*)&Raw45Word;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition45Player.unk5=0;
            Call45_8004F168((Vector3D*)(flyState+0x104));
            Transition45Player.union144.a.unk13db.y=0;
            vectorLength=Call45_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition45Player.unk8[0]=vectorLength;
            if(vectorLength<0x800)Transition45Player.unk8[0]=0x800;
            if(Transition45Player.unk8[0]>=0x4B01)Transition45Player.unk8[0]=0x4B00;
            Transition45Player.union144.a.unk13cb=0;
            Transition45Player.union144.b.unk148=0;
            Transition45Player.union144.a.unk13ce.x=0;
            Transition45Player.union144.a.unk13ce.y=0;
            Transition45Player.grounded=0;
            Transition45Player.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2B:case 0x2C:{

        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw45Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw45Union;
            *(int*)unionPointer=(-Transition45Player.unk7a[2].z)>>2;
            if(Raw45Word!=8){Transition45Player.union144.a.unk13cc=0x5900;Raw45Word=10;}
            Transition45Player.unk5=0;
            Transition45Player.unk8[0]=Call45_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition45Player.grounded=1;
            Transition45Player.unk15b=1;
            func_8004F178(&surfaceVector,(Vector3D*)(unionPointer-0x144));
            surfaceVector.z+=0x400;
            surfaceResult=Call45A358(&surfaceVector,0x800);
            surfaceVector.z=surfaceResult;
            if(surfaceResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&surfaceVector,0);SpawnParticle(6,0x2E,&surfaceVector,0);}
        }
        }
        goto clearPointers;

    }

    case 0x37:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw45Word=originalZ;
        __asm__ volatile("" : : : "memory");
        originalZ=Transition45Player.unk7a[2].z;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        {register int flagValue __asm__("$3")=1;
        __asm__("" : "=r"(flagValue) : "0"(flagValue));
        Transition45Player.unk15b=flagValue;
        __asm__ volatile("" : : : "memory");}
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition45Player.union144.a.unk13cc = 0;
        Transition45Player.unk5 = 0;
        Transition45Player.grounded = 0;
        __asm__ volatile("" : "=r"(originalZ) : "0"(originalZ) : "memory");
        Transition45Player.union144.a.unk13cb = -originalZ >> 2;
        soundSelector = soundTable[7];
        soundZero=0;
        goto playSharedSound;
    case 0x3D:
        stateBase=Raw45State;
        *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
        Transition45Player.unk5 = 0;
        Transition45Player.unk13a[0] = 0x60000;
        Transition45Player.unk8[0] = Call45_8004EDE8((Vector3D *) (stateBase + 0x48), 0);
        Transition45Player.horizontalSpeed = 0x1E80;
        Call45_80043A38(0xC00);
        Transition45Player.grounded = 1;
        if ((Transition45Player.unk13f[0] != 0) || (Transition45Player.spitState != 0) || (Transition45Player.unk17t != 6)) {
            spitWord=&Raw45Spit;
            if (((unsigned) (*spitWord - 3) < 2U) || (*spitWord == 5)) {
                *spitWord = 5;
            } else {
                *spitWord = 0;
            }
            Transition45Player.spitState = 0;
            Transition45Player.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition45Player.unk20a=0;
        Transition45Player.critterMobyPtr=0;
        return;
    }
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level45
 * 80088960: original871 instructions and144 dispatch words in sibling4839
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original45.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A45W48 __asm__("D_80070328 + 0x48");
extern int A45W4C __asm__("D_80070328 + 0x4C");
extern int A45W54 __asm__("D_80070328 + 0x54");
extern int A45WA0 __asm__("D_80070328 + 0xA0");
extern int A45WA8 __asm__("D_80070328 + 0xA8");
extern int A45WAC __asm__("D_80070328 + 0xAC");
extern int A45WB0 __asm__("D_80070328 + 0xB0");
extern int A45WB8 __asm__("D_80070328 + 0xB8");
extern int A45WCC __asm__("D_80070328 + 0xCC");
extern int A45WD0 __asm__("D_80070328 + 0xD0");
extern int A45WD4 __asm__("D_80070328 + 0xD4");
extern int A45W8C __asm__("D_80070328 + 0x8C");
extern int A45W90 __asm__("D_80070328 + 0x90");
extern int A45W94 __asm__("D_80070328 + 0x94");
extern int A45WE4 __asm__("D_80070328 + 0xE4");
extern int A45W144 __asm__("D_80070328 + 0x144");
extern int A45W158 __asm__("D_80070328 + 0x158");
extern int A45W1EC __asm__("D_80070328 + 0x1EC");
extern int A45W1F0 __asm__("D_80070328 + 0x1F0");
extern int A45W240 __asm__("D_80070328 + 0x240");
extern int A45W280 __asm__("D_80070328 + 0x280");
extern unsigned char A45B14 __asm__("D_80070328 + 0x14");
extern unsigned char A45B15 __asm__("D_80070328 + 0x15");
extern unsigned char A45B16 __asm__("D_80070328 + 0x16");
extern unsigned char A45B17 __asm__("D_80070328 + 0x17");
extern unsigned char A45B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A45BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A45B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A45B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A45Player[] __asm__("D_80070328");
extern unsigned char A45Table[] __asm__("D_80066530");
extern int A45Buttons __asm__("D_8006E538"),A45NewButtons __asm__("D_8006E53C");
extern int A45Mode __asm__("D_8006E044"),A45Gate __asm__("D_8006E344"),A45Count __asm__("D_8006C514");
extern int (*A45Callback)() __asm__("unk_ovlheader_80074374");
extern int A45W24 __asm__("D_80070328 + 0x24");
extern int A45W28C __asm__("D_80070328 + 0x28C");
extern int A45W290 __asm__("D_80070328 + 0x290");
extern int A45Surface __asm__("D_8006FA38");
extern unsigned char* A45SoundDesc __asm__("D_8006C654");
int A45Sound() __asm__("PlaySound");
int A45H3BF6C() __asm__("func_8003BF6C");
int A45H3BE70() __asm__("func_8003BE70");
int A45H40994() __asm__("func_80040994");
int A45H4BEF8() __asm__("func_8004BEF8");
int A45H49688() __asm__("func_80049688");
int A45H4F334() __asm__("func_8004F334");
int A45H498C0() __asm__("func_800498C0");
extern volatile int A45W20C __asm__("D_80070328 + 0x20C");
extern int A45W214 __asm__("D_80070328 + 0x214");
extern unsigned char A45B100 __asm__("D_80070328 + 0x100");
extern unsigned char A45E535 __asm__("D_8006E535");
extern unsigned char* A45Models __asm__("D_8006EE2C");
int A45H40BCC() __asm__("func_80040BCC");
int A45H1A310() __asm__("func_8001A310");
extern int A45W10C __asm__("D_80070328 + 0x10C");
extern int A45WB4 __asm__("D_80070328 + 0xB4");
extern int A45WA4 __asm__("D_80070328 + 0xA4");
extern int (*A45Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A45H40954() __asm__("func_80040954");
extern int A45W50 __asm__("D_80070328 + 0x50");
extern int A45WBC __asm__("D_80070328 + 0xBC"), A45W1BC __asm__("D_80070328 + 0x1BC"), A45W60 __asm__("D_80070328 + 0x60");
extern short A45H148 __asm__("D_80070328 + 0x148");
int A45H43194() __asm__("func_80043194");
int A45H4EDE8() __asm__("func_8004EDE8");
void func_level_45_80088960(void) {
 register int work2 __asm__("$2"),work3 __asm__("$3"),work4 __asm__("$4"),work5 __asm__("$5");
 register int* state __asm__("$16");
 register int* locomotion __asm__("$17");
 switch(A45W48){
 case 21: case 22: case 23: case 24: case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 36: case 37: case 38: case 39: case 40: case 41: case 42: case 45: case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 56: case 57: case 58: case 59: case 60: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89: case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: case 100: case 101: case 102: case 103: case 104: case 105: case 106: case 107: case 108: case 109: case 110: case 111: case 112: case 113: case 114: case 115: case 116: case 117: case 118: case 119: case 120: case 121: case 122: case 123: case 124: case 125: case 126: case 127: case 128: case 129: case 130: case 131: case 132: case 133: case 134: case 135: case 136: case 137: case 138: case 139: case 140: case 141: case 142: case 143: case 144: case 145: case 146: case 147: case 148: case 149: case 150: case 151: case 152: case 153: case 154: case 155: case 156: case 157: case 158: case 159: return;
 case 20:
  if(A45H40994())return;
  work2=A45NewButtons&64;work4=6;if(work2)goto call;
  work2=A45WB8<4;work4=7;if(!work2)goto call;if(A45WE4>=23)goto call;
  work3=A45Buttons;
  work2=work3&128;work4=13;if(work2)goto call;
  work2=A45WA8;if(work2<0)work2=-work2;
  if(work2>=17){work4=1;goto call;}
  work2=work3&12;
  __asm__("" : "=r"(work2):"0"(work2));
  if(!work2){work2=A45WAC;work4=1;if(work2)goto call;}
  if(A45Mode==7 || A45W240) {
   state=&A45W48;__asm__("" : "=r"(state):"0"(state));
   if(!*state)return;
   A45H4BEF8(0);
   if(A45Table[*((unsigned char*)state-0x2C)]>=96){A45B14=A45B15;A45B16=A45B17;}
   A45B17=0;work3=*state;work2=113;*((unsigned char*)state-0x2C)=work2;
   A45W1F0=0;A45B15=work3;A45W1EC=work3;return;
  }
  work2=A45BFC;work4=15;if(work2)goto call;
  A45H49688();return;
 case 53: case 54:work2=A45H40994();work4=0;if(work2)return;goto call;

 case 25:
  if(A45H40BCC())return;
  if(A45B1B5 && (A45NewButtons&64))A45B1B6=1;
  if(A45WE4>=23){
   work3=A45W8C;work2=A45WCC;work4=work3*work2;
   work3=A45W90;work2=A45WD0;work3=work3*work2;
   work2=work4+work3;work4=14;if(work2<0)goto call;
  }
  work3=A45WB0;if(work3>=3201){work2=A45WB4*2;work2=work2<work3;work4=14;if(work2)goto call;}
  if(!A45WB8){work2=A45W54<5;work4=61;if(!work2)goto call;}
  if(A45B1B6){work2=A45W94;work4=17;if(work2>=0)return;goto call;}
  work2=A45W94;work4=22;if(work2>=0)return;goto call;
 case 33:

  if(A45H40994())return;
  locomotion=&A45WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A45WE4>=23)A45H4BEF8(7);
   if(A45WAC>0){
    work3=A45WB0;work2=work3<3841;if(!work2){__asm__ volatile("" ::: "memory");work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A45WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A45NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A45H43194(4);work4=47;if(work2)goto call;
  work2=A45WBC;work4=7;if(!work2)goto call;
  work2=A45W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A45H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  work2=A45H148<2;work4=35;if(!work2)goto call;
  work2=A45W4C;work4=34;if(work2)goto call;
  work3=A45W60;work2=work3<365;if(!work2)goto call;
  work2=work3< -364;work4=35;if(!work2)return;goto call;

 case 34:

  if(A45H40994())return;
  locomotion=&A45WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A45WE4>=23)A45H4BEF8(7);
   if(A45WAC>0){
    work3=A45WB0;work2=work3<3841;if(!work2){__asm__ volatile("" ::: "memory");work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A45WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A45NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A45H43194(4);work4=47;if(work2)goto call;
  work2=A45WBC;work4=7;if(!work2)goto call;
  work2=A45W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A45H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  work2=A45H148<2;work4=35;if(!work2)goto call;
  if(A45W60>=256)return;
  work2=A45W4C;work4=33;if(work2)return;goto call;

 case 35:

  if(A45H40994())return;
  locomotion=&A45WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A45WE4>=23)A45H4BEF8(7);
   if(A45WAC>0){
    work3=A45WB0;work2=work3<3841;if(!work2){work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A45WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A45NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A45H43194(4);work4=47;if(work2)goto call;
  work2=A45WBC;work4=7;if(!work2)goto call;
  work2=A45W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A45H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  if(A45H148>=2)return;
  work2=A45W4C;work4=34;if(work2)goto call;
  work2=A45W60< -255;work4=33;if(work2)return;goto call;

 case 43: {
  register unsigned char* byte4 __asm__("$4");
  if(A45H40994())return;
  if((A45NewButtons&64) && A45W54>=9){work4=6;goto partialCall;}
  byte4=&A45B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto partialCall;}
  if(!(A45NewButtons&128))goto check44;
  if(A45W54<9)goto check44;
  work2=*(int*)(A45Models+220);byte4-=256;if(!work2)goto check44;
  work2=A45H1A310(byte4,1024,1,0);work4=40;
  if(work2)goto check44;goto call;
  partialCall:A45H4BEF8(work4);
  check44:work2=A45E535;work4=44;if(!work2)return;goto call;
 }
 case 44: {
  register unsigned char* byte4 __asm__("$4");
  register int (*callback2)() __asm__("$2");
  work3=A45W4C;work2=1;if(work3!=work2)goto other44;
  if(A45NewButtons&0x850)goto callback44;
  if(A45W54<61)return;
  callback44:callback2=A45Callback;__asm__("" : "=r"(callback2):"0"(callback2));
  if(!callback2)goto missingCallback;
  callback2();return;
  missingCallback:A45H498C0();return;
  other44:if(A45H40994())return;
  if((A45NewButtons&64) && A45W54>=9){work4=6;goto call;}
  byte4=&A45B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto call;}
  if(!(A45NewButtons&128))goto mode44;
  if(A45W54<9)goto mode44;
  work2=*(int*)(A45Models+220);byte4-=256;if(!work2)goto mode44;
  work2=A45H1A310(byte4,1024,1,0);work4=40;if(!work2)goto call;
  mode44:work3=A45Mode;work2=7;if(work3==work2)return;
  work2=A45E535;work4=43;if(work2)return;goto call;
 }
 case 55:
  if(A45W54<101)return;
  A45H4BEF8(44);work2=1;A45W4C=work2;work2=8;A45W50=work2;return;

 case 61:
  if(A45H40BCC())return;
  work2=1;__asm__("" : "=r"(work2):"0"(work2));state=&A45W4C;__asm__("" : "=r"(state):"0"(state));work3=*state;
  if(work3==work2){
   if(A45WB8>=4)goto partial25;
   work2=A45H40954(A45W10C);work3=9;if(work2==work3)goto finalSpeed;
   *state=0;goto finalSpeed;
  }
  if(A45Buttons&64){
   partial25:A45H4BEF8(25);work2=A45WB8;work3=3520;A45W94=work3;A45WB8=work2+1;return;
  }
  work2=A45WB8<4;work4=25;if(!work2)goto call;
  if(A45WE4>=23){
   work3=A45WCC;work2=A45W8C;work4=work3*work2;
   work3=A45WD0;work2=A45W90;work3=work3*work2;
   work2=work4+work3;work4=7;if(work2<0)goto call;
  }
  {
   register int* pointer4 __asm__("$4");
   pointer4=&A45W4C;__asm__("" : "=r"(pointer4):"0"(pointer4));
   work3=*pointer4;work2=2;if(work3==work2 && A45W54>=16)*pointer4=0;
  }
  if(A45Buttons&128)goto finalSpeed;
  work2=A45Surface;if(work2>=0)goto finalSpeed;
  work2=2;work3=A45W4C;work4=3;if(work3!=work2)goto call;
  finalSpeed:work3=A45WB0;work2=work3<3201;if(work2)return;
  work2=A45WB4*2;work2=work2<work3;work4=14;if(!work2)return;
  __asm__ volatile("" ::: "memory");
  goto call;
 case 160:
  if(A45H40994())return;
  if(A45W54<31)return;
  work2=A45W60< -512;work4=163;if(work2)goto call;
  work3=A45WA8;work2=work3<11;
  if(!work2){work4=162;goto call;}
  work2=work3< -10;work4=161;if(!work2)return;goto call;
 case 161:
  if(A45H40994())return;
  if(A45W54<31)return;
  work2=A45W60< -512;work4=163;if(work2)goto call;
  work2=A45WA8< -4;goto final160;
 case 162:
  if(A45H40994())return;
  if(A45W54<31)return;
  if(A45W60< -512)A45H4BEF8(163);
  work2=A45WA8<5;work4=160;if(!work2)return;goto call;
 case 163:
  if(A45H40994())return;
  if(A45W54<31)return;
  work2=A45W60< -383;
  final160:work4=160;if(work2)return;__asm__ volatile("" ::: "memory");
  call:__asm__ volatile("" ::: "memory");A45H4BEF8(work4);return;
 }
}
