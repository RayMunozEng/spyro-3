#include "matching.h"
#include "common.h"
#include "memcard.h"

/**
 * ChecksumSaveData_Options() - func_options_800778A0() - MATCHING
 * decomp.me is based on title implementation
 * https://decomp.me/scratch/1ODXk
 */
int func_options_800778A0(unsigned char* data) {
    return ChecksumSaveData(data);
}

/**
 * SaveGame_Options() - func_options_800778C8() - MATCHING
 * decomp.me is based on title implementation
 * https://decomp.me/scratch/dAm5W
 */
void func_options_800778C8(SaveFile* save, int noUpdate) {
    SaveGame(save, noUpdate);
    save->checksum = func_options_800778A0((char*)save);
}

typedef struct {
    unsigned char reserved00[8], active, reserved09[0x527];
    short scores[39];
    unsigned char reserved57E[2], flags[39];
} DecodedCompletionRecord;
extern unsigned char DecodedCompletionHeader[] __asm__("D_80066FCC");
extern unsigned char D_80066F54[], D_80066F7C[];
int func_options_80077B58(DecodedCompletionRecord* record) {
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

INCLUDE_RODATA("asm/nonmatchings/overlays/options/options2", D_options_800745A0);

/* AI generated; not human reviewed. Reuses verified loading_80079240 C.
 * SCUS-94467 options_80077C94: original numeric helper/global symbols
 * are mapped instruction by instruction. Save layouts/helper meanings remain open.
 */
extern int OptionsCallbackFields[] __asm__("D_800725B0");
extern int OptionsCallbackPending __asm__("D_800725B4"),
    OptionsCallbackResult __asm__("D_800725C4"), OptionsCallbackError __asm__("D_800725C8");
extern int OptionsCallbackPort __asm__("D_800725E0"), OptionsCallbackSlot __asm__("D_800725E4");
extern int OptionsCallbackConfigA __asm__("D_8006C694"),
    OptionsCallbackConfigB __asm__("D_8006C698"), OptionsCallbackLanguage __asm__("D_8006C76C");
extern int OptionsCallbackSource __asm__("D_options_8007ABE4");
extern unsigned char OptionsCallbackState __asm__("D_options_8007AFB6"), OptionsCallbackRetries
    __asm__("D_options_8007AFBA");
extern unsigned char OptionsCallbackConfig[] __asm__("D_options_8007B1DC");
extern unsigned char OptionsCallbackConfig1 __asm__("D_options_8007B1DD"),
    OptionsCallbackConfig2 __asm__("D_options_8007B1DE"),
    OptionsCallbackConfig3 __asm__("D_options_8007B1DF");
extern unsigned char OptionsCallbackSaveBytes[] __asm__("D_options_8007B25C"),
    OptionsCallbackChecksums[] __asm__("D_options_8007BB58");
int OptionsCallbackPoll(int, int*, int*) __asm__("func_options_800794B4");
void OptionsCallbackRead(int, int, void*, int, int) __asm__("func_options_8007925C");
void OptionsCallbackWrite(int, int, void*, int, int) __asm__("func_options_80079004");
void OptionsCallbackUse(int) __asm__("func_options_80078BD8");
void OptionsCallbackSave(void*, int) __asm__("func_options_800778C8");
int OptionsCallbackChecksum(void*) __asm__("func_options_800778A0");
extern unsigned char OptionsCallbackSavedBytes[] __asm__("D_options_8007B25C");
int func_options_80077C94(void) {
    register unsigned char* retry __asm__("$4");
    register unsigned int retryValue __asm__("$3");
    register int saved __asm__("$3");
    register int savedOffset __asm__("$2");
    register int state __asm__("$2");
    if (OptionsCallbackPoll(1, OptionsCallbackFields, OptionsCallbackFields + 1)) {
        switch (OptionsCallbackState) {
            case 0:
                OptionsCallbackError = 0;
                OptionsCallbackConfig[0] = OptionsCallbackConfigA;
                OptionsCallbackConfig1 = OptionsCallbackConfigB;
                OptionsCallbackConfig2 = OptionsCallbackLanguage;
                OptionsCallbackConfig3 = OptionsCallbackSlot;
                OptionsCallbackRead(OptionsCallbackPort * 16, OptionsCallbackSource,
                                    OptionsCallbackConfig, 512, 128);
                state = 1;
                OptionsCallbackState = state;
                return 0;
            case 1:
                if (!OptionsCallbackPending) {
                    OptionsCallbackSave(OptionsCallbackSaveBytes + OptionsCallbackSlot * 2304, 0);
                    savedOffset = OptionsCallbackSlot * 2304;
                    saved = *(int*)(OptionsCallbackSavedBytes + savedOffset);
                    state = 2;
                    OptionsCallbackState = state;
                    OptionsCallbackResult = saved;
                    return 0;
                }
                retry = &OptionsCallbackRetries;
                if ((retryValue = *retry) < 3) {
                    OptionsCallbackState = 0;
                    state = retryValue + 1;
                    *retry = state;
                    default:
                        return 0;
                }
                goto error;
            case 2:
                OptionsCallbackRead(OptionsCallbackPort * 16, OptionsCallbackSource,
                                    OptionsCallbackSaveBytes + OptionsCallbackSlot * 2304,
                                    OptionsCallbackSlot * 2304 + 640, 2304);
                state = 3;
                OptionsCallbackState = state;
                return 0;
            case 3:
                if (OptionsCallbackPending) {
                    retry = &OptionsCallbackRetries;
                    if ((retryValue = *retry) < 3)
                        goto retryRead;
                    goto error;
                }
                goto write;
            case 4:
                if (!OptionsCallbackPending) {
                    if (OptionsCallbackChecksum(OptionsCallbackSaveBytes +
                                                OptionsCallbackSlot * 2304) ==
                        *(int*)(OptionsCallbackChecksums + OptionsCallbackSlot * 2304)) {
                        OptionsCallbackUse(OptionsCallbackSlot);
                        OptionsCallbackState = 5;
                        return 0;
                    }
                    retry = &OptionsCallbackRetries;
                    if ((retryValue = *retry) < 3) {
                    retryRead:
                        state = retryValue + 1;
                        *retry = state;
                        state = 2;
                        OptionsCallbackState = state;
                        return 0;
                    }
                    goto error;
                }
                retry = &OptionsCallbackRetries;
                if ((retryValue = *retry) < 3) {
                    state = retryValue + 1;
                    *retry = state;
                write:
                    OptionsCallbackWrite(OptionsCallbackPort * 16, OptionsCallbackSource,
                                         OptionsCallbackSaveBytes + OptionsCallbackSlot * 2304,
                                         OptionsCallbackSlot * 2304 + 640, 2304);
                    state = 4;
                    OptionsCallbackState = state;
                    return 0;
                }
            error:
                OptionsCallbackError = 3;
                return -1;
            case 5:
                return 1;
        }
    } else
        return 0;
}
