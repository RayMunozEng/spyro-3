#include "common.h"
#include "environment.h"
#include "hud.h"
#include "tracers.h"
#include "savepoint.h"
#include "camera.h"
#include "mobyupdate.h"
#include "pad.h"
#include "spu.h"
#include "stdutil.h"
#include "str.h"
#include "warp.h"
#include "ovl_header.h"
#include "spyro.h"

// spyroupdate
extern void func_8003E83C(); // UpdateSpyro

// updatepause
extern void func_80057834(); // pause updates

//extern void func_title_8007566C(); // title screen updates // "ovlHeader+0x139C"

// data
extern unsigned char levelIndexToHomeworldLevelId[40]; // 800671A0

// sdata
extern int loadStage; // 8006C518
extern int levelIndex; // 8006C58C
extern int D_8006C598;
extern Moby* D_8006C5F8; // dunno what this is but it's a Moby, probably bullet time related
extern int deltaTime; // 8006C648
extern short D_8006C67C;
extern int D_8006C718;
extern int D_8006C7C8;

// bss
extern Game game; // 8006E344 - game.state
extern PauseData pauseData; // 8006fbc4

////////////////////////////////////////////////////////////////////////////////////

/* Retail source: USA Rev 0 PSX.EXE 0x80050B90..0x80050F18 (226 instructions).
 * Raw SHA-256 13c06150...d8a7; Rev 1 0x80050BB4 corroborates behavior.
 * Units: six byte lanes, 18-byte level records, mask bits, byte thresholds, and
 * an integer timer advanced by 10 and capped at 30. Cadence: one call evaluates
 * the base mask and up to six lanes. Confidence: confirmed retail exact by the
 * PSX.EXE SHA-256 e5406997...e39f and all 62 manifest hashes.
 * Falsifiable vectors: override nonzero; timer -20/-19/10/11; entry remainder
 * 1..5; packed modes 0x10/0x20/0x30; mask bits; threshold edges; fresh mode 3. */
extern int D_8006C658;
extern int D_8006C7C4;
extern int D_8006C7A8;
extern int D_8006C564;
extern int D_8006C5BC;
extern int D_8006C58C;
extern int D_8006C5C8;
extern int D_8006C504;
extern unsigned char D_8006C7B4;
extern unsigned char D_80066BDC[];
extern unsigned char D_80066BDD[];
extern unsigned char D_80066BDE[];
extern unsigned char D_80070300[];
extern unsigned char D_800715BC[];
extern unsigned char D_800716AC[];
void func_80050B90(void) {
    register int lane __asm__("$7");
    register int laneOffset __asm__("$9");
    register int entryId __asm__("$4");
    register int entryRemainder __asm__("$8");
    register int level __asm__("$5");
    int level2;
    int recordOffset;
    register int packed __asm__("$5");
    register int packedMode __asm__("$3");
    register int remainderProduct __asm__("$3");
    register int firstPacked __asm__("$2");
    register int firstOffset __asm__("$2");
    register int divisionV0 __asm__("$2");
    register int divisionV1 __asm__("$3");
    register int divisionHi __asm__("$24");
    int mode;
    register int threshold __asm__("$3");
    register int two __asm__("$11");
    register int one __asm__("$12");
    register int three __asm__("$10");
    register int five __asm__("$13");
    register unsigned char* thresholdBase __asm__("$14");
    register unsigned char* stateBase __asm__("$15");

    if (D_8006C658 != 0) {
        D_8006C7C4 = 1;
        return;
    }
    if (D_8006C7A8 < -19) {
        D_8006C564 = 2;
    } else if (D_8006C7A8 < 11) {
        D_8006C564 = 1;
    } else {
        D_8006C564 = 0;
    }
    lane = 0;
    two = 2;
    thresholdBase = D_800716AC;
    one = 1;
    three = 3;
    five = 5;
    stateBase = D_800715BC;
    D_8006C7C4 = D_8006C564;
    laneOffset = 0;
loop:
    __asm__ volatile (
        "lui %1,0x6666\n"
        "lui %0,%%hi(D_8006C5BC)\n"
        "lw %0,%%lo(D_8006C5BC)(%0)\n"
        "ori %1,%1,0x6667\n"
        "mult %0,%1\n"
        "lui %2,%%hi(D_8006C58C)\n"
        "lw %2,%%lo(D_8006C58C)(%2)\n"
        "sra %1,%0,31\n"
        "mfhi %4\n"
        "sra %3,%4,2\n"
        "subu %5,%3,%1"
        : "=r"(entryId), "=r"(divisionV0), "=r"(level),
          "=r"(divisionV1), "=r"(divisionHi), "=r"(entryRemainder));
    remainderProduct = entryRemainder * 10;
    firstOffset = level * 18;
    __asm__ volatile ("addu %0,%1,%2" : "=r"(firstOffset) : "r"(laneOffset), "0"(firstOffset));
    firstPacked = D_80066BDC[firstOffset];
    entryRemainder = entryId - remainderProduct;
    packedMode = firstPacked & 0xF0;
    if (lane == 0 && (unsigned)(entryRemainder - 1) < 4) {
        if ((D_8006C7B4 & 1) != 0) goto next_lane;
        if ((D_80070300[level] & 1) != 0) goto next_lane;
    }
    if (packedMode == 0x30) goto next_lane;
    level2 = D_8006C58C;
    recordOffset = laneOffset + level2 * 18;
    packed = D_80066BDC[recordOffset];
    if ((packed & 0xF) != D_8006C5C8) goto next_lane;
    if (((D_8006C7B4 >> lane) & 1) != 0) goto next_lane;
    D_8006C504 = two;
    packedMode = packed & 0xF0;
    if (packedMode == 0x10) goto mode_10;
    if (packedMode == 0x20) goto mode_20;
    goto mode_done;
mode_10:
    threshold = (thresholdBase + level2 * 6)[lane];
    if (threshold < D_80066BDD[recordOffset]) goto set_one;
    if (!(D_80066BDE[recordOffset] < threshold)) goto set_two;
    goto set_three;
mode_20:
    threshold = (thresholdBase + level2 * 6)[lane];
    if (!(threshold < D_80066BDD[recordOffset])) goto check_high;
set_one:
    D_8006C504 = one;
    goto mode_done;
check_high:
    if (D_80066BDE[recordOffset] < threshold) goto set_three;
set_two:
    D_8006C504 = two;
    goto mode_done;
set_three:
    D_8006C504 = three;
mode_done:
    if (D_8006C504 == two) {
        if (lane != 0 || entryRemainder == five) {
            if (D_8006C7C4 >= 2) D_8006C7C4 = one;
        }
    }
    mode = D_8006C504;
    if (mode == three) D_8006C7C4 = 0;
    {
        register int stateLevel __asm__("$2") = D_8006C58C;
        register unsigned char* state __asm__("$3");
        state = (unsigned char*)(stateLevel * 6);
        state += (int)stateBase;
        state += lane;
        if (*state == 0 && mode == three) {
            *state = (unsigned char)mode;
            D_8006C7A8 += 10;
            if (D_8006C7A8 >= 31) D_8006C7A8 = 30;
        }
    }
    if (entryRemainder != five) return;
next_lane:
    lane++;
    if (lane < 6) {
        laneOffset += 3;
        goto loop;
    }
}
/* Retail source: USA Rev 0 PSX.EXE 0x80050F18..0x800512E4 (243 instructions),
 * raw SHA-256 B24CB11342B67AD4858B7ADB7F6EBA60D6DC7C9015395E85C285C30345C1152F.
 * USA Rev 1 0x80050F3C and docs/yotd-re/manifests/dialogue-manager-runtime.json
 * corroborate the dialogue-runtime reset. Inputs are controller-mask bits and
 * frame ticks; the clock uses /900 steps, level records are 18 bytes with six
 * byte lanes, and the fade advances by 16 through 256. Called once per gameplay
 * update; sector state refreshes every 64 calls and lanes saturate at 255 only
 * when a /900 boundary changes. Confidence: confirmed by the exact linked EXE
 * and all 62 manifest hashes. Falsifiable vectors: pause bits 0x100/0x800 with
 * each gate set, clocks at 599/600 and 899/900, packed mode/nibble mismatches,
 * lane values 254/255, the -1 override sentinel, and fade values 0/240/256. */
extern int D_8006E53C, D_8006C74C, D_8006C64C, D_8006C598;
extern int D_8006E344, D_80070148, D_8006C640;
extern unsigned char D_8006E508, D_8006E534;
extern int D_8006C5F4, D_8006C584, D_8006C5D0, D_8006C648;
extern int D_8006C404, D_8006C7E4, D_8006C734;
extern int* D_8006C55C;
extern char D_80070328;
extern char g_CheatFlags;
void func_8005663C(void);
void func_80055294(int);
void func_800584BC(int, int);
void func_80050F18(void) {
    int priorStep;
    int currentStep;

    if ((D_8006E53C & 0x100) != 0 &&
        D_8006C74C == 0 && D_8006C64C == 0 && D_8006C598 == 0 &&
        *(int*)(&D_80070328 + 0x280) >= 0 && D_8006E344 == 0) {
        D_80070148 = 3;
        func_8005663C();
    }
    D_8006C640++;
    if ((D_8006E53C & 0x800) != 0 || D_8006E508 < 2) {
        if (D_8006C74C == 0 && D_8006C64C == 0 && D_8006C598 == 0 &&
            *(int*)(&D_80070328 + 0x280) >= 0 && D_8006E344 == 0) {
            func_8005663C();
        }
    }
    func_80055294(0x7B);
    priorStep = D_8006C5F4 / 900;
    if (D_8006E534 != 0) {
        D_8006C584 += D_8006C648;
    } else {
        D_8006C584 = 0;
    }
    if (D_8006C584 < 600) {
        D_8006C5D0 += D_8006C648;
        D_8006C5F4 += D_8006C648;
    }
    currentStep = D_8006C5F4 / 900;
    if (currentStep != priorStep) {
        register int lane __asm__("$6") = 0;
        register int packedMode __asm__("$9") = 0x10;
        register unsigned char* thresholdBase __asm__("$8") = D_800716AC;
        register int laneOffset __asm__("$7") = 0;
        do {
            int level = D_8006C58C;
            register int recordOffset __asm__("$2") = level * 18;
            register int packed __asm__("$4");
            register int packedLow __asm__("$2");
            register unsigned char* value __asm__("$4");
            __asm__ volatile ("addu %0,%1,%2" : "=r"(recordOffset) : "r"(laneOffset), "0"(recordOffset));
            __asm__ volatile (
                ".set noreorder\n"
                ".set noat\n"
                "lui $1,%%hi(D_80066BDC)\n"
                "addu $1,$1,%1\n"
                "lbu %0,%%lo(D_80066BDC)($1)\n"
                "nop\n"
                ".set at"
                : "=r"(packed) : "r"(recordOffset) : "$1");
            packedLow = packed & 0xF0;
            if (packedLow != packedMode) goto lane_done;
            packedLow = packed & 0xF;
            if (packedLow != D_8006C5C8) goto lane_done;
            recordOffset = level * 6;
            __asm__ volatile ("addu %0,%1,%2" : "=r"(recordOffset) : "0"(recordOffset), "r"(thresholdBase));
            value = (unsigned char*)recordOffset + lane;
            if (*value < 0xFF) (*value)++;
lane_done:
            lane++;
            laneOffset += 3;
        } while (lane < 6);
    }
    if ((D_8006C640 & 0x3F) == 0) func_80050B90();
    if (D_8006C404 != -1) D_8006C7C4 = D_8006C404;
    if (D_8006C658 == 1) {
        int target = *D_8006C55C - 18;
        if (D_8006C640 >= target) {
            if (D_8006C598 == 0) D_8006C598 = 0x10;
            target = *D_8006C55C - 18;
            if (D_8006C640 >= target && D_8006C598 != 0) {
                D_8006C598 += 0x10;
                if (D_8006C598 >= 0x100) D_8006C7E4 = 1;
            }
        }
        if (D_8006C7E4 != 0) {
            func_800584BC(5, 0);
            (&g_CheatFlags)[3] = (char)D_8006C734;
        }
    }
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

/* Retail source: USA Rev 0 PSX.EXE 0x800512E4..0x800518F8
 * (389 instructions / 1556 bytes), raw .text SHA-256
 * 75425f429fd047a4e3dbe9bcce5892ca72025b971b44cdb3e847a9af03f83720.
 * One invocation initializes the selected dialogue session, parses its byte
 * command stream, and rebuilds line pointers, signed 16-bit byte offsets,
 * marker counts, and formatted marker text. Control bytes are 0x20, 0x26,
 * 0x40, 0x5C, 0x5E, and 0xFF; accumulated widths use integer units with a
 * 435 boundary. Confidence: confirmed retail exact over all 561 instruction
 * and relocation comparison records. Falsifiable vectors: empty and 0xFF
 * terminated streams, each control byte, 434/435 width crossings, consecutive
 * 0x5E runs, nonzero break counts, and each dialogue lookup outcome. */
extern int D_8006C72C, D_8006C778, D_8006C790;
extern int D_8006C78C, D_8006C6A4, D_8006C51C, D_8006C520;
extern int D_8006C6D8, D_8006C620, D_8006C6FC, D_8006C7BC;
extern int D_8006C794, D_8006C608, D_8006C7D0, D_8006C624;
extern int D_8006C798, D_8006C5C4, D_8006C750;
extern int D_8006C76C, D_8006C7B0, D_8006C594;
extern int D_8006C674, D_8006C6DC, D_8006C6E8;
extern unsigned char D_8006C680, D_8006C5AC, D_8006C6E4, D_8006C7A4;
extern unsigned char D_8006C53C, D_800666F1[];
extern short D_8006C544, D_8006C57C, D_8006C6F0;
extern short D_8006C6F4, D_8006C6F6, D_80071938[], D_80071942;
extern unsigned char D_8006C6F2, D_8006C6F3;
extern Moby *D_8006C5A8, *D_8006C69C;
extern int D_8006C684[], D_8006C59C[];
extern unsigned char *D_8006C68C[], *D_800713A8;
extern unsigned char *D_80071390[];
extern char D_8006C4E8[];
int func_80027934(int);
int func_80037324(Moby *);
void func_800512E4(Moby *arg0, s32 arg1, s32 arg2) {
    u8 sp10[24];
    register SpeechProps *temp_s1 asm("$17");
    register int one asm("$18") = 1;
    register int initialState asm("$3");
    register unsigned int workV0 asm("$2");
    register int space asm("$13");
    register u8 **breakBase asm("$9");
    register u8 **breakPrev asm("$15");
    register u8 **lineBase asm("$12");
    register s16 *offsetBase asm("$11");
    register s32 *countBase asm("$14");
    register int loopOne asm("$10");
    register s16 temp_a1 asm("$5");
    s16 temp_v0;
    s16 temp_v1_2;
    register s32 var_v0_3 asm("$2");
    s32 *temp_a0_3;
    s32 *var_s1;
    register s32 temp_a0_4 asm("$4");
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    register s32 temp_v1_3 asm("$3");
    s32 var_a0;
    register s32 var_a1 asm("$5");
    register s32 var_a3 asm("$7");
    u8 **temp_v0_3;
    u8 **var_s2;
    register u8 *temp_a0 asm("$4");
    u8 *temp_a0_2;
    register u8 *temp_s0 asm("$16");
    u8 *temp_v1_4;
    register u8 *var_a2 asm("$6");
    register u8 *var_t0 asm("$8");
    u8 *var_v0_2;
    void *temp_v0_2;

    temp_s1 = arg0->mobyTag;
    D_8006C72C = arg1;
    D_8006C778 = arg2;
    temp_s1->talkable = 0;
    initialState = D_8006E344;
    if (initialState == 1) {
        goto block_2;
    }
    D_8006C790 = 0;
    goto block_3;
block_2:
    __asm__ volatile ("" : "=r"(initialState) : "0"(initialState));
        D_8006C790 = initialState;
block_3:
    __asm__ volatile ("" : : : "memory");
    D_8006C680 = 1;
    D_8006E344 = one;
    D_8006C78C = 0;
    D_8006C5A8 = arg0;
    D_8006C6A4 = 0;
    D_8006C51C = 0;
    D_8006C520 = 0;
    D_8006C6D8 = 0;
    D_8006C5AC = 0;
    D_8006C620 = 0;
    D_8006C6FC = 0;
    D_8006C7BC = 0;
    D_8006C794 = 0;
    D_8006C544 = 0;
    D_8006C6E4 = 0;
    D_8006C57C = 0;
    D_8006C7A4 = 0;
    D_8006C53C = 0;
    D_8006C608 = 0;
    D_8006C7D0 = 0;
    D_8006C624 = -1;
    D_8006C798 = 0;
    D_8006C5C4 = 0;
    D_8006C750 = 0;
    D_8006C69C = 0;
    temp_v0 = func_80027934(3);
    D_8006C6F0 = temp_v0;
    temp_v0_2 = ((s32) (temp_v0 << 0x10) >> 0xD) + (int)D_8006C738;
    initialState = *((u8 *)temp_v0_2 + 4);
    D_8006C6F2 = initialState;
    __asm__ volatile ("" : : : "memory");
    initialState = *((u8 *)temp_v0_2 + 2);
    D_8006C6F4 = 0x150;
    D_8006C6F6 = 0xBE;
    D_8006C6F3 = initialState;
    func_80037324(arg0);
    workV0 = temp_s1->nextMsg;
    __asm__ volatile ("" : : : "memory");
    initialState = temp_s1->nextMsg;
    workV0 <<= 2;
    temp_s1->prevMsg = initialState;
    initialState = D_8006C76C;
    workV0 += (unsigned int)temp_s1;
    initialState <<= 2;
    workV0 += initialState;
    initialState = D_8006C7B0;
    temp_s0 = *(u8 **)(workV0 + 0x10);
    var_a1 = 0;
    if (initialState == 0) {
        goto block_6;
    }
    var_a1 = 0;
    workV0 = FindMobyDialogue(temp_s1);
    var_a1 = 0;
    if (workV0 == 0) {
        goto block_6;
    }
    D_8006C794 = one;
block_6:
    var_a3 = 0;
    temp_s0 = temp_s0 + *temp_s0;
    var_a2 = temp_s0;
    initialState = (int)&D_800713A8;
    __asm__ volatile ("" : "=r"(initialState) : "0"(initialState));
    *(u8 **)initialState = temp_s0;
    var_t0 = temp_s0;
    if (*temp_s0 == 0) {
        goto block_33;
    }
    space = 0x20;
    __asm__ volatile ("" : "=r"(space) : "0"(space));
    breakBase = D_80071390;
    __asm__ volatile ("" : "=r"(breakBase) : "0"(breakBase));
    breakPrev = breakBase - 1;
    lineBase = (u8 **)initialState;
    offsetBase = D_80071938;
    countBase = D_8006C684;
    loopOne = 1;
loop_8:
    initialState = *var_a2;
    if (initialState == 0xFF) {
        goto block_33;
    }
    if (initialState != space) {
        goto block_11;
    }
    var_a1 += 0xB;
    var_a3 = 0;
    var_t0 = var_a2 + 1;
    goto block_32;
block_11:
    if (initialState != 0x40) {
        goto block_13;
    }
    var_a2 += 1;
    goto block_32;
block_13:
    if (initialState == 0x26) {
        goto block_16;
    }
    workV0 = 0x5C;
    if (initialState == workV0) {
        workV0 = 0x5E;
        goto block_18;
    }
    workV0 = 0x5E;
    goto block_21;
block_16:
    workV0 = (u16)D_8006C544;
    __asm__ volatile ("" : "=r"(var_a2) : "0"(var_a2), "r"(workV0));
    temp_a0 = var_a2 + 1;
    temp_a1 = workV0 + 1;
    workV0 <<= 0x10;
    workV0 = (s32)workV0 >> 0xE;
    temp_v0_3 = (u8 **)(workV0 + (unsigned int)breakBase);
    D_8006C544 = temp_a1;
    *temp_v0_3 = temp_a0;
    var_a3 = 0;
    if (var_a2[1] != 0x5B) {
        goto block_20;
    }
    workV0 = (u16)temp_a1;
    workV0 <<= 0x10;
    workV0 = (s32)workV0 >> 0xE;
    workV0 += (unsigned int)breakPrev;
    D_8006C53C = loopOne;
    *(u8 **)workV0 = temp_a0;
    goto block_20;block_18:
    __asm__ volatile ("" : "=r"(workV0) : "0"(workV0));
    var_a3 = 0;
    if (var_a2[1] != space) {
        goto block_20;
    }
    var_a2 += 1;
block_20:
    var_a1 = 0;
    temp_a0_2 = var_a2 + 1;
    temp_v0_4 = D_8006C6A4 + 1;
    D_8006C6A4 = temp_v0_4;
    lineBase[temp_v0_4] = temp_a0_2;
    offsetBase[temp_v0_4] = temp_a0_2 - temp_s0;
    goto block_27;
block_21:
    if (initialState != workV0) {
        goto block_26;
    }
    var_t0 = var_a2;
    workV0 = D_8006C620;
    __asm__ volatile ("" : "=r"(var_a1) : "0"(var_a1), "r"(workV0));
    var_a1 += 0xC;
    workV0 <<= 2;
    *(u8 **)((u8 *)D_8006C68C + workV0) = var_a2;
    __asm__ volatile ("" : "=r"(var_a2) : "0"(var_a2) : "memory");
    var_a2 += 1;
    temp_a0_3 = (s32 *)(workV0 + (unsigned int)countBase);
    *temp_a0_3 = loopOne;
    var_a3 = 0xC;
    if (*var_a2 != initialState) {
        goto block_25;
    }
    initialState = (s32)temp_a0_3;
    temp_a0 = (u8 *)0x5E;
loop_24:
    var_a1 += 0xC;
    workV0 = *(s32 *)initialState;
    var_a2 += 1;
    workV0 += 1;
    *(s32 *)initialState = workV0;
    workV0 = *var_a2;
    var_a3 += 0xC;
    if (workV0 == (s32)temp_a0) {
        goto loop_24;
    }
block_25:
    workV0 = D_8006C620;
    workV0 += 1;
    D_8006C620 = workV0;
    workV0 = var_a1 < 0x1B3;
    goto block_28;block_26:
    workV0 = initialState << 1;
    temp_v0_5 = D_800666F1[workV0] & 0xF;
    var_a1 += temp_v0_5;
    var_a3 += temp_v0_5;
block_27:
    workV0 = var_a1 < 0x1B3;
block_28:
    if (workV0 != 0) {
        goto block_32;
    }
    temp_v1_2 = D_8006C544;
    if (temp_v1_2 == 0) {
        goto block_31;
    }
    D_8006C544 = temp_v1_2 + 1;
    breakBase[temp_v1_2] = var_t0;
block_31:
    var_a1 = var_a3;
    temp_v0_6 = D_8006C6A4 + 1;
    D_8006C6A4 = temp_v0_6;
    lineBase[temp_v0_6] = var_t0;
    offsetBase[temp_v0_6] = var_t0 - temp_s0;
block_32:
    var_a2 += 1;
    if (*var_a2 != 0) {
        goto loop_8;
    }
block_33:
    workV0 = var_a2 - temp_s0;
    temp_a0_4 = D_8006C6A4;
    temp_v1_3 = D_8006C544;
    temp_a0_4 += 1;
    var_a1 = temp_a0_4 << 1;
    __asm__ volatile ("" : "=r"(temp_v1_3) : "0"(temp_v1_3), "r"(var_a1));
    temp_v1_3 = temp_a0_4 - temp_v1_3;
    *(s16 *)((u8 *)D_80071938 + var_a1) = workV0;
    workV0 = D_80071938[temp_v1_3];
    __asm__ volatile ("" : "=r"(workV0) : "0"(workV0) : "memory");
    var_a1 = D_8006C620;
    __asm__ volatile ("" : : : "memory");
    D_8006C6A4 = temp_a0_4;
    __asm__ volatile ("" : : : "memory");
    D_8006C6A4 = temp_v1_3;
    D_8006C520 = workV0;
    temp_s0 = (u8 *)0;
    if (var_a1 <= 0) {
        goto block_39;
    }
    var_s2 = D_8006C68C;
    var_s1 = D_8006C59C;
loop_35:
    sprintf(sp10, &D_8006C4E8, *var_s1);
    var_a0 = 0;
    __asm__ volatile ("" : "=r"(var_a0) : "0"(var_a0));
    var_a1 = (s32)sp10;
    if (sp10[0] == 0) {
        goto block_38;
    }
    var_a2 = (u8 *)var_s2;
    workV0 = var_a1 + var_a0;
loop_37:
    initialState = *(s32 *)var_a2;
    workV0 = *(u8 *)workV0;
    initialState += var_a0;
    var_a0 += 1;
    *(u8 *)initialState = workV0;
    workV0 = var_a1;
    __asm__ volatile ("" : "=r"(workV0) : "0"(workV0));
    workV0 += var_a0;
    workV0 = *(u8 *)workV0;
    if (workV0 != 0) {
        workV0 = var_a1 + var_a0;
        goto loop_37;
    }
block_38:
    var_s2 += 1;
    workV0 = D_8006C620;
    temp_s0 += 1;
    var_s1 += 1;
    if ((s32)temp_s0 < (s32)workV0) {
        goto loop_35;
    }
block_39:
    workV0 = D_8006C794;
    initialState = 5;
    D_8006C6E8 = initialState;
    if (workV0 != 0) {
        goto block_41;
    }
    workV0 = D_8006C6A4;
    workV0 = initialState < (s32)workV0;
    if (workV0 != 0) {
        goto block_42;
    }
block_41:
    workV0 = D_8006C520;
    goto block_43;
block_42:
    workV0 = (s32)D_80071942;
block_43:
    D_8006C6DC = workV0;
    workV0 = D_8006C7B0;
    if (workV0 == 0) {
        goto block_45;
    }
    D_8006C594 = (speechData[D_8006C76C][D_8006C674].len * 2) / 5;
block_45:
    return;
}


extern int D_8006E344;
extern int D_8006C74C;
extern char D_80070328;
extern int D_8006C620;
extern int D_8006C684[];
extern unsigned char* D_8006C68C[];
extern int D_8006C778;
extern int D_8006C72C;
extern Moby* D_8006C5A8;
extern int D_8006C770;
extern short D_8006C57C;
extern Moby* D_8006C69C;
extern int D_8006C5FC;
extern int D_8006C590;
extern void func_80035734(Moby*);
/* Retail source: asm/nonmatchings/update/func_800518F8.s,
 * 0x800518F8..0x80051A60; raw bytes and per-call state reset. */
void func_800518F8(void) {
    int i;
    int j;
    for (i = 0; i < D_8006C620; i++) {
        for (j = 0; j < D_8006C684[i]; j++) {
            D_8006C68C[i][j] = 0x5E;
        }
    }
    if (D_8006C778 != D_8006C72C) {
        Moby* moby = (Moby*)D_8006C5A8;
        if (moby->animationState.nextId != D_8006C72C) {
            D_8006C770 = 0;
            moby->animationProgress = 0xF2;
            ((Moby*)D_8006C5A8)->animationState.nextId = D_8006C72C;
            ((Moby*)D_8006C5A8)->animationState.nextFrame = 0;
            func_80035734((Moby*)D_8006C5A8);
        }
    }
    {
        int* current = (int*)D_8006C5A8;
        int tag;
        D_8006C57C = -1;
        D_8006E344 = 0;
        tag = *current;
        /* Preserve the retail load delay; this emits no instruction. */
        asm volatile ("" : : "r"(tag));
        D_8006C69C = 0;
        D_8006C5FC = 0;
        D_8006C590 = -1;
        D_8006C74C = 0;
        if (*((unsigned char*)tag + 5) == 2) {
            *(int*)(&D_80070328 + 0x20C) = 0x10000002;
        }
    }
}

/**
 * ???() - func_80051A60() - MATCHING
 * Ready to add
 * Differs in 1.1, so would be interesting to add
 * https://decomp.me/scratch/ziJbr
 */
/* Rev 0 source hypothesis: asm/nonmatchings/update/func_80051A60.s. */
extern int D_8006C790, D_8006C78C, D_8006C648, D_8006C5C4;
extern unsigned char D_8006C680;
void func_80047D00(Moby*);
void func_80055294(int);
extern short D_80065920[0x100], D_800658A0[0x100];
#define D_80070328 g_Spyro
typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} MobyTag_132;
extern CameraPosition D_80069094[]; // this too
extern CameraPosition D_800690F8[]; // this one actually DOES seem to be an array of CameraPositions! Not sure how big
extern CameraPosition D_8006915C[]; // this too
extern int D_8006C51C;
extern int D_8006C520;
extern unsigned char D_8006C53C;
extern short D_8006C544;
extern int D_8006C594;
extern unsigned char D_8006C5AC;
extern int D_8006C624;
extern SoundTable* D_8006C654; // may be better off as a char*, really
extern int D_8006C66C;
extern int D_8006C674;
extern int D_8006C6A4;
extern int D_8006C6D8;
extern int D_8006C6DC;
extern unsigned char D_8006C6E4;
extern int D_8006C6E8;
extern int D_8006C6FC;
extern int D_8006C794;
extern int D_8006C798;
extern unsigned char D_8006C7A4;
extern int D_8006C7BC;
extern short D_80071938[]; // not sure how long this is

static inline void SetAnimation2(Moby* m, int prog, int next) {
    D_8006C770 = 0;
    m->animationProgress = prog;
    m->animationState.nextId = next;
    m->animationState.nextFrame = 0;
    func_80035734(m);
}

#define SetAnimation(moby, prog, id) \
    D_8006C770 = 0;\
    (moby)->animationProgress = (prog);\
    (moby)->animationState.nextId = (id);\
    (moby)->animationState.nextFrame = 0;\
    func_80035734(moby);

void func_80051A60() {
    Vector3D sp10;
    char temp_v0_3;
    int temp_v0_6;
    int var_v0_5;
    int var_s0;
    int var_v1;
    char temp_s1;

    // I struggled to find a match that didn't have a goto, good luck
	if (D_8006C778 != D_8006C72C) {
		if (D_8006C674 == 0xFF) {
			if (D_8006C5A8->animationState.nextId != D_8006C778) {
				SetAnimation(D_8006C5A8, 0xF2, D_8006C778);
			}
		}
		else {
			if (D_8006C5A8->animationState.nextId != D_8006C778) {
				if ((streamingData.dat_8006e4b4 == 2) && (streamingData.dat_8006e48c == 6 || streamingData.dat_8006e48c == 7)) {
					SetAnimation(D_8006C5A8, 0xF2, D_8006C778);
					goto block_out;
				}
				if (D_8006C5A8->animationState.nextId != D_8006C778) {
					goto block_out;
				}
			}
			if ((streamingData.dat_8006e4b4 != 2) || !((streamingData.dat_8006e48c == 6 || streamingData.dat_8006e48c == 7))) {
				if (D_8006C5A8->animationState.nextId != D_8006C72C) {
					SetAnimation(D_8006C5A8, 0xF2, D_8006C72C);
				}
				if (D_8006C798 != 0) {
                    // 1.1 only:
                    // D_8006C798 = 0;
					D_8006C790 = 2;
					D_8006C78C = 0;
				}
			}
		}
	}
block_out:

    D_8006C74C = 1;
    if (D_8006C790 == 0) {
        D_8006C78C += D_8006C648;
        if ((D_8006C78C >= 0x3C) && (D_8006C78C >= 0x4C)) { // ???????
            D_8006C78C = 0;
            D_8006C790 = 1;
        }
    }
    else if (D_8006C790 == 1) {
        if (D_8006C7A4 != 0) {
            D_8006C78C += D_8006C648;
            if ((D_8006C53C == 0) && (pad.state.pressed & 0x5000)) {
                PlaySound(D_8006C654->pauseMove, 0, 0);
                D_8006C78C = 0;
                if (pad.state.pressed & 0x1000) {
                    D_8006C57C--;
                }
                else if (pad.state.pressed & 0x4000) {
                    D_8006C57C++;
                }
                D_8006C57C = (D_8006C57C + D_8006C6E4) % D_8006C6E4;
            }
            if ((pad.state.pressed & 0x840) || ((D_8006C53C != 0) && (pad.state.pressed & 0x810))) {
                if (D_8006C53C != 0) {
                    PlaySound(D_8006C654->pauseExit, 0, 0x80);
                    D_8006C790 = 2;
                    D_8006C78C = 0;
                }
                else {
                    func_80037768(D_8006C5A8);
                    if (D_8006C7A4 != 0) {
                        func_800512E4(D_8006C5A8, D_8006C72C, D_8006C778);
                        if (D_8006C544 == 0) {
                            D_8006C57C = -1;
                        }
                    } else {
                        PlaySound(D_8006C654->pauseExit, 0, 0x80);
                        D_8006C790 = 2;
                        D_8006C78C = 0;
                    }
                }
            }
        } else if ((D_8006C5AC != 0) && (pad.state.pressed & 0x850)) {
            // 1.1: seems to have this here
            // D_8006C798 = 0;
            if (D_8006C544 != 0) {
                D_8006C7A4 = 1;
            } else if (D_8006C624 != -1) {
                func_80037768(D_8006C5A8);
                func_800512E4(D_8006C5A8, D_8006C72C, D_8006C778);
            } else {
                PlaySound(D_8006C654->pauseExit, 0, 0x80);
                D_8006C790 = 2;
                D_8006C78C = 0;
            }
        } else if (D_8006C6D8 != 0) {
            if (pad.state.pressed & 0x840) { // TODO - where pad.state is mentioned, replace this with the buttons
                // 1.1: this if statement also requires ((D_8006C798 == 0) || ((streamingData.dat_8006e4b4 == 2) && (streamingData.dat_8006e48c == 6 || streamingData.dat_8006e48c == 7)))
                // Ghidra suggests this if statement goes above this if:
                /*
                if ((DAT_8006c878 != 0) && ((DAT_8006e594 != 2 || (1 < DAT_8006e56c - 6U)))) {
                    bVar1 = true;
                }
                */
                D_8006C6E8 += 3;
                if (D_8006C6E8 >= D_8006C6A4) {
                    D_8006C6DC = D_8006C520;
                } else {
                    D_8006C6DC = D_80071938[D_8006C6E8];
                }
                D_8006C6D8 = 0;
            }
        } else {
            if (D_8006C794 != 0) {
                D_8006C78C += 2;
                D_8006C51C = (D_8006C78C * D_8006C520) / D_8006C594;
                if (pad.state.pressed & 0x840) {
                    D_8006C794 = 0;
                    streamingData.dat_8006e498 = 1;
                    if (D_8006C6FC < 5) {
                        D_8006C6E8 = 5;
                    }
                    else if (D_8006C6FC < 8) {
                        D_8006C6E8 = 8;
                    }
                    else if (D_8006C6FC < 11) {
                        D_8006C6E8 = 11;
                    }
                    if (D_8006C6A4 <= D_8006C6E8) {
                        D_8006C6DC = D_8006C520;
                    } else {
                        D_8006C6DC = D_80071938[D_8006C6E8];
                    }
                }
            } else {
                D_8006C51C += 3;
                if (pad.state.pressed & 0x840) {
                    D_8006C51C = D_8006C6DC;
                }
            }
            if (D_8006C51C >= D_8006C520) {
                D_8006C51C = D_8006C520;
                D_8006C5AC = 1;
            } else if (D_8006C51C >= D_8006C6DC) {
                D_8006C51C = D_8006C6DC;
                D_8006C6D8 = 1;
            } else if (D_8006C7BC != 0) {
                if (D_8006C51C >= D_80071938[1 + D_8006C6FC]) {
                    D_8006C51C = D_80071938[1 + D_8006C6FC] - 1;
                }
            }
        }
    }
    else if (D_8006C790 == 2) {
        if (D_8006C78C == 0) {
            func_80037768(D_8006C5A8);
            if ((D_8006C5FC != 0) && (D_8006C5C4 == 0)) {
                SpawnMoby(272, D_8006C5A8);
            }
        }
        D_8006C78C += D_8006C648;
        if (D_8006C78C >= 0x18) {
            if (D_8006C5C4 != 0) {
                D_8006C790 = 3;
                D_8006C78C = 0;
                temp_s1 = D_8006C5A8->angle.yaw;
                if ((D_80070328.critterMode == CRITTER_BENTLEY) || (D_80070328.critterMode == CRITTER_BENTLEY_BOXING)) {
                    var_v1 = D_800690F8[D_8006C590].pos.azimuth;
                    var_v0_5 = ((temp_s1 * 0x10 + 0x800 + var_v1) & 0xFFF) >> 4;
                } else {
                    var_v1 = D_80069094[D_8006C590].pos.azimuth;
                    var_v0_5 = ((temp_s1 * 0x10 + 0x800 + var_v1) & 0xFFF) >> 4; // :(
                }
                if (D_8006C590 == 0) {
                    D_8006C590 = 3;
                    var_s0 = 0x600;
                } else {
                    D_8006C590 = 4;
                    var_s0 = 0xA00;
                }
                if (camera.cameraState == 0x12) {
                    camera.unk50 = 1;
                }
                temp_v0_3 = temp_s1 - (func_8003613C(temp_s1, var_v0_5) >> 1);
                sp10.x = (D_80065920[temp_v0_3] * 0x27) >> 7;
                sp10.y = (D_800658A0[temp_v0_3] * 0x27) >> 7;
                sp10.z = 0;
                sp10.z = (D_80070328.position.z - D_8006C5A8->position.z) - 0x40;
                func_8004F194(&camera.unk60, &D_8006C5A8->position, &sp10);
                camera.unk6c = (D_80070328.rotation.yaw + var_s0) & 0xFFF;
                if (D_80070328.critterMode == CRITTER_BENTLEY) {
                    func_800135A4(&camera.unk170, &D_800690F8[D_8006C590], 0);
                }
                else if (D_80070328.critterMode == CRITTER_BENTLEY_BOXING) {
                    D_8006C590 &= 1;
                    if (D_8006C590 == 0) {
                        var_s0 = 0xC00;
                    }
                    else {
                        var_s0 = 0x400;
                    }
                    camera.unk6c = (D_80070328.rotation.yaw + var_s0) & 0xFFF;
                    func_800135A4(&camera.unk170, &D_8006915C[D_8006C590], 0);
                }
                else {
                    func_800135A4(&camera.unk170, &D_80069094[D_8006C590], 0);
                }
                func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
                func_800138A0(&camera.unk7c.pos[0], &camera.unk7c.pos[0]);
                func_800135A4(&camera.unk7c.pos[2], &camera.unk7c.pos[0], 0);
            } else {
                if (D_8006C5FC != 0) {
                    D_8006C790 = 5;
                    D_8006C78C = 0;
                }
                else {
                    func_800518F8();
                }
            }
        }
    }
    else if (D_8006C790 == 3) {
        D_8006C78C++;
        if (D_8006C78C == 0x1E) {
            D_8006C69C = SpawnMoby(D_8006C5C4, D_8006C5A8);
            if (D_8006C69C != 0) {
                if (D_8006C5C4 == 0x84) {
                    MobyTag_132* tag = D_8006C69C->mobyTag;
                    tag->unk0 = D_8006C66C;
                    tag->unk6 = D_80070328.bodyRotation.yaw;
                    D_8006C69C->size = 0x7F;
                }
                func_8004F178(&D_8006C69C->position, &camera.unk60);
                D_8006C69C->position.z = D_8006C5A8->position.z;
                temp_v0_6 = func_80035D38(D_8006C69C);
                if (temp_v0_6 != 0) {
                    D_8006C69C->position.z = temp_v0_6;
                }
                D_8006C69C->state = 2;
                SpawnParticle(4, 0xC, (Vector3D* ) D_8006C69C, (Vector3D* )3);
            } else {
                D_8006C78C -= 1;
            }
        } else if ((D_8006C69C != 0) && (D_8006C69C->state & 0x80)) {
            func_800518F8();
        }
    }
    else {
        D_8006C78C++;
        if (D_8006C78C == 0x30) {
            func_800518F8();
        }
    }
    D_80070328.unk17a |= 0x10000002;
    if ((game.state == 1) && (D_8006C680 != 0)) {
        func_80047D00(D_8006C5A8);
    }
    if (D_8006C790 != 2) {
        func_80013ACC(D_8006C5A8, 0x12);
    }
    func_80055294(0x7B);
}



#undef D_80070328
/**
 * ???() - func_800527C4()
 * Does something with egg / dragon data, has placeholder struct and one register switch hasn't been fixed yet
 * https://decomp.me/scratch/i3rjG
 */
extern Moby* D_8006C5A8;
extern Moby* D_8006C69C;
extern int D_8006C590;
extern unsigned char D_8006C680;
extern unsigned char* D_8006C7A0;
extern int D_8006C790;
extern int D_8006C78C;
extern int D_8006C7D0;
extern int D_8006C5C4;
void func_800527C4(int arg0, int arg1) {
    game.state = 15;
    D_8006C680 = 1;
    D_8006C790 = 0;
    D_8006C78C = 0;
    D_8006C7D0 = 0;
    D_8006C5C4 = 0;
    D_8006C5A8 = arg0;
    D_8006C69C = arg0;
    {
    register unsigned int flag __asm__("$3") = D_8006C7A0[arg1 * 12 + 11];
    if (flag == 0) {
        __asm__ volatile ("" : "=r"(flag) : "0"(flag));
        D_8006C590 = 0;
    } else {
        D_8006C590 = 1;
    }
    }
}

extern short D_8006C57C;
extern Moby* D_8006C69C;
extern Moby* D_8006C5A8;
extern int D_8006C5FC;
extern int D_8006C590;
extern int D_8006E344;
extern int D_8006C74C;
void func_80052854(void) {
    D_8006C57C = -1;
    D_8006C69C = 0;
    D_8006C5A8 = 0;
    D_8006C5FC = 0;
    D_8006C590 = -1;
    D_8006E344 = 0;
    D_8006C74C = 0;
}

extern void func_80047D00(Moby*);
void func_80055294(int);
void func_8005289C(void) {
    Moby* current = (Moby*)D_8006C5A8;
    D_8006C74C = 1;
    func_80047D00(current);
    func_80013ACC((Moby*)D_8006C5A8, 0x12);
    func_80055294(0x7B);
    if (D_8006C69C != 0 &&
        (*((unsigned char*)D_8006C69C + 0x48) & 0x80) != 0) {
        func_80052854();
    }
}

extern Vector3D D_8006FA2C;
extern Vector3D D_800719BC;
extern unsigned char D_80071570[];
extern int D_8006C5C8, D_8006C75C, D_8006C5C0, D_8006C514;
extern int D_8006C6E0, D_8006C50C, D_8006C4F8, D_8006E49C;
extern int D_8006C5F4, D_8006C768;
/* Retail source: asm/nonmatchings/update/func_80052918.s,
 * 0x80052918..0x80052A84; raw Moby state and global reset fields. */
void func_80052918(int selected, Moby* moby) {
    register int current asm("$19") = selected;
    register Moby* actor asm("$17") = moby;
    register char* tag asm("$18") = (char*)actor->mobyTag;
    register Vector3D* position asm("$16");
    int prior;
    int angleAgain;
    int first;
    int second;
    position = &actor->position;
    func_800282D8();
    func_8004F178(&D_8006FA2C, position);
    func_8004F178(&D_800719BC, position);
    D_8006C5C0 = actor->angle.yaw << 4;
    prior = D_8006C5C8;
    angleAgain = actor->angle.yaw;
    D_8006C75C = prior;
    first = *(int*)(tag + 0x44);
    second = *(int*)(tag + 0x48);
    D_8006C5C8 = current;
    D_8006C514 = 0;
    D_8006C6E0 = angleAgain << 4;
    D_8006C50C = first;
    if (second >= 0) {
        if (D_80071570[second] == 0) D_8006C4F8 = 1;
        else D_8006C4F8 = 2;
    } else if (*(int*)(&D_80070328 + 0x24C)) {
        D_8006C4F8 = 2;
    } else {
        D_8006C4F8 = 0;
    }
    func_8003BEDC();
    D_8006E49C = 1;
    D_8006E344 = 13;
    D_8006C5F4 = 0;
    D_8006C768 = 0;
    *(int*)(&D_80070328 + 0x170) = 0;
    *(int*)(&D_80070328 + 0x178) = 0;
    *(int*)(&D_80070328 + 0x140) = 0;
    *(int*)(&D_80070328 + 0x254) = 0;
}

INCLUDE_ASM("asm/nonmatchings/update", func_80052A84);

INCLUDE_RODATA("asm/nonmatchings/update", D_80010C9C);

/* Retail source: USA Rev 0 PSX.EXE 0x80053374..0x80053944
 * (372 instructions; raw bytes SHA-256 13c06150...d8a7).
 * This is the loading transition state machine: states 0..9 advance once per
 * call; pointer relocation uses byte addresses and a word-aligned delta;
 * camera angles are 12-bit values and fades step by 0x10.
 * Confidence: confirmed retail exact against PSX.EXE SHA-256
 * e5406997...e39f and all 62 normal manifest hashes.
 * Falsifiable vectors: states 0..9; level 0x13 and >=0x3E; relocation bounds
 * at D_800722D8/D_800722E0; angle deltas -0x801/-0x800/-0x100/0xFF/0x100;
 * fade values 0/0x10/0xFE/0xFF; both D_8006C658 branches. */
extern volatile int currentLevel __asm__("D_80070328+0x48");
extern unsigned char D_80065878;
extern unsigned char * volatile *D_8006C558;
extern int D_8006E074;
extern int D_8006E12C;
extern int D_8006E130;
extern signed char D_8006E138;
extern signed char D_8006E139;
extern int D_8006E344;
extern unsigned char *D_800722D0;
extern unsigned int D_800722D8;
extern unsigned int D_800722E0;

#define UPDATE_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char *)(expr) + (offset)))

void func_80053374(void) {
    unsigned char *temp_s1;
    int temp_s0;
    int temp_v0;
    int temp_v0_2;
    int temp_v1_4;
    int temp_angle;
    int var_v0;
    int var_v1;
    int var_v1_2;
    unsigned char *temp_s0_2;
    unsigned int temp_v1;
    unsigned int temp_v1_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_v1_3;

    switch (D_8006C514) {
    case 0:
        var_v1 = D_8006C5C8;
        if (var_v1 == 0) {
            var_v1 = D_8006C75C;
        }
        temp_s0 = UPDATE_FIELD(&D_80070328, int *, 0x244);
        if (D_8006C50C != 0) {
            func_8004BEF8(7);
        } else if (((D_8006C5BC == 0xE) && (var_v1 == 3)) || ((D_8006C5BC == 0x2C) && (var_v1 == 2))) {
            func_8004BEF8(0x28);
        } else if (currentLevel != 0x13) {
            func_8004BEF8(3);
            UPDATE_FIELD(&D_80070328, int *, 0xB8) = 0;
        }
        func_80016764(0x23);
        UPDATE_FIELD(&D_80070328, int *, 0x1BC) = 0;
        UPDATE_FIELD(&D_80070328, int *, 0x1C4) = 0;
        UPDATE_FIELD(&D_80070328, int *, 0x1CC) = 0;
        UPDATE_FIELD(&D_80070328, int *, 0x1D0) = 0;
        if (temp_s0 != 0) {
            UPDATE_FIELD(&D_80070328, int *, 0x288) = 1;
        }
        D_8006C514 = 1;
        break;
    case 1:
        temp_v0 = D_8006C598 + 0x10;
        D_8006C598 = temp_v0;
        if (temp_v0 >= 0xFF) {
            D_8006C598 = 0xFF;
            D_8006C514 = 2;
        }
        break;
    case 2: {
        register int temp_a2 asm("$6");
        register int raw_delta asm("$3");
        register unsigned char * volatile *table_base asm("$5");
        temp_s1 = D_800722D0;
        D_8006E12C = 0;
        D_8006E130 = 0;
        D_8006E138 = 1;
        D_8006E139 = 1;
        func_8001FB10(0x10000);
        if (UPDATE_FIELD(&D_80070328, int *, 0x244) != 0) {
            UPDATE_FIELD(&D_80070328, int *, 0x244) = 0;
            if (currentLevel >= 0x3E) {
                func_8004BEF8(0);
            }
        }
        temp_s0_2 = D_8006C558[currentLevel];
        if ((unsigned int) temp_s0_2 < (unsigned int) D_800722E0) {
            func_8004E7D4(temp_s1, (int *) temp_s0_2, UPDATE_FIELD(temp_s0_2, int *, -4));
            table_base = D_8006C558;
            table_base[currentLevel] = temp_s1;
            raw_delta = (int) (temp_s1 - temp_s0_2);
            temp_a0 = table_base[currentLevel];
            temp_a2 = (raw_delta >> 2) * 4;
            UPDATE_FIELD(temp_a0, int *, 4) = (int) (UPDATE_FIELD(temp_a0, int *, 4) + temp_a2);
            temp_a0_2 = table_base[currentLevel];
            temp_v1 = UPDATE_FIELD(temp_a0_2, unsigned int *, 8);
            if (temp_v1 < (unsigned int) D_800722D8) {
                UPDATE_FIELD(temp_a0_2, unsigned int *, 8) = (unsigned int) (temp_v1 + temp_a2);
            }
            temp_a0_3 = D_8006C558[currentLevel];
            temp_v1_2 = UPDATE_FIELD(temp_a0_3, unsigned int *, 0xC);
            if (temp_v1_2 < (unsigned int) D_800722D8) {
                UPDATE_FIELD(temp_a0_3, unsigned int *, 0xC) = (unsigned int) (temp_v1_2 + temp_a2);
            }
            temp_v1_3 = D_8006C558[currentLevel];
            UPDATE_FIELD(temp_v1_3, int *, 0x10) = (int) (UPDATE_FIELD(temp_v1_3, int *, 0x10) + temp_a2);
        }
        D_8006C514 = 3;
        break;
    }
    case 3:
    case 4:
    case 5:
    case 6:
        func_80052A84();
        break;
    case 7:
        temp_angle = UPDATE_FIELD(&D_80070328, int *, 0x64) + 0x800;
        var_v1_2 = (D_8006E074 - temp_angle) & 0xFFF;
        if (var_v1_2 >= 0x801) {
            var_v1_2 -= 0x1000;
        }
        {
            register int magnitude asm("$2") = var_v1_2;
            if (var_v1_2 < 0) {
                magnitude = -magnitude;
            }
            var_v0 = magnitude;
        }
        if (var_v0 < 0x100) {
            D_8006C514 = 8;
            if (D_8006C658 != 0) {
                func_8001FB10((*(&D_80065878 + D_8006C58C) << 0xA) - 0x1000);
            } else {
                func_8001FB10(*(&D_80065878 + D_8006C58C) << 0xA);
            }
        }
        break;
    case 8:
        UPDATE_FIELD(&D_80070328, int *, 0x20C) = 0x10000002;
        func_80055294(0x7B);
        temp_v1_4 = D_8006C598 - 0x10;
        D_8006C640 += 1;
        D_8006C598 = temp_v1_4;
        if (temp_v1_4 <= 0) {
            D_8006C598 = 0;
            D_8006C514 = 9;
        }
        break;
    case 9:
        UPDATE_FIELD(&D_80070328, int *, 0x20C) = 0x10000002;
        func_80055294(0x7B);
        D_8006E344 = 0;
        D_8006C640 += 1;
        break;
    }
    if ((unsigned int) (D_8006C514 - 8) >= 2U) {
        UPDATE_FIELD(&D_80070328, int *, 0xA8) = 0;
        UPDATE_FIELD(&D_80070328, int *, 0x20C) = 0x10000002;
        func_800489CC();
        func_800473E4();
        func_80045D70();
        func_80044240();
        func_80048948();
        func_80047C7C();
        {
            register int angle asm("$3") = UPDATE_FIELD(&D_80070328, int *, 0x5C);
            register int step asm("$4");
            register int second_angle asm("$5");
            register int scratch asm("$2");
            UPDATE_FIELD(&D_80070328, int *, 0x2C) = 0;
            scratch = -angle;
            step = scratch & 0xFFF;
            scratch = step < 0x801;
            if (scratch == 0) {
                step -= 0x1000;
                scratch = step < -0x20;
            } else {
                scratch = step < -0x20;
            }
            if (scratch != 0) {
                step = -0x20;
                __asm__ volatile("" : "=r"(step) : "0"(step));
                scratch = step < 0x21;
            } else {
                scratch = step < 0x21;
            }
            if (scratch == 0) {
                step = 0x20;
            }
            second_angle = UPDATE_FIELD(&D_80070328, int *, 0x60);
            angle += step;
            UPDATE_FIELD(&D_80070328, int *, 0x5C) = angle;
            scratch = -second_angle;
            step = scratch & 0xFFF;
            scratch = step < 0x801;
            if (scratch == 0) {
                step -= 0x1000;
                scratch = step < -0x20;
            } else {
                scratch = step < -0x20;
            }
            if (scratch != 0) {
                step = -0x20;
                __asm__ volatile("" : "=r"(step) : "0"(step));
                scratch = step < 0x21;
            } else {
                scratch = step < 0x21;
            }
            if (scratch == 0) {
                step = 0x20;
            }
            UPDATE_FIELD(&D_80070328, signed char *, 0xC) = (signed char) (angle >> 4);
            temp_v0_2 = second_angle + step;
            UPDATE_FIELD(&D_80070328, int *, 0x60) = temp_v0_2;
            UPDATE_FIELD(&D_80070328, signed char *, 0xD) = (signed char) (temp_v0_2 >> 4);
            if ((UPDATE_FIELD(&g_CheatFlags, unsigned char *, 6) != 0) && (UPDATE_FIELD(&D_80070328, unsigned char *, 0x11) == 0)) {
                UPDATE_FIELD(&D_80070328, unsigned char *, 0x11) = 1U;
            }
            func_8001204C(step, second_angle);
        }
    }
}

#undef UPDATE_FIELD

/**
 * InitStateFadeIn() - func_80053944() - MATCHING
 * https://decomp.me/scratch/zZDVz
 */
void func_80053944() {
    pauseData.dat_8006fbc8 = 0;
    pauseData.frameCount = 0;
    pauseData.menuType = 0;
    pauseData.dat_8006fbd4 = 0;
    game.state = GAMESTATE_FADE_IN;
    func_8003BEDC();
    streamingData.musicEnabled = 1;
}

/**
 * ???() - func_8005399C() - MATCHING
 * Worth reviewing for the structs etc.
 * https://decomp.me/scratch/MKuo7
 */
void func_8005399C() {
    func_80053944(); // init state fade in
    pauseData.dat_8006fbc8 = 2;
    pauseData.frameCount = 1;
    D_8006C598 = 0xFF;
    D_8006C718 = 1;
    func_8004E790(&savedData, 0, 0x850);
    func_8004E790(&unsavedData, 0, 0x850);
}

/* Retail source: USA Rev 0 PSX.EXE 0x80053A10..0x80053F50
 * (336 instructions; raw bytes SHA-256
 * 5665be634f81a05124b0ebb364a20c0efbe104422680b9189af095ad89132eb3).
 * Called once per Update dispatch while GAMESTATE_FADE_IN is active. Its five
 * stages advance the screen fade by signed 0x10 steps clamped to 0..0xFF,
 * gate asynchronous CD loading with integer frame counters, restore player
 * positions in signed world units, and narrow Q4 rotation values to byte
 * angles with arithmetic shifts. Confidence: exact. Falsifiable by the full
 * 493 instruction/relocation comparison records and final executable/overlay
 * hashes. */
#define M2C_FIELD_53A10(p,t,o) (*(t *)((char *)(p) + (o)))
extern int D_8006FBC8, D_8006FBC4, D_8006FBD0;
extern int D_8006C598, D_8006E470, D_8006C5C8, D_8006C58C;
extern int D_8006FA38, D_8006FA3C, D_8006FA40, D_8006FA54;
extern int D_8006C5BC, D_8006D8D4;
extern char D_8006D088;
extern int D_8006C550, D_8006C704, D_8006C3F4;
extern int D_8006C74C, D_800725C8, D_80070148, D_8006E344, D_8006C640;
extern char D_800652B0[];
extern char D_800652B4[], D_800652B6[];
extern unsigned char D_80065734[];
extern char D_8006DBE0[], D_80072098[], D_8007209C[];
extern void *D_800722C8;
extern CameraPosition D_80068FF4, D_80069274, D_80069288, D_80068F90;
extern char D_80070328;
void func_80047190(void);
void *func_8002B810(void *);
int func_8001A358(void *, int);
void func_8004F178(Vector3D *, Vector3D *);
void func_8004BEF8(int);
void func_80052918(int, Moby *);
void func_8004F984(int, int, int);
void func_80055294(int);
void func_8005663C(void);
int CDLoadTime(void);
int CDLoadAsync(int, void *, int, int);
void func_80053A10(void) {
    register CameraPosition *var_a0 asm ("$4");
    CameraPosition *var_a0_2;
    int temp_a0;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v1;
    register int var_v0 asm ("$2");
    unsigned int var_a0_3;
    register void *temp_a1 asm ("$5");
    register int *stateTimer asm ("$16");

    switch (D_8006FBC8) {
    case 0:
        temp_v0 = D_8006C598 + 0x10;
        D_8006C598 = temp_v0;
        if (temp_v0 >= 0xFF) {
            {
                register int cap asm ("$4") = 0xFF;
                register int *fadeState asm ("$2") = &D_8006FBC8;
                int nextState = *fadeState + 1;
                D_8006C598 = cap;
                *fadeState = nextState;
            }
            return;
        }
    default:
        return;
    case 1:
        stateTimer = &D_8006FBC4;
        if (*stateTimer != 0) {
            *stateTimer += 1;
        }
        if (CDLoadTime() == 0) {
            if (*stateTimer == 0) {
                temp_v1 = (D_8006C5C8 * 0x10) + 0x18;
                CDLoadAsync(D_8006E470, D_800722C8, *(int *)(D_8007209C + temp_v1), *(int *)(D_80072098 + temp_v1) + *(int *)(D_8006DBE0 + (D_8006C58C * 0x10)));
                *stateTimer = 1;
                return;
            }
            {
                register int timerValue asm ("$3") = *stateTimer;
                var_v0 = D_8006FBD0;
                __asm__ volatile ("" : "=r"(var_v0) : "0"(var_v0));
                if (var_v0 != 0) {
                    var_v0 = timerValue < 0x50;
                } else {
                    var_v0 = timerValue < 6;
                    if (var_v0 == 0) goto advance_state;
                    var_v0 = timerValue < 0x50;
                }
                if (var_v0 != 0) return;
            }            goto advance_state;
        }
        break;
    case 2:
        func_80047190();
        func_8002B810(D_800722C8);
        goto advance_state;
    case 3:
        {
        register int *spawnState asm ("$5") = &D_8006FA38;
        if (*spawnState >= 0) {
            if (D_8006FA40 != 0) {
                func_8004F178((Vector3D *) &D_80070328, (Vector3D *) (spawnState + 4));
                func_8004F178((Vector3D *) ((char *)&D_80070328 + 0x124), (Vector3D *) &D_80070328);
                temp_v0_2 = D_8006FA54 * 0x10;
                {
                    register int currentLevel asm ("$3") = D_8006C5BC;
                M2C_FIELD_53A10(&D_80070328, int, 0x64) = temp_v0_2;
                M2C_FIELD_53A10(&D_80070328, unsigned char, 0xE) = (unsigned char) (temp_v0_2 >> 4);
                __asm__ volatile ("" : : : "memory");
                { register int expectedLevel asm ("$2") = 0x23;
                var_a0 = &D_80068FF4;
                __asm__ volatile ("" : "=r"(var_a0) : "0"(var_a0));
                if ((currentLevel == expectedLevel) && (D_8006FA3C == 3)) {
                    var_a0 = &D_80069288;
                }
                func_80012BA8(var_a0);
                }
                D_8006FA40 = 0;
                }
            }
            temp_v0_3 = func_8001A358(&D_80070328, 0x400);
            if (temp_v0_3 != 0) {
                M2C_FIELD_53A10(&D_80070328, int, 8) = temp_v0_3 + 0x164;
                func_8004BEF8(0);
            }
        } else {
            if ((D_8006C5BC == 0x2A) && (D_8006C5C8 == 1)) {
                var_a0_2 = &D_80069274;
                goto block_28;
            }
            if ((M2C_FIELD_53A10(&D_8006D088, int, 0) != 0) && (D_8006D8D4 != 0)) {
                var_a0_2 = &D_80068F90;
block_28:
                func_80012BA8(var_a0_2);
            }
        }
        }
        {
            register unsigned char *cheatPtr asm ("$5") = (unsigned char *)&g_CheatFlags + 0x16;
            if (*cheatPtr != 0) {
                register unsigned int actor asm ("$4") = D_8006C550;
                register unsigned int actorEnd asm ("$3") = D_8006C704;
                if (actor < actorEnd) {
                    register int keepScanning asm ("$8") = 1;
                    register int targetClass asm ("$7") = 0x3FE;
                    register unsigned int savedEnd asm ("$6");
                    stateTimer = (int *)cheatPtr;
                    __asm__ volatile ("" : "=r"(stateTimer) : "0"(stateTimer));
                    savedEnd = actorEnd;
                    __asm__ volatile ("" : "=r"(keepScanning) : "0"(keepScanning));
scan_actors:
                    if (keepScanning == 0) goto block_37;
                    if (M2C_FIELD_53A10(actor, short, 0x36) != targetClass) goto next_actor;
                    temp_a1 = M2C_FIELD_53A10(actor, void *, 0);
                    if (M2C_FIELD_53A10(temp_a1, int, 0x40) != 0) goto next_actor;
                    if (M2C_FIELD_53A10(temp_a1, int, 0x34) == *(unsigned char *)stateTimer) goto cheat_found;
next_actor:
                    actor += 0x58;
                    if (actor < savedEnd) goto scan_actors;
                }
            }
        }block_37:
        temp_v0_4 = D_80065734[D_8006C58C] * 8;
        temp_a0 = D_8006C3F4 + *(int *)(D_800652B0 + temp_v0_4);
        func_8004F984(temp_a0, temp_a0 + *(unsigned short *)(D_800652B4 + temp_v0_4), (int) *(unsigned short *)(D_800652B6 + temp_v0_4));
        M2C_FIELD_53A10(&D_80070328, int, 0x20C) = 0x10000002;
        func_80055294(0x7B);
        goto advance_state;
advance_state:
        { register int *fadeState asm ("$3") = &D_8006FBC8; *fadeState += 1; }
        return;
    case 4:
        temp_v0_5 = D_8006C598 - 0x10;
        D_8006C598 = temp_v0_5;
        if (temp_v0_5 <= 0) {
            D_8006C598 = 0;
            D_8006C74C = 0;
            if (D_800725C8 != 3) goto not_special_exit;
            D_80070148 = 2;
            func_8005663C();
            goto exit_selected;
cheat_found:
            {
                register int roll asm ("$2") = M2C_FIELD_53A10(&D_80070328, int, 0x5C);
                register int actorIndex asm ("$6") = M2C_FIELD_53A10(temp_a1, int, 0x30);
                register int yaw asm ("$3") = M2C_FIELD_53A10(&D_80070328, int, 0x64);
                M2C_FIELD_53A10(&D_80070328, signed char, 0xC) = (signed char) (roll >> 4);
                __asm__ volatile ("" : : : "memory");
                {
                    register int pitch asm ("$2") = M2C_FIELD_53A10(&D_80070328, int, 0x60);
                    M2C_FIELD_53A10(&D_80070328, unsigned char, 0xE) = (unsigned char) (yaw >> 4);
                    M2C_FIELD_53A10(&D_80070328, signed char, 0xD) = (signed char) (pitch >> 4);
                }
                {
                    register int selected asm ("$4") = M2C_FIELD_53A10(temp_a1, int, 0x34);
                    { register int actorOffset asm ("$5") = actorIndex * 0x58;
                    func_80052918(selected, (Moby *)(D_8006C550 + actorOffset)); }
                }
            }
            *(unsigned char *)stateTimer = 0;
            return;
not_special_exit:
            D_8006E344 = 0;
exit_selected:
            { register int *savedPoint asm ("$4") = &D_8006D088;
            if (*savedPoint == 0) {
                M2C_FIELD_53A10(&D_80070328, int, 8) -= 0x164;
                func_8003B634((Savepoint *) savedPoint, (Vector3D *)&D_80070328, (int) M2C_FIELD_53A10(&D_80070328, unsigned char, 0xE));
                M2C_FIELD_53A10(&D_80070328, int, 8) += 0x164;
            } }
        }
        M2C_FIELD_53A10(&D_80070328, int, 0x20C) = 0x10000002;
        func_80055294(0x7B);
        D_8006C640 += 1;
        break;
    }
}
#undef M2C_FIELD_53A10

/**
 * GoToLevel() - func_80053F50()
 * It's getting there, mostly register shit now
 * Actually pretty portal focused rather than going to levels in general
 * This is a function that is different in 1.1
 * https://decomp.me/scratch/0zqbG
 */
/* Rev 0 source hypothesis: asm/nonmatchings/update/func_80053F50.s. */
typedef struct {
    Vector3D polygonPoints[5]; // 00 0C 18 24 30
    unsigned int* skybox; // 3c
    char renderDistance; // 40
    char sidedness; // 41 // 0 is one-sided
    char levelId; // 42
    char animationState; // 43
} Portal;
typedef struct {
    int DAT_800722E8; // level ID (to load)?
    Vector3D DAT_800722EC;
    Vector3D DAT_800722F8;
    int DAT_80072304;
    Vector3D DAT_80072308;
    Vector3D DAT_80072314;
    short DAT_80072320;
    short DAT_80072322;
    int DAT_80072324;
    int DAT_80072328;
    int DAT_8007232C;
} Unknown;
extern unsigned char D_80066FCC[72];
extern unsigned char D_80070300[40];
extern ProgressFlags progressFlags;
extern Portal* D_8006C530;
extern Unknown D_800722E8;
extern int D_8006C508, D_8006C5BC, D_8006C73C;
int func_8004F2C8(int,int);
int func_8004F284(short,int);
void func_8004F178(Vector3D*,Vector3D*);
void func_8004F194(Vector3D*,Vector3D*,Vector3D*);
void func_8004F1C8(Vector3D*,Vector3D*,Vector3D*);
int func_8004EDE8(Vector3D*,int);
void func_80053F50(int arg0) {
    Vector3D sp10;
    int temp_a0;
    int homeworldNo;
    int temp_s0_4;
    register int temp_s3 __asm__("$19");
    int temp_s3a;
    unsigned int temp_v1;
    register int var_v0 __asm__("$2");
    Portal* temp_v0;
    int temp_s3b;

    if (arg0 >= 0) {
        temp_v0 = (Portal*)(arg0 * sizeof(Portal) + (int)D_8006C530);
        temp_s3 = func_8004E880(temp_v0->polygonPoints[4].x - temp_v0->polygonPoints[0].x,
                                temp_v0->polygonPoints[4].y - temp_v0->polygonPoints[0].y, 1);
        __asm__ volatile("" : : "r"(temp_s3) : "memory");
        temp_s3a = func_8004E880(spyro.position.x - D_8006C530[arg0].polygonPoints[2].x,
                                 spyro.position.y - D_8006C530[arg0].polygonPoints[2].y, 1);
        temp_s3b = func_8004F2C8(temp_s3, temp_s3a);

        var_v0 = ((temp_s3b < 0) ? temp_s3 - 0x400 : temp_s3 + 0x400);
        temp_s3 = var_v0 & 0xFFF;
        sp10.x = func_8004EA2C(temp_s3) >> 1;
        sp10.y = func_8004E9E4(temp_s3) >> 1;
        sp10.z = -1000;
        func_8004F194(&D_800722E8.DAT_800722EC, &D_8006C530[arg0].polygonPoints[2], &sp10);
        func_8004F178(&D_800722E8.DAT_800722F8, &sp10);
        sp10.x = -sp10.x >> 2;
        sp10.y = -sp10.y >> 2;
        func_8004F178(&D_800722E8.DAT_80072308, &camera.nextCameraPosCartesian);
        func_8004F194(&D_800722E8.DAT_80072314, &D_8006C530[arg0].polygonPoints[2], &sp10);
        D_800722E8.DAT_80072322 = temp_s3;
        D_800722E8.DAT_80072320 = camera.unk48;
        temp_s0_4 = func_8004E880(D_8006C530[arg0].polygonPoints[2].x - camera.nextCameraPosCartesian.x, D_8006C530[arg0].polygonPoints[2].y - camera.nextCameraPosCartesian.y, 1);
        func_8004F1C8(&sp10, &D_800722E8.DAT_80072308, &D_800722E8.DAT_80072314);

        D_800722E8.DAT_80072324 = (func_8004F284(temp_s3, temp_s0_4) * func_8004EDE8(&sp10, 0)) >> 0xB;
        if (D_800722E8.DAT_80072324 < 400) {
            D_800722E8.DAT_80072324 = 0;
        }

        D_800722E8.DAT_800722E8 = arg0;
        D_8006C7C8 = (!D_8006C508) ? levelIndexToHomeworldLevelId[levelIndex] : D_8006C530[arg0].levelId;
        pauseData.menuType = 0;
    } else {
        D_8006C7C8 = levelIndexToHomeworldLevelId[levelIndex];
        pauseData.menuType = 1;
    }
    homeworldNo = D_8006C7C8 / 10;

    if (D_8006C7C8 == (homeworldNo * 0xA)) {
        temp_v1 = D_8006C5BC % 10;
        if ((temp_v1 - 1 < 6) && (temp_v1 != 5)) {
            if ((D_8006C5BC < 60)
                && ((&progressFlags.lvl67_AMonsterToEndAllMonsters)[homeworldNo] == 0)) {

                temp_a0  = D_80070300[D_80066FCC[D_8006C7C8 + 1]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 2]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 3]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 4]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 6]] & 1;

                switch (D_8006C7C8) {
                case 10:
                    if (temp_a0 >= 2) {
                        progressFlags.lvl62_TheSecondWarning = 1;
                        func_800584BC(6, 62);
                        return;
                    }
                    break;
                case 20:
                    if (temp_a0 >= 2) {
                        progressFlags.lvl64_HuntersTussle = 1;
                        func_800584BC(6, 64);
                        return;
                    }
                    break;
                case 30:
                    if (temp_a0 >= 4) {
                        progressFlags.lvl66_AnApologyAndLunch = 1;
                        func_800584BC(6, 66);
                        return;
                    }
                    break;
                }
            }
        }
    }
    D_800722E8.DAT_8007232C = 0;
    pauseData.dat_8006fbc8 = 0;
    pauseData.frameCount = 0;
    loadStage = 0;
    game.state = GAMESTATE_LOADING_GLIDE;
    func_8003BEDC();
    streamingData.musicEnabled = 1;
    D_8006C73C = D_8006C5BC;
}





INCLUDE_ASM("asm/nonmatchings/update", func_80054450);

/**
 * InitGameOver() - func_80054AF8() - MATCHING
 * https://decomp.me/scratch/G5jiI
 */
void func_80054AF8() {
    game.state = GAMESTATE_GAME_OVER;
    pauseData.dat_8006fbc8 = 0;
    D_8006C598 = 0;
    D_8006C7C8 = levelIndexToHomeworldLevelId[levelIndex];
    loadStage = 0;
    func_8003BEDC();
    streamingData.musicEnabled = 1;
}

/* Retail source: asm/nonmatchings/update/func_80054B64.s,
 * 0x80054B64..0x80054CD8; one state update per call. */
extern int D_8006FBC8, D_8006FBC4, D_8006C518;
extern int D_8006C784, D_8006C5BC, D_8006C60C, D_8006C58C;
void func_8002CA50(void);
void func_8001FB10(int);
void func_title_80074DEC(int);
void func_loading_80076FEC(void);
void func_80054E5C(void);
void func_80054B64(void) {
    int state = D_8006FBC8;
    if (state >= 3) goto check_state_three;
    if (state > 0) goto loading;
    if (state == 0) goto state_zero;
    return;
check_state_three:
    if (state == 3) goto check_three;
    return;
state_zero:
    if (D_8006C518 < 2) func_8002CA50();
    D_8006C598 += 16;
    if (D_8006C598 < 256) return;
    func_8001EBAC();
    func_8001FB10(0x1C000);
    goto check_wait;
wait:
    func_8002CA50();
check_wait:
    if (D_8006C518 < 2) goto wait;
    if (D_8006C784 >= 0) {
        func_title_80074DEC(0);
        func_80054E5C();
        return;
    }
    D_8006FBC8 = 1;
    D_8006FBC4 = 0;
    D_8006C718 = 1;
    D_8006C5BC = D_8006C7C8;
    D_8006C60C = D_8006C58C;
    return;
loading:
    func_loading_80076FEC();
    return;
wait_three:
    func_8002CA50();
check_three:
    if (D_8006C518 >= 0) goto wait_three;
    func_8005399C();
}

/**
 * ???() - func_80054CD8() - MATCHING
 * Worth reviewing for the structs etc.
 * https://decomp.me/scratch/kCgmm
 */
extern char* D_80011254;
extern short D_8006C510;
extern short D_8006C540;
extern int D_8006C56C;
extern short D_8006C6A8;
extern int D_8006C6AC;
extern short D_8006C740;
extern short D_8006C744;
extern short D_8006C780;
extern int D_8006C7F0;
extern int D_8006DE88;
extern int D_8006DE8C;
extern int D_8006E470;
extern int D_8006E49C;
void func_80054CD8(void) {
    D_8006E344 = 0xA;
    D_8006C744 = 0;
    D_8006C740 = 0;
    D_8006C540 = 0;
    D_8006C510 = -1;
    D_8006C6AC = 0;
    D_8006C7F0 = 0;
    D_8006C780 = 0;
    D_8006C6A8 = 0;
    D_8006C56C = 0;
    CDLoadSync(D_8006E470, D_80011254, D_8006DE8C, D_8006DE88);
    func_8003BEDC();
    D_8006E49C = 1;
}

extern void func_credits_80074BA0(void);
extern void func_8002CA50(void);
void func_80054D84(void) {
    switch (D_8006C510) {
    case 0x63:
        {
        register int level __asm__("$5") = D_8006C67C;
        loadStage = 1;
        if (level > 0) {
            func_800584BC(0, level);
            D_8006C67C = -1;
        } else {
            func_800584BC(0, 0x28);
        }
        D_8006C780 = 0;
        D_8006C510 = (unsigned short)D_8006C510 + 1;
        }
        break;
    case 0x64:
        D_8006C780 = (unsigned short)D_8006C780 + deltaTime;
        func_8002CA50();
        break;
    default:
        func_credits_80074BA0();
        break;
    }
}

extern int D_8006C658;
extern int D_8006C7E4;
extern int D_8006C678;
extern int D_8006C64C;
extern int D_80065834;
extern char D_80070328;
extern char D_8006FBA8;
extern char D_8007179C;
extern char D_8006DFF8;
extern char D_8006D088;
extern char D_8006C7F8;
extern char g_CheatFlags;
extern void ActivateSparxPowers(void);
extern int func_8004F6A0(void);
extern void srand(int);
void func_80054E5C(void) {
    unsigned char cheat;
    D_8006E344 = 11;
    D_8006C658 = 0;
    D_8006C7E4 = 0;
    D_8006C678 = 0;
    D_8006C74C = 0;
    D_8006C64C = 0;
    func_8001FB10(0x1C000);
    func_8004E790(&D_80070328, 0, 0x2E8);
    func_8004E790(&D_8006FBA8, 0, 0x1C);
    func_8004E790(&D_8007179C, 0, 0x130);
    func_8004E790(&D_8006DFF8, 0, 0x1FC);
    *(int*)(&D_80070328 + 0x28C) = -1;
    *(int*)(&D_80070328 + 0x294) = -1;
    *(int*)(&D_80070328 + 0x280) = D_80065834;
    func_8004E790(&D_8006D088, 0, 0x850);
    func_8004E790(&D_8006C7F8, 0, 0x850);
    cheat = (&g_CheatFlags)[3];
    func_8004E790(&g_CheatFlags, 0, 0x18);
    (&g_CheatFlags)[3] = cheat;
    ActivateSparxPowers();
    srand(func_8004F6A0());
}

/**
 * ???() - func_80054F94() - MATCHING
 * Worth reviewing for the structs etc.
 * https://decomp.me/scratch/haRsG
 */
extern int D_8007232C;
extern int D_8006FBC8;
extern int D_8006FBC4;
extern int D_8006FBD0;
extern int D_8006C528;
extern int D_8006E49C;
extern int D_8006C73C;
extern int D_8006C5BC;
void func_80054F94(int arg0, Moby* arg1) {
    D_8007232C = 0;
    D_8006FBC8 = 0;
    D_8006FBC4 = 0;
    D_8006FBD0 = 1;
    loadStage = 0;
    D_8006E344 = 0xC;
    D_8006C7C8 = arg0;
    D_8006C528 = (int)arg1->mobyClass;
    func_8003BEDC();
    D_8006E49C = 1;
    D_8006C73C = D_8006C5BC;
}

/**
 * Loading-state updater - func_80055020() - MATCHING
 * Rev 0 target: asm/nonmatchings/update/func_80055020.s,
 * 0x80055020..0x80055294 (157 instruction words).
 * The 0x15000 buffer increment reads D_8006FC6C and writes D_8006FCE0.
 * https://decomp.me/scratch/bm0hn supplied the initial C candidate.
 */
extern int D_8006C508, D_8006C7DC, D_8006FC6C, D_8006FCE0;
extern char D_80070328, D_8006D088, D_8006C7F8;
extern Vector3D D_800722F8;
extern void func_80044240(void);
extern int func_80048444(Vector3D*);
extern void func_8004BEF8(int);
extern void func_loading_80078678(void);

void func_80055020(void) {
    int temp_v0;

    switch (pauseData.dat_8006fbc8) {
    case 0:
        if (((loadStage > 0) || (func_8002CA50(), (loadStage > 0))) && (CDLoadTime() == 0)) {
            func_8001FB10(0x1C000);
            D_8006C7DC = 0x15000;
            pauseData.dat_8006fbc8 = 1;
            pauseData.frameCount = 0;
            D_8006FCE0 = D_8006FC6C + 0x15000;
        }
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        func_loading_80078678();
        break;
    case 5:
        if (pauseData.frameCount == 0) {
            if (loadStage >= 0) {
                do {
                    func_8002CA50();
                } while (loadStage >= 0);
            }
            func_8004E790(&D_8006D088, 0, 0x850);
            func_8004E790(&D_8006C7F8, 0, 0x850);
            func_8005399C();
        }
        if (game.state == GAMESTATE_LOADING_GLIDE) {
            pauseData.frameCount++;
            if (pauseData.frameCount < 9) {
                D_8006C598 = (8 - pauseData.frameCount) << 5;
            }
            if (D_8006C508 != 0) {
                func_80044240();
                if (pauseData.frameCount >= 0xA) {
                    temp_v0 = func_80048444(&D_800722F8);
                    (&D_80070328)[0xC] = 0;
                    (&D_80070328)[0xD] = 0;
                    func_8001204C();
                    if (!temp_v0) {
                        func_8004BEF8(0);
                        game.state = GAMESTATE_FADE_IN;
                        pauseData.dat_8006fbc8 = 4;
                        pauseData.frameCount = 0;
                        pauseData.menuType = 0;
                        D_8006C598 = 0;
                        D_8006C718 = 1;
                    }
                }
                (&D_80070328)[0x1E] = 0x20;
            }
        }
        return;
    }
}

/**
 * UpdateUsingFlags() - func_80055294() - MATCHING
 * https://decomp.me/scratch/JW1UB
 */
void func_80055294(int flags) {

    if (flags & UPDATE_ENV) {
        func_80020E74(deltaTime);
        func_80021FF4();
        func_80022158();
        func_80022260();
    }
    if (flags & UPDATE_MOBYS) {
        func_8003038C();
    }
    if (flags & UPDATE_SPYRO) {
        func_8003E83C();
    }
    if (flags & UPDATE_PARTS) {
        if (UpdateParticles != 0) {
            (*UpdateParticles)(deltaTime);
        }
        func_800509F0();
    }
    if (flags & UPDATE_CAMERA) {
        func_8001204C();
    }
    func_800285A4(flags & UPDATE_HUD);
}

/**
 * InitBulletTime() - func_80055364() - MATCHING
 * https://decomp.me/scratch/kHnWT
 */
void func_80055364(Moby* moby) {
    game.state = GAMESTATE_BULLET_TIME;
    D_8006C5F8 = moby;
}

/**
 * ExitBulletTime() - func_80055380() - MATCHING
 * https://decomp.me/scratch/TqcH3
 */
void func_80055380(void) {
    game.state = GAMESTATE_GAMEPLAY;
    D_8006C5F8 = 0;
}

/**
 * UpdateBulletTime() - func_80055398() - MATCHING
 * https://decomp.me/scratch/BtdFp
 */
void func_80055398(void) {
    void (*mobyUpdate)(Moby*);
    void (**mobyUpdateFuncs)(Moby*) = ovlHeader.MobyUpdate;

    if (mobyUpdateFuncs != 0) {
        mobyUpdate = mobyUpdateFuncs[D_8006C5F8->mobyClass];
        if (mobyUpdate != 0) {
            mobyUpdate(D_8006C5F8);
        }
    }
    func_8001204C();
    func_800285A4(0);
}

/**
 * Update() - func_80055400() - MATCHING
 * Retail Rev 0: asm/nonmatchings/update/Update.s,
 * 0x80055400..0x800555C0 plus 20-entry jump table at 0x80011204.
 * Dispatch runs once per call. Exact C source hypothesis:
 * https://decomp.me/scratch/X6Lxc
 */


/* externed functions, only to be used as notes
void func_80050F18(); // gameplay updates
void func_80051A60(); // speech updates
void func_8005289C(); // egg collect updates
void func_80053374(); // sublevel loading updates
void func_80053A10(); // fade-in updates
void func_80054450(); // loading glide updates
void func_80054B64(); // game over updates
void func_80054CD8(); // init credits cheat updates
void func_80054D84(); // credits updates
void func_80055020(); // loading vehicle updates
void func_80055294(enum UpdateFlags updateFlags); // update with flags
void func_80055398(); // bullet time updates
*/

void Update(void) {
    enum UpdateFlags var_a0;

    D_8006C718 = 0;
    func_8003A584();
    func_8004FA24();
    switch (game.state) {
    case GAMESTATE_GAMEPLAY:
    case GAMESTATE_UNK_0E:
        func_80050F18();
        break;
    case GAMESTATE_SPEECH:
        func_80051A60();
        break;
    case GAMESTATE_EGG_COLLECT:
        func_8005289C();
        break;
    case GAMESTATE_SPEEDWAY_MENU:
        var_a0 = 0x10;
        if (camera.unk50 == 2) { // unsigned in some places? maybe causing matching issues
            (*ovlHeader.UpdateSpeedwayMenu)(var_a0); // 0x10 // UpdateSpeedwayMenu
            var_a0 = 0x11;
        }
        func_80055294(var_a0);
        break;
    case GAMESTATE_FADE_IN:
        func_80053A10();
        break;
    case GAMESTATE_PAUSE:
        func_80057834();
        break;
    case GAMESTATE_LOADING_IMG:
        func_80058778();
        break;
    case GAMESTATE_CUTSCENE:
        (*ovlHeader.UpdateCutscene)(); // UpdateCutscene
        break;
    case GAMESTATE_LOADING_GLIDE:
        func_80054450();
        break;
    case GAMESTATE_GAME_OVER:
        func_80054B64();
        break;
    case GAMESTATE_CREDITS:
        func_80054D84();
        break;
    case GAMESTATE_INIT_CREDITS_CHEAT:
        func_80054CD8();
        D_8006C67C = -1;
        break;
    case GAMESTATE_TITLE_SCREEN:
        func_title_8007566C();
        break;
    case GAMESTATE_LOADING_VEHICLE:
        func_80055020();
        break;
    case GAMESTATE_LOADING_SUBLEVEL:
        func_80053374();
        break;
    case GAMESTATE_BULLET_TIME:
        func_80055398();
        break;
    case GAMESTATE_SKATEBOARD_MENU:
        (*ovlHeader.UpdateSkateMenu)(); // UpdateSkateMenu
        var_a0 = 0x3B;
        func_80055294(var_a0);
        break;
    }
    func_8003C184();
}
