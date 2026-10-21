#include "matching.h"
#include "common.h"
#include "camera.h"
#include "mobyutil.h"
#include "spu.h"
#include "hud.h"
#include "drawutil.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80086D54.
* Assembly SHA256 7978df058e7f73ab601c0ad26340a3bdb187de00cfec1502584466aa80d7e870.
* AI-generated; not human reviewed. All1369 original instructions, * 0 selectors bias0 and 0 owned padding words are required.
* Original frame0xC8; every concrete field width and producer is retained.
* Sparse selector dispatch has no table. Verified25 and45 state bodies retain
* their concrete original producers. The original S1 playerVector54 pointer feeds
* the33/175 input argument at+100 before its conditional transition to player0;
* 43/44 independently retains its original S0 field4C pointer. States53/54, * 55 and176 retain their original S1-relative clear calls. State25's clamp
* stores the original S0 selector. State176 retains every original random, * 55D24/55F14, vector, stack and particle-byte producer. Its initialized T0
* function pointer comes from the original SpawnParticle LW and is the sole
* T0 C object. All low products and signed constant divisions are ordinary C;
* the33 and175 spring results have independent lifetimes. The175 body lacks
* the rotation-counter arm absent from its original instructions. Its global
* field4C accesses remain direct, while33 retains the original A1-relative
* stores. Their only shared late tail is the original add88 at8008826C.
* FrameC8, scratchSP10..AC and every original S0..S4/RA word are required.
* Initialized empty dependencies restore original particle argument order
* without emitting CPU instructions. Complete helper contracts remain open.
* Repeated identical declarations are removed; distinct typed aliases stay
* distinct. Initialized empty constraints and original address metadata emit
* zero CPU instructions; frozen C tools emit words. Units/fixed point, helper
* contracts and caller rate remain unresolved; cadence is per invocation.
* Falsification: every native/linked instruction, actual internal/conditional
* target, selector/data and full EXE/every-overlay retail hashes. Binary identity
* does not establish synchronized runtime or system completeness. */
#define Physics15Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern void* Physics15Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics15Data6E548View1 __asm__("D_8006E548");
int Physics15Call40D10View1() __asm__("func_80040D10");
int Physics15Call40F48View1() __asm__("func_80040F48");
int Physics15Call41404View1() __asm__("func_80041404");
int Physics15Call41580View1() __asm__("func_80041580");
int Physics15Call416F4View1() __asm__("func_800416F4");
int Physics15Call417FCView1() __asm__("func_800417FC");
int Physics15Call41848View1() __asm__("func_80041848");
int Physics15Call41B64View1() __asm__("func_80041B64");
int Physics15InterpolateSineView1() __asm__("func_8004E9E4");
int Physics15InterpolateCosineView1() __asm__("func_8004EA2C");
int Physics15MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Physics15ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Physics15ClearVectorView1() __asm__("func_8004F168");
int Physics15CopyVectorView1() __asm__("func_8004F178");
int Physics15AddVectorView1() __asm__("func_8004F194");
int Physics15SubtractVectorView1() __asm__("func_8004F1C8");
extern int Physics15Data6763CView1 __asm__("D_8006763C");
extern int Physics15Data67640View1 __asm__("D_80067640");
extern int Physics15Data67644View1 __asm__("D_80067644");
extern int Physics15Data6E044View1 __asm__("D_8006E044");
extern int Physics15PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics15Player94View1 __asm__("D_80070328+0x94");
extern int Physics15PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics15Player80View1 __asm__("D_80070328+0x80");
extern int Physics15PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics15Player64View1 __asm__("D_80070328+0x64");
extern int Physics15Player88View1 __asm__("D_80070328+0x88");
extern int Physics15Player84View1 __asm__("D_80070328+0x84");
extern int Physics15Player144View1 __asm__("D_80070328+0x144");
extern int Physics15Player60View1 __asm__("D_80070328+0x60");
extern int Physics15PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics15Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics15PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics15PlayerA0View1 __asm__("D_80070328+0xA0");
int Physics15Call13E38View1() __asm__("func_80013E38");
int Physics15RandSignedBetweenView1() __asm__("func_800363DC");
int Physics15Call410F8View1() __asm__("func_800410F8");
int Physics15Call41848View2() __asm__("func_80041848");
int Physics15Call41B64View2() __asm__("func_80041B64");
int Physics15Call4E4E4View1() __asm__("func_8004E4E4");
int Physics15InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics15AddVectorView2() __asm__("func_8004F194");
extern int Physics15Data67630View1 __asm__("D_80067630");
extern int Physics15Data67634View1 __asm__("D_80067634");
extern int Physics15Data67638View1 __asm__("D_80067638");
extern int Physics15Data6FA38View1 __asm__("D_8006FA38");
extern int Physics15Data71908View1 __asm__("D_80071908");
extern int Physics15Player130View1 __asm__("D_80070328+0x130");
extern int Physics15Player144View2 __asm__("D_80070328+0x144");
extern short Physics15Player148View1 __asm__("D_80070328+0x148");
extern short Physics15Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics15Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics15Player150View1 __asm__("D_80070328+0x150");
extern int Physics15Player154View1 __asm__("D_80070328+0x154");
extern int Physics15Player160View1 __asm__("D_80070328+0x160");
extern int Physics15Player48View1 __asm__("D_80070328+0x48");
extern int Physics15Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics15Player5CView1 __asm__("D_80070328+0x5C");
extern int Physics15Player60View2 __asm__("D_80070328+0x60");
extern int Physics15Player64View2 __asm__("D_80070328+0x64");
extern int Physics15Player8View1 __asm__("D_80070328+0x8");
extern int Physics15Player88View2 __asm__("D_80070328+0x88");
extern int Physics15Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics15Player90View1 __asm__("D_80070328+0x90");
extern int Physics15Player94View2 __asm__("D_80070328+0x94");
extern int Physics15PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics15PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics15PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics15PlayerF8View1 __asm__("D_80070328+0xF8");
int Physics15Call40D10View2() __asm__("func_80040D10");
int Physics15Call41580View2() __asm__("func_80041580");
int Physics15Call417FCView2() __asm__("func_800417FC");
int Physics15Call41848View3() __asm__("func_80041848");
int Physics15Call41B64View3() __asm__("func_80041B64");
int Physics15TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics15ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics15ClearVectorView2() __asm__("func_8004F168");
int Physics15CopyVectorView2() __asm__("func_8004F178");
int Physics15AddVectorView3() __asm__("func_8004F194");
int Physics15CallRandView1() __asm__("rand");
extern int Physics15Data6C640View1 __asm__("D_8006C640");
extern int Physics15Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics15Player0View1 __asm__("D_80070328");
extern void* (*Physics15SpawnParticleView1)() __asm__("SpawnParticle");
extern int Physics15Player148View2 __asm__("D_80070328+0x148");
extern unsigned char Physics15Player54View1 __asm__("D_80070328+0x54");
extern void* Physics15Player250View1 __asm__("D_80070328+0x250");
int Physics15RefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Physics15InterpolateMobyVertexView1() __asm__("func_80055F14");
void func_level_15_80086D54(int slotIndex) {
    register void* vector18 __asm__("$18");
    register void* vector19 __asm__("$19");
    register int numeric7 __asm__("$7");
    register void* result2 __asm__("$2");
    register void* (*effectCall)() __asm__("$8");
    register int stateSelector16 __asm__("$16");
    register void* playerVector54 __asm__("$17");
    register int numeric4 __asm__("$4");
    register int numeric5 __asm__("$5");
    register int delta18 __asm__("$18");
    register int delta19 __asm__("$19");
    register void* scratchPointer16 __asm__("$16");
    register int responseLimit16 __asm__("$16");
    int springProduct33, springProduct175;
    register int workWord2 __asm__("$2");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    int lowProduct0, lowProduct1;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC;
    } originalFrame;
    register int workWord3 __asm__("$3");
    register void* globalField4CPointer __asm__("$16");
    register int savedSlotIndex __asm__("$18");
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    int raw21_temp_a0_7;
    int raw21_temp_a1_4;
    int raw21_var_v0_2;
    void* raw21_temp_s0_11;
    void* raw21_temp_s1_7;
    void* raw21_temp_s2_3;
    void* raw21_temp_s4;
    savedSlotIndex = slotIndex;
    workWord2 = savedSlotIndex * 16;
    globalPointer = &Physics15Data6E548View1;
    stateSelector16 = Physics15Player48View1;
    __asm__("" : "=r"(globalPointer) : "0"(globalPointer), "r"(stateSelector16), "r"(workWord2));
    workWord2 += (int)globalPointer;
    playerVector54 = &Physics15Player54View1;
    MATCHING_KEEP2_VOLATILE_CLOBBER(workWord2, playerVector54, "memory");
    Physics15Data6C570View1 = (void*)workWord2;
    switch (stateSelector16) {
        default:
            return;
        case 53:
        case 54:
            MATCHING_OBSERVE_VOLATILE(stateSelector16);
            Physics15ClearVectorView1(playerVector54 + 44);
            Physics15ClearVectorView1(playerVector54 + 56);
            workWord3 = Physics15Data6E044View1;
            workWord2 = 7;
            if (workWord3 == workWord2)
                return;
            Physics15Call40D10View1(0x1200);
            Physics15Call416F4View1();
            Physics15Call41580View1(90, 16);
            return;
        case 25:
            Physics15Call40F48View1(&originalFrame.sp10, 1);
            workWord2 = originalFrame.sp10;
            workWord2 >>= 1;
            Physics15PlayerA8View1 = workWord2;
            workWord2 = workWord2 < -25;
            if (workWord2) {
                workWord2 = -25;
                Physics15PlayerA8View1 = workWord2;
            }
            workWord2 = Physics15PlayerA8View1;
            workWord2 = workWord2 < 26;
            if (!workWord2)
                Physics15PlayerA8View1 = stateSelector16;
            call4 = (void*)Physics15PlayerA8View1;
            Physics15Call41404View1(call4);
            Physics15Call417FCView1(576, 384);
            workWord2 = Physics15InterpolateCosineView1(Physics15Player64View1);
            workWord3 = Physics15PlayerB0View1;
            lowProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics15Player64View1;
            workWord2 = lowProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            Physics15Player80View1 = workWord2;
            workWord2 = Physics15InterpolateSineView1(call4);
            workWord3 = Physics15PlayerB0View1;
            lowProduct1 = workWord3 * workWord2;
            workWord2 = Physics15Player94View1;
            Physics15Player88View1 = workWord2;
            workWord2 = lowProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            Physics15Player84View1 = workWord2;
            Physics15Call41B64View1();
            workWord2 = Physics15Player144View1;
            workWord2 += 12;
            Physics15Player144View1 = workWord2;
            workWord2 = workWord2 < 193;
            if (!workWord2) {
                workWord2 = 192;
                Physics15Player144View1 = workWord2;
            }
            workWord2 = Physics15Player94View1;
            workWord3 = Physics15Player144View1;
            workWord2 -= workWord3;
            Physics15Player94View1 = workWord2;
            workWord2 = workWord2 < -8960;
        clamp19:
            __asm__ volatile("" ::"i"(0x80086C60) : "memory");
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics15Player94View1 = workWord2;
            return;
        case 176:
            workWord2 = Physics15PlayerB8View1;
            vector18 = &originalFrame.sp18;
            if (!workWord2)
                goto clear176;
            Physics15ClearVectorView1(vector18);
            call4 = vector18;
            call5 = vector18;
            MATCHING_KEEP2(call4, call5);
            vector19 = playerVector54 + 56;
            call6 = vector19;
            Physics15SubtractVectorView1(call4, call5, call6);
            originalFrame.sp20 = 0;
            call4 = vector18;
            call5 = 0;
            workWord2 = Physics15MeasureVectorLengthView1(call4, call5);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics15ScaleVectorRatioQ15View1(vector18, call5, 64);
            workWord2 = -192;
            originalFrame.sp20 = workWord2;
            scratchPointer16 = playerVector54 + 44;
            Physics15AddVectorView1(scratchPointer16, vector19, vector18);
            Physics15CopyVectorView1(vector19, scratchPointer16);
            goto particle176;
        clear176:
            Physics15ClearVectorView1(playerVector54 + 44);
            Physics15ClearVectorView1(playerVector54 + 56);
        particle176:
            globalPointer = &Physics15Player94View1;
            workWord2 = Physics15Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2)
                Physics15Field(globalPointer, int*, 0) = -8960;
            workWord2 = (int)Physics15SpawnParticleView1;
            call4 = (void*)10;
            if (!workWord2)
                return;
            call5 = (void*)30;
            workWord2 = Physics15RandSignedBetweenView1(call4, call5);
            call4 = (void*)10;
            call5 = (void*)30;
            originalFrame.sp28 = workWord2;
            workWord2 = Physics15RandSignedBetweenView1(call4, call5);
            call4 = Physics15Player250View1;
            MATCHING_KEEP_CLOBBER(call4, "$5");
            call5 = (void*)4;
            MATCHING_KEEP3_VOLATILE_CLOBBER(call4, call5, workWord2, "memory");
            originalFrame.sp2C = workWord2;
            workWord2 = 10;
            originalFrame.sp30 = workWord2;
            Physics15RefreshMobySpatialGridAndBasisView1(call4, call5);
            call5 = 0;
            MATCHING_KEEP(call5);
            scratchPointer16 = &originalFrame.sp38;
            call4 = Physics15Player250View1;
            call6 = scratchPointer16;
            Physics15InterpolateMobyVertexView1(call4, call5, call6);
            call4 = 0;
            call5 = (void*)20;
            workWord2 = Physics15RandSignedBetweenView1(call4, call5);
            call4 = 0;
            workWord3 = originalFrame.sp38;
            call5 = (void*)20;
            workWord3 += workWord2;
            originalFrame.sp38 = workWord3;
            workWord2 = Physics15RandSignedBetweenView1(call4, call5);
            call4 = 0;
            workWord3 = originalFrame.sp3C;
            call5 = (void*)20;
            workWord3 += workWord2;
            originalFrame.sp3C = workWord3;
            workWord2 = Physics15RandSignedBetweenView1(call4, call5);
            call4 = (void*)1;
            call5 = (void*)55;
            call6 = scratchPointer16;
            numeric7 = (int)&originalFrame.sp28;
            workWord3 = originalFrame.sp40;
            effectCall = Physics15SpawnParticleView1;
            workWord3 += workWord2;
            originalFrame.sp40 = workWord3;
            result2 = effectCall(call4, call5, call6, numeric7);
            workWord3 = 6;
            Physics15Field(result2, unsigned char*, 2) = workWord3;
            workWord3 = 32;
            Physics15Field(result2, unsigned char*, 10) = workWord3;
            return;
        case 33:
        case 34:
        case 35:
            call4 = &originalFrame.sp28;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = playerVector54 + 256;
            Physics15Call410F8View1(call4, call5, 0);
            workWord2 = originalFrame.sp2C;
            numeric4 = Physics15Player94View2;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp28;
            numeric4 -= 1024;
            originalFrame.sp38 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                scratchPointer16 = &originalFrame.sp30;
                call4 = scratchPointer16;
                call5 = scratchPointer16;
                __asm__ volatile(""
                                 : "=r"(playerVector54)
                                 : "0"(playerVector54), "r"(call4), "r"(call5)
                                 : "memory");
                playerVector54 -= 84;
                call6 = playerVector54;
                workWord2 = Physics15Player8CView1;
                workWord3 = Physics15Player90View1;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp30 = workWord2;
                originalFrame.sp34 = workWord3;
                Physics15AddVectorView2(call4, call5, call6);
                if (!Physics15Call13E38View1(playerVector54, scratchPointer16, 2)) {
                    workWord2 = Physics15Player8View1;
                    workWord3 = Physics15Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp2C = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp2C = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp2C;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics15PlayerF8View1;
            workWord3 = Physics15Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics15Player60View2;
                numeric4 = workWord2 >> 12;
                workWord3 = numeric4 - workWord3;
                numeric4 = workWord3 & 4095;
                workWord2 = numeric4 < 2049;
                if (!workWord2) {
                    numeric4 -= 4096;
                    workWord2 = numeric4 < delta18;
                } else
                    workWord2 = numeric4 < delta18;
                if (workWord2)
                    delta18 = numeric4;
            }
            call4 = &Physics15Player64View2;
            workWord2 = Physics15Field(call4, int*, 0);
            workWord3 = Physics15Player60View2;
            Physics15PlayerA8View2 = delta19;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics15Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics15Player60View2 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics15Player60View2 = workWord2;
            }
            workWord2 = Physics15Player60View2;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics15Player60View2 = -800;
            workWord2 = Physics15Player60View2;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics15Player60View2 = 800;
            workWord2 = Physics15Data6FA38View1;
            if (workWord2 >= 0)
                goto nonnegative33;
            workWord3 = Physics15Player60View2;
            if (workWord3 >= 0)
                goto positive33;
            numeric4 = Physics15Data67634View1;
            workWord2 = Physics15Data67630View1;
            workWord2 = numeric4 - workWord2;
            goto quotient33;
        positive33:
            if (workWord3 <= 0)
                goto zero33;
            workWord2 = Physics15Data67638View1;
            numeric4 = Physics15Data67634View1;
            workWord2 -= numeric4;
        quotient33:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics15PlayerACView2 = numeric4;
            goto modifier33;
        zero33:
            workWord2 = Physics15Data67634View1;
            Physics15PlayerACView2 = workWord2;
        modifier33:
        speed33:
            call5 = &Physics15Player144View2;
            workWord2 = Physics15PlayerACView2;
            numeric4 = Physics15PlayerB0View2;
            workWord3 = Physics15Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics15Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics15PlayerB0View2 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics15PlayerB0View2 = 2048;
            workWord2 = Physics15PlayerB0View2;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics15PlayerB0View2 = 19200;
            goto rotation33;
        nonnegative33:
            numeric4 = Physics15Player8View1;
            responseLimit16 = 0;
            workWord2 = Physics15Call4E4E4View1(numeric4);
            workWord3 = Physics15Player148View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            numeric4 = workWord2;
            MATCHING_KEEP(numeric4);
            Physics15PlayerACView2 = numeric4;
            numeric5 = workWord3;
            if (!workWord3)
                goto zeroCounter33;
            workWord2 = 0x60000;
            Physics15Player130View1 = workWord2;
            workWord2 = numeric5 - 1;
            Physics15Player148View1 = workWord2;
            workWord2 <<= 16;
            if (workWord2 > 0)
                goto positiveCounter33;
            workWord3 = Physics15PlayerB0View2;
            workWord2 = workWord3 - numeric4;
            workWord2 = workWord2 < 192;
            if (workWord2) {
                workWord2 = numeric4 + 8192;
                Physics15PlayerB0View2 = workWord2;
                Physics15Player148View1 = 0;
                goto counterClamp33;
            }
            workWord2 = workWord3 - 192;
            Physics15PlayerB0View2 = workWord2;
            workWord2 = 1;
            Physics15Player148View1 = workWord2;
            goto counterClamp33;
        positiveCounter33:
            workWord2 = numeric4 + 8192;
            Physics15PlayerB0View2 = workWord2;
            responseLimit16 = 96;
            goto counterClamp33;
        zeroCounter33:
            Physics15PlayerB0View2 = numeric4;
            __asm__ volatile("" : "=r"(responseLimit16) : "0"(responseLimit16) : "$3", "memory");
            Physics15Player130View1 = 0;
        counterClamp33:
            globalPointer = &Physics15PlayerB0View2;
            workWord2 = Physics15Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 22785;
            if (!workWord2)
                Physics15Field(globalPointer, int*, 0) = 22784;
            workWord2 = Physics15Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 2048;
            if (workWord2)
                Physics15Field(globalPointer, int*, 0) = 2048;
            numeric5 = Physics15Player14CView1;
            workWord3 = Physics15Player150View1;
            workWord2 = responseLimit16 - numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics15Player150View1 = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics15Player14CView1 = numeric5;
            if (numeric5 < 0)
                Physics15Player14CView1 = 0;
            workWord2 = Physics15Player14CView1;
            workWord2 = workWord2 < 97;
            if (!workWord2)
                Physics15Player14CView1 = 96;
        rotation33:
            workWord2 = Physics15Player148View1;
            workWord2 = workWord2 < 2;
            if (workWord2)
                goto spring33;
            workWord3 = Physics15Player14AView1;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 3;
            MATCHING_KEEP(workWord2);
            workWord3 = Physics15Player5CView1;
            workWord2 <<= 11;
            Physics15Player154View1 = workWord2;
            workWord2 >>= 6;
            workWord3 += workWord2;
            workWord3 &= 4095;
            workWord2 = workWord3 < 2049;
            Physics15Player5CView1 = workWord3;
            if (workWord2)
                goto rotationDone33;
            workWord2 = workWord3 - 4096;
            goto storeAngle33;
        spring33:
            workWord2 = Physics15InterpolateCosineView2(Physics15Player60View2);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            springProduct33 = delta19 * workWord2;
            workWord3 = Physics15Player154View1;
            numeric5 = Physics15Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = springProduct33 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics15Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics15Player5CView1 = numeric5;
            if (workWord2)
                goto rotationDone33;
            workWord2 = numeric5 - 4096;
        storeAngle33:
            Physics15Player5CView1 = workWord2;
        rotationDone33:
            Physics15Call41848View2();
            call5 = &Physics15Player4CView2;
            numeric4 = Physics15Field(call5, int*, 0);
            if (numeric4)
                goto active33;
            workWord2 = (int)Physics15Data6C570View1;
            workWord2 = Physics15Field((void*)workWord2, int*, 4) & 64;
            if (!workWord2)
                goto end15;
            workWord2 = Physics15PlayerF8View1;
            workWord3 = Physics15Player8View1;
            workWord2 -= 512;
            workWord3 = workWord3 < workWord2;
            if (!workWord3)
                goto end15;
            workWord3 = Physics15Player48View1;
            workWord2 = 33;
            if (workWord3 != workWord2)
                goto end15;
            workWord2 = 1;
            Physics15Field(call5, int*, 0) = workWord2;
            __asm__ volatile("" ::: "$4", "memory");
            Physics15Player160View1 = 0;
            goto end15;
        active33:
            workWord2 = Physics15Player8View1;
            workWord3 = Physics15PlayerF8View1;
            workWord2 = workWord2 < workWord3;
            if (workWord2) {
                workWord2 = 1;
                goto activeRemainder33;
            }
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics15Field(call5, int*, 0) = 0;
            goto end15;
        activeRemainder33:
            if (numeric4 != workWord2)
                goto decline33;
            workWord2 = Physics15Player160View1;
            workWord2 += 512;
            Physics15Player160View1 = workWord2;
            workWord2 = workWord2 < 6144;
            if (!workWord2) {
                workWord2 = 6144;
                Physics15Player160View1 = workWord2;
                workWord2 = 2;
                Physics15Field(call5, int*, 0) = workWord2;
            }
            goto sharedAdd88;
        decline33:
            workWord2 = Physics15Player160View1;
            workWord2 -= 256;
            Physics15Player160View1 = workWord2;
            if (workWord2 <= 0) {
                Physics15Player160View1 = 0;
                Physics15Field(call5, int*, 0) = 0;
            }
            goto sharedAdd88;
        case 43:
        case 44:
            workWord2 = 1;
            MATCHING_OBSERVE2_VOLATILE(workWord2, stateSelector16);
            globalField4CPointer = &Physics15Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics15Field(globalField4CPointer, int*, 0);
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            Physics15ClearVectorView2(globalField4CPointer + 52);
            Physics15ClearVectorView2(globalField4CPointer + 64);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics15Data6E044View2;
            if (workWord3 == workWord2) {
                Physics15Field(&Physics15Player0View1, int*, 0xB0) = 0;
            } else {
                Physics15Call40D10View2(0x980);
                raw21_var_v0_2 = Physics15Call41580View2(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics15Field(&Physics15Player0View1, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics15Field(&Physics15Player0View1, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics15Call417FCView2(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics15Player0View1 + 0xB0;
            if (Physics15Field(&Physics15Player0View1, int*, 0xB0) != 0) {
                Physics15Call41848View3();
                Physics15Call41B64View3();
                Physics15Field(&Physics15Player0View1, int*, 0x94) = 0;
            } else {
                Physics15ClearVectorView2(raw21_temp_s0_11 - 0x30);
                Physics15ClearVectorView2(raw21_temp_s0_11 - 0x24);
            }
            if (Physics15SpawnParticleView1 != 0) {
                raw21_temp_s4 = &Physics15Player0View1 + 0x28;
                if (Physics15Field(&Physics15Player0View1, int*, 0x28) < 0) {
                    if ((Physics15Field(&Physics15Player0View1, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics15Data6C640View1 & 1)) {
                        Physics15CopyVectorView2(&originalFrame.sp48, raw21_temp_s4 - 0x28);
                        originalFrame.sp5C = 0x40;
                        originalFrame.sp60 = 0;
                        originalFrame.sp58 =
                            (int)Physics15Field(&Physics15Player0View1, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp5C = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics15TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp58,
                                                             &originalFrame.sp68);
                        Physics15AddVectorView3(&originalFrame.sp48, &originalFrame.sp48,
                                                &originalFrame.sp68);
                        originalFrame.sp58 = 0;
                        originalFrame.sp50 = -Physics15Field(&Physics15Player0View1, int*, 0x28);
                        Physics15TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp58,
                                                             &originalFrame.sp58);
                        Physics15ShiftVectorRightTowardZeroView1(&originalFrame.sp58, 3);
                        Physics15SpawnParticleView1(1, 0x2A, &originalFrame.sp48,
                                                    &originalFrame.sp58);
                        if (!(Physics15CallRandView1() & 0x1F)) {
                            Physics15SpawnParticleView1(1, 0x29, &originalFrame.sp48, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics15Player0View1 + 0xB0;
                        if ((Physics15Field(&Physics15Player0View1, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics15Data6C640View1 & 7) &&
                            !(Physics15CallRandView1() & 3)) {
                            originalFrame.sp78 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp7C = 0;
                            originalFrame.sp80 = 0;
                            Physics15TransformVectorByBasisView1(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp78, &originalFrame.sp78);
                            Physics15AddVectorView3(&originalFrame.sp78, &originalFrame.sp78,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp80 =
                                -Physics15Field(&Physics15Player0View1, int*, 0x28);
                            Physics15SpawnParticleView1(1, 0x2B, &originalFrame.sp78, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics15Field(&Physics15Player0View1, int*, 0x144) -
                ((int)((Physics15Field(&Physics15Player0View1, int*, 0x148) * 2) +
                       (Physics15Field(&Physics15Player0View1, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics15Field(&Physics15Player0View1, int*, 0x148) + raw21_temp_a1_4;
            Physics15Field(&Physics15Player0View1, int*, 0x144) = raw21_temp_a1_4;
            Physics15Field(&Physics15Player0View1, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics15Field(&Physics15Player0View1, int*, 0x148) = 0x5900;
            }
            if (Physics15Field(&Physics15Player0View1, int*, 0x148) < -0x5900) {
                Physics15Field(&Physics15Player0View1, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 55: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics15ClearVectorView1(playerVector54 + 44);
            Physics15ClearVectorView1(playerVector54 + 56);
            numeric5 = Physics15Player148View2;
            numeric4 = Physics15Player144View1;
            workWord3 = numeric5 << 1;
            workWord2 = numeric4 * 5;
            workWord2 <<= 2;
            workWord3 += workWord2;
            workWord3 >>= 8;
            numeric4 -= workWord3;
            numeric5 += numeric4;
            Physics15Player144View1 = numeric4;
            Physics15Player148View2 = numeric5;
            return;
        }
        case 61:
            Physics15Call40F48View1(&originalFrame.sp68, 1);
            workWord3 = originalFrame.sp68;
            workWord2 = workWord3 * 25;
            call4 = (void*)(workWord2 >> 7);
            if (!call4)
                goto zeroSteer61;
            if ((int)call4 >= 0)
                goto positive61;
            workWord2 = Physics15PlayerA8View1;
            if (workWord2 <= 0)
                goto approach61;
            goto zeroSteer61;
        positive61:
            workWord2 = Physics15PlayerA8View1;
            if (workWord2 >= 0)
                goto approach61;
        zeroSteer61:
            Physics15PlayerA8View1 = 0;
        approach61:
            call5 = &Physics15PlayerA8View1;
            workWord3 = Physics15Field(call5, int*, 0);
            workWord2 = workWord3 < (int)call4;
            if (workWord2) {
                workWord2 = workWord3 + 3;
                Physics15Field(call5, int*, 0) = workWord2;
                workWord2 = (int)call4 < workWord2;
                goto clamp61;
            }
            workWord2 = workWord3 - 3;
            Physics15Field(call5, int*, 0) = workWord2;
            workWord2 = workWord2 < (int)call4;
        clamp61:
            if (workWord2)
                Physics15Field(call5, int*, 0) = (int)call4;
            call4 = (void*)Physics15PlayerA8View1;
            Physics15Call41404View1(call4);
            workWord3 = Physics15Player60View1;
            workWord2 = workWord3 < 2049;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics15Player60View1 = workWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                workWord3 = Physics15Player60View1;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            if (workWord3 >= 0)
                goto nonnegative61;
            call4 = (void*)Physics15Data67640View1;
            workWord2 = Physics15Data6763CView1;
            workWord2 = (int)call4 - workWord2;
            goto quotient61;
        nonnegative61:
            if (workWord3 <= 0)
                goto zero61;
            workWord2 = Physics15Data67644View1;
            call4 = (void*)Physics15Data67640View1;
            workWord2 -= (int)call4;
        quotient61:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 352;
            call4 += workWord3;
            Physics15PlayerACView1 = (int)call4;
            goto update61;
        zero61:
            workWord2 = Physics15Data67640View1;
            Physics15PlayerACView1 = workWord2;
        update61:
            Physics15Call417FCView1(576, 384);
            Physics15Call41848View1();
            call6 = &Physics15PlayerFCView1;
            workWord2 = Physics15Field(call6, unsigned char*, 0);
            if (workWord2)
                goto field94FromA0;
            workWord2 = Physics15PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vectorCommit61;
        field94FromA0:
            workWord2 = Physics15PlayerA0View1;
            workWord2 -= 192;
            Physics15Player94View1 = workWord2;
            return;
        vectorCommit61:
            call5 = call6 - 124;
            Physics15AddVectorView1(call4, call5, call6 - 20);
            return;
        case 175:
            call4 = &originalFrame.sp88;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = playerVector54 + 256;
            Physics15Call410F8View1(call4, call5, 0);
            workWord2 = originalFrame.sp8C;
            numeric4 = Physics15Player94View2;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 2;
            workWord3 = originalFrame.sp88;
            numeric4 -= 1024;
            originalFrame.sp98 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                scratchPointer16 = &originalFrame.sp90;
                call4 = scratchPointer16;
                call5 = scratchPointer16;
                __asm__ volatile(""
                                 : "=r"(playerVector54)
                                 : "0"(playerVector54), "r"(call4), "r"(call5)
                                 : "memory");
                playerVector54 -= 84;
                call6 = playerVector54;
                workWord2 = Physics15Player8CView1;
                workWord3 = Physics15Player90View1;
                workWord2 >>= 2;
                workWord3 >>= 2;
                originalFrame.sp90 = workWord2;
                originalFrame.sp94 = workWord3;
                Physics15AddVectorView2(call4, call5, call6);
                if (!Physics15Call13E38View1(playerVector54, scratchPointer16, 2)) {
                    workWord2 = Physics15Player8View1;
                    workWord3 = Physics15Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp8C = workWord2;
                    workWord2 = workWord2 < 6;
                    if (!workWord2)
                        originalFrame.sp8C = 5;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord3 = originalFrame.sp8C;
                    workWord2 = delta18 < workWord3;
                    if (workWord2)
                        delta18 = workWord3;
                }
            }
            workWord2 = Physics15PlayerF8View1;
            workWord3 = Physics15Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics15Player60View2;
                numeric4 = workWord2 >> 12;
                workWord3 = numeric4 - workWord3;
                numeric4 = workWord3 & 4095;
                workWord2 = numeric4 < 2049;
                if (!workWord2) {
                    numeric4 -= 4096;
                    workWord2 = numeric4 < delta18;
                } else
                    workWord2 = numeric4 < delta18;
                if (workWord2)
                    delta18 = numeric4;
            }
            call4 = &Physics15Player64View2;
            workWord2 = Physics15Field(call4, int*, 0);
            workWord3 = Physics15Player60View2;
            Physics15PlayerA8View2 = delta19;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics15Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics15Player60View2 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics15Player60View2 = workWord2;
            }
            workWord2 = Physics15Player60View2;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics15Player60View2 = -800;
            workWord2 = Physics15Player60View2;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics15Player60View2 = 800;
            numeric4 = Physics15Player8View1;
            responseLimit16 = 0;
            workWord2 = Physics15Call4E4E4View1(numeric4);
            workWord3 = Physics15Player148View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            numeric4 = workWord2;
            MATCHING_KEEP(numeric4);
            Physics15PlayerACView2 = numeric4;
            numeric5 = workWord3;
            if (!workWord3)
                goto zeroCounter160;
            workWord2 = 0x60000;
            Physics15Player130View1 = workWord2;
            workWord2 = numeric5 - 1;
            Physics15Player148View1 = workWord2;
            workWord2 <<= 16;
            if (workWord2 > 0)
                goto positiveCounter160;
            workWord3 = Physics15PlayerB0View2;
            workWord2 = workWord3 - numeric4;
            workWord2 = workWord2 < 192;
            if (workWord2) {
                workWord2 = numeric4 + 8192;
                Physics15PlayerB0View2 = workWord2;
                Physics15Player148View1 = 0;
                goto counterClamp160;
            }
            workWord2 = workWord3 - 192;
            Physics15PlayerB0View2 = workWord2;
            workWord2 = 1;
            Physics15Player148View1 = workWord2;
            goto counterClamp160;
        positiveCounter160:
            workWord2 = numeric4 + 8192;
            Physics15PlayerB0View2 = workWord2;
            responseLimit16 = 96;
            goto counterClamp160;
        zeroCounter160:
            Physics15PlayerB0View2 = numeric4;
            __asm__ volatile("" : "=r"(responseLimit16) : "0"(responseLimit16) : "$3", "memory");
            Physics15Player130View1 = 0;
        counterClamp160:
            globalPointer = &Physics15PlayerB0View2;
            workWord2 = Physics15Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 22785;
            if (!workWord2)
                Physics15Field(globalPointer, int*, 0) = 22784;
            workWord2 = Physics15Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 2048;
            if (workWord2)
                Physics15Field(globalPointer, int*, 0) = 2048;
            numeric5 = Physics15Player14CView1;
            workWord3 = Physics15Player150View1;
            workWord2 = responseLimit16 - numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics15Player150View1 = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics15Player14CView1 = numeric5;
            if (numeric5 < 0)
                Physics15Player14CView1 = 0;
            workWord2 = Physics15Player14CView1;
            workWord2 = workWord2 < 97;
            if (!workWord2)
                Physics15Player14CView1 = 96;
            workWord2 = Physics15InterpolateCosineView2(Physics15Player60View2);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            springProduct175 = delta19 * workWord2;
            workWord3 = Physics15Player154View1;
            numeric5 = Physics15Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = springProduct175 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics15Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics15Player5CView1 = numeric5;
            if (workWord2)
                goto rotationDone160;
            workWord2 = numeric5 - 4096;
            MATCHING_KEEP(workWord2);
        storeAngle160:
            Physics15Player5CView1 = workWord2;
        rotationDone160:
            Physics15Call41848View2();
            numeric4 = Physics15Player4CView2;
            if (numeric4)
                goto active45;
        noInput45:
            workWord2 = (int)Physics15Data6C570View1;
            workWord2 = Physics15Field((void*)workWord2, int*, 4) & 64;
            if (!workWord2)
                goto end15;
            workWord2 = Physics15PlayerF8View1;
            workWord3 = Physics15Player8View1;
            workWord2 -= 512;
            workWord3 = workWord3 < workWord2;
            if (!workWord3)
                goto end15;
            workWord3 = Physics15Player48View1;
            workWord2 = 33;
            if (workWord3 != workWord2)
                goto end15;
            workWord2 = 1;
            Physics15Player4CView2 = workWord2;
            __asm__ volatile("" ::: "$4", "memory");
            Physics15Player160View1 = 0;
            goto end15;
        active45:
            workWord2 = Physics15Player8View1;
            workWord3 = Physics15PlayerF8View1;
            workWord2 = workWord2 < workWord3;
            if (workWord2) {
                workWord2 = 1;
                goto activeRemainder45;
            }
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
        zeroActive45:
            Physics15Player4CView2 = 0;
            goto end15;
        activeRemainder45:
            if (numeric4 != workWord2)
                goto decline45;
        increment45:
            workWord2 = Physics15Player160View1;
            workWord2 += 512;
            Physics15Player160View1 = workWord2;
            workWord2 = workWord2 < 6144;
            if (!workWord2) {
                workWord2 = 6144;
                Physics15Player160View1 = workWord2;
                workWord2 = 2;
                Physics15Player4CView2 = workWord2;
            }
            goto sharedAdd88;
        decline45:
            workWord2 = Physics15Player160View1;
            workWord2 -= 256;
            Physics15Player160View1 = workWord2;
            if (workWord2 <= 0) {
                Physics15Player160View1 = 0;
                Physics15Player4CView2 = 0;
            }
        sharedAdd88:
            {
                register void* pointer2 __asm__("$2");
                pointer2 = &Physics15Player88View2;
                workWord3 = Physics15Field(pointer2, int*, 0);
                numeric4 = Physics15Player160View1;
                workWord3 += numeric4;
                Physics15Field(pointer2, int*, 0) = workWord3;
            }
        end15:
            Physics15Call41B64View2();
            return;
    }
}
#undef Physics15Field


extern Spyro Callback15Player __asm__("D_80070328");
int Callback15_80037058(int x, int y) __asm__("func_80037058");
int Callback15_8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback15_80041930(void) __asm__("func_80041930");
void Callback15_80041AE8(void) __asm__("func_80041AE8");
void Callback15_80041C20(void) __asm__("func_80041C20");
void Callback15_80042A44(void) __asm__("func_80042A44");
void Callback15_80043A38(int scale) __asm__("func_80043A38");
void Callback15_80049590(void) __asm__("func_80049590");
void Callback15_8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback15_8006E344 __asm__("D_8006E344");
extern int Callback15_8006E52C __asm__("D_8006E52C");
extern int Callback15_8006E530 __asm__("D_8006E530");
extern int Callback15_8006E538 __asm__("D_8006E538");
void func_level_15_800882B8(void) {
    struct {
        Vector3D value;
        int reserved[2];
    } local;
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    unsigned char* sourceBytes;
    register int value __asm__("$4");
    register int height __asm__("$3");
    register int iteration __asm__("$16");
    register int iterationLimit __asm__("$17");

    switch (Callback15Player.animationState) {
        case 0x35:
        case 0x36:
        case 0xB0:
            Callback15_80041C20();
            Callback15_80042A44();
            goto clearValue;
        case 0x19:
            Callback15_80041C20();
            Callback15_80042A44();
            Callback15_80041930();
            Callback15_80049590();
            if ((Callback15Player.movementState == MOVEMENT_STATE_SUPERCHARGE) &&
                (SpawnParticle != 0)) {
                SpawnParticle(1, 9, 0, 0);
            }
            if ((Callback15Player.unk7a[3].z < 0) && (Callback15Player.animationStateFrames >= 4)) {
                Callback15Player.unk5 = 1;
            } else if ((Callback15Player.unk5 == 0) && !(Callback15_8006E538 & 0x40)) {
                Callback15Player.unk5 = 2;
            }
            goto clearValue;
        case 0x21:
        case 0x22:
        case 0x23:
            Callback15_80041C20();
            Callback15_80042A44();
            Callback15_80041930();
            if ((SpawnParticle != 0) && (Callback15Player.union144.b.unk148 != 0)) {
                iterationLimit = 1;
                if (Callback15Player.union144.b.unk148 >= 2) {
                    iterationLimit = 2;
                }
                iteration = 0;
                if (iterationLimit != 0) {
                    sourceBytes = (unsigned char*)&Callback15Player.union144.a.unk13cc - 0xB0;
                    do {
                        func_8004F178(&local.value, (Vector3D*)sourceBytes);
                        Callback15_8004F110(&local.value, 7);
                        iteration += 1;
                        sample = rand();
                        component = local.value.x;
                        sample &= 254;
                        component -= 127;
                        component = component + sample;
                        MATCHING_KEEP(component);
                        local.value.x = component;
                        sample = rand();
                        component = local.value.y;
                        sample &= 254;
                        component -= 127;
                        component = component + sample;
                        MATCHING_KEEP(component);
                        local.value.y = component;
                        sample = rand();
                        kind = 1;
                        subtype = 23;
                        position = sourceBytes - 152;
                        vector = &local.value;
                        __asm__(""
                                : "=r"(sample)
                                : "0"(sample), "r"(kind), "r"(subtype), "r"(position), "r"(vector));
                        sample &= 254;
                        component = local.value.z;
                        component -= 127;
                        component = component + sample;

                    local.value.z = component;
                        SpawnParticle(kind, subtype, (Vector3D*)position, vector);
                    } while (iteration < iterationLimit);
                }
            }
            goto clearValue;
        case 0x2B:
        case 0x2C:
        case 0x37:
            Callback15_80041C20();
            Callback15_80042A44();
            Callback15_80041AE8();
            if ((unsigned char)Callback15Player.unk10[4] != 0) {
                sample =
                    Callback15_80037058(Callback15Player.position.x, Callback15Player.position.y);
                value = Callback15Player.unk9ha[4];
                height = Callback15Player.unk4a;
                __asm__("" : "=r"(value), "=r"(height) : "0"(value), "1"(height), "r"(sample));
                value = -value - sample;
                sample = (int)Callback15Player.union144.a.unk13cc;
                height -= value;
                Callback15Player.unk4[0] = value;
                sample >>= 6;
                height -= sample;
                Callback15Player.position.z = height;

            return;
            }
        default:
            return;
        case 0x3D:
            Callback15_80041C20();
            Callback15_80042A44();
            Callback15_80043A38(0xC00);
            Callback15_80049590();
            if (SpawnParticle != 0) {
                SpawnParticle(1, 9, 0, 0);
            }
            Callback15_8006E530 = 0x78;
            Callback15Player.unk4[0] = 0;
            Callback15_8006E52C = 4;
            if ((Callback15_8006E344 == 0) &&
                (Callback15_8003BF6C((int)D_8006C654->supercharge, Callback15Player.unk22[2]) ==
                 0)) {
                Callback15Player.unk22[2] = PlaySound((int)D_8006C654->supercharge, 0, 4);
                Callback15Player.unk22[3] = (int)D_8006C654->supercharge;
            }
            break;
        case 0xAF:
            Callback15_80041C20();
            Callback15_80042A44();
            value = Callback15Player.unk9ha[4];
            height = Callback15Player.unk4a;
            sample = Callback15Player.position.z;
            MATCHING_KEEP3(value, height, sample);
            value = value + height;
            if (sample < value)
                Callback15Player.position.z = value;
            Callback15_80041930();
        clearValue:
            Callback15Player.unk4[0] = 0;
            return;
    }
}

#define LEVEL_ID 15
#define PlaySpyroSounds_level_15 func_level_15_800886FC
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_15_80088804(int index) {
    register int* state __asm__("$5");
    register int value __asm__("$3");
    register unsigned char* base __asm__("$2");
    register unsigned int offset __asm__("$4");
    offset = index * 16;
    MATCHING_KEEP_CLOBBER(offset, "$2");
    base = D_8006E548;
    __asm__("" : "=r"(base) : "0"(base), "r"(offset) : "$5");
    state = &spyro.animationState;
    value = *state;
    MATCHING_KEEP_CLOBBER(value, "memory");
    offset = offset + (unsigned int)base;
    __asm__("" : "=r"(offset) : "0"(offset), "r"(value));
    D_8006C570 = (unsigned char*)offset;
    __asm__("" : : "r"(value) : "$2", "memory");
    if (value < 0x2D) {
        if (value >= 0x2B)
            goto vector;
        if (value == 0x19)
            goto other;
        return;
    } else {
        if (value == 0x3D)
            goto vector;
        if (value >= 0x3E) {
            if (value == 0xAF)
                return;
            if (value == 0xB0)
                goto reset;
            return;
        }
        if (value >= 0x38)
            return;
        if (value < 0x35)
            return;
    }
vector:
    MATCHING_OBSERVE(value);
    func_80043ABC(&spyro.unk9e);
    return;
reset:
    func_80043ABC(0);
    return;
other:
    func_80043E00((Vector3D*)((char*)state + 0x44));
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800888D4.
 * Reuses verified25/35 fly/surface/charge; original15 AF shares fly with
 * preserved<A0 pointer tail; B0 state8/ground1/timer15 retains pointers.
 * Offsets are bytes, original widths and sound selector22/7 retained.
 * Clamp7FF/800/4B00/4B01 ->800/800/4B00/4B00 before subsequent helpers.
 * Empty constraints emit no instructions. All original code/internal jumps/
 * owned words, strict complete TU and every retail hash required. Helpers,
 * physical units, audio semantics, cadence and live runtime parity remain open.
 */
extern Spyro Transition15Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw15Word __asm__("D_80070328+0x50");
extern unsigned char Raw15State[] __asm__("D_80070328+0x50");
extern unsigned char Raw15Union[] __asm__("D_80070328+0x144");
extern int Raw15Spit __asm__("D_80070328+0x170");
void Call15_8004F168(Vector3D*) __asm__("func_8004F168");
int Call15_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Call15A358(Vector3D*, int) __asm__("func_8001A358");
void Call15_800441F0(void) __asm__("func_800441F0");
void Call15_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
extern int Transition15DamageTimer __asm__("D_8006E524");
void func_level_15_800888D4(int arg0) {
    Vector3D surfaceVector;
    int vectorLength, surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");
    switch (arg0) {
        case 0x35:
            MATCHING_BARRIER_VOLATILE("memory");
            goto standEntry;
        case 0x36:
        standEntry:
            Transition15Player.movementState = MOVEMENT_STATE_STAND;
            Transition15Player.unk5 = 0;
            Call15_800441F0();
            Transition15Player.grounded = 1;
            goto clearPointers;

        case 0x19:
            soundZero = 0;
            MATCHING_KEEP(soundZero);
            soundTable = (unsigned char*)D_8006C654;
            MATCHING_KEEP(soundTable);
            Transition15Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
            Transition15Player.unk13a[0] = 0x60000;
            Transition15Player.unk5 = 0;
            Transition15Player.union144.a.unk13cb = 0;
            Transition15Player.grounded = 0;
            Transition15Player.unk15b = 1;
            soundSelector = soundTable[0x22];
        playSharedSound:
            PlaySound((int)soundSelector, (Moby*)soundZero, 0);
            goto clearPointers;
        case 0xAF:
        case 0x21:
        case 0x22:
        case 0x23: {
            register unsigned char* flyState __asm__("$17") = (unsigned char*)&Raw15Word;
            if (*(int*)flyState != 6) {
                *(int*)flyState = 6;
                Transition15Player.unk5 = 0;
                Call15_8004F168((Vector3D*)(flyState + 0x104));
                Transition15Player.union144.a.unk13db.y = 0;
                vectorLength = Call15_8004EDE8((Vector3D*)(flyState + 0x48), 0);
                Transition15Player.unk8[0] = vectorLength;
                if (vectorLength < 0x800)
                    Transition15Player.unk8[0] = 0x800;
                if (Transition15Player.unk8[0] >= 0x4B01)
                    Transition15Player.unk8[0] = 0x4B00;
                Transition15Player.union144.a.unk13cb = 0;
                Transition15Player.union144.b.unk148 = 0;
                Transition15Player.union144.a.unk13ce.x = 0;
                Transition15Player.union144.a.unk13ce.y = 0;
                Transition15Player.grounded = 0;
                Transition15Player.unk15b = 0;
            }
            if (arg0 < 0xA0)
                goto clearPointers;
            return;
        }
        case 0x2B:
        case 0x2C: {

            register unsigned char* unionPointer __asm__("$16");
            {
                register int stateWord __asm__("$3") = Raw15Word;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Raw15Union;
                    *(int*)unionPointer = (-Transition15Player.unk7a[2].z) >> 2;
                    if (Raw15Word != 8) {
                        Transition15Player.union144.a.unk13cc = 0x5900;
                        Raw15Word = 10;
                    }
                    Transition15Player.unk5 = 0;
                    Transition15Player.unk8[0] =
                        Call15_8004EDE8((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition15Player.grounded = 1;
                    Transition15Player.unk15b = 1;
                    func_8004F178(&surfaceVector, (Vector3D*)(unionPointer - 0x144));
                    surfaceVector.z += 0x400;
                    surfaceResult = Call15A358(&surfaceVector, 0x800);
                    surfaceVector.z = surfaceResult;
                    if (surfaceResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, &surfaceVector, 0);
                        SpawnParticle(6, 0x2E, &surfaceVector, 0);
                    }
                }
            }
            goto clearPointers;
        }

        case 0x37:
            originalZ = 8;
            MATCHING_KEEP(originalZ);
            Raw15Word = originalZ;
            MATCHING_BARRIER_VOLATILE("memory");
            originalZ = Transition15Player.unk7a[2].z;
            MATCHING_KEEP(originalZ);
            {
                register int flagValue __asm__("$3") = 1;
                MATCHING_KEEP(flagValue);
                Transition15Player.unk15b = flagValue;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            soundTable = (unsigned char*)D_8006C654;
            MATCHING_KEEP(soundTable);
            Transition15Player.union144.a.unk13cc = 0;
            Transition15Player.unk5 = 0;
            Transition15Player.grounded = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(originalZ, "memory");
            Transition15Player.union144.a.unk13cb = -originalZ >> 2;
            soundSelector = soundTable[7];
            soundZero = 0;
            goto playSharedSound;
        case 0x3D:
            stateBase = Raw15State;
            *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
            Transition15Player.unk5 = 0;
            Transition15Player.unk13a[0] = 0x60000;
            Transition15Player.unk8[0] = Call15_8004EDE8((Vector3D*)(stateBase + 0x48), 0);
            Transition15Player.horizontalSpeed = 0x1E80;
            Call15_80043A38(0xC00);
            Transition15Player.grounded = 1;
            if ((Transition15Player.unk13f[0] != 0) || (Transition15Player.spitState != 0) ||
                (Transition15Player.unk17t != 6)) {
                spitWord = &Raw15Spit;
                if (((unsigned)(*spitWord - 3) < 2U) || (*spitWord == 5)) {
                    *spitWord = 5;
                } else {
                    *spitWord = 0;
                }
                Transition15Player.spitState = 0;
                Transition15Player.unk17t = 6;
                func_80047138();
            }
        clearPointers:
            Transition15Player.unk20a = 0;
            Transition15Player.critterMobyPtr = 0;
            return;
        case 0xB0:
            originalZ = 8;
            MATCHING_KEEP(originalZ);
            Raw15Word = originalZ;
            Transition15Player.unk5 = 0;
            Call15_80043A38(0xC00);
            Transition15Player.grounded = 1;
            Transition15DamageTimer = 15;
            return;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level15
 * 80088D88: original760 instructions, sparse dispatch dispatch words in sibling4856
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original15.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A15W48 __asm__("D_80070328 + 0x48");
extern int A15W4C __asm__("D_80070328 + 0x4C");
extern int A15W54 __asm__("D_80070328 + 0x54");
extern int A15WA0 __asm__("D_80070328 + 0xA0");
extern int A15WA8 __asm__("D_80070328 + 0xA8");
extern int A15WAC __asm__("D_80070328 + 0xAC");
extern int A15WB0 __asm__("D_80070328 + 0xB0");
extern int A15WB8 __asm__("D_80070328 + 0xB8");
extern int A15WCC __asm__("D_80070328 + 0xCC");
extern int A15WD0 __asm__("D_80070328 + 0xD0");
extern int A15WD4 __asm__("D_80070328 + 0xD4");
extern int A15W8C __asm__("D_80070328 + 0x8C");
extern int A15W90 __asm__("D_80070328 + 0x90");
extern int A15W94 __asm__("D_80070328 + 0x94");
extern int A15WE4 __asm__("D_80070328 + 0xE4");
extern int A15W144 __asm__("D_80070328 + 0x144");
extern int A15W158 __asm__("D_80070328 + 0x158");
extern int A15W1EC __asm__("D_80070328 + 0x1EC");
extern int A15W1F0 __asm__("D_80070328 + 0x1F0");
extern int A15W240 __asm__("D_80070328 + 0x240");
extern int A15W280 __asm__("D_80070328 + 0x280");
extern unsigned char A15B14 __asm__("D_80070328 + 0x14");
extern unsigned char A15B15 __asm__("D_80070328 + 0x15");
extern unsigned char A15B16 __asm__("D_80070328 + 0x16");
extern unsigned char A15B17 __asm__("D_80070328 + 0x17");
extern unsigned char A15B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A15BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A15B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A15B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A15Player[] __asm__("D_80070328");
extern unsigned char A15Table[] __asm__("D_80066530");
extern int A15Buttons __asm__("D_8006E538"), A15NewButtons __asm__("D_8006E53C");
extern int A15Mode __asm__("D_8006E044"), A15Gate __asm__("D_8006E344"),
    A15Count __asm__("D_8006C514");
extern int (*A15Callback)() __asm__("unk_ovlheader_80074374");
extern int A15W24 __asm__("D_80070328 + 0x24");
extern int A15W28C __asm__("D_80070328 + 0x28C");
extern int A15W290 __asm__("D_80070328 + 0x290");
extern int A15Surface __asm__("D_8006FA38");
extern unsigned char* A15SoundDesc __asm__("D_8006C654");
int A15Sound() __asm__("PlaySound");
int A15H40994() __asm__("func_80040994");
int A15H4BEF8() __asm__("func_8004BEF8");
int A15H498C0() __asm__("func_800498C0");
extern volatile int A15W20C __asm__("D_80070328 + 0x20C");
extern int A15W214 __asm__("D_80070328 + 0x214");
extern unsigned char A15B100 __asm__("D_80070328 + 0x100");
extern unsigned char A15E535 __asm__("D_8006E535");
extern unsigned char* A15Models __asm__("D_8006EE2C");
int A15H40BCC() __asm__("func_80040BCC");
int A15H1A310() __asm__("func_8001A310");
extern int A15W10C __asm__("D_80070328 + 0x10C");
extern int A15WB4 __asm__("D_80070328 + 0xB4");
extern int A15WA4 __asm__("D_80070328 + 0xA4");
extern int (*A15Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A15H40954() __asm__("func_80040954");
extern int A15W50 __asm__("D_80070328 + 0x50");
extern int A15WBC __asm__("D_80070328 + 0xBC"), A15W1BC __asm__("D_80070328 + 0x1BC"),
    A15W60 __asm__("D_80070328 + 0x60");
extern short A15H148 __asm__("D_80070328 + 0x148");
int A15H43194() __asm__("func_80043194");
int A15MeasureVectorLength() __asm__("func_8004EDE8");
extern int A15WF4 __asm__("D_80070328 + 0xF4");
void func_level_15_80088D88(void) {
    register int work2 __asm__("$2"), work3 __asm__("$3"), work4 __asm__("$4");
    register int* state __asm__("$16");
    register int* buttons __asm__("$17");
    state = &A15W48;
    MATCHING_KEEP(state);
    switch (*state) {
        case 53:
        case 54:
            if (!A15H40994())
                goto set0;
            return;
        case 25:
            if (A15H40BCC())
                return;
            if (A15B1B5 && (A15NewButtons & 64))
                A15B1B6 = 1;
            if (A15WE4 >= 23) {
                work3 = A15W8C;
                work2 = A15WCC;
                work4 = work3 * work2;
                work3 = A15W90;
                work2 = A15WD0;
                work3 = work3 * work2;
                work2 = work4 + work3;
                if (work2 < 0)
                    goto set14;
            }
            work3 = A15WB0;
            if (work3 >= 3201) {
                work2 = A15WB4 * 2;
                work2 = work2 < work3;
                if (work2)
                    goto set14;
            }
            if (!A15WB8 && A15W54 >= 5) {
                A15H4BEF8(61);
                return;
            }
            if (A15B1B6) {
                if (A15W94 < 0)
                    goto set17;
                return;
            }
            if (A15W94 < 0)
                goto set22;
            return;
        case 33:
            if (A15H40994())
                return;
            if (!state[28]) {
                if (A15WE4 >= 23)
                    A15H4BEF8(7);
                if (A15WAC > 0) {
                speed33:
                    work3 = A15WB0;
                    work2 = work3 < 3841;
                    if (!work2)
                        goto set3;
                    work2 = work3 < 1921;
                    if (!work2)
                        goto set2;
                    goto set1;
                }
            speed0:
                work2 = A15WB0 < 1920;
                if (!work2)
                    goto set4;
                goto set0;
            }
            buttons = &A15NewButtons;
            MATCHING_KEEP(buttons);
            if (*buttons & 128)
                goto set22;
            if (A15H43194(4))
                goto set47;
            if (!A15WBC)
                goto set7;
            if (!state[93])
                goto set17;
            work2 = *buttons & 16;
            work4 = (int)state + 80;
            if (work2)
                goto set18;
            if (A15MeasureVectorLength((void*)work4, 1) < 1024)
                goto set7;
            if (*(short*)((char*)state + 256) >= 2)
                goto set35;
            if (state[1])
                goto set34;
            work4 = state[6];
            work2 = work4 < 365;
            if (!work2)
                goto set34;
            work2 = work4 < -364;
            if (!work2)
                return;
            goto set35;
        case 34:
            if (A15H40994())
                return;
            if (!state[28]) {
                if (A15WE4 >= 23)
                    A15H4BEF8(7);
                MATCHING_BARRIER_VOLATILE("memory");
                if (A15WAC <= 0)
                    goto speed0;
                MATCHING_BARRIER_VOLATILE("memory");
                goto speed33;
            }
            buttons = &A15NewButtons;
            MATCHING_KEEP(buttons);
            if (*buttons & 128)
                goto set22;
            if (A15H43194(4))
                goto set47;
            if (!A15WBC)
                goto set7;
            if (!A15W1BC)
                goto set17;
            work2 = *buttons & 16;
            work4 = (int)state + 80;
            if (work2)
                goto set18;
            if (A15MeasureVectorLength((void*)work4, 1) < 1024)
                goto set7;
            if (*(short*)((char*)state + 256) < 2)
                goto turn34;
        set35:
            A15H4BEF8(35);
            return;
        turn34:
            if (state[6] >= 256)
                return;
            if (!state[1])
                goto set33;
            return;
        case 35:
            if (A15H40994())
                return;
            if (!A15WB8) {
                if (A15WE4 >= 23)
                    A15H4BEF8(7);
                if (A15WAC > 0) {
                    work3 = A15WB0;
                    work2 = work3 < 3841;
                    if (!work2)
                        goto set3;
                    work2 = work3 < 1921;
                    if (work2)
                        goto set1;
                set2:
                    A15H4BEF8(2);
                    return;
                set1:
                    A15H4BEF8(1);
                    return;
                }
                if (A15WB0 < 1920)
                    goto set0;
            set4:
                A15H4BEF8(4);
                return;
            set0:
                A15H4BEF8(0);
                return;
            }
            buttons = &A15NewButtons;
            MATCHING_KEEP(buttons);
            if (*buttons & 128) {
            set22:
                A15H4BEF8(22);
                return;
            }
            if (A15H43194(4)) {
            set47:
                A15H4BEF8(47);
                return;
            }
            if (!A15WBC)
                goto set7;
            if (!A15W1BC) {
            set17:
                A15H4BEF8(17);
                return;
            }
            work2 = *buttons & 16;
            work4 = (int)state + 80;
            if (work2) {
            set18:
                A15H4BEF8(18);
                return;
            }
            if (A15MeasureVectorLength((void*)work4, 1) < 1024)
                goto set7;
            if (*(short*)((char*)state + 256) >= 2)
                return;
            if (state[1]) {
            set34:
                A15H4BEF8(34);
                return;
            }
            if (state[6] < -255)
                return;
        set33:
            A15H4BEF8(33);
            return;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (A15H40994())
                return;
            if ((A15NewButtons & 64) && A15W54 >= 9) {
                work4 = 6;
                goto partial43;
            }
            byte4 = &A15B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                work4 = 7;
                goto partial43;
            }
            if (!(A15NewButtons & 128))
                goto check44;
            if (A15W54 < 9)
                goto check44;
            work2 = *(int*)(A15Models + 220);
            byte4 -= 256;
            if (!work2)
                goto check44;
            if (!A15H1A310(byte4, 1024, 1, 0))
                goto set40;
            goto check44;
        partial43:
            A15H4BEF8(work4);
        check44:
            if (!A15E535)
                return;
            A15H4BEF8(44);
            return;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            work3 = A15W4C;
            work2 = 1;
            if (work3 != work2)
                goto other44;
            if (A15NewButtons & 0x850)
                goto callback44;
            if (A15W54 < 61)
                return;
        callback44:
            callback2 = A15Callback;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto fallback;
            callback2();
            return;
        other44:
            if (A15H40994())
                return;
            if ((A15NewButtons & 64) && A15W54 >= 9) {
                A15H4BEF8(6);
                return;
            }
            byte4 = &A15B100;
            MATCHING_KEEP(byte4);
            if (!*byte4)
                goto set7;
            if (!(A15NewButtons & 128))
                goto mode44;
            if (A15W54 < 9)
                goto mode44;
            work2 = *(int*)(A15Models + 220);
            byte4 -= 256;
            if (!work2)
                goto mode44;
            if (A15H1A310(byte4, 1024, 1, 0))
                goto mode44;
        set40:
            A15H4BEF8(40);
            return;
        mode44:
            work3 = A15Mode;
            work2 = 7;
            if (work3 == work2)
                return;
            if (A15E535)
                return;
            A15H4BEF8(43);
            return;
        }
        case 55:
            if (A15W54 < 101)
                return;
            A15H4BEF8(44);
            work2 = 1;
            A15W4C = work2;
            work2 = 8;
            A15W50 = work2;
            return;
        case 61:
            if (A15H40BCC())
                return;
            work2 = 1;
            work3 = A15W4C;
            if (work3 != work2)
                goto buttons61;
            if (A15WB8 >= 4)
                goto partial25;
            work2 = A15H40954(A15W10C);
            work3 = 9;
            if (work2 == work3)
                goto finalSpeed;
            A15W4C = 0;
            goto finalSpeed;
        buttons61:
            if (A15Buttons & 64) {
            partial25:
                A15H4BEF8(25);
                work2 = A15WB8;
                work3 = 3520;
                A15W94 = work3;
                A15WB8 = work2 + 1;
                return;
            }
            if (A15WB8 >= 4) {
                A15H4BEF8(25);
                return;
            }
            if (state[39] >= 23) {
                work3 = state[33];
                work2 = state[17];
                work4 = work3 * work2;
                work3 = state[34];
                work2 = state[18];
                work3 = work3 * work2;
                work2 = work4 + work3;
                if (work2 >= 0)
                    goto checkState;
            set7:
                A15H4BEF8(7);
                return;
            }
        checkState:
            {
                register int* pointer4 __asm__("$4");
                pointer4 = &A15W4C;
                MATCHING_KEEP(pointer4);
                work3 = *pointer4;
                work2 = 2;
                if (work3 == work2 && A15W54 >= 16)
                    *pointer4 = 0;
            }
            if (A15Buttons & 128)
                goto finalSpeed;
            work2 = A15Surface;
            if (work2 >= 0)
                goto finalSpeed;
            work2 = 2;
            work3 = A15W4C;
            if (work3 == work2)
                goto finalSpeed;
        set3:
            A15H4BEF8(3);
            return;
        finalSpeed:
            work3 = A15WB0;
            work2 = work3 < 3201;
            if (work2)
                return;
            work2 = A15WB4 * 2;
            work2 = work2 < work3;
            if (!work2)
                return;
        set14:
            A15H4BEF8(14);
            return;
        case 175:
            if (!A15W24)
                return;
            A15H4BEF8(176);
            A15W24 = 0;
            return;
        case 176:
            if (A15WF4 || !A15WB8)
                goto fallback;
            if (A15W54 < 91)
                return;
        fallback:
            A15H498C0();
            return;
    }
}
