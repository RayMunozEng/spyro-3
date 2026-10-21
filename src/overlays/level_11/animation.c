#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008B6A0.
 * Assembly SHA256 bebbc07f687311156e44cf0fcac0e515c97dbd547925f63a02e6ba7adf5f6cc7.
 * AI-generated; not human reviewed. All2660 original instructions,
 * 59 selectors (bias19) and one owned padding word are required.
 * Frame0x1B0 retains scratch10..184, savedS0..S7, slotS2 and combinedS7.
 * Seventeen exact groups reuse verified12/21/32/42. Three near groups retain
 * every original stack/address/register/field mapping and actual branch join.
 * State36/37/48 reuses22 with original signed /48 and /60 in ordinary C,
 * original matrix halfwords38/3A/3C, mode4 argument production and guarded
 * scalar stores. The final clamp belongs to36 at8008C500.
 * States66/69 and71 share the original vector argument tail at8008D900;
 * original66 omits42's independent vector call, and71 uses A2-relative -20.
 * The complete65..77 source family retains every concrete Rev0 difference.
 * Typed aliases remain distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Identified Rev1 Sheila tables and skateboard arithmetic support source
 * interpretation; original Rev0 words and full retail hashes remain required.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, conditional/internal target,
 * selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics11Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics11Call363DCView1() __asm__("func_800363DC");
unsigned char Physics11Call40D10View1() __asm__("func_80040D10");
unsigned char Physics11Call41580View1() __asm__("func_80041580");
unsigned char Physics11Call416F4View1() __asm__("func_800416F4");
unsigned char Physics11Call417FCView1() __asm__("func_800417FC");
unsigned char Physics11Call41B64View1() __asm__("func_80041B64");
int Physics11InterpolateSineView1() __asm__("func_8004E9E4");
int Physics11InterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char Physics11TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics11MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics11ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics11ClearVectorView1() __asm__("func_8004F168");
unsigned char Physics11CopyVectorView1() __asm__("func_8004F178");
unsigned char Physics11AddVectorView1() __asm__("func_8004F194");
unsigned char Physics11SubtractVectorView1() __asm__("func_8004F1C8");
int Physics11CallRandView1() __asm__("rand");
extern unsigned char Physics11Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics11Data65920View1 __asm__("D_80065920");
extern void* Physics11Data6C570View1 __asm__("D_8006C570");
extern int Physics11Data6C640View1 __asm__("D_8006C640");
extern int Physics11Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics11Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics11Player0View1 __asm__("D_80070328");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics11Call40D10View2() __asm__("func_80040D10");
int Physics11Call41580View2() __asm__("func_80041580");
int Physics11Call416F4View2() __asm__("func_800416F4");
int Physics11Call417FCView2() __asm__("func_800417FC");
int Physics11Call41848View1() __asm__("func_80041848");
int Physics11Call41B64View2() __asm__("func_80041B64");
int Physics11MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics11ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics11ClearVectorView2() __asm__("func_8004F168");
int Physics11CopyVectorView2() __asm__("func_8004F178");
int Physics11AddVectorView2() __asm__("func_8004F194");
int Physics11SubtractVectorView2() __asm__("func_8004F1C8");
extern int Physics11Data6E044View2 __asm__("D_8006E044");
extern int Physics11Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics11Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics11PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics11Player94View1 __asm__("D_80070328+0x94");
extern int Physics11PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics11Player80View1 __asm__("D_80070328+0x80");
extern int Physics11PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics11Player64View1 __asm__("D_80070328+0x64");
extern int Physics11Player88View1 __asm__("D_80070328+0x88");
extern int Physics11Player84View1 __asm__("D_80070328+0x84");
extern int Physics11Player144View1 __asm__("D_80070328+0x144");
extern int Physics11Player60View1 __asm__("D_80070328+0x60");
extern int Physics11PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics11Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics11Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics11PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics11PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics11Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics11Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics11Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics11Player101View1 __asm__("D_80070328+0x101");
extern int Physics11PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics11MeasureVectorLengthView3() __asm__("func_8004EDE8");
int Physics11ScaleVectorRatioQ15View3() __asm__("func_8004F08C");
int Physics11CopyVectorView3() __asm__("func_8004F178");
int Physics11AddVectorView3() __asm__("func_8004F194");
int Physics11SubtractVectorView3() __asm__("func_8004F1C8");
extern unsigned char Physics11Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics11Data65920View2 __asm__("D_80065920");
extern int Physics11Data6C514View1 __asm__("D_8006C514");
extern int Physics11Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics11Player0View3 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics11Player16CView1 __asm__("D_80070328+0x16C");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics11PlayerE4View1 __asm__("D_80070328+0xE4");
int Physics11Call40D10View3() __asm__("func_80040D10");
int Physics11Call410F8View1() __asm__("func_800410F8");
int Physics11Call41580View3() __asm__("func_80041580");
int Physics11Call417FCView3() __asm__("func_800417FC");
int Physics11Call41848View2() __asm__("func_80041848");
int Physics11Call41B64View3() __asm__("func_80041B64");
int Physics11InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics11TransformVectorByBasisView2() __asm__("func_8004ED6C");
int Physics11ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics11ClearVectorView3() __asm__("func_8004F168");
int Physics11CopyVectorView4() __asm__("func_8004F178");
int Physics11AddVectorView4() __asm__("func_8004F194");
int Physics11CallRandView2() __asm__("rand");
extern int* Physics11Data6C570View2 __asm__("D_8006C570");
extern int Physics11Data6C640View2 __asm__("D_8006C640");
extern int Physics11Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics11Player0View4 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics11Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics11Player158View1 __asm__("D_80070328+0x158");
extern int Physics11Player20CView2 __asm__("D_80070328+0x20C");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern unsigned char Physics11Player0View5 __asm__("D_80070328");
int Physics11Call40F48View1() __asm__("func_80040F48");
int Physics11Call417FCView4() __asm__("func_800417FC");
int Physics11Call41848View3() __asm__("func_80041848");
int Physics11Call4E56CView1() __asm__("func_8004E56C");
int Physics11PlanarHeadingLookupView1() __asm__("func_8004E880");
int Physics11Call4ECF4View1() __asm__("func_8004ECF4");
int Physics11MeasureVectorLengthView4() __asm__("func_8004EDE8");
int Physics11ScaleVectorRatioQ15View4() __asm__("func_8004F08C");
int Physics11CopyVectorView5() __asm__("func_8004F178");
int Physics11AddVectorView5() __asm__("func_8004F194");
int Physics11SubtractVectorView4() __asm__("func_8004F1C8");
int Physics11Call4F6C4View1() __asm__("func_8004F6C4");
int Physics11Call5F35CView1() __asm__("func_8005F35C");
extern int* Physics11Data6C570View3 __asm__("D_8006C570");
extern int Physics11Data6E538View2 __asm__("D_8006E538");
extern int Physics11PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics11Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics11Player68View1 __asm__("D_80070328+0x68");
extern int Physics11Player6CView1 __asm__("D_80070328+0x6C");
extern int Physics11Player70View1 __asm__("D_80070328+0x70");
extern int Physics11PlayerA0View2 __asm__("D_80070328+0xA0");
extern int Physics11Player5CView2 __asm__("D_80070328+0x5C");
extern int Physics11Player60View2 __asm__("D_80070328+0x60");
extern int Physics11Player64View2 __asm__("D_80070328+0x64");
extern int Physics11Player164View1 __asm__("D_80070328+0x164");
extern int Physics11PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics11PlayerB8View2 __asm__("D_80070328+0xB8");
extern int Physics11Player16CView2 __asm__("D_80070328+0x16C");
extern int Physics11Player168View1 __asm__("D_80070328+0x168");
extern int Physics11Player94View2 __asm__("D_80070328+0x94");
extern int Physics11Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics11Player80View2 __asm__("D_80070328+0x80");
extern int Physics11Player90View1 __asm__("D_80070328+0x90");
extern int Physics11Player84View2 __asm__("D_80070328+0x84");
int Physics11Call41580View4() __asm__("func_80041580");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
int Physics11ShiftVectorRightTowardZeroView2() __asm__("func_8004F110");
int Physics11CopyVectorView6() __asm__("func_8004F178");
int Physics11AddVectorView6() __asm__("func_8004F194");
extern int Physics11Data6E1D4View1 __asm__("D_8006E1D4");
extern int Physics11Data6E1D8View1 __asm__("D_8006E1D8");
extern int Physics11Data6E52CView1 __asm__("D_8006E52C");
extern int Physics11Data6E530View1 __asm__("D_8006E530");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics11Player250View1 __asm__("D_80070328+0x250");
extern int Physics11Player54View1 __asm__("D_80070328+0x54");
extern int Physics11PlayerD4View1 __asm__("D_80070328+0xD4");
extern void* Physics11Data6C654View1 __asm__("D_8006C654");
int Physics11DataPlaySoundView1() __asm__("PlaySound");
extern int Physics11Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics11Player90View2 __asm__("D_80070328+0x90");
extern void* (*Physics11_SpawnParticle)() __asm__("SpawnParticle");
int Physics11Call40954View1() __asm__("func_80040954");
extern int Physics11Data6C700View1 __asm__("D_8006C700");
extern int Physics11Player10CView1 __asm__("D_80070328+0x10C");
void func_level_11_8008B6A0(int slotIndex) {
    register void* fieldA4State28 __asm__("$16");
    register void* vector8CState28 __asm__("$17");
    register int signedWord19 __asm__("$19");
    register int signedWord20 __asm__("$20");
    register int signedWord21 __asm__("$21");
    register void* savedPointer22 __asm__("$22");
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
            sp154, sp158, sp15C, sp160, sp164, sp168, sp16C, sp170, sp174, sp178, sp17C, sp180,
            sp184;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$23");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldB8PointerState1A __asm__("$16");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    void* temp_v0_7;
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
    globalPointer = &Physics11Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics11Data6C570View1 = (void*)workWord2;
    workWord2 = Physics11Field(&Physics11Player0View1, int*, 0x54);
    stateWord3 = Physics11Field(&Physics11Player0View1, int*, 0x48);
    combinedIndex = workWord2 + savedSlotIndex;
    switch (stateWord3) {
        case 20:
            globalVector80 = &Physics11Player0View1 + 0x80;
            Physics11ClearVectorView1(globalVector80);
            Physics11ClearVectorView1(globalVector80 + 0xC);
            if (Physics11Data6E044View1 != 7) {
                Physics11Call40D10View1(0x1200);
                Physics11Call416F4View1();
                Physics11Call41580View1(0x5A, 0x10);
                return;
            }
            return;
        default:
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
            workWord3 = Physics11Data6E344View1;
            workWord2 = 13;
            if (workWord3 == workWord2) {
                workWord2 = Physics11Data6C514View1;
                if (workWord2)
                    return;
            }
            vectorAt30 = &Physics11Player0View3 + 8;
            workWord3 = Physics11Field(vectorAt30, int*, 0);
            workWord2 = Physics11Field(&Physics11Player0View3, int*, 0x144);
            numeric4 = workWord3 - workWord2;
            workWord2 = numeric4 < 1024;
            if (!workWord2)
                goto beyond19;
            workWord2 = Physics11Player94View1;
            workWord2 += 128;
            Physics11Player94View1 = workWord2;
            workWord2 = workWord2 < 4801;
            __asm__("" : "=r"(numeric4) : "0"(numeric4), "r"(workWord2));
            if (!workWord2) {
                workWord2 = 4800;
                Physics11Player94View1 = workWord2;
            }
            product19 = numeric4 * numeric4;
            call4 = &originalFrame.sp10;
            workWord3 = Physics11Field(&Physics11Player0View3, int*, 0x148);
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(workWord2, workWord3, call4, "memory");
            workWord2 = product19 >> 11;
            angle16 = workWord2 + workWord3;
            Physics11Player64View1 = angle16;
            __asm__ volatile("" : "=r"(vectorAt30) : "0"(vectorAt30), "r"(call4) : "memory");
            Physics11CopyVectorView3(call4, vectorAt30 + 340);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics11SubtractVectorView3(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics11MeasureVectorLengthView3(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8008B84C) : "memory");
            numeric6 = 1024;
            goto limit19;
        beyond19:
            numeric5 = Physics11Field(&Physics11Player0View3, int*, 0x14C);
            workWord2 = workWord3 - numeric5;
            workWord2 = workWord2 < -1024;
            numeric6 = numeric5 - workWord3;
            if (!workWord2)
                goto curve19;
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x8008B870));
            workWord2 = Physics11Player4CView1;
            workWord3 = 1;
            if (!workWord2) {
                workWord2 = Physics11Field(&Physics11Player0View3, int*, 0x148);
                Physics11Player4CView1 = workWord3;
                workWord2 += 512;
                Physics11Field(&Physics11Player0View3, int*, 0x148) = workWord2;
            }
            workWord2 = Physics11Player94View1;
            workWord2 += 128;
            Physics11Player94View1 = workWord2;
            workWord2 = workWord2 < 4801;
            if (!workWord2)
                Physics11Player94View1 = 4800;
            workWord2 = Physics11Field(&Physics11Player0View3, int*, 0x150);
            numeric6 = numeric4 - 1024;
            workWord3 = workWord2 * numeric6;
            workWord2 = Physics11Field(&Physics11Player0View3, int*, 0x154);
            workWord2 = workWord3 / workWord2;
            call4 = &originalFrame.sp10;
            workWord3 = Physics11Field(&Physics11Player0View3, int*, 0x148);
            angle16 = workWord3 + workWord2;
            workWord2 = (numeric6 << 10) >> 10;
            workWord2 = angle16 + workWord2;
            angle16 = workWord2 & 4095;
            Physics11Player64View1 = angle16;
            Physics11CopyVectorView3(call4, vectorAt30 + 340);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics11SubtractVectorView3(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics11MeasureVectorLengthView3(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8008B980) : "memory");
            numeric6 = 1024;
            goto limit19;
        curve19:
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x8008B988));
            workWord2 = (numeric6 * 4800) >> 10;
            Physics11Player94View1 = workWord2;
            workWord2 = Physics11Player16CView1;
            numeric7 = Physics11Field(&Physics11Player0View3, int*, 0x168);
            workWord3 = Physics11Field(&Physics11Player0View3, int*, 0x158);
            workWord2 &= 127;
            numeric4 = numeric7 << 1;
            Physics11Player16CView1 = workWord2;
            workWord2 = *(short*)(&Physics11Data65920View2 + numeric4);
            workWord3 += 1024;
            product10 = workWord3 * workWord2;
            square8 = numeric6 * numeric6;
            workWord2 = product10 >> 12;
            originalFrame.sp10 = workWord2;
            workWord2 = *(short*)(&Physics11Data658A0View2 + numeric4);
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
            Physics11AddVectorView3(call4, call5, numeric6, numeric7);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics11Player64View1 = angle16;
            Physics11SubtractVectorView3(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics11MeasureVectorLengthView3(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 2049;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            numeric6 = 2048;
        limit19:
            Physics11ScaleVectorRatioQ15View3(call4, call5, numeric6);
        commit19:
            workWord2 = originalFrame.sp10;
            workWord3 = originalFrame.sp14;
            Physics11Field(&Physics11Player0View3, int*, 0x8C) = workWord2;
            Physics11Field(&Physics11Player0View3, int*, 0x90) = workWord3;
            return;
        }
        case 21:
            raw22_temp_v0_6 = Physics11Field(&Physics11Player0View5, int*, 0x94) - 0x140;
            Physics11Field(&Physics11Player0View5, int*, 0x94) = raw22_temp_v0_6;
            if (raw22_temp_v0_6 < -0x2300) {
                Physics11Field(&Physics11Player0View5, int*, 0x94) = -0x2300;
            }
            Physics11Field(&Physics11Player0View5, int*, 0xA4) = Physics11PlanarHeadingLookupView1(
                Physics11Field(&Physics11Player0View5, int*, 0x8C),
                Physics11Field(&Physics11Player0View5, int*, 0x90), 1);
            Physics11Call41580View4(0x5A, 0x10);
            return;
        case 26:
            globalFieldB8PointerState1A = &Physics11Player0View3 + 0xB8;
            if (Physics11Field(&Physics11Player0View3, int*, 0xB8) != 0) {
                raw34_temp_v0_8 = Physics11Field(&Physics11Player0View3, int*, 0x94) - 0x600;
                Physics11Field(&Physics11Player0View3, int*, 0x94) = raw34_temp_v0_8;
                if (raw34_temp_v0_8 < -0x2300) {
                    Physics11Field(&Physics11Player0View3, int*, 0x94) = -0x2300;
                }
                Physics11CopyVectorView3(globalFieldB8PointerState1A - 0x38,
                                         globalFieldB8PointerState1A - 0x2C);
                return;
            }
            goto block_154;
        case 32:
            globalFieldB8PointerState20 = &Physics11Player0View1 + 0xB8;
            if (Physics11Field(&Physics11Player0View1, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp20;
                Physics11ClearVectorView1(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics11SubtractVectorView1(call4, call5, globalVector8CState20);
                originalFrame.sp28 = 0;
                temp_v0_6 = Physics11MeasureVectorLengthView1(&originalFrame.sp20, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics11ScaleVectorRatioQ15View1(&originalFrame.sp20, temp_v0_6, 0x40);
                }
                originalFrame.sp28 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics11AddVectorView1(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp20);
                Physics11CopyVectorView1(globalVector8CState20, globalVector80State20);
            } else {
                Physics11ClearVectorView1(globalFieldB8PointerState20 - 0x38);
                Physics11ClearVectorView1(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics11Field(&Physics11Player0View1, int*, 0x94) < -0x2300) {
                Physics11Field(&Physics11Player0View1, int*, 0x94) = -0x2300;
            }
            if ((Physics11Field(&Physics11Player0View1, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics11Data6C640View1 & 1)) {
                originalFrame.sp30 = 0;
                originalFrame.sp34 = 0;
                originalFrame.sp38 = 0xE;
                Physics11CopyVectorView1(&originalFrame.sp40,
                                         (&Physics11Player0View1 + 0x94) - 0x94);
                originalFrame.sp40 += Physics11Call363DCView1(0, 0x12C);
                originalFrame.sp44 += Physics11Call363DCView1(0, 0x12C);
                originalFrame.sp48 += Physics11Call363DCView1(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp40, &originalFrame.sp30);
                Physics11Field(temp_v0_7, signed char*, 2) = 6;
                Physics11Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 0x24:
        case 0x25:
        case 48: {
            register int limit16 __asm__("$16");
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics11Call40F48View1(&originalFrame.sp30, 0);
            workWord2 = originalFrame.sp30;
            call5 = &Physics11PlayerA8View2;
            workWord3 = workWord2 * 9;
            workWord3 <<= 2;
            workWord2 -= workWord3;
            workWord3 = Physics11Field(call5, int*, 0);
            numeric4 = workWord2 >> 7;
            workWord2 = workWord3 < numeric4;
            if (workWord2) {
                workWord2 = workWord3 + 8;
                Physics11Field(call5, int*, 0) = workWord2;
                workWord2 = numeric4 < workWord2;
            } else {
                workWord2 = workWord3 - 8;
                Physics11Field(call5, int*, 0) = workWord2;
                workWord2 = workWord2 < numeric4;
            }
            if (workWord2)
                Physics11Field(call5, int*, 0) = numeric4;
            workWord3 = Physics11Player4CView2;
            workWord2 = 5;
            if (workWord3 == workWord2) {
                workWord3 = Physics11Player68View1;
                numeric4 = Physics11Player6CView1;
                workWord2 = (workWord3 << 5) >> 9;
                workWord3 -= workWord2;
                workWord2 = (numeric4 << 5) >> 9;
                Physics11Player68View1 = workWord3;
                workWord3 = originalFrame.sp30;
                numeric4 -= workWord2;
                Physics11Player6CView1 = numeric4;
                numeric4 = Physics11Player70View1;
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
            workWord2 = Physics11Data6E538View2 & 16;
            if (!workWord2)
                goto default48;
            workWord2 = originalFrame.sp30;
            numeric4 = Physics11Player68View1;
            numeric5 = Physics11Player6CView1;
            workWord3 = (workWord2 * 48) >> 8;
            workWord2 = (numeric4 << 5) >> 9;
            workWord3 -= workWord2;
            workWord2 = originalFrame.sp34;
            numeric4 += workWord3;
            Physics11Player68View1 = numeric4;
            numeric4 = Physics11Player70View1;
            workWord3 = (workWord2 * 48) >> 8;
            workWord2 = (numeric5 << 5) >> 9;
            workWord3 -= workWord2;
            numeric5 += workWord3;
            workWord2 = (numeric4 << 5) >> 9;
            Physics11Player6CView1 = numeric5;
            numeric4 -= workWord2;
            goto store70;
        default48:
            globalVector80 = &Physics11PlayerA8View2;
            call4 = globalVector80 - 16;
            workWord2 = Physics11Field(globalVector80, int*, 0);
            call5 = 0;
            workWord2 = -workWord2;
            signedWord20 = workWord2 << 3;
            workWord2 = Physics11MeasureVectorLengthView4(call4, call5);
            call4 = (void*)workWord2;
            call5 = (void*)Physics11PlayerA0View2;
            workWord2 = Physics11PlanarHeadingLookupView1(call4, call5, 1);
            signedWord19 = workWord2 & 4095;
            workWord2 = signedWord19 < 2049;
            if (!workWord2) {
                signedWord19 -= 4096;
                workWord2 = signedWord19 < -256;
            } else
                workWord2 = signedWord19 < -256;
            if (workWord2)
                signedWord19 = -256;
            workWord2 = Physics11Player5CView2;
            workWord2 = signedWord20 - workWord2;
            signedWord20 = workWord2 & 4095;
            workWord2 = signedWord20 < 2049;
            if (!workWord2)
                signedWord20 -= 4096;
            workWord2 = Physics11Player60View2;
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
            numeric4 = Physics11Player68View1;
            signedWord21 = Physics11Field(globalVector80, int*, 0);
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
            workWord3 = signedWord19 << 2;
            Physics11Player68View1 = numeric4;
            numeric4 = Physics11Player6CView1;
            workWord3 >>= 4;
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
            workWord3 = signedWord21 << 2;
            Physics11Player6CView1 = numeric4;
            numeric4 = Physics11Player70View1;
            workWord3 >>= 4;
            workWord2 = (numeric4 << 5) >> 6;
            workWord3 -= workWord2;
            numeric4 += workWord3;
        store70:
            Physics11Player70View1 = numeric4;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = 4;
            signedWord20 = Physics11Player68View1;
            signedWord19 = Physics11Player6CView1;
            signedWord21 = Physics11Player70View1;
            workWord3 = Physics11Player4CView2;
            signedWord20 >>= 2;
            if (workWord3 == workWord2) {
                workWord2 = Physics11Data6E538View2 & 16;
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
            workWord2 = (unsigned int)(Physics11Player4CView2 - 4) < 2;
            globalVector80 = &originalFrame.sp38;
            if (workWord2) {
                call4 = Physics11Field(&Physics11Player0View5, void**, 0x250);
                if (call4) {
                    call4 = Physics11Field(call4, void**, 0);
                    workWord2 = Physics11Field(call4, int*, 0xF4);
                    workWord3 = Physics11Field(call4, int*, 0xFC);
                    workWord2 += signedWord20;
                    Physics11Field(call4, int*, 0xF4) = workWord2;
                    workWord2 = Physics11Field(call4, int*, 0xF8);
                    workWord3 += signedWord21;
                    Physics11Field(call4, int*, 0xFC) = workWord3;
                    workWord2 += signedWord19;
                    Physics11Field(call4, int*, 0xF8) = workWord2;
                }
            }
            call4 = globalVector80;
            globalVector8CState20 = &originalFrame.sp50;
            call5 = globalVector8CState20;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            savedPointer22 = &Physics11Player5CView2;
            workWord2 = Physics11Field(savedPointer22, int*, 0);
            workWord3 = Physics11Player64View2;
            __asm__ volatile("" ::"r"(workWord2), "r"(workWord3) : "$17", "memory");
            savedPointer17 = &originalFrame.sp68;
            Physics11Field(&originalFrame.sp38, short*, 0) = workWord2;
            workWord2 = Physics11Player60View2;
            call6 = savedPointer17;
            Physics11Field(&originalFrame.sp3C, short*, 0) = workWord3;
            workWord2 = -workWord2;
            Physics11Field(&originalFrame.sp38, short*, 2) = workWord2;
            Physics11Call4F6C4View1(call4, call5, call6);
            Physics11Call4ECF4View1(globalVector8CState20, globalVector8CState20);
            call4 = globalVector80;
            call5 = savedPointer17;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            globalVector80 = &originalFrame.sp80;
            call6 = globalVector80;
            Physics11Field(&originalFrame.sp38, short*, 0) = signedWord20;
            Physics11Field(&originalFrame.sp38, short*, 2) = signedWord19;
            Physics11Field(&originalFrame.sp3C, short*, 0) = signedWord21;
            Physics11Call4F6C4View1(call4, call5, call6);
            Physics11Call4ECF4View1(savedPointer17, savedPointer17);
            Physics11Call5F35CView1(globalVector8CState20, savedPointer17, globalVector80);
            Physics11Call4E56CView1(savedPointer22, globalVector80);
            workWord2 = Physics11Player164View1;
            if (workWord2) {
                workWord2 = 14208;
                Physics11PlayerACView2 = workWord2;
                workWord2 = 96;
                goto update16C;
            }
            workWord3 = Physics11PlayerB8View2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord3, "memory");
            workWord2 = 8192;
            Physics11PlayerACView2 = workWord2;
            call4 = savedPointer22 + 60;
            if (workWord3)
                goto queryC700;
            numeric4 = Physics11Data6C700View1;
            workWord3 = Physics11PlayerA0View2;
            Physics11PlayerACView2 = numeric4;
            limit16 = 8192;
            if (workWord3 >= 0)
                goto producerQuery;
            workWord2 = workWord3 / 48;
            __asm__ volatile("" ::"i"(0x8008C190) : "memory");
            workWord2 = numeric4 - workWord2;
            goto storeC700Difference;
        producerQuery:
            workWord2 = Physics11Call40954View1(Physics11Player10CView1);
            workWord3 = 9;
            if (workWord2 == workWord3)
                goto clampC700;
            numeric4 = Physics11PlayerA0View2;
            workWord3 = numeric4 / 60;
            workWord2 = Physics11Data6C700View1;
            workWord2 -= workWord3;
        storeC700Difference:
            Physics11Data6C700View1 = workWord2;
        clampC700:
            MATCHING_KEEP(limit16);
            workWord2 = Physics11Data6C700View1;
            workWord3 = limit16 + 7040;
            workWord2 = workWord3 < workWord2;
            if (workWord2)
                Physics11Data6C700View1 = workWord3;
            workWord2 = Physics11Data6C700View1;
            workWord3 = limit16 - 2560;
            workWord2 = workWord2 < workWord3;
            if (workWord2)
                Physics11Data6C700View1 = workWord3;
            numeric4 = Physics11Data6C700View1;
            workWord3 = limit16 - numeric4;
            workWord2 = workWord3 < 53;
            if (!workWord2) {
                workWord3 = 52;
                MATCHING_KEEP(workWord3);
                workWord2 = workWord3 < -18;
            } else
                workWord2 = workWord3 < -18;
            if (!workWord2) {
                workWord2 = numeric4 + workWord3;
                goto storeC700;
            }
            __asm__ volatile("" ::"i"(0x8008C25C) : "memory");
            workWord3 = -18;
            MATCHING_KEEP(workWord3);
            workWord2 = numeric4 + workWord3;
            goto storeC700;
        queryC700:
            workWord2 = Physics11MeasureVectorLengthView4(call4, 1);
            workWord3 = Physics11Data6C700View1;
            workWord2 -= workWord3;
            workWord2 -= 1000;
            if (workWord2 <= 0) {
                workWord2 = workWord3 + workWord2;
                goto doneC700;
            }
            workWord2 = workWord3 + workWord2;
        storeC700:
            Physics11Data6C700View1 = workWord2;
        doneC700:
            workWord2 = 0;
        update16C:
            savedPointer17 = &Physics11Player16CView2;
            numeric5 = Physics11Player168View1;
            workWord3 = Physics11Field(savedPointer17, int*, 0);
            workWord2 -= numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics11Field(savedPointer17, int*, 0) = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics11Player168View1 = numeric5;
            if (numeric5 < 0)
                Physics11Player168View1 = 0;
            workWord2 = Physics11Player168View1;
            workWord2 = workWord2 < 97;
            call4 = (void*)576;
            if (!workWord2) {
                workWord2 = 96;
                Physics11Player168View1 = workWord2;
            }
            Physics11Call417FCView4(call4, 48);
            Physics11Call41848View3();
            workWord3 = Physics11Player4CView2;
            workWord2 = 4;
            if (workWord3 != workWord2)
                goto maybeFive48;
            workWord2 = Physics11Data6E538View2 & 16;
            if (workWord2)
                goto subtract128;
            globalVector80 = &originalFrame.sp98;
            call4 = globalVector80;
            call5 = savedPointer17 - 236;
            __asm__ volatile(""
                             : "=r"(savedPointer17)
                             : "0"(savedPointer17), "r"(call4)
                             : "memory");
            savedPointer17 -= 224;
            Physics11SubtractVectorView4(call4, call5, savedPointer17);
            originalFrame.spA0 = 0;
            call5 = (void*)Physics11MeasureVectorLengthView4(globalVector80, 0);
            workWord2 = (int)call5 < 385;
            call4 = savedPointer17;
            if (!workWord2) {
                Physics11ScaleVectorRatioQ15View4(globalVector80, call5, 384);
                call4 = savedPointer17;
            }
            call5 = call4;
            Physics11AddVectorView5(call4, call5, globalVector80);
        subtract128:
            globalPointer = &Physics11Player94View2;
            workWord2 = Physics11Field(globalPointer, int*, 0);
            workWord2 -= 128;
            Physics11Field(globalPointer, int*, 0) = workWord2;
            goto clamp11;
        maybeFive48:
            workWord2 = 5;
            if (workWord3 != workWord2)
                goto gate48;
            globalVector80 = &originalFrame.spA8;
            call4 = globalVector80;
            __asm__ volatile(""
                             : "=r"(savedPointer17)
                             : "0"(savedPointer17), "r"(call4)
                             : "memory");
            savedPointer17 -= 224;
            Physics11CopyVectorView5(call4, savedPointer17);
            originalFrame.spB0 = 0;
            call5 = (void*)Physics11MeasureVectorLengthView4(globalVector80, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics11ScaleVectorRatioQ15View4(globalVector80, call5, 64);
            workWord2 = 128;
            originalFrame.spB0 = workWord2;
            call4 = savedPointer17;
            call5 = call4;
            Physics11SubtractVectorView4(call4, call5, globalVector80);
            goto clamp11;
        gate48:
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto flags48;
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto flags48;
            workWord2 = (int)Physics11Data6C570View3;
            workWord2 = Physics11Field((void*)workWord2, int*, 0) & 64;
            if (!workWord2)
                goto flags48;
            workWord2 = Physics11Player80View2;
            workWord3 = Physics11Player94View2;
            numeric4 = Physics11Player84View2;
            workWord3 -= 64;
            Physics11Player8CView2 = workWord2;
            Physics11Player90View1 = numeric4;
            Physics11Player94View2 = workWord3;
            goto clamp11;
        flags48:
            call6 = &Physics11PlayerFCView1;
            workWord2 = Physics11Field(call6, unsigned char*, 0);
            if (workWord2)
                goto copy48;
            workWord2 = Physics11PlayerB8View2;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector48;
        copy48:
            workWord2 = Physics11Player80View2;
            workWord3 = Physics11PlayerA0View2;
            numeric4 = Physics11Player84View2;
            workWord3 -= 192;
            Physics11Player8CView2 = workWord2;
            Physics11Player90View1 = numeric4;
            Physics11Player94View2 = workWord3;
            Physics11PlayerA0View2 = workWord3;
            goto clamp11;
        vector48:
            call5 = call6 - 124;
            Physics11AddVectorView5(call4, call5, call6 - 20);
            goto clamp11;
        clamp11:
            globalPointer = &Physics11Player94View2;
            workWord2 = Physics11Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
                Physics11Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        }
        case 40: {
            register int numeric4 __asm__("$4");
            call5 = &Physics11Player20CView2;
            MATCHING_KEEP(call5);
            workWord2 = Physics11Field(call5, int*, 0) & 64;
            call4 = &originalFrame.sp40;
            if (workWord2)
                goto block_132;
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics11Call410F8View1(call4, call5, 0);
            workWord3 = Physics11Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics11Player60View1;
                numeric4 = Physics11Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric4 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.sp44 = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.sp44 = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                workWord2 = originalFrame.sp44;
                workWord3 = numeric4 + 1;
                Physics11Player144View1 = workWord3;
                workWord3 = workWord3 < 21;
                workWord2 = (workWord2 << 7) >> 8;
                originalFrame.sp44 = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics11Player4CView1 = 0;
                }
            }
            raw21_temp_s1_4 = (int)(originalFrame.sp40 * 0x14) >> 7;
            Physics11Field(&Physics11Player0View4, int*, 0x64) =
                (int)((Physics11Field(&Physics11Player0View4, int*, 0x64) + raw21_temp_s1_4) &
                      0xFFF);
            raw21_temp_v1_6 = (Physics11Field(&Physics11Player0View4, int*, 0x60) +
                               ((int)(originalFrame.sp44 * -0xF) >> 7)) &
                              0xFFF;
            Physics11Field(&Physics11Player0View4, int*, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics11Field(&Physics11Player0View4, int*, 0x60) =
                    (int)(raw21_temp_v1_6 - 0x1000);
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x60) < -0x320) {
                Physics11Field(&Physics11Player0View4, int*, 0x60) = -0x320;
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x60) >= 0x321) {
                Physics11Field(&Physics11Player0View4, int*, 0x60) = 0x320;
            }
            if ((*Physics11Data6C570View2 & 0x40) ||
                (Physics11Field(&Physics11Player0View4, int*, 0x4C) == 1)) {
                Physics11Field(&Physics11Player0View4, int*, 0xAC) = 0xE00;
            } else {
                Physics11Field(&Physics11Player0View4, int*, 0xAC) = 0;
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x4C) == 2) {
                Physics11Call417FCView3(0xC0, 0xC0);
                if (Physics11Field(&Physics11Player0View4, int*, 0xB0) < 0xE01) {
                    Physics11Field(&Physics11Player0View4, int*, 0x4C) = 0;
                }
            } else {
                Physics11Call417FCView3(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics11Player0View4 + 0x60;
            raw21_temp_a0_5 =
                (((int)(raw21_temp_s1_4 * -(Physics11InterpolateCosineView2(
                                                Physics11Field(&Physics11Player0View4, int*, 0x60))
                                            << 5)) >>
                  0xC) -
                 ((int)(Physics11Field(&Physics11Player0View4, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics11Field(&Physics11Player0View4, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics11Field(&Physics11Player0View4, int*, 0x14C) + raw21_temp_a0_5;
            Physics11Field(&Physics11Player0View4, int*, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 =
                (Physics11Field(&Physics11Player0View4, int*, 0x5C) + (raw21_temp_v1_7 >> 6)) &
                0xFFF;
            Physics11Field(&Physics11Player0View4, int*, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics11Field(&Physics11Player0View4, int*, 0x5C) =
                    (int)(raw21_temp_a1_2 - 0x1000);
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x5C) < -0x300) {
                Physics11Field(&Physics11Player0View4, int*, 0x5C) = -0x300;
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x5C) >= 0x301) {
                Physics11Field(&Physics11Player0View4, int*, 0x5C) = 0x300;
            }
            Physics11Call41848View2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics11CopyVectorView4(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2 = Physics11CallRandView2() & 31;
            if (workWord2)
                goto block_130;
            MATCHING_KEEP(workWord2);
            particleCall3 = Physics21_SpawnParticle;
            call4 = (void*)1;
            if (!particleCall3)
                goto block_130;
            call5 = (void*)44;
            call6 = &originalFrame.spB8;
            particleArg7 = 0;
            MATCHING_KEEP(particleArg7);
            workWord2 = 544;
            originalFrame.spB8 = workWord2;
            workWord2 = 64;
            originalFrame.spBC = 0;
            __asm__ volatile("" ::"i"(0x8008C818) : "memory");
            originalFrame.spC0 = workWord2;
            goto block_129;
        }
        case 41: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics11Player0View4 + 0x20C;
            if (!(Physics11Field(&Physics11Player0View4, int*, 0x20C) & 0x40)) {
                if (Physics11Data6E044View3 != 7) {
                    Physics11Call410F8View1(&originalFrame.spB8, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3 = originalFrame.spB8;
                    numeric4 = originalFrame.spBC;
                    workWord2 = workWord3 * 5;
                    workWord2 <<= 2;
                    raw21_temp_s0_8 = workWord2 >> 7;
                    workWord2 = numeric4 << 4;
                    numeric4 -= workWord2;
                    numeric4 >>= 7;
                    workWord3 = Physics11Player64View1;
                    workWord2 = Physics11Player60View1;
                    workWord3 += raw21_temp_s0_8;
                    workWord3 &= 4095;
                    workWord2 += numeric4;
                    Physics11Player64View1 = workWord3;
                    workWord3 = workWord2 & 4095;
                    workWord2 = workWord3 < 2049;
                    Physics11Player60View1 = workWord3;
                    if (!workWord2) {
                        workWord2 = workWord3 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics11Player60View1 = workWord2;
                    }
                    if (Physics11Field(&Physics11Player0View4, int*, 0x60) < -0x320) {
                        Physics11Field(&Physics11Player0View4, int*, 0x60) = -0x320;
                    }
                    if (Physics11Field(&Physics11Player0View4, int*, 0x60) >= 0x321) {
                        Physics11Field(&Physics11Player0View4, int*, 0x60) = 0x320;
                    }
                    workWord2 = Physics11InterpolateCosineView2(Physics11Player60View1);
                    workWord2 <<= 5;
                    workWord2 = -workWord2;
                    product41 = raw21_temp_s0_8 * workWord2;
                    workWord3 = Physics11Field(raw21_temp_s1_5, int*, -192);
                    numeric5 = Physics11Player5CView1;
                    workWord2 = (workWord3 << 4) >> 6;
                    numeric4 = product41 >> 12;
                    numeric4 -= workWord2;
                    workWord2 = (numeric5 << 6) >> 6;
                    numeric4 -= workWord2;
                    workWord3 += numeric4;
                    Physics11Field(raw21_temp_s1_5, int*, -192) = workWord3;
                    workWord3 >>= 6;
                    numeric5 += workWord3;
                    numeric5 &= 4095;
                    workWord2 = numeric5 < 2049;
                    Physics11Player5CView1 = numeric5;
                    if (!workWord2) {
                        workWord2 = numeric5 - 4096;
                        MATCHING_KEEP(workWord2);
                        Physics11Player5CView1 = workWord2;
                    }
                    if (Physics11Field(&Physics11Player0View4, int*, 0x5C) < -0x300) {
                        Physics11Field(&Physics11Player0View4, int*, 0x5C) = -0x300;
                    }
                    if (Physics11Field(&Physics11Player0View4, int*, 0x5C) >= 0x301) {
                        Physics11Field(&Physics11Player0View4, int*, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics11Player0View4 + 0x80;
                Physics11ClearVectorView3(raw21_temp_s0_9);
                Physics11ClearVectorView3(raw21_temp_s0_9 + 0xC);
                workWord2 = Physics11CallRandView2() & 31;
                if (workWord2)
                    goto block_130;
                MATCHING_KEEP(workWord2);
                particleCall3 = Physics21_SpawnParticle;
                call4 = (void*)1;
                if (!particleCall3)
                    goto block_130;
                call5 = (void*)44;
                call6 = &originalFrame.spC8;
                particleArg7 = 0;
                MATCHING_KEEP(particleArg7);
                workWord2 = 544;
                originalFrame.spC8 = workWord2;
                workWord2 = 64;
                originalFrame.spCC = 0;
                originalFrame.spD0 = workWord2;
            block_129:
                particleCall3(call4, call5, call6, particleArg7);
            block_130:
                globalPointer = &Physics11Player158View1;
                workWord2 = Physics11Field(globalPointer, int*, 0);
                workWord2++;
                Physics11Field(globalPointer, int*, 0) = workWord2;
                return;
            }
            goto block_132;
        }
        case 42: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5 = &Physics11Player20CView2;
            MATCHING_KEEP(call5);
            workWord2 = Physics11Field(call5, int*, 0) & 64;
            call4 = &originalFrame.spC8;
            if (!workWord2)
                goto run42;
        block_132:
            Physics11PlayerACView1 = 0;
            Physics11PlayerB0View1 = 0;
            return;
        run42:
            call5 -= 192;
            MATCHING_KEEP(workWord2);
            Physics11Call410F8View1(call4, call5, 0);
            workWord3 = Physics11Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2) {
                workWord2 = 512;
                workWord3 = Physics11Player60View1;
                numeric5 = Physics11Player144View1;
                workWord2 -= workWord3;
                workWord3 = numeric5 << 4;
                workWord2 -= workWord3;
                workWord3 = workWord2 & 4095;
                originalFrame.spCC = workWord3;
                workWord2 = workWord3 < 2049;
                if (!workWord2) {
                    workWord2 = workWord3 - 4096;
                    MATCHING_KEEP(workWord2);
                    originalFrame.spCC = workWord2;
                }
                MATCHING_BARRIER_VOLATILE("memory");
                numeric4 = originalFrame.spCC;
                workWord3 = numeric5 + 1;
                Physics11Player144View1 = workWord3;
                workWord3 = workWord3 < 13;
                workWord2 = numeric4 * 3;
                workWord2 <<= 5;
                workWord2 >>= 8;
                originalFrame.spCC = workWord2;
                if (!workWord3) {
                    MATCHING_KEEP_VOLATILE(workWord3);
                    Physics11Player4CView1 = 0;
                }
            }
            raw21_temp_s1_6 = &Physics11Player0View4 + 0x64;
            raw21_temp_s0_10 = (int)(originalFrame.spC8 * 0x14) >> 7;
            Physics11Field(&Physics11Player0View4, int*, 0x64) =
                (int)((Physics11Field(&Physics11Player0View4, int*, 0x64) + raw21_temp_s0_10) &
                      0xFFF);
            raw21_temp_v1_13 = (Physics11Field(&Physics11Player0View4, int*, 0x60) +
                                ((int)(originalFrame.spCC * -0xF) >> 7)) &
                               0xFFF;
            Physics11Field(&Physics11Player0View4, int*, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics11Field(&Physics11Player0View4, int*, 0x60) =
                    (int)(raw21_temp_v1_13 - 0x1000);
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x60) < -0x320) {
                Physics11Field(&Physics11Player0View4, int*, 0x60) = -0x320;
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x60) >= 0x321) {
                Physics11Field(&Physics11Player0View4, int*, 0x60) = 0x320;
            }
            Physics11Field(&Physics11Player0View4, int*, 0xAC) = 0x1C00;
            Physics11Call417FCView3(0x240, 0x30);
            raw21_temp_a0_6 =
                (((int)(raw21_temp_s0_10 * -(Physics11InterpolateCosineView2(
                                                 Physics11Field(&Physics11Player0View4, int*, 0x60))
                                             << 5)) >>
                  0xC) -
                 ((int)(Physics11Field(&Physics11Player0View4, int*, 0x14C) * 0x10) >> 6)) -
                ((int)(Physics11Field(&Physics11Player0View4, int*, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 =
                Physics11Field(&Physics11Player0View4, int*, 0x14C) + raw21_temp_a0_6;
            Physics11Field(&Physics11Player0View4, int*, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 =
                (Physics11Field(&Physics11Player0View4, int*, 0x5C) + (raw21_temp_v1_14 >> 6)) &
                0xFFF;
            Physics11Field(&Physics11Player0View4, int*, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics11Field(&Physics11Player0View4, int*, 0x5C) =
                    (int)(raw21_temp_a1_3 - 0x1000);
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x5C) < -0x300) {
                Physics11Field(&Physics11Player0View4, int*, 0x5C) = -0x300;
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x5C) >= 0x301) {
                Physics11Field(&Physics11Player0View4, int*, 0x5C) = 0x300;
            }
            Physics11Call41848View2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics11CopyVectorView4(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) &&
                (Physics11Field(&Physics11Player0View4, int*, 0xB4) >= 0x7D1)) {
                originalFrame.spD8 = -0x190;
                originalFrame.spDC = 0x40 - (Physics11CallRandView2() & 0x7F);
                originalFrame.spE0 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.spD8, 0);
                return;
            }
            break;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics11Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics11Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            call4 = &Physics11Player80View1;
            MATCHING_KEEP(call4);
            Physics11ClearVectorView3(call4);
            call4 = &Physics11Player8CView1;
            MATCHING_KEEP(call4);
            Physics11ClearVectorView3(call4);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics11Data6E044View3;
            if (workWord3 == workWord2) {
                Physics11Field(&Physics11Player0View4, int*, 0xB0) = 0;
            } else {
                Physics11Call40D10View3(0x980);
                raw21_var_v0_2 = Physics11Call41580View3(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics11Field(&Physics11Player0View4, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics11Field(&Physics11Player0View4, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics11Call417FCView3(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics11Player0View4 + 0xB0;
            if (Physics11Field(&Physics11Player0View4, int*, 0xB0) != 0) {
                Physics11Call41848View2();
                Physics11Call41B64View3();
                Physics11Field(&Physics11Player0View4, int*, 0x94) = 0;
            } else {
                Physics11ClearVectorView3(raw21_temp_s0_11 - 0x30);
                Physics11ClearVectorView3(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics11Player0View4 + 0x28;
                if (Physics11Field(&Physics11Player0View4, int*, 0x28) < 0) {
                    if ((Physics11Field(&Physics11Player0View4, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics11Data6C640View2 & 1)) {
                        Physics11CopyVectorView4(&originalFrame.spD8, raw21_temp_s4 - 0x28);
                        originalFrame.spEC = 0x40;
                        originalFrame.spF0 = 0;
                        originalFrame.spE8 =
                            (int)Physics11Field(&Physics11Player0View4, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.spEC = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics11TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.spE8,
                                                             &originalFrame.spF8);
                        Physics11AddVectorView4(&originalFrame.spD8, &originalFrame.spD8,
                                                &originalFrame.spF8);
                        originalFrame.spE8 = 0;
                        originalFrame.spE0 = -Physics11Field(&Physics11Player0View4, int*, 0x28);
                        Physics11TransformVectorByBasisView2(raw21_temp_s2_3, &originalFrame.spE8,
                                                             &originalFrame.spE8);
                        Physics11ShiftVectorRightTowardZeroView1(&originalFrame.spE8, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.spD8, &originalFrame.spE8);
                        if (!(Physics11CallRandView2() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.spD8, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics11Player0View4 + 0xB0;
                        if ((Physics11Field(&Physics11Player0View4, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics11Data6C640View2 & 7) &&
                            !(Physics11CallRandView2() & 3)) {
                            originalFrame.sp108 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp10C = 0;
                            originalFrame.sp110 = 0;
                            Physics11TransformVectorByBasisView2(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp108, &originalFrame.sp108);
                            Physics11AddVectorView4(&originalFrame.sp108, &originalFrame.sp108,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp110 =
                                -Physics11Field(&Physics11Player0View4, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp108, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics11Field(&Physics11Player0View4, int*, 0x144) -
                ((int)((Physics11Field(&Physics11Player0View4, int*, 0x148) * 2) +
                       (Physics11Field(&Physics11Player0View4, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics11Field(&Physics11Player0View4, int*, 0x148) + raw21_temp_a1_4;
            Physics11Field(&Physics11Player0View4, int*, 0x144) = raw21_temp_a1_4;
            Physics11Field(&Physics11Player0View4, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics11Field(&Physics11Player0View4, int*, 0x148) = 0x5900;
            }
            if (Physics11Field(&Physics11Player0View4, int*, 0x148) < -0x5900) {
                Physics11Field(&Physics11Player0View4, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 65:
            globalVector80 = &Physics11Player0View2 + 0x80;
            Physics11ClearVectorView2(globalVector80);
            Physics11ClearVectorView2(globalVector80 + 12);
            if (Physics11Data6E044View2 != 7) {
                Physics11Call40D10View2(6016);
                Physics11Call416F4View2();
                Physics11Call41580View2(90, 16);
            }
            workWord2 = Physics11Player1BAView1;
            if (!workWord2)
                goto byteOne65;
            workWord2 = Physics11Data6E538View1 & 16;
            if (workWord2)
                return;
            workWord2 = 1;
            Physics11Player1BAView1 = 0;
            Physics11Player1B9View1 = workWord2;
            return;
        byteOne65:
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics11Player1B9View1 = workWord2;
            return;
        case 66:
        case 69:
            workWord3 = Physics11Data6E044View2;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics11Call40D10View2(6016);
            globalVector80 = &Physics11Data6E538View1;
            workWord2 = Physics11Field(globalVector80, int*, 0) & 12;
            if (workWord2)
                Physics11PlayerACView1 = 0;
            workWord2 = Physics11Call416F4View2();
            call4 = (void*)90;
            call5 = (void*)16;
            MATCHING_KEEP2(call4, call5);
            globalFieldA4Pointer = (void*)workWord2;
            workWord2 = Physics11Call41580View2(call4, call5);
            workWord3 = Physics11PlayerA8View1;
            if (workWord3 < 0)
                workWord3 = -workWord3;
            workWord3 = workWord3 < 8;
            __asm__("" : "=r"(workWord3) : "0"(workWord3), "r"(workWord2));
            call5 = (void*)workWord2;
            if (!workWord3)
                goto reset101;
            workWord2 = Physics11Field(globalVector80, int*, 0) & 12;
            if (!workWord2)
                goto reset101;
            workWord2 = Physics11Player144View1;
            workWord2++;
            Physics11Player144View1 = workWord2;
            goto saved101;
        reset101:
            Physics11Player144View1 = 0;
        saved101:
            call4 = &Physics11PlayerACView1;
            globalVector80 = (void*)Physics11Field(call4, int*, 0);
            if (globalFieldA4Pointer)
                goto collision101;
            workWord2 = (int)call5;
            if ((int)call5 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass101;
        collision101:
            workWord2 = Physics11Player20CView1 & 64;
            if (workWord2)
                Physics11Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics11PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics11Field(call4, int*, 0) = workWord3;
            }
        pass101:
            Physics11Call417FCView2(320, 192);
            workWord2 = Physics11Player101View1;
            call4 = &Physics11PlayerACView1;
            Physics11Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics11ClearVectorView2(call4 - 32);
                goto fields101;
            }
            Physics11Call41848View1(call4);
            Physics11Call41B64View2();
        fields101:
            call6 = &Physics11PlayerFCView1;
            workWord2 = Physics11Field(call6, unsigned char*, 0);
            if (workWord2)
                goto block_303;
            workWord2 = Physics11PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto block_303;
        commit101:
            goto vectorInput71;
        case 67: {
            int lowProduct3Case67, lowProduct4Case67;
            Physics11Call40D10View1(0xC80);
            Physics11Call41580View1(0x28, 8);
            Physics11Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics11Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics11InterpolateCosineView1(Physics11Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics11Field(&Physics11Player0View1, int*, 0xB0);
            lowProduct3Case67 = workWord3 * workWord2;
            call4 = (void*)Physics11Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3Case67 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spF8 = workWord2;
            workWord2 = Physics11InterpolateSineView1(call4);
            workWord3 = Physics11Field(&Physics11Player0View1, int*, 0xB0);
            lowProduct4Case67 = workWord3 * workWord2;
            workWord2 = lowProduct4Case67 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.spFC = workWord2;
            Physics11SubtractVectorView1(&originalFrame.spF8, &originalFrame.spF8, globalVector8C);
            originalFrame.sp100 = 0;
            temp_v0_4 = Physics11MeasureVectorLengthView1(&originalFrame.spF8, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics11ScaleVectorRatioQ15View1(&originalFrame.spF8, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics11AddVectorView1(var_a0_3, globalVector8C, &originalFrame.spF8);
            Physics11Call41B64View1();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract320_73;
            workWord2 = Physics11Player4CView1;
            if (workWord2)
                goto subtract320_73;
            workWord2 = (int)Physics11Data6C570View1;
            workWord2 = Physics11Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add30_70;
            workWord2 = Physics11Player144View1;
            if (workWord2)
                goto add30_70;
            goto subtract320_73;
        }
        case 68: {
            register void* child19 __asm__("$19");
            register int numeric5 __asm__("$5");
            int lowProduct3Case68, lowProduct4Case68;
            globalFieldA4Pointer = &Physics11Player4CView1;
            workWord2 = 2;
            globalPointer = (void*)Physics11Player250View1;
            call4 = (void*)Physics11Field(globalFieldA4Pointer, int*, 0);
            child19 = Physics11Field(globalPointer, void**, 0);
            numeric5 = 1600;
            if ((int)call4 == workWord2)
                numeric5 = 3200;
            Physics11Call40D10View1(numeric5, numeric5);
            Physics11Call41580View1(22, 4);
            Physics11Call417FCView1(320, 192);
            MATCHING_KEEP(globalFieldA4Pointer);
            globalVector8C = globalFieldA4Pointer + 64;
            workWord2 =
                Physics11InterpolateCosineView1(Physics11Field(globalFieldA4Pointer, int*, 88));
            workWord3 = Physics11PlayerB0View1;
            lowProduct3Case68 = workWord3 * workWord2;
            call4 = (void*)Physics11Field(globalFieldA4Pointer, int*, 88);
            workWord2 = lowProduct3Case68 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp118 = workWord2;
            workWord2 = Physics11InterpolateSineView1(call4);
            workWord3 = Physics11PlayerB0View1;
            lowProduct4Case68 = workWord3 * workWord2;
            workWord2 = lowProduct4Case68 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp11C = workWord2;
            Physics11SubtractVectorView1(&originalFrame.sp118, &originalFrame.sp118,
                                         globalVector8C);
            originalFrame.sp120 = 0;
            temp_v0_4 = Physics11MeasureVectorLengthView1(&originalFrame.sp118, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 52;
            if (temp_v0_4 >= 0x141) {
                Physics11ScaleVectorRatioQ15View1(&originalFrame.sp118, temp_v0_4, 0x140);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 52;
            }
            Physics11AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp118);
            Physics11Call41B64View1();
            workWord2 = Physics11Player94View1;
            workWord2 -= 320;
            Physics11Player94View1 = workWord2;
            workWord2 = workWord2 < -12800;
            if (workWord2) {
                workWord2 = -12800;
                Physics11Field(globalFieldA4Pointer, int*, 72) = workWord2;
            }
            workWord2 = Physics11Field(globalFieldA4Pointer, unsigned char*, 362);
            if (!workWord2)
                return;
            workWord2 = Physics11Field(child19, int*, 72);
            workWord2++;
            Physics11Field(child19, int*, 72) = workWord2;
            return;
        }
        case 70: {
            int lowProduct3Case70, lowProduct4Case70;
            Physics11Call40D10View1(0xC80);
            Physics11Call41580View1(0x28, 8);
            Physics11Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics11Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics11InterpolateCosineView1(Physics11Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics11Field(&Physics11Player0View1, int*, 0xB0);
            lowProduct3Case70 = workWord3 * workWord2;
            call4 = (void*)Physics11Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3Case70 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp128 = workWord2;
            workWord2 = Physics11InterpolateSineView1(call4);
            workWord3 = Physics11Field(&Physics11Player0View1, int*, 0xB0);
            lowProduct4Case70 = workWord3 * workWord2;
            workWord2 = lowProduct4Case70 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp12C = workWord2;
            Physics11SubtractVectorView1(&originalFrame.sp128, &originalFrame.sp128,
                                         globalVector8C);
            originalFrame.sp130 = 0;
            temp_v0_4 = Physics11MeasureVectorLengthView1(&originalFrame.sp128, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics11ScaleVectorRatioQ15View1(&originalFrame.sp128, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics11AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp128);
            Physics11Call41B64View1();
            workWord2 = combinedIndex < 7;
            if (!workWord2)
                goto subtract320_73;
            workWord3 = Physics11Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2)
                goto subtract320_73;
        add30_70:
            workWord2 = Physics11Player94View1;
            workWord2 += 30;
            Physics11Player94View1 = workWord2;
            return;
        }
        case 71: {
            register int numeric5 __asm__("$5");
            int lowProduct3Case71, lowProduct4Case71;
            globalFieldA4Pointer = &Physics11PlayerB8View1;
            workWord2 = Physics11Field(globalFieldA4Pointer, int*, 0);
            if (!workWord2)
                goto grounded71;
            workWord2 = 2;
            workWord3 = Physics11Player4CView1;
            numeric5 = 1600;
            if (workWord3 == workWord2)
                numeric5 = 3200;
            Physics11Call40D10View1(numeric5, numeric5);
            Physics11Call41580View1(22, 4);
            Physics11Call417FCView1(320, 192);
            MATCHING_KEEP(globalFieldA4Pointer);
            globalVector8C = globalFieldA4Pointer - 44;
            workWord2 = Physics11InterpolateCosineView1(Physics11PlayerA4View1);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(globalVector8C, "memory");
            workWord3 = Physics11PlayerB0View1;
            lowProduct3Case71 = workWord3 * workWord2;
            call4 = (void*)Physics11PlayerA4View1;
            workWord2 = lowProduct3Case71 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp138 = workWord2;
            workWord2 = Physics11InterpolateSineView1(call4);
            workWord3 = Physics11PlayerB0View1;
            lowProduct4Case71 = workWord3 * workWord2;
            workWord2 = lowProduct4Case71 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp13C = workWord2;
            Physics11SubtractVectorView1(&originalFrame.sp138, &originalFrame.sp138,
                                         globalVector8C);
            originalFrame.sp140 = 0;
            temp_v0_4 = Physics11MeasureVectorLengthView1(&originalFrame.sp138, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 56;
            if (temp_v0_4 >= 0x141) {
                Physics11ScaleVectorRatioQ15View1(&originalFrame.sp138, temp_v0_4, 0x140);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 56;
            }
            Physics11AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp138);
            Physics11Call41B64View1();
            workWord2 = Physics11Player94View1;
            workWord2 -= 320;
            Physics11Player94View1 = workWord2;
            workWord2 = workWord2 < -12800;
            if (workWord2) {
                workWord2 = -12800;
                Physics11Player94View1 = workWord2;
            }
            return;
        grounded71:
            workWord3 = Physics11Data6E044View2;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics11Call40D10View2(6016);
            globalVector80 = &Physics11Data6E538View1;
            workWord2 = Physics11Field(globalVector80, int*, 0) & 12;
            if (workWord2)
                Physics11PlayerACView1 = 0;
            workWord2 = Physics11Call416F4View2();
            call4 = (void*)90;
            call5 = (void*)16;
            MATCHING_KEEP2(call4, call5);
            globalFieldA4Pointer = (void*)workWord2;
            workWord2 = Physics11Call41580View2(call4, call5);
            workWord3 = Physics11PlayerA8View1;
            if (workWord3 < 0)
                workWord3 = -workWord3;
            workWord3 = workWord3 < 8;
            __asm__("" : "=r"(workWord3) : "0"(workWord3), "r"(workWord2));
            call5 = (void*)workWord2;
            if (!workWord3)
                goto reset71;
            workWord2 = Physics11Field(globalVector80, int*, 0) & 12;
            if (!workWord2)
                goto reset71;
            workWord2 = Physics11Player144View1;
            workWord2++;
            Physics11Player144View1 = workWord2;
            goto saved71;
        reset71:
            Physics11Player144View1 = 0;
        saved71:
            call4 = &Physics11PlayerACView1;
            globalVector80 = (void*)Physics11Field(call4, int*, 0);
            if (globalFieldA4Pointer)
                goto collision71;
            workWord2 = (int)call5;
            if ((int)call5 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass71;
        collision71:
            workWord2 = Physics11Player20CView1 & 64;
            if (workWord2)
                Physics11Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics11PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics11Field(call4, int*, 0) = workWord3;
            }
        pass71:
            Physics11Call417FCView2(320, 192);
            workWord2 = Physics11Player101View1;
            call4 = &Physics11PlayerACView1;
            Physics11Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics11ClearVectorView2(call4 - 32);
                goto fields71;
            }
            Physics11Call41848View1(call4);
            Physics11Call41B64View2();
        fields71:
            call6 = &Physics11PlayerFCView1;
            workWord2 = Physics11Field(call6, unsigned char*, 0);
            if (workWord2)
                goto block_303;
            workWord2 = Physics11PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vectorInput71;
        block_303:
            workWord2 = Physics11PlayerA0View1;
            workWord2 -= 320;
            Physics11Player94View1 = workWord2;
            return;
        vectorInput71:
            __asm__ volatile("" ::"i"(0x8008D900) : "memory");
            call5 = call4;
        vectorCommit49:
            Physics11AddVectorView6(call4, call5, call6 - 20);
            return;
        }
        case 72: {
            int lowProduct3Case72, lowProduct4Case72;
            globalFieldA4Pointer = &Physics11Player4CView1;
            workWord2 = Physics11Field(globalFieldA4Pointer, int*, 0);
            if (workWord2)
                goto vector72;
            workWord2 = combinedIndex < 19;
            call4 = globalFieldA4Pointer + 64;
            if (workWord2)
                goto neutralVector72;
            call4 = globalFieldA4Pointer + 52;
            workWord3 = Physics11Player8CView3;
            workWord2 = workWord3 * 7;
            workWord3 = Physics11Player90View2;
            workWord2 <<= 5;
            Physics11Field(globalFieldA4Pointer, int*, 52) = workWord2;
            workWord2 = workWord3 * 7;
            workWord3 = Physics11Player94View1;
            workWord2 <<= 5;
            Physics11Player84View1 = workWord2;
            workWord2 = workWord3 * 7;
            workWord2 <<= 5;
            Physics11Player88View1 = workWord2;
            Physics11ShiftVectorRightTowardZeroView2(call4, 8);
            MATCHING_KEEP(globalFieldA4Pointer);
            call4 = globalFieldA4Pointer + 64;
        neutralVector72:
            Physics11CopyVectorView6(call4, globalFieldA4Pointer + 52);
            workWord2 = Physics11Player94View1;
            workWord2 -= 192;
            Physics11Player94View1 = workWord2;
            workWord2 = workWord2 < -8960;
        clamp19:
            if (workWord2) {
                workWord2 = -8960;
                Physics11Player94View1 = workWord2;
            }
            return;
        vector72:
            Physics11Call40D10View1(3200);
            Physics11Call41580View1(40, 8);
            Physics11Call417FCView1(320, 192);
            MATCHING_KEEP(globalFieldA4Pointer);
            globalVector8C = globalFieldA4Pointer + 64;
            workWord2 = Physics11InterpolateCosineView1(Physics11PlayerA4View1);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(globalVector8C, "memory");
            workWord3 = Physics11PlayerB0View1;
            lowProduct3Case72 = workWord3 * workWord2;
            call4 = (void*)Physics11PlayerA4View1;
            workWord2 = lowProduct3Case72 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp148 = workWord2;
            workWord2 = Physics11InterpolateSineView1(call4);
            workWord3 = Physics11PlayerB0View1;
            lowProduct4Case72 = workWord3 * workWord2;
            workWord2 = lowProduct4Case72 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp14C = workWord2;
            Physics11SubtractVectorView1(&originalFrame.sp148, &originalFrame.sp148,
                                         globalVector8C);
            originalFrame.sp150 = 0;
            temp_v0_4 = Physics11MeasureVectorLengthView1(&originalFrame.sp148, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 52;
            if (temp_v0_4 >= 0x281) {
                Physics11ScaleVectorRatioQ15View1(&originalFrame.sp148, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 52;
            }
            Physics11AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp148);
            Physics11Call41B64View1();
            if (combinedIndex < 13) {
                MATCHING_OBSERVE(combinedIndex);
                workWord2 = Physics11Player94View1;
                workWord2 += 30;
            } else {
                workWord2 = Physics11Player94View1;
                workWord2 -= 320;
            }
            Physics11Player94View1 = workWord2;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics11Player0View1 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics11Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp168;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop72:
                    if (particleThreshold < (Physics11CallRandView1() & 0xFF)) {
                        workWord2 = Physics11Call363DCView1(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics11Data65920View1 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp158 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics11Data658A0View1 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp160 = 0xE;
                        originalFrame.sp168 = -0x12C;
                        originalFrame.sp16C = 0;
                        originalFrame.sp170 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp15C = (workWord3 * 5) >> 0xA;
                        Physics11TransformVectorByBasisView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp168 += Physics11Call363DCView1(0, 0x50);
                        originalFrame.sp16C += Physics11Call363DCView1(0, 0x50);
                        originalFrame.sp170 += Physics11Call363DCView1(0, 0x50);
                        Physics11AddVectorView1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp158);
                        workWord2 = (int)temp_v0_5;
                        workWord3 = 8;
                        Physics11Field((void*)workWord2, signed char*, 2) = workWord3;
                        workWord3 = 32;
                        Physics11Field((void*)workWord2, signed char*, 10) = workWord3;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop72;
                    }
                }
            }
            break;
        }
        case 73: {
            int lowProduct3Case73, lowProduct4Case73;
            Physics11Call40D10View1(0x640);
            Physics11Call41580View1(0x28, 8);
            Physics11Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics11Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics11InterpolateCosineView1(Physics11Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics11Field(&Physics11Player0View1, int*, 0xB0);
            lowProduct3Case73 = workWord3 * workWord2;
            call4 = (void*)Physics11Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3Case73 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp158 = workWord2;
            workWord2 = Physics11InterpolateSineView1(call4);
            workWord3 = Physics11Field(&Physics11Player0View1, int*, 0xB0);
            lowProduct4Case73 = workWord3 * workWord2;
            workWord2 = lowProduct4Case73 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp15C = workWord2;
            Physics11SubtractVectorView1(&originalFrame.sp158, &originalFrame.sp158,
                                         globalVector8C);
            originalFrame.sp160 = 0;
            temp_v0_4 = Physics11MeasureVectorLengthView1(&originalFrame.sp158, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics11ScaleVectorRatioQ15View1(&originalFrame.sp158, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics11AddVectorView1(var_a0_3, globalVector8C, &originalFrame.sp158);
            Physics11Call41B64View1();
            workWord2 = combinedIndex < 19;
            if (!workWord2)
                goto subtract320_73;
            workWord3 = Physics11Player4CView1;
            workWord2 = 1;
            if (workWord3 == workWord2)
                goto subtract320_73;
            workWord2 = Physics11Player94View1;
            workWord2 += 100;
            Physics11Player94View1 = workWord2;
            return;
        subtract320_73:
            globalPointer = &Physics11Player94View1;
            workWord2 = Physics11Field(globalPointer, int*, 0);
            workWord2 -= 320;
            Physics11Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 74:
            globalVector80 = &Physics11Player0View2 + 0xB8;
            workWord2 = Physics11Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero105;
            vectorAt30 = &originalFrame.sp178;
            Physics11ClearVectorView2(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics11SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.sp180 = 0;
            call5 = (void*)Physics11MeasureVectorLengthView2(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics11ScaleVectorRatioQ15View2(vectorAt30, call5, 64);
            originalFrame.sp180 = -320;
            globalVector80 -= 56;
            Physics11AddVectorView2(globalVector80, globalVector8CState20, vectorAt30);
            Physics11CopyVectorView2(globalVector8CState20, globalVector80);
            goto clamp74;
        zero105:
            Physics11ClearVectorView2(globalVector80 - 56);
            Physics11ClearVectorView2(globalVector80 - 44);
            goto clamp74;
        clamp74:
            globalPointer = &Physics11Player94View1;
            workWord2 = Physics11Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -12800;
            if (workWord2) {
                workWord2 = -12800;
                Physics11Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        case 75:
        case 76:
        case 77: {
            register int numeric5 __asm__("$5");
            int product75;
            call4 = &Physics11Player8CView3;
            MATCHING_KEEP(call4);
            workWord3 = Physics11Field(call4, int*, -64);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord3, "memory");
            numeric5 = 1;
            MATCHING_KEEP(numeric5);
            Physics11Field(call4, int*, 0) = 0;
            Physics11Field(call4, int*, 4) = 0;
            if (workWord3 == numeric5)
                goto descend75;
            workWord2 = workWord3 < 2;
            if (!workWord2)
                goto larger75;
            if (!workWord3)
                goto zero75;
            return;
        larger75:
            workWord2 = 2;
            if (workWord3 == workWord2)
                goto zeroVelocity75;
            return;
        zero75:
            workWord2 = Physics11Player144View1;
            workWord2++;
            Physics11Player144View1 = workWord2;
            workWord2 = workWord2 < 42;
            if (workWord2) {
                workWord2 = Physics11Player94View1;
                workWord2 -= 32;
                Physics11Player94View1 = workWord2;
                return;
            }
            Physics11Field(call4, int*, -64) = numeric5;
            __asm__ volatile("" ::: "$2", "memory");
            Physics11Player54View1 = 0;
            return;
        descend75:
            workWord2 = Physics11Field(call4, int*, 8);
            workWord2 -= 2048;
            Physics11Field(call4, int*, 8) = workWord2;
            workWord2 = workWord2 < -12800;
            if (workWord2)
                Physics11Field(call4, int*, 8) = -12800;
            workWord2 = Physics11PlayerB8View1;
            if (workWord2)
                return;
            workWord2 = Physics11Player54View1;
            workWord2 = workWord2 < 9;
            if (workWord2)
                return;
            workWord2 = Physics11PlayerE4View1;
            workWord2 = workWord2 < 23;
            if (!workWord2)
                return;
            workWord3 = Physics11PlayerD4View1;
            workWord2 = Physics11Field(call4, int*, 8);
            product75 = workWord3 * workWord2;
            if (product75 >= 0)
                return;
            workWord2 = 4096;
            particleCall3 = Physics42_SpawnParticle;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(particleCall3, "memory");
            Physics11Data6E1D4View1 = workWord2;
            workWord2 = 30;
            Physics11Data6E1D8View1 = workWord2;
            workWord2 = 2;
            Physics11Field(call4, int*, -64) = workWord2;
            Physics11Player54View1 = 0;
            call4 = (void*)8;
            if (particleCall3) {
                call5 = (void*)33;
                call6 = 0;
                particleArg7 = 2;
                particleCall3(call4, call5, call6, particleArg7);
                Physics42_SpawnParticle(8, 33, 0, 3);
            }
            call5 = 0;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            globalPointer = Physics11Data6C654View1;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(globalPointer, "memory");
            workWord2 = 120;
            Physics11Data6E530View1 = workWord2;
            workWord2 = 15;
            Physics11Data6E52CView1 = workWord2;
            call4 = (void*)Physics11Field(globalPointer, unsigned char*, 20);
            Physics11DataPlaySoundView1(call4, call5, 0);
            return;
        zeroVelocity75:
            Physics11Player94View1 = 0;
            return;
        }
    }
}
#undef Physics11Field

/* AI generated; not human reviewed. SCUS-94467 8008E030..8008E72C.
 * Newly verified23 case47 and verified50 table/state routes reused against
 * original11 selector scope, stack18 vector and numeric flag chains.
 * Original11 uses standalone stack vector18, immediate A0/A1 pointer producers
 * and S1 mask02000000, rather than23 saved vectorS1/maskS2. Source44-14/44-44
 * remain byte offsets. Table8006D048+14, selector80071924&63, stride4,entry+4
 * are numeric accesses; units, helper meanings and cadence remain unresolved.
 * Empty lifetime constraints emit no code. All original words, strict full TU
 * and every EXE/overlay hash required; compiled equality is not runtime parity.
 */
extern Spyro Callback11Player __asm__("D_80070328");
int Callback11Call80037058(int x, int y) __asm__("func_80037058");
void Callback11Call80041930(void) __asm__("func_80041930");
void Callback11Call80041AE8(void) __asm__("func_80041AE8");
void Callback11Call80041C20(void) __asm__("func_80041C20");
void Callback11Call80042A44(void) __asm__("func_80042A44");
void Callback11Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback11Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38, D_8006C648;
extern int D_80071924;
extern int** Callback11Table __asm__("D_8006D048+0x14");
int Callback11Call80055E84(Moby*) __asm__("func_80055E84");
void Callback11Call8004ED6C(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
void Callback11Call8001BA30(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
int Callback11Call80019138(Vector3D*, int, int, int, int, Moby*) __asm__("func_80019138");
int Callback11Call8001830C(Vector3D*, Vector3D*, int, int, Moby*) __asm__("func_8001830C");
extern int Callback11Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback11Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback11Values[] __asm__("D_8006FCF0");
void Callback11Call80049590(void) __asm__("func_80049590");
int Callback11Call8003BF6C(int, int) __asm__("func_8003BF6C");
void func_level_11_8008E030(void) {
    Vector3D localVector;
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

    switch (Callback11Player.animationState) {
        case 0x14:
        case 0x41:
            if (func_800438F4() == 0)
                func_80043728();
            Callback11Call80041C20();
            Callback11Player.unk9a = 0;
            Callback11Call80042A44();
            goto clearSharedValue;
        default:
            return;
        case 0x20:
        case 0x44:
        case 0x4A:
            Callback11Call80041C20();
            Callback11Call80042A44();
            goto clearSharedValue;
        case 0x42:
        case 0x45:
            func_800438F4();
            Callback11Call80041C20();
            Callback11Call80042A44();
            Callback11Call80041930();
            goto queryC00;
        case 0x13:
        case 0x15:
            Callback11Call80041C20();
            Callback11Call80042A44();
            goto call41930;
        case 0x1A:
            Callback11Call80041C20();
            Callback11Call80042A44();
            goto queryC00;
        case 0x24:
        case 0x25:
        case 0x30:
            Callback11Call80041C20();
            Callback11Call80042A44();
            Callback11Call80043A38(0xC00);
            if ((Callback11Player.ticksSinceLastSurfaceTouch == 0) &&
                (func_80040954(Callback11Player.unk11[2]) == 9)) {
                func_8004F178(
                    (Vector3D*)((unsigned char*)&Callback11Player.ticksSinceLastSurfaceTouch +
                                0x94),
                    (Vector3D*)((unsigned char*)&Callback11Player.ticksSinceLastSurfaceTouch +
                                0x14));
                Callback11Player.union144.a.unk13da = Callback11Player.unk7a[3].z;
            }
            Callback11Player.unk4[0] = 0;
            if ((Callback11Player.unk5 == 1) && ((Callback11Player.animationStateFrames >= 0xD) ||
                                                 !(Callback11Word8006E538 & 0x40))) {
                Callback11Player.unk5 = 2;
            }
            if (Callback11Player.unk5 != 3) {
                Callback11Player.union144.a.unk13db.x = 0;
                Callback11Player.union144.a.unk13db.y = 0;
                return;
            }
            break;
        case 0x28:
        case 0x29:
            Callback11Call80041C20();
            Callback11Call80042A44();
            descriptor = &Callback11Player.unk22[2];
            if (Callback11Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                decreasingValue = *(int*)(Callback11Values + valueOffset);
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
            Callback11Call80041C20();
            Callback11Call80042A44();
            Callback11Call80049590();
            descriptor = &Callback11Player.unk22[2];
            if (Callback11Call8003BF6C((int)D_8006C654->underwater, *descriptor) == 0) {
                descriptorResult = PlaySound((int)D_8006C654->underwater, 0, 4);
                *descriptor = descriptorResult;
                if (descriptorResult >= 0) {
                    func_8003C0B0(descriptorResult, 0x157C);
                    func_8003C140(*descriptor, 0x190);
                }
                Callback11Word290 = (int)D_8006C654->underwater;
                __asm__ volatile("" : : : "$16", "memory");
                descriptor = &Callback11Player.unk22[2];
            }
            if (Callback11Call8003BF6C((int)D_8006C654->underwater, *descriptor) != 0) {
                valueOffset = *descriptor * 0x2C;
                increasingValue = *(int*)(Callback11Values + valueOffset);
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
                *(int*)(Callback11Values + valueOffset) = tableValue;
            setTableFlag:
                flagOffset = *descriptor * 0x2C;
                Callback11Flags[flagOffset] = Callback11Flags[flagOffset] | 0x10;
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
            Callback11Call80041C20();
            Callback11Call80042A44();
            Callback11Call80041AE8();
            if ((unsigned char)Callback11Player.unk10[4] != 0) {
                computedValue = -Callback11Player.unk9ha[4] -
                                Callback11Call80037058(Callback11Player.position.x,
                                                       Callback11Player.position.y);
                positionValue = Callback11Player.unk4a - computedValue;
                Callback11Player.unk4[0] = computedValue;
                positionDelta = (int)Callback11Player.union144.a.unk13cc >> 6;
                positionValue -= positionDelta;
                MATCHING_KEEP(positionValue);
                Callback11Player.position.z = positionValue;
                return;
            }
            break;
        case 0x43:
        case 0x46:
        case 0x49:
            Callback11Call80041C20();
            Callback11Call80042A44();
            Callback11Call80041930();
            if (Callback11Player.unk7a[3].z < 0 && Callback11Player.animationStateFrames >= 4) {
                Callback11Player.unk5 = 1;
            } else {
                if (Callback11Player.unk5 == 0 && !(Callback11Word8006E538 & 0x40) &&
                    Callback11Player.union144.a.unk13cb == 0)
                    Callback11Player.unk5 = 2;
            }
            goto clearSharedValue;
        case 0x47: {
            register int progress __asm__("$4");
            register int value __asm__("$2");
            register int* sourceBase __asm__("$16");
            register int flags __asm__("$17");
            if (Callback11Player.ticksSinceLastSurfaceTouch) {
                Callback11Call80041C20();
                Callback11Call80042A44();
            } else {
                func_800438F4();
                Callback11Call80041C20();
                Callback11Call80042A44();
                Callback11Call80041930();
                Callback11Call80043A38(0xC00);
            }
            progress = Callback11Call80055E84(Callback11Player.critterMobyPtr);
            if (Callback11Player.critterMobyPtr->animationState.id == 6 &&
                (unsigned int)(progress - 2) < 6) {
                if (progress < 6)
                    value = (progress << 10) / 6;
                else
                    value = 0x400;
                localVector.x = value;
                MATCHING_BARRIER_VOLATILE("memory");
                sourceBase = &Callback11Player.unk4a;
                localVector.y = 0;
                localVector.z = 0x200 - *sourceBase;
                Callback11Call8004ED6C((unsigned char*)sourceBase - 0x14, (&localVector),
                                       (&localVector));
                {
                    register Vector3D* argument0 __asm__("$4") = (&localVector);
                    register Vector3D* argument1 __asm__("$5") = (&localVector);
                    MATCHING_KEEP2(argument0, argument1);
                    sourceBase = (int*)((unsigned char*)sourceBase - 0x44);
                    func_8004F194(argument0, argument1, (Vector3D*)sourceBase);
                }
                flags = 0x02000000;
                Callback11Call8001BA30((&localVector), 0x200, 0, 0, flags,
                                       Callback11Player.critterMobyPtr);
                if ((Callback11Call80019138((&localVector), 0x200, 0, 0, flags,
                                            Callback11Player.critterMobyPtr) != 0 ||
                     Callback11Call8001830C((Vector3D*)sourceBase, (&localVector), 0, 0x02000000,
                                            Callback11Player.critterMobyPtr) != 0)) {
                    register int* selector __asm__("$16") = &D_80071924;
                    if (func_80040954(*selector) == 3) {
                        register int index __asm__("$2") = *selector;
                        register int** table __asm__("$3") = Callback11Table;
                        register int* entry __asm__("$3");
                        index &= 63;
                        entry = table[index];
                        entry[1] |= flags;
                    }
                }
            }
            goto clearSharedValue;
        }
        case 0x4B:
        case 0x4C:
        case 0x4D:
            Callback11Call80041C20();
            Callback11Call80042A44();
            if (Callback11Player.unk5 == 1)
                func_800494A8();
            goto clearSharedValue;
        case 0x48:
            Callback11Call80041C20();
            Callback11Call80042A44();
            if (Callback11Player.unk5 != 0)
                goto call41930;
        queryC00:
            Callback11Call80043A38(0xC00);
            goto clearSharedValue;
        call41930:
            Callback11Call80041930();
        clearSharedValue:
            Callback11Player.unk4[0] = 0;
            return;
    }
}


/**
 * func_level_11_8008E730() - ???() - MATCHING
 * Ready to add. Currently appropriate for introducing as an animation.inc.h.
 * https://decomp.me/scratch/WDEnn
 */
#define LEVEL_ID 11
#define PlaySpyroSounds_level_11 func_level_11_8008E730
#include "overlay/animation.inc.h"

/**
 * func_level_11_8008E86C() - ???() - MATCHING
 * Ready to add. Interestingly implies the level 10 version of this has some unusual extra cases.
 * https://decomp.me/scratch/GJ9gX
 */
extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_11_8008E86C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x13:
        case 0x15:
        case 0x43:
        case 0x44:
        case 0x46:
        case 0x49:
        case 0x4b:
        case 0x4c:
        case 0x4d:
            func_80043ABC(0);
            break;
        case 0x47:
        case 0x48: {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            MATCHING_KEEP(state);
            if (*state)
                func_80043ABC(0);
            else
                func_80043ABC(&spyro.unk9e);
        } break;
        case 0x14:
        case 0x1a:
        case 0x20:
        case 0x2b:
        case 0x2c:
        case 0x41:
        case 0x42:
        case 0x45:
        case 0x4a:
            func_80043ABC(&spyro.unk9e);
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008E8FC.
 * Verified32 water/swirl,22 squish/death and skateboard scalar2000,
 * verified23 character41..4D. Original11 jump stack40 and water10/20/30;
 * original shared244/250 tail before41 and flags1B9/1BA tail after47 retained.
 * Numeric offsets are bytes. Word60 wrap800/801/FFF gives0/-7FF/-1;
 * signed table-2/0/2 gives-1/0/1. Each invocation preserves original code,
 * local jumps, owned tables; strict complete TU and all hashes required.
 * Helper meanings, physical units, audio, cadence and live parity remain open.
 */
int Transition11MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
extern short D_800658A0[];
extern short D_80065920[];
extern int Raw11Animation __asm__("D_80070328+0x48");
extern unsigned char Raw11Union[] __asm__("D_80070328+0x144");
extern unsigned char Raw11Movement[] __asm__("D_80070328+0x50");
extern int Raw11X __asm__("D_80070328+0x8C");
extern int Raw11Word __asm__("D_80070328+0x50");
extern int D_8006C700;
int Call11E9E4(int) __asm__("func_8004E9E4");
int Call11EA2C(int) __asm__("func_8004EA2C");
void Transition11ShiftVectorLeft(Vector3D*, int) __asm__("func_8004F0E8");
extern Spyro Transition11_D_80070328 __asm__("D_80070328");
int Transition11MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Transition11ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Transition11_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition11RawUnion[] __asm__("D_80070328+0x144");
extern int Transition11RawMovement __asm__("D_80070328+0x50");
extern void (*Call11Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw11State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call11A358(Vector3D*, int) __asm__("func_8001A358");
extern int Raw11NegativeWord __asm__("D_80070328+0x28");
int Transition11RandBetween(int, int) __asm__("func_8003636C");
void Transition11_func_800441F0(void) __asm__("func_800441F0");
void Transition11_func_80043A38(int) __asm__("func_80043A38");
int Transition11PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
void func_level_11_8008E8FC(int arg0) {
    struct {
        Vector3D first;
        int gap1;
        Vector3D second;
        int gap2;
        Vector3D third;
        int gap3;
        Vector3D fourth;
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
    int shiftedValue;
    register Vector3D* damageSource __asm__("$16");
    register Vector3D* damageDestination __asm__("$16");
    Vector3D* firstJumpSource;
    Vector3D* secondJumpSource;
    enum MovementState nextSubstate;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void* jumpPrivate __asm__("$18");
    register void* damagePrivate __asm__("$18");
    register Vector3D* jumpVector __asm__("$16");
    register int oldMovementC __asm__("$5");
    switch (arg0) {
        case 0x14:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.unk5 = 0;
            Transition11_func_800441F0();
            Transition11_D_80070328.grounded = 1;
            Transition11_D_80070328.union144.a.unk13cb = Transition11RandBetween(1, 3);
            Transition11_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x13: {
            register Moby* sourceMoby __asm__("$6");
            register int yawValue __asm__("$5");
            register int positionZ __asm__("$2");
            register int heightValue __asm__("$3");
            register int privateValue __asm__("$4");
            stateBase = (unsigned char*)&Transition11RawMovement;
            privateData = Transition11_D_80070328.m_WhirlwindPointer->mobyTag;
            *(int*)stateBase = 14;
            Transition11_D_80070328.unk5 = 0;
            Transition11_D_80070328.grounded = 0;
            Transition11ClearVector((Vector3D*)(stateBase + 0x3C));
            sourceMoby = Transition11_D_80070328.m_WhirlwindPointer;
            yawValue = Transition11_D_80070328.rotation.yaw;
            positionZ = Transition11_D_80070328.position.z;
            heightValue = sourceMoby->position.z;
            privateValue = *(int*)privateData;
            MATCHING_KEEP4(sourceMoby, yawValue, positionZ, heightValue);
            Transition11_D_80070328.union144.a.unk13cc = yawValue;
            Transition11_D_80070328.union144.a.unk13cb = positionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue += privateValue;
            Transition11_D_80070328.union144.a.unk13ce.x = heightValue;
            heightValue -= positionZ;
            heightValue -= 0x800;
            Transition11_D_80070328.union144.a.unk13ce.z = heightValue;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue = ((int)(heightValue << 0xA) >> 0xA) + 0x400;
            MATCHING_KEEP(heightValue);
            Transition11_D_80070328.union144.a.unk13ce.y = heightValue;
            maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
            Transition11_D_80070328.union144.a.unk13ce.y = maskedValue;
            if (maskedValue >= 0x801) {
                Transition11_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
            }
            Transition11_D_80070328.union144.a.unk13da = *(int*)(privateData + 4);
            func_8004F178((Vector3D*)(stateBase + 0x10C), &sourceMoby->position);
            Transition11_D_80070328.unk13e[0] =
                (int)Transition11_D_80070328.m_WhirlwindPointer->angle.yaw;
            positionZ = *(int*)(privateData + 8);
            MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
            Transition11_D_80070328.unk20a = 0;
            Transition11_D_80070328.critterMobyPtr = 0;
            Transition11_D_80070328.unk13e[1] = positionZ;
            return;
        }
        case 0x15:
            Transition11_D_80070328.movementState = 7;
            Transition11_D_80070328.grounded = 0;
            Transition11_D_80070328.unk5 = 0;
            if (Transition11_D_80070328.unk17a & 0x490) {
                register int first __asm__("$2") = Transition11_D_80070328.unk17e.x;
                register int second __asm__("$3") = Transition11_D_80070328.unk17e.z;
                register int third __asm__("$2");
                MATCHING_KEEP2(first, second);
                first <<= 6;
                Transition11_D_80070328.unk7a[2].x = first;
                MATCHING_BARRIER_VOLATILE("memory");
                third = Transition11_D_80070328.unk17e.y;
                MATCHING_KEEP2(third, second);
                second <<= 6;
                Transition11_D_80070328.unk7a[2].z = second;
                MATCHING_KEEP_VOLATILE_CLOBBER(third, "memory");
                third <<= 6;
                Transition11_D_80070328.unk7a[2].y = third;
            } else {
                shiftedValue = Transition11PlanarHeadingLookup(
                    -Transition11_D_80070328.unk7a[2].x, -Transition11_D_80070328.unk7a[2].y, 1);
                Transition11_D_80070328.unk7b = shiftedValue;
                Transition11_D_80070328.unk7a[2].x = (Call11EA2C(shiftedValue) << 12) >> 12;
                Transition11_D_80070328.unk7a[2].y =
                    (Call11E9E4(Transition11_D_80070328.unk7b) << 12) >> 12;
                Transition11_D_80070328.unk7a[2].z = 0x1000;
            }
            goto clearPointers;
        case 0x1A:
            savedBase = Transition11RawUnion;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            oldMovementC = Transition11RawMovement;
            Transition11RawMovement = MOVEMENT_STATE_HURT;
            Transition11_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementC;
            Transition11ClearVector(destination);
            Transition11_D_80070328.grounded = 1;
            Transition11_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            soundSelector = D_8006C654->squish;
            soundZero = 0;
            PlaySound(soundSelector, (Moby*)soundZero, 0);
            goto clearPointers;
        case 0x20:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition11_D_80070328.unk5 = 0;
            Transition11_func_80043A38(0xC00);
            Transition11_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Transition11_D_8006E524 = 0xF;
            goto clearPointers;
        case 0x24:
        case 0x25:
        case 0x30: {
            register unsigned char* state __asm__("$16") = Raw11State;
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
                Transition11_D_80070328.union144.a.unk13db.z = 0;
                Transition11_D_80070328.unk5 = 0;
                Transition11ClearVector((Vector3D*)(state + 0xFC));
                Transition11_D_80070328.union144.a.unk13da = 0;
                MATCHING_KEEP_VOLATILE_CLOBBER(state, "memory");
                destination = (Vector3D*)(state + 0x48);
            }
            *(int*)state = kind;
            Transition11_D_80070328.unk8[0] = Transition11MeasureVectorLength(destination, 0);
            currentScalar = D_8006C700;
            MATCHING_KEEP(currentScalar);
            scalar = 0x2000;
            MATCHING_KEEP(scalar);
            Transition11_D_80070328.horizontalSpeed = scalar;
            MATCHING_KEEP_VOLATILE_CLOBBER(currentScalar, "memory");
            if (currentScalar < 0x2000)
                D_8006C700 = scalar;
            Transition11_func_80043A38(0xC00);
            savedRoll = Transition11_D_80070328.rotation.roll;
            MATCHING_KEEP(savedRoll);
            Transition11_D_80070328.grounded = 1;
            Transition11_D_80070328.unk15c = 0;
            Transition11_D_80070328.union144.a.unk13cc = 0;
            Transition11_D_80070328.union144.a.unk13db.x = 0;
            Transition11_D_80070328.union144.a.unk13db.y = 0;
            Transition11_D_80070328.unk13a[0] = 0x20000;
            Transition11_D_80070328.union144.a.unk13cb = savedRoll;
            return;
        }
        case 0x28:
        case 0x29:
            if (((unsigned)(Transition11_D_80070328.movementState - 0xB) >= 2U) &&
                (Transition11_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
                if (SpawnParticle != 0) {
                    func_8004F178(
                        &vectors.first,
                        (Vector3D*)((unsigned char*)&Transition11_D_80070328.movementState - 0x50));
                    if ((Transition11_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw11NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.first.z = -negativeWord;
                        SpawnParticle(6, 0x2E, &vectors.first, 0);
                        firstParticleKind = 4;
                        firstParticleSubtype = 0x29;
                        goto emitFirstParticle;
                    }
                    if (Transition11_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        vectors.first.z += 0x400;
                        firstResult = Call11A358(&vectors.first, 0x800);
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
                firstWrappedWord = Transition11_D_80070328.rotation.pitch & 0xFFF;
                Transition11_D_80070328.rotation.pitch = firstWrappedWord;
                if (firstWrappedWord >= 0x801) {
                    Transition11_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
                }
                if (Transition11_D_80070328.rotation.pitch > 0) {
                    Transition11_D_80070328.rotation.pitch = 0;
                }
                if (arg0 == 0x28) {
                    Transition11_D_80070328.unk5 = 1;
                }
                Transition11ClearVector(
                    (Vector3D*)((unsigned char*)&Transition11_D_80070328.rotation.pitch + 0xEC));
                Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition11_D_80070328.unk8[0] = Transition11MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition11_D_80070328.rotation.pitch + 0x38), 0);
                Transition11_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
                goto clearUnderwaterWord;
            }
            if (Transition11_D_80070328.animationState == 0x2A) {
                Transition11_D_80070328.unk5 = 2;
            clearUnderwaterWord:
                Transition11_D_80070328.union144.a.unk13da = 0;
            }
            Transition11_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
            Transition11_D_80070328.unk20a = 0;
            Transition11_D_80070328.critterMobyPtr = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            goto clearPointers;
        case 0x2A: {
            register unsigned char* state __asm__("$17") = Raw11State;
            register Vector3D* localVector __asm__("$16");
            if ((unsigned)(*(int*)state - 0xB) >= 2U) {
                if (SpawnParticle != 0) {
                    localVector = &vectors.second;
                    func_8004F178(localVector, (Vector3D*)(state - 0x50));
                    if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) &&
                        (({
                             negativeWord = Raw11NegativeWord;
                             MATCHING_KEEP(negativeWord);
                             negativeWord;
                         }) < 0)) {
                        vectors.second.z = -negativeWord;
                        SpawnParticle(6, 0x2E, localVector, 0);
                        secondParticleKind = 4;
                        secondParticleSubtype = 0x29;
                        goto emitSecondParticle;
                    }
                    if (Transition11_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                        localVector = &vectors.second;
                        vectors.second.z += 0x400;
                        secondResult = Call11A358(localVector, 0x800);
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
                if (Transition11_D_80070328.animationState == 0x2E) {
                    Transition11_D_80070328.rotation.pitch -= 0x400;
                }
                secondWrappedWord = Transition11_D_80070328.rotation.pitch & 0xFFF;
                Transition11_D_80070328.rotation.pitch = secondWrappedWord;
                if (secondWrappedWord >= 0x801) {
                    Transition11_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
                }
                if (Transition11_D_80070328.rotation.pitch > 0) {
                    Transition11_D_80070328.rotation.pitch = 0;
                }
                Transition11_D_80070328.unk5 = 1;
                Transition11ClearVector(
                    (Vector3D*)((unsigned char*)&Transition11_D_80070328.animationState + 0x104));
                Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition11_D_80070328.unk8[0] = Transition11MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Transition11_D_80070328.animationState + 0x50), 0);
                Transition11_D_80070328.grounded = 1;
                PlaySound((int)D_8006C654->waterDive, 0, 0);
            }
            Transition11_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
            Transition11_D_80070328.unk13a[0] = 0x20000;
            goto clearPointers;
        }
        case 0x2B:
        case 0x2C: {
            register Vector3D* localVector __asm__("$16");
            register unsigned char* unionPointer __asm__("$17");
            {
                register int stateWord __asm__("$3") = Transition11RawMovement;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Transition11RawUnion;
                    *(int*)unionPointer = (-Transition11_D_80070328.unk7a[2].z) >> 2;
                    if (Transition11RawMovement != 8) {
                        Transition11_D_80070328.union144.a.unk13cc = 0x5900;
                        Transition11RawMovement = 10;
                    }
                    Transition11_D_80070328.unk5 = 0;
                    Transition11_D_80070328.unk8[0] =
                        Transition11MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition11_D_80070328.grounded = 1;
                    Transition11_D_80070328.unk15b = 1;
                    localVector = &vectors.third;
                    func_8004F178(localVector, (Vector3D*)(unionPointer - 0x144));
                    vectors.third.z += 0x400;
                    lengthResult = Call11A358(localVector, 0x800);
                    vectors.third.z = lengthResult;
                    if (lengthResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, localVector, 0);
                        SpawnParticle(6, 0x2E, localVector, 0);
                    }
                }
            }
            goto clearPointers;
        }
        clearPointers:
            Transition11_D_80070328.unk20a = 0;
            Transition11_D_80070328.critterMobyPtr = 0;
            return;
        case 0x41:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition11_func_800441F0();
            Transition11_D_80070328.grounded = 1;
            return;
        case 0x42:
        case 0x45:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_WALK;
            if ((arg0 == 0x57) && (Transition11_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
                func_8004F178(
                    (Vector3D*)((
                        Vector3D*)((unsigned char*)(&Transition11_D_80070328.movementState) +
                                   0x3C)),
                    (Vector3D*)((
                        Vector3D*)((unsigned char*)(&Transition11_D_80070328.movementState) +
                                   0x48)));
                Transition11_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            } else {
                Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            }
            Transition11_D_80070328.unk8[0] =
                Transition11MeasureVectorLength(&Transition11_D_80070328.unk7a[3], 0);
            Transition11_func_80043A38(0xC00);
            Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.grounded = 1;
            goto clearFlags;
        case 0x43:
        case 0x49:
            initialMovement = Raw11Movement;
            MATCHING_KEEP(initialMovement);
            comparisonKind = 10;
            MATCHING_KEEP(comparisonKind);
            {
                register Moby* critter __asm__("$3") = Transition11_D_80070328.critterMobyPtr;
                register int current __asm__("$4") = *(int*)initialMovement;
                MATCHING_KEEP2(critter, current);
                jumpPrivate = critter->mobyTag;
                MATCHING_KEEP(jumpPrivate);
                if ((current == comparisonKind) && (SpawnParticle != 0) &&
                    (Transition11_D_80070328.unk4[0] < 0)) {
                    jumpVector = &vectors.fourth;
                    func_8004F178(jumpVector, (Vector3D*)(initialMovement - 0x50));
                    vectors.fourth.z = -Transition11_D_80070328.unk4[0];
                    SpawnParticle(6, 0x2E, jumpVector, 0);
                    SpawnParticle(4, 0x29, jumpVector, 0);
                }
            }
            movement = Raw11Movement;
            MATCHING_KEEP(movement);
            firstJumpSource = (Vector3D*)(movement + 0x48);
            *(int*)movement = MOVEMENT_STATE_JUMP_HOVER;
            func_8004F178((Vector3D*)(movement + 0x3C), (Vector3D*)firstJumpSource);
            Transition11_D_80070328.unk8[0] =
                Transition11MeasureVectorLength((Vector3D*)firstJumpSource, 0);
            if (arg0 == 0x49) {
                Transition11_D_80070328.unk7a[2].z = 0x2580;
            } else {
                Transition11_D_80070328.unk7a[2].z = 0x1680;
                *(int*)((unsigned char*)jumpPrivate + 0x4C) = 0;
            }
            Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.grounded = 0;
            soundSelector = D_8006C654->jump;
            soundZero = 0;
            goto playJumpSound;
        case 0x44:
            Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            if (Transition11_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
                if (Transition11_D_80070328.animationState == 0x43)
                    Transition11_D_80070328.unk5 = 1;
                else if (Transition11_D_80070328.animationState == 0x46)
                    Transition11_D_80070328.unk5 = Transition11_D_80070328.movementState;
                else if (Transition11_D_80070328.animationState == 0x49)
                    Transition11_D_80070328.unk5 = 4;
            } else {
                Transition11_D_80070328.movementState = MOVEMENT_STATE_FALL;
            }
            Transition11_D_80070328.unk8[0] =
                Transition11MeasureVectorLength(&Transition11_D_80070328.unk7a[3], 0);
            Transition11_D_80070328.grounded = 0;
            goto clearFlags;
        case 0x46:
            movement = Raw11Movement;
            MATCHING_KEEP(movement);
            secondJumpSource = (Vector3D*)(movement + 0x48);
            *(int*)movement = MOVEMENT_STATE_JUMP_HOVER;
            func_8004F178((Vector3D*)(movement + 0x3C), (Vector3D*)secondJumpSource);
            Transition11_D_80070328.unk8[0] =
                Transition11MeasureVectorLength((Vector3D*)secondJumpSource, 0);
            Transition11_D_80070328.unk7a[2].z = 0x12C0;
            Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition11_D_80070328.grounded = 0;
            soundSelector = D_8006C654->jump;
            soundZero = 0;
        playJumpSound:
            PlaySound(soundSelector, (Moby*)soundZero, 0);
            return;
        case 0x47:
            if (Transition11_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                if (Transition11_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                    if (Transition11_D_80070328.animationState == 0x43) {
                        Transition11_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                    } else if (Transition11_D_80070328.animationState == 0x46) {
                        Transition11_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                    } else {
                        Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                    }
                }
                Transition11_D_80070328.movementState = MOVEMENT_STATE_FALL;
                Transition11_D_80070328.grounded = 0;
                Transition11_D_80070328.idle = 0;
                Transition11_D_80070328.unk15g = 0;
            } else {
                Transition11_D_80070328.movementState = MOVEMENT_STATE_WALK;
                Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                Transition11_func_80043A38(0xC00);
                Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Transition11_D_80070328.grounded = 1;
            }
            Transition11_D_80070328.unk8[0] =
                Transition11MeasureVectorLength(&Transition11_D_80070328.unk7a[3], 0);
            goto clearFlags;
        clearFlags:
            Transition11_D_80070328.idle = 0;
            Transition11_D_80070328.unk15g = 0;
            return;
        case 0x48: {
            register Moby* critter __asm__("$2") = Transition11_D_80070328.critterMobyPtr;
            MATCHING_KEEP_VOLATILE_CLOBBER(critter, "memory");
            damagePrivate = critter->mobyTag;
            MATCHING_KEEP_VOLATILE_CLOBBER(damagePrivate, "memory");
            previousValue = Raw11Word;
            MATCHING_KEEP_VOLATILE_CLOBBER(previousValue, "memory");
            unionBase = Raw11Union;
            MATCHING_KEEP2(previousValue, unionBase);
            *(int*)unionBase = previousValue;
            Raw11Word = MOVEMENT_STATE_HURT;
            if (Transition11_D_80070328.damageFlags & 8) {
                damageSource = (Vector3D*)(unionBase - 0xAC);
                Transition11_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                func_8004F178((Vector3D*)(unionBase - 0xB8), damageSource);
                Transition11_D_80070328.unk8[0] = Transition11MeasureVectorLength(damageSource, 0);
                soundTable = (unsigned char*)D_8006C654;
                soundZero = 0;
                MATCHING_KEEP2_VOLATILE_CLOBBER(soundTable, soundZero, "memory");
                Transition11_D_80070328.unk7a[2].z = 0x1680;
                *(int*)((unsigned char*)damagePrivate + 0x4C) = 0;
                Transition11_D_80070328.grounded = 0;
                Transition11_D_80070328.union144.a.unk13cc = 1;
                PlaySound(soundTable[12], (Moby*)soundZero, 0);
            } else {
                Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                damageDestination = (Vector3D*)(unionBase - 0xB8);
                if (Transition11_D_80070328.unk17a & 0x400) {
                    func_8004F178(damageDestination, (Vector3D*)((Vector3D*)(unionBase + 0xD8)));
                    Transition11ShiftVectorLeft(damageDestination, 6);
                } else if (Transition11_D_80070328.unk22[5] >= 0) {
                    tableIndex = Transition11_D_80070328.unk22[5] * 2;
                    tableValue = *(short*)((unsigned char*)D_80065920 + tableIndex);
                    MATCHING_KEEP(tableValue);
                    Raw11X = tableValue >> 1;
                    tableIndex = *(short*)((unsigned char*)D_800658A0 + tableIndex);
                    Transition11_D_80070328.unk7a[2].z = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tableIndex, "memory");
                    Transition11_D_80070328.unk7a[2].y = tableIndex >> 1;
                } else {
                    MATCHING_KEEP(unionBase);
                    Transition11ClearVector((Vector3D*)(unionBase - 0xB8));
                }
                func_8004F178(
                    &Transition11_D_80070328.unk7a[1],
                    (Vector3D*)((unsigned char*)(&Transition11_D_80070328.unk7a[1]) + 0xC));
                Transition11_func_80043A38(0xC00);
                Transition11_D_80070328.grounded = 1;
            }
            Transition11_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
                return;
            }
            break;
        }
        case 0x4A:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition11_func_80043A38(0xC00);
            Transition11_D_80070328.grounded = 1;
            Transition11_D_8006E524 = 0xF;
            return;
        case 0x4B:
            firstAnimation = Raw11Animation;
            MATCHING_KEEP(firstAnimation);
            if (firstAnimation == 0x44) {
                if (Transition11_D_80070328.unk5 == 4)
                    goto setHeadbashFlag;
                comparisonKind = 0x49;
                MATCHING_KEEP_VOLATILE_CLOBBER(comparisonKind, "memory");
                firstAnimation = Raw11Animation;
                MATCHING_KEEP(firstAnimation);
            } else
                comparisonKind = 0x49;
            if (firstAnimation == comparisonKind) {
            setHeadbashFlag:
                Transition11_D_80070328.union144.a.unk13cc = 1;
            } else
                Transition11_D_80070328.union144.a.unk13cc = 0;
            Transition11_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
            Transition11_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition11ClearVector((Vector3D*)((
                Vector3D*)((unsigned char*)(&Transition11_D_80070328.movementState) + 0x3C)));
            Transition11_D_80070328.unk7a[2].z = 0x800;
            Transition11_D_80070328.grounded = 0;
            Transition11_D_80070328.unk13a[0] = 0x20000;
            Transition11_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            return;
        case 0x4C:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
            nextSubstate = 1;
            goto setHeadbashSubstate;
        case 0x4D:
            Transition11_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
            nextSubstate = 2;
        setHeadbashSubstate:
            Transition11_D_80070328.unk5 = nextSubstate;
            Transition11_D_80070328.grounded = 0;
            Transition11_D_80070328.unk13a[0] = 0x20000;
            return;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008F910.
 * Assembly SHA256 443bfa15c83fcdc7d300c4f54c4b6c4ac1a282f14a6c83d1926bcac5e8926483.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1838 original instructions and59 state-table entries (bias19).
 * Original65..77 Sheila chains reuse the fully matched level23 baseline.
 * Each outer case cluster uses the target selectors; original49/66 guarded
 * exits remain distinct. View names preserve the original typed aliases;
 * exact symbol identities and per-state donor provenance are recorded.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim11Player48View1 __asm__("D_80070328 + 0x48");
extern unsigned char* Anim11Player250View1 __asm__("D_80070328 + 0x250");
extern int Anim11Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim11Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim11Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim11PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim11PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim11PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim11PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim11PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim11PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim11Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim11Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim11PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim11Player158View1 __asm__("D_80070328 + 0x158");
extern int Anim11Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim11Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim11Player240View1 __asm__("D_80070328 + 0x240");
extern unsigned char Anim11Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim11Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim11Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim11Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim11PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim11Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim11Data66530View1[] __asm__("D_80066530");
extern int Anim11Data6E538View1 __asm__("D_8006E538"), Anim11Data6E53CView1 __asm__("D_8006E53C");
extern int Anim11Data6E044View1 __asm__("D_8006E044"), A4898Gate __asm__("D_8006E344"),
    A4898Count __asm__("D_8006C514");
int Anim11Call40994View1() __asm__("func_80040994");
int Anim11Call4BEF8View1() __asm__("func_8004BEF8");
int Anim11Call49688View1() __asm__("func_80049688");
extern int Anim11Player10CView1 __asm__("D_80070328 + 0x10C");
int Anim11Call40954View1() __asm__("func_80040954");
extern int Anim11PlayerBCView1 __asm__("D_80070328 + 0xBC");
extern int Anim11Player160View1 __asm__("D_80070328 + 0x160");
extern int Anim11Player15CView1 __asm__("D_80070328 + 0x15C");
extern int Anim11Player88View1 __asm__("D_80070328 + 0x88");
extern int Anim11Player84View1 __asm__("D_80070328 + 0x84");
extern int Anim11Player68View1 __asm__("D_80070328 + 0x68");
extern int Anim11Player6CView1 __asm__("D_80070328 + 0x6C");
int Anim11PlayMobySoundEventView1() __asm__("func_8003BABC");
int Anim11SubtractVectorView1() __asm__("func_8004F1C8");
int Anim11MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Anim11PlayMobySoundEventView2() __asm__("func_8003BABC");
int Anim11TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Anim11NormalizeVectorToLengthView1() __asm__("func_8004EF04");
int Anim11Call41848View1() __asm__("func_80041848");
int Anim11CopyVectorView1() __asm__("func_8004F178");
int Anim11ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
int Anim11AddVectorView1() __asm__("func_8004F194");
int Anim11Call43E00View1() __asm__("func_80043E00");
int Anim11ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Anim11SubtractVectorView2() __asm__("func_8004F1C8");
int Anim11MeasureVectorLengthView2() __asm__("func_8004EDE8");
extern int Anim11Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim11Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim11PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim11PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim11Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim11Player158View2 __asm__("D_80070328 + 0x158");
extern int Anim11Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim11Player0View1[] __asm__("D_80070328");
extern int Anim11Data6E538View2 __asm__("D_8006E538"), Anim11Data6E53CView2 __asm__("D_8006E53C");
extern int Anim11Data6E044View2 __asm__("D_8006E044"), Anim11Data6E344View1 __asm__("D_8006E344"),
    Anim11Data6C514View1 __asm__("D_8006C514");
extern int (*Anim11Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim11Player24View1 __asm__("D_80070328 + 0x24");
extern unsigned char* Anim11Data6C654View1 __asm__("D_8006C654");
int Anim11CallPlaySoundView1() __asm__("PlaySound");
int Anim11Call40994View2() __asm__("func_80040994");
int Anim11Call4BEF8View2() __asm__("func_8004BEF8");
int Anim11ApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Anim11Call498C0View1() __asm__("func_800498C0");
extern volatile int Anim11Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim11Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim11Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim11Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim11Data6EE2CView1 __asm__("D_8006EE2C");
int Anim11Call40BCCView1() __asm__("func_80040BCC");
int Anim11Call1A310View1() __asm__("func_8001A310");
extern int Anim11Player44View1 __asm__("D_80070328 + 0x44");
extern int Anim11Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim11Player4CView3 __asm__("D_80070328 + 0x4C");
extern int Anim11Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim11Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim11Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim11Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim11Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim11Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim11PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim11PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim11PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim11PlayerB8View3 __asm__("D_80070328 + 0xB8");
extern int Anim11PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim11PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim11PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim11PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim11Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim11Player280View2 __asm__("D_80070328 + 0x280");
extern unsigned char Anim11Player0View2[] __asm__("D_80070328");
extern unsigned char* Anim11Player250View2 __asm__("D_80070328 + 0x250");
extern unsigned char Anim11Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim11Data6E535View2 __asm__("D_8006E535");
extern int Anim11Data6E538View3 __asm__("D_8006E538");
extern int Anim11Data6E53CView3 __asm__("D_8006E53C");
extern int Anim11Data6E530View1 __asm__("D_8006E530");
extern int Anim11Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char* Anim11Data6C654View2 __asm__("D_8006C654");
extern int (*Anim11Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim11DataSpawnParticleView1)(int, int, void*, int) __asm__("SpawnParticle");
int Anim11Call55E84View1(void*) __asm__("func_80055E84");
int Anim11Call1A358View1(void*, int) __asm__("func_8001A358");
int Anim11Call4BEF8View3(int) __asm__("func_8004BEF8");
int Anim11CallPlaySoundView2(unsigned char, int, int) __asm__("PlaySound");
#define Anim11Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_level_11_8008F910(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
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
    rawValue2 = Anim11Player48View1;
    switch (rawValue2) {
        case 20:
            if (Anim11Call40994View1())
                return;
            rawValue2 = Anim11Data6E53CView1 & 64;
            nextSelector4 = 6;
            if (rawValue2)
                goto select;
            rawValue2 = Anim11PlayerB8View1 < 4;
            nextSelector4 = 7;
            if (!rawValue2)
                goto select;
            if (Anim11PlayerE4View1 >= 23)
                goto select;
            rawValue3 = Anim11Data6E538View1;
            rawValue2 = rawValue3 & 128;
            nextSelector4 = 13;
            if (rawValue2)
                goto select;
            rawValue2 = Anim11PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            if (rawValue2 >= 17) {
                nextSelector4 = 1;
                goto select;
            }
            rawValue2 = rawValue3 & 12;
            MATCHING_KEEP(rawValue2);
            if (!rawValue2) {
                rawValue2 = Anim11PlayerACView1;
                nextSelector4 = 1;
                if (rawValue2)
                    goto select;
            }
            if (Anim11Data6E044View1 == 7 || Anim11Player240View1) {
                savedPointer16 = &Anim11Player48View2;
                MATCHING_KEEP(savedPointer16);
                if (!*savedPointer16)
                    return;
                Anim11Call4BEF8View1(0);
                if (Anim11Data66530View1[*((unsigned char*)savedPointer16 - 0x2C)] >= 96) {
                    Anim11Player14View1 = Anim11Player15View1;
                    Anim11Player16View1 = Anim11Player17View1;
                }
                Anim11Player17View1 = 0;
                rawValue3 = *savedPointer16;
                rawValue2 = 113;
                *((unsigned char*)savedPointer16 - 0x2C) = rawValue2;
                Anim11Player1F0View1 = 0;
                Anim11Player15View1 = rawValue3;
                Anim11Player1ECView1 = rawValue3;
                return;
            }
            rawValue2 = Anim11PlayerFCView1;
            nextSelector4 = 15;
            if (rawValue2)
                goto select;
            Anim11Call49688View1();
            return;
        case 19:
            if (Anim11Call40994View2())
                return;
            rawValue2 = 13;
            rawValue3 = Anim11Data6E344View1;
            if (rawValue3 == rawValue2) {
                rawValue2 = Anim11Data6C514View1;
                nextSelector4 = 17;
                if (rawValue2)
                    goto select;
            }
            nextSelector4 = (int)Anim11Player0View1;
            rawValue2 = Anim11ApproximatePlanarDistanceView1((void*)nextSelector4,
                                                             (void*)(nextSelector4 + 348));
            rawValue3 = Anim11Player158View2;
            rawValue3 = rawValue3 < rawValue2;
            nextSelector4 = 17;
            if (!rawValue3)
                return;
            goto select;
        case 21:
            if (Anim11Player54View1 < 33)
                return;
            if (!Anim11PlayerB8View1) {
                Anim11Call4BEF8View1(4);
                Anim11Player4CView1 = 1;
                return;
            }
            rawValue2 = Anim11PlayerBCView1;
            nextSelector4 = 7;
            if (rawValue2)
                return;
            goto select;
        case 26:
            if (Anim11Player24View1 & 16)
                return;
            if (Anim11Player54View2 < 25)
                return;
            if (Anim11Player280View1 < 0) {
                nextSelector4 = 32;
                goto select;
            }
            Anim11CallPlaySoundView1(Anim11Data6C654View1[15], 0, 0);
            rawValue3 = Anim11Player144View1;
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
            rawValue2 = Anim11PlayerB8View2;
            nextSelector4 = 0;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            nextSelector4 = 7;
            goto select;
        case 32:
            if (Anim11Player54View2 < 125)
                return;
        call498C0:
            Anim11Call498C0View1();
            return;
        case 36:
            if (Anim11Call40994View1())
                return;
            saved16 = &Anim11Player4CView1;
            rawValue2 = *saved16;
            if ((unsigned)(rawValue2 - 1) < 2 && !Anim11PlayerB8View1) {
                if (Anim11PlayerE4View1 >= 60)
                    goto expired36;
                frame.at10[0] = 0;
                frame.at10[1] = 0;
                frame.at10[2] = 4096;
                Anim11TransformVectorByBasisView1(saved16 - 7, frame.at10, frame.at10);
                Anim11NormalizeVectorToLengthView1(saved16 + 32, 4096);
                rawValue3 = frame.at10[0];
                rawValue2 = saved16[32];
                product5 = rawValue3 * rawValue2;
                rawValue3 = frame.at10[1];
                rawValue2 = Anim11PlayerD0View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = frame.at10[2];
                rawValue2 = Anim11PlayerD4View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                rawValue2 >>= 12;
                nextSelector4 = 21;
                if (rawValue2 < 1536)
                    goto select;
                product5 = 2;
                object4 = Anim11Player250View1;
                MATCHING_KEEP(object4);
                call6 = 0;
                MATCHING_KEEP3(object4, product5, call6);
                *saved16 = 0;
                Anim11PlayMobySoundEventView1(object4, product5, call6);
                return;
            expired36:
                MATCHING_BARRIER_VOLATILE("memory");
                nextSelector4 = 21;
                goto select;
            }
            state4 = &Anim11Player4CView1;
            rawValue3 = *state4;
            rawValue2 = 3;
            if (rawValue3 == rawValue2) {
                if (Anim11Data6E538View1 & 64)
                    Anim11Player1B6View1 = 1;
                rawValue2 = Anim11Call40954View1(Anim11Player10CView1);
                rawValue3 = 9;
                if (rawValue2 != rawValue3) {
                    if (Anim11PlayerA0View1 > 0 && Anim11Player160View1 >= 4)
                        Anim11PlayerB8View1 = 1;
                    else
                        Anim11Player4CView1 = 0;
                }
                saved17 = &Anim11PlayerB8View1;
                MATCHING_KEEP(saved17);
                rawValue2 = *saved17;
                if (!rawValue2)
                    goto remainder36;
                if (Anim11Player158View1 <= 2048)
                    goto reset36;
                Anim11Call41848View1();
                rawValue3 = Anim11Player15CView1;
                rawValue2 = 2;
                if (rawValue3 == rawValue2) {
                    nextSelector4 = 48;
                    if (Anim11Player1B6View1) {
                        rawValue2 = Anim11Player88View1;
                        rawValue2 += 3840;
                        Anim11Player88View1 = rawValue2;
                        rawValue2 = 4;
                        goto set36;
                    }
                    rawValue2 = 4;
                    goto set36;
                }
                if (Anim11Player1B6View1 || rawValue3 == 1) {
                    Anim11CopyVectorView1(frame.at10, saved17 + 37);
                    frame.at10[2] = 0;
                    Anim11NormalizeVectorToLengthView1(frame.at10, 4096);
                    rawValue3 = frame.at10[0];
                    rawValue2 = saved17[-14];
                    call6 = rawValue3 * rawValue2;
                    rawValue3 = frame.at10[1];
                    rawValue2 = Anim11Player84View1;
                    rawValue3 *= rawValue2;
                    call6 += rawValue3;
                    call6 >>= 12;
                    call6 = -call6;
                    Anim11ScaleVectorRatioQ15View1(frame.at10, 4096, call6);
                    saved16 = saved17 - 14;
                    Anim11Player88View1 += 2048;
                    Anim11AddVectorView1(saved16, saved16, frame.at10);
                    Anim11Call43E00View1(saved16);
                    Anim11ShiftVectorRightTowardZeroView1(frame.at10, 4);
                    Anim11AddVectorView1(saved17 - 46, saved17 - 46, frame.at10);
                    nextSelector4 = 37;
                    Anim11Player68View1 = 0;
                    Anim11Player6CView1 = 0;
                    rawValue2 = 5;
                    goto set36;
                }
                nextSelector4 = 48;
                rawValue2 = 4;
            set36:
                Anim11Player4CView1 = rawValue2;
                Anim11Call4BEF8View1(nextSelector4);
                Anim11PlayMobySoundEventView2(Anim11Player250View1, 1, 0);
                saved16 = &Anim11Player8CView1;
                nextSelector4 = (int)saved16;
                MATCHING_KEEP(nextSelector4);
                saved17 = saved16 - 3;
                Anim11CopyVectorView1((void*)nextSelector4, saved17);
                Anim11CopyVectorView1(saved16 + 3, saved17);
                return;
            reset36:
                Anim11Player4CView1 = 0;
                goto remainder36;
            }
            if (rawValue3)
                goto remainder36;
            if (Anim11PlayerB8View1 < 5 && (Anim11Data6E53CView1 & 64)) {
                rawValue2 = 1;
                rawValue3 = Anim11PlayerA0View1;
                *state4 = rawValue2;
                Anim11Player54View1 = 0;
                rawValue3 += 3520;
                Anim11Player94View1 = rawValue3;
                return;
            }
            rawValue2 = Anim11PlayerB8View1;
            if (rawValue2) {
                rawValue2 = rawValue2 < 5;
                goto count36;
            }
            rawValue2 = Anim11PlayerE4View1;
            rawValue2 = rawValue2 < 48;
            nextSelector4 = 21;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim11PlayerB8View1;
            rawValue2 = rawValue2 < 5;
        count36:
            if (!rawValue2) {
                rawValue2 = 1;
                Anim11Player4CView1 = rawValue2;
                Anim11Player54View1 = 0;
            }
        remainder36:
            saved18 = frame.at20;
            nextSelector4 = (int)saved18;
            MATCHING_KEEP(nextSelector4);
            saved16 = &Anim11Player8CView1;
            product5 = (int)saved16;
            MATCHING_KEEP(product5);
            saved17 = saved16 + 3;
            Anim11SubtractVectorView1((void*)nextSelector4, (void*)product5, saved17);
            saved19 = frame.at30;
            Anim11SubtractVectorView1(saved19, saved16 - 3, saved17);
            rawValue2 = Anim11MeasureVectorLengthView1(saved18, 1);
            rawValue3 = Anim11PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            if (rawValue2 < 218)
                return;
            rawValue2 = Anim11MeasureVectorLengthView1(saved19, 1);
            rawValue3 = Anim11PlayerACView1;
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
            if (Anim11Call40994View1())
                return;
            saved16 = &Anim11PlayerB8View1;
            if (!*saved16 && Anim11PlayerE4View1 < 60) {
                frame.at40[0] = 0;
                frame.at40[1] = 0;
                frame.at40[2] = 4096;
                Anim11TransformVectorByBasisView1(saved16 - 34, frame.at40, frame.at40);
                Anim11NormalizeVectorToLengthView1(saved16 + 5, 4096);
                rawValue3 = frame.at40[0];
                rawValue2 = saved16[5];
                product5 = rawValue3 * rawValue2;
                rawValue3 = frame.at40[1];
                rawValue2 = Anim11PlayerD0View1;
                nextSelector4 = rawValue3 * rawValue2;
                rawValue3 = frame.at40[2];
                rawValue2 = Anim11PlayerD4View1;
                rawValue3 *= rawValue2;
                rawValue2 = product5 + nextSelector4;
                rawValue2 += rawValue3;
                rawValue2 >>= 12;
                nextSelector4 = 21;
                if (rawValue2 < 1536)
                    goto select;
                Anim11Player4CView1 = 0;
                Anim11Call4BEF8View1(36);
                object4 = Anim11Player250View1;
                product5 = 2;
                goto partialBABC;
            }
            saved18 = frame.at50;
            nextSelector4 = (int)saved18;
            MATCHING_KEEP(nextSelector4);
            saved16 = &Anim11Player8CView1;
            product5 = (int)saved16;
            MATCHING_KEEP(product5);
            saved17 = saved16 + 3;
            Anim11SubtractVectorView2((void*)nextSelector4, (void*)product5, saved17);
            saved19 = frame.at60;
            Anim11SubtractVectorView2(saved19, saved16 - 3, saved17);
            rawValue2 = Anim11MeasureVectorLengthView2(saved18, 1);
            rawValue3 = Anim11PlayerACView1;
            rawValue2 <<= 8;
            rawValue2 /= rawValue3;
            if (rawValue2 < 218)
                return;
            rawValue2 = Anim11MeasureVectorLengthView2(saved19, 1);
            rawValue3 = Anim11PlayerACView1;
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
            if (Anim11Call40994View1())
                return;
            saved17 = &Anim11PlayerB8View1;
            if (*saved17)
                return;
            if (Anim11PlayerE4View1 >= 60)
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
            Anim11TransformVectorByBasisView1((void*)nextSelector4, (void*)product5, (void*)call6);
            Anim11NormalizeVectorToLengthView1(saved17 + 5, 4096);
            rawValue3 = frame.at70[0];
            rawValue2 = saved17[5];
            product5 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[1];
            rawValue2 = Anim11PlayerD0View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[2];
            rawValue2 = Anim11PlayerD4View1;
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
            Anim11TransformVectorByBasisView1(saved19, saved16, saved16);
            saved16 = frame.at80;
            Anim11CopyVectorView1(saved16, saved17 - 8);
            Anim11NormalizeVectorToLengthView1(saved16, 4096);
            rawValue3 = frame.at70[0];
            rawValue2 = frame.at80[0];
            product5 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[1];
            rawValue2 = frame.at80[1];
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = frame.at70[2];
            rawValue2 = frame.at80[2];
            rawValue3 *= rawValue2;
            Anim11Player4CView1 = 0;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            rawValue2 >>= 12;
            nextSelector4 = 21;
            if (rawValue2 < 2560)
                goto select;
            Anim11Call4BEF8View1(36);
            object4 = Anim11Player250View1;
            product5 = 2;
        partialBABC:
            Anim11PlayMobySoundEventView2(object4, product5, 0);
            return;
        case 40:
            if (Anim11Call40994View2())
                return;
            if ((Anim11Data6E538View2 & 128) && Anim11Player4CView2 != 1) {
                nextSelector4 = 42;
                goto select;
            }
            if (Anim11PlayerB0View1)
                return;
            rawValue2 = Anim11Player20CView1 & 64;
            nextSelector4 = 41;
            if (!rawValue2)
                goto select;
            if (Anim11Player214View1 <= 0)
                return;
            goto select;
        case 41:
            if (Anim11Call40994View2())
                return;
            nextSelector4 = Anim11Data6E538View2;
            rawValue2 = nextSelector4 & 128;
            if (rawValue2) {
                nextSelector4 = 42;
                goto select;
            }
            rawValue2 = 7;
            rawValue3 = Anim11Data6E044View2;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = nextSelector4 & 64;
            nextSelector4 = 40;
            if (rawValue2)
                goto select;
            if (!(Anim11Player20CView1 & 64))
                return;
            if (!Anim11Player214View1)
                goto select;
            return;
        case 42:
            if (Anim11Call40BCCView1())
                return;
            if ((Anim11Data6E538View2 & 128) || Anim11Player4CView2 == 1)
                goto flag64;
            rawValue2 = Anim11Player20CView1 & 128;
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        flag64:
            rawValue2 = Anim11Player20CView1 & 64;
            nextSelector4 = 40;
            if (!rawValue2)
                return;
            goto select;
        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (Anim11Call40994View2())
                return;
            if ((Anim11Data6E53CView2 & 64) && Anim11Player54View2 >= 9) {
                nextSelector4 = 6;
                goto partialCall;
            }
            byte4 = &Anim11Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto partialCall;
            }
            if (!(Anim11Data6E53CView2 & 128))
                goto check44;
            if (Anim11Player54View2 < 9)
                goto check44;
            rawValue2 = *(int*)(Anim11Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto check44;
            rawValue2 = Anim11Call1A310View1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (rawValue2)
                goto check44;
            goto select;
        partialCall:
            Anim11Call4BEF8View2(nextSelector4);
        check44:
            rawValue2 = Anim11Data6E535View1;
            nextSelector4 = 44;
            if (!rawValue2)
                return;
            goto select;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3 = Anim11Player4CView2;
            rawValue2 = 1;
            if (rawValue3 != rawValue2)
                goto other44;
            if (Anim11Data6E53CView2 & 0x850)
                goto callback44;
            if (Anim11Player54View2 < 61)
                return;
        callback44:
            callback2 = Anim11Data74374View1;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto missingCallback;
            callback2();
            return;
        missingCallback:
            goto call498C0;
        other44:
            if (Anim11Call40994View2())
                return;
            if ((Anim11Data6E53CView2 & 64) && Anim11Player54View2 >= 9) {
                nextSelector4 = 6;
                goto select;
            }
            byte4 = &Anim11Player100View1;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                nextSelector4 = 7;
                goto select;
            }
            if (!(Anim11Data6E53CView2 & 128))
                goto mode44;
            if (Anim11Player54View2 < 9)
                goto mode44;
            rawValue2 = *(int*)(Anim11Data6EE2CView1 + 220);
            byte4 -= 256;
            if (!rawValue2)
                goto mode44;
            rawValue2 = Anim11Call1A310View1(byte4, 1024, 1, 0);
            nextSelector4 = 40;
            if (!rawValue2)
                goto select;
        mode44:
            rawValue3 = Anim11Data6E044View2;
            rawValue2 = 7;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = Anim11Data6E535View1;
            nextSelector4 = 43;
            if (rawValue2)
                return;
            goto select;
        }
        case 65:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 64;
            if (rawValue2) {
                rawValue2 = (int)Anim11Player250View2;
                rawValue2 = (int)Anim11Field((void*)rawValue2, void**, 0);
                rawValue2 = Anim11Field((void*)rawValue2, int*, 0x48);
                rawValue2 = rawValue2 < 8;
                nextSelector4 = 67;
                if (!rawValue2)
                    goto select;
                __asm__ volatile("" ::"i"(0x800908F8) : "memory");
                nextSelector4 = 73;
                goto select;
            }
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = Anim11PlayerB8View3 < 4;
            nextSelector4 = 68;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11PlayerA8View2;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 66;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11Data6E538View3 & 12;
            if (rawValue2)
                return;
            rawValue2 = Anim11PlayerACView2;
            if (!rawValue2)
                return;
            goto select;
        case 66:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 64;
            if (rawValue2) {
                rawValue2 = (int)Anim11Player250View2;
                rawValue2 = (int)Anim11Field((void*)rawValue2, void**, 0);
                rawValue2 = Anim11Field((void*)rawValue2, int*, 0x48);
                rawValue2 = rawValue2 < 8;
                nextSelector4 = 67;
                if (!rawValue2)
                    goto select;
                __asm__ volatile("" ::"i"(0x800909EC) : "memory");
                nextSelector4 = 73;
                goto select;
            }
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = Anim11PlayerB8View3 < 4;
            nextSelector4 = 68;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                goto query66;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (rawValue2)
                goto input66;
        query66:
            rawValue2 = Anim11Call55E84View1((void*)nextSelector4);
            rawValue2 = rawValue2 < 4;
            if (!rawValue2)
                return;
        input66:
            rawValue2 = Anim11Data6E535View2;
            if (!rawValue2)
                goto held66;
            rawValue2 = Anim11PlayerB0View2;
            nextSelector4 = 65;
            if (!rawValue2)
                goto select;
        held66:
            rawValue2 = Anim11Data6E538View3 & 12;
            if (!rawValue2)
                return;
            rawValue2 = Anim11Player144View2 < 16;
            nextSelector4 = 65;
            if (rawValue2)
                return;
            goto select;
        case 67:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue2 = Anim11Player54View3 < 16;
            if (!rawValue2) {
                rawValue2 = Anim11Data6E53CView3 & 64;
                nextSelector4 = 70;
                if (rawValue2)
                    goto select;
            }
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 16;
            if (rawValue2) {
                product5 = Anim11Player44View1;
                nextSelector4 = (int)Anim11Player0View2;
                rawValue2 = Anim11Call1A358View1((void*)nextSelector4, product5 + 512);
                nextSelector4 = 75;
                if (!rawValue2)
                    goto select;
            }
            rawValue2 = Anim11PlayerB8View3;
            if (rawValue2)
                goto finish67;
            rawValue2 = Anim11Player54View3 < 16;
            if (rawValue2)
                goto finish67;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim11PlayerCCView1;
            rawValue2 = Anim11Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim11PlayerD0View2;
            rawValue2 = Anim11Player90View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim11PlayerD4View2;
            rawValue2 = Anim11Player94View2;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim11PlayerACView2;
            nextSelector4 = 66;
            if (!rawValue2)
                goto select65;
            __asm__ volatile("" ::"i"(0x80090C20) : "memory");
            goto select;
        finish67:
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 68;
            if (!rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80090C5C) : "memory");
            goto select;
        case 68:
            rawValue2 = (int)Anim11Player250View2;
            callback3 = Anim11Data7431CView1;
            record16 = Anim11Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(9);
            if (rawValue2)
                return;
            rawValue2 = Anim11Data6E53CView3 & 64;
            if (rawValue2) {
                rawValue2 = 1;
                nextSelector4 = (int)&Anim11Player4CView3;
                rawValue3 = *(int*)nextSelector4;
                MATCHING_KEEP(rawValue2);
                if (rawValue3 == rawValue2) {
                    rawValue2 = Anim11Player54View3 < 31;
                    nextSelector4 -= 76;
                    if (rawValue2) {
                        rawValue2 = Anim11Call1A358View1((void*)nextSelector4, 1024);
                        if (!rawValue2) {
                            nextSelector4 = 70;
                            goto select;
                        }
                    }
                }
                rawValue2 = 1;
                Anim11Player1B6View2 = rawValue2;
                Anim11Field(record16, int*, 0x48) = 0;
            }
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 16;
            if (rawValue2) {
                nextSelector4 = (int)&Anim11Player4CView3;
                rawValue2 = *(int*)nextSelector4;
                nextSelector4 -= 76;
                if (rawValue2) {
                    product5 = Anim11Player44View1;
                    rawValue2 = Anim11Call1A358View1((void*)nextSelector4, product5 + 512);
                    nextSelector4 = 75;
                    if (!rawValue2)
                        goto select;
                }
            }
            rawValue2 = Anim11PlayerB8View3;
            if (rawValue2)
                return;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue2 = Anim11Player1B6View2;
            if (rawValue2) {
                rawValue2 = Anim11Field(record16, int*, 0x48) < 7;
                if (rawValue2) {
                    rawValue2 = 2;
                    rawValue3 = Anim11Player50View1;
                    nextSelector4 = 67;
                    if (rawValue3 != rawValue2)
                        goto effectSelect;
                    nextSelector4 = 73;
                    goto effectSelect;
                }
            }
            rawValue3 = Anim11Player50View1;
            rawValue2 = 2;
            if (rawValue3 == rawValue2) {
                Anim11Field(record16, int*, 0x48) = 0;
            } else {
                rawValue2 = 255;
                Anim11Field(record16, int*, 0x48) = rawValue2;
            }
            rawValue2 = Anim11PlayerACView2;
            nextSelector4 = 66;
            if (rawValue2)
                goto effectSelect;
            nextSelector4 = 69;
            goto effectSelect;
        case 69:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 64;
            if (rawValue2) {
                rawValue2 = (int)Anim11Player250View2;
                rawValue2 = (int)Anim11Field((void*)rawValue2, void**, 0);
                rawValue2 = Anim11Field((void*)rawValue2, int*, 0x48);
                rawValue2 = rawValue2 < 8;
                nextSelector4 = 67;
                if (!rawValue2)
                    goto select;
                __asm__ volatile("" ::"i"(0x80090E54) : "memory");
                nextSelector4 = 73;
                goto select;
            }
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = Anim11PlayerB8View3 < 4;
            nextSelector4 = 68;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                goto query69;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (rawValue2)
                goto input69;
        query69:
            rawValue2 = Anim11Call55E84View1((void*)nextSelector4);
            rawValue2 = rawValue2 < 4;
            if (!rawValue2)
                return;
        input69:
            rawValue2 = Anim11Data6E535View2;
            if (!rawValue2)
                goto held69;
            rawValue2 = Anim11PlayerB0View2;
            nextSelector4 = 65;
            if (!rawValue2)
                goto select;
        held69:
            rawValue2 = Anim11Data6E538View3 & 12;
            nextSelector4 = 66;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11Player144View2 < 16;
            if (!rawValue2)
                goto select65;
            goto select;
        case 70:
        case 73:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 16;
            if (rawValue2) {
                product5 = Anim11Player44View1;
                nextSelector4 = (int)Anim11Player0View2;
                rawValue2 = Anim11Call1A358View1((void*)nextSelector4, product5 + 512);
                nextSelector4 = 75;
                if (!rawValue2)
                    goto select;
            }
            rawValue2 = Anim11PlayerB8View3;
            if (rawValue2)
                goto finish70;
            rawValue2 = Anim11Player54View3 < 16;
            if (rawValue2)
                goto finish70;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim11PlayerCCView1;
            rawValue2 = Anim11Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim11PlayerD0View2;
            rawValue2 = Anim11Player90View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim11PlayerD4View2;
            rawValue2 = Anim11Player94View2;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim11PlayerACView2;
            nextSelector4 = 66;
            if (!rawValue2)
                goto select65;
            __asm__ volatile("" ::"i"(0x80091058) : "memory");
            goto select;
        finish70:
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 68;
            if (!rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x80091094) : "memory");
            goto select;
        case 71:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue2 = 3;
            rawValue3 = Anim11Player50View1;
            if (rawValue3 != rawValue2)
                goto other71;
            rawValue2 = Anim11PlayerB8View3;
            if (rawValue2)
                goto finish71;
            rawValue2 = Anim11PlayerE4View2 < 23;
            nextSelector4 = 71;
            if (!rawValue2)
                return;
        effectSelect:
            Anim11Call4BEF8View3(nextSelector4);
            {
                register int (*spawn2)(int, int, void*, int) __asm__("$2") =
                    Anim11DataSpawnParticleView1;
                if (spawn2)
                    spawn2(8, 33, 0, 2);
            }
            rawValue2 = (int)Anim11Data6C654View2;
            product5 = 0;
            nextSelector4 = Anim11Field((void*)rawValue2, unsigned char*, 0x12);
            Anim11CallPlaySoundView2((unsigned char)nextSelector4, product5, 0);
            rawValue2 = Anim11Player58View1 < 24;
            if (rawValue2)
                return;
            rawValue2 = 120;
            Anim11Data6E530View1 = rawValue2;
            rawValue2 = 15;
            Anim11Data6E52CView1 = rawValue2;
            return;
        finish71:
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 68;
            if (!rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x800911A4) : "memory");
            goto select;
        other71:
            rawValue2 = Anim11PlayerB8View3 < 4;
            nextSelector4 = 71;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                goto query71;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                goto query71;
            rawValue2 = Anim11Data6E535View2;
            nextSelector4 = 65;
            if (rawValue2)
                goto select;
            nextSelector4 = 66;
            goto select;
        query71:
            rawValue2 = Anim11Call55E84View1((void*)nextSelector4);
            rawValue2 = rawValue2 < 16;
            if (rawValue2)
                return;
            rawValue2 = Anim11Data6E535View2;
            nextSelector4 = 66;
            if (rawValue2)
                return;
            goto select;
        case 72:
            rawValue2 = Anim11Player4CView3;
            if (!rawValue2)
                goto finish72;
            rawValue2 = Anim11Player280View2;
            if (rawValue2 < 0)
                goto finish72;
            rawValue2 = Anim11Player54View3 < 16;
            if (!rawValue2) {
                rawValue2 = Anim11Data6E53CView3 & 64;
                nextSelector4 = 70;
                if (rawValue2)
                    goto select;
            }
            rawValue3 = Anim11Data6E53CView3;
            rawValue2 = rawValue3 & 160;
            nextSelector4 = 71;
            if (rawValue2)
                goto select;
            rawValue2 = rawValue3 & 16;
            if (rawValue2) {
                product5 = Anim11Player44View1;
                nextSelector4 = (int)Anim11Player0View2;
                rawValue2 = Anim11Call1A358View1((void*)nextSelector4, product5 + 512);
                nextSelector4 = 75;
                if (!rawValue2)
                    goto select;
            }
            rawValue2 = Anim11PlayerB8View3;
            if (rawValue2)
                goto finish72;
            rawValue2 = Anim11Player54View3 < 16;
            if (rawValue2)
                goto finish72;
            rawValue2 = Anim11PlayerE4View2 < 23;
            if (!rawValue2)
                goto finish72;
            rawValue3 = Anim11PlayerCCView1;
            rawValue2 = Anim11Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim11PlayerD0View2;
            rawValue2 = Anim11Player90View1;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim11PlayerD4View2;
            rawValue2 = Anim11Player94View2;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                goto finish72;
            rawValue2 = Anim11PlayerACView2;
            nextSelector4 = 66;
            if (!rawValue2)
                goto select65;
            goto select;
        finish72:
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
            rawValue2 = Anim11Player280View2;
            if (rawValue2 < 0) {
                nextSelector4 = 74;
                goto select;
            }
            rawValue2 = 10;
            rawValue3 = Anim11Player144View2;
            nextSelector4 = 79;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim11PlayerB8View3;
            nextSelector4 = 68;
            if (!rawValue2)
                goto select65;
            goto select;
        case 74:
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
            goto call498C0;
        case 75:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue2 = 2;
            rawValue3 = Anim11Player4CView3;
            nextSelector4 = 77;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim11Player54View3 < 61;
            nextSelector4 = 68;
            if (!rawValue2)
                goto select;
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 76;
            if (!rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x800914F4) : "memory");
            goto select;
        case 76:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            rawValue2 = 2;
            rawValue3 = Anim11Player4CView3;
            nextSelector4 = 77;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim11Player54View3 < 61;
            nextSelector4 = 68;
            if (rawValue2)
                return;
            goto select;
        case 77:
            rawValue2 = Anim11Data7431CView1(9);
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim11Player250View2;
            rawValue2 = Anim11Player48View3;
            rawValue3 = Anim11Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 65;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim11Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2)
                return;
        select65:
            nextSelector4 = 65;
            goto select;
        default:
            return;
    }
select:
    Anim11Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim11Field
