#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008B0BC.
 * Assembly SHA256 3869d75db0523fa18a07c763ab54a45ea7c64979c542951234799710e5e8d48e.
 * AI-generated; not human reviewed. All1639 original instructions and
 * 52 selectors (bias10) are required. Frame0xE0 retains scratch10..C4,
 * savedS0..S4 and original incoming slotS2 / short combinedA0 producers.
 * Verified12/13/34 references retain five exact groups and near29/38/61
 * with per-case stack/address maps. Original10..12 and40..44/57 retain all
 * scalar, counter, signed spring, helper, callback, zero and shared joins.
 * Signed division144 uses a complete signed64 C product and the frozen
 * cc1 constant144 view, verified in this exact TU and30 signed native vectors.
 * Generic variable-product word extraction differs; this view must not be
 * generalized as a high-word helper or serialized PSX memory format.
 * No undefined accumulator input, CPU instruction assembly or opcode edits.
 * Typed aliases remain distinct. Empty initialized constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Rev1 transition files are identified cross-references; Rev0 words rule.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every original native/linked instruction, conditional/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics21Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics21Call363DCView1() __asm__("func_800363DC");
unsigned char Physics21Call40D10View1() __asm__("func_80040D10");
unsigned char Physics21Call41580View1() __asm__("func_80041580");
unsigned char Physics21Call416F4View1() __asm__("func_800416F4");
int Physics21MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics21ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics21ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics21CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics21AddVectorView1() __asm__("func_8004F194");
unsigned char Physics21SubtractVectorView1() __asm__("func_8004F1C8");
extern void* Physics21Data6C570View1 __asm__("D_8006C570");
extern int Physics21Data6C640View1 __asm__("D_8006C640");
extern int Physics21Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics21Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics21Player0View1 __asm__("D_80070328");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics21Call40F48View1() __asm__("func_80040F48");
int Physics21Call410F8View1() __asm__("func_800410F8");
int Physics21Call41404View1() __asm__("func_80041404");
int Physics21Call417FCView1() __asm__("func_800417FC");
int Physics21Call41848View1() __asm__("func_80041848");
int Physics21Call41B64View1() __asm__("func_80041B64");
int Physics21InterpolateSineView1() __asm__("func_8004E9E4");
int Physics21InterpolateCosineView1() __asm__("func_8004EA2C");
int Physics21AddVectorView2() __asm__("func_8004F194");
extern int Physics21Data6763CView1 __asm__("D_8006763C");
extern int Physics21Data67640View1 __asm__("D_80067640");
extern int Physics21Data67644View1 __asm__("D_80067644");
extern int Physics21Data6E538View1 __asm__("D_8006E538");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics21PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics21Player94View1 __asm__("D_80070328+0x94");
extern int Physics21PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics21Player80View1 __asm__("D_80070328+0x80");
extern int Physics21PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics21Player64View1 __asm__("D_80070328+0x64");
extern int Physics21Player88View1 __asm__("D_80070328+0x88");
extern int Physics21Player84View1 __asm__("D_80070328+0x84");
extern int Physics21Player144View1 __asm__("D_80070328+0x144");
extern int Physics21Player60View1 __asm__("D_80070328+0x60");
extern int Physics21PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics21Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics21Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics21Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics21PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics21PlayerA0View1 __asm__("D_80070328+0xA0");
extern signed char Physics21Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics21PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics21MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics21ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics21ClearVectorView2() __asm__("func_8004F168");
int Physics21CopyVectorView2() __asm__("func_8004F178");
int Physics21AddVectorView3() __asm__("func_8004F194");
int Physics21SubtractVectorView2() __asm__("func_8004F1C8");
extern unsigned char Physics21Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics21Data65920View1 __asm__("D_80065920");
extern int Physics21Data6C514View1 __asm__("D_8006C514");
extern int Physics21Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics21Player0View2 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics21Player16CView1 __asm__("D_80070328+0x16C");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
int Physics21Call40D10View2() __asm__("func_80040D10");
int Physics21Call410F8View2() __asm__("func_800410F8");
int Physics21Call41580View2() __asm__("func_80041580");
int Physics21Call417FCView2() __asm__("func_800417FC");
int Physics21Call41848View2() __asm__("func_80041848");
int Physics21Call41B64View2() __asm__("func_80041B64");
int Physics21InterpolateSineView2() __asm__("func_8004E9E4");
int Physics21InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics21TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics21MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics21ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics21ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics21ClearVectorView3() __asm__("func_8004F168");
int Physics21CopyVectorView3() __asm__("func_8004F178");
int Physics21AddVectorView4() __asm__("func_8004F194");
int Physics21SubtractVectorView3() __asm__("func_8004F1C8");
int Physics21CallRandView1() __asm__("rand");
extern int* Physics21Data6C570View2 __asm__("D_8006C570");
extern int Physics21Data6C640View2 __asm__("D_8006C640");
extern int Physics21Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics21Player0View3 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics21Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics21PlayerB4View1 __asm__("D_80070328+0xB4");
extern int Physics21Player158View1 __asm__("D_80070328+0x158");
extern int Physics21Player20CView1 __asm__("D_80070328+0x20C");
void func_level_21_8008B0BC(int slotIndex) {
    register void* (*particleCall3)() __asm__("$3");
    register int particleArg7 __asm__("$7");
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
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
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register int combinedIndex __asm__("$4");
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldB8PointerState1A __asm__("$16");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_7;
    void* raw34_temp_a0_3;
    void* raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
    int raw34_temp_v0_8;
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
    globalPointer = &Physics21Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics21Data6C570View1 = (void*)workWord2;
    workWord2 = Physics21Field(&Physics21Player0View1, int*, 0x54);
    stateWord3 = Physics21Field(&Physics21Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        case 20:
            globalVector80 = &Physics21Player0View1 + 0x80;
            Physics21ClearVectorView1(globalVector80);
            Physics21ClearVectorView1(globalVector80 + 0xC);
            if (Physics21Data6E044View1 != 7) {
                Physics21Call40D10View1(0x1200);
                Physics21Call416F4View1();
                Physics21Call41580View1(0x5A, 0x10);
                return;
            }
            return;
        default:
            return;
        case 10:
        case 11:
        case 12: {
            register void* pointer16 __asm__("$16");
            register int limit17 __asm__("$17");
            int product10a, product10b;
            union {
                long long wide;
                struct {
                    int high;
                    unsigned int low;
                } words;
            } product144;
            workWord3 = Physics21Data6E044View2;
            workWord2 = 7;
            call4 = (void*)50;
            if (workWord3 != workWord2) {
                Physics21Call40D10View2(4608);
                call4 = (void*)50;
            } else {
                workWord2 = Physics21Player64View1;
                Physics21PlayerACView1 = 0;
                Physics21PlayerA4View1 = workWord2;
            }
            Physics21Call41580View2(call4, 10);
            workWord3 = 0x38E30000;
            MATCHING_KEEP(workWord3);
            pointer16 = &Physics21PlayerACView1;
            workWord2 = Physics21Field(pointer16, int*, 0);
            workWord3 |= 0x8E39;
            product144.wide = (long long)workWord2 * workWord3;
            call4 = (void*)Physics21PlayerA4View1;
            Physics21PlayerB0View1 = workWord2;
            workWord2 >>= 31;
            workWord3 = product144.words.high >> 5;
            limit17 = workWord3 - workWord2;
            workWord2 = Physics21InterpolateCosineView2(call4);
            workWord3 = Physics21PlayerB0View1;
            product10a = workWord3 * workWord2;
            call4 = (void*)Physics21PlayerA4View1;
            workWord2 = product10a >> 12;
            MATCHING_KEEP2(workWord2, pointer16);
            Physics21Field(pointer16, int*, -44) = workWord2;
            workWord2 = Physics21InterpolateSineView2(call4);
            workWord3 = Physics21PlayerB0View1;
            product10b = workWord3 * workWord2;
            __asm__("" : "=r"(limit17) : "0"(limit17), "r"(workWord2), "r"(workWord3));
            limit17 += 32;
            call4 = &originalFrame.sp10;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = pointer16 - 44;
            pointer16 -= 32;
            Physics21Player88View1 = 0;
            workWord2 = product10b >> 12;
            MATCHING_KEEP(workWord2);
            Physics21Player84View1 = workWord2;
            MATCHING_KEEP_VOLATILE_CLOBBER(pointer16, "memory");
            Physics21SubtractVectorView3(call4, call5, pointer16);
            originalFrame.sp18 = 0;
            call5 = (void*)Physics21MeasureVectorLengthView3(&originalFrame.sp10, 0);
            workWord2 = limit17 < (int)call5;
            if (workWord2)
                Physics21ScaleVectorRatioQ15View3(&originalFrame.sp10, call5, limit17);
            call4 = pointer16;
            call5 = call4;
            Physics21AddVectorView4(call4, call5, &originalFrame.sp10);
            workWord2 = Physics21PlayerB4View1;
            workWord3 = -3072;
            Physics21Player94View1 = workWord3;
            workWord2 = workWord2 < 65;
            if (workWord2) {
                Physics21Player1B9View1 = 1;
                return;
            }
            Physics21Player1B9View1 = 0;
            return;
        }
        case 19: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3 = Physics21Data6E344View1;
            workWord2 = 13;
            if (workWord3 == workWord2) {
                workWord2 = Physics21Data6C514View1;
                if (workWord2)
                    return;
            }
            globalVector8CState20 = &Physics21Player0View2 + 8;
            workWord3 = Physics21Field(globalVector8CState20, int*, 0);
            workWord2 = Physics21Field(&Physics21Player0View2, int*, 0x144);
            numeric4 = workWord3 - workWord2;
            workWord2 = numeric4 < 1024;
            if (!workWord2)
                goto beyond19;
            workWord2 = Physics21Player94View1;
            workWord2 += 128;
            Physics21Player94View1 = workWord2;
            workWord2 = workWord2 < 4801;
            __asm__("" : "=r"(numeric4) : "0"(numeric4), "r"(workWord2));
            if (!workWord2) {
                workWord2 = 4800;
                Physics21Player94View1 = workWord2;
            }
            lowProduct2 = numeric4 * numeric4;
            vectorAt30 = &originalFrame.sp20;
            call4 = vectorAt30;
            workWord3 = Physics21Field(&Physics21Player0View2, int*, 0x148);
            MATCHING_OBSERVE3(workWord2, workWord3, call4);
            workWord2 = lowProduct2 >> 11;
            angle16 = workWord2 + workWord3;
            Physics21Player64View1 = angle16;
            __asm__ volatile(""
                             : "=r"(globalVector8CState20)
                             : "0"(globalVector8CState20), "r"(call4)
                             : "memory");
            Physics21CopyVectorView2(call4, globalVector8CState20 + 340);
            call4 = vectorAt30;
            call5 = call4;
            Physics21SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics21MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8008B3C0) : "memory");
            numeric6 = 1024;
            goto limit19;
        beyond19:
            numeric5 = Physics21Field(&Physics21Player0View2, int*, 0x14C);
            workWord2 = workWord3 - numeric5;
            workWord2 = workWord2 < -1024;
            numeric6 = numeric5 - workWord3;
            if (!workWord2)
                goto curve19;
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x8008B3E4));
            workWord2 = Physics21Player4CView1;
            workWord3 = 1;
            if (!workWord2) {
                workWord2 = Physics21Field(&Physics21Player0View2, int*, 0x148);
                Physics21Player4CView1 = workWord3;
                workWord2 += 512;
                Physics21Field(&Physics21Player0View2, int*, 0x148) = workWord2;
            }
            workWord2 = Physics21Player94View1;
            workWord2 += 128;
            Physics21Player94View1 = workWord2;
            workWord2 = workWord2 < 4801;
            if (!workWord2)
                Physics21Player94View1 = 4800;
            workWord2 = Physics21Field(&Physics21Player0View2, int*, 0x150);
            numeric6 = numeric4 - 1024;
            workWord3 = workWord2 * numeric6;
            workWord2 = Physics21Field(&Physics21Player0View2, int*, 0x154);
            workWord2 = workWord3 / workWord2;
            vectorAt30 = &originalFrame.sp20;
            call4 = vectorAt30;
            workWord3 = Physics21Field(&Physics21Player0View2, int*, 0x148);
            angle16 = workWord3 + workWord2;
            workWord2 = (numeric6 << 10) >> 10;
            workWord2 = angle16 + workWord2;
            angle16 = workWord2 & 4095;
            Physics21Player64View1 = angle16;
            Physics21CopyVectorView2(call4, globalVector8CState20 + 340);
            call4 = vectorAt30;
            call5 = call4;
            Physics21SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics21MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8008B4F8) : "memory");
            numeric6 = 1024;
            goto limit19;
        curve19:
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x8008B500));
            workWord2 = (numeric6 * 4800) >> 10;
            Physics21Player94View1 = workWord2;
            workWord2 = Physics21Player16CView1;
            numeric7 = Physics21Field(&Physics21Player0View2, int*, 0x168);
            workWord3 = Physics21Field(&Physics21Player0View2, int*, 0x158);
            workWord2 &= 127;
            numeric4 = numeric7 << 1;
            Physics21Player16CView1 = workWord2;
            workWord2 = *(short*)(&Physics21Data65920View1 + numeric4);
            workWord3 += 1024;
            product10 = workWord3 * workWord2;
            square8 = numeric6 * numeric6;
            workWord2 = product10 >> 12;
            originalFrame.sp20 = workWord2;
            workWord2 = *(short*)(&Physics21Data658A0View1 + numeric4);
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
            Physics21AddVectorView3(call4, call5, numeric6, numeric7);
            call4 = vectorAt30;
            call5 = call4;
            Physics21Player64View1 = angle16;
            Physics21SubtractVectorView2(call4, call5, globalVector8CState20 - 8);
            call4 = vectorAt30;
            call5 = 0;
            originalFrame.sp28 = 0;
            workWord2 = Physics21MeasureVectorLengthView2(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 2049;
            call4 = vectorAt30;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            numeric6 = 2048;
        limit19:
            Physics21ScaleVectorRatioQ15View2(call4, call5, numeric6);
        commit19:
            workWord2 = originalFrame.sp20;
            workWord3 = originalFrame.sp24;
            Physics21Field(&Physics21Player0View2, int*, 0x8C) = workWord2;
            Physics21Field(&Physics21Player0View2, int*, 0x90) = workWord3;
            return;
        }
        case 0x1D:
            Physics21ClearVectorView2(&originalFrame.sp30);
            raw34_temp_s1_2 = &Physics21Player0View2 + 0x8C;
            Physics21SubtractVectorView2(&originalFrame.sp30, &originalFrame.sp30, raw34_temp_s1_2);
            if (Physics21Field(&Physics21Player0View2, int*, 0xB8) != 0) {
                originalFrame.sp38 = 0;
                raw34_temp_v0_6 = Physics21MeasureVectorLengthView2(&originalFrame.sp30, 0);
                if (raw34_temp_v0_6 >= 0x41) {
                    Physics21ScaleVectorRatioQ15View2(&originalFrame.sp30, raw34_temp_v0_6, 0x40);
                }
                originalFrame.sp38 = -0xC0;
                call4 = raw34_temp_s1_2 - 12;
                call5 = raw34_temp_s1_2;
                call6 = &originalFrame.sp30;
                goto commit29;
            } else {
                raw34_temp_v0_7 = Physics21MeasureVectorLengthView2(&originalFrame.sp30, 1);
                if (raw34_temp_v0_7 >= 0x101) {
                    Physics21ScaleVectorRatioQ15View2(&originalFrame.sp30, raw34_temp_v0_7, 0x100);
                }
                Physics21AddVectorView3(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp30);
                call4 = raw34_temp_s1_2 - 12;
                call5 = raw34_temp_s1_2;
                MATCHING_KEEP(call5);
                call6 = call5 + 92;
            }
        commit29:
            Physics21AddVectorView3(call4, call5, call6);
            raw34_temp_a0_3 = &Physics21Player0View2 + 0x8C;
            Physics21CopyVectorView2(raw34_temp_a0_3, raw34_temp_a0_3 - 0xC);
            workWord2 = Physics21Player94View1;
            __asm__ volatile("" ::"i"(0x8008B6F8) : "memory");
            workWord2 = workWord2 < -8960;
            goto clamp19;
        case 25:
            Physics21Call40F48View1(&originalFrame.sp40, 1);
            workWord2 = originalFrame.sp40;
            call4 = &Physics21PlayerA8View1;
            workWord2 >>= 1;
            Physics21Field(call4, int*, 0) = workWord2;
            workWord2 = workWord2 < -25;
            if (workWord2) {
                workWord2 = -25;
                Physics21Field(call4, int*, 0) = workWord2;
            }
            workWord2 = Physics21Field(call4, int*, 0);
            workWord2 = workWord2 < 26;
            if (!workWord2) {
                workWord2 = 25;
                Physics21Field(call4, int*, 0) = workWord2;
            }
            call4 = (void*)Physics21Field(call4, int*, 0);
            Physics21Call41404View1(call4);
            Physics21Call417FCView1(576, 384);
            workWord2 = Physics21InterpolateCosineView1(Physics21Player64View1);
            workWord3 = Physics21PlayerB0View1;
            lowProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics21Player64View1;
            workWord2 = lowProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            Physics21Player80View1 = workWord2;
            workWord2 = Physics21InterpolateSineView1(call4);
            workWord3 = Physics21PlayerB0View1;
            lowProduct1 = workWord3 * workWord2;
            workWord2 = Physics21Player94View1;
            Physics21Player88View1 = workWord2;
            workWord2 = lowProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            Physics21Player84View1 = workWord2;
            Physics21Call41B64View1();
            workWord2 = Physics21Player144View1;
            workWord2 += 12;
            Physics21Player144View1 = workWord2;
            workWord2 = workWord2 < 193;
            if (!workWord2) {
                workWord2 = 192;
                Physics21Player144View1 = workWord2;
            }
            workWord2 = Physics21Player94View1;
            workWord3 = Physics21Player144View1;
            workWord2 -= workWord3;
            Physics21Player94View1 = workWord2;
            workWord2 = workWord2 < -8960;
        clamp19:
            __asm__ volatile("" ::"i"(0x8008B82C) : "memory");
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics21Player94View1 = workWord2;
            return;
        case 26:
            globalFieldB8PointerState1A = &Physics21Player0View2 + 0xB8;
            if (Physics21Field(&Physics21Player0View2, int*, 0xB8) != 0) {
                raw34_temp_v0_8 = Physics21Field(&Physics21Player0View2, int*, 0x94) - 0x600;
                Physics21Field(&Physics21Player0View2, int*, 0x94) = raw34_temp_v0_8;
                if (raw34_temp_v0_8 < -0x2300) {
                    Physics21Field(&Physics21Player0View2, int*, 0x94) = -0x2300;
                }
                Physics21CopyVectorView2(globalFieldB8PointerState1A - 0x38,
                                         globalFieldB8PointerState1A - 0x2C);
                return;
            }
            goto block_154;
        case 32:
            globalFieldB8PointerState20 = &Physics21Player0View1 + 0xB8;
            if (Physics21Field(&Physics21Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp48;
                Physics21ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics21SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp50 = 0;
                temp_v0_6 = Physics21MeasureVectorLengthView1(&originalFrame.sp48, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics21ScaleVectorRatioQ15View1(&originalFrame.sp48, temp_v0_6, 0x40);
                }
                originalFrame.sp50 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics21AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp48);
                Physics21CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics21ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics21ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            call5 = &Physics21Player94View1;
            MATCHING_KEEP(call5);
            workWord2 = Physics21Field(call5, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
                Physics21Field(call5, int*, 0) = workWord2;
            }
            if ((Physics21Field(&Physics21Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics21Data6C640View1 & 1)) {
                originalFrame.sp58 = 0;
                originalFrame.sp5C = 0;
                originalFrame.sp60 = 0xE;
                Physics21CopyVectorView1(&originalFrame.sp68, call5 - 148);
                originalFrame.sp68 += Physics21Call363DCView1(0, 0x12C);
                originalFrame.sp6C += Physics21Call363DCView1(0, 0x12C);
                originalFrame.sp70 += Physics21Call363DCView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp68, &originalFrame.sp58);
                Physics21Field(temp_v0_7, signed char*, 2) = 6;
                Physics21Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 38: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics21Call410F8View1(&originalFrame.sp58, &Physics21Player14CView1, 0);
            workWord3 = Physics21Player60View1;
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
            call4 = &Physics21Player64View1;
            workWord2 = Physics21Field(call4, int*, 0);
            workWord3 = Physics21Player60View1;
            workWord2 += (int)globalVector80;
            workWord2 &= 4095;
            workWord3 += numeric5;
            workWord3 &= 4095;
            Physics21Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics21Player60View1 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics21Player60View1 = workWord2;
            }
            workWord2 = Physics21Data6E538View1;
            workWord3 = 6144;
            Physics21PlayerACView1 = workWord3;
            workWord2 &= 192;
            if (workWord2) {
                workWord2 = 12800;
                Physics21PlayerACView1 = workWord2;
            }
            workWord3 = Physics21Player4CView1;
            workWord2 = 2;
            if (workWord3 == workWord2) {
                Physics21Call417FCView1(320, 192);
                workWord2 = Physics21PlayerB0View1 < 6145;
                if (workWord2)
                    Physics21Player4CView1 = 0;
            } else
                Physics21Call417FCView1(320, 80);
            globalFieldA4Pointer = &Physics21Player60View1;
            MATCHING_KEEP(globalFieldA4Pointer);
            workWord2 =
                Physics21InterpolateCosineView1(Physics21Field(globalFieldA4Pointer, int*, 0));
            workWord2 <<= 5;
            workWord2 = -workWord2;
            lowProduct5 = (int)globalVector80 * workWord2;
            workWord3 = Physics21Player14CView1;
            numeric5 = Physics21Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = lowProduct5 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics21Player14CView1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics21Player5CView1 = numeric5;
            if (!workWord2) {
                workWord2 = numeric5 - 4096;
                Physics21Player5CView1 = workWord2;
            }
            workWord2 = Physics21Player5CView1;
            workWord2 = workWord2 < -768;
            if (workWord2) {
                workWord2 = -768;
                Physics21Player5CView1 = workWord2;
            }
            workWord2 = Physics21Player5CView1;
            workWord2 = workWord2 < 769;
            if (!workWord2) {
                workWord2 = 768;
                Physics21Player5CView1 = workWord2;
            }
            Physics21Call41848View1(numeric4, numeric5);
            goto block_188;
        }
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics21Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics21Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp60;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics21Call410F8View2(call4, call5, 0);
            workWord3 = Physics21Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics21Player60View1;
                numeric4 = Physics21Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric4 << 4;
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
                workWord2 = originalFrame.sp64;
                workWord3 = numeric4 + 1;
                Physics21Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.sp64 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics21Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.sp60 * 0x14) >> 7;
            Physics21Field(&Physics21Player0View3, int*, 0x64) =
                (int)((Physics21Field(&Physics21Player0View3, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics21Field(&Physics21Player0View3, int*, 0x60) +
                               ((int)(originalFrame.sp64 * -0xF) >> 7)) &
                              0xFFF;
            Physics21Field(&Physics21Player0View3, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics21Field(&Physics21Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x60) < -0x320) {
                Physics21Field(&Physics21Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x60) >= 0x321) {
                Physics21Field(&Physics21Player0View3, int*, 0x60) = 0x320;
            }
            if ((*Physics21Data6C570View2 & 0x40) ||
                (Physics21Field(&Physics21Player0View3, int*, 0x4C) == 1)) {
                Physics21Field(&Physics21Player0View3, int*, 0xAC) = 0xE00;
            } else {
                Physics21Field(&Physics21Player0View3, int*, 0xAC) = 0;
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x4C) == 2) {
                Physics21Call417FCView2(0xC0, 0xC0);
                if (Physics21Field(&Physics21Player0View3, int*, 0xB0) < 0xE01) {
                    Physics21Field(&Physics21Player0View3, int*, 0x4C) = 0;
                }
            } else {
                Physics21Call417FCView2(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics21Player0View3 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics21InterpolateCosineView2(
                                                Physics21Field(&Physics21Player0View3, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics21Field(&Physics21Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics21Field(&Physics21Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics21Field(&Physics21Player0View3, int*, 0x14C) + raw21_temp_a0_5;
            Physics21Field(&Physics21Player0View3, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics21Field(&Physics21Player0View3, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics21Field(&Physics21Player0View3, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics21Field(&Physics21Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x5C) < -0x300) {
                Physics21Field(&Physics21Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x5C) >= 0x301) {
                Physics21Field(&Physics21Player0View3, int*, 0x5C) = 0x300;
            }
            Physics21Call41848View2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics21CopyVectorView3(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics21CallRandView1() & 31;
            if (workWord2)
                goto block_130;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto block_130;
            call5 = (void*)44;
            call6 = &originalFrame.sp78;
            particleArg7 = 0;
            MATCHING_KEEP(particleArg7);
            workWord2 = 544;
            originalFrame.sp78 = workWord2;
            workWord2 = 64;
            originalFrame.sp7C = 0;
            __asm__ volatile("" ::"i"(0x8008BF4C) : "memory");
            originalFrame.sp80 = workWord2;
            goto block_129;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics21Player0View3 + 0x20C;
            if (!(Physics21Field(&Physics21Player0View3, int*, 0x20C) & 0x40)) {
                if (Physics21Data6E044View2 != 7) {
                    Physics21Call410F8View2(&originalFrame.sp68, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.sp68;
                    numeric4 = originalFrame.sp6C;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics21Player64View1;
                    workWord2 = Physics21Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics21Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics21Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics21Player60View1 = workWord2;
                    }
                    if (Physics21Field(&Physics21Player0View3, int*, 0x60) < -0x320) {
                        Physics21Field(&Physics21Player0View3, int*, 0x60) = -0x320;
                    }
                    if (Physics21Field(&Physics21Player0View3, int*, 0x60) >= 0x321) {
                        Physics21Field(&Physics21Player0View3, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics21InterpolateCosineView2(Physics21Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics21Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics21Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics21Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics21Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics21Player5CView1 = workWord2;
                    }
                    if (Physics21Field(&Physics21Player0View3, int*, 0x5C) < -0x300) {
                        Physics21Field(&Physics21Player0View3, int*, 0x5C) = -0x300;
                    }
                    if (Physics21Field(&Physics21Player0View3, int*, 0x5C) >= 0x301) {
                        Physics21Field(&Physics21Player0View3, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics21Player0View3 + 0x80;
                Physics21ClearVectorView3(raw21_temp_s0_9);
                Physics21ClearVectorView3(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics21CallRandView1() & 31;
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
                globalPointer = &Physics21Player158View1;
                workWord2 = Physics21Field(globalPointer, int*, 0);
                workWord2++;
                Physics21Field(globalPointer, int*, 0) = workWord2;
                return;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics21Player20CView1;
            MATCHING_KEEP(call5);
            workWord2 = Physics21Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp70;
            if (!workWord2)
                goto run42;
        block_132:
            Physics21PlayerACView1 = 0;
            Physics21PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics21Call410F8View2(call4, call5, 0);
            workWord3 = Physics21Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics21Player60View1;
                numeric5 = Physics21Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.sp74 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.sp74 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.sp74;
                workWord3 = numeric5 + 1;
                Physics21Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.sp74 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics21Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics21Player0View3 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.sp70 * 0x14) >> 7;
            Physics21Field(&Physics21Player0View3, int*, 0x64) =
                (int)((Physics21Field(&Physics21Player0View3, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics21Field(&Physics21Player0View3, int*, 0x60) +
                                ((int)(originalFrame.sp74 * -0xF) >> 7)) &
                               0xFFF;
            Physics21Field(&Physics21Player0View3, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics21Field(&Physics21Player0View3, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x60) < -0x320) {
                Physics21Field(&Physics21Player0View3, int*, 0x60) = -0x320;
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x60) >= 0x321) {
                Physics21Field(&Physics21Player0View3, int*, 0x60) = 0x320;
            }
            Physics21Field(&Physics21Player0View3, int*, 0xAC) = 0x1C00;
            Physics21Call417FCView2(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics21InterpolateCosineView2(
                                                 Physics21Field(&Physics21Player0View3, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics21Field(&Physics21Player0View3, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics21Field(&Physics21Player0View3, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics21Field(&Physics21Player0View3, int*, 0x14C) + raw21_temp_a0_6;
            Physics21Field(&Physics21Player0View3, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics21Field(&Physics21Player0View3, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics21Field(&Physics21Player0View3, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics21Field(&Physics21Player0View3, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x5C) < -0x300) {
                Physics21Field(&Physics21Player0View3, int*, 0x5C) = -0x300;
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x5C) >= 0x301) {
                Physics21Field(&Physics21Player0View3, int*, 0x5C) = 0x300;
            }
            Physics21Call41848View2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics21CopyVectorView3(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics21Field(&Physics21Player0View3, int*, 0xB4) >= 0x7D1)) {
                originalFrame.sp88 = -0x190;
                originalFrame.sp8C = 0x40 - (Physics21CallRandView1() & 0x7F);
                originalFrame.sp90 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp88, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics21Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics21Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            call4 = &Physics21Player80View1;
            MATCHING_KEEP(call4);
            Physics21ClearVectorView3(call4);
            call4 = &Physics21Player8CView1;
            MATCHING_KEEP(call4);
            Physics21ClearVectorView3(call4);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics21Data6E044View2;
            if (workWord3 == workWord2) {
                Physics21Field(&Physics21Player0View3, int*, 0xB0) = 0;
            } else {
                Physics21Call40D10View2(0x980);
                raw21_var_v0_2 = Physics21Call41580View2(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics21Field(&Physics21Player0View3, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics21Field(&Physics21Player0View3, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics21Call417FCView2(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics21Player0View3 + 0xB0;
            if (Physics21Field(&Physics21Player0View3, int*, 0xB0) != 0) {
                Physics21Call41848View2();
                Physics21Call41B64View2();
                Physics21Field(&Physics21Player0View3, int*, 0x94) = 0;
            } else {
                Physics21ClearVectorView3(raw21_temp_s0_11 - 0x30);
                Physics21ClearVectorView3(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics21Player0View3 + 0x28;
                if (Physics21Field(&Physics21Player0View3, int*, 0x28) < 0) {
                    if ((Physics21Field(&Physics21Player0View3, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics21Data6C640View2 & 1)) {
                        Physics21CopyVectorView3(&originalFrame.sp88, raw21_temp_s4 - 0x28);
                        originalFrame.sp9C = 0x40;
                        originalFrame.spA0 = 0;
                        originalFrame.sp98 =
                            (int)Physics21Field(&Physics21Player0View3, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp9C = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics21TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp98,
                                                             &originalFrame.spA8);
                        Physics21AddVectorView4(&originalFrame.sp88, &originalFrame.sp88,
                                                &originalFrame.spA8);
                        originalFrame.sp98 = 0;
                        originalFrame.sp90 = -Physics21Field(&Physics21Player0View3, int*, 0x28);
                        Physics21TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp98,
                                                             &originalFrame.sp98);
                        Physics21ShiftVectorRightTowardZeroView1(&originalFrame.sp98, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp88, &originalFrame.sp98);
                        if (!(Physics21CallRandView1() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp88, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics21Player0View3 + 0xB0;
                        if ((Physics21Field(&Physics21Player0View3, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics21Data6C640View2 & 7) &&
                            !(Physics21CallRandView1() & 3)) {
                            originalFrame.spB8 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.spBC = 0;
                            originalFrame.spC0 = 0;
                            Physics21TransformVectorByBasisView1(
                                raw21_temp_s1_7 - 0x80, &originalFrame.spB8, &originalFrame.spB8);
                            Physics21AddVectorView4(&originalFrame.spB8, &originalFrame.spB8,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.spC0 =
                                -Physics21Field(&Physics21Player0View3, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.spB8, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics21Field(&Physics21Player0View3, int*, 0x144) -
                ((int)((Physics21Field(&Physics21Player0View3, int*, 0x148) * 2) +
                       (Physics21Field(&Physics21Player0View3, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics21Field(&Physics21Player0View3, int*, 0x148) + raw21_temp_a1_4;
            Physics21Field(&Physics21Player0View3, int*, 0x144) = raw21_temp_a1_4;
            Physics21Field(&Physics21Player0View3, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics21Field(&Physics21Player0View3, int*, 0x148) = 0x5900;
            }
            if (Physics21Field(&Physics21Player0View3, int*, 0x148) < -0x5900) {
                Physics21Field(&Physics21Player0View3, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 0x39:
            if ((workWord2 = combinedIndex < 9) == 0) {
                Physics21Field(&Physics21Player0View3, int*, 0x80) =
                    (int)(Physics21Field(&Physics21Player0View3, int*, 0x8C) * 0xF8);
                Physics21Field(&Physics21Player0View3, int*, 0x84) =
                    (int)(Physics21Field(&Physics21Player0View3, int*, 0x90) * 0xF8);
                Physics21Field(&Physics21Player0View3, int*, 0x88) =
                    (int)(Physics21Field(&Physics21Player0View3, int*, 0x94) * 0xF8);
                Physics21ShiftVectorRightTowardZeroView1(&Physics21Player0View3 + 0x80, 8);
            }
        block_188:
            call4 = &Physics21Player8CView1;
            call5 = &Physics21Player80View1;
            MATCHING_KEEP2(call4, call5);
            Physics21CopyVectorView3(call4, call5);
            return;
        case 61:
            Physics21Call40F48View1(&originalFrame.spA8, 1);
            workWord3 = originalFrame.spA8;
            workWord2 = workWord3 * 25;
            call4 = (void*)(workWord2 >> 7);
            if (call4)
                goto nonzero61;
            MATCHING_BARRIER_VOLATILE("$4");
            Physics21PlayerA8View1 = 0;
            goto approach61;
        nonzero61:
            if ((int)call4 >= 0)
                goto positive61;
            globalPointer = &Physics21PlayerA8View1;
            workWord2 = Physics21Field(globalPointer, int*, 0);
            if (workWord2 > 0)
                Physics21Field(globalPointer, int*, 0) = 0;
            goto approach61;
        positive61:
            globalPointer = &Physics21PlayerA8View1;
            workWord2 = Physics21Field(globalPointer, int*, 0);
            if (workWord2 < 0)
                Physics21Field(globalPointer, int*, 0) = 0;
        approach61:
            call5 = &Physics21PlayerA8View1;
            workWord3 = Physics21Field(call5, int*, 0);
            workWord2 = workWord3 < (int)call4;
            if (workWord2) {
                workWord2 = workWord3 + 3;
                Physics21Field(call5, int*, 0) = workWord2;
                workWord2 = (int)call4 < workWord2;
                goto clamp61;
            }
            workWord2 = workWord3 - 3;
            Physics21Field(call5, int*, 0) = workWord2;
            workWord2 = workWord2 < (int)call4;
        clamp61:
            if (workWord2)
                Physics21Field(call5, int*, 0) = (int)call4;
            call4 = (void*)Physics21PlayerA8View1;
            Physics21Call41404View1(call4);
            workWord3 = Physics21Player60View1;
            workWord2 = workWord3 < 2049;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics21Player60View1 = workWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                workWord3 = Physics21Player60View1;
            }
            if (workWord3 >= 0)
                goto nonnegative61;
            call4 = (void*)Physics21Data67640View1;
            workWord2 = Physics21Data6763CView1;
            workWord2 = (int)call4 - workWord2;
            goto quotient61;
        nonnegative61:
            if (workWord3 <= 0)
                goto zero61;
            workWord2 = Physics21Data67644View1;
            call4 = (void*)Physics21Data67640View1;
            workWord2 -= (int)call4;
        quotient61:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 352;
            call4 += workWord3;
            Physics21PlayerACView1 = (int)call4;
            goto update61;
        zero61:
            workWord2 = Physics21Data67640View1;
            Physics21PlayerACView1 = workWord2;
        update61:
            Physics21Call417FCView1(576, 384);
            Physics21Call41848View1();
            call6 = &Physics21PlayerFCView1;
            workWord2 = Physics21Field(call6, unsigned char*, 0);
            if (workWord2)
                goto field94FromA0;
            workWord2 = Physics21PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vectorCommit61;
        field94FromA0:
            workWord2 = Physics21PlayerA0View1;
            workWord2 -= 192;
            Physics21Player94View1 = workWord2;
            return;
        vectorCommit61:
            call5 = call6 - 124;
            Physics21AddVectorView2(call4, call5, call6 - 20);
            return;
    }
}
#undef Physics21Field


/* AI generated; not human reviewed. SCUS-94467 8008CA58..8008CF7C.
 * Verified20/37 independent table paths; original21 supplies selector scope,
 * case19 and3D callback/flag/table producers. Meanings/units/cadence unresolved.
 * Callbackkind1/subtype9, globals8006E530=120 and8006E52C=4,
 * and descriptor source8006C654 retain original widths and call order.
 * Their numeric equality does not establish audio/event or runtime semantics.
 * Every original word, strict full TU and all retail hashes required.
 */
extern Spyro Callback21Player __asm__("D_80070328");
int Callback21Call80037058(int x, int y) __asm__("func_80037058");
int Callback21Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback21Call80041930(void) __asm__("func_80041930");
void Callback21Call80041AE8(void) __asm__("func_80041AE8");
void Callback21Call80041C20(void) __asm__("func_80041C20");
void Callback21Call80042A44(void) __asm__("func_80042A44");
void Callback21Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38, D_8006C648;
extern int Callback21Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback21Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback21Values[] __asm__("D_8006FCF0");
void Callback21Call80049590(void) __asm__("func_80049590");
extern int Callback21Word8006E344 __asm__("D_8006E344");
extern int Callback21Word8006E52C __asm__("D_8006E52C");
extern int Callback21Word8006E530 __asm__("D_8006E530");
extern int Callback21Word8006E538 __asm__("D_8006E538");
void func_level_21_8008CA58(void) {
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

    switch (Callback21Player.animationState) {
        case 0x14:
            if (func_800438F4() == 0)
                func_80043728();
            Callback21Call80041C20();
            Callback21Player.unk9a = 0;
            goto call42A44;
        case 0x20:
            Callback21Call80041C20();
        call42A44:
            Callback21Call80042A44();
        clearSharedValue:
            Callback21Player.unk4[0] = 0;
            return;
        case 0xA:
        case 0xB:
        case 0xC:
            func_800438F4();
            Callback21Call80041C20();
            Callback21Call80042A44();
            Callback21Call80041930();
            goto queryC00;
        case 0x13:
            Callback21Call80041C20();
            Callback21Call80042A44();
            Callback21Call80041930();
            goto clearSharedValue;
        case 0x19:
            Callback21Call80041C20();
            Callback21Call80042A44();
            Callback21Call80041930();
            Callback21Call80049590();
            if (Callback21Player.movementState == MOVEMENT_STATE_SUPERCHARGE && SpawnParticle != 0)
                SpawnParticle(1, 9, 0, 0);
            if (Callback21Player.unk7a[3].z < 0 && Callback21Player.animationStateFrames >= 4)
                Callback21Player.unk5 = 1;
            else if (Callback21Player.unk5 == 0 && !(Callback21Word8006E538 & 0x40))
                Callback21Player.unk5 = 2;
            goto clearSharedValue;
        case 0x1A:
        case 0x1D:
            Callback21Call80041C20();
            Callback21Call80042A44();
        queryC00:
            Callback21Call80043A38(0xC00);
            goto clearSharedValue;
        case 0x26:
        case 0x28:
        case 0x29:
        case 0x39:
            Callback21Call80041C20();
            Callback21Call80042A44();
            descriptor = &Callback21Player.unk22[2];
            if (Callback21Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback21Values + valueOffset);
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
                *(int*)(Callback21Values + valueOffset) = tableValue;
            setDecreasingFlag:
                flagOffset = *descriptor * 0x2C;
                Callback21Flags[flagOffset] = Callback21Flags[flagOffset] | 0x10;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            goto clearSharedValue;
        case 0x2A:
            Callback21Call80041C20();
            Callback21Call80042A44();
            Callback21Call80049590();
            descriptor = &Callback21Player.unk22[2];
            if (Callback21Call8003BF6C((int)D_8006C654->underwater, *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback21Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback21Player.unk22[2];
            }
            if (Callback21Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback21Values + valueOffset);
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
                *(int*)(Callback21Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback21Flags[flagOffset] = Callback21Flags[flagOffset] | 0x10;
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback21Call80041C20();
            Callback21Call80042A44();
            Callback21Call80041AE8();
            if ((unsigned char)Callback21Player.unk10[4] != 0) {
                computedValue = -Callback21Player.unk9ha[4] -
                                Callback21Call80037058(Callback21Player.position.x,
                                                       Callback21Player.position.y);
                positionValue = Callback21Player.unk4a - computedValue;
                Callback21Player.unk4[0] = computedValue;
                positionDelta = (int)Callback21Player.union144.a.unk13cc >> 6;
                goto storePosition;
            }
            break;
        storePosition:
            positionValue -= positionDelta;
            MATCHING_KEEP(positionValue);
            Callback21Player.position.z = positionValue;
            return;
        case 0x3D:
            Callback21Call80041C20();
            Callback21Call80042A44();
            Callback21Call80043A38(0xC00);
            Callback21Call80049590();
            if (SpawnParticle != 0)
                SpawnParticle(1, 9, 0, 0);
            Callback21Word8006E530 = 120;
            Callback21Player.unk4[0] = 0;
            Callback21Word8006E52C = 4;
            if (Callback21Word8006E344 == 0 &&
                Callback21Call8003BF6C((int)D_8006C654->supercharge, Callback21Player.unk22[2]) ==
                    0) {
                Callback21Player.unk22[2] = PlaySound((int)D_8006C654->supercharge, 0, 4);
                Callback21Player.unk22[3] = (int)D_8006C654->supercharge;
            }
            break;
        default:
            return;
    }
}


#define LEVEL_ID 21
#define PlaySpyroSounds_level_21 func_level_21_8008CF80
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_21_8008D100(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0xa:
        case 0xb:
        case 0xc:
        case 0x14:
        case 0x1a:
        case 0x1d:
        case 0x20:
        case 0x2b:
        case 0x2c:
        case 0x3d:
            func_80043ABC(&spyro.unk9e);
            break;
        case 0x13:
            func_80043ABC(0);
            break;
        case 0x19:
            func_80043E00((Vector3D*)((char*)&spyro + 0x8C));
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008D198.
 * Reuses verified41 underwater/surface stack vectors, private0/4/8 swirl,
 * numeric21C/220/224 hurt, squish and signed-table producers. Original21 adds
 * selectorsA/B/C state10,19 state9/word130=60000,26 stateB/helper14C/98/word44=280,
 * and3D state9/vector98/wordAC=1E80/170,1FC,200 flags plus helper47138.
 * Shared descriptor call remains at the first hurt route; shared244/250 clears
 * follow3D. Numeric offsets are bytes, widths/shifts/branches are source-native.
 * Word60 FFF/801/1000 wrap/clamp inputs800/801/FFF yield0/-7FF/-1 before helpers.
 * Empty constraints emit no opcodes and retain original source lifetimes.
 * Every code/local jump/owned table word, strict complete TU and complete
 * EXE/every overlay hashes are required. Units, helper/audio meanings, caller
 * cadence and live runtime parity are open; execution is once per invocation.
 */
extern Spyro Transition21_D_80070328 __asm__("D_80070328");
int Transition21MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition21ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition21_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition21RawUnion[] __asm__("D_80070328+0x144");
extern int Transition21RawMovement __asm__("D_80070328+0x50");
extern void (*Call21Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw21State[] __asm__("D_80070328+0x50");
extern short Signed21TableA[] __asm__("D_800658A0");
extern short Signed21TableB[] __asm__("D_80065920");

extern int D_80071934;
int Call21A358(Vector3D*, int) __asm__("func_8001A358");
extern int Raw21NegativeWord __asm__("D_80070328+0x28");
extern int Raw21TableIndex __asm__("D_80070328+0x298");
extern int Raw21Yaw __asm__("D_80070328+0x64");
int Transition21RandBetween(int, int) __asm__("func_8003636C");
void Transition21_func_800441F0(void) __asm__("func_800441F0");
void Transition21_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_21_8008D198(int arg0) {
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
    register int oldMovementC __asm__("$5");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    switch (arg0) {
        case 0x14:
            Transition21_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition21_D_80070328.unk5 = 0;
            Transition21_func_800441F0();
            Transition21_D_80070328.grounded = 1;
            Transition21_D_80070328.union144.a.unk13cb = Transition21RandBetween(1, 3);
            Transition21_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0xA:
        case 0xB:
        case 0xC:
            Transition21_D_80070328.movementState = MOVEMENT_STATE_ICE_SKATE;
            Transition21_D_80070328.unk5 = 0;
            Transition21_D_80070328.unk8[0] = Transition21MeasureVectorLength(
                (Vector3D*)((unsigned char*)&Transition21_D_80070328.movementState + 0x48), 0);
            Transition21_func_80043A38(0xC00);
            Transition21_D_80070328.grounded = 1;
            goto clearPointers;
        case 0x13: {
            register Moby* sourceMoby __asm__("$6");
            register int yawValue __asm__("$5");
            register int positionZ __asm__("$2");
            register int heightValue __asm__("$3");
            register int privateValue __asm__("$4");
            stateBase = (unsigned char*)&Transition21RawMovement;
            privateData = Transition21_D_80070328.m_WhirlwindPointer->mobyTag;
            *(int*)stateBase = 14;
            Transition21_D_80070328.unk5 = 0;
            Transition21_D_80070328.grounded = 0;
            Transition21ClearVector((Vector3D*)(stateBase + 0x3C));
            sourceMoby = Transition21_D_80070328.m_WhirlwindPointer;
            yawValue = Transition21_D_80070328.rotation.yaw;
            positionZ = Transition21_D_80070328.position.z;
            heightValue = sourceMoby->position.z;
            privateValue = *(int*)privateData;
            MATCHING_KEEP4(sourceMoby, yawValue, positionZ, heightValue);
            Transition21_D_80070328.union144.a.unk13cc = yawValue;
            Transition21_D_80070328.union144.a.unk13cb = positionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue += privateValue;
            Transition21_D_80070328.union144.a.unk13ce.x = heightValue;
            heightValue -= positionZ;
            heightValue -= 0x800;
            Transition21_D_80070328.union144.a.unk13ce.z = heightValue;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue = ((int)(heightValue << 0xA) >> 0xA) + 0x400;
            MATCHING_KEEP(heightValue);
            Transition21_D_80070328.union144.a.unk13ce.y = heightValue;
            maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
            Transition21_D_80070328.union144.a.unk13ce.y = maskedValue;
            if (maskedValue >= 0x801) {
                Transition21_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
            }
            Transition21_D_80070328.union144.a.unk13da = *(int*)(privateData + 4);
            func_8004F178((Vector3D*)(stateBase + 0x10C), &sourceMoby->position);
            Transition21_D_80070328.unk13e[0] =
                (int)Transition21_D_80070328.m_WhirlwindPointer->angle.yaw;
            positionZ = *(int*)(privateData + 8);
            MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
            Transition21_D_80070328.unk20a = 0;
            Transition21_D_80070328.critterMobyPtr = 0;
            Transition21_D_80070328.unk13e[1] = positionZ;
            return;
        }
        case 0x1D: {
            register int oldState __asm__("$4") = Transition21RawMovement;
            register int first __asm__("$3") = Transition21_D_80070328.unk17e.x;
            register int second __asm__("$2");
            register int third __asm__("$3");
            MATCHING_KEEP2_CLOBBER(oldState, first, "memory");
            second = 7;
            MATCHING_KEEP(second);
            Transition21RawMovement = second;
            MATCHING_BARRIER_VOLATILE("memory");
            second = Transition21_D_80070328.unk17e.y;
            MATCHING_KEEP_VOLATILE_CLOBBER(second, "memory");
            Transition21_D_80070328.unk5 = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(first, "memory");
            first <<= 6;
            MATCHING_KEEP(first);
            Transition21_D_80070328.unk7a[2].x = first;
            MATCHING_BARRIER_VOLATILE("memory");
            third = Transition21_D_80070328.unk17e.z;
            second <<= 6;
            Transition21_D_80070328.union144.a.unk13cb = oldState;
            Transition21_D_80070328.unk7a[2].y = second;
            second = third << 6;
            if (third == 0)
                second = Transition21_D_80070328.unk7a[3].z;
            Transition21_D_80070328.unk7a[2].z = second;
            Transition21_func_80043A38(0xC00);
            Transition21_D_80070328.grounded = 1;
            Transition21_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            soundSelector = D_8006C654->spyroHurt;
            soundZero = 0;
        sharedSound:
            PlaySound(soundSelector, (Moby*)soundZero, 0);
            goto clearPointers;
        }

        case 0x19:
            Transition21_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
            Transition21_D_80070328.unk13a[0] = 0x60000;
            Transition21_D_80070328.unk5 = 0;
            Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition21_D_80070328.grounded = 0;
            Transition21_D_80070328.unk15b = 1;
            soundSelector = D_8006C654->jump;
            soundZero = 0;
            goto sharedSound;
        case 0x1A:
            savedBase = Transition21RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            oldMovementC = Transition21RawMovement;
            Transition21RawMovement = MOVEMENT_STATE_HURT;
            Transition21_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementC;
            Transition21ClearVector(destination);
            Transition21_D_80070328.grounded = 1;
            Transition21_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            soundSelector = D_8006C654->squish;
            soundZero = 0;
            goto sharedSound;
        case 0x20:
            Transition21_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition21_D_80070328.unk5 = 0;
            Transition21_func_80043A38(0xC00);
            Transition21_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition21_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x26:
            Transition21_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            if (Transition21_D_80070328.animationState == 0x2A) {
                Transition21_D_80070328.unk5 = 2;
            }
            Transition21ClearVector(
                (Vector3D*)((unsigned char*)&Transition21_D_80070328.movementState + 0xFC));
            Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition21_D_80070328.unk8[0] = Transition21MeasureVectorLength(
                (Vector3D*)((unsigned char*)&Transition21_D_80070328.movementState + 0x48), 0);
            Transition21_D_80070328.grounded = 1;
            Transition21_D_80070328.unk4a = 0x280;
            return;
        case 0x28:
        case 0x29:
            if (((unsigned)(Transition21_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition21_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition21_D_80070328.movementState - 0x50));
                    if ((Transition21_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw21NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition21_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call21A358(&vectors.first, 0x800);
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
                firstWrappedWord = Transition21_D_80070328.rotation.pitch & 0xFFF;
                Transition21_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition21_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition21_D_80070328.rotation.pitch > 0) {
                    Transition21_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition21_D_80070328.unk5 = 1;
                }
                Transition21ClearVector(
                    (Vector3D*)((unsigned char*)&Transition21_D_80070328.rotation.pitch + 0xEC));
                Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition21_D_80070328.unk8[0] = Transition21MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition21_D_80070328.rotation.pitch + 0x38), 0);
                Transition21_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition21_D_80070328.animationState == 0x2A) {
                Transition21_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition21_D_80070328.union144.a.unk13da = 0;
            }
            Transition21_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition21_D_80070328.unk20a = 0;
            Transition21_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw21State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw21NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition21_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call21A358(localVector, 0x800);
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
                if (Transition21_D_80070328.animationState == 0x2E) {
                    Transition21_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition21_D_80070328.rotation.pitch & 0xFFF;
                Transition21_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition21_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition21_D_80070328.rotation.pitch > 0) {
                    Transition21_D_80070328.rotation.pitch = 0;
                }
                Transition21_D_80070328.unk5 = 1;
                Transition21ClearVector(
                    (Vector3D*)((unsigned char*)&Transition21_D_80070328.animationState + 0x104));
                Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition21_D_80070328.unk8[0] = Transition21MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition21_D_80070328.animationState + 0x50), 0);
                Transition21_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition21_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition21_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition21RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition21RawUnion;
                    *(int*)unionPointer = (-Transition21_D_80070328.unk7a[2].z) >> 2;
                    if (Transition21RawMovement != 8) {
                        Transition21_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition21RawMovement = 10;
                    }
                    Transition21_D_80070328.unk5 = 0;
                    Transition21_D_80070328.unk8[0] =
                        Transition21MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition21_D_80070328.grounded = 1;
                    Transition21_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call21A358(localVector, 0x800);
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
            register int previousMovement __asm__("$2") = Transition21RawMovement;
            register int numericKind __asm__("$3");
            register int indexWord __asm__("$3");
            register unsigned char* unionPointer __asm__("$5");
            register int tableOffset __asm__("$2");
            register int tableWord __asm__("$3");
            MATCHING_KEEP(previousMovement);
            numericKind = 7;
            MATCHING_KEEP(numericKind);
            Transition21RawMovement = numericKind;
            MATCHING_BARRIER_VOLATILE("memory");
            indexWord = Raw21TableIndex;
            MATCHING_KEEP_VOLATILE_CLOBBER(indexWord, "memory");
            unionPointer = Transition21RawUnion;
            MATCHING_KEEP2_CLOBBER(indexWord, unionPointer, "memory");
            Transition21_D_80070328.unk5 = 0;
            *(int*)unionPointer = previousMovement;
            if (indexWord < 0)
                Raw21TableIndex = ((Raw21Yaw + 0x800) >> 4) & 0xFF;
            tableOffset = Raw21TableIndex * 2;
            tableWord = *(short*)((unsigned char*)Signed21TableB + tableOffset);
            destination = (Vector3D*)(unionPointer - 0xC4);
            *(int*)(unionPointer - 0xB8) = tableWord;
            tableOffset = *(short*)((unsigned char*)Signed21TableA + tableOffset);
            Transition21_D_80070328.unk7a[2].z = 0;
            Transition21_D_80070328.unk7a[2].y = tableOffset;
            func_8004F178(destination, (Vector3D*)(unionPointer - 0xB8));
            Transition21_D_80070328.grounded = 1;
            Transition21_D_8006E524 = 15;
            if (SpawnParticle)
                SpawnParticle(5, 10, 0, 0);
            soundSelector = D_8006C654->underwaterHit;
            soundZero = 0;
            goto sharedSound;
        }
        case 0x3D:
            Transition21_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
            Transition21_D_80070328.unk5 = 0;
            Transition21_D_80070328.unk13a[0] = 0x60000;
            Transition21_D_80070328.unk8[0] = Transition21MeasureVectorLength(
                (Vector3D*)((unsigned char*)&Transition21_D_80070328.movementState + 0x48), 0);
            Transition21_D_80070328.horizontalSpeed = 0x1E80;
            Transition21_func_80043A38(0xC00);
            Transition21_D_80070328.grounded = 1;
            if ((Transition21_D_80070328.unk13f[0] != 0) ||
                (Transition21_D_80070328.spitState != 0) || (Transition21_D_80070328.unk17t != 6)) {
                if (((unsigned)(Transition21_D_80070328.unk13f[0] - 3) < 2U) ||
                    (Transition21_D_80070328.unk13f[0] == 5)) {
                    Transition21_D_80070328.unk13f[0] = 5;
                } else {
                    Transition21_D_80070328.unk13f[0] = 0;
                }
                Transition21_D_80070328.spitState = 0;
                Transition21_D_80070328.unk17t = 6;
                func_80047138();
            }
        clearPointers:
            Transition21_D_80070328.unk20a = 0;
            Transition21_D_80070328.critterMobyPtr = 0;
            return;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level21
 * 8008DCD4: original813 instructions and52 dispatch words in sibling4833
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original21.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A21W48 __asm__("D_80070328 + 0x48");
extern int A21W4C __asm__("D_80070328 + 0x4C");
extern int A21W54 __asm__("D_80070328 + 0x54");
extern int A21WA0 __asm__("D_80070328 + 0xA0");
extern int A21WA8 __asm__("D_80070328 + 0xA8");
extern int A21WAC __asm__("D_80070328 + 0xAC");
extern int A21WB0 __asm__("D_80070328 + 0xB0");
extern int A21WB8 __asm__("D_80070328 + 0xB8");
extern int A21WCC __asm__("D_80070328 + 0xCC");
extern int A21WD0 __asm__("D_80070328 + 0xD0");
extern int A21WD4 __asm__("D_80070328 + 0xD4");
extern int A21W8C __asm__("D_80070328 + 0x8C");
extern int A21W90 __asm__("D_80070328 + 0x90");
extern int A21W94 __asm__("D_80070328 + 0x94");
extern int A21WE4 __asm__("D_80070328 + 0xE4");
extern int A21W144 __asm__("D_80070328 + 0x144");
extern int A21W158 __asm__("D_80070328 + 0x158");
extern int A21W1EC __asm__("D_80070328 + 0x1EC");
extern int A21W1F0 __asm__("D_80070328 + 0x1F0");
extern int A21W240 __asm__("D_80070328 + 0x240");
extern int A21W280 __asm__("D_80070328 + 0x280");
extern unsigned char A21B14 __asm__("D_80070328 + 0x14");
extern unsigned char A21B15 __asm__("D_80070328 + 0x15");
extern unsigned char A21B16 __asm__("D_80070328 + 0x16");
extern unsigned char A21B17 __asm__("D_80070328 + 0x17");
extern unsigned char A21B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A21BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A21B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A21B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A21Player[] __asm__("D_80070328");
extern unsigned char A21Table[] __asm__("D_80066530");
extern int A21Buttons __asm__("D_8006E538"), A21NewButtons __asm__("D_8006E53C");
extern int A21Mode __asm__("D_8006E044"), A21Gate __asm__("D_8006E344"),
    A21Count __asm__("D_8006C514");
extern int (*A21Callback)() __asm__("unk_ovlheader_80074374");
extern int A21W24 __asm__("D_80070328 + 0x24");
extern int A21W28C __asm__("D_80070328 + 0x28C");
extern int A21W290 __asm__("D_80070328 + 0x290");
extern int A21Surface __asm__("D_8006FA38");
extern unsigned char* A21SoundDesc __asm__("D_8006C654");
int A21Sound() __asm__("PlaySound");
int A21H40994() __asm__("func_80040994");
int A21H4BEF8() __asm__("func_8004BEF8");
int A21H49688() __asm__("func_80049688");
int A21ApproximatePlanarDistance() __asm__("func_8004F334");
int A21H498C0() __asm__("func_800498C0");
extern volatile int A21W20C __asm__("D_80070328 + 0x20C");
extern int A21W214 __asm__("D_80070328 + 0x214");
extern unsigned char A21B100 __asm__("D_80070328 + 0x100");
extern unsigned char A21E535 __asm__("D_8006E535");
extern unsigned char* A21Models __asm__("D_8006EE2C");
int A21H40BCC() __asm__("func_80040BCC");
int A21H1A310() __asm__("func_8001A310");
extern int A21W10C __asm__("D_80070328 + 0x10C");
extern int A21WB4 __asm__("D_80070328 + 0xB4");
extern int A21WA4 __asm__("D_80070328 + 0xA4");
extern int (*A21Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A21H40954() __asm__("func_80040954");
void func_level_21_8008DCD4(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register int* state __asm__("$16");
    switch (A21W48) {
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 21:
        case 22:
        case 23:
        case 24:
        case 27:
        case 28:
        case 30:
        case 31:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 39:
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
        case 58:
        case 59:
        case 60:
            return;
        case 20:
            if (A21H40994())
                return;
            work2 = A21NewButtons & 64;
            work4 = 6;
            if (work2)
                goto call;
            work2 = A21WB8 < 4;
            work4 = 7;
            if (!work2)
                goto call;
            if (A21WE4 >= 23)
                goto call;
            work3 = A21Buttons;
            work2 = work3 & 128;
            work4 = 13;
            if (work2)
                goto call;
            work2 = A21WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17) {
                work4 = 1;
                goto call;
            }
            work2 = work3 & 12;
            MATCHING_KEEP(work2);
            if (!work2) {
                work2 = A21WAC;
                work4 = 1;
                if (work2)
                    goto call;
            }
            if (A21Mode == 7 || A21W240) {
                state = &A21W48;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                A21H4BEF8(0);
                if (A21Table[*((unsigned char*)state - 0x2C)] >= 96) {
                    A21B14 = A21B15;
                    A21B16 = A21B17;
                }
                A21B17 = 0;
                work3 = *state;
                work2 = 113;
                *((unsigned char*)state - 0x2C) = work2;
                A21W1F0 = 0;
                A21B15 = work3;
                A21W1EC = work3;
                return;
            }
            work2 = A21BFC;
            work4 = 15;
            if (work2)
                goto call;
            A21H49688();
            return;
        case 10:
            if (A21H40994())
                return;
            work2 = A21WB8 < 4;
            work4 = 7;
            if (!work2)
                goto call;
            if (A21WE4 >= 23)
                goto call;
            work2 = A21H40954(A21W10C);
            work3 = 4;
            work4 = 1;
            if (work2 != work3)
                goto call;
            work3 = A21Mode;
            work2 = 7;
            if (work3 == work2)
                return;
            work2 = A21E535;
            work4 = 11;
            if (!work2)
                goto call;
            work2 = A21WB4 < 2305;
            work4 = 12;
            if (work2)
                return;
            goto call;
        case 11:
            if (A21H40994())
                return;
            work2 = A21WB8 < 4;
            work4 = 7;
            if (!work2)
                goto call;
            if (A21WE4 >= 23)
                goto call;
            work2 = A21H40954(A21W10C);
            work3 = 4;
            work4 = 1;
            if (work2 != work3)
                goto call;
            if (!A21E535)
                return;
            work2 = A21WB4 < 2305;
            work4 = 10;
            if (work2)
                goto call;
            work4 = 12;
            goto call;
        case 12:
            if (A21H40994())
                return;
            work2 = A21WB8 < 4;
            work4 = 7;
            if (!work2)
                goto call;
            if (A21WE4 >= 23)
                goto call;
            work2 = A21H40954(A21W10C);
            work3 = 4;
            work4 = 1;
            if (work2 != work3)
                goto call;
            work2 = A21E535;
            work4 = 11;
            if (!work2)
                goto call;
            work2 = A21WB4 < 1536;
            work4 = 10;
            if (!work2)
                return;
            goto call;
        case 29:
            if (A21W54 < 25)
                return;
            if (A21W280 < 0) {
                A21H4BEF8(31);
                return;
            }
            work2 = 10;
            work3 = A21W144;
            if (work3 == work2) {
                MATCHING_BARRIER_VOLATILE("memory");
                A21H4BEF8(44);
                return;
            }
            work2 = work3 - 11;
            if ((unsigned)work2 < 2) {
                MATCHING_BARRIER_VOLATILE("memory");
                A21H4BEF8(41);
                return;
            }
            work2 = A21WB8;
            work4 = 0;
            if (!work2)
                goto call;
            MATCHING_BARRIER_VOLATILE("memory");
            work4 = 7;
            goto call;
        case 19:
            if (A21H40994())
                return;
            work2 = 13;
            work3 = A21Gate;
            if (work3 == work2) {
                work2 = A21Count;
                work4 = 17;
                if (work2)
                    goto call;
            }
            work4 = (int)A21Player;
            work2 = A21ApproximatePlanarDistance((void*)work4, (void*)(work4 + 348));
            work3 = A21W158;
            work3 = work3 < work2;
            work4 = 17;
            if (!work3)
                return;
            goto call;
        case 25:
            if (A21H40BCC())
                return;
            if (A21B1B5 && (A21NewButtons & 64))
                A21B1B6 = 1;
            if (A21WE4 >= 23) {
                work3 = A21W8C;
                work2 = A21WCC;
                work4 = work3 * work2;
                work3 = A21W90;
                work2 = A21WD0;
                work3 = work3 * work2;
                work2 = work4 + work3;
                work4 = 14;
                if (work2 < 0)
                    goto call;
            }
            work3 = A21WB0;
            if (work3 >= 3201) {
                work2 = A21WB4 * 2;
                work2 = work2 < work3;
                work4 = 14;
                if (work2)
                    goto call;
            }
            if (!A21WB8) {
                work2 = A21W54 < 5;
                work4 = 61;
                if (!work2)
                    goto call;
            }
            if (A21B1B6) {
                work2 = A21W94;
                work4 = 17;
                if (work2 >= 0)
                    return;
                goto call;
            }
            work2 = A21W94;
            work4 = 22;
            if (work2 >= 0)
                return;
            goto call;
        case 26:
            if (A21W24 & 16)
                return;
            if (A21W54 < 25)
                return;
            if (A21W280 < 0) {
                A21H4BEF8(32);
                return;
            }
            A21Sound(A21SoundDesc[15], 0, 0);
            work3 = A21W144;
            work2 = 10;
            if (work3 == work2) {
                MATCHING_BARRIER_VOLATILE("memory");
                A21H4BEF8(44);
                return;
            }
            work2 = work3 - 11;
            if ((unsigned)work2 < 2) {
                MATCHING_BARRIER_VOLATILE("memory");
                A21H4BEF8(41);
                return;
            }
            work2 = A21WB8;
            work4 = 0;
            if (!work2)
                goto call;
            MATCHING_BARRIER_VOLATILE("memory");
            work4 = 7;
            goto call;
        case 32:
            if (A21W54 < 125)
                return;
        fallback32:
            A21H498C0();
            return;

        case 38: {
            register int (*callback2)(int) __asm__("$2");
            callback2 = A21Callback1;
            callback2(1);
            return;
        }
        case 40:
            if (A21H40994())
                return;
            if ((A21Buttons & 128) && A21W4C != 1) {
                work4 = 42;
                goto call;
            }
            if (A21WB0)
                return;
            work2 = A21W20C & 64;
            work4 = 41;
            if (!work2)
                goto call;
            if (A21W214 <= 0)
                return;
            goto call;
        case 41:
            if (A21H40994())
                return;
            work4 = A21Buttons;
            work2 = work4 & 128;
            if (work2) {
                work4 = 42;
                goto call;
            }
            work2 = 7;
            work3 = A21Mode;
            if (work3 == work2)
                return;
            work2 = work4 & 64;
            work4 = 40;
            if (work2)
                goto call;
            if (!(A21W20C & 64))
                return;
            if (!A21W214)
                goto call;
            return;
        case 42:
            if (A21H40BCC())
                return;
            if ((A21Buttons & 128) || A21W4C == 1)
                goto flag64;
            work2 = A21W20C & 128;
            work4 = 40;
            if (!work2)
                goto call;
        flag64:
            work2 = A21W20C & 64;
            work4 = 40;
            if (!work2)
                return;
            goto call;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (A21H40994())
                return;
            if ((A21NewButtons & 64) && A21W54 >= 9) {
                work4 = 6;
                goto partialCall;
            }
            byte4 = &A21B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                work4 = 7;
                goto partialCall;
            }
            if (!(A21NewButtons & 128))
                goto check44;
            if (A21W54 < 9)
                goto check44;
            work2 = *(int*)(A21Models + 220);
            byte4 -= 256;
            if (!work2)
                goto check44;
            work2 = A21H1A310(byte4, 1024, 1, 0);
            work4 = 40;
            if (work2)
                goto check44;
            goto call;
        partialCall:
            A21H4BEF8(work4);
        check44:
            work2 = A21E535;
            work4 = 44;
            if (!work2)
                return;
            goto call;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            work3 = A21W4C;
            work2 = 1;
            if (work3 != work2)
                goto other44;
            if (A21NewButtons & 0x850)
                goto callback44;
            if (A21W54 < 61)
                return;
        callback44:
            callback2 = A21Callback;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto fallback32;
        other44:
            if (A21H40994())
                return;
            if ((A21NewButtons & 64) && A21W54 >= 9) {
                work4 = 6;
                goto call;
            }
            byte4 = &A21B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                work4 = 7;
                goto call;
            }
            if (!(A21NewButtons & 128))
                goto mode44;
            if (A21W54 < 9)
                goto mode44;
            work2 = *(int*)(A21Models + 220);
            byte4 -= 256;
            if (!work2)
                goto mode44;
            work2 = A21H1A310(byte4, 1024, 1, 0);
            work4 = 40;
            if (!work2)
                goto call;
        mode44:
            work3 = A21Mode;
            work2 = 7;
            if (work3 == work2)
                return;
            work2 = A21E535;
            work4 = 43;
            if (work2)
                return;
            goto call;
        }
        case 57:
            if (A21W54 < 25)
                return;
            if (A21W280 < 0) {
                A21H4BEF8(31);
                return;
            }
            work2 = 10;
            work3 = A21W144;
            work4 = 41;
            if (work3 != work2)
                goto call;
            work4 = 44;
            goto call;
        case 61:
            if (A21H40BCC())
                return;
            work2 = 1;
            MATCHING_KEEP(work2);
            state = &A21W4C;
            MATCHING_KEEP(state);
            work3 = *state;
            if (work3 == work2) {
                if (A21WB8 >= 4)
                    goto partial25;
                work2 = A21H40954(A21W10C);
                work3 = 9;
                if (work2 == work3)
                    goto finalSpeed;
                *state = 0;
                goto finalSpeed;
            }
            if (A21Buttons & 64) {
            partial25:
                A21H4BEF8(25);
                work2 = A21WB8;
                work3 = 3520;
                A21W94 = work3;
                A21WB8 = work2 + 1;
                return;
            }
            work2 = A21WB8 < 4;
            work4 = 25;
            if (!work2)
                goto call;
            if (A21WE4 >= 23) {
                work3 = A21WCC;
                work2 = A21W8C;
                work4 = work3 * work2;
                work3 = A21WD0;
                work2 = A21W90;
                work3 = work3 * work2;
                work2 = work4 + work3;
                work4 = 7;
                if (work2 < 0)
                    goto call;
            }
            {
                register int* pointer4 __asm__("$4");
                pointer4 = &A21W4C;
                MATCHING_KEEP(pointer4);
                work3 = *pointer4;
                work2 = 2;
                if (work3 == work2 && A21W54 >= 16)
                    *pointer4 = 0;
            }
            if (A21Buttons & 128)
                goto finalSpeed;
            work2 = A21Surface;
            if (work2 >= 0)
                goto finalSpeed;
            work2 = 2;
            work3 = A21W4C;
            work4 = 3;
            if (work3 != work2)
                goto call;
        finalSpeed:
            work3 = A21WB0;
            work2 = work3 < 3201;
            if (work2)
                return;
            work2 = A21WB4 * 2;
            work2 = work2 < work3;
            work4 = 14;
            if (!work2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
        call:
            MATCHING_BARRIER_VOLATILE("memory");
            A21H4BEF8(work4);
            return;
    }
}
