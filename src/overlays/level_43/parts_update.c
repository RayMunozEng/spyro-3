#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 8008DE8C.
 * Assembly SHA256 482255ea1fc93b54eeb23312609e9b72eaed0dcbed1caa0769633c906c671ab9.
 * AI-generated; not human reviewed. Existing verified C case blocks were
 * adapted against every original target instruction, helper, field width,
 * shared branch entry and stack offset. The complete selector0x3C chain
 * reuses the verified level23 byte-mode source. Selector0x25 retains original
 * saved byte S2 and product T1 phases; selector0x55 uses stack20/22/24 and
 * falls through the single original predicate/byte/removal chain.
 * Physical units/fixed point, full helper semantics and caller cadence are
 * unresolved. Step is the original argument, not an inferred time unit.
 * Original 1720 instructions and 86 owned selectors/targets are mandatory.
 * Empty constraints retain initialized original value lifetimes. Volatile
 * metadata with original branch-address immediates keeps distinct clamp
 * joins and original branch delays; it emits zero CPU instructions. Those
 * addresses are provenance metadata, never runtime constants. Original MULT
 * producers precede all HI/LO captures. C generates every CPU instruction.
 * The original 0x98-byte frame, padding and pointer spill0x68 are retained; step
 * uses ordinary C allocation. Compiler/assembler/pipeline/flags are unchanged.
 * Falsification: native/linked words, internal branch targets, all selectors,
 * preserved data and complete EXE/every-overlay original retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
int Update8DE8CInterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
int Update8DE8CShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
extern unsigned char* Update8DE8CD_8006C550 __asm__("D_8006C550");
int Update8DE8CCountTimerDown(void*, int) __asm__("func_800359A4");
extern int Update8DE8CD_8006C648 __asm__("D_8006C648");
#define Update8DE8CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Update8DE8CInterpolateSine(short) __asm__("func_8004E9E4");
int Update8DE8CInterpolateCosine(short) __asm__("func_8004EA2C");
int Update8DE8CCopyVector(void*, void*) __asm__("func_8004F178");
int Update8DE8CPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
int Update8DE8CAddHalfwordVectors(void*, void*, void*) __asm__("func_8004F5A8");
int Update8DE8CReleaseParticleRecord(void*) __asm__("func_80056504");
extern int Update8DE8CD_8006C644 __asm__("D_8006C644");
extern unsigned short Update8DE8CSin[] __asm__("D_80065920");
extern unsigned short Update8DE8CCos[] __asm__("D_800658A0");
extern int (*Update8DE8CSpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
int Update8DE8Crand(void) __asm__("rand");
extern unsigned char* Update8DE8CD_8006C554 __asm__("D_8006C554");
extern int Update8DE8CD_8006C598 __asm__("D_8006C598");
extern int Update8DE8CD_8006C640 __asm__("D_8006C640");
extern short Update8DE8CD_8006E040 __asm__("D_8006E040");
extern int Update8DE8CD_8006E344 __asm__("D_8006E344");
extern unsigned char Update8DE8CD_80070328[] __asm__("D_80070328");
extern int Update8DE8CPlayer48 __asm__("D_80070328 + 0x48");
extern int Update8DE8CPlayer284 __asm__("D_80070328 + 0x284");
extern int Update8DE8CPlayer280 __asm__("D_80070328 + 0x280");
#define Update8DE8CHigh(a, b)                                                        \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
unsigned char* func_level_43_8008DE8C(int initialStep) {
    register unsigned char* playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    int step;
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[22];
        unsigned short halves[44];
        struct {
            int pad[14];
            volatile int doubled48;
            int rest[7];
        } saved;
    } frame;
    register int scratch5 __asm__("$5");
    register int scratch7 __asm__("$7");
    register int scratch8 __asm__("$8");
    register int predicate3 __asm__("$3");
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$23");
    register int word9 __asm__("$9");
    register int var_a1 __asm__("$5");
    register int iteration __asm__("$16");
    register int predicate2 __asm__("$2");
    register int random2 __asm__("$2");
    register int halfword3 __asm__("$3");
    register int scratch3 __asm__("$3");
    int temp_v0_14;
    int temp_v0_16;
    unsigned short temp_a0_4;
    register int temp_a1 __asm__("$5");
    unsigned short temp_a1_2;
    register unsigned char* recordPlus1 __asm__("$17");
    register unsigned char* record __asm__("$20");
    register unsigned char* recordPlus4 __asm__("$21");
    unsigned char* recordPlus24;
    unsigned char* var_v0;
    unsigned char temp_v0_10;
    unsigned char temp_v0_11;
    unsigned char temp_v0_13;
    unsigned char temp_v0_15;
    unsigned char temp_v0_17;
    unsigned char temp_v0_18;
    unsigned char temp_v0_19;
    unsigned char temp_v0_4;
    unsigned char temp_v0_5;
    unsigned char temp_v0_6;
    unsigned char temp_v0_7;
    unsigned char temp_v0_8;
    unsigned char temp_v0_9;
    unsigned char temp_v1;
    unsigned char temp_v1_10;
    register int scratch4 __asm__("$4");
    register int low19 __asm__("$19");
    register int savedLow22 __asm__("$22");
    int mode18;
    int maskedLow0;
    record = Update8DE8CD_8006C554;
    incomingStep = initialStep;
    MATCHING_KEEP2(record, incomingStep);
    step = incomingStep;
    MATCHING_KEEP2_CLOBBER(record, step, "$4");
    scratch4 = Update8DE8CField(record, unsigned char*, 1);
    MATCHING_KEEP(scratch4);
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2 = 255;
    MATCHING_KEEP(scratch2);
    scratch3 = scratch4 & 255;
    MATCHING_KEEP2(scratch3, scratch4);
    MATCHING_KEEP(step);
    if (scratch3 != scratch2) {
        word9 = step * 2;
        MATCHING_KEEP(step);
        quadrupledStep = step * 4;
        MATCHING_KEEP2(quadrupledStep, step);
        recordPlus1 = record + 1;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(recordPlus1, "memory");
        frame.saved.doubled48 = word9;
        word9 = (int)(record + 0x18);
        MATCHING_KEEP(word9);
        recordPlus24 = (unsigned char*)word9;
        recordPlus4 = record + 4;
        MATCHING_KEEP_VOLATILE_CLOBBER(scratch4, "memory");
        scratch3 = scratch4 & 0xFF;
        MATCHING_KEEP2(scratch3, scratch4);
        do {
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            if (scratch3 != 0xFE) {
                if (Update8DE8CD_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update8DE8CD_8006C598 == 0) {
                            goto dispatchRecord;
                        }
                        goto removeRecord;
                    }
                    goto nextRecord;
                }
            dispatchRecord:
                temp_v1 = *record;
                switch (temp_v1) {
                    case 0x0:
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word9);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled48;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        scratch3 += word9;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        scratch2 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        predicate2 = (unsigned int)scratch2 < 32;
                        scratch3 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x1:
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        if (scratch2 != 0) {
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        word9 = 1;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 += quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 24;
                        MATCHING_KEEP2(predicate2, scratch3);
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x2:
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        if (Update8DE8CField(recordPlus1, short*, 0x1D) != 0)
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) =
                                Update8DE8CField(recordPlus1, unsigned short*, 0x1B) + 1;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        word9 = 1;
                        __asm__("" : "=r"(word9) : "0"(word9), "r"(scratch2));
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        word9 = frame.saved.doubled48;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += word9;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        predicate2 = scratch3 < quadrupledStep;
                        if (!predicate2) {
                            scratch2 = scratch3 - quadrupledStep;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        } else
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        predicate2 = scratch3 < quadrupledStep;
                        if (!predicate2) {
                            scratch2 = scratch3 - quadrupledStep;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        } else
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = 0;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        predicate2 = scratch3 < quadrupledStep;
                        if (!predicate2) {
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(step, "memory");
                            scratch2 = scratch3 - quadrupledStep;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                        } else
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        goto checkPredicate;
                    case 0x9:
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word9);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled48;
                        scratch3 += word9;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch3;
                        goto checkPredicate;
                    case 0xA:
                        scratch3 = Update8DE8CPlayer48;
                        if (scratch3 == 30 && Update8DE8CPlayer280 < 0)
                            goto removeRecord;
                        playerEnd = Update8DE8CD_80070328 + 0x288;
                        MATCHING_KEEP(playerEnd);
                        if (Update8DE8CField(playerEnd, int*, 0) != 0)
                            goto removeRecord;
                        if (Update8DE8CPlayer284 == 0)
                            goto removeRecord;
                        Update8DE8CCopyVector(&frame.words[0], playerEnd - 0x288);
                        scratch2 = Update8DE8CInterpolateCosine(
                            Update8DE8CField(recordPlus1, short*, 0x17));
                        scratch3 = frame.words[0];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 >>= 4;
                        scratch3 += scratch2;
                        frame.words[0] = scratch3;
                        scratch2 =
                            Update8DE8CInterpolateSine(Update8DE8CField(recordPlus1, short*, 0x17));
                        scratch4 = (int)recordPlus4;
                        playerEnd = (unsigned char*)&frame.words[0];
                        MATCHING_KEEP3(scratch4, playerEnd, scratch2);
                        scratch2 >>= 4;
                        scratch3 = frame.words[1];
                        scratch6 = frame.words[2];
                        MATCHING_KEEP3(scratch2, scratch3, scratch6);
                        scratch3 += scratch2;
                        scratch6 += 256;
                        frame.words[1] = scratch3;
                        frame.words[2] = scratch6;
                        MATCHING_KEEP(scratch6);
                        Update8DE8CPackVectorShiftRight2((void*)scratch4, playerEnd);
                        scratch4 = Update8DE8CField(recordPlus1, unsigned short*, 0x17);
                        scratch4 += 64;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x17) = scratch4;
                        MATCHING_KEEP(scratch4);
                        scratch4 <<= 16;
                        scratch2 = Update8DE8CD_8006E040;
                        MATCHING_KEEP2(scratch4, scratch2);
                        scratch4 >>= 16;
                        scratch4 -= scratch2;
                        scratch2 = Update8DE8CInterpolateCosine(scratch4 & 4095);
                        scratch3 = 0x60606061;
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch2 < 0)
                            scratch2 = -scratch2;
                        MATCHING_KEEP2(scratch2, scratch3);
                        high7 = Update8DE8CHigh(scratch2, scratch3);
                        scratch2 >>= 31;
                        MATCHING_KEEP(scratch2);
                        scratch3 = high7 >> 6;
                        scratch3 -= scratch2;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch3;
                        goto nextRecord;
                    case 0xB:
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                        scratch4 = (int)recordPlus4;
                        if (scratch2 != 0) {
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x15);
                            scratch2++;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x15) = scratch2;
                        }
                        playerEnd = recordPlus4;
                        MATCHING_KEEP2(scratch4, playerEnd);
                        scratch6 = (int)record + 18;
                        __asm__("" : "=r"(scratch6) : "0"(scratch6) : "$3", "memory");
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        word9 = 1;
                        MATCHING_KEEP2(word9, scratch2);
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        Update8DE8CAddHalfwordVectors((void*)scratch4, playerEnd, (void*)scratch6);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        word9 = frame.saved.doubled48;
                        MATCHING_KEEP2(scratch2, word9);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        scratch2 += word9;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xA);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xA) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 &= 255;
                        MATCHING_KEEP2(scratch3, scratch2);
                        scratch2 -= 4;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        if (scratch3 == 0)
                            goto removeRecord;
                        goto checkByte2;
                    case 0xC:
                        Update8DE8CField(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update8DE8CField(recordPlus1, unsigned char*, 0xA) + 8);
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        temp_v0_4 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_4 != 0) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_4 - 8);
                        }
                        temp_v0_5 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_5 != 0) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_5 - 8);
                        }
                        temp_v0_6 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_6 != 0) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_6 - 8);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update8DE8CField(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0xD:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 28)
                            goto removeRecord;
                        if (Update8DE8CField(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        __asm__ volatile("" ::: "$8", "memory");
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        word9 = 1;
                        __asm__("" : "=r"(word9) : "0"(word9), "r"(scratch2));
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        word9 = frame.saved.doubled48;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP3(scratch2, word9, scratch3);
                        scratch2 += word9;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        if ((unsigned int)scratch3 >= 13) {
                            scratch2 = scratch3 - 12;
                            scratch2 *= 8;
                            word9 = 128;
                            MATCHING_KEEP(word9);
                            scratch2 = word9 - scratch2;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 64;
                            scratch3 -= 12;
                            scratch3 *= 4;
                            scratch2 -= scratch3;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                        } else {
                            predicate2 = (unsigned int)scratch3 < 5;
                            MATCHING_KEEP(predicate2);
                            if (!predicate2) {
                                word9 = 128;
                                MATCHING_KEEP_CLOBBER(word9, "memory");
                                scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                                scratch2 = -128;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = word9;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                                scratch3 -= 4;
                                scratch3 *= 8;
                                scratch2 -= scratch3;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            } else {
                                word9 = 128;
                                MATCHING_KEEP_CLOBBER(word9, "memory");
                                scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                                MATCHING_KEEP2(scratch2, word9);
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = word9;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = word9;
                                word9 = 128;
                                MATCHING_KEEP(word9);
                                scratch2 *= 32;
                                scratch2 = word9 - scratch2;
                                if (scratch2 < 0)
                                    scratch2 = 0;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            }
                        }
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    case 0x21:
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        if (Update8DE8CField(recordPlus1, short*, 0x1D) != 0) {
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*,
                                                                  0x1B) +
                                                 1);
                        }
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        word9 = frame.saved.doubled48;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        MATCHING_KEEP3(scratch2, word9, scratch3);
                        scratch4 = scratch2 - word9;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        word9 = 1;
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled48;
                        scratch3 += word9;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch3;
                        if (scratch4 < 0) {
                            scratch4 = 0;
                        }
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) =
                            (unsigned char)scratch4;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) =
                            (unsigned char)scratch4;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) =
                            (unsigned char)scratch4;
                        temp_v0_7 = Update8DE8CField(recordPlus1, unsigned char*, 1) + step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = temp_v0_7;
                        if (((unsigned int)(temp_v0_7 & 0xFF) < 0x20U) &&
                            (Update8DE8CField(recordPlus1, unsigned char*, 2) != 0) &&
                            (scratch4 != 0)) {
                            recordPlus1 += 0x20;
                        } else {
                            goto removeRecord;
                        }
                        break;
                    case 0x25:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch3 = scratch2 + step;
                        MATCHING_KEEP2(scratch2, scratch3);
                        mode18 = scratch2 & 255;
                        MATCHING_KEEP2(mode18, scratch3);
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch3;
                        scratch3 &= 255;
                        predicate2 = (unsigned int)scratch3 < 49;
                        if (!predicate2)
                            goto removeRecord;
                        if ((unsigned int)scratch3 < 16) {
                            register int product9 __asm__("$9");
                            register void* temporary16 __asm__("$16");
                            temp_a1 = 0;
                            __asm__("" : "=r"(temp_a1) : "0"(temp_a1) : "$4", "memory");
                            scratch2 = Update8DE8CField(recordPlus1, short*, 0x17);
                            product9 = scratch2 * scratch3;
                            MATCHING_KEEP(product9);
                            scratch2 = product9 >> 1;
                            frame.halves[8] = scratch2;
                            scratch3 = Update8DE8CField(recordPlus1, short*, 0x19);
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                            product9 = scratch3 * scratch2;
                            MATCHING_KEEP(product9);
                            scratch2 = product9 >> 1;
                            frame.halves[9] = scratch2;
                            scratch3 = Update8DE8CField(recordPlus1, short*, 0x1B);
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                            product9 = scratch3 * scratch2;
                            temporary16 = &frame.words[6];
                            MATCHING_KEEP2(product9, temporary16);
                            scratch2 = product9 >> 1;
                            frame.halves[10] = scratch2;
                            scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                            scratch4 = scratch2 * 88;
                            scratch2 = (int)Update8DE8CD_8006C550;
                            Update8DE8CInterpolateMobyVertex((void*)(scratch2 + scratch4), temp_a1,
                                                             temporary16);
                            Update8DE8CShiftVectorRightTowardZero(temporary16, 2);
                            scratch3 = frame.words[6];
                            scratch2 = frame.halves[8];
                            scratch2 += scratch3;
                            Update8DE8CField(recordPlus1, unsigned short*, 3) = scratch2;
                            scratch3 = frame.words[7];
                            scratch2 = frame.halves[9];
                            scratch2 += scratch3;
                            Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch3 = frame.words[8];
                            scratch2 = frame.halves[10];
                            scratch2 += scratch3;
                            Update8DE8CField(recordPlus1, unsigned short*, 7) = scratch2;
                            goto original25Tail;
                        }
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                    original25Tail:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 129) {
                            __asm__ volatile("" : : "i"(0x8008E6B4));
                            word9 = 128;
                            MATCHING_KEEP(word9);
                            Update8DE8CField(recordPlus1, unsigned char*, 9) = word9;
                        }
                        __asm__("" ::: "$2", "memory");
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch3 < 17) {
                            scratch2 = 256;
                            goto addedEarlyAge;
                        }
                        predicate2 = mode18 < 17;
                        MATCHING_KEEP(predicate2);
                        if (predicate2)
                            Update8DE8CSpawnParticle(1, 56, record, 0);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch2 -= 16;
                        scratch3 = scratch2 * 8;
                        scratch2 = 256;
                        scratch3 = scratch2 - scratch3;
                        if (scratch3 >= 256)
                            scratch3 = 255;
                        if (scratch3 < 0)
                            scratch3 = 0;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 >>= 1;
                        if (scratch3 >= scratch2)
                            goto nextRecord;
                    addedStoreByteC:
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch3, "memory");
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        goto nextRecord;
                    addedEarlyAge:
                        scratch3 = scratch3 * 16;
                        scratch3 = scratch2 - scratch3;
                        if (scratch3 >= 256)
                            scratch3 = 255;
                        if (scratch3 >= 32)
                            goto addedStoreByteC;
                        scratch3 = 32;
                        goto addedStoreByteC;
                    case 0x29:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0x1D);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += 1;
                        scratch8 = scratch2 & 255;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        if ((unsigned int)scratch3 < (unsigned int)scratch8) {
                            if (Update8DE8CField(recordPlus1, unsigned char*, 0x1E) == 0)
                                goto removeRecord;
                            Update8DE8CSpawnParticle(1, 43, recordPlus4, 0);
                            goto removeRecord;
                        }
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x17);
                        scratch7 = Update8DE8CField(recordPlus1, short*, 0x11);
                        MATCHING_KEEP2(scratch2, scratch7);
                        scratch2 -= scratch7;
                        scratch2 *= scratch8;
                        scratch8 = scratch2 / scratch3;
                        scratch6 = Update8DE8CField(recordPlus1, short*, 0x13);
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x19);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP3(scratch2, scratch3, scratch6);
                        scratch2 -= scratch6;
                        scratch2 *= scratch3;
                        scratch5 = Update8DE8CField(recordPlus1, unsigned char*, 0x1D);
                        scratch5 = scratch2 / scratch5;
                        scratch4 = Update8DE8CField(recordPlus1, unsigned short*, 0x15);
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch4, "memory");
                        scratch3 = Update8DE8CField(recordPlus1, unsigned short*, 0x15);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 7);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x15) = scratch3;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 += scratch4;
                        Update8DE8CField(recordPlus1, unsigned short*, 7) = scratch2;
                        scratch2 = Update8DE8CD_8006C644;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0x1C);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 *= 8;
                        scratch2 += scratch3;
                        scratch2 &= 255;
                        scratch7 += scratch8;
                        Update8DE8CField(recordPlus1, unsigned short*, 3) = scratch7;
                        scratch6 += scratch5;
                        Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch6;
                        scratch2 = Update8DE8CSin[scratch2];
                        MATCHING_KEEP(scratch2);
                        scratch2 <<= 16;
                        scratch2 >>= 26;
                        scratch2 += 10;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch2 = Update8DE8CD_8006C644;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0x1C);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 *= 8;
                        scratch2 += scratch3;
                        scratch2 &= 255;
                        scratch2 = Update8DE8CCos[scratch2];
                        MATCHING_KEEP(scratch2);
                        scratch2 <<= 16;
                        scratch2 >>= 27;
                        scratch2 += 6;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xA) = scratch2;
                        goto nextRecord;
                    case 0x2A:
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch2 = scratch3 + 1;
                        predicate3 = (unsigned int)scratch3 < 16;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        if (!predicate3)
                            goto removeRecord;
                        if (Update8DE8CField(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        scratch4 = Update8DE8CField(recordPlus1, short*, 0x11);
                        scratch5 = Update8DE8CField(recordPlus1, short*, 0x13);
                        MATCHING_KEEP4(scratch2, scratch3, scratch4, scratch5);
                        scratch2 += 2;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        scratch3 -= 6;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= 6;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, int*, 0x17);
                        scratch3 -= 6;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, int*, 0x1B);
                        scratch2 += scratch4;
                        Update8DE8CField(recordPlus1, int*, 0x17) = scratch2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch2 = Update8DE8CField(recordPlus1, int*, 0x17);
                        scratch3 += scratch5;
                        Update8DE8CField(recordPlus1, int*, 0x1B) = scratch3;
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch3 = Update8DE8CField(recordPlus1, int*, 0x1B);
                        scratch2 >>= 2;
                        scratch3 >>= 2;
                        Update8DE8CField(recordPlus1, unsigned short*, 3) = scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch3;
                        goto nextRecord;
                    case 0x2B:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        if ((unsigned int)scratch2 < 4)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x17);
                        temp_a1 = 3;
                        if (scratch2 != 0)
                            temp_a1 = 2;
                        scratch4 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        MATCHING_KEEP2_CLOBBER(scratch4, temp_a1, "memory");
                        scratch3 = Update8DE8CField(recordPlus1, short*, 0x17);
                        scratch2 = scratch4 + 1;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        if (scratch3 != 0) {
                            scratch2 = scratch4 + 2;
                            Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        }
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= temp_a1;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        scratch3 -= temp_a1;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch2 -= temp_a1;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        goto nextRecord;
                    case 0x2E:
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch2 = scratch3 + 1;
                        predicate3 = (unsigned int)scratch3 < 16;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        if (!predicate3)
                            goto removeRecord;
                        if (Update8DE8CField(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += 3;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        scratch3 -= 8;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= 8;
                        scratch3 -= 8;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto nextRecord;
                    case 0x32:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        if (scratch2 == 0)
                            goto nextRecord;
                        scratch2 = Update8DE8CD_8006C648;
                        scratch4 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch3 = (scratch2 << 3) - scratch2;
                        scratch4 -= scratch3;
                        if (scratch4 < 0)
                            scratch4 = 0;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch4;
                        if (Update8DE8CCountTimerDown(record + 2, 1) != 0)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x38:
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 49)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 129) {
                            __asm__ volatile("" ::: "$8", "memory");
                            word9 = 128;
                            MATCHING_KEEP(word9);
                            Update8DE8CField(recordPlus1, unsigned char*, 9) = word9;
                        }
                        __asm__ volatile("" : : "r"(step) : "$4", "memory");
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP_CLOBBER(scratch3, "$2");
                        if ((unsigned int)scratch3 < 16)
                            scratch2 = scratch3 * 4;
                        else {
                            scratch2 = 48;
                            scratch2 -= scratch3;
                            scratch2 *= 2;
                        }
                        if (scratch2 <= 0)
                            goto removeRecord;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                        goto nextRecord;
                    case 0x3B:
                        Update8DE8CField(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update8DE8CField(recordPlus1, unsigned char*, 0xA) + 8);
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        if (Update8DE8CD_8006C640 & 1) {
                            Update8DE8CField(recordPlus1, unsigned short*, 0x19) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*,
                                                                  0x19) +
                                                 1);
                        }
                        temp_v0_8 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_8 != 0) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_8 - 4);
                        }
                        temp_v0_9 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_9 != 0) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_9 - 4);
                        }
                        temp_v0_10 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_10 != 0) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_10 - 4);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update8DE8CField(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0x3C:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        low19 = scratch2 & 31;
                        savedLow22 = low19;
                        __asm__("" : "=r"(savedLow22) : "0"(savedLow22), "r"(low19));
                        mode18 = (unsigned int)scratch2 >> 5;
                        maskedLow0 = (unsigned char)savedLow22;
                        if ((unsigned int)maskedLow0 >= 28)
                            goto removeRecord;
                        if (Update8DE8CField(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        Update8DE8CAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update8DE8CField(recordPlus1, short*, 0x1D);
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 9);
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled48;
                        MATCHING_KEEP(word9);
                        scratch3 += word9;
                        Update8DE8CField(recordPlus1, unsigned char*, 9) = scratch3;
                        if (mode18 == 0) {
                            if ((unsigned int)maskedLow0 >= 13) {
                                scratch4 = maskedLow0 - 12;
                                scratch2 = scratch4 << 3;
                                word9 = 128;
                                MATCHING_KEEP(word9);
                                scratch3 = word9 - scratch2;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008ECA4));
                                    scratch3 = 0;
                                }
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                                scratch3 = scratch4 << 2;
                                scratch2 = 64;
                                scratch3 = scratch2 - scratch3;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008ECC0));
                                    scratch3 = 0;
                                }
                                goto storeByte12Zero13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                word9 = 128;
                                scratch3 = low19 - 4;
                                scratch3 <<= 3;
                                scratch2 = -128;
                                scratch2 -= scratch3;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = word9;
                                goto storeWordToByte12Zero13;
                            }
                            scratch2 = maskedLow0 << 5;
                            word9 = 128;
                            scratch3 = word9 - scratch2;
                            MATCHING_KEEP_VOLATILE(word9);
                            word9 = 128;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = word9;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = word9;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x8008ED04));
                                scratch3 = 0;
                            }
                            goto storeByte13;
                        }
                        word9 = 1;
                        MATCHING_KEEP(word9);
                        if (mode18 == word9) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008ED3C));
                                    scratch3 = 0;
                                }
                                goto storeByte12Zero13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                                goto storeWordToByte12Zero13;
                            }
                            scratch2 = maskedLow0 << 5;
                            word9 = 128;
                            scratch3 = word9 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x8008ED70));
                                scratch3 = 0;
                            }
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        storeByte13:
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                            goto finishByteModes;
                        }
                        if (mode18 == 2) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008EDB0));
                                    scratch3 = 0;
                                }
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = 0;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = maskedLow0 << 5;
                            word9 = 128;
                            scratch3 = word9 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x8008EDF4));
                                scratch3 = 0;
                            }
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            goto storeByte13;
                        }
                        if (mode18 == 3) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008EE30));
                                    scratch3 = 0;
                                }
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = 0;
                                goto finishByteModes;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = maskedLow0 << 5;
                            word9 = 128;
                            scratch3 = word9 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x8008EE74));
                                scratch3 = 0;
                            }
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                            goto finishByteModes;
                        }
                        if (mode18 == 4) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008EEB4));
                                    scratch3 = 0;
                                }
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                                goto storeByte13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = 0;
                            storeWordToBytes12And13:
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                                goto finishByteModes;
                            }
                            scratch2 = savedLow22 << 5;
                            word9 = 128;
                            scratch3 = word9 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x8008EEEC));
                                scratch3 = 0;
                            }
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto finishByteModes;
                        }
                        if (mode18 == 5) {
                            MATCHING_KEEP_VOLATILE(savedLow22);
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008EF2C));
                                    scratch3 = 0;
                                }
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                            storeByte12Zero13:
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch3 = (unsigned char)savedLow22;
                            if ((unsigned int)scratch3 >= 5) {
                                scratch2 = savedLow22 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            storeWordToByte12Zero13:
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = scratch3 << 5;
                            word9 = 128;
                            MATCHING_KEEP_VOLATILE(word9);
                            word9 = 128;
                            scratch3 = word9 - scratch2;
                            scratch2 = 255;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x8008EF84));
                                scratch3 = 0;
                            }
                            goto storeByte13;
                        }
                        if (mode18 == 6) {
                            if ((unsigned int)maskedLow0 >= 4) {
                                scratch2 = maskedLow0 << 3;
                                scratch2 -= maskedLow0;
                                scratch3 = 160;
                                scratch3 -= scratch2;
                                scratch2 = (unsigned char)scratch3;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x8008EFB8));
                                    scratch3 = 0;
                                }
                                scratch2 = (unsigned char)scratch3;
                                scratch2 = (unsigned int)scratch2 >> 1;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                                scratch2 = (unsigned int)scratch2 >> 1;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch3;
                                Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                                goto finishByteModes;
                            }
                            scratch2 = 160;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 80;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            scratch2 = 40;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto finishByteModes;
                        }
                        if (mode18 == 7 && savedLow22 != 0)
                            Update8DE8CReleaseParticleRecord(record);
                        goto finishByteModes;
                    finishByteModes:
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch3 = savedLow22 + step;
                        scratch2 &= 224;
                        scratch3 |= scratch2;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch3;
                        goto nextRecord;
                    case 0x3D:
                        if (Update8DE8CField(recordPlus1, short*, 0x1D) != 0)
                            Update8DE8CField(recordPlus1, unsigned short*, 0x1B) =
                                Update8DE8CField(recordPlus1, unsigned short*, 0x1B) + 1;
                        word9 = 1;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                        scratch2 = word9 - scratch2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                        scratch3 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch3 -= quadrupledStep;
                        Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$3", "memory");
                        scratch2 += step;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$8", "memory");
                        scratch2 &= 255;
                        predicate2 = (unsigned int)scratch2 < 32;
                        goto checkPredicate;
                    case 0x42:
                        iteration = 0;
                        if (step > 0) {
                            do {
                                if (Update8DE8CField(recordPlus1, unsigned char*, 1) & 1) {
                                    scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 3);
                                    scratch4 = Update8DE8CField(recordPlus1, unsigned short*, 0xF);
                                    scratch3 = Update8DE8CField(recordPlus1, unsigned short*, 5);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    temp_a1 = Update8DE8CField(recordPlus1, unsigned short*, 0x11);
                                    scratch2 += scratch4;
                                    Update8DE8CField(recordPlus1, unsigned short*, 3) = scratch2;
                                    scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 7);
                                    scratch4 = Update8DE8CField(recordPlus1, unsigned short*, 0x13);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch3 += temp_a1;
                                    Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch3;
                                    scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch2 += scratch4;
                                    scratch3 &= 2;
                                    Update8DE8CField(recordPlus1, unsigned short*, 7) = scratch2;
                                    if (scratch3 != 0) {
                                        random2 = Update8DE8Crand();
                                        halfword3 =
                                            Update8DE8CField(recordPlus1, unsigned short*, 0xF);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update8DE8CField(recordPlus1, unsigned short*, 0xF) =
                                            halfword3;
                                        random2 = Update8DE8Crand();
                                        halfword3 =
                                            Update8DE8CField(recordPlus1, unsigned short*, 0x11);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update8DE8CField(recordPlus1, unsigned short*, 0x11) =
                                            halfword3;
                                        random2 = Update8DE8Crand();
                                        halfword3 =
                                            Update8DE8CField(recordPlus1, unsigned short*, 0x13);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update8DE8CField(recordPlus1, unsigned short*, 0x13) =
                                            halfword3;
                                    }
                                }
                                iteration += 1;
                                Update8DE8CField(recordPlus1, unsigned char*, 1) =
                                    (unsigned char)(Update8DE8CField(recordPlus1, unsigned char*,
                                                                     1) +
                                                    1);
                            } while (iteration < step);
                        }
                        predicate2 =
                            (unsigned char)Update8DE8CField(recordPlus1, unsigned char*, 1) < 0x18U;
                        goto checkPredicate;
                    case 0x46:
                        temp_v0_11 = Update8DE8CField(recordPlus1, unsigned char*, 1) + 1;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = temp_v0_11;
                        if (((unsigned int)(temp_v0_11 & 0xFF) < 0x20U) &&
                            (Update8DE8CField(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_3 =
                                (int)((short)Update8DE8CField(recordPlus1, unsigned short*, 9) -
                                      (short)Update8DE8CField(recordPlus1, unsigned short*, 3)) >>
                                1;
                            frame.halves[8] = (unsigned short)temp_a0_3;
                            frame.halves[9] =
                                (unsigned short)((int)((short)Update8DE8CField(
                                                           recordPlus1, unsigned short*, 0xB) -
                                                       (short)Update8DE8CField(
                                                           recordPlus1, unsigned short*, 5)) >>
                                                 1);
                            frame.halves[10] =
                                (unsigned short)((int)((short)Update8DE8CField(
                                                           recordPlus1, unsigned short*, 0xD) -
                                                       (short)Update8DE8CField(
                                                           recordPlus1, unsigned short*, 7)) >>
                                                 1);
                            Update8DE8CField(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 3) +
                                                 temp_a0_3);
                            Update8DE8CField(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 5) +
                                                 frame.halves[9]);
                            Update8DE8CField(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 7) +
                                                 frame.halves[10]);
                            random2 = Update8DE8Crand();
                            halfword3 = frame.halves[8];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[8] = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = frame.halves[9];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[9] = halfword3;
                            if (Update8DE8CField(recordPlus1, unsigned char*, 1) & 1) {
                                frame.halves[10] -= 1;
                            }
                            random2 = Update8DE8CField(recordPlus1, unsigned short*, 9);
                            halfword3 = frame.halves[8];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update8DE8CField(recordPlus1, unsigned short*, 9) = random2;
                            random2 = Update8DE8CField(recordPlus1, unsigned short*, 0xB);
                            halfword3 = frame.halves[9];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update8DE8CField(recordPlus1, unsigned short*, 0xB) = random2;
                            halfword3 = Update8DE8CField(recordPlus1, unsigned short*, 0xD);
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xF);
                            scratch4 = frame.halves[10];
                            MATCHING_KEEP3(halfword3, scratch2, scratch4);
                            scratch2 = scratch2 - 3;
                            halfword3 += scratch4;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 &= 255;
                            MATCHING_KEEP2(scratch2, halfword3);
                            Update8DE8CField(recordPlus1, unsigned short*, 0xD) = halfword3;
                            if ((unsigned int)scratch2 < 128) {
                                word9 = 128;
                                MATCHING_KEEP(word9);
                                Update8DE8CField(recordPlus1, unsigned char*, 0xF) = word9;
                            }
                            temp_v0_13 = Update8DE8CField(recordPlus1, unsigned char*, 0x10) - 4;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x10) = temp_v0_13;
                            if ((unsigned int)(temp_v0_13 & 0xFF) < 0x60U) {
                                Update8DE8CField(recordPlus1, unsigned char*, 0x10) = 0x60U;
                            }
                            Update8DE8CField(recordPlus1, unsigned char*, 0x11) = 0;
                            temp_v0_14 =
                                (unsigned char)Update8DE8CField(recordPlus1, unsigned char*, 0x13) -
                                3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x13) = temp_v0_14;
                            if ((unsigned int)(temp_v0_14 & 0xFF) < 0xC0U) {
                                Update8DE8CField(recordPlus1, unsigned char*, 0x13) = 0xC0;
                            }
                            temp_v0_15 = Update8DE8CField(recordPlus1, unsigned char*, 0x14) - 4;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x14) = temp_v0_15;
                            if ((unsigned int)(temp_v0_15 & 0xFF) < 0x80U) {
                                __asm__ volatile("" : : "i"(0x8008F318));
                                word9 = 128;
                                MATCHING_KEEP(word9);
                                Update8DE8CField(recordPlus1, unsigned char*, 0x14) = word9;
                            }
                            temp_v0_16 =
                                (unsigned char)Update8DE8CField(recordPlus1, unsigned char*, 0x15) -
                                6;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x15) = temp_v0_16;
                            if ((unsigned int)(temp_v0_16 & 0xFF) < 0x20U) {
                                Update8DE8CField(recordPlus1, unsigned char*, 0x15) = 0x20;
                            }
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x47:
                        temp_v0_17 = Update8DE8CField(recordPlus1, unsigned char*, 1) + 1;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = temp_v0_17;
                        if (((unsigned int)(temp_v0_17 & 0xFF) < 0x20U) &&
                            (Update8DE8CField(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[10] =
                                (short)Update8DE8CField(recordPlus1, unsigned short*, 9) -
                                (short)Update8DE8CField(recordPlus1, unsigned short*, 3);
                            frame.words[11] =
                                (short)Update8DE8CField(recordPlus1, unsigned short*, 0xB) -
                                (short)Update8DE8CField(recordPlus1, unsigned short*, 5);
                            frame.words[12] =
                                (short)Update8DE8CField(recordPlus1, unsigned short*, 0xD) -
                                (short)Update8DE8CField(recordPlus1, unsigned short*, 7);
                            random2 = Update8DE8Crand();
                            halfword3 = frame.words[10];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[10] = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = frame.words[11];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[11] = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = frame.words[12];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[12] = halfword3;
                            Update8DE8CField(recordPlus1, unsigned short*, 9) =
                                (short)((unsigned short)Update8DE8CField(recordPlus1,
                                                                         unsigned short*, 9) +
                                        frame.words[10]);
                            Update8DE8CField(recordPlus1, unsigned short*, 0xB) =
                                (short)((unsigned short)Update8DE8CField(recordPlus1,
                                                                         unsigned short*, 0xB) +
                                        frame.words[11]);
                            Update8DE8CField(recordPlus1, unsigned short*, 0xD) =
                                (short)((unsigned short)Update8DE8CField(recordPlus1,
                                                                         unsigned short*, 0xD) +
                                        frame.words[12]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[10];
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 9);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update8DE8CField(recordPlus1, unsigned short*, 3) = scratch2;
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[11];
                            scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0xB);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0x13);
                            scratch4 = frame.words[12];
                            scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0x15);
                            MATCHING_KEEP3(scratch2, scratch4, scratch3);
                            scratch2 -= 2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x13) = scratch2;
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0x14);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 4;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x15) = scratch3;
                            scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0x10);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x14) = scratch2;
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xF);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x10) = scratch3;
                            scratch3 = Update8DE8CField(recordPlus1, unsigned short*, 0xD);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0x11);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= scratch4;
                            Update8DE8CField(recordPlus1, unsigned short*, 7) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 3;
                            Update8DE8CField(recordPlus1, unsigned char*, 0x11) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x48:
                        temp_v0_18 = Update8DE8CField(recordPlus1, unsigned char*, 1) + 1;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = temp_v0_18;
                        if (((unsigned int)(temp_v0_18 & 0xFF) < 0x38U) &&
                            (Update8DE8CField(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[10] =
                                (int)((short)Update8DE8CField(recordPlus1, unsigned short*, 3) -
                                      (short)Update8DE8CField(recordPlus1, unsigned short*, 9)) >>
                                1;
                            frame.words[11] =
                                (int)((short)Update8DE8CField(recordPlus1, unsigned short*, 5) -
                                      (short)Update8DE8CField(recordPlus1, unsigned short*, 0xB)) >>
                                1;
                            frame.words[12] =
                                (int)((short)Update8DE8CField(recordPlus1, unsigned short*, 7) -
                                      (short)Update8DE8CField(recordPlus1, unsigned short*, 0xD)) >>
                                1;
                            random2 = Update8DE8Crand();
                            halfword3 = frame.words[10];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[10] = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = frame.words[11];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[11] = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = frame.words[12];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[12] = halfword3;
                            Update8DE8CField(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 3) +
                                                 frame.words[10]);
                            Update8DE8CField(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 5) +
                                                 frame.words[11]);
                            Update8DE8CField(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 7) +
                                                 frame.words[12]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            Update8DE8CField(recordPlus1, unsigned short*, 9) =
                                (short)(Update8DE8CField(recordPlus1, unsigned short*, 3) -
                                        (frame.words[10] * 2));
                            Update8DE8CField(recordPlus1, unsigned short*, 0xB) =
                                (short)(Update8DE8CField(recordPlus1, unsigned short*, 5) -
                                        (frame.words[11] * 2));
                            Update8DE8CField(recordPlus1, unsigned short*, 0xD) =
                                (short)(Update8DE8CField(recordPlus1, unsigned short*, 7) -
                                        (frame.words[12] * 2));
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4E:
                        temp_v0_19 = Update8DE8CField(recordPlus1, unsigned char*, 1) + 1;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = temp_v0_19;
                        if (((unsigned int)(temp_v0_19 & 0xFF) < 0x28U) &&
                            (Update8DE8CField(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_4 = Update8DE8CField(recordPlus1, unsigned short*, 0x11);
                            temp_a1_2 = Update8DE8CField(recordPlus1, unsigned short*, 0x13);
                            Update8DE8CField(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 3) +
                                                 Update8DE8CField(recordPlus1, unsigned short*,
                                                                  0xF));
                            Update8DE8CField(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 5) +
                                                 temp_a0_4);
                            Update8DE8CField(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 7) +
                                                 temp_a1_2);
                            random2 = Update8DE8Crand();
                            halfword3 = Update8DE8CField(recordPlus1, unsigned short*, 0xF);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update8DE8CField(recordPlus1, unsigned short*, 0xF) = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = Update8DE8CField(recordPlus1, unsigned short*, 0x11);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x11) = halfword3;
                            random2 = Update8DE8Crand();
                            halfword3 = Update8DE8CField(recordPlus1, unsigned short*, 0x13);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update8DE8CField(recordPlus1, unsigned short*, 0x13) = halfword3;
                            MATCHING_KEEP(halfword3);
                            halfword3 = (short)halfword3;
                            if (halfword3 >= 3)
                                Update8DE8CField(recordPlus1, unsigned short*, 0x13) = 2;
                            scratch2 = Update8DE8CField(recordPlus1, short*, 0x13);
                            if (scratch2 < -4)
                                Update8DE8CField(recordPlus1, short*, 0x13) = -4;
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xB);
                            scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0xD);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= 2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0xC);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch3 -= 1;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xD) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 2;
                            Update8DE8CField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4F:
                        temp_a0_5 =
                            (int)((short)Update8DE8CField(recordPlus1, unsigned short*, 9) -
                                  (short)Update8DE8CField(recordPlus1, unsigned short*, 3)) >>
                            1;
                        frame.halves[8] = (unsigned short)temp_a0_5;
                        frame.halves[9] =
                            (unsigned short)((int)((short)Update8DE8CField(recordPlus1,
                                                                           unsigned short*, 0xB) -
                                                   (short)Update8DE8CField(recordPlus1,
                                                                           unsigned short*, 5)) >>
                                             1);
                        frame.halves[10] =
                            (unsigned short)((int)((short)Update8DE8CField(recordPlus1,
                                                                           unsigned short*, 0xD) -
                                                   (short)Update8DE8CField(recordPlus1,
                                                                           unsigned short*, 7)) >>
                                             1);
                        Update8DE8CField(recordPlus1, unsigned short*, 3) =
                            (unsigned short)(Update8DE8CField(recordPlus1, unsigned short*, 3) +
                                             temp_a0_5);
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[9];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch2;
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[10];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update8DE8CField(recordPlus1, unsigned short*, 7) = scratch2;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        random2 = Update8DE8CField(recordPlus1, unsigned short*, 9);
                        halfword3 = frame.halves[8];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update8DE8CField(recordPlus1, unsigned short*, 9) = random2;
                        random2 = Update8DE8CField(recordPlus1, unsigned short*, 0xB);
                        halfword3 = frame.halves[9];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update8DE8CField(recordPlus1, unsigned short*, 0xB) = random2;
                        halfword3 = Update8DE8CField(recordPlus1, unsigned short*, 0xD);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[10];
                        MATCHING_KEEP3(halfword3, scratch2, scratch4);
                        scratch2 = scratch2 + 1;
                        halfword3 += scratch4;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, halfword3);
                        Update8DE8CField(recordPlus1, unsigned short*, 0xD) = halfword3;
                        if ((unsigned int)scratch2 >= 24)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0x11);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned char*, 0x15);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= 3;
                        Update8DE8CField(recordPlus1, unsigned char*, 0x11) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 0x10);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 3;
                        MATCHING_KEEP2(scratch3, scratch2);
                        Update8DE8CField(recordPlus1, unsigned char*, 0x15) = scratch3;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 -= 4;
                        Update8DE8CField(recordPlus1, unsigned char*, 0x10) = scratch2;
                        temp_v1_10 =
                            (unsigned char)Update8DE8CField(recordPlus1, unsigned char*, 0x13);
                        Update8DE8CField(recordPlus1, unsigned char*, 0x14) =
                            (unsigned char)(Update8DE8CField(recordPlus1, unsigned char*, 0x14) -
                                            4);
                        if (temp_v1_10 >= 6U) {
                            Update8DE8CField(recordPlus1, unsigned char*, 0x13) =
                                (signed char)(temp_v1_10 - 6);
                        }
                        goto nextRecord;
                    case 0x55:
                        scratch4 = Update8DE8CField(recordPlus1, unsigned short*, 9);
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 3);
                        scratch4 -= scratch2;
                        frame.halves[8] = scratch4;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0xB);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned short*, 5);
                        scratch2 -= scratch3;
                        frame.halves[9] = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0xD);
                        scratch3 = Update8DE8CField(recordPlus1, unsigned short*, 7);
                        scratch2 -= scratch3;
                        frame.halves[10] = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 3);
                        scratch2 += scratch4;
                        Update8DE8CField(recordPlus1, unsigned short*, 3) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[9];
                        scratch2 += scratch3;
                        Update8DE8CField(recordPlus1, unsigned short*, 5) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[10];
                        scratch2 += scratch3;
                        Update8DE8CField(recordPlus1, unsigned short*, 7) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 9);
                        scratch3 = frame.halves[8];
                        scratch2 += scratch3;
                        Update8DE8CField(recordPlus1, unsigned short*, 9) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned short*, 0xB);
                        scratch3 = frame.halves[9];
                        scratch2 += scratch3;
                        scratch3 = Update8DE8CField(recordPlus1, unsigned short*, 0xD);
                        Update8DE8CField(recordPlus1, unsigned short*, 0xB) = scratch2;
                        scratch2 = Update8DE8CField(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[10];
                        scratch2 += 1;
                        scratch3 += scratch4;
                        Update8DE8CField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        predicate2 = (unsigned int)scratch2 < 2;
                        Update8DE8CField(recordPlus1, unsigned short*, 0xD) = scratch3;
                    checkPredicate:
                        if (predicate2 == 0)
                            goto removeRecord;
                    checkByte2:
                        if (Update8DE8CField(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        goto nextRecord;
                    removeRecord:
                        Update8DE8CReleaseParticleRecord(record);
                        goto nextRecord;
                    default:
                        goto nextRecord;
                }
            } else {
            nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus4 += 0x20;
            word9 = (int)recordPlus24;
            MATCHING_KEEP(word9);
            word9 += 0x20;
            recordPlus24 = (unsigned char*)word9;
            scratch4 = *recordPlus1;
            MATCHING_KEEP(scratch4);
            __asm__ __volatile__("" ::: "$2", "memory");
            scratch2 = 255;
            MATCHING_KEEP(scratch2);
            scratch3 = scratch4 & 0xFF;
            MATCHING_KEEP3(scratch4, scratch3, scratch2);
            record += 0x20;
        } while (scratch3 != scratch2);
    }
    return record;
}
#undef Update8DE8CHigh
#undef Update8DE8CField
