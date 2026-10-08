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
    __asm__("" : "=r"(flags) : "0"(flags));
    y = yArgument + 7;
    __asm__("" : "=r"(y) : "0"(y));
    row = 0;
    __asm__("" : "=r"(row) : "0"(row));
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
            __asm__("" : "=r"(index) : "0"(index));
            __asm__("" : "=r"(tileFlags) : "0"(tileFlags));
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
                    __asm__("" : "=r"(drawX) : "0"(drawX));
                    __asm__("" : "=r"(drawY) : "0"(drawY));
                    drawBase = DecodedAtlasTileSprites;
                    __asm__("" : : : "memory");
                    DecodedAtlasDrawTile(drawBase + spriteOffset, drawX, drawY, tileFlags ^ flags);
                }
                __asm__("" : : "r"(row), "r"(flags), "r"(entry));
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

INCLUDE_ASM("asm/nonmatchings/overlays/atlas/atlas2", func_atlas_8007839C);

/* AI generated; not human reviewed. Retail numeric atlas actor/view updates. */
extern short Decoded2058Mode __asm__("D_atlas_8007ADE4");
extern int Decoded2058Value __asm__("D_atlas_8007ADFC");
extern int Decoded2058X __asm__("D_80070118");
extern volatile int Decoded2058Y __asm__("D_8007011C");
extern int Decoded2058Z __asm__("D_80070120");
extern unsigned short Decoded2058Angle __asm__("D_8006E040");
extern short Decoded2058Shift __asm__("D_80070136");
extern unsigned char Decoded2058A __asm__("D_80070130"),Decoded2058B __asm__("D_80070131"),Decoded2058C __asm__("D_80070132");
extern int D_8006FBCC,D_8006C648;
extern Moby* D_8006C65C;
typedef struct {Moby* actor;int unk04;} Decoded2058Record;
extern Decoded2058Record Decoded2058State __asm__("D_8006E788");
void Decoded2058Update(Decoded2058Record*,int) __asm__("func_80055854");
void Decoded2058Actor(Moby*) __asm__("func_80034DAC");
extern void (*Decoded2058Particles)(int) __asm__("UpdateParticles");
void func_atlas_80078AFC(void) {
 int shift;
 {register int mode __asm__("$3")=Decoded2058Mode;

 Decoded2058X=2048;
 if(mode>=10||mode==7)Decoded2058Y=-1300;
 else if(Decoded2058Value)Decoded2058Y=(Decoded2058Value-40)*-6+1100;
 else Decoded2058Y=430;}
 __asm__("" : : : "memory");
 {register int mode __asm__("$3")=Decoded2058Mode;
 __asm__("" : "=r"(mode) : "0"(mode));
 if(mode>=10||mode==7)Decoded2058Z=897;
 else Decoded2058Z=553-(D_8006FBCC-1)*172;}
 Decoded2058C=((int)(Decoded2058Angle<<16)>>20)+64;
 if(Decoded2058Shift) {
  shift=Decoded2058Shift/8-1;if(shift>=7)shift=6;
  if(Decoded2058Y<430)Decoded2058Y=430;
  Decoded2058Y<<=shift;
 }
 Decoded2058A=0;Decoded2058B=0;
 if(D_8006C65C) {
  Decoded2058State.actor=D_8006C65C;Decoded2058State.unk04=0;
  Decoded2058Update(&Decoded2058State,2);
  if(D_8006C648>=3)Decoded2058Update(&Decoded2058State,D_8006C648+0x7FFFFFFE);
  Decoded2058Actor(D_8006C65C);
 }
 if(Decoded2058Particles)Decoded2058Particles(D_8006C648);
}


INCLUDE_ASM("asm/nonmatchings/overlays/atlas/atlas2", func_atlas_80078D0C);

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
typedef struct { short current, previous; } Atlas799B0HalfPair;
extern Atlas799B0HalfPair Atlas799B0Pair __asm__("D_atlas_8007ADE4");
extern unsigned char D_80066FCC[],D_80071FB0[],D_8007014E;
extern short D_atlas_8007ADE6,D_atlas_8007ADEA;
extern int D_atlas_8007ADE0,D_8006E53C,D_8006C648;
extern int D_8006FBCC,D_8006FBC4,D_8006FBD4,D_80070148;
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
        __asm__ volatile("" : : : "memory");
        one = 1;
        __asm__("" : "=r"(one) : "0"(one));
        word = &D_80070148;
        __asm__("" : "=r"(word) : "0"(word) : "memory");
        D_8006FBC4 = 0;
        D_8006FBD4 = 0;
        D_8006FBCC = one;
        if (*word == 3) {
            *word = 0;
        }
    } else {
        if (D_8006E53C & 0x10) {
            func_8002A6E4();
            if ((short) (Atlas799B0Pair.current % 10) == 8) {
                D_atlas_8007ADEA = 4;
                D_atlas_8007ADE6 = 5;
            } else if ((short) (unsigned short)Atlas799B0Pair.current == 0x32) {
                D_atlas_8007ADEA = 6;
                D_atlas_8007ADE6 = 6;
            } else {
                D_atlas_8007ADEA = 2;
                D_atlas_8007ADE6 = Atlas799B0Pair.current / 10;
            }
            D_8006FBCC = 1;
            __asm__ volatile("" : : : "$4", "memory");
            step = D_8006C648;
            __asm__("" : "=r"(step) : "0"(step));
            modeValue = 4;
            goto storeModeAndStep;
        }
        if (D_8006E53C & 0x8000) {
            halfPair = &Atlas799B0Pair;
            __asm__("" : "=r"(halfPair) : "0"(halfPair));
            { register int current __asm__("$4") = halfPair->current;
            if (current >= 0xB) {
                D_atlas_8007ADE6 = func_atlas_800758B0(current);
                selectionValue = 8;
            } else {
                table = D_80066FCC+0x32;
                __asm__("" : "=r"(table) : "0"(table));
                if (*(D_80071FB0 + *table) != 0) {
                    selectionValue = 6;
                    D_atlas_8007ADE6 = selectionValue;
                } else if (*(D_80071FB0 + D_80066FCC[0x12]) != 0) {
                    D_atlas_8007ADE6 = 5;
                    selectionValue = 4;
                } else {
                    register int lookupIndex __asm__("$2") = D_80066FCC[0x28];
                    __asm__("" : "=r"(lookupIndex) : "0"(lookupIndex) : "$3");
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
            __asm__("" : "=r"(step) : "0"(step));
            modeValue = 4;
            goto storeModeAndStep;
        }
        if (D_8006E53C & 0x2000) {
            lookupResult = func_atlas_80075824((short) (unsigned short)Atlas799B0Pair.current);
            if ((lookupResult >= 0) && (*(D_80071FB0 + *(D_80066FCC + lookupResult)) != 0)) {
                D_atlas_8007ADE6 = lookupResult;
                D_atlas_8007ADEA = 8;
                func_8002A6E4();
                D_8006FBCC = 1;
                __asm__ volatile("" : : : "$6", "memory");
                step = D_8006C648;
                __asm__("" : "=r"(step) : "0"(step));
                modeValue = 3;
storeModeAndStep:
                D_atlas_8007ADE0 = modeValue;
                __asm__ volatile("" : : : "memory");
                D_8006FBC4 = -step;
            }
        }
    }
}


/* AI generated; not human reviewed. Retail numeric input/page branches. */
extern int D_8006E53C,D_8006FBCC,D_8006FBC4,D_8006FBD4,D_8006C648;
extern int Decoded2044Mode __asm__("D_atlas_8007ADE0");
extern short Decoded2044Page __asm__("D_atlas_8007AE0C");
extern short Decoded2044A __asm__("D_atlas_8007ADE6");
extern short Decoded2044B __asm__("D_atlas_8007ADEA");
extern int Decoded2044Word __asm__("D_80070148");
extern unsigned char Decoded2044Byte __asm__("D_8007014E");
void func_8002A6E4(void);
void func_atlas_80079D18(void) {
 int input=D_8006E53C;register int delta __asm__("$3");
 if(input&0x100) {
  func_8002A6E4();Decoded2044Mode=6;D_8006FBCC=1;
  D_8006FBC4=0;D_8006FBD4=0;Decoded2044Byte=1;
 } else if(input&0x800) {
  func_8002A6E4();Decoded2044Mode=6;
  __asm__("" : : : "$2","memory");
  {register int one __asm__("$2")=1;
  __asm__("" : "=r"(one) : "0"(one) : "$4","memory");
  {register int* word __asm__("$4")=&Decoded2044Word;
  __asm__("" : "=r"(word) : "0"(word) : "memory");
  D_8006FBC4=0;D_8006FBD4=0;D_8006FBCC=one;
  if(*word==3)*word=0;}}
 } else if(input&0x10) {
  func_8002A6E4();D_8006FBCC=1;Decoded2044Mode=4;
  __asm__("" : : : "memory");
  {register unsigned int page __asm__("$2")=(unsigned short)Decoded2044Page;
  register int step __asm__("$3")=D_8006C648;
  __asm__("" : "=r"(page),"=r"(step) : "0"(page),"1"(step) : "memory");
  Decoded2044A=0;Decoded2044B=0;
  __asm__("" : "=r"(page) : "0"(page) : "memory");
  Decoded2044Page=page-1;delta=-step;goto storeDelta;}
 } else if(input&0x8000) {
  func_8002A6E4();
  {register short* page __asm__("$3")=&Decoded2044Page;
  __asm__("" : "=r"(page) : "0"(page));
  --*page;
  if(*page<0){Decoded2044A=0;Decoded2044B=0;}}
  D_8006FBCC=1;Decoded2044Mode=4;D_8006FBC4=-D_8006C648;
 } else if(input&0x2000) {
  register short* page __asm__("$16")=&Decoded2044Page;
  __asm__("" : "=r"(page) : "0"(page));
  if(*page<3) {
   func_8002A6E4();D_8006FBCC=1;Decoded2044Mode=3;
   {register unsigned int value __asm__("$2")=(unsigned short)*page;
    delta=D_8006C648;
    __asm__("" : "=r"(value),"=r"(delta) : "0"(value),"1"(delta));
    value++;delta=-delta;*page=value;}
   storeDelta:__asm__("" : "=r"(delta) : "0"(delta));D_8006FBC4=delta;
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
            __asm__ volatile("" : : : "memory");
            one = 1;
            __asm__("" : "=r"(one) : "0"(one));
            wordPointer = &D_80070148;
            __asm__("" : "=r"(wordPointer) : "0"(wordPointer) : "memory");
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
            if (((D_atlas_8007AE0E != 0x14) && (D_atlas_8007AE06 == 5)) || (D_atlas_8007AE06 >= 0xB)) {
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
            __asm__("" : "=r"(one) : "0"(one));
            copiedHalf = (unsigned short)D_atlas_8007AE08;
            D_8006FBC4 = 0;
            D_8006FBCC = one;
            /* Retain the original split SLL/store/SRA sequence. */
            signedHalfArgument = copiedHalf << 16;
            __asm__("" : "=r"(signedHalfArgument) : "0"(signedHalfArgument));
            D_atlas_8007AE06 = copiedHalf;
            signedHalfArgument >>= 16;
            goto finishHalfCopy;
        }
        halfPointer = &D_atlas_8007AE06;
        if ((*halfPointer == 0xB) && ((D_8006E538 & 0xA0) == 0xA0)) {
            one = 1;
            __asm__("" : "=r"(one) : "0"(one));
            copiedHalf = (unsigned short)D_atlas_8007AE08;
            D_8006FBC4 = 0;
            D_8006FBCC = one;
            signedHalfArgument = (short)copiedHalf;
            __asm__("" : "=r"(signedHalfArgument) : "0"(signedHalfArgument));
            *halfPointer = copiedHalf;
finishHalfCopy:
            D_atlas_8007ADE6 = copiedHalf + 0x64;
            func_atlas_80075CA8(signedHalfArgument);
            D_atlas_8007ADE0 = 3;
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/atlas/atlas2", func_atlas_8007A1A8);
