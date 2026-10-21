#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80088BDC.
 * Assembly SHA256 7675d5b2f026f49710b9177227137f8149be22dfecb6bec8c0375a087ff45a30.
 * AI-generated; not human reviewed. All1195 original instructions and
 * 90 selectors (bias20) are required. Original0xC0 frame retains scratch10..A4
 * and savedS0..S3. Decoded20/29/25/28/58/38/61/105/100..109 retain original
 * guarded vector, scalar, clamp, pointer and helper joins.
 * Seven independent ordinary C low-product variables retain their actual
 * short lifetimes. Signed division352 remains ordinary C; the compiler
 * emits the original high-product temporary without an undefined HI input.
 * Typed aliases remain distinct. Empty initialized constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every original native/linked instruction, conditional/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics13Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics13Call363DCView1() __asm__("func_800363DC");
unsigned char Physics13Call40D10View1() __asm__("func_80040D10");
unsigned char Physics13Call41580View1() __asm__("func_80041580");
unsigned char Physics13Call416F4View1() __asm__("func_800416F4");
unsigned char Physics13Call417FCView1() __asm__("func_800417FC");
unsigned char Physics13Call41B64View1() __asm__("func_80041B64");
int Physics13InterpolateSineView1() __asm__("func_8004E9E4");
int Physics13InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics13TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics13MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics13ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics13ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics13CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics13AddVectorView1() __asm__("func_8004F194");
unsigned char Physics13SubtractVectorView1() __asm__("func_8004F1C8");
int Physics13CallRandView1() __asm__("rand");
extern unsigned char Physics13Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics13Data65920View1 __asm__("D_80065920");
extern void* Physics13Data6C570View1 __asm__("D_8006C570");
extern int Physics13Data6C640View1 __asm__("D_8006C640");
extern int Physics13Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics13Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics13Player0View1 __asm__("D_80070328");
extern int Physics13Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics13Call40D10View2() __asm__("func_80040D10");
int Physics13Call40F48View1() __asm__("func_80040F48");
int Physics13Call410F8View1() __asm__("func_800410F8");
int Physics13Call41404View1() __asm__("func_80041404");
int Physics13Call41580View2() __asm__("func_80041580");
int Physics13Call416F4View2() __asm__("func_800416F4");
int Physics13Call417FCView2() __asm__("func_800417FC");
int Physics13Call41848View1() __asm__("func_80041848");
int Physics13Call41B64View2() __asm__("func_80041B64");
int Physics13InterpolateSineView2() __asm__("func_8004E9E4");
int Physics13InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics13MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics13ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics13ClearVectorView2() __asm__("func_8004F168");
int Physics13CopyVectorView2() __asm__("func_8004F178");
int Physics13AddVectorView2() __asm__("func_8004F194");
int Physics13SubtractVectorView2() __asm__("func_8004F1C8");
int Physics13Absolute12BitAngleDeltaView1() __asm__("func_8004F284");
extern int Physics13Data6763CView1 __asm__("D_8006763C");
extern int Physics13Data67640View1 __asm__("D_80067640");
extern int Physics13Data67644View1 __asm__("D_80067644");
extern unsigned char Physics13Data676E8View1 __asm__("D_800676E8");
extern int* Physics13Data6C570View2 __asm__("D_8006C570");
extern int Physics13Data6C58CView1 __asm__("D_8006C58C");
extern int Physics13Data6C5C8View1 __asm__("D_8006C5C8");
extern short Physics13Data6E040View1 __asm__("D_8006E040");
extern int Physics13Data6E044View2 __asm__("D_8006E044");
extern int Physics13Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics13Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics13PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics13Player94View2 __asm__("D_80070328+0x94");
extern int Physics13PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics13Player80View1 __asm__("D_80070328+0x80");
extern int Physics13PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics13Player64View1 __asm__("D_80070328+0x64");
extern int Physics13Player88View1 __asm__("D_80070328+0x88");
extern int Physics13Player84View1 __asm__("D_80070328+0x84");
extern int Physics13Player144View1 __asm__("D_80070328+0x144");
extern int Physics13Player60View1 __asm__("D_80070328+0x60");
extern int Physics13PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics13Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics13Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics13Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics13PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics13PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics13Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics13Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics13Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics13Player101View1 __asm__("D_80070328+0x101");
extern int Physics13PlayerA4View1 __asm__("D_80070328+0xA4");
extern int Physics13Player210View1 __asm__("D_80070328+0x210");
extern int Physics13PlayerF8View1 __asm__("D_80070328+0xF8");
extern int Physics13Player8View1 __asm__("D_80070328+0x8");
void func_level_13_80088BDC(int slotIndex) {
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void* vectorAt40 __asm__("$16");
    register void* vectorAt30 __asm__("$17");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5, lowProduct6;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$19");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$18");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    void* temp_v0_7;
    void* raw13_temp_s0_9;
    void* raw13_temp_s1_4;
    void* raw13_temp_s1_5;
    int raw13_temp_v0_15;
    int raw13_temp_v0_16;
    workWord2 = slotIndex * 16;
    globalPointer = &Physics13Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics13Data6C570View1 = (void*)workWord2;
    workWord2 = Physics13Field(&Physics13Player0View1, int*, 0x54);
    stateWord3 = Physics13Field(&Physics13Player0View1, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        case 20:
            globalVector80 = &Physics13Player0View1 + 0x80;
            Physics13ClearVectorView1(globalVector80);
            Physics13ClearVectorView1(globalVector80 + 0xC);
            if (Physics13Data6E044View1 != 7) {
                Physics13Call40D10View1(0x1200);
                Physics13Call416F4View1();
                Physics13Call41580View1(0x5A, 0x10);
                return;
            }
            return;
        case 29:
            Physics13ClearVectorView2(&originalFrame.sp10);
            call4 = &originalFrame.sp10;
            call5 = call4;
            MATCHING_KEEP2(call4, call5);
            globalVector80 = &Physics13Player0View2 + 0x8C;
            Physics13SubtractVectorView2(call4, call5, globalVector80);
            if (Physics13PlayerB8View1) {
                originalFrame.sp18 = 0;
                call5 = (void*)Physics13MeasureVectorLengthView2(&originalFrame.sp10, 0);
                workWord2 = (int)call5 < 65;
                if (!workWord2)
                    Physics13ScaleVectorRatioQ15View2(&originalFrame.sp10, call5, 64);
                originalFrame.sp18 = -192;
                call4 = globalVector80 - 12;
                call5 = globalVector80;
                call6 = &originalFrame.sp10;
                goto vector29;
            }
            call5 = (void*)Physics13MeasureVectorLengthView2(&originalFrame.sp10, 1);
            workWord2 = (int)call5 < 257;
            if (!workWord2)
                Physics13ScaleVectorRatioQ15View2(&originalFrame.sp10, call5, 256);
            Physics13AddVectorView2(globalVector80, globalVector80, &originalFrame.sp10);
            call4 = globalVector80 - 12;
            call5 = globalVector80;
            call6 = call5 + 0x5C;
        vector29:
            __asm__ volatile("" ::"i"(0x80088D4C) : "memory");
            Physics13AddVectorView2(call4, call5, call6);
            call4 = &Physics13Player0View2 + 0x8C;
            Physics13CopyVectorView2(call4, call4 - 12);
            workWord2 = Physics13Player94View2;
            workWord2 = workWord2 < -8960;
            goto clamp19;
        case 25:
            Physics13Call40F48View1(&originalFrame.sp20, 1);
            workWord2 = originalFrame.sp20;
            call4 = &Physics13PlayerA8View1;
            workWord2 >>= 1;
            Physics13Field(call4, int*, 0) = workWord2;
            workWord2 = workWord2 < -25;
            if (workWord2) {
                workWord2 = -25;
                Physics13Field(call4, int*, 0) = workWord2;
            }
            workWord2 = Physics13Field(call4, int*, 0);
            workWord2 = workWord2 < 26;
            if (!workWord2) {
                workWord2 = 25;
                Physics13Field(call4, int*, 0) = workWord2;
            }
            call4 = (void*)Physics13Field(call4, int*, 0);
            Physics13Call41404View1(call4);
            Physics13Call417FCView2(576, 384);
            workWord2 = Physics13InterpolateCosineView2(Physics13Player64View1);
            workWord3 = Physics13PlayerB0View1;
            lowProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics13Player64View1;
            workWord2 = lowProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            Physics13Player80View1 = workWord2;
            workWord2 = Physics13InterpolateSineView2(call4);
            workWord3 = Physics13PlayerB0View1;
            lowProduct1 = workWord3 * workWord2;
            workWord2 = Physics13Player94View2;
            Physics13Player88View1 = workWord2;
            workWord2 = lowProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            Physics13Player84View1 = workWord2;
            Physics13Call41B64View2();
            workWord2 = Physics13Player144View1;
            workWord2 += 12;
            Physics13Player144View1 = workWord2;
            workWord2 = workWord2 < 193;
            if (!workWord2) {
                workWord2 = 192;
                Physics13Player144View1 = workWord2;
            }
            workWord2 = Physics13Player94View2;
            workWord3 = Physics13Player144View1;
            workWord2 -= workWord3;
            Physics13Player94View2 = workWord2;
            workWord2 = workWord2 < -8960;
        clamp19:
            __asm__ volatile("" ::"i"(0x80088EA0) : "memory");
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics13Player94View2 = workWord2;
            return;
        case 28:
        case 107:
            Physics13Call40D10View1(0xC80);
            Physics13Call41580View1(0x28, 8);
            Physics13Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics13Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics13InterpolateCosineView1(Physics13Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics13Field(&Physics13Player0View1, int*, 0xB0);
            lowProduct2 = workWord3 * workWord2;
            call4 = (void*)Physics13Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct2 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp28 = workWord2;
            workWord2 = Physics13InterpolateSineView1(call4);
            workWord3 = Physics13Field(&Physics13Player0View1, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp2C = workWord2;
            Physics13SubtractVectorView1(&originalFrame.sp28, &originalFrame.sp28, globalVector8C);
            originalFrame.sp30 = 0;
            temp_v0_4 = Physics13MeasureVectorLengthView1(&originalFrame.sp28, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics13ScaleVectorRatioQ15View1(&originalFrame.sp28, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics13AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp28);
            Physics13Call41B64View1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics13Field(&Physics13Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics13Field(&Physics13Player0View1, int*, 0x94) - 0xC0;
            }
            Physics13Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics13Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics13Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp48;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics13CallRandView1() & 0xFF)) {
                        workWord2 = Physics13Call363DCView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics13Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp38 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics13Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp40 = 0xE;
                        originalFrame.sp48 = -0x12C;
                        originalFrame.sp4C = 0;
                        originalFrame.sp50 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp3C = (workWord3 * 5) >> 0xA;
                        Physics13TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp48 += Physics13Call363DCView1(0, 0x50);
                        originalFrame.sp4C += Physics13Call363DCView1(0, 0x50);
                        originalFrame.sp50 += Physics13Call363DCView1(0, 0x50);
                        Physics13AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp38);
                        Physics13Field(temp_v0_5, signed char*, 2) = 8;
                        Physics13Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 58:
        case 108:
            globalFieldB8PointerState20 = &Physics13Player0View1 + 0xB8;
            if (Physics13Field(&Physics13Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp38;
                Physics13ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics13SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp40 = 0;
                temp_v0_6 = Physics13MeasureVectorLengthView1(&originalFrame.sp38, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics13ScaleVectorRatioQ15View1(&originalFrame.sp38, temp_v0_6, 0x40);
                }
                originalFrame.sp40 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics13AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp38);
                Physics13CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics13ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics13ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics13Field(&Physics13Player0View1, int*, 0x94) < -0x2300) {
                Physics13Field(&Physics13Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics13Field(&Physics13Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics13Data6C640View1 & 1)) {
                originalFrame.sp58 = 0;
                originalFrame.sp5C = 0;
                originalFrame.sp60 = 0xE;
                Physics13CopyVectorView1(&originalFrame.sp68,
                                         (&Physics13Player0View1 + 0x94) - 0x94);
                originalFrame.sp68 += Physics13Call363DCView1(0, 0x12C);
                originalFrame.sp6C += Physics13Call363DCView1(0, 0x12C);
                originalFrame.sp70 += Physics13Call363DCView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp68, &originalFrame.sp58);
                Physics13Field(temp_v0_7, signed char*, 2) = 6;
                Physics13Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 38: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics13Call410F8View1(&originalFrame.sp58, &Physics13Player14CView1, 0);
            workWord3 = Physics13Player60View1;
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
                workWord3 = originalFrame.sp5C;
                workWord3 = -workWord3;
                MATCHING_KEEP(workWord3);
                workWord2 = workWord3 * 23;
                workWord3 = originalFrame.sp58;
                MATCHING_OBSERVE2(workWord3, workWord2);
                numeric5 = workWord2 >> 8;
                goto lateral38;
            }
            workWord3 = originalFrame.sp5C;
            workWord3 = -workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 23;
            workWord3 = originalFrame.sp58;
            MATCHING_OBSERVE2(workWord3, workWord2);
            numeric5 = workWord2 >> 7;
        lateral38:
            workWord2 = workWord3 * 30;
            globalVector80 = (void*)(workWord2 >> 7);
        rotate38:
            call4 = &Physics13Player64View1;
            workWord2 = Physics13Field(call4, int*, 0);
            workWord3 = Physics13Player60View1;
            workWord2 += (int)globalVector80;
            workWord2 &= 4095;
            workWord3 += numeric5;
            workWord3 &= 4095;
            Physics13Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics13Player60View1 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics13Player60View1 = workWord2;
            }
            workWord2 = Physics13Data6E538View1;
            workWord3 = 6144;
            Physics13PlayerACView1 = workWord3;
            workWord2 &= 192;
            if (workWord2) {
                workWord2 = 12800;
                Physics13PlayerACView1 = workWord2;
            }
            workWord3 = Physics13Player4CView1;
            workWord2 = 2;
            if (workWord3 == workWord2) {
                Physics13Call417FCView2(320, 192);
                workWord2 = Physics13PlayerB0View1 < 6145;
                if (workWord2)
                    Physics13Player4CView1 = 0;
            } else
                Physics13Call417FCView2(320, 80);
            globalFieldA4Pointer = &Physics13Player60View1;
            workWord2 =
                Physics13InterpolateCosineView2(Physics13Field(globalFieldA4Pointer, int*, 0));
            workWord2 <<= 5;
            workWord2 = -workWord2;
            lowProduct4 = (int)globalVector80 * workWord2;
            workWord3 = Physics13Player14CView1;
            numeric5 = Physics13Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = lowProduct4 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics13Player14CView1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics13Player5CView1 = numeric5;
            if (!workWord2) {
                workWord2 = numeric5 - 4096;
                Physics13Player5CView1 = workWord2;
            }
            workWord2 = Physics13Player5CView1;
            workWord2 = workWord2 < -768;
            if (workWord2) {
                workWord2 = -768;
                Physics13Player5CView1 = workWord2;
            }
            workWord2 = Physics13Player5CView1;
            workWord2 = workWord2 < 769;
            if (!workWord2) {
                workWord2 = 768;
                Physics13Player5CView1 = workWord2;
            }
            Physics13Call41848View1(numeric4, numeric5);
            Physics13CopyVectorView2(globalFieldA4Pointer + 44, globalFieldA4Pointer + 32);
            return;
        }
        case 61:
            Physics13Call40F48View1(&originalFrame.sp60, 1);
            workWord3 = originalFrame.sp60;
            workWord2 = workWord3 * 25;
            call4 = (void*)(workWord2 >> 7);
            if (call4)
                goto nonzero61;
            MATCHING_BARRIER_VOLATILE("$4");
            Physics13PlayerA8View1 = 0;
            goto approach61;
        nonzero61:
            if ((int)call4 >= 0)
                goto positive61;
            globalPointer = &Physics13PlayerA8View1;
            workWord2 = Physics13Field(globalPointer, int*, 0);
            if (workWord2 > 0)
                Physics13Field(globalPointer, int*, 0) = 0;
            goto approach61;
        positive61:
            globalPointer = &Physics13PlayerA8View1;
            workWord2 = Physics13Field(globalPointer, int*, 0);
            if (workWord2 < 0)
                Physics13Field(globalPointer, int*, 0) = 0;
        approach61:
            call5 = &Physics13PlayerA8View1;
            workWord3 = Physics13Field(call5, int*, 0);
            workWord2 = workWord3 < (int)call4;
            if (workWord2) {
                workWord2 = workWord3 + 3;
                Physics13Field(call5, int*, 0) = workWord2;
                workWord2 = (int)call4 < workWord2;
                goto clamp61;
            }
            workWord2 = workWord3 - 3;
            Physics13Field(call5, int*, 0) = workWord2;
            workWord2 = workWord2 < (int)call4;
        clamp61:
            if (workWord2)
                Physics13Field(call5, int*, 0) = (int)call4;
            call4 = (void*)Physics13PlayerA8View1;
            Physics13Call41404View1(call4);
            workWord3 = Physics13Player60View1;
            workWord2 = workWord3 < 2049;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics13Player60View1 = workWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                workWord3 = Physics13Player60View1;
            }
            if (workWord3 >= 0)
                goto nonnegative61;
            call4 = (void*)Physics13Data67640View1;
            workWord2 = Physics13Data6763CView1;
            workWord2 = (int)call4 - workWord2;
            goto quotient61;
        nonnegative61:
            if (workWord3 <= 0)
                goto zero61;
            workWord2 = Physics13Data67644View1;
            call4 = (void*)Physics13Data67640View1;
            workWord2 -= (int)call4;
        quotient61:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 352;
            call4 += workWord3;
            Physics13PlayerACView1 = (int)call4;
            goto update61;
        zero61:
            workWord2 = Physics13Data67640View1;
            Physics13PlayerACView1 = workWord2;
        update61:
            Physics13Call417FCView2(576, 384);
            Physics13Call41848View1();
            call6 = &Physics13PlayerFCView1;
            workWord2 = Physics13Field(call6, unsigned char*, 0);
            if (workWord2)
                goto field94FromA0;
            workWord2 = Physics13PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto field94FromA0;
            call5 = call6 - 124;
            goto vectorCommit61;
        case 105:
            globalVector80 = &Physics13Player0View2 + 0xB8;
            workWord2 = Physics13Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero105;
            vectorAt30 = &originalFrame.sp78;
            Physics13ClearVectorView2(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics13SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.sp80 = 0;
            call5 = (void*)Physics13MeasureVectorLengthView2(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics13ScaleVectorRatioQ15View2(vectorAt30, call5, 64);
            originalFrame.sp80 = -192;
            globalVector80 -= 56;
            Physics13AddVectorView2(globalVector80, globalVector8CState20, vectorAt30);
            Physics13CopyVectorView2(globalVector8CState20, globalVector80);
            goto clamp104;
        zero105:
            Physics13ClearVectorView2(globalVector80 - 56);
            Physics13ClearVectorView2(globalVector80 - 44);
            goto clamp104;
        case 100:
            globalVector80 = &Physics13Player0View2 + 0x80;
            Physics13ClearVectorView2(globalVector80);
            Physics13ClearVectorView2(globalVector80 + 12);
            if (Physics13Data6E044View2 != 7) {
                Physics13Call40D10View2(3840);
                Physics13Call416F4View2();
                Physics13Call41580View2(90, 16);
            }
            workWord2 = Physics13Player1BAView1;
            if (!workWord2) {
                workWord2 = 1;
                goto byteOne;
            }
            workWord2 = Physics13Data6E538View1 & 16;
            if (workWord2) {
                workWord2 = 1;
                goto wordOneReturn;
            }
            workWord2 = 1;
            Physics13Player1BAView1 = 0;
            __asm__ volatile("" ::"i"(0x800897E4) : "memory");
            goto byteOne;
        case 101:
            workWord3 = Physics13Data6E044View2;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics13Call40D10View2(3840);
            globalVector80 = &Physics13Data6E538View1;
            workWord2 = Physics13Field(globalVector80, int*, 0) & 12;
            if (workWord2)
                Physics13PlayerACView1 = 0;
            workWord2 = Physics13Call416F4View2();
            call4 = (void*)90;
            call5 = (void*)16;
            MATCHING_KEEP2(call4, call5);
            globalFieldA4Pointer = (void*)workWord2;
            workWord2 = Physics13Call41580View2(call4, call5);
            workWord3 = Physics13PlayerA8View1;
            if (workWord3 < 0)
                workWord3 = -workWord3;
            workWord3 = workWord3 < 8;
            __asm__("" : "=r"(workWord3) : "0"(workWord3), "r"(workWord2));
            call5 = (void*)workWord2;
            if (!workWord3)
                goto reset101;
            workWord2 = Physics13Field(globalVector80, int*, 0) & 12;
            if (!workWord2)
                goto reset101;
            workWord2 = Physics13Player144View1;
            workWord2++;
            Physics13Player144View1 = workWord2;
            goto saved101;
        reset101:
            Physics13Player144View1 = 0;
        saved101:
            call4 = &Physics13PlayerACView1;
            globalVector80 = (void*)Physics13Field(call4, int*, 0);
            if (globalFieldA4Pointer)
                goto collision101;
            workWord2 = (int)call5;
            if ((int)call5 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass101;
        collision101:
            workWord2 = Physics13Player20CView1 & 64;
            if (workWord2)
                Physics13Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics13PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics13Field(call4, int*, 0) = workWord3;
            }
        pass101:
            Physics13Call417FCView2(256, 384);
            workWord2 = Physics13Player101View1;
            call4 = &Physics13PlayerACView1;
            Physics13Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics13ClearVectorView2(call4 - 32);
                goto fields101;
            }
            Physics13Call41848View1(call4);
            Physics13Call41B64View2();
        fields101:
            call6 = &Physics13PlayerFCView1;
            workWord2 = Physics13Field(call6, unsigned char*, 0);
            if (workWord2)
                goto field94FromA0;
            workWord2 = Physics13PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto commit101;
        field94FromA0:
            workWord2 = Physics13PlayerA0View1;
            workWord2 -= 192;
            Physics13Player94View2 = workWord2;
            return;
        commit101:
            call5 = call4;
        vectorCommit61:
            Physics13AddVectorView2(call4, call5, call6 - 20);
            return;
        case 0x66:
        case 0x67:
        case 106: {
            register int limit17 __asm__("$17");
            register int numeric5 __asm__("$5");
            Physics13Call40D10View2(6400);
            workWord2 = Physics13Data6E538View1;
            workWord3 = workWord2 & 12;
            if (workWord3)
                goto held106;
            workWord2 = Physics13Absolute12BitAngleDeltaView1(Physics13PlayerA4View1,
                                                              Physics13Player64View1);
            workWord2 = workWord2 < 1665;
            if (workWord2)
                Physics13Call41580View2(44, 6);
            limit17 = 80;
            goto move106;
        held106:
            workWord2 = 8;
            if (workWord3 != workWord2)
                goto other106;
            workWord2 = Physics13Data6E040View1;
            workWord3 = 6400;
            Physics13PlayerACView1 = workWord3;
            workWord2 -= 1024;
            goto heading106;
        other106:
            workWord2 = 4;
            limit17 = 320;
            if (workWord3 != workWord2)
                goto move106;
            workWord2 = Physics13Data6E040View1;
            workWord3 = 6400;
            Physics13PlayerACView1 = workWord3;
            workWord2 += 1024;
        heading106:
            Physics13PlayerA4View1 = workWord2;
            limit17 = 320;
        move106:
            Physics13Call417FCView2(256, 384);
            globalVector8C = &Physics13Player210View1;
            workWord2 = Physics13Field(globalVector8C, int*, 0) & 1024;
            if (workWord2)
                goto clamp106;
            call4 = (void*)Physics13PlayerA4View1;
            globalVector8CState20 = globalVector8C - 388;
            workWord2 = Physics13InterpolateCosineView2(call4);
            workWord3 = Physics13PlayerB0View1;
            lowProduct5 = workWord3 * workWord2;
            call4 = (void*)Physics13PlayerA4View1;
            workWord2 = lowProduct5 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp88 = workWord2;
            workWord2 = Physics13InterpolateSineView2(call4);
            workWord3 = Physics13PlayerB0View1;
            lowProduct6 = workWord3 * workWord2;
            call4 = globalVector8CState20;
            call5 = globalVector8C - 376;
            workWord2 = lowProduct6 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp8C = workWord2;
            Physics13CopyVectorView2(call4, call5);
            globalVector80 = &originalFrame.sp88;
            Physics13SubtractVectorView2(globalVector80, globalVector80, globalVector8CState20);
            originalFrame.sp90 = 0;
            call5 = (void*)Physics13MeasureVectorLengthView2(globalVector80, 0);
            workWord2 = limit17 < (int)call5;
            if (workWord2)
                Physics13ScaleVectorRatioQ15View2(globalVector80, call5, limit17);
            Physics13AddVectorView2(globalVector8C - 400, globalVector8CState20, globalVector80);
            Physics13Call41B64View2();
            workWord2 = (int)Physics13Data6C570View2;
            workWord2 = Physics13Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                Physics13Player144View1 = 0;
            else {
                workWord2 = Physics13Player144View1;
                workWord2++;
                Physics13Player144View1 = workWord2;
            }
            workWord2 = Physics13Player144View1;
            workWord2 = workWord2 < 10;
            if (workWord2) {
                workWord2 = Physics13Player94View2;
                workWord2 += 256;
                goto store106;
            }
            workWord2 = Physics13Player94View2;
            workWord2 -= 96;
        store106:
            Physics13Player94View2 = workWord2;
            workWord2 = Physics13PlayerF8View1;
            workWord3 = Physics13Player8View1;
            numeric5 = workWord2 - workWord3;
            workWord2 = numeric5 < 4096;
            workWord3 = numeric5 << 2;
            if (!workWord2)
                goto mode106;
            workWord2 = Physics13Player94View2;
            workWord2 = workWord3 < workWord2;
            if (workWord2)
                Physics13Player94View2 = workWord3;
        mode106:
            workWord3 = Physics13Player4CView1;
            workWord2 = 127;
            if (workWord3 == workWord2)
                goto clamp106;
            call4 = &Physics13Data676E8View1;
            workWord2 = Physics13Data6C58CView1;
            workWord3 = Physics13Data6C5C8View1;
            workWord2 <<= 4;
            workWord2 += (int)call4;
            workWord3 <<= 2;
            workWord3 += workWord2;
            workWord2 = Physics13Player8View1;
            workWord3 = Physics13Field((void*)workWord3, int*, 0);
            workWord2 -= workWord3;
            numeric5 = workWord2 - 1024;
            workWord2 = numeric5 < 4096;
            workWord3 = -numeric5;
            if (workWord2) {
                workWord2 = Physics13Player94View2;
                MATCHING_OBSERVE2(workWord3, workWord2);
                workWord3 <<= 1;
                workWord2 = workWord2 < workWord3;
                if (workWord2)
                    Physics13Player94View2 = workWord3;
            }
        clamp106:
            globalPointer = &Physics13Player94View2;
            workWord2 = Physics13Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -4480;
            if (workWord2) {
                workWord2 = -4480;
                Physics13Field(globalPointer, int*, 0) = workWord2;
            }
            workWord2 = Physics13Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 1921;
            if (!workWord2) {
                workWord2 = 1920;
                Physics13Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        }
        case 104: {
            register int numeric5 __asm__("$5");
            Physics13ClearVectorView2(&originalFrame.sp98);
            raw13_temp_s1_4 = &Physics13Player0View2 + 0x8C;
            Physics13SubtractVectorView2(&originalFrame.sp98, &originalFrame.sp98, raw13_temp_s1_4);
            if (Physics13PlayerB8View1 != 0) {
                originalFrame.spA0 = 0;
                raw13_temp_v0_15 = Physics13MeasureVectorLengthView2(&originalFrame.sp98, 0);
                if (raw13_temp_v0_15 >= 0x41) {
                    Physics13ScaleVectorRatioQ15View2(&originalFrame.sp98, raw13_temp_v0_15, 0x40);
                }
            } else {
                raw13_temp_v0_16 = Physics13MeasureVectorLengthView2(&originalFrame.sp98, 1);
                if (raw13_temp_v0_16 >= 0x101) {
                    Physics13ScaleVectorRatioQ15View2(&originalFrame.sp98, raw13_temp_v0_16, 0x100);
                }
                Physics13AddVectorView2(raw13_temp_s1_4, raw13_temp_s1_4, &originalFrame.sp98);
            }
            raw13_temp_s0_9 = &Physics13Player0View2 + 0x80;
            raw13_temp_s1_5 = raw13_temp_s0_9 + 0xC;
            originalFrame.spA0 = -0xC0;
            Physics13AddVectorView2(raw13_temp_s0_9, raw13_temp_s1_5, &originalFrame.sp98);
            Physics13CopyVectorView2(raw13_temp_s1_5, raw13_temp_s0_9);
            call4 = &Physics13Data676E8View1;
            workWord2 = Physics13Data6C58CView1;
            workWord3 = Physics13Data6C5C8View1;
            workWord2 <<= 4;
            workWord2 += (int)call4;
            workWord3 <<= 2;
            workWord3 += workWord2;
            workWord2 = Physics13Player8View1;
            workWord3 = Physics13Field((void*)workWord3, int*, 0);
            workWord2 -= workWord3;
            numeric5 = workWord2 - 1024;
            workWord2 = numeric5 < 4096;
            workWord3 = -numeric5;
            if (workWord2) {
                workWord2 = Physics13Player94View2;
                MATCHING_OBSERVE2(workWord3, workWord2);
                workWord3 <<= 1;
                workWord2 = workWord2 < workWord3;
                if (workWord2)
                    Physics13Player94View2 = workWord3;
            }
        clamp104:
            globalPointer = &Physics13Player94View2;
            workWord2 = Physics13Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics13Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 109:
            globalVector80 = &Physics13Player0View2 + 0x80;
            Physics13ClearVectorView2(globalVector80);
            Physics13ClearVectorView2(globalVector80 + 12);
            workWord2 = Physics13Player1BAView1;
            if (!workWord2) {
                workWord2 = 1;
                goto byteOne;
            }
            workWord2 = Physics13Data6E538View1 & 16;
            if (workWord2) {
                workWord2 = 1;
                goto wordOneReturn;
            }
            workWord2 = 1;
            Physics13Player1BAView1 = 0;
        byteOne:
            Physics13Player1B9View1 = workWord2;
        wordOneReturn:
            MATCHING_OBSERVE(workWord2);
            return;
        default:
            return;
    }
}
#undef Physics13Field


extern unsigned char Callback13Values[] __asm__("D_8006FCF0");
extern unsigned char Callback13Flags[] __asm__("D_8006FCE6");
extern int Callback13Word8006E530 __asm__("D_8006E530");
extern int Callback13Word8006E52C __asm__("D_8006E52C");
extern int Callback13Word8006E344 __asm__("D_8006E344");
void Callback13Call80049590(void) __asm__("func_80049590");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089E88 callback.
 * Reuses verified22 child/vector path and verified21 table/flag producers.
 * Original13 supplies selector scope, independent case19 flag store, private
 * pointer S0, changed flag S3, source S2 and copy S1; standalone vectors SP18/28.
 * Private+30 child, child+38 halfword and byte source offsets24/-74/58 follow
 * original instructions. Table stride2C/flags10 and signed division preserved.
 * Empty constraints emit no instructions; retain original scheduling/lifetimes.
 * Units, helper meanings, audio semantics and update cadence remain unresolved.
 * Falsifiable acceptance: all original code/internal jumps/table words, strict
 * complete translation unit, complete EXE and every overlay retail hash.
 */
extern Spyro Callback13Player __asm__("D_80070328");
int Callback13Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback13Call80041930(void) __asm__("func_80041930");
void Callback13Call80041C20(void) __asm__("func_80041C20");
void Callback13Call80042A44(void) __asm__("func_80042A44");
void Callback13Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback13Word8006E538 __asm__("D_8006E538");
extern int D_8006C648;
int Callback13Query(Vector3D*, int) __asm__("func_8001A358");
extern unsigned char* Callback13Table[] __asm__("D_8006EE2C");
extern unsigned char Callback13Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback13Call8004F110(Vector3D*, int) __asm__("func_8004F110");
int Callback13Call80038000(Moby*, Vector3D*, int, int, int) __asm__("func_80038000");
void Callback13Call8004F1C8(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void Callback13Call8003BE70(int) __asm__("func_8003BE70");
void func_level_13_80089E88(void) {
    Vector3D localVector;
    int reserved;
    Vector3D copyVector;
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");


    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    register int flagOffset __asm__("$3");
    switch (Callback13Player.animationState) {
        case 0x14:
        case 0x64:
            if (func_800438F4() == 0)
                func_80043728();
            Callback13Call80041C20();
            Callback13Player.unk9a = 0;
            goto call42A44;
        case 0x67:
        case 0x69:
        case 0x6C:
            Callback13Call80041C20();
        call42A44:
            Callback13Call80042A44();
        clearSharedValue:
            Callback13Player.unk4[0] = 0;
            return;
        case 0x66:
            Callback13Call80041C20();
            Callback13Call80042A44();
            descriptorMoby = Callback13Player.critterMobyPtr;
            MATCHING_KEEP_VOLATILE_CLOBBER(descriptorMoby, "memory");
            Callback13Player.unk4[0] = 0;
            goto descriptorTail;
        case 0x65:
            func_800438F4();
            Callback13Call80041C20();
            Callback13Call80042A44();
            Callback13Call80041930();
            goto queryC00;
        case 0x1D:
        case 0x68:
            Callback13Call80041C20();
            Callback13Call80042A44();
        queryC00:
            Callback13Call80043A38(0xC00);
            goto clearSharedValue;
        case 0x19:
            Callback13Call80041C20();
            Callback13Call80042A44();
            Callback13Call80041930();
            Callback13Call80049590();
            if (Callback13Player.movementState == MOVEMENT_STATE_SUPERCHARGE && SpawnParticle != 0)
                SpawnParticle(1, 9, 0, 0);
            if (Callback13Player.unk7a[3].z < 0 && Callback13Player.animationStateFrames >= 4) {
                Callback13Player.unk5 = 1;
                MATCHING_BARRIER_VOLATILE("memory");
            } else if (Callback13Player.unk5 == 0 && !(Callback13Word8006E538 & 0x40))
                Callback13Player.unk5 = 2;
            goto clearSharedValue;
        case 0x1C:
        case 0x6B:
            Callback13Call80041C20();
            Callback13Call80042A44();
            Callback13Call80041930();
            if (Callback13Player.unk7a[3].z < 0 && Callback13Player.animationStateFrames >= 4)
                Callback13Player.unk5 = 1;
            goto clearSharedValue;
        case 0x26:
            Callback13Call80041C20();
            Callback13Call80042A44();
            descriptor = &Callback13Player.unk22[2];
            if (Callback13Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback13Values + valueOffset);
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
                *(int*)(Callback13Values + valueOffset) = tableValue;
            setDecreasingFlag:
                flagOffset = *descriptor * 0x2C;
                Callback13Flags[flagOffset] = Callback13Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x3A:
            Callback13Call80041C20();
            Callback13Call80042A44();
            Callback13Player.cheatColour.a = 255;
            Callback13Player.unk4[0] = 0;
            Callback13Player.cheatColour.b = 32;
            Callback13Player.cheatColour.g = 32;
            Callback13Player.cheatColour.r = 32;
            return;
        case 0x3D:
            Callback13Call80041C20();
            Callback13Call80042A44();
            Callback13Call80043A38(0xC00);
            Callback13Call80049590();
            if (SpawnParticle != 0)
                SpawnParticle(1, 9, 0, 0);
            Callback13Word8006E530 = 120;
            Callback13Player.unk4[0] = 0;
            Callback13Word8006E52C = 4;
            if (Callback13Word8006E344 == 0 &&
                Callback13Call8003BF6C((int)D_8006C654->supercharge, Callback13Player.unk22[2]) ==
                    0) {
                Callback13Player.unk22[2] = PlaySound((int)D_8006C654->supercharge, 0, 4);
                Callback13Player.unk22[3] = (int)D_8006C654->supercharge;
            }
            break;
        case 0x6A:
        case 0x6D: {
            register unsigned char* privateData __asm__("$16") =
                Callback13Player.critterMobyPtr->mobyTag;
            register int changed __asm__("$19") = 0;
            register Vector3D* copyBase __asm__("$17");
            register unsigned char* sourceBase __asm__("$18");
            register int queryHeight __asm__("$16");
            if (*(Moby**)(privateData + 0x30) != 0) {
                sourceBase = Callback13Source;
                func_8004F178((&localVector), (Vector3D*)sourceBase);
                Callback13Call8004F110((&localVector), 6);
                {
                    Moby* child = *(Moby**)(privateData + 0x30);
                    child->position.z +=
                        ((int)((unsigned int)*(unsigned short*)((unsigned char*)child + 0x38)
                               << 16)) >>
                        17;
                }
                func_8004F194((&localVector), (&localVector),
                              (Vector3D*)((unsigned char*)*(Moby**)(privateData + 0x30) + 0xC));
                copyBase = &copyVector;
                func_8004F178(copyBase, (&localVector));
                {
                    int height =
                        ((int)((unsigned int)*(
                                   unsigned short*)((unsigned char*)*(Moby**)(privateData + 0x30) +
                                                    0x38)
                               << 16)) >>
                        17;
                    register int result = Callback13Call80038000(
                        *(Moby**)(privateData + 0x30), (&localVector), height, height, 0x1022);
                    register Vector3D* childVector __asm__("$4") = (&localVector);
                    if (result != 0) {
                        register Vector3D* childCopy __asm__("$6") = copyBase;
                        {
                            register Moby* childArgument __asm__("$5") =
                                *(Moby**)(privateData + 0x30);
                            MATCHING_KEEP_VOLATILE_CLOBBER(changed, "memory");
                            changed = 1;
                            Callback13Call8004F1C8(childVector,
                                                   (Vector3D*)((unsigned char*)childArgument + 0xC),
                                                   childCopy);
                        }
                        func_8004F0E8((&localVector), 6);
                        func_8004F194((Vector3D*)sourceBase, (Vector3D*)sourceBase, (&localVector));
                    }
                }
                Callback13Call80041C20();
                {
                    register Vector3D* argument0 __asm__("$4") = (Vector3D*)(sourceBase + 0x24);
                    if (changed != 0) {
                        register int componentX __asm__("$8") = localVector.x;
                        register int divisor __asm__("$2") = D_8006C648;
                        register int componentY __asm__("$7");
                        register int componentZ __asm__("$3");
                        componentX /= divisor;
                        MATCHING_KEEP(componentX);
                        componentY = localVector.y / divisor;
                        MATCHING_KEEP(componentY);
                        componentZ = localVector.z / divisor;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(componentZ, argument0, "memory");
                        localVector.x = componentX;
                        localVector.y = componentY;
                        localVector.z = componentZ;
                        Callback13Call8004F1C8(argument0, argument0, (&localVector));
                    }
                }
                {
                    register Moby* child __asm__("$2") = *(Moby**)(privateData + 0x30);
                    register int childValue __asm__("$3") = *(short*)((unsigned char*)child + 0x38);
                    register int playerValue __asm__("$2") = Callback13Player.unk4a;
                    playerValue += childValue;
                    MATCHING_KEEP(playerValue);
                    queryHeight = playerValue + 64;
                }
                if (Callback13Query((Vector3D*)(sourceBase - 0x74), queryHeight) != 0 &&
                    Callback13Player.unk7a[2].z <= 0) {
                    if (Callback13Player.unk7a[2].z >= -2047)
                        Callback13Player.position.z = D_80071908 + queryHeight - 64;
                    Callback13Player.ticksSinceLastSurfaceTouch = 0;
                    func_8004F178((Vector3D*)(sourceBase + 0x58), &D_80071918);
                } else {
                    register int* counterPointer __asm__("$2") =
                        &Callback13Player.ticksSinceLastSurfaceTouch;
                    register int counterValue __asm__("$3");
                    register int vectorZ __asm__("$4");
                    MATCHING_KEEP(counterPointer);
                    Callback13Player.unk9e.x = 0;
                    Callback13Player.unk9e.y = 0;
                    counterValue = *counterPointer;
                    MATCHING_KEEP_VOLATILE_CLOBBER(counterPointer, "memory");
                    vectorZ = 4096;
                    Callback13Player.unk9e.z = vectorZ;
                    counterValue += 1;
                    *counterPointer = counterValue;
                }
            } else
                Callback13Call80041C20();
            Callback13Player.unk4[0] = 0;
            if (Callback13Player.animationState != 0x6A)
                return;
            descriptorMoby = Callback13Player.critterMobyPtr;
        descriptorTail:
            selector = Callback13Table[descriptorMoby->mobyClass][6];
            if (selector != (unsigned int)Callback13Player.unk22[3]) {
                if (Callback13Call8003BF6C(Callback13Player.unk22[3], Callback13Player.unk22[2]) !=
                    0)
                    Callback13Call8003BE70(Callback13Player.unk22[2]);
                Callback13Player.unk22[2] = -1;
            }
            Callback13Player.unk22[3] = selector;
            if (Callback13Call8003BF6C(selector, Callback13Player.unk22[2]) == 0)
                Callback13Player.unk22[2] = PlaySound(Callback13Player.unk22[3], 0, 4);
            return;
        }
        default:
            return;
    }
}


#define LEVEL_ID 13
#define PlaySpyroSounds_level_13 func_level_13_8008A5E4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_13_8008A750(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x14:
        case 0x1d:
        case 0x3a:
        case 0x3d:
        case 0x64:
        case 0x65:
        case 0x68:
        case 0x69:
        case 0x6c:
        case 0x6d:
            func_80043ABC(&spyro.unk9e);
            break;
        case 0x1c:
        case 0x66:
        case 0x67:
        case 0x6a:
        case 0x6b:
            func_80043ABC(0);
            break;
        case 0x19:
            func_80043E00((Vector3D*)((char*)&spyro + 0x8C));
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A7E8.
 * Reuses verified21 numeric1D/state9/B/3D, verified37 vector1C/DC0/damage200,
 * verified22 special64..6D. Original13 shared15/22/C descriptor call remains
 * at1C; 244/250 tail follows3D. Offsets are bytes, original widths/shifts and
 * branches retained. Empty constraints emit no opcodes and retain lifetimes.
 * Require every code/internal jump/owned dispatch word and complete retail
 * hashes. Helper/audio meanings, units, cadence and live parity remain open.
 */
extern short Signed13TableA[] __asm__("D_800658A0");
extern short Signed13TableB[] __asm__("D_80065920");
void Transition13ShiftVectorLeft(Vector3D*, int) __asm__("func_8004F0E8");
extern Spyro Transition13_D_80070328 __asm__("D_80070328");
int Transition13MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition13ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition13_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition13RawUnion[] __asm__("D_80070328+0x144");
extern int Transition13RawMovement __asm__("D_80070328+0x50");
extern void (*Call13Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw13State[] __asm__("D_80070328+0x50");
extern short Signed13TableA[] __asm__("D_800658A0");
extern short Signed13TableB[] __asm__("D_80065920");

extern int D_80071934;
int Transition13RandBetween(int, int) __asm__("func_8003636C");
void Transition13_func_800441F0(void) __asm__("func_800441F0");
void Transition13_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_13_8008A7E8(int arg0) {
    register Vector3D* destination __asm__("$4");

    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    switch (arg0) {
        case 0x14:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition13_D_80070328.unk5 = 0;
            Transition13_func_800441F0();
            Transition13_D_80070328.grounded = 1;
            Transition13_D_80070328.union144.a.unk13cb = Transition13RandBetween(1, 3);
            Transition13_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x1D: {
            register int oldState __asm__("$4") = Transition13RawMovement;
            register int first __asm__("$3") = Transition13_D_80070328.unk17e.x;
            register int second __asm__("$2");
            register int third __asm__("$3");
            MATCHING_KEEP2_CLOBBER(oldState, first, "memory");
            second = 7;
            MATCHING_KEEP(second);
            Transition13RawMovement = second;
            MATCHING_BARRIER_VOLATILE("memory");
            second = Transition13_D_80070328.unk17e.y;
            MATCHING_KEEP_VOLATILE_CLOBBER(second, "memory");
            Transition13_D_80070328.unk5 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(first, "memory");
            first <<= 6;
            MATCHING_KEEP(first);
            Transition13_D_80070328.unk7a[2].x = first;
            MATCHING_BARRIER_VOLATILE("memory");
            third = Transition13_D_80070328.unk17e.z;
            second <<= 6;
            Transition13_D_80070328.union144.a.unk13cb = oldState;
            Transition13_D_80070328.unk7a[2].y = second;
            second = third << 6;
            if (third == 0)
                second = Transition13_D_80070328.unk7a[3].z;
            Transition13_D_80070328.unk7a[2].z = second;
            Transition13_func_80043A38(0xC00);
            Transition13_D_80070328.grounded = 1;
            Transition13_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            soundSelector = D_8006C654->spyroHurt;
            soundZero = 0;
            goto sharedSound;
            goto clearPointers;
        }

        case 0x19:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
            Transition13_D_80070328.unk13a[0] = 0x60000;
            Transition13_D_80070328.unk5 = 0;
            Transition13_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition13_D_80070328.grounded = 0;
            Transition13_D_80070328.unk15b = 1;
            soundSelector = D_8006C654->jump;
            soundZero = 0;
            goto sharedSound;
        case 0x1C:
            savedBase = Transition13RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition13RawMovement;
            Transition13RawMovement = MOVEMENT_STATE_HURT;
            Transition13_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition13_D_80070328.unk8[0] = Transition13MeasureVectorLength(sourceC, 0);
            Transition13_D_80070328.unk7a[2].z = 0xDC0;
            Transition13_D_80070328.grounded = 0;
            Transition13_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            soundZero = 0;
            if (Transition13_D_80070328.damageFlags & 0x200) {
                Transition13_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition13_D_80070328.union144.a.unk13cc = 1;
                soundSelector = D_8006C654->lavaBurn;
            sharedSound:
                PlaySound(soundSelector, (Moby*)soundZero, 0);
            }
            goto clearPointers;
        case 0x3A:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition13_D_80070328.unk5 = 0;
            Transition13_func_80043A38(0xC00);
            Transition13_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition13_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x26:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            if (Transition13_D_80070328.animationState == 0x2A) {
                Transition13_D_80070328.unk5 = 2;
            }
            Transition13ClearVector(
                (Vector3D*)((unsigned char*)&Transition13_D_80070328.movementState + 0xFC));
            Transition13_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition13_D_80070328.unk8[0] = Transition13MeasureVectorLength(
                (Vector3D*)((unsigned char*)&Transition13_D_80070328.movementState + 0x48), 0);
            Transition13_D_80070328.grounded = 1;
            Transition13_D_80070328.unk4a = 0x280;
            return;
        case 0x3D:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
            Transition13_D_80070328.unk5 = 0;
            Transition13_D_80070328.unk13a[0] = 0x60000;
            Transition13_D_80070328.unk8[0] = Transition13MeasureVectorLength(
                (Vector3D*)((unsigned char*)&Transition13_D_80070328.movementState + 0x48), 0);
            Transition13_D_80070328.horizontalSpeed = 0x1E80;
            Transition13_func_80043A38(0xC00);
            Transition13_D_80070328.grounded = 1;
            if ((Transition13_D_80070328.unk13f[0] != 0) ||
                (Transition13_D_80070328.spitState != 0) || (Transition13_D_80070328.unk17t != 6)) {
                if (((unsigned)(Transition13_D_80070328.unk13f[0] - 3) < 2U) ||
                    (Transition13_D_80070328.unk13f[0] == 5)) {
                    Transition13_D_80070328.unk13f[0] = 5;
                } else {
                    Transition13_D_80070328.unk13f[0] = 0;
                }
                Transition13_D_80070328.spitState = 0;
                Transition13_D_80070328.unk17t = 6;
                func_80047138();
            }
        clearPointers:
            Transition13_D_80070328.unk20a = 0;
            Transition13_D_80070328.critterMobyPtr = 0;
            return;
        case 0x64:
        case 0x6D:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition13_D_80070328.unk5 = 0;
            Transition13_func_800441F0();
            Transition13_D_80070328.grounded = 1;
            return;
        case 0x65:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_WALK;
            if ((arg0 == 0x57) && (Transition13_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
                func_8004F178((Vector3D*)((unsigned char*)(unsigned char*)&Transition13_D_80070328
                                              .movementState +
                                          0x3C),
                              (Vector3D*)((unsigned char*)(unsigned char*)&Transition13_D_80070328
                                              .movementState +
                                          0x48));
                Transition13_D_80070328.unk5 = 1;
            } else {
                Transition13_D_80070328.unk5 = 0;
            }
            Transition13_D_80070328.unk8[0] =
                Transition13MeasureVectorLength(&Transition13_D_80070328.unk7a[3], 0);
            Transition13_func_80043A38(0xC00);
            Transition13_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition13_D_80070328.grounded = 1;
            goto clearSpecialTail;
        case 0x69:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition13_D_80070328.unk5 = 0;
            Transition13_func_80043A38(0xC00);
            Transition13_D_80070328.grounded = 1;
            goto clearDeathFlag;
        case 0x66:
        case 0x67:
        case 0x6A:
            stateBaseA = Raw13State;
            MATCHING_KEEP(stateBaseA);
            destination = (Vector3D*)(stateBaseA + 0x48);
            *(int*)stateBaseA = 3;
            Transition13_D_80070328.unk8[0] = Transition13MeasureVectorLength(destination, 0);
            Transition13_D_80070328.unk15b = 1;
            Transition13_D_80070328.grounded = 0;
            Transition13_D_80070328.union144.a.unk13cb = 0x14;
        clearSpecialTail:
            Transition13_D_80070328.idle = 0;
            Transition13_D_80070328.unk15g = 0;
            return;
        case 0x6B:
            savedBase = Transition13RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition13RawMovement;
            Transition13RawMovement = MOVEMENT_STATE_HURT;
            Transition13_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition13_D_80070328.unk8[0] = Transition13MeasureVectorLength(sourceC, 0);
            Transition13_D_80070328.unk7a[2].z = 0xDC0;
            Transition13_D_80070328.grounded = 0;
            Transition13_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition13_D_80070328.damageFlags & 0x200) {
                Transition13_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition13_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            return;
        case 0x6C:
            Transition13_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition13_D_80070328.unk5 = 0;
            Transition13_func_80043A38(0xC00);
            Transition13_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
        clearDeathFlag:
            Transition13_D_8006E524 = 0xF;
            return;
        case 0x68: {
            register int previousMovement __asm__("$2") = Transition13RawMovement;
            register int kind __asm__("$3");
            register int flags __asm__("$3");
            register unsigned char* unionPointer __asm__("$5");
            MATCHING_KEEP(previousMovement);
            kind = 7;
            MATCHING_KEEP(kind);
            Transition13RawMovement = kind;
            MATCHING_BARRIER_VOLATILE("memory");
            flags = Transition13_D_80070328.unk17a;
            MATCHING_KEEP_VOLATILE_CLOBBER(flags, "memory");
            unionPointer = Transition13RawUnion;
            MATCHING_KEEP2(flags, unionPointer);
            Transition13_D_80070328.unk5 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(flags, "memory");
            *(int*)unionPointer = previousMovement;
            if (flags & 0x400) {
                sourceC = (Vector3D*)(unionPointer - 0xB8);
                func_8004F178(sourceC, (Vector3D*)(unionPointer + 0xD8));
                Transition13ShiftVectorLeft(sourceC, 6);
            } else if (Transition13_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Transition13_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed13TableB + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                Transition13_D_80070328.unk7a[2].x = tableValueA >> 1;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed13TableA + tableOffsetOrValue);
                Transition13_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Transition13_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else
                Transition13ClearVector((Vector3D*)(unionPointer - 0xB8));
            destination = &Transition13_D_80070328.unk7a[1];
            func_8004F178(destination, (Vector3D*)((unsigned char*)destination + 0xC));
            Transition13_D_80070328.grounded = 1;
            Transition13_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            return;
        }
        default:
            return;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * func_level_13_8008AFCC:918 instructions and90 dispatch words, evidence4902.
 * Verified animation selector/input handler idioms reused; raw100..109 states
 * follow original private pointer, callback and numeric branch chains.
 * Field units, helper meanings and update cadence unresolved. Acceptance:
 * every original native/internal-target/table word and full retail hashes. */
#define A4891Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int A4891W48 __asm__("D_80070328 + 0x48");
extern unsigned char* A4891W250 __asm__("D_80070328 + 0x250");
extern volatile int A4891Buttons __asm__("D_8006E538");
extern unsigned char A4891E535 __asm__("D_8006E535");
extern int A4891WB8 __asm__("D_80070328 + 0xB8");
extern int A4891WE4 __asm__("D_80070328 + 0xE4");
extern int A4891WA8 __asm__("D_80070328 + 0xA8");
extern int A4891WAC __asm__("D_80070328 + 0xAC");
extern int A4891WB0 __asm__("D_80070328 + 0xB0");
extern int A4891W144 __asm__("D_80070328 + 0x144");
extern int A4891WA0 __asm__("D_80070328 + 0xA0");
extern int A4891W8 __asm__("D_80070328 + 8");
extern int A4891W4C __asm__("D_80070328 + 0x4C");
extern int A4891W94 __asm__("D_80070328 + 0x94");
extern int A4891W54 __asm__("D_80070328 + 0x54");
extern int A4891WCC __asm__("D_80070328 + 0xCC");
extern int A4891W8C __asm__("D_80070328 + 0x8C");
extern int A4891WD0 __asm__("D_80070328 + 0xD0");
extern int A4891W90 __asm__("D_80070328 + 0x90");
extern int A4891WD4 __asm__("D_80070328 + 0xD4");
extern unsigned char A4891Table[] __asm__("D_800676E8");
extern int A4891Row __asm__("D_8006C58C"), A4891Column __asm__("D_8006C5C8");
extern int (*A4891Callback)(int) __asm__("unk_ovlheader_8007431C");
void A4891Select(int) __asm__("func_8004BEF8");
void A4891H498C0(void) __asm__("func_800498C0");

extern int A4898W48 __asm__("D_80070328 + 0x48");
extern int A4898W4C __asm__("D_80070328 + 0x4C");
extern int A4898W54 __asm__("D_80070328 + 0x54");
extern int A4898WA0 __asm__("D_80070328 + 0xA0");
extern int A4898WA8 __asm__("D_80070328 + 0xA8");
extern int A4898WAC __asm__("D_80070328 + 0xAC");
extern int A4898WB0 __asm__("D_80070328 + 0xB0");
extern int A4898WB8 __asm__("D_80070328 + 0xB8");
extern int A4898WCC __asm__("D_80070328 + 0xCC");
extern int A4898WD0 __asm__("D_80070328 + 0xD0");
extern int A4898WD4 __asm__("D_80070328 + 0xD4");
extern int A4898W8C __asm__("D_80070328 + 0x8C");
extern int A4898W90 __asm__("D_80070328 + 0x90");
extern int A4898W94 __asm__("D_80070328 + 0x94");
extern int A4898WE4 __asm__("D_80070328 + 0xE4");
extern int A4898W144 __asm__("D_80070328 + 0x144");
extern int A4898W158 __asm__("D_80070328 + 0x158");
extern int A4898W1EC __asm__("D_80070328 + 0x1EC");
extern int A4898W1F0 __asm__("D_80070328 + 0x1F0");
extern int A4898W240 __asm__("D_80070328 + 0x240");
extern int A4898W280 __asm__("D_80070328 + 0x280");
extern unsigned char A4898B14 __asm__("D_80070328 + 0x14");
extern unsigned char A4898B15 __asm__("D_80070328 + 0x15");
extern unsigned char A4898B16 __asm__("D_80070328 + 0x16");
extern unsigned char A4898B17 __asm__("D_80070328 + 0x17");
extern unsigned char A4898B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A4898BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A4898B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A4898B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A4898Player[] __asm__("D_80070328");
extern unsigned char A4898Table[] __asm__("D_80066530");
extern int A4898Buttons __asm__("D_8006E538"), A4898NewButtons __asm__("D_8006E53C");
extern int A4898Mode __asm__("D_8006E044"), A4898Gate __asm__("D_8006E344"),
    A4898Count __asm__("D_8006C514");
extern int (*A4898Callback)() __asm__("unk_ovlheader_80074374");
extern int A4898W24 __asm__("D_80070328 + 0x24");
extern int A4898W28C __asm__("D_80070328 + 0x28C");
extern int A4898W290 __asm__("D_80070328 + 0x290");
extern int A4898Surface __asm__("D_8006FA38");
extern unsigned char* A4898SoundDesc __asm__("D_8006C654");
int A4898Sound() __asm__("PlaySound");
int A4898H40994() __asm__("func_80040994");
int A4898H4BEF8() __asm__("func_8004BEF8");
int A4898H49688() __asm__("func_80049688");
int A4898H498C0() __asm__("func_800498C0");
extern volatile int A4898W20C __asm__("D_80070328 + 0x20C");
extern int A4898W214 __asm__("D_80070328 + 0x214");
extern unsigned char A4898B100 __asm__("D_80070328 + 0x100");
extern unsigned char A4898E535 __asm__("D_8006E535");
extern unsigned char* A4898Models __asm__("D_8006EE2C");
int A4898H40BCC() __asm__("func_80040BCC");
extern int A4898W10C __asm__("D_80070328 + 0x10C");
extern int A4898WB4 __asm__("D_80070328 + 0xB4");
extern int A4898WA4 __asm__("D_80070328 + 0xA4");
extern int (*A4898Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A4898H40954() __asm__("func_80040954");

void func_level_13_8008AFCC(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int selector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* private16 __asm__("$16");
    register unsigned char* object4 __asm__("$4");
    register unsigned char* table4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");

    register int* state __asm__("$16");

    work2 = A4891W48;
    switch (work2) {
        case 21:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
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
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 59:
        case 60:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:
            return;

        case 20:
            if (A4898H40994())
                return;
            work2 = A4898NewButtons & 64;
            selector4 = 6;
            if (work2)
                goto select;
            work2 = A4898WB8 < 4;
            selector4 = 7;
            if (!work2)
                goto select;
            if (A4898WE4 >= 23)
                goto select;
            work3 = A4898Buttons;
            work2 = work3 & 128;
            selector4 = 13;
            if (work2)
                goto select;
            work2 = A4898WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17) {
                selector4 = 1;
                goto select;
            }
            work2 = work3 & 12;
            MATCHING_KEEP(work2);
            if (!work2) {
                work2 = A4898WAC;
                selector4 = 1;
                if (work2)
                    goto select;
            }
            if (A4898Mode == 7 || A4898W240) {
                state = &A4898W48;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                A4898H4BEF8(0);
                if (A4898Table[*((unsigned char*)state - 0x2C)] >= 96) {
                    A4898B14 = A4898B15;
                    A4898B16 = A4898B17;
                }
                A4898B17 = 0;
                work3 = *state;
                work2 = 113;
                *((unsigned char*)state - 0x2C) = work2;
                A4898W1F0 = 0;
                A4898B15 = work3;
                A4898W1EC = work3;
                return;
            }
            work2 = A4898BFC;
            selector4 = 15;
            if (work2)
                goto select;
            A4898H49688();
            return;
        case 29:
            if (A4898W54 < 25)
                return;
            if (A4898W280 < 0) {
                selector4 = 31;
                goto select;
            }
            work2 = 10;
            work3 = A4898W144;
            if (work3 == work2) {
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 44;
                goto select;
            }
            work2 = work3 - 11;
            if ((unsigned)work2 < 2) {
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 41;
                goto select;
            }
            work2 = A4898WB8;
            selector4 = 0;
            if (!work2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            selector4 = 7;
            goto select;
        case 25:
            if (A4898H40BCC())
                return;
            if (A4898B1B5 && (A4898NewButtons & 64))
                A4898B1B6 = 1;
            if (A4898WE4 >= 23) {
                work3 = A4898W8C;
                work2 = A4898WCC;
                selector4 = work3 * work2;
                work3 = A4898W90;
                work2 = A4898WD0;
                work3 = work3 * work2;
                work2 = selector4 + work3;
                selector4 = 14;
                if (work2 < 0)
                    goto select;
            }
            work3 = A4898WB0;
            if (work3 >= 3201) {
                work2 = A4898WB4 * 2;
                work2 = work2 < work3;
                selector4 = 14;
                if (work2)
                    goto select;
            }
            if (!A4898WB8) {
                work2 = A4898W54 < 5;
                selector4 = 61;
                if (!work2)
                    goto select;
            }
            if (A4898B1B6) {
                work2 = A4898W94;
                selector4 = 17;
                if (work2 >= 0)
                    return;
                goto select;
            }
            work2 = A4898W94;
            selector4 = 22;
            if (work2 >= 0)
                return;
            goto select;
        case 28:
            if (A4898B1B5 && (A4898NewButtons & 64))
                A4898B1B6 = 1;
            if (!A4898WB8 && A4898W54 >= 16 && A4898WE4 < 23) {
                work3 = A4898WCC;
                work2 = A4898W8C;
                product5 = work3 * work2;
                work3 = A4898WD0;
                work2 = A4898W90;
                selector4 = work3 * work2;
                work3 = A4898WD4;
                work2 = A4898W94;
                work3 *= work2;
                work2 = product5 + selector4;
                work2 += work3;
                if (work2 < 0) {
                    if (A4898WAC) {
                        work3 = A4898WB0;
                        if (work3 >= 3841) {
                            selector4 = 3;
                            goto select;
                        }
                        work2 = work3 < 1921;
                        selector4 = 1;
                        if (work2)
                            goto select;
                        selector4 = 2;
                        goto select;
                    }
                    work2 = A4898WB0 < 1920;
                    selector4 = 0;
                    if (work2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    selector4 = 4;
                    goto select;
                }
            }
            work2 = A4898Buttons & 128;
            if (work2 && A4898W4C == 1) {
                selector4 = 22;
                goto select;
            }
            if (A4898B1B5 && A4898B1B6) {
                work3 = A4898W4C;
                work2 = 1;
                selector4 = 17;
                if (work3 != work2)
                    return;
                goto select;
            }
            work3 = A4898W4C;
            work2 = 1;
            if (work3 != work2)
                return;
            work2 = A4898WA0 < -6400;
            selector4 = 7;
            if (work2)
                goto select;
            if (A4898W54 >= 91)
                goto select;
            return;

        case 38: {
            register int (*callback2)(int) __asm__("$2");
            callback2 = A4898Callback1;
            callback2(1);
            return;
        }
        case 58:
            if (A4898W54 < 137)
                return;
            A4898H498C0();
            return;

        case 61:
            if (A4898H40BCC())
                return;
            work2 = 1;
            MATCHING_KEEP(work2);
            state = &A4898W4C;
            MATCHING_KEEP(state);
            work3 = *state;
            if (work3 == work2) {
                if (A4898WB8 >= 4)
                    goto partial25;
                work2 = A4898H40954(A4898W10C);
                work3 = 9;
                if (work2 == work3)
                    goto finalSpeed;
                *state = 0;
                goto finalSpeed;
            }
            if (A4898Buttons & 64) {
            partial25:
                A4898H4BEF8(25);
                work2 = A4898WB8;
                work3 = 3520;
                A4898W94 = work3;
                A4898WB8 = work2 + 1;
                return;
            }
            work2 = A4898WB8 < 4;
            selector4 = 25;
            if (!work2)
                goto select;
            if (A4898WE4 >= 23) {
                work3 = A4898WCC;
                work2 = A4898W8C;
                selector4 = work3 * work2;
                work3 = A4898WD0;
                work2 = A4898W90;
                work3 = work3 * work2;
                work2 = selector4 + work3;
                selector4 = 7;
                if (work2 < 0)
                    goto select;
            }
            {
                register int* pointer4 __asm__("$4");
                pointer4 = &A4898W4C;
                MATCHING_KEEP(pointer4);
                work3 = *pointer4;
                work2 = 2;
                if (work3 == work2 && A4898W54 >= 16)
                    *pointer4 = 0;
            }
            if (A4898Buttons & 128)
                goto finalSpeed;
            work2 = A4898Surface;
            if (work2 >= 0)
                goto finalSpeed;
            work2 = 2;
            work3 = A4898W4C;
            selector4 = 3;
            if (work3 != work2)
                goto select;
        finalSpeed:
            work3 = A4898WB0;
            work2 = work3 < 3201;
            if (work2)
                return;
            work2 = A4898WB4 * 2;
            work2 = work2 < work3;
            selector4 = 14;
            if (!work2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto select;

        case 100:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            work3 = A4891Buttons;
            work2 = work3 & 64;
            selector4 = 102;
            if (work2)
                goto select;
            work2 = A4891WB8 < 4;
            selector4 = 103;
            if (!work2)
                goto select;
            if (A4891WE4 >= 23)
                goto select;
            work2 = A4891WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17) {
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 101;
                goto select;
            }
            work2 = work3 & 12;
            if (work2)
                return;
            work2 = A4891WAC;
            selector4 = 101;
            if (!work2)
                return;
            goto select;

        case 101:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2)
                goto select;
            work2 = A4891WB8 < 4;
            selector4 = 103;
            if (!work2)
                goto select;
            if (A4891WE4 >= 23)
                goto select;
            if (A4891E535) {
                work2 = A4891WB0;
                selector4 = 100;
                if (!work2)
                    goto select;
            }
            if (!(A4891Buttons & 12))
                return;
            work2 = A4891W144 < 16;
            selector4 = 100;
            if (work2)
                return;
            goto select;

        case 102:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            if (!A4891WB8 && A4891WA0 <= 0) {
                MATCHING_BARRIER_VOLATILE("memory");
                if (A4891WE4 >= 23)
                    return;
                work2 = A4891WAC;
                selector4 = 101;
                if (work2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 100;
                goto select;
            }
            if (A4891W144 < 11)
                return;
            table4 = A4891Table;
            work2 = A4891Row;
            work3 = A4891Column;
            work2 = (work2 << 4) + (int)table4;
            work3 = (work3 << 2) + work2;
            work2 = A4891W8;
            work3 = A4891Field((void*)work3, int*, 0);
            work2 -= work3;
            if (work2 <= 4096)
                return;
            work3 = A4891W4C;
            selector4 = 103;
            if (work3 == 127)
                return;
            goto select;

        case 103:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2)
                goto select;
            if (!A4891WB8) {
                if (A4891WE4 >= 23)
                    return;
                work2 = A4891WAC;
                selector4 = 101;
                if (work2)
                    goto select;
                selector4 = 100;
                goto select;
            }
            table4 = A4891Table;
            work2 = A4891Row;
            work3 = A4891Column;
            work2 = (work2 << 4) + (int)table4;
            work3 = (work3 << 2) + work2;
            work2 = A4891W8;
            work3 = A4891Field((void*)work3, int*, 0);
            work2 -= work3;
            selector4 = 102;
            if (work2 >= 4096)
                return;
            goto select;

        case 104:
            object4 = A4891W250;
            work2 = A4891W48;
            work3 = A4891Field(object4, unsigned char*, 0x3C);
            work2 -= 100;
            if (work3 != work2)
                return;
            work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
            if (!work2)
                return;
            work2 = A4891WB8;
            selector4 = 100;
            if (!work2)
                goto select;
            selector4 = 103;
            goto select;

        case 105:
        case 108:
            object4 = A4891W250;
            work2 = A4891W48;
            work3 = A4891Field(object4, unsigned char*, 0x3C);
            work2 -= 100;
            if (work3 != work2)
                return;
            work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
            if (!work2)
                return;
            A4891H498C0();
            return;

        case 106:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            if (!A4891Field(private16, int*, 0x30)) {
                work2 = A4891Buttons & 64;
                selector4 = 102;
                if (work2)
                    goto select;
                selector4 = 103;
                goto select;
            }
            if (A4891WB8)
                return;
            work2 = A4891W94;
            if (work2 > 0)
                return;
            work2 = -(work2 << 1) >> 2;
            A4891W94 = work2;
            A4891WA0 = work2;
            selector4 = 109;
            if (work2 >= 1024)
                return;
            goto select;

        case 107:
            if (!A4891WB8 && A4891W54 >= 16) {
                if (A4891WE4 >= 23)
                    return;
                work3 = A4891WCC;
                work2 = A4891W8C;
                product5 = work3 * work2;
                work3 = A4891WD0;
                work2 = A4891W90;
                selector4 = work3 * work2;
                work3 = A4891WD4;
                work2 = A4891W94;
                work3 *= work2;
                work2 = product5 + selector4;
                work2 += work3;
                if (work2 >= 0)
                    return;
                work2 = A4891WAC;
                selector4 = 100;
                if (!work2)
                    goto select;
                selector4 = 101;
                goto select;
            }
            work2 = A4891Buttons & 64;
            if (work2 && A4891W4C == 1) {
                selector4 = 102;
                goto select;
            }
            object4 = A4891W250;
            work2 = A4891W48;
            work3 = A4891Field(object4, unsigned char*, 0x3C);
            work2 -= 100;
            if (work3 != work2)
                return;
            work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
            if (!work2)
                return;
            selector4 = 103;
            goto select;

        case 109:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            if (!A4891Field(private16, int*, 0x30) || A4891WB8 >= 4) {
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 103;
                goto select;
            }
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2)
                goto select;
            MATCHING_BARRIER("$4");
            if (A4891E535)
                return;
            A4891WA0 = 1536;
            selector4 = 102;
            goto select;
    }
    return;
select:
    A4891Select(selector4);
}
#undef A4891Field
