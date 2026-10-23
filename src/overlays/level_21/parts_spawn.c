#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80089210.
 * Assembly SHA256 598ce89d60bb7ddba1ccbaa8aa08d5721e678acca67eb5d5b2076d07077eda37.
 * AI-generated; not human reviewed. Verified sibling C cases were adapted
 * to the original selector, field, helper, register and stack differences.
 * Selector0E is decoded from its complete original instruction chain.
 * Raw fields retain byte/halfword/word widths and original signed operations.
 * The original188-byte frame retains the outgoing fifth argument atSP10,
 * local objectSP18..15F, countSP140, iterationSP148 and strideSP158.
 * Byte128 uses ordinary C register allocation. The initialized integer SP
 * identity in selector29 derives from the local object's verifiedSP18 base;
 * it preserves the original repeated SP+A0 producers and emits no CPU word.
 * All empty metadata inputs are initialized. C emits every CPU instruction;
 * compiler/assembler/pipeline/flags, padding and acceptance gates are frozen.
 * Helper meanings/contracts, physical units/fixed point and caller cadence
 * remain unresolved. Cadence per invocation; invocation rate unknown.
 * Falsification: every original native/linked word, conditional/internal
 * target, owned table/data record, and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#include "common.h"
extern int Spawn89210D_8006E020 __asm__("D_8006E020");
extern int Spawn89210D_8006E024 __asm__("D_8006E024");
extern int Spawn89210D_8006E028 __asm__("D_8006E028");
extern int Spawn89210D_80071918 __asm__("D_80071918");
extern int Spawn89210D_8007191C __asm__("D_8007191C");
extern int Spawn89210D_80071920 __asm__("D_80071920");
extern int Spawn89210D_80071930 __asm__("D_80071930");
extern unsigned short Spawn89210D_8006E03E __asm__("D_8006E03E");
extern short Spawn89210D_8006E040 __asm__("D_8006E040");
int Spawn89210InterpolateCosine(int) __asm__("func_8004EA2C");
int Spawn89210InterpolateSine(int) __asm__("func_8004E9E4");
int Spawn89210QueryWorldHeightWithOptions(void*, int, int, int) __asm__("func_8001A310");
int Spawn89210QueryWorldHeight(void*, int) __asm__("func_8001A358");
extern int Spawn89210D_8006D07C __asm__("D_8006D07C");
extern int Spawn89210D_8006D080 __asm__("D_8006D080");
extern int Spawn89210D_8006D084 __asm__("D_8006D084");
extern int Spawn89210D_80071934 __asm__("D_80071934");
extern unsigned char Spawn89210PlayerE __asm__("D_80070328 + 0xE");
#define Spawn89210High(a, b)                                                         \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern unsigned char Spawn89210Color1[] __asm__("D_80066BAC");
extern unsigned char Spawn89210Color2[] __asm__("D_80066BAC");
#define Spawn89210Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Spawn89210BuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Spawn89210TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Spawn89210ShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
int Spawn89210CopyVector(void*, void*) __asm__("func_8004F178");
int Spawn89210AddVector(void*, void*, void*) __asm__("func_8004F194");
int Spawn89210MultiplyVectorGpfSf0(void*, void*, int) __asm__("func_8004F1FC");
int Spawn89210PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
void* Spawn89210AllocateParticleRecord(int) __asm__("func_80056434");
int Spawn89210RandBetween(int, int) __asm__("func_8003636C");
int Spawn89210CopyHalfwordVector(void*, void*) __asm__("func_8004F58C");
int Spawn89210rand(void) __asm__("rand");
extern unsigned char Spawn89210D_800658A0[] __asm__("D_800658A0");
extern unsigned char Spawn89210D_80065920[] __asm__("D_80065920");
extern unsigned char Spawn89210D_80066A28[] __asm__("D_80066A28");
extern unsigned char Spawn89210D_80066A48[] __asm__("D_80066A48");
extern unsigned char Spawn89210D_80066BAC[] __asm__("D_80066BAC");
extern unsigned char Spawn89210D_80070328[] __asm__("D_80070328");
extern int Spawn89210D_8006E344 __asm__("D_8006E344");
int Spawn89210NarrowWordVectorToHalfwords(void*, void*) __asm__("func_8004F570");
int Spawn89210AddHalfwordVectors(void*, void*, void*) __asm__("func_8004F5A8");
int Spawn89210RandSignedBetween(int, int) __asm__("func_800363DC");
int Spawn89210QueryWorldSegmentWithOptions(void*, void*, int, int, int) __asm__("func_8001830C");
extern int Spawn89210D_80071908 __asm__("D_80071908");
#define Spawn89210Stack(t, o) (*(t*)((unsigned char*)&frame + (o) - 0x18))
void* func_level_21_80089210(int entryCount, int kind, void* input, void* mode) {
    int frame[82];
    register int kindSelector __asm__("$22") = kind;
    register unsigned char* reference __asm__("$20") = input;
    register unsigned char* modeSelector __asm__("$23") = mode;
    register unsigned char* temp_s1 __asm__("$17");
    register unsigned char* temp_s1_2 __asm__("$17");
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    register int commonByte8 __asm__("$8");
    register int commonByte9 __asm__("$9");
    int byte128;
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
    record = 0;
    MATCHING_KEEP(record);
    Spawn89210Stack(int, 0x140) = entryCount;
    Spawn89210Stack(int, 0x148) = 0;
    if (entryCount > 0) {
        byte128 = 128;
        MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
        Spawn89210Stack(volatile int, 0x158) = 0;
        do {
            MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
            switch (kindSelector) {
                case 0x0:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$8");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$9");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = one;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210PackVectorShiftRight2(record + 0x18, modeSelector);
                    Spawn89210Field(record, short*, 0x1E) = 0;
                    Spawn89210Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Spawn89210rand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$3", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte9 = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte9, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Spawn89210Field(record, unsigned char*, 0xC) = byte128;
                        Spawn89210Field(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                        Spawn89210Field(record, unsigned char*, 0xE) = byte128;
                    }
                    MATCHING_KEEP_VOLATILE_CLOBBER(commonByte9, "memory");
                    Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x1:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210PackVectorShiftRight2(record + 0x18, modeSelector);
                    Spawn89210Field(record, short*, 0x1E) = 0;
                    Spawn89210Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Spawn89210rand();
                    Spawn89210Field(record, unsigned char*, 0xB) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 96;
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                    Spawn89210Field(record, unsigned char*, 0xC) = tailByte;
                    Spawn89210Field(record, unsigned char*, 0xD) = tailByte;
                    Spawn89210Field(record, unsigned char*, 0xE) = tailByte;
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                    tailByte = 4;
                    goto initializeF9;
                case 0x2:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3(tailByte, destination, source);
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                        tailByte = Spawn89210rand();
                        tailByte &= 63;
                        tailByte -= 32;
                        Spawn89210Stack(int, 0x18) = tailByte;
                        tailByte = Spawn89210rand();
                        destination = record + 24;
                        source = &Spawn89210Stack(int, 0x18);
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 63;
                        tailByte -= 32;
                        Spawn89210Stack(int, 0x1C) = tailByte;
                        Spawn89210Stack(int, 0x20) = 16;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    tailByte = 32;
                    Spawn89210Field(record, unsigned short*, 30) = 0;
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn89210rand();
                    commonByte9 = 46;
                    commonByte8 = 2;
                    MATCHING_KEEP3_CLOBBER(tailByte, commonByte9, commonByte8, "memory");
                    Spawn89210Field(record, volatile unsigned char*, 11) = tailByte;
                    Spawn89210Field(record, volatile unsigned char*, 12) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 13) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 14) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 15) = commonByte9;
                    Spawn89210Field(record, unsigned char*, 17) = commonByte8;
                    Spawn89210Field(record, unsigned char*, 16) = 0;
                    break;
                case 0x3:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int one __asm__("$2");
                        MATCHING_KEEP2_CLOBBER(destination, source, "$8");
                        one = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, one, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = one;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210PackVectorShiftRight2(record + 0x18, modeSelector);
                    Spawn89210Field(record, short*, 0x1E) = 0;
                    Spawn89210Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Spawn89210rand();
                    Spawn89210Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 64;
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Spawn89210Field(record, unsigned char*, 13) = tailByte;
                    tailByte = 2;
                    Spawn89210Field(record, unsigned char*, 12) = byte128;
                    Spawn89210Field(record, unsigned char*, 14) = 0;
                    __asm__ volatile("" ::"i"(0x80089444) : "memory");
                    Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x5:
                    record = Spawn89210AllocateParticleRecord(3);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn89210rand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 7;
                        Spawn89210Field(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 62;
                        component -= 31;
                        component += random;
                        Spawn89210Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 62;
                        component -= 31;
                        component += random;
                        Spawn89210Field(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 62;
                        Spawn89210Field(record, short*, 24) = 0;
                        Spawn89210Field(record, short*, 26) = 0;
                        Spawn89210Field(record, short*, 28) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component -= 31;
                        component += random;
                        Spawn89210Field(record, unsigned short*, 8) = component;
                    }
                    tailByte = Spawn89210rand();
                    tailByte &= 7;
                    {
                        register int value __asm__("$3") = tailByte + 18;
                        tailByte += 15;
                        Spawn89210Field(record, unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        Spawn89210Field(record, unsigned char*, 15) = tailByte;
                        tailByte = 4;
                        MATCHING_KEEP2_CLOBBER(tailByte, value, "memory");
                        Spawn89210Field(record, unsigned char*, 10) = value;
                        Spawn89210Field(record, unsigned char*, 12) = byte128;
                        Spawn89210Field(record, unsigned char*, 13) = byte128;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "$4");
                        Spawn89210Field(record, unsigned char*, 14) = byte128;
                    }
                    goto initializeTrailingBytes;
                case 0x6:
                    temp_s1 = Spawn89210Field(reference, unsigned char**, 0);
                    record = Spawn89210AllocateParticleRecord(3);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn89210rand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5");
                        scratch16 = (int)(reference + 12);
                        source = (void*)scratch16;
                        MATCHING_KEEP4(destination, source, scratch16, tailByte);
                        tailByte &= 15;
                        Spawn89210Field(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        component -= 63;
                        component += random;
                        Spawn89210Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 126;
                        Spawn89210Field(record, int*, 24) = scratch16;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                        component -= 63;
                        component += random;
                        Spawn89210Field(record, unsigned short*, 6) = component;
                    }
                    tailByte = Spawn89210Field(temp_s1, int*, 4);
                    Spawn89210Field(record, unsigned short*, 28) = tailByte;
                    {
                        register int value __asm__("$3") = Spawn89210Field(temp_s1, int*, 0);
                        tailByte = 32;
                        Spawn89210Field(record, unsigned char*, 10) = tailByte;
                        tailByte = 20;
                        Spawn89210Field(record, unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        MATCHING_KEEP2_CLOBBER(value, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 12) = byte128;
                        Spawn89210Field(record, unsigned char*, 13) = byte128;
                        Spawn89210Field(record, unsigned char*, 14) = byte128;
                        Spawn89210Field(record, unsigned char*, 15) = tailByte;
                        Spawn89210Field(record, unsigned char*, 17) = 0;
                        Spawn89210Field(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
                        value >>= 6;
                        Spawn89210Field(record, unsigned short*, 30) = value;
                    }
                    break;
                case 0x9:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* playerVector __asm__("$16") = &Spawn89210Stack(int, 0x28);
                        register void* destination __asm__("$4") = playerVector;
                        register unsigned char* player __asm__("$17");
                        register void* source __asm__("$5");
                        MATCHING_KEEP_CLOBBER(destination, "$17");
                        player = Spawn89210D_80070328;
                        source = player;
                        MATCHING_KEEP3_CLOBBER(destination, source, player, "$2");
                        tailByte = 1;
                        MATCHING_KEEP4_VOLATILE_CLOBBER(tailByte, destination, source, player,
                                                        "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210CopyVector(destination, source);
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x28);
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            Spawn89210Stack(int, 0x28) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = &Spawn89210Stack(int, 0x28);
                            __asm__(""
                                    : "=r"(destination), "=r"(source)
                                    : "0"(destination), "1"(source)
                                    : "$3", "memory");
                            component = Spawn89210Stack(int, 0x2C);
                            MATCHING_KEEP2(random, component);
                            random &= 0x7E;
                            MATCHING_KEEP2(random, component);
                            component -= 0x3F;
                            MATCHING_KEEP2(random, component);
                            component += random;
                            Spawn89210Stack(int, 0x2C) = component;
                            Spawn89210PackVectorShiftRight2(destination, source);
                        }
                        Spawn89210CopyVector(playerVector, player + 0x98);
                        Spawn89210ShiftVectorRightTowardZero(playerVector, 6);
                        Spawn89210PackVectorShiftRight2(record + 0x18, playerVector);
                    }
                    Spawn89210Field(record, short*, 0x1E) = 0;
                    Spawn89210Field(record, unsigned char*, 0xA) = 0x18;
                    tailByte = Spawn89210rand();
                    {
                        __asm__ volatile(""
                                         : "=r"(byte128), "=r"(tailByte)
                                         : "0"(byte128), "1"(tailByte)
                                         : "$4", "memory");
                        MATCHING_KEEP2_VOLATILE_CLOBBER(tailByte, byte128, "memory");
                        commonByte8 = 46;
                        MATCHING_KEEP2_CLOBBER(commonByte8, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 0xB) = tailByte;
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        MATCHING_KEEP_VOLATILE_CLOBBER(tailByte, "memory");
                        tailByte = 4;
                        Spawn89210Field(record, unsigned char*, 0xC) = byte128;
                        Spawn89210Field(record, unsigned char*, 0xD) = byte128;
                        __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$4", "memory");
                        Spawn89210Field(record, unsigned char*, 0xE) = byte128;
                    }
                    goto initializeF9;
                case 0xA:
                    record = Spawn89210AllocateParticleRecord(3);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = Spawn89210D_80070328;
                        tailByte = Spawn89210rand();
                        destination = record + 4;
                        source = Spawn89210D_80070328;
                        tailByte &= 31;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 2) = tailByte;
                        MATCHING_KEEP_CLOBBER(tailByte, "memory");
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
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
                        Spawn89210Field(record, unsigned char*, 10) = value;
                        value = 15;
                        Spawn89210Field(record, unsigned char*, 11) = value;
                        MATCHING_KEEP_CLOBBER(factor, "memory");
                        count = Spawn89210Stack(int, 0x140);
                        iteration8 = Spawn89210Stack(int, 0x148);
                        MATCHING_KEEP2(count, iteration8);
                        factor |= 0x6667;
                        dividend = count - iteration8;
                        count = Spawn89210Stack(volatile int, 0x158);
                        MATCHING_KEEP2(count, dividend);
                        dividend <<= 12;
                        value = *(Spawn89210D_80066BAC + count);
                        MATCHING_KEEP2_CLOBBER(dividend, factor, "memory");
                        productHigh = Spawn89210High(dividend, factor);
                        Spawn89210Field(record, unsigned char*, 12) = value;
                        value = *(Spawn89210Color1 + 1 + count);
                        dividend >>= 31;
                        Spawn89210Field(record, unsigned char*, 13) = value;
                        color = *(Spawn89210Color2 + 2 + count);
                        value = 44;
                        Spawn89210Field(record, unsigned char*, 15) = value;
                        value = 4;
                        Spawn89210Field(record, unsigned char*, 17) = value;
                        Spawn89210Field(record, unsigned char*, 16) = 0;
                        Spawn89210Field(record, unsigned char*, 14) = color;
                        __asm__(""
                                : "=h"(productHigh), "=r"(dividend)
                                : "0"(productHigh), "1"(dividend)
                                : "memory");
                        iteration8 = productHigh;
                        MATCHING_KEEP(iteration8);
                        value = (iteration8 >> 1) - dividend;
                        Spawn89210Field(record, short*, 24) = value;
                    }
                    break;
                case 0xC:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = reference + 32;
                        register int iteration __asm__("$9");
                        register void* vector __asm__("$6");
                        register int base __asm__("$2");
                        register void* table __asm__("$5");
                        __asm__("" : "=r"(destination) : "0"(destination) : "$2", "$5", "memory");
                        base = (int)Spawn89210D_80066A48;
                        vector16 = &Spawn89210Stack(int, 0x38);
                        MATCHING_KEEP_CLOBBER(vector16, "memory");
                        iteration = Spawn89210Stack(int, 0x148);
                        __asm__ volatile("" : "=r"(iteration) : "0"(iteration) : "$6", "memory");
                        vector = vector16;
                        MATCHING_KEEP4_CLOBBER(vector16, vector, iteration, base, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        table = (void*)(iteration * 12);
                        MATCHING_KEEP2(table, base);
                        table = (void*)((int)table + base);
                        __asm__("" : "=r"(table) : "0"(table) : "$2", "memory");
                        base = 1;
                        Spawn89210Field(record, unsigned char*, 3) = base;
                        base = 4;
                        Spawn89210Field(record, unsigned char*, 17) = base;
                        Spawn89210TransformVectorByBasis(destination, table, vector);
                    }
                    if (({
                            register int observed __asm__("$2") =
                                Spawn89210Field(reference, short*, 54);
                            MATCHING_KEEP_CLOBBER(observed, "memory");
                            scratch17 = 0x17D;
                            MATCHING_KEEP_CLOBBER(scratch17, "memory");
                            observed == scratch17;
                        })) {
                        Spawn89210MultiplyVectorGpfSf0(vector16, vector16, 3);
                    }
                    Spawn89210AddVector(vector16, vector16, reference + 0xC);
                    if (modeSelector == (unsigned char*)5) {
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x38);
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x38) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x3C);
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x3C) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x40);
                            MATCHING_KEEP2(random, component);
                            random &= 0x1FF;
                            MATCHING_KEEP2(random, component);
                            component += 0x100;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x40) = component;
                        }
                    }
                    if (modeSelector == (unsigned char*)6) {
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x38);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x38) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x3C);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x3C) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x40);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x40) = component;
                        }
                    }
                    if (Spawn89210Field(reference, short*, 0x36) == 0xB6) {
                        Spawn89210Stack(int, 0x40) += 0x200;
                    }
                    Spawn89210PackVectorShiftRight2(record + 4, vector16);
                    Spawn89210Field(record, int*, 0xC) =
                        (int)*(int*)(Spawn89210D_80066A28 + ((int)modeSelector * 4));
                    if (({
                            register int observed __asm__("$2") =
                                Spawn89210Field(reference, short*, 54);
                            MATCHING_KEEP_CLOBBER(scratch17, "memory");
                            observed == scratch17;
                        })) {
                        var_v0_2 = (Spawn89210rand() & 0x1F) + 0x60;
                    } else {
                        var_v0_2 = (Spawn89210rand() & 7) + 0x20;
                    }
                    Spawn89210Field(record, unsigned char*, 0xA) = var_v0_2;
                    tailByte = Spawn89210rand();
                    {
                        register void* destination __asm__("$4") = record + 24;
                        register int iteration __asm__("$8") = Spawn89210Stack(int, 0x148);
                        register int base __asm__("$3");
                        register void* source __asm__("$5");
                        __asm__(""
                                : "=r"(destination), "=r"(iteration), "=r"(tailByte)
                                : "0"(destination), "1"(iteration), "2"(tailByte)
                                : "$3", "$5", "memory");
                        base = (int)Spawn89210D_80066A48;
                        Spawn89210Field(record, unsigned char*, 11) = tailByte;
                        Spawn89210Field(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP2_CLOBBER(base, iteration, "memory");
                        source = (void*)(iteration * 12);
                        MATCHING_KEEP2(source, base);
                        source = (void*)((int)source + base);
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210Field(record, unsigned short*, 0x18) =
                        (unsigned short)(((int)(Spawn89210Field(record, unsigned short*, 0x18)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Spawn89210rand() & 7));
                    Spawn89210Field(record, unsigned short*, 0x1A) =
                        (unsigned short)(((int)(Spawn89210Field(record, unsigned short*, 0x1A)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Spawn89210rand() & 7));
                    Spawn89210Field(record, unsigned short*, 0x1C) =
                        (unsigned short)(((int)(Spawn89210Field(record, unsigned short*, 0x1C)
                                                << 0x10) >>
                                          0x12) -
                                         4 + (Spawn89210rand() & 7));
                    break;
                case 0xD:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210PackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Spawn89210Field(record, unsigned short*, 30) = 0;
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn89210rand();
                    commonByte9 = 255;
                    commonByte8 = 255;
                    MATCHING_KEEP3_CLOBBER(commonByte9, commonByte8, tailByte, "memory");
                    Spawn89210Field(record, unsigned char*, 12) = commonByte9;
                    commonByte9 = 46;
                    Spawn89210Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Spawn89210Field(record, unsigned char*, 13) = commonByte8;
                    Spawn89210Field(record, unsigned char*, 14) = 0;
                    Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0xE: {
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int value4 __asm__("$4");
                    register int value5 __asm__("$5");
                    register int low8 __asm__("$8");
                    register int low9 __asm__("$9");
                    register void* vector17 __asm__("$17");
                    register void* vector18 __asm__("$18");
                    register void* vector16 __asm__("$16");
                    int productLo;
                    value2 = Spawn89210rand();
                    value2 &= 1;
                    if (value2) {
                        value2 = Spawn89210rand();
                        value3 = Spawn89210D_8006E040;
                        value2 &= 1023;
                        value2 -= 512;
                        scratch17 = value3 - value2;
                    } else {
                        value2 = Spawn89210rand();
                        scratch17 = value2 & 4095;
                    }
                    value2 = Spawn89210rand();
                    value4 = scratch17;
                    scratch19 = value2 & 16383;
                    value2 = Spawn89210InterpolateCosine(value4);
                    scratch16 = value2;
                    value2 = Spawn89210rand();
                    productLo = scratch16 * scratch19;
                    __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                    value4 = scratch17;
                    value2 &= 2047;
                    value2 -= 1024;
                    value3 = Spawn89210Field(Spawn89210D_80070328, int*, 0x98);
                    value5 = Spawn89210D_8006E020;
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
                    Spawn89210Stack(int, 0x48) = value5;
                    value2 = Spawn89210InterpolateSine(value4);
                    scratch16 = value2;
                    value2 = Spawn89210rand();
                    productLo = scratch16 * scratch19;
                    __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                    value2 &= 2047;
                    value3 = Spawn89210D_8006E028;
                    value2 -= 1024;
                    value3 += 16384;
                    Spawn89210Stack(int, 0x50) = value3;
                    value3 = Spawn89210Field(Spawn89210D_80070328, int*, 0x9C);
                    value4 = Spawn89210D_8006E024;
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
                    value3 = Spawn89210Stack(int, 0x48);
                    value4 -= value2;
                    Spawn89210Stack(int, 0x4C) = value4;
                    if (value3 <= 0)
                        break;
                    if (value4 <= 0)
                        break;
                    value2 = Spawn89210QueryWorldHeightWithOptions(&Spawn89210Stack(int, 0x48),
                                                                   0x60C0, 2, 0);
                    scratch16 = value2;
                    if (reference) {
                        value2 = Spawn89210rand();
                        value2 &= 8191;
                        value3 = Spawn89210D_8006E028;
                        value2 -= 2048;
                        goto rawHeightE;
                    }
                    value2 = Spawn89210D_8006E03E;
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
                    value3 = Spawn89210D_8006E028;
                    value2 += 2048;
                rawHeightE:
                    value3 += value2;
                    Spawn89210Stack(int, 0x50) = value3;
                    goto heightDoneE;
                baseHeightE:
                    value2 = Spawn89210D_8006E028;
                    value2 += 8192;
                    Spawn89210Stack(int, 0x50) = value2;
                heightDoneE:
                    if (Spawn89210Stack(int, 0x50) < scratch16 + 1024)
                        break;
                    if (scratch16 && Spawn89210D_80071920 <= 0)
                        break;
                    record = Spawn89210AllocateParticleRecord(3);
                    value5 = 1;
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) = 0;
                    Spawn89210Field(record, unsigned char*, 3) = value5;
                    if (scratch16 == 0) {
                        value2 = Spawn89210Stack(int, 0x50);
                        scratch16 = value2 - 16384;
                        if (scratch16 < 1024)
                            scratch16 = 1024;
                    } else {
                        value2 = Spawn89210D_80071918;
                        value3 = Spawn89210D_8007191C;
                        value4 = Spawn89210D_80071920;
                        if (value2 < 0)
                            value2 = -value2;
                        if (value3 < 0)
                            value3 = -value3;
                        value2 += value3;
                        if (value2 < value4)
                            Spawn89210Field(record, unsigned char*, 2) = value5;
                    }
                    vector18 = record + 4;
                    value2 = Spawn89210rand();
                    Spawn89210Stack(int, 0x58) = value2 & 3;
                    value2 = Spawn89210rand();
                    Spawn89210Stack(int, 0x5C) = value2 & 3;
                    value2 = Spawn89210rand();
                    value2 &= 7;
                    value3 = Spawn89210Stack(int, 0x50);
                    value2 += 10;
                    value3 -= scratch16;
                    value3 >>= 2;
                    value3 /= value2;
                    value5 = (int)&Spawn89210Stack(int, 0x48);
                    Spawn89210Stack(int, 0x60) = value2;
                    value4 = (int)vector18;
                    Spawn89210Field(record, unsigned short*, 0x1C) = value3;
                    Spawn89210Stack(int, 0x50) = scratch16;
                    Spawn89210PackVectorShiftRight2((void*)value4, (void*)value5);
                    vector17 = &Spawn89210Stack(int, 0x68);
                    value4 = (int)vector17;
                    value5 = (int)&Spawn89210Stack(int, 0x58);
                    Spawn89210MultiplyVectorGpfSf0((void*)value4, (void*)value5,
                                                   Spawn89210Field(record, short*, 0x1C));
                    vector16 = &Spawn89210Stack(int, 0x78);
                    Spawn89210NarrowWordVectorToHalfwords(vector16, vector17);
                    Spawn89210AddHalfwordVectors(vector18, vector18, vector16);
                    value2 = Spawn89210Field(record, unsigned short*, 4);
                    value3 = Spawn89210Field(record, unsigned short*, 6);
                    Spawn89210Field(record, unsigned short*, 24) = value2;
                    Spawn89210Field(record, unsigned short*, 26) = value3;
                    value2 = Spawn89210rand();
                    Spawn89210Field(record, unsigned char*, 30) = value2;
                    value2 = Spawn89210rand();
                    value2 &= 3;
                    value2 += 1;
                    Spawn89210Field(record, unsigned char*, 31) = value2;
                    value2 = Spawn89210Stack(int, 0x58);
                    value2 = -value2;
                    Spawn89210Field(record, unsigned short*, 18) = value2;
                    value2 = Spawn89210Stack(int, 0x5C);
                    value2 = -value2;
                    Spawn89210Field(record, unsigned short*, 20) = value2;
                    value2 = Spawn89210Stack(int, 0x60);
                    value2 = -value2;
                    Spawn89210Field(record, unsigned short*, 22) = value2;
                    value2 = Spawn89210rand();
                    value2 &= 7;
                    value2 += 20;
                    Spawn89210Field(record, unsigned char*, 10) = value2;
                    value2 = Spawn89210rand();
                    value2 &= 7;
                    value2 += 12;
                    Spawn89210Field(record, volatile unsigned char*, 11) = value2;
                    value2 = 44;
                    Spawn89210Field(record, volatile unsigned char*, 12) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 13) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 14) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 15) = value2;
                    Spawn89210Field(record, volatile unsigned char*, 17) = 0;
                    Spawn89210Field(record, unsigned char*, 16) = 0;
                    break;
                }
                case 0xF:
                    record = Spawn89210AllocateParticleRecord(3);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn89210rand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 7;
                        Spawn89210Field(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    tailByte = Spawn89210RandSignedBetween(0, 35);
                    Spawn89210Field(record, unsigned short*, 24) = tailByte;
                    tailByte = Spawn89210RandSignedBetween(0, 35);
                    Spawn89210Field(record, unsigned short*, 26) = tailByte;
                    tailByte = Spawn89210RandBetween(-20, 35);
                    Spawn89210Field(record, unsigned short*, 28) = tailByte;
                    {
                        register int x __asm__("$3") = Spawn89210Field(record, unsigned short*, 4);
                        register int vx __asm__("$4") =
                            Spawn89210Field(record, unsigned short*, 24);
                        register int y __asm__("$2");
                        register int vy __asm__("$4");
                        register int z __asm__("$3");
                        register int vz __asm__("$5");
                        MATCHING_KEEP2_CLOBBER(x, vx, "memory");
                        y = Spawn89210Field(record, unsigned short*, 6);
                        vz = Spawn89210Field(record, unsigned short*, 28);
                        MATCHING_KEEP4_CLOBBER(x, vx, y, vz, "memory");
                        x += vx;
                        vy = Spawn89210Field(record, unsigned short*, 26);
                        Spawn89210Field(record, unsigned short*, 4) = x;
                        z = Spawn89210Field(record, unsigned short*, 8);
                        y += vy;
                        z += vz;
                        Spawn89210Field(record, unsigned short*, 6) = y;
                        Spawn89210Field(record, unsigned short*, 8) = z;
                    }
                    tailByte = Spawn89210rand();
                    tailByte &= 7;
                    {
                        register int value __asm__("$3") = tailByte + 18;
                        tailByte += 15;
                        Spawn89210Field(record, unsigned char*, 11) = tailByte;
                        tailByte = 44;
                        Spawn89210Field(record, unsigned char*, 15) = tailByte;
                        tailByte = 4;
                        MATCHING_KEEP2_CLOBBER(tailByte, value, "memory");
                        Spawn89210Field(record, unsigned char*, 10) = value;
                        Spawn89210Field(record, unsigned char*, 12) = byte128;
                        Spawn89210Field(record, unsigned char*, 13) = byte128;
                        Spawn89210Field(record, unsigned char*, 14) = byte128;
                    }
                    goto initializeTrailingBytes;
                case 0x12:
                    record = Spawn89210AllocateParticleRecord(4);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210CopyHalfwordVector(destination, source);
                    }
                    tailByte = Spawn89210rand();
                    tailByte &= 6;
                    MATCHING_KEEP(tailByte);
                    tailByte += 14;
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    {
                        register int value3 __asm__("$3") = Spawn89210PlayerE;
                        tailByte = 32;
                        Spawn89210Field(record, volatile unsigned char*, 12) = tailByte;
                        Spawn89210Field(record, volatile unsigned char*, 13) = tailByte;
                        tailByte = 64;
                        commonByte8 = 46;
                        Spawn89210Field(record, volatile unsigned char*, 14) = tailByte;
                        tailByte = 2;
                        Spawn89210Field(record, volatile unsigned char*, 15) = commonByte8;
                        Spawn89210Field(record, volatile unsigned char*, 17) = tailByte;
                        Spawn89210Field(record, volatile unsigned char*, 16) = 0;
                        __asm__ volatile("" ::"i"(0x80089E94) : "memory");
                        Spawn89210Field(record, unsigned char*, 11) = value3;
                    }
                    break;
                case 0x21:
                    record = Spawn89210AllocateParticleRecord(2);
                    tailByte = 1;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) = 0;
                    Spawn89210Field(record, unsigned char*, 3) = tailByte;
                    if (modeSelector == 0) {
                        {
                            register void* destination __asm__("$4");
                            scratch16 = (int)&Spawn89210Stack(int, 0x90);
                            destination = (void*)scratch16;
                            MATCHING_KEEP2_CLOBBER(scratch16, destination, "$17");
                            temp_s1 = Spawn89210D_80070328 + 0x98;
                            Spawn89210CopyVector(destination, temp_s1);
                        }
                        Spawn89210ShiftVectorRightTowardZero((void*)scratch16, 6);
                        Spawn89210CopyVector(&Spawn89210Stack(int, 0x80), temp_s1 - 0x98);
                        Spawn89210Stack(int, 0x88) -= 0x164;
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x80);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x80) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3");
                            MATCHING_KEEP_CLOBBER(random, "$18");
                            scratch19 = 48;
                            component = Spawn89210Stack(int, 0x84);
                            MATCHING_KEEP2(random, component);
                            random &= 0xFF;
                            MATCHING_KEEP2(random, component);
                            component += 0x80;
                            MATCHING_KEEP2(random, component);
                            component -= random;
                            Spawn89210Stack(int, 0x84) = component;
                        }
                        goto setDestination;
                    } else {
                        register int one __asm__("$9") = 1;
                        MATCHING_KEEP(one);
                        if (modeSelector == (unsigned char*)one) {
                            {
                                register void* base4 __asm__("$4") = Spawn89210D_80070328 + 0x30;
                                register void* arg5 __asm__("$5");
                                register void* arg6 __asm__("$6");
                                __asm__("" : "=r"(base4) : "0"(base4) : "$16", "memory");
                                scratch16 = (int)&Spawn89210Stack(int, 0x80);
                                arg5 = (void*)scratch16;
                                arg6 = arg5;
                                Spawn89210Stack(int, 0x80) = 0x164;
                                Spawn89210Stack(int, 0x84) = 0;
                                Spawn89210Stack(int, 0x88) = 0;
                                Spawn89210TransformVectorByBasis(base4, arg5, arg6);
                            }
                            {
                                register void* arg4 __asm__("$4") = (void*)scratch16;
                                register void* arg5 __asm__("$5") = arg4;
                                register unsigned char* table9 __asm__("$8") =
                                    Spawn89210D_80070328 + 0x30;
                                MATCHING_KEEP3_CLOBBER(arg4, arg5, table9, "memory");
                                Spawn89210AddVector(arg4, arg5, table9 - 0x30);
                            }
                            scratch19 = 0x40;
                            Spawn89210Stack(int, 0x90) = -(Spawn89210rand() & 7);
                            {
                                register int random __asm__("$2") = Spawn89210rand();
                                register int component __asm__("$3");
                                register void* destination __asm__("$4") =
                                    Spawn89210D_80070328 + 0x30;
                                register void* vector __asm__("$5") = &Spawn89210Stack(int, 0x90);
                                register int iteration8 __asm__("$9") = Spawn89210Stack(int, 0x148);
                                register int angle __asm__("$7");
                                register void* output __asm__("$6") = vector;
                                MATCHING_KEEP3_CLOBBER(destination, vector, output, "memory");
                                MATCHING_KEEP(iteration8);
                                random &= 15;
                                angle = iteration8 << 6;
                                component = *(unsigned short*)(Spawn89210D_80065920 + angle);
                                MATCHING_KEEP_CLOBBER(random, "memory");
                                random -= 8;
                                MATCHING_KEEP(random);
                                component = (component << 16) >> 23;
                                component -= random;
                                Spawn89210Stack(int, 0x94) = component;
                                random = *(unsigned short*)(Spawn89210D_800658A0 + angle);
                                random = (random << 16) >> 23;
                                Spawn89210Stack(int, 0x98) = random;
                                Spawn89210TransformVectorByBasis(destination, vector, output);
                            }
                            var_a0 = record + 4;
                            goto finishMode;
                        } else {
                            register int two __asm__("$8") = 2;
                            MATCHING_KEEP(two);
                            scratch16 = 5;
                            if (modeSelector == (unsigned char*)two) {
                                {
                                    register int iteration8 __asm__("$9") =
                                        Spawn89210Stack(int, 0x148);
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
                                    register int iteration9 __asm__("$8") =
                                        Spawn89210Stack(int, 0x148);
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
                    Spawn89210CopyVector(&Spawn89210Stack(int, 0x80), Spawn89210D_80070328);
                    {
                        register short* first __asm__("$5") = (short*)Spawn89210D_80065920;
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
                        other = Spawn89210Stack(int, 0x80);
                        value >>= scratch16;
                        other += value;
                        value = (int)Spawn89210D_800658A0;
                        second += value;
                        value = Spawn89210Stack(int, 0x88);
                        Spawn89210Stack(int, 0x80) = other;
                        other = *(short*)second;
                        value -= 356;
                        Spawn89210Stack(int, 0x88) = value;
                        value = Spawn89210Stack(int, 0x84);
                        other >>= scratch16;
                        value += other;
                        Spawn89210Stack(int, 0x84) = value;
                        __asm__(""
                                : "=r"(first), "=r"(second)
                                : "0"(first), "1"(second)
                                : "$2", "$3", "memory");
                        value = *first;
                        other = scratch16 + 1;
                        value >>= other;
                        Spawn89210Stack(int, 0x90) = value;
                        value = *(short*)second;
                        Spawn89210Stack(int, 0x98) = 0;
                        value >>= other;
                        Spawn89210Stack(int, 0x94) = value;
                    }
                setDestination:
                    var_a0 = record + 4;
                finishMode:
                    Spawn89210PackVectorShiftRight2(var_a0, &Spawn89210Stack(int, 0x80));
                    Spawn89210PackVectorShiftRight2(record + 0x18, &Spawn89210Stack(int, 0x90));
                    Spawn89210Field(record, short*, 0x1E) = 0;
                    Spawn89210Field(record, unsigned char*, 0xA) = 0x10;
                    tailByte = Spawn89210rand();
                    commonByte9 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte9, "memory");
                    Spawn89210Field(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Spawn89210Field(record, volatile unsigned char*, 12) = scratch19;
                    Spawn89210Field(record, volatile unsigned char*, 13) = scratch19;
                    Spawn89210Field(record, volatile unsigned char*, 14) = scratch19;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                case 0x29: {
                    register unsigned char* stackBase29 __asm__("$29");
                    register void* vector16 __asm__("$16");
                    register void* vector17 __asm__("$17");
                    register int angle21 __asm__("$21");
                    register int radius19 __asm__("$18");
                    register int value2 __asm__("$2");
                    register int value3 __asm__("$3");
                    register int index4 __asm__("$4");
                    register int low8 __asm__("$9");
                    register int low9 __asm__("$8");
                    register void* destination4 __asm__("$4");
                    register void* source5 __asm__("$5");
                    __asm__ volatile("" ::: "$16", "memory");
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned int)&frame - 0x18)
                                     : "memory");
                    vector16 = stackBase29 + 0xA0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    Spawn89210CopyVector(vector16, reference);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    value2 = Spawn89210rand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    value3 = Spawn89210Stack(int, 0xA0);
                    value2 &= 255;
                    value3 += 128;
                    value3 -= value2;
                    Spawn89210Stack(int, 0xA0) = value3;
                    value2 = Spawn89210rand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    value3 = Spawn89210Stack(int, 0xA4);
                    value2 &= 255;
                    value3 += 128;
                    value3 -= value2;
                    Spawn89210Stack(int, 0xA4) = value3;
                    value2 = Spawn89210rand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    angle21 = value2 & 255;
                    value2 = Spawn89210rand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    {
                        register void* arg4 __asm__("$4") = &Spawn89210Stack(int, 0xB0);
                        register void* arg5 __asm__("$5") = vector16;
                        MATCHING_KEEP3(arg4, arg5, value2);
                        value2 &= 1023;
                        radius19 = value2 + 512;
                        Spawn89210CopyVector(arg4, arg5);
                        MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    }
                    destination4 = &Spawn89210Stack(int, 0xC0);
                    if (modeSelector != 0)
                        source5 = modeSelector;
                    else {
                        source5 = Spawn89210D_80070328 + 0x8C;
                        MATCHING_KEEP_VOLATILE_CLOBBER(source5, "memory");
                    }
                    Spawn89210CopyVector(destination4, source5);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    __asm__ volatile("" ::: "$16", "memory");
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned int)&frame - 0x18)
                                     : "memory");
                    vector16 = stackBase29 + 0xC0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    Spawn89210ShiftVectorRightTowardZero(vector16, 1);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    {
                        register int count9 __asm__("$8") = Spawn89210Stack(int, 0x140);
                        register int one8 __asm__("$9") = 1;
                        MATCHING_KEEP2(count9, one8);
                        __asm__ volatile("" ::: "$17", "memory");
                        __asm__ volatile(""
                                         : "=r"(stackBase29)
                                         : "0"((unsigned int)&frame - 0x18)
                                         : "memory");
                        vector17 = stackBase29 + 0xB0;
                        if (count9 == one8) {
                            Spawn89210MultiplyVectorGpfSf0(vector16, vector16, 3);
                            MATCHING_KEEP_VOLATILE_CLOBBER(vector17, "memory");
                            __asm__ volatile("" ::: "$17", "memory");
                            __asm__ volatile(""
                                             : "=r"(stackBase29)
                                             : "0"((unsigned int)&frame - 0x18)
                                             : "memory");
                            vector17 = stackBase29 + 0xB0;
                            MATCHING_KEEP_VOLATILE_CLOBBER(vector17, "memory");
                        }
                    }
                    Spawn89210Stack(int, 0xC8) = 0;
                    Spawn89210AddVector(vector17, vector17, vector16);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    index4 = angle21 << 1;
                    value2 = Spawn89210Field(Spawn89210D_80065920 + index4, short*, 0);
                    __asm__ volatile("" : "=l"(low9) : "0"(value2 * radius19) : "memory");
                    value2 = Spawn89210Stack(int, 0xB0);
                    value3 = low9 >> 12;
                    value2 += value3;
                    Spawn89210Stack(int, 0xB0) = value2;
                    value2 = Spawn89210Field(Spawn89210D_800658A0 + index4, short*, 0);
                    {
                        int productLo = value2 * radius19;
                        __asm__ volatile("" : "=l"(productLo) : "0"(productLo) : "memory");
                        source5 = (void*)1024;
                        value2 = Spawn89210Stack(int, 0xB8);
                        MATCHING_KEEP2_CLOBBER(source5, value2, "$4");
                        destination4 = vector17;
                        MATCHING_KEEP3(source5, value2, destination4);
                        value2 += 512;
                        Spawn89210Stack(int, 0xB8) = value2;
                        value2 = Spawn89210Stack(int, 0xB4);
                        __asm__ volatile(""
                                         : "=l"(productLo), "=r"(value2)
                                         : "0"(productLo), "1"(value2)
                                         : "memory");
                        low8 = productLo;
                        MATCHING_KEEP(low8);
                        value3 = low8 >> 12;
                        value2 += value3;
                        Spawn89210Stack(int, 0xB4) = value2;
                        value2 = Spawn89210QueryWorldHeight(destination4, (int)source5);
                    }
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    Spawn89210Stack(int, 0xB8) = value2;
                    if (value2 == 0)
                        break;
                    record = Spawn89210AllocateParticleRecord(3);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    value2 = 1;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    Spawn89210Field(record, volatile unsigned char*, 3) = value2;
                    value2 = 10;
                    MATCHING_KEEP_CLOBBER(value2, "memory");
                    Spawn89210Field(record, volatile unsigned char*, 10) = value2;
                    value2 = 6;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$4", "memory");
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) = 0;
                    destination4 = record + 4;
                    MATCHING_KEEP(destination4);
                    Spawn89210Field(record, unsigned char*, 11) = value2;
                    value2 = Spawn89210D_8006D07C;
                    __asm__ volatile("" : "=r"(value2) : "0"(value2) : "$16", "memory");
                    __asm__ volatile("" ::: "$16", "memory");
                    __asm__ volatile(""
                                     : "=r"(stackBase29)
                                     : "0"((unsigned int)&frame - 0x18)
                                     : "memory");
                    vector16 = stackBase29 + 0xA0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(vector16, "memory");
                    value2 >>= 4;
                    Spawn89210Field(record, unsigned char*, 12) = value2;
                    value2 = Spawn89210D_8006D080;
                    __asm__("" : "=r"(value2) : "0"(value2) : "$5", "memory");
                    source5 = vector16;
                    MATCHING_KEEP2(value2, source5);
                    value2 >>= 4;
                    Spawn89210Field(record, unsigned char*, 13) = value2;
                    value3 = Spawn89210D_8006D084;
                    __asm__ volatile("" : "=r"(value3) : "0"(value3) : "$8", "$2", "memory");
                    commonByte8 = 46;
                    value2 = 2;
                    MATCHING_KEEP3(value3, commonByte8, value2);
                    Spawn89210Field(record, unsigned char*, 15) = commonByte8;
                    Spawn89210Field(record, unsigned char*, 17) = value2;
                    Spawn89210Field(record, unsigned char*, 16) = 0;
                    MATCHING_KEEP_VOLATILE_CLOBBER(value3, "memory");
                    value3 >>= 4;
                    Spawn89210Field(record, unsigned char*, 14) = value3;
                    Spawn89210PackVectorShiftRight2(destination4, source5);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    Spawn89210PackVectorShiftRight2(record + 18, vector16);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    Spawn89210PackVectorShiftRight2(record + 24, vector17);
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    scratch16 = Spawn89210rand();
                    value2 = Spawn89210rand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    scratch16 &= 14;
                    value2 = (value2 & 6) + 20;
                    scratch16 += value2;
                    Spawn89210Field(record, unsigned short*, 22) = scratch16;
                    Spawn89210Field(record, unsigned char*, 30) = 0;
                    while (scratch16 > 0 ||
                           Spawn89210Stack(int, 0xA8) > Spawn89210Stack(int, 0xB8)) {
                        Spawn89210Stack(int, 0xA8) += scratch16 << 2;
                        Spawn89210Field(record, unsigned char*, 30) += 1;
                        scratch16 -= 2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch16, "memory");
                    }
                    value2 = Spawn89210rand();
                    MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
                    Spawn89210Field(record, unsigned char*, 29) = value2;
                    Spawn89210Field(record, unsigned char*, 31) = Spawn89210D_80071934;
                } break;
                case 0x2A:
                    record = Spawn89210AllocateParticleRecord(4);
                    {
                        register void* arg4 __asm__("$4") = record + 4;
                        register void* arg5 __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(arg4, arg5, "$2");
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(arg4, arg5);
                    }
                    tailByte = Spawn89210Field(reference, int*, 0);
                    Spawn89210Field(record, int*, 24) = tailByte;
                    tailByte = Spawn89210Field(reference, int*, 4);
                    Spawn89210Field(record, int*, 28) = tailByte;
                    tailByte = Spawn89210Field(modeSelector, int*, 0);
                    Spawn89210Field(record, unsigned short*, 18) = tailByte;
                    tailByte = Spawn89210Field(modeSelector, int*, 4);
                    Spawn89210Field(record, unsigned short*, 20) = tailByte;
                    tailByte = Spawn89210rand();
                    tailByte = (tailByte & 7) + 3;
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    tailByte = 108;
                    __asm__("" : "=r"(tailByte) : "0"(tailByte) : "$3", "$9", "memory");
                    {
                        register int color3 __asm__("$3") = Spawn89210PlayerE;
                        __asm__(""
                                : "=r"(color3), "=r"(tailByte)
                                : "0"(color3), "1"(tailByte)
                                : "$9", "memory");
                        commonByte9 = 46;
                        Spawn89210Field(record, unsigned char*, 12) = tailByte;
                        Spawn89210Field(record, unsigned char*, 13) = tailByte;
                        Spawn89210Field(record, unsigned char*, 14) = tailByte;
                        Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                        Spawn89210Field(record, unsigned char*, 17) = 0;
                        Spawn89210Field(record, unsigned char*, 16) = 0;
                        MATCHING_KEEP_VOLATILE_CLOBBER(color3, "memory");
                        color3 += 32;
                        Spawn89210Field(record, unsigned char*, 11) = color3;
                    }
                    break;
                    {
                        register int commonByte3 __asm__("$3");
                        case 0x2B:
                            record = Spawn89210AllocateParticleRecord(4);
                            tailByte = 1;
                            Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                            Spawn89210Field(record, unsigned char*, 2) = 0;
                            Spawn89210Field(record, unsigned char*, 3) = tailByte;
                            if (modeSelector == 0) {
                                Spawn89210CopyHalfwordVector(record + 4, reference);
                                tailByte = Spawn89210rand();
                                tailByte &= 7;
                                tailByte += 2;
                                Spawn89210Field(record, unsigned char*, 10) = tailByte;
                                commonByte3 = 96;
                            } else {
                                Spawn89210PackVectorShiftRight2(record + 4, reference);
                                {
                                    register int two __asm__("$8") = 2;
                                    MATCHING_KEEP(two);
                                    if (modeSelector == (unsigned char*)two) {
                                        {
                                            register int random __asm__("$2") = Spawn89210rand();
                                            register int component __asm__("$3") =
                                                Spawn89210Field(record, unsigned short*, 4);
                                            MATCHING_KEEP2(random, component);
                                            random &= 127;
                                            component += 32;
                                            component -= random;
                                            Spawn89210Field(record, unsigned short*, 4) = component;
                                        }
                                        {
                                            register int random __asm__("$2") = Spawn89210rand();
                                            register int component __asm__("$3") =
                                                Spawn89210Field(record, unsigned short*, 6);
                                            MATCHING_KEEP2(random, component);
                                            random &= 127;
                                            component += 32;
                                            component -= random;
                                            Spawn89210Field(record, unsigned short*, 6) = component;
                                        }
                                    }
                                }
                                tailByte = Spawn89210rand();
                                tailByte &= 7;
                                MATCHING_KEEP(tailByte);
                                tailByte += 16;
                                Spawn89210Field(record, unsigned char*, 10) = tailByte;
                                commonByte3 = 64;
                            }
                            {
                                register int sourceByte __asm__("$2") =
                                    Spawn89210Field(Spawn89210D_80070328, unsigned char*, 14);
                                MATCHING_KEEP2_CLOBBER(sourceByte, commonByte3, "memory");
                                Spawn89210Field(record, unsigned char*, 12) = commonByte3;
                                Spawn89210Field(record, unsigned char*, 13) = commonByte3;
                                Spawn89210Field(record, unsigned char*, 14) = commonByte3;
                                commonByte9 = 46;
                                MATCHING_KEEP2_CLOBBER(sourceByte, commonByte9, "memory");
                                Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                                Spawn89210Field(record, unsigned char*, 17) = 0;
                                Spawn89210Field(record, unsigned char*, 16) = 0;
                                Spawn89210Field(record, unsigned short*, 24) = (int)modeSelector;
                                Spawn89210Field(record, unsigned char*, 11) = sourceByte;
                            }
                            break;
                    }
                case 0x2C: {
                    register void* vector17 __asm__("$17");
                    register unsigned char* player16 __asm__("$16");
                    register void* copy16 __asm__("$16");
                    register void* arg4 __asm__("$4") = Spawn89210D_80070328 + 0x30;
                    register void* arg5 __asm__("$5") = reference;
                    register void* arg6 __asm__("$6");
                    register int value2 __asm__("$2");
                    __asm__("" : "=r"(arg4), "=r"(arg5) : "0"(arg4), "1"(arg5) : "$17", "memory");
                    vector17 = &Spawn89210Stack(int, 0xD0);
                    MATCHING_KEEP3(arg4, arg5, vector17);
                    Spawn89210TransformVectorByBasis(arg4, arg5, vector17);
                    arg4 = vector17;
                    arg5 = vector17;
                    {
                        register unsigned char* table9 __asm__("$8") = Spawn89210D_80070328 + 0x30;
                        MATCHING_KEEP_CLOBBER(table9, "memory");
                        player16 = table9 - 0x30;
                    }
                    Spawn89210AddVector(arg4, arg5, player16);
                    if (Spawn89210QueryWorldSegmentWithOptions(player16, vector17, 2, 0, 0) != 0)
                        break;
                    record = Spawn89210AllocateParticleRecord(2);
                    arg4 = record + 4;
                    arg5 = vector17;
                    value2 = 1;
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 3) = value2;
                    Spawn89210PackVectorShiftRight2(arg4, arg5);
                    Spawn89210PackVectorShiftRight2(record + 24, vector17);
                    value2 = Spawn89210Field(Spawn89210D_80070328, int*, 0x8C);
                    value2 >>= 9;
                    Spawn89210Field(record, unsigned short*, 18) = value2;
                    value2 = Spawn89210Field(Spawn89210D_80070328, int*, 0x90);
                    value2 >>= 9;
                    Spawn89210Field(record, unsigned short*, 20) = value2;
                    value2 = Spawn89210rand();
                    value2 &= 3;
                    MATCHING_KEEP(value2);
                    value2 += 4;
                    commonByte9 = 46;
                    Spawn89210Field(record, volatile unsigned short*, 22) = value2;
                    value2 = 2;
                    Spawn89210Field(record, volatile unsigned char*, 11) = 0;
                    Spawn89210Field(record, volatile unsigned char*, 12) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 13) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 14) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 15) = commonByte9;
                    Spawn89210Field(record, volatile unsigned char*, 17) = value2;
                    Spawn89210Field(record, unsigned char*, 16) = 0;
                    value2 = Spawn89210rand();
                    value2 &= 7;
                    MATCHING_KEEP(value2);
                    value2 += 6;
                    Spawn89210Field(record, unsigned char*, 10) = value2;
                    value2 = Spawn89210rand();
                    Spawn89210Field(record, unsigned char*, 28) = value2;
                    value2 = Spawn89210rand();
                    value2 &= 31;
                    {
                        register int value3 __asm__("$3") = 16;
                        value3 -= value2;
                        Spawn89210Field(record, unsigned char*, 29) = value3;
                    }
                    value2 = Spawn89210rand();
                    copy16 = &Spawn89210Stack(int, 0xE0);
                    arg4 = copy16;
                    arg5 = vector17;
                    MATCHING_KEEP4_CLOBBER(copy16, arg4, arg5, value2, "memory");
                    value2 &= 31;
                    MATCHING_KEEP(value2);
                    value2 += 64;
                    Spawn89210Field(record, unsigned char*, 2) = value2;
                    Spawn89210CopyVector(arg4, arg5);
                    arg4 = vector17;
                    arg5 = copy16;
                    value2 = Spawn89210Stack(int, 0xE8);
                    value2 += 3072;
                    Spawn89210Stack(int, 0xE8) = value2;
                    value2 = Spawn89210QueryWorldSegmentWithOptions(arg4, arg5, 2, 0, 0);
                    if (value2) {
                        value2 = Spawn89210D_80071908;
                        value2 >>= 2;
                        Spawn89210Field(record, unsigned short*, 30) = value2;
                        value2 = Spawn89210D_80071934;
                        if (value2 == 0)
                            break;
                        value2 = 3;
                        Spawn89210Field(record, unsigned char*, 17) = value2;
                        break;
                    }
                    value2 = Spawn89210Stack(int, 0xE8);
                    value2 >>= 2;
                    Spawn89210Field(record, unsigned short*, 30) = value2;
                } break;
                case 0x2E:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        tailByte = 1;
                        MATCHING_KEEP3_CLOBBER(destination, source, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 127;
                        component += 64;
                        component -= random;
                        Spawn89210Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 127;
                        component += 64;
                        component -= random;
                        Spawn89210Field(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector != 0) {
                        tailByte = Spawn89210rand();
                        tailByte &= 15;
                        MATCHING_KEEP(tailByte);
                        tailByte = (int)modeSelector + tailByte;
                    } else {
                        tailByte = Spawn89210rand();
                        tailByte &= 15;
                        MATCHING_KEEP(tailByte);
                        tailByte += 20;
                    }
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn89210rand();
                    commonByte8 = 46;
                    MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                    Spawn89210Field(record, volatile unsigned char*, 11) = tailByte;
                    tailByte = 2;
                    Spawn89210Field(record, volatile unsigned char*, 12) = byte128;
                    Spawn89210Field(record, volatile unsigned char*, 13) = byte128;
                    MATCHING_BARRIER_VOLATILE("memory");
                    Spawn89210Field(record, unsigned char*, 14) = byte128;
                    goto initializeF9;
                case 0x3A:
                    record = Spawn89210AllocateParticleRecord(2);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP2_CLOBBER(destination, source, "$2");
                        tailByte = 1;
                        MATCHING_KEEP3_VOLATILE_CLOBBER(destination, source, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 2) = 0;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210PackVectorShiftRight2(record + 0x18, modeSelector);
                    tailByte = 24;
                    Spawn89210Field(record, short*, 0x1E) = 0;
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    tailByte = Spawn89210rand();
                    commonByte9 = 255;
                    commonByte8 = 46;
                    MATCHING_KEEP3_CLOBBER(commonByte9, commonByte8, tailByte, "memory");
                    Spawn89210Field(record, unsigned char*, 11) = tailByte;
                    tailByte = 4;
                    Spawn89210Field(record, unsigned char*, 12) = byte128;
                initializePrivateColor:
                    Spawn89210Field(record, unsigned char*, 13) = commonByte9;
                    Spawn89210Field(record, unsigned char*, 14) = 0;
                initializeF9:
                    Spawn89210Field(record, unsigned char*, 15) = commonByte8;
                initializeTrailingBytes:
                    __asm__ volatile("" : "=r"(tailByte) : "0"(tailByte) : "$3", "memory");
                    Spawn89210Field(record, unsigned char*, 17) = tailByte;
                    Spawn89210Field(record, unsigned char*, 16) = 0;
                    break;
                case 0x3B:
                    record = Spawn89210AllocateParticleRecord(5);
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        register int flags __asm__("$3");
                        register int value __asm__("$2");
                        __asm__(""
                                : "=r"(destination), "=r"(source)
                                : "0"(destination), "1"(source)
                                : "$3", "$2", "memory");
                        flags = Spawn89210Field(record, unsigned char*, 1);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 1;
                        MATCHING_KEEP_CLOBBER(value, "memory");
                        Spawn89210Field(record, unsigned char*, 3) = value;
                        value = 16;
                        Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                        Spawn89210Field(record, unsigned char*, 17) = value;
                        flags |= 16;
                        Spawn89210Field(record, unsigned char*, 1) = flags;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 31;
                        MATCHING_KEEP2(random, component);
                        component += 16;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Spawn89210Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 15;
                        MATCHING_KEEP2(random, component);
                        component += 8;
                        MATCHING_KEEP2(random, component);
                        component -= random;
                        Spawn89210Field(record, unsigned short*, 6) = component;
                    }
                    if (modeSelector == 0) {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E0080C0;
                    } else {
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        var_v0 = 0x2E00C000;
                    }
                    MATCHING_KEEP(var_v0);
                    Spawn89210Field(record, int*, 12) = var_v0;
                    Spawn89210Field(record, unsigned char*, 0xA) =
                        (unsigned char)((Spawn89210rand() & 0xF) + 0x14);
                    Spawn89210Field(record, unsigned char*, 0xB) = Spawn89210rand();
                    Spawn89210Field(record, unsigned char*, 0x10) = 0;
                    Spawn89210Field(record, short*, 0x18) = (short)((Spawn89210rand() & 7) - 4);
                    Spawn89210Field(record, short*, 0x1A) = (short)(-2 - (Spawn89210rand() & 7));
                    Spawn89210Field(record, short*, 0x1C) = (short)((Spawn89210rand() & 0xF) - 8);
                    break;
                case 0x42: {
                    register int local128 __asm__("$8");
                    record = Spawn89210AllocateParticleRecord(0);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn89210rand() & 0xF);
                    Spawn89210Field(record, unsigned char*, 3) = 1;
                    Spawn89210Field(record, short*, 4) =
                        (short)((((int)Spawn89210Field(reference, int*, 0) >> 2) +
                                 (Spawn89210rand() & 0xF)) -
                                8);
                    Spawn89210Field(record, short*, 6) =
                        (short)((((int)Spawn89210Field(reference, int*, 4) >> 2) +
                                 (Spawn89210rand() & 0xF)) -
                                8);
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") = Spawn89210Field(reference, int*, 8);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random &= 15;
                        Spawn89210Field(record, short*, 16) = 0;
                        Spawn89210Field(record, short*, 18) = 0;
                        Spawn89210Field(record, short*, 20) = 0;
                        MATCHING_KEEP2_CLOBBER(random, component, "memory");
                        component >>= 2;
                        component += random;
                        component -= 8;
                        Spawn89210Field(record, short*, 8) = component;
                    }
                    {
                        register int observed __asm__("$3") = Spawn89210D_8006E344;
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
                        Spawn89210Field(record, unsigned char*, 10) = var_v0_4;
                        if (modeSelector == (unsigned char*)one)
                            goto forceColor;
                        if (modeSelector != 0)
                            goto selectColor;
                        if (Spawn89210Field(Spawn89210D_80070328, int*, 0x280) < 3)
                            goto selectColor;
                    forceColor:
                        commonByte8 = 255;
                        commonByte9 = 255;
                        __asm__(""
                                : "=r"(commonByte8), "=r"(commonByte9)
                                : "0"(commonByte8), "1"(commonByte9)
                                : "$2", "memory");
                        Spawn89210Field(record, unsigned char*, 12) = commonByte8;
                        goto forcedSecondColor;
                    selectColor:;
                    }
                    temp_v1_2 = Spawn89210rand() & 7;
                    switch (temp_v1_2) {
                        case 0:
                            commonByte8 = 255;
                            MATCHING_KEEP(commonByte8);
                            Spawn89210Field(record, unsigned char*, 12) = commonByte8;
                            Spawn89210Field(record, unsigned char*, 13) = 0;
                            Spawn89210Field(record, unsigned char*, 14) = 0;
                            break;
                        case 1:
                            commonByte9 = 255;
                            commonByte8 = 255;
                            MATCHING_KEEP2(commonByte9, commonByte8);
                            Spawn89210Field(record, unsigned char*, 12) = commonByte9;
                            Spawn89210Field(record, unsigned char*, 13) = commonByte8;
                            Spawn89210Field(record, unsigned char*, 14) = 0;
                            break;
                        case 2:
                            commonByte9 = 255;
                            MATCHING_KEEP(commonByte9);
                            Spawn89210Field(record, unsigned char*, 12) = 0;
                        forcedSecondColor:
                            Spawn89210Field(record, unsigned char*, 13) = commonByte9;
                            Spawn89210Field(record, unsigned char*, 14) = 0;
                            break;
                        case 3:
                            commonByte8 = 255;
                            commonByte9 = 255;
                            MATCHING_KEEP2(commonByte8, commonByte9);
                            Spawn89210Field(record, unsigned char*, 12) = 0;
                            Spawn89210Field(record, unsigned char*, 13) = commonByte8;
                            Spawn89210Field(record, unsigned char*, 14) = commonByte9;
                            break;
                        case 4:
                            commonByte8 = 255;
                            MATCHING_KEEP(commonByte8);
                            Spawn89210Field(record, unsigned char*, 12) = 0;
                            Spawn89210Field(record, unsigned char*, 13) = 0;
                            goto thirdColor;
                        case 5:
                            commonByte9 = 255;
                            commonByte8 = 255;
                            MATCHING_KEEP2(commonByte9, commonByte8);
                            Spawn89210Field(record, unsigned char*, 12) = commonByte9;
                            Spawn89210Field(record, unsigned char*, 13) = 0;
                            goto thirdColor;
                        case 6:
                            commonByte9 = 255;
                            MATCHING_KEEP(commonByte9);
                            Spawn89210Field(record, unsigned char*, 12) = commonByte9;
                            Spawn89210Field(record, unsigned char*, 13) = byte128;
                            Spawn89210Field(record, unsigned char*, 14) = 0;
                            break;
                        case 7:
                            commonByte8 = 255;
                            MATCHING_KEEP(commonByte8);
                            Spawn89210Field(record, unsigned char*, 12) = 0;
                            Spawn89210Field(record, unsigned char*, 13) = byte128;
                        thirdColor:
                            Spawn89210Field(record, unsigned char*, 14) = commonByte8;
                            break;
                    }
                    Spawn89210Field(record, unsigned char*, 0xF) = 0x40;
                    break;
                }
                case 0x46: {
                    register int local128 __asm__("$8");
                    record = Spawn89210AllocateParticleRecord(1);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn89210rand() & 0xF);
                    Spawn89210Field(record, unsigned char*, 3) = 1;
                    Spawn89210Stack(unsigned char, 0x100) = 0;
                    Spawn89210Stack(unsigned char, 0x101) = Spawn89210rand();
                    Spawn89210Stack(unsigned char, 0x102) = Spawn89210rand();
                    Spawn89210BuildPackedAngleBasisMatrix(&Spawn89210Stack(unsigned char, 0x100),
                                                          &Spawn89210Stack(int, 0x108), 0);
                    Spawn89210Stack(int, 0xF0) = (int)modeSelector;
                    Spawn89210Stack(int, 0xF4) = 0;
                    Spawn89210Stack(int, 0xF8) = 0;
                    Spawn89210TransformVectorByBasis(&Spawn89210Stack(int, 0x108),
                                                     (unsigned char*)&Spawn89210Stack(int, 0xF0),
                                                     (unsigned char*)&Spawn89210Stack(int, 0xF0));
                    Spawn89210Field(record, unsigned short*, 4) =
                        (unsigned short)((int)Spawn89210Field(reference, int*, 0) >> 2);
                    Spawn89210Field(record, unsigned short*, 6) =
                        (unsigned short)((int)Spawn89210Field(reference, int*, 4) >> 2);
                    Spawn89210Field(record, unsigned short*, 8) =
                        (unsigned short)((int)Spawn89210Field(reference, int*, 8) >> 2);
                    {
                        register int value __asm__("$2") = Spawn89210Stack(int, 0xF0);
                        register int other __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Spawn89210Field(record, short*, 10) = other;
                        MATCHING_BARRIER("memory");
                        value = Spawn89210Stack(int, 0xF4);
                        other = Spawn89210Field(record, unsigned short*, 6);
                        value <<= 1;
                        other += value;
                        MATCHING_KEEP2(value, other);
                        Spawn89210Field(record, short*, 12) = other;
                        __asm__("" ::: "$2", "memory");
                        other = Spawn89210Stack(int, 0xF8);
                        value = 2;
                        Spawn89210Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Spawn89210Field(record, unsigned char*, 16) = value;
                        __asm__ volatile("" ::: "$9", "memory");
                        value = 192;
                        commonByte9 = 255;
                        MATCHING_KEEP2_CLOBBER(value, commonByte9, "memory");
                        Spawn89210Field(record, unsigned char*, 17) = value;
                        value = 80;
                        Spawn89210Field(record, unsigned char*, 19) = value;
                        __asm__("" : "=r"(other) : "0"(other) : "$2", "memory");
                        value = Spawn89210Field(record, unsigned short*, 8);
                        __asm__ __volatile__("" ::: "$8", "memory");
                        local128 = 255;
                        MATCHING_KEEP(local128);
                        Spawn89210Field(record, unsigned char*, 18) = 0;
                        Spawn89210Field(record, unsigned char*, 20) = commonByte9;
                        Spawn89210Field(record, unsigned char*, 21) = local128;
                        Spawn89210Field(record, unsigned char*, 22) = byte128;
                        MATCHING_KEEP2_CLOBBER(other, value, "memory");
                        other <<= 1;
                        value += other;
                        Spawn89210Field(record, short*, 14) = value;
                    }
                    break;
                }
                case 0x47:
                    record = Spawn89210AllocateParticleRecord(1);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn89210rand() & 7);
                    Spawn89210Field(record, unsigned char*, 3) = 1;
                    temp_v0_4 = (int)(((Spawn89210rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    Spawn89210Stack(int, 0x120) = temp_v0_4;
                    temp_v0_5 = (int)(((Spawn89210rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    Spawn89210Stack(int, 0x124) = temp_v0_5;
                    temp_v0_6 = (int)(((Spawn89210rand() & 0xFFF) - 0x800) * 0x10) >> 0xC;
                    Spawn89210Stack(int, 0x128) = temp_v0_6;
                    {
                        register int value __asm__("$2");
                        register int other __asm__("$3");
                        other = Spawn89210Field(reference, int*, 0);
                        value = Spawn89210Stack(int, 0x120);
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Spawn89210Field(record, unsigned short*, 4) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Spawn89210Field(reference, int*, 4);
                        value = Spawn89210Stack(int, 0x124);
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Spawn89210Field(record, unsigned short*, 6) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Spawn89210Field(reference, int*, 8);
                        value = Spawn89210Stack(int, 0x128);
                        other >>= 2;
                        value <<= 2;
                        MATCHING_KEEP2(other, value);
                        other += value;
                        Spawn89210Field(record, unsigned short*, 8) = other;
                        __asm__("" ::: "$2", "$3", "memory");
                    }
                    {
                        register int other __asm__("$3") = Spawn89210Stack(int, 0x120);
                        register int value __asm__("$2") =
                            Spawn89210Field(record, unsigned short*, 4);
                        register int finalComponent __asm__("$4");
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Spawn89210Field(record, short*, 10) = value;
                        __asm__("" ::: "$2", "$3", "memory");
                        other = Spawn89210Stack(int, 0x124);
                        value = Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(value, other);
                        value += other;
                        Spawn89210Field(record, short*, 12) = value;
                        __asm__("" ::: "$2", "$3", "$4", "memory");
                        finalComponent = Spawn89210Stack(int, 0x128);
                        __asm__ __volatile__("" ::: "$2", "memory");
                        value = 2;
                        Spawn89210Field(record, unsigned char*, 23) = value;
                        value = 224;
                        Spawn89210Field(record, volatile unsigned char*, 16) = value;
                        Spawn89210Field(record, volatile unsigned char*, 17) = value;
                        value = 96;
                        commonByte9 = 255;
                        __asm__(""
                                : "=r"(value), "=r"(commonByte9)
                                : "0"(value), "1"(commonByte9)
                                : "$3", "memory");
                        other = Spawn89210Field(record, unsigned short*, 8);
                        __asm__("" : "=r"(other) : "0"(other) : "$8", "memory");
                        commonByte8 = 255;
                        MATCHING_KEEP2_CLOBBER(other, commonByte8, "memory");
                        Spawn89210Field(record, volatile unsigned char*, 20) = commonByte9;
                        Spawn89210Field(record, volatile unsigned char*, 18) = value;
                        value = 80;
                        Spawn89210Field(record, volatile unsigned char*, 21) = commonByte8;
                        Spawn89210Field(record, volatile unsigned char*, 22) = commonByte9;
                        Spawn89210Field(record, unsigned char*, 19) = value;
                        MATCHING_KEEP2_CLOBBER(other, finalComponent, "memory");
                        other += finalComponent;
                        Spawn89210Field(record, short*, 14) = other;
                    }
                    break;
                case 0x4A:
                    record = Spawn89210AllocateParticleRecord(0);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn89210rand();
                    {
                        register void* destination __asm__("$4") = record + 4;
                        register void* source __asm__("$5") = reference;
                        MATCHING_KEEP3(destination, source, tailByte);
                        tailByte &= 15;
                        Spawn89210Field(record, unsigned char*, 2) = tailByte;
                        tailByte = 1;
                        Spawn89210Field(record, unsigned char*, 3) = tailByte;
                        Spawn89210PackVectorShiftRight2(destination, source);
                    }
                    Spawn89210PackVectorShiftRight2(record + 16, modeSelector);
                    tailByte = Spawn89210rand();
                    tailByte |= 192;
                    Spawn89210Field(record, unsigned char*, 12) = tailByte;
                    tailByte = Spawn89210rand();
                    tailByte &= 63;
                    tailByte -= 128;
                    Spawn89210Field(record, unsigned char*, 13) = tailByte;
                    tailByte = 64;
                    Spawn89210Field(record, unsigned char*, 15) = tailByte;
                    tailByte = 4;
                    Spawn89210Field(record, unsigned char*, 14) = 0;
                    Spawn89210Field(record, unsigned char*, 10) = tailByte;
                    break;
                case 0x4E:
                    record = Spawn89210AllocateParticleRecord(0);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn89210rand() & 0x1F);
                    Spawn89210Field(record, unsigned char*, 3) = 1;
                    Spawn89210PackVectorShiftRight2(record + 4, reference);
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Spawn89210Field(record, unsigned short*, 4) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Spawn89210Field(record, unsigned short*, 6) = component;
                    }
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 8);
                        MATCHING_KEEP2(random, component);
                        random &= 63;
                        MATCHING_KEEP2(random, component);
                        component -= 32;
                        MATCHING_KEEP2(random, component);
                        component += random;
                        Spawn89210Field(record, unsigned short*, 8) = component;
                    }
                    Spawn89210Field(record, short*, 0x10) = (short)((Spawn89210rand() & 2) - 1);
                    Spawn89210Field(record, short*, 0x12) = (short)((Spawn89210rand() & 2) - 1);
                    Spawn89210Field(record, short*, 0x14) = (short)-(Spawn89210rand() & 1);
                    tailByte = Spawn89210rand();
                    tailByte |= 128;
                    MATCHING_KEEP_CLOBBER(tailByte, "memory");
                    Spawn89210Field(record, unsigned char*, 12) = tailByte;
                    {
                        register int random __asm__("$2") = Spawn89210rand();
                        register int component __asm__("$3");
                        random &= 127;
                        MATCHING_KEEP(random);
                        component = Spawn89210Field(record, unsigned char*, 12);
                        MATCHING_KEEP_CLOBBER(random, "memory");
                        random += 96;
                        MATCHING_KEEP2(random, component);
                        Spawn89210Field(record, unsigned char*, 13) = random;
                        if ((unsigned int)component < (unsigned int)random)
                            Spawn89210Field(record, unsigned char*, 13) = component;
                    }
                    Spawn89210Field(record, unsigned char*, 0xE) =
                        (unsigned char)((Spawn89210rand() & 0x3F) + 0x40);
                    Spawn89210Field(record, unsigned char*, 0xF) = 0x40;
                    Spawn89210Field(record, unsigned char*, 0xA) = 2;
                    break;
                case 0x4F:
                    record = Spawn89210AllocateParticleRecord(1);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    Spawn89210Field(record, unsigned char*, 2) =
                        (unsigned char)(Spawn89210rand() & 0xF);
                    Spawn89210Field(record, unsigned char*, 3) = 1;
                    Spawn89210PackVectorShiftRight2(record + 0xA, reference);
                    {
                        register void* vector __asm__("$16");
                        MATCHING_BARRIER_VOLATILE("$16");
                        vector = (void*)&Spawn89210Stack(int, 0x120);
                        MATCHING_KEEP(vector);
                        Spawn89210AddVector(vector, reference, modeSelector);
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3");
                            component = *(volatile int*)&Spawn89210Stack(int, 0x120);
                            MATCHING_KEEP2_VOLATILE_CLOBBER(random, component, "memory");
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            Spawn89210Stack(int, 0x120) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3") = Spawn89210Stack(int, 0x124);
                            random &= 0x3F;
                            component -= 0x20;
                            component += random;
                            Spawn89210Stack(int, 0x124) = component;
                        }
                        {
                            register int random __asm__("$2") = Spawn89210rand();
                            register int component __asm__("$3");
                            register void* destination __asm__("$4") = record + 4;
                            register void* source __asm__("$5") = vector;
                            component = Spawn89210Stack(int, 0x128);
                            random &= 0x7F;
                            component -= 0x40;
                            component += random;
                            Spawn89210Stack(int, 0x128) = component;
                            Spawn89210PackVectorShiftRight2(destination, source);
                        }
                    }
                    Spawn89210Field(record, unsigned char*, 0x17) = 2;
                    tailByte = Spawn89210rand();
                    tailByte |= 192;
                    Spawn89210Field(record, unsigned char*, 16) = tailByte;
                    Spawn89210Field(record, unsigned char*, 0x11) =
                        (unsigned char)((Spawn89210rand() & 0x3F) - 0x60);
                    Spawn89210Field(record, unsigned char*, 0x12) = 0;
                    tailByte = Spawn89210rand();
                    tailByte |= 224;
                    Spawn89210Field(record, unsigned char*, 20) = tailByte;
                    tailByte = Spawn89210rand();
                    tailByte |= 224;
                    Spawn89210Field(record, unsigned char*, 21) = tailByte;
                    {
                        Spawn89210Field(record, unsigned char*, 0x16) = byte128;
                    }
                    Spawn89210Field(record, unsigned char*, 0x13) = 0x50;
                    break;
                case 0x52:
                    temp_s1 = Spawn89210Field(reference, unsigned char**, 0);
                    record = Spawn89210AllocateParticleRecord(1);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn89210rand();
                    tailByte &= 15;
                    Spawn89210Field(record, unsigned char*, 2) = tailByte;
                    tailByte = 1;
                    Spawn89210Field(record, unsigned char*, 3) = tailByte;
                    tailByte = Spawn89210rand();
                    scratch16 = tailByte & 255;
                    {
                        register int upper __asm__("$5") = Spawn89210Field(temp_s1, int*, 4);
                        tailByte = Spawn89210RandBetween(upper >> 1, upper);
                    }
                    scratch16 <<= 1;
                    {
                        register int component __asm__("$3") =
                            Spawn89210Field(Spawn89210D_80065920 + scratch16, short*, 0);
                        register int low8 __asm__("$8") = component * tailByte;
                        MATCHING_KEEP2(low8, tailByte);
                        component = low8 >> 12;
                        Spawn89210Stack(int, 0x130) = component;
                    }
                    {
                        register int component __asm__("$3") =
                            Spawn89210Field(Spawn89210D_800658A0 + scratch16, short*, 0);
                        register int low9 __asm__("$9") = component * tailByte;
                        register void* third __asm__("$6") = reference + 12;
                        register void* first __asm__("$4");
                        register void* second __asm__("$5");
                        scratch16 = (int)&Spawn89210Stack(int, 0x130);
                        first = (void*)scratch16;
                        second = first;
                        Spawn89210Stack(int, 0x138) = 0;
                        MATCHING_KEEP4(low9, third, first, second);
                        tailByte = low9 >> 12;
                        Spawn89210Stack(int, 0x134) = tailByte;
                        Spawn89210AddVector(first, second, third);
                    }
                    Spawn89210PackVectorShiftRight2(record + 4, (void*)scratch16);
                    {
                        register int value3 __asm__("$3") =
                            Spawn89210Field(record, unsigned short*, 4);
                        register int value2 __asm__("$2") =
                            Spawn89210Field(record, unsigned short*, 8);
                        register int value4 __asm__("$4") =
                            Spawn89210Field(record, unsigned short*, 6);
                        MATCHING_KEEP3(value3, value2, value4);
                        value2 += 96;
                        Spawn89210Field(record, volatile unsigned short*, 10) = value3;
                        Spawn89210Field(record, volatile unsigned short*, 12) = value4;
                        Spawn89210Field(record, volatile unsigned short*, 14) = value2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(value2, "memory");
                        value3 = Spawn89210Field(reference, int*, 20);
                        value4 = Spawn89210Field(temp_s1, int*, 0);
                        __asm__ volatile(""
                                         : "=r"(value3), "=r"(value4)
                                         : "0"(value3), "1"(value4)
                                         : "$2", "memory");
                        tailByte = 112;
                        MATCHING_KEEP3_CLOBBER(value3, value4, tailByte, "memory");
                        Spawn89210Field(record, unsigned char*, 16) = tailByte;
                        Spawn89210Field(record, unsigned char*, 17) = tailByte;
                        tailByte = 224;
                        commonByte8 = 255;
                        MATCHING_KEEP2_CLOBBER(tailByte, commonByte8, "memory");
                        Spawn89210Field(record, unsigned char*, 18) = tailByte;
                        Spawn89210Field(record, unsigned char*, 20) = tailByte;
                        Spawn89210Field(record, unsigned char*, 21) = tailByte;
                        tailByte = 80;
                        Spawn89210Field(record, unsigned char*, 22) = commonByte8;
                        Spawn89210Field(record, unsigned char*, 19) = tailByte;
                        Spawn89210Field(record, unsigned char*, 23) = 0;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(value3, value4, "memory");
                        value3 += value4;
                        value3 >>= 2;
                        Spawn89210Field(record, int*, 24) = value3;
                    }
                    break;
                case 0x54:
                    record = Spawn89210AllocateParticleRecord(0);
                    Spawn89210Field(record, unsigned char*, 0) = kindSelector;
                    tailByte = Spawn89210rand();
                    tailByte &= 15;
                    Spawn89210Field(record, unsigned char*, 2) = tailByte;
                    Spawn89210Field(record, unsigned char*, 3) = 1;
                    Spawn89210Field(record, unsigned short*, 4) =
                        Spawn89210Field(reference, int*, 0) >> 2;
                    Spawn89210Field(record, unsigned short*, 6) =
                        Spawn89210Field(reference, int*, 4) >> 2;
                    Spawn89210Field(record, unsigned short*, 8) =
                        Spawn89210Field(reference, int*, 8) >> 2;
                    tailByte = Spawn89210RandBetween(-3, 3);
                    Spawn89210Field(record, unsigned short*, 16) = tailByte;
                    tailByte = Spawn89210RandBetween(-3, 3);
                    Spawn89210Field(record, unsigned short*, 18) = tailByte;
                    tailByte = Spawn89210RandBetween(-3, 3);
                    Spawn89210Field(record, unsigned short*, 20) = tailByte;
                    Spawn89210Field(record, unsigned char*, 10) = 2;
                    Spawn89210Field(record, unsigned char*, 12) =
                        Spawn89210Field(modeSelector, unsigned char*, 0);
                    Spawn89210Field(record, unsigned char*, 13) =
                        Spawn89210Field(modeSelector, unsigned char*, 1);
                    {
                        register int color3 __asm__("$3") =
                            Spawn89210Field(modeSelector, unsigned char*, 2);
                        tailByte = 64;
                        Spawn89210Field(record, unsigned char*, 15) = tailByte;
                        Spawn89210Field(record, unsigned char*, 14) = color3;
                    }
                    break;
                storeTrailingF9:
                    Spawn89210Field(record, unsigned char*, 15) = commonByte9;
                    goto initializeTrailingBytes;
                initializeF8:
                    Spawn89210Field(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
                storeTrailingF8:
                    Spawn89210Field(record, unsigned char*, 15) = commonByte8;
                    goto initializeTrailingBytes;
            }
            MATCHING_KEEP_VOLATILE_CLOBBER(byte128, "memory");
            {
                register int stride9 __asm__("$9") = Spawn89210Stack(volatile int, 0x158);
                register int iteration8 __asm__("$8") = Spawn89210Stack(int, 0x148);
                MATCHING_KEEP2(stride9, iteration8);
                stride9 += 4;
                Spawn89210Stack(volatile int, 0x158) = stride9;
                stride9 = Spawn89210Stack(int, 0x140);
                MATCHING_KEEP2(stride9, iteration8);
                iteration8 += 1;
                var_v0 = iteration8 < stride9;
                __asm__ volatile(""
                                 : "=r"(var_v0), "=r"(iteration8)
                                 : "0"(var_v0), "1"(iteration8)
                                 : "$3", "memory");
                Spawn89210Stack(int, 0x148) = iteration8;
            }
        } while (var_v0);
    }
    return record;
}
#undef Spawn89210Field
#undef Spawn89210High
#undef Spawn89210Stack
