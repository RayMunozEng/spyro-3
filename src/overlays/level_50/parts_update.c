#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80096A58.
 * Assembly SHA256 01c76f0044f4f9ed7272cb6113567c7896a8376d616f7e12584cd04f087ae151.
 * AI-generated; not human reviewed. Verified C cases are adapted against
 * every original instruction. The large0x3C chain reuses verified level47 C.
 * All raw field widths, literals, helper arguments, stack offsets and shared
 * branch entries are retained. Physical units/fixed point, complete helper
 * semantics and caller cadence remain unresolved. Step is the original
 * argument, not an inferred time unit.
 * Original2020 instructions and85 owned selectors/targets are mandatory.
 * The original0xE0-byte frame retains double at SP0x78 and pointer at SP0xB0.
 * Raw128 uses ordinary C allocation to the original persistent FP constant;
 * no fixed FP binding. Cases0/1/B retain original A0 quad producers. Case39
 * retains the original SP0x50 vector and shared age entry;4F/54 share the
 * original removal call. Empty initialized constraints preserve original
 * producer lifetimes, constants and distinct joins, emitting zero CPU words.
 * Original MULT producers precede every HI/LO capture. C generates every CPU
 * instruction; compiler/assembler/pipeline/flags/padding/gates are unchanged.
 * Falsification: all native/linked words, conditional/internal targets,
 * selectors, preserved data and full EXE/every-overlay original retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Update96A58Step()                       \
    ({                                          \
        word9 = frame.saved.step88;             \
        __asm__("" : "=r"(word9) : "0"(word9)); \
        word9;                                  \
    })
int Update96A58SubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
int Update96A58ShiftVectorLeft(void*, int) __asm__("func_8004F0E8");
int Update96A58MeasureVectorLength(void*, int) __asm__("func_8004EDE8");
extern int Update96A58D_8006C5C8 __asm__("D_8006C5C8");
extern unsigned char Update96A58D_8006E020[] __asm__("D_8006E020");
extern unsigned short Update96A58Table658A0[] __asm__("D_800658A0");
extern unsigned short Update96A58Table65920[] __asm__("D_80065920");
int Update96A58CountTimerDown(void*, int) __asm__("func_800359A4");
#define Update96A58Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Update96A58func_8004E9E4(short) __asm__("func_8004E9E4");
int Update96A58InterpolateCosine(short) __asm__("func_8004EA2C");
int Update96A58CopyVector(void*, void*) __asm__("func_8004F178");
int Update96A58PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
int Update96A58func_8004F5A8(void*, void*, void*) __asm__("func_8004F5A8");
int Update96A58func_80056504(void*) __asm__("func_80056504");
extern int Update96A58D_8006C644 __asm__("D_8006C644");
extern unsigned short Update96A58Sin[] __asm__("D_80065920");
extern unsigned short Update96A58Cos[] __asm__("D_800658A0");
extern int (*Update96A58SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
int Update96A58rand(void) __asm__("rand");
extern unsigned char* Update96A58D_8006C554 __asm__("D_8006C554");
extern int Update96A58D_8006C598 __asm__("D_8006C598");
extern int Update96A58D_8006C640 __asm__("D_8006C640");
extern short Update96A58D_8006E040 __asm__("D_8006E040");
extern int Update96A58D_8006E344 __asm__("D_8006E344");
extern unsigned char Update96A58D_80070328[] __asm__("D_80070328");
extern int Update96A58Player48 __asm__("D_80070328 + 0x48");
extern int Update96A58Player284 __asm__("D_80070328 + 0x284");
extern int Update96A58Player280 __asm__("D_80070328 + 0x280");
#define Update96A58High(a, b)                                                        \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
unsigned char* func_level_50_80096A58(int initialStep) {
    register int quadrupledStep __asm__("$4");
    register void* vector17 __asm__("$17");
    int halfwordMinus1;
    int halfwordMinus2;
    register unsigned char* playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$9");
    register int step __asm__("$23");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[40];
        unsigned short halves[80];
        struct {
            int pad[26];
            volatile int doubled78;
            int rest[13];
        } saved;
    } frame;
    register int scratch5 __asm__("$5");
    register int scratch7 __asm__("$7");
    register int scratch8 __asm__("$8");
    register int predicate3 __asm__("$3");
    int temp_a0_3;
    int temp_a0_5;
    int raw128;
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
    register unsigned char* recordPlus1 __asm__("$18");
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
    int mode17;
    int maskedLow0;
    record = Update96A58D_8006C554;
    incomingStep = initialStep;
    MATCHING_KEEP2(record, incomingStep);
    step = incomingStep;
    MATCHING_KEEP2_CLOBBER(record, step, "$4");
    scratch4 = Update96A58Field(record, unsigned char*, 1);
    MATCHING_KEEP(scratch4);
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2 = 255;
    MATCHING_KEEP(scratch2);
    scratch3 = scratch4 & 255;
    MATCHING_KEEP2(scratch3, scratch4);
    MATCHING_KEEP(step);
    if (scratch3 != scratch2) {
        word9 = step * 2;
        MATCHING_KEEP2(word9, step);
        raw128 = 128;
        MATCHING_KEEP(raw128);
        recordPlus1 = record + 1;
        MATCHING_KEEP_VOLATILE_CLOBBER(recordPlus1, "memory");
        frame.saved.doubled78 = word9;
        word9 = (int)(record + 0x18);
        MATCHING_KEEP(word9);
        recordPlus24 = (unsigned char*)word9;
        recordPlus4 = record + 4;
        MATCHING_KEEP_VOLATILE_CLOBBER(scratch4, "memory");
        scratch3 = scratch4 & 255;
        MATCHING_KEEP2(scratch3, scratch4);
        do {
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            if (scratch3 != 0xFE) {
                if (Update96A58D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update96A58D_8006C598 == 0) {
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
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word9);
                        quadrupledStep = step * 4;
                        MATCHING_KEEP(quadrupledStep);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled78;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 += word9;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        scratch2 -= quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        predicate2 = (unsigned int)scratch2 < 32;
                        scratch3 -= quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x1:
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word9);
                        quadrupledStep = step * 4;
                        MATCHING_KEEP(quadrupledStep);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch3 -= quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch2 += quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch3 -= quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        goto checkMasked24;
                    case 0x4:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch3 = Update96A58Field(recordPlus1, short*, 0x17);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += 1;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        if (scratch2 < scratch3) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                            scratch2 += 4;
                            Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        }
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xA);
                        scratch4 = Update96A58Field(recordPlus1, unsigned char*, 0x19);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                        scratch5 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                        MATCHING_KEEP4(scratch3, scratch4, scratch2, scratch5);
                        scratch3 += scratch4;
                        scratch2 += scratch5;
                        Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                        scratch2 <<= 16;
                        Update96A58Field(recordPlus1, unsigned char*, 0xA) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, short*, 0x1D);
                        scratch2 >>= 16;
                        predicate3 = scratch3 < scratch2;
                        MATCHING_KEEP(predicate3);
                        if (!predicate3)
                            goto nextRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch2 -= 4;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 < 9)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x9:
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word9);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled78;
                        scratch3 += word9;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch3;
                        goto checkPredicate;
                    case 0xA:
                        scratch3 = Update96A58Player48;
                        if (scratch3 == 30 && Update96A58Player280 < 0)
                            goto removeRecord;
                        playerEnd = Update96A58D_80070328 + 0x288;
                        MATCHING_KEEP(playerEnd);
                        if (Update96A58Field(playerEnd, int*, 0) != 0)
                            goto removeRecord;
                        if (Update96A58Player284 == 0)
                            goto removeRecord;
                        Update96A58CopyVector(&frame.words[0], playerEnd - 0x288);
                        scratch2 = Update96A58InterpolateCosine(
                            Update96A58Field(recordPlus1, short*, 0x17));
                        scratch3 = frame.words[0];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 >>= 4;
                        scratch3 += scratch2;
                        frame.words[0] = scratch3;
                        scratch2 =
                            Update96A58func_8004E9E4(Update96A58Field(recordPlus1, short*, 0x17));
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
                        Update96A58PackVectorShiftRight2((void*)scratch4, playerEnd);
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 += 64;
                        Update96A58Field(recordPlus1, unsigned short*, 0x17) = scratch4;
                        MATCHING_KEEP(scratch4);
                        scratch4 <<= 16;
                        scratch2 = Update96A58D_8006E040;
                        MATCHING_KEEP2(scratch4, scratch2);
                        scratch4 >>= 16;
                        scratch4 -= scratch2;
                        scratch2 = Update96A58InterpolateCosine(scratch4 & 4095);
                        scratch3 = 0x60606061;
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch2 < 0)
                            scratch2 = -scratch2;
                        MATCHING_KEEP2(scratch2, scratch3);
                        high7 = Update96A58High(scratch2, scratch3);
                        scratch2 >>= 31;
                        MATCHING_KEEP(scratch2);
                        scratch3 = high7 >> 6;
                        scratch3 -= scratch2;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch3;
                        goto nextRecord;
                    case 0xB:
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        scratch4 = (int)recordPlus4;
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x15);
                            scratch2++;
                            Update96A58Field(recordPlus1, unsigned short*, 0x15) = scratch2;
                        }
                        playerEnd = recordPlus4;
                        scratch6 = (int)record + 18;
                        MATCHING_KEEP3(scratch4, playerEnd, scratch6);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        word9 = 1;
                        MATCHING_KEEP(word9);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        Update96A58func_8004F5A8((void*)scratch4, playerEnd, (void*)scratch6);
                        quadrupledStep = step * 4;
                        MATCHING_KEEP(quadrupledStep);
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        word9 = frame.saved.doubled78;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += word9;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xA);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += quadrupledStep;
                        Update96A58Field(recordPlus1, unsigned char*, 0xA) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 &= 255;
                        MATCHING_KEEP2(scratch3, scratch2);
                        scratch2 -= 4;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        if (scratch3 == 0)
                            goto removeRecord;
                        goto checkByte2;
                    case 0xC:
                        Update96A58Field(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update96A58Field(recordPlus1, unsigned char*, 0xA) + 8);
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        temp_v0_4 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_4 != 0) {
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_4 - 8);
                        }
                        temp_v0_5 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_5 != 0) {
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_5 - 8);
                        }
                        temp_v0_6 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_6 != 0) {
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_6 - 8);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0xD: {
                        register void* temporary17 __asm__("$17");
                        register void* other16 __asm__("$16");
                        scratch3 = Update96A58D_8006C5C8;
                        scratch2 = 2;
                        if (scratch3 != scratch2)
                            goto original13Body;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto original13Body;
                        scratch2 = 255;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xA);
                        if (scratch3 == scratch2)
                            goto original13Body;
                        scratch2 = Update96A58Field(recordPlus1, short*, 3);
                        temporary17 = &frame.words[4];
                        frame.words[4] = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, short*, 5);
                        frame.words[5] = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, short*, 7);
                        frame.words[6] = scratch2;
                        Update96A58ShiftVectorLeft(temporary17, 2);
                        other16 = &frame.words[8];
                        Update96A58SubtractVector(other16, temporary17, Update96A58D_8006E020);
                        scratch2 = Update96A58MeasureVectorLength(other16, 0);
                        if (scratch2 < 0x546)
                            goto removeRecord;
                    }
                    original13Body:;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 28)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        word9 = 1;
                        MATCHING_KEEP(word9);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        {
                            register int originalDouble9 __asm__("$9") = frame.saved.doubled78;
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                            MATCHING_KEEP3(originalDouble9, scratch3, scratch2);
                            scratch2 += originalDouble9;
                        }
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if (!(predicate2 = (unsigned int)scratch3 < 13)) {
                            scratch2 = (scratch3 - 12) << 3;
                            scratch2 = raw128 - scratch2;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 64;
                            scratch3 = (scratch3 - 12) << 2;
                            scratch2 -= scratch3;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto zeroDAndAge;
                        } else if (!(predicate2 = (unsigned int)scratch3 < 5)) {
                            scratch2 = -128;
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = 0;
                            scratch3 = (scratch3 - 4) << 3;
                            scratch2 -= scratch3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto originalAge;
                        } else {
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            scratch2 <<= 5;
                            scratch2 = raw128 - scratch2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = raw128;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto originalAge;
                        }
                    case 0xE:
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) != 0) {
                            halfwordMinus1 =
                                Update96A58Field(recordPlus1, unsigned short*, 0x1B) - 1;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = halfwordMinus1;
                            if ((short)halfwordMinus1 == -1) {
                                if (Update96A58Field(recordPlus1, unsigned char*, 1) != 0) {
                                    Update96A58SpawnParticle(1, 0x12, (Vector3D*)recordPlus4, 0);
                                }
                                goto removeRecord;
                            }
                            if (Update96A58Field(recordPlus1, unsigned char*, 2) != 0) {
                                scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                                scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                                scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                                temp_a1 = Update96A58Field(recordPlus1, unsigned short*, 0x15);
                                scratch6 = Update96A58Field(recordPlus1, unsigned char*, 0x1E);
                                MATCHING_KEEP5(scratch2, scratch3, scratch4, temp_a1, scratch6);
                                scratch2 += scratch3;
                                Update96A58Field(recordPlus1, unsigned short*, 0x17) = scratch2;
                                scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x19);
                                scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                                scratch2 += scratch4;
                                scratch3 *= 2;
                                Update96A58Field(recordPlus1, unsigned short*, 0x19) = scratch2;
                                scratch3 = Update96A58Field(Update96A58Table65920, unsigned short*,
                                                            scratch3);
                                scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                                scratch4 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                                MATCHING_KEEP3(scratch3, scratch2, scratch4);
                                scratch3 = (scratch3 << 16) >> 23;
                                scratch2 += scratch3;
                                scratch4 *= 2;
                                Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                                scratch4 = Update96A58Field(Update96A58Table658A0, unsigned short*,
                                                            scratch4);
                                scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                                scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                                MATCHING_KEEP5(scratch4, scratch2, scratch3, temp_a1, scratch6);
                                scratch2 += temp_a1;
                                scratch3 += scratch6;
                                scratch4 <<= 16;
                                Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                                scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x19);
                                scratch4 >>= 23;
                                Update96A58Field(recordPlus1, unsigned char*, 0x1D) = scratch3;
                                scratch2 += scratch4;
                                Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                            }
                            goto nextRecord;
                        }
                        halfwordMinus2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B) - 2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1B) = halfwordMinus2;
                        if ((halfwordMinus2 << 16) <= 0)
                            goto removeRecord;
                        scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                        MATCHING_KEEP3(scratch3, scratch2, scratch4);
                        scratch3 *= 2;
                        scratch2 += scratch3;
                        scratch4 *= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x17) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x19);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                        scratch2 += scratch4;
                        scratch3 *= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x19) = scratch2;
                        scratch2 =
                            Update96A58Field(Update96A58Table65920, unsigned short*, scratch3);
                        scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x15);
                        MATCHING_KEEP3(scratch2, scratch3, scratch4);
                        scratch2 = (scratch2 << 16) >> 23;
                        scratch3 += scratch2;
                        scratch4 *= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 3) = scratch3;
                        __asm__ volatile("" ::: "$3", "memory");
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                        scratch3 *= 2;
                        temp_a1 =
                            Update96A58Field(Update96A58Table658A0, unsigned short*, scratch3);
                        scratch2 += scratch4;
                        Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                        __asm__ volatile("" ::: "$3", "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x1E);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                        MATCHING_KEEP3(scratch2, scratch3, temp_a1);
                        scratch2 *= 2;
                        scratch3 += scratch2;
                        temp_a1 <<= 16;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x19);
                        temp_a1 >>= 23;
                        Update96A58Field(recordPlus1, unsigned char*, 0x1D) = scratch3;
                        scratch2 += temp_a1;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                        goto nextRecord;
                    case 0x12:
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) != 0) {
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 9);
                            if (scratch3 >= 5U) {
                                scratch2 = scratch3 - 1;
                                MATCHING_KEEP(scratch2);
                                Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                                goto nextRecord;
                            }
                        }
                        goto removeRecord;
                    case 0x21:
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        if (Update96A58Field(recordPlus1, short*, 0x1D) != 0) {
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*,
                                                                  0x1B) +
                                                 1);
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        word9 = frame.saved.doubled78;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        MATCHING_KEEP3(scratch2, word9, scratch3);
                        scratch4 = scratch2 - word9;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        word9 = 1;
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled78;
                        scratch3 += word9;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch3;
                        if (scratch4 < 0) {
                            scratch4 = 0;
                        }
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) =
                            (unsigned char)scratch4;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) =
                            (unsigned char)scratch4;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) =
                            (unsigned char)scratch4;
                        temp_v0_7 = Update96A58Field(recordPlus1, unsigned char*, 1) + step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = temp_v0_7;
                        if (((unsigned int)(temp_v0_7 & 0xFF) < 0x20U) &&
                            (Update96A58Field(recordPlus1, unsigned char*, 2) != 0) &&
                            (scratch4 != 0)) {
                            recordPlus1 += 0x20;
                        } else {
                            goto removeRecord;
                        }
                        break;
                    case 0x27:
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x17);
                        if (scratch2 > 0) {
                            scratch3 = scratch2;
                            MATCHING_KEEP(scratch3);
                            scratch2 = scratch3 - 1;
                        } else {
                            scratch3 = scratch2;
                            MATCHING_KEEP(scratch3);
                            scratch2 = scratch3 + 1;
                        }
                        Update96A58Field(recordPlus1, unsigned short*, 0x17) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x19);
                        if (scratch2 > 0) {
                            scratch3 = scratch2;
                            MATCHING_KEEP(scratch3);
                            scratch2 = scratch3 - 1;
                        } else {
                            scratch3 = scratch2;
                            MATCHING_KEEP(scratch3);
                            scratch2 = scratch3 + 1;
                        }
                        Update96A58Field(recordPlus1, unsigned short*, 0x19) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                        scratch2 += 1;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        scratch2 <<= 16;
                        scratch2 >>= 16;
                        if (scratch2 >= 25)
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = 24;
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch4 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch4);
                        scratch2 <<= 4;
                        scratch2 &= 0x1F0;
                        scratch4 <<= 4;
                        scratch4 &= 0x1F0;
                        MATCHING_KEEP2(scratch2, scratch4);
                        scratch3 = Update96A58Field(Update96A58Sin, unsigned short*, scratch2);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 3);
                        scratch3 <<= 16;
                        scratch3 >>= 25;
                        scratch2 += scratch3;
                        Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch4, "memory");
                        scratch3 = Update96A58Field(Update96A58Cos, unsigned short*, scratch4);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 5);
                        scratch4 = Update96A58Field(recordPlus1, unsigned char*, 0xA);
                        MATCHING_KEEP3(scratch3, scratch2, scratch4);
                        scratch3 <<= 16;
                        scratch3 >>= 25;
                        scratch2 += scratch3;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                        if (scratch4 == 0 || (Update96A58D_8006C640 & 1) != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                            scratch2 += 1;
                            Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        }
                        if (Update96A58CountTimerDown(record + 2, 1) != 0)
                            goto removeRecord;
                        if (Update96A58Field(recordPlus1, unsigned char*, 0xA) == 0)
                            goto checkByte2;
                        recordPlus1 += 32;
                        break;
                    case 0x29:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += 1;
                        scratch8 = scratch2 & 255;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        if ((unsigned int)scratch3 < (unsigned int)scratch8) {
                            if (Update96A58Field(recordPlus1, unsigned char*, 0x1E) == 0)
                                goto removeRecord;
                            Update96A58SpawnParticle(1, 43, recordPlus4, 0);
                            goto removeRecord;
                        }
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x17);
                        scratch7 = Update96A58Field(recordPlus1, short*, 0x11);
                        MATCHING_KEEP2(scratch2, scratch7);
                        scratch2 -= scratch7;
                        scratch2 *= scratch8;
                        scratch8 = scratch2 / scratch3;
                        scratch6 = Update96A58Field(recordPlus1, short*, 0x13);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x19);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP3(scratch2, scratch3, scratch6);
                        scratch2 -= scratch6;
                        scratch2 *= scratch3;
                        scratch5 = Update96A58Field(recordPlus1, unsigned char*, 0x1D);
                        scratch5 = scratch2 / scratch5;
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x15);
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch4, "memory");
                        scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0x15);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x15) = scratch3;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 += scratch4;
                        Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                        scratch2 = Update96A58D_8006C644;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1C);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 *= 8;
                        scratch2 += scratch3;
                        scratch2 &= 255;
                        scratch7 += scratch8;
                        Update96A58Field(recordPlus1, unsigned short*, 3) = scratch7;
                        scratch6 += scratch5;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch6;
                        scratch2 = Update96A58Sin[scratch2];
                        MATCHING_KEEP(scratch2);
                        scratch2 <<= 16;
                        scratch2 >>= 26;
                        scratch2 += 10;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch2 = Update96A58D_8006C644;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1C);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 *= 8;
                        scratch2 += scratch3;
                        scratch2 &= 255;
                        scratch2 = Update96A58Cos[scratch2];
                        MATCHING_KEEP(scratch2);
                        scratch2 <<= 16;
                        scratch2 >>= 27;
                        scratch2 += 6;
                        Update96A58Field(recordPlus1, unsigned char*, 0xA) = scratch2;
                        goto nextRecord;
                    case 0x2A:
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 = scratch3 + 1;
                        predicate3 = (unsigned int)scratch3 < 16;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        if (!predicate3)
                            goto removeRecord;
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        scratch4 = Update96A58Field(recordPlus1, short*, 0x11);
                        scratch5 = Update96A58Field(recordPlus1, short*, 0x13);
                        MATCHING_KEEP4(scratch2, scratch3, scratch4, scratch5);
                        scratch2 += 2;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        scratch3 -= 6;
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= 6;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, int*, 0x17);
                        scratch3 -= 6;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, int*, 0x1B);
                        scratch2 += scratch4;
                        Update96A58Field(recordPlus1, int*, 0x17) = scratch2;
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch2 = Update96A58Field(recordPlus1, int*, 0x17);
                        scratch3 += scratch5;
                        Update96A58Field(recordPlus1, int*, 0x1B) = scratch3;
                        MATCHING_BARRIER_VOLATILE("memory");
                        scratch3 = Update96A58Field(recordPlus1, int*, 0x1B);
                        scratch2 >>= 2;
                        scratch3 >>= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch3;
                        goto nextRecord;
                    case 0x2B:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        if ((unsigned int)scratch2 < 4)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x17);
                        temp_a1 = 3;
                        if (scratch2 != 0)
                            temp_a1 = 2;
                        scratch4 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        MATCHING_KEEP2_CLOBBER(scratch4, temp_a1, "memory");
                        scratch3 = Update96A58Field(recordPlus1, short*, 0x17);
                        scratch2 = scratch4 + 1;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if (scratch3 != 0) {
                            scratch2 = scratch4 + 2;
                            Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= temp_a1;
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        scratch3 -= temp_a1;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch2 -= temp_a1;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        goto nextRecord;
                    case 0x2C:
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                        scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0x19);
                        scratch5 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                        MATCHING_KEEP4(scratch2, scratch4, scratch3, scratch5);
                        scratch2 += scratch4;
                        Update96A58Field(recordPlus1, unsigned short*, 0x17) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x15);
                        scratch3 += scratch5;
                        Update96A58Field(recordPlus1, unsigned short*, 0x19) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1B);
                        scratch2 += scratch4;
                        scratch3 *= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch3, "memory");
                        scratch3 = Update96A58Field(Update96A58Sin, unsigned short*, scratch3);
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 = Update96A58Field(recordPlus1, unsigned char*, 0x1B);
                        MATCHING_KEEP3(scratch3, scratch2, scratch4);
                        scratch3 <<= 16;
                        scratch3 >>= 24;
                        scratch2 += scratch3;
                        scratch4 *= 2;
                        Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x1B);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x1C);
                        scratch4 = Update96A58Field(Update96A58Cos, unsigned short*, scratch4);
                        MATCHING_KEEP3(scratch2, scratch3, scratch4);
                        scratch2 += scratch3;
                        scratch4 <<= 16;
                        scratch4 >>= 24;
                        Update96A58Field(recordPlus1, unsigned char*, 0x1B) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x19);
                        scratch3 = Update96A58D_8006C640;
                        scratch2 += scratch4;
                        scratch3 &= 3;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                        if (scratch3 == 0) {
                            scratch2 = Update96A58Field(recordPlus1, short*, 0x15);
                            scratch3 = scratch2;
                            MATCHING_KEEP2(scratch2, scratch3);
                            if (scratch2 < 9) {
                                scratch2 = scratch3 + 1;
                                MATCHING_KEEP(scratch2);
                                Update96A58Field(recordPlus1, unsigned short*, 0x15) = scratch2;
                            }
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 9);
                            if ((unsigned int)scratch3 < 20) {
                                scratch2 = scratch3 + 1;
                                MATCHING_KEEP(scratch2);
                                Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                            }
                        }
                        scratch2 = Update96A58Field(recordPlus1, short*, 7);
                        scratch3 = Update96A58Field(recordPlus1, short*, 0x1D);
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch2 >= scratch3) {
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x10);
                            scratch2 = 3;
                            if (scratch3 != scratch2)
                                goto removeRecord;
                        sharedSpawn43:
                            Update96A58SpawnParticle(1, 43, recordPlus4, 0);
                            goto removeRecord;
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch2, "memory");
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_VOLATILE("memory");
                        goto checkByte2;
                    case 0x2E:
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 = scratch3 + 1;
                        predicate3 = (unsigned int)scratch3 < 16;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        if (!predicate3)
                            goto removeRecord;
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += 3;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        scratch3 -= 8;
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= 8;
                        scratch3 -= 8;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto nextRecord;
                    case 0x37:
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP(scratch3);
                        scratch2 = scratch3 + step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 49)
                            goto removeRecord;
                        scratch3 &= 255;
                        MATCHING_KEEP_CLOBBER(scratch3, "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 129)
                            Update96A58Field(recordPlus1, unsigned char*, 9) = raw128;
                        scratch4 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch4 < 17) {
                            scratch2 = 256;
                            goto addedEarlyAge;
                        }
                        predicate2 = scratch3 < 17;
                        MATCHING_KEEP(predicate2);
                        if (predicate2)
                            Update96A58SpawnParticle(1, 56, record, 0);
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 -= 16;
                        scratch3 = scratch2 * 8;
                        scratch2 = 256;
                        scratch3 = scratch2 - scratch3;
                        if (scratch3 >= 256)
                            scratch3 = 255;
                        if (scratch3 < 0)
                            scratch3 = 0;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 >>= 1;
                        if (scratch3 >= scratch2)
                            goto nextRecord;
                    addedStoreByteC:
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch3, "memory");
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        goto nextRecord;
                    addedEarlyAge:
                        scratch3 = scratch4 * 16;
                        scratch3 = scratch2 - scratch3;
                        if (scratch3 >= 256)
                            scratch3 = 255;
                        if (scratch3 >= 32)
                            goto addedStoreByteC;
                        scratch3 = 32;
                        goto addedStoreByteC;
                    case 0x38:
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 49)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 129)
                            Update96A58Field(recordPlus1, unsigned char*, 9) = raw128;
                        __asm__ volatile("" : : "r"(step) : "$4", "memory");
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
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
                        Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                        goto nextRecord;
                    case 0x39: {
                        register void* temporary17 __asm__("$17");
                        register void* other16 __asm__("$16");
                        scratch3 = Update96A58D_8006C5C8;
                        scratch2 = 2;
                        if (scratch3 != scratch2)
                            goto original39Body;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto original39Body;
                        __asm__ volatile("" ::: "$3", "memory");
                        scratch2 = Update96A58Field(recordPlus1, short*, 3);
                        temporary17 = &frame.words[12];
                        frame.words[12] = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, short*, 5);
                        frame.words[13] = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, short*, 7);
                        frame.words[14] = scratch2;
                        Update96A58ShiftVectorLeft(temporary17, 2);
                        other16 = &frame.words[16];
                        Update96A58SubtractVector(other16, temporary17, Update96A58D_8006E020);
                        scratch2 = Update96A58MeasureVectorLength(other16, 0);
                        if (scratch2 < 0x546)
                            goto removeRecord;
                    }
                    original39Body:;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 28)
                            goto removeRecord;
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        __asm__ volatile("" ::: "$9", "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$9", "memory");
                        word9 = 1;
                        MATCHING_KEEP2(scratch2, word9);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        word9 = frame.saved.doubled78;
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP3(scratch2, word9, scratch3);
                        scratch2 += word9;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if ((unsigned int)scratch3 >= 13) {
                            scratch2 = scratch3 - 12;
                            scratch2 *= 8;
                            MATCHING_KEEP(raw128);
                            scratch2 = raw128 - scratch2;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            scratch2 = 64;
                            scratch3 -= 12;
                            scratch3 *= 4;
                            scratch2 -= scratch3;
                            goto shared39Clamp;
                        } else {
                            predicate2 = (unsigned int)scratch3 < 5;
                            MATCHING_KEEP(predicate2);
                            scratch4 = -128;
                            if (!predicate2) {
                                MATCHING_KEEP_CLOBBER(raw128, "memory");
                                scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                                __asm__ volatile(""
                                                 : "=r"(scratch2)
                                                 : "0"(scratch2)
                                                 : "$3", "memory");
                                scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                                MATCHING_KEEP3_VOLATILE(scratch2, scratch3, raw128);
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = raw128;
                                MATCHING_KEEP3_VOLATILE_CLOBBER(scratch2, scratch3, scratch4,
                                                                "memory");
                                scratch2 = (scratch2 - 4) * 8;
                                scratch2 = scratch4 - scratch2;
                                scratch3 = (scratch3 - 4) * 8;
                                scratch4 -= scratch3;
                                MATCHING_KEEP2_VOLATILE_CLOBBER(scratch2, scratch4, "memory");
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch4;
                                goto originalAge;
                            } else {
                                MATCHING_KEEP_CLOBBER(raw128, "memory");
                                scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                                MATCHING_KEEP2(scratch2, raw128);
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = raw128;
                                MATCHING_KEEP(raw128);
                                scratch2 *= 32;
                                scratch2 = raw128 - scratch2;
                            shared39Clamp:
                                if (scratch2 < 0)
                                    scratch2 = 0;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            }
                        }
                        goto originalAge;
                    case 0x3A:
                        if ((unsigned int)Update96A58Field(recordPlus1, unsigned char*, 1) >= 28)
                            goto removeRecord;
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        word9 = frame.saved.doubled78;
                        scratch2 += word9;
                        MATCHING_KEEP(scratch3);
                        scratch4 = scratch3 & 255;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if (!(predicate2 = (unsigned int)scratch4 < 13)) {
                            scratch2 = (scratch4 - 12) << 2;
                            scratch3 = 64;
                            scratch3 -= scratch2;
                            if (scratch3 < 0)
                                scratch3 = 0;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            scratch2 = (scratch2 - 12) << 3;
                            scratch3 = raw128 - scratch2;
                            if (scratch3 < 0)
                                scratch3 = 0;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                            goto zeroDAndAge;
                        } else if (!(predicate2 = (unsigned int)scratch4 < 5)) {
                            scratch3 = (scratch3 - 4) << 3;
                            scratch2 = -128;
                            scratch2 -= scratch3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = raw128;
                        zeroDAndAge:
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = 0;
                        }
                    originalAge:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    case 0x3B:
                        Update96A58Field(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update96A58Field(recordPlus1, unsigned char*, 0xA) + 8);
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        if (Update96A58D_8006C640 & 1) {
                            Update96A58Field(recordPlus1, unsigned short*, 0x19) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*,
                                                                  0x19) +
                                                 1);
                        }
                        temp_v0_8 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_8 != 0) {
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_8 - 4);
                        }
                        temp_v0_9 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_9 != 0) {
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_9 - 4);
                        }
                        temp_v0_10 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_10 != 0) {
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_10 - 4);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0x3C:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        low19 = scratch2 & 31;
                        savedLow22 = low19;
                        __asm__("" : "=r"(savedLow22) : "0"(savedLow22), "r"(low19));
                        mode17 = (unsigned int)scratch2 >> 5;
                        maskedLow0 = (unsigned char)savedLow22;
                        if ((unsigned int)maskedLow0 >= 28)
                            goto removeRecord;
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        Update96A58func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update96A58Field(recordPlus1, short*, 0x1D);
                        word9 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update96A58Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word9 - scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word9 = frame.saved.doubled78;
                        MATCHING_KEEP(word9);
                        scratch3 += word9;
                        Update96A58Field(recordPlus1, unsigned char*, 9) = scratch3;
                        if (mode17 == 0) {
                            if ((unsigned int)maskedLow0 >= 13) {
                                scratch4 = maskedLow0 - 12;
                                scratch2 = scratch4 << 3;
                                MATCHING_KEEP(raw128);
                                scratch3 = raw128 - scratch2;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80097E04));
                                    scratch3 = 0;
                                }
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                                scratch3 = scratch4 << 2;
                                scratch2 = 64;
                                scratch3 = scratch2 - scratch3;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80097E20));
                                    scratch3 = 0;
                                }
                                goto storeByte12Zero13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch3 = low19 - 4;
                                scratch3 <<= 3;
                                scratch2 = -128;
                                scratch2 -= scratch3;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = raw128;
                                goto storeWordToByte12Zero13;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            MATCHING_KEEP_VOLATILE(raw128);
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = raw128;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80097E58));
                                scratch3 = 0;
                            }
                            goto storeByte13;
                        }
                        word9 = 1;
                        MATCHING_KEEP(raw128);
                        if (mode17 == word9) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80097E90));
                                    scratch3 = 0;
                                }
                                goto storeByte12Zero13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = 0;
                                goto storeWordToByte12Zero13;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80097EC0));
                                scratch3 = 0;
                            }
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        storeByte13:
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                            goto finishByteModes;
                        }
                        if (mode17 == 2) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80097F00));
                                    scratch3 = 0;
                                }
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = 0;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80097F40));
                                scratch3 = 0;
                            }
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            goto storeByte13;
                        }
                        if (mode17 == 3) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80097F7C));
                                    scratch3 = 0;
                                }
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = 0;
                                goto finishByteModes;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = 0;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80097FBC));
                                scratch3 = 0;
                            }
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                            goto finishByteModes;
                        }
                        if (mode17 == 4) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80097FFC));
                                    scratch3 = 0;
                                }
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                                goto storeByte13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = 0;
                            storeWordToBytes12And13:
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                                goto finishByteModes;
                            }
                            scratch2 = savedLow22 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80098030));
                                scratch3 = 0;
                            }
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto finishByteModes;
                        }
                        if (mode17 == 5) {
                            MATCHING_KEEP_VOLATILE(savedLow22);
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80098070));
                                    scratch3 = 0;
                                }
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            storeByte12Zero13:
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch3 = (unsigned char)savedLow22;
                            if ((unsigned int)scratch3 >= 5) {
                                scratch2 = savedLow22 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            storeWordToByte12Zero13:
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = scratch3 << 5;
                            MATCHING_KEEP_VOLATILE(raw128);
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x800980C0));
                                scratch3 = 0;
                            }
                            goto storeByte13;
                        }
                        if (mode17 == 6) {
                            if ((unsigned int)maskedLow0 >= 4) {
                                scratch2 = maskedLow0 << 3;
                                scratch2 -= maskedLow0;
                                scratch3 = 160;
                                scratch3 -= scratch2;
                                scratch2 = (unsigned char)scratch3;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x800980F4));
                                    scratch3 = 0;
                                }
                                scratch2 = (unsigned char)scratch3;
                                scratch2 = (unsigned int)scratch2 >> 1;
                                Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                                scratch2 = (unsigned int)scratch2 >> 1;
                                Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                                Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                                goto finishByteModes;
                            }
                            scratch2 = 160;
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 80;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            scratch2 = 40;
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto finishByteModes;
                        }
                        if (mode17 == 7 && savedLow22 != 0)
                            Update96A58func_80056504(record);
                        goto finishByteModes;
                    finishByteModes:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch3 = savedLow22 + step;
                        scratch2 &= 224;
                        scratch3 |= scratch2;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch3;
                        goto nextRecord;
                    case 0x42:
                        iteration = 0;
                        if (step > 0) {
                            do {
                                if (Update96A58Field(recordPlus1, unsigned char*, 1) & 1) {
                                    scratch2 = Update96A58Field(recordPlus1, unsigned short*, 3);
                                    scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0xF);
                                    scratch3 = Update96A58Field(recordPlus1, unsigned short*, 5);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    temp_a1 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                                    scratch2 += scratch4;
                                    Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                                    scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                                    scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch3 += temp_a1;
                                    Update96A58Field(recordPlus1, unsigned short*, 5) = scratch3;
                                    scratch3 = Update96A58Field(recordPlus1, unsigned char*, 1);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch2 += scratch4;
                                    scratch3 &= 2;
                                    Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                                    if (scratch3 != 0) {
                                        random2 = Update96A58rand();
                                        halfword3 =
                                            Update96A58Field(recordPlus1, unsigned short*, 0xF);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update96A58Field(recordPlus1, unsigned short*, 0xF) =
                                            halfword3;
                                        random2 = Update96A58rand();
                                        halfword3 =
                                            Update96A58Field(recordPlus1, unsigned short*, 0x11);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update96A58Field(recordPlus1, unsigned short*, 0x11) =
                                            halfword3;
                                        random2 = Update96A58rand();
                                        halfword3 =
                                            Update96A58Field(recordPlus1, unsigned short*, 0x13);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update96A58Field(recordPlus1, unsigned short*, 0x13) =
                                            halfword3;
                                    }
                                }
                                iteration += 1;
                                Update96A58Field(recordPlus1, unsigned char*, 1) =
                                    (unsigned char)(Update96A58Field(recordPlus1, unsigned char*,
                                                                     1) +
                                                    1);
                            } while (iteration < step);
                        }
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                    checkMasked24:
                        predicate2 = (unsigned int)scratch2 < 24;
                        goto checkPredicate;
                    checkPredicate:
                        if (predicate2 == 0)
                            goto removeRecord;
                    checkByte2:
                        if (Update96A58Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x46:
                        temp_v0_11 = Update96A58Field(recordPlus1, unsigned char*, 1) + 1;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = temp_v0_11;
                        if (((unsigned int)(temp_v0_11 & 0xFF) < 0x20U) &&
                            (Update96A58Field(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_3 =
                                (int)((short)Update96A58Field(recordPlus1, unsigned short*, 9) -
                                      (short)Update96A58Field(recordPlus1, unsigned short*, 3)) >>
                                1;
                            frame.halves[40] = (unsigned short)temp_a0_3;
                            frame.halves[41] =
                                (unsigned short)((int)((short)Update96A58Field(
                                                           recordPlus1, unsigned short*, 0xB) -
                                                       (short)Update96A58Field(
                                                           recordPlus1, unsigned short*, 5)) >>
                                                 1);
                            frame.halves[42] =
                                (unsigned short)((int)((short)Update96A58Field(
                                                           recordPlus1, unsigned short*, 0xD) -
                                                       (short)Update96A58Field(
                                                           recordPlus1, unsigned short*, 7)) >>
                                                 1);
                            Update96A58Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 3) +
                                                 temp_a0_3);
                            Update96A58Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 5) +
                                                 frame.halves[41]);
                            Update96A58Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 7) +
                                                 frame.halves[42]);
                            random2 = Update96A58rand();
                            halfword3 = frame.halves[40];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[40] = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = frame.halves[41];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[41] = halfword3;
                            if (Update96A58Field(recordPlus1, unsigned char*, 1) & 1) {
                                frame.halves[42] -= 1;
                            }
                            random2 = Update96A58Field(recordPlus1, unsigned short*, 9);
                            halfword3 = frame.halves[40];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update96A58Field(recordPlus1, unsigned short*, 9) = random2;
                            random2 = Update96A58Field(recordPlus1, unsigned short*, 0xB);
                            halfword3 = frame.halves[41];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update96A58Field(recordPlus1, unsigned short*, 0xB) = random2;
                            halfword3 = Update96A58Field(recordPlus1, unsigned short*, 0xD);
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xF);
                            scratch4 = frame.halves[42];
                            MATCHING_KEEP3(halfword3, scratch2, scratch4);
                            scratch2 = scratch2 - 3;
                            halfword3 += scratch4;
                            Update96A58Field(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 &= 255;
                            MATCHING_KEEP2(scratch2, halfword3);
                            Update96A58Field(recordPlus1, unsigned short*, 0xD) = halfword3;
                            if ((unsigned int)scratch2 < 128)
                                Update96A58Field(recordPlus1, unsigned char*, 0xF) = raw128;
                            temp_v0_13 = Update96A58Field(recordPlus1, unsigned char*, 0x10) - 4;
                            Update96A58Field(recordPlus1, unsigned char*, 0x10) = temp_v0_13;
                            if ((unsigned int)(temp_v0_13 & 0xFF) < 0x60U) {
                                Update96A58Field(recordPlus1, unsigned char*, 0x10) = 0x60U;
                            }
                            Update96A58Field(recordPlus1, unsigned char*, 0x11) = 0;
                            temp_v0_14 =
                                (unsigned char)Update96A58Field(recordPlus1, unsigned char*, 0x13) -
                                3;
                            Update96A58Field(recordPlus1, unsigned char*, 0x13) = temp_v0_14;
                            if ((unsigned int)(temp_v0_14 & 0xFF) < 0xC0U) {
                                Update96A58Field(recordPlus1, unsigned char*, 0x13) = 0xC0;
                            }
                            temp_v0_15 = Update96A58Field(recordPlus1, unsigned char*, 0x14) - 4;
                            Update96A58Field(recordPlus1, unsigned char*, 0x14) = temp_v0_15;
                            if ((unsigned int)(temp_v0_15 & 0xFF) < 0x80U) {
                                Update96A58Field(recordPlus1, unsigned char*, 0x14) = raw128;
                            }
                            temp_v0_16 =
                                (unsigned char)Update96A58Field(recordPlus1, unsigned char*, 0x15) -
                                6;
                            Update96A58Field(recordPlus1, unsigned char*, 0x15) = temp_v0_16;
                            if ((unsigned int)(temp_v0_16 & 0xFF) < 0x20U) {
                                Update96A58Field(recordPlus1, unsigned char*, 0x15) = 0x20;
                            }
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x47:
                        temp_v0_17 = Update96A58Field(recordPlus1, unsigned char*, 1) + 1;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = temp_v0_17;
                        if (((unsigned int)(temp_v0_17 & 0xFF) < 0x20U) &&
                            (Update96A58Field(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[22] =
                                (short)Update96A58Field(recordPlus1, unsigned short*, 9) -
                                (short)Update96A58Field(recordPlus1, unsigned short*, 3);
                            frame.words[23] =
                                (short)Update96A58Field(recordPlus1, unsigned short*, 0xB) -
                                (short)Update96A58Field(recordPlus1, unsigned short*, 5);
                            frame.words[24] =
                                (short)Update96A58Field(recordPlus1, unsigned short*, 0xD) -
                                (short)Update96A58Field(recordPlus1, unsigned short*, 7);
                            random2 = Update96A58rand();
                            halfword3 = frame.words[22];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[22] = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = frame.words[23];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[23] = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = frame.words[24];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[24] = halfword3;
                            Update96A58Field(recordPlus1, unsigned short*, 9) =
                                (short)((unsigned short)Update96A58Field(recordPlus1,
                                                                         unsigned short*, 9) +
                                        frame.words[22]);
                            Update96A58Field(recordPlus1, unsigned short*, 0xB) =
                                (short)((unsigned short)Update96A58Field(recordPlus1,
                                                                         unsigned short*, 0xB) +
                                        frame.words[23]);
                            Update96A58Field(recordPlus1, unsigned short*, 0xD) =
                                (short)((unsigned short)Update96A58Field(recordPlus1,
                                                                         unsigned short*, 0xD) +
                                        frame.words[24]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[22];
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 9);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[23];
                            scratch2 = Update96A58Field(recordPlus1, unsigned short*, 0xB);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x13);
                            scratch4 = frame.words[24];
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x15);
                            MATCHING_KEEP3(scratch2, scratch4, scratch3);
                            scratch2 -= 2;
                            Update96A58Field(recordPlus1, unsigned char*, 0x13) = scratch2;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x14);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 4;
                            Update96A58Field(recordPlus1, unsigned char*, 0x15) = scratch3;
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x10);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 2;
                            Update96A58Field(recordPlus1, unsigned char*, 0x14) = scratch2;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xF);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 3;
                            Update96A58Field(recordPlus1, unsigned char*, 0x10) = scratch3;
                            scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0xD);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 3;
                            Update96A58Field(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x11);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= scratch4;
                            Update96A58Field(recordPlus1, unsigned short*, 7) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 3;
                            Update96A58Field(recordPlus1, unsigned char*, 0x11) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x48:
                        temp_v0_18 = Update96A58Field(recordPlus1, unsigned char*, 1) + 1;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = temp_v0_18;
                        if (((unsigned int)(temp_v0_18 & 0xFF) < 0x38U) &&
                            (Update96A58Field(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[20] =
                                (int)((short)Update96A58Field(recordPlus1, unsigned short*, 3) -
                                      (short)Update96A58Field(recordPlus1, unsigned short*, 9)) >>
                                1;
                            frame.words[21] =
                                (int)((short)Update96A58Field(recordPlus1, unsigned short*, 5) -
                                      (short)Update96A58Field(recordPlus1, unsigned short*, 0xB)) >>
                                1;
                            frame.words[22] =
                                (int)((short)Update96A58Field(recordPlus1, unsigned short*, 7) -
                                      (short)Update96A58Field(recordPlus1, unsigned short*, 0xD)) >>
                                1;
                            random2 = Update96A58rand();
                            halfword3 = frame.words[20];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[20] = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = frame.words[21];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[21] = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = frame.words[22];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[22] = halfword3;
                            Update96A58Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 3) +
                                                 frame.words[20]);
                            Update96A58Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 5) +
                                                 frame.words[21]);
                            Update96A58Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 7) +
                                                 frame.words[22]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            Update96A58Field(recordPlus1, unsigned short*, 9) =
                                (short)(Update96A58Field(recordPlus1, unsigned short*, 3) -
                                        (frame.words[20] * 2));
                            Update96A58Field(recordPlus1, unsigned short*, 0xB) =
                                (short)(Update96A58Field(recordPlus1, unsigned short*, 5) -
                                        (frame.words[21] * 2));
                            Update96A58Field(recordPlus1, unsigned short*, 0xD) =
                                (short)(Update96A58Field(recordPlus1, unsigned short*, 7) -
                                        (frame.words[22] * 2));
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4E:
                        temp_v0_19 = Update96A58Field(recordPlus1, unsigned char*, 1) + 1;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = temp_v0_19;
                        if (((unsigned int)(temp_v0_19 & 0xFF) < 0x28U) &&
                            (Update96A58Field(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_4 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                            temp_a1_2 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                            Update96A58Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 3) +
                                                 Update96A58Field(recordPlus1, unsigned short*,
                                                                  0xF));
                            Update96A58Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 5) +
                                                 temp_a0_4);
                            Update96A58Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 7) +
                                                 temp_a1_2);
                            random2 = Update96A58rand();
                            halfword3 = Update96A58Field(recordPlus1, unsigned short*, 0xF);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update96A58Field(recordPlus1, unsigned short*, 0xF) = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update96A58Field(recordPlus1, unsigned short*, 0x11) = halfword3;
                            random2 = Update96A58rand();
                            halfword3 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update96A58Field(recordPlus1, unsigned short*, 0x13) = halfword3;
                            MATCHING_KEEP(halfword3);
                            halfword3 = (short)halfword3;
                            if (halfword3 >= 3)
                                Update96A58Field(recordPlus1, unsigned short*, 0x13) = 2;
                            scratch2 = Update96A58Field(recordPlus1, short*, 0x13);
                            if (scratch2 < -4)
                                Update96A58Field(recordPlus1, short*, 0x13) = -4;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xB);
                            scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0xD);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= 2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0xC);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch3 -= 1;
                            Update96A58Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 2;
                            Update96A58Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4F:
                        temp_a0_5 =
                            (int)((short)Update96A58Field(recordPlus1, unsigned short*, 9) -
                                  (short)Update96A58Field(recordPlus1, unsigned short*, 3)) >>
                            1;
                        frame.halves[40] = (unsigned short)temp_a0_5;
                        frame.halves[41] =
                            (unsigned short)((int)((short)Update96A58Field(recordPlus1,
                                                                           unsigned short*, 0xB) -
                                                   (short)Update96A58Field(recordPlus1,
                                                                           unsigned short*, 5)) >>
                                             1);
                        frame.halves[42] =
                            (unsigned short)((int)((short)Update96A58Field(recordPlus1,
                                                                           unsigned short*, 0xD) -
                                                   (short)Update96A58Field(recordPlus1,
                                                                           unsigned short*, 7)) >>
                                             1);
                        Update96A58Field(recordPlus1, unsigned short*, 3) =
                            (unsigned short)(Update96A58Field(recordPlus1, unsigned short*, 3) +
                                             temp_a0_5);
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[41];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[42];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update96A58Field(recordPlus1, unsigned short*, 7) = scratch2;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        random2 = Update96A58Field(recordPlus1, unsigned short*, 9);
                        halfword3 = frame.halves[40];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update96A58Field(recordPlus1, unsigned short*, 9) = random2;
                        random2 = Update96A58Field(recordPlus1, unsigned short*, 0xB);
                        halfword3 = frame.halves[41];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update96A58Field(recordPlus1, unsigned short*, 0xB) = random2;
                        halfword3 = Update96A58Field(recordPlus1, unsigned short*, 0xD);
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[42];
                        MATCHING_KEEP3(halfword3, scratch2, scratch4);
                        scratch2 = scratch2 + 1;
                        halfword3 += scratch4;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, halfword3);
                        Update96A58Field(recordPlus1, unsigned short*, 0xD) = halfword3;
                        if ((unsigned int)scratch2 >= 24)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 != 0)
                            goto surviving4F;
                        goto removeRecord;
                    surviving4F:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x11);
                        scratch3 = Update96A58Field(recordPlus1, unsigned char*, 0x15);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= 3;
                        Update96A58Field(recordPlus1, unsigned char*, 0x11) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 0x10);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 3;
                        MATCHING_KEEP2(scratch3, scratch2);
                        Update96A58Field(recordPlus1, unsigned char*, 0x15) = scratch3;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 -= 4;
                        Update96A58Field(recordPlus1, unsigned char*, 0x10) = scratch2;
                        temp_v1_10 =
                            (unsigned char)Update96A58Field(recordPlus1, unsigned char*, 0x13);
                        Update96A58Field(recordPlus1, unsigned char*, 0x14) =
                            (unsigned char)(Update96A58Field(recordPlus1, unsigned char*, 0x14) -
                                            4);
                        if (temp_v1_10 >= 6U) {
                            Update96A58Field(recordPlus1, unsigned char*, 0x13) =
                                (signed char)(temp_v1_10 - 6);
                        }
                        goto nextRecord;
                    case 0x54:
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 1);
                        scratch2 += 1;
                        Update96A58Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 8)
                            goto removeRecord;
                        scratch2 = Update96A58Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 != 0)
                            goto surviving54;
                    removeRecord:
                        Update96A58func_80056504(record);
                        recordPlus1 += 32;
                        break;
                    surviving54:
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 3);
                        scratch3 = Update96A58Field(recordPlus1, unsigned short*, 0xF);
                        scratch4 = Update96A58Field(recordPlus1, unsigned short*, 0x11);
                        temp_a1 = Update96A58Field(recordPlus1, unsigned short*, 0x13);
                        MATCHING_KEEP4(scratch2, scratch3, scratch4, temp_a1);
                        scratch2 += scratch3;
                        Update96A58Field(recordPlus1, unsigned short*, 3) = scratch2;
                        scratch2 = Update96A58Field(recordPlus1, unsigned short*, 5);
                        scratch3 = Update96A58Field(recordPlus1, unsigned short*, 7);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch4;
                        scratch3 += temp_a1;
                        Update96A58Field(recordPlus1, unsigned short*, 5) = scratch2;
                        Update96A58Field(recordPlus1, unsigned short*, 7) = scratch3;
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
#undef Update96A58High
#undef Update96A58Field
