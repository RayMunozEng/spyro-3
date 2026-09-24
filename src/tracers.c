#include "common.h"
#include "stdutil.h"
#include "tracers.h"

/* USA Rev 0: asm/nonmatchings/tracers/func_80050844.s,
 * 0x80050844..0x800509E8 (105 words). The pool has 32 slots of 0x6C bytes;
 * each call claims the first free slot and copies 2..16 short vectors.
 * Register constraints and framePad preserve the retail compiler layout;
 * framePad emits no runtime instruction. */
Tracer* func_80050844(void* source, int mode, int count, int flags) {
    int j;
    register void* sourceReg asm("$21");
    register int modeReg;
    register int countReg asm("$19");
    register int innerOffset asm("$20");
    volatile int storedFlags = flags;
    volatile char framePad[8];
    register Tracer* result asm("$23");
    register int* lastField asm("$22");
    register int offset asm("$18");
    register Vector3D16* firstVector asm("$4");
    register Vector3D16* cursor asm("$16");
    register char* base asm("$2");
    register char* endBase asm("$3");
    register int originalFlags asm("$8");
    register int flagMask asm("$3");
    register Tracer* returnValue asm("$2");
    sourceReg = source;
    __asm__("" : "=r"(sourceReg) : "0"(sourceReg));
    modeReg = mode;
    __asm__("" : "=r"(modeReg) : "0"(modeReg));
    countReg = count;
    __asm__("" : "=r"(countReg) : "0"(countReg));
    base = (char*)&D_80070610[0].unk4[0];
    result = (Tracer*)(base - 4);
    endBase = base + 0x64;
    __asm__("" : "=r"(endBase) : "0"(endBase));
    lastField = (int*)endBase;
    offset = 0;
    firstVector = (Vector3D16*)base;
    for (;;) {
        if (*(void**)((char*)D_80070610 + offset) == 0) {
            *(void**)((char*)D_80070610 + offset) = sourceReg;
            if (countReg < 0) {
                *(unsigned char*)((char*)D_80070610 + offset + 0x67) = 1;
                countReg = -countReg;
            } else {
                *(unsigned char*)((char*)D_80070610 + offset + 0x67) = 0;
            }
            MIN(countReg, 2);
            MAX(countReg, 16);
            if (countReg > 0) {
                j = 0;
                innerOffset = offset;
                cursor = firstVector;
                do {
                    if (*(unsigned char*)((char*)D_80070610 + innerOffset + 0x67)) {
                        func_8004F58C(cursor, (Vector3D16*)sourceReg);
                    } else {
                        func_8004F504(cursor, (Vector3D16*)sourceReg);
                    }
                    j++;
                    cursor++;
                } while (j < countReg);
            }
            returnValue = result;
            __asm__("" : "=r"(returnValue) : "0"(returnValue));
            *(unsigned char*)((char*)D_80070610 + offset + 0x64) = 0;
            *(unsigned char*)((char*)D_80070610 + offset + 0x65) = countReg;
            *(unsigned char*)((char*)D_80070610 + offset + 0x66) = modeReg;
            originalFlags = storedFlags;
            __asm__("" : "=r"(originalFlags) : "0"(originalFlags));
            flagMask = 0x3E000000;
            __asm__("" : "=r"(flagMask) : "0"(flagMask));
            *lastField = originalFlags | flagMask;
            return returnValue;
        }
        result++;
        lastField = (int*)((char*)lastField + 0x6C);
        offset += 0x6C;
        firstVector = (Vector3D16*)((char*)firstVector + 0x6C);
        if ((int)lastField >= (int)(endBase + 0xD80)) break;
    }
    return 0;
}

/**
 * ???() - func_800509E8() - MATCHING
 * https://decomp.me/scratch/VCBgx
 */
void func_800509E8(int* ptr) {
    *ptr = 0;
}

/**
 * UpdateTracers() - func_800509F0() - MATCHING
 * https://decomp.me/scratch/1ofwG
 */
void func_800509F0() {
    int i;

    for (i = 0; i < 0x20; i++) {
        if (D_80070610[i].unk0) {
            
            D_80070610[i].unk64 += 1;
            if (D_80070610[i].unk64 >= D_80070610[i].unk65) {
                D_80070610[i].unk64 = 0;
            }
            
            if (D_80070610[i].unk67) {
                func_8004F58C(&D_80070610[i].unk4[D_80070610[i].unk64], D_80070610[i].unk0);
            } else {
                func_8004F504(&D_80070610[i].unk4[D_80070610[i].unk64], D_80070610[i].unk0);
            }
            
        }
    }
}

/**
 * ???() - func_80050B00() - MATCHING
 * https://decomp.me/scratch/LIHxH
 */
Unknown_80070260* func_80050B00(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int i;

    for (i = 0; i < 8; i++) {
        if (D_80070260[i].unk0 == 0) {
            D_80070260[i].unk0 = arg0;
            D_80070260[i].unk4 = arg1;
            D_80070260[i].unk8 = arg2;
            D_80070260[i].unkC = arg3;
            D_80070260[i].unk10 = arg4;
            return &D_80070260[i];
        }
    }
    return 0;
}

/**
 * ???() - func_80050B88() - MATCHING
 * https://decomp.me/scratch/wl5A8
 */
void func_80050B88(int* ptr) {
    *ptr = 0;
}
