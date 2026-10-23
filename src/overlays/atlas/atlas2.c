#include "matching.h"
#include "common.h"

extern unsigned char DecodedAtlasTileIndices[] __asm__("D_atlas_8007AE10");
extern unsigned char DecodedAtlasTileFlags[] __asm__("D_atlas_8007AE11");
extern unsigned char* DecodedAtlasTileSprites __asm__("D_80070108");
void DecodedAtlasDrawTile(unsigned char*, int, int, int) __asm__("func_80028D30");
/* USA SCUS-94467 Rev 0, 0x800781FC..0x8007839C, 104 words.
 * Seven rows of six two-byte slots, with an 84-byte entry stride. Slot FF
 * skips drawing; byte1 is XORed with the incoming flags. Sprite records
 * retain the original eight-byte stride and byte coordinate differences.
 * Empty constraints retain register lifetimes, fresh reads and scheduling;
 * none emit instructions. Caller cadence/table producers remain unresolved.
 * Raw draw coordinates gain no new physical units or scale conversion.
 * AI generated; not yet human reviewed.
 */
void func_atlas_800781FC(int xArgument, int yArgument, int entryArgument, int flagsArgument) {
    volatile int originX = xArgument;
    int flags = flagsArgument;
    int entry;
    register int spriteOffset __asm__("$16");
    register int x __asm__("$17");
    register int columnOffset __asm__("$18");
    register int column __asm__("$19");
    register int mirrored __asm__("$20");
    register int rowOffset __asm__("$21");
    register int y __asm__("$22");
    register int entryOffset __asm__("$23");
    int row;
    register int temporary __asm__("$2");
    MATCHING_KEEP(flags);
    y = yArgument + 7;
    MATCHING_KEEP(y);
    row = 0;
    MATCHING_KEEP(row);
    temporary = entryArgument * 20;
    __asm__("" : "=r"(temporary) : "0"(temporary), "r"(flags), "r"(row));
    entry = temporary + entryArgument;
    rowOffset = 0;
    do {
        x = originX;
        column = 0;
        entryOffset = entry * 4;
        mirrored = flags & 1;
        columnOffset = rowOffset;
        do {
            register int index __asm__("$5");
            register int tileFlags __asm__("$7");
            register int limit __asm__("$3");
            temporary = columnOffset + entryOffset;
            __asm__("" : "=r"(temporary) : "0"(temporary), "r"(flags), "r"(row));
            limit = 255;
            __asm__("" : "=r"(limit) : "0"(limit), "r"(temporary));
            index = DecodedAtlasTileIndices[temporary];
            tileFlags = DecodedAtlasTileFlags[temporary];
            MATCHING_KEEP(index);
            MATCHING_KEEP(tileFlags);
            if (index != limit) {
                if (mirrored) {
                    register unsigned char* sprite __asm__("$2");
                    register int width __asm__("$3");
                    register int left __asm__("$4");
                    temporary = index * 8;
                    __asm__("" : "=r"(temporary) : "0"(temporary), "r"(flags), "r"(row));
                    width = (int)DecodedAtlasTileSprites;
                    sprite = (unsigned char*)(temporary + width);
                    width = sprite[4];
                    left = x - 1;
                    width -= sprite[0];
                    x = left - width;
                }
                spriteOffset = index * 8;
                {
                    register int drawX __asm__("$5") = x;
                    register int drawY __asm__("$6") = y;
                    register unsigned char* drawBase __asm__("$4");
                    MATCHING_KEEP(drawX);
                    MATCHING_KEEP(drawY);
                    drawBase = DecodedAtlasTileSprites;
                    MATCHING_BARRIER("memory");
                    DecodedAtlasDrawTile(drawBase + spriteOffset, drawX, drawY, tileFlags ^ flags);
                }
                MATCHING_OBSERVE3(row, flags, entry);
                {
                    register int right __asm__("$4") = x + 1;
                    if (!mirrored) {
                        register unsigned char* sprite __asm__("$2");
                        register int width __asm__("$3");
                        temporary = (int)DecodedAtlasTileSprites;
                        __asm__("" : "=r"(temporary) : "0"(temporary), "r"(flags), "r"(row));
                        sprite = (unsigned char*)(spriteOffset + temporary);
                        width = sprite[4];
                        width -= sprite[0];
                        x = right + width;
                    }
                }
            }
            column++;
            columnOffset += 2;
        } while (column != 6);
        {
            register unsigned char* sprite __asm__("$2");
            register int height __asm__("$3");
            register int bottom __asm__("$4");
            temporary = entry * 4;
            __asm__("" : "=r"(temporary) : "0"(temporary), "r"(flags), "r"(row));
            temporary = rowOffset + temporary;
            __asm__("" : "=r"(temporary) : "0"(temporary), "r"(flags), "r"(row));
            rowOffset += 12;
            row++;
            temporary = DecodedAtlasTileIndices[temporary];
            height = (int)DecodedAtlasTileSprites;
            temporary *= 8;
            sprite = (unsigned char*)(temporary + height);
            height = sprite[5];
            bottom = y + 1;
            height -= sprite[1];
            y = bottom + height;
        }
    } while (row != 7);
}

// This had to be added manually because splat didn't see most of it, maybe there's more file splittings / a different split??
INCLUDE_RODATA("asm/nonmatchings/overlays/atlas/atlas2", D_atlas_800757B8);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
extern volatile unsigned short Atlas_7839C_HalfAE0C __asm__("D_atlas_8007AE0C");
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/atlas/atlas2/func_atlas_8007839C.s SHA256 4fa87596a0264bd49542f77c2a10a6e76fd4ad643be07ec4a3ad51796a6a34ef. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
typedef int (*Atlas_7839C_Callback)(void*, int, int, int);
#define Atlas_7839C_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Atlas_7839CEmitScreenColorQuad() __asm__("func_800200A0");
/* extern */
int Atlas_7839CRemapPrimitiveListScreenCoordinates() __asm__("func_80030258");
/* extern */
int Atlas_7839C_func_atlas_80077EB8() __asm__("func_atlas_80077EB8");
/* extern */
int Atlas_7839C_func_atlas_80077F50() __asm__("func_atlas_80077F50");
/* extern */
int Atlas_7839C_func_atlas_800781FC() __asm__("func_atlas_800781FC");
/* extern */
extern int Atlas_7839C_D_8006C598 __asm__("D_8006C598");
extern int Atlas_7839C_D_8006C664 __asm__("D_8006C664");
extern int Atlas_7839C_D_8006FBC4 __asm__("D_8006FBC4");
extern int Atlas_7839C_D_8006FBF8 __asm__("D_8006FBF8");
extern unsigned int Atlas_7839C_D_atlas_8007ADE0 __asm__("D_atlas_8007ADE0");
extern short Atlas_7839C_D_atlas_8007ADE4 __asm__("D_atlas_8007ADE4");
extern short Atlas_7839C_D_atlas_8007ADE6 __asm__("D_atlas_8007ADE6");
extern short Atlas_7839C_D_atlas_8007ADE8 __asm__("D_atlas_8007ADE8");
extern short Atlas_7839C_D_atlas_8007ADEA __asm__("D_atlas_8007ADEA");
extern unsigned char Atlas_7839C_D_atlas_8007AE0C __asm__("D_atlas_8007AE0C");
extern unsigned char Atlas_7839C_D_atlas_8007AF10 __asm__("D_atlas_8007AF10");
void func_atlas_8007839C(void) {
    /* SCUS-94467 USA Rev0 8007839C; original source and SHA256 above.
    * 472 instructions, nine dispatch entries at800757D8 and a zero padding
    * word at800757FC. Original32-byte frame: saved16/SP10,17/SP14,RA/SP18.
    * Callback entries are WORD pointers with byte24 record strides.
    * NEXT paths retain signed LH5, original +1 in3, separate scale2 and
    * current-index scale4; callback data bases add BYTES to selected fields.
    * Full signed LH6 values are passed without a short parameter narrowing.
    * The callback type projects original caller registers4/5/6/7 only;
    * its complete callee contract and data meaning remain unresolved.
    * Selected16/17 field pointers retain original case-specific lifetimes.
    * AE0C updates retain unsigned LHU, original +/-1, lower-halfword SH,
    * and the exact selector/delta/store order. Memory boundaries do not
    * prematurely consume fresh load results, preserving original load-delay
    * fillers. Every value observation consumes an initialized producer;
    * dead2/5/6 boundaries precede their identified original replacements.
    * The shared callback and30258 call remain at their original case tails.
    * No nonempty CPU instruction assembly or opcode patching is added.
    * Compiler/flags and all acceptance gates remain unchanged; the separately
    * authorized filter fix retains the original .rodata.jtbl section.
    * Confidence requires exact native/linked words, all conditional/internal
    * jump targets, owned table/padding data and full EXE/every-overlay hashes.
    * Cadence is per invocation. Physical units/fixed point, helper/asset/SFX
    * chains, frame frequency and synchronized runtime verification remain
    * unresolved. No browser or subsystem completion claim.
    * AI generated; not human reviewed. */
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int callbackByteAddress4 __asm__("$4");
    register int callbackArgument5 __asm__("$5");
    register int callbackSigned6 __asm__("$6");
    register short* selectedHalf16 __asm__("$16");
    register short* selectedHalf17 __asm__("$17");
    register Atlas_7839C_Callback nextCallbackA3 __asm__("$3");
    register Atlas_7839C_Callback nextCallbackB3 __asm__("$3");
    register Atlas_7839C_Callback currentCallbackB3 __asm__("$3");
    register Atlas_7839C_Callback nextCallbackC3 __asm__("$3");
    register Atlas_7839C_Callback currentCallbackC3 __asm__("$3");
    register Atlas_7839C_Callback nextCallbackD3 __asm__("$3");
    register Atlas_7839C_Callback nextCallbackE3 __asm__("$3");
    register Atlas_7839C_Callback currentCallbackE3 __asm__("$3");
    register Atlas_7839C_Callback currentCallbackF3 __asm__("$3");
    register Atlas_7839C_Callback sharedCallback3 __asm__("$3");
    register int sharedArgument5 __asm__("$5");
    register int sharedSigned6 __asm__("$6");
    int recordOffsetA2;
    int recordOffsetB2;
    int recordOffsetC2;
    int recordOffsetD2;
    int recordOffsetE2;
    int recordOffsetF2;
    int phaseWord16;
    register int phasePredicateA2 __asm__("$2");
    register int phasePredicateB2 __asm__("$2");
    register int phasePredicateC2 __asm__("$2");
    register void* sharedArgument4 __asm__("$4");
    switch (Atlas_7839C_D_atlas_8007ADE0) {
        case 0:
        case 1:
            Atlas_7839C_func_atlas_80077EB8(0x100, 0xC, 0);
            if (Atlas_7839C_D_8006C598 != 0) {
                Atlas_7839CEmitScreenColorQuad(2, Atlas_7839C_D_8006C598, Atlas_7839C_D_8006C598,
                                               Atlas_7839C_D_8006C598);
                return;
            }
        default:
            return;
        case 5:
        case 6:
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 0);
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 1, 0);
            selectedHalf17 = (short*)&Atlas_7839C_D_atlas_8007ADE8;
            MATCHING_KEEP(selectedHalf17);
            callbackArgument5 = (*selectedHalf17);
            MATCHING_KEEP(callbackArgument5);
            rawWord3 = callbackArgument5 + 1;
            MATCHING_KEEP(rawWord3);
            rawWord2 = rawWord3 * 24;
            nextCallbackA3 = *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + rawWord2));
            if (nextCallbackA3 != 0) {
                callbackByteAddress4 = callbackArgument5 * 24;
                rawWord2 = (int)((unsigned char*)selectedHalf17 + 0x13C);
                MATCHING_KEEP2(callbackByteAddress4, rawWord2);
                callbackByteAddress4 += rawWord2;
                callbackArgument5 = 0;
                MATCHING_KEEP(callbackArgument5);
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                nextCallbackA3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6, 0);
            }
            phaseWord16 = (Atlas_7839C_D_8006FBC4 * 4) + 3;
            Atlas_7839C_D_8006FBF8 = Atlas_7839C_D_8006C664;
            if (phaseWord16 >= 0x80) {
                phaseWord16 = 0x7F;
            }
            if (Atlas_7839C_D_atlas_8007ADE0 == 6) {
                phaseWord16 = 0x7F - phaseWord16;
                phasePredicateA2 = phaseWord16 < 0x40;
            } else {
                phasePredicateA2 = phaseWord16 < 0x40;
            }
            if (phasePredicateA2 != 0) {
                Atlas_7839C_func_atlas_80077EB8(0x100, 0xC, 4);
            } else {
                Atlas_7839C_func_atlas_80077F50(0x100, 0xB, 5);
                Atlas_7839C_func_atlas_800781FC(0x100, 0xB, 2, 5);
                recordOffsetA2 = (*selectedHalf17) * 0x18;
                sharedCallback3 =
                    *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + recordOffsetA2));
                phaseWord16 += 0x80;
                if (sharedCallback3 != 0) {
                    callbackByteAddress4 = (int)((unsigned char*)selectedHalf17 + 0x124);
                    MATCHING_KEEP(callbackByteAddress4);
                    sharedArgument4 = (void*)(recordOffsetA2 + callbackByteAddress4);
                    sharedSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                    sharedArgument5 = 1;
                    goto callSharedRecord;
                }
            }
            goto call30258;
        case 2:
        case 7:
        case 8:
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 0);
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 1);
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 1, 0);
            selectedHalf16 = (short*)&Atlas_7839C_D_atlas_8007ADE8;
            MATCHING_KEEP(selectedHalf16);
            callbackArgument5 = (*selectedHalf16);
            MATCHING_KEEP(callbackArgument5);
            rawWord3 = callbackArgument5 + 1;
            MATCHING_KEEP(rawWord3);
            rawWord2 = rawWord3 * 24;
            nextCallbackB3 = *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + rawWord2));
            if (nextCallbackB3 != 0) {
                callbackByteAddress4 = callbackArgument5 * 24;
                rawWord2 = (int)((unsigned char*)selectedHalf16 + 0x13C);
                MATCHING_KEEP2(callbackByteAddress4, rawWord2);
                callbackByteAddress4 += rawWord2;
                callbackArgument5 = 0;
                MATCHING_KEEP(callbackArgument5);
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                nextCallbackB3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6, 0);
            }
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 2, 1);
            recordOffsetB2 = (*selectedHalf16) * 0x18;
            currentCallbackB3 =
                *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + recordOffsetB2));
            if (currentCallbackB3 != 0) {
                callbackByteAddress4 = (int)((unsigned char*)selectedHalf16 + 0x124);
                MATCHING_KEEP(callbackByteAddress4);
                callbackByteAddress4 = recordOffsetB2 + callbackByteAddress4;
                callbackArgument5 = 1;
                MATCHING_KEEP_CLOBBER(callbackArgument5, "$6");
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                currentCallbackB3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6,
                                  0);
                return;
            }
            break;
        case 3:
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 0);
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 1);
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 1, 0);
            selectedHalf17 = (short*)&Atlas_7839C_D_atlas_8007ADEA;
            MATCHING_KEEP(selectedHalf17);
            callbackArgument5 = (*selectedHalf17);
            MATCHING_KEEP(callbackArgument5);
            rawWord3 = callbackArgument5 + 1;
            MATCHING_KEEP(rawWord3);
            rawWord2 = rawWord3 * 24;
            nextCallbackC3 = *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + rawWord2));
            if (nextCallbackC3 != 0) {
                callbackByteAddress4 = callbackArgument5 * 24;
                rawWord2 = (int)((unsigned char*)selectedHalf17 + 0x13A);
                MATCHING_KEEP2(callbackByteAddress4, rawWord2);
                callbackByteAddress4 += rawWord2;
                callbackArgument5 = 0;
                MATCHING_KEEP(callbackArgument5);
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE6;
                nextCallbackC3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6, 0);
            }
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 2, 1);
            Atlas_7839C_HalfAE0C = (unsigned short)(Atlas_7839C_HalfAE0C - 1);
            recordOffsetC2 = Atlas_7839C_D_atlas_8007ADE8 * 0x18;
            currentCallbackC3 =
                *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + recordOffsetC2));
            if (currentCallbackC3 != 0) {
                callbackByteAddress4 = (int)((unsigned char*)selectedHalf17 + 0x122);
                MATCHING_KEEP(callbackByteAddress4);
                callbackByteAddress4 = recordOffsetC2 + callbackByteAddress4;
                callbackArgument5 = 1;
                MATCHING_KEEP_CLOBBER(callbackArgument5, "$6");
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                currentCallbackC3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6,
                                  0);
            }
            rawWord3 = Atlas_7839C_HalfAE0C;
            __asm__("" : : : "$2", "memory");
            rawWord2 = Atlas_7839C_D_8006FBC4;
            callbackByteAddress4 = Atlas_7839C_D_8006C664;
            rawWord3 += 1;
            rawWord2 <<= 2;
            phaseWord16 = rawWord2 + 3;
            phasePredicateB2 = phaseWord16 < 128;
            MATCHING_KEEP_CLOBBER(phasePredicateB2, "memory");
            Atlas_7839C_HalfAE0C = (unsigned short)rawWord3;
            Atlas_7839C_D_8006FBF8 = callbackByteAddress4;
            if (!phasePredicateB2) {
                phaseWord16 = 127;
            }
            if (Atlas_7839C_D_atlas_8007ADE0 == 4) {
                phaseWord16 = 0x7F - phaseWord16;
                phasePredicateB2 = phaseWord16 < 0x40;
            } else {
                phasePredicateB2 = phaseWord16 < 0x40;
            }
            if (phasePredicateB2 != 0) {
                Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 1, 4);
                rawWord2 = Atlas_7839C_HalfAE0C;
                __asm__("" : : : "$5", "memory");
                callbackArgument5 = Atlas_7839C_D_atlas_8007ADE8;
                rawWord2 -= 1;
                MATCHING_KEEP2(callbackArgument5, rawWord2);
                rawWord3 = callbackArgument5 + 1;
                MATCHING_KEEP2_CLOBBER(rawWord3, rawWord2, "memory");
                Atlas_7839C_HalfAE0C = (unsigned short)rawWord2;
                rawWord2 = rawWord3 * 24;
                nextCallbackD3 =
                    *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + rawWord2));
                if (nextCallbackD3 != 0) {
                    callbackByteAddress4 = callbackArgument5 * 24;
                    rawWord2 = (int)((unsigned char*)selectedHalf17 + 0x13A);
                    MATCHING_KEEP2(callbackByteAddress4, rawWord2);
                    callbackByteAddress4 += rawWord2;
                    callbackArgument5 = 0;
                    MATCHING_KEEP(callbackArgument5);
                    callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                    nextCallbackD3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6,
                                   4);
                }
                Atlas_7839C_HalfAE0C = (unsigned short)(Atlas_7839C_HalfAE0C + 1);
            } else {
                Atlas_7839C_func_atlas_800781FC(0x100, 0xB, 2, 5);
                recordOffsetD2 = (*selectedHalf17) * 0x18;
                sharedCallback3 =
                    *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + recordOffsetD2));
                phaseWord16 += 0x80;
                if (sharedCallback3 != 0) {
                    callbackByteAddress4 = (int)((unsigned char*)selectedHalf17 + 0x122);
                    MATCHING_KEEP(callbackByteAddress4);
                    sharedArgument4 = (void*)(recordOffsetD2 + callbackByteAddress4);
                    sharedArgument5 = 1;
                loadSharedSigned6:
                    sharedSigned6 = Atlas_7839C_D_atlas_8007ADE6;
                callSharedRecord:
                    sharedCallback3(sharedArgument4, sharedArgument5, sharedSigned6, 4);
                }
            }
            goto call30258;
        case 4:
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 0);
            Atlas_7839C_func_atlas_80077F50(0x100, 0xC, 1);
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 1, 0);
            selectedHalf17 = (short*)&Atlas_7839C_D_atlas_8007AE0C;
            MATCHING_KEEP(selectedHalf17);
            rawWord2 = Atlas_7839C_Field((unsigned char*)selectedHalf17, unsigned short*, 0);
            __asm__("" : : : "$5", "memory");
            callbackArgument5 = Atlas_7839C_Field((unsigned char*)selectedHalf17, short*, -0x24);
            rawWord2 += 1;
            MATCHING_KEEP2(callbackArgument5, rawWord2);
            rawWord3 = callbackArgument5 + 1;
            MATCHING_KEEP2_CLOBBER(rawWord3, rawWord2, "memory");
            Atlas_7839C_Field((unsigned char*)selectedHalf17, unsigned short*, 0) =
                (unsigned short)rawWord2;
            rawWord2 = rawWord3 * 24;
            nextCallbackE3 = *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + rawWord2));
            if (nextCallbackE3 != 0) {
                callbackByteAddress4 = callbackArgument5 * 24;
                rawWord2 = (int)((unsigned char*)selectedHalf17 + 0x118);
                MATCHING_KEEP2(callbackByteAddress4, rawWord2);
                callbackByteAddress4 += rawWord2;
                callbackArgument5 = 0;
                MATCHING_KEEP(callbackArgument5);
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                nextCallbackE3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6, 0);
            }
            Atlas_7839C_Field((unsigned char*)selectedHalf17, unsigned short*, 0) =
                (unsigned short)(Atlas_7839C_Field((unsigned char*)selectedHalf17, unsigned short*,
                                                   0) -
                                 1);
            Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 2, 1);
            recordOffsetE2 = Atlas_7839C_D_atlas_8007ADEA * 0x18;
            currentCallbackE3 =
                *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + recordOffsetE2));
            if (currentCallbackE3 != 0) {
                callbackByteAddress4 = (int)((unsigned char*)selectedHalf17 + 0x100);
                MATCHING_KEEP(callbackByteAddress4);
                callbackByteAddress4 = recordOffsetE2 + callbackByteAddress4;
                callbackArgument5 = 1;
                MATCHING_KEEP_CLOBBER(callbackArgument5, "$6");
                callbackSigned6 = Atlas_7839C_D_atlas_8007ADE6;
                currentCallbackE3((void*)callbackByteAddress4, callbackArgument5, callbackSigned6,
                                  0);
            }
            phaseWord16 = (Atlas_7839C_D_8006FBC4 * 4) + 3;
            Atlas_7839C_D_8006FBF8 = Atlas_7839C_D_8006C664;
            if (phaseWord16 >= 0x80) {
                phaseWord16 = 0x7F;
            }
            if (Atlas_7839C_D_atlas_8007ADE0 == 4) {
                phaseWord16 = 0x7F - phaseWord16;
                phasePredicateC2 = phaseWord16 < 0x40;
            } else {
                phasePredicateC2 = phaseWord16 < 0x40;
            }
            if (phasePredicateC2 != 0) {
                Atlas_7839C_func_atlas_800781FC(0x100, 0xC, 1, 4);
                callbackArgument5 = Atlas_7839C_D_atlas_8007ADEA;
                MATCHING_KEEP(callbackArgument5);
                rawWord3 = callbackArgument5 + 1;
                MATCHING_KEEP(rawWord3);
                rawWord2 = rawWord3 * 24;
                sharedCallback3 =
                    *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + rawWord2));
                if (sharedCallback3 != 0) {
                    callbackByteAddress4 = callbackArgument5 * 24;
                    rawWord2 = (int)((unsigned char*)selectedHalf17 + 0x118);
                    MATCHING_KEEP2(callbackByteAddress4, rawWord2);
                    callbackByteAddress4 += rawWord2;
                    sharedArgument4 = (void*)callbackByteAddress4;
                    sharedArgument5 = 0;
                    goto loadSharedSigned6;
                }
            } else {
                Atlas_7839C_func_atlas_800781FC(0x100, 0xB, 2, 5);
                Atlas_7839C_Field((unsigned char*)selectedHalf17, unsigned short*, 0) =
                    (unsigned short)(Atlas_7839C_Field((unsigned char*)selectedHalf17,
                                                       unsigned short*, 0) +
                                     1);
                recordOffsetF2 =
                    Atlas_7839C_Field((unsigned char*)selectedHalf17, short*, -0x24) * 0x18;
                currentCallbackF3 =
                    *((Atlas_7839C_Callback*)(&Atlas_7839C_D_atlas_8007AF10 + recordOffsetF2));
                phaseWord16 += 0x80;
                if (currentCallbackF3 != 0) {
                    callbackByteAddress4 = (int)((unsigned char*)selectedHalf17 + 0x100);
                    MATCHING_KEEP(callbackByteAddress4);
                    callbackByteAddress4 = recordOffsetF2 + callbackByteAddress4;
                    callbackArgument5 = 1;
                    MATCHING_KEEP_CLOBBER(callbackArgument5, "$6");
                    callbackSigned6 = Atlas_7839C_D_atlas_8007ADE4;
                    currentCallbackF3((void*)callbackByteAddress4, callbackArgument5,
                                      callbackSigned6, 4);
                }
                Atlas_7839C_Field((unsigned char*)selectedHalf17, unsigned short*, 0) =
                    (unsigned short)(Atlas_7839C_Field((unsigned char*)selectedHalf17,
                                                       unsigned short*, 0) -
                                     1);
            }
            goto call30258;
    }
    return;
call30258:
    Atlas_7839CRemapPrimitiveListScreenCoordinates(Atlas_7839C_D_8006FBF8, phaseWord16);
}
#undef Atlas_7839C_Field


/* AI generated; not human reviewed. Retail numeric atlas actor/view updates. */
extern short Decoded2058Mode __asm__("D_atlas_8007ADE4");
extern int Decoded2058Value __asm__("D_atlas_8007ADFC");
extern int Decoded2058X __asm__("D_80070118");
extern volatile int Decoded2058Y __asm__("D_8007011C");
extern int Decoded2058Z __asm__("D_80070120");
extern unsigned short Decoded2058Angle __asm__("D_8006E040");
extern short Decoded2058Shift __asm__("D_80070136");
extern unsigned char Decoded2058A __asm__("D_80070130"), Decoded2058B __asm__("D_80070131"),
    Decoded2058C __asm__("D_80070132");
extern int D_8006FBCC, D_8006C648;
extern Moby* D_8006C65C;
typedef struct {
    Moby* actor;
    int unk04;
} Decoded2058Record;
extern Decoded2058Record Decoded2058State __asm__("D_8006E788");
void Decoded2058UpdateMobyAnimations(Decoded2058Record*, int) __asm__("func_80055854");
void Decoded2058FinalizeMobyAnimationTransform(Moby*) __asm__("func_80034DAC");
extern void (*Decoded2058Particles)(int) __asm__("UpdateParticles");
void func_atlas_80078AFC(void) {
    int shift;
    {
        register int mode __asm__("$3") = Decoded2058Mode;

 Decoded2058X = 2048;
        if (mode >= 10 || mode == 7)
            Decoded2058Y = -1300;
        else if (Decoded2058Value)
            Decoded2058Y = (Decoded2058Value - 40) * -6 + 1100;
        else
            Decoded2058Y = 430;
    }
    MATCHING_BARRIER("memory");
    {
        register int mode __asm__("$3") = Decoded2058Mode;
        MATCHING_KEEP(mode);
        if (mode >= 10 || mode == 7)
            Decoded2058Z = 897;
        else
            Decoded2058Z = 553 - (D_8006FBCC - 1) * 172;
    }
    Decoded2058C = ((int)(Decoded2058Angle << 16) >> 20) + 64;
    if (Decoded2058Shift) {
        shift = Decoded2058Shift / 8 - 1;
        if (shift >= 7)
            shift = 6;
        if (Decoded2058Y < 430)
            Decoded2058Y = 430;
        Decoded2058Y <<= shift;
    }
    Decoded2058A = 0;
    Decoded2058B = 0;
    if (D_8006C65C) {
        Decoded2058State.actor = D_8006C65C;
        Decoded2058State.unk04 = 0;
        Decoded2058UpdateMobyAnimations(&Decoded2058State, 2);
        if (D_8006C648 >= 3)
            Decoded2058UpdateMobyAnimations(&Decoded2058State, D_8006C648 + 0x7FFFFFFE);
        Decoded2058FinalizeMobyAnimationTransform(D_8006C65C);
    }
    if (Decoded2058Particles)
        Decoded2058Particles(D_8006C648);
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 Atlas, original function80078D0C.
* Assembly SHA256 c9b042419a225eebacd395d804a9955f5ae217929d5994ef176e45d94a795905.
* Original byte/halfword/word reads, signed shifts, table selectors and
* branch targets are preserved. Address names and register roles do not
* establish full UI semantics, physical units, fixed point or frame cadence.
* The source retains original unused local frame storage; do not prune it.
* The paired .set directives below are assembler scheduling metadata only.
* They emit no CPU instructions. C produces original BEQ633/SLL634/SRA635;
* the false-branch destination replaces the shifted scratch register before
* using it. No live predicate is overwritten by a constraint or extra producer.
* Original source/shift values are separate initialized inputs. All other
* empty boundaries likewise consume initialized original producers.
* Existing atlas2.c's void2A6E4 declaration supplies the helper's symbol view.
* Complete helper meanings/caller runtime chains remain unresolved.
* Falsification: every native/linked word and owned table/transfer target,
* preserved data and complete EXE/every-overlay retail hash. Compiler,
* assembler pipeline, flags, assertions and acceptance gates are unchanged.
* AI-generated; not human reviewed. No synchronized runtime parity claim. */
#define Atlas78DHighProduct(a, b)                                       \
    ({                                                                  \
        int high;                                                       \
        __asm__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                           \
    })
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/atlas/atlas2/func_atlas_80078D0C.s SHA256 c9b042419a225eebacd395d804a9955f5ae217929d5994ef176e45d94a795905. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Atlas78DField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
struct Atlas78DOriginalFrameDescription {
    /* 0x00 */ char pad0[0x40];
};
/* size = 0x40 */
void Atlas78DSubmitHudSoundByte17(void) __asm__("func_8002A6E4");
/* extern */
int Atlas78DSubmitHudSoundByte18WithWord0C() __asm__("func_8002A714");
/* extern */
int Atlas78DBeginLevelWarp() __asm__("func_800584BC");
/* extern */
int Atlas78D_func_atlas_80075C3C() __asm__("func_atlas_80075C3C");
/* extern */
extern int Atlas78D_D_8006581C __asm__("D_8006581C");
extern unsigned char Atlas78D_D_80066FCC __asm__("D_80066FCC");
extern int Atlas78D_D_8006C5BC __asm__("D_8006C5BC");
extern int Atlas78D_D_8006C648 __asm__("D_8006C648");
extern int Atlas78D_D_8006E53C __asm__("D_8006E53C");
extern int Atlas78D_D_8006FBC4 __asm__("D_8006FBC4");
extern volatile int Atlas78D_D_8006FBCC __asm__("D_8006FBCC");
extern int Atlas78D_D_8006FBD4 __asm__("D_8006FBD4");
extern int Atlas78D_D_80070148 __asm__("D_80070148");
extern signed char Atlas78D_D_8007014E __asm__("D_8007014E");
extern signed char Atlas78D_D_8007014F __asm__("D_8007014F");
extern unsigned char Atlas78D_D_8007158F __asm__("D_8007158F");
extern unsigned char Atlas78D_D_80071FB0 __asm__("D_80071FB0");
extern int Atlas78D_D_atlas_8007ADE0 __asm__("D_atlas_8007ADE0");
extern short Atlas78D_D_atlas_8007ADE4 __asm__("D_atlas_8007ADE4");
extern short Atlas78D_D_atlas_8007ADE6 __asm__("D_atlas_8007ADE6");
extern short Atlas78D_D_atlas_8007ADE8 __asm__("D_atlas_8007ADE8");
extern short Atlas78D_D_atlas_8007ADEA __asm__("D_atlas_8007ADEA");
extern short Atlas78D_D_atlas_8007ADF8 __asm__("D_atlas_8007ADF8");
extern short Atlas78D_D_atlas_8007AE06 __asm__("D_atlas_8007AE06");
extern short Atlas78D_D_atlas_8007AE08 __asm__("D_atlas_8007AE08");
extern short Atlas78D_D_atlas_8007AE0C __asm__("D_atlas_8007AE0C");
extern short Atlas78D_D_atlas_8007AE0E __asm__("D_atlas_8007AE0E");
void func_atlas_80078D0C(unsigned char arg0, short* arg1, int arg2) {
    unsigned char* temp_a3;
    register short* var_a1 __asm__("$5");
    short temp_v0_4;
    short temp_v0_5;
    int var_a0_4;
    short var_v0;
    short var_v0_4;
    register int var_v0_5 __asm__("$2");
    register int temp_a1 __asm__("$5");
    int temp_v0;
    int var_a0_2;
    int var_a0_3;
    register int var_s1 __asm__("$17");
    register int var_s2 __asm__("$18");
    int var_t0;
    int var_v0_2;
    int var_v0_3;
    register int var_v1 __asm__("$3");
    int var_v1_2;
    unsigned char temp_v0_2;
    unsigned char temp_v0_3;
    unsigned char temp_v1;
    register int var_a0 __asm__("$4");
    unsigned char* temp_a1_2;
    register int entryMask3 __asm__("$3");
    int selectionPredicate, selectionShift;
    register volatile int* resetWord4 __asm__("$4");
    register volatile int* forwardCursor6 __asm__("$6");
    register volatile int* forwardCursor4 __asm__("$4");
    register short* forwardHalf4 __asm__("$4");
    register short* forwardHalf10 __asm__("$10");
    register unsigned char* forwardBase7 __asm__("$7");
    register unsigned char* forwardByte4 __asm__("$4");
    register int forwardWord5 __asm__("$5");
    register int forwardFlag8 __asm__("$8");
    register int forwardLiteral9 __asm__("$9");
    register int forwardProduct11 __asm__("$11");
    register volatile int* cursorPointer3 __asm__("$3");
    register volatile int* cursorPointer4 __asm__("$4");
    register volatile int* cursorPointer5 __asm__("$5");
    register short* rowPointer6 __asm__("$6");
    register unsigned char* bytePointer5 __asm__("$5");
    register unsigned char* recordPointer7 __asm__("$7");
    register unsigned char* recordBase9 __asm__("$9");
    register int scanFlag4 __asm__("$4");
    register int literal5 __asm__("$5");
    register int literal7 __asm__("$7");
    register int literal8 __asm__("$8");
    register int product11 __asm__("$11");
    unsigned char originalUnusedFrameBytes[16];
    register int rawWord2 __asm__("$2");
    register int sharedStep2 __asm__("$2");
    register int rawWord4 __asm__("$4");
    register int highWord11 __asm__("$11");
    register int* maskPointer19 __asm__("$19");
    register int* stepPointer16 __asm__("$16");
    register int halfWord2 __asm__("$2");
    register int shiftedWord4 __asm__("$4");
    register int signedWord5 __asm__("$5");
    entryMask3 = Atlas78D_D_8006E53C;
    var_a0 = arg0;
    var_a1 = arg1;
    if (entryMask3 & 0x100) {
        __asm__ volatile("" : "=m"(originalUnusedFrameBytes));
        __asm__("" : : : "$2", "memory");
        Atlas78DSubmitHudSoundByte17();
        Atlas78D_D_atlas_8007ADE0 = 6;
        Atlas78D_D_8006FBCC = 1;
        Atlas78D_D_8006FBC4 = 0;
        Atlas78D_D_8006FBD4 = 0;
        Atlas78D_D_8007014E = 1;
        return;
    }
    if (entryMask3 & 0x800) {
        __asm__("" : : : "$4", "memory");
        Atlas78DSubmitHudSoundByte17();
        rawWord2 = 6;
        goto block_110;
    }
    if (entryMask3 & 0x10) {
        __asm__("" : : : "$5", "memory");
        Atlas78DSubmitHudSoundByte17();
        halfWord2 = *(unsigned short*)&Atlas78D_D_atlas_8007ADE4;
        shiftedWord4 = halfWord2 << 16;
        MATCHING_KEEP(shiftedWord4);
        signedWord5 = shiftedWord4 >> 16;
        MATCHING_KEEP(signedWord5);
        if (signedWord5 == 0)
            goto block_109;
        if (signedWord5 < 8) {
            Atlas78D_D_atlas_8007ADE6 = 0;
            Atlas78D_D_atlas_8007ADEA = 0;
            __asm__("" : : : "$2", "memory");
            rawWord2 = 1;
            goto block_107;
        }
        rawWord2 = 0x66660000;
        MATCHING_KEEP(rawWord2);
        rawWord2 |= 0x6667;
        highWord11 = Atlas78DHighProduct(signedWord5, rawWord2);
        rawWord2 = shiftedWord4 >> 31;
        entryMask3 = highWord11 >> 2;
        shiftedWord4 = entryMask3 - rawWord2;
        MATCHING_KEEP(shiftedWord4);
        rawWord2 = shiftedWord4 * 10;
        rawWord2 = signedWord5 - rawWord2;
        rawWord2 = (short)rawWord2;
        entryMask3 = 8;
        if (rawWord2 == entryMask3) {
            rawWord2 = 5;
            Atlas78D_D_atlas_8007ADE6 = rawWord2;
            rawWord2 = 4;
        } else {
            rawWord2 = signedWord5 < 50;
            MATCHING_KEEP(rawWord2);
            if (rawWord2 == 0) {
                rawWord2 = 6;
                Atlas78D_D_atlas_8007ADE6 = rawWord2;
            } else {
                Atlas78D_D_atlas_8007ADE6 = shiftedWord4;
                rawWord2 = 2;
            }
        }
        Atlas78D_D_atlas_8007ADEA = rawWord2;
        __asm__("" : : : "$2", "memory");
        rawWord2 = 1;
        goto block_107;
    }
    rawWord2 = entryMask3 & 0x40;
    MATCHING_KEEP(rawWord2);
    if (rawWord2 != 0) {
        var_a1 = &Atlas78D_D_atlas_8007ADE6;
        MATCHING_KEEP_CLOBBER(var_a1, "memory");
        entryMask3 = Atlas78D_D_atlas_8007ADE8;
        rawWord4 = Atlas78D_D_8006FBCC;
        entryMask3 += 1;
        MATCHING_KEEP(entryMask3);
        rawWord2 = entryMask3 * 24;
        MATCHING_KEEP_CLOBBER(rawWord2, "$3");
        entryMask3 = (int)var_a1 + 0x12E;
        rawWord2 += entryMask3;
        rawWord2 += rawWord4;
        var_a0 = Atlas78DField(rawWord2, unsigned char*, 0);
        entryMask3 = var_a0;
        MATCHING_KEEP_CLOBBER(entryMask3, "memory");
        *var_a1 = (short)var_a0;
        if (entryMask3 == 0) {
            Atlas78D_D_atlas_8007ADEA = 0;
            __asm__("" : : : "$6", "memory");
            Atlas78DSubmitHudSoundByte17();
            Atlas78D_D_8006FBCC = 1;
            __asm__("" : : : "$2", "memory");
            sharedStep2 = Atlas78D_D_8006C648;
            MATCHING_KEEP_CLOBBER(sharedStep2, "$3");
            var_v1 = 3;
            goto block_108;
        }
        if (entryMask3 < 5) {
            Atlas78D_D_atlas_8007ADEA = 2;
            if (*(&Atlas78D_D_80071FB0 + *(&Atlas78D_D_80066FCC + (entryMask3 * 0xA))) != 0) {
                __asm__("" : : : "$2", "$4", "memory");
                Atlas78DSubmitHudSoundByte17();
                Atlas78D_D_8006FBCC = 1;
                __asm__("" : : : "$2", "memory");
                sharedStep2 = Atlas78D_D_8006C648;
                MATCHING_KEEP_CLOBBER(sharedStep2, "$3");
                var_v1 = 3;
                goto block_108;
            }
            goto block_31;
        }
        if (entryMask3 == 6) {
            Atlas78D_D_atlas_8007ADEA = 6;
            if (*(&Atlas78D_D_80071FB0 +
                  Atlas78DField(&Atlas78D_D_80066FCC, unsigned char*, 0x32)) != 0) {
                __asm__("" : : : "$2", "$5", "memory");
                Atlas78DSubmitHudSoundByte17();
                Atlas78D_D_8006FBCC = 1;
                __asm__("" : : : "$2", "memory");
                sharedStep2 = Atlas78D_D_8006C648;
                MATCHING_KEEP_CLOBBER(sharedStep2, "$3");
                var_v1 = 3;
                goto block_108;
            }
            goto block_31;
        }
        if (entryMask3 == 5) {
            Atlas78D_D_atlas_8007ADEA = 4;
            if (*(&Atlas78D_D_80071FB0 +
                  Atlas78DField(&Atlas78D_D_80066FCC, unsigned char*, 0x12)) != 0) {
                __asm__("" : : : "$2", "$6", "memory");
                Atlas78DSubmitHudSoundByte17();
                Atlas78D_D_8006FBCC = 1;
                __asm__("" : : : "$2", "memory");
                sharedStep2 = Atlas78D_D_8006C648;
                MATCHING_KEEP_CLOBBER(sharedStep2, "$3");
                var_v1 = 3;
                goto block_108;
            }
            goto block_31;
        }
        if (((short)Atlas78D_D_atlas_8007ADE4 != 0) && ((short)Atlas78D_D_atlas_8007ADE4 < 5)) {
            entryMask3 = Atlas78D_D_atlas_8007ADE4;
            entryMask3 -= 1;
            MATCHING_KEEP(entryMask3);
            rawWord2 = entryMask3 * 10;
            rawWord2 = var_a0 + rawWord2;
            *var_a1 = (short)rawWord2;
        }
        Atlas78D_D_atlas_8007ADEA = 8;
        if (*(&Atlas78D_D_80071FB0 + *(&Atlas78D_D_80066FCC + Atlas78D_D_atlas_8007ADE6)) != 0) {
            __asm__("" : : : "$4", "$5", "memory");
            Atlas78DSubmitHudSoundByte17();
            Atlas78D_D_8006FBCC = 1;
            Atlas78D_D_8006FBC4 = 0;
            Atlas78D_D_atlas_8007ADF8 = 0;
            Atlas78D_D_atlas_8007ADE0 = 7;
            return;
        }
        goto block_31;
    }
block_31:
    if (arg2 == 0) {
        var_s1 = 0;
        var_s2 = 0xA;
        if (Atlas78D_D_8007158F != 0) {
            maskPointer19 = &Atlas78D_D_8006E53C;
            MATCHING_KEEP_CLOBBER(maskPointer19, "memory");
            if (*maskPointer19 & 0x80) {
                Atlas78D_D_atlas_8007ADE6 = 7;
                Atlas78D_D_atlas_8007ADEA = 0xC;
                Atlas78D_D_atlas_8007ADE0 = 3;
                __asm__("" : : : "$2", "memory");
                sharedStep2 = Atlas78D_D_8006C648;
                __asm__("" : : : "$16", "memory");
                stepPointer16 = &Atlas78D_D_8006FBC4;
                MATCHING_KEEP_CLOBBER(stepPointer16, "memory");
                Atlas78D_D_atlas_8007AE0C = 0;
                *stepPointer16 = -sharedStep2;
                Atlas78DSubmitHudSoundByte17();
                rawWord2 = 1;
                *stepPointer16 = 0;
                Atlas78D_D_8006FBCC = rawWord2;
            }
            if ((Atlas78D_D_atlas_8007AE0E >= 0xA) && (*maskPointer19 & 0x20)) {
                Atlas78D_D_atlas_8007ADEA = 0xA;
                Atlas78DSubmitHudSoundByte17();
                Atlas78D_D_8006FBCC = 1;
                Atlas78D_D_8006FBC4 = 0;
                Atlas78D_D_atlas_8007AE06 = 0;
                Atlas78D_D_atlas_8007AE08 = 0;
                Atlas78D_D_atlas_8007ADE6 = 0x64;
                __asm__("" : : : "$4", "memory");
                Atlas78D_func_atlas_80075C3C(0);
                Atlas78D_D_atlas_8007ADE0 = 8;
                return;
            }
            goto block_44;
        }
        goto block_44;
    }
    var_s1 = 0;
    if ((unsigned int)(arg2 - 5) >= 2U) {
        entryMask3 = arg2 - 1;
        rawWord2 = entryMask3 * 5;
        MATCHING_KEEP(rawWord2);
        var_s1 = rawWord2 << 1;
    }
    var_s2 = 1;
    if ((Atlas78D_D_8006581C >= 2) && (Atlas78D_D_8006E53C & 0x80)) {
        forwardHalf4 = &Atlas78D_D_atlas_8007ADE8;
        MATCHING_KEEP_CLOBBER(forwardHalf4, "memory");
        entryMask3 = *forwardHalf4;
        forwardByte4 = (unsigned char*)forwardHalf4 + 0x12C;
        entryMask3 += 1;
        MATCHING_KEEP(entryMask3);
        rawWord2 = entryMask3 * 24;
        rawWord2 += (int)forwardByte4;
        entryMask3 = Atlas78D_D_8006FBCC;
        rawWord2 += entryMask3;
        rawWord2 = Atlas78DField(rawWord2, unsigned char*, 0);
        temp_a1 = var_s1 + rawWord2;
        if (temp_a1 != Atlas78D_D_8006C5BC) {
            Atlas78D_D_8007014F = 0;
            Atlas78D_D_80070148 = 0;
            Atlas78DBeginLevelWarp(0, temp_a1);
        }
    } else {
    block_44:
        if (Atlas78D_D_8006E53C & 0x1000) {
            Atlas78DSubmitHudSoundByte18WithWord0C();
            cursorPointer3 = &Atlas78D_D_8006FBCC;
            MATCHING_KEEP_CLOBBER(cursorPointer3, "memory");
            rawWord2 = *cursorPointer3;
            scanFlag4 = 1;
            rawWord2 -= 1;
            *(int*)cursorPointer3 = rawWord2;
            if (rawWord2 <= 0)
                goto scanWrap;
            rowPointer6 = &Atlas78D_D_atlas_8007ADE8;
            __asm__("" : "=r"(rowPointer6) : "0"(rowPointer6) : "$9", "memory");
            recordBase9 = (unsigned char*)rowPointer6 + 0x12C;
            literal8 = 5;
            literal7 = 6;
            cursorPointer5 = cursorPointer3;
        scanA:
            if (scanFlag4 == 0)
                goto checkWrap;
            rawWord2 = *rowPointer6;
            rawWord2 += 1;
            MATCHING_KEEP(rawWord2);
            entryMask3 = rawWord2 * 24;
            rawWord2 = Atlas78D_D_8006FBCC;
            entryMask3 += (int)recordBase9;
            entryMask3 += rawWord2;
            MATCHING_KEEP_CLOBBER(entryMask3, "$2");
            rawWord2 = Atlas78DField(entryMask3, unsigned char*, 0);
            if (rawWord2 == literal8) {
                rawWord2 = 18;
            } else if (rawWord2 == literal7) {
                rawWord2 = 50;
            } else {
                product11 = rawWord2 * var_s2;
                rawWord2 = var_s1 + product11;
            }
            rawWord2 = *(&Atlas78D_D_80066FCC + rawWord2);
            rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
            __asm__("" : : : "$3", "$11", "memory");
            if (rawWord2 != 0) {
                scanFlag4 = 0;
            } else {
                rawWord2 = *cursorPointer5;
                rawWord2 -= 1;
                *cursorPointer5 = rawWord2;
            }
            rawWord2 = *cursorPointer5;
            if (rawWord2 > 0)
                goto scanA;
        checkWrap:
            rawWord2 = Atlas78D_D_8006FBCC;
            if (rawWord2 > 0)
                goto scanSecond;
        scanWrap:
            __asm__("" : : : "$6", "memory");
            rowPointer6 = &Atlas78D_D_atlas_8007ADE8;
            MATCHING_KEEP_CLOBBER(rowPointer6, "memory");
            entryMask3 = *rowPointer6;
            __asm__("" : : : "$5", "memory");
            bytePointer5 = (unsigned char*)rowPointer6 + 0x12D;
            MATCHING_KEEP2(entryMask3, bytePointer5);
            rawWord2 = entryMask3 * 3;
            MATCHING_KEEP_CLOBBER(rawWord2, "$3");
            entryMask3 = Atlas78D_D_8006FBCC;
            rawWord2 <<= 3;
            rawWord2 += entryMask3;
            rawWord2 += (int)bytePointer5;
            entryMask3 = Atlas78DField(rawWord2, unsigned char*, 0);
            rawWord2 = 255;
            if (entryMask3 == rawWord2)
                goto scanSecond;
            cursorPointer4 = &Atlas78D_D_8006FBCC;
            recordPointer7 = bytePointer5;
            literal5 = 255;
        scanWrapLoop:
            rawWord2 = *cursorPointer4;
            entryMask3 = *rowPointer6;
            rawWord2 += 1;
            *cursorPointer4 = rawWord2;
            rawWord2 = entryMask3 * 3;
            entryMask3 = Atlas78D_D_8006FBCC;
            rawWord2 <<= 3;
            rawWord2 += entryMask3;
            rawWord2 += (int)recordPointer7;
            rawWord2 = Atlas78DField(rawWord2, unsigned char*, 0);
            if (rawWord2 != literal5)
                goto scanWrapLoop;
        scanSecond:
            cursorPointer3 = &Atlas78D_D_8006FBCC;
            MATCHING_KEEP_CLOBBER(cursorPointer3, "memory");
            rawWord2 = *cursorPointer3;
            scanFlag4 = 1;
            if (rawWord2 <= 0)
                goto scanFinish;
            rowPointer6 = &Atlas78D_D_atlas_8007ADE8;
            __asm__("" : "=r"(rowPointer6) : "0"(rowPointer6) : "$9", "memory");
            recordBase9 = (unsigned char*)rowPointer6 + 0x12C;
            literal8 = 5;
            literal7 = 6;
            cursorPointer5 = cursorPointer3;
        scanB:
            if (scanFlag4 == 0)
                goto readScanFinish;
            rawWord2 = *rowPointer6;
            rawWord2 += 1;
            MATCHING_KEEP(rawWord2);
            entryMask3 = rawWord2 * 24;
            rawWord2 = Atlas78D_D_8006FBCC;
            entryMask3 += (int)recordBase9;
            entryMask3 += rawWord2;
            MATCHING_KEEP_CLOBBER(entryMask3, "$2");
            rawWord2 = Atlas78DField(entryMask3, unsigned char*, 0);
            if (rawWord2 == literal8) {
                rawWord2 = 18;
            } else if (rawWord2 == literal7) {
                rawWord2 = 50;
            } else {
                product11 = rawWord2 * var_s2;
                rawWord2 = var_s1 + product11;
            }
            rawWord2 = *(&Atlas78D_D_80066FCC + rawWord2);
            rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
            __asm__("" : : : "$3", "memory");
            if (rawWord2 != 0) {
                scanFlag4 = 0;
            } else {
                rawWord2 = *cursorPointer5;
                rawWord2 -= 1;
                *cursorPointer5 = rawWord2;
            }
            rawWord2 = *cursorPointer5;
            if (rawWord2 > 0)
                goto scanB;
        readScanFinish:
            cursorPointer3 = &Atlas78D_D_8006FBCC;
            MATCHING_KEEP_CLOBBER(cursorPointer3, "memory");
            rawWord2 = *cursorPointer3;
        scanFinish:
            if (rawWord2 == 0) {
                rawWord2 = 1;
                *(int*)cursorPointer3 = rawWord2;
            }
        } else if (Atlas78D_D_8006E53C & 0x4000) {
            Atlas78DSubmitHudSoundByte18WithWord0C();
            forwardCursor6 = &Atlas78D_D_8006FBCC;
            __asm__("" : "=r"(forwardCursor6) : "0"(forwardCursor6) : "$4", "memory");
            forwardHalf4 = &Atlas78D_D_atlas_8007ADE8;
            MATCHING_KEEP_CLOBBER(forwardHalf4, "memory");
            rawWord2 = *forwardCursor6;
            __asm__("" : : : "$7", "memory");
            forwardBase7 = (unsigned char*)forwardHalf4 + 0x12C;
            MATCHING_KEEP_CLOBBER(forwardBase7, "memory");
            rawWord2 += 1;
            *forwardCursor6 = rawWord2;
            entryMask3 = *forwardHalf4;
            forwardWord5 = Atlas78D_D_8006FBCC;
            rawWord2 = entryMask3 * 24;
            rawWord2 += (int)forwardBase7;
            rawWord2 += forwardWord5;
            entryMask3 = Atlas78DField(rawWord2, unsigned char*, 0);
            __asm__("" : : : "$8", "memory");
            rawWord2 = 255;
            forwardFlag8 = 1;
            if (entryMask3 == rawWord2)
                goto block_126;
            forwardHalf10 = forwardHalf4;
            forwardLiteral9 = 5;
            forwardCursor4 = forwardCursor6;
            MATCHING_KEEP3(forwardHalf10, forwardLiteral9, forwardCursor4);
        forwardScan:
            if (forwardFlag8 == 0)
                goto forwardFinalByte;
            entryMask3 = *forwardHalf10;
            entryMask3 += 1;
            MATCHING_KEEP(entryMask3);
            rawWord2 = entryMask3 * 24;
            rawWord2 += (int)forwardBase7;
            rawWord2 += forwardWord5;
            entryMask3 = Atlas78DField(rawWord2, unsigned char*, 0);
            rawWord2 = 6;
            if (entryMask3 == forwardLiteral9) {
                entryMask3 = 18;
            } else if (entryMask3 == rawWord2) {
                entryMask3 = 50;
            } else {
                forwardProduct11 = entryMask3 * var_s2;
                entryMask3 = var_s1 + forwardProduct11;
            }
            rawWord2 = *(&Atlas78D_D_80066FCC + entryMask3);
            rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
            if (rawWord2 != 0) {
                forwardFlag8 = 0;
            } else {
                rawWord2 = *forwardCursor4;
                rawWord2 += 1;
                *forwardCursor4 = rawWord2;
            }
            entryMask3 = Atlas78D_D_atlas_8007ADE8;
            forwardWord5 = Atlas78D_D_8006FBCC;
            rawWord2 = entryMask3 * 24;
            rawWord2 += (int)forwardBase7;
            rawWord2 += forwardWord5;
            entryMask3 = Atlas78DField(rawWord2, unsigned char*, 0);
            rawWord2 = 255;
            if (entryMask3 != rawWord2)
                goto forwardScan;
        forwardFinalByte:
            forwardHalf4 = &Atlas78D_D_atlas_8007ADE8;
            MATCHING_KEEP_CLOBBER(forwardHalf4, "memory");
            entryMask3 = *forwardHalf4;
            forwardByte4 = (unsigned char*)forwardHalf4 + 0x12C;
            MATCHING_KEEP2(entryMask3, forwardByte4);
            rawWord2 = entryMask3 * 24;
            MATCHING_KEEP_CLOBBER(rawWord2, "$3");
            entryMask3 = Atlas78D_D_8006FBCC;
            rawWord2 += (int)forwardByte4;
            rawWord2 += entryMask3;
            entryMask3 = Atlas78DField(rawWord2, unsigned char*, 0);
            rawWord2 = 255;
            if (entryMask3 != rawWord2)
                return;
            rawWord2 = 1;
            goto block_127;
        } else if (Atlas78D_D_8006E53C & 0x8000) {
            rawWord2 = Atlas78D_D_atlas_8007ADE4;
            rawWord4 = rawWord2;
            if (rawWord2 > 0) {
                rawWord2 = rawWord4 - 1;
                Atlas78D_D_atlas_8007ADE6 = (short)rawWord2;
                rawWord2 = (short)rawWord2;
                entryMask3 = 5;
                if (rawWord2 == entryMask3) {
                    rawWord2 = Atlas78DField(&Atlas78D_D_80066FCC, unsigned char*, 0x12);
                    rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
                    if (rawWord2 == 0) {
                        rawWord2 = rawWord4 - 2;
                        Atlas78D_D_atlas_8007ADE6 = (short)rawWord2;
                    }
                }
                var_a1 = &Atlas78D_D_atlas_8007ADE6;
                MATCHING_KEEP_CLOBBER(var_a1, "memory");
                entryMask3 = *(unsigned short*)var_a1;
                selectionPredicate = (unsigned int)(entryMask3 - 1) < 4U;
                MATCHING_KEEP(selectionPredicate);
                __asm__ volatile(".set\tnoreorder");
                if (selectionPredicate == 0)
                    goto selectionFinal;
                selectionShift = (unsigned int)entryMask3 << 16;
                __asm__ volatile(".set\treorder"
                                 : "=r"(selectionShift)
                                 : "0"(selectionShift), "r"(entryMask3));
                entryMask3 = selectionShift >> 16;
                MATCHING_KEEP_CLOBBER(entryMask3, "$2");
                rawWord2 = entryMask3 << 2;
                if (entryMask3 <= 0)
                    goto selectionFinal;
                MATCHING_KEEP(rawWord2);
                rawWord2 += entryMask3;
                rawWord2 <<= 1;
                rawWord2 = *(&Atlas78D_D_80066FCC + rawWord2);
                rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
                __asm__("" : : : "$4", "memory");
                rawWord4 = (int)&Atlas78D_D_80066FCC;
                MATCHING_KEEP_CLOBBER(rawWord4, "memory");
                if (rawWord2 != 0)
                    goto selectionFinal;
            selectionPrevious:
                rawWord2 = *(unsigned short*)var_a1;
                rawWord2 -= 1;
                *var_a1 = (short)rawWord2;
                rawWord2 <<= 16;
                MATCHING_KEEP_CLOBBER(rawWord2, "$3");
                entryMask3 = rawWord2 >> 16;
                MATCHING_KEEP_CLOBBER(entryMask3, "$2");
                rawWord2 = entryMask3 << 2;
                if (entryMask3 <= 0)
                    goto selectionFinal;
                MATCHING_KEEP(rawWord2);
                rawWord2 += entryMask3;
                rawWord2 <<= 1;
                rawWord2 += rawWord4;
                rawWord2 = Atlas78DField(rawWord2, unsigned char*, 0);
                rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
                if (rawWord2 == 0)
                    goto selectionPrevious;
            selectionFinal:
                entryMask3 = Atlas78D_D_atlas_8007ADE6;
                rawWord2 = 5;
                if (entryMask3 == 0) {
                    Atlas78D_D_atlas_8007ADEA = 0;
                } else {
                    if (entryMask3 == rawWord2)
                        rawWord2 = 4;
                    else
                        rawWord2 = 2;
                    Atlas78D_D_atlas_8007ADEA = (short)rawWord2;
                }
                Atlas78DSubmitHudSoundByte17();
                rawWord2 = 1;
            block_107:
                Atlas78D_D_8006FBCC = rawWord2;
                __asm__("" : : : "$2", "memory");
                sharedStep2 = Atlas78D_D_8006C648;
                MATCHING_KEEP_CLOBBER(sharedStep2, "$3");
                var_v1 = 4;
            block_108:
                Atlas78D_D_atlas_8007ADE0 = var_v1;
                MATCHING_KEEP_CLOBBER(sharedStep2, "memory");
                Atlas78D_D_8006FBC4 = -sharedStep2;
                return;
            }
        block_109:
            rawWord2 = 6;
        block_110:
            Atlas78D_D_atlas_8007ADE0 = rawWord2;
            MATCHING_BARRIER("memory");
            rawWord2 = 1;
            MATCHING_KEEP(rawWord2);
            resetWord4 = &Atlas78D_D_80070148;
            MATCHING_KEEP_CLOBBER(resetWord4, "memory");
            Atlas78D_D_8006FBC4 = 0;
            Atlas78D_D_8006FBD4 = 0;
            Atlas78D_D_8006FBCC = rawWord2;
            entryMask3 = *resetWord4;
            rawWord2 = 3;
            if (entryMask3 == rawWord2)
                *(int*)resetWord4 = 0;
        } else if (Atlas78D_D_8006E53C & 0x2000) {
            if (((short)Atlas78D_D_atlas_8007ADE4 < 4) &&
                (*(&Atlas78D_D_80071FB0 + *(&Atlas78D_D_80066FCC + 0xA +
                                            ((short)Atlas78D_D_atlas_8007ADE4 * 0xA))) != 0)) {
                Atlas78D_D_atlas_8007ADE6 = (short)Atlas78D_D_atlas_8007ADE4 + 1;
                var_v0_5 = 2;
                goto block_122;
            }
            if (((short)Atlas78D_D_atlas_8007ADE4 < 5) &&
                (*(&Atlas78D_D_80071FB0 +
                   Atlas78DField(&Atlas78D_D_80066FCC, unsigned char*, 0x12)) != 0)) {
                Atlas78D_D_atlas_8007ADE6 = 5;
                var_v0_5 = 4;
                goto block_122;
            }
            if ((short)Atlas78D_D_atlas_8007ADE4 < 6) {
                rawWord2 = Atlas78DField(&Atlas78D_D_80066FCC, unsigned char*, 0x32);
                rawWord2 = *(&Atlas78D_D_80071FB0 + rawWord2);
                if (rawWord2 != 0) {
                    var_v0_5 = 6;
                    Atlas78D_D_atlas_8007ADE6 = var_v0_5;
                block_122:
                    Atlas78D_D_atlas_8007ADEA = var_v0_5;
                    Atlas78D_D_atlas_8007ADE0 = 3;
                    Atlas78D_D_8006FBC4 = -Atlas78D_D_8006C648;
                } else {
                    goto block_124;
                }
            } else {
            block_124:
                Atlas78D_D_atlas_8007ADE6 = 0xA;
                Atlas78D_D_atlas_8007ADEA = 8;
                Atlas78D_D_8006FBC4 = 0;
                Atlas78D_D_atlas_8007ADE0 = 7;
            }
            Atlas78DSubmitHudSoundByte17();
        block_126:
            rawWord2 = 1;
        block_127:
            Atlas78D_D_8006FBCC = rawWord2;
        }
    }
}
#undef Atlas78DField
#undef Atlas78DHighProduct


/* SCUS-94467 USA Rev 0, 0x800799B0..0x80079D18, 218 instructions.
 * AI generated; not yet human reviewed. Input masks retain priority.
 * Division/modulo use the signed first halfword. The adjacent halfword is
 * decremented via an unsigned load/store and sign-extended for stride10.
 * All table selectors/payloads remain unsigned bytes; helper definitions
 * retain existing int signatures. No new field/helper meaning is asserted.
 * Empty constraints preserve original lifetimes and route-specific reads;
 * none emit instructions. Table producers, units and caller cadence remain
 * unresolved. Evidence: atlas/atlas2/func_atlas_800799B0.s.
 * Falsifiable vector: every original linked word and all retail hashes.
 */
typedef struct {
    short current, previous;
} Atlas799B0HalfPair;
extern Atlas799B0HalfPair Atlas799B0Pair __asm__("D_atlas_8007ADE4");
extern unsigned char D_80066FCC[], D_80071FB0[], D_8007014E;
extern short D_atlas_8007ADE6, D_atlas_8007ADEA;
extern int D_atlas_8007ADE0, D_8006E53C, D_8006C648;
extern int D_8006FBCC, D_8006FBC4, D_8006FBD4, D_80070148;
void func_8002A6E4(void);
int func_atlas_80075824(int);
int func_atlas_800758B0(int);
void func_atlas_800799B0(void) {
    int lookupResult;
    register int selectionValue __asm__("$2");
    register int modeValue __asm__("$3");
    register int step __asm__("$2");
    register Atlas799B0HalfPair* halfPair __asm__("$6");
    register unsigned char* table __asm__("$5");
    register short* previous __asm__("$4");
    register int* word __asm__("$4");
    register int one __asm__("$2");
    unsigned short decrementedHalf;

    if (D_8006E53C & 0x100) {
        func_8002A6E4();
        D_atlas_8007ADE0 = 6;
        D_8006FBCC = 1;
        D_8006FBC4 = 0;
        D_8006FBD4 = 0;
        D_8007014E = 1;
        return;
    }
    if (D_8006E53C & 0x800) {
        func_8002A6E4();
        D_atlas_8007ADE0 = 6;
        MATCHING_BARRIER_VOLATILE("memory");
        one = 1;
        MATCHING_KEEP(one);
        word = &D_80070148;
        MATCHING_KEEP_CLOBBER(word, "memory");
        D_8006FBC4 = 0;
        D_8006FBD4 = 0;
        D_8006FBCC = one;
        if (*word == 3) {
            *word = 0;
        }
    } else {
        if (D_8006E53C & 0x10) {
            func_8002A6E4();
            if ((short)(Atlas799B0Pair.current % 10) == 8) {
                D_atlas_8007ADEA = 4;
                D_atlas_8007ADE6 = 5;
            } else if ((short)(unsigned short)Atlas799B0Pair.current == 0x32) {
                D_atlas_8007ADEA = 6;
                D_atlas_8007ADE6 = 6;
            } else {
                D_atlas_8007ADEA = 2;
                D_atlas_8007ADE6 = Atlas799B0Pair.current / 10;
            }
            D_8006FBCC = 1;
            __asm__ volatile("" : : : "$4", "memory");
            step = D_8006C648;
            MATCHING_KEEP(step);
            modeValue = 4;
            goto storeModeAndStep;
        }
        if (D_8006E53C & 0x8000) {
            halfPair = &Atlas799B0Pair;
            MATCHING_KEEP(halfPair);
            {
                register int current __asm__("$4") = halfPair->current;
                if (current >= 0xB) {
                    D_atlas_8007ADE6 = func_atlas_800758B0(current);
                    selectionValue = 8;
                } else {
                    table = D_80066FCC + 0x32;
                    MATCHING_KEEP(table);
                    if (*(D_80071FB0 + *table) != 0) {
                        selectionValue = 6;
                        D_atlas_8007ADE6 = selectionValue;
                    } else if (*(D_80071FB0 + D_80066FCC[0x12]) != 0) {
                        D_atlas_8007ADE6 = 5;
                        selectionValue = 4;
                    } else {
                        register int lookupIndex __asm__("$2") = D_80066FCC[0x28];
                        MATCHING_KEEP_CLOBBER(lookupIndex, "$3");
                        D_atlas_8007ADE6 = 4;
                        if (D_80071FB0[lookupIndex] != 0) {
                            selectionValue = 2;
                            goto storeSelection;
                        }
                        previous = &halfPair->previous;
                        table -= 0x32;
                        do {
                            decrementedHalf = *previous - 1;
                            *previous = decrementedHalf;
                        } while (D_80071FB0[table[(short)decrementedHalf * 10]] == 0);
                        selectionValue = 2;
                    }
                }
            }
        storeSelection:
            D_atlas_8007ADEA = selectionValue;
            func_8002A6E4();
            D_8006FBCC = 1;
            __asm__ volatile("" : : : "$5", "memory");
            step = D_8006C648;
            MATCHING_KEEP(step);
            modeValue = 4;
            goto storeModeAndStep;
        }
        if (D_8006E53C & 0x2000) {
            lookupResult = func_atlas_80075824((short)(unsigned short)Atlas799B0Pair.current);
            if ((lookupResult >= 0) && (*(D_80071FB0 + *(D_80066FCC + lookupResult)) != 0)) {
                D_atlas_8007ADE6 = lookupResult;
                D_atlas_8007ADEA = 8;
                func_8002A6E4();
                D_8006FBCC = 1;
                __asm__ volatile("" : : : "$6", "memory");
                step = D_8006C648;
                MATCHING_KEEP(step);
                modeValue = 3;
            storeModeAndStep:
                D_atlas_8007ADE0 = modeValue;
                MATCHING_BARRIER_VOLATILE("memory");
                D_8006FBC4 = -step;
            }
        }
    }
}

/* AI generated; not human reviewed. Retail numeric input/page branches. */
extern int D_8006E53C, D_8006FBCC, D_8006FBC4, D_8006FBD4, D_8006C648;
extern int Decoded2044Mode __asm__("D_atlas_8007ADE0");
extern short Decoded2044Page __asm__("D_atlas_8007AE0C");
extern short Decoded2044A __asm__("D_atlas_8007ADE6");
extern short Decoded2044B __asm__("D_atlas_8007ADEA");
extern int Decoded2044Word __asm__("D_80070148");
extern unsigned char Decoded2044Byte __asm__("D_8007014E");
void func_8002A6E4(void);
void func_atlas_80079D18(void) {
    int input = D_8006E53C;
    register int delta __asm__("$3");
    if (input & 0x100) {
        func_8002A6E4();
        Decoded2044Mode = 6;
        D_8006FBCC = 1;
        D_8006FBC4 = 0;
        D_8006FBD4 = 0;
        Decoded2044Byte = 1;
    } else if (input & 0x800) {
        func_8002A6E4();
        Decoded2044Mode = 6;
        __asm__("" : : : "$2", "memory");
        {
            register int one __asm__("$2") = 1;
            __asm__("" : "=r"(one) : "0"(one) : "$4", "memory");
            {
                register int* word __asm__("$4") = &Decoded2044Word;
                MATCHING_KEEP_CLOBBER(word, "memory");
                D_8006FBC4 = 0;
                D_8006FBD4 = 0;
                D_8006FBCC = one;
                if (*word == 3)
                    *word = 0;
            }
        }
    } else if (input & 0x10) {
        func_8002A6E4();
        D_8006FBCC = 1;
        Decoded2044Mode = 4;
        MATCHING_BARRIER("memory");
        {
            register unsigned int page __asm__("$2") = (unsigned short)Decoded2044Page;
            register int step __asm__("$3") = D_8006C648;
            MATCHING_KEEP2_CLOBBER(page, step, "memory");
            Decoded2044A = 0;
            Decoded2044B = 0;
            MATCHING_KEEP_CLOBBER(page, "memory");
            Decoded2044Page = page - 1;
            delta = -step;
            goto storeDelta;
        }
    } else if (input & 0x8000) {
        func_8002A6E4();
        {
            register short* page __asm__("$3") = &Decoded2044Page;
            MATCHING_KEEP(page);
            --*page;
            if (*page < 0) {
                Decoded2044A = 0;
                Decoded2044B = 0;
            }
        }
        D_8006FBCC = 1;
        Decoded2044Mode = 4;
        D_8006FBC4 = -D_8006C648;
    } else if (input & 0x2000) {
        register short* page __asm__("$16") = &Decoded2044Page;
        MATCHING_KEEP(page);
        if (*page < 3) {
            func_8002A6E4();
            D_8006FBCC = 1;
            Decoded2044Mode = 3;
            {
                register unsigned int value __asm__("$2") = (unsigned short)*page;
                delta = D_8006C648;
                MATCHING_KEEP2(value, delta);
                value++;
                delta = -delta;
                *page = value;
            }
        storeDelta:
            MATCHING_KEEP(delta);
            D_8006FBC4 = delta;
        }
    }
}

/* SCUS-94467 USA Rev 0, 0x80079F1C..0x8007A1A8, 163 instructions.
 * AI generated; not yet human reviewed. Numeric input masks retain their
 * original priority. Halfword copies use unsigned loads, signed 16-bit call
 * arguments and the original +100 halfword store. All stores retain width.
 * Empty compiler constraints preserve register lifetimes and access order;
 * none emit instructions. Helper meanings, producers, units and caller
 * cadence remain unresolved. Evidence: atlas/atlas2/func_atlas_80079F1C.s.
 * Falsifiable vector: every linked original word and full retail hashes.
 */
int CDLoadTime(void);
void func_8002A6E4(void);
void func_atlas_80075C3C(int);
void func_atlas_80075CA8(int);
void func_atlas_80075EB0(int);
extern short D_atlas_8007AE06, D_atlas_8007AE08, D_atlas_8007AE0E;
extern short D_atlas_8007ADE6, D_atlas_8007ADEA;
extern int D_atlas_8007ADE0, D_8006E538, D_8006E53C;
extern int D_8006FBCC, D_8006FBC4, D_8006FBD4, D_80070148;
extern unsigned char D_8007014E;
void func_atlas_80079F1C(void) {
    short incrementedHalf;
    register int signedHalfArgument __asm__("$4");
    register unsigned int copiedHalf __asm__("$3");
    register int* wordPointer __asm__("$4");
    register short* halfPointer __asm__("$5");
    register int one __asm__("$2");

    if (CDLoadTime() == 0) {
        if ((D_atlas_8007AE06 < 0xC) && (D_atlas_8007AE06 == D_atlas_8007AE08)) {
            incrementedHalf = D_atlas_8007AE08 + 1;
            D_atlas_8007AE08 = incrementedHalf;
            func_atlas_80075C3C(incrementedHalf);
            return;
        }
        if (D_8006E53C & 0x100) {
            func_8002A6E4();
            D_atlas_8007ADE0 = 6;
            D_8006FBCC = 1;
            D_8006FBC4 = 0;
            D_8006FBD4 = 0;
            D_8007014E = 1;
            func_atlas_80075EB0(0);
            return;
        }
        if (D_8006E53C & 0x800) {
            func_8002A6E4();
            D_atlas_8007ADE0 = 6;
            MATCHING_BARRIER_VOLATILE("memory");
            one = 1;
            MATCHING_KEEP(one);
            wordPointer = &D_80070148;
            MATCHING_KEEP_CLOBBER(wordPointer, "memory");
            D_8006FBC4 = 0;
            D_8006FBD4 = 0;
            D_8006FBCC = one;
            if (*wordPointer == 3) {
                *wordPointer = 0;
            }
            func_atlas_80075EB0(0);
            return;
        }
        if (D_8006E53C & 0x10) {
            func_8002A6E4();
            goto resetFields;
        }
        if (D_8006E53C & 0x2040) {
            func_8002A6E4();
            if (((D_atlas_8007AE0E != 0x14) && (D_atlas_8007AE06 == 5)) ||
                (D_atlas_8007AE06 >= 0xB)) {
            resetFields:
                D_8006FBCC = 1;
                D_atlas_8007ADE6 = 0;
                D_atlas_8007ADEA = 0;
                D_atlas_8007ADE0 = 4;
                D_8006FBC4 = -D_8006C648;
                func_atlas_80075EB0(0);
                return;
            }
            one = 1;
            MATCHING_KEEP(one);
            copiedHalf = (unsigned short)D_atlas_8007AE08;
            D_8006FBC4 = 0;
            D_8006FBCC = one;
            /* Retain the original split SLL/store/SRA sequence. */
            signedHalfArgument = copiedHalf << 16;
            MATCHING_KEEP(signedHalfArgument);
            D_atlas_8007AE06 = copiedHalf;
            signedHalfArgument >>= 16;
            goto finishHalfCopy;
        }
        halfPointer = &D_atlas_8007AE06;
        if ((*halfPointer == 0xB) && ((D_8006E538 & 0xA0) == 0xA0)) {
            one = 1;
            MATCHING_KEEP(one);
            copiedHalf = (unsigned short)D_atlas_8007AE08;
            D_8006FBC4 = 0;
            D_8006FBCC = one;
            signedHalfArgument = (short)copiedHalf;
            MATCHING_KEEP(signedHalfArgument);
            *halfPointer = copiedHalf;
        finishHalfCopy:
            D_atlas_8007ADE6 = copiedHalf + 0x64;
            func_atlas_80075CA8(signedHalfArgument);
            D_atlas_8007ADE0 = 3;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/atlas/atlas2/func_atlas_8007A1A8.s SHA256 659db7ee1a2da7ec8650b41e977c5052b032592236e83957d3abb90f4ffdfb95. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Atlas_7A1A8_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Atlas_7A1A8_CDLoadTime() __asm__("CDLoadTime");
/* extern */
int Atlas_7A1A8TransposePackedHalfwordMatrix3x3() __asm__("func_8004ECF4");
/* extern */
int Atlas_7A1A8TransformVectorByBasis() __asm__("func_8004ED6C");
/* extern */
int Atlas_7A1A8AddVector() __asm__("func_8004F194");
/* extern */
int Atlas_7A1A8DeleteMoby() __asm__("func_80055B18");
/* extern */
int Atlas_7A1A8_func_atlas_80075824() __asm__("func_atlas_80075824");
/* extern */
int Atlas_7A1A8_func_atlas_800758B0() __asm__("func_atlas_800758B0");
/* extern */
int Atlas_7A1A8_func_atlas_8007594C() __asm__("func_atlas_8007594C");
/* extern */
int Atlas_7A1A8_func_atlas_800759CC() __asm__("func_atlas_800759CC");
/* extern */
int Atlas_7A1A8_func_atlas_80075CA8() __asm__("func_atlas_80075CA8");
/* extern */
int Atlas_7A1A8_func_atlas_80075F2C() __asm__("func_atlas_80075F2C");
/* extern */
int Atlas_7A1A8_func_atlas_80078AFC() __asm__("func_atlas_80078AFC");
/* extern */
extern unsigned char Atlas_7A1A8_D_80066BC8 __asm__("D_80066BC8");
extern unsigned char Atlas_7A1A8_D_80066FCC __asm__("D_80066FCC");
extern int Atlas_7A1A8_D_8006C598 __asm__("D_8006C598");
extern int Atlas_7A1A8_D_8006C5BC __asm__("D_8006C5BC");
extern int Atlas_7A1A8_D_8006C648 __asm__("D_8006C648");
extern void* Atlas_7A1A8_D_8006C65C __asm__("D_8006C65C");
extern unsigned char Atlas_7A1A8_D_8006E00C __asm__("D_8006E00C");
extern int Atlas_7A1A8_D_8006E48C __asm__("D_8006E48C");
extern int Atlas_7A1A8_D_8006FBC4 __asm__("D_8006FBC4");
extern int Atlas_7A1A8_D_8006FBC8 __asm__("D_8006FBC8");
extern int Atlas_7A1A8_D_8006FBCC __asm__("D_8006FBCC");
extern int Atlas_7A1A8_D_8006FBD4 __asm__("D_8006FBD4");
extern unsigned char Atlas_7A1A8_D_80070114 __asm__("D_80070114");
extern unsigned char Atlas_7A1A8_D_80070130 __asm__("D_80070130");
extern unsigned char Atlas_7A1A8_D_80070131 __asm__("D_80070131");
extern unsigned char Atlas_7A1A8_D_80070132 __asm__("D_80070132");
extern short Atlas_7A1A8_D_80070136 __asm__("D_80070136");
extern int Atlas_7A1A8_D_80070148 __asm__("D_80070148");
extern unsigned char Atlas_7A1A8_D_8007014F __asm__("D_8007014F");
extern unsigned int Atlas_7A1A8_D_atlas_8007ADE0 __asm__("D_atlas_8007ADE0");
extern unsigned short Atlas_7A1A8_D_atlas_8007ADE4 __asm__("D_atlas_8007ADE4");
extern short Atlas_7A1A8_D_atlas_8007ADE6 __asm__("D_atlas_8007ADE6");
extern unsigned short Atlas_7A1A8_D_atlas_8007ADE8 __asm__("D_atlas_8007ADE8");
extern unsigned short Atlas_7A1A8_D_atlas_8007ADEA __asm__("D_atlas_8007ADEA");
extern short Atlas_7A1A8_D_atlas_8007ADEC __asm__("D_atlas_8007ADEC");
extern short Atlas_7A1A8_D_atlas_8007ADF0 __asm__("D_atlas_8007ADF0");
extern unsigned char Atlas_7A1A8_D_atlas_8007ADF7 __asm__("D_atlas_8007ADF7");
extern unsigned char Atlas_7A1A8_D_atlas_8007ADF8 __asm__("D_atlas_8007ADF8");
extern int Atlas_7A1A8_D_atlas_8007AE00 __asm__("D_atlas_8007AE00");
extern short Atlas_7A1A8_D_atlas_8007AE04 __asm__("D_atlas_8007AE04");
extern short Atlas_7A1A8_D_atlas_8007AE06 __asm__("D_atlas_8007AE06");
extern short Atlas_7A1A8_D_atlas_8007AE0E __asm__("D_atlas_8007AE0E");
extern short Atlas_7A1A8_FlagADF8 __asm__("D_atlas_8007ADF8");
extern unsigned char Atlas_7A1A8_D_atlas_8007AF0C __asm__("D_atlas_8007AF0C");
void func_atlas_8007A1A8(void) {
    /* SCUS-94467 USA Rev0 address8007A1A8; source/SHA above.
    * 508 original instructions plus nine dispatch words, frame68; vector
    *SP10, matrixSP20, saves16/17/18 at58/5C/60 and RA64.
    * Matrix storage capacity is proven by original asm/stdutil.s:
    *4ECF4 at8004ECF4..8004ED68 reads/writes words0/4/8/C/10, and4ED6C
    * at8004ED6C..8004EDE4 reads those same matrix words and writes vector
    * words0/4/8. That source SHA256 is 7f481bfe399bb2653f584e24b790b91bad3fe87b95c93f163385a71783a38abd.
    * Pointer16 remains a halfword address until the next helper's LH4
    * is completed, before first return2 is copied to16. This reproduces
    * the original delay-slot copy, with no pointer/return overlap.
    * The list advances by one halfword (byte2). Callback tables contain
    * word pointers at byte24 record intervals; callback data begins at
    * selectedHalfwordPointer16+byte108, with byte24 selection offsets.
    * Final input6 is the full signed LH word fromADE4. The callback type
    * projects original caller registers only; its full contract is unknown.
    * The ADF8 field is observed as a full signed LH word2; a volatile-HI
    * type would make this compiler emit a different LHU/extension sequence.
    * Original increment, clamp, shared negation and stored-global pointer
    * lifetimes retain disc instruction and branch ordering. Every empty
    * constraint consumes initialized original values; dead clobbers precede
    * identified replacement producers. No nonempty CPU asm or opcode changes are added.
    * Compiler/flags and matching gates remain unchanged. The separately
    * approved filter fix preserves the original jump-table section.
    * AI generated; not human reviewed. Confirmed scope is exact native/
    * linked words, conditional/internal J targets and owned dispatch data.
    * The falsifiable test vector includes preserved data and full EXE/
    * every-overlay hashes. Cadence per invocation; frame frequency, fixed
    * point/physical units, complete helper/asset/SFX chains and synchronized
    * retail runtime verification remain unresolved. Browser is unchanged. */
    struct {
        int sp10[4];
        int sp20[5];
    } originalFrame;
    register int* counterAE00Pointer2 __asm__("2");
    register int counterAE00Word3 __asm__("3");
    register void* matrixPointer16 __asm__("16");
    register unsigned char* data70130Pointer18 __asm__("18");
    register unsigned char* flag7014FPointer16 __asm__("16");
    register short* selectedHalfwordPointer16 __asm__("16");
    register short* halfword70136Pointer4 __asm__("4");
    register int* globalWordPointer3 __asm__("3");
    register int limitC648Word3 __asm__("3");
    register int returned2 __asm__("2");
    register int nextArgument4 __asm__("4");
    register int literal2 __asm__("2");
    register int rawByte2 __asm__("2");
    register int callbackBaseByteAddress2 __asm__("2");
    register int callbackByteOffset4 __asm__("4");
    register int callbackOneArgument5 __asm__("5");
    register int callbackSignedWord6 __asm__("6");
    register int callbackSignedIndex2 __asm__("2");
    register int flagADF8SignedWord2 __asm__("2");
    register int (*callback3)(void*, int, int) __asm__("3");
    short* halfwordCursor;
    short decreasedHalfword;
    short listHalfword;
    short otherDecreasedHalfword;
    register int fadeWord2 __asm__("2");
    int firstResult;
    register int increasedFade2 __asm__("2");
    int otherResult;
    int countArgument5;
    register int firstResult16 __asm__("16");
    register int indexOrWord3 __asm__("3");
    int secondResult;
    unsigned char selectedByte5;
    register unsigned int selectedByte17 __asm__("17");
    register unsigned int candidateWord4 __asm__("4");
    counterAE00Pointer2 = &Atlas_7A1A8_D_atlas_8007AE00;
    MATCHING_KEEP(counterAE00Pointer2);
    counterAE00Word3 = *counterAE00Pointer2;
    ++counterAE00Word3;
    *counterAE00Pointer2 = counterAE00Word3;
    Atlas_7A1A8_func_atlas_80078AFC();
    switch (Atlas_7A1A8_D_atlas_8007ADE0) {
        case 0:
            matrixPointer16 = &originalFrame.sp20;
            if (Atlas_7A1A8_D_8006C65C != 0) {
                data70130Pointer18 = &Atlas_7A1A8_D_80070130;
                MATCHING_KEEP(data70130Pointer18);
                Atlas_7A1A8_Field(Atlas_7A1A8_D_8006C65C, unsigned char*, 0x44) =
                    *data70130Pointer18;
                Atlas_7A1A8_Field(Atlas_7A1A8_D_8006C65C, unsigned char*, 0x45) =
                    (unsigned char)Atlas_7A1A8_D_80070131;
                Atlas_7A1A8_Field(Atlas_7A1A8_D_8006C65C, unsigned char*, 0x46) =
                    (unsigned char)Atlas_7A1A8_D_80070132;
                Atlas_7A1A8TransposePackedHalfwordMatrix3x3(matrixPointer16,
                                                            &Atlas_7A1A8_D_8006E00C);
                Atlas_7A1A8TransformVectorByBasis(matrixPointer16, data70130Pointer18 - 0x18,
                                                  &originalFrame.sp10);
                Atlas_7A1A8AddVector(Atlas_7A1A8_D_8006C65C + 0xC, &originalFrame.sp10,
                                     &Atlas_7A1A8_D_8006E00C + 0x14);
            }
            fadeWord2 = Atlas_7A1A8_D_8006C598;
            if (fadeWord2 > 0) {
                fadeWord2 -= 0x10;
                Atlas_7A1A8_D_8006C598 = fadeWord2;
                if (fadeWord2 < 0) {
                    Atlas_7A1A8_D_8006C598 = 0;
                    return;
                }
            } else if (Atlas_7A1A8_CDLoadTime() == 0) {
                selectedByte5 = *(&Atlas_7A1A8_D_80066FCC + Atlas_7A1A8_D_8006C5BC);
                if (Atlas_7A1A8_D_80070148 == 3) {
                    if (Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) == 0) {
                        Atlas_7A1A8_D_atlas_8007ADE8 = 8;
                        Atlas_7A1A8_D_atlas_8007ADEA = 8;
                        Atlas_7A1A8_D_atlas_8007ADE4 = (unsigned short)Atlas_7A1A8_D_8006C5BC;
                        Atlas_7A1A8_D_atlas_8007ADE6 = (short)Atlas_7A1A8_D_8006C5BC;
                        Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) = 1;
                        firstResult =
                            Atlas_7A1A8_func_atlas_800758B0(Atlas_7A1A8_D_8006C5BC, selectedByte5);
                        if (firstResult > 0) {
                            Atlas_7A1A8_func_atlas_8007594C(
                                *(&Atlas_7A1A8_D_80066FCC + firstResult), 0);
                        }
                    } else {
                        Atlas_7A1A8_func_atlas_8007594C(selectedByte5, 1);
                        Atlas_7A1A8_D_atlas_8007ADF0 = -1;
                        Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) = 0;
                    }
                }
                indexOrWord3 = 0;
                if (Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) == 0) {
                    Atlas_7A1A8_D_atlas_8007AE0E = 0;
                    do {
                        if (*(&Atlas_7A1A8_D_80066BC8 + indexOrWord3) & 2) {
                            Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, unsigned short*,
                                              0x16) =
                                (unsigned short)(Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8,
                                                                   unsigned short*, 0x16) +
                                                 1);
                        }
                        indexOrWord3 += 1;
                    } while (indexOrWord3 < 0x14);
                    limitC648Word3 = Atlas_7A1A8_D_8006C648;
                    Atlas_7A1A8_D_8006FBCC = 1;
                    Atlas_7A1A8_D_8006FBD4 = 0;
                    Atlas_7A1A8_D_atlas_8007ADE0 = 5;
                    Atlas_7A1A8_D_atlas_8007ADF7 = 0;
                    goto clearAndNegateLimit;
                }
            } else {
                default:
                    return;
            }
            break;
        case 1:
            literal2 = 1;
            if (Atlas_7A1A8_D_8006C65C != 0) {
                if (({
                        flag7014FPointer16 = &Atlas_7A1A8_D_8007014F;
                        MATCHING_KEEP(flag7014FPointer16);
                        *flag7014FPointer16;
                    }) == literal2) {
                    Atlas_7A1A8DeleteMoby(Atlas_7A1A8_D_8006C65C);
                    Atlas_7A1A8_D_8006C65C = 0;
                    *flag7014FPointer16 = 0;
                } else if (*flag7014FPointer16 == 2) {
                    Atlas_7A1A8_Field(Atlas_7A1A8_D_8006C65C, signed char*, 0x4C) = 0;
                    Atlas_7A1A8_Field(Atlas_7A1A8_D_8006C65C, signed char*, 0x4D) = 0;
                    *flag7014FPointer16 = 0;
                }
            }
            if (({
                    selectedHalfwordPointer16 = &Atlas_7A1A8_D_atlas_8007AE04;
                    MATCHING_KEEP(selectedHalfwordPointer16);
                    *selectedHalfwordPointer16;
                }) != 0) {
                if (Atlas_7A1A8_CDLoadTime() == 0) {
                    Atlas_7A1A8_func_atlas_80075F2C(*selectedHalfwordPointer16 - 1);
                    return;
                }
            } else {
                globalWordPointer3 = &Atlas_7A1A8_D_8006FBD4;
                MATCHING_KEEP(globalWordPointer3);
                if ((*globalWordPointer3 >= 5) && (Atlas_7A1A8_D_8006E48C == 0) &&
                    (Atlas_7A1A8_D_80070114 == 0)) {
                    Atlas_7A1A8_D_atlas_8007ADE0 = 0;
                    Atlas_7A1A8_D_8006FBC8 = 0x12;
                    *globalWordPointer3 = 0;
                } else {
                    *globalWordPointer3 += 1;
                }
                if (({
                        halfword70136Pointer4 = &Atlas_7A1A8_D_80070136;
                        MATCHING_KEEP(halfword70136Pointer4);
                        *halfword70136Pointer4;
                    }) < 0xFF) {
                    *halfword70136Pointer4 += 0x10;
                }
                indexOrWord3 = Atlas_7A1A8_D_8006C598;
                if (indexOrWord3 < 0xFF) {
                    increasedFade2 = indexOrWord3 + 0x10;
                    Atlas_7A1A8_D_8006C598 = increasedFade2;
                    if (increasedFade2 >= 0x100) {
                        Atlas_7A1A8_D_8006C598 = 0xFF;
                        return;
                    }
                }
            }
            break;
        case 6:
            if (({
                    halfword70136Pointer4 = &Atlas_7A1A8_D_80070136;
                    MATCHING_KEEP(halfword70136Pointer4);
                    *halfword70136Pointer4;
                }) < 0xFF) {
                *halfword70136Pointer4 += 0x10;
            }
            globalWordPointer3 = &Atlas_7A1A8_D_8006FBC4;
            MATCHING_KEEP(globalWordPointer3);
            if (*globalWordPointer3 >= 0x20) {
                *globalWordPointer3 = 0;
                Atlas_7A1A8_D_atlas_8007ADE0 = 1;
                return;
            }
            break;
        case 7:
            if (Atlas_7A1A8_CDLoadTime() == 0) {
                indexOrWord3 = Atlas_7A1A8_D_atlas_8007ADE6;
                flagADF8SignedWord2 = Atlas_7A1A8_FlagADF8;
                MATCHING_KEEP(flagADF8SignedWord2);
                nextArgument4 = *(&Atlas_7A1A8_D_80066FCC + indexOrWord3);
                if (flagADF8SignedWord2 == 0) {
                    literal2 = 1;
                    Atlas_7A1A8_FlagADF8 = literal2;
                    otherResult = Atlas_7A1A8_func_atlas_800758B0(indexOrWord3);
                    if (otherResult > 0) {
                        Atlas_7A1A8_func_atlas_8007594C(*(&Atlas_7A1A8_D_80066FCC + otherResult),
                                                        0);
                        return;
                    }
                } else {
                    Atlas_7A1A8_func_atlas_8007594C(nextArgument4, 1);
                    limitC648Word3 = Atlas_7A1A8_D_8006C648;
                    Atlas_7A1A8_D_atlas_8007ADF0 = -1;
                    Atlas_7A1A8_D_atlas_8007ADE0 = 3;
                clearAndNegateLimit:
                    Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(limitC648Word3, "memory");
                    Atlas_7A1A8_D_8006FBC4 = -limitC648Word3;
                    return;
                }
            }
            break;
        case 8:
            if (Atlas_7A1A8_CDLoadTime() == 0) {
                Atlas_7A1A8_D_8006FBC4 = 0;
                Atlas_7A1A8_D_8006FBCC = 1;
                Atlas_7A1A8_func_atlas_80075CA8(Atlas_7A1A8_D_atlas_8007AE06);
                Atlas_7A1A8_D_atlas_8007ADE0 = 3;
                return;
            }
            break;
        case 3:
        case 4:
        case 5:
            if (({
                    halfword70136Pointer4 = &Atlas_7A1A8_D_80070136;
                    MATCHING_KEEP(halfword70136Pointer4);
                    *halfword70136Pointer4;
                }) > 0) {
                decreasedHalfword = *halfword70136Pointer4 - 0x10;
                *halfword70136Pointer4 = decreasedHalfword;
                if (decreasedHalfword < 0) {
                    *halfword70136Pointer4 = 0;
                }
            }
            if (((unsigned int)((unsigned short)({
                                    selectedHalfwordPointer16 = &Atlas_7A1A8_D_atlas_8007ADE6;
                                    MATCHING_KEEP(selectedHalfwordPointer16);
                                    *selectedHalfwordPointer16;
                                }) -
                                0xA) < 0x5AU) &&
                (Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) == 0)) {
                if (Atlas_7A1A8_CDLoadTime() != 0) {
                    Atlas_7A1A8_D_8006FBC4 = -Atlas_7A1A8_D_8006C648;
                    return;
                }
                selectedByte17 = *(&Atlas_7A1A8_D_80066FCC + *selectedHalfwordPointer16);
                Atlas_7A1A8_func_atlas_800759CC(selectedByte17, 1 - Atlas_7A1A8_D_atlas_8007ADF7);
                if (Atlas_7A1A8_D_atlas_8007ADE0 == 4) {
                    returned2 = Atlas_7A1A8_func_atlas_800758B0(*selectedHalfwordPointer16);
                    nextArgument4 = *selectedHalfwordPointer16;
                    MATCHING_KEEP2(returned2, nextArgument4);
                    firstResult16 = returned2;
                    secondResult = Atlas_7A1A8_func_atlas_80075824(nextArgument4);
                } else {
                    returned2 = Atlas_7A1A8_func_atlas_80075824(*selectedHalfwordPointer16);
                    nextArgument4 = *selectedHalfwordPointer16;
                    MATCHING_KEEP2(returned2, nextArgument4);
                    firstResult16 = returned2;
                    secondResult = Atlas_7A1A8_func_atlas_800758B0(nextArgument4);
                }
                if (secondResult >= 0xA) {
                    candidateWord4 = *(&Atlas_7A1A8_D_80066FCC + secondResult);
                } else {
                    rawByte2 = Atlas_7A1A8_Field(&Atlas_7A1A8_D_80066FCC, unsigned char*, 0x32);
                    MATCHING_KEEP(rawByte2);
                    candidateWord4 = rawByte2 + 1;
                }
                countArgument5 = 0;
                if (firstResult16 >= 0) {
                    halfwordCursor = &Atlas_7A1A8_D_atlas_8007ADEC;
                compareHalfwordList:
                    listHalfword = *halfwordCursor;
                    if ((listHalfword == candidateWord4) || (listHalfword == selectedByte17)) {
                        countArgument5 += 1;
                        halfwordCursor += 1;
                        if (countArgument5 < 3) {
                            goto compareHalfwordList;
                        }
                    }
                    Atlas_7A1A8_func_atlas_8007594C(*(&Atlas_7A1A8_D_80066FCC + firstResult16),
                                                    countArgument5);
                }
                Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) = 1;
                return;
            }
            if (Atlas_7A1A8_D_8006FBC4 >= 0x20) {
                Atlas_7A1A8_D_atlas_8007ADE0 = 2;
                Atlas_7A1A8_D_atlas_8007ADE4 = (unsigned short)Atlas_7A1A8_D_atlas_8007ADE6;
                Atlas_7A1A8_Field(&Atlas_7A1A8_D_atlas_8007ADF8, short*, 0) = 0;
                Atlas_7A1A8_D_atlas_8007ADE8 = Atlas_7A1A8_D_atlas_8007ADEA;
                Atlas_7A1A8_D_atlas_8007ADF7 = 1 - Atlas_7A1A8_D_atlas_8007ADF7;
                return;
            }
            break;
        case 2:
            if (({
                    halfword70136Pointer4 = &Atlas_7A1A8_D_80070136;
                    MATCHING_KEEP(halfword70136Pointer4);
                    *halfword70136Pointer4;
                }) > 0) {
                otherDecreasedHalfword = *halfword70136Pointer4 - 0x10;
                *halfword70136Pointer4 = otherDecreasedHalfword;
                if (otherDecreasedHalfword < 0) {
                    *halfword70136Pointer4 = 0;
                }
            }
            if (({
                    selectedHalfwordPointer16 = &Atlas_7A1A8_D_atlas_8007AE04;
                    MATCHING_KEEP(selectedHalfwordPointer16);
                    *selectedHalfwordPointer16;
                }) != 0) {
                if (Atlas_7A1A8_CDLoadTime() == 0) {
                    Atlas_7A1A8_func_atlas_80075F2C(*selectedHalfwordPointer16 - 1);
                    goto invokeSelectedCallback;
                }
            } else {
            invokeSelectedCallback:
                callback3 =
                    *(int (**)(void*, int, int))((unsigned char*)&Atlas_7A1A8_D_atlas_8007AF0C +
                                                 ((short)Atlas_7A1A8_D_atlas_8007ADE8 * 0x18));
                if (callback3 != 0) {
                    callbackOneArgument5 = 1;
                    MATCHING_KEEP(callbackOneArgument5);
                    callbackSignedIndex2 = (short)Atlas_7A1A8_D_atlas_8007ADEA;
                    callbackSignedWord6 = (short)Atlas_7A1A8_D_atlas_8007ADE4;
                    MATCHING_KEEP2(callbackSignedIndex2, callbackSignedWord6);
                    callbackByteOffset4 = callbackSignedIndex2 * 0x18;
                    callbackBaseByteAddress2 =
                        (int)((unsigned char*)selectedHalfwordPointer16 + 0x108);
                    callback3(callbackByteOffset4 + callbackBaseByteAddress2, callbackOneArgument5,
                              callbackSignedWord6);
                }
            }
            break;
    }
    return;
}
#undef Atlas_7A1A8_Field
