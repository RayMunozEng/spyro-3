#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80088AD4.
 * Assembly SHA256 71fc8c237777303142e6ab6feb5bc56ef91a5de1a64bee28f87d216ae67c815b.
 * AI-generated; not human reviewed. All1106 original instructions,
 * 39 selectors bias20 and 1 owned padding words are required.
 * Original frame0xC8; every concrete field width and producer is retained.
 * Seven exact groups reuse verified11/12/32; near29 retains its independent
 * scalar clamp, and last43 falls directly into the epilogue. Original frame
 * scratch10..AC,savedS0..S4,slotS2,combinedS3 and28 S2 vector are retained.
 * All original water,scalar,vector,particle and control producers remain.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics37Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics37Call363DCView1() __asm__("func_800363DC");
unsigned char Physics37Call40D10View1() __asm__("func_80040D10");
unsigned char Physics37Call41580View1() __asm__("func_80041580");
unsigned char Physics37Call416F4View1() __asm__("func_800416F4");
unsigned char Physics37Call417FCView1() __asm__("func_800417FC");
unsigned char Physics37Call41B64View1() __asm__("func_80041B64");
int Physics37InterpolateSineView1() __asm__("func_8004E9E4");
int Physics37InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics37TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics37MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics37ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics37ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics37CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics37AddVectorView1() __asm__("func_8004F194");
unsigned char Physics37SubtractVectorView1() __asm__("func_8004F1C8");
int Physics37CallRandView1() __asm__("rand");
extern unsigned char Physics37Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics37Data65920View1 __asm__("D_80065920");
extern void* Physics37Data6C570View1 __asm__("D_8006C570");
extern int Physics37Data6C640View1 __asm__("D_8006C640");
extern int Physics37Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics37Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics37Player0View1 __asm__("D_80070328");
extern int Physics37Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics37Player80View1 __asm__("D_80070328+0x80");
extern int Physics37PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics37Player64View1 __asm__("D_80070328+0x64");
extern int Physics37Player144View1 __asm__("D_80070328+0x144");
extern int Physics37Player60View1 __asm__("D_80070328+0x60");
extern int Physics37PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics37Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics37Player5CView1 __asm__("D_80070328+0x5C");
int Physics37MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics37ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics37ClearVectorView2() __asm__("func_8004F168");
int Physics37CopyVectorView2() __asm__("func_8004F178");
int Physics37AddVectorView2() __asm__("func_8004F194");
int Physics37SubtractVectorView2() __asm__("func_8004F1C8");
extern unsigned char Physics37Player0View2 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
int Physics37Call40D10View2() __asm__("func_80040D10");
int Physics37Call410F8View1() __asm__("func_800410F8");
int Physics37Call41580View2() __asm__("func_80041580");
int Physics37Call417FCView2() __asm__("func_800417FC");
int Physics37Call41848View1() __asm__("func_80041848");
int Physics37Call41B64View2() __asm__("func_80041B64");
int Physics37InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics37TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics37ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics37ClearVectorView3() __asm__("func_8004F168");
int Physics37CopyVectorView3() __asm__("func_8004F178");
int Physics37AddVectorView3() __asm__("func_8004F194");
int Physics37CallRandView2() __asm__("rand");
extern int* Physics37Data6C570View2 __asm__("D_8006C570");
extern int Physics37Data6C640View2 __asm__("D_8006C640");
extern int Physics37Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics37Player0View3 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics37Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics37Player158View1 __asm__("D_80070328+0x158");
extern int Physics37Player20CView1 __asm__("D_80070328+0x20C");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
void func_level_37_80088AD4(int slotIndex) {
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
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
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
    void* raw34_temp_a0_3;
    void* raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
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
    globalPointer = &Physics37Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics37Data6C570View1 = (void*)workWord2;
    workWord2 = Physics37Field(&Physics37Player0View1, int*, 0x54);
    stateWord3 = Physics37Field(&Physics37Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        default:
            return;
        case 20:
        case 53:
        case 54:
            globalVector80 = &Physics37Player0View1 + 0x80;
            Physics37ClearVectorView1(globalVector80);
            Physics37ClearVectorView1(globalVector80 + 0xC);
            if (Physics37Data6E044View1 != 7) {
                Physics37Call40D10View1(0x1200);
                Physics37Call416F4View1();
                Physics37Call41580View1(0x5A, 0x10);
                return;
            }
            return;
        case 29:
            Physics37ClearVectorView2(&originalFrame.sp10);
            raw34_temp_s1_2 = &Physics37Player0View2 + 0x8C;
            Physics37SubtractVectorView2(&originalFrame.sp10, &originalFrame.sp10, raw34_temp_s1_2);
            if (Physics37Field(&Physics37Player0View2, int*, 0xB8) != 0) {
                originalFrame.sp18 = 0;
                raw34_temp_v0_6 = Physics37MeasureVectorLengthView2(&originalFrame.sp10, 0);
                if (raw34_temp_v0_6 >= 0x41) {
                    Physics37ScaleVectorRatioQ15View2(&originalFrame.sp10, raw34_temp_v0_6, 0x40);
                }
                originalFrame.sp18 = -0xC0;
                call4 = raw34_temp_s1_2 - 12;
                call5 = raw34_temp_s1_2;
                call6 = &originalFrame.sp10;
                goto commit29;
            } else {
                raw34_temp_v0_7 = Physics37MeasureVectorLengthView2(&originalFrame.sp10, 1);
                if (raw34_temp_v0_7 >= 0x101) {
                    Physics37ScaleVectorRatioQ15View2(&originalFrame.sp10, raw34_temp_v0_7, 0x100);
                }
                Physics37AddVectorView2(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp10);
                call4 = raw34_temp_s1_2 - 12;
                call5 = raw34_temp_s1_2;
                MATCHING_KEEP(call5);
                call6 = call5 + 92;
            }
        commit29:
            Physics37AddVectorView2(call4, call5, call6);
            raw34_temp_a0_3 = &Physics37Player0View2 + 0x8C;
            Physics37CopyVectorView2(raw34_temp_a0_3, raw34_temp_a0_3 - 0xC);
            if (Physics37Field(&Physics37Player0View2, int*, 0x94) < -0x2300) {
                Physics37Field(&Physics37Player0View2, int*, 0x94) = -0x2300;
                return;
            }
            break;
        case 28:
            Physics37Call40D10View1(0xC80);
            Physics37Call41580View1(0x28, 8);
            Physics37Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics37Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics37InterpolateCosineView1(Physics37Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics37Field(&Physics37Player0View1, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics37Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp20 = workWord2;
            workWord2 = Physics37InterpolateSineView1(call4);
            workWord3 = Physics37Field(&Physics37Player0View1, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp24 = workWord2;
            Physics37SubtractVectorView1(&originalFrame.sp20, &originalFrame.sp20, globalVector8C);
            originalFrame.sp28 = 0;
            temp_v0_4 = Physics37MeasureVectorLengthView1(&originalFrame.sp20, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics37ScaleVectorRatioQ15View1(&originalFrame.sp20, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics37AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp20);
            Physics37Call41B64View1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics37Field(&Physics37Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics37Field(&Physics37Player0View1, int*, 0x94) - 0xC0;
            }
            Physics37Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics37Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics37Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp40;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics37CallRandView1() & 0xFF)) {
                        workWord2 = Physics37Call363DCView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics37Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp30 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics37Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp38 = 0xE;
                        originalFrame.sp40 = -0x12C;
                        originalFrame.sp44 = 0;
                        originalFrame.sp48 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp34 = (workWord3 * 5) >> 0xA;
                        Physics37TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp40 += Physics37Call363DCView1(0, 0x50);
                        originalFrame.sp44 += Physics37Call363DCView1(0, 0x50);
                        originalFrame.sp48 += Physics37Call363DCView1(0, 0x50);
                        Physics37AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp30);
                        Physics37Field(temp_v0_5, signed char*, 2) = 8;
                        Physics37Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 30:
            globalVector80 = &Physics37Player80View1;
            MATCHING_KEEP_VOLATILE_CLOBBER(globalVector80, "memory");
            goto block_154;
        case 58:
            globalFieldB8PointerState20 = &Physics37Player0View1 + 0xB8;
            if (Physics37Field(&Physics37Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp30;
                Physics37ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics37SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp38 = 0;
                temp_v0_6 = Physics37MeasureVectorLengthView1(&originalFrame.sp30, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics37ScaleVectorRatioQ15View1(&originalFrame.sp30, temp_v0_6, 0x40);
                }
                originalFrame.sp38 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics37AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp30);
                Physics37CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics37ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics37ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics37Field(&Physics37Player0View1, int*, 0x94) < -0x2300) {
                Physics37Field(&Physics37Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics37Field(&Physics37Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics37Data6C640View1 & 1)) {
                originalFrame.sp50 = 0;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = 0xE;
                Physics37CopyVectorView1(&originalFrame.sp60,
                                         (&Physics37Player0View1 + 0x94) - 0x94);
                originalFrame.sp60 += Physics37Call363DCView1(0, 0x12C);
                originalFrame.sp64 += Physics37Call363DCView1(0, 0x12C);
                originalFrame.sp68 += Physics37Call363DCView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp60, &originalFrame.sp50);
                Physics37Field(temp_v0_7, signed char*, 2) = 6;
                Physics37Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics37Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics37Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp50;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics37Call410F8View1(call4, call5, 0);
            workWord3 = Physics37Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics37Player60View1;
                numeric4 = Physics37Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric4 << 4;
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
                workWord2 = originalFrame.sp54;
                workWord3 = numeric4 + 1;
                Physics37Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.sp54 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics37Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.sp50 * 0x14) >> 7;
            Physics37Field(&Physics37Player0View3, int*, 0x64) =
                (int)((Physics37Field(&Physics37Player0View3, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics37Field(&Physics37Player0View3, int*, 0x60) +
                               ((int)(originalFrame.sp54 * -0xF) >> 7)) &
                              0xFFF;
            Physics37Field(&Physics37Player0View3, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics37Field(&Physics37Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x60) < -0x320) {
                Physics37Field(&Physics37Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x60) >= 0x321) {
                Physics37Field(&Physics37Player0View3, int*, 0x60) = 0x320;
            }
            if ((*Physics37Data6C570View2 & 0x40) ||
                (Physics37Field(&Physics37Player0View3, int*, 0x4C) == 1)) {
                Physics37Field(&Physics37Player0View3, int*, 0xAC) = 0xE00;
            } else {
                Physics37Field(&Physics37Player0View3, int*, 0xAC) = 0;
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x4C) == 2) {
                Physics37Call417FCView2(0xC0, 0xC0);
                if (Physics37Field(&Physics37Player0View3, int*, 0xB0) < 0xE01) {
                    Physics37Field(&Physics37Player0View3, int*, 0x4C) = 0;
                }
            } else {
                Physics37Call417FCView2(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics37Player0View3 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics37InterpolateCosineView2(
                                                Physics37Field(&Physics37Player0View3, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics37Field(&Physics37Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics37Field(&Physics37Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics37Field(&Physics37Player0View3, int*, 0x14C) + raw21_temp_a0_5;
            Physics37Field(&Physics37Player0View3, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics37Field(&Physics37Player0View3, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics37Field(&Physics37Player0View3, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics37Field(&Physics37Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x5C) < -0x300) {
                Physics37Field(&Physics37Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x5C) >= 0x301) {
                Physics37Field(&Physics37Player0View3, int*, 0x5C) = 0x300;
            }
            Physics37Call41848View1(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics37CopyVectorView3(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics37CallRandView2() & 31;
            if (workWord2)
                goto block_130;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto block_130;
            call5 = (void*)44;
            call6 = &originalFrame.sp58;
            particleArg7 = 0;
            MATCHING_KEEP(particleArg7);
            workWord2 = 544;
            originalFrame.sp58 = workWord2;
            workWord2 = 64;
            originalFrame.sp5C = 0;
            __asm__ volatile("" ::"i"(0x80089398) : "memory");
            originalFrame.sp60 = workWord2;
            goto block_129;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics37Player0View3 + 0x20C;
            if (!(Physics37Field(&Physics37Player0View3, int*, 0x20C) & 0x40)) {
                if (Physics37Data6E044View2 != 7) {
                    Physics37Call410F8View1(&originalFrame.sp58, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.sp58;
                    numeric4 = originalFrame.sp5C;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics37Player64View1;
                    workWord2 = Physics37Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics37Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics37Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics37Player60View1 = workWord2;
                    }
                    if (Physics37Field(&Physics37Player0View3, int*, 0x60) < -0x320) {
                        Physics37Field(&Physics37Player0View3, int*, 0x60) = -0x320;
                    }
                    if (Physics37Field(&Physics37Player0View3, int*, 0x60) >= 0x321) {
                        Physics37Field(&Physics37Player0View3, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics37InterpolateCosineView2(Physics37Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics37Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics37Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics37Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics37Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics37Player5CView1 = workWord2;
                    }
                    if (Physics37Field(&Physics37Player0View3, int*, 0x5C) < -0x300) {
                        Physics37Field(&Physics37Player0View3, int*, 0x5C) = -0x300;
                    }
                    if (Physics37Field(&Physics37Player0View3, int*, 0x5C) >= 0x301) {
                        Physics37Field(&Physics37Player0View3, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics37Player0View3 + 0x80;
                Physics37ClearVectorView3(raw21_temp_s0_9);
                Physics37ClearVectorView3(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics37CallRandView2() & 31;
                if (workWord2)
                    goto block_130;
                MATCHING_KEEP(workWord2);
                particleCall3 = Physics21_SpawnParticle;
                call4 = (void*)1;
                if (!particleCall3)
                    goto block_130;
                call5 = (void*)44;
                call6 = &originalFrame.sp70;
                particleArg7 = 0;
                MATCHING_KEEP(particleArg7);
                workWord2 = 544;
                originalFrame.sp70 = workWord2;
                workWord2 = 64;
                originalFrame.sp74 = 0;
                originalFrame.sp78 = workWord2;
            block_129:
                particleCall3(call4, call5, call6, particleArg7);
            block_130:
                globalPointer = &Physics37Player158View1;
                workWord2 = Physics37Field(globalPointer, int*, 0);
                workWord2++;
                Physics37Field(globalPointer, int*, 0) = workWord2;
                return;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics37Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics37Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp60;
            if (!workWord2)
                goto run42;
        block_132:
            Physics37PlayerACView1 = 0;
            Physics37PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics37Call410F8View1(call4, call5, 0);
            workWord3 = Physics37Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics37Player60View1;
                numeric5 = Physics37Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.sp64 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.sp64 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.sp64;
                workWord3 = numeric5 + 1;
                Physics37Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.sp64 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics37Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics37Player0View3 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.sp60 * 0x14) >> 7;
            Physics37Field(&Physics37Player0View3, int*, 0x64) =
                (int)((Physics37Field(&Physics37Player0View3, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics37Field(&Physics37Player0View3, int*, 0x60) +
                                ((int)(originalFrame.sp64 * -0xF) >> 7)) &
                               0xFFF;
            Physics37Field(&Physics37Player0View3, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics37Field(&Physics37Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x60) < -0x320) {
                Physics37Field(&Physics37Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x60) >= 0x321) {
                Physics37Field(&Physics37Player0View3, int*, 0x60) = 0x320;
            }
            Physics37Field(&Physics37Player0View3, int*, 0xAC) = 0x1C00;
            Physics37Call417FCView2(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics37InterpolateCosineView2(
                                                 Physics37Field(&Physics37Player0View3, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics37Field(&Physics37Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics37Field(&Physics37Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics37Field(&Physics37Player0View3, int*, 0x14C) + raw21_temp_a0_6;
            Physics37Field(&Physics37Player0View3, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics37Field(&Physics37Player0View3, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics37Field(&Physics37Player0View3, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics37Field(&Physics37Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x5C) < -0x300) {
                Physics37Field(&Physics37Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x5C) >= 0x301) {
                Physics37Field(&Physics37Player0View3, int*, 0x5C) = 0x300;
            }
            Physics37Call41848View1(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics37CopyVectorView3(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics37Field(&Physics37Player0View3, int*, 0xB4) >= 0x7D1)) {
                originalFrame.sp68 = -0x190;
                originalFrame.sp6C = 0x40 - (Physics37CallRandView2() & 0x7F);
                originalFrame.sp70 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp68, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics37Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics37Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            call4 = &Physics37Player80View1;
            MATCHING_KEEP(call4);
            Physics37ClearVectorView3(call4);
            call4 = &Physics37Player8CView1;
            MATCHING_KEEP(call4);
            Physics37ClearVectorView3(call4);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics37Data6E044View2;
            if (workWord3 == workWord2) {
                Physics37Field(&Physics37Player0View3, int*, 0xB0) = 0;
            } else {
                Physics37Call40D10View2(0x980);
                raw21_var_v0_2 = Physics37Call41580View2(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics37Field(&Physics37Player0View3, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics37Field(&Physics37Player0View3, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics37Call417FCView2(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics37Player0View3 + 0xB0;
            if (Physics37Field(&Physics37Player0View3, int*, 0xB0) != 0) {
                Physics37Call41848View1();
                Physics37Call41B64View2();
                Physics37Field(&Physics37Player0View3, int*, 0x94) = 0;
            } else {
                Physics37ClearVectorView3(raw21_temp_s0_11 - 0x30);
                Physics37ClearVectorView3(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics37Player0View3 + 0x28;
                if (Physics37Field(&Physics37Player0View3, int*, 0x28) < 0) {
                    if ((Physics37Field(&Physics37Player0View3, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics37Data6C640View2 & 1)) {
                        Physics37CopyVectorView3(&originalFrame.sp68, raw21_temp_s4 - 0x28);
                        originalFrame.sp84 = 0x40;
                        originalFrame.sp88 = 0;
                        originalFrame.sp80 =
                            (int)Physics37Field(&Physics37Player0View3, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp84 = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics37TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp80,
                                                             &originalFrame.sp90);
                        Physics37AddVectorView3(&originalFrame.sp68, &originalFrame.sp68,
                                                &originalFrame.sp90);
                        originalFrame.sp80 = 0;
                        originalFrame.sp70 = -Physics37Field(&Physics37Player0View3, int*, 0x28);
                        Physics37TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.sp80,
                                                             &originalFrame.sp80);
                        Physics37ShiftVectorRightTowardZeroView1(&originalFrame.sp80, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp68, &originalFrame.sp80);
                        if (!(Physics37CallRandView2() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp68, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics37Player0View3 + 0xB0;
                        if ((Physics37Field(&Physics37Player0View3, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics37Data6C640View2 & 7) &&
                            !(Physics37CallRandView2() & 3)) {
                            originalFrame.spA0 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.spA4 = 0;
                            originalFrame.spA8 = 0;
                            Physics37TransformVectorByBasisView2(
                                raw21_temp_s1_7 - 0x80, &originalFrame.spA0, &originalFrame.spA0);
                            Physics37AddVectorView3(&originalFrame.spA0, &originalFrame.spA0,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.spA8 =
                                -Physics37Field(&Physics37Player0View3, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.spA0, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics37Field(&Physics37Player0View3, int*, 0x144) -
                ((int)((Physics37Field(&Physics37Player0View3, int*, 0x148) * 2) +
                       (Physics37Field(&Physics37Player0View3, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics37Field(&Physics37Player0View3, int*, 0x148) + raw21_temp_a1_4;
            Physics37Field(&Physics37Player0View3, int*, 0x144) = raw21_temp_a1_4;
            Physics37Field(&Physics37Player0View3, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics37Field(&Physics37Player0View3, int*, 0x148) = 0x5900;
            }
            if (Physics37Field(&Physics37Player0View3, int*, 0x148) < -0x5900) {
                Physics37Field(&Physics37Player0View3, int*, 0x148) = -0x5900;
                return;
            }
            break;
    }
}
#undef Physics37Field


/* AI generated; not human reviewed. SCUS-94467 80089C1C..8008A0D8.
 * Verified30/44 scalar/table code reused only against original37 instructions.
 * Original37 supplies selector scope and independent table tails; meanings,
 * units and cadence remain unresolved. The first shared call/clear block follows
 * original80089C80..80089CA4. Empty memory boundary after first table flag
 * store retains original independent table tails without emitting instructions.
 * All original words, strict full translation unit and retail hashes required.
 */
extern int Callback37Step __asm__("D_80070328+0x144");
extern int Callback37Z __asm__("D_80070328+8");
extern int Callback37Limit __asm__("D_80070328+0x280");
extern Spyro Callback37Player __asm__("D_80070328");
int Callback37Call80037058(int x, int y) __asm__("func_80037058");
int Callback37Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback37Call80041930(void) __asm__("func_80041930");
void Callback37Call80041AE8(void) __asm__("func_80041AE8");
void Callback37Call80041C20(void) __asm__("func_80041C20");
void Callback37Call80042A44(void) __asm__("func_80042A44");
void Callback37Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38, D_8006C648;
int Callback37Query(Vector3D*, int) __asm__("func_8001A358");
extern int Callback37Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback37Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback37Values[] __asm__("D_8006FCF0");
void Callback37Call80049590(void) __asm__("func_80049590");
void func_level_37_80089C1C(void) {
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

    switch (Callback37Player.animationState) {
        case 0x14:
            if (func_800438F4() == 0)
                func_80043728();
            Callback37Call80041C20();
            Callback37Player.unk9a = 0;
            goto call42A44;
        case 0x35:
        case 0x36:
            Callback37Call80041C20();
        call42A44:
            Callback37Call80042A44();
        clearSharedValue:
            Callback37Player.unk4[0] = 0;
            return;
        case 0x1D:
            Callback37Call80041C20();
            Callback37Call80042A44();
            Callback37Call80043A38(0xC00);
            goto clearSharedValue;
        case 0x1C:
            Callback37Call80041C20();
            Callback37Call80042A44();
            Callback37Call80041930();
            if (Callback37Player.unk7a[3].z < 0 && Callback37Player.animationStateFrames >= 4)
                Callback37Player.unk5 = 1;
            goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5") = &Callback37Z;
            register int velocity __asm__("$6") = Callback37Step;
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
            status = Callback37Limit;
            velocity += tick;
            Callback37Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback37Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback37Step = 0x2580;
            }
        limitsDone:
            Callback37Call80041C20();
            Callback37Call80042A44();
            func_8004F178(&local.first, &Callback37Player.position);
            local.first.z += 0x400;
            Callback37Player.unk4[0] = Callback37Query(&local.first, 0xC00);
            positionDelta = (int)Callback37Player.union144.a.unk13cb;
            positionValue = Callback37Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
        case 0x28:
        case 0x29:
            Callback37Call80041C20();
            Callback37Call80042A44();
            descriptor = &Callback37Player.unk22[2];
            if (Callback37Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback37Values + valueOffset);
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
                *(int*)(Callback37Values + valueOffset) = tableValue;
            setDecreasingFlag:
                flagOffset = *descriptor * 0x2C;
                Callback37Flags[flagOffset] = Callback37Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x2A:
            Callback37Call80041C20();
            Callback37Call80042A44();
            Callback37Call80049590();
            descriptor = &Callback37Player.unk22[2];
            if (Callback37Call8003BF6C((int)D_8006C654->underwater, *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback37Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback37Player.unk22[2];
            }
            if (Callback37Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback37Values + valueOffset);
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
                *(int*)(Callback37Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback37Flags[flagOffset] = Callback37Flags[flagOffset] | 0x10;
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback37Call80041C20();
            Callback37Call80042A44();
            Callback37Call80041AE8();
            if ((unsigned char)Callback37Player.unk10[4] != 0) {
                computedValue = -Callback37Player.unk9ha[4] -
                                Callback37Call80037058(Callback37Player.position.x,
                                                       Callback37Player.position.y);
                positionValue = Callback37Player.unk4a - computedValue;
                Callback37Player.unk4[0] = computedValue;
                positionDelta = (int)Callback37Player.union144.a.unk13cc >> 6;
                goto storePosition;
            }
            break;
        storePosition:
            positionValue -= positionDelta;
            MATCHING_KEEP(positionValue);
            Callback37Player.position.z = positionValue;
            return;
        case 0x3A:
            Callback37Call80041C20();
            Callback37Call80042A44();
            Callback37Player.cheatColour.a = 0xFF;
            Callback37Player.unk4[0] = 0;
            Callback37Player.cheatColour.b = 0x20;
            Callback37Player.cheatColour.g = 0x20;
            Callback37Player.cheatColour.r = 0x20;
            break;
        default:
            return;
    }
}


#define LEVEL_ID 37
#define PlaySpyroSounds_level_37 func_level_37_8008A0DC
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_37_8008A218(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x14:
        case 0x1d:
        case 0x1e:
        case 0x2b:
        case 0x2c:
        case 0x35:
        case 0x36:
        case 0x3a:
            position = &spyro.unk9e;
            break;
        case 0x1c:
            position = 0;
            break;
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
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
            return;
        default:
            return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A294.
 * Reuses verified21 stack10/20/30 underwater/surface and numeric1D producers,
 * verified33 numeric1C vector/DC0/damage200 and drowning callback lifetimes.
 * Original37 retains independent descriptor15 call, clears244/250 before290
 * in selector1E, and shared35/36 stand. Offsets are bytes; widths and shifts
 * are original. Word60 wrap/clamp vectors800/801/FFF yield0/-7FF/-1.
 * Empty constraints preserve original register lifetimes and emit no opcodes.
 * Require every code/internal jump/owned dispatch word and complete retail
 * hashes. Helper/audio semantics, units, cadence and live parity remain open.
 */
extern Spyro Transition37_D_80070328 __asm__("D_80070328");
int Transition37MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition37ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition37_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition37RawUnion[] __asm__("D_80070328+0x144");
extern int Transition37RawMovement __asm__("D_80070328+0x50");
extern void (*Call37Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw37State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call37A358(Vector3D*, int) __asm__("func_8001A358");
extern int Raw37NegativeWord __asm__("D_80070328+0x28");
int Transition37RandBetween(int, int) __asm__("func_8003636C");
void Transition37_func_800441F0(void) __asm__("func_800441F0");
void Transition37_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_37_8008A294(int arg0) {
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
    switch (arg0) {
        case 0x14:
            Transition37_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition37_D_80070328.unk5 = 0;
            Transition37_func_800441F0();
            Transition37_D_80070328.grounded = 1;
            Transition37_D_80070328.union144.a.unk13cb = Transition37RandBetween(1, 3);
            Transition37_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x1D: {
            register int oldState __asm__("$4") = Transition37RawMovement;
            register int first __asm__("$3") = Transition37_D_80070328.unk17e.x;
            register int second __asm__("$2");
            register int third __asm__("$3");
            MATCHING_KEEP2_CLOBBER(oldState, first, "memory");
            second = 7;
            MATCHING_KEEP(second);
            Transition37RawMovement = second;
            MATCHING_BARRIER_VOLATILE("memory");
            second = Transition37_D_80070328.unk17e.y;
            MATCHING_KEEP_VOLATILE_CLOBBER(second, "memory");
            Transition37_D_80070328.unk5 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(first, "memory");
            first <<= 6;
            MATCHING_KEEP(first);
            Transition37_D_80070328.unk7a[2].x = first;
            MATCHING_BARRIER_VOLATILE("memory");
            third = Transition37_D_80070328.unk17e.z;
            second <<= 6;
            Transition37_D_80070328.union144.a.unk13cb = oldState;
            Transition37_D_80070328.unk7a[2].y = second;
            second = third << 6;
            if (third == 0)
                second = Transition37_D_80070328.unk7a[3].z;
            Transition37_D_80070328.unk7a[2].z = second;
            Transition37_func_80043A38(0xC00);
            Transition37_D_80070328.grounded = 1;
            Transition37_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            soundSelector = D_8006C654->spyroHurt;
            soundZero = 0;
            PlaySound(soundSelector, (Moby*)soundZero, 0);
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        }

        case 0x1C:
            savedBase = Transition37RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition37RawMovement;
            Transition37RawMovement = MOVEMENT_STATE_HURT;
            Transition37_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition37_D_80070328.unk8[0] = Transition37MeasureVectorLength(sourceC, 0);
            Transition37_D_80070328.unk7a[2].z = 0xDC0;
            Transition37_D_80070328.grounded = 0;
            Transition37_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition37_D_80070328.damageFlags & 0x200) {
                Transition37_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition37_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            goto clearPointers;
        case 0x1E: {
            register int oldState __asm__("$3") = Transition37RawMovement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Transition37RawMovement = value;
            value = 1;
            MATCHING_KEEP(value);
            Transition37_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Transition37_D_8006E524 = value;
            stateWord = (int*)Transition37RawUnion;
            MATCHING_KEEP(stateWord);
            Transition37_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Transition37_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            value = (int)D_8006C654->drown;
            MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
            Transition37_D_80070328.unk20a = 0;
            Transition37_D_80070328.critterMobyPtr = 0;
            Transition37_D_80070328.unk22[3] = value;
            return;
        }
        case 0x3A:
            Transition37_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition37_D_80070328.unk5 = 0;
            Transition37_func_80043A38(0xC00);
            Transition37_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition37_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x28:
        case 0x29:
            if (((unsigned)(Transition37_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition37_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition37_D_80070328.movementState - 0x50));
                    if ((Transition37_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw37NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition37_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call37A358(&vectors.first, 0x800);
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
                firstWrappedWord = Transition37_D_80070328.rotation.pitch & 0xFFF;
                Transition37_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition37_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition37_D_80070328.rotation.pitch > 0) {
                    Transition37_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition37_D_80070328.unk5 = 1;
                }
                Transition37ClearVector(
                    (Vector3D*)((unsigned char*)&Transition37_D_80070328.rotation.pitch + 0xEC));
                Transition37_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition37_D_80070328.unk8[0] = Transition37MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition37_D_80070328.rotation.pitch + 0x38), 0);
                Transition37_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition37_D_80070328.animationState == 0x2A) {
                Transition37_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition37_D_80070328.union144.a.unk13da = 0;
            }
            Transition37_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition37_D_80070328.unk20a = 0;
            Transition37_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw37State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw37NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition37_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call37A358(localVector, 0x800);
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
                if (Transition37_D_80070328.animationState == 0x2E) {
                    Transition37_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition37_D_80070328.rotation.pitch & 0xFFF;
                Transition37_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition37_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition37_D_80070328.rotation.pitch > 0) {
                    Transition37_D_80070328.rotation.pitch = 0;
                }
                Transition37_D_80070328.unk5 = 1;
                Transition37ClearVector(
                    (Vector3D*)((unsigned char*)&Transition37_D_80070328.animationState + 0x104));
                Transition37_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition37_D_80070328.unk8[0] = Transition37MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition37_D_80070328.animationState + 0x50), 0);
                Transition37_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition37_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition37_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition37RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition37RawUnion;
                    *(int*)unionPointer = (-Transition37_D_80070328.unk7a[2].z) >> 2;
                    if (Transition37RawMovement != 8) {
                        Transition37_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition37RawMovement = 10;
                    }
                    Transition37_D_80070328.unk5 = 0;
                    Transition37_D_80070328.unk8[0] =
                        Transition37MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition37_D_80070328.grounded = 1;
                    Transition37_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call37A358(localVector, 0x800);
                    vectors.third.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, localVector, 0);
                        SpawnParticle(6, 0x2E, localVector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        case 0x35:
        case 0x36:
            Transition37_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition37_D_80070328.unk5 = 0;
            Transition37_func_800441F0();
            Transition37_D_80070328.grounded = 1;
        clearPointers:
            Transition37_D_80070328.unk20a = 0;
            Transition37_D_80070328.critterMobyPtr = 0;
            return;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level37
 * 8008AB0C: original658 instructions and39 dispatch words in sibling4810
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original37.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A37W48 __asm__("D_80070328 + 0x48");
extern int A37W4C __asm__("D_80070328 + 0x4C");
extern int A37W54 __asm__("D_80070328 + 0x54");
extern int A37WA0 __asm__("D_80070328 + 0xA0");
extern int A37WA8 __asm__("D_80070328 + 0xA8");
extern int A37WAC __asm__("D_80070328 + 0xAC");
extern int A37WB0 __asm__("D_80070328 + 0xB0");
extern int A37WB8 __asm__("D_80070328 + 0xB8");
extern int A37WCC __asm__("D_80070328 + 0xCC");
extern int A37WD0 __asm__("D_80070328 + 0xD0");
extern int A37WD4 __asm__("D_80070328 + 0xD4");
extern int A37W8C __asm__("D_80070328 + 0x8C");
extern int A37W90 __asm__("D_80070328 + 0x90");
extern int A37W94 __asm__("D_80070328 + 0x94");
extern int A37WE4 __asm__("D_80070328 + 0xE4");
extern int A37W144 __asm__("D_80070328 + 0x144");
extern int A37W158 __asm__("D_80070328 + 0x158");
extern int A37W1EC __asm__("D_80070328 + 0x1EC");
extern int A37W1F0 __asm__("D_80070328 + 0x1F0");
extern int A37W240 __asm__("D_80070328 + 0x240");
extern int A37W280 __asm__("D_80070328 + 0x280");
extern unsigned char A37B14 __asm__("D_80070328 + 0x14");
extern unsigned char A37B15 __asm__("D_80070328 + 0x15");
extern unsigned char A37B16 __asm__("D_80070328 + 0x16");
extern unsigned char A37B17 __asm__("D_80070328 + 0x17");
extern unsigned char A37B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A37BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A37B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A37B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A37Player[] __asm__("D_80070328");
extern unsigned char A37Table[] __asm__("D_80066530");
extern int A37Buttons __asm__("D_8006E538"), A37NewButtons __asm__("D_8006E53C");
extern int A37Mode __asm__("D_8006E044"), A37Gate __asm__("D_8006E344"),
    A37Count __asm__("D_8006C514");
extern int (*A37Callback)() __asm__("unk_ovlheader_80074374");
extern int A37W24 __asm__("D_80070328 + 0x24");
extern int A37W28C __asm__("D_80070328 + 0x28C");
extern int A37W290 __asm__("D_80070328 + 0x290");
extern int A37Surface __asm__("D_8006FA38");
extern unsigned char* A37SoundDesc __asm__("D_8006C654");
int A37Sound() __asm__("PlaySound");
int A37H3BF6C() __asm__("func_8003BF6C");
int A37H3BE70() __asm__("func_8003BE70");
int A37H40994() __asm__("func_80040994");
int A37H4BEF8() __asm__("func_8004BEF8");
int A37H49688() __asm__("func_80049688");
int A37H498C0() __asm__("func_800498C0");
extern volatile int A37W20C __asm__("D_80070328 + 0x20C");
extern int A37W214 __asm__("D_80070328 + 0x214");
extern unsigned char A37B100 __asm__("D_80070328 + 0x100");
extern unsigned char A37E535 __asm__("D_8006E535");
extern unsigned char* A37Models __asm__("D_8006EE2C");
int A37H40BCC() __asm__("func_80040BCC");
int A37H1A310() __asm__("func_8001A310");
void func_level_37_8008AB0C(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register int* state __asm__("$16");
    switch (A37W48) {
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 55:
        case 56:
        case 57:
            return;
        case 20:
            if (A37H40994())
                return;
            if (A37NewButtons & 0x40)
                goto set6;
            if (A37WB8 >= 4 || A37WE4 >= 23)
                goto set7;
            work3 = A37Buttons;
            if (work3 & 0x80) {
                A37H4BEF8(13);
                return;
            }
            work2 = A37WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17)
                goto set1;
            work2 = work3 & 12;
            MATCHING_KEEP(work2);
            if (!work2 && A37WAC)
                goto set1;
            if (A37Mode == 7 || A37W240) {
                state = &A37W48;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                A37H4BEF8(0);
                if (A37Table[*((unsigned char*)state - 0x2C)] >= 96) {
                    A37B14 = A37B15;
                    A37B16 = A37B17;
                }
                A37B17 = 0;
                work3 = *state;
                work2 = 113;
                *((unsigned char*)state - 0x2C) = work2;
                A37W1F0 = 0;
                A37B15 = work3;
                A37W1EC = work3;
                return;
            }
            if (A37BFC) {
                A37H4BEF8(15);
                return;
            }
            A37H49688();
            return;
        case 53:
        case 54:
            if (!A37H40994())
                goto set0;
            return;
        case 29:
            if (A37W54 < 25)
                return;
            if (A37W280 < 0) {
                A37H4BEF8(31);
                return;
            }
        selectState:
            work3 = A37W144;
            if (work3 == 10)
                goto set44;
            work2 = work3 - 11;
            MATCHING_KEEP(work2);
            if ((unsigned int)work2 < 2)
                goto set41;
            if (!A37WB8)
                goto set0;
            goto set7;
        case 28:
            if (A37B1B5 && (A37NewButtons & 64))
                A37B1B6 = 1;
            if (A37WB8 || A37W54 < 16 || A37WE4 >= 23)
                goto buttons;
            work3 = A37WCC;
            work2 = A37W8C;
            work5 = work3 * work2;
            work3 = A37WD0;
            work2 = A37W90;
            work4 = work3 * work2;
            work3 = A37WD4;
            work2 = A37W94;
            work3 = work3 * work2;
            work2 = work5 + work4;
            work2 += work3;
            if (work2 >= 0)
                goto buttons;
            if (!A37WAC)
                goto checkSpeed;
            work3 = A37WB0;
            if (work3 > 3840) {
                A37H4BEF8(3);
                return;
            }
            work2 = work3 < 1921;
            MATCHING_KEEP(work2);
            if (!work2) {
                A37H4BEF8(2);
                return;
            }
        set1:
            A37H4BEF8(1);
            return;
        checkSpeed:
            if (A37WB0 < 1920)
                goto set0;
            A37H4BEF8(4);
            return;
        set0:
            A37H4BEF8(0);
            return;
        buttons:
            if ((A37Buttons & 128) && A37W4C == 1) {
                A37H4BEF8(22);
                return;
            }
            if (A37B1B5 && A37B1B6) {
                if (A37W4C != 1)
                    return;
            set17:
                A37H4BEF8(17);
                return;
            }
            if (A37W4C != 1)
                return;
            if (A37WA0 < -6400)
                goto set7;
            if (A37W54 < 91)
                return;
            goto set7;
        case 30: {
            register int* timer4 __asm__("$4");
            register int (*callback3)() __asm__("$3");
            if (A37NewButtons & 64)
                A37B1B6 = 1;
            if (A37Surface >= 0) {
                if (A37W144 <= 0x8FFF)
                    return;
                callback3 = A37Callback;
                A37W28C = -1;
                if (callback3) {
                    callback3();
                    return;
                }
                goto call498C0;
            }
            timer4 = &A37W280;
            MATCHING_KEEP(timer4);
            if (*timer4 < 0) {
                if (A37W144 <= 0x8FFF)
                    return;
                A37W28C = -1;
                goto call498C0;
            }
            work3 = A37W54;
            if (work3 >= 61) {
                *timer4 = -1;
                return;
            }
            work2 = work3 < 16;
            MATCHING_KEEP(work2);
            if (work2)
                return;
            if (!A37B1B6)
                return;
            if (A37W28C >= 0) {
                if (A37H3BF6C(A37W290, A37W28C))
                    A37H3BE70(A37W28C);
                A37W28C = -1;
            }
            goto set6;
        }
        case 40:
            if (A37H40994())
                return;
            if ((A37Buttons & 128) && A37W4C != 1)
                goto set42;
            if (A37WB0)
                return;
            if (!(A37W20C & 64))
                goto set41;
            if (A37W214 <= 0)
                return;
        set41:
            A37H4BEF8(41);
            return;
        case 41:
            if (A37H40994())
                return;
            work4 = A37Buttons;
            work2 = work4 & 128;
            if (work2) {
            set42:
                A37H4BEF8(42);
                return;
            }
            work2 = 7;
            work3 = A37Mode;
            if (work3 == work2)
                return;
            work2 = work4 & 64;
            if (work2)
                goto set40;
            if (!(A37W20C & 64))
                return;
            if (!A37W214)
                goto set40;
            return;
        case 42:
            if (A37H40BCC())
                return;
            if ((A37Buttons & 128) || A37W4C == 1)
                goto flag64;
            if (!(A37W20C & 128))
                goto set40;
        flag64:
            if (!(A37W20C & 64))
                return;
            goto set40;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
        entry43:
            if (A37H40994())
                return;
            if ((A37NewButtons & 64) && A37W54 >= 9) {
                work4 = 6;
                goto callSelector;
            }
            byte4 = &A37B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                work4 = 7;
                goto callSelector;
            }
            if (!(A37NewButtons & 128))
                goto check44;
            if (A37W54 < 9)
                goto check44;
            work2 = *(int*)(A37Models + 220);
            if (!work2)
                goto check44;
            byte4 -= 256;
            if (!A37H1A310(byte4, 1024, 1, 0))
                goto set40;
            goto check44;
        callSelector:
            A37H4BEF8(work4);
        check44:
            if (!A37E535)
                return;
        set44:
            A37H4BEF8(44);
            return;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            work3 = A37W4C;
            work2 = 1;
            if (work3 != work2)
                goto other44;
            if (A37NewButtons & 0x850)
                goto callback44;
            if (A37W54 < 61)
                return;
        callback44:
            callback2 = A37Callback;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto call498C0;
            callback2();
            return;
        other44:
            if (A37H40994())
                return;
            if ((A37NewButtons & 64) && A37W54 >= 9) {
            set6:
                A37H4BEF8(6);
                return;
            }
            byte4 = &A37B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
            set7:
                A37H4BEF8(7);
                return;
            }
            if (!(A37NewButtons & 128))
                goto mode44;
            if (A37W54 < 9)
                goto mode44;
            work2 = *(int*)(A37Models + 220);
            if (!work2)
                goto mode44;
            byte4 -= 256;
            if (A37H1A310(byte4, 1024, 1, 0))
                goto mode44;
        set40:
            A37H4BEF8(40);
            return;
        mode44:
            work3 = A37Mode;
            work2 = 7;
            if (work3 == work2)
                return;
            if (A37E535)
                return;
            A37H4BEF8(43);
            return;
        }
        case 58:
            work2 = A37W54 < 137;
            if (work2)
                return;
        call498C0:
            A37H498C0();
            return;
    }
}
