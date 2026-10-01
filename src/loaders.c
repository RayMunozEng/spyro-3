#include "common.h"
#include "init.h"
#include "stdutil.h"
#include "loaders.h"
#include "spu.h"
#include "str.h"

// spyroupdate
extern void func_80047190();

// sdata
extern Particle* D_8006C554; // partsArrayPtr, like first moby ptr?
extern Particle* D_8006C614; // another parts related pointer it seems

// bss
extern WadHeader wadHeader;
extern SpeedwayData speedwayData; // 8006FA38

// bss - probably need structs or retyping
extern int D_8006DEF8[64]; // unknown ints
extern int D_8006E1F4[80]; // something moby dialogue related apparently?
extern int D_80070260[40]; // something drawing related, seems to be its own struct or array
extern char D_80070610[3456]; // fuck knows, may not even be chars
extern char D_80072430[384]; // fuck knows, may not even be chars

////////////////////////////////////////////////////////////////////////////////////

/**
 * ???() - func_8002AE00() - MATCHING
 * Speedway related (or rather, when not in speedways)
 * https://decomp.me/scratch/py5DN
 */
void func_8002AE00() {
    func_8002D044();
    speedwayData.speedwayIndex = -1;
    func_80047190();
}

extern void* volatile D_8006EE2C;
extern char* D_8006C558;
extern char* D_8006C4FC;
extern int D_800722E0;
/* Retail source: asm/nonmatchings/loaders/func_8002AE34.s,
 * 0x8002AE34..0x8002AF9C; indexed stream relocations and size bounds. */
void func_8002AE34(int* stream, int* end) {
    volatile char scratch[8];
    register int i asm("$7") = 0;
    register int* slot asm("$6");
    register int* limit asm("$9");
    register int sentinel asm("$8");
    int count = *(volatile int*)D_8006EE2C;
    if (count > 0) {
        limit = &D_800722E0;
        sentinel = -1;
        slot = (int*)D_8006C558;
        do {
            int value;
            __asm__ volatile("nop");
            value = *slot;
            if ((unsigned)value < (unsigned)*limit || value == sentinel) *slot = 0;
            count = *(volatile int*)D_8006EE2C;
            __asm__ volatile ("" : "=r"(count) : "0"(count));
            i++;
            slot++;
        } while (i < count);
    }
    {
        register char* input asm("$4") = (char*)stream;
        register int* entries asm("$9");
        register char* relocation asm("$7");
        register int size asm("$8");
        register int* selected asm("$6");
        register int* bound asm("$5") = end;
        register int value asm("$2") = *(int*)input;
        input += 4;
        if (value < 0) return;
        entries = (int*)D_8006C558;
        relocation = D_8006C4FC;
        do {
            register int* entry asm("$3");
            int byteOffset;
            size = *(int*)input;
            input += 4;
            selected = (int*)((value << 2) + (int)entries);
            __asm__ volatile ("" : "=r"(selected) : "0"(selected));
            *selected = (int)input;
            byteOffset = (unsigned char)*input * 20 + 20;
            *(int*)(input + 4) = (int)(input + byteOffset);
            entry = (int*)*selected; __asm__ volatile ("" : "=r"(entry) : "0"(entry));
            if ((unsigned)((char*)entry + 8) < (unsigned)bound) {
                entry[2] = (int)relocation + entry[2];
                entry = (int*)*selected; __asm__ volatile ("" : "=r"(entry) : "0"(entry));
            }
            if ((unsigned)((char*)entry + 12) < (unsigned)bound) entry[3] = (int)relocation + entry[3];
            { register int* finalEntry asm("$6") = (int*)*selected;
              __asm__ volatile ("" : "=r"(finalEntry) : "0"(finalEntry));
              if ((unsigned)((char*)finalEntry + 16) < (unsigned)bound)
                  finalEntry[4] = finalEntry[1] + finalEntry[4]; }
            input += size;
            value = *(int*)input;
            input += 4;
        } while (value >= 0);
    }
}

/* Retail source: USA Rev 0 PSX.EXE 0x8002AF9C..0x8002B31C (224 words).
 * Walks one of two packed record shapes and relocates only fields whose source
 * addresses are below the unsigned block end. The root is published through
 * D_8006EE2C once per call. Rev 1 0x8002AFC0 independently confirms the two
 * shapes. Units: byte offsets and absolute 32-bit pointers; negative-shape
 * adjustments are unsigned 16-bit fields. Cadence: one bounded pass per call,
 * followed by one D_8006EE2C[type] publication. Confidence: confirmed retail
 * exact: PSX.EXE SHA-256 e5406997...e39f and all 62 manifest hashes.
 * Falsifiable vectors: root at end, both root signs, null optional fields, each
 * end-boundary slot, and the positive shape's +28 null fallback. */
void func_8002AF9C(int* arg0, int arg1, int* arg2) {
    volatile char stackSpace[16];
    register char* base __asm__("$12") = (char*)arg0;
    register char* root __asm__("$9") = base;
    register int firstWord __asm__("$2");
    register int index __asm__("$10");
    register int fieldOffset __asm__("$7");
    register char* cursor __asm__("$3");
    register char* record __asm__("$4");
    int count;

    if ((unsigned)root >= (unsigned)arg2) return;
    __asm__ volatile("lw %0,0(%1)" : "=r"(firstWord) : "r"(root));
    index = 0;
    if (firstWord < 0) {
        register char* negativeRoot __asm__("$8");
        __asm__("move %0,%1" : "=r"(negativeRoot) : "r"(root));
        fieldOffset = 8;
        __asm__("move %0,%1" : "=r"(cursor) : "r"(root));
        do {
            int value = *(int*)(cursor + 8);
            if (value != 0 && (unsigned)(negativeRoot + fieldOffset) < (unsigned)arg2) {
                *(int*)(cursor + 8) = (int)base + value;
            }
            fieldOffset += 4;
            index++;
            cursor += 4;
        } while (index < 2);
        if ((unsigned)(negativeRoot + 16) < (unsigned)arg2) {
            *(int*)(negativeRoot + 16) = (int)base + *(int*)(negativeRoot + 16);
        }
        count = -*(int*)negativeRoot;
        *(int*)negativeRoot = count;
        index = 0;
        if (count > 0) {
            register char* nestedCursor __asm__("$7") = negativeRoot;
            register int nestedOffset __asm__("$11") = 20;
            do {
                if ((unsigned)(negativeRoot + nestedOffset) < (unsigned)arg2) {
                    *(int*)(nestedCursor + 20) = (int)base + *(int*)(nestedCursor + 20);
                }
                record = *(char**)(nestedCursor + 20);
                if ((unsigned)(record + 8) < (unsigned)arg2) {
                    *(unsigned short*)(record + 8) = *(unsigned short*)(record + 8) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                    record = *(char**)(nestedCursor + 20);
                    *(unsigned short*)(record + 10) = *(unsigned short*)(record + 10) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                }
                record = *(char**)(nestedCursor + 20);
                if ((unsigned)(record + 12) < (unsigned)arg2) {
                    *(unsigned short*)(record + 12) = *(unsigned short*)(record + 12) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                    record = *(char**)(nestedCursor + 20);
                    *(unsigned short*)(record + 14) = *(unsigned short*)(record + 14) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                }
                nestedCursor += 4;
                count = *(volatile int*)negativeRoot;
                index++;
                nestedOffset += 4;
            } while (index < count);
        }
        root = (char*)((unsigned)root & 0x7FFFFFFF);
    } else {
        index = 0;
        fieldOffset = 20;
        __asm__("move %0,%1" : "=r"(cursor) : "r"(root));
        do {
            int value = *(int*)(cursor + 20);
            if (value != 0 && (unsigned)(root + fieldOffset) < (unsigned)arg2) {
                *(int*)(cursor + 20) = (int)base + value;
            }
            fieldOffset += 4;
            index++;
            cursor += 4;
        } while (index < 8);
        if ((unsigned)(root + 52) < (unsigned)arg2) *(int*)(root + 52) = (int)base + *(int*)(root + 52);
        if ((unsigned)(root + 56) < (unsigned)arg2) *(int*)(root + 56) = (int)base + *(int*)(root + 56);
        index = 0;
        if (*(int*)root > 0) {
            register char* nestedCursor __asm__("$7") = root;
            register int nestedOffset __asm__("$8") = 60;
            do {
                if ((unsigned)(root + nestedOffset) < (unsigned)arg2) {
                    *(int*)(nestedCursor + 60) = (int)base + *(int*)(nestedCursor + 60);
                }
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 12) < (unsigned)arg2)
                    *(int*)(record + 12) = *(int*)(root + 56) + *(int*)(record + 12);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 16) < (unsigned)arg2)
                    *(int*)(record + 16) = *(int*)(root + 56) + *(int*)(record + 16);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 20) < (unsigned)arg2)
                    *(int*)(record + 20) = *(int*)(root + 56) + *(int*)(record + 20);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 24) < (unsigned)arg2 && *(int*)(record + 24) != 0) {
                    *(int*)(record + 24) = *(int*)(root + 56) + *(int*)(record + 24);
                }
                {
                    register char* specialRecord __asm__("$3") = *(char**)(nestedCursor + 60);
                    if ((unsigned)(specialRecord + 28) < (unsigned)arg2) {
                        register int specialValue __asm__("$4") = *(int*)(specialRecord + 28);
                        if (specialValue != 0)
                            *(int*)(specialRecord + 28) = *(int*)(root + 56) + specialValue;
                        else
                            *(int*)(specialRecord + 28) = *(int*)(specialRecord + 20);
                    }
                }
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 32) < (unsigned)arg2)
                    *(int*)(record + 32) = *(int*)(root + 56) + *(int*)(record + 32);
                nestedCursor += 4;
                count = *(volatile int*)root;
                index++;
                nestedOffset += 4;
            } while (index < count);
        }
    }
    ((int*)&D_8006EE2C)[arg1] = (int)root;
}

extern int D_8006C5C8;
extern int* D_8006D050;
extern int* D_8006D054;
extern int D_8006D058;
extern volatile int* volatile D_8006D070;
extern int D_8006D074;
extern int D_8006F600[];
extern int D_800720A8;
extern int D_800720AC;
extern int D_80072138;
extern int D_8007213C;
extern int D_80072140;
/* Retail source: USA Rev 0 PSX.EXE 0x8002B31C..0x8002B5EC
 * (180 words). The image rectangle uses signed 16-bit SDK coordinates and
 * dimensions; loaded block references are byte offsets until this routine
 * relocates them against the block base. This runs once for each loaded block.
 * Confidence is exact: falsify by comparing all 180 rebuilt words, the retail
 * executable SHA-256, and every overlay SHA-256 in sha256sum.txt. */
int func_8002B31C(int* input, int* end) {
    RECT image;
    register int initialOffset __asm__("$2") = D_800720AC;
    register char* base __asm__("$19") = (char*)input;
    register int* bound __asm__("$21") = end;
    register char* result __asm__("$22");
    register int* tableBase __asm__("$20");
    register int* tableEnd __asm__("$18");
    register short* type __asm__("$17");
    register int* entry __asm__("$16");
    int* cursor;

    result = base + initialOffset;
    {
        register int* block __asm__("$2") =
            (int*)(base + *(int*)base);
        register int imageX __asm__("$6") = ((volatile int*)block)[0];
        register int imageY __asm__("$7") = ((volatile int*)block)[1];
        register int imageW __asm__("$3") = ((volatile int*)block)[2];
        register int imageH __asm__("$5") = ((volatile int*)block)[3];
        if (imageW != 0 && imageH != 0) {
        register char* imageData __asm__("$16");
        imageData = (char*)block[4];
        image.x = imageX;
        image.y = imageY;
        image.w = imageW;
        image.h = imageH;
        imageData += 0x10;
        imageData = (char*)block + (int)imageData;
        LoadImage(&image, (unsigned long*)imageData);
        result = imageData;
        }
    }
    if (D_8006C5C8 == 0) {
        register int* first __asm__("$5");
        register int* second __asm__("$4") = (int*)base + 1;
        register int offset __asm__("$2") = ((int*)base)[1];
        int* third;
        first = second;
        second = (int*)((char*)second + offset);
        if (offset < 9) {
            D_8006D050 = first;
            D_8006D074 = 0x18000;
            D_8006D058 = 0;
        } else {
            D_8006D074 = 0x2C000;
            D_8006D050 = (int*)base + 2;
            D_8006D058 = 1;
        }
        first = second;
        second = (int*)((char*)second + *second);
        if (*first < 9) {
            D_8006D054 = first;
            *first = -1;
        } else {
            register int* next __asm__("$2") = first + 1;
            D_8006D054 = next;
        }
        third = second;
        if (*third == -2) {
            register int* relocation __asm__("$4") = third + 2;
            D_8006D070 = relocation;
            { volatile int* p = D_8006D070; p[3] = (int)((char*)relocation + p[3]); }
            { volatile int* p = D_8006D070; p[4] = (int)((char*)relocation + p[4]); }
            { volatile int* p = D_8006D070; p[5] = (int)((char*)relocation + p[5]); }
            { volatile int* p = D_8006D070; p[6] = (int)((char*)relocation + p[6]); }
            { volatile int* p = D_8006D070; p[7] = (int)((char*)relocation + p[7]); }
            {
                volatile int* p = D_8006D070;
                register int relocated __asm__("$2") =
                    (int)((char*)relocation + p[8]);
                p[8] = relocated;
            }
        }
    }
    func_8002AE34((int*)(base + (D_80072138 - D_800720A8)), bound);
    {
        int i = 0x1F5;
        cursor = D_8006F600;
        do {
            *cursor = 0;
            i++;
            cursor++;
        } while (i < 0x1FA);
    }
    {
    register int* table __asm__("$4") = &D_8007213C;
    if (D_80072140 > 0) {
        tableBase = table - 1;
        tableEnd = table + 1;
        type = (short*)((char*)table + 0xFE);
        entry = table;
        do {
            register int callType __asm__("$5");
            register int callOffset __asm__("$4");
            register int baseOffset __asm__("$2");
            register int* callBound __asm__("$6");
            tableEnd++;
            callType = *type;
            type++;
            callOffset = *(volatile int*)entry;
            baseOffset = *(volatile int*)(tableBase - 36);
            __asm__ volatile("" : "=r"(callType), "=r"(callOffset),
                                  "=r"(baseOffset), "=r"(type) :
                                  "0"(callType), "1"(callOffset),
                                  "2"(baseOffset), "3"(type));
            callBound = bound;
            callOffset -= baseOffset;
            func_8002AF9C(
                (int*)(base + callOffset), callType, callBound);
            entry++;
        } while (*tableEnd > 0);
    }
    }
    return (int)result;
}

/**
 * ???() - func_8002B5EC()
 * A bit of a mess, not quite there yet
 * Seems to turn some data offsets to pointers
 * https://decomp.me/scratch/ULX4S
 */
extern void* volatile D_8006EE2C;
extern char* D_8006C558;
extern char* D_8006C4FC;
void func_8002B5EC(void* arg0) {
    char* base = (char*)arg0;
    int stackSlot;
    register int* item __asm__("$5");
    volatile int* header;
    char* loopData;
    char* data;
    int count;
    int i;
    __asm__ volatile ("" : : "m"(stackSlot));
    D_8006EE2C = base;
    __asm__ volatile ("" : "=r"(base) : "0"(base));
    header = (volatile int*)D_8006EE2C;
    item = (int*)(base + 0x3C);
    D_8006C558 = (char*)item;
    {
        int offset = *(volatile int*)((char*)header + 0x38);
        count = *header;
        data = base + offset;
    }
    D_8006C4FC = data;
    if (count > 0) {
        register int sentinel __asm__("$8");
        i = 0;
        __asm__ volatile ("" : "=r"(i) : "0"(i));
        sentinel = -1;
        __asm__ volatile ("" : "=r"(sentinel) : "0"(sentinel));
        loopData = data;
        do {
            int offset = *item;
            if (offset != sentinel) {
                int* p = (int*)(base + offset);
                *item = (int)p;
                p[1] = (int)loopData + p[1];
                p = (int*)*item;
                p[2] = (int)loopData + p[2];
                p = (int*)*item;
                p[3] = (int)loopData + p[3];
                p = (int*)*item;
                p[4] = (int)loopData + p[4];
            }
            { int limit = *(volatile int*)D_8006EE2C;
              __asm__ volatile ("addiu %0, %0, 1" : "=r"(i) : "0"(i), "r"(limit));
              item++;
              if (i >= limit) break;
            }
        } while (1);
    }
}

extern unsigned char* D_8006E340;
extern unsigned char D_8006E33C;
extern unsigned char D_8006E33D;
extern unsigned char D_8006E33E;
extern int D_8006E334;
extern unsigned char* D_8006E338;
void func_8002B6C8(void) {
    int stackSlot;
    register unsigned char** slot __asm__("$3") = &D_8006E340;
    register unsigned char** loopSlot __asm__("$6");
    unsigned char* source = *slot;
    int count;
    int i;
    if (source != 0) {
        __asm__ volatile ("" : : "m"(stackSlot));
        D_8006E33C = source[0];
        D_8006E33D = source[1];
        D_8006E33E = source[2];
        source += 4;
        count = *(int*)source;
        source += 4;
        D_8006E338 = source;
        D_8006E334 = count;
        i = 0;
        if (count > 0) {
            loopSlot = slot;
            __asm__ volatile ("" : "=r"(loopSlot) : "0"(loopSlot));
            do {
                *(int*)source = (int)*loopSlot + *(int*)source;
                i++;
                source += 4;
            } while (i < *(int*)((char*)loopSlot - 12));
        }
        D_8006E340 = 0;
    }
}

/**
 * ???() - func_8002B768() - MATCHING
 * https://decomp.me/scratch/XKB8s
 */
void func_8002B768(Particle* arg0) {
    D_8006C554 = arg0;
    D_8006C614 = arg0;
    arg0->unk1 = 0xFF;
    *(int*)&D_8006C554[256].unk0 = -1;
    
    memset(D_8006E1F4, 0, 0x140);
    memset(D_8006DEF8, 0, 0x100);
    memset((int*)D_80072430, 0, 0x180);
    memset((int*)D_80070610, 0, 0xD80);
    memset(D_80070260, 0, 0xA0);
}

/**
 * LoadLayout() - func_8002B810()
 * WIP
 * https://decomp.me/scratch/XH66Q
 */
INCLUDE_ASM("asm/nonmatchings/loaders", func_8002B810);

/**
 * ???() - func_8002C9F4() - MATCHING
 * https://decomp.me/scratch/bMIyg
 */
void func_8002C9F4(char* pData, int pPatchAddressesInTable) {
    int soundCount;

    g_SoundTablePtr = (SoundTable*)pData;
    pData += 0x100; // sizeof(SoundTable)

    soundCount = *(int*)pData;
    pData += sizeof(int);
    
    g_SpuDefinitionsPtr = (SoundDefinition*)pData;
    
    if (pPatchAddressesInTable) {
        while (--soundCount >= 0) {
            g_SpuDefinitionsPtr[soundCount].m_Addr += 0x1010;
        }
    }
}

/* USA Rev 0 retail executable, 0x8002CA50..0x8002D044.
 * 1524 bytes (381 instructions). The two integrity scans operate on raw
 * executable bytes; pointer arithmetic is therefore byte-sized. Called once
 * per loader update while the load state is active. Confidence: confirmed by
 * normalized object comparison. Test vector: compile this TU, link PSX.EXE,
 * and verify the repository retail SHA-256 manifest. */
extern unsigned char D_80065878[];
extern unsigned int D_8006C518;
extern signed int D_8006C54C, D_8006C58C, D_8006C5BC, D_8006C658;
extern signed int D_8006C6B4, D_8006C6F8, D_8006C714, D_8006C720;
extern signed int D_8006C774, D_8006DB00, D_8006DB04;
extern unsigned char *D_8006C6B8;
extern unsigned char D_8006D910[], D_8006D914[];
extern unsigned char D_8006DBE8[], D_8006DBEC[];
extern signed int D_8006E344, D_8006E470;
extern signed short D_800719D6, D_800719D8, D_800719DA, D_800719DE;
extern signed int D_80071A10[];
extern void *D_80011254, *D_800722B8;
extern signed int MobyUpdate;
extern unsigned char loading_text_end, loading_text_start;
extern unsigned char main, main_DATA_START, main_TEXT_START;

void func_8002CA50(void) {
    register signed int *var_v1 asm("$3");
    signed int temp_v0;
    signed int temp_v0_2;
    signed int temp_v1_2;
    signed int temp_v1_4;
    signed int var_a0;
    signed int var_a0_2;
    register signed int var_a0_3 asm("$4");
    signed int var_a1;
    signed int var_a1_2;
    register signed int var_a2 asm("$6");
    register signed int var_a3 asm("$7");
    register signed int loadA0 asm("$4");
    register void *loadA1 asm("$5");
    register signed int savedDb04 asm("$3");
    unsigned int temp_a0;
    unsigned char *temp_v1_3;
    register unsigned char *temp_v1 asm("$8");
    register signed int *db04 asm("$16");
    register unsigned char *initialEnd asm("$3");
    register signed int poly asm("$6");
    register signed int mask asm("$7");

    if (CDLoadTime() != 0) {
        if ((unsigned int) (D_8006C518 - 2) < 6U) {
            if (D_8006C6B8 == 0) {
                D_8006C6B8 = &main_TEXT_START + 1 - 0x473E;
            }
            initialEnd = &main_DATA_START - 0x473E;
            if ((unsigned int) D_8006C6B8 < (unsigned int) initialEnd) {
                var_a1 = 0;
                temp_v1 = initialEnd;
                mask = 0x800000;
                poly = 0x400280;
                __asm__ volatile ("" : : "r" (temp_v1), "r" (mask), "r" (poly) : "memory");
loop_6:
                if ((unsigned int) D_8006C6B8 < (unsigned int) temp_v1) {
                    var_a0 = 8;
                    D_8006C6B4 ^= D_8006C6B8[0x473E] << 0xF;
                    do {
                        temp_v1_2 = D_8006C6B4 * 2;
                        D_8006C6B4 = temp_v1_2;
                        var_a0 -= 1;
                        if (temp_v1_2 & mask) {
                            D_8006C6B4 = temp_v1_2 ^ poly;
                        }
                    } while (var_a0 != 0);
                    var_a1 += 1;
                    temp_v1_3 = D_8006C6B8 + (((signed int) (D_8006C6B4 & 0x180) >> 7) + 1);
                    D_8006C6B8 = temp_v1_3;
                    if (var_a1 >= 0x1400) {
                        if (temp_v1_3 >= (&main_DATA_START - 0x473E)) {
                            goto block_13;
                        }
                    } else {
                        goto loop_6;
                    }
                } else {
block_13:
                    D_8006C6B8 = &loading_text_start - 0x473E;
                }
            }
            var_a1_2 = 0;
            if ((unsigned int) D_8006C6B8 >= (unsigned int) (&loading_text_start - 0x473E)) {
                temp_v1 = &loading_text_end - 0x473E;
                mask = 0x800000;
                poly = 0x400280;
                __asm__ volatile ("" : : "r" (temp_v1), "r" (mask), "r" (poly) : "memory");
loop_16:
                if ((unsigned int) D_8006C6B8 < (unsigned int) temp_v1) {
                    var_a0_2 = 8;
                    D_8006C6B4 ^= D_8006C6B8[0x473E] << 0xF;
                    do {
                        temp_v1_4 = D_8006C6B4 * 2;
                        D_8006C6B4 = temp_v1_4;
                        var_a0_2 -= 1;
                        if (temp_v1_4 & mask) {
                            D_8006C6B4 = temp_v1_4 ^ poly;
                        }
                    } while (var_a0_2 != 0);
                    var_a1_2 += 1;
                    D_8006C6B8 += 1;
                    if (var_a1_2 >= 0x1400) {

                    } else {
                        goto loop_16;
                    }
                }
                if (D_8006C6B8 == (&loading_text_end - 0x473E)) {
                    D_8006C6B8 += 0x473E;
                }
            }
        }
    } else {
        switch (D_8006C518) {
        case 0:
            func_800282D8();
            db04 = &D_8006DB04;
            __asm__ volatile ("" : "=r" (db04) : "0" (db04));
            CDLoadAsync(D_8006E470, D_80011254, *db04, D_8006DB00);
            savedDb04 = *db04;
            __asm__ volatile ("" : "=r" (savedDb04) : "0" (savedDb04));
            D_8006C518 = 1;
            D_8006C714 = savedDb04;
            return;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            func_loading_8007494C();
            return;
        case 8:
            if ((D_8006C6B8 != &loading_text_end) || (D_8006C6B4 != 0)) {
                ((signed int *)&func_8002AB38)[rand() & 0x3F] = 0;
            } else {
                D_8006C6B8 = 0;
                D_8006C6B4 = 0;
            }
            if (D_8006E344 != 4) {
                if (D_8006C5BC < 0x3C) {
                    if (D_8006C658 != 0) {
                        var_a0_3 = (D_80065878[D_8006C58C] << 0xA) - 0x1000;
                    } else {
                        var_a0_3 = D_80065878[D_8006C58C] << 0xA;
                    }
                } else {
                    var_a0_3 = D_80065878[0] << 0xA;
                }
                func_8001FB10(var_a0_3);
                func_8002B6C8();
            }
            if (D_8006C5BC >= 0x3C) {
                loadA0 = D_8006E470;
                temp_v0 = D_8006C58C * 0x18;
                loadA1 = D_800722B8;
                var_a2 = *(signed int *)((unsigned char *)D_8006D914 + temp_v0);
                var_a3 = *(signed int *)((unsigned char *)D_8006D910 + temp_v0);
                __asm__ volatile ("" : : "r" (loadA0), "r" (loadA1), "r" (var_a2), "r" (var_a3));
            } else {
                loadA0 = D_8006E470;
                temp_v0_2 = D_8006C58C * 0x10;
                loadA1 = D_800722B8;
                var_a2 = *(signed int *)((unsigned char *)D_8006DBEC + temp_v0_2);
                var_a3 = *(signed int *)((unsigned char *)D_8006DBE8 + temp_v0_2);
                __asm__ volatile ("" : : "r" (loadA0), "r" (loadA1), "r" (var_a2), "r" (var_a3));
            }
            CDLoadAsync(loadA0, loadA1, var_a2, var_a3);
            D_800719D6 = 0;
            D_800719D8 = 0;
            D_800719DA = 0;
            D_800719DE = 0;
            D_8006C518 = 9;
            return;
        case 9:
            D_8006C518 = 0xC;
            return;
        case 10:
        case 11:
            VSync(0);
            D_8006C518 += 1;
            return;
        case 12:
            if (MobyUpdate != 0) {
                if (D_8006C5BC < 0x3C) {
                    temp_a0 = *(unsigned int *)((unsigned char *)D_800722B8 + 4);
                    var_v1 = (signed int *)((unsigned char *)D_800722B8 + 0x1000);
                    if ((unsigned int) var_v1 < temp_a0) {
                        do {
                            *var_v1 ^= temp_a0;
                            var_v1 += 1;
                        } while ((unsigned int) var_v1 < temp_a0);
                    }
                }
            }
            func_8005E0BC(1, 0, 0);
            if ((D_8006E344 != 4) && (D_8006C5BC < 0x3C)) {
                D_8006C6F8 = 0;
                D_8006C720 = D_80071A10[D_8006C58C];
            }
            D_8006C518 = -1U;
            D_8006C774 = 0;
            D_8006C54C = D_8006C58C + (signed int)(&main + 2);
            /* fallthrough */
        default:
            return;
        }
    }
}


/**
 * ???() - func_8002D044() - MATCHING
 * Defines cdState and loadingData
 * Note that some variables in here (modelsEnd and modelsStart) are hardcoded
 * I'm not sure if these are actually relative to something
 * https://decomp.me/scratch/HBeBQ
 */
void func_8002D044() {
    CDLoadSync(cdState.wadSector, (int*)0x801AE800, wadHeader.spyroMdls.size, wadHeader.spyroMdls.offset);
    
    loadingData.D_800722e0 = (int*)(0x801FF800 - *(int*)0x801AE800); // D_801AE800; modelsEnd
    func_8004E828(loadingData.D_800722e0, (int*)0x801AF000, *(int*)0x801AE800); // D_801AE800
    
    func_8002B5EC((void*)(((int)loadingData.D_800722e0 + *(int*)0x801AE804) - 0x800)); // D_801AE804; modelsStart
    func_8002AA34();
}
