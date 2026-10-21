#include "matching.h"
#include "common.h"
#include "camera.h"
#include "hud.h"
#include "drawutil.h"
#include "spu.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_27/animation/func_level_27_80088028.s SHA256 420d3f859a7b47de023598c24e25e1fb27c539b5e2a9a1f0c910d06583272747. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller88028_func_800363DC() __asm__("func_800363DC");                       /* extern */
unsigned char Controller88028_func_80040D10() __asm__("func_80040D10");             /* extern */
unsigned char Controller88028_func_80041580() __asm__("func_80041580");             /* extern */
unsigned char Controller88028_func_800416F4() __asm__("func_800416F4");             /* extern */
unsigned char Controller88028_func_800417FC() __asm__("func_800417FC");             /* extern */
unsigned char Controller88028_func_80041B64() __asm__("func_80041B64");             /* extern */
int Controller88028InterpolateSine() __asm__("func_8004E9E4");                      /* extern */
int Controller88028InterpolateCosine() __asm__("func_8004EA2C");                    /* extern */
unsigned char Controller88028TransformVectorByBasis() __asm__("func_8004ED6C");     /* extern */
int Controller88028MeasureVectorLength() __asm__("func_8004EDE8");                  /* extern */
unsigned char Controller88028ScaleVectorRatioQ15() __asm__("func_8004F08C");        /* extern */
unsigned char Controller88028ShiftVectorRightTowardZero() __asm__("func_8004F110"); /* extern */
unsigned char Controller88028ClearVector() __asm__("func_8004F168");                /* extern */
unsigned char Controller88028CopyVector() __asm__("func_8004F178");                 /* extern */
unsigned char Controller88028AddVector() __asm__("func_8004F194");                  /* extern */
unsigned char Controller88028SubtractVector() __asm__("func_8004F1C8");             /* extern */
int Controller88028_rand() __asm__("rand");                                         /* extern */
extern unsigned char Controller88028_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller88028_D_80065920 __asm__("D_80065920");
extern void* Controller88028_D_8006C570 __asm__("D_8006C570");
extern int Controller88028_D_8006C640 __asm__("D_8006C640");
extern int Controller88028_D_8006E044 __asm__("D_8006E044");
extern unsigned char Controller88028_D_8006E548 __asm__("D_8006E548");
extern unsigned char Controller88028_D_80070328 __asm__("D_80070328");
/* Exact raw symbol alias prevents reuse of a different field address. */
extern int Controller88028_globalField94 __asm__("D_80070328 + 0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");

void func_level_27_80088028(int slotIndex) {
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void* vectorAt40 __asm__("$16");
    register void* vectorAt30 __asm__("$17");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    register int below19 __asm__("$2");
    register int rawProduct __asm__("$9");
    register void* globalPointer __asm__("$3");
    /* Original vectors occupy0x10..0x6C; saved registers begin at0x70. */
    struct {
        int sp10, sp14, sp18, pad1C, sp20, sp24, sp28, pad2C, sp30, sp34, sp38, pad3C, sp40, sp44,
            sp48, pad4C, sp50, sp54, sp58, pad5C, sp60, sp64, sp68, pad6C;
    } originalFrame;

    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState9 __asm__("$17");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$19");
    register void* var_a0 __asm__("$4");
    register void* var_a0_2 __asm__("$4");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$18");
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalField4CPointer __asm__("$16");
    register void* globalFieldB8PointerState1A __asm__("$16");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    void* temp_v0_7;

    workWord2 = slotIndex * 16;
    globalPointer = &Controller88028_D_8006E548;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Controller88028_D_8006C570 = (void*)workWord2;
    workWord2 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x54);
    stateWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        case 0x14:
        case 0x35:
        case 0x36:
            globalVector80 = &Controller88028_D_80070328 + 0x80;
            Controller88028ClearVector(globalVector80);
            Controller88028ClearVector(globalVector80 + 0xC);
            if (Controller88028_D_8006E044 != 7) {
                Controller88028_func_80040D10(0x1200);
                Controller88028_func_800416F4();
                Controller88028_func_80041580(0x5A, 0x10);
                return;
            }
        default:
            return;
        case 0x9:
            globalField4CPointer = &Controller88028_D_80070328 + 0x4C;
            workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x4C);
            MATCHING_KEEP(workWord3);
            workWord2 = 1;
            if (workWord3 == workWord2) {
                Controller88028_func_80040D10(0xC80);
                Controller88028_func_80041580(0x28, 8);
                Controller88028_func_800417FC(0x140, 0xC0);
                globalVector8CState9 = globalField4CPointer + 0x40;
                workWord2 = Controller88028InterpolateCosine(
                    M2C_FIELD(&Controller88028_D_80070328, int*, 0xA4));
                workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0xB0);
                rawProduct = workWord3 * workWord2;
                workWord2 = rawProduct >> 12;
                MATCHING_KEEP(workWord2);
                originalFrame.sp10 = workWord2;
                workWord2 = Controller88028InterpolateSine(
                    M2C_FIELD(&Controller88028_D_80070328, int*, 0xA4));
                workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0xB0);
                rawProduct = workWord3 * workWord2;
                workWord2 = rawProduct >> 12;
                MATCHING_KEEP(workWord2);
                originalFrame.sp14 = workWord2;
                Controller88028SubtractVector(&originalFrame.sp10, &originalFrame.sp10,
                                              globalVector8CState9);
                originalFrame.sp18 = 0;
                temp_v0 = Controller88028MeasureVectorLength(&originalFrame.sp10, 0);
                MATCHING_KEEP(globalField4CPointer);
                var_a0 = globalField4CPointer + 0x34;

                if (temp_v0 >= 0x281) {
                    Controller88028ScaleVectorRatioQ15(&originalFrame.sp10, temp_v0, 0x280);
                    MATCHING_KEEP(globalField4CPointer);
                    var_a0 = globalField4CPointer + 0x34;
                }
                Controller88028AddVector(var_a0, globalVector8CState9, &originalFrame.sp10);
                Controller88028_func_80041B64();
                if (combinedIndex < 0xD) {
                    MATCHING_OBSERVE(combinedIndex);
                    M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) =
                        (int)(M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) + 0x17);
                    return;
                }
                M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) =
                    (int)(M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) - 0xC0);
                return;
            }
            below19 = combinedIndex < 19;
            MATCHING_KEEP(globalField4CPointer);
            var_a0_2 = globalField4CPointer + 0x40;

            if (!below19) {
                MATCHING_OBSERVE(combinedIndex);
                call4 = globalField4CPointer + 0x34;
                MATCHING_KEEP(call4);
                workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x8C);
                workWord2 = workWord3 * 7;
                workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x90);
                M2C_FIELD(globalField4CPointer, int*, 0x34) = workWord2 << 5;
                workWord2 = workWord3 * 7;
                workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x94);
                M2C_FIELD(&Controller88028_D_80070328, int*, 0x84) = workWord2 << 5;
                M2C_FIELD(&Controller88028_D_80070328, int*, 0x88) = (workWord3 * 7) << 5;
                Controller88028ShiftVectorRightTowardZero(call4, 8);
                MATCHING_KEEP(globalField4CPointer);
                var_a0_2 = globalField4CPointer + 0x40;
            }
            Controller88028CopyVector(var_a0_2, globalField4CPointer + 0x34);
            temp_v0_2 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) - 0xC0;
            M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) = temp_v0_2;
            if (temp_v0_2 < -0x2300) {
                M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) = -0x2300;
                return;
            }
            break;
        case 0x1A:
            globalFieldB8PointerState1A = &Controller88028_D_80070328 + 0xB8;
            if (M2C_FIELD(&Controller88028_D_80070328, int*, 0xB8) != 0) {
                temp_v0_3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) - 0x600;
                M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) = temp_v0_3;
                if (temp_v0_3 < -0x2300) {
                    M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) = -0x2300;
                }
                Controller88028CopyVector(globalFieldB8PointerState1A - 0x38,
                                          globalFieldB8PointerState1A - 0x2C);
                return;
            }
            Controller88028ClearVector(globalFieldB8PointerState1A - 0x38);
            Controller88028ClearVector(globalFieldB8PointerState1A - 0x2C);
            return;
        case 0x1C:
            Controller88028_func_80040D10(0xC80);
            Controller88028_func_80041580(0x28, 8);
            Controller88028_func_800417FC(0x140, 0xC0);
            globalFieldA4Pointer = &Controller88028_D_80070328 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 = Controller88028InterpolateCosine(M2C_FIELD(globalFieldA4Pointer, int*, 0));
            workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0xB0);
            rawProduct = workWord3 * workWord2;
            call4 = (void*)M2C_FIELD(globalFieldA4Pointer, int*, 0);
            workWord2 = rawProduct >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp20 = workWord2;
            workWord2 = Controller88028InterpolateSine(call4);
            workWord3 = M2C_FIELD(&Controller88028_D_80070328, int*, 0xB0);
            rawProduct = workWord3 * workWord2;
            workWord2 = rawProduct >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp24 = workWord2;
            Controller88028SubtractVector(&originalFrame.sp20, &originalFrame.sp20, globalVector8C);
            originalFrame.sp28 = 0;
            temp_v0_4 = Controller88028MeasureVectorLength(&originalFrame.sp20, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;

            if (temp_v0_4 >= 0x281) {
                Controller88028ScaleVectorRatioQ15(&originalFrame.sp20, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Controller88028AddVector(var_a0_3, globalVector8C, &originalFrame.sp20);
            Controller88028_func_80041B64();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) + 0x17;
            } else {
                nextField94 = M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) - 0xC0;
            }
            Controller88028_globalField94 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Controller88028_D_80070328 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (M2C_FIELD(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp40;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Controller88028_rand() & 0xFF)) {
                        workWord2 = Controller88028_func_800363DC(0, 0xC);
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
                        signedTableWord = *(short*)(&Controller88028_D_80065920 + workWord3);
                        call6 = vectorAt40;

                        originalFrame.sp30 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Controller88028_D_800658A0 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp38 = 0xE;
                        originalFrame.sp40 = -0x12C;
                        originalFrame.sp44 = 0;
                        originalFrame.sp48 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp34 = (workWord3 * 5) >> 0xA;
                        Controller88028TransformVectorByBasis(call4, call5, call6, signedTableWord);
                        originalFrame.sp40 += Controller88028_func_800363DC(0, 0x50);
                        originalFrame.sp44 += Controller88028_func_800363DC(0, 0x50);
                        originalFrame.sp48 += Controller88028_func_800363DC(0, 0x50);
                        Controller88028AddVector(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp30);
                        M2C_FIELD(temp_v0_5, signed char*, 2) = 8;
                        M2C_FIELD(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 0x20:
        case 0x3A:
            globalFieldB8PointerState20 = &Controller88028_D_80070328 + 0xB8;
            if (M2C_FIELD(&Controller88028_D_80070328, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp30;
                Controller88028ClearVector(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Controller88028SubtractVector(call4, call5, globalVector8CState20);
                originalFrame.sp38 = 0;
                temp_v0_6 = Controller88028MeasureVectorLength(&originalFrame.sp30, 0);
                if (temp_v0_6 >= 0x41) {
                    Controller88028ScaleVectorRatioQ15(&originalFrame.sp30, temp_v0_6, 0x40);
                }
                originalFrame.sp38 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Controller88028AddVector(globalVector80State20, globalVector8CState20,
                                         &originalFrame.sp30);
                Controller88028CopyVector(globalVector8CState20, globalVector80State20);
            } else {
                Controller88028ClearVector(globalFieldB8PointerState20 - 0x38);
                Controller88028ClearVector(globalFieldB8PointerState20 - 0x2C);
            }
            if (M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) < -0x2300) {
                M2C_FIELD(&Controller88028_D_80070328, int*, 0x94) = -0x2300;
            }
            if ((M2C_FIELD(&Controller88028_D_80070328, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Controller88028_D_8006C640 & 1)) {
                originalFrame.sp50 = 0;
                originalFrame.sp54 = 0;
                originalFrame.sp58 = 0xE;
                Controller88028CopyVector(&originalFrame.sp60,
                                          (&Controller88028_D_80070328 + 0x94) - 0x94);
                originalFrame.sp60 += Controller88028_func_800363DC(0, 0x12C);
                originalFrame.sp64 += Controller88028_func_800363DC(0, 0x12C);
                originalFrame.sp68 += Controller88028_func_800363DC(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp60, &originalFrame.sp50);
                M2C_FIELD(temp_v0_7, signed char*, 2) = 6;
                M2C_FIELD(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
    }
}
#undef M2C_FIELD

void func_level_27_8008874C(void) {
    switch (spyro.animationState) {
        case 0x14:
            if (func_800438F4() == 0) {
                func_80043728();
            }
            func_80041C20();
            spyro.unk9a = 0;
            goto block_6;
        case 0x20:
        case 0x35:
        case 0x36:
            func_80041C20();
        block_6:
            func_80042A44();
        block_7:
            spyro.unk4[0] = 0;
            return;
        case 0x9:
            func_80041C20();
            func_80042A44();
            if (spyro.unk5 == 1) {
                func_80041930();
            } else {
                func_80043A38(0xC00);
            }
            if ((unsigned char)spyro.bodyAnimation.nextFrame < 0xAU) {
                spyro.cheatColour.a = 0xFF;
                if (spyro.bodyAnimation.nextFrame & 1) {
                    spyro.cheatColour.b = 0xFF;
                    spyro.cheatColour.g = 0xFF;
                    spyro.cheatColour.r = 0xFF;
                } else {
                    spyro.cheatColour.b = 0x40;
                    spyro.cheatColour.g = 0x40;
                    spyro.cheatColour.r = 0x40;
                }
            }
            goto block_7;
        case 0x1A:
            func_80041C20();
            func_80042A44();
            func_80043A38(0xC00);
            goto block_7;
        case 0x1C:
            func_80041C20();
            func_80042A44();
            func_80041930();
            if ((spyro.unk7a[3].z < 0) && (spyro.animationStateFrames >= 4)) {
                spyro.unk5 = 1;
            }
            goto block_7;
        case 0x3A:
            func_80041C20();
            func_80042A44();
            spyro.cheatColour.a = 0xFF;
            spyro.unk4[0] = 0;
            spyro.cheatColour.b = 0x20;
            spyro.cheatColour.g = 0x20;
            spyro.cheatColour.r = 0x20;

        default:
            return;
    }
}

#define LEVEL_ID 27
#define PlaySpyroSounds_level_27 func_level_27_80088940
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_27_80088A48(int index) {
    Vector3D* vector;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 9: {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0x4C);
            MATCHING_KEEP(state);
            if (*state == 1)
                goto reset;
            vector = (Vector3D*)((char*)state + 0x80);
            goto apply;
        }
        case 0x14:
        case 0x1A:
        case 0x20:
        case 0x35:
        case 0x36:
        case 0x3A:
            vector = &spyro.unk9e;
            goto apply;
        case 0x1C:
        reset:
            vector = 0;
        apply:
            func_80043ABC(vector);
            break;
    }
}

extern Spyro Callback27_D_80070328 __asm__("D_80070328");
extern short Callback27_D_800658A0[] __asm__("D_800658A0");
extern short Callback27_D_80065920[] __asm__("D_80065920");
int Callback27MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
int Callback27RandBetween(int low, int high) __asm__("func_8003636C");
int Callback27_func_80040954(int arg0) __asm__("func_80040954");
void Callback27_func_80043A38(int scale) __asm__("func_80043A38");
void Callback27_func_800441F0(void) __asm__("func_800441F0");
void Callback27ShiftVectorLeft(Vector3D*, int) __asm__("func_8004F0E8");
void Callback27ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Callback27_D_8006E524 __asm__("D_8006E524");
extern int Callback27_D_8006E528 __asm__("D_8006E528");
extern unsigned char Raw27Union[] __asm__("D_80070328+0x144");
extern int Raw27Movement __asm__("D_80070328+0x50");
extern short Signed27A[] __asm__("D_800658A0");
extern short Signed27B[] __asm__("D_80065920");
extern int Raw27X __asm__("D_80070328+0x8C");
int Squish27Call(int, int, int) __asm__("PlaySound");
void func_level_27_80088AE4(int selector) {
    register Vector3D* sourceC __asm__("$16");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register int oldMovementC __asm__("$5");
    register int oldMovementD __asm__("$6");
    register int oldMovementA __asm__("$3");
    register int oldMovementB __asm__("$3");
    register int flags __asm__("$2");
    register unsigned char* header __asm__("$17");
    register int* sourceA __asm__("$16");
    int* sourceB;

    switch (selector) {
        case 0x14:
            Callback27_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Callback27_D_80070328.unk5 = 0;
            Callback27_func_800441F0();
            Callback27_D_80070328.grounded = 1;
            Callback27_D_80070328.union144.a.unk13cb = Callback27RandBetween(1, 3);
            Callback27_D_80070328.union144.a.unk13cc = 0;
            goto clearTail;
        case 0x9:
            header = (unsigned char*)&Callback27_D_80070328.unk11[2];
            if (Callback27_func_80040954(*(int*)header) == 7) {
                sourceA = header - 0x74;
                oldMovementA = Raw27Movement;
                Raw27Movement = MOVEMENT_STATE_HURT;
                Callback27_D_80070328.unk5 = 1;
                Callback27_D_80070328.union144.a.unk13cb = oldMovementA;
                func_8004F178((Vector3D*)(header - 0x80), (Vector3D*)sourceA);
                Callback27_D_80070328.unk8[0] =
                    Callback27MeasureVectorLength((Vector3D*)sourceA, 0);
                Callback27_D_80070328.unk7a[2].z = 0xDC0;
                Callback27_D_80070328.grounded = 0;
            } else {
                oldMovementB = Raw27Movement;
                flags = Callback27_D_80070328.unk17a;
                MATCHING_KEEP2(oldMovementB, flags);
                Raw27Movement = MOVEMENT_STATE_HURT;
                Callback27_D_80070328.unk5 = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(flags, "memory");
                Callback27_D_80070328.union144.a.unk13cb = oldMovementB;
                sourceB = header - 0x80;
                if (flags & 0x400) {
                    func_8004F178((Vector3D*)sourceB, (Vector3D*)(header + 0x110));
                    Callback27ShiftVectorLeft((Vector3D*)sourceB, 6);
                } else if (Callback27_D_80070328.unk22[5] >= 0) {
                    tableIndex = Callback27_D_80070328.unk22[5] * 2;
                    tableValue = *(short*)((unsigned char*)Signed27B + tableIndex);
                    MATCHING_KEEP(tableValue);
                    Raw27X = tableValue >> 1;
                    tableIndex = *(short*)((unsigned char*)Signed27A + tableIndex);
                    Callback27_D_80070328.unk7a[2].z = 0;
                    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableIndex, "memory");
                    Callback27_D_80070328.unk7a[2].y = tableIndex >> 1;
                } else {
                    MATCHING_KEEP(header);
                    destination = (Vector3D*)(header - 0x80);
                    Callback27ClearVector(destination);
                }
                func_8004F178(&Callback27_D_80070328.unk7a[1],
                              (unsigned char*)&Callback27_D_80070328.unk7a[1] + 0xC);
                Callback27_func_80043A38(0xC00);
                Callback27_D_80070328.grounded = 1;
            }
            Callback27_D_8006E528 = 0x2D;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            goto clearTail;
        case 0x1A:
            savedBase = Raw27Union;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            oldMovementC = Raw27Movement;
            Raw27Movement = MOVEMENT_STATE_HURT;
            Callback27_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementC;
            Callback27ClearVector(destination);
            Callback27_D_80070328.grounded = 1;
            Callback27_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            Squish27Call((int)D_8006C654->squish, 0, 0);
            goto clearTail;
        case 0x1C:
            savedBase = Raw27Union;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Raw27Movement;
            Raw27Movement = MOVEMENT_STATE_HURT;
            Callback27_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Callback27_D_80070328.unk8[0] = Callback27MeasureVectorLength(sourceC, 0);
            Callback27_D_80070328.unk7a[2].z = 0xDC0;
            Callback27_D_80070328.grounded = 0;
            Callback27_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Callback27_D_80070328.damageFlags & 0x200) {
                Callback27_D_80070328.union144.a.unk13cc = 0;
            } else {
                Callback27_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            goto clearTail;
        case 0x20:
        case 0x3A:
            Callback27_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Callback27_D_80070328.unk5 = 0;
            Callback27_func_80043A38(0xC00);
            Callback27_D_80070328.grounded = 1;
            if ((selector == 0x3A) || (selector == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Callback27_D_8006E524 = 0xF;
            goto clearTail;
        case 0x35:
        case 0x36:
            Callback27_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Callback27_D_80070328.unk5 = 0;
            Callback27_func_800441F0();
            Callback27_D_80070328.grounded = 1;
        clearTail:
            Callback27_D_80070328.unk20a = 0;
            Callback27_D_80070328.critterMobyPtr = 0;
            break;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level27
 * 80088F0C: original508 instructions and50 dispatch words in sibling4506
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original27.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A27W48 __asm__("D_80070328 + 0x48");
extern int A27W4C __asm__("D_80070328 + 0x4C");
extern int A27W54 __asm__("D_80070328 + 0x54");
extern int A27WA0 __asm__("D_80070328 + 0xA0");
extern int A27WA8 __asm__("D_80070328 + 0xA8");
extern int A27WAC __asm__("D_80070328 + 0xAC");
extern int A27WB0 __asm__("D_80070328 + 0xB0");
extern int A27WB8 __asm__("D_80070328 + 0xB8");
extern int A27WCC __asm__("D_80070328 + 0xCC");
extern int A27WD0 __asm__("D_80070328 + 0xD0");
extern int A27WD4 __asm__("D_80070328 + 0xD4");
extern int A27W8C __asm__("D_80070328 + 0x8C");
extern int A27W90 __asm__("D_80070328 + 0x90");
extern int A27W94 __asm__("D_80070328 + 0x94");
extern int A27WE4 __asm__("D_80070328 + 0xE4");
extern int A27W144 __asm__("D_80070328 + 0x144");
extern int A27W158 __asm__("D_80070328 + 0x158");
extern int A27W1EC __asm__("D_80070328 + 0x1EC");
extern int A27W1F0 __asm__("D_80070328 + 0x1F0");
extern int A27W240 __asm__("D_80070328 + 0x240");
extern int A27W280 __asm__("D_80070328 + 0x280");
extern unsigned char A27B14 __asm__("D_80070328 + 0x14");
extern unsigned char A27B15 __asm__("D_80070328 + 0x15");
extern unsigned char A27B16 __asm__("D_80070328 + 0x16");
extern unsigned char A27B17 __asm__("D_80070328 + 0x17");
extern unsigned char A27B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A27BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A27B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A27B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A27Player[] __asm__("D_80070328");
extern unsigned char A27Table[] __asm__("D_80066530");
extern int A27Buttons __asm__("D_8006E538"), A27NewButtons __asm__("D_8006E53C");
extern int A27Mode __asm__("D_8006E044"), A27Gate __asm__("D_8006E344"),
    A27Count __asm__("D_8006C514");
extern int (*A27Callback)() __asm__("unk_ovlheader_80074374");
extern int A27W24 __asm__("D_80070328 + 0x24");
extern int A27W28C __asm__("D_80070328 + 0x28C");
extern int A27W290 __asm__("D_80070328 + 0x290");
extern int A27Surface __asm__("D_8006FA38");
extern unsigned char* A27SoundDesc __asm__("D_8006C654");
int A27Sound() __asm__("PlaySound");
int A27H40994() __asm__("func_80040994");
int A27H4BEF8() __asm__("func_8004BEF8");
int A27H49688() __asm__("func_80049688");
int A27H498C0() __asm__("func_800498C0");
void func_level_27_80088F0C(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register int* state __asm__("$16");
    switch (A27W48) {
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 27:
        case 29:
        case 30:
        case 31:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
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
        case 55:
        case 56:
        case 57:
            return;
        case 20:
            if (A27H40994())
                return;
            if (A27NewButtons & 0x40) {
                A27H4BEF8(6);
                return;
            }
            if (A27WB8 >= 4 || A27WE4 >= 23)
                goto set7;
            work3 = A27Buttons;
            if (work3 & 0x80) {
                A27H4BEF8(13);
                return;
            }
            work2 = A27WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17)
                goto set1;
            work2 = work3 & 12;
            MATCHING_KEEP(work2);
            if (!work2 && A27WAC)
                goto set1;
            if (A27Mode == 7 || A27W240) {
                state = &A27W48;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                A27H4BEF8(0);
                if (A27Table[*((unsigned char*)state - 0x2C)] >= 96) {
                    A27B14 = A27B15;
                    A27B16 = A27B17;
                }
                A27B17 = 0;
                work3 = *state;
                work2 = 113;
                *((unsigned char*)state - 0x2C) = work2;
                A27W1F0 = 0;
                A27B15 = work3;
                A27W1EC = work3;
                return;
            }
            if (A27BFC) {
                A27H4BEF8(15);
                return;
            }
            A27H49688();
            return;
        case 53:
        case 54:
            if (!A27H40994())
                goto set0;
            return;
        case 9:
            work3 = A27W4C;
            if (work3 != 1)
                goto charge9;
            if (A27B1B5 && (A27NewButtons & 64))
                A27B1B6 = 1;
            if (A27WB8 || A27W54 < 16 || A27WE4 >= 23)
                goto buttons9;
            work3 = A27WCC;
            work2 = A27W8C;
            work5 = work3 * work2;
            work3 = A27WD0;
            work2 = A27W90;
            work4 = work3 * work2;
            work3 = A27WD4;
            work2 = A27W94;
            work3 = work3 * work2;
            work2 = work5 + work4;
            work2 += work3;
            if (work2 >= 0)
                goto buttons9;
            if (A27WAC) {
                work3 = A27WB0;
                if (work3 > 3840)
                    goto set3;
                work2 = work3 < 1921;
                MATCHING_KEEP(work2);
                if (!work2)
                    goto set2;
                goto set1;
            }
            if (A27WB0 >= 1920)
                goto set4;
            goto set0;
        buttons9:
            if ((A27Buttons & 128) && A27WA0 < 0 && A27W54 >= 5)
                goto set22;
            if (A27B1B5 && A27B1B6) {
                if (A27WA0 >= 0)
                    return;
                if (A27W54 >= 5)
                    goto set17;
            }
            work3 = A27WA0;
            if (work3 >= 0)
                return;
            work4 = A27W54;
            if (work4 < 5)
                return;
            work2 = work3 < -6400;
            MATCHING_KEEP(work2);
            if (work2)
                goto set7;
            work2 = work4 < 91;
            goto check91;
        charge9:
            if (A27W24 & 32)
                return;
            if (A27W54 < 25)
                return;
            if (A27W280 < 0) {
                A27H4BEF8(31);
                return;
            }
        selectState:
            work3 = A27W144;
            if (work3 == 10)
                goto set44;
            work2 = work3 - 11;
            MATCHING_KEEP(work2);
            if ((unsigned int)work2 < 2)
                goto set41;
            if (!A27WB8)
                goto set0;
            goto set7;
        case 26:
            if (A27W24 & 16)
                return;
            if (A27W54 < 25)
                return;
            if (A27W280 < 0) {
                A27H4BEF8(32);
                return;
            }
            A27Sound(A27SoundDesc[15], 0, 0);
            goto selectState;
        set44:
            A27H4BEF8(44);
            return;
        set41:
            A27H4BEF8(41);
            return;
        case 28:
            if (A27B1B5 && (A27NewButtons & 64))
                A27B1B6 = 1;
            if (A27WB8 || A27W54 < 16 || A27WE4 >= 23)
                goto buttons;
            work3 = A27WCC;
            work2 = A27W8C;
            work5 = work3 * work2;
            work3 = A27WD0;
            work2 = A27W90;
            work4 = work3 * work2;
            work3 = A27WD4;
            work2 = A27W94;
            work3 = work3 * work2;
            work2 = work5 + work4;
            work2 += work3;
            if (work2 >= 0)
                goto buttons;
            if (!A27WAC)
                goto checkSpeed;
            work3 = A27WB0;
            if (work3 > 3840) {
            set3:
                A27H4BEF8(3);
                return;
            }
            work2 = work3 < 1921;
            MATCHING_KEEP(work2);
            if (!work2) {
            set2:
                A27H4BEF8(2);
                return;
            }
        set1:
            A27H4BEF8(1);
            return;
        checkSpeed:
            if (A27WB0 < 1920)
                goto set0;
        set4:
            A27H4BEF8(4);
            return;
        set0:
            A27H4BEF8(0);
            return;
        buttons:
            if ((A27Buttons & 128) && A27W4C == 1) {
            set22:
                A27H4BEF8(22);
                return;
            }
            if (A27B1B5 && A27B1B6) {
                if (A27W4C != 1)
                    return;
            set17:
                A27H4BEF8(17);
                return;
            }
            if (A27W4C != 1)
                return;
            if (A27WA0 < -6400)
                goto set7;
            work2 = A27W54 < 91;
        check91:
            if (work2)
                return;
        set7:
            A27H4BEF8(7);
            return;
        case 32:
            work2 = A27W54 < 125;
            goto checkTimer;
        case 58:
            work2 = A27W54 < 137;
        checkTimer:
            if (work2)
                return;
        call498C0:
            A27H498C0();
            return;
    }
}

