#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008B348.
 * Assembly SHA256 bcabbb95d6edf90801f8ead01db7c078039e5f7ab6a781bf5a38c4297441acd9.
 * AI-generated; not human reviewed. Verified sibling C cases were adapted
 * to the original selector, field, helper, register and stack differences.
 * Selector0E is decoded from its complete original instruction chain.
 * Raw fields retain byte/halfword/word widths and original signed operations.
 * The original120-byte frame retains the iteration retained in an ordinary saved register,
 * local objectSP10..F7, countSPD8, cached vectorSPE0 and strideSPF0.
 * Iteration and byte255 use ordinary C allocation to FP and S7. Selector10
 * retains the original BGEZ/address delay with paired zero-CPU .set metadata.
 * All empty metadata inputs are initialized. C emits every CPU instruction;
 * compiler/assembler/pipeline/flags, padding and acceptance gates are frozen.
 * Helper meanings/contracts, physical units/fixed point and caller cadence
 * remain unresolved. Cadence per invocation; invocation rate unknown.
 * Falsification: every original native/linked word, conditional/internal
 * target, owned table/data record, and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#include "common.h"
extern int Spawn8B348D_8006E020 __asm__("D_8006E020");
extern int Spawn8B348D_8006E024 __asm__("D_8006E024");
extern int Spawn8B348D_8006E028 __asm__("D_8006E028");
extern int Spawn8B348D_80071918 __asm__("D_80071918");
extern int Spawn8B348D_8007191C __asm__("D_8007191C");
extern int Spawn8B348D_80071920 __asm__("D_80071920");
extern int Spawn8B348D_80071930 __asm__("D_80071930");
extern unsigned short Spawn8B348D_8006E03E __asm__("D_8006E03E");
extern short Spawn8B348D_8006E040 __asm__("D_8006E040");
int Spawn8B348InterpolateCosine(int) __asm__("func_8004EA2C");
int Spawn8B348InterpolateSine(int) __asm__("func_8004E9E4");
int Spawn8B348func_8001A310(void*, int, int, int) __asm__("func_8001A310");
extern int Spawn8B348D_8006D07C __asm__("D_8006D07C");
extern int Spawn8B348D_8006D080 __asm__("D_8006D080");
extern int Spawn8B348D_8006D084 __asm__("D_8006D084");
extern int Spawn8B348D_80071934 __asm__("D_80071934");
extern unsigned char Spawn8B348PlayerE __asm__("D_80070328 + 0xE");
#define Spawn8B348High(a, b)                                                         \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Spawn8B348Color1[] __asm__("D_80066BAC");
extern unsigned char Spawn8B348Color2[] __asm__("D_80066BAC");
#define Spawn8B348Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Spawn8B348func_8004EA90(void*, void*, int) __asm__("func_8004EA90");
int Spawn8B348TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Spawn8B348ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Spawn8B348CopyVector(void*, void*) __asm__("func_8004F178");
int Spawn8B348AddVector(void*, void*, void*) __asm__("func_8004F194");
int Spawn8B348MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Spawn8B348PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Spawn8B348func_80056434(int) __asm__("func_80056434");
int Spawn8B348func_8004F58C(void*, void*) __asm__("func_8004F58C");
int Spawn8B348rand(void) __asm__("rand");
extern unsigned char Spawn8B348D_800658A0[] __asm__("D_800658A0");
extern unsigned char Spawn8B348D_80065920[] __asm__("D_80065920");
extern unsigned char Spawn8B348D_80066A28[] __asm__("D_80066A28");
extern unsigned char Spawn8B348D_80066A48[] __asm__("D_80066A48");
extern unsigned char Spawn8B348D_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Spawn8B348D_80070328[] __asm__("D_80070328");
extern int Spawn8B348D_8006E344 __asm__("D_8006E344");
int Spawn8B348func_8004F570(void*, void*) __asm__("func_8004F570");
int Spawn8B348func_8004F5A8(void*, void*, void*) __asm__("func_8004F5A8");
#define Spawn8B348Stack(t, o) (*(t*)((unsigned char*)&frame + (o) - 0x10))
void* func_level_31_8008B348(int entryCount, int kind, void* input, void* mode) {
    int frame[58];
    register int kindSelector __asm__("$21") = kind;
    register unsigned char* reference __asm__("$20") = input;
    register unsigned char* modeSelector __asm__("$22") = mode;
    register unsigned char* temp_s1 __asm__("$17");
    register unsigned char* temp_s1_2 __asm__("$17");
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    register int commonByte8 __asm__("$8");
    register int commonByte9 __asm__("$9");
    int byte255;
    register int iteration;
    register int scratch16 __asm__("$16");
    register int scratch17 __asm__("$17");
    register int var_v0 __asm__("$2");
    register int tailByte __asm__("$2");
    register int scratch19 __asm__("$18");
    int var_v0_2;
    register int var_v0_4 __asm__("$2");
    unsigned int temp_v1_2;
    unsigned char temp_v1_3;
    void* var_a0;
    register unsigned char* record __asm__("$19");
    register void* vector16 __asm__("$16");
    MATCHING_KEEP3(kindSelector, reference, modeSelector);
    iteration = 0;
    MATCHING_KEEP(iteration);
    record = 0;
    MATCHING_KEEP(record);
    Spawn8B348Stack(int, 0xD8) = entryCount;
    if (entryCount > 0) {
        {
            register int* vectorBase __asm__("$8") = &Spawn8B348Stack(int, 0x30);
            MATCHING_KEEP_CLOBBER(vectorBase, "$23");
            byte255 = 255;
            Spawn8B348Stack(int* volatile, 0xE0) = vectorBase;
        }
        Spawn8B348Stack(volatile int, 0xF0) = 0;
        do {
            switch (kindSelector) {
                case 0x0:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$8");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = one;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    Spawn8B348PackVectorShiftRight2(record + 0x18, modeSelector);
                    Spawn8B348Field(record, short*, 0x1E) = 0;
                    Spawn8B348Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Spawn8B348rand();
                    {
                        register int byte128 __asm__("$8") = 128;
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$3", "memory");
                        Spawn8B348Field(record, unsigned char*, 0xC) = byte128;
                        Spawn8B348Field(record, unsigned char*, 0xD) = byte128;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 0xE) = byte128;
                        commonByte8 = 46;
                        MATCHING_KEEP_CLOBBER(commonByte8, "memory");
                        Spawn8B348Field(record, unsigned char*, 0xB) = tailByte;
                        __asm__ volatile(""
                                         : "=r"(tailByte)
                                         : "0"(tailByte), "r"(kindSelector)
                                         : "$3", "memory");
                        tailByte = 4;
                    }
                    goto initializeF8;
                case 0x1:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    Spawn8B348PackVectorShiftRight2(record + 0x18, modeSelector);
                    Spawn8B348Field(record, short*, 0x1E) = 0;
                    Spawn8B348Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Spawn8B348rand();
                    Spawn8B348Field(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                    Spawn8B348Field(record, unsigned char*, 0xC) = tailByte;
                    Spawn8B348Field(record, unsigned char*, 0xD) = tailByte;
                    Spawn8B348Field(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    goto initializeF9;
                case 0x2:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                        tailByte = Spawn8B348rand();
                        tailByte &= 63;
                        tailByte -= 32;
                        Spawn8B348Stack(int, 0x10) = tailByte;
                        tailByte = Spawn8B348rand();
                        destination = record + 24;
                        source = &Spawn8B348Stack(int, 0x10);
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        Spawn8B348Stack(int, 0x14) = tailByte;
                        Spawn8B348Stack(int, 0x18) = 16;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Spawn8B348Field(record, unsigned short*, 30) = 0;
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn8B348rand();
                    commonByte8 = 128;
                    MATCHING_KEEP2(commonByte8, tailByte);
                    Spawn8B348Field(record, volatile unsigned char*, 12) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 13) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 14) = commonByte8;
                    commonByte8 = 46;
                    Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    goto initializeF8;
                case 0x9:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* playerVector __asm__("$16") = &Spawn8B348Stack(int, 0x20);
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Spawn8B348D_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348CopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x20);
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            Spawn8B348Stack(int, 0x20) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = &Spawn8B348Stack(int, 0x20);
                            __asm__(""
                                    : "=r"(destination), "=r"(source)
                                    : "0"(destination), "1"(source)
                                    : "$3", "memory");
                            component = Spawn8B348Stack(int, 0x24);
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            Spawn8B348Stack(int, 0x24) = component;
                            Spawn8B348PackVectorShiftRight2(destination, source);
                        }
                        Spawn8B348CopyVector(playerVector, player + 0x98);
                        Spawn8B348ShiftVectorRightTowardZero(playerVector, 6);
                        Spawn8B348PackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Spawn8B348Field(record, short*, 0x1E) = 0;
                    Spawn8B348Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Spawn8B348rand();
                    commonByte8 = 128;
                    MATCHING_KEEP2(commonByte8, tailByte);
                    Spawn8B348Field(record, volatile unsigned char*, 12) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 13) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 14) = commonByte8;
                    commonByte8 = 46;
                    Spawn8B348Field(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    goto initializeF8;
                case 0xA:
                    record = Spawn8B348func_80056434(3);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Spawn8B348D_80070328;
                        tailByte = Spawn8B348rand();
                        destination = record + 4;
                        source = Spawn8B348D_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
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
                        Spawn8B348Field(record, unsigned char*, 10) = value;
                        value = 15;
                        Spawn8B348Field(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = Spawn8B348Stack(int, 0xD8);
                        factor |= 0x6667;
                        dividend = count - iteration;
                        count = Spawn8B348Stack(volatile int, 0xF0);
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Spawn8B348D_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Spawn8B348High(dividend, factor);
                        Spawn8B348Field(record, unsigned char*, 12) = value;
                        value = *(Spawn8B348Color1 + 1 + count);
                        dividend >>= 31;
                        Spawn8B348Field(record, unsigned char*, 13) = value;
                        color = *(Spawn8B348Color2 + 2 + count);
                        value = 44;
                        Spawn8B348Field(record, unsigned char*, 15) = value;
                        value = 4;
                        Spawn8B348Field(record, unsigned char*, 17) = value;
                        Spawn8B348Field(record, unsigned char*, 16) = 0;
                        Spawn8B348Field(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        count = productHigh;
                        MATCHING_KEEP(count);
                        value = (count >> 1) - dividend;
                        Spawn8B348Field(record, short*, 24) = value;
                    }
                    break;
                case 0xC:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register void* vector __asm__("$6");
                        register int base __asm__("$2");
                        register void* table __asm__("$5") = (void*)(iteration * 12);
                        __asm__(""
                                : "=r"(destination), "=r"(table)
                                : "0"(destination), "1"(table)
                                : "$2", "$6", "memory");
                        base = (int)Spawn8B348D_80066A48;
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "$6", "memory");
                        vector = Spawn8B348Stack(int* volatile, 0xE0);
                        base = 1;
                        Spawn8B348Field(record, unsigned char*, 3) = base;
                        base = 4;
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 17) = base;
                        Spawn8B348TransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Spawn8B348Field(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        Spawn8B348MultiplyVectorGpfSf0(Spawn8B348Stack(int* volatile, 0xE0),
                                                       Spawn8B348Stack(int* volatile, 0xE0), 3);
                    }
                    Spawn8B348AddVector(Spawn8B348Stack(int* volatile, 0xE0),
                                        Spawn8B348Stack(int* volatile, 0xE0), reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x30);
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x30) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x34);
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x34) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x38);
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x38) = component;
                        }
                    }
                    if (modeSelector == (unsigned char*)6) {
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x30);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x30) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x34);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x34) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x38);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x38) = component;
                        }
                    }
                    if (Spawn8B348Field(reference, short*, 0x36) == 0xB6) {
                        Spawn8B348Stack(int, 0x38) += 0x200;
                    }
                    Spawn8B348PackVectorShiftRight2(record + 4,
                                                    Spawn8B348Stack(int* volatile, 0xE0));
                    Spawn8B348Field(record, int*, 0xC) =
                        (int)*(int*)(Spawn8B348D_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Spawn8B348Field(reference, short*, 54);
                            register int expected __asm__("$8");
                            __asm__ __volatile__("" ::: "$8", "memory");
                            expected = 0x17D;
                            MATCHING_KEEP(expected);
                            observed == expected;
                        })) {
                        var_v0_2 = (Spawn8B348rand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Spawn8B348rand() & 7) + 0x20;
                    }
                    Spawn8B348Field(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Spawn8B348rand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int base __asm__("$3");
                        register void* source __asm__("$5") = (void*)(iteration * 12);
                        __asm__(""
                                : "=r"(destination), "=r"(source), "=r"(tailByte)
                                : "0"(destination), "1"(source), "2"(tailByte)
                                : "$3", "memory");
                        base = (int)Spawn8B348D_80066A48;
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        MATCHING_KEEP2_CLOBBER(source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                        Spawn8B348Field(record, unsigned char*, 16) = 0;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    Spawn8B348Field(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Spawn8B348Field(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Spawn8B348rand() & 7));
                    Spawn8B348Field(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Spawn8B348Field(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Spawn8B348rand() & 7));
                    Spawn8B348Field(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Spawn8B348Field(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Spawn8B348rand() & 7));
                    break;
                case 0xD:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    Spawn8B348PackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Spawn8B348Field(record, short*, 0x1E) = 0;
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn8B348rand();
                    commonByte8 = 46;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$3", "memory");
                    Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$4", "memory");
                    Spawn8B348Field(record, unsigned char*, 12) = byte255;
                    __asm__ volatile(""
                                     : "=r"(commonByte8), "=r"(tailByte)
                                     : "0"(commonByte8), "1"(tailByte)
                                     : "$4", "memory");
                    Spawn8B348Field(record, unsigned char*, 13) = byte255;
                    goto initializeZeroE;
                case 0xE: {
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int value4 __asm__("$4");
                    register int value5 __asm__("$5");
                    register int low8 __asm__("$8");
                    register int low9 __asm__("$8");
                    register void* vector17 __asm__("$17");
                    register void* vector18 __asm__("$18");
                    register void* vector16 __asm__("$16");
                    int productLo;
                    value2 = Spawn8B348rand();
                    value2 &= 1;
                    if (value2) {
                        value2 = Spawn8B348rand();
                        value3 = Spawn8B348D_8006E040;
                        value2 &= 1023;
                        value2 -= 512;
                        scratch17 = value3 - value2;
                    } else {
                        value2 = Spawn8B348rand();
                        scratch17 = value2 & 4095;
                    }
                    value2 = Spawn8B348rand();
                    value4 = scratch17;
                    scratch19 = value2 & 16383;
                    value2 = Spawn8B348InterpolateCosine(value4);
                    scratch16 = value2;
                    value2 = Spawn8B348rand();
                    productLo = scratch16 * scratch19;
                    __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                    value4 = scratch17;
                    value2 &= 2047;
                    value2 -= 1024;
                    value3 = Spawn8B348Field(Spawn8B348D_80070328, int*, 0x98);
                    value5 = Spawn8B348D_8006E020;
                    value3 <<= 1;
                    value5 += value3;
                    __asm__ volatile(""
                                     : "=l"(productLo), "=r"(value2), "=r"(value4), "=r"(value5)
                                     : "0"(productLo), "1"(value2), "2"(value4), "3"(value5)
                                     : "memory");
                    low8 = productLo;
                    MATCHING_KEEP(low8);
                    value3 = low8 >> 12;
                    value5 += value3;
                    value5 -= value2;
                    Spawn8B348Stack(int, 0x40) = value5;
                    value2 = Spawn8B348InterpolateSine(value4);
                    scratch16 = value2;
                    value2 = Spawn8B348rand();
                    productLo = scratch16 * scratch19;
                    __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                    value2 &= 2047;
                    value3 = Spawn8B348D_8006E028;
                    value2 -= 1024;
                    value3 += 16384;
                    Spawn8B348Stack(int, 0x48) = value3;
                    value3 = Spawn8B348Field(Spawn8B348D_80070328, int*, 0x9C);
                    value4 = Spawn8B348D_8006E024;
                    value3 <<= 1;
                    value4 += value3;
                    __asm__ volatile(""
                                     : "=l"(productLo), "=r"(value2), "=r"(value4)
                                     : "0"(productLo), "1"(value2), "2"(value4)
                                     : "memory");
                    low9 = productLo;
                    MATCHING_KEEP(low9);
                    value3 = low9 >> 12;
                    value4 += value3;
                    value3 = Spawn8B348Stack(int, 0x40);
                    value4 -= value2;
                    Spawn8B348Stack(int, 0x44) = value4;
                    if (value3 <= 0)
                        break;
                    if (value4 <= 0)
                        break;
                    value2 = Spawn8B348func_8001A310(&Spawn8B348Stack(int, 0x40), 0x60C0, 2, 0);
                    scratch16 = value2;
                    if (reference) {
                        value2 = Spawn8B348rand();
                        value2 &= 8191;
                        value3 = Spawn8B348D_8006E028;
                        value2 -= 2048;
                        goto rawHeightE;
                    }
                    value2 = Spawn8B348D_8006E03E;
                    value3 = value2 & 4095;
                    value2 = value3 < 1024;
                    MATCHING_KEEP2(value2, value3);
                    if (value2) {
                        value2 = scratch19 >> 2;
                        goto angleHeightE;
                    }
                    value2 = value3 < 3841;
                    MATCHING_KEEP(value2);
                    if (value2) {
                        value2 = scratch19 >> 1;
                        goto baseHeightE;
                    }
                    value2 = scratch19 >> 1;
                angleHeightE:
                    value3 = Spawn8B348D_8006E028;
                    value2 += 2048;
                rawHeightE:
                    value3 += value2;
                    Spawn8B348Stack(int, 0x48) = value3;
                    goto heightDoneE;
                baseHeightE:
                    value2 = Spawn8B348D_8006E028;
                    value2 += 8192;
                    Spawn8B348Stack(int, 0x48) = value2;
                heightDoneE:
                    if (Spawn8B348Stack(int, 0x48) < scratch16 + 1024)
                        break;
                    if (scratch16 && Spawn8B348D_80071920 <= 0)
                        break;
                    record = Spawn8B348func_80056434(3);
                    value5 = 1;
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) = 0;
                    Spawn8B348Field(record, unsigned char*, 3) = value5;
                    if (scratch16 == 0) {
                        value2 = Spawn8B348Stack(int, 0x48);
                        scratch16 = value2 - 16384;
                        if (scratch16 < 1024)
                            scratch16 = 1024;
                    } else {
                        value2 = Spawn8B348D_80071918;
                        value3 = Spawn8B348D_8007191C;
                        value4 = Spawn8B348D_80071920;
                        if (value2 < 0)
                            value2 = -value2;
                        if (value3 < 0)
                            value3 = -value3;
                        value2 += value3;
                        if (value2 < value4)
                            Spawn8B348Field(record, unsigned char*, 2) = value5;
                    }
                    vector18 = record + 4;
                    value2 = Spawn8B348rand();
                    Spawn8B348Stack(int, 0x50) = value2 & 3;
                    value2 = Spawn8B348rand();
                    Spawn8B348Stack(int, 0x54) = value2 & 3;
                    value2 = Spawn8B348rand();
                    value2 &= 7;
                    value3 = Spawn8B348Stack(int, 0x48);
                    value2 += 10;
                    value3 -= scratch16;
                    value3 >>= 2;
                    value3 /= value2;
                    value5 = (int)&Spawn8B348Stack(int, 0x40);
                    Spawn8B348Stack(int, 0x58) = value2;
                    value4 = (int)vector18;
                    Spawn8B348Field(record, unsigned short*, 0x1C) = value3;
                    Spawn8B348Stack(int, 0x48) = scratch16;
                    Spawn8B348PackVectorShiftRight2((void*)value4, (void*)value5);
                    vector17 = &Spawn8B348Stack(int, 0x60);
                    value4 = (int)vector17;
                    value5 = (int)&Spawn8B348Stack(int, 0x50);
                    Spawn8B348MultiplyVectorGpfSf0((void*)value4, (void*)value5,
                                                   Spawn8B348Field(record, short*, 0x1C));
                    vector16 = &Spawn8B348Stack(int, 0x70);
                    Spawn8B348func_8004F570(vector16, vector17);
                    Spawn8B348func_8004F5A8(vector18, vector18, vector16);
                    value2 = Spawn8B348Field(record, unsigned short*, 4);
                    value3 = Spawn8B348Field(record, unsigned short*, 6);
                    Spawn8B348Field(record, unsigned short*, 24) = value2;
                    Spawn8B348Field(record, unsigned short*, 26) = value3;
                    value2 = Spawn8B348rand();
                    Spawn8B348Field(record, unsigned char*, 30) = value2;
                    value2 = Spawn8B348rand();
                    value2 &= 3;
                    value2 += 1;
                    Spawn8B348Field(record, unsigned char*, 31) = value2;
                    value2 = Spawn8B348Stack(int, 0x50);
                    value2 = -value2;
                    Spawn8B348Field(record, unsigned short*, 18) = value2;
                    value2 = Spawn8B348Stack(int, 0x54);
                    value2 = -value2;
                    Spawn8B348Field(record, unsigned short*, 20) = value2;
                    value2 = Spawn8B348Stack(int, 0x58);
                    value2 = -value2;
                    Spawn8B348Field(record, unsigned short*, 22) = value2;
                    value2 = Spawn8B348rand();
                    value2 &= 7;
                    value2 += 20;
                    Spawn8B348Field(record, unsigned char*, 10) = value2;
                    value2 = Spawn8B348rand();
                    value2 &= 7;
                    value2 += 12;
                    commonByte8 = 128;
                    MATCHING_KEEP2(commonByte8, value2);
                    Spawn8B348Field(record, volatile unsigned char*, 12) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 13) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 11) = value2;
                    value2 = 44;
                    Spawn8B348Field(record, volatile unsigned char*, 14) = commonByte8;
                    Spawn8B348Field(record, volatile unsigned char*, 15) = value2;
                    Spawn8B348Field(record, volatile unsigned char*, 17) = 0;
                    Spawn8B348Field(record, unsigned char*, 16) = 0;
                    break;
                }
                case 0x10:
                    record = Spawn8B348func_80056434(2);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    {
                        register int value2 __asm__("$2") = Spawn8B348rand();
                        register int value3 __asm__("$3") = value2;
                        register void* destination4 __asm__("$4");
                        register void* source5 __asm__("$5");
                        MATCHING_KEEP2(value2, value3);
                        __asm__ volatile(".set	noreorder" : "=r"(value3) : "0"(value3));
                        if (value3 < 0) {
                            destination4 = record + 4;
                            value2 = value3 + 7;
                        } else {
                            destination4 = record + 4;
                        }
                        __asm__ volatile(".set	reorder"
                                         : "=r"(destination4)
                                         : "0"(destination4)
                                         : "$5");
                        source5 = reference;
                        value2 >>= 3;
                        value2 <<= 3;
                        value2 = value3 - value2;
                        Spawn8B348Field(record, unsigned char*, 2) = value2;
                        value2 = 1;
                        Spawn8B348Field(record, unsigned char*, 3) = value2;
                        Spawn8B348PackVectorShiftRight2(destination4, source5);
                    }
                    Spawn8B348PackVectorShiftRight2(record + 24, modeSelector);
                    tailByte = 5;
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn8B348rand();
                    Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 112;
                    commonByte8 = 128;
                    Spawn8B348Field(record, volatile unsigned char*, 12) = tailByte;
                    tailByte = 192;
                    Spawn8B348Field(record, volatile unsigned char*, 13) = commonByte8;
                    commonByte8 = 46;
                    Spawn8B348Field(record, unsigned char*, 14) = tailByte;
                    __asm__ volatile("" ::"i"(0x8008BD2C) : "memory");
                    tailByte = 4;
                    goto initializeF8;
                case 0x12:
                    record = Spawn8B348func_80056434(4);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348func_8004F58C(destination, source);
                    }
                    tailByte = Spawn8B348rand();
                    tailByte &= 6;
                    MATCHING_KEEP(tailByte);
                    tailByte += 14;
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    {
                        register int value3 __asm__("$3") = Spawn8B348PlayerE;
                        tailByte = 32;
                        Spawn8B348Field(record, volatile unsigned char*, 12) = tailByte;
                        Spawn8B348Field(record, volatile unsigned char*, 13) = tailByte;
                        tailByte = 64;
                        commonByte8 = 46;
                        Spawn8B348Field(record, volatile unsigned char*, 14) = tailByte;
                        tailByte = 2;
                        Spawn8B348Field(record, volatile unsigned char*, 15) = commonByte8;
                        Spawn8B348Field(record, volatile unsigned char*, 17) = tailByte;
                        Spawn8B348Field(record, volatile unsigned char*, 16) = 0;
                        __asm__ volatile("" ::"i"(0x8008BDA0) : "memory");
                        Spawn8B348Field(record, unsigned char*, 11) = value3;
                    }
                    break;
                case 0x16:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    Spawn8B348PackVectorShiftRight2(record + 0x18, modeSelector);
                    Spawn8B348Field(record, unsigned char*, 0x1E) = 0;
                    Spawn8B348Field(record, unsigned char*, 0x1F) = 0;
                    Spawn8B348Field(record, unsigned char*, 10) = 12;
                    tailByte = Spawn8B348rand();
                    Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 32;
                    commonByte8 = 46;
                    MATCHING_KEEP2(tailByte, commonByte8);
                    Spawn8B348Field(record, unsigned char*, 12) = tailByte;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "$4", "memory");
                    Spawn8B348Field(record, unsigned char*, 13) = tailByte;
                    Spawn8B348Field(record, unsigned char*, 14) = tailByte;
                    tailByte = 4;
                    Spawn8B348Field(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                case 0x21:
                    record = Spawn8B348func_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) = 0;
                    Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&Spawn8B348Stack(int, 0x88);
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Spawn8B348D_80070328 + 0x98;
                            Spawn8B348CopyVector(destination, temp_s1);
                        }
                        Spawn8B348ShiftVectorRightTowardZero((void*)scratch16, 6);
                        Spawn8B348CopyVector(&Spawn8B348Stack(int, 0x78), temp_s1 - 0x98);
                        Spawn8B348Stack(int, 0x80) -= 0x164;
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3") = Spawn8B348Stack(int, 0x78);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x78) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn8B348rand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$18");
                            scratch19 = 48;
                            component = Spawn8B348Stack(int, 0x7C);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn8B348Stack(int, 0x7C) = component;
                        }
                        goto setDestination;
                    } else {
                        register int one __asm__("$8") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            temp_s1_2 = Spawn8B348D_80070328 + 0x30;
                            Spawn8B348Stack(int, 0x78) = 0x164;
                            Spawn8B348Stack(int, 0x7C) = 0;
                            Spawn8B348Stack(int, 0x80) = 0;
                            Spawn8B348TransformVectorByBasis(temp_s1_2, &Spawn8B348Stack(int, 0x78),
                                                             &Spawn8B348Stack(int, 0x78));
                            Spawn8B348AddVector(&Spawn8B348Stack(int, 0x78),
                                                &Spawn8B348Stack(int, 0x78), temp_s1_2 - 0x30);
                            scratch19 = 0x40;
                            Spawn8B348Stack(int, 0x88) = -(Spawn8B348rand() & 7);
                            {
                                register int random __asm__("$2") = Spawn8B348rand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") = temp_s1_2;
                                register void* vector __asm__("$5") = &Spawn8B348Stack(int, 0x88);
                                register int angle __asm__("$7") = iteration << 6;
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP3_CLOBBER(destination, vector, output, "memory");
                                random &= 15;
                                component = *(unsigned short*)(Spawn8B348D_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                Spawn8B348Stack(int, 0x8C) = component;
                                random = *(unsigned short*)(Spawn8B348D_800658A0 + angle);
                                random = (random << 16) >> 23;
                                Spawn8B348Stack(int, 0x90) = random;
                                Spawn8B348TransformVectorByBasis(destination, vector, output);
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
                    Spawn8B348CopyVector(&Spawn8B348Stack(int, 0x78), Spawn8B348D_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Spawn8B348D_80065920;
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
                        other = Spawn8B348Stack(int, 0x78);
                        value >>= scratch16;
                        other += value;
                        value = (int)Spawn8B348D_800658A0;
                        second += value;
                        value = Spawn8B348Stack(int, 0x80);
                        Spawn8B348Stack(int, 0x78) = other;
                        other = *(short*)second;
                        value -= 356;
                        Spawn8B348Stack(int, 0x80) = value;
                        value = Spawn8B348Stack(int, 0x7C);
                        other >>= scratch16;
                        value += other;
                        Spawn8B348Stack(int, 0x7C) = value;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        value = *first;
                        other = scratch16 + 1;
                        value >>= other;
                        Spawn8B348Stack(int, 0x88) = value;
                        value = *(short*)second;
                        Spawn8B348Stack(int, 0x90) = 0;
                        value >>= other;
                        Spawn8B348Stack(int, 0x8C) = value;
                    }
                setDestination:
                    var_a0 = record + 4;
                finishMode:
                    Spawn8B348PackVectorShiftRight2(var_a0, &Spawn8B348Stack(int, 0x78));
                    Spawn8B348PackVectorShiftRight2(record + 0x18, &Spawn8B348Stack(int, 0x88));
                    Spawn8B348Field(record, short*, 0x1E) = 0;
                    Spawn8B348Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Spawn8B348rand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                    Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Spawn8B348Field(record, unsigned char*, 0xC) = scratch19;
                    Spawn8B348Field(record, unsigned char*, 0xD) = scratch19;
                    Spawn8B348Field(record, unsigned char*, 0xE) = scratch19;
                    tailByte = 4;
                    goto initializeF9;
                case 0x37:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    Spawn8B348PackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 64;
                    Spawn8B348Field(record, unsigned char*, 0xA) = tailByte;
                    tailByte = Spawn8B348rand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                    Spawn8B348Field(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    Spawn8B348Field(record, unsigned char*, 0xC) = byte255;
                    Spawn8B348Field(record, unsigned char*, 13) = byte255;
                    goto initializeZeroE;
                case 0x38:
                    record = Spawn8B348func_80056434(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) = 0;
                    Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                    Spawn8B348Field(record, unsigned short*, 4) =
                        Spawn8B348Field(reference, unsigned short*, 4);
                    Spawn8B348Field(record, unsigned short*, 6) =
                        Spawn8B348Field(reference, unsigned short*, 6);
                    Spawn8B348Field(record, unsigned short*, 8) =
                        Spawn8B348Field(reference, unsigned short*, 8);
                    Spawn8B348Field(record, int*, 24) = Spawn8B348Field(reference, int*, 24);
                    Spawn8B348Field(record, int*, 28) = Spawn8B348Field(reference, int*, 28);
                    tailByte = Spawn8B348Field(reference, unsigned char*, 10);
                    MATCHING_KEEP(tailByte);
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    MATCHING_BARRIER_VOLATILE("memory");
                    {
                        register unsigned int sourceByte __asm__("$2") =
                            Spawn8B348Field(reference, unsigned char*, 11);
                        MATCHING_KEEP_CLOBBER(sourceByte, "memory");
                        commonByte8 = 46;
                        Spawn8B348Field(record, volatile unsigned char*, 12) = 0;
                        Spawn8B348Field(record, volatile unsigned char*, 13) = 0;
                        Spawn8B348Field(record, volatile unsigned char*, 14) = 0;
                        Spawn8B348Field(record, volatile unsigned char*, 15) = commonByte8;
                        Spawn8B348Field(record, volatile unsigned char*, 17) = 0;
                        Spawn8B348Field(record, volatile unsigned char*, 16) = 0;
                        Spawn8B348Field(record, unsigned char*, 11) = sourceByte;
                    }
                    break;
                case 0x3B:
                    record = Spawn8B348func_80056434(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Spawn8B348Field(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Spawn8B348Field(record, unsigned char*, 3) = value;
                        value = 16;
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Spawn8B348Field(record, unsigned char*, 1) = flags;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Spawn8B348rand();
                        register int component __asm__("$3") =
                            Spawn8B348Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Spawn8B348Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn8B348rand();
                        register int component __asm__("$3") =
                            Spawn8B348Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Spawn8B348Field(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Spawn8B348Field(record, int*, 12) = var_v0;
                    Spawn8B348Field(record, unsigned char*, 0xA) =
                        (unsigned char)((Spawn8B348rand() & 0xF) + 0x14);
                    Spawn8B348Field(record, unsigned char*, 0xB) = Spawn8B348rand();
                    Spawn8B348Field(record, unsigned char*, 0x10) = 0;
                    Spawn8B348Field(record, short*, 0x18) = (short)((Spawn8B348rand() & 7) - 4);
                    Spawn8B348Field(record, short*, 0x1A) = (short)(-2 - (Spawn8B348rand() & 7));
                    Spawn8B348Field(record, short*, 0x1C) = (short)((Spawn8B348rand() & 0xF) - 8);
                    break;
                case 0x3D:
                    record = Spawn8B348func_80056434(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                        Spawn8B348Field(record, unsigned char*, 2) = 0;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination, source);
                    }
                    tailByte = 72;
                    Spawn8B348Field(record, short*, 30) = 0;
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn8B348rand();
                    {
                        register int mask __asm__("$3") = -128;
                        MATCHING_KEEP2_CLOBBER(mask, tailByte, "memory");
                        Spawn8B348Field(record, unsigned char*, 11) = tailByte;
                        tailByte = (int)modeSelector & mask;
                        Spawn8B348Field(record, unsigned char*, 12) = tailByte;
                        tailByte = (int)modeSelector >> 8;
                        tailByte &= mask;
                        commonByte8 = 46;
                        MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                        Spawn8B348Field(record, unsigned char*, 13) = tailByte;
                        tailByte = 8;
                        Spawn8B348Field(record, unsigned char*, 14) = 0;
                    }
                initializeF9:
                    Spawn8B348Field(record, unsigned char*, 15) = commonByte8;
                initializeTrailingBytes:
                    Spawn8B348Field(record, unsigned char*, 17) = tailByte;
                    Spawn8B348Field(record, unsigned char*, 16) = 0;
                    break;
                case 0x42:
                    record = Spawn8B348func_80056434(0);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn8B348rand() & 0xF);
                    Spawn8B348Field(record, unsigned char*, 3) = 1;
                    Spawn8B348Field(record, short*, 4) =
                        (short)((((int)Spawn8B348Field(reference, int*, 0) >> 2) +
                                 (Spawn8B348rand() & 0xF)) -
                                8);
                    Spawn8B348Field(record, short*, 6) =
                        (short)((((int)Spawn8B348Field(reference, int*, 4) >> 2) +
                                 (Spawn8B348rand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Spawn8B348rand();
                        register int component __asm__("$3") = Spawn8B348Field(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Spawn8B348Field(record, short*, 16) = 0;
                        Spawn8B348Field(record, short*, 18) = 0;
                        Spawn8B348Field(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Spawn8B348Field(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Spawn8B348D_8006E344;
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
                        Spawn8B348Field(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Spawn8B348Field(Spawn8B348D_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto colorCaseOne;
                    selectColor:;
                    }
                    temp_v1_2 = Spawn8B348rand() & 7;
                    switch (temp_v1_2) {
                        case 0:
                            Spawn8B348Field(record, unsigned char*, 0xC) = byte255;
                            Spawn8B348Field(record, unsigned char*, 0xD) = 0;
                            Spawn8B348Field(record, unsigned char*, 0xE) = 0;
                            break;
                        case 1:
                        colorCaseOne:
                            Spawn8B348Field(record, unsigned char*, 12) = byte255;
                            goto storeSecondColor;
                        case 2:
                            Spawn8B348Field(record, unsigned char*, 12) = 0;
                        storeSecondColor:
                            Spawn8B348Field(record, unsigned char*, 13) = byte255;
                            Spawn8B348Field(record, unsigned char*, 14) = 0;
                            break;
                        case 3:
                            Spawn8B348Field(record, unsigned char*, 0xC) = 0;
                            Spawn8B348Field(record, unsigned char*, 0xD) = byte255;
                            goto storeThirdColor;
                        case 4:
                            Spawn8B348Field(record, unsigned char*, 0xC) = 0;
                            Spawn8B348Field(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 5:
                            Spawn8B348Field(record, unsigned char*, 0xC) = byte255;
                            Spawn8B348Field(record, unsigned char*, 0xD) = 0;
                            goto storeThirdColor;
                        case 6: {
                            register int byte128 __asm__("$8") = 128;
                            MATCHING_KEEP(byte128);
                            Spawn8B348Field(record, unsigned char*, 12) = byte255;
                            Spawn8B348Field(record, unsigned char*, 13) = byte128;
                        }
                            Spawn8B348Field(record, unsigned char*, 0xE) = 0;
                            break;
                        case 7: {
                            register int byte128 __asm__("$8") = 128;
                            MATCHING_KEEP(byte128);
                            Spawn8B348Field(record, unsigned char*, 12) = 0;
                            Spawn8B348Field(record, unsigned char*, 13) = byte128;
                        }
                        storeThirdColor:
                            Spawn8B348Field(record, unsigned char*, 14) = byte255;
                            break;
                    }
                    Spawn8B348Field(record, unsigned char*, 0xF) = 0x40;
                    break;
                case 0x46:
                    record = Spawn8B348func_80056434(1);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn8B348rand() & 0xF);
                    Spawn8B348Field(record, unsigned char*, 3) = 1;
                    Spawn8B348Stack(unsigned char, 0xA8) = 0;
                    Spawn8B348Stack(unsigned char, 0xA9) = Spawn8B348rand();
                    Spawn8B348Stack(unsigned char, 0xAA) = Spawn8B348rand();
                    Spawn8B348func_8004EA90(&Spawn8B348Stack(unsigned char, 0xA8),
                                            &Spawn8B348Stack(int, 0xB0), 0);
                    Spawn8B348Stack(int, 0x98) = modeSelector;
                    Spawn8B348Stack(int, 0x9C) = 0;
                    Spawn8B348Stack(int, 0xA0) = 0;
                    Spawn8B348TransformVectorByBasis(&Spawn8B348Stack(int, 0xB0),
                                                     (unsigned char*)&Spawn8B348Stack(int, 0x98),
                                                     (unsigned char*)&Spawn8B348Stack(int, 0x98));
                    Spawn8B348Field(record, unsigned short*, 4) =
                        (unsigned short)((int)Spawn8B348Field(reference, int*, 0) >> 2);
                    Spawn8B348Field(record, unsigned short*, 6) =
                        (unsigned short)((int)Spawn8B348Field(reference, int*, 4) >> 2);
                    Spawn8B348Field(record, unsigned short*, 8) =
                        (unsigned short)((int)Spawn8B348Field(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = Spawn8B348Stack(int, 0x98);
                        register int other __asm__("$3") =
                            Spawn8B348Field(record, unsigned short*, 4);
                        register int byte128 __asm__("$8");
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Spawn8B348Field(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = Spawn8B348Stack(int, 0x9C);
                        other = Spawn8B348Field(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Spawn8B348Field(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = Spawn8B348Stack(int, 0xA0);
                        value = 2;
                        Spawn8B348Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Spawn8B348Field(record, unsigned char*, 16) = value;
                        value = 192;
                        Spawn8B348Field(record, unsigned char*, 17) = value;
                        value = 80;
                        Spawn8B348Field(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Spawn8B348Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");
                        byte128 = 128;
                        MATCHING_KEEP(byte128);
                        Spawn8B348Field(record, unsigned char*, 18) = 0;
                        Spawn8B348Field(record, unsigned char*, 20) = byte255;
                        Spawn8B348Field(record, unsigned char*, 21) = byte255;
                        Spawn8B348Field(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Spawn8B348Field(record, short*, 14) = value;
                    }
                    break;
                case 0x47:
                    record = Spawn8B348func_80056434(1);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn8B348rand() & 7);
                    Spawn8B348Field(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Spawn8B348rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    Spawn8B348Stack(int, 0xC8) = temp_v0_4;
                    temp_v0_5 = (int)(((Spawn8B348rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    Spawn8B348Stack(int, 0xCC) = temp_v0_5;
                    temp_v0_6 = (int)(((Spawn8B348rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    Spawn8B348Stack(int, 0xD0) = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Spawn8B348Field(reference, int*, 0);
                        value = Spawn8B348Stack(int, 0xC8);
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Spawn8B348Field(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Spawn8B348Field(reference, int*, 4);
                        value = Spawn8B348Stack(int, 0xCC);
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Spawn8B348Field(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Spawn8B348Field(reference, int*, 8);
                        value = Spawn8B348Stack(int, 0xD0);
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Spawn8B348Field(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = Spawn8B348Stack(int, 0xC8);
                        register int value __asm__("$2") =
                            Spawn8B348Field(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Spawn8B348Field(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Spawn8B348Stack(int, 0xCC);
                        value = Spawn8B348Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Spawn8B348Field(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = Spawn8B348Stack(int, 0xD0);
                        other = Spawn8B348Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Spawn8B348Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Spawn8B348Field(record, unsigned char*, 16) = value;
                        Spawn8B348Field(record, unsigned char*, 17) = value;
                        value = 96;
                        Spawn8B348Field(record, unsigned char*, 18) = value;
                        Spawn8B348Field(record, unsigned char*, 20) = byte255;
                        Spawn8B348Field(record, unsigned char*, 21) = byte255;
                        Spawn8B348Field(record, unsigned char*, 22) = byte255;
                        value = 80;
                        Spawn8B348Field(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Spawn8B348Field(record, short*, 14) = other;
                    }
                    break;
                case 0x4E:
                    record = Spawn8B348func_80056434(0);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    Spawn8B348Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn8B348rand() & 0x1F);
                    Spawn8B348Field(record, unsigned char*, 3) = 1;
                    Spawn8B348PackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Spawn8B348rand();
                        register int component __asm__("$3") =
                            Spawn8B348Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Spawn8B348Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn8B348rand();
                        register int component __asm__("$3") =
                            Spawn8B348Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Spawn8B348Field(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn8B348rand();
                        register int component __asm__("$3") =
                            Spawn8B348Field(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Spawn8B348Field(record, unsigned short*, 8) = component;
                    }
                    Spawn8B348Field(record, short*, 0x10) = (short)((Spawn8B348rand() & 2) - 1);
                    Spawn8B348Field(record, short*, 0x12) = (short)((Spawn8B348rand() & 2) - 1);
                    Spawn8B348Field(record, short*, 0x14) = (short)-(Spawn8B348rand() & 1);
                    tailByte = Spawn8B348rand();
                    tailByte |= 128;
                    Spawn8B348Field(record, unsigned char*, 14) = tailByte;
                    tailByte = Spawn8B348rand();
                    tailByte &= 31;
                    MATCHING_KEEP(tailByte);
                    tailByte += 64;
                    Spawn8B348Field(record, unsigned char*, 13) = tailByte;
                    tailByte = Spawn8B348rand();
                    tailByte &= 7;
                    MATCHING_KEEP(tailByte);
                    tailByte += 32;
                    Spawn8B348Field(record, unsigned char*, 12) = tailByte;
                    tailByte = 64;
                    Spawn8B348Field(record, unsigned char*, 15) = tailByte;
                    tailByte = 2;
                    Spawn8B348Field(record, unsigned char*, 10) = tailByte;
                    break;
                case 0x4F:
                    record = Spawn8B348func_80056434(1);
                    Spawn8B348Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn8B348rand();
                    {
                        register void* destination4 __asm__("$4") = record + 10;
                        register void* source5 __asm__("$5") = reference;
                        MATCHING_KEEP3(destination4, source5, tailByte);
                        tailByte &= 15;
                        Spawn8B348Field(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Spawn8B348Field(record, unsigned char*, 3) = tailByte;
                        Spawn8B348PackVectorShiftRight2(destination4, source5);
                    }
                    {
                        register void* vector16 __asm__("$16") = &Spawn8B348Stack(int, 0xC8);
                        Spawn8B348AddVector(vector16, reference, modeSelector);
                        {
                            register int random2 __asm__("$2") = Spawn8B348rand();
                            register int value3 __asm__("$3") = Spawn8B348Stack(int, 0xC8);
                            MATCHING_KEEP2(random2, value3);
                            random2 &= 63;
                            value3 -= 32;
                            value3 += random2;
                            Spawn8B348Stack(int, 0xC8) = value3;
                        }
                        {
                            register int random2 __asm__("$2") = Spawn8B348rand();
                            register int value3 __asm__("$3") = Spawn8B348Stack(int, 0xCC);
                            MATCHING_KEEP2(random2, value3);
                            random2 &= 63;
                            value3 -= 32;
                            value3 += random2;
                            Spawn8B348Stack(int, 0xCC) = value3;
                        }
                        {
                            register int random2 __asm__("$2") = Spawn8B348rand();
                            register int value3 __asm__("$3");
                            register void* destination4 __asm__("$4") = record + 4;
                            register void* source5 __asm__("$5") = vector16;
                            __asm__(""
                                    : "=r"(destination4), "=r"(source5), "=r"(random2)
                                    : "0"(destination4), "1"(source5), "2"(random2)
                                    : "$3", "memory");
                            value3 = Spawn8B348Stack(int, 0xD0);
                            random2 &= 127;
                            value3 -= 64;
                            value3 += random2;
                            Spawn8B348Stack(int, 0xD0) = value3;
                            Spawn8B348PackVectorShiftRight2(destination4, source5);
                        }
                    }
                    tailByte = 2;
                    Spawn8B348Field(record, unsigned char*, 23) = tailByte;
                    tailByte = Spawn8B348rand();
                    tailByte |= 192;
                    Spawn8B348Field(record, unsigned char*, 18) = tailByte;
                    tailByte = Spawn8B348rand();
                    tailByte &= 15;
                    MATCHING_KEEP(tailByte);
                    tailByte += 80;
                    Spawn8B348Field(record, unsigned char*, 17) = tailByte;
                    tailByte = 40;
                    Spawn8B348Field(record, unsigned char*, 16) = tailByte;
                    tailByte = Spawn8B348rand();
                    tailByte |= 224;
                    Spawn8B348Field(record, unsigned char*, 22) = tailByte;
                    tailByte = Spawn8B348rand();
                    tailByte &= 7;
                    MATCHING_KEEP(tailByte);
                    tailByte += 120;
                    Spawn8B348Field(record, unsigned char*, 21) = tailByte;
                    tailByte = 60;
                    Spawn8B348Field(record, unsigned char*, 20) = tailByte;
                    tailByte = 80;
                    Spawn8B348Field(record, unsigned char*, 19) = tailByte;
                    break;
                storeTrailingE8:
                    Spawn8B348Field(record, unsigned char*, 14) = commonByte8;
                    goto initializeF8;
                initializeZeroE:
                    Spawn8B348Field(record, unsigned char*, 14) = 0;
                    goto initializeF8;
                storeTrailingF9:
                    Spawn8B348Field(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                initializeF8:
                    Spawn8B348Field(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                storeTrailingF8:
                    Spawn8B348Field(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
            }
            {
                register int stride8 __asm__("$8") = Spawn8B348Stack(volatile int, 0xF0);
                MATCHING_KEEP(stride8);
                stride8 += 4;
                Spawn8B348Stack(volatile int, 0xF0) = stride8;
                stride8 = Spawn8B348Stack(int, 0xD8);
                MATCHING_KEEP2(stride8, iteration);
                iteration += 1;
                var_v0 = iteration < stride8;
                MATCHING_KEEP(var_v0);
            }
        } while (var_v0);
    }
    return record;
}
#undef Spawn8B348Field
#undef Spawn8B348High
#undef Spawn8B348Stack
