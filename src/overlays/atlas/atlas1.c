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
            if (D_atlas_8007B1B0[index] == level) break;
        if (index < 0x27) {
            do {
                index++;
                if (D_80071FB0[D_80066FCC[D_atlas_8007B1B0[index]]]) break;
            } while (index < 0x28);
            if (index < 0x28) result = D_atlas_8007B1B0[index];
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
            if (D_atlas_8007B1B0[index] == level) break;
        if (index > 0) {
            do {
                index--;
                if (D_80071FB0[D_80066FCC[D_atlas_8007B1B0[index]]]) break;
            } while (index >= 0);
            if (index >= 0) result = D_atlas_8007B1B0[index];
        }
    }
    return result;
}

extern int D_8006E470;
extern char* D_80070140;
extern WadHeader D_8006D8D8;
extern short D_atlas_8007ADEC[];
void func_atlas_8007594C(int index, int slot) {
    CDLoadAsync(D_8006E470, D_80070140 + slot * 0x4800,
        0x4800, D_8006D8D8.atlasImgs.offset + index * 0x4800);
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
    __asm__("" : "=r"(wanted) : "0"(wanted));
    retainedSlot = slot;
    __asm__("" : "=r"(retainedSlot) : "0"(retainedSlot));
    index = 0;
    __asm__("" : "=r"(index) : "0"(index));
    base = DecodedAtlasImageKeys;
    cursor = base;
    do {
        register int current __asm__("$2") = *cursor;
        __asm__("" : "=r"(current) : "0"(current));
        if (current == wanted) break;
        index++;
        cursor++;
    } while (index < 3);
    zeroArgument = 0;
    __asm__("" : "=r"(zeroArgument) : "0"(zeroArgument));
    base += 3;
    base[retainedSlot] = wanted;
    rectangle.x = 768;
    rectangle.y = retainedSlot + 126;
    rectangle.w = 256;
    rectangle.h = 1;
    pixels = DecodedAtlasImageData + index * 18432 + 28;
    DrawSync(zeroArgument);
    LoadImage(&rectangle, (unsigned long*)pixels);
    __asm__("" : "=r"(pixels) : "0"(pixels));
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
    __asm__("" : "=r"(x) : "0"(x));
    origin = yArgument;
    __asm__("" : "=r"(origin) : "0"(origin));
    index = 0;
    cursor = DecodedAtlasSmallImageKeys;
    do {
        register int current __asm__("$2") = *cursor;
        __asm__("" : "=r"(current) : "0"(current));
        if (current == wanted) break;
        index++;
        cursor++;
    } while (index < 2);
    if (index < 2) {
        register int limit __asm__("$3");
        sprite.unk2 = ((index + 126) << 6) | 48;
        temporary = 80 << index;
        __asm__("" : "=r"(temporary) : "0"(temporary));
        limit = 1024;
        column = limit - temporary;
        temporary = index * 80;
        __asm__("" : "=r"(temporary) : "0"(temporary));
        limit -= temporary;
        if (column < limit) {
            end = limit;
            do {
                y = origin;
                row = 0;
                temporary = column & 63;
                __asm__("" : "=r"(temporary) : "0"(temporary));
                left = temporary * 2;
                right = left + 39;
                temporary = column & 1023;
                __asm__("" : "=r"(temporary) : "0"(temporary));
                texture = (temporary >> 6) | 224;
                do {
                    sprite.unk0 = left;
                    sprite.unk1 = row;
                    sprite.unk4 = right;
                    temporary = 80;
                    __asm__("" : "=r"(temporary) : "0"(temporary));
                    if (row == temporary) {
                        sprite.unk5 = 98;
                    } else {
                        sprite.unk5 = row + 19;
                    }
                    temporary = ((row & 256) >> 4) | texture;
                    __asm__("" : "=r"(temporary) : "0"(temporary));
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
    CDLoadAsync(D_8006E470, D_80070140 + (index & 1) * 0xB800,
        0xB800, D_8006D8D8.epilogueImgs.offset + index * 0xB800);
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
    __asm__("" : "=r"(image) : "0"(image));
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
    __asm__("" : "=r"(page) : "0"(page));
    coefficient = 1 - side;
    __asm__("" : "=r"(coefficient) : "0"(coefficient));
    temporary = coefficient * 96 + 1024;
    __asm__("" : "=r"(temporary) : "0"(temporary));
    coefficient = 192 << page;
    __asm__("" : "=r"(coefficient) : "0"(coefficient));
    column = temporary - coefficient;
    texturePage = ((page + 254) << 6) | 48;
    __asm__("" : "=r"(texturePage) : "0"(texturePage));
    start = column;
    __asm__("" : "=r"(start) : "0"(start));
    drawMode = mode;
    __asm__("" : "=r"(drawMode) : "0"(drawMode));
    enabled = 1;
    savedY = yArgument;
    __asm__("" : "=r"(enabled) : "0"(enabled));
    sprite.unk2 = texturePage;
    if (enabled) {
        do {
            y = savedY;
            row = 128;
            temporary = column & 63;
            __asm__("" : "=r"(temporary) : "0"(temporary));
            left = temporary * 2;
            right = left + 31;
            temporary = column & 1023;
            __asm__("" : "=r"(temporary) : "0"(temporary));
            texture = (temporary >> 6) | 224;
            do {
                temporary = row + 19;
                __asm__("" : "=r"(temporary) : "0"(temporary));
                coefficient = ((row & 256) >> 4) | texture;
                __asm__("" : "=r"(coefficient) : "0"(coefficient));
                sprite.unk5 = temporary;
                __asm__ volatile("" : : "m"(sprite.unk5));
                sprite.unk0 = left;
                sprite.unk1 = row;
                sprite.unk4 = right;
                coefficient |= (row & 512) << 2;
                __asm__("" : : "r"(coefficient) : "$4");
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
    __asm__("" : "=r"(sectorOffset) : "0"(sectorOffset));
    levelOffset = D_8006C58C;
    combined = D_80072098.vramSpu.offset;
    sector = D_8006E470;
    length = 0x10000;
    levelOffset = D_8006D8D8.lvl[levelOffset].lvl.offset;
    buffer = D_80070140;
    combined += levelOffset;
    __asm__("" : "=r"(combined), "=r"(sectorOffset)
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
    if (slot) D_atlas_8007AE04 = 0;
    else func_atlas_80075EB0(1);
}

extern unsigned char D_atlas_8007AE0A;
int func_atlas_80075FBC(unsigned char value) {
    int glyph;
    value = D_atlas_8007AE0A ^ value;
    if ((unsigned char)(value - 'a') < 26) glyph = value - 31;
    else if ((unsigned char)(value - 'A') < 26) glyph = value + 27;
    else if ((unsigned char)(value - '0') < 10) glyph = value + 70;
    else if (value == 39) glyph = 0x80;
    else if (value == ':') glyph = 0x81;
    else if (value == ',') glyph = 0x82;
    else if (value == '!') glyph = 0x83;
    else if (value == '.') glyph = 0x84;
    else if (value == '?') glyph = 0x85;
    else if (value == '/') glyph = 0x86;
    else if (value == '%') glyph = 0x87;
    else if (value == '[') glyph = 0x9F;
    else if (value == ']') glyph = 0xA0;
    else if (value == '{') glyph = 0xA1;
    else if (value == '}') glyph = 0xA2;
    else if (value == '@') glyph = 0xA3;
    else glyph = -1;
    return glyph;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/atlas/atlas1", D_atlas_80074490);

/* AI generated; not human reviewed. Numeric mapping from original dispatch table. */
extern unsigned char Decoded2055Marker __asm__("D_atlas_8007AE0A");
int func_atlas_80076128(unsigned char argument) {
 int result;
 switch((Decoded2055Marker^argument)&255) {
 case 33:result=0x88;break;
 case 63:result=0x89;break;
 case 83:result=0x8A;break;
 case 67:result=0x8B;break;
 case 99:result=0x8C;break;
 case 65:result=0x91;break;
 case 97:result=0x92;break;
 case 66:result=0x93;break;
 case 98:result=0x94;break;
 case 71:result=0x8D;break;
 case 103:result=0x8E;break;
 case 72:result=0x8F;break;
 case 104:result=0x90;break;
 case 85:result=0x95;break;
 case 117:result=0x96;break;
 case 86:result=0x97;break;
 case 118:result=0x98;break;
 case 73:result=0x99;break;
 case 105:result=0x9A;break;
 case 74:result=0x9B;break;
 case 106:result=0x9C;break;
 case 84:result=0x9D;break;
 case 116:result=0x9E;break;
 default:result=-1;break;
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
        __asm__("" : "=r"(byte) : "0"(byte));
        byteOrIndex = byte & 255;
        glyph = Atlas76228Glyph(byteOrIndex);
        if (glyph == 0xA3) {
            text++;
            glyph = Atlas76228Escape(*text);
            if (glyph == 0x92 ||
                glyph == 0x8E ||
                glyph == 0x94 ||
                glyph == 0x90 ||
                glyph == 0x9A) bias = -1;
            else if (glyph == 0x91 ||
                glyph == 0x8D ||
                glyph == 0x99 ||
                glyph == 0x93 ||
                glyph == 0x8F ||
                glyph == 0x9B) bias = -4;
        } else {
            byteOrIndex ^= Atlas76228Marker;
            if (byteOrIndex == 0x67 || (unsigned int)(byteOrIndex - 0x70) < 2 ||
                byteOrIndex == 0x79) bias = 3;
            else if (byteOrIndex == 0x2E ||
                byteOrIndex == 0x2C ||
                byteOrIndex == 0x2F ||
                byteOrIndex == 0x25) bias = 1;
        }
        byteOrIndex = glyph - 0x42;
        if (glyph >= 0) {
            advance = Atlas76228Advance[byteOrIndex];
            offset = 0;
            if (advance >= 0x80) offset = advance - 0x100;
            sourceBase = Atlas76228Sprites;
            sourceOffset = glyph * 8;
            packet = func_800289C8((SpriteData*)((unsigned char*)sourceBase + sourceOffset), x + offset, y + bias);
            comparison = glyph < 0x9F;
            __asm__("" : "=r"(comparison) : "0"(comparison));
            if (comparison) packet[1] = (packet[1] & 0xFF000000) | colour;
            advance = Atlas76228Advance[byteOrIndex];
            if (advance < 0x80) x += advance;
        } else x += 6;
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
            if (widthByte < 128) width += widthByte;
        } else width += 6;
        text++;
check:
        /* Retail reads this byte once and compares its low byte to a signed halfword. */
        byte = *text;
        __asm__("" : "=r"(byte) : "0"(byte));
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
        if (width >= maximumWidth) goto finish;
        byte &= 255;
        mask = *terminator;
        /* Original marker test uses XOR with a fresh terminator halfword. */
        if ((byte ^ mask) == 32) splitAddress = (int)text;
        glyph = DecodedAtlasGlyph(byte);
        if (glyph == 163) {
            text++;
            glyph = func_atlas_80076128(*text);
        }
        if (glyph >= 0) {
            unsigned int widthByte = D_atlas_8007B01A[glyph];
            if (widthByte < 128) width += widthByte;
        } else width += 6;
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

INCLUDE_ASM("asm/nonmatchings/overlays/atlas/atlas1", func_atlas_800765F8);

INCLUDE_ASM("asm/nonmatchings/overlays/atlas/atlas1", func_atlas_80076B64);

/* AI generated; not human reviewed. Numeric atlas totals/text routes. */
extern unsigned char D_80066FCC[],D_80066F54[],D_80070300[];
extern int D_80071A10[],D_8006C76C;
extern int AtlasTotalsBase __asm__("D_80070108");
extern int AtlasTotalsTick __asm__("D_atlas_8007AE00");
extern unsigned char* AtlasTotalsTitles[] __asm__("D_80069CF8");
extern unsigned char* AtlasTotalsSuffix __asm__("D_atlas_8007AA1C");
extern char AtlasTotalsFormat[] __asm__("D_atlas_800757C8");
extern char AtlasPercentFormat[] __asm__("D_atlas_800757C0");
void AtlasTotalsDraw(unsigned char*,int,int,int) __asm__("func_atlas_80076228");
void AtlasTotalsLevel(int,int,int) __asm__("func_atlas_80075AD4");
unsigned int* AtlasTotalsIcon(int,int,int,int) __asm__("func_80028D30");
extern int sprintf(char*,const char*,...);
void func_atlas_800775D8(int unused,int side,int index,int mode) {
 unsigned char buffer[24];
 register unsigned char** titles __asm__("$16");
 register int x __asm__("$17")=370;
 register int level __asm__("$19");
 register int levelOffset __asm__("$18");
 register int collected __asm__("$18");
 int colour,bits,count,percentage,width;
 register int total __asm__("$16");
 register int y __asm__("$20");
 if(side)x=142;
 __asm__("" : : : "$16");
 titles=AtlasTotalsTitles;
 {register int language __asm__("$3")=D_8006C76C;
  register unsigned char** table __asm__("$2");
  level=D_80066FCC[index];
  table=(unsigned char**)((char*)titles+language*160);
  __asm__("" : "=r"(table): "0"(table),"r"(level));
  levelOffset=level*4;
  width=func_atlas_80076430(*(unsigned char**)(levelOffset+(unsigned int)table));}
 {register int drawX __asm__("$5")=x-(width>>1);
  register int drawY __asm__("$6")=30;
  register int drawColour __asm__("$7")=0x202020;
  register unsigned char** table __asm__("$2")=(unsigned char**)((char*)titles+D_8006C76C*160);
  __asm__("" : "=r"(table): "0"(table),"r"(drawX),"r"(drawY),"r"(drawColour));
  AtlasTotalsDraw(*(unsigned char**)(levelOffset+(unsigned int)table),drawX,drawY,drawColour);}
 x=292;
 AtlasTotalsLevel(level,64,48);
 if(side)x=64;
 {register int multiplier __asm__("$3")=D_80066F54[level];
  register int partial __asm__("$2");
  collected=*(int*)((char*)D_80071A10+levelOffset);
  __asm__("" : "=r"(multiplier): "0"(multiplier),"r"(collected));
  partial=multiplier*25;
  __asm__("" : "=r"(partial): "0"(partial));
  total=partial*4;}
 y=160;
 if(total) {
  __asm__("" : "=r"(y): "0"(y));
  {register int iconX __asm__("$5")=x;
   register int iconY __asm__("$6")=154;
   register int iconMode __asm__("$7")=mode;
   __asm__("" : "=r"(iconX),"=r"(iconY),"=r"(iconMode): "0"(iconX),"1"(iconY),"2"(iconMode));
   x+=36;
   AtlasTotalsIcon(AtlasTotalsBase+256+((AtlasTotalsTick%6)<<3),iconX,iconY,iconMode);}
  sprintf((char*)buffer,AtlasTotalsFormat,collected,total);
  colour=0x202020;if(collected==total)colour=0xD8CCC;
  AtlasTotalsDraw(buffer,x,160,colour);
 }
 bits=D_80070300[level];count=0;
 while(bits) {if(bits&1)count++;bits>>=1;}
 percentage=func_80038B44(level,D_80071A10[level],count);
 x=292;
 sprintf((char*)buffer,AtlasPercentFormat,percentage,37,AtlasTotalsSuffix);
 if(side)x=64;
 AtlasTotalsDraw(buffer,x,y+20,0x2020A0);
}


/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80077830-80077A5C.
 * Six byte entries; exact original row/name tables and per-invocation branches.
 * The row start is a compiler spill, not a volatile struct field. Buffer bytes,
 * mode stack48, original widths, signed remainder14 and constants are retained.
 * Empty constraints emit no opcodes. Acceptance requires 140 original words,
 * internal jumps, strict complete TU and every original EXE/overlay hash.
 * Unknown helper semantics, physical units and live runtime remain open.
 */
extern unsigned char D_80066FCC[],D_80070300[];
extern unsigned char Atlas77830Rows[] __asm__("D_atlas_8007B0C0");
extern unsigned char* Atlas77830Names[] __asm__("D_atlas_8007AA34");
extern unsigned char* Atlas77830Fallback __asm__("D_atlas_8007AA30");
extern int Atlas77830Value __asm__("D_atlas_8007AE00"),Atlas77830Base __asm__("D_80070108");
void Atlas77830Copy(unsigned char*,unsigned char*) __asm__("func_80064DDC");
unsigned int* Atlas77830Icon(int,int,int,int) __asm__("func_80028D30");
unsigned char* Atlas77830Split(unsigned char*,int) __asm__("func_atlas_800764DC");
void Atlas77830Draw(unsigned char*,int,int,int) __asm__("func_atlas_80076228");
void func_atlas_80077830(int unused,int side,int index,int mode) {
 struct {
     unsigned char buffer[56];
     int mode;
     int reserved4C;
 } local;
 unsigned char* start;
 unsigned char* cursor;
 unsigned char* name;
 unsigned char* tail;
 int x=274,y,selected,offset,pulse,colour,iconColour,shift;
 register int first __asm__("$23");
 register unsigned char* destination __asm__("$4");
 unsigned int* icon;
 local.mode=mode;
 if(side)x=46;
 y=40;
 first=1;
 __asm__("" : "=r"(first) : "0"(first));
 selected=D_80066FCC[index];
 __asm__("" : : : "$3","memory");
 {register unsigned char* base __asm__("$3")=Atlas77830Rows;
  __asm__("" : "=r"(base) : "0"(base));
  offset=selected*6;base=(unsigned char*)(offset+(unsigned int)base);
  __asm__("" : "=r"(base) : "0"(base));
  start=base;
 }
 cursor=start;
 do {
  int entry=*cursor;
  if(entry!=255) {
   if((D_80070300[selected]>>entry)&1) {
    pulse=Atlas77830Value%14;
    if(pulse>=8)pulse=14-pulse;
    iconColour=0x808080;
    colour=0xD8CCC;
    name=Atlas77830Names[offset+entry];
   } else {
    pulse=0;
    iconColour=0x606060;
    colour=0x78898C;
    if(first) {destination=local.buffer;
     __asm__("" : "=r"(destination) : "0"(destination));
     name=Atlas77830Names[offset+entry];
     first=0;
     goto copyName;
    }
    else name=Atlas77830Fallback;
   }
   destination=local.buffer;
 copyName:
   Atlas77830Copy(destination,name);
   icon=Atlas77830Icon(Atlas77830Base+304+(pulse<<3),x,y,local.mode);
   icon[1]=(icon[1]&0xFF000000)|iconColour;
   tail=Atlas77830Split(local.buffer,170);
   if((int)tail<0) {
    Atlas77830Draw(tail,x+32,y+12,colour);
    shift=0;
   }
   else shift=6;
   Atlas77830Draw(local.buffer,x+32,y+shift,colour);
   y+=28;
  }
 }while((int)++cursor<(int)start+6);
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
    __asm__("" : "=r"(y) : "0"(y));
    x = 370;
    __asm__("" : "=r"(x) : "0"(x));
    if (y) x = 142;
    title = &DecodedAtlasListTitle;
    {
        int width = func_atlas_80076430(*title);
        register int titleX __asm__("$5") = x - (width >> 1);
        register int titleY __asm__("$6") = 30;
        register int colour __asm__("$7");
        __asm__("" : : "r"(titleX), "r"(titleY));
        colour = 0x202020;
        __asm__("" : "=r"(colour) : "0"(colour));
        DecodedAtlasDrawText(*title, titleX, titleY, colour);
    }
    x = 274;
    __asm__("" : "=r"(x) : "0"(x));
    if (y) x = 46;
    page = DecodedAtlasListPage;
    __asm__("" : "=r"(page) : "0"(page));
    end = page * 4;
    __asm__("" : "=r"(end) : "0"(end));
    index = end + page;
    page++;
    end = page * 5;
    __asm__("" : "=r"(end) : "0"(end));
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
            __asm__("" : : "r"(rowX), "r"(rowY));
            language = DecodedAtlasListLanguage;
            __asm__ volatile("" : : : "memory");
            style = 1;
            __asm__("" : "=r"(language) : "0"(language), "r"(style));
            offset = language * 5;
            __asm__("" : "=r"(offset) : "0"(offset));
            language = DecodedAtlasListItems[index];
            __asm__("" : "=r"(language) : "0"(language), "r"(offset));
            offset <<= 5;
            language = D_80066FCC[language];
            __asm__("" : "=r"(language) : "0"(language), "r"(offset));
            offset += (int)strings;
            selected = (unsigned char**)(language * 4 + offset);
            __asm__("" : "=r"(selected) : "0"(selected));
            text = *selected;
            __asm__("" : "=r"(text) : "0"(text));
            y += 32;
            DecodedAtlasDrawText(text, rowX, rowY, style);
            language = DecodedAtlasListPage;
            __asm__("" : "=r"(language) : "0"(language));
            index++;
            language++;
            offset = language * 5;
            __asm__("" : "=r"(offset) : "0"(offset));
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
unsigned char* AtlasListSplit(unsigned char*,int) __asm__("func_atlas_800764DC");
void AtlasListDraw(unsigned char*,int,int,int) __asm__("func_atlas_80076228");
void func_atlas_80077B90(int unused,int side) {
    unsigned char buffer[56];
    register int x __asm__("$19")=274;
    register int index __asm__("$17");
    register int y __asm__("$18");
    register unsigned char** entry __asm__("$16");
    register unsigned char* work __asm__("$20");
    register int marker __asm__("$21");
    if(side)x=46;
    { register int page __asm__("$2")=AtlasListPage;
      register int bound __asm__("$3");
      __asm__("" : "=r"(page) : "0"(page));
      { register int scaled __asm__("$3")=page<<2;
        __asm__("" : "=r"(scaled) : "0"(scaled));
        index=scaled+page; }
      __asm__("" : "=r"(index) : "0"(index));
      page++;bound=page*5;
      __asm__("" : "=r"(bound) : "0"(bound));
      y=45;
    if(index<bound) {
        marker=107;work=buffer;
        { register unsigned char** names __asm__("$3")=AtlasListNames;
          __asm__("" : "=r"(names) : "0"(names));
          { register int byteOffset __asm__("$2")=index<<2;
            __asm__("" : "=r"(byteOffset) : "0"(byteOffset));
            entry=(unsigned char**)(byteOffset+(unsigned int)names); } }
        do {
            if(D_80066BC8[index]&2) {
                register int count __asm__("$6")=0;
                register short* markerPointer __asm__("$5")=&AtlasListMarker;
                register unsigned char* destination __asm__("$4");
                unsigned char* tail;
                int shift;
                *markerPointer=marker;
                if((*entry)[0]!=marker) {
                    destination=work;
                    do {*destination=(*entry)[count];count++;destination++;}
                    while((*entry)[count]!=*markerPointer);
                }
                { register unsigned char* firstArgument __asm__("$4")=work;
                  register int splitLimit __asm__("$5")=190;
                  __asm__("" : : "r"(firstArgument),"r"(splitLimit));
                  { register unsigned int markerByte __asm__("$3")=(unsigned short)AtlasListMarker;
                  register unsigned char* terminator __asm__("$2");
                  __asm__("" : "=r"(markerByte) : "0"(markerByte));
                  terminator=work+count;
                  __asm__("" : "=r"(markerByte),"=r"(terminator) : "0"(markerByte),"1"(terminator));
                  *terminator=markerByte; }
                tail=AtlasListSplit(firstArgument,splitLimit); }
                if((int)tail<0) {AtlasListDraw(tail,x,y+12,1);shift=0;}
                else shift=6;
                AtlasListDraw(buffer,x,y+shift,1);
                AtlasListMarker=0;
            } else AtlasListDraw(AtlasListFallback,x+24,y+6,1);
            y+=32;
            { register int page __asm__("$3")=AtlasListPage;
              register int limit __asm__("$2");
              __asm__("" : "=r"(page) : "0"(page));
              index++;page++;limit=page*5;
              __asm__("" : "=r"(limit) : "0"(limit));
              entry++;
              if(index>=limit)break; }
        } while(1);
    } }
    if(AtlasListPage<3)AtlasListDraw(AtlasListFooter,x+180,200,1);
}

/* AI generated; not human reviewed. Retail nested text split routing. */
extern unsigned char* D_atlas_8007AC1C[];
extern int sprintf(char*,const char*,...);
unsigned char* Decoded2043Split(unsigned char*,int) __asm__("func_atlas_800764DC");
void Decoded2043Draw(unsigned char*,int,int,int) __asm__("func_atlas_80076228");
void func_atlas_80077D70(int unused,int side,int index,int mode) {
 unsigned char buffer[100];unsigned char* second;unsigned char* third;unsigned char* fourth;
 int x=274;int row;
 if(side)x=46;
 sprintf((char*)buffer,(char*)D_atlas_8007AC1C[index]);
 second=Decoded2043Split(buffer,200);row=40;
 if(second) {
  third=Decoded2043Split(second,200);
  if(third) {
   fourth=Decoded2043Split(third,200);
   if(fourth) {
    if(side)goto finish;
    Decoded2043Draw(fourth,x,195,1);
   }
   if(side)goto finish;
   Decoded2043Draw(third,x,184,1);
  }
  if(side)goto finish;
  Decoded2043Draw(second,x,row|133,1);
 }
 if(side)goto finish;
 Decoded2043Draw(buffer,x,row+122,1);
 finish:
 func_atlas_80075D78(index-100,256-side*192,row,side,mode);
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
    DecodedAtlasDrawSprite(sprite,
        x - ((dimensions->unk4 - dimensions->unk0) >> 1),
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
    __asm__("" : "=r"(firstSprites) : "0"(firstSprites) : "$19");
    y = incomingY;
    __asm__("" : "=r"(y) : "0"(y) : "$23");
    x = incomingX;
    __asm__("" : "=r"(x) : "0"(x) : "$20");
    mode = incomingMode;
    __asm__("" : "=r"(mode) : "0"(mode) : "$21");
    advance = 0;
    {
        register int delta __asm__("$2") = firstSprites[23].unk5;
        register int lower __asm__("$3") = firstSprites[23].unk1;
        register int sideWidth __asm__("$4") = firstSprites[18].unk4;
        __asm__("" : "=r"(delta), "=r"(lower), "=r"(sideWidth) : "0"(delta), "1"(lower), "2"(sideWidth));
        delta -= lower;
        delta -= 215;
        __asm__("" : "=r"(delta) : "0"(delta));
        bottom = y - delta;
        lower = firstSprites[18].unk0;
        delta = firstSprites[20].unk0;
        sideWidth -= lower;
        lower = firstSprites[20].unk4;
        __asm__("" : "=r"(lower) : "0"(lower));
        lower -= delta;
        delta = 255 - lower;
        width = delta;
        step = sideWidth + 1;
    }
    if (mode & 1) {
        register int left __asm__("$2") = x - step;
        __asm__("" : "=r"(left) : "0"(left));
        drawX = left + 1;
    }
    else drawX = x;
    firstColumn = drawX;
    if (mode & 1) {
        firstRow = y;
        __asm__("" : "=r"(firstColumn), "=r"(firstRow) : "0"(firstColumn), "1"(firstRow) : "$16", "memory");
        bank = &D_80070108;
        __asm__("" : "=r"(bank) : "0"(bank) : "$17");
        retainedMode = mode ^ 1;
        DecodedAtlasDrawSprite(*bank + 17, firstColumn, firstRow, retainedMode);
        DecodedAtlasDrawSprite(*bank + 22, drawX, bottom, retainedMode);
    } else {
        firstRow = y;
        __asm__("" : "=r"(firstColumn), "=r"(firstRow) : "0"(firstColumn), "1"(firstRow) : "$16", "memory");
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
        __asm__ __volatile__("" : "=r"(extent), "=r"(edgeStart) : "0"(extent), "1"(edgeStart) : "$8", "memory");
        widthLimit = width;
        __asm__("" : "=r"(widthLimit) : "0"(widthLimit), "r"(extent), "r"(edgeStart));
        extent -= edgeStart;
        step = extent + 1;
    }
    nextAdvance = advance + step;
    __asm__("" : "=r"(nextAdvance), "=r"(widthLimit) : "0"(nextAdvance), "1"(widthLimit));
    beyond = widthLimit < nextAdvance;
    __asm__("" : "=r"(beyond) : "0"(beyond), "r"(widthLimit));
    if (!beyond) {
        retainedMode = mode & 1;
        bank = &D_80070108;
        do {
            if (retainedMode) {
                register int left __asm__("$2") = x - nextAdvance;
                __asm__("" : "=r"(left) : "0"(left));
                drawX = left + 1;
            }
            else drawX = x + advance;
            {
                register int column __asm__("$5") = drawX;
                register int row __asm__("$6") = y;
                register int drawMode __asm__("$7") = mode;
                register SpriteData* piece __asm__("$4");
                __asm__("" : "=r"(column), "=r"(row), "=r"(drawMode) : "0"(column), "1"(row), "2"(drawMode) : "$4", "memory");
                piece = *bank;
                advance += step;
                DecodedAtlasDrawSprite(piece + 19, column, row, drawMode);
            }
            DecodedAtlasDrawSprite(*bank + 24, drawX, bottom, mode);
            widthLimit = width;
            __asm__ __volatile__("" : : : "$3", "memory");
            nextAdvance = advance + step;
            __asm__("" : "=r"(nextAdvance), "=r"(widthLimit) : "0"(nextAdvance), "1"(widthLimit));
            beyond = widthLimit < nextAdvance;
            __asm__("" : "=r"(beyond) : "0"(beyond), "r"(widthLimit));
        } while (!beyond);
    }
    if (mode & 1) drawX = x - 255;
    else drawX = x + advance;
    firstColumn = drawX;
    firstRow = y;
    __asm__("" : "=r"(firstColumn), "=r"(firstRow) : "0"(firstColumn), "1"(firstRow) : "$16", "memory");
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
        __asm__("" : "=r"(delta), "=r"(edgeStart), "=r"(originalY) : "0"(delta), "1"(edgeStart), "2"(originalY));
        piece += 25;
        __asm__("" : "=r"(piece) : "0"(piece), "r"(delta), "r"(edgeStart));
        delta -= edgeStart;
        delta -= 215;
        __asm__("" : "=r"(delta) : "0"(delta));
        bottom = originalY - delta;
        DecodedAtlasDrawSprite(piece, column, bottom, drawMode);
    }
    sprites = D_80070108;
    {
        register int edgeStart __asm__("$3");
        register int delta __asm__("$4") = sprites[20].unk5;
        register int lower __asm__("$2") = sprites[20].unk1;
        register int row __asm__("$5");
        __asm__ __volatile__("" : "=r"(delta), "=r"(lower) : "0"(delta), "1"(lower) : "$5", "memory");
        row = y + 1;
        __asm__("" : "=r"(row) : "0"(row), "r"(delta), "r"(lower));
        delta -= lower;
        lower = sprites[21].unk5;
        edgeStart = sprites[21].unk1;
        y = row + delta;
        lower -= edgeStart;
        __asm__("" : "=r"(lower) : "0"(lower));
        verticalStep = lower + 1;
    }
    goto checkVertical;
verticalPiece:
    {
        register int row __asm__("$6");
        register int drawMode __asm__("$7");
        register SpriteData* piece __asm__("$4");
        __asm__("" : "=r"(y) : "0"(y));
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
    if (!beyond) goto verticalPiece;
}
