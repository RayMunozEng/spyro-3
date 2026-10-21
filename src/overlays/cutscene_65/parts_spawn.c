#include "matching.h"
#include "common.h"

#define Cutscene75B88High(a, b)                                                      \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Cutscene75B88Color1[] __asm__("D_80066BAC");
extern unsigned char Cutscene75B88Color2[] __asm__("D_80066BAC");
#define Cutscene75B88Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Cutscene75B88func_8004EA90(void*, void*, int) __asm__("func_8004EA90");
int Cutscene75B88TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Cutscene75B88ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Cutscene75B88CopyVector(void*, void*) __asm__("func_8004F178");
int Cutscene75B88AddVector(void*, void*, void*) __asm__("func_8004F194");
int Cutscene75B88MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Cutscene75B88PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Cutscene75B88func_80056434(int) __asm__("func_80056434");
int Cutscene75B88rand(void) __asm__("rand");
extern unsigned char Cutscene75B88D_800658A0[] __asm__("D_800658A0");
extern unsigned char Cutscene75B88D_80065920[] __asm__("D_80065920");
extern unsigned char Cutscene75B88D_80066A28[] __asm__("D_80066A28");
extern unsigned char Cutscene75B88D_80066A48[] __asm__("D_80066A48");
extern unsigned char Cutscene75B88D_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Cutscene75B88D_80070328[] __asm__("D_80070328");
extern int Cutscene75B88D_8006E344 __asm__("D_8006E344");
/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * The original 904 instructions and 88 owned dispatch words are the authority.
 * Field widths, byte offsets, integer arithmetic and case order retain the disc
 * representation. Physical units, selector semantics, helper contracts and
 * caller cadence remain unresolved. The loop advances once per input entry.
 * Signed high products reuse the existing drawutil.c MULT_HI compiler idiom.
 * Empty constraints emit no instructions; they retain compiler allocation
 * and scheduling. Acceptance requires unmasked linked words and all retail
 * hashes. These byte matches do not establish semantic runtime completeness.
 */
void* func_cutscene_65_80075704(int entryCount, int kind, void* input, void* mode) {
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
        int sp90;
        int pad94;
        int* volatile sp98;
        int pad9C, padA0, padA4;
        volatile int spA8;
        int padAC;
        volatile int spB0;
        int padB4;
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
    frame.sp90 = entryCount;
    if (entryCount > 0) {
        {
            register int* vectorBase __asm__("$8") = &frame.sp20;
            MATCHING_KEEP_CLOBBER(vectorBase, "$23");
            byte255 = 255;
            frame.sp98 = vectorBase;
        }
        frame.spA8 = 0;
        frame.spB0 = 0;
        do {
            switch (kindSelector) { /* switch 1 */
                case 0x0:           /* switch 1 */
                    record = Cutscene75B88func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$8");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B88Field(record, unsigned char*, 2) = 0;
                        Cutscene75B88Field(record, unsigned char*, 3) = one;
                        Cutscene75B88PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B88PackVectorShiftRight2(record + 0x18, modeSelector);
                    Cutscene75B88Field(record, short*, 0x1E) = 0;
                    Cutscene75B88Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Cutscene75B88rand();
                    {
                        register int byte128 __asm__("$8") = 128;
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$3", "memory");
                        Cutscene75B88Field(record, unsigned char*, 0xC) = byte128;
                        Cutscene75B88Field(record, unsigned char*, 0xD) = byte128;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        Cutscene75B88Field(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 46;
                        Cutscene75B88Field(record, unsigned char*, 0xF) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                        Cutscene75B88Field(record, unsigned char*, 0xE) = byte128;
                    }

                    goto initializeTrailingBytes;
                case 0x1: /* switch 1 */
                    record = Cutscene75B88func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B88Field(record, unsigned char*, 2) = 0;
                        Cutscene75B88Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B88PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B88PackVectorShiftRight2(record + 0x18, modeSelector);
                    Cutscene75B88Field(record, short*, 0x1E) = 0;
                    Cutscene75B88Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Cutscene75B88rand();
                    Cutscene75B88Field(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    Cutscene75B88Field(record, unsigned char*, 0xC) = tailByte;
                    Cutscene75B88Field(record, unsigned char*, 0xD) = tailByte;
                    Cutscene75B88Field(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 46;
                    Cutscene75B88Field(record, unsigned char*, 0xF) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    goto initializeTrailingBytes;
                case 0x9: /* switch 1 */
                    record = Cutscene75B88func_80056434(2);
                    {
                        register void* destination __asm__("$4") = &frame.sp10;
                        register unsigned char* player __asm__("$16");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$16");
                        player = Cutscene75B88D_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B88Field(record, unsigned char*, 2) = 0;
                        Cutscene75B88Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B88CopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            Cutscene75B88PackVectorShiftRight2(destination, source);
                        }
                        Cutscene75B88CopyVector(&frame.sp10, player + 0x98);
                        Cutscene75B88ShiftVectorRightTowardZero(&frame.sp10, 6);
                        Cutscene75B88PackVectorShiftRight2(record + 0x18, &frame.sp10);
                    }
                    Cutscene75B88Field(record, short*, 0x1E) = 0;
                    Cutscene75B88Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Cutscene75B88rand();
                    {
                        register int byte128 __asm__("$8") = 128;
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$4", "memory");
                        Cutscene75B88Field(record, unsigned char*, 0xC) = byte128;
                        Cutscene75B88Field(record, unsigned char*, 0xD) = byte128;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        Cutscene75B88Field(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 46;
                        Cutscene75B88Field(record, unsigned char*, 0xF) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$4", "memory");
                        Cutscene75B88Field(record, unsigned char*, 0xE) = byte128;
                    }

                    goto initializeTrailingBytes;
                case 0xA: /* switch 1 */
                    record = Cutscene75B88func_80056434(3);
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Cutscene75B88D_80070328;
                        tailByte = Cutscene75B88rand();
                        destination = record + 4;
                        source = Cutscene75B88D_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Cutscene75B88Field(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Cutscene75B88Field(record, unsigned char*, 3) = tailByte;
                        Cutscene75B88PackVectorShiftRight2(destination, source);
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
                        Cutscene75B88Field(record, unsigned char*, 10) = value;
                        value = 15;
                        Cutscene75B88Field(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = frame.sp90;
                        factor |= 0x6667;
                        dividend = count - iteration;
                        count = frame.spB0;
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Cutscene75B88D_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Cutscene75B88High(dividend, factor);
                        Cutscene75B88Field(record, unsigned char*, 12) = value;
                        value = *(Cutscene75B88Color1 + 1 + count);
                        dividend >>= 31;
                        Cutscene75B88Field(record, unsigned char*, 13) = value;
                        color = *(Cutscene75B88Color2 + 2 + count);
                        value = 44;
                        Cutscene75B88Field(record, unsigned char*, 15) = value;
                        value = 4;
                        Cutscene75B88Field(record, unsigned char*, 17) = value;
                        Cutscene75B88Field(record, unsigned char*, 16) = 0;
                        Cutscene75B88Field(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        count = productHigh;
                        MATCHING_KEEP(count);
                        value = (count >> 1) - dividend;
                        Cutscene75B88Field(record, short*, 24) = value;
                    }
                    break;
                case 0xC: /* switch 1 */
                    record = Cutscene75B88func_80056434(2);
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
                        table = Cutscene75B88D_80066A48;
                        offset = frame.spA8;
                        vector = frame.sp98;
                        __asm__(""
                                : "=r"(table), "=r"(offset), "=r"(vector)
                                : "0"(table), "1"(offset), "2"(vector)
                                : "$2", "memory");
                        value = 1;
                        Cutscene75B88Field(record, unsigned char*, 3) = value;
                        value = 4;
                        Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B88Field(record, unsigned char*, 17) = value;
                        MATCHING_KEEP4_CLOBBER(destination, table, offset, vector, "memory");
                        table = (void*)(offset + (int)table);
                        Cutscene75B88TransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Cutscene75B88Field(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Cutscene75B88MultiplyVectorGpfSf0(frame.sp98, frame.sp98, 3);
                    }
                    Cutscene75B88AddVector(frame.sp98, frame.sp98, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                    if (Cutscene75B88Field(reference, short*, 0x36) == 0xB6) {
                        frame.sp28 += 0x200;
                    }
                    Cutscene75B88PackVectorShiftRight2(record + 4, frame.sp98);
                    Cutscene75B88Field(record, int*, 0xC) =
                        (int)*(int*)(Cutscene75B88D_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Cutscene75B88Field(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Cutscene75B88rand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Cutscene75B88rand() & 7) + 0x20;
                    }
                    Cutscene75B88Field(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Cutscene75B88rand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int offset __asm__("$8") = frame.spA8;
                        register void* source __asm__("$5");
                        __asm__("" : "=r"(destination) : "0"(destination) : "$5", "memory");
                        source = Cutscene75B88D_80066A48;
                        MATCHING_KEEP4_CLOBBER(destination, offset, source, tailByte, "memory");
                        Cutscene75B88Field(record, unsigned char*, 11) = tailByte;
                        Cutscene75B88Field(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP3_CLOBBER(destination, offset, source, "memory");
                        source = (void*)(offset + (int)source);
                        Cutscene75B88PackVectorShiftRight2(destination, source);
                    }
                    Cutscene75B88Field(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Cutscene75B88Field(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Cutscene75B88rand() & 7));
                    Cutscene75B88Field(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Cutscene75B88Field(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Cutscene75B88rand() & 7));
                    Cutscene75B88Field(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Cutscene75B88Field(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Cutscene75B88rand() & 7));
                    break;
                case 0x21: /* switch 1 */
                    record = Cutscene75B88func_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B88Field(record, unsigned char*, 2) = 0;
                    Cutscene75B88Field(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&frame.sp40;
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Cutscene75B88D_80070328 + 0x98;
                            Cutscene75B88CopyVector(destination, temp_s1);
                        }
                        Cutscene75B88ShiftVectorRightTowardZero((void*)scratch16, 6);
                        Cutscene75B88CopyVector(&frame.sp30, temp_s1 - 0x98);
                        frame.sp38 -= 0x164;
                        {
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            temp_s1_2 = Cutscene75B88D_80070328 + 0x30;
                            frame.sp30 = 0x164;
                            frame.sp34 = 0;
                            frame.sp38 = 0;
                            Cutscene75B88TransformVectorByBasis(temp_s1_2, &frame.sp30,
                                                                &frame.sp30);
                            Cutscene75B88AddVector(&frame.sp30, &frame.sp30, temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            frame.sp40 = -(Cutscene75B88rand() & 7);
                            {
                                register int random __asm__("$2") = Cutscene75B88rand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") = temp_s1_2;
                                register void* vector __asm__("$5") = &frame.sp40;
                                register int angle __asm__("$7") = iteration << 6;
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP4_CLOBBER(destination, vector, angle, output,
                                                       "memory");
                                random &= 15;
                                component = *(unsigned short*)(Cutscene75B88D_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                frame.sp44 = component;
                                random = *(unsigned short*)(Cutscene75B88D_800658A0 + angle);
                                random = (random << 16) >> 23;
                                frame.sp48 = random;
                                Cutscene75B88TransformVectorByBasis(destination, vector, output);
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
                    Cutscene75B88CopyVector(&frame.sp30, Cutscene75B88D_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Cutscene75B88D_80065920;
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
                        value = (int)Cutscene75B88D_800658A0;
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
                    Cutscene75B88PackVectorShiftRight2(var_a0, &frame.sp30);
                    Cutscene75B88PackVectorShiftRight2(record + 0x18, &frame.sp40);
                    Cutscene75B88Field(record, short*, 0x1E) = 0;
                    Cutscene75B88Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Cutscene75B88rand();
                    Cutscene75B88Field(record, unsigned char*, 11) = tailByte;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    tailByte = 46;
                    MATCHING_KEEP(tailByte);
                    Cutscene75B88Field(record, unsigned char*, 15) = tailByte;
                    Cutscene75B88Field(record, unsigned char*, 0xC) = scratch19;
                    Cutscene75B88Field(record, unsigned char*, 0xD) = scratch19;
                    Cutscene75B88Field(record, unsigned char*, 0xE) = scratch19;
                    tailByte = 4;
                initializeTrailingBytes:
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                    Cutscene75B88Field(record, unsigned char*, 0x11) = tailByte;
                    Cutscene75B88Field(record, unsigned char*, 0x10) = 0;
                    break;
                case 0x3B: /* switch 1 */
                    record = Cutscene75B88func_80056434(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Cutscene75B88Field(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Cutscene75B88Field(record, unsigned char*, 3) = value;
                        value = 16;
                        Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                        Cutscene75B88Field(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Cutscene75B88Field(record, unsigned char*, 1) = flags;
                        Cutscene75B88PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3") =
                            Cutscene75B88Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Cutscene75B88Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3") =
                            Cutscene75B88Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Cutscene75B88Field(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Cutscene75B88Field(record, int*, 12) = var_v0;
                    Cutscene75B88Field(record, unsigned char*, 0xA) =
                        (unsigned char)((Cutscene75B88rand() & 0xF) + 0x14);
                    Cutscene75B88Field(record, unsigned char*, 0xB) = Cutscene75B88rand();
                    Cutscene75B88Field(record, unsigned char*, 0x10) = 0;
                    Cutscene75B88Field(record, short*, 0x18) =
                        (short)((Cutscene75B88rand() & 7) - 4);
                    Cutscene75B88Field(record, short*, 0x1A) =
                        (short)(-2 - (Cutscene75B88rand() & 7));
                    Cutscene75B88Field(record, short*, 0x1C) =
                        (short)((Cutscene75B88rand() & 0xF) - 8);
                    break;
                case 0x42: /* switch 1 */
                    record = Cutscene75B88func_80056434(0);
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B88Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B88rand() & 0xF);
                    Cutscene75B88Field(record, unsigned char*, 3) = 1;
                    Cutscene75B88Field(record, short*, 4) =
                        (short)((((int)Cutscene75B88Field(reference, int*, 0) >> 2) +
                                 (Cutscene75B88rand() & 0xF)) -
                                8);
                    Cutscene75B88Field(record, short*, 6) =
                        (short)((((int)Cutscene75B88Field(reference, int*, 4) >> 2) +
                                 (Cutscene75B88rand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3") =
                            Cutscene75B88Field(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Cutscene75B88Field(record, short*, 16) = 0;
                        Cutscene75B88Field(record, short*, 18) = 0;
                        Cutscene75B88Field(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Cutscene75B88Field(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Cutscene75B88D_8006E344;
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
                        Cutscene75B88Field(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Cutscene75B88Field(Cutscene75B88D_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Cutscene75B88rand() & 7;
                    switch (temp_v1_2) { /* switch 3 */
                        case 0:          /* switch 3 */
                            Cutscene75B88Field(record, unsigned char*, 0xC) = byte255;
                            Cutscene75B88Field(record, unsigned char*, 0xD) = 0;
                            Cutscene75B88Field(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Cutscene75B88Field(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Cutscene75B88Field(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Cutscene75B88Field(record, unsigned char*, 13) = byte255;
                            Cutscene75B88Field(record, unsigned char*, 14) = 0;
                            break;
                        case 3: /* switch 3 */
                            Cutscene75B88Field(record, unsigned char*, 0xC) = 0;
                            Cutscene75B88Field(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4: /* switch 3 */
                            Cutscene75B88Field(record, unsigned char*, 0xC) = 0;
                            Cutscene75B88Field(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5: /* switch 3 */
                            Cutscene75B88Field(record, unsigned char*, 0xC) = byte255;
                            Cutscene75B88Field(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            register int byte128 __asm__("$8") = 128;
                            MATCHING_KEEP(byte128);
                            Cutscene75B88Field(record, unsigned char*, 12) = byte255;
                            Cutscene75B88Field(record, unsigned char*, 13) = byte128;
                        }
                            Cutscene75B88Field(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            register int byte128 __asm__("$8") = 128;
                            MATCHING_KEEP(byte128);
                            Cutscene75B88Field(record, unsigned char*, 12) = 0;
                            Cutscene75B88Field(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Cutscene75B88Field(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Cutscene75B88Field(record, unsigned char*, 0xF) = 0x40;
                    break;
                case 0x46: /* switch 1 */
                    record = Cutscene75B88func_80056434(1);
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B88Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B88rand() & 0xF);
                    Cutscene75B88Field(record, unsigned char*, 3) = 1;
                    frame.sp60 = 0;
                    frame.sp61 = Cutscene75B88rand();
                    frame.sp62 = Cutscene75B88rand();
                    Cutscene75B88func_8004EA90(&frame.sp60, &frame.sp68, 0);
                    frame.sp50 = modeSelector;
                    frame.sp54 = 0;
                    frame.sp58 = 0;
                    Cutscene75B88TransformVectorByBasis(&frame.sp68, (unsigned char*)&frame.sp50,
                                                        (unsigned char*)&frame.sp50);
                    Cutscene75B88Field(record, unsigned short*, 4) =
                        (unsigned short)((int)Cutscene75B88Field(reference, int*, 0) >> 2);
                    Cutscene75B88Field(record, unsigned short*, 6) =
                        (unsigned short)((int)Cutscene75B88Field(reference, int*, 4) >> 2);
                    Cutscene75B88Field(record, unsigned short*, 8) =
                        (unsigned short)((int)Cutscene75B88Field(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = frame.sp50;
                        register int other __asm__("$3") =
                            Cutscene75B88Field(record, unsigned short*, 4);
                        register int byte128 __asm__("$8");
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Cutscene75B88Field(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = frame.sp54;
                        other = Cutscene75B88Field(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Cutscene75B88Field(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = frame.sp58;
                        value = 2;
                        Cutscene75B88Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Cutscene75B88Field(record, unsigned char*, 16) = value;
                        value = 192;
                        Cutscene75B88Field(record, unsigned char*, 17) = value;
                        value = 80;
                        Cutscene75B88Field(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Cutscene75B88Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");
                        byte128 = 128;
                        MATCHING_KEEP(byte128);
                        Cutscene75B88Field(record, unsigned char*, 18) = 0;
                        Cutscene75B88Field(record, unsigned char*, 20) = byte255;
                        Cutscene75B88Field(record, unsigned char*, 21) = byte255;
                        Cutscene75B88Field(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Cutscene75B88Field(record, short*, 14) = value;
                    }
                    break;
                case 0x47: /* switch 1 */
                    record = Cutscene75B88func_80056434(1);
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B88Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B88rand() & 7);
                    Cutscene75B88Field(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Cutscene75B88rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp80 = temp_v0_4;
                    temp_v0_5 = (int)(((Cutscene75B88rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp84 = temp_v0_5;
                    temp_v0_6 = (int)(((Cutscene75B88rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    frame.sp88 = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Cutscene75B88Field(reference, int*, 0);
                        value = frame.sp80;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Cutscene75B88Field(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Cutscene75B88Field(reference, int*, 4);
                        value = frame.sp84;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Cutscene75B88Field(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Cutscene75B88Field(reference, int*, 8);
                        value = frame.sp88;
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Cutscene75B88Field(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = frame.sp80;
                        register int value __asm__("$2") =
                            Cutscene75B88Field(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Cutscene75B88Field(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = frame.sp84;
                        value = Cutscene75B88Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Cutscene75B88Field(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = frame.sp88;
                        other = Cutscene75B88Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Cutscene75B88Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Cutscene75B88Field(record, unsigned char*, 16) = value;
                        Cutscene75B88Field(record, unsigned char*, 17) = value;
                        value = 96;
                        Cutscene75B88Field(record, unsigned char*, 18) = value;
                        Cutscene75B88Field(record, unsigned char*, 20) = byte255;
                        Cutscene75B88Field(record, unsigned char*, 21) = byte255;
                        Cutscene75B88Field(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Cutscene75B88Field(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Cutscene75B88Field(record, short*, 14) = other;
                    }
                    break;
                case 0x4E: /* switch 1 */
                    record = Cutscene75B88func_80056434(0);
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B88Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B88rand() & 0x1F);
                    Cutscene75B88Field(record, unsigned char*, 3) = 1;
                    Cutscene75B88PackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3") =
                            Cutscene75B88Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Cutscene75B88Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3") =
                            Cutscene75B88Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Cutscene75B88Field(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3") =
                            Cutscene75B88Field(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Cutscene75B88Field(record, unsigned short*, 8) = component;
                    }
                    Cutscene75B88Field(record, short*, 0x10) =
                        (short)((Cutscene75B88rand() & 2) - 1);
                    Cutscene75B88Field(record, short*, 0x12) =
                        (short)((Cutscene75B88rand() & 2) - 1);
                    Cutscene75B88Field(record, short*, 0x14) = (short)-(Cutscene75B88rand() & 1);
                    tailByte = Cutscene75B88rand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B88Field(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Cutscene75B88rand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Cutscene75B88Field(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Cutscene75B88Field(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Cutscene75B88Field(record, unsigned char*, 13) = component;
                    }
                    Cutscene75B88Field(record, unsigned char*, 0xE) =
                        (unsigned char)((Cutscene75B88rand() & 0x3F) + 0x40);
                    Cutscene75B88Field(record, unsigned char*, 0xF) = 0x40;
                    Cutscene75B88Field(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F: /* switch 1 */
                    record = Cutscene75B88func_80056434(1);
                    Cutscene75B88Field(record, unsigned char*, 0) = kindSelector;
                    Cutscene75B88Field(record, unsigned char*, 2) =
                        (unsigned char)(Cutscene75B88rand() & 0xF);
                    Cutscene75B88Field(record, unsigned char*, 3) = 1;
                    Cutscene75B88PackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&frame.sp80;
                        MATCHING_KEEP(vector);
                        Cutscene75B88AddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            register int random __asm__("$2") = Cutscene75B88rand();
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
                            Cutscene75B88PackVectorShiftRight2(destination, source);
                        }
                    }
                    Cutscene75B88Field(record, unsigned char*, 0x17) = 2;
                    tailByte = Cutscene75B88rand();
                    tailByte |= 192;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B88Field(record, unsigned char*, 16) = tailByte;
                    Cutscene75B88Field(record, unsigned char*, 0x11) =
                        (unsigned char)((Cutscene75B88rand() & 0x3F) - 0x60);
                    Cutscene75B88Field(record, unsigned char*, 0x12) = 0;
                    tailByte = Cutscene75B88rand();
                    tailByte |= 224;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B88Field(record, unsigned char*, 20) = tailByte;
                    tailByte = Cutscene75B88rand();
                    tailByte |= 224;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Cutscene75B88Field(record, unsigned char*, 21) = tailByte;
                    {
                        register int byte128 __asm__("$8") = 128;
                        MATCHING_KEEP(byte128);
                        Cutscene75B88Field(record, unsigned char*, 0x16) = byte128;
                    }
                    Cutscene75B88Field(record, unsigned char*, 0x13) = 0x50;
                    break;
            }
            {
                register int stride __asm__("$8") = frame.spA8;
                MATCHING_KEEP(stride);
                stride += 12;
                frame.spA8 = stride;
                stride = frame.spB0;
                MATCHING_KEEP(stride);
                stride += 4;
                frame.spB0 = stride;
                MATCHING_KEEP_VOLATILE_CLOBBER(iteration, "memory");
                stride = frame.sp90;
                MATCHING_KEEP2(stride, iteration);
                iteration += 1;
                MATCHING_KEEP2(iteration, stride);
                var_v0 = iteration < stride;
            }

        } while (var_v0);
    }
    return record;
}

#undef Cutscene75B88Field

#undef Cutscene75B88High
