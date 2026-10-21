#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Level38Spawnfunc_8001830C(void*, void*, int, int, int) __asm__("func_8001830C");
int Level38SpawnSubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Level38SpawnPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern int Level38SpawnD_80071908 __asm__("D_80071908");
typedef struct {
    unsigned char raw[88];
} Level38SpawnRawRecord;
extern Level38SpawnRawRecord* Level38SpawnRecords __asm__("D_8006C550");
extern int Level38SpawnD_8006D07C __asm__("D_8006D07C");
extern int Level38SpawnD_8006D080 __asm__("D_8006D080");
extern int Level38SpawnD_8006D084 __asm__("D_8006D084");
extern int Level38SpawnD_80071934 __asm__("D_80071934");
extern unsigned char Level38SpawnPlayerE __asm__("D_80070328 + 0xE");
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level38SpawnHigh(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Level38SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level38SpawnColor2[] __asm__("D_80066BAC");
#define Level38SpawnField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level38Spawnfunc_8004EA90(void*, void*, int) __asm__("func_8004EA90");
int Level38SpawnTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level38SpawnShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Level38SpawnCopyVector(void*, void*) __asm__("func_8004F178");
int Level38SpawnAddVector(void*, void*, void*) __asm__("func_8004F194");
int Level38SpawnMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Level38SpawnPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Level38Spawnfunc_80056434(int) __asm__("func_80056434");
int Level38SpawnRandBetween(int, int) __asm__("func_8003636C");
int Level38Spawnrand(void) __asm__("rand");
extern unsigned char Level38SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level38SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level38SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level38SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level38SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level38SpawnD_80070328[] __asm__("D_80070328");
extern int Level38SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original USA Rev0 level38 instructions
 * and dispatch: build/sibling4149.func_level_38_800869A8.json.
 * Raw units, helper contracts and cadence remain unresolved. */
void* func_level_38_800869A8(int entryCount, int kind, void* input, void* mode) {
    struct {
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
        unsigned char sp98, sp99, sp9A, pad9B;
        int sp9C;
        int spA0;
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
        int* volatile spD8;
        int spDC;
        int spE0;
        int spE4;
        volatile int spE8;
        int spEC;
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
    int byte128;
    register int byte255 __asm__("$23");
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    int var_v0_3;
    register int tailByte __asm__("$2");
    register int commonByte8 __asm__("$8");
    register int commonByte9 __asm__("$9");
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
    frame.spC8 = entryCount;
    frame.spD0 = 0;
    if (entryCount > 0) {
        byte128 = 128;
        MATCHING_KEEP(byte128);
        {
            register int* vectorBase __asm__("$8") = &frame.sp28;
            MATCHING_KEEP_CLOBBER(vectorBase, "$23");
            byte255 = 255;
            frame.spD8 = vectorBase;
        }

        frame.spE8 = 0;
        do {
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$9");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                        Level38SpawnField(record, unsigned char*, 3) = one;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level38SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level38SpawnField(record, short*, 0x1E) = 0;
                    Level38SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level38Spawnrand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$3", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte8 = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Level38SpawnField(record, unsigned char*, 0xC) = byte128;
                        Level38SpawnField(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                        Level38SpawnField(record, unsigned char*, 0xE) = byte128;
                    }

                    MATCHING_KEEP_VOLATILE_CLOBBER(commonByte8, "memory");
                    Level38SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x1: /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                        Level38SpawnField(record, unsigned char*, 3) = tailByte;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level38SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level38SpawnField(record, short*, 0x1E) = 0;
                    Level38SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level38Spawnrand();
                    Level38SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Level38SpawnField(record, unsigned char*, 0xC) = tailByte;
                    Level38SpawnField(record, unsigned char*, 0xD) = tailByte;
                    Level38SpawnField(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    goto initializeF9;
                case 0x9: /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                initializeMode0:
                    {
                        register void* destination __asm__("$4") = &frame.sp18;
                        register void* source __asm__("$5") = Level38SpawnD_80070328;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                        Level38SpawnField(record, unsigned char*, 3) = tailByte;
                        Level38SpawnCopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp18;
                            MATCHING_KEEP2(random, component);
                            random &= 126;
                            component -= 63;
                            component += random;
                            frame.sp18 = component;
                        }
                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp1C;
                            destination = record + 4;
                            source = &frame.sp18;
                            MATCHING_KEEP4(random, component, destination, source);
                            random &= 126;
                            component -= 63;
                            component += random;
                            frame.sp1C = component;
                            Level38SpawnPackVectorShiftRight2(destination, source);
                        }
                        {
                            register unsigned char* player8 __asm__("$8");
                            destination = &frame.sp18;
                            __asm__("" : "=r"(destination) : "0"(destination) : "$8", "memory");
                            player8 = Level38SpawnD_80070328;
                            MATCHING_KEEP2_CLOBBER(player8, destination, "memory");
                            Level38SpawnCopyVector(destination, player8 + 152);
                        }
                        Level38SpawnShiftVectorRightTowardZero(&frame.sp18, 6);
                        Level38SpawnPackVectorShiftRight2(record + 24, &frame.sp18);
                    }
                    Level38SpawnField(record, short*, 0x1E) = 0;
                    Level38SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level38Spawnrand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$4", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte9 = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Level38SpawnField(record, unsigned char*, 0xC) = byte128;
                        Level38SpawnField(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$4", "memory");
                        Level38SpawnField(record, unsigned char*, 0xE) = byte128;
                    }

                    goto initializeF9;
                case 0xA: /* switch 1 */
                    record = Level38Spawnfunc_80056434(3);
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Level38SpawnD_80070328;
                        tailByte = Level38Spawnrand();
                        destination = record + 4;
                        source = Level38SpawnD_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Level38SpawnField(record, unsigned char*, 3) = tailByte;
                        Level38SpawnPackVectorShiftRight2(destination, source);
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
                        Level38SpawnField(record, unsigned char*, 10) = value;
                        value = 15;
                        Level38SpawnField(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.spC8;
                        iteration8 = frame.spD0;
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = frame.spE8;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Level38SpawnD_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Level38SpawnHigh(dividend, factor);
                        Level38SpawnField(record, unsigned char*, 12) = value;
                        value = *(Level38SpawnColor1 + 1 + count);
                        dividend >>= 31;
                        Level38SpawnField(record, unsigned char*, 13) = value;
                        color = *(Level38SpawnColor2 + 2 + count);
                        value = 44;
                        Level38SpawnField(record, unsigned char*, 15) = value;
                        value = 4;
                        Level38SpawnField(record, unsigned char*, 17) = value;
                        Level38SpawnField(record, unsigned char*, 16) = 0;
                        Level38SpawnField(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Level38SpawnField(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register int iteration __asm__("$8") = frame.spD0;
                        register void* vector __asm__("$6") = frame.spD8;
                        register int base __asm__("$2");
                        register void* table __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(vector)
                                : "0"(destination), "1"(iteration), "2"(vector)
                                : "$2", "$5", "memory");
                        base = (int)Level38SpawnD_80066A48;
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        table = (void*)(iteration * 12);
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "memory");
                        base = 1;
                        Level38SpawnField(record, unsigned char*, 3) = base;
                        base = 4;
                        Level38SpawnField(record, unsigned char*, 17) = base;
                        Level38SpawnTransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Level38SpawnField(reference, short*, 54);
                            register int expected __asm__("$9");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Level38SpawnMultiplyVectorGpfSf0(frame.spD8, frame.spD8, 3);
                    }
                    Level38SpawnAddVector(frame.spD8, frame.spD8, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp28;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp28 = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp2C;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp2C = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp30;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp30 = component;
                        }
                    }
                    if (modeSelector == (unsigned char*)6) {
                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp28;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp28 = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp2C;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp2C = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp30;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp30 = component;
                        }
                    }
                    if (Level38SpawnField(reference, short*, 0x36) == 0xB6) {
                        frame.sp30 += 0x200;
                    }
                    Level38SpawnPackVectorShiftRight2(record + 4, frame.spD8);
                    Level38SpawnField(record, int*, 0xC) =
                        (int)*(int*)(Level38SpawnD_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Level38SpawnField(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Level38Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level38Spawnrand() & 7) + 0x20;
                    }
                    Level38SpawnField(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Level38Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int iteration __asm__("$9") = frame.spD0;
                        register int base __asm__("$3");
                        register void* source __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(tailByte)
                                : "0"(destination), "1"(iteration), "2"(tailByte)
                                : "$3", "$5", "memory");
                        base = (int)Level38SpawnD_80066A48;
                        Level38SpawnField(record, unsigned char*, 11) = tailByte;
                        Level38SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        source = (void*)(iteration * 12);
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level38SpawnField(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Level38SpawnField(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level38Spawnrand() & 7));
                    Level38SpawnField(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Level38SpawnField(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level38Spawnrand() & 7));
                    Level38SpawnField(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Level38SpawnField(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level38Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                        Level38SpawnField(record, unsigned char*, 3) = tailByte;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level38SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Level38SpawnField(record, short*, 0x1E) = 0;
                    Level38SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level38Spawnrand();
                    commonByte8 = 46;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$3", "memory");
                    Level38SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level38SpawnField(record, unsigned char*, 12) = byte255;
                    Level38SpawnField(record, unsigned char*, 13) = byte255;
                    Level38SpawnField(record, unsigned char*, 14) = 0;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$4", "memory");
                    Level38SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x14:
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                        Level38SpawnField(record, unsigned char*, 3) = tailByte;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level38SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 48;
                    goto initializeAddedCase;
                case 0x1E: /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$2");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;

                        Level38SpawnField(record, unsigned char*, 3) = one;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int value4 __asm__("$4") = 10;
                        register int value5 __asm__("$5") = 24;
                        MATCHING_KEEP2_CLOBBER(value4, value5, "memory");
                        commonByte8 = 46;
                        tailByte = 4;
                        Level38SpawnField(record, volatile void**, 24) = modeSelector;
                        Level38SpawnField(record, volatile unsigned char*, 11) = 0;
                        Level38SpawnField(record, volatile unsigned char*, 12) = byte128;
                        Level38SpawnField(record, volatile unsigned char*, 13) = byte128;
                        Level38SpawnField(record, volatile unsigned char*, 14) = byte128;
                        Level38SpawnField(record, unsigned char*, 15) = commonByte8;
                        Level38SpawnField(record, unsigned char*, 17) = tailByte;
                        Level38SpawnField(record, unsigned char*, 16) = 0;
                        tailByte = Level38SpawnRandBetween(value4, value5);
                        Level38SpawnField(record, unsigned char*, 10) = tailByte;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                    }
                    break;

                case 0x21: /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) = 0;
                    Level38SpawnField(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp48;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Level38SpawnD_80070328 + 0x98;
                            Level38SpawnCopyVector(destination, temp_s1);
                        }
                        Level38SpawnShiftVectorRightTowardZero((void*)scratch16, 6);
                        Level38SpawnCopyVector(&frame.sp38, temp_s1 - 0x98);
                        frame.sp40 -= 0x164;
                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.sp38;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp38 = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$19");
                            scratch19 = 48;
                            component = frame.sp3C;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp3C = component;
                        }

                        goto setDestination;
                    } else {
                        register int one __asm__("$9") = 1;
                        register int two __asm__("$2");
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Level38SpawnD_80070328 + 0x30;
                            frame.sp38 = 0x164;
                            frame.sp3C = 0;
                            frame.sp40 = 0;
                            Level38SpawnTransformVectorByBasis(temp_s1_2, &frame.sp38, &frame.sp38);
                            Level38SpawnAddVector(&frame.sp38, &frame.sp38, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp48 = -(Level38Spawnrand() & 7);
                            {
                                register int random __asm__("$2") = Level38Spawnrand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") = temp_s1_2;
                                register void* vector __asm__("$5") = &frame.sp48;
                                register int iteration8 __asm__("$8") = frame.spD0;
                                register int angle __asm__("$7");
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP4_CLOBBER(destination, vector, angle, output,
                                                       "memory");
                                MATCHING_KEEP(iteration8);
                                random &= 15;
                                angle = iteration8 << 6;
                                component = *(unsigned short*)(Level38SpawnD_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp4C = component;
                                random = *(unsigned short*)(Level38SpawnD_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp50 = random;
                                Level38SpawnTransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else {
                            two = 2;
                            MATCHING_KEEP(two);
                            scratch16 = 5;
                            if (modeSelector == (unsigned char*)two) {
                                {
                                    register int iteration8 __asm__("$9") = frame.spD0;
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
                                    register int iteration9 __asm__("$8") = frame.spD0;
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
                    Level38SpawnCopyVector(&frame.sp38, Level38SpawnD_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Level38SpawnD_80065920;
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
                        other = frame.sp38;
                        value >>= scratch16;
                        other += value;
                        value = (int)Level38SpawnD_800658A0;
                        second += value;
                        value = frame.sp40;
                        frame.sp38 = other;
                        other = *(short*)second;
                        value -= 356;
                        frame.sp40 = value;
                        value = frame.sp3C;
                        other >>= scratch16;
                        value += other;
                        frame.sp3C = value;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        value = *first;
                        other = scratch16 + 1;
                        value >>= other;
                        frame.sp48 = value;
                        value = *(short*)second;
                        frame.sp50 = 0;
                        value >>= other;
                        frame.sp4C = value;
                    }
                setDestination:
                    var_a0 = record + 4;
                finishMode:
                    Level38SpawnPackVectorShiftRight2(var_a0, &frame.sp38);
                    Level38SpawnPackVectorShiftRight2(record + 0x18, &frame.sp48);
                    Level38SpawnField(record, short*, 0x1E) = 0;
                    Level38SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level38Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Level38SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level38SpawnField(record, unsigned char*, 0xC) = scratch19;
                    Level38SpawnField(record, unsigned char*, 0xD) = scratch19;
                    Level38SpawnField(record, unsigned char*, 0xE) = scratch19;
                    goto initializeF9;
                case 0x2C: {
                    register void* vector17 __asm__("$17");
                    register unsigned char* player16 __asm__("$16");
                    register void* copy16 __asm__("$16");
                    register void* arg4 __asm__("$4") = Level38SpawnD_80070328 + 0x30;
                    register void* arg5 __asm__("$5") = reference;
                    register void* arg6 __asm__("$6");
                    register int value2 __asm__("$2");
                    __asm__("" : "=r"(arg4), "=r"(arg5) : "0"(arg4), "1"(arg5) : "$17", "memory");
                    vector17 = &frame.sp58;
                    MATCHING_KEEP3(arg4, arg5, vector17);
                    Level38SpawnTransformVectorByBasis(arg4, arg5, vector17);
                    arg4 = vector17;
                    __asm__("" : "=r"(arg4) : "0"(arg4) : "$6", "memory");
                    arg6 = Level38SpawnD_80070328;
                    MATCHING_KEEP_CLOBBER(arg6, "memory");
                    arg5 = vector17;
                    Level38SpawnAddVector(arg4, arg5, arg6);
                    if (Level38Spawnfunc_8001830C(Level38SpawnD_80070328, vector17, 2, 0, 0) != 0)
                        break;
                    record = Level38Spawnfunc_80056434(2);
                    arg4 = record + 4;
                    arg5 = vector17;
                    value2 = 1;
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 3) = value2;
                    Level38SpawnPackVectorShiftRight2(arg4, arg5);
                    Level38SpawnPackVectorShiftRight2(record + 24, vector17);
                    value2 = Level38SpawnField(Level38SpawnD_80070328, int*, 0x8C);
                    value2 >>= 9;
                    Level38SpawnField(record, unsigned short*, 18) = value2;
                    value2 = Level38SpawnField(Level38SpawnD_80070328, int*, 0x90);
                    value2 >>= 9;
                    Level38SpawnField(record, unsigned short*, 20) = value2;
                    value2 = Level38Spawnrand();
                    value2 &= 3;
                    MATCHING_KEEP(value2);
                    value2 += 4;
                    commonByte8 = 46;
                    Level38SpawnField(record, volatile unsigned short*, 22) = value2;
                    value2 = 2;
                    Level38SpawnField(record, volatile unsigned char*, 11) = 0;
                    Level38SpawnField(record, volatile unsigned char*, 12) = byte128;
                    Level38SpawnField(record, volatile unsigned char*, 13) = byte128;
                    Level38SpawnField(record, volatile unsigned char*, 14) = byte128;
                    Level38SpawnField(record, volatile unsigned char*, 15) = commonByte8;
                    Level38SpawnField(record, volatile unsigned char*, 17) = value2;
                    Level38SpawnField(record, unsigned char*, 16) = 0;
                    value2 = Level38Spawnrand();
                    value2 &= 7;
                    MATCHING_KEEP(value2);
                    value2 += 6;
                    Level38SpawnField(record, unsigned char*, 10) = value2;
                    value2 = Level38Spawnrand();
                    Level38SpawnField(record, unsigned char*, 28) = value2;
                    value2 = Level38Spawnrand();
                    value2 &= 31;
                    {
                        register int value3 __asm__("$3") = 16;
                        value3 -= value2;
                        Level38SpawnField(record, unsigned char*, 29) = value3;
                    }
                    value2 = Level38Spawnrand();
                    copy16 = &frame.sp68;
                    arg4 = copy16;
                    arg5 = vector17;
                    MATCHING_KEEP4_CLOBBER(copy16, arg4, arg5, value2, "memory");
                    value2 &= 31;
                    MATCHING_KEEP(value2);
                    value2 += 64;
                    Level38SpawnField(record, unsigned char*, 2) = value2;
                    Level38SpawnCopyVector(arg4, arg5);
                    arg4 = vector17;
                    arg5 = copy16;
                    value2 = frame.sp70;
                    value2 += 3072;
                    frame.sp70 = value2;
                    value2 = Level38Spawnfunc_8001830C(arg4, arg5, 2, 0, 0);
                    if (value2) {
                        value2 = Level38SpawnD_80071908;
                        value2 >>= 2;
                        Level38SpawnField(record, unsigned short*, 30) = value2;
                        value2 = Level38SpawnD_80071934;
                        if (value2 == 0)
                            break;
                        value2 = 3;
                        Level38SpawnField(record, unsigned char*, 17) = value2;
                        break;
                    }
                    value2 = frame.sp70;
                    value2 >>= 2;
                    Level38SpawnField(record, unsigned short*, 30) = value2;
                } break;
                case 0x37:
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                        Level38SpawnField(record, unsigned char*, 3) = tailByte;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level38SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 64;
                initializeAddedCase:
                    Level38SpawnField(record, unsigned char*, 0xA) = tailByte;
                    tailByte = Level38Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Level38SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level38SpawnField(record, unsigned char*, 0xC) = byte255;
                    Level38SpawnField(record, unsigned char*, 0xD) = byte255;
                    Level38SpawnField(record, unsigned char*, 0xE) = 0;
                initializeF9:
                    Level38SpawnField(record, unsigned char*, 15) = commonByte9;
                initializeTrailingBytes:
                    Level38SpawnField(record, unsigned char*, 17) = tailByte;
                    Level38SpawnField(record, unsigned char*, 16) = 0;
                    break;
                case 0x38:
                    record = Level38Spawnfunc_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) = 0;
                    Level38SpawnField(record, unsigned char*, 3) = tailByte;
                    Level38SpawnField(record, unsigned short*, 4) =
                        Level38SpawnField(reference, unsigned short*, 4);
                    Level38SpawnField(record, unsigned short*, 6) =
                        Level38SpawnField(reference, unsigned short*, 6);
                    Level38SpawnField(record, unsigned short*, 8) =
                        Level38SpawnField(reference, unsigned short*, 8);
                    Level38SpawnField(record, int*, 24) = Level38SpawnField(reference, int*, 24);
                    Level38SpawnField(record, int*, 28) = Level38SpawnField(reference, int*, 28);
                    tailByte = Level38SpawnField(reference, unsigned char*, 10);
                    MATCHING_KEEP(tailByte);
                    Level38SpawnField(record, unsigned char*, 10) = tailByte;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register unsigned int sourceByte __asm__("$2") =
                            Level38SpawnField(reference, unsigned char*, 11);
                        MATCHING_KEEP_CLOBBER(sourceByte, "memory");
                        commonByte8 = 46;
                        Level38SpawnField(record, volatile unsigned char*, 12) = 0;
                        Level38SpawnField(record, volatile unsigned char*, 13) = 0;
                        Level38SpawnField(record, volatile unsigned char*, 14) = 0;
                        Level38SpawnField(record, volatile unsigned char*, 15) = commonByte8;
                        Level38SpawnField(record, volatile unsigned char*, 17) = 0;
                        Level38SpawnField(record, volatile unsigned char*, 16) = 0;
                        Level38SpawnField(record, unsigned char*, 11) = sourceByte;
                    }
                    break;
                case 0x3B: /* switch 1 */
                    record = Level38Spawnfunc_80056434(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Level38SpawnField(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Level38SpawnField(record, unsigned char*, 3) = value;
                        value = 16;
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Level38SpawnField(record, unsigned char*, 1) = flags;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3") =
                            Level38SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level38SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3") =
                            Level38SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level38SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Level38SpawnField(record, int*, 12) = var_v0;
                    Level38SpawnField(record, unsigned char*, 0xA) =
                        (unsigned char)((Level38Spawnrand() & 0xF) + 0x14);
                    Level38SpawnField(record, unsigned char*, 0xB) = Level38Spawnrand();
                    Level38SpawnField(record, unsigned char*, 0x10) = 0;
                    Level38SpawnField(record, short*, 0x18) = (short)((Level38Spawnrand() & 7) - 4);
                    Level38SpawnField(record, short*, 0x1A) =
                        (short)(-2 - (Level38Spawnrand() & 7));
                    Level38SpawnField(record, short*, 0x1C) =
                        (short)((Level38Spawnrand() & 0xF) - 8);
                    break;
                case 0x3E: /* switch 1 */
                    record = Level38Spawnfunc_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$2");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level38SpawnField(record, unsigned char*, 3) = one;
                        Level38SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int value2 __asm__("$2") =
                            Level38SpawnField(modeSelector, int*, 0);
                        register int value3 __asm__("$3");
                        register void* arg4 __asm__("$4");
                        register unsigned char* arg5 __asm__("$5");
                        register int value6 __asm__("$6");
                        Level38SpawnField(record, int*, 24) = value2;
                        value2 = Level38SpawnField(modeSelector, unsigned short*, 4);
                        arg5 = Level38SpawnField(record, unsigned char**, 24);
                        Level38SpawnField(record, unsigned short*, 28) = value2;
                        value2 = (value2 << 16) >> 16;
                        value3 = Level38SpawnField(arg5, short*, 0);
                        value6 = value2 + 1;
                        arg4 = &frame.sp78;
                        if (value6 >= value3)
                            value6 = value3 - 1;
                        value2 = Level38SpawnField(arg5, int*, 12);
                        value6 <<= 4;
                        arg5 = (unsigned char*)(value2 + value6);
                        value6 -= 16;
                        Level38SpawnSubtractVector(arg4, arg5, (void*)(value2 + value6));
                        value2 = Level38SpawnPlanarHeadingLookup(frame.sp78, frame.sp7C, 0);
                        {
                            register int value4 __asm__("$4") = 20;
                            register int value5 __asm__("$5") = 34;

                            MATCHING_KEEP3_CLOBBER(value4, value5, value2, "memory");
                            commonByte9 = 46;
                            Level38SpawnField(record, volatile unsigned short*, 30) = value2;
                            value2 = 4;
                            Level38SpawnField(record, volatile unsigned char*, 11) = 0;
                            Level38SpawnField(record, volatile unsigned char*, 12) = byte128;
                            Level38SpawnField(record, volatile unsigned char*, 13) = byte128;
                            Level38SpawnField(record, volatile unsigned char*, 14) = byte128;
                            Level38SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                        initializeAddedAge:
                            Level38SpawnField(record, volatile unsigned char*, 17) = value2;
                            Level38SpawnField(record, unsigned char*, 16) = 0;
                            value2 = Level38SpawnRandBetween(value4, value5);
                        }
                        Level38SpawnField(record, unsigned char*, 10) = value2;
                        Level38SpawnField(record, unsigned char*, 2) = 0;
                    }
                    break;
                case 0x42: /* switch 1 */
                    record = Level38Spawnfunc_80056434(0);
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level38Spawnrand() & 0xF);
                    Level38SpawnField(record, unsigned char*, 3) = 1;
                    Level38SpawnField(record, short*, 4) =
                        (short)((((int)Level38SpawnField(reference, int*, 0) >> 2) +
                                 (Level38Spawnrand() & 0xF)) -
                                8);
                    Level38SpawnField(record, short*, 6) =
                        (short)((((int)Level38SpawnField(reference, int*, 4) >> 2) +
                                 (Level38Spawnrand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3") =
                            Level38SpawnField(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Level38SpawnField(record, short*, 16) = 0;
                        Level38SpawnField(record, short*, 18) = 0;
                        Level38SpawnField(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Level38SpawnField(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Level38SpawnD_8006E344;
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
                        Level38SpawnField(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Level38SpawnField(Level38SpawnD_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Level38Spawnrand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Level38SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level38SpawnField(record, unsigned char*, 0xD) = 0;
                            Level38SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Level38SpawnField(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Level38SpawnField(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Level38SpawnField(record, unsigned char*, 13) = byte255;
                            Level38SpawnField(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Level38SpawnField(record, unsigned char*, 0xC) = 0;
                            Level38SpawnField(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Level38SpawnField(record, unsigned char*, 0xC) = 0;
                            Level38SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Level38SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level38SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            MATCHING_KEEP(byte128);
                            Level38SpawnField(record, unsigned char*, 12) = byte255;
                            Level38SpawnField(record, unsigned char*, 13) = byte128;
                        }
                            Level38SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            MATCHING_KEEP(byte128);
                            Level38SpawnField(record, unsigned char*, 12) = 0;
                            Level38SpawnField(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Level38SpawnField(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Level38SpawnField(record, unsigned char*, 0xF) = 0x40;
                    break;
                case 0x46: /* switch 1 */
                    record = Level38Spawnfunc_80056434(1);
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level38Spawnrand() & 0xF);
                    Level38SpawnField(record, unsigned char*, 3) = 1;
                    frame.sp98 = 0;
                    frame.sp99 = Level38Spawnrand();
                    frame.sp9A = Level38Spawnrand();
                    Level38Spawnfunc_8004EA90(&frame.sp98, &frame.spA0, 0);
                    frame.sp88 = (int)modeSelector;
                    frame.sp8C = 0;
                    frame.sp90 = 0;
                    Level38SpawnTransformVectorByBasis(&frame.spA0, (unsigned char*)&frame.sp88,
                                                       (unsigned char*)&frame.sp88);
                    Level38SpawnField(record, unsigned short*, 4) =
                        (unsigned short)((int)Level38SpawnField(reference, int*, 0) >> 2);
                    Level38SpawnField(record, unsigned short*, 6) =
                        (unsigned short)((int)Level38SpawnField(reference, int*, 4) >> 2);
                    Level38SpawnField(record, unsigned short*, 8) =
                        (unsigned short)((int)Level38SpawnField(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.sp88;
                        register int other __asm__("$3") =
                            Level38SpawnField(record, unsigned short*, 4);

                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level38SpawnField(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.sp8C;
                        other = Level38SpawnField(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level38SpawnField(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.sp90;
                        value = 2;
                        Level38SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level38SpawnField(record, unsigned char*, 16) = value;
                        value = 192;
                        Level38SpawnField(record, unsigned char*, 17) = value;
                        value = 80;
                        Level38SpawnField(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Level38SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");

                        MATCHING_KEEP(byte128);
                        Level38SpawnField(record, unsigned char*, 18) = 0;
                        Level38SpawnField(record, unsigned char*, 20) = byte255;
                        Level38SpawnField(record, unsigned char*, 21) = byte255;
                        Level38SpawnField(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Level38SpawnField(record, short*, 14) = value;
                    }
                    break;
                case 0x47: /* switch 1 */
                    record = Level38Spawnfunc_80056434(1);
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level38Spawnrand() & 7);
                    Level38SpawnField(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Level38Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spB8 = temp_v0_4;
                    temp_v0_5 = (int)(((Level38Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spBC = temp_v0_5;
                    temp_v0_6 = (int)(((Level38Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spC0 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Level38SpawnField(reference, int*, 0);
                        value = frame.spB8;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level38SpawnField(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level38SpawnField(reference, int*, 4);
                        value = frame.spBC;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level38SpawnField(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level38SpawnField(reference, int*, 8);
                        value = frame.spC0;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level38SpawnField(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.spB8;
                        register int value __asm__("$2") =
                            Level38SpawnField(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level38SpawnField(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.spBC;
                        value = Level38SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level38SpawnField(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.spC0;
                        other = Level38SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Level38SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level38SpawnField(record, unsigned char*, 16) = value;
                        Level38SpawnField(record, unsigned char*, 17) = value;
                        value = 96;
                        Level38SpawnField(record, unsigned char*, 18) = value;
                        Level38SpawnField(record, unsigned char*, 20) = byte255;
                        Level38SpawnField(record, unsigned char*, 21) = byte255;
                        Level38SpawnField(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Level38SpawnField(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Level38SpawnField(record, short*, 14) = other;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Level38Spawnfunc_80056434(0);
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level38Spawnrand() & 0x1F);
                    Level38SpawnField(record, unsigned char*, 3) = 1;
                    Level38SpawnPackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3") =
                            Level38SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level38SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3") =
                            Level38SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level38SpawnField(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3") =
                            Level38SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level38SpawnField(record, unsigned short*, 8) = component;
                    }
                    Level38SpawnField(record, short*, 0x10) = (short)((Level38Spawnrand() & 2) - 1);
                    Level38SpawnField(record, short*, 0x12) = (short)((Level38Spawnrand() & 2) - 1);
                    Level38SpawnField(record, short*, 0x14) = (short)-(Level38Spawnrand() & 1);
                    tailByte = Level38Spawnrand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level38SpawnField(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Level38Spawnrand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Level38SpawnField(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Level38SpawnField(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Level38SpawnField(record, unsigned char*, 13) = component;
                    }
                    Level38SpawnField(record, unsigned char*, 0xE) =
                        (unsigned char)((Level38Spawnrand() & 0x3F) + 0x40);
                    Level38SpawnField(record, unsigned char*, 0xF) = 0x40;
                    Level38SpawnField(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                    record = Level38Spawnfunc_80056434(1);
                    Level38SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level38SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level38Spawnrand() & 0xF);
                    Level38SpawnField(record, unsigned char*, 3) = 1;
                    Level38SpawnPackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.spB8;
                        MATCHING_KEEP(vector);
                        Level38SpawnAddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&frame.spB8;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            frame.spB8 = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3") = frame.spBC;

                            random &= 0x3F;

                            component -= 0x20;

                            component += random;
                            frame.spBC = component;
                        }

                        {
                            register int random __asm__("$2") = Level38Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;

                            component = frame.spC0;

                            random &= 0x7F;

                            component -= 0x40;

                            component += random;
                            frame.spC0 = component;
                            Level38SpawnPackVectorShiftRight2(destination, source);
                        }
                    }
                    Level38SpawnField(record, unsigned char*, 0x17) = 2;
                    tailByte = Level38Spawnrand();
                    tailByte |= 192;

                    Level38SpawnField(record, unsigned char*, 16) = tailByte;
                    Level38SpawnField(record, unsigned char*, 0x11) =
                        (unsigned char)((Level38Spawnrand() & 0x3F) - 0x60);
                    Level38SpawnField(record, unsigned char*, 0x12) = 0;
                    tailByte = Level38Spawnrand();
                    tailByte |= 224;

                    Level38SpawnField(record, unsigned char*, 20) = tailByte;
                    tailByte = Level38Spawnrand();
                    tailByte |= 224;

                    Level38SpawnField(record, unsigned char*, 21) = tailByte;
                    {

                        Level38SpawnField(record, unsigned char*, 0x16) = byte128;
                    }
                    Level38SpawnField(record, unsigned char*, 0x13) = 0x50;
                    break;
            }
            {
                register int stride8 __asm__("$9") = frame.spE8;
                register int iteration9 __asm__("$8") = frame.spD0;
                MATCHING_KEEP2(stride8, iteration9);
                stride8 += 4;
                frame.spE8 = stride8;
                stride8 = frame.spC8;
                MATCHING_KEEP2(stride8, iteration9);
                iteration9 += 1;
                var_v0 = iteration9 < stride8;
                __asm__ volatile(""
                                 : "=r"(var_v0), "=r"(iteration9)
                                 : "0"(var_v0), "1"(iteration9)
                                 : "$3", "memory");
                frame.spD0 = iteration9;
            }
        } while (var_v0);
    }
    return record;
}

#undef Level38SpawnField

#undef Level38SpawnHigh
