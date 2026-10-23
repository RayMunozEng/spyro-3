#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800922B0.
 * Assembly SHA256 df0737cb19d0babb72a6569cb4ba82eac2e56cd52f9dd13db95402d082914ad9.
 * AI-generated; not human reviewed. All1643 original instructions,
 * 78 selectors bias20 and 0 owned padding words are required.
 * Original frame0xE0; every concrete field width and producer is retained.
 * Fifteen mapped groups reuse verified Bentley36 and common11/43/23/14.
 * Original scratch10..C4,savedS0..S4,slotS2,combinedS3 and all fields remain.
 * Original87 uses S1 mode/S2 vector/S0 frame with separate short product lives.
 * Original40/41 retain their separate callbacks,delay-slot stores and158
 * counter increments,sharing only the original final94/158 store80093C34.
 * Every pointer,shift,branch,callback and original selector is required.
 * Repeated identical declarations are removed; distinct typed aliases stay
 * distinct. Initialized empty constraints and original address metadata emit
 * zero CPU instructions; frozen C tools emit words. Units/fixed point,helper
 * contracts and caller rate remain unresolved; cadence is per invocation.
 * Falsification: every native/linked instruction,actual internal/conditional
 * target,selector/data and full EXE/every-overlay retail hashes. Binary identity
 * does not establish synchronized runtime or system completeness. */
#define Physics24Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Physics24UpdatePlayerGroundInputTargetsView1() __asm__("func_80040D10");
unsigned char Physics24ApproachPlayerTargetHeadingView1() __asm__("func_80041580");
unsigned char Physics24BlendPlayerHeadingFromInputVectorView1() __asm__("func_800416F4");
unsigned char Physics24ApproachPlayerTargetSpeedView1() __asm__("func_800417FC");
unsigned char Physics24BuildPlayerResponseVectorView1() __asm__("func_80041B64");
int Physics24InterpolateSineView1() __asm__("func_8004E9E4");
int Physics24InterpolateCosineView1() __asm__("func_8004EA2C");
int Physics24MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics24ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics24ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics24AddVectorView1() __asm__("func_8004F194");
unsigned char Physics24SubtractVectorView1() __asm__("func_8004F1C8");
extern void* Physics24Data6C570View1 __asm__("D_8006C570");
extern int Physics24Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics24Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics24Player0View1 __asm__("D_80070328");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics24UpdatePlayerGroundInputTargetsView2() __asm__("func_80040D10");
int Physics24ApproachPlayerTargetHeadingView2() __asm__("func_80041580");
int Physics24BlendPlayerHeadingFromInputVectorView2() __asm__("func_800416F4");
int Physics24ApproachPlayerTargetSpeedView2() __asm__("func_800417FC");
int Physics24BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Physics24BuildPlayerResponseVectorView2() __asm__("func_80041B64");
int Physics24InterpolateSineView2() __asm__("func_8004E9E4");
int Physics24InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics24MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics24ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics24ClearVectorView2() __asm__("func_8004F168");
int Physics24CopyVectorView1() __asm__("func_8004F178");
int Physics24AddVectorView2() __asm__("func_8004F194");
int Physics24SubtractVectorView2() __asm__("func_8004F1C8");
extern int Physics24Data6E044View2 __asm__("D_8006E044");
extern int Physics24Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics24Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics24PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics24Player94View1 __asm__("D_80070328+0x94");
extern int Physics24PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics24Player80View1 __asm__("D_80070328+0x80");
extern int Physics24PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics24Player64View1 __asm__("D_80070328+0x64");
extern int Physics24Player84View1 __asm__("D_80070328+0x84");
extern int Physics24Player144View1 __asm__("D_80070328+0x144");
extern int Physics24Player60View1 __asm__("D_80070328+0x60");
extern int Physics24PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics24Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics24Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics24PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics24PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics24Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics24Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics24Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics24Player101View1 __asm__("D_80070328+0x101");
extern int Physics24PlayerA4View1 __asm__("D_80070328+0xA4");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
int Physics24UpdatePlayerGroundInputTargetsView3() __asm__("func_80040D10");
int Physics24UpdateSmoothedInputPairView1() __asm__("func_800410F8");
int Physics24ApproachPlayerTargetHeadingView3() __asm__("func_80041580");
int Physics24ApproachPlayerTargetSpeedView3() __asm__("func_800417FC");
int Physics24BuildPlayerMovementVectorView2() __asm__("func_80041848");
int Physics24BuildPlayerResponseVectorView3() __asm__("func_80041B64");
int Physics24InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics24TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics24ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics24ClearVectorView3() __asm__("func_8004F168");
int Physics24CopyVectorView2() __asm__("func_8004F178");
int Physics24AddVectorView3() __asm__("func_8004F194");
int Physics24CallRandView1() __asm__("rand");
extern int* Physics24Data6C570View2 __asm__("D_8006C570");
extern int Physics24Data6C640View1 __asm__("D_8006C640");
extern int Physics24Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics24Player0View3 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics24Player158View1 __asm__("D_80070328+0x158");
extern int Physics24Player20CView2 __asm__("D_80070328+0x20C");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics24Player8CView1 __asm__("D_80070328+0x8C");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern void* Physics24Player250View1 __asm__("D_80070328+0x250");
extern int Physics24Player88View1 __asm__("D_80070328+0x88");
extern int Physics24PlayerE8View1 __asm__("D_80070328+0xE8");
extern void* (*Physics14_SpawnParticle)() __asm__("SpawnParticle");
void func_level_24_800922B0(int slotIndex) {
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
            spB8, spBC, spC0, spC4;
    } originalFrame;
    register void* globalVector80 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    register int workWord3 __asm__("$3");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
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
    globalPointer = &Physics24Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics24Data6C570View1 = (void*)workWord2;
    workWord2 = Physics24Field(&Physics24Player0View1, int*, 0x54);
    stateWord3 = Physics24Field(&Physics24Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        default:
            return;
        case 20:
            globalVector80 = &Physics24Player0View1 + 0x80;
            Physics24ClearVectorView1(globalVector80);
            Physics24ClearVectorView1(globalVector80 + 0xC);
            if (Physics24Data6E044View1 != 7) {
                Physics24UpdatePlayerGroundInputTargetsView1(0x1200);
                Physics24BlendPlayerHeadingFromInputVectorView1();
                Physics24ApproachPlayerTargetHeadingView1(0x5A, 0x10);
                return;
            }
            return;
        case 29:
            Physics24ClearVectorView2(&originalFrame.sp10);
            call4 = &originalFrame.sp10;
            call5 = call4;
            MATCHING_KEEP2(call4, call5);
            globalVector80 = &Physics24Player0View2 + 0x8C;
            Physics24SubtractVectorView2(call4, call5, globalVector80);
            if (Physics24PlayerB8View1) {
                originalFrame.sp18 = 0;
                call5 = (void*)Physics24MeasureVectorLengthView2(&originalFrame.sp10, 0);
                workWord2 = (int)call5 < 65;
                if (!workWord2)
                    Physics24ScaleVectorRatioQ15View2(&originalFrame.sp10, call5, 64);
                originalFrame.sp18 = -192;
                call4 = globalVector80 - 12;
                call5 = globalVector80;
                call6 = &originalFrame.sp10;
                goto vector29;
            }
            call5 = (void*)Physics24MeasureVectorLengthView2(&originalFrame.sp10, 1);
            workWord2 = (int)call5 < 257;
            if (!workWord2)
                Physics24ScaleVectorRatioQ15View2(&originalFrame.sp10, call5, 256);
            Physics24AddVectorView2(globalVector80, globalVector80, &originalFrame.sp10);
            call4 = globalVector80 - 12;
            call5 = globalVector80;
            call6 = call5 + 0x5C;
            goto vector29;
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics24Player20CView2;
            MATCHING_KEEP(call5);
            workWord2 = Physics24Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp20;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics24UpdateSmoothedInputPairView1(call4, call5, 0);
            workWord3 = Physics24Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics24Player60View1;
                numeric4 = Physics24Player144View1;
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
                Physics24Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.sp24 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics24Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.sp20 * 0x14) >> 7;
            Physics24Field(&Physics24Player0View3, int*, 0x64) =
                (int)((Physics24Field(&Physics24Player0View3, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics24Field(&Physics24Player0View3, int*, 0x60) +
                               ((int)(originalFrame.sp24 * -0xF) >> 7)) &
                              0xFFF;
            Physics24Field(&Physics24Player0View3, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics24Field(&Physics24Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x60) < -0x320) {
                Physics24Field(&Physics24Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x60) >= 0x321) {
                Physics24Field(&Physics24Player0View3, int*, 0x60) = 0x320;
            }
            if ((*Physics24Data6C570View2 & 0x40) ||
                (Physics24Field(&Physics24Player0View3, int*, 0x4C) == 1)) {
                Physics24Field(&Physics24Player0View3, int*, 0xAC) = 0xE00;
            } else {
                Physics24Field(&Physics24Player0View3, int*, 0xAC) = 0;
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x4C) == 2) {
                Physics24ApproachPlayerTargetSpeedView3(0xC0, 0xC0);
                if (Physics24Field(&Physics24Player0View3, int*, 0xB0) < 0xE01) {
                    Physics24Field(&Physics24Player0View3, int*, 0x4C) = 0;
                }
            } else {
                Physics24ApproachPlayerTargetSpeedView3(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics24Player0View3 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics24InterpolateCosineView3(
                                                Physics24Field(&Physics24Player0View3, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics24Field(&Physics24Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics24Field(&Physics24Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics24Field(&Physics24Player0View3, int*, 0x14C) + raw21_temp_a0_5;
            Physics24Field(&Physics24Player0View3, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics24Field(&Physics24Player0View3, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics24Field(&Physics24Player0View3, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics24Field(&Physics24Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x5C) < -0x300) {
                Physics24Field(&Physics24Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x5C) >= 0x301) {
                Physics24Field(&Physics24Player0View3, int*, 0x5C) = 0x300;
            }
            Physics24BuildPlayerMovementVectorView2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics24CopyVectorView2(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics24CallRandView1() & 31;
            if (workWord2)
                goto counter40;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto counter40;
            call5 = (void*)44;
            call6 = &originalFrame.sp28;
            particleArg7 = 0;
            __asm__("" : "=r"(particleArg7) : "0"(particleArg7), "r"(call5), "r"(call6));
            workWord2 = 544;
            originalFrame.sp28 = workWord2;
            workWord2 = 64;
            originalFrame.sp2C = 0;
            originalFrame.sp30 = workWord2;
            particleCall3(call4, call5, call6, particleArg7);
            goto counter40;
        counter40:
            globalPointer = &Physics24Player158View1;
            workWord2 = Physics24Field(globalPointer, int*, 0);
            __asm__("" : "=r"(workWord2) : "0"(workWord2), "i"(0x80092730));
            workWord2++;
            goto store95;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics24Player0View3 + 0x20C;
            if (!(Physics24Field(&Physics24Player0View3, int*, 0x20C) & 0x40)) {
                if (Physics24Data6E044View3 != 7) {
                    Physics24UpdateSmoothedInputPairView1(&originalFrame.sp28,
                                                          raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.sp28;
                    numeric4 = originalFrame.sp2C;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics24Player64View1;
                    workWord2 = Physics24Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics24Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics24Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics24Player60View1 = workWord2;
                    }
                    if (Physics24Field(&Physics24Player0View3, int*, 0x60) < -0x320) {
                        Physics24Field(&Physics24Player0View3, int*, 0x60) = -0x320;
                    }
                    if (Physics24Field(&Physics24Player0View3, int*, 0x60) >= 0x321) {
                        Physics24Field(&Physics24Player0View3, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics24InterpolateCosineView3(Physics24Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics24Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics24Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics24Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics24Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics24Player5CView1 = workWord2;
                    }
                    if (Physics24Field(&Physics24Player0View3, int*, 0x5C) < -0x300) {
                        Physics24Field(&Physics24Player0View3, int*, 0x5C) = -0x300;
                    }
                    if (Physics24Field(&Physics24Player0View3, int*, 0x5C) >= 0x301) {
                        Physics24Field(&Physics24Player0View3, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics24Player0View3 + 0x80;
                Physics24ClearVectorView3(raw21_temp_s0_9);
                Physics24ClearVectorView3(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics24CallRandView1() & 31;
                if (workWord2)
                    goto block_130;
                MATCHING_KEEP(workWord2);
                particleCall3 = Physics21_SpawnParticle;
                call4 = (void*)1;
                if (!particleCall3)
                    goto block_130;
                call5 = (void*)44;
                call6 = &originalFrame.sp38;
                particleArg7 = 0;
                __asm__("" : "=r"(particleArg7) : "0"(particleArg7), "r"(call5), "r"(call6));
                workWord2 = 544;
                originalFrame.sp38 = workWord2;
                workWord2 = 64;
                originalFrame.sp3C = 0;
                originalFrame.sp40 = workWord2;
            block_129:
                particleCall3(call4, call5, call6, particleArg7);
            block_130:
                globalPointer = &Physics24Player158View1;
                workWord2 = Physics24Field(globalPointer, int*, 0);
                __asm__("" : "=r"(workWord2) : "0"(workWord2), "i"(0x80092944));
                workWord2++;
                goto store95;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics24Player20CView2;
            MATCHING_KEEP(call5);
            workWord2 = Physics24Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp38;
            if (!workWord2)
                goto run42;
        block_132:
            Physics24PlayerACView1 = 0;
            Physics24PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics24UpdateSmoothedInputPairView1(call4, call5, 0);
            workWord3 = Physics24Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics24Player60View1;
                numeric5 = Physics24Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.sp3C = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.sp3C = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.sp3C;
                workWord3 = numeric5 + 1;
                Physics24Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.sp3C = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics24Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics24Player0View3 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.sp38 * 0x14) >> 7;
            Physics24Field(&Physics24Player0View3, int*, 0x64) =
                (int)((Physics24Field(&Physics24Player0View3, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics24Field(&Physics24Player0View3, int*, 0x60) +
                                ((int)(originalFrame.sp3C * -0xF) >> 7)) &
                               0xFFF;
            Physics24Field(&Physics24Player0View3, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics24Field(&Physics24Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x60) < -0x320) {
                Physics24Field(&Physics24Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x60) >= 0x321) {
                Physics24Field(&Physics24Player0View3, int*, 0x60) = 0x320;
            }
            Physics24Field(&Physics24Player0View3, int*, 0xAC) = 0x1C00;
            Physics24ApproachPlayerTargetSpeedView3(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics24InterpolateCosineView3(
                                                 Physics24Field(&Physics24Player0View3, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics24Field(&Physics24Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics24Field(&Physics24Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics24Field(&Physics24Player0View3, int*, 0x14C) + raw21_temp_a0_6;
            Physics24Field(&Physics24Player0View3, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics24Field(&Physics24Player0View3, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics24Field(&Physics24Player0View3, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics24Field(&Physics24Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x5C) < -0x300) {
                Physics24Field(&Physics24Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x5C) >= 0x301) {
                Physics24Field(&Physics24Player0View3, int*, 0x5C) = 0x300;
            }
            Physics24BuildPlayerMovementVectorView2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics24CopyVectorView2(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics24Field(&Physics24Player0View3, int*, 0xB4) >= 0x7D1)) {
                originalFrame.sp48 = -0x190;
                originalFrame.sp4C = 0x40 - (Physics24CallRandView1() & 0x7F);
                originalFrame.sp50 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp48, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics24Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics24Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            Physics24ClearVectorView3(globalField4CPointer + 52);
            Physics24ClearVectorView3(globalField4CPointer + 64);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics24Data6E044View3;
            if (workWord3 == workWord2) {
                Physics24Field(&Physics24Player0View3, int*, 0xB0) = 0;
            } else {
                Physics24UpdatePlayerGroundInputTargetsView3(0x980);
                raw21_var_v0_2 = Physics24ApproachPlayerTargetHeadingView3(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics24Field(&Physics24Player0View3, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics24Field(&Physics24Player0View3, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics24ApproachPlayerTargetSpeedView3(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics24Player0View3 + 0xB0;
            if (Physics24Field(&Physics24Player0View3, int*, 0xB0) != 0) {
                Physics24BuildPlayerMovementVectorView2();
                Physics24BuildPlayerResponseVectorView3();
                Physics24Field(&Physics24Player0View3, int*, 0x94) = 0;
            } else {
                Physics24ClearVectorView3(raw21_temp_s0_11 - 0x30);
                Physics24ClearVectorView3(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics24Player0View3 + 0x28;
                if (Physics24Field(&Physics24Player0View3, int*, 0x28) < 0) {
                    if ((Physics24Field(&Physics24Player0View3, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics24Data6C640View1 & 1)) {
                        Physics24CopyVectorView2(&originalFrame.sp48, raw21_temp_s4 - 0x28);
                        originalFrame.sp5C = 0x40;
                        originalFrame.sp60 = 0;
                        originalFrame.sp58 =
                            (int)Physics24Field(&Physics24Player0View3, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp5C = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics24TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp58,
                                                             &originalFrame.sp68);
                        Physics24AddVectorView3(&originalFrame.sp48, &originalFrame.sp48,
                                                &originalFrame.sp68);
                        originalFrame.sp58 = 0;
                        originalFrame.sp50 = -Physics24Field(&Physics24Player0View3, int*, 0x28);
                        Physics24TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp58,
                                                             &originalFrame.sp58);
                        Physics24ShiftVectorRightTowardZeroView1(&originalFrame.sp58, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp48, &originalFrame.sp58);
                        if (!(Physics24CallRandView1() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp48, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics24Player0View3 + 0xB0;
                        if ((Physics24Field(&Physics24Player0View3, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics24Data6C640View1 & 7) &&
                            !(Physics24CallRandView1() & 3)) {
                            originalFrame.sp78 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp7C = 0;
                            originalFrame.sp80 = 0;
                            Physics24TransformVectorByBasisView1(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp78, &originalFrame.sp78);
                            Physics24AddVectorView3(&originalFrame.sp78, &originalFrame.sp78,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp80 =
                                -Physics24Field(&Physics24Player0View3, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp78, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics24Field(&Physics24Player0View3, int*, 0x144) -
                ((int)((Physics24Field(&Physics24Player0View3, int*, 0x148) * 2) +
                       (Physics24Field(&Physics24Player0View3, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics24Field(&Physics24Player0View3, int*, 0x148) + raw21_temp_a1_4;
            Physics24Field(&Physics24Player0View3, int*, 0x144) = raw21_temp_a1_4;
            Physics24Field(&Physics24Player0View3, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics24Field(&Physics24Player0View3, int*, 0x148) = 0x5900;
            }
            if (Physics24Field(&Physics24Player0View3, int*, 0x148) < -0x5900) {
                Physics24Field(&Physics24Player0View3, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 57:
            if ((workWord2 = combinedIndex < 9) == 0) {
                Physics24Field(&Physics24Player0View3, int*, 0x80) =
                    (int)(Physics24Field(&Physics24Player0View3, int*, 0x8C) * 0xF8);
                Physics24Field(&Physics24Player0View3, int*, 0x84) =
                    (int)(Physics24Field(&Physics24Player0View3, int*, 0x90) * 0xF8);
                Physics24Field(&Physics24Player0View3, int*, 0x88) =
                    (int)(Physics24Field(&Physics24Player0View3, int*, 0x94) * 0xF8);
                Physics24ShiftVectorRightTowardZeroView1(&Physics24Player0View3 + 0x80, 8);
            }
        block_188:
            call4 = &Physics24Player0View3 + 0x8C;
            call5 = call4 - 12;
            Physics24CopyVectorView2(call4, call5);
            return;
        case 85:
        case 91:
            globalVector80 = &Physics24Player0View2 + 0x80;
            Physics24ClearVectorView2(globalVector80);
            Physics24ClearVectorView2(globalVector80 + 12);
            if (Physics24Data6E044View2 != 7) {
                Physics24UpdatePlayerGroundInputTargetsView2(3840);
                Physics24BlendPlayerHeadingFromInputVectorView2();
                Physics24ApproachPlayerTargetHeadingView2(90, 16);
            }
            workWord2 = Physics24Player1BAView1;
            if (!workWord2)
                goto byteOne65;
            workWord2 = Physics24Data6E538View1 & 16;
            if (workWord2)
                return;
            workWord2 = 1;
            Physics24Player1BAView1 = 0;
            Physics24Player1B9View1 = workWord2;
            return;
        byteOne65:
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics24Player1B9View1 = workWord2;
            return;
        case 86:
        case 92:
            workWord3 = Physics24Data6E044View2;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics24UpdatePlayerGroundInputTargetsView2(3840);
            globalVector80 = &Physics24Data6E538View1;
            workWord2 = Physics24Field(globalVector80, int*, 0) & 12;
            if (workWord2)
                Physics24PlayerACView1 = 0;
            workWord2 = Physics24BlendPlayerHeadingFromInputVectorView2();
            call4 = (void*)90;
            call5 = (void*)16;
            MATCHING_KEEP2(call4, call5);
            globalFieldA4Pointer = (void*)workWord2;
            workWord2 = Physics24ApproachPlayerTargetHeadingView2(call4, call5);
            workWord3 = Physics24PlayerA8View1;
            if (workWord3 < 0)
                workWord3 = -workWord3;
            workWord3 = workWord3 < 8;
            __asm__("" : "=r"(workWord3) : "0"(workWord3), "r"(workWord2));
            call5 = (void*)workWord2;
            if (!workWord3)
                goto reset101;
            workWord2 = Physics24Field(globalVector80, int*, 0) & 12;
            if (!workWord2)
                goto reset101;
            workWord2 = Physics24Player144View1;
            workWord2++;
            Physics24Player144View1 = workWord2;
            goto saved101;
        reset101:
            Physics24Player144View1 = 0;
        saved101:
            call4 = &Physics24PlayerACView1;
            globalVector80 = (void*)Physics24Field(call4, int*, 0);
            if (globalFieldA4Pointer)
                goto collision101;
            workWord2 = (int)call5;
            if ((int)call5 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass101;
        collision101:
            workWord2 = Physics24Player20CView1 & 64;
            if (workWord2)
                Physics24Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics24PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics24Field(call4, int*, 0) = workWord3;
            }
        pass101:
            Physics24ApproachPlayerTargetSpeedView2(256, 384);
            workWord2 = Physics24Player101View1;
            call4 = &Physics24PlayerACView1;
            Physics24Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics24ClearVectorView2(call4 - 32);
                goto fields101;
            }
            Physics24BuildPlayerMovementVectorView1(call4);
            Physics24BuildPlayerResponseVectorView2();
        fields101:
            call6 = &Physics24PlayerFCView1;
            MATCHING_KEEP(call6);
            workWord2 = Physics24Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar95;
            workWord2 = Physics24PlayerB8View1;
            if (!workWord2)
                goto vector95;
            __asm__ volatile("" ::"i"(0x80093234) : "memory");
            goto scalar95;
        case 87: {
            int product87_0, product87_1;
            register void* modePointer17 __asm__("$17");
            register void* vectorPointer18 __asm__("$18");
            register void* framePointer16 __asm__("$16");
            modePointer17 = &Physics24Player4CView1;
            workWord3 = Physics24Field(modePointer17, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto ground87;
            Physics24UpdatePlayerGroundInputTargetsView2(3200);
            Physics24ApproachPlayerTargetHeadingView2(40, 8);
            Physics24ApproachPlayerTargetSpeedView2(256, 384);
            vectorPointer18 = modePointer17 + 64;
            workWord2 = Physics24InterpolateCosineView2(Physics24PlayerA4View1);
            workWord3 = Physics24PlayerB0View1;
            product87_0 = workWord3 * workWord2;
            call4 = (void*)Physics24PlayerA4View1;
            workWord2 = product87_0 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp68 = workWord2;
            workWord2 = Physics24InterpolateSineView2(call4);
            workWord3 = Physics24PlayerB0View1;
            product87_1 = workWord3 * workWord2;
            framePointer16 = &originalFrame.sp68;
            call4 = framePointer16;
            call5 = call4;
            call6 = vectorPointer18;
            workWord2 = product87_1 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp6C = workWord2;
            Physics24SubtractVectorView2(call4, call5, call6);
            originalFrame.sp70 = 0;
            temp_v0_4 = Physics24MeasureVectorLengthView2(framePointer16, 0);
            MATCHING_KEEP(modePointer17);
            var_a0_3 = modePointer17 + 52;
            if (temp_v0_4 >= 641) {
                Physics24ScaleVectorRatioQ15View2(framePointer16, temp_v0_4, 640);
                MATCHING_KEEP(modePointer17);
                var_a0_3 = modePointer17 + 52;
            }
            Physics24AddVectorView2(var_a0_3, vectorPointer18, framePointer16);
            Physics24BuildPlayerResponseVectorView2();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract87;
            workWord2 = Physics24Field(modePointer17, int*, 0);
            if (workWord2)
                goto subtract87;
            workWord2 = (int)Physics24Data6C570View1;
            workWord2 = Physics24Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_93;
            workWord2 = Physics24Player144View1;
            if (workWord2)
                goto add23_93;
        subtract87:
            globalPointer = &Physics24Player94View1;
            workWord2 = Physics24Field(globalPointer, int*, 0);
            __asm__("" : "=r"(workWord2) : "0"(workWord2), "i"(0x80093378));
            workWord2 -= 192;
            goto store95;
        ground87:
            workWord3 = Physics24Data6E044View2;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics24UpdatePlayerGroundInputTargetsView2(3840);
            globalVector80 = &Physics24Data6E538View1;
            workWord2 = Physics24Field(globalVector80, int*, 0) & 12;
            if (workWord2)
                Physics24PlayerACView1 = 0;
            workWord2 = Physics24BlendPlayerHeadingFromInputVectorView2();
            call4 = (void*)90;
            call5 = (void*)16;
            MATCHING_KEEP2(call4, call5);
            globalFieldA4Pointer = (void*)workWord2;
            workWord2 = Physics24ApproachPlayerTargetHeadingView2(call4, call5);
            workWord3 = Physics24PlayerA8View1;
            if (workWord3 < 0)
                workWord3 = -workWord3;
            workWord3 = workWord3 < 8;
            __asm__("" : "=r"(workWord3) : "0"(workWord3), "r"(workWord2));
            call5 = (void*)workWord2;
            if (!workWord3)
                goto reset87;
            workWord2 = Physics24Field(globalVector80, int*, 0) & 12;
            if (!workWord2)
                goto reset87;
            workWord2 = Physics24Player144View1;
            workWord2++;
            Physics24Player144View1 = workWord2;
            goto saved87;
        reset87:
            Physics24Player144View1 = 0;
        saved87:
            call4 = &Physics24PlayerACView1;
            globalVector80 = (void*)Physics24Field(call4, int*, 0);
            if (globalFieldA4Pointer)
                goto collision87;
            workWord2 = (int)call5;
            if ((int)call5 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass87;
        collision87:
            workWord2 = Physics24Player20CView1 & 64;
            if (workWord2)
                Physics24Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics24PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics24Field(call4, int*, 0) = workWord3;
            }
        pass87:
            Physics24ApproachPlayerTargetSpeedView2(256, 384);
            workWord2 = Physics24Player101View1;
            call4 = &Physics24PlayerACView1;
            Physics24Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics24ClearVectorView2(call4 - 32);
                goto fields87;
            }
            Physics24BuildPlayerMovementVectorView1(call4);
            Physics24BuildPlayerResponseVectorView2();
        fields87:
            call6 = &Physics24PlayerFCView1;
            workWord2 = Physics24Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar95;
            workWord2 = Physics24PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto scalar95;
        commit87:
            call5 = call4;
            Physics24AddVectorView2(call4, call5, call6 - 20);
            return;
        }
        case 88:
            vectorAt40 = &originalFrame.sp88;
            Physics24ClearVectorView2(vectorAt40);
            call4 = vectorAt40;
            call5 = call4;
            Physics24SubtractVectorView2(call4, call5, &Physics24Player8CView1);
            workWord2 = Physics24PlayerB8View1;
            call4 = vectorAt40;
            if (!workWord2)
                goto detached121;
            originalFrame.sp90 = 0;
            workWord2 = Physics24MeasureVectorLengthView2(call4, 0);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 9;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)8;
            goto limit121;
        detached121:
            workWord2 = Physics24MeasureVectorLengthView2(call4, 1);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 65;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)64;
        limit121:
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(call4, call5, call6, "memory");
            Physics24ScaleVectorRatioQ15View2(call4, call5, call6);
        vectors121:
            globalVector80 = &Physics24Player80View1;
            call4 = globalVector80;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            MATCHING_KEEP(globalVector80);
            globalFieldA4Pointer = globalVector80 + 12;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(globalFieldA4Pointer, "memory");
            call5 = globalFieldA4Pointer;
            call6 = &originalFrame.sp88;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call5, call6, "memory");
            workWord2 = -192;
            originalFrame.sp90 = workWord2;
            MATCHING_BARRIER_VOLATILE("memory");
        vector29:
            __asm__ volatile("" ::"i"(0x800935C4) : "memory");
            Physics24AddVectorView2(call4, call5, call6);
            call4 = &Physics24Player8CView1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = &Physics24Player80View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            Physics24CopyVectorView1(call4, call5);
            workWord2 = Physics24Player94View1;
            workWord2 = workWord2 < -8960;
        clamp19:
        clamp119:
            if (workWord2) {
                workWord2 = -8960;
                Physics24Player94View1 = workWord2;
            }
            return;
        case 89: {
            int product89_0, product89_1, product89_2, product89_3;
            register int numeric4 __asm__("$4");
            workWord3 = Physics24Player4CView1;
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto free89;
            workWord2 = (int)Physics24Player250View1;
            workWord2 = Physics24Field((void*)workWord2, int*, 0);
            numeric4 = Physics24Field((void*)workWord2, int*, 80);
            workWord2 = Physics24Player64View1;
            workWord3 = numeric4 - 512;
            workWord2 -= workWord3;
            workWord3 = workWord2 & 4095;
            workWord2 = workWord3 < 1024;
            if (workWord2) {
                workWord3 = numeric4;
                goto snapped89;
            }
            workWord2 = workWord3 < 2048;
            if (workWord2) {
                workWord3 = numeric4 + 1024;
                goto snapped89;
            }
            workWord2 = workWord3 < 3072;
            workWord3 = numeric4 + 2048;
            if (!workWord2)
                workWord3 = numeric4 + 3072;
        snapped89:
            workWord2 = 1600;
            Physics24PlayerA4View1 = workWord3;
            Physics24PlayerACView1 = workWord2;
            call4 = (void*)22;
            goto speed89;
        free89:
            Physics24UpdatePlayerGroundInputTargetsView2(1600);
            call4 = (void*)22;
        speed89:
            Physics24ApproachPlayerTargetHeadingView2(call4, 4);
            Physics24ApproachPlayerTargetSpeedView2(256, 384);
            globalFieldA4Pointer = &Physics24Player4CView1;
            MATCHING_KEEP(globalFieldA4Pointer);
            workWord3 = Physics24Field(globalFieldA4Pointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto air89;
            workWord2 = Physics24InterpolateCosineView2(Physics24PlayerA4View1);
            workWord3 = Physics24PlayerB0View1;
            product89_0 = workWord3 * workWord2;
            call4 = (void*)Physics24PlayerA4View1;
            workWord2 = product89_0 >> 12;
            MATCHING_KEEP(workWord2);
            Physics24Field(globalFieldA4Pointer, int*, 52) = workWord2;
            workWord2 = Physics24InterpolateSineView2(call4);
            workWord3 = Physics24PlayerB0View1;
            product89_1 = workWord3 * workWord2;
            call4 = globalFieldA4Pointer + 64;
            workWord2 = Physics24Player94View1;
            Physics24Player88View1 = workWord2;
            workWord2 = product89_1 >> 12;
            Physics24Player84View1 = workWord2;
            Physics24CopyVectorView1(call4, globalFieldA4Pointer + 52);
            goto subtract89;
        air89:
            globalVector8C = globalFieldA4Pointer + 64;
            workWord2 = Physics24InterpolateCosineView2(Physics24PlayerA4View1);
            workWord3 = Physics24PlayerB0View1;
            product89_2 = workWord3 * workWord2;
            call4 = (void*)Physics24PlayerA4View1;
            workWord2 = product89_2 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp98 = workWord2;
            workWord2 = Physics24InterpolateSineView2(call4);
            workWord3 = Physics24PlayerB0View1;
            product89_3 = workWord3 * workWord2;
            globalVector80 = &originalFrame.sp98;
            call4 = globalVector80;
            call5 = globalVector80;
            call6 = globalVector8C;
            MATCHING_KEEP3(call4, call5, call6);
            workWord2 = product89_3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp9C = workWord2;
            Physics24SubtractVectorView2(call4, call5, call6);
            originalFrame.spA0 = 0;
            temp_v0_4 = Physics24MeasureVectorLengthView2(globalVector80, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 52;
            if (temp_v0_4 >= 321) {
                Physics24ScaleVectorRatioQ15View2(globalVector80, temp_v0_4, 320);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 52;
            }
            Physics24AddVectorView2(var_a0_3, globalVector8C, globalVector80);
            Physics24BuildPlayerResponseVectorView2();
        subtract89:
            globalPointer = &Physics24Player94View1;
            workWord2 = Physics24Field(globalPointer, int*, 0);
            workWord2 -= 192;
            Physics24Field(globalPointer, int*, 0) = workWord2;
            goto clamp95;
        }
        case 93:
        case 94: {
            int product93_0, product93_1;
            Physics24UpdatePlayerGroundInputTargetsView1(0xC80);
            Physics24ApproachPlayerTargetHeadingView1(0x28, 8);
            Physics24ApproachPlayerTargetSpeedView1(256, 384);
            globalFieldA4Pointer = &Physics24Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics24InterpolateCosineView1(Physics24Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics24Field(&Physics24Player0View1, int*, 0xB0);
            product93_0 = workWord3 * workWord2;
            call4 = (void*)Physics24Field(globalFieldA4Pointer, int*, 0);
            workWord2 = product93_0 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spA8 = workWord2;
            workWord2 = Physics24InterpolateSineView1(call4);
            workWord3 = Physics24Field(&Physics24Player0View1, int*, 0xB0);
            product93_1 = workWord3 * workWord2;
            workWord2 = product93_1 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spAC = workWord2;
            Physics24SubtractVectorView1(&originalFrame.spA8, &originalFrame.spA8, globalVector8C);
            originalFrame.spB0 = 0;
            temp_v0_4 = Physics24MeasureVectorLengthView1(&originalFrame.spA8, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics24ScaleVectorRatioQ15View1(&originalFrame.spA8, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics24AddVectorView1(var_a0_3, globalVector8C, &originalFrame.spA8);
            Physics24BuildPlayerResponseVectorView1();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract93;
            workWord2 = Physics24Player4CView1;
            if (workWord2)
                goto subtract93;
            workWord2 = (int)Physics24Data6C570View1;
            workWord2 = Physics24Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_93;
            workWord2 = Physics24Player144View1;
            if (workWord2)
                goto add23_93;
            goto subtract93;
        add23_93:
            workWord2 = Physics24Player94View1;
            workWord2 += 23;
            Physics24Player94View1 = workWord2;
            return;
        subtract93:
            globalPointer = &Physics24Player94View1;
            workWord2 = Physics24Field(globalPointer, int*, 0);
            workWord2 -= 192;
            goto store95;
        }
        case 95:
        case 96:
        case 97: {
            int product95_0, product95_1, product95_2;
            register int numeric4 __asm__("$4");
            register int angle17 __asm__("$17");
            register void* vector17 __asm__("$17");
            workWord2 = (int)Physics24Player250View1;
            globalVector80 = Physics24Field((void*)workWord2, void**, 0);
            workWord2 = Physics24Field(globalVector80, int*, 76);
            if (!workWord2) {
                workWord2 = Physics24Field(globalVector80, int*, 88);
                workWord2++;
                Physics24Field(globalVector80, int*, 88) = workWord2;
            }
            workWord3 = Physics24Data6E044View2;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics24UpdatePlayerGroundInputTargetsView2(1536);
            numeric4 = Physics24Field(globalVector80, int*, 80);
            workWord2 = Physics24PlayerA4View1;
            workWord3 = numeric4 - 512;
            workWord2 -= workWord3;
            angle17 = workWord2 & 4095;
            workWord2 = angle17 < 1024;
            if (workWord2) {
                angle17 = numeric4;
                goto snapped95;
            }
            workWord2 = angle17 < 2048;
            if (workWord2) {
                angle17 = numeric4 + 1024;
                goto snapped95;
            }
            workWord2 = angle17 < 3072;
            angle17 = numeric4 + 2048;
            if (!workWord2)
                angle17 = numeric4 + 3072;
        snapped95:
            globalVector80 = &Physics24PlayerA4View1;
            numeric4 = Physics24Field(globalVector80, int*, 0);
            workWord2 = Physics24InterpolateCosineView2(numeric4 - angle17);
            workWord3 = Physics24PlayerACView1;
            product95_0 = workWord3 * workWord2;
            Physics24Field(globalVector80, int*, 0) = angle17;
            workWord2 = product95_0 >> 12;
            Physics24PlayerACView1 = workWord2;
            if (workWord2 < 0)
                Physics24PlayerACView1 = 0;
            workWord2 = Physics24ApproachPlayerTargetHeadingView2(90, 16);
            angle17 = Physics24PlayerACView1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            call4 = (void*)128;
            if (!workWord2) {
                workWord3 = Physics24PlayerB0View1;
                workWord2 = workWord3 < angle17;
                if (workWord2)
                    Physics24PlayerACView1 = workWord3;
            }
            Physics24ApproachPlayerTargetSpeedView2(call4, 256);
            call4 = (void*)Physics24PlayerA4View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            globalVector80 = &Physics24PlayerACView1;
            MATCHING_KEEP(globalVector80);
            Physics24Field(globalVector80, int*, 0) = angle17;
            workWord2 = Physics24InterpolateCosineView2(call4);
            workWord3 = Physics24PlayerB0View1;
            product95_1 = workWord3 * workWord2;
            call4 = (void*)Physics24PlayerA4View1;
            workWord2 = product95_1 >> 12;
            MATCHING_KEEP(workWord2);
            Physics24Field(globalVector80, int*, -44) = workWord2;
            workWord2 = Physics24InterpolateSineView2(call4);
            workWord3 = Physics24PlayerB0View1;
            product95_2 = workWord3 * workWord2;
            vector17 = globalVector80 - 32;
            MATCHING_KEEP(vector17);
            call4 = vector17;
            Physics24Player88View1 = 0;
            workWord2 = product95_2 >> 12;
            Physics24Player84View1 = workWord2;
            Physics24CopyVectorView1(call4, globalVector80 - 44);
            workWord2 = Physics24PlayerFCView1;
            if (workWord2)
                goto scalar95;
            workWord2 = Physics24PlayerB8View1;
            if (!workWord2)
                goto vector95;
        scalar95:
            workWord2 = Physics24PlayerA0View1;
            workWord2 -= 192;
            Physics24Player94View1 = workWord2;
            return;
        vector95:
            call4 = &Physics24Player8CView1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call6 = &Physics24PlayerE8View1;
            Physics24AddVectorView2(call4, call4, call6);
            return;
        }
        case 90:
            globalVector80 = &Physics24Player0View2 + 0xB8;
            workWord2 = Physics24Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero128;
            vectorAt30 = &originalFrame.spB8;
            Physics24ClearVectorView2(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics24SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.spC0 = 0;
            call5 = (void*)Physics24MeasureVectorLengthView2(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics24ScaleVectorRatioQ15View2(vectorAt30, call5, 64);
            originalFrame.spC0 = -192;
            globalVector80 -= 56;
            Physics24AddVectorView2(globalVector80, globalVector8CState20, vectorAt30);
            Physics24CopyVectorView1(globalVector8CState20, globalVector80);
            goto clamp128;
        zero128:
            Physics24ClearVectorView2(globalVector80 - 56);
            Physics24ClearVectorView2(globalVector80 - 44);
            goto clamp128;
        clamp128:
            globalPointer = &Physics24Player94View1;
            workWord2 = Physics24Field(globalPointer, int*, 0);
        clamp95:
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
            store95:
                __asm__ volatile("" ::"i"(0x80093C34) : "memory");
                Physics24Field(globalPointer, int*, 0) = workWord2;
            }
            return;
    }
}
#undef Physics24Field


extern Moby* Callback24QueryMoby __asm__("D_80070328+0x250");
extern Moby* Callback24FirstCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback24SecondCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback24InitialMoby __asm__("D_80070328+0x250");
extern int Callback24ClearedWord __asm__("D_80070328+0x28");
extern unsigned char Callback24MobyPointer[] __asm__("D_80070328+0x250");
extern Moby* Callback24Word71930 __asm__("D_80071930");
extern int Callback24WordE1D4 __asm__("D_8006E1D4");
extern int Callback24WordE1D8 __asm__("D_8006E1D8");
extern int Callback24WordE530 __asm__("D_8006E530");
extern int Callback24WordE52C __asm__("D_8006E52C");
extern void (*Callback24Header344)(void) __asm__("unk_ovlheader_80074344");
int Callback24QueryWorldSegment(Vector3D*, Vector3D*) __asm__("func_80018368");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80093C5C.
 * Verified14 supplies byte position and shared query routes; verified13 supplies
 * independently scheduled table/flag paths. Original24 supplies private-data
 * selectors56..61, header344 and numeric helper/vector chains. Pointer offsets
 * are bytes: private4C/50/54/58, selected unsigned byte46 shifted4 and word0,
 * player28+8/-28, playerBC-8C/-BC and global250-250. Vectors at stack18/28
 * use original integers600/0/-380 and400/0/200; their units are unresolved.
 * Separate aliases name the same original addresses to preserve independent
 * loads. Empty constraints emit no instructions and retain original lifetimes,
 * load-delay order and branch targets. Header344 has no newly prepared argument;
 * helper return values are used only in their observed numeric/pointer roles.
 * Helper meanings, selector semantics, cadence and retail runtime remain open.
 * Acceptance requires every code/local-jump/table word, strict full translation
 * unit and complete original EXE and overlay hashes.
 */
extern Spyro Callback24Player __asm__("D_80070328");
int Callback24SamplePlanarPhaseTable(int x, int y) __asm__("func_80037058");
void Callback24ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback24CapturePlayerPlanarVectorDifference(void) __asm__("func_80041AE8");
void Callback24UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback24UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
void Callback24BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
extern int Callback24Word8006E538 __asm__("D_8006E538");
int Callback24ReadSelectedFrameScalar(Moby*) __asm__("func_80055E84");
void Callback24TransformVectorByBasis(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
void* Callback24QueryDynamicMobyGeometry(Vector3D*, int, int, int, int,
                                         Moby*) __asm__("func_8001BA30");
int Callback24QueryWorldSphereWithOptions(Vector3D*, int, int, int, int,
                                          Moby*) __asm__("func_80019138");
int Callback24QueryWorldSegmentWithOptions(Vector3D*, Vector3D*, int, int,
                                           Moby*) __asm__("func_8001830C");
extern int Callback24Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback24Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback24Values[] __asm__("D_8006FCF0");
void Callback24MarkPlayerSegmentSurfaceType3Flags(void) __asm__("func_80049590");
int Callback24SoundHandleMatchesIdInStates1Or2(int, int) __asm__("func_8003BF6C");
void func_level_24_80093C5C(void) {
    struct {
        Vector3D first;
        int reserved24;
        Vector3D second;
        int reserved34;
    } local;
    register unsigned char* privateData __asm__("$16");
    register unsigned char* privateOther __asm__("$16");
    register Moby* selected __asm__("$2");
    register int selectedClass __asm__("$3");
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    register int flagOffset __asm__("$3");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback24Player.animationState) {
        case 0x14:
        case 0x55:
            if (func_800438F4() == 0)
                func_80043728();
            Callback24UpdatePlayerCollisionResponse();
            Callback24Player.unk9a = 0;
            Callback24UpdatePlayerSurfaceState();
            goto clearSharedValue;
        case 0x5A:
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            goto clearSharedValue;
        case 0x1D:
        case 0x58:
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            goto queryC00;
        case 0x28:
        case 0x29:
        case 0x39:
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            descriptor = &Callback24Player.unk22[2];
            if (Callback24SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback24Values + valueOffset);
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
                *(int*)(Callback24Values + valueOffset) = tableValue;
            setDecreasingFlag:
                flagOffset = *descriptor * 0x2C;
                Callback24Flags[flagOffset] = Callback24Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x2A:
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24MarkPlayerSegmentSurfaceType3Flags();
            descriptor = &Callback24Player.unk22[2];
            if (Callback24SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback24Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback24Player.unk22[2];
            }
            if (Callback24SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback24Values + valueOffset);
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
                *(int*)(Callback24Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback24Flags[flagOffset] = Callback24Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24CapturePlayerPlanarVectorDifference();
            if ((unsigned char)Callback24Player.unk10[4] != 0) {
                computedValue = -Callback24Player.unk9ha[4] -
                                Callback24SamplePlanarPhaseTable(Callback24Player.position.x,
                                                                 Callback24Player.position.y);
                positionValue = Callback24Player.unk4a - computedValue;
                Callback24Player.unk4[0] = computedValue;
                positionDelta = (int)Callback24Player.union144.a.unk13cc >> 6;
                positionValue -= positionDelta;
                MATCHING_KEEP(positionValue);
                Callback24Player.position.z = positionValue;
                return;
            }
            break;
        case 0x56:
        case 0x5C:
            privateData = Callback24Player.critterMobyPtr->mobyTag;
            func_800438F4();
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24ProbePlayerContactSegment();
            if ((unsigned char)Callback24Player.unk10[2] != 0) {
                selected = Callback24Word71930;
                *(Moby**)(privateData + 0x4C) = selected;
                if (selected) {
                    selectedClass = selected->mobyClass;
                    if (selectedClass != 0x4B && selectedClass != 0x4F && selectedClass != 0x2FF) {
                        *(Moby**)(privateData + 0x4C) = 0;
                        goto queryC00;
                    }
                    goto copySelected;
                }
            } else
                goto clearSelected;
            goto queryC00;
        case 0x57: {
            register unsigned char* sourceBase __asm__("$17");
            register int* clearedWord __asm__("$16");
            register Moby** mobyPointer __asm__("$16");
            void* result;
            register Moby* initialMoby __asm__("$4");
            func_800438F4();
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24ProbePlayerContactSegment();
            Callback24BuildNegatedNormalizedPlayerVector(0xC00);
            initialMoby = Callback24InitialMoby;
            MATCHING_KEEP_VOLATILE_CLOBBER(initialMoby, "memory");
            clearedWord = &Callback24ClearedWord;
            *clearedWord = 0;
            if (initialMoby->animationState.id == 2 &&
                Callback24ReadSelectedFrameScalar(initialMoby) >= 4 &&
                Callback24ReadSelectedFrameScalar(Callback24QueryMoby) < 13) {
                local.first.x = 0x600;
                local.first.y = 0;
                local.first.z = -0x380;
                Callback24TransformVectorByBasis((unsigned char*)clearedWord + 8, &local.first,
                                                 &local.first);
                sourceBase = (unsigned char*)clearedWord - 0x28;
                func_8004F194(&local.first, &local.first, (Vector3D*)sourceBase);
                result = Callback24QueryDynamicMobyGeometry(&local.first, 0x400, 1, 0, 0,
                                                            Callback24FirstCallMoby);
                if (result) {
                    func_8004F178(&local.second, (Vector3D*)((unsigned char*)result + 0xC));
                    local.second.z += 0x80;
                    if (Callback24QueryWorldSegment((Vector3D*)sourceBase, &local.second) == 0)
                        Callback24QueryDynamicMobyGeometry(&local.first, 0x400, 1, 0, 0x04000000,
                                                           Callback24SecondCallMoby);
                }
                {
                    register Vector3D* argument0 __asm__("$4") = &local.first;
                    register int argument1 __asm__("$5") = 0x400;
                    register int argument2 __asm__("$6") = 0;
                    register int argument3 __asm__("$7") = 0;
                    register Moby* lastMoby __asm__("$3");
                    MATCHING_KEEP4_VOLATILE_CLOBBER(argument0, argument1, argument2, argument3,
                                                    "memory");
                    mobyPointer = (Moby**)Callback24MobyPointer;
                    lastMoby = *mobyPointer;
                    Callback24QueryWorldSphereWithOptions(argument0, argument1, argument2,
                                                          argument3, 0x04000000, lastMoby);
                }
                Callback24QueryWorldSegmentWithOptions(
                    (Vector3D*)((unsigned char*)mobyPointer - 0x250), &local.first, 0, 0x04000000,
                    *mobyPointer);
                if (Callback24ReadSelectedFrameScalar(*mobyPointer) >= 8) {
                    register int* limitPointer __asm__("$3") = &Callback24WordE1D4;
                    if (*limitPointer < 0xC00)
                        *limitPointer = 0xC00;
                    if (Callback24WordE1D8 < 10)
                        Callback24WordE1D8 = 10;
                    Callback24WordE530 = 120;
                    Callback24WordE52C = 5;
                }
            }
            if (Callback24Player.unk5 == 1) {
                if (Callback24Player.ticksSinceLastSurfaceTouch == 0)
                    Callback24Player.unk5 = 0;
            } else if (Callback24Player.ticksSinceLastSurfaceTouch != 0) {
                Callback24Player.unk5 = 1;
                Callback24Player.unk7a[2].z = Callback24Player.unk7a[3].z;
            }
            return;
        }
        case 0x59:
            privateOther = Callback24Player.critterMobyPtr->mobyTag;
            Callback24Header344();
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24ProbePlayerContactSegment();
            if ((unsigned char)Callback24Player.unk10[2] != 0) {
                selected = Callback24Word71930;
                *(Moby**)(privateOther + 0x4C) = selected;
                if (selected) {
                    selectedClass = selected->mobyClass;
                    if (selectedClass == 0x4B || selectedClass == 0x4F || selectedClass == 0x2FF) {
                        register Moby* bytePointer __asm__("$2") = *(Moby**)(privateOther + 0x4C);
                        register int shiftedByte __asm__("$2") =
                            ((unsigned char*)bytePointer)[0x46];
                        register Moby* propertyPointer __asm__("$3");
                        register int propertyWord __asm__("$2");
                        MATCHING_BARRIER_VOLATILE("memory");
                        propertyPointer = *(Moby**)(privateOther + 0x4C);
                        shiftedByte <<= 4;
                        *(int*)(privateOther + 0x50) = shiftedByte;
                        propertyWord = *(int*)propertyPointer;
                        MATCHING_BARRIER_VOLATILE("memory");
                        *(int*)(privateOther + 0x58) = 0;
                        *(int*)(privateOther + 0x54) = propertyWord;
                        Callback24Player.unk5 = 1;
                    } else
                        goto clearSelectedOther;
                }
            } else {
            clearSelectedOther:
                *(Moby**)(privateOther + 0x4C) = 0;
                Callback24Player.unk5 = 0;
            }
            goto clearSharedValue;
        case 0x5B: {
            register Vector3D* vectorBase __asm__("$16");
            register void* argument0 __asm__("$4");
            if (func_800438F4() == 0)
                func_80043728();
            Callback24UpdatePlayerCollisionResponse();
            Callback24Player.unk9a = 0;
            Callback24UpdatePlayerSurfaceState();
            Callback24Player.unk4[0] = 0;
            argument0 = (unsigned char*)&Callback24Player.unk9a - 0x8C;
            if (Callback24Player.critterMobyPtr->animationState.id == 6) {
                vectorBase = &local.second;
                local.second.x = 0x400;
                local.second.y = 0;
                local.second.z = 0x200;
                Callback24TransformVectorByBasis(argument0, vectorBase, vectorBase);
                func_8004F194(vectorBase, vectorBase,
                              (Vector3D*)((unsigned char*)&Callback24Player.unk9a - 0xBC));
                Callback24QueryDynamicMobyGeometry(vectorBase, 0x400, 0, 0, 0x08000000,
                                                   Callback24Player.critterMobyPtr);
            }
            return;
        }
        case 0x5D:
        case 0x5E:
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24ProbePlayerContactSegment();
            if (Callback24Player.unk5 != 0x7F) {
                if (Callback24Player.unk7a[3].z < 0 && Callback24Player.animationStateFrames >= 4)
                    Callback24Player.unk5 = 1;
                else if (Callback24Player.unk5 == 0 && !(Callback24Word8006E538 & 0x40) &&
                         Callback24Player.union144.a.unk13cb == 0)
                    Callback24Player.unk5 = 2;
            }
            goto clearSharedValue;
        case 0x5F:
        case 0x60:
        case 0x61:
            privateData = Callback24Player.critterMobyPtr->mobyTag;
            Callback24Header344();
            func_800438F4();
            Callback24UpdatePlayerCollisionResponse();
            Callback24UpdatePlayerSurfaceState();
            Callback24ProbePlayerContactSegment();
            if ((unsigned char)Callback24Player.unk10[2] != 0) {
                selected = Callback24Word71930;
                *(Moby**)(privateData + 0x4C) = selected;
                if (selected) {
                    selectedClass = selected->mobyClass;
                    if (selectedClass == 0x4B || selectedClass == 0x4F || selectedClass == 0x2FF)
                        goto copySelected;
                    goto clearSelected;
                }
            } else
                goto clearSelected;
            goto queryC00;
        copySelected:
            {
                register Moby* bytePointer __asm__("$2") = *(Moby**)(privateData + 0x4C);
                register int shiftedByte __asm__("$2") = ((unsigned char*)bytePointer)[0x46];
                register Moby* propertyPointer __asm__("$3");
                register int propertyWord __asm__("$2");
                MATCHING_BARRIER_VOLATILE("memory");
                propertyPointer = *(Moby**)(privateData + 0x4C);
                shiftedByte <<= 4;
                *(int*)(privateData + 0x50) = shiftedByte;
                propertyWord = *(int*)propertyPointer;
                MATCHING_BARRIER_VOLATILE("memory");
                *(int*)(privateData + 0x58) = 0;
                *(int*)(privateData + 0x54) = propertyWord;
                goto queryC00;
            }
        clearSelected:
            *(Moby**)(privateData + 0x4C) = 0;
        queryC00:
            Callback24BuildNegatedNormalizedPlayerVector(0xC00);
        clearSharedValue:
            Callback24Player.unk4[0] = 0;
            return;
        default:
            return;
    }
}


#define LEVEL_ID 24
#define PlaySpyroSounds_level_24 func_level_24_80094558
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_24_800946C4(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x14:
        case 0x1d:
        case 0x2b:
        case 0x2c:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x5a:
        case 0x5b:
        case 0x5c:
        case 0x5f:
        case 0x60:
        case 0x61:
            func_80043ABC(&spyro.unk9e);
            break;
        case 0x59:
        case 0x5d:
        case 0x5e:
            func_80043ABC(0);
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80094740.
 * Reuses verified30/44 underwater/surface stack vectors and39 signed table
 * producer, plus verified43 numeric21C/220/224 hurt route. Original24 supplies
 * selector14, shared sound descriptor15/19 call,55..61 routes,58 signed-halfword
 * vectors,5D state50 vector8C/98 and5E saved S1 value2/A1 source98 ordering.
 * Word60 wrap/clamp uses FFF/801/1000; inputs800/801/FFF yield0/-7FF/-1 before
 * helpers. Numeric pointer offsets are bytes, access widths/branches/shifts
 * retain disc instructions. Stack spacing and empty compiler constraints do
 * not imply original C variables. All code/local jumps/owned table words,
 * strict full TU and complete EXE/every overlay hashes are required.
 * Helper meanings, units/conversions, sound semantics and caller cadence are
 * unverified; code executes once per invocation. Live runtime parity is open.
 */
extern Spyro Transition24_D_80070328 __asm__("D_80070328");
int Transition24MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition24ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition24_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition24RawUnion[] __asm__("D_80070328+0x144");
extern int Transition24RawMovement __asm__("D_80070328+0x50");
extern void (*Call24Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw24State[] __asm__("D_80070328+0x50");
extern Spyro Special24_D_80070328 __asm__("D_80070328");
extern short Signed24TableA[] __asm__("D_800658A0");
extern short Signed24TableB[] __asm__("D_80065920");
int Special24MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Special24ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Special24_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call24QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
extern int Raw24NegativeWord __asm__("D_80070328+0x28");
extern int Raw24TableIndex __asm__("D_80070328+0x298");
extern int Raw24Yaw __asm__("D_80070328+0x64");
int Transition24RandBetween(int, int) __asm__("func_8003636C");
void Transition24ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Transition24BuildNegatedNormalizedPlayerVector(int) __asm__("func_80043A38");
void func_level_24_80094740(int arg0) {
    struct {
        Vector3D first;
        int gap1;
        Vector3D second;
        int gap2;
        Vector3D third;
    } vectors;
    register int negativeWord __asm__("$3");
    int firstResult, secondResult, firstWrappedWord, secondWrappedWord, firstParticleKind,
        secondParticleKind, firstParticleSubtype, secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* sourceBytesA __asm__("$16");

    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    switch (arg0) {
        case 0x14:
            Transition24_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition24_D_80070328.unk5 = 0;
            Transition24ClearPlayerMotionVectors();
            Transition24_D_80070328.grounded = 1;
            Transition24_D_80070328.union144.a.unk13cb = Transition24RandBetween(1, 3);
            Transition24_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x1D: {
            register int oldState __asm__("$4") = Transition24RawMovement;
            register int first __asm__("$3") = Transition24_D_80070328.unk17e.x;
            register int second __asm__("$2");
            register int third __asm__("$3");
            MATCHING_KEEP2_CLOBBER(oldState, first, "memory");
            second = 7;
            MATCHING_KEEP(second);
            Transition24RawMovement = second;
            MATCHING_BARRIER_VOLATILE("memory");
            second = Transition24_D_80070328.unk17e.y;
            MATCHING_KEEP_VOLATILE_CLOBBER(second, "memory");
            Transition24_D_80070328.unk5 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(first, "memory");
            first <<= 6;
            MATCHING_KEEP(first);
            Transition24_D_80070328.unk7a[2].x = first;
            MATCHING_BARRIER_VOLATILE("memory");
            third = Transition24_D_80070328.unk17e.z;
            second <<= 6;
            Transition24_D_80070328.union144.a.unk13cb = oldState;
            Transition24_D_80070328.unk7a[2].y = second;
            second = third << 6;
            if (third == 0)
                second = Transition24_D_80070328.unk7a[3].z;
            Transition24_D_80070328.unk7a[2].z = second;
            Transition24BuildNegatedNormalizedPlayerVector(0xC00);
            Transition24_D_80070328.grounded = 1;
            Transition24_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            soundSelector = D_8006C654->spyroHurt;
            soundZero = 0;
            goto sharedSound;
        }

        case 0x28:
        case 0x29:
            if (((unsigned)(Transition24_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition24_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition24_D_80070328.movementState - 0x50));
                    if ((Transition24_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw24NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition24_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call24QueryWorldHeight(&vectors.first, 0x800);
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
                firstWrappedWord = Transition24_D_80070328.rotation.pitch & 0xFFF;
                Transition24_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition24_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition24_D_80070328.rotation.pitch > 0) {
                    Transition24_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition24_D_80070328.unk5 = 1;
                }
                Transition24ClearVector(
                    (Vector3D*)((unsigned char*)&Transition24_D_80070328.rotation.pitch + 0xEC));
                Transition24_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition24_D_80070328.unk8[0] = Transition24MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition24_D_80070328.rotation.pitch + 0x38), 0);
                Transition24_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition24_D_80070328.animationState == 0x2A) {
                Transition24_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition24_D_80070328.union144.a.unk13da = 0;
            }
            Transition24_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition24_D_80070328.unk20a = 0;
            Transition24_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw24State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw24NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition24_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call24QueryWorldHeight(localVector, 0x800);
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
                if (Transition24_D_80070328.animationState == 0x2E) {
                    Transition24_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition24_D_80070328.rotation.pitch & 0xFFF;
                Transition24_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition24_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition24_D_80070328.rotation.pitch > 0) {
                    Transition24_D_80070328.rotation.pitch = 0;
                }
                Transition24_D_80070328.unk5 = 1;
                Transition24ClearVector(
                    (Vector3D*)((unsigned char*)&Transition24_D_80070328.animationState + 0x104));
                Transition24_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition24_D_80070328.unk8[0] = Transition24MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition24_D_80070328.animationState + 0x50), 0);
                Transition24_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition24_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition24_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition24RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition24RawUnion;
                    *(int*)unionPointer = (-Transition24_D_80070328.unk7a[2].z) >> 2;
                    if (Transition24RawMovement != 8) {
                        Transition24_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition24RawMovement = 10;
                    }
                    Transition24_D_80070328.unk5 = 0;
                    Transition24_D_80070328.unk8[0] =
                        Transition24MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition24_D_80070328.grounded = 1;
                    Transition24_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call24QueryWorldHeight(localVector, 0x800);
                    vectors.third.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, localVector, 0);
                        SpawnParticle(6, 0x2E, localVector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        case 0x39: {
            register int previousMovement __asm__("$2") = Transition24RawMovement;
            register int numericKind __asm__("$3");
            register int indexWord __asm__("$3");
            register unsigned char* unionPointer __asm__("$5");
            register int tableOffset __asm__("$2");
            register int tableWord __asm__("$3");
            MATCHING_KEEP(previousMovement);
            numericKind = 7;
            MATCHING_KEEP(numericKind);
            Transition24RawMovement = numericKind;
            MATCHING_BARRIER_VOLATILE("memory");
            indexWord = Raw24TableIndex;
            MATCHING_KEEP_VOLATILE_CLOBBER(indexWord, "memory");
            unionPointer = Transition24RawUnion;
            MATCHING_KEEP2_CLOBBER(indexWord, unionPointer, "memory");
            Transition24_D_80070328.unk5 = 0;
            *(int*)unionPointer = previousMovement;
            if (indexWord < 0)
                Raw24TableIndex = ((Raw24Yaw + 0x800) >> 4) & 0xFF;
            tableOffset = Raw24TableIndex * 2;
            tableWord = *(short*)((unsigned char*)Signed24TableB + tableOffset);
            destination = (Vector3D*)(unionPointer - 0xC4);
            *(int*)(unionPointer - 0xB8) = tableWord;
            tableOffset = *(short*)((unsigned char*)Signed24TableA + tableOffset);
            Transition24_D_80070328.unk7a[2].z = 0;
            Transition24_D_80070328.unk7a[2].y = tableOffset;
            func_8004F178(destination, (Vector3D*)(unionPointer - 0xB8));
            Transition24_D_80070328.grounded = 1;
            Transition24_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            {
                register unsigned char* soundTable __asm__("$2") = (unsigned char*)D_8006C654;
                MATCHING_KEEP_VOLATILE_CLOBBER(soundTable, "memory");
                soundZero = 0;
                soundSelector = soundTable[0x19];
            }
        sharedSound:
            PlaySound(soundSelector, (Moby*)soundZero, 0);
        }
        clearPointers:
            Transition24_D_80070328.unk20a = 0;
            Transition24_D_80070328.critterMobyPtr = 0;
            return;
        case 0x55:
        case 0x5B:
            Transition24_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition24_D_80070328.unk5 = 0;
            Transition24ClearPlayerMotionVectors();
            Transition24_D_80070328.grounded = 1;
            return;
        case 0x56:
        case 0x57:
        case 0x5C:
        case 0x5F:
        case 0x60:
        case 0x61:
            Transition24_D_80070328.movementState = MOVEMENT_STATE_WALK;
            if ((arg0 == 0x57) && (Transition24_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
                func_8004F178((Vector3D*)((unsigned char*)(unsigned char*)&Transition24_D_80070328
                                              .movementState +
                                          0x3C),
                              (Vector3D*)((unsigned char*)(unsigned char*)&Transition24_D_80070328
                                              .movementState +
                                          0x48));
                Transition24_D_80070328.unk5 = 1;
            } else {
                Transition24_D_80070328.unk5 = 0;
            }
            Transition24_D_80070328.unk8[0] =
                Transition24MeasureVectorLength(&Transition24_D_80070328.unk7a[3], 0);
            Transition24BuildNegatedNormalizedPlayerVector(0xC00);
            Transition24_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition24_D_80070328.grounded = 1;
            goto clearSpecialTail;
        case 0x58:
            Special24_D_80070328.movementState = MOVEMENT_STATE_HURT;
            Special24_D_80070328.unk5 = 0;
            if (Special24_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Special24_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed24TableB + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                tableValueA >>= 1;
                Special24_D_80070328.unk7a[2].x = tableValueA;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed24TableA + tableOffsetOrValue);
                Special24_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Special24_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else {
                Special24ClearVector(
                    (Vector3D*)((unsigned char*)&Special24_D_80070328.movementState + 0x3C));
            }
            Special24_D_80070328.unk7a[2].z = 0x200;
            func_8004F178((Vector3D*)((unsigned char*)&Special24_D_80070328.unk7a[2].z - 0x14),
                          (Vector3D*)((unsigned char*)&Special24_D_80070328.unk7a[2].z - 8));
            Special24_D_80070328.grounded = 1;
            Special24_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
                return;
            }
        default:
            return;
        case 0x5A:
            Transition24_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition24_D_80070328.unk5 = 0;
            Transition24BuildNegatedNormalizedPlayerVector(0xC00);
            Transition24_D_80070328.grounded = 1;
            Transition24_D_8006E524 = 0xF;
            return;
        case 0x59:
            Transition24_D_80070328.movementState = MOVEMENT_STATE_FALL;
            if (Transition24_D_80070328.animationState == 0x5F) {
                Transition24_D_80070328.unk5 = 1;
            } else {
                Transition24_D_80070328.unk5 = 0;
            }
            Transition24_D_80070328.unk8[0] =
                Transition24MeasureVectorLength(&Transition24_D_80070328.unk7a[3], 0);
            Transition24_D_80070328.grounded = 0;
            Transition24_D_80070328.unk15b = 1;
        clearSpecialTail:
            Transition24_D_80070328.idle = 0;
            Transition24_D_80070328.unk15g = 0;
            return;
        case 0x5D:
            stateBaseA = Raw24State;
            MATCHING_KEEP(stateBaseA);
            destination = (Vector3D*)(stateBaseA + 0x3C);
            MATCHING_KEEP(destination);
            sourceBytesA = stateBaseA + 0x48;
            *(int*)stateBaseA = 2;
            func_8004F178(destination, (Vector3D*)sourceBytesA);
            Special24_D_80070328.unk8[0] = Special24MeasureVectorLength((Vector3D*)sourceBytesA, 0);
            Special24_D_80070328.unk7a[2].z = 0xA00;
            Special24_D_80070328.unk5 = 0;
            Special24_D_80070328.union144.a.unk13cb = 0;
            Special24_D_80070328.grounded = 0;
            PlaySound((int)D_8006C654->jump, 0, 0);
            return;
        case 0x5E: {
            register unsigned char* state __asm__("$2") = Raw24State;
            register Vector3D* source __asm__("$16");
            register Vector3D* argument __asm__("$5");
            register int numericKind __asm__("$17");
            MATCHING_KEEP(state);
            destination = (Vector3D*)(state + 0x3C);
            MATCHING_KEEP(destination);
            source = (Vector3D*)(state + 0x48);
            __asm__ volatile("" : "=r"(source) : "0"(source) : "$17", "memory");
            argument = source;
            MATCHING_KEEP(argument);
            numericKind = 2;
            MATCHING_KEEP(numericKind);
            *(int*)state = numericKind;
            func_8004F178(destination, argument);
            Transition24_D_80070328.unk8[0] = Transition24MeasureVectorLength(source, 0);
            Transition24_D_80070328.unk5 = numericKind;
            Transition24_D_80070328.union144.a.unk13cb = 0;
            Transition24_D_80070328.grounded = 0;
            return;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8009518C.
 * Assembly SHA256 8b592f741de1d38aa72a5bcea5df0114be270ecb8d730ea7a6c3c19fe52c1d74.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1213 original instructions and78 state-table entries (bias20).
 * Verified donor41 original85..97 chains retain callback1, input/collision priority,
 * raw nested-object fields, signed wrapped heading thresholds, three-axis
 * products, partial effect callback, raw helper arguments and counter stores.
 * The original0x38 frame retains vectors atSP10/SP20 and savedS0.
 * Verified generic states retain all target selector and branch joins.
 * Rev1's source-locked thirteen transition graphs are decoding references;
 * no browser-derived behavior or values are used. Typed view aliases remain
 * distinct; exact symbols and per-state donors are recorded in provenance.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim24Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim24Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim24Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim24PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim24PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim24PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim24PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim24Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim24Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim24Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim24Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim24Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim24Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim24Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim24Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim24Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim24PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim24Data66530View1[] __asm__("D_80066530");
extern int Anim24Data6E538View1 __asm__("D_8006E538"), Anim24Data6E53CView1 __asm__("D_8006E53C");
extern int Anim24Data6E044View1 __asm__("D_8006E044"), A4898Gate __asm__("D_8006E344"),
    A4898Count __asm__("D_8006C514");
int Anim24ProcessPlayerStateFlagsView1() __asm__("func_80040994");
int Anim24DispatchPlayerStateRequestView1() __asm__("func_8004BEF8");
int Anim24SelectPlayerAnimationLoopRequestView1() __asm__("func_80049688");
int Anim24UpdatePlayerRetryStateView1() __asm__("func_800498C0");
extern int Anim24Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim24Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim24PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim24Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim24Player280View2 __asm__("D_80070328 + 0x280");
extern int Anim24Data6E538View2 __asm__("D_8006E538"), Anim24Data6E53CView2 __asm__("D_8006E53C");
extern int Anim24Data6E044View2 __asm__("D_8006E044"), A21Gate __asm__("D_8006E344"),
    A21Count __asm__("D_8006C514");
extern int (*Anim24Data74374View1)() __asm__("unk_ovlheader_80074374");
int Anim24ProcessPlayerStateFlagsView2() __asm__("func_80040994");
int Anim24DispatchPlayerStateRequestView2() __asm__("func_8004BEF8");
extern volatile int Anim24Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim24Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim24Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim24Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim24Data6EE2CView1 __asm__("D_8006EE2C");
int Anim24ProcessPlayerContactFlagsView1() __asm__("func_80040BCC");
int Anim24QueryWorldHeightWithOptionsView1() __asm__("func_8001A310");
extern int Anim24Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim24Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim24Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim24Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim24Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim24Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim24Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim24PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim24PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim24PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim24PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim24PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim24PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim24PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim24PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim24Player144View3 __asm__("D_80070328 + 0x144");
extern int Anim24Player280View3 __asm__("D_80070328 + 0x280");
extern unsigned char Anim24Player0View1[] __asm__("D_80070328");
extern unsigned char* Anim24Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim24Data6E535View2 __asm__("D_8006E535");
extern int Anim24Data6E538View3 __asm__("D_8006E538");
extern int Anim24Data6E53CView3 __asm__("D_8006E53C");
extern int Anim24Data6E530View1 __asm__("D_8006E530");
extern int Anim24Data6E52CView1 __asm__("D_8006E52C");
extern int (*Anim24Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim24DataSpawnParticleView1)(int, int, void*, int) __asm__("SpawnParticle");
int Anim24ReadSelectedFrameScalarView1(void*) __asm__("func_80055E84");
int Anim24DispatchPlayerStateRequestView3(int) __asm__("func_8004BEF8");
extern int Anim24PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim24PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim24PlayerA0View1 __asm__("D_80070328 + 0xA0");
int Anim24SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Anim24PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Anim24PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
#define Anim24Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_level_24_8009518C(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    struct {
        int at10[4], at20[4];
    } frame;
    register int* savedPointer16 __asm__("$16");
    rawValue2 = Anim24Player48View1;
    switch (rawValue2) {
        case 20:
            if (Anim24ProcessPlayerStateFlagsView1())
                return;
            rawValue2 = Anim24Data6E53CView1 & 64;
            nextSelector4 = 6;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            if (Anim24PlayerE4View1 >= 23)
                goto select;
            rawValue3 = Anim24Data6E538View1;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 13;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            if (rawValue2 >= 17) {
                nextSelector4 = 1;
                goto select;
            }
            rawValue2 = rawValue3 & 12;
            MATCHING_KEEP(rawValue2);
            if (!rawValue2) {
                rawValue2 = Anim24PlayerACView1;
                nextSelector4 = 1;
                if (rawValue2)
                    goto select;
            }
            if (Anim24Data6E044View1 == 7 || Anim24Player240View1) {
                savedPointer16 = &Anim24Player48View2;
                MATCHING_KEEP(savedPointer16);
                if (!*savedPointer16)
                    return;
                Anim24DispatchPlayerStateRequestView1(0);
                if (Anim24Data66530View1[*((unsigned char*)savedPointer16 - 0x2C)] >= 96) {
                    Anim24Player14View1 = Anim24Player15View1;
                    Anim24Player16View1 = Anim24Player17View1;
                }
                Anim24Player17View1 = 0;
                rawValue3 = *savedPointer16;
                rawValue2 = 113;
                *((unsigned char*)savedPointer16 - 0x2C) = rawValue2;
                Anim24Player1F0View1 = 0;
                Anim24Player15View1 = rawValue3;
                Anim24Player1ECView1 = rawValue3;
                return;
            }
            rawValue2 = Anim24PlayerFCView1;
            nextSelector4 = 15;
            if (rawValue2)
                goto select;
            Anim24SelectPlayerAnimationLoopRequestView1();
            return;
        case 29:
            if (Anim24Player54View1 < 25)
                return;
            if (Anim24Player280View1 < 0) {
                nextSelector4 = 31;
                goto select;
            }
            rawValue2 = 10;
            rawValue3 = Anim24Player144View1;
            if (rawValue3 == rawValue2) {
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 44;
                goto select;
            }
            rawValue2 = rawValue3 - 11;
            if ((unsigned)rawValue2 < 2) {
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 41;
                goto select;
            }
            rawValue2 = Anim24PlayerB8View1;
            nextSelector4 = 0;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            nextSelector4 = 7;
            goto select;
        case 40:
            if (Anim24ProcessPlayerStateFlagsView2())
                return;
            if ((Anim24Data6E538View2 & 128) && Anim24Player4CView1 != 1) {
                nextSelector4 = 42;
                goto select;
            }
            if (Anim24PlayerB0View1)
                return;
            rawValue2 = Anim24Player20CView1 & 64;
            nextSelector4 = 41;
            if (!rawValue2)
                goto select;
            if (Anim24Player214View1 <= 0)
                return;
            goto select;
        case 41:
            if (Anim24ProcessPlayerStateFlagsView2())
                return;
            nextSelector4 = Anim24Data6E538View2;
            rawValue2 = nextSelector4 & 128;
            if (rawValue2) {
                nextSelector4 = 42;
                goto select;
            }
            rawValue2 = 7;
            rawValue3 = Anim24Data6E044View2;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = nextSelector4 & 64;
            nextSelector4 = 40;
            if (rawValue2)
                goto select;
            if (!(Anim24Player20CView1 & 64))
                return;
            if (!Anim24Player214View1)
                goto select;
            return;
        case 42:
            if (Anim24ProcessPlayerContactFlagsView1())
                return;
            if ((Anim24Data6E538View2 & 128) || Anim24Player4CView1 == 1)
                goto flag64;
            rawValue2 = Anim24Player20CView1 & 128;
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        flag64:
            rawValue2 = Anim24Player20CView1 & 64;
            nextSelector4 = 40;
            if (!rawValue2)
                return;
            goto select;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (Anim24ProcessPlayerStateFlagsView2())
                return;
            if ((Anim24Data6E53CView2 & 64) && Anim24Player54View2 >= 9) {
                nextSelector4 = 6;
                goto partialCall;
            }
            byte4 = &Anim24Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto partialCall;
            }
            if (!(Anim24Data6E53CView2 & 128))
                goto check44;
            if (Anim24Player54View2 < 9)
                goto check44;
            rawValue2 = *(int*)(Anim24Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto check44;
            rawValue2 = Anim24QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (rawValue2)
                goto check44;
            goto select;
        partialCall:
            Anim24DispatchPlayerStateRequestView2(nextSelector4);
        check44:
            rawValue2 = Anim24Data6E535View1;
            nextSelector4 = 44;
            if (!rawValue2)
                return;
            goto select;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3 = Anim24Player4CView1;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                goto other44;
            if (Anim24Data6E53CView2 & 0x850)
                goto callback44;
            if (Anim24Player54View2 < 61)
                return;
        callback44:
            callback2 = Anim24Data74374View1;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto call498C0;
        other44:
            if (Anim24ProcessPlayerStateFlagsView2())
                return;
            if ((Anim24Data6E53CView2 & 64) && Anim24Player54View2 >= 9) {
                nextSelector4 = 6;
                goto select;
            }
            byte4 = &Anim24Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto select;
            }
            if (!(Anim24Data6E53CView2 & 128))
                goto mode44;
            if (Anim24Player54View2 < 9)
                goto mode44;
            rawValue2 = *(int*)(Anim24Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto mode44;
            rawValue2 = Anim24QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        mode44:
            rawValue3 = Anim24Data6E044View2;
            rawValue2 = 7;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = Anim24Data6E535View1;
            nextSelector4 = 43;
            if (rawValue2)
                return;
            goto select;
        }
        case 57:
            if (Anim24Player54View2 < 25)
                return;
            if (Anim24Player280View2 < 0) {
                __asm__ volatile("" ::"i"(0x800957CC) : "memory");
                nextSelector4 = 31;
                goto select;
            }
            rawValue2 = 10;
            rawValue3 = Anim24Player144View2;
            nextSelector4 = 41;
            if (rawValue3 != rawValue2)
                goto select;
            nextSelector4 = 44;
            goto select;
        case 85:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue3 = Anim24Data6E53CView3;
            rawValue2 = rawValue3 & 64;
            nextSelector4 = 93;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerB8View2 < 4;
            nextSelector4 = 89;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = rawValue3 & 32;
            nextSelector4 = 87;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 91;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerA8View2;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 86;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim24Data6E538View3 & 12;
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerACView2;
            if (!rawValue2)
                return;
            goto select;
        case 86:
            rawValue2 = (int)Anim24Player250View1;
            callback3 = Anim24Data7431CView1;
            record16 = Anim24Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue3 = Anim24Data6E53CView3;
            rawValue2 = rawValue3 & 64;
            nextSelector4 = 93;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerB8View2 < 4;
            nextSelector4 = 89;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = rawValue3 & 32;
            nextSelector4 = 87;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 91;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24Data6E535View2;
            if (!rawValue2)
                goto held86;
            rawValue2 = Anim24PlayerB0View2;
            nextSelector4 = 85;
            if (!rawValue2)
                goto select;
        held86:
            rawValue2 = Anim24Data6E538View3 & 12;
            if (!rawValue2)
                goto angle86;
            rawValue2 = Anim24Player144View3 < 16;
            nextSelector4 = 85;
            if (!rawValue2)
                goto select;
        angle86:
            rawValue2 = Anim24Field(record16, int*, 0x4C);
            nextSelector4 = (int)frame.at10;
            if (!rawValue2)
                goto distance86;
            Anim24SubtractVectorView1((void*)nextSelector4, (void*)(rawValue2 + 12),
                                      Anim24Player0View1);
            rawValue2 = Anim24PlanarHeadingLookupView1(frame.at10[0], frame.at10[1], 1);
            rawValue3 = Anim24PlayerA4View1;
            rawValue2 -= rawValue3;
            rawValue3 = rawValue2 & 4095;
            rawValue2 = rawValue3 < 2049;
            if (!rawValue2)
                rawValue3 -= 4096;
            rawValue2 = rawValue3;
            if (rawValue3 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 256;
            nextSelector4 = 96;
            if (rawValue2)
                goto select;
        distance86:
            rawValue2 = Anim24PlayerB4View1 < 3585;
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24ReadSelectedFrameScalarView1((void*)nextSelector4);
            rawValue2 = rawValue2 < 33;
            nextSelector4 = 92;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80095A38) : "memory");
            goto select;
        case 87:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 85;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim24Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
            rawValue2 = Anim24PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne87;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (rawValue2)
                goto ground87;
        airborne87:
            __asm__ volatile("" ::"i"(0x80095AC0) : "memory");
            nextSelector4 = 89;
            goto select;
        ground87:
            rawValue2 = Anim24PlayerACView2;
            nextSelector4 = 86;
            if (!rawValue2)
                goto select85;
            __asm__ volatile("" ::"i"(0x80095ADC) : "memory");
            goto select;
        case 88:
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 85;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim24Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
            rawValue2 = Anim24Player280View3;
            nextSelector4 = 90;
            if (rawValue2 < 0)
                goto select;
            rawValue2 = Anim24PlayerB8View2;
            nextSelector4 = 89;
            if (!rawValue2)
                goto select85;
            goto select;
        case 89:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerB8View2;
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue2 = Anim24PlayerACView2;
            nextSelector4 = 86;
            if (!rawValue2)
                nextSelector4 = 85;
            Anim24DispatchPlayerStateRequestView3(nextSelector4);
            {
                register int (*spawn2)(int, int, void*, int) __asm__("$2") =
                    Anim24DataSpawnParticleView1;
                if (spawn2)
                    spawn2(8, 33, 0, 2);
            }
            product5 = 2;
            nextSelector4 = (int)Anim24Player250View1;
            Anim24PlayMobySoundEventView1((void*)nextSelector4, product5, 0);
            rawValue2 = Anim24Player58View1 < 24;
            if (rawValue2)
                return;
            rawValue2 = 120;
            Anim24Data6E530View1 = rawValue2;
            rawValue2 = 15;
            Anim24Data6E52CView1 = rawValue2;
            return;
        case 90:
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 85;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim24Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
        call498C0:
            Anim24UpdatePlayerRetryStateView1();
            return;
        case 91:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne91;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (rawValue2)
                goto held91;
        airborne91:
            __asm__ volatile("" ::"i"(0x80095CAC) : "memory");
            nextSelector4 = 89;
            goto select;
        held91:
            rawValue2 = Anim24Data6E538View3 & 128;
            if (rawValue2)
                goto age91;
            rawValue2 = Anim24Player54View3 < 30;
            if (!rawValue2)
                goto input91;
        age91:
            rawValue2 = Anim24Player54View3 < 120;
            if (rawValue2)
                return;
        input91:
            rawValue2 = Anim24Data6E535View2;
            nextSelector4 = 85;
            if (rawValue2)
                goto select;
            nextSelector4 = 86;
            goto select;
        case 92:
            rawValue2 = (int)Anim24Player250View1;
            callback3 = Anim24Data7431CView1;
            record16 = Anim24Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue3 = Anim24Data6E53CView3;
            rawValue2 = rawValue3 & 64;
            nextSelector4 = 93;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerB8View2 < 4;
            nextSelector4 = 89;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = rawValue3 & 32;
            nextSelector4 = 87;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 91;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24Data6E535View2;
            if (!rawValue2)
                goto held92;
            rawValue2 = Anim24PlayerB0View2;
            nextSelector4 = 85;
            if (!rawValue2)
                goto select;
        held92:
            rawValue2 = Anim24Data6E538View3 & 12;
            if (!rawValue2)
                goto angle92;
            rawValue2 = Anim24Player144View3 < 16;
            nextSelector4 = 85;
            if (!rawValue2)
                goto select;
        angle92:
            rawValue2 = Anim24Field(record16, int*, 0x4C);
            nextSelector4 = (int)frame.at10;
            if (!rawValue2)
                goto distance92;
            Anim24SubtractVectorView1((void*)nextSelector4, (void*)(rawValue2 + 12),
                                      Anim24Player0View1);
            rawValue2 = Anim24PlanarHeadingLookupView1(frame.at10[0], frame.at10[1], 1);
            rawValue3 = Anim24PlayerA4View1;
            rawValue2 -= rawValue3;
            rawValue3 = rawValue2 & 4095;
            rawValue2 = rawValue3 < 2049;
            if (!rawValue2)
                rawValue3 -= 4096;
            rawValue2 = rawValue3;
            if (rawValue3 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 256;
            nextSelector4 = 96;
            if (rawValue2)
                goto select;
        distance92:
            rawValue2 = Anim24PlayerB4View1 < 3072;
            if (!rawValue2)
                return;
            rawValue3 = (int)Anim24Player250View1;
            rawValue2 = Anim24Field((void*)rawValue3, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)rawValue3, unsigned char*, 0x3C);
            rawValue2 -= 85;
            nextSelector4 = 86;
            if (rawValue3 != rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80095EAC) : "memory");
            goto select;
        case 93:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24Data6E53CView3 & 32;
            nextSelector4 = 87;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerB8View2;
            if (rawValue2)
                goto finish93;
            rawValue2 = Anim24Player54View3 < 16;
            if (rawValue2)
                goto finish93;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim24PlayerCCView1;
            rawValue2 = Anim24Player8CView1;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim24PlayerD0View1;
            rawValue2 = Anim24Player90View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim24PlayerD4View1;
            rawValue2 = Anim24Player94View1;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim24PlayerACView2;
            nextSelector4 = 86;
            if (!rawValue2)
                goto select85;
            __asm__ volatile("" ::"i"(0x80095FA4) : "memory");
            goto select;
        finish93:
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 85;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim24Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            nextSelector4 = 94;
            if (!rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80095FE0) : "memory");
            goto select;
        case 94:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24Data6E53CView3 & 32;
            nextSelector4 = 87;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24PlayerB8View2;
            if (rawValue2)
                goto finish94;
            rawValue2 = Anim24Player54View3 < 16;
            if (rawValue2)
                goto finish94;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim24PlayerCCView1;
            rawValue2 = Anim24Player8CView1;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim24PlayerD0View1;
            rawValue2 = Anim24Player90View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim24PlayerD4View1;
            rawValue2 = Anim24Player94View1;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim24PlayerACView2;
            nextSelector4 = 86;
            if (!rawValue2)
                goto select85;
            __asm__ volatile("" ::"i"(0x800960D8) : "memory");
            goto select;
        finish94:
            rawValue3 = Anim24Player4CView2;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim24PlayerA0View1 < -6400;
            nextSelector4 = 89;
            if (rawValue2)
                goto select;
            rawValue2 = Anim24Player54View3 < 121;
            if (!rawValue2)
                goto select;
            return;
        case 95:
            rawValue2 = (int)Anim24Player250View1;
            callback3 = Anim24Data7431CView1;
            record16 = Anim24Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne95;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (rawValue2)
                goto input95;
        airborne95:
            __asm__ volatile("" ::"i"(0x80096180) : "memory");
            nextSelector4 = 89;
            goto select;
        input95:
            rawValue2 = Anim24Data6E535View2;
            if (!rawValue2)
                goto held95;
            rawValue2 = Anim24PlayerB0View2;
            nextSelector4 = 97;
            if (!rawValue2)
                goto select;
        held95:
            rawValue2 = Anim24Data6E538View3 & 12;
            if (!rawValue2)
                goto private95;
            rawValue2 = Anim24Player144View3 < 16;
            nextSelector4 = 97;
            if (!rawValue2)
                goto select;
        private95:
            rawValue2 = Anim24Field(record16, int*, 0x58) < 16;
            nextSelector4 = 97;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim24Field(record16, int*, 0x4C);
            nextSelector4 = (int)frame.at10;
            if (!rawValue2)
                return;
            Anim24SubtractVectorView1((void*)nextSelector4, (void*)(rawValue2 + 12),
                                      Anim24Player0View1);
            rawValue2 = Anim24PlanarHeadingLookupView1(frame.at10[0], frame.at10[1], 1);
            rawValue3 = Anim24PlayerA4View1;
            rawValue2 -= rawValue3;
            rawValue3 = rawValue2 & 4095;
            rawValue2 = rawValue3 < 2049;
            if (!rawValue2)
                rawValue3 -= 4096;
            rawValue2 = rawValue3;
            if (rawValue3 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 321;
            nextSelector4 = 97;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80096260) : "memory");
            goto select;
        case 96:
            rawValue2 = (int)Anim24Player250View1;
            callback3 = Anim24Data7431CView1;
            record16 = Anim24Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne96;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (rawValue2)
                goto input96;
        airborne96:
            __asm__ volatile("" ::"i"(0x800962BC) : "memory");
            nextSelector4 = 89;
            goto select;
        input96:
            rawValue2 = Anim24Data6E535View2;
            if (!rawValue2)
                goto held96;
            rawValue2 = Anim24PlayerB0View2;
            nextSelector4 = 97;
            if (!rawValue2)
                goto select;
        held96:
            rawValue2 = Anim24Data6E538View3 & 12;
            if (!rawValue2)
                goto private96;
            rawValue2 = Anim24Player144View3 < 16;
            nextSelector4 = 97;
            if (!rawValue2)
                goto select;
        private96:
            rawValue2 = Anim24Field(record16, int*, 0x58) < 16;
            nextSelector4 = 97;
            if (!rawValue2)
                goto select;
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 85;
            if (rawValue3 != rawValue2)
                goto angle96;
            rawValue2 = Anim24Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            nextSelector4 = 95;
            if (rawValue2)
                goto select;
        angle96:
            rawValue2 = Anim24Field(record16, int*, 0x4C);
            nextSelector4 = (int)frame.at20;
            if (!rawValue2)
                return;
            Anim24SubtractVectorView1((void*)nextSelector4, (void*)(rawValue2 + 12),
                                      Anim24Player0View1);
            rawValue2 = Anim24PlanarHeadingLookupView1(frame.at20[0], frame.at20[1], 1);
            rawValue3 = Anim24PlayerA4View1;
            rawValue2 -= rawValue3;
            rawValue3 = rawValue2 & 4095;
            rawValue2 = rawValue3 < 2049;
            if (!rawValue2)
                rawValue3 -= 4096;
            rawValue2 = rawValue3;
            if (rawValue3 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 321;
            nextSelector4 = 97;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x800963D0) : "memory");
            goto select;
        case 97:
            rawValue2 = Anim24Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim24PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne97;
            rawValue2 = Anim24PlayerE4View2 < 23;
            if (rawValue2)
                goto finish97;
        airborne97:
            __asm__ volatile("" ::"i"(0x80096424) : "memory");
            nextSelector4 = 89;
            goto select;
        finish97:
            nextSelector4 = (int)Anim24Player250View1;
            rawValue2 = Anim24Player48View3;
            rawValue3 = Anim24Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 85;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim24Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
        select85:
            nextSelector4 = 85;
            goto select;
        default:
            return;
    }
select:
    Anim24DispatchPlayerStateRequestView1(nextSelector4);
    return;
}
#undef Anim24Field
