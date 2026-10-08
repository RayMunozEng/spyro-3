#include "common.h"
#include "memcard.h"

/**
 * ChecksumSaveData_Loading() - func_loading_80078F88() - MATCHING
 * decomp.me is based on title implementation
 * https://decomp.me/scratch/1ODXk
 */
int func_loading_80078F88(unsigned char* data) {
    return ChecksumSaveData(data);
}

/**
 * SaveGame_Loading() - func_loading_80078FB0() - MATCHING
 * decomp.me is based on title implementation
 * https://decomp.me/scratch/dAm5W
 */
void func_loading_80078FB0(SaveFile* save, int noUpdate) {
    SaveGame(save, noUpdate);
    save->checksum = func_loading_80078F88((char*)save);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/loading/loading5", D_loading_8007460C);


/* AI-generated; not human reviewed. Numeric original callback; helper semantics unresolved. */
extern int RawFields[] __asm__("D_800725B0");
extern int RawPending __asm__("D_800725B4"), RawResult __asm__("D_800725C4"), RawError __asm__("D_800725C8");
extern int RawPort __asm__("D_800725E0"), RawSlot __asm__("D_800725E4");
extern int RawConfigA __asm__("D_8006C694"), RawConfigB __asm__("D_8006C698"), RawLanguage __asm__("D_8006C76C");
extern int RawSource __asm__("D_loading_8007B710");
extern unsigned char RawState __asm__("D_loading_8007B956"), RawRetries __asm__("D_loading_8007B95A");
extern unsigned char RawConfig[] __asm__("D_loading_8007BB7C");
extern unsigned char RawConfig1 __asm__("D_loading_8007BB7D"), RawConfig2 __asm__("D_loading_8007BB7E"), RawConfig3 __asm__("D_loading_8007BB7F");
extern unsigned char RawSaveBytes[] __asm__("D_loading_8007BBFC"), RawChecksums[] __asm__("D_loading_8007C4F8");
int RawPoll(int, int*, int*) __asm__("func_loading_8007ABC8");
void RawRead(int, int, void*, int, int) __asm__("func_loading_8007A970");
void RawWrite(int, int, void*, int, int) __asm__("func_loading_8007A718");
void RawUse(int) __asm__("func_loading_8007A2EC");
void RawSave(void*, int) __asm__("func_loading_80078FB0");
int RawChecksum(void*) __asm__("func_loading_80078F88");
extern unsigned char RawSavedBytes[] __asm__("D_loading_8007BBFC");
int func_loading_80079240(void) {
    register unsigned char *retry __asm__("$4");
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
            RawRead(RawPort * 16, RawSource, RawSaveBytes + RawSlot * 2304, RawSlot * 2304 + 640, 2304);
            state = 3;
            RawState = state;
            return 0;
        case 3:
            if (RawPending) {
                retry = &RawRetries;
                if ((retryValue = *retry) < 3) goto retryRead;
                goto error;
            }
            goto write;
        case 4:
            if (!RawPending) {
                if (RawChecksum(RawSaveBytes + RawSlot * 2304) == *(int*)(RawChecksums + RawSlot * 2304)) {
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
                RawWrite(RawPort * 16, RawSource, RawSaveBytes + RawSlot * 2304, RawSlot * 2304 + 640, 2304);
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
    } else return 0;
}
