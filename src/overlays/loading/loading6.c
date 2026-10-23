#include "matching.h"
#include "common.h"
#include "stdutil.h"

/**
 * LoadEnvironment() - func_loading_800795BC()
 * WIP
 * https://decomp.me/scratch/bZqgq
 */
/* AI-generated, not human reviewed. Original byte-offset relocation chain. */
extern int* SharedEnvironmentNodes __asm__("D_8006D068");
extern int SharedEnvironmentNodeCount __asm__("D_8006D06C");
extern char* SharedEnvironmentPacked __asm__("D_8006C724");
extern int SharedEnvironmentPackedCount __asm__("D_8006C77C");
extern int* SharedEnvironmentOffsets __asm__("D_8006D048");
extern int SharedEnvironmentOffsetCount __asm__("D_8006D04C");
extern char* SharedEnvironmentFirst __asm__("D_8006D050");
extern char* SharedEnvironmentSecond __asm__("D_8006D054");
extern int SharedEnvironmentFirstMode __asm__("D_8006D058");
extern int SharedEnvironmentLimit __asm__("D_8006D074");
extern char* SharedEnvironmentData __asm__("D_8006E340");
extern unsigned char SharedEnvironmentR __asm__("D_8006E33C"),
    SharedEnvironmentG __asm__("D_8006E33D"), SharedEnvironmentB __asm__("D_8006E33E");
extern int SharedEnvironmentDataCount __asm__("D_8006E334");
extern int* SharedEnvironmentDataOffsets __asm__("D_8006E338");
extern unsigned short SharedEnvironmentConfig __asm__("D_8006C6A8");
void SharedBindSoundTables(char*, int) __asm__("func_8002C9F4");
void SharedEnvironmentSound(int, int, int) __asm__("PlaySound");
/* Numeric assembly evidence: build/shared-loader-evidence2160.md. */
extern int* SharedExtraOffsets __asm__("D_8006D05C");
extern int SharedExtraCount __asm__("D_8006D060");
extern char* SharedBlock __asm__("D_8006D064");
extern char* volatile SharedRelocations __asm__("D_8006D070");
extern char* SharedRecords __asm__("D_8006C530");
extern int SharedRecordCount __asm__("D_8006C5E0");
extern char* SharedShortTable[] __asm__("D_80070160");
extern char* SharedTail __asm__("D_8006C5B0");
extern char* SharedGroups __asm__("D_8006C7A0");
extern char* SharedPointers __asm__("D_8006C560");
extern char* SharedFinal __asm__("D_8006C708");
extern int SharedSnapshot[] __asm__("D_80071960");
void SharedCopy(char*, char*) __asm__("func_8004F178");
char* func_loading_800795BC(char* input) {
    char* cursor = input;
    register char* block __asm__("$17") = cursor;
    register int count __asm__("$2");
    register int index __asm__("$3");
    volatile int reservedStack[8];
    register int* nodeCount __asm__("$4");
    MATCHING_KEEP(block);
    cursor += 4;
    count = *(int*)cursor;
    cursor += 4;
    SharedEnvironmentNodes = (int*)cursor;
    nodeCount = &SharedEnvironmentNodeCount;
    *nodeCount = count;
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    SharedEnvironmentPacked = cursor + 4;
    SharedEnvironmentPackedCount = (*(int*)cursor - 4) / 28;
    cursor += *(int*)cursor;
    count = *(int*)cursor;
    cursor += 4;
    SharedEnvironmentOffsets = (int*)cursor;
    SharedEnvironmentOffsetCount = count;
    index = 0;
    if (count > 0) {
        nodeCount = (int*)((char*)nodeCount - 32);
        do {
            int offset = *(int*)cursor + 4;
            MATCHING_KEEP(offset);
            *(int*)cursor = (int)block + offset;
            index++;
            cursor += 4;
        } while (index < *nodeCount);
    }
    index = 0;
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    count = *(int*)cursor;
    cursor += 4;
    SharedExtraOffsets = (int*)cursor;
    nodeCount = &SharedExtraCount;
    *nodeCount = count;
    if (count > 0)
        do {
            int offset = *(int*)cursor + 4;
            MATCHING_KEEP(offset);
            *(int*)cursor = (int)block + offset;
            index++;
            cursor += 4;
        } while (index < *nodeCount);
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    nodeCount = (int*)&SharedBlock;
    *nodeCount = (int)cursor;
    cursor = block + *(int*)block;
    SharedCopy((char*)nodeCount + 24, cursor);
    cursor += 12;
    block = cursor;
    if (*(int*)cursor >= 9) {
        char* record;
        cursor += 4;
        SharedRelocations = cursor;
        *(int*)(cursor + 12) = (int)cursor + *(int*)(cursor + 12);
        record = SharedRelocations;
        *(int*)(record + 16) = (int)cursor + *(int*)(record + 16);
        record = SharedRelocations;
        *(int*)(record + 20) = (int)cursor + *(int*)(record + 20);
        record = SharedRelocations;
        *(int*)(record + 24) = (int)cursor + *(int*)(record + 24);
        record = SharedRelocations;
        *(int*)(record + 28) = (int)cursor + *(int*)(record + 28);
        record = SharedRelocations;
        *(int*)(record + 32) = (int)cursor + *(int*)(record + 32);
    }
    cursor = block + *(int*)block;
    SharedEnvironmentData = cursor + 4;
    cursor += *(int*)cursor;
    block = cursor;
    cursor += 4;
    count = *(int*)cursor;
    cursor += 4;
    SharedRecords = cursor;
    SharedRecordCount = count;
    index = 0;
    if (count > 0) {
        register int limit __asm__("$5") = count;
        register char* record __asm__("$4") = cursor;
        do {
            *(int*)(record + 60) = *(int*)(record + 60) + (int)block;
            index++;
            record += 68;
        } while (index < limit);
    }
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    {
        register int remaining __asm__("$3") = *(int*)cursor;
        cursor += 4;
        if (remaining > 0) {
            char** table = SharedShortTable;
            do {
                table[*(short*)cursor] = cursor;
                cursor = cursor + *(short*)(cursor + 2) + 4;
                remaining--;
            } while (remaining > 0);
        }
    }
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    {
        char* tail = cursor + *(int*)cursor;
        register char* base __asm__("$5");
        register char* entry __asm__("$4");
        cursor += 4;
        base = cursor - 4;
        entry = cursor;
        SharedTail = tail;
        SharedGroups = entry;
        index = 0;
        do {
            *(int*)entry = *(int*)entry + (int)base;
            index++;
            entry += 12;
        } while (index < 8);
    }
    cursor = block + *(int*)block;
    block = cursor;
    cursor += 4;
    {
        register int limit __asm__("$4") = *(int*)cursor;
        cursor += 4;
        SharedPointers = cursor;
        index = 0;
        if (limit > 0)
            do {
                *(int*)cursor = (int)cursor + *(int*)cursor;
                index++;
                cursor += 4;
            } while (index < limit);
    }
    cursor = block + *(int*)block;
    SharedFinal = cursor;
    cursor += 32;
    MATCHING_KEEP(cursor);
    block = cursor;
    SharedBindSoundTables(block + 4, 1);
    MATCHING_KEEP(block);
    {
        int offsets = (int)SharedEnvironmentOffsets;
        int end = *(int*)block;
        int count = SharedEnvironmentOffsetCount;
        int first = (int)SharedEnvironmentFirst;
        int second = (int)SharedEnvironmentSecond;
        int mode = SharedEnvironmentFirstMode;
        int shared = (int)SharedBlock;
        int relocations = (int)SharedRelocations;
        int limit = SharedEnvironmentLimit;
        cursor = block + end;
        SharedSnapshot[0] = offsets;
        SharedSnapshot[1] = count;
        SharedSnapshot[2] = first;
        SharedSnapshot[3] = second;
        SharedSnapshot[4] = mode;
        SharedSnapshot[5] = shared;
        SharedSnapshot[6] = relocations;
        SharedSnapshot[7] = limit;
    }
    return cursor;
}


extern int D_8006EDFC, D_8006EDD8, D_8006E344;
extern int* D_8006EE10;
extern int* DecodedFinishModels[] __asm__("D_8006EE2C");
extern int* DecodedFinishDescriptor __asm__("D_8006C6A0");
extern unsigned char DecodedFinishCheats[] __asm__("g_CheatFlags");
extern int D_8006EE18[];
void func_loading_80079A0C(void) {
    register int type __asm__("$4");
    int level;
    func_8004E7D4((int*)DecodedFinishModels, D_8006EE10, D_8006EDFC * 4);
    if (*((unsigned char*)&DecodedFinishCheats + 5)) {
        func_800584BC(0, *((unsigned char*)&DecodedFinishCheats + 5));
        *((unsigned char*)&DecodedFinishCheats + 5) = 0;
        return;
    }
    switch (D_8006EDD8) {
        case 0:
            func_8004E7D4(DecodedFinishDescriptor, D_8006EE18, 0x14);
            return;
        case 1:
            type = 6;
            __asm__("" : "=r"(type) : "0"(type), "i"(1));
            level = 0x4B;
            break;
        case 2:
            type = 6;
            __asm__("" : "=r"(type) : "0"(type), "i"(2));
            level = 0x4C;
            break;
        case 3:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(3));
            level = 0xA;
            break;
        case 4:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(4));
            level = 0x11;
            break;
        case 5:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(5));
            level = 0x1B;
            break;
        case 6:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(6));
            level = 0x25;
            break;
        case 7:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(7));
            level = 0xA;
            break;
        case 8:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(8));
            level = 0x14;
            break;
        case 9:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(9));
            level = 0x1E;
            break;
        case 10:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(10));
            level = 0x28;
            break;
        case 11:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(11));
            level = 0xA;
            break;
        case 12:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(12));
            level = 0x14;
            break;
        case 13:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(13));
            level = 0x1E;
            break;
        case 18:
        case 19:
            D_8006E344 = 0x13;
            return;
        case 14:
            type = 0;
            __asm__("" : "=r"(type) : "0"(type), "i"(14));
            level = 0x28;
            break;
        case 15:
            type = 6;
            __asm__("" : "=r"(type) : "0"(type), "i"(15));
            level = 0x46;
            break;
        case 16:
            type = 6;
            __asm__("" : "=r"(type) : "0"(type), "i"(16));
            level = 0x47;
            break;
        case 17:
            type = 6;
            __asm__("" : "=r"(type) : "0"(type), "i"(17));
            level = 0x49;
            break;
        default:
            return;
    }
    func_800584BC(type, level);
}
