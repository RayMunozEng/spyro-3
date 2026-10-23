#include "matching.h"
#include "libgpu.h"
#include "common.h"
#include "stdutil.h"
#include "drawutil.h"

extern void* D_8006C664;

/**
 * ???() - func_credits_800744BC() - MATCHING
 * https://decomp.me/scratch/0F0ce
 */
void func_credits_800744BC(int arg0, char r, char g, char b) {
    struct {
        DR_MODE drMode;
        POLY_F4 f4;
    } *poly = D_8006C664;
    
    func_8005C564(&poly->drMode, 1, 0, arg0 << 5, 0);
    func_8004E71C(&poly->drMode.tag, 8);
    poly->f4.tag = 0x05000000;
    poly->f4.code = 0x28 | 2;
    poly->f4.y0 = 0xC;
    poly->f4.y1 = 0xC;
    poly->f4.x0 = 0;
    poly->f4.x1 = 0x200;
    poly->f4.x2 = 0;
    poly->f4.y2 = 0xE4;
    poly->f4.x3 = 0x200;
    poly->f4.y3 = 0xE4;
    poly->f4.r0 = r;
    poly->f4.g0 = g;
    poly->f4.b0 = b;
    func_8004E71C(&poly->f4.tag, 8);
    D_8006C664 = poly + 1;
}

/* AI-generated, not human reviewed. Original byte-offset relocation chain. */
extern int* CreditsEnvironmentNodes __asm__("D_8006D068");
extern int CreditsEnvironmentNodeCount __asm__("D_8006D06C");
extern char* CreditsEnvironmentPacked __asm__("D_8006C724");
extern int CreditsEnvironmentPackedCount __asm__("D_8006C77C");
extern int* CreditsEnvironmentOffsets __asm__("D_8006D048");
extern int CreditsEnvironmentOffsetCount __asm__("D_8006D04C");
extern char* CreditsEnvironmentFirst __asm__("D_8006D050");
extern char* CreditsEnvironmentSecond __asm__("D_8006D054");
extern int CreditsEnvironmentFirstMode __asm__("D_8006D058");
extern int CreditsEnvironmentLimit __asm__("D_8006D074");
extern char* CreditsEnvironmentData __asm__("D_8006E340");
extern unsigned char CreditsEnvironmentR __asm__("D_8006E33C"),
    CreditsEnvironmentG __asm__("D_8006E33D"), CreditsEnvironmentB __asm__("D_8006E33E");
extern int CreditsEnvironmentDataCount __asm__("D_8006E334");
extern int* CreditsEnvironmentDataOffsets __asm__("D_8006E338");
extern unsigned short CreditsEnvironmentConfig __asm__("D_8006C6A8");
void CreditsBindSoundTables(char*, int) __asm__("func_8002C9F4");
void CreditsEnvironmentSound(int, int, int) __asm__("PlaySound");
char* func_credits_8007458C(char* input) {
    char* cursor = input;
    register char* block __asm__("$17") = cursor;
    register int count __asm__("$2");
    int index;
    volatile int reservedStack[4];
    register int* nodeCount __asm__("$4");
    MATCHING_KEEP(block);
    cursor += 4;
    count = *(int*)cursor;
    cursor += 4;
    CreditsEnvironmentNodes = (int*)cursor;
    nodeCount = &CreditsEnvironmentNodeCount;
    *nodeCount = count;
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    CreditsEnvironmentPacked = cursor + 4;
    CreditsEnvironmentPackedCount = (*(int*)cursor - 4) / 28;
    cursor += *(int*)cursor;
    count = *(int*)cursor;
    cursor += 4;
    CreditsEnvironmentOffsets = (int*)cursor;
    CreditsEnvironmentOffsetCount = count;
    index = 0;
    if (count > 0) {
        nodeCount = (int*)((char*)nodeCount - 32);
        do {
            int offset = *(int*)cursor + 4;
            MATCHING_KEEP(offset);
            *(int*)cursor = (int)block + offset;
            index++;
            cursor += 4;
        } while (index < *nodeCount);
    }
    cursor = block + *(int*)block;
    block = cursor;
    MATCHING_KEEP(block);
    {
        int size = *(int*)cursor;
        int again = *(volatile int*)block;
        cursor += size;
        if (again < 9) {
            CreditsEnvironmentFirst = block;
            CreditsEnvironmentFirstMode = 0;
        } else {
            register char* next __asm__("$2") = block + 4;
            MATCHING_KEEP(next);
            CreditsEnvironmentFirst = next;
            CreditsEnvironmentFirstMode = 1;
        }
    }
    CreditsEnvironmentLimit = 180224;
    block = cursor;
    MATCHING_KEEP(block);
    {
        int size = *(int*)cursor;
        int again = *(volatile int*)block;
        cursor += size;
        if (again < 9) {
            CreditsEnvironmentSecond = block;
            *(int*)block = -1;
        } else {
            register char* next __asm__("$2") = block + 4;
            MATCHING_KEEP(next);
            CreditsEnvironmentSecond = next;
        }
    }
    {
        register char** slot __asm__("$3") = &CreditsEnvironmentData;
        register int* offsets __asm__("$4");
        register int index __asm__("$5");
        *slot = cursor + 4;
        CreditsEnvironmentR = cursor[4];
        CreditsEnvironmentG = cursor[5];
        count = (unsigned char)cursor[6];
        __asm__("" : : "r"(count) : "$4", "$5");
        offsets = (int*)(cursor + 12);
        CreditsEnvironmentB = count;
        count = *(int*)(cursor + 8);
        CreditsEnvironmentDataOffsets = offsets;
        CreditsEnvironmentDataCount = count;
        index = 0;
        if (count > 0) {
            register char** loopSlot __asm__("$6") = slot;
            do {
                *offsets = (int)*loopSlot + *offsets;
                index++;
                offsets++;
            } while (index < *(int*)((char*)loopSlot - 12));
        }
    }
    {
        int config = (short)CreditsEnvironmentConfig;
        cursor += *(int*)cursor;
        if ((short)(config % 12) == 0) {
            block = cursor;
            CreditsBindSoundTables(block + 4, 1);
            MATCHING_KEEP(block);
            {
                register int zero __asm__("$4") = 0;
                MATCHING_OBSERVE(zero);
                count = *(int*)block;
                cursor = block + count;
                CreditsEnvironmentSound(zero, 0, 4);
            }
        }
    }
    return cursor;
}


/* AI integration, not human reviewed. EXE relocation baseline. */
extern int D_8006EE2C[];
void func_credits_80074820(int* arg0, int arg1, int* arg2) {
    volatile char stackSpace[16];
    register char* base __asm__("$12") = (char*)arg0;
    register char* root __asm__("$9") = base;
    register int firstWord __asm__("$2");
    register int index __asm__("$10");
    register int fieldOffset __asm__("$7");
    register char* cursor __asm__("$3");
    register char* record __asm__("$4");
    int count;

    if ((unsigned)root >= (unsigned)arg2)
        return;
    MATCHING_KEEP(root);
    firstWord = *(volatile int*)root;
    MATCHING_KEEP(firstWord);
    index = 0;
    if (firstWord < 0) {
        register char* negativeRoot __asm__("$8");
        negativeRoot = root;
        __asm__("" : "=r"(negativeRoot) : "0"(negativeRoot), "r"(root));
        fieldOffset = 8;
        cursor = root;
        __asm__("" : "=r"(cursor) : "0"(cursor), "r"(root));
        do {
            int value = *(int*)(cursor + 8);
            if (value != 0 && (unsigned)(negativeRoot + fieldOffset) < (unsigned)arg2) {
                *(int*)(cursor + 8) = (int)base + value;
            }
            fieldOffset += 4;
            index++;
            cursor += 4;
        } while (index < 2);
        if ((unsigned)(negativeRoot + 16) < (unsigned)arg2) {
            *(int*)(negativeRoot + 16) = (int)base + *(int*)(negativeRoot + 16);
        }
        count = -*(int*)negativeRoot;
        *(int*)negativeRoot = count;
        index = 0;
        if (count > 0) {
            register char* nestedCursor __asm__("$7") = negativeRoot;
            register int nestedOffset __asm__("$11") = 20;
            do {
                if ((unsigned)(negativeRoot + nestedOffset) < (unsigned)arg2) {
                    *(int*)(nestedCursor + 20) = (int)base + *(int*)(nestedCursor + 20);
                }
                record = *(char**)(nestedCursor + 20);
                if ((unsigned)(record + 8) < (unsigned)arg2) {
                    *(unsigned short*)(record + 8) =
                        *(unsigned short*)(record + 8) + (*(int*)(negativeRoot + 16) - (int)record);
                    record = *(char**)(nestedCursor + 20);
                    *(unsigned short*)(record + 10) = *(unsigned short*)(record + 10) +
                                                      (*(int*)(negativeRoot + 16) - (int)record);
                }
                record = *(char**)(nestedCursor + 20);
                if ((unsigned)(record + 12) < (unsigned)arg2) {
                    *(unsigned short*)(record + 12) = *(unsigned short*)(record + 12) +
                                                      (*(int*)(negativeRoot + 16) - (int)record);
                    record = *(char**)(nestedCursor + 20);
                    *(unsigned short*)(record + 14) = *(unsigned short*)(record + 14) +
                                                      (*(int*)(negativeRoot + 16) - (int)record);
                }
                nestedCursor += 4;
                count = *(volatile int*)negativeRoot;
                index++;
                nestedOffset += 4;
            } while (index < count);
        }
        root = (char*)((unsigned)root & 0x7FFFFFFF);
    } else {
        index = 0;
        fieldOffset = 20;
        cursor = root;
        __asm__("" : "=r"(cursor) : "0"(cursor), "r"(root));
        do {
            int value = *(int*)(cursor + 20);
            if (value != 0 && (unsigned)(root + fieldOffset) < (unsigned)arg2) {
                *(int*)(cursor + 20) = (int)base + value;
            }
            fieldOffset += 4;
            index++;
            cursor += 4;
        } while (index < 8);
        if ((unsigned)(root + 52) < (unsigned)arg2)
            *(int*)(root + 52) = (int)base + *(int*)(root + 52);
        if ((unsigned)(root + 56) < (unsigned)arg2)
            *(int*)(root + 56) = (int)base + *(int*)(root + 56);
        index = 0;
        if (*(int*)root > 0) {
            register char* nestedCursor __asm__("$7") = root;
            register int nestedOffset __asm__("$8") = 60;
            do {
                if ((unsigned)(root + nestedOffset) < (unsigned)arg2) {
                    *(int*)(nestedCursor + 60) = (int)base + *(int*)(nestedCursor + 60);
                }
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 12) < (unsigned)arg2)
                    *(int*)(record + 12) = *(int*)(root + 56) + *(int*)(record + 12);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 16) < (unsigned)arg2)
                    *(int*)(record + 16) = *(int*)(root + 56) + *(int*)(record + 16);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 20) < (unsigned)arg2)
                    *(int*)(record + 20) = *(int*)(root + 56) + *(int*)(record + 20);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 24) < (unsigned)arg2 && *(int*)(record + 24) != 0) {
                    *(int*)(record + 24) = *(int*)(root + 56) + *(int*)(record + 24);
                }
                {
                    register char* specialRecord __asm__("$3") = *(char**)(nestedCursor + 60);
                    if ((unsigned)(specialRecord + 28) < (unsigned)arg2) {
                        register int specialValue __asm__("$4") = *(int*)(specialRecord + 28);
                        if (specialValue != 0)
                            *(int*)(specialRecord + 28) = *(int*)(root + 56) + specialValue;
                        else
                            *(int*)(specialRecord + 28) = *(int*)(specialRecord + 20);
                    }
                }
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 32) < (unsigned)arg2)
                    *(int*)(record + 32) = *(int*)(root + 56) + *(int*)(record + 32);
                nestedCursor += 4;
                count = *(volatile int*)root;
                index++;
                nestedOffset += 4;
            } while (index < count);
        }
    }
    ((int*)&D_8006EE2C)[arg1] = (int)root;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80074BA0.
 * AI generated; not human reviewed. Acceptance requires all1374 native
 * instructions,all5 selectors,every actual target and full retail hashes.
 * The original A0-byte frame saves S0..S7/FP/RA at SP78..9C.
 * RECT halfword homes SP10..16,18..1E and20..26 are completely written
 * before their consumers. Scalar homes SP18/1C/20/28/2C/30 and count
 * snapshot SP40 have original explicit producers. Reserve bytes are
 * never read. Product unions are local and their addresses never escape.
 * Original saved roles have initialized parameter-free global/scalar
 * producers. Their pointer/count/divisor phases end before reassignment.
 * The natural FP value16 is compiler allocated;FP/SP are never fixed.
 * The V0 full scalar and short symbol index have disjoint lifetimes:
 * the full literal58 predicate is consumed before the short39/40 result
 * begins;that result dies at its original halfword store,before the next
 * full scalar producer. They never overlap as live fixed aliases.
 * All6 MULT sites are distinct complete signed64 C products:five low
 * projections preserve the original variable-divisor30 arithmetic and
 * byte stores;the final ordinary high projection preserves signed/12.
 * There is no partial HI/LO input or instruction assembly.
 * Whole initialized value/address identities retain original delays,
 * byte reloads,selectors and distinct paths. Metadata consumes original
 * written fields or initialized values;dead GP clobbers precede fresh
 * producers. Metadata emits zero CPU instructions.
 * The9 table views all bind the same original D6D8D8+5B8 relocation.
 * They introduce no data or writes and claim no distinct runtime objects.
 * Original index stride8 and all original loaded offsets are retained.
 * Primary helper views cite str.h,mobyutil.h,stdutil.h and the accepted
 * original credits helpers.3636C/363DC have two formals;their original
 * complete extra physical caller values remain observed before final
 * delay stores. The diagnostic format has no conversion and only its
 * original string argument is passed. Unresolved library formal and
 * semantic contracts retain unprototyped forwarding views.
 * Compiler/filter/flags,all native/linked transfers,data relocations,
 * selector bytes and full EXE/every-overlay hashes remain mandatory.
 * Confidence after gates is binary identity. Broader caller/writer and
 * asset contracts,units/fixed-point domains,invocation cadence,Rev1
 * mapping,human review and synchronized retail captures remain open.
 * No complete credits subsystem or browser parity claim is made.
 */
/* Original assembly SHA256 6cc95ca9bb2efcae10495c19158db0b841b2b0c4d50e64fe5e4d27741b55db72 */
#define Credits_74BA0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Credits_74BA0Keep(x) __asm__ volatile("" : "=r"(x) : "0"(x))
int Credits_74BA0_CDLoadAsync(int, void*, int, int) __asm__("CDLoadAsync");
void Credits_74BA0_CDLoadSync(int, void*, int, int) __asm__("CDLoadSync");
int Credits_74BA0_DrawSync(int) __asm__("DrawSync");
int Credits_74BA0_LoadImage(void*, void*) __asm__("LoadImage");
int Credits_74BA0_MoveImage(void*, int, int) __asm__("MoveImage");
int Credits_74BA0CountTimerDown(void*, int) __asm__("func_800359A4");
int Credits_74BA0RandBetween(int, int) __asm__("func_8003636C");
int Credits_74BA0RandSignedBetween(int, int) __asm__("func_800363DC");
void Credits_74BA0CopyWordRangeUnrolled4(void*, void*, int) __asm__("func_8004E7D4");
int Credits_74BA0TriggerSignedAdditionOverflow() __asm__("func_8004F6B4");
int Credits_74BA0SyncCdCommandResult() __asm__("func_8005E074");
int Credits_74BA0WriteFormattedOutput(const char*, ...) __asm__("func_8005F5FC");
int Credits_74BA0SetSpuTransferAddress() __asm__("func_80064A2C");
int Credits_74BA0WriteSpuTransferData() __asm__("func_80064A8C");
int Credits_74BA0CheckSpuTransferCompletion() __asm__("func_80064AEC");
void* Credits_74BA0_func_credits_8007458C(void*) __asm__("func_credits_8007458C");
void Credits_74BA0_func_credits_80074820(void*, int, void*) __asm__("func_credits_80074820");
extern unsigned char Credits_74BA0_D_800658A0 __asm__("D_800658A0");
extern int Credits_74BA0_D_8006C500 __asm__("D_8006C500");
extern short Credits_74BA0_D_8006C510 __asm__("D_8006C510");
extern int Credits_74BA0_D_8006C524 __asm__("D_8006C524");
extern short Credits_74BA0_D_8006C540 __asm__("D_8006C540");
extern int Credits_74BA0_D_8006C550 __asm__("D_8006C550");
extern int Credits_74BA0_D_8006C56C __asm__("D_8006C56C");
extern int Credits_74BA0_D_8006C598 __asm__("D_8006C598");
extern short Credits_74BA0_D_8006C5A4 __asm__("D_8006C5A4");
extern int Credits_74BA0_D_8006C5E0 __asm__("D_8006C5E0");
extern int Credits_74BA0_D_8006C5E4 __asm__("D_8006C5E4");
extern int Credits_74BA0_D_8006C5F0 __asm__("D_8006C5F0");
extern int Credits_74BA0_D_8006C648 __asm__("D_8006C648");
extern short Credits_74BA0_D_8006C6A8 __asm__("D_8006C6A8");
extern int Credits_74BA0_D_8006C6AC __asm__("D_8006C6AC");
extern short Credits_74BA0_D_8006C740 __asm__("D_8006C740");
extern short Credits_74BA0_D_8006C744 __asm__("D_8006C744");
extern unsigned short Credits_74BA0_D_8006C780 __asm__("D_8006C780");
extern int Credits_74BA0_D_8006C7DC __asm__("D_8006C7DC");
extern int Credits_74BA0_D_8006C7EC __asm__("D_8006C7EC");
extern int Credits_74BA0_D_8006C7F0 __asm__("D_8006C7F0");
extern unsigned char Credits_74BA0_D_8006D8D8 __asm__("D_8006D8D8");
extern int Credits_74BA0_D_8006E020 __asm__("D_8006E020");
extern int Credits_74BA0_D_8006E024 __asm__("D_8006E024");
extern int Credits_74BA0_D_8006E028 __asm__("D_8006E028");
extern unsigned short Credits_74BA0_D_8006E03C __asm__("D_8006E03C");
extern unsigned short Credits_74BA0_D_8006E03E __asm__("D_8006E03E");
extern unsigned short Credits_74BA0_D_8006E040 __asm__("D_8006E040");
extern int Credits_74BA0_D_8006E470 __asm__("D_8006E470");
extern int Credits_74BA0_D_8006E480 __asm__("D_8006E480");
extern int Credits_74BA0_D_8006E53C __asm__("D_8006E53C");
extern int Credits_74BA0_D_8006FC6C __asm__("D_8006FC6C");
extern int Credits_74BA0_D_8006FCE0 __asm__("D_8006FCE0");
extern unsigned char Credits_74BA0_D_80070328 __asm__("D_80070328");
extern int Credits_74BA0_D_80072098 __asm__("D_80072098");
extern int Credits_74BA0_D_8007209C __asm__("D_8007209C");
extern int Credits_74BA0_D_800720A0 __asm__("D_800720A0");
extern int Credits_74BA0_D_800720A4 __asm__("D_800720A4");
extern int Credits_74BA0_D_800720A8 __asm__("D_800720A8");
extern int Credits_74BA0_D_800720AC __asm__("D_800720AC");
extern int Credits_74BA0_D_800720B0 __asm__("D_800720B0");
extern int Credits_74BA0_D_800720B4 __asm__("D_800720B4");
extern short Credits_74BA0_D_80072238 __asm__("D_80072238");
extern int Credits_74BA0_D_800722BC __asm__("D_800722BC");
extern int Credits_74BA0_D_800722C0 __asm__("D_800722C0");
extern int Credits_74BA0_D_800722C4 __asm__("D_800722C4");
extern int Credits_74BA0_D_800722C8 __asm__("D_800722C8");
extern int Credits_74BA0_D_800722D0 __asm__("D_800722D0");
extern int Credits_74BA0_D_800722D4 __asm__("D_800722D4");
extern int Credits_74BA0_D_800722D8 __asm__("D_800722D8");
extern unsigned char Credits_74BA0_D_credits_80076318 __asm__("D_credits_80076318");
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned low;
#else
        unsigned low;
        int high;
#endif
    } words;
} Credits_74BA0CompleteProduct;
extern int Credits_74BA0Index0[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index1[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index2[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index3[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index4[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index5[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index6[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index7[] __asm__("D_8006D8D8+1464");
extern int Credits_74BA0Index8[] __asm__("D_8006D8D8+1464");
void func_credits_80074BA0(void) {
    register int bufferRowOrSlotOffset16 __asm__("$16"), headerTextOrDivisor17 __asm__("$17"),
        ioRootOrSlotIndex18 __asm__("$18"), rowIndex19 __asm__("$19"), spacingMode20 __asm__("$20"),
        slotOrHalfWidth21 __asm__("$21"), rowCursor22 __asm__("$22"),
        rowByteOffset23 __asm__("$23");
    register int resultOrIntermediate2 __asm__("$2"), fieldOrIntermediate3 __asm__("$3"),
        argumentOrIntermediate4 __asm__("$4"), argumentOrIntermediate5 __asm__("$5"),
        argumentOrIntermediate6 __asm__("$6"), argumentOrIntermediate7 __asm__("$7"),
        constantOrLowCapture8 __asm__("$8"), snapshotOrHighCapture9 __asm__("$9"),
        lowCapture10 __asm__("$10"), work11 __asm__("$11");
    struct {
        short sp10, sp12, sp14, sp16;
        union {
            int word;
            struct {
                short low, high;
            } half;
        } home18, home1C, home20;
        short sp24, sp26;
        int sp28, sp2C, sp30;
        char reserve34[12];
        int sp40;
        char reserve44[32];
    } originalFrame;
    short temp_v0_8;
    short temp_v0_9;
    int temp_a0;
    int spacingIncrement;
    register short symbolIndex2 __asm__("$2");
    Credits_74BA0CompleteProduct product1, product2, product3, product4, product5, product6;
    int temp_v0_4;
    unsigned int var_v0_4;
    int temp_v0_5;
    int var_v1_3;
    if (Credits_74BA0_D_8006C510 != -1) {
        goto block_11;
    }
    Credits_74BA0Field((int)&Credits_74BA0_D_80070328, int*, 0x288) = 1;
    Credits_74BA0_DrawSync(0);
    resultOrIntermediate2 = 0x2C000;
    fieldOrIntermediate3 = Credits_74BA0_D_800722D8;
    Credits_74BA0_D_8006C7DC = resultOrIntermediate2;
    fieldOrIntermediate3 -= resultOrIntermediate2;
    resultOrIntermediate2 = fieldOrIntermediate3 - resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    Credits_74BA0Keep(fieldOrIntermediate3);
    Credits_74BA0_D_800722D0 = resultOrIntermediate2;
    Credits_74BA0_D_8006FC6C = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0_D_8006C7F0;
    MATCHING_KEEP_VOLATILE_CLOBBER(resultOrIntermediate2, "$16");
    bufferRowOrSlotOffset16 = (int)&Credits_74BA0_D_credits_80076318;
    Credits_74BA0Keep(bufferRowOrSlotOffset16);
    Credits_74BA0_D_800722D4 = fieldOrIntermediate3;
    Credits_74BA0_D_8006FCE0 = fieldOrIntermediate3;
    fieldOrIntermediate3 = 0;
    if (resultOrIntermediate2 != 0)
        goto block_5;
    Credits_74BA0Keep(resultOrIntermediate2);
    Credits_74BA0Keep(fieldOrIntermediate3);
    argumentOrIntermediate4 = 0;
    Credits_74BA0_D_8006C5F0 = bufferRowOrSlotOffset16;
    Credits_74BA0_D_8006C5A4 = 0;
loop_3:
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 += 1;
    resultOrIntermediate2 = fieldOrIntermediate3 + resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    Credits_74BA0Field(resultOrIntermediate2, signed char*, 4) = 0;
    fieldOrIntermediate3 += 0x1C;
    if (argumentOrIntermediate4 < 0x64)
        goto loop_3;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + 0xAF0;
    Credits_74BA0_D_8006C524 = resultOrIntermediate2;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + 0x2800;
    Credits_74BA0_D_8006C550 = resultOrIntermediate2;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + 0x6400;
    Credits_74BA0_D_800722C4 = resultOrIntermediate2;
    resultOrIntermediate2 = 0xB400;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    Credits_74BA0_D_8006C7F0 = resultOrIntermediate2;
    Credits_74BA0_D_800722BC = resultOrIntermediate2;
    Credits_74BA0_D_800722C0 = resultOrIntermediate2;
block_5:
    /* Initial buffer/header load phase. */
    ioRootOrSlotIndex18 = (int)&Credits_74BA0_D_8006E470;
    bufferRowOrSlotOffset16 = (int)&Credits_74BA0_D_800722C0;
    Credits_74BA0Keep(ioRootOrSlotIndex18);
    Credits_74BA0Keep(bufferRowOrSlotOffset16);
    Credits_74BA0_CDLoadSync(Credits_74BA0Field(ioRootOrSlotIndex18, int*, 0),
                             Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0), 0x800,
                             Credits_74BA0Index0[Credits_74BA0_D_8006C6A8 * 2]);
    headerTextOrDivisor17 = (int)&Credits_74BA0_D_80072098;
    Credits_74BA0Keep(headerTextOrDivisor17);
    Credits_74BA0CopyWordRangeUnrolled4(
        headerTextOrDivisor17, Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0), (void*)0x220);
    Credits_74BA0_CDLoadSync(Credits_74BA0Field(ioRootOrSlotIndex18, int*, 0),
                             Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0), 0x60000,
                             Credits_74BA0Field(headerTextOrDivisor17, int*, 0) +
                                 Credits_74BA0Index1[Credits_74BA0_D_8006C6A8 * 2]);
    argumentOrIntermediate4 = (int)&originalFrame.sp10;
    argumentOrIntermediate5 = Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0);
    Credits_74BA0Keep(argumentOrIntermediate4);
    Credits_74BA0Keep(argumentOrIntermediate5);
    resultOrIntermediate2 = 0x200;
    originalFrame.sp10 = resultOrIntermediate2;
    originalFrame.sp14 = resultOrIntermediate2;
    resultOrIntermediate2 = 0x180;
    originalFrame.sp12 = 0;
    originalFrame.sp16 = resultOrIntermediate2;
    Credits_74BA0_LoadImage(argumentOrIntermediate4, argumentOrIntermediate5);
    Credits_74BA0_CDLoadSync(Credits_74BA0Field(ioRootOrSlotIndex18, int*, 0),
                             Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0),
                             Credits_74BA0_D_8007209C + 0xFFFA0000,
                             Credits_74BA0Field(headerTextOrDivisor17, int*, 0) +
                                 Credits_74BA0Index2[Credits_74BA0_D_8006C6A8 * 2] + 0x60000);
    Credits_74BA0SetSpuTransferAddress(0x1010);
    Credits_74BA0WriteSpuTransferData(Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0),
                                      0x7EFF0);
loop_6:
    if (Credits_74BA0CheckSpuTransferCompletion(0) == 0) {
        goto loop_6;
    }
    headerTextOrDivisor17 = (int)&Credits_74BA0_D_8006E470;
    bufferRowOrSlotOffset16 = (int)&Credits_74BA0_D_800722C0;
    Credits_74BA0Keep(headerTextOrDivisor17);
    Credits_74BA0Keep(bufferRowOrSlotOffset16);
    Credits_74BA0_CDLoadSync(
        Credits_74BA0Field(headerTextOrDivisor17, int*, 0),
        Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0), Credits_74BA0_D_800720A4,
        Credits_74BA0_D_800720A0 + Credits_74BA0Index3[Credits_74BA0_D_8006C6A8 * 2]);
    resultOrIntermediate2 =
        Credits_74BA0_func_credits_8007458C(Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0));
    argumentOrIntermediate4 = Credits_74BA0Field(headerTextOrDivisor17, int*, 0);
    argumentOrIntermediate5 = Credits_74BA0_D_800722C4;
    argumentOrIntermediate6 = Credits_74BA0_D_800720AC;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C6A8;
    Credits_74BA0_D_800722C8 = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0_D_800720A8;
    Credits_74BA0_D_8006C5E0 = 0;
    argumentOrIntermediate7 = Credits_74BA0Index4[fieldOrIntermediate3 * 2];
    argumentOrIntermediate7 = resultOrIntermediate2 + argumentOrIntermediate7;
    Credits_74BA0_CDLoadSync(argumentOrIntermediate4, argumentOrIntermediate5,
                             argumentOrIntermediate6, argumentOrIntermediate7);
    Credits_74BA0_func_credits_80074820(Credits_74BA0_D_800722C4, Credits_74BA0_D_80072238,
                                        0x80800000);
    Credits_74BA0_CDLoadSync(Credits_74BA0Field(headerTextOrDivisor17, int*, 0),
                             Credits_74BA0_D_800722C8, Credits_74BA0_D_800720B4,
                             Credits_74BA0_D_800720B0 +
                                 Credits_74BA0Index5[Credits_74BA0_D_8006C6A8 * 2]);
    resultOrIntermediate2 = Credits_74BA0_D_800722C8;
    argumentOrIntermediate4 = Credits_74BA0_D_8006C524;
    fieldOrIntermediate3 = Credits_74BA0Field(resultOrIntermediate2, int*, 4);
    Credits_74BA0_D_8006C6AC = resultOrIntermediate2;
    fieldOrIntermediate3 += 4;
    resultOrIntermediate2 += fieldOrIntermediate3;
    argumentOrIntermediate5 = resultOrIntermediate2 + 0xC;
    Credits_74BA0_D_8006C7EC = resultOrIntermediate2;
    argumentOrIntermediate6 = Credits_74BA0Field(resultOrIntermediate2, int*, 0);
    fieldOrIntermediate3 = Credits_74BA0Field(resultOrIntermediate2, int*, 4);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, int*, 8);
    argumentOrIntermediate6 -= 0xC;
    Credits_74BA0_D_8006C540 = resultOrIntermediate2;
    resultOrIntermediate2 = argumentOrIntermediate4 + fieldOrIntermediate3;
    bufferRowOrSlotOffset16 = resultOrIntermediate2 - 0xC;
    Credits_74BA0CopyWordRangeUnrolled4(argumentOrIntermediate4, argumentOrIntermediate5,
                                        argumentOrIntermediate6);
    argumentOrIntermediate4 = 0;
    resultOrIntermediate2 = Credits_74BA0_D_8006C540;
    if (resultOrIntermediate2 <= 0) {
        goto block_10;
    }
    argumentOrIntermediate5 = resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C524;
    Credits_74BA0Keep(argumentOrIntermediate5);
loop_9:
    resultOrIntermediate2 = Credits_74BA0Field(fieldOrIntermediate3, int*, 0);
    argumentOrIntermediate4 += 1;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    Credits_74BA0Field(fieldOrIntermediate3, int*, 0) = resultOrIntermediate2;
    fieldOrIntermediate3 += 0xC;
    if (argumentOrIntermediate4 < argumentOrIntermediate5) {
        goto loop_9;
    }
block_10:
    Credits_74BA0_D_8006C510 = 0;
    Credits_74BA0_D_8006C6A8 = (unsigned short)Credits_74BA0_D_8006C6A8 + 1;
block_11:
    /* Camera-record cursor update. */
    if (Credits_74BA0_D_8006C6AC == 0) {
        goto block_24;
    }
    resultOrIntermediate2 = Credits_74BA0_D_8006C510;
    if (resultOrIntermediate2 < 0) {
        goto block_24;
    }
    argumentOrIntermediate6 = resultOrIntermediate2;
    Credits_74BA0Keep(argumentOrIntermediate6);
    var_v1_3 = Credits_74BA0Field(Credits_74BA0_D_8006C6AC, int*, 0) + Credits_74BA0_D_8006C648;
    temp_a0 = Credits_74BA0Field(Credits_74BA0_D_8006C6AC, int*, 8) * 2;
    Credits_74BA0Field(Credits_74BA0_D_8006C6AC, int*, 0) = var_v1_3;
    if ((int)var_v1_3 >= temp_a0) {
        goto block_23;
    }
    if ((int)var_v1_3 < 0x20) {
        goto block_16;
    }
    var_v1_3 = temp_a0 - var_v1_3;
    if ((int)var_v1_3 >= 0x20) {
        goto block_17;
    }
block_16:
    Credits_74BA0_D_8006C598 = 0x10 - ((int)var_v1_3 >> 1);
    goto block_18;
block_17:
    Credits_74BA0_D_8006C598 = 0;
block_18:
    if (Credits_74BA0_D_8006C598 < 0x10) {
        goto block_20;
    }
    Credits_74BA0_D_8006C598 = 0xF;
block_20:
    if (Credits_74BA0_D_8006C598 >= 0) {
        goto block_22;
    }
    Credits_74BA0_D_8006C598 = 0;
block_22:
    /* Original six halfword projections from the selected record. */
    argumentOrIntermediate4 = Credits_74BA0_D_8006C6AC;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, int*, 0) >> 1;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 *= 4;
    resultOrIntermediate2 = resultOrIntermediate2 + argumentOrIntermediate4;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, unsigned short*, 0x10);
    Credits_74BA0_D_8006E020 = resultOrIntermediate2 * 4;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, int*, 0) >> 1;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 *= 4;
    resultOrIntermediate2 = argumentOrIntermediate4 + resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, unsigned short*, 0x12);
    Credits_74BA0_D_8006E024 = resultOrIntermediate2 * 4;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, int*, 0) >> 1;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 *= 4;
    resultOrIntermediate2 = argumentOrIntermediate4 + resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, unsigned short*, 0x14);
    Credits_74BA0_D_8006E028 = resultOrIntermediate2 * 4;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, int*, 0) >> 1;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 *= 4;
    resultOrIntermediate2 = argumentOrIntermediate4 + resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, unsigned short*, 0x16);
    Credits_74BA0_D_8006E03C = resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, int*, 0) >> 1;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 *= 4;
    resultOrIntermediate2 = argumentOrIntermediate4 + resultOrIntermediate2;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, unsigned short*, 0x18);
    Credits_74BA0_D_8006E03E = resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, int*, 0) >> 1;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 *= 4;
    argumentOrIntermediate4 = argumentOrIntermediate4 + resultOrIntermediate2;
    Credits_74BA0Keep(argumentOrIntermediate4);
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate4, unsigned short*, 0x1A);
    Credits_74BA0_D_8006E040 = resultOrIntermediate2;
    goto block_24;
block_23:
    resultOrIntermediate2 = argumentOrIntermediate6 + 1;
    Credits_74BA0_D_8006C510 = resultOrIntermediate2;
block_24:
    if (!(Credits_74BA0_D_8006E53C & 0x810)) {
        goto block_26;
    }
    Credits_74BA0_D_8006C56C = 1;
block_26:
    if (Credits_74BA0_D_8006C56C != 0) {
        goto block_29;
    }
    if (Credits_74BA0_D_8006C5A4 != 0) {
        goto block_34;
    }
    if (Credits_74BA0_D_8006C744 < Credits_74BA0_D_8006C540) {
        goto block_33;
    }
block_29:
    fieldOrIntermediate3 = Credits_74BA0_D_8006C648;
    resultOrIntermediate2 = Credits_74BA0_D_8006C780;
    temp_v0_4 = resultOrIntermediate2 + fieldOrIntermediate3;
    Credits_74BA0_D_8006C780 = temp_v0_4;
    Credits_74BA0_D_8006C598 = (int)(short)temp_v0_4;
    if ((short)temp_v0_4 < 0x10) {
        goto block_31;
    }
    Credits_74BA0_D_8006C598 = 0xF;
block_31:
    if (Credits_74BA0_D_8006C598 != 0xF) {
        goto block_33;
    }
    Credits_74BA0_D_8006C510 = 0x63;
block_33:
block_34:
    if (Credits_74BA0_D_8006C5A4 > 0) {
        goto block_37;
    }
    if (Credits_74BA0_D_8006C540 <= 0) {
        goto block_137;
    }
    if (Credits_74BA0_D_8006C744 >= Credits_74BA0_D_8006C540) {
        goto block_137;
    }
block_37:
    /* Process row records and their byte strings. */
    rowCursor22 = Credits_74BA0_D_8006C744;
    Credits_74BA0Keep(rowCursor22);
    spacingMode20 = 1;
    snapshotOrHighCapture9 = (int)Credits_74BA0_D_8006C740;
    resultOrIntermediate2 = snapshotOrHighCapture9 < rowCursor22;
    Credits_74BA0Keep(resultOrIntermediate2);
    originalFrame.sp40 = snapshotOrHighCapture9;
    if (resultOrIntermediate2) {
        goto block_100;
    }
    resultOrIntermediate2 = rowCursor22 * 3;
    Credits_74BA0Keep(resultOrIntermediate2);
    rowByteOffset23 = resultOrIntermediate2 * 4;
loop_39:
    rowIndex19 = -1;
    if (Credits_74BA0CountTimerDown(Credits_74BA0_D_8006C524 + rowByteOffset23 + 6, 2) == 0) {
        goto block_43;
    }
    temp_v0_5 = rowByteOffset23 + Credits_74BA0_D_8006C524;
    resultOrIntermediate2 = temp_v0_5;
    fieldOrIntermediate3 = 2;
    Credits_74BA0Keep(resultOrIntermediate2);
    Credits_74BA0Keep(fieldOrIntermediate3);
    Credits_74BA0Field(resultOrIntermediate2, short*, 0xA) = fieldOrIntermediate3;
    if (Credits_74BA0Field(resultOrIntermediate2, short*, 8) != 0) {
        goto block_43;
    }
    if (rowCursor22 != Credits_74BA0_D_8006C744) {
        goto block_43;
    }
    Credits_74BA0_D_8006C744 += 1;
block_43:
    if (Credits_74BA0Field(Credits_74BA0_D_8006C524, short*, 0xA) != 0) {
        goto block_45;
    }
    rowIndex19 = 0;
    goto block_49;
block_45:
    if (Credits_74BA0CountTimerDown(Credits_74BA0_D_8006C524 + rowByteOffset23 + 8, 2) == 0) {
        goto block_50;
    }
    if (Credits_74BA0Field((rowByteOffset23 + Credits_74BA0_D_8006C524), short*, 0x16) != 0) {
        goto block_50;
    }
    if (rowCursor22 >= (Credits_74BA0_D_8006C540 - 1)) {
        goto block_50;
    }
    rowIndex19 = rowCursor22 + 1;
block_49:
block_50:
    if (rowIndex19 == -1) {
        goto block_99;
    }
    resultOrIntermediate2 = rowIndex19 * 2;
    slotOrHalfWidth21 = 0;
    resultOrIntermediate2 += rowIndex19;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C524;
    resultOrIntermediate2 *= 4;
    argumentOrIntermediate5 = resultOrIntermediate2 + fieldOrIntermediate3;
    Credits_74BA0Keep(argumentOrIntermediate5);
    Credits_74BA0Field(argumentOrIntermediate5, short*, 0xA) = 1;
    resultOrIntermediate2 = Credits_74BA0_D_8006C740;
    resultOrIntermediate2 = resultOrIntermediate2 < rowIndex19;
    spacingIncrement = 16;
    if (!resultOrIntermediate2) {
        goto block_53;
    }
    Credits_74BA0_D_8006C740 = rowIndex19;
block_53:
    if (Credits_74BA0_D_8006C540 >= Credits_74BA0_D_8006C740) {
        goto block_55;
    }
    Credits_74BA0_D_8006C740 = Credits_74BA0_D_8006C540;
block_55:
    /* Initialize every scalar frame home used by the byte parser. */
    originalFrame.home18.word = 0x100;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate5, short*, 4);
    originalFrame.home20.word = 0xDAC;
    originalFrame.sp28 = 0xE;
    originalFrame.sp2C = 1;
    originalFrame.sp30 = 0x1194;
    originalFrame.home1C.word = fieldOrIntermediate3;
    headerTextOrDivisor17 = Credits_74BA0Field(argumentOrIntermediate5, unsigned char**, 0);
    fieldOrIntermediate3 = Credits_74BA0Field(headerTextOrDivisor17, unsigned char*, 0);
    Credits_74BA0Keep(fieldOrIntermediate3);
    if (fieldOrIntermediate3 == 0) {
        goto block_94;
    }
loop_56:
    ioRootOrSlotIndex18 = slotOrHalfWidth21;
    if ((fieldOrIntermediate3 & 0xFF) == 0x20) {
        goto block_90;
    }
    Credits_74BA0Keep(ioRootOrSlotIndex18);
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5A4;
    resultOrIntermediate2 = ioRootOrSlotIndex18 < fieldOrIntermediate3;
    Credits_74BA0Keep(resultOrIntermediate2);
    argumentOrIntermediate5 = fieldOrIntermediate3;
    if (!resultOrIntermediate2) {
        goto block_63;
    }
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5F0;
    resultOrIntermediate2 = ioRootOrSlotIndex18 * 28;
    argumentOrIntermediate4 = resultOrIntermediate2 + fieldOrIntermediate3;
loop_59:
    if (Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 4) == 0) {
        goto block_61;
    }
    ioRootOrSlotIndex18 += 1;
    argumentOrIntermediate4 += 0x1C;
    if (ioRootOrSlotIndex18 < argumentOrIntermediate5) {
        goto loop_59;
    }
block_61:
    if (ioRootOrSlotIndex18 >= Credits_74BA0_D_8006C5A4) {
        goto block_63;
    }
    slotOrHalfWidth21 = ioRootOrSlotIndex18;
    resultOrIntermediate2 = (ioRootOrSlotIndex18 * 8) - slotOrHalfWidth21;
    resultOrIntermediate2 *= 4;
    goto block_64;
block_63:
    argumentOrIntermediate4 =
        Credits_74BA0Field((int)&Credits_74BA0_D_8006C5A4, unsigned short*, 0);
    Credits_74BA0Keep(argumentOrIntermediate4);
    fieldOrIntermediate3 = (int)((unsigned)argumentOrIntermediate4 << 16);
    Credits_74BA0Keep(fieldOrIntermediate3);
    fieldOrIntermediate3 >>= 16;
    resultOrIntermediate2 = (fieldOrIntermediate3 * 7) * 4;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 += 1;
    Credits_74BA0_D_8006C5A4 = argumentOrIntermediate4;
block_64:
    bufferRowOrSlotOffset16 = fieldOrIntermediate3 + resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(headerTextOrDivisor17, unsigned char*, 0);
    Credits_74BA0Keep(fieldOrIntermediate3);
    if ((unsigned int)(fieldOrIntermediate3 - 0x41) >= 0x1AU) {
        goto block_66;
    }
    spacingMode20 = 1;
block_66:
    resultOrIntermediate2 = fieldOrIntermediate3 - 0x61;
    Credits_74BA0Keep(resultOrIntermediate2);
    if ((unsigned int)resultOrIntermediate2 >= 0x1AU) {
        goto block_68;
    }
    spacingMode20 = 0;
block_68:
    Credits_74BA0Field(bufferRowOrSlotOffset16, signed char*, 4) = 1;
    resultOrIntermediate2 = Credits_74BA0_D_8006C5A4;
    resultOrIntermediate2 = resultOrIntermediate2 < 0x65;
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x18) = rowIndex19;
    if (resultOrIntermediate2) {
        goto block_70;
    }
    Credits_74BA0WriteFormattedOutput("Too many moby tags.\n");
    Credits_74BA0TriggerSignedAdditionOverflow();
block_70:
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x12) = (short)originalFrame.home18.word;
    Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14) =
        (unsigned short)originalFrame.home1C.word;
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x16) = (short)originalFrame.home20.word;
    if (spacingMode20 != 0) {
        goto block_72;
    }
    Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14) =
        (unsigned short)(Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14) +
                         originalFrame.sp2C);
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x16) = (short)originalFrame.sp30;
block_72:
    /* Byte-range and punctuation index mapping. */
    fieldOrIntermediate3 = Credits_74BA0Field(headerTextOrDivisor17, unsigned char*, 0);
    Credits_74BA0Keep(fieldOrIntermediate3);
    if ((unsigned)(fieldOrIntermediate3 - 0x30) < 10) {
        symbolIndex2 = fieldOrIntermediate3 - 0x16;
        goto block_85;
    }
    if ((unsigned)(fieldOrIntermediate3 - 0x41) < 26) {
        symbolIndex2 = (short)(fieldOrIntermediate3 - 0x41);
        goto block_85;
    }
    if ((unsigned)(fieldOrIntermediate3 - 0x61) < 26) {
        symbolIndex2 = (short)(fieldOrIntermediate3 - 0x61);
        goto block_85;
    }
    fieldOrIntermediate3 = fieldOrIntermediate3 & 0xFF;
    if (fieldOrIntermediate3 != 0x21) {
        goto block_77;
    }
    symbolIndex2 = 0x24;
    goto block_85;
block_77:
    if (fieldOrIntermediate3 != 0x2C) {
        goto block_79;
    }
    fieldOrIntermediate3 = Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14);
    symbolIndex2 = 0x25;
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x1A) = symbolIndex2;
    fieldOrIntermediate3 += 5;
    Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14) = fieldOrIntermediate3;
    goto block_86;
block_79:
    if (fieldOrIntermediate3 != 0x2E) {
        goto block_81;
    }
    fieldOrIntermediate3 = Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14);
    symbolIndex2 = 0x26;
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x1A) = symbolIndex2;
    fieldOrIntermediate3 += 3;
    Credits_74BA0Field(bufferRowOrSlotOffset16, unsigned short*, 0x14) = fieldOrIntermediate3;
    goto block_86;
block_81:
    if (fieldOrIntermediate3 == 0x2D) {
        goto block_84;
    }
    resultOrIntermediate2 = 0x3A;
    Credits_74BA0Keep(resultOrIntermediate2);
    if (fieldOrIntermediate3 == resultOrIntermediate2) {
        symbolIndex2 = 0x28;
        goto block_85;
    }
    symbolIndex2 = 0x27;
    goto block_85;
block_84:
    symbolIndex2 = 0x27;
    Credits_74BA0Keep(symbolIndex2);
block_85:
    Credits_74BA0Field(bufferRowOrSlotOffset16, short*, 0x1A) = symbolIndex2;
block_86:
    Credits_74BA0Keep(spacingIncrement);
    if (spacingMode20 == 0) {
        goto block_88;
    }
    resultOrIntermediate2 = originalFrame.home18.word + spacingIncrement;
    goto block_89;
block_88:
    resultOrIntermediate2 = originalFrame.home18.word;
    fieldOrIntermediate3 = originalFrame.sp28;
    resultOrIntermediate2 += fieldOrIntermediate3;
block_89:
    originalFrame.home18.word = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(headerTextOrDivisor17, unsigned char*, 0);
    resultOrIntermediate2 -= 0x30;
    spacingMode20 = (unsigned)resultOrIntermediate2 < 10;
    goto block_93;
block_90:
    fieldOrIntermediate3 = originalFrame.sp28 * 3;
    spacingMode20 = 1;
    if (fieldOrIntermediate3 >= 0) {
        goto block_92;
    }
    fieldOrIntermediate3 += 3;
block_92:
    resultOrIntermediate2 = originalFrame.home18.word + (fieldOrIntermediate3 >> 2);
    originalFrame.home18.word = resultOrIntermediate2;
block_93:
    headerTextOrDivisor17 += 1;
    fieldOrIntermediate3 = Credits_74BA0Field(headerTextOrDivisor17, unsigned char*, 0);
    Credits_74BA0Keep(fieldOrIntermediate3);
    if (fieldOrIntermediate3 != 0) {
        goto loop_56;
    }
block_94:
    /* Derive the signed half-width and initialize the original divisor30. */
    resultOrIntermediate2 = originalFrame.home18.word;
    ioRootOrSlotIndex18 = 0;
    resultOrIntermediate2 -= 0x100;
    slotOrHalfWidth21 = resultOrIntermediate2 >> 1;
    Credits_74BA0Keep(slotOrHalfWidth21);
    headerTextOrDivisor17 = 30;
    if (Credits_74BA0_D_8006C5A4 <= 0) {
        goto block_99;
    }
    bufferRowOrSlotOffset16 = 0;
loop_96:
    /* Initialize slot motion from complete quotient/product values. */
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate7 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    if (Credits_74BA0Field(argumentOrIntermediate7, short*, 0x18) != rowIndex19)
        goto block_98;
    argumentOrIntermediate5 = 15;
    argumentOrIntermediate6 =
        Credits_74BA0Field(argumentOrIntermediate7, unsigned short*, 0x12) - slotOrHalfWidth21;
    resultOrIntermediate2 = (short)argumentOrIntermediate6;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 -= 0x100;
    fieldOrIntermediate3 = -((resultOrIntermediate2 * 2) + resultOrIntermediate2);
    Credits_74BA0Keep(fieldOrIntermediate3);
    Credits_74BA0Keep(headerTextOrDivisor17);
    fieldOrIntermediate3 = fieldOrIntermediate3 / headerTextOrDivisor17;
    Credits_74BA0Keep(fieldOrIntermediate3);
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate7, short*, 0x16);
    resultOrIntermediate2 = -(resultOrIntermediate2 * 2);
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = resultOrIntermediate2 / headerTextOrDivisor17;
    Credits_74BA0Keep(resultOrIntermediate2);
    product1.full = (long long)(int)fieldOrIntermediate3 * (long long)(int)headerTextOrDivisor17;
    __asm__("" : "=x"(product1.full) : "0"(product1.full));
    lowCapture10 = (int)product1.words.low;
    Credits_74BA0Keep(lowCapture10);
    product2.full = (long long)(int)resultOrIntermediate2 * (long long)(int)headerTextOrDivisor17;
    __asm__("" : "=x"(product2.full) : "0"(product2.full));
    Credits_74BA0Field(argumentOrIntermediate7, unsigned short*, 0x12) = argumentOrIntermediate6;
    __asm__ volatile("" ::"m"(Credits_74BA0Field(argumentOrIntermediate7, unsigned short*, 0x12)));
    argumentOrIntermediate4 = 4;
    Credits_74BA0Field(argumentOrIntermediate7, short*, 0xC) = fieldOrIntermediate3;
    Credits_74BA0Field(argumentOrIntermediate7, short*, 0x10) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate7, unsigned short*, 0x16);
    __asm__("" ::"m"(Credits_74BA0Field(argumentOrIntermediate7, short*, 0xC)),
            "m"(Credits_74BA0Field(argumentOrIntermediate7, short*, 0x10)));
    argumentOrIntermediate6 -= lowCapture10;
    Credits_74BA0Field(argumentOrIntermediate7, unsigned short*, 0x12) = argumentOrIntermediate6;
    constantOrLowCapture8 = (int)product2.words.low;
    Credits_74BA0Keep(constantOrLowCapture8);
    resultOrIntermediate2 -= constantOrLowCapture8;
    MATCHING_OBSERVE2_VOLATILE(argumentOrIntermediate6, argumentOrIntermediate7);
    Credits_74BA0Field(argumentOrIntermediate7, short*, 0x16) = resultOrIntermediate2;
    resultOrIntermediate2 =
        Credits_74BA0RandSignedBetween(argumentOrIntermediate4, argumentOrIntermediate5);
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 8) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0RandSignedBetween(4, 15);
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 9) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0RandSignedBetween(4, 15);
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 0xA) = resultOrIntermediate2;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Keep(fieldOrIntermediate3);
    resultOrIntermediate2 = -(int)Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 8);
    Credits_74BA0Keep(resultOrIntermediate2);
    product3.full = (long long)(int)resultOrIntermediate2 * (long long)(int)headerTextOrDivisor17;
    __asm__("" : "=x"(product3.full) : "0"(product3.full));
    constantOrLowCapture8 = (int)product3.words.low;
    Credits_74BA0Keep(constantOrLowCapture8);
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 5) = constantOrLowCapture8;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Keep(fieldOrIntermediate3);
    resultOrIntermediate2 = -(int)Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 9);
    Credits_74BA0Keep(resultOrIntermediate2);
    product4.full = (long long)(int)resultOrIntermediate2 * (long long)(int)headerTextOrDivisor17;
    __asm__("" : "=x"(product4.full) : "0"(product4.full));
    constantOrLowCapture8 = (int)product4.words.low;
    Credits_74BA0Keep(constantOrLowCapture8);
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 6) = constantOrLowCapture8;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Keep(fieldOrIntermediate3);
    resultOrIntermediate2 = -(int)Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 0xA);
    Credits_74BA0Keep(resultOrIntermediate2);
    product5.full = (long long)(int)resultOrIntermediate2 * (long long)(int)headerTextOrDivisor17;
    __asm__("" : "=x"(product5.full) : "0"(product5.full));
    constantOrLowCapture8 = (int)product5.words.low;
    Credits_74BA0Keep(constantOrLowCapture8);
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 7) = constantOrLowCapture8;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Keep(resultOrIntermediate2);
    Credits_74BA0Field(resultOrIntermediate2, signed char*, 0xB) = headerTextOrDivisor17;
block_98:
    resultOrIntermediate2 = Credits_74BA0_D_8006C5A4;
    __asm__("" : "=r"(ioRootOrSlotIndex18) : "0"(ioRootOrSlotIndex18), "r"(resultOrIntermediate2));
    ioRootOrSlotIndex18 += 1;
    bufferRowOrSlotOffset16 += 0x1C;
    if (ioRootOrSlotIndex18 < resultOrIntermediate2) {
        goto loop_96;
    }
block_99:
    snapshotOrHighCapture9 = originalFrame.sp40;
    __asm__("" : "=r"(rowCursor22) : "0"(rowCursor22), "r"(snapshotOrHighCapture9));
    rowCursor22 += 1;
    resultOrIntermediate2 = snapshotOrHighCapture9 < rowCursor22;
    Credits_74BA0Keep(resultOrIntermediate2);
    rowByteOffset23 += 0xC;
    if (!resultOrIntermediate2) {
        goto loop_39;
    }
block_100:
    /* Apply row completion state transitions. */
    ioRootOrSlotIndex18 = 0;
    resultOrIntermediate2 = Credits_74BA0_D_8006C5A4;
    if (resultOrIntermediate2 <= 0) {
        goto block_109CurrentCount;
    }
    constantOrLowCapture8 = 2;
    argumentOrIntermediate7 = 3;
    argumentOrIntermediate6 = 4;
    argumentOrIntermediate5 = 0;
    Credits_74BA0Keep(constantOrLowCapture8);
    Credits_74BA0Keep(argumentOrIntermediate7);
    Credits_74BA0Keep(argumentOrIntermediate6);
loop_102:
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 = argumentOrIntermediate5 + resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, short*, 0x18);
    Credits_74BA0Keep(fieldOrIntermediate3);
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C524;
    resultOrIntermediate2 *= 4;
    resultOrIntermediate2 += fieldOrIntermediate3;
    fieldOrIntermediate3 = Credits_74BA0Field(resultOrIntermediate2, short*, 0xA);
    if (fieldOrIntermediate3 != constantOrLowCapture8) {
        goto block_107;
    }
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 4);
    if (resultOrIntermediate2 != fieldOrIntermediate3) {
        goto block_105;
    }
    Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 4) = argumentOrIntermediate7;
    goto block_107;
block_105:
    if (resultOrIntermediate2 != argumentOrIntermediate6) {
        goto block_107;
    }
    Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 4) = 0U;
block_107:
    resultOrIntermediate2 = Credits_74BA0_D_8006C5A4;
    ioRootOrSlotIndex18 += 1;
    argumentOrIntermediate5 += 0x1C;
    if (ioRootOrSlotIndex18 < resultOrIntermediate2) {
        goto loop_102;
    }
block_109:
    /* Load a fresh count after the first loop. */
    MATCHING_BARRIER_VOLATILE("memory");
    resultOrIntermediate2 = Credits_74BA0_D_8006C5A4;
block_109CurrentCount:
    /* The earlier nonpositive-count path arrives with its initialized count. */
    Credits_74BA0Keep(resultOrIntermediate2);
    ioRootOrSlotIndex18 = 0;
    if (resultOrIntermediate2 <= 0) {
        goto block_132;
    }
    bufferRowOrSlotOffset16 = 0;
loop_111:
    /* Update the selected slot state. */
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate6 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 4);
    if (fieldOrIntermediate3 == 2) {
        goto block_122;
    }
    if ((int)fieldOrIntermediate3 >= 3) {
        goto block_115;
    }
    if (fieldOrIntermediate3 == 1) {
        goto block_117;
    }
    goto block_131;
block_115:
    if (fieldOrIntermediate3 == 3) {
        goto block_127;
    }
    goto block_131;
block_117:
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x12);
    argumentOrIntermediate4 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0xC);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 5);
    argumentOrIntermediate5 = Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 8);
    resultOrIntermediate2 += argumentOrIntermediate4;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x12) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x16);
    fieldOrIntermediate3 += argumentOrIntermediate5;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 5) = fieldOrIntermediate3;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x10);
    argumentOrIntermediate4 = Credits_74BA0_D_8006C5F0;
    resultOrIntermediate2 += fieldOrIntermediate3;
    argumentOrIntermediate4 = bufferRowOrSlotOffset16 + argumentOrIntermediate4;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x16) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 6);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 9);
    resultOrIntermediate2 += fieldOrIntermediate3;
    Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 6) = resultOrIntermediate2;
    argumentOrIntermediate4 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 = bufferRowOrSlotOffset16 + argumentOrIntermediate4;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 7);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 0xA);
    resultOrIntermediate2 += fieldOrIntermediate3;
    Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 7) = resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5F0;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + fieldOrIntermediate3;
    resultOrIntermediate2 = Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 0xB) - 1;
    Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 0xB) = resultOrIntermediate2;
    resultOrIntermediate2 &= 255;
    fieldOrIntermediate3 = 2;
    if (resultOrIntermediate2)
        goto block_131;
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    resultOrIntermediate2 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    Credits_74BA0Field(resultOrIntermediate2, unsigned char*, 4) = fieldOrIntermediate3;
    argumentOrIntermediate4 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 = bufferRowOrSlotOffset16 + argumentOrIntermediate4;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, short*, 0x12);
    MATCHING_KEEP_CLOBBER(fieldOrIntermediate3, "$6");
    argumentOrIntermediate6 = argumentOrIntermediate4;
    fieldOrIntermediate3 -= 0x100;
    resultOrIntermediate2 = fieldOrIntermediate3 * 3;
    resultOrIntermediate2 = resultOrIntermediate2 * 8 + fieldOrIntermediate3;
    resultOrIntermediate2 >>= 8;
    __asm__(""
            : "=r"(argumentOrIntermediate4)
            : "0"(argumentOrIntermediate4), "r"(argumentOrIntermediate6));
    Credits_74BA0Field(argumentOrIntermediate4, short*, 0xC) = resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate6, short*, 0x12);
    resultOrIntermediate2 = 0x100;
    argumentOrIntermediate4 = resultOrIntermediate2 - fieldOrIntermediate3;
    Credits_74BA0Keep(argumentOrIntermediate4);
    if (argumentOrIntermediate4 < 0)
        goto block_120;
    resultOrIntermediate2 = argumentOrIntermediate4 * 15;
    goto block_121;
block_120:
    fieldOrIntermediate3 -= 0x100;
    resultOrIntermediate2 = fieldOrIntermediate3 * 15;
block_121:
    resultOrIntermediate2 = (unsigned)resultOrIntermediate2 >> 6;
    MATCHING_OBSERVE_VOLATILE(argumentOrIntermediate6);
    Credits_74BA0Field(argumentOrIntermediate6, short*, 0x10) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0RandBetween(0x60, 0xC0);
    argumentOrIntermediate4 = 4;
    argumentOrIntermediate5 = 9;
    Credits_74BA0Keep(argumentOrIntermediate5);
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5F0;
    resultOrIntermediate2 = -resultOrIntermediate2;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + fieldOrIntermediate3;
    Credits_74BA0Field(fieldOrIntermediate3, short*, 0xE) = resultOrIntermediate2;
    resultOrIntermediate2 =
        Credits_74BA0RandSignedBetween(argumentOrIntermediate4, argumentOrIntermediate5);
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 8) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0RandSignedBetween(4, 9);
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 9) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0RandSignedBetween(4, 9);
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + Credits_74BA0_D_8006C5F0;
    Credits_74BA0Field(fieldOrIntermediate3, signed char*, 0xA) = resultOrIntermediate2;
    goto block_131;
block_122:
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 0xB) + 1;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 0xB) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    if (Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 0xB) >= 0x40)
        Credits_74BA0Field(fieldOrIntermediate3, unsigned char*, 0xB) = 0;
block_124:
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 0xB);
    Credits_74BA0Keep(fieldOrIntermediate3);
    if (fieldOrIntermediate3 < 32) {
        resultOrIntermediate2 = fieldOrIntermediate3 * 2;
        goto block_126;
    }
    resultOrIntermediate2 = 64;
    fieldOrIntermediate3 = resultOrIntermediate2 - fieldOrIntermediate3;
    Credits_74BA0Keep(fieldOrIntermediate3);
    resultOrIntermediate2 = fieldOrIntermediate3 * 2;
block_126:
    resultOrIntermediate2 =
        Credits_74BA0Field((int)&Credits_74BA0_D_800658A0, unsigned short*, resultOrIntermediate2);
    resultOrIntermediate2 = ((int)((unsigned)resultOrIntermediate2 << 16)) >> 22;
    resultOrIntermediate2 -= 32;
    Credits_74BA0Field(argumentOrIntermediate4, signed char*, 7) = resultOrIntermediate2;
    goto block_131;
block_127:
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x12);
    argumentOrIntermediate4 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0xC);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0xE);
    argumentOrIntermediate5 = Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 8);
    resultOrIntermediate2 += argumentOrIntermediate4;
    fieldOrIntermediate3 = (int)((unsigned)fieldOrIntermediate3 << 16) >> 20;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x12) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x14);
    argumentOrIntermediate4 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x10);
    resultOrIntermediate2 += fieldOrIntermediate3;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x14) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x16);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 5);
    resultOrIntermediate2 += argumentOrIntermediate4;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0x16) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0xE);
    fieldOrIntermediate3 += argumentOrIntermediate5;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned char*, 5) = fieldOrIntermediate3;
    argumentOrIntermediate4 = Credits_74BA0_D_8006C5F0;
    resultOrIntermediate2 += 14;
    argumentOrIntermediate4 = bufferRowOrSlotOffset16 + argumentOrIntermediate4;
    Credits_74BA0Field(argumentOrIntermediate6, unsigned short*, 0xE) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 6);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 9);
    resultOrIntermediate2 += fieldOrIntermediate3;
    Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 6) = resultOrIntermediate2;
    argumentOrIntermediate4 = Credits_74BA0_D_8006C5F0;
    argumentOrIntermediate4 = bufferRowOrSlotOffset16 + argumentOrIntermediate4;
    resultOrIntermediate2 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 7);
    fieldOrIntermediate3 = Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 0xA);
    resultOrIntermediate2 += fieldOrIntermediate3;
    Credits_74BA0Field(argumentOrIntermediate4, unsigned char*, 7) = resultOrIntermediate2;
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    if (Credits_74BA0Field(fieldOrIntermediate3, short*, 0xE) >= 0x141)
        Credits_74BA0Field(fieldOrIntermediate3, short*, 0xE) = 0x140;
block_129:
    resultOrIntermediate2 = Credits_74BA0_D_8006C5F0;
    fieldOrIntermediate3 = bufferRowOrSlotOffset16 + resultOrIntermediate2;
    if (Credits_74BA0Field(fieldOrIntermediate3, short*, 0x14) >= 0x119)
        Credits_74BA0Field(fieldOrIntermediate3, signed char*, 4) = 4;
block_131:
    MATCHING_BARRIER_VOLATILE("memory");
    resultOrIntermediate2 = Credits_74BA0_D_8006C5A4;
    ioRootOrSlotIndex18 += 1;
    bufferRowOrSlotOffset16 += 0x1C;
    if (ioRootOrSlotIndex18 < resultOrIntermediate2) {
        goto loop_111;
    }
block_132:
    /* Retire trailing inactive slots using the original signed16 count. */
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5A4;
    Credits_74BA0Keep(fieldOrIntermediate3);
    if (fieldOrIntermediate3 <= 0)
        goto block_137;
    resultOrIntermediate2 = (fieldOrIntermediate3 * 7) * 4;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C5F0;
    resultOrIntermediate2 += fieldOrIntermediate3;
    if (Credits_74BA0Field(resultOrIntermediate2, unsigned char*, -0x18))
        goto block_137;
    argumentOrIntermediate4 = fieldOrIntermediate3;
loop_135:
    resultOrIntermediate2 =
        Credits_74BA0Field((int)&Credits_74BA0_D_8006C5A4, unsigned short*, 0) - 1;
    Credits_74BA0_D_8006C5A4 = resultOrIntermediate2;
    resultOrIntermediate2 = (int)((unsigned)resultOrIntermediate2 << 16);
    Credits_74BA0Keep(resultOrIntermediate2);
    fieldOrIntermediate3 = resultOrIntermediate2 >> 16;
    Credits_74BA0Keep(fieldOrIntermediate3);
    if (fieldOrIntermediate3 <= 0)
        goto block_137;
    resultOrIntermediate2 = (fieldOrIntermediate3 * 7) * 4;
    resultOrIntermediate2 += argumentOrIntermediate4;
    if (!Credits_74BA0Field(resultOrIntermediate2, unsigned char*, -0x18))
        goto loop_135;
block_137:
    /* Original external-operation and five-way loader dispatch gates. */
    fieldOrIntermediate3 = Credits_74BA0_D_8006C510;
    resultOrIntermediate2 = -1;
    if (fieldOrIntermediate3 == resultOrIntermediate2)
        goto block_155;
    if (fieldOrIntermediate3 <= 0)
        goto block_142;
    resultOrIntermediate2 = (int)&Credits_74BA0_D_8006E480;
    Credits_74BA0Keep(resultOrIntermediate2);
    resultOrIntermediate2 = Credits_74BA0Field(resultOrIntermediate2, int*, 0);
    if (resultOrIntermediate2 != 0)
        goto block_155;
    argumentOrIntermediate4 = 1;
    __asm__(""
            : "=r"(resultOrIntermediate2)
            : "0"(resultOrIntermediate2), "r"(argumentOrIntermediate4));
    argumentOrIntermediate5 = 0;
    resultOrIntermediate2 =
        Credits_74BA0SyncCdCommandResult(argumentOrIntermediate4, argumentOrIntermediate5);
    fieldOrIntermediate3 = 2;
    if (resultOrIntermediate2 != fieldOrIntermediate3)
        goto block_155;
    fieldOrIntermediate3 = Credits_74BA0_D_8006C510;
block_142:
    switch (fieldOrIntermediate3) {
        case 0:
            MATCHING_OBSERVE_VOLATILE(fieldOrIntermediate3);
            argumentOrIntermediate4 = Credits_74BA0_D_8006E470;
            resultOrIntermediate2 = Credits_74BA0_D_8006C6A8;
            argumentOrIntermediate5 = Credits_74BA0_D_8006C7EC;
            argumentOrIntermediate7 = Credits_74BA0Index6[resultOrIntermediate2 * 2];
            argumentOrIntermediate6 = 0x800;
            goto block_148;
        case 1:
            MATCHING_OBSERVE_VOLATILE(fieldOrIntermediate3);
            bufferRowOrSlotOffset16 = (int)&Credits_74BA0_D_80072098;
            Credits_74BA0Keep(bufferRowOrSlotOffset16);
            Credits_74BA0CopyWordRangeUnrolled4(bufferRowOrSlotOffset16, Credits_74BA0_D_8006C7EC,
                                                0x220);
            resultOrIntermediate2 = Credits_74BA0_D_8006C6A8;
            argumentOrIntermediate4 = Credits_74BA0_D_8006E470;
            fieldOrIntermediate3 = Credits_74BA0Field(bufferRowOrSlotOffset16, int*, 0);
            __asm__(""
                    : "=r"(resultOrIntermediate2)
                    : "0"(resultOrIntermediate2), "r"(argumentOrIntermediate4),
                      "r"(fieldOrIntermediate3));
            argumentOrIntermediate7 = Credits_74BA0Index7[resultOrIntermediate2 * 2];
            argumentOrIntermediate5 = Credits_74BA0_D_8006C7EC;
            argumentOrIntermediate6 = 0x20000;
            goto block_147;
        case 2:
            MATCHING_OBSERVE_VOLATILE(fieldOrIntermediate3);
            argumentOrIntermediate4 = 0;
            Credits_74BA0Keep(argumentOrIntermediate4);
            fieldOrIntermediate3 = 0x200;
            resultOrIntermediate2 = 0x180;
            originalFrame.home18.half.high = resultOrIntermediate2;
            resultOrIntermediate2 = 0x80;
            originalFrame.home18.half.low = fieldOrIntermediate3;
            originalFrame.home1C.half.low = fieldOrIntermediate3;
            originalFrame.home1C.half.high = resultOrIntermediate2;
            Credits_74BA0_DrawSync(argumentOrIntermediate4);
            Credits_74BA0_LoadImage(&originalFrame.home18.word, Credits_74BA0_D_8006C7EC);
            Credits_74BA0_DrawSync(0);
            resultOrIntermediate2 = 0x40000;
            argumentOrIntermediate4 = Credits_74BA0_D_8006E470;
            argumentOrIntermediate5 = Credits_74BA0_D_8006C7EC;
            fieldOrIntermediate3 = Credits_74BA0_D_800720B4;
            argumentOrIntermediate6 = Credits_74BA0_D_800720A4;
            fieldOrIntermediate3 += resultOrIntermediate2;
            argumentOrIntermediate6 += fieldOrIntermediate3;
            resultOrIntermediate2 = Credits_74BA0_D_8006C6A8;
            fieldOrIntermediate3 = Credits_74BA0_D_80072098;
            resultOrIntermediate2 = Credits_74BA0Index8[resultOrIntermediate2 * 2];
            argumentOrIntermediate7 = 0x20000;
            Credits_74BA0_D_8006C500 = argumentOrIntermediate6;
            fieldOrIntermediate3 += resultOrIntermediate2;
        block_147:
            argumentOrIntermediate7 = fieldOrIntermediate3 + argumentOrIntermediate7;
        block_148:
            Credits_74BA0_CDLoadAsync(argumentOrIntermediate4, argumentOrIntermediate5,
                                      argumentOrIntermediate6, argumentOrIntermediate7);
            Credits_74BA0_D_8006C510 = (unsigned short)Credits_74BA0_D_8006C510 + 1;
            return;
        case 3:
            MATCHING_OBSERVE_VOLATILE(fieldOrIntermediate3);
            Credits_74BA0_D_8006C5E4 = 0;
            return;
        case 4:
            MATCHING_OBSERVE_VOLATILE(fieldOrIntermediate3);
            originalFrame.home20.half.low = 0x200;
            originalFrame.home20.half.high = 0x80;
            originalFrame.sp24 = 0x200;
            originalFrame.sp26 = 0x100;
            Credits_74BA0_D_800722BC = Credits_74BA0_D_8006C7F0;
            Credits_74BA0_D_800722C0 = Credits_74BA0_D_8006C7F0;
            Credits_74BA0_DrawSync(0);
            Credits_74BA0_LoadImage(&originalFrame.home20.word, Credits_74BA0_D_8006C7EC);
            originalFrame.home20.half.low = 0x200;
            originalFrame.home20.half.high = 0x180;
            originalFrame.sp24 = 0x200;
            originalFrame.sp26 = 0x80;
            Credits_74BA0_MoveImage(&originalFrame.home20.word, 0x200, 0);
            Credits_74BA0_DrawSync(0);
            Credits_74BA0CopyWordRangeUnrolled4(Credits_74BA0_D_8006C7F0,
                                                Credits_74BA0_D_8006C7EC + 0x40000,
                                                Credits_74BA0_D_8006C500 - 0x40000);
            Credits_74BA0_D_8006C7EC =
                (Credits_74BA0_D_8006C7F0 + Credits_74BA0_D_8006C500) - 0x40000;
            resultOrIntermediate2 = Credits_74BA0_func_credits_8007458C(Credits_74BA0_D_800722C0);
            fieldOrIntermediate3 = 0x2AAAAAAB;
            argumentOrIntermediate5 =
                Credits_74BA0Field((int)&Credits_74BA0_D_8006C6A8, unsigned short*, 0);
            argumentOrIntermediate5 = (int)((unsigned)argumentOrIntermediate5 << 16);
            argumentOrIntermediate4 = argumentOrIntermediate5 >> 16;
            product6.full =
                (long long)(int)argumentOrIntermediate4 * (long long)(int)fieldOrIntermediate3;
            argumentOrIntermediate6 = Credits_74BA0_D_800720A4;
            Credits_74BA0_D_800722C4 = resultOrIntermediate2;
            fieldOrIntermediate3 = Credits_74BA0_D_800722C0;
            argumentOrIntermediate5 >>= 31;
            fieldOrIntermediate3 += argumentOrIntermediate6;
            Credits_74BA0_D_800722C8 = fieldOrIntermediate3;
            Credits_74BA0_D_8006C6AC = fieldOrIntermediate3;
            snapshotOrHighCapture9 = product6.words.high;
            Credits_74BA0Keep(snapshotOrHighCapture9);
            fieldOrIntermediate3 = snapshotOrHighCapture9 >> 1;
            Credits_74BA0Keep(fieldOrIntermediate3);
            fieldOrIntermediate3 -= argumentOrIntermediate5;
            resultOrIntermediate2 = fieldOrIntermediate3 * 12;
            argumentOrIntermediate4 -= resultOrIntermediate2;
            argumentOrIntermediate4 = (short)argumentOrIntermediate4;
            if (argumentOrIntermediate4 >= 11)
                goto block_152;
            Credits_74BA0_D_8006C510 = 0;
            goto block_153;
        block_152:
            Credits_74BA0_D_8006C510 = 3;
        block_153:
            temp_v0_9 = (unsigned short)Credits_74BA0_D_8006C6A8 + 1;
            Credits_74BA0_D_8006C6A8 = temp_v0_9;
            if (temp_v0_9 != 0xC) {
                goto block_155;
            }
            Credits_74BA0_D_8006C6A8 = 6;
        block_155:
            return;
        default:
            goto block_155;
    }
}
#undef Credits_74BA0Field
#undef Credits_74BA0Keep

/* AI generated; not human reviewed. Numeric retail credits actor rebuild. */
typedef struct {
    unsigned char reserved00[4];
    unsigned char kind, roll, pitch, yaw;
    unsigned char reserved08[10];
    short x, y, z;
    unsigned char reserved18[2];
    unsigned short value;
} CreditsLayoutRecord;
extern short D_8006C510, D_8006C5A4;
extern Moby* D_8006C550;
extern CreditsLayoutRecord* D_8006C5F0;
extern unsigned char D_8006E33C, D_8006E33D, D_8006E33E;
extern unsigned char D_8006FC15, D_8006FC16, D_8006FC17, D_8006FC89, D_8006FC8A, D_8006FC8B;
extern int D_8006C598, D_8006D074;
void CreditsShade(int, int, int, int) __asm__("func_credits_800744BC");
extern void func_80022378(void), func_8001C368(void);
void func_credits_80076118(void) {
    volatile unsigned char stackSpace[8];
    register Moby* actor __asm__("$19");
    register unsigned char* fields __asm__("$17");
    register int i __asm__("$18");
    register int offset __asm__("$20");
    register CreditsLayoutRecord* record __asm__("$16");
    if (D_8006C510 == -1) {
        func_8001EBAC();
        return;
    }
    actor = D_8006C550;
    {
        int r = D_8006E33C, g = D_8006E33D, b = D_8006E33E;
        D_8006FC15 = r;
        D_8006FC16 = g;
        D_8006FC17 = b;
        D_8006FC89 = r;
        D_8006FC8A = g;
        D_8006FC8B = b;
    }
    i = 0;
    if (D_8006C5A4 > 0) {
        offset = 0;
        fields = (unsigned char*)actor + 0x47;
        do {
            register int kind __asm__("$3");
            {
                register CreditsLayoutRecord* base __asm__("$2") = D_8006C5F0;
                MATCHING_KEEP(base);
                record = (CreditsLayoutRecord*)((char*)base + offset);
            }
            kind = record->kind;
            MATCHING_KEEP(kind);
            if ((unsigned int)(kind - 1) < 2 || (unsigned char)kind == 3) {
                func_8004E790(actor, 0, 0x58);
                *(int*)(fields - 0x3B) = record->x;
                *(int*)(fields - 0x37) = record->y;
                *(int*)(fields - 0x33) = record->z;
                fields[-3] = record->roll;
                fields[-2] = record->pitch;
                fields[-1] = record->yaw;
                fields[-11] = record->value;
                {
                    int next = record->value;
                    actor++;
                    *(short*)(fields - 0x11) = 0x3B;
                    fields[13] = 2;
                    fields[5] = 255;
                    fields[7] = 32;
                    fields[0] = 127;
                    fields[-10] = next;
                }
                fields += 0x58;
                MATCHING_KEEP(fields);
            }
            offset += 28;
            i++;
        } while (i < D_8006C5A4);
    }
    actor->state = 255;
    if (D_8006C598) {
        int shade = D_8006C598 << 4;
        CreditsShade(2, shade, shade, shade);
    }
    func_8001EC5C();
    D_8006D074 = 0x18000;
    func_80022378();
    func_8001C368();
}
