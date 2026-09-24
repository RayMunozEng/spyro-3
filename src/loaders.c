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

INCLUDE_ASM("asm/nonmatchings/loaders", func_8002AF9C);

INCLUDE_ASM("asm/nonmatchings/loaders", func_8002B31C);

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

INCLUDE_ASM("asm/nonmatchings/loaders", func_8002CA50);

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
