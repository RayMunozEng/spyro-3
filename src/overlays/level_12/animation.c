#include "matching.h"
#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008864C.
 * Assembly SHA256 5886949620539da58842fd6e746cc383807a4f4cc1b40bf54bfea08967199fce.
 * AI-generated; not human reviewed. All1352 original instructions and
 * 50 selectors (bias9) are required. Original0xB8 frame retains scratch10..9C
 * and savedS0..S3. Verified source references cover20/28/58 and38; original9/19
 * preserve their distinct saved pointers, frame and scalar/store producers.
 * All458 original33/34/35 instructions retain exact scalar, helper, wrapped
 * angle, signed counter, spring and state joins. Original49 retains pointer210,
 * independent selector1 producers, helper/vector guards and shared94 ownership.
 * Ordinary C short product lifetimes preserve original low/high temporaries;
 * signed divisions800/5 remain ordinary C. No undefined HI/LO producer.
 * Typed aliases remain distinct. Empty initialized constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every original native/linked instruction, conditional/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics12Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics12RandSignedBetweenView1() __asm__("func_800363DC");
unsigned char Physics12UpdatePlayerGroundInputTargetsView1() __asm__("func_80040D10");
unsigned char Physics12ApproachPlayerTargetHeadingView1() __asm__("func_80041580");
unsigned char Physics12BlendPlayerHeadingFromInputVectorView1() __asm__("func_800416F4");
unsigned char Physics12ApproachPlayerTargetSpeedView1() __asm__("func_800417FC");
unsigned char Physics12BuildPlayerResponseVectorView1() __asm__("func_80041B64");
int Physics12InterpolateSineView1() __asm__("func_8004E9E4");
int Physics12InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics12TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics12MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics12ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics12ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
unsigned char Physics12ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics12CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics12AddVectorView1() __asm__("func_8004F194");
unsigned char Physics12SubtractVectorView1() __asm__("func_8004F1C8");
int Physics12CallRandView1() __asm__("rand");
extern unsigned char Physics12Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics12Data65920View1 __asm__("D_80065920");
extern void* Physics12Data6C570View1 __asm__("D_8006C570");
extern int Physics12Data6C640View1 __asm__("D_8006C640");
extern int Physics12Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics12Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics12Player0View1 __asm__("D_80070328");
extern int Physics12Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics12UpdateSmoothedInputPairView1() __asm__("func_800410F8");
int Physics12ApproachPlayerTargetSpeedView2() __asm__("func_800417FC");
int Physics12BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Physics12InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics12CopyVectorView2() __asm__("func_8004F178");
extern int Physics12Data6E538View1 __asm__("D_8006E538");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics12Player94View2 __asm__("D_80070328+0x94");
extern int Physics12PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics12Player64View1 __asm__("D_80070328+0x64");
extern int Physics12Player60View1 __asm__("D_80070328+0x60");
extern int Physics12PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics12Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics12Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics12Player5CView1 __asm__("D_80070328+0x5C");
int Physics12MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics12ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics12CopyVectorView3() __asm__("func_8004F178");
int Physics12AddVectorView2() __asm__("func_8004F194");
int Physics12SubtractVectorView2() __asm__("func_8004F1C8");
extern unsigned char Physics12Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics12Data65920View2 __asm__("D_80065920");
extern int Physics12Data6C514View1 __asm__("D_8006C514");
extern int Physics12Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics12Player0View2 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics12Player16CView1 __asm__("D_80070328+0x16C");
int Physics12TestSubdividedSegmentPathView1() __asm__("func_80013E38");
int Physics12UpdateSmoothedInputPairView2() __asm__("func_800410F8");
int Physics12ApproachPlayerTargetSpeedView3() __asm__("func_800417FC");
int Physics12BuildPlayerMovementVectorView2() __asm__("func_80041848");
int Physics12BuildPlayerResponseVectorView2() __asm__("func_80041B64");
int Physics12EvaluateClampedPlayerRootCurveView1() __asm__("func_8004E4E4");
int Physics12PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics12InterpolateSineView2() __asm__("func_8004E9E4");
int Physics12InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics12MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics12ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics12ShiftVectorLeftView1() __asm__("func_8004F0E8");
int Physics12CopyVectorView4() __asm__("func_8004F178");
int Physics12AddVectorView3() __asm__("func_8004F194");
int Physics12SubtractVectorView3() __asm__("func_8004F1C8");
extern int Physics12Data67630View1 __asm__("D_80067630");
extern int Physics12Data67634View1 __asm__("D_80067634");
extern int Physics12Data67638View1 __asm__("D_80067638");
extern int Physics12Data6C7C4View1 __asm__("D_8006C7C4");
extern int Physics12Data6FA38View1 __asm__("D_8006FA38");
extern int Physics12Data71908View1 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics12Player130View1 __asm__("D_80070328+0x130");
extern int Physics12Player144View1 __asm__("D_80070328+0x144");
extern short Physics12Player148View1 __asm__("D_80070328+0x148");
extern short Physics12Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics12Player14CView2 __asm__("D_80070328+0x14C");
extern int Physics12Player150View1 __asm__("D_80070328+0x150");
extern int Physics12Player154View1 __asm__("D_80070328+0x154");
extern int Physics12Player160View1 __asm__("D_80070328+0x160");
extern int Physics12Player48View1 __asm__("D_80070328+0x48");
extern int Physics12Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics12Player5CView2 __asm__("D_80070328+0x5C");
extern int Physics12Player60View2 __asm__("D_80070328+0x60");
extern int Physics12Player64View2 __asm__("D_80070328+0x64");
extern int Physics12Player8View1 __asm__("D_80070328+0x8");
extern int Physics12Player88View1 __asm__("D_80070328+0x88");
extern int Physics12Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics12Player90View1 __asm__("D_80070328+0x90");
extern int Physics12Player94View3 __asm__("D_80070328+0x94");
extern int Physics12PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics12PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics12PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics12PlayerF8View1 __asm__("D_80070328+0xF8");
extern int Physics12Player148View2 __asm__("D_80070328+0x148");
extern int Physics12Player210View1 __asm__("D_80070328+0x210");
extern int Physics12Player220View1 __asm__("D_80070328+0x220");
extern int Physics12Player98View1 __asm__("D_80070328+0x98");
extern int Physics12PlayerA0View1 __asm__("D_80070328+0xA0");
extern int Physics12PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics12PlayerCCView1 __asm__("D_80070328+0xCC");
extern int Physics12PlayerD0View1 __asm__("D_80070328+0xD0");
extern int Physics12PlayerE4View1 __asm__("D_80070328+0xE4");
extern unsigned char Physics12PlayerFCView1 __asm__("D_80070328+0xFC");
void func_level_12_8008864C(int slotIndex) {
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void* vectorAt40 __asm__("$16");
    register void* vectorAt30 __asm__("$17");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    register int below19 __asm__("$2");
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState9 __asm__("$17");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$19");
    register void* var_a0 __asm__("$4");
    register void* var_a0_2 __asm__("$4");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$18");
    int temp_v0;
    int temp_v0_2;
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    void* temp_v0_7;
    workWord2 = slotIndex * 16;
    globalPointer = &Physics12Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics12Data6C570View1 = (void*)workWord2;
    workWord2 = Physics12Field(&Physics12Player0View1, int*, 0x54);
    stateWord3 = Physics12Field(&Physics12Player0View1, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        case 20:
            globalVector80 = &Physics12Player0View1 + 0x80;
            Physics12ClearVectorView1(globalVector80);
            Physics12ClearVectorView1(globalVector80 + 0xC);
            if (Physics12Data6E044View1 != 7) {
                Physics12UpdatePlayerGroundInputTargetsView1(0x1200);
                Physics12BlendPlayerHeadingFromInputVectorView1();
                Physics12ApproachPlayerTargetHeadingView1(0x5A, 0x10);
                return;
            }
            return;
        default:
            return;
        case 0x9:
            globalField4CPointer = &Physics12Player0View1 + 0x4C;
            workWord3 = Physics12Field(&Physics12Player0View1, int*, 0x4C);
            MATCHING_KEEP(workWord3);
            workWord2 = 1;
            if (workWord3 == workWord2) {
                Physics12UpdatePlayerGroundInputTargetsView1(0xC80);
                Physics12ApproachPlayerTargetHeadingView1(0x28, 8);
                Physics12ApproachPlayerTargetSpeedView1(0x140, 0xC0);
                globalVector8CState9 = globalField4CPointer + 0x40;
                workWord2 = Physics12InterpolateCosineView1(
                    Physics12Field(&Physics12Player0View1, int*, 0xA4));
                workWord3 = Physics12Field(&Physics12Player0View1, int*, 0xB0);
                lowProduct0 = workWord3 * workWord2;
                workWord2 = lowProduct0 >> 12;
                MATCHING_KEEP(workWord2);
                originalFrame.sp10 = workWord2;
                workWord2 = Physics12InterpolateSineView1(
                    Physics12Field(&Physics12Player0View1, int*, 0xA4));
                workWord3 = Physics12Field(&Physics12Player0View1, int*, 0xB0);
                lowProduct1 = workWord3 * workWord2;
                workWord2 = lowProduct1 >> 12;
                MATCHING_KEEP(workWord2);
                originalFrame.sp14 = workWord2;
                Physics12SubtractVectorView1(&originalFrame.sp10, &originalFrame.sp10,
                                             globalVector8CState9);
                originalFrame.sp18 = 0;
                temp_v0 = Physics12MeasureVectorLengthView1(&originalFrame.sp10, 0);
                MATCHING_KEEP(globalField4CPointer);
                var_a0 = globalField4CPointer + 0x34;
                if (temp_v0 >= 0x281) {
                    Physics12ScaleVectorRatioQ15View1(&originalFrame.sp10, temp_v0, 0x280);
                    MATCHING_KEEP(globalField4CPointer);
                    var_a0 = globalField4CPointer + 0x34;
                }
                Physics12AddVectorView1(var_a0, globalVector8CState9, &originalFrame.sp10);
                Physics12BuildPlayerResponseVectorView1();
                if (combinedIndex < 0xD) {
                    MATCHING_OBSERVE(combinedIndex);
                    Physics12Field(&Physics12Player0View1, int*, 0x94) =
                        (int)(Physics12Field(&Physics12Player0View1, int*, 0x94) + 0x17);
                    return;
                }
                workWord2 = Physics12Player94View2 - 192;
                goto store94From2;
                return;
            }
            below19 = combinedIndex < 19;
            MATCHING_KEEP(globalField4CPointer);
            var_a0_2 = globalField4CPointer + 0x40;
            if (!below19) {
                MATCHING_OBSERVE(combinedIndex);
                call4 = globalField4CPointer + 0x34;
                MATCHING_KEEP(call4);
                workWord3 = Physics12Field(&Physics12Player0View1, int*, 0x8C);
                workWord2 = workWord3 * 7;
                workWord3 = Physics12Field(&Physics12Player0View1, int*, 0x90);
                Physics12Field(globalField4CPointer, int*, 0x34) = workWord2 << 5;
                workWord2 = workWord3 * 7;
                workWord3 = Physics12Field(&Physics12Player0View1, int*, 0x94);
                Physics12Field(&Physics12Player0View1, int*, 0x84) = workWord2 << 5;
                Physics12Field(&Physics12Player0View1, int*, 0x88) = (workWord3 * 7) << 5;
                Physics12ShiftVectorRightTowardZeroView1(call4, 8);
                MATCHING_KEEP(globalField4CPointer);
                var_a0_2 = globalField4CPointer + 0x40;
            }
            Physics12CopyVectorView1(var_a0_2, globalField4CPointer + 0x34);
            temp_v0_2 = Physics12Field(&Physics12Player0View1, int*, 0x94) - 0xC0;
            Physics12Field(&Physics12Player0View1, int*, 0x94) = temp_v0_2;
            if (temp_v0_2 < -0x2300) {
                workWord2 = -8960;
                __asm__ volatile("" ::"i"(0x800888BC) : "memory");
                Physics12Field(&Physics12Player0View1, int*, 0x94) = workWord2;
                return;
            }
            break;
        case 19: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3 = Physics12Data6E344View1;
            workWord2 = 13;
            if (workWord3 == workWord2) {
                workWord2 = Physics12Data6C514View1;
                if (workWord2)
                    return;
            }
            globalVector8CState20 = &Physics12Player0View2 + 8;
            workWord3 = Physics12Field(globalVector8CState20, int*, 0);
            workWord2 = Physics12Field(&Physics12Player0View2, int*, 0x144);
            numeric4 = workWord3 - workWord2;
            workWord2 = numeric4 < 1024;
            if (!workWord2)
                goto beyond19;
            workWord2 = Physics12Player94View2;
            workWord2 += 128;
            Physics12Player94View2 = workWord2;
            workWord2 = workWord2 < 4801;
            __asm__("" : "=r"(numeric4) : "0"(numeric4), "r"(workWord2));
            if (!workWord2) {
                workWord2 = 4800;
                Physics12Player94View2 = workWord2;
            }
            lowProduct2 = numeric4 * numeric4;
            vectorAt30 = &originalFrame.sp20;
            call4 = vectorAt30;
            workWord3 = Physics12Field(&Physics12Player0View2, int*, 0x148);
            MATCHING_OBSERVE3(workWord2, workWord3, call4);
            workWord2 = lowProduct2 >> 11;
            angle16 = workWord2 + workWord3;
            Physics12Player64View1 = angle16;
            __asm__ volatile(""
                             : "=r"(globalVector8CState20)
                             : "0"(globalVector8CState20), "r"(call4)
                             : "memory");
            Physics12CopyVectorView3(call4, globalVector8CState20 + 340);
            call4 = vectorAt30;
            call5 = call4;
            Physics12SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics12MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x800889AC) : "memory");
            numeric6 = 1024;
            goto limit19;
        beyond19:
            numeric5 = Physics12Field(&Physics12Player0View2, int*, 0x14C);
            workWord2 = workWord3 - numeric5;
            workWord2 = workWord2 < -1024;
            numeric6 = numeric5 - workWord3;
            if (!workWord2)
                goto curve19;
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x800889D0));
            workWord2 = Physics12Player4CView1;
            workWord3 = 1;
            if (!workWord2) {
                workWord2 = Physics12Field(&Physics12Player0View2, int*, 0x148);
                Physics12Player4CView1 = workWord3;
                workWord2 += 512;
                Physics12Field(&Physics12Player0View2, int*, 0x148) = workWord2;
            }
            workWord2 = Physics12Player94View2;
            workWord2 += 128;
            Physics12Player94View2 = workWord2;
            workWord2 = workWord2 < 4801;
            if (!workWord2)
                Physics12Player94View2 = 4800;
            workWord2 = Physics12Field(&Physics12Player0View2, int*, 0x150);
            numeric6 = numeric4 - 1024;
            workWord3 = workWord2 * numeric6;
            workWord2 = Physics12Field(&Physics12Player0View2, int*, 0x154);
            workWord2 = workWord3 / workWord2;
            vectorAt30 = &originalFrame.sp20;
            call4 = vectorAt30;
            workWord3 = Physics12Field(&Physics12Player0View2, int*, 0x148);
            angle16 = workWord3 + workWord2;
            workWord2 = (numeric6 << 10) >> 10;
            workWord2 = angle16 + workWord2;
            angle16 = workWord2 & 4095;
            Physics12Player64View1 = angle16;
            Physics12CopyVectorView3(call4, globalVector8CState20 + 340);
            call4 = vectorAt30;
            call5 = call4;
            Physics12SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics12MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x80088AE4) : "memory");
            numeric6 = 1024;
            goto limit19;
        curve19:
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x80088AEC));
            workWord2 = (numeric6 * 4800) >> 10;
            Physics12Player94View2 = workWord2;
            workWord2 = Physics12Player16CView1;
            numeric7 = Physics12Field(&Physics12Player0View2, int*, 0x168);
            workWord3 = Physics12Field(&Physics12Player0View2, int*, 0x158);
            workWord2 &= 127;
            numeric4 = numeric7 << 1;
            Physics12Player16CView1 = workWord2;
            workWord2 = *(short*)(&Physics12Data65920View2 + numeric4);
            workWord3 += 1024;
            product10 = workWord3 * workWord2;
            square8 = numeric6 * numeric6;
            workWord2 = product10 >> 12;
            originalFrame.sp20 = workWord2;
            workWord2 = *(short*)(&Physics12Data658A0View2 + numeric4);
            workWord3 = workWord3 * workWord2;
            vectorAt30 = &originalFrame.sp20;
            call5 = vectorAt30;
            numeric7 <<= 4;
            call4 = vectorAt30;
            __asm__(""
                    : "=r"(globalVector8CState20)
                    : "0"(globalVector8CState20), "r"(call4), "r"(call5));
            numeric6 = (int)globalVector8CState20 + 340;
            workWord2 = square8 >> 11;
            angle16 = numeric7 - workWord2;
            workWord2 = workWord3 >> 12;
            originalFrame.sp24 = workWord2;
            Physics12AddVectorView2(call4, call5, numeric6, numeric7);
            call4 = vectorAt30;
            call5 = call4;
            Physics12Player64View1 = angle16;
            Physics12SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics12MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 2049;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            numeric6 = 2048;
        limit19:
            Physics12ScaleVectorRatioQ15View2(call4, call5, numeric6);
        commit19:
            workWord2 = originalFrame.sp20;
            workWord3 = originalFrame.sp24;
            Physics12Field(&Physics12Player0View2, int*, 0x8C) = workWord2;
            Physics12Field(&Physics12Player0View2, int*, 0x90) = workWord3;
            return;
        }
        case 28:
            Physics12UpdatePlayerGroundInputTargetsView1(0xC80);
            Physics12ApproachPlayerTargetHeadingView1(0x28, 8);
            Physics12ApproachPlayerTargetSpeedView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics12Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics12InterpolateCosineView1(Physics12Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics12Field(&Physics12Player0View1, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics12Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp30 = workWord2;
            workWord2 = Physics12InterpolateSineView1(call4);
            workWord3 = Physics12Field(&Physics12Player0View1, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp34 = workWord2;
            Physics12SubtractVectorView1(&originalFrame.sp30, &originalFrame.sp30, globalVector8C);
            originalFrame.sp38 = 0;
            temp_v0_4 = Physics12MeasureVectorLengthView1(&originalFrame.sp30, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics12ScaleVectorRatioQ15View1(&originalFrame.sp30, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics12AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp30);
            Physics12BuildPlayerResponseVectorView1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics12Field(&Physics12Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics12Field(&Physics12Player0View1, int*, 0x94) - 0xC0;
            }
            Physics12Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics12Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics12Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp50;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics12CallRandView1() & 0xFF)) {
                        workWord2 = Physics12RandSignedBetweenView1(0, 0xC);
                        call4 = globalByteE + 0x22;
                        workWord3 = *globalByteE;
                        MATCHING_KEEP(workWord3);
                        call5 = vectorAt40;
                        MATCHING_KEEP2(call4, call5);
                        workWord3 += 0x80;
                        MATCHING_KEEP(workWord3);
                        workWord3 += workWord2;
                        MATCHING_KEEP(workWord3);
                        workWord3 = (workWord3 & 0xFF) * 2;
                        signedTableWord = *(short*)(&Physics12Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp40 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics12Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp48 = 0xE;
                        originalFrame.sp50 = -0x12C;
                        originalFrame.sp54 = 0;
                        originalFrame.sp58 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp44 = (workWord3 * 5) >> 0xA;
                        Physics12TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp50 += Physics12RandSignedBetweenView1(0, 0x50);
                        originalFrame.sp54 += Physics12RandSignedBetweenView1(0, 0x50);
                        originalFrame.sp58 += Physics12RandSignedBetweenView1(0, 0x50);
                        Physics12AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp40);
                        Physics12Field(temp_v0_5, signed char*, 2) = 8;
                        Physics12Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 58:
            globalFieldB8PointerState20 = &Physics12Player0View1 + 0xB8;
            if (Physics12Field(&Physics12Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp40;
                Physics12ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics12SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp48 = 0;
                temp_v0_6 = Physics12MeasureVectorLengthView1(&originalFrame.sp40, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics12ScaleVectorRatioQ15View1(&originalFrame.sp40, temp_v0_6, 0x40);
                }
                originalFrame.sp48 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics12AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp40);
                Physics12CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics12ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics12ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics12Field(&Physics12Player0View1, int*, 0x94) < -0x2300) {
                Physics12Field(&Physics12Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics12Field(&Physics12Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics12Data6C640View1 & 1)) {
                originalFrame.sp60 = 0;
                originalFrame.sp64 = 0;
                originalFrame.sp68 = 0xE;
                Physics12CopyVectorView1(&originalFrame.sp70,
                                         (&Physics12Player0View1 + 0x94) - 0x94);
                originalFrame.sp70 += Physics12RandSignedBetweenView1(0, 0x12C);
                originalFrame.sp74 += Physics12RandSignedBetweenView1(0, 0x12C);
                originalFrame.sp78 += Physics12RandSignedBetweenView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp70, &originalFrame.sp60);
                Physics12Field(temp_v0_7, signed char*, 2) = 6;
                Physics12Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 33:
        case 34:
        case 35: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta18 __asm__("$18");
            register int delta19 __asm__("$19");
            register void* pointer17 __asm__("$17");
            register void* pointer16 __asm__("$16");
            register int limit16 __asm__("$16");
            int originalLow;
            call4 = &originalFrame.sp60;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            pointer17 = &Physics12Player154View1;
            Physics12UpdateSmoothedInputPairView2(call4, pointer17, 0);
            workWord2 = originalFrame.sp64;
            numeric4 = Physics12Player94View3;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp60;
            numeric4 -= 1024;
            originalFrame.sp70 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                pointer16 = &originalFrame.sp68;
                call4 = pointer16;
                call5 = pointer16;
                __asm__ volatile(""
                                 : "=r"(pointer17)
                                 : "0"(pointer17), "r"(call4), "r"(call5)
                                 : "memory");
                pointer17 -= 340;
                call6 = pointer17;
                workWord2 = Physics12Player8CView1;
                workWord3 = Physics12Player90View1;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp68 = workWord2;
                originalFrame.sp6C = workWord3;
                Physics12AddVectorView3(call4, call5, call6);
                if (!Physics12TestSubdividedSegmentPathView1(pointer17, pointer16, 2)) {
                    workWord2 = Physics12Player8View1;
                    workWord3 = Physics12Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp64 = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp64 = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp64;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics12PlayerF8View1;
            workWord3 = Physics12Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics12Player60View2;
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
            call4 = &Physics12Player64View2;
            workWord2 = Physics12Field(call4, int*, 0);
            workWord3 = Physics12Player60View2;
            Physics12PlayerA8View1 = delta19;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics12Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics12Player60View2 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics12Player60View2 = workWord2;
            }
            workWord2 = Physics12Player60View2;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics12Player60View2 = -800;
            workWord2 = Physics12Player60View2;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics12Player60View2 = 800;
            workWord2 = Physics12Data6FA38View1;
            if (workWord2 >= 0)
                goto nonnegative33;
            workWord3 = Physics12Player60View2;
            if (workWord3 >= 0)
                goto positive33;
            numeric4 = Physics12Data67634View1;
            workWord2 = Physics12Data67630View1;
            workWord2 = numeric4 - workWord2;
            goto quotient33;
        positive33:
            if (workWord3 <= 0)
                goto zero33;
            workWord2 = Physics12Data67638View1;
            numeric4 = Physics12Data67634View1;
            workWord2 -= numeric4;
        quotient33:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics12PlayerACView2 = numeric4;
            goto modifier33;
        zero33:
            workWord2 = Physics12Data67634View1;
            Physics12PlayerACView2 = workWord2;
        modifier33:
            workWord3 = Physics12Data6C7C4View1;
            workWord2 = 2;
            if (workWord3 != workWord2)
                goto subtract33;
            numeric4 = Physics12Data67634View1;
            workWord3 = numeric4 / 5;
            call5 = &Physics12PlayerACView2;
            workWord2 = Physics12Field(call5, int*, 0);
            __asm__ volatile("" ::"i"(0x800892D8) : "memory");
            workWord2 += workWord3;
            goto storeModifier33;
        subtract33:
            if (workWord3)
                goto speed33;
            numeric4 = Physics12Data67634View1;
            workWord3 = numeric4 / 5;
            call5 = &Physics12PlayerACView2;
            workWord2 = Physics12Field(call5, int*, 0);
            workWord2 -= workWord3;
        storeModifier33:
            Physics12Field(call5, int*, 0) = workWord2;
        speed33:
            call5 = &Physics12Player144View1;
            workWord2 = Physics12PlayerACView2;
            numeric4 = Physics12PlayerB0View2;
            workWord3 = Physics12Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics12Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics12PlayerB0View2 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics12PlayerB0View2 = 2048;
            workWord2 = Physics12PlayerB0View2;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics12PlayerB0View2 = 19200;
            goto rotation33;
        nonnegative33:
            numeric4 = Physics12Player8View1;
            limit16 = 0;
            workWord2 = Physics12EvaluateClampedPlayerRootCurveView1(numeric4);
            workWord3 = Physics12Player148View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            numeric4 = workWord2;
            MATCHING_KEEP(numeric4);
            Physics12PlayerACView2 = numeric4;
            numeric5 = workWord3;
            if (!workWord3)
                goto zeroCounter33;
            workWord2 = 0x60000;
            Physics12Player130View1 = workWord2;
            workWord2 = numeric5 - 1;
            Physics12Player148View1 = workWord2;
            workWord2 <<= 16;
            if (workWord2 > 0)
                goto positiveCounter33;
            workWord3 = Physics12PlayerB0View2;
            workWord2 = workWord3 - numeric4;
            workWord2 = workWord2 < 192;
            if (workWord2) {
                workWord2 = numeric4 + 8192;
                Physics12PlayerB0View2 = workWord2;
                Physics12Player148View1 = 0;
                goto counterClamp33;
            }
            workWord2 = workWord3 - 192;
            Physics12PlayerB0View2 = workWord2;
            workWord2 = 1;
            Physics12Player148View1 = workWord2;
            goto counterClamp33;
        positiveCounter33:
            workWord2 = numeric4 + 8192;
            Physics12PlayerB0View2 = workWord2;
            limit16 = 96;
            goto counterClamp33;
        zeroCounter33:
            Physics12PlayerB0View2 = numeric4;
            __asm__ volatile("" : "=r"(limit16) : "0"(limit16) : "$3", "memory");
            Physics12Player130View1 = 0;
        counterClamp33:
            globalPointer = &Physics12PlayerB0View2;
            workWord2 = Physics12Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 22785;
            if (!workWord2)
                Physics12Field(globalPointer, int*, 0) = 22784;
            workWord2 = Physics12Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 2048;
            if (workWord2)
                Physics12Field(globalPointer, int*, 0) = 2048;
            numeric5 = Physics12Player14CView2;
            workWord3 = Physics12Player150View1;
            workWord2 = limit16 - numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics12Player150View1 = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics12Player14CView2 = numeric5;
            if (numeric5 < 0)
                Physics12Player14CView2 = 0;
            workWord2 = Physics12Player14CView2;
            workWord2 = workWord2 < 97;
            if (!workWord2)
                Physics12Player14CView2 = 96;
        rotation33:
            workWord2 = Physics12Player148View1;
            workWord2 = workWord2 < 2;
            if (workWord2)
                goto spring33;
            workWord3 = Physics12Player14AView1;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 3;
            MATCHING_KEEP(workWord2);
            workWord3 = Physics12Player5CView2;
            workWord2 <<= 11;
            Physics12Player154View1 = workWord2;
            workWord2 >>= 6;
            workWord3 += workWord2;
            workWord3 &= 4095;
            workWord2 = workWord3 < 2049;
            Physics12Player5CView2 = workWord3;
            if (workWord2)
                goto rotationDone33;
            workWord2 = workWord3 - 4096;
            goto storeAngle33;
        spring33:
            workWord2 = Physics12InterpolateCosineView3(Physics12Player60View2);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            originalLow = delta19 * workWord2;
            workWord3 = Physics12Player154View1;
            numeric5 = Physics12Player5CView2;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = originalLow >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics12Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics12Player5CView2 = numeric5;
            if (workWord2)
                goto rotationDone33;
            workWord2 = numeric5 - 4096;
        storeAngle33:
            Physics12Player5CView2 = workWord2;
        rotationDone33:
            Physics12BuildPlayerMovementVectorView2();
            call5 = &Physics12Player4CView2;
            numeric4 = Physics12Field(call5, int*, 0);
            if (numeric4)
                goto active33;
            workWord2 = (int)Physics12Data6C570View1;
            workWord2 = Physics12Field((void*)workWord2, int*, 4) & 64;
            if (!workWord2)
                goto end33;
            workWord2 = Physics12PlayerF8View1;
            workWord3 = Physics12Player8View1;
            workWord2 -= 512;
            workWord3 = workWord3 < workWord2;
            if (!workWord3)
                goto end33;
            workWord3 = Physics12Player48View1;
            workWord2 = 33;
            if (workWord3 != workWord2)
                goto end33;
            workWord2 = 1;
            Physics12Field(call5, int*, 0) = workWord2;
            __asm__ volatile("" ::: "$4", "memory");
            Physics12Player160View1 = 0;
            goto end33;
        active33:
            workWord2 = Physics12Player8View1;
            workWord3 = Physics12PlayerF8View1;
            workWord2 = workWord2 < workWord3;
            if (workWord2) {
                workWord2 = 1;
                goto activeRemainder33;
            }
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics12Field(call5, int*, 0) = 0;
            goto end33;
        activeRemainder33:
            if (numeric4 != workWord2)
                goto decline33;
            workWord2 = Physics12Player160View1;
            workWord2 += 512;
            Physics12Player160View1 = workWord2;
            workWord2 = workWord2 < 6144;
            if (!workWord2) {
                workWord2 = 6144;
                Physics12Player160View1 = workWord2;
                workWord2 = 2;
                Physics12Field(call5, int*, 0) = workWord2;
            }
            goto add88;
        decline33:
            workWord2 = Physics12Player160View1;
            workWord2 -= 256;
            Physics12Player160View1 = workWord2;
            if (workWord2 <= 0) {
                Physics12Player160View1 = 0;
                Physics12Field(call5, int*, 0) = 0;
            }
        add88:
            {
                register void* pointer2 __asm__("$2");
                pointer2 = &Physics12Player88View1;
                workWord3 = Physics12Field(pointer2, int*, 0);
                numeric4 = Physics12Player160View1;
                workWord3 += numeric4;
                Physics12Field(pointer2, int*, 0) = workWord3;
            }
        end33:
            Physics12BuildPlayerResponseVectorView2();
            return;
        }
        case 38: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics12UpdateSmoothedInputPairView1(&originalFrame.sp80, &Physics12Player14CView1, 0);
            workWord3 = Physics12Player60View1;
            workWord2 = workWord3 + 800;
            workWord2 = (unsigned int)workWord2 < 1825;
            if (!workWord2) {
                MATCHING_BARRIER_VOLATILE("$2");
                globalVector80 = 0;
                numeric5 = 23;
                goto rotate38;
            }
            workWord2 = workWord3 < 801;
            if (!workWord2) {
                workWord3 = originalFrame.sp84;
                workWord3 = -workWord3;
                MATCHING_KEEP(workWord3);
                workWord2 = workWord3 * 23;
                workWord3 = originalFrame.sp80;
                MATCHING_OBSERVE2(workWord3, workWord2);
                numeric5 = workWord2 >> 8;
                goto lateral38;
            }
            workWord3 = originalFrame.sp84;
            workWord3 = -workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 23;
            workWord3 = originalFrame.sp80;
            MATCHING_OBSERVE2(workWord3, workWord2);
            numeric5 = workWord2 >> 7;
        lateral38:
            workWord2 = workWord3 * 30;
            globalVector80 = (void*)(workWord2 >> 7);
        rotate38:
            call4 = &Physics12Player64View1;
            workWord2 = Physics12Field(call4, int*, 0);
            workWord3 = Physics12Player60View1;
            workWord2 += (int)globalVector80;
            workWord2 &= 4095;
            workWord3 += numeric5;
            workWord3 &= 4095;
            Physics12Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics12Player60View1 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics12Player60View1 = workWord2;
            }
            workWord2 = Physics12Data6E538View1;
            workWord3 = 6144;
            Physics12PlayerACView1 = workWord3;
            workWord2 &= 192;
            if (workWord2) {
                workWord2 = 12800;
                Physics12PlayerACView1 = workWord2;
            }
            workWord3 = Physics12Player4CView1;
            workWord2 = 2;
            if (workWord3 == workWord2) {
                Physics12ApproachPlayerTargetSpeedView2(320, 192);
                workWord2 = Physics12PlayerB0View1 < 6145;
                if (workWord2)
                    Physics12Player4CView1 = 0;
            } else
                Physics12ApproachPlayerTargetSpeedView2(320, 80);
            globalFieldA4Pointer = &Physics12Player60View1;
            workWord2 =
                Physics12InterpolateCosineView2(Physics12Field(globalFieldA4Pointer, int*, 0));
            workWord2 <<= 5;
            workWord2 = -workWord2;
            lowProduct5 = (int)globalVector80 * workWord2;
            workWord3 = Physics12Player14CView1;
            numeric5 = Physics12Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = lowProduct5 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics12Player14CView1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics12Player5CView1 = numeric5;
            if (!workWord2) {
                workWord2 = numeric5 - 4096;
                Physics12Player5CView1 = workWord2;
            }
            workWord2 = Physics12Player5CView1;
            workWord2 = workWord2 < -768;
            if (workWord2) {
                workWord2 = -768;
                Physics12Player5CView1 = workWord2;
            }
            workWord2 = Physics12Player5CView1;
            workWord2 = workWord2 < 769;
            if (!workWord2) {
                workWord2 = 768;
                Physics12Player5CView1 = workWord2;
            }
            Physics12BuildPlayerMovementVectorView1(numeric4, numeric5);
            Physics12CopyVectorView2(globalFieldA4Pointer + 44, globalFieldA4Pointer + 32);
            return;
        }
        case 49: {
            register void* pointer17 __asm__("$17");
            register void* pointer18 __asm__("$18");
            register void* pointer16 __asm__("$16");
            int product49a, product49b;
            pointer17 = &Physics12Player210View1;
            workWord2 = Physics12Field(pointer17, int*, 0) & 1024;
            call6 = (void*)1;
            if (!workWord2)
                goto noFlag49;
            MATCHING_KEEP(pointer17);
            call4 = (void*)Physics12Field(pointer17, int*, 12);
            call5 = (void*)Physics12Player220View1;
            __asm__ volatile(""
                             : "=r"(pointer17)
                             : "0"(pointer17), "r"(call4), "r"(call5)
                             : "memory");
            pointer17 += 12;
            workWord2 = Physics12PlanarHeadingLookupView1(call4, call5, call6);
            pointer16 = &originalFrame.sp88;
            call4 = pointer16;
            Physics12Player148View2 = workWord2;
            Physics12CopyVectorView4(call4, pointer17);
            Physics12ShiftVectorLeftView1(pointer16, 6);
            workWord2 = Physics12MeasureVectorLengthView3(pointer16, 1);
            Physics12PlayerB0View2 = workWord2;
            call4 = (void*)128;
            goto prepare49;
        noFlag49:
            MATCHING_KEEP(call6);
            workWord2 = Physics12PlayerE4View1;
            workWord2 = workWord2 < 11;
            if (workWord2)
                goto lowMode49;
            call4 = (void*)Physics12PlayerCCView1;
            call5 = (void*)Physics12PlayerD0View1;
            __asm__ volatile("" ::"i"(0x80089A0C) : "memory");
            call6 = (void*)1;
            goto query49;
        lowMode49:
            call4 = (void*)Physics12Player98View1;
            call5 = call4;
        query49:
            workWord2 = Physics12PlanarHeadingLookupView1(call4, call5, call6);
            Physics12Player148View2 = workWord2;
            call4 = (void*)128;
        prepare49:
            call5 = (void*)192;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            pointer18 = &Physics12PlayerACView2;
            workWord2 = 3840;
            Physics12Field(pointer18, int*, 0) = workWord2;
            Physics12ApproachPlayerTargetSpeedView3(call4, call5);
            call4 = (void*)Physics12Player148View2;
            pointer17 = pointer18 - 44;
            workWord2 = Physics12InterpolateCosineView3(call4);
            workWord3 = Physics12PlayerB0View2;
            product49a = workWord3 * workWord2;
            call4 = (void*)Physics12Player148View2;
            workWord2 = product49a >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp88 = workWord2;
            workWord2 = Physics12InterpolateSineView2(call4);
            workWord3 = Physics12PlayerB0View2;
            product49b = workWord3 * workWord2;
            pointer16 = &originalFrame.sp88;
            call4 = pointer16;
            call5 = pointer16;
            call6 = pointer17;
            originalFrame.sp90 = 0;
            workWord2 = product49b >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp8C = workWord2;
            Physics12SubtractVectorView3(call4, call5, call6);
            originalFrame.sp90 = 0;
            call5 = (void*)Physics12MeasureVectorLengthView3(pointer16, 0);
            workWord2 = (int)call5 < 257;
            call4 = pointer17;
            if (!workWord2) {
                Physics12ScaleVectorRatioQ15View3(pointer16, call5, 256);
                call4 = pointer17;
            }
            call5 = pointer17;
            Physics12AddVectorView3(call4, call5, pointer16);
            workWord2 = Physics12PlayerFCView1;
            if (workWord2)
                goto scalar49;
            workWord2 = Physics12PlayerB8View1;
            call4 = pointer18 - 32;
            if (!workWord2)
                goto vector49;
        scalar49:
            workWord2 = Physics12PlayerA0View1;
            workWord2 -= 192;
        store94From2:
            Physics12Player94View3 = workWord2;
            return;
        vector49:
            call5 = pointer17;
            Physics12AddVectorView3(call4, call5, pointer18 + 60);
            return;
        }
    }
}
#undef Physics12Field

void Callback12BuildNegatedNormalizedPlayerVector(int) __asm__("func_80043A38");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089B6C callback.
 * Reuses verified10 particle, verified13 table and verified43 timer producers.
 * Original12 supplies dispatch and byte colour selectors: nextFrame unsigned
 * comparison10/parity1, colour bytesFF/40/20. Count148-B0 and source-98 are byte
 * offsets, table stride2C and flag10 retained, original timer helper selectorA.
 * Stack vectorSP10, frame38 and reserved spacing follow original output;
 * reserved words establish no retail variable meaning. Empty constraints
 * emit no instructions; preserve original register lifetimes/load scheduling.
 * Units, helper meanings, sound semantics and caller cadence unresolved.
 * Acceptance: every original code/local jump/table word, strict complete TU,
 * complete EXE and every retail overlay hash. Runtime parity remains open.
 */
extern Spyro Callback12Player __asm__("D_80070328");
int Callback12SoundHandleMatchesIdInStates1Or2(int soundId, int index) __asm__("func_8003BF6C");
void Callback12ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback12UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback12UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
extern int D_8006C648;
extern unsigned char Callback12Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback12Values[] __asm__("D_8006FCF0");
extern short Callback12Count __asm__("D_80070328+0x148");
void Callback12ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
void func_level_12_80089B6C(void) {
    Vector3D localVector;
    int reservedStackWords[2];
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$18");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$17");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int, int, Vector3D*, Vector3D*)__asm__("$2");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    register int flagOffset __asm__("$3");

    switch (Callback12Player.animationState) {
        case 0x14:
            if (func_800438F4() == 0)
                func_80043728();
            Callback12UpdatePlayerCollisionResponse();
            Callback12Player.unk9a = 0;
            Callback12UpdatePlayerSurfaceState();
        clearSharedValue:
            Callback12Player.unk4[0] = 0;
            return;
        case 0x9:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            if (Callback12Player.unk5 == 1)
                Callback12ProbePlayerContactSegment();
            else
                Callback12BuildNegatedNormalizedPlayerVector(0xC00);
            if ((unsigned char)Callback12Player.bodyAnimation.nextFrame < 10U) {
                Callback12Player.cheatColour.a = 255;
                if (Callback12Player.bodyAnimation.nextFrame & 1) {
                    Callback12Player.cheatColour.b = 255;
                    Callback12Player.cheatColour.g = 255;
                    Callback12Player.cheatColour.r = 255;
                } else {
                    Callback12Player.cheatColour.b = 64;
                    Callback12Player.cheatColour.g = 64;
                    Callback12Player.cheatColour.r = 64;
                }
            }
            goto clearSharedValue;
        case 0x13:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            Callback12ProbePlayerContactSegment();
            goto clearSharedValue;
        case 0x1C:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            Callback12ProbePlayerContactSegment();
            if (Callback12Player.unk7a[3].z < 0 && Callback12Player.animationStateFrames >= 4)
                Callback12Player.unk5 = 1;
            goto clearSharedValue;
        case 0x21:
        case 0x22:
        case 0x23:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            Callback12ProbePlayerContactSegment();
            if (SpawnParticle != 0) {
                countBase = (unsigned char*)&Callback12Count;
                if (*(short*)countBase == 0)
                    goto clearSharedValue;
                secondLimit = 1;
                if (*(short*)countBase >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    MATCHING_KEEP(countBase);
                    sourceBytes = countBase - 0xB0;
                    do {
                        func_8004F178((&localVector), (Vector3D*)sourceBytes);
                        Callback12ShiftVectorRightTowardZero((&localVector), 7);
                        iteration += 1;
                        sample = rand();
                        component = localVector.x;
                        sample &= 254;
                        component -= 127;
                        component += sample;
                        MATCHING_KEEP(component);
                        localVector.x = component;
                        sample = rand();
                        component = localVector.y;
                        sample &= 254;
                        component -= 127;
                        component += sample;
                        MATCHING_KEEP(component);
                        localVector.y = component;
                        sample = rand();
                        kind = 1;
                        subtype = 0x17;
                        position = sourceBytes - 0x98;
                        __asm__(""
                                : "=r"(kind), "=r"(subtype), "=r"(position)
                                : "0"(kind), "1"(subtype), "2"(position), "r"(sample)
                                : "$3", "memory");
                        component = localVector.z;
                        __asm__("" : "=r"(component) : "0"(component), "r"(sample));
                        sample &= 254;
                        component -= 127;
                        component += sample;
                        __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                        particles = SpawnParticle;
                        MATCHING_KEEP_VOLATILE_CLOBBER(particles, "$7");
                        vector = (&localVector);
                        MATCHING_KEEP3(particles, vector, component);
                        localVector.z = component;
                        particles(kind, subtype, (Vector3D*)position, vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
        case 0x26:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            descriptor = &Callback12Player.unk22[2];
            if (Callback12SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback12Values + valueOffset);
                {
                    register int below __asm__("$2") = decreasingValue < 0xC8;
                    MATCHING_KEEP_VOLATILE_CLOBBER(below, "$4");
                    if (!below)
                        goto setDecreasingFlag;
                    tableValue = decreasingValue - 0xC8;
                    goto storeDecreasingValue;
                }
                goto setDecreasingFlag;
            storeDecreasingValue:
                *(int*)(Callback12Values + valueOffset) = tableValue;
            setDecreasingFlag:
                flagOffset = *descriptor * 0x2C;
                Callback12Flags[flagOffset] = Callback12Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x31:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            Callback12BuildNegatedNormalizedPlayerVector(0xC00);
            if (func_80040954(Callback12Player.unk11[2]) == 0xA) {
                Callback12Player.union144.a.unk13cb = 0;
            } else {
                Callback12Player.union144.a.unk13cb += D_8006C648;
            }
            Callback12Player.unk4[0] = 0;
            if (Callback12SoundHandleMatchesIdInStates1Or2((int)D_8006C654->unk32,
                                                           Callback12Player.unk22[2]) == 0) {
                Callback12Player.unk22[2] = PlaySound((int)D_8006C654->unk32, 0, 4);
                Callback12Player.unk22[3] = (int)D_8006C654->unk32;
                return;
            }
            break;
        case 0x3A:
            Callback12UpdatePlayerCollisionResponse();
            Callback12UpdatePlayerSurfaceState();
            Callback12Player.cheatColour.a = 255;
            Callback12Player.unk4[0] = 0;
            Callback12Player.cheatColour.b = 32;
            Callback12Player.cheatColour.g = 32;
            Callback12Player.cheatColour.r = 32;
            return;
        default:
            return;
    }
}


/**
 * func_level_12_80089FE4() - ???() - MATCHING
 * Ready to add. Currently appropriate for introducing as an animation.inc.h.
 * https://decomp.me/scratch/CMQIW
 */
#define LEVEL_ID 12
#define PlaySpyroSounds_level_12 func_level_12_80089FE4
#include "overlay/animation.inc.h"

/**
 * func_level_12_8008A0EC() - ???() - MATCHING
 * Ready to add. The case order seems to be a mess here.
 * https://decomp.me/scratch/pcTDp
 */
extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_12_8008A0EC(int index) {
    Vector3D* vector;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 9: {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0x4C);
            MATCHING_KEEP(state);
            if (*state == 1)
                goto reset;
            vector = (Vector3D*)((char*)state + 0x80);
            goto apply;
        }
        case 0x14:
        case 0x31:
        case 0x3A:
            vector = &spyro.unk9e;
            goto apply;
        case 0x13:
        case 0x1C:
        reset:
            vector = 0;
        apply:
            func_80043ABC(vector);
            break;
    }
}

extern short Transition12SignedA[] __asm__("D_800658A0");
extern short Transition12SignedB[] __asm__("D_80065920");
extern int Transition12RawX __asm__("D_80070328+0x8C");
int Transition12GetSurfaceTypeFromFlags(int) __asm__("func_80040954");
void Transition12ShiftVectorLeft(Vector3D*, int) __asm__("func_8004F0E8");
extern int Transition12_D_8006E528 __asm__("D_8006E528");
int Transition12PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A188 transition.
 * Reuses verified47 private words0/4/8 and verified27 case9/1C producers.
 * Original12 supplies saved movement pointer and selectors21/22/23/26/31.
 * All pointer arithmetic is in bytes: header10C-74/-80/+110, movement50+
 * 104/48/FC/10C and lengthB0-30/-18; slide copies8C from80. Movement6,
 * signed table halfwords/shift1, signed clamp800/4B00 and yaw wrapFFF follow
 * original target instructions. Empty constraints emit no instructions and
 * preserve original scheduling/register lifetimes. Helper meanings, units,
 * audio semantics, caller cadence and live/runtime behavior remain unresolved.
 * Acceptance requires all original code/local jumps/table words, strict full
 * translation unit and complete EXE/every original overlay hashes.
 */
extern Spyro Transition12_D_80070328 __asm__("D_80070328");
int Transition12MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
int Transition12RandBetween(int low, int high) __asm__("func_8003636C");
void Transition12BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
void Transition12ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Transition12ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition12_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition12RawUnion[] __asm__("D_80070328+0x144");
extern int Transition12RawMovement __asm__("D_80070328+0x50");
void func_level_12_8008A188(int selector) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");

    int deltaValue;

    int lengthResult;

    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register int oldMovementA __asm__("$3");
    register int oldMovementB __asm__("$3");
    register int flags __asm__("$2");
    register unsigned char* header __asm__("$17");
    register int* sourceA __asm__("$16");
    int* sourceB;
    register unsigned char* stateBase __asm__("$17");
    switch (selector) {
        case 0x14:
            Transition12_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition12_D_80070328.unk5 = 0;
            Transition12ClearPlayerMotionVectors();
            Transition12_D_80070328.grounded = 1;
            Transition12_D_80070328.union144.a.unk13cb = Transition12RandBetween(1, 3);
            Transition12_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x9:
            header = (unsigned char*)&Transition12_D_80070328.unk11[2];
            if (Transition12GetSurfaceTypeFromFlags(*(int*)header) == 7) {
                sourceA = (int*)(header - 0x74);
                oldMovementA = Transition12RawMovement;
                Transition12RawMovement = MOVEMENT_STATE_HURT;
                Transition12_D_80070328.unk5 = 1;
                Transition12_D_80070328.union144.a.unk13cb = oldMovementA;
                func_8004F178((Vector3D*)(header - 0x80), (Vector3D*)sourceA);
                Transition12_D_80070328.unk8[0] =
                    Transition12MeasureVectorLength((Vector3D*)sourceA, 0);
                Transition12_D_80070328.unk7a[2].z = 0xDC0;
                Transition12_D_80070328.grounded = 0;
            } else {
                oldMovementB = Transition12RawMovement;
                flags = Transition12_D_80070328.unk17a;
                MATCHING_KEEP2(oldMovementB, flags);
                Transition12RawMovement = MOVEMENT_STATE_HURT;
                Transition12_D_80070328.unk5 = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(flags, "memory");
                Transition12_D_80070328.union144.a.unk13cb = oldMovementB;
                sourceB = (int*)(header - 0x80);
                if (flags & 0x400) {
                    func_8004F178((Vector3D*)sourceB, (Vector3D*)(header + 0x110));
                    Transition12ShiftVectorLeft((Vector3D*)sourceB, 6);
                } else if (Transition12_D_80070328.unk22[5] >= 0) {
                    tableIndex = Transition12_D_80070328.unk22[5] * 2;
                    tableValue = *(short*)((unsigned char*)Transition12SignedB + tableIndex);
                    MATCHING_KEEP(tableValue);
                    Transition12RawX = tableValue >> 1;
                    tableIndex = *(short*)((unsigned char*)Transition12SignedA + tableIndex);
                    Transition12_D_80070328.unk7a[2].z = 0;
                    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableIndex, "memory");
                    Transition12_D_80070328.unk7a[2].y = tableIndex >> 1;
                } else {
                    MATCHING_KEEP(header);
                    destination = (Vector3D*)(header - 0x80);
                    Transition12ClearVector(destination);
                }
                func_8004F178(&Transition12_D_80070328.unk7a[1],
                              (Vector3D*)((unsigned char*)&Transition12_D_80070328.unk7a[1] + 0xC));
                Transition12BuildNegatedNormalizedPlayerVector(0xC00);
                Transition12_D_80070328.grounded = 1;
            }
            Transition12_D_8006E528 = 0x2D;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            goto clearPointers;
        case 0x13: {
            register Moby* sourceMoby __asm__("$6");
            register int yawValue __asm__("$5");
            register int positionZ __asm__("$2");
            register int heightValue __asm__("$3");
            register int privateValue __asm__("$4");
            stateBase = (unsigned char*)&Transition12RawMovement;
            privateData = Transition12_D_80070328.m_WhirlwindPointer->mobyTag;
            *(int*)stateBase = 14;
            Transition12_D_80070328.unk5 = 0;
            Transition12_D_80070328.grounded = 0;
            Transition12ClearVector((Vector3D*)(stateBase + 0x3C));
            sourceMoby = Transition12_D_80070328.m_WhirlwindPointer;
            yawValue = Transition12_D_80070328.rotation.yaw;
            positionZ = Transition12_D_80070328.position.z;
            heightValue = sourceMoby->position.z;
            privateValue = *(int*)privateData;
            MATCHING_KEEP4(sourceMoby, yawValue, positionZ, heightValue);
            Transition12_D_80070328.union144.a.unk13cc = yawValue;
            Transition12_D_80070328.union144.a.unk13cb = positionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue += privateValue;
            Transition12_D_80070328.union144.a.unk13ce.x = heightValue;
            heightValue -= positionZ;
            heightValue -= 0x800;
            Transition12_D_80070328.union144.a.unk13ce.z = heightValue;
            deltaValue = heightValue;
            shiftedValue = ((int)(deltaValue << 0xA) >> 0xA) + 0x400;
            Transition12_D_80070328.union144.a.unk13ce.y = shiftedValue;
            maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - shiftedValue) & 0xFFF;
            Transition12_D_80070328.union144.a.unk13ce.y = maskedValue;
            if (maskedValue >= 0x801) {
                Transition12_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
            }
            Transition12_D_80070328.union144.a.unk13da = *(int*)(privateData + 4);
            func_8004F178((Vector3D*)(stateBase + 0x10C), &sourceMoby->position);
            Transition12_D_80070328.unk13e[0] =
                (int)Transition12_D_80070328.m_WhirlwindPointer->angle.yaw;
            positionZ = *(int*)(privateData + 8);
            MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
            Transition12_D_80070328.unk20a = 0;
            Transition12_D_80070328.critterMobyPtr = 0;
            Transition12_D_80070328.unk13e[1] = positionZ;
            return;
        }
        case 0x1C:
            savedBase = Transition12RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition12RawMovement;
            Transition12RawMovement = MOVEMENT_STATE_HURT;
            Transition12_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition12_D_80070328.unk8[0] = Transition12MeasureVectorLength(sourceC, 0);
            Transition12_D_80070328.unk7a[2].z = 0xDC0;
            Transition12_D_80070328.grounded = 0;
            Transition12_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition12_D_80070328.damageFlags & 0x200) {
                Transition12_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition12_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            goto clearPointers;
        case 0x3A:
            Transition12_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition12_D_80070328.unk5 = 0;
            Transition12BuildNegatedNormalizedPlayerVector(0xC00);
            Transition12_D_80070328.grounded = 1;
            if ((selector == 0x3A) || (selector == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition12_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x21:
        case 0x22:
        case 0x23: {
            register unsigned char* flyState __asm__("$16") =
                (unsigned char*)&Transition12RawMovement;
            if (*(int*)flyState != 6) {
                *(int*)flyState = 6;
                Transition12_D_80070328.unk5 = 0;
                Transition12ClearVector((Vector3D*)(flyState + 0x104));
                Transition12_D_80070328.union144.a.unk13db.y = 0;
                lengthResult = Transition12MeasureVectorLength((Vector3D*)(flyState + 0x48), 0);
                Transition12_D_80070328.unk8[0] = lengthResult;
                if (lengthResult < 0x800)
                    Transition12_D_80070328.unk8[0] = 0x800;
                if (Transition12_D_80070328.unk8[0] >= 0x4B01)
                    Transition12_D_80070328.unk8[0] = 0x4B00;
                Transition12_D_80070328.union144.a.unk13cb = 0;
                Transition12_D_80070328.union144.b.unk148 = 0;
                Transition12_D_80070328.union144.a.unk13ce.x = 0;
                Transition12_D_80070328.union144.a.unk13ce.y = 0;
                Transition12_D_80070328.grounded = 0;
                Transition12_D_80070328.unk15b = 0;
            }
            if (selector < 0xA0)
                goto clearPointers;
            return;
        }
        case 0x26: {
            register unsigned char* state __asm__("$16") = (unsigned char*)&Transition12RawMovement;
            *(int*)state = 11;
            if (Transition12_D_80070328.animationState == 0x2A)
                Transition12_D_80070328.unk5 = 2;
            Transition12ClearVector((Vector3D*)(state + 0xFC));
            Transition12_D_80070328.union144.a.unk13cb = 0;
            Transition12_D_80070328.unk8[0] =
                Transition12MeasureVectorLength((Vector3D*)(state + 0x48), 0);
            Transition12_D_80070328.grounded = 1;
            Transition12_D_80070328.unk4a = 0x280;
            return;
        }
        case 0x31: {
            register unsigned char* lengthBase __asm__("$5") =
                (unsigned char*)&Transition12_D_80070328.unk8[0];
            register int valueA __asm__("$4");
            register int valueB __asm__("$5");
            register int valueKind __asm__("$6");
            *(int*)lengthBase = 0;
            if (Transition12_D_80070328.animationState == 0xD ||
                Transition12_D_80070328.movementState == 1)
                func_8004F178((Vector3D*)(lengthBase - 0x30), (Vector3D*)(lengthBase - 0x18));
            else
                Transition12ClearVector((Vector3D*)(lengthBase - 0x30));
            func_8004F178(&Transition12_D_80070328.unk7a[2],
                          (Vector3D*)((unsigned char*)&Transition12_D_80070328.unk7a[2] - 0xC));
            Transition12_D_80070328.movementState = 17;
            Transition12_D_80070328.unk5 = 0;
            Transition12BuildNegatedNormalizedPlayerVector(0xC00);
            Transition12_D_80070328.grounded = 0;
            Transition12_D_80070328.union144.a.unk13cb = 0;
            valueKind = 1;
            if (Transition12_D_80070328.unk9ha[0] >= 11) {
                valueA = Transition12_D_80070328.unk9e.x;
                valueB = Transition12_D_80070328.unk9e.y;
            } else {
                valueA = Transition12_D_80070328.unk7a[3].x;
                valueB = valueA;
            }
            Transition12_D_80070328.union144.a.unk13cc =
                Transition12PlanarHeadingLookup(valueA, valueB, valueKind);
        clearPointers:
            Transition12_D_80070328.unk20a = 0;
            Transition12_D_80070328.critterMobyPtr = 0;
            return;
        }
        default:
            return;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level12
 * 8008A82C: original789 instructions and50 dispatch words in sibling4816
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original12.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A12W48 __asm__("D_80070328 + 0x48");
extern int A12W4C __asm__("D_80070328 + 0x4C");
extern int A12W54 __asm__("D_80070328 + 0x54");
extern int A12WA0 __asm__("D_80070328 + 0xA0");
extern int A12WA8 __asm__("D_80070328 + 0xA8");
extern int A12WAC __asm__("D_80070328 + 0xAC");
extern int A12WB0 __asm__("D_80070328 + 0xB0");
extern int A12WB8 __asm__("D_80070328 + 0xB8");
extern int A12WCC __asm__("D_80070328 + 0xCC");
extern int A12WD0 __asm__("D_80070328 + 0xD0");
extern int A12WD4 __asm__("D_80070328 + 0xD4");
extern int A12W8C __asm__("D_80070328 + 0x8C");
extern int A12W90 __asm__("D_80070328 + 0x90");
extern int A12W94 __asm__("D_80070328 + 0x94");
extern int A12WE4 __asm__("D_80070328 + 0xE4");
extern int A12W144 __asm__("D_80070328 + 0x144");
extern int A12W158 __asm__("D_80070328 + 0x158");
extern int A12W1EC __asm__("D_80070328 + 0x1EC");
extern int A12W1F0 __asm__("D_80070328 + 0x1F0");
extern int A12W240 __asm__("D_80070328 + 0x240");
extern int A12W280 __asm__("D_80070328 + 0x280");
extern unsigned char A12B14 __asm__("D_80070328 + 0x14");
extern unsigned char A12B15 __asm__("D_80070328 + 0x15");
extern unsigned char A12B16 __asm__("D_80070328 + 0x16");
extern unsigned char A12B17 __asm__("D_80070328 + 0x17");
extern unsigned char A12B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A12BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A12B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A12B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A12Player[] __asm__("D_80070328");
extern unsigned char A12Table[] __asm__("D_80066530");
extern int A12Buttons __asm__("D_8006E538"), A12NewButtons __asm__("D_8006E53C");
extern int A12Mode __asm__("D_8006E044"), A12Gate __asm__("D_8006E344"),
    A12Count __asm__("D_8006C514");
extern int (*A12Callback)(int) __asm__("unk_ovlheader_8007431C");
extern int A12W24 __asm__("D_80070328 + 0x24");
extern int A12W28C __asm__("D_80070328 + 0x28C");
extern int A12W290 __asm__("D_80070328 + 0x290");
extern int A12Surface __asm__("D_8006FA38");
extern unsigned char* A12SoundDesc __asm__("D_8006C654");
int A12Sound() __asm__("PlaySound");
int A12ProcessPlayerStateFlags() __asm__("func_80040994");
int A12DispatchPlayerStateRequest() __asm__("func_8004BEF8");
int A12SelectPlayerAnimationLoopRequest() __asm__("func_80049688");
int A12ApproximatePlanarDistance() __asm__("func_8004F334");
int A12UpdatePlayerRetryState() __asm__("func_800498C0");
extern int A12WBC __asm__("D_80070328 + 0xBC");
extern int A12W1BC __asm__("D_80070328 + 0x1BC");
extern int A12W60 __asm__("D_80070328 + 0x60");
extern short A12H148 __asm__("D_80070328 + 0x148");
int A12TestPlayerProbePattern() __asm__("func_80043194");
int A12MeasureVectorLength() __asm__("func_8004EDE8");
void func_level_12_8008A82C(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register int* state __asm__("$16");
    register int* locomotion __asm__("$17");
    switch (A12W48) {
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 29:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 30:
        case 31:
        case 32:
        case 36:
        case 37:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
            return;
        case 20:
            if (A12ProcessPlayerStateFlags())
                return;
            if (A12NewButtons & 0x40) {
                A12DispatchPlayerStateRequest(6);
                return;
            }
            if (A12WB8 >= 4 || A12WE4 >= 23)
                goto set7;
            work3 = A12Buttons;
            if (work3 & 0x80) {
                A12DispatchPlayerStateRequest(13);
                return;
            }
            work2 = A12WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17)
                goto set1;
            work2 = work3 & 12;
            MATCHING_KEEP(work2);
            if (!work2 && A12WAC)
                goto set1;
            if (A12Mode == 7 || A12W240) {
                state = &A12W48;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                A12DispatchPlayerStateRequest(0);
                if (A12Table[*((unsigned char*)state - 0x2C)] >= 96) {
                    A12B14 = A12B15;
                    A12B16 = A12B17;
                }
                A12B17 = 0;
                work3 = *state;
                work2 = 113;
                *((unsigned char*)state - 0x2C) = work2;
                A12W1F0 = 0;
                A12B15 = work3;
                A12W1EC = work3;
                return;
            }
            if (A12BFC) {
                A12DispatchPlayerStateRequest(15);
                return;
            }
            A12SelectPlayerAnimationLoopRequest();
            return;
        case 9:
            work3 = A12W4C;
            if (work3 != 1)
                goto charge9;
            if (A12B1B5 && (A12NewButtons & 64))
                A12B1B6 = 1;
            if (A12WB8 || A12W54 < 16 || A12WE4 >= 23)
                goto buttons9;
            work3 = A12WCC;
            work2 = A12W8C;
            work5 = work3 * work2;
            work3 = A12WD0;
            work2 = A12W90;
            work4 = work3 * work2;
            work3 = A12WD4;
            work2 = A12W94;
            work3 = work3 * work2;
            work2 = work5 + work4;
            work2 += work3;
            if (work2 >= 0)
                goto buttons9;
            if (A12WAC) {
            speed_choice:
                work3 = A12WB0;
                if (work3 > 3840)
                    goto set3;
                work2 = work3 < 1921;
                MATCHING_KEEP(work2);
                if (!work2)
                    goto set2;
                goto set1;
            }
            work2 = A12WB0 < 1920;
            MATCHING_KEEP(work2);
            if (!work2)
                goto set4;
            goto set0;
        buttons9:
            if ((A12Buttons & 128) && A12WA0 < 0 && A12W54 >= 5)
                goto set22;
            if (A12B1B5 && A12B1B6) {
                if (A12WA0 >= 0)
                    return;
                if (A12W54 >= 5)
                    goto set17;
            }
            work3 = A12WA0;
            if (work3 >= 0)
                return;
            work4 = A12W54;
            if (work4 < 5)
                return;
            work2 = work3 < -6400;
            MATCHING_KEEP(work2);
            if (work2)
                goto set7;
            work2 = work4 < 91;
            if (!work2)
                goto set7;
            return;
        charge9:
            if (A12W24 & 32)
                return;
            if (A12W54 < 25)
                return;
            if (A12W280 < 0) {
                A12DispatchPlayerStateRequest(31);
                return;
            }
        selectState:
            work3 = A12W144;
            if (work3 == 10) {
                A12DispatchPlayerStateRequest(44);
                return;
            }
            work2 = work3 - 11;
            MATCHING_KEEP(work2);
            if ((unsigned int)work2 < 2) {
                A12DispatchPlayerStateRequest(41);
                return;
            }
            if (!A12WB8)
                goto set0;
            goto set7;
        case 19:
            if (A12ProcessPlayerStateFlags())
                return;
            work2 = 13;
            work3 = A12Gate;
            if (work3 == work2 && A12Count)
                goto set17;
            work4 = (int)A12Player;
            work2 = A12ApproximatePlanarDistance((void*)work4, (void*)(work4 + 348));
            work3 = A12W158;
            work3 = work3 < work2;
            if (!work3)
                return;
            goto set17;
        case 28:
            if (A12B1B5 && (A12NewButtons & 64))
                A12B1B6 = 1;
            if (A12WB8 || A12W54 < 16 || A12WE4 >= 23)
                goto buttons;
            work3 = A12WCC;
            work2 = A12W8C;
            work5 = work3 * work2;
            work3 = A12WD0;
            work2 = A12W90;
            work4 = work3 * work2;
            work3 = A12WD4;
            work2 = A12W94;
            work3 = work3 * work2;
            work2 = work5 + work4;
            work2 += work3;
            if (work2 >= 0)
                goto buttons;
            work2 = A12WAC;
            MATCHING_KEEP(work2);
            if (work2)
                goto speed_choice;
            work2 = A12WB0 < 1920;
            MATCHING_KEEP(work2);
            if (!work2)
                goto set4;
            goto set0;
        buttons:
            if ((A12Buttons & 128) && A12W4C == 1)
                goto set22;
            if (A12B1B5 && A12B1B6) {
                if (A12W4C == 1)
                    goto set17;
                return;
            }
            if (A12W4C != 1)
                return;
            if (A12WA0 < -6400)
                goto set7;
            if (A12W54 >= 91)
                goto set7;
            return;
        case 33:
            if (A12ProcessPlayerStateFlags())
                return;
            locomotion = &A12WB8;
            MATCHING_KEEP(locomotion);
            if (!*locomotion) {
                if (A12WE4 >= 23)
                    A12DispatchPlayerStateRequest(7);
                if (A12WAC > 0)
                    goto speed_choice;
                work2 = A12WB0 < 1920;
                MATCHING_KEEP(work2);
                if (!work2)
                    goto set4;
                MATCHING_BARRIER_VOLATILE("memory");
                goto set0;
            }
            state = &A12NewButtons;
            MATCHING_KEEP(state);
            if (*state & 128)
                goto set22;
            if (A12TestPlayerProbePattern(4))
                goto set47;
            if (!A12WBC)
                goto set7;
            if (!A12W1BC)
                goto set17;
            if (*state & 16)
                goto set18;
            work4 = (int)locomotion - 32;
            if (A12MeasureVectorLength((void*)work4, 1) < 1024)
                goto set7;
            if (A12H148 >= 2)
                goto set35;
            if (A12W4C)
                goto set34;
            work3 = A12W60;
            work2 = work3 < 365;
            if (!work2)
                goto set34;
            work2 = work3 < -364;
            if (!work2)
                return;
            goto set35;
        case 34:
            if (A12ProcessPlayerStateFlags())
                return;
            locomotion = &A12WB8;
            MATCHING_KEEP(locomotion);
            if (!*locomotion) {
                if (A12WE4 >= 23)
                    A12DispatchPlayerStateRequest(7);
                if (A12WAC > 0)
                    goto speed_choice;
                work2 = A12WB0 < 1920;
                MATCHING_KEEP(work2);
                if (!work2)
                    goto set4;
                goto set0;
            }
            state = &A12NewButtons;
            MATCHING_KEEP(state);
            if (*state & 128)
                goto set22;
            if (A12TestPlayerProbePattern(4))
                goto set47;
            if (!A12WBC)
                goto set7;
            if (!A12W1BC)
                goto set17;
            if (*state & 16)
                goto set18;
            work4 = (int)locomotion - 32;
            if (A12MeasureVectorLength((void*)work4, 1) < 1024)
                goto set7;
            if (A12H148 >= 2) {
            set35:
                A12DispatchPlayerStateRequest(35);
                return;
            }
            if (A12W60 >= 256)
                return;
            if (!A12W4C)
                goto set33;
            return;
        case 35:
            if (A12ProcessPlayerStateFlags())
                return;
            locomotion = &A12WB8;
            MATCHING_KEEP(locomotion);
            if (!*locomotion) {
                if (A12WE4 >= 23)
                    A12DispatchPlayerStateRequest(7);
                if (A12WAC > 0) {
                    work3 = A12WB0;
                    if (work3 > 3840) {
                    set3:
                        A12DispatchPlayerStateRequest(3);
                        return;
                    }
                    work2 = work3 < 1921;
                    MATCHING_KEEP(work2);
                    if (!work2) {
                    set2:
                        A12DispatchPlayerStateRequest(2);
                        return;
                    }
                set1:
                    A12DispatchPlayerStateRequest(1);
                    return;
                }
                if (A12WB0 < 1920)
                    goto set0;
            set4:
                A12DispatchPlayerStateRequest(4);
                return;
            }
            state = &A12NewButtons;
            MATCHING_KEEP(state);
            if (*state & 128) {
            set22:
                A12DispatchPlayerStateRequest(22);
                return;
            }
            if (A12TestPlayerProbePattern(4)) {
            set47:
                A12DispatchPlayerStateRequest(47);
                return;
            }
            if (!A12WBC)
                goto set7;
            if (!A12W1BC) {
            set17:
                A12DispatchPlayerStateRequest(17);
                return;
            }
            if (*state & 16) {
            set18:
                A12DispatchPlayerStateRequest(18);
                return;
            }
            work4 = (int)locomotion - 32;
            if (A12MeasureVectorLength((void*)work4, 1) < 1024)
                goto set7;
            if (A12H148 >= 2)
                return;
            if (A12W4C) {
            set34:
                A12DispatchPlayerStateRequest(34);
                return;
            }
            if (A12W60 < -255)
                return;
        set33:
            A12DispatchPlayerStateRequest(33);
            return;
        case 38: {
            register int (*callback2)(int) __asm__("$2");
        callback:
            callback2 = A12Callback;
            callback2(1);
            return;
        }
        case 49:
            if (A12ProcessPlayerStateFlags())
                return;
            if (A12WB8 >= 4) {
            set7:
                A12DispatchPlayerStateRequest(7);
                return;
            }
            if (A12W144 < 16)
                return;
        set0:
            A12DispatchPlayerStateRequest(0);
            return;
        case 58:
            if (A12W54 < 137)
                return;
            A12UpdatePlayerRetryState();
            return;
    }
}
