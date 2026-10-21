#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI-generated; not human reviewed. Verified update48 and update35 C.
 * Original3987 instructions and dispatch prove selectors32/50/58,
 * raw fields and temporary roles. Helper meanings/units/cadence unresolved.
 * Native and linked original words plus all retail hashes required. */

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Update86A50Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Update86A50func_8004E9E4(short) __asm__("func_8004E9E4");
int Update86A50InterpolateCosine(short) __asm__("func_8004EA2C");
int Update86A50CopyVector(void*, void*) __asm__("func_8004F178");
int Update86A50PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
int Update86A50func_8004F5A8(void*, void*, void*) __asm__("func_8004F5A8");
int Update86A50func_80056504(void*) __asm__("func_80056504");
int Update86A50CountTimerDown(void*, int) __asm__("func_800359A4");
extern int Update86A50D_8006C648 __asm__("D_8006C648");
int Update86A50rand(void) __asm__("rand");
extern unsigned char* Update86A50D_8006C554 __asm__("D_8006C554");
extern int Update86A50D_8006C598 __asm__("D_8006C598");
extern int Update86A50D_8006C640 __asm__("D_8006C640");
extern short Update86A50D_8006E040 __asm__("D_8006E040");
extern int Update86A50D_8006E344 __asm__("D_8006E344");
extern unsigned char Update86A50D_80070328[] __asm__("D_80070328");
extern int Update86A50Player48 __asm__("D_80070328 + 0x48");
extern int Update86A50Player284 __asm__("D_80070328 + 0x284");
extern int Update86A50Player280 __asm__("D_80070328 + 0x280");
#define Update86A50High(a, b)                                                        \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern int (*Update86A50SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
unsigned char* func_level_37_80086A50(int initialStep) {
    register unsigned char* playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$7");
    register int step __asm__("$21");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[12];
        unsigned short halves[24];
    } frame;
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$23");
    int raw128;
    register int doubledStep __asm__("$22");
    register int originalOne7 __asm__("$7");
    int var_a1;
    register int iteration __asm__("$17");
    register int predicate2 __asm__("$2");
    register int random2 __asm__("$2");
    register int halfword3 __asm__("$3");
    register int scratch3 __asm__("$3");
    int temp_v0_14;
    int temp_v0_16;
    unsigned short temp_a0_4;
    register int temp_a1 __asm__("$5");
    unsigned short temp_a1_2;
    register unsigned char* recordPlus1 __asm__("$16");
    register unsigned char* record __asm__("$18");
    register unsigned char* recordPlus4 __asm__("$19");
    register unsigned char* recordPlus24 __asm__("$20");
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
    record = Update86A50D_8006C554;
    incomingStep = initialStep;
    MATCHING_KEEP2(record, incomingStep);
    step = incomingStep;
    MATCHING_KEEP2_CLOBBER(record, step, "$4");
    scratch4 = Update86A50Field(record, unsigned char*, 1);
    MATCHING_KEEP(scratch4);
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2 = 255;
    MATCHING_KEEP(scratch2);
    scratch3 = scratch4 & 255;
    MATCHING_KEEP2(scratch3, scratch4);
    if (scratch3 != scratch2) {
        doubledStep = step * 2;
        MATCHING_KEEP2(step, doubledStep);
        quadrupledStep = step * 4;
        MATCHING_KEEP3(doubledStep, quadrupledStep, step);
        raw128 = 128;
        MATCHING_KEEP(raw128);
        recordPlus1 = record + 1;
        recordPlus24 = record + 0x18;
        recordPlus4 = record + 4;
        MATCHING_KEEP(scratch4);
        scratch3 = scratch4 & 0xFF;
        MATCHING_KEEP2(scratch3, scratch4);
        do {
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            if (scratch3 != 0xFE) {
                if (Update86A50D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update86A50D_8006C598 == 0) {
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
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        originalOne7 = 1;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xC);
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= quadrupledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        MATCHING_KEEP2(predicate2, scratch3);
                        Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x1:
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        originalOne7 = 1;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 += quadrupledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xC);
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= quadrupledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 24;
                        MATCHING_KEEP2(predicate2, scratch3);
                        Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x9:
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        originalOne7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch3 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch2 += step;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        predicate2 = (unsigned int)scratch2 < 32;
                        goto checkPredicate;
                    case 0xA:
                        scratch3 = Update86A50Player48;
                        if (scratch3 == 30 && Update86A50Player280 < 0)
                            goto removeRecord;
                        playerEnd = Update86A50D_80070328 + 0x288;
                        MATCHING_KEEP(playerEnd);
                        if (Update86A50Field(playerEnd, int*, 0) != 0)
                            goto removeRecord;
                        if (Update86A50Player284 == 0)
                            goto removeRecord;
                        Update86A50CopyVector(&frame.words[0], playerEnd - 0x288);
                        scratch2 = Update86A50InterpolateCosine(
                            Update86A50Field(recordPlus1, short*, 0x17));
                        scratch3 = frame.words[0];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 >>= 4;
                        scratch3 += scratch2;
                        frame.words[0] = scratch3;
                        scratch2 =
                            Update86A50func_8004E9E4(Update86A50Field(recordPlus1, short*, 0x17));
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
                        Update86A50PackVectorShiftRight2((void*)scratch4, playerEnd);
                        scratch4 = Update86A50Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 += 64;
                        Update86A50Field(recordPlus1, unsigned short*, 0x17) = scratch4;
                        MATCHING_KEEP(scratch4);
                        scratch4 <<= 16;
                        scratch2 = Update86A50D_8006E040;
                        MATCHING_KEEP2(scratch4, scratch2);
                        scratch4 >>= 16;
                        scratch4 -= scratch2;
                        scratch2 = Update86A50InterpolateCosine(scratch4 & 4095);
                        scratch3 = 0x60606061;
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch2 < 0)
                            scratch2 = -scratch2;
                        MATCHING_KEEP2(scratch2, scratch3);
                        high7 = Update86A50High(scratch2, scratch3);
                        scratch2 >>= 31;
                        MATCHING_KEEP(scratch2);
                        scratch3 = high7 >> 6;
                        scratch3 -= scratch2;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch3;
                        goto nextRecord;
                    case 0xB:
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        scratch4 = (int)recordPlus4;
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x15);
                            scratch2++;
                            Update86A50Field(recordPlus1, unsigned short*, 0x15) = scratch2;
                        }
                        playerEnd = recordPlus4;
                        scratch6 = (int)record + 18;
                        MATCHING_KEEP3(scratch4, playerEnd, scratch6);
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        originalOne7 = 1;
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        Update86A50func_8004F5A8((void*)scratch4, playerEnd, (void*)scratch6);
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xA);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += quadrupledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 0xA) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xC);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 &= 255;
                        MATCHING_KEEP2(scratch3, scratch2);
                        scratch2 -= 4;
                        Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        if (scratch3 == 0)
                            goto removeRecord;
                        goto checkByte2;
                    case 0xC:
                        Update86A50Field(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update86A50Field(recordPlus1, unsigned char*, 0xA) + 8);
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        temp_v0_4 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_4 != 0) {
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_4 - 8);
                        }
                        temp_v0_5 = Update86A50Field(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_5 != 0) {
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_5 - 8);
                        }
                        temp_v0_6 = Update86A50Field(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_6 != 0) {
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_6 - 8);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update86A50Field(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0xD:
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 28)
                            goto removeRecord;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        originalOne7 = 1;
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch2 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if (!(predicate2 = (unsigned int)scratch3 < 13)) {
                            scratch2 = (scratch3 - 12) << 3;
                            scratch2 = raw128 - scratch2;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 64;
                            scratch3 = (scratch3 - 12) << 2;
                            scratch2 -= scratch3;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto zeroDAndAge;
                        } else if (!(predicate2 = (unsigned int)scratch3 < 5)) {
                            scratch2 = -128;
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = 0;
                            scratch3 = (scratch3 - 4) << 3;
                            scratch2 -= scratch3;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto originalAge;
                        } else {
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            scratch2 <<= 5;
                            scratch2 = raw128 - scratch2;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = raw128;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto originalAge;
                        }
                    case 0x20:
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 44)
                            goto removeRecord;
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        originalOne7 = 1;
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch2 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if (!(predicate2 = (unsigned int)scratch3 < 15)) {
                            scratch2 = (scratch3 - 12) << 3;
                            scratch2 = raw128 - scratch2;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 64;
                            scratch3 = (scratch3 - 12) << 2;
                            scratch2 -= scratch3;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            __asm__("" ::: "$3", "memory");
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = 0;
                            goto original32Age;
                        } else if (!(predicate2 = (unsigned int)scratch3 < 5)) {
                            scratch2 = -128;
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = 0;
                            __asm__(""
                                    : "=r"(scratch2), "=r"(scratch3)
                                    : "0"(scratch2), "1"(scratch3)
                                    : "$4", "memory");
                            scratch3 = (scratch3 - 4) << 3;
                            scratch2 -= scratch3;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto original32Age;
                        } else {
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            scratch2 <<= 5;
                            scratch2 = raw128 - scratch2;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = raw128;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                        }
                    original32Age:
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch2 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    case 0x21:
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        originalOne7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch4 = scratch2 - doubledStep;
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 += doubledStep;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        if (scratch4 < 0)
                            scratch4 = 0;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch4;
                        Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch4;
                        Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch4;
                        scratch2 += step;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 32)
                            goto removeRecord;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        if (scratch4 == 0)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x32:
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        if (scratch2 == 0)
                            goto nextRecord;
                        scratch2 = Update86A50D_8006C648;
                        scratch4 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch3 = (scratch2 << 3) - scratch2;
                        scratch4 -= scratch3;
                        if (scratch4 < 0)
                            scratch4 = 0;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch4;
                        if (Update86A50CountTimerDown(record + 2, 1) != 0)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x3A:
                        if ((unsigned int)Update86A50Field(recordPlus1, unsigned char*, 1) >= 28)
                            goto removeRecord;
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update86A50Field(recordPlus1, short*, 0x1D);
                        originalOne7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update86A50Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch2 = originalOne7 - scratch2;
                        Update86A50Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 9);
                        scratch2 += doubledStep;
                        MATCHING_KEEP(scratch3);
                        scratch4 = scratch3 & 255;
                        Update86A50Field(recordPlus1, unsigned char*, 9) = scratch2;
                        if (!(predicate2 = (unsigned int)scratch4 < 13)) {
                            scratch2 = (scratch4 - 12) << 2;
                            scratch3 = 64;
                            scratch3 -= scratch2;
                            if (scratch3 < 0)
                                scratch3 = 0;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            scratch2 = (scratch2 - 12) << 3;
                            scratch3 = raw128 - scratch2;
                            if (scratch3 < 0)
                                scratch3 = 0;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                            goto zeroDAndAge;
                        } else if (!(predicate2 = (unsigned int)scratch4 < 5)) {
                            scratch3 = (scratch3 - 4) << 3;
                            scratch2 = -128;
                            scratch2 -= scratch3;
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = raw128;
                        zeroDAndAge:
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = 0;
                        }
                    originalAge:
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    case 0x3B:
                        Update86A50Field(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update86A50Field(recordPlus1, unsigned char*, 0xA) + 8);
                        Update86A50func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        if (Update86A50D_8006C640 & 1) {
                            Update86A50Field(recordPlus1, unsigned short*, 0x19) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*,
                                                                  0x19) +
                                                 1);
                        }
                        temp_v0_8 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_8 != 0) {
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_8 - 4);
                        }
                        temp_v0_9 = Update86A50Field(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_9 != 0) {
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_9 - 4);
                        }
                        temp_v0_10 = Update86A50Field(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_10 != 0) {
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_10 - 4);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update86A50Field(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0x42:
                        iteration = 0;
                        if (step > 0) {
                            do {
                                if (Update86A50Field(recordPlus1, unsigned char*, 1) & 1) {
                                    scratch2 = Update86A50Field(recordPlus1, unsigned short*, 3);
                                    scratch4 = Update86A50Field(recordPlus1, unsigned short*, 0xF);
                                    scratch3 = Update86A50Field(recordPlus1, unsigned short*, 5);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    temp_a1 = Update86A50Field(recordPlus1, unsigned short*, 0x11);
                                    scratch2 += scratch4;
                                    Update86A50Field(recordPlus1, unsigned short*, 3) = scratch2;
                                    scratch2 = Update86A50Field(recordPlus1, unsigned short*, 7);
                                    scratch4 = Update86A50Field(recordPlus1, unsigned short*, 0x13);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch3 += temp_a1;
                                    Update86A50Field(recordPlus1, unsigned short*, 5) = scratch3;
                                    scratch3 = Update86A50Field(recordPlus1, unsigned char*, 1);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch2 += scratch4;
                                    scratch3 &= 2;
                                    Update86A50Field(recordPlus1, unsigned short*, 7) = scratch2;
                                    if (scratch3 != 0) {
                                        random2 = Update86A50rand();
                                        halfword3 =
                                            Update86A50Field(recordPlus1, unsigned short*, 0xF);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update86A50Field(recordPlus1, unsigned short*, 0xF) =
                                            halfword3;
                                        random2 = Update86A50rand();
                                        halfword3 =
                                            Update86A50Field(recordPlus1, unsigned short*, 0x11);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update86A50Field(recordPlus1, unsigned short*, 0x11) =
                                            halfword3;
                                        random2 = Update86A50rand();
                                        halfword3 =
                                            Update86A50Field(recordPlus1, unsigned short*, 0x13);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update86A50Field(recordPlus1, unsigned short*, 0x13) =
                                            halfword3;
                                    }
                                }
                                iteration += 1;
                                Update86A50Field(recordPlus1, unsigned char*, 1) =
                                    (unsigned char)(Update86A50Field(recordPlus1, unsigned char*,
                                                                     1) +
                                                    1);
                            } while (iteration < step);
                        }
                        predicate2 =
                            (unsigned char)Update86A50Field(recordPlus1, unsigned char*, 1) < 0x18U;
                        goto checkPredicate;
                    checkPredicate:
                        if (predicate2 == 0)
                            goto removeRecord;
                    checkByte2:
                        if (Update86A50Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x46:
                        temp_v0_11 = Update86A50Field(recordPlus1, unsigned char*, 1) + 1;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = temp_v0_11;
                        if (((unsigned int)(temp_v0_11 & 0xFF) < 0x20U) &&
                            (Update86A50Field(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_3 =
                                (int)((short)Update86A50Field(recordPlus1, unsigned short*, 9) -
                                      (short)Update86A50Field(recordPlus1, unsigned short*, 3)) >>
                                1;
                            frame.halves[8] = (unsigned short)temp_a0_3;
                            frame.halves[9] =
                                (unsigned short)((int)((short)Update86A50Field(
                                                           recordPlus1, unsigned short*, 0xB) -
                                                       (short)Update86A50Field(
                                                           recordPlus1, unsigned short*, 5)) >>
                                                 1);
                            frame.halves[10] =
                                (unsigned short)((int)((short)Update86A50Field(
                                                           recordPlus1, unsigned short*, 0xD) -
                                                       (short)Update86A50Field(
                                                           recordPlus1, unsigned short*, 7)) >>
                                                 1);
                            Update86A50Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 3) +
                                                 temp_a0_3);
                            Update86A50Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 5) +
                                                 frame.halves[9]);
                            Update86A50Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 7) +
                                                 frame.halves[10]);
                            random2 = Update86A50rand();
                            halfword3 = frame.halves[8];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[8] = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = frame.halves[9];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[9] = halfword3;
                            if (Update86A50Field(recordPlus1, unsigned char*, 1) & 1) {
                                frame.halves[10] -= 1;
                            }
                            random2 = Update86A50Field(recordPlus1, unsigned short*, 9);
                            halfword3 = frame.halves[8];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update86A50Field(recordPlus1, unsigned short*, 9) = random2;
                            random2 = Update86A50Field(recordPlus1, unsigned short*, 0xB);
                            halfword3 = frame.halves[9];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update86A50Field(recordPlus1, unsigned short*, 0xB) = random2;
                            halfword3 = Update86A50Field(recordPlus1, unsigned short*, 0xD);
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xF);
                            scratch4 = frame.halves[10];
                            MATCHING_KEEP3(halfword3, scratch2, scratch4);
                            scratch2 = scratch2 - 3;
                            halfword3 += scratch4;
                            Update86A50Field(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 &= 255;
                            MATCHING_KEEP2(scratch2, halfword3);
                            Update86A50Field(recordPlus1, unsigned short*, 0xD) = halfword3;
                            if ((unsigned int)scratch2 < 128)
                                Update86A50Field(recordPlus1, unsigned char*, 0xF) = raw128;
                            temp_v0_13 = Update86A50Field(recordPlus1, unsigned char*, 0x10) - 4;
                            Update86A50Field(recordPlus1, unsigned char*, 0x10) = temp_v0_13;
                            if ((unsigned int)(temp_v0_13 & 0xFF) < 0x60U) {
                                Update86A50Field(recordPlus1, unsigned char*, 0x10) = 0x60U;
                            }
                            Update86A50Field(recordPlus1, unsigned char*, 0x11) = 0;
                            temp_v0_14 =
                                (unsigned char)Update86A50Field(recordPlus1, unsigned char*, 0x13) -
                                3;
                            Update86A50Field(recordPlus1, unsigned char*, 0x13) = temp_v0_14;
                            if ((unsigned int)(temp_v0_14 & 0xFF) < 0xC0U) {
                                Update86A50Field(recordPlus1, unsigned char*, 0x13) = 0xC0;
                            }
                            temp_v0_15 = Update86A50Field(recordPlus1, unsigned char*, 0x14) - 4;
                            Update86A50Field(recordPlus1, unsigned char*, 0x14) = temp_v0_15;
                            if ((unsigned int)(temp_v0_15 & 0xFF) < 0x80U) {
                                Update86A50Field(recordPlus1, unsigned char*, 0x14) = raw128;
                            }
                            temp_v0_16 =
                                (unsigned char)Update86A50Field(recordPlus1, unsigned char*, 0x15) -
                                6;
                            Update86A50Field(recordPlus1, unsigned char*, 0x15) = temp_v0_16;
                            if ((unsigned int)(temp_v0_16 & 0xFF) < 0x20U) {
                                Update86A50Field(recordPlus1, unsigned char*, 0x15) = 0x20;
                            }
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x47:
                        temp_v0_17 = Update86A50Field(recordPlus1, unsigned char*, 1) + 1;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = temp_v0_17;
                        if (((unsigned int)(temp_v0_17 & 0xFF) < 0x20U) &&
                            (Update86A50Field(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[6] =
                                (short)Update86A50Field(recordPlus1, unsigned short*, 9) -
                                (short)Update86A50Field(recordPlus1, unsigned short*, 3);
                            frame.words[7] =
                                (short)Update86A50Field(recordPlus1, unsigned short*, 0xB) -
                                (short)Update86A50Field(recordPlus1, unsigned short*, 5);
                            frame.words[8] =
                                (short)Update86A50Field(recordPlus1, unsigned short*, 0xD) -
                                (short)Update86A50Field(recordPlus1, unsigned short*, 7);
                            random2 = Update86A50rand();
                            halfword3 = frame.words[6];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[6] = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = frame.words[7];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[7] = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = frame.words[8];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[8] = halfword3;
                            Update86A50Field(recordPlus1, unsigned short*, 9) =
                                (short)((unsigned short)Update86A50Field(recordPlus1,
                                                                         unsigned short*, 9) +
                                        frame.words[6]);
                            Update86A50Field(recordPlus1, unsigned short*, 0xB) =
                                (short)((unsigned short)Update86A50Field(recordPlus1,
                                                                         unsigned short*, 0xB) +
                                        frame.words[7]);
                            Update86A50Field(recordPlus1, unsigned short*, 0xD) =
                                (short)((unsigned short)Update86A50Field(recordPlus1,
                                                                         unsigned short*, 0xD) +
                                        frame.words[8]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[6];
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 9);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update86A50Field(recordPlus1, unsigned short*, 3) = scratch2;
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[7];
                            scratch2 = Update86A50Field(recordPlus1, unsigned short*, 0xB);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update86A50Field(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0x13);
                            scratch4 = frame.words[8];
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0x15);
                            MATCHING_KEEP3(scratch2, scratch4, scratch3);
                            scratch2 -= 2;
                            Update86A50Field(recordPlus1, unsigned char*, 0x13) = scratch2;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0x14);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 4;
                            Update86A50Field(recordPlus1, unsigned char*, 0x15) = scratch3;
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0x10);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 2;
                            Update86A50Field(recordPlus1, unsigned char*, 0x14) = scratch2;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xF);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 3;
                            Update86A50Field(recordPlus1, unsigned char*, 0x10) = scratch3;
                            scratch3 = Update86A50Field(recordPlus1, unsigned short*, 0xD);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 3;
                            Update86A50Field(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0x11);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= scratch4;
                            Update86A50Field(recordPlus1, unsigned short*, 7) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 3;
                            Update86A50Field(recordPlus1, unsigned char*, 0x11) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x48:
                        temp_v0_18 = Update86A50Field(recordPlus1, unsigned char*, 1) + 1;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = temp_v0_18;
                        if (((unsigned int)(temp_v0_18 & 0xFF) < 0x38U) &&
                            (Update86A50Field(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[4] =
                                (int)((short)Update86A50Field(recordPlus1, unsigned short*, 3) -
                                      (short)Update86A50Field(recordPlus1, unsigned short*, 9)) >>
                                1;
                            frame.words[5] =
                                (int)((short)Update86A50Field(recordPlus1, unsigned short*, 5) -
                                      (short)Update86A50Field(recordPlus1, unsigned short*, 0xB)) >>
                                1;
                            frame.words[6] =
                                (int)((short)Update86A50Field(recordPlus1, unsigned short*, 7) -
                                      (short)Update86A50Field(recordPlus1, unsigned short*, 0xD)) >>
                                1;
                            random2 = Update86A50rand();
                            halfword3 = frame.words[4];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[4] = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = frame.words[5];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[5] = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = frame.words[6];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[6] = halfword3;
                            Update86A50Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 3) +
                                                 frame.words[4]);
                            Update86A50Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 5) +
                                                 frame.words[5]);
                            Update86A50Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 7) +
                                                 frame.words[6]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            Update86A50Field(recordPlus1, unsigned short*, 9) =
                                (short)(Update86A50Field(recordPlus1, unsigned short*, 3) -
                                        (frame.words[4] * 2));
                            Update86A50Field(recordPlus1, unsigned short*, 0xB) =
                                (short)(Update86A50Field(recordPlus1, unsigned short*, 5) -
                                        (frame.words[5] * 2));
                            Update86A50Field(recordPlus1, unsigned short*, 0xD) =
                                (short)(Update86A50Field(recordPlus1, unsigned short*, 7) -
                                        (frame.words[6] * 2));
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4E:
                        temp_v0_19 = Update86A50Field(recordPlus1, unsigned char*, 1) + 1;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = temp_v0_19;
                        if (((unsigned int)(temp_v0_19 & 0xFF) < 0x28U) &&
                            (Update86A50Field(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_4 = Update86A50Field(recordPlus1, unsigned short*, 0x11);
                            temp_a1_2 = Update86A50Field(recordPlus1, unsigned short*, 0x13);
                            Update86A50Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 3) +
                                                 Update86A50Field(recordPlus1, unsigned short*,
                                                                  0xF));
                            Update86A50Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 5) +
                                                 temp_a0_4);
                            Update86A50Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 7) +
                                                 temp_a1_2);
                            random2 = Update86A50rand();
                            halfword3 = Update86A50Field(recordPlus1, unsigned short*, 0xF);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update86A50Field(recordPlus1, unsigned short*, 0xF) = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = Update86A50Field(recordPlus1, unsigned short*, 0x11);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update86A50Field(recordPlus1, unsigned short*, 0x11) = halfword3;
                            random2 = Update86A50rand();
                            halfword3 = Update86A50Field(recordPlus1, unsigned short*, 0x13);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update86A50Field(recordPlus1, unsigned short*, 0x13) = halfword3;
                            MATCHING_KEEP(halfword3);
                            halfword3 = (short)halfword3;
                            if (halfword3 >= 3)
                                Update86A50Field(recordPlus1, unsigned short*, 0x13) = 2;
                            scratch2 = Update86A50Field(recordPlus1, short*, 0x13);
                            if (scratch2 < -4)
                                Update86A50Field(recordPlus1, short*, 0x13) = -4;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xB);
                            scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0xD);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= 2;
                            Update86A50Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0xC);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch3 -= 1;
                            Update86A50Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 2;
                            Update86A50Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4F:
                        temp_a0_5 =
                            (int)((short)Update86A50Field(recordPlus1, unsigned short*, 9) -
                                  (short)Update86A50Field(recordPlus1, unsigned short*, 3)) >>
                            1;
                        frame.halves[8] = (unsigned short)temp_a0_5;
                        frame.halves[9] =
                            (unsigned short)((int)((short)Update86A50Field(recordPlus1,
                                                                           unsigned short*, 0xB) -
                                                   (short)Update86A50Field(recordPlus1,
                                                                           unsigned short*, 5)) >>
                                             1);
                        frame.halves[10] =
                            (unsigned short)((int)((short)Update86A50Field(recordPlus1,
                                                                           unsigned short*, 0xD) -
                                                   (short)Update86A50Field(recordPlus1,
                                                                           unsigned short*, 7)) >>
                                             1);
                        Update86A50Field(recordPlus1, unsigned short*, 3) =
                            (unsigned short)(Update86A50Field(recordPlus1, unsigned short*, 3) +
                                             temp_a0_5);
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[9];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update86A50Field(recordPlus1, unsigned short*, 5) = scratch2;
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update86A50Field(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[10];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update86A50Field(recordPlus1, unsigned short*, 7) = scratch2;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        random2 = Update86A50Field(recordPlus1, unsigned short*, 9);
                        halfword3 = frame.halves[8];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update86A50Field(recordPlus1, unsigned short*, 9) = random2;
                        random2 = Update86A50Field(recordPlus1, unsigned short*, 0xB);
                        halfword3 = frame.halves[9];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update86A50Field(recordPlus1, unsigned short*, 0xB) = random2;
                        halfword3 = Update86A50Field(recordPlus1, unsigned short*, 0xD);
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[10];
                        MATCHING_KEEP3(halfword3, scratch2, scratch4);
                        scratch2 = scratch2 + 1;
                        halfword3 += scratch4;
                        Update86A50Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, halfword3);
                        Update86A50Field(recordPlus1, unsigned short*, 0xD) = halfword3;
                        if ((unsigned int)scratch2 >= 24)
                            goto removeRecord;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 != 0)
                            goto surviving4F;
                    removeRecord:
                        Update86A50func_80056504(record);
                        recordPlus1 += 32;
                        break;
                    surviving4F:
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0x11);
                        scratch3 = Update86A50Field(recordPlus1, unsigned char*, 0x15);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= 3;
                        Update86A50Field(recordPlus1, unsigned char*, 0x11) = scratch2;
                        scratch2 = Update86A50Field(recordPlus1, unsigned char*, 0x10);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 3;
                        MATCHING_KEEP2(scratch3, scratch2);
                        Update86A50Field(recordPlus1, unsigned char*, 0x15) = scratch3;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 -= 4;
                        Update86A50Field(recordPlus1, unsigned char*, 0x10) = scratch2;
                        temp_v1_10 =
                            (unsigned char)Update86A50Field(recordPlus1, unsigned char*, 0x13);
                        Update86A50Field(recordPlus1, unsigned char*, 0x14) =
                            (unsigned char)(Update86A50Field(recordPlus1, unsigned char*, 0x14) -
                                            4);
                        if (temp_v1_10 >= 6U) {
                            Update86A50Field(recordPlus1, unsigned char*, 0x13) =
                                (signed char)(temp_v1_10 - 6);
                        }
                        goto nextRecord;
                    default:
                        goto nextRecord;
                }
            } else {
            nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus24 += 0x20;
            recordPlus4 += 0x20;
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
