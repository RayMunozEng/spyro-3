#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8009A6B4.
 * Assembly SHA256 3497c0ad76b481fdd7678a31313caab6ad4b2c46bc7f98ebe160ad18f1bd129c.
 * AI-generated; not human reviewed. All2580 original instructions and
 * 131 selectors (bias21) and one owned padding word are required.
 * Original frame0x188 retains scratch
 * 10..15C, savedS0..S7, incoming slotS2 and combinedS7.
 * Ten exact groups reuse verified12/32 with original frame/address maps.
 * Near28 retains its original two saved pointers and particle selector13.
 * Near33/34/35 retains the additional table-selected altitude constraint
 * and wrapped AC*170/100 modifier. Near150/151 retains wrapped AC*150/100.
 * All372 original27/60 rows preserve the state50 test, flight recurrence,
 * dynamic signed division by4608 with its original checks, input branches,
 * trig/vector arithmetic, final94 store and original shared helper join.
 * Three independent low-product lifetimes preserve the original MFLO roles.
 * Typed aliases remain distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, conditional/internal target,
 * selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics50Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics50RandSignedBetweenView1() __asm__("func_800363DC");
unsigned char Physics50UpdatePlayerGroundInputTargetsView1() __asm__("func_80040D10");
unsigned char Physics50ApproachPlayerTargetHeadingView1() __asm__("func_80041580");
unsigned char Physics50BlendPlayerHeadingFromInputVectorView1() __asm__("func_800416F4");
unsigned char Physics50ApproachPlayerTargetSpeedView1() __asm__("func_800417FC");
unsigned char Physics50BuildPlayerResponseVectorView1() __asm__("func_80041B64");
int Physics50InterpolateSineView1() __asm__("func_8004E9E4");
int Physics50InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics50TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics50MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics50ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics50ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics50CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics50AddVectorView1() __asm__("func_8004F194");
unsigned char Physics50SubtractVectorView1() __asm__("func_8004F1C8");
int Physics50CallRandView1() __asm__("rand");
extern unsigned char Physics50Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics50Data65920View1 __asm__("D_80065920");
extern void* Physics50Data6C570View1 __asm__("D_8006C570");
extern int Physics50Data6C640View1 __asm__("D_8006C640");
extern int Physics50Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics50Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics50Player0View1 __asm__("D_80070328");
extern int Physics50Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics50Player94View2 __asm__("D_80070328+0x94");
extern int Physics50Player80View1 __asm__("D_80070328+0x80");
extern int Physics50PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics50Player64View1 __asm__("D_80070328+0x64");
extern int Physics50Player88View1 __asm__("D_80070328+0x88");
extern int Physics50Player84View1 __asm__("D_80070328+0x84");
extern int Physics50Player144View1 __asm__("D_80070328+0x144");
extern int Physics50Player60View1 __asm__("D_80070328+0x60");
extern int Physics50PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics50Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics50Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics50Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics50PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics50PlayerA4View1 __asm__("D_80070328+0xA4");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
int Physics50TestSubdividedSegmentPathView1() __asm__("func_80013E38");
int Physics50UpdateSmoothedInputPairView1() __asm__("func_800410F8");
int Physics50BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Physics50EvaluateClampedPlayerRootCurveView1() __asm__("func_8004E4E4");
int Physics50InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics50AddVectorView2() __asm__("func_8004F194");
extern int Physics50Data67630View1 __asm__("D_80067630");
extern int Physics50Data67634View1 __asm__("D_80067634");
extern int Physics50Data67638View1 __asm__("D_80067638");
extern int Physics50Data6FA38View1 __asm__("D_8006FA38");
extern int Physics50Data71908View1 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics50Player130View1 __asm__("D_80070328+0x130");
extern int Physics50Player144View2 __asm__("D_80070328+0x144");
extern short Physics50Player148View1 __asm__("D_80070328+0x148");
extern short Physics50Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics50Player14CView2 __asm__("D_80070328+0x14C");
extern int Physics50Player150View1 __asm__("D_80070328+0x150");
extern int Physics50Player154View1 __asm__("D_80070328+0x154");
extern int Physics50Player160View1 __asm__("D_80070328+0x160");
extern int Physics50Player48View1 __asm__("D_80070328+0x48");
extern int Physics50Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics50Player5CView2 __asm__("D_80070328+0x5C");
extern int Physics50Player60View2 __asm__("D_80070328+0x60");
extern int Physics50Player64View2 __asm__("D_80070328+0x64");
extern int Physics50Player8View1 __asm__("D_80070328+0x8");
extern int Physics50Player88View2 __asm__("D_80070328+0x88");
extern int Physics50Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics50Player90View1 __asm__("D_80070328+0x90");
extern int Physics50Player94View3 __asm__("D_80070328+0x94");
extern int Physics50PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics50PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics50PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics50PlayerF8View1 __asm__("D_80070328+0xF8");
int Physics50UpdatePlayerGroundInputTargetsView2() __asm__("func_80040D10");
int Physics50UpdateSmoothedInputPairView2() __asm__("func_800410F8");
int Physics50ApproachPlayerTargetHeadingView2() __asm__("func_80041580");
int Physics50ApproachPlayerTargetSpeedView2() __asm__("func_800417FC");
int Physics50BuildPlayerMovementVectorView2() __asm__("func_80041848");
int Physics50BuildPlayerResponseVectorView2() __asm__("func_80041B64");
int Physics50InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics50TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics50ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics50ClearVectorView2() __asm__("func_8004F168");
int Physics50CopyVectorView2() __asm__("func_8004F178");
int Physics50AddVectorView3() __asm__("func_8004F194");
int Physics50CallRandView2() __asm__("rand");
extern int* Physics50Data6C570View2 __asm__("D_8006C570");
extern int Physics50Data6C640View2 __asm__("D_8006C640");
extern int Physics50Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics50Player0View2 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics50Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics50Player158View1 __asm__("D_80070328+0x158");
extern int Physics50Player20CView1 __asm__("D_80070328+0x20C");
int Physics50UpdateSmoothedInputPairView3() __asm__("func_800410F8");
int Physics50ApproachPlayerTargetSpeedView3() __asm__("func_800417FC");
int Physics50BuildPlayerMovementVectorView3() __asm__("func_80041848");
int Physics50InterpolateCosineView4() __asm__("func_8004EA2C");
int Physics50CopyVectorView3() __asm__("func_8004F178");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char Physics50Player0View3 __asm__("D_80070328");
int Physics50BuildOrientedInputPairView1() __asm__("func_80040F48");
int Physics50ApproachPlayerTargetSpeedView4() __asm__("func_800417FC");
int Physics50BuildPlayerMovementVectorView4() __asm__("func_80041848");
int Physics50WriteBasisAngleTripletView1() __asm__("func_8004E56C");
int Physics50PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics50TransposePackedHalfwordMatrix3x3View1() __asm__("func_8004ECF4");
int Physics50MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics50ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics50CopyVectorView4() __asm__("func_8004F178");
int Physics50AddVectorView4() __asm__("func_8004F194");
int Physics50SubtractVectorView2() __asm__("func_8004F1C8");
int Physics50BuildEulerBasisPairView1() __asm__("func_8004F6C4");
int Physics50MultiplyPackedGteMatricesView1() __asm__("func_8005F35C");
extern int* Physics50Data6C570View3 __asm__("D_8006C570");
extern int Physics50Data6E538View1 __asm__("D_8006E538");
extern int Physics50PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics50Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics50Player68View1 __asm__("D_80070328+0x68");
extern int Physics50Player6CView1 __asm__("D_80070328+0x6C");
extern int Physics50Player70View1 __asm__("D_80070328+0x70");
extern int Physics50PlayerA0View1 __asm__("D_80070328+0xA0");
extern int Physics50Player5CView3 __asm__("D_80070328+0x5C");
extern int Physics50Player60View3 __asm__("D_80070328+0x60");
extern int Physics50Player64View3 __asm__("D_80070328+0x64");
extern int Physics50Player164View1 __asm__("D_80070328+0x164");
extern int Physics50PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics50PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics50Player16CView1 __asm__("D_80070328+0x16C");
extern int Physics50Player168View1 __asm__("D_80070328+0x168");
extern int Physics50Player94View4 __asm__("D_80070328+0x94");
extern int Physics50Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics50Player80View2 __asm__("D_80070328+0x80");
extern int Physics50Player90View2 __asm__("D_80070328+0x90");
extern int Physics50Player84View2 __asm__("D_80070328+0x84");
extern int Physics50PlayerF4View1 __asm__("D_80070328+0xF4");
extern int Physics50Player8View2 __asm__("D_80070328+0x8");
extern int Physics50Player48View2 __asm__("D_80070328+0x48");
int Physics50ApproachPlayerTargetHeadingView3() __asm__("func_80041580");
int Physics50SubAngle12View1() __asm__("func_8003615C");
int Physics50UpdatePlayerGroundInputTargetsView3() __asm__("func_80040D10");
int Physics50UpdateSmoothedInputPairView4() __asm__("func_800410F8");
int Physics50ApproachPlayerTargetHeadingView4() __asm__("func_80041580");
int Physics50BuildPlayerResponseVectorView3() __asm__("func_80041B64");
int Physics50InterpolateSineView2() __asm__("func_8004E9E4");
int Physics50InterpolateCosineView5() __asm__("func_8004EA2C");
int Physics50TransformVectorByBasisView3() __asm__("func_8004ED6C");
int Physics50MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics50ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics50ClearVectorView3() __asm__("func_8004F168");
int Physics50AddVectorView5() __asm__("func_8004F194");
int Physics50SubtractVectorView3() __asm__("func_8004F1C8");
extern unsigned char Physics50Data676E8View1 __asm__("D_800676E8");
extern int Physics50Data6C58CView1 __asm__("D_8006C58C");
extern int Physics50Data6C5C8View1 __asm__("D_8006C5C8");
extern short Physics50Data6E040View1 __asm__("D_8006E040");
extern int Physics50Data6E538View2 __asm__("D_8006E538");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics50Player50View1 __asm__("D_80070328+0x50");
extern int Physics50PlayerB4View1 __asm__("D_80070328+0xB4");
extern int Physics50Player30View1 __asm__("D_80070328+0x30");
void func_level_50_8009A6B4(int slotIndex) {
    register void* fieldA4State28 __asm__("$16");
    register void* vector8CState28 __asm__("$17");
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
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4,
            spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC, spE0, spE4, spE8, spEC,
            spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C, sp120,
            sp124, sp128, sp12C, sp130, sp134, sp138, sp13C, sp140, sp144, sp148, sp14C, sp150,
            sp154, sp158, sp15C;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$23");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldB8PointerState20 __asm__("$16");
    void* temp_v0_5;
    void* temp_v0_7;
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
    globalPointer = &Physics50Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics50Data6C570View1 = (void*)workWord2;
    workWord2 = Physics50Field(&Physics50Player0View1, int*, 0x54);
    stateWord3 = Physics50Field(&Physics50Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        case 53:
        case 54:
            globalVector80 = &Physics50Player0View1 + 0x80;
            Physics50ClearVectorView1(globalVector80);
            Physics50ClearVectorView1(globalVector80 + 0xC);
            if (Physics50Data6E044View1 != 7) {
                Physics50UpdatePlayerGroundInputTargetsView1(0x1200);
                Physics50BlendPlayerHeadingFromInputVectorView1();
                Physics50ApproachPlayerTargetHeadingView1(0x5A, 0x10);
                return;
            }
            return;
        default:
            return;
        case 21:
            raw22_temp_v0_6 = Physics50Field(&Physics50Player0View3, int*, 0x94) - 0x140;
            Physics50Field(&Physics50Player0View3, int*, 0x94) = raw22_temp_v0_6;
            if (raw22_temp_v0_6 < -0x2300) {
                Physics50Field(&Physics50Player0View3, int*, 0x94) = -0x2300;
            }
            Physics50Field(&Physics50Player0View3, int*, 0xA4) = Physics50PlanarHeadingLookupView1(
                Physics50Field(&Physics50Player0View3, int*, 0x8C),
                Physics50Field(&Physics50Player0View3, int*, 0x90), 1);
            Physics50ApproachPlayerTargetHeadingView3(0x5A, 0x10);
            return;
        case 28:
            Physics50UpdatePlayerGroundInputTargetsView1(0xC80);
            Physics50ApproachPlayerTargetHeadingView1(0x28, 8);
            Physics50ApproachPlayerTargetSpeedView1(0x140, 0xC0);
            fieldA4State28 = &Physics50Player0View1 + 0xA4;
            vector8CState28 = fieldA4State28 - 0x18;
            workWord2 = Physics50InterpolateCosineView1(Physics50Field(fieldA4State28, int*, 0));
            workWord3 = Physics50Field(&Physics50Player0View1, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics50Field(fieldA4State28, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp10 = workWord2;
            workWord2 = Physics50InterpolateSineView1(call4);
            workWord3 = Physics50Field(&Physics50Player0View1, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp14 = workWord2;
            Physics50SubtractVectorView1(&originalFrame.sp10, &originalFrame.sp10, vector8CState28);
            originalFrame.sp18 = 0;
            temp_v0_4 = Physics50MeasureVectorLengthView1(&originalFrame.sp10, 0);
            MATCHING_KEEP(fieldA4State28);
            var_a0_3 = fieldA4State28 - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics50ScaleVectorRatioQ15View1(&originalFrame.sp10, temp_v0_4, 0x280);
                MATCHING_KEEP(fieldA4State28);
                var_a0_3 = fieldA4State28 - 0x24;
            }
            Physics50AddVectorView1(var_a0_3, vector8CState28, &originalFrame.sp10);
            Physics50BuildPlayerResponseVectorView1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics50Field(&Physics50Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics50Field(&Physics50Player0View1, int*, 0x94) - 0xC0;
            }
            Physics50Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics50Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics50Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp30;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics50CallRandView1() & 0xFF)) {
                        workWord2 = Physics50RandSignedBetweenView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics50Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp20 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics50Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp28 = 0xE;
                        originalFrame.sp30 = -0x12C;
                        originalFrame.sp34 = 0;
                        originalFrame.sp38 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp24 = (workWord3 * 5) >> 0xA;
                        Physics50TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp30 += Physics50RandSignedBetweenView1(0, 0x50);
                        originalFrame.sp34 += Physics50RandSignedBetweenView1(0, 0x50);
                        originalFrame.sp38 += Physics50RandSignedBetweenView1(0, 0x50);
                        Physics50AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp20);
                        Physics50Field(temp_v0_5, signed char*, 2) = 8;
                        Physics50Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 30:
            globalVector80 = &Physics50Player80View1;
            MATCHING_KEEP_VOLATILE_CLOBBER(globalVector80, "memory");
            goto block_154;
        case 58:
            globalFieldB8PointerState20 = &Physics50Player0View1 + 0xB8;
            if (Physics50Field(&Physics50Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp20;
                Physics50ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics50SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp28 = 0;
                temp_v0_6 = Physics50MeasureVectorLengthView1(&originalFrame.sp20, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics50ScaleVectorRatioQ15View1(&originalFrame.sp20, temp_v0_6, 0x40);
                }
                originalFrame.sp28 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics50AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp20);
                Physics50CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics50ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics50ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics50Field(&Physics50Player0View1, int*, 0x94) < -0x2300) {
                Physics50Field(&Physics50Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics50Field(&Physics50Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics50Data6C640View1 & 1)) {
                originalFrame.sp40 = 0;
                originalFrame.sp44 = 0;
                originalFrame.sp48 = 0xE;
                Physics50CopyVectorView1(&originalFrame.sp50,
                                         (&Physics50Player0View1 + 0x94) - 0x94);
                originalFrame.sp50 += Physics50RandSignedBetweenView1(0, 0x12C);
                originalFrame.sp54 += Physics50RandSignedBetweenView1(0, 0x12C);
                originalFrame.sp58 += Physics50RandSignedBetweenView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp50, &originalFrame.sp40);
                Physics50Field(temp_v0_7, signed char*, 2) = 6;
                Physics50Field(temp_v0_7, signed char*, 0xA) = 0x20;
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
            call4 = &originalFrame.sp40;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            pointer17 = &Physics50Player154View1;
            Physics50UpdateSmoothedInputPairView1(call4, pointer17, 0);
            workWord2 = originalFrame.sp44;
            numeric4 = Physics50Player94View3;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp40;
            numeric4 -= 1024;
            originalFrame.sp50 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                pointer16 = &originalFrame.sp48;
                call4 = pointer16;
                call5 = pointer16;
                __asm__ volatile(""
                                 : "=r"(pointer17)
                                 : "0"(pointer17), "r"(call4), "r"(call5)
                                 : "memory");
                pointer17 -= 340;
                call6 = pointer17;
                workWord2 = Physics50Player8CView1;
                workWord3 = Physics50Player90View1;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp48 = workWord2;
                originalFrame.sp4C = workWord3;
                Physics50AddVectorView2(call4, call5, call6);
                if (!Physics50TestSubdividedSegmentPathView1(pointer17, pointer16, 2)) {
                    workWord2 = Physics50Player8View1;
                    workWord3 = Physics50Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp44 = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp44 = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp44;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics50PlayerF8View1;
            workWord3 = Physics50Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics50Player60View2;
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
            numeric4 = (int)&Physics50Data676E8View1;
            workWord3 = Physics50Data6C58CView1;
            workWord2 = Physics50Data6C5C8View1;
            workWord3 <<= 4;
            workWord3 += numeric4;
            workWord2 <<= 2;
            workWord2 += workWord3;
            workWord3 = Physics50Player8View1;
            numeric4 = Physics50Field((void*)workWord2, int*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(numeric4, "memory");
            workWord2 = workWord3 - numeric4;
            workWord2 -= 1024;
            workWord2 = workWord2 < 4096;
            workWord3 -= 1024;
            if (workWord2) {
                workWord3 = numeric4 - workWord3;
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics50Player60View2;
                numeric4 = workWord2 >> 12;
                workWord3 = numeric4 - workWord3;
                numeric4 = workWord3 & 4095;
                workWord2 = numeric4 < 2049;
                if (!workWord2) {
                    numeric4 -= 4096;
                    workWord2 = delta18 < numeric4;
                } else
                    workWord2 = delta18 < numeric4;
                if (workWord2)
                    delta18 = numeric4;
            }
            call4 = &Physics50Player64View2;
            workWord2 = Physics50Field(call4, int*, 0);
            workWord3 = Physics50Player60View2;
            Physics50PlayerA8View1 = delta19;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics50Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics50Player60View2 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics50Player60View2 = workWord2;
            }
            workWord2 = Physics50Player60View2;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics50Player60View2 = -800;
            workWord2 = Physics50Player60View2;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics50Player60View2 = 800;
            workWord2 = Physics50Data6FA38View1;
            if (workWord2 >= 0)
                goto nonnegative33;
            workWord3 = Physics50Player60View2;
            if (workWord3 >= 0)
                goto positive33;
            numeric4 = Physics50Data67634View1;
            workWord2 = Physics50Data67630View1;
            workWord2 = numeric4 - workWord2;
            goto quotient33;
        positive33:
            if (workWord3 <= 0)
                goto zero33;
            workWord2 = Physics50Data67638View1;
            numeric4 = Physics50Data67634View1;
            workWord2 -= numeric4;
        quotient33:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics50PlayerACView2 = numeric4;
            goto modifier33;
        zero33:
            workWord2 = Physics50Data67634View1;
            Physics50PlayerACView2 = workWord2;
        modifier33:
            workWord2 = Physics50Data6C5C8View1;
            if (workWord2)
                goto speed33;
            call4 = &Physics50PlayerACView2;
            workWord3 = Physics50Field(call4, int*, 0);
            workWord2 = workWord3 * 5;
            workWord3 = workWord2 << 4;
            workWord2 += workWord3;
            workWord2 <<= 1;
            workWord3 = workWord2 / 100;
            Physics50Field(call4, int*, 0) = workWord3;
        speed33:
            call5 = &Physics50Player144View2;
            workWord2 = Physics50PlayerACView2;
            numeric4 = Physics50PlayerB0View2;
            workWord3 = Physics50Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics50Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics50PlayerB0View2 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics50PlayerB0View2 = 2048;
            workWord2 = Physics50PlayerB0View2;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics50PlayerB0View2 = 19200;
            goto rotation33;
        nonnegative33:
            numeric4 = Physics50Player8View1;
            limit16 = 0;
            workWord2 = Physics50EvaluateClampedPlayerRootCurveView1(numeric4);
            workWord3 = Physics50Player148View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            numeric4 = workWord2;
            MATCHING_KEEP(numeric4);
            Physics50PlayerACView2 = numeric4;
            numeric5 = workWord3;
            if (!workWord3)
                goto zeroCounter33;
            workWord2 = 0x60000;
            Physics50Player130View1 = workWord2;
            workWord2 = numeric5 - 1;
            Physics50Player148View1 = workWord2;
            workWord2 <<= 16;
            if (workWord2 > 0)
                goto positiveCounter33;
            workWord3 = Physics50PlayerB0View2;
            workWord2 = workWord3 - numeric4;
            workWord2 = workWord2 < 192;
            if (workWord2) {
                workWord2 = numeric4 + 8192;
                Physics50PlayerB0View2 = workWord2;
                Physics50Player148View1 = 0;
                goto counterClamp33;
            }
            workWord2 = workWord3 - 192;
            Physics50PlayerB0View2 = workWord2;
            workWord2 = 1;
            Physics50Player148View1 = workWord2;
            goto counterClamp33;
        positiveCounter33:
            workWord2 = numeric4 + 8192;
            Physics50PlayerB0View2 = workWord2;
            limit16 = 96;
            goto counterClamp33;
        zeroCounter33:
            Physics50PlayerB0View2 = numeric4;
            __asm__ volatile("" : "=r"(limit16) : "0"(limit16) : "$3", "memory");
            Physics50Player130View1 = 0;
        counterClamp33:
            globalPointer = &Physics50PlayerB0View2;
            workWord2 = Physics50Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 22785;
            if (!workWord2)
                Physics50Field(globalPointer, int*, 0) = 22784;
            workWord2 = Physics50Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 2048;
            if (workWord2)
                Physics50Field(globalPointer, int*, 0) = 2048;
            numeric5 = Physics50Player14CView2;
            workWord3 = Physics50Player150View1;
            workWord2 = limit16 - numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics50Player150View1 = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics50Player14CView2 = numeric5;
            if (numeric5 < 0)
                Physics50Player14CView2 = 0;
            workWord2 = Physics50Player14CView2;
            workWord2 = workWord2 < 97;
            if (!workWord2)
                Physics50Player14CView2 = 96;
        rotation33:
            workWord2 = Physics50Player148View1;
            workWord2 = workWord2 < 2;
            if (workWord2)
                goto spring33;
            workWord3 = Physics50Player14AView1;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 3;
            MATCHING_KEEP(workWord2);
            workWord3 = Physics50Player5CView2;
            workWord2 <<= 11;
            Physics50Player154View1 = workWord2;
            workWord2 >>= 6;
            workWord3 += workWord2;
            workWord3 &= 4095;
            workWord2 = workWord3 < 2049;
            Physics50Player5CView2 = workWord3;
            if (workWord2)
                goto rotationDone33;
            workWord2 = workWord3 - 4096;
            goto storeAngle33;
        spring33:
            workWord2 = Physics50InterpolateCosineView2(Physics50Player60View2);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            originalLow = delta19 * workWord2;
            workWord3 = Physics50Player154View1;
            numeric5 = Physics50Player5CView2;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = originalLow >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics50Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics50Player5CView2 = numeric5;
            if (workWord2)
                goto rotationDone33;
            workWord2 = numeric5 - 4096;
        storeAngle33:
            Physics50Player5CView2 = workWord2;
        rotationDone33:
            Physics50BuildPlayerMovementVectorView1();
            call5 = &Physics50Player4CView2;
            numeric4 = Physics50Field(call5, int*, 0);
            if (numeric4)
                goto active33;
            workWord2 = (int)Physics50Data6C570View1;
            workWord2 = Physics50Field((void*)workWord2, int*, 4) & 64;
            if (!workWord2)
                goto end33;
            workWord2 = Physics50PlayerF8View1;
            workWord3 = Physics50Player8View1;
            workWord2 -= 512;
            workWord3 = workWord3 < workWord2;
            if (!workWord3)
                goto end33;
            workWord3 = Physics50Player48View1;
            workWord2 = 33;
            if (workWord3 != workWord2)
                goto end33;
            workWord2 = 1;
            Physics50Field(call5, int*, 0) = workWord2;
            __asm__ volatile("" ::: "$4", "memory");
            Physics50Player160View1 = 0;
            goto end33;
        active33:
            workWord2 = Physics50Player8View1;
            workWord3 = Physics50PlayerF8View1;
            workWord2 = workWord2 < workWord3;
            if (workWord2) {
                workWord2 = 1;
                goto activeRemainder33;
            }
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics50Field(call5, int*, 0) = 0;
            goto end33;
        activeRemainder33:
            if (numeric4 != workWord2)
                goto decline33;
            workWord2 = Physics50Player160View1;
            workWord2 += 512;
            Physics50Player160View1 = workWord2;
            workWord2 = workWord2 < 6144;
            if (!workWord2) {
                workWord2 = 6144;
                Physics50Player160View1 = workWord2;
                workWord2 = 2;
                Physics50Field(call5, int*, 0) = workWord2;
            }
            goto add88;
        decline33:
            workWord2 = Physics50Player160View1;
            workWord2 -= 256;
            Physics50Player160View1 = workWord2;
            if (workWord2 <= 0) {
                Physics50Player160View1 = 0;
                Physics50Field(call5, int*, 0) = 0;
            }
        add88:
            {
                register void* pointer2 __asm__("$2");
                pointer2 = &Physics50Player88View2;
                workWord3 = Physics50Field(pointer2, int*, 0);
                numeric4 = Physics50Player160View1;
                workWord3 += numeric4;
                Physics50Field(pointer2, int*, 0) = workWord3;
            }
        end33:
            goto finishPhysics50;
        }
        case 36:
        case 37:
        case 48: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics50BuildOrientedInputPairView1(&originalFrame.sp60, 0);
            workWord2 = originalFrame.sp60;
            call5 = &Physics50PlayerA8View2;
            workWord3 = workWord2 * 9;
            workWord3 <<= 2;
            workWord2 -= workWord3;
            workWord3 = Physics50Field(call5, int*, 0);
            numeric4 = workWord2 >> 7;
            workWord2 = workWord3 < numeric4;
            if (workWord2) {
                workWord2 = workWord3 + 8;
                Physics50Field(call5, int*, 0) = workWord2;
                workWord2 = numeric4 < workWord2;
            } else {
                workWord2 = workWord3 - 8;
                Physics50Field(call5, int*, 0) = workWord2;
                workWord2 = workWord2 < numeric4;
            }
            if (workWord2)
                Physics50Field(call5, int*, 0) = numeric4;
            workWord3 = Physics50Player4CView3;
            workWord2 = 5;
            if (workWord3 == workWord2) {
                workWord3 = Physics50Player68View1;
                numeric4 = Physics50Player6CView1;
                workWord2 = (workWord3 << 5) >> 9;
                workWord3 -= workWord2;
                workWord2 = (numeric4 << 5) >> 9;
                Physics50Player68View1 = workWord3;
                workWord3 = originalFrame.sp60;
                numeric4 -= workWord2;
                Physics50Player6CView1 = numeric4;
                numeric4 = Physics50Player70View1;
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
            workWord2 = Physics50Data6E538View1 & 16;
            if (!workWord2)
                goto default48;
            workWord2 = originalFrame.sp60;
            numeric4 = Physics50Player68View1;
            numeric5 = Physics50Player6CView1;
            workWord3 = (workWord2 * 48) >> 8;
            workWord2 = (numeric4 << 5) >> 9;
            workWord3 -= workWord2;
            workWord2 = originalFrame.sp64;
            numeric4 += workWord3;
            Physics50Player68View1 = numeric4;
            numeric4 = Physics50Player70View1;
            workWord3 = (workWord2 * 48) >> 8;
            workWord2 = (numeric5 << 5) >> 9;
            workWord3 -= workWord2;
            numeric5 += workWord3;
            workWord2 = (numeric4 << 5) >> 9;
            Physics50Player6CView1 = numeric5;
            numeric4 -= workWord2;
            goto store70;
        default48:
            globalVector80 = &Physics50PlayerA8View2;
            call4 = globalVector80 - 16;
            workWord2 = Physics50Field(globalVector80, int*, 0);
            call5 = 0;
            workWord2 = -workWord2;
            signedWord20 = workWord2 << 3;
            workWord2 = Physics50MeasureVectorLengthView2(call4, call5);
            call4 = (void*)workWord2;
            call5 = (void*)Physics50PlayerA0View1;
            workWord2 = Physics50PlanarHeadingLookupView1(call4, call5, 1);
            signedWord19 = workWord2 & 4095;
            workWord2 = signedWord19 < 2049;
            if (!workWord2) {
                signedWord19 -= 4096;
                workWord2 = signedWord19 < -256;
            } else
                workWord2 = signedWord19 < -256;
            if (workWord2)
                signedWord19 = -256;
            workWord2 = Physics50Player5CView3;
            workWord2 = signedWord20 - workWord2;
            signedWord20 = workWord2 & 4095;
            workWord2 = signedWord20 < 2049;
            if (!workWord2)
                signedWord20 -= 4096;
            workWord2 = Physics50Player60View3;
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
            numeric4 = Physics50Player68View1;
            signedWord21 = Physics50Field(globalVector80, int*, 0);
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
            workWord3 = signedWord19 << 2;
            Physics50Player68View1 = numeric4;
            numeric4 = Physics50Player6CView1;
            workWord3 >>= 4;
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
            workWord3 = signedWord21 << 2;
            Physics50Player6CView1 = numeric4;
            numeric4 = Physics50Player70View1;
            workWord3 >>= 4;
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
        store70:
            Physics50Player70View1 = numeric4;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = 4;
            signedWord20 = Physics50Player68View1;
            signedWord19 = Physics50Player6CView1;
            signedWord21 = Physics50Player70View1;
            workWord3 = Physics50Player4CView3;
            signedWord20 >>= 2;
            if (workWord3 == workWord2) {
                workWord2 = Physics50Data6E538View1 & 16;
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
            workWord2 = (unsigned int)(Physics50Player4CView3 - 4) < 2;
            globalVector80 = &originalFrame.sp68;
            if (workWord2) {
                call4 = Physics50Field(&Physics50Player0View3, void**, 0x250);
                if (call4) {
                    call4 = Physics50Field(call4, void**, 0);
                    workWord2 = Physics50Field(call4, int*, 0xF4);
                    workWord3 = Physics50Field(call4, int*, 0xFC);
                    workWord2 += signedWord20;
                    Physics50Field(call4, int*, 0xF4) = workWord2;
                    workWord2 = Physics50Field(call4, int*, 0xF8);
                    workWord3 += signedWord21;
                    Physics50Field(call4, int*, 0xFC) = workWord3;
                    workWord2 += signedWord19;
                    Physics50Field(call4, int*, 0xF8) = workWord2;
                }
            }
            call4 = globalVector80;
            globalVector8CState20 = &originalFrame.sp70;
            call5 = globalVector8CState20;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            savedPointer22 = &Physics50Player5CView3;
            workWord2 = Physics50Field(savedPointer22, int*, 0);
            workWord3 = Physics50Player64View3;
            __asm__ volatile("" ::"r"(workWord2), "r"(workWord3) : "$17", "memory");
            savedPointer17 = &originalFrame.sp88;
            Physics50Field(&originalFrame.sp68, short*, 0) = workWord2;
            workWord2 = Physics50Player60View3;
            call6 = savedPointer17;
            Physics50Field(&originalFrame.sp6C, short*, 0) = workWord3;
            workWord2 = -workWord2;
            Physics50Field(&originalFrame.sp68, short*, 2) = workWord2;
            Physics50BuildEulerBasisPairView1(call4, call5, call6);
            Physics50TransposePackedHalfwordMatrix3x3View1(globalVector8CState20,
                                                           globalVector8CState20);
            call4 = globalVector80;
            call5 = savedPointer17;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            globalVector80 = &originalFrame.spA0;
            call6 = globalVector80;
            Physics50Field(&originalFrame.sp68, short*, 0) = signedWord20;
            Physics50Field(&originalFrame.sp68, short*, 2) = signedWord19;
            Physics50Field(&originalFrame.sp6C, short*, 0) = signedWord21;
            Physics50BuildEulerBasisPairView1(call4, call5, call6);
            Physics50TransposePackedHalfwordMatrix3x3View1(savedPointer17, savedPointer17);
            Physics50MultiplyPackedGteMatricesView1(globalVector8CState20, savedPointer17,
                                                    globalVector80);
            Physics50WriteBasisAngleTripletView1(savedPointer22, globalVector80);
            workWord2 = Physics50Player164View1;
            if (workWord2) {
                workWord2 = 14208;
                Physics50PlayerACView3 = workWord2;
                workWord2 = 96;
                goto update16C;
            }
            workWord2 = 9280;
            Physics50PlayerACView3 = workWord2;
            workWord2 = 0;
        update16C:
            savedPointer17 = &Physics50Player16CView1;
            numeric5 = Physics50Player168View1;
            workWord3 = Physics50Field(savedPointer17, int*, 0);
            workWord2 -= numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics50Field(savedPointer17, int*, 0) = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics50Player168View1 = numeric5;
            if (numeric5 < 0)
                Physics50Player168View1 = 0;
            workWord2 = Physics50Player168View1;
            workWord2 = workWord2 < 97;
            call4 = (void*)576;
            if (!workWord2) {
                workWord2 = 96;
                Physics50Player168View1 = workWord2;
            }
            Physics50ApproachPlayerTargetSpeedView4(call4, 48);
            Physics50BuildPlayerMovementVectorView4();
            workWord3 = Physics50Player4CView3;
            workWord2 = 4;
            if (workWord3 != workWord2)
                goto maybeFive48;
            workWord2 = Physics50Data6E538View1 & 16;
            if (workWord2)
                goto subtract128;
            globalVector80 = &originalFrame.spB8;
            call4 = globalVector80;
            call5 = savedPointer17 - 236;
            __asm__ volatile(""
                             : "=r"(savedPointer17)
                             : "0"(savedPointer17), "r"(call4), "r"(call5)
                             : "memory");
            savedPointer17 -= 224;
            Physics50SubtractVectorView2(call4, call5, savedPointer17);
            originalFrame.spC0 = 0;
            call5 = (void*)Physics50MeasureVectorLengthView2(globalVector80, 0);
            workWord2 = (int)call5 < 385;
            call4 = savedPointer17;
            if (!workWord2) {
                Physics50ScaleVectorRatioQ15View2(globalVector80, call5, 384);
                call4 = savedPointer17;
            }
            call5 = call4;
            Physics50AddVectorView4(call4, call5, globalVector80);
        subtract128:
            globalPointer = &Physics50Player94View4;
            workWord2 = Physics50Field(globalPointer, int*, 0);
            workWord2 -= 128;
            Physics50Field(globalPointer, int*, 0) = workWord2;
            goto clampPhysics32PointerReady;
        maybeFive48:
            workWord2 = 5;
            if (workWord3 != workWord2)
                goto gate48;
            globalVector80 = &originalFrame.spC8;
            call4 = globalVector80;
            __asm__ volatile(""
                             : "=r"(savedPointer17)
                             : "0"(savedPointer17), "r"(call4)
                             : "memory");
            savedPointer17 -= 224;
            Physics50CopyVectorView4(call4, savedPointer17);
            originalFrame.spD0 = 0;
            call5 = (void*)Physics50MeasureVectorLengthView2(globalVector80, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics50ScaleVectorRatioQ15View2(globalVector80, call5, 64);
            workWord2 = 128;
            originalFrame.spD0 = workWord2;
            call4 = savedPointer17;
            call5 = call4;
            Physics50SubtractVectorView2(call4, call5, globalVector80);
            goto clampPhysics32;
        gate48:
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto flags48;
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto flags48;
            workWord2 = (int)Physics50Data6C570View3;
            workWord2 = Physics50Field((void*)workWord2, int*, 0) & 64;
            if (!workWord2)
                goto flags48;
            workWord2 = Physics50Player80View2;
            workWord3 = Physics50Player94View4;
            numeric4 = Physics50Player84View2;
            workWord3 -= 64;
            Physics50Player8CView3 = workWord2;
            Physics50Player90View2 = numeric4;
            Physics50Player94View4 = workWord3;
            goto clampPhysics32;
        flags48:
            call6 = &Physics50PlayerFCView1;
            workWord2 = Physics50Field(call6, unsigned char*, 0);
            if (workWord2)
                goto copy48;
            workWord2 = Physics50PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector48;
        copy48:
            workWord2 = Physics50Player80View2;
            workWord3 = Physics50PlayerA0View1;
            numeric4 = Physics50Player84View2;
            workWord3 -= 192;
            Physics50Player8CView3 = workWord2;
            Physics50Player90View2 = numeric4;
            Physics50Player94View4 = workWord3;
            Physics50PlayerA0View1 = workWord3;
            goto clampPhysics32;
        vector48:
            call5 = call6 - 124;
            Physics50AddVectorView4(call4, call5, call6 - 20);
            goto clampPhysics32;
        clampPhysics32:
            globalPointer = &Physics50Player94View4;
        clampPhysics32PointerReady:
            workWord2 = Physics50Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics50Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics50Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics50Field(call5, int*, 0) & 64;
            call4 = &originalFrame.spD8;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics50UpdateSmoothedInputPairView2(call4, call5, 0);
            workWord3 = Physics50Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics50Player60View1;
                numeric4 = Physics50Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric4 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.spDC = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.spDC = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                workWord2 = originalFrame.spDC;
                workWord3 = numeric4 + 1;
                Physics50Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.spDC = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics50Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.spD8 * 0x14) >> 7;
            Physics50Field(&Physics50Player0View2, int*, 0x64) =
                (int)((Physics50Field(&Physics50Player0View2, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics50Field(&Physics50Player0View2, int*, 0x60) +
                               ((int)(originalFrame.spDC * -0xF) >> 7)) &
                              0xFFF;
            Physics50Field(&Physics50Player0View2, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics50Field(&Physics50Player0View2, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x60) < -0x320) {
                Physics50Field(&Physics50Player0View2, int*, 0x60) = -0x320;
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x60) >= 0x321) {
                Physics50Field(&Physics50Player0View2, int*, 0x60) = 0x320;
            }
            if ((*Physics50Data6C570View2 & 0x40) ||
                (Physics50Field(&Physics50Player0View2, int*, 0x4C) == 1)) {
                Physics50Field(&Physics50Player0View2, int*, 0xAC) = 0xE00;
            } else {
                Physics50Field(&Physics50Player0View2, int*, 0xAC) = 0;
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x4C) == 2) {
                Physics50ApproachPlayerTargetSpeedView2(0xC0, 0xC0);
                if (Physics50Field(&Physics50Player0View2, int*, 0xB0) < 0xE01) {
                    Physics50Field(&Physics50Player0View2, int*, 0x4C) = 0;
                }
            } else {
                Physics50ApproachPlayerTargetSpeedView2(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics50Player0View2 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics50InterpolateCosineView3(
                                                Physics50Field(&Physics50Player0View2, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics50Field(&Physics50Player0View2, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics50Field(&Physics50Player0View2, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics50Field(&Physics50Player0View2, int*, 0x14C) + raw21_temp_a0_5;
            Physics50Field(&Physics50Player0View2, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics50Field(&Physics50Player0View2, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics50Field(&Physics50Player0View2, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics50Field(&Physics50Player0View2, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x5C) < -0x300) {
                Physics50Field(&Physics50Player0View2, int*, 0x5C) = -0x300;
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x5C) >= 0x301) {
                Physics50Field(&Physics50Player0View2, int*, 0x5C) = 0x300;
            }
            Physics50BuildPlayerMovementVectorView2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics50CopyVectorView2(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics50CallRandView2() & 31;
            if (workWord2)
                goto block_130;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto block_130;
            call5 = (void*)44;
            call6 = &originalFrame.spE0;
            particleArg7 = 0;
            MATCHING_KEEP(particleArg7);
            workWord2 = 544;
            originalFrame.spE0 = workWord2;
            workWord2 = 64;
            originalFrame.spE4 = 0;
            __asm__ volatile("" ::"i"(0x8009BD54) : "memory");
            originalFrame.spE8 = workWord2;
            goto block_129;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics50Player0View2 + 0x20C;
            if (!(Physics50Field(&Physics50Player0View2, int*, 0x20C) & 0x40)) {
                if (Physics50Data6E044View2 != 7) {
                    Physics50UpdateSmoothedInputPairView2(&originalFrame.spE0,
                                                          raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.spE0;
                    numeric4 = originalFrame.spE4;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics50Player64View1;
                    workWord2 = Physics50Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics50Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics50Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics50Player60View1 = workWord2;
                    }
                    if (Physics50Field(&Physics50Player0View2, int*, 0x60) < -0x320) {
                        Physics50Field(&Physics50Player0View2, int*, 0x60) = -0x320;
                    }
                    if (Physics50Field(&Physics50Player0View2, int*, 0x60) >= 0x321) {
                        Physics50Field(&Physics50Player0View2, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics50InterpolateCosineView3(Physics50Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics50Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics50Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics50Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics50Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics50Player5CView1 = workWord2;
                    }
                    if (Physics50Field(&Physics50Player0View2, int*, 0x5C) < -0x300) {
                        Physics50Field(&Physics50Player0View2, int*, 0x5C) = -0x300;
                    }
                    if (Physics50Field(&Physics50Player0View2, int*, 0x5C) >= 0x301) {
                        Physics50Field(&Physics50Player0View2, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics50Player0View2 + 0x80;
                Physics50ClearVectorView2(raw21_temp_s0_9);
                Physics50ClearVectorView2(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics50CallRandView2() & 31;
                if (workWord2)
                    goto block_130;
                MATCHING_KEEP(workWord2);
                particleCall3 = Physics21_SpawnParticle;
                call4 = (void*)1;
                if (!particleCall3)
                    goto block_130;
                call5 = (void*)44;
                call6 = &originalFrame.spF0;
                particleArg7 = 0;
                MATCHING_KEEP(particleArg7);
                workWord2 = 544;
                originalFrame.spF0 = workWord2;
                workWord2 = 64;
                originalFrame.spF4 = 0;
                originalFrame.spF8 = workWord2;
            block_129:
                particleCall3(call4, call5, call6, particleArg7);
            block_130:
                globalPointer = &Physics50Player158View1;
                workWord2 = Physics50Field(globalPointer, int*, 0);
                workWord2++;
                Physics50Field(globalPointer, int*, 0) = workWord2;
                return;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics50Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics50Field(call5, int*, 0) & 64;
            call4 = &originalFrame.spF0;
            if (!workWord2)
                goto run42;
        block_132:
            Physics50PlayerACView1 = 0;
            Physics50PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics50UpdateSmoothedInputPairView2(call4, call5, 0);
            workWord3 = Physics50Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics50Player60View1;
                numeric5 = Physics50Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.spF4 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.spF4 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.spF4;
                workWord3 = numeric5 + 1;
                Physics50Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.spF4 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics50Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics50Player0View2 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.spF0 * 0x14) >> 7;
            Physics50Field(&Physics50Player0View2, int*, 0x64) =
                (int)((Physics50Field(&Physics50Player0View2, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics50Field(&Physics50Player0View2, int*, 0x60) +
                                ((int)(originalFrame.spF4 * -0xF) >> 7)) &
                               0xFFF;
            Physics50Field(&Physics50Player0View2, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics50Field(&Physics50Player0View2, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x60) < -0x320) {
                Physics50Field(&Physics50Player0View2, int*, 0x60) = -0x320;
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x60) >= 0x321) {
                Physics50Field(&Physics50Player0View2, int*, 0x60) = 0x320;
            }
            Physics50Field(&Physics50Player0View2, int*, 0xAC) = 0x1C00;
            Physics50ApproachPlayerTargetSpeedView2(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics50InterpolateCosineView3(
                                                 Physics50Field(&Physics50Player0View2, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics50Field(&Physics50Player0View2, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics50Field(&Physics50Player0View2, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics50Field(&Physics50Player0View2, int*, 0x14C) + raw21_temp_a0_6;
            Physics50Field(&Physics50Player0View2, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics50Field(&Physics50Player0View2, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics50Field(&Physics50Player0View2, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics50Field(&Physics50Player0View2, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x5C) < -0x300) {
                Physics50Field(&Physics50Player0View2, int*, 0x5C) = -0x300;
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x5C) >= 0x301) {
                Physics50Field(&Physics50Player0View2, int*, 0x5C) = 0x300;
            }
            Physics50BuildPlayerMovementVectorView2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics50CopyVectorView2(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics50Field(&Physics50Player0View2, int*, 0xB4) >= 0x7D1)) {
                originalFrame.sp100 = -0x190;
                originalFrame.sp104 = 0x40 - (Physics50CallRandView2() & 0x7F);
                originalFrame.sp108 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp100, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics50Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics50Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            call4 = &Physics50Player80View1;
            MATCHING_KEEP(call4);
            Physics50ClearVectorView2(call4);
            call4 = &Physics50Player8CView2;
            MATCHING_KEEP(call4);
            Physics50ClearVectorView2(call4);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics50Data6E044View2;
            if (workWord3 == workWord2) {
                Physics50Field(&Physics50Player0View2, int*, 0xB0) = 0;
            } else {
                Physics50UpdatePlayerGroundInputTargetsView2(0x980);
                raw21_var_v0_2 = Physics50ApproachPlayerTargetHeadingView2(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics50Field(&Physics50Player0View2, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics50Field(&Physics50Player0View2, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics50ApproachPlayerTargetSpeedView2(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics50Player0View2 + 0xB0;
            if (Physics50Field(&Physics50Player0View2, int*, 0xB0) != 0) {
                Physics50BuildPlayerMovementVectorView2();
                Physics50BuildPlayerResponseVectorView2();
                Physics50Field(&Physics50Player0View2, int*, 0x94) = 0;
            } else {
                Physics50ClearVectorView2(raw21_temp_s0_11 - 0x30);
                Physics50ClearVectorView2(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics50Player0View2 + 0x28;
                if (Physics50Field(&Physics50Player0View2, int*, 0x28) < 0) {
                    if ((Physics50Field(&Physics50Player0View2, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics50Data6C640View2 & 1)) {
                        Physics50CopyVectorView2(&originalFrame.sp100, raw21_temp_s4 - 0x28);
                        originalFrame.sp114 = 0x40;
                        originalFrame.sp118 = 0;
                        originalFrame.sp110 =
                            (int)Physics50Field(&Physics50Player0View2, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp114 = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics50TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp110,
                                                             &originalFrame.sp120);
                        Physics50AddVectorView3(&originalFrame.sp100, &originalFrame.sp100,
                                                &originalFrame.sp120);
                        originalFrame.sp110 = 0;
                        originalFrame.sp108 = -Physics50Field(&Physics50Player0View2, int*, 0x28);
                        Physics50TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp110,
                                                             &originalFrame.sp110);
                        Physics50ShiftVectorRightTowardZeroView1(&originalFrame.sp110, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp100,
                                                &originalFrame.sp110);
                        if (!(Physics50CallRandView2() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp100, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics50Player0View2 + 0xB0;
                        if ((Physics50Field(&Physics50Player0View2, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics50Data6C640View2 & 7) &&
                            !(Physics50CallRandView2() & 3)) {
                            originalFrame.sp130 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp134 = 0;
                            originalFrame.sp138 = 0;
                            Physics50TransformVectorByBasisView2(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp130, &originalFrame.sp130);
                            Physics50AddVectorView3(&originalFrame.sp130, &originalFrame.sp130,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp138 =
                                -Physics50Field(&Physics50Player0View2, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp130, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics50Field(&Physics50Player0View2, int*, 0x144) -
                ((int)((Physics50Field(&Physics50Player0View2, int*, 0x148) * 2) +
                       (Physics50Field(&Physics50Player0View2, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics50Field(&Physics50Player0View2, int*, 0x148) + raw21_temp_a1_4;
            Physics50Field(&Physics50Player0View2, int*, 0x144) = raw21_temp_a1_4;
            Physics50Field(&Physics50Player0View2, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics50Field(&Physics50Player0View2, int*, 0x148) = 0x5900;
            }
            if (Physics50Field(&Physics50Player0View2, int*, 0x148) < -0x5900) {
                Physics50Field(&Physics50Player0View2, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 57:
            if ((workWord2 = combinedIndex < 9) == 0) {
                Physics50Field(&Physics50Player0View2, int*, 0x80) =
                    (int)(Physics50Field(&Physics50Player0View2, int*, 0x8C) * 0xF8);
                Physics50Field(&Physics50Player0View2, int*, 0x84) =
                    (int)(Physics50Field(&Physics50Player0View2, int*, 0x90) * 0xF8);
                Physics50Field(&Physics50Player0View2, int*, 0x88) =
                    (int)(Physics50Field(&Physics50Player0View2, int*, 0x94) * 0xF8);
                Physics50ShiftVectorRightTowardZeroView1(&Physics50Player0View2 + 0x80, 8);
            }
        block_188:
            call4 = &Physics50Player0View2 + 0x8C;
            call5 = call4 - 12;
            Physics50CopyVectorView2(call4, call5);
            return;
        case 27:
        case 60: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta18 __asm__("$18");
            register int delta19 __asm__("$19");
            register void* pointer17 __asm__("$17");
            register void* pointer16 __asm__("$16");
            register int limit16 __asm__("$16");
            int originalLow0, originalLow1, originalLow2;
            pointer17 = &Physics50Player50View1;
            workWord3 = Physics50Field(pointer17, int*, 0);
            workWord2 = 6;
            if (workWord3 != workWord2)
                goto ground27;
            Physics50UpdateSmoothedInputPairView4(&originalFrame.sp140, pointer17 + 260, 0);
            workWord2 = originalFrame.sp144;
            numeric4 = Physics50Player94View3;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp140;
            numeric4 -= 1024;
            originalFrame.sp150 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                pointer16 = &originalFrame.sp148;
                call4 = pointer16;
                call5 = pointer16;
                __asm__ volatile(""
                                 : "=r"(pointer17)
                                 : "0"(pointer17), "r"(call4), "r"(call5)
                                 : "memory");
                pointer17 -= 80;
                call6 = pointer17;
                workWord2 = Physics50Player8CView1;
                workWord3 = Physics50Player90View1;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp148 = workWord2;
                originalFrame.sp14C = workWord3;
                Physics50AddVectorView2(call4, call5, call6);
                if (!Physics50TestSubdividedSegmentPathView1(pointer17, pointer16, 2)) {
                    workWord2 = Physics50Player8View1;
                    workWord3 = Physics50Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp144 = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp144 = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp144;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics50PlayerF8View1;
            workWord3 = Physics50Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics50Player60View2;
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
            call4 = &Physics50Player64View2;
            workWord2 = Physics50Field(call4, int*, 0);
            workWord3 = Physics50Player60View2;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics50Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics50Player60View2 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics50Player60View2 = workWord2;
            }
            workWord2 = Physics50Player60View2;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics50Player60View2 = -800;
            workWord2 = Physics50Player60View2;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics50Player60View2 = 800;
            workWord3 = Physics50Player60View2;
            if (workWord3 >= 0)
                goto positive27;
            numeric4 = Physics50Data67634View1;
            workWord2 = Physics50Data67630View1;
            workWord2 = numeric4 - workWord2;
            goto quotient27;
        positive27:
            if (workWord3 <= 0)
                goto zero27;
            workWord2 = Physics50Data67638View1;
            numeric4 = Physics50Data67634View1;
            workWord2 -= numeric4;
        quotient27:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics50PlayerACView2 = numeric4;
            goto speed27;
        zero27:
            workWord2 = Physics50Data67634View1;
            Physics50PlayerACView2 = workWord2;
        speed27:
            call5 = &Physics50Player144View2;
            workWord2 = Physics50PlayerACView2;
            numeric4 = Physics50PlayerB0View2;
            workWord3 = Physics50Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics50Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics50PlayerB0View2 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics50PlayerB0View2 = 2048;
            workWord2 = Physics50PlayerB0View2;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics50PlayerB0View2 = 19200;
            goto spring27;
        spring27:
            workWord2 = Physics50InterpolateCosineView2(Physics50Player60View2);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            originalLow0 = delta19 * workWord2;
            workWord3 = Physics50Player154View1;
            numeric5 = Physics50Player5CView2;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = originalLow0 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics50Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics50Player5CView2 = numeric5;
            if (workWord2)
                goto rotationDone27;
            workWord2 = numeric5 - 4096;
        storeAngle27:
            MATCHING_KEEP(workWord2);
            Physics50Player5CView2 = workWord2;
        rotationDone27:
            Physics50BuildPlayerMovementVectorView1();
        finishPhysics50:
            Physics50BuildPlayerResponseVectorView3();
            return;
        ground27:
            Physics50UpdatePlayerGroundInputTargetsView3(4608);
            workWord2 = Physics50PlayerACView1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            limit16 = 4608;
            MATCHING_KEEP(limit16);
            workWord2 <<= 5;
            delta18 = workWord2 / limit16;
            Physics50ClearVectorView3(pointer17 + 48);
            pointer17 = &Physics50Data6E538View2;
            workWord2 = Physics50Field(pointer17, int*, 0);
            workWord2 &= 12;
            delta18 += 32;
            if (!workWord2)
                goto noInput27;
            Physics50ApproachPlayerTargetHeadingView4(25, 5);
            workWord2 = Physics50PlayerB4View1;
            workWord3 = Physics50PlayerACView1;
            workWord2 = workWord2 < 2048;
            Physics50PlayerB0View1 = workWord3;
            if (workWord2) {
                workWord2 = delta18 << 1;
                delta18 += workWord2;
            }
            workWord3 = Physics50Field(pointer17, int*, 0);
            workWord2 = workWord3 & 8;
            if (workWord2) {
                Physics50Player84View1 = -4608;
                goto rotateGround27;
            }
            workWord2 = workWord3 & 4;
            if (workWord2)
                Physics50Player84View1 = limit16;
        rotateGround27:
            call4 = &Physics50Player30View1;
            call5 = call4 + 80;
            Physics50TransformVectorByBasisView3(call4, call5, call5);
            goto velocity27;
        noInput27:
            workWord2 = Physics50SubAngle12View1(Physics50Data6E040View1, Physics50PlayerA4View1);
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 1800;
            if (workWord2) {
                Physics50ApproachPlayerTargetHeadingView4(25, 5);
                workWord2 = Physics50PlayerACView1;
                Physics50PlayerB0View1 = workWord2;
            }
        velocity27:
            pointer16 = &Physics50PlayerA4View1;
            workWord2 = Physics50InterpolateCosineView5(Physics50Field(pointer16, int*, 0));
            workWord3 = Physics50PlayerACView1;
            originalLow1 = workWord3 * workWord2;
            call4 = (void*)Physics50Field(pointer16, int*, 0);
            workWord2 = Physics50Player80View1;
            workWord3 = originalLow1 >> 12;
            workWord2 += workWord3;
            Physics50Player80View1 = workWord2;
            workWord2 = Physics50InterpolateSineView2(call4);
            workWord3 = Physics50PlayerACView1;
            originalLow2 = workWord3 * workWord2;
            call4 = pointer16 - 12;
            Physics50Player88View1 = 0;
            workWord2 = Physics50Player84View1;
            workWord3 = originalLow2 >> 12;
            workWord2 += workWord3;
            Physics50Player84View1 = workWord2;
            workWord2 = Physics50MeasureVectorLengthView3(call4, 0);
            workWord2 = workWord2 < 256;
            pointer16 -= 24;
            if (!workWord2)
                goto vectors27;
            workWord2 = Physics50MeasureVectorLengthView3(pointer16, 0);
            workWord2 = workWord2 < 2049;
            if (!workWord2)
                Physics50ClearVectorView3(pointer16);
        vectors27:
            pointer16 = &originalFrame.sp120;
            call4 = pointer16;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = &Physics50Player80View1;
            pointer17 = call5 + 12;
            Physics50SubtractVectorView3(call4, call5, pointer17);
            originalFrame.sp128 = 0;
            workWord2 = Physics50MeasureVectorLengthView3(pointer16, 0);
            numeric5 = workWord2;
            workWord2 = delta18 < numeric5;
            call4 = pointer16;
            if (workWord2)
                Physics50ScaleVectorRatioQ15View3(call4, numeric5, delta18);
            call4 = pointer17;
            call5 = call4;
            Physics50AddVectorView5(call4, call5, pointer16);
            workWord2 = -3072;
            goto store94From2;
        }
        case 150:
        case 151: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta17 __asm__("$17");
            register void* pointer16 __asm__("$16");
            int product150;
            Physics50UpdateSmoothedInputPairView3(&originalFrame.sp140, &Physics50Player14CView1,
                                                  0);
            workWord2 = originalFrame.sp144;
            workWord3 = workWord2 << 4;
            workWord2 -= workWord3;
            workWord3 = originalFrame.sp140;
            numeric5 = workWord2 >> 7;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            workWord3 = Physics50PlayerF4View1;
            delta17 = workWord2 >> 7;
            if (!workWord3)
                goto rotate150;
            numeric4 = Physics50Player60View1;
            if (numeric4 <= 0)
                goto rotate150;
            workWord2 = Physics50Player8View2;
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
            call4 = &Physics50Player64View1;
            workWord2 = Physics50Field(call4, int*, 0);
            workWord3 = Physics50Player60View1;
            workWord2 += delta17;
            workWord2 &= 4095;
            workWord3 += numeric5;
            workWord3 &= 4095;
            Physics50Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics50Player60View1 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics50Player60View1 = workWord2;
            }
            workWord2 = Physics50Player60View1;
            workWord2 = workWord2 < -512;
            if (workWord2)
                Physics50Player60View1 = -512;
            workWord2 = Physics50Player60View1;
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics50Player60View1 = 512;
            workWord3 = Physics50Player48View2;
            workWord2 = 151;
            MATCHING_KEEP(workWord2);
            if (workWord3 == workWord2)
                workWord2 = 8192;
            else
                workWord2 = 1088;
            Physics50PlayerACView1 = workWord2;
            __asm__ volatile("" ::: "$4", "$5", "memory");
            numeric5 = 0x51EB0000;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(numeric5, "memory");
            call4 = &Physics50PlayerACView1;
            workWord2 = Physics50Field(call4, int*, 0);
            workWord3 = workWord2 * 5;
            workWord2 = workWord3 << 4;
            workWord2 -= workWord3;
            workWord2 <<= 1;
            workWord3 = workWord2 / 100;
            Physics50Field(call4, int*, 0) = workWord3;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord3 = Physics50Player48View2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord3, "memory");
            workWord2 = 151;
            MATCHING_KEEP(workWord2);
            call4 = (void*)192;
            if (workWord3 == workWord2)
                call4 = (void*)384;
            Physics50ApproachPlayerTargetSpeedView3(call4, 48);
            pointer16 = &Physics50Player60View1;
            workWord2 = Physics50InterpolateCosineView4(Physics50Field(pointer16, int*, 0));
            workWord3 = workWord2 * 3;
            workWord3 <<= 3;
            workWord3 = -workWord3;
            product150 = delta17 * workWord3;
            workWord3 = Physics50Player14CView1;
            numeric5 = Physics50Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = product150 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics50Player14CView1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics50Player5CView1 = numeric5;
            if (!workWord2) {
                workWord2 = numeric5 - 4096;
                MATCHING_KEEP(workWord2);
                Physics50Player5CView1 = workWord2;
            }
            workWord2 = Physics50Player5CView1;
            workWord2 = workWord2 < -512;
            if (workWord2)
                Physics50Player5CView1 = -512;
            workWord2 = Physics50Player5CView1;
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics50Player5CView1 = 512;
            Physics50BuildPlayerMovementVectorView3();
            Physics50CopyVectorView3(pointer16 + 44, pointer16 + 32);
            workWord3 = Physics50PlayerF4View1;
            if (!workWord3)
                return;
            workWord2 = Physics50Player8View2;
            workWord2 = workWord3 - workWord2;
            workWord3 = Physics50Player94View2;
            workWord2 <<= 4;
            workWord3 = workWord2 < workWord3;
            if (!workWord3)
                return;
        store94From2:
            Physics50Player94View2 = workWord2;
            return;
        }
    }
    return;
}
#undef Physics50Field


extern int Callback50Word290 __asm__("D_80070328+0x290");
/* AI generated; not human reviewed. SCUS-94467 8009CF04..8009D564.
 * Baseline: verified level35_8008A2EC scalar and particle chains, adapted
 * to original level50 registers, final callback order and dispatch scope.
 * Original word/byte tables at 8006FCF0/8006FCE6 retain byte stride44,
 * numeric limits200/5096 and mask16. No sound or helper meanings are inferred.
 * Units, source producers, invocation cadence and runtime parity remain open.
 * Empty lifetime constraints emit no code; every original code/table word
 * and complete EXE/overlay hash must agree before acceptance.
 */
extern int Callback50Step __asm__("D_80070328+0x144");
extern int Callback50Z __asm__("D_80070328+8");
extern int Callback50Limit __asm__("D_80070328+0x280");
extern Spyro Callback50Player __asm__("D_80070328");
int Callback50SamplePlanarPhaseTable(int x, int y) __asm__("func_80037058");
int Callback50SoundHandleMatchesIdInStates1Or2(int soundId, int index) __asm__("func_8003BF6C");
void Callback50ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback50CapturePlayerPlanarVectorDifference(void) __asm__("func_80041AE8");
void Callback50UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback50UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
void Callback50BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
void Callback50MarkPlayerSegmentSurfaceType3Flags(void) __asm__("func_80049590");
void Callback50ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern int Callback50Word8006E344 __asm__("D_8006E344");
extern int Callback50Word8006E52C __asm__("D_8006E52C");
extern int Callback50Word8006E530 __asm__("D_8006E530");
extern int Callback50Word8006E538 __asm__("D_8006E538");
extern short Callback50Count __asm__("D_80070328+0x148");
extern int D_8006FA38, D_8006C648;
int Callback50Query(Vector3D*, int) __asm__("func_8001A358");
extern unsigned char Callback50Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback50Values[] __asm__("D_8006FCF0");
void func_level_50_8009CF04(void) {
    struct {
        Vector3D first;
        int reserved1C;
        Vector3D second;
        int reserved2C;
        int reserved[2];
    } local;
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$19");
    register Vector3D* vectorPointer __asm__("$17");
    register int* descriptor __asm__("$16");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int height __asm__("$3");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int, int, Vector3D*, Vector3D*)__asm__("$2");
    int computedValue;
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int computedValueA0 __asm__("$4");

    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int tableValue __asm__("$2");
    register int positionValueV3 __asm__("$3");
    register int valueOffset __asm__("$3");

    switch (Callback50Player.animationState) {
        case 0x35:
        case 0x36:
        case 0x96:
        case 0x97:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            goto clearSharedValue;
        default:
            return;
        case 0x15:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50ProbePlayerContactSegment();
            goto clearSharedValue;
        case 0x1C:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50ProbePlayerContactSegment();
            if ((Callback50Player.unk7a[3].z < 0) && (Callback50Player.animationStateFrames >= 4)) {
                Callback50Player.unk5 = 1;
            }
            goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5") = &Callback50Z;
            register int velocity __asm__("$6") = Callback50Step;
            register int positionValue __asm__("$2") = *zWord;
            register int tick __asm__("$3") = D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            MATCHING_KEEP(velocity);
            MATCHING_KEEP(positionValue);
            MATCHING_KEEP(tick);
            increment = velocity >> 6;
            MATCHING_KEEP(increment);
            positionValue += increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(positionValue));
            tick <<= 9;
            *zWord = positionValue;
            status = Callback50Limit;
            velocity += tick;
            Callback50Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback50Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback50Step = 0x2580;
            }
        limitsDone:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            func_8004F178(&local.first, &Callback50Player.position);
            local.first.z += 0x400;
            Callback50Player.unk4[0] = Callback50Query(&local.first, 0xC00);
            positionDelta = (int)Callback50Player.union144.a.unk13cb;
            positionValueV3 = Callback50Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
        case 0x21:
        case 0x22:
        case 0x23:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50ProbePlayerContactSegment();
            if (SpawnParticle != 0) {
                countBase = (unsigned char*)&Callback50Count;
                if (*(short*)countBase == 0)
                    goto clearSharedValue;
                secondLimit = 1;
                if (*(short*)countBase >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    vectorPointer = &local.second;
                    MATCHING_KEEP2(vectorPointer, countBase);
                    sourceBytes = countBase - 0xB0;
                    do {
                        func_8004F178(vectorPointer, (Vector3D*)sourceBytes);
                        Callback50ShiftVectorRightTowardZero(vectorPointer, 7);
                        iteration += 1;
                        sample = rand();
                        component = local.second.x;
                        sample &= 254;
                        component -= 127;
                        component += sample;
                        MATCHING_KEEP(component);
                        local.second.x = component;
                        sample = rand();
                        component = local.second.y;
                        sample &= 254;
                        component -= 127;
                        component += sample;
                        MATCHING_KEEP(component);
                        local.second.y = component;
                        sample = rand();
                        kind = 1;
                        subtype = 0x17;
                        position = sourceBytes - 0x98;
                        __asm__(""
                                : "=r"(kind), "=r"(subtype), "=r"(position)
                                : "0"(kind), "1"(subtype), "2"(position), "r"(sample)
                                : "$3", "memory");
                        component = local.second.z;
                        __asm__("" : "=r"(component) : "0"(component), "r"(sample));
                        sample &= 254;
                        component -= 127;
                        component += sample;
                        __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                        particles = SpawnParticle;
                        MATCHING_KEEP_VOLATILE_CLOBBER(particles, "$7");
                        vector = vectorPointer;
                        MATCHING_KEEP3(particles, vector, component);
                        local.second.z = component;
                        particles(kind, subtype, (Vector3D*)position, vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
        case 0x24:
        case 0x25:
        case 0x30:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50BuildNegatedNormalizedPlayerVector(0xC00);
            if ((Callback50Player.ticksSinceLastSurfaceTouch == 0) &&
                (func_80040954(Callback50Player.unk11[2]) == 9)) {
                func_8004F178(
                    (Vector3D*)((unsigned char*)&Callback50Player.ticksSinceLastSurfaceTouch +
                                0x94),
                    (Vector3D*)((unsigned char*)&Callback50Player.ticksSinceLastSurfaceTouch +
                                0x14));
                Callback50Player.union144.a.unk13da = Callback50Player.unk7a[3].z;
            }
            Callback50Player.unk4[0] = 0;
            if ((Callback50Player.unk5 == 1) && ((Callback50Player.animationStateFrames >= 0xD) ||
                                                 !(Callback50Word8006E538 & 0x40))) {
                Callback50Player.unk5 = 2;
            }
            if (Callback50Player.unk5 != 3) {
                Callback50Player.union144.a.unk13db.x = 0;
                Callback50Player.union144.a.unk13db.y = 0;
                return;
            }
            break;
        case 0x28:
        case 0x29:
        case 0x39:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            descriptor = &Callback50Player.unk22[2];
            if (Callback50SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback50Values + valueOffset);
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
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50MarkPlayerSegmentSurfaceType3Flags();
            descriptor = &Callback50Player.unk22[2];
            if (Callback50SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback50Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback50Player.unk22[2];
            }
            if (Callback50SoundHandleMatchesIdInStates1Or2((int)D_8006C654->underwater,
                                                           *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback50Values + valueOffset);
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
                *(int*)(Callback50Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback50Flags[flagOffset] = Callback50Flags[flagOffset] | 0x10;
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50CapturePlayerPlanarVectorDifference();
            if ((unsigned char)Callback50Player.unk10[4] != 0) {
                computedValueA0 = -Callback50Player.unk9ha[4] -
                                  Callback50SamplePlanarPhaseTable(Callback50Player.position.x,
                                                                   Callback50Player.position.y);
                positionValueV3 = Callback50Player.unk4a - computedValueA0;
                Callback50Player.unk4[0] = computedValueA0;
                positionDelta = (int)Callback50Player.union144.a.unk13cc >> 6;
                goto storePosition;
            }
            break;
        storePosition:
            positionValueV3 -= positionDelta;
            MATCHING_KEEP(positionValueV3);
            Callback50Player.position.z = positionValueV3;
            return;
        case 0x3A:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            Callback50Player.cheatColour.a = 0xFF;
            Callback50Player.unk4[0] = 0;
            Callback50Player.cheatColour.b = 0x20;
            Callback50Player.cheatColour.g = 0x20;
            Callback50Player.cheatColour.r = 0x20;
            return;
        case 0x1B:
        case 0x3C:
            Callback50UpdatePlayerCollisionResponse();
            Callback50UpdatePlayerSurfaceState();
            if (Callback50Player.movementState != MOVEMENT_STATE_SUPERFLY)
                goto clearSharedValue;
        call41930:
            Callback50ProbePlayerContactSegment();
        clearSharedValue:
            Callback50Player.unk4[0] = 0;
            return;
    }
}

#define LEVEL_ID 50
#define PlaySpyroSounds_level_50 func_level_50_8009D568
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_50_8009D6E0(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
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
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3b:
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

        case 0x1e:
        case 0x2b:
        case 0x2c:
        case 0x35:
        case 0x36:
        case 0x3a:
            func_80043ABC(&spyro.unk9e);
            break;
        case 0x1b:
        case 0x3c:
            if (*(int*)((char*)&spyro + 0x50) != 6)
                func_80043ABC(0);
            break;
        case 0x15:
        case 0x1c:
            func_80043ABC(0);
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8009D770.
 * Reuses verified32 water/vector/skateboard/table,10 fly and37 death.
 * Original50 class2F5/F0 branch, pointer250 helpers14C/98, state12/B0/300;
 * shared sound after39 and independent35/36. Numeric offsets are bytes;
 * word60 wrap vectors800/801/FFF give0/-7FF/-1. Scalar2440, flag20000.
 * Require every instruction/internal jump/owned table, strict full TU and
 * complete original hashes. Helper meanings, units, cadence and live parity open.
 */
extern int D_8006C700;
int Call50InterpolateSine(int) __asm__("func_8004E9E4");
int Call50InterpolateCosine(int) __asm__("func_8004EA2C");
extern Spyro Transition50_D_80070328 __asm__("D_80070328");
int Transition50MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition50ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition50_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition50RawUnion[] __asm__("D_80070328+0x144");
extern int Transition50RawMovement __asm__("D_80070328+0x50");
extern void (*Call50Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw50State[] __asm__("D_80070328+0x50");
extern short Signed50TableA[] __asm__("D_800658A0");
extern short Signed50TableB[] __asm__("D_80065920");

extern int D_80071934;
int Call50QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
extern int Raw50NegativeWord __asm__("D_80070328+0x28");
extern int Raw50TableIndex __asm__("D_80070328+0x298");
extern int Raw50Yaw __asm__("D_80070328+0x64");
void Transition50ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Transition50BuildNegatedNormalizedPlayerVector(int) __asm__("func_80043A38");
int Transition50PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void func_level_50_8009D770(int arg0) {
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
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    int shiftedValue;
    switch (arg0) {
        case 0x35:
            Transition50_D_80070328.movementState = 0;
            Transition50_D_80070328.unk5 = 0;
            Transition50ClearPlayerMotionVectors();
            Transition50_D_80070328.grounded = 1;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x15:
            Transition50_D_80070328.movementState = 7;
            Transition50_D_80070328.grounded = 0;
            Transition50_D_80070328.unk5 = 0;
            if (Transition50_D_80070328.unk17a & 0x490) {
                register int first __asm__("$2") = Transition50_D_80070328.unk17e.x;
                register int second __asm__("$3") = Transition50_D_80070328.unk17e.z;
                register int third __asm__("$2");
                MATCHING_KEEP2(first, second);
                first <<= 6;
                Transition50_D_80070328.unk7a[2].x = first;
                MATCHING_BARRIER_VOLATILE("memory");
                third = Transition50_D_80070328.unk17e.y;
                MATCHING_KEEP2(third, second);
                second <<= 6;
                Transition50_D_80070328.unk7a[2].z = second;
                MATCHING_KEEP_VOLATILE_CLOBBER(third, "memory");
                third <<= 6;
                Transition50_D_80070328.unk7a[2].y = third;
            } else {
                shiftedValue = Transition50PlanarHeadingLookup(
                    -Transition50_D_80070328.unk7a[2].x, -Transition50_D_80070328.unk7a[2].y, 1);
                Transition50_D_80070328.unk7b = shiftedValue;
                Transition50_D_80070328.unk7a[2].x =
                    (Call50InterpolateCosine(shiftedValue) << 12) >> 12;
                Transition50_D_80070328.unk7a[2].y =
                    (Call50InterpolateSine(Transition50_D_80070328.unk7b) << 12) >> 12;
                Transition50_D_80070328.unk7a[2].z = 0x1000;
            }
            goto clearPointers;
        case 0x1C:
            savedBase = Transition50RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition50RawMovement;
            Transition50RawMovement = MOVEMENT_STATE_HURT;
            Transition50_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition50_D_80070328.unk8[0] = Transition50MeasureVectorLength(sourceC, 0);
            Transition50_D_80070328.unk7a[2].z = 0xDC0;
            Transition50_D_80070328.grounded = 0;
            Transition50_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition50_D_80070328.damageFlags & 0x200) {
                Transition50_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition50_D_80070328.union144.a.unk13cc = 1;
                soundSelector = D_8006C654->lavaBurn;
                soundZero = 0;
                goto sharedSound;
            }
            goto clearPointers;
        case 0x1E: {
            register int oldState __asm__("$3") = Transition50RawMovement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Transition50RawMovement = value;
            value = 1;
            MATCHING_KEEP(value);
            Transition50_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Transition50_D_8006E524 = value;
            stateWord = (int*)Transition50RawUnion;
            MATCHING_KEEP(stateWord);
            Transition50_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Transition50_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            value = (int)D_8006C654->drown;
            MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
            Transition50_D_80070328.unk20a = 0;
            Transition50_D_80070328.critterMobyPtr = 0;
            Transition50_D_80070328.unk22[3] = value;
            return;
        }
        case 0x3A:
            Transition50_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition50_D_80070328.unk5 = 0;
            Transition50BuildNegatedNormalizedPlayerVector(0xC00);
            Transition50_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition50_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x21:
        case 0x22:
        case 0x23: {
            register unsigned char* flyState __asm__("$16") =
                (unsigned char*)&Transition50RawMovement;
            if (*(int*)flyState != 6) {
                *(int*)flyState = 6;
                Transition50_D_80070328.unk5 = 0;
                Transition50ClearVector((Vector3D*)(flyState + 0x104));
                Transition50_D_80070328.union144.a.unk13db.y = 0;
                lengthResult = Transition50MeasureVectorLength((Vector3D*)(flyState + 0x48), 0);
                Transition50_D_80070328.unk8[0] = lengthResult;
                if (lengthResult < 0x800)
                    Transition50_D_80070328.unk8[0] = 0x800;
                if (Transition50_D_80070328.unk8[0] >= 0x4B01)
                    Transition50_D_80070328.unk8[0] = 0x4B00;
                Transition50_D_80070328.union144.a.unk13cb = 0;
                Transition50_D_80070328.union144.b.unk148 = 0;
                Transition50_D_80070328.union144.a.unk13ce.x = 0;
                Transition50_D_80070328.union144.a.unk13ce.y = 0;
                Transition50_D_80070328.grounded = 0;
                Transition50_D_80070328.unk15b = 0;
            }
            if (arg0 < 0xA0)
                goto clearPointers;
            return;
        }
        case 0x24:
        case 0x25:
        case 0x30: {
            register unsigned char* state __asm__("$16") = Raw50State;
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
                Transition50_D_80070328.union144.a.unk13db.z = 0;
                Transition50_D_80070328.unk5 = 0;
                Transition50ClearVector((Vector3D*)(state + 0xFC));
                Transition50_D_80070328.union144.a.unk13da = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(state, "memory");
                destination = (Vector3D*)(state + 0x48);
            }
            *(int*)state = kind;
            Transition50_D_80070328.unk8[0] = Transition50MeasureVectorLength(destination, 0);
            currentScalar = D_8006C700;
            MATCHING_KEEP(currentScalar);
            scalar = 0x2440;
            MATCHING_KEEP(scalar);
            Transition50_D_80070328.horizontalSpeed = scalar;
            MATCHING_KEEP_VOLATILE_CLOBBER(currentScalar, "memory");
            if (currentScalar < 0x2440)
                D_8006C700 = scalar;
            Transition50BuildNegatedNormalizedPlayerVector(0xC00);
            savedRoll = Transition50_D_80070328.rotation.roll;
            MATCHING_KEEP(savedRoll);
            Transition50_D_80070328.grounded = 1;
            Transition50_D_80070328.unk15c = 0;
            Transition50_D_80070328.union144.a.unk13cc = 0;
            Transition50_D_80070328.union144.a.unk13db.x = 0;
            Transition50_D_80070328.union144.a.unk13db.y = 0;
            Transition50_D_80070328.unk13a[0] = 0x20000;
            Transition50_D_80070328.union144.a.unk13cb = savedRoll;
            return;
        }
        case 0x28:
        case 0x29:
            if (((unsigned)(Transition50_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition50_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition50_D_80070328.movementState - 0x50));
                    if ((Transition50_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw50NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition50_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call50QueryWorldHeight(&vectors.first, 0x800);
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
                firstWrappedWord = Transition50_D_80070328.rotation.pitch & 0xFFF;
                Transition50_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition50_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition50_D_80070328.rotation.pitch > 0) {
                    Transition50_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition50_D_80070328.unk5 = 1;
                }
                Transition50ClearVector(
                    (Vector3D*)((unsigned char*)&Transition50_D_80070328.rotation.pitch + 0xEC));
                Transition50_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition50_D_80070328.unk8[0] = Transition50MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition50_D_80070328.rotation.pitch + 0x38), 0);
                Transition50_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition50_D_80070328.animationState == 0x2A) {
                Transition50_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition50_D_80070328.union144.a.unk13da = 0;
            }
            Transition50_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition50_D_80070328.unk20a = 0;
            Transition50_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw50State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw50NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition50_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call50QueryWorldHeight(localVector, 0x800);
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
                if (Transition50_D_80070328.animationState == 0x2E) {
                    Transition50_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition50_D_80070328.rotation.pitch & 0xFFF;
                Transition50_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition50_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition50_D_80070328.rotation.pitch > 0) {
                    Transition50_D_80070328.rotation.pitch = 0;
                }
                Transition50_D_80070328.unk5 = 1;
                Transition50ClearVector(
                    (Vector3D*)((unsigned char*)&Transition50_D_80070328.animationState + 0x104));
                Transition50_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition50_D_80070328.unk8[0] = Transition50MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition50_D_80070328.animationState + 0x50), 0);
                Transition50_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition50_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition50_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition50RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition50RawUnion;
                    *(int*)unionPointer = (-Transition50_D_80070328.unk7a[2].z) >> 2;
                    if (Transition50RawMovement != 8) {
                        Transition50_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition50RawMovement = 10;
                    }
                    Transition50_D_80070328.unk5 = 0;
                    Transition50_D_80070328.unk8[0] =
                        Transition50MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition50_D_80070328.grounded = 1;
                    Transition50_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call50QueryWorldHeight(localVector, 0x800);
                    vectors.third.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, localVector, 0);
                        SpawnParticle(6, 0x2E, localVector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        case 0x36:
            Transition50_D_80070328.movementState = 0;
            Transition50_D_80070328.unk5 = 0;
            Transition50ClearPlayerMotionVectors();
            Transition50_D_80070328.grounded = 1;
            goto clearPointers;
        case 0x39: {
            register int previousMovement __asm__("$2") = Transition50RawMovement;
            register int numericKind __asm__("$3");
            register int indexWord __asm__("$3");
            register unsigned char* unionPointer __asm__("$5");
            register int tableOffset __asm__("$2");
            register int tableWord __asm__("$3");
            MATCHING_KEEP(previousMovement);
            numericKind = 7;
            MATCHING_KEEP(numericKind);
            Transition50RawMovement = numericKind;
            MATCHING_BARRIER_VOLATILE("memory");
            indexWord = Raw50TableIndex;
            MATCHING_KEEP_VOLATILE_CLOBBER(indexWord, "memory");
            unionPointer = Transition50RawUnion;
            MATCHING_KEEP2_CLOBBER(indexWord, unionPointer, "memory");
            Transition50_D_80070328.unk5 = 0;
            *(int*)unionPointer = previousMovement;
            if (indexWord < 0)
                Raw50TableIndex = ((Raw50Yaw + 0x800) >> 4) & 0xFF;
            tableOffset = Raw50TableIndex * 2;
            tableWord = *(short*)((unsigned char*)Signed50TableB + tableOffset);
            destination = (Vector3D*)(unionPointer - 0xC4);
            *(int*)(unionPointer - 0xB8) = tableWord;
            tableOffset = *(short*)((unsigned char*)Signed50TableA + tableOffset);
            Transition50_D_80070328.unk7a[2].z = 0;
            Transition50_D_80070328.unk7a[2].y = tableOffset;
            func_8004F178(destination, (Vector3D*)(unionPointer - 0xB8));
            Transition50_D_80070328.grounded = 1;
            Transition50_D_8006E524 = 15;
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
            Transition50_D_80070328.unk20a = 0;
            Transition50_D_80070328.critterMobyPtr = 0;
            return;
        case 0x1B:
        case 0x3C: {
            register unsigned char* critterWord __asm__("$16") =
                (unsigned char*)&Transition50_D_80070328.critterMobyPtr;
            register int classWord __asm__("$3");
            register unsigned char* movement __asm__("$3");
            if (*(Moby**)critterWord &&
                ((classWord = Transition50_D_80070328.critterMobyPtr->mobyClass) == 0x2F5 ||
                 classWord == 0xF0)) {
                if (Transition50RawMovement != 6) {
                    Transition50RawMovement = 6;
                    Transition50_D_80070328.unk5 = 0;
                    Transition50ClearVector((Vector3D*)(critterWord - 0xFC));
                    Transition50_D_80070328.union144.a.unk13db.y = 0;
                    lengthResult =
                        Transition50MeasureVectorLength((Vector3D*)(critterWord - 0x1B8), 0);
                    Transition50_D_80070328.unk8[0] = lengthResult;
                    if (lengthResult < 0x800)
                        Transition50_D_80070328.unk8[0] = 0x800;
                    if (Transition50_D_80070328.unk8[0] >= 0x4B01)
                        Transition50_D_80070328.unk8[0] = 0x4B00;
                    Transition50_D_80070328.union144.a.unk13cb = 0;
                    Transition50_D_80070328.union144.b.unk148 = 0;
                    Transition50_D_80070328.union144.a.unk13ce.x = 0;
                    Transition50_D_80070328.union144.a.unk13ce.y = 0;
                    Transition50_D_80070328.grounded = 0;
                    Transition50_D_80070328.unk15b = 0;
                }
            } else {
                movement = Raw50State;
                *(int*)movement = 18;
                Transition50_D_80070328.unk5 = 0;
                Transition50_D_80070328.unk8[0] =
                    Transition50MeasureVectorLength((Vector3D*)(movement + 0x48), 0);
                Transition50_D_80070328.grounded = 1;
                Transition50BuildNegatedNormalizedPlayerVector(0xC00);
                Transition50_D_80070328.unk4a = 0x300;
            }
            return;
        }
        case 0x96:
        case 0x97: {
            register unsigned char* animation __asm__("$16") =
                (unsigned char*)&Transition50_D_80070328.animationState;
            if (*(int*)animation < 0x96) {
                Transition50ClearVector((Vector3D*)(animation + 0x104));
                Transition50_D_80070328.union144.a.unk13cb = 0;
                Transition50_D_80070328.unk8[0] =
                    Transition50MeasureVectorLength((Vector3D*)(animation + 0x50), 0);
                Transition50_D_80070328.grounded = 1;
                Transition50_D_80070328.union144.a.unk13da = 0;
                Transition50_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
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
/* SCUS-94467 USA Rev0, original8009E40C.
 * Assembly SHA256 1ae65f3a59403a55d49e13aeef7b42d4ac15779052fd5f199b32b199b18b3fda.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1395 original instructions and131 state-table entries (bias21).
 * Original27/33/34/35/58/96/97 branches, shared selector calls, indirect callback,
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
extern int Anim50Player48View1 __asm__("D_80070328 + 0x48");
extern unsigned char* Anim50Player250View1 __asm__("D_80070328 + 0x250");
extern int Anim50Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim50Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim50PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim50PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim50PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim50PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim50PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim50PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim50PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim50Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim50Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim50Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim50PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim50Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim50Player158View1 __asm__("D_80070328 + 0x158");
extern int Anim50Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim50Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim50Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern int Anim50Data6E538View1 __asm__("D_8006E538"), Anim50Data6E53CView1 __asm__("D_8006E53C");
extern int (*Anim50Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim50Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim50Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim50Data6FA38View1 __asm__("D_8006FA38");
int Anim50SoundHandleMatchesIdInStates1Or2View1() __asm__("func_8003BF6C");
int Anim50TransitionSoundHandleTo3Or5View1() __asm__("func_8003BE70");
int Anim50ProcessPlayerStateFlagsView1() __asm__("func_80040994");
int Anim50DispatchPlayerStateRequestView1() __asm__("func_8004BEF8");
int Anim50UpdatePlayerRetryStateView1() __asm__("func_800498C0");
extern int Anim50Player10CView1 __asm__("D_80070328 + 0x10C");
int Anim50GetSurfaceTypeFromFlagsView1() __asm__("func_80040954");
extern int Anim50PlayerBCView1 __asm__("D_80070328 + 0xBC");
extern int Anim50Player160View1 __asm__("D_80070328 + 0x160");
extern int Anim50Player15CView1 __asm__("D_80070328 + 0x15C");
extern int Anim50Player88View1 __asm__("D_80070328 + 0x88");
extern int Anim50Player84View1 __asm__("D_80070328 + 0x84");
extern int Anim50Player68View1 __asm__("D_80070328 + 0x68");
extern int Anim50Player6CView1 __asm__("D_80070328 + 0x6C");
int Anim50PlayMobySoundEventView1() __asm__("func_8003BABC");
int Anim50SubtractVectorView1() __asm__("func_8004F1C8");
int Anim50MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Anim50PlayMobySoundEventView2() __asm__("func_8003BABC");
int Anim50TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Anim50NormalizeVectorToLengthView1() __asm__("func_8004EF04");
int Anim50BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Anim50CopyVectorView1() __asm__("func_8004F178");
int Anim50ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Anim50AddVectorView1() __asm__("func_8004F194");
int Anim50UpdatePlayerTiltFromVectorView1() __asm__("func_80043E00");
int Anim50ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Anim50SubtractVectorView2() __asm__("func_8004F1C8");
int Anim50MeasureVectorLengthView2() __asm__("func_8004EDE8");
extern int Anim50Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim50Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim50PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim50Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim50Player280View2 __asm__("D_80070328 + 0x280");
extern int Anim50Data6E538View2 __asm__("D_8006E538"), Anim50Data6E53CView2 __asm__("D_8006E53C");
extern int Anim50Data6E044View1 __asm__("D_8006E044"), A21Gate __asm__("D_8006E344"),
    A21Count __asm__("D_8006C514");
extern int (*Anim50Data74374View2)() __asm__("unk_ovlheader_80074374");
int Anim50ProcessPlayerStateFlagsView2() __asm__("func_80040994");
int Anim50DispatchPlayerStateRequestView2() __asm__("func_8004BEF8");
extern volatile int Anim50Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim50Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim50Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim50Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim50Data6EE2CView1 __asm__("D_8006EE2C");
int Anim50ProcessPlayerContactFlagsView1() __asm__("func_80040BCC");
int Anim50QueryWorldHeightWithOptionsView1() __asm__("func_8001A310");
extern int Anim50Player4CView3 __asm__("D_80070328 + 0x4C");
extern int Anim50PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim50PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim50PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim50PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int A35Buttons __asm__("D_8006E538"), Anim50Data6E53CView3 __asm__("D_8006E53C");
int Anim50ProcessPlayerStateFlagsView3() __asm__("func_80040994");
int Anim50DispatchPlayerStateRequestView3() __asm__("func_8004BEF8");
extern int Anim50PlayerBCView2 __asm__("D_80070328 + 0xBC"),
    Anim50Player1BCView1 __asm__("D_80070328 + 0x1BC"),
    Anim50Player60View1 __asm__("D_80070328 + 0x60");
extern short Anim50Player148View1 __asm__("D_80070328 + 0x148");
int Anim50TestPlayerProbePatternView1() __asm__("func_80043194");
int Anim50MeasureVectorLengthView3() __asm__("func_8004EDE8");
extern int (*Anim50Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
void func_level_50_8009E40C(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* object4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");
    struct {
        int at10[4], at20[4], at30[4], at40[4], at50[4], at60[4], at70[4], at80[4];
    } frame;
    register int* savedPointer16 __asm__("$16");
    register int* saved16 __asm__("$16");
    register int* saved17 __asm__("$17");
    register int* saved18 __asm__("$18");
    register int* saved19 __asm__("$19");
    register int* state4 __asm__("$4");
    register int call6 __asm__("$6");
    register int* savedPointer17 __asm__("$17");
    rawValue2 = Anim50Player48View1;
    switch (rawValue2) {
        case 53:
        case 54:
            if (Anim50ProcessPlayerStateFlagsView1())
                return;
            nextSelector4 = 0;
            goto select;
        case 21:
            if (Anim50Player54View1 < 33)
                return;
            if (!Anim50PlayerB8View1) {
                Anim50DispatchPlayerStateRequestView1(4);
                Anim50Player4CView1 = 1;
                return;
            }
            rawValue2 = Anim50PlayerBCView1;
            nextSelector4 = 7;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009E4C8) : "memory");
            goto select;
        case 27:
            if (Anim50Player54View1 < 25)
                return;
            rawValue2 = Anim50Player280View1;
            nextSelector4 = 60;
            if (rawValue2 >= 0)
                goto select;
            __asm__ volatile("" ::"i"(0x8009E4FC) : "memory");
            nextSelector4 = 31;
            goto select;
        case 28:
            if (Anim50Player1B5View1 && (Anim50Data6E53CView1 & 64))
                Anim50Player1B6View1 = 1;
            if (!Anim50PlayerB8View1 && Anim50Player54View1 >= 16 && Anim50PlayerE4View1 < 23) {
                rawValue3 = Anim50PlayerCCView1;
                rawValue2 = Anim50Player8CView1;
                product5 = rawValue3 * rawValue2;
                rawValue3 = Anim50PlayerD0View1;
                rawValue2 = Anim50Player90View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = Anim50PlayerD4View1;
                rawValue2 = Anim50Player94View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                if (rawValue2 < 0) {
                    if (Anim50PlayerACView1) {
                        rawValue3 = Anim50PlayerB0View1;
                        if (rawValue3 >= 3841) {
                            __asm__ volatile("" ::"i"(0x8009E60C) : "memory");
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
                    rawValue2 = Anim50PlayerB0View1 < 1920;
                    nextSelector4 = 0;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 4;
                    goto select;
                }
            }
            rawValue2 = Anim50Data6E538View1 & 128;
            if (rawValue2 && Anim50Player4CView1 == 1) {
                nextSelector4 = 22;
                goto select;
            }
            if (Anim50Player1B5View1 && Anim50Player1B6View1) {
                rawValue3 = Anim50Player4CView1;
                rawValue2 = 1;
                nextSelector4 = 17;
                if (rawValue3 != rawValue2)
                    return;
                goto select;
            }
            rawValue3 = Anim50Player4CView1;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim50PlayerA0View1 < -6400;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            if (Anim50Player54View1 >= 91)
                goto select;
            return;
        case 30: {
            register int* timer4 __asm__("$4");
            register int (*callback3)() __asm__("$3");
            if (Anim50Data6E53CView1 & 64)
                Anim50Player1B6View1 = 1;
            if (Anim50Data6FA38View1 >= 0) {
                if (Anim50Player144View1 <= 0x8FFF)
                    return;
                callback3 = Anim50Data74374View1;
                Anim50Player28CView1 = -1;
                if (callback3) {
                    callback3();
                    return;
                }
                goto call498C0;
            }
            timer4 = &Anim50Player280View1;
            MATCHING_KEEP(timer4);
            if (*timer4 < 0) {
                if (Anim50Player144View1 <= 0x8FFF)
                    return;
                Anim50Player28CView1 = -1;
            call498C0:
                Anim50UpdatePlayerRetryStateView1();
                MATCHING_BARRIER_VOLATILE("memory");
                return;
            }
            rawValue3 = Anim50Player54View1;
            if (rawValue3 >= 61) {
                *timer4 = -1;
                return;
            }
            rawValue2 = rawValue3 < 16;
            MATCHING_KEEP(rawValue2);
            if (rawValue2)
                return;
            if (!Anim50Player1B6View1)
                return;
            if (Anim50Player28CView1 >= 0) {
                if (Anim50SoundHandleMatchesIdInStates1Or2View1(Anim50Player290View1,
                                                                Anim50Player28CView1))
                    Anim50TransitionSoundHandleTo3Or5View1(Anim50Player28CView1);
                Anim50Player28CView1 = -1;
            }
            nextSelector4 = 6;
            goto select;
        }
        case 33:
            if (Anim50ProcessPlayerStateFlagsView3())
                return;
            savedPointer17 = &Anim50PlayerB8View2;
            MATCHING_KEEP(savedPointer17);
            if (!*savedPointer17) {
                if (Anim50PlayerE4View2 >= 23)
                    Anim50DispatchPlayerStateRequestView3(7);
                if (Anim50PlayerACView2 > 0) {
                    rawValue3 = Anim50PlayerB0View3;
                    rawValue2 = rawValue3 < 3841;
                    if (!rawValue2) {
                        MATCHING_BARRIER_VOLATILE("memory");
                        __asm__ volatile("" ::"i"(0x8009E8C0) : "memory");
                        nextSelector4 = 3;
                        goto select;
                    }
                    rawValue2 = rawValue3 < 1921;
                    MATCHING_KEEP(rawValue2);
                    nextSelector4 = 1;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 2;
                    goto select;
                }
                rawValue2 = Anim50PlayerB0View3 < 1920;
                nextSelector4 = 0;
                if (rawValue2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 4;
                goto select;
            }
            savedPointer16 = &Anim50Data6E53CView3;
            MATCHING_KEEP(savedPointer16);
            rawValue2 = *savedPointer16 & 128;
            nextSelector4 = 22;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50TestPlayerProbePatternView1(4);
            nextSelector4 = 47;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50PlayerBCView2;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim50Player1BCView1;
            nextSelector4 = 17;
            if (!rawValue2)
                goto select;
            rawValue2 = *savedPointer16 & 16;
            nextSelector4 = 18;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)savedPointer17 - 32;
            rawValue2 = Anim50MeasureVectorLengthView3((void*)nextSelector4, 1);
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50Player148View1 < 2;
            nextSelector4 = 35;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim50Player4CView3;
            nextSelector4 = 34;
            if (rawValue2)
                goto select;
            rawValue3 = Anim50Player60View1;
            rawValue2 = rawValue3 < 365;
            if (!rawValue2)
                goto select;
            rawValue2 = rawValue3 < -364;
            nextSelector4 = 35;
            if (!rawValue2)
                return;
            goto select;
        case 34:
            if (Anim50ProcessPlayerStateFlagsView3())
                return;
            savedPointer17 = &Anim50PlayerB8View2;
            MATCHING_KEEP(savedPointer17);
            if (!*savedPointer17) {
                if (Anim50PlayerE4View2 >= 23)
                    Anim50DispatchPlayerStateRequestView3(7);
                if (Anim50PlayerACView2 > 0) {
                    rawValue3 = Anim50PlayerB0View3;
                    rawValue2 = rawValue3 < 3841;
                    if (!rawValue2) {
                        MATCHING_BARRIER_VOLATILE("memory");
                        __asm__ volatile("" ::"i"(0x8009EA40) : "memory");
                        nextSelector4 = 3;
                        goto select;
                    }
                    rawValue2 = rawValue3 < 1921;
                    MATCHING_KEEP(rawValue2);
                    nextSelector4 = 1;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 2;
                    goto select;
                }
                rawValue2 = Anim50PlayerB0View3 < 1920;
                nextSelector4 = 0;
                if (rawValue2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 4;
                goto select;
            }
            savedPointer16 = &Anim50Data6E53CView3;
            MATCHING_KEEP(savedPointer16);
            rawValue2 = *savedPointer16 & 128;
            nextSelector4 = 22;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50TestPlayerProbePatternView1(4);
            nextSelector4 = 47;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50PlayerBCView2;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim50Player1BCView1;
            nextSelector4 = 17;
            if (!rawValue2)
                goto select;
            rawValue2 = *savedPointer16 & 16;
            nextSelector4 = 18;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)savedPointer17 - 32;
            rawValue2 = Anim50MeasureVectorLengthView3((void*)nextSelector4, 1);
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50Player148View1 < 2;
            nextSelector4 = 35;
            if (!rawValue2)
                goto select;
            if (Anim50Player60View1 >= 256)
                return;
            rawValue2 = Anim50Player4CView3;
            nextSelector4 = 33;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009EB3C) : "memory");
            goto select;
        case 35:
            if (Anim50ProcessPlayerStateFlagsView3())
                return;
            savedPointer17 = &Anim50PlayerB8View2;
            MATCHING_KEEP(savedPointer17);
            if (!*savedPointer17) {
                if (Anim50PlayerE4View2 >= 23)
                    Anim50DispatchPlayerStateRequestView3(7);
                if (Anim50PlayerACView2 > 0) {
                    rawValue3 = Anim50PlayerB0View3;
                    rawValue2 = rawValue3 < 3841;
                    if (!rawValue2) {
                        __asm__ volatile("" ::"i"(0x8009EBB8) : "memory");
                        nextSelector4 = 3;
                        goto select;
                    }
                    rawValue2 = rawValue3 < 1921;
                    MATCHING_KEEP(rawValue2);
                    nextSelector4 = 1;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 2;
                    goto select;
                }
                rawValue2 = Anim50PlayerB0View3 < 1920;
                nextSelector4 = 0;
                if (rawValue2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 4;
                goto select;
            }
            savedPointer16 = &Anim50Data6E53CView3;
            MATCHING_KEEP(savedPointer16);
            rawValue2 = *savedPointer16 & 128;
            nextSelector4 = 22;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50TestPlayerProbePatternView1(4);
            nextSelector4 = 47;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50PlayerBCView2;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim50Player1BCView1;
            nextSelector4 = 17;
            if (!rawValue2)
                goto select;
            rawValue2 = *savedPointer16 & 16;
            nextSelector4 = 18;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)savedPointer17 - 32;
            rawValue2 = Anim50MeasureVectorLengthView3((void*)nextSelector4, 1);
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            if (Anim50Player148View1 >= 2)
                return;
            rawValue2 = Anim50Player4CView3;
            nextSelector4 = 34;
            if (rawValue2)
                goto select;
            rawValue2 = Anim50Player60View1 < -255;
            nextSelector4 = 33;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009ECB4) : "memory");
            goto select;
        case 36:
            if (Anim50ProcessPlayerStateFlagsView1())
                return;
            saved16 = &Anim50Player4CView1;
            rawValue2 = *saved16;
            if ((unsigned)(rawValue2 - 1) < 2 && !Anim50PlayerB8View1) {
                if (Anim50PlayerE4View1 >= 60)
                    goto expired36;
                frame.at10[0] = 0;
                frame.at10[1] = 0;
                frame.at10[2] = 4096;
                Anim50TransformVectorByBasisView1(saved16 - 7, frame.at10, frame.at10);
                Anim50NormalizeVectorToLengthView1(saved16 + 32, 4096);
                rawValue3 = frame.at10[0];
                rawValue2 = saved16[32];
                product5 = rawValue3 * rawValue2;
                rawValue3 = frame.at10[1];
                rawValue2 = Anim50PlayerD0View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = frame.at10[2];
                rawValue2 = Anim50PlayerD4View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                rawValue2 >>= 12;
                nextSelector4 = 21;
                if (rawValue2 < 1536)
                    goto select;
                product5 = 2;
                object4 = Anim50Player250View1;
                MATCHING_KEEP(object4);
                call6 = 0;
                MATCHING_KEEP3(object4, product5, call6);
                *saved16 = 0;
                Anim50PlayMobySoundEventView1(object4, product5, call6);
                return;
            expired36:
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 21;
                goto select;
            }
            state4 = &Anim50Player4CView1;
            rawValue3 = *state4;
            rawValue2 = 3;
            if (rawValue3 == rawValue2) {
                if (Anim50Data6E538View1 & 64)
                    Anim50Player1B6View1 = 1;
                rawValue2 = Anim50GetSurfaceTypeFromFlagsView1(Anim50Player10CView1);
                rawValue3 = 9;
                if (rawValue2 != rawValue3) {
                    if (Anim50PlayerA0View1 > 0 && Anim50Player160View1 >= 4)
                        Anim50PlayerB8View1 = 1;
                    else
                        Anim50Player4CView1 = 0;
                }
                saved17 = &Anim50PlayerB8View1;
                MATCHING_KEEP(saved17);
                rawValue2 = *saved17;
                if (!rawValue2)
                    goto remainder36;
                if (Anim50Player158View1 <= 2048)
                    goto reset36;
                Anim50BuildPlayerMovementVectorView1();
                rawValue3 = Anim50Player15CView1;
                rawValue2 = 2;
                if (rawValue3 == rawValue2) {
                    nextSelector4 = 48;
                    if (Anim50Player1B6View1) {
                        rawValue2 = Anim50Player88View1;
                        rawValue2 += 3840;
                        Anim50Player88View1 = rawValue2;
                        rawValue2 = 4;
                        goto set36;
                    }
                    rawValue2 = 4;
                    goto set36;
                }
                if (Anim50Player1B6View1 || rawValue3 == 1) {
                    Anim50CopyVectorView1(frame.at10, saved17 + 37);
                    frame.at10[2] = 0;
                    Anim50NormalizeVectorToLengthView1(frame.at10, 4096);
                    rawValue3 = frame.at10[0];
                    rawValue2 = saved17[-14];
                    call6 = rawValue3 * rawValue2;
                    rawValue3 = frame.at10[1];
                    rawValue2 = Anim50Player84View1;
                    rawValue3 *= rawValue2;
                    call6 += rawValue3;
                    call6 >>= 12;
                    call6 = -call6;
                    Anim50ScaleVectorRatioQ15View1(frame.at10, 4096, call6);
                    saved16 = saved17 - 14;
                    Anim50Player88View1 += 2048;
                    Anim50AddVectorView1(saved16, saved16, frame.at10);
                    Anim50UpdatePlayerTiltFromVectorView1(saved16);
                    Anim50ShiftVectorRightTowardZeroView1(frame.at10, 4);
                    Anim50AddVectorView1(saved17 - 46, saved17 - 46, frame.at10);
                    nextSelector4 = 37;
                    Anim50Player68View1 = 0;
                    Anim50Player6CView1 = 0;
                    rawValue2 = 5;
                    goto set36;
                }
                nextSelector4 = 48;
                rawValue2 = 4;
            set36:
                Anim50Player4CView1 = rawValue2;
                Anim50DispatchPlayerStateRequestView1(nextSelector4);
                Anim50PlayMobySoundEventView2(Anim50Player250View1, 1, 0);
                saved16 = &Anim50Player8CView1;
                nextSelector4 = (int)saved16;
                MATCHING_KEEP(nextSelector4);
                saved17 = saved16 - 3;
                Anim50CopyVectorView1((void*)nextSelector4, saved17);
                Anim50CopyVectorView1(saved16 + 3, saved17);
                return;
            reset36:
                Anim50Player4CView1 = 0;
                goto remainder36;
            }
            if (rawValue3)
                goto remainder36;
            if (Anim50PlayerB8View1 < 5 && (Anim50Data6E53CView1 & 64)) {
                rawValue2 = 1;
                rawValue3 = Anim50PlayerA0View1;
                *state4 = rawValue2;
                Anim50Player54View1 = 0;
                rawValue3 += 3520;
                Anim50Player94View1 = rawValue3;
                return;
            }
            rawValue2 = Anim50PlayerB8View1;
            if (rawValue2) {
                rawValue2 = rawValue2 < 5;
                goto count36;
            }
            rawValue2 = Anim50PlayerE4View1;
            rawValue2 = rawValue2 < 48;
            nextSelector4 = 21;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim50PlayerB8View1;
            rawValue2 = rawValue2 < 5;
        count36:
            if (!rawValue2) {
                rawValue2 = 1;
                Anim50Player4CView1 = rawValue2;
                Anim50Player54View1 = 0;
            }
        remainder36:
            saved18 = frame.at20;
            nextSelector4 = (int)saved18;
            MATCHING_KEEP(nextSelector4);
            saved16 = &Anim50Player8CView1;
            product5 = (int)saved16;
            MATCHING_KEEP(product5);
            saved17 = saved16 + 3;
            Anim50SubtractVectorView1((void*)nextSelector4, (void*)product5, saved17);
            saved19 = frame.at30;
            Anim50SubtractVectorView1(saved19, saved16 - 3, saved17);
            rawValue2 = Anim50MeasureVectorLengthView1(saved18, 1);
            rawValue3 = Anim50PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            if (rawValue2 < 218)
                return;
            rawValue2 = Anim50MeasureVectorLengthView1(saved19, 1);
            rawValue3 = Anim50PlayerACView1;
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
            if (Anim50ProcessPlayerStateFlagsView1())
                return;
            saved16 = &Anim50PlayerB8View1;
            if (!*saved16 && Anim50PlayerE4View1 < 60) {
                frame.at40[0] = 0;
                frame.at40[1] = 0;
                frame.at40[2] = 4096;
                Anim50TransformVectorByBasisView1(saved16 - 34, frame.at40, frame.at40);
                Anim50NormalizeVectorToLengthView1(saved16 + 5, 4096);
                rawValue3 = frame.at40[0];
                rawValue2 = saved16[5];
                product5 = rawValue3 * rawValue2;
                rawValue3 = frame.at40[1];
                rawValue2 = Anim50PlayerD0View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = frame.at40[2];
                rawValue2 = Anim50PlayerD4View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                rawValue2 >>= 12;
                nextSelector4 = 21;
                if (rawValue2 < 1536)
                    goto select;
                Anim50Player4CView1 = 0;
                Anim50DispatchPlayerStateRequestView1(36);
                object4 = Anim50Player250View1;
                product5 = 2;
                goto partialBABC;
            }
            saved18 = frame.at50;
            nextSelector4 = (int)saved18;
            MATCHING_KEEP(nextSelector4);
            saved16 = &Anim50Player8CView1;
            product5 = (int)saved16;
            MATCHING_KEEP(product5);
            saved17 = saved16 + 3;
            Anim50SubtractVectorView2((void*)nextSelector4, (void*)product5, saved17);
            saved19 = frame.at60;
            Anim50SubtractVectorView2(saved19, saved16 - 3, saved17);
            rawValue2 = Anim50MeasureVectorLengthView2(saved18, 1);
            rawValue3 = Anim50PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            if (rawValue2 < 218)
                return;
            rawValue2 = Anim50MeasureVectorLengthView2(saved19, 1);
            rawValue3 = Anim50PlayerACView1;
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
            if (Anim50ProcessPlayerStateFlagsView1())
                return;
            saved17 = &Anim50PlayerB8View1;
            if (*saved17)
                return;
            if (Anim50PlayerE4View1 >= 60)
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
            Anim50TransformVectorByBasisView1((void*)nextSelector4, (void*)product5, (void*)call6);
            Anim50NormalizeVectorToLengthView1(saved17 + 5, 4096);
            rawValue3 = frame.at70[0];
            rawValue2 = saved17[5];
            product5 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[1];
            rawValue2 = Anim50PlayerD0View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[2];
            rawValue2 = Anim50PlayerD4View1;
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
            Anim50TransformVectorByBasisView1(saved19, saved16, saved16);
            saved16 = frame.at80;
            Anim50CopyVectorView1(saved16, saved17 - 8);
            Anim50NormalizeVectorToLengthView1(saved16, 4096);
            rawValue3 = frame.at70[0];
            rawValue2 = frame.at80[0];
            product5 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[1];
            rawValue2 = frame.at80[1];
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[2];
            rawValue2 = frame.at80[2];
            rawValue3 *= rawValue2;
            Anim50Player4CView1 = 0;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            rawValue2 >>= 12;
            nextSelector4 = 21;
            if (rawValue2 < 2560)
                goto select;
            Anim50DispatchPlayerStateRequestView1(36);
            object4 = Anim50Player250View1;
            product5 = 2;
        partialBABC:
            Anim50PlayMobySoundEventView2(object4, product5, 0);
            return;
        case 40:
            if (Anim50ProcessPlayerStateFlagsView2())
                return;
            if ((Anim50Data6E538View2 & 128) && Anim50Player4CView2 != 1) {
                nextSelector4 = 42;
                goto select;
            }
            if (Anim50PlayerB0View2)
                return;
            rawValue2 = Anim50Player20CView1 & 64;
            nextSelector4 = 41;
            if (!rawValue2)
                goto select;
            if (Anim50Player214View1 <= 0)
                return;
            goto select;
        case 41:
            if (Anim50ProcessPlayerStateFlagsView2())
                return;
            nextSelector4 = Anim50Data6E538View2;
            rawValue2 = nextSelector4 & 128;
            if (rawValue2) {
                nextSelector4 = 42;
                goto select;
            }
            rawValue2 = 7;
            rawValue3 = Anim50Data6E044View1;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = nextSelector4 & 64;
            nextSelector4 = 40;
            if (rawValue2)
                goto select;
            if (!(Anim50Player20CView1 & 64))
                return;
            if (!Anim50Player214View1)
                goto select;
            return;
        case 42:
            if (Anim50ProcessPlayerContactFlagsView1())
                return;
            if ((Anim50Data6E538View2 & 128) || Anim50Player4CView2 == 1)
                goto flag64;
            rawValue2 = Anim50Player20CView1 & 128;
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        flag64:
            rawValue2 = Anim50Player20CView1 & 64;
            nextSelector4 = 40;
            if (!rawValue2)
                return;
            goto select;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (Anim50ProcessPlayerStateFlagsView2())
                return;
            if ((Anim50Data6E53CView2 & 64) && Anim50Player54View2 >= 9) {
                nextSelector4 = 6;
                goto partialCall;
            }
            byte4 = &Anim50Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto partialCall;
            }
            if (!(Anim50Data6E53CView2 & 128))
                goto check44;
            if (Anim50Player54View2 < 9)
                goto check44;
            rawValue2 = *(int*)(Anim50Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto check44;
            rawValue2 = Anim50QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (rawValue2)
                goto check44;
            goto select;
        partialCall:
            Anim50DispatchPlayerStateRequestView2(nextSelector4);
        check44:
            rawValue2 = Anim50Data6E535View1;
            nextSelector4 = 44;
            if (!rawValue2)
                return;
            goto select;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3 = Anim50Player4CView2;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                goto other44;
            if (Anim50Data6E53CView2 & 0x850)
                goto callback44;
            if (Anim50Player54View2 < 61)
                return;
        callback44:
            callback2 = Anim50Data74374View2;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto call498C0;
        other44:
            if (Anim50ProcessPlayerStateFlagsView2())
                return;
            if ((Anim50Data6E53CView2 & 64) && Anim50Player54View2 >= 9) {
                nextSelector4 = 6;
                goto select;
            }
            byte4 = &Anim50Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto select;
            }
            if (!(Anim50Data6E53CView2 & 128))
                goto mode44;
            if (Anim50Player54View2 < 9)
                goto mode44;
            rawValue2 = *(int*)(Anim50Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto mode44;
            rawValue2 = Anim50QueryWorldHeightWithOptionsView1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        mode44:
            rawValue3 = Anim50Data6E044View1;
            rawValue2 = 7;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = Anim50Data6E535View1;
            nextSelector4 = 43;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009F8BC) : "memory");
            goto select;
        }
        case 57:
            if (Anim50Player54View2 < 25)
                return;
            if (Anim50Player280View2 < 0) {
                nextSelector4 = 31;
                goto select;
            }
            rawValue2 = 10;
            rawValue3 = Anim50Player144View2;
            nextSelector4 = 41;
            if (rawValue3 != rawValue2)
                goto select;
            nextSelector4 = 44;
            goto select;
        case 58:
            rawValue2 = Anim50Player54View1 < 137;
            if (!rawValue2)
                goto call498C0;
            return;
        case 60: {
            register int (*callback2)(int) __asm__("$2");
        callback:
            callback2 = Anim50Data7431CView1;
            callback2(1);
            return;
        }
        case 150: {
            register int (*callback2)(int) __asm__("$2") = Anim50Data7431CView1;
            callback2(1);
            rawValue2 = Anim50Data6E538View1 & 0xC0;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 151;
            if (rawValue2 == 0)
                return;
            goto select;
        }
        case 151: {
            register int (*callback2)(int) __asm__("$2") = Anim50Data7431CView1;
            callback2(1);
            rawValue2 = Anim50Data6E538View1 & 0xC0;
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
    Anim50DispatchPlayerStateRequestView1(nextSelector4);
    return;
}
