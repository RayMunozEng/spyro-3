#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800882B4.
 * Assembly SHA256 2446940b3f513bc4aab6f31613b5a0c1ab2528d9717a89cefd8d02548f18f190.
 * AI-generated; not human reviewed. All1926 original instructions,
 * 105 selectors bias28 and original owned padding are required.
 * Frame0x148 preserves scratch10..12C, savedS0..S4, slotS2, combinedS3.
 * Sixteen exact physical groups reuse verified44/23 bodies with explicit
 * stack/address maps. Original159-row28 retains AC clear in417FC's delay
 * slot, absolute A4 producers, S0 AC/S1 vector8C and SP10 vector. All
 * particle, scalar, callback and real shared targets are disc-derived.
 * Original50 owns its F178 call; terminal131 remains after the switch.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions. Frozen C tools emit words.
 * Raw field units/fixed point, helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, actual internal/conditional
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime completeness. */
#define Physics30Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics30Call363DCView1() __asm__("func_800363DC");
unsigned char Physics30Call40D10View1() __asm__("func_80040D10");
unsigned char Physics30Call41580View1() __asm__("func_80041580");
unsigned char Physics30Call417FCView1() __asm__("func_800417FC");
unsigned char Physics30Call41B64View1() __asm__("func_80041B64");
int Physics30InterpolateSineView1() __asm__("func_8004E9E4");
int Physics30InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics30TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics30MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics30ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics30AddVectorView1() __asm__("func_8004F194");
unsigned char Physics30SubtractVectorView1() __asm__("func_8004F1C8");
int Physics30CallRandView1() __asm__("rand");
extern unsigned char Physics30Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics30Data65920View1 __asm__("D_80065920");
extern void* Physics30Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics30Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics30Player0View1 __asm__("D_80070328");
extern int Physics30Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics30Call40D10View2() __asm__("func_80040D10");
int Physics30Call40F48View1() __asm__("func_80040F48");
int Physics30Call41580View2() __asm__("func_80041580");
int Physics30Call416F4View1() __asm__("func_800416F4");
int Physics30Call417FCView2() __asm__("func_800417FC");
int Physics30Call41848View1() __asm__("func_80041848");
int Physics30Call41B64View2() __asm__("func_80041B64");
int Physics30InterpolateSineView2() __asm__("func_8004E9E4");
int Physics30InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics30MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics30ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics30ClearVectorView1() __asm__("func_8004F168");
int Physics30CopyVectorView1() __asm__("func_8004F178");
int Physics30AddVectorView2() __asm__("func_8004F194");
int Physics30SubtractVectorView2() __asm__("func_8004F1C8");
extern short Physics30Data6E040View1 __asm__("D_8006E040");
extern int Physics30Data6E044View1 __asm__("D_8006E044");
extern int Physics30Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics30Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics30PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics30Player94View2 __asm__("D_80070328+0x94");
extern int Physics30PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics30Player80View1 __asm__("D_80070328+0x80");
extern int Physics30PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics30Player64View1 __asm__("D_80070328+0x64");
extern int Physics30Player144View1 __asm__("D_80070328+0x144");
extern int Physics30Player60View1 __asm__("D_80070328+0x60");
extern int Physics30PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics30Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics30Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics30PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics30PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics30Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics30Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics30Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics30Player101View1 __asm__("D_80070328+0x101");
extern int Physics30PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics30Call40F48View2() __asm__("func_80040F48");
int Physics30Call43194View1() __asm__("func_80043194");
int Physics30PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics30TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics30MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics30ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics30ClearVectorView2() __asm__("func_8004F168");
int Physics30CopyVectorView2() __asm__("func_8004F178");
int Physics30AddVectorView3() __asm__("func_8004F194");
int Physics30SubtractVectorView3() __asm__("func_8004F1C8");
extern int Physics30Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics30Player0View3 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
int Physics30Call40D10View3() __asm__("func_80040D10");
int Physics30Call410F8View1() __asm__("func_800410F8");
int Physics30Call41580View3() __asm__("func_80041580");
int Physics30Call417FCView3() __asm__("func_800417FC");
int Physics30Call41848View2() __asm__("func_80041848");
int Physics30Call41B64View3() __asm__("func_80041B64");
int Physics30InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics30TransformVectorByBasisView3() __asm__("func_8004ED6C");
int Physics30ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics30ClearVectorView3() __asm__("func_8004F168");
int Physics30CopyVectorView3() __asm__("func_8004F178");
int Physics30AddVectorView4() __asm__("func_8004F194");
int Physics30CallRandView2() __asm__("rand");
extern int* Physics30Data6C570View2 __asm__("D_8006C570");
extern int Physics30Data6C640View1 __asm__("D_8006C640");
extern int Physics30Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics30Player0View4 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics30Player158View1 __asm__("D_80070328+0x158");
extern int Physics30Player20CView2 __asm__("D_80070328+0x20C");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics30Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics30Player80View2 __asm__("D_80070328+0x80");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern int Physics30Player50View1 __asm__("D_80070328+0x50");
extern int Physics30Player250View1 __asm__("D_80070328+0x250");
int Physics30PlanarHeadingLookupView2() __asm__("func_8004E880");
void func_level_30_800882B4(int slotIndex) {
    register void* fieldAC28 __asm__("$16");
    register void* vector8C28 __asm__("$17");
    int vectorProduct28A, vectorProduct28B;
    int agentProduct0, agentProduct1, agentProduct2, agentProduct3, agentProduct4, agentProduct5,
        agentProduct6, agentProduct7;
    register void* fieldA4State28 __asm__("$16");
    register void* vector8CState28 __asm__("$17");
    register int signedWord19 __asm__("$20");
    register int signedWord20 __asm__("$21");
    register int signedWord21 __asm__("$22");
    register void* savedPointer22 __asm__("$19");
    register void* savedPointer17 __asm__("$17");
    register void* (*particleCall3)() __asm__("$3");
    register int particleArg7 __asm__("$7");
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void* vectorAt40 __asm__("$16");
    register void* vectorAt30 __asm__("$17");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4,
            spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC,
            spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C, sp120,
            sp124, sp128, sp12C;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    void* raw21_temp_s0_9;
    int raw21_temp_a0_5;
    int raw21_temp_a0_6;
    int raw21_temp_a0_7;
    int raw21_temp_a1_2;
    int raw21_temp_a1_3;
    int raw21_temp_a1_4;
    int raw21_temp_s0_10;
    register int raw21_temp_s0_8 __asm__("$16");
    int raw21_temp_s1_4;
    int raw21_temp_v1_13;
    int raw21_temp_v1_14;
    int raw21_temp_v1_6;
    int raw21_temp_v1_7;
    int raw21_var_v0_2;
    void* raw21_temp_s0_11;
    void* raw21_temp_s0_7;
    register void* raw21_temp_s1_5 __asm__("$17");
    void* raw21_temp_s1_6;
    void* raw21_temp_s1_7;
    void* raw21_temp_s2_3;
    void* raw21_temp_s4;
    savedSlotIndex = slotIndex;
    workWord2 = savedSlotIndex * 16;
    globalPointer = &Physics30Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics30Data6C570View1 = (void*)workWord2;
    workWord2 = Physics30Field(&Physics30Player0View1, int*, 0x54);
    stateWord3 = Physics30Field(&Physics30Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        default:
            return;
        case 28:
            Physics30Call40D10View1(3200);
            Physics30Call41580View1(40, 8);
            call4 = (void*)320;
            call5 = (void*)192;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            fieldAC28 = &Physics30PlayerACView1;
            Physics30Field(fieldAC28, int*, 0) = 0;
            Physics30Call417FCView1(call4, call5);
            vector8C28 = fieldAC28 - 32;
            workWord2 = Physics30InterpolateCosineView1(Physics30PlayerA4View1);
            workWord3 = Physics30PlayerB0View1;
            vectorProduct28A = workWord3 * workWord2;
            call4 = (void*)Physics30PlayerA4View1;
            workWord2 = vectorProduct28A >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp10 = workWord2;
            workWord2 = Physics30InterpolateSineView1(call4);
            workWord3 = Physics30PlayerB0View1;
            vectorProduct28B = workWord3 * workWord2;
            call4 = &originalFrame.sp10;
            call5 = call4;
            call6 = vector8C28;
            workWord2 = vectorProduct28B >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp14 = workWord2;
            Physics30SubtractVectorView1(call4, call5, call6);
            originalFrame.sp18 = 0;
            temp_v0_4 = Physics30MeasureVectorLengthView1(&originalFrame.sp10, 0);
            MATCHING_KEEP(fieldAC28);
            var_a0_3 = fieldAC28 - 44;
            if (temp_v0_4 >= 641) {
                Physics30ScaleVectorRatioQ15View1(&originalFrame.sp10, temp_v0_4, 640);
                MATCHING_KEEP(fieldAC28);
                var_a0_3 = fieldAC28 - 44;
            }
            Physics30AddVectorView1(var_a0_3, vector8C28, &originalFrame.sp10);
            Physics30Call41B64View1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics30Field(&Physics30Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics30Field(&Physics30Player0View1, int*, 0x94) - 0xC0;
            }
            Physics30Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics30Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics30Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp30;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics30CallRandView1() & 0xFF)) {
                        workWord2 = Physics30Call363DCView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics30Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp20 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics30Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp28 = 0xE;
                        originalFrame.sp30 = -0x12C;
                        originalFrame.sp34 = 0;
                        originalFrame.sp38 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp24 = (workWord3 * 5) >> 0xA;
                        Physics30TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp30 += Physics30Call363DCView1(0, 0x50);
                        originalFrame.sp34 += Physics30Call363DCView1(0, 0x50);
                        originalFrame.sp38 += Physics30Call363DCView1(0, 0x50);
                        Physics30AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp20);
                        Physics30Field(temp_v0_5, signed char*, 2) = 8;
                        Physics30Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics30Player20CView2;
            MATCHING_KEEP(call5);
            workWord2 = Physics30Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp20;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics30Call410F8View1(call4, call5, 0);
            workWord3 = Physics30Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics30Player60View1;
                numeric4 = Physics30Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric4 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.sp24 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.sp24 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                workWord2 = originalFrame.sp24;
                workWord3 = numeric4 + 1;
                Physics30Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.sp24 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics30Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.sp20 * 0x14) >> 7;
            Physics30Field(&Physics30Player0View4, int*, 0x64) =
                (int)((Physics30Field(&Physics30Player0View4, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics30Field(&Physics30Player0View4, int*, 0x60) +
                               ((int)(originalFrame.sp24 * -0xF) >> 7)) &
                              0xFFF;
            Physics30Field(&Physics30Player0View4, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics30Field(&Physics30Player0View4, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x60) < -0x320) {
                Physics30Field(&Physics30Player0View4, int*, 0x60) = -0x320;
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x60) >= 0x321) {
                Physics30Field(&Physics30Player0View4, int*, 0x60) = 0x320;
            }
            if ((*Physics30Data6C570View2 & 0x40) ||
                (Physics30Field(&Physics30Player0View4, int*, 0x4C) == 1)) {
                Physics30Field(&Physics30Player0View4, int*, 0xAC) = 0xE00;
            } else {
                Physics30Field(&Physics30Player0View4, int*, 0xAC) = 0;
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x4C) == 2) {
                Physics30Call417FCView3(0xC0, 0xC0);
                if (Physics30Field(&Physics30Player0View4, int*, 0xB0) < 0xE01) {
                    Physics30Field(&Physics30Player0View4, int*, 0x4C) = 0;
                }
            } else {
                Physics30Call417FCView3(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics30Player0View4 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics30InterpolateCosineView3(
                                                Physics30Field(&Physics30Player0View4, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics30Field(&Physics30Player0View4, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics30Field(&Physics30Player0View4, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics30Field(&Physics30Player0View4, int*, 0x14C) + raw21_temp_a0_5;
            Physics30Field(&Physics30Player0View4, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics30Field(&Physics30Player0View4, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics30Field(&Physics30Player0View4, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics30Field(&Physics30Player0View4, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x5C) < -0x300) {
                Physics30Field(&Physics30Player0View4, int*, 0x5C) = -0x300;
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x5C) >= 0x301) {
                Physics30Field(&Physics30Player0View4, int*, 0x5C) = 0x300;
            }
            Physics30Call41848View2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics30CopyVectorView3(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics30CallRandView2() & 31;
            if (workWord2)
                goto block_130;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto block_130;
            call5 = (void*)44;
            call6 = &originalFrame.sp40;
            particleArg7 = 0;
            MATCHING_KEEP(particleArg7);
            workWord2 = 544;
            originalFrame.sp40 = workWord2;
            workWord2 = 64;
            originalFrame.sp44 = 0;
            __asm__ volatile("" ::"i"(0x80088898) : "memory");
            originalFrame.sp48 = workWord2;
            goto block_129;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics30Player0View4 + 0x20C;
            if (!(Physics30Field(&Physics30Player0View4, int*, 0x20C) & 0x40)) {
                if (Physics30Data6E044View3 != 7) {
                    Physics30Call410F8View1(&originalFrame.sp40, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.sp40;
                    numeric4 = originalFrame.sp44;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics30Player64View1;
                    workWord2 = Physics30Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics30Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics30Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics30Player60View1 = workWord2;
                    }
                    if (Physics30Field(&Physics30Player0View4, int*, 0x60) < -0x320) {
                        Physics30Field(&Physics30Player0View4, int*, 0x60) = -0x320;
                    }
                    if (Physics30Field(&Physics30Player0View4, int*, 0x60) >= 0x321) {
                        Physics30Field(&Physics30Player0View4, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics30InterpolateCosineView3(Physics30Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics30Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics30Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics30Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics30Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics30Player5CView1 = workWord2;
                    }
                    if (Physics30Field(&Physics30Player0View4, int*, 0x5C) < -0x300) {
                        Physics30Field(&Physics30Player0View4, int*, 0x5C) = -0x300;
                    }
                    if (Physics30Field(&Physics30Player0View4, int*, 0x5C) >= 0x301) {
                        Physics30Field(&Physics30Player0View4, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics30Player0View4 + 0x80;
                Physics30ClearVectorView3(raw21_temp_s0_9);
                Physics30ClearVectorView3(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics30CallRandView2() & 31;
                if (workWord2)
                    goto block_130;
                MATCHING_KEEP(workWord2);
                particleCall3 = Physics21_SpawnParticle;
                call4 = (void*)1;
                if (!particleCall3)
                    goto block_130;
                call5 = (void*)44;
                call6 = &originalFrame.sp50;
                particleArg7 = 0;
                MATCHING_KEEP(particleArg7);
                workWord2 = 544;
                originalFrame.sp50 = workWord2;
                workWord2 = 64;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = workWord2;
            block_129:
                particleCall3(call4, call5, call6, particleArg7);
            block_130:
                globalPointer = &Physics30Player158View1;
                workWord2 = Physics30Field(globalPointer, int*, 0);
                workWord2++;
                __asm__ volatile("" ::"i"(0x80088AB4) : "memory");
                Physics30Field(globalPointer, int*, 0) = workWord2;
                return;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics30Player20CView2;
            MATCHING_KEEP(call5);
            workWord2 = Physics30Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp50;
            if (!workWord2)
                goto run42;
        block_132:
            Physics30PlayerACView1 = 0;
            Physics30PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics30Call410F8View1(call4, call5, 0);
            workWord3 = Physics30Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics30Player60View1;
                numeric5 = Physics30Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.sp54 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.sp54 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.sp54;
                workWord3 = numeric5 + 1;
                Physics30Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.sp54 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics30Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics30Player0View4 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.sp50 * 0x14) >> 7;
            Physics30Field(&Physics30Player0View4, int*, 0x64) =
                (int)((Physics30Field(&Physics30Player0View4, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics30Field(&Physics30Player0View4, int*, 0x60) +
                                ((int)(originalFrame.sp54 * -0xF) >> 7)) &
                               0xFFF;
            Physics30Field(&Physics30Player0View4, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics30Field(&Physics30Player0View4, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x60) < -0x320) {
                Physics30Field(&Physics30Player0View4, int*, 0x60) = -0x320;
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x60) >= 0x321) {
                Physics30Field(&Physics30Player0View4, int*, 0x60) = 0x320;
            }
            Physics30Field(&Physics30Player0View4, int*, 0xAC) = 0x1C00;
            Physics30Call417FCView3(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics30InterpolateCosineView3(
                                                 Physics30Field(&Physics30Player0View4, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics30Field(&Physics30Player0View4, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics30Field(&Physics30Player0View4, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics30Field(&Physics30Player0View4, int*, 0x14C) + raw21_temp_a0_6;
            Physics30Field(&Physics30Player0View4, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics30Field(&Physics30Player0View4, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics30Field(&Physics30Player0View4, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics30Field(&Physics30Player0View4, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x5C) < -0x300) {
                Physics30Field(&Physics30Player0View4, int*, 0x5C) = -0x300;
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x5C) >= 0x301) {
                Physics30Field(&Physics30Player0View4, int*, 0x5C) = 0x300;
            }
            Physics30Call41848View2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics30CopyVectorView3(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics30Field(&Physics30Player0View4, int*, 0xB4) >= 0x7D1)) {
                originalFrame.sp60 = -0x190;
                originalFrame.sp64 = 0x40 - (Physics30CallRandView2() & 0x7F);
                originalFrame.sp68 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp60, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics30Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics30Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 == workWord2)
                goto clear47Calls;
        continue43:
            workWord2 = 7;
            workWord3 = Physics30Data6E044View3;
            if (workWord3 == workWord2) {
                Physics30Field(&Physics30Player0View4, int*, 0xB0) = 0;
            } else {
                Physics30Call40D10View3(0x980);
                raw21_var_v0_2 = Physics30Call41580View3(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics30Field(&Physics30Player0View4, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics30Field(&Physics30Player0View4, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics30Call417FCView3(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics30Player0View4 + 0xB0;
            if (Physics30Field(&Physics30Player0View4, int*, 0xB0) != 0) {
                Physics30Call41848View2();
                Physics30Call41B64View3();
                Physics30Field(&Physics30Player0View4, int*, 0x94) = 0;
            } else {
                Physics30ClearVectorView3(raw21_temp_s0_11 - 0x30);
                Physics30ClearVectorView3(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics30Player0View4 + 0x28;
                if (Physics30Field(&Physics30Player0View4, int*, 0x28) < 0) {
                    if ((Physics30Field(&Physics30Player0View4, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics30Data6C640View1 & 1)) {
                        Physics30CopyVectorView3(&originalFrame.sp60, raw21_temp_s4 - 0x28);
                        originalFrame.sp74 = 0x40;
                        originalFrame.sp78 = 0;
                        originalFrame.sp70 =
                            (int)Physics30Field(&Physics30Player0View4, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp74 = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics30TransformVectorByBasisView3(raw21_temp_s2_3, &originalFrame.sp70,
                                                             &originalFrame.sp80);
                        Physics30AddVectorView4(&originalFrame.sp60, &originalFrame.sp60,
                                                &originalFrame.sp80);
                        originalFrame.sp70 = 0;
                        originalFrame.sp68 = -Physics30Field(&Physics30Player0View4, int*, 0x28);
                        Physics30TransformVectorByBasisView3(raw21_temp_s2_3, &originalFrame.sp70,
                                                             &originalFrame.sp70);
                        Physics30ShiftVectorRightTowardZeroView1(&originalFrame.sp70, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp60, &originalFrame.sp70);
                        if (!(Physics30CallRandView2() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp60, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics30Player0View4 + 0xB0;
                        if ((Physics30Field(&Physics30Player0View4, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics30Data6C640View1 & 7) &&
                            !(Physics30CallRandView2() & 3)) {
                            originalFrame.sp90 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp94 = 0;
                            originalFrame.sp98 = 0;
                            Physics30TransformVectorByBasisView3(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp90, &originalFrame.sp90);
                            Physics30AddVectorView4(&originalFrame.sp90, &originalFrame.sp90,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp98 =
                                -Physics30Field(&Physics30Player0View4, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp90, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics30Field(&Physics30Player0View4, int*, 0x144) -
                ((int)((Physics30Field(&Physics30Player0View4, int*, 0x148) * 2) +
                       (Physics30Field(&Physics30Player0View4, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics30Field(&Physics30Player0View4, int*, 0x148) + raw21_temp_a1_4;
            Physics30Field(&Physics30Player0View4, int*, 0x144) = raw21_temp_a1_4;
            Physics30Field(&Physics30Player0View4, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics30Field(&Physics30Player0View4, int*, 0x148) = 0x5900;
            }
            if (Physics30Field(&Physics30Player0View4, int*, 0x148) < -0x5900) {
                Physics30Field(&Physics30Player0View4, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 47: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3 = Physics30Data6E044View2;
            workWord2 = 7;
            if (workWord3 == workWord2)
                goto zero47;
            Physics30Call40F48View2(&originalFrame.sp80, 0);
            workWord2 = originalFrame.sp80;
            numeric6 = originalFrame.sp84;
            originalFrame.spA0 = 0;
            workWord3 = (workWord2 * 9 << 7) >> 7;
            workWord2 = (numeric6 * 3 << 9) >> 7;
            originalFrame.sp80 = workWord3;
            workWord3 = -workWord3;
            originalFrame.sp84 = workWord2;
            originalFrame.spA4 = workWord3;
            originalFrame.spA8 = workWord2;
            workWord2 = Physics30MeasureVectorLengthView3(&originalFrame.spA0, 0, numeric6);
            numeric4 = originalFrame.spA8;
            workWord3 = numeric4;
            if (numeric4 < 0) {
                MATCHING_KEEP(workWord3);
                workWord3 = -workWord3;
            }
            workWord3 = workWord3 < workWord2;
            if (workWord3) {
                workWord2 = originalFrame.spA4;
                originalFrame.spA8 = 0;
                MATCHING_BARRIER_VOLATILE("$4");
                numeric4 = 0;
                if (workWord2 > 0) {
                    __asm__ volatile("" ::"i"(0x80089170) : "memory");
                    numeric4 = 1;
                }
                if (!Physics30Call43194View1(numeric4)) {
                    originalFrame.spA4 = 0;
                }
            } else {
                MATCHING_BARRIER_VOLATILE("$3");
                originalFrame.spA4 = 0;
                originalFrame.spA0 = 0;
                if (numeric4 > 0) {
                    __asm__ volatile("" ::"i"(0x80089198) : "memory");
                    numeric4 = 2;
                } else
                    numeric4 = 3;
                if (!Physics30Call43194View1(numeric4)) {
                    originalFrame.spA8 = 0;
                }
            }
            call4 = &originalFrame.spA0;
            workWord2 = Physics30MeasureVectorLengthView3(call4, 1);
            Physics30PlayerACView1 = workWord2;
            __asm__ volatile("" ::"i"(0x800891C8) : "memory");
            goto clear47;
        zero47:
            Physics30PlayerACView1 = 0;
        clear47:
            globalVector80 = &Physics30Player80View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(globalVector80, "memory");
        clear47Calls:
            call4 = &Physics30Player80View2;
            MATCHING_KEEP(call4);
            Physics30ClearVectorView2(call4);
            call4 = &Physics30Player8CView1;
            MATCHING_KEEP(call4);
            Physics30ClearVectorView2(call4);
            return;
        }
        case 50:
        case 51:
        case 52: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics30Call40F48View2(&originalFrame.spB0, 0);
            workWord2 = originalFrame.spB0;
            numeric6 = originalFrame.spB4;
            originalFrame.spB8 = 0;
            workWord3 = (workWord2 * 9 << 7) >> 7;
            workWord2 = (numeric6 * 3 << 9) >> 7;
            originalFrame.spB0 = workWord3;
            workWord3 = -workWord3;
            originalFrame.spB4 = workWord2;
            originalFrame.spBC = workWord3;
            originalFrame.spC0 = workWord2;
            workWord2 = Physics30MeasureVectorLengthView3(&originalFrame.spB8, 0, numeric6);
            numeric4 = originalFrame.spC0;
            workWord3 = numeric4;
            if (numeric4 < 0) {
                MATCHING_KEEP(workWord3);
                workWord3 = -workWord3;
            }
            workWord3 = workWord3 < workWord2;
            if (workWord3) {
                workWord2 = originalFrame.spBC;
                originalFrame.spC0 = 0;
                MATCHING_BARRIER_VOLATILE("$4");
                numeric4 = 0;
                if (workWord2 > 0) {
                    __asm__ volatile("" ::"i"(0x80089290) : "memory");
                    numeric4 = 1;
                }
                if (!Physics30Call43194View1(numeric4)) {
                    originalFrame.spBC = 0;
                }
            } else {
                MATCHING_BARRIER_VOLATILE("$3");
                originalFrame.spBC = 0;
                originalFrame.spB8 = 0;
                if (numeric4 > 0) {
                    __asm__ volatile("" ::"i"(0x800892B8) : "memory");
                    numeric4 = 2;
                } else
                    numeric4 = 3;
                if (!Physics30Call43194View1(numeric4)) {
                    originalFrame.spC0 = 0;
                }
            }
            vectorAt30 = &originalFrame.spB8;
            workWord2 = Physics30MeasureVectorLengthView3(vectorAt30, 1);
            numeric6 = 1;
            MATCHING_KEEP(numeric6);
            numeric4 = originalFrame.spB0;
            numeric5 = originalFrame.spB4;
            globalVector80 = &Physics30PlayerACView1;
            Physics30Field(globalVector80, int*, 0) = workWord2;
            workWord2 = Physics30PlanarHeadingLookupView1(numeric4, numeric5, numeric6);
            workWord3 = workWord2;
            workWord2 = workWord3 < 2049;
            Physics30PlayerA4View1 = workWord3;
            call4 = globalVector80 - 124;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics30PlayerA4View1 = workWord2;
            }
            call5 = vectorAt30;
            workWord2 = originalFrame.spB8;
            call6 = vectorAt30;
            workWord2 += 1024;
            originalFrame.spB8 = workWord2;
            Physics30TransformVectorByBasisView2(call4, call5, call6);
            call4 = vectorAt30;
            call5 = vectorAt30;
            __asm__("" : "=r"(globalVector80) : "0"(globalVector80), "r"(call4), "r"(call5));
            globalVector8CState20 = globalVector80 - 32;
            Physics30SubtractVectorView3(call4, call5, globalVector8CState20);
            call5 = (void*)Physics30MeasureVectorLengthView3(vectorAt30, 0);
            workWord2 = (int)call5 < 385;
            if (!workWord2)
                Physics30ScaleVectorRatioQ15View3(vectorAt30, call5, 384);
            globalVector80 -= 44;
            Physics30AddVectorView3(globalVector80, globalVector8CState20, vectorAt30);
            Physics30CopyVectorView2(globalVector8CState20, globalVector80);
            return;
        }
        case 128:
            globalVector80 = &Physics30Player0View2 + 0xB8;
            workWord2 = Physics30Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero128;
            vectorAt30 = &originalFrame.spC8;
            Physics30ClearVectorView1(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics30SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.spD0 = 0;
            call5 = (void*)Physics30MeasureVectorLengthView2(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics30ScaleVectorRatioQ15View2(vectorAt30, call5, 64);
            originalFrame.spD0 = -192;
            globalVector80 -= 56;
            Physics30AddVectorView2(globalVector80, globalVector8CState20, vectorAt30);
            Physics30CopyVectorView1(globalVector8CState20, globalVector80);
            goto clamp128;
        zero128:
            Physics30ClearVectorView1(globalVector80 - 56);
            Physics30ClearVectorView1(globalVector80 - 44);
            goto clamp128;
        clamp128:
            globalPointer = &Physics30Player94View2;
            workWord2 = Physics30Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
                Physics30Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        case 115:
        case 120:
        case 126:
            globalVector80 = &Physics30Player80View1;
            Physics30ClearVectorView1(globalVector80);
            Physics30ClearVectorView1(globalVector80 + 12);
            workWord3 = Physics30Data6E044View1;
            workWord2 = 40;
            if (workWord3 != workWord2)
                goto ordinary115;
            Physics44Slot4454();
            goto bytes115;
        ordinary115:
            workWord2 = 31;
            if (workWord3 == workWord2)
                goto bytes115;
            Physics30Call40D10View2(3840);
            Physics30Call416F4View1();
            Physics30Call41580View2(90, 16);
        bytes115:
            globalPointer = &Physics30Player1BAView1;
            workWord2 = Physics30Field(globalPointer, unsigned char*, 0);
            if (!workWord2)
                goto byteOne115;
            workWord2 = Physics30Data6E538View1 & 16;
            if (workWord2)
                return;
            workWord2 = 1;
            Physics30Field(globalPointer, unsigned char*, 0) = 0;
            Physics30Player1B9View1 = workWord2;
            return;
        byteOne115:
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics30Player1B9View1 = workWord2;
            return;
        case 116:
        case 117: {
            register void* mode16 __asm__("$16");
            register int mode17 __asm__("$17");
            register int callback18 __asm__("$18");
            mode16 = &Physics30Data6E044View1;
            workWord3 = Physics30Field(mode16, int*, 0);
            mode17 = 40;
            if (workWord3 == mode17)
                goto callback131;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics30Call40D10View2(3840);
            workWord2 = Physics30Data6E538View1 & 12;
            if (workWord2)
                Physics30PlayerACView1 = 0;
            workWord2 = Physics30Call416F4View1();
            workWord3 = Physics30Field(mode16, int*, 0);
            callback18 = workWord2;
            if (workWord3 == mode17) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else {
                call4 = (void*)90;
                call5 = (void*)16;
            }
            workWord2 = Physics30Call41580View2(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics30PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics30Data6E538View1 & 12;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics30Player144View1;
            workWord2++;
            Physics30Player144View1 = workWord2;
            goto saved116;
        reset116:
            Physics30Player144View1 = 0;
        saved116:
            call4 = &Physics30PlayerACView1;
            globalVector80 = (void*)Physics30Field(call4, int*, 0);
            if (callback18)
                goto collision116;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass116;
        collision116:
            workWord2 = Physics30Player20CView1 & 64;
            if (workWord2)
                Physics30Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics30PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics30Field(call4, int*, 0) = workWord3;
            }
        pass116:
            Physics30Call417FCView2(320, 192);
            workWord2 = Physics30Player101View1;
            call4 = &Physics30PlayerACView1;
            Physics30Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics30ClearVectorView1(call4 - 32);
                goto fields116;
            }
            Physics30Call41848View1(call4);
            Physics30Call41B64View2();
        fields116:
            call6 = &Physics30PlayerFCView1;
            workWord2 = Physics30Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics30PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto scalar130;
            goto vector130Input;
        }
        case 118:
            Physics30Call40D10View2(3200);
            workWord3 = Physics30Data6E044View1;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics30Call41580View2(call4, call5);
            Physics30Call417FCView2(320, 192);
            globalFieldA4Pointer = &Physics30PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics30InterpolateCosineView1(Physics30Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics30PlayerB0View1;
            agentProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics30Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spD8 = workWord2;
            workWord2 = Physics30InterpolateSineView1(call4);
            workWord3 = Physics30PlayerB0View1;
            agentProduct1 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spD8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spDC = workWord2;
            Physics30SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.spE0 = 0;
        vector118Read:
            __asm__ volatile("" ::"i"(0x80089798) : "memory");
            workWord2 = Physics30MeasureVectorLengthView1(call4, call5);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            call5 = (void*)workWord2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            workWord2 = (int)call5 < 641;
            MATCHING_KEEP(globalFieldA4Pointer);
            call4 = globalFieldA4Pointer - 36;
            if (!workWord2) {
                Physics30ScaleVectorRatioQ15View1(vectorAt40, call5, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                call4 = globalFieldA4Pointer - 36;
            }
            Physics30AddVectorView1(call4, globalVector8C, vectorAt40);
            Physics30Call41B64View1();
        gate118:
            __asm__ volatile("" ::"i"(0x800897D4) : "memory");
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics30Player4CView1;
            __asm__ volatile("" ::"i"(0x800897EC) : "memory");
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics30Data6C570View1;
            workWord2 = Physics30Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics30Player144View1;
            __asm__ volatile("" ::"i"(0x80089820) : "memory");
            if (!workWord2)
                goto subtract192_130;
            __asm__ volatile("" ::"i"(0x80089828) : "memory");
            goto add23_130;
        case 119:
            globalFieldA4Pointer = &Physics30Player50View1;
            workWord3 = Physics30Field(globalFieldA4Pointer, int*, 0);
            workWord2 = 3;
            if (workWord3 != workWord2)
                goto airborne119;
            Physics30Call40D10View2(1600);
            Physics30Call41580View2(22, 4);
            Physics30Call417FCView2(320, 192);
            globalVector8C = globalFieldA4Pointer + 60;
            workWord2 = Physics30InterpolateCosineView1(Physics30PlayerA4View1);
            workWord3 = Physics30PlayerB0View1;
            agentProduct2 = workWord3 * workWord2;
            call4 = (void*)Physics30PlayerA4View1;
            workWord2 = agentProduct2 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spE8 = workWord2;
            workWord2 = Physics30InterpolateSineView1(call4);
            workWord3 = Physics30PlayerB0View1;
            agentProduct3 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spE8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spEC = workWord2;
            Physics30SubtractVectorView1(call4, call5, call6);
            originalFrame.spF0 = 0;
            temp_v0_4 = Physics30MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 48;
            if (temp_v0_4 >= 321) {
                Physics30ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 320);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 48;
            }
            Physics30AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics30Call41B64View1();
            workWord2 = Physics30Player94View2;
            workWord2 -= 192;
            Physics30Player94View2 = workWord2;
            workWord2 = workWord2 < -8960;
            goto clamp119;
        airborne119:
            Physics30Call40D10View2(3200);
            workWord3 = Physics30Data6E044View1;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics30Call41580View2(call4, call5);
            Physics30Call417FCView2(320, 192);
            globalFieldA4Pointer = &Physics30PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics30InterpolateCosineView1(Physics30Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics30PlayerB0View1;
            agentProduct4 = workWord3 * workWord2;
            call4 = (void*)Physics30Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spE8 = workWord2;
            workWord2 = Physics30InterpolateSineView1(call4);
            workWord3 = Physics30PlayerB0View1;
            agentProduct5 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spE8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct5 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spEC = workWord2;
            Physics30SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.spF0 = 0;
            goto vector118Read;
        case 121:
            vectorAt40 = &originalFrame.spF8;
            Physics30ClearVectorView1(vectorAt40);
            call4 = vectorAt40;
            call5 = call4;
            Physics30SubtractVectorView2(call4, call5, &Physics30Player8CView1);
            workWord2 = Physics30PlayerB8View1;
            call4 = vectorAt40;
            if (!workWord2)
                goto detached121;
            originalFrame.sp100 = 0;
            workWord2 = Physics30MeasureVectorLengthView2(call4, 0);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 9;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)8;
            goto limit121;
        detached121:
            workWord2 = Physics30MeasureVectorLengthView2(call4, 1);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 65;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)64;
        limit121:
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(call4, call5, call6, "memory");
            Physics30ScaleVectorRatioQ15View2(call4, call5, call6);
        vectors121:
            globalVector80 = &Physics30Player80View1;
            call4 = globalVector80;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            globalFieldA4Pointer = globalVector80 + 12;
            call5 = globalFieldA4Pointer;
            call6 = &originalFrame.spF8;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call5, call6, "memory");
            workWord2 = -192;
            originalFrame.sp100 = workWord2;
            Physics30AddVectorView2(call4, call5, call6);
            Physics30CopyVectorView1(globalFieldA4Pointer, globalVector80);
            workWord2 = Physics30Player94View2;
            workWord2 = workWord2 < -8960;
        clamp119:
            if (workWord2) {
                workWord2 = -8960;
                Physics30Player94View2 = workWord2;
            }
            return;
        case 122:
        case 123: {
            int boundedScalar122;
            int numerator122a, numerator122b;
            register void* child18 __asm__("$18");
            register void* position19 __asm__("$19");
            register void* player20 __asm__("$20");
            register void* input16 __asm__("$16");
            register int trig17 __asm__("$17");
            register void* vector17 __asm__("$17");
            register int length16 __asm__("$16");
            register int secondTrig16 __asm__("$16");
            register int numeric5 __asm__("$5");
            call4 = &originalFrame.sp108;
            workWord2 = Physics30Player250View1;
            child18 = Physics30Field((void*)workWord2, void**, 0);
            Physics30Call40F48View1(call4, 0);
            input16 = &Physics30Data6E040View1;
            workWord2 = Physics30InterpolateCosineView2(Physics30Field(input16, short*, 0));
            position19 = child18 + 100;
            trig17 = workWord2;
            workWord2 = Physics30InterpolateSineView2(Physics30Field(input16, short*, 0));
            workWord3 = originalFrame.sp10C;
            numeric5 = workWord3 * trig17;
            workWord3 = originalFrame.sp108;
            workWord3 *= workWord2;
            call4 = (void*)Physics30Field(input16, short*, 0);
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.sp110 = workWord2;
            workWord2 = Physics30InterpolateCosineView2(call4);
            call4 = (void*)Physics30Field(input16, short*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            secondTrig16 = workWord2;
            workWord2 = Physics30InterpolateSineView2(call4);
            workWord3 = originalFrame.sp108;
            workWord3 = -workWord3;
            numeric5 = workWord3 * secondTrig16;
            workWord3 = originalFrame.sp10C;
            workWord3 *= workWord2;
            vector17 = &originalFrame.sp110;
            call4 = vector17;
            player20 = &Physics30Player0View2;
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.sp114 = workWord2;
            workWord2 = Physics30Field(child18, int*, 100);
            workWord3 = originalFrame.sp110;
            call6 = player20;
            workWord2 += workWord3;
            Physics30Field(child18, int*, 100) = workWord2;
            workWord2 = Physics30Field(child18, int*, 104);
            workWord3 = originalFrame.sp114;
            call5 = position19;
            workWord2 += workWord3;
            Physics30Field(child18, int*, 104) = workWord2;
            Physics30SubtractVectorView2(call4, call5, call6);
            originalFrame.sp118 = 0;
            workWord2 = Physics30MeasureVectorLengthView2(vector17, 0);
            length16 = workWord2;
            workWord2 = length16 < 13313;
            if (!workWord2) {
                call4 = vector17;
                call5 = (void*)length16;
                call6 = (void*)13312;
                goto clamp122;
            }
            workWord2 = length16 < 1024;
            call4 = vector17;
            if (!workWord2)
                goto selector122;
            call5 = (void*)length16;
            call6 = (void*)1024;
        clamp122:
            Physics30ScaleVectorRatioQ15View2(call4, call5, call6);
            Physics30AddVectorView2(position19, player20, vector17);
        selector122:
            call4 = (void*)originalFrame.sp110;
            call5 = (void*)originalFrame.sp114;
            workWord2 = Physics30PlanarHeadingLookupView2(call4, call5, 1);
            workWord3 = Physics30Data6E044View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            Physics30PlayerA4View1 = workWord2;
            workWord2 = 40;
            call4 = (void*)24;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)4;
            Physics30Call41580View2(call4, call5);
            workWord2 = length16 < 6145;
            if (workWord2)
                goto below122;
            boundedScalar122 = (length16 - 6144) / 56 + 384;
            goto store122;
        below122:
            boundedScalar122 = 384 - ((6144 - length16) / 40);
        store122:
            MATCHING_OBSERVE_VOLATILE_CLOBBER(length16, "memory");
            Physics30Field(child18, int*, 92) = boundedScalar122;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = Physics30Field(child18, int*, 92);
            workWord2 = workWord2 < 256;
            if (workWord2)
                Physics30Field(child18, int*, 92) = 256;
            workWord2 = Physics30Field(child18, int*, 92);
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics30Field(child18, int*, 92) = 512;
            call4 = (void*)Physics30Player250View1;
            Physics44Slot432C(call4);
            return;
        }
        case 124:
        case 129:
        clear30:
            globalVector80 = &Physics30Player0View3 + 0x80;
            Physics30ClearVectorView2(globalVector80);
            Physics30ClearVectorView2(globalVector80 + 0xC);
            return;
        case 130: {
            register int callback17 __asm__("$17");
            globalVector80 = &Physics30Player50View1;
            workWord3 = Physics30Field(globalVector80, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto airborne130;
            workWord2 = 8;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            globalVector80 = &Physics30Data6E044View1;
            MATCHING_KEEP(globalVector80);
            workWord3 = Physics30Field(globalVector80, int*, 0);
            if (workWord3 != workWord2)
                Physics30Call40D10View2(3840);
            workWord2 = Physics30Data6E538View1 & 12;
            if (workWord2)
                Physics30PlayerACView1 = 0;
            workWord2 = Physics30Call416F4View1();
            callback17 = workWord2;
            workWord3 = Physics30Field(globalVector80, int*, 0);
            workWord2 = 40;
            call4 = (void*)90;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)16;
            workWord2 = Physics30Call41580View2(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics30PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics30Data6E538View1 & 12;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics30Player144View1;
            workWord2++;
            Physics30Player144View1 = workWord2;
            goto saved130;
        reset130:
            Physics30Player144View1 = 0;
        saved130:
            call4 = &Physics30PlayerACView1;
            globalVector80 = (void*)Physics30Field(call4, int*, 0);
            if (callback17)
                goto collision130;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass130;
        collision130:
            workWord2 = Physics30Player20CView1 & 64;
            if (workWord2)
                Physics30Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics30PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics30Field(call4, int*, 0) = workWord3;
            }
        pass130:
            Physics30Call417FCView2(320, 192);
            workWord2 = Physics30Player101View1;
            call4 = &Physics30PlayerACView1;
            Physics30Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics30ClearVectorView1(call4 - 32);
                goto fields130;
            }
            Physics30Call41848View1(call4);
            Physics30Call41B64View2();
        fields130:
            call6 = &Physics30PlayerFCView1;
            workWord2 = Physics30Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics30PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector130Input;
        scalar130:
            workWord2 = Physics30PlayerA0View1;
            workWord2 -= 192;
            Physics30Player94View2 = workWord2;
            return;
        vector130Input:
            __asm__ volatile("" ::"i"(0x80089F04) : "memory");
            call5 = call4;
            Physics30AddVectorView2(call4, call5, call6 - 20);
            return;
        airborne130:
            Physics30Call40D10View2(3200);
            workWord3 = Physics30Data6E044View1;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics30Call41580View2(call4, call5);
            Physics30Call417FCView2(320, 192);
            globalFieldA4Pointer = &Physics30PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics30InterpolateCosineView1(Physics30Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics30PlayerB0View1;
            agentProduct6 = workWord3 * workWord2;
            call4 = (void*)Physics30Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct6 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp120 = workWord2;
            workWord2 = Physics30InterpolateSineView1(call4);
            workWord3 = Physics30PlayerB0View1;
            agentProduct7 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.sp120;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct7 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp124 = workWord2;
            Physics30SubtractVectorView1(call4, call5, call6);
            originalFrame.sp128 = 0;
            temp_v0_4 = Physics30MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 36;
            if (temp_v0_4 >= 641) {
                Physics30ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 36;
            }
            Physics30AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics30Call41B64View1();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics30Player4CView1;
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics30Data6C570View1;
            workWord2 = Physics30Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics30Player144View1;
            if (!workWord2)
                goto subtract192_130;
        add23_130:
            workWord2 = Physics30Player94View2;
            workWord2 += 23;
            Physics30Player94View2 = workWord2;
            return;
        subtract192_130:
            globalPointer = &Physics30Player94View2;
            workWord2 = Physics30Field(globalPointer, int*, 0);
            workWord2 -= 192;
            Physics30Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 131:
        case 132:
            goto callback131;
    }
    return;
callback131:
    __asm__ volatile("" ::"i"(0x8008A094) : "memory");
    Physics44Slot4454();
    return;
}
#undef Physics30Field


/* AI generated; not human reviewed. SCUS-94467 8008A0CC..8008A774.
 * Newly hash-verified44_800902B4 supplies scalar/clamp and descriptor-table
 * producers; its source chain is verified43 and verified50. Original30 adds
 * case1C and removes case39. Exact original30 instructions control acceptance.
 * Original30 supplies every selector and numeric access; byte offsets and helper
 * names establish no units, meanings or caller cadence. All code/table words,
 * strict complete translation unit and every retail hash required for acceptance.
 */
extern int Callback30Step __asm__("D_80070328+0x144");
extern int Callback30Z __asm__("D_80070328+8");
extern int Callback30Limit __asm__("D_80070328+0x280");
extern Spyro Callback30Player __asm__("D_80070328");
int Callback30Call80037058(int x, int y) __asm__("func_80037058");
int Callback30Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback30Call80041930(void) __asm__("func_80041930");
void Callback30Call80041AE8(void) __asm__("func_80041AE8");
void Callback30Call80041C20(void) __asm__("func_80041C20");
void Callback30Call80042A44(void) __asm__("func_80042A44");
void Callback30Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback30Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38, D_8006C648;
int Callback30Query(Vector3D*, int) __asm__("func_8001A358");
int Callback30Length(Vector3D*, int) __asm__("func_8004EDE8");
extern int Callback30Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback30Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback30Values[] __asm__("D_8006FCF0");
void Callback30Call80049590(void) __asm__("func_80049590");
void func_level_30_8008A0CC(void) {
    struct {
        Vector3D first;
        int reserved1C;
    } local;
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback30Player.animationState) {
        case 0x73:
        case 0x78:
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7E:
            if (func_800438F4() == 0) {
                func_80043728();
            }
            Callback30Call80041C20();
            Callback30Player.unk9a = 0;
            Callback30Call80042A44();
            goto clearSharedValue;
        default:
            return;
        case 0x80:
            Callback30Call80041C20();
            Callback30Call80042A44();
            goto clearSharedValue;
        case 0x79:
            Callback30Call80041C20();
            Callback30Call80042A44();
            goto queryC00;
        case 0x1C:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
            if (Callback30Player.unk7a[3].z < 0 && Callback30Player.animationStateFrames >= 4)
                Callback30Player.unk5 = 1;
            goto clearSharedValue;
        case 0x81: {
            register int* zWord __asm__("$5") = &Callback30Z;
            register int velocity __asm__("$6") = Callback30Step;
            register int scalarPosition __asm__("$2") = *zWord;
            register int tick __asm__("$3") = D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            MATCHING_KEEP(velocity);
            MATCHING_KEEP(scalarPosition);
            MATCHING_KEEP(tick);
            increment = velocity >> 6;
            MATCHING_KEEP(increment);
            scalarPosition += increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(scalarPosition));
            tick <<= 9;
            *zWord = scalarPosition;
            status = Callback30Limit;
            velocity += tick;
            Callback30Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback30Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback30Step = 0x2580;
            }
        limitsDone:
            Callback30Call80041C20();
            Callback30Call80042A44();
            func_8004F178(&local.first, &Callback30Player.position);
            local.first.z += 0x400;
            Callback30Player.unk4[0] = Callback30Query(&local.first, 0xC00);
            positionDelta = (int)Callback30Player.union144.a.unk13cb;
            positionValue = Callback30Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
        case 0x28:
        case 0x29:
            Callback30Call80041C20();
            Callback30Call80042A44();
            descriptor = &Callback30Player.unk22[2];
            if (Callback30Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback30Values + valueOffset);
                {
                    register int below __asm__("$2") = decreasingValue < 0xC8;
                    MATCHING_KEEP_VOLATILE_CLOBBER(below, "$4");
                    if (!below)
                        goto setTableFlag;
                    tableValue = decreasingValue - 0xC8;
                    goto storeTableValue;
                }
                goto setTableFlag;
            }
            goto clearSharedValue;
        case 0x2A:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80049590();
            descriptor = &Callback30Player.unk22[2];
            if (Callback30Call8003BF6C((int)D_8006C654->underwater, *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback30Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback30Player.unk22[2];
            }
            if (Callback30Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback30Values + valueOffset);
                {
                    register int below __asm__("$2") = increasingValue < 0x13E8;
                    MATCHING_KEEP_VOLATILE_CLOBBER(below, "$4");
                    if (!below)
                        goto setTableFlag;
                    tableValue = increasingValue + 0xC8;
                    goto storeTableValue;
                }
                goto setTableFlag;
            storeTableValue:
                *(int*)(Callback30Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback30Flags[flagOffset] = Callback30Flags[flagOffset] | 0x10;
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041AE8();
            if ((unsigned char)Callback30Player.unk10[4] != 0) {
                computedValue = -Callback30Player.unk9ha[4] -
                                Callback30Call80037058(Callback30Player.position.x,
                                                       Callback30Player.position.y);
                positionValue = Callback30Player.unk4a - computedValue;
                Callback30Player.unk4[0] = computedValue;
                positionDelta = (int)Callback30Player.union144.a.unk13cc >> 6;
                goto storePosition;
            }
            break;
        storePosition:
            positionValue -= positionDelta;
            MATCHING_KEEP(positionValue);
            Callback30Player.position.z = positionValue;
            return;
        case 0x2F:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
            func_80042F64();
            goto clearSharedValue;
        case 0x32:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
            func_80042F64();
            numerator = (int)((unsigned int)Callback30Player.unk7a[3].z << 2);
            Callback30Player.unk4[0] = 0;
            {
                register int quotient __asm__("$3") =
                    (int)((unsigned int)ABS(numerator) + 0x300U) / 1536;
                MATCHING_KEEP(quotient);
                clampedValue = quotient << 4;
            }
            belowLimit = clampedValue < 0x10;
            MATCHING_KEEP(belowLimit);
            if (belowLimit) {
                clampedValue = 0x10;
                goto compareUpperLimit;
            }
            goto compareUpperLimit;
        case 0x33:
        case 0x34:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
            func_80042F64();
            Callback30Player.unk4[0] = 0;
            {
                register int quotient __asm__("$3") =
                    (int)(((unsigned int)Callback30Length(
                               (Vector3D*)((unsigned char*)Callback30Player.unk4 + 0x70), 0)
                           << 2) +
                          0x300U) /
                    1536;
                MATCHING_KEEP(quotient);
                clampedValue = quotient << 4;
            }
            belowLimit = clampedValue < 8;
            MATCHING_KEEP(belowLimit);
            if (belowLimit) {
                clampedValue = 8;
                goto compareUpperLimit;
            }
            goto compareUpperLimit;
        compareUpperLimit:
            belowLimit = clampedValue < 0x41;
        applyUpperLimit:
            if (!belowLimit)
                clampedValue = 0x40;
            func_800443A4(clampedValue);
            return;
        case 0x76:
        case 0x77:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
            if (Callback30Player.unk5 != 0x7F) {
                if ((Callback30Player.unk7a[3].z < 0) &&
                    (Callback30Player.animationStateFrames >= 4)) {
                    Callback30Player.unk5 = 1;
                } else {
                    goto checkSecondFlag;
                }
            }
            goto clearSharedValue;
        case 0x82:
            if (Callback30Player.movementState != MOVEMENT_STATE_WALK)
                goto other82;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
        queryC00:
            Callback30Call80043A38(0xC00);
            goto clearSharedValue;
        other82:
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
            if ((Callback30Player.unk7a[3].z < 0) && (Callback30Player.animationStateFrames >= 4)) {
                Callback30Player.unk5 = 1;
            } else {
            checkSecondFlag:
                if ((Callback30Player.unk5 == 0) && !(Callback30Word8006E538 & 0x40) &&
                    (Callback30Player.union144.a.unk13cb == 0)) {
                    Callback30Player.unk5 = 2;
                }
            }
        clearSharedValue:
            Callback30Player.unk4[0] = 0;
            return;
    }
}


#define LEVEL_ID 30
#define PlaySpyroSounds_level_30 func_level_30_8008A778
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_30_8008A9B4(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x1c:
        case 0x76:
        case 0x77:
            func_80043ABC(0);
            break;
        case 0x2f:
        case 0x32:
        case 0x33:
        case 0x34:
            func_80043F3C(&spyro.unk9h);
            break;
        case 0x82: {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            MATCHING_KEEP(state);
            if (*state)
                func_80043ABC(0);
            else
                func_80043ABC(&spyro.unk9e);
        } break;
        case 0x2b:
        case 0x2c:
        case 0x73:
        case 0x74:
        case 0x75:
        case 0x78:
        case 0x79:
        case 0x7a:
        case 0x7b:
        case 0x7c:
        case 0x7e:
        case 0x80:
        case 0x81:
        case 0x83:
        case 0x84:
            func_80043ABC(&spyro.unk9e);
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008AA5C.
 * Reuses verified43 surface and33/46 special-state routes. Original30 supplies
 * independent stack10/20 underwater vectors, stack30 surface vector, selector1C
 * and a single ladder block. Byte offsets: scalar60; helper vectors14C/98;
 * second helper vectors14C/98 from animation48; stores130=20000 and158=0.
 * The scalar wraps with FFF, subtracts1000 for values>=801, then clamps positives
 * to zero. Falsifiable inputs800/801/FFF yield0/-7FF/-1 before helper callbacks.
 * Signed words/halfwords, shifts, pointer byte arithmetic and callback reloads
 * follow original instructions. Unused stack words preserve original spacing;
 * they do not establish source variables. Empty constraints emit no opcodes.
 * Acceptance requires every code/local jump/owned dispatch word, strict full TU,
 * and complete EXE/every overlay hashes. Helper meanings, numeric conversions,
 * audio semantics, caller cadence and live runtime parity remain unverified.
 */

extern Spyro Transition30_D_80070328 __asm__("D_80070328");
int Transition30MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition30_func_800441F0(void) __asm__("func_800441F0");
void Transition30ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition30_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition30RawUnion[] __asm__("D_80070328+0x144");
extern int Transition30RawMovement __asm__("D_80070328+0x50");
extern int Raw30Movement __asm__("D_80070328+0x50");
extern int Raw30Union __asm__("D_80070328+0x144");
void Call30ED6C(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
extern void (*Call30Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw30State[] __asm__("D_80070328+0x50");
extern Spyro Special30_D_80070328 __asm__("D_80070328");
extern short Signed30TableA[] __asm__("D_800658A0");
extern short Signed30TableB[] __asm__("D_80065920");
int Special30MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Special30_func_80043A38(int scale) __asm__("func_80043A38");
void Special30_func_800441F0(void) __asm__("func_800441F0");
void Special30ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Special30_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call30A358(Vector3D*, int) __asm__("func_8001A358");
extern int Raw30NegativeWord __asm__("D_80070328+0x28");
void func_level_30_8008AA5C(int arg0) {
    struct {
        Vector3D first;
        int gap1;
        Vector3D second;
        int gap2;
        Vector3D third;
    } vectors;
    register int previousMovement __asm__("$3");
    register int negativeWord __asm__("$3");
    int firstResult, secondResult, firstWrappedWord, secondWrappedWord, firstParticleKind,
        secondParticleKind, firstParticleSubtype, secondParticleSubtype;
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int groundValue __asm__("$2");
    switch (arg0) {
        case 0x1C:
            previousMovement = Transition30RawMovement;
            MATCHING_KEEP(previousMovement);
            Transition30RawMovement = MOVEMENT_STATE_HURT;
            Transition30_D_80070328.unk5 = 0;
            Transition30_D_80070328.union144.a.unk13cb = previousMovement;
            Transition30_func_800441F0();
            Transition30_D_80070328.unk7a[2].z = 0xDC0;
            Transition30_D_80070328.grounded = 0;
            Transition30_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition30_D_80070328.damageFlags & 0x200) {
                Transition30_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition30_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            goto clearPointers;
        case 0x28:
        case 0x29:
            if (((unsigned)(Transition30_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition30_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition30_D_80070328.movementState - 0x50));
                    if ((Transition30_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw30NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition30_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call30A358(&vectors.first, 0x800);
                        vectors.first.z = firstResult;
                        if (firstResult != 0) {
                            firstParticleKind = 6;
                            if (D_80071934 != 0) {
                                firstParticleSubtype = 0x2E;
                            emitFirstParticle:
                                SpawnParticle(firstParticleKind, firstParticleSubtype,
                                              &vectors.first, 0);
                            }
                        }
                    }
                }
                firstWrappedWord = Transition30_D_80070328.rotation.pitch & 0xFFF;
                Transition30_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition30_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition30_D_80070328.rotation.pitch > 0) {
                    Transition30_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition30_D_80070328.unk5 = 1;
                }
                Transition30ClearVector(
                    (Vector3D*)((unsigned char*)&Transition30_D_80070328.rotation.pitch + 0xEC));
                Transition30_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition30_D_80070328.unk8[0] = Transition30MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition30_D_80070328.rotation.pitch + 0x38), 0);
                Transition30_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition30_D_80070328.animationState == 0x2A) {
                Transition30_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition30_D_80070328.union144.a.unk13da = 0;
            }
            Transition30_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition30_D_80070328.unk20a = 0;
            Transition30_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw30State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw30NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition30_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call30A358(localVector, 0x800);
                        vectors.second.z = secondResult;
                        if (secondResult != 0) {
                            secondParticleKind = 6;
                            if (D_80071934 != 0) {
                                secondParticleSubtype = 0x2E;
                            emitSecondParticle:
                                SpawnParticle(secondParticleKind, secondParticleSubtype,
                                              localVector, 0);
                            }
                        }
                    }
                }
                if (Transition30_D_80070328.animationState == 0x2E) {
                    Transition30_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition30_D_80070328.rotation.pitch & 0xFFF;
                Transition30_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition30_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition30_D_80070328.rotation.pitch > 0) {
                    Transition30_D_80070328.rotation.pitch = 0;
                }
                Transition30_D_80070328.unk5 = 1;
                Transition30ClearVector(
                    (Vector3D*)((unsigned char*)&Transition30_D_80070328.animationState + 0x104));
                Transition30_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition30_D_80070328.unk8[0] = Transition30MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition30_D_80070328.animationState + 0x50), 0);
                Transition30_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition30_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition30_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition30RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition30RawUnion;
                    *(int*)unionPointer = (-Transition30_D_80070328.unk7a[2].z) >> 2;
                    if (Transition30RawMovement != 8) {
                        Transition30_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition30RawMovement = 10;
                    }
                    Transition30_D_80070328.unk5 = 0;
                    Transition30_D_80070328.unk8[0] =
                        Transition30MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition30_D_80070328.grounded = 1;
                    Transition30_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call30A358(localVector, 0x800);
                    vectors.third.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, localVector, 0);
                        SpawnParticle(6, 0x2E, localVector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        case 0x2F:
        case 0x32:
        case 0x33:
        case 0x34:
            savedBase = (unsigned char*)&Transition30RawMovement;
            destination = (Vector3D*)(savedBase + 0x3C);
            if (*(int*)savedBase != 13) {
                *(int*)savedBase = 13;
                Transition30_D_80070328.unk5 = 0;
                func_8004F178(destination, (Vector3D*)(savedBase + 0x48));
                Transition30_D_80070328.grounded = 1;
            }
        clearPointers:
            Transition30_D_80070328.unk20a = 0;
            Transition30_D_80070328.critterMobyPtr = 0;
            return;
        case 0x73:
        case 0x78:
        case 0x7E:
            Special30_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Special30_D_80070328.unk5 = 0;
            Special30_func_800441F0();
            Special30_D_80070328.grounded = 1;
            return;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            walkBase = Raw30State;
            walkFlag = 1;
            MATCHING_KEEP(walkFlag);
            *(int*)walkBase = walkFlag;
            if (arg0 == 0x57 && Special30_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                MATCHING_BARRIER_VOLATILE("memory");
                destination = (Vector3D*)(walkBase + 0x3C);
                goto copyWalkVector;
            }
            goto clearWalkFlag;
        case 0x80:
            Special30_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Special30_D_80070328.unk5 = 0;
            Special30_func_80043A38(0xC00);
            Special30_D_80070328.grounded = 1;
            Special30_D_8006E524 = 0xF;
            return;
        case 0x81: {
            register int oldState __asm__("$3") = Raw30Movement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Raw30Movement = value;
            value = 1;
            MATCHING_KEEP(value);
            Special30_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Special30_D_8006E524 = value;
            Special30_D_80070328.unk5 = 0;
            stateWord = &Raw30Union;
            MATCHING_KEEP(stateWord);
            Special30_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Special30_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            Special30_D_80070328.unk22[3] = (int)D_8006C654->drown;
            return;
        }
        case 0x79:
            Special30_D_80070328.movementState = MOVEMENT_STATE_HURT;
            Special30_D_80070328.unk5 = 0;
            if (Special30_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Special30_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed30TableB + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                tableValueA >>= 1;
                Special30_D_80070328.unk7a[2].x = tableValueA;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed30TableA + tableOffsetOrValue);
                Special30_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Special30_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else {
                Special30ClearVector(
                    (Vector3D*)((unsigned char*)&Special30_D_80070328.movementState + 0x3C));
            }
            Special30_D_80070328.unk7a[2].z = 0x200;
            func_8004F178((Vector3D*)((unsigned char*)&Special30_D_80070328.unk7a[2].z - 0x14),
                          (Vector3D*)((unsigned char*)&Special30_D_80070328.unk7a[2].z - 8));
            Special30_D_80070328.grounded = 1;
            Special30_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
                return;
            }
        default:
            return;
        case 0x7A: {
            register unsigned char* privateData __asm__("$17") =
                Special30_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* state __asm__("$18") = Raw30State;
            register Vector3D* vector __asm__("$16");
            *(int*)state = 0;
            Special30_D_80070328.unk5 = 0;
            vector = (Vector3D*)(privateData + 0x64);
            Special30_func_800441F0();
            Special30_D_80070328.grounded = 1;
            Special30_D_80070328.idle = 0;
            Special30_D_80070328.unk15g = 0;
            *(int*)(privateData + 0x5C) = 0x180;
            *(int*)(privateData + 0x64) = 0x1800;
            *(int*)(privateData + 0x68) = 0;
            *(int*)(privateData + 0x6C) = 0;
            Call30ED6C((Vector3D*)(state - 0x20), vector, vector);
            func_8004F194(vector, vector, (Vector3D*)(state - 0x50));
            Call30Header(Special30_D_80070328.critterMobyPtr);
            return;
        }
        case 0x7B:
            Special30_D_80070328.movementState = 0;
            Special30_func_800441F0();
            groundValue = 1;
            goto sharedGround;
        case 0x7C: {
            register unsigned char* privateData __asm__("$16") =
                Special30_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* child __asm__("$4");
            Special30_D_80070328.movementState = 0;
            Special30_func_800441F0();
            Special30_D_80070328.grounded = 1;
            Special30_D_80070328.idle = 0;
            Special30_D_80070328.unk15g = 0;
            child = *(unsigned char**)(privateData + 0x78);
            if (child) {
                if (*(short*)(privateData + 0x74) == 0x22A)
                    child[0x48] = 0x50;
                else
                    child[0x48] = 1;
            }
            return;
        }
        case 0x76:
            stateBaseA = Raw30State;
            MATCHING_KEEP(stateBaseA);
            destination = (Vector3D*)(stateBaseA + 0x3C);
            MATCHING_KEEP(destination);
            sourceBytesA = stateBaseA + 0x48;
            *(int*)stateBaseA = 2;
            func_8004F178(destination, (Vector3D*)sourceBytesA);
            Special30_D_80070328.unk8[0] = Special30MeasureVectorLength((Vector3D*)sourceBytesA, 0);
            Special30_D_80070328.unk7a[2].z = 0xDC0;
            Special30_D_80070328.unk5 = 0;
            if (Special30_D_80070328.animationState == 0x81)
                Special30_D_80070328.union144.a.unk13cb = 1;
            else
                Special30_D_80070328.union144.a.unk13cb = 0;
            Special30_D_80070328.grounded = 0;
            PlaySound((int)D_8006C654->jump, 0, 0);
            return;
        case 0x77: {
            register unsigned char* state __asm__("$6") = Raw30State;
            if (*(int*)state != 2) {
                *(int*)state = 3;
                Special30_D_80070328.unk8[0] =
                    Special30MeasureVectorLength((Vector3D*)(state + 0x48), 0);
                Special30_D_80070328.grounded = 0;
                Special30_D_80070328.unk15b = 1;
                goto clearTail;
            }
            return;
        }
        case 0x82: {
            walkBase = Raw30State;
            if (*(int*)walkBase != 2) {
                walkFlag = 1;
                MATCHING_KEEP(walkFlag);
                *(int*)walkBase = walkFlag;
                if (arg0 == 0x57 && Special30_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                    destination = (Vector3D*)(walkBase + 0x3C);
                copyWalkVector:
                    func_8004F178(destination, (Vector3D*)(walkBase + 0x48));
                    Special30_D_80070328.unk5 = walkFlag;
                } else {
                clearWalkFlag:
                    Special30_D_80070328.unk5 = 0;
                }
                Special30_D_80070328.unk8[0] = Special30MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Special30_D_80070328.movementState + 0x48), 0);
                Special30_func_80043A38(0xC00);
                groundValue = 1;
                MATCHING_KEEP(groundValue);
                Special30_D_80070328.union144.a.unk13cb = 0;
            sharedGround:
                Special30_D_80070328.grounded = groundValue;
            clearTail:
                Special30_D_80070328.idle = 0;
                Special30_D_80070328.unk15g = 0;
            }
            return;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008B568.
 * Assembly SHA256 d7dfd18611b06171628269baf9fefc3e6ede1433151ed42fec19e1b59529248e.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1515 original instructions and105 state-table entries (bias28).
 * Verified donor33 original115..132 state chains retain callback1, collision/input
 * priority, private78/7C/4C fields, masks and mode31/40 gates, signed products,
 * original partial effect/sound calls, counters, water/helper paths and the
 * shared selector119 call that restores the original saved word54 afterward.
 * The original0x18 frame retains savedS0. Generic
 * state C is reused from verified donors with every original selector/join.
 * Rev1's identified Agent9 callback/table and snapshot-writer decoders are
 * cross-references only; no browser-derived behavior or values are used.
 * Typed view aliases remain distinct; exact symbols are in provenance.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim30Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim30Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim30Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim30PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim30PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim30PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim30PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim30PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim30PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim30PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim30Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim30Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim30Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim30PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern unsigned char Anim30Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim30Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern int Anim30Data6E538View1 __asm__("D_8006E538"), Anim30Data6E53CView1 __asm__("D_8006E53C");
int Anim30Call40994View1() __asm__("func_80040994");
int Anim30Call4BEF8View1() __asm__("func_8004BEF8");
extern int Anim30PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim30PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim30Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim30Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim30PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim30Data6E538View2 __asm__("D_8006E538"), Anim30Data6E53CView2 __asm__("D_8006E53C");
extern int Anim30Data6E044View1 __asm__("D_8006E044"), A21Gate __asm__("D_8006E344"),
    A21Count __asm__("D_8006C514");
extern int (*Anim30Data74374View1)() __asm__("unk_ovlheader_80074374");
int Anim30Call40994View2() __asm__("func_80040994");
int Anim30Call4BEF8View2() __asm__("func_8004BEF8");
extern volatile int Anim30Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim30Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim30Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim30Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim30Data6EE2CView1 __asm__("D_8006EE2C");
int Anim30Call40BCCView1() __asm__("func_80040BCC");
int Anim30Call1A310View1() __asm__("func_8001A310");
extern int Anim30Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim30Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim30Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim30Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim30Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim30Player90View2 __asm__("D_80070328 + 0x90");
extern int Anim30Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim30PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim30PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim30PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim30PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim30PlayerCCView2 __asm__("D_80070328 + 0xCC");
extern int Anim30PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim30PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim30PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim30Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim30Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char* Anim30Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim30Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim30Data6E535View2 __asm__("D_8006E535");
extern int Anim30Data6E538View3 __asm__("D_8006E538");
extern int Anim30Data6E53CView3 __asm__("D_8006E53C");
extern int Anim30Data6E530View1 __asm__("D_8006E530");
extern int Anim30Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char* Anim30Data6C654View1 __asm__("D_8006C654");
extern int (*Anim30Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim30DataSpawnParticleView1)(int, int, void*, int) __asm__("SpawnParticle");
int Anim30Call55E84View1(void*) __asm__("func_80055E84");
int Anim30Call4BEF8View3(int) __asm__("func_8004BEF8");
int Anim30CallPlaySoundView1(unsigned char, int, int) __asm__("PlaySound");
extern int Anim30PlayerB4View2 __asm__("D_80070328 + 0xB4");
extern int Anim30Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim30Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim30Data6E044View2 __asm__("D_8006E044");
int Anim30Call498C0View1(void*) __asm__("func_800498C0");
int Anim30Call3BF6CView1(int, int) __asm__("func_8003BF6C");
int Anim30Call3BE70View1(int) __asm__("func_8003BE70");
#define Anim30Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_level_30_8008B568(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int savedWord16 __asm__("$16");
    rawValue2 = Anim30Player48View1;
    switch (rawValue2) {
        case 28:
            if (!Anim30PlayerB8View1 && Anim30Player54View1 >= 16 && Anim30PlayerE4View1 < 23) {
                rawValue3 = Anim30PlayerCCView1;
                rawValue2 = Anim30Player8CView1;
                product5 = rawValue3 * rawValue2;
                rawValue3 = Anim30PlayerD0View1;
                rawValue2 = Anim30Player90View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = Anim30PlayerD4View1;
                rawValue2 = Anim30Player94View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                if (rawValue2 < 0) {
                    if (Anim30PlayerACView1) {
                        rawValue3 = Anim30PlayerB0View1;
                        if (rawValue3 >= 3841) {
                            nextSelector4 = 3;
                            goto select;
                        }
                        rawValue2 = rawValue3 < 1921;
                        nextSelector4 = 1;
                        if (rawValue2)
                            goto select;
                        nextSelector4 = 2;
                        goto select;
                    }
                    rawValue2 = Anim30PlayerB0View1 < 1920;
                    nextSelector4 = 0;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 4;
                    goto select;
                }
            }
            rawValue3 = Anim30Player4CView1;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30PlayerA0View1 < -6400;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            if (Anim30Player54View1 >= 91)
                goto select;
            return;
        case 40:
            if (Anim30Call40994View2())
                return;
            if ((Anim30Data6E538View2 & 128) && Anim30Player4CView2 != 1) {
                nextSelector4 = 42;
                goto select;
            }
            if (Anim30PlayerB0View2)
                return;
            rawValue2 = Anim30Player20CView1 & 64;
            nextSelector4 = 41;
            if (!rawValue2)
                goto select;
            if (Anim30Player214View1 <= 0)
                return;
            goto select;
        case 41:
            if (Anim30Call40994View2())
                return;
            nextSelector4 = Anim30Data6E538View2;
            rawValue2 = nextSelector4 & 128;
            if (rawValue2) {
                nextSelector4 = 42;
                goto select;
            }
            rawValue2 = 7;
            rawValue3 = Anim30Data6E044View1;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = nextSelector4 & 64;
            nextSelector4 = 40;
            if (rawValue2)
                goto select;
            if (!(Anim30Player20CView1 & 64))
                return;
            if (!Anim30Player214View1)
                goto select;
            return;
        case 42:
            if (Anim30Call40BCCView1())
                return;
            if ((Anim30Data6E538View2 & 128) || Anim30Player4CView2 == 1)
                goto flag64;
            rawValue2 = Anim30Player20CView1 & 128;
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        flag64:
            rawValue2 = Anim30Player20CView1 & 64;
            nextSelector4 = 40;
            if (!rawValue2)
                return;
            goto select;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (Anim30Call40994View2())
                return;
            if ((Anim30Data6E53CView2 & 64) && Anim30Player54View2 >= 9) {
                nextSelector4 = 6;
                goto partialCall;
            }
            byte4 = &Anim30Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto partialCall;
            }
            if (!(Anim30Data6E53CView2 & 128))
                goto check44;
            if (Anim30Player54View2 < 9)
                goto check44;
            rawValue2 = *(int*)(Anim30Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto check44;
            rawValue2 = Anim30Call1A310View1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (rawValue2)
                goto check44;
            goto select;
        partialCall:
            Anim30Call4BEF8View2(nextSelector4);
        check44:
            rawValue2 = Anim30Data6E535View1;
            nextSelector4 = 44;
            if (!rawValue2)
                return;
            goto select;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3 = Anim30Player4CView2;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                goto other44;
            if (Anim30Data6E53CView2 & 0x850)
                goto callback44;
            if (Anim30Player54View2 < 61)
                return;
        callback44:
            callback2 = Anim30Data74374View1;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto call498C0;
        other44:
            if (Anim30Call40994View2())
                return;
            if ((Anim30Data6E53CView2 & 64) && Anim30Player54View2 >= 9) {
                nextSelector4 = 6;
                goto select;
            }
            byte4 = &Anim30Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto select;
            }
            if (!(Anim30Data6E53CView2 & 128))
                goto mode44;
            if (Anim30Player54View2 < 9)
                goto mode44;
            rawValue2 = *(int*)(Anim30Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto mode44;
            rawValue2 = Anim30Call1A310View1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        mode44:
            rawValue3 = Anim30Data6E044View1;
            rawValue2 = 7;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = Anim30Data6E535View1;
            nextSelector4 = 43;
            if (rawValue2)
                return;
            goto select;
        }
        case 47:
            if (Anim30Call40994View1())
                return;
            if (Anim30Data6E53CView1 & 64) {
                rawValue2 = Anim30Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (rawValue2)
                    goto specialJump;
                MATCHING_BARRIER_VOLATILE("memory");
                goto select;
            }
            rawValue2 = Anim30PlayerACView1;
            nextSelector4 = 50;
            if (!rawValue2)
                return;
            goto select;
        case 50:
            if (Anim30Call40994View1())
                return;
            if (Anim30Data6E53CView1 & 64) {
                rawValue2 = Anim30Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (rawValue2)
                    goto specialJump;
                goto select;
            }
            rawValue2 = Anim30PlayerACView1;
            nextSelector4 = 47;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerA0View1;
            rawValue3 = Anim30PlayerB4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < rawValue3;
            if (!rawValue2)
                return;
            rawValue2 = Anim30PlayerA4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 52;
            if (!rawValue2)
                goto select;
            nextSelector4 = 51;
            goto select;
        case 51:
        case 52:
            if (Anim30Call40994View1())
                return;
            if (Anim30Data6E53CView1 & 64) {
                rawValue2 = Anim30Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (!rawValue2)
                    goto select;
            specialJump:
                Anim30Call4BEF8View1(7);
                rawValue2 = 3;
                Anim30Player4CView1 = rawValue2;
                return;
            }
            rawValue2 = Anim30PlayerACView1;
            nextSelector4 = 47;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerA0View1;
            rawValue3 = Anim30PlayerB4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < rawValue3;
            nextSelector4 = 50;
            if (rawValue2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto select;
        case 115:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne115;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground115;
        airborne115:
            __asm__ volatile("" ::"i"(0x8008BCC4) : "memory");
            nextSelector4 = 119;
            goto select;
        ground115:
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input115;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input115:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim30Data6E044View2;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim30Data6E044View2;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim30PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerACView2;
            if (rawValue2)
                goto select;
            rawValue2 = 25;
            rawValue3 = Anim30Field(record16, int*, 0x4C);
            nextSelector4 = 126;
            if (rawValue3 != rawValue2)
                return;
            goto select;
        case 116:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne116;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground116;
        airborne116:
            __asm__ volatile("" ::"i"(0x8008BE00) : "memory");
            nextSelector4 = 119;
            goto select;
        ground116:
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload116;
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload116:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim30Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input116:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8008BE98) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim30Data6E535View2;
            if (!rawValue2)
                goto afterLatch116;
            rawValue2 = Anim30PlayerB0View3;
            if (!rawValue2)
                goto latch116;
            rawValue2 = 40;
            rawValue3 = Anim30Data6E044View2;
            if (rawValue3 != rawValue2)
                goto afterLatch116;
        latch116:
            __asm__ volatile("" ::"i"(0x8008BEE4) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch116:
            rawValue2 = Anim30PlayerB4View2 < 3073;
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Call55E84View1((void*)nextSelector4);
            rawValue2 = rawValue2 < 37;
            nextSelector4 = 117;
            if (rawValue2)
                return;
            goto select;
        case 117:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne117;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground117;
        airborne117:
            __asm__ volatile("" ::"i"(0x8008BF7C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground117:
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload117;
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload117:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim30Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input117:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8008C014) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim30Data6E535View2;
            if (!rawValue2)
                goto afterLatch117;
            rawValue2 = Anim30PlayerB0View3;
            if (!rawValue2)
                goto latch117;
            rawValue2 = 40;
            rawValue3 = Anim30Data6E044View2;
            if (rawValue3 != rawValue2)
                goto afterLatch117;
        latch117:
            __asm__ volatile("" ::"i"(0x8008C060) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch117:
            rawValue2 = Anim30PlayerB4View2 < 2560;
            if (!rawValue2)
                return;
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8008C0B4) : "memory");
            goto select;
        case 118:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim30Player54View3 < 16;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim30PlayerCCView2;
            rawValue2 = Anim30Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim30PlayerD0View2;
            rawValue2 = Anim30Player90View2;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim30PlayerD4View2;
            rawValue2 = Anim30Player94View2;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8008C1A4) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim30PlayerACView2;
            nextSelector4 = 120;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x8008C1E0) : "memory");
            nextSelector4 = 117;
            goto select;
        private118:
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        finish118:
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8008C254) : "memory");
            goto preserveAge;
        case 119:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2;
            rawValue3 = 2;
            if (rawValue2)
                goto other119;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8008C2C8) : "memory");
                nextSelector4 = 131;
                goto effect119;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto effect119;
            rawValue2 = Anim30PlayerACView2;
            if (rawValue2)
                goto distance119;
            nextSelector4 = 120;
            goto effect119;
        distance119:
            rawValue2 = Anim30PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto effect119;
            nextSelector4 = 117;
        effect119:
            Anim30Call4BEF8View3(nextSelector4);
            {
                register int (*spawn2)(int, int, void*, int) __asm__("$2") =
                    Anim30DataSpawnParticleView1;
                if (spawn2)
                    spawn2(8, 33, 0, 2);
            }
            rawValue2 = (int)Anim30Data6C654View1;
            product5 = 0;
            nextSelector4 = Anim30Field((void*)rawValue2, unsigned char*, 0x12);
            Anim30CallPlaySoundView1((unsigned char)nextSelector4, product5, 0);
            rawValue2 = Anim30Player58View1 < 24;
            if (rawValue2)
                return;
            rawValue2 = 120;
            Anim30Data6E530View1 = rawValue2;
            rawValue2 = 15;
            Anim30Data6E52CView1 = rawValue2;
            return;
        other119:
            rawValue2 = 2;
            rawValue3 = Anim30Player50View1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                return;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            if (!rawValue2)
                return;
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 130;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8008C3D4) : "memory");
            goto select;
        case 120:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30PlayerB8View2 < 4;
            nextSelector4 = 119;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input120;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input120:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8008C484) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim30Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Data6E53CView3 & 32;
            nextSelector4 = 115;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8008C4F4) : "memory");
            goto select;
        case 121:
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto done121;
        done121:
            rawValue2 = Anim30Player280View1;
            if (rawValue2 < 0) {
                nextSelector4 = 128;
                goto select;
            }
            rawValue2 = Anim30PlayerB8View2;
            nextSelector4 = 115;
            if (!rawValue2)
                goto select;
            nextSelector4 = 119;
            goto select;
        case 122:
            rawValue2 = Anim30Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne122;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground122;
        airborne122:
            __asm__ volatile("" ::"i"(0x8008C5B4) : "memory");
            nextSelector4 = 119;
            goto select;
        ground122:
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 123;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8008C5F0) : "memory");
            goto select;
        case 123:
            rawValue2 = Anim30Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne123;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground123;
        airborne123:
            __asm__ volatile("" ::"i"(0x8008C644) : "memory");
            nextSelector4 = 119;
            goto select;
        ground123:
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 124;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8008C664) : "memory");
            goto select;
        case 124:
            rawValue2 = Anim30Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne124;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground124;
        airborne124:
            __asm__ volatile("" ::"i"(0x8008C6B8) : "memory");
            nextSelector4 = 119;
            goto select;
        ground124:
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8008C6F4) : "memory");
            goto select;
        case 126:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne126;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground126;
        airborne126:
            __asm__ volatile("" ::"i"(0x8008C750) : "memory");
            nextSelector4 = 119;
            goto select;
        ground126:
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input126;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input126:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim30Data6E044View2;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim30Data6E044View2;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim30PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerACView2;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8008C854) : "memory");
            goto select;
        case 128:
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto helper128;
        call498C0:
        helper128:
            Anim30Call498C0View1((void*)nextSelector4);
            return;
        case 129:
            rawValue2 = Anim30Data6E53CView3 & 64;
            if (rawValue2) {
                rawValue2 = 1;
                Anim30Player1B6View2 = rawValue2;
            }
            nextSelector4 = (int)&Anim30Player280View1;
            rawValue2 = *(int*)nextSelector4;
            if (rawValue2 < 0) {
                rawValue2 = 36863;
                rawValue3 = Anim30Player144View1;
                rawValue2 = rawValue2 < rawValue3;
                if (!rawValue2)
                    return;
                rawValue2 = -1;
                Anim30Player28CView1 = rawValue2;
                goto helper128;
            }
            rawValue3 = Anim30Player54View3;
            rawValue2 = rawValue3 < 61;
            if (!rawValue2) {
                rawValue2 = -1;
                *(int*)nextSelector4 = rawValue2;
                return;
            }
            rawValue2 = rawValue3 < 16;
            if (rawValue2)
                return;
            rawValue2 = Anim30Player1B6View2;
            if (!rawValue2)
                return;
            product5 = Anim30Player28CView1;
            nextSelector4 = 118;
            if (product5 < 0)
                goto select;
            nextSelector4 = Anim30Player290View1;
            rawValue2 = Anim30Call3BF6CView1(nextSelector4, product5);
            if (rawValue2) {
                nextSelector4 = Anim30Player28CView1;
                Anim30Call3BE70View1(nextSelector4);
            }
            rawValue2 = -1;
            Anim30Player28CView1 = rawValue2;
            nextSelector4 = 118;
            goto select;
        case 130:
            rawValue2 = Anim30Data7431CView1(1);
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim30Player250View1;
            rawValue2 = Anim30Player48View2;
            rawValue3 = Anim30Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                goto other130;
            rawValue2 = Anim30Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                goto other130;
            }
            goto completed130;
        completed130:
            rawValue2 = Anim30PlayerB8View2;
            if (rawValue2)
                goto preserveAge;
            rawValue2 = Anim30Data6E535View2;
            if (rawValue2)
                goto latch130;
            rawValue2 = Anim30PlayerB4View2 < 2560;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x8008CA20) : "memory");
            nextSelector4 = 117;
            goto select;
        latch130:
            __asm__ volatile("" ::"i"(0x8008CA28) : "memory");
            nextSelector4 = 115;
            goto select;
        preserveAge:
            savedWord16 = Anim30Player54View3;
            Anim30Call4BEF8View3(119);
            Anim30Player54View3 = savedWord16;
            return;
        other130:
            nextSelector4 = (int)&Anim30Player50View1;
            rawValue3 = *(int*)nextSelector4;
            rawValue2 = 2;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2;
            if (rawValue2)
                return;
            rawValue2 = 1;
            *(int*)nextSelector4 = rawValue2;
            goto select116;
        case 131:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne131;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground131;
        airborne131:
            __asm__ volatile("" ::"i"(0x8008CAD8) : "memory");
            nextSelector4 = 119;
            goto select;
        ground131:
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload131;
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload131:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim30Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input131:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 4;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim30Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerB0View3;
            if (!rawValue2)
                goto latch131;
            rawValue2 = 40;
            rawValue3 = Anim30Data6E044View2;
            if (rawValue3 != rawValue2)
                goto select;
        latch131:
            __asm__ volatile("" ::"i"(0x8008CBB4) : "memory");
            nextSelector4 = 115;
            goto select;
        case 132:
            rawValue2 = (int)Anim30Player250View1;
            callback3 = Anim30Data7431CView1;
            record16 = Anim30Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim30PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne132;
            rawValue2 = Anim30PlayerE4View2 < 23;
            if (rawValue2)
                goto ground132;
        airborne132:
            __asm__ volatile("" ::"i"(0x8008CC10) : "memory");
            nextSelector4 = 119;
            goto select;
        ground132:
            rawValue2 = Anim30Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim30Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload132;
            rawValue2 = Anim30Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload132:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim30Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim30Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input132:
            rawValue2 = Anim30Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 4;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 8;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 131;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim30Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim30PlayerB0View3;
            if (!rawValue2)
                goto latch132;
            rawValue2 = 40;
            rawValue3 = Anim30Data6E044View2;
            if (rawValue3 != rawValue2)
                goto select;
        latch132:
            __asm__ volatile("" ::"i"(0x8008CCEC) : "memory");
            nextSelector4 = 115;
            goto select;
        default:
            return;
    }
select116:
    nextSelector4 = 116;
select:
    Anim30Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim30Field
