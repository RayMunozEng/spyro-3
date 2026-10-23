#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80091058.
 * Assembly SHA256 d828d3ae3552e63394d7188085cef65c5f8053111cee0c49d0b753a185402648.
 * AI-generated; not human reviewed. All1726 original instructions,
 * 113 selectors bias20 and original owned padding are required.
 * Frame0x138 preserves scratch10..11C,savedS0..S4,slotS2,combinedS3.
 * Fourteen exact groups reuse verified sources; five near groups retain
 * original actual branch joins and field/register producers. New149-row
 * 27/60 retains signed dynamic DIV and original checks, control/angle
 * branches, wrapped scalar/trig additions, vector limits and final94 store.
 * Original26 enters124 after its S0 producer;29 enters121's shared vector
 * call;49 enters130's scalar/vector tails. Original116 owns its vector
 * copy;130 reloads the absolute E8 address. Original121 retains separate
 * absolute F178 arguments and the shared clamp. Callback131 stays after
 * the switch. Every actual target and selector remains original.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions. Frozen C tools emit words.
 * Raw field units/fixed point, helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, actual internal/conditional
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime completeness. */
#define Physics43Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics43RandSignedBetweenView1() __asm__("func_800363DC");
unsigned char Physics43UpdatePlayerGroundInputTargetsView1() __asm__("func_80040D10");
unsigned char Physics43ApproachPlayerTargetHeadingView1() __asm__("func_80041580");
unsigned char Physics43BlendPlayerHeadingFromInputVectorView1() __asm__("func_800416F4");
unsigned char Physics43BuildPlayerResponseVectorView1() __asm__("func_80041B64");
int Physics43InterpolateSineView1() __asm__("func_8004E9E4");
int Physics43InterpolateCosineView1() __asm__("func_8004EA2C");
int Physics43MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics43ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics43ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics43CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics43AddVectorView1() __asm__("func_8004F194");
unsigned char Physics43SubtractVectorView1() __asm__("func_8004F1C8");
extern void* Physics43Data6C570View1 __asm__("D_8006C570");
extern int Physics43Data6C640View1 __asm__("D_8006C640");
extern int Physics43Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics43Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics43Player0View1 __asm__("D_80070328");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics43UpdatePlayerGroundInputTargetsView2() __asm__("func_80040D10");
int Physics43BuildOrientedInputPairView1() __asm__("func_80040F48");
int Physics43ApproachPlayerTargetHeadingView2() __asm__("func_80041580");
int Physics43BlendPlayerHeadingFromInputVectorView2() __asm__("func_800416F4");
int Physics43ApproachPlayerTargetSpeedView1() __asm__("func_800417FC");
int Physics43BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Physics43BuildPlayerResponseVectorView2() __asm__("func_80041B64");
int Physics43InterpolateSineView2() __asm__("func_8004E9E4");
int Physics43InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics43MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics43ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics43ClearVectorView2() __asm__("func_8004F168");
int Physics43CopyVectorView2() __asm__("func_8004F178");
int Physics43AddVectorView2() __asm__("func_8004F194");
int Physics43SubtractVectorView2() __asm__("func_8004F1C8");
extern short Physics43Data6E040View1 __asm__("D_8006E040");
extern int Physics43Data6E044View2 __asm__("D_8006E044");
extern int Physics43Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics43Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics43PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics43Player94View1 __asm__("D_80070328+0x94");
extern int Physics43PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics43Player80View1 __asm__("D_80070328+0x80");
extern int Physics43PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics43Player144View1 __asm__("D_80070328+0x144");
extern int Physics43PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics43Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics43PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics43PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics43Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics43Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics43Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics43Player101View1 __asm__("D_80070328+0x101");
extern int Physics43PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics43BuildOrientedInputPairView2() __asm__("func_80040F48");
int Physics43TestPlayerProbePatternView1() __asm__("func_80043194");
int Physics43PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics43TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics43MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics43ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics43ClearVectorView3() __asm__("func_8004F168");
int Physics43CopyVectorView3() __asm__("func_8004F178");
int Physics43AddVectorView3() __asm__("func_8004F194");
int Physics43SubtractVectorView3() __asm__("func_8004F1C8");
extern int Physics43Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics43Player0View3 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
int Physics43ApproachPlayerTargetSpeedView2() __asm__("func_800417FC");
int Physics43PlanarHeadingLookupView2() __asm__("func_8004E880");
int Physics43InterpolateSineView3() __asm__("func_8004E9E4");
int Physics43InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics43MeasureVectorLengthView4() __asm__("func_8004EDE8");
int Physics43ScaleVectorRatioQ15View4() __asm__("func_8004F08C");
int Physics43ShiftVectorLeftView1() __asm__("func_8004F0E8");
int Physics43CopyVectorView4() __asm__("func_8004F178");
int Physics43AddVectorView4() __asm__("func_8004F194");
int Physics43SubtractVectorView4() __asm__("func_8004F1C8");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics43PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics43PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics43Player148View1 __asm__("D_80070328+0x148");
extern int Physics43Player210View1 __asm__("D_80070328+0x210");
extern int Physics43Player220View1 __asm__("D_80070328+0x220");
extern int Physics43Player98View1 __asm__("D_80070328+0x98");
extern int Physics43PlayerB8View2 __asm__("D_80070328+0xB8");
extern int Physics43PlayerCCView1 __asm__("D_80070328+0xCC");
extern int Physics43PlayerD0View1 __asm__("D_80070328+0xD0");
extern int Physics43PlayerE4View1 __asm__("D_80070328+0xE4");
extern unsigned char Physics43PlayerFCView2 __asm__("D_80070328+0xFC");
int Physics43UpdatePlayerGroundInputTargetsView3() __asm__("func_80040D10");
int Physics43ApproachPlayerTargetHeadingView3() __asm__("func_80041580");
int Physics43ApproachPlayerTargetSpeedView3() __asm__("func_800417FC");
int Physics43BuildPlayerMovementVectorView2() __asm__("func_80041848");
int Physics43BuildPlayerResponseVectorView3() __asm__("func_80041B64");
int Physics43TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics43ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics43ClearVectorView4() __asm__("func_8004F168");
int Physics43CopyVectorView5() __asm__("func_8004F178");
int Physics43AddVectorView5() __asm__("func_8004F194");
int Physics43CallRandView1() __asm__("rand");
extern int Physics43Data6C640View2 __asm__("D_8006C640");
extern int Physics43Data6E044View4 __asm__("D_8006E044");
extern unsigned char Physics43Player0View4 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics43Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics43Player80View2 __asm__("D_80070328+0x80");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics43Player8CView2 __asm__("D_80070328+0x8C");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern int Physics43Player50View1 __asm__("D_80070328+0x50");
extern int Physics43Player250View1 __asm__("D_80070328+0x250");
int Physics43PlanarHeadingLookupView3() __asm__("func_8004E880");
int Physics43SubAngle12View1() __asm__("func_8003615C");
extern int Physics43Player84View1 __asm__("D_80070328+0x84");
extern int Physics43Player88View1 __asm__("D_80070328+0x88");
extern int Physics43PlayerB4View1 __asm__("D_80070328+0xB4");
int Physics43TransformVectorByBasisView3() __asm__("func_8004ED6C");
int Physics43ClearVectorView5() __asm__("func_8004F168");
extern int Physics43PlayerE8View1 __asm__("D_80070328+0xE8");
void func_level_43_80091058(int slotIndex) {
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
            spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC,
            spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C;
    } originalFrame;
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldB8PointerState1A __asm__("$16");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_7;
    int raw34_temp_v0_8;
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
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
    globalPointer = &Physics43Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics43Data6C570View1 = (void*)workWord2;
    workWord2 = Physics43Field(&Physics43Player0View1, int*, 0x54);
    stateWord3 = Physics43Field(&Physics43Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        default:
            return;
        case 20:
        case 53:
        case 54:
            globalVector80 = &Physics43Player0View1 + 0x80;
            Physics43ClearVectorView1(globalVector80);
            Physics43ClearVectorView1(globalVector80 + 0xC);
            if (Physics43Data6E044View1 != 7) {
                Physics43UpdatePlayerGroundInputTargetsView1(0x1200);
                Physics43BlendPlayerHeadingFromInputVectorView1();
                Physics43ApproachPlayerTargetHeadingView1(0x5A, 0x10);
                return;
            }
            return;
        case 29:
            Physics43ClearVectorView2(&originalFrame.sp10);
            call4 = &originalFrame.sp10;
            call5 = call4;
            MATCHING_KEEP2(call4, call5);
            globalVector80 = &Physics43Player0View2 + 0x8C;
            Physics43SubtractVectorView2(call4, call5, globalVector80);
            if (Physics43PlayerB8View1) {
                originalFrame.sp18 = 0;
                call5 = (void*)Physics43MeasureVectorLengthView2(&originalFrame.sp10, 0);
                workWord2 = (int)call5 < 65;
                if (!workWord2)
                    Physics43ScaleVectorRatioQ15View2(&originalFrame.sp10, call5, 64);
                originalFrame.sp18 = -192;
                call4 = globalVector80 - 12;
                call5 = globalVector80;
                call6 = &originalFrame.sp10;
                goto vector29;
            }
            call5 = (void*)Physics43MeasureVectorLengthView2(&originalFrame.sp10, 1);
            workWord2 = (int)call5 < 257;
            if (!workWord2)
                Physics43ScaleVectorRatioQ15View2(&originalFrame.sp10, call5, 256);
            Physics43AddVectorView2(globalVector80, globalVector80, &originalFrame.sp10);
            call4 = globalVector80 - 12;
            call5 = globalVector80;
            call6 = call5 + 0x5C;
            goto vector29;
        case 26:
            globalFieldB8PointerState1A = &Physics43Player0View3 + 0xB8;
            if (Physics43Field(&Physics43Player0View3, int*, 0xB8) != 0) {
                raw34_temp_v0_8 = Physics43Field(&Physics43Player0View3, int*, 0x94) - 0x600;
                Physics43Field(&Physics43Player0View3, int*, 0x94) = raw34_temp_v0_8;
                if (raw34_temp_v0_8 < -0x2300) {
                    Physics43Field(&Physics43Player0View3, int*, 0x94) = -0x2300;
                }
                Physics43CopyVectorView3(globalFieldB8PointerState1A - 0x38,
                                         globalFieldB8PointerState1A - 0x2C);
                return;
            }
            goto block_42;
        case 32:
            globalFieldB8PointerState20 = &Physics43Player0View1 + 0xB8;
            if (Physics43Field(&Physics43Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp20;
                Physics43ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics43SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp28 = 0;
                temp_v0_6 = Physics43MeasureVectorLengthView1(&originalFrame.sp20, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics43ScaleVectorRatioQ15View1(&originalFrame.sp20, temp_v0_6, 0x40);
                }
                originalFrame.sp28 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics43AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp20);
                Physics43CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics43ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics43ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics43Field(&Physics43Player0View1, int*, 0x94) < -0x2300) {
                Physics43Field(&Physics43Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics43Field(&Physics43Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics43Data6C640View1 & 1)) {
                originalFrame.sp30 = 0;
                originalFrame.sp34 = 0;
                originalFrame.sp38 = 0xE;
                Physics43CopyVectorView1(&originalFrame.sp40,
                                         (&Physics43Player0View1 + 0x94) - 0x94);
                originalFrame.sp40 += Physics43RandSignedBetweenView1(0, 0x12C);
                originalFrame.sp44 += Physics43RandSignedBetweenView1(0, 0x12C);
                originalFrame.sp48 += Physics43RandSignedBetweenView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp40, &originalFrame.sp30);
                Physics43Field(temp_v0_7, signed char*, 2) = 6;
                Physics43Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 43:
        case 44:
            globalField4CPointer = &Physics43Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics43Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            Physics43ClearVectorView4(globalField4CPointer + 52);
            Physics43ClearVectorView4(globalField4CPointer + 64);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics43Data6E044View4;
            if (workWord3 == workWord2) {
                Physics43Field(&Physics43Player0View4, int*, 0xB0) = 0;
            } else {
                Physics43UpdatePlayerGroundInputTargetsView3(0x980);
                raw21_var_v0_2 = Physics43ApproachPlayerTargetHeadingView3(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics43Field(&Physics43Player0View4, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics43Field(&Physics43Player0View4, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics43ApproachPlayerTargetSpeedView3(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics43Player0View4 + 0xB0;
            if (Physics43Field(&Physics43Player0View4, int*, 0xB0) != 0) {
                Physics43BuildPlayerMovementVectorView2();
                Physics43BuildPlayerResponseVectorView3();
                Physics43Field(&Physics43Player0View4, int*, 0x94) = 0;
            } else {
                Physics43ClearVectorView4(raw21_temp_s0_11 - 0x30);
                Physics43ClearVectorView4(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics43Player0View4 + 0x28;
                if (Physics43Field(&Physics43Player0View4, int*, 0x28) < 0) {
                    if ((Physics43Field(&Physics43Player0View4, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics43Data6C640View2 & 1)) {
                        Physics43CopyVectorView5(&originalFrame.sp30, raw21_temp_s4 - 0x28);
                        originalFrame.sp54 = 0x40;
                        originalFrame.sp58 = 0;
                        originalFrame.sp50 =
                            (int)Physics43Field(&Physics43Player0View4, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp54 = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics43TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp50,
                                                             &originalFrame.sp60);
                        Physics43AddVectorView5(&originalFrame.sp30, &originalFrame.sp30,
                                                &originalFrame.sp60);
                        originalFrame.sp50 = 0;
                        originalFrame.sp38 = -Physics43Field(&Physics43Player0View4, int*, 0x28);
                        Physics43TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp50,
                                                             &originalFrame.sp50);
                        Physics43ShiftVectorRightTowardZeroView1(&originalFrame.sp50, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp30, &originalFrame.sp50);
                        if (!(Physics43CallRandView1() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp30, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics43Player0View4 + 0xB0;
                        if ((Physics43Field(&Physics43Player0View4, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics43Data6C640View2 & 7) &&
                            !(Physics43CallRandView1() & 3)) {
                            originalFrame.sp70 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp74 = 0;
                            originalFrame.sp78 = 0;
                            Physics43TransformVectorByBasisView2(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp70, &originalFrame.sp70);
                            Physics43AddVectorView5(&originalFrame.sp70, &originalFrame.sp70,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp78 =
                                -Physics43Field(&Physics43Player0View4, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp70, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics43Field(&Physics43Player0View4, int*, 0x144) -
                ((int)((Physics43Field(&Physics43Player0View4, int*, 0x148) * 2) +
                       (Physics43Field(&Physics43Player0View4, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics43Field(&Physics43Player0View4, int*, 0x148) + raw21_temp_a1_4;
            Physics43Field(&Physics43Player0View4, int*, 0x144) = raw21_temp_a1_4;
            Physics43Field(&Physics43Player0View4, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics43Field(&Physics43Player0View4, int*, 0x148) = 0x5900;
            }
            if (Physics43Field(&Physics43Player0View4, int*, 0x148) < -0x5900) {
                Physics43Field(&Physics43Player0View4, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 47: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3 = Physics43Data6E044View3;
            workWord2 = 7;
            if (workWord3 == workWord2)
                goto zero47;
            Physics43BuildOrientedInputPairView2(&originalFrame.sp40, 0);
            workWord2 = originalFrame.sp40;
            numeric6 = originalFrame.sp44;
            originalFrame.sp60 = 0;
            workWord3 = (workWord2 * 9 << 7) >> 7;
            workWord2 = (numeric6 * 3 << 9) >> 7;
            originalFrame.sp40 = workWord3;
            workWord3 = -workWord3;
            originalFrame.sp44 = workWord2;
            originalFrame.sp64 = workWord3;
            originalFrame.sp68 = workWord2;
            workWord2 = Physics43MeasureVectorLengthView3(&originalFrame.sp60, 0, numeric6);
            numeric4 = originalFrame.sp68;
            workWord3 = numeric4;
            if (numeric4 < 0) {
                MATCHING_KEEP(workWord3);
                workWord3 = -workWord3;
            }
            workWord3 = workWord3 < workWord2;
            if (workWord3) {
                workWord2 = originalFrame.sp64;
                originalFrame.sp68 = 0;
                MATCHING_BARRIER_VOLATILE("$4");
                numeric4 = 0;
                if (workWord2 > 0) {
                    __asm__ volatile("" ::"i"(0x800917C8) : "memory");
                    numeric4 = 1;
                }
                if (!Physics43TestPlayerProbePatternView1(numeric4)) {
                    originalFrame.sp64 = 0;
                }
            } else {
                MATCHING_BARRIER_VOLATILE("$3");
                originalFrame.sp64 = 0;
                originalFrame.sp60 = 0;
                if (numeric4 > 0) {
                    __asm__ volatile("" ::"i"(0x800917F0) : "memory");
                    numeric4 = 2;
                } else
                    numeric4 = 3;
                if (!Physics43TestPlayerProbePatternView1(numeric4)) {
                    originalFrame.sp68 = 0;
                }
            }
            call4 = &originalFrame.sp60;
            workWord2 = Physics43MeasureVectorLengthView3(call4, 1);
            Physics43PlayerACView1 = workWord2;
            __asm__ volatile("" ::"i"(0x80091820) : "memory");
            goto clear30;
        zero47:
            Physics43PlayerACView1 = 0;
            goto clear30;
        }
        case 129:
        clear30:
            globalVector80 = &Physics43Player0View3 + 0x80;
            Physics43ClearVectorView3(globalVector80);
            Physics43ClearVectorView3(globalVector80 + 0xC);
            return;
        case 49: {
            register void* pointer17 __asm__("$17");
            register void* pointer18 __asm__("$18");
            register void* pointer16 __asm__("$16");
            int product49a, product49b;
            pointer17 = &Physics43Player210View1;
            workWord2 = Physics43Field(pointer17, int*, 0) & 1024;
            call6 = (void*)1;
            if (!workWord2)
                goto noFlag49;
            MATCHING_KEEP(pointer17);
            call4 = (void*)Physics43Field(pointer17, int*, 12);
            call5 = (void*)Physics43Player220View1;
            __asm__ volatile(""
                             : "=r"(pointer17)
                             : "0"(pointer17), "r"(call4), "r"(call5)
                             : "memory");
            pointer17 += 12;
            workWord2 = Physics43PlanarHeadingLookupView2(call4, call5, call6);
            pointer16 = &originalFrame.sp80;
            call4 = pointer16;
            Physics43Player148View1 = workWord2;
            Physics43CopyVectorView4(call4, pointer17);
            Physics43ShiftVectorLeftView1(pointer16, 6);
            workWord2 = Physics43MeasureVectorLengthView4(pointer16, 1);
            Physics43PlayerB0View2 = workWord2;
            call4 = (void*)128;
            goto prepare49;
        noFlag49:
            MATCHING_KEEP(call6);
            workWord2 = Physics43PlayerE4View1;
            workWord2 = workWord2 < 11;
            if (workWord2)
                goto lowMode49;
            call4 = (void*)Physics43PlayerCCView1;
            call5 = (void*)Physics43PlayerD0View1;
            __asm__ volatile("" ::"i"(0x800918E8) : "memory");
            call6 = (void*)1;
            goto query49;
        lowMode49:
            call4 = (void*)Physics43Player98View1;
            call5 = call4;
        query49:
            workWord2 = Physics43PlanarHeadingLookupView2(call4, call5, call6);
            Physics43Player148View1 = workWord2;
            call4 = (void*)128;
        prepare49:
            call5 = (void*)192;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            pointer18 = &Physics43PlayerACView2;
            workWord2 = 3840;
            Physics43Field(pointer18, int*, 0) = workWord2;
            Physics43ApproachPlayerTargetSpeedView2(call4, call5);
            call4 = (void*)Physics43Player148View1;
            pointer17 = pointer18 - 44;
            workWord2 = Physics43InterpolateCosineView3(call4);
            workWord3 = Physics43PlayerB0View2;
            product49a = workWord3 * workWord2;
            call4 = (void*)Physics43Player148View1;
            workWord2 = product49a >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp80 = workWord2;
            workWord2 = Physics43InterpolateSineView3(call4);
            workWord3 = Physics43PlayerB0View2;
            product49b = workWord3 * workWord2;
            pointer16 = &originalFrame.sp80;
            call4 = pointer16;
            call5 = pointer16;
            call6 = pointer17;
            originalFrame.sp88 = 0;
            workWord2 = product49b >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp84 = workWord2;
            Physics43SubtractVectorView4(call4, call5, call6);
            originalFrame.sp88 = 0;
            call5 = (void*)Physics43MeasureVectorLengthView4(pointer16, 0);
            workWord2 = (int)call5 < 257;
            call4 = pointer17;
            if (!workWord2) {
                Physics43ScaleVectorRatioQ15View4(pointer16, call5, 256);
                call4 = pointer17;
            }
            call5 = pointer17;
            Physics43AddVectorView4(call4, call5, pointer16);
            workWord2 = Physics43PlayerFCView2;
            if (workWord2)
                goto scalar130;
            workWord2 = Physics43PlayerB8View2;
            call4 = pointer18 - 32;
            if (!workWord2)
                goto vector49;
            goto scalar130;
        vector49:
            call5 = pointer17;
            goto vector130Call;
        }
        case 50:
        case 51:
        case 52: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics43BuildOrientedInputPairView2(&originalFrame.sp90, 0);
            workWord2 = originalFrame.sp90;
            numeric6 = originalFrame.sp94;
            originalFrame.sp98 = 0;
            workWord3 = (workWord2 * 9 << 7) >> 7;
            workWord2 = (numeric6 * 3 << 9) >> 7;
            originalFrame.sp90 = workWord3;
            workWord3 = -workWord3;
            originalFrame.sp94 = workWord2;
            originalFrame.sp9C = workWord3;
            originalFrame.spA0 = workWord2;
            workWord2 = Physics43MeasureVectorLengthView3(&originalFrame.sp98, 0, numeric6);
            numeric4 = originalFrame.spA0;
            workWord3 = numeric4;
            if (numeric4 < 0) {
                MATCHING_KEEP(workWord3);
                workWord3 = -workWord3;
            }
            workWord3 = workWord3 < workWord2;
            if (workWord3) {
                workWord2 = originalFrame.sp9C;
                originalFrame.spA0 = 0;
                MATCHING_BARRIER_VOLATILE("$4");
                numeric4 = 0;
                if (workWord2 > 0) {
                    __asm__ volatile("" ::"i"(0x80091A8C) : "memory");
                    numeric4 = 1;
                }
                if (!Physics43TestPlayerProbePatternView1(numeric4)) {
                    originalFrame.sp9C = 0;
                }
            } else {
                MATCHING_BARRIER_VOLATILE("$3");
                originalFrame.sp9C = 0;
                originalFrame.sp98 = 0;
                if (numeric4 > 0) {
                    __asm__ volatile("" ::"i"(0x80091AB4) : "memory");
                    numeric4 = 2;
                } else
                    numeric4 = 3;
                if (!Physics43TestPlayerProbePatternView1(numeric4)) {
                    originalFrame.spA0 = 0;
                }
            }
            vectorAt30 = &originalFrame.sp98;
            workWord2 = Physics43MeasureVectorLengthView3(vectorAt30, 1);
            numeric6 = 1;
            MATCHING_KEEP(numeric6);
            numeric4 = originalFrame.sp90;
            numeric5 = originalFrame.sp94;
            globalVector80 = &Physics43PlayerACView1;
            Physics43Field(globalVector80, int*, 0) = workWord2;
            workWord2 = Physics43PlanarHeadingLookupView1(numeric4, numeric5, numeric6);
            workWord3 = workWord2;
            workWord2 = workWord3 < 2049;
            Physics43PlayerA4View1 = workWord3;
            call4 = globalVector80 - 124;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics43PlayerA4View1 = workWord2;
            }
            call5 = vectorAt30;
            workWord2 = originalFrame.sp98;
            call6 = vectorAt30;
            workWord2 += 1024;
            originalFrame.sp98 = workWord2;
            Physics43TransformVectorByBasisView1(call4, call5, call6);
            call4 = vectorAt30;
            call5 = vectorAt30;
            __asm__("" : "=r"(globalVector80) : "0"(globalVector80), "r"(call4), "r"(call5));
            globalVector8CState20 = globalVector80 - 32;
            Physics43SubtractVectorView3(call4, call5, globalVector8CState20);
            call5 = (void*)Physics43MeasureVectorLengthView3(vectorAt30, 0);
            workWord2 = (int)call5 < 385;
            if (!workWord2)
                Physics43ScaleVectorRatioQ15View3(vectorAt30, call5, 384);
            globalVector80 -= 44;
            Physics43AddVectorView3(globalVector80, globalVector8CState20, vectorAt30);
            Physics43CopyVectorView3(globalVector8CState20, globalVector80);
            return;
        }
        case 27:
        case 60: {
            register void* pointer16 __asm__("$16");
            register int limit17 __asm__("$17");
            register int divisor18 __asm__("$18");
            register void* controls19 __asm__("$19");
            register void* vector18 __asm__("$18");
            int product27A, product27B;
            Physics43UpdatePlayerGroundInputTargetsView2(4608);
            pointer16 = &Physics43PlayerACView1;
            workWord2 = Physics43Field(pointer16, int*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            divisor18 = 4608;
            MATCHING_KEEP(divisor18);
            workWord2 <<= 5;
            limit17 = workWord2 / divisor18;
            Physics43ClearVectorView2(pointer16 - 44);
            controls19 = &Physics43Data6E538View1;
            workWord2 = Physics43Field(controls19, int*, 0) & 12;
            limit17 += 32;
            if (!workWord2)
                goto angle27;
            MATCHING_KEEP(limit17);
            Physics43ApproachPlayerTargetHeadingView2(25, 5);
            workWord2 = Physics43PlayerB4View1;
            workWord3 = Physics43Field(pointer16, int*, 0);
            workWord2 = workWord2 < 2048;
            Physics43PlayerB0View1 = workWord3;
            if (workWord2) {
                workWord2 = limit17 * 2;
                limit17 += workWord2;
            }
            workWord3 = Physics43Field(controls19, int*, 0);
            workWord2 = workWord3 & 8;
            if (workWord2)
                Physics43Player84View1 = -4608;
            else {
                workWord2 = workWord3 & 4;
                if (workWord2)
                    Physics43Player84View1 = divisor18;
            }
            call4 = &Physics43Player0View2 + 48;
            call5 = call4 + 80;
            Physics43TransformVectorByBasisView3(call4, call5, call5);
            goto common27;
        angle27:
            MATCHING_KEEP(limit17);
            workWord2 = Physics43SubAngle12View1(Physics43Data6E040View1, Physics43PlayerA4View1);
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 1800;
            call4 = (void*)25;
            if (workWord2) {
                Physics43ApproachPlayerTargetHeadingView2(call4, 5);
                workWord2 = Physics43Field(pointer16, int*, 0);
                Physics43PlayerB0View1 = workWord2;
            }
        common27:
            pointer16 = &Physics43PlayerA4View1;
            workWord2 = Physics43InterpolateCosineView2(Physics43Field(pointer16, int*, 0));
            workWord3 = Physics43PlayerACView1;
            product27A = workWord3 * workWord2;
            call4 = (void*)Physics43Field(pointer16, int*, 0);
            workWord2 = Physics43Player80View1;
            workWord3 = product27A >> 12;
            workWord2 += workWord3;
            Physics43Player80View1 = workWord2;
            workWord2 = Physics43InterpolateSineView2(call4);
            workWord3 = Physics43PlayerACView1;
            product27B = workWord3 * workWord2;
            call4 = pointer16 - 12;
            Physics43Player88View1 = 0;
            workWord2 = Physics43Player84View1;
            workWord3 = product27B >> 12;
            workWord2 += workWord3;
            Physics43Player84View1 = workWord2;
            workWord2 = Physics43MeasureVectorLengthView2(call4, 0);
            workWord2 = workWord2 < 256;
            pointer16 -= 24;
            if (!workWord2)
                goto vector27;
            workWord2 = Physics43MeasureVectorLengthView2(pointer16, 0);
            workWord2 = workWord2 < 2049;
            if (!workWord2)
                Physics43ClearVectorView2(pointer16);
        vector27:
            pointer16 = &originalFrame.spA8;
            call4 = pointer16;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = &Physics43Player80View1;
            vector18 = call5 + 12;
            Physics43SubtractVectorView2(call4, call5, vector18);
            originalFrame.spB0 = 0;
            workWord2 = Physics43MeasureVectorLengthView2(pointer16, 0);
            call5 = (void*)workWord2;
            workWord2 = limit17 < (int)call5;
            call4 = pointer16;
            if (workWord2)
                Physics43ScaleVectorRatioQ15View2(call4, call5, limit17);
            call4 = vector18;
            call5 = call4;
            Physics43AddVectorView2(call4, call5, pointer16);
            Physics43Player94View1 = -3072;
            return;
        }
        case 128:
            globalVector80 = &Physics43Player0View2 + 0xB8;
            workWord2 = Physics43Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero128;
            vectorAt30 = &originalFrame.spB8;
            Physics43ClearVectorView2(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics43SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.spC0 = 0;
            call5 = (void*)Physics43MeasureVectorLengthView2(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics43ScaleVectorRatioQ15View2(vectorAt30, call5, 64);
            originalFrame.spC0 = -192;
            globalVector80 -= 56;
            Physics43AddVectorView2(globalVector80, globalVector8CState20, vectorAt30);
            Physics43CopyVectorView2(globalVector8CState20, globalVector80);
            goto clamp128;
        zero128:
            Physics43ClearVectorView2(globalVector80 - 56);
            Physics43ClearVectorView2(globalVector80 - 44);
            goto clamp128;
        clamp128:
            globalPointer = &Physics43Player94View1;
            workWord2 = Physics43Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
                Physics43Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        case 115:
        case 120:
        case 126:
            globalVector80 = &Physics43Player80View1;
            Physics43ClearVectorView2(globalVector80);
            Physics43ClearVectorView2(globalVector80 + 12);
            workWord3 = Physics43Data6E044View2;
            workWord2 = 40;
            if (workWord3 != workWord2)
                goto ordinary115;
            Physics44Slot4454();
            goto bytes115;
        ordinary115:
            workWord2 = 31;
            if (workWord3 == workWord2)
                goto bytes115;
            Physics43UpdatePlayerGroundInputTargetsView2(3840);
            Physics43BlendPlayerHeadingFromInputVectorView2();
            Physics43ApproachPlayerTargetHeadingView2(90, 16);
        bytes115:
            globalPointer = &Physics43Player1BAView1;
            workWord2 = Physics43Field(globalPointer, unsigned char*, 0);
            if (!workWord2)
                goto byteOne115;
            workWord2 = Physics43Data6E538View1 & 16;
            if (workWord2)
                return;
            workWord2 = 1;
            Physics43Field(globalPointer, unsigned char*, 0) = 0;
            Physics43Player1B9View1 = workWord2;
            return;
        byteOne115:
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics43Player1B9View1 = workWord2;
            return;
        case 116:
        case 117: {
            register void* mode16 __asm__("$16");
            register int mode17 __asm__("$17");
            register int callback18 __asm__("$18");
            mode16 = &Physics43Data6E044View2;
            workWord3 = Physics43Field(mode16, int*, 0);
            mode17 = 40;
            if (workWord3 == mode17)
                goto callback131;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics43UpdatePlayerGroundInputTargetsView2(3840);
            workWord2 = Physics43Data6E538View1 & 12;
            if (workWord2)
                Physics43PlayerACView1 = 0;
            workWord2 = Physics43BlendPlayerHeadingFromInputVectorView2();
            workWord3 = Physics43Field(mode16, int*, 0);
            callback18 = workWord2;
            if (workWord3 == mode17) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else {
                call4 = (void*)90;
                call5 = (void*)16;
            }
            workWord2 = Physics43ApproachPlayerTargetHeadingView2(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics43PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics43Data6E538View1 & 12;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics43Player144View1;
            workWord2++;
            Physics43Player144View1 = workWord2;
            goto saved116;
        reset116:
            Physics43Player144View1 = 0;
        saved116:
            call4 = &Physics43PlayerACView1;
            globalVector80 = (void*)Physics43Field(call4, int*, 0);
            if (callback18)
                goto collision116;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass116;
        collision116:
            workWord2 = Physics43Player20CView1 & 64;
            if (workWord2)
                Physics43Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics43PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics43Field(call4, int*, 0) = workWord3;
            }
        pass116:
            Physics43ApproachPlayerTargetSpeedView1(320, 192);
            workWord2 = Physics43Player101View1;
            call4 = &Physics43PlayerACView1;
            Physics43Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics43ClearVectorView2(call4 - 32);
                goto fields116;
            }
            Physics43BuildPlayerMovementVectorView1(call4);
            Physics43BuildPlayerResponseVectorView2();
        fields116:
            call6 = &Physics43PlayerFCView1;
            workWord2 = Physics43Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics43PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto scalar130;
            call5 = call4;
            Physics43AddVectorView2(call4, call5, call6 - 20);
            return;
        }
        case 118:
            Physics43UpdatePlayerGroundInputTargetsView2(3200);
            workWord3 = Physics43Data6E044View2;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics43ApproachPlayerTargetHeadingView2(call4, call5);
            Physics43ApproachPlayerTargetSpeedView1(320, 192);
            globalFieldA4Pointer = &Physics43PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics43InterpolateCosineView1(Physics43Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics43PlayerB0View1;
            agentProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics43Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spC8 = workWord2;
            workWord2 = Physics43InterpolateSineView1(call4);
            workWord3 = Physics43PlayerB0View1;
            agentProduct1 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spC8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spCC = workWord2;
            Physics43SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.spD0 = 0;
        vector118Read:
            __asm__ volatile("" ::"i"(0x800921F4) : "memory");
            workWord2 = Physics43MeasureVectorLengthView1(call4, call5);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            call5 = (void*)workWord2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            workWord2 = (int)call5 < 641;
            MATCHING_KEEP(globalFieldA4Pointer);
            call4 = globalFieldA4Pointer - 36;
            if (!workWord2) {
                Physics43ScaleVectorRatioQ15View1(vectorAt40, call5, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                call4 = globalFieldA4Pointer - 36;
            }
            Physics43AddVectorView1(call4, globalVector8C, vectorAt40);
            Physics43BuildPlayerResponseVectorView1();
        gate118:
            __asm__ volatile("" ::"i"(0x80092230) : "memory");
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics43Player4CView1;
            __asm__ volatile("" ::"i"(0x80092248) : "memory");
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics43Data6C570View1;
            workWord2 = Physics43Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics43Player144View1;
            __asm__ volatile("" ::"i"(0x8009227C) : "memory");
            if (!workWord2)
                goto subtract192_130;
            __asm__ volatile("" ::"i"(0x80092284) : "memory");
            goto add23_130;
        case 119:
            globalFieldA4Pointer = &Physics43Player50View1;
            workWord3 = Physics43Field(globalFieldA4Pointer, int*, 0);
            workWord2 = 3;
            if (workWord3 != workWord2)
                goto airborne119;
            Physics43UpdatePlayerGroundInputTargetsView2(1600);
            Physics43ApproachPlayerTargetHeadingView2(22, 4);
            Physics43ApproachPlayerTargetSpeedView1(320, 192);
            globalVector8C = globalFieldA4Pointer + 60;
            workWord2 = Physics43InterpolateCosineView1(Physics43PlayerA4View1);
            workWord3 = Physics43PlayerB0View1;
            agentProduct2 = workWord3 * workWord2;
            call4 = (void*)Physics43PlayerA4View1;
            workWord2 = agentProduct2 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spD8 = workWord2;
            workWord2 = Physics43InterpolateSineView1(call4);
            workWord3 = Physics43PlayerB0View1;
            agentProduct3 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spD8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spDC = workWord2;
            Physics43SubtractVectorView1(call4, call5, call6);
            originalFrame.spE0 = 0;
            temp_v0_4 = Physics43MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 48;
            if (temp_v0_4 >= 321) {
                Physics43ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 320);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 48;
            }
            Physics43AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics43BuildPlayerResponseVectorView1();
            workWord2 = Physics43Player94View1;
            workWord2 -= 192;
            Physics43Player94View1 = workWord2;
            workWord2 = workWord2 < -8960;
            goto clamp119;
        airborne119:
            Physics43UpdatePlayerGroundInputTargetsView2(3200);
            workWord3 = Physics43Data6E044View2;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics43ApproachPlayerTargetHeadingView2(call4, call5);
            Physics43ApproachPlayerTargetSpeedView1(320, 192);
            globalFieldA4Pointer = &Physics43PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics43InterpolateCosineView1(Physics43Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics43PlayerB0View1;
            agentProduct4 = workWord3 * workWord2;
            call4 = (void*)Physics43Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spD8 = workWord2;
            workWord2 = Physics43InterpolateSineView1(call4);
            workWord3 = Physics43PlayerB0View1;
            agentProduct5 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spD8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct5 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spDC = workWord2;
            Physics43SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.spE0 = 0;
            goto vector118Read;
        case 121:
            vectorAt40 = &originalFrame.spE8;
            Physics43ClearVectorView2(vectorAt40);
            call4 = vectorAt40;
            call5 = call4;
            Physics43SubtractVectorView2(call4, call5, &Physics43Player8CView2);
            workWord2 = Physics43PlayerB8View1;
            call4 = vectorAt40;
            if (!workWord2)
                goto detached121;
            originalFrame.spF0 = 0;
            workWord2 = Physics43MeasureVectorLengthView2(call4, 0);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 9;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)8;
            goto limit121;
        detached121:
            workWord2 = Physics43MeasureVectorLengthView2(call4, 1);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 65;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)64;
        limit121:
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(call4, call5, call6, "memory");
            Physics43ScaleVectorRatioQ15View2(call4, call5, call6);
        vectors121:
            globalVector80 = &Physics43Player80View1;
            call4 = globalVector80;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            MATCHING_KEEP(globalVector80);
            globalFieldA4Pointer = globalVector80 + 12;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(globalFieldA4Pointer, "memory");
            call5 = globalFieldA4Pointer;
            call6 = &originalFrame.spE8;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call5, call6, "memory");
            workWord2 = -192;
            originalFrame.spF0 = workWord2;
            MATCHING_BARRIER_VOLATILE("memory");
        vector29:
            __asm__ volatile("" ::"i"(0x800924E4) : "memory");
            Physics43AddVectorView2(call4, call5, call6);
            call4 = &Physics43Player8CView2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = &Physics43Player80View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            Physics43CopyVectorView2(call4, call5);
            workWord2 = Physics43Player94View1;
            workWord2 = workWord2 < -8960;
        clamp19:
        clamp119:
            if (workWord2) {
                workWord2 = -8960;
                Physics43Player94View1 = workWord2;
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
            call4 = &originalFrame.spF8;
            workWord2 = Physics43Player250View1;
            child18 = Physics43Field((void*)workWord2, void**, 0);
            Physics43BuildOrientedInputPairView1(call4, 0);
            input16 = &Physics43Data6E040View1;
            workWord2 = Physics43InterpolateCosineView2(Physics43Field(input16, short*, 0));
            position19 = child18 + 100;
            trig17 = workWord2;
            workWord2 = Physics43InterpolateSineView2(Physics43Field(input16, short*, 0));
            workWord3 = originalFrame.spFC;
            numeric5 = workWord3 * trig17;
            workWord3 = originalFrame.spF8;
            workWord3 *= workWord2;
            call4 = (void*)Physics43Field(input16, short*, 0);
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.sp100 = workWord2;
            workWord2 = Physics43InterpolateCosineView2(call4);
            call4 = (void*)Physics43Field(input16, short*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            secondTrig16 = workWord2;
            workWord2 = Physics43InterpolateSineView2(call4);
            workWord3 = originalFrame.spF8;
            workWord3 = -workWord3;
            numeric5 = workWord3 * secondTrig16;
            workWord3 = originalFrame.spFC;
            workWord3 *= workWord2;
            vector17 = &originalFrame.sp100;
            call4 = vector17;
            player20 = &Physics43Player0View2;
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.sp104 = workWord2;
            workWord2 = Physics43Field(child18, int*, 100);
            workWord3 = originalFrame.sp100;
            call6 = player20;
            workWord2 += workWord3;
            Physics43Field(child18, int*, 100) = workWord2;
            workWord2 = Physics43Field(child18, int*, 104);
            workWord3 = originalFrame.sp104;
            call5 = position19;
            workWord2 += workWord3;
            Physics43Field(child18, int*, 104) = workWord2;
            Physics43SubtractVectorView2(call4, call5, call6);
            originalFrame.sp108 = 0;
            workWord2 = Physics43MeasureVectorLengthView2(vector17, 0);
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
            Physics43ScaleVectorRatioQ15View2(call4, call5, call6);
            Physics43AddVectorView2(position19, player20, vector17);
        selector122:
            call4 = (void*)originalFrame.sp100;
            call5 = (void*)originalFrame.sp104;
            workWord2 = Physics43PlanarHeadingLookupView3(call4, call5, 1);
            workWord3 = Physics43Data6E044View2;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            Physics43PlayerA4View1 = workWord2;
            workWord2 = 40;
            call4 = (void*)24;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)4;
            Physics43ApproachPlayerTargetHeadingView2(call4, call5);
            workWord2 = length16 < 6145;
            if (workWord2)
                goto below122;
            boundedScalar122 = (length16 - 6144) / 56 + 384;
            goto store122;
        below122:
            boundedScalar122 = 384 - ((6144 - length16) / 40);
        store122:
            MATCHING_OBSERVE_VOLATILE_CLOBBER(length16, "memory");
            Physics43Field(child18, int*, 92) = boundedScalar122;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = Physics43Field(child18, int*, 92);
            workWord2 = workWord2 < 256;
            if (workWord2)
                Physics43Field(child18, int*, 92) = 256;
            workWord2 = Physics43Field(child18, int*, 92);
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics43Field(child18, int*, 92) = 512;
            call4 = (void*)Physics43Player250View1;
            Physics44Slot432C(call4);
            return;
        }
        case 124:
            globalVector80 = &Physics43Player80View1;
            MATCHING_KEEP_VOLATILE(globalVector80);
        block_42:
            call4 = &Physics43Player80View2;
            MATCHING_KEEP(call4);
            Physics43ClearVectorView5(call4);
            call4 = &Physics43Player8CView1;
            MATCHING_KEEP(call4);
            Physics43ClearVectorView5(call4);
            return;
        case 130: {
            register int callback17 __asm__("$17");
            globalVector80 = &Physics43Player50View1;
            workWord3 = Physics43Field(globalVector80, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto airborne130;
            workWord2 = 8;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            globalVector80 = &Physics43Data6E044View2;
            MATCHING_KEEP(globalVector80);
            workWord3 = Physics43Field(globalVector80, int*, 0);
            if (workWord3 != workWord2)
                Physics43UpdatePlayerGroundInputTargetsView2(3840);
            workWord2 = Physics43Data6E538View1 & 12;
            if (workWord2)
                Physics43PlayerACView1 = 0;
            workWord2 = Physics43BlendPlayerHeadingFromInputVectorView2();
            callback17 = workWord2;
            workWord3 = Physics43Field(globalVector80, int*, 0);
            workWord2 = 40;
            call4 = (void*)90;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)16;
            workWord2 = Physics43ApproachPlayerTargetHeadingView2(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics43PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics43Data6E538View1 & 12;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics43Player144View1;
            workWord2++;
            Physics43Player144View1 = workWord2;
            goto saved130;
        reset130:
            Physics43Player144View1 = 0;
        saved130:
            call4 = &Physics43PlayerACView1;
            globalVector80 = (void*)Physics43Field(call4, int*, 0);
            if (callback17)
                goto collision130;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass130;
        collision130:
            workWord2 = Physics43Player20CView1 & 64;
            if (workWord2)
                Physics43Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics43PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics43Field(call4, int*, 0) = workWord3;
            }
        pass130:
            Physics43ApproachPlayerTargetSpeedView1(320, 192);
            workWord2 = Physics43Player101View1;
            call4 = &Physics43PlayerACView1;
            Physics43Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics43ClearVectorView2(call4 - 32);
                goto fields130;
            }
            Physics43BuildPlayerMovementVectorView1(call4);
            Physics43BuildPlayerResponseVectorView2();
        fields130:
            call6 = &Physics43PlayerFCView1;
            workWord2 = Physics43Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics43PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector130Input;
        scalar130:
            workWord2 = Physics43PlayerA0View1;
            workWord2 -= 192;
            Physics43Player94View1 = workWord2;
            return;
        vector130Input:
            __asm__ volatile("" ::"i"(0x80092980) : "memory");
            call5 = call4;
        vector130Call:
            call6 = &Physics43PlayerE8View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call6, "memory");
            Physics43AddVectorView2(call4, call5, call6);
            return;
        airborne130:
            Physics43UpdatePlayerGroundInputTargetsView2(3200);
            workWord3 = Physics43Data6E044View2;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics43ApproachPlayerTargetHeadingView2(call4, call5);
            Physics43ApproachPlayerTargetSpeedView1(320, 192);
            globalFieldA4Pointer = &Physics43PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics43InterpolateCosineView1(Physics43Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics43PlayerB0View1;
            agentProduct6 = workWord3 * workWord2;
            call4 = (void*)Physics43Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct6 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp110 = workWord2;
            workWord2 = Physics43InterpolateSineView1(call4);
            workWord3 = Physics43PlayerB0View1;
            agentProduct7 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.sp110;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct7 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp114 = workWord2;
            Physics43SubtractVectorView1(call4, call5, call6);
            originalFrame.sp118 = 0;
            temp_v0_4 = Physics43MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 36;
            if (temp_v0_4 >= 641) {
                Physics43ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 36;
            }
            Physics43AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics43BuildPlayerResponseVectorView1();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics43Player4CView1;
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics43Data6C570View1;
            workWord2 = Physics43Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics43Player144View1;
            if (!workWord2)
                goto subtract192_130;
        add23_130:
            workWord2 = Physics43Player94View1;
            workWord2 += 23;
            Physics43Player94View1 = workWord2;
            return;
        subtract192_130:
            globalPointer = &Physics43Player94View1;
            workWord2 = Physics43Field(globalPointer, int*, 0);
            workWord2 -= 192;
            Physics43Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 131:
        case 132:
            goto callback131;
    }
    return;
callback131:
    __asm__ volatile("" ::"i"(0x80092B18) : "memory");
    Physics44Slot4454();
    return;
}
#undef Physics43Field


int Callback43First42A44(void) __asm__("func_80042A44");
/* AI generated; not human reviewed. SCUS-94467 80092B50..800930D0.
 * Baseline: verified level50_8009CF04 scalar state producers. Original43
 * supplies dispatch, helper/flag/clamp tails and signed division by1536.
 * Numeric pointer addition0x70 is a byte offset from player+0x28.
 * Empty constraints retain register lifetimes, including the otherwise unused
 * V0 result after case1A's call; no helper-return meaning is established.
 * Units, producer chains, invocation cadence and runtime parity remain open.
 * Acceptance: every original code/table word and every complete retail hash.
 */
extern int Callback43Step __asm__("D_80070328+0x144");
extern int Callback43Z __asm__("D_80070328+8");
extern int Callback43Limit __asm__("D_80070328+0x280");
extern Spyro Callback43Player __asm__("D_80070328");
int Callback43SamplePlanarPhaseTable(int x, int y) __asm__("func_80037058");
int Callback43SoundHandleMatchesIdInStates1Or2(int soundId, int index) __asm__("func_8003BF6C");
void Callback43ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback43CapturePlayerPlanarVectorDifference(void) __asm__("func_80041AE8");
void Callback43UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback43UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
void Callback43BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
extern int Callback43Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38, D_8006C648;
int Callback43Query(Vector3D*, int) __asm__("func_8001A358");
int Callback43Length(Vector3D*, int) __asm__("func_8004EDE8");
void func_level_43_80092B50(void) {
    struct {
        Vector3D first;
        int reserved1C;
    } local;
    register int computedValue __asm__("$4");

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback43Player.animationState) {
        case 0x14:
        case 0x73:
        case 0x78:
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7E:
            if (func_800438F4() == 0) {
                func_80043728();
            }
            Callback43UpdatePlayerCollisionResponse();
            Callback43Player.unk9a = 0;
            Callback43First42A44();
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearSharedValue;
        default:
            return;
        case 0x1B:
        case 0x20:
        case 0x35:
        case 0x36:
        case 0x3C:
        case 0x80:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            goto clearSharedValue;
        case 0x1D:
        case 0x79:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            goto queryC00;
        case 0x1A:
            Callback43UpdatePlayerCollisionResponse();
            {
                register int helperResult __asm__("$2") = Callback43First42A44();
                MATCHING_OBSERVE_VOLATILE(helperResult);
            }
            goto queryC00;
        case 0x81: {
            register int* zWord __asm__("$5") = &Callback43Z;
            register int velocity __asm__("$6") = Callback43Step;
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
            status = Callback43Limit;
            velocity += tick;
            Callback43Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback43Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback43Step = 0x2580;
            }
        limitsDone:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            func_8004F178(&local.first, &Callback43Player.position);
            local.first.z += 0x400;
            Callback43Player.unk4[0] = Callback43Query(&local.first, 0xC00);
            positionDelta = (int)Callback43Player.union144.a.unk13cb;
            positionValue = Callback43Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
        case 0x2B:
        case 0x2C:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43CapturePlayerPlanarVectorDifference();
            if ((unsigned char)Callback43Player.unk10[4] != 0) {
                computedValue = -Callback43Player.unk9ha[4] -
                                Callback43SamplePlanarPhaseTable(Callback43Player.position.x,
                                                                 Callback43Player.position.y);
                positionValue = Callback43Player.unk4a - computedValue;
                Callback43Player.unk4[0] = computedValue;
                positionDelta = (int)Callback43Player.union144.a.unk13cc >> 6;
                goto storePosition;
            }
            break;
        storePosition:
            positionValue -= positionDelta;
            MATCHING_KEEP(positionValue);
            Callback43Player.position.z = positionValue;
            return;
        case 0x2F:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43ProbePlayerContactSegment();
            func_80042F64();
            goto clearSharedValue;
        case 0x31:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43BuildNegatedNormalizedPlayerVector(0xC00);
            if (func_80040954(Callback43Player.unk11[2]) == 0xA) {
                Callback43Player.union144.a.unk13cb = 0;
            } else {
                Callback43Player.union144.a.unk13cb += D_8006C648;
            }
            Callback43Player.unk4[0] = 0;
            if (Callback43SoundHandleMatchesIdInStates1Or2((int)D_8006C654->unk32,
                                                           Callback43Player.unk22[2]) == 0) {
                Callback43Player.unk22[2] = PlaySound((int)D_8006C654->unk32, 0, 4);
                Callback43Player.unk22[3] = (int)D_8006C654->unk32;
                return;
            }
            break;
        case 0x32:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43ProbePlayerContactSegment();
            func_80042F64();
            numerator = (int)((unsigned int)Callback43Player.unk7a[3].z << 2);
            Callback43Player.unk4[0] = 0;
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
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43ProbePlayerContactSegment();
            func_80042F64();
            Callback43Player.unk4[0] = 0;
            {
                register int quotient __asm__("$3") =
                    (int)(((unsigned int)Callback43Length(
                               (Vector3D*)((unsigned char*)Callback43Player.unk4 + 0x70), 0)
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
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43ProbePlayerContactSegment();
            if (Callback43Player.unk5 != 0x7F) {
                if ((Callback43Player.unk7a[3].z < 0) &&
                    (Callback43Player.animationStateFrames >= 4)) {
                    Callback43Player.unk5 = 1;
                } else {
                    goto checkSecondFlag;
                }
            }
            goto clearSharedValue;
        case 0x82:
            if (Callback43Player.movementState != MOVEMENT_STATE_WALK)
                goto other82;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43ProbePlayerContactSegment();
        queryC00:
            Callback43BuildNegatedNormalizedPlayerVector(0xC00);
            goto clearSharedValue;
        other82:
            Callback43UpdatePlayerCollisionResponse();
            Callback43UpdatePlayerSurfaceState();
            Callback43ProbePlayerContactSegment();
            if ((Callback43Player.unk7a[3].z < 0) && (Callback43Player.animationStateFrames >= 4)) {
                Callback43Player.unk5 = 1;
            } else {
            checkSecondFlag:
                if ((Callback43Player.unk5 == 0) && !(Callback43Word8006E538 & 0x40) &&
                    (Callback43Player.union144.a.unk13cb == 0)) {
                    Callback43Player.unk5 = 2;
                }
            }
        clearSharedValue:
            Callback43Player.unk4[0] = 0;
            return;
    }
}


#define LEVEL_ID 43
#define PlaySpyroSounds_level_43 func_level_43_800930D4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_43_80093310(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x76:
        case 0x77:
            func_80043ABC(0);
            break;
        case 0x1b:
        case 0x3c:
            if (*(int*)((char*)&spyro + 0x50) != 6)
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
        case 0x14:
        case 0x1a:
        case 0x1d:
        case 0x20:
        case 0x2b:
        case 0x2c:
        case 0x31:
        case 0x35:
        case 0x36:
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

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800933D4.
 * Reuses newly verified33 ladder and special-state transitions, verified12
 * slide route and verified27 selector1A. Original43 supplies1D numeric words
 * 21C/220/224 to8C/90/94, signed shift6/fallbackA0 and stack10 vector route
 * with helper1A358(800), two particle callbacks and numeric table byte selectors.
 * Numeric pointer offsets are bytes. Access widths, shifts and conditions
 * follow original instructions. Empty constraints emit no instructions and
 * retain original source order, independent helper branches and saved selector
 * S0/walk flagS1. Reused semantic names do not establish meanings, units,
 * conversions, audio mappings or caller cadence. Acceptance requires every
 * original code/internal jump/owned dispatch word, strict complete translation
 * unit, complete EXE/every overlay hashes. Live runtime parity remains open.
 */
extern short Transition43SignedA[] __asm__("D_800658A0");
extern short Transition43SignedB[] __asm__("D_80065920");
extern int Transition43RawX __asm__("D_80070328+0x8C");
extern int Transition43_D_8006E528 __asm__("D_8006E528");
int Transition43PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");

extern Spyro Transition43_D_80070328 __asm__("D_80070328");
int Transition43MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
int Transition43RandBetween(int low, int high) __asm__("func_8003636C");
void Transition43BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
void Transition43ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Transition43ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition43_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition43RawUnion[] __asm__("D_80070328+0x144");
extern int Transition43RawMovement __asm__("D_80070328+0x50");
extern int Raw43Movement __asm__("D_80070328+0x50");
extern int Raw43Union __asm__("D_80070328+0x144");
void Call43TransformVectorByBasis(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
extern void (*Call43Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw43State[] __asm__("D_80070328+0x50");
extern Spyro Special43_D_80070328 __asm__("D_80070328");
extern short Signed43TableA[] __asm__("D_800658A0");
extern short Signed43TableB[] __asm__("D_80065920");
int Special43MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Special43BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
void Special43ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Special43ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Special43_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call43QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
void func_level_43_800933D4(int arg0) {
    Vector3D vector;
    register int oldMovementC __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register unsigned char* privateData __asm__("$16");

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$17");
    register int groundValue __asm__("$2");
    switch (arg0) {
        case 0x14:
            Transition43_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition43_D_80070328.unk5 = 0;
            Transition43ClearPlayerMotionVectors();
            Transition43_D_80070328.grounded = 1;
            Transition43_D_80070328.union144.a.unk13cb = Transition43RandBetween(1, 3);
            Transition43_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x1D: {
            register int oldState __asm__("$4") = Transition43RawMovement;
            register int first __asm__("$3") = Transition43_D_80070328.unk17e.x;
            register int second __asm__("$2");
            register int third __asm__("$3");
            MATCHING_KEEP2_CLOBBER(oldState, first, "memory");
            second = 7;
            MATCHING_KEEP(second);
            Transition43RawMovement = second;
            MATCHING_BARRIER_VOLATILE("memory");
            second = Transition43_D_80070328.unk17e.y;
            MATCHING_KEEP_VOLATILE_CLOBBER(second, "memory");
            Transition43_D_80070328.unk5 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(first, "memory");
            first <<= 6;
            MATCHING_KEEP(first);
            Transition43_D_80070328.unk7a[2].x = first;
            MATCHING_BARRIER_VOLATILE("memory");
            third = Transition43_D_80070328.unk17e.z;
            second <<= 6;
            Transition43_D_80070328.union144.a.unk13cb = oldState;
            Transition43_D_80070328.unk7a[2].y = second;
            second = third << 6;
            if (third == 0)
                second = Transition43_D_80070328.unk7a[3].z;
            Transition43_D_80070328.unk7a[2].z = second;
            Transition43BuildNegatedNormalizedPlayerVector(0xC00);
            Transition43_D_80070328.grounded = 1;
            Transition43_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            PlaySound((int)D_8006C654->spyroHurt, 0, 0);
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        }
        case 0x1A:
            savedBase = Transition43RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            oldMovementC = Transition43RawMovement;
            Transition43RawMovement = MOVEMENT_STATE_HURT;
            Transition43_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementC;
            Transition43ClearVector(destination);
            Transition43_D_80070328.grounded = 1;
            Transition43_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            PlaySound((int)D_8006C654->squish, 0, 0);
            goto clearPointers;
        case 0x20:
            Transition43_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition43_D_80070328.unk5 = 0;
            Transition43BuildNegatedNormalizedPlayerVector(0xC00);
            Transition43_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition43_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x2B:
        case 0x2C: {
            register unsigned char* unionPointer __asm__("$16");
            {
                register int stateWord __asm__("$3") = Transition43RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition43RawUnion;
                    *(int*)unionPointer = (-Transition43_D_80070328.unk7a[2].z) >> 2;
                    if (Transition43RawMovement != 8) {
                        Transition43_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition43RawMovement = 10;
                    }
                    Transition43_D_80070328.unk5 = 0;
                    Transition43_D_80070328.unk8[0] =
                        Transition43MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition43_D_80070328.grounded = 1;
                    Transition43_D_80070328.unk15b = 1;
                    func_8004F178(&vector, (Vector3D*)(unionPointer - 0x144));
                    vector.z += 0x400;
                    lengthResult = Call43QueryWorldHeight(&vector, 0x800);
                    vector.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, &vector, 0);
                        SpawnParticle(6, 0x2E, &vector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        case 0x2F:
            savedBase = (unsigned char*)&Transition43RawMovement;
            destination = (Vector3D*)(savedBase + 0x3C);
            if (*(int*)savedBase != 13) {
                *(int*)savedBase = 13;
                Transition43_D_80070328.unk5 = 0;
                func_8004F178(destination, (Vector3D*)(savedBase + 0x48));
                MATCHING_BARRIER_VOLATILE("memory");
                goto groundAndClear;
            }
            goto clearPointers;
        case 0x31: {
            register unsigned char* lengthBase __asm__("$5") =
                (unsigned char*)&Transition43_D_80070328.unk8[0];
            register int valueA __asm__("$4");
            register int valueB __asm__("$5");
            register int valueKind __asm__("$6");
            *(int*)lengthBase = 0;
            if (Transition43_D_80070328.animationState == 0xD ||
                Transition43_D_80070328.movementState == 1)
                func_8004F178((Vector3D*)(lengthBase - 0x30), (Vector3D*)(lengthBase - 0x18));
            else
                Transition43ClearVector((Vector3D*)(lengthBase - 0x30));
            func_8004F178(&Transition43_D_80070328.unk7a[2],
                          (Vector3D*)((unsigned char*)&Transition43_D_80070328.unk7a[2] - 0xC));
            Transition43_D_80070328.movementState = 17;
            Transition43_D_80070328.unk5 = 0;
            Transition43BuildNegatedNormalizedPlayerVector(0xC00);
            Transition43_D_80070328.grounded = 0;
            Transition43_D_80070328.union144.a.unk13cb = 0;
            valueKind = 1;
            if (Transition43_D_80070328.unk9ha[0] >= 11) {
                valueA = Transition43_D_80070328.unk9e.x;
                valueB = Transition43_D_80070328.unk9e.y;
            } else {
                valueA = Transition43_D_80070328.unk7a[3].x;
                valueB = valueA;
            }
            Transition43_D_80070328.union144.a.unk13cc =
                Transition43PlanarHeadingLookup(valueA, valueB, valueKind);
            goto clearPointers;
        }
        case 0x32:
        case 0x33:
        case 0x34:
            savedBase = (unsigned char*)&Transition43RawMovement;
            destination = (Vector3D*)(savedBase + 0x3C);
            if (*(int*)savedBase != 13) {
                *(int*)savedBase = 13;
                Transition43_D_80070328.unk5 = 0;
                func_8004F178(destination, (Vector3D*)(savedBase + 0x48));
                goto groundAndClear;
            }
            goto clearPointers;
        case 0x35:
        case 0x36:
            Transition43_D_80070328.movementState = 0;
            Transition43_D_80070328.unk5 = 0;
            Transition43ClearPlayerMotionVectors();
        groundAndClear:
            Transition43_D_80070328.grounded = 1;
        clearPointers:
            Transition43_D_80070328.unk20a = 0;
            Transition43_D_80070328.critterMobyPtr = 0;
            return;
        case 0x1B:
        case 0x3C: {
            register unsigned char* state __asm__("$3") = (unsigned char*)&Transition43RawMovement;
            *(int*)state = 18;
            Transition43_D_80070328.unk5 = 0;
            Transition43_D_80070328.unk8[0] =
                Transition43MeasureVectorLength((Vector3D*)(state + 0x48), 0);
            Transition43_D_80070328.grounded = 1;
            Transition43BuildNegatedNormalizedPlayerVector(0xC00);
            Transition43_D_80070328.unk4a = 0x300;
            return;
        }
        case 0x73:
        case 0x78:
        case 0x7E:
            Special43_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Special43_D_80070328.unk5 = 0;
            Special43ClearPlayerMotionVectors();
            Special43_D_80070328.grounded = 1;
            return;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            walkBase = Raw43State;
            walkFlag = 1;
            MATCHING_KEEP(walkFlag);
            *(int*)walkBase = walkFlag;
            if (arg0 == 0x57 && Special43_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                MATCHING_BARRIER_VOLATILE("memory");
                destination = (Vector3D*)(walkBase + 0x3C);
                goto copyWalkVector;
            }
            goto clearWalkFlag;
        case 0x80:
            Special43_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Special43_D_80070328.unk5 = 0;
            Special43BuildNegatedNormalizedPlayerVector(0xC00);
            Special43_D_80070328.grounded = 1;
            Special43_D_8006E524 = 0xF;
            return;
        case 0x81: {
            register int oldState __asm__("$3") = Raw43Movement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Raw43Movement = value;
            value = 1;
            MATCHING_KEEP(value);
            Special43_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Special43_D_8006E524 = value;
            Special43_D_80070328.unk5 = 0;
            stateWord = &Raw43Union;
            MATCHING_KEEP(stateWord);
            Special43_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Special43_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            Special43_D_80070328.unk22[3] = (int)D_8006C654->drown;
            return;
        }
        case 0x79:
            Special43_D_80070328.movementState = MOVEMENT_STATE_HURT;
            Special43_D_80070328.unk5 = 0;
            if (Special43_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Special43_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed43TableB + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                tableValueA >>= 1;
                Special43_D_80070328.unk7a[2].x = tableValueA;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed43TableA + tableOffsetOrValue);
                Special43_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Special43_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else {
                Special43ClearVector(
                    (Vector3D*)((unsigned char*)&Special43_D_80070328.movementState + 0x3C));
            }
            Special43_D_80070328.unk7a[2].z = 0x200;
            func_8004F178((Vector3D*)((unsigned char*)&Special43_D_80070328.unk7a[2].z - 0x14),
                          (Vector3D*)((unsigned char*)&Special43_D_80070328.unk7a[2].z - 8));
            Special43_D_80070328.grounded = 1;
            Special43_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
                return;
            }
        default:
            return;
        case 0x7A: {
            register unsigned char* privateData __asm__("$17") =
                Special43_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* state __asm__("$18") = Raw43State;
            register Vector3D* vector __asm__("$16");
            *(int*)state = 0;
            Special43_D_80070328.unk5 = 0;
            vector = (Vector3D*)(privateData + 0x64);
            Special43ClearPlayerMotionVectors();
            Special43_D_80070328.grounded = 1;
            Special43_D_80070328.idle = 0;
            Special43_D_80070328.unk15g = 0;
            *(int*)(privateData + 0x5C) = 0x180;
            *(int*)(privateData + 0x64) = 0x1800;
            *(int*)(privateData + 0x68) = 0;
            *(int*)(privateData + 0x6C) = 0;
            Call43TransformVectorByBasis((Vector3D*)(state - 0x20), vector, vector);
            func_8004F194(vector, vector, (Vector3D*)(state - 0x50));
            Call43Header(Special43_D_80070328.critterMobyPtr);
            return;
        }
        case 0x7B:
            Special43_D_80070328.movementState = 0;
            Special43ClearPlayerMotionVectors();
            groundValue = 1;
            goto sharedGround;
        case 0x7C: {
            register unsigned char* privateData __asm__("$16") =
                Special43_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* child __asm__("$4");
            Special43_D_80070328.movementState = 0;
            Special43ClearPlayerMotionVectors();
            Special43_D_80070328.grounded = 1;
            Special43_D_80070328.idle = 0;
            Special43_D_80070328.unk15g = 0;
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
            stateBaseA = Raw43State;
            MATCHING_KEEP(stateBaseA);
            destination = (Vector3D*)(stateBaseA + 0x3C);
            MATCHING_KEEP(destination);
            sourceBytesA = stateBaseA + 0x48;
            *(int*)stateBaseA = 2;
            func_8004F178(destination, (Vector3D*)sourceBytesA);
            Special43_D_80070328.unk8[0] = Special43MeasureVectorLength((Vector3D*)sourceBytesA, 0);
            Special43_D_80070328.unk7a[2].z = 0xDC0;
            Special43_D_80070328.unk5 = 0;
            if (Special43_D_80070328.animationState == 0x81)
                Special43_D_80070328.union144.a.unk13cb = 1;
            else
                Special43_D_80070328.union144.a.unk13cb = 0;
            Special43_D_80070328.grounded = 0;
            PlaySound((int)D_8006C654->jump, 0, 0);
            return;
        case 0x77: {
            register unsigned char* state __asm__("$6") = Raw43State;
            if (*(int*)state != 2) {
                *(int*)state = 3;
                Special43_D_80070328.unk8[0] =
                    Special43MeasureVectorLength((Vector3D*)(state + 0x48), 0);
                Special43_D_80070328.grounded = 0;
                Special43_D_80070328.unk15b = 1;
                goto clearTail;
            }
            return;
        }
        case 0x82: {
            walkBase = Raw43State;
            if (*(int*)walkBase != 2) {
                walkFlag = 1;
                MATCHING_KEEP(walkFlag);
                *(int*)walkBase = walkFlag;
                if (arg0 == 0x57 && Special43_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                    destination = (Vector3D*)(walkBase + 0x3C);
                copyWalkVector:
                    func_8004F178(destination, (Vector3D*)(walkBase + 0x48));
                    Special43_D_80070328.unk5 = walkFlag;
                } else {
                clearWalkFlag:
                    Special43_D_80070328.unk5 = 0;
                }
                Special43_D_80070328.unk8[0] = Special43MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Special43_D_80070328.movementState + 0x48), 0);
                Special43BuildNegatedNormalizedPlayerVector(0xC00);
                groundValue = 1;
                MATCHING_KEEP(groundValue);
                Special43_D_80070328.union144.a.unk13cb = 0;
            sharedGround:
                Special43_D_80070328.grounded = groundValue;
            clearTail:
                Special43_D_80070328.idle = 0;
                Special43_D_80070328.unk15g = 0;
            }
            return;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80093DF4.
 * Assembly SHA256 e6a11f9df9bc8ece50cfc4bd758c5c527b0b5619b714deb6169bfb3de75bfe8e.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1565 original instructions and113 state-table entries (bias20).
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
extern int Anim43Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim43Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim43Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim43Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim43PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim43PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim43PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim43PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim43PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim43Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim43Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim43Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim43Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim43Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim43Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim43Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim43Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim43Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim43PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim43Data66530View1[] __asm__("D_80066530");
extern int Anim43Data6E538View1 __asm__("D_8006E538"), Anim43Data6E53CView1 __asm__("D_8006E53C");
extern int Anim43Data6E044View1 __asm__("D_8006E044"), A4898Gate __asm__("D_8006E344"),
    A4898Count __asm__("D_8006C514");
int Anim43ProcessPlayerStateFlagsView1() __asm__("func_80040994");
int Anim43DispatchPlayerStateRequestView1() __asm__("func_8004BEF8");
int Anim43SelectPlayerAnimationLoopRequestView1() __asm__("func_80049688");
extern int Anim43PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim43PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim43Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim43Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim43PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim43Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim43Player280View2 __asm__("D_80070328 + 0x280");
extern int A21Buttons __asm__("D_8006E538"), Anim43Data6E53CView2 __asm__("D_8006E53C");
extern int Anim43Data6E044View2 __asm__("D_8006E044"), A21Gate __asm__("D_8006E344"),
    A21Count __asm__("D_8006C514");
extern int (*Anim43Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim43Player24View1 __asm__("D_80070328 + 0x24");
extern unsigned char* Anim43Data6C654View1 __asm__("D_8006C654");
int Anim43CallPlaySoundView1() __asm__("PlaySound");
int Anim43ProcessPlayerStateFlagsView2() __asm__("func_80040994");
int Anim43DispatchPlayerStateRequestView2() __asm__("func_8004BEF8");
int Anim43UpdatePlayerRetryStateView1() __asm__("func_800498C0");
extern unsigned char Anim43Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim43Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim43Data6EE2CView1 __asm__("D_8006EE2C");
int Anim43QueryWorldHeightWithOptionsView1() __asm__("func_8001A310");
extern int Anim43Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim43Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim43Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim43Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim43Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim43Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim43Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim43PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim43PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim43PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim43PlayerB8View3 __asm__("D_80070328 + 0xB8");
extern int Anim43PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim43PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim43PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim43PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim43Player144View3 __asm__("D_80070328 + 0x144");
extern int Anim43Player280View3 __asm__("D_80070328 + 0x280");
extern unsigned char* Anim43Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim43Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim43Data6E535View2 __asm__("D_8006E535");
extern int Anim43Data6E538View2 __asm__("D_8006E538");
extern int Anim43Data6E53CView3 __asm__("D_8006E53C");
extern int Anim43Data6E530View1 __asm__("D_8006E530");
extern int Anim43Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char* Anim43Data6C654View2 __asm__("D_8006C654");
extern int (*Anim43Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim43DataSpawnParticleView1)(int, int, void*, int) __asm__("SpawnParticle");
int Anim43ReadSelectedFrameScalarView1(void*) __asm__("func_80055E84");
int Anim43DispatchPlayerStateRequestView3(int) __asm__("func_8004BEF8");
int Anim43CallPlaySoundView2(unsigned char, int, int) __asm__("PlaySound");
extern int (*Anim43Data7431CView2)(int) __asm__("unk_ovlheader_8007431C");
extern int Anim43PlayerB4View2 __asm__("D_80070328 + 0xB4");
extern int Anim43Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim43Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim43Data6E044View3 __asm__("D_8006E044");
int Anim43SoundHandleMatchesIdInStates1Or2View1(int, int) __asm__("func_8003BF6C");
int Anim43TransitionSoundHandleTo3Or5View1(int) __asm__("func_8003BE70");
#define Anim43Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_level_43_80093DF4(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int* savedPointer16 __asm__("$16");
    register int savedWord16 __asm__("$16");
    rawValue2 = Anim43Player48View1;
    switch (rawValue2) {
        case 20:
            if (Anim43ProcessPlayerStateFlagsView1())
                return;
            rawValue2 = Anim43Data6E53CView1 & 64;
            nextSelector4 = 6;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            if (Anim43PlayerE4View1 >= 23)
                goto select;
            rawValue3 = Anim43Data6E538View1;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 13;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            if (rawValue2 >= 17) {
                nextSelector4 = 1;
                goto select;
            }
            rawValue2 = rawValue3 & 12;
            MATCHING_KEEP(rawValue2);
            if (!rawValue2) {
                rawValue2 = Anim43PlayerACView1;
                nextSelector4 = 1;
                if (rawValue2)
                    goto select;
            }
            if (Anim43Data6E044View1 == 7 || Anim43Player240View1) {
                savedPointer16 = &Anim43Player48View2;
                MATCHING_KEEP(savedPointer16);
                if (!*savedPointer16)
                    return;
                Anim43DispatchPlayerStateRequestView1(0);
                if (Anim43Data66530View1[*((unsigned char*)savedPointer16 - 0x2C)] >= 96) {
                    Anim43Player14View1 = Anim43Player15View1;
                    Anim43Player16View1 = Anim43Player17View1;
                }
                Anim43Player17View1 = 0;
                rawValue3 = *savedPointer16;
                rawValue2 = 113;
                *((unsigned char*)savedPointer16 - 0x2C) = rawValue2;
                Anim43Player1F0View1 = 0;
                Anim43Player15View1 = rawValue3;
                Anim43Player1ECView1 = rawValue3;
                return;
            }
            rawValue2 = Anim43PlayerFCView1;
            nextSelector4 = 15;
            if (rawValue2)
                goto select;
            Anim43SelectPlayerAnimationLoopRequestView1();
            return;
        case 53:
        case 54:
            if (Anim43ProcessPlayerStateFlagsView1())
                return;
            nextSelector4 = 0;
            goto select;
        case 29:
            if (Anim43Player54View1 < 25)
                return;
            if (Anim43Player280View1 < 0) {
                nextSelector4 = 31;
                goto select;
            }
            rawValue2 = 10;
            rawValue3 = Anim43Player144View1;
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
            rawValue2 = Anim43PlayerB8View1;
            nextSelector4 = 0;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            nextSelector4 = 7;
            goto select;
        case 26:
            if (Anim43Player24View1 & 16)
                return;
            if (Anim43Player54View2 < 25)
                return;
            if (Anim43Player280View2 < 0) {
                nextSelector4 = 32;
                goto select;
            }
            Anim43CallPlaySoundView1(Anim43Data6C654View1[15], 0, 0);
            rawValue3 = Anim43Player144View2;
            rawValue2 = 10;
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
            rawValue2 = Anim43PlayerB8View2;
            nextSelector4 = 0;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            nextSelector4 = 7;
            goto select;
        case 27:
            if (Anim43Player54View1 < 25)
                return;
            rawValue2 = Anim43Player280View1;
            nextSelector4 = 60;
            if (rawValue2 >= 0)
                goto select;
            __asm__ volatile("" ::"i"(0x8009413C) : "memory");
            nextSelector4 = 31;
            goto select;
        case 32:
            if (Anim43Player54View2 < 125)
                return;
        call498C0:
            Anim43UpdatePlayerRetryStateView1();
            return;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (Anim43ProcessPlayerStateFlagsView2())
                return;
            if ((Anim43Data6E53CView2 & 64) && Anim43Player54View2 >= 9) {
                nextSelector4 = 6;
                goto partialCall;
            }
            byte4 = &Anim43Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto partialCall;
            }
            if (!(Anim43Data6E53CView2 & 128))
                goto check44;
            if (Anim43Player54View2 < 9)
                goto check44;
            rawValue2 = *(int*)(Anim43Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto check44;
            rawValue2 = Anim43QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (rawValue2)
                goto check44;
            goto select;
        partialCall:
            Anim43DispatchPlayerStateRequestView2(nextSelector4);
        check44:
            rawValue2 = Anim43Data6E535View1;
            nextSelector4 = 44;
            if (!rawValue2)
                return;
            goto select;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3 = Anim43Player4CView2;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                goto other44;
            if (Anim43Data6E53CView2 & 0x850)
                goto callback44;
            if (Anim43Player54View2 < 61)
                return;
        callback44:
            callback2 = Anim43Data74374View1;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto call498C0;
        other44:
            if (Anim43ProcessPlayerStateFlagsView2())
                return;
            if ((Anim43Data6E53CView2 & 64) && Anim43Player54View2 >= 9) {
                nextSelector4 = 6;
                goto select;
            }
            byte4 = &Anim43Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto select;
            }
            if (!(Anim43Data6E53CView2 & 128))
                goto mode44;
            if (Anim43Player54View2 < 9)
                goto mode44;
            rawValue2 = *(int*)(Anim43Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto mode44;
            rawValue2 = Anim43QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        mode44:
            rawValue3 = Anim43Data6E044View2;
            rawValue2 = 7;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = Anim43Data6E535View1;
            nextSelector4 = 43;
            if (rawValue2)
                return;
            goto select;
        }
        case 47:
            if (Anim43ProcessPlayerStateFlagsView1())
                return;
            if (Anim43Data6E53CView1 & 64) {
                rawValue2 = Anim43Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (rawValue2)
                    goto specialJump;
                MATCHING_BARRIER_VOLATILE("memory");
                goto select;
            }
            rawValue2 = Anim43PlayerACView1;
            nextSelector4 = 50;
            if (!rawValue2)
                return;
            goto select;
        case 49:
            if (Anim43ProcessPlayerStateFlagsView1())
                return;
            rawValue2 = Anim43PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43Player144View1 < 16;
            nextSelector4 = 0;
            if (rawValue2)
                return;
            goto select;
        case 50:
            if (Anim43ProcessPlayerStateFlagsView1())
                return;
            if (Anim43Data6E53CView1 & 64) {
                rawValue2 = Anim43Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (rawValue2)
                    goto specialJump;
                goto select;
            }
            rawValue2 = Anim43PlayerACView1;
            nextSelector4 = 47;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerA0View1;
            rawValue3 = Anim43PlayerB4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < rawValue3;
            if (!rawValue2)
                return;
            rawValue2 = Anim43PlayerA4View1;
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
            if (Anim43ProcessPlayerStateFlagsView1())
                return;
            if (Anim43Data6E53CView1 & 64) {
                rawValue2 = Anim43Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (!rawValue2)
                    goto select;
            specialJump:
                Anim43DispatchPlayerStateRequestView1(7);
                rawValue2 = 3;
                Anim43Player4CView1 = rawValue2;
                return;
            }
            rawValue2 = Anim43PlayerACView1;
            nextSelector4 = 47;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerA0View1;
            rawValue3 = Anim43PlayerB4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < rawValue3;
            nextSelector4 = 50;
            if (rawValue2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto select;
        case 60: {
            register int (*callback2)(int) __asm__("$2");
        callback:
            callback2 = Anim43Data7431CView2;
            callback2(1);
            return;
        }
        case 115:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne115;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground115;
        airborne115:
            __asm__ volatile("" ::"i"(0x80094620) : "memory");
            nextSelector4 = 119;
            goto select;
        ground115:
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input115;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input115:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim43Data6E044View3;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim43Data6E044View3;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim43PlayerA8View2;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerACView2;
            if (rawValue2)
                goto select;
            rawValue2 = 25;
            rawValue3 = Anim43Field(record16, int*, 0x4C);
            nextSelector4 = 126;
            if (rawValue3 != rawValue2)
                return;
            goto select;
        case 116:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne116;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground116;
        airborne116:
            __asm__ volatile("" ::"i"(0x8009475C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground116:
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload116;
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload116:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim43Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input116:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x800947F4) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim43Data6E535View2;
            if (!rawValue2)
                goto afterLatch116;
            rawValue2 = Anim43PlayerB0View1;
            if (!rawValue2)
                goto latch116;
            rawValue2 = 40;
            rawValue3 = Anim43Data6E044View3;
            if (rawValue3 != rawValue2)
                goto afterLatch116;
        latch116:
            __asm__ volatile("" ::"i"(0x80094840) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch116:
            rawValue2 = Anim43PlayerB4View2 < 3073;
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43ReadSelectedFrameScalarView1((void*)nextSelector4);
            rawValue2 = rawValue2 < 37;
            nextSelector4 = 117;
            if (rawValue2)
                return;
            goto select;
        case 117:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne117;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground117;
        airborne117:
            __asm__ volatile("" ::"i"(0x800948D8) : "memory");
            nextSelector4 = 119;
            goto select;
        ground117:
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload117;
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload117:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim43Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input117:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x80094970) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim43Data6E535View2;
            if (!rawValue2)
                goto afterLatch117;
            rawValue2 = Anim43PlayerB0View1;
            if (!rawValue2)
                goto latch117;
            rawValue2 = 40;
            rawValue3 = Anim43Data6E044View3;
            if (rawValue3 != rawValue2)
                goto afterLatch117;
        latch117:
            __asm__ volatile("" ::"i"(0x800949BC) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch117:
            rawValue2 = Anim43PlayerB4View2 < 2560;
            if (!rawValue2)
                return;
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x80094A10) : "memory");
            goto select;
        case 118:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim43Player54View3 < 16;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim43PlayerCCView1;
            rawValue2 = Anim43Player8CView1;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim43PlayerD0View1;
            rawValue2 = Anim43Player90View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim43PlayerD4View1;
            rawValue2 = Anim43Player94View1;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x80094B00) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim43PlayerACView2;
            nextSelector4 = 120;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x80094B3C) : "memory");
            nextSelector4 = 117;
            goto select;
        private118:
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        finish118:
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x80094BB0) : "memory");
            goto preserveAge;
        case 119:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3;
            rawValue3 = 2;
            if (rawValue2)
                goto other119;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x80094C24) : "memory");
                nextSelector4 = 131;
                goto effect119;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto effect119;
            rawValue2 = Anim43PlayerACView2;
            if (rawValue2)
                goto distance119;
            nextSelector4 = 120;
            goto effect119;
        distance119:
            rawValue2 = Anim43PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto effect119;
            nextSelector4 = 117;
        effect119:
            Anim43DispatchPlayerStateRequestView3(nextSelector4);
            {
                register int (*spawn2)(int, int, void*, int) __asm__("$2") =
                    Anim43DataSpawnParticleView1;
                if (spawn2)
                    spawn2(8, 33, 0, 2);
            }
            rawValue2 = (int)Anim43Data6C654View2;
            product5 = 0;
            nextSelector4 = Anim43Field((void*)rawValue2, unsigned char*, 0x12);
            Anim43CallPlaySoundView2((unsigned char)nextSelector4, product5, 0);
            rawValue2 = Anim43Player58View1 < 24;
            if (rawValue2)
                return;
            rawValue2 = 120;
            Anim43Data6E530View1 = rawValue2;
            rawValue2 = 15;
            Anim43Data6E52CView1 = rawValue2;
            return;
        other119:
            rawValue2 = 2;
            rawValue3 = Anim43Player50View1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                return;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            if (!rawValue2)
                return;
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 130;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80094D30) : "memory");
            goto select;
        case 120:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43PlayerB8View3 < 4;
            nextSelector4 = 119;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input120;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input120:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x80094DE0) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim43Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Data6E53CView3 & 32;
            nextSelector4 = 115;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x80094E50) : "memory");
            goto select;
        case 121:
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto done121;
        done121:
            rawValue2 = Anim43Player280View3;
            if (rawValue2 < 0) {
                nextSelector4 = 128;
                goto select;
            }
            rawValue2 = Anim43PlayerB8View3;
            nextSelector4 = 115;
            if (!rawValue2)
                goto select;
            nextSelector4 = 119;
            goto select;
        case 122:
            rawValue2 = Anim43Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne122;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground122;
        airborne122:
            __asm__ volatile("" ::"i"(0x80094F10) : "memory");
            nextSelector4 = 119;
            goto select;
        ground122:
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 123;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x80094F4C) : "memory");
            goto select;
        case 123:
            rawValue2 = Anim43Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne123;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground123;
        airborne123:
            __asm__ volatile("" ::"i"(0x80094FA0) : "memory");
            nextSelector4 = 119;
            goto select;
        ground123:
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 124;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80094FC0) : "memory");
            goto select;
        case 124:
            rawValue2 = Anim43Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne124;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground124;
        airborne124:
            __asm__ volatile("" ::"i"(0x80095014) : "memory");
            nextSelector4 = 119;
            goto select;
        ground124:
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x80095050) : "memory");
            goto select;
        case 126:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne126;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground126;
        airborne126:
            __asm__ volatile("" ::"i"(0x800950AC) : "memory");
            nextSelector4 = 119;
            goto select;
        ground126:
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input126;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input126:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim43Data6E044View3;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim43Data6E044View3;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim43PlayerA8View2;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerACView2;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x800951B0) : "memory");
            goto select;
        case 128:
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto helper128;
        helper128:
            goto call498C0;
        case 129:
            rawValue2 = Anim43Data6E53CView3 & 64;
            if (rawValue2) {
                rawValue2 = 1;
                Anim43Player1B6View1 = rawValue2;
            }
            nextSelector4 = (int)&Anim43Player280View3;
            rawValue2 = *(int*)nextSelector4;
            if (rawValue2 < 0) {
                rawValue2 = 36863;
                rawValue3 = Anim43Player144View3;
                rawValue2 = rawValue2 < rawValue3;
                if (!rawValue2)
                    return;
                rawValue2 = -1;
                Anim43Player28CView1 = rawValue2;
                goto call498C0;
            }
            rawValue3 = Anim43Player54View3;
            rawValue2 = rawValue3 < 61;
            if (!rawValue2) {
                rawValue2 = -1;
                *(int*)nextSelector4 = rawValue2;
                return;
            }
            rawValue2 = rawValue3 < 16;
            if (rawValue2)
                return;
            rawValue2 = Anim43Player1B6View1;
            if (!rawValue2)
                return;
            product5 = Anim43Player28CView1;
            nextSelector4 = 118;
            if (product5 < 0)
                goto select;
            nextSelector4 = Anim43Player290View1;
            rawValue2 = Anim43SoundHandleMatchesIdInStates1Or2View1(nextSelector4, product5);
            if (rawValue2) {
                nextSelector4 = Anim43Player28CView1;
                Anim43TransitionSoundHandleTo3Or5View1(nextSelector4);
            }
            rawValue2 = -1;
            Anim43Player28CView1 = rawValue2;
            nextSelector4 = 118;
            goto select;
        case 130:
            rawValue2 = Anim43Data7431CView1(1);
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim43Player250View1;
            rawValue2 = Anim43Player48View3;
            rawValue3 = Anim43Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                goto other130;
            rawValue2 = Anim43Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                goto other130;
            }
            goto completed130;
        completed130:
            rawValue2 = Anim43PlayerB8View3;
            if (rawValue2)
                goto preserveAge;
            rawValue2 = Anim43Data6E535View2;
            if (rawValue2)
                goto latch130;
            rawValue2 = Anim43PlayerB4View2 < 2560;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x80095374) : "memory");
            nextSelector4 = 117;
            goto select;
        latch130:
            __asm__ volatile("" ::"i"(0x8009537C) : "memory");
            nextSelector4 = 115;
            goto select;
        preserveAge:
            savedWord16 = Anim43Player54View3;
            Anim43DispatchPlayerStateRequestView3(119);
            Anim43Player54View3 = savedWord16;
            return;
        other130:
            nextSelector4 = (int)&Anim43Player50View1;
            rawValue3 = *(int*)nextSelector4;
            rawValue2 = 2;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3;
            if (rawValue2)
                return;
            rawValue2 = 1;
            *(int*)nextSelector4 = rawValue2;
            goto select116;
        case 131:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne131;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground131;
        airborne131:
            __asm__ volatile("" ::"i"(0x8009542C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground131:
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload131;
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload131:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim43Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input131:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 4;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim43Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerB0View1;
            if (!rawValue2)
                goto latch131;
            rawValue2 = 40;
            rawValue3 = Anim43Data6E044View3;
            if (rawValue3 != rawValue2)
                goto select;
        latch131:
            __asm__ volatile("" ::"i"(0x80095508) : "memory");
            nextSelector4 = 115;
            goto select;
        case 132:
            rawValue2 = (int)Anim43Player250View1;
            callback3 = Anim43Data7431CView1;
            record16 = Anim43Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim43PlayerB8View3 < 4;
            if (!rawValue2)
                goto airborne132;
            rawValue2 = Anim43PlayerE4View2 < 23;
            if (rawValue2)
                goto ground132;
        airborne132:
            __asm__ volatile("" ::"i"(0x80095564) : "memory");
            nextSelector4 = 119;
            goto select;
        ground132:
            rawValue2 = Anim43Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim43Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload132;
            rawValue2 = Anim43Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload132:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim43Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim43Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input132:
            rawValue2 = Anim43Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 4;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 8;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 131;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim43Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim43PlayerB0View1;
            if (!rawValue2)
                goto latch132;
            rawValue2 = 40;
            rawValue3 = Anim43Data6E044View3;
            if (rawValue3 != rawValue2)
                goto select;
        latch132:
            __asm__ volatile("" ::"i"(0x80095640) : "memory");
            nextSelector4 = 115;
            goto select;
        default:
            return;
    }
select116:
    nextSelector4 = 116;
select:
    Anim43DispatchPlayerStateRequestView1(nextSelector4);
    return;
}
#undef Anim43Field
