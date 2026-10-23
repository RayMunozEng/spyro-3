#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80097550.
 * Assembly SHA256 833311efc9ea17f6b57658fdba023dc3bd041d4d8a4b6c4905690160c38f77a0.
 * AI-generated; not human reviewed. All2043 original instructions,
 * 143 selectors (bias9) and one owned table-padding word are required.
 * Frame0x168 retains scratch10..13C, savedS0..S7, incoming slotS2 and
 * combinedS7. Seven groups reuse verified12/21/22; near9/28/49/57 and443-row
 * 36/37/48 retain exact saved-register, stack and original-address mappings.
 * Original32 stores fixedAC9280; source22's absent C700 path is not copied.
 * Matrix halfwords60/62/64 preserve original widths. Original particle
 * selector58, pointer-ready/address94 joins and final94 ownership are exact.
 * All160 original150/151 rows retain both selector151 loads, signed wrapped
 * arithmetic, bounds, spring/trig, vector and guarded final94 store.
 * Typed aliases remain distinct. Empty initialized constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Rev1 skateboard source is an identified cross-reference; Rev0 words rule.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every original native/linked instruction, conditional/internal
 * target, selector/padding/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics32Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics32RandSignedBetweenView1() __asm__("func_800363DC");
unsigned char Physics32UpdatePlayerGroundInputTargetsView1() __asm__("func_80040D10");
unsigned char Physics32ApproachPlayerTargetHeadingView1() __asm__("func_80041580");
unsigned char Physics32BlendPlayerHeadingFromInputVectorView1() __asm__("func_800416F4");
unsigned char Physics32ApproachPlayerTargetSpeedView1() __asm__("func_800417FC");
unsigned char Physics32BuildPlayerResponseVectorView1() __asm__("func_80041B64");
int Physics32InterpolateSineView1() __asm__("func_8004E9E4");
int Physics32InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics32TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics32MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics32ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics32ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
unsigned char Physics32ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics32CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics32AddVectorView1() __asm__("func_8004F194");
unsigned char Physics32SubtractVectorView1() __asm__("func_8004F1C8");
int Physics32CallRandView1() __asm__("rand");
extern unsigned char Physics32Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics32Data65920View1 __asm__("D_80065920");
extern void* Physics32Data6C570View1 __asm__("D_8006C570");
extern int Physics32Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics32Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics32Player0View1 __asm__("D_80070328");
extern int Physics32Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics32Player94View2 __asm__("D_80070328+0x94");
extern int Physics32Player80View1 __asm__("D_80070328+0x80");
extern int Physics32PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics32Player64View1 __asm__("D_80070328+0x64");
extern int Physics32Player144View1 __asm__("D_80070328+0x144");
extern int Physics32Player60View1 __asm__("D_80070328+0x60");
extern int Physics32PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics32Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics32Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics32Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics32PlayerFCView1 __asm__("D_80070328+0xFC");
int Physics32MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics32ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics32CopyVectorView2() __asm__("func_8004F178");
int Physics32AddVectorView2() __asm__("func_8004F194");
int Physics32SubtractVectorView2() __asm__("func_8004F1C8");
extern unsigned char Physics32Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics32Data65920View2 __asm__("D_80065920");
extern int Physics32Data6C514View1 __asm__("D_8006C514");
extern int Physics32Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics32Player0View2 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics32Player16CView1 __asm__("D_80070328+0x16C");
int Physics32ApproachPlayerTargetSpeedView2() __asm__("func_800417FC");
int Physics32PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics32InterpolateSineView2() __asm__("func_8004E9E4");
int Physics32InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics32MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics32ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics32ShiftVectorLeftView1() __asm__("func_8004F0E8");
int Physics32CopyVectorView3() __asm__("func_8004F178");
int Physics32AddVectorView3() __asm__("func_8004F194");
int Physics32SubtractVectorView3() __asm__("func_8004F1C8");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics32PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics32PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics32Player148View1 __asm__("D_80070328+0x148");
extern int Physics32Player210View1 __asm__("D_80070328+0x210");
extern int Physics32Player220View1 __asm__("D_80070328+0x220");
extern int Physics32Player98View1 __asm__("D_80070328+0x98");
extern int Physics32PlayerA0View1 __asm__("D_80070328+0xA0");
extern int Physics32PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics32PlayerCCView1 __asm__("D_80070328+0xCC");
extern int Physics32PlayerD0View1 __asm__("D_80070328+0xD0");
extern int Physics32PlayerE4View1 __asm__("D_80070328+0xE4");
extern unsigned char Physics32PlayerFCView2 __asm__("D_80070328+0xFC");
int Physics32UpdatePlayerGroundInputTargetsView2() __asm__("func_80040D10");
int Physics32UpdateSmoothedInputPairView1() __asm__("func_800410F8");
int Physics32ApproachPlayerTargetHeadingView2() __asm__("func_80041580");
int Physics32ApproachPlayerTargetSpeedView3() __asm__("func_800417FC");
int Physics32BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Physics32BuildPlayerResponseVectorView2() __asm__("func_80041B64");
int Physics32InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics32TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics32ShiftVectorRightTowardZeroView2() __asm__("func_8004F110");
int Physics32ClearVectorView2() __asm__("func_8004F168");
int Physics32CopyVectorView4() __asm__("func_8004F178");
int Physics32AddVectorView4() __asm__("func_8004F194");
int Physics32CallRandView2() __asm__("rand");
extern int* Physics32Data6C570View2 __asm__("D_8006C570");
extern int Physics32Data6C640View1 __asm__("D_8006C640");
extern int Physics32Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics32Player0View3 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics32Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics32Player158View1 __asm__("D_80070328+0x158");
extern int Physics32Player20CView1 __asm__("D_80070328+0x20C");
int Physics32UpdateSmoothedInputPairView2() __asm__("func_800410F8");
int Physics32ApproachPlayerTargetSpeedView4() __asm__("func_800417FC");
int Physics32BuildPlayerMovementVectorView2() __asm__("func_80041848");
int Physics32InterpolateCosineView4() __asm__("func_8004EA2C");
int Physics32CopyVectorView5() __asm__("func_8004F178");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char Physics32Player0View4 __asm__("D_80070328");
int Physics32BuildOrientedInputPairView1() __asm__("func_80040F48");
int Physics32ApproachPlayerTargetSpeedView5() __asm__("func_800417FC");
int Physics32BuildPlayerMovementVectorView3() __asm__("func_80041848");
int Physics32WriteBasisAngleTripletView1() __asm__("func_8004E56C");
int Physics32PlanarHeadingLookupView2() __asm__("func_8004E880");
int Physics32TransposePackedHalfwordMatrix3x3View1() __asm__("func_8004ECF4");
int Physics32MeasureVectorLengthView4() __asm__("func_8004EDE8");
int Physics32ScaleVectorRatioQ15View4() __asm__("func_8004F08C");
int Physics32CopyVectorView6() __asm__("func_8004F178");
int Physics32AddVectorView5() __asm__("func_8004F194");
int Physics32SubtractVectorView4() __asm__("func_8004F1C8");
int Physics32BuildEulerBasisPairView1() __asm__("func_8004F6C4");
int Physics32MultiplyPackedGteMatricesView1() __asm__("func_8005F35C");
extern int* Physics32Data6C570View3 __asm__("D_8006C570");
extern int Physics32Data6E538View1 __asm__("D_8006E538");
extern int Physics32PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics32Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics32Player68View1 __asm__("D_80070328+0x68");
extern int Physics32Player6CView1 __asm__("D_80070328+0x6C");
extern int Physics32Player70View1 __asm__("D_80070328+0x70");
extern int Physics32PlayerA0View2 __asm__("D_80070328+0xA0");
extern int Physics32Player5CView2 __asm__("D_80070328+0x5C");
extern int Physics32Player60View2 __asm__("D_80070328+0x60");
extern int Physics32Player64View2 __asm__("D_80070328+0x64");
extern int Physics32Player164View1 __asm__("D_80070328+0x164");
extern int Physics32PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics32PlayerB8View2 __asm__("D_80070328+0xB8");
extern int Physics32Player16CView2 __asm__("D_80070328+0x16C");
extern int Physics32Player168View1 __asm__("D_80070328+0x168");
extern int Physics32Player94View3 __asm__("D_80070328+0x94");
extern int Physics32Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics32Player80View2 __asm__("D_80070328+0x80");
extern int Physics32Player90View1 __asm__("D_80070328+0x90");
extern int Physics32Player84View1 __asm__("D_80070328+0x84");
extern int Physics32PlayerF4View1 __asm__("D_80070328+0xF4");
extern int Physics32Player8View1 __asm__("D_80070328+0x8");
extern int Physics32Player48View1 __asm__("D_80070328+0x48");
int Physics32ApproachPlayerTargetHeadingView3() __asm__("func_80041580");
void func_level_32_80097550(int slotIndex) {
    register int signedWord19 __asm__("$20");
    register int signedWord20 __asm__("$21");
    register int signedWord21 __asm__("$22");
    register void* savedPointer22 __asm__("$19");
    register void* savedPointer17 __asm__("$17");
    int raw22_temp_v0_6;
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
    register int below19 __asm__("$2");
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4,
            spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC,
            spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C, sp120,
            sp124, sp128, sp12C, sp130, sp134, sp138, sp13C;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector8CState9 __asm__("$17");
    register void* globalVector8CState20 __asm__("$18");
    register void* var_a0 __asm__("$4");
    register void* var_a0_2 __asm__("$4");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$23");
    int temp_v0;
    int temp_v0_2;
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
    globalPointer = &Physics32Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics32Data6C570View1 = (void*)workWord2;
    workWord2 = Physics32Field(&Physics32Player0View1, int*, 0x54);
    stateWord3 = Physics32Field(&Physics32Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        case 20:
        case 53:
        case 54:
            globalVector80 = &Physics32Player0View1 + 0x80;
            Physics32ClearVectorView1(globalVector80);
            Physics32ClearVectorView1(globalVector80 + 0xC);
            if (Physics32Data6E044View1 != 7) {
                Physics32UpdatePlayerGroundInputTargetsView1(0x1200);
                Physics32BlendPlayerHeadingFromInputVectorView1();
                Physics32ApproachPlayerTargetHeadingView1(0x5A, 0x10);
                return;
            }
            return;
        default:
            return;
        case 0x9:
            globalField4CPointer = &Physics32Player0View1 + 0x4C;
            workWord3 = Physics32Field(&Physics32Player0View1, int*, 0x4C);
            MATCHING_KEEP(workWord3);
            workWord2 = 1;
            if (workWord3 == workWord2) {
                Physics32UpdatePlayerGroundInputTargetsView1(0xC80);
                Physics32ApproachPlayerTargetHeadingView1(0x28, 8);
                Physics32ApproachPlayerTargetSpeedView1(0x140, 0xC0);
                globalVector8CState9 = globalField4CPointer + 0x40;
                workWord2 = Physics32InterpolateCosineView1(
                    Physics32Field(&Physics32Player0View1, int*, 0xA4));
                workWord3 = Physics32Field(&Physics32Player0View1, int*, 0xB0);
                lowProduct0 = workWord3 * workWord2;
                workWord2 = lowProduct0 >> 12;
                MATCHING_KEEP(workWord2);
                originalFrame.sp10 = workWord2;
                workWord2 = Physics32InterpolateSineView1(
                    Physics32Field(&Physics32Player0View1, int*, 0xA4));
                workWord3 = Physics32Field(&Physics32Player0View1, int*, 0xB0);
                lowProduct1 = workWord3 * workWord2;
                workWord2 = lowProduct1 >> 12;
                MATCHING_KEEP(workWord2);
                originalFrame.sp14 = workWord2;
                Physics32SubtractVectorView1(&originalFrame.sp10, &originalFrame.sp10,
                                             globalVector8CState9);
                originalFrame.sp18 = 0;
                temp_v0 = Physics32MeasureVectorLengthView1(&originalFrame.sp10, 0);
                MATCHING_KEEP(globalField4CPointer);
                var_a0 = globalField4CPointer + 0x34;
                if (temp_v0 >= 0x281) {
                    Physics32ScaleVectorRatioQ15View1(&originalFrame.sp10, temp_v0, 0x280);
                    MATCHING_KEEP(globalField4CPointer);
                    var_a0 = globalField4CPointer + 0x34;
                }
                Physics32AddVectorView1(var_a0, globalVector8CState9, &originalFrame.sp10);
                Physics32BuildPlayerResponseVectorView1();
                if (combinedIndex < 0xD) {
                    MATCHING_OBSERVE(combinedIndex);
                    workWord2 = Physics32Player94View2;
                    workWord2 += 23;
                    goto store94From2;
                    return;
                }
                workWord2 = Physics32Player94View2 - 192;
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
                workWord3 = Physics32Field(&Physics32Player0View1, int*, 0x8C);
                workWord2 = workWord3 * 7;
                workWord3 = Physics32Field(&Physics32Player0View1, int*, 0x90);
                Physics32Field(globalField4CPointer, int*, 0x34) = workWord2 << 5;
                workWord2 = workWord3 * 7;
                workWord3 = Physics32Field(&Physics32Player0View1, int*, 0x94);
                Physics32Field(&Physics32Player0View1, int*, 0x84) = workWord2 << 5;
                Physics32Field(&Physics32Player0View1, int*, 0x88) = (workWord3 * 7) << 5;
                Physics32ShiftVectorRightTowardZeroView1(call4, 8);
                MATCHING_KEEP(globalField4CPointer);
                var_a0_2 = globalField4CPointer + 0x40;
            }
            Physics32CopyVectorView1(var_a0_2, globalField4CPointer + 0x34);
            temp_v0_2 = Physics32Field(&Physics32Player0View1, int*, 0x94) - 0xC0;
            Physics32Field(&Physics32Player0View1, int*, 0x94) = temp_v0_2;
            if (temp_v0_2 < -8960) {
                workWord2 = -8960;
                goto store94From2;
            }
            return;
        case 19: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3 = Physics32Data6E344View1;
            workWord2 = 13;
            if (workWord3 == workWord2) {
                workWord2 = Physics32Data6C514View1;
                if (workWord2)
                    return;
            }
            globalVector8CState20 = &Physics32Player0View2 + 8;
            workWord3 = Physics32Field(globalVector8CState20, int*, 0);
            workWord2 = Physics32Field(&Physics32Player0View2, int*, 0x144);
            numeric4 = workWord3 - workWord2;
            workWord2 = numeric4 < 1024;
            if (!workWord2)
                goto beyond19;
            workWord2 = Physics32Player94View2;
            workWord2 += 128;
            Physics32Player94View2 = workWord2;
            workWord2 = workWord2 < 4801;
            __asm__("" : "=r"(numeric4) : "0"(numeric4), "r"(workWord2));
            if (!workWord2) {
                workWord2 = 4800;
                Physics32Player94View2 = workWord2;
            }
            lowProduct2 = numeric4 * numeric4;
            vectorAt30 = &originalFrame.sp20;
            call4 = vectorAt30;
            workWord3 = Physics32Field(&Physics32Player0View2, int*, 0x148);
            MATCHING_OBSERVE3(workWord2, workWord3, call4);
            workWord2 = lowProduct2 >> 11;
            angle16 = workWord2 + workWord3;
            Physics32Player64View1 = angle16;
            __asm__ volatile(""
                             : "=r"(globalVector8CState20)
                             : "0"(globalVector8CState20), "r"(call4)
                             : "memory");
            Physics32CopyVectorView2(call4, globalVector8CState20 + 340);
            call4 = vectorAt30;
            call5 = call4;
            Physics32SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics32MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x800978AC) : "memory");
            numeric6 = 1024;
            goto limit19;
        beyond19:
            numeric5 = Physics32Field(&Physics32Player0View2, int*, 0x14C);
            workWord2 = workWord3 - numeric5;
            workWord2 = workWord2 < -1024;
            numeric6 = numeric5 - workWord3;
            if (!workWord2)
                goto curve19;
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x800978D0));
            workWord2 = Physics32Player4CView1;
            workWord3 = 1;
            if (!workWord2) {
                workWord2 = Physics32Field(&Physics32Player0View2, int*, 0x148);
                Physics32Player4CView1 = workWord3;
                workWord2 += 512;
                Physics32Field(&Physics32Player0View2, int*, 0x148) = workWord2;
            }
            workWord2 = Physics32Player94View2;
            workWord2 += 128;
            Physics32Player94View2 = workWord2;
            workWord2 = workWord2 < 4801;
            if (!workWord2)
                Physics32Player94View2 = 4800;
            workWord2 = Physics32Field(&Physics32Player0View2, int*, 0x150);
            numeric6 = numeric4 - 1024;
            workWord3 = workWord2 * numeric6;
            workWord2 = Physics32Field(&Physics32Player0View2, int*, 0x154);
            workWord2 = workWord3 / workWord2;
            vectorAt30 = &originalFrame.sp20;
            call4 = vectorAt30;
            workWord3 = Physics32Field(&Physics32Player0View2, int*, 0x148);
            angle16 = workWord3 + workWord2;
            workWord2 = (numeric6 << 10) >> 10;
            workWord2 = angle16 + workWord2;
            angle16 = workWord2 & 4095;
            Physics32Player64View1 = angle16;
            Physics32CopyVectorView2(call4, globalVector8CState20 + 340);
            call4 = vectorAt30;
            call5 = call4;
            Physics32SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics32MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x800979E4) : "memory");
            numeric6 = 1024;
            goto limit19;
        curve19:
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x800979EC));
            workWord2 = (numeric6 * 4800) >> 10;
            Physics32Player94View2 = workWord2;
            workWord2 = Physics32Player16CView1;
            numeric7 = Physics32Field(&Physics32Player0View2, int*, 0x168);
            workWord3 = Physics32Field(&Physics32Player0View2, int*, 0x158);
            workWord2 &= 127;
            numeric4 = numeric7 << 1;
            Physics32Player16CView1 = workWord2;
            workWord2 = *(short*)(&Physics32Data65920View2 + numeric4);
            workWord3 += 1024;
            product10 = workWord3 * workWord2;
            square8 = numeric6 * numeric6;
            workWord2 = product10 >> 12;
            originalFrame.sp20 = workWord2;
            workWord2 = *(short*)(&Physics32Data658A0View2 + numeric4);
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
            Physics32AddVectorView2(call4, call5, numeric6, numeric7);
            call4 = vectorAt30;
            call5 = call4;
            Physics32Player64View1 = angle16;
            Physics32SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics32MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 2049;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            numeric6 = 2048;
        limit19:
            Physics32ScaleVectorRatioQ15View2(call4, call5, numeric6);
        commit19:
            workWord2 = originalFrame.sp20;
            workWord3 = originalFrame.sp24;
            Physics32Field(&Physics32Player0View2, int*, 0x8C) = workWord2;
            Physics32Field(&Physics32Player0View2, int*, 0x90) = workWord3;
            return;
        }
        case 21:
            raw22_temp_v0_6 = Physics32Field(&Physics32Player0View4, int*, 0x94) - 0x140;
            Physics32Field(&Physics32Player0View4, int*, 0x94) = raw22_temp_v0_6;
            if (raw22_temp_v0_6 < -0x2300) {
                Physics32Field(&Physics32Player0View4, int*, 0x94) = -0x2300;
            }
            Physics32Field(&Physics32Player0View4, int*, 0xA4) = Physics32PlanarHeadingLookupView2(
                Physics32Field(&Physics32Player0View4, int*, 0x8C),
                Physics32Field(&Physics32Player0View4, int*, 0x90), 1);
            Physics32ApproachPlayerTargetHeadingView3(0x5A, 0x10);
            return;
        case 28:
            Physics32UpdatePlayerGroundInputTargetsView1(0xC80);
            Physics32ApproachPlayerTargetHeadingView1(0x28, 8);
            Physics32ApproachPlayerTargetSpeedView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics32Player0View1 + 0xA4;
            globalVector8CState20 = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics32InterpolateCosineView1(Physics32Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics32Field(&Physics32Player0View1, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics32Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp30 = workWord2;
            workWord2 = Physics32InterpolateSineView1(call4);
            workWord3 = Physics32Field(&Physics32Player0View1, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp34 = workWord2;
            Physics32SubtractVectorView1(&originalFrame.sp30, &originalFrame.sp30,
                                         globalVector8CState20);
            originalFrame.sp38 = 0;
            temp_v0_4 = Physics32MeasureVectorLengthView1(&originalFrame.sp30, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics32ScaleVectorRatioQ15View1(&originalFrame.sp30, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics32AddVectorView1(var_a0_3, globalVector8CState20, &originalFrame.sp30);
            Physics32BuildPlayerResponseVectorView1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics32Field(&Physics32Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics32Field(&Physics32Player0View1, int*, 0x94) - 0xC0;
            }
            Physics32Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics32Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics32Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp50;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics32CallRandView1() & 0xFF)) {
                        workWord2 = Physics32RandSignedBetweenView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics32Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp40 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics32Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp48 = 0xE;
                        originalFrame.sp50 = -0x12C;
                        originalFrame.sp54 = 0;
                        originalFrame.sp58 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp44 = (workWord3 * 5) >> 0xA;
                        Physics32TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp50 += Physics32RandSignedBetweenView1(0, 0x50);
                        originalFrame.sp54 += Physics32RandSignedBetweenView1(0, 0x50);
                        originalFrame.sp58 += Physics32RandSignedBetweenView1(0, 0x50);
                        Physics32AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0x3A, vectorAt40, &originalFrame.sp40);
                        Physics32Field(temp_v0_5, signed char*, 2) = 8;
                        Physics32Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 30:
            globalVector80 = &Physics32Player80View1;
            MATCHING_KEEP_VOLATILE_CLOBBER(globalVector80, "memory");
            goto block_154;
        case 0x24:
        case 0x25:
        case 48: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics32BuildOrientedInputPairView1(&originalFrame.sp40, 0);
            workWord2 = originalFrame.sp40;
            call5 = &Physics32PlayerA8View1;
            workWord3 = workWord2 * 9;
            workWord3 <<= 2;
            workWord2 -= workWord3;
            workWord3 = Physics32Field(call5, int*, 0);
            numeric4 = workWord2 >> 7;
            workWord2 = workWord3 < numeric4;
            if (workWord2) {
                workWord2 = workWord3 + 8;
                Physics32Field(call5, int*, 0) = workWord2;
                workWord2 = numeric4 < workWord2;
            } else {
                workWord2 = workWord3 - 8;
                Physics32Field(call5, int*, 0) = workWord2;
                workWord2 = workWord2 < numeric4;
            }
            if (workWord2)
                Physics32Field(call5, int*, 0) = numeric4;
            workWord3 = Physics32Player4CView2;
            workWord2 = 5;
            if (workWord3 == workWord2) {
                workWord3 = Physics32Player68View1;
                numeric4 = Physics32Player6CView1;
                workWord2 = (workWord3 << 5) >> 9;
                workWord3 -= workWord2;
                workWord2 = (numeric4 << 5) >> 9;
                Physics32Player68View1 = workWord3;
                workWord3 = originalFrame.sp40;
                numeric4 -= workWord2;
                Physics32Player6CView1 = numeric4;
                numeric4 = Physics32Player70View1;
                workWord2 = workWord3 * 48;
                workWord2 = -workWord2;
                workWord2 >>= 8;
                workWord3 = (numeric4 << 5) >> 9;
                workWord2 -= workWord3;
                numeric4 += workWord2;
                goto store70;
            }
            workWord2 = 4;
            if (workWord3 != workWord2)
                goto default48;
            workWord2 = Physics32Data6E538View1 & 16;
            if (!workWord2)
                goto default48;
            workWord2 = originalFrame.sp40;
            numeric4 = Physics32Player68View1;
            numeric5 = Physics32Player6CView1;
            workWord3 = (workWord2 * 48) >> 8;
            workWord2 = (numeric4 << 5) >> 9;
            workWord3 -= workWord2;
            workWord2 = originalFrame.sp44;
            numeric4 += workWord3;
            Physics32Player68View1 = numeric4;
            numeric4 = Physics32Player70View1;
            workWord3 = (workWord2 * 48) >> 8;
            workWord2 = (numeric5 << 5) >> 9;
            workWord3 -= workWord2;
            numeric5 += workWord3;
            workWord2 = (numeric4 << 5) >> 9;
            Physics32Player6CView1 = numeric5;
            numeric4 -= workWord2;
            goto store70;
        default48:
            globalVector80 = &Physics32PlayerA8View1;
            call4 = globalVector80 - 16;
            workWord2 = Physics32Field(globalVector80, int*, 0);
            call5 = 0;
            workWord2 = -workWord2;
            signedWord20 = workWord2 << 3;
            workWord2 = Physics32MeasureVectorLengthView4(call4, call5);
            call4 = (void*)workWord2;
            call5 = (void*)Physics32PlayerA0View2;
            workWord2 = Physics32PlanarHeadingLookupView2(call4, call5, 1);
            signedWord19 = workWord2 & 4095;
            workWord2 = signedWord19 < 2049;
            if (!workWord2) {
                signedWord19 -= 4096;
                workWord2 = signedWord19 < -256;
            } else
                workWord2 = signedWord19 < -256;
            if (workWord2)
                signedWord19 = -256;
            workWord2 = Physics32Player5CView2;
            workWord2 = signedWord20 - workWord2;
            signedWord20 = workWord2 & 4095;
            workWord2 = signedWord20 < 2049;
            if (!workWord2)
                signedWord20 -= 4096;
            workWord2 = Physics32Player60View2;
            workWord2 -= signedWord19;
            signedWord19 = workWord2 & 4095;
            workWord2 = signedWord19 < 2049;
            if (!workWord2)
                signedWord19 -= 4096;
            workWord2 = signedWord20 < -256;
            if (workWord2) {
                signedWord20 = -256;
                MATCHING_KEEP(signedWord20);
                workWord2 = signedWord20 < 257;
            } else
                workWord2 = signedWord20 < 257;
            if (!workWord2)
                signedWord20 = 256;
            workWord2 = signedWord19 < -256;
            if (workWord2) {
                signedWord19 = -256;
                MATCHING_KEEP(signedWord19);
                workWord2 = signedWord19 < 257;
            } else
                workWord2 = signedWord19 < 257;
            if (!workWord2)
                signedWord19 = 256;
            workWord3 = (signedWord20 << 2) >> 4;
            numeric4 = Physics32Player68View1;
            signedWord21 = Physics32Field(globalVector80, int*, 0);
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
            workWord3 = signedWord19 << 2;
            Physics32Player68View1 = numeric4;
            numeric4 = Physics32Player6CView1;
            workWord3 >>= 4;
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
            workWord3 = signedWord21 << 2;
            Physics32Player6CView1 = numeric4;
            numeric4 = Physics32Player70View1;
            workWord3 >>= 4;
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
        store70:
            Physics32Player70View1 = numeric4;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = 4;
            signedWord20 = Physics32Player68View1;
            signedWord19 = Physics32Player6CView1;
            signedWord21 = Physics32Player70View1;
            workWord3 = Physics32Player4CView2;
            signedWord20 >>= 2;
            if (workWord3 == workWord2) {
                workWord2 = Physics32Data6E538View1 & 16;
                signedWord19 >>= 2;
                if (workWord2)
                    signedWord21 >>= 2;
            } else {
                workWord2 = 5;
                if (workWord3 == workWord2) {
                    signedWord21 >>= 2;
                    signedWord19 >>= 2;
                }
            }
            workWord2 = (unsigned int)(Physics32Player4CView2 - 4) < 2;
            globalVector80 = &originalFrame.sp60;
            if (workWord2) {
                call4 = Physics32Field(&Physics32Player0View4, void**, 0x250);
                if (call4) {
                    call4 = Physics32Field(call4, void**, 0);
                    workWord2 = Physics32Field(call4, int*, 0xF4);
                    workWord3 = Physics32Field(call4, int*, 0xFC);
                    workWord2 += signedWord20;
                    Physics32Field(call4, int*, 0xF4) = workWord2;
                    workWord2 = Physics32Field(call4, int*, 0xF8);
                    workWord3 += signedWord21;
                    Physics32Field(call4, int*, 0xFC) = workWord3;
                    workWord2 += signedWord19;
                    Physics32Field(call4, int*, 0xF8) = workWord2;
                }
            }
            call4 = globalVector80;
            globalVector8CState20 = &originalFrame.sp68;
            call5 = globalVector8CState20;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            savedPointer22 = &Physics32Player5CView2;
            workWord2 = Physics32Field(savedPointer22, int*, 0);
            workWord3 = Physics32Player64View2;
            __asm__ volatile("" ::"r"(workWord2), "r"(workWord3) : "$17", "memory");
            savedPointer17 = &originalFrame.sp80;
            Physics32Field(&originalFrame.sp60, short*, 0) = workWord2;
            workWord2 = Physics32Player60View2;
            call6 = savedPointer17;
            Physics32Field(&originalFrame.sp64, short*, 0) = workWord3;
            workWord2 = -workWord2;
            Physics32Field(&originalFrame.sp60, short*, 2) = workWord2;
            Physics32BuildEulerBasisPairView1(call4, call5, call6);
            Physics32TransposePackedHalfwordMatrix3x3View1(globalVector8CState20,
                                                           globalVector8CState20);
            call4 = globalVector80;
            call5 = savedPointer17;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            globalVector80 = &originalFrame.sp98;
            call6 = globalVector80;
            Physics32Field(&originalFrame.sp60, short*, 0) = signedWord20;
            Physics32Field(&originalFrame.sp60, short*, 2) = signedWord19;
            Physics32Field(&originalFrame.sp64, short*, 0) = signedWord21;
            Physics32BuildEulerBasisPairView1(call4, call5, call6);
            Physics32TransposePackedHalfwordMatrix3x3View1(savedPointer17, savedPointer17);
            Physics32MultiplyPackedGteMatricesView1(globalVector8CState20, savedPointer17,
                                                    globalVector80);
            Physics32WriteBasisAngleTripletView1(savedPointer22, globalVector80);
            workWord2 = Physics32Player164View1;
            if (workWord2) {
                workWord2 = 14208;
                Physics32PlayerACView3 = workWord2;
                workWord2 = 96;
                goto update16C;
            }
            workWord2 = 9280;
            Physics32PlayerACView3 = workWord2;
            workWord2 = 0;
        update16C:
            savedPointer17 = &Physics32Player16CView2;
            numeric5 = Physics32Player168View1;
            workWord3 = Physics32Field(savedPointer17, int*, 0);
            workWord2 -= numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics32Field(savedPointer17, int*, 0) = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics32Player168View1 = numeric5;
            if (numeric5 < 0)
                Physics32Player168View1 = 0;
            workWord2 = Physics32Player168View1;
            workWord2 = workWord2 < 97;
            call4 = (void*)576;
            if (!workWord2) {
                workWord2 = 96;
                Physics32Player168View1 = workWord2;
            }
            Physics32ApproachPlayerTargetSpeedView5(call4, 48);
            Physics32BuildPlayerMovementVectorView3();
            workWord3 = Physics32Player4CView2;
            workWord2 = 4;
            if (workWord3 != workWord2)
                goto maybeFive48;
            workWord2 = Physics32Data6E538View1 & 16;
            if (workWord2)
                goto subtract128;
            globalVector80 = &originalFrame.spB0;
            call4 = globalVector80;
            call5 = savedPointer17 - 236;
            __asm__ volatile(""
                             : "=r"(savedPointer17)
                             : "0"(savedPointer17), "r"(call4), "r"(call5)
                             : "memory");
            savedPointer17 -= 224;
            Physics32SubtractVectorView4(call4, call5, savedPointer17);
            originalFrame.spB8 = 0;
            call5 = (void*)Physics32MeasureVectorLengthView4(globalVector80, 0);
            workWord2 = (int)call5 < 385;
            call4 = savedPointer17;
            if (!workWord2) {
                Physics32ScaleVectorRatioQ15View4(globalVector80, call5, 384);
                call4 = savedPointer17;
            }
            call5 = call4;
            Physics32AddVectorView5(call4, call5, globalVector80);
        subtract128:
            globalPointer = &Physics32Player94View3;
            workWord2 = Physics32Field(globalPointer, int*, 0);
            workWord2 -= 128;
            Physics32Field(globalPointer, int*, 0) = workWord2;
            goto clampPhysics32PointerReady;
        maybeFive48:
            workWord2 = 5;
            if (workWord3 != workWord2)
                goto gate48;
            globalVector80 = &originalFrame.spC0;
            call4 = globalVector80;
            __asm__ volatile(""
                             : "=r"(savedPointer17)
                             : "0"(savedPointer17), "r"(call4)
                             : "memory");
            savedPointer17 -= 224;
            Physics32CopyVectorView6(call4, savedPointer17);
            originalFrame.spC8 = 0;
            call5 = (void*)Physics32MeasureVectorLengthView4(globalVector80, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics32ScaleVectorRatioQ15View4(globalVector80, call5, 64);
            workWord2 = 128;
            originalFrame.spC8 = workWord2;
            call4 = savedPointer17;
            call5 = call4;
            Physics32SubtractVectorView4(call4, call5, globalVector80);
            goto clampPhysics32;
        gate48:
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto flags48;
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto flags48;
            workWord2 = (int)Physics32Data6C570View3;
            workWord2 = Physics32Field((void*)workWord2, int*, 0) & 64;
            if (!workWord2)
                goto flags48;
            workWord2 = Physics32Player80View2;
            workWord3 = Physics32Player94View3;
            numeric4 = Physics32Player84View1;
            workWord3 -= 64;
            Physics32Player8CView2 = workWord2;
            Physics32Player90View1 = numeric4;
            Physics32Player94View3 = workWord3;
            goto clampPhysics32;
        flags48:
            call6 = &Physics32PlayerFCView1;
            workWord2 = Physics32Field(call6, unsigned char*, 0);
            if (workWord2)
                goto copy48;
            workWord2 = Physics32PlayerB8View2;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector48;
        copy48:
            workWord2 = Physics32Player80View2;
            workWord3 = Physics32PlayerA0View2;
            numeric4 = Physics32Player84View1;
            workWord3 -= 192;
            Physics32Player8CView2 = workWord2;
            Physics32Player90View1 = numeric4;
            Physics32Player94View3 = workWord3;
            Physics32PlayerA0View2 = workWord3;
            goto clampPhysics32;
        vector48:
            call5 = call6 - 124;
            Physics32AddVectorView5(call4, call5, call6 - 20);
            goto clampPhysics32;
        clampPhysics32:
            globalPointer = &Physics32Player94View3;
        clampPhysics32PointerReady:
            workWord2 = Physics32Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics32Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics32Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics32Field(call5, int*, 0) & 64;
            call4 = &originalFrame.spD0;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics32UpdateSmoothedInputPairView1(call4, call5, 0);
            workWord3 = Physics32Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics32Player60View1;
                numeric4 = Physics32Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric4 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.spD4 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.spD4 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                workWord2 = originalFrame.spD4;
                workWord3 = numeric4 + 1;
                Physics32Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.spD4 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics32Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.spD0 * 0x14) >> 7;
            Physics32Field(&Physics32Player0View3, int*, 0x64) =
                (int)((Physics32Field(&Physics32Player0View3, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics32Field(&Physics32Player0View3, int*, 0x60) +
                               ((int)(originalFrame.spD4 * -0xF) >> 7)) &
                              0xFFF;
            Physics32Field(&Physics32Player0View3, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics32Field(&Physics32Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x60) < -0x320) {
                Physics32Field(&Physics32Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x60) >= 0x321) {
                Physics32Field(&Physics32Player0View3, int*, 0x60) = 0x320;
            }
            if ((*Physics32Data6C570View2 & 0x40) ||
                (Physics32Field(&Physics32Player0View3, int*, 0x4C) == 1)) {
                Physics32Field(&Physics32Player0View3, int*, 0xAC) = 0xE00;
            } else {
                Physics32Field(&Physics32Player0View3, int*, 0xAC) = 0;
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x4C) == 2) {
                Physics32ApproachPlayerTargetSpeedView3(0xC0, 0xC0);
                if (Physics32Field(&Physics32Player0View3, int*, 0xB0) < 0xE01) {
                    Physics32Field(&Physics32Player0View3, int*, 0x4C) = 0;
                }
            } else {
                Physics32ApproachPlayerTargetSpeedView3(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics32Player0View3 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics32InterpolateCosineView3(
                                                Physics32Field(&Physics32Player0View3, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics32Field(&Physics32Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics32Field(&Physics32Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics32Field(&Physics32Player0View3, int*, 0x14C) + raw21_temp_a0_5;
            Physics32Field(&Physics32Player0View3, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics32Field(&Physics32Player0View3, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics32Field(&Physics32Player0View3, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics32Field(&Physics32Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x5C) < -0x300) {
                Physics32Field(&Physics32Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x5C) >= 0x301) {
                Physics32Field(&Physics32Player0View3, int*, 0x5C) = 0x300;
            }
            Physics32BuildPlayerMovementVectorView1(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics32CopyVectorView4(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics32CallRandView2() & 31;
            if (workWord2)
                goto block_130;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto block_130;
            call5 = (void*)44;
            call6 = &originalFrame.spD8;
            particleArg7 = 0;
            MATCHING_KEEP(particleArg7);
            workWord2 = 544;
            originalFrame.spD8 = workWord2;
            workWord2 = 64;
            originalFrame.spDC = 0;
            __asm__ volatile("" ::"i"(0x800987CC) : "memory");
            originalFrame.spE0 = workWord2;
            goto block_129;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics32Player0View3 + 0x20C;
            if (!(Physics32Field(&Physics32Player0View3, int*, 0x20C) & 0x40)) {
                if (Physics32Data6E044View2 != 7) {
                    Physics32UpdateSmoothedInputPairView1(&originalFrame.spD8,
                                                          raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.spD8;
                    numeric4 = originalFrame.spDC;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics32Player64View1;
                    workWord2 = Physics32Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics32Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics32Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics32Player60View1 = workWord2;
                    }
                    if (Physics32Field(&Physics32Player0View3, int*, 0x60) < -0x320) {
                        Physics32Field(&Physics32Player0View3, int*, 0x60) = -0x320;
                    }
                    if (Physics32Field(&Physics32Player0View3, int*, 0x60) >= 0x321) {
                        Physics32Field(&Physics32Player0View3, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics32InterpolateCosineView3(Physics32Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics32Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics32Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics32Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics32Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics32Player5CView1 = workWord2;
                    }
                    if (Physics32Field(&Physics32Player0View3, int*, 0x5C) < -0x300) {
                        Physics32Field(&Physics32Player0View3, int*, 0x5C) = -0x300;
                    }
                    if (Physics32Field(&Physics32Player0View3, int*, 0x5C) >= 0x301) {
                        Physics32Field(&Physics32Player0View3, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics32Player0View3 + 0x80;
                Physics32ClearVectorView2(raw21_temp_s0_9);
                Physics32ClearVectorView2(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics32CallRandView2() & 31;
                if (workWord2)
                    goto block_130;
                MATCHING_KEEP(workWord2);
                particleCall3 = Physics21_SpawnParticle;
                call4 = (void*)1;
                if (!particleCall3)
                    goto block_130;
                call5 = (void*)44;
                call6 = &originalFrame.spE8;
                particleArg7 = 0;
                MATCHING_KEEP(particleArg7);
                workWord2 = 544;
                originalFrame.spE8 = workWord2;
                workWord2 = 64;
                originalFrame.spEC = 0;
                originalFrame.spF0 = workWord2;
            block_129:
                particleCall3(call4, call5, call6, particleArg7);
            block_130:
                globalPointer = &Physics32Player158View1;
                workWord2 = Physics32Field(globalPointer, int*, 0);
                workWord2++;
                Physics32Field(globalPointer, int*, 0) = workWord2;
                return;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics32Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics32Field(call5, int*, 0) & 64;
            call4 = &originalFrame.spE8;
            if (!workWord2)
                goto run42;
        block_132:
            Physics32PlayerACView1 = 0;
            Physics32PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics32UpdateSmoothedInputPairView1(call4, call5, 0);
            workWord3 = Physics32Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics32Player60View1;
                numeric5 = Physics32Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.spEC = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.spEC = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.spEC;
                workWord3 = numeric5 + 1;
                Physics32Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.spEC = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics32Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics32Player0View3 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.spE8 * 0x14) >> 7;
            Physics32Field(&Physics32Player0View3, int*, 0x64) =
                (int)((Physics32Field(&Physics32Player0View3, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics32Field(&Physics32Player0View3, int*, 0x60) +
                                ((int)(originalFrame.spEC * -0xF) >> 7)) &
                               0xFFF;
            Physics32Field(&Physics32Player0View3, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics32Field(&Physics32Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x60) < -0x320) {
                Physics32Field(&Physics32Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x60) >= 0x321) {
                Physics32Field(&Physics32Player0View3, int*, 0x60) = 0x320;
            }
            Physics32Field(&Physics32Player0View3, int*, 0xAC) = 0x1C00;
            Physics32ApproachPlayerTargetSpeedView3(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics32InterpolateCosineView3(
                                                 Physics32Field(&Physics32Player0View3, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics32Field(&Physics32Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics32Field(&Physics32Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics32Field(&Physics32Player0View3, int*, 0x14C) + raw21_temp_a0_6;
            Physics32Field(&Physics32Player0View3, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics32Field(&Physics32Player0View3, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics32Field(&Physics32Player0View3, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics32Field(&Physics32Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x5C) < -0x300) {
                Physics32Field(&Physics32Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x5C) >= 0x301) {
                Physics32Field(&Physics32Player0View3, int*, 0x5C) = 0x300;
            }
            Physics32BuildPlayerMovementVectorView1(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics32CopyVectorView4(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics32Field(&Physics32Player0View3, int*, 0xB4) >= 0x7D1)) {
                originalFrame.spF8 = -0x190;
                originalFrame.spFC = 0x40 - (Physics32CallRandView2() & 0x7F);
                originalFrame.sp100 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.spF8, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics32Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics32Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            call4 = &Physics32Player80View1;
            MATCHING_KEEP(call4);
            Physics32ClearVectorView2(call4);
            call4 = &Physics32Player8CView1;
            MATCHING_KEEP(call4);
            Physics32ClearVectorView2(call4);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics32Data6E044View2;
            if (workWord3 == workWord2) {
                Physics32Field(&Physics32Player0View3, int*, 0xB0) = 0;
            } else {
                Physics32UpdatePlayerGroundInputTargetsView2(0x980);
                raw21_var_v0_2 = Physics32ApproachPlayerTargetHeadingView2(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics32Field(&Physics32Player0View3, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics32Field(&Physics32Player0View3, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics32ApproachPlayerTargetSpeedView3(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics32Player0View3 + 0xB0;
            if (Physics32Field(&Physics32Player0View3, int*, 0xB0) != 0) {
                Physics32BuildPlayerMovementVectorView1();
                Physics32BuildPlayerResponseVectorView2();
                Physics32Field(&Physics32Player0View3, int*, 0x94) = 0;
            } else {
                Physics32ClearVectorView2(raw21_temp_s0_11 - 0x30);
                Physics32ClearVectorView2(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics32Player0View3 + 0x28;
                if (Physics32Field(&Physics32Player0View3, int*, 0x28) < 0) {
                    if ((Physics32Field(&Physics32Player0View3, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics32Data6C640View1 & 1)) {
                        Physics32CopyVectorView4(&originalFrame.spF8, raw21_temp_s4 - 0x28);
                        originalFrame.sp10C = 0x40;
                        originalFrame.sp110 = 0;
                        originalFrame.sp108 =
                            (int)Physics32Field(&Physics32Player0View3, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp10C = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics32TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp108,
                                                             &originalFrame.sp118);
                        Physics32AddVectorView4(&originalFrame.spF8, &originalFrame.spF8,
                                                &originalFrame.sp118);
                        originalFrame.sp108 = 0;
                        originalFrame.sp100 = -Physics32Field(&Physics32Player0View3, int*, 0x28);
                        Physics32TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp108,
                                                             &originalFrame.sp108);
                        Physics32ShiftVectorRightTowardZeroView2(&originalFrame.sp108, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.spF8, &originalFrame.sp108);
                        if (!(Physics32CallRandView2() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.spF8, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics32Player0View3 + 0xB0;
                        if ((Physics32Field(&Physics32Player0View3, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics32Data6C640View1 & 7) &&
                            !(Physics32CallRandView2() & 3)) {
                            originalFrame.sp128 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp12C = 0;
                            originalFrame.sp130 = 0;
                            Physics32TransformVectorByBasisView2(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp128, &originalFrame.sp128);
                            Physics32AddVectorView4(&originalFrame.sp128, &originalFrame.sp128,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp130 =
                                -Physics32Field(&Physics32Player0View3, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp128, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics32Field(&Physics32Player0View3, int*, 0x144) -
                ((int)((Physics32Field(&Physics32Player0View3, int*, 0x148) * 2) +
                       (Physics32Field(&Physics32Player0View3, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics32Field(&Physics32Player0View3, int*, 0x148) + raw21_temp_a1_4;
            Physics32Field(&Physics32Player0View3, int*, 0x144) = raw21_temp_a1_4;
            Physics32Field(&Physics32Player0View3, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics32Field(&Physics32Player0View3, int*, 0x148) = 0x5900;
            }
            if (Physics32Field(&Physics32Player0View3, int*, 0x148) < -0x5900) {
                Physics32Field(&Physics32Player0View3, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 49: {
            register void* pointer17 __asm__("$17");
            register void* pointer18 __asm__("$18");
            register void* pointer16 __asm__("$16");
            int product49a, product49b;
            pointer17 = &Physics32Player210View1;
            workWord2 = Physics32Field(pointer17, int*, 0) & 1024;
            call6 = (void*)1;
            if (!workWord2)
                goto noFlag49;
            MATCHING_KEEP(pointer17);
            call4 = (void*)Physics32Field(pointer17, int*, 12);
            call5 = (void*)Physics32Player220View1;
            __asm__ volatile(""
                             : "=r"(pointer17)
                             : "0"(pointer17), "r"(call4), "r"(call5)
                             : "memory");
            pointer17 += 12;
            workWord2 = Physics32PlanarHeadingLookupView1(call4, call5, call6);
            pointer16 = &originalFrame.sp118;
            call4 = pointer16;
            Physics32Player148View1 = workWord2;
            Physics32CopyVectorView3(call4, pointer17);
            Physics32ShiftVectorLeftView1(pointer16, 6);
            workWord2 = Physics32MeasureVectorLengthView3(pointer16, 1);
            Physics32PlayerB0View2 = workWord2;
            call4 = (void*)128;
            goto prepare49;
        noFlag49:
            MATCHING_KEEP(call6);
            workWord2 = Physics32PlayerE4View1;
            workWord2 = workWord2 < 11;
            if (workWord2)
                goto lowMode49;
            call4 = (void*)Physics32PlayerCCView1;
            call5 = (void*)Physics32PlayerD0View1;
            __asm__ volatile("" ::"i"(0x800990CC) : "memory");
            call6 = (void*)1;
            goto query49;
        lowMode49:
            call4 = (void*)Physics32Player98View1;
            call5 = call4;
        query49:
            workWord2 = Physics32PlanarHeadingLookupView1(call4, call5, call6);
            Physics32Player148View1 = workWord2;
            call4 = (void*)128;
        prepare49:
            call5 = (void*)192;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            pointer18 = &Physics32PlayerACView2;
            workWord2 = 3840;
            Physics32Field(pointer18, int*, 0) = workWord2;
            Physics32ApproachPlayerTargetSpeedView2(call4, call5);
            call4 = (void*)Physics32Player148View1;
            pointer17 = pointer18 - 44;
            workWord2 = Physics32InterpolateCosineView2(call4);
            workWord3 = Physics32PlayerB0View2;
            product49a = workWord3 * workWord2;
            call4 = (void*)Physics32Player148View1;
            workWord2 = product49a >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp118 = workWord2;
            workWord2 = Physics32InterpolateSineView2(call4);
            workWord3 = Physics32PlayerB0View2;
            product49b = workWord3 * workWord2;
            pointer16 = &originalFrame.sp118;
            call4 = pointer16;
            call5 = pointer16;
            call6 = pointer17;
            originalFrame.sp120 = 0;
            workWord2 = product49b >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp11C = workWord2;
            Physics32SubtractVectorView3(call4, call5, call6);
            originalFrame.sp120 = 0;
            call5 = (void*)Physics32MeasureVectorLengthView3(pointer16, 0);
            workWord2 = (int)call5 < 257;
            call4 = pointer17;
            if (!workWord2) {
                Physics32ScaleVectorRatioQ15View3(pointer16, call5, 256);
                call4 = pointer17;
            }
            call5 = pointer17;
            Physics32AddVectorView3(call4, call5, pointer16);
            workWord2 = Physics32PlayerFCView2;
            if (workWord2)
                goto scalar49;
            workWord2 = Physics32PlayerB8View1;
            call4 = pointer18 - 32;
            if (!workWord2)
                goto vector49;
        scalar49:
            workWord2 = Physics32PlayerA0View1;
            workWord2 -= 192;
            goto store94From2;
        vector49:
            call5 = pointer17;
            Physics32AddVectorView3(call4, call5, pointer18 + 60);
            return;
        }
        case 0x39:
            if ((workWord2 = combinedIndex < 9) == 0) {
                Physics32Field(&Physics32Player0View3, int*, 0x80) =
                    (int)(Physics32Field(&Physics32Player0View3, int*, 0x8C) * 0xF8);
                Physics32Field(&Physics32Player0View3, int*, 0x84) =
                    (int)(Physics32Field(&Physics32Player0View3, int*, 0x90) * 0xF8);
                Physics32Field(&Physics32Player0View3, int*, 0x88) =
                    (int)(Physics32Field(&Physics32Player0View3, int*, 0x94) * 0xF8);
                Physics32ShiftVectorRightTowardZeroView2(&Physics32Player0View3 + 0x80, 8);
            }
        block_188:
            call4 = &Physics32Player0View3 + 0x8C;
            call5 = call4 - 12;
            Physics32CopyVectorView4(call4, call5);
            return;
        case 150:
        case 151: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta17 __asm__("$17");
            register void* pointer16 __asm__("$16");
            int product150;
            Physics32UpdateSmoothedInputPairView2(&originalFrame.sp138, &Physics32Player14CView1,
                                                  0);
            workWord2 = originalFrame.sp13C;
            workWord3 = workWord2 << 4;
            workWord2 -= workWord3;
            workWord3 = originalFrame.sp138;
            numeric5 = workWord2 >> 7;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            workWord3 = Physics32PlayerF4View1;
            delta17 = workWord2 >> 7;
            if (!workWord3)
                goto rotate150;
            numeric4 = Physics32Player60View1;
            if (numeric4 <= 0)
                goto rotate150;
            workWord2 = Physics32Player8View1;
            workWord3 -= workWord2;
            workWord2 = workWord3 - numeric4;
            workWord3 = workWord2 & 4095;
            workWord2 = workWord3 < 2049;
            if (workWord2)
                goto rotate150;
            workWord3 -= 4096;
            workWord3 >>= 2;
            workWord2 = workWord3 < numeric5;
            if (workWord2)
                numeric5 = workWord3;
        rotate150:
            call4 = &Physics32Player64View1;
            workWord2 = Physics32Field(call4, int*, 0);
            workWord3 = Physics32Player60View1;
            workWord2 += delta17;
            workWord2 &= 4095;
            workWord3 += numeric5;
            workWord3 &= 4095;
            Physics32Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics32Player60View1 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics32Player60View1 = workWord2;
            }
            workWord2 = Physics32Player60View1;
            workWord2 = workWord2 < -512;
            if (workWord2)
                Physics32Player60View1 = -512;
            workWord2 = Physics32Player60View1;
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics32Player60View1 = 512;
            workWord3 = Physics32Player48View1;
            workWord2 = 151;
            MATCHING_KEEP(workWord2);
            if (workWord3 == workWord2)
                workWord2 = 8192;
            else
                workWord2 = 1088;
            Physics32PlayerACView1 = workWord2;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord3 = Physics32Player48View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord3, "memory");
            workWord2 = 151;
            MATCHING_KEEP(workWord2);
            call4 = (void*)192;
            if (workWord3 == workWord2)
                call4 = (void*)384;
            Physics32ApproachPlayerTargetSpeedView4(call4, 48);
            pointer16 = &Physics32Player60View1;
            workWord2 = Physics32InterpolateCosineView4(Physics32Field(pointer16, int*, 0));
            workWord3 = workWord2 * 3;
            workWord3 <<= 3;
            workWord3 = -workWord3;
            product150 = delta17 * workWord3;
            workWord3 = Physics32Player14CView1;
            numeric5 = Physics32Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = product150 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics32Player14CView1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics32Player5CView1 = numeric5;
            if (!workWord2) {
                workWord2 = numeric5 - 4096;
                MATCHING_KEEP(workWord2);
                Physics32Player5CView1 = workWord2;
            }
            workWord2 = Physics32Player5CView1;
            workWord2 = workWord2 < -512;
            if (workWord2)
                Physics32Player5CView1 = -512;
            workWord2 = Physics32Player5CView1;
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics32Player5CView1 = 512;
            Physics32BuildPlayerMovementVectorView2();
            Physics32CopyVectorView5(pointer16 + 44, pointer16 + 32);
            workWord3 = Physics32PlayerF4View1;
            if (!workWord3)
                return;
            workWord2 = Physics32Player8View1;
            workWord2 = workWord3 - workWord2;
            workWord3 = Physics32Player94View2;
            workWord2 <<= 4;
            workWord3 = workWord2 < workWord3;
            if (!workWord3)
                return;
        store94From2:
            Physics32Player94View2 = workWord2;
            return;
        }
    }
}
#undef Physics32Field


/* AI generated; not human reviewed. SCUS-94467 8009953C..80099CDC.
 * Verified37 scalar/independent table,50 case24 and43 case31 routes reused
 * against original32 selectors, query negation and particle numeric writes.
 * Empty constraints preserve original lifetimes; helper meaning, units and
 * invocation cadence remain unresolved. Original800997B0..800997E0 supplies
 * query negation, V3 step and callback A0; shift6 occupies callback load delay.
 * Original8009985C..80099894 supplies final V0 callback, stack vectors30/20,
 * numeric returned bytes2=6 andA=32. These writes establish no helper contract.
 * Every code/table word, strict full TU and every retail hash must agree.
 */
extern int Callback32Step __asm__("D_80070328+0x144");
extern int Callback32Z __asm__("D_80070328+8");
extern int Callback32Limit __asm__("D_80070328+0x280");
extern Spyro Callback32Player __asm__("D_80070328");
int Callback32SamplePlanarPhaseTable(int x, int y) __asm__("func_80037058");
int Callback32SoundHandleMatchesIdInStates1Or2(int soundId, int index) __asm__("func_8003BF6C");
void Callback32ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback32CapturePlayerPlanarVectorDifference(void) __asm__("func_80041AE8");
void Callback32UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback32UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
void Callback32BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
extern int D_8006FA38, D_8006C648;
int Callback32Query(Vector3D*, int) __asm__("func_8001A358");
extern int Callback32Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback32Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback32Values[] __asm__("D_8006FCF0");
void Callback32MarkPlayerSegmentSurfaceType3Flags(void) __asm__("func_80049590");
extern int D_8006C640;
extern int Callback32Word8006E538 __asm__("D_8006E538");
int Callback32RandSignedBetween(int, int) __asm__("func_800363DC");
void func_level_32_8009953C(void) {
    struct {
        Vector3D first;
        int reserved1C;
        Vector3D second;
        int reserved2C;
        Vector3D third;
        int reserved3C;
    } local;
    register Vector3D* playerPosition __asm__("$17");
    register Vector3D* particlePosition __asm__("$16");
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

    switch (Callback32Player.animationState) {
        case 0x14:
            if (func_800438F4() == 0)
                func_80043728();
            Callback32UpdatePlayerCollisionResponse();
            Callback32Player.unk9a = 0;
            goto call42A44;
        case 0x35:
        case 0x36:
        case 0x96:
        case 0x97:
            Callback32UpdatePlayerCollisionResponse();
        call42A44:
            Callback32UpdatePlayerSurfaceState();
        clearSharedValue:
            Callback32Player.unk4[0] = 0;
            return;
        case 0x9:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            if (Callback32Player.unk5 == 1)
                Callback32ProbePlayerContactSegment();
            else
                Callback32BuildNegatedNormalizedPlayerVector(0xC00);
            if ((unsigned char)Callback32Player.bodyAnimation.nextFrame < 10) {
                Callback32Player.cheatColour.a = 255;
                if (Callback32Player.bodyAnimation.nextFrame & 1) {
                    Callback32Player.cheatColour.b = 255;
                    Callback32Player.cheatColour.g = 255;
                    Callback32Player.cheatColour.r = 255;
                } else {
                    Callback32Player.cheatColour.b = 64;
                    Callback32Player.cheatColour.g = 64;
                    Callback32Player.cheatColour.r = 64;
                }
            }
            goto clearSharedValue;
        case 0x13:
        case 0x15:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            Callback32ProbePlayerContactSegment();
            goto clearSharedValue;
        case 0x1C:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            Callback32ProbePlayerContactSegment();
            if (Callback32Player.unk7a[3].z < 0 && Callback32Player.animationStateFrames >= 4)
                Callback32Player.unk5 = 1;
            goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5") = &Callback32Z;
            register int velocity __asm__("$6") = Callback32Step;
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
            status = Callback32Limit;
            velocity += tick;
            Callback32Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback32Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback32Step = 0x2580;
            }
        limitsDone:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            playerPosition = &Callback32Player.position;
            func_8004F178(&local.first, playerPosition);
            local.first.z += 0x400;
            {
                register int result __asm__("$2") = Callback32Query(&local.first, 0xC00);
                register int step __asm__("$3") = Callback32Step;
                register int z __asm__("$2");
                register char* (*callback)(int, int, Vector3D*, Vector3D*)__asm__("$4");
                __asm__("" : "=r"(step) : "0"(step), "r"(result));
                result = -result;
                Callback32Player.unk4[0] = result;
                z = Callback32Z;
                callback = SpawnParticle;
                MATCHING_KEEP_VOLATILE_CLOBBER(step, "memory");
                step >>= 6;
                z -= step;
                Callback32Z = z;
                if (callback == 0)
                    return;
            }
            if (D_8006C640 & 1) {
                register int sample __asm__("$2");
                register int component __asm__("$3");
                register int kind __asm__("$4");
                register int subtype __asm__("$5");
                register Vector3D* position __asm__("$6");
                register Vector3D* vector __asm__("$7");
                register char* (*particles)(int, int, Vector3D*, Vector3D*)__asm__("$2");
                register char* returned __asm__("$2");
                particlePosition = &local.third;
                local.second.x = 0;
                local.second.y = 0;
                local.second.z = 14;
                func_8004F178(particlePosition, playerPosition);
                sample = Callback32RandSignedBetween(0, 300);
                component = local.third.x + sample;
                MATCHING_KEEP(component);
                local.third.x = component;
                sample = Callback32RandSignedBetween(0, 300);
                component = local.third.y + sample;
                MATCHING_KEEP(component);
                local.third.y = component;
                sample = Callback32RandSignedBetween(0, 300);
                kind = 1;
                subtype = 0x3A;
                MATCHING_KEEP3_CLOBBER(kind, subtype, sample, "memory");
                component = local.third.z;
                MATCHING_BARRIER_VOLATILE("memory");
                position = particlePosition;
                __asm__("" : "=r"(position) : "0"(position), "r"(sample));
                component += sample;
                __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                particles = SpawnParticle;
                MATCHING_KEEP_VOLATILE_CLOBBER(particles, "$7");
                vector = &local.second;
                MATCHING_KEEP3(particles, vector, component);
                local.third.z = component;
                returned = particles(kind, subtype, position, vector);
                returned[2] = 6;
                returned[10] = 32;
            }
            return;
        }
        case 0x24:
        case 0x25:
        case 0x30:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            Callback32BuildNegatedNormalizedPlayerVector(0xC00);
            if ((Callback32Player.ticksSinceLastSurfaceTouch == 0) &&
                (func_80040954(Callback32Player.unk11[2]) == 9)) {
                func_8004F178(
                    (Vector3D*)((unsigned char*)&Callback32Player.ticksSinceLastSurfaceTouch +
                                0x94),
                    (Vector3D*)((unsigned char*)&Callback32Player.ticksSinceLastSurfaceTouch +
                                0x14));
                Callback32Player.union144.a.unk13da = Callback32Player.unk7a[3].z;
            }
            Callback32Player.unk4[0] = 0;
            if ((Callback32Player.unk5 == 1) && ((Callback32Player.animationStateFrames >= 0xD) ||
                                                 !(Callback32Word8006E538 & 0x40))) {
                Callback32Player.unk5 = 2;
            }
            if (Callback32Player.unk5 != 3) {
                Callback32Player.union144.a.unk13db.x = 0;
                Callback32Player.union144.a.unk13db.y = 0;
                return;
            }
            break;
        case 0x28:
        case 0x29:
        case 0x39:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            descriptor = &Callback32Player.unk22[2];
            if (Callback32SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback32Values + valueOffset);
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
                *(int*)(Callback32Values + valueOffset) = tableValue;
            setDecreasingFlag:
                flagOffset = *descriptor * 0x2C;
                Callback32Flags[flagOffset] = Callback32Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x2A:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            Callback32MarkPlayerSegmentSurfaceType3Flags();
            descriptor = &Callback32Player.unk22[2];
            if (Callback32SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback32Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback32Player.unk22[2];
            }
            if (Callback32SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback32Values + valueOffset);
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
                *(int*)(Callback32Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback32Flags[flagOffset] = Callback32Flags[flagOffset] | 0x10;
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            Callback32CapturePlayerPlanarVectorDifference();
            if ((unsigned char)Callback32Player.unk10[4] != 0) {
                computedValue = -Callback32Player.unk9ha[4] -
                                Callback32SamplePlanarPhaseTable(Callback32Player.position.x,
                                                                 Callback32Player.position.y);
                positionValue = Callback32Player.unk4a - computedValue;
                Callback32Player.unk4[0] = computedValue;
                positionDelta = (int)Callback32Player.union144.a.unk13cc >> 6;
                positionValue -= positionDelta;
                MATCHING_KEEP(positionValue);
                Callback32Player.position.z = positionValue;
                return;
            }
            break;
        case 0x31:
            Callback32UpdatePlayerCollisionResponse();
            Callback32UpdatePlayerSurfaceState();
            Callback32BuildNegatedNormalizedPlayerVector(0xC00);
            if (func_80040954(Callback32Player.unk11[2]) == 0xA) {
                Callback32Player.union144.a.unk13cb = 0;
            } else {
                Callback32Player.union144.a.unk13cb += D_8006C648;
            }
            Callback32Player.unk4[0] = 0;
            if (Callback32SoundHandleMatchesIdInStates1Or2((int)D_8006C654->unk32,
                                                           Callback32Player.unk22[2]) == 0) {
                Callback32Player.unk22[2] = PlaySound((int)D_8006C654->unk32, 0, 4);
                Callback32Player.unk22[3] = (int)D_8006C654->unk32;
                return;
            }
            break;
        default:
            return;
    }
}


#define LEVEL_ID 32
#define PlaySpyroSounds_level_32 func_level_32_80099CE0
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_32_80099E1C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0xa:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1d:
        case 0x1f:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2d:
        case 0x2e:
        case 0x2f:
        case 0x30:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0x5c:
        case 0x5d:
        case 0x5e:
        case 0x5f:
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
        case 0x6c:
        case 0x6d:
        case 0x6e:
        case 0x6f:
        case 0x70:
        case 0x71:
        case 0x72:
        case 0x73:
        case 0x74:
        case 0x75:
        case 0x76:
        case 0x77:
        case 0x78:
        case 0x79:
        case 0x7a:
        case 0x7b:
        case 0x7c:
        case 0x7d:
        case 0x7e:
        case 0x7f:
        case 0x80:
        case 0x81:
        case 0x82:
        case 0x83:
        case 0x84:
        case 0x85:
        case 0x86:
        case 0x87:
        case 0x88:
        case 0x89:
        case 0x8a:
        case 0x8b:
        case 0x8c:
        case 0x8d:
        case 0x8e:
        case 0x8f:
        case 0x90:
        case 0x91:
        case 0x92:
        case 0x93:
        case 0x94:
        case 0x95:
        case 0x96:
        case 0x97:
            break;

        case 0x9: {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0x4C);
            MATCHING_KEEP(state);
            if (*state == 1)
                func_80043ABC(0);
            else
                func_80043ABC((Vector3D*)((char*)state + 0x80));
        } break;
        case 0x14:
        case 0x1e:
        case 0x2b:
        case 0x2c:
        case 0x31:
        case 0x35:
        case 0x36:
            func_80043ABC(&spyro.unk9e);
            break;
        case 0x13:
        case 0x15:
        case 0x1c:
            func_80043ABC(0);
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80099EB8.
 * Reuses verified41 water/swirl/slide/table,12 helper9 producer,22 numeric15
 * and skateboard,37 vector/drowning. Original32 helper input10C, vector8C/98
 * or flags400 copy21C/scale6/signed table; independent35/36; skateboard scalar
 * 2440 minimum and separate130 flag20000;96/97 animation<96 helper14C/98 route.
 * Numeric offsets are bytes. Word60 wrap/clamp vectors800/801/FFF give0/-7FF/-1.
 * Original widths/shifts/branches and empty constraints preserve instructions.
 * Require every code/internal jump/owned table word, strict full TU and all
 * retail hashes. Helper/audio semantics, units, cadence and live parity are open.
 */
extern int D_8006C700;
int Call32InterpolateSine(int) __asm__("func_8004E9E4");
int Call32InterpolateCosine(int) __asm__("func_8004EA2C");
extern int Transition32_D_8006E528 __asm__("D_8006E528");
void Transition32ShiftVectorLeft(Vector3D*, int) __asm__("func_8004F0E8");
int Transition32GetSurfaceTypeFromFlags(int) __asm__("func_80040954");
extern int Transition32RawX __asm__("D_80070328+0x8C");
extern short Transition32SignedB[] __asm__("D_80065920");
extern short Transition32SignedA[] __asm__("D_800658A0");
extern Spyro Transition32_D_80070328 __asm__("D_80070328");
int Transition32MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition32ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition32_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition32RawUnion[] __asm__("D_80070328+0x144");
extern int Transition32RawMovement __asm__("D_80070328+0x50");
extern void (*Call32Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw32State[] __asm__("D_80070328+0x50");
extern short Signed32TableA[] __asm__("D_800658A0");
extern short Signed32TableB[] __asm__("D_80065920");

extern int D_80071934;
int Call32QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
extern int Raw32NegativeWord __asm__("D_80070328+0x28");
extern int Raw32TableIndex __asm__("D_80070328+0x298");
extern int Raw32Yaw __asm__("D_80070328+0x64");
int Transition32RandBetween(int, int) __asm__("func_8003636C");
void Transition32ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Transition32BuildNegatedNormalizedPlayerVector(int) __asm__("func_80043A38");
int Transition32PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void func_level_32_80099EB8(int arg0) {
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

    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register int oldMovementA __asm__("$3");
    register int oldMovementB __asm__("$3");
    register int flags __asm__("$2");
    register unsigned char* header __asm__("$17");
    register int* sourceA __asm__("$16");
    int* sourceB;
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    int shiftedValue;
    switch (arg0) {
        case 0x14:
            Transition32_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition32_D_80070328.unk5 = 0;
            Transition32ClearPlayerMotionVectors();
            Transition32_D_80070328.grounded = 1;
            Transition32_D_80070328.union144.a.unk13cb = Transition32RandBetween(1, 3);
            Transition32_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x35:
            Transition32_D_80070328.movementState = 0;
            Transition32_D_80070328.unk5 = 0;
            Transition32ClearPlayerMotionVectors();
            Transition32_D_80070328.grounded = 1;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x9:
            header = (unsigned char*)&Transition32_D_80070328.unk11[2];
            if (Transition32GetSurfaceTypeFromFlags(*(int*)header) == 7) {
                sourceA = (int*)(header - 0x74);
                oldMovementA = Transition32RawMovement;
                Transition32RawMovement = MOVEMENT_STATE_HURT;
                Transition32_D_80070328.unk5 = 1;
                Transition32_D_80070328.union144.a.unk13cb = oldMovementA;
                func_8004F178((Vector3D*)(header - 0x80), (Vector3D*)sourceA);
                Transition32_D_80070328.unk8[0] =
                    Transition32MeasureVectorLength((Vector3D*)sourceA, 0);
                Transition32_D_80070328.unk7a[2].z = 0xDC0;
                Transition32_D_80070328.grounded = 0;
            } else {
                oldMovementB = Transition32RawMovement;
                flags = Transition32_D_80070328.unk17a;
                MATCHING_KEEP2(oldMovementB, flags);
                Transition32RawMovement = MOVEMENT_STATE_HURT;
                Transition32_D_80070328.unk5 = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(flags, "memory");
                Transition32_D_80070328.union144.a.unk13cb = oldMovementB;
                sourceB = (int*)(header - 0x80);
                if (flags & 0x400) {
                    func_8004F178((Vector3D*)sourceB, (Vector3D*)(header + 0x110));
                    Transition32ShiftVectorLeft((Vector3D*)sourceB, 6);
                } else if (Transition32_D_80070328.unk22[5] >= 0) {
                    tableIndex = Transition32_D_80070328.unk22[5] * 2;
                    tableValue = *(short*)((unsigned char*)Transition32SignedB + tableIndex);
                    MATCHING_KEEP(tableValue);
                    Transition32RawX = tableValue >> 1;
                    tableIndex = *(short*)((unsigned char*)Transition32SignedA + tableIndex);
                    Transition32_D_80070328.unk7a[2].z = 0;
                    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableIndex, "memory");
                    Transition32_D_80070328.unk7a[2].y = tableIndex >> 1;
                } else {
                    MATCHING_KEEP(header);
                    destination = (Vector3D*)(header - 0x80);
                    Transition32ClearVector(destination);
                }
                func_8004F178(&Transition32_D_80070328.unk7a[1],
                              (Vector3D*)((unsigned char*)&Transition32_D_80070328.unk7a[1] + 0xC));
                Transition32BuildNegatedNormalizedPlayerVector(0xC00);
                Transition32_D_80070328.grounded = 1;
            }
            Transition32_D_8006E528 = 0x2D;
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
            stateBase = (unsigned char*)&Transition32RawMovement;
            privateData = Transition32_D_80070328.m_WhirlwindPointer->mobyTag;
            *(int*)stateBase = 14;
            Transition32_D_80070328.unk5 = 0;
            Transition32_D_80070328.grounded = 0;
            Transition32ClearVector((Vector3D*)(stateBase + 0x3C));
            sourceMoby = Transition32_D_80070328.m_WhirlwindPointer;
            yawValue = Transition32_D_80070328.rotation.yaw;
            positionZ = Transition32_D_80070328.position.z;
            heightValue = sourceMoby->position.z;
            privateValue = *(int*)privateData;
            MATCHING_KEEP4(sourceMoby, yawValue, positionZ, heightValue);
            Transition32_D_80070328.union144.a.unk13cc = yawValue;
            Transition32_D_80070328.union144.a.unk13cb = positionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue += privateValue;
            Transition32_D_80070328.union144.a.unk13ce.x = heightValue;
            heightValue -= positionZ;
            heightValue -= 0x800;
            Transition32_D_80070328.union144.a.unk13ce.z = heightValue;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue = ((int)(heightValue << 0xA) >> 0xA) + 0x400;
            MATCHING_KEEP(heightValue);
            Transition32_D_80070328.union144.a.unk13ce.y = heightValue;
            maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
            Transition32_D_80070328.union144.a.unk13ce.y = maskedValue;
            if (maskedValue >= 0x801) {
                Transition32_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
            }
            Transition32_D_80070328.union144.a.unk13da = *(int*)(privateData + 4);
            func_8004F178((Vector3D*)(stateBase + 0x10C), &sourceMoby->position);
            Transition32_D_80070328.unk13e[0] =
                (int)Transition32_D_80070328.m_WhirlwindPointer->angle.yaw;
            positionZ = *(int*)(privateData + 8);
            MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
            Transition32_D_80070328.unk20a = 0;
            Transition32_D_80070328.critterMobyPtr = 0;
            Transition32_D_80070328.unk13e[1] = positionZ;
            return;
        }
        case 0x15:
            Transition32_D_80070328.movementState = 7;
            Transition32_D_80070328.grounded = 0;
            Transition32_D_80070328.unk5 = 0;
            if (Transition32_D_80070328.unk17a & 0x490) {
                register int first __asm__("$2") = Transition32_D_80070328.unk17e.x;
                register int second __asm__("$3") = Transition32_D_80070328.unk17e.z;
                register int third __asm__("$2");
                MATCHING_KEEP2(first, second);
                first <<= 6;
                Transition32_D_80070328.unk7a[2].x = first;
                MATCHING_BARRIER_VOLATILE("memory");
                third = Transition32_D_80070328.unk17e.y;
                MATCHING_KEEP2(third, second);
                second <<= 6;
                Transition32_D_80070328.unk7a[2].z = second;
                MATCHING_KEEP_VOLATILE_CLOBBER(third, "memory");
                third <<= 6;
                Transition32_D_80070328.unk7a[2].y = third;
            } else {
                shiftedValue = Transition32PlanarHeadingLookup(
                    -Transition32_D_80070328.unk7a[2].x, -Transition32_D_80070328.unk7a[2].y, 1);
                Transition32_D_80070328.unk7b = shiftedValue;
                Transition32_D_80070328.unk7a[2].x =
                    (Call32InterpolateCosine(shiftedValue) << 12) >> 12;
                Transition32_D_80070328.unk7a[2].y =
                    (Call32InterpolateSine(Transition32_D_80070328.unk7b) << 12) >> 12;
                Transition32_D_80070328.unk7a[2].z = 0x1000;
            }
            goto clearPointers;
        case 0x1C:
            savedBase = Transition32RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition32RawMovement;
            Transition32RawMovement = MOVEMENT_STATE_HURT;
            Transition32_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition32_D_80070328.unk8[0] = Transition32MeasureVectorLength(sourceC, 0);
            Transition32_D_80070328.unk7a[2].z = 0xDC0;
            Transition32_D_80070328.grounded = 0;
            Transition32_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition32_D_80070328.damageFlags & 0x200) {
                Transition32_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition32_D_80070328.union144.a.unk13cc = 1;
                soundSelector = D_8006C654->lavaBurn;
                soundZero = 0;
                goto sharedSound;
            }
            goto clearPointers;
        case 0x1E: {
            register int oldState __asm__("$3") = Transition32RawMovement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Transition32RawMovement = value;
            value = 1;
            MATCHING_KEEP(value);
            Transition32_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Transition32_D_8006E524 = value;
            stateWord = (int*)Transition32RawUnion;
            MATCHING_KEEP(stateWord);
            Transition32_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Transition32_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            value = (int)D_8006C654->drown;
            MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
            Transition32_D_80070328.unk20a = 0;
            Transition32_D_80070328.critterMobyPtr = 0;
            Transition32_D_80070328.unk22[3] = value;
            return;
        }
        case 0x24:
        case 0x25:
        case 0x30: {
            register unsigned char* state __asm__("$16") = Raw32State;
            register int kind __asm__("$17");
            register int previous __asm__("$2") = *(int*)state;
            register int currentScalar __asm__("$2");
            register int scalar __asm__("$3");
            register int savedRoll __asm__("$3");
            MATCHING_KEEP(previous);
            kind = 19;
            MATCHING_KEEP(kind);

            destination = (Vector3D*)(state + 0x48);
            if (previous != kind) {
                Transition32_D_80070328.union144.a.unk13db.z = 0;
                Transition32_D_80070328.unk5 = 0;
                Transition32ClearVector((Vector3D*)(state + 0xFC));
                Transition32_D_80070328.union144.a.unk13da = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(state, "memory");
                destination = (Vector3D*)(state + 0x48);
            }
            *(int*)state = kind;
            Transition32_D_80070328.unk8[0] = Transition32MeasureVectorLength(destination, 0);
            currentScalar = D_8006C700;
            MATCHING_KEEP(currentScalar);
            scalar = 0x2440;
            MATCHING_KEEP(scalar);
            Transition32_D_80070328.horizontalSpeed = scalar;
            MATCHING_KEEP_VOLATILE_CLOBBER(currentScalar, "memory");
            if (currentScalar < 0x2440)
                D_8006C700 = scalar;
            Transition32BuildNegatedNormalizedPlayerVector(0xC00);
            savedRoll = Transition32_D_80070328.rotation.roll;
            MATCHING_KEEP(savedRoll);
            Transition32_D_80070328.grounded = 1;
            Transition32_D_80070328.unk15c = 0;
            Transition32_D_80070328.union144.a.unk13cc = 0;
            Transition32_D_80070328.union144.a.unk13db.x = 0;
            Transition32_D_80070328.union144.a.unk13db.y = 0;
            Transition32_D_80070328.unk13a[0] = 0x20000;
            Transition32_D_80070328.union144.a.unk13cb = savedRoll;
            return;
        }
        case 0x28:
        case 0x29:
            if (((unsigned)(Transition32_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition32_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition32_D_80070328.movementState - 0x50));
                    if ((Transition32_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw32NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition32_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call32QueryWorldHeight(&vectors.first, 0x800);
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
                firstWrappedWord = Transition32_D_80070328.rotation.pitch & 0xFFF;
                Transition32_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition32_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition32_D_80070328.rotation.pitch > 0) {
                    Transition32_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition32_D_80070328.unk5 = 1;
                }
                Transition32ClearVector(
                    (Vector3D*)((unsigned char*)&Transition32_D_80070328.rotation.pitch + 0xEC));
                Transition32_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition32_D_80070328.unk8[0] = Transition32MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition32_D_80070328.rotation.pitch + 0x38), 0);
                Transition32_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition32_D_80070328.animationState == 0x2A) {
                Transition32_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition32_D_80070328.union144.a.unk13da = 0;
            }
            Transition32_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition32_D_80070328.unk20a = 0;
            Transition32_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw32State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw32NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition32_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call32QueryWorldHeight(localVector, 0x800);
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
                if (Transition32_D_80070328.animationState == 0x2E) {
                    Transition32_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition32_D_80070328.rotation.pitch & 0xFFF;
                Transition32_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition32_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition32_D_80070328.rotation.pitch > 0) {
                    Transition32_D_80070328.rotation.pitch = 0;
                }
                Transition32_D_80070328.unk5 = 1;
                Transition32ClearVector(
                    (Vector3D*)((unsigned char*)&Transition32_D_80070328.animationState + 0x104));
                Transition32_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition32_D_80070328.unk8[0] = Transition32MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition32_D_80070328.animationState + 0x50), 0);
                Transition32_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition32_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition32_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition32RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition32RawUnion;
                    *(int*)unionPointer = (-Transition32_D_80070328.unk7a[2].z) >> 2;
                    if (Transition32RawMovement != 8) {
                        Transition32_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition32RawMovement = 10;
                    }
                    Transition32_D_80070328.unk5 = 0;
                    Transition32_D_80070328.unk8[0] =
                        Transition32MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition32_D_80070328.grounded = 1;
                    Transition32_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call32QueryWorldHeight(localVector, 0x800);
                    vectors.third.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, localVector, 0);
                        SpawnParticle(6, 0x2E, localVector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        case 0x31: {
            register unsigned char* lengthBase __asm__("$5") =
                (unsigned char*)&Transition32_D_80070328.unk8[0];
            register int valueA __asm__("$4");
            register int valueB __asm__("$5");
            register int valueKind __asm__("$6");
            *(int*)lengthBase = 0;
            if (Transition32_D_80070328.animationState == 0xD ||
                Transition32_D_80070328.movementState == 1)
                func_8004F178((Vector3D*)(lengthBase - 0x30), (Vector3D*)(lengthBase - 0x18));
            else
                Transition32ClearVector((Vector3D*)(lengthBase - 0x30));
            func_8004F178(&Transition32_D_80070328.unk7a[2],
                          (Vector3D*)((unsigned char*)&Transition32_D_80070328.unk7a[2] - 0xC));
            Transition32_D_80070328.movementState = 17;
            Transition32_D_80070328.unk5 = 0;
            Transition32BuildNegatedNormalizedPlayerVector(0xC00);
            Transition32_D_80070328.grounded = 0;
            Transition32_D_80070328.union144.a.unk13cb = 0;
            valueKind = 1;
            if (Transition32_D_80070328.unk9ha[0] >= 11) {
                valueA = Transition32_D_80070328.unk9e.x;
                valueB = Transition32_D_80070328.unk9e.y;
            } else {
                valueA = Transition32_D_80070328.unk7a[3].x;
                valueB = valueA;
            }
            Transition32_D_80070328.union144.a.unk13cc =
                Transition32PlanarHeadingLookup(valueA, valueB, valueKind);
            goto clearPointers;
        }
        case 0x36:
            Transition32_D_80070328.movementState = 0;
            Transition32_D_80070328.unk5 = 0;
            Transition32ClearPlayerMotionVectors();
            Transition32_D_80070328.grounded = 1;
            goto clearPointers;
        case 0x39: {
            register int previousMovement __asm__("$2") = Transition32RawMovement;
            register int numericKind __asm__("$3");
            register int indexWord __asm__("$3");
            register unsigned char* unionPointer __asm__("$5");
            register int tableOffset __asm__("$2");
            register int tableWord __asm__("$3");
            MATCHING_KEEP(previousMovement);
            numericKind = 7;
            MATCHING_KEEP(numericKind);
            Transition32RawMovement = numericKind;
            MATCHING_BARRIER_VOLATILE("memory");
            indexWord = Raw32TableIndex;
            MATCHING_KEEP_VOLATILE_CLOBBER(indexWord, "memory");
            unionPointer = Transition32RawUnion;
            MATCHING_KEEP2_CLOBBER(indexWord, unionPointer, "memory");
            Transition32_D_80070328.unk5 = 0;
            *(int*)unionPointer = previousMovement;
            if (indexWord < 0)
                Raw32TableIndex = ((Raw32Yaw + 0x800) >> 4) & 0xFF;
            tableOffset = Raw32TableIndex * 2;
            tableWord = *(short*)((unsigned char*)Signed32TableB + tableOffset);
            destination = (Vector3D*)(unionPointer - 0xC4);
            *(int*)(unionPointer - 0xB8) = tableWord;
            tableOffset = *(short*)((unsigned char*)Signed32TableA + tableOffset);
            Transition32_D_80070328.unk7a[2].z = 0;
            Transition32_D_80070328.unk7a[2].y = tableOffset;
            func_8004F178(destination, (Vector3D*)(unionPointer - 0xB8));
            Transition32_D_80070328.grounded = 1;
            Transition32_D_8006E524 = 15;
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
            Transition32_D_80070328.unk20a = 0;
            Transition32_D_80070328.critterMobyPtr = 0;
            return;
        case 0x96:
        case 0x97: {
            register unsigned char* animation __asm__("$16") =
                (unsigned char*)&Transition32_D_80070328.animationState;
            if (*(int*)animation < 0x96) {
                Transition32ClearVector((Vector3D*)(animation + 0x104));
                Transition32_D_80070328.union144.a.unk13cb = 0;
                Transition32_D_80070328.unk8[0] =
                    Transition32MeasureVectorLength((Vector3D*)(animation + 0x50), 0);
                Transition32_D_80070328.grounded = 1;
                Transition32_D_80070328.union144.a.unk13da = 0;
                Transition32_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            }
            return;
        }
        default:
            return;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8009ACBC.
 * Assembly SHA256 4caa0e9300a9f33cb13b5c73edd66ad89a44be6e6f0004b19dafc8d80bd26320.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1407 original instructions and143 state-table entries (bias9).
 * Original9/31/96/97 branches, shared selector calls, indirect callback,
 * saved-value phases, signed products, raw fields and complete exits match.
 * FrameA8 retains eight four-word scratch slots atSP10,20,...80 and the
 * original saved S0..S3/RA positions. No field/helper meanings are inferred.
 * View names retain distinct original typed aliases; their exact assembly
 * symbol identities and donor sources are recorded in the provenance file.
 * Empty metadata consumes initialized values and original source addresses,
 * emits no CPU instructions and retains the original distinct branch joins.
 * C emits every CPU word through the unchanged compiler/assembler/pipeline
 * and flags. Original padding and every acceptance gate remain unchanged.
 * Raw physical units/fixed point, helper/callback contracts and invocation
 * cadence remain unresolved. Cadence per invocation; rate unknown.
 * Falsification: every original native/linked word, conditional/internal
 * target, selector/data record and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim32Player48View1 __asm__("D_80070328 + 0x48");
extern unsigned char* Anim32Player250View1 __asm__("D_80070328 + 0x250");
extern int Anim32Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim32Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim32Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim32PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim32PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim32PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim32PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim32PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim32PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim32PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim32PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim32Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim32Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim32Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim32PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim32Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim32Player158View1 __asm__("D_80070328 + 0x158");
extern int Anim32Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim32Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim32Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim32Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim32Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim32Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim32Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim32Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim32PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim32Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim32Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim32Data66530View1[] __asm__("D_80066530");
extern int Anim32Data6E538View1 __asm__("D_8006E538"), Anim32Data6E53CView1 __asm__("D_8006E53C");
extern int Anim32Data6E044View1 __asm__("D_8006E044"), A4898Gate __asm__("D_8006E344"),
    A4898Count __asm__("D_8006C514");
extern int (*Anim32Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim32Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim32Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim32Data6FA38View1 __asm__("D_8006FA38");
int Anim32SoundHandleMatchesIdInStates1Or2View1() __asm__("func_8003BF6C");
int Anim32TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Anim32ProcessPlayerStateFlagsView1() __asm__("func_80040994");
int Anim32DispatchPlayerStateRequestView1() __asm__("func_8004BEF8");
int Anim32SelectPlayerAnimationLoopRequestView1() __asm__("func_80049688");
int Anim32UpdatePlayerRetryStateView1() __asm__("func_800498C0");
extern int Anim32Player10CView1 __asm__("D_80070328 + 0x10C");
int Anim32GetSurfaceTypeFromFlagsView1() __asm__("func_80040954");
extern int Anim32PlayerBCView1 __asm__("D_80070328 + 0xBC");
extern int Anim32Player160View1 __asm__("D_80070328 + 0x160");
extern int Anim32Player15CView1 __asm__("D_80070328 + 0x15C");
extern int Anim32Player88View1 __asm__("D_80070328 + 0x88");
extern int Anim32Player84View1 __asm__("D_80070328 + 0x84");
extern int Anim32Player68View1 __asm__("D_80070328 + 0x68");
extern int Anim32Player6CView1 __asm__("D_80070328 + 0x6C");
int Anim32PlayMobySoundEventView1() __asm__("func_8003BABC");
int Anim32SubtractVectorView1() __asm__("func_8004F1C8");
int Anim32MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Anim32PlayMobySoundEventView2() __asm__("func_8003BABC");
int Anim32TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Anim32NormalizeVectorToLengthView1() __asm__("func_8004EF04");
int Anim32BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Anim32CopyVectorView1() __asm__("func_8004F178");
int Anim32ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Anim32AddVectorView1() __asm__("func_8004F194");
int Anim32UpdatePlayerTiltFromVectorView1() __asm__("func_80043E00");
int Anim32ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Anim32SubtractVectorView2() __asm__("func_8004F1C8");
int Anim32MeasureVectorLengthView2() __asm__("func_8004EDE8");
extern int Anim32Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim32Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim32PlayerA0View2 __asm__("D_80070328 + 0xA0");
extern int Anim32PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim32PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim32PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim32PlayerCCView2 __asm__("D_80070328 + 0xCC");
extern int Anim32PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim32PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim32Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim32Player90View2 __asm__("D_80070328 + 0x90");
extern int Anim32Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim32PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim32Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim32Player280View2 __asm__("D_80070328 + 0x280");
extern unsigned char Anim32Player1B5View2 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim32Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern int Anim32Data6E538View2 __asm__("D_8006E538"), Anim32Data6E53CView2 __asm__("D_8006E53C");
extern int (*Anim32Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int Anim32Player24View1 __asm__("D_80070328 + 0x24");
extern int Anim32Player4CView3 __asm__("D_80070328 + 0x4C");
extern int Anim32Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim32PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim32Player144View3 __asm__("D_80070328 + 0x144");
extern int Anim32Player158View2 __asm__("D_80070328 + 0x158");
extern int Anim32Player280View3 __asm__("D_80070328 + 0x280");
extern unsigned char Anim32Player0View1[] __asm__("D_80070328");
extern int Anim32Data6E538View3 __asm__("D_8006E538"), Anim32Data6E53CView3 __asm__("D_8006E53C");
extern int Anim32Data6E044View2 __asm__("D_8006E044"), Anim32Data6E344View1 __asm__("D_8006E344"),
    Anim32Data6C514View1 __asm__("D_8006C514");
extern int (*Anim32Data74374View2)() __asm__("unk_ovlheader_80074374");
int Anim32ProcessPlayerStateFlagsView2() __asm__("func_80040994");
int Anim32DispatchPlayerStateRequestView2() __asm__("func_8004BEF8");
int Anim32ApproximatePlanarDistanceView1() __asm__("func_8004F334");
extern volatile int Anim32Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim32Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim32Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim32Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim32Data6EE2CView1 __asm__("D_8006EE2C");
int Anim32ProcessPlayerContactFlagsView1() __asm__("func_80040BCC");
int Anim32QueryWorldHeightWithOptionsView1() __asm__("func_8001A310");
void func_level_32_8009ACBC(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* object4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");
    struct {
        int at10[4], at20[4], at30[4], at40[4], at50[4], at60[4], at70[4], at80[4];
    } frame;
    register int* state __asm__("$16");
    register int* saved16 __asm__("$16");
    register int* saved17 __asm__("$17");
    register int* saved18 __asm__("$18");
    register int* saved19 __asm__("$19");
    register int* state4 __asm__("$4");
    register int call6 __asm__("$6");
    rawValue2 = Anim32Player48View1;
    switch (rawValue2) {
        case 20:
            if (Anim32ProcessPlayerStateFlagsView1())
                return;
            rawValue2 = Anim32Data6E53CView1 & 64;
            nextSelector4 = 6;
            if (rawValue2)
                goto select;
            rawValue2 = Anim32PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            if (Anim32PlayerE4View1 >= 23)
                goto select;
            rawValue3 = Anim32Data6E538View1;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 13;
            if (rawValue2)
                goto select;
            rawValue2 = Anim32PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            if (rawValue2 >= 17) {
                nextSelector4 = 1;
                goto select;
            }
            rawValue2 = rawValue3 & 12;
            MATCHING_KEEP(rawValue2);
            if (!rawValue2) {
                rawValue2 = Anim32PlayerACView1;
                nextSelector4 = 1;
                if (rawValue2)
                    goto select;
            }
            if (Anim32Data6E044View1 == 7 || Anim32Player240View1) {
                state = &Anim32Player48View2;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                Anim32DispatchPlayerStateRequestView1(0);
                if (Anim32Data66530View1[*((unsigned char*)state - 0x2C)] >= 96) {
                    Anim32Player14View1 = Anim32Player15View1;
                    Anim32Player16View1 = Anim32Player17View1;
                }
                Anim32Player17View1 = 0;
                rawValue3 = *state;
                rawValue2 = 113;
                *((unsigned char*)state - 0x2C) = rawValue2;
                Anim32Player1F0View1 = 0;
                Anim32Player15View1 = rawValue3;
                Anim32Player1ECView1 = rawValue3;
                return;
            }
            rawValue2 = Anim32PlayerFCView1;
            nextSelector4 = 15;
            if (rawValue2)
                goto select;
            Anim32SelectPlayerAnimationLoopRequestView1();
            return;
        case 53:
        case 54:
            if (Anim32ProcessPlayerStateFlagsView1())
                return;
            nextSelector4 = 0;
            goto select;
        case 9:
            rawValue3 = Anim32Player4CView2;
            if (rawValue3 != 1)
                goto charge9;
            if (Anim32Player1B5View2 && (Anim32Data6E53CView2 & 64))
                Anim32Player1B6View2 = 1;
            if (Anim32PlayerB8View2 || Anim32Player54View2 < 16 || Anim32PlayerE4View2 >= 23)
                goto buttons9;
            rawValue3 = Anim32PlayerCCView2;
            rawValue2 = Anim32Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim32PlayerD0View2;
            rawValue2 = Anim32Player90View2;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim32PlayerD4View2;
            rawValue2 = Anim32Player94View2;
            rawValue3 = rawValue3 * rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                goto buttons9;
            if (Anim32PlayerACView2) {
                rawValue3 = Anim32PlayerB0View2;
                if (rawValue3 >= 3841) {
                    __asm__ volatile("" ::"i"(0x8009AFD0) : "memory");
                    nextSelector4 = 3;
                    goto select;
                }
                rawValue2 = rawValue3 < 1921;
                nextSelector4 = 1;
                if (rawValue2)
                    goto select;
                __asm__ volatile("" ::"i"(0x8009AFE0) : "memory");
                nextSelector4 = 2;
                goto select;
            }
            rawValue2 = Anim32PlayerB0View2 < 1920;
            nextSelector4 = 0;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x8009B000) : "memory");
            nextSelector4 = 4;
            goto select;
        buttons9:
            if ((Anim32Data6E538View2 & 128) && Anim32PlayerA0View2 < 0 &&
                Anim32Player54View2 >= 5) {
                nextSelector4 = 22;
                goto select;
            }
            if (Anim32Player1B5View2 && Anim32Player1B6View2) {
                if (Anim32PlayerA0View2 >= 0)
                    return;
                if (Anim32Player54View2 >= 5) {
                    nextSelector4 = 17;
                    goto select;
                }
            }
            rawValue3 = Anim32PlayerA0View2;
            if (rawValue3 >= 0)
                return;
            nextSelector4 = Anim32Player54View2;
            if (nextSelector4 < 5)
                return;
            rawValue2 = rawValue3 < -6400;
            MATCHING_KEEP(rawValue2);
            if (rawValue2)
                goto case9Select7;
            rawValue2 = nextSelector4 < 91;
            if (rawValue2)
                return;
        case9Select7:
            __asm__ volatile("" ::"i"(0x8009B0DC) : "memory");
            nextSelector4 = 7;
            goto select;
        charge9:
            if (Anim32Player24View1 & 32)
                return;
            if (Anim32Player54View2 < 25)
                return;
            if (Anim32Player280View2 < 0) {
                __asm__ volatile("" ::"i"(0x8009B128) : "memory");
                nextSelector4 = 31;
                goto select;
            }
        selectState:
            rawValue3 = Anim32Player144View2;
            if (rawValue3 == 10) {
                __asm__ volatile("" ::"i"(0x8009B144) : "memory");
                nextSelector4 = 44;
                goto select;
            }
            rawValue2 = rawValue3 - 11;
            MATCHING_KEEP(rawValue2);
            if ((unsigned int)rawValue2 < 2) {
                nextSelector4 = 41;
                goto select;
            }
            rawValue2 = Anim32PlayerB8View2;
            nextSelector4 = 0;
            if (!rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x8009B174) : "memory");
            nextSelector4 = 7;
            goto select;
        case 19:
            if (Anim32ProcessPlayerStateFlagsView2())
                return;
            rawValue2 = 13;
            rawValue3 = Anim32Data6E344View1;
            if (rawValue3 == rawValue2) {
                rawValue2 = Anim32Data6C514View1;
                nextSelector4 = 17;
                if (rawValue2)
                    goto select;
            }
            nextSelector4 = (int)Anim32Player0View1;
            rawValue2 = Anim32ApproximatePlanarDistanceView1((void*)nextSelector4,
                                                             (void*)(nextSelector4 + 348));
            rawValue3 = Anim32Player158View2;
            rawValue3 = rawValue3 < rawValue2;
            nextSelector4 = 17;
            if (!rawValue3)
                return;
            goto select;
        case 21:
            if (Anim32Player54View1 < 33)
                return;
            if (!Anim32PlayerB8View1) {
                Anim32DispatchPlayerStateRequestView1(4);
                Anim32Player4CView1 = 1;
                return;
            }
            rawValue2 = Anim32PlayerBCView1;
            nextSelector4 = 7;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009B240) : "memory");
            goto select;
        case 28:
            if (Anim32Player1B5View1 && (Anim32Data6E53CView1 & 64))
                Anim32Player1B6View1 = 1;
            if (!Anim32PlayerB8View1 && Anim32Player54View1 >= 16 && Anim32PlayerE4View1 < 23) {
                rawValue3 = Anim32PlayerCCView1;
                rawValue2 = Anim32Player8CView1;
                product5 = rawValue3 * rawValue2;
                rawValue3 = Anim32PlayerD0View1;
                rawValue2 = Anim32Player90View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = Anim32PlayerD4View1;
                rawValue2 = Anim32Player94View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                if (rawValue2 < 0) {
                    if (Anim32PlayerACView1) {
                        rawValue3 = Anim32PlayerB0View1;
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
                    rawValue2 = Anim32PlayerB0View1 < 1920;
                    nextSelector4 = 0;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 4;
                    goto select;
                }
            }
            rawValue2 = Anim32Data6E538View1 & 128;
            if (rawValue2 && Anim32Player4CView1 == 1) {
                nextSelector4 = 22;
                goto select;
            }
            if (Anim32Player1B5View1 && Anim32Player1B6View1) {
                rawValue3 = Anim32Player4CView1;
                rawValue2 = 1;
                nextSelector4 = 17;
                if (rawValue3 != rawValue2)
                    return;
                goto select;
            }
            rawValue3 = Anim32Player4CView1;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim32PlayerA0View1 < -6400;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            if (Anim32Player54View1 >= 91)
                goto select;
            return;
        case 30: {
            register int* timer4 __asm__("$4");
            register int (*callback3)() __asm__("$3");
            if (Anim32Data6E53CView1 & 64)
                Anim32Player1B6View1 = 1;
            if (Anim32Data6FA38View1 >= 0) {
                if (Anim32Player144View1 <= 0x8FFF)
                    return;
                callback3 = Anim32Data74374View1;
                Anim32Player28CView1 = -1;
                if (callback3) {
                    callback3();
                    return;
                }
                goto call498C0;
            }
            timer4 = &Anim32Player280View1;
            MATCHING_KEEP(timer4);
            if (*timer4 < 0) {
                if (Anim32Player144View1 <= 0x8FFF)
                    return;
                Anim32Player28CView1 = -1;
            call498C0:
                Anim32UpdatePlayerRetryStateView1();
                MATCHING_BARRIER_VOLATILE("memory");
                return;
            }
            rawValue3 = Anim32Player54View1;
            if (rawValue3 >= 61) {
                *timer4 = -1;
                return;
            }
            rawValue2 = rawValue3 < 16;
            MATCHING_KEEP(rawValue2);
            if (rawValue2)
                return;
            if (!Anim32Player1B6View1)
                return;
            if (Anim32Player28CView1 >= 0) {
                if (Anim32SoundHandleMatchesIdInStates1Or2View1(Anim32Player290View1,
                                                                Anim32Player28CView1))
                    Anim32TransitionSoundHandleTo3Or5View1(Anim32Player28CView1);
                Anim32Player28CView1 = -1;
            }
            nextSelector4 = 6;
            goto select;
        }
        case 36:
            if (Anim32ProcessPlayerStateFlagsView1())
                return;
            saved16 = &Anim32Player4CView1;
            rawValue2 = *saved16;
            if ((unsigned)(rawValue2 - 1) < 2 && !Anim32PlayerB8View1) {
                if (Anim32PlayerE4View1 >= 60)
                    goto expired36;
                frame.at10[0] = 0;
                frame.at10[1] = 0;
                frame.at10[2] = 4096;
                Anim32TransformVectorByBasisView1(saved16 - 7, frame.at10, frame.at10);
                Anim32NormalizeVectorToLengthView1(saved16 + 32, 4096);
                rawValue3 = frame.at10[0];
                rawValue2 = saved16[32];
                product5 = rawValue3 * rawValue2;
                rawValue3 = frame.at10[1];
                rawValue2 = Anim32PlayerD0View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = frame.at10[2];
                rawValue2 = Anim32PlayerD4View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                rawValue2 >>= 12;
                nextSelector4 = 21;
                if (rawValue2 < 1536)
                    goto select;
                product5 = 2;
                object4 = Anim32Player250View1;
                MATCHING_KEEP(object4);
                call6 = 0;
                MATCHING_KEEP3(object4, product5, call6);
                *saved16 = 0;
                Anim32PlayMobySoundEventView1(object4, product5, call6);
                return;
            expired36:
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 21;
                goto select;
            }
            state4 = &Anim32Player4CView1;
            rawValue3 = *state4;
            rawValue2 = 3;
            if (rawValue3 == rawValue2) {
                if (Anim32Data6E538View1 & 64)
                    Anim32Player1B6View1 = 1;
                rawValue2 = Anim32GetSurfaceTypeFromFlagsView1(Anim32Player10CView1);
                rawValue3 = 9;
                if (rawValue2 != rawValue3) {
                    if (Anim32PlayerA0View1 > 0 && Anim32Player160View1 >= 4)
                        Anim32PlayerB8View1 = 1;
                    else
                        Anim32Player4CView1 = 0;
                }
                saved17 = &Anim32PlayerB8View1;
                MATCHING_KEEP(saved17);
                rawValue2 = *saved17;
                if (!rawValue2)
                    goto remainder36;
                if (Anim32Player158View1 <= 2048)
                    goto reset36;
                Anim32BuildPlayerMovementVectorView1();
                rawValue3 = Anim32Player15CView1;
                rawValue2 = 2;
                if (rawValue3 == rawValue2) {
                    nextSelector4 = 48;
                    if (Anim32Player1B6View1) {
                        rawValue2 = Anim32Player88View1;
                        rawValue2 += 3840;
                        Anim32Player88View1 = rawValue2;
                        rawValue2 = 4;
                        goto set36;
                    }
                    rawValue2 = 4;
                    goto set36;
                }
                if (Anim32Player1B6View1 || rawValue3 == 1) {
                    Anim32CopyVectorView1(frame.at10, saved17 + 37);
                    frame.at10[2] = 0;
                    Anim32NormalizeVectorToLengthView1(frame.at10, 4096);
                    rawValue3 = frame.at10[0];
                    rawValue2 = saved17[-14];
                    call6 = rawValue3 * rawValue2;
                    rawValue3 = frame.at10[1];
                    rawValue2 = Anim32Player84View1;
                    rawValue3 *= rawValue2;
                    call6 += rawValue3;
                    call6 >>= 12;
                    call6 = -call6;
                    Anim32ScaleVectorRatioQ15View1(frame.at10, 4096, call6);
                    saved16 = saved17 - 14;
                    Anim32Player88View1 += 2048;
                    Anim32AddVectorView1(saved16, saved16, frame.at10);
                    Anim32UpdatePlayerTiltFromVectorView1(saved16);
                    Anim32ShiftVectorRightTowardZeroView1(frame.at10, 4);
                    Anim32AddVectorView1(saved17 - 46, saved17 - 46, frame.at10);
                    nextSelector4 = 37;
                    Anim32Player68View1 = 0;
                    Anim32Player6CView1 = 0;
                    rawValue2 = 5;
                    goto set36;
                }
                nextSelector4 = 48;
                rawValue2 = 4;
            set36:
                Anim32Player4CView1 = rawValue2;
                Anim32DispatchPlayerStateRequestView1(nextSelector4);
                Anim32PlayMobySoundEventView2(Anim32Player250View1, 1, 0);
                saved16 = &Anim32Player8CView1;
                nextSelector4 = (int)saved16;
                MATCHING_KEEP(nextSelector4);
                saved17 = saved16 - 3;
                Anim32CopyVectorView1((void*)nextSelector4, saved17);
                Anim32CopyVectorView1(saved16 + 3, saved17);
                return;
            reset36:
                Anim32Player4CView1 = 0;
                goto remainder36;
            }
            if (rawValue3)
                goto remainder36;
            if (Anim32PlayerB8View1 < 5 && (Anim32Data6E53CView1 & 64)) {
                rawValue2 = 1;
                rawValue3 = Anim32PlayerA0View1;
                *state4 = rawValue2;
                Anim32Player54View1 = 0;
                rawValue3 += 3520;
                Anim32Player94View1 = rawValue3;
                return;
            }
            rawValue2 = Anim32PlayerB8View1;
            if (rawValue2) {
                rawValue2 = rawValue2 < 5;
                goto count36;
            }
            rawValue2 = Anim32PlayerE4View1;
            rawValue2 = rawValue2 < 48;
            nextSelector4 = 21;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim32PlayerB8View1;
            rawValue2 = rawValue2 < 5;
        count36:
            if (!rawValue2) {
                rawValue2 = 1;
                Anim32Player4CView1 = rawValue2;
                Anim32Player54View1 = 0;
            }
        remainder36:
            saved18 = frame.at20;
            nextSelector4 = (int)saved18;
            MATCHING_KEEP(nextSelector4);
            saved16 = &Anim32Player8CView1;
            product5 = (int)saved16;
            MATCHING_KEEP(product5);
            saved17 = saved16 + 3;
            Anim32SubtractVectorView1((void*)nextSelector4, (void*)product5, saved17);
            saved19 = frame.at30;
            Anim32SubtractVectorView1(saved19, saved16 - 3, saved17);
            rawValue2 = Anim32MeasureVectorLengthView1(saved18, 1);
            rawValue3 = Anim32PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            if (rawValue2 < 218)
                return;
            rawValue2 = Anim32MeasureVectorLengthView1(saved19, 1);
            rawValue3 = Anim32PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            MATCHING_KEEP_VOLATILE_CLOBBER(rawValue2, "$4");
            rawValue2 = rawValue2 < 218;
            nextSelector4 = 21;
            if (rawValue2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto select;
        case 48:
            if (Anim32ProcessPlayerStateFlagsView1())
                return;
            saved16 = &Anim32PlayerB8View1;
            if (!*saved16 && Anim32PlayerE4View1 < 60) {
                frame.at40[0] = 0;
                frame.at40[1] = 0;
                frame.at40[2] = 4096;
                Anim32TransformVectorByBasisView1(saved16 - 34, frame.at40, frame.at40);
                Anim32NormalizeVectorToLengthView1(saved16 + 5, 4096);
                rawValue3 = frame.at40[0];
                rawValue2 = saved16[5];
                product5 = rawValue3 * rawValue2;
                rawValue3 = frame.at40[1];
                rawValue2 = Anim32PlayerD0View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = frame.at40[2];
                rawValue2 = Anim32PlayerD4View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                rawValue2 >>= 12;
                nextSelector4 = 21;
                if (rawValue2 < 1536)
                    goto select;
                Anim32Player4CView1 = 0;
                Anim32DispatchPlayerStateRequestView1(36);
                object4 = Anim32Player250View1;
                product5 = 2;
                goto partialBABC;
            }
            saved18 = frame.at50;
            nextSelector4 = (int)saved18;
            MATCHING_KEEP(nextSelector4);
            saved16 = &Anim32Player8CView1;
            product5 = (int)saved16;
            MATCHING_KEEP(product5);
            saved17 = saved16 + 3;
            Anim32SubtractVectorView2((void*)nextSelector4, (void*)product5, saved17);
            saved19 = frame.at60;
            Anim32SubtractVectorView2(saved19, saved16 - 3, saved17);
            rawValue2 = Anim32MeasureVectorLengthView2(saved18, 1);
            rawValue3 = Anim32PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            if (rawValue2 < 218)
                return;
            rawValue2 = Anim32MeasureVectorLengthView2(saved19, 1);
            rawValue3 = Anim32PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            MATCHING_BARRIER("$4");
            rawValue2 = rawValue2 < 218;
            nextSelector4 = 21;
            if (rawValue2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto select;
        case 37:
            if (Anim32ProcessPlayerStateFlagsView1())
                return;
            saved17 = &Anim32PlayerB8View1;
            if (*saved17)
                return;
            if (Anim32PlayerE4View1 >= 60)
                return;
            saved19 = saved17 - 34;
            nextSelector4 = (int)saved19;
            MATCHING_KEEP(nextSelector4);
            saved16 = frame.at70;
            product5 = (int)saved16;
            call6 = product5;
            MATCHING_KEEP2(product5, call6);
            saved18 = (int*)4096;
            frame.at70[0] = 0;
            frame.at70[1] = 0;
            frame.at70[2] = (int)saved18;
            Anim32TransformVectorByBasisView1((void*)nextSelector4, (void*)product5, (void*)call6);
            Anim32NormalizeVectorToLengthView1(saved17 + 5, 4096);
            rawValue3 = frame.at70[0];
            rawValue2 = saved17[5];
            product5 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[1];
            rawValue2 = Anim32PlayerD0View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[2];
            rawValue2 = Anim32PlayerD4View1;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            rawValue2 >>= 12;
            nextSelector4 = 21;
            if (rawValue2 < 1536)
                goto select;
            frame.at70[0] = (int)saved18;
            frame.at70[1] = 0;
            frame.at70[2] = 0;
            Anim32TransformVectorByBasisView1(saved19, saved16, saved16);
            saved16 = frame.at80;
            Anim32CopyVectorView1(saved16, saved17 - 8);
            Anim32NormalizeVectorToLengthView1(saved16, 4096);
            rawValue3 = frame.at70[0];
            rawValue2 = frame.at80[0];
            product5 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[1];
            rawValue2 = frame.at80[1];
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[2];
            rawValue2 = frame.at80[2];
            rawValue3 *= rawValue2;
            Anim32Player4CView1 = 0;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            rawValue2 >>= 12;
            nextSelector4 = 21;
            if (rawValue2 < 2560)
                goto select;
            Anim32DispatchPlayerStateRequestView1(36);
            object4 = Anim32Player250View1;
            product5 = 2;
        partialBABC:
            Anim32PlayMobySoundEventView2(object4, product5, 0);
            return;
        case 40:
            if (Anim32ProcessPlayerStateFlagsView2())
                return;
            if ((Anim32Data6E538View3 & 128) && Anim32Player4CView3 != 1) {
                nextSelector4 = 42;
                goto select;
            }
            if (Anim32PlayerB0View3)
                return;
            rawValue2 = Anim32Player20CView1 & 64;
            nextSelector4 = 41;
            if (!rawValue2)
                goto select;
            if (Anim32Player214View1 <= 0)
                return;
            goto select;
        case 41:
            if (Anim32ProcessPlayerStateFlagsView2())
                return;
            nextSelector4 = Anim32Data6E538View3;
            rawValue2 = nextSelector4 & 128;
            if (rawValue2) {
                nextSelector4 = 42;
                goto select;
            }
            rawValue2 = 7;
            rawValue3 = Anim32Data6E044View2;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = nextSelector4 & 64;
            nextSelector4 = 40;
            if (rawValue2)
                goto select;
            if (!(Anim32Player20CView1 & 64))
                return;
            if (!Anim32Player214View1)
                goto select;
            return;
        case 42:
            if (Anim32ProcessPlayerContactFlagsView1())
                return;
            if ((Anim32Data6E538View3 & 128) || Anim32Player4CView3 == 1)
                goto flag64;
            rawValue2 = Anim32Player20CView1 & 128;
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        flag64:
            rawValue2 = Anim32Player20CView1 & 64;
            nextSelector4 = 40;
            if (!rawValue2)
                return;
            goto select;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (Anim32ProcessPlayerStateFlagsView2())
                return;
            if ((Anim32Data6E53CView3 & 64) && Anim32Player54View3 >= 9) {
                nextSelector4 = 6;
                goto partialCall;
            }
            byte4 = &Anim32Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto partialCall;
            }
            if (!(Anim32Data6E53CView3 & 128))
                goto check44;
            if (Anim32Player54View3 < 9)
                goto check44;
            rawValue2 = *(int*)(Anim32Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto check44;
            rawValue2 = Anim32QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (rawValue2)
                goto check44;
            goto select;
        partialCall:
            Anim32DispatchPlayerStateRequestView2(nextSelector4);
        check44:
            rawValue2 = Anim32Data6E535View1;
            nextSelector4 = 44;
            if (!rawValue2)
                return;
            goto select;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3 = Anim32Player4CView3;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                goto other44;
            if (Anim32Data6E53CView3 & 0x850)
                goto callback44;
            if (Anim32Player54View3 < 61)
                return;
        callback44:
            callback2 = Anim32Data74374View2;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto call498C0;
        other44:
            if (Anim32ProcessPlayerStateFlagsView2())
                return;
            if ((Anim32Data6E53CView3 & 64) && Anim32Player54View3 >= 9) {
                nextSelector4 = 6;
                goto select;
            }
            byte4 = &Anim32Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                __asm__ volatile("" ::"i"(0x8009C0FC) : "memory");
                nextSelector4 = 7;
                goto select;
            }
            if (!(Anim32Data6E53CView3 & 128))
                goto mode44;
            if (Anim32Player54View3 < 9)
                goto mode44;
            rawValue2 = *(int*)(Anim32Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto mode44;
            rawValue2 = Anim32QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        mode44:
            rawValue3 = Anim32Data6E044View2;
            rawValue2 = 7;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = Anim32Data6E535View1;
            nextSelector4 = 43;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009C190) : "memory");
            goto select;
        }
        case 49:
            if (Anim32ProcessPlayerStateFlagsView1())
                return;
            rawValue2 = Anim32PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim32Player144View1 < 16;
            nextSelector4 = 0;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009C1D8) : "memory");
            goto select;
        case 57:
            if (Anim32Player54View3 < 25)
                return;
            if (Anim32Player280View3 < 0) {
                nextSelector4 = 31;
                goto select;
            }
            rawValue2 = 10;
            rawValue3 = Anim32Player144View3;
            nextSelector4 = 41;
            if (rawValue3 != rawValue2)
                goto select;
            nextSelector4 = 44;
            goto select;
        case 150: {
            register int (*callback2)(int) __asm__("$2") = Anim32Data7431CView1;
            callback2(1);
            rawValue2 = Anim32Data6E538View1 & 0xC0;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 151;
            if (rawValue2 == 0)
                return;
            goto select;
        }
        case 151: {
            register int (*callback2)(int) __asm__("$2") = Anim32Data7431CView1;
            callback2(1);
            rawValue2 = Anim32Data6E538View1 & 0xC0;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 150;
            if (rawValue2 != 0)
                return;
            goto select;
        }
        default:
            return;
    }
select:
    Anim32DispatchPlayerStateRequestView1(nextSelector4);
    return;
}
