#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
extern int Level12SpawnD_8006E020 __asm__("D_8006E020");
extern int Level12SpawnD_8006E024 __asm__("D_8006E024");
extern int Level12SpawnD_8006E028 __asm__("D_8006E028");
extern int Level12SpawnD_80071918 __asm__("D_80071918");
extern int Level12SpawnD_8007191C __asm__("D_8007191C");
extern int Level12SpawnD_80071920 __asm__("D_80071920");
extern int Level12SpawnD_80071930 __asm__("D_80071930");
extern unsigned short Level12SpawnD_8006E03E __asm__("D_8006E03E");
extern short Level12SpawnD_8006E040 __asm__("D_8006E040");
int Level12SpawnInterpolateCosine(int, int) __asm__("func_8004EA2C");
int Level12SpawnInterpolateSine(int, int) __asm__("func_8004E9E4");
int Level12SpawnQueryWorldHeightWithOptions(void*, int, int, int) __asm__("func_8001A310");
int Level12SpawnQueryWorldHeight(void*, int) __asm__("func_8001A358");
extern int Level12SpawnD_8006D07C __asm__("D_8006D07C");
extern int Level12SpawnD_8006D080 __asm__("D_8006D080");
extern int Level12SpawnD_8006D084 __asm__("D_8006D084");
extern int Level12SpawnD_80071934 __asm__("D_80071934");
extern unsigned char Level12SpawnPlayerE __asm__("D_80070328 + 0xE");
int Level12SpawnQueryWorldHeight(void*, int) __asm__("func_8001A358");
extern int Level12SpawnD_8006D07C __asm__("D_8006D07C");
extern int Level12SpawnD_8006D080 __asm__("D_8006D080");
extern int Level12SpawnD_8006D084 __asm__("D_8006D084");
extern int Level12SpawnD_80071934 __asm__("D_80071934");
extern unsigned char Level12SpawnPlayerE __asm__("D_80070328 + 0xE");
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level12SpawnHigh(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Level12SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level12SpawnColor2[] __asm__("D_80066BAC");
#define Level12SpawnField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level12SpawnBuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Level12SpawnTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level12SpawnShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Level12SpawnCopyVector(void*, void*) __asm__("func_8004F178");
int Level12SpawnAddVector(void*, void*, void*) __asm__("func_8004F194");
int Level12SpawnMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Level12SpawnPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Level12SpawnAllocateParticleRecord(int) __asm__("func_80056434");
int Level12SpawnRandBetween(int, int) __asm__("func_8003636C");
int Level12SpawnCopyHalfwordVector(void*, void*) __asm__("func_8004F58C");
int Level12Spawnrand(void) __asm__("rand");
extern unsigned char Level12SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level12SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level12SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level12SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level12SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level12SpawnD_80070328[] __asm__("D_80070328");
extern int Level12SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original USA Rev0 level40 instructions
 * and dispatch: build/sibling4163.func_level_12_80086F50.json.
 * Raw units, helper contracts and cadence remain unresolved. */
void* func_level_12_80086F50(int entryCount, int kind, void* input, void* mode) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        int sp1C;
        int sp20;
        int sp24;
        int sp28;
        int sp2C;
        int sp30;
        int sp34;
        int sp38;
        int sp3C;
        int sp40;
        int sp44;
        int sp48;
        int sp4C;
        int sp50;
        int sp54;
        int sp58;
        int sp5C;
        int sp60;
        int sp64;
        int sp68;
        int sp6C;
        int sp70;
        int sp74;
        int sp78;
        int sp7C;
        int sp80;
        int sp84;
        int sp88;
        int sp8C;
        int sp90;
        int sp94;
        int sp98;
        int sp9C;
        unsigned char spA0, spA1, spA2, padA3;
        int spA4;
        int spA8;
        int spAC;
        int spB0;
        int spB4;
        int spB8;
        int spBC;
        int spC0;
        int spC4;
        int spC8;
        int spCC;
        int spD0;
        int spD4;
        int spD8;
        int spDC;
        int spE0;
        int spE4;
        int spE8;
        int spEC;
        int* volatile spF0;
        int spF4;
        int spF8;
        int spFC;
        volatile int sp100;
        int sp104;
    } frame;
    register int kindSelector __asm__("$21") = kind;
    register unsigned char* reference __asm__("$20") = input;
    register unsigned char* modeSelector __asm__("$22") = mode;
    short* temp_a0_2;
    short* temp_a1;
    register unsigned char* temp_s1 __asm__("$17");
    register unsigned char* temp_s1_2 __asm__("$17");
    int temp_a0;
    int temp_a3;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v1;
    register int commonByte8 __asm__("$8");
    register int commonByte9 __asm__("$9");
    register int byte255 __asm__("$23");
    int byte128;
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailByte __asm__("$2");
    register int scratch19 __asm__("$18");
    int var_v0_2;
    register int var_v0_4 __asm__("$2");
    unsigned int temp_v1_2;
    int temp_v0_7;
    unsigned char temp_v1_3;
    void* var_a0;
    register unsigned char* record __asm__("$19");

    MATCHING_KEEP3(kindSelector, reference, modeSelector);
    record = 0;
    MATCHING_KEEP(record);
    frame.spE0 = entryCount;
    frame.spE8 = 0;
    if (entryCount > 0) {
        {
            register int* vectorBase __asm__("$8");
            byte128 = 128;
            __asm__ volatile("" : "=r"(byte128) : "0"(byte128) : "$8", "memory");
            vectorBase = &frame.sp30;
            MATCHING_KEEP_CLOBBER(vectorBase, "$23");
            byte255 = 255;
            MATCHING_KEEP2_VOLATILE_CLOBBER(byte255, byte128, "memory");
            frame.spF0 = vectorBase;
        }
        frame.sp100 = 0;
        do {
            MATCHING_KEEP2_VOLATILE_CLOBBER(byte255, byte128, "memory");
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$9");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = one;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level12SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level12SpawnField(record, short*, 0x1E) = 0;
                    Level12SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level12Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                    Level12SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level12SpawnField(record, volatile unsigned char*, 12) = byte128;
                    Level12SpawnField(record, volatile unsigned char*, 13) = byte128;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level12SpawnField(record, unsigned char*, 14) = byte128;
                    goto storeTrailingF8;

                case 0x1: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level12SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level12SpawnField(record, short*, 0x1E) = 0;
                    Level12SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level12Spawnrand();
                    Level12SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 96;
                    commonByte9 = 46;
                    MATCHING_KEEP2(commonByte9, tailByte);
                    Level12SpawnField(record, volatile unsigned char*, 12) = tailByte;
                    Level12SpawnField(record, volatile unsigned char*, 13) = tailByte;
                    Level12SpawnField(record, volatile unsigned char*, 14) = tailByte;
                    __asm__ volatile(""
                                     : "=r"(commonByte9), "=r"(tailByte)
                                     : "0"(commonByte9), "1"(tailByte)
                                     : "$3", "memory");
                    tailByte = 4;
                    Level12SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x2:
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                        tailByte = Level12Spawnrand();
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp10 = tailByte;
                        tailByte = Level12Spawnrand();
                        destination = record + 24;
                        source = &frame.sp10;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp14 = tailByte;
                        frame.sp18 = 16;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Level12SpawnField(record, unsigned short*, 30) = 0;
                    Level12SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level12Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                    Level12SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level12SpawnField(record, volatile unsigned char*, 12) = byte128;
                    Level12SpawnField(record, volatile unsigned char*, 13) = byte128;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level12SpawnField(record, unsigned char*, 14) = byte128;
                    goto storeTrailingF8;

                case 0x4:
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 8;
                    Level12SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level12Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level12SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level12SpawnField(record, unsigned char*, 12) = byte128;
                    Level12SpawnField(record, unsigned char*, 13) = byte128;
                    Level12SpawnField(record, unsigned char*, 14) = byte128;
                    Level12SpawnField(record, unsigned char*, 15) = commonByte9;
                    Level12SpawnField(record, unsigned char*, 17) = tailByte;
                    Level12SpawnField(record, unsigned char*, 16) = 0;
                    tailByte = Level12Spawnrand();
                    tailByte &= 3;
                    MATCHING_KEEP(tailByte);
                    tailByte += 4;
                    Level12SpawnField(record, unsigned short*, 24) = tailByte;
                    tailByte = Level12Spawnrand();
                    tailByte &= 3;
                    tailByte += 2;
                    Level12SpawnField(record, unsigned short*, 26) = tailByte;
                    tailByte = Level12Spawnrand();
                    tailByte &= 7;
                    tailByte += 3;
                    Level12SpawnField(record, unsigned short*, 28) = tailByte;
                    tailByte = (int)modeSelector >> 2;
                    Level12SpawnField(record, unsigned short*, 30) = tailByte;
                    break;
                case 0x6:
                    temp_s1 = Level12SpawnField(reference, unsigned char**, 0);
                    record = Level12SpawnAllocateParticleRecord(3);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level12Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5");
                        scratch16 = (int)(reference + 12);
                        source = (void*)scratch16;
                        MATCHING_KEEP4(destination, source, scratch16, tailByte);
                        tailByte &= 15;
                        Level12SpawnField(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        component -= 63;
                        component += random;
                        Level12SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        Level12SpawnField(record, int*, 24) = scratch16;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                        component -= 63;
                        component += random;
                        Level12SpawnField(record, unsigned short*, 6) = component;
                    }
                    tailByte = Level12SpawnField(temp_s1, int*, 4);
                    Level12SpawnField(record, unsigned short*, 28) = tailByte;
                    {
                        register int value __asm__("$3") = Level12SpawnField(temp_s1, int*, 0);
                        tailByte = 32;
                        Level12SpawnField(record, unsigned char*, 10) = tailByte;
                        tailByte = 20;
                        Level12SpawnField(record, unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        MATCHING_KEEP2_CLOBBER(value, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 12) = byte128;
                        Level12SpawnField(record, unsigned char*, 13) = byte128;
                        Level12SpawnField(record, unsigned char*, 14) = byte128;
                        Level12SpawnField(record, unsigned char*, 15) = tailByte;
                        Level12SpawnField(record, unsigned char*, 17) = 0;
                        Level12SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
                        value >>= 6;
                        Level12SpawnField(record, unsigned short*, 30) = value;
                    }
                    break;
                case 0x8:
                    record = Level12SpawnAllocateParticleRecord(4);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnCopyHalfwordVector(destination, source);
                    }
                    tailByte = Level12Spawnrand();
                    tailByte &= 6;
                    MATCHING_KEEP(tailByte);
                    tailByte += 14;
                    Level12SpawnField(record, unsigned char*, 10) = tailByte;
                    {
                        register int value3 __asm__("$3") = Level12SpawnPlayerE;
                        tailByte = 32;
                        Level12SpawnField(record, volatile unsigned char*, 12) = tailByte;
                        Level12SpawnField(record, volatile unsigned char*, 13) = tailByte;
                        tailByte = 64;
                        commonByte8 = 46;
                        Level12SpawnField(record, volatile unsigned char*, 14) = tailByte;
                        tailByte = 2;
                        Level12SpawnField(record, volatile unsigned char*, 15) = commonByte8;
                        Level12SpawnField(record, volatile unsigned char*, 17) = tailByte;
                        Level12SpawnField(record, volatile unsigned char*, 16) = 0;
                        Level12SpawnField(record, unsigned char*, 11) = value3;
                    }
                    break;
                case 0x9: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* playerVector __asm__("$16") = &frame.sp20;
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Level12SpawnD_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnCopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp20;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp20 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = &frame.sp20;
                            __asm__(""
                                    : "=r"(destination), "=r"(source)
                                    : "0"(destination), "1"(source)
                                    : "$3", "memory");
                            component = frame.sp24;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp24 = component;
                            Level12SpawnPackVectorShiftRight2(destination, source);
                        }
                        Level12SpawnCopyVector(playerVector, player + 0x98);
                        Level12SpawnShiftVectorRightTowardZero(playerVector, 6);
                        Level12SpawnPackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Level12SpawnField(record, short*, 0x1E) = 0;
                    Level12SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level12Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level12SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level12SpawnField(record, volatile unsigned char*, 12) = byte128;
                    Level12SpawnField(record, volatile unsigned char*, 13) = byte128;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level12SpawnField(record, volatile unsigned char*, 14) = byte128;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level12SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;

                case 0xA: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(3);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Level12SpawnD_80070328;
                        tailByte = Level12Spawnrand();
                        destination = record + 4;
                        source = Level12SpawnD_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int factor __asm__("$4") = 0x66660000;
                        register int value __asm__("$2");
                        register int count __asm__("$8");
                        register int iteration8 __asm__("$9");
                        register int dividend __asm__("$3");
                        register int productHigh __asm__("hi");
                        register int color __asm__("$4");
                        value = 24;
                        MATCHING_KEEP2(factor, value);
                        Level12SpawnField(record, unsigned char*, 10) = value;
                        value = 15;
                        Level12SpawnField(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.spE0;
                        iteration8 = frame.spE8;
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = frame.sp100;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Level12SpawnD_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Level12SpawnHigh(dividend, factor);
                        Level12SpawnField(record, unsigned char*, 12) = value;
                        value = *(Level12SpawnColor1 + 1 + count);
                        dividend >>= 31;
                        Level12SpawnField(record, unsigned char*, 13) = value;
                        color = *(Level12SpawnColor2 + 2 + count);
                        value = 44;
                        Level12SpawnField(record, unsigned char*, 15) = value;
                        value = 4;
                        Level12SpawnField(record, unsigned char*, 17) = value;
                        Level12SpawnField(record, unsigned char*, 16) = 0;
                        Level12SpawnField(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Level12SpawnField(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register int iteration __asm__("$8") = frame.spE8;
                        register void* vector __asm__("$6") = frame.spF0;
                        register int base __asm__("$2");
                        register void* table __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(vector)
                                : "0"(destination), "1"(iteration), "2"(vector)
                                : "$2", "$5", "memory");
                        base = (int)Level12SpawnD_80066A48;
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        table = (void*)(iteration * 12);
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "memory");
                        base = 1;
                        Level12SpawnField(record, unsigned char*, 3) = base;
                        base = 4;
                        Level12SpawnField(record, unsigned char*, 17) = base;
                        Level12SpawnTransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Level12SpawnField(reference, short*, 54);
                            register int expected __asm__("$9");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Level12SpawnMultiplyVectorGpfSf0(frame.spF0, frame.spF0, 3);
                    }
                    Level12SpawnAddVector(frame.spF0, frame.spF0, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp30;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp30 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp34;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp34 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp38;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp38 = component;
                        }
                    }
                    if (modeSelector == (unsigned char*)6) {
                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp30;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp30 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp34;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp34 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp38;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp38 = component;
                        }
                    }
                    if (Level12SpawnField(reference, short*, 0x36) == 0xB6) {
                        frame.sp38 += 0x200;
                    }
                    Level12SpawnPackVectorShiftRight2(record + 4, frame.spF0);
                    Level12SpawnField(record, int*, 0xC) =
                        (int)*(int*)(Level12SpawnD_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Level12SpawnField(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Level12Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level12Spawnrand() & 7) + 0x20;
                    }
                    Level12SpawnField(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Level12Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int iteration __asm__("$9") = frame.spE8;
                        register int base __asm__("$3");
                        register void* source __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(tailByte)
                                : "0"(destination), "1"(iteration), "2"(tailByte)
                                : "$3", "$5", "memory");
                        base = (int)Level12SpawnD_80066A48;
                        Level12SpawnField(record, unsigned char*, 11) = tailByte;
                        Level12SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        source = (void*)(iteration * 12);
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level12SpawnField(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Level12SpawnField(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level12Spawnrand() & 7));
                    Level12SpawnField(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Level12SpawnField(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level12Spawnrand() & 7));
                    Level12SpawnField(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Level12SpawnField(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level12Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level12SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Level12SpawnField(record, unsigned short*, 30) = 0;
                    goto initializeRand37;
                case 0x13:
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level12SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 32;

                    Level12SpawnField(record, unsigned char*, 0xA) = tailByte;
                    tailByte = Level12Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Level12SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level12SpawnField(record, unsigned char*, 0xC) = byte255;
                    Level12SpawnField(record, unsigned char*, 0xD) = byte255;
                    Level12SpawnField(record, volatile unsigned char*, 14) = 0;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level12SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;

                case 0x21: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) = 0;
                    Level12SpawnField(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp50;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Level12SpawnD_80070328 + 0x98;
                            Level12SpawnCopyVector(destination, temp_s1);
                        }
                        Level12SpawnShiftVectorRightTowardZero((void*)scratch16, 6);
                        Level12SpawnCopyVector(&frame.sp40, temp_s1 - 0x98);
                        frame.sp48 -= 0x164;
                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.sp40;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp40 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$18");
                            scratch19 = 48;
                            component = frame.sp44;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp44 = component;
                        }

                        goto setDestination;
                    } else {
                        register int one __asm__("$8") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Level12SpawnD_80070328 + 0x30;
                            frame.sp40 = 0x164;
                            frame.sp44 = 0;
                            frame.sp48 = 0;
                            Level12SpawnTransformVectorByBasis(temp_s1_2, &frame.sp40, &frame.sp40);
                            Level12SpawnAddVector(&frame.sp40, &frame.sp40, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp50 = -(Level12Spawnrand() & 7);
                            {
                                register int random __asm__("$2") = Level12Spawnrand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") = temp_s1_2;
                                register void* vector __asm__("$5") = &frame.sp50;
                                register int iteration8 __asm__("$9") = frame.spE8;
                                register int angle __asm__("$7");
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP4_CLOBBER(destination, vector, angle, output,
                                                       "memory");
                                MATCHING_KEEP(iteration8);
                                random &= 15;
                                angle = iteration8 << 6;
                                component = *(unsigned short*)(Level12SpawnD_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp54 = component;
                                random = *(unsigned short*)(Level12SpawnD_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp58 = random;
                                Level12SpawnTransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else {
                            register int two __asm__("$2") = 2;
                            MATCHING_KEEP(two);
                            scratch16 = 5;
                            if (modeSelector == (unsigned char*)two) {
                                {
                                    register int iteration8 __asm__("$8") = frame.spE8;
                                    __asm__(""
                                            : "=r"(iteration8)
                                            : "0"(iteration8)
                                            : "$17", "$16", "$18", "memory");
                                    scratch17 = iteration8 << 5;
                                    __asm__(""
                                            : "=r"(scratch17)
                                            : "0"(scratch17)
                                            : "$16", "$18", "memory");
                                }
                                scratch16 = 6;
                                scratch19 = 0x30;
                                goto updateSharedVector;
                            } else {
                                {
                                    register int iteration9 __asm__("$9") = frame.spE8;
                                    register int offset __asm__("$2");
                                    scratch19 = 64;
                                    __asm__(""
                                            : "=r"(iteration9), "=r"(scratch19)
                                            : "0"(iteration9), "1"(scratch19)
                                            : "$2", "memory");
                                    offset = iteration9 << 5;
                                    MATCHING_KEEP(offset);
                                    scratch17 = offset + 16;
                                }
                            }
                        }
                    }

                updateSharedVector:
                    Level12SpawnCopyVector(&frame.sp40, Level12SpawnD_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Level12SpawnD_80065920;
                        register unsigned char* second __asm__("$4");
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        second = (unsigned char*)(scratch17 * 2);
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        first = (short*)((int)second + (int)first);
                        value = *first;
                        other = frame.sp40;
                        value >>= scratch16;
                        other += value;
                        value = (int)Level12SpawnD_800658A0;
                        second += value;
                        value = frame.sp48;
                        frame.sp40 = other;
                        other = *(short*)second;
                        value -= 356;
                        frame.sp48 = value;
                        value = frame.sp44;
                        other >>= scratch16;
                        value += other;
                        frame.sp44 = value;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        value = *first;
                        other = scratch16 + 1;
                        value >>= other;
                        frame.sp50 = value;
                        value = *(short*)second;
                        frame.sp58 = 0;
                        value >>= other;
                        frame.sp54 = value;
                    }
                setDestination:
                    var_a0 = record + 4;
                finishMode:
                    Level12SpawnPackVectorShiftRight2(var_a0, &frame.sp40);
                    Level12SpawnPackVectorShiftRight2(record + 0x18, &frame.sp50);
                    Level12SpawnField(record, short*, 0x1E) = 0;
                    Level12SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level12Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                    Level12SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level12SpawnField(record, volatile unsigned char*, 12) = scratch19;
                    Level12SpawnField(record, volatile unsigned char*, 13) = scratch19;
                    Level12SpawnField(record, unsigned char*, 14) = scratch19;
                    goto storeTrailingF8;
                case 0x2D: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$2");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = one;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 110;
                    Level12SpawnField(record, unsigned short*, 30) = 0;
                    Level12SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level12Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level12SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level12SpawnField(record, volatile unsigned char*, 12) = byte128;
                    Level12SpawnField(record, volatile unsigned char*, 13) = byte128;
                    Level12SpawnField(record, volatile unsigned char*, 14) = byte128;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level12SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;

                case 0x37:
                    record = Level12SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 2) = 0;
                        Level12SpawnField(record, unsigned char*, 3) = tailByte;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level12SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 64;

                initializeRand37:
                    Level12SpawnField(record, unsigned char*, 0xA) = tailByte;
                    tailByte = Level12Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                    Level12SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level12SpawnField(record, unsigned char*, 0xC) = byte255;
                    Level12SpawnField(record, unsigned char*, 0xD) = byte255;
                    Level12SpawnField(record, unsigned char*, 0xE) = 0;
                storeTrailingF8:
                    MATCHING_KEEP2_VOLATILE_CLOBBER(commonByte8, tailByte, "memory");
                    Level12SpawnField(record, unsigned char*, 15) = commonByte8;
                initializeTrailingBytes:
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                    Level12SpawnField(record, unsigned char*, 0x11) = tailByte;
                    Level12SpawnField(record, unsigned char*, 0x10) = 0;
                    break;

                case 0x38:
                    record = Level12SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) = 0;
                    Level12SpawnField(record, unsigned char*, 3) = tailByte;
                    Level12SpawnField(record, unsigned short*, 4) =
                        Level12SpawnField(reference, unsigned short*, 4);
                    Level12SpawnField(record, unsigned short*, 6) =
                        Level12SpawnField(reference, unsigned short*, 6);
                    Level12SpawnField(record, unsigned short*, 8) =
                        Level12SpawnField(reference, unsigned short*, 8);
                    Level12SpawnField(record, int*, 24) = Level12SpawnField(reference, int*, 24);
                    Level12SpawnField(record, int*, 28) = Level12SpawnField(reference, int*, 28);
                    tailByte = Level12SpawnField(reference, unsigned char*, 10);
                    MATCHING_KEEP(tailByte);
                    Level12SpawnField(record, unsigned char*, 10) = tailByte;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register unsigned int sourceByte __asm__("$2") =
                            Level12SpawnField(reference, unsigned char*, 11);
                        MATCHING_KEEP_CLOBBER(sourceByte, "memory");
                        commonByte9 = 46;
                        Level12SpawnField(record, volatile unsigned char*, 12) = 0;
                        Level12SpawnField(record, volatile unsigned char*, 13) = 0;
                        Level12SpawnField(record, volatile unsigned char*, 14) = 0;
                        Level12SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                        Level12SpawnField(record, volatile unsigned char*, 17) = 0;
                        Level12SpawnField(record, volatile unsigned char*, 16) = 0;
                        Level12SpawnField(record, unsigned char*, 11) = sourceByte;
                    }
                    break;
                case 0x3B: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Level12SpawnField(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Level12SpawnField(record, unsigned char*, 3) = value;
                        value = 16;
                        Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level12SpawnField(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Level12SpawnField(record, unsigned char*, 1) = flags;
                        Level12SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level12SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level12SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Level12SpawnField(record, int*, 12) = var_v0;
                    Level12SpawnField(record, unsigned char*, 0xA) =
                        (unsigned char)((Level12Spawnrand() & 0xF) + 0x14);
                    Level12SpawnField(record, unsigned char*, 0xB) = Level12Spawnrand();
                    Level12SpawnField(record, unsigned char*, 0x10) = 0;
                    Level12SpawnField(record, short*, 0x18) = (short)((Level12Spawnrand() & 7) - 4);
                    Level12SpawnField(record, short*, 0x1A) =
                        (short)(-2 - (Level12Spawnrand() & 7));
                    Level12SpawnField(record, short*, 0x1C) =
                        (short)((Level12Spawnrand() & 0xF) - 8);
                    break;
                case 0x42: /* switch 1 */
                {
                    register int local128 __asm__("$8");
                    record = Level12SpawnAllocateParticleRecord(0);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level12Spawnrand() & 0xF);
                    Level12SpawnField(record, unsigned char*, 3) = 1;
                    Level12SpawnField(record, short*, 4) =
                        (short)((((int)Level12SpawnField(reference, int*, 0) >> 2) +
                                 (Level12Spawnrand() & 0xF)) -
                                8);
                    Level12SpawnField(record, short*, 6) =
                        (short)((((int)Level12SpawnField(reference, int*, 4) >> 2) +
                                 (Level12Spawnrand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Level12SpawnField(record, short*, 16) = 0;
                        Level12SpawnField(record, short*, 18) = 0;
                        Level12SpawnField(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Level12SpawnField(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Level12SpawnD_8006E344;
                        register int expected __asm__("$2");
                        __asm__ __volatile__("" ::: "$2", "memory");
                        expected = 4;
                        MATCHING_KEEP2(observed, expected);
                        if (observed == expected)
                            var_v0_4 = 100;
                        else
                            var_v0_4 = 2;
                    }
                    {
                        register int one __asm__("$8") = 1;
                        MATCHING_KEEP2(one, var_v0_4);
                        Level12SpawnField(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Level12SpawnField(Level12SpawnD_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Level12Spawnrand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Level12SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level12SpawnField(record, unsigned char*, 0xD) = 0;
                            Level12SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Level12SpawnField(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Level12SpawnField(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Level12SpawnField(record, unsigned char*, 13) = byte255;
                            Level12SpawnField(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Level12SpawnField(record, unsigned char*, 0xC) = 0;
                            Level12SpawnField(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Level12SpawnField(record, unsigned char*, 0xC) = 0;
                            Level12SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Level12SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level12SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {

                            Level12SpawnField(record, unsigned char*, 12) = byte255;
                            Level12SpawnField(record, unsigned char*, 13) = byte128;
                        }
                            Level12SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {

                            Level12SpawnField(record, unsigned char*, 12) = 0;
                            Level12SpawnField(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Level12SpawnField(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Level12SpawnField(record, unsigned char*, 0xF) = 0x40;
                    break;
                }
                case 0x45: {
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int value4 __asm__("$4");
                    register int value5 __asm__("$5");
                    register int value6 __asm__("$6");
                    register int low8 __asm__("$8");
                    register int low9 __asm__("$9");
                    int productLo, productHi;
                    register void* vector17 __asm__("$17");
                    register void* vector18 __asm__("$18");
                    register void* vector16 __asm__("$16");
                    value2 = Level12Spawnrand();
                    value2 &= 1023;
                    scratch17 = Level12SpawnD_8006E040;
                    value2 -= 512;
                    scratch17 -= value2;
                    value2 = Level12Spawnrand();
                    value3 = 0x38E38E39;
                    __asm__ volatile("" : "=h"(productHi) : "l"(value2 * value3) : "memory");
                    value4 = scratch17;
                    value3 = value2 >> 31;
                    low9 = productHi;
                    MATCHING_KEEP(low9);
                    value5 = low9 >> 12;
                    value5 -= value3;
                    value3 = value5 << 3;
                    value3 += value5;
                    value3 <<= 11;
                    value2 -= value3;
                    scratch19 = value2 - 2048;
                    value2 = Level12SpawnInterpolateCosine(value4, value5);
                    scratch16 = value2;
                    value2 = Level12Spawnrand();
                    __asm__ volatile("" : "=l"(low8) : "0"(scratch16 * scratch19) : "memory");
                    value4 = scratch17;
                    value2 &= 2047;
                    value2 -= 1024;
                    value5 = Level12SpawnD_8006E020;
                    value3 = low8 >> 12;
                    value5 += value3;
                    value5 -= value2;
                    frame.sp60 = value5;
                    value2 = Level12SpawnInterpolateSine(value4, value5);
                    scratch16 = value2;
                    value2 = Level12Spawnrand();
                    productLo = scratch16 * scratch19;
                    __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                    value2 &= 2047;
                    value2 -= 1024;
                    value3 = Level12SpawnD_8006E028;
                    value4 = Level12SpawnD_8006E024;
                    value3 += 16384;
                    frame.sp68 = value3;
                    __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                    low9 = productLo;
                    MATCHING_KEEP(low9);
                    value3 = low9 >> 12;
                    value4 += value3;
                    value3 = frame.sp60;
                    value4 -= value2;
                    frame.sp64 = value4;
                    if (value3 <= 0)
                        break;
                    if (value4 <= 0)
                        break;
                    value2 = Level12SpawnQueryWorldHeightWithOptions(&frame.sp60, 0x60C0, 2, 0);
                    value3 = Level12SpawnD_8006E03E;
                    MATCHING_KEEP2_CLOBBER(value2, value3, "memory");
                    scratch16 = value2;
                    value3 &= 4095;
                    value2 = value3 < 1024;
                    MATCHING_KEEP(value2);
                    if (value2) {
                        value2 = scratch19 >> 2;
                        goto rawHeight45;
                    }
                    value2 = value3 < 3841;
                    MATCHING_KEEP(value2);
                    if (value2) {
                        value2 = scratch19 >> 1;
                        goto baseHeight45;
                    }
                    value2 = scratch19 >> 1;
                rawHeight45:
                    value3 = Level12SpawnD_8006E028;
                    value2 += 2048;
                    value3 += value2;
                    frame.sp68 = value3;
                    goto heightDone45;
                baseHeight45:
                    value2 = Level12SpawnD_8006E028;
                    value2 += 8192;
                    frame.sp68 = value2;
                heightDone45:;
                    if (frame.sp68 < scratch16 + 1024)
                        break;
                    if (scratch16 != 0 && Level12SpawnD_80071920 <= 0)
                        break;
                    record = Level12SpawnAllocateParticleRecord(1);
                    tailByte = 1;
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 3) = tailByte;
                    if (scratch16 == 0) {
                        value2 = frame.sp68;
                        MATCHING_KEEP_CLOBBER(value2, "memory");
                        scratch16 = value2 - 16384;
                        if (scratch16 < 1024)
                            scratch16 = 1024;
                        goto zeroHalf45;
                    }
                    if (Level12SpawnD_80071930 != 0)
                        goto zeroHalf45;
                    value2 = Level12SpawnD_80071918;
                    value3 = Level12SpawnD_8007191C;
                    value4 = Level12SpawnD_80071920;
                    if (value2 < 0)
                        value2 = -value2;
                    if (value3 < 0)
                        value3 = -value3;
                    value2 += value3;
                    if (value2 < value4) {
                        commonByte8 = 1;
                        Level12SpawnField(record, unsigned short*, 24) = commonByte8;
                        goto initializeVector45;
                    }
                zeroHalf45:
                    Level12SpawnField(record, unsigned short*, 24) = 0;
                initializeVector45:
                    value2 = Level12Spawnrand();
                    frame.sp70 = value2 & 63;
                    value2 = Level12Spawnrand();
                    frame.sp74 = value2 & 63;
                    value2 = Level12Spawnrand();
                    value2 &= 127;
                    value6 = frame.sp68;
                    MATCHING_KEEP2(value2, value6);
                    value2 += 384;
                    value6 -= scratch16;
                    value6 /= value2;
                    vector17 = &frame.sp80;
                    value4 = (int)vector17;
                    MATCHING_KEEP2_CLOBBER(vector17, value4, "memory");
                    vector18 = &frame.sp70;
                    value5 = (int)vector18;
                    frame.sp78 = value2;
                    frame.sp68 = scratch16;
                    Level12SpawnField(record, unsigned char*, 2) = value6;
                    Level12SpawnMultiplyVectorGpfSf0((void*)value4, (void*)value5, value6);
                    vector16 = &frame.sp60;
                    Level12SpawnAddVector(vector16, vector16, vector17);
                    Level12SpawnPackVectorShiftRight2(record + 4, vector16);
                    Level12SpawnAddVector(vector16, vector16, vector18);
                    Level12SpawnPackVectorShiftRight2(record + 10, vector16);
                    tailByte = 112;
                    Level12SpawnField(record, volatile unsigned char*, 20) = tailByte;
                    Level12SpawnField(record, volatile unsigned char*, 21) = tailByte;
                    tailByte = 160;
                    Level12SpawnField(record, volatile unsigned char*, 16) = tailByte;
                    Level12SpawnField(record, volatile unsigned char*, 17) = tailByte;
                    tailByte = 176;
                    Level12SpawnField(record, volatile unsigned char*, 18) = tailByte;
                    tailByte = 80;
                    Level12SpawnField(record, unsigned char*, 23) = 0;
                    goto finishRawTail45;
                }

                case 0x46: /* switch 1 */
                {
                    register int local128 __asm__("$8");
                    record = Level12SpawnAllocateParticleRecord(1);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level12Spawnrand() & 0xF);
                    Level12SpawnField(record, unsigned char*, 3) = 1;
                    frame.spA0 = 0;
                    frame.spA1 = Level12Spawnrand();
                    frame.spA2 = Level12Spawnrand();
                    Level12SpawnBuildPackedAngleBasisMatrix(&frame.spA0, &frame.spA8, 0);
                    frame.sp90 = (int)modeSelector;
                    frame.sp94 = 0;
                    frame.sp98 = 0;
                    Level12SpawnTransformVectorByBasis(&frame.spA8, (unsigned char*)&frame.sp90,
                                                       (unsigned char*)&frame.sp90);
                    Level12SpawnField(record, unsigned short*, 4) =
                        (unsigned short)((int)Level12SpawnField(reference, int*, 0) >> 2);
                    Level12SpawnField(record, unsigned short*, 6) =
                        (unsigned short)((int)Level12SpawnField(reference, int*, 4) >> 2);
                    Level12SpawnField(record, unsigned short*, 8) =
                        (unsigned short)((int)Level12SpawnField(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.sp90;
                        register int other __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 4);

                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level12SpawnField(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.sp94;
                        other = Level12SpawnField(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level12SpawnField(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.sp98;
                        value = 2;
                        Level12SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level12SpawnField(record, unsigned char*, 16) = value;
                        value = 192;
                        Level12SpawnField(record, unsigned char*, 17) = value;
                        value = 80;
                        Level12SpawnField(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Level12SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");

                        Level12SpawnField(record, unsigned char*, 18) = 0;
                        Level12SpawnField(record, unsigned char*, 20) = byte255;
                        Level12SpawnField(record, unsigned char*, 21) = byte255;
                        Level12SpawnField(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Level12SpawnField(record, short*, 14) = value;
                    }
                    break;
                }
                case 0x47: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(1);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level12Spawnrand() & 7);
                    Level12SpawnField(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Level12Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC0 = temp_v0_4;
                    temp_v0_5 = (int)(((Level12Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC4 = temp_v0_5;
                    temp_v0_6 = (int)(((Level12Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC8 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Level12SpawnField(reference, int*, 0);
                        value = frame.spC0;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level12SpawnField(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level12SpawnField(reference, int*, 4);
                        value = frame.spC4;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level12SpawnField(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level12SpawnField(reference, int*, 8);
                        value = frame.spC8;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level12SpawnField(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.spC0;
                        register int value __asm__("$2") =
                            Level12SpawnField(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level12SpawnField(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.spC4;
                        value = Level12SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level12SpawnField(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.spC8;
                        other = Level12SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Level12SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level12SpawnField(record, unsigned char*, 16) = value;
                        Level12SpawnField(record, unsigned char*, 17) = value;
                        value = 96;
                        Level12SpawnField(record, unsigned char*, 18) = value;
                        Level12SpawnField(record, unsigned char*, 20) = byte255;
                        Level12SpawnField(record, unsigned char*, 21) = byte255;
                        Level12SpawnField(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Level12SpawnField(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Level12SpawnField(record, short*, 14) = other;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Level12SpawnAllocateParticleRecord(0);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level12Spawnrand() & 0x1F);
                    Level12SpawnField(record, unsigned char*, 3) = 1;
                    Level12SpawnPackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level12SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level12SpawnField(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level12SpawnField(record, unsigned short*, 8) = component;
                    }
                    Level12SpawnField(record, short*, 0x10) = (short)((Level12Spawnrand() & 2) - 1);
                    Level12SpawnField(record, short*, 0x12) = (short)((Level12Spawnrand() & 2) - 1);
                    Level12SpawnField(record, short*, 0x14) = (short)-(Level12Spawnrand() & 1);
                    tailByte = Level12Spawnrand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level12SpawnField(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Level12Spawnrand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Level12SpawnField(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Level12SpawnField(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Level12SpawnField(record, unsigned char*, 13) = component;
                    }
                    Level12SpawnField(record, unsigned char*, 0xE) =
                        (unsigned char)((Level12Spawnrand() & 0x3F) + 0x40);
                    Level12SpawnField(record, unsigned char*, 0xF) = 0x40;
                    Level12SpawnField(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                {
                    register int local128 __asm__("$9");
                    record = Level12SpawnAllocateParticleRecord(1);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level12SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level12Spawnrand() & 0xF);
                    Level12SpawnField(record, unsigned char*, 3) = 1;
                    Level12SpawnPackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.spC0;
                        MATCHING_KEEP(vector);
                        Level12SpawnAddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&frame.spC0;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            frame.spC0 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3") = frame.spC4;

                            random &= 0x3F;

                            component -= 0x20;

                            component += random;
                            frame.spC4 = component;
                        }

                        {
                            register int random __asm__("$2") = Level12Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;

                            component = frame.spC8;

                            random &= 0x7F;

                            component -= 0x40;

                            component += random;
                            frame.spC8 = component;
                            Level12SpawnPackVectorShiftRight2(destination, source);
                        }
                    }
                    Level12SpawnField(record, unsigned char*, 0x17) = 2;
                    tailByte = Level12Spawnrand();
                    tailByte |= 192;

                    Level12SpawnField(record, unsigned char*, 16) = tailByte;
                    Level12SpawnField(record, unsigned char*, 0x11) =
                        (unsigned char)((Level12Spawnrand() & 0x3F) - 0x60);
                    Level12SpawnField(record, unsigned char*, 0x12) = 0;
                    tailByte = Level12Spawnrand();
                    tailByte |= 224;

                    Level12SpawnField(record, unsigned char*, 20) = tailByte;
                    tailByte = Level12Spawnrand();
                    tailByte |= 224;

                    Level12SpawnField(record, unsigned char*, 21) = tailByte;
                    {

                        tailByte = 80;
                    finishRawTail45:
                        Level12SpawnField(record, unsigned char*, 0x16) = byte128;
                    }
                    Level12SpawnField(record, unsigned char*, 0x13) = tailByte;
                    break;
                }
                case 0x52:
                    temp_s1 = Level12SpawnField(reference, unsigned char**, 0);
                    record = Level12SpawnAllocateParticleRecord(1);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level12Spawnrand();
                    tailByte &= 15;
                    Level12SpawnField(record, unsigned char*, 2) = tailByte;
                    tailByte = 1;
                    Level12SpawnField(record, unsigned char*, 3) = tailByte;
                    tailByte = Level12Spawnrand();
                    scratch16 = tailByte & 255;
                    {
                        register int upper __asm__("$5") = Level12SpawnField(temp_s1, int*, 4);
                        tailByte = Level12SpawnRandBetween(upper >> 1, upper);
                    }
                    scratch16 <<= 1;
                    {
                        register int component __asm__("$3") =
                            Level12SpawnField(Level12SpawnD_80065920 + scratch16, short*, 0);
                        register int low8 __asm__("$9") = component * tailByte;
                        MATCHING_KEEP2(low8, tailByte);
                        component = low8 >> 12;
                        frame.spD0 = component;
                    }
                    {
                        register int component __asm__("$3") =
                            Level12SpawnField(Level12SpawnD_800658A0 + scratch16, short*, 0);
                        register int low9 __asm__("$8") = component * tailByte;
                        register void* third __asm__("$6") = reference + 12;
                        register void* first __asm__("$4");
                        register void* second __asm__("$5");
                        scratch16 = (int)&frame.spD0;
                        first = (void*)scratch16;
                        second = first;
                        frame.spD8 = 0;
                        MATCHING_KEEP4(low9, third, first, second);
                        tailByte = low9 >> 12;
                        frame.spD4 = tailByte;
                        Level12SpawnAddVector(first, second, third);
                    }
                    Level12SpawnPackVectorShiftRight2(record + 4, (void*)scratch16);
                    {
                        register int value3 __asm__("$3") =
                            Level12SpawnField(record, unsigned short*, 4);
                        register int value2 __asm__("$2") =
                            Level12SpawnField(record, unsigned short*, 8);
                        register int value4 __asm__("$4") =
                            Level12SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP3(value3, value2, value4);
                        value2 += 96;
                        Level12SpawnField(record, volatile unsigned short*, 10) = value3;
                        Level12SpawnField(record, volatile unsigned short*, 12) = value4;
                        Level12SpawnField(record, volatile unsigned short*, 14) = value2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value3 = Level12SpawnField(reference, int*, 20);
                        value4 = Level12SpawnField(temp_s1, int*, 0);
                        __asm__ volatile(""
                                         : "=r"(value3), "=r"(value4)
                                         : "0"(value3), "1"(value4)
                                         : "$2", "memory");
                        tailByte = 112;
                        MATCHING_KEEP3_CLOBBER(value3, value4, tailByte, "memory");
                        Level12SpawnField(record, unsigned char*, 16) = tailByte;
                        Level12SpawnField(record, unsigned char*, 17) = tailByte;
                        tailByte = 224;
                        Level12SpawnField(record, unsigned char*, 18) = tailByte;
                        Level12SpawnField(record, unsigned char*, 20) = tailByte;
                        Level12SpawnField(record, unsigned char*, 21) = tailByte;
                        tailByte = 80;
                        Level12SpawnField(record, unsigned char*, 22) = byte255;
                        Level12SpawnField(record, unsigned char*, 19) = tailByte;
                        Level12SpawnField(record, unsigned char*, 23) = 0;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(value3, value4, "memory");
                        value3 += value4;
                        value3 >>= 2;
                        Level12SpawnField(record, int*, 24) = value3;
                    }
                    break;
                case 0x54:
                    record = Level12SpawnAllocateParticleRecord(0);
                    Level12SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level12Spawnrand();
                    tailByte &= 15;
                    Level12SpawnField(record, unsigned char*, 2) = tailByte;
                    Level12SpawnField(record, unsigned char*, 3) = 1;
                    Level12SpawnField(record, unsigned short*, 4) =
                        Level12SpawnField(reference, int*, 0) >> 2;
                    Level12SpawnField(record, unsigned short*, 6) =
                        Level12SpawnField(reference, int*, 4) >> 2;
                    Level12SpawnField(record, unsigned short*, 8) =
                        Level12SpawnField(reference, int*, 8) >> 2;
                    tailByte = Level12SpawnRandBetween(-3, 3);
                    Level12SpawnField(record, unsigned short*, 16) = tailByte;
                    tailByte = Level12SpawnRandBetween(-3, 3);
                    Level12SpawnField(record, unsigned short*, 18) = tailByte;
                    tailByte = Level12SpawnRandBetween(-3, 3);
                    Level12SpawnField(record, unsigned short*, 20) = tailByte;
                    Level12SpawnField(record, unsigned char*, 10) = 2;
                    Level12SpawnField(record, unsigned char*, 12) =
                        Level12SpawnField(modeSelector, unsigned char*, 0);
                    Level12SpawnField(record, unsigned char*, 13) =
                        Level12SpawnField(modeSelector, unsigned char*, 1);
                    {
                        register int color3 __asm__("$3") =
                            Level12SpawnField(modeSelector, unsigned char*, 2);
                        tailByte = 64;
                        Level12SpawnField(record, unsigned char*, 15) = tailByte;
                        Level12SpawnField(record, unsigned char*, 14) = color3;
                    }
                    break;
            }
            MATCHING_KEEP2_VOLATILE_CLOBBER(byte255, byte128, "memory");
            {
                register int stride8 __asm__("$9") = frame.sp100;
                register int iteration9 __asm__("$8") = frame.spE8;
                MATCHING_KEEP2(stride8, iteration9);
                stride8 += 4;
                frame.sp100 = stride8;
                stride8 = frame.spE0;
                MATCHING_KEEP2(stride8, iteration9);
                iteration9 += 1;
                var_v0 = iteration9 < stride8;
                __asm__ volatile(""
                                 : "=r"(var_v0), "=r"(iteration9)
                                 : "0"(var_v0), "1"(iteration9)
                                 : "$3", "memory");
                frame.spE8 = iteration9;
            }
        } while (var_v0);
    }
    return record;
}

#undef Level12SpawnField

#undef Level12SpawnHigh
