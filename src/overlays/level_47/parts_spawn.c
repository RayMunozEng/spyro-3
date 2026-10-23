#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI-generated; not human reviewed. Original SCUS-94467 USA Rev0 level47 instruction/data evidence: build/sibling4211.func_level_47_8008A9DC.json. Raw helper meanings/units/cadence unresolved. */
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Level47SpawnHigh(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Level47SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level47SpawnColor2[] __asm__("D_80066BAC");
#define Level47SpawnField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level47SpawnBuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Level47SpawnTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level47SpawnShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Level47SpawnCopyVector(void*, void*) __asm__("func_8004F178");
int Level47SpawnAddVector(void*, void*, void*) __asm__("func_8004F194");
int Level47SpawnMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Level47SpawnPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Level47SpawnAllocateParticleRecord(int) __asm__("func_80056434");
int Level47SpawnRandBetween(int, int) __asm__("func_8003636C");
int Level47Spawnrand(void) __asm__("rand");
extern unsigned char Level47SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level47SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level47SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level47SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level47SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level47SpawnD_80070328[] __asm__("D_80070328");
extern int Level47SpawnD_8006E344 __asm__("D_8006E344");
void* func_level_47_8008A9DC(int entryCount, int kind, void* input, void* mode) {
    struct {
        int sp10, sp14, sp18, pad1C;
        int sp20, sp24, sp28, pad2C;
        int sp30, sp34, sp38, pad3C;
        int sp40, sp44, sp48, pad4C;
        int sp50, sp54, sp58, pad5C;
        unsigned char sp60, sp61, sp62, pad63;
        int pad64;
        int sp68, matrix6C, matrix70, matrix74, matrix78, matrix7C;
        int sp80, sp84, sp88;
        int pad8C;
        int sp90, sp94, sp98, pad9C;
        int spA0, padA4;
        int* volatile spA8;
        int padAC, padB0, padB4;
        volatile int spB8;
        int padBC;
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
    register int iteration;
    register int byte255 __asm__("$23");
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailByte __asm__("$2");
    register int tailHalf3 __asm__("$3");
    register int commonByte __asm__("$8");
    register int scratch19 __asm__("$19");
    int var_v0_2;
    register int var_v0_4 __asm__("$2");
    unsigned int temp_v1_2;
    int temp_v0_7;
    unsigned char temp_v1_3;
    void* var_a0;
    register unsigned char* record __asm__("$18");

    MATCHING_KEEP3(kindSelector, reference, modeSelector);
    iteration = 0;
    record = 0;
    frame.spA0 = entryCount;
    if (entryCount > 0) {
        {
            register int* vectorBase __asm__("$8") = &frame.sp20;
            MATCHING_KEEP_CLOBBER(vectorBase, "$23");
            byte255 = 255;
            frame.spA8 = vectorBase;
        }
        frame.spB8 = 0;
        do {
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$8");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = one;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level47SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level47SpawnField(record, short*, 0x1E) = 0;
                    Level47SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level47Spawnrand();
                    {
                        register int byte128 __asm__("$8") = 128;
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$3", "memory");
                        Level47SpawnField(record, unsigned char*, 0xC) = byte128;
                        Level47SpawnField(record, unsigned char*, 0xD) = byte128;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0xE) = byte128;
                        commonByte = 46;
                        MATCHING_KEEP_CLOBBER(commonByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0xB) = tailByte;
                        __asm__ volatile(""
                                         : "=r"(tailByte)
                                         : "0"(tailByte), "r"(kindSelector)
                                         : "$3", "memory");
                        tailByte = 4;
                    }

                    goto initializeTrailingBytes;
                case 0x1: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level47SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level47SpawnField(record, short*, 0x1E) = 0;
                    Level47SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level47Spawnrand();
                    Level47SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte, tailByte, "memory");

                    Level47SpawnField(record, unsigned char*, 0xC) = tailByte;
                    Level47SpawnField(record, unsigned char*, 0xD) = tailByte;
                    Level47SpawnField(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    goto initializeTrailingBytes;
                case 0x6:
                    temp_s1 = Level47SpawnField(reference, unsigned char**, 0);
                    record = Level47SpawnAllocateParticleRecord(3);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level47Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5");
                        scratch16 = (int)(reference + 12);
                        source = (void*)scratch16;
                        MATCHING_KEEP4(destination, source, scratch16, tailByte);
                        tailByte &= 15;
                        Level47SpawnField(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        component -= 63;
                        component += random;
                        Level47SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        Level47SpawnField(record, int*, 24) = scratch16;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                        component -= 63;
                        component += random;
                        Level47SpawnField(record, unsigned short*, 6) = component;
                    }
                    tailByte = Level47SpawnField(temp_s1, int*, 4);
                    Level47SpawnField(record, unsigned short*, 28) = tailByte;
                    {
                        register int byte128 __asm__("$8");
                        register int value __asm__("$3") = Level47SpawnField(temp_s1, int*, 0);
                        tailByte = 32;
                        Level47SpawnField(record, unsigned char*, 10) = tailByte;
                        __asm__("" : "=r"(value) : "0"(value) : "$8", "memory");
                        tailByte = 20;
                        byte128 = 128;

                        MATCHING_KEEP2_CLOBBER(value, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 12) = byte128;
                        Level47SpawnField(record, unsigned char*, 13) = byte128;
                        MATCHING_KEEP2_CLOBBER(byte128, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        Level47SpawnField(record, unsigned char*, 14) = byte128;
                        Level47SpawnField(record, unsigned char*, 15) = tailByte;
                        Level47SpawnField(record, unsigned char*, 17) = 0;
                        Level47SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
                        value >>= 6;
                        Level47SpawnField(record, unsigned short*, 30) = value;
                    }
                    break;
                case 0x9: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = &frame.sp10;
                        register unsigned char* player __asm__("$16");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$16");
                        player = Level47SpawnD_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnCopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp10;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp10 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = &frame.sp10;
                            __asm__(""
                                    : "=r"(destination), "=r"(source)
                                    : "0"(destination), "1"(source)
                                    : "$3", "memory");
                            component = frame.sp14;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp14 = component;
                            Level47SpawnPackVectorShiftRight2(destination, source);
                        }
                        Level47SpawnCopyVector(&frame.sp10, player + 0x98);
                        Level47SpawnShiftVectorRightTowardZero(&frame.sp10, 6);
                        Level47SpawnPackVectorShiftRight2(record + 0x18, &frame.sp10);
                    }
                    Level47SpawnField(record, short*, 0x1E) = 0;
                    Level47SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level47Spawnrand();
                    {
                        register int byte128 __asm__("$8") = 128;
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$4", "memory");
                        Level47SpawnField(record, unsigned char*, 0xC) = byte128;
                        Level47SpawnField(record, unsigned char*, 0xD) = byte128;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0xE) = byte128;
                        commonByte = 46;
                        MATCHING_KEEP_CLOBBER(commonByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0xB) = tailByte;
                        __asm__ volatile(""
                                         : "=r"(tailByte)
                                         : "0"(tailByte), "r"(kindSelector)
                                         : "$4", "memory");
                        tailByte = 4;
                    }

                    goto initializeTrailingBytes;
                case 0xA: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(3);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Level47SpawnD_80070328;
                        tailByte = Level47Spawnrand();
                        destination = record + 4;
                        source = Level47SpawnD_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int factor __asm__("$4") = 0x66660000;
                        register int value __asm__("$2");
                        register int count __asm__("$8");
                        register int dividend __asm__("$3");
                        register int productHigh __asm__("hi");
                        register int color __asm__("$4");
                        value = 24;
                        MATCHING_KEEP2(factor, value);
                        Level47SpawnField(record, unsigned char*, 10) = value;
                        value = 15;
                        Level47SpawnField(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.spA0;
                        factor |= 0x6667;
                        dividend = count - iteration;
                        count = frame.spB8;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Level47SpawnD_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Level47SpawnHigh(dividend, factor);
                        Level47SpawnField(record, unsigned char*, 12) = value;
                        value = *(Level47SpawnColor1 + 1 + count);
                        dividend >>= 31;
                        Level47SpawnField(record, unsigned char*, 13) = value;
                        color = *(Level47SpawnColor2 + 2 + count);
                        value = 44;
                        Level47SpawnField(record, unsigned char*, 15) = value;
                        value = 4;
                        Level47SpawnField(record, unsigned char*, 17) = value;
                        Level47SpawnField(record, unsigned char*, 16) = 0;
                        Level47SpawnField(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        count = productHigh;
                        MATCHING_KEEP(count);
                        value = (count >> 1) - dividend;
                        Level47SpawnField(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register void* vector __asm__("$6");
                        register int base __asm__("$2");
                        register void* table __asm__("$5") = (void*)(iteration * 12);
                        __asm__(""
                                : "=r"(destination), "=r"(table)
                                : "0"(destination), "1"(table)
                                : "$2", "$6", "memory");
                        base = (int)Level47SpawnD_80066A48;
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "$6", "memory");
                        vector = frame.spA8;
                        base = 1;
                        Level47SpawnField(record, unsigned char*, 3) = base;
                        base = 4;
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 17) = base;
                        Level47SpawnTransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Level47SpawnField(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Level47SpawnMultiplyVectorGpfSf0(frame.spA8, frame.spA8, 3);
                    }
                    Level47SpawnAddVector(frame.spA8, frame.spA8, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp20;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp20 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp24;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp24 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp28;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp28 = component;
                        }
                    }
                    if (modeSelector == (unsigned char*)6) {
                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp20;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp20 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp24;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp24 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp28;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp28 = component;
                        }
                    }
                    if (Level47SpawnField(reference, short*, 0x36) == 0xB6) {
                        frame.sp28 += 0x200;
                    }
                    Level47SpawnPackVectorShiftRight2(record + 4, frame.spA8);
                    Level47SpawnField(record, int*, 0xC) =
                        (int)*(int*)(Level47SpawnD_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Level47SpawnField(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Level47Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level47Spawnrand() & 7) + 0x20;
                    }
                    Level47SpawnField(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Level47Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int base __asm__("$3");
                        register void* source __asm__("$5") = (void*)(iteration * 12);
                        __asm__(""
                                : "=r"(destination), "=r"(source), "=r"(tailByte)
                                : "0"(destination), "1"(source), "2"(tailByte)
                                : "$3", "memory");
                        base = (int)Level47SpawnD_80066A48;
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        MATCHING_KEEP2_CLOBBER(source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 11) = tailByte;
                        Level47SpawnField(record, unsigned char*, 16) = 0;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level47SpawnField(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Level47SpawnField(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level47Spawnrand() & 7));
                    Level47SpawnField(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Level47SpawnField(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level47Spawnrand() & 7));
                    Level47SpawnField(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Level47SpawnField(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level47Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level47SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Level47SpawnField(record, unsigned short*, 30) = 0;
                    Level47SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level47Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                    Level47SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level47SpawnField(record, unsigned char*, 12) = byte255;
                    Level47SpawnField(record, unsigned char*, 13) = byte255;
                    Level47SpawnField(record, unsigned char*, 14) = 0;
                    goto initializeTrailingBytes;
                case 0x21: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level47SpawnField(record, unsigned char*, 2) = 0;
                    Level47SpawnField(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp40;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Level47SpawnD_80070328 + 0x98;
                            Level47SpawnCopyVector(destination, temp_s1);
                        }
                        Level47SpawnShiftVectorRightTowardZero((void*)scratch16, 6);
                        Level47SpawnCopyVector(&frame.sp30, temp_s1 - 0x98);
                        frame.sp38 -= 0x164;
                        {
                            register int random __asm__("$2") = Level47Spawnrand();
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
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$19");
                            scratch19 = 48;
                            component = frame.sp34;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp34 = component;
                        }

                        goto setDestination;
                    } else {
                        register int one __asm__("$8") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Level47SpawnD_80070328 + 0x30;
                            frame.sp30 = 0x164;
                            frame.sp34 = 0;
                            frame.sp38 = 0;
                            Level47SpawnTransformVectorByBasis(temp_s1_2, &frame.sp30, &frame.sp30);
                            Level47SpawnAddVector(&frame.sp30, &frame.sp30, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp40 = -(Level47Spawnrand() & 7);
                            {
                                register int random __asm__("$2") = Level47Spawnrand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") = temp_s1_2;
                                register void* vector __asm__("$5") = &frame.sp40;
                                register int angle __asm__("$7") = iteration << 6;
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP4_CLOBBER(destination, vector, angle, output,
                                                       "memory");
                                random &= 15;
                                component = *(unsigned short*)(Level47SpawnD_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp44 = component;
                                random = *(unsigned short*)(Level47SpawnD_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp48 = random;
                                Level47SpawnTransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else if (modeSelector == (unsigned char*)2) {
                            scratch17 = iteration << 5;
                            scratch16 = 6;
                            scratch19 = 0x30;
                            goto updateSharedVector;
                        } else {
                            {
                                register int offset __asm__("$2") = iteration << 5;
                                MATCHING_KEEP(offset);
                                scratch17 = offset + 16;
                            }
                            scratch16 = 5;
                            scratch19 = 0x40;
                        }
                    }

                updateSharedVector:
                    Level47SpawnCopyVector(&frame.sp30, Level47SpawnD_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Level47SpawnD_80065920;
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
                        other = frame.sp30;
                        value >>= scratch16;
                        other += value;
                        value = (int)Level47SpawnD_800658A0;
                        second += value;
                        value = frame.sp38;
                        frame.sp30 = other;
                        other = *(short*)second;
                        value -= 356;
                        frame.sp38 = value;
                        value = frame.sp34;
                        other >>= scratch16;
                        value += other;
                        frame.sp34 = value;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        value = *first;
                        other = scratch16 + 1;
                        value >>= other;
                        frame.sp40 = value;
                        value = *(short*)second;
                        frame.sp48 = 0;
                        value >>= other;
                        frame.sp44 = value;
                    }
                setDestination:
                    var_a0 = record + 4;
                finishMode:
                    Level47SpawnPackVectorShiftRight2(var_a0, &frame.sp30);
                    Level47SpawnPackVectorShiftRight2(record + 0x18, &frame.sp40);
                    Level47SpawnField(record, short*, 0x1E) = 0;
                    Level47SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level47Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte, tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 11) = tailByte;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 0xC) = scratch19;
                    Level47SpawnField(record, unsigned char*, 0xD) = scratch19;
                    Level47SpawnField(record, unsigned char*, 0xE) = scratch19;
                    tailByte = 4;
                    goto initializeTrailingBytes;
                case 0x31:
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 96;
                    Level47SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level47Spawnrand();
                    Level47SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 64;
                    Level47SpawnField(record, unsigned char*, 12) = tailByte;
                    Level47SpawnField(record, unsigned char*, 13) = tailByte;
                    Level47SpawnField(record, unsigned char*, 14) = tailByte;
                    commonByte = 46;
                    tailByte = 2;
                    goto initializeTrailingBytes;
                case 0x3B: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Level47SpawnField(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Level47SpawnField(record, unsigned char*, 3) = value;
                        value = 16;
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Level47SpawnField(record, unsigned char*, 1) = flags;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level47SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level47SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Level47SpawnField(record, int*, 12) = var_v0;
                    Level47SpawnField(record, unsigned char*, 0xA) =
                        (unsigned char)((Level47Spawnrand() & 0xF) + 0x14);
                    Level47SpawnField(record, unsigned char*, 0xB) = Level47Spawnrand();
                    Level47SpawnField(record, unsigned char*, 0x10) = 0;
                    Level47SpawnField(record, short*, 0x18) = (short)((Level47Spawnrand() & 7) - 4);
                    Level47SpawnField(record, short*, 0x1A) =
                        (short)(-2 - (Level47Spawnrand() & 7));
                    Level47SpawnField(record, short*, 0x1C) =
                        (short)((Level47Spawnrand() & 0xF) - 8);
                    break;
                case 0x3C:
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level47SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    {
                        register int value __asm__("$3") = Level47SpawnField(modeSelector, int*, 8);
                        tailByte = value - 1;
                        MATCHING_KEEP2(tailByte, value);
                        if ((unsigned)tailByte < 7) {
                            tailByte = value << 5;
                            Level47SpawnField(record, unsigned char*, 2) = tailByte;
                            Level47SpawnField(record, unsigned short*, 28) = 0;
                            Level47SpawnField(record, unsigned char*, 14) = byte255;
                        } else
                            Level47SpawnField(record, unsigned char*, 14) = 0;
                    }
                    tailByte = 24;
                    Level47SpawnField(record, unsigned short*, 30) = 0;
                    Level47SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level47Spawnrand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                    Level47SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level47SpawnField(record, unsigned char*, 12) = byte255;
                    Level47SpawnField(record, unsigned char*, 13) = byte255;
                    goto initializeTrailingBytes;
                case 0x3D:
                    record = Level47SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 72;
                    Level47SpawnField(record, short*, 30) = 0;
                    Level47SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level47Spawnrand();
                    {
                        register int mask __asm__("$3") = -128;
                        MATCHING_KEEP2_CLOBBER(mask, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 11) = tailByte;
                        tailByte = (int)modeSelector & mask;
                        Level47SpawnField(record, unsigned char*, 12) = tailByte;
                        tailByte = (int)modeSelector >> 8;
                        tailByte &= mask;
                        commonByte = 46;
                        MATCHING_KEEP2_CLOBBER(tailByte, commonByte, "memory");
                        Level47SpawnField(record, unsigned char*, 13) = tailByte;
                        tailByte = 8;
                    initializeEZero:
                    }
                initializeZeroE:
                    Level47SpawnField(record, unsigned char*, 14) = 0;
                initializeTrailingBytes:
                    Level47SpawnField(record, unsigned char*, 15) = commonByte;
                initializeByte11:
                    Level47SpawnField(record, unsigned char*, 17) = tailByte;
                    Level47SpawnField(record, unsigned char*, 16) = 0;
                    break;
                case 0x42: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(0);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level47SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level47Spawnrand() & 0xF);
                    Level47SpawnField(record, unsigned char*, 3) = 1;
                    Level47SpawnField(record, short*, 4) =
                        (short)((((int)Level47SpawnField(reference, int*, 0) >> 2) +
                                 (Level47Spawnrand() & 0xF)) -
                                8);
                    Level47SpawnField(record, short*, 6) =
                        (short)((((int)Level47SpawnField(reference, int*, 4) >> 2) +
                                 (Level47Spawnrand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Level47SpawnField(record, short*, 16) = 0;
                        Level47SpawnField(record, short*, 18) = 0;
                        Level47SpawnField(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Level47SpawnField(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Level47SpawnD_8006E344;
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
                        Level47SpawnField(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Level47SpawnField(Level47SpawnD_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Level47Spawnrand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Level47SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level47SpawnField(record, unsigned char*, 0xD) = 0;
                            Level47SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Level47SpawnField(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Level47SpawnField(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Level47SpawnField(record, unsigned char*, 13) = byte255;
                            Level47SpawnField(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Level47SpawnField(record, unsigned char*, 0xC) = 0;
                            Level47SpawnField(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Level47SpawnField(record, unsigned char*, 0xC) = 0;
                            Level47SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Level47SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level47SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            register int byte128 __asm__("$8") = 128;
                            MATCHING_KEEP(byte128);
                            Level47SpawnField(record, unsigned char*, 12) = byte255;
                            Level47SpawnField(record, unsigned char*, 13) = byte128;
                        }
                            Level47SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            register int byte128 __asm__("$8") = 128;
                            MATCHING_KEEP(byte128);
                            Level47SpawnField(record, unsigned char*, 12) = 0;
                            Level47SpawnField(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Level47SpawnField(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Level47SpawnField(record, unsigned char*, 0xF) = 0x40;
                    break;
                case 0x46: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(1);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level47SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level47Spawnrand() & 0xF);
                    Level47SpawnField(record, unsigned char*, 3) = 1;
                    frame.sp60 = 0;
                    frame.sp61 = Level47Spawnrand();
                    frame.sp62 = Level47Spawnrand();
                    Level47SpawnBuildPackedAngleBasisMatrix(&frame.sp60, &frame.sp68, 0);
                    frame.sp50 = modeSelector;
                    frame.sp54 = 0;
                    frame.sp58 = 0;
                    Level47SpawnTransformVectorByBasis(&frame.sp68, (unsigned char*)&frame.sp50,
                                                       (unsigned char*)&frame.sp50);
                    Level47SpawnField(record, unsigned short*, 4) =
                        (unsigned short)((int)Level47SpawnField(reference, int*, 0) >> 2);
                    Level47SpawnField(record, unsigned short*, 6) =
                        (unsigned short)((int)Level47SpawnField(reference, int*, 4) >> 2);
                    Level47SpawnField(record, unsigned short*, 8) =
                        (unsigned short)((int)Level47SpawnField(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.sp50;
                        register int other __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 4);
                        register int byte128 __asm__("$8");
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level47SpawnField(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.sp54;
                        other = Level47SpawnField(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level47SpawnField(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.sp58;
                        value = 2;
                        Level47SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level47SpawnField(record, unsigned char*, 16) = value;
                        value = 192;
                        Level47SpawnField(record, unsigned char*, 17) = value;
                        value = 80;
                        Level47SpawnField(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Level47SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");
                        byte128 = 128;
                        MATCHING_KEEP(byte128);
                        Level47SpawnField(record, unsigned char*, 18) = 0;
                        Level47SpawnField(record, unsigned char*, 20) = byte255;
                        Level47SpawnField(record, unsigned char*, 21) = byte255;
                        Level47SpawnField(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Level47SpawnField(record, short*, 14) = value;
                    }
                    break;
                case 0x47: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(1);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level47SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level47Spawnrand() & 7);
                    Level47SpawnField(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Level47Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp80 = temp_v0_4;
                    temp_v0_5 = (int)(((Level47Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp84 = temp_v0_5;
                    temp_v0_6 = (int)(((Level47Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp88 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Level47SpawnField(reference, int*, 0);
                        value = frame.sp80;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level47SpawnField(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level47SpawnField(reference, int*, 4);
                        value = frame.sp84;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level47SpawnField(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level47SpawnField(reference, int*, 8);
                        value = frame.sp88;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level47SpawnField(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.sp80;
                        register int value __asm__("$2") =
                            Level47SpawnField(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level47SpawnField(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.sp84;
                        value = Level47SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level47SpawnField(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.sp88;
                        other = Level47SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Level47SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level47SpawnField(record, unsigned char*, 16) = value;
                        Level47SpawnField(record, unsigned char*, 17) = value;
                        value = 96;
                        Level47SpawnField(record, unsigned char*, 18) = value;
                        Level47SpawnField(record, unsigned char*, 20) = byte255;
                        Level47SpawnField(record, unsigned char*, 21) = byte255;
                        Level47SpawnField(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Level47SpawnField(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;

                        tailHalf3 = other;
                        goto initializeHalfE;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(0);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level47SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level47Spawnrand() & 0x1F);
                    Level47SpawnField(record, unsigned char*, 3) = 1;
                    Level47SpawnPackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level47SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level47SpawnField(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level47SpawnField(record, unsigned short*, 8) = component;
                    }
                    Level47SpawnField(record, short*, 0x10) = (short)((Level47Spawnrand() & 2) - 1);
                    Level47SpawnField(record, short*, 0x12) = (short)((Level47Spawnrand() & 2) - 1);
                    Level47SpawnField(record, short*, 0x14) = (short)-(Level47Spawnrand() & 1);
                    tailByte = Level47Spawnrand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Level47Spawnrand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Level47SpawnField(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Level47SpawnField(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Level47SpawnField(record, unsigned char*, 13) = component;
                    }
                    Level47SpawnField(record, unsigned char*, 0xE) =
                        (unsigned char)((Level47Spawnrand() & 0x3F) + 0x40);
                    Level47SpawnField(record, unsigned char*, 0xF) = 0x40;
                    Level47SpawnField(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                    record = Level47SpawnAllocateParticleRecord(1);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level47SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level47Spawnrand() & 0xF);
                    Level47SpawnField(record, unsigned char*, 3) = 1;
                    Level47SpawnPackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.sp80;
                        MATCHING_KEEP(vector);
                        Level47SpawnAddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp80;
                            MATCHING_KEEP2(random, component);
                            random &= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component -= 0x20;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp80 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3") = frame.sp84;
                            MATCHING_KEEP2(random, component);
                            random &= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component -= 0x20;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp84 = component;
                        }

                        {
                            register int random __asm__("$2") = Level47Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;
                            __asm__(""
                                    : "=r"(destination), "=r"(source)
                                    : "0"(destination), "1"(source)
                                    : "$3", "memory");
                            component = frame.sp88;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7F;
                            MATCHING_KEEP2(random, component);
                            component -= 0x40;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp88 = component;
                            Level47SpawnPackVectorShiftRight2(destination, source);
                        }
                    }
                    Level47SpawnField(record, unsigned char*, 0x17) = 2;
                    tailByte = Level47Spawnrand();
                    tailByte |= 192;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 16) = tailByte;
                    Level47SpawnField(record, unsigned char*, 0x11) =
                        (unsigned char)((Level47Spawnrand() & 0x3F) - 0x60);
                    Level47SpawnField(record, unsigned char*, 0x12) = 0;
                    tailByte = Level47Spawnrand();
                    tailByte |= 224;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 20) = tailByte;
                    tailByte = Level47Spawnrand();
                    tailByte |= 224;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level47SpawnField(record, unsigned char*, 21) = tailByte;
                    {
                        register int byte128 __asm__("$8") = 128;
                        MATCHING_KEEP(byte128);
                        Level47SpawnField(record, unsigned char*, 0x16) = byte128;
                    }
                    Level47SpawnField(record, unsigned char*, 0x13) = 0x50;
                    break;
                case 0x52:
                    temp_s1 = Level47SpawnField(reference, unsigned char**, 0);
                    record = Level47SpawnAllocateParticleRecord(1);
                    Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level47Spawnrand();
                    tailByte &= 15;
                    Level47SpawnField(record, unsigned char*, 2) = tailByte;
                    tailByte = 1;
                    Level47SpawnField(record, unsigned char*, 3) = tailByte;
                    tailByte = Level47Spawnrand();
                    scratch16 = tailByte & 255;
                    {
                        register int upper __asm__("$5") = Level47SpawnField(temp_s1, int*, 4);
                        tailByte = Level47SpawnRandBetween(upper >> 1, upper);
                    }
                    scratch16 <<= 1;
                    {
                        register int component __asm__("$3") =
                            Level47SpawnField(Level47SpawnD_80065920 + scratch16, short*, 0);
                        register int low8 __asm__("$8") = component * tailByte;
                        MATCHING_KEEP2(low8, tailByte);
                        component = low8 >> 12;
                        frame.sp90 = component;
                    }
                    {
                        register int component __asm__("$3") =
                            Level47SpawnField(Level47SpawnD_800658A0 + scratch16, short*, 0);
                        register int low9 __asm__("$8") = component * tailByte;
                        register void* third __asm__("$6") = reference + 12;
                        register void* first __asm__("$4");
                        register void* second __asm__("$5");
                        scratch16 = (int)&frame.sp90;
                        first = (void*)scratch16;
                        second = first;
                        frame.sp98 = 0;
                        MATCHING_KEEP4(low9, third, first, second);
                        tailByte = low9 >> 12;
                        frame.sp94 = tailByte;
                        Level47SpawnAddVector(first, second, third);
                    }
                    Level47SpawnPackVectorShiftRight2(record + 4, (void*)scratch16);
                    {
                        register int value3 __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 4);
                        register int value2 __asm__("$2") =
                            Level47SpawnField(record, unsigned short*, 8);
                        register int value4 __asm__("$4") =
                            Level47SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP3(value3, value2, value4);
                        value2 += 96;
                        Level47SpawnField(record, volatile unsigned short*, 10) = value3;
                        Level47SpawnField(record, volatile unsigned short*, 12) = value4;
                        Level47SpawnField(record, volatile unsigned short*, 14) = value2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value3 = Level47SpawnField(reference, int*, 20);
                        value4 = Level47SpawnField(temp_s1, int*, 0);
                        __asm__ volatile(""
                                         : "=r"(value3), "=r"(value4)
                                         : "0"(value3), "1"(value4)
                                         : "$2", "memory");
                        tailByte = 112;
                        MATCHING_KEEP3_CLOBBER(value3, value4, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 16) = tailByte;
                        Level47SpawnField(record, unsigned char*, 17) = tailByte;
                        tailByte = 224;
                        Level47SpawnField(record, unsigned char*, 18) = tailByte;
                        Level47SpawnField(record, unsigned char*, 20) = tailByte;
                        Level47SpawnField(record, unsigned char*, 21) = tailByte;
                        tailByte = 80;
                        Level47SpawnField(record, unsigned char*, 22) = byte255;
                        Level47SpawnField(record, unsigned char*, 19) = tailByte;
                        Level47SpawnField(record, unsigned char*, 23) = 0;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(value3, value4, "memory");
                        value3 += value4;
                        value3 >>= 2;
                        Level47SpawnField(record, int*, 24) = value3;
                    }
                    break;
                case 0x55:
                    record = Level47SpawnAllocateParticleRecord(1);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level47SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level47SpawnField(record, unsigned char*, 2) = 0;
                        Level47SpawnField(record, unsigned char*, 3) = tailByte;
                        Level47SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level47SpawnPackVectorShiftRight2(record + 0xA, modeSelector);
                    {
                        register int first __asm__("$3") =
                            Level47SpawnField(record, unsigned short*, 10);
                        register int x __asm__("$4") =
                            Level47SpawnField(record, unsigned short*, 4);
                        register int second __asm__("$2");
                        register int z __asm__("$5");
                        register int byte128 __asm__("$8");
                        __asm__(""
                                : "=r"(first), "=r"(x)
                                : "0"(first), "1"(x)
                                : "$2", "$5", "memory");
                        second = 80;
                        Level47SpawnField(record, unsigned char*, 19) = second;
                        second = Level47SpawnField(record, unsigned short*, 12);
                        z = Level47SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP4_CLOBBER(first, x, second, z, "memory");
                        __asm__(""
                                : "=r"(first), "=r"(x), "=r"(second), "=r"(z)
                                : "0"(first), "1"(x), "2"(second), "3"(z)
                                : "$8", "memory");
                        byte128 = 128;
                        Level47SpawnField(record, unsigned char*, 20) = byte128;
                        MATCHING_KEEP5_CLOBBER(first, x, second, z, byte128, "memory");
                        first += x;
                        x = Level47SpawnField(record, unsigned short*, 6);
                        Level47SpawnField(record, unsigned char*, 23) = 0;
                        Level47SpawnField(record, unsigned char*, 16) = byte255;
                        Level47SpawnField(record, unsigned char*, 17) = byte255;
                        Level47SpawnField(record, unsigned char*, 18) = 0;
                        Level47SpawnField(record, unsigned char*, 21) = byte128;
                        Level47SpawnField(record, unsigned char*, 22) = 0;
                        MATCHING_KEEP4_CLOBBER(first, x, second, z, "memory");
                        Level47SpawnField(record, unsigned short*, 10) = first;
                        first = Level47SpawnField(record, unsigned short*, 14);
                        MATCHING_KEEP4_CLOBBER(first, x, second, z, "memory");
                        second += x;
                        first += z;
                        Level47SpawnField(record, unsigned short*, 12) = second;
                        tailHalf3 = first;
                    }
                initializeHalfE:
                    Level47SpawnField(record, unsigned short*, 14) = tailHalf3;
                    break;
            }
            {
                register int stride __asm__("$8") = frame.spB8;
                MATCHING_KEEP(stride);
                stride += 4;
                frame.spB8 = stride;
                MATCHING_KEEP_VOLATILE_CLOBBER(iteration, "memory");
                stride = frame.spA0;
                MATCHING_KEEP2(stride, iteration);
                iteration += 1;
                var_v0 = iteration < stride;
            }
        } while (var_v0);
    }
    return record;
}
