#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "hud.h"
#include "libgpu.h"
#include "drawutil.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80074DEC.
* Assembly SHA256 1be8cb0fa050bb059a71ee6f6c8dec54394958588d906984195f806ec6229cd4.
* AI generated; not human reviewed. All544 original instructions and
* actual transfer/call targets are required. Frame0x58 retains every
* S0..S7/FP/RA save and SP10..2F local extent,including the four original
* rectangle halfwords. The buffer word is8017C000. Every retained global
* address phase,independent literal argument,reload,header branch and
* physical load/store order remains exact. Original wait-loop transfers
* and constants0xA4/0x3C/0xB4 are retained without timing interpretation.
* Three complete CRC loops retain polynomial0x8005,mask0x8000,eight bit
* steps,original variable/linear byte cursors and destructive16-bit masks.
* The block-local CRC accumulator has ordinary C allocation; the outer
* fixed GPR3 word is dead throughout this scope. Unsigned left shifts
* preserve native32-bit word bits. Original conditional code-memory stores
* through func8002A9D0/func8002A99C remain ordinary evidenced stores.
* Empty fully initialized dependencies/late consumers/dead clobbers emit0
* instructions. Tags identify scheduling sites,not retail addresses.
* No undefined register input,FP binding,live-alias overlap or opcode
* assembly. Confidence is binary identity after all gates. Raw units/fixed
* point,full helper contracts,caller cadence and synchronized runtime remain
* open. Cadence is per invocation. Falsification: every native/linked word,
* actual transfer target,full EXE and every overlay retail hash must match. */
#define Title74DECField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Title74DECCallCDLoadAsyncView1() __asm__("CDLoadAsync");
int Title74DECCallCDLoadSyncView1() __asm__("CDLoadSync");
int Title74DECCallCDLoadTimeView1() __asm__("CDLoadTime");
int Title74DECCallDrawSyncView1() __asm__("DrawSync");
int Title74DECCallLoadImageView1() __asm__("LoadImage");
int Title74DECCallPlaySoundView1() __asm__("PlaySound");
int Title74DECCallVSyncView1() __asm__("VSync");
int Title74DECClearTwoDisplayRegionsView1() __asm__("func_8001EBAC");
int Title74DECConfigureDrawBufferRangesView1() __asm__("func_8001FB10");
int Title74DECInitializeDisplayBufferPairView1() __asm__("func_80020168");
int Title74DECInitializePadAndVSyncCallbackView1() __asm__("func_8002A9D0");
int Title74DECReloadResourceArenaAndResetPlayerView1() __asm__("func_8002AE00");
int Title74DECApplyPendingTripletOffsetsView1() __asm__("func_8002B6C8");
int Title74DECInitializeParticleAndEffectPoolsView1() __asm__("func_8002B768");
int Title74DECInitializeLevelSceneView1() __asm__("func_8002B810");
int Title74DECFillWordRangeView1() __asm__("func_8004E790");
int Title74DECCopyWordRangeUnrolled4View1() __asm__("func_8004E7D4");
int Title74DECSetSpuTransferAddressView1() __asm__("func_80064A2C");
int Title74DECWriteSpuTransferDataView1() __asm__("func_80064A8C");
int Title74DECCheckSpuTransferCompletionView1() __asm__("func_80064AEC");
int Title74DECCall78848View1() __asm__("func_title_80078848");
int Title74DECCall79744View1() __asm__("func_title_80079744");
int Title74DECCall79D30View1() __asm__("func_title_80079D30");
int Title74DECCall79FE0View1() __asm__("func_title_80079FE0");
int Title74DECCall7C1F8View1() __asm__("func_title_8007C1F8");
int Title74DECCall7D6B4View1() __asm__("func_title_8007D6B4");
int Title74DECCallrandView1() __asm__("rand");
extern int Title74DECData11254View1 __asm__("D_80011254");
extern int Title74DECData6C3F8View1 __asm__("D_8006C3F8");
extern int Title74DECData6C3FCView1 __asm__("D_8006C3FC");
extern int Title74DECData6C534View1 __asm__("D_8006C534");
extern int Title74DECData6C554View1 __asm__("D_8006C554");
extern int Title74DECData6C598View1 __asm__("D_8006C598");
extern int Title74DECData6C6A0View1 __asm__("D_8006C6A0");
extern int Title74DECData6C714View1 __asm__("D_8006C714");
extern int Title74DECData6C7E0View1 __asm__("D_8006C7E0");
extern int Title74DECData6D074View1 __asm__("D_8006D074");
extern int Title74DECData6D8D8View1 __asm__("D_8006D8D8");
extern int Title74DECData6D8E8View1 __asm__("D_8006D8E8");
extern int Title74DECData6D908View1 __asm__("D_8006D908");
extern int Title74DECData6E344View1 __asm__("D_8006E344");
extern int Title74DECData6E470View1 __asm__("D_8006E470");
extern int Title74DECData6E4ACView1 __asm__("D_8006E4AC");
extern int Title74DECData6EDD8View1 __asm__("D_8006EDD8");
extern int Title74DECData6EDDCView1 __asm__("D_8006EDDC");
extern int Title74DECData6EDE0View1 __asm__("D_8006EDE0");
extern int Title74DECData6EDF0View1 __asm__("D_8006EDF0");
extern int Title74DECData6EDF4View1 __asm__("D_8006EDF4");
extern int Title74DECData6EE14View1 __asm__("D_8006EE14");
extern signed char Title74DECData6FC15View1 __asm__("D_8006FC15");
extern signed char Title74DECData6FC16View1 __asm__("D_8006FC16");
extern signed char Title74DECData6FC17View1 __asm__("D_8006FC17");
extern signed char Title74DECData6FC89View1 __asm__("D_8006FC89");
extern signed char Title74DECData6FC8AView1 __asm__("D_8006FC8A");
extern signed char Title74DECData6FC8BView1 __asm__("D_8006FC8B");
extern int Title74DECData70328View1 __asm__("D_80070328");
extern int Title74DECData72098View1 __asm__("D_80072098");
extern int Title74DECData7209CView1 __asm__("D_8007209C");
extern int Title74DECData720A0View1 __asm__("D_800720A0");
extern int Title74DECData720A4View1 __asm__("D_800720A4");
extern int Title74DECData720B0View1 __asm__("D_800720B0");
extern int Title74DECData720B4View1 __asm__("D_800720B4");
extern int Title74DECData722BCView1 __asm__("D_800722BC");
extern int Title74DECData722C0View1 __asm__("D_800722C0");
extern int Title74DECData722C4View1 __asm__("D_800722C4");
extern int Title74DECData722C8View1 __asm__("D_800722C8");
extern int Title74DECData722D0View1 __asm__("D_800722D0");
extern int Title74DECData725E0View1 __asm__("D_800725E0");
extern signed char Title74DECData7F12DView1 __asm__("D_title_8007F12D");
extern signed char Title74DECData7F12EView1 __asm__("D_title_8007F12E");
extern signed char Title74DECData7F130View1 __asm__("D_title_8007F130");
extern int Title74DECData7F134View1 __asm__("D_title_8007F134");
extern int Title74DECData7F138View1 __asm__("D_title_8007F138");
extern int Title74DECCall2A99CView1 __asm__("func_8002A99C");
extern unsigned char Title74DECDatamain_TEXT_ENDView1 __asm__("main_TEXT_END");
extern unsigned char Title74DECDatamain_TEXT_STARTView1 __asm__("main_TEXT_START");
extern unsigned char Title74DECDatatitle_text_endView1 __asm__("title_text_end");
extern unsigned char Title74DECDatatitle_text_startView1 __asm__("title_text_start");
void func_title_80074DEC(int input) {
    register int incomingMode22 __asm__("$22"), retainedLoadWord19 __asm__("$19"),
        retainedLoadWord23 __asm__("$23"), retainedSyncWord21 __asm__("$21");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    int retainedThirdLoadWord;
    register int retainedWord16 __asm__("$16"), retainedAddress17 __asm__("$17"),
        retainedSizeAddress18 __asm__("$18"), loadBufferAddress20 __asm__("$20");
    struct {
        short sp10, sp12, sp14, sp16;
        int sp18, sp1C, sp20, sp24, sp28, sp2C;
    } originalFrame;
    int firstPackedSource5;
    int temporaryWord1;
    int temporaryWord2;
    unsigned char* variableStepCodeCursor;
    unsigned char* mainCodeCursor;
    unsigned char* titleCodeCursor;
    incomingMode22 = input;
    MATCHING_KEEP(incomingMode22);
    retainedLoadWord19 = 0;
    retainedLoadWord23 = 0;
    retainedThirdLoadWord = 0;
    retainedSyncWord21 = 0;
    Title74DECConfigureDrawBufferRangesView1(0x1C000);
    loadBufferAddress20 = 0x8017C000;
    Title74DECData6C3F8View1 = 0xA;
    Title74DECData6C3FCView1 = 0xA;
    Title74DECData6E4ACView1 = 0x5FFF;
    if (incomingMode22 != 0) {
        argumentWord5 = 0x80170000;
        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(argumentWord5, "$16");
        retainedWord16 = (int)((unsigned char*)&Title74DECData6D8D8View1 + 0x14);
        MATCHING_KEEP(retainedWord16);
        Title74DECCallCDLoadSyncView1(Title74DECData6E470View1, argumentWord5 | 0xC000,
                                      Title74DECField(retainedWord16, int*, 0),
                                      Title74DECData6D8E8View1);
        retainedLoadWord19 = Title74DECField(retainedWord16, int*, 0);
        retainedSyncWord21 = Title74DECCallVSyncView1(-1);
        Title74DECCall78848View1(0x8017C000, loadBufferAddress20 + retainedLoadWord19, 0x78);
        Title74DECCall7D6B4View1(0);
        Title74DECInitializePadAndVSyncCallbackView1();
        Title74DECCall7C1F8View1();
        Title74DECReloadResourceArenaAndResetPlayerView1();
    } else {
        Title74DECCall7C1F8View1();
    }
    if ((incomingMode22 != 0) || (Title74DECData6E344View1 == 9)) {
        retainedWord16 = (int)&Title74DECData6E470View1;
        retainedAddress17 = (int)((unsigned char*)&Title74DECData6D8D8View1 + 0x1C);
        MATCHING_KEEP2(retainedWord16, retainedAddress17);
        Title74DECCallCDLoadSyncView1(Title74DECField(retainedWord16, int*, 0), loadBufferAddress20,
                                      Title74DECField(retainedAddress17, int*, 0),
                                      Title74DECField(&Title74DECData6D8D8View1, int*, 0x18));
        retainedLoadWord19 = Title74DECField(retainedAddress17, int*, 0);
        retainedAddress17 = loadBufferAddress20 + retainedLoadWord19;
        Title74DECCallCDLoadSyncView1(Title74DECField(retainedWord16, int*, 0), retainedAddress17,
                                      Title74DECField(&Title74DECData6D8D8View1, int*, 0x24),
                                      Title74DECField(&Title74DECData6D8D8View1, int*, 0x20));
        retainedLoadWord23 = Title74DECField(&Title74DECData6D8D8View1, int*, 0x24);
        Title74DECCallCDLoadSyncView1(Title74DECField(retainedWord16, int*, 0),
                                      retainedAddress17 + retainedLoadWord23,
                                      Title74DECField(&Title74DECData6D8D8View1, int*, 0x2C),
                                      Title74DECField(&Title74DECData6D8D8View1, int*, 0x28));
        retainedThirdLoadWord = Title74DECField(&Title74DECData6D8D8View1, int*, 0x2C);
    }
    firstPackedSource5 = Title74DECData11254View1 + Title74DECData6C714View1;
    Title74DECData722BCView1 = firstPackedSource5;
    Title74DECData722C0View1 = firstPackedSource5;
    Title74DECCallCDLoadAsyncView1(Title74DECData6E470View1, firstPackedSource5, 0x800,
                                   Title74DECData6D908View1);
    if (incomingMode22 != 0) {
    waitFirstSyncThreshold:
        if ((Title74DECCallVSyncView1(-1) - retainedSyncWord21) < 0xA4) {
            Title74DECCallVSyncView1(0);
            goto waitFirstSyncThreshold;
        }
        Title74DECInitializeDisplayBufferPairView1();
        Title74DECClearTwoDisplayRegionsView1();
        Title74DECCallVSyncView1(4);
        if (incomingMode22 != 0) {
            retainedSyncWord21 = Title74DECCallVSyncView1(-1);
            Title74DECCall78848View1(loadBufferAddress20,
                                     loadBufferAddress20 + retainedLoadWord19 + retainedLoadWord23 +
                                         retainedThirdLoadWord,
                                     0x58);
        }
    }
    do {
    } while (Title74DECCallCDLoadTimeView1() != 0);
    retainedWord16 = (int)&Title74DECData72098View1;
    MATCHING_KEEP(retainedWord16);
    argumentWord4 = retainedWord16;
    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
    retainedAddress17 = (int)&Title74DECData722C0View1;
    MATCHING_KEEP(retainedAddress17);
    Title74DECCopyWordRangeUnrolled4View1(argumentWord4,
                                          Title74DECField(retainedAddress17, int*, 0), 0x220);
    Title74DECCallCDLoadAsyncView1(
        Title74DECData6E470View1, Title74DECField(retainedAddress17, int*, 0), 0x80000,
        Title74DECField(retainedWord16, int*, 0) + Title74DECData6D908View1);
    if ((incomingMode22 != 0) || (Title74DECData6E344View1 == 9)) {
    waitSecondSyncThreshold:
        rawWord2 = Title74DECCallVSyncView1(-1) - retainedSyncWord21;
        rawWord2 = rawWord2 < 60;
        argumentWord4 = loadBufferAddress20 + retainedLoadWord19;
        if (rawWord2) {
            Title74DECCallVSyncView1(0);
            goto waitSecondSyncThreshold;
        }
        Title74DECCall78848View1(argumentWord4,
                                 argumentWord4 + retainedLoadWord23 + retainedThirdLoadWord, 0xC4);
    }
    do {
    } while (Title74DECCallCDLoadTimeView1() != 0);
    argumentWord4 = (int)&originalFrame.sp10;
    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$17");
    retainedAddress17 = (int)&Title74DECData722C0View1;
    MATCHING_KEEP(retainedAddress17);
    argumentWord5 = Title74DECField(retainedAddress17, int*, 0);
    rawWord2 = 512;
    originalFrame.sp10 = rawWord2;
    originalFrame.sp12 = 0;
    originalFrame.sp14 = rawWord2;
    originalFrame.sp16 = rawWord2;
    Title74DECCallLoadImageView1(argumentWord4, argumentWord5);
    Title74DECCallDrawSyncView1(0);
    retainedSizeAddress18 = (int)&Title74DECData7209CView1;
    MATCHING_KEEP(retainedSizeAddress18);
    rawWord3 = 0xFFF80000;
    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(rawWord3, "$16");
    retainedWord16 = 0x80000;
    argumentWord4 = Title74DECData6E470View1;
    argumentWord5 = Title74DECField(retainedAddress17, int*, 0);
    argumentWord6 = Title74DECField(retainedSizeAddress18, int*, 0);
    argumentWord7 = Title74DECData72098View1;
    rawWord2 = Title74DECData6D908View1;
    argumentWord6 += rawWord3;
    argumentWord7 += rawWord2;
    argumentWord7 += retainedWord16;
    Title74DECCallCDLoadSyncView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
    Title74DECSetSpuTransferAddressView1(0x1010);
    Title74DECWriteSpuTransferDataView1(Title74DECField(retainedAddress17, int*, 0),
                                        Title74DECField(retainedSizeAddress18, int*, 0) -
                                            retainedWord16);
    do {
    } while (Title74DECCheckSpuTransferCompletionView1(0) == 0);
    MATCHING_KEEP(retainedAddress17);
    retainedWord16 = (int)&Title74DECData722C0View1;
    MATCHING_KEEP(retainedWord16);
    Title74DECCallCDLoadSyncView1(
        Title74DECData6E470View1, Title74DECField(retainedWord16, int*, 0),
        Title74DECData720A4View1, Title74DECData720A0View1 + Title74DECData6D908View1);
    Title74DECData722C8View1 = Title74DECCall79744View1(Title74DECField(retainedWord16, int*, 0));
    Title74DECApplyPendingTripletOffsetsView1();
    if (incomingMode22 != 0) {
    waitThirdSyncThreshold:
        if ((Title74DECCallVSyncView1(-1) - retainedSyncWord21) < 0xB4) {
            Title74DECCallVSyncView1(0);
            goto waitThirdSyncThreshold;
        }
        Title74DECInitializeDisplayBufferPairView1();
        Title74DECClearTwoDisplayRegionsView1();
        Title74DECCallVSyncView1(4);
        if (incomingMode22 != 0) {
            retainedSyncWord21 = Title74DECCallVSyncView1(-1);
            temporaryWord1 = loadBufferAddress20 + retainedLoadWord19 + retainedLoadWord23;
            Title74DECCall78848View1(temporaryWord1, temporaryWord1 + retainedThirdLoadWord, 0x78);
        }
    }
    retainedAddress17 = (int)&Title74DECData6E470View1;
    retainedWord16 = (int)&Title74DECData722C8View1;
    MATCHING_KEEP2(retainedAddress17, retainedWord16);
    Title74DECCallCDLoadSyncView1(
        Title74DECField(retainedAddress17, int*, 0), Title74DECField(retainedWord16, int*, 0),
        Title74DECData720B4View1, Title74DECData720B0View1 + Title74DECData6D908View1);
    rawWord2 = Title74DECInitializeLevelSceneView1(Title74DECField(retainedWord16, int*, 0));
    argumentWord4 = Title74DECField(retainedAddress17, int*, 0);
    argumentWord6 = Title74DECField(&Title74DECData6D8D8View1, int*, 0x44);
    argumentWord7 = Title74DECField(&Title74DECData6D8D8View1, int*, 0x40);
    argumentWord5 = rawWord2;
    Title74DECData722C4View1 = argumentWord5;
    Title74DECCallCDLoadSyncView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
    argumentWord5 = 0;
    argumentWord4 = Title74DECData722C4View1;
    MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(argumentWord4, argumentWord5, "$16");
    retainedWord16 = (int)&Title74DECData6EDD8View1;
    MATCHING_KEEP(retainedWord16);
    Title74DECField(retainedWord16, int*, 0) = 0;
    Title74DECField(retainedWord16, int*, -4) = 0;
    Title74DECCall79D30View1(argumentWord4, argumentWord5);
    if (incomingMode22 != 0) {
        Title74DECField(retainedWord16, int*, 4) = -2;
    } else {
        Title74DECData6EDDCView1 = 0x296;
        Title74DECData6C598View1 = 0xF0;
    }
    MATCHING_KEEP(retainedWord16);
    retainedWord16 = (int)&Title74DECData6EDE0View1;
    MATCHING_KEEP(retainedWord16);
    argumentWord4 = Title74DECData722D0View1;
    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(argumentWord4, "$2");
    rawWord2 = 2;
    Title74DECField(retainedWord16, int*, 0) = rawWord2;
    Title74DECData6FC15View1 = 0;
    Title74DECData6FC16View1 = 0;
    Title74DECData6FC17View1 = 0;
    Title74DECData6FC89View1 = 0;
    Title74DECData6FC8AView1 = 0;
    Title74DECData6FC8BView1 = 0;
    Title74DECInitializeParticleAndEffectPoolsView1(argumentWord4 - 0x2004);
    temporaryWord2 = Title74DECData6C554View1 - 0x1000;
    Title74DECData6C7E0View1 = temporaryWord2;
    Title74DECFillWordRangeView1(temporaryWord2, 0, 0x1000);
    Title74DECCopyWordRangeUnrolled4View1(retainedWord16 + 0x38, Title74DECData6C6A0View1, 0x14);
    if (incomingMode22) {
        rawWord3 = 131072;
        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(rawWord3, "$2");
        rawWord2 = Title74DECData6C6A0View1;
        __asm__ __volatile__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2), "i"(544901));
        rawWord3 |= 4112;
        goto storeSelectedHeaderWord;
    }
    rawWord3 = 262144;
    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(rawWord3, "$2");
    rawWord2 = Title74DECData6C6A0View1;
    __asm__ __volatile__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2), "i"(544902));
    rawWord3 |= 9687;
storeSelectedHeaderWord:
    Title74DECField(rawWord2, int*, 0) = rawWord3;
    __asm__ __volatile__("" ::"m"(Title74DECField(rawWord2, int*, 0)) : "$4", "$5", "$6", "memory");
    argumentWord4 = 0;
    argumentWord5 = 0;
    argumentWord6 = 0;
    __asm__ __volatile__("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                         : "$3", "$2");
    rawWord3 = Title74DECData6C6A0View1;
    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(rawWord3, "$2");
    rawWord2 = 0x2FFF;
    Title74DECField(rawWord3, short*, 6) = rawWord2;
    rawWord2 = 0x800;
    Title74DECField(rawWord3, short*, 12) = rawWord2;
    Title74DECField(rawWord3, short*, 14) = rawWord2;
    Title74DECData6EE14View1 =
        Title74DECCallPlaySoundView1(argumentWord4, argumentWord5, argumentWord6);
    Title74DECField(&Title74DECData70328View1, int*, 0x288) = 1;
    retainedWord16 = 0;
    rawWord3 = Title74DECData6EDF0View1;
    if (rawWord3 > 0) {
        MATCHING_KEEP_GNU_VOLATILE(retainedWord16);
        argumentWord5 = retainedWord16;
        do {
            rawWord3 = Title74DECData6EDF4View1;
            rawWord2 = retainedWord16 << 2;
            rawWord2 += rawWord3;
            rawWord3 = Title74DECData722C4View1;
            argumentWord4 = Title74DECField(rawWord2, int*, 0);
            argumentWord6 = 0;
            argumentWord4 = rawWord3 + argumentWord4;
            Title74DECCall79FE0View1(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 = Title74DECData6EDF0View1;
            __asm__ __volatile__("" : "=r"(retainedWord16) : "0"(retainedWord16), "r"(rawWord2));
            retainedWord16 += 1;
            rawWord2 = retainedWord16 < rawWord2;
            argumentWord5 = retainedWord16;
        } while (rawWord2);
    }
    Title74DECData6D074View1 = 0x18000;
    {
        int crcAccumulator;
        variableStepCodeCursor = &Title74DECDatatitle_text_startView1;
        argumentWord6 = (int)&Title74DECDatatitle_text_endView1;
        rawWord2 = (unsigned int)variableStepCodeCursor < (unsigned int)argumentWord6;
        crcAccumulator = 0;
        if (rawWord2) {
            do {
                argumentWord4 = 7;
                crcAccumulator ^= *variableStepCodeCursor << 8;
            stepVariableCursorBits:
                if (crcAccumulator & 0x8000) {
                    crcAccumulator = ((unsigned int)crcAccumulator << 1) ^ 0x8005;
                } else {
                    crcAccumulator = (unsigned int)crcAccumulator << 1;
                }
                argumentWord4 -= 1;
                if (argumentWord4 >= 0) {
                    goto stepVariableCursorBits;
                }
                rawWord2 = crcAccumulator & 3;
                rawWord2 += 1;
                variableStepCodeCursor += rawWord2;
            } while ((unsigned int)variableStepCodeCursor < (unsigned int)argumentWord6);
        }
        mainCodeCursor = &Title74DECDatamain_TEXT_STARTView1;
        rawWord2 = (int)&Title74DECDatamain_TEXT_ENDView1;
        argumentWord7 = rawWord2 - (int)mainCodeCursor;
        argumentWord6 = 0;
        if (argumentWord7 > 0) {
            do {
                argumentWord4 = 7;
                crcAccumulator ^= *mainCodeCursor << 8;
            stepMainCodeBits:
                if (crcAccumulator & 0x8000) {
                    crcAccumulator = ((unsigned int)crcAccumulator << 1) ^ 0x8005;
                } else {
                    crcAccumulator = (unsigned int)crcAccumulator << 1;
                }
                argumentWord4 -= 1;
                if (argumentWord4 >= 0) {
                    goto stepMainCodeBits;
                }
                argumentWord6 += 1;
                mainCodeCursor += 1;
            } while (argumentWord6 < argumentWord7);
        }
        crcAccumulator &= 65535;
        if (crcAccumulator) {
            Title74DECField((unsigned char*)Title74DECInitializePadAndVSyncCallbackView1, int*,
                            (Title74DECCallrandView1() & 31) * 4) = 0;
        }
        titleCodeCursor = &Title74DECDatatitle_text_startView1;
        rawWord2 = (int)&Title74DECDatatitle_text_endView1;
        argumentWord7 = rawWord2 - (int)titleCodeCursor;
        argumentWord6 = 0;
        crcAccumulator = 0;
        if (argumentWord7 > 0) {
            do {
                argumentWord4 = 7;
                crcAccumulator ^= *titleCodeCursor << 8;
            stepTitleCodeBits:
                if (crcAccumulator & 0x8000) {
                    crcAccumulator = ((unsigned int)crcAccumulator << 1) ^ 0x8005;
                } else {
                    crcAccumulator = (unsigned int)crcAccumulator << 1;
                }
                argumentWord4 -= 1;
                if (argumentWord4 >= 0) {
                    goto stepTitleCodeBits;
                }
                argumentWord6 += 1;
                titleCodeCursor += 1;
            } while (argumentWord6 < argumentWord7);
        }
        crcAccumulator &= 65535;
        if (crcAccumulator) {
            Title74DECField(&Title74DECCall2A99CView1, int*, (Title74DECCallrandView1() & 63) * 4) =
                0;
        }
    }
    if (incomingMode22 != 0) {
    waitFinalSyncThreshold:
        if ((Title74DECCallVSyncView1(-1) - retainedSyncWord21) < 0xB4) {
            Title74DECCallVSyncView1(0);
            goto waitFinalSyncThreshold;
        }
    }
    rawWord2 = (int)&Title74DECData7F134View1;
    MATCHING_KEEP(rawWord2);
    Title74DECField(rawWord2, int*, 0) = 0;
    Title74DECData7F138View1 = 0;
    Title74DECField(rawWord2, signed char*, -8) = 0;
    Title74DECData7F12EView1 = 0;
    Title74DECData7F130View1 = 0;
    Title74DECData7F12DView1 = 0;
    Title74DECField(rawWord2, signed char*, -5) = 0;
    Title74DECField(rawWord2, signed char*, -3) = 0;
    Title74DECField(rawWord2, signed char*, -2) = 0;
    Title74DECData725E0View1 = -1;
    Title74DECData6C534View1 = 0;
}
#undef Title74DECField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI-generated reconstruction; not human reviewed.
 * SCUS-94467 USA Rev0, title8007566C:2390 original native words,
 * 69 selector words and one zero padding word; original frame56 bytes.
 * Original assembly: asm/nonmatchings/overlays/title/title1/func_title_8007566C.s
 * Names retain raw storage/register roles where semantic meaning is unresolved.
 * Helpers retain identified original o32 word arities and complete return words.
 * Empty metadata observes initialized whole values and exact original selector
 * or next-address contexts; it supplies no CPU instructions. Its source shape
 * preserves original CFG joins and cannot be removed without re-verification.
 * The full counter product is initialized before its compiler-endian high-word
 * projection; raw arithmetic widths, signed shifts and original order remain.
 * Reserved SP18..1F is neither read, written, addressed nor observed.
 * Native identity does not establish complete helper/asset meaning, physical
 * units, update cadence or end-to-end synchronized retail runtime behavior.
 * Acceptance requires all native/linked words, actual targets, selector/data
 * values and complete executable/every-overlay hashes. No human review claimed.
 */
#define TitleMenu7566CKeep(v) __asm__("" : "=r"(v) : "0"(v))
#define TitleMenu7566CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int TitleMenu7566C_PlaySound(int originalWord1, int originalWord2,
                             int originalWord3) __asm__("PlaySound");
void TitleMenu7566CInitializeDisplayBufferPair(void) __asm__("func_80020168");
int TitleMenu7566CFindHudClassIndex(int originalWord1) __asm__("func_80027934");
int TitleMenu7566CPlaySoundFromGlobalByteTable(int originalWord1, int originalWord2,
                                               int originalWord3) __asm__("func_8003BB10");
void TitleMenu7566CTransitionUnmaskedSoundSlots(void) __asm__("func_8003BEDC");
void TitleMenu7566CUpdateSoundVoiceSlots(void) __asm__("func_8003C184");
void TitleMenu7566CFillWordRange(int originalWord1, int originalWord2,
                                 int originalWord3) __asm__("func_8004E790");
void TitleMenu7566CCopyWordRangeUnrolled4(int originalWord1, int originalWord2,
                                          int originalWord3) __asm__("func_8004E7D4");
void TitleMenu7566CConfigurePrimaryRangeRequest(int originalWord1, int originalWord2,
                                                int originalWord3) __asm__("func_8004F984");
void TitleMenu7566CBeginLevelWarp(int originalWord1, int originalWord2) __asm__("func_800584BC");
void TitleMenu7566CIssueCdControlCommand(int originalWord1, int originalWord2,
                                         int originalWord3) __asm__("func_8005E0BC");
void TitleMenu7566C_func_title_80078918(void) __asm__("func_title_80078918");
void TitleMenu7566C_func_title_80078B88(void) __asm__("func_title_80078B88");
int TitleMenu7566C_func_title_80078BF4(int originalWord1) __asm__("func_title_80078BF4");
void TitleMenu7566C_func_title_80078C1C(int originalWord1,
                                        int originalWord2) __asm__("func_title_80078C1C");
void TitleMenu7566C_func_title_80078EAC(int originalWord1) __asm__("func_title_80078EAC");
int TitleMenu7566C_func_title_8007928C(int originalWord1) __asm__("func_title_8007928C");
int TitleMenu7566C_func_title_800793C8(void) __asm__("func_title_800793C8");
void TitleMenu7566C_func_title_80079B94(void) __asm__("func_title_80079B94");
void TitleMenu7566C_func_title_8007A1C0(void) __asm__("func_title_8007A1C0");
int TitleMenu7566C_func_title_8007AD80(void) __asm__("func_title_8007AD80");
int TitleMenu7566C_func_title_8007AF44(int originalWord1) __asm__("func_title_8007AF44");
void TitleMenu7566C_func_title_8007C268(void) __asm__("func_title_8007C268");
int TitleMenu7566C_func_title_8007C62C(int originalWord1) __asm__("func_title_8007C62C");
void TitleMenu7566C_func_title_8007C93C(void) __asm__("func_title_8007C93C");
void TitleMenu7566C_func_title_8007CD68(int originalWord1, int originalWord2, int originalWord3,
                                        int originalWord4,
                                        int originalWord5) __asm__("func_title_8007CD68");
void TitleMenu7566C_func_title_8007CFC0(int originalWord1, int originalWord2, int originalWord3,
                                        int originalWord4,
                                        int originalWord5) __asm__("func_title_8007CFC0");
int TitleMenu7566C_func_title_8007D218(int originalWord1, int originalWord2,
                                       int originalWord3) __asm__("func_title_8007D218");
int TitleMenu7566C_func_title_8007D334(int originalWord1, int originalWord2,
                                       int originalWord3) __asm__("func_title_8007D334");
int TitleMenu7566C_func_title_8007D430(int originalWord1) __asm__("func_title_8007D430");
extern int TitleMenu7566C_D_800652B0 __asm__("D_800652B0");
extern int TitleMenu7566C_D_800652B4 __asm__("D_800652B4");
extern int TitleMenu7566C_D_800652B6 __asm__("D_800652B6");
extern unsigned char TitleMenu7566C_D_80066EDC __asm__("D_80066EDC");
extern unsigned char TitleMenu7566C_D_80066EE4 __asm__("D_80066EE4");
extern int TitleMenu7566C_D_8006C3F0 __asm__("D_8006C3F0");
extern int TitleMenu7566C_D_8006C3F4 __asm__("D_8006C3F4");
extern int TitleMenu7566C_D_8006C534 __asm__("D_8006C534");
extern int TitleMenu7566C_D_8006C538 __asm__("D_8006C538");
extern int TitleMenu7566C_D_8006C55C __asm__("D_8006C55C");
extern int TitleMenu7566C_D_8006C598 __asm__("D_8006C598");
extern int TitleMenu7566C_D_8006C5BC __asm__("D_8006C5BC");
extern int TitleMenu7566C_D_8006C5C0 __asm__("D_8006C5C0");
extern int TitleMenu7566C_D_8006C5C8 __asm__("D_8006C5C8");
extern int TitleMenu7566C_D_8006C648 __asm__("D_8006C648");
extern int TitleMenu7566C_D_8006C654 __asm__("D_8006C654");
extern int TitleMenu7566C_D_8006C658 __asm__("D_8006C658");
extern int TitleMenu7566C_D_8006C694 __asm__("D_8006C694");
extern int TitleMenu7566C_D_8006C698 __asm__("D_8006C698");
extern int TitleMenu7566C_D_8006C6A0 __asm__("D_8006C6A0");
extern int TitleMenu7566C_D_8006C734 __asm__("D_8006C734");
extern int TitleMenu7566C_D_8006C738 __asm__("D_8006C738");
extern int TitleMenu7566C_D_8006C76C __asm__("D_8006C76C");
extern int TitleMenu7566C_D_8006C7B8 __asm__("D_8006C7B8");
extern int TitleMenu7566C_D_8006C7C4 __asm__("D_8006C7C4");
extern int TitleMenu7566C_D_8006C7E4 __asm__("D_8006C7E4");
extern unsigned short TitleMenu7566C_D_8006E03E __asm__("D_8006E03E");
extern unsigned short TitleMenu7566C_D_8006E040 __asm__("D_8006E040");
extern int TitleMenu7566C_D_8006E4B4 __asm__("D_8006E4B4");
extern int TitleMenu7566C_D_8006E538 __asm__("D_8006E538");
extern int TitleMenu7566C_D_8006E53C __asm__("D_8006E53C");
extern int TitleMenu7566C_D_8006EDDC __asm__("D_8006EDDC");
extern int TitleMenu7566C_D_8006EDE0 __asm__("D_8006EDE0");
extern int TitleMenu7566C_D_8006EDE4 __asm__("D_8006EDE4");
extern int TitleMenu7566C_D_8006EDF4 __asm__("D_8006EDF4");
extern int TitleMenu7566C_D_8006EE14 __asm__("D_8006EE14");
extern int TitleMenu7566C_D_8006FA2C __asm__("D_8006FA2C");
extern int TitleMenu7566C_D_8006FA30 __asm__("D_8006FA30");
extern int TitleMenu7566C_D_8006FA34 __asm__("D_8006FA34");
extern int TitleMenu7566C_D_8006FA40 __asm__("D_8006FA40");
extern int TitleMenu7566C_D_8006FA48 __asm__("D_8006FA48");
extern int TitleMenu7566C_D_8006FA4C __asm__("D_8006FA4C");
extern int TitleMenu7566C_D_8006FA50 __asm__("D_8006FA50");
extern int TitleMenu7566C_D_8006FA54 __asm__("D_8006FA54");
extern short TitleMenu7566C_D_8006FC60 __asm__("D_8006FC60");
extern short TitleMenu7566C_D_8006FC62 __asm__("D_8006FC62");
extern short TitleMenu7566C_D_8006FCD4 __asm__("D_8006FCD4");
extern short TitleMenu7566C_D_8006FCD6 __asm__("D_8006FCD6");
extern signed char TitleMenu7566C_D_80071FB0 __asm__("D_80071FB0");
extern int TitleMenu7566C_D_800722C4 __asm__("D_800722C4");
extern int TitleMenu7566C_D_800725B0 __asm__("D_800725B0");
extern int TitleMenu7566C_D_800725B4 __asm__("D_800725B4");
extern int TitleMenu7566C_D_800725B8 __asm__("D_800725B8");
extern int TitleMenu7566C_D_800725BC __asm__("D_800725BC");
extern int TitleMenu7566C_D_800725C0 __asm__("D_800725C0");
extern int TitleMenu7566C_D_800725C4 __asm__("D_800725C4");
extern int TitleMenu7566C_D_800725C8 __asm__("D_800725C8");
extern int TitleMenu7566C_D_800725CC __asm__("D_800725CC");
extern int TitleMenu7566C_D_800725D0 __asm__("D_800725D0");
extern int TitleMenu7566C_D_800725D4 __asm__("D_800725D4");
extern int TitleMenu7566C_D_800725D8 __asm__("D_800725D8");
extern int TitleMenu7566C_D_800725E0 __asm__("D_800725E0");
extern int TitleMenu7566C_D_800725E4 __asm__("D_800725E4");
extern int TitleMenu7566C_D_800725E8 __asm__("D_800725E8");
extern int TitleMenu7566C_D_title_8007EC9C __asm__("D_title_8007EC9C");
extern int TitleMenu7566C_D_title_8007ECA0 __asm__("D_title_8007ECA0");
extern unsigned char TitleMenu7566C_D_title_8007F12C __asm__("D_title_8007F12C");
extern unsigned char TitleMenu7566C_D_title_8007F12D __asm__("D_title_8007F12D");
extern unsigned char TitleMenu7566C_D_title_8007F12E __asm__("D_title_8007F12E");
extern unsigned char TitleMenu7566C_D_title_8007F12F __asm__("D_title_8007F12F");
extern unsigned char TitleMenu7566C_D_title_8007F130 __asm__("D_title_8007F130");
extern unsigned char TitleMenu7566C_D_title_8007F131 __asm__("D_title_8007F131");
extern unsigned char TitleMenu7566C_D_title_8007F132 __asm__("D_title_8007F132");
extern unsigned char TitleMenu7566C_D_title_8007F133 __asm__("D_title_8007F133");
extern int TitleMenu7566C_D_title_8007F134 __asm__("D_title_8007F134");
extern int TitleMenu7566C_D_title_8007F138 __asm__("D_title_8007F138");
extern short TitleMenu7566C_D_title_8007F13C __asm__("D_title_8007F13C");
extern unsigned char TitleMenu7566C_D_title_8007F13E __asm__("D_title_8007F13E");
extern unsigned char TitleMenu7566C_D_title_8007F13F __asm__("D_title_8007F13F");
extern signed char TitleMenu7566C_D_title_8007F154 __asm__("D_title_8007F154");
extern signed char TitleMenu7566C_D_title_8007F354 __asm__("D_title_8007F354");
extern unsigned char TitleMenu7566C_D_title_8007F355 __asm__("D_title_8007F355");
extern signed char TitleMenu7566C_D_title_8007F356 __asm__("D_title_8007F356");
extern unsigned char TitleMenu7566C_D_title_8007F357 __asm__("D_title_8007F357");
extern int TitleMenu7566C_D_title_8007F3D4 __asm__("D_title_8007F3D4");
extern unsigned char TitleMenu7566C_D_title_8007F3D8 __asm__("D_title_8007F3D8");
extern int TitleMenu7566C_D_title_8007FCD0 __asm__("D_title_8007FCD0");
extern signed char TitleMenu7566C_D_title_8007FCD8 __asm__("D_title_8007FCD8");
extern int TitleMenu7566C_D_title_800805D0 __asm__("D_title_800805D0");
extern signed char TitleMenu7566C_D_title_800805D8 __asm__("D_title_800805D8");
extern int TitleMenu7566C_D_title_80080ED0 __asm__("D_title_80080ED0");
extern int TitleMenu7566C_g_CheatFlags __asm__("g_CheatFlags");
void TitleMenu7566C_func_title_8007CD68Other(int originalWord1, int originalWord2,
                                             int originalWord3, int originalWord4,
                                             int originalWord5) __asm__("func_title_8007CD68");
/* Register-only full product view follows the frozen compiler endian order;
 * it is never a retail memory-layout claim or an addressed local object. */
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned low;
#else
        unsigned low;
        int high;
#endif
    } words;
} TitleMenu7566CProduct;
void func_title_8007566C(void) {
    TitleMenu7566CProduct counterProduct;
    register int workWord9 __asm__("$9");

int retainedOriginalRecordBase, indexedRecordAddress, temporaryWord4, temporaryWord5,
        temporaryWord6;

register int workWord8 __asm__("$8"), savedWord19 __asm__("$19");

register int resultWord __asm__("$2"), workWord __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        int reserved18, reserved1C;
    } originalUnusedFrame;

register int savedWord16 __asm__("$16"), savedWord17 __asm__("$17"), savedWord18 __asm__("$18");

    int var_a1_2;

    int temp_v0_10;

    int temp_v0_12;

    int temp_v0_14;

    int temp_v0_7;

    int temp_a1;

    int temp_a1_2;

    int var_a3;

    int var_v1_2;

    int temp_a0;

    int temp_a0_2;

    int temp_a3;

    int temp_a3_2;

    int temp_v0_16;

    int temp_v0_17;

    int temp_v0_18;

    int temp_v0_5;

    int temp_v1;

    int var_a0;

    int var_a0_2;

    int var_a0_3;

    int var_a0_4;

    int var_a1;

    int var_a1_3;

    int var_a2;

    int var_a2_2;

    int var_v0_6;

    int var_v0_7;

    int var_v0_8;

    int var_v1_3;

    int var_v1_4;

    int var_v1_5;

    int temp_a0_3;

    int temp_a0_4;

    int temp_v0;

    int temp_v0_11;

    int temp_v0_8;

    int temp_v1_2;

    int var_v0_4;

    int var_v0_5;

    int var_v0_9;

    int temp_v0_13;

    int temp_v0_15;

    argumentWord4 = (int)&TitleMenu7566C_D_8006EDDC;
    TitleMenu7566CKeep(argumentWord4);
    resultWord = TitleMenu7566CField(argumentWord4, int*, 0);
    argumentWord5 = TitleMenu7566C_D_8006C648;
    workWord = resultWord + argumentWord5;
    TitleMenu7566CField(argumentWord4, int*, 0) = workWord;
    if (workWord >= 0x654) {
        resultWord = workWord - 0x258;
        TitleMenu7566CField(argumentWord4, int*, 0) = resultWord;
    }
    TitleMenu7566CKeep(argumentWord4);
    workWord = TitleMenu7566CField(argumentWord4, int*, 0);
    resultWord = workWord < 0x4B0;
    if (resultWord) {
        resultWord = 0x88880000;
        goto titleCounterExtendMagic;
    }
    resultWord = 0x88880000;
    MATCHING_OBSERVE(resultWord);
    resultWord = workWord - argumentWord5;
    if (resultWord >= 0x4B0)
        goto titleCounterFullMagic;
    TitleMenu7566CPlaySoundFromGlobalByteTable(0, 9, 1);
titleCounterFullMagic:
    resultWord = 0x88880000;
titleCounterExtendMagic:
    argumentWord4 = TitleMenu7566C_D_8006EDDC;
    resultWord |= 0x8889;
    counterProduct.full = (long long)argumentWord4 * (long long)resultWord;
    __asm__("" : "=x"(counterProduct.full) : "0"(counterProduct.full));
    argumentWord5 = TitleMenu7566C_D_8006C598;
    workWord = argumentWord4 >> 31;
    workWord9 = counterProduct.words.high;
    TitleMenu7566CKeep(workWord9);
    resultWord = workWord9 + argumentWord4;
    resultWord = (resultWord >> 6) - workWord;
    workWord = resultWord * 120;
    argumentWord4 -= workWord;
    TitleMenu7566C_D_8006EDE0 = resultWord;
    TitleMenu7566C_D_8006EDE4 = argumentWord4;
    if (TitleMenu7566C_D_8006C598 == 0) {
        goto titleBlock10;
    }
    if (TitleMenu7566C_D_8006C598 >= 0x11) {
        goto titleBlock9;
    }
    TitleMenu7566C_D_8006C598 = 0;
    goto titleBlock10;
titleBlock9:
    TitleMenu7566C_D_8006C598 -= 0x10;
titleBlock10:
    argumentWord5 = (int)&TitleMenu7566C_D_8006EDE0;
    TitleMenu7566CKeep(argumentWord5);
    workWord = TitleMenu7566CField(argumentWord5, int*, 0);
    argumentWord5 += 0x28;
    resultWord = TitleMenu7566C_D_8006EDE0;
    argumentWord4 = TitleMenu7566C_D_8006EDF4;
    workWord = (workWord & 1) << 2;
    __asm__("" : "=r"(workWord) : "0"(workWord), "r"(resultWord), "r"(argumentWord4));
    resultWord = (resultWord << 2) + argumentWord4;
    argumentWord4 = TitleMenu7566C_D_800722C4;
    resultWord = TitleMenu7566CField(resultWord, int*, 0);
    workWord += argumentWord5;
    argumentWord4 += resultWord;
    TitleMenu7566CField(workWord, int*, 0) = argumentWord4;
    TitleMenu7566C_func_title_8007A1C0();
    workWord = TitleMenu7566C_D_8006EDDC;
    resultWord = workWord < 0x154;
    argumentWord5 = workWord - 0x154;
    if (!resultWord) {
        if (argumentWord5 >= 0x21)
            argumentWord5 = 0x20;
        argumentWord4 = (int)&TitleMenu7566C_D_8006E03E;
        TitleMenu7566CKeep(argumentWord4);
        resultWord = argumentWord5 * 0x30;
        workWord = TitleMenu7566CField(argumentWord4, unsigned short*, 0);
        __asm__("" : "=r"(resultWord) : "0"(resultWord), "r"(workWord));
        resultWord >>= 5;
        workWord -= resultWord;
        __asm__("" : "=r"(workWord) : "0"(workWord), "r"(resultWord));
        resultWord = argumentWord5 * 0x28;
        TitleMenu7566CField(argumentWord4, unsigned short*, 0) = workWord;
        workWord = TitleMenu7566C_D_8006E040;
        workWord += resultWord >> 5;
        TitleMenu7566C_D_8006E040 = workWord;
    }
    resultWord = TitleMenu7566C_D_8006C7B8 ? TitleMenu7566C_func_title_8007AF44(1) : 0;
    if (resultWord)
        goto titleBlock20;
    resultWord = TitleMenu7566C_D_8006EDDC;
    TitleMenu7566C_D_8006C7B8 = 0;
    if (resultWord < 0x1E1)
        goto titleBlock20;
    workWord = TitleMenu7566C_D_8006E4B4;
    resultWord = 1;
    if (workWord == resultWord)
        goto titleBlock20;
    TitleMenu7566CIssueCdControlCommand(0xC, 0, 0);
    temp_a0_2 = TitleMenu7566C_D_8006C3F4 +
                TitleMenu7566CField((int)&TitleMenu7566C_D_800652B0, int*, 0x90);
    TitleMenu7566CConfigurePrimaryRangeRequest(
        temp_a0_2,
        temp_a0_2 + TitleMenu7566CField((int)&TitleMenu7566C_D_800652B4, unsigned short*, 0x90),
        TitleMenu7566CField((int)&TitleMenu7566C_D_800652B6, unsigned short*, 0x90));
titleBlock20:
    if ((unsigned char)TitleMenu7566C_D_title_8007F12C >= 0x18U) {
        goto titleBlock391;
    }
    switch (TitleMenu7566C_D_title_8007F12C) {
        case 0:
            goto title2390_dispatch1_selector0;
        case 1:
            goto title2390_dispatch1_selector1;
        case 2:
            goto title2390_dispatch1_selector2;
        case 3:
            goto title2390_dispatch1_selector3;
        case 4:
            goto title2390_dispatch1_selector4;
        case 5:
            goto title2390_dispatch1_selector5;
        case 6:
            goto title2390_dispatch1_selector6;
        case 7:
            goto title2390_dispatch1_selector7;
        case 8:
            goto title2390_dispatch1_selector8;
        case 9:
            goto title2390_dispatch1_selector9;
        case 10:
            goto title2390_dispatch1_selector10;
        case 11:
            goto title2390_dispatch1_selector11;
        case 12:
            goto title2390_dispatch1_selector12;
        case 13:
            goto title2390_dispatch1_selector13;
        case 14:
            goto title2390_dispatch1_selector14;
        case 15:
            goto title2390_dispatch1_selector15;
        case 16:
            goto title2390_dispatch1_selector16;
        case 17:
            goto title2390_dispatch1_selector17;
        case 18:
            goto title2390_dispatch1_selector18;
        case 19:
            goto title2390_dispatch1_selector19;
        case 20:
            goto title2390_dispatch1_selector20;
        case 21:
            goto title2390_dispatch1_selector21;
        case 22:
            goto title2390_dispatch1_selector22;
        case 23:
            goto title2390_dispatch1_selector23;
        default:
            goto titleBlock391;
    }
title2390_dispatch1_selector0:
    if (TitleMenu7566C_func_title_8007D218(1, (int)&TitleMenu7566C_D_800725B0,
                                           (int)&TitleMenu7566C_D_800725B0 + 4) == 0) {
        goto titleBlock391;
    }
    if ((unsigned char)TitleMenu7566C_D_title_8007F12E >= 7U) {
        goto titleBlock391;
    }
    switch (TitleMenu7566C_D_title_8007F12E) {
        case 0:
            goto title2390_dispatch2_selector0;
        case 1:
            goto title2390_dispatch2_selector1;
        case 2:
            goto title2390_dispatch2_selector2;
        case 3:
            goto title2390_dispatch2_selector3;
        case 4:
            goto title2390_dispatch2_selector4;
        case 5:
            goto title2390_dispatch2_selector5;
        case 6:
            goto title2390_dispatch2_selector6;
        default:
            goto titleBlock391;
    }
title2390_dispatch2_selector0:
    TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) = -1;
    TitleMenu7566C_D_title_8007F133 = 0;
    TitleMenu7566C_D_title_8007F12E = 1;
    goto titleBlock391;
title2390_dispatch2_selector1:
    TitleMenu7566C_D_800725C8 = 0;
    TitleMenu7566C_func_title_8007C62C(0);
    goto titleBlock247;
title2390_dispatch2_selector2:
    TitleMenu7566C_D_800725CC = TitleMenu7566C_D_800725B4;
    TitleMenu7566C_D_800725D4 = TitleMenu7566C_D_800725B4 != 4;
    TitleMenu7566C_func_title_8007C62C(0x10);
    goto titleBlock186;
title2390_dispatch2_selector3:
    workWord = TitleMenu7566C_D_800725B4;
    __asm__ volatile("" ::"i"(&TitleMenu7566C_D_800725D0) : "$4");
    argumentWord4 = (int)&TitleMenu7566C_D_800725D0;
    __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(workWord));
    resultWord = workWord != 4;
    TitleMenu7566CField(argumentWord4, int*, 0) = workWord;
    TitleMenu7566C_D_800725D8 = resultWord;
    resultWord = TitleMenu7566CField(argumentWord4, int*, -4);
    argumentWord5 = 2;
    if (resultWord != argumentWord5)
        goto titleBlock30;
    resultWord = 1;
    TitleMenu7566CField(argumentWord4, int*, -4) = resultWord;
titleBlock30:
    if (workWord != argumentWord5)
        goto titleBlock32;
    resultWord = 1;
    TitleMenu7566CField(argumentWord4, int*, 0) = resultWord;
titleBlock32:
    workWord = TitleMenu7566CField(argumentWord4, int*, -4);
    resultWord = 1;
    if (workWord == resultWord)
        goto titleBlock34;
    TitleMenu7566C_D_800725E0 = 0;
    TitleMenu7566C_D_title_8007F12E = 4;
    goto titleBlock391;
titleBlock34:
    resultWord = TitleMenu7566CField(argumentWord4, int*, 0);
    if (resultWord != workWord)
        goto titleBlock47;
    goto titleBlock49;
title2390_dispatch2_selector4:
    TitleMenu7566C_func_title_8007CD68(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10,
        TitleMenu7566C_D_title_8007EC9C, (int)&TitleMenu7566C_D_title_8007F354, 0x200, 0x80);
    goto titleBlock197;
title2390_dispatch2_selector5:
    if (TitleMenu7566C_D_800725B4 != 5) {
        goto titleBlock41;
    }
    if (TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) != 0) {
        goto titleBlock49;
    }
    resultWord = TitleMenu7566C_D_800725D0;
    workWord = 1;
    if (resultWord != workWord) {
        goto titleBlock47;
    }
    goto titleBlock49;
titleBlock41:
    if (TitleMenu7566C_D_800725B4 != 0) {
        goto titleBlock43;
    }
    TitleMenu7566C_D_8006C76C = 0;
    TitleMenu7566C_D_title_8007F12E = 6;
    TitleMenu7566C_D_8006C694 = (int)TitleMenu7566C_D_title_8007F354;
    TitleMenu7566C_D_8006C698 = (int)TitleMenu7566C_D_title_8007F355;
    goto titleBlock391;
titleBlock43:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F132;
    TitleMenu7566CKeep(argumentWord4);
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if ((unsigned)workWord >= 3)
        goto titleBlock45;
    resultWord = workWord + 1;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
    TitleMenu7566C_D_title_8007F12E = 0;
    goto titleBlock391;
titleBlock45:
    if (TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) != 0) {
        goto titleBlock49;
    }
    resultWord = TitleMenu7566C_D_800725D0;
    workWord = 1;
    if (resultWord == workWord) {
        goto titleBlock48;
    }
titleBlock47:
    TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) = workWord;
    TitleMenu7566C_D_title_8007F12E = 4;
    goto titleBlock391;
titleBlock48:
titleBlock49:
    TitleMenu7566C_D_title_8007F12E = 6;
    goto titleBlock391;
title2390_dispatch2_selector6:
    savedWord16 = (int)&TitleMenu7566C_D_8006EDDC;
    TitleMenu7566CKeep(savedWord16);
    resultWord = TitleMenu7566CField(savedWord16, int*, 0);
    if (resultWord >= 0x1E0)
        goto titleBlock53;
    resultWord = TitleMenu7566C_D_8006E53C;
    if (!(resultWord & 0x840))
        goto titleBlock53;
    TitleMenu7566CTransitionUnmaskedSoundSlots();
    MATCHING_BARRIER_VOLATILE("$4");
    TitleMenu7566CPlaySoundFromGlobalByteTable(0, 4, 0x41);
    workWord = 0x42D70;
    argumentWord4 = 0;
    argumentWord5 = 0;
    resultWord = TitleMenu7566C_D_8006C6A0;
    TitleMenu7566CField(resultWord, int*, 0) = workWord;
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x40);
    TitleMenu7566C_D_8006EE14 = resultWord;
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(0) : "memory");
    resultWord = 0x2A8;
    TitleMenu7566CField(savedWord16, int*, 0) = resultWord;
titleBlock53:
    if (TitleMenu7566C_D_8006EDDC < 0x2A8) {
        goto titleBlock391;
    }
    TitleMenu7566C_func_title_80078918();
    resultWord = 1;
    goto titleBlock390;
title2390_dispatch1_selector1:
    resultWord = -1;
    workWord = TitleMenu7566C_D_8006C648;
    __asm__ volatile("" ::"i"(&TitleMenu7566C_D_title_8007F133) : "$4");
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F133;
    TitleMenu7566CKeep(argumentWord4);
    TitleMenu7566C_D_800725E0 = resultWord;
    resultWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    workWord <<= 2;
    resultWord += workWord;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
    resultWord &= 255;
    if ((unsigned)resultWord < 201)
        goto titleBlock57;
    resultWord = 200;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
titleBlock57:
    workWord = TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(workWord);
    resultWord = 1;
    if (workWord == resultWord)
        goto titleBlock65;
    if (workWord >= 2)
        goto titleBlock61;
    if (workWord == 0)
        goto titleBlock63;
    goto titleBlock391;
titleBlock61:
    resultWord = 2;
    if (workWord == resultWord)
        goto titleBlock74;
    goto titleBlock391;
titleBlock63:
    if (TitleMenu7566C_D_8006EDDC < 0x348)
        goto titleBlock391;
    goto titleBlock238;
titleBlock65:
    argumentWord4 = TitleMenu7566C_D_8006E538;
    resultWord = 0x86;
    if (argumentWord4 != resultWord)
        goto titleBlock67;
    TitleMenu7566CTransitionUnmaskedSoundSlots();
    TitleMenu7566CUpdateSoundVoiceSlots();
    TitleMenu7566CInitializeDisplayBufferPair();
    TitleMenu7566C_func_title_80078B88();
    goto titleBlock391;
titleBlock67:
    resultWord = TitleMenu7566C_D_8006E53C;
    argumentWord5 = 0;
    if (!(resultWord & 0x840))
        goto titleBlock69;
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(1) : "memory");
    goto titleBlock247;
titleBlock69:
    resultWord = argumentWord4 & 0xF0F0;
    if (!resultWord)
        goto titleBlock71;
    TitleMenu7566C_D_title_8007F138 = 0;
titleBlock71:
    if (TitleMenu7566C_D_title_8007F138 < 0x384)
        goto titleBlock391;
    resultWord = TitleMenu7566C_D_8006C658;
    if (resultWord) {
        resultWord = 0x15;
        goto titleBlock390;
    }
    resultWord = 0x15;
    TitleMenu7566C_D_8006C658 = workWord;
    goto titleBlock390;
titleBlock74:
    workWord = TitleMenu7566C_D_title_8007F134;
    resultWord = 24;
    if (workWord)
        goto titleBlock76;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(resultWord, "$3");
    argumentWord4 = 0;
    argumentWord5 = 6;
    goto titleBlock78;
titleBlock76:
    if (workWord != resultWord)
        goto titleBlock79;
    argumentWord4 = 0;
    argumentWord5 = 7;
titleBlock78:
    TitleMenu7566CPlaySoundFromGlobalByteTable(argumentWord4, argumentWord5, 1);
titleBlock79:
    if (TitleMenu7566C_D_title_8007F134 < 0x34) {
        goto titleBlock391;
    }
    TitleMenu7566C_D_title_8007F12C = 2;
    TitleMenu7566CPlaySoundFromGlobalByteTable(0, 2, 1);
    goto titleBlock391;
title2390_dispatch1_selector2:
    savedWord16 = (int)&TitleMenu7566C_D_800725E0;
    TitleMenu7566CField(savedWord16, int*, 0) = -1;
    MATCHING_KEEP(savedWord16);
    argumentWord4 = 1;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
    savedWord18 = savedWord16 - 48;
    MATCHING_KEEP(savedWord18);
    if (TitleMenu7566C_func_title_8007D218(argumentWord4, savedWord18, savedWord16 - 44) == 0) {
        goto titleBlock391;
    }
    resultWord = 1;
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F12E;
    MATCHING_KEEP(savedWord17);
    workWord = TitleMenu7566CField(savedWord17, unsigned char*, 0);
    MATCHING_KEEP(workWord);
    if (workWord == resultWord) {
        goto titleBlock89;
    }
    if (workWord >= 2) {
        goto titleBlock86;
    }
    argumentWord4 = 0;
    if (workWord == 0) {
        goto titleBlock88;
    }
    goto titleBlock391;
titleBlock86:
    argumentWord6 = 0;
    if (workWord == 2) {
        goto titleBlock90;
    }
    goto titleBlock391;
titleBlock88:
    MATCHING_KEEP2_VOLATILE(workWord, argumentWord4);
    TitleMenu7566CField(savedWord16, int*, -24) = 0;
    TitleMenu7566C_func_title_8007C62C(argumentWord4);
    goto titleBlock128;
titleBlock89:
    resultWord = TitleMenu7566CField(savedWord16, int*, -44);
    TitleMenu7566C_D_800725CC = resultWord;
    resultWord = resultWord != 4;
    TitleMenu7566C_D_800725D4 = resultWord;
    TitleMenu7566C_func_title_8007C62C(0x10);
    goto titleBlock128;
titleBlock90:
    argumentWord4 = 0;
    MATCHING_KEEP_VOLATILE(workWord);
    workWord8 = 2;
    argumentWord7 = 1;
    argumentWord5 = savedWord18 + 28;
    resultWord = TitleMenu7566CField(savedWord16, int*, -44);
    workWord = argumentWord5;
    TitleMenu7566CField(savedWord16, int*, -16) = resultWord;
    resultWord = resultWord != 4;
    TitleMenu7566CField(savedWord16, int*, -8) = resultWord;
loop_91:
    resultWord = TitleMenu7566CField(workWord, int*, 0);
    if (resultWord != workWord8)
        goto titleBlock93;
    TitleMenu7566CField(workWord, int*, 0) = argumentWord7;
    resultWord = TitleMenu7566CField(workWord, volatile int*, 0);
titleBlock93:
    if (resultWord == argumentWord7)
        goto titleBlock95;
    TitleMenu7566CField(argumentWord5, int*, 20) = argumentWord4;
    argumentWord6++;
titleBlock95:
    argumentWord4++;
    resultWord = argumentWord4 < 2;
    workWord += 4;
    if (resultWord)
        goto loop_91;
    resultWord = 2;
    if (argumentWord6 != resultWord) {
        resultWord = 1;
        goto titleBlock98;
    }
    resultWord = 5;
    goto titleBlock390;
titleBlock98:
    if (argumentWord6 != resultWord) {
        resultWord = 3;
        goto titleBlock390;
    }
    resultWord = 6;
    goto titleBlock390;
title2390_dispatch1_selector3:
    TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) = -1;
    workWord = TitleMenu7566C_func_title_8007AD80();
    resultWord = 2;
    argumentWord5 = 0;
    if (workWord != resultWord) {
        goto titleBlock102;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    TitleMenu7566C_D_title_8007F133 = 0;
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(3) : "memory");
    resultWord = 1;
    goto titleBlock390;
titleBlock102:
    if (workWord == 0) {
        goto titleBlock104;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(3) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock104:
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    if (!resultWord) {
        resultWord = workWord & 0xA000;
        goto titleBlock264;
    }
    if (TitleMenu7566C_D_title_8007F130 == 0) {
        goto titleBlock107;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(3) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock107:
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(3) : "memory");
    resultWord = 4;
    goto titleBlock390;
title2390_dispatch1_selector4:
    savedWord16 = -1;
    TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) = savedWord16;
    workWord = TitleMenu7566C_func_title_8007AD80();
    resultWord = 2;
    argumentWord5 = 0;
    if (workWord != resultWord) {
        goto titleBlock110;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    TitleMenu7566C_D_title_8007F133 = 0;
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(4) : "memory");
    resultWord = 1;
    goto titleBlock390;
titleBlock110:
    if (workWord == 0) {
        goto titleBlock112;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(4) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock112:
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    if (!resultWord) {
        resultWord = workWord & 0xA000;
        goto titleBlock264;
    }
    if (TitleMenu7566C_D_title_8007F130 != 0) {
        goto titleBlock115;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(4) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock115:
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(4) : "memory");
    TitleMenu7566C_D_800725B8 = 0;
    TitleMenu7566C_D_800725BC = savedWord16;
    TitleMenu7566C_D_800725C0 = savedWord16;
    resultWord = 0x13;
    goto titleBlock390;
title2390_dispatch1_selector5:
    savedWord16 = (int)&TitleMenu7566C_D_800725E0;
    TitleMenu7566CKeep(savedWord16);
    TitleMenu7566CField(savedWord16, int*, 0) = -1;
    workWord = TitleMenu7566C_func_title_8007AD80();
    resultWord = 2;
    argumentWord5 = 0;
    if (workWord != resultWord) {
        goto titleBlock118;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    TitleMenu7566C_D_title_8007F133 = 0;
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(5) : "memory");
    resultWord = 1;
    goto titleBlock390;
titleBlock118:
    if (workWord == 0) {
        goto titleBlock120;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(5) : "memory");
    resultWord = 2;
    goto titleBlock390;
    do {
    titleBlock120:
        workWord = TitleMenu7566C_D_8006E53C;
        resultWord = workWord & 0x840;
        if (!resultWord)
            goto titleBlock263;
        resultWord = TitleMenu7566C_D_8006C654;
        argumentWord5 = 0;
        argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
        MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
        resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
        /* Actual original outer selector on every incoming path. */
        __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(5) : "memory");
        TitleMenu7566C_D_title_8007F12C = 6;
        TitleMenu7566CField(savedWord16, int*, 0) = (int)TitleMenu7566C_D_title_8007F130;
        goto titleBlock391;
    } while (0);
title2390_dispatch1_selector6:
    argumentWord4 = 1;
    MATCHING_OBSERVE_VOLATILE(argumentWord4);
    savedWord16 = (int)&TitleMenu7566C_D_800725B0;
    if (TitleMenu7566C_func_title_8007D218(argumentWord4, savedWord16, savedWord16 + 4) == 0) {
        goto titleBlock391;
    }
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F12E;
    MATCHING_KEEP(savedWord17);
    workWord = TitleMenu7566CField(savedWord17, unsigned char*, 0);
    if (!workWord) {
        goto titleBlock126;
    }
    if (workWord == 1) {
        goto titleBlock130;
    }
    goto titleBlock391;
titleBlock126:
    argumentWord4 = TitleMenu7566C_D_800725E0;
    retainedOriginalRecordBase = savedWord16;
    MATCHING_KEEP_VOLATILE(retainedOriginalRecordBase);
    indexedRecordAddress = retainedOriginalRecordBase + argumentWord4 * 4;
    resultWord = TitleMenu7566CField(indexedRecordAddress, int*, 36);
    MATCHING_OBSERVE_VOLATILE(retainedOriginalRecordBase);
    temporaryWord4 = argumentWord4 * 16;
    if (!resultWord) {
        goto titleBlock129;
    }
    temporaryWord5 = (int)&TitleMenu7566C_D_title_8007F154;
    MATCHING_KEEP_VOLATILE(workWord);
    temporaryWord6 = 0;
titleVerifiedRecordTransfer:
    TitleMenu7566C_func_title_8007CD68(temporaryWord4, TitleMenu7566C_D_title_8007EC9C,
                                       temporaryWord5, temporaryWord6, 7552);
titleBlock128:
    resultWord = TitleMenu7566CField(savedWord17, unsigned char*, 0);
    resultWord++;
    TitleMenu7566CField(savedWord17, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock129:
    resultWord = 7;
    goto titleState7LookupEntry;
titleBlock130:
    argumentWord5 = TitleMenu7566CField(savedWord16, int*, 4);
    if (argumentWord5 == 5) {
        resultWord = 7;
        goto titleState7RecordEntry;
    }
titleVerifiedCRCResults:
    if (argumentWord5 != 0) {
        goto titleBlock144;
    }
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4) !=
        TitleMenu7566C_D_title_8007FCD0) {
        goto titleBlock135;
    }
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4 + 0x900) !=
        TitleMenu7566C_D_title_800805D0) {
        goto titleBlock135;
    }
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4 + 0x1200) ==
        TitleMenu7566C_D_title_80080ED0) {
        goto titleBlock143;
    }
titleBlock135:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F132;
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if ((unsigned)workWord >= 3)
        goto titleBlock137;
    resultWord = workWord + 1;
    TitleMenu7566C_D_title_8007F12E = 0;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock137:
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4) ==
        TitleMenu7566C_D_title_8007FCD0) {
        goto titleBlock139;
    }
    TitleMenu7566C_D_title_8007F3D8 = 0;
    TitleMenu7566C_func_title_80078C1C((int)&TitleMenu7566C_D_title_8007F3D4, 1);
titleBlock139:
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F3D4 + 0x900;
    if (TitleMenu7566C_func_title_80078BF4(savedWord17) == TitleMenu7566C_D_title_800805D0) {
        goto titleBlock141;
    }
    TitleMenu7566C_D_title_8007FCD8 = 0;
    TitleMenu7566C_func_title_80078C1C(savedWord17, 1);
titleBlock141:
    savedWord16 = (int)&TitleMenu7566C_D_title_8007F3D4 + 0x1200;
    if (TitleMenu7566C_func_title_80078BF4(savedWord16) == TitleMenu7566C_D_title_80080ED0) {
        goto titleBlock143;
    }
    TitleMenu7566C_D_title_800805D8 = 0;
    TitleMenu7566C_func_title_80078C1C(savedWord16, 1);
    goto titleBlock143;
titleBlock143:
    resultWord = 11;
    goto titleBlock390;
titleBlock144:
    workWord = TitleMenu7566C_D_title_8007F132;
    __asm__ volatile("" : "=r"(workWord) : "0"(workWord), "r"(argumentWord5));
    if ((unsigned)workWord < 3) {
        resultWord = workWord + 1;
        goto titleBlock357;
    }
    resultWord = 23;
    goto titleBlock390;

titleVerifiedRetryExit23:
    resultWord = 23;
    goto titleBlock390;
title2390_dispatch1_selector7:
    resultWord = TitleMenu7566C_func_title_8007AD80();
    argumentWord5 = 0;
    if (!resultWord) {
        goto titleBlock148;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(7) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock148:
    MATCHING_KEEP_VOLATILE(argumentWord5);
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    if (!resultWord) {
        resultWord = workWord & 0xA000;
        goto titleBlock264;
    }
    resultWord = workWord & 0xA000;
    MATCHING_OBSERVE_VOLATILE(resultWord);
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(7) : "memory");
    resultWord = TitleMenu7566C_D_title_8007F130;
    if (resultWord) {
        resultWord = 4;
        goto titleBlock390;
    }
    resultWord =
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725D4, int*, TitleMenu7566C_D_800725E0 * 4);
    if (resultWord) {
        resultWord = 10;
        goto titleBlock390;
    }
    resultWord = 8;
    goto titleBlock390;
title2390_dispatch1_selector8:
    resultWord = TitleMenu7566C_func_title_8007AD80();
    argumentWord5 = 0;
    if (!resultWord) {
        goto titleBlock154;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(8) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock154:
    MATCHING_KEEP_VOLATILE(argumentWord5);
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    if (!resultWord) {
        resultWord = workWord & 0xA000;
        goto titleBlock264;
    }
    resultWord = workWord & 0xA000;
    MATCHING_OBSERVE_VOLATILE(resultWord);
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(8) : "memory");
    resultWord = TitleMenu7566C_D_title_8007F130;
    if (resultWord)
        goto title8Return9;
    resultWord = 9;
    __asm__ volatile("" ::"r"(resultWord), "i"(8));
    resultWord = 4;
    goto titleBlock390;
title8Return9:
    resultWord = 9;
    goto titleBlock390;
title2390_dispatch1_selector9:
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F12E;
    MATCHING_KEEP(savedWord17);
    workWord = TitleMenu7566CField(savedWord17, unsigned char*, 0);
    savedWord18 = 1;
    MATCHING_KEEP(savedWord18);
    if (workWord == savedWord18) {
        goto titleBlock165;
    }
    if ((int)workWord >= 2) {
        goto titleBlock161;
    }
    if (!workWord) {
        goto titleBlock163;
    }
    goto titleBlock391;
titleBlock161:
    if (workWord == 2) {
        goto titleBlock170;
    }
    goto titleBlock391;
titleBlock163:
    if (TitleMenu7566C_func_title_8007D218(1, (int)&TitleMenu7566C_D_800725B0,
                                           (int)&TitleMenu7566C_D_800725B0 + 4) == 0) {
        goto titleBlock391;
    }
    goto titleBlock352;
titleBlock165:
    if (TitleMenu7566C_func_title_8007D430(
            TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10) == 0) {
        goto titleBlock169;
    }
    if ((unsigned char)TitleMenu7566C_D_title_8007F132 >= 3U)
        goto titleRetry8Exit23;
    TitleMenu7566C_D_title_8007F132 += 1;
    goto titleBlock391;
titleRetry8Exit23:
    resultWord = 23;
    goto titleState23Retry8Entry;
titleBlock169:
    TitleMenu7566C_func_title_8007C62C(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10);
    resultWord = 2;
    goto titleBlock355;
titleBlock170:
    if (TitleMenu7566C_func_title_8007D218(1, (int)&TitleMenu7566C_D_800725B0,
                                           (int)&TitleMenu7566C_D_800725B0 + 4) == 0) {
        goto titleBlock391;
    }
    if (TitleMenu7566CField((int)&TitleMenu7566C_D_800725B0, int*, 4) != 0) {
        goto titleBlock173;
    }
    resultWord = TitleMenu7566C_D_800725E0;
    resultWord *= 4;
    resultWord += (int)&TitleMenu7566C_D_800725B0 + 28;
    TitleMenu7566CField(resultWord, int*, 0) = 0;
    resultWord = TitleMenu7566C_D_800725E0;
    resultWord *= 4;
    resultWord += (int)&TitleMenu7566C_D_800725B0 + 36;
    TitleMenu7566CField(resultWord, int*, 0) = savedWord18;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(resultWord, "memory");
titleVerifiedState10:
    resultWord = 0xA;
    goto titleBlock390;
    goto titleBlock391;
titleBlock173:
    workWord = TitleMenu7566C_D_title_8007F132;
    if ((unsigned)workWord >= 3)
        goto titleRetry9Exit23;
    resultWord = workWord + 1;
    TitleMenu7566C_D_title_8007F132 = resultWord;
    goto titleBlock352;
titleRetry9Exit23:
    resultWord = 23;
    goto titleState23Retry9Entry;
title2390_dispatch1_selector10:
    if (TitleMenu7566C_func_title_8007D218(1, (int)&TitleMenu7566C_D_800725B0,
                                           (int)&TitleMenu7566C_D_800725B0 + 4) == 0) {
        goto titleBlock391;
    }
    if ((unsigned char)TitleMenu7566C_D_title_8007F12E >= 6U) {
        goto titleBlock391;
    }
    switch (TitleMenu7566C_D_title_8007F12E) {
        case 1:
            goto title2390_dispatch3_selector1;
        case 2:
            goto title2390_dispatch3_selector2;
        case 3:
            goto title2390_dispatch3_selector3;
        case 4:
            goto title2390_dispatch3_selector4;
        case 5:
            goto title2390_dispatch3_selector5;
        case 0:
            goto title2390_dispatch3_selector0;
        default:
            return;
    }
title2390_dispatch3_selector1:
    temp_v0_5 = TitleMenu7566C_func_title_8007D334(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10,
        TitleMenu7566C_D_title_8007EC9C, 1);
    TitleMenu7566C_D_800725B4 = temp_v0_5;
    if (temp_v0_5 == 0) {
        goto titleBlock246;
    }
    if (temp_v0_5 == 6) {
        goto titleBlock246;
    }
    if (temp_v0_5 != 7) {
        goto titleRetryFromHeader;
    }
    resultWord = 0x16;
    goto titleBlock390;
    goto titleBlock391;
titleRetryFromHeader:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F132;
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if ((unsigned)workWord >= 3)
        goto titleHeaderRetryExit23;
    resultWord = workWord + 1;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
    goto titleBlock237;
titleHeaderRetryExit23:
    resultWord = 23;
    goto titleState23HeaderRetryEntry;
title2390_dispatch3_selector2:
    TitleMenu7566CFillWordRange((int)&TitleMenu7566C_D_title_8007F154, 0, 0x1D80);
    TitleMenu7566CCopyWordRangeUnrolled4((int)&TitleMenu7566C_D_title_8007F154,
                                         (int)&TitleMenu7566C_D_title_8007ECA0, 0x200);
    TitleMenu7566C_D_title_8007F357 = 0;
    TitleMenu7566C_D_title_8007F3D8 = 0;
    TitleMenu7566C_D_title_8007F354 = (signed char)TitleMenu7566C_D_8006C694;
    TitleMenu7566C_D_title_8007F355 = (signed char)TitleMenu7566C_D_8006C698;
    TitleMenu7566C_D_title_8007F356 = (signed char)TitleMenu7566C_D_8006C76C;
    TitleMenu7566C_func_title_80078C1C((int)&TitleMenu7566C_D_title_8007F154 + 0x280, 1);
    TitleMenu7566C_D_title_8007FCD8 = 0;
    TitleMenu7566C_func_title_80078C1C((int)&TitleMenu7566C_D_title_8007F154 + 0xB80, 1);
    TitleMenu7566C_D_title_800805D8 = 0;
    TitleMenu7566C_func_title_80078C1C((int)&TitleMenu7566C_D_title_8007F154 + 0x1480, 1);
    TitleMenu7566C_func_title_8007CFC0(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10,
        TitleMenu7566C_D_title_8007EC9C, (int)&TitleMenu7566C_D_title_8007F154, 0, 0x1D80);
titleBlock186:
    TitleMenu7566C_D_title_8007F12E = 3;
    goto titleBlock391;
title2390_dispatch3_selector3:
    resultWord = TitleMenu7566C_D_800725B4;
    argumentWord7 = 0;
    if (resultWord)
        goto titleBlock189;
    argumentWord6 = (int)&TitleMenu7566C_D_title_8007F154;
    goto titleBlock202;
titleBlock189:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F132;
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if ((unsigned)workWord >= 3)
        goto titleValidation3Exit23;
    resultWord = workWord + 1;
titleBlock191:
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
    goto titleBlock246;
titleValidation3Exit23:
    resultWord = 23;
    goto titleState23Validation3Entry;
title2390_dispatch3_selector4:
    if (TitleMenu7566C_D_800725B4 != 0) {
        goto titleBlock200;
    }
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4) !=
        TitleMenu7566C_D_title_8007FCD0) {
        goto titleBlock198;
    }
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4 + 0x900) !=
        TitleMenu7566C_D_title_800805D0) {
        goto titleBlock198;
    }
    if (TitleMenu7566C_func_title_80078BF4((int)&TitleMenu7566C_D_title_8007F3D4 + 0x1200) !=
        TitleMenu7566C_D_title_80080ED0) {
        goto titleBlock198;
    }
    TitleMenu7566C_func_title_8007C93C();
titleBlock197:
    TitleMenu7566C_D_title_8007F12E = 5;
    goto titleBlock391;
titleBlock198:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F132;
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if ((unsigned)workWord < 3) {
        resultWord = workWord + 1;
        goto titleBlock191;
    }
    resultWord = 23;
    goto titleState23Validation4Entry;
titleBlock200:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F132;
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if ((unsigned)workWord >= 3) {
        resultWord = workWord + 1;
        goto titleBlock203;
    }
    resultWord = workWord + 1;
    argumentWord6 = (int)&TitleMenu7566C_D_title_8007F154;
    argumentWord7 = 0;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
titleBlock202:
    TitleMenu7566C_func_title_8007CD68Other(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 16,
        TitleMenu7566C_D_title_8007EC9C, argumentWord6, argumentWord7, 7552);
    TitleMenu7566C_D_title_8007F12E = 4;
    goto titleBlock391;
titleBlock203:
    resultWord = 23;
titleValidationState23:
    goto titleState23ValidationResultEntry;
    goto titleBlock391;
title2390_dispatch3_selector5:
titleValidationNext13:
titleValidationNext13Again:
    resultWord = 13;
    goto titleState13ValidationEntry;
    goto titleBlock391;
title2390_dispatch1_selector11:
    savedWord16 = (int)&TitleMenu7566C_D_title_8007F354;
    TitleMenu7566CKeep(savedWord16);
    resultWord = TitleMenu7566CField(savedWord16, signed char*, 0);
    workWord = TitleMenu7566C_D_title_8007F355;
    argumentWord5 = TitleMenu7566C_D_title_8007F357;
    TitleMenu7566C_D_8006C694 = resultWord;
    TitleMenu7566C_D_8006C698 = workWord;
    TitleMenu7566C_D_800725E4 = argumentWord5;
    TitleMenu7566C_D_8006FCD4 = resultWord;
    TitleMenu7566C_D_8006FC60 = resultWord;
    TitleMenu7566C_D_8006FCD6 = workWord;
    TitleMenu7566C_D_8006FC62 = workWord;
    resultWord = TitleMenu7566C_func_title_8007928C(savedWord16 + 0x80);
    if (resultWord >= 0) {
        resultWord = 12;
        goto titleBlock390;
    }
    resultWord = TitleMenu7566C_func_title_8007928C(savedWord16 + 0x980);
    if (resultWord >= 0) {
        resultWord = 12;
        goto titleBlock390;
    }
    resultWord = TitleMenu7566C_func_title_8007928C(savedWord16 + 0x1280);
    if (resultWord >= 0) {
        resultWord = 12;
        goto titleBlock390;
    }
    resultWord = 13;
    goto titleBlock390;
title2390_dispatch1_selector12:
    workWord = TitleMenu7566C_func_title_8007AD80();
    resultWord = 2;
    argumentWord5 = 0;
    if (workWord != resultWord) {
        goto titleBlock211;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    TitleMenu7566C_D_title_8007F133 = 0;
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(12) : "memory");
    resultWord = 1;
    goto titleBlock390;
titleBlock211:
    if (workWord == 0) {
        goto titleBlock213;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(12) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock213:
    savedWord19 = (int)&TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(savedWord19);
    argumentWord4 = TitleMenu7566CField(savedWord19, unsigned char*, 0);
    if (!argumentWord4)
        goto titleBlock216;
    if (argumentWord4 == 1)
        goto titleBlock219;
    goto titleBlock391;
titleBlock216:
    TitleMenu7566CKeep(argumentWord4);
    savedWord16 = savedWord19 + 14;
    savedWord18 = 0;
    savedWord17 = 0;
    savedWord19 += 38;
loop_217:
    temp_v0_7 = TitleMenu7566CFindHudClassIndex(
        TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D8, unsigned char*, savedWord18) +
        1000);
    TitleMenu7566CField(savedWord16, short*, 0) = temp_v0_7;
    savedWord18 += 2304;
    TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F13E, unsigned char*, savedWord17) =
        TitleMenu7566CField(((temp_v0_7 << 16) >> 13) + TitleMenu7566C_D_8006C738, unsigned char*,
                            4);
    temp_v0_8 = TitleMenu7566CField(TitleMenu7566CField(savedWord16, short*, 0) * 8 +
                                        TitleMenu7566C_D_8006C738,
                                    unsigned char*, 2);
    savedWord16 += 8;
    TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F13F, unsigned char*, savedWord17) =
        temp_v0_8;
    savedWord17 += 8;
    if (savedWord16 < savedWord19)
        goto loop_217;
    goto titleBlock326;
titleBlock219:
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    argumentWord5 = 0;
    if (!resultWord)
        goto titleBlock223;
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(12) : "memory");
    resultWord = TitleMenu7566C_D_title_8007F130;
    workWord = 13;
    if (!resultWord)
        goto title12Return17;
    resultWord = 1;
    TitleMenu7566C_D_title_8007F12C = workWord;
    TitleMenu7566CField(savedWord19, unsigned char*, 0) = resultWord;
    TitleMenu7566C_D_title_8007F12D = workWord;
    TitleMenu7566C_D_title_8007F132 = 0;
    goto titleBlock391;
title12Return17:
    resultWord = 17;
    goto titleBlock390;
titleBlock223:
    resultWord = workWord & 0xA000;
    if (!resultWord)
        goto titleBlock391;
    resultWord = TitleMenu7566C_D_title_8007F130;
    resultWord = argumentWord4 - resultWord;
    TitleMenu7566C_D_title_8007F130 = resultWord;
    goto titleBlock391;
title2390_dispatch1_selector13:
    workWord = TitleMenu7566C_func_title_8007AD80();
    argumentWord5 = 2;
    if (workWord != argumentWord5) {
        goto titleBlock227;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    TitleMenu7566C_D_title_8007F133 = 0;
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(13) : "memory");
    resultWord = 1;
    goto titleBlock390;
titleBlock227:
    resultWord = 1;
    if (workWord == 0) {
        goto titleBlock229;
    }
    MATCHING_OBSERVE(resultWord);
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(13) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock229:
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(argumentWord4);
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    if (workWord == resultWord)
        goto titleBlock240;
    if (workWord >= 2)
        goto titleBlock233;
    savedWord16 = argumentWord4 + 14;
    if (!workWord)
        goto titleBlock235;
    goto titleBlock391;
titleBlock233:
    if (workWord == argumentWord5)
        goto titleBlock248;
    goto titleBlock391;
titleBlock235:
    MATCHING_KEEP_VOLATILE(workWord);
    savedWord18 = 0;
    savedWord17 = 0;
    MATCHING_OBSERVE2_VOLATILE_CLOBBER(savedWord18, savedWord17, "$19");
    savedWord19 = argumentWord4 + 38;
loop_236:
    temp_v0_10 =
        TitleMenu7566CFindHudClassIndex(TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D8,
                                                            unsigned char*, (savedWord18) * 1) +
                                        0x3E8);
    TitleMenu7566CField(savedWord16, short*, 0) = temp_v0_10;
    savedWord18 += 0x900;
    TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F13E, unsigned char*, (savedWord17) * 1) =
        TitleMenu7566CField((((int)(temp_v0_10 << 0x10) >> 0xD) + TitleMenu7566C_D_8006C738),
                            unsigned char*, 4);
    temp_v0_11 = TitleMenu7566CField(
        ((TitleMenu7566CField(savedWord16, short*, 0) * 8) + TitleMenu7566C_D_8006C738),
        unsigned char*, 2);
    savedWord16 += 8;
    TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F13F, unsigned char*, (savedWord17) * 1) =
        temp_v0_11;
    savedWord17 += 8;
    if (savedWord16 < savedWord19) {
        goto loop_236;
    }
title2390_dispatch3_selector0:
titleBlock237:
titleBlock238:
    TitleMenu7566C_D_title_8007F12E = 1;
    goto titleBlock391;
titleBlock239:
    TitleMenu7566C_D_title_8007F130 = resultWord;
    TitleMenu7566C_D_title_8007F131 = resultWord;
    resultWord = savedWord16 < 3;
    goto titleBlock244;
titleBlock240:
    savedWord16 = 0;
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F3D4;
loop_241:
    resultWord = TitleMenu7566C_func_title_8007928C(savedWord17);
    if (resultWord < 0) {
        resultWord = savedWord16;
        goto titleBlock239;
    }
    savedWord16++;
    savedWord17 += 0x900;
    if (savedWord16 < 3)
        goto loop_241;
    TitleMenu7566CKeep(savedWord16);
    resultWord = savedWord16 < 3;
titleBlock244:
    if (resultWord)
        goto titleBlock247;
    TitleMenu7566C_D_title_8007F130 = 0;
    TitleMenu7566C_D_title_8007F131 = 0;
titleBlock246:
titleBlock247:
    resultWord = 2;
    TitleMenu7566C_D_title_8007F12E = resultWord;
    goto titleBlock391;
titleBlock248:
    if (!(TitleMenu7566C_D_8006E53C & 0x840)) {
        goto titleBlock251;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(13) : "memory");
    TitleMenu7566C_D_800725BC = TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0);
    TitleMenu7566C_D_800725E4 = (int)TitleMenu7566C_D_title_8007F130;
    TitleMenu7566C_D_800725C0 = (int)TitleMenu7566C_D_title_8007F130;
    resultWord = TitleMenu7566C_func_title_8007928C((TitleMenu7566C_D_title_8007F130 * 0x900) +
                                                    (int)&TitleMenu7566C_D_title_8007F3D4);
    if (resultWord >= 0)
        goto title13Return14;
    resultWord = 15;
    goto titleBlock390;
title13Return14:
    resultWord = 14;
    goto titleBlock390;
titleBlock251:
    if (!(TitleMenu7566C_D_8006E53C & 0x2000)) {
        goto titleBlock254;
    }
    if ((unsigned char)TitleMenu7566C_D_title_8007F130 >= 2U) {
        goto titleBlock391;
    }
    TitleMenu7566C_D_title_8007F130 += 1;
    goto titleBlock391;
titleBlock254:
    if (!(TitleMenu7566C_D_8006E53C & 0x8000)) {
        goto titleBlock391;
    }
    if (TitleMenu7566C_D_title_8007F130 == 0) {
        goto titleBlock391;
    }
    TitleMenu7566C_D_title_8007F130 -= 1;
    goto titleBlock391;
title2390_dispatch1_selector14:
    if (TitleMenu7566C_func_title_8007AD80() == 0) {
        goto titleBlock259;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(14) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock259:
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    if (!resultWord) {
        resultWord = workWord & 0xA000;
        goto titleBlock264;
    }
    if (TitleMenu7566C_D_title_8007F130 == 0) {
        goto titleBlock262;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(14) : "memory");
    resultWord = 0xF;
    goto titleBlock390;
titleBlock262:
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(14) : "memory");
    resultWord = 2;
    goto titleBlock390;
    do {
    titleBlock263:
        resultWord = workWord & 0xA000;
    titleBlock264:;
    } while (0);
    if (!resultWord)
        goto titleBlock391;
    resultWord = 1;
    TitleMenu7566CKeep(resultWord);
    argumentWord4 = (int)&TitleMenu7566C_D_title_8007F130;
    TitleMenu7566CKeep(argumentWord4);
    workWord = TitleMenu7566CField(argumentWord4, unsigned char*, 0);
    resultWord -= workWord;
    TitleMenu7566CField(argumentWord4, unsigned char*, 0) = resultWord;
    goto titleBlock391;
title2390_dispatch1_selector15:
    if (TitleMenu7566C_func_title_8007AD80() == 0) {
        goto titleBlock268;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(15) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock268:
    savedWord16 = TitleMenu7566C_D_title_8007F12E;
    if (savedWord16 == 0) {
        goto titleBlock271;
    }
    if (savedWord16 == 1) {
        goto titleBlock283;
    }
    goto titleBlock391;
titleBlock271:
    savedWord17 = -1;
    MATCHING_KEEP_VOLATILE(savedWord17);
    savedWord16 = -1;
    savedWord17++;
loop_272:
    resultWord = TitleMenu7566CFindHudClassIndex(savedWord17 + 1001);
    workWord = TitleMenu7566C_D_8006C738;
    resultWord *= 8;
    resultWord += workWord;
    resultWord = TitleMenu7566CField(resultWord, short*, 0);
    savedWord17++;
    if (resultWord != savedWord16)
        goto loop_272;
    savedWord17--;
    savedWord16 = 1;
    argumentWord7 = (int)&TitleMenu7566C_D_800725E4;
    resultWord = savedWord17 < savedWord16;
loop_274:
    argumentWord6 = 1;
    if (!resultWord)
        goto titleBlock276;
    savedWord16 = 1;
titleBlock276:
    workWord = 0;
    argumentWord5 = TitleMenu7566CField(argumentWord7, int*, 0);
    argumentWord4 = 0;
loop_277:
    if (workWord == argumentWord5)
        goto titleBlock280;
    resultWord =
        TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D8, unsigned char*, argumentWord4);
    if (resultWord != savedWord16)
        goto titleBlock280;
    savedWord16++;
    argumentWord6 = 0;
    goto titleBlock281;
titleBlock280:
    workWord++;
    resultWord = workWord < 3;
    argumentWord4 += 2304;
    if (resultWord)
        goto loop_277;
titleBlock281:
    resultWord = savedWord17 < savedWord16;
    if (!argumentWord6)
        goto loop_274;
    resultWord = TitleMenu7566CFindHudClassIndex(savedWord16 + 1000);
    TitleMenu7566C_D_title_8007F13C = resultWord;
    workWord = TitleMenu7566C_D_8006C738;
    resultWord = (resultWord << 16) >> 13;
    resultWord += workWord;
    workWord = TitleMenu7566CField(resultWord, unsigned char*, 4);
    TitleMenu7566C_D_title_8007F13E = workWord;
    workWord = TitleMenu7566C_D_title_8007F12E;
    resultWord = TitleMenu7566CField(resultWord, unsigned char*, 2);
    TitleMenu7566C_D_title_8007F130 = savedWord16;
    TitleMenu7566C_D_title_8007F131 = savedWord16;
    workWord++;
    TitleMenu7566C_D_title_8007F12E = workWord;
    TitleMenu7566C_D_title_8007F13F = resultWord;
    goto titleBlock391;
titleBlock283:
    TitleMenu7566CKeep(savedWord16);
    workWord = TitleMenu7566C_D_8006E53C;
    resultWord = workWord & 0x840;
    if (!resultWord) {
        goto titleBlock285;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(15) : "memory");
    workWord = TitleMenu7566C_D_800725E4;
    resultWord = workWord * 0x900;
    workWord = TitleMenu7566C_D_title_8007F130;
    TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D8, unsigned char*, resultWord) =
        workWord;
    resultWord = 1;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_80071FB0 = resultWord;
    TitleMenu7566C_D_8006C5BC = 0;
    TitleMenu7566C_D_800725E8 = (int)savedWord16;
    resultWord = 0x10;
    goto titleBlock390;
titleBlock285:
    resultWord = workWord & 0x2000;
    savedWord16 = -1;
    if (!resultWord)
        goto titleBlock298;
    MATCHING_KEEP_VOLATILE(savedWord16);
    savedWord17 = -1;
    savedWord16++;
loop_287:
    resultWord = TitleMenu7566CFindHudClassIndex(savedWord16 + 1001);
    workWord = TitleMenu7566C_D_8006C738;
    resultWord *= 8;
    resultWord += workWord;
    resultWord = TitleMenu7566CField(resultWord, short*, 0);
    savedWord16++;
    if (resultWord != savedWord17)
        goto loop_287;
    savedWord16--;
    resultWord = TitleMenu7566C_D_title_8007F130;
    workWord8 = (int)&TitleMenu7566C_D_800725E4;
    argumentWord5 = resultWord + 1;
    resultWord = savedWord16 < argumentWord5;
loop_289:
    argumentWord7 = 1;
    if (!resultWord)
        goto titleBlock291;
    argumentWord5 = 1;
titleBlock291:
    workWord = 0;
    argumentWord6 = TitleMenu7566CField(workWord8, int*, 0);
    argumentWord4 = 0;
loop_292:
    if (workWord == argumentWord6)
        goto titleBlock295;
    resultWord =
        TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D8, unsigned char*, argumentWord4);
    if (resultWord != argumentWord5)
        goto titleBlock295;
    argumentWord5++;
    argumentWord7 = 0;
    goto titleBlock296;
titleBlock295:
    workWord++;
    resultWord = workWord < 3;
    argumentWord4 += 2304;
    if (resultWord)
        goto loop_292;
titleBlock296:
    resultWord = savedWord16 < argumentWord5;
    if (!argumentWord7)
        goto loop_289;
    goto titleBlock310;
titleBlock298:
    MATCHING_KEEP_VOLATILE_CLOBBER(savedWord16, "$2");
    resultWord = workWord & 0x8000;
    savedWord17 = -1;
    if (!resultWord)
        goto titleBlock391;
    savedWord16++;
loop_300:
    resultWord = TitleMenu7566CFindHudClassIndex(savedWord16 + 1001);
    workWord = TitleMenu7566C_D_8006C738;
    resultWord *= 8;
    resultWord += workWord;
    resultWord = TitleMenu7566CField(resultWord, short*, 0);
    savedWord16++;
    if (resultWord != savedWord17)
        goto loop_300;
    savedWord16--;
    resultWord = TitleMenu7566C_D_title_8007F130;
    workWord8 = (int)&TitleMenu7566C_D_800725E4;
    argumentWord5 = resultWord - 1;
loop_302:
    argumentWord7 = 1;
    if (argumentWord5 > 0)
        goto titleBlock304;
    argumentWord5 = savedWord16;
titleBlock304:
    workWord = 0;
    argumentWord6 = TitleMenu7566CField(workWord8, int*, 0);
    argumentWord4 = 0;
loop_305:
    if (workWord == argumentWord6)
        goto titleBlock308;
    resultWord =
        TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D8, unsigned char*, argumentWord4);
    if (resultWord != argumentWord5)
        goto titleBlock308;
    argumentWord5--;
    argumentWord7 = 0;
    goto titleBlock309;
titleBlock308:
    workWord++;
    resultWord = workWord < 3;
    argumentWord4 += 2304;
    if (resultWord)
        goto loop_305;
titleBlock309:
    if (!argumentWord7)
        goto loop_302;
titleBlock310:
    TitleMenu7566C_D_title_8007F130 = argumentWord5;
    resultWord = TitleMenu7566CFindHudClassIndex(argumentWord5 + 1000);
    TitleMenu7566C_D_title_8007F13C = resultWord;
    workWord = TitleMenu7566C_D_8006C738;
    resultWord = (resultWord << 16) >> 13;
    resultWord += workWord;
    workWord = TitleMenu7566CField(resultWord, unsigned char*, 4);
    TitleMenu7566C_D_title_8007F13E = workWord;
    resultWord = TitleMenu7566CField(resultWord, unsigned char*, 2);
    TitleMenu7566C_D_title_8007F13F = resultWord;
    goto titleBlock391;
title2390_dispatch1_selector16:
    argumentWord4 = TitleMenu7566C_func_title_800793C8();
    resultWord = -1;
    if (argumentWord4 != resultWord) {
        resultWord = 1;
        goto titleBlock313;
    }
    resultWord = 23;
    goto titleState23Choice16Entry;
titleBlock313:
    if (argumentWord4 != resultWord)
        goto titleBlock391;
    resultWord = TitleMenu7566C_D_800725E0;
    workWord = TitleMenu7566C_D_800725E4;
    TitleMenu7566C_D_800725B8 = argumentWord4;
    TitleMenu7566C_D_800725BC = resultWord;
    resultWord = workWord * 2304;
    TitleMenu7566C_D_800725C0 = workWord;
    workWord = TitleMenu7566CField((int)&TitleMenu7566C_D_title_8007F3D4, int*, resultWord);
    resultWord = 19;
    TitleMenu7566C_D_title_8007F12C = resultWord;
    TitleMenu7566C_D_800725C4 = workWord;
    goto titleBlock391;
title2390_dispatch1_selector17:
    if (TitleMenu7566C_func_title_8007AD80() == 0) {
        goto titleBlock317;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x17);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(17) : "memory");
    resultWord = 2;
    goto titleBlock390;
titleBlock317:
    savedWord16 = TitleMenu7566C_D_title_8007F12E;
    if (savedWord16 == 0) {
        goto titleBlock320;
    }
    if (savedWord16 == 1) {
        goto titleBlock327;
    }
    goto titleBlock391;
titleBlock320:
    savedWord16 = (int)&TitleMenu7566C_D_800725E4;
    TitleMenu7566CKeep(savedWord16);
    resultWord = TitleMenu7566CField(savedWord16, int*, 0);
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F3D4;
    resultWord = TitleMenu7566C_func_title_8007928C(resultWord * 0x900 + savedWord17);
    if (resultWord < 0)
        goto titleBlock323;
    resultWord = TitleMenu7566CField(savedWord16, unsigned char*, 0);
titleBlock322:
    TitleMenu7566C_D_title_8007F130 = resultWord;
    TitleMenu7566C_D_title_8007F131 = resultWord;
    goto titleBlock326;
titleBlock323:
    savedWord16 = 0;
loop_324:
    resultWord = TitleMenu7566C_func_title_8007928C(savedWord17);
    if (resultWord >= 0) {
        resultWord = savedWord16;
        goto titleBlock322;
    }
    savedWord16++;
    savedWord17 += 0x900;
    if (savedWord16 < 3)
        goto loop_324;
titleBlock326:
    workWord = (int)&TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(workWord);
    resultWord = TitleMenu7566CField(workWord, unsigned char*, 0);
    resultWord++;
    TitleMenu7566CField(workWord, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock327:
    if (!(TitleMenu7566C_D_8006E53C & 0x840)) {
        goto titleBlock329;
    }
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord5 = 0;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x16);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    /* Actual original outer selector on every incoming path. */
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "i"(17) : "memory");
    TitleMenu7566C_D_800725E8 = (int)savedWord16;
    TitleMenu7566C_D_title_8007F12C = 0x12;
    TitleMenu7566C_D_800725E4 = (int)TitleMenu7566C_D_title_8007F130;
    goto titleBlock391;
titleBlock329:
    if (!(TitleMenu7566C_D_8006E53C & 0x2000)) {
        goto titleBlock336;
    }
    resultWord = TitleMenu7566C_D_title_8007F130;
    workWord = (int)&TitleMenu7566C_D_title_8007F3D4;
    TitleMenu7566CKeep(workWord);
    savedWord16 = resultWord + 1;
    resultWord = savedWord16 * 0x900;
    savedWord17 = resultWord + workWord;
loop_331:
    resultWord = TitleMenu7566C_func_title_8007928C(savedWord17);
    if (resultWord >= 0)
        goto titleBlock334;
    savedWord17 += 0x900;
    resultWord = savedWord16 < 3;
    if (!resultWord)
        goto titleBlock391;
    savedWord16++;
    goto loop_331;
titleBlock334:
    resultWord = savedWord16 < 3;
    if (!resultWord) {
        goto titleBlock391;
    }
    TitleMenu7566C_D_title_8007F130 = (unsigned char)savedWord16;
    goto titleBlock391;
titleBlock336:
    if (!(TitleMenu7566C_D_8006E53C & 0x8000)) {
        goto titleBlock391;
    }
    resultWord = TitleMenu7566C_D_title_8007F130;
    workWord = (int)&TitleMenu7566C_D_title_8007F3D4;
    TitleMenu7566CKeep(workWord);
    savedWord16 = resultWord - 1;
    resultWord = savedWord16 * 0x900;
    savedWord17 = resultWord + workWord;
loop_338:
    if (TitleMenu7566C_func_title_8007928C(savedWord17) >= 0) {
        goto titleBlock341;
    }
    savedWord17 -= 0x900;
    if (savedWord16 < 0) {
        goto titleBlock341;
    }
    savedWord16 -= 1;
    goto loop_338;
titleBlock341:
    MATCHING_KEEP_VOLATILE(savedWord16);
    if (savedWord16 < 0) {
        goto titleBlock391;
    }
    TitleMenu7566C_D_title_8007F130 = (unsigned char)savedWord16;
    goto titleBlock391;
title2390_dispatch1_selector18:
    argumentWord4 = 1;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$16");
    savedWord16 = (int)&TitleMenu7566C_D_800725B0;
    TitleMenu7566CKeep(savedWord16);
    resultWord = TitleMenu7566C_func_title_8007D218(argumentWord4, savedWord16, savedWord16 + 4);
    argumentWord4 = 1;
    if (!resultWord)
        goto titleBlock391;
    savedWord17 = (int)&TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(savedWord17);
    workWord = TitleMenu7566CField(savedWord17, unsigned char*, 0);
    TitleMenu7566CKeep(workWord);
    if (workWord == argumentWord4)
        goto titleBlock353;
    if (workWord >= 2)
        goto titleBlock348;
    if (!workWord)
        goto titleBlock351;
    goto titleBlock391;
titleBlock348:
    resultWord = 2;
    if (workWord == resultWord)
        goto titleBlock362;
    resultWord = 3;
    if (workWord == resultWord)
        goto titleBlock363;
    goto titleBlock391;
titleBlock351:
    temp_a3 = TitleMenu7566C_D_800725E4 * 0x900;
    TitleMenu7566C_func_title_8007CD68(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10,
        TitleMenu7566C_D_title_8007EC9C, temp_a3 + (int)&TitleMenu7566C_D_title_8007F3D4,
        temp_a3 + 0x280, 0x900);
titleBlock352:
    resultWord = 1;
    TitleMenu7566CField(savedWord17, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock353:
    resultWord = TitleMenu7566CField(savedWord16, int*, 4);
    if (resultWord) {
        goto titleBlock359;
    }
    if (TitleMenu7566C_func_title_80078BF4((TitleMenu7566C_D_800725E4 * 0x900) +
                                           (int)&TitleMenu7566C_D_title_8007F3D4) !=
        TitleMenu7566CField(
            ((int)&TitleMenu7566C_D_title_8007FCD0 + (TitleMenu7566C_D_800725E4 * 0x900)), int*,
            0)) {
        goto titleBlock356;
    }
titleBlock355:
    resultWord = 2;
    TitleMenu7566CField(savedWord17, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock356:
    workWord = TitleMenu7566C_D_title_8007F132;
    if ((unsigned)workWord >= 3)
        goto titleBlock358;
    resultWord = workWord + 1;
titleBlock357:
    TitleMenu7566C_D_title_8007F132 = resultWord;
    TitleMenu7566CField(savedWord17, unsigned char*, 0) = 0;
    goto titleBlock391;
titleBlock358:
    resultWord = 23;
    goto titleState23Retry18Entry;
titleBlock359:
    if ((unsigned char)TitleMenu7566C_D_title_8007F132 >= 3U) {
        goto titleBlock361;
    }
    temp_a3_2 = TitleMenu7566C_D_800725E4 * 0x900;
    TitleMenu7566C_func_title_8007CD68(
        TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0) * 0x10,
        TitleMenu7566C_D_title_8007EC9C, temp_a3_2 + (int)&TitleMenu7566C_D_title_8007F3D4,
        temp_a3_2 + 0x280, 0x900);
    resultWord = TitleMenu7566C_D_title_8007F132;
    workWord = 1;
    TitleMenu7566CField(savedWord17, unsigned char*, 0) = workWord;
    resultWord++;
    TitleMenu7566C_D_title_8007F132 = resultWord;
    goto titleBlock391;
titleBlock361:
    resultWord = 0x17;
    goto titleBlock390;
titleBlock362:
    TitleMenu7566C_D_800725B8 = 1;
    TitleMenu7566C_D_800725BC = TitleMenu7566CField((int)&TitleMenu7566C_D_800725E0, int*, 0);
    TitleMenu7566C_D_800725C0 = TitleMenu7566C_D_800725E4;
    TitleMenu7566C_D_800725C4 = TitleMenu7566CField(
        ((int)&TitleMenu7566C_D_title_8007F3D4 + (TitleMenu7566C_D_800725E4 * 0x900)), int*, 0);
    TitleMenu7566C_func_title_8007C93C();
    resultWord = 3;
    TitleMenu7566CField(savedWord17, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock363:
    TitleMenu7566C_func_title_80078EAC((TitleMenu7566C_D_800725E4 * 0x900) +
                                       (int)&TitleMenu7566C_D_title_8007F3D4);
    resultWord = 0x13;
    goto titleBlock390;
title2390_dispatch1_selector19:
    if (!TitleMenu7566C_func_title_8007D218(1, (int)&TitleMenu7566C_D_800725B0,
                                            (int)&TitleMenu7566C_D_800725B0 + 4))
        goto titleBlock391;
    savedWord16 = (int)&TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(savedWord16);
    workWord = TitleMenu7566CField(savedWord16, unsigned char*, 0);
    resultWord = 1;
    if (!workWord)
        goto titleBlock372;
    if (workWord != resultWord)
        goto titleBlock391;
    resultWord = 20;
    goto titleBlock390;
title2390_dispatch1_selector21:
    if (!TitleMenu7566C_func_title_8007D218(1, (int)&TitleMenu7566C_D_800725B0,
                                            (int)&TitleMenu7566C_D_800725B0 + 4))
        goto titleBlock391;
    savedWord16 = (int)&TitleMenu7566C_D_title_8007F12E;
    TitleMenu7566CKeep(savedWord16);
    savedWord17 = TitleMenu7566CField(savedWord16, unsigned char*, 0);
    resultWord = 1;
    if (!savedWord17)
        goto titleBlock372;
    if (savedWord17 == resultWord)
        goto titleBlock373;
    goto titleBlock391;
titleBlock372:
    TitleMenu7566C_func_title_8007C268();
    resultWord = TitleMenu7566CField(savedWord16, unsigned char*, 0);
    resultWord++;
    TitleMenu7566CField(savedWord16, unsigned char*, 0) = resultWord;
    goto titleBlock391;
titleBlock373:
    TitleMenu7566C_func_title_80079B94();
    temp_a0_3 = TitleMenu7566CField((int)&TitleMenu7566C_g_CheatFlags, unsigned char*, 3);
    TitleMenu7566CField((int)&TitleMenu7566C_g_CheatFlags, unsigned char*, 3) = 0U;
    TitleMenu7566C_D_8006C7E4 = 0;
    TitleMenu7566C_D_8006C734 = (int)temp_a0_3;
    temp_a0_4 = TitleMenu7566CField(((int)&TitleMenu7566C_D_80066EDC + TitleMenu7566C_D_8006C3F0),
                                    unsigned char*, 0);
    TitleMenu7566C_D_8006C5BC = (int)temp_a0_4;
    temp_v1_2 = TitleMenu7566CField(((int)&TitleMenu7566C_D_80066EE4 + TitleMenu7566C_D_8006C3F0),
                                    unsigned char*, 0);
    temp_v0_18 = TitleMenu7566C_D_8006C3F0 + 1;
    TitleMenu7566C_D_8006C3F0 = temp_v0_18;
    TitleMenu7566C_D_8006C5C8 = (int)temp_v1_2;
    if (TitleMenu7566CField(((int)&TitleMenu7566C_D_80066EDC + temp_v0_18), unsigned char*, 0) !=
        0xFF) {
        goto titleBlock375;
    }
    TitleMenu7566C_D_8006C3F0 = 0;
titleBlock375:
    TitleMenu7566C_D_8006C7C4 = (int)savedWord17;
    if ((unsigned int)(temp_a0_4 - 0xD) >= 0x20U) {
        goto titleBlock385;
    }
    switch (temp_a0_4) {
        case 13:
            goto title2390_dispatch4_selector13;
        case 22:
            goto title2390_dispatch4_selector22;
        case 31:
            goto title2390_dispatch4_selector31;
        case 33:
            goto title2390_dispatch4_selector33;
        case 35:
            goto title2390_dispatch4_selector35;
        case 44:
            goto title2390_dispatch4_selector44;
        default:
            goto titleBlock385;
    }
title2390_dispatch4_selector13:
    resultWord = 0xBB79;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA2C = resultWord;
    resultWord = 0xB3DF;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA30 = resultWord;
    resultWord = 0x3915;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA34 = resultWord;
    resultWord = 0x41C;
    goto titleBlock384;
title2390_dispatch4_selector22:
    resultWord = 0xE0CD;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA2C = resultWord;
    resultWord = 0x3C76;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA30 = resultWord;
    resultWord = 0x6323;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA34 = resultWord;
    resultWord = 0x410;
    goto titleBlock384;
title2390_dispatch4_selector31:
    workWord = 0x1DECD;
    TitleMenu7566CKeep(workWord);
    resultWord = 0x15700;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA30 = resultWord;
    resultWord = 0x3C00;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA34 = resultWord;
    TitleMenu7566C_D_8006FA2C = workWord;
    resultWord = 0x200;
    goto titleBlock384;
title2390_dispatch4_selector33:
    if (TitleMenu7566C_D_8006C5C8 == 0) {
        goto titleBlock385;
    }
    resultWord = 0x6A0C;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA2C = resultWord;
    resultWord = 0x849A;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA30 = resultWord;
    resultWord = 0x4C76;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA34 = resultWord;
    resultWord = 0x41B;
    goto titleBlock384;
title2390_dispatch4_selector35:
    argumentWord4 = 0x1510C;
    TitleMenu7566CKeep(argumentWord4);
    workWord = 0x267B4;
    TitleMenu7566CKeep(workWord);
    resultWord = 1;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA40 = resultWord;
    resultWord = 0x4400;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA50 = resultWord;
    TitleMenu7566C_D_8006FA48 = argumentWord4;
    TitleMenu7566C_D_8006FA4C = workWord;
    resultWord = 0xC0;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA54 = resultWord;
    goto titleBlock385;
title2390_dispatch4_selector44:
    resultWord = 0x2F31B;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA2C = resultWord;
    resultWord = 0xD84A;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA30 = resultWord;
    resultWord = 0x3575;
    TitleMenu7566CKeep(resultWord);
    TitleMenu7566C_D_8006FA34 = resultWord;
    resultWord = 0x3F0;
titleBlock384:
    TitleMenu7566C_D_8006C5C0 = resultWord;
titleBlock385:
    TitleMenu7566CBeginLevelWarp(0, TitleMenu7566C_D_8006C5BC);
    TitleMenu7566C_D_8006C658 = 1;
    TitleMenu7566C_D_8006C55C = 0x80100000;
    TitleMenu7566C_D_8006C538 = 0x80100004;
    goto titleBlock391;
title2390_dispatch1_selector20:
    TitleMenu7566C_func_title_80079B94();
    if (TitleMenu7566C_D_8006C5BC != 0) {
        goto titleBlock388;
    }
    TitleMenu7566C_D_8006C534 = 1;
    TitleMenu7566CBeginLevelWarp(6, 0x3D);
    goto titleBlock391;
titleBlock388:
    TitleMenu7566CBeginLevelWarp(0, TitleMenu7566C_D_8006C5BC);
    goto titleBlock391;
title2390_dispatch1_selector22:
title2390_dispatch1_selector23:
    resultWord = TitleMenu7566C_D_8006E53C;
    resultWord &= 0x850;
    if (!resultWord)
        goto titleBlock391;
    resultWord = 2;
titleState7LookupEntry:
    MATCHING_KEEP(resultWord);
titleState7RecordEntry:
    MATCHING_KEEP_VOLATILE(resultWord);
titleState23Retry8Entry:
    __asm__("" : "=g"(resultWord) : "0"(resultWord));
titleState23Retry9Entry:
    __asm__ volatile("" : "=g"(resultWord) : "0"(resultWord));
titleState23Validation3Entry:
    __asm__("" : "=r"(resultWord) : "0"(resultWord), "r"(resultWord));
titleState23Validation4Entry:
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "r"(resultWord));
titleState23Choice16Entry:
    __asm__("" : "=g"(resultWord) : "0"(resultWord), "r"(resultWord));
titleState23Retry18Entry:
    __asm__ volatile("" : "=g"(resultWord) : "0"(resultWord), "r"(resultWord));
titleState23ValidationResultEntry:
    __asm__("" : "=r"(resultWord) : "0"(resultWord), "r"(resultWord), "r"(resultWord));
titleState13ValidationEntry:
    __asm__ volatile("" : "=r"(resultWord) : "0"(resultWord), "r"(resultWord), "r"(resultWord));
titleState23HeaderRetryEntry:
    __asm__("" : "=g"(resultWord) : "0"(resultWord), "r"(resultWord), "r"(resultWord));
titleBlock390:
    TitleMenu7566C_D_title_8007F12C = resultWord;
titleBlock391:
    __asm__ volatile("" ::"i"(&TitleMenu7566C_D_title_8007F12C) : "memory");
    workWord = TitleMenu7566C_D_title_8007F12C;
    resultWord = TitleMenu7566C_D_title_8007F12D;
    if (workWord == resultWord)
        goto titleBlock393;
    TitleMenu7566C_D_title_8007F12D = workWord;
    TitleMenu7566C_D_title_8007F12E = 0;
    TitleMenu7566C_D_title_8007F12F = 0;
    TitleMenu7566C_D_title_8007F130 = 0;
    TitleMenu7566C_D_title_8007F131 = 0;
    TitleMenu7566C_D_title_8007F132 = 0;
    TitleMenu7566C_D_title_8007F134 = 0;
    TitleMenu7566C_D_title_8007F138 = 0;
    return;
titleBlock393:
    workWord = TitleMenu7566C_D_title_8007F12E;
    resultWord = TitleMenu7566C_D_title_8007F12F;
    if (workWord == resultWord)
        goto titleBlock395;
    resultWord = TitleMenu7566C_D_title_8007F130;
    TitleMenu7566C_D_title_8007F12F = workWord;
    goto titleBlock397;
titleBlock395:
    workWord = TitleMenu7566C_D_title_8007F130;
    resultWord = TitleMenu7566C_D_title_8007F131;
    argumentWord5 = 0;
    if (workWord == resultWord)
        goto titleBlock398;
    resultWord = TitleMenu7566C_D_8006C654;
    argumentWord4 = TitleMenu7566CField(resultWord, unsigned char*, 0x18);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$6");
    resultWord = TitleMenu7566C_PlaySound(argumentWord4, argumentWord5, 0x80);
    resultWord = TitleMenu7566C_D_title_8007F130;
titleBlock397:
    TitleMenu7566C_D_title_8007F134 = 0;
    TitleMenu7566C_D_title_8007F138 = 0;
    TitleMenu7566C_D_title_8007F131 = resultWord;
    return;
titleBlock398:
    resultWord = TitleMenu7566C_D_title_8007F134;
    argumentWord4 = TitleMenu7566C_D_8006C648;
    workWord = TitleMenu7566C_D_title_8007F138;
    resultWord += argumentWord4;
    workWord += argumentWord4;
    TitleMenu7566C_D_title_8007F134 = resultWord;
    TitleMenu7566C_D_title_8007F138 = workWord;
    return;
}
#undef TitleMenu7566CField

#undef TitleMenu7566CKeep

extern int D_8006C76C;
extern char* D_title_8007EEC0[];
void func_title_80077BC4(void) {
    DrawStringCentered(D_title_8007EEC0[D_8006C76C], 0x100, 0xD2, 2);
}

extern unsigned char D_title_8007F133;
extern unsigned short DecodedTitleSine[] __asm__("D_80065920");
void func_title_80077C04(void) {
    int frame, x, y;
    SpriteData* sprite;
    frame = D_8006C738[func_80027934(1103)].frame;
    sprite = (SpriteData*)(frame * sizeof(SpriteData) + (unsigned int)D_8006C788);
    y = D_title_8007F133;
    x = 256 - ((sprite->unk4 - sprite->unk0 + 1) >> 1);
    if ((unsigned int)y < 80)
        y -= 60;
    else if ((unsigned int)y < 112)
        y = (((int)(DecodedTitleSine[((y - 80) << 3) & 248] << 16)) >> 26) + 20;
    else if ((unsigned int)y < 144)
        y = (((int)(DecodedTitleSine[((y - 112) << 3) & 248] << 16)) >> 27) + 20;
    else
        y = 20;
    func_800289C8(&D_8006C788[frame], x, y);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80077CFC.
* Assembly SHA256 57aa23b19f60be29e87fb76106712daca029168ca1cb5090e0a5c56a769f61a1.
* AI generated; not human reviewed. All723 original instructions and
* actual branch/call/internal targets are required. The selector table
* has23 entries with bias1 and no owned padding. Frame20 preserves the
* original S0/S1/S2/RA save/restore words; no local spill is introduced.
* Language/string table accesses remain original LW words at exact byte
* offsets. Repeated states retain their original independent status/time
* loads, selection tests and physical joins. All seven literal1/status-byte
* load slots, zero argument branch slots, signed half-difference producers,
* both rectangle field triples and final independent table-index reloads
* remain exact. The source generator shares analysis-time patterns only;
* no generated runtime helper or guessed string/layout contract is added.
* Empty initialized constraints, original-address immediates and clobbers
* of dead registers emit no CPU instructions. No partial HI, FP shortcut
* or opcode assembly is used. Raw units/fixed point, full helper contracts,
* caller cadence and synchronized retail runtime remain unresolved.
* Cadence here is per invocation; confidence is binary identity only.
* Falsification: every native/linked word and actual target, all selectors,
* full EXE and every overlay retail hash must remain identical. */
#define TitleField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char TitleCallDrawStringCenteredView1() __asm__("DrawStringCentered");
unsigned char TitleCallDrawStringRowCenteredView1() __asm__("DrawStringRowCentered");
unsigned char TitleDispatchFrameRenderMaskView1() __asm__("func_8001E460");
int TitleFindHudClassIndexView1() __asm__("func_80027934");
int TitleSelectHudIconAnimationFrameView1() __asm__("func_80028378");
void* TitleEmitHudTexturedQuadsView1() __asm__("func_800289C8");
unsigned char TitleCall77BC4View1() __asm__("func_title_80077BC4");
unsigned char TitleCall77C04View1() __asm__("func_title_80077C04");
unsigned char TitleCall7AA54View1() __asm__("func_title_8007AA54");
unsigned char TitleCall7AB24View1() __asm__("func_title_8007AB24");
extern unsigned char TitleData69DD8View1 __asm__("D_80069DD8");
extern unsigned char TitleData69DDCView1 __asm__("D_80069DDC");
extern int TitleData6C738View1 __asm__("D_8006C738");
extern int TitleData6C76CView1 __asm__("D_8006C76C");
extern int TitleData6C788View1 __asm__("D_8006C788");
extern int TitleData725E0View1 __asm__("D_800725E0");
extern unsigned char TitleData7EEA0View1 __asm__("D_title_8007EEA0");
extern unsigned char TitleData7EEA4View1 __asm__("D_title_8007EEA4");
extern unsigned char TitleData7EEACView1 __asm__("D_title_8007EEAC");
extern unsigned char TitleData7EEB0View1 __asm__("D_title_8007EEB0");
extern unsigned char TitleData7EEB4View1 __asm__("D_title_8007EEB4");
extern unsigned char TitleData7EEB8View1 __asm__("D_title_8007EEB8");
extern unsigned char TitleData7EEC4View1 __asm__("D_title_8007EEC4");
extern unsigned char TitleData7EEC8View1 __asm__("D_title_8007EEC8");
extern unsigned char TitleData7EED0View1 __asm__("D_title_8007EED0");
extern unsigned char TitleData7EFE8View1 __asm__("D_title_8007EFE8");
extern unsigned char TitleData7EFECView1 __asm__("D_title_8007EFEC");
extern unsigned char TitleData7EFF4View1 __asm__("D_title_8007EFF4");
extern unsigned char TitleData7EFF8View1 __asm__("D_title_8007EFF8");
extern unsigned char TitleData7EFFCView1 __asm__("D_title_8007EFFC");
extern unsigned char TitleData7F000View1 __asm__("D_title_8007F000");
extern unsigned char TitleData7F004View1 __asm__("D_title_8007F004");
extern unsigned char TitleData7F008View1 __asm__("D_title_8007F008");
extern unsigned char TitleData7F00CView1 __asm__("D_title_8007F00C");
extern unsigned char TitleData7F010View1 __asm__("D_title_8007F010");
extern unsigned char TitleData7F014View1 __asm__("D_title_8007F014");
extern unsigned char TitleData7F018View1 __asm__("D_title_8007F018");
extern unsigned char TitleData7F01CView1 __asm__("D_title_8007F01C");
extern unsigned char TitleData7F12CView1 __asm__("D_title_8007F12C");
extern unsigned char TitleData7F12EView1 __asm__("D_title_8007F12E");
extern unsigned char TitleData7F130View1 __asm__("D_title_8007F130");
extern int TitleData7F134View1 __asm__("D_title_8007F134");
extern signed char TitleData7F13FView1 __asm__("D_title_8007F13F");
void func_title_80077CFC(void) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"),
        argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int selectionPointerOrHalfWidth16 __asm__("$16"), verticalOffset17 __asm__("$17"),
        selectedByte18 __asm__("$18");
    TitleDispatchFrameRenderMaskView1(13);
    switch (TitleData7F12CView1) {
        case 1:
            TitleCall77C04View1();
            argumentWord7 = 2;
            if (TitleData7F12EView1 == 1) {
                argumentWord7 = 2;
                MATCHING_KEEP(argumentWord7);
                argumentWord4 = (int)&TitleData7EEA0View1;
                MATCHING_KEEP(argumentWord4);
                rawWord2 = TitleData6C76CView1;
                rawWord3 = TitleData7F134View1;
                rawWord2 <<= 2;
                rawWord3 &= 31;
                rawWord3 = rawWord3 < 22;
                rawWord2 += argumentWord4;
                if (rawWord3)
                    argumentWord7 = 3;
                argumentWord4 = TitleField(rawWord2, int*, 0);
                argumentWord5 = 256;
                argumentWord6 = 210;
                TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                                 argumentWord7);
            }
            break;
        case 2:
        case 6:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EFE8View1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x80077dd8) : "memory");
            argumentWord6 = 66;
            goto drawSharedMessageRow;
        case 3:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EFECView1, int*, rawWord2);
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData7EEA4View1;
            MATCHING_KEEP(argumentWord4);
            selectionPointerOrHalfWidth16 = (int)&TitleData7F130View1;
            MATCHING_KEEP(selectionPointerOrHalfWidth16);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$3", "memory");
            rawWord3 = (int)&TitleData7EEACView1;
            MATCHING_KEEP(rawWord3);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x80077eac)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 4:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EFF4View1, int*, rawWord2);
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            rawWord3 = (int)&TitleData7EEA4View1;
            MATCHING_KEEP(rawWord3);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$16", "memory");
            selectionPointerOrHalfWidth16 = (int)&TitleData7F130View1;
            MATCHING_KEEP(selectionPointerOrHalfWidth16);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData7EEACView1;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x80077f80)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 5:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EFF8View1, int*, rawWord2);
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData7EEB0View1;
            MATCHING_KEEP(argumentWord4);
            selectionPointerOrHalfWidth16 = (int)&TitleData7F130View1;
            MATCHING_KEEP(selectionPointerOrHalfWidth16);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$3", "memory");
            rawWord3 = (int)&TitleData7EEB4View1;
            MATCHING_KEEP(rawWord3);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x80078054)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 7:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EFFCView1, int*, rawWord2);
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData69DD8View1;
            MATCHING_KEEP(argumentWord4);
            selectionPointerOrHalfWidth16 = (int)&TitleData7F130View1;
            MATCHING_KEEP(selectionPointerOrHalfWidth16);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$3", "memory");
            rawWord3 = (int)&TitleData69DDCView1;
            MATCHING_KEEP(rawWord3);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x80078128)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 8:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F004View1, int*, rawWord2);
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            rawWord3 = (int)&TitleData69DD8View1;
            MATCHING_KEEP(rawWord3);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$16", "memory");
            selectionPointerOrHalfWidth16 = (int)&TitleData7F130View1;
            MATCHING_KEEP(selectionPointerOrHalfWidth16);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData69DDCView1;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x800781fc)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 9:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F008View1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x8007822c) : "memory");
            argumentWord6 = 66;
            goto drawSharedMessageRow;
        case 10:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F000View1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x8007825c) : "memory");
            argumentWord6 = 66;
            goto drawSharedMessageRow;
        case 11:
            TitleCall7AA54View1(16);
            break;
        case 12:
            TitleCall7AA54View1(16);
            rawWord2 = TitleData7F12EView1;
            argumentWord4 = -1;
            if (!rawWord2)
                goto finishSharedSelection;
            TitleCall7AB24View1(argumentWord4, 56);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData7EEC4View1;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleData7F130View1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$3", "memory");
            rawWord3 = (int)&TitleData7EEA4View1;
            MATCHING_KEEP(rawWord3);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleData7F130View1;
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x80078334)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 13:
            TitleCall7AA54View1(16);
            rawWord3 = TitleData7F12EView1;
            rawWord2 = 1;
            if (rawWord3 == rawWord2) {
                argumentWord4 = -1;
                goto drawState13Selector;
            }
            rawWord2 = 2;
            argumentWord5 = 192;
            if (rawWord3 != rawWord2)
                goto drawState13Text;
            argumentWord4 = TitleData7F130View1;
        drawState13Selector:
            TitleCall7AB24View1(argumentWord4, 56);
            argumentWord5 = 192;
        drawState13Text:
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 98;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EEC4View1, int*, rawWord2);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            argumentWord5 = 320;
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$6", "memory");
            argumentWord6 = 98;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EEA4View1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x800783C0) : "$7", "memory");
            argumentWord7 = 3;
            goto drawSharedSelection;
        case 14:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F010View1, int*, rawWord2);
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            rawWord3 = (int)&TitleData69DD8View1;
            MATCHING_KEEP(rawWord3);
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$16", "memory");
            selectionPointerOrHalfWidth16 = (int)&TitleData7F130View1;
            MATCHING_KEEP(selectionPointerOrHalfWidth16);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + rawWord3;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            __asm__ __volatile__("" ::: "$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__("" ::"r"(rawWord2) : "$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = 192;
            argumentWord6 = 98;
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7 | 2);
            argumentWord7 = 0;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData69DDCView1;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleField(selectionPointerOrHalfWidth16, unsigned char*, 0);
            rawWord2 <<= 2;
            argumentWord4 = rawWord2 + argumentWord4;
            if (!rawWord3) {
                rawWord2 = TitleData7F134View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord4 = TitleField(argumentWord4, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
            __asm__ __volatile__(""
                                 : "=r"(argumentWord7)
                                 : "0"(argumentWord7), "i"(0x80078494)
                                 : "memory");
            argumentWord7 |= 2;
            goto drawSharedSelection;
        case 15:
            TitleCall7AA54View1(16);
            argumentWord4 = (int)&TitleData7F12EView1;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = TitleField(argumentWord4, unsigned char*, 0);
            argumentWord4 += 14;
            if (rawWord2) {
                rawWord2 = TitleSelectHudIconAnimationFrameView1(argumentWord4, 0);
                TitleData7F13FView1 = rawWord2;
                rawWord2 &= 255;
                rawWord2 <<= 3;
                argumentWord4 = TitleData6C788View1;
                selectionPointerOrHalfWidth16 = 54;
                argumentWord4 = argumentWord4 + rawWord2;
                argumentWord6 = TitleField(argumentWord4, unsigned char*, 4);
                argumentWord5 = TitleField(argumentWord4, unsigned char*, 0);
                rawWord2 = TitleField(argumentWord4, unsigned char*, 5);
                rawWord3 = TitleField(argumentWord4, unsigned char*, 1);
                argumentWord6 -= argumentWord5;
                rawWord2 -= rawWord3;
                verticalOffset17 = rawWord2 >> 1;
                rawWord2 = argumentWord6 >> 1;
                argumentWord5 = 256;
                argumentWord5 -= rawWord2;
                TitleEmitHudTexturedQuadsView1(argumentWord4, argumentWord5,
                                               selectionPointerOrHalfWidth16 - verticalOffset17);
                rawWord2 = TitleFindHudClassIndexView1(1102);
                rawWord3 = TitleData6C738View1;
                rawWord2 <<= 3;
                rawWord2 += rawWord3;
                selectedByte18 = TitleField(rawWord2, unsigned char*, 2);
                rawWord2 = TitleData6C788View1;
                argumentWord4 = selectedByte18 * 8 + rawWord2;
                argumentWord6 = TitleField(argumentWord4, unsigned char*, 4);
                argumentWord5 = TitleField(argumentWord4, unsigned char*, 0);
                rawWord2 = TitleField(argumentWord4, unsigned char*, 5);
                rawWord3 = TitleField(argumentWord4, unsigned char*, 1);
                argumentWord6 -= argumentWord5;
                rawWord2 -= rawWord3;
                verticalOffset17 = rawWord2 >> 1;
                verticalOffset17 = selectionPointerOrHalfWidth16 - verticalOffset17;
                selectionPointerOrHalfWidth16 = argumentWord6 >> 1;
                argumentWord5 = 344;
                argumentWord5 -= selectionPointerOrHalfWidth16;
                rawWord2 = (int)TitleEmitHudTexturedQuadsView1(argumentWord4, argumentWord5,
                                                               verticalOffset17);
                rawWord3 = TitleData7F134View1;
                rawWord3 &= 31;
                rawWord3 = rawWord3 < 22;
                argumentWord4 = rawWord2;
                if (!rawWord3) {
                    rawWord2 = 64;
                    TitleField(argumentWord4, unsigned char*, 4) = rawWord2;
                    TitleField(argumentWord4, unsigned char*, 5) = rawWord2;
                    TitleField(argumentWord4, unsigned char*, 6) = rawWord2;
                }
                selectedByte18++;
                MATCHING_KEEP(selectedByte18);
                argumentWord5 = 168;
                argumentWord5 -= selectionPointerOrHalfWidth16;
                argumentWord6 = verticalOffset17;
                rawWord2 = TitleData6C788View1;
                argumentWord4 = selectedByte18 * 8;
                rawWord2 = (int)TitleEmitHudTexturedQuadsView1(rawWord2 + argumentWord4,
                                                               argumentWord5, argumentWord6);
                rawWord3 = TitleData7F134View1;
                rawWord3 &= 31;
                rawWord3 = rawWord3 < 22;
                argumentWord4 = rawWord2;
                if (!rawWord3) {
                    rawWord2 = 64;
                    TitleField(argumentWord4, unsigned char*, 4) = rawWord2;
                    TitleField(argumentWord4, unsigned char*, 5) = rawWord2;
                    TitleField(argumentWord4, unsigned char*, 6) = rawWord2;
                }
            }
            argumentWord7 = 2;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData7EEC8View1;
            MATCHING_KEEP(argumentWord4);
            rawWord2 = TitleData6C76CView1;
            rawWord3 = TitleData7F134View1;
            rawWord2 <<= 2;
            rawWord3 &= 31;
            rawWord3 = rawWord3 < 22;
            rawWord2 += argumentWord4;
            if (rawWord3)
                argumentWord7 = 3;
            argumentWord4 = TitleField(rawWord2, int*, 0);
            argumentWord5 = 256;
            argumentWord6 = 76;
            goto drawSharedSelection;
        case 16:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F00CView1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x8007865c) : "memory");
            argumentWord6 = 66;
            goto drawSharedMessageRow;
        case 17:
            TitleCall7AA54View1(16);
            rawWord2 = TitleData7F12EView1;
            argumentWord4 = -1;
            if (rawWord2)
                argumentWord4 = TitleData7F130View1;
            TitleCall7AB24View1(argumentWord4, 56);
            argumentWord5 = 192;
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 98;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EEC4View1, int*, rawWord2);
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, 3);
            argumentWord5 = 320;
            rawWord2 = TitleData6C76CView1;
            __asm__ __volatile__("" ::: "$6", "memory");
            argumentWord6 = 98;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7EEA4View1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x800786D8) : "$7", "memory");
            argumentWord7 = 2;
            goto drawSharedSelection;
        case 18:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F014View1, int*, rawWord2);
        drawSharedMessageRow:
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            break;
        case 22:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F01CView1, int*, rawWord2);
            __asm__ __volatile__("" ::"i"(0x80078740) : "memory");
            argumentWord6 = 66;
            goto drawFinalMessageRow;
        case 23:
            TitleCall7AA54View1(16);
            argumentWord5 = 256;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = TitleData6C76CView1;
            argumentWord6 = 66;
            rawWord2 <<= 2;
            argumentWord4 = TitleField(&TitleData7F018View1, int*, rawWord2);
        drawFinalMessageRow:
            TitleCallDrawStringRowCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            argumentWord7 = 2;
            MATCHING_KEEP(argumentWord7);
            argumentWord4 = (int)&TitleData7EED0View1;
            MATCHING_KEEP(argumentWord4);
            rawWord3 = TitleData6C76CView1;
            rawWord2 = TitleData7F134View1;
            rawWord3 <<= 2;
            rawWord2 &= 31;
            rawWord2 = rawWord2 < 22;
            rawWord3 += argumentWord4;
            if (rawWord2)
                argumentWord7 = 3;
            argumentWord4 = TitleField(rawWord3, int*, 0);
            argumentWord5 = 320;
            argumentWord6 = 98;
        drawSharedSelection:
            TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
        finishSharedSelection:
            TitleCall77BC4View1();
    }
    rawWord2 = TitleData725E0View1;
    if (rawWord2 < 0)
        return;
    rawWord2 = TitleData7F12CView1;
    argumentWord5 = 256;
    if ((unsigned int)rawWord2 < 2)
        return;
    argumentWord6 = 21;
    MATCHING_KEEP(argumentWord6);
    argumentWord4 = (int)&TitleData7EEB8View1;
    MATCHING_KEEP(argumentWord4);
    rawWord2 = TitleData6C76CView1;
    rawWord3 = TitleData725E0View1;
    rawWord2 <<= 3;
    rawWord2 += argumentWord4;
    rawWord3 <<= 2;
    rawWord3 += rawWord2;
    MATCHING_KEEP(rawWord3);
    argumentWord4 = TitleField(rawWord3, int*, 0);
    TitleCallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
}
#undef TitleField

int func_8004F820(void*, void*, int);
int VSync(int);
void func_title_80078848(void* source, unsigned long* pixels, int y) {
    int index;
    RECT rectangle;
    for (index = 4; index < 16; index++) {
        int size = func_8004F820(source, pixels, (15 - index) * 2);
        VSync(0);
        rectangle.y = y - (size >> 11);
        rectangle.x = 0;
        rectangle.w = 0x200;
        rectangle.h = size >> 10;
        LoadImage(&rectangle, pixels);
        rectangle.y += 0xE4;
        LoadImage(&rectangle, pixels);
        DrawSync(0);
    }
}

/* AI generated; not human reviewed. Retail save/reset fields retain numeric labels. */
extern int D_8006C784, D_8006C3F8, D_8006C3FC, D_8006C5BC, D_8006C7B0, D_8006E4AC, D_8006C400,
    D_8006C5D0, D_8006C584, D_8006C7A8, D_8006C7C4, D_8006C70C, D_8006C710, D_8006C660, D_8006C71C;
extern unsigned char D_8006E50C, D_8007201C;
extern unsigned char ResetCheats[] __asm__("g_CheatFlags");
extern unsigned char D_800716AC[40][6], D_800715BC[40][6];
extern unsigned char D_80070300[], D_80071A10[], D_80071AB0[], D_80071FB0[], D_80071570[],
    D_8007145C[], D_8006C408[], D_80066EEC[];
extern short D_80066EAE[];
extern int ResetRecords[4][11] __asm__("speedwayRecords");
extern void ActivateSparxPowers(void);
void func_title_80078918(void) {
    register int i __asm__("$8") = 0;
    register int offset __asm__("$2");
    register int one __asm__("$3");
    register int first __asm__("$2");
    register int lives __asm__("$2");
    register unsigned char* performance __asm__("$6") = &D_800716AC[0][0];
    register unsigned char* thresholds __asm__("$7") = &D_800715BC[0][0];
    lives = 4;
    MATCHING_KEEP(lives);
    D_8006C784 = lives;
    first = 1;
    MATCHING_KEEP_CLOBBER(first, "$3");
    one = 1;
    D_8006E50C = first;
    D_8007201C = first;
    D_8006C3F8 = 10;
    D_8006C3FC = 10;
    D_8006C5BC = 0;
    ResetCheats[2] = 0;
    D_8006C7B0 = one;
    D_8006E4AC = 0x5FFF;
    D_8006C400 = one;
    D_8006C5D0 = 0;
    D_8006C584 = 0;
    D_8006C7A8 = 0;
    D_8006C7C4 = 0;
    D_8006C70C = 0;
    D_8006C710 = 0;
    do {
        register unsigned char* p __asm__("$3") = performance;
        register unsigned char* t __asm__("$4") = thresholds;
        register unsigned char* end __asm__("$5") = performance + 6;
        do {
            *t++ = 0;
            *p++ = 0;
        } while ((int)p < (int)end);
        performance += 6;
        thresholds += 6;
    } while (++i < 40);
    D_8006C660 = 0;
    func_8004E790(D_80070300, 0, 40);
    D_8006C71C = 0;
    func_8004E790(D_80071A10, 0, 160);
    func_8004E790(D_80071AB0, 0, 1280);
    func_8004E790(D_80071FB0, 0, 40);
    func_8004E790(D_80071570, 0, 76);
    func_8004E790(D_8007145C, 0, 40);
    func_8004E790(D_8006C408, 0, 8);
    func_8004E790(D_80066EEC, 0, 32);
    offset = 44;
    do {
        *(short*)((char*)D_80066EAE + offset) = 0;
        offset -= 4;
    } while (offset >= 0);
    {
        register int recordIndex __asm__("$4") = 0;
        register int recordValue __asm__("$5") = 36000;
        register int recordOffset __asm__("$3") = 0;
        do {
            *(int*)((char*)ResetRecords + recordOffset + 16) = 0;
            *(int*)((char*)ResetRecords + recordOffset + 20) = recordValue;
            *(int*)((char*)ResetRecords + recordOffset + 28) = 0;
            *(int*)((char*)ResetRecords + recordOffset + 40) = recordValue;
            *(int*)((char*)ResetRecords + recordOffset + 36) = 0;
            recordOffset += 44;
        } while (++recordIndex < 4);
    }
    ActivateSparxPowers();
}
