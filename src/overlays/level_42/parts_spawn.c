#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Level42SpawnQueryWorldSegmentWithOptions(void*, void*, int, int, int) __asm__("func_8001830C");
extern int Level42SpawnD_80071908 __asm__("D_80071908");
typedef struct {
    unsigned char raw[88];
} Level42SpawnRawRecord;
extern Level42SpawnRawRecord* Level42SpawnRecords __asm__("D_8006C550");
int Level42SpawnQueryWorldHeight(void*, int) __asm__("func_8001A358");
extern int Level42SpawnD_8006D07C __asm__("D_8006D07C");
extern int Level42SpawnD_8006D080 __asm__("D_8006D080");
extern int Level42SpawnD_8006D084 __asm__("D_8006D084");
extern int Level42SpawnD_80071934 __asm__("D_80071934");
extern unsigned char Level42SpawnPlayerE __asm__("D_80070328 + 0xE");
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Level42SpawnHigh(a, b)                                                       \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Level42SpawnColor1[] __asm__("D_80066BAC");
extern unsigned char Level42SpawnColor2[] __asm__("D_80066BAC");
#define Level42SpawnField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level42SpawnBuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Level42SpawnTransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Level42SpawnShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Level42SpawnCopyVector(void*, void*) __asm__("func_8004F178");
int Level42SpawnAddVector(void*, void*, void*) __asm__("func_8004F194");
int Level42SpawnMultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Level42SpawnPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Level42SpawnAllocateParticleRecord(int) __asm__("func_80056434");
int Level42SpawnRandBetween(int, int) __asm__("func_8003636C");
int Level42SpawnCopyHalfwordVector(void*, void*) __asm__("func_8004F58C");
int Level42Spawnrand(void) __asm__("rand");
extern unsigned char Level42SpawnD_800658A0[] __asm__("D_800658A0");
extern unsigned char Level42SpawnD_80065920[] __asm__("D_80065920");
extern unsigned char Level42SpawnD_80066A28[] __asm__("D_80066A28");
extern unsigned char Level42SpawnD_80066A48[] __asm__("D_80066A48");
extern unsigned char Level42SpawnD_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Level42SpawnD_80070328[] __asm__("D_80070328");
extern int Level42SpawnD_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original SCUS-94467 USA Rev0 level42
 * evidence: build/sibling4289.func_level_42_80087D48.json.
 * Raw helper meanings, units and cadence remain unresolved. */
void* func_level_42_80087D48(int entryCount, int kind, void* input, void* mode) {
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
        int spC0;
        int spC4;
        unsigned char spC8, spC9, spCA, padCB;
        int spCC;
        int spD0;
        int spD4;
        int spD8;
        int spDC;
        int spE0;
        int spE4;
        int spE8;
        int spEC;
        int spF0;
        int spF4;
        int spF8;
        int spFC;
        int sp100;
        int sp104;
        int sp108;
        int sp10C;
        int sp110;
        int sp114;
        int* volatile sp118;
        int sp11C;
        int sp120;
        int sp124;
        volatile int sp128;
        int sp12C;
    } frame;
    register int kindSelector __asm__("$22") = kind;
    register unsigned char* reference __asm__("$20") = input;
    register unsigned char* modeSelector __asm__("$23") = mode;
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
    frame.sp108 = entryCount;
    frame.sp110 = 0;
    if (entryCount > 0) {
        {
            register int* vectorBase __asm__("$8") = &frame.sp38;
            MATCHING_KEEP_CLOBBER(vectorBase, "$30");
            byte255 = 255;
            MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
            frame.sp118 = vectorBase;
        }
        frame.sp128 = 0;
        do {
            MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$9");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = one;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level42SpawnField(record, short*, 0x1E) = 0;
                    Level42SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level42Spawnrand();
                    commonByte8 = 128;
                    commonByte9 = 128;
                    MATCHING_KEEP3(commonByte8, commonByte9, tailByte);
                    Level42SpawnField(record, volatile unsigned char*, 12) = commonByte8;
                    Level42SpawnField(record, volatile unsigned char*, 13) = commonByte9;
                    commonByte9 = 46;
                    Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level42SpawnField(record, volatile unsigned char*, 14) = commonByte8;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level42SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x1: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    Level42SpawnField(record, short*, 0x1E) = 0;
                    Level42SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level42Spawnrand();
                    Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 96;
                    commonByte8 = 46;
                    MATCHING_KEEP2(commonByte8, tailByte);
                    Level42SpawnField(record, volatile unsigned char*, 12) = tailByte;
                    Level42SpawnField(record, volatile unsigned char*, 13) = tailByte;
                    Level42SpawnField(record, volatile unsigned char*, 14) = tailByte;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$3", "memory");
                    tailByte = 4;
                    Level42SpawnField(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x2:
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                        tailByte = Level42Spawnrand();
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp18 = tailByte;
                        tailByte = Level42Spawnrand();
                        destination = record + 24;
                        source = &frame.sp18;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp1C = tailByte;
                        frame.sp20 = 16;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Level42SpawnField(record, unsigned short*, 30) = 0;
                    Level42SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level42Spawnrand();
                    commonByte9 = 128;
                    commonByte8 = 128;
                    MATCHING_KEEP3(commonByte9, commonByte8, tailByte);
                    Level42SpawnField(record, volatile unsigned char*, 12) = commonByte9;
                    Level42SpawnField(record, volatile unsigned char*, 13) = commonByte8;
                    commonByte8 = 46;
                    Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level42SpawnField(record, unsigned char*, 14) = commonByte9;
                    goto initializeF8;

                case 0x6:
                    temp_s1 = Level42SpawnField(reference, unsigned char**, 0);
                    record = Level42SpawnAllocateParticleRecord(3);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level42Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5");
                        scratch16 = (int)(reference + 12);
                        source = (void*)scratch16;
                        MATCHING_KEEP4(destination, source, scratch16, tailByte);
                        tailByte &= 15;
                        Level42SpawnField(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        component -= 63;
                        component += random;
                        Level42SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        Level42SpawnField(record, int*, 24) = scratch16;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                        component -= 63;
                        component += random;
                        Level42SpawnField(record, unsigned short*, 6) = component;
                    }
                    tailByte = Level42SpawnField(temp_s1, int*, 4);
                    Level42SpawnField(record, unsigned short*, 28) = tailByte;
                    {
                        register int value __asm__("$3") = Level42SpawnField(temp_s1, int*, 0);
                        tailByte = 32;
                        Level42SpawnField(record, unsigned char*, 10) = tailByte;
                        __asm__ volatile("" : "=r"(value) : "0"(value) : "$9", "$8", "memory");
                        tailByte = 20;
                        commonByte9 = 128;
                        commonByte8 = 128;
                        MATCHING_KEEP3(tailByte, commonByte9, commonByte8);
                        Level42SpawnField(record, volatile unsigned char*, 12) = commonByte9;
                        Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        Level42SpawnField(record, volatile unsigned char*, 13) = commonByte8;
                        Level42SpawnField(record, volatile unsigned char*, 14) = commonByte9;
                        Level42SpawnField(record, volatile unsigned char*, 15) = tailByte;
                        Level42SpawnField(record, volatile unsigned char*, 17) = 0;
                        Level42SpawnField(record, volatile unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
                        value >>= 6;
                        Level42SpawnField(record, unsigned short*, 30) = value;
                        break;
                    }
                case 0x9: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* playerVector __asm__("$16") = &frame.sp28;
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Level42SpawnD_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnCopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp28;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp28 = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = &frame.sp28;
                            __asm__(""
                                    : "=r"(destination), "=r"(source)
                                    : "0"(destination), "1"(source)
                                    : "$3", "memory");
                            component = frame.sp2C;
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            frame.sp2C = component;
                            Level42SpawnPackVectorShiftRight2(destination, source);
                        }
                        Level42SpawnCopyVector(playerVector, player + 0x98);
                        Level42SpawnShiftVectorRightTowardZero(playerVector, 6);
                        Level42SpawnPackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Level42SpawnField(record, short*, 0x1E) = 0;
                    Level42SpawnField(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Level42Spawnrand();
                    commonByte8 = 128;
                    commonByte9 = 128;
                    MATCHING_KEEP3(commonByte8, commonByte9, tailByte);
                    Level42SpawnField(record, volatile unsigned char*, 12) = commonByte8;
                    Level42SpawnField(record, volatile unsigned char*, 13) = commonByte9;
                    commonByte9 = 46;
                    Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    __asm__ volatile(""
                                     : "=r"(tailByte), "=r"(commonByte9), "=r"(commonByte8)
                                     : "0"(tailByte), "1"(commonByte9), "2"(commonByte8)
                                     : "$3", "memory");
                    Level42SpawnField(record, volatile unsigned char*, 14) = commonByte8;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Level42SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0xA: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(3);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Level42SpawnD_80070328;
                        tailByte = Level42Spawnrand();
                        destination = record + 4;
                        source = Level42SpawnD_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
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
                        Level42SpawnField(record, unsigned char*, 10) = value;
                        value = 15;
                        Level42SpawnField(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.sp108;
                        iteration8 = frame.sp110;
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = frame.sp128;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Level42SpawnD_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Level42SpawnHigh(dividend, factor);
                        Level42SpawnField(record, unsigned char*, 12) = value;
                        value = *(Level42SpawnColor1 + 1 + count);
                        dividend >>= 31;
                        Level42SpawnField(record, unsigned char*, 13) = value;
                        color = *(Level42SpawnColor2 + 2 + count);
                        value = 44;
                        Level42SpawnField(record, unsigned char*, 15) = value;
                        value = 4;
                        Level42SpawnField(record, unsigned char*, 17) = value;
                        Level42SpawnField(record, unsigned char*, 16) = 0;
                        Level42SpawnField(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Level42SpawnField(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register int iteration __asm__("$8") = frame.sp110;
                        register void* vector __asm__("$6") = frame.sp118;
                        register int base __asm__("$2");
                        register void* table __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(vector)
                                : "0"(destination), "1"(iteration), "2"(vector)
                                : "$2", "$5", "memory");
                        base = (int)Level42SpawnD_80066A48;
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        table = (void*)(iteration * 12);
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "memory");
                        base = 1;
                        Level42SpawnField(record, unsigned char*, 3) = base;
                        base = 4;
                        Level42SpawnField(record, unsigned char*, 17) = base;
                        Level42SpawnTransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Level42SpawnField(reference, short*, 54);
                            MATCHING_KEEP_CLOBBER(observed, "memory");
                            scratch16 = 0x17D;
                            MATCHING_KEEP_CLOBBER(scratch16, "memory");
                            observed == scratch16;
                        })) {
                        Level42SpawnMultiplyVectorGpfSf0(frame.sp118, frame.sp118, 3);
                    }
                    Level42SpawnAddVector(frame.sp118, frame.sp118, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp38;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp38 = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp3C;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp3C = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp40;
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp40 = component;
                        }
                    }
                    if (modeSelector == (unsigned char*)6) {
                        {
                            register int random __asm__("$2") = Level42Spawnrand();
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
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp3C;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp3C = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp40;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp40 = component;
                        }
                    }
                    if (Level42SpawnField(reference, short*, 0x36) == 0xB6) {
                        frame.sp40 += 0x200;
                    }
                    Level42SpawnPackVectorShiftRight2(record + 4, frame.sp118);
                    Level42SpawnField(record, int*, 0xC) =
                        (int)*(int*)(Level42SpawnD_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Level42SpawnField(reference, short*, 54);
                            MATCHING_KEEP_CLOBBER(scratch16, "memory");
                            observed == scratch16;
                        })) {
                        var_v0_2 = (Level42Spawnrand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Level42Spawnrand() & 7) + 0x20;
                    }
                    Level42SpawnField(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Level42Spawnrand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int iteration __asm__("$9") = frame.sp110;
                        register int base __asm__("$3");
                        register void* source __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(tailByte)
                                : "0"(destination), "1"(iteration), "2"(tailByte)
                                : "$3", "$5", "memory");
                        base = (int)Level42SpawnD_80066A48;
                        Level42SpawnField(record, unsigned char*, 11) = tailByte;
                        Level42SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        source = (void*)(iteration * 12);
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnField(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Level42SpawnField(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level42Spawnrand() & 7));
                    Level42SpawnField(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Level42SpawnField(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level42Spawnrand() & 7));
                    Level42SpawnField(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Level42SpawnField(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Level42Spawnrand() & 7));
                    break;
                case 0xd:
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Level42SpawnField(record, unsigned short*, 30) = 0;
                    goto initializeRand37;
                case 0x20:
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 26;
                    Level42SpawnField(record, short*, 0x1E) = 0;
                    Level42SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level42Spawnrand();
                    commonByte9 = 46;
                    __asm__ volatile(""
                                     : "=r"(commonByte9), "=r"(tailByte)
                                     : "0"(commonByte9), "1"(tailByte)
                                     : "$3", "memory");
                    Level42SpawnField(record, unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Level42SpawnField(record, unsigned char*, 12) = byte255;
                    Level42SpawnField(record, unsigned char*, 13) = byte255;
                    Level42SpawnField(record, unsigned char*, 14) = 0;
                    Level42SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x21: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) = 0;
                    Level42SpawnField(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp58;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Level42SpawnD_80070328 + 0x98;
                            Level42SpawnCopyVector(destination, temp_s1);
                        }
                        Level42SpawnShiftVectorRightTowardZero((void*)scratch16, 6);
                        Level42SpawnCopyVector(&frame.sp48, temp_s1 - 0x98);
                        frame.sp50 -= 0x164;
                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.sp48;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp48 = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$19");
                            scratch19 = 48;
                            component = frame.sp4C;
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            frame.sp4C = component;
                        }

                        goto setDestination;
                    } else {
                        register int one __asm__("$8") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            {
                                register void* base4 __asm__("$4") = Level42SpawnD_80070328 + 0x30;
                                register void* arg5 __asm__("$5");
                                register void* arg6 __asm__("$6");
                                __asm__("" : "=r"(base4) : "0"(base4) : "$16", "memory");
                                scratch16 = (int)&frame.sp48;
                                arg5 = (void*)scratch16;
                                arg6 = arg5;
                                frame.sp48 = 0x164;
                                frame.sp4C = 0;
                                frame.sp50 = 0;
                                Level42SpawnTransformVectorByBasis(base4, arg5, arg6);
                            }
                            {
                                register void* arg4 __asm__("$4") = (void*)scratch16;
                                register void* arg5 __asm__("$5") = arg4;
                                register unsigned char* table9 __asm__("$9") =
                                    Level42SpawnD_80070328 + 0x30;
                                MATCHING_KEEP3_CLOBBER(arg4, arg5, table9, "memory");
                                Level42SpawnAddVector(arg4, arg5, table9 - 0x30);
                            }
                            scratch19 = 0x40;
                            frame.sp58 = -(Level42Spawnrand() & 7);
                            {
                                register int random __asm__("$2") = Level42Spawnrand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") =
                                    Level42SpawnD_80070328 + 0x30;
                                register void* vector __asm__("$5") = &frame.sp58;
                                register int iteration8 __asm__("$8") = frame.sp110;
                                register int angle __asm__("$7");
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP4_CLOBBER(destination, vector, angle, output,
                                                       "memory");
                                MATCHING_KEEP(iteration8);
                                random &= 15;
                                angle = iteration8 << 6;
                                component = *(unsigned short*)(Level42SpawnD_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp5C = component;
                                random = *(unsigned short*)(Level42SpawnD_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp60 = random;
                                Level42SpawnTransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else {
                            register int two __asm__("$2") = 2;
                            MATCHING_KEEP(two);
                            scratch16 = 5;
                            if (modeSelector == (unsigned char*)two) {
                                {
                                    register int iteration8 __asm__("$9") = frame.sp110;
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
                                    register int iteration9 __asm__("$8") = frame.sp110;
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
                    Level42SpawnCopyVector(&frame.sp48, Level42SpawnD_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Level42SpawnD_80065920;
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
                        other = frame.sp48;
                        value >>= scratch16;
                        other += value;
                        value = (int)Level42SpawnD_800658A0;
                        second += value;
                        value = frame.sp50;
                        frame.sp48 = other;
                        other = *(short*)second;
                        value -= 356;
                        frame.sp50 = value;
                        value = frame.sp4C;
                        other >>= scratch16;
                        value += other;
                        frame.sp4C = value;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        value = *first;
                        other = scratch16 + 1;
                        value >>= other;
                        frame.sp58 = value;
                        value = *(short*)second;
                        frame.sp60 = 0;
                        value >>= other;
                        frame.sp5C = value;
                    }
                setDestination:
                    var_a0 = record + 4;
                finishMode:
                    Level42SpawnPackVectorShiftRight2(var_a0, &frame.sp48);
                    Level42SpawnPackVectorShiftRight2(record + 0x18, &frame.sp58);
                    Level42SpawnField(record, short*, 0x1E) = 0;
                    Level42SpawnField(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Level42Spawnrand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Level42SpawnField(record, volatile unsigned char*, 12) = scratch19;
                    Level42SpawnField(record, volatile unsigned char*, 13) = scratch19;
                    Level42SpawnField(record, unsigned char*, 14) = scratch19;
                    Level42SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x27: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$2");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 3) = one;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    {
                        register int value4 __asm__("$4") = 10;
                        register int value5 __asm__("$5") = 24;
                        commonByte8 = 128;
                        commonByte9 = 128;
                        MATCHING_KEEP4_CLOBBER(value4, value5, commonByte8, commonByte9, "memory");
                        Level42SpawnField(record, volatile unsigned char*, 12) = commonByte8;
                        Level42SpawnField(record, volatile unsigned char*, 13) = commonByte9;
                        commonByte9 = 46;
                        tailByte = 4;
                        Level42SpawnField(record, volatile unsigned char*, 11) = 0;
                        Level42SpawnField(record, volatile unsigned char*, 14) = commonByte8;
                        Level42SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                        Level42SpawnField(record, volatile unsigned char*, 17) = tailByte;
                        Level42SpawnField(record, unsigned char*, 16) = 0;
                        tailByte = Level42SpawnRandBetween(value4, value5);
                    }
                    Level42SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level42SpawnRandBetween(40, 70);
                    Level42SpawnField(record, unsigned char*, 2) = tailByte;
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
                                     : "0"((unsigned char*)&frame - 0x18)
                                     : "memory");
                    vector16 = stackBase29 + 0x68;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    Level42SpawnCopyVector(vector16, reference);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value2 = Level42Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value3 = frame.sp68;
                    value2 &= 255;
                    value3 += 128;
                    value3 -= value2;
                    frame.sp68 = value3;
                    value2 = Level42Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value3 = frame.sp6C;
                    value2 &= 255;
                    value3 += 128;
                    value3 -= value2;
                    frame.sp6C = value3;
                    value2 = Level42Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    angle21 = value2 & 255;
                    value2 = Level42Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    {
                        register void* arg4 __asm__("$4") = &frame.sp78;
                        register void* arg5 __asm__("$5") = vector16;
                        MATCHING_KEEP3(arg4, arg5, value2);
                        value2 &= 1023;
                        radius19 = value2 + 512;
                        Level42SpawnCopyVector(arg4, arg5);
                        MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    }
                    destination4 = &frame.sp88;
                    if (modeSelector != 0)
                        source5 = modeSelector;
                    else {
                        source5 = Level42SpawnD_80070328 + 0x8C;
                        MATCHING_KEEP_VOLATILE_CLOBBER(source5, "memory");
                    }
                    Level42SpawnCopyVector(destination4, source5);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    __asm__ volatile(
                        "" ::
                            : "$16",
                              "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned char*)&frame - 0x18)
                                     : "memory");
                    vector16 = stackBase29 + 0x88;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    Level42SpawnShiftVectorRightTowardZero(vector16, 1);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    {
                        register int count9 __asm__("$8") = frame.sp108;
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
                                         : "0"((unsigned char*)&frame - 0x18)
                                         : "memory");
                        vector17 = stackBase29 + 0x78;
                        if (count9 == one8) {
                            Level42SpawnMultiplyVectorGpfSf0(vector16, vector16, 3);
                            MATCHING_KEEP_VOLATILE_CLOBBER(vector17, "memory");
                            __asm__ volatile(
                                "" ::
                                    : "$17",
                                      "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                            __asm__ volatile(""
                                             : "=r"(stackBase29)
                                             : "0"((unsigned char*)&frame - 0x18)
                                             : "memory");
                            vector17 = stackBase29 + 0x78;
                            MATCHING_KEEP_VOLATILE_CLOBBER(vector17, "memory");
                        }
                    }
                    frame.sp90 = 0;
                    Level42SpawnAddVector(vector17, vector17, vector16);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    index4 = angle21 << 1;
                    value2 = Level42SpawnField(Level42SpawnD_80065920 + index4, short*, 0);
                    __asm__ volatile("" : "=l"(low9) : "0"(value2 * radius19) : "memory");
                    value2 = frame.sp78;
                    value3 = low9 >> 12;
                    value2 += value3;
                    frame.sp78 = value2;
                    value2 = Level42SpawnField(Level42SpawnD_800658A0 + index4, short*, 0);
                    {
                        int productLo = value2 * radius19;
                        __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                        source5 = (void*)1024;
                        value2 = frame.sp80;
                        MATCHING_KEEP2_CLOBBER(source5, value2, "$4");
                        destination4 = vector17;
                        MATCHING_KEEP3(source5, value2, destination4);
                        value2 += 512;
                        frame.sp80 = value2;
                        value2 = frame.sp7C;
                        __asm__ volatile(""
                                         : "=l"(productLo), "=r"(value2)
                                         : "0"(productLo), "1"(value2)
                                         : "memory");
                        low8 = productLo;
                        MATCHING_KEEP(low8);
                        value3 = low8 >> 12;
                        value2 += value3;
                        frame.sp7C = value2;
                        value2 = Level42SpawnQueryWorldHeight(destination4, (int)source5);
                    }
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    frame.sp80 = value2;
                    if (value2 == 0)
                        break;
                    record = Level42SpawnAllocateParticleRecord(3);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    value2 = 1;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    Level42SpawnField(record, volatile unsigned char*, 3) = value2;
                    value2 = 10;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    Level42SpawnField(record, volatile unsigned char*, 10) = value2;
                    value2 = 6;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$4", "memory");
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) = 0;
                    destination4 = record + 4;
                    MATCHING_KEEP(destination4);
                    Level42SpawnField(record, unsigned char*, 11) = value2;
                    value2 = Level42SpawnD_8006D07C;
                    __asm__ volatile("" : "=r"(value2) : "0"(value2) : "$16", "memory");

                    __asm__ volatile(
                        "" ::
                            : "$16",
                              "memory"); /* Original SP-relative producer; empty identity constraint, no CPU assembly.
                      * Frame starts atSP10 under the unchanged pipeline. Native
                      * frame/address words must match before this probe is installed. */
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned char*)&frame - 0x18)
                                     : "memory");
                    vector16 = stackBase29 + 0x68;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");

                    value2 >>= 4;
                    Level42SpawnField(record, unsigned char*, 12) = value2;
                    value2 = Level42SpawnD_8006D080;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$5", "memory");
                    source5 = vector16;
                    MATCHING_KEEP2(value2, source5);
                    value2 >>= 4;
                    Level42SpawnField(record, unsigned char*, 13) = value2;
                    value3 = Level42SpawnD_8006D084;
                    __asm__ volatile("" : "=r"(value3) : "0"(value3) : "$8", "$2", "memory");
                    commonByte8 = 46;
                    value2 = 2;
                    MATCHING_KEEP3(value3, commonByte8, value2);
                    Level42SpawnField(record, unsigned char*, 15) = commonByte8;
                    Level42SpawnField(record, unsigned char*, 17) = value2;
                    Level42SpawnField(record, unsigned char*, 16) = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value3, "memory");
                    value3 >>= 4;
                    Level42SpawnField(record, unsigned char*, 14) = value3;
                    Level42SpawnPackVectorShiftRight2(destination4, source5);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    Level42SpawnPackVectorShiftRight2(record + 18, vector16);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    Level42SpawnPackVectorShiftRight2(record + 24, vector17);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    scratch16 = Level42Spawnrand();
                    value2 = Level42Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    scratch16 &= 14;
                    value2 = (value2 & 6) + 20;
                    scratch16 += value2;
                    Level42SpawnField(record, unsigned short*, 22) = scratch16;
                    Level42SpawnField(record, unsigned char*, 30) = 0;
                    while (scratch16 > 0 || frame.sp70 > frame.sp80) {
                        frame.sp70 += scratch16 << 2;
                        Level42SpawnField(record, unsigned char*, 30) += 1;
                        scratch16 -= 2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch16, "memory");
                    }
                    value2 = Level42Spawnrand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
                    Level42SpawnField(record, unsigned char*, 29) = value2;
                    Level42SpawnField(record, unsigned char*, 31) = Level42SpawnD_80071934;
                } break;
                case 0x2A:
                    record = Level42SpawnAllocateParticleRecord(4);
                    {
                        register void* arg4 __asm__("$4") = record + 4;
                        register void* arg5 __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(arg4, arg5, "$2");
                        tailByte = 1;
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(arg4, arg5);
                    }
                    tailByte = Level42SpawnField(reference, int*, 0);
                    Level42SpawnField(record, int*, 24) = tailByte;
                    tailByte = Level42SpawnField(reference, int*, 4);
                    Level42SpawnField(record, int*, 28) = tailByte;
                    tailByte = Level42SpawnField(modeSelector, int*, 0);
                    Level42SpawnField(record, unsigned short*, 18) = tailByte;
                    tailByte = Level42SpawnField(modeSelector, int*, 4);
                    Level42SpawnField(record, unsigned short*, 20) = tailByte;
                    tailByte = Level42Spawnrand();
                    tailByte = (tailByte & 7) + 3;
                    Level42SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = 108;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "$3", "$9", "memory");
                    {
                        register int color3 __asm__("$3") = Level42SpawnPlayerE;
                        __asm__(""
                                : "=r"(color3), "=r"(tailByte)
                                : "0"(color3), "1"(tailByte)
                                : "$9", "memory");
                        commonByte9 = 46;
                        Level42SpawnField(record, unsigned char*, 12) = tailByte;
                        Level42SpawnField(record, unsigned char*, 13) = tailByte;
                        Level42SpawnField(record, unsigned char*, 14) = tailByte;
                        Level42SpawnField(record, unsigned char*, 15) = commonByte9;
                        Level42SpawnField(record, unsigned char*, 17) = 0;
                        Level42SpawnField(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(color3, "memory");
                        color3 += 32;
                        Level42SpawnField(record, unsigned char*, 11) = color3;
                    }
                    break;
                    {
                        register int commonByte3 __asm__("$3");
                        case 0x2B:
                            record = Level42SpawnAllocateParticleRecord(4);
                            tailByte = 1;
                            Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                            Level42SpawnField(record, unsigned char*, 2) = 0;
                            Level42SpawnField(record, unsigned char*, 3) = tailByte;
                            if (modeSelector == 0) {
                                Level42SpawnCopyHalfwordVector(record + 4, reference);
                                tailByte = Level42Spawnrand();
                                tailByte &= 7;
                                tailByte += 2;
                                Level42SpawnField(record, unsigned char*, 10) = tailByte;
                                commonByte3 = 96;
                            } else {
                                Level42SpawnPackVectorShiftRight2(record + 4, reference);
                                {
                                    register int two __asm__("$2") = 2;
                                    MATCHING_KEEP(two);
                                    if (modeSelector == (unsigned char*)two) {
                                        {
                                            register int random __asm__("$2") = Level42Spawnrand();
                                            register int component __asm__("$3") =
                                                Level42SpawnField(record, unsigned short*, 4);
                                            MATCHING_KEEP2(random, component);
                                            random &= 127;
                                            component += 32;
                                            component -= random;
                                            Level42SpawnField(record, unsigned short*, 4) =
                                                component;
                                        }
                                        {
                                            register int random __asm__("$2") = Level42Spawnrand();
                                            register int component __asm__("$3") =
                                                Level42SpawnField(record, unsigned short*, 6);
                                            MATCHING_KEEP2(random, component);
                                            random &= 127;
                                            component += 32;
                                            component -= random;
                                            Level42SpawnField(record, unsigned short*, 6) =
                                                component;
                                        }
                                    }
                                }
                                tailByte = Level42Spawnrand();
                                tailByte &= 7;
                                MATCHING_KEEP(tailByte);
                                tailByte += 16;
                                Level42SpawnField(record, unsigned char*, 10) = tailByte;
                                commonByte3 = 64;
                            }
                            {
                                register int sourceByte __asm__("$2") =
                                    Level42SpawnField(Level42SpawnD_80070328, unsigned char*, 14);
                                MATCHING_KEEP2_CLOBBER(sourceByte, commonByte3, "memory");
                                Level42SpawnField(record, unsigned char*, 12) = commonByte3;
                                Level42SpawnField(record, unsigned char*, 13) = commonByte3;
                                Level42SpawnField(record, unsigned char*, 14) = commonByte3;
                                commonByte8 = 46;
                                MATCHING_KEEP2_CLOBBER(sourceByte, commonByte8, "memory");
                                Level42SpawnField(record, unsigned char*, 15) = commonByte8;
                                Level42SpawnField(record, unsigned char*, 17) = 0;
                                Level42SpawnField(record, unsigned char*, 16) = 0;
                                Level42SpawnField(record, unsigned short*, 24) = (int)modeSelector;
                                Level42SpawnField(record, unsigned char*, 11) = sourceByte;
                            }
                            break;
                    }
                case 0x2C: {
                    register void* vector17 __asm__("$17");
                    register unsigned char* player16 __asm__("$16");
                    register void* copy16 __asm__("$16");
                    register void* arg4 __asm__("$4") = Level42SpawnD_80070328 + 0x30;
                    register void* arg5 __asm__("$5") = reference;
                    register void* arg6 __asm__("$6");
                    register int value2 __asm__("$2");
                    __asm__("" : "=r"(arg4), "=r"(arg5) : "0"(arg4), "1"(arg5) : "$17", "memory");
                    vector17 = &frame.sp98;
                    MATCHING_KEEP3(arg4, arg5, vector17);
                    Level42SpawnTransformVectorByBasis(arg4, arg5, vector17);
                    arg4 = vector17;
                    arg5 = vector17;
                    {
                        register unsigned char* table9 __asm__("$9") =
                            Level42SpawnD_80070328 + 0x30;
                        MATCHING_KEEP_CLOBBER(table9, "memory");
                        player16 = table9 - 0x30;
                    }
                    Level42SpawnAddVector(arg4, arg5, player16);
                    if (Level42SpawnQueryWorldSegmentWithOptions(player16, vector17, 2, 0, 0) != 0)
                        break;
                    record = Level42SpawnAllocateParticleRecord(2);
                    arg4 = record + 4;
                    arg5 = vector17;
                    value2 = 1;
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 3) = value2;
                    Level42SpawnPackVectorShiftRight2(arg4, arg5);
                    Level42SpawnPackVectorShiftRight2(record + 24, vector17);
                    value2 = Level42SpawnField(Level42SpawnD_80070328, int*, 0x8C);
                    value2 >>= 9;
                    Level42SpawnField(record, unsigned short*, 18) = value2;
                    value2 = Level42SpawnField(Level42SpawnD_80070328, int*, 0x90);
                    value2 >>= 9;
                    Level42SpawnField(record, unsigned short*, 20) = value2;
                    value2 = Level42Spawnrand();
                    value2 &= 3;
                    MATCHING_KEEP(value2);
                    value2 += 4;
                    commonByte8 = 128;
                    commonByte9 = 128;
                    MATCHING_KEEP3_CLOBBER(value2, commonByte8, commonByte9, "memory");
                    Level42SpawnField(record, volatile unsigned char*, 12) = commonByte8;
                    Level42SpawnField(record, volatile unsigned char*, 13) = commonByte9;
                    commonByte9 = 46;
                    Level42SpawnField(record, volatile unsigned short*, 22) = value2;
                    value2 = 2;
                    Level42SpawnField(record, volatile unsigned char*, 11) = 0;
                    Level42SpawnField(record, volatile unsigned char*, 14) = commonByte8;
                    Level42SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                    Level42SpawnField(record, volatile unsigned char*, 17) = value2;
                    Level42SpawnField(record, unsigned char*, 16) = 0;
                    value2 = Level42Spawnrand();
                    value2 &= 7;
                    MATCHING_KEEP(value2);
                    value2 += 6;
                    Level42SpawnField(record, unsigned char*, 10) = value2;
                    value2 = Level42Spawnrand();
                    Level42SpawnField(record, unsigned char*, 28) = value2;
                    value2 = Level42Spawnrand();
                    value2 &= 31;
                    {
                        register int value3 __asm__("$3") = 16;
                        value3 -= value2;
                        Level42SpawnField(record, unsigned char*, 29) = value3;
                    }
                    value2 = Level42Spawnrand();
                    copy16 = &frame.spA8;
                    arg4 = copy16;
                    arg5 = vector17;
                    MATCHING_KEEP4_CLOBBER(copy16, arg4, arg5, value2, "memory");
                    value2 &= 31;
                    MATCHING_KEEP(value2);
                    value2 += 64;
                    Level42SpawnField(record, unsigned char*, 2) = value2;
                    Level42SpawnCopyVector(arg4, arg5);
                    arg4 = vector17;
                    arg5 = copy16;
                    value2 = frame.spB0;
                    value2 += 3072;
                    frame.spB0 = value2;
                    value2 = Level42SpawnQueryWorldSegmentWithOptions(arg4, arg5, 2, 0, 0);
                    if (value2) {
                        value2 = Level42SpawnD_80071908;
                        value2 >>= 2;
                        Level42SpawnField(record, unsigned short*, 30) = value2;
                        value2 = Level42SpawnD_80071934;
                        if (value2 == 0)
                            break;
                        value2 = 3;
                        Level42SpawnField(record, unsigned char*, 17) = value2;
                        break;
                    }
                    value2 = frame.spB0;
                    value2 >>= 2;
                    Level42SpawnField(record, unsigned short*, 30) = value2;
                } break;
                case 0x2E:
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 127;
                        component += 64;
                        component -= random;
                        Level42SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 127;
                        component += 64;
                        component -= random;
                        Level42SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector != 0) {
                        tailByte = Level42Spawnrand();
                        tailByte &= 15;
                        MATCHING_KEEP(tailByte);
                        tailByte = (int)modeSelector + tailByte;
                    } else {
                        tailByte = Level42Spawnrand();
                        tailByte &= 15;
                        MATCHING_KEEP(tailByte);
                        tailByte += 20;
                    }
                    Level42SpawnField(record, unsigned char*, 10) = tailByte;
                    tailByte = Level42Spawnrand();
                    commonByte8 = 128;
                    commonByte9 = 128;
                    MATCHING_KEEP3(commonByte8, commonByte9, tailByte);
                    Level42SpawnField(record, volatile unsigned char*, 12) = commonByte8;
                    Level42SpawnField(record, volatile unsigned char*, 13) = commonByte9;
                    commonByte9 = 46;
                    Level42SpawnField(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    __asm__ volatile(""
                                     : "=r"(tailByte), "=r"(commonByte9), "=r"(commonByte8)
                                     : "0"(tailByte), "1"(commonByte9), "2"(commonByte8)
                                     : "$4", "memory");
                    Level42SpawnField(record, unsigned char*, 14) = commonByte8;
                    Level42SpawnField(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;

                case 0x37:
                    record = Level42SpawnAllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 2) = 0;
                        Level42SpawnField(record, unsigned char*, 3) = tailByte;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 64;

                initializeRand37:
                    Level42SpawnField(record, unsigned char*, 0xA) = tailByte;
                    tailByte = Level42Spawnrand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                    Level42SpawnField(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Level42SpawnField(record, unsigned char*, 0xC) = byte255;
                    Level42SpawnField(record, unsigned char*, 0xD) = byte255;
                    Level42SpawnField(record, unsigned char*, 0xE) = 0;
                initializeF8:
                    Level42SpawnField(record, unsigned char*, 15) = commonByte8;
                initializeTrailingBytes:
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                    Level42SpawnField(record, unsigned char*, 17) = tailByte;
                    Level42SpawnField(record, unsigned char*, 16) = 0;
                    break;

                case 0x38:
                    record = Level42SpawnAllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) = 0;
                    Level42SpawnField(record, unsigned char*, 3) = tailByte;
                    Level42SpawnField(record, unsigned short*, 4) =
                        Level42SpawnField(reference, unsigned short*, 4);
                    Level42SpawnField(record, unsigned short*, 6) =
                        Level42SpawnField(reference, unsigned short*, 6);
                    Level42SpawnField(record, unsigned short*, 8) =
                        Level42SpawnField(reference, unsigned short*, 8);
                    Level42SpawnField(record, int*, 24) = Level42SpawnField(reference, int*, 24);
                    Level42SpawnField(record, int*, 28) = Level42SpawnField(reference, int*, 28);
                    tailByte = Level42SpawnField(reference, unsigned char*, 10);
                    MATCHING_KEEP(tailByte);
                    Level42SpawnField(record, unsigned char*, 10) = tailByte;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register unsigned int sourceByte __asm__("$2") =
                            Level42SpawnField(reference, unsigned char*, 11);
                        MATCHING_KEEP_CLOBBER(sourceByte, "memory");
                        commonByte9 = 46;
                        Level42SpawnField(record, volatile unsigned char*, 12) = 0;
                        Level42SpawnField(record, volatile unsigned char*, 13) = 0;
                        Level42SpawnField(record, volatile unsigned char*, 14) = 0;
                        Level42SpawnField(record, volatile unsigned char*, 15) = commonByte9;
                        Level42SpawnField(record, volatile unsigned char*, 17) = 0;
                        Level42SpawnField(record, volatile unsigned char*, 16) = 0;
                        Level42SpawnField(record, unsigned char*, 11) = sourceByte;
                    }
                    break;
                case 0x3B: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Level42SpawnField(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Level42SpawnField(record, unsigned char*, 3) = value;
                        value = 16;
                        Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                        Level42SpawnField(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Level42SpawnField(record, unsigned char*, 1) = flags;
                        Level42SpawnPackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level42SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Level42SpawnField(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Level42SpawnField(record, int*, 12) = var_v0;
                    Level42SpawnField(record, unsigned char*, 0xA) =
                        (unsigned char)((Level42Spawnrand() & 0xF) + 0x14);
                    Level42SpawnField(record, unsigned char*, 0xB) = Level42Spawnrand();
                    Level42SpawnField(record, unsigned char*, 0x10) = 0;
                    Level42SpawnField(record, short*, 0x18) = (short)((Level42Spawnrand() & 7) - 4);
                    Level42SpawnField(record, short*, 0x1A) =
                        (short)(-2 - (Level42Spawnrand() & 7));
                    Level42SpawnField(record, short*, 0x1C) =
                        (short)((Level42Spawnrand() & 0xF) - 8);
                    break;
                case 0x42: /* switch 1 */
                {
                    register int local128 __asm__("$9");
                    record = Level42SpawnAllocateParticleRecord(0);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level42Spawnrand() & 0xF);
                    Level42SpawnField(record, unsigned char*, 3) = 1;
                    Level42SpawnField(record, short*, 4) =
                        (short)((((int)Level42SpawnField(reference, int*, 0) >> 2) +
                                 (Level42Spawnrand() & 0xF)) -
                                8);
                    Level42SpawnField(record, short*, 6) =
                        (short)((((int)Level42SpawnField(reference, int*, 4) >> 2) +
                                 (Level42Spawnrand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Level42SpawnField(record, short*, 16) = 0;
                        Level42SpawnField(record, short*, 18) = 0;
                        Level42SpawnField(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Level42SpawnField(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Level42SpawnD_8006E344;
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
                        Level42SpawnField(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Level42SpawnField(Level42SpawnD_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Level42Spawnrand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Level42SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level42SpawnField(record, unsigned char*, 0xD) = 0;
                            Level42SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Level42SpawnField(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Level42SpawnField(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Level42SpawnField(record, unsigned char*, 13) = byte255;
                            Level42SpawnField(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Level42SpawnField(record, unsigned char*, 0xC) = 0;
                            Level42SpawnField(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Level42SpawnField(record, unsigned char*, 0xC) = 0;
                            Level42SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Level42SpawnField(record, unsigned char*, 0xC) = byte255;
                            Level42SpawnField(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            local128 = 128;
                            MATCHING_KEEP(local128);
                            Level42SpawnField(record, unsigned char*, 12) = byte255;
                            Level42SpawnField(record, unsigned char*, 13) = local128;
                        }
                            Level42SpawnField(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            commonByte8 = 128;
                            MATCHING_KEEP(commonByte8);
                            Level42SpawnField(record, unsigned char*, 12) = 0;
                            Level42SpawnField(record, unsigned char*, 13) = commonByte8;
                        }
                        storeThirdColor:
                            Level42SpawnField(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Level42SpawnField(record, unsigned char*, 0xF) = 0x40;
                    break;
                }
                case 0x46: /* switch 1 */
                {
                    register int local128 __asm__("$9");
                    record = Level42SpawnAllocateParticleRecord(1);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level42Spawnrand() & 0xF);
                    Level42SpawnField(record, unsigned char*, 3) = 1;
                    frame.spC8 = 0;
                    frame.spC9 = Level42Spawnrand();
                    frame.spCA = Level42Spawnrand();
                    Level42SpawnBuildPackedAngleBasisMatrix(&frame.spC8, &frame.spD0, 0);
                    frame.spB8 = (int)modeSelector;
                    frame.spBC = 0;
                    frame.spC0 = 0;
                    Level42SpawnTransformVectorByBasis(&frame.spD0, (unsigned char*)&frame.spB8,
                                                       (unsigned char*)&frame.spB8);
                    Level42SpawnField(record, unsigned short*, 4) =
                        (unsigned short)((int)Level42SpawnField(reference, int*, 0) >> 2);
                    Level42SpawnField(record, unsigned short*, 6) =
                        (unsigned short)((int)Level42SpawnField(reference, int*, 4) >> 2);
                    Level42SpawnField(record, unsigned short*, 8) =
                        (unsigned short)((int)Level42SpawnField(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.spB8;
                        register int other __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 4);

                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level42SpawnField(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.spBC;
                        other = Level42SpawnField(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Level42SpawnField(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.spC0;
                        value = 2;
                        Level42SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level42SpawnField(record, unsigned char*, 16) = value;
                        value = 192;
                        Level42SpawnField(record, unsigned char*, 17) = value;
                        value = 80;
                        Level42SpawnField(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Level42SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$9", "memory");

                        local128 = 128;
                        MATCHING_KEEP(local128);
                        Level42SpawnField(record, unsigned char*, 18) = 0;
                        Level42SpawnField(record, unsigned char*, 20) = byte255;
                        Level42SpawnField(record, unsigned char*, 21) = byte255;
                        Level42SpawnField(record, unsigned char*, 22) = local128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Level42SpawnField(record, short*, 14) = value;
                    }
                    break;
                }
                case 0x47: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(1);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level42Spawnrand() & 7);
                    Level42SpawnField(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Level42Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spE8 = temp_v0_4;
                    temp_v0_5 = (int)(((Level42Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spEC = temp_v0_5;
                    temp_v0_6 = (int)(((Level42Spawnrand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spF0 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Level42SpawnField(reference, int*, 0);
                        value = frame.spE8;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level42SpawnField(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level42SpawnField(reference, int*, 4);
                        value = frame.spEC;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level42SpawnField(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Level42SpawnField(reference, int*, 8);
                        value = frame.spF0;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Level42SpawnField(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.spE8;
                        register int value __asm__("$2") =
                            Level42SpawnField(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level42SpawnField(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.spEC;
                        value = Level42SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Level42SpawnField(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.spF0;
                        other = Level42SpawnField(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Level42SpawnField(record, unsigned char*, 23) = value;
                        value = 224;
                        Level42SpawnField(record, unsigned char*, 16) = value;
                        Level42SpawnField(record, unsigned char*, 17) = value;
                        value = 96;
                        Level42SpawnField(record, unsigned char*, 18) = value;
                        Level42SpawnField(record, unsigned char*, 20) = byte255;
                        Level42SpawnField(record, unsigned char*, 21) = byte255;
                        Level42SpawnField(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Level42SpawnField(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Level42SpawnField(record, short*, 14) = other;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Level42SpawnAllocateParticleRecord(0);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level42Spawnrand() & 0x1F);
                    Level42SpawnField(record, unsigned char*, 3) = 1;
                    Level42SpawnPackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level42SpawnField(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level42SpawnField(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Level42SpawnField(record, unsigned short*, 8) = component;
                    }
                    Level42SpawnField(record, short*, 0x10) = (short)((Level42Spawnrand() & 2) - 1);
                    Level42SpawnField(record, short*, 0x12) = (short)((Level42Spawnrand() & 2) - 1);
                    Level42SpawnField(record, short*, 0x14) = (short)-(Level42Spawnrand() & 1);
                    tailByte = Level42Spawnrand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Level42SpawnField(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Level42Spawnrand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Level42SpawnField(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Level42SpawnField(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Level42SpawnField(record, unsigned char*, 13) = component;
                    }
                    Level42SpawnField(record, unsigned char*, 0xE) =
                        (unsigned char)((Level42Spawnrand() & 0x3F) + 0x40);
                    Level42SpawnField(record, unsigned char*, 0xF) = 0x40;
                    Level42SpawnField(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                {
                    register int local128 __asm__("$8");
                    record = Level42SpawnAllocateParticleRecord(1);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    Level42SpawnField(record, unsigned char*, 2) =
                        (unsigned char)(Level42Spawnrand() & 0xF);
                    Level42SpawnField(record, unsigned char*, 3) = 1;
                    Level42SpawnPackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.spE8;
                        MATCHING_KEEP(vector);
                        Level42SpawnAddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&frame.spE8;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            frame.spE8 = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3") = frame.spEC;

                            random &= 0x3F;

                            component -= 0x20;

                            component += random;
                            frame.spEC = component;
                        }

                        {
                            register int random __asm__("$2") = Level42Spawnrand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;

                            component = frame.spF0;

                            random &= 0x7F;

                            component -= 0x40;

                            component += random;
                            frame.spF0 = component;
                            Level42SpawnPackVectorShiftRight2(destination, source);
                        }
                    }
                    Level42SpawnField(record, unsigned char*, 0x17) = 2;
                    tailByte = Level42Spawnrand();
                    tailByte |= 192;

                    Level42SpawnField(record, unsigned char*, 16) = tailByte;
                    Level42SpawnField(record, unsigned char*, 0x11) =
                        (unsigned char)((Level42Spawnrand() & 0x3F) - 0x60);
                    Level42SpawnField(record, unsigned char*, 0x12) = 0;
                    tailByte = Level42Spawnrand();
                    tailByte |= 224;

                    Level42SpawnField(record, unsigned char*, 20) = tailByte;
                    tailByte = Level42Spawnrand();
                    tailByte |= 224;

                    local128 = 128;
                    Level42SpawnField(record, unsigned char*, 21) = tailByte;
                    {

                        Level42SpawnField(record, unsigned char*, 0x16) = local128;
                    }
                    Level42SpawnField(record, unsigned char*, 0x13) = 0x50;
                    break;
                }

                case 0x52:
                    temp_s1 = Level42SpawnField(reference, unsigned char**, 0);
                    record = Level42SpawnAllocateParticleRecord(1);
                    Level42SpawnField(record, unsigned char*, 0) = kindSelector;
                    tailByte = Level42Spawnrand();
                    tailByte &= 15;
                    Level42SpawnField(record, unsigned char*, 2) = tailByte;
                    tailByte = 1;
                    Level42SpawnField(record, unsigned char*, 3) = tailByte;
                    tailByte = Level42Spawnrand();
                    scratch16 = tailByte & 255;
                    {
                        register int upper __asm__("$5") = Level42SpawnField(temp_s1, int*, 4);
                        tailByte = Level42SpawnRandBetween(upper >> 1, upper);
                    }
                    scratch16 <<= 1;
                    {
                        register int component __asm__("$3") =
                            Level42SpawnField(Level42SpawnD_80065920 + scratch16, short*, 0);
                        register int low8 __asm__("$9") = component * tailByte;
                        MATCHING_KEEP2(low8, tailByte);
                        component = low8 >> 12;
                        frame.spF8 = component;
                    }
                    {
                        register int component __asm__("$3") =
                            Level42SpawnField(Level42SpawnD_800658A0 + scratch16, short*, 0);
                        register int low9 __asm__("$8") = component * tailByte;
                        register void* third __asm__("$6") = reference + 12;
                        register void* first __asm__("$4");
                        register void* second __asm__("$5");
                        scratch16 = (int)&frame.spF8;
                        first = (void*)scratch16;
                        second = first;
                        frame.sp100 = 0;
                        MATCHING_KEEP4(low9, third, first, second);
                        tailByte = low9 >> 12;
                        frame.spFC = tailByte;
                        Level42SpawnAddVector(first, second, third);
                    }
                    Level42SpawnPackVectorShiftRight2(record + 4, (void*)scratch16);
                    {
                        register int value3 __asm__("$3") =
                            Level42SpawnField(record, unsigned short*, 4);
                        register int value2 __asm__("$2") =
                            Level42SpawnField(record, unsigned short*, 8);
                        register int value4 __asm__("$4") =
                            Level42SpawnField(record, unsigned short*, 6);
                        MATCHING_KEEP3(value3, value2, value4);
                        value2 += 96;
                        Level42SpawnField(record, volatile unsigned short*, 10) = value3;
                        Level42SpawnField(record, volatile unsigned short*, 12) = value4;
                        Level42SpawnField(record, volatile unsigned short*, 14) = value2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value3 = Level42SpawnField(reference, int*, 20);
                        value4 = Level42SpawnField(temp_s1, int*, 0);
                        __asm__ volatile(""
                                         : "=r"(value3), "=r"(value4)
                                         : "0"(value3), "1"(value4)
                                         : "$2", "memory");
                        tailByte = 112;
                        MATCHING_KEEP3_CLOBBER(value3, value4, tailByte, "memory");
                        Level42SpawnField(record, unsigned char*, 16) = tailByte;
                        Level42SpawnField(record, unsigned char*, 17) = tailByte;
                        tailByte = 224;
                        Level42SpawnField(record, unsigned char*, 18) = tailByte;
                        Level42SpawnField(record, unsigned char*, 20) = tailByte;
                        Level42SpawnField(record, unsigned char*, 21) = tailByte;
                        tailByte = 80;
                        Level42SpawnField(record, unsigned char*, 22) = byte255;
                        Level42SpawnField(record, unsigned char*, 19) = tailByte;
                        Level42SpawnField(record, unsigned char*, 23) = 0;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(value3, value4, "memory");
                        value3 += value4;
                        value3 >>= 2;
                        Level42SpawnField(record, int*, 24) = value3;
                    }
                    break;
            }
            MATCHING_KEEP_VOLATILE_CLOBBER(byte255, "memory");
            {
                register int stride8 __asm__("$9") = frame.sp128;
                register int iteration9 __asm__("$8") = frame.sp110;
                MATCHING_KEEP2(stride8, iteration9);
                stride8 += 4;
                frame.sp128 = stride8;
                stride8 = frame.sp108;
                MATCHING_KEEP2(stride8, iteration9);
                iteration9 += 1;
                var_v0 = iteration9 < stride8;
                __asm__ volatile(""
                                 : "=r"(var_v0), "=r"(iteration9)
                                 : "0"(var_v0), "1"(iteration9)
                                 : "$3", "memory");
                frame.sp110 = iteration9;
            }
        } while (var_v0);
    }
    return record;
}

#undef Level42SpawnField

#undef Level42SpawnHigh
