#include "matching.h"
#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008E538.
 * Assembly SHA256 0a9dad922bdac29ad9ea8df712b1b56aa1e64cc26e0ab87b7ae5771d37f08718.
 * AI-generated; not human reviewed. All872 original instructions,
 * 18 selectors bias115 and 0 owned padding words are required.
 * Original frame0x90; every concrete field width and producer is retained.
 * Nine exact groups reuse verified44 Agent9 physics. Original128 uses
 * direct SP10 vector arguments and S1 vector8C,with no invented saved frame
 * pointer. Original scratch10..74,savedS0..S4,combinedS3 and incoming A0
 * prefix are retained. All115..132 fields,callbacks,scalar/division/trig,
 * vector/control branches and actual shared targets remain original.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics46Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Physics46Call41B64View1() __asm__("func_80041B64");
int Physics46InterpolateSineView1() __asm__("func_8004E9E4");
int Physics46InterpolateCosineView1() __asm__("func_8004EA2C");
int Physics46MeasureVectorLengthView1() __asm__("func_8004EDE8");
unsigned char Physics46ScaleVectorRatioQ15View1() __asm__("func_8004F08C");
unsigned char Physics46AddVectorView1() __asm__("func_8004F194");
unsigned char Physics46SubtractVectorView1() __asm__("func_8004F1C8");
extern void* Physics46Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics46Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics46Player0View1 __asm__("D_80070328");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics46Call40D10View1() __asm__("func_80040D10");
int Physics46Call40F48View1() __asm__("func_80040F48");
int Physics46Call41580View1() __asm__("func_80041580");
int Physics46Call416F4View1() __asm__("func_800416F4");
int Physics46Call417FCView1() __asm__("func_800417FC");
int Physics46Call41848View1() __asm__("func_80041848");
int Physics46Call41B64View2() __asm__("func_80041B64");
int Physics46InterpolateSineView2() __asm__("func_8004E9E4");
int Physics46InterpolateCosineView2() __asm__("func_8004EA2C");
int Physics46MeasureVectorLengthView2() __asm__("func_8004EDE8");
int Physics46ScaleVectorRatioQ15View2() __asm__("func_8004F08C");
int Physics46ClearVectorView1() __asm__("func_8004F168");
int Physics46CopyVectorView1() __asm__("func_8004F178");
int Physics46AddVectorView2() __asm__("func_8004F194");
int Physics46SubtractVectorView2() __asm__("func_8004F1C8");
extern short Physics46Data6E040View1 __asm__("D_8006E040");
extern int Physics46Data6E044View1 __asm__("D_8006E044");
extern int Physics46Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics46Player0View2 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics46PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics46Player94View1 __asm__("D_80070328+0x94");
extern int Physics46PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics46Player80View1 __asm__("D_80070328+0x80");
extern int Physics46PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics46Player144View1 __asm__("D_80070328+0x144");
extern int Physics46PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics46Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics46PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics46PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics46Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics46Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics46Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics46Player101View1 __asm__("D_80070328+0x101");
extern int Physics46PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics46ClearVectorView2() __asm__("func_8004F168");
extern unsigned char Physics46Player0View3 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics46Player8CView1 __asm__("D_80070328+0x8C");
extern void* (*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern int Physics46Player50View1 __asm__("D_80070328+0x50");
extern int Physics46Player250View1 __asm__("D_80070328+0x250");
int Physics46PlanarHeadingLookupView1() __asm__("func_8004E880");
void func_level_46_8008E538(int slotIndex) {
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
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74;
    } originalFrame;
    register void* globalVector80 __asm__("$16");
    register void* globalVector8CState20 __asm__("$17");
    register void* globalVector8C __asm__("$18");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    register int workWord3 __asm__("$3");
    register void* globalFieldA4Pointer __asm__("$17");
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    workWord2 = slotIndex * 16;
    globalPointer = &Physics46Data6E548View1;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics46Data6C570View1 = (void*)workWord2;
    workWord2 = Physics46Field(&Physics46Player0View1, int*, 0x54);
    stateWord3 = Physics46Field(&Physics46Player0View1, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        default:
            return;
        case 128:
            globalVector80 = &Physics46Player0View2 + 0xB8;
            workWord2 = Physics46Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero128;
            Physics46ClearVectorView1((&originalFrame.sp10));
            call4 = (&originalFrame.sp10);
            call5 = (&originalFrame.sp10);
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics46SubtractVectorView2(call4, call5, globalVector8CState20);
            originalFrame.sp18 = 0;
            call5 = (void*)Physics46MeasureVectorLengthView2((&originalFrame.sp10), 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics46ScaleVectorRatioQ15View2((&originalFrame.sp10), call5, 64);
            originalFrame.sp18 = -192;
            globalVector80 -= 56;
            Physics46AddVectorView2(globalVector80, globalVector8CState20, (&originalFrame.sp10));
            Physics46CopyVectorView1(globalVector8CState20, globalVector80);
            goto clamp128;
        zero128:
            Physics46ClearVectorView1(globalVector80 - 56);
            Physics46ClearVectorView1(globalVector80 - 44);
            goto clamp128;
        clamp128:
            globalPointer = &Physics46Player94View1;
            workWord2 = Physics46Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (workWord2) {
                workWord2 = -8960;
                Physics46Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        case 115:
        case 120:
        case 126:
            globalVector80 = &Physics46Player80View1;
            Physics46ClearVectorView1(globalVector80);
            Physics46ClearVectorView1(globalVector80 + 12);
            workWord3 = Physics46Data6E044View1;
            workWord2 = 40;
            if (workWord3 != workWord2)
                goto ordinary115;
            Physics44Slot4454();
            goto bytes115;
        ordinary115:
            workWord2 = 31;
            if (workWord3 == workWord2)
                goto bytes115;
            Physics46Call40D10View1(3840);
            Physics46Call416F4View1();
            Physics46Call41580View1(90, 16);
        bytes115:
            globalPointer = &Physics46Player1BAView1;
            workWord2 = Physics46Field(globalPointer, unsigned char*, 0);
            if (!workWord2)
                goto byteOne115;
            workWord2 = Physics46Data6E538View1 & 16;
            if (workWord2)
                return;
            workWord2 = 1;
            Physics46Field(globalPointer, unsigned char*, 0) = 0;
            Physics46Player1B9View1 = workWord2;
            return;
        byteOne115:
            workWord2 = 1;
            MATCHING_KEEP(workWord2);
            Physics46Player1B9View1 = workWord2;
            return;
        case 116:
        case 117: {
            register void* mode16 __asm__("$16");
            register int mode17 __asm__("$17");
            register int callback18 __asm__("$18");
            mode16 = &Physics46Data6E044View1;
            workWord3 = Physics46Field(mode16, int*, 0);
            mode17 = 40;
            if (workWord3 == mode17)
                goto callback131;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics46Call40D10View1(3840);
            workWord2 = Physics46Data6E538View1 & 12;
            if (workWord2)
                Physics46PlayerACView1 = 0;
            workWord2 = Physics46Call416F4View1();
            workWord3 = Physics46Field(mode16, int*, 0);
            callback18 = workWord2;
            if (workWord3 == mode17) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else {
                call4 = (void*)90;
                call5 = (void*)16;
            }
            workWord2 = Physics46Call41580View1(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics46PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics46Data6E538View1 & 12;
            if (!workWord2)
                goto reset116;
            workWord2 = Physics46Player144View1;
            workWord2++;
            Physics46Player144View1 = workWord2;
            goto saved116;
        reset116:
            Physics46Player144View1 = 0;
        saved116:
            call4 = &Physics46PlayerACView1;
            globalVector80 = (void*)Physics46Field(call4, int*, 0);
            if (callback18)
                goto collision116;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass116;
        collision116:
            workWord2 = Physics46Player20CView1 & 64;
            if (workWord2)
                Physics46Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics46PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics46Field(call4, int*, 0) = workWord3;
            }
        pass116:
            Physics46Call417FCView1(320, 192);
            workWord2 = Physics46Player101View1;
            call4 = &Physics46PlayerACView1;
            Physics46Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics46ClearVectorView1(call4 - 32);
                goto fields116;
            }
            Physics46Call41848View1(call4);
            Physics46Call41B64View2();
        fields116:
            call6 = &Physics46PlayerFCView1;
            workWord2 = Physics46Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics46PlayerB8View1;
            call4 = call6 - 112;
            if (workWord2)
                goto scalar130;
            goto vector130Input;
        }
        case 118:
            Physics46Call40D10View1(3200);
            workWord3 = Physics46Data6E044View1;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics46Call41580View1(call4, call5);
            Physics46Call417FCView1(320, 192);
            globalFieldA4Pointer = &Physics46PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics46InterpolateCosineView1(Physics46Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics46PlayerB0View1;
            agentProduct0 = workWord3 * workWord2;
            call4 = (void*)Physics46Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct0 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp20 = workWord2;
            workWord2 = Physics46InterpolateSineView1(call4);
            workWord3 = Physics46PlayerB0View1;
            agentProduct1 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.sp20;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct1 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp24 = workWord2;
            Physics46SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.sp28 = 0;
        vector118Read:
            __asm__ volatile("" ::"i"(0x8008E9A4) : "memory");
            workWord2 = Physics46MeasureVectorLengthView1(call4, call5);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            call5 = (void*)workWord2;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call5, "memory");
            workWord2 = (int)call5 < 641;
            MATCHING_KEEP(globalFieldA4Pointer);
            call4 = globalFieldA4Pointer - 36;
            if (!workWord2) {
                Physics46ScaleVectorRatioQ15View1(vectorAt40, call5, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                call4 = globalFieldA4Pointer - 36;
            }
            Physics46AddVectorView1(call4, globalVector8C, vectorAt40);
            Physics46Call41B64View1();
        gate118:
            __asm__ volatile("" ::"i"(0x8008E9E0) : "memory");
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics46Player4CView1;
            __asm__ volatile("" ::"i"(0x8008E9F8) : "memory");
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics46Data6C570View1;
            workWord2 = Physics46Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics46Player144View1;
            __asm__ volatile("" ::"i"(0x8008EA2C) : "memory");
            if (!workWord2)
                goto subtract192_130;
            __asm__ volatile("" ::"i"(0x8008EA34) : "memory");
            goto add23_130;
        case 119:
            globalFieldA4Pointer = &Physics46Player50View1;
            workWord3 = Physics46Field(globalFieldA4Pointer, int*, 0);
            workWord2 = 3;
            if (workWord3 != workWord2)
                goto airborne119;
            Physics46Call40D10View1(1600);
            Physics46Call41580View1(22, 4);
            Physics46Call417FCView1(320, 192);
            globalVector8C = globalFieldA4Pointer + 60;
            workWord2 = Physics46InterpolateCosineView1(Physics46PlayerA4View1);
            workWord3 = Physics46PlayerB0View1;
            agentProduct2 = workWord3 * workWord2;
            call4 = (void*)Physics46PlayerA4View1;
            workWord2 = agentProduct2 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp30 = workWord2;
            workWord2 = Physics46InterpolateSineView1(call4);
            workWord3 = Physics46PlayerB0View1;
            agentProduct3 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.sp30;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp34 = workWord2;
            Physics46SubtractVectorView1(call4, call5, call6);
            originalFrame.sp38 = 0;
            temp_v0_4 = Physics46MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer + 48;
            if (temp_v0_4 >= 321) {
                Physics46ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 320);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer + 48;
            }
            Physics46AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics46Call41B64View1();
            workWord2 = Physics46Player94View1;
            workWord2 -= 192;
            Physics46Player94View1 = workWord2;
            workWord2 = workWord2 < -8960;
            goto clamp119;
        airborne119:
            Physics46Call40D10View1(3200);
            workWord3 = Physics46Data6E044View1;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics46Call41580View1(call4, call5);
            Physics46Call417FCView1(320, 192);
            globalFieldA4Pointer = &Physics46PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics46InterpolateCosineView1(Physics46Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics46PlayerB0View1;
            agentProduct4 = workWord3 * workWord2;
            call4 = (void*)Physics46Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp30 = workWord2;
            workWord2 = Physics46InterpolateSineView1(call4);
            workWord3 = Physics46PlayerB0View1;
            agentProduct5 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.sp30;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct5 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp34 = workWord2;
            Physics46SubtractVectorView1(call4, call5, call6);
            call4 = vectorAt40;
            call5 = 0;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call4, call5, "memory");
            originalFrame.sp38 = 0;
            goto vector118Read;
        case 121:
            vectorAt40 = &originalFrame.sp40;
            Physics46ClearVectorView1(vectorAt40);
            call4 = vectorAt40;
            call5 = call4;
            Physics46SubtractVectorView2(call4, call5, &Physics46Player8CView1);
            workWord2 = Physics46PlayerB8View1;
            call4 = vectorAt40;
            if (!workWord2)
                goto detached121;
            originalFrame.sp48 = 0;
            workWord2 = Physics46MeasureVectorLengthView2(call4, 0);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 9;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)8;
            goto limit121;
        detached121:
            workWord2 = Physics46MeasureVectorLengthView2(call4, 1);
            call5 = (void*)workWord2;
            workWord2 = (int)call5 < 65;
            call4 = vectorAt40;
            if (workWord2)
                goto vectors121;
            call6 = (void*)64;
        limit121:
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(call4, call5, call6, "memory");
            Physics46ScaleVectorRatioQ15View2(call4, call5, call6);
        vectors121:
            globalVector80 = &Physics46Player80View1;
            call4 = globalVector80;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            globalFieldA4Pointer = globalVector80 + 12;
            call5 = globalFieldA4Pointer;
            call6 = &originalFrame.sp40;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(call5, call6, "memory");
            workWord2 = -192;
            originalFrame.sp48 = workWord2;
            Physics46AddVectorView2(call4, call5, call6);
            Physics46CopyVectorView1(globalFieldA4Pointer, globalVector80);
            workWord2 = Physics46Player94View1;
            workWord2 = workWord2 < -8960;
        clamp119:
            if (workWord2) {
                workWord2 = -8960;
                Physics46Player94View1 = workWord2;
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
            call4 = &originalFrame.sp50;
            workWord2 = Physics46Player250View1;
            child18 = Physics46Field((void*)workWord2, void**, 0);
            Physics46Call40F48View1(call4, 0);
            input16 = &Physics46Data6E040View1;
            workWord2 = Physics46InterpolateCosineView2(Physics46Field(input16, short*, 0));
            position19 = child18 + 100;
            trig17 = workWord2;
            workWord2 = Physics46InterpolateSineView2(Physics46Field(input16, short*, 0));
            workWord3 = originalFrame.sp54;
            numeric5 = workWord3 * trig17;
            workWord3 = originalFrame.sp50;
            workWord3 *= workWord2;
            call4 = (void*)Physics46Field(input16, short*, 0);
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.sp58 = workWord2;
            workWord2 = Physics46InterpolateCosineView2(call4);
            call4 = (void*)Physics46Field(input16, short*, 0);
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            secondTrig16 = workWord2;
            workWord2 = Physics46InterpolateSineView2(call4);
            workWord3 = originalFrame.sp50;
            workWord3 = -workWord3;
            numeric5 = workWord3 * secondTrig16;
            workWord3 = originalFrame.sp54;
            workWord3 *= workWord2;
            vector17 = &originalFrame.sp58;
            call4 = vector17;
            player20 = &Physics46Player0View2;
            workWord2 = numeric5 + workWord3;
            workWord2 >>= 13;
            originalFrame.sp5C = workWord2;
            workWord2 = Physics46Field(child18, int*, 100);
            workWord3 = originalFrame.sp58;
            call6 = player20;
            workWord2 += workWord3;
            Physics46Field(child18, int*, 100) = workWord2;
            workWord2 = Physics46Field(child18, int*, 104);
            workWord3 = originalFrame.sp5C;
            call5 = position19;
            workWord2 += workWord3;
            Physics46Field(child18, int*, 104) = workWord2;
            Physics46SubtractVectorView2(call4, call5, call6);
            originalFrame.sp60 = 0;
            workWord2 = Physics46MeasureVectorLengthView2(vector17, 0);
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
            Physics46ScaleVectorRatioQ15View2(call4, call5, call6);
            Physics46AddVectorView2(position19, player20, vector17);
        selector122:
            call4 = (void*)originalFrame.sp58;
            call5 = (void*)originalFrame.sp5C;
            workWord2 = Physics46PlanarHeadingLookupView1(call4, call5, 1);
            workWord3 = Physics46Data6E044View1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(workWord3, workWord2, "memory");
            Physics46PlayerA4View1 = workWord2;
            workWord2 = 40;
            call4 = (void*)24;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)4;
            Physics46Call41580View1(call4, call5);
            workWord2 = length16 < 6145;
            if (workWord2)
                goto below122;
            boundedScalar122 = (length16 - 6144) / 56 + 384;
            goto store122;
        below122:
            boundedScalar122 = 384 - ((6144 - length16) / 40);
        store122:
            MATCHING_OBSERVE_VOLATILE_CLOBBER(length16, "memory");
            Physics46Field(child18, int*, 92) = boundedScalar122;
            MATCHING_BARRIER_VOLATILE("memory");
            workWord2 = Physics46Field(child18, int*, 92);
            workWord2 = workWord2 < 256;
            if (workWord2)
                Physics46Field(child18, int*, 92) = 256;
            workWord2 = Physics46Field(child18, int*, 92);
            workWord2 = workWord2 < 513;
            if (!workWord2)
                Physics46Field(child18, int*, 92) = 512;
            call4 = (void*)Physics46Player250View1;
            Physics44Slot432C(call4);
            return;
        }
        case 124:
        case 129:
        clear30:
            globalVector80 = &Physics46Player0View3 + 0x80;
            Physics46ClearVectorView2(globalVector80);
            Physics46ClearVectorView2(globalVector80 + 0xC);
            return;
        case 130: {
            register int callback17 __asm__("$17");
            globalVector80 = &Physics46Player50View1;
            workWord3 = Physics46Field(globalVector80, int*, 0);
            workWord2 = 1;
            if (workWord3 != workWord2)
                goto airborne130;
            workWord2 = 8;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            globalVector80 = &Physics46Data6E044View1;
            MATCHING_KEEP(globalVector80);
            workWord3 = Physics46Field(globalVector80, int*, 0);
            if (workWord3 != workWord2)
                Physics46Call40D10View1(3840);
            workWord2 = Physics46Data6E538View1 & 12;
            if (workWord2)
                Physics46PlayerACView1 = 0;
            workWord2 = Physics46Call416F4View1();
            callback17 = workWord2;
            workWord3 = Physics46Field(globalVector80, int*, 0);
            workWord2 = 40;
            call4 = (void*)90;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)16;
            workWord2 = Physics46Call41580View1(call4, call5);
            workWord3 = workWord2;
            workWord2 = Physics46PlayerA8View1;
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 8;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics46Data6E538View1 & 12;
            if (!workWord2)
                goto reset130;
            workWord2 = Physics46Player144View1;
            workWord2++;
            Physics46Player144View1 = workWord2;
            goto saved130;
        reset130:
            Physics46Player144View1 = 0;
        saved130:
            call4 = &Physics46PlayerACView1;
            globalVector80 = (void*)Physics46Field(call4, int*, 0);
            if (callback17)
                goto collision130;
            workWord2 = workWord3;
            if (workWord3 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass130;
        collision130:
            workWord2 = Physics46Player20CView1 & 64;
            if (workWord2)
                Physics46Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics46PlayerB0View1;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics46Field(call4, int*, 0) = workWord3;
            }
        pass130:
            Physics46Call417FCView1(320, 192);
            workWord2 = Physics46Player101View1;
            call4 = &Physics46PlayerACView1;
            Physics46Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics46ClearVectorView1(call4 - 32);
                goto fields130;
            }
            Physics46Call41848View1(call4);
            Physics46Call41B64View2();
        fields130:
            call6 = &Physics46PlayerFCView1;
            workWord2 = Physics46Field(call6, unsigned char*, 0);
            if (workWord2)
                goto scalar130;
            workWord2 = Physics46PlayerB8View1;
            call4 = call6 - 112;
            if (!workWord2)
                goto vector130Input;
        scalar130:
            workWord2 = Physics46PlayerA0View1;
            workWord2 -= 192;
            Physics46Player94View1 = workWord2;
            return;
        vector130Input:
            __asm__ volatile("" ::"i"(0x8008F110) : "memory");
            call5 = call4;
            Physics46AddVectorView2(call4, call5, call6 - 20);
            return;
        airborne130:
            Physics46Call40D10View1(3200);
            workWord3 = Physics46Data6E044View1;
            workWord2 = 40;
            call4 = (void*)40;
            if (workWord3 == workWord2) {
                call4 = (void*)30;
                call5 = (void*)1;
            } else
                call5 = (void*)8;
            Physics46Call41580View1(call4, call5);
            Physics46Call417FCView1(320, 192);
            globalFieldA4Pointer = &Physics46PlayerA4View1;
            globalVector8C = globalFieldA4Pointer - 24;
            workWord2 =
                Physics46InterpolateCosineView1(Physics46Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics46PlayerB0View1;
            agentProduct6 = workWord3 * workWord2;
            call4 = (void*)Physics46Field(globalFieldA4Pointer, int*, 0);
            workWord2 = agentProduct6 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp68 = workWord2;
            workWord2 = Physics46InterpolateSineView1(call4);
            workWord3 = Physics46PlayerB0View1;
            agentProduct7 = workWord3 * workWord2;
            vectorAt40 = &originalFrame.sp68;
            call4 = vectorAt40;
            call5 = vectorAt40;
            call6 = globalVector8C;
            workWord2 = agentProduct7 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp6C = workWord2;
            Physics46SubtractVectorView1(call4, call5, call6);
            originalFrame.sp70 = 0;
            temp_v0_4 = Physics46MeasureVectorLengthView1(vectorAt40, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 36;
            if (temp_v0_4 >= 641) {
                Physics46ScaleVectorRatioQ15View1(vectorAt40, temp_v0_4, 640);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 36;
            }
            Physics46AddVectorView1(var_a0_3, globalVector8C, vectorAt40);
            Physics46Call41B64View1();
            workWord2 = combinedIndex < 13;
            if (!workWord2)
                goto subtract192_130;
            workWord2 = Physics46Player4CView1;
            if (workWord2)
                goto subtract192_130;
            workWord2 = (int)Physics46Data6C570View1;
            workWord2 = Physics46Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                goto add23_130;
            workWord2 = Physics46Player144View1;
            if (!workWord2)
                goto subtract192_130;
        add23_130:
            workWord2 = Physics46Player94View1;
            workWord2 += 23;
            Physics46Player94View1 = workWord2;
            return;
        subtract192_130:
            globalPointer = &Physics46Player94View1;
            workWord2 = Physics46Field(globalPointer, int*, 0);
            workWord2 -= 192;
            Physics46Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 131:
        case 132:
            goto callback131;
    }
    return;
callback131:
    __asm__ volatile("" ::"i"(0x8008F2A0) : "memory");
    Physics44Slot4454();
    return;
}
#undef Physics46Field


extern unsigned char DecodedAnimationPlayer[] __asm__("D_80070328");
extern int D_8006C648, D_8006FA38;
extern int DecodedAnimationStep __asm__("D_80070328 + 0x144");
extern int DecodedAnimationZ __asm__("D_80070328 + 8");
extern int DecodedAnimationLimitSelector __asm__("D_80070328 + 0x280");
int func_8001A358(Vector3D*, int);
extern int DecodedAnimationWordA0 __asm__("D_80070328 + 0xA0");
extern int DecodedAnimationWord4C __asm__("D_80070328 + 0x4C");
extern unsigned char DecodedAnimationByte23 __asm__("D_80070328 + 0x23");
extern unsigned char DecodedAnimationByte22 __asm__("D_80070328 + 0x22");
extern unsigned char DecodedAnimationByte21 __asm__("D_80070328 + 0x21");
extern unsigned char DecodedAnimationByte20 __asm__("D_80070328 + 0x20");
void func_80043A38(int);
extern int D_8006E538;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008F2D8..8008F5CC,190 code words plus18 dispatch words.
 * Signed-step branch reused from verified level17_80082B84; original
 * modes115..132 and all raw word gates/helper call order retained.
 * Units, input/player producers, helper semantics and cadence unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_46_8008F2D8(void) {
    Vector3D sample;
    switch (spyro.animationState) {
        case 115:
        case 120:
        case 122:
        case 123:
        case 124:
        case 126:
            if (!func_800438F4())
                func_80043728();
            func_80041C20();
            spyro.unk9a = 0;
            func_80042A44();
            goto clearWord28;
        case 128:
            func_80041C20();
            func_80042A44();
            goto clearWord28;
        case 121:
            func_80041C20();
            func_80042A44();
            goto query;
        case 129: {
            register int* zPointer __asm__("$5") = (int*)(DecodedAnimationPlayer + 8);
            register int velocity __asm__("$6") = DecodedAnimationStep;
            register int position __asm__("$2") = *zPointer;
            register int tick __asm__("$3") = D_8006C648;
            register int status __asm__("$2");
            register int increment __asm__("$4");
            MATCHING_KEEP(velocity);
            MATCHING_KEEP(position);
            MATCHING_KEEP(tick);
            increment = velocity >> 6;
            MATCHING_KEEP(increment);
            position += increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(position));
            tick <<= 9;
            *zPointer = position;
            status = DecodedAnimationLimitSelector;
            velocity += tick;
            DecodedAnimationStep = velocity;
            MATCHING_BARRIER("memory");
            if (status >= 0 && D_8006FA38 < 0)
                goto lowerLimit;
            {
                register int limit __asm__("$3") = 0x9000;
                register int exceeded __asm__("$2");
                MATCHING_KEEP(limit);
                exceeded = limit < velocity;
                if (exceeded)
                    DecodedAnimationStep = limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2") = velocity < 0x2581;
                if (!below)
                    DecodedAnimationStep = 0x2580;
            }
        limitsDone:
            func_80041C20();
            func_80042A44();
            func_8004F178(&sample, (Vector3D*)DecodedAnimationPlayer);
            sample.z += 0x400;
            spyro.unk4[0] = func_8001A358(&sample, 0xC00);
            DecodedAnimationZ -= DecodedAnimationStep >> 6;
            return;
        }
        case 118:
        case 119: {
            register int* state __asm__("$4");
            func_80041C20();
            func_80042A44();
            func_80041930();
            state = &DecodedAnimationWord4C;
            /* Retain original A0 address base; this constraint emits no code. */
            MATCHING_KEEP(state);
            if (*state == 127)
                goto clearWord28;
            if (DecodedAnimationWordA0 < 0 && spyro.animationStateFrames >= 4) {
                *state = 1;
                goto clearWord28;
            }
            goto transition;
        }
        case 130:
            if (spyro.movementState != 1)
                goto alternative;
        case 116:
        case 117:
        case 131:
        case 132:
            func_800438F4();
            func_80041C20();
            func_80042A44();
            func_80041930();
        query:
            func_80043A38(0xC00);
            goto clearWord28;
        alternative:
            func_80041C20();
            func_80042A44();
            func_80041930();
            if (DecodedAnimationWordA0 < 0 && spyro.animationStateFrames >= 4) {
                DecodedAnimationWord4C = 1;
                goto clearWord28;
            }
        transition:
            {
                int* state = &DecodedAnimationWord4C;
                if (*state == 0 && !(D_8006E538 & 0x40) && DecodedAnimationStep == 0)
                    *state = 2;
            }
        clearWord28:
            spyro.unk4[0] = 0;
            return;
    }
}

#define LEVEL_ID 46
#define PlaySpyroSounds_level_46 func_level_46_8008F5D0
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_46_8008F6F8(int index) {
    register Vector3D* position __asm__("$4");
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x76:
        case 0x77:
            MATCHING_BARRIER("memory");
            position = 0;
            break;
        case 0x82:
            position = (Vector3D*)((char*)&spyro + 0xB8);
            MATCHING_KEEP(position);
            if (position->x) {
                position = 0;
                break;
            }
        case 0x73:
        case 0x74:
        case 0x75:
        case 0x78:
        case 0x79:
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7E:
        case 0x80:
        case 0x81:
        case 0x83:
        case 0x84:
            position = &g_Spyro.unk9e;
            break;
        default:
            return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008F788 callback.
 * Reuses verified level36 transition table/copy producer. Original46 supplies
 * selectors73..84, private+5C/64/68/6C and private+74 signed halfword/+78 pointer,
 * child+48 byte writes, and original callback argument Moby+250.
 * Numeric offsets are bytes. Signed table shifts, constants and original
 * independent walk queries follow original instructions. Empty constraints
 * preserve register lifetimes/scheduling; no instruction-emitting asm.
 * Source units, helper meanings, audio semantics and update cadence unresolved.
 * Falsifiable acceptance: every original code/local jump/table word, strict
 * complete translation unit and complete EXE/every overlay hashes.
 */
extern int Raw46Movement __asm__("D_80070328+0x50");
extern int Raw46Union __asm__("D_80070328+0x144");
void Call46ED6C(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
extern void (*Call46Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw46State[] __asm__("D_80070328+0x50");
extern Spyro Callback46_D_80070328 __asm__("D_80070328");
extern short Signed46TableA[] __asm__("D_800658A0");
extern short Signed46TableB[] __asm__("D_80065920");
int Callback46MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Callback46_func_80043A38(int scale) __asm__("func_80043A38");
void Callback46_func_800441F0(void) __asm__("func_800441F0");
void Callback46ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Callback46_D_8006E524 __asm__("D_8006E524");

void func_level_46_8008F788(int arg0) {
    register Vector3D* destination __asm__("$4");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int selector __asm__("$4");
    register int groundValue __asm__("$2");
    switch (arg0) {
        case 0x73:
        case 0x78:
        case 0x7E:
            Callback46_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Callback46_D_80070328.unk5 = 0;
            Callback46_func_800441F0();
            Callback46_D_80070328.grounded = 1;
            return;
        case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            walkBase = Raw46State;
            walkFlag = 1;
            MATCHING_KEEP(walkFlag);
            selector = arg0;
            MATCHING_KEEP(selector);
            *(int*)walkBase = walkFlag;
            if (selector == 0x57 && Callback46_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                MATCHING_BARRIER_VOLATILE("memory");
                destination = (Vector3D*)(walkBase + 0x3C);
                goto copyWalkVector;
            }
            goto clearWalkFlag;
        case 0x80:
            Callback46_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Callback46_D_80070328.unk5 = 0;
            Callback46_func_80043A38(0xC00);
            Callback46_D_80070328.grounded = 1;
            Callback46_D_8006E524 = 0xF;
            return;
        case 0x81: {
            register int oldState __asm__("$3") = Raw46Movement;
            register void (*callback)(int, int, Vector3D*, Vector3D*) __asm__("$8") = SpawnParticle;
            register int* stateWord __asm__("$2");
            register int value __asm__("$2");
            MATCHING_KEEP2_VOLATILE_CLOBBER(oldState, callback, "memory");
            value = 7;
            MATCHING_KEEP(value);
            Raw46Movement = value;
            value = 1;
            MATCHING_KEEP(value);
            Callback46_D_80070328.grounded = value;
            value = 15;
            MATCHING_KEEP(value);
            Callback46_D_8006E524 = value;
            Callback46_D_80070328.unk5 = 0;
            stateWord = &Raw46Union;
            MATCHING_KEEP(stateWord);
            Callback46_D_80070328.unk5 = 0;
            *stateWord = oldState;
            MATCHING_BARRIER_VOLATILE("memory");
            *stateWord = 0;
            if (callback)
                callback(5, 10, 0, 0);
            Callback46_D_80070328.unk22[2] = PlaySound((int)D_8006C654->drown, 0, 0);
            Callback46_D_80070328.unk22[3] = (int)D_8006C654->drown;
            return;
        }
        case 0x79:
            Callback46_D_80070328.movementState = MOVEMENT_STATE_HURT;
            Callback46_D_80070328.unk5 = 0;
            if (Callback46_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Callback46_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed46TableB + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                tableValueA >>= 1;
                Callback46_D_80070328.unk7a[2].x = tableValueA;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed46TableA + tableOffsetOrValue);
                Callback46_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Callback46_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else {
                Callback46ClearVector(
                    (Vector3D*)((unsigned char*)&Callback46_D_80070328.movementState + 0x3C));
            }
            Callback46_D_80070328.unk7a[2].z = 0x200;
            func_8004F178((Vector3D*)((unsigned char*)&Callback46_D_80070328.unk7a[2].z - 0x14),
                          (Vector3D*)((unsigned char*)&Callback46_D_80070328.unk7a[2].z - 8));
            Callback46_D_80070328.grounded = 1;
            Callback46_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
                return;
            }
        default:
            return;
        case 0x7A: {
            register unsigned char* privateData __asm__("$17") =
                Callback46_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* state __asm__("$18") = Raw46State;
            register Vector3D* vector __asm__("$16");
            *(int*)state = 0;
            Callback46_D_80070328.unk5 = 0;
            vector = (Vector3D*)(privateData + 0x64);
            Callback46_func_800441F0();
            Callback46_D_80070328.grounded = 1;
            Callback46_D_80070328.idle = 0;
            Callback46_D_80070328.unk15g = 0;
            *(int*)(privateData + 0x5C) = 0x180;
            *(int*)(privateData + 0x64) = 0x1800;
            *(int*)(privateData + 0x68) = 0;
            *(int*)(privateData + 0x6C) = 0;
            Call46ED6C((Vector3D*)(state - 0x20), vector, vector);
            func_8004F194(vector, vector, (Vector3D*)(state - 0x50));
            Call46Header(Callback46_D_80070328.critterMobyPtr);
            return;
        }
        case 0x7B:
            Callback46_D_80070328.movementState = 0;
            Callback46_func_800441F0();
            groundValue = 1;
            goto sharedGround;
        case 0x7C: {
            register unsigned char* privateData __asm__("$16") =
                Callback46_D_80070328.critterMobyPtr->mobyTag;
            register unsigned char* child __asm__("$4");
            Callback46_D_80070328.movementState = 0;
            Callback46_func_800441F0();
            Callback46_D_80070328.grounded = 1;
            Callback46_D_80070328.idle = 0;
            Callback46_D_80070328.unk15g = 0;
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
            stateBaseA = Raw46State;
            MATCHING_KEEP(stateBaseA);
            destination = (Vector3D*)(stateBaseA + 0x3C);
            MATCHING_KEEP(destination);
            sourceBytesA = stateBaseA + 0x48;
            *(int*)stateBaseA = 2;
            func_8004F178(destination, (Vector3D*)sourceBytesA);
            Callback46_D_80070328.unk8[0] =
                Callback46MeasureVectorLength((Vector3D*)sourceBytesA, 0);
            Callback46_D_80070328.unk7a[2].z = 0xDC0;
            Callback46_D_80070328.unk5 = 0;
            if (Callback46_D_80070328.animationState == 0x81)
                Callback46_D_80070328.union144.a.unk13cb = 1;
            else
                Callback46_D_80070328.union144.a.unk13cb = 0;
            Callback46_D_80070328.grounded = 0;
            PlaySound((int)D_8006C654->jump, 0, 0);
            return;
        case 0x77: {
            register unsigned char* state __asm__("$6") = Raw46State;
            if (*(int*)state != 2) {
                *(int*)state = 3;
                Callback46_D_80070328.unk8[0] =
                    Callback46MeasureVectorLength((Vector3D*)(state + 0x48), 0);
                Callback46_D_80070328.grounded = 0;
                Callback46_D_80070328.unk15b = 1;
                goto clearTail;
            }
            return;
        }
        case 0x82: {
            walkBase = Raw46State;
            if (*(int*)walkBase != 2) {
                walkFlag = 1;
                MATCHING_KEEP(walkFlag);
                *(int*)walkBase = walkFlag;
                if (arg0 == 0x57 && Callback46_D_80070328.ticksSinceLastSurfaceTouch != 0) {
                    destination = (Vector3D*)(walkBase + 0x3C);
                copyWalkVector:
                    func_8004F178(destination, (Vector3D*)(walkBase + 0x48));
                    Callback46_D_80070328.unk5 = walkFlag;
                } else {
                clearWalkFlag:
                    Callback46_D_80070328.unk5 = 0;
                }
                Callback46_D_80070328.unk8[0] = Callback46MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Callback46_D_80070328.movementState + 0x48), 0);
                Callback46_func_80043A38(0xC00);
                groundValue = 1;
                MATCHING_KEEP(groundValue);
                Callback46_D_80070328.union144.a.unk13cb = 0;
            sharedGround:
                Callback46_D_80070328.grounded = groundValue;
            clearTail:
                Callback46_D_80070328.idle = 0;
                Callback46_D_80070328.unk15g = 0;
            }
            return;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008FC9C.
 * Assembly SHA256 087fb8d9b607b9a555ee7f4e148e7767fecc84006cc535620ee56c0d0504f5ec.
 * AI-generated; not human reviewed. All1082 original instructions and
 * 18 selectors bias115 are required. Original frame18 saves S0 and RA.
 * All17 physical state groups reuse verified30/33 Agent9 state C with exact
 * original address maps. All callback/input/counter/sound/effect/private
 * fields, selector priorities, helper ownership and actual joins remain
 * original. Original119 saves/restores word54 around the shared helper.
 * Distinct typed aliases are preserved. Initialized empty constraints and
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Identified Rev1 Agent9 state/table and snapshot-writer decoders guide
 * interpretation; Rev0 instructions, targets and full hashes rule.
 * Units/fixed point, full helper contracts and caller rate remain unknown.
 * Cadence is per invocation. Falsification: all native/linked instructions,
 * actual targets/selectors/data and full EXE/every-overlay retail hashes.
 * Binary identity does not establish synchronized runtime completeness. */
extern int Anim46Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim46Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim46Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim46PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim46PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim46PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim46PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim46PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim46PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim46PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim46Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim46Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim46Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim46PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern unsigned char Anim46Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim46Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern int Anim46Data6E538View1 __asm__("D_8006E538"), Anim46Data6E53CView1 __asm__("D_8006E53C");
int Anim46Call4BEF8View1() __asm__("func_8004BEF8");
extern int Anim46PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim46PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim46Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim46Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim46PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim46Data6E538View2 __asm__("D_8006E538"), Anim46Data6E53CView2 __asm__("D_8006E53C");
extern int Anim46Data6E044View1 __asm__("D_8006E044"), A21Gate __asm__("D_8006E344"),
    A21Count __asm__("D_8006C514");
extern int (*Anim46Data74374View1)() __asm__("unk_ovlheader_80074374");
extern volatile int Anim46Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim46Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim46Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim46Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim46Data6EE2CView1 __asm__("D_8006EE2C");
extern int Anim46Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim46Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim46Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim46Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim46Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim46Player90View2 __asm__("D_80070328 + 0x90");
extern int Anim46Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim46PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim46PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim46PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim46PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim46PlayerCCView2 __asm__("D_80070328 + 0xCC");
extern int Anim46PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim46PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim46PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim46Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim46Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char* Anim46Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim46Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim46Data6E535View2 __asm__("D_8006E535");
extern int Anim46Data6E538View3 __asm__("D_8006E538");
extern int Anim46Data6E53CView3 __asm__("D_8006E53C");
extern int Anim46Data6E530View1 __asm__("D_8006E530");
extern int Anim46Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char* Anim46Data6C654View1 __asm__("D_8006C654");
extern int (*Anim46Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim46DataSpawnParticleView1)(int, int, void*, int) __asm__("SpawnParticle");
int Anim46Call55E84View1(void*) __asm__("func_80055E84");
int Anim46Call4BEF8View3(int) __asm__("func_8004BEF8");
int Anim46CallPlaySoundView1(unsigned char, int, int) __asm__("PlaySound");
extern int Anim46PlayerB4View2 __asm__("D_80070328 + 0xB4");
extern int Anim46Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim46Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim46Data6E044View2 __asm__("D_8006E044");
int Anim46Call498C0View1(void*) __asm__("func_800498C0");
int Anim46Call3BF6CView1(int, int) __asm__("func_8003BF6C");
int Anim46Call3BE70View1(int) __asm__("func_8003BE70");
#define Anim46Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_level_46_8008FC9C(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int savedWord16 __asm__("$16");
    rawValue2 = Anim46Player48View1;
    switch (rawValue2) {
        case 115:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne115;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground115;
        airborne115:
            __asm__ volatile("" ::"i"(0x8008FD2C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground115:
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input115;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input115:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim46Data6E044View2;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim46Data6E044View2;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim46PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46PlayerACView2;
            if (rawValue2)
                goto select;
            rawValue2 = 25;
            rawValue3 = Anim46Field(record16, int*, 0x4C);
            nextSelector4 = 126;
            if (rawValue3 != rawValue2)
                return;
            goto select;
        case 116:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne116;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground116;
        airborne116:
            __asm__ volatile("" ::"i"(0x8008FE68) : "memory");
            nextSelector4 = 119;
            goto select;
        ground116:
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload116;
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload116:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input116;
            rawValue2 = Anim46Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input116:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8008FF00) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim46Data6E535View2;
            if (!rawValue2)
                goto afterLatch116;
            rawValue2 = Anim46PlayerB0View3;
            if (!rawValue2)
                goto latch116;
            rawValue2 = 40;
            rawValue3 = Anim46Data6E044View2;
            if (rawValue3 != rawValue2)
                goto afterLatch116;
        latch116:
            __asm__ volatile("" ::"i"(0x8008FF4C) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch116:
            rawValue2 = Anim46PlayerB4View2 < 3073;
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Call55E84View1((void*)nextSelector4);
            rawValue2 = rawValue2 < 37;
            nextSelector4 = 117;
            if (rawValue2)
                return;
            goto select;
        case 117:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne117;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground117;
        airborne117:
            __asm__ volatile("" ::"i"(0x8008FFE4) : "memory");
            nextSelector4 = 119;
            goto select;
        ground117:
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload117;
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload117:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input117;
            rawValue2 = Anim46Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input117:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009007C) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim46Data6E535View2;
            if (!rawValue2)
                goto afterLatch117;
            rawValue2 = Anim46PlayerB0View3;
            if (!rawValue2)
                goto latch117;
            rawValue2 = 40;
            rawValue3 = Anim46Data6E044View2;
            if (rawValue3 != rawValue2)
                goto afterLatch117;
        latch117:
            __asm__ volatile("" ::"i"(0x800900C8) : "memory");
            nextSelector4 = 115;
            goto select;
        afterLatch117:
            rawValue2 = Anim46PlayerB4View2 < 2560;
            if (!rawValue2)
                return;
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009011C) : "memory");
            goto select;
        case 118:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim46Player54View3 < 16;
            if (rawValue2)
                goto private118;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue3 = Anim46PlayerCCView2;
            rawValue2 = Anim46Player8CView2;
            product5 = rawValue3 * rawValue2;
            rawValue3 = Anim46PlayerD0View2;
            rawValue2 = Anim46Player90View2;
            nextSelector4 = rawValue3 * rawValue2;
            rawValue3 = Anim46PlayerD4View2;
            rawValue2 = Anim46Player94View2;
            rawValue3 *= rawValue2;
            rawValue2 = product5 + nextSelector4;
            rawValue2 += rawValue3;
            if (rawValue2 >= 0)
                return;
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x8009020C) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim46PlayerACView2;
            nextSelector4 = 120;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x80090248) : "memory");
            nextSelector4 = 117;
            goto select;
        private118:
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto finish118;
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        finish118:
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x800902BC) : "memory");
            goto preserveAge;
        case 119:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2;
            rawValue3 = 2;
            if (rawValue2)
                goto other119;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (!rawValue2)
                return;
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x80090330) : "memory");
                nextSelector4 = 131;
                goto effect119;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto effect119;
            rawValue2 = Anim46PlayerACView2;
            if (rawValue2)
                goto distance119;
            nextSelector4 = 120;
            goto effect119;
        distance119:
            rawValue2 = Anim46PlayerB4View2 < 3073;
            nextSelector4 = 116;
            if (rawValue2)
                goto effect119;
            nextSelector4 = 117;
        effect119:
            Anim46Call4BEF8View3(nextSelector4);
            {
                register int (*spawn2)(int, int, void*, int) __asm__("$2") =
                    Anim46DataSpawnParticleView1;
                if (spawn2)
                    spawn2(8, 33, 0, 2);
            }
            rawValue2 = (int)Anim46Data6C654View1;
            product5 = 0;
            nextSelector4 = Anim46Field((void*)rawValue2, unsigned char*, 0x12);
            Anim46CallPlaySoundView1((unsigned char)nextSelector4, product5, 0);
            rawValue2 = Anim46Player58View1 < 24;
            if (rawValue2)
                return;
            rawValue2 = 120;
            Anim46Data6E530View1 = rawValue2;
            rawValue2 = 15;
            Anim46Data6E52CView1 = rawValue2;
            return;
        other119:
            rawValue2 = 2;
            rawValue3 = Anim46Player50View1;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                return;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            if (!rawValue2)
                return;
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 130;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x8009043C) : "memory");
            goto select;
        case 120:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46PlayerB8View2 < 4;
            nextSelector4 = 119;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input120;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input120:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2) {
                __asm__ volatile("" ::"i"(0x800904EC) : "memory");
                nextSelector4 = 131;
                goto select;
            }
            rawValue2 = 4;
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim46Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Data6E53CView3 & 32;
            nextSelector4 = 115;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009055C) : "memory");
            goto select;
        case 121:
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto done121;
        done121:
            rawValue2 = Anim46Player280View1;
            if (rawValue2 < 0) {
                nextSelector4 = 128;
                goto select;
            }
            rawValue2 = Anim46PlayerB8View2;
            nextSelector4 = 115;
            if (!rawValue2)
                goto select;
            nextSelector4 = 119;
            goto select;
        case 122:
            rawValue2 = Anim46Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne122;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground122;
        airborne122:
            __asm__ volatile("" ::"i"(0x8009061C) : "memory");
            nextSelector4 = 119;
            goto select;
        ground122:
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 123;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x80090658) : "memory");
            goto select;
        case 123:
            rawValue2 = Anim46Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne123;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground123;
        airborne123:
            __asm__ volatile("" ::"i"(0x800906AC) : "memory");
            nextSelector4 = 119;
            goto select;
        ground123:
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 124;
            if (rawValue2)
                return;
            __asm__ volatile("" ::"i"(0x800906CC) : "memory");
            goto select;
        case 124:
            rawValue2 = Anim46Data7431CView1(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne124;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground124;
        airborne124:
            __asm__ volatile("" ::"i"(0x80090720) : "memory");
            nextSelector4 = 119;
            goto select;
        ground124:
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x8009075C) : "memory");
            goto select;
        case 126:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne126;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground126;
        airborne126:
            __asm__ volatile("" ::"i"(0x800907B8) : "memory");
            nextSelector4 = 119;
            goto select;
        ground126:
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input126;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            nextSelector4 = 122;
            if (rawValue2)
                goto select;
        input126:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = 8;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim46Data6E044View2;
                nextSelector4 = 131;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = 4;
            rawValue2 &= 15;
            if (rawValue2 == rawValue3) {
                rawValue2 = 31;
                rawValue3 = Anim46Data6E044View2;
                nextSelector4 = 132;
                if (rawValue3 != rawValue2)
                    goto select;
            }
            rawValue2 = Anim46PlayerA8View1;
            if (rawValue2 < 0)
                rawValue2 = -rawValue2;
            rawValue2 = rawValue2 < 17;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46PlayerACView2;
            if (rawValue2)
                goto select;
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 115;
            if (!rawValue2) {
                return;
            }
            __asm__ volatile("" ::"i"(0x800908BC) : "memory");
            goto select;
        case 128:
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                return;
            }
            goto helper128;
        call498C0:
        helper128:
            Anim46Call498C0View1((void*)nextSelector4);
            return;
        case 129:
            rawValue2 = Anim46Data6E53CView3 & 64;
            if (rawValue2) {
                rawValue2 = 1;
                Anim46Player1B6View2 = rawValue2;
            }
            nextSelector4 = (int)&Anim46Player280View1;
            rawValue2 = *(int*)nextSelector4;
            if (rawValue2 < 0) {
                rawValue2 = 36863;
                rawValue3 = Anim46Player144View1;
                rawValue2 = rawValue2 < rawValue3;
                if (!rawValue2)
                    return;
                rawValue2 = -1;
                Anim46Player28CView1 = rawValue2;
                Anim46Call498C0View1((void*)nextSelector4);
                return;
            }
            rawValue3 = Anim46Player54View3;
            rawValue2 = rawValue3 < 61;
            if (!rawValue2) {
                rawValue2 = -1;
                *(int*)nextSelector4 = rawValue2;
                return;
            }
            rawValue2 = rawValue3 < 16;
            if (rawValue2)
                return;
            rawValue2 = Anim46Player1B6View2;
            if (!rawValue2)
                return;
            product5 = Anim46Player28CView1;
            nextSelector4 = 118;
            if (product5 < 0)
                goto select;
            nextSelector4 = Anim46Player290View1;
            rawValue2 = Anim46Call3BF6CView1(nextSelector4, product5);
            if (rawValue2) {
                nextSelector4 = Anim46Player28CView1;
                Anim46Call3BE70View1(nextSelector4);
            }
            rawValue2 = -1;
            Anim46Player28CView1 = rawValue2;
            nextSelector4 = 118;
            goto select;
        case 130:
            rawValue2 = Anim46Data7431CView1(1);
            if (rawValue2)
                return;
            nextSelector4 = (int)Anim46Player250View1;
            rawValue2 = Anim46Player48View2;
            rawValue3 = Anim46Field((void*)nextSelector4, unsigned char*, 0x3C);
            rawValue2 -= 115;
            if (rawValue3 != rawValue2)
                goto other130;
            rawValue2 = Anim46Field((void*)nextSelector4, unsigned char*, 0x42) & 2;
            if (!rawValue2) {
                goto other130;
            }
            goto completed130;
        completed130:
            rawValue2 = Anim46PlayerB8View2;
            if (rawValue2)
                goto preserveAge;
            rawValue2 = Anim46Data6E535View2;
            if (rawValue2)
                goto latch130;
            rawValue2 = Anim46PlayerB4View2 < 2560;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 116;
            if (rawValue2)
                goto select;
            __asm__ volatile("" ::"i"(0x80090A90) : "memory");
            nextSelector4 = 117;
            goto select;
        latch130:
            __asm__ volatile("" ::"i"(0x80090A98) : "memory");
            nextSelector4 = 115;
            goto select;
        preserveAge:
            savedWord16 = Anim46Player54View3;
            Anim46Call4BEF8View3(119);
            Anim46Player54View3 = savedWord16;
            return;
        other130:
            nextSelector4 = (int)&Anim46Player50View1;
            rawValue3 = *(int*)nextSelector4;
            rawValue2 = 2;
            if (rawValue3 != rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2;
            if (rawValue2)
                return;
            rawValue2 = 1;
            *(int*)nextSelector4 = rawValue2;
            goto select116;
        case 131:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne131;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground131;
        airborne131:
            __asm__ volatile("" ::"i"(0x80090B48) : "memory");
            nextSelector4 = 119;
            goto select;
        ground131:
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload131;
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload131:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input131;
            rawValue2 = Anim46Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input131:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 8;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 4;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 132;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim46Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46PlayerB0View3;
            if (!rawValue2)
                goto latch131;
            rawValue2 = 40;
            rawValue3 = Anim46Data6E044View2;
            if (rawValue3 != rawValue2)
                goto select;
        latch131:
            __asm__ volatile("" ::"i"(0x80090C24) : "memory");
            nextSelector4 = 115;
            goto select;
        case 132:
            rawValue2 = (int)Anim46Player250View1;
            callback3 = Anim46Data7431CView1;
            record16 = Anim46Field((void*)rawValue2, unsigned char**, 0);
            rawValue2 = callback3(1);
            if (rawValue2)
                return;
            rawValue2 = Anim46PlayerB8View2 < 4;
            if (!rawValue2)
                goto airborne132;
            rawValue2 = Anim46PlayerE4View2 < 23;
            if (rawValue2)
                goto ground132;
        airborne132:
            __asm__ volatile("" ::"i"(0x80090C80) : "memory");
            nextSelector4 = 119;
            goto select;
        ground132:
            rawValue2 = Anim46Data6E53CView3 & 64;
            nextSelector4 = 118;
            if (rawValue2)
                goto select;
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim46Field(record16, int*, 0x7C);
            if (!rawValue2)
                goto reload132;
            rawValue2 = Anim46Data6E538View3 & 128;
            nextSelector4 = 130;
            if (!rawValue2)
                goto select;
        reload132:
            MATCHING_BARRIER_VOLATILE("memory");
            rawValue2 = Anim46Field(record16, int*, 0x78);
            if (!rawValue2)
                goto input132;
            rawValue2 = Anim46Field(record16, int*, 0x7C) < 12;
            nextSelector4 = 122;
            if (!rawValue2)
                goto select;
        input132:
            rawValue2 = Anim46Data6E538View3;
            rawValue3 = rawValue2 & 15;
            rawValue2 = 4;
            if (rawValue3 == rawValue2)
                return;
            rawValue2 = 8;
            __asm__ volatile("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
            nextSelector4 = 131;
            if (rawValue3 == rawValue2)
                goto select;
            rawValue2 = Anim46Data6E535View2;
            nextSelector4 = 116;
            if (!rawValue2)
                goto select;
            rawValue2 = Anim46PlayerB0View3;
            if (!rawValue2)
                goto latch132;
            rawValue2 = 40;
            rawValue3 = Anim46Data6E044View2;
            if (rawValue3 != rawValue2)
                goto select;
        latch132:
            __asm__ volatile("" ::"i"(0x80090D5C) : "memory");
            nextSelector4 = 115;
            goto select;
        default:
            return;
    }
select116:
    nextSelector4 = 116;
select:
    Anim46Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim46Field
