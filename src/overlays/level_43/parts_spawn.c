#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
typedef struct {
    unsigned char raw[88];
} Level43SpawnRawRecord;
int Level43SpawnInterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern Level43SpawnRawRecord* Level43SpawnRecords __asm__("D_8006C550");
int Level43Spawnfunc_8001A358(void*, int) __asm__("func_8001A358");
extern int Level43SpawnD_8006D07C __asm__("D_8006D07C");
extern int Level43SpawnD_8006D080 __asm__("D_8006D080");
extern int Level43SpawnD_8006D084 __asm__("D_8006D084");
extern int Level43SpawnD_80071934 __asm__("D_80071934");
extern unsigned char Level43SpawnPlayerE __asm__("D_80070328 + 0xE");
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level43SpawnHigh(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Level43SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level43SpawnColor2[] __asm__("D_80066BAC");
#define Level43SpawnField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level43Spawnfunc_8004EA90(void*, void*, int) __asm__("func_8004EA90");
int Level43SpawnTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level43SpawnShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Level43SpawnCopyVector(void*, void*) __asm__("func_8004F178");
int Level43SpawnAddVector(void*, void*, void*) __asm__("func_8004F194");
int Level43SpawnMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Level43SpawnPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Level43Spawnfunc_80056434(int) __asm__("func_80056434");
int Level43Spawnfunc_8004F58C(void*, void*) __asm__("func_8004F58C");
int Level43Spawnrand(void) __asm__("rand");
extern unsigned char Level43SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level43SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level43SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level43SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level43SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level43SpawnD_80070328[] __asm__("D_80070328");
extern int Level43SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original SCUS-94467 USA Rev0 level43
 * evidence: build/sibling4261.func_level_43_8008F96C.json.
 * Raw helper meanings, units and cadence remain unresolved. */
void* func_level_43_8008F96C(int entryCount, int kind, void* input, void* mode) {
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
        int spA0;
        int spA4;
        int spA8;
        int spAC;
        unsigned char spB0, spB1, spB2, padB3;
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
    register int kindSelector __asm__("$23") = kind;
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
    int byte255;
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailHalf3 __asm__("$3");
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
    frame.spE0 = entryCount;
    frame.spE8 = 0;
    if (entryCount > 0) {
        {
            register int* vectorBase __asm__("$8") = &frame.sp30;
            MATCHING_KEEP_CLOBBER(vectorBase, "$30");
            byte255 = 255;
            MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
            frame.spF0 = vectorBase;
        }
        frame.sp100 = 0;
        do {
            MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$9");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = one;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level43SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level43SpawnField(record, short*, 0x1E) = 0;
                    Level43SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level43Spawnrand();
                    commonByte8 = 128;
                    commonByte9 = 128;
                    MATCHING_KEEP3(commonByte8, commonByte9, tailByte);
                    Level43SpawnField(record, volatile unsigned char*, 12) = commonByte8;
                    Level43SpawnField(record, volatile unsigned char*, 13) = commonByte9;
                    commonByte9 = 46;
                    Level43SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level43SpawnField(record, unsigned char*, 14) = commonByte8;
                    goto initializeF9;
                case 0x1: /* switch 1 */
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level43SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level43SpawnField(record, short*, 0x1E) = 0;
                    Level43SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level43Spawnrand();
                    Level43SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 96;
                    commonByte8 = 46;
                    MATCHING_KEEP2(commonByte8, tailByte);
                    Level43SpawnField(record, volatile unsigned char*, 12) = tailByte;
                    Level43SpawnField(record, volatile unsigned char*, 13) = tailByte;
                    Level43SpawnField(record, volatile unsigned char*, 14) = tailByte;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$3", "memory");
                    tailByte = 4;
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x2:
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                        tailByte = Level43Spawnrand();
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp10 = tailByte;
                        tailByte = Level43Spawnrand();
                        destination = record + 24;
                        source = &frame.sp10;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp14 = tailByte;
                        frame.sp18 = 16;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Level43SpawnField(record, unsigned short*, 30) = 0;
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level43Spawnrand();
                    commonByte9 = 128;
                    commonByte8 = 128;
                    MATCHING_KEEP3(commonByte9, commonByte8, tailByte);
                    Level43SpawnField(record, volatile unsigned char*, 12) = commonByte9;
                    Level43SpawnField(record, volatile unsigned char*, 13) = commonByte8;
                    commonByte8 = 46;
                    Level43SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level43SpawnField(record, volatile unsigned char*, 14) = commonByte9;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;

                case 0x9: /* switch 1 */
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* playerVector __asm__("$16") = &frame.sp20;
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Level43SpawnD_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnCopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            Level43SpawnPackVectorShiftRight2(destination, source);
                        }
                        Level43SpawnCopyVector(playerVector, player + 0x98);
                        Level43SpawnShiftVectorRightTowardZero(playerVector, 6);
                        Level43SpawnPackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Level43SpawnField(record, short*, 0x1E) = 0;
                    Level43SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level43Spawnrand();
                    commonByte9 = 128;
                    commonByte8 = 128;
                    MATCHING_KEEP3(commonByte9, commonByte8, tailByte);
                    Level43SpawnField(record, volatile unsigned char*, 12) = commonByte9;
                    Level43SpawnField(record, volatile unsigned char*, 13) = commonByte8;
                    commonByte8 = 46;
                    Level43SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    __asm__ volatile(""
                                     : "=r"(tailByte), "=r"(commonByte8), "=r"(commonByte9)
                                     : "0"(tailByte), "1"(commonByte8), "2"(commonByte9)
                                     : "$3", "memory");
                    Level43SpawnField(record, volatile unsigned char*, 14) = commonByte9;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0xA: /* switch 1 */
                    record = Level43Spawnfunc_80056434(3);
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Level43SpawnD_80070328;
                        tailByte = Level43Spawnrand();
                        destination = record + 4;
                        source = Level43SpawnD_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int factor __asm__("$4") = 0x66660000;
                        register int value __asm__("$2");
                        register int count __asm__("$9");
                        register int iteration8 __asm__("$8");
                        register int dividend __asm__("$3");
                        register int productHigh __asm__("hi");
                        register int color __asm__("$4");
                        value = 24;
                        MATCHING_KEEP2(factor, value);
                        Level43SpawnField(record, unsigned char*, 10) = value;
                        value = 15;
                        Level43SpawnField(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.spE0;
                        iteration8 = frame.spE8;
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = frame.sp100;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Level43SpawnD_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Level43SpawnHigh(dividend, factor);
                        Level43SpawnField(record, unsigned char*, 12) = value;
                        value = *(Level43SpawnColor1 + 1 + count);
                        dividend >>= 31;
                        Level43SpawnField(record, unsigned char*, 13) = value;
                        color = *(Level43SpawnColor2 + 2 + count);
                        value = 44;
                        Level43SpawnField(record, unsigned char*, 15) = value;
                        value = 4;
                        Level43SpawnField(record, unsigned char*, 17) = value;
                        Level43SpawnField(record, unsigned char*, 16) = 0;
                        Level43SpawnField(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Level43SpawnField(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register int iteration __asm__("$9") = frame.spE8;
                        register void* vector __asm__("$6") = frame.spF0;
                        register int base __asm__("$2");
                        register void* table __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(vector)
                                : "0"(destination), "1"(iteration), "2"(vector)
                                : "$2", "$5", "memory");
                        base = (int)Level43SpawnD_80066A48;
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        table = (void*)(iteration * 12);
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "memory");
                        base = 1;
                        Level43SpawnField(record, unsigned char*, 3) = base;
                        base = 4;
                        Level43SpawnField(record, unsigned char*, 17) = base;
                        Level43SpawnTransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Level43SpawnField(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$9", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Level43SpawnMultiplyVectorGpfSf0(frame.spF0, frame.spF0, 3);
                    }
                    Level43SpawnAddVector(frame.spF0, frame.spF0, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                    if (Level43SpawnField(reference, short*, 0x36) == 0xB6) {
                        frame.sp38 += 0x200;
                    }
                    Level43SpawnPackVectorShiftRight2(record + 4, frame.spF0);
                    Level43SpawnField(record, int*, 0xC) =
                        (int)*(int*)(Level43SpawnD_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Level43SpawnField(reference, short*, 54);
                            register int expected __asm__("$9");
                            __asm__ __volatile__("" ::: "$9", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Level43Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level43Spawnrand() & 7) + 0x20;
                    }
                    Level43SpawnField(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Level43Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int iteration __asm__("$8") = frame.spE8;
                        register int base __asm__("$3");
                        register void* source __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(tailByte)
                                : "0"(destination), "1"(iteration), "2"(tailByte)
                                : "$3", "$5", "memory");
                        base = (int)Level43SpawnD_80066A48;
                        Level43SpawnField(record, unsigned char*, 11) = tailByte;
                        Level43SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        source = (void*)(iteration * 12);
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level43SpawnField(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Level43SpawnField(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level43Spawnrand() & 7));
                    Level43SpawnField(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Level43SpawnField(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level43Spawnrand() & 7));
                    Level43SpawnField(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Level43SpawnField(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level43Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level43SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Level43SpawnField(record, short*, 0x1E) = 0;
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level43Spawnrand();
                    commonByte9 = 46;
                    __asm__ volatile(""
                                     : "=r"(commonByte9), "=r"(tailByte)
                                     : "0"(commonByte9), "1"(tailByte)
                                     : "$3", "memory");
                    Level43SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level43SpawnField(record, unsigned char*, 12) = byte255;
                    Level43SpawnField(record, unsigned char*, 13) = byte255;
                    goto initializeEZero;
                case 0x21: /* switch 1 */
                    record = Level43Spawnfunc_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) = 0;
                    Level43SpawnField(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp50;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Level43SpawnD_80070328 + 0x98;
                            Level43SpawnCopyVector(destination, temp_s1);
                        }
                        Level43SpawnShiftVectorRightTowardZero((void*)scratch16, 6);
                        Level43SpawnCopyVector(&frame.sp40, temp_s1 - 0x98);
                        frame.sp48 -= 0x164;
                        {
                            register int random __asm__("$2") = Level43Spawnrand();
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
                            register int random __asm__("$2") = Level43Spawnrand();
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
                        register int one __asm__("$8") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Level43SpawnD_80070328 + 0x30;
                            frame.sp40 = 0x164;
                            frame.sp44 = 0;
                            frame.sp48 = 0;
                            Level43SpawnTransformVectorByBasis(temp_s1_2, &frame.sp40, &frame.sp40);
                            Level43SpawnAddVector(&frame.sp40, &frame.sp40, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp50 = -(Level43Spawnrand() & 7);
                            {
                                register int random __asm__("$2") = Level43Spawnrand();
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
                                component = *(unsigned short*)(Level43SpawnD_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp54 = component;
                                random = *(unsigned short*)(Level43SpawnD_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp58 = random;
                                Level43SpawnTransformVectorByBasis(destination, vector, output);
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
                    Level43SpawnCopyVector(&frame.sp40, Level43SpawnD_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Level43SpawnD_80065920;
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
                        value = (int)Level43SpawnD_800658A0;
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
                    Level43SpawnPackVectorShiftRight2(var_a0, &frame.sp40);
                    Level43SpawnPackVectorShiftRight2(record + 0x18, &frame.sp50);
                    Level43SpawnField(record, short*, 0x1E) = 0;
                    Level43SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level43Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                    Level43SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level43SpawnField(record, volatile unsigned char*, 12) = scratch19;
                    Level43SpawnField(record, volatile unsigned char*, 13) = scratch19;
                    Level43SpawnField(record, volatile unsigned char*, 14) = scratch19;
                    MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, commonByte8, "memory");
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x25:
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* first __asm__("$4") = reference;
                        register int second __asm__("$5") = 0;
                        register void* third __asm__("$6");
                        scratch16 = (int)&frame.sp60;
                        third = (void*)scratch16;
                        tailByte = 1;
                        MATCHING_KEEP5_CLOBBER(first, second, third, tailByte, scratch16, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnInterpolateMobyVertex(first, second, third);
                    }
                    Level43SpawnPackVectorShiftRight2(record + 4, (void*)scratch16);
                    Level43SpawnPackVectorShiftRight2(record + 24, modeSelector);
                    {
                        register Level43SpawnRawRecord* base __asm__("$4") = Level43SpawnRecords;
                        tailByte = 64;
                        Level43SpawnField(record, unsigned char*, 10) = tailByte;
                        tailByte = (Level43SpawnRawRecord*)reference - base;
                        Level43SpawnField(record, short*, 30) = tailByte;
                    }
                    tailByte = Level43Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, commonByte9, "memory");
                    Level43SpawnField(record, unsigned char*, 11) = tailByte;
                    Level43SpawnField(record, unsigned char*, 12) = byte255;
                    Level43SpawnField(record, unsigned char*, 13) = byte255;
                    Level43SpawnField(record, unsigned char*, 14) = 0;
                    Level43SpawnField(record, unsigned char*, 15) = commonByte9;
                    Level43SpawnField(record, unsigned char*, 17) = 0;
                    Level43SpawnField(record, unsigned char*, 16) = 0;
                    break;
                case 0x29: {
                    register unsigned char* stackBase29 __asm__("$29");
                    register void* vector16 __asm__("$16");
                    register void* vector17 __asm__("$17");
                    register int angle21 __asm__("$21");
                    register int radius19 __asm__("$19");
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int index4 __asm__("$4");
                    register int low8 __asm__("$9");
                    register int low9 __asm__("$8");
                    register void* destination4 __asm__("$4");
                    register void* source5 __asm__("$5");
                    __asm__ volatile(
                        "" ::
                            : "$16",
                              "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned char*)&frame - 0x10)
                                     : "memory");
                    vector16 = stackBase29 + 0x70;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    Level43SpawnCopyVector(vector16, reference);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value2 = Level43Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value3 = frame.sp70;
                    value2 &= 255;
                    value3 += 128;
                    value3 -= value2;
                    frame.sp70 = value3;
                    value2 = Level43Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value3 = frame.sp74;
                    value2 &= 255;
                    value3 += 128;
                    value3 -= value2;
                    frame.sp74 = value3;
                    value2 = Level43Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    angle21 = value2 & 255;
                    value2 = Level43Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    {
                        register void* arg4 __asm__("$4") = &frame.sp80;
                        register void* arg5 __asm__("$5") = vector16;
                        MATCHING_KEEP3(arg4, arg5, value2);
                        value2 &= 1023;
                        radius19 = value2 + 512;
                        Level43SpawnCopyVector(arg4, arg5);
                        MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    }
                    destination4 = &frame.sp90;
                    if (modeSelector != 0)
                        source5 = modeSelector;
                    else {
                        source5 = Level43SpawnD_80070328 + 0x8C;
                        MATCHING_KEEP_VOLATILE_CLOBBER(source5, "memory");
                    }
                    Level43SpawnCopyVector(destination4, source5);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    __asm__ volatile(
                        "" ::
                            : "$16",
                              "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned char*)&frame - 0x10)
                                     : "memory");
                    vector16 = stackBase29 + 0x90;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    Level43SpawnShiftVectorRightTowardZero(vector16, 1);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    {
                        register int count9 __asm__("$8") = frame.spE0;
                        register int one8 __asm__("$9") = 1;
                        MATCHING_KEEP2(count9, one8);
                        __asm__ volatile(
                            "" ::
                                : "$17",
                                  "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                        __asm__ volatile(""
                                         : "=r"(stackBase29)
                                         : "0"((unsigned char*)&frame - 0x10)
                                         : "memory");
                        vector17 = stackBase29 + 0x80;
                        if (count9 == one8) {
                            Level43SpawnMultiplyVectorGpfSf0(vector16, vector16, 3);
                            MATCHING_KEEP_VOLATILE_CLOBBER(vector17, "memory");
                            __asm__ volatile(
                                "" ::
                                    : "$17",
                                      "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                            __asm__ volatile(""
                                             : "=r"(stackBase29)
                                             : "0"((unsigned char*)&frame - 0x10)
                                             : "memory");
                            vector17 = stackBase29 + 0x80;
                            MATCHING_KEEP_VOLATILE_CLOBBER(vector17, "memory");
                        }
                    }
                    frame.sp98 = 0;
                    Level43SpawnAddVector(vector17, vector17, vector16);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    index4 = angle21 << 1;
                    value2 = Level43SpawnField(Level43SpawnD_80065920 + index4, short*, 0);
                    __asm__ volatile("" : "=l"(low9) : "0"(value2 * radius19) : "memory");
                    value2 = frame.sp80;
                    value3 = low9 >> 12;
                    value2 += value3;
                    frame.sp80 = value2;
                    value2 = Level43SpawnField(Level43SpawnD_800658A0 + index4, short*, 0);
                    {
                        int productLo = value2 * radius19;
                        __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                        source5 = (void*)1024;
                        value2 = frame.sp88;
                        MATCHING_KEEP2_CLOBBER(source5, value2, "$4");
                        destination4 = vector17;
                        MATCHING_KEEP3(source5, value2, destination4);
                        value2 += 512;
                        frame.sp88 = value2;
                        value2 = frame.sp84;
                        __asm__ volatile(""
                                         : "=l"(productLo), "=r"(value2)
                                         : "0"(productLo), "1"(value2)
                                         : "memory");
                        low8 = productLo;
                        MATCHING_KEEP(low8);
                        value3 = low8 >> 12;
                        value2 += value3;
                        frame.sp84 = value2;
                        value2 = Level43Spawnfunc_8001A358(destination4, (int)source5);
                    }
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    frame.sp88 = value2;
                    if (value2 == 0)
                        break;
                    record = Level43Spawnfunc_80056434(3);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value2 = 1;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    Level43SpawnField(record, volatile unsigned char*, 3) = value2;
                    value2 = 10;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    Level43SpawnField(record, volatile unsigned char*, 10) = value2;
                    value2 = 6;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$4", "memory");
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) = 0;
                    destination4 = record + 4;
                    MATCHING_KEEP(destination4);
                    Level43SpawnField(record, unsigned char*, 11) = value2;
                    value2 = Level43SpawnD_8006D07C;
                    __asm__ volatile("" : "=r"(value2) : "0"(value2) : "$16", "memory");

                    __asm__ volatile(
                        "" ::
                            : "$16",
                              "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned char*)&frame - 0x10)
                                     : "memory");
                    vector16 = stackBase29 + 0x70;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");

                    value2 >>= 4;
                    Level43SpawnField(record, unsigned char*, 12) = value2;
                    value2 = Level43SpawnD_8006D080;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$5", "memory");
                    source5 = vector16;
                    MATCHING_KEEP2(value2, source5);
                    value2 >>= 4;
                    Level43SpawnField(record, unsigned char*, 13) = value2;
                    value3 = Level43SpawnD_8006D084;
                    __asm__ volatile("" : "=r"(value3) : "0"(value3) : "$8", "$2", "memory");
                    commonByte8 = 46;
                    value2 = 2;
                    MATCHING_KEEP3(value3, commonByte8, value2);
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    Level43SpawnField(record, unsigned char*, 17) = value2;
                    Level43SpawnField(record, unsigned char*, 16) = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value3, "memory");
                    value3 >>= 4;
                    Level43SpawnField(record, unsigned char*, 14) = value3;
                    Level43SpawnPackVectorShiftRight2(destination4, source5);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    Level43SpawnPackVectorShiftRight2(record + 18, vector16);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    Level43SpawnPackVectorShiftRight2(record + 24, vector17);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    scratch16 = Level43Spawnrand();
                    value2 = Level43Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    scratch16 &= 14;
                    value2 = (value2 & 6) + 20;
                    scratch16 += value2;
                    Level43SpawnField(record, unsigned short*, 22) = scratch16;
                    Level43SpawnField(record, unsigned char*, 30) = 0;
                    while (scratch16 > 0 || frame.sp78 > frame.sp88) {
                        frame.sp78 += scratch16 << 2;
                        Level43SpawnField(record, unsigned char*, 30) += 1;
                        scratch16 -= 2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch16, "memory");
                    }
                    value2 = Level43Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    Level43SpawnField(record, unsigned char*, 29) = value2;
                    Level43SpawnField(record, unsigned char*, 31) = Level43SpawnD_80071934;
                } break;
                case 0x2A:
                    record = Level43Spawnfunc_80056434(4);
                    {
                        register void* arg4 __asm__("$4") = record + 4;
                        register void* arg5 __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(arg4, arg5, "$2");
                        tailByte = 1;
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(arg4, arg5);
                    }
                    tailByte = Level43SpawnField(reference, int*, 0);
                    Level43SpawnField(record, int*, 24) = tailByte;
                    tailByte = Level43SpawnField(reference, int*, 4);
                    Level43SpawnField(record, int*, 28) = tailByte;
                    tailByte = Level43SpawnField(modeSelector, int*, 0);
                    Level43SpawnField(record, unsigned short*, 18) = tailByte;
                    tailByte = Level43SpawnField(modeSelector, int*, 4);
                    Level43SpawnField(record, unsigned short*, 20) = tailByte;
                    tailByte = Level43Spawnrand();
                    tailByte = (tailByte & 7) + 3;
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = 108;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "$3", "$9", "memory");
                    {
                        register int color3 __asm__("$3") = Level43SpawnPlayerE;
                        __asm__(""
                                : "=r"(color3), "=r"(tailByte)
                                : "0"(color3), "1"(tailByte)
                                : "$9", "memory");
                        commonByte9 = 46;
                        Level43SpawnField(record, unsigned char*, 12) = tailByte;
                        Level43SpawnField(record, unsigned char*, 13) = tailByte;
                        Level43SpawnField(record, unsigned char*, 14) = tailByte;
                        Level43SpawnField(record, unsigned char*, 15) = commonByte9;
                        Level43SpawnField(record, unsigned char*, 17) = 0;
                        Level43SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(color3, "memory");
                        color3 += 32;
                        Level43SpawnField(record, unsigned char*, 11) = color3;
                    }
                    break;
                    {
                        register int commonByte3 __asm__("$3");
                        case 0x2B:
                            record = Level43Spawnfunc_80056434(4);
                            tailByte = 1;
                            Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                            Level43SpawnField(record, unsigned char*, 2) = 0;
                            Level43SpawnField(record, unsigned char*, 3) = tailByte;
                            if (modeSelector == 0) {
                                Level43Spawnfunc_8004F58C(record + 4, reference);
                                tailByte = Level43Spawnrand();
                                tailByte &= 7;
                                tailByte += 2;
                                Level43SpawnField(record, unsigned char*, 10) = tailByte;
                                commonByte3 = 96;
                            } else {
                                Level43SpawnPackVectorShiftRight2(record + 4, reference);
                                {
                                    register int two __asm__("$2") = 2;
                                    MATCHING_KEEP(two);
                                    if (modeSelector == (unsigned char*)two) {
                                        {
                                            register int random __asm__("$2") = Level43Spawnrand();
                                            register int component __asm__("$3") =
                                                Level43SpawnField(record, unsigned short*, 4);
                                            MATCHING_KEEP2(random, component);
                                            random &= 127;
                                            component += 32;
                                            component -= random;
                                            Level43SpawnField(record, unsigned short*, 4) =
                                                component;
                                        }
                                        {
                                            register int random __asm__("$2") = Level43Spawnrand();
                                            register int component __asm__("$3") =
                                                Level43SpawnField(record, unsigned short*, 6);
                                            MATCHING_KEEP2(random, component);
                                            random &= 127;
                                            component += 32;
                                            component -= random;
                                            Level43SpawnField(record, unsigned short*, 6) =
                                                component;
                                        }
                                    }
                                }
                                tailByte = Level43Spawnrand();
                                tailByte &= 7;
                                MATCHING_KEEP(tailByte);
                                tailByte += 16;
                                Level43SpawnField(record, unsigned char*, 10) = tailByte;
                                commonByte3 = 64;
                            }
                            {
                                register int sourceByte __asm__("$2") =
                                    Level43SpawnField(Level43SpawnD_80070328, unsigned char*, 14);
                                MATCHING_KEEP2_CLOBBER(sourceByte, commonByte3, "memory");
                                Level43SpawnField(record, unsigned char*, 12) = commonByte3;
                                Level43SpawnField(record, unsigned char*, 13) = commonByte3;
                                Level43SpawnField(record, unsigned char*, 14) = commonByte3;
                                commonByte8 = 46;
                                MATCHING_KEEP2_CLOBBER(sourceByte, commonByte8, "memory");
                                Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                                Level43SpawnField(record, unsigned char*, 17) = 0;
                                Level43SpawnField(record, unsigned char*, 16) = 0;
                                Level43SpawnField(record, unsigned short*, 24) = (int)modeSelector;
                                Level43SpawnField(record, unsigned char*, 11) = sourceByte;
                            }
                            break;
                    }
                case 0x2E:
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 127;
                        component += 64;
                        component -= random;
                        Level43SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 127;
                        component += 64;
                        component -= random;
                        Level43SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector != 0) {
                        tailByte = Level43Spawnrand();
                        tailByte &= 15;
                        MATCHING_KEEP(tailByte);
                        tailByte = (int)modeSelector + tailByte;
                    } else {
                        tailByte = Level43Spawnrand();
                        tailByte &= 15;
                        MATCHING_KEEP(tailByte);
                        tailByte += 20;
                    }
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level43Spawnrand();
                    commonByte9 = 128;
                    commonByte8 = 128;
                    MATCHING_KEEP3(commonByte9, commonByte8, tailByte);
                    Level43SpawnField(record, volatile unsigned char*, 12) = commonByte9;
                    Level43SpawnField(record, volatile unsigned char*, 13) = commonByte8;
                    commonByte8 = 46;
                    Level43SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    __asm__ volatile(""
                                     : "=r"(tailByte), "=r"(commonByte8), "=r"(commonByte9)
                                     : "0"(tailByte), "1"(commonByte8), "2"(commonByte9)
                                     : "$4", "memory");
                    Level43SpawnField(record, volatile unsigned char*, 14) = commonByte9;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x32:
                    record = Level43Spawnfunc_80056434(4);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3") =
                            Level43SpawnField(record, unsigned char*, 1);
                        MATCHING_KEEP3_CLOBBER(destination, source, flags, "$2");
                        tailByte = 1;
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        MATCHING_KEEP_CLOBBER(flags, "memory");
                        flags |= 16;
                        Level43SpawnField(record, unsigned char*, 1) = flags;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 20;
                    commonByte9 = 128;
                    commonByte8 = 128;
                    MATCHING_KEEP3_CLOBBER(tailByte, commonByte9, commonByte8, "memory");
                    Level43SpawnField(record, volatile unsigned char*, 12) = commonByte9;
                    Level43SpawnField(record, volatile unsigned char*, 13) = commonByte8;
                    commonByte8 = 46;
                    Level43SpawnField(record, volatile unsigned char*, 10) = tailByte;
                    tailByte = 2;
                    Level43SpawnField(record, volatile unsigned char*, 11) = 0;
                    Level43SpawnField(record, volatile unsigned char*, 14) = commonByte9;
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;

                case 0x38:
                    record = Level43Spawnfunc_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) = 0;
                    Level43SpawnField(record, unsigned char*, 3) = tailByte;
                    Level43SpawnField(record, unsigned short*, 4) =
                        Level43SpawnField(reference, unsigned short*, 4);
                    Level43SpawnField(record, unsigned short*, 6) =
                        Level43SpawnField(reference, unsigned short*, 6);
                    Level43SpawnField(record, unsigned short*, 8) =
                        Level43SpawnField(reference, unsigned short*, 8);
                    Level43SpawnField(record, int*, 24) = Level43SpawnField(reference, int*, 24);
                    Level43SpawnField(record, int*, 28) = Level43SpawnField(reference, int*, 28);
                    tailByte = Level43SpawnField(reference, unsigned char*, 10);
                    MATCHING_KEEP(tailByte);
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register unsigned int sourceByte __asm__("$2") =
                            Level43SpawnField(reference, unsigned char*, 11);
                        MATCHING_KEEP_CLOBBER(sourceByte, "memory");
                        commonByte9 = 46;
                        Level43SpawnField(record, volatile unsigned char*, 12) = 0;
                        Level43SpawnField(record, volatile unsigned char*, 13) = 0;
                        Level43SpawnField(record, volatile unsigned char*, 14) = 0;
                        Level43SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                        Level43SpawnField(record, volatile unsigned char*, 17) = 0;
                        Level43SpawnField(record, volatile unsigned char*, 16) = 0;
                        Level43SpawnField(record, unsigned char*, 11) = sourceByte;
                    }
                    break;
                case 0x3B: /* switch 1 */
                    record = Level43Spawnfunc_80056434(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Level43SpawnField(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Level43SpawnField(record, unsigned char*, 3) = value;
                        value = 16;
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Level43SpawnField(record, unsigned char*, 1) = flags;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level43SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level43SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Level43SpawnField(record, int*, 12) = var_v0;
                    Level43SpawnField(record, unsigned char*, 0xA) =
                        (unsigned char)((Level43Spawnrand() & 0xF) + 0x14);
                    Level43SpawnField(record, unsigned char*, 0xB) = Level43Spawnrand();
                    Level43SpawnField(record, unsigned char*, 0x10) = 0;
                    Level43SpawnField(record, short*, 0x18) = (short)((Level43Spawnrand() & 7) - 4);
                    Level43SpawnField(record, short*, 0x1A) =
                        (short)(-2 - (Level43Spawnrand() & 7));
                    Level43SpawnField(record, short*, 0x1C) =
                        (short)((Level43Spawnrand() & 0xF) - 8);
                    break;
                case 0x3C:
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level43SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    {
                        register int value __asm__("$3") = Level43SpawnField(modeSelector, int*, 8);
                        tailByte = value - 1;
                        MATCHING_KEEP2(tailByte, value);
                        if ((unsigned)tailByte < 7) {
                            tailByte = value << 5;
                            Level43SpawnField(record, unsigned char*, 2) = tailByte;
                            Level43SpawnField(record, unsigned short*, 28) = 0;
                            Level43SpawnField(record, unsigned char*, 14) = byte255;
                        } else
                            Level43SpawnField(record, unsigned char*, 14) = 0;
                    }
                    tailByte = 24;
                    Level43SpawnField(record, unsigned short*, 30) = 0;
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level43Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                    Level43SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level43SpawnField(record, unsigned char*, 12) = byte255;
                    Level43SpawnField(record, unsigned char*, 13) = byte255;
                    Level43SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x3D:
                    record = Level43Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 72;
                    Level43SpawnField(record, short*, 30) = 0;
                    Level43SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level43Spawnrand();
                    {
                        register int mask __asm__("$3") = -128;
                        MATCHING_KEEP2_CLOBBER(mask, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 11) = tailByte;
                        tailByte = (int)modeSelector & mask;
                        Level43SpawnField(record, unsigned char*, 12) = tailByte;
                        tailByte = (int)modeSelector >> 8;
                        tailByte &= mask;
                        commonByte9 = 46;
                        MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                        Level43SpawnField(record, unsigned char*, 13) = tailByte;
                        tailByte = 8;
                    initializeEZero:
                    }
                initializeZeroE:
                    Level43SpawnField(record, unsigned char*, 14) = 0;
                initializeF9:
                    Level43SpawnField(record, unsigned char*, 15) = commonByte9;
                initializeByte11:
                initializeTrailingBytes:
                    Level43SpawnField(record, unsigned char*, 17) = tailByte;
                    Level43SpawnField(record, unsigned char*, 16) = 0;
                    break;
                case 0x42: /* switch 1 */
                {
                    register int local128 __asm__("$9");
                    record = Level43Spawnfunc_80056434(0);
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level43Spawnrand() & 0xF);
                    Level43SpawnField(record, unsigned char*, 3) = 1;
                    Level43SpawnField(record, short*, 4) =
                        (short)((((int)Level43SpawnField(reference, int*, 0) >> 2) +
                                 (Level43Spawnrand() & 0xF)) -
                                8);
                    Level43SpawnField(record, short*, 6) =
                        (short)((((int)Level43SpawnField(reference, int*, 4) >> 2) +
                                 (Level43Spawnrand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Level43SpawnField(record, short*, 16) = 0;
                        Level43SpawnField(record, short*, 18) = 0;
                        Level43SpawnField(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Level43SpawnField(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Level43SpawnD_8006E344;
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
                        Level43SpawnField(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Level43SpawnField(Level43SpawnD_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Level43Spawnrand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Level43SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level43SpawnField(record, unsigned char*, 0xD) = 0;
                            Level43SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Level43SpawnField(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Level43SpawnField(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Level43SpawnField(record, unsigned char*, 13) = byte255;
                            Level43SpawnField(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Level43SpawnField(record, unsigned char*, 0xC) = 0;
                            Level43SpawnField(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Level43SpawnField(record, unsigned char*, 0xC) = 0;
                            Level43SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Level43SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level43SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            local128 = 128;
                            MATCHING_KEEP(local128);
                            Level43SpawnField(record, unsigned char*, 12) = byte255;
                            Level43SpawnField(record, unsigned char*, 13) = local128;
                        }
                            Level43SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            commonByte8 = 128;
                            MATCHING_KEEP(commonByte8);
                            Level43SpawnField(record, unsigned char*, 12) = 0;
                            Level43SpawnField(record, unsigned char*, 13) = commonByte8;
                        }
                        storeThirdColor:
                            Level43SpawnField(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Level43SpawnField(record, unsigned char*, 0xF) = 0x40;
                    break;
                }
                case 0x46: /* switch 1 */
                {
                    register int local128 __asm__("$9");
                    record = Level43Spawnfunc_80056434(1);
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level43Spawnrand() & 0xF);
                    Level43SpawnField(record, unsigned char*, 3) = 1;
                    frame.spB0 = 0;
                    frame.spB1 = Level43Spawnrand();
                    frame.spB2 = Level43Spawnrand();
                    Level43Spawnfunc_8004EA90(&frame.spB0, &frame.spB8, 0);
                    frame.spA0 = (int)modeSelector;
                    frame.spA4 = 0;
                    frame.spA8 = 0;
                    Level43SpawnTransformVectorByBasis(&frame.spB8, (unsigned char*)&frame.spA0,
                                                       (unsigned char*)&frame.spA0);
                    Level43SpawnField(record, unsigned short*, 4) =
                        (unsigned short)((int)Level43SpawnField(reference, int*, 0) >> 2);
                    Level43SpawnField(record, unsigned short*, 6) =
                        (unsigned short)((int)Level43SpawnField(reference, int*, 4) >> 2);
                    Level43SpawnField(record, unsigned short*, 8) =
                        (unsigned short)((int)Level43SpawnField(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.spA0;
                        register int other __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 4);

                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level43SpawnField(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.spA4;
                        other = Level43SpawnField(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level43SpawnField(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.spA8;
                        value = 2;
                        Level43SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level43SpawnField(record, unsigned char*, 16) = value;
                        value = 192;
                        Level43SpawnField(record, unsigned char*, 17) = value;
                        value = 80;
                        Level43SpawnField(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Level43SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$9", "memory");

                        local128 = 128;
                        MATCHING_KEEP(local128);
                        Level43SpawnField(record, unsigned char*, 18) = 0;
                        Level43SpawnField(record, unsigned char*, 20) = byte255;
                        Level43SpawnField(record, unsigned char*, 21) = byte255;
                        Level43SpawnField(record, unsigned char*, 22) = local128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Level43SpawnField(record, short*, 14) = value;
                    }
                    break;
                }
                case 0x47: /* switch 1 */
                    record = Level43Spawnfunc_80056434(1);
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level43Spawnrand() & 7);
                    Level43SpawnField(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Level43Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spD0 = temp_v0_4;
                    temp_v0_5 = (int)(((Level43Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spD4 = temp_v0_5;
                    temp_v0_6 = (int)(((Level43Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spD8 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Level43SpawnField(reference, int*, 0);
                        value = frame.spD0;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level43SpawnField(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level43SpawnField(reference, int*, 4);
                        value = frame.spD4;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level43SpawnField(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level43SpawnField(reference, int*, 8);
                        value = frame.spD8;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level43SpawnField(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.spD0;
                        register int value __asm__("$2") =
                            Level43SpawnField(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level43SpawnField(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.spD4;
                        value = Level43SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level43SpawnField(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.spD8;
                        other = Level43SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Level43SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level43SpawnField(record, unsigned char*, 16) = value;
                        Level43SpawnField(record, unsigned char*, 17) = value;
                        value = 96;
                        Level43SpawnField(record, unsigned char*, 18) = value;
                        Level43SpawnField(record, unsigned char*, 20) = byte255;
                        Level43SpawnField(record, unsigned char*, 21) = byte255;
                        Level43SpawnField(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Level43SpawnField(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Level43SpawnField(record, short*, 14) = other;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Level43Spawnfunc_80056434(0);
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level43Spawnrand() & 0x1F);
                    Level43SpawnField(record, unsigned char*, 3) = 1;
                    Level43SpawnPackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level43SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level43SpawnField(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level43SpawnField(record, unsigned short*, 8) = component;
                    }
                    Level43SpawnField(record, short*, 0x10) = (short)((Level43Spawnrand() & 2) - 1);
                    Level43SpawnField(record, short*, 0x12) = (short)((Level43Spawnrand() & 2) - 1);
                    Level43SpawnField(record, short*, 0x14) = (short)-(Level43Spawnrand() & 1);
                    tailByte = Level43Spawnrand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level43SpawnField(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Level43Spawnrand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Level43SpawnField(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Level43SpawnField(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Level43SpawnField(record, unsigned char*, 13) = component;
                    }
                    Level43SpawnField(record, unsigned char*, 0xE) =
                        (unsigned char)((Level43Spawnrand() & 0x3F) + 0x40);
                    Level43SpawnField(record, unsigned char*, 0xF) = 0x40;
                    Level43SpawnField(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                {
                    register int local128 __asm__("$8");
                    record = Level43Spawnfunc_80056434(1);
                    Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level43SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level43Spawnrand() & 0xF);
                    Level43SpawnField(record, unsigned char*, 3) = 1;
                    Level43SpawnPackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.spD0;
                        MATCHING_KEEP(vector);
                        Level43SpawnAddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Level43Spawnrand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&frame.spD0;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            frame.spD0 = component;
                        }

                        {
                            register int random __asm__("$2") = Level43Spawnrand();
                            register int component __asm__("$3") = frame.spD4;

                            random &= 0x3F;

                            component -= 0x20;

                            component += random;
                            frame.spD4 = component;
                        }

                        {
                            register int random __asm__("$2") = Level43Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;

                            component = frame.spD8;

                            random &= 0x7F;

                            component -= 0x40;

                            component += random;
                            frame.spD8 = component;
                            Level43SpawnPackVectorShiftRight2(destination, source);
                        }
                    }
                    Level43SpawnField(record, unsigned char*, 0x17) = 2;
                    tailByte = Level43Spawnrand();
                    tailByte |= 192;

                    Level43SpawnField(record, unsigned char*, 16) = tailByte;
                    Level43SpawnField(record, unsigned char*, 0x11) =
                        (unsigned char)((Level43Spawnrand() & 0x3F) - 0x60);
                    Level43SpawnField(record, unsigned char*, 0x12) = 0;
                    tailByte = Level43Spawnrand();
                    tailByte |= 224;

                    Level43SpawnField(record, unsigned char*, 20) = tailByte;
                    tailByte = Level43Spawnrand();
                    tailByte |= 224;

                    local128 = 128;
                    Level43SpawnField(record, unsigned char*, 21) = tailByte;
                    {

                        Level43SpawnField(record, unsigned char*, 0x16) = local128;
                    }
                    Level43SpawnField(record, unsigned char*, 0x13) = 0x50;
                    break;
                }
                case 0x55:
                    record = Level43Spawnfunc_80056434(1);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level43SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level43SpawnField(record, unsigned char*, 2) = 0;
                        Level43SpawnField(record, unsigned char*, 3) = tailByte;
                        Level43SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level43SpawnPackVectorShiftRight2(record + 0xA, modeSelector);
                    commonByte9 = 128;
                    MATCHING_KEEP_CLOBBER(commonByte9, "memory");
                    {
                        register int first __asm__("$3") =
                            Level43SpawnField(record, unsigned short*, 10);
                        register int x __asm__("$4") =
                            Level43SpawnField(record, unsigned short*, 4);
                        register int second __asm__("$2");
                        register int z __asm__("$5");
                        __asm__(""
                                : "=r"(first), "=r"(x)
                                : "0"(first), "1"(x)
                                : "$2", "$5", "memory");
                        second = 80;
                        Level43SpawnField(record, unsigned char*, 19) = second;
                        second = Level43SpawnField(record, unsigned short*, 12);
                        z = Level43SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP4_CLOBBER(first, x, second, z, "memory");
                        first += x;
                        x = Level43SpawnField(record, unsigned short*, 6);
                        __asm__ volatile("" ::: "$8", "memory");
                        commonByte8 = 128;
                        Level43SpawnField(record, unsigned char*, 23) = 0;
                        Level43SpawnField(record, unsigned char*, 16) = byte255;
                        Level43SpawnField(record, unsigned char*, 17) = byte255;
                        Level43SpawnField(record, unsigned char*, 18) = 0;
                        Level43SpawnField(record, unsigned char*, 20) = commonByte9;
                        Level43SpawnField(record, unsigned char*, 21) = commonByte8;
                        Level43SpawnField(record, unsigned char*, 22) = 0;
                        MATCHING_KEEP4_CLOBBER(first, x, second, z, "memory");
                        Level43SpawnField(record, unsigned short*, 10) = first;
                        first = Level43SpawnField(record, unsigned short*, 14);
                        MATCHING_KEEP4_CLOBBER(first, x, second, z, "memory");
                        second += x;
                        first += z;
                        Level43SpawnField(record, unsigned short*, 12) = second;
                        tailHalf3 = first;
                    }
                initializeHalfE:
                    Level43SpawnField(record, unsigned short*, 14) = tailHalf3;
                    break;
            }
            MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
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

#undef Level43SpawnField

#undef Level43SpawnHigh
