#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Update81ADCExpandUnsignedHalfwordVectorTimes4(void*, void*) __asm__("func_8004F52C");
int Update81ADCExpandSignedHalfwordVector(void*, void*) __asm__("func_8004F554");
int Update81ADCAddVector(void*, void*, void*) __asm__("func_8004F194");
int Update81ADCSubtractVector(void*, void*, void*) __asm__("func_8004F1C8");
extern unsigned char Update81ADCD_8006E020[] __asm__("D_8006E020");
#define Update81ADCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Update81ADCInterpolateSine(short) __asm__("func_8004E9E4");
int Update81ADCInterpolateCosine(short) __asm__("func_8004EA2C");
int Update81ADCCopyVector(void*, void*) __asm__("func_8004F178");
int Update81ADCPackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
int Update81ADCAddHalfwordVectors(void*, void*, void*) __asm__("func_8004F5A8");
int Update81ADCReleaseParticleRecord(void*) __asm__("func_80056504");
int Update81ADCInterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
int Update81ADCShiftVectorRightTowardZero(void*, int) __asm__("func_8004F110");
extern unsigned char* Update81ADCD_8006C550 __asm__("D_8006C550");
int Update81ADCrand(void) __asm__("rand");
extern unsigned char* Update81ADCD_8006C554 __asm__("D_8006C554");
extern int Update81ADCD_8006C598 __asm__("D_8006C598");
extern int Update81ADCD_8006C640 __asm__("D_8006C640");
extern short Update81ADCD_8006E040 __asm__("D_8006E040");
extern int Update81ADCD_8006E344 __asm__("D_8006E344");
extern unsigned char Update81ADCD_80070328[] __asm__("D_80070328");
extern int Update81ADCPlayer48 __asm__("D_80070328 + 0x48");
extern int Update81ADCPlayer284 __asm__("D_80070328 + 0x284");
extern int Update81ADCPlayer280 __asm__("D_80070328 + 0x280");
#define Update81ADCHigh(a, b)                                                        \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
extern int (*Update81ADCSpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
unsigned char* func_level_36_80081ADC(int initialStep) {
    register unsigned char* playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$8");
    register int step __asm__("$23");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[32];
        unsigned short halves[64];
    } frame;
    register int savedAge21 __asm__("$17");
    int temp_a0_3;
    int temp_a0_5;
    register int quadrupledStep __asm__("$22");
    int doubledStep;
    register void* vector16 __asm__("$16");
    register void* vector17 __asm__("$17");
    register int var_a1 __asm__("$4");
    register int rawOne __asm__("$8");
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
    register unsigned char* record __asm__("$19");
    register unsigned char* recordPlus4 __asm__("$20");
    register unsigned char* recordPlus24 __asm__("$21");
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
    record = Update81ADCD_8006C554;
    incomingStep = initialStep;
    MATCHING_KEEP2(record, incomingStep);
    step = incomingStep;
    MATCHING_KEEP2_CLOBBER(record, step, "$4");
    scratch4 = Update81ADCField(record, unsigned char*, 1);
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
        recordPlus1 = record + 1;
        recordPlus24 = record + 0x18;
        recordPlus4 = record + 4;
        MATCHING_KEEP(scratch4);
        scratch3 = scratch4 & 0xFF;
        MATCHING_KEEP2(scratch3, scratch4);
        do {
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            if (scratch3 != 0xFE) {
                if (Update81ADCD_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update81ADCD_8006C598 == 0) {
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
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update81ADCField(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        if (scratch2 != 0) {
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update81ADCField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        rawOne = 1;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 += doubledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        scratch2 = rawOne - scratch2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= quadrupledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        MATCHING_KEEP2(predicate2, scratch3);
                        Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x1:
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update81ADCField(recordPlus1, short*, 0x1D);
                        __asm__ __volatile__("" ::: "$3", "memory");
                        if (scratch2 != 0) {
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update81ADCField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        rawOne = 1;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 += quadrupledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        scratch2 = rawOne - scratch2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= quadrupledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= quadrupledStep;
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 24;
                        MATCHING_KEEP2(predicate2, scratch3);
                        Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x2:
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        if (Update81ADCField(recordPlus1, short*, 0x1D) != 0)
                            Update81ADCField(recordPlus1, unsigned short*, 0x1B) =
                                Update81ADCField(recordPlus1, unsigned short*, 0x1B) + 1;
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "$8", "memory");
                        rawOne = 1;
                        scratch2 = rawOne - scratch2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += doubledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                        predicate2 = scratch3 < quadrupledStep;
                        if (!predicate2) {
                            scratch2 = scratch3 - quadrupledStep;
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        } else
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) = 0;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        predicate2 = scratch3 < quadrupledStep;
                        if (!predicate2) {
                            scratch2 = scratch3 - quadrupledStep;
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        } else
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) = 0;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        predicate2 = scratch3 < quadrupledStep;
                        if (!predicate2) {
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(step, "memory");
                            scratch2 = scratch3 - quadrupledStep;
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch2;
                        } else
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = 0;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$3", "memory");
                        predicate2 = (unsigned int)scratch2 < 32;
                        goto checkPredicate;
                    case 0x3:
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update81ADCField(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update81ADCField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        rawOne = 1;
                        MATCHING_KEEP(rawOne);
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        scratch4 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch4);
                        scratch2 = rawOne - scratch2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += 3;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                        if (scratch3 == scratch4) {
                            scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                            scratch2 = scratch4 - 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            scratch3 -= 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch3;
                        } else {
                            scratch2 = scratch4 + 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch2;
                        }
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        scratch2 -= 4;
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 &= 255;
                        __asm__ volatile("" : "=r"(scratch2) : "0"(scratch2) : "$3", "memory");
                        if (scratch2 == 0)
                            goto removeRecord;
                        __asm__ volatile("" ::: "$3", "memory");
                        goto checkByte2;
                    case 0x5:
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 48)
                            goto removeRecord;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        Update81ADCExpandUnsignedHalfwordVectorTimes4(&frame.words[0], recordPlus4);
                        random2 = Update81ADCrand();
                        halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0x17);
                        MATCHING_KEEP2(random2, halfword3);
                        random2 &= 6;
                        halfword3 -= 3;
                        halfword3 += random2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x17) = halfword3;
                        random2 = Update81ADCrand();
                        vector16 = &frame.words[4];
                        scratch4 = (int)vector16;
                        playerEnd = recordPlus24;
                        MATCHING_KEEP2(scratch4, playerEnd);
                        random2 &= 6;
                        halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0x19);
                        scratch6 = Update81ADCField(recordPlus1, unsigned short*, 0x1B);
                        MATCHING_KEEP3(random2, halfword3, scratch6);
                        halfword3 -= 3;
                        halfword3 += random2;
                        scratch6 -= 1;
                        Update81ADCField(recordPlus1, unsigned short*, 0x19) = halfword3;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1B) = scratch6;
                        Update81ADCExpandSignedHalfwordVector((void*)scratch4, playerEnd);
                        Update81ADCShiftVectorRightTowardZero(vector16, 2);
                        Update81ADCAddVector(&frame.words[0], &frame.words[0], vector16);
                        Update81ADCPackVectorShiftRight2(recordPlus4, &frame.words[0]);
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch2 += 1;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    case 0x9:
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update81ADCField(recordPlus1, short*, 0x1D);
                        if (scratch2 != 0) {
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update81ADCField(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        rawOne = 1;
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        scratch2 = rawOne - scratch2;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch3 += doubledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        goto checkPredicate;
                    case 0xA:
                        scratch3 = Update81ADCPlayer48;
                        if (scratch3 == 30 && Update81ADCPlayer280 < 0)
                            goto removeRecord;
                        playerEnd = Update81ADCD_80070328 + 0x288;
                        MATCHING_KEEP(playerEnd);
                        if (Update81ADCField(playerEnd, int*, 0) != 0)
                            goto removeRecord;
                        if (Update81ADCPlayer284 == 0)
                            goto removeRecord;
                        vector16 = &frame.words[8];
                        Update81ADCCopyVector(vector16, playerEnd - 0x288);
                        scratch2 = Update81ADCInterpolateCosine(
                            Update81ADCField(recordPlus1, short*, 0x17));
                        scratch3 = frame.words[8];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 >>= 4;
                        scratch3 += scratch2;
                        frame.words[8] = scratch3;
                        scratch2 =
                            Update81ADCInterpolateSine(Update81ADCField(recordPlus1, short*, 0x17));
                        scratch4 = (int)recordPlus4;
                        playerEnd = (unsigned char*)vector16;
                        MATCHING_KEEP3(scratch4, playerEnd, scratch2);
                        scratch2 >>= 4;
                        scratch3 = frame.words[9];
                        scratch6 = frame.words[10];
                        MATCHING_KEEP3(scratch2, scratch3, scratch6);
                        scratch3 += scratch2;
                        scratch6 += 256;
                        frame.words[9] = scratch3;
                        frame.words[10] = scratch6;
                        MATCHING_KEEP(scratch6);
                        Update81ADCPackVectorShiftRight2((void*)scratch4, playerEnd);
                        scratch4 = Update81ADCField(recordPlus1, unsigned short*, 0x17);
                        scratch4 += 64;
                        Update81ADCField(recordPlus1, unsigned short*, 0x17) = scratch4;
                        MATCHING_KEEP(scratch4);
                        scratch4 <<= 16;
                        scratch2 = Update81ADCD_8006E040;
                        MATCHING_KEEP2(scratch4, scratch2);
                        scratch4 >>= 16;
                        scratch4 -= scratch2;
                        scratch2 = Update81ADCInterpolateCosine(scratch4 & 4095);
                        scratch3 = 0x60606061;
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch2 < 0)
                            scratch2 = -scratch2;
                        MATCHING_KEEP2(scratch2, scratch3);
                        high7 = Update81ADCHigh(scratch2, scratch3);
                        scratch2 >>= 31;
                        MATCHING_KEEP(scratch2);
                        scratch3 = high7 >> 6;
                        scratch3 -= scratch2;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch3;
                        goto nextRecord;
                    case 0xB:
                        scratch2 = Update81ADCField(recordPlus1, short*, 0x1D);
                        scratch4 = (int)recordPlus4;
                        if (scratch2 != 0) {
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x15);
                            scratch2++;
                            Update81ADCField(recordPlus1, unsigned short*, 0x15) = scratch2;
                        }
                        playerEnd = recordPlus4;
                        scratch6 = (int)record + 18;
                        MATCHING_KEEP3(scratch4, playerEnd, scratch6);
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP_CLOBBER(scratch2, "$8");
                        rawOne = 1;
                        scratch2 = rawOne - scratch2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        Update81ADCAddHalfwordVectors((void*)scratch4, playerEnd, (void*)scratch6);
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += doubledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xA);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += quadrupledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 0xA) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 &= 255;
                        MATCHING_KEEP2(scratch3, scratch2);
                        scratch2 -= 4;
                        Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        if (scratch3 == 0)
                            goto removeRecord;
                        goto checkByte2;
                    case 0xC:
                        Update81ADCField(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update81ADCField(recordPlus1, unsigned char*, 0xA) + 8);
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        temp_v0_4 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_4 != 0) {
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_4 - 8);
                        }
                        temp_v0_5 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_5 != 0) {
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_5 - 8);
                        }
                        temp_v0_6 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_6 != 0) {
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_6 - 8);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update81ADCField(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0xF:
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch2 >= 48)
                            goto removeRecord;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        vector17 = &frame.words[12];
                        Update81ADCExpandUnsignedHalfwordVectorTimes4(vector17, recordPlus4);
                        random2 = Update81ADCrand();
                        halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0x17);
                        MATCHING_KEEP2(random2, halfword3);
                        random2 &= 6;
                        halfword3 -= 3;
                        halfword3 += random2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x17) = halfword3;
                        random2 = Update81ADCrand();
                        vector16 = &frame.words[16];
                        scratch4 = (int)vector16;
                        playerEnd = recordPlus24;
                        MATCHING_KEEP2(scratch4, playerEnd);
                        random2 &= 6;
                        halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0x19);
                        scratch6 = Update81ADCField(recordPlus1, unsigned short*, 0x1B);
                        MATCHING_KEEP3(random2, halfword3, scratch6);
                        halfword3 -= 3;
                        halfword3 += random2;
                        scratch6 -= 1;
                        Update81ADCField(recordPlus1, unsigned short*, 0x19) = halfword3;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1B) = scratch6;
                        Update81ADCExpandSignedHalfwordVector((void*)scratch4, playerEnd);

                        Update81ADCAddVector(vector17, vector17, vector16);
                        Update81ADCPackVectorShiftRight2(recordPlus4, vector17);
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch2 += 1;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        Update81ADCSubtractVector(vector16, vector17, Update81ADCD_8006E020);
                        scratch4 = frame.words[16];
                        scratch3 = frame.words[17];
                        scratch2 = frame.words[18];
                        MATCHING_KEEP3(scratch4, scratch3, scratch2);
                        if (scratch4 < 0)
                            scratch4 = -scratch4;
                        if (scratch3 < 0)
                            scratch3 = -scratch3;
                        scratch4 += scratch3;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(scratch4, scratch2, "memory");
                        if (scratch2 < 0)
                            scratch2 = -scratch2;
                        scratch4 += scratch2;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0);
                        scratch2 = 3;
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch3 == scratch2) {
                            predicate2 = scratch4 < 0x3001;
                            MATCHING_KEEP(predicate2);
                            if (predicate2)
                                goto nextRecord;
                            scratch2 = 255;
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            scratch2 = 4;
                            Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                            Update81ADCField(recordPlus1, unsigned char*, 0) = 0;
                            Update81ADCField(recordPlus1, unsigned char*, 0xE) = 64;
                        } else {
                            predicate2 = scratch4 < 0x2800;
                            MATCHING_KEEP(predicate2);
                            if (!predicate2)
                                goto nextRecord;
                            scratch2 = 3;
                            Update81ADCField(recordPlus1, unsigned char*, 0) = scratch2;
                            scratch2 = 128;
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch2;
                            scratch2 = 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0x10) = scratch2;
                            scratch2 = 44;
                            Update81ADCField(recordPlus1, unsigned char*, 0xE) = scratch2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xF) = 0;
                            scratch2 = Update81ADCrand();
                            scratch4 = scratch2 & 7;
                            scratch2 = scratch4 + 18;
                            Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                            scratch2 = scratch4 + 15;
                            Update81ADCField(recordPlus1, unsigned char*, 0xA) = scratch2;
                        }
                        goto nextRecord;
                    case 0x21:
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        if (Update81ADCField(recordPlus1, short*, 0x1D) != 0) {
                            Update81ADCField(recordPlus1, unsigned short*, 0x1B) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*,
                                                                  0x1B) +
                                                 1);
                        }
                        rawOne = 1;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        MATCHING_KEEP2(scratch2, scratch3);
                        var_a1 = scratch2 - doubledStep;
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP2(scratch2, var_a1);
                        scratch3 += doubledStep;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch3;
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 = rawOne - scratch2;
                        Update81ADCField(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        if (var_a1 < 0) {
                            var_a1 = 0;
                        }
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = (unsigned char)var_a1;
                        Update81ADCField(recordPlus1, unsigned char*, 0xC) = (unsigned char)var_a1;
                        Update81ADCField(recordPlus1, unsigned char*, 0xD) = (unsigned char)var_a1;
                        temp_v0_7 = Update81ADCField(recordPlus1, unsigned char*, 1) + step;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = temp_v0_7;
                        if (((unsigned int)(temp_v0_7 & 0xFF) < 0x20U) &&
                            (Update81ADCField(recordPlus1, unsigned char*, 2) != 0) &&
                            (var_a1 != 0)) {
                            recordPlus1 += 0x20;
                        } else {
                            goto removeRecord;
                        }
                        break;
                    case 0x25:
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch3 = scratch2 + step;
                        MATCHING_KEEP2(scratch2, scratch3);
                        savedAge21 = scratch2 & 255;
                        MATCHING_KEEP2(savedAge21, scratch3);
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch3;
                        scratch3 &= 255;
                        predicate2 = (unsigned int)scratch3 < 49;
                        if (!predicate2)
                            goto removeRecord;
                        if ((unsigned int)scratch3 < 16) {
                            register int product8 __asm__("$8");
                            register void* temporary16 __asm__("$16");
                            temp_a1 = 0;
                            __asm__("" : "=r"(temp_a1) : "0"(temp_a1) : "$4", "memory");
                            scratch2 = Update81ADCField(recordPlus1, short*, 0x17);
                            product8 = scratch2 * scratch3;
                            MATCHING_KEEP(product8);
                            scratch2 = product8 >> 1;
                            frame.halves[40] = scratch2;
                            scratch3 = Update81ADCField(recordPlus1, short*, 0x19);
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                            product8 = scratch3 * scratch2;
                            MATCHING_KEEP(product8);
                            scratch2 = product8 >> 1;
                            frame.halves[41] = scratch2;
                            scratch3 = Update81ADCField(recordPlus1, short*, 0x1B);
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                            product8 = scratch3 * scratch2;
                            temporary16 = &frame.words[22];
                            MATCHING_KEEP2(product8, temporary16);
                            scratch2 = product8 >> 1;
                            frame.halves[42] = scratch2;
                            scratch2 = Update81ADCField(recordPlus1, short*, 0x1D);
                            scratch4 = scratch2 * 88;
                            scratch2 = (int)Update81ADCD_8006C550;
                            Update81ADCInterpolateMobyVertex((void*)(scratch2 + scratch4), temp_a1,
                                                             temporary16);
                            Update81ADCShiftVectorRightTowardZero(temporary16, 2);
                            scratch3 = frame.words[22];
                            scratch2 = frame.halves[40];
                            scratch2 += scratch3;
                            Update81ADCField(recordPlus1, unsigned short*, 3) = scratch2;
                            scratch3 = frame.words[23];
                            scratch2 = frame.halves[41];
                            scratch2 += scratch3;
                            Update81ADCField(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch3 = frame.words[24];
                            scratch2 = frame.halves[42];
                            scratch2 += scratch3;
                            Update81ADCField(recordPlus1, unsigned short*, 7) = scratch2;
                            goto original25Tail;
                        }
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                    original25Tail:
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        if ((unsigned int)scratch2 >= 129) {
                            scratch2 = 128;
                            Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                        }
                        __asm__("" ::: "$2", "memory");
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch3 < 17) {
                            scratch2 = 256;
                            goto addedEarlyAge;
                        }
                        predicate2 = savedAge21 < 17;
                        MATCHING_KEEP(predicate2);
                        if (predicate2)
                            Update81ADCSpawnParticle(1, 56, record, 0);
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch2 -= 16;
                        scratch3 = scratch2 * 8;
                        scratch2 = 256;
                        scratch3 = scratch2 - scratch3;
                        if (scratch3 >= 256)
                            scratch3 = 255;
                        if (scratch3 < 0)
                            scratch3 = 0;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 >>= 1;
                        if (scratch3 >= scratch2)
                            goto nextRecord;
                    addedStoreByteC:
                        MATCHING_KEEP_VOLATILE_CLOBBER(scratch3, "memory");
                        Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch3;
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
                    case 0x38:
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        if ((unsigned int)scratch2 >= 49)
                            goto removeRecord;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 9);
                        scratch2 += step;
                        Update81ADCField(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        if ((unsigned int)scratch2 >= 129)
                            Update81ADCField(recordPlus1, unsigned char*, 9) = 128;
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        if ((unsigned int)scratch3 < 16)
                            scratch2 = scratch3 << 2;
                        else
                            scratch2 = (48 - scratch3) << 1;
                        if (scratch2 <= 0)
                            goto removeRecord;
                        Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                        Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch2;
                        Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch2;
                        goto nextRecord;
                    case 0x3B:
                        Update81ADCField(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update81ADCField(recordPlus1, unsigned char*, 0xA) + 8);
                        Update81ADCAddHalfwordVectors(recordPlus4, recordPlus4, recordPlus24);
                        if (Update81ADCD_8006C640 & 1) {
                            Update81ADCField(recordPlus1, unsigned short*, 0x19) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*,
                                                                  0x19) +
                                                 1);
                        }
                        temp_v0_8 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_8 != 0) {
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_8 - 4);
                        }
                        temp_v0_9 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_9 != 0) {
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_9 - 4);
                        }
                        temp_v0_10 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_10 != 0) {
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_10 - 4);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update81ADCField(recordPlus1, unsigned int*, 0xB);
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
                                if (Update81ADCField(recordPlus1, unsigned char*, 1) & 1) {
                                    scratch2 = Update81ADCField(recordPlus1, unsigned short*, 3);
                                    scratch4 = Update81ADCField(recordPlus1, unsigned short*, 0xF);
                                    scratch3 = Update81ADCField(recordPlus1, unsigned short*, 5);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    temp_a1 = Update81ADCField(recordPlus1, unsigned short*, 0x11);
                                    scratch2 += scratch4;
                                    Update81ADCField(recordPlus1, unsigned short*, 3) = scratch2;
                                    scratch2 = Update81ADCField(recordPlus1, unsigned short*, 7);
                                    scratch4 = Update81ADCField(recordPlus1, unsigned short*, 0x13);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch3 += temp_a1;
                                    Update81ADCField(recordPlus1, unsigned short*, 5) = scratch3;
                                    scratch3 = Update81ADCField(recordPlus1, unsigned char*, 1);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch2 += scratch4;
                                    scratch3 &= 2;
                                    Update81ADCField(recordPlus1, unsigned short*, 7) = scratch2;
                                    if (scratch3 != 0) {
                                        random2 = Update81ADCrand();
                                        halfword3 =
                                            Update81ADCField(recordPlus1, unsigned short*, 0xF);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update81ADCField(recordPlus1, unsigned short*, 0xF) =
                                            halfword3;
                                        random2 = Update81ADCrand();
                                        halfword3 =
                                            Update81ADCField(recordPlus1, unsigned short*, 0x11);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update81ADCField(recordPlus1, unsigned short*, 0x11) =
                                            halfword3;
                                        random2 = Update81ADCrand();
                                        halfword3 =
                                            Update81ADCField(recordPlus1, unsigned short*, 0x13);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update81ADCField(recordPlus1, unsigned short*, 0x13) =
                                            halfword3;
                                    }
                                }
                                iteration += 1;
                                Update81ADCField(recordPlus1, unsigned char*, 1) =
                                    (unsigned char)(Update81ADCField(recordPlus1, unsigned char*,
                                                                     1) +
                                                    1);
                            } while (iteration < step);
                        }
                        predicate2 =
                            (unsigned char)Update81ADCField(recordPlus1, unsigned char*, 1) < 0x18U;
                        goto checkPredicate;
                    checkPredicate:
                        if (predicate2 == 0)
                            goto removeRecord;
                    checkByte2:
                        if (Update81ADCField(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x46:
                        temp_v0_11 = Update81ADCField(recordPlus1, unsigned char*, 1) + 1;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = temp_v0_11;
                        if (((unsigned int)(temp_v0_11 & 0xFF) < 0x20U) &&
                            (Update81ADCField(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_3 =
                                (int)((short)Update81ADCField(recordPlus1, unsigned short*, 9) -
                                      (short)Update81ADCField(recordPlus1, unsigned short*, 3)) >>
                                1;
                            frame.halves[40] = (unsigned short)temp_a0_3;
                            frame.halves[41] =
                                (unsigned short)((int)((short)Update81ADCField(
                                                           recordPlus1, unsigned short*, 0xB) -
                                                       (short)Update81ADCField(
                                                           recordPlus1, unsigned short*, 5)) >>
                                                 1);
                            frame.halves[42] =
                                (unsigned short)((int)((short)Update81ADCField(
                                                           recordPlus1, unsigned short*, 0xD) -
                                                       (short)Update81ADCField(
                                                           recordPlus1, unsigned short*, 7)) >>
                                                 1);
                            Update81ADCField(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 3) +
                                                 temp_a0_3);
                            Update81ADCField(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 5) +
                                                 frame.halves[41]);
                            Update81ADCField(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 7) +
                                                 frame.halves[42]);
                            random2 = Update81ADCrand();
                            halfword3 = frame.halves[40];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[40] = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = frame.halves[41];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[41] = halfword3;
                            if (Update81ADCField(recordPlus1, unsigned char*, 1) & 1) {
                                frame.halves[42] -= 1;
                            }
                            random2 = Update81ADCField(recordPlus1, unsigned short*, 9);
                            halfword3 = frame.halves[40];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update81ADCField(recordPlus1, unsigned short*, 9) = random2;
                            random2 = Update81ADCField(recordPlus1, unsigned short*, 0xB);
                            halfword3 = frame.halves[41];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update81ADCField(recordPlus1, unsigned short*, 0xB) = random2;
                            halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0xD);
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xF);
                            scratch4 = frame.halves[42];
                            MATCHING_KEEP3(halfword3, scratch2, scratch4);
                            scratch2 = scratch2 - 3;
                            halfword3 += scratch4;
                            Update81ADCField(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 &= 255;
                            MATCHING_KEEP2(scratch2, halfword3);
                            Update81ADCField(recordPlus1, unsigned short*, 0xD) = halfword3;
                            if ((unsigned int)scratch2 < 128)
                                Update81ADCField(recordPlus1, unsigned char*, 0xF) = 128;
                            temp_v0_13 = Update81ADCField(recordPlus1, unsigned char*, 0x10) - 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0x10) = temp_v0_13;
                            if ((unsigned int)(temp_v0_13 & 0xFF) < 0x60U) {
                                Update81ADCField(recordPlus1, unsigned char*, 0x10) = 0x60U;
                            }
                            Update81ADCField(recordPlus1, unsigned char*, 0x11) = 0;
                            temp_v0_14 =
                                (unsigned char)Update81ADCField(recordPlus1, unsigned char*, 0x13) -
                                3;
                            Update81ADCField(recordPlus1, unsigned char*, 0x13) = temp_v0_14;
                            if ((unsigned int)(temp_v0_14 & 0xFF) < 0xC0U) {
                                Update81ADCField(recordPlus1, unsigned char*, 0x13) = 0xC0;
                            }
                            temp_v0_15 = Update81ADCField(recordPlus1, unsigned char*, 0x14) - 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0x14) = temp_v0_15;
                            if ((unsigned int)(temp_v0_15 & 0xFF) < 0x80U) {
                                Update81ADCField(recordPlus1, unsigned char*, 0x14) = 128;
                            }
                            temp_v0_16 =
                                (unsigned char)Update81ADCField(recordPlus1, unsigned char*, 0x15) -
                                6;
                            Update81ADCField(recordPlus1, unsigned char*, 0x15) = temp_v0_16;
                            if ((unsigned int)(temp_v0_16 & 0xFF) < 0x20U) {
                                Update81ADCField(recordPlus1, unsigned char*, 0x15) = 0x20;
                            }
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x47:
                        temp_v0_17 = Update81ADCField(recordPlus1, unsigned char*, 1) + 1;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = temp_v0_17;
                        if (((unsigned int)(temp_v0_17 & 0xFF) < 0x20U) &&
                            (Update81ADCField(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[26] =
                                (short)Update81ADCField(recordPlus1, unsigned short*, 9) -
                                (short)Update81ADCField(recordPlus1, unsigned short*, 3);
                            frame.words[27] =
                                (short)Update81ADCField(recordPlus1, unsigned short*, 0xB) -
                                (short)Update81ADCField(recordPlus1, unsigned short*, 5);
                            frame.words[28] =
                                (short)Update81ADCField(recordPlus1, unsigned short*, 0xD) -
                                (short)Update81ADCField(recordPlus1, unsigned short*, 7);
                            random2 = Update81ADCrand();
                            halfword3 = frame.words[26];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[26] = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = frame.words[27];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[27] = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = frame.words[28];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[28] = halfword3;
                            Update81ADCField(recordPlus1, unsigned short*, 9) =
                                (short)((unsigned short)Update81ADCField(recordPlus1,
                                                                         unsigned short*, 9) +
                                        frame.words[26]);
                            Update81ADCField(recordPlus1, unsigned short*, 0xB) =
                                (short)((unsigned short)Update81ADCField(recordPlus1,
                                                                         unsigned short*, 0xB) +
                                        frame.words[27]);
                            Update81ADCField(recordPlus1, unsigned short*, 0xD) =
                                (short)((unsigned short)Update81ADCField(recordPlus1,
                                                                         unsigned short*, 0xD) +
                                        frame.words[28]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[26];
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 9);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update81ADCField(recordPlus1, unsigned short*, 3) = scratch2;
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[27];
                            scratch2 = Update81ADCField(recordPlus1, unsigned short*, 0xB);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update81ADCField(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0x13);
                            scratch4 = frame.words[28];
                            scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0x15);
                            MATCHING_KEEP3(scratch2, scratch4, scratch3);
                            scratch2 -= 2;
                            Update81ADCField(recordPlus1, unsigned char*, 0x13) = scratch2;
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0x14);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 4;
                            Update81ADCField(recordPlus1, unsigned char*, 0x15) = scratch3;
                            scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0x10);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 2;
                            Update81ADCField(recordPlus1, unsigned char*, 0x14) = scratch2;
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xF);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 3;
                            Update81ADCField(recordPlus1, unsigned char*, 0x10) = scratch3;
                            scratch3 = Update81ADCField(recordPlus1, unsigned short*, 0xD);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 3;
                            Update81ADCField(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0x11);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= scratch4;
                            Update81ADCField(recordPlus1, unsigned short*, 7) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 3;
                            Update81ADCField(recordPlus1, unsigned char*, 0x11) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x48:
                        temp_v0_18 = Update81ADCField(recordPlus1, unsigned char*, 1) + 1;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = temp_v0_18;
                        if (((unsigned int)(temp_v0_18 & 0xFF) < 0x38U) &&
                            (Update81ADCField(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[26] =
                                (int)((short)Update81ADCField(recordPlus1, unsigned short*, 3) -
                                      (short)Update81ADCField(recordPlus1, unsigned short*, 9)) >>
                                1;
                            frame.words[27] =
                                (int)((short)Update81ADCField(recordPlus1, unsigned short*, 5) -
                                      (short)Update81ADCField(recordPlus1, unsigned short*, 0xB)) >>
                                1;
                            frame.words[28] =
                                (int)((short)Update81ADCField(recordPlus1, unsigned short*, 7) -
                                      (short)Update81ADCField(recordPlus1, unsigned short*, 0xD)) >>
                                1;
                            random2 = Update81ADCrand();
                            halfword3 = frame.words[26];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[26] = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = frame.words[27];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[27] = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = frame.words[28];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[28] = halfword3;
                            Update81ADCField(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 3) +
                                                 frame.words[26]);
                            Update81ADCField(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 5) +
                                                 frame.words[27]);
                            Update81ADCField(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 7) +
                                                 frame.words[28]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            Update81ADCField(recordPlus1, unsigned short*, 9) =
                                (short)(Update81ADCField(recordPlus1, unsigned short*, 3) -
                                        (frame.words[26] * 2));
                            Update81ADCField(recordPlus1, unsigned short*, 0xB) =
                                (short)(Update81ADCField(recordPlus1, unsigned short*, 5) -
                                        (frame.words[27] * 2));
                            Update81ADCField(recordPlus1, unsigned short*, 0xD) =
                                (short)(Update81ADCField(recordPlus1, unsigned short*, 7) -
                                        (frame.words[28] * 2));
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4E:
                        temp_v0_19 = Update81ADCField(recordPlus1, unsigned char*, 1) + 1;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = temp_v0_19;
                        if (((unsigned int)(temp_v0_19 & 0xFF) < 0x28U) &&
                            (Update81ADCField(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_4 = Update81ADCField(recordPlus1, unsigned short*, 0x11);
                            temp_a1_2 = Update81ADCField(recordPlus1, unsigned short*, 0x13);
                            Update81ADCField(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 3) +
                                                 Update81ADCField(recordPlus1, unsigned short*,
                                                                  0xF));
                            Update81ADCField(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 5) +
                                                 temp_a0_4);
                            Update81ADCField(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 7) +
                                                 temp_a1_2);
                            random2 = Update81ADCrand();
                            halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0xF);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update81ADCField(recordPlus1, unsigned short*, 0xF) = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0x11);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update81ADCField(recordPlus1, unsigned short*, 0x11) = halfword3;
                            random2 = Update81ADCrand();
                            halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0x13);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update81ADCField(recordPlus1, unsigned short*, 0x13) = halfword3;
                            MATCHING_KEEP(halfword3);
                            halfword3 = (short)halfword3;
                            if (halfword3 >= 3)
                                Update81ADCField(recordPlus1, unsigned short*, 0x13) = 2;
                            scratch2 = Update81ADCField(recordPlus1, short*, 0x13);
                            if (scratch2 < -4)
                                Update81ADCField(recordPlus1, short*, 0x13) = -4;
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xB);
                            scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0xD);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= 2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0xC);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch3 -= 1;
                            Update81ADCField(recordPlus1, unsigned char*, 0xD) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 2;
                            Update81ADCField(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4F:
                        temp_a0_5 =
                            (int)((short)Update81ADCField(recordPlus1, unsigned short*, 9) -
                                  (short)Update81ADCField(recordPlus1, unsigned short*, 3)) >>
                            1;
                        frame.halves[40] = (unsigned short)temp_a0_5;
                        frame.halves[41] =
                            (unsigned short)((int)((short)Update81ADCField(recordPlus1,
                                                                           unsigned short*, 0xB) -
                                                   (short)Update81ADCField(recordPlus1,
                                                                           unsigned short*, 5)) >>
                                             1);
                        frame.halves[42] =
                            (unsigned short)((int)((short)Update81ADCField(recordPlus1,
                                                                           unsigned short*, 0xD) -
                                                   (short)Update81ADCField(recordPlus1,
                                                                           unsigned short*, 7)) >>
                                             1);
                        Update81ADCField(recordPlus1, unsigned short*, 3) =
                            (unsigned short)(Update81ADCField(recordPlus1, unsigned short*, 3) +
                                             temp_a0_5);
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[41];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update81ADCField(recordPlus1, unsigned short*, 5) = scratch2;
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update81ADCField(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[42];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update81ADCField(recordPlus1, unsigned short*, 7) = scratch2;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        random2 = Update81ADCField(recordPlus1, unsigned short*, 9);
                        halfword3 = frame.halves[40];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update81ADCField(recordPlus1, unsigned short*, 9) = random2;
                        random2 = Update81ADCField(recordPlus1, unsigned short*, 0xB);
                        halfword3 = frame.halves[41];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update81ADCField(recordPlus1, unsigned short*, 0xB) = random2;
                        halfword3 = Update81ADCField(recordPlus1, unsigned short*, 0xD);
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[42];
                        MATCHING_KEEP3(halfword3, scratch2, scratch4);
                        scratch2 = scratch2 + 1;
                        halfword3 += scratch4;
                        Update81ADCField(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, halfword3);
                        Update81ADCField(recordPlus1, unsigned short*, 0xD) = halfword3;
                        if ((unsigned int)scratch2 >= 24)
                            goto removeRecord;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 2);
                        if (scratch2 != 0)
                            goto surviving4F;
                    removeRecord:
                        Update81ADCReleaseParticleRecord(record);
                        recordPlus1 += 32;
                        break;
                    surviving4F:
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0x11);
                        scratch3 = Update81ADCField(recordPlus1, unsigned char*, 0x15);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= 3;
                        Update81ADCField(recordPlus1, unsigned char*, 0x11) = scratch2;
                        scratch2 = Update81ADCField(recordPlus1, unsigned char*, 0x10);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 3;
                        MATCHING_KEEP2(scratch3, scratch2);
                        Update81ADCField(recordPlus1, unsigned char*, 0x15) = scratch3;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 -= 4;
                        Update81ADCField(recordPlus1, unsigned char*, 0x10) = scratch2;
                        temp_v1_10 =
                            (unsigned char)Update81ADCField(recordPlus1, unsigned char*, 0x13);
                        Update81ADCField(recordPlus1, unsigned char*, 0x14) =
                            (unsigned char)(Update81ADCField(recordPlus1, unsigned char*, 0x14) -
                                            4);
                        if (temp_v1_10 >= 6U) {
                            Update81ADCField(recordPlus1, unsigned char*, 0x13) =
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
