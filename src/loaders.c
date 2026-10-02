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
/* Retail source: asm/nonmatchings/loaders/func_8002B810.s,
 * SCUS-94467 USA Rev 0, 0x8002B810..0x8002C9F4.
 * Loads and relocates a layout once per invocation. Pointer offsets are bytes;
 * packed fields retain their retail widths, shifts and signedness.
 * Verification vector: all 1,145 instructions and the complete executable/
 * overlay SHA-256 checks match. Register constraints emit no instructions;
 * they preserve GCC 2.7.2's retail temporary register selection for /10.
 */
#define DIV10(v) ({ \
    int quotient; \
    register int scratch9 asm("$9"); \
    register int scratch10 asm("$10"); \
    register int scratch11 asm("$11"); \
    register int scratch12 asm("$12"); \
    register int scratch13 asm("$13"); \
    register int scratch14 asm("$14"); \
    register int scratch15 asm("$15"); \
    register int scratch24 asm("$24"); \
    register int scratch25 asm("$25"); \
    __asm__("" : "=r"(scratch9), "=r"(scratch10), "=r"(scratch11), \
        "=r"(scratch12), "=r"(scratch13), "=r"(scratch14), "=r"(scratch15), \
        "=r"(scratch24), "=r"(scratch25)); \
    quotient = (v) / 10; \
    __asm__ volatile("" : : "r"(scratch9), "r"(scratch10), "r"(scratch11), \
        "r"(scratch12), "r"(scratch13), "r"(scratch14), "r"(scratch15), \
        "r"(scratch24), "r"(scratch25)); \
    quotient; \
})
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern int D_8006C5BC,D_8006C58C,D_8006C658,D_80071928,D_8006E344;
int func_80012BA8(int *);                   /* extern */
int func_8001A310(Vector3D *, int, int, void *); /* extern */
int func_8001A358(Vector3D *, int);             /* extern */
int func_80021A70();                            /* extern */
int func_80027B70();                            /* extern */
int func_8003038C();                            /* extern */
void *func_80036A68(void *, int, int, Vector3D *); /* extern */
int func_8003B918(int *);                       /* extern */
int func_8004BEF8(int);                     /* extern */
int func_8004F52C(Vector3D *, void *);          /* extern */
int func_80050B90();                            /* extern */
int func_80055B18(void *);                      /* extern */
int func_80055C24(void *);                      /* extern */
int func_80055D10(void *);                      /* extern */
int func_8005629C(void *);                      /* extern */
int srand(int);                             /* extern */
extern int D_80067150;
extern int D_80067178;
extern int D_8006717E;
extern int D_800671B8;
extern int D_800671D4;
extern int D_80068F7C;
extern int D_8006C4F4;
extern int D_8006C508;
extern int D_8006C52C;
extern void *D_8006C530;
extern int *D_8006C538;
extern void *D_8006C550;
extern int *D_8006C55C;
extern int D_8006C568;
extern int D_8006C574;
extern int D_8006C578;
extern int D_8006C580;
extern int D_8006C588;
extern int D_8006C590;
extern int D_8006C5B8;
extern int D_8006C5E0;
extern int D_8006C5E8;
extern void *D_8006C5EC;
extern int D_8006C60C;
extern void *D_8006C610;
extern int D_8006C618;
extern int D_8006C61C;
extern int D_8006C628;
extern int D_8006C640;
extern int D_8006C644;
extern int D_8006C64C;
extern int D_8006C650;
extern int D_8006C65C;
extern char D_8006C670;
extern int D_8006C678;
extern int D_8006C6C4;
extern int D_8006C6C8;
extern int D_8006C6CC;
extern void *D_8006C704;
extern void *D_8006C728;
extern void *D_8006C730;
extern void *D_8006C738;
extern int D_8006C73C;
extern char D_8006C748;
extern int D_8006C74C;
extern void *D_8006C754;
extern void *D_8006C758;
extern int D_8006C76C;
extern int D_8006C784;
extern void *D_8006C788;
extern int D_8006C79C;
extern int D_8006C7C4;
extern int *D_8006C7E0;
extern int D_8006D088;
extern int D_8006D08C;
extern int D_8006D0B8;
extern int D_8006D8D0;
extern int D_8006E038;
extern int D_8006E350;
extern void **D_8006E354;
extern int D_8006E358;
extern void **D_8006E35C;
extern int D_8006E360;
extern void **D_8006E364;
extern int D_8006E368;
extern void **D_8006E36C;
extern int D_8006E370;
extern void **D_8006E374;
extern int D_8006E378;
extern void **D_8006E37C;
extern int D_8006E380;
extern void **D_8006E384;
extern int D_8006E388;
extern int D_8006E38C;
extern int D_8006FA38;
extern int D_8006FA3C;
extern int D_8006FA40;
extern unsigned char D_8006FC15;
extern unsigned char D_8006FC16;
extern unsigned char D_8006FC17;
extern unsigned char D_8006FC89;
extern unsigned char D_8006FC8A;
extern unsigned char D_8006FC8B;
extern Vector3D D_80070328;
extern int D_80071484;
extern unsigned char D_80071599;
extern int D_8007179C;
extern int D_800717AC;
extern int D_800717B0;
extern char D_80071A0D;
extern int D_80071AB0;
extern int D_80071FB0;
extern int D_8007209C;
extern int D_800722C8;
extern int *D_800722CC;
extern int D_80072330;
extern int (*SpawnMoby)(int, int, int);

void *func_8002B810(void *arg0) {
    struct { Vector3D v10; int gap1c[3]; int f28; char gap2c[84]; } frame;
    register char *var_v1 asm("$3");
    int var_a0_6;
    register Vector3D *temp_s0_2 asm("$16");
    register Vector3D *temp_s0_3 asm("$16");
    register Vector3D *temp_s2_2 asm("$18");
    register Vector3D *temp_s3_3 asm("$19");
    register int temp_v1_5 asm("$3");
    int *temp_a0;
    int *temp_a0_2;
    register int *temp_s0 asm("$16");
    register int *temp_s1_6 asm("$17");
    register int *temp_s5 asm("$21");
    register int *temp_s5_10 asm("$21");
    register int *temp_s5_9 asm("$21");
    register int *var_s1_10 asm("$17");
    register int *var_s1_12 asm("$17");
    register int *var_s1_2 asm("$17");
    register int *var_s5 asm("$21");
    register unsigned int temp_hi asm("$18");
    register int temp_s1_8 asm("$17");
    register int temp_s1_9 asm("$17");
    register int temp_s3 asm("$19");
    register int temp_s3_2 asm("$19");
    register int temp_s7 asm("$23");
    int temp_v0;
    register int temp_v0_10 asm("$2");
    register int temp_v0_13 asm("$2");
    register int temp_v0_14 asm("$2");
    int temp_v0_16;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_8;
    int temp_v1;
    register int temp_v1_4 asm("$3");
    register int temp_v1_7 asm("$3");
    register int temp_v1_8 asm("$3");
    register int var_a0_2 asm("$4");
    register int var_a0_3 asm("$4");
    register int var_a1 asm("$5");
    register int var_a2 asm("$6");
    register int var_s0 asm("$16");
    register int var_s0_2 asm("$16");
    register int var_s2 asm("$18");
    register int var_s2_2 asm("$18");
    register int var_s2_3 asm("$18");
    register int var_s2_4 asm("$18");
    register int var_s2_5 asm("$18");
    register int var_s2_6 asm("$18");
    register int var_s2_7 asm("$18");
    register int var_s2_8 asm("$18");
    register int var_s2_9 asm("$18");
    register int var_s6 asm("$22");
    register int var_v0 asm("$2");
    register int var_v0_3 asm("$2");
    int var_v0_4;
    char *var_a0;
    unsigned char temp_v0_12;
    unsigned char temp_v1_6;
    register int var_a0_4 asm("$4");
    register int var_a0_5 asm("$4");
    void **temp_v0_11;
    register void **var_s1_11 asm("$17");
    register void **var_s1_3 asm("$17");
    register void **var_s1_4 asm("$17");
    register void **var_s1_5 asm("$17");
    register void **var_s1_6 asm("$17");
    register void **var_s1_7 asm("$17");
    register void **var_s1_8 asm("$17");
    register void **var_s1_9 asm("$17");
    register void **var_v1_2 asm("$3");
    void *temp_a0_3;
    void *temp_a1;
    register void *temp_s1 asm("$17");
    register void *temp_s1_2 asm("$17");
    register void *temp_s1_3 asm("$17");
    register void *temp_s1_4 asm("$17");
    register void *temp_s1_5 asm("$17");
    register void *temp_s1_7 asm("$17");
    register void *temp_s2 asm("$18");
    register void *temp_s3_4 asm("$19");
    register void *temp_s4 asm("$20");
    register void *temp_s5_11 asm("$21");
    register void *temp_s5_12 asm("$21");
    register void *temp_s5_2 asm("$21");
    register void *temp_s5_3 asm("$21");
    register void *temp_s5_4 asm("$21");
    register void *temp_s5_5 asm("$21");
    register void *temp_s5_6 asm("$21");
    register void *temp_s5_7 asm("$21");
    register void *temp_s5_8 asm("$21");
    void *temp_v0_15;
    void *temp_v0_9;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_9;
    register char *var_a1_2 asm("$5");
    register void *var_s1 asm("$17");
    void *var_v0_2;

    register char *cursor17 asm("$17");
    register char *chunk21 asm("$21");
    register int *count3 asm("$3");
    register int (*spawn6)(int, int, void *) asm("$6");
    register int *eventRoot4 asm("$4");
    register char *saveBits7 asm("$7");
    register char *claimedBits6 asm("$6");
    register char *saveRoot3 asm("$3");
    int word8;
    register char *next4 asm("$4");
    register char *tableBase6 asm("$6");
    register int sentinel5 asm("$5");
    register int value4 asm("$4");
    register int value6 asm("$6");
    register int value5 asm("$5");
    register int value3 asm("$3");
    char *actorBitsBase;
    char *saveWord8;
    register int value2 asm("$2");
    register int counter18 asm("$18");
    register void *argument17 asm("$17");
    register void *original19 asm("$19");
    argument17 = arg0;
    __asm__("" : "=r"(argument17) : "0"(argument17));
    func_80050B90();
    __asm__ volatile("" ::: "$19");

    original19 = argument17;
    if (D_8006C5BC < 0x3C) {
        *(((char *)((char *)&D_80071FB0)) + D_8006C58C) = 1;
    }
    var_s2 = 9;
    var_a0 = &D_80071A0D;
    D_8006C644 = 0;
    D_8006C640 = 0;
    D_8006C74C = 0;
    D_8006C64C = 0;
    D_8006C5B8 = 1;
    D_8006C628 = 0;
    D_8006C6C4 = 0;
    D_8006C6C8 = 0;
    D_8006C6CC = 0;
    D_8006C568 = 0;
    D_8006C5E8 = 0;
    D_8006C52C = 0;
    D_8006C588 = 0;
    D_8006C670 = 0;
    D_8006C748 = 0;
    D_8006FA3C = D_8006FA40;
    do {
        *var_a0 = 0;
        var_s2 -= 1;
        var_a0 -= 1;
    } while (var_s2 >= 0);
    value2 = -1;
    __asm__("" : "=r"(value2) : "0"(value2));
    temp_s0 = &D_8006D088;
    __asm__("" : "=r"(temp_s0) : "0"(temp_s0));
    D_8006C590 = value2;
    value2 = *temp_s0;
    __asm__("" : "=r"(value2) : "0"(value2));
    temp_s2 = ((char *)&D_80070328) + 0x5C;
    D_8006C650 = 0;
    M2C_FIELD(&D_80070328, int *, 0x5C) = 0;
    M2C_FIELD(&D_80070328, int *, 0x60) = 0;
    __asm__("" : "=r"(temp_s2) : "0"(temp_s2));
    value4 = (int)temp_s2 - 0x5C;
    if (value2 != 0) {
        temp_s0 = (int *)((char *)temp_s0 + 0x24);
        func_8004F178((Vector3D *)value4, (Vector3D *)temp_s0);
        func_8004F178(((char *)temp_s2) + 0xC8, (Vector3D *) temp_s0);
        M2C_FIELD(&D_80070328, int *, 0x64) = (int) D_8006D0B8;
        var_s1 = (char *)argument17 + 0x10;
    } else {
        if (D_8006C658 != 0) {
            if (D_8006C5BC == 0x21) {
                if (D_8006C5C8 == 0) {
                    value2 = 0xA7FF;
                    __asm__("" : "=r"(value2) : "0"(value2));
                    D_80070328.x = value2;
                    value2 = 0x9E49;
                    __asm__("" : "=r"(value2) : "0"(value2));
                    D_80070328.y = value2;
                    value2 = 0x1568;
                    __asm__("" : "=r"(value2) : "0"(value2));
                    D_80070328.z = value2;
                    var_v0 = 0xA2;
                    goto block_17;
                }
            } else {
                goto block_16;
            }
        } else {
            if ((D_8006C5BC == 0x12) && (D_80071599 != 0)) {
                value3 = 0x1257B;
                __asm__("" : "=r"(value3) : "0"(value3));
                value2 = 0x6F8F;
                    __asm__("" : "=r"(value2) : "0"(value2));
                    D_80070328.x = value2;
                value2 = 0x2981;
                    __asm__("" : "=r"(value2) : "0"(value2));
                    D_80070328.z = value2;
                D_80070328.y = value3;
                var_v0 = 0x400;
            } else if ((D_8006C73C == (D_8006C5BC + 8)) && (temp_v1 = DIV10(D_8006C5BC), (D_8006C5BC == (temp_v1 * 0xA)))) {
                func_8004F178(&D_80070328, (temp_v1 * 0x10) + (char *)&D_800671B8);
                value2 = DIV10(D_8006C5BC) - 1;
                __asm__("" : "=r"(value2) : "0"(value2));
                var_v0 = M2C_FIELD(&D_800671D4, int *, value2 * 0x10);
            } else {
block_16:
                func_8004F178(&D_80070328, (Vector3D *)argument17);
                var_v0 = M2C_FIELD(argument17, unsigned char *, 0xE) * 0x10;
            }
block_17:
            __asm__("" : "=r"(var_v0) : "0"(var_v0));
            M2C_FIELD(&D_80070328, int *, 0x64) = var_v0;
        }
        temp_s2_2 = ((char *)&D_80070328) + 0x124;
        value4 = (int)temp_s2_2;
        __asm__("" : "=r"(value4) : "0"(value4));
        temp_s0_2 = (Vector3D *)((char *)temp_s2_2 - 0x124);
        func_8004F178((Vector3D *)value4, temp_s0_2);
        if (D_8006C784 < 0) {
            func_8004F52C(temp_s0_2, (*(((char *)((unsigned char *)&D_80067150)) + D_8006C60C) * 8) + (char *)&D_80067178);
            func_8004F178(temp_s2_2, temp_s0_2);
            __asm__("" : "=r"(temp_s2_2) : "0"(temp_s2_2));
            value2 = D_8006C60C;
            value2 = M2C_FIELD(&D_80067150, unsigned char *, value2);
            __asm__("" : "=r"(value2) : "0"(value2) : "$3");
            value3 = D_8006C784;
            __asm__("" : "=r"(value2), "=r"(value3) : "0"(value2), "1"(value3));
            value2 = M2C_FIELD(&D_8006717E, short *, value2 * 8);
            M2C_FIELD(temp_s2_2, int *, -0xC0) = value2;
            if (value3 < 0) {
                D_8006C784 = 4;
            }
        }
        D_8006C60C = 0;
        var_s1 = (char *)argument17 + 0x10;
    }
    cursor17 = (char *)var_s1;
    value2 = *(int *)cursor17;
    value3 = D_8006C5BC;
    __asm__("" : "=r"(value2), "=r"(value3) : "0"(value2), "1"(value3));
    cursor17 += 4;
    __asm__("" : "=r"(cursor17) : "0"(cursor17));
    D_8006C79C = value2;
    value2 = *(int *)cursor17;
    D_8006C4F4 = value2;
    cursor17 += 4;
    if (value3 != 0) {
        __asm__("" : "=r"(cursor17) : "0"(cursor17));
        func_8004E790(&D_8007179C, 0, 0x130);
        value2 = *(int *)cursor17;
        D_800717AC = value2;
        value2 = *(int *)(cursor17 + 4);
        cursor17 += 8;
        __asm__("" : "=r"(cursor17) : "0"(cursor17));
        D_800717B0 = value2;
        value2 = *(int *)cursor17;
        D_8006E388 = value2;
        value2 = *(int *)(cursor17 + 4);
        cursor17 += 8;
        __asm__("" : "=r"(cursor17) : "0"(cursor17));
        D_8006E38C = value2;
        value2 = *(int *)cursor17;
        value3 = *(int *)(cursor17+4);
        cursor17 += 8;
        __asm__("" : "=r"(value2), "=r"(value3), "=r"(cursor17) : "0"(value2), "1"(value3), "2"(cursor17));
        D_8006C618 = value2;
        D_8006C61C = value3;
    }
    var_s1_2 = (int *)cursor17;
    var_s2_2 = 0;
    if (*var_s1_2 >= 5) {
        D_8006E340 = ((char *)var_s1_2) + 4;
        func_8002B6C8();
    }
    cursor17 = (char *)var_s1_2;
    counter18 = 0;
    value2 = *(int *)cursor17;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E350;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = cursor17 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E354 = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    counter18 = 0;
    value2 = *(int *)chunk21;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E358;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = chunk21 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E35C = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    counter18 = 0;
    value2 = *(int *)chunk21;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E370;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = chunk21 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E374 = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    counter18 = 0;
    value2 = *(int *)chunk21;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E360;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = chunk21 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E364 = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    counter18 = 0;
    value2 = *(int *)chunk21;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E380;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = chunk21 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E384 = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    counter18 = 0;
    value2 = *(int *)chunk21;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E378;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = chunk21 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E37C = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    counter18 = 0;
    value2 = *(int *)chunk21;
    __asm__("" : "=r"(value2) : "0"(value2));
    count3 = &D_8006E368;
    __asm__("" : "=r"(count3) : "0"(count3));
    chunk21 = chunk21 + value2;
    value2 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    D_8006E36C = (void *)cursor17;
    *count3 = value2;
    if (value2 > 0) {
        do {
            counter18 += 1;
            value2 = *(int *)cursor17 + 4;
            __asm__("" : "=r"(value2) : "0"(value2));
            *(int *)cursor17 = (int)chunk21 + value2;
            cursor17 += 4;
        } while (counter18 < *count3);
    }
    value2 = *(int *)chunk21;
    temp_s1_4 = chunk21 + value2;
    func_80021A70();
    var_s5 = (int *)temp_s1_4;
    __asm__("" : "=r"(var_s5) : "0"(var_s5));
    var_s1_10 = (int *)((char *)var_s5 + 4);
    var_a0_2 = 0;
    __asm__("" : "=r"(var_a0_2) : "0"(var_a0_2));
    value2 = D_8006C76C;
    var_v1 = (char *)&D_80071484;
    value5 = value2 << 2;
    __asm__("" : "=r"(var_v1), "=r"(value5) : "0"(var_v1), "1"(value5));
    do {
        *(int *)(value5 + (int)var_v1) = 0;
        __asm__ volatile("" : : : "memory");
        var_a0_2 += 1;
        __asm__("" : "=r"(var_a0_2) : "0"(var_a0_2));
        var_v1 += 4;
    } while (var_a0_2 < 28);
    cursor17 = (char *)var_s1_10;
    value3 = *(int *)cursor17;
    if (value3 != -1) {
        tableBase6 = (char *)&D_80071484;
        sentinel5 = -1;
        __asm__("" : "=r"(tableBase6), "=r"(sentinel5) : "0"(tableBase6), "1"(sentinel5));
        do {
            value2 = *(int *)cursor17;
            next4 = cursor17 + value2;
            __asm__("" : "=r"(next4) : "0"(next4));
            cursor17 += 4;
            __asm__("" : "=r"(cursor17) : "0"(cursor17));
            value3 = *(int *)cursor17;
            cursor17 += 4;
            __asm__("" : "=r"(cursor17) : "0"(cursor17));
            value2 = D_8006C76C;
            value3 = (value3 << 2) + (int)tableBase6;
            __asm__("" : "=r"(value3) : "0"(value3));
            value2 = (value2 << 2) + value3;
            *(char **)value2 = cursor17;
            value2 = *(int *)cursor17;
            if (value2 != sentinel5) {
                value3 = -1;
                value2 += (int)cursor17;
                do {
                    *(int *)cursor17 = value2;
                    __asm__ volatile(".set	noat");
                    cursor17 += 4;
                    value2 = *(int *)cursor17;
                    if (value2 == value3) break;
                    value2 += (int)cursor17;
                } while (1);
            }
            value2 = *(int *)next4;
            cursor17 = next4;
        } while (value2 != sentinel5);
    }
    value2 = *(int *)var_s5;
    var_s5 = (int *)((char *)var_s5 + value2);
    __asm__("" : "=r"(var_s5) : "0"(var_s5));
    if (*var_s5 >= 5) {
        D_8006C754 = ((char *)var_s5) + 4;
        var_s5 = (void *)((char *)var_s5 + *var_s5);
        D_8006C758 = ((char *)var_s5) + 4;
    } else {
        D_8006C754 = 0;
        D_8006C758 = 0;
    }
    value2 = *(int *)var_s5;
    chunk21 = (char *)var_s5 + value2;
    cursor17 = chunk21 + 4;
    __asm__("" : "=r"(cursor17) : "0"(cursor17));
    D_8006C788 = cursor17;
    value2 = *(int *)chunk21;
    chunk21 += value2;
    cursor17 = chunk21 + 4;
    __asm__("" : "=r"(cursor17) : "0"(cursor17));
    D_8006C738 = cursor17;
    value2 = *(int *)chunk21;
    chunk21 += value2;
    temp_s7 = *(int *)(chunk21 + 4);
    cursor17 = chunk21 + 8;
    __asm__("" : "=r"(cursor17), "=r"(chunk21) : "0"(cursor17), "1"(chunk21));
    value3 = (int)(chunk21 + 8);
    __asm__("" : "=r"(cursor17), "=r"(value3) : "0"(cursor17), "1"(value3));
    D_8006C550 = cursor17;
    value4 = *(int *)chunk21;
    __asm__("" : "=r"(value4) : "0"(value4));
    value3 += temp_s7 * 0x58;
    __asm__("" : "=r"(value3) : "0"(value3));
    D_8006C704 = (void *)value3;
    D_8006C610 = (void *)value3;
    M2C_FIELD((void *)value3, char *, 0x48) = 0xFF;
    cursor17 = chunk21 + value4;
    value2 = (unsigned int)(cursor17 - (char *)D_8006C704);
    __asm__("" : "=r"(value2) : "0"(value2));
    { unsigned int quotient = (unsigned int)value2 / 112;
    __asm__("" : "=r"(temp_hi) : "0"(quotient)); }
    D_8006C574 = 0;
    D_8006C578 = temp_hi - 1;
    temp_v1_3 = D_8006C704 + temp_hi * 0x58;
    D_8006C5EC = temp_v1_3;
    D_8006C728 = temp_v1_3;
    value2 = *(int *)cursor17;
    __asm__("" : "=r"(value2) : "0"(value2));
    chunk21 = cursor17 + value2;
    value2 = *(int *)(chunk21 + 4);
    __asm__("" : "=r"(value2) : "0"(value2));
    cursor17 = chunk21 + 8;
    __asm__("" : "=r"(value2), "=r"(cursor17) : "0"(value2), "1"(cursor17));
    D_8006C730 = cursor17;
    __asm__ volatile("" ::: "memory");
    counter18 = value2 - 1;
    D_8006C580 = value2;
    if (counter18 >= 0) {
        value2 = counter18 << 2;
        var_v1_2 = (void **)(value2 + (int)cursor17);
        __asm__("" : "=r"(var_v1_2) : "0"(var_v1_2));
        do {
            value2 = *(int *)var_v1_2;
            counter18 -= 1;
            *(int *)var_v1_2 = value2 + (int)chunk21;
            var_v1_2 = (void **)((char *)var_v1_2 - 4);
        } while (counter18 >= 0);
    }
    value2 = *(int *)chunk21;
    counter18 = 0;
    chunk21 += value2;
    __asm__("" : "=r"(chunk21) : "0"(chunk21));
    value2 = *(int *)chunk21;
    cursor17 = chunk21 + 4;
    if (value2 > 0) {
        do {
            value2 = *(int *)cursor17;
            __asm__("" : "=r"(value2) : "0"(value2));
            value2 = (int)original19 + value2;
            __asm__("" : "=r"(value2) : "0"(value2));
            value3 = *(int *)value2;
            counter18 += 1;
            value3 += (int)original19;
            *(int *)value2 = value3;
            cursor17 += 4;
        } while (counter18 < *(int *)chunk21);
    }
    temp_s5 = (int *)chunk21;
    var_s1_12 = (void **)cursor17;
    var_a2 = 0;
    var_a1 = 0;
    var_a0_3 = 0x18;
    do {
        temp_v1_4 = M2C_FIELD(&D_8007209C, int *, var_a0_3);
        if (var_a2 < temp_v1_4) {
            var_a2 = temp_v1_4;
        }
        var_a1 += 1;
        __asm__("" : "=r"(var_a1) : "0"(var_a1));
        var_a0_3 += 0x10;
    } while (var_a1 < 4);
    value2 = D_800722C8;
    value3 = D_8006C658;
    __asm__("" : "=r"(value2), "=r"(value3) : "0"(value2), "1"(value3));
    value2 = var_a2 + value2;
    __asm__("" : "=r"(value2) : "0"(value2));
    temp_a0_2 = value2 + 0x3004;
    D_800722CC = temp_a0_2;
    if (value3 == 1) {
        func_8004E7D4(temp_a0_2, var_s1_12, (*var_s1_12 * 8) | 4);
    }
    D_8006C7E0 = temp_s5;
    func_8004E790(temp_s5, 0, 0x1000);
    if (D_8006C5BC < 0x3C) {
        saveRoot3 = (char *)&D_8006D088;
        __asm__("" : "=r"(saveRoot3) : "0"(saveRoot3));
        value2 = *(int *)saveRoot3;
        __asm__("" : "=r"(value2) : "0"(value2));
        frame.f28 = 0;
        if (value2 != 0) {
            var_s2_8 = 0;
            if (temp_s7 > 0) {
                saveBits7 = saveRoot3 + 4;
                saveRoot3 = (char *)&D_80071AB0;
                __asm__("" : "=r"(saveRoot3), "=r"(saveBits7) : "0"(saveRoot3), "1"(saveBits7));
                value2 = D_8006C58C;
                var_a1_2 = D_8006C550;
                __asm__("" : "=r"(value2), "=r"(var_a1_2) : "0"(value2), "1"(var_a1_2));
                value2 <<= 5;
                claimedBits6 = (char *)(value2 + (int)saveRoot3);
                __asm__("" : "=r"(claimedBits6) : "0"(claimedBits6));
                do {
                    __asm__("" : "=r"(var_a1_2) : "0"(var_a1_2));
                    temp_v0_12 = M2C_FIELD(var_a1_2, unsigned char *, 0x3B);
                    if ((temp_v0_12 != 0) && (temp_v0_12 < 0x21U)) {
                        var_a0_4 = M2C_FIELD(var_a1_2, unsigned char *, 0x50);
                        temp_v0_13 = var_s2_8 + D_8006C79C;
                        __asm__("" : "=r"(temp_v0_13) : "0"(temp_v0_13));
                        temp_s3 = temp_v0_13 >> 5;
                        temp_s1_8 = temp_v0_13 & 0x1F;
                        value2 = (unsigned int)(var_a0_4 - 1);
                        __asm__("" : "=r"(value2) : "0"(value2));
                        if ((unsigned int)value2 >= 2) {
                            value2 = 5;
                            __asm__("" : "=r"(value2) : "0"(value2));
                            if (var_a0_4 != value2) {
                                value2 = 10;
                                __asm__("" : "=r"(value2) : "0"(value2));
                                if (var_a0_4 != value2) {
                                    value2 = 25;
                                    __asm__("" : "=r"(value2) : "0"(value2));
                                    if (var_a0_4 != value2) var_a0_4 = 0;
                                }
                            }
                        }
                        var_v0_3 = var_s2_8 < 0x100;
                        var_s0 = 1;
                        if ((var_v0_3 != 0) && (((int) ({ value3 = temp_s3 << 2; __asm__("" : "=r"(value3) : "0"(value3)); value2 = value3 + (int)saveBits7; __asm__("" : "=r"(value2) : "0"(value2)); *(int *)value2; }) >> temp_s1_8) & 1) && ((var_a0_4 == 0) || (((int) ({ value2 = value3 + (int)claimedBits6; __asm__("" : "=r"(value2) : "0"(value2)); *(int *)value2; }) >> temp_s1_8) & 1))) {
                            var_s0 = 0;
                        }
                        if (var_s0 != 0) {
                            int firstWord8;
                            value2 = 1;
                            value3 = M2C_FIELD(var_a1_2, unsigned char *, 0x3B);
                            firstWord8 = frame.f28;
                            value3 -= 1;
                            __asm__("" : "=r"(value2), "=r"(value3) : "0"(value2), "1"(value3));
                            firstWord8 |= value2 << value3;
                            frame.f28 = firstWord8;
                            __asm__ volatile("" : : "r"(var_a0_4), "r"(var_a1_2), "r"(claimedBits6), "r"(saveBits7));
                        }
                    }
                    var_s2_8 += 1;
                    var_a1_2 = (void *)((char *)var_a1_2 + 0x58);
                } while (var_s2_8 < temp_s7);
            }
        }
        __asm__ volatile(".set\tnoat");
        var_s2_9 = 0;
        if (temp_s7 > 0) {
            actorBitsBase = (char *)&D_80071AB0;
            __asm__("" : "=r"(actorBitsBase) : "0"(actorBitsBase));
            var_s6 = 0;
            do {
                value2 = D_8006C79C;
                value3 = (int)D_8006C550;
                __asm__("" : "=r"(value2), "=r"(value3) : "0"(value2), "1"(value3));
                temp_v0_14 = var_s2_9 + value2;
                __asm__("" : "=r"(temp_v0_14) : "0"(temp_v0_14));
                temp_s3_2 = temp_v0_14 >> 5;
                temp_a0_3 = (void *)(var_s6 + value3);
                temp_v1_5 = M2C_FIELD(temp_a0_3, short *, 0x36);
                __asm__("" : "=r"(temp_v1_5) : "0"(temp_v1_5));
                temp_s1_9 = temp_v0_14 & 0x1F;
                var_s0_2 = 1;
                if ((temp_v1_5 < 0x300) && (({ value2 = temp_v1_5 << 2; __asm__("" : "=r"(value2) : "0"(value2)); M2C_FIELD(&D_8006EE2C, int *, value2); }) != 0)) {
                    func_80055C24(temp_a0_3);
                } else {
                    func_80055D10(D_8006C550 + var_s6);
                }
                var_a0_5 = M2C_FIELD(((void *)(var_s6 + (int)D_8006C550)), unsigned char *, 0x50);
                if (((unsigned int) (var_a0_5 - 1) >= 2U) && (var_a0_5 != 5) && (var_a0_5 != 0xA) && (var_a0_5 != 0x19)) {
                    var_a0_5 = 0;
                }
                temp_a1 = (void *)(var_s6 + (int)D_8006C550);
                if (!(((int) (M2C_FIELD(temp_a1, unsigned char *, 0x53) & 7) >> D_8006C7C4) & 1)) {
                    var_s0_2 = 0;
                }
                value2 = 255;
                __asm__("" : "=r"(value2) : "0"(value2));
                M2C_FIELD(temp_a1, char *, 0x3A) = value2;
                temp_v1_6 = M2C_FIELD(((void *)(var_s6 + (int)D_8006C550)), unsigned char *, 0x3B);
                if (temp_v1_6 == 0x7E) {
                    var_s0_2 = 1;
                    if ((var_s2_9 < 0x100) && (((int) *((int *)((temp_s3_2 * 4) + ({ value2 = D_8006C58C << 5; value2 += (int)actorBitsBase; __asm__("" : "=r"(value2) : "0"(value2)); value2; }))) >> temp_s1_9) & 1)) {
                        var_a0_5 = 0;
                    }
                } else if (temp_v1_6 == 0x7D) {
                    var_v0_4 = var_s2_9 < 0x100;
                    temp_v1_7 = temp_s3_2 * 4;
                    if (var_v0_4) {
                        value2 = D_8006C58C;
                        value2 <<= 5;
                        value2 += (int)actorBitsBase;
                        __asm__("" : "=r"(value2), "=r"(temp_v1_7) : "0"(value2), "1"(temp_v1_7));
                        temp_v1_7 += value2;
                        __asm__("" : "=r"(temp_v1_7) : "0"(temp_v1_7));
                        value2 = *(int *)temp_v1_7;
                        __asm__("" : "=r"(value2) : "0"(value2));
                        var_v0_4 = value2 >> temp_s1_9;
                        goto block_112;
                    }
                } else if ((D_8006D088 != 0) && (temp_v1_6 < 0x21U) && !((({ int secondWord8; value2 = temp_v1_6 - 1; secondWord8 = frame.f28; __asm__("" : "=r"(value2), "=r"(secondWord8) : "0"(value2), "1"(secondWord8), "r"(var_a0_5) : "$3", "$5", "$6", "$7"); value2 = secondWord8 >> value2; __asm__("" : "=r"(value2) : "0"(value2)); value2; })) & 1)) {
                    temp_v1_7 = temp_s3_2 * 4;
                    if ((var_s2_9 < 0x100) && (((int) ({ saveWord8 = (char *)&D_8006D08C; __asm__("" : "=r"(saveWord8) : "0"(saveWord8), "r"(temp_v1_7), "r"(var_a0_5) : "$2", "$5", "$6", "$7"); value2 = temp_v1_7 + (int)saveWord8; __asm__("" : "=r"(value2) : "0"(value2)); *(int *)value2; }) >> temp_s1_9) & 1)) {
                        if (var_a0_5 != 0) {
                            var_v0_4 = (int) *((int *)(temp_v1_7 + ({ value2 = D_8006C58C << 5; value2 += (int)actorBitsBase; __asm__("" : "=r"(value2) : "0"(value2)); value2; }))) >> temp_s1_9;
block_112:
                            if (var_v0_4 & 1) {
                                goto block_113;
                            }
                        } else {
block_113:
                            var_s0_2 = 0;
                            var_a0_5 = 0;
                        }
                    }
                }
                __asm__ volatile("" : "=r"(temp_s3_2) : "0"(temp_s3_2));
                temp_v1_8 = temp_s3_2 * 4;
                if (var_s0_2 == 0) {
                    if ((var_s2_9 < 0x100) && (((int) ({ value2 = D_8006C58C << 5; value2 += (int)actorBitsBase; __asm__("" : "=r"(value2) : "0"(value2)); temp_v1_8 += value2; __asm__("" : "=r"(temp_v1_8) : "0"(temp_v1_8)); *(int *)temp_v1_8; }) >> temp_s1_9) & 1)) {
                        __asm__ volatile("" ::: "$16");
                        var_a0_5 = 0;
                    }
                    if (var_a0_5 != 0) {
                        value2 = (int)SpawnMoby;
                        value5 = 1;
                        if (value2 != 0) {
                        value2 = (int)D_8006C550;
                        value6 = 0;
                        temp_s4 = (void *)(value2 + var_s6);
                        value4 = (int)temp_s4;
                        __asm__("" : "=r"(value4) : "0"(value4));
                        temp_s3_3 = (Vector3D *)((char *)temp_s4 + 0xC);
                        __asm__("" : "=r"(temp_s3_3) : "0"(temp_s3_3));
                        temp_v0_15 = func_80036A68((void *)value4, value5, value6, temp_s3_3);
                        temp_s0_3 = ((char *)temp_v0_15) + 0xC;
                        if (temp_v0_15 != 0) {
                            value5 = (int)temp_s3_3;
                            __asm__("" : "=r"(value5) : "0"(value5));
                            temp_s3_4 = M2C_FIELD(temp_v0_15, void **, 0);
                            func_8004F178(temp_s0_3, (Vector3D *)value5);
                            temp_v0_16 = func_8001A358(temp_s0_3, 0x400);
                            if (temp_v0_16 != 0) {
                                M2C_FIELD(temp_v0_15, int *, 0x14) = temp_v0_16;
                            }
                            value2 = M2C_FIELD(temp_s4, volatile unsigned char *, 0x50);
                            M2C_FIELD(temp_v0_15, char *, 0x48) = 0;
                            M2C_FIELD(temp_v0_15, unsigned char *, 0x50) = value2;
                            M2C_FIELD(temp_s3_4, char *, 0x11) = 1;
                        }
                    }
                    }
                    func_80055B18(D_8006C550 + var_s6);
                    var_s2_9 += 1;
                } else {
                    if (((int) ({ value2 = D_8006C58C << 5; value2 += (int)actorBitsBase; __asm__("" : "=r"(value2) : "0"(value2)); temp_v1_8 += value2; __asm__("" : "=r"(temp_v1_8) : "0"(temp_v1_8)); *(int *)temp_v1_8; }) >> temp_s1_9) & 1) {
                        value3 = 255;
                        __asm__("" : "=r"(value3) : "0"(value3));
                        M2C_FIELD(((void *)(var_s6 + (int)D_8006C550)), char *, 0x50) = value3;
                    }
                    func_8004F178(&frame.v10, D_8006C550 + var_s6 + 0xC);
                    frame.v10.z += 0x400;
                    func_8001A310(&frame.v10, 0x10000, 0, D_8006C550 + var_s6);
                    func_8005629C(D_8006C550 + var_s6);
                    temp_v1_9 = (void *)(var_s6 + (int)D_8006C550);
                    if (M2C_FIELD(temp_v1_9, unsigned char *, 0x52) != 0) {
                        M2C_FIELD(temp_v1_9, unsigned char *, 0x52) = (unsigned char) D_80071928;
                    } else {
                        value2 = 255;
                        __asm__("" : "=r"(value2) : "0"(value2));
                        M2C_FIELD(temp_v1_9, unsigned char *, 0x52) = value2;
                    }
                    value2 = (int)D_8006C550;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$3");
                    value3 = 1;
                    __asm__("" : "=r"(value3) : "0"(value3));
                    value2 = var_s6 + value2;
                    M2C_FIELD((void *)value2, char *, 0x4D) = value3;
                    __asm__ volatile("" : "=r"(var_s2_9) : "0"(var_s2_9) : "memory");
                    var_s2_9 += 1;
                }
                var_s6 += 0x58;
            } while (var_s2_9 < temp_s7);
        }
    }
    eventRoot4 = &D_8006D088;
    __asm__("" : "=r"(eventRoot4) : "0"(eventRoot4));
    if (*eventRoot4 != 0) {
        func_8003B918(eventRoot4);
        if (D_8006E344 != 13) {
            if (D_8006D8D0 == 1) goto block_event_1;
            if (D_8006D8D0 == 2) goto block_event_2;
            goto block_after_event;
block_event_1:
            var_a0_6 = 44;
            goto block_140;
        }
    } else if (D_8006C5BC == 14) {
block_event_2:
        var_a0_6 = 41;
block_140:
        func_8004BEF8(var_a0_6);
    }
block_after_event:
    func_8002B768((Particle *) (((char *)D_8006C7E0) + 0x1000));
    if (D_8006C658 != 0) {
        srand(0x4D2);
        D_8006C678 = 1;
        if (D_8006C658 == 1) {
            D_8006C55C = D_800722CC;
            D_8006C538 = ((char *)D_800722CC) + 4;
        } else {
            D_8006C55C = (int *)0x80600000;
            D_8006C538 = (int *)0x80600004;
            func_8004E790((void *)0x80600000, 0, 0x4000);
        }
    }
    if (D_8006C5BC != 0) {
        spawn6 = SpawnMoby;
        __asm__("" : "=r"(spawn6) : "0"(spawn6));
        if ((spawn6 != 0) && (D_8006FA38 < 0) && (((DIV10(D_8006C5BC)) * 0xA) != (D_8006C5BC - 8))) {
            D_8006C65C = spawn6(0x78, 0, spawn6);
        } else {
            D_8006C65C = 0;
        }
        func_80012BA8(&D_80068F7C);
        D_8006E038 = 0;
        D_8006FC15 = D_8006E33C;
        D_8006FC16 = D_8006E33D;
        D_8006FC17 = D_8006E33E;
        D_8006FC89 = D_8006E33C;
        D_8006FC8A = D_8006E33D;
        D_8006FC8B = D_8006E33E;
        func_8004E790(&D_80072330, 0x03030303, 0x100);
    }
    func_80027B70();
    if ((D_8006C5BC != 0) && (func_8003038C != 0)) {
        func_8003038C();
    }
    if ((D_8006C508 == 0) && (D_8006C5BC < 0x3C) && (D_8006C5E0 != 0)) {
        M2C_FIELD(D_8006C530, char *, 0x40) = 0;
    }
    return temp_s5;
}

#undef DIV10
#undef M2C_FIELD

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
