#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80078678.
* Assembly SHA256 05ee468207a4c3251977bdeece2ace42a8e8059a9df0a1e0d92f5eaf5c5d9575.
* AI generated; not human reviewed. All579 original instructions and
* actual branch/call/internal targets are required; there is no owned
* selector/data table. Frame30 preserves S0/S1/S2/S3/S4/RA saves and the
* original unused SP10/SP14 extent. Its write-only empty memory output
* has no memory input; neither word is read, passed to a helper or given
* an invented retail value. It emits no initialization or CPU instruction.
* Original dispatch,32-bit cursor/count relocation, independent archive
* pointer reloads,color byte copies,record word/byte accesses,complete rand
* results,ordinary signed division by3/remainder160,and both independent
* timer paths match exactly. No HI operand/partial-product constraint,
* fixed FP shortcut or opcode assembly is used. Initialized register
* dependencies and dead-register clobbers emit zero instructions.
* Raw units/fixed point, complete helper contracts, caller cadence and
* synchronized retail runtime remain unresolved. Cadence here is per
* invocation; confidence is binary identity after every acceptance gate.
* Falsification: every native/linked word and actual target, full EXE and
* every overlay retail hash must remain identical. */
#define LoadingField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char LoadingCallCDLoadAsyncView1() __asm__("CDLoadAsync");
int LoadingCallCDLoadTimeView1() __asm__("CDLoadTime");
int LoadingCallPlaySoundView1() __asm__("PlaySound");
unsigned char LoadingClearTwoDisplayRegionsView1() __asm__("func_8001EBAC");
unsigned char LoadingRelocateAndPublishModelView1() __asm__("func_8002AF9C");
unsigned char LoadingServiceLevelResourceLoadingView1() __asm__("func_8002CA50");
unsigned char LoadingSetSoundHandleWord0CAndFlag10View1() __asm__("func_8003C140");
unsigned char LoadingUpdatePlayerAnimationSubstepsView1() __asm__("func_80044240");
unsigned char LoadingResetPlayerRuntimeStateView1() __asm__("func_80047190");
int LoadingPullPlayerPoseTowardTargetView1() __asm__("func_80048444");
unsigned char LoadingDispatchPlayerStateRequestView1() __asm__("func_8004BEF8");
unsigned char LoadingCall75738View1() __asm__("func_loading_80075738");
int LoadingCallrandView1() __asm__("rand");
extern unsigned char LoadingData6668CView1 __asm__("D_8006668C");
extern unsigned char LoadingData66FCCView1 __asm__("D_80066FCC");
extern int LoadingData6C508View1 __asm__("D_8006C508");
extern int LoadingData6C518View1 __asm__("D_8006C518");
extern int LoadingData6C58CView1 __asm__("D_8006C58C");
extern int LoadingData6C598View1 __asm__("D_8006C598");
extern int LoadingData6C5BCView1 __asm__("D_8006C5BC");
extern int LoadingData6C60CView1 __asm__("D_8006C60C");
extern int LoadingData6C6F8View1 __asm__("D_8006C6F8");
extern int LoadingData6C718View1 __asm__("D_8006C718");
extern unsigned char* LoadingData6C764View1 __asm__("D_8006C764");
extern int LoadingData6C7C8View1 __asm__("D_8006C7C8");
extern unsigned char LoadingData6D8D8View1 __asm__("D_8006D8D8");
extern int LoadingData6E038View1 __asm__("D_8006E038");
extern int LoadingData6E334View1 __asm__("D_8006E334");
extern void** LoadingData6E338View1 __asm__("D_8006E338");
extern unsigned char LoadingData6E33CView1 __asm__("D_8006E33C");
extern unsigned char LoadingData6E33DView1 __asm__("D_8006E33D");
extern unsigned char LoadingData6E33EView1 __asm__("D_8006E33E");
extern int LoadingData6E470View1 __asm__("D_8006E470");
extern unsigned char LoadingData6E988View1 __asm__("D_8006E988");
extern int LoadingData6FBC4View1 __asm__("D_8006FBC4");
extern int LoadingData6FBC8View1 __asm__("D_8006FBC8");
extern int LoadingData6FBD0View1 __asm__("D_8006FBD0");
extern unsigned char LoadingData6FC15View1 __asm__("D_8006FC15");
extern unsigned char LoadingData6FC16View1 __asm__("D_8006FC16");
extern unsigned char LoadingData6FC17View1 __asm__("D_8006FC17");
extern unsigned char LoadingData6FC89View1 __asm__("D_8006FC89");
extern unsigned char LoadingData6FC8AView1 __asm__("D_8006FC8A");
extern unsigned char LoadingData6FC8BView1 __asm__("D_8006FC8B");
extern unsigned char LoadingData70328View1 __asm__("D_80070328");
extern void* LoadingData722D0View1 __asm__("D_800722D0");
extern int LoadingData722ECView1 __asm__("D_800722EC");
extern int LoadingData722F0View1 __asm__("D_800722F0");
extern int LoadingData722F8View1 __asm__("D_800722F8");
extern int LoadingData722FCView1 __asm__("D_800722FC");
extern int LoadingData72328View1 __asm__("D_80072328");
extern int LoadingData7232CView1 __asm__("D_8007232C");
void func_loading_80078678(void) {
    register int basePointerOrIndex16 __asm__("$16");
    register int timerPointerOrOffset17 __asm__("$17");
    register int bufferPointerOrStep18 __asm__("$18");
    register int chunkCursorOrThreshold19 __asm__("$19");
    register int retainedOne20 __asm__("$20");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    int temporaryWord4;
    void* temporaryPointer1;
    void* temporaryPointer2;
    void* temporaryPointer3;
    struct {
        int words[2];
    } originalUnusedFrameExtent;
    argumentWord5 = (int)&LoadingData6FBC8View1;
    MATCHING_KEEP(argumentWord5);
    rawWord3 = LoadingField(argumentWord5, int*, 0);
    __asm__ __volatile__("" ::: "$4", "memory");
    argumentWord4 = 2;
    if (rawWord3 == argumentWord4)
        goto loadingState2;
    rawWord2 = rawWord3 < 3;
    if (rawWord2) {
        rawWord2 = 1;
        if (rawWord3 == rawWord2)
            goto loadingState1;
        return;
    }
    rawWord2 = 3;
    if (rawWord3 == rawWord2)
        goto loadingState3;
    rawWord2 = 4;
    if (rawWord3 == rawWord2)
        goto loadingState4;
    return;
    {
    loadingState1:
        if (LoadingData6C518View1 < 2) {
            LoadingServiceLevelResourceLoadingView1(argumentWord4, argumentWord5);
            return;
        }
        LoadingField(argumentWord5, int*, 0) = argumentWord4;
        return;
    loadingState2:
        if (LoadingData7232CView1 == 0) {
            if (LoadingData6C508View1 != 0) {
                temporaryWord4 = LoadingData6C7C8View1;
            } else {
                temporaryWord4 = LoadingData6C5BCView1;
            }
            LoadingCallCDLoadAsyncView1(
                LoadingData6E470View1, LoadingData722D0View1 + 0x2A000, 0xC000,
                LoadingField(&LoadingData6D8D8View1, int*, 0x300) +
                    (LoadingField(
                         &LoadingData6668CView1, unsigned char*,
                         LoadingField(&LoadingData66FCCView1, unsigned char*, temporaryWord4)) *
                     0xC000));
            LoadingData7232CView1 = 1;
        }
        timerPointerOrOffset17 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(timerPointerOrOffset17);
        rawWord2 = LoadingField(timerPointerOrOffset17, int*, 0);
        rawWord3 = LoadingData6FBD0View1;
        argumentWord4 = rawWord2 + 1;
        LoadingField(timerPointerOrOffset17, int*, 0) = argumentWord4;
        if (!rawWord3) {
            rawWord2 = argumentWord4 < 16;
            MATCHING_KEEP(rawWord2);
            if (!rawWord2)
                goto clearPendingColorBytes;
            basePointerOrIndex16 = (int)&LoadingData722ECView1;
            MATCHING_KEEP(basePointerOrIndex16);
            if (LoadingPullPlayerPoseTowardTargetView1(basePointerOrIndex16) < 1024) {
                rawWord2 = LoadingField(basePointerOrIndex16, int*, 0);
                argumentWord4 = LoadingData722F8View1;
                rawWord3 = LoadingData722F0View1;
                argumentWord5 = LoadingData722FCView1;
                rawWord2 += argumentWord4;
                rawWord3 += argumentWord5;
                LoadingField(basePointerOrIndex16, int*, 0) = rawWord2;
                LoadingData722F0View1 = rawWord3;
            }
            LoadingUpdatePlayerAnimationSubstepsView1();
            rawWord2 = LoadingField(timerPointerOrOffset17, int*, 0);
            LoadingData6C598View1 = rawWord2 * 16;
            return;
        }
    clearPendingColorBytes:
        LoadingData6FC15View1 = 0;
        LoadingData6FC16View1 = 0;
        LoadingData6FC17View1 = 0;
        LoadingData6FC89View1 = 0;
        LoadingData6FC8AView1 = 0;
        LoadingData6FC8BView1 = 0;
        if ((LoadingData7232CView1 != 0) && (LoadingCallCDLoadTimeView1() == 0)) {
            timerPointerOrOffset17 = 0x2A000;
            bufferPointerOrStep18 = (int)&LoadingData722D0View1;
            MATCHING_KEEP(bufferPointerOrStep18);
            basePointerOrIndex16 = LoadingField(bufferPointerOrStep18, int*, 0);
            argumentWord5 = 1;
            chunkCursorOrThreshold19 = basePointerOrIndex16 + timerPointerOrOffset17;
            argumentWord4 = LoadingField(chunkCursorOrThreshold19, int*, 0);
            argumentWord6 = 0x80800000;
            argumentWord4 += timerPointerOrOffset17;
            argumentWord4 = basePointerOrIndex16 + argumentWord4;
            LoadingRelocateAndPublishModelView1(argumentWord4 + 20, argumentWord5, argumentWord6);
            argumentWord5 = 0x202;
            argumentWord6 = 0x80800000;
            argumentWord4 = LoadingField(basePointerOrIndex16, int*, 0x2A004);
            rawWord2 = LoadingField(bufferPointerOrStep18, int*, 0);
            argumentWord4 += timerPointerOrOffset17;
            LoadingRelocateAndPublishModelView1(rawWord2 + argumentWord4, argumentWord5,
                                                argumentWord6);
            argumentWord5 = 0x204;
            argumentWord6 = 0x80800000;
            argumentWord4 = LoadingField(basePointerOrIndex16, int*, 0x2A008);
            rawWord2 = LoadingField(bufferPointerOrStep18, int*, 0);
            argumentWord4 += timerPointerOrOffset17;
            LoadingRelocateAndPublishModelView1(rawWord2 + argumentWord4, argumentWord5,
                                                argumentWord6);
            argumentWord5 = 0x28B;
            argumentWord6 = 0x80800000;
            argumentWord4 = LoadingField(basePointerOrIndex16, int*, 0x2A00C);
            rawWord2 = LoadingField(bufferPointerOrStep18, int*, 0);
            argumentWord4 += timerPointerOrOffset17;
            LoadingRelocateAndPublishModelView1(rawWord2 + argumentWord4, argumentWord5,
                                                argumentWord6);
            rawWord2 = LoadingField(basePointerOrIndex16, int*, 0x2A010);
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = (int)&LoadingData6E33CView1;
            MATCHING_KEEP(argumentWord5);
            chunkCursorOrThreshold19 += rawWord2;
            rawWord2 = LoadingField(chunkCursorOrThreshold19, unsigned char*, 0);
            LoadingField(argumentWord5, unsigned char*, 0) = rawWord2;
            rawWord2 = LoadingField(chunkCursorOrThreshold19, unsigned char*, 1);
            argumentWord4 = chunkCursorOrThreshold19;
            LoadingData6E33DView1 = rawWord2;
            rawWord2 = LoadingField(chunkCursorOrThreshold19, unsigned char*, 2);
            MATCHING_KEEP(chunkCursorOrThreshold19);
            chunkCursorOrThreshold19 += 4;
            LoadingData6E33EView1 = rawWord2;
            rawWord2 = LoadingField(chunkCursorOrThreshold19, int*, 0);
            chunkCursorOrThreshold19 += 4;
            LoadingData6E338View1 = (void**)chunkCursorOrThreshold19;
            LoadingData6E334View1 = rawWord2;
            __asm__ __volatile__("" ::: "$3", "memory");
            rawWord3 = 0;
            if (rawWord2 > 0) {
                __asm__ __volatile__(""
                                     : "=r"(argumentWord5)
                                     : "0"(argumentWord5), "i"(0x80078998)
                                     : "memory");
                argumentWord5 -= 8;
                do {
                    rawWord2 = LoadingField(chunkCursorOrThreshold19, int*, 0);
                    rawWord3++;
                    rawWord2 = argumentWord4 + rawWord2;
                    LoadingField(chunkCursorOrThreshold19, int*, 0) = rawWord2;
                    rawWord2 = LoadingField(argumentWord5, int*, 0);
                    chunkCursorOrThreshold19 += 4;
                } while (rawWord3 < rawWord2);
            }
            LoadingData6C718View1 = 1;
            LoadingData6E038View1 = 0;
            LoadingData6FBC8View1 = 3;
            LoadingData6FBC4View1 = 0;
            LoadingData6FC15View1 = LoadingData6E33CView1;
            LoadingData6FC16View1 = LoadingData6E33DView1;
            LoadingData6FC17View1 = LoadingData6E33EView1;
            LoadingData6FC89View1 = LoadingData6E33CView1;
            LoadingData6FC8AView1 = LoadingData6E33DView1;
            LoadingData6FC8BView1 = LoadingData6E33EView1;
            LoadingData6C5BCView1 = LoadingData6C7C8View1;
            LoadingData6C60CView1 = LoadingData6C58CView1;
            return;
        }
        return;
    loadingState3:
        if (LoadingData6C518View1 < 8) {
            LoadingServiceLevelResourceLoadingView1();
        }
        if (LoadingData6FBC4View1 == 0) {
            LoadingResetPlayerRuntimeStateView1();
            LoadingField(&LoadingData70328View1, int*, 0) = 0x2000;
            LoadingField(&LoadingData70328View1, int*, 4) = 0x2000;
            LoadingField(&LoadingData70328View1, int*, 8) = 0x2000;
            LoadingField(&LoadingData70328View1, signed char*, 0x1E) = 0;
            LoadingDispatchPlayerStateRequestView1(0);
            LoadingField(&LoadingData70328View1, signed char*, 0xC) = 0;
            LoadingField(&LoadingData70328View1, signed char*, 0xD) = 0;
            LoadingField(&LoadingData70328View1, signed char*, 0xE) = 0;
            LoadingData72328View1 = LoadingCallrandView1() & 1;
        }
        LoadingUpdatePlayerAnimationSubstepsView1();
        if ((unsigned int)(LoadingData6FBC4View1 - 0x20) < 0x49U) {
            if (LoadingData6FBC4View1 == 0x20) {
                LoadingData6C764View1 = &LoadingData6E988View1;
                basePointerOrIndex16 = 0;
                MATCHING_KEEP(basePointerOrIndex16);
                do {
                    rawWord2 = basePointerOrIndex16 * 8;
                    rawWord3 = (int)LoadingData6C764View1;
                    basePointerOrIndex16++;
                    rawWord2 += rawWord3;
                    LoadingField(rawWord2, unsigned char*, 4) = 0;
                    rawWord2 = basePointerOrIndex16 < 32;
                    MATCHING_KEEP(rawWord2);
                } while (rawWord2);
            }
            bufferPointerOrStep18 = 3;
            if (LoadingData6C6F8View1 >= 0x10) {
                bufferPointerOrStep18 = 1;
            }
            basePointerOrIndex16 = 0;
            retainedOne20 = 1;
            MATCHING_KEEP(retainedOne20);
            timerPointerOrOffset17 = 0;
            chunkCursorOrThreshold19 = 0x20;
            do {
                if ((basePointerOrIndex16 < LoadingData6C6F8View1) &&
                    (LoadingData6FBC4View1 >= chunkCursorOrThreshold19)) {
                    rawWord2 = (int)LoadingData6C764View1;
                    rawWord3 = timerPointerOrOffset17 + rawWord2;
                    temporaryPointer2 = (void*)rawWord3;
                    if (LoadingField(temporaryPointer2, unsigned char*, 4) == 0) {
                        if (LoadingData6FBC4View1 < 0x40) {
                            LoadingField(temporaryPointer2, unsigned char*, 4) = retainedOne20;
                            if ((bufferPointerOrStep18 != retainedOne20) ||
                                (basePointerOrIndex16 == ((basePointerOrIndex16 / 3) * 3))) {
                                LoadingSetSoundHandleWord0CAndFlag10View1(
                                    LoadingCallPlaySoundView1(1, 0, 0), 0x800);
                            }
                            rawWord2 = (int)LoadingData6C764View1;
                            rawWord2 = timerPointerOrOffset17 + rawWord2;
                            LoadingField(rawWord2, int*, 0) = 0;
                            if (basePointerOrIndex16 == 0) {
                                LoadingField(LoadingData6C764View1, signed char*, 5) =
                                    LoadingCallrandView1();
                            } else {
                                rawWord2 = LoadingCallrandView1();
                                argumentWord6 = (int)LoadingData6C764View1;
                                argumentWord6 = timerPointerOrOffset17 + argumentWord6;
                                argumentWord5 =
                                    LoadingField(argumentWord6, unsigned char*, -3) + 48;
                                LoadingField(argumentWord6, unsigned char*, 5) =
                                    argumentWord5 + (rawWord2 % 160);
                            }
                            rawWord2 = LoadingCallrandView1();
                            rawWord3 = (int)LoadingData6C764View1;
                            rawWord3 = timerPointerOrOffset17 + rawWord3;
                            LoadingField(rawWord3, unsigned char*, 6) = rawWord2;
                            rawWord2 = LoadingCallrandView1();
                            rawWord2 &= 15;
                            rawWord3 = (int)LoadingData6C764View1;
                            rawWord2 -= 8;
                            rawWord3 = timerPointerOrOffset17 + rawWord3;
                            LoadingField(rawWord3, unsigned char*, 7) = rawWord2;
                        }
                        if (LoadingField(timerPointerOrOffset17 + (int)LoadingData6C764View1,
                                         unsigned char*, 4) != 0) {
                            goto advanceRecord;
                        }
                    } else {
                    advanceRecord:
                        argumentWord4 = (int)LoadingData6C764View1;
                        argumentWord4 = timerPointerOrOffset17 + argumentWord4;
                        temporaryPointer1 = (void*)argumentWord4;
                        LoadingField(temporaryPointer1, unsigned char*, 6) =
                            (unsigned char)(LoadingField(temporaryPointer1, unsigned char*, 6) +
                                            LoadingField(temporaryPointer1, unsigned char*, 7));
                        rawWord3 = (int)LoadingData6C764View1;
                        rawWord3 = timerPointerOrOffset17 + rawWord3;
                        temporaryPointer3 = (void*)rawWord3;
                        LoadingField(temporaryPointer1, int*, 0) =
                            (int)(LoadingField(temporaryPointer1, int*, 0) + 1);
                        if ((LoadingField(temporaryPointer3, int*, 0) >= 0x28) &&
                            ((LoadingField(temporaryPointer3, signed char*, 4) = 0,
                              (bufferPointerOrStep18 != retainedOne20)) ||
                             (basePointerOrIndex16 == ((basePointerOrIndex16 / 3) * 3)))) {
                            LoadingSetSoundHandleWord0CAndFlag10View1(
                                LoadingCallPlaySoundView1(0, 0, 0), 0x800);
                        }
                    }
                }
                timerPointerOrOffset17 += 8;
                basePointerOrIndex16 += 1;
                chunkCursorOrThreshold19 += bufferPointerOrStep18;
            } while (basePointerOrIndex16 < 0x18);
        }
        LoadingCall75738View1();
        rawWord2 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(rawWord2);
        argumentWord4 = LoadingField(rawWord2, int*, 0);
        rawWord3 = argumentWord4 + 1;
        LoadingField(rawWord2, int*, 0) = rawWord3;
        rawWord2 = rawWord3 < 9;
        MATCHING_KEEP(rawWord2);
        if (rawWord2) {
            rawWord2 = 8;
            rawWord2 -= rawWord3;
            goto storeState3TimerValue;
        }
        rawWord2 = rawWord3 < 133;
        if (rawWord2)
            goto afterState3Timer;
        rawWord2 = argumentWord4 - 131;
    storeState3TimerValue:
        rawWord2 <<= 5;
        LoadingData6C598View1 = rawWord2;
    afterState3Timer:;
        argumentWord4 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(argumentWord4);
        rawWord3 = LoadingField(argumentWord4, int*, 0);
        if (rawWord3 == 140) {
            rawWord2 = 4;
            LoadingData6FBC8View1 = rawWord2;
            rawWord2 = 255;
            LoadingField(argumentWord4, int*, 0) = 0;
            LoadingData6C598View1 = rawWord2;
            return;
        }
        return;
    loadingState4:
        __asm__ __volatile__("" : "=m"(originalUnusedFrameExtent));
        if (LoadingData6C518View1 < 8) {
            LoadingServiceLevelResourceLoadingView1();
        }
        if (LoadingData6FBC4View1 == 0) {
            LoadingData72328View1 = (LoadingCallrandView1() & 1) + 2;
        }
        LoadingUpdatePlayerAnimationSubstepsView1();
        LoadingCall75738View1();
        argumentWord4 = LoadingData6FBC4View1;
        rawWord3 = argumentWord4 + 1;
        rawWord2 = rawWord3 < 9;
        LoadingData6FBC4View1 = rawWord3;
        MATCHING_KEEP(rawWord2);
        if (rawWord2) {
            rawWord2 = 8;
            rawWord2 -= rawWord3;
            goto storeState4TimerValue;
        }
        rawWord2 = rawWord3 < 112;
        if (rawWord2)
            goto afterState4Timer;
        rawWord2 = argumentWord4 - 111;
    storeState4TimerValue:
        rawWord2 <<= 5;
        LoadingData6C598View1 = rawWord2;
    afterState4Timer:;
        if (LoadingData6C598View1 >= 0x100) {
            LoadingData6C598View1 = 0xFF;
        }
        basePointerOrIndex16 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(basePointerOrIndex16);
        rawWord3 = LoadingField(basePointerOrIndex16, int*, 0);
        if (rawWord3 == 120) {
            LoadingClearTwoDisplayRegionsView1();
            rawWord2 = 5;
            LoadingData6FBC8View1 = rawWord2;
            rawWord2 = LoadingData6C518View1;
            rawWord3 = 1;
            LoadingField(basePointerOrIndex16, int*, 0) = 0;
            LoadingData6C718View1 = rawWord3;
            if (rawWord2 < 8) {
                do {
                    LoadingServiceLevelResourceLoadingView1();
                } while (LoadingData6C518View1 < 8);
            }
        }
        return;
    }
}
#undef LoadingField


INCLUDE_RODATA("asm/nonmatchings/overlays/loading/loading4", D_loading_8007452C);
