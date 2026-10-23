#include "matching.h"
#include "common.h"
#include "memcard.h"

/**
 * ChecksumSaveData_Title() - func_title_80078BF4() - MATCHING
 * https://decomp.me/scratch/1ODXk
 */
int func_title_80078BF4(unsigned char* data) {
    return ChecksumSaveData(data);
}

/**
 * SaveGame_Title() - func_title_80078C1C() - MATCHING
 * https://decomp.me/scratch/dAm5W
 */
void func_title_80078C1C(SaveFile* save, int noUpdate) {
    SaveGame(save, noUpdate);
    save->checksum = func_title_80078BF4((char*)save);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/title/title2/func_title_80078EAC.s SHA256 5bfd9f15758a0a281013bbe6a89325e6f968659c5e25d6941cee14c960f9826b. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Title78EACField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

void Title78EAC_ActivateSparxPowers(void) __asm__("ActivateSparxPowers");
/* extern */
void Title78EACCopyWordRangeUnrolled4(void*, void*, int) __asm__("func_8004E7D4");
/* extern */
extern unsigned char Title78EAC_D_80066BC8 __asm__("D_80066BC8");
extern unsigned char Title78EAC_D_80066EAC __asm__("D_80066EAC");
extern unsigned char Title78EAC_D_80066EAE __asm__("D_80066EAE");
extern unsigned char Title78EAC_D_80066F54 __asm__("D_80066F54");
extern int Title78EAC_D_8006C3F8 __asm__("D_8006C3F8");
extern int Title78EAC_D_8006C3FC __asm__("D_8006C3FC");
extern int Title78EAC_D_8006C400 __asm__("D_8006C400");
extern int Title78EAC_D_8006C5BC __asm__("D_8006C5BC");
extern int Title78EAC_D_8006C5D0 __asm__("D_8006C5D0");
extern int Title78EAC_D_8006C660 __asm__("D_8006C660");
extern int Title78EAC_D_8006C70C __asm__("D_8006C70C");
extern int Title78EAC_D_8006C710 __asm__("D_8006C710");
extern int Title78EAC_D_8006C71C __asm__("D_8006C71C");
extern int Title78EAC_D_8006C784 __asm__("D_8006C784");
extern int Title78EAC_D_8006C7A8 __asm__("D_8006C7A8");
extern int Title78EAC_D_8006C7B0 __asm__("D_8006C7B0");
extern int Title78EAC_D_8006E4AC __asm__("D_8006E4AC");
extern unsigned char Title78EAC_D_8006E50C __asm__("D_8006E50C");
extern unsigned char Title78EAC_D_80070300 __asm__("D_80070300");
extern unsigned char Title78EAC_D_8007145C __asm__("D_8007145C");
extern unsigned char Title78EAC_D_80071570 __asm__("D_80071570");
extern unsigned char Title78EAC_D_80071573 __asm__("D_80071573");
extern unsigned char Title78EAC_D_800715BC __asm__("D_800715BC");
extern unsigned char Title78EAC_D_800716AC __asm__("D_800716AC");
extern int Title78EAC_D_800718CC __asm__("D_800718CC");
extern int Title78EAC_D_80071A10 __asm__("D_80071A10");
extern unsigned char Title78EAC_D_80071AB0 __asm__("D_80071AB0");
extern unsigned char Title78EAC_D_80071FB0 __asm__("D_80071FB0");
extern unsigned char Title78EAC_D_8007201C __asm__("D_8007201C");
extern unsigned char Title78EAC_CheatBytes[] __asm__("g_CheatFlags");
extern unsigned char Title78EAC_Records[] __asm__("speedwayRecords");

void func_title_80078EAC(void* inputOwner) {
    /* Original 0x18 frame;
     buffer saved in register16. Byte fields remain
     * unsigned, the 0x530 records and moneybags-table reads use signed LH,
     * and each word destination advances four BYTES. RecordWord7 advances
     * 0x2C BYTES, not 0x2C ints. Repeated field/global reloads and the four
     * 0x64C..0x658 word loads precede their original stores. The existing
     * 4E7D4 contract is three arguments with an int length;
      the matched
     * ActivateSparxPowers routine has no arguments. Empty constraints
     * preserve raw register producers and emit no instructions. Raw field
     * units, frame cadence, semantic consumer chains and synchronized
     * runtime validation remain unresolved. AI generated;
      not human reviewed. */
    register void* buffer16 __asm__("$16") = inputOwner;
    register int signedHalfword4 __asm__("$4");
    register int* destinationWords4 __asm__("$4");
    register int* wordTotals6 __asm__("$6");
    register int* recordWord7 __asm__("$7");
    register void* copy4 __asm__("$4");
    register void* copy5 __asm__("$5");
    register int word8 __asm__("$8");
    register int recordThreshold9 __asm__("$9");
    register int recordOne8 __asm__("$8");
    register int comparisonOne5 __asm__("$5");
    register int temp_a3 __asm__("$7");
    register int temp_v0_2 __asm__("$2");
    register int temp_v0_3 __asm__("$2");
    register int temp_v1 __asm__("$3");
    register int byteOffset4 __asm__("$4");
    register int recordOffset4 __asm__("$4");
    register int recordIndex5 __asm__("$5");
    register int recordIndex5_2 __asm__("$5");
    register int wordIndex5 __asm__("$5");
    register int bitIndex3 __asm__("$3");
    register unsigned char* recordFlags7 __asm__("$7");
    register int temp_v0 __asm__("$2");
    register unsigned char temp_v1_3 __asm__("$3");
    void* temp_v1_2;
    register void* sourceWords6 __asm__("$6");
    register void* halfwordCursor8 __asm__("$8");
    register void* sourceWords3 __asm__("$3");

    MATCHING_KEEP(buffer16);
    Title78EAC_D_8006C5BC = (int)Title78EACField(buffer16, unsigned char*, 5);
    temp_v0 = Title78EACField(buffer16, unsigned char*, 6);
    MATCHING_KEEP(temp_v0);
    Title78EAC_D_8006C784 = (int)temp_v0;
    if ((int)temp_v0 >= 0x64) {
        Title78EAC_D_8006C784 = 0;
    }
    if (Title78EAC_D_8006C784 < 4) {
        Title78EAC_D_8006C784 = 4;
    }
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_80071FB0, buffer16 + 8, 0x28);
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_80071AB0, buffer16 + 0x30, 0x500);
    recordIndex5 = 0;
    recordFlags7 = &Title78EAC_D_80070300;
    wordTotals6 = &Title78EAC_D_80071A10;
    halfwordCursor8 = buffer16;
    Title78EAC_D_8006C71C = 0;
    Title78EAC_D_8006C660 = 0;
    do {
        signedHalfword4 = Title78EACField(halfwordCursor8, short*, 0x530);
        *wordTotals6 = (int)signedHalfword4;
        if (recordIndex5 < 0x27) {
            temp_v1 = *(&Title78EAC_D_80066F54 + recordIndex5) * 0x64;
            temp_v0_2 = temp_v1 < signedHalfword4;
            MATCHING_KEEP(temp_v0_2);
            if (temp_v0_2) {
                *wordTotals6 = temp_v1;
            }
        }
        Title78EAC_D_8006C71C += *wordTotals6;
        bitIndex3 = 0;
        *recordFlags7 = Title78EACField((buffer16 + recordIndex5), unsigned char*, 0x580);
    countSetBits:
        if (((int)*recordFlags7 >> bitIndex3) & 1) {
            Title78EAC_D_8006C660 += 1;
        }
        bitIndex3 += 1;
        if (bitIndex3 < 8) {
            goto countSetBits;
        }
        recordFlags7 += 1;
        wordTotals6 += 1;
        recordIndex5 += 1;
        halfwordCursor8 += 2;
    } while (recordIndex5 < 0x28);
    copy4 = &Title78EAC_D_800715BC;
    copy5 = buffer16 + 0x65C;
    MATCHING_KEEP2(copy4, copy5);
    temp_v0_2 = Title78EACField(buffer16, int*, 0x64C);
    temp_v1 = Title78EACField(buffer16, int*, 0x650);
    temp_a3 = Title78EACField(buffer16, int*, 0x654);
    word8 = Title78EACField(buffer16, int*, 0x658);
    MATCHING_KEEP4(temp_v0_2, temp_v1, temp_a3, word8);
    Title78EAC_D_8006C5D0 = temp_v0_2;
    Title78EAC_D_8006C70C = temp_v1;
    Title78EAC_D_8006C710 = temp_a3;
    Title78EAC_D_8006C7A8 = word8;
    Title78EACCopyWordRangeUnrolled4(copy4, copy5, 240);
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_800716AC, buffer16 + 0x74C, 0xF0);
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_80066EAC, buffer16 + 0x5A8, 0x30);
    comparisonOne5 = 1;
    if (Title78EAC_D_80071573 == 0) {
        byteOffset4 = 0;
        do {
            if (Title78EACField(&Title78EAC_D_80066EAE, short*, byteOffset4) == comparisonOne5) {
                Title78EAC_D_8006C71C -=
                    Title78EACField(&Title78EAC_D_80066EAC, short*, byteOffset4);
            }
            byteOffset4 += 4;
        } while (byteOffset4 < 0x30);
    }
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_80071570, buffer16 + 0x5D8, 0x4C);
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_8007145C, buffer16 + 0x624, 0x28);
    Title78EACCopyWordRangeUnrolled4(&Title78EAC_D_80066BC8, buffer16 + 0x874, 0x4C);
    recordIndex5_2 = 0;
    recordThreshold9 = 0x8C9F;
    recordOne8 = 1;
    recordWord7 = (int*)(Title78EAC_Records + 0x24);
    sourceWords6 = buffer16;
    recordOffset4 = 0;
    do {
        temp_v1_2 = buffer16 + recordIndex5_2;
        Title78EACField(Title78EAC_Records, int*, 16 + recordOffset4) =
            (int)Title78EACField(temp_v1_2, unsigned char*, 0x83C);
        Title78EACField(Title78EAC_Records, int*, 20 + recordOffset4) =
            Title78EACField(sourceWords6, int*, 0x840);
        Title78EACField(Title78EAC_Records, int*, 28 + recordOffset4) =
            (int)Title78EACField(temp_v1_2, unsigned char*, 0x850);
        temp_v0_2 = Title78EACField(sourceWords6, int*, 0x854);
        Title78EACField(Title78EAC_Records, int*, 40 + recordOffset4) = temp_v0_2;
        if (temp_v0_2 <= recordThreshold9) {
            *recordWord7 = recordOne8;
        } else {
            *recordWord7 = 0;
        }
        recordWord7 = (int*)((unsigned char*)recordWord7 + 0x2C);
        sourceWords6 += 4;
        recordIndex5_2 += 1;
        recordOffset4 += 0x2C;
    } while (recordIndex5_2 < 4);
    wordIndex5 = 0;
    destinationWords4 = &Title78EAC_D_800718CC;
    sourceWords3 = buffer16;
    do {
        temp_v0_3 = Title78EACField(sourceWords3, int*, 0x864);
        sourceWords3 += 4;
        wordIndex5 += 1;
        *destinationWords4 = temp_v0_3;
        destinationWords4 += 1;
    } while (wordIndex5 < 4);
    Title78EACField(Title78EAC_CheatBytes, unsigned char*, 2) =
        (unsigned char)Title78EACField(buffer16, unsigned char*, 0x889);
    Title78EAC_D_8006E50C = Title78EACField(buffer16, unsigned char*, 0x88A);
    Title78EAC_D_8007201C = Title78EACField(buffer16, unsigned char*, 0x88A);
    Title78EAC_D_8006C7B0 = (int)Title78EACField(buffer16, unsigned char*, 0x88B);
    Title78EAC_D_8006C3F8 = (int)Title78EACField(buffer16, unsigned char*, 0x88C);
    temp_v1_3 = Title78EACField(buffer16, unsigned char*, 0x88D);
    Title78EAC_D_8006C3FC = (int)temp_v1_3;
    Title78EAC_D_8006E4AC = (temp_v1_3 * 0x5FFF) / 10;
    Title78EAC_D_8006C400 = (int)Title78EACField(buffer16, unsigned char*, 0x88E);
    Title78EAC_ActivateSparxPowers();
}
#undef Title78EACField

typedef struct {
    unsigned char reserved00[8], active, reserved09[0x527];
    short scores[39];
    unsigned char reserved57E[2], flags[39];
} DecodedCompletionRecord;
extern unsigned char DecodedCompletionHeader[] __asm__("D_80066FCC");
extern unsigned char D_80066F54[], D_80066F7C[];
int func_title_8007928C(DecodedCompletionRecord* record) {
    register int total __asm__("$7") = 0;
    register int possible __asm__("$8") = 0;
    int index, result;
    register int bit __asm__("$3");
    unsigned char* excluded;
    if (!record->active)
        return -1;
    excluded = DecodedCompletionHeader + 0x32;
    for (index = 0; index < 0x27; index++) {
        register int bits __asm__("$6");
        total += record->scores[index];
        if (index != *excluded)
            possible += D_80066F54[index] * 100;
        bit = 0;
        MATCHING_KEEP_VOLATILE(bit);
        bits = record->flags[index];
        do {
            if ((bits >> bit) & 1)
                total += 100;
            bit++;
        } while (bit < 8);
        if (index != *excluded)
            possible += D_80066F7C[index] * 100;
    }
    result = total * 100 / possible;
    if (total && !result)
        return 1;
    return result;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/title/title2", D_title_8007464C);


/* AI-generated; not human reviewed. Memory-card save operation state machine.
 * Poll completion, retry reads/writes, serialize save data and verify checksums.
 * Original states, retry limits, transfer sizes and helper calls are retained.
 */
extern int RawFields[] __asm__("D_800725B0");
extern int RawPending __asm__("D_800725B4"), RawResult __asm__("D_800725C4"),
    RawError __asm__("D_800725C8");
extern int RawPort __asm__("D_800725E0"), RawSlot __asm__("D_800725E4");
extern int RawConfigA __asm__("D_8006C694"), RawConfigB __asm__("D_8006C698"),
    RawLanguage __asm__("D_8006C76C");
extern int RawSource __asm__("D_title_8007EC9C");
extern unsigned char RawState __asm__("D_title_8007F12E"), RawRetries __asm__("D_title_8007F132");
extern unsigned char RawConfig[] __asm__("D_title_8007F354");
extern unsigned char RawConfig1 __asm__("D_title_8007F355"), RawConfig2 __asm__("D_title_8007F356"),
    RawConfig3 __asm__("D_title_8007F357");
extern unsigned char RawSaveBytes[] __asm__("D_title_8007F3D4"), RawChecksums[] __asm__(
                                                                     "D_title_8007FCD0");
int RawPoll(int, int*, int*) __asm__("func_title_8007D218");
void RawRead(int, int, void*, int, int) __asm__("func_title_8007CFC0");
void RawWrite(int, int, void*, int, int) __asm__("func_title_8007CD68");
void RawUse(int) __asm__("func_title_8007C93C");
void RawSave(void*, int) __asm__("func_title_80078C1C");
int RawChecksum(void*) __asm__("func_title_80078BF4");
extern unsigned char RawSavedBytes[] __asm__("D_title_8007F3D4");
int func_title_800793C8(void) {
    register unsigned char* retry __asm__("$4");
    register unsigned int retryValue __asm__("$3");
    register int saved __asm__("$3");
    register int savedOffset __asm__("$2");
    register int state __asm__("$2");
    if (RawPoll(1, RawFields, RawFields + 1)) {
        switch (RawState) {
            case 0:
                RawError = 0;
                RawConfig[0] = RawConfigA;
                RawConfig1 = RawConfigB;
                RawConfig2 = RawLanguage;
                RawConfig3 = RawSlot;
                RawRead(RawPort * 16, RawSource, RawConfig, 512, 128);
                state = 1;
                RawState = state;
                return 0;
            case 1:
                if (!RawPending) {
                    RawSave(RawSaveBytes + RawSlot * 2304, 0);
                    savedOffset = RawSlot * 2304;
                    saved = *(int*)(RawSavedBytes + savedOffset);
                    state = 2;
                    RawState = state;
                    RawResult = saved;
                    return 0;
                }
                retry = &RawRetries;
                if ((retryValue = *retry) < 3) {
                    RawState = 0;
                    state = retryValue + 1;
                    *retry = state;
                    default:
                        return 0;
                }
                goto error;
            case 2:
                RawRead(RawPort * 16, RawSource, RawSaveBytes + RawSlot * 2304,
                        RawSlot * 2304 + 640, 2304);
                state = 3;
                RawState = state;
                return 0;
            case 3:
                if (RawPending) {
                    retry = &RawRetries;
                    if ((retryValue = *retry) < 3)
                        goto retryRead;
                    goto error;
                }
                goto write;
            case 4:
                if (!RawPending) {
                    if (RawChecksum(RawSaveBytes + RawSlot * 2304) ==
                        *(int*)(RawChecksums + RawSlot * 2304)) {
                        RawUse(RawSlot);
                        RawState = 5;
                        return 0;
                    }
                    retry = &RawRetries;
                    if ((retryValue = *retry) < 3) {
                    retryRead:
                        state = retryValue + 1;
                        *retry = state;
                        state = 2;
                        RawState = state;
                        return 0;
                    }
                    goto error;
                }
                retry = &RawRetries;
                if ((retryValue = *retry) < 3) {
                    state = retryValue + 1;
                    *retry = state;
                write:
                    RawWrite(RawPort * 16, RawSource, RawSaveBytes + RawSlot * 2304,
                             RawSlot * 2304 + 640, 2304);
                    state = 4;
                    RawState = state;
                    return 0;
                }
            error:
                RawError = 3;
                return -1;
            case 5:
                return 1;
        }
    } else
        return 0;
}
