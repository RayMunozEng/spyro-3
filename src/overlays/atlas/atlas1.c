#include "matching.h"
#include "common.h"
#include "mobyutil.h"
#include "libgpu.h"
#include "hud.h"
#include "str.h"

/**
 * ???() - func_atlas_80075824()
 * https://decomp.me/scratch/mW9oc (better match, but needs cleaning)
 * https://decomp.me/scratch/eyxfk (worse match, but more condensed)
 */
extern signed char D_atlas_8007B1B0[];
extern unsigned char D_80066FCC[], D_80071FB0[];
int func_atlas_80075824(int level) {
    int result = -1;
    int index;
    if (level < 0x32) {
        for (index = 0; index < 0x27; index++)
            if (D_atlas_8007B1B0[index] == level)
                break;
        if (index < 0x27) {
            do {
                index++;
                if (D_80071FB0[D_80066FCC[D_atlas_8007B1B0[index]]])
                    break;
            } while (index < 0x28);
            if (index < 0x28)
                result = D_atlas_8007B1B0[index];
        }
    }
    return result;
}

extern signed char D_atlas_8007B1B0[];
extern unsigned char D_80066FCC[], D_80071FB0[];
int func_atlas_800758B0(int level) {
    int result = -1;
    int index;
    if (level >= 0xB) {
        for (index = 0; index < 0x27; index++)
            if (D_atlas_8007B1B0[index] == level)
                break;
        if (index > 0) {
            do {
                index--;
                if (D_80071FB0[D_80066FCC[D_atlas_8007B1B0[index]]])
                    break;
            } while (index >= 0);
            if (index >= 0)
                result = D_atlas_8007B1B0[index];
        }
    }
    return result;
}

extern int D_8006E470;
extern char* D_80070140;
extern WadHeader D_8006D8D8;
extern short D_atlas_8007ADEC[];
void func_atlas_8007594C(int index, int slot) {
    CDLoadAsync(D_8006E470, D_80070140 + slot * 0x4800, 0x4800,
                D_8006D8D8.atlasImgs.offset + index * 0x4800);
    D_atlas_8007ADEC[slot] = index;
}

extern short DecodedAtlasImageKeys[] __asm__("D_atlas_8007ADEC");
extern unsigned char* DecodedAtlasImageData __asm__("D_80070140");
/* SCUS-94467 Rev 0: atlas 0x800759CC..0x80075AD0.
 * Two original VRAM uploads; table entries and rectangle fields are signed
 * halfwords. Empty asm constraints preserve retail temporary lifetimes
 * without emitting instructions. AI generated; not yet human reviewed.
 */
void func_atlas_800759CC(int key, int slot) {
    RECT rectangle;
    register int retainedSlot __asm__("$17");
    register unsigned char* pixels __asm__("$16");
    register int wanted __asm__("$6") = key;
    register int index __asm__("$5");
    register short* base __asm__("$3");
    register short* cursor __asm__("$4");
    register int zeroArgument __asm__("$4");
    MATCHING_KEEP(wanted);
    retainedSlot = slot;
    MATCHING_KEEP(retainedSlot);
    index = 0;
    MATCHING_KEEP(index);
    base = DecodedAtlasImageKeys;
    cursor = base;
    do {
        register int current __asm__("$2") = *cursor;
        MATCHING_KEEP(current);
        if (current == wanted)
            break;
        index++;
        cursor++;
    } while (index < 3);
    zeroArgument = 0;
    MATCHING_KEEP(zeroArgument);
    base += 3;
    base[retainedSlot] = wanted;
    rectangle.x = 768;
    rectangle.y = retainedSlot + 126;
    rectangle.w = 256;
    rectangle.h = 1;
    pixels = DecodedAtlasImageData + index * 18432 + 28;
    DrawSync(zeroArgument);
    LoadImage(&rectangle, (unsigned long*)pixels);
    MATCHING_KEEP(pixels);
    pixels += 512;
    rectangle.x = 1024 - (80 << retainedSlot);
    rectangle.w = 80;
    rectangle.y = 0;
    rectangle.h = 100;
    DrawSync(0);
    LoadImage(&rectangle, (unsigned long*)pixels);
    DrawSync(0);
}

extern short DecodedAtlasSmallImageKeys[] __asm__("D_atlas_8007ADF2");
void DecodedAtlasDrawSmallSprite(SpriteData*, int, int) __asm__("func_800289C8");
/* SCUS-94467 USA Rev 0: atlas 0x80075AD4..0x80075C38.
 * Two signed-halfword keys; original byte UV and packed halfword fields.
 * A separate lookup temporary preserves the native loop's register lifetime.
 * Empty constraints emit no instructions. Caller cadence remains unresolved.
 * AI generated; not yet human reviewed.
 */
void func_atlas_80075AD4(int key, int xArgument, int yArgument) {
    SpriteData sprite;
    register int row __asm__("$16");
    register int y __asm__("$17");
    register int column __asm__("$18");
    register int left __asm__("$19");
    register int x __asm__("$20") = xArgument;
    register int texture __asm__("$21");
    register int right __asm__("$22");
    register int end __asm__("$23");
    int origin;
    register int wanted __asm__("$4") = key;
    register int index __asm__("$5");
    register short* cursor __asm__("$3");
    register int temporary __asm__("$2");
    MATCHING_KEEP(x);
    origin = yArgument;
    MATCHING_KEEP(origin);
    index = 0;
    cursor = DecodedAtlasSmallImageKeys;
    do {
        register int current __asm__("$2") = *cursor;
        MATCHING_KEEP(current);
        if (current == wanted)
            break;
        index++;
        cursor++;
    } while (index < 2);
    if (index < 2) {
        register int limit __asm__("$3");
        sprite.unk2 = ((index + 126) << 6) | 48;
        temporary = 80 << index;
        MATCHING_KEEP(temporary);
        limit = 1024;
        column = limit - temporary;
        temporary = index * 80;
        MATCHING_KEEP(temporary);
        limit -= temporary;
        if (column < limit) {
            end = limit;
            do {
                y = origin;
                row = 0;
                temporary = column & 63;
                MATCHING_KEEP(temporary);
                left = temporary * 2;
                right = left + 39;
                temporary = column & 1023;
                MATCHING_KEEP(temporary);
                texture = (temporary >> 6) | 224;
                do {
                    sprite.unk0 = left;
                    sprite.unk1 = row;
                    sprite.unk4 = right;
                    temporary = 80;
                    MATCHING_KEEP(temporary);
                    if (row == temporary) {
                        sprite.unk5 = 98;
                    } else {
                        sprite.unk5 = row + 19;
                    }
                    temporary = ((row & 256) >> 4) | texture;
                    MATCHING_KEEP(temporary);
                    {
                        register int bits __asm__("$3") = (row & 512) << 2;
                        sprite.unk6 = temporary | bits;
                    }
                    DecodedAtlasDrawSmallSprite(&sprite, x, y);
                    row += 20;
                    y += 20;
                } while (row < 100);
                column += 20;
                x += 40;
            } while (column < end);
        }
    }
}

extern char* D_80070140;
extern int D_8006E470;
extern WadHeader D_8006D8D8;
void func_atlas_80075C3C(int index) {
    CDLoadAsync(D_8006E470, D_80070140 + (index & 1) * 0xB800, 0xB800,
                D_8006D8D8.epilogueImgs.offset + index * 0xB800);
}

extern char* D_80070140;
void func_atlas_80075CA8(int page) {
    RECT rectangle;
    register unsigned char* image __asm__("$16");
    page &= 1;
    rectangle.x = 0x300;
    rectangle.y = page + 0xFE;
    rectangle.w = 0x100;
    rectangle.h = 1;
    image = (unsigned char*)D_80070140 + page * 0xB800 + 0x1C;
    DrawSync(0);
    LoadImage(&rectangle, (unsigned long*)image);
    MATCHING_KEEP(image);
    image += 0x200;
    rectangle.x = 0x400 - (0xC0 << page);
    rectangle.y = 0x80;
    rectangle.w = 0xC0;
    rectangle.h = 0x78;
    DrawSync(0);
    LoadImage(&rectangle, (unsigned long*)image);
    DrawSync(0);
}

int* DecodedAtlasDrawSprite(SpriteData*, int, int, int) __asm__("func_80028D30");
/* SCUS-94467 USA Rev 0: atlas 0x80075D78..0x80075EAC.
 * Original byte UV fields and halfword texture selectors; no coordinate conversion.
 * Empty constraints preserve native allocation and store ordering without code.
 * Caller cadence and sprite consumer interpretation remain unresolved.
 * AI generated; not yet human reviewed.
 */
void func_atlas_80075D78(int page, int xArgument, int yArgument, int side, int mode) {
    SpriteData sprite;
    volatile int savedY;
    int reserved1C;
    register int coefficient __asm__("$3");
    register int temporary __asm__("$2");
    register int row __asm__("$16");
    register int y __asm__("$17");
    register int column __asm__("$18");
    register int left __asm__("$19");
    register int x __asm__("$20") = xArgument;
    register int texture __asm__("$21");
    register int right __asm__("$22");
    register int drawMode __asm__("$23");
    int start;
    register int texturePage __asm__("$4");
    register int enabled __asm__("$2");
    page &= 1;
    MATCHING_KEEP(page);
    coefficient = 1 - side;
    MATCHING_KEEP(coefficient);
    temporary = coefficient * 96 + 1024;
    MATCHING_KEEP(temporary);
    coefficient = 192 << page;
    MATCHING_KEEP(coefficient);
    column = temporary - coefficient;
    texturePage = ((page + 254) << 6) | 48;
    MATCHING_KEEP(texturePage);
    start = column;
    MATCHING_KEEP(start);
    drawMode = mode;
    MATCHING_KEEP(drawMode);
    enabled = 1;
    savedY = yArgument;
    MATCHING_KEEP(enabled);
    sprite.unk2 = texturePage;
    if (enabled) {
        do {
            y = savedY;
            row = 128;
            temporary = column & 63;
            MATCHING_KEEP(temporary);
            left = temporary * 2;
            right = left + 31;
            temporary = column & 1023;
            MATCHING_KEEP(temporary);
            texture = (temporary >> 6) | 224;
            do {
                temporary = row + 19;
                MATCHING_KEEP(temporary);
                coefficient = ((row & 256) >> 4) | texture;
                MATCHING_KEEP(coefficient);
                sprite.unk5 = temporary;
                __asm__ volatile("" : : "m"(sprite.unk5));
                sprite.unk0 = left;
                sprite.unk1 = row;
                sprite.unk4 = right;
                coefficient |= (row & 512) << 2;
                MATCHING_OBSERVE_CLOBBER(coefficient, "$4");
                sprite.unk6 = coefficient;
                DecodedAtlasDrawSprite(&sprite, x, y, drawMode);
                row += 20;
                y += 20;
            } while (row < 248);
            column += 16;
            x += 32;
        } while (column < start + 96);
    }
}

extern int D_8006C58C, D_8006E470;
extern char* D_80070140;
extern LevelWadHeader D_80072098;
extern WadHeader D_8006D8D8;
extern short D_atlas_8007AE04;
void func_atlas_80075EB0(int index) {
    register int sectorOffset __asm__("$7") = index << 16;
    register int levelOffset __asm__("$2");
    register int combined __asm__("$3");
    register int sector __asm__("$4");
    register int length __asm__("$6");
    register char* buffer __asm__("$5");
    MATCHING_KEEP(sectorOffset);
    levelOffset = D_8006C58C;
    combined = D_80072098.vramSpu.offset;
    sector = D_8006E470;
    length = 0x10000;
    levelOffset = D_8006D8D8.lvl[levelOffset].lvl.offset;
    buffer = D_80070140;
    combined += levelOffset;
    __asm__(""
            : "=r"(combined), "=r"(sectorOffset)
            : "0"(combined), "1"(sectorOffset), "r"(sector), "r"(length), "r"(buffer));
    sectorOffset += 0x20000;
    CDLoadAsync(sector, buffer, length, combined + sectorOffset);
    D_atlas_8007AE04 = index + 1;
}

extern char* D_80070140;
extern short D_atlas_8007AE04;
void func_atlas_80075EB0(int);
void func_atlas_80075F2C(int slot) {
    RECT rectangle;
    char* data = D_80070140;
    rectangle.x = 0x200;
    rectangle.y = (slot << 6) + 0x80;
    rectangle.w = 0x200;
    rectangle.h = 0x40;
    DrawSync(0);
    LoadImage(&rectangle, (unsigned long*)data);
    DrawSync(0);
    if (slot)
        D_atlas_8007AE04 = 0;
    else
        func_atlas_80075EB0(1);
}

extern unsigned char D_atlas_8007AE0A;
int func_atlas_80075FBC(unsigned char value) {
    int glyph;
    value = D_atlas_8007AE0A ^ value;
    if ((unsigned char)(value - 'a') < 26)
        glyph = value - 31;
    else if ((unsigned char)(value - 'A') < 26)
        glyph = value + 27;
    else if ((unsigned char)(value - '0') < 10)
        glyph = value + 70;
    else if (value == 39)
        glyph = 0x80;
    else if (value == ':')
        glyph = 0x81;
    else if (value == ',')
        glyph = 0x82;
    else if (value == '!')
        glyph = 0x83;
    else if (value == '.')
        glyph = 0x84;
    else if (value == '?')
        glyph = 0x85;
    else if (value == '/')
        glyph = 0x86;
    else if (value == '%')
        glyph = 0x87;
    else if (value == '[')
        glyph = 0x9F;
    else if (value == ']')
        glyph = 0xA0;
    else if (value == '{')
        glyph = 0xA1;
    else if (value == '}')
        glyph = 0xA2;
    else if (value == '@')
        glyph = 0xA3;
    else
        glyph = -1;
    return glyph;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/atlas/atlas1", D_atlas_80074490);

/* AI generated; not human reviewed. Numeric mapping from original dispatch table. */
extern unsigned char Decoded2055Marker __asm__("D_atlas_8007AE0A");
int func_atlas_80076128(unsigned char argument) {
    int result;
    switch ((Decoded2055Marker ^ argument) & 255) {
        case 33:
            result = 0x88;
            break;
        case 63:
            result = 0x89;
            break;
        case 83:
            result = 0x8A;
            break;
        case 67:
            result = 0x8B;
            break;
        case 99:
            result = 0x8C;
            break;
        case 65:
            result = 0x91;
            break;
        case 97:
            result = 0x92;
            break;
        case 66:
            result = 0x93;
            break;
        case 98:
            result = 0x94;
            break;
        case 71:
            result = 0x8D;
            break;
        case 103:
            result = 0x8E;
            break;
        case 72:
            result = 0x8F;
            break;
        case 104:
            result = 0x90;
            break;
        case 85:
            result = 0x95;
            break;
        case 117:
            result = 0x96;
            break;
        case 86:
            result = 0x97;
            break;
        case 118:
            result = 0x98;
            break;
        case 73:
            result = 0x99;
            break;
        case 105:
            result = 0x9A;
            break;
        case 74:
            result = 0x9B;
            break;
        case 106:
            result = 0x9C;
            break;
        case 84:
            result = 0x9D;
            break;
        case 116:
            result = 0x9E;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}


extern short Atlas76228Marker __asm__("D_atlas_8007AE0A");
extern unsigned char Atlas76228Advance[] __asm__("D_atlas_8007B05C");
extern SpriteData* Atlas76228Sprites __asm__("D_80070108");
int Atlas76228Glyph(int) __asm__("func_atlas_80075FBC");
int Atlas76228Escape(unsigned char) __asm__("func_atlas_80076128");
/* AI generated; not human reviewed. Original atlas 0x80076228..0x8007642C.
 * Numeric glyph, bias, marker and packet chains are preserved. Helper meanings,
 * table producers, coordinate units and caller cadence remain unestablished.
 * Empty constraints preserve original masks; they emit no instructions.
 */
void func_atlas_80076228(unsigned char* text, int x, int y, int colour) {
    register unsigned int byte __asm__("$4");
    register int byteOrIndex __asm__("$16");
    register int glyph __asm__("$17");
    register int bias __asm__("$18");
    unsigned int advance;
    int offset;
    register int* packet __asm__("$4");
    register int comparison __asm__("$2");
    register int marker __asm__("$3");
    register SpriteData* sourceBase __asm__("$2");
    register unsigned int sourceOffset __asm__("$4");
    goto check;
    do {
        MATCHING_KEEP(byte);
        byteOrIndex = byte & 255;
        glyph = Atlas76228Glyph(byteOrIndex);
        if (glyph == 0xA3) {
            text++;
            glyph = Atlas76228Escape(*text);
            if (glyph == 0x92 || glyph == 0x8E || glyph == 0x94 || glyph == 0x90 || glyph == 0x9A)
                bias = -1;
            else if (glyph == 0x91 || glyph == 0x8D || glyph == 0x99 || glyph == 0x93 ||
                     glyph == 0x8F || glyph == 0x9B)
                bias = -4;
        } else {
            byteOrIndex ^= Atlas76228Marker;
            if (byteOrIndex == 0x67 || (unsigned int)(byteOrIndex - 0x70) < 2 ||
                byteOrIndex == 0x79)
                bias = 3;
            else if (byteOrIndex == 0x2E || byteOrIndex == 0x2C || byteOrIndex == 0x2F ||
                     byteOrIndex == 0x25)
                bias = 1;
        }
        byteOrIndex = glyph - 0x42;
        if (glyph >= 0) {
            advance = Atlas76228Advance[byteOrIndex];
            offset = 0;
            if (advance >= 0x80)
                offset = advance - 0x100;
            sourceBase = Atlas76228Sprites;
            sourceOffset = glyph * 8;
            packet = func_800289C8((SpriteData*)((unsigned char*)sourceBase + sourceOffset),
                                   x + offset, y + bias);
            comparison = glyph < 0x9F;
            MATCHING_KEEP(comparison);
            if (comparison)
                packet[1] = (packet[1] & 0xFF000000) | colour;
            advance = Atlas76228Advance[byteOrIndex];
            if (advance < 0x80)
                x += advance;
        } else
            x += 6;
        text++;
    check:
        byte = *text;
        marker = Atlas76228Marker;
        __asm__("" : "=r"(byte) : "0"(byte), "r"(marker));
        comparison = byte & 255;
        bias = 0;
    } while (comparison != marker);
}


extern unsigned char D_atlas_8007B01A[];
extern short DecodedAtlasTerminator __asm__("D_atlas_8007AE0A");
int func_atlas_80076128(unsigned char);
int DecodedAtlasGlyph(int) __asm__("func_atlas_80075FBC");
/* Exact original width loop; glyph and lookup semantics remain source-defined. */
int func_atlas_80076430(unsigned char* text) {
    int width = 0;
    int glyph;
    unsigned int byte;
    goto check;
    do {
        glyph = DecodedAtlasGlyph(byte);
        /* Escape 0xA3 consumes one additional input byte. */
        if (glyph == 163) {
            text++;
            glyph = func_atlas_80076128(*text);
        }
        if (glyph >= 0) {
            unsigned int widthByte = D_atlas_8007B01A[glyph];
            if (widthByte < 128)
                width += widthByte;
        } else
            width += 6;
        text++;
    check:
        /* Retail reads this byte once and compares its low byte to a signed halfword. */
        byte = *text;
        MATCHING_KEEP(byte);
    } while ((byte & 255) != DecodedAtlasTerminator);
    return width;
}

/* Numeric 32-bit address result: 0, 1, or one byte after a stored split marker. */
int func_atlas_800764DC(unsigned char* text, int maximumWidth) {
    int width = 0;
    int splitAddress = 0;
    int glyph;
    register int mask __asm__("$3");
    register unsigned int byte __asm__("$4");
    register short* terminator __asm__("$5");
    terminator = &DecodedAtlasTerminator;
    goto check;
    do {
        __asm__("" : "=r"(byte) : "0"(byte), "r"(width < maximumWidth) : "memory");
        if (width >= maximumWidth)
            goto finish;
        byte &= 255;
        mask = *terminator;
        /* Original marker test uses XOR with a fresh terminator halfword. */
        if ((byte ^ mask) == 32)
            splitAddress = (int)text;
        glyph = DecodedAtlasGlyph(byte);
        if (glyph == 163) {
            text++;
            glyph = func_atlas_80076128(*text);
        }
        if (glyph >= 0) {
            unsigned int widthByte = D_atlas_8007B01A[glyph];
            if (widthByte < 128)
                width += widthByte;
        } else
            width += 6;
        text++;
        terminator = &DecodedAtlasTerminator;
    check:
        byte = *text;
        __asm__("" : "=r"(byte) : "0"(byte), "r"(terminator));
    } while ((byte & 255) != *terminator);
    /* Reaching the terminator below the width limit returns numeric zero. */
    if (width < maximumWidth) {
        splitAddress = -1;
        goto result;
    }
finish:
    if (splitAddress)
        *(unsigned char*)splitAddress = (unsigned short)DecodedAtlasTerminator;
result:
    return splitAddress + 1;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/atlas/atlas1/func_atlas_800765F8.s SHA256 701d8c6b3c5dec27bc473e413d0063dce0a362b4d226fbd65dcfe9f8ec1719bb. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
int Atlas765F8_Call_func_atlas_80076228() __asm__("func_atlas_80076228");
int Atlas765F8_Call_func_atlas_80076430() __asm__("func_atlas_80076430");
#define Atlas765F8Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

extern unsigned char Atlas765F8_D_80066F54 __asm__("D_80066F54");
extern unsigned char Atlas765F8_D_80066F7C __asm__("D_80066F7C");
extern unsigned char Atlas765F8_D_80066FCC __asm__("D_80066FCC");
extern unsigned char Atlas765F8_D_80069CF8 __asm__("D_80069CF8");
extern int Atlas765F8_D_8006C76C __asm__("D_8006C76C");
extern int Atlas765F8_D_8006FBCC __asm__("D_8006FBCC");
extern unsigned char Atlas765F8_D_80070300 __asm__("D_80070300");
extern unsigned char Atlas765F8_D_8007158F __asm__("D_8007158F");
extern unsigned char Atlas765F8_D_80071A10 __asm__("D_80071A10");
extern unsigned char Atlas765F8_D_80071FB0 __asm__("D_80071FB0");
extern unsigned char Atlas765F8_D_atlas_8007A9FC __asm__("D_atlas_8007A9FC");
extern int Atlas765F8_D_atlas_8007AA18 __asm__("D_atlas_8007AA18");
extern int Atlas765F8_D_atlas_8007AA28 __asm__("D_atlas_8007AA28");
extern int Atlas765F8_D_atlas_8007ADFC __asm__("D_atlas_8007ADFC");

void func_atlas_800765F8(void* inputRecord, int sideWord, int inputModeWord) {
    register int modeWord20 __asm__("$20") = inputModeWord;
    void* wordTable30;
    register unsigned char* baseWord2 __asm__("$2");
    register unsigned char* stringTable17 __asm__("$17");
    register int indexWord2 __asm__("$2");
    register int addressWord3 __asm__("$3");
    /* Original frame is 0x50 bytes, with saved registers from SP+0x28.
     * SP+0x10 retains the side argument; SP+0x18 retains the row step.
     * Table offsets are byte offsets and table payloads use original LW.
     * Explicit entries retain the original branch targets and delay slots.
     * Empty constraints emit no instruction. Color interpretation, helper
     * contracts, coordinate units and caller cadence remain unresolved. */
    struct {
        int sp10, pad14, sp18, pad1C, pad20, pad24;
    } originalFrame;

    register int colorWord7 __asm__("$7");
    register int* headerPointer16 __asm__("$16");
    register void* wordCursor4 __asm__("$4");
    register int stringByteOffset16 __asm__("$16");
    register int rangeEnd3 __asm__("$3");
    register int tableByteOffset4 __asm__("$4");
    int selectedString4;
    register int groupIndex6 __asm__("$6");
    register int eligibleWord7 __asm__("$7");
    register int headerX19 __asm__("$19");
    register int rowX19 __asm__("$19");
    register int footerX19 __asm__("$19");
    register int rowY21 __asm__("$21");
    register int rowOrdinal23 __asm__("$23");
    register int var_v0 __asm__("$2");
    register unsigned char* entryCursor18 __asm__("$18");
    unsigned char groupTableIndex5;
    unsigned char temp_v0;
    register int entryByte3 __asm__("$3");
    register int limit6 __asm__("$6");
    register int shift2 __asm__("$2");
    register int flags3 __asm__("$3");
    register int renderX5 __asm__("$5");
    register int sentinel2 __asm__("$2");
    register int entryByte4 __asm__("$4");
    register int rangeIndex5 __asm__("$5");
    register int headerIndex22 __asm__("$22");
    register int rowBase22 __asm__("$22");
    register int tableIndex8 __asm__("$8");
    register int constant9 __asm__("$9");
    register unsigned int currentByte2 __asm__("$2");

    MATCHING_KEEP(modeWord20);
    entryCursor18 = inputRecord + 8;
    MATCHING_KEEP(entryCursor18);
    headerX19 = 0x172;
    __asm__("" : "=r"(headerX19) : "0"(headerX19), "r"(entryCursor18), "r"(modeWord20));
    originalFrame.sp10 = sideWord;
    if (sideWord != 0) {
        headerX19 = 0x8E;
    }
    headerIndex22 = Atlas765F8Field(inputRecord, unsigned char*, 8);
    rowY21 = 0x1E;
    if ((modeWord20 != 0) && (modeWord20 < 8)) {
        var_v0 = headerIndex22 - 1;
        __asm__("" : "=r"(var_v0) : "0"(var_v0), "r"(headerIndex22));
        headerIndex22 = var_v0 + modeWord20;
    }
    MATCHING_KEEP(rowY21);
    entryCursor18 = entryCursor18 + 1;
    baseWord2 = &Atlas765F8_D_atlas_8007A9FC;
    MATCHING_KEEP(baseWord2);
    headerPointer16 = (int*)(headerIndex22 * 4);
    __asm__("" : "=r"(headerPointer16) : "0"(headerPointer16), "r"(baseWord2));
    headerPointer16 = (int*)((unsigned char*)headerPointer16 + (unsigned int)baseWord2);
    rowOrdinal23 = 1;
    Atlas765F8_Call_func_atlas_80076228(
        *headerPointer16, headerX19 - (Atlas765F8_Call_func_atlas_80076430(*headerPointer16) >> 1),
        rowY21, 0x202020);
    constant9 = originalFrame.sp10;
    MATCHING_KEEP_VOLATILE(constant9);
    rowX19 = 0x10C;
    if (constant9 != 0) {
        rowX19 = 0x28;
    }
    if ((modeWord20 == 0) || (rowY21 = 0x37, ((modeWord20 < 5) == 0))) {
        rowY21 = 0x37;
        constant9 = 0x12;
        MATCHING_KEEP_VOLATILE(constant9);
        originalFrame.sp18 = constant9;
        rowBase22 = 0;
    } else {
        constant9 = 0x12;
        MATCHING_KEEP_VOLATILE(constant9);
        originalFrame.sp18 = constant9;
        rowBase22 = *(&Atlas765F8_D_80066FCC + (modeWord20 * 0xA));
    }
    entryByte4 = *entryCursor18;
    sentinel2 = 0xFF;
    __asm__("" : "=r"(entryByte4) : "0"(entryByte4), "r"(sentinel2));
    if ((entryByte4 & 0xFF) != sentinel2) {
        wordTable30 = &Atlas765F8_D_80071A10;
        MATCHING_KEEP(wordTable30);
        do {
            constant9 = 6;
            MATCHING_KEEP_VOLATILE(constant9);
            eligibleWord7 = 1;
            if (modeWord20 == constant9) {
                currentByte2 = entryByte4 & 0xFF;
                __asm__("" : "=r"(currentByte2) : "0"(currentByte2), "r"(entryByte4));
                tableIndex8 = *(&Atlas765F8_D_80066FCC + currentByte2);
                tableByteOffset4 = tableIndex8 * 4;
                goto checkSingleTableRow;
            }
            MATCHING_BARRIER_VOLATILE("$9");
            constant9 = 5;
            MATCHING_KEEP_VOLATILE(constant9);
            if (modeWord20 == constant9) {
                tableIndex8 = *(&Atlas765F8_D_80066FCC + *entryCursor18);
                tableByteOffset4 = tableIndex8 * 4;
                goto checkSingleTableRow;
            }
            if (modeWord20 != 0) {
                currentByte2 = *entryCursor18;
                MATCHING_KEEP(currentByte2);
                tableIndex8 = rowBase22 + currentByte2;
                goto directTableShift;
            }
            constant9 = 6;
            currentByte2 = *entryCursor18;
            MATCHING_KEEP(currentByte2);
            if (currentByte2 == constant9) {
                tableIndex8 = Atlas765F8Field(&Atlas765F8_D_80066FCC, unsigned char*, 0x32);
            directTableShift:
                tableByteOffset4 = tableIndex8 * 4;
            checkSingleTableRow:
                if ((Atlas765F8Field(tableByteOffset4, int*, (unsigned int)wordTable30) !=
                     (*(&Atlas765F8_D_80066F54 + tableIndex8) * 0x64)) ||
                    ((int)*(&Atlas765F8_D_80070300 + tableIndex8) <
                     ((eligibleWord7 << *(&Atlas765F8_D_80066F7C + tableIndex8)) - 1))) {
                    eligibleWord7 = 0;
                }
                goto selectRowColor;
            }
            MATCHING_BARRIER_VOLATILE("$9");
            constant9 = 5;
            MATCHING_KEEP_VOLATILE(constant9);
            groupIndex6 = 0x12;
            if (currentByte2 == constant9) {
                tableIndex8 = Atlas765F8Field(&Atlas765F8_D_80066FCC, unsigned char*, 0x12);
            checkGroupedTableRows:
                if (eligibleWord7 != 0) {
                    groupTableIndex5 = *(&Atlas765F8_D_80066FCC + groupIndex6);
                    if (Atlas765F8Field(wordTable30, int*, groupTableIndex5 * 4) !=
                        (*(&Atlas765F8_D_80066F54 + groupTableIndex5) * 0x64)) {
                        eligibleWord7 = 0;
                    } else {
                        MATCHING_BARRIER_VOLATILE("$9");
                        constant9 = 1;
                        MATCHING_KEEP_VOLATILE(constant9);
                        shift2 = *(&Atlas765F8_D_80066F7C + groupTableIndex5);
                        flags3 = *(&Atlas765F8_D_80070300 + groupTableIndex5);
                        __asm__("" : "=r"(flags3) : "0"(flags3), "r"(shift2));
                        shift2 = (constant9 << shift2) - 1;
                        flags3 = flags3 < shift2;
                        MATCHING_KEEP(flags3);
                        if (flags3)
                            eligibleWord7 = 0;
                    }
                    groupIndex6 += 0xA;
                    if (groupIndex6 < 0x31) {
                        goto checkGroupedTableRows;
                    }
                    goto selectRowColor;
                }
                goto selectUnavailableColor;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            currentByte2 = *entryCursor18;
            MATCHING_KEEP(currentByte2);
            rangeEnd3 = currentByte2 * 0xA;
            MATCHING_KEEP(rangeEnd3);
            tableIndex8 = *(&Atlas765F8_D_80066FCC + rangeEnd3);
            MATCHING_KEEP(tableIndex8);
            rangeEnd3 = tableIndex8 + 8;
            rangeIndex5 = tableIndex8;
            if ((int)tableIndex8 < rangeEnd3) {
                limit6 = rangeEnd3;
                __asm__("" : "=r"(limit6) : "0"(limit6), "r"(tableIndex8));
                var_v0 = tableIndex8 * 4;
                MATCHING_KEEP(var_v0);
                wordCursor4 = (void*)(var_v0 + (unsigned int)wordTable30);
            checkConsecutiveTableRows:
                if (eligibleWord7 != 0) {
                    if (Atlas765F8Field(wordCursor4, int*, 0) !=
                        (*(&Atlas765F8_D_80066F54 + rangeIndex5) * 0x64)) {
                        eligibleWord7 = 0;
                    } else {
                        MATCHING_BARRIER_VOLATILE("$9");
                        constant9 = 1;
                        MATCHING_KEEP_VOLATILE(constant9);
                        shift2 = *(&Atlas765F8_D_80066F7C + rangeIndex5);
                        flags3 = *(&Atlas765F8_D_80070300 + rangeIndex5);
                        __asm__("" : "=r"(flags3) : "0"(flags3), "r"(shift2));
                        shift2 = (constant9 << shift2) - 1;
                        flags3 = flags3 < shift2;
                        MATCHING_KEEP(flags3);
                        if (flags3)
                            eligibleWord7 = 0;
                    }
                    rangeIndex5 += 1;
                    wordCursor4 += 4;
                    if ((int)rangeIndex5 >= limit6) {
                        goto selectRowColor;
                    }
                    goto checkConsecutiveTableRows;
                }
                goto selectUnavailableColor;
            }
            goto selectRowColor;
        selectRowColor:
            if (eligibleWord7 != 0) {
                colorWord7 = 0xD8CCC;
            } else {
            selectUnavailableColor:
                colorWord7 = 0x78898C;
                if (*(&Atlas765F8_D_80071FB0 + tableIndex8) != 0) {
                    colorWord7 = 0x202020;
                }
            }
            renderX5 = rowX19;
            if (modeWord20 != 0) {
                stringTable17 = &Atlas765F8_D_80069CF8;
                MATCHING_KEEP_VOLATILE(stringTable17);
                indexWord2 = Atlas765F8_D_8006C76C;
                MATCHING_KEEP(indexWord2);
                stringByteOffset16 = tableIndex8 * 4;
                __asm__("" : "=r"(stringByteOffset16) : "0"(stringByteOffset16), "r"(indexWord2));
                addressWord3 = indexWord2 * 0xA0 + (unsigned int)stringTable17;
                __asm__("" : "=r"(addressWord3) : "0"(addressWord3), "r"(stringByteOffset16));
                addressWord3 = stringByteOffset16 + addressWord3;
                Atlas765F8_Call_func_atlas_80076228(Atlas765F8Field(addressWord3, int*, 0),
                                                    renderX5, rowY21, colorWord7);
                if (rowOrdinal23 == Atlas765F8_D_8006FBCC) {
                    indexWord2 = Atlas765F8_D_8006C76C;
                    addressWord3 = indexWord2 * 0xA0 + (unsigned int)stringTable17;
                    __asm__("" : "=r"(addressWord3) : "0"(addressWord3), "r"(stringByteOffset16));
                    addressWord3 = stringByteOffset16 + addressWord3;
                    selectedString4 = Atlas765F8Field(addressWord3, int*, 0);
                    goto storeSelectedStringExtent;
                }
            } else {
                entryByte3 = *entryCursor18;
                MATCHING_KEEP(entryByte3);
                MATCHING_BARRIER_VOLATILE("$9");
                constant9 = 6;
                MATCHING_KEEP_VOLATILE(constant9);
                var_v0 = entryByte3 * 4;
                if (entryByte3 == constant9) {
                    if (Atlas765F8_D_8007158F != 0) {
                        MATCHING_KEEP(entryByte3);
                        var_v0 = entryByte3 * 4;
                        goto drawZeroModeRow;
                    }
                } else {
                drawZeroModeRow:
                    Atlas765F8_Call_func_atlas_80076228(
                        Atlas765F8Field(&Atlas765F8_D_atlas_8007A9FC, int*, var_v0), renderX5,
                        rowY21, colorWord7);
                    var_v0 = Atlas765F8_D_8006FBCC;
                    MATCHING_KEEP(var_v0);
                    headerPointer16 = (int*)&Atlas765F8_D_atlas_8007A9FC;
                    __asm__("" : "=r"(headerPointer16) : "0"(headerPointer16), "r"(var_v0));
                    if (rowOrdinal23 == var_v0) {
                        selectedString4 =
                            Atlas765F8Field(headerPointer16, int*, *entryCursor18 * 4);
                    storeSelectedStringExtent:
                        Atlas765F8_D_atlas_8007ADFC =
                            rowX19 + Atlas765F8_Call_func_atlas_80076430(selectedString4);
                    }
                }
            }
            entryCursor18 += 1;
            rowOrdinal23 += 1;
            sentinel2 = 0xFF;
            MATCHING_KEEP(sentinel2);
            constant9 = originalFrame.sp18;
            MATCHING_KEEP_VOLATILE(constant9);
            entryByte4 = *entryCursor18;
            __asm__("" : "=r"(entryByte4) : "0"(entryByte4), "r"(sentinel2), "r"(constant9));
            rowY21 += constant9;
        } while ((entryByte4 & 0xFF) != sentinel2);
    }
    if (modeWord20 == 0) {
        headerPointer16 = &Atlas765F8_D_atlas_8007AA18;
        MATCHING_KEEP(headerPointer16);
        Atlas765F8_Call_func_atlas_80076228(
            *headerPointer16, 0xE5 - Atlas765F8_Call_func_atlas_80076430(*headerPointer16), rowY21,
            0x2020A0);
        if (Atlas765F8_D_8007158F != 0) {
            constant9 = originalFrame.sp10;
            MATCHING_KEEP_VOLATILE(constant9);
            footerX19 = 0x1D8;
            if (constant9 != 0) {
                footerX19 = 0xF4;
            }
            Atlas765F8_Call_func_atlas_80076228(
                Atlas765F8_D_atlas_8007AA28,
                footerX19 - Atlas765F8_Call_func_atlas_80076430(Atlas765F8_D_atlas_8007AA28), 0xC4,
                0x202020);
        }
    }
}
#undef Atlas765F8Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Atlas_76B64_SignedHigh(a, b)                                             \
    ({                                                                           \
        int high;                                                                \
        __asm__ volatile("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                    \
    })
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/atlas/atlas1/func_atlas_80076B64.s SHA256 b6705d41156aa2170af3cba8f305a54b16ffc0c68f90e562a0329097713e55ef. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
int Atlas_76B64_func_80028D30() __asm__("func_80028D30");
int Atlas_76B64_func_80038B44() __asm__("func_80038B44");
int Atlas_76B64_func_atlas_80076228() __asm__("func_atlas_80076228");
int Atlas_76B64_func_atlas_80076430() __asm__("func_atlas_80076430");
int Atlas_76B64_sprintf() __asm__("sprintf");
#define Atlas_76B64_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int Atlas_76B64_D_8006581C __asm__("D_8006581C");
extern unsigned char Atlas_76B64_D_80066F54 __asm__("D_80066F54");
extern unsigned char Atlas_76B64_D_80066F7C __asm__("D_80066F7C");
extern unsigned char Atlas_76B64_D_80066FA4 __asm__("D_80066FA4");
extern unsigned char Atlas_76B64_D_80066FCC __asm__("D_80066FCC");
extern int Atlas_76B64_D_80070108 __asm__("D_80070108");
extern unsigned char Atlas_76B64_D_80070300 __asm__("D_80070300");
extern unsigned char Atlas_76B64_D_8007158F __asm__("D_8007158F");
extern unsigned char Atlas_76B64_D_80071A10 __asm__("D_80071A10");
extern unsigned char Atlas_76B64_D_80071FB0 __asm__("D_80071FB0");
extern unsigned char Atlas_76B64_D_atlas_800757B8 __asm__("D_atlas_800757B8");
extern unsigned char Atlas_76B64_D_atlas_800757BC __asm__("D_atlas_800757BC");
extern unsigned char Atlas_76B64_D_atlas_800757C0 __asm__("D_atlas_800757C0");
extern int Atlas_76B64_D_atlas_8007AA1C __asm__("D_atlas_8007AA1C");
extern unsigned char* Atlas_76B64_D_atlas_8007AA20 __asm__("D_atlas_8007AA20");
extern unsigned char* Atlas_76B64_D_atlas_8007AA24 __asm__("D_atlas_8007AA24");
extern int Atlas_76B64_D_atlas_8007AE00 __asm__("D_atlas_8007AE00");
extern short Atlas_76B64_D_atlas_8007AE0E __asm__("D_atlas_8007AE0E");
void func_atlas_80076B64(unsigned char* recordBytes, int argument5, int argument6, int argument7) {
    /* SCUS-94467 USA Rev0 80076B64; original source SHA256 above.
    * 669 original instruction words; original C8-byte stack frame, with
    * saved16..23 at A0..BC, FP/C0 and RA/C4. Explicit frame fields retain
    * original byte offsets; textBuffer occupies SP18..SP2F (24 bytes).
    * recordBytes advances by BYTES: +9 initially, then exactly +1 before
    * each next LBU. The FF sentinel compares the original masked byte.
    * 71A10 is accessed with WORD loads at mappedIndex*4. F54, F7C, FA4,
    * FFCC and 70300 retain original unsigned BYTE loads. Register sums
    * remain full words; bit counts retain the original nonnegative SRA.
    * Signed reciprocal products /14, /6 and /10 consume identified MULT
    * operands. rowHigh is defined by that product before its later HI
    * constraint; no incoming HI/LO value is assumed. Integer percentage
    * retains the original multiply-by100 chains and guarded signed DIV.
    * Empty constraints only preserve initialized producers or place dead
    * scratch boundaries before their original replacement producers.
    * Memory-only boundaries preserve the original independent load-delay
    * fillers. No emitted CPU assembly or instruction patch is introduced.
    * Format data at 757B8/757BC/757C0 is "%d/", "%d", "%d%c %s".
    * The AA1C string's complete producer and length remain unresolved;
    * this reproduces the original caller, without a buffer-safety claim.
    * Caller aliases project original registers only; complete helper,
    * table producer, asset and SFX meanings remain unresolved. Text/color
    * words are original values, not newly inferred physical conversions.
    * Cadence is per invocation; frame frequency, physical units/fixed point
    * and synchronized runtime verification remain open evidence needs.
    * Confidence requires exact native/linked words and every conditional
    * and internal jump target, plus full EXE and every-overlay retail hash.
    * No engine/browser or subsystem completion claim. AI generated;
    * not human reviewed. */
    register unsigned char* formatPointer16 __asm__("$16");
    register unsigned char* formatPointer17 __asm__("$17");
    register unsigned char** footerWord16 __asm__("$16");
    register int* tablePointer8 __asm__("$8");
    register int* tablePointer9 __asm__("$9");
    int rowHigh;
    register int signedWord4 __asm__("$4");
    register int callerWord4 __asm__("$4");
    register int callerWord5 __asm__("$5");
    register int callerWord6 __asm__("$6");
    register int callerWord7 __asm__("$7");
    register int highWord8 __asm__("$8");
    register int highWord9 __asm__("$9");
    register int* bankWord18 __asm__("$18");
    register int inputWord3 __asm__("$3");
    register int quotientWord2 __asm__("$2");
    struct {
        unsigned char textBuffer[24];
        int savedArgument5;
        unsigned char pad34[4];
        int savedArgument6;
        unsigned char pad3C[4];
        int savedArgument7;
        unsigned char pad44[4];
        int rowPositionWord;
        unsigned char pad4C[4];
        int rowStepWord;
        unsigned char pad54[4];
        int sumByteF7C;
        unsigned char pad5C[4];
        int sumByteF54Times100;
        unsigned char pad64[4];
        int sumFlagBitCount;
        unsigned char pad6C[4];
        int sumWord71A10;
        unsigned char pad74[4];
        int sumScaledHelperReturn;
        unsigned char pad7C[4];
        int rowSelector80;
        unsigned char pad84[4];
        int rawSelector88;
        unsigned char pad8C[4];
        int rightTextOffsetWord;
        unsigned char pad94[4];
        unsigned char* rowByteCursor;
        unsigned char pad9C[4];
    } frame;
    register unsigned char* footerText4 __asm__("$4");
    register int footerY6 __asm__("$6");
    register int rowCount100_18 __asm__("$18");
    register int rowByteOffset23 __asm__("$23");
    register int rowRemainder5 __asm__("$5");
    register int footerOffset5 __asm__("$5");
    register int flagsCountA6 __asm__("$6");
    register int flagsCountB6 __asm__("$6");
    register int flagsCountC6 __asm__("$6");
    register int percentage6 __asm__("$6");
    register int rowArgument7 __asm__("$7");
    int textBaseWord;
    register int remainder14_17 __asm__("$17");
    register int mappedRowIndex17 __asm__("$17");
    register int columnIndex17 __asm__("$17");
    register int leftTextColor17 __asm__("$17");
    register int rightTextColor17 __asm__("$17");
    register int setBitCount19 __asm__("$19");
    register int bankWord20 __asm__("$20");
    register int rowByte21 __asm__("$21");
    register int twiceByteF54_2 __asm__("$2");
    register int bitA2 __asm__("$2");
    register int bitB2 __asm__("$2");
    register int scaledReturnA2 __asm__("$2");
    register int bitC2 __asm__("$2");
    register int scaledReturnB2 __asm__("$2");
    register int bitD2 __asm__("$2");
    register int scaledReturnC2 __asm__("$2");
    register int textPredicate2 __asm__("$2");
    register int factorA4 __asm__("$4");
    register int factorB4 __asm__("$4");
    register int factorC4 __asm__("$4");
    register int mappedIndexA16 __asm__("$16");
    register int mappedIndexB16 __asm__("$16");
    register int mappedIndexC16 __asm__("$16");
    register int rowByte4 __asm__("$4");
    register int flagsA4 __asm__("$4");
    register int flagsB4 __asm__("$4");
    register int flagsC4 __asm__("$4");
    register int flagsD4 __asm__("$4");
    register int mappedIndex16 __asm__("$16");
    register int byteF54_18 __asm__("$18");
    register int byteF7C22 __asm__("$22");
    mappedIndex16 = 0;
    recordBytes += 9;
    MATCHING_KEEP(recordBytes);
    textBaseWord = 0x10C;
    frame.savedArgument5 = argument5;
    frame.savedArgument6 = argument6;
    frame.savedArgument7 = argument7;
    frame.rawSelector88 = 0;
    frame.rowByteCursor = recordBytes;
    if (argument5 != 0) {
        textBaseWord = 0x28;
    }
    quotientWord2 = (int)0x92492493;
    inputWord3 = Atlas_76B64_D_atlas_8007AE00;
    highWord8 = Atlas_76B64_SignedHigh(inputWord3, quotientWord2);
    signedWord4 = inputWord3 >> 31;
    quotientWord2 = highWord8 + inputWord3;
    quotientWord2 >>= 3;
    remainder14_17 = quotientWord2 - signedWord4;
    MATCHING_KEEP(remainder14_17);
    quotientWord2 = remainder14_17 * 14;
    remainder14_17 = inputWord3 - quotientWord2;
    if (remainder14_17 >= 8) {
        remainder14_17 = 0xE - remainder14_17;
    }
    quotientWord2 = 0x2AAAAAAB;
    highWord9 = Atlas_76B64_SignedHigh(inputWord3, quotientWord2);
    callerWord5 = textBaseWord + 0x2D;
    callerWord6 = 30;
    MATCHING_KEEP2_CLOBBER(callerWord5, callerWord6, "$18");
    bankWord18 = &Atlas_76B64_D_80070108;
    MATCHING_KEEP_CLOBBER(bankWord18, "memory");
    callerWord7 = frame.savedArgument7;
    MATCHING_KEEP(callerWord7);
    quotientWord2 = highWord9 - signedWord4;
    MATCHING_KEEP(quotientWord2);
    callerWord4 = quotientWord2 * 6;
    callerWord4 = inputWord3 - callerWord4;
    callerWord4 <<= 3;
    __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$2", "memory");
    quotientWord2 = *bankWord18;
    MATCHING_BARRIER("memory");
    callerWord4 += 0x100;
    Atlas_76B64_func_80028D30(quotientWord2 + callerWord4, callerWord5, callerWord6, callerWord7);
    highWord8 = frame.savedArgument6;
    callerWord5 = textBaseWord + 0x82;
    if (highWord8 == 0)
        callerWord5 = textBaseWord + 0x96;
    callerWord6 = 30;
    MATCHING_KEEP_CLOBBER(callerWord6, "$4");
    callerWord4 = remainder14_17 << 3;
    callerWord4 += 0x130;
    quotientWord2 = *bankWord18;
    callerWord7 = frame.savedArgument7;
    Atlas_76B64_func_80028D30(quotientWord2 + callerWord4, callerWord5, callerWord6, callerWord7);
    highWord9 = frame.savedArgument6;
    if (highWord9 == 0) {
        highWord8 = 55;
        highWord9 = 18;
        frame.rowPositionWord = highWord8;
        highWord8 = 170;
        frame.rowStepWord = highWord9;
        frame.rightTextOffsetWord = highWord8;
    } else {
        highWord9 = 55;
        highWord8 = 18;
        frame.rowPositionWord = highWord9;
        highWord9 = 150;
        frame.rowStepWord = highWord8;
        frame.rightTextOffsetWord = highWord9;
    }
    highWord8 = (int)frame.rowByteCursor;
    frame.sumByteF54Times100 = 0;
    frame.sumWord71A10 = 0;
    frame.sumByteF7C = 0;
    frame.sumFlagBitCount = 0;
    rowByte4 = Atlas_76B64_Field(highWord8, unsigned char*, 0);
    __asm__("" : : : "$2", "memory");
    quotientWord2 = 255;
    MATCHING_KEEP2(rowByte4, quotientWord2);
    inputWord3 = rowByte4 & 255;
    frame.sumScaledHelperReturn = 0;
    if (inputWord3 != quotientWord2) {
        do {
            highWord9 = frame.savedArgument6;
            MATCHING_KEEP_CLOBBER(rowByte4, "memory");
            rowByte21 = rowByte4 & 0xFF;
            frame.rowSelector80 = 0;
            if ((highWord9 != 0) && (highWord9 < 8)) {
                if (highWord9 < 5) {
                    inputWord3 = rowByte21 - 10;
                    quotientWord2 = highWord9 * 10;
                    rowByte21 = inputWord3 + quotientWord2;
                }
                quotientWord2 = 0x66666667;
                rowHigh = Atlas_76B64_SignedHigh(rowByte21, quotientWord2);
                mappedIndex16 = *(&Atlas_76B64_D_80066FCC + rowByte21);
                __asm__("" : : : "$8", "memory");
                tablePointer8 = (int*)&Atlas_76B64_D_80071A10;
                MATCHING_KEEP_CLOBBER(tablePointer8, "memory");
                quotientWord2 = mappedIndex16 << 2;
                quotientWord2 += (int)tablePointer8;
                MATCHING_KEEP_CLOBBER(quotientWord2, "memory");
                bankWord20 = Atlas_76B64_Field(quotientWord2, int*, 0);
                __asm__("" : : : "$2", "memory");
                quotientWord2 = rowByte21 >> 31;
                byteF54_18 = *(&Atlas_76B64_D_80066F54 + mappedIndex16);
                byteF7C22 = *(&Atlas_76B64_D_80066F7C + mappedIndex16);
                flagsA4 = *(&Atlas_76B64_D_80070300 + mappedIndex16);
                __asm__("" : "=h"(rowHigh) : "0"(rowHigh) : "memory");
                highWord9 = rowHigh;
                inputWord3 = highWord9 >> 2;
                rowRemainder5 = inputWord3 - quotientWord2;
                MATCHING_KEEP(rowRemainder5);
                inputWord3 = rowRemainder5;
                quotientWord2 = inputWord3 * 10;
                rowRemainder5 = rowByte21 - quotientWord2;
                quotientWord2 = (unsigned int)(rowRemainder5 - 1) < 4U;
                MATCHING_KEEP_CLOBBER(quotientWord2, "$19");
                setBitCount19 = 0;
                if (quotientWord2 != 0)
                    goto rowIcon;
                highWord8 = 6;
                if (rowRemainder5 != highWord8)
                    goto rowBits;
            rowIcon:
                highWord9 = 6;
                quotientWord2 = inputWord3 - 1;
                if (rowRemainder5 == highWord9)
                    rowRemainder5 = 5;
                MATCHING_KEEP(quotientWord2);
                inputWord3 = quotientWord2 * 5;
                inputWord3 += 45;
                MATCHING_KEEP(inputWord3);
                rowRemainder5 += inputWord3;
                highWord8 = 1;
                quotientWord2 = flagsA4 & 1;
                frame.rawSelector88 = rowRemainder5;
                MATCHING_BARRIER("memory");
                frame.rowSelector80 = highWord8;
                if (quotientWord2 != 0) {
                    highWord9 = 2;
                    frame.rowSelector80 = highWord9;
                }
            rowBits:
                twiceByteF54_2 = byteF54_18 * 2;
                if (flagsA4 != 0) {
                    bitA2 = flagsA4 & 1;
                    do {
                        if (bitA2 != 0) {
                            setBitCount19 += 1;
                        }
                        flagsA4 = (flagsA4 >> 1);
                        bitA2 = flagsA4 & 1;
                    } while (flagsA4 != 0);
                    twiceByteF54_2 = byteF54_18 * 2;
                }
            } else {
                highWord8 = 6;
                if (rowByte21 == highWord8) {
                    byteF54_18 = 0;
                    byteF7C22 = 0;
                    bankWord20 = 0;
                    setBitCount19 = 0;
                    if (Atlas_76B64_D_8007158F != 0) {
                        mappedIndexA16 =
                            Atlas_76B64_Field(&Atlas_76B64_D_80066FCC, unsigned char*, 0x32);
                        __asm__("" : : : "$9", "memory");
                        tablePointer9 = (int*)&Atlas_76B64_D_80071A10;
                        MATCHING_KEEP_CLOBBER(tablePointer9, "memory");
                        quotientWord2 = mappedIndexA16 << 2;
                        quotientWord2 += (int)tablePointer9;
                        byteF54_18 = *(&Atlas_76B64_D_80066F54 + mappedIndexA16);
                        byteF7C22 = *(&Atlas_76B64_D_80066F7C + mappedIndexA16);
                        flagsB4 = *(&Atlas_76B64_D_80070300 + mappedIndexA16);
                        bankWord20 = Atlas_76B64_Field(quotientWord2, int*, 0);
                        flagsCountA6 = 0;
                        if (flagsB4 != 0) {
                            bitB2 = flagsB4 & 1;
                            do {
                                if (bitB2 != 0) {
                                    flagsCountA6 += 1;
                                }
                                flagsB4 = (flagsB4 >> 1);
                                bitB2 = flagsB4 & 1;
                            } while (flagsB4 != 0);
                        }
                        MATCHING_KEEP(setBitCount19);
                        setBitCount19 += flagsCountA6;
                        quotientWord2 = mappedIndexA16 << 2;
                        MATCHING_KEEP_CLOBBER(quotientWord2, "$8");
                        tablePointer8 = (int*)&Atlas_76B64_D_80071A10;
                        MATCHING_KEEP_CLOBBER(tablePointer8, "memory");
                        quotientWord2 += (int)tablePointer8;
                        callerWord5 = Atlas_76B64_Field(quotientWord2, int*, 0);
                        scaledReturnA2 = Atlas_76B64_func_80038B44((int)mappedIndexA16, callerWord5,
                                                                   flagsCountA6);
                        factorA4 = *(&Atlas_76B64_D_80066FA4 + mappedIndexA16);
                        if (factorA4 != 0) {
                            scaledReturnA2 *= factorA4;
                        }
                        highWord8 = frame.sumScaledHelperReturn;
                        mappedIndex16 =
                            Atlas_76B64_Field(&Atlas_76B64_D_80066FCC, unsigned char*, 0x32);
                        highWord8 += scaledReturnA2;
                        frame.sumScaledHelperReturn = highWord8;
                    }
                    goto scaleRowCount;
                }
                if (rowByte21 == 5) {
                    byteF54_18 = 0;
                    byteF7C22 = 0;
                    bankWord20 = 0;
                    setBitCount19 = 0;
                    mappedRowIndex17 = 0x12;
                    do {
                        flagsCountB6 = 0;
                        mappedIndexB16 = *(&Atlas_76B64_D_80066FCC + mappedRowIndex17);
                        __asm__("" : : : "$9", "memory");
                        tablePointer9 = (int*)&Atlas_76B64_D_80071A10;
                        MATCHING_KEEP_CLOBBER(tablePointer9, "memory");
                        quotientWord2 = *(&Atlas_76B64_D_80066F54 + mappedIndexB16);
                        flagsC4 = *(&Atlas_76B64_D_80070300 + mappedIndexB16);
                        inputWord3 = *(&Atlas_76B64_D_80066F7C + mappedIndexB16);
                        byteF54_18 += quotientWord2;
                        quotientWord2 = mappedIndexB16 << 2;
                        quotientWord2 += (int)tablePointer9;
                        quotientWord2 = Atlas_76B64_Field(quotientWord2, int*, 0);
                        byteF7C22 += inputWord3;
                        bankWord20 += quotientWord2;
                        if (flagsC4 != 0) {
                            bitC2 = flagsC4 & 1;
                            do {
                                if (bitC2 != 0) {
                                    flagsCountB6 += 1;
                                }
                                flagsC4 = (flagsC4 >> 1);
                                bitC2 = flagsC4 & 1;
                            } while (flagsC4 != 0);
                        }
                        setBitCount19 += flagsCountB6;
                        quotientWord2 = mappedIndexB16 << 2;
                        MATCHING_KEEP_CLOBBER(quotientWord2, "$8");
                        tablePointer8 = (int*)&Atlas_76B64_D_80071A10;
                        MATCHING_KEEP_CLOBBER(tablePointer8, "memory");
                        quotientWord2 += (int)tablePointer8;
                        callerWord5 = Atlas_76B64_Field(quotientWord2, int*, 0);
                        scaledReturnB2 = Atlas_76B64_func_80038B44((int)mappedIndexB16, callerWord5,
                                                                   flagsCountB6);
                        factorB4 = *(&Atlas_76B64_D_80066FA4 + mappedIndexB16);
                        if (factorB4 != 0) {
                            scaledReturnB2 *= factorB4;
                        }
                        highWord8 = frame.sumScaledHelperReturn;
                        mappedRowIndex17 += 0xA;
                        highWord8 += scaledReturnB2;
                        frame.sumScaledHelperReturn = highWord8;
                    } while ((quotientWord2 = mappedRowIndex17 < 0x31));
                    mappedIndex16 =
                        Atlas_76B64_Field(&Atlas_76B64_D_80066FCC, unsigned char*, 0x12);
                    twiceByteF54_2 = byteF54_18 * 2;
                } else {
                    quotientWord2 = rowByte21 * 5;
                    MATCHING_KEEP(quotientWord2);
                    rowByteOffset23 = quotientWord2 << 1;
                    byteF54_18 = 0;
                    byteF7C22 = 0;
                    bankWord20 = 0;
                    setBitCount19 = 0;
                    columnIndex17 = 0;
                    do {
                        quotientWord2 = rowByteOffset23 + columnIndex17;
                        MATCHING_KEEP_CLOBBER(quotientWord2, "$9");
                        highWord9 = (int)&Atlas_76B64_D_80066FCC;
                        MATCHING_KEEP(highWord9);
                        quotientWord2 += highWord9;
                        MATCHING_KEEP_CLOBBER(quotientWord2, "$6");
                        flagsCountC6 = 0;
                        mappedIndexC16 = Atlas_76B64_Field(quotientWord2, unsigned char*, 0);
                        __asm__("" : : : "$8", "memory");
                        tablePointer8 = (int*)&Atlas_76B64_D_80071A10;
                        MATCHING_KEEP_CLOBBER(tablePointer8, "memory");
                        quotientWord2 = *(&Atlas_76B64_D_80066F54 + mappedIndexC16);
                        flagsD4 = *(&Atlas_76B64_D_80070300 + mappedIndexC16);
                        inputWord3 = *(&Atlas_76B64_D_80066F7C + mappedIndexC16);
                        byteF54_18 += quotientWord2;
                        quotientWord2 = mappedIndexC16 << 2;
                        quotientWord2 += (int)tablePointer8;
                        quotientWord2 = Atlas_76B64_Field(quotientWord2, int*, 0);
                        byteF7C22 += inputWord3;
                        bankWord20 += quotientWord2;
                        if (flagsD4 != 0) {
                            bitD2 = flagsD4 & 1;
                            do {
                                if (bitD2 != 0) {
                                    flagsCountC6 += 1;
                                }
                                flagsD4 = (flagsD4 >> 1);
                                bitD2 = flagsD4 & 1;
                            } while (flagsD4 != 0);
                        }
                        setBitCount19 += flagsCountC6;
                        quotientWord2 = mappedIndexC16 << 2;
                        MATCHING_KEEP_CLOBBER(quotientWord2, "$9");
                        tablePointer9 = (int*)&Atlas_76B64_D_80071A10;
                        MATCHING_KEEP_CLOBBER(tablePointer9, "memory");
                        quotientWord2 += (int)tablePointer9;
                        callerWord5 = Atlas_76B64_Field(quotientWord2, int*, 0);
                        scaledReturnC2 = Atlas_76B64_func_80038B44((int)mappedIndexC16, callerWord5,
                                                                   flagsCountC6);
                        factorC4 = *(&Atlas_76B64_D_80066FA4 + mappedIndexC16);
                        if (factorC4 != 0) {
                            scaledReturnC2 *= factorC4;
                        }
                        highWord8 = frame.sumScaledHelperReturn;
                        columnIndex17 += 1;
                        highWord8 += scaledReturnC2;
                        frame.sumScaledHelperReturn = highWord8;
                    } while ((quotientWord2 = columnIndex17 < 8));
                    mappedIndex16 = *(&Atlas_76B64_D_80066FCC + rowByteOffset23);
                scaleRowCount:
                    twiceByteF54_2 = byteF54_18 * 2;
                }
            }
            rowCount100_18 = (((twiceByteF54_2 + byteF54_18) * 8) + byteF54_18) * 4;
            highWord9 = 6;
            if (rowByte21 != highWord9) {
                highWord8 = frame.sumByteF54Times100;
                highWord9 = frame.sumByteF7C;
                highWord8 += rowCount100_18;
                frame.sumByteF54Times100 = highWord8;
                MATCHING_BARRIER("memory");
                highWord9 += byteF7C22;
                frame.sumByteF7C = highWord9;
            }
            highWord8 = frame.sumWord71A10;
            highWord9 = frame.sumFlagBitCount;
            highWord8 += bankWord20;
            highWord9 += setBitCount19;
            frame.sumWord71A10 = highWord8;
            highWord8 = 6;
            frame.sumFlagBitCount = highWord9;
            if ((rowByte21 != highWord8) || (Atlas_76B64_D_8007158F != 0)) {
                textPredicate2 = setBitCount19 < (int)byteF7C22;
                if (rowCount100_18 != 0) {
                    if (bankWord20 == rowCount100_18) {
                        leftTextColor17 = 0xD8CCC;
                    } else {
                        leftTextColor17 = 0x78898C;
                        if (*(&Atlas_76B64_D_80071FB0 + mappedIndex16) != 0) {
                            leftTextColor17 = 0x202020;
                        }
                    }
                    Atlas_76B64_sprintf(frame.textBuffer, &Atlas_76B64_D_atlas_800757B8,
                                        bankWord20);
                    quotientWord2 = Atlas_76B64_func_atlas_80076430(frame.textBuffer);
                    inputWord3 = 66;
                    MATCHING_KEEP(inputWord3);
                    inputWord3 -= quotientWord2;
                    callerWord4 = (int)frame.textBuffer;
                    __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
                    callerWord5 = textBaseWord + inputWord3;
                    callerWord6 = frame.rowPositionWord;
                    Atlas_76B64_func_atlas_80076228((void*)callerWord4, callerWord5, callerWord6,
                                                    leftTextColor17);
                    Atlas_76B64_sprintf(frame.textBuffer, &Atlas_76B64_D_atlas_800757BC,
                                        rowCount100_18);
                    callerWord4 = (int)frame.textBuffer;
                    __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
                    callerWord5 = textBaseWord + 66;
                    callerWord6 = frame.rowPositionWord;
                    Atlas_76B64_func_atlas_80076228((void*)callerWord4, callerWord5, callerWord6,
                                                    leftTextColor17);
                    textPredicate2 = setBitCount19 < (int)byteF7C22;
                }
                if (textPredicate2 == 0) {
                    rightTextColor17 = 0xD8CCC;
                } else {
                    rightTextColor17 = 0x78898C;
                    if (*(&Atlas_76B64_D_80071FB0 + mappedIndex16) != 0) {
                        rightTextColor17 = 0x202020;
                    }
                }
                Atlas_76B64_sprintf(frame.textBuffer, &Atlas_76B64_D_atlas_800757B8, setBitCount19);
                quotientWord2 = Atlas_76B64_func_atlas_80076430(frame.textBuffer);
                callerWord4 = (int)frame.textBuffer;
                __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
                callerWord7 = rightTextColor17;
                highWord9 = frame.rightTextOffsetWord;
                callerWord6 = frame.rowPositionWord;
                inputWord3 = highWord9 - quotientWord2;
                Atlas_76B64_func_atlas_80076228((void*)callerWord4, textBaseWord + inputWord3,
                                                callerWord6, callerWord7);
                Atlas_76B64_sprintf(frame.textBuffer, &Atlas_76B64_D_atlas_800757BC,
                                    (int)byteF7C22);
                callerWord4 = (int)frame.textBuffer;
                __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
                callerWord7 = rightTextColor17;
                highWord8 = frame.rightTextOffsetWord;
                callerWord6 = frame.rowPositionWord;
                Atlas_76B64_func_atlas_80076228((void*)callerWord4, textBaseWord + highWord8,
                                                callerWord6, callerWord7);
                highWord9 = frame.rowSelector80;
                if (highWord9 != 0) {
                    quotientWord2 = 2;
                    callerWord5 = textBaseWord + 175;
                    if (highWord9 == quotientWord2) {
                        rowArgument7 = frame.savedArgument7;
                    } else {
                        highWord8 = frame.savedArgument7;
                        rowArgument7 = highWord8 | 16;
                    }
                    highWord9 = frame.rowPositionWord;
                    quotientWord2 = Atlas_76B64_D_80070108;
                    highWord8 = frame.rawSelector88;
                    callerWord6 = highWord9 - 4;
                    callerWord4 = highWord8 << 3;
                    Atlas_76B64_func_80028D30(quotientWord2 + callerWord4, callerWord5, callerWord6,
                                              rowArgument7);
                }
            }
            highWord9 = (int)frame.rowByteCursor;
            highWord8 = frame.rowPositionWord;
            highWord9 += 1;
            MATCHING_KEEP_CLOBBER(highWord9, "memory");
            frame.rowByteCursor = (unsigned char*)highWord9;
            rowByte4 = Atlas_76B64_Field(highWord9, unsigned char*, 0);
            highWord9 = frame.rowStepWord;
            quotientWord2 = 255;
            highWord8 += highWord9;
            MATCHING_KEEP3(rowByte4, quotientWord2, highWord8);
            inputWord3 = rowByte4 & 255;
            frame.rowPositionWord = highWord8;
        } while (inputWord3 != quotientWord2);
    }
    highWord8 = frame.savedArgument6;
    if (highWord8 == 0) {
        callerWord4 = (int)frame.textBuffer;
        __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$17", "memory");
        formatPointer17 = &Atlas_76B64_D_atlas_800757B8;
        MATCHING_KEEP_CLOBBER(formatPointer17, "memory");
        Atlas_76B64_sprintf((void*)callerWord4, formatPointer17, frame.sumWord71A10);
        quotientWord2 = Atlas_76B64_func_atlas_80076430(frame.textBuffer);
        inputWord3 = 66;
        MATCHING_KEEP(inputWord3);
        inputWord3 -= quotientWord2;
        callerWord4 = (int)frame.textBuffer;
        __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
        callerWord5 = textBaseWord + inputWord3;
        callerWord6 = frame.rowPositionWord;
        Atlas_76B64_func_atlas_80076228((void*)callerWord4, callerWord5, callerWord6, 0x2020A0);
        callerWord4 = (int)frame.textBuffer;
        __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$16", "memory");
        formatPointer16 = &Atlas_76B64_D_atlas_800757BC;
        MATCHING_KEEP_CLOBBER(formatPointer16, "memory");
        Atlas_76B64_sprintf((void*)callerWord4, formatPointer16, frame.sumByteF54Times100);
        callerWord4 = (int)frame.textBuffer;
        __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
        callerWord5 = textBaseWord + 66;
        callerWord6 = frame.rowPositionWord;
        Atlas_76B64_func_atlas_80076228((void*)callerWord4, callerWord5, callerWord6, 0x2020A0);
        Atlas_76B64_sprintf(frame.textBuffer, formatPointer17, frame.sumFlagBitCount);
        quotientWord2 = Atlas_76B64_func_atlas_80076430(frame.textBuffer);
        callerWord4 = (int)frame.textBuffer;
        __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
        callerWord7 = 0x2020A0;
        highWord9 = frame.rightTextOffsetWord;
        callerWord6 = frame.rowPositionWord;
        inputWord3 = highWord9 - quotientWord2;
        Atlas_76B64_func_atlas_80076228((void*)callerWord4, textBaseWord + inputWord3, callerWord6,
                                        callerWord7);
        Atlas_76B64_sprintf(frame.textBuffer, formatPointer16, frame.sumByteF7C);
        callerWord4 = (int)frame.textBuffer;
        __asm__("" : "=r"(callerWord4) : "0"(callerWord4) : "$5", "$7");
        callerWord7 = 0x2020A0;
        highWord8 = frame.rightTextOffsetWord;
        callerWord6 = frame.rowPositionWord;
        Atlas_76B64_func_atlas_80076228((void*)callerWord4, textBaseWord + highWord8, callerWord6,
                                        callerWord7);
        highWord9 = frame.rowPositionWord;
        highWord8 = frame.rowStepWord;
        highWord9 += highWord8;
        frame.rowPositionWord = highWord9;
        MATCHING_BARRIER("memory");
        highWord9 = frame.sumFlagBitCount;
        highWord8 = frame.sumWord71A10;
        inputWord3 = highWord9 * 100;
        inputWord3 = highWord8 + inputWord3;
        quotientWord2 = inputWord3 * 25;
        MATCHING_KEEP(quotientWord2);
        callerWord6 = quotientWord2 << 2;
        highWord9 = frame.sumByteF7C;
        highWord8 = frame.sumByteF54Times100;
        quotientWord2 = highWord9 * 100;
        quotientWord2 = highWord8 + quotientWord2;
        highWord9 = frame.sumScaledHelperReturn;
        MATCHING_KEEP2_CLOBBER(callerWord6, quotientWord2, "memory");
        percentage6 = callerWord6 / quotientWord2;
        if ((highWord9 != 0) && (percentage6 == 0)) {
            percentage6 = 1;
        }
        Atlas_76B64_sprintf(frame.textBuffer, &Atlas_76B64_D_atlas_800757C0, percentage6, 0x25,
                            Atlas_76B64_D_atlas_8007AA1C);
        Atlas_76B64_func_atlas_80076228(
            frame.textBuffer, 0x172 - (Atlas_76B64_func_atlas_80076430(frame.textBuffer) >> 1),
            frame.rowPositionWord, 0x2020A0);
        if ((Atlas_76B64_D_8007158F != 0) && (Atlas_76B64_D_atlas_8007AE0E >= 0xA)) {
            textBaseWord = 0x1D8;
            if ((highWord8 = frame.savedArgument5) != 0) {
                textBaseWord = 0xF4;
            }
            footerOffset5 =
                textBaseWord - Atlas_76B64_func_atlas_80076430(Atlas_76B64_D_atlas_8007AA24);
            footerY6 = 196;
            __asm__(""
                    : "=r"(footerOffset5), "=r"(footerY6)
                    : "0"(footerOffset5), "1"(footerY6)
                    : "$4", "$7", "memory");
            footerText4 = Atlas_76B64_D_atlas_8007AA24;
            callerWord7 = 0x00200000;
            goto drawFooterText;
        }
    } else if (Atlas_76B64_D_8006581C >= 2) {
        textBaseWord = 0x1D8;
        if ((highWord9 = frame.savedArgument5) != 0) {
            textBaseWord = 0xF4;
        }
        footerWord16 = &Atlas_76B64_D_atlas_8007AA20;
        MATCHING_KEEP_CLOBBER(footerWord16, "memory");
        footerOffset5 = textBaseWord - Atlas_76B64_func_atlas_80076430(*footerWord16);
        footerY6 = 196;
        __asm__(""
                : "=r"(footerOffset5), "=r"(footerY6)
                : "0"(footerOffset5), "1"(footerY6)
                : "$4", "$7", "memory");
        callerWord7 = 0x00200000;
        __asm__("" : "=r"(callerWord7) : "0"(callerWord7) : "$4", "memory");
        footerText4 = *footerWord16;
    drawFooterText:
        Atlas_76B64_func_atlas_80076228(footerText4, footerOffset5, footerY6, callerWord7 | 0x2020);
    }
}
#undef Atlas_76B64_Field
#undef Atlas_76B64_SignedHigh

/* AI generated; not human reviewed. Numeric atlas totals/text routes. */
extern unsigned char D_80066FCC[], D_80066F54[], D_80070300[];
extern int D_80071A10[], D_8006C76C;
extern int AtlasTotalsBase __asm__("D_80070108");
extern int AtlasTotalsTick __asm__("D_atlas_8007AE00");
extern unsigned char* AtlasTotalsTitles[] __asm__("D_80069CF8");
extern unsigned char* AtlasTotalsSuffix __asm__("D_atlas_8007AA1C");
extern char AtlasTotalsFormat[] __asm__("D_atlas_800757C8");
extern char AtlasPercentFormat[] __asm__("D_atlas_800757C0");
void AtlasTotalsDraw(unsigned char*, int, int, int) __asm__("func_atlas_80076228");
void AtlasTotalsLevel(int, int, int) __asm__("func_atlas_80075AD4");
unsigned int* AtlasTotalsIcon(int, int, int, int) __asm__("func_80028D30");
extern int sprintf(char*, const char*, ...);
void func_atlas_800775D8(int unused, int side, int index, int mode) {
    unsigned char buffer[24];
    register unsigned char** titles __asm__("$16");
    register int x __asm__("$17") = 370;
    register int level __asm__("$19");
    register int levelOffset __asm__("$18");
    register int collected __asm__("$18");
    int colour, bits, count, percentage, width;
    register int total __asm__("$16");
    register int y __asm__("$20");
    if (side)
        x = 142;
    MATCHING_BARRIER("$16");
    titles = AtlasTotalsTitles;
    {
        register int language __asm__("$3") = D_8006C76C;
        register unsigned char** table __asm__("$2");
        level = D_80066FCC[index];
        table = (unsigned char**)((char*)titles + language * 160);
        __asm__("" : "=r"(table) : "0"(table), "r"(level));
        levelOffset = level * 4;
        width = func_atlas_80076430(*(unsigned char**)(levelOffset + (unsigned int)table));
    }
    {
        register int drawX __asm__("$5") = x - (width >> 1);
        register int drawY __asm__("$6") = 30;
        register int drawColour __asm__("$7") = 0x202020;
        register unsigned char** table __asm__("$2") =
            (unsigned char**)((char*)titles + D_8006C76C * 160);
        __asm__("" : "=r"(table) : "0"(table), "r"(drawX), "r"(drawY), "r"(drawColour));
        AtlasTotalsDraw(*(unsigned char**)(levelOffset + (unsigned int)table), drawX, drawY,
                        drawColour);
    }
    x = 292;
    AtlasTotalsLevel(level, 64, 48);
    if (side)
        x = 64;
    {
        register int multiplier __asm__("$3") = D_80066F54[level];
        register int partial __asm__("$2");
        collected = *(int*)((char*)D_80071A10 + levelOffset);
        __asm__("" : "=r"(multiplier) : "0"(multiplier), "r"(collected));
        partial = multiplier * 25;
        MATCHING_KEEP(partial);
        total = partial * 4;
    }
    y = 160;
    if (total) {
        MATCHING_KEEP(y);
        {
            register int iconX __asm__("$5") = x;
            register int iconY __asm__("$6") = 154;
            register int iconMode __asm__("$7") = mode;
            MATCHING_KEEP3(iconX, iconY, iconMode);
            x += 36;
            AtlasTotalsIcon(AtlasTotalsBase + 256 + ((AtlasTotalsTick % 6) << 3), iconX, iconY,
                            iconMode);
        }
        sprintf((char*)buffer, AtlasTotalsFormat, collected, total);
        colour = 0x202020;
        if (collected == total)
            colour = 0xD8CCC;
        AtlasTotalsDraw(buffer, x, 160, colour);
    }
    bits = D_80070300[level];
    count = 0;
    while (bits) {
        if (bits & 1)
            count++;
        bits >>= 1;
    }
    percentage = func_80038B44(level, D_80071A10[level], count);
    x = 292;
    sprintf((char*)buffer, AtlasPercentFormat, percentage, 37, AtlasTotalsSuffix);
    if (side)
        x = 64;
    AtlasTotalsDraw(buffer, x, y + 20, 0x2020A0);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80077830-80077A5C.
 * Six byte entries; exact original row/name tables and per-invocation branches.
 * The row start is a compiler spill, not a volatile struct field. Buffer bytes,
 * mode stack48, original widths, signed remainder14 and constants are retained.
 * Empty constraints emit no opcodes. Acceptance requires 140 original words,
 * internal jumps, strict complete TU and every original EXE/overlay hash.
 * Unknown helper semantics, physical units and live runtime remain open.
 */
extern unsigned char D_80066FCC[], D_80070300[];
extern unsigned char Atlas77830Rows[] __asm__("D_atlas_8007B0C0");
extern unsigned char* Atlas77830Names[] __asm__("D_atlas_8007AA34");
extern unsigned char* Atlas77830Fallback __asm__("D_atlas_8007AA30");
extern int Atlas77830Value __asm__("D_atlas_8007AE00"), Atlas77830Base __asm__("D_80070108");
void Atlas77830Copy(unsigned char*, unsigned char*) __asm__("func_80064DDC");
unsigned int* Atlas77830Icon(int, int, int, int) __asm__("func_80028D30");
unsigned char* Atlas77830Split(unsigned char*, int) __asm__("func_atlas_800764DC");
void Atlas77830Draw(unsigned char*, int, int, int) __asm__("func_atlas_80076228");
void func_atlas_80077830(int unused, int side, int index, int mode) {
    struct {
        unsigned char buffer[56];
        int mode;
        int reserved4C;
    } local;
    unsigned char* start;
    unsigned char* cursor;
    unsigned char* name;
    unsigned char* tail;
    int x = 274, y, selected, offset, pulse, colour, iconColour, shift;
    register int first __asm__("$23");
    register unsigned char* destination __asm__("$4");
    unsigned int* icon;
    local.mode = mode;
    if (side)
        x = 46;
    y = 40;
    first = 1;
    MATCHING_KEEP(first);
    selected = D_80066FCC[index];
    __asm__("" : : : "$3", "memory");
    {
        register unsigned char* base __asm__("$3") = Atlas77830Rows;
        MATCHING_KEEP(base);
        offset = selected * 6;
        base = (unsigned char*)(offset + (unsigned int)base);
        MATCHING_KEEP(base);
        start = base;
    }
    cursor = start;
    do {
        int entry = *cursor;
        if (entry != 255) {
            if ((D_80070300[selected] >> entry) & 1) {
                pulse = Atlas77830Value % 14;
                if (pulse >= 8)
                    pulse = 14 - pulse;
                iconColour = 0x808080;
                colour = 0xD8CCC;
                name = Atlas77830Names[offset + entry];
            } else {
                pulse = 0;
                iconColour = 0x606060;
                colour = 0x78898C;
                if (first) {
                    destination = local.buffer;
                    MATCHING_KEEP(destination);
                    name = Atlas77830Names[offset + entry];
                    first = 0;
                    goto copyName;
                } else
                    name = Atlas77830Fallback;
            }
            destination = local.buffer;
        copyName:
            Atlas77830Copy(destination, name);
            icon = Atlas77830Icon(Atlas77830Base + 304 + (pulse << 3), x, y, local.mode);
            icon[1] = (icon[1] & 0xFF000000) | iconColour;
            tail = Atlas77830Split(local.buffer, 170);
            if ((int)tail < 0) {
                Atlas77830Draw(tail, x + 32, y + 12, colour);
                shift = 0;
            } else
                shift = 6;
            Atlas77830Draw(local.buffer, x + 32, y + shift, colour);
            y += 28;
        }
    } while ((int)++cursor < (int)start + 6);
}

extern unsigned char* DecodedAtlasListTitle __asm__("D_atlas_8007AA2C");
extern short DecodedAtlasListPage __asm__("D_atlas_8007AE0C");
extern unsigned char DecodedAtlasListItems[] __asm__("D_atlas_8007A998");
extern unsigned char* DecodedAtlasListStrings[] __asm__("D_80069CF8");
extern int DecodedAtlasListLanguage __asm__("D_8006C76C");
void DecodedAtlasDrawText(unsigned char*, int, int, int) __asm__("func_atlas_80076228");
/* SCUS-94467 USA Rev 0, atlas 0x80077A60..0x80077B8C.
 * Five localized rows; signed page halfword is reread after each draw.
 * Coordinates are passed unchanged to the upstream Atlas text renderer.
 * Empty constraints preserve allocation/scheduling and emit no instructions.
 * AI generated; not yet human reviewed.
 */
void func_atlas_80077A60(int unused, int side) {
    register int index __asm__("$16");
    register int x __asm__("$17");
    register int y __asm__("$18") = side;
    register unsigned char** strings __asm__("$19");
    unsigned char** title;
    register int page __asm__("$2");
    register int end __asm__("$3");
    MATCHING_KEEP(y);
    x = 370;
    MATCHING_KEEP(x);
    if (y)
        x = 142;
    title = &DecodedAtlasListTitle;
    {
        int width = func_atlas_80076430(*title);
        register int titleX __asm__("$5") = x - (width >> 1);
        register int titleY __asm__("$6") = 30;
        register int colour __asm__("$7");
        MATCHING_OBSERVE2(titleX, titleY);
        colour = 0x202020;
        MATCHING_KEEP(colour);
        DecodedAtlasDrawText(*title, titleX, titleY, colour);
    }
    x = 274;
    MATCHING_KEEP(x);
    if (y)
        x = 46;
    page = DecodedAtlasListPage;
    MATCHING_KEEP(page);
    end = page * 4;
    MATCHING_KEEP(end);
    index = end + page;
    page++;
    end = page * 5;
    MATCHING_KEEP(end);
    y = 51;
    if (index < end) {
        strings = DecodedAtlasListStrings;
        do {
            register int language __asm__("$3");
            register int rowX __asm__("$5") = x;
            register int rowY __asm__("$6") = y;
            register int style __asm__("$7");
            register unsigned char* text __asm__("$4");
            register int offset __asm__("$2");
            register unsigned char** selected __asm__("$3");
            MATCHING_OBSERVE2(rowX, rowY);
            language = DecodedAtlasListLanguage;
            MATCHING_BARRIER_VOLATILE("memory");
            style = 1;
            __asm__("" : "=r"(language) : "0"(language), "r"(style));
            offset = language * 5;
            MATCHING_KEEP(offset);
            language = DecodedAtlasListItems[index];
            __asm__("" : "=r"(language) : "0"(language), "r"(offset));
            offset <<= 5;
            language = D_80066FCC[language];
            __asm__("" : "=r"(language) : "0"(language), "r"(offset));
            offset += (int)strings;
            selected = (unsigned char**)(language * 4 + offset);
            MATCHING_KEEP(selected);
            text = *selected;
            MATCHING_KEEP(text);
            y += 32;
            DecodedAtlasDrawText(text, rowX, rowY, style);
            language = DecodedAtlasListPage;
            MATCHING_KEEP(language);
            index++;
            language++;
            offset = language * 5;
            MATCHING_KEEP(offset);
            end = offset;
        } while (index < end);
    }
}

/* SCUS-94467 USA Rev0 0x80077B90..0x80077D6C,120 original words.
 * Five entries per page, byte flag2 and sentinel107 follow original loads.
 * The helper result is tested as a signed pointer, with native draw ordering.
 * Empty constraints preserve compiler temporary lifetimes without instructions.
 * Table producers, descriptor semantics and caller cadence remain unresolved.
 * AI generated; not human reviewed. See batch2026-10-05-1624.
 */
extern short AtlasListPage __asm__("D_atlas_8007AE0C");
extern short AtlasListMarker __asm__("D_atlas_8007AE0A");
extern unsigned char* AtlasListNames[] __asm__("D_atlas_8007A9AC");
extern unsigned char* AtlasListFallback __asm__("D_atlas_8007AA30");
extern unsigned char AtlasListFooter[] __asm__("D_atlas_800757D0");
extern unsigned char D_80066BC8[];
unsigned char* AtlasListSplit(unsigned char*, int) __asm__("func_atlas_800764DC");
void AtlasListDraw(unsigned char*, int, int, int) __asm__("func_atlas_80076228");
void func_atlas_80077B90(int unused, int side) {
    unsigned char buffer[56];
    register int x __asm__("$19") = 274;
    register int index __asm__("$17");
    register int y __asm__("$18");
    register unsigned char** entry __asm__("$16");
    register unsigned char* work __asm__("$20");
    register int marker __asm__("$21");
    if (side)
        x = 46;
    {
        register int page __asm__("$2") = AtlasListPage;
        register int bound __asm__("$3");
        MATCHING_KEEP(page);
        {
            register int scaled __asm__("$3") = page << 2;
            MATCHING_KEEP(scaled);
            index = scaled + page;
        }
        MATCHING_KEEP(index);
        page++;
        bound = page * 5;
        MATCHING_KEEP(bound);
        y = 45;
        if (index < bound) {
            marker = 107;
            work = buffer;
            {
                register unsigned char** names __asm__("$3") = AtlasListNames;
                MATCHING_KEEP(names);
                {
                    register int byteOffset __asm__("$2") = index << 2;
                    MATCHING_KEEP(byteOffset);
                    entry = (unsigned char**)(byteOffset + (unsigned int)names);
                }
            }
            do {
                if (D_80066BC8[index] & 2) {
                    register int count __asm__("$6") = 0;
                    register short* markerPointer __asm__("$5") = &AtlasListMarker;
                    register unsigned char* destination __asm__("$4");
                    unsigned char* tail;
                    int shift;
                    *markerPointer = marker;
                    if ((*entry)[0] != marker) {
                        destination = work;
                        do {
                            *destination = (*entry)[count];
                            count++;
                            destination++;
                        } while ((*entry)[count] != *markerPointer);
                    }
                    {
                        register unsigned char* firstArgument __asm__("$4") = work;
                        register int splitLimit __asm__("$5") = 190;
                        MATCHING_OBSERVE2(firstArgument, splitLimit);
                        {
                            register unsigned int markerByte __asm__("$3") =
                                (unsigned short)AtlasListMarker;
                            register unsigned char* terminator __asm__("$2");
                            MATCHING_KEEP(markerByte);
                            terminator = work + count;
                            MATCHING_KEEP2(markerByte, terminator);
                            *terminator = markerByte;
                        }
                        tail = AtlasListSplit(firstArgument, splitLimit);
                    }
                    if ((int)tail < 0) {
                        AtlasListDraw(tail, x, y + 12, 1);
                        shift = 0;
                    } else
                        shift = 6;
                    AtlasListDraw(buffer, x, y + shift, 1);
                    AtlasListMarker = 0;
                } else
                    AtlasListDraw(AtlasListFallback, x + 24, y + 6, 1);
                y += 32;
                {
                    register int page __asm__("$3") = AtlasListPage;
                    register int limit __asm__("$2");
                    MATCHING_KEEP(page);
                    index++;
                    page++;
                    limit = page * 5;
                    MATCHING_KEEP(limit);
                    entry++;
                    if (index >= limit)
                        break;
                }
            } while (1);
        }
    }
    if (AtlasListPage < 3)
        AtlasListDraw(AtlasListFooter, x + 180, 200, 1);
}

/* AI generated; not human reviewed. Retail nested text split routing. */
extern unsigned char* D_atlas_8007AC1C[];
extern int sprintf(char*, const char*, ...);
unsigned char* Decoded2043Split(unsigned char*, int) __asm__("func_atlas_800764DC");
void Decoded2043Draw(unsigned char*, int, int, int) __asm__("func_atlas_80076228");
void func_atlas_80077D70(int unused, int side, int index, int mode) {
    unsigned char buffer[100];
    unsigned char* second;
    unsigned char* third;
    unsigned char* fourth;
    int x = 274;
    int row;
    if (side)
        x = 46;
    sprintf((char*)buffer, (char*)D_atlas_8007AC1C[index]);
    second = Decoded2043Split(buffer, 200);
    row = 40;
    if (second) {
        third = Decoded2043Split(second, 200);
        if (third) {
            fourth = Decoded2043Split(third, 200);
            if (fourth) {
                if (side)
                    goto finish;
                Decoded2043Draw(fourth, x, 195, 1);
            }
            if (side)
                goto finish;
            Decoded2043Draw(third, x, 184, 1);
        }
        if (side)
            goto finish;
        Decoded2043Draw(second, x, row | 133, 1);
    }
    if (side)
        goto finish;
    Decoded2043Draw(buffer, x, row + 122, 1);
finish:
    func_atlas_80075D78(index - 100, 256 - side * 192, row, side, mode);
}

extern SpriteData* D_80070108;
/* Same retail pointer; preserve the original independent loads. */
extern SpriteData* DecodedAtlasSpriteData __asm__("D_80070108");
void func_atlas_800781FC(int, int, int, int);
/* This retail call passes full-width coordinates, with no caller narrowing. */
int* DecodedAtlasDrawSprite(SpriteData*, int, int, int) __asm__("func_80028D30");
void func_atlas_80077EB8(int x, int y, int mode) {
    SpriteData* sprite;
    SpriteData* dimensions;
    register int drawMode __asm__("$7");
    func_atlas_800781FC(x, y - 7, 0, mode);
    drawMode = mode;
    __asm__("" : "=r"(drawMode) : "0"(drawMode), "r"(x), "r"(y));
    x += 0x80;
    y += 0x6C;
    sprite = D_80070108 + 16;
    dimensions = DecodedAtlasSpriteData + 16;
    DecodedAtlasDrawSprite(sprite, x - ((dimensions->unk4 - dimensions->unk0) >> 1),
                           y - ((dimensions->unk5 - dimensions->unk1) >> 1), drawMode);
}

/* AI generated; not human reviewed. SCUS-94467 80077F50..800781F8.
 * Byte bounds and eight-byte sprite records follow original instructions.
 * Empty constraints preserve original register and memory lifetimes.
 * Sprite meanings, coordinate units, helper contracts and cadence remain open.
 */
void func_atlas_80077F50(int incomingX, int incomingY, int incomingMode) {
    register SpriteData* firstSprites __asm__("$5") = D_80070108;
    register int x __asm__("$23");
    register int y __asm__("$19");
    register int mode __asm__("$20");
    register int advance __asm__("$21");
    register int step __asm__("$22");
    register int drawX __asm__("$18");
    register SpriteData** bank __asm__("$16");
    register int retainedMode __asm__("$17");
    register int verticalStep __asm__("$16");
    int bottom;
    int width;
    register int firstColumn __asm__("$5");
    register int firstRow __asm__("$6");
    register int nextAdvance __asm__("$3");
    register int widthLimit __asm__("$8");
    register int beyond __asm__("$2");
    register SpriteData* sprites __asm__("$3");
    MATCHING_KEEP_CLOBBER(firstSprites, "$19");
    y = incomingY;
    MATCHING_KEEP_CLOBBER(y, "$23");
    x = incomingX;
    MATCHING_KEEP_CLOBBER(x, "$20");
    mode = incomingMode;
    MATCHING_KEEP_CLOBBER(mode, "$21");
    advance = 0;
    {
        register int delta __asm__("$2") = firstSprites[23].unk5;
        register int lower __asm__("$3") = firstSprites[23].unk1;
        register int sideWidth __asm__("$4") = firstSprites[18].unk4;
        MATCHING_KEEP3(delta, lower, sideWidth);
        delta -= lower;
        delta -= 215;
        MATCHING_KEEP(delta);
        bottom = y - delta;
        lower = firstSprites[18].unk0;
        delta = firstSprites[20].unk0;
        sideWidth -= lower;
        lower = firstSprites[20].unk4;
        MATCHING_KEEP(lower);
        lower -= delta;
        delta = 255 - lower;
        width = delta;
        step = sideWidth + 1;
    }
    if (mode & 1) {
        register int left __asm__("$2") = x - step;
        MATCHING_KEEP(left);
        drawX = left + 1;
    } else
        drawX = x;
    firstColumn = drawX;
    if (mode & 1) {
        firstRow = y;
        __asm__(""
                : "=r"(firstColumn), "=r"(firstRow)
                : "0"(firstColumn), "1"(firstRow)
                : "$16", "memory");
        bank = &D_80070108;
        MATCHING_KEEP_CLOBBER(bank, "$17");
        retainedMode = mode ^ 1;
        DecodedAtlasDrawSprite(*bank + 17, firstColumn, firstRow, retainedMode);
        DecodedAtlasDrawSprite(*bank + 22, drawX, bottom, retainedMode);
    } else {
        firstRow = y;
        __asm__(""
                : "=r"(firstColumn), "=r"(firstRow)
                : "0"(firstColumn), "1"(firstRow)
                : "$16", "memory");
        bank = &D_80070108;
        DecodedAtlasDrawSprite(*bank + 18, firstColumn, firstRow, mode);
        DecodedAtlasDrawSprite(*bank + 23, drawX, bottom, mode);
    }
    advance += step;
    sprites = D_80070108;
    {
        register int edgeStart __asm__("$3");
        register int extent __asm__("$2") = sprites[19].unk4;
        edgeStart = sprites[19].unk0;
        __asm__ __volatile__(""
                             : "=r"(extent), "=r"(edgeStart)
                             : "0"(extent), "1"(edgeStart)
                             : "$8", "memory");
        widthLimit = width;
        __asm__("" : "=r"(widthLimit) : "0"(widthLimit), "r"(extent), "r"(edgeStart));
        extent -= edgeStart;
        step = extent + 1;
    }
    nextAdvance = advance + step;
    MATCHING_KEEP2(nextAdvance, widthLimit);
    beyond = widthLimit < nextAdvance;
    __asm__("" : "=r"(beyond) : "0"(beyond), "r"(widthLimit));
    if (!beyond) {
        retainedMode = mode & 1;
        bank = &D_80070108;
        do {
            if (retainedMode) {
                register int left __asm__("$2") = x - nextAdvance;
                MATCHING_KEEP(left);
                drawX = left + 1;
            } else
                drawX = x + advance;
            {
                register int column __asm__("$5") = drawX;
                register int row __asm__("$6") = y;
                register int drawMode __asm__("$7") = mode;
                register SpriteData* piece __asm__("$4");
                __asm__(""
                        : "=r"(column), "=r"(row), "=r"(drawMode)
                        : "0"(column), "1"(row), "2"(drawMode)
                        : "$4", "memory");
                piece = *bank;
                advance += step;
                DecodedAtlasDrawSprite(piece + 19, column, row, drawMode);
            }
            DecodedAtlasDrawSprite(*bank + 24, drawX, bottom, mode);
            widthLimit = width;
            __asm__ __volatile__("" : : : "$3", "memory");
            nextAdvance = advance + step;
            MATCHING_KEEP2(nextAdvance, widthLimit);
            beyond = widthLimit < nextAdvance;
            __asm__("" : "=r"(beyond) : "0"(beyond), "r"(widthLimit));
        } while (!beyond);
    }
    if (mode & 1)
        drawX = x - 255;
    else
        drawX = x + advance;
    firstColumn = drawX;
    firstRow = y;
    __asm__(""
            : "=r"(firstColumn), "=r"(firstRow)
            : "0"(firstColumn), "1"(firstRow)
            : "$16", "memory");
    bank = &D_80070108;
    DecodedAtlasDrawSprite(*bank + 20, firstColumn, firstRow, mode);
    {
        register int column __asm__("$5") = drawX;
        register int drawMode __asm__("$7") = mode;
        register SpriteData* piece __asm__("$4");
        register int edgeStart __asm__("$3");
        register int originalY __asm__("$8");
        register int delta __asm__("$2");
        __asm__("" : "=r"(column), "=r"(drawMode) : "0"(column), "1"(drawMode) : "$3", "memory");
        sprites = D_80070108;
        piece = *bank;
        __asm__("" : "=r"(sprites), "=r"(piece) : "0"(sprites), "1"(piece) : "$8", "memory");
        originalY = incomingY;
        delta = sprites[25].unk5;
        edgeStart = sprites[25].unk1;
        MATCHING_KEEP3(delta, edgeStart, originalY);
        piece += 25;
        __asm__("" : "=r"(piece) : "0"(piece), "r"(delta), "r"(edgeStart));
        delta -= edgeStart;
        delta -= 215;
        MATCHING_KEEP(delta);
        bottom = originalY - delta;
        DecodedAtlasDrawSprite(piece, column, bottom, drawMode);
    }
    sprites = D_80070108;
    {
        register int edgeStart __asm__("$3");
        register int delta __asm__("$4") = sprites[20].unk5;
        register int lower __asm__("$2") = sprites[20].unk1;
        register int row __asm__("$5");
        __asm__ __volatile__(""
                             : "=r"(delta), "=r"(lower)
                             : "0"(delta), "1"(lower)
                             : "$5", "memory");
        row = y + 1;
        __asm__("" : "=r"(row) : "0"(row), "r"(delta), "r"(lower));
        delta -= lower;
        lower = sprites[21].unk5;
        edgeStart = sprites[21].unk1;
        y = row + delta;
        lower -= edgeStart;
        MATCHING_KEEP(lower);
        verticalStep = lower + 1;
    }
    goto checkVertical;
verticalPiece:
    {
        register int row __asm__("$6");
        register int drawMode __asm__("$7");
        register SpriteData* piece __asm__("$4");
        MATCHING_KEEP(y);
        row = y;
        __asm__ __volatile__("" : "=r"(row) : "0"(row) : "$7", "memory");
        drawMode = mode;
        __asm__("" : "=r"(row), "=r"(drawMode) : "0"(row), "1"(drawMode) : "$4", "memory");
        piece = D_80070108;
        y += verticalStep;
        DecodedAtlasDrawSprite(piece + 21, firstColumn, row, drawMode);
    }
checkVertical:
    beyond = bottom < y + verticalStep;
    firstColumn = drawX;
    if (!beyond)
        goto verticalPiece;
}
