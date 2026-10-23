#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"

#define Cutscene75B44High(a, b)                                                      \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Cutscene75B44Color1[] __asm__("D_80066BAC");
extern unsigned char Cutscene75B44Color2[] __asm__("D_80066BAC");
#define Cutscene75B44Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Cutscene75B44BuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Cutscene75B44TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Cutscene75B44ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Cutscene75B44CopyVector(void*, void*) __asm__("func_8004F178");
int Cutscene75B44AddVector(void*, void*, void*) __asm__("func_8004F194");
int Cutscene75B44MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Cutscene75B44PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Cutscene75B44AllocateParticleRecord(int) __asm__("func_80056434");
int Cutscene75B44InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
typedef struct {
    unsigned char raw[88];
} Cutscene75B44RawRecord;
extern Cutscene75B44RawRecord* Cutscene75B44Records __asm__("D_8006C550");
int Cutscene75B44rand(void) __asm__("rand");
extern unsigned char Cutscene75B44D_800658A0[] __asm__("D_800658A0");
extern unsigned char Cutscene75B44D_80065920[] __asm__("D_80065920");
extern unsigned char Cutscene75B44D_80066A28[] __asm__("D_80066A28");
extern unsigned char Cutscene75B44D_80066A48[] __asm__("D_80066A48");
extern unsigned char Cutscene75B44D_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Cutscene75B44D_80070328[] __asm__("D_80070328");
extern int Cutscene75B44D_8006E344 __asm__("D_8006E344");
/* AI-generated; not human reviewed. Original USA Rev0 cutscene70 instructions
 * and dispatch: build/sibling4172.func_cutscene_70_80075B44.json.
 * Raw units, helper contracts and cadence remain unresolved. */
void* func_cutscene_70_80075B44(int entryCount, int kind, void* input, void* mode) {
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
        unsigned char sp80, sp81, sp82, pad83;
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
        volatile int spD8;
        int spDC;
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
    register int commonByte __asm__("$8");
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
        frame.spD8 = 0;
        do {
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$9");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = one;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B44PackVectorShiftRight2(record + 0x18, modeSelector);
                    Cutscene75B44Field(record, short*, 0x1E) = 0;
                    Cutscene75B44Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Cutscene75B44rand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$3", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Cutscene75B44Field(record, unsigned char*, 0xC) = byte128;
                        Cutscene75B44Field(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                        Cutscene75B44Field(record, unsigned char*, 0xE) = byte128;
                    }

                    MATCHING_KEEP_VOLATILE_CLOBBER(commonByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 15) = commonByte;
                    goto initializeTrailingBytes;
                case 0x1: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B44PackVectorShiftRight2(record + 0x18, modeSelector);
                    Cutscene75B44Field(record, short*, 0x1E) = 0;
                    Cutscene75B44Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Cutscene75B44rand();
                    Cutscene75B44Field(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 0xC) = tailByte;
                    Cutscene75B44Field(record, unsigned char*, 0xD) = tailByte;
                    Cutscene75B44Field(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    goto initializeF9;
                case 0x2:
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                        tailByte = Cutscene75B44rand();
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp10 = tailByte;
                        tailByte = Cutscene75B44rand();
                        destination = record + 24;
                        source = &frame.sp10;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        frame.sp14 = tailByte;
                        frame.sp18 = 16;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Cutscene75B44Field(record, unsigned short*, 30) = 0;
                    Cutscene75B44Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Cutscene75B44rand();
                    commonByte = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte, tailByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Cutscene75B44Field(record, unsigned char*, 12) = byte128;
                    Cutscene75B44Field(record, unsigned char*, 13) = byte128;
                    Cutscene75B44Field(record, unsigned char*, 14) = byte128;
                    Cutscene75B44Field(record, unsigned char*, 15) = commonByte;
                    goto initializeTrailingBytes;
                case 0x9: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* playerVector __asm__("$16") = &frame.sp20;
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Cutscene75B44D_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44CopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            Cutscene75B44PackVectorShiftRight2(destination, source);
                        }
                        Cutscene75B44CopyVector(playerVector, player + 0x98);
                        Cutscene75B44ShiftVectorRightTowardZero(playerVector, 6);
                        Cutscene75B44PackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Cutscene75B44Field(record, short*, 0x1E) = 0;
                    Cutscene75B44Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Cutscene75B44rand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$4", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte9 = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");

                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Cutscene75B44Field(record, unsigned char*, 0xC) = byte128;
                        Cutscene75B44Field(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$4", "memory");
                        Cutscene75B44Field(record, unsigned char*, 0xE) = byte128;
                    }

                    goto initializeF9;
                case 0xA: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(3);
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Cutscene75B44D_80070328;
                        tailByte = Cutscene75B44rand();
                        destination = record + 4;
                        source = Cutscene75B44D_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
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
                        Cutscene75B44Field(record, unsigned char*, 10) = value;
                        value = 15;
                        Cutscene75B44Field(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.spB0;
                        iteration8 = frame.spB8;
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = frame.spD8;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Cutscene75B44D_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Cutscene75B44High(dividend, factor);
                        Cutscene75B44Field(record, unsigned char*, 12) = value;
                        value = *(Cutscene75B44Color1 + 1 + count);
                        dividend >>= 31;
                        Cutscene75B44Field(record, unsigned char*, 13) = value;
                        color = *(Cutscene75B44Color2 + 2 + count);
                        value = 44;
                        Cutscene75B44Field(record, unsigned char*, 15) = value;
                        value = 4;
                        Cutscene75B44Field(record, unsigned char*, 17) = value;
                        Cutscene75B44Field(record, unsigned char*, 16) = 0;
                        Cutscene75B44Field(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Cutscene75B44Field(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register void* table __asm__("$5");
                        register int offset __asm__("$8");
                        register void* vector __asm__("$6");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination)
                                : "0"(destination)
                                : "$5", "$8", "$6", "$2", "memory");
                        table = Cutscene75B44D_80066A48;
                        offset = frame.spD0;
                        vector = frame.spC0;
                        __asm__(""
                                : "=r"(table), "=r"(offset), "=r"(vector)
                                : "0"(table), "1"(offset), "2"(vector)
                                : "$2", "memory");
                        value = 1;
                        Cutscene75B44Field(record, unsigned char*, 3) = value;
                        value = 4;
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 17) = value;
                        MATCHING_KEEP4_CLOBBER(destination, table, offset, vector, "memory");
                        table = (void*)(offset + (int)table);
                        Cutscene75B44TransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Cutscene75B44Field(reference, short*, 54);
                            register int expected __asm__("$9");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Cutscene75B44MultiplyVectorGpfSf0(frame.spC0, frame.spC0, 3);
                    }
                    Cutscene75B44AddVector(frame.spC0, frame.spC0, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                    if (Cutscene75B44Field(reference, short*, 0x36) == 0xB6) {
                        frame.sp38 += 0x200;
                    }
                    Cutscene75B44PackVectorShiftRight2(record + 4, frame.spC0);
                    Cutscene75B44Field(record, int*, 0xC) =
                        (int)*(int*)(Cutscene75B44D_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Cutscene75B44Field(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Cutscene75B44rand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Cutscene75B44rand() & 7) + 0x20;
                    }
                    Cutscene75B44Field(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Cutscene75B44rand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int offset __asm__("$9") = frame.spD0;
                        register void* source __asm__("$5");
                        __asm__("" : "=r"(destination) : "0"(destination) : "$5", "memory");
                        source = Cutscene75B44D_80066A48;
                        MATCHING_KEEP4_CLOBBER(destination, offset, source, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 11) = tailByte;
                        Cutscene75B44Field(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP3_CLOBBER(destination, offset, source, "memory");
                        source = (void*)(offset + (int)source);
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B44Field(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Cutscene75B44Field(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Cutscene75B44rand() & 7));
                    Cutscene75B44Field(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Cutscene75B44Field(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Cutscene75B44rand() & 7));
                    Cutscene75B44Field(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Cutscene75B44Field(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Cutscene75B44rand() & 7));
                    break;
                case 0xd:
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B44PackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Cutscene75B44Field(record, short*, 0x1E) = 0;
                    Cutscene75B44Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Cutscene75B44rand();
                    commonByte = 46;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$3", "memory");
                    Cutscene75B44Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Cutscene75B44Field(record, unsigned char*, 12) = byte255;
                    Cutscene75B44Field(record, unsigned char*, 13) = byte255;
                    Cutscene75B44Field(record, unsigned char*, 14) = 0;
                    __asm__ volatile(""
                                     : "=r"(commonByte), "=r"(tailByte)
                                     : "0"(commonByte), "1"(tailByte)
                                     : "$4", "memory");
                    Cutscene75B44Field(record, unsigned char*, 15) = commonByte;
                    goto initializeTrailingBytes;
                case 0x21: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B44Field(record, unsigned char*, 2) = 0;
                    Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp50;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Cutscene75B44D_80070328 + 0x98;
                            Cutscene75B44CopyVector(destination, temp_s1);
                        }
                        Cutscene75B44ShiftVectorRightTowardZero((void*)scratch16, 6);
                        Cutscene75B44CopyVector(&frame.sp40, temp_s1 - 0x98);
                        frame.sp48 -= 0x164;
                        {
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                            register int random __asm__("$2") = Cutscene75B44rand();
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
                        register int two __asm__("$2");
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Cutscene75B44D_80070328 + 0x30;
                            frame.sp40 = 0x164;
                            frame.sp44 = 0;
                            frame.sp48 = 0;
                            Cutscene75B44TransformVectorByBasis(temp_s1_2, &frame.sp40,
                                                                &frame.sp40);
                            Cutscene75B44AddVector(&frame.sp40, &frame.sp40, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp50 = -(Cutscene75B44rand() & 7);
                            {
                                register int random __asm__("$2") = Cutscene75B44rand();
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
                                component = *(unsigned short*)(Cutscene75B44D_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp54 = component;
                                random = *(unsigned short*)(Cutscene75B44D_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp58 = random;
                                Cutscene75B44TransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else {
                            two = 2;
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
                    Cutscene75B44CopyVector(&frame.sp40, Cutscene75B44D_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Cutscene75B44D_80065920;
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
                        value = (int)Cutscene75B44D_800658A0;
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
                    Cutscene75B44PackVectorShiftRight2(var_a0, &frame.sp40);
                    Cutscene75B44PackVectorShiftRight2(record + 0x18, &frame.sp50);
                    Cutscene75B44Field(record, short*, 0x1E) = 0;
                    Cutscene75B44Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Cutscene75B44rand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Cutscene75B44Field(record, unsigned char*, 0xC) = scratch19;
                    Cutscene75B44Field(record, unsigned char*, 0xD) = scratch19;
                    Cutscene75B44Field(record, unsigned char*, 0xE) = scratch19;
                    goto initializeF9;
                case 0x25:
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* first __asm__("$4") = reference;
                        register int second __asm__("$5") = 0;
                        register void* third __asm__("$6");
                        scratch16 = (int)&frame.sp60;
                        third = (void*)scratch16;
                        tailByte = 1;
                        MATCHING_KEEP5_CLOBBER(first, second, third, tailByte, scratch16, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44InterpolateMobyVertex(first, second, third);
                    }
                    Cutscene75B44PackVectorShiftRight2(record + 4, (void*)scratch16);
                    Cutscene75B44PackVectorShiftRight2(record + 24, modeSelector);
                    {
                        register Cutscene75B44RawRecord* base __asm__("$4") = Cutscene75B44Records;
                        tailByte = 64;
                        Cutscene75B44Field(record, unsigned char*, 10) = tailByte;
                        tailByte = (Cutscene75B44RawRecord*)reference - base;
                        Cutscene75B44Field(record, short*, 30) = tailByte;
                    }
                    tailByte = Cutscene75B44rand();
                    commonByte = 46;
                    MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, commonByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 11) = tailByte;
                    Cutscene75B44Field(record, unsigned char*, 12) = byte255;
                    Cutscene75B44Field(record, unsigned char*, 13) = byte255;
                    Cutscene75B44Field(record, unsigned char*, 14) = 0;
                    Cutscene75B44Field(record, unsigned char*, 15) = commonByte;
                    Cutscene75B44Field(record, unsigned char*, 17) = 0;
                    Cutscene75B44Field(record, unsigned char*, 16) = 0;
                    break;
                case 0x3B: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Cutscene75B44Field(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Cutscene75B44Field(record, unsigned char*, 3) = value;
                        value = 16;
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Cutscene75B44Field(record, unsigned char*, 1) = flags;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3") =
                            Cutscene75B44Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Cutscene75B44Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3") =
                            Cutscene75B44Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Cutscene75B44Field(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Cutscene75B44Field(record, int*, 12) = var_v0;
                    Cutscene75B44Field(record, unsigned char*, 0xA) =
                        (unsigned char)((Cutscene75B44rand() & 0xF) + 0x14);
                    Cutscene75B44Field(record, unsigned char*, 0xB) = Cutscene75B44rand();
                    Cutscene75B44Field(record, unsigned char*, 0x10) = 0;
                    Cutscene75B44Field(record, short*, 0x18) =
                        (short)((Cutscene75B44rand() & 7) - 4);
                    Cutscene75B44Field(record, short*, 0x1A) =
                        (short)(-2 - (Cutscene75B44rand() & 7));
                    Cutscene75B44Field(record, short*, 0x1C) =
                        (short)((Cutscene75B44rand() & 0xF) - 8);
                    break;
                case 0x3D:
                    record = Cutscene75B44AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B44Field(record, unsigned char*, 2) = 0;
                        Cutscene75B44Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B44PackVectorShiftRight2(destination, source);
                    }
                    tailByte = 72;
                    Cutscene75B44Field(record, short*, 30) = 0;
                    Cutscene75B44Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Cutscene75B44rand();
                    {
                        register int mask __asm__("$3") = -128;
                        MATCHING_KEEP2_CLOBBER(mask, tailByte, "memory");
                        Cutscene75B44Field(record, unsigned char*, 11) = tailByte;
                        tailByte = (int)modeSelector & mask;
                        Cutscene75B44Field(record, unsigned char*, 12) = tailByte;
                        tailByte = (int)modeSelector >> 8;
                        tailByte &= mask;
                        commonByte9 = 46;
                        MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                        Cutscene75B44Field(record, unsigned char*, 13) = tailByte;
                        tailByte = 8;
                        Cutscene75B44Field(record, unsigned char*, 14) = 0;
                    }
                initializeF9:
                    Cutscene75B44Field(record, unsigned char*, 15) = commonByte9;
                initializeTrailingBytes:
                    Cutscene75B44Field(record, unsigned char*, 17) = tailByte;
                    Cutscene75B44Field(record, unsigned char*, 16) = 0;
                    break;
                case 0x42: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(0);
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B44Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B44rand() & 0xF);
                    Cutscene75B44Field(record, unsigned char*, 3) = 1;
                    Cutscene75B44Field(record, short*, 4) =
                        (short)((((int)Cutscene75B44Field(reference, int*, 0) >> 2) +
                                 (Cutscene75B44rand() & 0xF)) -
                                8);
                    Cutscene75B44Field(record, short*, 6) =
                        (short)((((int)Cutscene75B44Field(reference, int*, 4) >> 2) +
                                 (Cutscene75B44rand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3") =
                            Cutscene75B44Field(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Cutscene75B44Field(record, short*, 16) = 0;
                        Cutscene75B44Field(record, short*, 18) = 0;
                        Cutscene75B44Field(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Cutscene75B44Field(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Cutscene75B44D_8006E344;
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
                        Cutscene75B44Field(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Cutscene75B44Field(Cutscene75B44D_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Cutscene75B44rand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Cutscene75B44Field(record, unsigned char*, 0xC) = byte255;
                            Cutscene75B44Field(record, unsigned char*, 0xD) = 0;
                            Cutscene75B44Field(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Cutscene75B44Field(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Cutscene75B44Field(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Cutscene75B44Field(record, unsigned char*, 13) = byte255;
                            Cutscene75B44Field(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Cutscene75B44Field(record, unsigned char*, 0xC) = 0;
                            Cutscene75B44Field(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Cutscene75B44Field(record, unsigned char*, 0xC) = 0;
                            Cutscene75B44Field(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Cutscene75B44Field(record, unsigned char*, 0xC) = byte255;
                            Cutscene75B44Field(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            MATCHING_KEEP(byte128);
                            Cutscene75B44Field(record, unsigned char*, 12) = byte255;
                            Cutscene75B44Field(record, unsigned char*, 13) = byte128;
                        }
                            Cutscene75B44Field(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            MATCHING_KEEP(byte128);
                            Cutscene75B44Field(record, unsigned char*, 12) = 0;
                            Cutscene75B44Field(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Cutscene75B44Field(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Cutscene75B44Field(record, unsigned char*, 0xF) = 0x40;
                    break;
                case 0x46: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(1);
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B44Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B44rand() & 0xF);
                    Cutscene75B44Field(record, unsigned char*, 3) = 1;
                    frame.sp80 = 0;
                    frame.sp81 = Cutscene75B44rand();
                    frame.sp82 = Cutscene75B44rand();
                    Cutscene75B44BuildPackedAngleBasisMatrix(&frame.sp80, &frame.sp88, 0);
                    frame.sp70 = (int)modeSelector;
                    frame.sp74 = 0;
                    frame.sp78 = 0;
                    Cutscene75B44TransformVectorByBasis(&frame.sp88, (unsigned char*)&frame.sp70,
                                                        (unsigned char*)&frame.sp70);
                    Cutscene75B44Field(record, unsigned short*, 4) =
                        (unsigned short)((int)Cutscene75B44Field(reference, int*, 0) >> 2);
                    Cutscene75B44Field(record, unsigned short*, 6) =
                        (unsigned short)((int)Cutscene75B44Field(reference, int*, 4) >> 2);
                    Cutscene75B44Field(record, unsigned short*, 8) =
                        (unsigned short)((int)Cutscene75B44Field(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.sp70;
                        register int other __asm__("$3") =
                            Cutscene75B44Field(record, unsigned short*, 4);

                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Cutscene75B44Field(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.sp74;
                        other = Cutscene75B44Field(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Cutscene75B44Field(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.sp78;
                        value = 2;
                        Cutscene75B44Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Cutscene75B44Field(record, unsigned char*, 16) = value;
                        value = 192;
                        Cutscene75B44Field(record, unsigned char*, 17) = value;
                        value = 80;
                        Cutscene75B44Field(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Cutscene75B44Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");

                        MATCHING_KEEP(byte128);
                        Cutscene75B44Field(record, unsigned char*, 18) = 0;
                        Cutscene75B44Field(record, unsigned char*, 20) = byte255;
                        Cutscene75B44Field(record, unsigned char*, 21) = byte255;
                        Cutscene75B44Field(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Cutscene75B44Field(record, short*, 14) = value;
                    }
                    break;
                case 0x47: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(1);
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B44Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B44rand() & 7);
                    Cutscene75B44Field(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Cutscene75B44rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spA0 = temp_v0_4;
                    temp_v0_5 = (int)(((Cutscene75B44rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spA4 = temp_v0_5;
                    temp_v0_6 = (int)(((Cutscene75B44rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.spA8 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Cutscene75B44Field(reference, int*, 0);
                        value = frame.spA0;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Cutscene75B44Field(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Cutscene75B44Field(reference, int*, 4);
                        value = frame.spA4;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Cutscene75B44Field(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Cutscene75B44Field(reference, int*, 8);
                        value = frame.spA8;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Cutscene75B44Field(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.spA0;
                        register int value __asm__("$2") =
                            Cutscene75B44Field(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Cutscene75B44Field(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.spA4;
                        value = Cutscene75B44Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Cutscene75B44Field(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.spA8;
                        other = Cutscene75B44Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Cutscene75B44Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Cutscene75B44Field(record, unsigned char*, 16) = value;
                        Cutscene75B44Field(record, unsigned char*, 17) = value;
                        value = 96;
                        Cutscene75B44Field(record, unsigned char*, 18) = value;
                        Cutscene75B44Field(record, unsigned char*, 20) = byte255;
                        Cutscene75B44Field(record, unsigned char*, 21) = byte255;
                        Cutscene75B44Field(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Cutscene75B44Field(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Cutscene75B44Field(record, short*, 14) = other;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(0);
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B44Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B44rand() & 0x1F);
                    Cutscene75B44Field(record, unsigned char*, 3) = 1;
                    Cutscene75B44PackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3") =
                            Cutscene75B44Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Cutscene75B44Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3") =
                            Cutscene75B44Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Cutscene75B44Field(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3") =
                            Cutscene75B44Field(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Cutscene75B44Field(record, unsigned short*, 8) = component;
                    }
                    Cutscene75B44Field(record, short*, 0x10) =
                        (short)((Cutscene75B44rand() & 2) - 1);
                    Cutscene75B44Field(record, short*, 0x12) =
                        (short)((Cutscene75B44rand() & 2) - 1);
                    Cutscene75B44Field(record, short*, 0x14) = (short)-(Cutscene75B44rand() & 1);
                    tailByte = Cutscene75B44rand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B44Field(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Cutscene75B44rand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Cutscene75B44Field(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Cutscene75B44Field(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Cutscene75B44Field(record, unsigned char*, 13) = component;
                    }
                    Cutscene75B44Field(record, unsigned char*, 0xE) =
                        (unsigned char)((Cutscene75B44rand() & 0x3F) + 0x40);
                    Cutscene75B44Field(record, unsigned char*, 0xF) = 0x40;
                    Cutscene75B44Field(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                    record = Cutscene75B44AllocateParticleRecord(1);
                    Cutscene75B44Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B44Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B44rand() & 0xF);
                    Cutscene75B44Field(record, unsigned char*, 3) = 1;
                    Cutscene75B44PackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.spA0;
                        MATCHING_KEEP(vector);
                        Cutscene75B44AddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Cutscene75B44rand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&frame.spA0;
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            frame.spA0 = component;
                        }

                        {
                            register int random __asm__("$2") = Cutscene75B44rand();
                            register int component __asm__("$3") = frame.spA4;

                            random &= 0x3F;

                            component -= 0x20;

                            component += random;
                            frame.spA4 = component;
                        }

                        {
                            register int random __asm__("$2") = Cutscene75B44rand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;

                            component = frame.spA8;

                            random &= 0x7F;

                            component -= 0x40;

                            component += random;
                            frame.spA8 = component;
                            Cutscene75B44PackVectorShiftRight2(destination, source);
                        }
                    }
                    Cutscene75B44Field(record, unsigned char*, 0x17) = 2;
                    tailByte = Cutscene75B44rand();
                    tailByte |= 192;

                    Cutscene75B44Field(record, unsigned char*, 16) = tailByte;
                    Cutscene75B44Field(record, unsigned char*, 0x11) =
                        (unsigned char)((Cutscene75B44rand() & 0x3F) - 0x60);
                    Cutscene75B44Field(record, unsigned char*, 0x12) = 0;
                    tailByte = Cutscene75B44rand();
                    tailByte |= 224;

                    Cutscene75B44Field(record, unsigned char*, 20) = tailByte;
                    tailByte = Cutscene75B44rand();
                    tailByte |= 224;

                    Cutscene75B44Field(record, unsigned char*, 21) = tailByte;
                    {

                        Cutscene75B44Field(record, unsigned char*, 0x16) = byte128;
                    }
                    Cutscene75B44Field(record, unsigned char*, 0x13) = 0x50;
                    break;
            }
            {
                register int stride9 __asm__("$9") = frame.spD0;
                register int stride8 __asm__("$8") = frame.spD8;
                MATCHING_KEEP2(stride9, stride8);
                stride9 += 12;
                frame.spD0 = stride9;
                stride9 = frame.spB8;
                MATCHING_KEEP2_CLOBBER(stride9, stride8, "memory");
                stride8 += 4;
                frame.spD8 = stride8;
                stride8 = frame.spB0;
                MATCHING_KEEP2(stride8, stride9);
                stride9 += 1;
                var_v0 = stride9 < stride8;
                __asm__ volatile(""
                                 : "=r"(var_v0), "=r"(stride9)
                                 : "0"(var_v0), "1"(stride9)
                                 : "$3", "memory");
                frame.spB8 = stride9;
            }
        } while (var_v0);
    }
    return record;
}

#undef Cutscene75B44Field

#undef Cutscene75B44High
