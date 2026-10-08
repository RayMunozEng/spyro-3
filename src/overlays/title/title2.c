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

INCLUDE_ASM("asm/nonmatchings/overlays/title/title2", func_title_80078EAC);

typedef struct {
    unsigned char reserved00[8],active,reserved09[0x527];
    short scores[39];
    unsigned char reserved57E[2],flags[39];
} DecodedCompletionRecord;
extern unsigned char DecodedCompletionHeader[] __asm__("D_80066FCC");
extern unsigned char D_80066F54[],D_80066F7C[];
int func_title_8007928C(DecodedCompletionRecord* record) {
    register int total __asm__("$7")=0;
    register int possible __asm__("$8")=0;
    int index,result;
    register int bit __asm__("$3");
    unsigned char* excluded;
    if(!record->active)return -1;
    excluded=DecodedCompletionHeader+0x32;
    for(index=0;index<0x27;index++) {
        register int bits __asm__("$6");
        total+=record->scores[index];
        if(index!=*excluded)possible+=D_80066F54[index]*100;
        bit=0;
        __asm__ volatile("" : "=r"(bit) : "0"(bit));
        bits=record->flags[index];
        do {if((bits>>bit)&1)total+=100;bit++;}while(bit<8);
        if(index!=*excluded)possible+=D_80066F7C[index]*100;
    }
    result=total*100/possible;
    if(total && !result)return 1;
    return result;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/title/title2", D_title_8007464C);


/* AI-generated; not human reviewed. Numeric original callback; helper semantics unresolved. */
extern int RawFields[] __asm__("D_800725B0");
extern int RawPending __asm__("D_800725B4"), RawResult __asm__("D_800725C4"), RawError __asm__("D_800725C8");
extern int RawPort __asm__("D_800725E0"), RawSlot __asm__("D_800725E4");
extern int RawConfigA __asm__("D_8006C694"), RawConfigB __asm__("D_8006C698"), RawLanguage __asm__("D_8006C76C");
extern int RawSource __asm__("D_title_8007EC9C");
extern unsigned char RawState __asm__("D_title_8007F12E"), RawRetries __asm__("D_title_8007F132");
extern unsigned char RawConfig[] __asm__("D_title_8007F354");
extern unsigned char RawConfig1 __asm__("D_title_8007F355"), RawConfig2 __asm__("D_title_8007F356"), RawConfig3 __asm__("D_title_8007F357");
extern unsigned char RawSaveBytes[] __asm__("D_title_8007F3D4"), RawChecksums[] __asm__("D_title_8007FCD0");
int RawPoll(int, int*, int*) __asm__("func_title_8007D218");
void RawRead(int, int, void*, int, int) __asm__("func_title_8007CFC0");
void RawWrite(int, int, void*, int, int) __asm__("func_title_8007CD68");
void RawUse(int) __asm__("func_title_8007C93C");
void RawSave(void*, int) __asm__("func_title_80078C1C");
int RawChecksum(void*) __asm__("func_title_80078BF4");
extern unsigned char RawSavedBytes[] __asm__("D_title_8007F3D4");
int func_title_800793C8(void) {
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
