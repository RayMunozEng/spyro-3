#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80089474.
 * Assembly SHA256 fcb9c44196e4dacb142db1187b8e58d113d54fb210c15fd83729e3d6ca267428.
 * AI-generated; not human reviewed. Verified case C was adapted against all
 * original instructions. Selectors0/1/0x3D retain their concrete original
 * byte/halfword chains; selector0x3C reuses verified level23 byte-mode C.
 * Raw widths, constants, stack offsets, helper arguments and shared entries
 * are preserved. Units/fixed point, complete helper semantics and caller
 * cadence remain unresolved; step is the original argument, not a time unit.
 * Original1370 instructions and86 owned selectors/targets are mandatory.
 * Word7 follows the original A3 double/quad/pointer/one/product phases. The
 * doubled and quadrupled values live at SP0x48/SP0x50, pointer at SP0x60.
 * Raw128 uses ordinary C allocation for the original persistent FP constant;
 * the original frame is0x90 bytes. No fixed FP binding is used.
 * All empty-constraint inputs are initialized. Original MULT producers
 * precede HI/LO captures. Empty original-address metadata keeps distinct
 * clamp/case joins and emits zero CPU instructions. Addresses are provenance
 * metadata, not runtime values. C generates every CPU instruction. Compiler,
 * assembler, pipeline, flags, original padding and all gates are unchanged.
 * Falsification: all native/linked words and internal targets, every selector,
 * preserved data and full EXE/every-overlay original retail hashes.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Update89474Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Update89474func_8004E9E4(short) __asm__("func_8004E9E4");
int Update89474InterpolateCosine(short) __asm__("func_8004EA2C");
int Update89474CopyVector(void*, void*) __asm__("func_8004F178");
int Update89474PackVectorShiftRight2(void*, void*) __asm__("func_8004F504");
int Update89474func_8004F5A8(void*, void*, void*) __asm__("func_8004F5A8");
int Update89474func_80056504(void*) __asm__("func_80056504");
extern int Update89474D_8006C644 __asm__("D_8006C644");
extern unsigned short Update89474Sin[] __asm__("D_80065920");
extern unsigned short Update89474Cos[] __asm__("D_800658A0");
extern int (*Update89474SpawnParticle)(int, int, void*, int) __asm__("SpawnParticle");
int Update89474rand(void) __asm__("rand");
extern unsigned char* Update89474D_8006C554 __asm__("D_8006C554");
extern int Update89474D_8006C598 __asm__("D_8006C598");
extern int Update89474D_8006C640 __asm__("D_8006C640");
extern short Update89474D_8006E040 __asm__("D_8006E040");
extern int Update89474D_8006E344 __asm__("D_8006E344");
extern unsigned char Update89474D_80070328[] __asm__("D_80070328");
extern int Update89474Player48 __asm__("D_80070328 + 0x48");
extern int Update89474Player284 __asm__("D_80070328 + 0x284");
extern int Update89474Player280 __asm__("D_80070328 + 0x280");
#define Update89474High(a, b)                                                        \
    ({                                                                               \
        int high;                                                                    \
        __asm__ __volatile__("" : "=h"(high) : "l"((int)(a) * (int)(b)) : "memory"); \
        high;                                                                        \
    })
unsigned char* func_level_47_80089474(int initialStep) {
    register unsigned char* playerEnd __asm__("$5");
    register int scratch6 __asm__("$6");
    register int high7 __asm__("$7");
    register int step __asm__("$23");
    register int incomingStep __asm__("$4");
    register int scratch2 __asm__("$2");
    union {
        int words[20];
        unsigned short halves[40];
        struct {
            int pad[14];
            volatile int doubled48;
            int pad4C;
            volatile int quadrupled50;
            int rest[3];
        } saved;
    } frame;
    register int scratch5 __asm__("$5");
    register int scratch7 __asm__("$7");
    register int scratch8 __asm__("$8");
    register int predicate3 __asm__("$3");
    int temp_a0_3;
    int temp_a0_5;
    int raw128;
    register int word7 __asm__("$7");
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
    record = Update89474D_8006C554;
    incomingStep = initialStep;
    MATCHING_KEEP2(record, incomingStep);
    step = incomingStep;
    MATCHING_KEEP2_CLOBBER(record, step, "$4");
    scratch4 = Update89474Field(record, unsigned char*, 1);
    MATCHING_KEEP(scratch4);
    __asm__ __volatile__("" ::: "$2", "memory");
    scratch2 = 255;
    MATCHING_KEEP(scratch2);
    scratch3 = scratch4 & 255;
    MATCHING_KEEP2(scratch3, scratch4);
    MATCHING_KEEP(step);
    if (scratch3 != scratch2) {
        word7 = step * 2;
        MATCHING_KEEP2(word7, step);
        frame.saved.doubled48 = word7;
        word7 = step * 4;
        raw128 = 128;
        MATCHING_KEEP2(raw128, word7);
        recordPlus1 = record + 1;
        MATCHING_KEEP_VOLATILE_CLOBBER(recordPlus1, "memory");
        frame.saved.quadrupled50 = word7;
        word7 = (int)(record + 0x18);
        MATCHING_KEEP(word7);
        recordPlus24 = (unsigned char*)word7;
        recordPlus4 = record + 4;
        MATCHING_KEEP_VOLATILE_CLOBBER(scratch4, "memory");
        scratch3 = scratch4 & 255;
        MATCHING_KEEP2(scratch3, scratch4);
        do {
            MATCHING_BARRIER_GNU_VOLATILE("$2");
            if (scratch3 != 0xFE) {
                if (Update89474D_8006E344 == 4) {
                    if (*record == 0x42) {
                        if (Update89474D_8006C598 == 0) {
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
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        word7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word7);
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word7 = frame.saved.doubled48;
                        MATCHING_KEEP(word7);
                        scratch3 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        word7 = frame.saved.quadrupled50;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 -= word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch3 -= word7;
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, scratch3);
                        predicate2 = (unsigned int)scratch2 < 32;
                        __asm__ volatile("" : : "i"(0x800895DC));
                        Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x1:
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        word7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word7);
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word7 = frame.saved.quadrupled50;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        scratch2 -= word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch3 -= word7;
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        predicate2 = (unsigned int)scratch2 < 24;
                        scratch3 -= word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x6: {
                        register int radius16 __asm__("$16");
                        register int angle18 __asm__("$18");
                        register int height19 __asm__("$19");
                        register int product7 __asm__("$7");
                        playerEnd = Update89474Field(recordPlus1, unsigned char**, 0x17);
                        Update89474CopyVector(&frame.words[0], playerEnd);
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        radius16 = scratch2 << 6;
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        scratch3 = frame.words[2];
                        scratch2 <<= 6;
                        height19 = scratch3 + scratch2;
                        scratch3 = Update89474Field(recordPlus1, short*, 0x1B);
                        angle18 = radius16;
                        if (scratch3 < radius16)
                            radius16 = scratch3;
                        scratch2 = Update89474InterpolateCosine(angle18);
                        product7 = radius16 * scratch2;
                        scratch2 = frame.words[0];
                        MATCHING_KEEP2(product7, scratch2);
                        scratch3 = product7 >> 12;
                        scratch2 += scratch3;
                        frame.words[0] = scratch2;
                        scratch2 = Update89474func_8004E9E4(angle18);
                        product7 = radius16 * scratch2;
                        scratch2 = frame.words[1];
                        MATCHING_KEEP2(product7, scratch2);
                        scratch3 = product7 >> 12;
                        scratch2 += scratch3;
                        frame.words[1] = scratch2;
                        scratch2 = Update89474Field(recordPlus1, short*, 7);
                        scratch2 = (scratch2 << 2) + 64;
                        frame.words[2] = scratch2;
                        if (height19 < scratch2)
                            goto removeRecord;
                        Update89474PackVectorShiftRight2(recordPlus4, &frame.words[0]);
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch2++;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    }
                    case 0x9:
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        word7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2++;
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word7);
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word7 = frame.saved.doubled48;
                        scratch3 += word7;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP(scratch2);
                        predicate2 = (unsigned int)scratch2 < 32;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch3;
                        goto checkPredicate;
                    case 0xA: {
                        register void* temporary16 __asm__("$16");
                        scratch3 = Update89474Player48;
                        if (scratch3 == 30 && Update89474Player280 < 0)
                            goto removeRecord;
                        playerEnd = Update89474D_80070328 + 0x288;
                        MATCHING_KEEP(playerEnd);
                        if (Update89474Field(playerEnd, int*, 0) != 0)
                            goto removeRecord;
                        if (Update89474Player284 == 0)
                            goto removeRecord;
                        temporary16 = &frame.words[4];
                        Update89474CopyVector(temporary16, playerEnd - 0x288);
                        scratch2 = Update89474InterpolateCosine(
                            Update89474Field(recordPlus1, short*, 0x17));
                        scratch3 = frame.words[4];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 >>= 4;
                        scratch3 += scratch2;
                        frame.words[4] = scratch3;
                        scratch2 =
                            Update89474func_8004E9E4(Update89474Field(recordPlus1, short*, 0x17));
                        scratch4 = (int)recordPlus4;
                        playerEnd = (unsigned char*)temporary16;
                        MATCHING_KEEP3(scratch4, playerEnd, scratch2);
                        scratch2 >>= 4;
                        scratch3 = frame.words[5];
                        scratch6 = frame.words[6];
                        MATCHING_KEEP3(scratch2, scratch3, scratch6);
                        scratch3 += scratch2;
                        scratch6 += 256;
                        frame.words[5] = scratch3;
                        frame.words[6] = scratch6;
                        MATCHING_KEEP(scratch6);
                        Update89474PackVectorShiftRight2((void*)scratch4, playerEnd);
                        scratch4 = Update89474Field(recordPlus1, unsigned short*, 0x17);
                        scratch4 += 64;
                        Update89474Field(recordPlus1, unsigned short*, 0x17) = scratch4;
                        MATCHING_KEEP(scratch4);
                        scratch4 <<= 16;
                        scratch2 = Update89474D_8006E040;
                        MATCHING_KEEP2(scratch4, scratch2);
                        scratch4 >>= 16;
                        scratch4 -= scratch2;
                        scratch2 = Update89474InterpolateCosine(scratch4 & 4095);
                        scratch3 = 0x60606061;
                        MATCHING_KEEP2(scratch2, scratch3);
                        if (scratch2 < 0)
                            scratch2 = -scratch2;
                        MATCHING_KEEP2(scratch2, scratch3);
                        high7 = Update89474High(scratch2, scratch3);
                        scratch2 >>= 31;
                        MATCHING_KEEP(scratch2);
                        scratch3 = high7 >> 6;
                        scratch3 -= scratch2;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch3;
                        goto nextRecord;
                    }
                    case 0xB:
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        scratch4 = (int)recordPlus4;
                        if (scratch2 != 0) {
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x15);
                            scratch2++;
                            Update89474Field(recordPlus1, unsigned short*, 0x15) = scratch2;
                        }
                        playerEnd = recordPlus4;
                        MATCHING_KEEP2(scratch4, playerEnd);
                        scratch6 = (int)record + 18;
                        __asm__("" : "=r"(scratch6) : "0"(scratch6) : "$3", "memory");
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP(scratch2);
                        word7 = 1;
                        MATCHING_KEEP2(word7, scratch2);
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        Update89474func_8004F5A8((void*)scratch4, playerEnd, (void*)scratch6);
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 9);
                        word7 = frame.saved.doubled48;
                        MATCHING_KEEP2(scratch2, word7);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        scratch2 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xA);
                        word7 = frame.saved.quadrupled50;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xA) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 4;
                        Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch3 &= 255;
                        MATCHING_KEEP2(scratch3, scratch2);
                        scratch2 -= 4;
                        Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        if (scratch3 == 0)
                            goto removeRecord;
                        goto checkByte2;
                    case 0xC:
                        Update89474Field(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update89474Field(recordPlus1, unsigned char*, 0xA) + 8);
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        temp_v0_4 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_4 != 0) {
                            Update89474Field(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_4 - 8);
                        }
                        temp_v0_5 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_5 != 0) {
                            Update89474Field(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_5 - 8);
                        }
                        temp_v0_6 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_6 != 0) {
                            Update89474Field(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_6 - 8);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update89474Field(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0xD:
                        if ((unsigned int)Update89474Field(recordPlus1, unsigned char*, 1) >= 28)
                            goto removeRecord;
                        if (Update89474Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        if (Update89474Field(recordPlus1, short*, 0x1D) != 0)
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) =
                                Update89474Field(recordPlus1, unsigned short*, 0x1B) + 1;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        MATCHING_KEEP_CLOBBER(scratch2, "$8");
                        word7 = 1;
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 9);
                        word7 = frame.saved.doubled48;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 1);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch2;
                        predicate2 = (unsigned int)scratch3 < 13;
                        MATCHING_KEEP(predicate2);
                        if (!predicate2) {
                            scratch2 = (scratch3 - 12) * 8;
                            scratch2 = raw128 - scratch2;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            scratch3 = Update89474Field(recordPlus1, unsigned char*, 1);
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 64;
                            scratch3 = (scratch3 - 12) * 4;
                            scratch2 -= scratch3;
                            if (scratch2 < 0)
                                scratch2 = 0;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update89474Field(recordPlus1, unsigned char*, 0xD) = 0;
                        } else {
                            predicate2 = (unsigned int)scratch3 < 5;
                            if (!predicate2) {
                                scratch2 = -128;
                                scratch3 = Update89474Field(recordPlus1, unsigned char*, 1);
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = raw128;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = 0;
                                scratch3 = (scratch3 - 4) * 8;
                                scratch2 -= scratch3;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            } else {
                                scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = raw128;
                                scratch2 *= 32;
                                scratch2 = raw128 - scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = raw128;
                                if (scratch2 < 0)
                                    scratch2 = 0;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            }
                        }
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        goto nextRecord;
                    case 0x21:
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        if (Update89474Field(recordPlus1, short*, 0x1D) != 0) {
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*,
                                                                  0x1B) +
                                                 1);
                        }
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        word7 = frame.saved.doubled48;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 9);
                        MATCHING_KEEP3(scratch2, word7, scratch3);
                        scratch4 = scratch2 - word7;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        word7 = 1;
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word7 = frame.saved.doubled48;
                        scratch3 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch3;
                        if (scratch4 < 0) {
                            scratch4 = 0;
                        }
                        Update89474Field(recordPlus1, unsigned char*, 0xB) =
                            (unsigned char)scratch4;
                        Update89474Field(recordPlus1, unsigned char*, 0xC) =
                            (unsigned char)scratch4;
                        Update89474Field(recordPlus1, unsigned char*, 0xD) =
                            (unsigned char)scratch4;
                        temp_v0_7 = Update89474Field(recordPlus1, unsigned char*, 1) + step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = temp_v0_7;
                        if (((unsigned int)(temp_v0_7 & 0xFF) < 0x20U) &&
                            (Update89474Field(recordPlus1, unsigned char*, 2) != 0) &&
                            (scratch4 != 0)) {
                            recordPlus1 += 0x20;
                        } else {
                            goto removeRecord;
                        }
                        break;
                    case 0x31:
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 9);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 -= step;
                        Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= step;
                        Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch3 -= step;
                        Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        predicate2 = (unsigned int)scratch2 < 48;
                        goto checkPredicate;
                    case 0x3B:
                        Update89474Field(recordPlus1, unsigned char*, 0xA) =
                            (unsigned char)(Update89474Field(recordPlus1, unsigned char*, 0xA) + 8);
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        if (Update89474D_8006C640 & 1) {
                            Update89474Field(recordPlus1, unsigned short*, 0x19) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*,
                                                                  0x19) +
                                                 1);
                        }
                        temp_v0_8 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        if (temp_v0_8 != 0) {
                            Update89474Field(recordPlus1, unsigned char*, 0xB) =
                                (unsigned char)(temp_v0_8 - 4);
                        }
                        temp_v0_9 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        if (temp_v0_9 != 0) {
                            Update89474Field(recordPlus1, unsigned char*, 0xC) =
                                (unsigned char)(temp_v0_9 - 4);
                        }
                        temp_v0_10 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        if (temp_v0_10 != 0) {
                            Update89474Field(recordPlus1, unsigned char*, 0xD) =
                                (unsigned char)(temp_v0_10 - 4);
                        }
                        scratch3 = 0xFF0000;
                        __asm__ __volatile__("" : "=r"(scratch3) : "0"(scratch3) : "$2", "memory");
                        scratch2 = Update89474Field(recordPlus1, unsigned int*, 0xB);
                        scratch3 |= 0xFFFF;
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 &= scratch3;
                        MATCHING_KEEP(scratch2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        MATCHING_BARRIER_GNU_VOLATILE("$2");
                        goto checkByte2;
                    case 0x3C:
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        low19 = scratch2 & 31;
                        savedLow22 = low19;
                        __asm__("" : "=r"(savedLow22) : "0"(savedLow22), "r"(low19));
                        mode18 = (unsigned int)scratch2 >> 5;
                        maskedLow0 = (unsigned char)savedLow22;
                        if ((unsigned int)maskedLow0 >= 28)
                            goto removeRecord;
                        if (Update89474Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        Update89474func_8004F5A8(recordPlus4, recordPlus4, recordPlus24);
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        word7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 9);
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word7 = frame.saved.doubled48;
                        MATCHING_KEEP(word7);
                        scratch3 += word7;
                        Update89474Field(recordPlus1, unsigned char*, 9) = scratch3;
                        if (mode18 == 0) {
                            if ((unsigned int)maskedLow0 >= 13) {
                                scratch4 = maskedLow0 - 12;
                                scratch2 = scratch4 << 3;
                                MATCHING_KEEP(raw128);
                                scratch3 = raw128 - scratch2;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80089CFC));
                                    scratch3 = 0;
                                }
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                                scratch3 = scratch4 << 2;
                                scratch2 = 64;
                                scratch3 = scratch2 - scratch3;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80089D18));
                                    scratch3 = 0;
                                }
                                goto storeByte12Zero13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch3 = low19 - 4;
                                scratch3 <<= 3;
                                scratch2 = -128;
                                scratch2 -= scratch3;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = raw128;
                                goto storeWordToByte12Zero13;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            MATCHING_KEEP_VOLATILE(raw128);
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = raw128;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = raw128;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80089D50));
                                scratch3 = 0;
                            }
                            goto storeByte13;
                        }
                        word7 = 1;
                        MATCHING_KEEP(raw128);
                        if (mode18 == word7) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80089D88));
                                    scratch3 = 0;
                                }
                                goto storeByte12Zero13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = 0;
                                goto storeWordToByte12Zero13;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80089DB8));
                                scratch3 = 0;
                            }
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                        storeByte13:
                            Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                            goto finishByteModes;
                        }
                        if (mode18 == 2) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80089DF8));
                                    scratch3 = 0;
                                }
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = 0;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80089E38));
                                scratch3 = 0;
                            }
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            goto storeByte13;
                        }
                        if (mode18 == 3) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80089E74));
                                    scratch3 = 0;
                                }
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = 0;
                                goto finishByteModes;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = 0;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = maskedLow0 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80089EB4));
                                scratch3 = 0;
                            }
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                            goto finishByteModes;
                        }
                        if (mode18 == 4) {
                            if ((unsigned int)maskedLow0 >= 15) {
                                scratch2 = maskedLow0 - 12;
                                scratch2 <<= 2;
                                scratch3 = 64;
                                scratch3 -= scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = 0;
                                if (scratch3 < 0) {
                                    __asm__ volatile("" : : "i"(0x80089EF4));
                                    scratch3 = 0;
                                }
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                                goto storeByte13;
                            }
                            if ((unsigned int)maskedLow0 >= 5) {
                                scratch2 = low19 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = 0;
                            storeWordToBytes12And13:
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                                goto finishByteModes;
                            }
                            scratch2 = savedLow22 << 5;
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80089F28));
                                scratch3 = 0;
                            }
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
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
                                    __asm__ volatile("" : : "i"(0x80089F68));
                                    scratch3 = 0;
                                }
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                            storeByte12Zero13:
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch3 = (unsigned char)savedLow22;
                            if ((unsigned int)scratch3 >= 5) {
                                scratch2 = savedLow22 - 4;
                                scratch2 <<= 3;
                                scratch2 = ~scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            storeWordToByte12Zero13:
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = 0;
                                goto finishByteModes;
                            }
                            scratch2 = scratch3 << 5;
                            MATCHING_KEEP_VOLATILE(raw128);
                            scratch3 = raw128 - scratch2;
                            scratch2 = 255;
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            if (scratch3 < 0) {
                                __asm__ volatile("" : : "i"(0x80089FB8));
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
                                    __asm__ volatile("" : : "i"(0x80089FEC));
                                    scratch3 = 0;
                                }
                                scratch2 = (unsigned char)scratch3;
                                scratch2 = (unsigned int)scratch2 >> 1;
                                Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                                scratch2 = (unsigned int)scratch2 >> 1;
                                Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch3;
                                Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                                goto finishByteModes;
                            }
                            scratch2 = 160;
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = 80;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            scratch2 = 40;
                            Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch2;
                            goto finishByteModes;
                        }
                        if (mode18 == 7 && savedLow22 != 0)
                            Update89474func_80056504(record);
                        goto finishByteModes;
                    finishByteModes:
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch3 = savedLow22 + step;
                        scratch2 &= 224;
                        scratch3 |= scratch2;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch3;
                        goto nextRecord;
                    case 0x3D:
                        scratch2 = Update89474Field(recordPlus1, short*, 0x1D);
                        word7 = 1;
                        if (scratch2 != 0) {
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1B);
                            scratch2 += 1;
                            Update89474Field(recordPlus1, unsigned short*, 0x1B) = scratch2;
                        }
                        MATCHING_KEEP(word7);
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0x1D);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                        scratch2 = word7 - scratch2;
                        Update89474Field(recordPlus1, unsigned short*, 0x1D) = scratch2;
                        word7 = frame.saved.quadrupled50;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                        scratch3 -= word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                        scratch2 -= word7;
                        Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch3 -= word7;
                        scratch2 += step;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, scratch3);
                        predicate2 = (unsigned int)scratch2 < 32;
                        Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                        goto checkPredicate;
                    case 0x42:
                        iteration = 0;
                        if (step > 0) {
                            do {
                                if (Update89474Field(recordPlus1, unsigned char*, 1) & 1) {
                                    scratch2 = Update89474Field(recordPlus1, unsigned short*, 3);
                                    scratch4 = Update89474Field(recordPlus1, unsigned short*, 0xF);
                                    scratch3 = Update89474Field(recordPlus1, unsigned short*, 5);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    temp_a1 = Update89474Field(recordPlus1, unsigned short*, 0x11);
                                    scratch2 += scratch4;
                                    Update89474Field(recordPlus1, unsigned short*, 3) = scratch2;
                                    scratch2 = Update89474Field(recordPlus1, unsigned short*, 7);
                                    scratch4 = Update89474Field(recordPlus1, unsigned short*, 0x13);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch3 += temp_a1;
                                    Update89474Field(recordPlus1, unsigned short*, 5) = scratch3;
                                    scratch3 = Update89474Field(recordPlus1, unsigned char*, 1);
                                    MATCHING_KEEP3(scratch2, scratch4, scratch3);
                                    scratch2 += scratch4;
                                    scratch3 &= 2;
                                    Update89474Field(recordPlus1, unsigned short*, 7) = scratch2;
                                    if (scratch3 != 0) {
                                        random2 = Update89474rand();
                                        halfword3 =
                                            Update89474Field(recordPlus1, unsigned short*, 0xF);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update89474Field(recordPlus1, unsigned short*, 0xF) =
                                            halfword3;
                                        random2 = Update89474rand();
                                        halfword3 =
                                            Update89474Field(recordPlus1, unsigned short*, 0x11);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update89474Field(recordPlus1, unsigned short*, 0x11) =
                                            halfword3;
                                        random2 = Update89474rand();
                                        halfword3 =
                                            Update89474Field(recordPlus1, unsigned short*, 0x13);
                                        MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2,
                                                                            "memory");
                                        random2 &= 2;
                                        halfword3 -= 1;
                                        halfword3 += random2;
                                        Update89474Field(recordPlus1, unsigned short*, 0x13) =
                                            halfword3;
                                    }
                                }
                                iteration += 1;
                                Update89474Field(recordPlus1, unsigned char*, 1) =
                                    (unsigned char)(Update89474Field(recordPlus1, unsigned char*,
                                                                     1) +
                                                    1);
                            } while (iteration < step);
                        }
                        predicate2 =
                            (unsigned char)Update89474Field(recordPlus1, unsigned char*, 1) < 0x18U;
                        goto checkPredicate;
                    case 0x46:
                        temp_v0_11 = Update89474Field(recordPlus1, unsigned char*, 1) + 1;
                        Update89474Field(recordPlus1, unsigned char*, 1) = temp_v0_11;
                        if (((unsigned int)(temp_v0_11 & 0xFF) < 0x20U) &&
                            (Update89474Field(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_3 =
                                (int)((short)Update89474Field(recordPlus1, unsigned short*, 9) -
                                      (short)Update89474Field(recordPlus1, unsigned short*, 3)) >>
                                1;
                            frame.halves[16] = (unsigned short)temp_a0_3;
                            frame.halves[17] =
                                (unsigned short)((int)((short)Update89474Field(
                                                           recordPlus1, unsigned short*, 0xB) -
                                                       (short)Update89474Field(
                                                           recordPlus1, unsigned short*, 5)) >>
                                                 1);
                            frame.halves[18] =
                                (unsigned short)((int)((short)Update89474Field(
                                                           recordPlus1, unsigned short*, 0xD) -
                                                       (short)Update89474Field(
                                                           recordPlus1, unsigned short*, 7)) >>
                                                 1);
                            Update89474Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 3) +
                                                 temp_a0_3);
                            Update89474Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 5) +
                                                 frame.halves[17]);
                            Update89474Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 7) +
                                                 frame.halves[18]);
                            random2 = Update89474rand();
                            halfword3 = frame.halves[16];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[16] = halfword3;
                            random2 = Update89474rand();
                            halfword3 = frame.halves[17];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.halves[17] = halfword3;
                            if (Update89474Field(recordPlus1, unsigned char*, 1) & 1) {
                                frame.halves[18] -= 1;
                            }
                            random2 = Update89474Field(recordPlus1, unsigned short*, 9);
                            halfword3 = frame.halves[16];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update89474Field(recordPlus1, unsigned short*, 9) = random2;
                            random2 = Update89474Field(recordPlus1, unsigned short*, 0xB);
                            halfword3 = frame.halves[17];
                            MATCHING_KEEP2(random2, halfword3);
                            random2 += halfword3;
                            Update89474Field(recordPlus1, unsigned short*, 0xB) = random2;
                            halfword3 = Update89474Field(recordPlus1, unsigned short*, 0xD);
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xF);
                            scratch4 = frame.halves[18];
                            MATCHING_KEEP3(halfword3, scratch2, scratch4);
                            scratch2 = scratch2 - 3;
                            halfword3 += scratch4;
                            Update89474Field(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 &= 255;
                            MATCHING_KEEP2(scratch2, halfword3);
                            Update89474Field(recordPlus1, unsigned short*, 0xD) = halfword3;
                            if ((unsigned int)scratch2 < 128) {
                                MATCHING_KEEP(raw128);
                                Update89474Field(recordPlus1, unsigned char*, 0xF) = raw128;
                            }
                            temp_v0_13 = Update89474Field(recordPlus1, unsigned char*, 0x10) - 4;
                            Update89474Field(recordPlus1, unsigned char*, 0x10) = temp_v0_13;
                            if ((unsigned int)(temp_v0_13 & 0xFF) < 0x60U) {
                                Update89474Field(recordPlus1, unsigned char*, 0x10) = 0x60U;
                            }
                            Update89474Field(recordPlus1, unsigned char*, 0x11) = 0;
                            temp_v0_14 =
                                (unsigned char)Update89474Field(recordPlus1, unsigned char*, 0x13) -
                                3;
                            Update89474Field(recordPlus1, unsigned char*, 0x13) = temp_v0_14;
                            if ((unsigned int)(temp_v0_14 & 0xFF) < 0xC0U) {
                                Update89474Field(recordPlus1, unsigned char*, 0x13) = 0xC0;
                            }
                            temp_v0_15 = Update89474Field(recordPlus1, unsigned char*, 0x14) - 4;
                            Update89474Field(recordPlus1, unsigned char*, 0x14) = temp_v0_15;
                            if ((unsigned int)(temp_v0_15 & 0xFF) < 0x80U) {
                                __asm__ volatile("" ::: "$8", "memory");
                                MATCHING_KEEP(raw128);
                                Update89474Field(recordPlus1, unsigned char*, 0x14) = raw128;
                            }
                            temp_v0_16 =
                                (unsigned char)Update89474Field(recordPlus1, unsigned char*, 0x15) -
                                6;
                            Update89474Field(recordPlus1, unsigned char*, 0x15) = temp_v0_16;
                            if ((unsigned int)(temp_v0_16 & 0xFF) < 0x20U) {
                                Update89474Field(recordPlus1, unsigned char*, 0x15) = 0x20;
                            }
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x47:
                        temp_v0_17 = Update89474Field(recordPlus1, unsigned char*, 1) + 1;
                        Update89474Field(recordPlus1, unsigned char*, 1) = temp_v0_17;
                        if (((unsigned int)(temp_v0_17 & 0xFF) < 0x20U) &&
                            (Update89474Field(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[10] =
                                (short)Update89474Field(recordPlus1, unsigned short*, 9) -
                                (short)Update89474Field(recordPlus1, unsigned short*, 3);
                            frame.words[11] =
                                (short)Update89474Field(recordPlus1, unsigned short*, 0xB) -
                                (short)Update89474Field(recordPlus1, unsigned short*, 5);
                            frame.words[12] =
                                (short)Update89474Field(recordPlus1, unsigned short*, 0xD) -
                                (short)Update89474Field(recordPlus1, unsigned short*, 7);
                            random2 = Update89474rand();
                            halfword3 = frame.words[10];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[10] = halfword3;
                            random2 = Update89474rand();
                            halfword3 = frame.words[11];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[11] = halfword3;
                            random2 = Update89474rand();
                            halfword3 = frame.words[12];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[12] = halfword3;
                            Update89474Field(recordPlus1, unsigned short*, 9) =
                                (short)((unsigned short)Update89474Field(recordPlus1,
                                                                         unsigned short*, 9) +
                                        frame.words[10]);
                            Update89474Field(recordPlus1, unsigned short*, 0xB) =
                                (short)((unsigned short)Update89474Field(recordPlus1,
                                                                         unsigned short*, 0xB) +
                                        frame.words[11]);
                            Update89474Field(recordPlus1, unsigned short*, 0xD) =
                                (short)((unsigned short)Update89474Field(recordPlus1,
                                                                         unsigned short*, 0xD) +
                                        frame.words[12]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[10];
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 9);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update89474Field(recordPlus1, unsigned short*, 3) = scratch2;
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            scratch3 = frame.words[11];
                            scratch2 = Update89474Field(recordPlus1, unsigned short*, 0xB);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= scratch3;
                            Update89474Field(recordPlus1, unsigned short*, 5) = scratch2;
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0x13);
                            scratch4 = frame.words[12];
                            scratch3 = Update89474Field(recordPlus1, unsigned char*, 0x15);
                            MATCHING_KEEP3(scratch2, scratch4, scratch3);
                            scratch2 -= 2;
                            Update89474Field(recordPlus1, unsigned char*, 0x13) = scratch2;
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0x14);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 4;
                            Update89474Field(recordPlus1, unsigned char*, 0x15) = scratch3;
                            scratch3 = Update89474Field(recordPlus1, unsigned char*, 0x10);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 2;
                            Update89474Field(recordPlus1, unsigned char*, 0x14) = scratch2;
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xF);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= 3;
                            Update89474Field(recordPlus1, unsigned char*, 0x10) = scratch3;
                            scratch3 = Update89474Field(recordPlus1, unsigned short*, 0xD);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch2 -= 3;
                            Update89474Field(recordPlus1, unsigned char*, 0xF) = scratch2;
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0x11);
                            MATCHING_KEEP3(scratch2, scratch3, scratch4);
                            scratch3 -= scratch4;
                            Update89474Field(recordPlus1, unsigned short*, 7) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 3;
                            Update89474Field(recordPlus1, unsigned char*, 0x11) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x48:
                        temp_v0_18 = Update89474Field(recordPlus1, unsigned char*, 1) + 1;
                        Update89474Field(recordPlus1, unsigned char*, 1) = temp_v0_18;
                        if (((unsigned int)(temp_v0_18 & 0xFF) < 0x38U) &&
                            (Update89474Field(recordPlus1, unsigned char*, 2) != 0)) {
                            frame.words[8] =
                                (int)((short)Update89474Field(recordPlus1, unsigned short*, 3) -
                                      (short)Update89474Field(recordPlus1, unsigned short*, 9)) >>
                                1;
                            frame.words[9] =
                                (int)((short)Update89474Field(recordPlus1, unsigned short*, 5) -
                                      (short)Update89474Field(recordPlus1, unsigned short*, 0xB)) >>
                                1;
                            frame.words[10] =
                                (int)((short)Update89474Field(recordPlus1, unsigned short*, 7) -
                                      (short)Update89474Field(recordPlus1, unsigned short*, 0xD)) >>
                                1;
                            random2 = Update89474rand();
                            halfword3 = frame.words[8];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[8] = halfword3;
                            random2 = Update89474rand();
                            halfword3 = frame.words[9];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 4;
                            halfword3 -= 2;
                            halfword3 += random2;
                            frame.words[9] = halfword3;
                            random2 = Update89474rand();
                            halfword3 = frame.words[10];
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            frame.words[10] = halfword3;
                            Update89474Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 3) +
                                                 frame.words[8]);
                            Update89474Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 5) +
                                                 frame.words[9]);
                            Update89474Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 7) +
                                                 frame.words[10]);
                            MATCHING_BARRIER_GNU_VOLATILE("memory");
                            Update89474Field(recordPlus1, unsigned short*, 9) =
                                (short)(Update89474Field(recordPlus1, unsigned short*, 3) -
                                        (frame.words[8] * 2));
                            Update89474Field(recordPlus1, unsigned short*, 0xB) =
                                (short)(Update89474Field(recordPlus1, unsigned short*, 5) -
                                        (frame.words[9] * 2));
                            Update89474Field(recordPlus1, unsigned short*, 0xD) =
                                (short)(Update89474Field(recordPlus1, unsigned short*, 7) -
                                        (frame.words[10] * 2));
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4E:
                        temp_v0_19 = Update89474Field(recordPlus1, unsigned char*, 1) + 1;
                        Update89474Field(recordPlus1, unsigned char*, 1) = temp_v0_19;
                        if (((unsigned int)(temp_v0_19 & 0xFF) < 0x28U) &&
                            (Update89474Field(recordPlus1, unsigned char*, 2) != 0)) {
                            temp_a0_4 = Update89474Field(recordPlus1, unsigned short*, 0x11);
                            temp_a1_2 = Update89474Field(recordPlus1, unsigned short*, 0x13);
                            Update89474Field(recordPlus1, unsigned short*, 3) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 3) +
                                                 Update89474Field(recordPlus1, unsigned short*,
                                                                  0xF));
                            Update89474Field(recordPlus1, unsigned short*, 5) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 5) +
                                                 temp_a0_4);
                            Update89474Field(recordPlus1, unsigned short*, 7) =
                                (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 7) +
                                                 temp_a1_2);
                            random2 = Update89474rand();
                            halfword3 = Update89474Field(recordPlus1, unsigned short*, 0xF);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update89474Field(recordPlus1, unsigned short*, 0xF) = halfword3;
                            random2 = Update89474rand();
                            halfword3 = Update89474Field(recordPlus1, unsigned short*, 0x11);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update89474Field(recordPlus1, unsigned short*, 0x11) = halfword3;
                            random2 = Update89474rand();
                            halfword3 = Update89474Field(recordPlus1, unsigned short*, 0x13);
                            MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(halfword3, random2, "memory");
                            random2 &= 2;
                            halfword3 -= 1;
                            halfword3 += random2;
                            Update89474Field(recordPlus1, unsigned short*, 0x13) = halfword3;
                            MATCHING_KEEP(halfword3);
                            halfword3 = (short)halfword3;
                            if (halfword3 >= 3)
                                Update89474Field(recordPlus1, unsigned short*, 0x13) = 2;
                            scratch2 = Update89474Field(recordPlus1, short*, 0x13);
                            if (scratch2 < -4)
                                Update89474Field(recordPlus1, short*, 0x13) = -4;
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xB);
                            scratch3 = Update89474Field(recordPlus1, unsigned char*, 0xD);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch2 -= 2;
                            Update89474Field(recordPlus1, unsigned char*, 0xB) = scratch2;
                            scratch2 = Update89474Field(recordPlus1, unsigned char*, 0xC);
                            MATCHING_KEEP2(scratch2, scratch3);
                            scratch3 -= 1;
                            Update89474Field(recordPlus1, unsigned char*, 0xD) = scratch3;
                            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                            scratch2 -= 2;
                            Update89474Field(recordPlus1, unsigned char*, 0xC) = scratch2;
                            goto nextRecord;
                        }
                        goto removeRecord;
                    case 0x4F:
                        temp_a0_5 =
                            (int)((short)Update89474Field(recordPlus1, unsigned short*, 9) -
                                  (short)Update89474Field(recordPlus1, unsigned short*, 3)) >>
                            1;
                        frame.halves[16] = (unsigned short)temp_a0_5;
                        frame.halves[17] =
                            (unsigned short)((int)((short)Update89474Field(recordPlus1,
                                                                           unsigned short*, 0xB) -
                                                   (short)Update89474Field(recordPlus1,
                                                                           unsigned short*, 5)) >>
                                             1);
                        frame.halves[18] =
                            (unsigned short)((int)((short)Update89474Field(recordPlus1,
                                                                           unsigned short*, 0xD) -
                                                   (short)Update89474Field(recordPlus1,
                                                                           unsigned short*, 7)) >>
                                             1);
                        Update89474Field(recordPlus1, unsigned short*, 3) =
                            (unsigned short)(Update89474Field(recordPlus1, unsigned short*, 3) +
                                             temp_a0_5);
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[17];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update89474Field(recordPlus1, unsigned short*, 5) = scratch2;
                        __asm__ __volatile__("" ::: "$2", "$3", "memory");
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[18];
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 += scratch3;
                        Update89474Field(recordPlus1, unsigned short*, 7) = scratch2;
                        MATCHING_BARRIER_GNU_VOLATILE("memory");
                        random2 = Update89474Field(recordPlus1, unsigned short*, 9);
                        halfword3 = frame.halves[16];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update89474Field(recordPlus1, unsigned short*, 9) = random2;
                        random2 = Update89474Field(recordPlus1, unsigned short*, 0xB);
                        halfword3 = frame.halves[17];
                        MATCHING_KEEP2(random2, halfword3);
                        random2 += halfword3;
                        Update89474Field(recordPlus1, unsigned short*, 0xB) = random2;
                        halfword3 = Update89474Field(recordPlus1, unsigned short*, 0xD);
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[18];
                        MATCHING_KEEP3(halfword3, scratch2, scratch4);
                        scratch2 = scratch2 + 1;
                        halfword3 += scratch4;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        MATCHING_KEEP2(scratch2, halfword3);
                        Update89474Field(recordPlus1, unsigned short*, 0xD) = halfword3;
                        if ((unsigned int)scratch2 >= 24)
                            goto removeRecord;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 2);
                        if (scratch2 == 0)
                            goto removeRecord;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0x11);
                        scratch3 = Update89474Field(recordPlus1, unsigned char*, 0x15);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch2 -= 3;
                        Update89474Field(recordPlus1, unsigned char*, 0x11) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 0x10);
                        MATCHING_KEEP2(scratch2, scratch3);
                        scratch3 -= 3;
                        MATCHING_KEEP2(scratch3, scratch2);
                        Update89474Field(recordPlus1, unsigned char*, 0x15) = scratch3;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(scratch2, "memory");
                        scratch2 -= 4;
                        Update89474Field(recordPlus1, unsigned char*, 0x10) = scratch2;
                        temp_v1_10 =
                            (unsigned char)Update89474Field(recordPlus1, unsigned char*, 0x13);
                        Update89474Field(recordPlus1, unsigned char*, 0x14) =
                            (unsigned char)(Update89474Field(recordPlus1, unsigned char*, 0x14) -
                                            4);
                        if (temp_v1_10 >= 6U) {
                            Update89474Field(recordPlus1, unsigned char*, 0x13) =
                                (signed char)(temp_v1_10 - 6);
                        }
                        goto nextRecord;
                    case 0x52:
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 7);
                        scratch3 = Update89474Field(recordPlus1, unsigned short*, 0xD);
                        scratch2 += 48;
                        scratch3 += 48;
                        Update89474Field(recordPlus1, unsigned short*, 0xD) = scratch3;
                        scratch3 = (short)scratch3;
                        Update89474Field(recordPlus1, unsigned short*, 7) = scratch2;
                        if (scratch3 < 0)
                            goto removeRecord;
                        scratch2 = Update89474Field(recordPlus1, int*, 0x17);
                        if (scratch2 < scratch3)
                            goto removeRecord;
                        recordPlus1 += 32;
                        break;
                    case 0x55:
                        scratch4 = Update89474Field(recordPlus1, unsigned short*, 9);
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 3);
                        scratch4 -= scratch2;
                        frame.halves[16] = scratch4;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0xB);
                        scratch3 = Update89474Field(recordPlus1, unsigned short*, 5);
                        scratch2 -= scratch3;
                        frame.halves[17] = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0xD);
                        scratch3 = Update89474Field(recordPlus1, unsigned short*, 7);
                        scratch2 -= scratch3;
                        frame.halves[18] = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 3);
                        scratch2 += scratch4;
                        Update89474Field(recordPlus1, unsigned short*, 3) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 5);
                        scratch3 = frame.halves[17];
                        scratch2 += scratch3;
                        Update89474Field(recordPlus1, unsigned short*, 5) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 7);
                        scratch3 = frame.halves[18];
                        scratch2 += scratch3;
                        Update89474Field(recordPlus1, unsigned short*, 7) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 9);
                        scratch3 = frame.halves[16];
                        scratch2 += scratch3;
                        Update89474Field(recordPlus1, unsigned short*, 9) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned short*, 0xB);
                        scratch3 = frame.halves[17];
                        scratch2 += scratch3;
                        scratch3 = Update89474Field(recordPlus1, unsigned short*, 0xD);
                        Update89474Field(recordPlus1, unsigned short*, 0xB) = scratch2;
                        scratch2 = Update89474Field(recordPlus1, unsigned char*, 1);
                        scratch4 = frame.halves[18];
                        scratch2 += 1;
                        scratch3 += scratch4;
                        Update89474Field(recordPlus1, unsigned char*, 1) = scratch2;
                        scratch2 &= 255;
                        predicate2 = (unsigned int)scratch2 < 2;
                        Update89474Field(recordPlus1, unsigned short*, 0xD) = scratch3;
                        goto checkPredicate;
                    checkPredicate:
                        if (predicate2 == 0)
                            goto removeRecord;
                    checkByte2:
                        if (Update89474Field(recordPlus1, unsigned char*, 2) == 0)
                            goto removeRecord;
                        goto nextRecord;
                    removeRecord:
                        Update89474func_80056504(record);
                        goto nextRecord;
                    default:
                        goto nextRecord;
                }
            } else {
            nextRecord:
                recordPlus1 += 0x20;
            }
            recordPlus4 += 0x20;
            word7 = (int)recordPlus24;
            MATCHING_KEEP(word7);
            word7 += 0x20;
            recordPlus24 = (unsigned char*)word7;
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
#undef Update89474High
#undef Update89474Field
