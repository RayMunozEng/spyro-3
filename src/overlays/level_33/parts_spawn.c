#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level33SpawnHigh(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Level33SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level33SpawnColor2[] __asm__("D_80066BAC");
#define Level33SpawnField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level33SpawnBuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Level33SpawnTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level33SpawnShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Level33SpawnCopyVector(void*, void*) __asm__("func_8004F178");
int Level33SpawnAddVector(void*, void*, void*) __asm__("func_8004F194");
int Level33SpawnMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Level33SpawnPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Level33SpawnAllocateParticleRecord(int) __asm__("func_80056434");
int Level33SpawnRandBetween(int, int) __asm__("func_8003636C");
int Level33Spawnrand(void) __asm__("rand");
extern unsigned char Level33SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level33SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level33SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level33SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level33SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level33SpawnD_80070328[] __asm__("D_80070328");
extern int Level33SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original USA Rev0 level33 instructions
 * and dispatch: build/sibling4198.func_level_33_80097C74.json.
 * Raw units, helper contracts and cadence remain unresolved. */
void* func_level_33_80097C74(int entryCount, int kind, void* input, void* mode) {
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
        unsigned char sp70, sp71, sp72, pad73;
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
        int spA0;
        int spA4;
        int spA8;
        int spAC;
        int spB0;
        int spB4;
        int spB8;
        int spBC;
        int* volatile spC0;
        int spC4;
        int spC8;
        int spCC;
        volatile int spD0;
        int spD4;
    } frame;
    register int zeroColor __asm__("$8");
    register int commonByte __asm__("$8");
    register int commonByte9 __asm__("$9");
    register int zeroFour __asm__("$9");
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
    int byte128;
    register int byte255 __asm__("$23");
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailByte __asm__("$2");
    register int scratch19 __asm__("$19");
    int var_v0_2;
    register int var_v0_4 __asm__("$2");
    unsigned int temp_v1_2;
    int temp_v0_7;
    unsigned char temp_v1_3;
    void* var_a0;
    register unsigned char* record __asm__("$18");

    MATCHING_KEEP3(kindSelector, reference, modeSelector);
    record = 0;
    MATCHING_KEEP(record);
    frame.spB0 = entryCount;
    frame.spB8 = 0;
    if (entryCount > 0) {
        byte128 = 128;
        MATCHING_KEEP(byte128);
        {
            register int* vectorBase __asm__("$8") = &frame.sp30;
            MATCHING_KEEP_CLOBBER(vectorBase, "$23");
            byte255 = 255;
            frame.spC0 = vectorBase;
        }
        frame.spD0 = 0;
        do {
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$9");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = one;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level33SpawnField(record, short*, 0x1E) = 0;
                    Level33SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level33Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level33SpawnField(record, unsigned char*, 12) = byte128;
                    Level33SpawnField(record, unsigned char*, 13) = byte128;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$4", "memory");
                    Level33SpawnField(record, unsigned char*, 14) = byte128;
                    goto initializeF8;
                case 0x1: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level33SpawnField(record, short*, 0x1E) = 0;
                    Level33SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level33Spawnrand();
                    Level33SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Level33SpawnField(record, unsigned char*, 0xC) = tailByte;
                    Level33SpawnField(record, unsigned char*, 0xD) = tailByte;
                    Level33SpawnField(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level33SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x2:
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                        tailByte = Level33Spawnrand();
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp10 = tailByte;
                        tailByte = Level33Spawnrand();
                        destination = record + 24;
                        source = &frame.sp10;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp14 = tailByte;
                        frame.sp18 = 16;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Level33SpawnField(record, unsigned short*, 30) = 0;
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level33Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte, tailByte, "memory");
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level33SpawnField(record, unsigned char*, 12) = byte128;
                    Level33SpawnField(record, unsigned char*, 13) = byte128;
                    Level33SpawnField(record, unsigned char*, 14) = byte128;

                    goto initializeF8;
                case 0x3: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$2");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = one;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level33SpawnField(record, short*, 0x1E) = 0;
                    Level33SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level33Spawnrand();
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 64;
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level33SpawnField(record, unsigned char*, 13) = tailByte;
                    tailByte = 2;
                    Level33SpawnField(record, unsigned char*, 12) = byte128;

                    Level33SpawnField(record, unsigned char*, 14) = 0;
                    Level33SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x4:
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 8;
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level33Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level33SpawnField(record, unsigned char*, 12) = byte128;
                    Level33SpawnField(record, unsigned char*, 13) = byte128;
                    Level33SpawnField(record, unsigned char*, 14) = byte128;
                    Level33SpawnField(record, unsigned char*, 15) = commonByte;
                    Level33SpawnField(record, unsigned char*, 17) = tailByte;
                    Level33SpawnField(record, unsigned char*, 16) = 0;
                    tailByte = Level33Spawnrand();
                    tailByte &= 3;
                    MATCHING_KEEP(tailByte);
                    tailByte += 4;
                    Level33SpawnField(record, unsigned short*, 24) = tailByte;
                    tailByte = Level33Spawnrand();
                    tailByte &= 3;
                    tailByte += 2;
                    Level33SpawnField(record, unsigned short*, 26) = tailByte;
                    tailByte = Level33Spawnrand();
                    tailByte &= 7;
                    tailByte += 3;
                    Level33SpawnField(record, unsigned short*, 28) = tailByte;
                    tailByte = (int)modeSelector >> 2;
                    Level33SpawnField(record, unsigned short*, 30) = tailByte;
                    break;
                case 0x6:
                    temp_s1 = Level33SpawnField(reference, unsigned char**, 0);
                    record = Level33SpawnAllocateParticleRecord(3);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level33Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5");
                        scratch16 = (int)(reference + 12);
                        source = (void*)scratch16;
                        MATCHING_KEEP4(destination, source, scratch16, tailByte);
                        tailByte &= 15;
                        Level33SpawnField(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        component -= 63;
                        component += random;
                        Level33SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        Level33SpawnField(record, int*, 24) = scratch16;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                        component -= 63;
                        component += random;
                        Level33SpawnField(record, unsigned short*, 6) = component;
                    }
                    tailByte = Level33SpawnField(temp_s1, int*, 4);
                    Level33SpawnField(record, unsigned short*, 28) = tailByte;
                    {
                        register int value __asm__("$3") = Level33SpawnField(temp_s1, int*, 0);
                        tailByte = 32;
                        Level33SpawnField(record, unsigned char*, 10) = tailByte;
                        tailByte = 20;
                        Level33SpawnField(record, unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        MATCHING_KEEP2_CLOBBER(value, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 12) = byte128;
                        Level33SpawnField(record, unsigned char*, 13) = byte128;
                        Level33SpawnField(record, unsigned char*, 14) = byte128;
                        Level33SpawnField(record, unsigned char*, 15) = tailByte;
                        Level33SpawnField(record, unsigned char*, 17) = 0;
                        Level33SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
                        value >>= 6;
                        Level33SpawnField(record, unsigned short*, 30) = value;
                    }
                    break;
                case 0x9: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* playerVector __asm__("$16") = &frame.sp20;
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Level33SpawnD_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnCopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            Level33SpawnPackVectorShiftRight2(destination, source);
                        }
                        Level33SpawnCopyVector(playerVector, player + 0x98);
                        Level33SpawnShiftVectorRightTowardZero(playerVector, 6);
                        Level33SpawnPackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Level33SpawnField(record, short*, 0x1E) = 0;
                    Level33SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level33Spawnrand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$4", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte9 = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Level33SpawnField(record, unsigned char*, 0xC) = byte128;
                        Level33SpawnField(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$4", "memory");
                        Level33SpawnField(record, unsigned char*, 0xE) = byte128;
                    }

                    __asm__ volatile(""
                                     : "=r"(commonByte9), "=r"(tailByte)
                                     : "0"(commonByte9), "1"(tailByte)
                                     : "$4", "memory");
                    Level33SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0xA: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(3);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Level33SpawnD_80070328;
                        tailByte = Level33Spawnrand();
                        destination = record + 4;
                        source = Level33SpawnD_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
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
                        Level33SpawnField(record, unsigned char*, 10) = value;
                        value = 15;
                        Level33SpawnField(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.spB0;
                        iteration8 = frame.spB8;
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = frame.spD0;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Level33SpawnD_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Level33SpawnHigh(dividend, factor);
                        Level33SpawnField(record, unsigned char*, 12) = value;
                        value = *(Level33SpawnColor1 + 1 + count);
                        dividend >>= 31;
                        Level33SpawnField(record, unsigned char*, 13) = value;
                        color = *(Level33SpawnColor2 + 2 + count);
                        value = 44;
                        Level33SpawnField(record, unsigned char*, 15) = value;
                        value = 4;
                        Level33SpawnField(record, unsigned char*, 17) = value;
                        Level33SpawnField(record, unsigned char*, 16) = 0;
                        Level33SpawnField(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Level33SpawnField(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register int iteration __asm__("$8") = frame.spB8;
                        register void* vector __asm__("$6") = frame.spC0;
                        register int base __asm__("$2");
                        register void* table __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(vector)
                                : "0"(destination), "1"(iteration), "2"(vector)
                                : "$2", "$5", "memory");
                        base = (int)Level33SpawnD_80066A48;
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        table = (void*)(iteration * 12);
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "memory");
                        base = 1;
                        Level33SpawnField(record, unsigned char*, 3) = base;
                        base = 4;
                        Level33SpawnField(record, unsigned char*, 17) = base;
                        Level33SpawnTransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Level33SpawnField(reference, short*, 54);
                            register int expected __asm__("$9");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Level33SpawnMultiplyVectorGpfSf0(frame.spC0, frame.spC0, 3);
                    }
                    Level33SpawnAddVector(frame.spC0, frame.spC0, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
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
                    if (Level33SpawnField(reference, short*, 0x36) == 0xB6) {
                        frame.sp38 += 0x200;
                    }
                    Level33SpawnPackVectorShiftRight2(record + 4, frame.spC0);
                    Level33SpawnField(record, int*, 0xC) =
                        (int)*(int*)(Level33SpawnD_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Level33SpawnField(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Level33Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level33Spawnrand() & 7) + 0x20;
                    }
                    Level33SpawnField(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Level33Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int iteration __asm__("$9") = frame.spB8;
                        register int base __asm__("$3");
                        register void* source __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(tailByte)
                                : "0"(destination), "1"(iteration), "2"(tailByte)
                                : "$3", "$5", "memory");
                        base = (int)Level33SpawnD_80066A48;
                        Level33SpawnField(record, unsigned char*, 11) = tailByte;
                        Level33SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        source = (void*)(iteration * 12);
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnField(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Level33SpawnField(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level33Spawnrand() & 7));
                    Level33SpawnField(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Level33SpawnField(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level33Spawnrand() & 7));
                    Level33SpawnField(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Level33SpawnField(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level33Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Level33SpawnField(record, short*, 0x1E) = 0;
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level33Spawnrand();
                    commonByte = 46;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$3", "memory");
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$4", "memory");
                    Level33SpawnField(record, unsigned char*, 12) = byte255;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$4", "memory");
                    Level33SpawnField(record, unsigned char*, 13) = byte255;
                    goto initializeZeroE;
                case 0x21: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) = 0;
                    Level33SpawnField(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp50;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Level33SpawnD_80070328 + 0x98;
                            Level33SpawnCopyVector(destination, temp_s1);
                        }
                        Level33SpawnShiftVectorRightTowardZero((void*)scratch16, 6);
                        Level33SpawnCopyVector(&frame.sp40, temp_s1 - 0x98);
                        frame.sp48 -= 0x164;
                        {
                            register int random __asm__("$2") = Level33Spawnrand();
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
                            register int random __asm__("$2") = Level33Spawnrand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$19");
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
                        register int one __asm__("$9") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Level33SpawnD_80070328 + 0x30;
                            frame.sp40 = 0x164;
                            frame.sp44 = 0;
                            frame.sp48 = 0;
                            Level33SpawnTransformVectorByBasis(temp_s1_2, &frame.sp40, &frame.sp40);
                            Level33SpawnAddVector(&frame.sp40, &frame.sp40, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp50 = -(Level33Spawnrand() & 7);
                            {
                                register int random __asm__("$2") = Level33Spawnrand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") = temp_s1_2;
                                register void* vector __asm__("$5") = &frame.sp50;
                                register int iteration8 __asm__("$8") = frame.spB8;
                                register int angle __asm__("$7");
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP4_CLOBBER(destination, vector, angle, output,
                                                       "memory");
                                MATCHING_KEEP(iteration8);
                                random &= 15;
                                angle = iteration8 << 6;
                                component = *(unsigned short*)(Level33SpawnD_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp54 = component;
                                random = *(unsigned short*)(Level33SpawnD_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp58 = random;
                                Level33SpawnTransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else {
                            register int two __asm__("$2") = 2;
                            MATCHING_KEEP(two);
                            scratch16 = 5;
                            if (modeSelector == (unsigned char*)two) {
                                {
                                    register int iteration8 __asm__("$9") = frame.spB8;
                                    __asm__(""
                                            : "=r"(iteration8)
                                            : "0"(iteration8)
                                            : "$17", "$16", "$19", "memory");
                                    scratch17 = iteration8 << 5;
                                    __asm__(""
                                            : "=r"(scratch17)
                                            : "0"(scratch17)
                                            : "$16", "$19", "memory");
                                }
                                scratch16 = 6;
                                scratch19 = 0x30;
                                goto updateSharedVector;
                            } else {
                                {
                                    register int iteration9 __asm__("$8") = frame.spB8;
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
                    Level33SpawnCopyVector(&frame.sp40, Level33SpawnD_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Level33SpawnD_80065920;
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
                        value = (int)Level33SpawnD_800658A0;
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
                    Level33SpawnPackVectorShiftRight2(var_a0, &frame.sp40);
                    Level33SpawnPackVectorShiftRight2(record + 0x18, &frame.sp50);
                    Level33SpawnField(record, short*, 0x1E) = 0;
                    Level33SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level33Spawnrand();
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level33SpawnField(record, unsigned char*, 12) = scratch19;
                    Level33SpawnField(record, unsigned char*, 13) = scratch19;
                    Level33SpawnField(record, unsigned char*, 14) = scratch19;
                    Level33SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x24:
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = Level33Spawnrand();
                    tailByte &= 7;
                    tailByte -= 4;
                    Level33SpawnField(record, unsigned short*, 24) = tailByte;
                    tailByte = Level33Spawnrand();
                    tailByte &= 7;
                    tailByte -= 4;
                    Level33SpawnField(record, unsigned short*, 26) = tailByte;
                    tailByte = Level33Spawnrand();
                    tailByte &= 15;
                    tailByte += 8;
                    Level33SpawnField(record, unsigned short*, 28) = tailByte;
                    tailByte = (int)modeSelector >> 2;
                    Level33SpawnField(record, unsigned short*, 30) = tailByte;
                    tailByte = 64;
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level33Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                    Level33SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level33SpawnField(record, unsigned char*, 12) = byte255;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$3", "memory");
                    Level33SpawnField(record, unsigned char*, 13) = byte255;
                    goto initializeZeroE;
                case 0x32:
                    record = Level33SpawnAllocateParticleRecord(4);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3") =
                            Level33SpawnField(record, unsigned char*, 1);
                        MATCHING_KEEP3_CLOBBER(destination, source, flags, "$2");
                        tailByte = 1;
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        MATCHING_KEEP_CLOBBER(flags, "memory");
                        flags |= 16;
                        Level33SpawnField(record, unsigned char*, 1) = flags;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 20;
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = 2;
                    Level33SpawnField(record, unsigned char*, 11) = 0;
                    Level33SpawnField(record, unsigned char*, 12) = byte128;
                    Level33SpawnField(record, unsigned char*, 13) = byte128;
                    Level33SpawnField(record, unsigned char*, 14) = byte128;
                    Level33SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x37:
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 64;
                    Level33SpawnField(record, unsigned char*, 0xA) = tailByte;
                    tailByte = Level33Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte, tailByte, "memory");
                    Level33SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level33SpawnField(record, unsigned char*, 0xC) = byte255;
                    Level33SpawnField(record, unsigned char*, 13) = byte255;
                    goto initializeZeroE;
                case 0x34:
                case 0x38:
                    record = Level33SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) = 0;
                    Level33SpawnField(record, unsigned char*, 3) = tailByte;
                    Level33SpawnField(record, unsigned short*, 4) =
                        Level33SpawnField(reference, unsigned short*, 4);
                    Level33SpawnField(record, unsigned short*, 6) =
                        Level33SpawnField(reference, unsigned short*, 6);
                    Level33SpawnField(record, unsigned short*, 8) =
                        Level33SpawnField(reference, unsigned short*, 8);
                    Level33SpawnField(record, int*, 24) = Level33SpawnField(reference, int*, 24);
                    Level33SpawnField(record, int*, 28) = Level33SpawnField(reference, int*, 28);
                    tailByte = Level33SpawnField(reference, unsigned char*, 10);
                    MATCHING_KEEP(tailByte);
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register unsigned int sourceByte __asm__("$2") =
                            Level33SpawnField(reference, unsigned char*, 11);
                        MATCHING_KEEP_CLOBBER(sourceByte, "memory");
                        commonByte9 = 46;
                        Level33SpawnField(record, volatile unsigned char*, 12) = 0;
                        Level33SpawnField(record, volatile unsigned char*, 13) = 0;
                        Level33SpawnField(record, volatile unsigned char*, 14) = 0;
                        Level33SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                        Level33SpawnField(record, volatile unsigned char*, 17) = 0;
                        Level33SpawnField(record, volatile unsigned char*, 16) = 0;
                        Level33SpawnField(record, unsigned char*, 11) = sourceByte;
                    }
                    break;
                case 0x3B: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Level33SpawnField(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Level33SpawnField(record, unsigned char*, 3) = value;
                        value = 16;
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Level33SpawnField(record, unsigned char*, 1) = flags;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level33SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level33SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Level33SpawnField(record, int*, 12) = var_v0;
                    Level33SpawnField(record, unsigned char*, 0xA) =
                        (unsigned char)((Level33Spawnrand() & 0xF) + 0x14);
                    Level33SpawnField(record, unsigned char*, 0xB) = Level33Spawnrand();
                    Level33SpawnField(record, unsigned char*, 0x10) = 0;
                    Level33SpawnField(record, short*, 0x18) = (short)((Level33Spawnrand() & 7) - 4);
                    Level33SpawnField(record, short*, 0x1A) =
                        (short)(-2 - (Level33Spawnrand() & 7));
                    Level33SpawnField(record, short*, 0x1C) =
                        (short)((Level33Spawnrand() & 0xF) - 8);
                    break;
                case 0x3D:
                    record = Level33SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level33SpawnField(record, unsigned char*, 2) = 0;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 72;
                    Level33SpawnField(record, short*, 30) = 0;
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level33Spawnrand();
                    {
                        register int mask __asm__("$3") = -128;
                        MATCHING_KEEP2_CLOBBER(mask, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 11) = tailByte;
                        tailByte = (int)modeSelector & mask;
                        Level33SpawnField(record, unsigned char*, 12) = tailByte;
                        tailByte = (int)modeSelector >> 8;
                        tailByte &= mask;
                        commonByte = 46;
                        MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                        Level33SpawnField(record, unsigned char*, 13) = tailByte;
                        tailByte = 8;
                    initializeEZero:
                    }
                initializeZeroE:
                    Level33SpawnField(record, unsigned char*, 14) = 0;
                initializeF8:
                    Level33SpawnField(record, unsigned char*, 15) = commonByte;
                initializeTrailingBytes:
                    Level33SpawnField(record, unsigned char*, 17) = tailByte;
                    Level33SpawnField(record, unsigned char*, 16) = 0;
                    break;
                case 0x42: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(0);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level33Spawnrand() & 0xF);
                    Level33SpawnField(record, unsigned char*, 3) = 1;
                    Level33SpawnField(record, short*, 4) =
                        (short)((((int)Level33SpawnField(reference, int*, 0) >> 2) +
                                 (Level33Spawnrand() & 0xF)) -
                                8);
                    Level33SpawnField(record, short*, 6) =
                        (short)((((int)Level33SpawnField(reference, int*, 4) >> 2) +
                                 (Level33Spawnrand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Level33SpawnField(record, short*, 16) = 0;
                        Level33SpawnField(record, short*, 18) = 0;
                        Level33SpawnField(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Level33SpawnField(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Level33SpawnD_8006E344;
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
                        register int one __asm__("$9") = 1;
                        MATCHING_KEEP2(one, var_v0_4);
                        Level33SpawnField(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Level33SpawnField(Level33SpawnD_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Level33Spawnrand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Level33SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level33SpawnField(record, unsigned char*, 0xD) = 0;
                            Level33SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Level33SpawnField(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Level33SpawnField(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Level33SpawnField(record, unsigned char*, 13) = byte255;
                            Level33SpawnField(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Level33SpawnField(record, unsigned char*, 0xC) = 0;
                            Level33SpawnField(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Level33SpawnField(record, unsigned char*, 0xC) = 0;
                            Level33SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Level33SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level33SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            MATCHING_KEEP(byte128);
                            Level33SpawnField(record, unsigned char*, 12) = byte255;
                            Level33SpawnField(record, unsigned char*, 13) = byte128;
                        }
                            Level33SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            MATCHING_KEEP(byte128);
                            Level33SpawnField(record, unsigned char*, 12) = 0;
                            Level33SpawnField(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Level33SpawnField(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Level33SpawnField(record, unsigned char*, 0xF) = 0x40;
                    break;
                case 0x46: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(1);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level33Spawnrand() & 0xF);
                    Level33SpawnField(record, unsigned char*, 3) = 1;
                    frame.sp70 = 0;
                    frame.sp71 = Level33Spawnrand();
                    frame.sp72 = Level33Spawnrand();
                    Level33SpawnBuildPackedAngleBasisMatrix(&frame.sp70, &frame.sp78, 0);
                    frame.sp60 = (int)modeSelector;
                    frame.sp64 = 0;
                    frame.sp68 = 0;
                    Level33SpawnTransformVectorByBasis(&frame.sp78, (unsigned char*)&frame.sp60,
                                                       (unsigned char*)&frame.sp60);
                    Level33SpawnField(record, unsigned short*, 4) =
                        (unsigned short)((int)Level33SpawnField(reference, int*, 0) >> 2);
                    Level33SpawnField(record, unsigned short*, 6) =
                        (unsigned short)((int)Level33SpawnField(reference, int*, 4) >> 2);
                    Level33SpawnField(record, unsigned short*, 8) =
                        (unsigned short)((int)Level33SpawnField(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.sp60;
                        register int other __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 4);

                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level33SpawnField(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.sp64;
                        other = Level33SpawnField(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level33SpawnField(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.sp68;
                        value = 2;
                        Level33SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level33SpawnField(record, unsigned char*, 16) = value;
                        value = 192;
                        Level33SpawnField(record, unsigned char*, 17) = value;
                        value = 80;
                        Level33SpawnField(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Level33SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");

                        MATCHING_KEEP(byte128);
                        Level33SpawnField(record, unsigned char*, 18) = 0;
                        Level33SpawnField(record, unsigned char*, 20) = byte255;
                        Level33SpawnField(record, unsigned char*, 21) = byte255;
                        Level33SpawnField(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Level33SpawnField(record, short*, 14) = value;
                    }
                    break;
                case 0x47: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(1);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level33Spawnrand() & 7);
                    Level33SpawnField(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Level33Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp90 = temp_v0_4;
                    temp_v0_5 = (int)(((Level33Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp94 = temp_v0_5;
                    temp_v0_6 = (int)(((Level33Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp98 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Level33SpawnField(reference, int*, 0);
                        value = frame.sp90;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level33SpawnField(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level33SpawnField(reference, int*, 4);
                        value = frame.sp94;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level33SpawnField(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level33SpawnField(reference, int*, 8);
                        value = frame.sp98;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level33SpawnField(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.sp90;
                        register int value __asm__("$2") =
                            Level33SpawnField(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level33SpawnField(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.sp94;
                        value = Level33SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level33SpawnField(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.sp98;
                        other = Level33SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Level33SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level33SpawnField(record, unsigned char*, 16) = value;
                        Level33SpawnField(record, unsigned char*, 17) = value;
                        value = 96;
                        Level33SpawnField(record, unsigned char*, 18) = value;
                        Level33SpawnField(record, unsigned char*, 20) = byte255;
                        Level33SpawnField(record, unsigned char*, 21) = byte255;
                        Level33SpawnField(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Level33SpawnField(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Level33SpawnField(record, short*, 14) = other;
                    }
                    break;
                case 0x4A:
                    record = Level33SpawnAllocateParticleRecord(0);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level33Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 15;
                        Level33SpawnField(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Level33SpawnField(record, unsigned char*, 3) = tailByte;
                        Level33SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 16, modeSelector);
                    tailByte = Level33Spawnrand();
                    tailByte |= 192;
                    Level33SpawnField(record, unsigned char*, 12) = tailByte;
                    tailByte = Level33Spawnrand();
                    tailByte &= 63;
                    tailByte -= 128;
                    Level33SpawnField(record, unsigned char*, 13) = tailByte;
                    tailByte = 64;
                    Level33SpawnField(record, unsigned char*, 15) = tailByte;
                    tailByte = 4;
                    Level33SpawnField(record, unsigned char*, 14) = 0;
                    Level33SpawnField(record, unsigned char*, 10) = tailByte;
                    break;
                case 0x4E: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(0);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level33Spawnrand() & 0x1F);
                    Level33SpawnField(record, unsigned char*, 3) = 1;
                    Level33SpawnPackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level33SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level33SpawnField(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level33SpawnField(record, unsigned short*, 8) = component;
                    }
                    Level33SpawnField(record, short*, 0x10) = (short)((Level33Spawnrand() & 2) - 1);
                    Level33SpawnField(record, short*, 0x12) = (short)((Level33Spawnrand() & 2) - 1);
                    Level33SpawnField(record, short*, 0x14) = (short)-(Level33Spawnrand() & 1);
                    tailByte = Level33Spawnrand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level33SpawnField(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Level33Spawnrand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Level33SpawnField(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Level33SpawnField(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Level33SpawnField(record, unsigned char*, 13) = component;
                    }
                    Level33SpawnField(record, unsigned char*, 0xE) =
                        (unsigned char)((Level33Spawnrand() & 0x3F) + 0x40);
                    Level33SpawnField(record, unsigned char*, 0xF) = 0x40;
                    Level33SpawnField(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                    record = Level33SpawnAllocateParticleRecord(1);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level33SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level33Spawnrand() & 0xF);
                    Level33SpawnField(record, unsigned char*, 3) = 1;
                    Level33SpawnPackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.sp90;
                        MATCHING_KEEP(vector);
                        Level33SpawnAddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Level33Spawnrand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&frame.sp90;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            frame.sp90 = component;
                        }

                        {
                            register int random __asm__("$2") = Level33Spawnrand();
                            register int component __asm__("$3") = frame.sp94;

                            random &= 0x3F;

                            component -= 0x20;

                            component += random;
                            frame.sp94 = component;
                        }

                        {
                            register int random __asm__("$2") = Level33Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;

                            component = frame.sp98;

                            random &= 0x7F;

                            component -= 0x40;

                            component += random;
                            frame.sp98 = component;
                            Level33SpawnPackVectorShiftRight2(destination, source);
                        }
                    }
                    Level33SpawnField(record, unsigned char*, 0x17) = 2;
                    tailByte = Level33Spawnrand();
                    tailByte |= 192;

                    Level33SpawnField(record, unsigned char*, 16) = tailByte;
                    Level33SpawnField(record, unsigned char*, 0x11) =
                        (unsigned char)((Level33Spawnrand() & 0x3F) - 0x60);
                    Level33SpawnField(record, unsigned char*, 0x12) = 0;
                    tailByte = Level33Spawnrand();
                    tailByte |= 224;

                    Level33SpawnField(record, unsigned char*, 20) = tailByte;
                    tailByte = Level33Spawnrand();
                    tailByte |= 224;

                    Level33SpawnField(record, unsigned char*, 21) = tailByte;
                    {

                        Level33SpawnField(record, unsigned char*, 0x16) = byte128;
                    }
                    Level33SpawnField(record, unsigned char*, 0x13) = 0x50;
                    break;
                case 0x52:
                    temp_s1 = Level33SpawnField(reference, unsigned char**, 0);
                    record = Level33SpawnAllocateParticleRecord(1);
                    Level33SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level33Spawnrand();
                    tailByte &= 15;
                    Level33SpawnField(record, unsigned char*, 2) = tailByte;
                    tailByte = 1;
                    Level33SpawnField(record, unsigned char*, 3) = tailByte;
                    tailByte = Level33Spawnrand();
                    scratch16 = tailByte & 255;
                    {
                        register int upper __asm__("$5") = Level33SpawnField(temp_s1, int*, 4);
                        tailByte = Level33SpawnRandBetween(upper >> 1, upper);
                    }
                    scratch16 <<= 1;
                    {
                        register int component __asm__("$3") =
                            Level33SpawnField(Level33SpawnD_80065920 + scratch16, short*, 0);
                        register int low8 __asm__("$8") = component * tailByte;
                        MATCHING_KEEP2(low8, tailByte);
                        component = low8 >> 12;
                        frame.spA0 = component;
                    }
                    {
                        register int component __asm__("$3") =
                            Level33SpawnField(Level33SpawnD_800658A0 + scratch16, short*, 0);
                        register int low9 __asm__("$9") = component * tailByte;
                        register void* third __asm__("$6") = reference + 12;
                        register void* first __asm__("$4");
                        register void* second __asm__("$5");
                        scratch16 = (int)&frame.spA0;
                        first = (void*)scratch16;
                        second = first;
                        frame.spA8 = 0;
                        MATCHING_KEEP4(low9, third, first, second);
                        tailByte = low9 >> 12;
                        frame.spA4 = tailByte;
                        Level33SpawnAddVector(first, second, third);
                    }
                    Level33SpawnPackVectorShiftRight2(record + 4, (void*)scratch16);
                    {
                        register int value3 __asm__("$3") =
                            Level33SpawnField(record, unsigned short*, 4);
                        register int value2 __asm__("$2") =
                            Level33SpawnField(record, unsigned short*, 8);
                        register int value4 __asm__("$4") =
                            Level33SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP3(value3, value2, value4);
                        value2 += 96;
                        Level33SpawnField(record, volatile unsigned short*, 10) = value3;
                        Level33SpawnField(record, volatile unsigned short*, 12) = value4;
                        Level33SpawnField(record, volatile unsigned short*, 14) = value2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value3 = Level33SpawnField(reference, int*, 20);
                        value4 = Level33SpawnField(temp_s1, int*, 0);
                        __asm__ volatile(""
                                         : "=r"(value3), "=r"(value4)
                                         : "0"(value3), "1"(value4)
                                         : "$2", "memory");
                        tailByte = 112;
                        MATCHING_KEEP3_CLOBBER(value3, value4, tailByte, "memory");
                        Level33SpawnField(record, unsigned char*, 16) = tailByte;
                        Level33SpawnField(record, unsigned char*, 17) = tailByte;
                        tailByte = 224;
                        Level33SpawnField(record, unsigned char*, 18) = tailByte;
                        Level33SpawnField(record, unsigned char*, 20) = tailByte;
                        Level33SpawnField(record, unsigned char*, 21) = tailByte;
                        tailByte = 80;
                        Level33SpawnField(record, unsigned char*, 22) = byte255;
                        Level33SpawnField(record, unsigned char*, 19) = tailByte;
                        Level33SpawnField(record, unsigned char*, 23) = 0;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(value3, value4, "memory");
                        value3 += value4;
                        value3 >>= 2;
                        Level33SpawnField(record, int*, 24) = value3;
                    }
                    break;
            }
            {
                register int stride9 __asm__("$8") = frame.spD0;
                register int stride8 __asm__("$9") = frame.spB8;
                MATCHING_KEEP2(stride9, stride8);
                stride9 += 4;
                frame.spD0 = stride9;
                stride9 = frame.spB0;
                MATCHING_KEEP2(stride9, stride8);
                stride8 += 1;
                var_v0 = stride8 < stride9;
                __asm__ volatile(""
                                 : "=r"(var_v0), "=r"(stride8)
                                 : "0"(var_v0), "1"(stride8)
                                 : "$3", "memory");
                frame.spB8 = stride8;
            }
        } while (var_v0);
    }
    return record;
}

#undef Level33SpawnField

#undef Level33SpawnHigh
