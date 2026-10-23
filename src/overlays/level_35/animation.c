#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80088A0C.
 * Assembly SHA256 416927b947a4ff92d76d60c9ee5951cd45d778dc70d90cb7cce96403278fd228.
 * AI-generated; not human reviewed. All1592 original instructions,
 * 148 selectors bias25 and 0 owned padding words are required.
 * Original frame0x118; every concrete field width and producer is retained.
 * Seven groups reuse verified11/13/25/33/37 source with original stack maps.
 * Original165..168 and169..171 retain signed dynamic remainders, both original
 * divide checks, four separately wrapped products, original interpolation
 * arguments, vertical branches and the shared angular recurrence at8008A1A8.
 * Original165 retains the actual previous30-minus-updated30 delta in S5;
 * no zero value inferred by m2c is substituted. Each relative44/88/94 pointer
 * producer and every169 input branch remains original. Original172 reads the
 * two signed lookup tables and retains each source byte reload and stack store.
 * All bindings follow original register ownership; shared join values are
 * initialized on every incoming path. All metadata templates are empty.
 * Repeated identical declarations are removed; distinct typed aliases stay
 * distinct. Initialized empty constraints and original address metadata emit
 * zero CPU instructions; frozen C tools emit words. Units/fixed point,helper
 * contracts and caller rate remain unresolved; cadence is per invocation.
 * Falsification: every native/linked instruction,actual internal/conditional
 * target,selector/data and full EXE/every-overlay retail hashes. Binary identity
 * does not establish synchronized runtime or system completeness. */
#define Physics35Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Physics35UpdatePlayerGroundInputTargetsView1() __asm__("func_80040D10");
unsigned char Physics35ApproachPlayerTargetHeadingView1() __asm__("func_80041580");
unsigned char Physics35BlendPlayerHeadingFromInputVectorView1() __asm__("func_800416F4");
unsigned char Physics35ClearVectorView1() __asm__("func_8004F168");
extern void* Physics35Data6C570View1 __asm__("D_8006C570");
extern int Physics35Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics35Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics35Player0View1 __asm__("D_80070328");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics35BuildOrientedInputPairView1() __asm__("func_80040F48");
int Physics35ApplyPlayerRotationStepView1() __asm__("func_80041404");
int Physics35ApproachPlayerTargetHeadingView2() __asm__("func_80041580");
int Physics35ApproachPlayerTargetSpeedView1() __asm__("func_800417FC");
int Physics35BuildPlayerMovementVectorView1() __asm__("func_80041848");
int Physics35BuildPlayerResponseVectorView1() __asm__("func_80041B64");
int Physics35InterpolateSineView1() __asm__("func_8004E9E4");
int Physics35InterpolateCosineView1() __asm__("func_8004EA2C");
int Physics35MeasureVectorLengthView1() __asm__("func_8004EDE8");
int Physics35ClearVectorView2() __asm__("func_8004F168");
int Physics35CopyVectorView1() __asm__("func_8004F178");
int Physics35AddVectorView1() __asm__("func_8004F194");
int Physics35SubtractVectorView1() __asm__("func_8004F1C8");
extern unsigned char Physics35Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics35Data65920View1 __asm__("D_80065920");
extern int Physics35Data6763CView1 __asm__("D_8006763C");
extern int Physics35Data67640View1 __asm__("D_80067640");
extern int Physics35Data67644View1 __asm__("D_80067644");
extern int Physics35Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics35Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics35PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics35Player94View1 __asm__("D_80070328+0x94");
extern int Physics35PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics35Player80View1 __asm__("D_80070328+0x80");
extern int Physics35PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics35Player64View1 __asm__("D_80070328+0x64");
extern int Physics35Player88View1 __asm__("D_80070328+0x88");
extern int Physics35Player84View1 __asm__("D_80070328+0x84");
extern int Physics35Player144View1 __asm__("D_80070328+0x144");
extern int Physics35Player60View1 __asm__("D_80070328+0x60");
extern int Physics35PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics35Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics35Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics35PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics35PlayerA0View1 __asm__("D_80070328+0xA0");
extern int Physics35PlayerA4View1 __asm__("D_80070328+0xA4");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
int Physics35TestSubdividedSegmentPathView1() __asm__("func_80013E38");
int Physics35UpdateSmoothedInputPairView1() __asm__("func_800410F8");
int Physics35BuildPlayerMovementVectorView2() __asm__("func_80041848");
int Physics35BuildPlayerResponseVectorView2() __asm__("func_80041B64");
int Physics35EvaluateClampedPlayerRootCurveView1() __asm__("func_8004E4E4");
int Physics35InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics35AddVectorView2() __asm__("func_8004F194");
extern int Physics35Data67630View1 __asm__("D_80067630");
extern int Physics35Data67634View1 __asm__("D_80067634");
extern int Physics35Data67638View1 __asm__("D_80067638");
extern int Physics35Data6FA38View1 __asm__("D_8006FA38");
extern int Physics35Data71908View1 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics35Player130View1 __asm__("D_80070328+0x130");
extern int Physics35Player144View2 __asm__("D_80070328+0x144");
extern short Physics35Player148View1 __asm__("D_80070328+0x148");
extern short Physics35Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics35Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics35Player150View1 __asm__("D_80070328+0x150");
extern int Physics35Player154View1 __asm__("D_80070328+0x154");
extern int Physics35Player160View1 __asm__("D_80070328+0x160");
extern int Physics35Player48View1 __asm__("D_80070328+0x48");
extern int Physics35Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics35Player5CView2 __asm__("D_80070328+0x5C");
extern int Physics35Player60View2 __asm__("D_80070328+0x60");
extern int Physics35Player64View2 __asm__("D_80070328+0x64");
extern int Physics35Player8View1 __asm__("D_80070328+0x8");
extern int Physics35Player88View2 __asm__("D_80070328+0x88");
extern int Physics35Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics35Player90View1 __asm__("D_80070328+0x90");
extern int Physics35Player94View2 __asm__("D_80070328+0x94");
extern int Physics35PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics35PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics35PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics35PlayerF8View1 __asm__("D_80070328+0xF8");
int Physics35UpdatePlayerGroundInputTargetsView2() __asm__("func_80040D10");
int Physics35ApproachPlayerTargetHeadingView3() __asm__("func_80041580");
int Physics35ApproachPlayerTargetSpeedView2() __asm__("func_800417FC");
int Physics35BuildPlayerMovementVectorView3() __asm__("func_80041848");
int Physics35BuildPlayerResponseVectorView3() __asm__("func_80041B64");
int Physics35TransformVectorByBasisView1() __asm__("func_8004ED6C");
int Physics35ShiftVectorRightTowardZeroView1() __asm__("func_8004F110");
int Physics35ClearVectorView3() __asm__("func_8004F168");
int Physics35CopyVectorView2() __asm__("func_8004F178");
int Physics35AddVectorView3() __asm__("func_8004F194");
int Physics35CallRandView1() __asm__("rand");
extern int Physics35Data6C640View1 __asm__("D_8006C640");
extern int Physics35Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics35Player0View3 __asm__("D_80070328");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics35Player8CView2 __asm__("D_80070328+0x8C");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
int Physics35PlanarHeadingLookupView1() __asm__("func_8004E880");
extern int Physics35Player148View2 __asm__("D_80070328+0x148");
extern void* Physics35Player250View1 __asm__("D_80070328+0x250");
extern int Physics35Player44View1 __asm__("D_80070328+0x44");
extern int Physics35Data6C550View1 __asm__("D_8006C550");
int Physics35NormalizeVectorToLengthView1() __asm__("func_8004EF04");
void func_level_35_80088A0C(int slotIndex) {
    register int angle16 __asm__("$16");
    register void* frame16 __asm__("$16");
    register int length17 __asm__("$17");
    register void* heading17 __asm__("$17");
    register void* vector18 __asm__("$18");
    register void* context19 __asm__("$19");
    register void* vector20 __asm__("$20");
    register int next20 __asm__("$20");
    register int delta21 __asm__("$21");
    register void* base21 __asm__("$21");
    register void* base22 __asm__("$22");
    register int numeric4 __asm__("$4");
    register int numeric6 __asm__("$6");
    register int numeric7 __asm__("$7");
    int product35_0, product35_1, product35_2, product35_3;
    register int blend35 __asm__("$8");
    register int stateSelector4 __asm__("$4");
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
            spF0, spF4;
    } originalFrame;
    register void* globalVector80 __asm__("$16");
    register int workWord3 __asm__("$3");
    register void* globalField4CPointer __asm__("$16");
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
    globalPointer = &Physics35Data6E548View1;
    stateSelector4 = Physics35Field(&Physics35Player0View1, int*, 0x48);
    __asm__("" : "=r"(globalPointer) : "0"(globalPointer), "r"(stateSelector4), "r"(workWord2));
    workWord2 += (int)globalPointer;
    Physics35Data6C570View1 = (void*)workWord2;
    switch (stateSelector4) {
        default:
            return;
        case 53:
        case 54:
            globalVector80 = &Physics35Player0View1 + 0x80;
            Physics35ClearVectorView1(globalVector80);
            Physics35ClearVectorView1(globalVector80 + 0xC);
            if (Physics35Data6E044View1 != 7) {
                Physics35UpdatePlayerGroundInputTargetsView1(0x1200);
                Physics35BlendPlayerHeadingFromInputVectorView1();
                Physics35ApproachPlayerTargetHeadingView1(0x5A, 0x10);
                return;
            }
            return;
        case 25:
            Physics35BuildOrientedInputPairView1(&originalFrame.sp10, 1);
            workWord2 = originalFrame.sp10;
            call4 = &Physics35PlayerA8View1;
            workWord2 >>= 1;
            Physics35Field(call4, int*, 0) = workWord2;
            workWord2 = workWord2 < -25;
            if (workWord2) {
                workWord2 = -25;
                Physics35Field(call4, int*, 0) = workWord2;
            }
            workWord2 = Physics35Field(call4, int*, 0);
            workWord2 = workWord2 < 26;
            if (!workWord2) {
                workWord2 = 25;
                Physics35Field(call4, int*, 0) = workWord2;
            }
            call4 = (void*)Physics35Field(call4, int*, 0);
            Physics35ApplyPlayerRotationStepView1(call4);
            Physics35ApproachPlayerTargetSpeedView1(576, 384);
            workWord2 = Physics35InterpolateCosineView1(Physics35Player64View1);
            workWord3 = Physics35PlayerB0View1;
            lowProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics35Player64View1;
            workWord2 = lowProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            Physics35Player80View1 = workWord2;
            workWord2 = Physics35InterpolateSineView1(call4);
            workWord3 = Physics35PlayerB0View1;
            lowProduct1 = workWord3 * workWord2;
            workWord2 = Physics35Player94View1;
            Physics35Player88View1 = workWord2;
            workWord2 = lowProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            Physics35Player84View1 = workWord2;
            Physics35BuildPlayerResponseVectorView1();
            workWord2 = Physics35Player144View1;
            workWord2 += 12;
            Physics35Player144View1 = workWord2;
            workWord2 = workWord2 < 193;
            if (!workWord2) {
                workWord2 = 192;
                Physics35Player144View1 = workWord2;
            }
            workWord2 = Physics35Player94View1;
            workWord3 = Physics35Player144View1;
            workWord2 -= workWord3;
            Physics35Player94View1 = workWord2;
            workWord2 = workWord2 < -8960;
        clamp19:
            __asm__ volatile("" ::"i"(0x80088BF8) : "memory");
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics35Player94View1 = workWord2;
            return;
        case 30:
            globalVector80 = &Physics35Player80View1;
            MATCHING_KEEP_VOLATILE_CLOBBER(globalVector80, "memory");
            goto block_154;
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
            call4 = &originalFrame.sp18;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            pointer17 = &Physics35Player154View1;
            Physics35UpdateSmoothedInputPairView1(call4, pointer17, 0);
            workWord2 = originalFrame.sp1C;
            numeric4 = Physics35Player94View2;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp18;
            numeric4 -= 1024;
            originalFrame.sp28 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                pointer16 = &originalFrame.sp20;
                call4 = pointer16;
                call5 = pointer16;
                __asm__ volatile(""
                                 : "=r"(pointer17)
                                 : "0"(pointer17), "r"(call4), "r"(call5)
                                 : "memory");
                pointer17 -= 340;
                call6 = pointer17;
                workWord2 = Physics35Player8CView1;
                workWord3 = Physics35Player90View1;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp20 = workWord2;
                originalFrame.sp24 = workWord3;
                Physics35AddVectorView2(call4, call5, call6);
                if (!Physics35TestSubdividedSegmentPathView1(pointer17, pointer16, 2)) {
                    workWord2 = Physics35Player8View1;
                    workWord3 = Physics35Data71908View1;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp1C = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp1C = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp1C;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics35PlayerF8View1;
            workWord3 = Physics35Player8View1;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics35Player60View2;
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
            call4 = &Physics35Player64View2;
            workWord2 = Physics35Field(call4, int*, 0);
            workWord3 = Physics35Player60View2;
            Physics35PlayerA8View2 = delta19;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics35Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics35Player60View2 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics35Player60View2 = workWord2;
            }
            workWord2 = Physics35Player60View2;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics35Player60View2 = -800;
            workWord2 = Physics35Player60View2;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics35Player60View2 = 800;
            workWord2 = Physics35Data6FA38View1;
            if (workWord2 >= 0)
                goto nonnegative33;
            workWord3 = Physics35Player60View2;
            if (workWord3 >= 0)
                goto positive33;
            numeric4 = Physics35Data67634View1;
            workWord2 = Physics35Data67630View1;
            workWord2 = numeric4 - workWord2;
            goto quotient33;
        positive33:
            if (workWord3 <= 0)
                goto zero33;
            workWord2 = Physics35Data67638View1;
            numeric4 = Physics35Data67634View1;
            workWord2 -= numeric4;
        quotient33:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics35PlayerACView2 = numeric4;
            goto modifier33;
        zero33:
            workWord2 = Physics35Data67634View1;
            Physics35PlayerACView2 = workWord2;
        modifier33:
        speed33:
            call5 = &Physics35Player144View2;
            workWord2 = Physics35PlayerACView2;
            numeric4 = Physics35PlayerB0View2;
            workWord3 = Physics35Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics35Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics35PlayerB0View2 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics35PlayerB0View2 = 2048;
            workWord2 = Physics35PlayerB0View2;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics35PlayerB0View2 = 19200;
            goto rotation33;
        nonnegative33:
            numeric4 = Physics35Player8View1;
            limit16 = 0;
            workWord2 = Physics35EvaluateClampedPlayerRootCurveView1(numeric4);
            workWord3 = Physics35Player148View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            numeric4 = workWord2;
            MATCHING_KEEP(numeric4);
            Physics35PlayerACView2 = numeric4;
            numeric5 = workWord3;
            if (!workWord3)
                goto zeroCounter33;
            workWord2 = 0x60000;
            Physics35Player130View1 = workWord2;
            workWord2 = numeric5 - 1;
            Physics35Player148View1 = workWord2;
            workWord2 <<= 16;
            if (workWord2 > 0)
                goto positiveCounter33;
            workWord3 = Physics35PlayerB0View2;
            workWord2 = workWord3 - numeric4;
            workWord2 = workWord2 < 192;
            if (workWord2) {
                workWord2 = numeric4 + 8192;
                Physics35PlayerB0View2 = workWord2;
                Physics35Player148View1 = 0;
                goto counterClamp33;
            }
            workWord2 = workWord3 - 192;
            Physics35PlayerB0View2 = workWord2;
            workWord2 = 1;
            Physics35Player148View1 = workWord2;
            goto counterClamp33;
        positiveCounter33:
            workWord2 = numeric4 + 8192;
            Physics35PlayerB0View2 = workWord2;
            limit16 = 96;
            goto counterClamp33;
        zeroCounter33:
            Physics35PlayerB0View2 = numeric4;
            __asm__ volatile("" : "=r"(limit16) : "0"(limit16) : "$3", "memory");
            Physics35Player130View1 = 0;
        counterClamp33:
            globalPointer = &Physics35PlayerB0View2;
            workWord2 = Physics35Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 22785;
            if (!workWord2)
                Physics35Field(globalPointer, int*, 0) = 22784;
            workWord2 = Physics35Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 2048;
            if (workWord2)
                Physics35Field(globalPointer, int*, 0) = 2048;
            numeric5 = Physics35Player14CView1;
            workWord3 = Physics35Player150View1;
            workWord2 = limit16 - numeric5;
            workWord2 <<= 4;
            numeric4 = workWord3 << 5;
            workWord2 -= numeric4;
            workWord2 >>= 6;
            workWord3 += workWord2;
            Physics35Player150View1 = workWord3;
            workWord3 >>= 4;
            numeric5 += workWord3;
            Physics35Player14CView1 = numeric5;
            if (numeric5 < 0)
                Physics35Player14CView1 = 0;
            workWord2 = Physics35Player14CView1;
            workWord2 = workWord2 < 97;
            if (!workWord2)
                Physics35Player14CView1 = 96;
        rotation33:
            workWord2 = Physics35Player148View1;
            workWord2 = workWord2 < 2;
            if (workWord2)
                goto spring33;
            workWord3 = Physics35Player14AView1;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 * 3;
            MATCHING_KEEP(workWord2);
            workWord3 = Physics35Player5CView2;
            workWord2 <<= 11;
            Physics35Player154View1 = workWord2;
            workWord2 >>= 6;
            workWord3 += workWord2;
            workWord3 &= 4095;
            workWord2 = workWord3 < 2049;
            Physics35Player5CView2 = workWord3;
            if (workWord2)
                goto rotationDone33;
            workWord2 = workWord3 - 4096;
            goto storeAngle33;
        spring33:
            workWord2 = Physics35InterpolateCosineView2(Physics35Player60View2);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            originalLow = delta19 * workWord2;
            workWord3 = Physics35Player154View1;
            numeric5 = Physics35Player5CView2;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = originalLow >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics35Player154View1 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics35Player5CView2 = numeric5;
            if (workWord2)
                goto rotationDone33;
            workWord2 = numeric5 - 4096;
        storeAngle33:
            Physics35Player5CView2 = workWord2;
        rotationDone33:
            Physics35BuildPlayerMovementVectorView2();
            call5 = &Physics35Player4CView2;
            numeric4 = Physics35Field(call5, int*, 0);
            if (numeric4)
                goto active33;
            workWord2 = (int)Physics35Data6C570View1;
            workWord2 = Physics35Field((void*)workWord2, int*, 4) & 64;
            if (!workWord2)
                goto end33;
            workWord2 = Physics35PlayerF8View1;
            workWord3 = Physics35Player8View1;
            workWord2 -= 512;
            workWord3 = workWord3 < workWord2;
            if (!workWord3)
                goto end33;
            workWord3 = Physics35Player48View1;
            workWord2 = 33;
            if (workWord3 != workWord2)
                goto end33;
            workWord2 = 1;
            Physics35Field(call5, int*, 0) = workWord2;
            __asm__ volatile("" ::: "$4", "memory");
            Physics35Player160View1 = 0;
            goto end33;
        active33:
            workWord2 = Physics35Player8View1;
            workWord3 = Physics35PlayerF8View1;
            workWord2 = workWord2 < workWord3;
            if (workWord2) {
                workWord2 = 1;
                goto activeRemainder33;
            }
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics35Field(call5, int*, 0) = 0;
            goto end33;
        activeRemainder33:
            if (numeric4 != workWord2)
                goto decline33;
            workWord2 = Physics35Player160View1;
            workWord2 += 512;
            Physics35Player160View1 = workWord2;
            workWord2 = workWord2 < 6144;
            if (!workWord2) {
                workWord2 = 6144;
                Physics35Player160View1 = workWord2;
                workWord2 = 2;
                Physics35Field(call5, int*, 0) = workWord2;
            }
            goto add88;
        decline33:
            workWord2 = Physics35Player160View1;
            workWord2 -= 256;
            Physics35Player160View1 = workWord2;
            if (workWord2 <= 0) {
                Physics35Player160View1 = 0;
                Physics35Field(call5, int*, 0) = 0;
            }
        add88:
            {
                register void* pointer2 __asm__("$2");
                pointer2 = &Physics35Player88View2;
                workWord3 = Physics35Field(pointer2, int*, 0);
                numeric4 = Physics35Player160View1;
                workWord3 += numeric4;
                Physics35Field(pointer2, int*, 0) = workWord3;
            }
        end33:
            Physics35BuildPlayerResponseVectorView2();
            return;
        }
        case 43:
        case 44:
            globalField4CPointer = &Physics35Player4CView1;
            MATCHING_KEEP(globalField4CPointer);
            workWord3 = Physics35Field(globalField4CPointer, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto continue43;
        block_154:
            call4 = &Physics35Player80View1;
            MATCHING_KEEP(call4);
            Physics35ClearVectorView3(call4);
            call4 = &Physics35Player8CView2;
            MATCHING_KEEP(call4);
            Physics35ClearVectorView3(call4);
            return;
        continue43:
            workWord2 = 7;
            workWord3 = Physics35Data6E044View2;
            if (workWord3 == workWord2) {
                Physics35Field(&Physics35Player0View3, int*, 0xB0) = 0;
            } else {
                Physics35UpdatePlayerGroundInputTargetsView2(0x980);
                raw21_var_v0_2 = Physics35ApproachPlayerTargetHeadingView3(0x5A, 0x10);
                if (raw21_var_v0_2 < 0) {
                    raw21_var_v0_2 = -raw21_var_v0_2;
                }
                if (raw21_var_v0_2 >= 0x201) {
                    Physics35Field(&Physics35Player0View3, int*, 0xAC) = 0;
                }
                raw21_var_a0_2 = 0xC0;
                if (Physics35Field(&Physics35Player0View3, int*, 0xB0) >= 0xC81) {
                    raw21_var_a0_2 = 0;
                    raw21_var_a1_4 = 0xC0;
                } else {
                    raw21_var_a1_4 = 0x40;
                }
                Physics35ApproachPlayerTargetSpeedView2(raw21_var_a0_2, raw21_var_a1_4);
            }
            raw21_temp_s0_11 = &Physics35Player0View3 + 0xB0;
            if (Physics35Field(&Physics35Player0View3, int*, 0xB0) != 0) {
                Physics35BuildPlayerMovementVectorView3();
                Physics35BuildPlayerResponseVectorView3();
                Physics35Field(&Physics35Player0View3, int*, 0x94) = 0;
            } else {
                Physics35ClearVectorView3(raw21_temp_s0_11 - 0x30);
                Physics35ClearVectorView3(raw21_temp_s0_11 - 0x24);
            }
            if (Physics21_SpawnParticle != 0) {
                raw21_temp_s4 = &Physics35Player0View3 + 0x28;
                if (Physics35Field(&Physics35Player0View3, int*, 0x28) < 0) {
                    if ((Physics35Field(&Physics35Player0View3, int*, 0xB0) >= 0x401) &&
                        (savedSlotIndex < 2) && (Physics35Data6C640View1 & 1)) {
                        Physics35CopyVectorView2(&originalFrame.sp30, raw21_temp_s4 - 0x28);
                        originalFrame.sp44 = 0x40;
                        originalFrame.sp48 = 0;
                        originalFrame.sp40 =
                            (int)Physics35Field(&Physics35Player0View3, int*, 0xB0) >> 5;
                        if (savedSlotIndex != 0) {
                            originalFrame.sp44 = -0x40;
                        }
                        raw21_temp_s2_3 = raw21_temp_s4 + 8;
                        Physics35TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp40,
                                                             &originalFrame.sp50);
                        Physics35AddVectorView3(&originalFrame.sp30, &originalFrame.sp30,
                                                &originalFrame.sp50);
                        originalFrame.sp40 = 0;
                        originalFrame.sp38 = -Physics35Field(&Physics35Player0View3, int*, 0x28);
                        Physics35TransformVectorByBasisView1(raw21_temp_s2_3, &originalFrame.sp40,
                                                             &originalFrame.sp40);
                        Physics35ShiftVectorRightTowardZeroView1(&originalFrame.sp40, 3);
                        Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp30, &originalFrame.sp40);
                        if (!(Physics35CallRandView1() & 0x1F)) {
                            Physics21_SpawnParticle(1, 0x29, &originalFrame.sp30, 0);
                        }
                    } else {
                        raw21_temp_s1_7 = &Physics35Player0View3 + 0xB0;
                        if ((Physics35Field(&Physics35Player0View3, int*, 0xB0) < 0x201) &&
                            (savedSlotIndex == 0) && !(Physics35Data6C640View1 & 7) &&
                            !(Physics35CallRandView1() & 3)) {
                            originalFrame.sp60 = 0x80;
                            MATCHING_KEEP(savedSlotIndex);
                            originalFrame.sp64 = 0;
                            originalFrame.sp68 = 0;
                            Physics35TransformVectorByBasisView1(
                                raw21_temp_s1_7 - 0x80, &originalFrame.sp60, &originalFrame.sp60);
                            Physics35AddVectorView3(&originalFrame.sp60, &originalFrame.sp60,
                                                    raw21_temp_s1_7 - 0xB0);
                            originalFrame.sp68 =
                                -Physics35Field(&Physics35Player0View3, int*, 0x28);
                            Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp60, (int*)1);
                        }
                    }
                }
            }
            raw21_temp_a1_4 =
                Physics35Field(&Physics35Player0View3, int*, 0x144) -
                ((int)((Physics35Field(&Physics35Player0View3, int*, 0x148) * 2) +
                       (Physics35Field(&Physics35Player0View3, int*, 0x144) * 0x14)) >>
                 8);
            raw21_temp_a0_7 = Physics35Field(&Physics35Player0View3, int*, 0x148) + raw21_temp_a1_4;
            Physics35Field(&Physics35Player0View3, int*, 0x144) = raw21_temp_a1_4;
            Physics35Field(&Physics35Player0View3, int*, 0x148) = raw21_temp_a0_7;
            if (raw21_temp_a0_7 >= 0x5901) {
                Physics35Field(&Physics35Player0View3, int*, 0x148) = 0x5900;
            }
            if (Physics35Field(&Physics35Player0View3, int*, 0x148) < -0x5900) {
                Physics35Field(&Physics35Player0View3, int*, 0x148) = -0x5900;
                return;
            }
            break;
        case 55: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            globalVector80 = &Physics35Player80View1;
            Physics35ClearVectorView2(globalVector80);
            Physics35ClearVectorView2(globalVector80 + 12);
            numeric5 = Physics35Player148View2;
            numeric4 = Physics35Player144View1;
            workWord3 = numeric5 << 1;
            workWord2 = numeric4 * 5;
            workWord2 <<= 2;
            workWord3 += workWord2;
            workWord3 >>= 8;
            numeric4 -= workWord3;
            numeric5 += numeric4;
            Physics35Player144View1 = numeric4;
            Physics35Player148View2 = numeric5;
            return;
        }
        case 61:
            Physics35BuildOrientedInputPairView1(&originalFrame.sp50, 1);
            workWord3 = originalFrame.sp50;
            workWord2 = workWord3 * 25;
            call4 = (void*)(workWord2 >> 7);
            if (call4)
                goto nonzero61;
            MATCHING_BARRIER_VOLATILE("$4");
            Physics35PlayerA8View1 = 0;
            goto approach61;
        nonzero61:
            if ((int)call4 >= 0)
                goto positive61;
            globalPointer = &Physics35PlayerA8View1;
            workWord2 = Physics35Field(globalPointer, int*, 0);
            if (workWord2 > 0)
                Physics35Field(globalPointer, int*, 0) = 0;
            goto approach61;
        positive61:
            globalPointer = &Physics35PlayerA8View1;
            workWord2 = Physics35Field(globalPointer, int*, 0);
            if (workWord2 < 0)
                Physics35Field(globalPointer, int*, 0) = 0;
        approach61:
            call5 = &Physics35PlayerA8View1;
            workWord3 = Physics35Field(call5, int*, 0);
            workWord2 = workWord3 < (int)call4;
            if (workWord2) {
                workWord2 = workWord3 + 3;
                Physics35Field(call5, int*, 0) = workWord2;
                workWord2 = (int)call4 < workWord2;
                goto clamp61;
            }
            workWord2 = workWord3 - 3;
            Physics35Field(call5, int*, 0) = workWord2;
            workWord2 = workWord2 < (int)call4;
        clamp61:
            if (workWord2)
                Physics35Field(call5, int*, 0) = (int)call4;
            call4 = (void*)Physics35PlayerA8View1;
            Physics35ApplyPlayerRotationStepView1(call4);
            workWord3 = Physics35Player60View1;
            workWord2 = workWord3 < 2049;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                Physics35Player60View1 = workWord2;
                MATCHING_BARRIER_VOLATILE("memory");
                workWord3 = Physics35Player60View1;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            if (workWord3 >= 0)
                goto nonnegative61;
            call4 = (void*)Physics35Data67640View1;
            workWord2 = Physics35Data6763CView1;
            workWord2 = (int)call4 - workWord2;
            goto quotient61;
        nonnegative61:
            if (workWord3 <= 0)
                goto zero61;
            workWord2 = Physics35Data67644View1;
            call4 = (void*)Physics35Data67640View1;
            workWord2 -= (int)call4;
        quotient61:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 352;
            call4 += workWord3;
            Physics35PlayerACView1 = (int)call4;
            goto update61;
        zero61:
            workWord2 = Physics35Data67640View1;
            Physics35PlayerACView1 = workWord2;
        update61:
            Physics35ApproachPlayerTargetSpeedView1(576, 384);
            Physics35BuildPlayerMovementVectorView1();
            call6 = &Physics35PlayerFCView1;
            workWord2 = Physics35Field(call6, unsigned char*, 0);
            if (workWord2)
                goto field94FromA0;
            workWord2 = Physics35PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vectorCommit61;
        field94FromA0:
            workWord2 = Physics35PlayerA0View1;
            workWord2 -= 192;
            Physics35Player94View1 = workWord2;
            return;
        vectorCommit61:
            call5 = call6 - 124;
            Physics35AddVectorView1(call4, call5, call6 - 20);
            return;
        case 165:
        case 166:
        case 167:
        case 168:
            call4 = &originalFrame.spA0;
            workWord2 = (int)Physics35Player250View1;
            context19 = Physics35Field((void*)workWord2, void**, 0);
            Physics35BuildOrientedInputPairView1(call4, 0);
            workWord2 = Physics35Player64View1;
            angle16 = workWord2 + 1024;
            workWord2 = originalFrame.spA0;
            delta21 = Physics35Field(context19, int*, 48);
            workWord2 >>= 4;
            workWord3 = delta21 + workWord2;
            workWord2 = workWord3 < 128;
            Physics35Field(context19, int*, 48) = workWord3;
            if (!workWord2) {
                workWord2 = 127;
                goto clamp165;
            }
            workWord2 = workWord3 < -127;
            MATCHING_KEEP(workWord2);
            if (!workWord2)
                goto clamped165;
            workWord2 = -127;
        clamp165:
            Physics35Field(context19, int*, 48) = workWord2;
        clamped165:
            workWord2 = Physics35Field(context19, int*, 48);
            delta21 -= workWord2;
            workWord2 = Physics35InterpolateCosineView1(angle16);
            workWord3 = Physics35Field(context19, int*, 48);
            product35_0 = workWord3 * workWord2;
            call4 = (void*)angle16;
            workWord2 = product35_0 >> 8;
            originalFrame.sp90 = workWord2;
            workWord2 = Physics35InterpolateSineView1(call4);
            workWord3 = Physics35Field(context19, int*, 48);
            product35_1 = workWord3 * workWord2;
            vector18 = &originalFrame.sp70;
            call4 = vector18;
            base22 = &Physics35Player0View2;
            originalFrame.sp98 = 0;
            workWord2 = product35_1 >> 8;
            originalFrame.sp94 = workWord2;
            workWord2 = (int)Physics35Field(context19, void**, 36);
            call6 = base22;
            call5 = (void*)(int)Physics35Field((void*)workWord2, short*, 2);
            workWord2 = Physics35Field((void*)workWord2, int*, 12);
            call5 = (void*)((int)call5 << 4);
            call5 = workWord2 + (int)call5;
            Physics35SubtractVectorView1(call4, call5, call6);
            call4 = vector18;
            call5 = vector18;
            MATCHING_KEEP2(call4, call5);
            vector20 = &originalFrame.sp90;
            Physics35AddVectorView1(call4, call5, vector20);
            length17 = Physics35MeasureVectorLengthView1(vector18, 0);
            workWord2 =
                Physics35PlanarHeadingLookupView1(originalFrame.sp70, originalFrame.sp74, 1);
            workWord3 = Physics35Player64View1;
            workWord2 -= workWord3;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            if (!workWord2)
                angle16 -= 4096;
            workWord2 = length17 < 512;
            if (workWord2)
                goto advance165;
            workWord2 = angle16;
            if (angle16 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 801;
            if (workWord2)
                goto ready165;
        advance165:
            call5 = Physics35Field(context19, void**, 36);
            workWord3 = Physics35Field(call5, short*, 0);
            workWord2 = Physics35Field(call5, short*, 2);
            numeric4 = workWord3 + 1;
            workWord2 += numeric4;
            workWord3 = workWord2 % workWord3;
            call6 = base22;
            Physics35Field(call5, short*, 2) = workWord3;
            workWord2 = (int)Physics35Field(context19, void**, 36);
            call4 = vector18;
            call5 = (void*)(int)Physics35Field((void*)workWord2, short*, 2);
            workWord2 = Physics35Field((void*)workWord2, int*, 12);
            call5 = (void*)((int)call5 << 4);
            call5 = workWord2 + (int)call5;
            Physics35SubtractVectorView1(call4, call5, call6);
            Physics35AddVectorView1(vector18, vector18, vector20);
            length17 = Physics35MeasureVectorLengthView1(vector18, 0);
        ready165:
            vector18 = &Physics35Player44View1;
            MATCHING_KEEP(vector18);
            workWord2 = originalFrame.sp78;
            workWord3 = Physics35Field(vector18, int*, 0);
            workWord2 += workWord3;
            originalFrame.sp78 = workWord2;
            call5 = Physics35Field(context19, void**, 36);
            workWord3 = Physics35Field(call5, short*, 0);
            workWord2 = Physics35Field(call5, short*, 2);
            numeric4 = workWord3 + 1;
            workWord2 += numeric4;
            next20 = workWord2 % workWord3;
            frame16 = &originalFrame.sp80;
            call6 = vector18 - 68;
            __asm__("" : "=r"(call6) : "0"(call6), "r"(length17));
            length17 -= 512;
            call4 = frame16;
            workWord2 = Physics35Field(call5, int*, 12);
            call5 = (void*)(next20 << 4);
            call5 = workWord2 + (int)call5;
            Physics35SubtractVectorView1(call4, call5, call6);
            Physics35AddVectorView1(frame16, frame16, &originalFrame.sp90);
            call4 = frame16;
            workWord2 = originalFrame.sp88;
            workWord3 = Physics35Field(vector18, int*, 0);
            call5 = 0;
            workWord2 += workWord3;
            originalFrame.sp88 = workWord2;
            Physics35MeasureVectorLengthView1(call4, call5);
            workWord2 = length17 < 4097;
            if (!workWord2)
                length17 = 4096;
            workWord2 = originalFrame.sp70;
            blend35 = length17 * workWord2;
            workWord3 = 4096;
            workWord2 = originalFrame.sp80;
            workWord3 -= length17;
            numeric6 = workWord3 * workWord2;
            workWord2 = originalFrame.sp74;
            numeric7 = length17 * workWord2;
            workWord2 = originalFrame.sp84;
            workWord3 = workWord3 * workWord2;
            frame16 = &originalFrame.sp70;
            call4 = frame16;
            call5 = (void*)6144;
            originalFrame.sp78 = 0;
            workWord2 = blend35 + numeric6;
            workWord2 >>= 12;
            originalFrame.sp70 = workWord2;
            workWord2 = numeric7 + workWord3;
            workWord2 >>= 12;
            originalFrame.sp74 = workWord2;
            Physics35NormalizeVectorToLengthView1(call4, call5, numeric6, numeric7);
            Physics35CopyVectorView1(vector18 + 72, frame16);
            workWord2 = Physics35PlayerB8View1;
            if (workWord2) {
                workWord2 = Physics35Field(vector18, int*, 68);
                workWord2 -= 96;
                Physics35Field(vector18, int*, 68) = workWord2;
                Physics35Field(vector18, int*, 80) = workWord2;
            } else {
                workWord2 = -96;
                Physics35Player94View1 = workWord2;
                Physics35Player88View1 = workWord2;
            }
            call4 = &originalFrame.sp70;
            MATCHING_KEEP2_VOLATILE_CLOBBER(call4, next20, "memory");
            workWord2 = (int)Physics35Field(context19, void**, 36);
            call5 = (void*)(next20 << 4);
            workWord3 = Physics35Field((void*)workWord2, int*, 12);
            call6 = (void*)(int)Physics35Field((void*)workWord2, short*, 2);
            call5 = workWord3 + (int)call5;
            call6 = (void*)((int)call6 << 4);
            call6 = workWord3 + (int)call6;
            Physics35SubtractVectorView1(call4, call5, call6);
            workWord2 =
                Physics35PlanarHeadingLookupView1(originalFrame.sp70, originalFrame.sp74, 1);
            heading17 = &Physics35PlayerA4View1;
            workWord3 = Physics35Field(heading17, int*, 0);
            workWord2 -= workWord3;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            call4 = (void*)90;
            if (!workWord2)
                angle16 -= 4096;
            call5 = (void*)8;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            workWord2 = angle16 >> 3;
            Physics35PlayerA8View1 = workWord2;
            workWord2 = workWord3 + workWord2;
            Physics35Field(heading17, int*, 0) = workWord2;
            Physics35ApproachPlayerTargetHeadingView2(call4, call5);
            workWord2 = Physics35PlayerB8View1;
            angle16 = 0;
            if (workWord2)
                goto pitch165;
            MATCHING_KEEP_VOLATILE_CLOBBER(angle16, "$2");
            workWord2 = Physics35MeasureVectorLengthView1(heading17 - 24, 0);
            angle16 = Physics35PlanarHeadingLookupView1(workWord2, Physics35PlayerA0View1, 1);
        pitch165:
            call5 = &Physics35Player60View1;
            numeric4 = Physics35Field(call5, int*, 0);
            workWord2 = angle16 - numeric4;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            if (!workWord2)
                angle16 -= 4096;
            angle16 >>= 3;
            workWord3 = Physics35PlayerA8View1;
            workWord2 = numeric4 + angle16;
            Physics35Field(call5, int*, 0) = workWord2;
            workWord2 = Physics35Player5CView1;
            angle16 = workWord3 << 5;
            workWord3 = delta21 << 6;
            angle16 = workWord3 - angle16;
            goto windJoin169;
        case 169:
        case 170:
        case 171:
            call4 = &originalFrame.spD8;
            workWord2 = (int)Physics35Player250View1;
            context19 = Physics35Field((void*)workWord2, void**, 0);
            Physics35BuildOrientedInputPairView1(call4, 0);
            workWord2 = Physics35Player64View1;
            angle16 = workWord2 + 1024;
            workWord2 = originalFrame.spD8;
            workWord3 = Physics35Field(context19, int*, 48);
            workWord2 >>= 4;
            workWord3 = workWord3 + workWord2;
            workWord2 = workWord3 < 128;
            Physics35Field(context19, int*, 48) = workWord3;
            if (!workWord2) {
                workWord2 = 127;
                goto clamp169;
            }
            workWord2 = workWord3 < -127;
            MATCHING_KEEP(workWord2);
            if (!workWord2)
                goto clamped169;
            workWord2 = -127;
        clamp169:
            Physics35Field(context19, int*, 48) = workWord2;
        clamped169:
            workWord2 = Physics35InterpolateCosineView1(angle16);
            workWord3 = Physics35Field(context19, int*, 48);
            product35_2 = workWord3 * workWord2;
            call4 = (void*)angle16;
            workWord2 = product35_2 >> 8;
            originalFrame.spC8 = workWord2;
            workWord2 = Physics35InterpolateSineView1(call4);
            workWord3 = Physics35Field(context19, int*, 48);
            product35_3 = workWord3 * workWord2;
            vector18 = &originalFrame.spA8;
            call4 = vector18;
            MATCHING_KEEP(call4);
            base21 = &Physics35Player0View2;
            originalFrame.spD0 = 0;
            workWord2 = product35_3 >> 8;
            originalFrame.spCC = workWord2;
            workWord2 = (int)Physics35Field(context19, void**, 36);
            call6 = base21;
            call5 = (void*)(int)Physics35Field((void*)workWord2, short*, 2);
            workWord2 = Physics35Field((void*)workWord2, int*, 12);
            call5 = (void*)((int)call5 << 4);
            call5 = workWord2 + (int)call5;
            Physics35SubtractVectorView1(call4, call5, call6);
            call4 = vector18;
            call5 = vector18;
            MATCHING_KEEP2(call4, call5);
            vector20 = &originalFrame.spC8;
            Physics35AddVectorView1(call4, call5, vector20);
            length17 = Physics35MeasureVectorLengthView1(vector18, 0);
            workWord2 =
                Physics35PlanarHeadingLookupView1(originalFrame.spA8, originalFrame.spAC, 1);
            workWord3 = Physics35Player64View1;
            workWord2 -= workWord3;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            if (!workWord2)
                angle16 -= 4096;
            workWord2 = length17 < 512;
            if (workWord2)
                goto advance169;
            workWord2 = angle16;
            if (angle16 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 801;
            if (workWord2)
                goto ready169;
        advance169:
            call5 = Physics35Field(context19, void**, 36);
            workWord3 = Physics35Field(call5, short*, 0);
            workWord2 = Physics35Field(call5, short*, 2);
            numeric4 = workWord3 + 1;
            workWord2 += numeric4;
            workWord3 = workWord2 % workWord3;
            call6 = base21;
            Physics35Field(call5, short*, 2) = workWord3;
            workWord2 = (int)Physics35Field(context19, void**, 36);
            call4 = vector18;
            call5 = (void*)(int)Physics35Field((void*)workWord2, short*, 2);
            workWord2 = Physics35Field((void*)workWord2, int*, 12);
            call5 = (void*)((int)call5 << 4);
            call5 = workWord2 + (int)call5;
            Physics35SubtractVectorView1(call4, call5, call6);
            Physics35AddVectorView1(vector18, vector18, vector20);
            length17 = Physics35MeasureVectorLengthView1(vector18, 0);
        ready169:
            vector18 = &Physics35Player44View1;
            MATCHING_KEEP(vector18);
            workWord2 = originalFrame.spB0;
            workWord3 = Physics35Field(vector18, int*, 0);
            workWord2 += workWord3;
            originalFrame.spB0 = workWord2;
            call5 = Physics35Field(context19, void**, 36);
            workWord3 = Physics35Field(call5, short*, 0);
            workWord2 = Physics35Field(call5, short*, 2);
            numeric4 = workWord3 + 1;
            workWord2 += numeric4;
            next20 = workWord2 % workWord3;
            frame16 = &originalFrame.spB8;
            call6 = vector18 - 68;
            __asm__("" : "=r"(call6) : "0"(call6), "r"(length17));
            length17 -= 512;
            call4 = frame16;
            workWord2 = Physics35Field(call5, int*, 12);
            call5 = (void*)(next20 << 4);
            call5 = workWord2 + (int)call5;
            Physics35SubtractVectorView1(call4, call5, call6);
            Physics35AddVectorView1(frame16, frame16, &originalFrame.spC8);
            call4 = frame16;
            workWord2 = originalFrame.spC0;
            workWord3 = Physics35Field(vector18, int*, 0);
            call5 = 0;
            workWord2 += workWord3;
            originalFrame.spC0 = workWord2;
            Physics35MeasureVectorLengthView1(call4, call5);
            workWord2 = length17 < 4097;
            if (!workWord2)
                length17 = 4096;
            workWord2 = originalFrame.spA8;
            blend35 = length17 * workWord2;
            workWord3 = 4096;
            workWord2 = originalFrame.spB8;
            workWord3 -= length17;
            numeric6 = workWord3 * workWord2;
            workWord2 = originalFrame.spAC;
            numeric7 = length17 * workWord2;
            workWord2 = originalFrame.spBC;
            workWord3 = workWord3 * workWord2;
            frame16 = &originalFrame.spA8;
            call4 = frame16;
            call5 = (void*)6144;
            originalFrame.spB0 = 0;
            workWord2 = blend35 + numeric6;
            workWord2 >>= 12;
            originalFrame.spA8 = workWord2;
            workWord2 = numeric7 + workWord3;
            workWord2 >>= 12;
            originalFrame.spAC = workWord2;
            Physics35NormalizeVectorToLengthView1(call4, call5, numeric6, numeric7);
            Physics35CopyVectorView1(vector18 + 72, frame16);
            workWord2 = Physics35PlayerB8View1;
            if (workWord2) {
                workWord3 = Physics35Player48View1;
                workWord2 = 169;
                if (workWord3 == workWord2) {
                    workWord2 = Physics35Data6E538View1;
                    workWord3 = Physics35Field(vector18, int*, 68);
                    workWord2 &= 64;
                    call4 = vector18 + 68;
                    if (workWord2) {
                        workWord3 += 64;
                        goto storeVertical169;
                    }
                    workWord3 += 32;
                    goto storeVertical169;
                }
                workWord2 = Physics35Data6E538View1;
                workWord3 = Physics35Field(vector18, int*, 68);
                workWord2 &= 64;
                call4 = vector18 + 68;
                if (workWord2) {
                    workWord3 -= 64;
                    goto storeVertical169;
                }
                workWord3 -= 96;
            storeVertical169:
                Physics35Field(call4, int*, 0) = workWord3;
                workWord2 = Physics35Player88View1;
                Physics35Player94View1 = workWord2;
            } else {
                workWord3 = Physics35Player48View1;
                workWord2 = 169;
                if (workWord3 != workWord2) {
                    workWord2 = -96;
                    Physics35Field(vector18, int*, 80) = workWord2;
                    Physics35Field(vector18, int*, 68) = workWord2;
                } else {
                    workWord2 = 3096;
                    Physics35Field(vector18, int*, 68) = workWord2;
                    Physics35Field(vector18, int*, 80) = workWord2;
                }
            }
            call4 = &originalFrame.spA8;
            MATCHING_KEEP2_VOLATILE_CLOBBER(call4, next20, "memory");
            workWord2 = (int)Physics35Field(context19, void**, 36);
            call5 = (void*)(next20 << 4);
            workWord3 = Physics35Field((void*)workWord2, int*, 12);
            call6 = (void*)(int)Physics35Field((void*)workWord2, short*, 2);
            call5 = workWord3 + (int)call5;
            call6 = (void*)((int)call6 << 4);
            call6 = workWord3 + (int)call6;
            Physics35SubtractVectorView1(call4, call5, call6);
            workWord2 =
                Physics35PlanarHeadingLookupView1(originalFrame.spA8, originalFrame.spAC, 1);
            heading17 = &Physics35PlayerA4View1;
            workWord3 = Physics35Field(heading17, int*, 0);
            workWord2 -= workWord3;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            call4 = (void*)90;
            if (!workWord2)
                angle16 -= 4096;
            call5 = (void*)8;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            workWord2 = angle16 >> 3;
            Physics35PlayerA8View1 = workWord2;
            workWord2 = workWord3 + workWord2;
            Physics35Field(heading17, int*, 0) = workWord2;
            Physics35ApproachPlayerTargetHeadingView2(call4, call5);
            workWord2 = Physics35PlayerB8View1;
            angle16 = 300;
            if (workWord2)
                goto pitch169;
            MATCHING_KEEP_VOLATILE_CLOBBER(angle16, "$2");
            workWord2 = Physics35MeasureVectorLengthView1(heading17 - 24, 0);
            angle16 = Physics35PlanarHeadingLookupView1(workWord2, Physics35PlayerA0View1, 1);
        pitch169:
            call5 = &Physics35Player60View1;
            numeric4 = Physics35Field(call5, int*, 0);
            workWord2 = angle16 - numeric4;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            if (!workWord2)
                angle16 -= 4096;
            angle16 >>= 3;
            workWord3 = Physics35PlayerA8View1;
            workWord2 = numeric4 + angle16;
            Physics35Field(call5, int*, 0) = workWord2;
            workWord2 = Physics35Player5CView1;
            workWord3 = -workWord3;
            angle16 = workWord3 << 5;
        windJoin169:
            workWord2 = angle16 - workWord2;
            angle16 = workWord2 & 4095;
            workWord2 = angle16 < 2049;
            if (!workWord2)
                angle16 -= 4096;
            workWord3 = Physics35Field(context19, int*, 44);
            numeric4 = angle16 << 6;
            workWord2 = workWord3 * 3;
            workWord2 <<= 5;
            numeric4 -= workWord2;
            numeric4 >>= 6;
            workWord3 += numeric4;
            Physics35Field(context19, int*, 44) = workWord3;
            workWord2 = Physics35Player5CView1;
            workWord3 >>= 5;
            workWord2 += workWord3;
            Physics35Player5CView1 = workWord2;
            return;
        case 172:
            workWord2 = (int)Physics35Player250View1;
            workWord2 = (int)Physics35Field((void*)workWord2, void**, 0);
            workWord3 = Physics35Field((void*)workWord2, int*, 68);
            numeric4 = Physics35Data6C550View1;
            workWord2 = workWord3 * 3;
            workWord2 <<= 2;
            workWord2 -= workWord3;
            workWord2 <<= 3;
            numeric4 += workWord2;
            workWord2 = Physics35Field((void*)numeric4, unsigned char*, 70);
            workWord2 <<= 1;
            workWord2 = Physics35Field(&Physics35Data65920View1, short*, workWord2);
            workWord3 = workWord2 * 25;
            workWord3 >>= 5;
            originalFrame.spE0 = workWord3;
            workWord2 = Physics35Field((void*)numeric4, unsigned char*, 70);
            workWord2 <<= 1;
            numeric4 = Physics35Field(&Physics35Data658A0View1, short*, workWord2);
            workWord2 = 3200;
            originalFrame.spE8 = 0;
            Physics35Player8CView1 = workWord3;
            Physics35Player94View1 = workWord2;
            workWord2 = numeric4 * 25;
            workWord2 >>= 5;
            originalFrame.spE4 = workWord2;
            Physics35Player90View1 = workWord2;
            return;
    }
}
#undef Physics35Field


/* AI generated; not human reviewed. SCUS-94467 8008A2EC..8008A804.
 * Baselines: verified level45_80087D60 particle loop and level17_80082B84
 * state30 scalar producers, adapted only to the original level35 instructions.
 * Two vector stack slots, byte offsets, signed shifts6/9 and numeric limits
 * retain original domains; helper meanings, units and cadence remain open.
 * Empty constraints preserve original register and memory lifetimes.
 * Acceptance requires all original linked words and complete retail hashes.
 */
extern int Callback35Step __asm__("D_80070328+0x144");
extern int Callback35Z __asm__("D_80070328+8");
extern int Callback35Limit __asm__("D_80070328+0x280");
extern Spyro Callback35Player __asm__("D_80070328");
int Callback35SamplePlanarPhaseTable(int x, int y) __asm__("func_80037058");
int Callback35SoundHandleMatchesIdInStates1Or2(int soundId, int index) __asm__("func_8003BF6C");
void Callback35ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback35CapturePlayerPlanarVectorDifference(void) __asm__("func_80041AE8");
void Callback35UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback35UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
void Callback35BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
void Callback35MarkPlayerSegmentSurfaceType3Flags(void) __asm__("func_80049590");
void Callback35ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
extern int Callback35Word8006E344 __asm__("D_8006E344");
extern int Callback35Word8006E52C __asm__("D_8006E52C");
extern int Callback35Word8006E530 __asm__("D_8006E530");
extern int Callback35Word8006E538 __asm__("D_8006E538");
extern short Callback35Count __asm__("D_80070328+0x148");
extern int D_8006FA38, D_8006C648;
int Callback35Query(Vector3D*, int) __asm__("func_8001A358");
void func_level_35_8008A2EC(void) {
    struct {
        Vector3D first;
        int reserved1C;
        Vector3D second;
        int reserved2C;
        int reserved[2];
    } local;
    register int* stateWord __asm__("$19") = &Callback35Player.animationState;
    register unsigned char* sourceBytes __asm__("$19");
    register Vector3D* vectorPointer __asm__("$17");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int height __asm__("$3");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int, int, Vector3D*, Vector3D*)__asm__("$8");
    int computedValue;
    switch (*stateWord) {
        case 0x35:
        case 0x36:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
        clearSharedValue:
            Callback35Player.unk4[0] = 0;
            return;
        case 25:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
            Callback35ProbePlayerContactSegment();
            Callback35MarkPlayerSegmentSurfaceType3Flags();
            if ((Callback35Player.movementState == MOVEMENT_STATE_SUPERCHARGE) &&
                (SpawnParticle != 0)) {
                SpawnParticle(1, 9, 0, 0);
            }
            if ((Callback35Player.unk7a[3].z < 0) && (Callback35Player.animationStateFrames >= 4)) {
                Callback35Player.unk5 = 1;
            } else if ((Callback35Player.unk5 == 0) && !(Callback35Word8006E538 & 0x40)) {
                Callback35Player.unk5 = 2;
            }
            goto clearSharedValue;
        case 0x1E: {
            register int velocity __asm__("$5") = Callback35Step;
            register int positionValue __asm__("$2") = Callback35Z;
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
            Callback35Z = positionValue;
            status = Callback35Limit;
            velocity += tick;
            Callback35Step = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    Callback35Step = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    Callback35Step = 0x2580;
            }
        limitsDone:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
            func_8004F178(&local.first, &Callback35Player.position);
            local.first.z += 0x400;
            Callback35Player.unk4[0] = Callback35Query(&local.first, 0xC00);
            sample = (int)Callback35Player.union144.a.unk13cb;
            height = Callback35Player.position.z;
            sample >>= 6;
            goto storePosition;
        }
        case 0x21:
        case 0x22:
        case 0x23:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
            Callback35ProbePlayerContactSegment();
            if (SpawnParticle != 0) {
                if (Callback35Count == 0)
                    goto clearSharedValue;
                secondLimit = 1;
                if (Callback35Count >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    vectorPointer = &local.second;
                    MATCHING_KEEP2(vectorPointer, stateWord);
                    sourceBytes = (unsigned char*)stateWord + 0x50;
                    do {
                        func_8004F178(vectorPointer, (Vector3D*)sourceBytes);
                        Callback35ShiftVectorRightTowardZero(vectorPointer, 7);
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
                        vector = vectorPointer;
                        __asm__(""
                                : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector)
                                : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample)
                                : "$3", "$8", "memory");
                        sample &= 254;
                        __asm__("" : "=r"(sample) : "0"(sample) : "$3", "$8", "memory");
                        component = local.second.z;
                        __asm__("" : "=r"(component) : "0"(component) : "$8", "memory");
                        particles = SpawnParticle;
                        MATCHING_KEEP2(particles, component);
                        component -= 127;
                        component += sample;
                        MATCHING_KEEP(component);
                        local.second.z = component;
                        particles(kind, subtype, (Vector3D*)position, vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
        case 0x37:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
            Callback35CapturePlayerPlanarVectorDifference();
            if ((unsigned char)Callback35Player.unk10[4] != 0) {
                computedValue = -Callback35Player.unk9ha[4] -
                                Callback35SamplePlanarPhaseTable(Callback35Player.position.x,
                                                                 Callback35Player.position.y);
                height = Callback35Player.unk4a - computedValue;
                Callback35Player.unk4[0] = computedValue;
                sample = (int)Callback35Player.union144.a.unk13cc >> 6;
                goto storePosition;
            }

            return;
        storePosition:
            height -= sample;
            MATCHING_KEEP(height);
            Callback35Player.position.z = height;
            return;
        case 0x3D:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
            Callback35BuildNegatedNormalizedPlayerVector(0xC00);
            Callback35MarkPlayerSegmentSurfaceType3Flags();
            if (SpawnParticle != 0) {
                SpawnParticle(1, 9, 0, 0);
            }
            Callback35Word8006E530 = 0x78;
            Callback35Player.unk4[0] = 0;
            Callback35Word8006E52C = 4;
            if ((Callback35Word8006E344 == 0) &&
                (Callback35SoundHandleMatchesIdInStates1Or2((int)D_8006C654->supercharge,
                                                            Callback35Player.unk22[2]) == 0)) {
                Callback35Player.unk22[2] = PlaySound((int)D_8006C654->supercharge, 0, 4);
                Callback35Player.unk22[3] = (int)D_8006C654->supercharge;
            }

            return;
        case 0xA5:
        case 0xA6:
        case 0xA7:
        case 0xA8:
        case 0xA9:
        case 0xAA:
        case 0xAB:
            Callback35UpdatePlayerCollisionResponse();
            Callback35UpdatePlayerSurfaceState();
            return;
        case 0xAC:
            Callback35UpdatePlayerCollisionResponse();
            return;
        default:
            return;
    }
}


#define LEVEL_ID 35
#define PlaySpyroSounds_level_35 func_level_35_8008A808
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_35_8008A910(int index) {
    register int* state __asm__("$5");
    register int value __asm__("$3");
    register unsigned char* base __asm__("$2");
    register unsigned int offset __asm__("$4");
    offset = index * 16;
    MATCHING_KEEP_CLOBBER(offset, "$2");
    base = D_8006E548;
    __asm__("" : "=r"(base) : "0"(base), "r"(offset) : "$5");
    state = &spyro.animationState;
    value = *state;
    MATCHING_KEEP_CLOBBER(value, "memory");
    offset = offset + (unsigned int)base;
    __asm__("" : "=r"(offset) : "0"(offset), "r"(value));
    D_8006C570 = (unsigned char*)offset;
    __asm__("" : : "r"(value) : "$2", "memory");
    if (value < 0x2D) {
        if (value >= 0x2B)
            goto vector;
        if (value == 0x1E)
            goto vector;
        if (value >= 0x1F)
            return;
        if (value == 0x19)
            goto other;
        return;
    } else {
        if (value == 0x3D)
            goto vector;
        if (value >= 0x3E)
            return;
        if (value >= 0x38)
            return;
        if (value < 0x35)
            return;
    }
vector:
    MATCHING_OBSERVE(value);
    func_80043ABC(&spyro.unk9e);
    return;
other:
    func_80043E00((Vector3D*)((char*)state + 0x44));
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A9C4.
 * Verified25 fly/surface/charge and23 drowning. Original35 independent35/36
 * dispatch, surface stack10, A5..AC state12 and A9 vector/C18 path retained.
 * Numeric offsets are bytes; clamp7FF/800/4B00/4B01 gives800/800/4B00/4B00
 * before later helpers. Every code/internal jump/owned word, complete TU and
 * all retail hashes required. Helpers, units, audio, cadence/live parity open.
 */
extern Spyro Transition35Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw35Word __asm__("D_80070328+0x50");
extern unsigned char Raw35State[] __asm__("D_80070328+0x50");
extern unsigned char Raw35Union[] __asm__("D_80070328+0x144");
extern int Raw35Spit __asm__("D_80070328+0x170");
void Call35_ClearVector(Vector3D*) __asm__("func_8004F168");
int Call35_MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
int Call35QueryWorldHeight(Vector3D*, int) __asm__("func_8001A358");
void Call35_ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Call35_BuildNegatedNormalizedPlayerVector(int) __asm__("func_80043A38");
void func_80047138(void);
extern int Transition35DamageTimer __asm__("D_8006E524");
void func_level_35_8008A9C4(int arg0) {
    Vector3D surfaceVector;
    int vectorLength, surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");
    switch (arg0) {
        case 0x35:
            MATCHING_BARRIER_VOLATILE("memory");
            goto standEntry;
        case 0x36:
        standEntry:
            Transition35Player.movementState = MOVEMENT_STATE_STAND;
            Transition35Player.unk5 = 0;
            Call35_ClearPlayerMotionVectors();
            Transition35Player.grounded = 1;
            goto clearPointers;

        case 0x19:
            soundZero = 0;
            MATCHING_KEEP(soundZero);
            soundTable = (unsigned char*)D_8006C654;
            MATCHING_KEEP(soundTable);
            Transition35Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
            Transition35Player.unk13a[0] = 0x60000;
            Transition35Player.unk5 = 0;
            Transition35Player.union144.a.unk13cb = 0;
            Transition35Player.grounded = 0;
            Transition35Player.unk15b = 1;
            soundSelector = soundTable[0x22];
        playSharedSound:
            PlaySound((int)soundSelector, (Moby*)soundZero, 0);
            goto clearPointers;
        case 0x1E: {
            register int oldState __asm__("$3") = Raw35Word;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Raw35Word = value;
            value = 1;
            MATCHING_KEEP(value);
            Transition35Player.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Transition35DamageTimer = value;
            stateWord = (int*)Raw35Union;
            MATCHING_KEEP(stateWord);
            Transition35Player.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Transition35Player.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            value = (int)D_8006C654->drown;
            MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
            Transition35Player.unk20a = 0;
            Transition35Player.critterMobyPtr = 0;
            Transition35Player.unk22[3] = value;
            return;
        }
        case 0x21:
        case 0x22:
        case 0x23: {
            register unsigned char* flyState __asm__("$17") = (unsigned char*)&Raw35Word;
            if (*(int*)flyState != 6) {
                *(int*)flyState = 6;
                Transition35Player.unk5 = 0;
                Call35_ClearVector((Vector3D*)(flyState + 0x104));
                Transition35Player.union144.a.unk13db.y = 0;
                vectorLength = Call35_MeasureVectorLength((Vector3D*)(flyState + 0x48), 0);
                Transition35Player.unk8[0] = vectorLength;
                if (vectorLength < 0x800)
                    Transition35Player.unk8[0] = 0x800;
                if (Transition35Player.unk8[0] >= 0x4B01)
                    Transition35Player.unk8[0] = 0x4B00;
                Transition35Player.union144.a.unk13cb = 0;
                Transition35Player.union144.b.unk148 = 0;
                Transition35Player.union144.a.unk13ce.x = 0;
                Transition35Player.union144.a.unk13ce.y = 0;
                Transition35Player.grounded = 0;
                Transition35Player.unk15b = 0;
            }
            if (arg0 < 0xA0)
                goto clearPointers;
            return;
        }
        case 0x2B:
        case 0x2C: {

            register unsigned char* unionPointer __asm__("$16");
            {
                register int stateWord __asm__("$3") = Raw35Word;
                register int initialKind __asm__("$2") = 10;
                MATCHING_KEEP2(stateWord, initialKind);
                if (stateWord != initialKind) {
                    PlaySound((int)D_8006C654->waterSurface, 0, 0);
                    unionPointer = Raw35Union;
                    *(int*)unionPointer = (-Transition35Player.unk7a[2].z) >> 2;
                    if (Raw35Word != 8) {
                        Transition35Player.union144.a.unk13cc = 0x5900;
                        Raw35Word = 10;
                    }
                    Transition35Player.unk5 = 0;
                    Transition35Player.unk8[0] =
                        Call35_MeasureVectorLength((Vector3D*)(unionPointer - 0xAC), 0);
                    Transition35Player.grounded = 1;
                    Transition35Player.unk15b = 1;
                    func_8004F178(&surfaceVector, (Vector3D*)(unionPointer - 0x144));
                    surfaceVector.z += 0x400;
                    surfaceResult = Call35QueryWorldHeight(&surfaceVector, 0x800);
                    surfaceVector.z = surfaceResult;
                    if (surfaceResult != 0 && D_80071934 != 0 && SpawnParticle) {
                        SpawnParticle(10, 0x29, &surfaceVector, 0);
                        SpawnParticle(6, 0x2E, &surfaceVector, 0);
                    }
                }
            }
            goto clearPointers;
        }

        case 0x37:
            originalZ = 8;
            MATCHING_KEEP(originalZ);
            Raw35Word = originalZ;
            MATCHING_BARRIER_VOLATILE("memory");
            originalZ = Transition35Player.unk7a[2].z;
            MATCHING_KEEP(originalZ);
            {
                register int flagValue __asm__("$3") = 1;
                MATCHING_KEEP(flagValue);
                Transition35Player.unk15b = flagValue;
                MATCHING_BARRIER_VOLATILE("memory");
            }
            soundTable = (unsigned char*)D_8006C654;
            MATCHING_KEEP(soundTable);
            Transition35Player.union144.a.unk13cc = 0;
            Transition35Player.unk5 = 0;
            Transition35Player.grounded = 0;
            MATCHING_KEEP_VOLATILE_CLOBBER(originalZ, "memory");
            Transition35Player.union144.a.unk13cb = -originalZ >> 2;
            soundSelector = soundTable[7];
            soundZero = 0;
            goto playSharedSound;
        case 0x3D:
            stateBase = Raw35State;
            *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
            Transition35Player.unk5 = 0;
            Transition35Player.unk13a[0] = 0x60000;
            Transition35Player.unk8[0] =
                Call35_MeasureVectorLength((Vector3D*)(stateBase + 0x48), 0);
            Transition35Player.horizontalSpeed = 0x1E80;
            Call35_BuildNegatedNormalizedPlayerVector(0xC00);
            Transition35Player.grounded = 1;
            if ((Transition35Player.unk13f[0] != 0) || (Transition35Player.spitState != 0) ||
                (Transition35Player.unk17t != 6)) {
                spitWord = &Raw35Spit;
                if (((unsigned)(*spitWord - 3) < 2U) || (*spitWord == 5)) {
                    *spitWord = 5;
                } else {
                    *spitWord = 0;
                }
                Transition35Player.spitState = 0;
                Transition35Player.unk17t = 6;
                func_80047138();
            }
        clearPointers:
            Transition35Player.unk20a = 0;
            Transition35Player.critterMobyPtr = 0;
            return;
        case 0xA5:
        case 0xA6:
        case 0xA7:
        case 0xA8:
        case 0xA9:
        case 0xAA:
        case 0xAB:
        case 0xAC: {
            register unsigned char* state __asm__("$17") = Raw35State;
            register Vector3D* vector __asm__("$16");
            if (*(int*)state != 18) {
                *(int*)state = 18;
                Transition35Player.unk5 = 0;
                Transition35Player.grounded = 0;
                Transition35Player.unk15b = 0;
                Call35_ClearVector((Vector3D*)(state + 0x30));
                Call35_ClearVector((Vector3D*)(state + 0x3C));
                return;
            }
            if (arg0 == 0xA9) {
                {
                    register Vector3D* destination __asm__("$4") = (Vector3D*)(state + 0x3C);
                    MATCHING_KEEP(destination);
                    vector = (Vector3D*)(state + 0x48);
                    func_8004F178(destination, vector);
                }
                Transition35Player.unk8[0] = Call35_MeasureVectorLength(vector, 0);
                Transition35Player.unk7a[2].z = 0xC18;
            }
            return;
        }
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level35
 * 8008AF8C: original863 instructions and148 dispatch words in sibling4851
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original35.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A35W48 __asm__("D_80070328 + 0x48");
extern int A35W4C __asm__("D_80070328 + 0x4C");
extern int A35W54 __asm__("D_80070328 + 0x54");
extern int A35WA0 __asm__("D_80070328 + 0xA0");
extern int A35WA8 __asm__("D_80070328 + 0xA8");
extern int A35WAC __asm__("D_80070328 + 0xAC");
extern int A35WB0 __asm__("D_80070328 + 0xB0");
extern int A35WB8 __asm__("D_80070328 + 0xB8");
extern int A35WCC __asm__("D_80070328 + 0xCC");
extern int A35WD0 __asm__("D_80070328 + 0xD0");
extern int A35WD4 __asm__("D_80070328 + 0xD4");
extern int A35W8C __asm__("D_80070328 + 0x8C");
extern int A35W90 __asm__("D_80070328 + 0x90");
extern int A35W94 __asm__("D_80070328 + 0x94");
extern int A35WE4 __asm__("D_80070328 + 0xE4");
extern int A35W144 __asm__("D_80070328 + 0x144");
extern int A35W158 __asm__("D_80070328 + 0x158");
extern int A35W1EC __asm__("D_80070328 + 0x1EC");
extern int A35W1F0 __asm__("D_80070328 + 0x1F0");
extern int A35W240 __asm__("D_80070328 + 0x240");
extern int A35W280 __asm__("D_80070328 + 0x280");
extern unsigned char A35B14 __asm__("D_80070328 + 0x14");
extern unsigned char A35B15 __asm__("D_80070328 + 0x15");
extern unsigned char A35B16 __asm__("D_80070328 + 0x16");
extern unsigned char A35B17 __asm__("D_80070328 + 0x17");
extern unsigned char A35B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A35BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A35B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A35B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A35Player[] __asm__("D_80070328");
extern unsigned char A35Table[] __asm__("D_80066530");
extern int A35Buttons __asm__("D_8006E538"), A35NewButtons __asm__("D_8006E53C");
extern int A35Mode __asm__("D_8006E044"), A35Gate __asm__("D_8006E344"),
    A35Count __asm__("D_8006C514");
extern int (*A35Callback)() __asm__("unk_ovlheader_80074374");
extern int A35W24 __asm__("D_80070328 + 0x24");
extern int A35W28C __asm__("D_80070328 + 0x28C");
extern int A35W290 __asm__("D_80070328 + 0x290");
extern int A35Surface __asm__("D_8006FA38");
extern unsigned char* A35SoundDesc __asm__("D_8006C654");
int A35Sound() __asm__("PlaySound");
int A35SoundHandleMatchesIdInStates1Or2() __asm__("func_8003BF6C");
int A35TransitionSoundHandleTo3Or5() __asm__("func_8003BE70");
int A35ProcessPlayerStateFlags() __asm__("func_80040994");
int A35DispatchPlayerStateRequest() __asm__("func_8004BEF8");
int A35UpdatePlayerRetryState() __asm__("func_800498C0");
extern volatile int A35W20C __asm__("D_80070328 + 0x20C");
extern int A35W214 __asm__("D_80070328 + 0x214");
extern unsigned char A35B100 __asm__("D_80070328 + 0x100");
extern unsigned char A35E535 __asm__("D_8006E535");
extern unsigned char* A35Models __asm__("D_8006EE2C");
int A35ProcessPlayerContactFlags() __asm__("func_80040BCC");
int A35QueryWorldHeightWithOptions() __asm__("func_8001A310");
extern int A35W10C __asm__("D_80070328 + 0x10C");
extern int A35WB4 __asm__("D_80070328 + 0xB4");
extern int A35WA4 __asm__("D_80070328 + 0xA4");
extern int (*A35Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A35GetSurfaceTypeFromFlags() __asm__("func_80040954");
extern int A35W50 __asm__("D_80070328 + 0x50");
extern int A35WBC __asm__("D_80070328 + 0xBC"), A35W1BC __asm__("D_80070328 + 0x1BC"),
    A35W60 __asm__("D_80070328 + 0x60");
extern short A35H148 __asm__("D_80070328 + 0x148");
int A35TestPlayerProbePattern() __asm__("func_80043194");
int A35MeasureVectorLength() __asm__("func_8004EDE8");
extern unsigned char* volatile A35W250 __asm__("D_80070328 + 0x250");
void func_level_35_8008AF8C(void) {
    register int work2 __asm__("$2"), work3 __asm__("$3"), work4 __asm__("$4"), work5 __asm__("$5");
    register int* state __asm__("$16");
    register int* locomotion __asm__("$17");
    switch (A35W48) {
        case 26:
        case 27:
        case 28:
        case 29:
        case 31:
        case 32:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 56:
        case 57:
        case 58:
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
        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 114:
        case 115:
        case 116:
        case 117:
        case 118:
        case 119:
        case 120:
        case 121:
        case 122:
        case 123:
        case 124:
        case 125:
        case 126:
        case 127:
        case 128:
        case 129:
        case 130:
        case 131:
        case 132:
        case 133:
        case 134:
        case 135:
        case 136:
        case 137:
        case 138:
        case 139:
        case 140:
        case 141:
        case 142:
        case 143:
        case 144:
        case 145:
        case 146:
        case 147:
        case 148:
        case 149:
        case 150:
        case 151:
        case 152:
        case 153:
        case 154:
        case 155:
        case 156:
        case 157:
        case 158:
        case 159:
        case 160:
        case 161:
        case 162:
        case 163:
        case 164:
        case 172:
            return;
        case 53:
        case 54:
            work2 = A35ProcessPlayerStateFlags();
            work4 = 0;
            if (work2)
                return;
            goto call;

        case 25:
            if (A35ProcessPlayerContactFlags())
                return;
            if (A35B1B5 && (A35NewButtons & 64))
                A35B1B6 = 1;
            if (A35WE4 >= 23) {
                work3 = A35W8C;
                work2 = A35WCC;
                work4 = work3 * work2;
                work3 = A35W90;
                work2 = A35WD0;
                work3 = work3 * work2;
                work2 = work4 + work3;
                work4 = 14;
                if (work2 < 0)
                    goto call;
            }
            work3 = A35WB0;
            if (work3 >= 3201) {
                work2 = A35WB4 * 2;
                work2 = work2 < work3;
                work4 = 14;
                if (work2)
                    goto call;
            }
            if (!A35WB8) {
                work2 = A35W54 < 5;
                work4 = 61;
                if (!work2)
                    goto call;
            }
            if (A35B1B6) {
                work2 = A35W94;
                work4 = 17;
                if (work2 >= 0)
                    return;
                goto call;
            }
            work2 = A35W94;
            work4 = 22;
            if (work2 >= 0)
                return;
            goto call;
        case 30: {
            register int* timer4 __asm__("$4");
            register int (*callback3)() __asm__("$3");
            if (A35NewButtons & 64)
                A35B1B6 = 1;
            if (A35Surface >= 0) {
                if (A35W144 <= 0x8FFF)
                    return;
                callback3 = A35Callback;
                A35W28C = -1;
                if (callback3) {
                    callback3();
                    return;
                }
                goto call498C0;
            }
            timer4 = &A35W280;
            MATCHING_KEEP(timer4);
            if (*timer4 < 0) {
                if (A35W144 <= 0x8FFF)
                    return;
                A35W28C = -1;
            call498C0:
                A35UpdatePlayerRetryState();
                MATCHING_BARRIER_VOLATILE("memory");
                return;
            }
            work3 = A35W54;
            if (work3 >= 61) {
                *timer4 = -1;
                return;
            }
            work2 = work3 < 16;
            MATCHING_KEEP(work2);
            if (work2)
                return;
            if (!A35B1B6)
                return;
            if (A35W28C >= 0) {
                if (A35SoundHandleMatchesIdInStates1Or2(A35W290, A35W28C))
                    A35TransitionSoundHandleTo3Or5(A35W28C);
                A35W28C = -1;
            }
            work4 = 6;
            goto call;
        }
        case 33:

            if (A35ProcessPlayerStateFlags())
                return;
            locomotion = &A35WB8;
            MATCHING_KEEP(locomotion);
            if (!*locomotion) {
                if (A35WE4 >= 23)
                    A35DispatchPlayerStateRequest(7);
                if (A35WAC > 0) {
                    work3 = A35WB0;
                    work2 = work3 < 3841;
                    if (!work2) {
                        MATCHING_BARRIER_VOLATILE("memory");
                        work4 = 3;
                        goto call;
                    }
                    work2 = work3 < 1921;
                    MATCHING_KEEP(work2);
                    work4 = 1;
                    if (work2)
                        goto call;
                    MATCHING_BARRIER_VOLATILE("memory");
                    work4 = 2;
                    goto call;
                }
                work2 = A35WB0 < 1920;
                work4 = 0;
                if (work2)
                    goto call;
                MATCHING_BARRIER_VOLATILE("memory");
                work4 = 4;
                goto call;
            }
            state = &A35NewButtons;
            MATCHING_KEEP(state);
            work2 = *state & 128;
            work4 = 22;
            if (work2)
                goto call;
            work2 = A35TestPlayerProbePattern(4);
            work4 = 47;
            if (work2)
                goto call;
            work2 = A35WBC;
            work4 = 7;
            if (!work2)
                goto call;
            work2 = A35W1BC;
            work4 = 17;
            if (!work2)
                goto call;
            work2 = *state & 16;
            work4 = 18;
            if (work2)
                goto call;
            work4 = (int)locomotion - 32;
            work2 = A35MeasureVectorLength((void*)work4, 1);
            work2 = work2 < 1024;
            work4 = 7;
            if (work2)
                goto call;
            work2 = A35H148 < 2;
            work4 = 35;
            if (!work2)
                goto call;
            work2 = A35W4C;
            work4 = 34;
            if (work2)
                goto call;
            work3 = A35W60;
            work2 = work3 < 365;
            if (!work2)
                goto call;
            work2 = work3 < -364;
            work4 = 35;
            if (!work2)
                return;
            goto call;

        case 34:

            if (A35ProcessPlayerStateFlags())
                return;
            locomotion = &A35WB8;
            MATCHING_KEEP(locomotion);
            if (!*locomotion) {
                if (A35WE4 >= 23)
                    A35DispatchPlayerStateRequest(7);
                if (A35WAC > 0) {
                    work3 = A35WB0;
                    work2 = work3 < 3841;
                    if (!work2) {
                        MATCHING_BARRIER_VOLATILE("memory");
                        work4 = 3;
                        goto call;
                    }
                    work2 = work3 < 1921;
                    MATCHING_KEEP(work2);
                    work4 = 1;
                    if (work2)
                        goto call;
                    MATCHING_BARRIER_VOLATILE("memory");
                    work4 = 2;
                    goto call;
                }
                work2 = A35WB0 < 1920;
                work4 = 0;
                if (work2)
                    goto call;
                MATCHING_BARRIER_VOLATILE("memory");
                work4 = 4;
                goto call;
            }
            state = &A35NewButtons;
            MATCHING_KEEP(state);
            work2 = *state & 128;
            work4 = 22;
            if (work2)
                goto call;
            work2 = A35TestPlayerProbePattern(4);
            work4 = 47;
            if (work2)
                goto call;
            work2 = A35WBC;
            work4 = 7;
            if (!work2)
                goto call;
            work2 = A35W1BC;
            work4 = 17;
            if (!work2)
                goto call;
            work2 = *state & 16;
            work4 = 18;
            if (work2)
                goto call;
            work4 = (int)locomotion - 32;
            work2 = A35MeasureVectorLength((void*)work4, 1);
            work2 = work2 < 1024;
            work4 = 7;
            if (work2)
                goto call;
            work2 = A35H148 < 2;
            work4 = 35;
            if (!work2)
                goto call;
            if (A35W60 >= 256)
                return;
            work2 = A35W4C;
            work4 = 33;
            if (work2)
                return;
            goto call;

        case 35:

            if (A35ProcessPlayerStateFlags())
                return;
            locomotion = &A35WB8;
            MATCHING_KEEP(locomotion);
            if (!*locomotion) {
                if (A35WE4 >= 23)
                    A35DispatchPlayerStateRequest(7);
                if (A35WAC > 0) {
                    work3 = A35WB0;
                    work2 = work3 < 3841;
                    if (!work2) {
                        work4 = 3;
                        goto call;
                    }
                    work2 = work3 < 1921;
                    MATCHING_KEEP(work2);
                    work4 = 1;
                    if (work2)
                        goto call;
                    MATCHING_BARRIER_VOLATILE("memory");
                    work4 = 2;
                    goto call;
                }
                work2 = A35WB0 < 1920;
                work4 = 0;
                if (work2)
                    goto call;
                MATCHING_BARRIER_VOLATILE("memory");
                work4 = 4;
                goto call;
            }
            state = &A35NewButtons;
            MATCHING_KEEP(state);
            work2 = *state & 128;
            work4 = 22;
            if (work2)
                goto call;
            work2 = A35TestPlayerProbePattern(4);
            work4 = 47;
            if (work2)
                goto call;
            work2 = A35WBC;
            work4 = 7;
            if (!work2)
                goto call;
            work2 = A35W1BC;
            work4 = 17;
            if (!work2)
                goto call;
            work2 = *state & 16;
            work4 = 18;
            if (work2)
                goto call;
            work4 = (int)locomotion - 32;
            work2 = A35MeasureVectorLength((void*)work4, 1);
            work2 = work2 < 1024;
            work4 = 7;
            if (work2)
                goto call;
            if (A35H148 >= 2)
                return;
            work2 = A35W4C;
            work4 = 34;
            if (work2)
                goto call;
            work2 = A35W60 < -255;
            work4 = 33;
            if (work2)
                return;
            goto call;

        case 43: {
            register unsigned char* byte4 __asm__("$4");
            if (A35ProcessPlayerStateFlags())
                return;
            if ((A35NewButtons & 64) && A35W54 >= 9) {
                work4 = 6;
                goto partialCall;
            }
            byte4 = &A35B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                work4 = 7;
                goto partialCall;
            }
            if (!(A35NewButtons & 128))
                goto check44;
            if (A35W54 < 9)
                goto check44;
            work2 = *(int*)(A35Models + 220);
            byte4 -= 256;
            if (!work2)
                goto check44;
            work2 = A35QueryWorldHeightWithOptions(byte4, 1024, 1, 0);
            work4 = 40;
            if (work2)
                goto check44;
            goto call;
        partialCall:
            A35DispatchPlayerStateRequest(work4);
        check44:
            work2 = A35E535;
            work4 = 44;
            if (!work2)
                return;
            goto call;
        }
        case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            work3 = A35W4C;
            work2 = 1;
            if (work3 != work2)
                goto other44;
            if (A35NewButtons & 0x850)
                goto callback44;
            if (A35W54 < 61)
                return;
        callback44:
            callback2 = A35Callback;
            MATCHING_KEEP(callback2);
            if (!callback2)
                goto call498C0;
            callback2();
            return;
        other44:
            if (A35ProcessPlayerStateFlags())
                return;
            if ((A35NewButtons & 64) && A35W54 >= 9) {
                work4 = 6;
                goto call;
            }
            byte4 = &A35B100;
            MATCHING_KEEP(byte4);
            if (!*byte4) {
                work4 = 7;
                goto call;
            }
            if (!(A35NewButtons & 128))
                goto mode44;
            if (A35W54 < 9)
                goto mode44;
            work2 = *(int*)(A35Models + 220);
            byte4 -= 256;
            if (!work2)
                goto mode44;
            work2 = A35QueryWorldHeightWithOptions(byte4, 1024, 1, 0);
            work4 = 40;
            if (!work2)
                goto call;
        mode44:
            work3 = A35Mode;
            work2 = 7;
            if (work3 == work2)
                return;
            work2 = A35E535;
            work4 = 43;
            if (work2)
                return;
            goto call;
        }
        case 55:
            if (A35W54 < 101)
                return;
            A35DispatchPlayerStateRequest(44);
            work2 = 1;
            A35W4C = work2;
            work2 = 8;
            A35W50 = work2;
            return;

        case 61:
            if (A35ProcessPlayerContactFlags())
                return;
            work2 = 1;
            MATCHING_KEEP(work2);
            state = &A35W4C;
            MATCHING_KEEP(state);
            work3 = *state;
            if (work3 == work2) {
                if (A35WB8 >= 4)
                    goto partial25;
                work2 = A35GetSurfaceTypeFromFlags(A35W10C);
                work3 = 9;
                if (work2 == work3)
                    goto finalSpeed;
                *state = 0;
                goto finalSpeed;
            }
            if (A35Buttons & 64) {
            partial25:
                A35DispatchPlayerStateRequest(25);
                work2 = A35WB8;
                work3 = 3520;
                A35W94 = work3;
                A35WB8 = work2 + 1;
                return;
            }
            work2 = A35WB8 < 4;
            work4 = 25;
            if (!work2)
                goto call;
            if (A35WE4 >= 23) {
                work3 = A35WCC;
                work2 = A35W8C;
                work4 = work3 * work2;
                work3 = A35WD0;
                work2 = A35W90;
                work3 = work3 * work2;
                work2 = work4 + work3;
                work4 = 7;
                if (work2 < 0)
                    goto call;
            }
            {
                register int* pointer4 __asm__("$4");
                pointer4 = &A35W4C;
                MATCHING_KEEP(pointer4);
                work3 = *pointer4;
                work2 = 2;
                if (work3 == work2 && A35W54 >= 16)
                    *pointer4 = 0;
            }
            if (A35Buttons & 128)
                goto finalSpeed;
            work2 = A35Surface;
            if (work2 >= 0)
                goto finalSpeed;
            work2 = 2;
            work3 = A35W4C;
            work4 = 3;
            if (work3 != work2)
                goto call;
        finalSpeed:
            work3 = A35WB0;
            work2 = work3 < 3201;
            if (work2)
                return;
            work2 = A35WB4 * 2;
            work2 = work2 < work3;
            work4 = 14;
            if (!work2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
            goto call;
        case 165:
        case 166:
        case 167:
            if (A35Buttons & 64) {
                work2 = (int)A35W250;
                work3 = *((unsigned char*)work2 + 72);
                work2 = 4;
                work4 = 169;
                if (work3 != work2) {
                    MATCHING_BARRIER_VOLATILE("memory");
                    goto call;
                }
            } else {
                work2 = (int)A35W250;
                work3 = *((unsigned char*)work2 + 72);
                work2 = 4;
                if (work3 != work2)
                    goto gate24;
            }
            work2 = (int)A35W250;
            work2 = *((unsigned char*)work2 + 73);
            work4 = 172;
            if (work2)
                goto call;
        gate24:
            state = &A35W24;
            MATCHING_KEEP(state);
            if (!*state)
                return;
            A35DispatchPlayerStateRequest(168);
            *state = 0;
            return;
        case 168:
            if (A35Buttons & 64) {
                work2 = (int)A35W250;
                work3 = *((unsigned char*)work2 + 72);
                work2 = 4;
                work4 = 169;
                if (work3 != work2) {
                    MATCHING_BARRIER_VOLATILE("memory");
                    goto call;
                }
            } else {
                work2 = (int)A35W250;
                work3 = *((unsigned char*)work2 + 72);
                work2 = 4;
                if (work3 != work2)
                    goto check171;
            }
            work2 = (int)A35W250;
            work2 = *((unsigned char*)work2 + 73);
            work4 = 172;
            if (!work2)
                goto check171;
            goto call;
        case 169: {
            register unsigned char* pointer4 __asm__("$4");
            pointer4 = A35W250;
            work2 = A35W48;
            work3 = pointer4[60];
            work2 -= 163;
            if (work3 != work2)
                return;
            work2 = pointer4[66] & 2;
            work4 = 170;
            if (!work2)
                return;
            goto call;
        }
        case 170:
            work2 = A35WB8;
            work4 = 171;
            if (work2)
                return;
            goto call;
        case 171: {
            register unsigned char* pointer4 __asm__("$4");
        check171:
            pointer4 = A35W250;
            work2 = A35W48;
            work3 = pointer4[60];
            work2 -= 163;
            if (work3 != work2)
                return;
            work2 = pointer4[66] & 2;
            work4 = 165;
            if (!work2)
                return;
            MATCHING_BARRIER_VOLATILE("memory");
        call:
            MATCHING_BARRIER_VOLATILE("memory");
            A35DispatchPlayerStateRequest(work4);
            return;
        }
    }
}
