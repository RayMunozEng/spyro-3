#include "matching.h"
#include "common.h"
#include "drawutil.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80074C00.
 * Assembly SHA256 d4c148d746cef35e8aa5ee78a8a692c89a9a7bee819323dfa088e5ab5f038d16.
 * AI generated; not human reviewed. All 352 original instructions, nine
 * selector words (bias 13), one table-padding word and original strings
 * "%d"/"llllllllll" are required. Original frame 0x60 preserves buffer
 * SP18..37, fifth call argument SP10 and every saved S0..S7/FP/RA word.
 * S0 changes from the menu-record pointer to the draw-style word; other
 * original saved roles retain their explicit producers. The center argument
 * is an ordinary C variable; no fixed FP binding or skipped save is used.
 * Menu records use original stride12; language rows use stride180 bytes.
 * String entries remain LW pointers. Independent case loads, shared aligned
 * draw call, two original fill loops and default row advance are retained.
 * Every constant and string is from the identified original instructions/data.
 * Initialized empty constraints preserve original short producer lifetimes
 * and emit zero CPU words; the frozen C toolchain emits every instruction.
 * Units/fixed point, complete helper contracts and caller rate remain open;
 * cadence is per invocation. Falsification: every native/linked instruction,
 * actual branch/internal/table target, format/data/padding byte and full EXE/
 * every-overlay retail hash. Binary identity does not establish synchronized
 * runtime or system completeness. */
extern int OptionsTextData6FBD0View1 __asm__("D_8006FBD0");
extern int OptionsTextData6FBCCView1 __asm__("D_8006FBCC");
extern int OptionsTextData6FBC4View1 __asm__("D_8006FBC4");
extern int OptionsTextData6C76CView1 __asm__("D_8006C76C");
extern int OptionsTextData6C598View1 __asm__("D_8006C598");
extern int OptionsTextData6C694View1 __asm__("D_8006C694");
extern int OptionsTextData6C698View1 __asm__("D_8006C698");
extern int OptionsTextData6C7B0View1 __asm__("D_8006C7B0");
extern int OptionsTextData6C3F8View1 __asm__("D_8006C3F8");
extern int OptionsTextData6C3FCView1 __asm__("D_8006C3FC");
extern int OptionsTextData6C400View1 __asm__("D_8006C400");
extern unsigned char OptionsTextData67570View1[] __asm__("D_80067570");
extern unsigned char OptionsTextData69DE4View1[] __asm__("D_80069DE4");
extern unsigned char OptionsTextData69E3CView1[] __asm__("D_80069E3C");
extern unsigned char OptionsTextData69E40View1[] __asm__("D_80069E40");
extern unsigned char OptionsTextData69E44View1[] __asm__("D_80069E44");
extern unsigned char OptionsTextData69E48View1[] __asm__("D_80069E48");
extern unsigned char OptionsTextData69E4CView1[] __asm__("D_80069E4C");
extern unsigned char OptionsTextData69E50View1[] __asm__("D_80069E50");
extern unsigned char OptionsTextDatag_CheatFlags_2View1 __asm__("g_CheatFlags + 2");
extern unsigned char OptionsTextData6E50CView1 __asm__("D_8006E50C");
void OptionsTextCall1FD00View1(int, int, int, int) __asm__("func_8001FD00");
void OptionsTextCallDrawStringCenteredView1(char*, int, int, int) __asm__("DrawStringCentered");
void OptionsTextCallDrawStringRightAlignedView1(char*, int, int,
                                                int) __asm__("DrawStringRightAligned");
void OptionsTextCall2E748View1(char*, int, int, int, void*) __asm__("func_8002E748");
int OptionsTextCall2EBB0View1(char*) __asm__("func_8002EBB0");
int OptionsTextCallSprintfView1(char*, const char*, ...) __asm__("sprintf");
#define OptionsTextField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void func_options_80074C00(void) {
    char buffer[32];
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register int savedWord16 __asm__("$16");
    register int rowArgument17;
    register int rightArgument18 __asm__("$18");
    register int entryPointer19 __asm__("$19");
    register int bufferPointer20 __asm__("$20");
    register int entryIndex21;
    register int fillByte22 __asm__("$22");
    register int leftArgument23 __asm__("$23");
    register int centerArgument;
    argument4 = 152;
    argument5 = 360;
    argument6 = 76;
    MATCHING_KEEP3_CLOBBER(argument4, argument5, argument6, "$3");
    rawValue3 = OptionsTextData6FBD0View1;
    MATCHING_KEEP_CLOBBER(rawValue3, "$7");
    argument7 = 172;
    MATCHING_KEEP2(rawValue3, argument7);
    rowArgument17 = 101;
    entryIndex21 = 1;
    __asm__ volatile(""
                     : "=r"(rawValue3)
                     : "0"(rawValue3), "r"(rowArgument17), "r"(entryIndex21)
                     : "memory");
    rawValue2 = rawValue3 * 12;
    rawValue3 = (int)OptionsTextData67570View1;
    savedWord16 = rawValue2 + rawValue3;
    OptionsTextCall1FD00View1(argument4, argument5, argument6, argument7);
    MATCHING_KEEP(savedWord16);
    argument5 = 256;
    argument6 = 80;
    __asm__ volatile(""
                     : "=r"(argument5), "=r"(argument6)
                     : "0"(argument5), "1"(argument6)
                     : "$2", "$4", "memory");
    rawValue2 = OptionsTextData6C76CView1;
    __asm__("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
    argument4 = (int)OptionsTextData69DE4View1;
    rawValue3 = rawValue2 * 3;
    rawValue2 = (rawValue3 << 4) - rawValue3;
    rawValue2 <<= 2;
    rawValue3 = OptionsTextField((void*)savedWord16, unsigned char*, 0);
    rawValue2 += argument4;
    rawValue3 <<= 2;
    rawValue3 += rawValue2;
    MATCHING_KEEP(rawValue3);
    argument4 = OptionsTextField((void*)rawValue3, int*, 0);
    OptionsTextCallDrawStringCenteredView1((char*)argument4, argument5, argument6, 2);
    __asm__ volatile("" ::: "$30", "$23", "memory");
    centerArgument = 256;
    MATCHING_KEEP(centerArgument);
    leftArgument23 = 160;
    rawValue3 = OptionsTextField((void*)savedWord16, unsigned char*, 1);
    MATCHING_KEEP_CLOBBER(rawValue3, "$2");
    rawValue2 = 255;
    rightArgument18 = 352;
    if (rawValue3 == rawValue2)
        return;
    bufferPointer20 = (int)buffer;
    fillByte22 = 108;
    entryPointer19 = savedWord16 + 1;
drawNextEntry:
    argument5 = OptionsTextField((void*)entryPointer19, unsigned char*, 0);
    rawValue2 = 46;
    if (argument5 == rawValue2)
        goto advanceRow;
    rawValue2 = OptionsTextData6C76CView1;
    __asm__("" : "=r"(rawValue2) : "0"(rawValue2) : "$4", "memory");
    argument4 = (int)OptionsTextData69DE4View1;
    rawValue3 = rawValue2 * 3;
    rawValue2 = (rawValue3 << 4) - rawValue3;
    rawValue2 <<= 2;
    rawValue2 += argument4;
    rawValue3 = argument5 << 2;
    rawValue3 += rawValue2;
    rawValue2 = OptionsTextData6C598View1;
    argument4 = OptionsTextField((void*)rawValue3, int*, 0);
    if (rawValue2)
        goto alternateStyle;
    rawValue2 = OptionsTextData6FBCCView1;
    argument7 = 0;
    if (rawValue2 == entryIndex21) {
        rawValue2 = OptionsTextData6FBC4View1;
        rawValue2 &= 31;
        argument7 = rawValue2 < 22;
    }
    savedWord16 = argument7 + 2;
    goto styleReady;
alternateStyle:
    rawValue2 = OptionsTextData6FBCCView1;
    rawValue2 ^= entryIndex21;
    rawValue2 = (unsigned)rawValue2 < 1;
    MATCHING_KEEP(rawValue2);
    savedWord16 = rawValue2 + 2;
styleReady:
    rawValue3 = OptionsTextField((void*)entryPointer19, unsigned char*, 1);
    rawValue2 = 255;
    argument5 = leftArgument23;
    if (rawValue3 == rawValue2)
        goto drawCentered;
    argument6 = rowArgument17;
    argument7 = savedWord16;
    OptionsTextCall2E748View1((char*)argument4, argument5, argument6, argument7, 0);
    rawValue2 = OptionsTextField((void*)entryPointer19, unsigned char*, 0);
    switch (rawValue2) {
        case 13:
            rawValue2 = OptionsTextDatag_CheatFlags_2View1;
            argument5 = rightArgument18;
            if (!rawValue2)
                goto off13;
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E48View1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074E00) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        off13:
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E44View1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074E34) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 14:
            rawValue2 = OptionsTextData6E50CView1;
            argument5 = rightArgument18;
            if (!rawValue2)
                goto off14;
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E40View1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074E7C) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        off14:
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E3CView1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074EB0) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 15:
            argument6 = OptionsTextData6C694View1;
            argument5 = (int)"%d";
            OptionsTextCallSprintfView1(buffer, (char*)argument5, argument6);
            argument4 = (int)buffer;
            argument5 = rightArgument18;
            __asm__ volatile("" : : "i"(0x80074ED8) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 16:
            argument6 = OptionsTextData6C698View1;
            argument5 = (int)"%d";
            OptionsTextCallSprintfView1(buffer, (char*)argument5, argument6);
            argument4 = (int)buffer;
            argument5 = rightArgument18;
            __asm__ volatile("" : : "i"(0x80074F00) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 18:
            rawValue2 = OptionsTextData6C7B0View1;
            argument5 = rightArgument18;
            if (!rawValue2)
                goto off18;
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E40View1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074F48) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        off18:
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E3CView1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074F7C) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 19:
            rawValue2 = OptionsTextData6C3F8View1;
            argument5 = rightArgument18;
            if (!rawValue2)
                goto off19;
            rawValue3 = 0;
            if (rawValue2 <= 0)
                goto drawBar;
            argument4 = bufferPointer20;
            do {
                OptionsTextField((void*)argument4, unsigned char*, 0) = fillByte22;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "i"(0x80074FA4) : "memory");
                rawValue2 = OptionsTextData6C3F8View1;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "r"(rawValue2) : "memory");
                rawValue3++;
                rawValue2 = rawValue3 < rawValue2;
                argument4++;
            } while (rawValue2);
            goto drawBar;
        off19:
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E3CView1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80074FF4) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 20:
            rawValue2 = OptionsTextData6C3FCView1;
            argument5 = rightArgument18;
            if (!rawValue2)
                goto off20;
            rawValue3 = 0;
            if (rawValue2 <= 0)
                goto drawBar;
            argument4 = bufferPointer20;
            do {
                OptionsTextField((void*)argument4, unsigned char*, 0) = fillByte22;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "i"(0x8007501C) : "memory");
                rawValue2 = OptionsTextData6C3FCView1;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "r"(rawValue2) : "memory");
                rawValue3++;
                rawValue2 = rawValue3 < rawValue2;
                argument4++;
            } while (rawValue2);
        drawBar:
            __asm__ volatile("" : : "i"(0x80075038) : "memory");
            argument4 = (int)"llllllllll";
            MATCHING_KEEP_CLOBBER(argument4, "$2");
            rawValue2 = bufferPointer20 + rawValue3;
            MATCHING_KEEP(rawValue2);
            OptionsTextField((void*)rawValue2, unsigned char*, 0) = 0;
            rawValue2 = OptionsTextCall2EBB0View1((char*)argument4);
            argument4 = bufferPointer20;
            argument5 = rightArgument18 - rawValue2;
            argument6 = rowArgument17;
            argument7 = savedWord16;
            OptionsTextCall2E748View1((char*)argument4, argument5, argument6, argument7, 0);
            rowArgument17 += 14;
            goto nextEntry;
        off20:
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E3CView1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x80075098) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        case 21:
            rawValue2 = OptionsTextData6C400View1;
            argument5 = rightArgument18;
            if (!rawValue2)
                goto off21;
            rawValue2 = OptionsTextData6C76CView1;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E4CView1 + rawValue2, int*, 0);
            __asm__ volatile("" : : "i"(0x800750E0) : "memory");
            argument6 = rowArgument17;
            goto drawRightAligned;
        off21:
            rawValue2 = OptionsTextData6C76CView1;
            argument6 = rowArgument17;
            rawValue2 *= 180;
            argument4 = OptionsTextField(OptionsTextData69E50View1 + rawValue2, int*, 0);
        drawRightAligned:
            OptionsTextCallDrawStringRightAlignedView1((char*)argument4, argument5, argument6,
                                                       savedWord16);
            rowArgument17 += 14;
            goto nextEntry;
        default:
            goto advanceRow;
    }
drawCentered:
    argument5 = centerArgument;
    argument6 = rowArgument17;
    OptionsTextCallDrawStringCenteredView1((char*)argument4, argument5, argument6, savedWord16);
advanceRow:
    rowArgument17 += 14;
nextEntry:
    entryPointer19++;
    rawValue3 = OptionsTextField((void*)entryPointer19, unsigned char*, 0);
    rawValue2 = 255;
    entryIndex21++;
    if (rawValue3 != rawValue2)
        goto drawNextEntry;
}
#undef OptionsTextField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/options/options1/func_options_80075180.s SHA256 bb1a3fd9c763356c409a39a82afdccff0e7b1fe9479c6fbad16eb75072b409dd. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Options75180Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

void Options75180_DrawStringCentered(int, int, int, int) __asm__("DrawStringCentered");
/* extern */
void Options75180_DrawStringRowCentered(int, int, int, int) __asm__("DrawStringRowCentered");
/* extern */
int Options75180_func_80027934(int) __asm__("func_80027934");
/* extern */
int Options75180_func_80028378(unsigned char*, unsigned char) __asm__("func_80028378");
/* extern */
void* Options75180_func_800289C8(void*, int, int) __asm__("func_800289C8");
/* extern */
unsigned char Options75180_func_options_80078010(int) __asm__("func_options_80078010");
/* extern */
unsigned char Options75180_func_options_800780E0(int, int) __asm__("func_options_800780E0");
/* extern */
extern unsigned char Options75180_D_80069DD8 __asm__("D_80069DD8");
extern unsigned char Options75180_D_80069DDC __asm__("D_80069DDC");
extern int Options75180_D_8006C738 __asm__("D_8006C738");
extern int Options75180_D_8006C76C __asm__("D_8006C76C");
extern int Options75180_D_8006C788 __asm__("D_8006C788");
extern int Options75180_D_800725E0 __asm__("D_800725E0");
extern unsigned char Options75180_D_options_8007ADF0 __asm__("D_options_8007ADF0");
extern unsigned char Options75180_D_options_8007ADF4 __asm__("D_options_8007ADF4");
extern unsigned char Options75180_D_options_8007ADF8 __asm__("D_options_8007ADF8");
extern unsigned char Options75180_D_options_8007ADFC __asm__("D_options_8007ADFC");
extern unsigned char Options75180_D_options_8007AE00 __asm__("D_options_8007AE00");
extern unsigned char Options75180_D_options_8007AE10 __asm__("D_options_8007AE10");
extern unsigned char Options75180_D_options_8007AE18 __asm__("D_options_8007AE18");
extern unsigned char Options75180_D_options_8007AF30 __asm__("D_options_8007AF30");
extern unsigned char Options75180_D_options_8007AF38 __asm__("D_options_8007AF38");
extern unsigned char Options75180_D_options_8007AF40 __asm__("D_options_8007AF40");
extern unsigned char Options75180_D_options_8007AF44 __asm__("D_options_8007AF44");
extern unsigned char Options75180_D_options_8007AF48 __asm__("D_options_8007AF48");
extern unsigned char Options75180_D_options_8007AF4C __asm__("D_options_8007AF4C");
extern unsigned char Options75180_D_options_8007AF50 __asm__("D_options_8007AF50");
extern unsigned char Options75180_D_options_8007AF54 __asm__("D_options_8007AF54");
extern unsigned char Options75180_D_options_8007AF58 __asm__("D_options_8007AF58");
extern unsigned char Options75180_D_options_8007AF60 __asm__("D_options_8007AF60");
extern unsigned char Options75180_D_options_8007AF64 __asm__("D_options_8007AF64");
extern unsigned char Options75180_D_options_8007AF68 __asm__("D_options_8007AF68");
extern unsigned char Options75180_D_options_8007AF6C __asm__("D_options_8007AF6C");
extern unsigned char Options75180_D_options_8007AF70 __asm__("D_options_8007AF70");
extern unsigned char Options75180_D_options_8007AFB4 __asm__("D_options_8007AFB4");
extern unsigned char Options75180_D_options_8007AFB6 __asm__("D_options_8007AFB6");
extern unsigned char Options75180_D_options_8007AFB8 __asm__("D_options_8007AFB8");
extern int Options75180_D_options_8007AFBC __asm__("D_options_8007AFBC");
extern signed char Options75180_D_options_8007AFC7 __asm__("D_options_8007AFC7");

void func_options_80075180(void) {
    /* Original SCUS-94467 options1 function0x80075180:558 code words,
     * eighteen selectors at0x800744C8, frame0x20 and saved16/17/18 at
     * SP10/SP14/SP18. Language-table entries are WORDS indexed by four
     * byte offsets. Record data uses the original eight-byte stride and
     * unsigned byte reads at0/1/4/5;
      differences use signed word shifts.
     * Saved16 begins as103, then becomes a half-width scratch;
      saved17
     * retains the corresponding second coordinate across helper calls.
     * The selector byte pointer is held through both drawing calls.
     * Shared tails1/18 and2/3/6/9/10/14 retain their original targets;
     * duplicate8/12 and5/16/17 paths remain physically distinct.
     * The footer selector is reloaded as required by the disc. Empty
     * constraints and comment markers emit no CPU instructions.
     * Section metadata migration from batch11019 changed no original
     * instruction/data rows, labels or relocation expressions.
     * AI generated;
      not human reviewed. Physical coordinate/style units,
     * helper meanings, frame cadence and synchronized runtime parity
     * remain unresolved;
      binary identity is the confirmed boundary. */
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int recordIndex18 __asm__("$18");
    register int recordCoordinate5 __asm__("$5");
    register int recordCoordinate6 __asm__("$6");
    register int scratch2 __asm__("$2");
    register int scratch3 __asm__("$3");
    register unsigned char* recordPointer4 __asm__("$4");
    register unsigned char* selectionPointer16 __asm__("$16");
    register int highlight7 __asm__("$7");
    register unsigned char* secondTablePointer3 __asm__("$3");
    register int coordinate5 __asm__("$5");
    register int coordinate6 __asm__("$6");
    register int rowString4 __asm__("$4");
    register int string4 __asm__("$4");
    register int alternateRow4 __asm__("$4");
    register int style7 __asm__("$7");
    int selectorArgument4;

    Options75180_func_options_80078010(0x41);
    switch (Options75180_D_options_8007AFB4) {
        case 1:
            coordinate5 = 256;
            rowString4 = Options75180Field(
                &Options75180_D_options_8007AF68 + (Options75180_D_8006C76C * 4), int*, 0);
            coordinate6 = 115;
            goto block_50;
        case 2:
        case 3:
        case 6:
            coordinate5 = 256;
            alternateRow4 = Options75180Field(
                &Options75180_D_options_8007AF30 + (Options75180_D_8006C76C * 4), int*, 0);
            coordinate6 = 115;
            goto block_39;
        case 4:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF40 + Options75180_D_8006C76C * 4,
                                  int*, 0),
                256, 115, 2);
            highlight7 = 0;
            recordPointer4 = &Options75180_D_options_8007ADF8;
            selectionPointer16 = &Options75180_D_options_8007AFB8;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = *selectionPointer16;
            recordPointer4 = scratch2 * 4 + recordPointer4;
            if (scratch3 != 0)
                goto firstDraw4;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        firstDraw4:
            Options75180_DrawStringCentered(Options75180Field(recordPointer4, int*, 0), 192, 147,
                                            highlight7 | 2);
            scratch2 = Options75180_D_8006C76C;
            __asm__ volatile("# staged-language" ::: "memory");
            secondTablePointer3 = &Options75180_D_options_8007ADFC;
            highlight7 = 0;
            goto block_53;
        case 5:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF38 + (Options75180_D_8006C76C * 4),
                                  int*, 0),
                0x100, 0x73, 2);
            style7 = 2;
            recordPointer4 = &Options75180_D_options_8007AE18;
            scratch3 = Options75180_D_8006C76C;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch3 *= 4;
            scratch2 &= 31;
            scratch2 = scratch2 < 22;
            scratch3 += (int)recordPointer4;
            if (scratch2)
                style7 = 3;
            string4 = Options75180Field((void*)scratch3, int*, 0);
            coordinate5 = 320;
            __asm__ volatile("# scalar-case5");
            coordinate6 = 147;
            goto block_56;
        case 7:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF44 + Options75180_D_8006C76C * 4,
                                  int*, 0),
                256, 115, 2);
            highlight7 = 0;
            recordPointer4 = &Options75180_D_80069DD8;
            selectionPointer16 = &Options75180_D_options_8007AFB8;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = *selectionPointer16;
            recordPointer4 = scratch2 * 4 + recordPointer4;
            if (scratch3 != 0)
                goto firstDraw7;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        firstDraw7:
            Options75180_DrawStringCentered(Options75180Field(recordPointer4, int*, 0), 192, 147,
                                            highlight7 | 2);
            scratch2 = Options75180_D_8006C76C;
            __asm__ volatile("# staged-language" ::: "memory");
            secondTablePointer3 = &Options75180_D_80069DDC;
            MATCHING_KEEP(secondTablePointer3);
            highlight7 = 0;
            goto block_53;
        case 8:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF4C + Options75180_D_8006C76C * 4,
                                  int*, 0),
                256, 115, 2);
            secondTablePointer3 = &Options75180_D_80069DD8;
            scratch2 = Options75180_D_8006C76C;
            MATCHING_KEEP_CLOBBER(scratch2, "$16");
            selectionPointer16 = &Options75180_D_options_8007AFB8;
            recordPointer4 = (unsigned char*)(scratch2 * 4 + (int)secondTablePointer3);
            scratch3 = *selectionPointer16;
            highlight7 = 0;
            if (scratch3 != 1)
                goto firstDraw8;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        firstDraw8:
            Options75180_DrawStringCentered(Options75180Field(recordPointer4, int*, 0), 192, 147,
                                            highlight7 | 2);
            highlight7 = 0;
            recordPointer4 = &Options75180_D_80069DDC;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = *selectionPointer16;
            recordPointer4 = scratch2 * 4 + recordPointer4;
            if (scratch3)
                goto block_55;
            __asm__ volatile("# distinct-case8");
            goto block_54;
        case 9:
            coordinate5 = 256;
            alternateRow4 = Options75180Field(
                &Options75180_D_options_8007AF50 + (Options75180_D_8006C76C * 4), int*, 0);
            coordinate6 = 115;
            goto block_39;
        case 10:
            coordinate5 = 256;
            alternateRow4 = Options75180Field(
                &Options75180_D_options_8007AF48 + (Options75180_D_8006C76C * 4), int*, 0);
            coordinate6 = 115;
            goto block_39;
        case 11:
            selectorArgument4 = -1U;
            if (Options75180_D_options_8007AFB6 != 1) {
                style7 = 2;
                if (Options75180_D_options_8007AFB6 == 2) {
                    selectorArgument4 = Options75180_D_options_8007AFB8;
                    goto block_22;
                }
            } else {
            block_22:
                Options75180_func_options_800780E0(selectorArgument4, 0x69);
                style7 = 2;
            }
            style7 = 2;
            recordPointer4 = &Options75180_D_options_8007ADF0;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = Options75180_D_options_8007AFBC;
            scratch2 *= 4;
            scratch3 &= 31;
            scratch3 = scratch3 < 22;
            scratch2 += (int)recordPointer4;
            if (scratch3)
                style7 = 3;
            string4 = Options75180Field((void*)scratch2, int*, 0);
            coordinate5 = 320;
            __asm__ volatile("# scalar-case11");
            coordinate6 = 147;
            goto block_56;
        case 12:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF58 + Options75180_D_8006C76C * 4,
                                  int*, 0),
                256, 115, 2);
            secondTablePointer3 = &Options75180_D_80069DD8;
            scratch2 = Options75180_D_8006C76C;
            MATCHING_KEEP_CLOBBER(scratch2, "$16");
            selectionPointer16 = &Options75180_D_options_8007AFB8;
            recordPointer4 = (unsigned char*)(scratch2 * 4 + (int)secondTablePointer3);
            scratch3 = *selectionPointer16;
            highlight7 = 0;
            if (scratch3 != 1)
                goto firstDraw12;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        firstDraw12:
            Options75180_DrawStringCentered(Options75180Field(recordPointer4, int*, 0), 192, 147,
                                            highlight7 | 2);
            highlight7 = 0;
            recordPointer4 = &Options75180_D_80069DDC;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = *selectionPointer16;
            recordPointer4 = scratch2 * 4 + recordPointer4;
            if (scratch3)
                goto block_55;
            __asm__ volatile("# distinct-case12");
            goto block_54;
        case 13:
            recordPointer4 = &Options75180_D_options_8007AFB6;
            scratch2 = *recordPointer4;
            if (!scratch2)
                goto scalar13;
            scratch2 = Options75180_func_80028378(recordPointer4 + 14, 0);
            Options75180_D_options_8007AFC7 = scratch2;
            scratch2 &= 255;
            scratch2 <<= 3;
            recordPointer4 = (unsigned char*)Options75180_D_8006C788;
            scratch16 = 103;
            recordPointer4 += scratch2;
            recordCoordinate6 = recordPointer4[4];
            recordCoordinate5 = recordPointer4[0];
            scratch2 = recordPointer4[5];
            scratch3 = recordPointer4[1];
            recordCoordinate6 -= recordCoordinate5;
            scratch2 -= scratch3;
            scratch17 = scratch2 >> 1;
            scratch2 = recordCoordinate6 >> 1;
            recordCoordinate5 = 256 - scratch2;
            Options75180_func_800289C8(recordPointer4, recordCoordinate5, scratch16 - scratch17);
            scratch2 = Options75180_func_80027934(0x44E);
            scratch3 = Options75180_D_8006C738;
            scratch2 <<= 3;
            scratch2 += scratch3;
            recordIndex18 = Options75180Field((void*)scratch2, unsigned char*, 2);
            scratch2 = Options75180_D_8006C788;
            recordPointer4 = (unsigned char*)(recordIndex18 << 3);
            recordPointer4 += (int)scratch2;
            recordCoordinate6 = recordPointer4[4];
            recordCoordinate5 = recordPointer4[0];
            scratch2 = recordPointer4[5];
            scratch3 = recordPointer4[1];
            recordCoordinate6 -= recordCoordinate5;
            scratch2 -= scratch3;
            scratch17 = scratch2 >> 1;
            scratch17 = scratch16 - scratch17;
            scratch16 = recordCoordinate6 >> 1;
            recordCoordinate5 = 344 - scratch16;
            scratch2 =
                (int)Options75180_func_800289C8(recordPointer4, recordCoordinate5, scratch17);
            scratch3 = Options75180_D_options_8007AFBC;
            scratch3 &= 31;
            scratch3 = scratch3 < 22;
            recordPointer4 = (unsigned char*)scratch2;
            if (scratch3)
                goto secondRecord;
            scratch2 = 64;
            recordPointer4[4] = scratch2;
            recordPointer4[5] = scratch2;
            recordPointer4[6] = scratch2;
        secondRecord:
            recordIndex18 += 1;
            recordCoordinate5 = 168 - scratch16;
            recordCoordinate6 = scratch17;
            scratch2 = Options75180_D_8006C788;
            recordPointer4 = (unsigned char*)scratch2 + (recordIndex18 << 3);
            scratch2 = (int)Options75180_func_800289C8(recordPointer4, recordCoordinate5,
                                                       recordCoordinate6);
            scratch3 = Options75180_D_options_8007AFBC;
            scratch3 &= 31;
            scratch3 = scratch3 < 22;
            recordPointer4 = (unsigned char*)scratch2;
            if (scratch3)
                goto scalar13;
            scratch2 = 64;
            recordPointer4[4] = scratch2;
            recordPointer4[5] = scratch2;
            recordPointer4[6] = scratch2;
        scalar13:
            style7 = 2;
            recordPointer4 = &Options75180_D_options_8007AE10;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = Options75180_D_options_8007AFBC;
            scratch2 *= 4;
            scratch3 &= 31;
            scratch3 = scratch3 < 22;
            scratch2 += (int)recordPointer4;
            if (scratch3)
                style7 = 3;
            string4 = Options75180Field((void*)scratch2, int*, 0);
            coordinate5 = 256;
            __asm__ volatile("# scalar-case13");
            coordinate6 = 125;
            goto block_56;
        case 14:
            coordinate5 = 256;
            alternateRow4 = Options75180Field(
                &Options75180_D_options_8007AF54 + (Options75180_D_8006C76C * 4), int*, 0);
            coordinate6 = 115;
        block_39:
            Options75180_DrawStringRowCentered(alternateRow4, coordinate5, coordinate6, 2);
            break;
        case 15:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF6C + Options75180_D_8006C76C * 4,
                                  int*, 0),
                256, 115, 2);
            highlight7 = 0;
            recordPointer4 = &Options75180_D_80069DD8;
            selectionPointer16 = &Options75180_D_options_8007AFB8;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = *selectionPointer16;
            recordPointer4 = scratch2 * 4 + recordPointer4;
            if (scratch3 != 0)
                goto firstDraw15;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        firstDraw15:
            Options75180_DrawStringCentered(Options75180Field(recordPointer4, int*, 0), 192, 147,
                                            highlight7 | 2);
            scratch2 = Options75180_D_8006C76C;
            __asm__ volatile("# staged-language" ::: "memory");
            secondTablePointer3 = &Options75180_D_80069DDC;
            MATCHING_KEEP(secondTablePointer3);
            highlight7 = 0;
            goto block_53;
        case 16:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF64 + (Options75180_D_8006C76C * 4),
                                  int*, 0),
                0x100, 0x73, 2);
            style7 = 2;
            recordPointer4 = &Options75180_D_options_8007AE18;
            scratch3 = Options75180_D_8006C76C;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch3 *= 4;
            scratch2 &= 31;
            scratch2 = scratch2 < 22;
            scratch3 += (int)recordPointer4;
            if (scratch2)
                style7 = 3;
            string4 = Options75180Field((void*)scratch3, int*, 0);
            coordinate5 = 320;
            __asm__ volatile("# scalar-case16");
            coordinate6 = 147;
            goto block_56;
        case 17:
            Options75180_DrawStringRowCentered(
                Options75180Field(&Options75180_D_options_8007AF60 + (Options75180_D_8006C76C * 4),
                                  int*, 0),
                0x100, 0x73, 2);
            style7 = 2;
            recordPointer4 = &Options75180_D_options_8007AE18;
            scratch3 = Options75180_D_8006C76C;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch3 *= 4;
            scratch2 &= 31;
            scratch2 = scratch2 < 22;
            scratch3 += (int)recordPointer4;
            if (scratch2)
                style7 = 3;
            string4 = Options75180Field((void*)scratch3, int*, 0);
            coordinate5 = 320;
            __asm__ volatile("# scalar-case17");
            coordinate6 = 147;
            goto block_56;
        case 18:
            coordinate5 = 256;
            rowString4 = Options75180Field(
                &Options75180_D_options_8007AF70 + (Options75180_D_8006C76C * 4), int*, 0);
            coordinate6 = 115;
        block_50:
            Options75180_DrawStringRowCentered(rowString4, coordinate5, coordinate6, 2);
            highlight7 = 0;
            recordPointer4 = &Options75180_D_options_8007ADF0;
            selectionPointer16 = &Options75180_D_options_8007AFB8;
            scratch2 = Options75180_D_8006C76C;
            scratch3 = *selectionPointer16;
            recordPointer4 = scratch2 * 4 + recordPointer4;
            if (scratch3)
                goto firstDraw18;
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        firstDraw18:
            Options75180_DrawStringCentered(Options75180Field(recordPointer4, int*, 0), 192, 147,
                                            highlight7 | 2);
            highlight7 = 0;
            scratch2 = Options75180_D_8006C76C;
            __asm__ volatile("# staged-language" ::: "memory");
            secondTablePointer3 = &Options75180_D_options_8007ADF4;
        block_53:
            recordPointer4 = (unsigned char*)(scratch2 * 4 + (int)secondTablePointer3);
            scratch3 = *selectionPointer16;
            if (scratch3 != 1)
                goto block_55;
        block_54:
            scratch2 = Options75180_D_options_8007AFBC;
            scratch2 &= 31;
            highlight7 = scratch2 < 22;
        block_55:
            string4 = Options75180Field(recordPointer4, int*, 0);
            coordinate5 = 320;
            coordinate6 = 147;
            style7 = highlight7 | 2;
        block_56:
            Options75180_DrawStringCentered(string4, coordinate5, coordinate6, style7);
            break;
    }
    scratch2 = Options75180_D_800725E0;
    if (scratch2 < 0)
        goto done;
    coordinate5 = 256;
    coordinate6 = 70;
    recordPointer4 = &Options75180_D_options_8007AE00;
    __asm__ volatile("# reload-footer-selector" ::: "memory");
    scratch2 = Options75180_D_8006C76C;
    scratch3 = Options75180_D_800725E0;
    scratch2 *= 8;
    scratch2 += (int)recordPointer4;
    scratch3 *= 4;
    scratch3 += scratch2;
    MATCHING_KEEP(scratch3);
    Options75180_DrawStringCentered(Options75180Field((void*)scratch3, int*, 0), coordinate5,
                                    coordinate6, 2);
done:
    return;
}
#undef Options75180Field

extern int D_options_8007ABE0, D_80070148, D_8006FBD0;
void func_80058408(void);
void func_options_80074C00(void);
void func_options_80075180(void);
void func_options_80075A38(void) {
    func_80058408();
    switch (D_options_8007ABE0) {
        case 0:
        case 2:
            if (D_80070148 == 2)
                return;
            goto draw;
        case 1:
            switch (D_8006FBD0) {
                case 8:
                    goto draw;
                case 9:
                case 10:
                    goto menu;
                case 11:
                    goto special;
                default:
                    return;
            }
        default:
            return;
    }
draw:
    func_80020D70(0);
    return;
menu:
    func_options_80074C00();
    return;
special:
    func_options_80075180();
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/options/options1/func_options_80075B18.s SHA256 d4bd4f8c24be3c1d487f696b25d49dc67bcea9b89fc09f22f3bb29618d5bcb72. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Options75B18Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Options75B18_PlaySound(int, int, int) __asm__("PlaySound");
/* extern */
unsigned char Options75B18_func_800142AC(void*) __asm__("func_800142AC");
/* extern */
void Options75B18_func_8002A6B4(void) __asm__("func_8002A6B4");
/* extern */
void Options75B18_func_8002A714(void) __asm__("func_8002A714");
/* extern */
void Options75B18_func_8002A754(void) __asm__("func_8002A754");
/* extern */
unsigned char Options75B18_func_8003C140(int, int) __asm__("func_8003C140");
/* extern */
extern unsigned char Options75B18_D_80067570 __asm__("D_80067570");
extern int Options75B18_D_8006C3F8 __asm__("D_8006C3F8");
extern int Options75B18_D_8006C3FC __asm__("D_8006C3FC");
extern int Options75B18_D_8006C400 __asm__("D_8006C400");
extern void* Options75B18_D_8006C654 __asm__("D_8006C654");
extern int Options75B18_D_8006C694 __asm__("D_8006C694");
extern int Options75B18_D_8006C698 __asm__("D_8006C698");
extern int Options75B18_D_8006C7AC __asm__("D_8006C7AC");
extern int Options75B18_D_8006C7B0 __asm__("D_8006C7B0");
extern int Options75B18_D_8006E4AC __asm__("D_8006E4AC");
extern unsigned char Options75B18_D_8006E50C __asm__("D_8006E50C");
extern int Options75B18_D_8006E524 __asm__("D_8006E524");
extern int Options75B18_D_8006E53C __asm__("D_8006E53C");
extern int Options75B18_D_8006FBC4 __asm__("D_8006FBC4");
extern int Options75B18_D_8006FBCC __asm__("D_8006FBCC");
extern int Options75B18_D_8006FBD0 __asm__("D_8006FBD0");
extern int Options75B18_D_8006FBD4 __asm__("D_8006FBD4");
extern unsigned short Options75B18_D_8006FC60 __asm__("D_8006FC60");
extern unsigned short Options75B18_D_8006FC62 __asm__("D_8006FC62");
extern unsigned short Options75B18_D_8006FCD4 __asm__("D_8006FCD4");
extern unsigned short Options75B18_D_8006FCD6 __asm__("D_8006FCD6");
extern signed char Options75B18_D_8007014E __asm__("D_8007014E");
extern int Options75B18_D_options_8007ABE0 __asm__("D_options_8007ABE0");
extern signed char Options75B18_D_options_8007AFB4 __asm__("D_options_8007AFB4");
extern unsigned char g_CheatFlags;

void func_options_80075B18(void) {
    /* Original SCUS-94467 options1 routine at 0x80075B18: 431 code
     * words, with nine owned selectors at 0x80074510. The preceding 0x80075180 table uses the ordinary read-only
     * section so compiler-emitted selectors follow it in retail order.
     * That assembly change modifies section metadata only: all original
     * instructions, data, labels and relocation expressions are retained.
     * Frame size0x18,
     * saved RA atSP10. Table rows use twelve-byte strides. The three
     * HUD helper calls have no C arguments;
      incoming register4 values
     * in the disc instructions are retained raw table/selector producers.
     * Selected values use signed word bounds;
      the two mirrored outputs
     * reload unsigned HALFWORDS from their original word locations.
     * Full-width raw producers and ordered shared labels retain selector,
     * increment/decrement and sound-call control targets. The sound
     * descriptor byte is read at offset0x1A;
      event semantics, archive
     * mapping, playback units and timing remain unresolved. Empty
     * constraints emit no CPU instructions. AI generated;
      not human
     * reviewed. Physical units, frame cadence and runtime parity remain
     * unresolved;
      matching the binary does not establish those meanings. */
    register int scratch2 __asm__("$2");
    register int scratch3 __asm__("$3");
    register unsigned char* tablePointer4 __asm__("$4");
    register unsigned char* rowPointer5 __asm__("$5");
    register int* cursorPointer6 __asm__("$6");
    register int* cursorPointer5 __asm__("$5");
    register int* cursorPointer4 __asm__("$4");
    register int sentinel5 __asm__("$5");
    register int channel4 __asm__("$4");
    register int quantity6 __asm__("$6");
    register unsigned char* descriptorPointer3 __asm__("$3");
    register int argumentZero5 __asm__("$5");
    unsigned char toggledByte2;

    scratch3 = Options75B18_D_8006E53C;
    if (scratch3 & 0x800) {
        Options75B18_D_options_8007ABE0 = 2;
        Options75B18_D_8006FBCC = 1;
        Options75B18_D_8006FBD0 = 7;
        Options75B18_D_8006FBC4 = 0;
        Options75B18_D_8006FBD4 = 0;
        Options75B18_D_8007014E = 1;
        goto done;
    }
    if (scratch3 & 0x10)
        goto sharedToggle;
    scratch2 = scratch3 & 0x40;
    if (!scratch2)
        goto navigation;
    scratch3 = Options75B18_D_8006FBD0;
    tablePointer4 = &Options75B18_D_80067570;
    scratch2 = scratch3 * 12;
    scratch3 = Options75B18_D_8006FBCC;
    scratch2 = (int)(tablePointer4 + scratch2 + scratch3);
    scratch3 = *(unsigned char*)scratch2;
    if (scratch3 != 34)
        goto selectOther;
sharedToggle:
    cursorPointer4 = &Options75B18_D_8006FBD0;
    if (*cursorPointer4 != 8)
        goto setEight;
    Options75B18_D_options_8007ABE0 = 2;
    *cursorPointer4 = 7;
    goto resetSelection;
setEight:
    *cursorPointer4 = 8;
    goto resetSelection;
selectOther:
    if (scratch3 == 32)
        goto selected32;
    if (scratch3 >= 33)
        goto test33;
    if (scratch3 == 31)
        goto selected31;
    goto navigation;
test33:
    if (scratch3 != 33)
        goto navigation;
    Options75B18_func_8002A6B4();
    Options75B18_D_8006FBD0 = 11;
    Options75B18_D_8006FBC4 = 0;
    Options75B18_D_8006FBD4 = 0;
    Options75B18_D_8006FBCC = 1;
    Options75B18_D_options_8007AFB4 = 0;
    goto done;
selected31:
    Options75B18_func_8002A6B4();
    scratch2 = 9;
    goto storeSelection;
selected32:
    Options75B18_func_8002A6B4();
    scratch2 = 10;
storeSelection:
    Options75B18_D_8006FBD0 = scratch2;
resetSelection:
    Options75B18_D_8006FBC4 = 0;
    Options75B18_D_8006FBD4 = 0;
    Options75B18_D_8006FBCC = 1;
    goto done;
navigation:
    __asm__ volatile("# reload-controls" ::: "memory");
    scratch3 = Options75B18_D_8006E53C;
    scratch2 = scratch3 & 0x1000;
    if (!scratch2) {
        scratch2 = scratch3 & 0x4000;
        goto nextNavigation;
    }
    Options75B18_func_8002A714();
    cursorPointer6 = &Options75B18_D_8006FBCC;
    scratch2 = *cursorPointer6 - 1;
    *cursorPointer6 = scratch2;
    if (scratch2 > 0)
        goto done;
    scratch3 = Options75B18_D_8006FBD0;
    tablePointer4 = &Options75B18_D_80067570;
    scratch2 = scratch3 * 12;
    scratch3 = Options75B18_D_8006FBCC;
    rowPointer5 = tablePointer4 + scratch2;
    scratch3 = *(rowPointer5 + scratch3 + 1);
    if (scratch3 == 255)
        goto done;
    cursorPointer4 = cursorPointer6;
    scratch3 = (int)rowPointer5;
    sentinel5 = 255;
    MATCHING_KEEP(sentinel5);
previousLoop:
    scratch2 = *cursorPointer4 + 1;
    *cursorPointer4 = scratch2;
    scratch2 = Options75B18_D_8006FBCC;
    scratch2 = *(unsigned char*)(scratch3 + scratch2 + 1);
    if (scratch2 == sentinel5)
        goto done;
    goto previousLoop;
nextNavigation:
    if (!scratch2)
        goto selectedSetting;
    Options75B18_func_8002A714();
    cursorPointer5 = &Options75B18_D_8006FBCC;
    scratch2 = *cursorPointer5 + 1;
    *cursorPointer5 = scratch2;
    scratch3 = Options75B18_D_8006FBD0;
    tablePointer4 = &Options75B18_D_80067570;
    scratch2 = scratch3 * 12;
    scratch3 = Options75B18_D_8006FBCC;
    scratch2 = (int)(tablePointer4 + scratch2 + scratch3);
    scratch3 = *(unsigned char*)scratch2;
    if (scratch3 != 255)
        goto done;
    *cursorPointer5 = 1;
    goto done;
selectedSetting:
    scratch3 = Options75B18_D_8006FBD0;
    tablePointer4 = &Options75B18_D_80067570;
    scratch2 = scratch3 * 12;
    scratch3 = Options75B18_D_8006FBCC;
    scratch2 = (int)(tablePointer4 + scratch2 + scratch3);
    scratch2 = *(unsigned char*)scratch2;
    switch (scratch2) {
        case 13: /* switch 2 */
            if (Options75B18_D_8006E53C & 0xA040) {
                Options75B18_func_8002A754();
                Options75B18Field(&g_CheatFlags, unsigned char*, 2) =
                    (unsigned char)(1 - Options75B18Field(&g_CheatFlags, unsigned char*, 2));
                Options75B18_func_800142AC(&g_CheatFlags + 2);
                return;
            }
        default: /* switch 2 */
            return;
        case 14: /* switch 2 */
            if (Options75B18_D_8006E53C & 0xA040) {
                Options75B18_func_8002A754();
                toggledByte2 = 1 - Options75B18_D_8006E50C;
                Options75B18_D_8006E50C = toggledByte2;
                if (toggledByte2 & 0xFF) {
                    Options75B18_D_8006E524 = 0xF;
                    return;
                }
            }
            goto done;
        case 15:
            scratch3 = Options75B18_D_8006C694;
            if (scratch3 >= 16) {
                scratch2 = scratch3 < -15;
                goto lower15;
            }
            scratch2 = Options75B18_D_8006E53C & 0x2000;
            if (scratch2) {
                scratch2 = scratch3 + 1;
                goto store15;
            }
            scratch2 = scratch3 < -15;
        lower15:
            if (scratch2)
                goto copy15;
            scratch2 = Options75B18_D_8006E53C & 0x8000;
            if (!scratch2)
                goto copy15;
            scratch2 = scratch3 - 1;
        store15:
            Options75B18_D_8006C694 = scratch2;
            Options75B18_D_8006C7AC = 1;
            Options75B18_func_8002A754();
        copy15:
            scratch2 = Options75B18Field(&Options75B18_D_8006C694, unsigned short*, 0);
            Options75B18_D_8006FCD4 = scratch2;
            Options75B18_D_8006FC60 = scratch2;
            goto done;
        case 16:
            scratch3 = Options75B18_D_8006C698;
            if (scratch3 >= 16)
                goto lower16;
            scratch2 = Options75B18_D_8006E53C & 0x2000;
            if (scratch2) {
                scratch2 = scratch3 + 1;
                goto store16;
            }
        lower16:
            if (scratch3 <= 0)
                goto copy16;
            scratch2 = Options75B18_D_8006E53C & 0x8000;
            if (!scratch2)
                goto copy16;
            scratch2 = scratch3 - 1;
        store16:
            Options75B18_D_8006C698 = scratch2;
            Options75B18_D_8006C7AC = 1;
            Options75B18_func_8002A754();
        copy16:
            scratch2 = Options75B18Field(&Options75B18_D_8006C698, unsigned short*, 0);
            Options75B18_D_8006FCD6 = scratch2;
            Options75B18_D_8006FC62 = scratch2;
            goto done;
        case 18: /* switch 2 */
            if (Options75B18_D_8006E53C & 0xA040) {
                Options75B18_func_8002A754();
                Options75B18_D_8006C7B0 = 1 - Options75B18_D_8006C7B0;
                return;
            }
            goto done;
        case 19:
            scratch3 = Options75B18_D_8006C3F8;
            if (scratch3 >= 10)
                goto lower19;
            scratch2 = Options75B18_D_8006E53C & 0x2000;
            if (scratch2) {
                scratch2 = scratch3 + 1;
                goto store19;
            }
        lower19:
            if (!scratch3)
                goto done;
            scratch2 = Options75B18_D_8006E53C & 0x8000;
            if (!scratch2)
                goto done;
            scratch2 = scratch3 - 1;
        store19:
            Options75B18_D_8006C3F8 = scratch2;
            Options75B18_func_8002A754();
            goto done;
        case 20: /* switch 2 */
            quantity6 = Options75B18_D_8006C3FC;
            channel4 = -1;
            if (quantity6 >= 10)
                goto decrementAudio;
            scratch2 = Options75B18_D_8006E53C & 0x2000;
            if (!scratch2)
                goto decrementAudio;
            argumentZero5 = 0;
            descriptorPointer3 = Options75B18_D_8006C654;
            scratch2 = quantity6 + 1;
            goto storeAudio;
        decrementAudio:
            if (!quantity6)
                goto afterAudio;
            scratch2 = Options75B18_D_8006E53C & 0x8000;
            if (!scratch2)
                goto afterAudio;
            argumentZero5 = 0;
            descriptorPointer3 = Options75B18_D_8006C654;
            scratch2 = quantity6 - 1;
        storeAudio:
            Options75B18_D_8006C3FC = scratch2;
            channel4 = Options75B18_PlaySound(descriptorPointer3[0x1A], argumentZero5, 0);
        afterAudio:
            if (channel4 >= 0) {
                Options75B18_func_8003C140(channel4, (Options75B18_D_8006C3FC * 0xC00) / 10);
            }
            Options75B18_D_8006E4AC = (Options75B18_D_8006C3FC * 0x5FFF) / 10;
            return;
        case 21: /* switch 2 */
            if (Options75B18_D_8006E53C & 0xA040) {
                Options75B18_func_8002A754();
                Options75B18_D_8006C400 = 1 - Options75B18_D_8006C400;
            }
            goto done;
    }
done:
    return;
}
#undef Options75B18Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800761D4.
* AI generated; not human reviewed. All1405 original instructions,26 switch
* selectors and every actual destination must match:1431 recorded words.
* Frame30hex=48 bytes saves S0..S3/RA;SP10..1F contains outgoing arguments.
* The original20-way outer and6-way inner dispatches retain physical order.
* Three signed LH-1 table scans retain full -1 counters and late increments.
* Original3 is produced after the context-result zero test. A complete
* initialized V0 identity on the nonzero path preserves the original second
* comparison and delay slot;this also keeps the earlier mode test exact.
* Both complete79004 fifth arguments128/7552 are explicit C ABI inputs.
* A separate original second call site uses an independent symbol view of
* that same helper;no new CPU function or instruction is introduced.
* Indexed-record ADDU retains its complete original base through the load.
* Original context/mode pointers,halfword sprite selectors,byte flags,
* full result/state words and all shared state/return entries remain exact.
* Known helper views reuse hud.h,memcard.h,stdutil.h and matched options
* source contracts. Remaining helper meanings and units are unresolved.
* Empty metadata consumes complete initialized values or written fields,
* or clobbers dead values before fresh full producers;zero CPU instructions.
* No opcode asm,partial HI/LO,fixed FP,undefined incoming saved input or
* overlapping live fixed aliases. Compiler/filter/flags remain unchanged.
* Confidence is binary identity after all gates. Complete helper/caller
* chains,units/fixed point,cadence beyond invocation,Rev1 mapping and retail
* runtime remain open. Next:human review and synchronized retail captures.
* Every native/linked word,actual target,owned selector and full EXE/every-
* overlay retail hash must remain identical.
*/
/* Original assembly SHA256 78a2521633cfb8a92b06ce01bc620e4491717762c936518e3fc02e010bf3d843 */
#define Options761D4Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Options761D4Call27934View1(int) __asm__("func_80027934");
void Options761D4Call4E790View1(void*, int, int) __asm__("func_8004E790");
void Options761D4Call4E7D4View1(int*, int*, int) __asm__("func_8004E7D4");
int Options761D4Call778A0View1(unsigned char*) __asm__("func_options_800778A0");
void Options761D4Call778C8View1(void*, int) __asm__("func_options_800778C8");
int Options761D4Call77B58View1(void*) __asm__("func_options_80077B58");
int Options761D4Call77C94View1() __asm__("func_options_80077C94");
int Options761D4Call7833CView1() __asm__("func_options_8007833C");
int Options761D4Call78494View1() __asm__("func_options_80078494");
int Options761D4Call78504View1() __asm__("func_options_80078504");
int Options761D4Call788C8View1() __asm__("func_options_800788C8");
int Options761D4Call78BD8View1() __asm__("func_options_80078BD8");
int Options761D4Call79004View1() __asm__("func_options_80079004");
int Options761D4Call79004View2() __asm__("func_options_80079004");
int Options761D4Call7925CView1() __asm__("func_options_8007925C");
int Options761D4Call794B4View1(int, int*, int*) __asm__("func_options_800794B4");
int Options761D4Call795D0View1() __asm__("func_options_800795D0");
int Options761D4Call796CCView1() __asm__("func_options_800796CC");
extern int Options761D4Data6C648View1 __asm__("D_8006C648");
extern int Options761D4Data6C694View1 __asm__("D_8006C694");
extern int Options761D4Data6C698View1 __asm__("D_8006C698");
extern int Options761D4Data6C738View1 __asm__("D_8006C738");
extern int Options761D4Data6C76CView1 __asm__("D_8006C76C");
extern int Options761D4Data6E53CView1 __asm__("D_8006E53C");
extern int Options761D4Data6FBC4View1 __asm__("D_8006FBC4");
extern int Options761D4Data6FBCCView1 __asm__("D_8006FBCC");
extern int Options761D4Data6FBD0View1 __asm__("D_8006FBD0");
extern int Options761D4Data6FBD4View1 __asm__("D_8006FBD4");
extern int Options761D4Data70148View1 __asm__("D_80070148");
extern signed char Options761D4Data7014EView1 __asm__("D_8007014E");
extern int Options761D4Data725B0View1 __asm__("D_800725B0");
extern int Options761D4Data725B4View1 __asm__("D_800725B4");
extern int Options761D4Data725B8View1 __asm__("D_800725B8");
extern int Options761D4Data725BCView1 __asm__("D_800725BC");
extern int Options761D4Data725C0View1 __asm__("D_800725C0");
extern int Options761D4Data725C4View1 __asm__("D_800725C4");
extern int Options761D4Data725C8View1 __asm__("D_800725C8");
extern int Options761D4Data725CCView1 __asm__("D_800725CC");
extern int Options761D4Data725D4View1 __asm__("D_800725D4");
extern int Options761D4Data725E0View1 __asm__("D_800725E0");
extern int Options761D4Data725E4View1 __asm__("D_800725E4");
extern int Options761D4Data7ABE0View1 __asm__("D_options_8007ABE0");
extern int Options761D4Data7ABE4View1 __asm__("D_options_8007ABE4");
extern int Options761D4Data7ABE8View1 __asm__("D_options_8007ABE8");
extern unsigned char Options761D4Data7AFB4View1 __asm__("D_options_8007AFB4");
extern unsigned char Options761D4Data7AFB5View1 __asm__("D_options_8007AFB5");
extern unsigned char Options761D4Data7AFB6View1 __asm__("D_options_8007AFB6");
extern unsigned char Options761D4Data7AFB7View1 __asm__("D_options_8007AFB7");
extern unsigned char Options761D4Data7AFB8View1 __asm__("D_options_8007AFB8");
extern unsigned char Options761D4Data7AFB9View1 __asm__("D_options_8007AFB9");
extern unsigned char Options761D4Data7AFBAView1 __asm__("D_options_8007AFBA");
extern int Options761D4Data7AFBCView1 __asm__("D_options_8007AFBC");
extern short Options761D4Data7AFC4View1 __asm__("D_options_8007AFC4");
extern unsigned char Options761D4Data7AFC6View1 __asm__("D_options_8007AFC6");
extern unsigned char Options761D4Data7AFC7View1 __asm__("D_options_8007AFC7");
extern int Options761D4Data7AFDCView1 __asm__("D_options_8007AFDC");
extern signed char Options761D4Data7B1DCView1 __asm__("D_options_8007B1DC");
extern signed char Options761D4Data7B1DDView1 __asm__("D_options_8007B1DD");
extern signed char Options761D4Data7B1DEView1 __asm__("D_options_8007B1DE");
extern signed char Options761D4Data7B1DFView1 __asm__("D_options_8007B1DF");
extern int Options761D4Data7B25CView1 __asm__("D_options_8007B25C");
extern unsigned char Options761D4Data7B260View1 __asm__("D_options_8007B260");
extern int Options761D4Data7BB58View1 __asm__("D_options_8007BB58");
extern signed char Options761D4Data7BB60View1 __asm__("D_options_8007BB60");
extern int Options761D4Data7C458View1 __asm__("D_options_8007C458");
extern signed char Options761D4Data7C460View1 __asm__("D_options_8007C460");
extern int Options761D4Data7CD58View1 __asm__("D_options_8007CD58");
void func_options_800761D4(void) {
    register int retainedContextRecordOrIndex16 __asm__("$16"),
        retainedModePointerOrIndex17 __asm__("$17"), retainedContextBase18 __asm__("$18"),
        retainedSignedTerminator19 __asm__("$19");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        scratchWord8 __asm__("$8"), scratchWord9 __asm__("$9");
    int temporaryWord5;
    int completeInitialModeOne;
    int indexedRecordAddress;
    int retainedOriginalRecordBase;
    int temporaryWord2;
    int temporaryWord1;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord3;
    if ((unsigned char)Options761D4Data7AFB4View1 >= 0x14U) {
        goto returnOriginal;
    }
    switch (Options761D4Data7AFB4View1) {
        case 0:
            goto originalDispatch1Case0;
        case 1:
            goto originalDispatch1Case1;
        case 2:
            goto originalDispatch1Case2;
        case 3:
            goto originalDispatch1Case3;
        case 4:
            goto originalDispatch1Case4;
        case 5:
            goto originalDispatch1Case5;
        case 6:
            goto originalDispatch1Case6;
        case 7:
            goto originalDispatch1Case7;
        case 8:
            goto originalDispatch1Case8;
        case 9:
            goto originalDispatch1Case9;
        case 10:
            goto originalDispatch1Case10;
        case 11:
            goto originalDispatch1Case11;
        case 12:
            goto originalDispatch1Case12;
        case 13:
            goto originalDispatch1Case13;
        case 14:
            goto originalDispatch1Case14;
        case 15:
            goto originalDispatch1Case15;
        case 16:
            goto originalDispatch1Case16;
        case 17:
            goto originalDispatch1Case17;
        case 18:
            goto originalDispatch1Case18;
        case 19:
            goto originalDispatch1Case19;
        default:
            return;
    }
originalDispatch1Case0:
    Options761D4Call78494View1();
    if (Options761D4Data725C8View1 != 3) {
        goto block_229;
    }
    rawWord2 = 0x11;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case1:
    Options761D4Data725C8View1 = 0;
    if (Options761D4Data6E53CView1 & 0x810) {
        goto block_232;
    }
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0xA000;
        goto block_236;
    }
    rawWord2 = rawWord3 & 0xA000;
    if (Options761D4Data7AFB8View1 != 0) {
        goto block_232;
    }
    Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) = (int)Options761D4Data725BCView1;
    Options761D4Data725E4View1 = Options761D4Data725C0View1;
    if (Options761D4Data725BCView1 < 0) {
        goto block_233;
    }
    rawWord2 = 2;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case2:
    argumentWord4 = 1;
    MATCHING_OBSERVE_VOLATILE(argumentWord4);
    retainedContextRecordOrIndex16 = (int)&Options761D4Data725B0View1;
    if (Options761D4Call794B4View1(argumentWord4, retainedContextRecordOrIndex16,
                                   retainedContextRecordOrIndex16 + 4) == 0) {
        goto returnOriginal;
    }
    completeInitialModeOne = 1;
    MATCHING_OBSERVE_VOLATILE(completeInitialModeOne);
    retainedModePointerOrIndex17 = (int)&Options761D4Data7AFB6View1;
    MATCHING_KEEP(retainedModePointerOrIndex17);
    argumentWord4 = Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0);
    MATCHING_KEEP(argumentWord4);
    if (argumentWord4 == completeInitialModeOne) {
        goto readOriginalContextResult89;
    }
    if (argumentWord4 >= 2) {
        goto block_14;
    }
    if (argumentWord4 == 0) {
        goto block_16;
    }
    goto returnOriginal;
block_14:
    if (argumentWord4 == 2) {
        goto checkOriginalSecondMode129;
    }
    goto returnOriginal;
block_16:
    Options761D4Call788C8View1(Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) * 0x10);
    goto writeOriginalSharedReturnState;
readOriginalContextResult89:
    argumentWord5 = Options761D4Field(retainedContextRecordOrIndex16, int*, 4);
    if (!argumentWord5) {
        rawWord2 = 3;
        goto prepareOriginalRecordTransfer95;
    }
    rawWord2 = 3;
    MATCHING_KEEP(rawWord2);
    if (argumentWord5 != rawWord2) {
        goto checkOriginalRetryCount112;
    }
prepareOriginalRecordTransfer95:
    Options761D4Call79004View1(Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) * 16,
                               Options761D4Data7ABE4View1,
                               (int)&Options761D4Data7B25CView1 + Options761D4Data725E4View1 * 2304,
                               Options761D4Data725E4View1 * 2304 + 640, 128);
    goto writeOriginalSharedReturnState;
checkOriginalRetryCount112:
    rawWord3 = Options761D4Data7AFBAView1;
    if ((unsigned)rawWord3 >= 3) {
        rawWord2 = -1;
        goto prepareOriginalContextReset122;
    }
    rawWord2 = rawWord3 + 1;
    Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0) = 0;
    Options761D4Data7AFBAView1 = rawWord2;
    goto returnOriginal;
prepareOriginalContextReset122:
    Options761D4Data725BCView1 = rawWord2;
    Options761D4Data725C0View1 = rawWord2;
    Options761D4Data725C8View1 = argumentWord4;
    MATCHING_OBSERVE2_VOLATILE(argumentWord4, rawWord2);
    rawWord2 = 3;
    goto writeOriginalSharedState;
checkOriginalSecondMode129:
    argumentWord5 = Options761D4Field(retainedContextRecordOrIndex16, int*, 4);
    rawWord2 = 5;
    if (argumentWord5 != rawWord2) {
        rawWord2 = -1;
        goto readOriginalRecordTable145;
    }
    rawWord2 = -1;
    Options761D4Data725BCView1 = rawWord2;
    Options761D4Data725C0View1 = rawWord2;
    Options761D4Data725C8View1 = argumentWord4;
    MATCHING_OBSERVE2_VOLATILE(argumentWord5, rawWord2);
    rawWord2 = 3;
    goto writeOriginalSharedState;
readOriginalRecordTable145:
    if (argumentWord5)
        goto block_29;
    rawWord3 = Options761D4Data725E4View1;
    rawWord2 = rawWord3 * 2304;
    rawWord3 = Options761D4Field((int)&Options761D4Data7B25CView1, int*, rawWord2);
    rawWord2 = Options761D4Data725C4View1;
    if (rawWord3 != rawWord2) {
        rawWord2 = -1;
        goto block_28;
    }
    rawWord2 = 15;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_28:
    Options761D4Data725BCView1 = rawWord2;
    Options761D4Data725C0View1 = rawWord2;
    Options761D4Data725C8View1 = argumentWord4;
    MATCHING_OBSERVE2_VOLATILE(rawWord3, rawWord2);
    rawWord2 = 3;
    goto writeOriginalSharedState;
block_29:
    rawWord3 = Options761D4Data7AFBAView1;
    if ((unsigned)rawWord3 < 3) {
        rawWord2 = rawWord3 + 1;
        goto block_83;
    }
    rawWord2 = 3;
    Options761D4Data725C8View1 = rawWord2;
    rawWord2 = -1;
    Options761D4Data725BCView1 = rawWord2;
    Options761D4Data725C0View1 = rawWord2;
    rawWord2 = 17;
writeOriginalSharedState:
    Options761D4Data725B8View1 = 0;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case3:
    retainedContextRecordOrIndex16 = (int)&Options761D4Data725E0View1;
    Options761D4Field(retainedContextRecordOrIndex16, int*, 0) = -1;
    MATCHING_KEEP(retainedContextRecordOrIndex16);
    argumentWord4 = 1;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$18");
    retainedContextBase18 = retainedContextRecordOrIndex16 - 48;
    MATCHING_KEEP(retainedContextBase18);
    if (Options761D4Call794B4View1(argumentWord4, retainedContextBase18,
                                   retainedContextRecordOrIndex16 - 44) == 0) {
        goto returnOriginal;
    }
    rawWord2 = 1;
    retainedModePointerOrIndex17 = (int)&Options761D4Data7AFB6View1;
    MATCHING_KEEP(retainedModePointerOrIndex17);
    rawWord3 = Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0);
    MATCHING_KEEP(rawWord3);
    if (rawWord3 == rawWord2) {
        goto block_40;
    }
    if (rawWord3 >= 2) {
        goto block_37;
    }
    if (rawWord3 == 0) {
        goto block_39;
    }
    goto returnOriginal;
block_37:
    argumentWord6 = 0;
    if (rawWord3 == 2) {
        goto block_41;
    }
    goto returnOriginal;
block_39:
    MATCHING_KEEP_VOLATILE(rawWord3);
    Options761D4Call788C8View1(0);
    goto writeOriginalSharedReturnState;
block_40:
    rawWord2 = Options761D4Field(retainedContextRecordOrIndex16, int*, -44);
    Options761D4Data725CCView1 = rawWord2;
    rawWord2 = rawWord2 != 4;
    Options761D4Data725D4View1 = rawWord2;
    Options761D4Call788C8View1(0x10);
    goto writeOriginalSharedReturnState;
block_41:
    argumentWord4 = 0;
    MATCHING_KEEP_VOLATILE(rawWord3);
    scratchWord8 = 2;
    argumentWord7 = 1;
    argumentWord5 = retainedContextBase18 + 28;
    rawWord2 = Options761D4Field(retainedContextRecordOrIndex16, int*, -44);
    rawWord3 = argumentWord5;
    Options761D4Field(retainedContextRecordOrIndex16, int*, -16) = rawWord2;
    rawWord2 = rawWord2 != 4;
    Options761D4Field(retainedContextRecordOrIndex16, int*, -8) = rawWord2;
loop_42:
    rawWord2 = Options761D4Field(rawWord3, int*, 0);
    if (rawWord2 != scratchWord8)
        goto block_44;
    Options761D4Field(rawWord3, int*, 0) = argumentWord7;
    rawWord2 = Options761D4Field(rawWord3, volatile int*, 0);
block_44:
    if (rawWord2 == argumentWord7)
        goto checkStatusBit;
    Options761D4Field(argumentWord5, int*, 20) = argumentWord4;
    argumentWord6++;
checkStatusBit:
    argumentWord4++;
    rawWord2 = argumentWord4 < 2;
    rawWord3 += 4;
    if (rawWord2)
        goto loop_42;
    rawWord2 = 2;
    if (argumentWord6 != rawWord2) {
        rawWord2 = 1;
        goto block_49;
    }
    rawWord2 = -1;
    Options761D4Data725E0View1 = rawWord2;
    rawWord2 = 4;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_49:
    if (argumentWord6 != rawWord2) {
        rawWord2 = 5;
        goto block_51;
    }
    rawWord2 = 6;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_51:
    rawWord2 = 5;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case4:
    Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) = -1;
    if (Options761D4Call7833CView1() == 0) {
        goto block_55;
    }
block_53:
    if (Options761D4Data6E53CView1 & 0x810) {
        goto block_229;
    }
    goto block_234;
block_55:
    if (!(Options761D4Data6E53CView1 & 0x840)) {
        goto block_235;
    }
    rawWord2 = 6;
    Options761D4Data7AFB4View1 = rawWord2;
    Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) = (int)Options761D4Data7AFB8View1;
    goto returnOriginal;
originalDispatch1Case5:
    Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) = -1;
    if (Options761D4Call7833CView1() != 0) {
        goto block_53;
    }
    if (!(Options761D4Data6E53CView1 & 0x840)) {
        goto returnOriginal;
    }
    goto block_229;
originalDispatch1Case6:
    argumentWord4 = 1;
    MATCHING_OBSERVE_VOLATILE(argumentWord4);
    retainedContextRecordOrIndex16 = (int)&Options761D4Data725B0View1;
    if (Options761D4Call794B4View1(argumentWord4, retainedContextRecordOrIndex16,
                                   retainedContextRecordOrIndex16 + 4) == 0) {
        goto returnOriginal;
    }
    retainedModePointerOrIndex17 = (int)&Options761D4Data7AFB6View1;
    MATCHING_KEEP(retainedModePointerOrIndex17);
    rawWord3 = Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0);
    if (!rawWord3) {
        goto block_64;
    }
    if (rawWord3 == 1) {
        goto block_68;
    }
    goto returnOriginal;
block_64:
    argumentWord4 = Options761D4Data725E0View1;
    retainedOriginalRecordBase = retainedContextRecordOrIndex16;
    MATCHING_KEEP_VOLATILE(retainedOriginalRecordBase);
    indexedRecordAddress = retainedOriginalRecordBase + argumentWord4 * 4;
    rawWord2 = Options761D4Field(indexedRecordAddress, int*, 36);
    MATCHING_OBSERVE_VOLATILE(retainedOriginalRecordBase);
    temporaryWord4 = argumentWord4 * 16;
    if (!rawWord2) {
        goto block_69;
    }
    temporaryWord5 = (int)&Options761D4Data7AFDCView1;
    MATCHING_KEEP_VOLATILE(rawWord3);
    temporaryWord6 = 0;
block_66:
    Options761D4Call79004View1(temporaryWord4, Options761D4Data7ABE4View1, temporaryWord5,
                               temporaryWord6, 7552);
writeOriginalSharedReturnState:
    rawWord2 = Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0);
    rawWord2++;
    Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
block_68:
    argumentWord5 = Options761D4Field(retainedContextRecordOrIndex16, int*, 4);
    if (argumentWord5 != 5) {
        goto block_70;
    }
block_69:
    rawWord2 = 7;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_70:
    if (argumentWord5 != 0) {
        goto block_82;
    }
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1) !=
        Options761D4Data7BB58View1) {
        goto block_74;
    }
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1 + 0x900) !=
        Options761D4Data7C458View1) {
        goto block_74;
    }
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1 + 0x1200) ==
        Options761D4Data7CD58View1) {
        goto block_140;
    }
block_74:
    argumentWord4 = (int)&Options761D4Data7AFBAView1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    if ((unsigned)rawWord3 >= 3)
        goto block_76;
    rawWord2 = rawWord3 + 1;
    Options761D4Data7AFB6View1 = 0;
    Options761D4Field(argumentWord4, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
block_76:
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1) ==
        Options761D4Data7BB58View1) {
        goto block_78;
    }
    Options761D4Data7B260View1 = 0;
    Options761D4Call778C8View1((int)&Options761D4Data7B25CView1, 1);
block_78:
    retainedModePointerOrIndex17 = (int)&Options761D4Data7B25CView1 + 0x900;
    if (Options761D4Call778A0View1(retainedModePointerOrIndex17) == Options761D4Data7C458View1) {
        goto block_80;
    }
    Options761D4Data7BB60View1 = 0;
    Options761D4Call778C8View1(retainedModePointerOrIndex17, 1);
block_80:
    retainedContextRecordOrIndex16 = (int)&Options761D4Data7B25CView1 + 0x1200;
    if (Options761D4Call778A0View1(retainedContextRecordOrIndex16) == Options761D4Data7CD58View1) {
        goto block_139;
    }
    Options761D4Data7C460View1 = 0;
    Options761D4Call778C8View1(retainedContextRecordOrIndex16, 1);
    goto block_140;
block_82:
    rawWord3 = Options761D4Data7AFBAView1;
    if ((unsigned)rawWord3 >= 3) {
        rawWord2 = rawWord3 + 1;
        goto block_137;
    }
    rawWord2 = rawWord3 + 1;
block_83:
    Options761D4Data7AFBAView1 = rawWord2;
    Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0) = 0;
    goto returnOriginal;
originalDispatch1Case7:
    if (Options761D4Call7833CView1() != 0) {
        goto block_53;
    }
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0xA000;
        goto block_236;
    }
    rawWord2 = rawWord3 & 0xA000;
    if (Options761D4Data7AFB8View1 != 0) {
        goto block_229;
    }
    if (Options761D4Field((int)&Options761D4Data725D4View1, int*,
                          (Options761D4Field((int)&Options761D4Data725E0View1, int*, 0)) * 4) !=
        0) {
        goto block_108;
    }
    rawWord2 = 8;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case8:
    if (Options761D4Call7833CView1() != 0) {
        goto block_53;
    }
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0xA000;
        goto block_236;
    }
    rawWord2 = rawWord3 & 0xA000;
    if (Options761D4Data7AFB8View1 == 0) {
        goto block_228;
    }
    rawWord2 = 9;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case9:
    retainedModePointerOrIndex17 = (int)&Options761D4Data7AFB6View1;
    MATCHING_KEEP(retainedModePointerOrIndex17);
    rawWord3 = Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0);
    retainedContextBase18 = 1;
    MATCHING_KEEP(retainedContextBase18);
    if (rawWord3 == retainedContextBase18) {
        goto block_101;
    }
    if ((int)rawWord3 >= 2) {
        goto block_97;
    }
    if (!rawWord3) {
        goto block_99;
    }
    goto returnOriginal;
block_97:
    if (rawWord3 == 2) {
        goto block_105;
    }
    goto returnOriginal;
block_99:
    if (Options761D4Call794B4View1(1, (int)&Options761D4Data725B0View1,
                                   (int)&Options761D4Data725B0View1 + 4) == 0) {
        goto returnOriginal;
    }
    goto block_111;
block_101:
    if (Options761D4Call796CCView1(Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) *
                                   0x10) == 0) {
        goto block_104;
    }
    if ((unsigned char)Options761D4Data7AFBAView1 >= 3U) {
        goto block_137;
    }
    Options761D4Data7AFBAView1 += 1;
    goto returnOriginal;
block_104:
    Options761D4Call788C8View1(Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) * 0x10);
    rawWord2 = 2;
    Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
block_105:
    if (Options761D4Call794B4View1(1, (int)&Options761D4Data725B0View1,
                                   (int)&Options761D4Data725B0View1 + 4) == 0) {
        goto returnOriginal;
    }
    if (Options761D4Field((int)&Options761D4Data725B0View1, int*, 4) != 0) {
        goto block_109;
    }
    rawWord2 = Options761D4Data725E0View1;
    rawWord2 *= 4;
    rawWord2 += (int)&Options761D4Data725B0View1 + 28;
    Options761D4Field(rawWord2, int*, 0) = 0;
    rawWord2 = Options761D4Data725E0View1;
    rawWord2 *= 4;
    rawWord2 += (int)&Options761D4Data725B0View1 + 36;
    Options761D4Field(rawWord2, int*, 0) = retainedContextBase18;
block_108:
    rawWord2 = 0xA;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_109:
    if ((unsigned char)Options761D4Data7AFBAView1 >= 3U) {
        goto block_137;
    }
    Options761D4Data7AFBAView1 += 1;
block_111:
    rawWord2 = 1;
    Options761D4Field(retainedModePointerOrIndex17, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
originalDispatch1Case10:
    if (Options761D4Call794B4View1(1, (int)&Options761D4Data725B0View1,
                                   (int)&Options761D4Data725B0View1 + 4) == 0) {
        goto returnOriginal;
    }
    if ((unsigned char)Options761D4Data7AFB6View1 >= 6U) {
        goto returnOriginal;
    }
    switch (Options761D4Data7AFB6View1) {
        case 1:
            goto originalDispatch2Case1;
        case 2:
            goto originalDispatch2Case2;
        case 3:
            goto originalDispatch2Case3;
        case 4:
            goto originalDispatch2Case4;
        case 5:
            goto originalDispatch2Case5;
        case 0:
            goto originalDispatch2Case0;
        default:
            return;
    }
originalDispatch2Case1:
    temporaryWord1 = Options761D4Call795D0View1(
        Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) * 0x10,
        Options761D4Data7ABE4View1, 1);
    Options761D4Data725B4View1 = temporaryWord1;
    if (temporaryWord1 == 0) {
        goto block_158;
    }
    if (temporaryWord1 == 6) {
        goto block_158;
    }
    if (temporaryWord1 != 7) {
        goto block_119;
    }
    rawWord2 = 0x10;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_119:
    argumentWord4 = (int)&Options761D4Data7AFBAView1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    if ((unsigned)rawWord3 >= 3) {
        rawWord2 = rawWord3 + 1;
        goto block_137;
    }
    rawWord2 = rawWord3 + 1;
    Options761D4Field(argumentWord4, unsigned char*, 0) = rawWord2;
    goto block_150;
originalDispatch2Case2:
    Options761D4Call4E790View1((int)&Options761D4Data7AFDCView1, 0, 0x1D80);
    Options761D4Call4E7D4View1((int)&Options761D4Data7AFDCView1, (int)&Options761D4Data7ABE8View1,
                               0x200);
    Options761D4Data7B1DFView1 = 0;
    Options761D4Data7B260View1 = 0;
    Options761D4Data7B1DCView1 = (signed char)Options761D4Data6C694View1;
    Options761D4Data7B1DDView1 = (signed char)Options761D4Data6C698View1;
    Options761D4Data7B1DEView1 = (signed char)Options761D4Data6C76CView1;
    Options761D4Call778C8View1((int)&Options761D4Data7AFDCView1 + 0x280, 1);
    Options761D4Data7BB60View1 = 0;
    Options761D4Call778C8View1((int)&Options761D4Data7AFDCView1 + 0xB80, 1);
    Options761D4Data7C460View1 = 0;
    Options761D4Call778C8View1((int)&Options761D4Data7AFDCView1 + 0x1480, 1);
    Options761D4Call7925CView1(Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) * 0x10,
                               Options761D4Data7ABE4View1, (int)&Options761D4Data7AFDCView1, 0,
                               0x1D80);
    Options761D4Data7AFB6View1 = 3;
    goto returnOriginal;
originalDispatch2Case3:
    rawWord2 = Options761D4Data725B4View1;
    argumentWord7 = 0;
    if (rawWord2)
        goto block_124;
    argumentWord6 = (int)&Options761D4Data7AFDCView1;
    goto block_136;
block_124:
    argumentWord4 = (int)&Options761D4Data7AFBAView1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    if ((unsigned)rawWord3 >= 3) {
        rawWord2 = 17;
        goto block_138;
    }
    rawWord2 = rawWord3 + 1;
block_126:
    Options761D4Field(argumentWord4, unsigned char*, 0) = rawWord2;
    goto block_158;
originalDispatch2Case4:
    if (Options761D4Data725B4View1 != 0) {
        goto block_134;
    }
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1) !=
        Options761D4Data7BB58View1) {
        goto block_132;
    }
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1 + 0x900) !=
        Options761D4Data7C458View1) {
        goto block_132;
    }
    if (Options761D4Call778A0View1((int)&Options761D4Data7B25CView1 + 0x1200) !=
        Options761D4Data7CD58View1) {
        goto block_132;
    }
    Options761D4Call78BD8View1();
    Options761D4Data7AFB6View1 = 5;
    goto returnOriginal;
block_132:
    argumentWord4 = (int)&Options761D4Data7AFBAView1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    if ((unsigned)rawWord3 < 3) {
        rawWord2 = rawWord3 + 1;
        goto block_126;
    }
    rawWord2 = 17;
    goto block_138;
block_134:
    argumentWord4 = (int)&Options761D4Data7AFBAView1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    if ((unsigned)rawWord3 >= 3) {
        rawWord2 = rawWord3 + 1;
        goto block_137;
    }
    rawWord2 = rawWord3 + 1;
    argumentWord6 = (int)&Options761D4Data7AFDCView1;
    argumentWord7 = 0;
    Options761D4Field(argumentWord4, unsigned char*, 0) = rawWord2;
block_136:
    Options761D4Call79004View2(Options761D4Field((int)&Options761D4Data725E0View1, int*, 0) * 16,
                               Options761D4Data7ABE4View1, argumentWord6, argumentWord7, 7552);
    Options761D4Data7AFB6View1 = 4;
    goto returnOriginal;
block_137:
    rawWord2 = 17;
block_138:
    Options761D4Data7AFB4View1 = rawWord2;
    Options761D4Data725B8View1 = 0;
    Options761D4Data725BCView1 = -1;
    Options761D4Data725C0View1 = -1;
    goto returnOriginal;
originalDispatch2Case5:
block_139:
block_140:
    rawWord2 = 0xB;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case11:
    if (Options761D4Call7833CView1() != 0)
        goto block_53;
    completeInitialModeOne = 1;
    MATCHING_OBSERVE_VOLATILE(completeInitialModeOne);
    argumentWord4 = (int)&Options761D4Data7AFB6View1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    MATCHING_KEEP(rawWord3);
    if (rawWord3 == 1)
        goto block_152;
    if (rawWord3 >= 2)
        goto block_146;
    retainedContextRecordOrIndex16 = argumentWord4 + 14;
    if (!rawWord3)
        goto block_148;
    goto returnOriginal;
block_146:
    if (rawWord3 == 2)
        goto block_160;
    goto returnOriginal;
block_148:
    MATCHING_KEEP_VOLATILE(rawWord3);
    retainedContextBase18 = 0;
    retainedModePointerOrIndex17 = 0;
    MATCHING_OBSERVE2_VOLATILE_CLOBBER(retainedContextBase18, retainedModePointerOrIndex17, "$19");
    retainedSignedTerminator19 = argumentWord4 + 38;
loop_149:
    temporaryWord2 =
        Options761D4Call27934View1(Options761D4Field((int)&Options761D4Data7B260View1,
                                                     unsigned char*, (retainedContextBase18) * 1) +
                                   0x3E8);
    Options761D4Field(retainedContextRecordOrIndex16, short*, 0) = temporaryWord2;
    retainedContextBase18 += 0x900;
    Options761D4Field((int)&Options761D4Data7AFC6View1, unsigned char*,
                      (retainedModePointerOrIndex17) * 1) =
        Options761D4Field((((int)(temporaryWord2 << 0x10) >> 0xD) + Options761D4Data6C738View1),
                          unsigned char*, 4);
    temporaryWord3 =
        Options761D4Field(((Options761D4Field(retainedContextRecordOrIndex16, short*, 0) * 8) +
                           Options761D4Data6C738View1),
                          unsigned char*, 2);
    retainedContextRecordOrIndex16 += 8;
    Options761D4Field((int)&Options761D4Data7AFC7View1, unsigned char*,
                      (retainedModePointerOrIndex17) * 1) = temporaryWord3;
    retainedModePointerOrIndex17 += 8;
    if (retainedContextRecordOrIndex16 < retainedSignedTerminator19) {
        goto loop_149;
    }
originalDispatch2Case0:
block_150:
    Options761D4Data7AFB6View1 = 1;
    goto returnOriginal;
block_151:
    rawWord2 = retainedContextRecordOrIndex16;
    Options761D4Data7AFB8View1 = rawWord2;
    Options761D4Data7AFB9View1 = rawWord2;
    rawWord2 = (int)retainedContextRecordOrIndex16 < 3;
    goto block_156;
block_152:
    retainedContextRecordOrIndex16 = 0;
    retainedModePointerOrIndex17 = (int)&Options761D4Data7B25CView1;
loop_153:
    if (Options761D4Call77B58View1(retainedModePointerOrIndex17) < 0) {
        goto block_151;
    }
    retainedContextRecordOrIndex16 += 1;
    retainedModePointerOrIndex17 += 0x900;
    if ((int)retainedContextRecordOrIndex16 < 3) {
        goto loop_153;
    }
    MATCHING_KEEP_VOLATILE(retainedContextRecordOrIndex16);
    rawWord2 = retainedContextRecordOrIndex16 < 3;
block_156:
    if (rawWord2 != 0) {
        goto block_159;
    }
    Options761D4Data7AFB8View1 = 0;
    Options761D4Data7AFB9View1 = 0;
block_158:
block_159:
    Options761D4Data7AFB6View1 = 2;
    goto returnOriginal;
block_160:
    if (!(Options761D4Data6E53CView1 & 0x840)) {
        goto block_163;
    }
    Options761D4Data725BCView1 = Options761D4Field((int)&Options761D4Data725E0View1, int*, 0);
    Options761D4Data725E4View1 = (int)Options761D4Data7AFB8View1;
    Options761D4Data725C0View1 = (int)Options761D4Data7AFB8View1;
    if (Options761D4Call77B58View1((Options761D4Data7AFB8View1 * 0x900) +
                                   (int)&Options761D4Data7B25CView1) < 0) {
        goto block_172;
    }
    rawWord2 = 0xC;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_163:
    if (!(Options761D4Data6E53CView1 & 0x2000)) {
        goto block_166;
    }
    if ((unsigned char)Options761D4Data7AFB8View1 >= 2U) {
        goto block_166;
    }
    Options761D4Data7AFB8View1 += 1;
block_166:
    if (!(Options761D4Data6E53CView1 & 0x8000)) {
        goto returnOriginal;
    }
    rawWord3 = (int)&Options761D4Data7AFB8View1;
    rawWord2 = Options761D4Field(rawWord3, unsigned char*, 0);
    if (!rawWord2)
        goto returnOriginal;
    rawWord2--;
    Options761D4Field(rawWord3, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
originalDispatch1Case12:
    if (Options761D4Call7833CView1() != 0) {
        goto block_53;
    }
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0xA000;
        goto block_236;
    }
    rawWord2 = rawWord3 & 0xA000;
    if (Options761D4Data7AFB8View1 == 0) {
        goto block_229;
    }
block_172:
    rawWord2 = 0xD;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case13:
    if (Options761D4Call7833CView1() != 0) {
        goto block_53;
    }
    if (Options761D4Data7AFB6View1 == 0) {
        goto block_177;
    }
    if (Options761D4Data7AFB6View1 == 1) {
        goto block_189;
    }
    goto returnOriginal;
block_177:
    retainedModePointerOrIndex17 = -1;
    MATCHING_KEEP_VOLATILE(retainedModePointerOrIndex17);
    retainedContextRecordOrIndex16 = -1;
    retainedModePointerOrIndex17++;
loop_178:
    rawWord2 = Options761D4Call27934View1(retainedModePointerOrIndex17 + 1001);
    rawWord3 = Options761D4Data6C738View1;
    rawWord2 *= 8;
    rawWord2 += rawWord3;
    rawWord2 = Options761D4Field(rawWord2, short*, 0);
    retainedModePointerOrIndex17++;
    if (rawWord2 != retainedContextRecordOrIndex16)
        goto loop_178;
    retainedModePointerOrIndex17--;
    retainedContextRecordOrIndex16 = 1;
    argumentWord7 = (int)&Options761D4Data725E4View1;
    rawWord2 = retainedModePointerOrIndex17 < retainedContextRecordOrIndex16;
loop_180:
    argumentWord6 = 1;
    if (!rawWord2)
        goto block_182;
    retainedContextRecordOrIndex16 = 1;
block_182:
    rawWord3 = 0;
    argumentWord5 = Options761D4Field(argumentWord7, int*, 0);
    argumentWord4 = 0;
loop_183:
    if (rawWord3 == argumentWord5)
        goto block_186;
    rawWord2 = Options761D4Field((int)&Options761D4Data7B260View1, unsigned char*, argumentWord4);
    if (rawWord2 != retainedContextRecordOrIndex16)
        goto block_186;
    retainedContextRecordOrIndex16++;
    argumentWord6 = 0;
    goto block_187;
block_186:
    rawWord3++;
    rawWord2 = rawWord3 < 3;
    argumentWord4 += 2304;
    if (rawWord2)
        goto loop_183;
block_187:
    rawWord2 = retainedModePointerOrIndex17 < retainedContextRecordOrIndex16;
    if (!argumentWord6)
        goto loop_180;
    rawWord2 = Options761D4Call27934View1(retainedContextRecordOrIndex16 + 1000);
    Options761D4Data7AFC4View1 = rawWord2;
    rawWord3 = Options761D4Data6C738View1;
    rawWord2 = (rawWord2 << 16) >> 13;
    rawWord2 += rawWord3;
    rawWord3 = Options761D4Field(rawWord2, unsigned char*, 4);
    Options761D4Data7AFC6View1 = rawWord3;
    rawWord3 = Options761D4Data7AFB6View1;
    rawWord2 = Options761D4Field(rawWord2, unsigned char*, 2);
    Options761D4Data7AFB8View1 = retainedContextRecordOrIndex16;
    Options761D4Data7AFB9View1 = retainedContextRecordOrIndex16;
    rawWord3++;
    Options761D4Data7AFB6View1 = rawWord3;
    Options761D4Data7AFC7View1 = rawWord2;
    goto returnOriginal;
block_189:
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0x2000;
        goto block_191;
    }
    rawWord2 = rawWord3 & 0x2000;
    rawWord3 = Options761D4Data725E4View1;
    rawWord2 = rawWord3 * 2304;
    rawWord3 = Options761D4Data7AFB8View1;
    Options761D4Field((int)&Options761D4Data7B260View1, unsigned char*, rawWord2) = rawWord3;
    rawWord2 = 14;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_191:
    retainedContextRecordOrIndex16 = -1;
    if (!rawWord2)
        goto block_204;
    MATCHING_KEEP_VOLATILE(retainedContextRecordOrIndex16);
    retainedModePointerOrIndex17 = -1;
    retainedContextRecordOrIndex16++;
loop_193:
    rawWord2 = Options761D4Call27934View1(retainedContextRecordOrIndex16 + 1001);
    rawWord3 = Options761D4Data6C738View1;
    rawWord2 *= 8;
    rawWord2 += rawWord3;
    rawWord2 = Options761D4Field(rawWord2, short*, 0);
    retainedContextRecordOrIndex16++;
    if (rawWord2 != retainedModePointerOrIndex17)
        goto loop_193;
    retainedContextRecordOrIndex16--;
    rawWord2 = Options761D4Data7AFB8View1;
    scratchWord8 = (int)&Options761D4Data725E4View1;
    argumentWord5 = rawWord2 + 1;
    rawWord2 = retainedContextRecordOrIndex16 < argumentWord5;
loop_195:
    argumentWord7 = 1;
    if (!rawWord2)
        goto block_197;
    argumentWord5 = 1;
block_197:
    rawWord3 = 0;
    argumentWord6 = Options761D4Field(scratchWord8, int*, 0);
    argumentWord4 = 0;
loop_198:
    if (rawWord3 == argumentWord6)
        goto block_201;
    rawWord2 = Options761D4Field((int)&Options761D4Data7B260View1, unsigned char*, argumentWord4);
    if (rawWord2 != argumentWord5)
        goto block_201;
    argumentWord5++;
    argumentWord7 = 0;
    goto block_202;
block_201:
    rawWord3++;
    rawWord2 = rawWord3 < 3;
    argumentWord4 += 2304;
    if (rawWord2)
        goto loop_198;
block_202:
    rawWord2 = retainedContextRecordOrIndex16 < argumentWord5;
    if (!argumentWord7)
        goto loop_195;
    goto block_216;
block_204:
    MATCHING_KEEP_VOLATILE_CLOBBER(retainedContextRecordOrIndex16, "$2");
    rawWord2 = rawWord3 & 0x8000;
    retainedModePointerOrIndex17 = -1;
    if (!rawWord2)
        goto returnOriginal;
    retainedContextRecordOrIndex16++;
loop_206:
    rawWord2 = Options761D4Call27934View1(retainedContextRecordOrIndex16 + 1001);
    rawWord3 = Options761D4Data6C738View1;
    rawWord2 *= 8;
    rawWord2 += rawWord3;
    rawWord2 = Options761D4Field(rawWord2, short*, 0);
    retainedContextRecordOrIndex16++;
    if (rawWord2 != retainedModePointerOrIndex17)
        goto loop_206;
    retainedContextRecordOrIndex16--;
    rawWord2 = Options761D4Data7AFB8View1;
    scratchWord8 = (int)&Options761D4Data725E4View1;
    argumentWord5 = rawWord2 - 1;
loop_208:
    argumentWord7 = 1;
    if (argumentWord5 > 0)
        goto block_210;
    argumentWord5 = retainedContextRecordOrIndex16;
block_210:
    rawWord3 = 0;
    argumentWord6 = Options761D4Field(scratchWord8, int*, 0);
    argumentWord4 = 0;
loop_211:
    if (rawWord3 == argumentWord6)
        goto block_214;
    rawWord2 = Options761D4Field((int)&Options761D4Data7B260View1, unsigned char*, argumentWord4);
    if (rawWord2 != argumentWord5)
        goto block_214;
    argumentWord5--;
    argumentWord7 = 0;
    goto block_215;
block_214:
    rawWord3++;
    rawWord2 = rawWord3 < 3;
    argumentWord4 += 2304;
    if (rawWord2)
        goto loop_211;
block_215:
    if (!argumentWord7)
        goto loop_208;
block_216:
    Options761D4Data7AFB8View1 = argumentWord5;
    rawWord2 = Options761D4Call27934View1(argumentWord5 + 1000);
    Options761D4Data7AFC4View1 = rawWord2;
    rawWord3 = Options761D4Data6C738View1;
    rawWord2 = (rawWord2 << 16) >> 13;
    rawWord2 += rawWord3;
    rawWord3 = Options761D4Field(rawWord2, unsigned char*, 4);
    Options761D4Data7AFC6View1 = rawWord3;
    rawWord2 = Options761D4Field(rawWord2, unsigned char*, 2);
    Options761D4Data7AFC7View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case14:
    argumentWord4 = Options761D4Call77C94View1();
    rawWord2 = -1;
    if (argumentWord4 != rawWord2) {
        rawWord2 = 1;
        goto block_219;
    }
    rawWord2 = 17;
    Options761D4Data7AFB4View1 = rawWord2;
    Options761D4Data725B8View1 = 0;
    Options761D4Data725BCView1 = argumentWord4;
    Options761D4Data725C0View1 = argumentWord4;
    goto returnOriginal;
block_219:
    if (argumentWord4 != rawWord2)
        goto returnOriginal;
    rawWord2 = Options761D4Data725E0View1;
    rawWord3 = Options761D4Data725E4View1;
    Options761D4Data725B8View1 = argumentWord4;
    Options761D4Data725BCView1 = rawWord2;
    rawWord2 = rawWord3 * 2304;
    Options761D4Data725C0View1 = rawWord3;
    rawWord3 = Options761D4Field((int)&Options761D4Data7B25CView1, int*, rawWord2);
    rawWord2 = 19;
    Options761D4Data7AFB4View1 = rawWord2;
    Options761D4Data725C4View1 = rawWord3;
    goto returnOriginal;
originalDispatch1Case15:
    if (Options761D4Call7833CView1() != 0) {
        goto block_53;
    }
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0xA000;
        goto block_236;
    }
    rawWord2 = rawWord3 & 0xA000;
    if (Options761D4Data7AFB8View1 != 0) {
        goto block_234;
    }
    rawWord3 = Options761D4Data725BCView1;
    argumentWord4 = Options761D4Data725C0View1;
    rawWord2 = 1;
    Options761D4Data725B8View1 = rawWord2;
    rawWord2 = 14;
    Options761D4Data7AFB4View1 = rawWord2;
    Options761D4Data725E0View1 = rawWord3;
    Options761D4Data725E4View1 = argumentWord4;
    goto returnOriginal;
originalDispatch1Case16:
originalDispatch1Case17:
    if (!(Options761D4Data6E53CView1 & 0x850)) {
        goto returnOriginal;
    }
    rawWord2 = 0x12;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
originalDispatch1Case18:
    Options761D4Data725C8View1 = 0;
    if (!(Options761D4Data6E53CView1 & 0x810)) {
        goto block_230;
    }
block_228:
block_229:
    rawWord2 = 1;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_230:
    rawWord3 = Options761D4Data6E53CView1;
    rawWord2 = rawWord3 & 0x840;
    if (!rawWord2) {
        rawWord2 = rawWord3 & 0xA000;
        goto block_236;
    }
    rawWord2 = rawWord3 & 0xA000;
    if (Options761D4Data7AFB8View1 == 0) {
        goto block_233;
    }
block_232:
    rawWord2 = 0x13;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_233:
block_234:
    rawWord2 = 3;
    Options761D4Data7AFB4View1 = rawWord2;
    goto returnOriginal;
block_235:
    rawWord2 = Options761D4Data6E53CView1 & 0xA000;
block_236:
    if (rawWord2 == 0) {
        goto returnOriginal;
    }
    argumentWord4 = (int)&Options761D4Data7AFB8View1;
    rawWord3 = Options761D4Field(argumentWord4, unsigned char*, 0);
    rawWord2 = 1 - rawWord3;
    Options761D4Field(argumentWord4, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
originalDispatch1Case19:
    if (Options761D4Call794B4View1(1, (int)&Options761D4Data725B0View1,
                                   (int)&Options761D4Data725B0View1 + 4) == 0) {
        goto returnOriginal;
    }
    retainedContextRecordOrIndex16 = (int)&Options761D4Data7AFB6View1;
    MATCHING_KEEP(retainedContextRecordOrIndex16);
    rawWord3 = Options761D4Field(retainedContextRecordOrIndex16, unsigned char*, 0);
    if (!rawWord3) {
        goto block_242;
    }
    if (rawWord3 == 1) {
        goto block_243;
    }
    goto returnOriginal;
block_242:
    Options761D4Call78504View1();
    rawWord2 = Options761D4Field(retainedContextRecordOrIndex16, unsigned char*, 0);
    rawWord2++;
    Options761D4Field(retainedContextRecordOrIndex16, unsigned char*, 0) = rawWord2;
    goto returnOriginal;
block_243:
    Options761D4Data6FBCCView1 = rawWord3;
    Options761D4Data7ABE0View1 = 2;
    Options761D4Data6FBC4View1 = 0;
    Options761D4Data6FBD4View1 = 0;
    Options761D4Data6FBD0View1 = 7;
    if (Options761D4Data70148View1 != 2) {
        goto returnOriginal;
    }
    Options761D4Data7014EView1 = 1;
returnOriginal:
    if (Options761D4Data7AFB4View1 == Options761D4Data7AFB5View1) {
        goto block_247;
    }
    Options761D4Data7AFB5View1 = Options761D4Data7AFB4View1;
    Options761D4Data7AFB6View1 = 0;
    Options761D4Data7AFB7View1 = 0;
    Options761D4Data7AFB8View1 = 0;
    Options761D4Data7AFB9View1 = 0;
    Options761D4Data7AFBAView1 = 0;
    Options761D4Data7AFBCView1 = 0;
    return;
block_247:
    if (Options761D4Data7AFB6View1 == Options761D4Data7AFB7View1) {
        goto block_249;
    }
    Options761D4Data7AFB7View1 = Options761D4Data7AFB6View1;
    Options761D4Data7AFBCView1 = 0;
    Options761D4Data7AFB9View1 = Options761D4Data7AFB8View1;
    return;
block_249:
    if (Options761D4Data7AFB8View1 == Options761D4Data7AFB9View1) {
        goto block_251;
    }
    Options761D4Data7AFB9View1 = Options761D4Data7AFB8View1;
    Options761D4Data7AFBCView1 = 0;
    return;
block_251:
    Options761D4Data7AFBCView1 += Options761D4Data6C648View1;
    return;
}
#undef Options761D4Field

extern int D_options_8007ABE0;
extern int D_8006FBD0, D_80070148, D_8006FBC8, D_8006FBD4;
extern unsigned char D_options_8007AFB4;
void func_options_800761D4(void);
void func_options_80075B18(void);
void func_options_800777C8(void) {
    register int* state __asm__("$6") = &D_options_8007ABE0;
    MATCHING_KEEP(state);
    switch (*state) {
        case 0: {
            register int value __asm__("$2") = 8;
            register int* destination __asm__("$4");
            MATCHING_KEEP_CLOBBER(value, "$4");
            destination = &D_8006FBD0;
            *destination = value;
            *state = 1;
            MATCHING_OBSERVE(destination);
            if (D_80070148 == 2) {
                *destination = 11;
                D_options_8007AFB4 = 0;
            }
            break;
        }
        case 2:
            D_8006FBC8 = 24;
            D_8006FBD4 = 0;
            break;
        case 1:
            if (D_8006FBD0 == 11)
                func_options_800761D4();
            else
                func_options_80075B18();
            break;
    }
}
