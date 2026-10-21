#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800990E0.
 * Assembly SHA256 6b69c86c4f1ef38470a10c23b4240a3e5f63b2bcf25089574153a8552a6bb9b8.
 * AI-generated; not human reviewed. All1970 original instructions,
 * 114 selectors bias19 and original owned padding are required.
 * Frame0x128 preserves scratch10..10C and savedS0..S4. Original
 * incoming A0 is consumed by combinedS3 without an invented saved copy.
 * Sixteen exact physical groups reuse verified44/23/12/11 bodies with
 * explicit stack/address maps. Original33 omits the separate C7C4 scalar
 * modifier; original47 retains both jumps into124/129 clear30. All source
 * widths, callback131 placement, particle/scalar/vector arithmetic and
 * real shared branch targets remain original.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions. Frozen C tools emit words.
 * Raw field units/fixed point, helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, actual internal/conditional
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime completeness. */
#define Physics33Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics33Call363DCView1() __asm__("func_800363DC");
unsigned char Physics33Call40D10View1() __asm__("func_80040D10");
unsigned char Physics33Call41580View1() __asm__("func_80041580");
unsigned char Physics33Call416F4View1() __asm__("func_800416F4");
unsigned char Physics33Call417FCView1() __asm__("func_800417FC");
unsigned char Physics33Call41B64View1() __asm__("func_80041B64");
int Physics33InterpolateSineView1() __asm__("func_8004E9E4");
int Physics33InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics33TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics33MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics33ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics33ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics33CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics33AddVectorView1() __asm__("func_8004F194");
unsigned char Physics33SubtractVectorView1() __asm__("func_8004F1C8");
int Physics33CallRandView1() __asm__("rand");
extern unsigned char Physics33Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics33Data65920View1 __asm__("D_80065920");
extern void* Physics33Data6C570View1 __asm__("D_8006C570");
extern int Physics33Data6C640View1 __asm__("D_8006C640");
extern int Physics33Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics33Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics33Player0View1 __asm__("D_80070328");
extern int Physics33Player94View1 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics33Call40D10View2() __asm__("func_80040D10");
int Physics33Call40F48View1() __asm__("func_80040F48");
int Physics33Call41580View2() __asm__("func_80041580");
int Physics33Call416F4View2() __asm__("func_800416F4");
int Physics33Call417FCView2() __asm__("func_800417FC");
int Physics33Call41848View1() __asm__("func_80041848");
int Physics33Call41B64View2() __asm__("func_80041B64");
int Physics33InterpolateSineView2() __asm__("func_8004E9E4");
int Physics33InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics33MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics33ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics33ClearVectorView2() __asm__("func_8004F168");
int Physics33CopyVectorView2() __asm__("func_8004F178");
int Physics33AddVectorView2() __asm__("func_8004F194");
int Physics33SubtractVectorView2() __asm__("func_8004F1C8");
extern short Physics33Data6E040View1 __asm__("D_8006E040");
extern int Physics33Data6E044View2 __asm__("D_8006E044");
extern int Physics33Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics33Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics33PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics33Player94View2 __asm__("D_80070328+0x94");
extern int Physics33PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics33Player80View1 __asm__("D_80070328+0x80");
extern int Physics33PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics33Player64View1 __asm__("D_80070328+0x64");
extern int Physics33Player144View1 __asm__("D_80070328+0x144");
extern int Physics33PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics33Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics33PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics33PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics33Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics33Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics33Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics33Player101View1 __asm__("D_80070328+0x101");
extern int Physics33PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics33Call40F48View2() __asm__("func_80040F48");
int Physics33Call43194View1() __asm__("func_80043194");
int Physics33PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics33TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics33MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics33ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics33ClearVectorView3() __asm__("func_8004F168");
int Physics33CopyVectorView3() __asm__("func_8004F178");
int Physics33AddVectorView3() __asm__("func_8004F194");
int Physics33SubtractVectorView3() __asm__("func_8004F1C8");
extern unsigned char Physics33Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics33Data65920View2 __asm__("D_80065920");
extern int Physics33Data6C514View1 __asm__("D_8006C514");
extern int Physics33Data6E044View3 __asm__("D_8006E044");
extern int Physics33Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics33Player0View3 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics33Player16CView1 __asm__("D_80070328+0x16C");
int Physics33Call13E38View1() __asm__("func_80013E38");
int Physics33Call410F8View1() __asm__("func_800410F8");
int Physics33Call41848View2() __asm__("func_80041848");
int Physics33Call41B64View3() __asm__("func_80041B64");
int Physics33Call4E4E4View1() __asm__("func_8004E4E4");
int Physics33InterpolateCosineView3() __asm__("func_8004EA2C");
int Physics33AddVectorView4() __asm__("func_8004F194");
extern int Physics33Data67630View1 __asm__("D_80067630");
extern int Physics33Data67634View1 __asm__("D_80067634");
extern int Physics33Data67638View1 __asm__("D_80067638");
extern int Physics33Data6FA38View1 __asm__("D_8006FA38");
extern int Physics33Data71908View1 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics33Player130View1 __asm__("D_80070328+0x130");
extern int Physics33Player144View2 __asm__("D_80070328+0x144");
extern short Physics33Player148View1 __asm__("D_80070328+0x148");
extern short Physics33Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics33Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics33Player150View1 __asm__("D_80070328+0x150");
extern int Physics33Player154View1 __asm__("D_80070328+0x154");
extern int Physics33Player160View1 __asm__("D_80070328+0x160");
extern int Physics33Player48View1 __asm__("D_80070328+0x48");
extern int Physics33Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics33Player5CView1 __asm__("D_80070328+0x5C");
extern int Physics33Player60View1 __asm__("D_80070328+0x60");
extern int Physics33Player64View2 __asm__("D_80070328+0x64");
extern int Physics33Player8View1 __asm__("D_80070328+0x8");
extern int Physics33Player88View1 __asm__("D_80070328+0x88");
extern int Physics33Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics33Player90View1 __asm__("D_80070328+0x90");
extern int Physics33Player94View3 __asm__("D_80070328+0x94");
extern int Physics33PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics33PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics33PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics33PlayerF8View1 __asm__("D_80070328+0xF8");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char Physics33Player0View4 __asm__("D_80070328");
int Physics33PlanarHeadingLookupView2() __asm__("func_8004E880");
int Physics33Call41580View3() __asm__("func_80041580");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics33Player8CView2 __asm__("D_80070328+0x8C");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern int Physics33Player50View1 __asm__("D_80070328+0x50");
extern int Physics33Player250View1 __asm__("D_80070328+0x250");
int Physics33PlanarHeadingLookupView3() __asm__("func_8004E880");
void func_level_33_800990E0(int slotIndex) {
    int agentProduct0, agentProduct1, agentProduct2, agentProduct3, agentProduct4, agentProduct5,
        agentProduct6, agentProduct7;
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
            spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C;
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
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    void* temp_v0_7;
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    workWord2 = slotIndex * 16;
    globalPointer = &Physics33Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics33Data6C570View1 = (void*)workWord2;
    workWord2 = Physics33Field(&Physics33Player0View1, int*, 0x54);
    stateWord3 = Physics33Field(&Physics33Player0View1, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        default:
            return;
        case 20:
        case 53:
        case 54:
            globalVector80 = &Physics33Player0View1 + 0x80;
            Physics33ClearVectorView1(globalVector80);
            Physics33ClearVectorView1(globalVector80 + 0xC);
            if (Physics33Data6E044View1 != 7) {
                Physics33Call40D10View1(0x1200);
                Physics33Call416F4View1();
                Physics33Call41580View1(0x5A, 0x10);
                return;
            }
            return;
        case 19: {
            int product19;
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3 = Physics33Data6E344View1;
            workWord2 = 13;
            if (workWord3 == workWord2) {
                workWord2 = Physics33Data6C514View1;
                if (workWord2)
                    return;
            }
            vectorAt30 = &Physics33Player0View3 + 8;
            workWord3 = Physics33Field(vectorAt30, int*, 0);
            workWord2 = Physics33Field(&Physics33Player0View3, int*, 0x144);
            numeric4 = workWord3 - workWord2;
            workWord2 = numeric4 < 1024;
            if (!workWord2)
                goto beyond19;
            workWord2 = Physics33Player94View2;
            workWord2 += 128;
            Physics33Player94View2 = workWord2;
            workWord2 = workWord2 < 4801;
            __asm__("" : "=r"(numeric4) : "0"(numeric4), "r"(workWord2));
            if (!workWord2) {
                workWord2 = 4800;
                Physics33Player94View2 = workWord2;
            }
            product19 = numeric4 * numeric4;
            call4 = &originalFrame.sp10;
            workWord3 = Physics33Field(&Physics33Player0View3, int*, 0x148);
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(workWord2, workWord3, call4, "memory");
            workWord2 = product19 >> 11;
            angle16 = workWord2 + workWord3;
            Physics33Player64View1 = angle16;
            __asm__ volatile("" : "=r"(vectorAt30) : "0"(vectorAt30), "r"(call4) : "memory");
            Physics33CopyVectorView3(call4, vectorAt30 + 340);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics33SubtractVectorView3(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics33MeasureVectorLengthView3(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8009927C) : "memory");
            numeric6 = 1024;
            goto limit19;
        beyond19:
            numeric5 = Physics33Field(&Physics33Player0View3, int*, 0x14C);
            workWord2 = workWord3 - numeric5;
            workWord2 = workWord2 < -1024;
            numeric6 = numeric5 - workWord3;
            if (!workWord2)
                goto curve19;
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x800992A0));
            workWord2 = Physics33Player4CView1;
            workWord3 = 1;
            if (!workWord2) {
                workWord2 = Physics33Field(&Physics33Player0View3, int*, 0x148);
                Physics33Player4CView1 = workWord3;
                workWord2 += 512;
                Physics33Field(&Physics33Player0View3, int*, 0x148) = workWord2;
            }
            workWord2 = Physics33Player94View2;
            workWord2 += 128;
            Physics33Player94View2 = workWord2;
            workWord2 = workWord2 < 4801;
            if (!workWord2)
                Physics33Player94View2 = 4800;
            workWord2 = Physics33Field(&Physics33Player0View3, int*, 0x150);
            numeric6 = numeric4 - 1024;
            workWord3 = workWord2 * numeric6;
            workWord2 = Physics33Field(&Physics33Player0View3, int*, 0x154);
            workWord2 = workWord3 / workWord2;
            call4 = &originalFrame.sp10;
            workWord3 = Physics33Field(&Physics33Player0View3, int*, 0x148);
            angle16 = workWord3 + workWord2;
            workWord2 = (numeric6 << 10) >> 10;
            workWord2 = angle16 + workWord2;
            angle16 = workWord2 & 4095;
            Physics33Player64View1 = angle16;
            Physics33CopyVectorView3(call4, vectorAt30 + 340);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics33SubtractVectorView3(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics33MeasureVectorLengthView3(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x800993B0) : "memory");
            numeric6 = 1024;
            goto limit19;
        curve19:
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x800993B8));
            workWord2 = (numeric6 * 4800) >> 10;
            Physics33Player94View2 = workWord2;
            workWord2 = Physics33Player16CView1;
            numeric7 = Physics33Field(&Physics33Player0View3, int*, 0x168);
            workWord3 = Physics33Field(&Physics33Player0View3, int*, 0x158);
            workWord2 &= 127;
            numeric4 = numeric7 << 1;
            Physics33Player16CView1 = workWord2;
            workWord2 = *(short*)(&Physics33Data65920View2 + numeric4);
            workWord3 += 1024;
            product10 = workWord3 * workWord2;
            square8 = numeric6 * numeric6;
            workWord2 = product10 >> 12;
            originalFrame.sp10 = workWord2;
            workWord2 = *(short*)(&Physics33Data658A0View2 + numeric4);
            workWord3 = workWord3 * workWord2;
            numeric7 <<= 4;
            call4 = &originalFrame.sp10;
            call5 = call4;
            __asm__("" : "=r"(vectorAt30) : "0"(vectorAt30), "r"(call4), "r"(call5));
            numeric6 = (int)vectorAt30 + 340;
            workWord2 = square8 >> 11;
            angle16 = numeric7 - workWord2;
            workWord2 = workWord3 >> 12;
            originalFrame.sp14 = workWord2;
            Physics33AddVectorView3(call4, call5, numeric6, numeric7);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics33Player64View1 = angle16;
            Physics33SubtractVectorView3(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics33MeasureVectorLengthView3(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 2049;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            numeric6 = 2048;
        limit19:
            Physics33ScaleVectorRatioQ15View3(call4, call5, numeric6);
        commit19:
            workWord2 = originalFrame.sp10;
            workWord3 = originalFrame.sp14;
            Physics33Field(&Physics33Player0View3, int*, 0x8C) = workWord2;
            Physics33Field(&Physics33Player0View3, int*, 0x90) = workWord3;
            return;
        }
        case 21:
            raw22_temp_v0_6 = Physics33Field(&Physics33Player0View4, int*, 0x94) - 0x140;
            Physics33Field(&Physics33Player0View4, int*, 0x94) = raw22_temp_v0_6;
            if (raw22_temp_v0_6 < -0x2300) {
                Physics33Field(&Physics33Player0View4, int*, 0x94) = -0x2300;
            }
            Physics33Field(&Physics33Player0View4, int*, 0xA4) = Physics33PlanarHeadingLookupView2(
                Physics33Field(&Physics33Player0View4, int*, 0x8C),
                Physics33Field(&Physics33Player0View4, int*, 0x90), 1);
            Physics33Call41580View3(0x5A, 0x10);
            return;
        case 28:
            Physics33Call40D10View1(0xC80);
            Physics33Call41580View1(0x28, 8);
            Physics33Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics33Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics33InterpolateCosineView1(Physics33Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics33Field(&Physics33Player0View1, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics33Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp20 = workWord2;
            workWord2 = Physics33InterpolateSineView1(call4);
            workWord3 = Physics33Field(&Physics33Player0View1, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp24 = workWord2;
            Physics33SubtractVectorView1(&originalFrame.sp20, &originalFrame.sp20, globalVector8C);
            originalFrame.sp28 = 0;
            temp_v0_4 = Physics33MeasureVectorLengthView1(&originalFrame.sp20, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics33ScaleVectorRatioQ15View1(&originalFrame.sp20, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics33AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp20);
            Physics33Call41B64View1();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics33Field(&Physics33Player0View1, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics33Field(&Physics33Player0View1, int*, 0x94) - 0xC0;
            }
            Physics33Player94View1 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics33Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics33Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp40;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics33CallRandView1() & 0xFF)) {
                        workWord2 = Physics33Call363DCView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics33Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp30 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics33Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp38 = 0xE;
                        originalFrame.sp40 = -0x12C;
                        originalFrame.sp44 = 0;
                        originalFrame.sp48 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp34 = (workWord3 * 5) >> 0xA;
                        Physics33TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp40 += Physics33Call363DCView1(0, 0x50);
                        originalFrame.sp44 += Physics33Call363DCView1(0, 0x50);
                        originalFrame.sp48 += Physics33Call363DCView1(0, 0x50);
                        Physics33AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp30);
                        Physics33Field(temp_v0_5, signed char*, 2) = 8;
                        Physics33Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 58:
            globalFieldB8PointerState20 = &Physics33Player0View1 + 0xB8;
            if (Physics33Field(&Physics33Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp30;
                Physics33ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics33SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp38 = 0;
                temp_v0_6 = Physics33MeasureVectorLengthView1(&originalFrame.sp30, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics33ScaleVectorRatioQ15View1(&originalFrame.sp30, temp_v0_6, 0x40);
                }
                originalFrame.sp38 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics33AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp30);
                Physics33CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics33ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics33ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics33Field(&Physics33Player0View1, int*, 0x94) < -0x2300) {
                Physics33Field(&Physics33Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics33Field(&Physics33Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics33Data6C640View1 & 1)) {
                originalFrame.sp50 = 0;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = 0xE;
                Physics33CopyVectorView1(&originalFrame.sp60,
                                         (&Physics33Player0View1 + 0x94) - 0x94);
                originalFrame.sp60 += Physics33Call363DCView1(0, 0x12C);
                originalFrame.sp64 += Physics33Call363DCView1(0, 0x12C);
                originalFrame.sp68 += Physics33Call363DCView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp60, &originalFrame.sp50);
                Physics33Field(temp_v0_7, signed char*, 2) = 6;
                Physics33Field(temp_v0_7, signed char*, 0xA) = 0x20;
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
            call4 = &originalFrame.sp50;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            pointer17 = &Physics33Player154View1;
            Physics33Call410F8View1(call4, pointer17, 0);
            workWord2 = originalFrame.sp54;
            numeric4 = Physics33Player94View3;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp50;
            numeric4 -= 1024;
            originalFrame.sp60 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                pointer16 = &originalFrame.sp58;
                call4 = pointer16;
                call5 = pointer16;
                __asm__ volatile(""
                                 : "=r"(pointer17)
                                 : "0"(pointer17), "r"(call4), "r"(call5)
                                 : "memory");
                pointer17 -= 340;
                call6 = pointer17;
                workWord2 = Physics33Player8CView1;
                workWord3 = Physics33Player90View1;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp58 = workWord2;
                originalFrame.sp5C = workWord3;
                Physics33AddVectorView4(call4, call5, call6);
                if (!Physics33Call13E38View1(pointer17, pointer16, 2)) {
                    workWord2 = Physics33Player8View1;
                    workWord3 = Physics33Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp54 = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp54 = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp54;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics33PlayerF8View1;
            workWord3 = Physics33Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics33Player60View1;
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
            call4 = &Physics33Player64View2;
            workWord2 = Physics33Field(call4, int*, 0);
            workWord3 = Physics33Player60View1;
            Physics33PlayerA8View2 = delta19;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics33Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics33Player60View1 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics33Player60View1 = workWord2;
            }
            workWord2 = Physics33Player60View1;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics33Player60View1 = -800;
            workWord2 = Physics33Player60View1;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics33Player60View1 = 800;
            workWord2 = Physics33Data6FA38View1;
            if (workWord2 >= 0)
                goto nonnegative33;
            workWord3 = Physics33Player60View1;
            if (workWord3 >= 0)
                goto positive33;
            numeric4 = Physics33Data67634View1;
            workWord2 = Physics33Data67630View1;
            workWord2 = numeric4 - workWord2;
            goto quotient33;
        positive33:
            if (workWord3 <= 0)
                goto zero33;
            workWord2 = Physics33Data67638View1;
            numeric4 = Physics33Data67634View1;
            workWord2 -= numeric4;
        quotient33:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics33PlayerACView2 = numeric4;
            goto modifier33;
        zero33:
            workWord2 = Physics33Data67634View1;
            Physics33PlayerACView2 = workWord2;
        modifier33:
        speed33:
            call5 = &Physics33Player144View2;
            workWord2 = Physics33PlayerACView2;
            numeric4 = Physics33PlayerB0View2;
            workWord3 = Physics33Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics33Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics33PlayerB0View2 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics33PlayerB0View2 = 2048;
            workWord2 = Physics33PlayerB0View2;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics33PlayerB0View2 = 19200;
            goto rotation33;
        nonnegative33:
            numeric4 = Physics33Player8View1;
            limit16 = 0;
            workWord2 = Physics33Call4E4E4View1(numeric4);
            workWord3 = Physics33Player148View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            numeric4 = workWord2;
            MATCHING_KEEP(numeric4);
            Physics33PlayerACView2 = numeric4;
            numeric5 = workWord3;
            if (!workWord3)
                goto zeroCounter33;
            workWord2 = 0x60000;
            Physics33Player130View1 = workWord2;
            workWord2 = numeric5 - 1;
            Physics33Player148View1 = workWord2;
            workWord2 <<= 16;
            if (workWord2 > 0)
                goto positiveCounter33;
            workWord3 = Physics33PlayerB0View2;
            workWord2 = workWord3 - numeric4;
            workWord2 = workWord2 < 192;
            if (workWord2) {
                workWord2 = numeric4 + 8192;
                Physics33PlayerB0View2 = workWord2;
                Physics33Player148View1 = 0;
                goto counterClamp33;
            }
            workWord2 = workWord3 - 192;
            Physics33PlayerB0View2 = workWord2;
            workWord2 = 1;
            Physics33Player148View1 = workWord2;
            goto counterClamp33;
        positiveCounter33:
            workWord2 = numeric4 + 8192;
            Physics33PlayerB0View2 = workWord2;
            limit16 = 96;
            goto counterClamp33;
        zeroCounter33:
            Physics33PlayerB0View2 = numeric4;
            __asm__ volatile("" : "=r"(limit16) : "0"(limit16) : "$3", "memory");
            Physics33Player130View1 = 0;
        counterClamp33:
            globalPointer = &Physics33PlayerB0View2;
            workWord2 = Physics33Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 22785;
            if (!workWord2)
                Physics33Field(globalPointer, int*, 0) = 22784;
            workWord2 = Physics33Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 2048;
            if (workWord2)
                Physics33Field(globalPointer, int*, 0) = 2048;
            numeric5 = Physics33Player14CView1;
            workWord3 = Physics33Player150View1;
            workWord2 = limit16 - numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics33Player150View1 = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics33Player14CView1 = numeric5;
            if (numeric5 < 0)
                Physics33Player14CView1 = 0;
            workWord2 = Physics33Player14CView1;
            workWord2 = workWord2 < 97;
            if (!workWord2)
                Physics33Player14CView1 = 96;
        rotation33:
            workWord2 = Physics33Player148View1;
            workWord2 = workWord2 < 2;
            if (workWord2)
                goto spring33;
            workWord3 = Physics33Player14AView1;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 3;
            MATCHING_KEEP(workWord2);
            workWord3 = Physics33Player5CView1;
            workWord2 <<= 11;
            Physics33Player154View1 = workWord2;
            workWord2 >>= 6;
            workWord3 += workWord2;
            workWord3 &= 4095;
            workWord2 = workWord3 < 2049;
            Physics33Player5CView1 = workWord3;
            if (workWord2)
                goto rotationDone33;
            workWord2 = workWord3 - 4096;
            goto storeAngle33;
        spring33:
            workWord2 = Physics33InterpolateCosineView3(Physics33Player60View1);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            originalLow = delta19 * workWord2;
            workWord3 = Physics33Player154View1;
            numeric5 = Physics33Player5CView1;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = originalLow >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics33Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics33Player5CView1 = numeric5;
            if (workWord2)
                goto rotationDone33;
            workWord2 = numeric5 - 4096;
        storeAngle33:
            Physics33Player5CView1 = workWord2;
        rotationDone33:
            Physics33Call41848View2();
            call5 = &Physics33Player4CView2;
            numeric4 = Physics33Field(call5, int*, 0);
            if (numeric4)
                goto active33;
            workWord2 = (int)Physics33Data6C570View1;
            workWord2 = Physics33Field((void*)workWord2, int*, 4) & 64;
            if (!workWord2)
                goto end33;
            workWord2 = Physics33PlayerF8View1;
            workWord3 = Physics33Player8View1;
            workWord2 -= 512;
            workWord3 = workWord3 < workWord2;
            if (!workWord3)
                goto end33;
            workWord3 = Physics33Player48View1;
            workWord2 = 33;
            if (workWord3 != workWord2)
                goto end33;
            workWord2 = 1;
            Physics33Field(call5, int*, 0) = workWord2;
            __asm__ volatile("" ::: "$4", "memory");
            Physics33Player160View1 = 0;
            goto end33;
        active33:
            workWord2 = Physics33Player8View1;
            workWord3 = Physics33PlayerF8View1;
            workWord2 = workWord2 < workWord3;
            if (workWord2) {
                workWord2 = 1;
                goto activeRemainder33;
            }
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics33Field(call5, int*, 0) = 0;
            goto end33;
        activeRemainder33:
            if (numeric4 != workWord2)
                goto decline33;
            workWord2 = Physics33Player160View1;
            workWord2 += 512;
            Physics33Player160View1 = workWord2;
            workWord2 = workWord2 < 6144;
            if (!workWord2) {
                workWord2 = 6144;
                Physics33Player160View1 = workWord2;
                workWord2 = 2;
                Physics33Field(call5, int*, 0) = workWord2;
            }
            goto add88;
        decline33:
            workWord2 = Physics33Player160View1;
            workWord2 -= 256;
            Physics33Player160View1 = workWord2;
            if (workWord2 <= 0) {
                Physics33Player160View1 = 0;
                Physics33Field(call5, int*, 0) = 0;
            }
        add88:
            {
                register void* pointer2 __asm__("$2");
                pointer2 = &Physics33Player88View1;
                workWord3 = Physics33Field(pointer2, int*, 0);
                numeric4 = Physics33Player160View1;
                workWord3 += numeric4;
                Physics33Field(pointer2, int*, 0) = workWord3;
            }
        end33:
            Physics33Call41B64View3();
            return;
        }
        case 47: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3 = Physics33Data6E044View3;
            workWord2 = 7;
            if (workWord3 == workWord2)
                goto zero47;
            Physics33Call40F48View2(&originalFrame.sp70, 0);
            workWord2 = originalFrame.sp70;
            numeric6 = originalFrame.sp74;
            originalFrame.sp78 = 0;
            workWord3 = (workWord2 * 9 << 7) >> 7;
            workWord2 = (numeric6 * 3 << 9) >> 7;
            originalFrame.sp70 = workWord3;
            workWord3 = -workWord3;
            originalFrame.sp74 = workWord2;
            originalFrame.sp7C = workWord3;
            originalFrame.sp80 = workWord2;
            workWord2 = Physics33MeasureVectorLengthView3(&originalFrame.sp78, 0, numeric6);
            numeric4 = originalFrame.sp80;
            workWord3 = numeric4;
            if (numeric4 < 0) {
                MATCHING_KEEP(workWord3);
                workWord3 = -workWord3;
            }
            workWord3 = workWord3 < workWord2;
            if (workWord3) {
                workWord2 = originalFrame.sp7C;
                originalFrame.sp80 = 0;
                MATCHING_BARRIER_VOLATILE("$4");
                numeric4 = 0;
                if (workWord2 > 0) {
                    __asm__ volatile("" ::"i"(0x8009A074) : "memory");
                    numeric4 = 1;
                }
                if (!Physics33Call43194View1(numeric4)) {
                    originalFrame.sp7C = 0;
                }
            } else {
                MATCHING_BARRIER_VOLATILE("$3");
                originalFrame.sp7C = 0;
                originalFrame.sp78 = 0;
                if (numeric4 > 0) {
                    __asm__ volatile("" ::"i"(0x8009A09C) : "memory");
                    numeric4 = 2;
                } else
                    numeric4 = 3;
                if (!Physics33Call43194View1(numeric4)) {
                    originalFrame.sp80 = 0;
                }
            }
            call4 = &originalFrame.sp78;
            workWord2 = Physics33MeasureVectorLengthView3(call4, 1);
            Physics33PlayerACView1 = workWord2;
            __asm__ volatile("" ::"i"(0x8009A0CC) : "memory");
            goto clear30;
        zero47:
            Physics33PlayerACView1 = 0;
            goto clear30;
        }
        case 50:
        case 51:
        case 52: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics33Call40F48View2(&originalFrame.sp88, 0);
            workWord2 = originalFrame.sp88;
            numeric6 = originalFrame.sp8C;
            originalFrame.sp90 = 0;
            workWord3 = (workWord2 * 9 << 7) >> 7;
            workWord2 = (numeric6 * 3 << 9) >> 7;
            originalFrame.sp88 = workWord3;
            workWord3 = -workWord3;
            originalFrame.sp8C = workWord2;
            originalFrame.sp94 = workWord3;
            originalFrame.sp98 = workWord2;
            workWord2 = Physics33MeasureVectorLengthView3(&originalFrame.sp90, 0, numeric6);
            numeric4 = originalFrame.sp98;
            workWord3 = numeric4;
            if (numeric4 < 0) {
                MATCHING_KEEP(workWord3);
                workWord3 = -workWord3;
            }
            workWord3 = workWord3 < workWord2;
            if (workWord3) {
                workWord2 = originalFrame.sp94;
                originalFrame.sp98 = 0;
                MATCHING_BARRIER_VOLATILE("$4");
                numeric4 = 0;
                if (workWord2 > 0) {
                    __asm__ volatile("" ::"i"(0x8009A16C) : "memory");
                    numeric4 = 1;
                }
                if (!Physics33Call43194View1(numeric4)) {
                    originalFrame.sp94 = 0;
                }
            } else {
                MATCHING_BARRIER_VOLATILE("$3");
                originalFrame.sp94 = 0;
                originalFrame.sp90 = 0;
                if (numeric4 > 0) {
                    __asm__ volatile("" ::"i"(0x8009A194) : "memory");
                    numeric4 = 2;
                } else
                    numeric4 = 3;
                if (!Physics33Call43194View1(numeric4)) {
                    originalFrame.sp98 = 0;
                }
            }
            vectorAt30 = &originalFrame.sp90;
            workWord2 = Physics33MeasureVectorLengthView3(vectorAt30, 1);
            numeric6 = 1;
            MATCHING_KEEP(numeric6);
            numeric4 = originalFrame.sp88;
            numeric5 = originalFrame.sp8C;
            globalVector80 = &Physics33PlayerACView1;
            Physics33Field(globalVector80, int*, 0) = workWord2;
            workWord2 = Physics33PlanarHeadingLookupView1(numeric4, numeric5, numeric6);
            workWord3 = workWord2;
            workWord2 = workWord3 < 2049;
            Physics33PlayerA4View1 = workWord3;
            call4 = globalVector80 - 124;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics33PlayerA4View1 = workWord2;
            }
            call5 = vectorAt30;
            workWord2 = originalFrame.sp90;
            call6 = vectorAt30;
            workWord2 += 1024;
            originalFrame.sp90 = workWord2;
            Physics33TransformVectorByBasisView2(call4, call5, call6);
            call4 = vectorAt30;
            call5 = vectorAt30;
            __asm__("" : "=r"(globalVector80) : "0"(globalVector80), "r"(call4), "r"(call5));
            globalVector8CState20 = globalVector80 - 32;
            Physics33SubtractVectorView3(call4, call5, globalVector8CState20);
            call5 = (void*)Physics33MeasureVectorLengthView3(vectorAt30, 0);
            workWord2 = (int)call5 < 385;
            if (!workWord2)
                Physics33ScaleVectorRatioQ15View3(vectorAt30, call5, 384);
            globalVector80 -= 44;
            Physics33AddVectorView3(globalVector80, globalVector8CState20, vectorAt30);
            Physics33CopyVectorView3(globalVector8CState20, globalVector80);
            return;
        }
        case 128:
            globalVector80 = &Physics33Player0View2 + 0xB8;
            workWord2 = Physics33Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero128;
            vectorAt30 = &originalFrame.spA0;
            Physics33ClearVectorView2(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics33SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.spA8 = 0;
            call5 = (void*)Physics33MeasureVectorLengthView2(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics33ScaleVectorRatioQ15View2(vectorAt30, call5, 64);
            originalFrame.spA8 = -192;
            globalVector80 -= 56;
            Physics33AddVectorView2(globalVector80, globalVector8CState20, vectorAt30);
            Physics33CopyVectorView2(globalVector8CState20, globalVector80);
            goto clamp128;
        zero128:
            Physics33ClearVectorView2(globalVector80 - 56);
            Physics33ClearVectorView2(globalVector80 - 44);
            goto clamp128;
        clamp128:
            globalPointer = &Physics33Player94View2;
            workWord2 = Physics33Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
                Physics33Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        case 115:
        case 120:
        case 126:
            globalVector80 = &Physics33Player80View1;
            Physics33ClearVectorView2(globalVector80);
            Physics33ClearVectorView2(globalVector80 + 12);
            workWord3 = Physics33Data6E044View2;
            workWord2 = 40;
            if (workWord3 != workWord2)
                goto ordinary115;
            Physics44Slot4454();
            goto bytes115;
        ordinary115:
            workWord2 = 31;
            if (workWord3 == workWord2)
                goto bytes115;
            Physics33Call40D10View2(3840);
            Physics33Call416F4View2();
            Physics33Call41580View2(90, 16);
        bytes115:
            globalPointer = &Physics33Player1BAView1;
            workWord2 = Physics33Field(globalPointer, unsigned char*, 0);
            if (!workWord2)
                goto byteOne115;
            workWord2 = Physics33Data6E538View1 & 16;
            if (workWord2)
                return;
            workWord2 = 1;
            Physics33Field(globalPointer, unsigned char*, 0) = 0;
            Physics33Player1B9View1 = workWord2;
            return;
        byteOne115:
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics33Player1B9View1 = workWord2;
            return;
        case 116:
        case 117: {
            register void* mode16 __asm__("$16");
            register int mode17 __asm__("$17");
            register int callback18 __asm__("$18");
            mode16 = &Physics33Data6E044View2;
            workWord3 = Physics33Field(mode16, int*, 0);
            mode17 = 40;
            if (workWord3 == mode17)
                goto callback131;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics33Call40D10View2(3840);
            workWord2 = Physics33Data6E538View1 & 12;
            if (workWord2)
                Physics33PlayerACView1 = 0;
            workWord2 = Physics33Call416F4View2();
            workWord3 = Physics33Field(mode16, int*, 0);
            callback18 = workWord2;
            if (workWord3 == mode17) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else {
                call4 = (void*)90;
                call5 = (void*)16;
            }
            workWord2 = Physics33Call41580View2(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics33PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics33Data6E538View1 & 12;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics33Player144View1;
            workWord2++;
            Physics33Player144View1 = workWord2;
            goto saved116;
        reset116:
            Physics33Player144View1 = 0;
        saved116:
            call4 = &Physics33PlayerACView1;
            globalVector80 = (void*)Physics33Field(call4, int*, 0);
            if (callback18)
                goto collision116;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass116;
        collision116:
            workWord2 = Physics33Player20CView1 & 64;
            if (workWord2)
                Physics33Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics33PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics33Field(call4, int*, 0) = workWord3;
            }
        pass116:
            Physics33Call417FCView2(320, 192);
            workWord2 = Physics33Player101View1;
            call4 = &Physics33PlayerACView1;
            Physics33Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics33ClearVectorView2(call4 - 32);
                goto fields116;
            }
            Physics33Call41848View1(call4);
            Physics33Call41B64View2();
        fields116:
            call6 = &Physics33PlayerFCView1;
            workWord2 = Physics33Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics33PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto scalar130;
            goto vector130Input;
        }
        case 118:
            Physics33Call40D10View2(3200);
            workWord3 = Physics33Data6E044View2;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics33Call41580View2(call4, call5);
            Physics33Call417FCView2(320, 192);
            globalFieldA4Pointer = &Physics33PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics33InterpolateCosineView1(Physics33Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics33PlayerB0View1;
            agentProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics33Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spB0 = workWord2;
            workWord2 = Physics33InterpolateSineView1(call4);
            workWord3 = Physics33PlayerB0View1;
            agentProduct1 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spB0;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spB4 = workWord2;
            Physics33SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.spB8 = 0;
        vector118Read:
            __asm__ volatile("" ::"i"(0x8009A674) : "memory");
            workWord2 = Physics33MeasureVectorLengthView1(call4, call5);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            call5 = (void*)workWord2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            workWord2 = (int)call5 < 641;
            MATCHING_KEEP(globalFieldA4Pointer);
            call4 = globalFieldA4Pointer - 36;
            if (!workWord2) {
                Physics33ScaleVectorRatioQ15View1(vectorAt40, call5, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                call4 = globalFieldA4Pointer - 36;
            }
            Physics33AddVectorView1(call4, globalVector8C, vectorAt40);
            Physics33Call41B64View1();
        gate118:
            __asm__ volatile("" ::"i"(0x8009A6B0) : "memory");
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics33Player4CView1;
            __asm__ volatile("" ::"i"(0x8009A6C8) : "memory");
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics33Data6C570View1;
            workWord2 = Physics33Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics33Player144View1;
            __asm__ volatile("" ::"i"(0x8009A6FC) : "memory");
            if (!workWord2)
                goto subtract192_130;
            __asm__ volatile("" ::"i"(0x8009A704) : "memory");
            goto add23_130;
        case 119:
            globalFieldA4Pointer = &Physics33Player50View1;
            workWord3 = Physics33Field(globalFieldA4Pointer, int*, 0);
            workWord2 = 3;
            if (workWord3 != workWord2)
                goto airborne119;
            Physics33Call40D10View2(1600);
            Physics33Call41580View2(22, 4);
            Physics33Call417FCView2(320, 192);
            globalVector8C = globalFieldA4Pointer + 60;
            workWord2 = Physics33InterpolateCosineView1(Physics33PlayerA4View1);
            workWord3 = Physics33PlayerB0View1;
            agentProduct2 = workWord3 * workWord2;
            call4 = (void*)Physics33PlayerA4View1;
            workWord2 = agentProduct2 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spC0 = workWord2;
            workWord2 = Physics33InterpolateSineView1(call4);
            workWord3 = Physics33PlayerB0View1;
            agentProduct3 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spC0;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spC4 = workWord2;
            Physics33SubtractVectorView1(call4, call5, call6);
            originalFrame.spC8 = 0;
            temp_v0_4 = Physics33MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 48;
            if (temp_v0_4 >= 321) {
                Physics33ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 320);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 48;
            }
            Physics33AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics33Call41B64View1();
            workWord2 = Physics33Player94View2;
            workWord2 -= 192;
            Physics33Player94View2 = workWord2;
            workWord2 = workWord2 < -8960;
            goto clamp119;
        airborne119:
            Physics33Call40D10View2(3200);
            workWord3 = Physics33Data6E044View2;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics33Call41580View2(call4, call5);
            Physics33Call417FCView2(320, 192);
            globalFieldA4Pointer = &Physics33PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics33InterpolateCosineView1(Physics33Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics33PlayerB0View1;
            agentProduct4 = workWord3 * workWord2;
            call4 = (void*)Physics33Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spC0 = workWord2;
            workWord2 = Physics33InterpolateSineView1(call4);
            workWord3 = Physics33PlayerB0View1;
            agentProduct5 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spC0;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct5 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spC4 = workWord2;
            Physics33SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.spC8 = 0;
            goto vector118Read;
        case 121:
            vectorAt40 = &originalFrame.spD0;
            Physics33ClearVectorView2(vectorAt40);
            call4 = vectorAt40;
            call5 = call4;
            Physics33SubtractVectorView2(call4, call5, &Physics33Player8CView2);
            workWord2 = Physics33PlayerB8View1;
            call4 = vectorAt40;
            if (!workWord2)
                goto detached121;
            originalFrame.spD8 = 0;
            workWord2 = Physics33MeasureVectorLengthView2(call4, 0);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 9;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)8;
            goto limit121;
        detached121:
            workWord2 = Physics33MeasureVectorLengthView2(call4, 1);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 65;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)64;
        limit121:
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(call4, call5, call6, "memory");
            Physics33ScaleVectorRatioQ15View2(call4, call5, call6);
        vectors121:
            globalVector80 = &Physics33Player80View1;
            call4 = globalVector80;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            globalFieldA4Pointer = globalVector80 + 12;
            call5 = globalFieldA4Pointer;
            call6 = &originalFrame.spD0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call5, call6, "memory");
            workWord2 = -192;
            originalFrame.spD8 = workWord2;
            Physics33AddVectorView2(call4, call5, call6);
            Physics33CopyVectorView2(globalFieldA4Pointer, globalVector80);
            workWord2 = Physics33Player94View2;
            workWord2 = workWord2 < -8960;
        clamp119:
            if (workWord2) {
                workWord2 = -8960;
                Physics33Player94View2 = workWord2;
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
            call4 = &originalFrame.spE0;
            workWord2 = Physics33Player250View1;
            child18 = Physics33Field((void*)workWord2, void**, 0);
            Physics33Call40F48View1(call4, 0);
            input16 = &Physics33Data6E040View1;
            workWord2 = Physics33InterpolateCosineView2(Physics33Field(input16, short*, 0));
            position19 = child18 + 100;
            trig17 = workWord2;
            workWord2 = Physics33InterpolateSineView2(Physics33Field(input16, short*, 0));
            workWord3 = originalFrame.spE4;
            numeric5 = workWord3 * trig17;
            workWord3 = originalFrame.spE0;
            workWord3 *= workWord2;
            call4 = (void*)Physics33Field(input16, short*, 0);
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.spE8 = workWord2;
            workWord2 = Physics33InterpolateCosineView2(call4);
            call4 = (void*)Physics33Field(input16, short*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            secondTrig16 = workWord2;
            workWord2 = Physics33InterpolateSineView2(call4);
            workWord3 = originalFrame.spE0;
            workWord3 = -workWord3;
            numeric5 = workWord3 * secondTrig16;
            workWord3 = originalFrame.spE4;
            workWord3 *= workWord2;
            vector17 = &originalFrame.spE8;
            call4 = vector17;
            player20 = &Physics33Player0View2;
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.spEC = workWord2;
            workWord2 = Physics33Field(child18, int*, 100);
            workWord3 = originalFrame.spE8;
            call6 = player20;
            workWord2 += workWord3;
            Physics33Field(child18, int*, 100) = workWord2;
            workWord2 = Physics33Field(child18, int*, 104);
            workWord3 = originalFrame.spEC;
            call5 = position19;
            workWord2 += workWord3;
            Physics33Field(child18, int*, 104) = workWord2;
            Physics33SubtractVectorView2(call4, call5, call6);
            originalFrame.spF0 = 0;
            workWord2 = Physics33MeasureVectorLengthView2(vector17, 0);
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
            Physics33ScaleVectorRatioQ15View2(call4, call5, call6);
            Physics33AddVectorView2(position19, player20, vector17);
        selector122:
            call4 = (void*)originalFrame.spE8;
            call5 = (void*)originalFrame.spEC;
            workWord2 = Physics33PlanarHeadingLookupView3(call4, call5, 1);
            workWord3 = Physics33Data6E044View2;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            Physics33PlayerA4View1 = workWord2;
            workWord2 = 40;
            call4 = (void*)24;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)4;
            Physics33Call41580View2(call4, call5);
            workWord2 = length16 < 6145;
            if (workWord2)
                goto below122;
            boundedScalar122 = (length16 - 6144) / 56 + 384;
            goto store122;
        below122:
            boundedScalar122 = 384 - ((6144 - length16) / 40);
        store122:
            MATCHING_OBSERVE_VOLATILE_CLOBBER(length16, "memory");
            Physics33Field(child18, int*, 92) = boundedScalar122;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = Physics33Field(child18, int*, 92);
            workWord2 = workWord2 < 256;
            if (workWord2)
                Physics33Field(child18, int*, 92) = 256;
            workWord2 = Physics33Field(child18, int*, 92);
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics33Field(child18, int*, 92) = 512;
            call4 = (void*)Physics33Player250View1;
            Physics44Slot432C(call4);
            return;
        }
        case 124:
        case 129:
        clear30:
            globalVector80 = &Physics33Player0View3 + 0x80;
            Physics33ClearVectorView3(globalVector80);
            Physics33ClearVectorView3(globalVector80 + 0xC);
            return;
        case 130: {
            register int callback17 __asm__("$17");
            globalVector80 = &Physics33Player50View1;
            workWord3 = Physics33Field(globalVector80, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto airborne130;
            workWord2 = 8;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            globalVector80 = &Physics33Data6E044View2;
            MATCHING_KEEP(globalVector80);
            workWord3 = Physics33Field(globalVector80, int*, 0);
            if (workWord3 != workWord2)
                Physics33Call40D10View2(3840);
            workWord2 = Physics33Data6E538View1 & 12;
            if (workWord2)
                Physics33PlayerACView1 = 0;
            workWord2 = Physics33Call416F4View2();
            callback17 = workWord2;
            workWord3 = Physics33Field(globalVector80, int*, 0);
            workWord2 = 40;
            call4 = (void*)90;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)16;
            workWord2 = Physics33Call41580View2(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics33PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics33Data6E538View1 & 12;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics33Player144View1;
            workWord2++;
            Physics33Player144View1 = workWord2;
            goto saved130;
        reset130:
            Physics33Player144View1 = 0;
        saved130:
            call4 = &Physics33PlayerACView1;
            globalVector80 = (void*)Physics33Field(call4, int*, 0);
            if (callback17)
                goto collision130;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass130;
        collision130:
            workWord2 = Physics33Player20CView1 & 64;
            if (workWord2)
                Physics33Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics33PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics33Field(call4, int*, 0) = workWord3;
            }
        pass130:
            Physics33Call417FCView2(320, 192);
            workWord2 = Physics33Player101View1;
            call4 = &Physics33PlayerACView1;
            Physics33Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics33ClearVectorView2(call4 - 32);
                goto fields130;
            }
            Physics33Call41848View1(call4);
            Physics33Call41B64View2();
        fields130:
            call6 = &Physics33PlayerFCView1;
            workWord2 = Physics33Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics33PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector130Input;
        scalar130:
            workWord2 = Physics33PlayerA0View1;
            workWord2 -= 192;
            Physics33Player94View2 = workWord2;
            return;
        vector130Input:
            __asm__ volatile("" ::"i"(0x8009ADE0) : "memory");
            call5 = call4;
            Physics33AddVectorView2(call4, call5, call6 - 20);
            return;
        airborne130:
            Physics33Call40D10View2(3200);
            workWord3 = Physics33Data6E044View2;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics33Call41580View2(call4, call5);
            Physics33Call417FCView2(320, 192);
            globalFieldA4Pointer = &Physics33PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics33InterpolateCosineView1(Physics33Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics33PlayerB0View1;
            agentProduct6 = workWord3 * workWord2;
            call4 = (void*)Physics33Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct6 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spF8 = workWord2;
            workWord2 = Physics33InterpolateSineView1(call4);
            workWord3 = Physics33PlayerB0View1;
            agentProduct7 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.spF8;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct7 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spFC = workWord2;
            Physics33SubtractVectorView1(call4, call5, call6);
            originalFrame.sp100 = 0;
            temp_v0_4 = Physics33MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 36;
            if (temp_v0_4 >= 641) {
                Physics33ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 36;
            }
            Physics33AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics33Call41B64View1();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics33Player4CView1;
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics33Data6C570View1;
            workWord2 = Physics33Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics33Player144View1;
            if (!workWord2)
                goto subtract192_130;
        add23_130:
            workWord2 = Physics33Player94View2;
            workWord2 += 23;
            Physics33Player94View2 = workWord2;
            return;
        subtract192_130:
            globalPointer = &Physics33Player94View2;
            workWord2 = Physics33Field(globalPointer, int*, 0);
            workWord2 -= 192;
            Physics33Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 131:
        case 132:
            goto callback131;
    }
    return;
callback131:
    __asm__ volatile("" ::"i"(0x8009AF70) : "memory");
    Physics44Slot4454();
    return;
}
#undef Physics33Field


/* AI generated; not human reviewed. SCUS-94467 8009AFA8..8009B594.
 * Baselines: linked-byte-verified 43_80092B50 scalar/clamp and 50_8009CF04
 * particle loop. Original33 supplies selector scope and numeric memory accesses.
 * Source +0x28+0x70, +0x148-0xB0 and -0x98 are byte offsets.
 * Original33 8009B278..8009B288 masks V0, loads the third component,
 * then computes A2 in its load delay; the empty memory boundary preserves this.
 * Empty lifetime constraints emit no instructions; helper meanings, units and
 * invocation cadence remain unresolved. Acceptance requires every original
 * code/table word, strict full translation unit and all EXE/overlay hashes.
 */
extern int Callback33Step __asm__("D_80070328+0x144");
extern int Callback33Z __asm__("D_80070328+8");
extern int Callback33Limit __asm__("D_80070328+0x280");
extern Spyro Callback33Player __asm__("D_80070328");
void Callback33Call80041930(void) __asm__("func_80041930");
void Callback33Call80041C20(void) __asm__("func_80041C20");
void Callback33Call80042A44(void) __asm__("func_80042A44");
void Callback33Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback33Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38, D_8006C648;
int Callback33Query(Vector3D*, int) __asm__("func_8001A358");
int Callback33Length(Vector3D*, int) __asm__("func_8004EDE8");
void Callback33Call8004F110(Vector3D*, int) __asm__("func_8004F110");
extern short Callback33Count __asm__("D_80070328+0x148");
void func_level_33_8009AFA8(void) {
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


    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback33Player.animationState) {
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
            Callback33Call80041C20();
            Callback33Player.unk9a = 0;
            Callback33Call80042A44();
            goto clearSharedValue;
        default:
            return;
        case 0x35:
        case 0x36:
        case 0x80:
            Callback33Call80041C20();
            Callback33Call80042A44();
            goto clearSharedValue;
        case 0x79:
            Callback33Call80041C20();
            Callback33Call80042A44();
            goto queryC00;
        case 0x13:
        case 0x15:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            goto clearSharedValue;
        case 0x1C:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            if (Callback33Player.unk7a[3].z < 0 && Callback33Player.animationStateFrames >= 4)
                Callback33Player.unk5 = 1;
            goto clearSharedValue;
        case 0x81: {
            register int* zWord __asm__("$5") = &Callback33Z;
            register int velocity __asm__("$6") = Callback33Step;
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
            status = Callback33Limit;
            velocity += tick;
            Callback33Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback33Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback33Step = 0x2580;
            }
        limitsDone:
            Callback33Call80041C20();
            Callback33Call80042A44();
            func_8004F178(&local.first, &Callback33Player.position);
            local.first.z += 0x400;
            Callback33Player.unk4[0] = Callback33Query(&local.first, 0xC00);
            positionDelta = (int)Callback33Player.union144.a.unk13cb;
            positionValue = Callback33Player.position.z;
            positionDelta >>= 6;
            positionValue -= positionDelta;
            MATCHING_KEEP(positionValue);
            Callback33Player.position.z = positionValue;
            return;
        }
        case 0x21:
        case 0x22:
        case 0x23:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            if (SpawnParticle != 0) {
                countBase = (unsigned char*)&Callback33Count;
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
                        Callback33Call8004F110(vectorPointer, 7);
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
                        MATCHING_KEEP3_CLOBBER(kind, subtype, sample, "memory");
                        sample &= 254;
                        component = local.second.z;
                        MATCHING_BARRIER_VOLATILE("memory");
                        position = sourceBytes - 0x98;
                        __asm__("" : "=r"(position) : "0"(position), "r"(sample));
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
        case 0x2F:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            func_80042F64();
            goto clearSharedValue;
        case 0x32:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            func_80042F64();
            numerator = (int)((unsigned int)Callback33Player.unk7a[3].z << 2);
            Callback33Player.unk4[0] = 0;
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
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            func_80042F64();
            Callback33Player.unk4[0] = 0;
            {
                register int quotient __asm__("$3") =
                    (int)(((unsigned int)Callback33Length(
                               (Vector3D*)((unsigned char*)Callback33Player.unk4 + 0x70), 0)
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
        case 0x3A:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Player.cheatColour.a = 0xFF;
            Callback33Player.unk4[0] = 0;
            Callback33Player.cheatColour.b = 0x20;
            Callback33Player.cheatColour.g = 0x20;
            Callback33Player.cheatColour.r = 0x20;
            return;
        case 0x76:
        case 0x77:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            if (Callback33Player.unk5 != 0x7F) {
                if ((Callback33Player.unk7a[3].z < 0) &&
                    (Callback33Player.animationStateFrames >= 4)) {
                    Callback33Player.unk5 = 1;
                } else {
                    goto checkSecondFlag;
                }
            }
            goto clearSharedValue;
        case 0x82:
            if (Callback33Player.movementState != MOVEMENT_STATE_WALK)
                goto other82;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
        queryC00:
            Callback33Call80043A38(0xC00);
            goto clearSharedValue;
        other82:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            if ((Callback33Player.unk7a[3].z < 0) && (Callback33Player.animationStateFrames >= 4)) {
                Callback33Player.unk5 = 1;
            } else {
            checkSecondFlag:
                if ((Callback33Player.unk5 == 0) && !(Callback33Word8006E538 & 0x40) &&
                    (Callback33Player.union144.a.unk13cb == 0)) {
                    Callback33Player.unk5 = 2;
                }
            }
        clearSharedValue:
            Callback33Player.unk4[0] = 0;
            return;
    }
}

#define LEVEL_ID 33
#define PlaySpyroSounds_level_33 func_level_33_8009B598
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_33_8009B800(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x13:
        case 0x15:
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
        case 0x14:
        case 0x35:
        case 0x36:
        case 0x3a:
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

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8009B8A8.
 * Reuses verified12 transition/private0/4/8 and46 special-state producers.
 * Original33 supplies15 numeric flags490/shift6/trig signed shifts12 and
 * independent2F/32/33/34 ladder routes and35/36 shared grounded/pointer tail.
 * All numeric pointer offsets are bytes. Height signed shifts10, yaw maskFFF,
 * length clamp800/4B00, signed trig table halfwords/shift1, private5C/64/68/6C
 * and74/78 child48 chain retain the original instructions and access widths.
 * Empty register/memory constraints retain original independent branch blocks
 * and scheduling; they emit no instructions. Existing names do not establish
 * helper meanings, source units, audio semantics, or caller/update cadence.
 * Confidence is exact compiled code/data only. Falsifiable acceptance vectors:
 * every original code/local jump/owned table word, strict complete translation
 * unit, and complete EXE/every original overlay hashes. Runtime parity remains
 * unverified; this change does not modify the browser implementation.
 */
extern short Transition33SignedA[] __asm__("D_800658A0");
extern short Transition33SignedB[] __asm__("D_80065920");
extern int Transition33RawX __asm__("D_80070328+0x8C");
extern int Transition33_D_8006E528 __asm__("D_8006E528");
int Transition33PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");

extern Spyro Transition33_D_80070328 __asm__("D_80070328");
int Transition33MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
int Transition33RandBetween(int low, int high) __asm__("func_8003636C");
void Transition33_func_80043A38(int scale) __asm__("func_80043A38");
void Transition33_func_800441F0(void) __asm__("func_800441F0");
void Transition33ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition33_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition33RawUnion[] __asm__("D_80070328+0x144");
extern int Transition33RawMovement __asm__("D_80070328+0x50");
extern int Raw33Movement __asm__("D_80070328+0x50");
extern int Raw33Union __asm__("D_80070328+0x144");
void Call33ED6C(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
extern void (*Call33Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw33State[] __asm__("D_80070328+0x50");
extern Spyro Special33_D_80070328 __asm__("D_80070328");
extern short Signed33TableA[] __asm__("D_800658A0");
extern short Signed33TableB[] __asm__("D_80065920");
int Special33MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Special33_func_80043A38(int scale) __asm__("func_80043A38");
void Special33_func_800441F0(void) __asm__("func_800441F0");
void Special33ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Special33_D_8006E524 __asm__("D_8006E524");

int Call33EA2C(int) __asm__("func_8004EA2C");
int Call33E9E4(int) __asm__("func_8004E9E4");
void func_level_33_8009B8A8(int arg0) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");

    int lengthResult;

    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    register unsigned char* stateBase __asm__("$17");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int groundValue __asm__("$2");
    switch (arg0) {
        case 0x14:
            Transition33_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition33_D_80070328.unk5 = 0;
            Transition33_func_800441F0();
            Transition33_D_80070328.grounded = 1;
            Transition33_D_80070328.union144.a.unk13cb = Transition33RandBetween(1, 3);
            Transition33_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x13: {
            register Moby* sourceMoby __asm__("$6");
            register int yawValue __asm__("$5");
            register int positionZ __asm__("$2");
            register int heightValue __asm__("$3");
            register int privateValue __asm__("$4");
            stateBase = (unsigned char*)&Transition33RawMovement;
            privateData = Transition33_D_80070328.m_WhirlwindPointer->mobyTag;
            *(int*)stateBase = 14;
            Transition33_D_80070328.unk5 = 0;
            Transition33_D_80070328.grounded = 0;
            Transition33ClearVector((Vector3D*)(stateBase + 0x3C));
            sourceMoby = Transition33_D_80070328.m_WhirlwindPointer;
            yawValue = Transition33_D_80070328.rotation.yaw;
            positionZ = Transition33_D_80070328.position.z;
            heightValue = sourceMoby->position.z;
            privateValue = *(int*)privateData;
            MATCHING_KEEP4(sourceMoby, yawValue, positionZ, heightValue);
            Transition33_D_80070328.union144.a.unk13cc = yawValue;
            Transition33_D_80070328.union144.a.unk13cb = positionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue += privateValue;
            Transition33_D_80070328.union144.a.unk13ce.x = heightValue;
            heightValue -= positionZ;
            heightValue -= 0x800;
            Transition33_D_80070328.union144.a.unk13ce.z = heightValue;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue = ((int)(heightValue << 0xA) >> 0xA) + 0x400;
            MATCHING_KEEP(heightValue);
            Transition33_D_80070328.union144.a.unk13ce.y = heightValue;
            maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
            Transition33_D_80070328.union144.a.unk13ce.y = maskedValue;
            if (maskedValue >= 0x801) {
                Transition33_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
            }
            Transition33_D_80070328.union144.a.unk13da = *(int*)(privateData + 4);
            func_8004F178((Vector3D*)(stateBase + 0x10C), &sourceMoby->position);
            Transition33_D_80070328.unk13e[0] =
                (int)Transition33_D_80070328.m_WhirlwindPointer->angle.yaw;
            positionZ = *(int*)(privateData + 8);
            MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
            Transition33_D_80070328.unk20a = 0;
            Transition33_D_80070328.critterMobyPtr = 0;
            Transition33_D_80070328.unk13e[1] = positionZ;
            return;
        }
        case 0x15:
            Transition33_D_80070328.movementState = 7;
            Transition33_D_80070328.grounded = 0;
            Transition33_D_80070328.unk5 = 0;
            if (Transition33_D_80070328.unk17a & 0x490) {
                Transition33_D_80070328.unk7a[2].x = Transition33_D_80070328.unk17e.x << 6;
                Transition33_D_80070328.unk7a[2].y = Transition33_D_80070328.unk17e.y << 6;
                Transition33_D_80070328.unk7a[2].z = Transition33_D_80070328.unk17e.z << 6;
            } else {
                shiftedValue = Transition33PlanarHeadingLookup(
                    -Transition33_D_80070328.unk7a[2].x, -Transition33_D_80070328.unk7a[2].y, 1);
                Transition33_D_80070328.unk7b = shiftedValue;
                Transition33_D_80070328.unk7a[2].x = (Call33EA2C(shiftedValue) << 12) >> 12;
                Transition33_D_80070328.unk7a[2].y =
                    (Call33E9E4(Transition33_D_80070328.unk7b) << 12) >> 12;
                Transition33_D_80070328.unk7a[2].z = 0x1000;
            }
            goto clearPointers;
        case 0x1C:
            savedBase = Transition33RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Transition33RawMovement;
            Transition33RawMovement = MOVEMENT_STATE_HURT;
            Transition33_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Transition33_D_80070328.unk8[0] = Transition33MeasureVectorLength(sourceC, 0);
            Transition33_D_80070328.unk7a[2].z = 0xDC0;
            Transition33_D_80070328.grounded = 0;
            Transition33_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Transition33_D_80070328.damageFlags & 0x200) {
                Transition33_D_80070328.union144.a.unk13cc = 0;
            } else {
                Transition33_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            goto clearPointers;
        case 0x3A:
            Transition33_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition33_D_80070328.unk5 = 0;
            Transition33_func_80043A38(0xC00);
            Transition33_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition33_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x21:
        case 0x22:
        case 0x23: {
            register unsigned char* flyState __asm__("$16") =
                (unsigned char*)&Transition33RawMovement;
            if (*(int*)flyState != 6) {
                *(int*)flyState = 6;
                Transition33_D_80070328.unk5 = 0;
                Transition33ClearVector((Vector3D*)(flyState + 0x104));
                Transition33_D_80070328.union144.a.unk13db.y = 0;
                lengthResult = Transition33MeasureVectorLength((Vector3D*)(flyState + 0x48), 0);
                Transition33_D_80070328.unk8[0] = lengthResult;
                if (lengthResult < 0x800)
                    Transition33_D_80070328.unk8[0] = 0x800;
                if (Transition33_D_80070328.unk8[0] >= 0x4B01)
                    Transition33_D_80070328.unk8[0] = 0x4B00;
                Transition33_D_80070328.union144.a.unk13cb = 0;
                Transition33_D_80070328.union144.b.unk148 = 0;
                Transition33_D_80070328.union144.a.unk13ce.x = 0;
                Transition33_D_80070328.union144.a.unk13ce.y = 0;
                Transition33_D_80070328.grounded = 0;
                Transition33_D_80070328.unk15b = 0;
            }
            if (arg0 < 0xA0)
                goto clearPointers;
            return;
        }
        case 0x2F:
            savedBase = (unsigned char*)&Transition33RawMovement;
            destination = (Vector3D*)(savedBase + 0x3C);
            if (*(int*)savedBase != 13) {
                *(int*)savedBase = 13;
                Transition33_D_80070328.unk5 = 0;
                func_8004F178(destination, (Vector3D*)(savedBase + 0x48));
                MATCHING_BARRIER_VOLATILE("memory");
                goto groundAndClear;
            }
            goto clearPointers;
        case 0x32:
        case 0x33:
        case 0x34:
            savedBase = (unsigned char*)&Transition33RawMovement;
            destination = (Vector3D*)(savedBase + 0x3C);
            if (*(int*)savedBase != 13) {
                *(int*)savedBase = 13;
                Transition33_D_80070328.unk5 = 0;
                func_8004F178(destination, (Vector3D*)(savedBase + 0x48));
                goto groundAndClear;
            }
            goto clearPointers;
        case 0x35:
        case 0x36:
            Transition33_D_80070328.movementState = 0;
            Transition33_D_80070328.unk5 = 0;
            Transition33_func_800441F0();
        groundAndClear:
            Transition33_D_80070328.grounded = 1;
        clearPointers:
            Transition33_D_80070328.unk20a = 0;
            Transition33_D_80070328.critterMobyPtr = 0;
            return;
        case 0x73:
        case 0x78:
        case 0x7E:
            Special33_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Special33_D_80070328.unk5 = 0;
            Special33_func_800441F0();
            Special33_D_80070328.grounded = 1;
            return;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            walkBase = Raw33State;
            walkFlag = 1;
            MATCHING_KEEP(walkFlag);
            *(int*)walkBase = walkFlag;
            if (arg0 == 0x57 && Special33_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                MATCHING_BARRIER_VOLATILE("memory");
                destination = (Vector3D*)(walkBase + 0x3C);
                goto copyWalkVector;
            }
            goto clearWalkFlag;
        case 0x80:
            Special33_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Special33_D_80070328.unk5 = 0;
            Special33_func_80043A38(0xC00);
            Special33_D_80070328.grounded = 1;
            Special33_D_8006E524 = 0xF;
            return;
        case 0x81: {
            register int oldState __asm__("$3") = Raw33Movement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Raw33Movement = value;
            value = 1;
            MATCHING_KEEP(value);
            Special33_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Special33_D_8006E524 = value;
            Special33_D_80070328.unk5 = 0;
            stateWord = &Raw33Union;
            MATCHING_KEEP(stateWord);
            Special33_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Special33_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            Special33_D_80070328.unk22[3] = (int)D_8006C654->drown;
            return;
        }
        case 0x79:
            Special33_D_80070328.movementState = MOVEMENT_STATE_HURT;
            Special33_D_80070328.unk5 = 0;
            if (Special33_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Special33_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed33TableB + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                tableValueA >>= 1;
                Special33_D_80070328.unk7a[2].x = tableValueA;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed33TableA + tableOffsetOrValue);
                Special33_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Special33_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else {
                Special33ClearVector(
                    (Vector3D*)((unsigned char*)&Special33_D_80070328.movementState + 0x3C));
            }
            Special33_D_80070328.unk7a[2].z = 0x200;
            func_8004F178((Vector3D*)((unsigned char*)&Special33_D_80070328.unk7a[2].z - 0x14),
                          (Vector3D*)((unsigned char*)&Special33_D_80070328.unk7a[2].z - 8));
            Special33_D_80070328.grounded = 1;
            Special33_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
                return;
            }
        default:
            return;
        case 0x7A: {
            register unsigned char* privateData __asm__("$17") =
                Special33_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* state __asm__("$18") = Raw33State;
            register Vector3D* vector __asm__("$16");
            *(int*)state = 0;
            Special33_D_80070328.unk5 = 0;
            vector = (Vector3D*)(privateData + 0x64);
            Special33_func_800441F0();
            Special33_D_80070328.grounded = 1;
            Special33_D_80070328.idle = 0;
            Special33_D_80070328.unk15g = 0;
            *(int*)(privateData + 0x5C) = 0x180;
            *(int*)(privateData + 0x64) = 0x1800;
            *(int*)(privateData + 0x68) = 0;
            *(int*)(privateData + 0x6C) = 0;
            Call33ED6C((Vector3D*)(state - 0x20), vector, vector);
            func_8004F194(vector, vector, (Vector3D*)(state - 0x50));
            Call33Header(Special33_D_80070328.critterMobyPtr);
            return;
        }
        case 0x7B:
            Special33_D_80070328.movementState = 0;
            Special33_func_800441F0();
            groundValue = 1;
            goto sharedGround;
        case 0x7C: {
            register unsigned char* privateData __asm__("$16") =
                Special33_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* child __asm__("$4");
            Special33_D_80070328.movementState = 0;
            Special33_func_800441F0();
            Special33_D_80070328.grounded = 1;
            Special33_D_80070328.idle = 0;
            Special33_D_80070328.unk15g = 0;
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
            stateBaseA = Raw33State;
            MATCHING_KEEP(stateBaseA);
            destination = (Vector3D*)(stateBaseA + 0x3C);
            MATCHING_KEEP(destination);
            sourceBytesA = stateBaseA + 0x48;
            *(int*)stateBaseA = 2;
            func_8004F178(destination, (Vector3D*)sourceBytesA);
            Special33_D_80070328.unk8[0] = Special33MeasureVectorLength((Vector3D*)sourceBytesA, 0);
            Special33_D_80070328.unk7a[2].z = 0xDC0;
            Special33_D_80070328.unk5 = 0;
            if (Special33_D_80070328.animationState == 0x81)
                Special33_D_80070328.union144.a.unk13cb = 1;
            else
                Special33_D_80070328.union144.a.unk13cb = 0;
            Special33_D_80070328.grounded = 0;
            PlaySound((int)D_8006C654->jump, 0, 0);
            return;
        case 0x77: {
            register unsigned char* state __asm__("$6") = Raw33State;
            if (*(int*)state != 2) {
                *(int*)state = 3;
                Special33_D_80070328.unk8[0] =
                    Special33MeasureVectorLength((Vector3D*)(state + 0x48), 0);
                Special33_D_80070328.grounded = 0;
                Special33_D_80070328.unk15b = 1;
                goto clearTail;
            }
            return;
        }
        case 0x82: {
            walkBase = Raw33State;
            if (*(int*)walkBase != 2) {
                walkFlag = 1;
                MATCHING_KEEP(walkFlag);
                *(int*)walkBase = walkFlag;
                if (arg0 == 0x57 && Special33_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                    destination = (Vector3D*)(walkBase + 0x3C);
                copyWalkVector:
                    func_8004F178(destination, (Vector3D*)(walkBase + 0x48));
                    Special33_D_80070328.unk5 = walkFlag;
                } else {
                clearWalkFlag:
                    Special33_D_80070328.unk5 = 0;
                }
                Special33_D_80070328.unk8[0] = Special33MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Special33_D_80070328.movementState + 0x48), 0);
                Special33_func_80043A38(0xC00);
                groundValue = 1;
                MATCHING_KEEP(groundValue);
                Special33_D_80070328.union144.a.unk13cb = 0;
            sharedGround:
                Special33_D_80070328.grounded = groundValue;
            clearTail:
                Special33_D_80070328.idle = 0;
                Special33_D_80070328.unk15g = 0;
            }
            return;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8009C2B8.
 * Assembly SHA256 bf087db34c22e4d4e757c8f9ff64aab9f7aaacd66449ccac7de3e876465775de.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1773 original instructions and114 state-table entries (bias19).
 * New original115..132 state chains retain callback1, collision/input
 * priority, private78/7C/4C fields, masks and mode31/40 gates, signed products,
 * original partial effect/sound calls, counters, water/helper paths and the
 * shared selector119 call that restores the original saved word54 afterward.
 * The original0x20 frame retains savedS0/S1. Generic
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
extern int Anim33Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim33Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim33Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim33Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim33PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim33PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim33PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim33PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim33PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim33PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim33PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim33PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim33Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim33Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim33Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim33PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim33Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim33Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim33Player240View1 __asm__("D_80070328 + 0x240");
extern unsigned char Anim33Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim33Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim33Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim33Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim33PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim33Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim33Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim33Data66530View1[] __asm__("D_80066530");
extern int Anim33Data6E538View1 __asm__("D_8006E538"), Anim33Data6E53CView1 __asm__("D_8006E53C");
extern int Anim33Data6E044View1 __asm__("D_8006E044"), A4898Gate __asm__("D_8006E344"),
    A4898Count __asm__("D_8006C514");
int Anim33Call40994View1() __asm__("func_80040994");
int Anim33Call4BEF8View1() __asm__("func_8004BEF8");
int Anim33Call49688View1() __asm__("func_80049688");
int Anim33Call498C0View1() __asm__("func_800498C0");
extern int Anim33PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim33PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim33PlayerBCView1 __asm__("D_80070328 + 0xBC");
extern int Anim33Player158View1 __asm__("D_80070328 + 0x158");
extern unsigned char Anim33Player0View1[] __asm__("D_80070328");
extern int A21Mode __asm__("D_8006E044"), Anim33Data6E344View1 __asm__("D_8006E344"),
    Anim33Data6C514View1 __asm__("D_8006C514");
int Anim33Call40994View2() __asm__("func_80040994");
int Anim33ApproximatePlanarDistanceView1() __asm__("func_8004F334");
extern int Anim33Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim33Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim33Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim33Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim33Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim33Player90View2 __asm__("D_80070328 + 0x90");
extern int Anim33Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim33PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim33PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim33PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim33PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim33PlayerCCView2 __asm__("D_80070328 + 0xCC");
extern int Anim33PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim33PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim33PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim33Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim33Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char* Anim33Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim33Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim33Data6E535View1 __asm__("D_8006E535");
extern int Anim33Data6E538View2 __asm__("D_8006E538");
extern int Anim33Data6E53CView2 __asm__("D_8006E53C");
extern int Anim33Data6E530View1 __asm__("D_8006E530");
extern int Anim33Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char* Anim33Data6C654View1 __asm__("D_8006C654");
extern int (*Anim33Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim33DataSpawnParticleView1)(int, int, void*, int) __asm__("SpawnParticle");
int Anim33Call55E84View1(void*) __asm__("func_80055E84");
int Anim33Call4BEF8View2(int) __asm__("func_8004BEF8");
int Anim33CallPlaySoundView1(unsigned char, int, int) __asm__("PlaySound");
extern int Anim33Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim33PlayerACView3 __asm__("D_80070328 + 0xAC");
extern int Anim33PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim33PlayerB8View3 __asm__("D_80070328 + 0xB8");
extern int Anim33PlayerE4View3 __asm__("D_80070328 + 0xE4");
extern int A35Buttons __asm__("D_8006E538"), Anim33Data6E53CView3 __asm__("D_8006E53C");
int Anim33Call40994View3() __asm__("func_80040994");
int Anim33Call4BEF8View3() __asm__("func_8004BEF8");
extern int Anim33PlayerBCView2 __asm__("D_80070328 + 0xBC"),
    Anim33Player1BCView1 __asm__("D_80070328 + 0x1BC"),
    Anim33Player60View1 __asm__("D_80070328 + 0x60");
extern short Anim33Player148View1 __asm__("D_80070328 + 0x148");
int Anim33Call43194View1() __asm__("func_80043194");
int Anim33MeasureVectorLengthView1() __asm__("func_8004EDE8");
extern int Anim33PlayerB4View2 __asm__("D_80070328 + 0xB4");
extern int Anim33Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim33Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim33Data6E044View2 __asm__("D_8006E044");
int Anim33Call498C0View2(void*) __asm__("func_800498C0");
int Anim33Call3BF6CView1(int, int) __asm__("func_8003BF6C");
int Anim33Call3BE70View1(int) __asm__("func_8003BE70");
#define Anim33Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_level_33_8009C2B8(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int* savedPointer16 __asm__("$16");
    register int* savedPointer17 __asm__("$17");
    register int savedWord16 __asm__("$16");
    rawValue2 = Anim33Player48View1;
    switch (rawValue2) {
        case 20:
            if (Anim33Call40994View1())
                return;
            rawValue2 = Anim33Data6E53CView1 & 64;
            nextSelector4 = 6;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            if (Anim33PlayerE4View1 >= 23)
                goto select;
            rawValue3 = Anim33Data6E538View1;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 13;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            if (rawValue2 >= 17) {
                nextSelector4 = 1;
                goto select;
            }
            rawValue2 = rawValue3 & 12;
            MATCHING_KEEP(rawValue2);
            if (!rawValue2) {
                rawValue2 = Anim33PlayerACView1;
                nextSelector4 = 1;
                if (rawValue2)
                    goto select;
            }
            if (Anim33Data6E044View1 == 7 || Anim33Player240View1) {
                savedPointer16 = &Anim33Player48View2;
                MATCHING_KEEP(savedPointer16);
                if (!*savedPointer16)
                    return;
                Anim33Call4BEF8View1(0);
                if (Anim33Data66530View1[*((unsigned char*)savedPointer16 - 0x2C)] >= 96) {
                    Anim33Player14View1 = Anim33Player15View1;
                    Anim33Player16View1 = Anim33Player17View1;
                }
                Anim33Player17View1 = 0;
                rawValue3 = *savedPointer16;
                rawValue2 = 113;
                *((unsigned char*)savedPointer16 - 0x2C) = rawValue2;
                Anim33Player1F0View1 = 0;
                Anim33Player15View1 = rawValue3;
                Anim33Player1ECView1 = rawValue3;
                return;
            }
            rawValue2 = Anim33PlayerFCView1;
            nextSelector4 = 15;
            if (rawValue2)
                goto select;
            Anim33Call49688View1();
            return;
        case 53:
        case 54:
            if (Anim33Call40994View1())
                return;
            nextSelector4 = 0;
            goto select;
        case 19:
            if (Anim33Call40994View2())
                return;
            rawValue2 = 13;
            rawValue3 = Anim33Data6E344View1;
            if (rawValue3 == rawValue2) {
                rawValue2 = Anim33Data6C514View1;
                nextSelector4 = 17;
                if (rawValue2)
                    goto select;
            }
            nextSelector4 = (int)Anim33Player0View1;
            rawValue2 = Anim33ApproximatePlanarDistanceView1((void*)nextSelector4,
                                                             (void*)(nextSelector4 + 348));
            rawValue3 = Anim33Player158View1;
            rawValue3 = rawValue3 < rawValue2;
            nextSelector4 = 17;
            if (!rawValue3)
                return;
            goto select;
        case 21:
            if (Anim33Player54View1 < 33)
                return;
            if (!Anim33PlayerB8View1) {
                Anim33Call4BEF8View1(4);
                Anim33Player4CView1 = 1;
                return;
            }
            rawValue2 = Anim33PlayerBCView1;
            nextSelector4 = 7;
            if (rawValue2)
                return;
            goto select;
        case 28:
            if (Anim33Player1B5View1 && (Anim33Data6E53CView1 & 64))
                Anim33Player1B6View1 = 1;
            if (!Anim33PlayerB8View1 && Anim33Player54View1 >= 16 && Anim33PlayerE4View1 < 23) {
                rawValue3 = Anim33PlayerCCView1;
                rawValue2 = Anim33Player8CView1;
                product5 = rawValue3 * rawValue2;
                rawValue3 = Anim33PlayerD0View1;
                rawValue2 = Anim33Player90View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = Anim33PlayerD4View1;
                rawValue2 = Anim33Player94View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                if (rawValue2 < 0) {
                    if (Anim33PlayerACView1) {
                        rawValue3 = Anim33PlayerB0View1;
                        if (rawValue3 >= 3841) {
                            __asm__ volatile("" ::"i"(0x8009C67C) : "memory");
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
                    rawValue2 = Anim33PlayerB0View1 < 1920;
                    nextSelector4 = 0;
                    if (rawValue2)
                        goto select;
                    MATCHING_BARRIER_VOLATILE("memory");
                    nextSelector4 = 4;
                    goto select;
                }
            }
            rawValue2 = Anim33Data6E538View1 & 128;
            if (rawValue2 && Anim33Player4CView1 == 1) {
                nextSelector4 = 22;
                goto select;
            }
            if (Anim33Player1B5View1 && Anim33Player1B6View1) {
                rawValue3 = Anim33Player4CView1;
                rawValue2 = 1;
                nextSelector4 = 17;
                if (rawValue3 != rawValue2)
                    return;
                goto select;
            }
            rawValue3 = Anim33Player4CView1;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33PlayerA0View1 < -6400;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            if (Anim33Player54View1 >= 91)
                goto select;
            return;
        case 33:
            if (Anim33Call40994View3())
                return;
            savedPointer17 = &Anim33PlayerB8View3;
            MATCHING_KEEP(savedPointer17);
            if (!*savedPointer17) {
                if (Anim33PlayerE4View3 >= 23)
                    Anim33Call4BEF8View3(7);
                if (Anim33PlayerACView3 > 0) {
                    rawValue3 = Anim33PlayerB0View3;
                    rawValue2 = rawValue3 < 3841;
                    if (!rawValue2) {
                        MATCHING_BARRIER_VOLATILE("memory");
                        __asm__ volatile("" ::"i"(0x8009C7E4) : "memory");
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
                rawValue2 = Anim33PlayerB0View3 < 1920;
                nextSelector4 = 0;
                if (rawValue2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 4;
                goto select;
            }
            savedPointer16 = &Anim33Data6E53CView3;
            MATCHING_KEEP(savedPointer16);
            rawValue2 = *savedPointer16 & 128;
            nextSelector4 = 22;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Call43194View1(4);
            nextSelector4 = 47;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33PlayerBCView2;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33Player1BCView1;
            nextSelector4 = 17;
            if (!rawValue2)
                goto select;
            rawValue2 = *savedPointer16 & 16;
            nextSelector4 = 18;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)savedPointer17 - 32;
            rawValue2 = Anim33MeasureVectorLengthView1((void*)nextSelector4, 1);
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Player148View1 < 2;
            nextSelector4 = 35;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33Player4CView2;
            nextSelector4 = 34;
            if (rawValue2)
                goto select;
            rawValue3 = Anim33Player60View1;
            rawValue2 = rawValue3 < 365;
            if (!rawValue2)
                goto select;
            rawValue2 = rawValue3 < -364;
            nextSelector4 = 35;
            if (!rawValue2)
                return;
            goto select;
        case 34:
            if (Anim33Call40994View3())
                return;
            savedPointer17 = &Anim33PlayerB8View3;
            MATCHING_KEEP(savedPointer17);
            if (!*savedPointer17) {
                if (Anim33PlayerE4View3 >= 23)
                    Anim33Call4BEF8View3(7);
                if (Anim33PlayerACView3 > 0) {
                    rawValue3 = Anim33PlayerB0View3;
                    rawValue2 = rawValue3 < 3841;
                    if (!rawValue2) {
                        MATCHING_BARRIER_VOLATILE("memory");
                        __asm__ volatile("" ::"i"(0x8009C964) : "memory");
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
                rawValue2 = Anim33PlayerB0View3 < 1920;
                nextSelector4 = 0;
                if (rawValue2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 4;
                goto select;
            }
            savedPointer16 = &Anim33Data6E53CView3;
            MATCHING_KEEP(savedPointer16);
            rawValue2 = *savedPointer16 & 128;
            nextSelector4 = 22;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Call43194View1(4);
            nextSelector4 = 47;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33PlayerBCView2;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33Player1BCView1;
            nextSelector4 = 17;
            if (!rawValue2)
                goto select;
            rawValue2 = *savedPointer16 & 16;
            nextSelector4 = 18;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)savedPointer17 - 32;
            rawValue2 = Anim33MeasureVectorLengthView1((void*)nextSelector4, 1);
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Player148View1 < 2;
            nextSelector4 = 35;
            if (!rawValue2)
                goto select;
            if (Anim33Player60View1 >= 256)
                return;
            rawValue2 = Anim33Player4CView2;
            nextSelector4 = 33;
            if (rawValue2)
                return;
            goto select;
        case 35:
            if (Anim33Call40994View3())
                return;
            savedPointer17 = &Anim33PlayerB8View3;
            MATCHING_KEEP(savedPointer17);
            if (!*savedPointer17) {
                if (Anim33PlayerE4View3 >= 23)
                    Anim33Call4BEF8View3(7);
                if (Anim33PlayerACView3 > 0) {
                    rawValue3 = Anim33PlayerB0View3;
                    rawValue2 = rawValue3 < 3841;
                    if (!rawValue2) {
                        __asm__ volatile("" ::"i"(0x8009CADC) : "memory");
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
                rawValue2 = Anim33PlayerB0View3 < 1920;
                nextSelector4 = 0;
                if (rawValue2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 4;
                goto select;
            }
            savedPointer16 = &Anim33Data6E53CView3;
            MATCHING_KEEP(savedPointer16);
            rawValue2 = *savedPointer16 & 128;
            nextSelector4 = 22;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Call43194View1(4);
            nextSelector4 = 47;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33PlayerBCView2;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33Player1BCView1;
            nextSelector4 = 17;
            if (!rawValue2)
                goto select;
            rawValue2 = *savedPointer16 & 16;
            nextSelector4 = 18;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)savedPointer17 - 32;
            rawValue2 = Anim33MeasureVectorLengthView1((void*)nextSelector4, 1);
            rawValue2 = rawValue2 < 1024;
            nextSelector4 = 7;
            if (rawValue2)
                goto select;
            if (Anim33Player148View1 >= 2)
                return;
            rawValue2 = Anim33Player4CView2;
            nextSelector4 = 34;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Player60View1 < -255;
            nextSelector4 = 33;
            if (rawValue2)
                return;
            goto select;
        case 47:
            if (Anim33Call40994View1())
                return;
            if (Anim33Data6E53CView1 & 64) {
                rawValue2 = Anim33Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (rawValue2)
                    goto specialJump;
                MATCHING_BARRIER_VOLATILE("memory");
                goto select;
            }
            rawValue2 = Anim33PlayerACView1;
            nextSelector4 = 50;
            if (!rawValue2)
                return;
            goto select;
        case 50:
            if (Anim33Call40994View1())
                return;
            if (Anim33Data6E53CView1 & 64) {
                rawValue2 = Anim33Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (rawValue2)
                    goto specialJump;
                goto select;
            }
            rawValue2 = Anim33PlayerACView1;
            nextSelector4 = 47;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerA0View1;
            rawValue3 = Anim33PlayerB4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < rawValue3;
            if (!rawValue2)
                return;
            rawValue2 = Anim33PlayerA4View1;
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
            if (Anim33Call40994View1())
                return;
            if (Anim33Data6E53CView1 & 64) {
                rawValue2 = Anim33Data6E538View1 & 16384;
                nextSelector4 = 6;
                if (!rawValue2)
                    goto select;
            specialJump:
                Anim33Call4BEF8View1(7);
                rawValue2 = 3;
                Anim33Player4CView1 = rawValue2;
                return;
            }
            rawValue2 = Anim33PlayerACView1;
            nextSelector4 = 47;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerA0View1;
            rawValue3 = Anim33PlayerB4View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < rawValue3;
            nextSelector4 = 50;
            if (rawValue2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto select;
        case 58:
            if (Anim33Player54View1 < 137)
                return;
        call498C0:
            Anim33Call498C0View1();
            return;
        case 115:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne115;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground115;
        airborne115:
            __asm__ volatile("" ::"i"(0x8009CE10) : "memory");
            nextSelector4 = 119;
            goto select;
        ground115:
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input115;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input115:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim33Data6E044View2;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim33Data6E044View2;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim33PlayerA8View2;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerACView2;
            if (rawValue2)
                goto select;
            rawValue2 = 25;
            rawValue3 = Anim33Field(record16, int*, 0x4C);
            nextSelector4 = 126;
            if (rawValue3 != rawValue2)
                return;
            goto select;
        case 116:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne116;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground116;
        airborne116:
            __asm__ volatile("" ::"i"(0x8009CF4C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground116:
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload116;
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload116:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim33Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input116:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009CFE4) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim33Data6E535View1;
            if (!rawValue2)
                goto afterLatch116;
            rawValue2 = Anim33PlayerB0View2;
            if (!rawValue2)
                goto latch116;
            rawValue2 = 40;
            rawValue3 = Anim33Data6E044View2;
            if (rawValue3 != rawValue2)
                goto afterLatch116;
        latch116:
            __asm__ volatile("" ::"i"(0x8009D030) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch116:
            rawValue2 = Anim33PlayerB4View2 < 3073;
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Call55E84View1((void*)nextSelector4);
            rawValue2 = rawValue2 < 37;
            nextSelector4 = 117;
            if (rawValue2)
                return;
            goto select;
        case 117:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne117;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground117;
        airborne117:
            __asm__ volatile("" ::"i"(0x8009D0C8) : "memory");
            nextSelector4 = 119;
            goto select;
        ground117:
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload117;
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload117:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim33Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input117:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009D160) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim33Data6E535View1;
            if (!rawValue2)
                goto afterLatch117;
            rawValue2 = Anim33PlayerB0View2;
            if (!rawValue2)
                goto latch117;
            rawValue2 = 40;
            rawValue3 = Anim33Data6E044View2;
            if (rawValue3 != rawValue2)
                goto afterLatch117;
        latch117:
            __asm__ volatile("" ::"i"(0x8009D1AC) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch117:
            rawValue2 = Anim33PlayerB4View2 < 2560;
            if (!rawValue2)
                return;
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009D200) : "memory");
            goto select;
        case 118:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim33Player54View2 < 16;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim33PlayerCCView2;
            rawValue2 = Anim33Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim33PlayerD0View2;
            rawValue2 = Anim33Player90View2;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim33PlayerD4View2;
            rawValue2 = Anim33Player94View2;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009D2F0) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim33PlayerACView2;
            nextSelector4 = 120;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x8009D32C) : "memory");
            nextSelector4 = 117;
            goto select;
        private118:
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        finish118:
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009D3A0) : "memory");
            goto preserveAge;
        case 119:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2;
            rawValue3 = 2;
            if (rawValue2)
                goto other119;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009D414) : "memory");
                nextSelector4 = 131;
                goto effect119;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto effect119;
            rawValue2 = Anim33PlayerACView2;
            if (rawValue2)
                goto distance119;
            nextSelector4 = 120;
            goto effect119;
        distance119:
            rawValue2 = Anim33PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto effect119;
            nextSelector4 = 117;
        effect119:
            Anim33Call4BEF8View2(nextSelector4);
            {
                register int (*spawn2)(int, int, void*, int) __asm__("$2") =
                    Anim33DataSpawnParticleView1;
                if (spawn2)
                    spawn2(8, 33, 0, 2);
            }
            rawValue2 = (int)Anim33Data6C654View1;
            product5 = 0;
            nextSelector4 = Anim33Field((void*)rawValue2, unsigned char*, 0x12);
            Anim33CallPlaySoundView1((unsigned char)nextSelector4, product5, 0);
            rawValue2 = Anim33Player58View1 < 24;
            if (rawValue2)
                return;
            rawValue2 = 120;
            Anim33Data6E530View1 = rawValue2;
            rawValue2 = 15;
            Anim33Data6E52CView1 = rawValue2;
            return;
        other119:
            rawValue2 = 2;
            rawValue3 = Anim33Player50View1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                return;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            if (!rawValue2)
                return;
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 130;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009D520) : "memory");
            goto select;
        case 120:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33PlayerB8View2 < 4;
            nextSelector4 = 119;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input120;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input120:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009D5D0) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim33Data6E535View1;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Data6E53CView2 & 32;
            nextSelector4 = 115;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009D640) : "memory");
            goto select;
        case 121:
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto done121;
        done121:
            rawValue2 = Anim33Player280View1;
            if (rawValue2 < 0) {
                nextSelector4 = 128;
                goto select;
            }
            rawValue2 = Anim33PlayerB8View2;
            nextSelector4 = 115;
            if (!rawValue2)
                goto select;
            nextSelector4 = 119;
            goto select;
        case 122:
            rawValue2 = Anim33Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne122;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground122;
        airborne122:
            __asm__ volatile("" ::"i"(0x8009D700) : "memory");
            nextSelector4 = 119;
            goto select;
        ground122:
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 123;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009D73C) : "memory");
            goto select;
        case 123:
            rawValue2 = Anim33Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne123;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground123;
        airborne123:
            __asm__ volatile("" ::"i"(0x8009D790) : "memory");
            nextSelector4 = 119;
            goto select;
        ground123:
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 124;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009D7B0) : "memory");
            goto select;
        case 124:
            rawValue2 = Anim33Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne124;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground124;
        airborne124:
            __asm__ volatile("" ::"i"(0x8009D804) : "memory");
            nextSelector4 = 119;
            goto select;
        ground124:
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009D840) : "memory");
            goto select;
        case 126:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne126;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground126;
        airborne126:
            __asm__ volatile("" ::"i"(0x8009D89C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground126:
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input126;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input126:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim33Data6E044View2;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim33Data6E044View2;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim33PlayerA8View2;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerACView2;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009D9A0) : "memory");
            goto select;
        case 128:
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto helper128;
        helper128:
            Anim33Call498C0View2((void*)nextSelector4);
            return;
        case 129:
            rawValue2 = Anim33Data6E53CView2 & 64;
            if (rawValue2) {
                rawValue2 = 1;
                Anim33Player1B6View2 = rawValue2;
            }
            nextSelector4 = (int)&Anim33Player280View1;
            rawValue2 = *(int*)nextSelector4;
            if (rawValue2 < 0) {
                rawValue2 = 36863;
                rawValue3 = Anim33Player144View1;
                rawValue2 = rawValue2 < rawValue3;
                if (!rawValue2)
                    return;
                rawValue2 = -1;
                Anim33Player28CView1 = rawValue2;
                Anim33Call498C0View2((void*)nextSelector4);
                return;
            }
            rawValue3 = Anim33Player54View2;
            rawValue2 = rawValue3 < 61;
            if (!rawValue2) {
                rawValue2 = -1;
                *(int*)nextSelector4 = rawValue2;
                return;
            }
            rawValue2 = rawValue3 < 16;
            if (rawValue2)
                return;
            rawValue2 = Anim33Player1B6View2;
            if (!rawValue2)
                return;
            product5 = Anim33Player28CView1;
            nextSelector4 = 118;
            if (product5 < 0)
                goto select;
            nextSelector4 = Anim33Player290View1;
            rawValue2 = Anim33Call3BF6CView1(nextSelector4, product5);
            if (rawValue2) {
                nextSelector4 = Anim33Player28CView1;
                Anim33Call3BE70View1(nextSelector4);
            }
            rawValue2 = -1;
            Anim33Player28CView1 = rawValue2;
            nextSelector4 = 118;
            goto select;
        case 130:
            rawValue2 = Anim33Data7431CView1(1);
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim33Player250View1;
            rawValue2 = Anim33Player48View3;
            rawValue3 = Anim33Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                goto other130;
            rawValue2 = Anim33Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                goto other130;
            }
            goto completed130;
        completed130:
            rawValue2 = Anim33PlayerB8View2;
            if (rawValue2)
                goto preserveAge;
            rawValue2 = Anim33Data6E535View1;
            if (rawValue2)
                goto latch130;
            rawValue2 = Anim33PlayerB4View2 < 2560;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x8009DB74) : "memory");
            nextSelector4 = 117;
            goto select;
        latch130:
            __asm__ volatile("" ::"i"(0x8009DB7C) : "memory");
            nextSelector4 = 115;
            goto select;
        preserveAge:
            savedWord16 = Anim33Player54View2;
            Anim33Call4BEF8View2(119);
            Anim33Player54View2 = savedWord16;
            return;
        other130:
            nextSelector4 = (int)&Anim33Player50View1;
            rawValue3 = *(int*)nextSelector4;
            rawValue2 = 2;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2;
            if (rawValue2)
                return;
            rawValue2 = 1;
            *(int*)nextSelector4 = rawValue2;
            goto select116;
        case 131:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne131;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground131;
        airborne131:
            __asm__ volatile("" ::"i"(0x8009DC2C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground131:
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload131;
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload131:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim33Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input131:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 4;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim33Data6E535View1;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerB0View2;
            if (!rawValue2)
                goto latch131;
            rawValue2 = 40;
            rawValue3 = Anim33Data6E044View2;
            if (rawValue3 != rawValue2)
                goto select;
        latch131:
            __asm__ volatile("" ::"i"(0x8009DD08) : "memory");
            nextSelector4 = 115;
            goto select;
        case 132:
            rawValue2 = (int)Anim33Player250View1;
            callback3 = Anim33Data7431CView1;
            record16 = Anim33Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim33PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne132;
            rawValue2 = Anim33PlayerE4View2 < 23;
            if (rawValue2)
                goto ground132;
        airborne132:
            __asm__ volatile("" ::"i"(0x8009DD64) : "memory");
            nextSelector4 = 119;
            goto select;
        ground132:
            rawValue2 = Anim33Data6E53CView2 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim33Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload132;
            rawValue2 = Anim33Data6E538View2 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload132:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim33Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim33Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input132:
            rawValue2 = Anim33Data6E538View2;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 4;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 8;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 131;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim33Data6E535View1;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim33PlayerB0View2;
            if (!rawValue2)
                goto latch132;
            rawValue2 = 40;
            rawValue3 = Anim33Data6E044View2;
            if (rawValue3 != rawValue2)
                goto select;
        latch132:
            __asm__ volatile("" ::"i"(0x8009DE40) : "memory");
            nextSelector4 = 115;
            goto select;
        default:
            return;
    }
select116:
    nextSelector4 = 116;
select:
    Anim33Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim33Field
